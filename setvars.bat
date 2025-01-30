@echo off

rem Copyright © Intel Corporation
rem SPDX-License-Identifier: MIT

rem Permission is hereby granted, free of charge, to any person obtaining a copy
rem of this software and associated documentation files (the "Software"), to deal
rem in the Software without restriction, including without limitation the rights
rem to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
rem copies of the Software, and to permit persons to whom the Software is
rem furnished to do so, subject to the following conditions:
rem
rem The above copyright notice and this permission notice shall be included in all
rem copies or substantial portions of the Software.
rem
rem THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
rem IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
rem FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
rem AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
rem LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
rem OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
rem SOFTWARE.


rem ===========================================================================
rem location of this bat file, without a trailing \ (backslash character)
set "ONEAPI_ROOT=%~dp0"
set "ONEAPI_ROOT=%ONEAPI_ROOT:~0,-1%"
set "script_name=%~nx0"
set topargs=%*

rem SETVARS_CALL
set SETVARS_CALL=1


goto :EndUsage
rem ===========================================================================
rem To be called if we encounter bad command-line args or user asks for help.

:Usage
  echo:
  echo: usage: setvars [--force] [--config=file] [--help] [...]
  echo:   --force        force setvars to re-run, doing so may overload environment
  echo:   --config=file  customize env vars using a setvars configuration file
  echo:   ...            additional args are passed to individual env\vars.bat scripts
  echo:                  additional args must follow this script's arguments
  echo:
  echo:   --help         display this help message and exit
  echo:   -? or /?       display this help message and exit
  echo:
  echo: The oneAPI toolkits no longer support 32-bit libraries, starting with the 2025.0 toolkit release. See the oneAPI release notes for more details.
  echo:
goto :eofCleanup
:EndUsage


rem ===========================================================================
rem setup default arguments
set configpath=""
set config_arg_found=""
set force=-1
set ia32=0

rem Parse command-line arguments passed to this script.
rem --config removal from topargs may result in a dangling ' = ' that is safely ignored.
rem Unable to capture path/filenames containing right parenthesis characters.
rem see: https://ss64.com/nt/syntax-brackets.html
rem see: https://www.dostips.com/DtTipsStringManipulation.php#Snippets.Remove
setlocal EnableDelayedExpansion
set "_topargs=%topargs%"
set "_force=%force%"
:ParseParam
  if [%~1] == [--config] (
    set "_config_arg_found=1"
    if NOT ["%~2"] == [""] (
      set "_configpath="%~2""
      set "_tempconfigpath=%~2"
      call set _topargs=%%_topargs:--config=%%
      call set _topargs=%%_topargs:!_tempconfigpath!=%%
      shift
    ) else (
      set _configpath=""
      call set _topargs=%%_topargs:--config=%%
    )
  ) else if [%~1] == [--force] (
      set "_force=1"
      set "_topargs=%_topargs:--force=%"
  ) else if [%~1] == [--ia32] (
      set "_ia32=1"
      set "_topargs=%_topargs:--ia32=%" 
  ) else if [%~1] == [ia32] (
      set "_ia32=1"
      set "_topargs=%_topargs:ia32=%" 
  ) else if [%~1] == [--help] (
      call :Usage
      goto :eofCleanup
  ) else if [%~1] == [-?] (
      call :Usage
      goto :eofCleanup
  ) else if [%~1] == [/?] (
      call :Usage
      goto :eofCleanup
  )

  shift

  if [%~1] neq [] (
    goto :ParseParam
  )
:EndParseParam
endlocal & set "topargs=%_topargs%" & set "config_arg_found=%_config_arg_found%" & set "configpath=%_configpath%" & set "force=%_force%" & set "ia32=%_ia32%"

rem Handle special case where "" are missing around %configpath% variable.
if [%configpath%] == [] (
  set configpath=""
)

rem Setvars design only accommodates single word arguments.
rem Some of the env\vars.bat scripts choke on quoted arguments.
rem Remove any remaining " characters from passed argument array.
rem Removing " chars is touchy, removing "=" chars seems to be impossible.
rem First line (below) ensures that at least one " is found by second line.
set topargs=%topargs%"
set topargs=%topargs:"=%

if ["%ia32%"] == ["1"] (
  echo :: ERROR: The oneAPI toolkits no longer support 32-bit libraries, starting with the 2025.0 toolkit release. See the oneAPI release notes for more details.
  call :Usage
  goto :eofCleanup
)

rem ===========================================================================
rem Override default 64-bit target if 32-bit Visual Studio env already exists.
rem Primarily affects "classic" compilers and some libraries (e.g., IPP, MKL).
if defined VSCMD_VER (
  if /i [%VSCMD_ARG_TGT_ARCH%] == [x86] (
    echo :: ERROR: The oneAPI toolkits no longer support 32-bit libraries, starting with the 2025.0 toolkit release. See the oneAPI release notes for more details.
    call :Usage
    goto :eofCleanup
  ) else (
    set TARGET_ARCH=intel64
  )
)
set "topargs=%topargs% %TARGET_ARCH%"


rem ===========================================================================
rem Capture bad config files first helps prevent confusing error messages.
rem Especially when no config file was provided, potentially consuming a valid option.
if ["%config_arg_found%"] == ["1"] (
  if [%configpath%] == [""] (
    echo :: ERROR: --config option specified but no config filename provided.
    call :Usage
    goto :eofCleanup
  )
  if NOT EXIST %configpath% (
    echo :: ERROR: --config file not found: %configpath%
    call :Usage
    goto :eofCleanup
  )
)


rem ===========================================================================
if ["%SETVARS_COMPLETED%"] == ["1"] (
  if [%force%] == [-1] (
    echo :: WARNING: %script_name% has already been run. Skipping re-execution.
    echo:   To force a re-execution of %script_name%, use the '--force' option.
    echo:   Using '--force' can result in excessive use of your environment variables.
    goto :eofCleanup
  )
)


rem ===========================================================================
rem setup default configuration
set componentArray[default]=latest

rem load configuration from file
if ["%config_arg_found%"] == ["1"] (
  for /F "usebackq tokens=1,2 delims==" %%i in (%configpath%) do call :BuildConfigList %%i %%j
)
goto :EndBuildConfigList

:BuildConfigArray
  rem Creates componentArray members in the global environment space and
  rem trims any whitespace from the component name and version name/value.
  set "componentArray[%1]=%2"
  set "componentName=%1"
  set "componentVersion=%2"
exit /b

:BuildConfigList
  call :BuildConfigArray %1 %2
  if "%componentName%" == "default" (
    if NOT "%componentVersion%" == "exclude" (
      if NOT "%componentVersion%" == "latest" (
        echo :: ERROR: Bad "default=%componentVersion%" entry in %configpath% file.
        echo:   Only "default=latest" and "default=exclude" are supported.
        call :eofCleanup
        goto :nonExistentLabel || exit /b 1
      )
    ) else (
      echo :: NOTE: "default=exclude" entry found in %configpath% file.
      echo:   Only explicitly specified components will be processed by "%script_name%".
    )
  ) else if EXIST "%ONEAPI_ROOT%\%componentName%\" (
      if NOT "exclude" == "%componentVersion%" (
        if NOT EXIST "%ONEAPI_ROOT%\%componentName%\%componentVersion%\env\vars.bat" (
          echo :: ERROR: Bad config file entry.
          echo:   Unrecognized version "%componentVersion%" for "%componentName%" component specified in %configpath% file.
          call :eofCleanup
          goto :nonExistentLabel || exit /b 1
        )
      ) else (
        echo :: NOTE: Exclude flag found for "%componentName%" component.
        echo:   The "%componentName%" env\vars.bat script will not be processed by "%script_name%".
      )
  ) else (
      echo :: ERROR: Bad config file entry.
      echo:   Unrecognized component "%componentName%" specified in %configpath% file.
      call :eofCleanup
      goto :nonExistentLabel || exit /b 1
  )
exit /b
:EndBuildConfigList


rem ===========================================================================
title Intel(r) oneAPI
echo :: initializing oneAPI environment...

rem ===========================================================================
rem Call Microsoft Visual Studio env scripts, if not already configured.
echo:   Initializing Visual Studio command-line environment...

rem The check for an existing install of the Visual Studio command-line
rem environment is honored, even if this is a --force run. In other words, we will
rem always retain any prior init of the Visual Studio environment, which may be
rem due to a prior run of setvars.bat or because the end-user opened one of the
rem Visual Studio terminal sessions from the Windows Start Menu (in the Visual
rem Studio group) and then ran setvars.bat in that terminal session. This is done
rem because running the Visual Studio command-line environment scripts more then
rem once in the same session has been shown to result in unpredictable
rem side-effects, indicating that it is designed to only be run once in a terminal
rem session.

if not defined VSCMD_VER (
  call "%ONEAPI_ROOT%\setvars-vcvarsall.bat" %topargs%
)
if defined VSCMD_VER (
  echo:   Visual Studio version %VSCMD_VER% environment configured.
  echo:   "%VSINSTALLDIR%"
  if "%VSCMD_ARG_HOST_ARCH%" NEQ "%VSCMD_ARG_TGT_ARCH%" (
    echo:   Visual Studio command-line environment initialized for: '%VSCMD_ARG_HOST_ARCH%_%VSCMD_ARG_TGT_ARCH%'
  ) else (
    echo:   Visual Studio command-line environment initialized for: '%VSCMD_ARG_TGT_ARCH%'
  )
) else (
  echo:   Visual Studio command-line environment was not configured.
)


rem ===========================================================================
rem loop thru component directories (see :DoIt), calling vars.bat for each one
rem see: https://stackoverflow.com/a/17113667/2914328 regarding the '^' character
for /f "delims=" %%d in ( 'dir /a:d /b "%ONEAPI_ROOT%" 2^>nul' ) do call :DoIt "%%d"
goto EndDoIt

:DoIt
  set "componentpath=%ONEAPI_ROOT%\%~1"
  set "cname=%~n1"

  rem Grab component version from componentArray if specified by a config file.
  setlocal EnableDelayedExpansion
  set version=!componentArray[%cname%]!
  endlocal & set "version=%version%"

  rem Else if not specified in a config file, use default version.
  if "%version%" equ ""  (
    set version=%componentArray[default]%
  )

  if "exclude" == "%version%"  (
    rem echo:   "excluding"
  ) else (
    if EXIST "%componentpath%\%version%\env\vars.bat" (
      echo :  %cname% -- %version%
      rem 'call' command is not properly handling special characters, even when quoted, use pushd/popd
      pushd "%componentpath%\%version%\env"
      call vars.bat %topargs%
      popd
    ) else (
      rem echo:   %cname% vars.bat file not found in "%componentpath%\%version%\env\vars.bat"
    )
  )
exit /b
:EndDoIt

set SETVARS_COMPLETED=1
echo :: oneAPI environment initialized ::
title Intel(r) oneAPI
goto :keepTitle

rem Call or jump to in order to insure a clean exit from this script.
rem see: https://ss64.com/nt/exit.html
:eofCleanup
title cmd
:keepTitle
set "SETVARS_CALL="
set "script_name="
set "topargs="
set "configpath="
set "config_arg_found="
set "force="
set "ia32="
set "componentpath="
set "cname="
set "version="
set "componentArray[default]="
set "componentName="
set "componentVersion="
set "TARGET_ARCH="
for /f "delims=" %%d in ( 'dir /a:d /b "%ONEAPI_ROOT%"' ) do set "componentArray[%%d]="

goto:eof
