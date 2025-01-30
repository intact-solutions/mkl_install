@echo off
rem Copyright (c) Intel Corporation
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

set "VARSDIR=%~dp0"
for /f "delims=" %%F in ("%VARSDIR%..") do set "CMPLR_ROOT=%%~fF"

set "SCRIPT_NAME=%~nx0"
set "VS_TARGET_ARCH=amd64"
set "INTEL_TARGET_ARCH=intel64"
set "USE_INTEL_LLVM=0"

:ParseArgs
:: Parse the incoming arguments
if /i "%1"==""              goto CheckArgs
if /i "%1"=="vs2022"        (set TARGET_VS=vs2022)           & shift & goto ParseArgs
if /i "%1"=="vs2019"        (set TARGET_VS=vs2019)           & shift & goto ParseArgs
if /i "%1"=="--include-intel-llvm"   (set USE_INTEL_LLVM=1)  & shift & goto ParseArgs
shift & goto ParseArgs

:CheckArgs
:: Setup Intel Compiler environment directly if Visual Studio environment is ready.
if defined VSCMD_VER (
    if /i "%VSCMD_ARG_TGT_ARCH%"=="x86" (
        echo:   Visual Studio environment '%VSCMD_ARG_TGT_ARCH%' is incompatible with '%INTEL_TARGET_ARCH%'.
        goto EndWithError
    ) else (
        set INTEL_TARGET_ARCH=intel64
    )
    goto SetIntelEnv
)

:: setvars-vcvarsall.bat is called by setvars.bat, skip checking Visual Studio environment again.
if ["%SETVARS_CALL%"] == ["1"] (
    goto SetIntelEnv
)

::detect installed VS
set "MSVS_VAR_SCRIPT="

rem The exact installation directory depends on both the version and offering
rem of Visual Studio (professional, etc.), according to the following pattern:
rem VS2019 and earlier: %ProgramFiles(x86)%\Microsoft Visual Studio\<version>\<offering>
rem VS2022 and later:   %ProgramFiles%\Microsoft Visual Studio\<version>\<offering>
rem Check for VS20??INSTALLDIR override by user, especially with custom installs.

set VS2022INSTALLDIR_USER=
set VS2019INSTALLDIR_USER=

if defined VS2022INSTALLDIR (
    set "VS2022INSTALLDIR_USER=%VS2022INSTALLDIR%"
) else (
    call :SetVS2022INSTALLDIR VS2022INSTALLDIR
)
if defined VS2019INSTALLDIR (
    set "VS2019INSTALLDIR_USER=%VS2019INSTALLDIR%"
) else (
    call :SetVS2019INSTALLDIR VS2019INSTALLDIR
)

rem ===========================================================================
rem default, set the latest VS in global environment
:SetVCVars

set "MSVS_VAR_SCRIPT_2022=%VS2022INSTALLDIR%\VC\Auxiliary\Build\vcvarsall.bat"
set "MSVS_VAR_SCRIPT_2019=%VS2019INSTALLDIR%\VC\Auxiliary\Build\vcvarsall.bat"

rem VS2022 or VS2019
if /i [%TARGET_VS%] == [] (
    if exist "%MSVS_VAR_SCRIPT_2022%" goto SetVS2022
    if exist "%MSVS_VAR_SCRIPT_2019%" goto SetVS2019
    call :NO_VS 2022 or 2019
    goto EndWithError
)

:VS2022
if /i [%TARGET_VS%] == [vs2022] (
    if exist "%MSVS_VAR_SCRIPT_2022%" goto SetVS2022
    call :NO_VS 2022
    goto EndWithError
)

:VS2019
if /i [%TARGET_VS%] == [vs2019] (
    if exist "%MSVS_VAR_SCRIPT_2019%" goto SetVS2019
    call :NO_VS 2019
    goto EndWithError
)

rem ===========================================================================
rem Why not assign MSVS_VAR_SCRIPT in the logic above? Because the assignment
rem will be trapped inside the if () "line" and getting it out is harder than
rem just adding this extra, simple step.

:SetVS2022
set "MSVS_VAR_SCRIPT=%MSVS_VAR_SCRIPT_2022%"
goto Setup

:SetVS2019
set "MSVS_VAR_SCRIPT=%MSVS_VAR_SCRIPT_2019%"
goto Setup

rem ===========================================================================
rem call Visual Studio vcvarsall.bat script
:Setup
if [%VSCMD_START_DIR%] == [] (
    if EXIST "%USERPROFILE%\Source" (
        set "VSCMD_START_DIR=%CD%"
    )
)

@call "%MSVS_VAR_SCRIPT%" %VS_TARGET_ARCH% 1>NUL

call :GetFullPath "%MSVS_VAR_SCRIPT%\.." MSVS_VAR_SCRIPT_DIR

set __MS_VC_INSTALL_PATH=
if defined VCToolsInstallDir (
    set "__MS_VC_INSTALL_PATH=%VCToolsInstallDir%"
)

set "VS_TARGET_ARCH="
set "TARGET_VS="
set "MSVS_VAR_SCRIPT="
set "MSVS_VAR_SCRIPT_DIR="
set "MSVS_VAR_SCRIPT_2022="
set "MSVS_VAR_SCRIPT_2019="
set "_tmpdir="
set "VS2022INSTALLDIR="
set "VS2019INSTALLDIR="
if defined VS2022INSTALLDIR_USER set "VS2022INSTALLDIR=%VS2022INSTALLDIR_USER%"
if defined VS2019INSTALLDIR_USER set "VS2019INSTALLDIR=%VS2019INSTALLDIR_USER%"
set "VS2022INSTALLDIR_USER="
set "VS2019INSTALLDIR_USER="
rem Do not clear __MS_VC_INSTALL_PATH.


rem ===========================================================================
rem setup intel compiler after visual studio environment ready
:SetIntelEnv
rem There should be only one OpenCL CPU / FGPA emu runtime is loaded.
if defined OCL_ICD_FILENAMES (
    set "OCL_ICD_FILENAMES="
)

rem OpenCL FPGA runtime
if exist "%CMPLR_ROOT%\opt\oclfpga\fpgavars.bat" (
    call "%CMPLR_ROOT%\opt\oclfpga\fpgavars.bat"
)

set "PATH=%CMPLR_ROOT%\bin;%PATH%"
set "PATH=%CMPLR_ROOT%\lib\ocloc;%PATH%"
if /i "%USE_INTEL_LLVM%"=="1" (
    set "PATH=%CMPLR_ROOT%\bin\compiler;%PATH%"
)

set "CPATH=%CMPLR_ROOT%\include;%CPATH%"
set "INCLUDE=%CMPLR_ROOT%\include;%INCLUDE%"
set "LIB=%CMPLR_ROOT%\lib\clang\19\lib\windows;%CMPLR_ROOT%\opt\compiler\lib;%CMPLR_ROOT%\lib;%LIB%"
set "PKG_CONFIG_PATH=%CMPLR_ROOT%\lib\pkgconfig;%PKG_CONFIG_PATH%"

set "OCL_ICD_FILENAMES=%OCL_ICD_FILENAMES%;%CMPLR_ROOT%\bin\intelocl64_emu.dll;%CMPLR_ROOT%\bin\intelocl64.dll"

set "CMAKE_PREFIX_PATH=%CMPLR_ROOT%;%CMAKE_PREFIX_PATH%"

goto End

:End
exit /B 0


rem ===========================================================================
:GetFullPath
SET %2=%~f1
GOTO :EOF


rem ===========================================================================
:NO_VS
echo :: WARNING: Visual Studio was not found in the standard installation location:
echo:   "%ProgramFiles%\Microsoft Visual Studio\<Year>\<Edition>" or
echo:   "%ProgramFiles(x86)%\Microsoft Visual Studio\<Year>\<Edition>"
echo:   Set the VS2019INSTALLDIR or VS2022INSTALLDIR
echo:   environment variable to point to your install location and try again.
goto :EOF

:EndWithError
set "VS_TARGET_ARCH="
set "INTEL_TARGET_ARCH="
set "TARGET_VS="
set "MSVS_VAR_SCRIPT="
set "MSVS_VAR_SCRIPT_DIR="
set "MSVS_VAR_SCRIPT_2022="
set "MSVS_VAR_SCRIPT_2019="
set "_tmpdir="
set "VS2022INSTALLDIR="
set "VS2019INSTALLDIR="
if defined VS2022INSTALLDIR_USER set "VS2022INSTALLDIR=%VS2022INSTALLDIR_USER%"
if defined VS2019INSTALLDIR_USER set "VS2019INSTALLDIR=%VS2019INSTALLDIR_USER%"
set "VS2022INSTALLDIR_USER="
set "VS2019INSTALLDIR_USER="
rem Do not clear __MS_VC_INSTALL_PATH.
exit /B 1


rem ===========================================================================
rem What appears to be extra assignments is actually needed to avoid
rem employing setlocal EnableDelayedExpansion / endlocal shenanigans.
rem HINT: %var% is expanded on reading a "line," not evaluation of the "line."
rem see https://ss64.com/nt/delayedexpansion.html and https://ss64.org/viewtopic.php?f=2&t=27
:SetVS2022INSTALLDIR

set "_tmpdir=%ProgramFiles%\Microsoft Visual Studio\2022\Professional"
set "%~1=%_tmpdir%"
if exist "%_tmpdir%" exit /b

set "_tmpdir=%ProgramFiles%\Microsoft Visual Studio\2022\Enterprise"
set "%~1=%_tmpdir%"
if exist "%_tmpdir%" exit /b

set "_tmpdir=%ProgramFiles%\Microsoft Visual Studio\2022\Community"
set "%~1=%_tmpdir%"
if exist "%_tmpdir%" exit /b

goto :EOF


rem ===========================================================================
:SetVS2019INSTALLDIR

set "_tmpdir=%ProgramFiles(x86)%\Microsoft Visual Studio\2019\Professional"
set "%~1=%_tmpdir%"
if exist "%_tmpdir%" exit /b

set "_tmpdir=%ProgramFiles(x86)%\Microsoft Visual Studio\2019\Enterprise"
set "%~1=%_tmpdir%"
if exist "%_tmpdir%" exit /b

set "_tmpdir=%ProgramFiles(x86)%\Microsoft Visual Studio\2019\Community"
set "%~1=%_tmpdir%"
if exist "%_tmpdir%" exit /b

goto :EOF

