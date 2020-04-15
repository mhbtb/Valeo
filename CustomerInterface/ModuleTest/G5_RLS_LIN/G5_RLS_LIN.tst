-- VectorCAST 6.2n
-- Test Case Script
-- 
-- Environment    : G5_RLS_LIN
-- Unit(s) Under Test: G5_RLS_LIN
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Unit: G5_RLS_LIN

-- Subprogram: ApplLinInit

-- Test Case: BASIS-PATH-001-LIN_State_0
TEST.UNIT:G5_RLS_LIN
TEST.SUBPROGRAM:ApplLinInit
TEST.NEW
TEST.NAME:BASIS-PATH-001-LIN_State_0
TEST.BASIS_PATH:1 of 2
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) while (rb_Index_l < 8) ==> FALSE
   Test Case Generation Notes:
      Cannot set rb_Index_l due to assignment
      Cannot set rb_Index_l due to assignment
      Cannot set rb_Index_l due to assignment
      Cannot set rb_Index_l due to assignment
      Cannot set rb_Index_l due to assignment
      Cannot set rb_Index_l due to assignment
      Cannot set rb_Index_l due to assignment
TEST.END_NOTES:
TEST.VALUE:G5_RLS_LIN.ApplLinInit.rb_LIN_State_l:0x0
TEST.EXPECTED:G5_RLS_LIN.<<GLOBAL>>.uF_SCIFlags_mg.Bit.B6:1
TEST.EXPECTED:G5_RLS_LIN.<<GLOBAL>>.uF_StatusRainsensor_mg.Bit.B7:1
TEST.EXPECTED:uut_prototype_stubs.sci_init.rb_WakeUpFrame_l:0x0
TEST.END

-- Test Case: BASIS-PATH-002-LIN_State_1
TEST.UNIT:G5_RLS_LIN
TEST.SUBPROGRAM:ApplLinInit
TEST.NEW
TEST.NAME:BASIS-PATH-002-LIN_State_1
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) while (rb_Index_l < 8) ==> FALSE
   Test Case Generation Notes:
      Cannot set rb_Index_l due to assignment
      Cannot set rb_Index_l due to assignment
      Cannot set rb_Index_l due to assignment
      Cannot set rb_Index_l due to assignment
      Cannot set rb_Index_l due to assignment
      Cannot set rb_Index_l due to assignment
      Cannot set rb_Index_l due to assignment
TEST.END_NOTES:
TEST.VALUE:G5_RLS_LIN.ApplLinInit.rb_LIN_State_l:0x1
TEST.EXPECTED:G5_RLS_LIN.<<GLOBAL>>.uF_SCIFlags_mg.Bit.B6:1
TEST.EXPECTED:G5_RLS_LIN.<<GLOBAL>>.uF_StatusRainsensor_mg.Bit.B7:1
TEST.EXPECTED:uut_prototype_stubs.sci_init.rb_WakeUpFrame_l:0x1
TEST.END

-- Subprogram: ApplLinSlavePreCopy

-- Test Case: BASIS-PATH-001-FSsMsg
TEST.UNIT:G5_RLS_LIN
TEST.SUBPROGRAM:ApplLinSlavePreCopy
TEST.NEW
TEST.NAME:BASIS-PATH-001-FSsMsg
TEST.BASIS_PATH:1 of 3
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (rb_MessageID_l == ((EEPROM_Struct_PD.EEPROMStructPD).IDRLSs_01 & 0x3f) && ((EEPROM_Struct_PD.EEPROMStructPD).RSControlFlags & 0x80) == 0) ==> FALSE
      (2) if (rb_MessageID_l == ((EEPROM_Struct_PD.EEPROMStructPD).IDFSs_01 & 0x3f) && ((EEPROM_Struct_PD.EEPROMStructPD).RSControlFlags & 0x80) != 0) ==> FALSE
   Test Case Generation Notes:
      Cannot set variable to unknown value in branch 1
      Cannot set variable to unknown value in branch 2
      Conflict: Multiple equality operators with different values (G5_RLS_LIN.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.RSControlFlags) in branches 1/2
TEST.END_NOTES:
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.uF_Communication_mg.Bit.B6:1
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.RSControlFlags:0x80
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.IDFSs_01:0x3F
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.FSs_01.fss_01.FS_ResponseError:0
TEST.VALUE:G5_RLS_LIN.ApplLinSlavePreCopy.rb_MessageID_l:0x3F
TEST.EXPECTED:G5_RLS_LIN.<<GLOBAL>>.uF_Communication_mg.Bit.B6:0
TEST.EXPECTED:G5_RLS_LIN.<<GLOBAL>>.FSs_01.fss_01.FS_ResponseError:1
TEST.END

-- Test Case: BASIS-PATH-001-FSsMsg.001
TEST.UNIT:G5_RLS_LIN
TEST.SUBPROGRAM:ApplLinSlavePreCopy
TEST.NEW
TEST.NAME:BASIS-PATH-001-FSsMsg.001
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (rb_MessageID_l == ((EEPROM_Struct_PD.EEPROMStructPD).IDRLSs_01 & 0x3f) && ((EEPROM_Struct_PD.EEPROMStructPD).RSControlFlags & 0x80) == 0) ==> FALSE
      (2) if (rb_MessageID_l == ((EEPROM_Struct_PD.EEPROMStructPD).IDFSs_01 & 0x3f) && ((EEPROM_Struct_PD.EEPROMStructPD).RSControlFlags & 0x80) != 0) ==> FALSE
   Test Case Generation Notes:
      Cannot set variable to unknown value in branch 1
      Cannot set variable to unknown value in branch 2
      Conflict: Multiple equality operators with different values (G5_RLS_LIN.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.RSControlFlags) in branches 1/2
TEST.END_NOTES:
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.uF_Communication_mg.Bit.B6:1
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.RSControlFlags:0x7F
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.IDFSs_01:0x3F
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.FSs_01.fss_01.FS_ResponseError:0
TEST.VALUE:G5_RLS_LIN.ApplLinSlavePreCopy.rb_MessageID_l:0x3F
TEST.EXPECTED:G5_RLS_LIN.<<GLOBAL>>.uF_Communication_mg.Bit.B6:1
TEST.EXPECTED:G5_RLS_LIN.<<GLOBAL>>.FSs_01.fss_01.FS_ResponseError:0
TEST.END

-- Test Case: BASIS-PATH-001-FSsMsg.002
TEST.UNIT:G5_RLS_LIN
TEST.SUBPROGRAM:ApplLinSlavePreCopy
TEST.NEW
TEST.NAME:BASIS-PATH-001-FSsMsg.002
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (rb_MessageID_l == ((EEPROM_Struct_PD.EEPROMStructPD).IDRLSs_01 & 0x3f) && ((EEPROM_Struct_PD.EEPROMStructPD).RSControlFlags & 0x80) == 0) ==> FALSE
      (2) if (rb_MessageID_l == ((EEPROM_Struct_PD.EEPROMStructPD).IDFSs_01 & 0x3f) && ((EEPROM_Struct_PD.EEPROMStructPD).RSControlFlags & 0x80) != 0) ==> FALSE
   Test Case Generation Notes:
      Cannot set variable to unknown value in branch 1
      Cannot set variable to unknown value in branch 2
      Conflict: Multiple equality operators with different values (G5_RLS_LIN.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.RSControlFlags) in branches 1/2
TEST.END_NOTES:
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.uF_Communication_mg.Bit.B6:1
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.RSControlFlags:0x80
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.IDFSs_01:0x3F
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.FSs_01.fss_01.FS_ResponseError:0
TEST.EXPECTED:G5_RLS_LIN.<<GLOBAL>>.uF_Communication_mg.Bit.B6:1
TEST.EXPECTED:G5_RLS_LIN.<<GLOBAL>>.FSs_01.fss_01.FS_ResponseError:0
TEST.ATTRIBUTES:G5_RLS_LIN.ApplLinSlavePreCopy.rb_MessageID_l:INPUT_BASE=16
TEST.VALUE_USER_CODE:G5_RLS_LIN.ApplLinSlavePreCopy.rb_MessageID_l
<<G5_RLS_LIN.ApplLinSlavePreCopy.rb_MessageID_l>> != ( 0x3F );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: BASIS-PATH-002-RLSMsg.001
TEST.UNIT:G5_RLS_LIN
TEST.SUBPROGRAM:ApplLinSlavePreCopy
TEST.NEW
TEST.NAME:BASIS-PATH-002-RLSMsg.001
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (rb_MessageID_l == ((EEPROM_Struct_PD.EEPROMStructPD).IDRLSs_01 & 0x3f) && ((EEPROM_Struct_PD.EEPROMStructPD).RSControlFlags & 0x80) == 0) ==> FALSE
      (2) if (rb_MessageID_l == ((EEPROM_Struct_PD.EEPROMStructPD).IDFSs_01 & 0x3f) && ((EEPROM_Struct_PD.EEPROMStructPD).RSControlFlags & 0x80) != 0) ==> FALSE
   Test Case Generation Notes:
      Cannot set variable to unknown value in branch 1
      Cannot set variable to unknown value in branch 2
      Conflict: Multiple equality operators with different values (G5_RLS_LIN.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.RSControlFlags) in branches 1/2
TEST.END_NOTES:
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.uF_Communication_mg.Bit.B6:1
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.RSControlFlags:0x7F
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.IDRLSs_01:0x3F
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.RLSs_01.rlss_01.RLS_ResponseError:0
TEST.VALUE:G5_RLS_LIN.ApplLinSlavePreCopy.rb_MessageID_l:0x3F
TEST.EXPECTED:G5_RLS_LIN.<<GLOBAL>>.uF_Communication_mg.Bit.B6:0
TEST.EXPECTED:G5_RLS_LIN.<<GLOBAL>>.RLSs_01.rlss_01.RLS_ResponseError:1
TEST.END

-- Subprogram: LIN_CalculateFixIntervalTime

-- Test Case: BASIS-PATH-001-PARTIAL
TEST.UNIT:G5_RLS_LIN
TEST.SUBPROGRAM:LIN_CalculateFixIntervalTime
TEST.NEW
TEST.NAME:BASIS-PATH-001-PARTIAL
TEST.BASIS_PATH:1 of 12
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if ((uF_Communication_mg.Bit).B1 == 1) ==> FALSE
      (3) if ((((uF_Communication_mg.Bit).B5 == 1 || ((EEPROM_Struct_PD.EEPROMStructPD).EEKodierbyte0_g & 0x40) > 0 == 1 && (uF_Main_Flags_g.Bit).B6 == 0) && (uF_VoltageStatus_g.Bit).B2 == 1) && ((uF_StatusRainsensor2_mg.Bit).B2 == 1 || (EEPROM_Struct_RD.EEPROMStructRD).Release_IntervalMarker_g == 0xa && (
rb_Release_IntervalMarker_Update_g & 0xa0) != 0xa0)) ==> FALSE
   Test Case Generation Notes:
      Conflict: Unable to validate expression-to-expression comparison in branch 3
TEST.END_NOTES:
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.uF_Communication_mg.Bit.B1:<<MIN>>
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.uF_Communication_mg.Bit.B5:<<MIN>>
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.rb_Release_IntervalMarker_Update_g:160
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.EEPROM_Struct_RD.EEPROMStructRD.Release_IntervalMarker_g:<<MIN>>
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.uF_VoltageStatus_g.Bit.B2:<<MIN>>
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.uF_StatusRainsensor2_mg.Bit.B2:<<MIN>>
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.uF_Main_Flags_g.Bit.B6:1
TEST.END

-- Test Case: BASIS-PATH-002
TEST.UNIT:G5_RLS_LIN
TEST.SUBPROGRAM:LIN_CalculateFixIntervalTime
TEST.NEW
TEST.NAME:BASIS-PATH-002
TEST.BASIS_PATH:2 of 12
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if ((uF_Communication_mg.Bit).B1 == 1) ==> FALSE
      (3) if ((((uF_Communication_mg.Bit).B5 == 1 || ((EEPROM_Struct_PD.EEPROMStructPD).EEKodierbyte0_g & 0x40) > 0 == 1 && (uF_Main_Flags_g.Bit).B6 == 0) && (uF_VoltageStatus_g.Bit).B2 == 1) && ((uF_StatusRainsensor2_mg.Bit).B2 == 1 || (EEPROM_Struct_RD.EEPROMStructRD).Release_IntervalMarker_g == 0xa && (
rb_Release_IntervalMarker_Update_g & 0xa0) != 0xa0)) ==> TRUE
      (4) if ((BCM1_LIN1_01.bcm1_lin1_01).WH_Intervall == 1) ==> FALSE
      (10) if ((BCM1_LIN1_01.bcm1_lin1_01).WH_WischerStufe1 == 1 || (BCM1_LIN1_01.bcm1_lin1_01).WH_WischerStufe2 == 1) ==> FALSE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.uF_Communication_mg.Bit.B1:<<MIN>>
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.uF_Communication_mg.Bit.B5:1
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.rb_Release_IntervalMarker_Update_g:0
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.EEPROM_Struct_RD.EEPROMStructRD.Release_IntervalMarker_g:10
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.BCM1_LIN1_01.bcm1_lin1_01.WH_Intervall:<<MIN>>
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.BCM1_LIN1_01.bcm1_lin1_01.WH_WischerStufe1:<<MIN>>
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.BCM1_LIN1_01.bcm1_lin1_01.WH_WischerStufe2:<<MIN>>
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.uF_VoltageStatus_g.Bit.B2:1
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.uF_StatusRainsensor2_mg.Bit.B2:1
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.uF_Main_Flags_g.Bit.B6:0
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL
TEST.UNIT:G5_RLS_LIN
TEST.SUBPROGRAM:LIN_CalculateFixIntervalTime
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL
TEST.BASIS_PATH:3 of 12
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) if ((uF_Communication_mg.Bit).B1 == 1) ==> FALSE
      (3) if ((((uF_Communication_mg.Bit).B5 == 1 || ((EEPROM_Struct_PD.EEPROMStructPD).EEKodierbyte0_g & 0x40) > 0 == 1 && (uF_Main_Flags_g.Bit).B6 == 0) && (uF_VoltageStatus_g.Bit).B2 == 1) && ((uF_StatusRainsensor2_mg.Bit).B2 == 1 || (EEPROM_Struct_RD.EEPROMStructRD).Release_IntervalMarker_g == 0xa && (
rb_Release_IntervalMarker_Update_g & 0xa0) != 0xa0)) ==> TRUE
      (4) if ((BCM1_LIN1_01.bcm1_lin1_01).WH_Intervall == 1) ==> FALSE
      (10) if ((BCM1_LIN1_01.bcm1_lin1_01).WH_WischerStufe1 == 1 || (BCM1_LIN1_01.bcm1_lin1_01).WH_WischerStufe2 == 1) ==> TRUE
      (11) if (rw_AfterWWSWipeCounter_mg >> 4 >= (25)) ==> FALSE
   Test Case Generation Notes:
      Conflict: Unable to validate expression-to-expression comparison in branch 11
TEST.END_NOTES:
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.uF_Communication_mg.Bit.B1:<<MIN>>
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.uF_Communication_mg.Bit.B5:1
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.rb_Release_IntervalMarker_Update_g:0
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.EEPROM_Struct_RD.EEPROMStructRD.Release_IntervalMarker_g:10
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.BCM1_LIN1_01.bcm1_lin1_01.WH_Intervall:<<MIN>>
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.BCM1_LIN1_01.bcm1_lin1_01.WH_WischerStufe1:1
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.BCM1_LIN1_01.bcm1_lin1_01.WH_WischerStufe2:1
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.uF_VoltageStatus_g.Bit.B2:1
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.uF_StatusRainsensor2_mg.Bit.B2:1
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.uF_Main_Flags_g.Bit.B6:0
TEST.END

-- Test Case: BASIS-PATH-004-PARTIAL
TEST.UNIT:G5_RLS_LIN
TEST.SUBPROGRAM:LIN_CalculateFixIntervalTime
TEST.NEW
TEST.NAME:BASIS-PATH-004-PARTIAL
TEST.BASIS_PATH:4 of 12
TEST.NOTES:
This is an automatically generated test case.
   Test Path 4
      (1) if ((uF_Communication_mg.Bit).B1 == 1) ==> FALSE
      (3) if ((((uF_Communication_mg.Bit).B5 == 1 || ((EEPROM_Struct_PD.EEPROMStructPD).EEKodierbyte0_g & 0x40) > 0 == 1 && (uF_Main_Flags_g.Bit).B6 == 0) && (uF_VoltageStatus_g.Bit).B2 == 1) && ((uF_StatusRainsensor2_mg.Bit).B2 == 1 || (EEPROM_Struct_RD.EEPROMStructRD).Release_IntervalMarker_g == 0xa && (
rb_Release_IntervalMarker_Update_g & 0xa0) != 0xa0)) ==> TRUE
      (4) if ((BCM1_LIN1_01.bcm1_lin1_01).WH_Intervall == 1) ==> FALSE
      (10) if ((BCM1_LIN1_01.bcm1_lin1_01).WH_WischerStufe1 == 1 || (BCM1_LIN1_01.bcm1_lin1_01).WH_WischerStufe2 == 1) ==> TRUE
      (11) if (rw_AfterWWSWipeCounter_mg >> 4 >= (25)) ==> TRUE
   Test Case Generation Notes:
      Conflict: Unable to validate expression-to-expression comparison in branch 11
TEST.END_NOTES:
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.uF_Communication_mg.Bit.B1:<<MIN>>
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.uF_Communication_mg.Bit.B5:1
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.rb_Release_IntervalMarker_Update_g:0
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.EEPROM_Struct_RD.EEPROMStructRD.Release_IntervalMarker_g:10
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.BCM1_LIN1_01.bcm1_lin1_01.WH_Intervall:<<MIN>>
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.BCM1_LIN1_01.bcm1_lin1_01.WH_WischerStufe1:1
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.BCM1_LIN1_01.bcm1_lin1_01.WH_WischerStufe2:1
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.uF_VoltageStatus_g.Bit.B2:1
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.uF_StatusRainsensor2_mg.Bit.B2:1
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.uF_Main_Flags_g.Bit.B6:0
TEST.END

-- Test Case: BASIS-PATH-005-PARTIAL
TEST.UNIT:G5_RLS_LIN
TEST.SUBPROGRAM:LIN_CalculateFixIntervalTime
TEST.NEW
TEST.NAME:BASIS-PATH-005-PARTIAL
TEST.BASIS_PATH:5 of 12
TEST.NOTES:
This is an automatically generated test case.
   Test Path 5
      (1) if ((uF_Communication_mg.Bit).B1 == 1) ==> FALSE
      (3) if ((((uF_Communication_mg.Bit).B5 == 1 || ((EEPROM_Struct_PD.EEPROMStructPD).EEKodierbyte0_g & 0x40) > 0 == 1 && (uF_Main_Flags_g.Bit).B6 == 0) && (uF_VoltageStatus_g.Bit).B2 == 1) && ((uF_StatusRainsensor2_mg.Bit).B2 == 1 || (EEPROM_Struct_RD.EEPROMStructRD).Release_IntervalMarker_g == 0xa && (
rb_Release_IntervalMarker_Update_g & 0xa0) != 0xa0)) ==> TRUE
      (4) if ((BCM1_LIN1_01.bcm1_lin1_01).WH_Intervall == 1) ==> TRUE
      (5) if (rb_speed_in_kmh_g <= 4) ==> FALSE
      (6) if (rb_speed_in_kmh_g < 200) ==> FALSE
      (7) if (rw_AfterWWSWipeCounter_mg / (10) >= rb_intervaltime_rainSensorOff_g) ==> FALSE
      (8) if (rb_Deaktivierung_RS_mg == 0 && (BCM1_LIN1_01.bcm1_lin1_01).Deaktivierung_RS == 1) ==> FALSE
      (9) if (rw_NoCommunicationCounter_g <= (((EEPROM_Struct_AD.EEPROMStructAD).p_t_autobahn_delay_on_g >> 5 & 0x7) * 100 + 200) - 3) ==> FALSE
   Test Case Generation Notes:
      Cannot set local variable cab_FixIntervtim_a200kmph_mg in branch 7
      Cannot set local variable rb_Deaktivierung_RS_mg in branch 8
TEST.END_NOTES:
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.uF_Communication_mg.Bit.B1:<<MIN>>
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.uF_Communication_mg.Bit.B5:1
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.rw_NoCommunicationCounter_g:<<MAX>>
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.rb_Release_IntervalMarker_Update_g:0
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.EEPROM_Struct_RD.EEPROMStructRD.Release_IntervalMarker_g:10
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.BCM1_LIN1_01.bcm1_lin1_01.WH_Intervall:1
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.BCM1_LIN1_01.bcm1_lin1_01.Deaktivierung_RS:<<MIN>>
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.uF_VoltageStatus_g.Bit.B2:1
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.uF_StatusRainsensor2_mg.Bit.B2:1
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.uF_Main_Flags_g.Bit.B6:0
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.rb_speed_in_kmh_g:<<MAX>>
TEST.END

-- Test Case: BASIS-PATH-006-PARTIAL
TEST.UNIT:G5_RLS_LIN
TEST.SUBPROGRAM:LIN_CalculateFixIntervalTime
TEST.NEW
TEST.NAME:BASIS-PATH-006-PARTIAL
TEST.BASIS_PATH:6 of 12
TEST.NOTES:
This is an automatically generated test case.
   Test Path 6
      (1) if ((uF_Communication_mg.Bit).B1 == 1) ==> FALSE
      (3) if ((((uF_Communication_mg.Bit).B5 == 1 || ((EEPROM_Struct_PD.EEPROMStructPD).EEKodierbyte0_g & 0x40) > 0 == 1 && (uF_Main_Flags_g.Bit).B6 == 0) && (uF_VoltageStatus_g.Bit).B2 == 1) && ((uF_StatusRainsensor2_mg.Bit).B2 == 1 || (EEPROM_Struct_RD.EEPROMStructRD).Release_IntervalMarker_g == 0xa && (
rb_Release_IntervalMarker_Update_g & 0xa0) != 0xa0)) ==> TRUE
      (4) if ((BCM1_LIN1_01.bcm1_lin1_01).WH_Intervall == 1) ==> TRUE
      (5) if (rb_speed_in_kmh_g <= 4) ==> FALSE
      (6) if (rb_speed_in_kmh_g < 200) ==> FALSE
      (7) if (rw_AfterWWSWipeCounter_mg / (10) >= rb_intervaltime_rainSensorOff_g) ==> FALSE
      (8) if (rb_Deaktivierung_RS_mg == 0 && (BCM1_LIN1_01.bcm1_lin1_01).Deaktivierung_RS == 1) ==> FALSE
      (9) if (rw_NoCommunicationCounter_g <= (((EEPROM_Struct_AD.EEPROMStructAD).p_t_autobahn_delay_on_g >> 5 & 0x7) * 100 + 200) - 3) ==> TRUE
   Test Case Generation Notes:
      Cannot set local variable cab_FixIntervtim_a200kmph_mg in branch 7
      Cannot set local variable rb_Deaktivierung_RS_mg in branch 8
TEST.END_NOTES:
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.uF_Communication_mg.Bit.B1:<<MIN>>
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.uF_Communication_mg.Bit.B5:1
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.rw_NoCommunicationCounter_g:<<MIN>>
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.rb_Release_IntervalMarker_Update_g:0
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.EEPROM_Struct_RD.EEPROMStructRD.Release_IntervalMarker_g:10
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.BCM1_LIN1_01.bcm1_lin1_01.WH_Intervall:1
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.BCM1_LIN1_01.bcm1_lin1_01.Deaktivierung_RS:<<MIN>>
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.uF_VoltageStatus_g.Bit.B2:1
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.uF_StatusRainsensor2_mg.Bit.B2:1
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.uF_Main_Flags_g.Bit.B6:0
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.rb_speed_in_kmh_g:<<MAX>>
TEST.END

-- Test Case: BASIS-PATH-007-PARTIAL
TEST.UNIT:G5_RLS_LIN
TEST.SUBPROGRAM:LIN_CalculateFixIntervalTime
TEST.NEW
TEST.NAME:BASIS-PATH-007-PARTIAL
TEST.BASIS_PATH:7 of 12
TEST.NOTES:
This is an automatically generated test case.
   Test Path 7
      (1) if ((uF_Communication_mg.Bit).B1 == 1) ==> FALSE
      (3) if ((((uF_Communication_mg.Bit).B5 == 1 || ((EEPROM_Struct_PD.EEPROMStructPD).EEKodierbyte0_g & 0x40) > 0 == 1 && (uF_Main_Flags_g.Bit).B6 == 0) && (uF_VoltageStatus_g.Bit).B2 == 1) && ((uF_StatusRainsensor2_mg.Bit).B2 == 1 || (EEPROM_Struct_RD.EEPROMStructRD).Release_IntervalMarker_g == 0xa && (
rb_Release_IntervalMarker_Update_g & 0xa0) != 0xa0)) ==> TRUE
      (4) if ((BCM1_LIN1_01.bcm1_lin1_01).WH_Intervall == 1) ==> TRUE
      (5) if (rb_speed_in_kmh_g <= 4) ==> FALSE
      (6) if (rb_speed_in_kmh_g < 200) ==> FALSE
      (7) if (rw_AfterWWSWipeCounter_mg / (10) >= rb_intervaltime_rainSensorOff_g) ==> FALSE
      (8) if (rb_Deaktivierung_RS_mg == 0 && (BCM1_LIN1_01.bcm1_lin1_01).Deaktivierung_RS == 1) ==> TRUE
      (9) if (rw_NoCommunicationCounter_g <= (((EEPROM_Struct_AD.EEPROMStructAD).p_t_autobahn_delay_on_g >> 5 & 0x7) * 100 + 200) - 3) ==> FALSE
   Test Case Generation Notes:
      Cannot set local variable cab_FixIntervtim_a200kmph_mg in branch 7
      Cannot set local variable rb_Deaktivierung_RS_mg in branch 8
TEST.END_NOTES:
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.uF_Communication_mg.Bit.B1:<<MIN>>
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.uF_Communication_mg.Bit.B5:1
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.rw_NoCommunicationCounter_g:<<MAX>>
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.rb_Release_IntervalMarker_Update_g:0
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.EEPROM_Struct_RD.EEPROMStructRD.Release_IntervalMarker_g:10
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.BCM1_LIN1_01.bcm1_lin1_01.WH_Intervall:1
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.BCM1_LIN1_01.bcm1_lin1_01.Deaktivierung_RS:1
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.uF_VoltageStatus_g.Bit.B2:1
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.uF_StatusRainsensor2_mg.Bit.B2:1
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.uF_Main_Flags_g.Bit.B6:0
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.rb_speed_in_kmh_g:<<MAX>>
TEST.END

-- Test Case: BASIS-PATH-008-PARTIAL
TEST.UNIT:G5_RLS_LIN
TEST.SUBPROGRAM:LIN_CalculateFixIntervalTime
TEST.NEW
TEST.NAME:BASIS-PATH-008-PARTIAL
TEST.BASIS_PATH:8 of 12
TEST.NOTES:
This is an automatically generated test case.
   Test Path 8
      (1) if ((uF_Communication_mg.Bit).B1 == 1) ==> FALSE
      (3) if ((((uF_Communication_mg.Bit).B5 == 1 || ((EEPROM_Struct_PD.EEPROMStructPD).EEKodierbyte0_g & 0x40) > 0 == 1 && (uF_Main_Flags_g.Bit).B6 == 0) && (uF_VoltageStatus_g.Bit).B2 == 1) && ((uF_StatusRainsensor2_mg.Bit).B2 == 1 || (EEPROM_Struct_RD.EEPROMStructRD).Release_IntervalMarker_g == 0xa && (
rb_Release_IntervalMarker_Update_g & 0xa0) != 0xa0)) ==> TRUE
      (4) if ((BCM1_LIN1_01.bcm1_lin1_01).WH_Intervall == 1) ==> TRUE
      (5) if (rb_speed_in_kmh_g <= 4) ==> FALSE
      (6) if (rb_speed_in_kmh_g < 200) ==> FALSE
      (7) if (rw_AfterWWSWipeCounter_mg / (10) >= rb_intervaltime_rainSensorOff_g) ==> TRUE
      (8) if (rb_Deaktivierung_RS_mg == 0 && (BCM1_LIN1_01.bcm1_lin1_01).Deaktivierung_RS == 1) ==> FALSE
      (9) if (rw_NoCommunicationCounter_g <= (((EEPROM_Struct_AD.EEPROMStructAD).p_t_autobahn_delay_on_g >> 5 & 0x7) * 100 + 200) - 3) ==> FALSE
   Test Case Generation Notes:
      Cannot set local variable cab_FixIntervtim_a200kmph_mg in branch 7
      Cannot set local variable rb_Deaktivierung_RS_mg in branch 8
TEST.END_NOTES:
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.uF_Communication_mg.Bit.B1:<<MIN>>
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.uF_Communication_mg.Bit.B5:1
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.rw_NoCommunicationCounter_g:<<MAX>>
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.rb_Release_IntervalMarker_Update_g:0
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.EEPROM_Struct_RD.EEPROMStructRD.Release_IntervalMarker_g:10
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.BCM1_LIN1_01.bcm1_lin1_01.WH_Intervall:1
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.BCM1_LIN1_01.bcm1_lin1_01.Deaktivierung_RS:<<MIN>>
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.uF_VoltageStatus_g.Bit.B2:1
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.uF_StatusRainsensor2_mg.Bit.B2:1
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.uF_Main_Flags_g.Bit.B6:0
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.rb_speed_in_kmh_g:<<MAX>>
TEST.END

-- Test Case: BASIS-PATH-009-PARTIAL
TEST.UNIT:G5_RLS_LIN
TEST.SUBPROGRAM:LIN_CalculateFixIntervalTime
TEST.NEW
TEST.NAME:BASIS-PATH-009-PARTIAL
TEST.BASIS_PATH:9 of 12
TEST.NOTES:
This is an automatically generated test case.
   Test Path 9
      (1) if ((uF_Communication_mg.Bit).B1 == 1) ==> FALSE
      (3) if ((((uF_Communication_mg.Bit).B5 == 1 || ((EEPROM_Struct_PD.EEPROMStructPD).EEKodierbyte0_g & 0x40) > 0 == 1 && (uF_Main_Flags_g.Bit).B6 == 0) && (uF_VoltageStatus_g.Bit).B2 == 1) && ((uF_StatusRainsensor2_mg.Bit).B2 == 1 || (EEPROM_Struct_RD.EEPROMStructRD).Release_IntervalMarker_g == 0xa && (
rb_Release_IntervalMarker_Update_g & 0xa0) != 0xa0)) ==> TRUE
      (4) if ((BCM1_LIN1_01.bcm1_lin1_01).WH_Intervall == 1) ==> TRUE
      (5) if (rb_speed_in_kmh_g <= 4) ==> FALSE
      (6) if (rb_speed_in_kmh_g < 200) ==> TRUE
      (7) if (rw_AfterWWSWipeCounter_mg / (10) >= rb_intervaltime_rainSensorOff_g) ==> FALSE
      (8) if (rb_Deaktivierung_RS_mg == 0 && (BCM1_LIN1_01.bcm1_lin1_01).Deaktivierung_RS == 1) ==> FALSE
      (9) if (rw_NoCommunicationCounter_g <= (((EEPROM_Struct_AD.EEPROMStructAD).p_t_autobahn_delay_on_g >> 5 & 0x7) * 100 + 200) - 3) ==> FALSE
   Test Case Generation Notes:
      Cannot set rb_intervaltime_rainSensorOff_g due to assignment
      Cannot set local variable rb_Deaktivierung_RS_mg in branch 8
TEST.END_NOTES:
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.uF_Communication_mg.Bit.B1:<<MIN>>
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.uF_Communication_mg.Bit.B5:1
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.rw_NoCommunicationCounter_g:<<MAX>>
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.rb_Release_IntervalMarker_Update_g:0
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.EEPROM_Struct_RD.EEPROMStructRD.Release_IntervalMarker_g:10
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.BCM1_LIN1_01.bcm1_lin1_01.WH_Intervall:1
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.BCM1_LIN1_01.bcm1_lin1_01.Deaktivierung_RS:<<MIN>>
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.uF_VoltageStatus_g.Bit.B2:1
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.uF_StatusRainsensor2_mg.Bit.B2:1
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.uF_Main_Flags_g.Bit.B6:0
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.rb_speed_in_kmh_g:5
TEST.END

-- Test Case: BASIS-PATH-010-PARTIAL
TEST.UNIT:G5_RLS_LIN
TEST.SUBPROGRAM:LIN_CalculateFixIntervalTime
TEST.NEW
TEST.NAME:BASIS-PATH-010-PARTIAL
TEST.BASIS_PATH:10 of 12
TEST.NOTES:
This is an automatically generated test case.
   Test Path 10
      (1) if ((uF_Communication_mg.Bit).B1 == 1) ==> FALSE
      (3) if ((((uF_Communication_mg.Bit).B5 == 1 || ((EEPROM_Struct_PD.EEPROMStructPD).EEKodierbyte0_g & 0x40) > 0 == 1 && (uF_Main_Flags_g.Bit).B6 == 0) && (uF_VoltageStatus_g.Bit).B2 == 1) && ((uF_StatusRainsensor2_mg.Bit).B2 == 1 || (EEPROM_Struct_RD.EEPROMStructRD).Release_IntervalMarker_g == 0xa && (
rb_Release_IntervalMarker_Update_g & 0xa0) != 0xa0)) ==> TRUE
      (4) if ((BCM1_LIN1_01.bcm1_lin1_01).WH_Intervall == 1) ==> TRUE
      (5) if (rb_speed_in_kmh_g <= 4) ==> TRUE
      (7) if (rw_AfterWWSWipeCounter_mg / (10) >= rb_intervaltime_rainSensorOff_g) ==> FALSE
      (8) if (rb_Deaktivierung_RS_mg == 0 && (BCM1_LIN1_01.bcm1_lin1_01).Deaktivierung_RS == 1) ==> FALSE
      (9) if (rw_NoCommunicationCounter_g <= (((EEPROM_Struct_AD.EEPROMStructAD).p_t_autobahn_delay_on_g >> 5 & 0x7) * 100 + 200) - 3) ==> FALSE
   Test Case Generation Notes:
      Cannot set local variable cab_FixIntervtim_bel4kmph_mg in branch 6
      Cannot set local variable rb_Deaktivierung_RS_mg in branch 8
TEST.END_NOTES:
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.uF_Communication_mg.Bit.B1:<<MIN>>
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.uF_Communication_mg.Bit.B5:1
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.rw_NoCommunicationCounter_g:<<MAX>>
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.rb_Release_IntervalMarker_Update_g:0
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.EEPROM_Struct_RD.EEPROMStructRD.Release_IntervalMarker_g:10
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.BCM1_LIN1_01.bcm1_lin1_01.WH_Intervall:1
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.BCM1_LIN1_01.bcm1_lin1_01.Deaktivierung_RS:<<MIN>>
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.uF_VoltageStatus_g.Bit.B2:1
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.uF_StatusRainsensor2_mg.Bit.B2:1
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.uF_Main_Flags_g.Bit.B6:0
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.rb_speed_in_kmh_g:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-011-PARTIAL
TEST.UNIT:G5_RLS_LIN
TEST.SUBPROGRAM:LIN_CalculateFixIntervalTime
TEST.NEW
TEST.NAME:BASIS-PATH-011-PARTIAL
TEST.BASIS_PATH:11 of 12
TEST.NOTES:
This is an automatically generated test case.
   Test Path 11
      (1) if ((uF_Communication_mg.Bit).B1 == 1) ==> TRUE
      (2) if ((rw_WH_State_l_old_mg != rw_temporary_WH_State_l && (rw_WH_State_l_old_mg & (0x1ff)) > (0)) && ((uF_Communication_mg.Bit).B5 == 1 || ((EEPROM_Struct_PD.EEPROMStructPD).EEKodierbyte0_g & 0x40) > 0 == 1 && (uF_VoltageStatus_g.Bit).B2 == 1)) ==> FALSE
      (3) if ((((uF_Communication_mg.Bit).B5 == 1 || ((EEPROM_Struct_PD.EEPROMStructPD).EEKodierbyte0_g & 0x40) > 0 == 1 && (uF_Main_Flags_g.Bit).B6 == 0) && (uF_VoltageStatus_g.Bit).B2 == 1) && ((uF_StatusRainsensor2_mg.Bit).B2 == 1 || (EEPROM_Struct_RD.EEPROMStructRD).Release_IntervalMarker_g == 0xa && (
rb_Release_IntervalMarker_Update_g & 0xa0) != 0xa0)) ==> FALSE
   Test Case Generation Notes:
      Cannot set local variable rw_WH_State_l_old_mg in branch 2
      Cannot set rw_temporary_WH_State_l due to assignment
      Conflict: Unable to validate expression-to-expression comparison in branch 3
TEST.END_NOTES:
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.uF_Communication_mg.Bit.B1:1
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.uF_Communication_mg.Bit.B5:<<MIN>>
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.rb_Release_IntervalMarker_Update_g:160
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.EEPROM_Struct_RD.EEPROMStructRD.Release_IntervalMarker_g:<<MIN>>
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.uF_VoltageStatus_g.Bit.B2:<<MIN>>
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.uF_StatusRainsensor2_mg.Bit.B2:<<MIN>>
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.uF_Main_Flags_g.Bit.B6:1
TEST.END

-- Test Case: BASIS-PATH-012-PARTIAL
TEST.UNIT:G5_RLS_LIN
TEST.SUBPROGRAM:LIN_CalculateFixIntervalTime
TEST.NEW
TEST.NAME:BASIS-PATH-012-PARTIAL
TEST.BASIS_PATH:12 of 12
TEST.NOTES:
This is an automatically generated test case.
   Test Path 12
      (1) if ((uF_Communication_mg.Bit).B1 == 1) ==> TRUE
      (2) if ((rw_WH_State_l_old_mg != rw_temporary_WH_State_l && (rw_WH_State_l_old_mg & (0x1ff)) > (0)) && ((uF_Communication_mg.Bit).B5 == 1 || ((EEPROM_Struct_PD.EEPROMStructPD).EEKodierbyte0_g & 0x40) > 0 == 1 && (uF_VoltageStatus_g.Bit).B2 == 1)) ==> TRUE
      (3) if ((((uF_Communication_mg.Bit).B5 == 1 || ((EEPROM_Struct_PD.EEPROMStructPD).EEKodierbyte0_g & 0x40) > 0 == 1 && (uF_Main_Flags_g.Bit).B6 == 0) && (uF_VoltageStatus_g.Bit).B2 == 1) && ((uF_StatusRainsensor2_mg.Bit).B2 == 1 || (EEPROM_Struct_RD.EEPROMStructRD).Release_IntervalMarker_g == 0xa && (
rb_Release_IntervalMarker_Update_g & 0xa0) != 0xa0)) ==> FALSE
   Test Case Generation Notes:
      Cannot set local variable rw_WH_State_l_old_mg in branch 2
      Cannot set rw_temporary_WH_State_l due to assignment
      Conflict: Unable to validate expression-to-expression comparison in branch 2
      Conflict: Unable to validate expression-to-expression comparison in branch 3
      Cannot set (uF_StatusRainsensor2_mg.Bit).B2 due to assignment
TEST.END_NOTES:
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.uF_Communication_mg.Bit.B1:1
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.uF_Communication_mg.Bit.B5:<<MIN>>
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.rb_Release_IntervalMarker_Update_g:160
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.EEPROM_Struct_RD.EEPROMStructRD.Release_IntervalMarker_g:<<MIN>>
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.uF_VoltageStatus_g.Bit.B2:<<MIN>>
TEST.VALUE:G5_RLS_LIN.<<GLOBAL>>.uF_Main_Flags_g.Bit.B6:1
TEST.END
