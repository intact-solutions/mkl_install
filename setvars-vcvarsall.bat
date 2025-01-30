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


rem ===========================================================================
rem Set default target architecture to 64-bit.
rem setvars.bat will only set to 32-bit if explicity declared on command-line.
rem USE_INTEL_LLVM is in compiler vars.bat, but we should ignore it in
rem setvars.bat because our focus is only on the Visual Studio vcvars script.
set "VS_TARGET_ARCH=x64"
set "INTEL_TARGET_ARCH=intel64"
rem set "USE_INTEL_LLVM=0"

:ParseArgs
rem Parse the incoming arguments
if /i [%1] == []         goto EndParseArgs
if /i [%1] == [ia32]     (set INTEL_TARGET_ARCH=ia32)     & (set VS_TARGET_ARCH=x86)
if /i [%1] == [intel64]  (set INTEL_TARGET_ARCH=intel64)  & (set VS_TARGET_ARCH=x64)
if /i [%1] == [vs2019]   (set TARGET_VS=vs2019)
if /i [%1] == [vs2022]   (set TARGET_VS=vs2022)
rem if /i [%1] == [--include-intel-llvm] (set USE_INTEL_LLVM=1)
shift & goto ParseArgs
:EndParseArgs


rem ===========================================================================
rem detect installed VS
set MSVS_VAR_SCRIPT=

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
rem see: https://ss64.com/nt/if.html note regarding if path/filename
:Setup
if ["%VSCMD_START_DIR%"] == [] (
    if EXIST "%USERPROFILE%\Source" (
        set "VSCMD_START_DIR=%CD%"
    )
)

@call "%MSVS_VAR_SCRIPT%" %VS_TARGET_ARCH% 1>NUL

call :GetFullPath "%MSVS_VAR_SCRIPT%\.." MSVS_VAR_SCRIPT_DIR

rem add Visual Studio build tools to path
if /i [%INTEL_TARGET_ARCH%] == [ia32] (
    if defined VCToolsInstallDir (
        if exist "%VCToolsInstallDir%\bin\HostX64\x64" (
            set "PATH=%PATH%;%VCToolsInstallDir%\bin\HostX64\x64"
            goto set_dll_end
        )
    )
    if exist "%MSVS_VAR_SCRIPT_DIR%\bin\amd64" (
        set "PATH=%PATH%;%MSVS_VAR_SCRIPT_DIR%\bin\amd64"
        goto set_dll_end
    )
)
:set_dll_end

set __MS_VC_INSTALL_PATH=
if defined VCToolsInstallDir (
    set "__MS_VC_INSTALL_PATH=%VCToolsInstallDir%"
)

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
rem Do not clear or set or define USE_INTEL_LLVM.
exit /B 0


rem ===========================================================================
:GetFullPath
SET %2=%~f1
GOTO :EOF


rem ===========================================================================
:NO_VS
echo :: WARNING: Visual Studio was not found in a standard install location:
echo:     "%ProgramFiles%\Microsoft Visual Studio\<Year>\<Edition>" or
echo:     "%ProgramFiles(x86)%\Microsoft Visual Studio\<Year>\<Edition>"
echo:   Set the VS2019INSTALLDIR or VS2022INSTALLDIR environment variable to
echo:   point to your install location and try again. For example, if you
echo:   are using the VS 2022 Build Tools, do the following:
echo:     set "VS2022INSTALLDIR=%ProgramFiles(x86)%\Microsoft Visual Studio\2022\BuildTools"
echo:     "%ProgramFiles(x86)%\Intel\oneAPI\setvars.bat"
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
rem Do not clear or set or define USE_INTEL_LLVM.
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
