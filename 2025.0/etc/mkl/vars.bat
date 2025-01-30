@echo off
rem ============================================================================
rem Copyright 2023 Intel Corporation.
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


rem This etc\mkl\vars.bat script is intended to be called by oneapi-vars.bat script
rem and is not intended to be called directly.


rem ############################################################################
rem
rem oneAPI MKL vars.bat arguments:
rem
rem   <install-dir>\oneapi-vars.bat [--force] [--help] [mod [<MKL_interface>]]
rem
rem     mod (optional) - Set path to oneAPI MKL F95 modules
rem
rem     <MKL_interface> (optional) - oneAPI MKL programming interface for the
rem                                  "mod" option to set path
rem         lp64         : 4 bytes integer (default)
rem         ilp64        : 8 bytes integer
rem
rem ############################################################################

if not defined SETVARS_CALL (
  echo:
  echo :: ERROR: This script must be called by oneapi-vars.bat.
  echo    Try '^<install-dir^>\oneapi-vars.bat --help' for help.
  echo:
  exit /b 255
)

if not defined ONEAPI_ROOT (
  echo:
  echo :: ERROR: This script requires that the ONEAPI_ROOT env variable is set.
  echo    Try '^<install-dir^>\oneapi-vars.bat --help' for help.
  echo:
  exit /b 254
)

rem ############################################################################

setlocal

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
shift & goto ParseArgs

:SetEnv
set "MKLROOT=%ONEAPI_ROOT%"
if /i "%MKL_MOD%"=="%MKL_MOD_NAME%" (
    call :JoinPaths "%MKLROOT%\include\mkl\intel64\%MKL_LP64_ILP64%" "%INCLUDE%" INCLUDE
)

:: Set global variables from local ones
endlocal & ^
set "MKLROOT=%MKLROOT%" & ^
set "INCLUDE=%INCLUDE%"

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
