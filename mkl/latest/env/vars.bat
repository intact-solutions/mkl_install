@echo off
rem ============================================================================
rem Copyright 2003-2024 Intel Corporation.
rem
rem This software  and the related  documents  are Intel  copyrighted materials,
rem and your use  of them is  governed by the express  license under  which they
rem were provided to you (License).  Unless the License provides otherwise,  you
rem may not use,  modify,  copy, publish,  distribute, disclose or transmit this
rem software or the related documents without Intel's prior written permission.
rem
rem This software and the related documents are provided as is,  with no express
rem or implied warranties,  other  than those that  are expressly  stated in the
rem License.
rem ============================================================================

rem ############################################################################
rem
rem oneAPI MKL vars.bat syntax:
rem
rem   vars.bat [mod [<MKL_interface>]]
rem
rem     mod (optional) - Set path to oneAPI MKL F95 modules
rem
rem     <MKL_interface> (optional) - oneAPI MKL programming interface for the
rem                                  "mod" option to set path
rem         lp64         : 4 bytes integer (default)
rem         ilp64        : 8 bytes integer
rem
rem ############################################################################

setlocal

set "MKL_SCRIPT_NAME=%~nx0"
set "MKL_SCRIPT_DIR=%~dp0"

:: Constants
set "MKL_MOD_NAME=mod"

:: Defaults
set "MKL_MOD="
set "MKL_LP64_ILP64=lp64"

:ParseArgs
if /i "%1"==""               goto SetEnv
if /i "%1"=="%MKL_MOD_NAME%" (set "MKL_MOD=%MKL_MOD_NAME%") & shift & goto ParseArgs
if /i "%1"=="lp64"           (set "MKL_LP64_ILP64=lp64")    & shift & goto ParseArgs
if /i "%1"=="ilp64"          (set "MKL_LP64_ILP64=ilp64")   & shift & goto ParseArgs
if /i "%1"=="--help"         goto Syntax
shift & goto ParseArgs

:SetEnv
call :GetFullPath "%MKL_SCRIPT_DIR%\.." MKLROOT
call :JoinPaths "%MKLROOT%\include" "%INCLUDE%" INCLUDE
if /i "%MKL_MOD%"=="%MKL_MOD_NAME%" (
    call :JoinPaths "%MKLROOT%\include\mkl\intel64\%MKL_LP64_ILP64%" "%INCLUDE%" INCLUDE
)
call :JoinPaths "%MKLROOT%\lib" "%LIB%" LIB
call :JoinPaths "%MKLROOT%\bin" "%PATH%" PATH
call :JoinPaths "%MKLROOT%\lib\pkgconfig" "%PKG_CONFIG_PATH%" PKG_CONFIG_PATH
call :JoinPaths "%MKLROOT%\lib\cmake" "%CMAKE_PREFIX_PATH%" CMAKE_PREFIX_PATH

:: Set global variables from local ones
endlocal & ^
set "MKLROOT=%MKLROOT%" & ^
set "INCLUDE=%INCLUDE%" & ^
set "LIB=%LIB%" & ^
set "PATH=%PATH%" & ^
set "PKG_CONFIG_PATH=%PKG_CONFIG_PATH%" & ^
set "CMAKE_PREFIX_PATH=%CMAKE_PREFIX_PATH%"

goto End

:Syntax
echo.
echo oneAPI MKL %MKL_SCRIPT_NAME% syntax:
echo.
echo   %MKL_SCRIPT_NAME% [mod [^<MKL_interface^>]]
echo.
echo     mod (optional) - Set path to oneAPI MKL F95 modules
echo.    
echo     ^<MKL_interface^> (optional) - oneAPI MKL programming interface for the
echo                                  "mod" option to set path
echo         lp64         : 4 bytes integer (default)
echo         ilp64        : 8 bytes integer
echo.
exit /B 1

:GetFullPath
set %2=%~f1
goto End

:JoinPaths
if "%~2"=="" (
    set "%3=%~1"
) else (
    set "%3=%~1;%~2"
)
goto End

:End
exit /B 0
