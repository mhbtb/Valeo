REM ##########################################################
REM
REM			VALEO comfort & driving assistance systems
REM
REM ##########################################################
REM
REM    VectorCast should always be started with a script
REM    All needed variables will be set in this script
REM    For each module and each compiler is one script
REM    and directory necessary !!
REM
REM ##########################################################
REM
REM			compiler: Renesas IAR EWRL78_1_40
REM
REM ##########################################################

REM ##########################################################
REM path of the tool-directory
SET PATH_T=C:

REM ##########################################################
REM path of the QAC installation
SET PATH_QAC=%PATH_T%\PRQA\QAC-7.1

REM ##########################################################
REM install directory of VectorCAST
SET VECTORCAST_DIR=%PATH_T%\VCAST

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
SET VCAST_IAR_INSTALL_DIR=%PATH_T%\Program Files (x86)\IAR Systems\Embedded Workbench 7.0\rl78
REM CSPYBAT_INIFILE= C:\workset\RLS_GP_RLXS_GEN5_DEV\05_SwDev\01_SrcCode\Application\settings\RLS_GP_RLXS_GEN5_DEV_APPLI_CHINA.dni


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
REM start cmd for VectorCAST with language C
start %VECTORCAST_DIR%\vcastqt -lc

REM ##########################################################
REM
REM					END of start-script
REM
REM ##########################################################