-- VectorCAST 6.2n
-- Test Case Script
-- 
-- Environment    : G5_LINSCI_SR
-- Unit(s) Under Test: G5_LINsci_sr
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Unit: G5_LINsci_sr

-- Subprogram: SCIVLIN_NEC_errorInterrupt

-- Test Case: SCIVLIN_NEC_errorInterrupt.001
TEST.UNIT:G5_LINsci_sr
TEST.SUBPROGRAM:SCIVLIN_NEC_errorInterrupt
TEST.NEW
TEST.NAME:SCIVLIN_NEC_errorInterrupt.001
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.my_UF0STR:0x4002
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.rb_ResponseTime_g:0
TEST.EXPECTED:uut_prototype_stubs.ApplLinProtocolError.error:0x2
TEST.END

-- Test Case: SCIVLIN_NEC_errorInterrupt.002
TEST.UNIT:G5_LINsci_sr
TEST.SUBPROGRAM:SCIVLIN_NEC_errorInterrupt
TEST.NEW
TEST.NAME:SCIVLIN_NEC_errorInterrupt.002
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.uF_sciState_mg.Bit.B3:<<MAX>>
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.uF_sciState_mg.Bit.B4:<<MAX>>
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.my_UF0BUCTL:0xF
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.my_UF0STR:0x2
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.rb_ResponseTimeMax_mg:100
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.rb_ResponseTime_g:101
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.uF_sciState_mg.Bit.B3:<<MAX>>
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.my_UF0BUCTL:0xF
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.my_UF0STR:0x2
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.rb_ResponseTimeMax_mg:100
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.rb_ResponseTime_g:0
TEST.END

-- Test Case: SCIVLIN_NEC_errorInterrupt.003
TEST.UNIT:G5_LINsci_sr
TEST.SUBPROGRAM:SCIVLIN_NEC_errorInterrupt
TEST.NEW
TEST.NAME:SCIVLIN_NEC_errorInterrupt.003
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.uF_sciState_mg.Bit.B3:<<MAX>>
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.my_UF0STR:0x2
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.rb_ResponseTimeMax_mg:100
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.rb_ResponseTime_g:100
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.uF_sciState_mg.Bit.B3:<<MAX>>
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.my_UF0STR:0x2
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.rb_ResponseTimeMax_mg:100
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.rb_ResponseTime_g:0
TEST.END

-- Test Case: linNoResponseNoTimeout
TEST.UNIT:G5_LINsci_sr
TEST.SUBPROGRAM:SCIVLIN_NEC_errorInterrupt
TEST.NEW
TEST.NAME:linNoResponseNoTimeout
TEST.NOTES:
This is an automatically generated test case.
   Test Path 9
      (1) if ((rw_err_typ_l & (2)) > (0)) ==> TRUE
      (2) if (rb_ResponseTime_g > rb_ResponseTimeMax_mg) ==> FALSE
   Test Case Generation Notes:
      Conflict: Unable to validate expression-to-expression comparison in branch 1
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.uF_sciState_mg.Bit.B3:<<MIN>>
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.my_rw_err_typ_l:0x2
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.my_UF0BUCTL:0xF
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.my_UF0STR:0x2
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.rb_ResponseTimeMax_mg:100
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.rb_ResponseTime_g:100
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.uF_sciState_mg.Bit.B3:<<MIN>>
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.uF_sciState_mg.Bit.B4:<<MIN>>
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.my_rw_err_typ_l:0x2
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.my_UF0BUCTL:0xF
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.my_UF0STR:0x2
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.rb_ResponseTimeMax_mg:100
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.rb_ResponseTime_g:0
TEST.EXPECTED:uut_prototype_stubs.ApplLinProtocolError.error:128
TEST.END

-- Test Case: linNoResponseUARTMaskFalse
TEST.UNIT:G5_LINsci_sr
TEST.SUBPROGRAM:SCIVLIN_NEC_errorInterrupt
TEST.NEW
TEST.NAME:linNoResponseUARTMaskFalse
TEST.NOTES:
This is an automatically generated test case.
   Test Path 9
      (1) if ((rw_err_typ_l & (2)) > (0)) ==> TRUE
      (2) if (rb_ResponseTime_g > rb_ResponseTimeMax_mg) ==> FALSE
   Test Case Generation Notes:
      Conflict: Unable to validate expression-to-expression comparison in branch 1
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.uF_sciState_mg.Bit.B4:<<MAX>>
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.my_rw_err_typ_l:0x2
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.my_UF0BUCTL:0xFFF0
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.my_UF0STR:0x2
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.rb_ResponseTimeMax_mg:100
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.rb_ResponseTime_g:101
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.uF_sciState_mg.Bit.B4:<<MIN>>
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.my_rw_err_typ_l:0x2
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.my_UF0BUCTL:0xFFF0
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.my_UF0STR:0x2
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.rb_ResponseTimeMax_mg:100
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.rb_ResponseTime_g:0
TEST.EXPECTED:uut_prototype_stubs.ApplLinProtocolError.error:64
TEST.END

-- Test Case: linNoResponseUARTMaskTrue
TEST.UNIT:G5_LINsci_sr
TEST.SUBPROGRAM:SCIVLIN_NEC_errorInterrupt
TEST.NEW
TEST.NAME:linNoResponseUARTMaskTrue
TEST.NOTES:
This is an automatically generated test case.
   Test Path 9
      (1) if ((rw_err_typ_l & (2)) > (0)) ==> TRUE
      (2) if (rb_ResponseTime_g > rb_ResponseTimeMax_mg) ==> FALSE
   Test Case Generation Notes:
      Conflict: Unable to validate expression-to-expression comparison in branch 1
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.uF_sciState_mg.Bit.B3:<<MIN>>
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.uF_sciState_mg.Bit.B4:<<MAX>>
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.my_rw_err_typ_l:0x2
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.my_UF0BUCTL:0xF
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.my_UF0STR:0x2
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.rb_ResponseTimeMax_mg:100
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.rb_ResponseTime_g:101
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.uF_sciState_mg.Bit.B3:<<MIN>>
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.uF_sciState_mg.Bit.B4:<<MIN>>
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.my_rw_err_typ_l:0x2
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.my_UF0BUCTL:0xF
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.my_UF0STR:0x2
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.rb_ResponseTimeMax_mg:100
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.rb_ResponseTime_g:0
TEST.EXPECTED:uut_prototype_stubs.ApplLinProtocolError.error:8
TEST.END

-- Test Case: linProtocolErrorCase0x0001
TEST.UNIT:G5_LINsci_sr
TEST.SUBPROGRAM:SCIVLIN_NEC_errorInterrupt
TEST.NEW
TEST.NAME:linProtocolErrorCase0x0001
TEST.NOTES:
This is an automatically generated test case.
   Test Path 9
      (1) if ((rw_err_typ_l & (2)) > (0)) ==> TRUE
      (2) if (rb_ResponseTime_g > rb_ResponseTimeMax_mg) ==> FALSE
   Test Case Generation Notes:
      Conflict: Unable to validate expression-to-expression comparison in branch 1
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.my_UF0STR:0x1
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.rb_ResponseTimeMax_mg:<<MAX>>
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.rb_ResponseTime_g:<<MIN>>
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.my_UF0STR:0x1
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.rb_ResponseTimeMax_mg:<<MAX>>
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.rb_ResponseTime_g:<<MIN>>
TEST.END

-- Test Case: linProtocolErrorCase0x0004
TEST.UNIT:G5_LINsci_sr
TEST.SUBPROGRAM:SCIVLIN_NEC_errorInterrupt
TEST.NEW
TEST.NAME:linProtocolErrorCase0x0004
TEST.NOTES:
This is an automatically generated test case.
   Test Path 9
      (1) if ((rw_err_typ_l & (2)) > (0)) ==> TRUE
      (2) if (rb_ResponseTime_g > rb_ResponseTimeMax_mg) ==> FALSE
   Test Case Generation Notes:
      Conflict: Unable to validate expression-to-expression comparison in branch 1
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.my_rw_err_typ_l:0x4
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.my_UF0STR:4
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.rb_ResponseTimeMax_mg:<<MAX>>
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.rb_ResponseTime_g:<<MIN>>
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.my_rw_err_typ_l:0x4
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.my_UF0STR:4
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.rb_ResponseTimeMax_mg:<<MAX>>
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.rb_ResponseTime_g:<<MIN>>
TEST.END

-- Test Case: linProtocolErrorCase0x0008
TEST.UNIT:G5_LINsci_sr
TEST.SUBPROGRAM:SCIVLIN_NEC_errorInterrupt
TEST.NEW
TEST.NAME:linProtocolErrorCase0x0008
TEST.NOTES:
This is an automatically generated test case.
   Test Path 9
      (1) if ((rw_err_typ_l & (2)) > (0)) ==> TRUE
      (2) if (rb_ResponseTime_g > rb_ResponseTimeMax_mg) ==> FALSE
   Test Case Generation Notes:
      Conflict: Unable to validate expression-to-expression comparison in branch 1
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.my_rw_err_typ_l:0x8
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.my_UF0STR:0x8
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.rb_ResponseTimeMax_mg:<<MAX>>
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.rb_ResponseTime_g:<<MIN>>
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.my_rw_err_typ_l:0x8
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.my_UF0STR:0x8
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.rb_ResponseTimeMax_mg:<<MAX>>
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.rb_ResponseTime_g:<<MIN>>
TEST.END

-- Test Case: linProtocolErrorCase0x2000
TEST.UNIT:G5_LINsci_sr
TEST.SUBPROGRAM:SCIVLIN_NEC_errorInterrupt
TEST.NEW
TEST.NAME:linProtocolErrorCase0x2000
TEST.NOTES:
This is an automatically generated test case.
   Test Path 9
      (1) if ((rw_err_typ_l & (2)) > (0)) ==> TRUE
      (2) if (rb_ResponseTime_g > rb_ResponseTimeMax_mg) ==> FALSE
   Test Case Generation Notes:
      Conflict: Unable to validate expression-to-expression comparison in branch 1
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.my_rw_err_typ_l:0x2000
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.my_UF0STR:8192
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.rb_ResponseTimeMax_mg:<<MAX>>
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.rb_ResponseTime_g:<<MIN>>
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.my_rw_err_typ_l:0x2000
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.my_UF0STR:8192
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.rb_ResponseTimeMax_mg:<<MAX>>
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.rb_ResponseTime_g:<<MIN>>
TEST.END

-- Test Case: linProtocolErrorCase0x4000
TEST.UNIT:G5_LINsci_sr
TEST.SUBPROGRAM:SCIVLIN_NEC_errorInterrupt
TEST.NEW
TEST.NAME:linProtocolErrorCase0x4000
TEST.NOTES:
This is an automatically generated test case.
   Test Path 9
      (1) if ((rw_err_typ_l & (2)) > (0)) ==> TRUE
      (2) if (rb_ResponseTime_g > rb_ResponseTimeMax_mg) ==> FALSE
   Test Case Generation Notes:
      Conflict: Unable to validate expression-to-expression comparison in branch 1
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.my_rw_err_typ_l:0x4000
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.my_UF0STR:0x4000
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.rb_ResponseTimeMax_mg:<<MAX>>
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.rb_ResponseTime_g:<<MIN>>
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.my_rw_err_typ_l:0x4000
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.my_UF0STR:0x4000
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.rb_ResponseTimeMax_mg:<<MAX>>
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.rb_ResponseTime_g:<<MIN>>
TEST.END

-- Test Case: linProtocolErrorCaseDefault
TEST.UNIT:G5_LINsci_sr
TEST.SUBPROGRAM:SCIVLIN_NEC_errorInterrupt
TEST.NEW
TEST.NAME:linProtocolErrorCaseDefault
TEST.BASIS_PATH:9 of 11
TEST.NOTES:
This is an automatically generated test case.
   Test Path 9
      (1) if ((rw_err_typ_l & (2)) > (0)) ==> TRUE
      (2) if (rb_ResponseTime_g > rb_ResponseTimeMax_mg) ==> FALSE
   Test Case Generation Notes:
      Conflict: Unable to validate expression-to-expression comparison in branch 1
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.rb_ResponseTimeMax_mg:<<MAX>>
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.rb_ResponseTime_g:<<MIN>>
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.rb_ResponseTimeMax_mg:<<MAX>>
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.rb_ResponseTime_g:<<MIN>>
TEST.END

-- Subprogram: SioInterrupt

-- Test Case: SioInterrupt.001
TEST.UNIT:G5_LINsci_sr
TEST.SUBPROGRAM:SioInterrupt
TEST.NEW
TEST.NAME:SioInterrupt.001
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.my_UF0OPT1:0
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.my_UF0TXE:<<MAX>>
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.my_UF0OPT1:0x6
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.my_UF0TXE:1
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.rb_WakeupCounter_mg:0
TEST.END

-- Test Case: SioInterrupt.002
TEST.UNIT:G5_LINsci_sr
TEST.SUBPROGRAM:SioInterrupt
TEST.NEW
TEST.NAME:SioInterrupt.002
TEST.STUB:G5_LINsci_sr.set_rab_ReadBuffer_mg
TEST.STUB:G5_LINsci_sr.sci_CheckParity
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.my_UF0OPT1:0x6
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.my_UF0TXE:1
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.my_UF0STR:0x800
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.my_UF0ID:1
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.my_kLinNumberOfTxObjects:1
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.my_kLinNumberOfRxObjects:2
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.rab_ReadBuffer_mg[1]:0x10
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.rabRAMLinMsgIDToHandleTbl[16]:0x10
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.uF_sciState_mg.Bit.B3:1
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.uF_sciState_mg.Bit.B7:1
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.my_UF0BUCTL:0x40
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.rw_NoCommunicationCounter_g:0
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.rb_ResponseTime_g:0
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.uF_ASIC_ControlFlags_g.Bit.B3:<<MAX>>
TEST.EXPECTED:G5_LINsci_sr.set_rab_ReadBuffer_mg.rb_position_l:1
TEST.EXPECTED:G5_LINsci_sr.set_rab_ReadBuffer_mg.rb_value_l:1
TEST.EXPECTED:G5_LINsci_sr.sci_CheckParity.rb_Data:0x10
TEST.END

-- Test Case: SioInterrupt.003
TEST.UNIT:G5_LINsci_sr
TEST.SUBPROGRAM:SioInterrupt
TEST.NEW
TEST.NAME:SioInterrupt.003
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.uF_sciState_mg.Bit.B3:0
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.uF_sciState_mg.Bit.B4:1
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.uF_sciState_mg.Bit.B7:0
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.my_UF0BUCTL:<<MAX>>
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.my_UF0TXE:0
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.my_UF0STR:0x800
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.my_kLinNumberOfTxObjects:10
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.my_kLinNumberOfRxObjects:10
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.rab_ReadBuffer_mg[1]:0x10
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.rabRAMLinMsgIDToHandleTbl[16]:0x10
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.uF_sciState_mg.Bit.B3:1
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.uF_sciState_mg.Bit.B4:1
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.uF_sciState_mg.Bit.B7:0
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.my_UF0BUCTL:0x40
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.rb_MsgHandle_mg:0x0
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.rw_NoCommunicationCounter_g:0
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.rb_ResponseTime_g:0
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.uF_ASIC_ControlFlags_g.Bit.B3:1
TEST.EXPECTED:uut_prototype_stubs.ApplLinProtocolError.error:0x2
TEST.END

-- Test Case: SioInterrupt.004
TEST.UNIT:G5_LINsci_sr
TEST.SUBPROGRAM:SioInterrupt
TEST.NEW
TEST.NAME:SioInterrupt.004
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.uF_sciState_mg.Bit.B3:0
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.uF_sciState_mg.Bit.B4:0
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.uF_sciState_mg.Bit.B7:0
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.my_cabLinRxDLCTbl[3]:0xC
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.my_UF0BUCTL:<<MIN-1>>
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.my_UF0CTL1:0xF
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.my_UF0TXE:0
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.my_UF0STR:0x800
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.my_UF0ID:0xF
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.my_kLinNumberOfTxObjects:12
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.my_kLinNumberOfRxObjects:10
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.rab_ReadBuffer_mg[1]:0xF
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.rabRAMLinMsgIDToHandleTbl[15]:0xF
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.uF_sciState_mg.Bit.B3:1
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.uF_sciState_mg.Bit.B4:0
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.uF_sciState_mg.Bit.B7:0
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.my_cabLinRxDLCTbl[3]:0xC
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.my_UF0BUCTL:0x40
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.my_UF0CTL1:15
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.my_UF0TXE:0
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.rab_ReadBuffer_mg[1]:0xF
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.rb_MsgHandle_mg:0xF
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.rb_ResponseTimeMax_mg:0
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.rw_NoCommunicationCounter_g:0
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.rb_MessageLength_mg:0x0
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.rb_ResponseTime_g:0x0
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.uF_ASIC_ControlFlags_g.Bit.B3:1
TEST.EXPECTED:uut_prototype_stubs.ApplLinProtocolError.error:0x2
TEST.END

-- Test Case: SioInterrupt.005
TEST.UNIT:G5_LINsci_sr
TEST.SUBPROGRAM:SioInterrupt
TEST.NEW
TEST.NAME:SioInterrupt.005
TEST.STUB:G5_LINsci_sr.set_rab_ReadBuffer_mg
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.my_UF0STR:0x400
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.rab_ReadBuffer_mg[2]:0xA0
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.rab_ReadBuffer_mg[3]:0x1
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.rab_ReadBuffer_mg[4]:0x55
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.rab_ReadBuffer_mg[5]:0x56
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.rab_ReadBuffer_mg[6]:0x61
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.rab_ReadBuffer_mg[7]:0x4C
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.rab_ReadBuffer_mg[8]:0x65
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.rab_ReadBuffer_mg[9]:0x4F
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.rb_MessageLength_mg:8
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.uF_sciState_mg.Bit.B3:1
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.rb_WakeupCounter_mg:0
TEST.EXPECTED:G5_LINsci_sr.set_rab_ReadBuffer_mg.rb_position_l:2,3,4,5,6,7,8,9
TEST.EXPECTED:G5_LINsci_sr.set_rab_ReadBuffer_mg.rb_value_l:(8)255
TEST.END

-- Test Case: SioInterrupt.006
TEST.UNIT:G5_LINsci_sr
TEST.SUBPROGRAM:SioInterrupt
TEST.NEW
TEST.NAME:SioInterrupt.006
TEST.STUB:G5_LINsci_sr.set_rab_ReadBuffer_mg
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.my_UF0STR:0x400
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.rab_ReadBuffer_mg[2]:0x0
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.rab_ReadBuffer_mg[3]:0x0
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.rab_ReadBuffer_mg[4]:0x0
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.rab_ReadBuffer_mg[5]:0x0
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.rab_ReadBuffer_mg[6]:0x0
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.rab_ReadBuffer_mg[7]:0x0
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.rab_ReadBuffer_mg[8]:0x0
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.rab_ReadBuffer_mg[9]:0x0
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.rb_MessageLength_mg:8
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.uF_sciState_mg.Bit.B3:1
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.rb_WakeupCounter_mg:0
TEST.EXPECTED:G5_LINsci_sr.set_rab_ReadBuffer_mg.rb_position_l:2,3,4,5,6,7,8,9
TEST.EXPECTED:G5_LINsci_sr.set_rab_ReadBuffer_mg.rb_value_l:(8)255
TEST.END

-- Test Case: SioInterrupt.007
TEST.UNIT:G5_LINsci_sr
TEST.SUBPROGRAM:SioInterrupt
TEST.NEW
TEST.NAME:SioInterrupt.007
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:FALSE
TEST.STUB:G5_LINsci_sr.sci_CheckParity
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.uF_sciState_mg.Bit.B3:0
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.uF_sciState_mg.Bit.B4:0
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.uF_sciState_mg.Bit.B7:1
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.my_cabLinRxDLCTbl[3]:0xC
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.my_UF0CTL1:0xF
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.my_UF0TXE:0
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.my_UF0STR:0x800
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.my_UF0ID:0x3C
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.my_kLinNumberOfTxObjects:57
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.my_kLinNumberOfRxObjects:20
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.rab_ReadBuffer_mg[1]:0x3C
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.rabRAMLinMsgIDToHandleTbl[60]:0x3C
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.uF_sciState_mg.Bit.B3:1
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.uF_sciState_mg.Bit.B4:0
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.uF_sciState_mg.Bit.B7:1
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.my_UF0BUCTL:0x40
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.rab_ReadBuffer_mg[1]:0x3C
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.rb_MsgHandle_mg:0x3C
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.rb_ResponseTimeMax_mg:0
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.rw_NoCommunicationCounter_g:0
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.rb_MessageLength_mg:0x0
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.rb_ResponseTime_g:0x0
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.uF_ASIC_ControlFlags_g.Bit.B3:1
TEST.EXPECTED:G5_LINsci_sr.sci_CheckParity.rb_Data:0x3C
TEST.END

-- Test Case: SioInterrupt.008
TEST.UNIT:G5_LINsci_sr
TEST.SUBPROGRAM:SioInterrupt
TEST.NEW
TEST.NAME:SioInterrupt.008
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:FALSE
TEST.STUB:G5_LINsci_sr.sci_CheckParity
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.uF_sciState_mg.Bit.B4:0
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.uF_sciState_mg.Bit.B7:1
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.my_cabLinRxDLCTbl[3]:0xC
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.my_UF0CTL1:0xF
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.my_UF0TXE:0
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.my_UF0STR:0x800
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.my_UF0ID:0x3C
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.my_kLinNumberOfTxObjects:57
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.my_kLinNumberOfRxObjects:20
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.rab_ReadBuffer_mg[1]:0x3C
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.uF_SCIFlags_mg.Bit.B3:1
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.rabRAMLinMsgIDToHandleTbl[60]:0x3C
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.uF_sciState_mg.Bit.B4:0
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.uF_sciState_mg.Bit.B7:1
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.rab_ReadBuffer_mg[1]:0x3C
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.rb_MsgHandle_mg:0x3C
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.rb_ResponseTimeMax_mg:0
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.rw_NoCommunicationCounter_g:0
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.rb_ResponseTime_g:0x0
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.uF_ASIC_ControlFlags_g.Bit.B3:1
TEST.EXPECTED:G5_LINsci_sr.sci_CheckParity.rb_Data:0x3C
TEST.END

-- Test Case: SioInterrupt.009
TEST.UNIT:G5_LINsci_sr
TEST.SUBPROGRAM:SioInterrupt
TEST.NEW
TEST.NAME:SioInterrupt.009
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:FALSE
TEST.STUB:G5_LINsci_sr.sci_CheckParity
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.uF_sciState_mg.Bit.B4:0
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.uF_sciState_mg.Bit.B7:1
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.my_cabLinRxDLCTbl[3]:0xC
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.my_UF0CTL1:0xF
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.my_UF0TXE:0
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.my_UF0STR:0x800
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.my_UF0ID:0x3C
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.my_kLinNumberOfTxObjects:61
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.my_kLinNumberOfRxObjects:16
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.rab_ReadBuffer_mg[1]:0x3C
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.uF_SCIFlags_mg.Bit.B3:1
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.rabRAMLinMsgIDToHandleTbl[60]:0x3C
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.uF_sciState_mg.Bit.B7:1
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.rab_ReadBuffer_mg[1]:0x3C
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.rb_MsgHandle_mg:0x3C
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.rb_ResponseTimeMax_mg:0
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.rw_NoCommunicationCounter_g:0
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.rb_ResponseTime_g:0x0
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.uF_ASIC_ControlFlags_g.Bit.B3:1
TEST.EXPECTED:G5_LINsci_sr.sci_CheckParity.rb_Data:0x3C
TEST.END

-- Test Case: SioInterrupt.010
TEST.UNIT:G5_LINsci_sr
TEST.SUBPROGRAM:SioInterrupt
TEST.NEW
TEST.NAME:SioInterrupt.010
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:FALSE
TEST.STUB:G5_LINsci_sr.sci_CheckParity
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.uF_sciState_mg.Bit.B4:0
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.uF_sciState_mg.Bit.B7:1
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.my_cabLinRxDLCTbl[3]:0xC
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.my_UF0CTL1:0xF
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.my_UF0TXE:0
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.my_UF0STR:0x800
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.my_UF0ID:0x3D
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.my_kLinNumberOfTxObjects:57
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.my_kLinNumberOfRxObjects:20
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.rab_ReadBuffer_mg[1]:0x3D
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.uF_SCIFlags_mg.Bit.B3:1
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.rabRAMLinMsgIDToHandleTbl[60]:0x3D
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.rabRAMLinMsgIDToHandleTbl[61]:0x3D
TEST.VALUE:G5_LINsci_sr.sci_CheckParity.rb_Data:0x3D
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.uF_sciState_mg.Bit.B4:0
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.uF_sciState_mg.Bit.B7:1
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.rab_ReadBuffer_mg[1]:0x3D
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.rb_ResponseTimeMax_mg:0
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.rw_NoCommunicationCounter_g:0
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.rb_ResponseTime_g:0x0
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.uF_ASIC_ControlFlags_g.Bit.B3:1
TEST.EXPECTED:G5_LINsci_sr.sci_CheckParity.rb_Data:0x3D
TEST.END

-- Subprogram: r_uartf0_interrupt_send

-- Test Case: r_uartf0_interrupt_send.001
TEST.UNIT:G5_LINsci_sr
TEST.SUBPROGRAM:r_uartf0_interrupt_send
TEST.NEW
TEST.NAME:r_uartf0_interrupt_send.001
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.uF_sciState_mg.Bit.B3:1
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.uF_sciState_mg.Bit.B4:0
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.rb_ResponseTime_g:0
TEST.END

-- Subprogram: sci_CheckParity

-- Test Case: sci_CheckParity0x40Mask
TEST.UNIT:G5_LINsci_sr
TEST.SUBPROGRAM:sci_CheckParity
TEST.NEW
TEST.NAME:sci_CheckParity0x40Mask
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.uF_sciState_mg.Bit.B7:<<MIN>>
TEST.VALUE:G5_LINsci_sr.sci_CheckParity.rb_Data:<<MAX>>
TEST.VALUE:G5_LINsci_sr.sci_CheckParity.return:1
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.uF_sciState_mg.Bit.B7:<<MIN>>
TEST.EXPECTED:G5_LINsci_sr.sci_CheckParity.rb_Data:<<MAX>>
TEST.EXPECTED:G5_LINsci_sr.sci_CheckParity.return:0
TEST.END

-- Test Case: sci_CheckParity0x80Mask
TEST.UNIT:G5_LINsci_sr
TEST.SUBPROGRAM:sci_CheckParity
TEST.NEW
TEST.NAME:sci_CheckParity0x80Mask
TEST.BASIS_PATH:1 of 3
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if ((rb_Data & 64) != rb_Result_l) ==> FALSE
      (2) if ((rb_Data & 128) != rb_Result_l) ==> FALSE
   Test Case Generation Notes:
      Cannot set variable to unknown value in branch 1
      Cannot set variable to unknown value in branch 2
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.uF_sciState_mg.Bit.B7:<<MIN>>
TEST.VALUE:G5_LINsci_sr.sci_CheckParity.rb_Data:<<MIN>>
TEST.VALUE:G5_LINsci_sr.sci_CheckParity.return:1
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.uF_sciState_mg.Bit.B7:<<MIN>>
TEST.EXPECTED:G5_LINsci_sr.sci_CheckParity.return:0
TEST.END

-- Test Case: sci_CheckParityBothMaskFalse
TEST.UNIT:G5_LINsci_sr
TEST.SUBPROGRAM:sci_CheckParity
TEST.NEW
TEST.NAME:sci_CheckParityBothMaskFalse
TEST.BASIS_PATH:2 of 3
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if ((rb_Data & 64) != rb_Result_l) ==> FALSE
      (2) if ((rb_Data & 128) != rb_Result_l) ==> TRUE
   Test Case Generation Notes:
      Cannot set variable to unknown value in branch 1
      Cannot set variable to unknown value in branch 2
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_LINsci_sr.sci_CheckParity.rb_Data:0x80
TEST.VALUE:G5_LINsci_sr.sci_CheckParity.return:0
TEST.EXPECTED:G5_LINsci_sr.sci_CheckParity.rb_Data:0x80
TEST.EXPECTED:G5_LINsci_sr.sci_CheckParity.return:1
TEST.END

-- Subprogram: sci_Communication

-- Test Case: sci_Communication.001
TEST.UNIT:G5_LINsci_sr
TEST.SUBPROGRAM:sci_Communication
TEST.NEW
TEST.NAME:sci_Communication.001
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.my_UF0OPT1:0
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.rb_WakeupTimer_mg:1
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.rb_WakeupCounter_mg:3
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.rb_WDG_SCITaskCounter_g:1
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.uF_sciState_mg.Bit.B4:0
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.my_UF0OPT1:0
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.my_UF0TXE:1
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.rb_WakeupTimer_mg:159
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.rw_NoCommunicationCounter_g:0
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.rb_WakeupCounter_mg:1
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.rb_WDG_SCITaskCounter_g:2
TEST.END

-- Test Case: sci_Communication.002
TEST.UNIT:G5_LINsci_sr
TEST.SUBPROGRAM:sci_Communication
TEST.NEW
TEST.NAME:sci_Communication.002
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.rb_WakeupTimer_mg:2
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.rb_WakeupCounter_mg:1
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.rb_WDG_SCITaskCounter_g:1
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.rb_WakeupTimer_mg:1
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.rb_WakeupCounter_mg:1
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.rb_WDG_SCITaskCounter_g:2
TEST.END

-- Test Case: sci_Communication.003
TEST.UNIT:G5_LINsci_sr
TEST.SUBPROGRAM:sci_Communication
TEST.NEW
TEST.NAME:sci_Communication.003
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.my_UF0OPT1:0
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.rb_WakeupTimer_mg:1
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.rb_WakeupCounter_mg:1
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.rb_WDG_SCITaskCounter_g:1
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.uF_sciState_mg.Bit.B4:0
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.my_UF0OPT1:0
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.my_UF0TXE:1
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.rb_WakeupTimer_mg:17
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.rw_NoCommunicationCounter_g:0
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.rb_WakeupCounter_mg:2
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.rb_WDG_SCITaskCounter_g:2
TEST.END

-- Test Case: sci_Communication.004
TEST.UNIT:G5_LINsci_sr
TEST.SUBPROGRAM:sci_Communication
TEST.NEW
TEST.NAME:sci_Communication.004
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.rb_WakeupCounter_mg:0
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.rb_WDG_SCITaskCounter_g:1
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.rb_WDG_SCITaskCounter_g:2
TEST.END

-- Subprogram: sci_CopyReceiveBuffer

-- Test Case: sci_CopyReceiveMasterReq0x3C
TEST.UNIT:G5_LINsci_sr
TEST.SUBPROGRAM:sci_CopyReceiveBuffer
TEST.NEW
TEST.NAME:sci_CopyReceiveMasterReq0x3C
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if ((uF_sciState_mg.Bit).B7 == 1) ==> TRUE
      (2) while (rb_Length_l > 0) ==> FALSE
      (3) if (rb_Message_ID_l == 60) ==> FALSE
   Test Case Generation Notes:
      Cannot set const variable G5_LINsci_sr.<<GLOBAL>>.cabLinMsgHandleTbl[0]: in branch 1
      Cannot set const variable TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.cabLinRxDataLenTbl[0]: in branch 2
      Cannot set const variable G5_LINsci_sr.<<GLOBAL>>.cabLinMsgHandleTbl[0]: in branch 2
      Cannot set rb_Message_ID_l due to assignment
      Cannot set const variable G5_LINsci_sr.<<GLOBAL>>.cabLinMsgHandleTbl[0]: in branch 3
      Cannot set const variable TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.cabLinRxDataLenTbl[0]: in branch 3
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.uF_sciState_mg.Bit.B7:1
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.my_cabLinMsgHandleTbl[3]:2
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.rab_ReadBuffer_mg[1]:0x3C
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.rab_ReadBuffer_mg[2]:1
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.rb_MsgHandle_mg:<<MAX>>
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.rabRAMLinMsgIDToHandleTbl[60]:0x3
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.uF_sciState_mg.Bit.B7:0
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.my_cabLinMsgHandleTbl[3]:2
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.rab_ReadBuffer_mg[1]:0x3C
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.rab_ReadBuffer_mg[2]:1
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.rb_MsgHandle_mg:2
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.rabRAMLinMsgIDToHandleTbl[60]:0x3
TEST.END

-- Test Case: sci_CopyReceiveProtocolError
TEST.UNIT:G5_LINsci_sr
TEST.SUBPROGRAM:sci_CopyReceiveBuffer
TEST.NEW
TEST.NAME:sci_CopyReceiveProtocolError
TEST.BASIS_PATH:1 of 5
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if ((uF_sciState_mg.Bit).B7 == 1) ==> FALSE
   Test Case Generation Notes:
      Cannot set const variable G5_LINsci_sr.<<GLOBAL>>.cabLinMsgHandleTbl[0]: in branch 1
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.uF_sciState_mg.Bit.B7:<<MIN>>
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.rab_ReadBuffer_mg[1]:0x10
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.uF_sciState_mg.Bit.B7:<<MIN>>
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.rab_ReadBuffer_mg[1]:0x10
TEST.END

-- Test Case: sci_CopyReceiveSleep0x3C
TEST.UNIT:G5_LINsci_sr
TEST.SUBPROGRAM:sci_CopyReceiveBuffer
TEST.NEW
TEST.NAME:sci_CopyReceiveSleep0x3C
TEST.BASIS_PATH:2 of 5
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if ((uF_sciState_mg.Bit).B7 == 1) ==> TRUE
      (2) while (rb_Length_l > 0) ==> FALSE
      (3) if (rb_Message_ID_l == 60) ==> FALSE
   Test Case Generation Notes:
      Cannot set const variable G5_LINsci_sr.<<GLOBAL>>.cabLinMsgHandleTbl[0]: in branch 1
      Cannot set const variable TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.cabLinRxDataLenTbl[0]: in branch 2
      Cannot set const variable G5_LINsci_sr.<<GLOBAL>>.cabLinMsgHandleTbl[0]: in branch 2
      Cannot set rb_Message_ID_l due to assignment
      Cannot set const variable G5_LINsci_sr.<<GLOBAL>>.cabLinMsgHandleTbl[0]: in branch 3
      Cannot set const variable TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.cabLinRxDataLenTbl[0]: in branch 3
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.uF_sciState_mg.Bit.B7:1
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.my_cabLinMsgHandleTbl[2]:2
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.my_cabLinRxDataLenTbl[2]:8
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.rab_ReadBuffer_mg[1]:0x3C
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.rab_ReadBuffer_mg[2]:0
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.rb_MsgHandle_mg:<<MAX>>
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.rabRAMLinMsgIDToHandleTbl[60]:2
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.uF_sciState_mg.Bit.B7:0
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.my_cabLinMsgHandleTbl[2]:2
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.my_cabLinRxDataLenTbl[2]:8
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.rab_ReadBuffer_mg[1]:0x3C
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.rab_ReadBuffer_mg[2]:0
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.rb_MsgHandle_mg:2
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.rabRAMLinMsgIDToHandleTbl[60]:2
TEST.END

-- Test Case: sci_CopyReceiveValid0x30
TEST.UNIT:G5_LINsci_sr
TEST.SUBPROGRAM:sci_CopyReceiveBuffer
TEST.NEW
TEST.NAME:sci_CopyReceiveValid0x30
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if ((uF_sciState_mg.Bit).B7 == 1) ==> TRUE
      (2) while (rb_Length_l > 0) ==> FALSE
      (3) if (rb_Message_ID_l == 60) ==> FALSE
   Test Case Generation Notes:
      Cannot set const variable G5_LINsci_sr.<<GLOBAL>>.cabLinMsgHandleTbl[0]: in branch 1
      Cannot set const variable TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.cabLinRxDataLenTbl[0]: in branch 2
      Cannot set const variable G5_LINsci_sr.<<GLOBAL>>.cabLinMsgHandleTbl[0]: in branch 2
      Cannot set rb_Message_ID_l due to assignment
      Cannot set const variable G5_LINsci_sr.<<GLOBAL>>.cabLinMsgHandleTbl[0]: in branch 3
      Cannot set const variable TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.cabLinRxDataLenTbl[0]: in branch 3
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.uF_sciState_mg.Bit.B7:1
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.my_cabLinMsgHandleTbl[2]:3
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.rab_ReadBuffer_mg[1]:0x30
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.rb_MsgHandle_mg:<<MAX>>
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.rabRAMLinMsgIDToHandleTbl[48]:2
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.rabRAMLinMsgIDToHandleTbl[60]:0
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.uF_sciState_mg.Bit.B7:0
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.my_cabLinMsgHandleTbl[2]:3
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.rab_ReadBuffer_mg[1]:0x30
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.rb_MsgHandle_mg:3
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.rabRAMLinMsgIDToHandleTbl[48]:2
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.rabRAMLinMsgIDToHandleTbl[60]:0
TEST.END

-- Subprogram: sci_GetLINMsgID

-- Test Case: sci_GetLINMsgID
TEST.UNIT:G5_LINsci_sr
TEST.SUBPROGRAM:sci_GetLINMsgID
TEST.NEW
TEST.NAME:sci_GetLINMsgID
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.rab_ReadBuffer_mg[0]:0
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.rab_ReadBuffer_mg[1]:0xF
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.rab_ReadBuffer_mg[2]:0
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.rab_ReadBuffer_mg[3]:0
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.rab_ReadBuffer_mg[4]:0
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.rab_ReadBuffer_mg[5]:0
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.rab_ReadBuffer_mg[6]:0
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.rab_ReadBuffer_mg[7]:0
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.rab_ReadBuffer_mg[8]:0
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.rab_ReadBuffer_mg[9]:0
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.rab_ReadBuffer_mg[10]:0
TEST.VALUE:G5_LINsci_sr.sci_GetLINMsgID.return:0x0
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.rab_ReadBuffer_mg[0]:0
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.rab_ReadBuffer_mg[1]:0xF
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.rab_ReadBuffer_mg[2]:0
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.rab_ReadBuffer_mg[3]:0
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.rab_ReadBuffer_mg[4]:0
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.rab_ReadBuffer_mg[5]:0
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.rab_ReadBuffer_mg[6]:0
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.rab_ReadBuffer_mg[7]:0
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.rab_ReadBuffer_mg[8]:0
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.rab_ReadBuffer_mg[9]:0
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.rab_ReadBuffer_mg[10]:0
TEST.EXPECTED:G5_LINsci_sr.sci_GetLINMsgID.return:0xF
TEST.END

-- Subprogram: sci_WriteMessage

-- Test Case: writeNoSend0x3D
TEST.UNIT:G5_LINsci_sr
TEST.SUBPROGRAM:sci_WriteMessage
TEST.NEW
TEST.NAME:writeNoSend0x3D
TEST.BASIS_PATH:6 of 6
TEST.NOTES:
This is an automatically generated test case.
   Test Path 6
      (1) if (rb_MessageID == 61) ==> TRUE
      (2) if (rb_Send_l == 1) ==> FALSE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.rb_MsgHandle_mg:0
TEST.VALUE:G5_LINsci_sr.sci_WriteMessage.rb_MessageID:61
TEST.VALUE:uut_prototype_stubs.ApplLinSlaveCmdFrmFct.return:<<MIN>>
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.my_UF0BUCTL:0x40
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.rb_MsgHandle_mg:0
TEST.EXPECTED:G5_LINsci_sr.sci_WriteMessage.rb_MessageID:<<ANY>>
TEST.END

-- Test Case: writeSend0x0
TEST.UNIT:G5_LINsci_sr
TEST.SUBPROGRAM:sci_WriteMessage
TEST.NEW
TEST.NAME:writeSend0x0
TEST.BASIS_PATH:1 of 6
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (rb_MessageID == 61) ==> FALSE
      (2) if (rb_Send_l == 1) ==> FALSE
   Test Case Generation Notes:
      Cannot set rb_Send_l due to assignment
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.my_cabLinTxDataLenTbl[0]:0x2
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.rb_MsgHandle_mg:0
TEST.VALUE:G5_LINsci_sr.sci_WriteMessage.rb_MessageID:<<MIN>>
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.uF_sciState_mg.Bit.B4:1
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.my_UF0BUCTL:0x292
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.rb_MsgHandle_mg:0
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.rb_WBPosition_mg:3
TEST.EXPECTED:G5_LINsci_sr.sci_WriteMessage.rb_MessageID:<<ANY>>
TEST.EXPECTED:uut_prototype_stubs.ApplLinSlavePreCopy.rb_MessageID_l:<<MIN>>
TEST.END

-- Test Case: writeSend0x3C
TEST.UNIT:G5_LINsci_sr
TEST.SUBPROGRAM:sci_WriteMessage
TEST.NEW
TEST.NAME:writeSend0x3C
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (rb_MessageID == 61) ==> FALSE
      (2) if (rb_Send_l == 1) ==> FALSE
   Test Case Generation Notes:
      Cannot set rb_Send_l due to assignment
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.my_cabLinTxDataLenTbl[0]:<<MIN>>
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.my_cabLinTxDataLenTbl[1]:4
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.my_cabLinTxDataLenTbl[2..3]:<<MIN>>
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.my_capbLinTxDataPtrTbl[1][0]:<<MIN>>
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.my_capbLinTxDataPtrTbl[1][1]:5
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.my_capbLinTxDataPtrTbl[1][2]:10
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.my_capbLinTxDataPtrTbl[1][3]:<<MAX>>
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.rab_WriteBuffer_mg[1]:<<MID>>
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.rab_WriteBuffer_mg[2]:<<MID>>
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.rab_WriteBuffer_mg[3]:<<MIN>>
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.rab_WriteBuffer_mg[4]:<<MIN>>
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.rab_WriteBuffer_mg[5]:<<MIN>>
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.rb_MsgHandle_mg:1
TEST.VALUE:G5_LINsci_sr.sci_WriteMessage.rb_MessageID:0x3C
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.my_cabLinTxDataLenTbl[0]:<<MIN>>
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.my_cabLinTxDataLenTbl[1]:4
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.my_cabLinTxDataLenTbl[2..3]:<<MIN>>
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.my_capbLinTxDataPtrTbl[1][0]:<<MIN>>
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.my_capbLinTxDataPtrTbl[1][1]:5
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.my_capbLinTxDataPtrTbl[1][2]:10
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.my_capbLinTxDataPtrTbl[1][3]:<<MAX>>
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.rab_WriteBuffer_mg[1]:<<MIN>>
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.rab_WriteBuffer_mg[2]:5
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.rab_WriteBuffer_mg[3]:10
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.rab_WriteBuffer_mg[4]:<<MAX>>
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.rab_WriteBuffer_mg[5]:<<MIN>>
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.rb_MsgHandle_mg:1
TEST.EXPECTED:G5_LINsci_sr.sci_WriteMessage.rb_MessageID:0x3C
TEST.END

-- Test Case: writeSend0x3CLen
TEST.UNIT:G5_LINsci_sr
TEST.SUBPROGRAM:sci_WriteMessage
TEST.NEW
TEST.NAME:writeSend0x3CLen
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (rb_MessageID == 61) ==> FALSE
      (2) if (rb_Send_l == 1) ==> FALSE
   Test Case Generation Notes:
      Cannot set rb_Send_l due to assignment
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.my_cabLinTxDataLenTbl[1]:5
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.my_capbLinTxDataPtrTbl[1][0]:<<MIN>>
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.my_capbLinTxDataPtrTbl[1][1]:5
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.my_capbLinTxDataPtrTbl[1][2]:10
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.my_capbLinTxDataPtrTbl[1][3]:<<MAX>>
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.rab_WriteBuffer_mg[1]:<<MID>>
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.rab_WriteBuffer_mg[2]:<<MID>>
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.rab_WriteBuffer_mg[3]:<<MIN>>
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.rab_WriteBuffer_mg[4]:<<MIN>>
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.rab_WriteBuffer_mg[5]:<<MIN>>
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.rb_MsgHandle_mg:1
TEST.VALUE:G5_LINsci_sr.sci_WriteMessage.rb_MessageID:0x3C
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.my_cabLinTxDataLenTbl[1]:5
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.my_capbLinTxDataPtrTbl[1][0]:<<MIN>>
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.my_capbLinTxDataPtrTbl[1][1]:5
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.my_capbLinTxDataPtrTbl[1][2]:10
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.my_capbLinTxDataPtrTbl[1][3]:<<MAX>>
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.rab_WriteBuffer_mg[1]:<<MIN>>
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.rab_WriteBuffer_mg[2]:5
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.rab_WriteBuffer_mg[3]:10
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.rab_WriteBuffer_mg[4]:<<MAX>>
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.rab_WriteBuffer_mg[5]:<<MIN>>
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.rb_MsgHandle_mg:1
TEST.EXPECTED:G5_LINsci_sr.sci_WriteMessage.rb_MessageID:0x3C
TEST.END

-- Test Case: writeSend0x3D
TEST.UNIT:G5_LINsci_sr
TEST.SUBPROGRAM:sci_WriteMessage
TEST.NEW
TEST.NAME:writeSend0x3D
TEST.NOTES:
This is an automatically generated test case.
   Test Path 6
      (1) if (rb_MessageID == 61) ==> TRUE
      (2) if (rb_Send_l == 1) ==> FALSE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.rb_MsgHandle_mg:0
TEST.VALUE:G5_LINsci_sr.sci_WriteMessage.rb_MessageID:61
TEST.VALUE:uut_prototype_stubs.ApplLinSlaveCmdFrmFct.return:1
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.uF_sciState_mg.Bit.B4:1
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.my_UF0BUCTL:0x210
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.rb_WBPosition_mg:1
TEST.END

-- Subprogram: sci_init

-- Test Case: sci_init.001
TEST.UNIT:G5_LINsci_sr
TEST.SUBPROGRAM:sci_init
TEST.NEW
TEST.NAME:sci_init.001
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:FALSE
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.my_UF0OPT1:2
TEST.VALUE:G5_LINsci_sr.sci_init.rb_WakeUpFrame_l:1
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.uF_sciState_mg.Bit.B4:<<MIN>>
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.my_UF0OPT1:0
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.my_UF0TXE:1
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.rb_WakeupTimer_mg:17
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.rw_NoCommunicationCounter_g:<<MIN>>
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.rb_WakeupCounter_mg:2
TEST.END

-- Test Case: sci_init.002
TEST.UNIT:G5_LINsci_sr
TEST.SUBPROGRAM:sci_init
TEST.NEW
TEST.NAME:sci_init.002
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.my_UF0OPT1:0
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.my_UF0TXE:0
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.rb_WakeupTimer_mg:0
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.rw_NoCommunicationCounter_g:0
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.rb_WakeupCounter_mg:0
TEST.VALUE:G5_LINsci_sr.sci_init.rb_WakeUpFrame_l:0
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.my_UF0OPT1:0
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.my_UF0TXE:0
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.rb_WakeupTimer_mg:0
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.rw_NoCommunicationCounter_g:0
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.rb_WakeupCounter_mg:0
TEST.END

-- Subprogram: set_rab_ReadBuffer_mg

-- Test Case: set_rab_ReadBuffer_mg.001
TEST.UNIT:G5_LINsci_sr
TEST.SUBPROGRAM:set_rab_ReadBuffer_mg
TEST.NEW
TEST.NAME:set_rab_ReadBuffer_mg.001
TEST.NOTES:
Only set function is tested
Enabling and disabbling of the RAM Guard is tested in G5_Check_sr
Iterate over all 12 elements of the read buffer
Assign 244 to first element and add 1 to current element per iteration
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.rab_ReadBuffer_mg[0]:<<MAX>>
TEST.VALUE:G5_LINsci_sr.set_rab_ReadBuffer_mg.rb_position_l:0
TEST.VALUE:G5_LINsci_sr.set_rab_ReadBuffer_mg.rb_value_l:0
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.rab_ReadBuffer_mg[0]:<<MIN>>
TEST.EXPECTED:G5_LINsci_sr.set_rab_ReadBuffer_mg.rb_position_l:0
TEST.EXPECTED:G5_LINsci_sr.set_rab_ReadBuffer_mg.rb_value_l:0
TEST.END

-- Test Case: set_rab_ReadBuffer_mg.002
TEST.UNIT:G5_LINsci_sr
TEST.SUBPROGRAM:set_rab_ReadBuffer_mg
TEST.NEW
TEST.NAME:set_rab_ReadBuffer_mg.002
TEST.NOTES:
Only set function is tested
Enabling and disabbling of the RAM Guard is tested in G5_Check_sr
Iterate over all 12 elements of the read buffer
Assign 244 to first element and add 1 to current element per iteration
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.rab_ReadBuffer_mg[11]:<<MIN>>
TEST.VALUE:G5_LINsci_sr.set_rab_ReadBuffer_mg.rb_position_l:11
TEST.VALUE:G5_LINsci_sr.set_rab_ReadBuffer_mg.rb_value_l:255
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.rab_ReadBuffer_mg[11]:<<MAX>>
TEST.EXPECTED:G5_LINsci_sr.set_rab_ReadBuffer_mg.rb_position_l:11
TEST.EXPECTED:G5_LINsci_sr.set_rab_ReadBuffer_mg.rb_value_l:255
TEST.END

-- Subprogram: set_rab_WriteBuffer_mg

-- Test Case: set_rab_WriteBuffer_mg.001
TEST.UNIT:G5_LINsci_sr
TEST.SUBPROGRAM:set_rab_WriteBuffer_mg
TEST.NEW
TEST.NAME:set_rab_WriteBuffer_mg.001
TEST.NOTES:
Only set function is tested
Enabling and disabbling of the RAM Guard is tested in G5_Check_sr
Iterate over all 12 elements of the write buffer
Assign 0 to first element and add 21 to current element per iteration
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.rab_WriteBuffer_mg[0]:<<MAX>>
TEST.VALUE:G5_LINsci_sr.set_rab_WriteBuffer_mg.rb_position_l:0
TEST.VALUE:G5_LINsci_sr.set_rab_WriteBuffer_mg.rb_value_l:0
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.rab_WriteBuffer_mg[0]:<<MIN>>
TEST.EXPECTED:G5_LINsci_sr.set_rab_WriteBuffer_mg.rb_position_l:0
TEST.EXPECTED:G5_LINsci_sr.set_rab_WriteBuffer_mg.rb_value_l:0
TEST.END

-- Test Case: set_rab_WriteBuffer_mg.002
TEST.UNIT:G5_LINsci_sr
TEST.SUBPROGRAM:set_rab_WriteBuffer_mg
TEST.NEW
TEST.NAME:set_rab_WriteBuffer_mg.002
TEST.NOTES:
Only set function is tested
Enabling and disabbling of the RAM Guard is tested in G5_Check_sr
Iterate over all 12 elements of the write buffer
Assign 0 to first element and add 21 to current element per iteration
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_LINsci_sr.<<GLOBAL>>.rab_WriteBuffer_mg[0]:<<MIN>>
TEST.VALUE:G5_LINsci_sr.set_rab_WriteBuffer_mg.rb_position_l:0
TEST.VALUE:G5_LINsci_sr.set_rab_WriteBuffer_mg.rb_value_l:255
TEST.EXPECTED:G5_LINsci_sr.<<GLOBAL>>.rab_WriteBuffer_mg[0]:<<MAX>>
TEST.EXPECTED:G5_LINsci_sr.set_rab_WriteBuffer_mg.rb_position_l:0
TEST.EXPECTED:G5_LINsci_sr.set_rab_WriteBuffer_mg.rb_value_l:255
TEST.END
