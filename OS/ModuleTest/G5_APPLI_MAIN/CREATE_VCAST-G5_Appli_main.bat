REM ##########################################################
REM
REM			VALEO comfort & driving assistance systems
REM
REM ##########################################################
REM
REM    To create an environment from regressions scripts it
REM    is necessary to start the batch-file from VectorCast from
REM    this batch-file to use the right settings
REM
REM ##########################################################
REM
REM			compiler: Renesas IAR EWRL78_1_40
REM
REM ##########################################################

REM ##########################################################
REM path of the tool-directory
SET PATH_T=C:\Tool

REM ##########################################################
REM path of the QAC installation
SET PATH_QAC=%PATH_T%\PRQA\QAC-7.1

REM ##########################################################
REM install directory of VectorCAST
SET vectorcast_dir=%PATH_T%\VCAST

REM ##########################################################
REM The client will look for a license according to any data 
REM saved in the registry. We can prevent that by setting an
REM environment variable LM_APP_DISABLE_CACHE_READ
set LM_APP_DISABLE_CACHE_READ=1

REM Kill lm_license_file by putting a newline after the equals
REM Later you may want to change this to @server or port@server
REM    e.g.   set LM_LICENSE_FILE= 27002@server
REM    or     set LM_LICENSE_FILE= @server
set LM_LICENSE_FILE=

REM use a local license file or the name of the license server
SET VECTOR_LICENSE_FILE=4734@BIE2-FLEXLM1;4734@BIE2-FLEXLM2;4734@BIE2-FLEXLM3

REM ##########################################################
REM complier path
SET VCAST_IAR_INSTALL_DIR=%PATH_T%\IAR Systems\Embedded Workbench 7.0\rl78

REM Put the compiler in the path that is shipped with VectorCAST
SET IAR7_COMPILER_PATH=%VCAST_IAR_INSTALL_DIR%\bin
SET IAR7_COMPILER_LIBRARY_PATH=%VCAST_IAR_INSTALL_DIR%\lib

REM ##########################################################
REM working directory
REM SET SW_DEV_PATH=c:\baseline\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_AUB8_G5B1_X008B\05_SwDev
REM c:
REM cd %SW_DEV_PATH%\Application\Diagnostics\ModuleTest

REM ##########################################################
REM create %PATH% variable
SET PATH=%IAR7_COMPILER_PATH%;%IAR7_COMPILER_LIBRARY_PATH%;%VCAST_IAR_INSTALL_DIR%;%PATH%

REM ##########################################################
REM call the batch from VectorCast to build up the environment
REM call BUILD_[module_name].bat

REM call BUILD_[module_name]_NO_RUN.bat

REM ##########################################################
REM Use command line interface to run regression tests
REM Pass environment name without file extension as parameter
SET PARAM1=G5_APPLI_MAIN
call RUN_REGRESSION.bat %PARAM1%

REM ##########################################################
REM
REM					END of start-script
REM
REM ##########################################################