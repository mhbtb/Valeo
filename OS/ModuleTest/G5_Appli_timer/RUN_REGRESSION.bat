REM ##########################################################
REM
REM			VALEO comfort & driving assistance systems
REM
REM ##########################################################
REM
REM    To run regression tests, this batch file is called
REM    by CREATE_VCAST.bat
REM
REM ##########################################################
REM
REM			compiler: Renesas EWRL78_1_40
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
REM working directory
REM c:
REM cd c:\workset\RLS_GP_RLXS_GEN5_DEV\05_SwDev\01_SrcCode\Application\ModuleTest\

REM ##########################################################
REM Use command line interface to execute unit tests
set PARAM1=%1
%VECTORCAST_DIR%\clicast -lc -e%PARAM1% environment delete
%VECTORCAST_DIR%\clicast -lc environment build %PARAM1%.env
%VECTORCAST_DIR%\clicast -lc -e%PARAM1% test script run %PARAM1%.tst
%VECTORCAST_DIR%\clicast -lc -e%PARAM1% execute batch
%VECTORCAST_DIR%\clicast -lc -e%PARAM1% reports custom full
%VECTORCAST_DIR%\clicast -lc -e%PARAM1% reports custom management
REM %VECTORCAST_DIR%\clicast -lc -e%PARAM1% reports prqa_error %PARAM1%_QAC.log

REM ##########################################################
REM
REM					END of start-script
REM
REM ##########################################################