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
  echo: usage: oneapi-vars [--force] [--help] [...]
  echo:   --force        force oneapi-vars to re-run, doing so may overload environment
  echo:   ...            additional args are passed to individual etc\*\vars.bat scripts
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
set ia32=0
set force=-1

rem Parse command-line arguments passed to this script.
rem --config removal from topargs may result in a dangling ' = ' that is safely ignored.
rem Unable to capture path/filenames containing right parenthesis characters.
rem see: https://ss64.com/nt/syntax-brackets.html
rem see: https://www.dostips.com/DtTipsStringManipulation.php#Snippets.Remove
setlocal EnableDelayedExpansion
set "_topargs=%topargs%"
set "_force=%force%"
:ParseParam
  if [%~1] == [--ia32] (
      set "_ia32=1"
      set "_topargs=%_topargs:--ia32=%"
  ) else if [%~1] == [ia32] (
      set "_ia32=1"
      set "_topargs=%_topargs:ia32=%"
  ) else if [%~1] == [--force] (
      set "_force=1"
      set "_topargs=%_topargs:--force=%"
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
endlocal & set "topargs=%_topargs%" & set "force=%_force%" & set "ia32=%_ia32%"

rem Setvars design only accommodates single word arguments.
rem Some of the env\vars.bat scripts choke on quoted arguments.
rem Remove any remaining " characters from passed argument array.
rem Removing " chars is touchy, removing "=" chars seems to be impossible.
rem First line (below) ensures that at least one " is found by second line.
set topargs=%topargs%"
set topargs=%topargs:"=%


rem ===========================================================================
rem rem Generate error and exit if 32-bit Visual Studio env already exists.
rem Primarily affects "classic" compilers and some libraries (e.g., IPP, MKL).
rem Referenced by setvars-vcvarsall.bat and Visual Studio vcvarsall.bat.
if ["%ia32%"] == ["1"] (
  echo :: ERROR: The oneAPI toolkits no longer support 32-bit libraries, starting with the 2025.0 toolkit release. See the oneAPI release notes for more details.
  set ia32=0
  call :Usage
  goto :eofCleanup
)
if defined VSCMD_VER (
  if /i [%VSCMD_ARG_TGT_ARCH%] == [x86] (
    echo :: ERROR: The oneAPI toolkits no longer support 32-bit libraries, starting with the 2025.0 toolkit release. See the oneAPI release notes for more details.
    call :Usage
    goto :eofCleanup
  ) else (
    set TARGET_ARCH=intel64
    set ia32=0
  )
)
set "topargs=%topargs% %TARGET_ARCH%"


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
title Intel(r) oneAPI
echo :: initializing oneAPI environment...

rem ===========================================================================
rem Call Microsoft Visual Studio env scripts, if not already configured.
echo:   Initializing Visual Studio command-line environment...

rem The check for an existing install of the Visual Studio command-line
rem environment is honored, even if this is a --force run. In other words, we will
rem always retain any prior init of the Visual Studio environment, which may be
rem due to a prior run of oneapi-vars.bat or because the end-user opened one of the
rem Visual Studio terminal sessions from the Windows Start Menu (in the Visual
rem Studio group) and then ran oneapi-vars.bat in that terminal session. This is done
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


rem ONEAPI_ROOT is expected to point to the topmost oneAPI install folder.
rem The ONEAPI_ROOT environment variable was defined near the top of this script.

rem The following global environment variables are sufficient for a large number
rem of oneAPI components. The remainder of this script will process any additional
rem env vars scripts that have been provided by a specific oneAPI component.
rem The include32 folder is primarily used for 32-bit Fortran mod files.
rem TODO: How to address CMAKE_PREFIX_PATH when ia32 is requested?

set "CMAKE_PREFIX_PATH=%ONEAPI_ROOT%;%CMAKE_PREFIX_PATH%"
set "CLASSPATH=%ONEAPI_ROOT%\share\java;%CLASSPATH%"

rem These vars point only to 64-bit folders.
set "PATH=%ONEAPI_ROOT%\bin;%ONEAPI_ROOT%\share\locale;%PATH%"
set "CPATH=%ONEAPI_ROOT%\include;%CPATH%"
set "INCLUDE=%ONEAPI_ROOT%\include;%INCLUDE%"

rem point to intel64 paths, because ia32 is no longer supported
set "INTEL_TARGET_ARCH=intel64"
set "LIB=%ONEAPI_ROOT%\lib;%LIB%"
set "LIBRARY_PATH=%ONEAPI_ROOT%\lib;%LIBRARY_PATH%"
set "PKG_CONFIG_PATH=%ONEAPI_ROOT%\lib\pkgconfig;%PKG_CONFIG_PATH%"


rem ===========================================================================
rem loop thru component directories (see :DoIt), calling vars.bat for each one
rem see: https://stackoverflow.com/a/17113667/2914328 regarding the '^' character
for /f "delims=" %%d in ( 'dir /a:d /b "%ONEAPI_ROOT%\etc" 2^>nul' ) do call :DoIt "%%d"
goto EndDoIt

:DoIt
  set "componentpath=%ONEAPI_ROOT%\etc\%~1"
  set "cname=%~n1"

  if EXIST "%componentpath%\vars.bat" (
    echo :: %cname% -- processing etc\%cname%\vars.bat
    rem 'call' command is not properly handling special characters, even when quoted, use pushd/popd
    pushd "%componentpath%"
    call vars.bat %topargs%
    popd
  ) else (
    rem echo:   %cname% vars.bat file not found in "%ONEAPI_ROOT%\etc\%name%"
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
set "force="
set "componentpath="
set "cname="
set "TARGET_ARCH="
set "ia32="

goto:eof
