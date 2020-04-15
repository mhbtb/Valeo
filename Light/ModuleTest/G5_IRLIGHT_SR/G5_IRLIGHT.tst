-- VectorCAST 6.2n
-- Test Case Script
-- 
-- Environment    : G5_IRLIGHT
-- Unit(s) Under Test: G5_irlight
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Unit: G5_irlight

-- Subprogram: IO_CalculateWiperActivity

-- Test Case: 01_wipeTimeActive
TEST.UNIT:G5_irlight
TEST.SUBPROGRAM:IO_CalculateWiperActivity
TEST.NEW
TEST.NAME:01_wipeTimeActive
TEST.NOTES:
rw_WipeTime_g less than 0xFFFFU
-> rw_WipeTime_g is incremented by 1 to MAX

-> Wiper should not leave park position for this test case: uF_SCIFlags_mg . Bit . 6 = 1)
-> No wipe does not overflow: rw_NoWipeTime_g increments by 1 0xFFFE -> 0xFFFF
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_irlight.<<GLOBAL>>.rw_WipeTime_g:0xFFFE
TEST.VALUE:G5_irlight.<<GLOBAL>>.rw_NoWipeTime_g:0xFFFE
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_SCIFlags_mg.Bit.B6:1
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rw_WipeTime_g:<<MAX>>
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rw_NoWipeTime_g:0xFFFF
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_SCIFlags_mg.Bit.B6:1
TEST.ATTRIBUTES:G5_irlight.<<GLOBAL>>.rw_WipeTime_g:EXPECTED_BASE=16
TEST.END

-- Test Case: 02_wipeTimeMax
TEST.UNIT:G5_irlight
TEST.SUBPROGRAM:IO_CalculateWiperActivity
TEST.NEW
TEST.NAME:02_wipeTimeMax
TEST.NOTES:
rw_WipeTime_g less than 0xFFFFU
-> rw_WipeTime_g is initialised to MAX and and stays at MAX

Wiper should not leave park position for this test case (uF_SCIFlags_mg . Bit . 6 = 1)
-> No wipe time overflows: rw_NoWipeTime_g stays at 0xFFFF
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_irlight.<<GLOBAL>>.rw_WipeTime_g:<<MIN-1>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rw_NoWipeTime_g:<<MAX>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_SCIFlags_mg.Bit.B6:1
TEST.VALUE:G5_irlight.<<GLOBAL>>.RSStatus.Bit.B6:1
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rw_WipeTime_g:<<MAX>>
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rw_NoWipeTime_g:<<MAX>>
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_SCIFlags_mg.Bit.B6:1
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.RSStatus.Bit.B6:1
TEST.ATTRIBUTES:G5_irlight.<<GLOBAL>>.rw_WipeTime_g:INPUT_BASE=16,EXPECTED_BASE=16
TEST.END

-- Test Case: 03_washingActive
TEST.UNIT:G5_irlight
TEST.SUBPROGRAM:IO_CalculateWiperActivity
TEST.NEW
TEST.NAME:03_washingActive
TEST.COMPOUND_ONLY
TEST.NOTES:
rbi_WashingActive bit is set (=1). This means washing is active.
rbi_WashingActive bit is bit 1 of the RSStatus flag (RSStatus.Bit.B1)
-> The after washing counter is set to EEPROM parameter, rw_afterWashingTime_counter_s
 cw_DURATATION_WIPE_AFTER_WASH_mg =
     (((EEPROM_Struct_AD.EEPROMStructAD.Frontwaschen_Autobahndelay_g>>4)&0x0F) * 1) + 10) * 20
In this test case:
  cw_DURATATION_WIPE_AFTER_WASH_mg = ((((0xFF >> 4) & 0x0F) * 1) + 10) * 20 = 500
  This is confirmed by the static prefix user global, vc_rw_afterWashingTime_counter_s, initialisation via test case user code

Wiper should not leave park position for this test case (uF_SCIFlags_mg . Bit . 6 = 1)
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:FALSE
TEST.VALUE:G5_irlight.<<GLOBAL>>.vc_rw_afterWashingTime_counter_s:<<ZERO>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.Frontwaschen_Autobahndelay_g:0xFF
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_SCIFlags_mg.Bit.B6:1
TEST.VALUE:G5_irlight.<<GLOBAL>>.RSStatus.Bit.B1:1
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.vc_rw_afterWashingTime_counter_s:500
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.Frontwaschen_Autobahndelay_g:0xFF
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_SCIFlags_mg.Bit.B6:1
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.RSStatus.Bit.B1:1
TEST.VALUE_USER_CODE:<<testcase>>
vc_rw_afterWashingTime_counter_s = cw_DURATION_WIPE_AFTER_WASH_mg;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: 04_washingInactive
TEST.UNIT:G5_irlight
TEST.SUBPROGRAM:IO_CalculateWiperActivity
TEST.NEW
TEST.NAME:04_washingInactive
TEST.COMPOUND_ONLY
TEST.NOTES:
rbi_WashingActive bit is not set (=0). This means washing is not active.
rbi_WashingActive bit is bit 1 of the RSStatus flag (RSStatus.Bit.B1)
-> The after washing counter, rw_afterWashingTime_counter_s, is decremented by 1 from cw_DURATATION_WIPE_AFTER_WASH_mg to 499
This is confirmed by the static prefix user global variable, vc_rw_afterWashingTime_counter_s, that is decremented via test case user code

Wiper should not leave park position for this test case (uF_SCIFlags_mg . Bit . 6 = 1)
  
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:FALSE
TEST.VALUE:G5_irlight.<<GLOBAL>>.vc_rw_afterWashingTime_counter_s:<<KEEP>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.Frontwaschen_Autobahndelay_g:<<MAX>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_SCIFlags_mg.Bit.B6:1
TEST.VALUE:G5_irlight.<<GLOBAL>>.RSStatus.Bit.B1:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.vc_rw_afterWashingTime_counter_s:499
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.Frontwaschen_Autobahndelay_g:<<MAX>>
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_SCIFlags_mg.Bit.B6:1
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.RSStatus.Bit.B1:0
TEST.ATTRIBUTES:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.Frontwaschen_Autobahndelay_g:INPUT_BASE=16,EXPECTED_BASE=16
TEST.VALUE_USER_CODE:<<testcase>>
vc_rw_afterWashingTime_counter_s--;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: 05_NotInParkInDelay
TEST.UNIT:G5_irlight
TEST.SUBPROGRAM:IO_CalculateWiperActivity
TEST.NEW
TEST.NAME:05_NotInParkInDelay
TEST.COMPOUND_ONLY
TEST.NOTES:
rbi_WashingActive bit is not set (=0). This means washing is not active.
rbi_WashingActive bit is bit 1 of the RSStatus flag (RSStatus.Bit.B1)
-> The after washing counter, rw_afterWashingTime_counter_s, is decremented by 1 from cw_DURATATION_WIPE_AFTER_WASH_mg to 499
This is confirmed by the static prefix user global variable, vc_rw_afterWashingTime_counter_s, that is decremented twice via test case user code

Wiper should not leave park position for this test case (uF_SCIFlags_mg . Bit . 6 = 1)
  
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:FALSE
TEST.VALUE:G5_irlight.<<GLOBAL>>.vc_rw_afterWashingTime_counter_s:<<KEEP>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rw_NoWipeTime_g:0xFFFE
TEST.VALUE:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.Frontwaschen_Autobahndelay_g:<<MAX>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_SCIFlags_mg.Bit.B6:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.RSStatus.Bit.B1:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.vc_rw_afterWashingTime_counter_s:498
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rw_NoWipeTime_g:0xFFFF
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.Frontwaschen_Autobahndelay_g:<<MAX>>
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_SCIFlags_mg.Bit.B6:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.RSStatus.Bit.B1:0
TEST.ATTRIBUTES:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.Frontwaschen_Autobahndelay_g:INPUT_BASE=16,EXPECTED_BASE=16
TEST.VALUE_USER_CODE:<<testcase>>
int i;
for(i=0; i<2; i++)
{
   IO_CalculateWiperActivity();
   vc_rw_afterWashingTime_counter_s--;
}
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: 06_NotInParkDelayOver
TEST.UNIT:G5_irlight
TEST.SUBPROGRAM:IO_CalculateWiperActivity
TEST.NEW
TEST.NAME:06_NotInParkDelayOver
TEST.COMPOUND_ONLY
TEST.NOTES:
rbi_WashingActive bit is not set (=0). This means washing is not active.
rbi_WashingActive bit is bit 1 of the RSStatus flag (RSStatus.Bit.B1)
-> The after washing counter is set to EEPROM parameter, cw_DURATATION_WIPE_AFTER_WASH_mg
 cw_DURATATION_WIPE_AFTER_WASH_mg =
     (((EEPROM_Struct_AD.EEPROMStructAD.Frontwaschen_Autobahndelay_g>>4)&0x0F) * 1) + 10) * 20
In this test case:
  cw_DURATATION_WIPE_AFTER_WASH_mg = ((((0xFF >> 4) & 0x0F) * 1) + 10) * 20 = 500

Note: The unit prefix user global variable, vc_rw_afterWashingTime_counter_s,confirms that the
after washing delay counter is indeed initialized to cw_DURATATION_WIPE_AFTER_WASH_mg (500).
See test case user code for its usage.
  
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_irlight.<<GLOBAL>>.vc_rw_afterWashingTime_counter_s:<<ZERO>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rw_NoWipeTime_g:<<MAX>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rb_WipeCounter_g:254
TEST.VALUE:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.Frontwaschen_Autobahndelay_g:<<MAX>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_SCIFlags_mg.Bit.B6:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.RSStatus.Bit.B1:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.vc_rw_afterWashingTime_counter_s:500
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rw_NoWipeTime_g:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rb_WipeCounter_g:254
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.Frontwaschen_Autobahndelay_g:<<MAX>>
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_SCIFlags_mg.Bit.B6:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.RSStatus.Bit.B1:0
TEST.ATTRIBUTES:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.Frontwaschen_Autobahndelay_g:INPUT_BASE=16,EXPECTED_BASE=16
TEST.VALUE_USER_CODE:<<testcase>>
for(;vc_rw_afterWashingTime_counter_s<cw_DURATION_WIPE_AFTER_WASH_mg; vc_rw_afterWashingTime_counter_s++)
{
   IO_CalculateWiperActivity();
}
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: 07_NotInParkLastContact
TEST.UNIT:G5_irlight
TEST.SUBPROGRAM:IO_CalculateWiperActivity
TEST.NEW
TEST.NAME:07_NotInParkLastContact
TEST.COMPOUND_ONLY
TEST.NOTES:
rbi_WashingActive bit is not set (=0). This means washing is not active.
rbi_WashingActive bit is bit 1 of the RSStatus flag (RSStatus.Bit.B1)
-> The after washing counter is set to EEPROM parameter, cw_DURATATION_WIPE_AFTER_WASH_mg
 cw_DURATATION_WIPE_AFTER_WASH_mg =
     (((EEPROM_Struct_AD.EEPROMStructAD.Frontwaschen_Autobahndelay_g>>4)&0x0F) * 1) + 10) * 20
In this test case:
  cw_DURATATION_WIPE_AFTER_WASH_mg = ((((0xFF >> 4) & 0x0F) * 1) + 10) * 20 = 500

Note: The unit prefix user global variable, vc_rw_afterWashingTime_counter_s,confirms that the
after washing delay counter is indeed initialized to cw_DURATATION_WIPE_AFTER_WASH_mg (500).
See test case user code for its usage.
  
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_irlight.<<GLOBAL>>.vc_rw_afterWashingTime_counter_s:<<ZERO>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rw_NoWipeTime_g:<<MAX>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rb_WipeCounter_g:254
TEST.VALUE:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.Frontwaschen_Autobahndelay_g:<<MAX>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_SCIFlags_mg.Bit.B6:1
TEST.VALUE:G5_irlight.<<GLOBAL>>.RSStatus.Bit.B1:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.vc_rw_afterWashingTime_counter_s:500
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rw_NoWipeTime_g:<<MAX>>
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rb_WipeCounter_g:254
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.Frontwaschen_Autobahndelay_g:<<MAX>>
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_SCIFlags_mg.Bit.B6:1
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.RSStatus.Bit.B1:0
TEST.ATTRIBUTES:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.Frontwaschen_Autobahndelay_g:INPUT_BASE=16,EXPECTED_BASE=16
TEST.VALUE_USER_CODE:<<testcase>>
for(;vc_rw_afterWashingTime_counter_s<cw_DURATION_WIPE_AFTER_WASH_mg; vc_rw_afterWashingTime_counter_s++)
{
   IO_CalculateWiperActivity();
}
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: 08_NotInParkLastPosition
TEST.UNIT:G5_irlight
TEST.SUBPROGRAM:IO_CalculateWiperActivity
TEST.NEW
TEST.NAME:08_NotInParkLastPosition
TEST.COMPOUND_ONLY
TEST.NOTES:
rbi_WashingActive bit is not set (=0). This means washing is not active.
rbi_WashingActive bit is bit 1 of the RSStatus flag (RSStatus.Bit.B1)
-> The after washing counter is set to EEPROM parameter, cw_DURATATION_WIPE_AFTER_WASH_mg
 cw_DURATATION_WIPE_AFTER_WASH_mg =
     (((EEPROM_Struct_AD.EEPROMStructAD.Frontwaschen_Autobahndelay_g>>4)&0x0F) * 1) + 10) * 20
In this test case:
  cw_DURATATION_WIPE_AFTER_WASH_mg = ((((0xFF >> 4) & 0x0F) * 1) + 10) * 20 = 500

Note: The unit prefix user global variable, vc_rw_afterWashingTime_counter_s,confirms that the
after washing delay counter is indeed initialized to cw_DURATATION_WIPE_AFTER_WASH_mg (500).
See test case user code for its usage.
  
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_irlight.<<GLOBAL>>.vc_rw_afterWashingTime_counter_s:<<ZERO>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rw_NoWipeTime_g:0xFE
TEST.VALUE:G5_irlight.<<GLOBAL>>.rb_WipeCounter_g:<<KEEP>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.Frontwaschen_Autobahndelay_g:<<MAX>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_SCIFlags_mg.Bit.B6:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.RSStatus.Bit.B1:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.vc_rw_afterWashingTime_counter_s:<<ZERO>>
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rw_NoWipeTime_g:0x0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rb_WipeCounter_g:<<MAX>>
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.Frontwaschen_Autobahndelay_g:<<MAX>>
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_SCIFlags_mg.Bit.B6:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.RSStatus.Bit.B1:0
TEST.ATTRIBUTES:G5_irlight.<<GLOBAL>>.rb_WipeCounter_g:INPUT_BASE=16,EXPECTED_BASE=16
TEST.ATTRIBUTES:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.Frontwaschen_Autobahndelay_g:INPUT_BASE=16,EXPECTED_BASE=16
TEST.END

-- Test Case: 09_NotInParkWashingActive
TEST.UNIT:G5_irlight
TEST.SUBPROGRAM:IO_CalculateWiperActivity
TEST.NEW
TEST.NAME:09_NotInParkWashingActive
TEST.COMPOUND_ONLY
TEST.NOTES:
rbi_WashingActive bit is set (=1). This means washing is active.
rbi_WashingActive bit is bit 1 of the RSStatus flag (RSStatus.Bit.B1)
-> The after washing counter is set to EEPROM parameter, cw_DURATATION_WIPE_AFTER_WASH_mg
 cw_DURATATION_WIPE_AFTER_WASH_mg =
     (((EEPROM_Struct_AD.EEPROMStructAD.Frontwaschen_Autobahndelay_g>>4)&0x0F) * 1) + 10) * 20
In this test case:
  cw_DURATATION_WIPE_AFTER_WASH_mg = ((((0xFF >> 4) & 0x0F) * 1) + 10) * 20 = 500

Note: The unit prefix user global variable, vc_rw_afterWashingTime_counter_s,confirms that the
after washing delay counter is indeed initialized to cw_DURATATION_WIPE_AFTER_WASH_mg (500).
See test case user code for its usage.
  
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_irlight.<<GLOBAL>>.vc_rw_afterWashingTime_counter_s:<<ZERO>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rw_NoWipeTime_g:0xFFFD
TEST.VALUE:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.Frontwaschen_Autobahndelay_g:<<MAX>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_SCIFlags_mg.Bit.B6:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.RSStatus.Bit.B1:1
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.vc_rw_afterWashingTime_counter_s:<<ZERO>>
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rw_NoWipeTime_g:<<MAX>>
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.Frontwaschen_Autobahndelay_g:<<MAX>>
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_SCIFlags_mg.Bit.B6:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.RSStatus.Bit.B1:1
TEST.ATTRIBUTES:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.Frontwaschen_Autobahndelay_g:INPUT_BASE=16,EXPECTED_BASE=16
TEST.ATTRIBUTES:G5_irlight.<<GLOBAL>>.rw_NoWipeTime_g:EXPECTED_BASE=16
TEST.END

-- Subprogram: MODI_LIGHTSENS_NIGHT_BIT_CLEAR

-- Test Case: 01_vetoCounterZero
TEST.UNIT:G5_irlight
TEST.SUBPROGRAM:MODI_LIGHTSENS_NIGHT_BIT_CLEAR
TEST.NEW
TEST.NAME:01_vetoCounterZero
TEST.NOTES:
Night bit:
uF_modi_lightsens_g.Bit.B1 = 1
-> 0 after function call

uF_modi_lightsens_inv_g = 0
-> 1 after function call

uF_LightInternalStatus_g = 0
-> remains zero because veto counter is zero
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B1:1
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B1:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B1:0
TEST.VALUE:uut_prototype_stubs.get_rb_LightVetoCounter_g.return:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B1:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B1:1
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B1:0
TEST.END

-- Test Case: 02_vetoCounterNotZero
TEST.UNIT:G5_irlight
TEST.SUBPROGRAM:MODI_LIGHTSENS_NIGHT_BIT_CLEAR
TEST.NEW
TEST.NAME:02_vetoCounterNotZero
TEST.NOTES:
Night bit:
uF_modi_lightsens_g.Bit.B1 = 1
-> 0 after function call

uF_modi_lightsens_inv_g = 0
-> 1 after function call

uF_LightInternalStatus_g = 0
-> remains zero because veto counter is zero
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B1:1
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B1:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B1:0
TEST.VALUE:uut_prototype_stubs.get_rb_LightVetoCounter_g.return:0xFF
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B1:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B1:1
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B1:1
TEST.END

-- Subprogram: MODI_LIGHTSENS_NIGHT_BIT_SET

-- Test Case: 01_setNightBit
TEST.UNIT:G5_irlight
TEST.SUBPROGRAM:MODI_LIGHTSENS_NIGHT_BIT_SET
TEST.NEW
TEST.NAME:01_setNightBit
TEST.NOTES:
Night bit:
uF_modi_lightsens_g.Bit.B0 = 1 -> 0
uF_modi_lightsens_g.Bit.B1 = 0 -> 1
uF_modi_lightsens_g.Bit.B2 = 1 -> 0
uF_modi_lightsens_g.Bit.B3 = 1 -> 1 (not used)
uF_modi_lightsens_g.Bit.B4 = 0 -> 0 (not used)
uF_modi_lightsens_g.Bit.B5 = 1 -> 1 (not used)

uF_modi_lightsens_g_inv.Bit.B0 = 0 -> 1
uF_modi_lightsens_g_inv.Bit.B1 = 1 -> 0
uF_modi_lightsens_g_inv.Bit.B2 = 0 -> 1
uF_modi_lightsens_g_inv.Bit.B3 = 0 -> 1 
uF_modi_lightsens_g_inv.Bit.B4 = 0 -> 0 (not used)
uF_modi_lightsens_g_inv.Bit.B5 = 0 -> 1
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B0:1
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B1:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B2:1
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B3:1
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B4:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B5:1
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B6:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B7:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B0:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B1:1
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B2:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B3:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B4:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B5:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B6:1
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B7:1
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B0:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B1:1
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B2:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B3:1
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B4:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B5:1
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B6:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B7:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B0:1
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B1:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B2:1
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B3:1
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B4:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B5:1
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B6:1
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B7:1
TEST.END

-- Subprogram: MODI_LIGHTSENS_NIGHT_DARKST_CLEAR

-- Test Case: 01_vetocounterZero
TEST.UNIT:G5_irlight
TEST.SUBPROGRAM:MODI_LIGHTSENS_NIGHT_DARKST_CLEAR
TEST.NEW
TEST.NAME:01_vetocounterZero
TEST.NOTES:
Night bit:
uF_modi_lightsens_g.Bit.B0 = 1
-> 0 after function call

uF_modi_lightsens_inv_g.Bit.B0 = 0
-> 1 after function call

uF_LightInternalStatus_g.Bit.B1 = 1
-> remains zero because veto counter is zero
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B0:1
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B1:1
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B2:1
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B3:1
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B4:1
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B5:1
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B6:1
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B7:1
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B0:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B1:1
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B2:1
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B3:1
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B4:1
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B5:1
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B6:1
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B7:1
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B1:0
TEST.VALUE:uut_prototype_stubs.get_rb_LightVetoCounter_g.return:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B0:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B1:1
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B2:1
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B3:1
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B4:1
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B5:1
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B6:1
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B7:1
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B0:1
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B1:1
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B2:1
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B3:1
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B4:1
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B5:1
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B6:1
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B7:1
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B1:0
TEST.END

-- Test Case: 02_vetocounterNotZero
TEST.UNIT:G5_irlight
TEST.SUBPROGRAM:MODI_LIGHTSENS_NIGHT_DARKST_CLEAR
TEST.NEW
TEST.NAME:02_vetocounterNotZero
TEST.NOTES:
Night bit:
uF_modi_lightsens_g.Bit.B0 = 1
-> 0 after function call

uF_modi_lightsens_inv_g.Bit.B0 = 0
-> 1 after function call

uF_LightInternalStatus_g = 1
-> remains zero because veto counter is zero
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B0:1
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B1:1
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B2:1
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B3:1
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B4:1
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B5:1
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B6:1
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B7:1
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B0:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B1:1
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B2:1
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B3:1
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B4:1
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B5:1
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B6:1
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B7:1
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B1:0
TEST.VALUE:uut_prototype_stubs.get_rb_LightVetoCounter_g.return:<<MAX>>
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B0:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B1:1
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B2:1
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B3:1
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B4:1
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B5:1
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B6:1
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B7:1
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B0:1
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B1:1
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B2:1
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B3:1
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B4:1
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B5:1
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B6:1
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B7:1
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B1:1
TEST.END

-- Subprogram: MODI_LIGHTSENS_RAIN_CLEAR

-- Test Case: 01_rainClear
TEST.UNIT:G5_irlight
TEST.SUBPROGRAM:MODI_LIGHTSENS_RAIN_CLEAR
TEST.NEW
TEST.NAME:01_rainClear
TEST.NOTES:
uF_modi_lightsens_g.Bit.B4 = 1 -> 0
uF_modi_lightsens_g_inv.Bit.B4 = 0 -> 1
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B0:1
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B1:1
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B2:1
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B3:1
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B4:1
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B5:1
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B6:1
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B7:1
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B0:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B1:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B2:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B3:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B4:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B5:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B6:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B7:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B0:1
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B1:1
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B2:1
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B3:1
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B4:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B5:1
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B6:1
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B7:1
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B0:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B1:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B2:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B3:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B4:1
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B5:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B6:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B7:0
TEST.END

-- Subprogram: MODI_LIGHTSENS_RAIN_SET

-- Test Case: 01_rainSet
TEST.UNIT:G5_irlight
TEST.SUBPROGRAM:MODI_LIGHTSENS_RAIN_SET
TEST.NEW
TEST.NAME:01_rainSet
TEST.NOTES:
uF_modi_lightsens_g.Bit.B4 = 0 -> 1
uF_modi_lightsens_g_inv.Bit.B4 = 1 -> 0
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B0:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B1:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B2:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B3:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B4:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B5:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B6:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B7:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B0:1
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B1:1
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B2:1
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B3:1
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B4:1
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B5:1
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B6:1
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B7:1
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B0:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B1:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B2:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B3:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B4:1
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B5:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B6:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B7:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B0:1
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B1:1
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B2:1
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B3:1
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B4:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B5:1
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B6:1
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B7:1
TEST.END

-- Subprogram: MODI_LIGHTSENS_TUNNEL_CLEAR

-- Test Case: 01_vetoNoDoCheckVeto
TEST.UNIT:G5_irlight
TEST.SUBPROGRAM:MODI_LIGHTSENS_TUNNEL_CLEAR
TEST.NEW
TEST.NAME:01_vetoNoDoCheckVeto
TEST.NOTES:
Night bit:
uF_modi_lightsens_g.Bit.B2 = 1
-> 0 after function call

uF_modi_lightsens_inv_g.Bit.B2 = 0
-> 1 after function call

doCheckLightVeto = 0
-> no vetoCounter check

uF_LightInternalStatus_g.Bit.B1 = 1
-> remains zero because veto counter is zero
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B0:1
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B1:1
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B2:1
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B3:1
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B4:1
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B5:1
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B6:1
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B7:1
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B0:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B1:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B2:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B3:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B4:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B5:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B6:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B7:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B1:1
TEST.VALUE:G5_irlight.MODI_LIGHTSENS_TUNNEL_CLEAR.doCheckLightVeto:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B0:1
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B1:1
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B2:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B3:1
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B4:1
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B5:1
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B6:1
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B7:1
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B0:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B1:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B2:1
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B3:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B4:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B5:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B6:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B7:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B1:1
TEST.EXPECTED:G5_irlight.MODI_LIGHTSENS_TUNNEL_CLEAR.doCheckLightVeto:0
TEST.END

-- Test Case: 02_vetoDoCheckVetoZeroNoCount
TEST.UNIT:G5_irlight
TEST.SUBPROGRAM:MODI_LIGHTSENS_TUNNEL_CLEAR
TEST.NEW
TEST.NAME:02_vetoDoCheckVetoZeroNoCount
TEST.NOTES:
Night bit:
uF_modi_lightsens_g.Bit.B2 = 1
-> 0 after function call

uF_modi_lightsens_inv_g.Bit.B2 = 0
-> 1 after function call

doCheckLightVeto = 1
-> no vetoCounter check

uF_LightInternalStatus_g.Bit.B1 = 1
-> remains zero because veto counter is zero
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B0:1
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B1:1
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B2:1
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B3:1
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B4:1
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B5:1
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B6:1
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B7:1
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B0:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B1:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B2:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B3:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B4:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B5:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B6:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B7:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B1:1
TEST.VALUE:G5_irlight.MODI_LIGHTSENS_TUNNEL_CLEAR.doCheckLightVeto:1
TEST.VALUE:uut_prototype_stubs.get_rb_LightVetoCounter_g.return:<<MIN>>
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B0:1
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B1:1
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B2:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B3:1
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B4:1
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B5:1
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B6:1
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B7:1
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B0:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B1:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B2:1
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B3:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B4:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B5:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B6:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B7:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B1:1
TEST.EXPECTED:G5_irlight.MODI_LIGHTSENS_TUNNEL_CLEAR.doCheckLightVeto:1
TEST.END

-- Test Case: 03_vetoDoCheckVetoZeroCount
TEST.UNIT:G5_irlight
TEST.SUBPROGRAM:MODI_LIGHTSENS_TUNNEL_CLEAR
TEST.NEW
TEST.NAME:03_vetoDoCheckVetoZeroCount
TEST.NOTES:
Night bit:
uF_modi_lightsens_g.Bit.B2 = 1
-> 0 after function call

uF_modi_lightsens_inv_g.Bit.B2 = 0
-> 1 after function call

doCheckLightVeto = 1
-> no vetoCounter check

uF_LightInternalStatus_g.Bit.B1 = 1
-> remains zero because veto counter is zero
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B0:1
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B1:1
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B2:1
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B3:1
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B4:1
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B5:1
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B6:1
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B7:1
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B0:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B1:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B2:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B3:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B4:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B5:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B6:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B7:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B1:0
TEST.VALUE:G5_irlight.MODI_LIGHTSENS_TUNNEL_CLEAR.doCheckLightVeto:1
TEST.VALUE:uut_prototype_stubs.get_rb_LightVetoCounter_g.return:<<MAX>>
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B0:1
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B1:1
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B2:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B3:1
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B4:1
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B5:1
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B6:1
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B7:1
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B0:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B1:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B2:1
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B3:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B4:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B5:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B6:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B7:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B1:1
TEST.EXPECTED:G5_irlight.MODI_LIGHTSENS_TUNNEL_CLEAR.doCheckLightVeto:1
TEST.ATTRIBUTES:uut_prototype_stubs.get_rb_LightVetoCounter_g.return:INPUT_BASE=16
TEST.END

-- Subprogram: MODI_LIGHTSENS_TUNNEL_SET

-- Test Case: 01_tunnel_set
TEST.UNIT:G5_irlight
TEST.SUBPROGRAM:MODI_LIGHTSENS_TUNNEL_SET
TEST.NEW
TEST.NAME:01_tunnel_set
TEST.NOTES:
Night bit:
uF_modi_lightsens_g.Bit.B0 = 1 -> 0
uF_modi_lightsens_g.Bit.B1 = 1 -> 0
uF_modi_lightsens_g.Bit.B2 = 0 -> 1
uF_modi_lightsens_g.Bit.B3 = 1 -> 1 (not used)
uF_modi_lightsens_g.Bit.B4 = 0 -> 0 (not used)
uF_modi_lightsens_g.Bit.B5 = 1 -> 1 (not used)

uF_modi_lightsens_g_inv.Bit.B0 = 0 -> 1
uF_modi_lightsens_g_inv.Bit.B1 = 1 -> 0
uF_modi_lightsens_g_inv.Bit.B2 = 0 -> 1
uF_modi_lightsens_g_inv.Bit.B3 = 0 -> 1 
uF_modi_lightsens_g_inv.Bit.B4 = 1 -> 1 (not used)
uF_modi_lightsens_g_inv.Bit.B5 = 0 -> 1
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B0:1
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B1:1
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B2:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B3:1
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B4:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B5:1
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B6:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B7:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B0:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B1:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B2:1
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B3:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B4:1
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B5:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B6:1
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B7:1
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B0:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B1:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B2:1
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B3:1
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B4:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B5:1
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B6:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B7:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B0:1
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B1:1
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B2:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B3:1
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B4:1
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B5:1
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B6:1
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B7:1
TEST.END

-- Subprogram: lightScheduler

-- Test Case: 01_powerFail
TEST.UNIT:G5_irlight
TEST.SUBPROGRAM:lightScheduler
TEST.NEW
TEST.NAME:01_powerFail
TEST.NOTES:
In case of power fail, all variables retain their previous values
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_irlight.<<GLOBAL>>.rb_LS_Potistage_alt_g:<<MIN>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rw_dayCounter_mg:<<MAX>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rw_nightCounter_mg:<<MAX+1>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rb_LSPotiStage_g:<<MIN-1>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_Check_lightsensor_g.Bit.B0:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_Check_lightsensor_g.Bit.B1:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_Check_lightsensor_g.Bit.B2:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_Check_lightsensor_g.Bit.B3:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_Check_lightsensor_g.Bit.B4:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_Check_lightsensor_g.Bit.B5:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_Check_lightsensor_g.Bit.B6:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_Check_lightsensor_g.Bit.B7:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B0:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B1:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B2:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B3:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B4:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B5:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B6:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B7:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B0:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B1:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B2:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B3:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B4:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B5:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B6:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B7:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B0:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B1:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B2:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B3:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B4:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B5:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B6:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B7:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uf_LightAlgoReInit_g.Bit.B0:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uf_LightAlgoReInit_g.Bit.B1:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uf_LightAlgoReInit_g.Bit.B2:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uf_LightAlgoReInit_g.Bit.B3:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uf_LightAlgoReInit_g.Bit.B4:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uf_LightAlgoReInit_g.Bit.B5:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uf_LightAlgoReInit_g.Bit.B6:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uf_LightAlgoReInit_g.Bit.B7:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.rb_AfterVddPowerFailDelay_g:255
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rb_LS_Potistage_alt_g:<<MIN>>
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rw_dayCounter_mg:<<MAX>>
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rw_nightCounter_mg:<<MIN>>
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rb_LSPotiStage_g:<<MAX>>
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_Check_lightsensor_g.Bit.B0:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_Check_lightsensor_g.Bit.B1:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_Check_lightsensor_g.Bit.B2:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_Check_lightsensor_g.Bit.B3:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_Check_lightsensor_g.Bit.B4:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_Check_lightsensor_g.Bit.B5:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_Check_lightsensor_g.Bit.B6:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_Check_lightsensor_g.Bit.B7:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B0:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B1:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B2:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B3:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B4:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B5:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B6:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B7:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B0:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B1:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B2:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B3:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B4:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B5:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B6:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B7:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B0:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B1:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B2:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B3:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B4:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B5:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B6:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B7:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uf_LightAlgoReInit_g.Bit.B0:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uf_LightAlgoReInit_g.Bit.B1:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uf_LightAlgoReInit_g.Bit.B2:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uf_LightAlgoReInit_g.Bit.B3:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uf_LightAlgoReInit_g.Bit.B4:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uf_LightAlgoReInit_g.Bit.B5:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uf_LightAlgoReInit_g.Bit.B6:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uf_LightAlgoReInit_g.Bit.B7:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rb_AfterVddPowerFailDelay_g:255
TEST.END

-- Test Case: 02_powerOkNoPotiChange
TEST.UNIT:G5_irlight
TEST.SUBPROGRAM:lightScheduler
TEST.NEW
TEST.NAME:02_powerOkNoPotiChange
TEST.NOTES:
No power fail, poti is not changed
-> rb_AfterVddPowerFailDelay_g = 0 (no power fail)
-> uf_LightAlgoReInit_g.Bit.B1 = 0 (no poti change)
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_irlight.<<GLOBAL>>.rw_dayCounter_mg:<<MAX>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rw_nightCounter_mg:<<MAX>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.uf_LightAlgoReInit_g.Bit.B1:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.Day_Delay:<<MAX>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.Night_Delay:<<MAX>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rb_AfterVddPowerFailDelay_g:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rw_dayCounter_mg:<<MAX>>
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rw_nightCounter_mg:<<MAX>>
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uf_LightAlgoReInit_g.Bit.B1:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.Day_Delay:<<MAX>>
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.Night_Delay:<<MAX>>
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rb_AfterVddPowerFailDelay_g:0
TEST.END

-- Test Case: 03_powerOkNoDayCount
TEST.UNIT:G5_irlight
TEST.SUBPROGRAM:lightScheduler
TEST.NEW
TEST.NAME:03_powerOkNoDayCount
TEST.NOTES:
No power fail, poti is not changed
-> rb_AfterVddPowerFailDelay_g = 0 (no power fail)
-> uf_LightAlgoReInit_g.Bit.B1 = 1 #8poti change)

EEPROM parameters:
Day_Delay = 0xFF
Night_Delay = 0xFF

Day night counters:
rw_dayCounter_mg = 16220
rw_nihgtCounter_mg = 16220

-> no running day and night counters
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_irlight.<<GLOBAL>>.rw_dayCounter_mg:16220
TEST.VALUE:G5_irlight.<<GLOBAL>>.rw_nightCounter_mg:16220
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B1:1
TEST.VALUE:G5_irlight.<<GLOBAL>>.uf_LightAlgoReInit_g.Bit.B1:1
TEST.VALUE:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.Day_Delay:<<MAX>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.Night_Delay:<<MAX>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rb_AfterVddPowerFailDelay_g:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rw_dayCounter_mg:16220
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rw_nightCounter_mg:16220
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B1:1
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uf_LightAlgoReInit_g.Bit.B1:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.Day_Delay:<<MAX>>
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.Night_Delay:<<MAX>>
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rb_AfterVddPowerFailDelay_g:0
TEST.END

-- Test Case: 04_powerOkNoNightCount
TEST.UNIT:G5_irlight
TEST.SUBPROGRAM:lightScheduler
TEST.NEW
TEST.NAME:04_powerOkNoNightCount
TEST.NOTES:
No power fail, poti is not changed
-> rb_AfterVddPowerFailDelay_g = 0 (no power fail)
-> uf_LightAlgoReInit_g.Bit.B1 = 1 (poti change)

EEPROM parameters:
Day_Delay = 0xFF
Night_Delay = 0xFF

Day night counters:
rw_dayCounter_mg = 16220
rw_nihgtCounter_mg = 16220

-> no running day and night counters
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_irlight.<<GLOBAL>>.rw_dayCounter_mg:16220
TEST.VALUE:G5_irlight.<<GLOBAL>>.rw_nightCounter_mg:16220
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B1:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uf_LightAlgoReInit_g.Bit.B1:1
TEST.VALUE:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.Day_Delay:<<MAX>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.Night_Delay:<<MAX>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rb_AfterVddPowerFailDelay_g:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rw_dayCounter_mg:16220
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rw_nightCounter_mg:16220
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B1:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uf_LightAlgoReInit_g.Bit.B1:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.Day_Delay:<<MAX>>
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.Night_Delay:<<MAX>>
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rb_AfterVddPowerFailDelay_g:0
TEST.END

-- Test Case: 05_powerOkDayCount
TEST.UNIT:G5_irlight
TEST.SUBPROGRAM:lightScheduler
TEST.NEW
TEST.NAME:05_powerOkDayCount
TEST.NOTES:
No power fail, poti is not changed
-> rb_AfterVddPowerFailDelay_g = 0 (no power fail)
-> uf_LightAlgoReInit_g.Bit.B1 = 1 (poti change)

EEPROM parameters:
Day_Delay = 0xFF
Night_Delay = 0xFF

Day night counters:
rw_dayCounter_mg = 16220
rw_nihgtCounter_mg = 16220

-> no running day and night counters
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_irlight.<<GLOBAL>>.rw_dayCounter_mg:16219
TEST.VALUE:G5_irlight.<<GLOBAL>>.rw_nightCounter_mg:16219
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B1:1
TEST.VALUE:G5_irlight.<<GLOBAL>>.uf_LightAlgoReInit_g.Bit.B1:1
TEST.VALUE:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.Day_Delay:<<MAX>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.Night_Delay:<<MAX>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rb_AfterVddPowerFailDelay_g:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rw_dayCounter_mg:16220
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rw_nightCounter_mg:16219
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B1:1
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uf_LightAlgoReInit_g.Bit.B1:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.Day_Delay:<<MAX>>
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.Night_Delay:<<MAX>>
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rb_AfterVddPowerFailDelay_g:0
TEST.END

-- Test Case: 06_powerOkNightCount
TEST.UNIT:G5_irlight
TEST.SUBPROGRAM:lightScheduler
TEST.NEW
TEST.NAME:06_powerOkNightCount
TEST.NOTES:
No power fail, poti is not changed
-> rb_AfterVddPowerFailDelay_g = 0 (no power fail)
-> uf_LightAlgoReInit_g.Bit.B1 = 1 (poti change)

EEPROM parameters:
Day_Delay = 0xFF
Night_Delay = 0xFF

Day night counters:
rw_dayCounter_mg = 16220
rw_nihgtCounter_mg = 16220

-> no running day and night counters
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_irlight.<<GLOBAL>>.rw_dayCounter_mg:16219
TEST.VALUE:G5_irlight.<<GLOBAL>>.rw_nightCounter_mg:16219
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B1:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uf_LightAlgoReInit_g.Bit.B1:1
TEST.VALUE:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.Day_Delay:<<MAX>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.Night_Delay:<<MAX>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rb_AfterVddPowerFailDelay_g:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rw_dayCounter_mg:16219
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rw_nightCounter_mg:16220
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B1:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uf_LightAlgoReInit_g.Bit.B1:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.Day_Delay:<<MAX>>
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.Night_Delay:<<MAX>>
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rb_AfterVddPowerFailDelay_g:0
TEST.END

-- Test Case: 07_powerOk50msCounter
TEST.UNIT:G5_irlight
TEST.SUBPROGRAM:lightScheduler
TEST.NEW
TEST.NAME:07_powerOk50msCounter
TEST.NOTES:
No power fail, poti is not changed
-> rb_AfterVddPowerFailDelay_g = 0 (no power fail)
-> uf_LightAlgoReInit_g.Bit.B1 = 0 (no poti change)

Testcase user code to run rb_Irligth10ms_to4_counter_mg (50ms)
uF_modi_light_sens_h.AllBit &=0xF -> 0
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_irlight.<<GLOBAL>>.rw_dayCounter_mg:<<MAX>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rw_nightCounter_mg:<<MAX>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B0:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B1:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B2:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B3:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B4:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B5:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B6:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B7:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uf_LightAlgoReInit_g.Bit.B1:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.Day_Delay:<<MAX>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.Night_Delay:<<MAX>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rb_AfterVddPowerFailDelay_g:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rw_dayCounter_mg:<<MAX>>
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rw_nightCounter_mg:<<MAX>>
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B0:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B1:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B2:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B3:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B4:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B5:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B6:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B7:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uf_LightAlgoReInit_g.Bit.B1:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.Day_Delay:<<MAX>>
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.Night_Delay:<<MAX>>
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rb_AfterVddPowerFailDelay_g:0
TEST.VALUE_USER_CODE:<<testcase>>
int i;
for(i=0; i<5; i++)
{
   lightScheduler();
}
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: 08_powerOk50msCounter
TEST.UNIT:G5_irlight
TEST.SUBPROGRAM:lightScheduler
TEST.NEW
TEST.NAME:08_powerOk50msCounter
TEST.NOTES:
No power fail, poti is not changed
-> rb_AfterVddPowerFailDelay_g = 0 (no power fail)
-> uf_LightAlgoReInit_g.Bit.B1 = 0 (no poti change)

Testcase user code to run rb_Irligth10ms_to4_counter_mg (50ms)
uF_modi_light_sens_h.AllBit &=0xF -> 1
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_irlight.<<GLOBAL>>.rw_dayCounter_mg:<<MAX>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rw_nightCounter_mg:<<MAX>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B0:1
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B1:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B2:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B3:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B4:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B5:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B6:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B7:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uf_LightAlgoReInit_g.Bit.B1:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.Day_Delay:<<MAX>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.Night_Delay:<<MAX>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rb_AfterVddPowerFailDelay_g:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rw_dayCounter_mg:<<MAX>>
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rw_nightCounter_mg:<<MAX>>
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B0:1
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B1:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B2:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B3:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B4:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B5:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B6:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B7:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uf_LightAlgoReInit_g.Bit.B1:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.Day_Delay:<<MAX>>
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.Night_Delay:<<MAX>>
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rb_AfterVddPowerFailDelay_g:0
TEST.VALUE_USER_CODE:<<testcase>>
int i;
for(i=0; i<5; i++)
{
   lightScheduler();
}
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: 09_powerOk50msCounter
TEST.UNIT:G5_irlight
TEST.SUBPROGRAM:lightScheduler
TEST.NEW
TEST.NAME:09_powerOk50msCounter
TEST.NOTES:
No power fail, poti is not changed
-> rb_AfterVddPowerFailDelay_g = 0 (no power fail)
-> uf_LightAlgoReInit_g.Bit.B1 = 0 (no poti change)

Testcase user code to run rb_Irligth10ms_to4_counter_mg (50ms)
uF_modi_light_sens_h.AllBit &=0xF -> 2
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_irlight.<<GLOBAL>>.rw_dayCounter_mg:<<MAX>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rw_nightCounter_mg:<<MAX>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B0:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B1:1
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B2:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B3:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B4:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B5:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B6:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B7:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uf_LightAlgoReInit_g.Bit.B1:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.Day_Delay:<<MAX>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.Night_Delay:<<MAX>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rb_AfterVddPowerFailDelay_g:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rw_dayCounter_mg:<<MAX>>
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rw_nightCounter_mg:<<MAX>>
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B0:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B1:1
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B2:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B3:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B4:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B5:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B6:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B7:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uf_LightAlgoReInit_g.Bit.B1:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.Day_Delay:<<MAX>>
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.Night_Delay:<<MAX>>
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rb_AfterVddPowerFailDelay_g:0
TEST.VALUE_USER_CODE:<<testcase>>
int i;
for(i=0; i<5; i++)
{
   lightScheduler();
}
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: 10_powerOk50msCounter
TEST.UNIT:G5_irlight
TEST.SUBPROGRAM:lightScheduler
TEST.NEW
TEST.NAME:10_powerOk50msCounter
TEST.NOTES:
No power fail, poti is not changed
-> rb_AfterVddPowerFailDelay_g = 0 (no power fail)
-> uf_LightAlgoReInit_g.Bit.B1 = 0 (no poti change)

Testcase user code to run rb_Irligth10ms_to4_counter_mg (50ms)
uF_modi_light_sens_h.AllBit &=0xF -> 4
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_irlight.<<GLOBAL>>.rw_dayCounter_mg:<<MAX>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rw_nightCounter_mg:<<MAX>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B0:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B1:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B2:1
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B3:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B4:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B5:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B6:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B7:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uf_LightAlgoReInit_g.Bit.B1:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.Day_Delay:<<MAX>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.Night_Delay:<<MAX>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rb_AfterVddPowerFailDelay_g:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rw_dayCounter_mg:<<MAX>>
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rw_nightCounter_mg:<<MAX>>
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B0:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B1:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B2:1
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B3:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B4:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B5:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B6:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B7:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uf_LightAlgoReInit_g.Bit.B1:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.Day_Delay:<<MAX>>
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.Night_Delay:<<MAX>>
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rb_AfterVddPowerFailDelay_g:0
TEST.VALUE_USER_CODE:<<testcase>>
int i;
for(i=0; i<5; i++)
{
   lightScheduler();
}
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: 11_powerOk50msCounter
TEST.UNIT:G5_irlight
TEST.SUBPROGRAM:lightScheduler
TEST.NEW
TEST.NAME:11_powerOk50msCounter
TEST.NOTES:
No power fail, poti is not changed
-> rb_AfterVddPowerFailDelay_g = 0 (no power fail)
-> uf_LightAlgoReInit_g.Bit.B1 = 0 (no poti change)

Testcase user code to run rb_Irligth10ms_to4_counter_mg (50ms)
uF_modi_light_sens_h.AllBit &=0xF -> 8
-> uF_modi_light_sens_h.AllBit = 2 (see test case user code)
-> Software error counter reaches 3, by calling the light scheduler (see test case user code)

Note: uncovered brach b_SoftwareErrorCounter_g reaches 0xff, because it is resource intensive
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_irlight.<<GLOBAL>>.rw_dayCounter_mg:<<MAX>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rw_nightCounter_mg:<<MAX>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B0:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B1:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B2:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B3:<<KEEP>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B4:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B5:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B6:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B7:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B0:1
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B1:1
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B2:1
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B3:1
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B4:1
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B5:1
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B6:1
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B7:1
TEST.VALUE:G5_irlight.<<GLOBAL>>.uf_LightAlgoReInit_g.Bit.B1:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.Day_Delay:<<MAX>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.Night_Delay:<<MAX>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rb_AfterVddPowerFailDelay_g:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rw_dayCounter_mg:<<MAX>>
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rw_nightCounter_mg:<<MAX>>
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B0:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B1:1
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B2:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B3:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B4:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B5:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B6:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B7:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B0:1
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B1:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B2:1
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B3:1
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B4:1
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B5:1
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B6:1
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B7:1
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uf_LightAlgoReInit_g.Bit.B1:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.Day_Delay:<<MAX>>
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.Night_Delay:<<MAX>>
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rb_AfterVddPowerFailDelay_g:0
TEST.VALUE_USER_CODE:<<testcase>>
int i;
for(i=0; i<15; i++)
{
   uF_modi_lightsens_g.Bit.B3 = 1;
   lightScheduler();
}
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: light_Threshold_cac

-- Test Case: 01_ThresholdFactor26
TEST.UNIT:G5_irlight
TEST.SUBPROGRAM:light_Threshold_cac
TEST.NEW
TEST.NAME:01_ThresholdFactor26
TEST.NOTES:
Day thresholds for rw_DayThresholdFakt_l = 26
Night thresholds for rw_NightThresholdFakt_l = 26

All EEPROM thresholds are set to 255.
Threshold testing is done by varying factors via poti stage as follows:
rb_LSPotiStage_g	factor
0		26
1		34
2		45
3		54
4		64
5		77
6		90
7		102
8		115

Limits:

FW AMB DAY
400
All IR
240
AMB night
240
FW night
245
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_irlight.<<GLOBAL>>.rw_Amb_DayHigh_Threshold_g:<<MIN-1>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rb_Amb_NightLow_Threshold_g:<<MIN-1>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rw_FW_Day_Threshold_g:<<MAX>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rw_Amb_Day_Threshold_g:<<MAX+1>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rw_FW_DayHigh_Threshold_g:<<MIN>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rb_IR_Day_Threshold_g:<<MIN-1>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rb_Amb_Night_Threshold_g:<<MIN>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rb_IR_DayHigh_Threshold_g:<<MAX>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rb_FW_Night_Threshold_g:<<MIN>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rb_IR_Night_Threshold_g:<<MAX>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rb_FW_NightLow_Threshold_g:<<MIN>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rb_IR_NightLow_Threshold_g:<<MAX>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rb_LSPotiStage_g:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.Amb_Base_Day_Threshold:255
TEST.VALUE:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.Amb_Base_Night_Threshold:255
TEST.VALUE:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.FW_Base_Day_Threshold:255
TEST.VALUE:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.IR_Base_Day_Threshold:255
TEST.VALUE:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.FW_Base_Night_Threshold:255
TEST.VALUE:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.IR_Base_Night_Threshold:255
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rw_Amb_DayHigh_Threshold_g:115
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rb_Amb_NightLow_Threshold_g:78
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rw_FW_Day_Threshold_g:103
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rw_Amb_Day_Threshold_g:103
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rw_FW_DayHigh_Threshold_g:115
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rb_IR_Day_Threshold_g:103
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rb_Amb_Night_Threshold_g:103
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rb_IR_DayHigh_Threshold_g:115
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rb_FW_Night_Threshold_g:103
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rb_IR_Night_Threshold_g:103
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rb_FW_NightLow_Threshold_g:78
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rb_IR_NightLow_Threshold_g:78
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rb_LSPotiStage_g:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.Amb_Base_Day_Threshold:255
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.Amb_Base_Night_Threshold:255
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.FW_Base_Day_Threshold:255
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.IR_Base_Day_Threshold:255
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.FW_Base_Night_Threshold:255
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.IR_Base_Night_Threshold:255
TEST.END

-- Test Case: 02_ThresholdFactor34
TEST.UNIT:G5_irlight
TEST.SUBPROGRAM:light_Threshold_cac
TEST.NEW
TEST.NAME:02_ThresholdFactor34
TEST.NOTES:
Day thresholds for rw_DayThresholdFakt_l = 26
Night thresholds for rw_NightThresholdFakt_l = 26

All EEPROM thresholds are set to 255.
Threshold testing is done by varying factors via poti stage as follows:
rb_LSPotiStage_g	factor
0		26
1		34
2		45
3		54
4		64
5		77
6		90
7		102
8		115

Limits:

FW AMB DAY
400
All IR
240
AMB night
240
FW night
245
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_irlight.<<GLOBAL>>.rw_Amb_DayHigh_Threshold_g:<<MIN-1>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rb_Amb_NightLow_Threshold_g:<<MIN-1>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rw_FW_Day_Threshold_g:<<MAX>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rw_Amb_Day_Threshold_g:<<MAX+1>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rw_FW_DayHigh_Threshold_g:<<MIN>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rb_IR_Day_Threshold_g:<<MIN-1>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rb_Amb_Night_Threshold_g:<<MIN>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rb_IR_DayHigh_Threshold_g:<<MAX>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rb_FW_Night_Threshold_g:<<MIN>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rb_IR_Night_Threshold_g:<<MAX>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rb_FW_NightLow_Threshold_g:<<MIN>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rb_IR_NightLow_Threshold_g:<<MAX>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rb_LSPotiStage_g:1
TEST.VALUE:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.Amb_Base_Day_Threshold:255
TEST.VALUE:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.Amb_Base_Night_Threshold:255
TEST.VALUE:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.FW_Base_Day_Threshold:255
TEST.VALUE:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.IR_Base_Day_Threshold:255
TEST.VALUE:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.FW_Base_Night_Threshold:255
TEST.VALUE:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.IR_Base_Night_Threshold:255
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rw_Amb_DayHigh_Threshold_g:151
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rb_Amb_NightLow_Threshold_g:102
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rw_FW_Day_Threshold_g:135
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rw_Amb_Day_Threshold_g:135
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rw_FW_DayHigh_Threshold_g:151
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rb_IR_Day_Threshold_g:135
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rb_Amb_Night_Threshold_g:135
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rb_IR_DayHigh_Threshold_g:151
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rb_FW_Night_Threshold_g:135
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rb_IR_Night_Threshold_g:135
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rb_FW_NightLow_Threshold_g:102
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rb_IR_NightLow_Threshold_g:102
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rb_LSPotiStage_g:1
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.Amb_Base_Day_Threshold:255
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.Amb_Base_Night_Threshold:255
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.FW_Base_Day_Threshold:255
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.IR_Base_Day_Threshold:255
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.FW_Base_Night_Threshold:255
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.IR_Base_Night_Threshold:255
TEST.END

-- Test Case: 03_ThresholdFactor45
TEST.UNIT:G5_irlight
TEST.SUBPROGRAM:light_Threshold_cac
TEST.NEW
TEST.NAME:03_ThresholdFactor45
TEST.NOTES:
Day thresholds for rw_DayThresholdFakt_l = 26
Night thresholds for rw_NightThresholdFakt_l = 26

All EEPROM thresholds are set to 255.
Threshold testing is done by varying factors via poti stage as follows:
rb_LSPotiStage_g	factor
0		26
1		34
2		45
3		54
4		64
5		77
6		90
7		102
8		115

Limits:

FW AMB DAY
400
All IR
240
AMB night
240
FW night
245
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_irlight.<<GLOBAL>>.rw_Amb_DayHigh_Threshold_g:<<MIN-1>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rb_Amb_NightLow_Threshold_g:<<MIN-1>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rw_FW_Day_Threshold_g:<<MAX>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rw_Amb_Day_Threshold_g:<<MAX+1>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rw_FW_DayHigh_Threshold_g:<<MIN>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rb_IR_Day_Threshold_g:<<MIN-1>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rb_Amb_Night_Threshold_g:<<MIN>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rb_IR_DayHigh_Threshold_g:<<MAX>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rb_FW_Night_Threshold_g:<<MIN>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rb_IR_Night_Threshold_g:<<MAX>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rb_FW_NightLow_Threshold_g:<<MIN>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rb_IR_NightLow_Threshold_g:<<MAX>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rb_LSPotiStage_g:2
TEST.VALUE:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.Amb_Base_Day_Threshold:255
TEST.VALUE:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.Amb_Base_Night_Threshold:255
TEST.VALUE:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.FW_Base_Day_Threshold:255
TEST.VALUE:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.IR_Base_Day_Threshold:255
TEST.VALUE:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.FW_Base_Night_Threshold:255
TEST.VALUE:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.IR_Base_Night_Threshold:255
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rw_Amb_DayHigh_Threshold_g:201
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rb_Amb_NightLow_Threshold_g:135
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rw_FW_Day_Threshold_g:179
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rw_Amb_Day_Threshold_g:179
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rw_FW_DayHigh_Threshold_g:201
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rb_IR_Day_Threshold_g:179
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rb_Amb_Night_Threshold_g:179
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rb_IR_DayHigh_Threshold_g:201
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rb_FW_Night_Threshold_g:179
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rb_IR_Night_Threshold_g:179
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rb_FW_NightLow_Threshold_g:135
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rb_IR_NightLow_Threshold_g:135
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rb_LSPotiStage_g:2
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.Amb_Base_Day_Threshold:255
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.Amb_Base_Night_Threshold:255
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.FW_Base_Day_Threshold:255
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.IR_Base_Day_Threshold:255
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.FW_Base_Night_Threshold:255
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.IR_Base_Night_Threshold:255
TEST.END

-- Test Case: 04_ThresholdFactor54
TEST.UNIT:G5_irlight
TEST.SUBPROGRAM:light_Threshold_cac
TEST.NEW
TEST.NAME:04_ThresholdFactor54
TEST.NOTES:
Day thresholds for rw_DayThresholdFakt_l = 26
Night thresholds for rw_NightThresholdFakt_l = 26

All EEPROM thresholds are set to 255.
Threshold testing is done by varying factors via poti stage as follows:
rb_LSPotiStage_g	factor
0		26
1		34
2		45
3		54
4		64
5		77
6		90
7		102
8		115

Limits:

FW AMB DAY
400
All IR
240
AMB night
240
FW night
245

TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_irlight.<<GLOBAL>>.rw_Amb_DayHigh_Threshold_g:<<MIN-1>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rb_Amb_NightLow_Threshold_g:<<MIN-1>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rw_FW_Day_Threshold_g:<<MAX>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rw_Amb_Day_Threshold_g:<<MAX+1>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rw_FW_DayHigh_Threshold_g:<<MIN>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rb_IR_Day_Threshold_g:<<MIN-1>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rb_Amb_Night_Threshold_g:<<MIN>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rb_IR_DayHigh_Threshold_g:<<MAX>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rb_FW_Night_Threshold_g:<<MIN>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rb_IR_Night_Threshold_g:<<MAX>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rb_FW_NightLow_Threshold_g:<<MIN>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rb_IR_NightLow_Threshold_g:<<MAX>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rb_LSPotiStage_g:3
TEST.VALUE:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.Amb_Base_Day_Threshold:255
TEST.VALUE:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.Amb_Base_Night_Threshold:255
TEST.VALUE:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.FW_Base_Day_Threshold:255
TEST.VALUE:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.IR_Base_Day_Threshold:255
TEST.VALUE:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.FW_Base_Night_Threshold:255
TEST.VALUE:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.IR_Base_Night_Threshold:255
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rw_Amb_DayHigh_Threshold_g:241
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rb_Amb_NightLow_Threshold_g:162
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rw_FW_Day_Threshold_g:215
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rw_Amb_Day_Threshold_g:215
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rw_FW_DayHigh_Threshold_g:241
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rb_IR_Day_Threshold_g:215
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rb_Amb_Night_Threshold_g:215
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rb_IR_DayHigh_Threshold_g:240
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rb_FW_Night_Threshold_g:215
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rb_IR_Night_Threshold_g:215
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rb_FW_NightLow_Threshold_g:162
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rb_IR_NightLow_Threshold_g:162
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rb_LSPotiStage_g:3
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.Amb_Base_Day_Threshold:255
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.Amb_Base_Night_Threshold:255
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.FW_Base_Day_Threshold:255
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.IR_Base_Day_Threshold:255
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.FW_Base_Night_Threshold:255
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.IR_Base_Night_Threshold:255
TEST.END

-- Test Case: 05_ThresholdFactor64
TEST.UNIT:G5_irlight
TEST.SUBPROGRAM:light_Threshold_cac
TEST.NEW
TEST.NAME:05_ThresholdFactor64
TEST.NOTES:
Day thresholds for rw_DayThresholdFakt_l = 26
Night thresholds for rw_NightThresholdFakt_l = 26

All EEPROM thresholds are set to 255.
Threshold testing is done by varying factors via poti stage as follows:
rb_LSPotiStage_g	factor
0		26
1		34
2		45
3		54
4		64
5		77
6		90
7		102
8		115

Limits:

FW AMB DAY
400
All IR
240
AMB night
240
FW night
245


TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_irlight.<<GLOBAL>>.rw_Amb_DayHigh_Threshold_g:<<MIN-1>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rb_Amb_NightLow_Threshold_g:<<MIN-1>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rw_FW_Day_Threshold_g:<<MAX>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rw_Amb_Day_Threshold_g:<<MAX+1>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rw_FW_DayHigh_Threshold_g:<<MIN>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rb_IR_Day_Threshold_g:<<MIN-1>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rb_Amb_Night_Threshold_g:<<MIN>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rb_IR_DayHigh_Threshold_g:<<MAX>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rb_FW_Night_Threshold_g:<<MIN>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rb_IR_Night_Threshold_g:<<MAX>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rb_FW_NightLow_Threshold_g:<<MIN>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rb_IR_NightLow_Threshold_g:<<MAX>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rb_LSPotiStage_g:4
TEST.VALUE:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.Amb_Base_Day_Threshold:255
TEST.VALUE:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.Amb_Base_Night_Threshold:255
TEST.VALUE:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.FW_Base_Day_Threshold:255
TEST.VALUE:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.IR_Base_Day_Threshold:255
TEST.VALUE:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.FW_Base_Night_Threshold:255
TEST.VALUE:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.IR_Base_Night_Threshold:255
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rw_Amb_DayHigh_Threshold_g:286
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rb_Amb_NightLow_Threshold_g:180
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rw_FW_Day_Threshold_g:255
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rw_Amb_Day_Threshold_g:255
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rw_FW_DayHigh_Threshold_g:286
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rb_IR_Day_Threshold_g:240
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rb_Amb_Night_Threshold_g:240
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rb_IR_DayHigh_Threshold_g:240
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rb_FW_Night_Threshold_g:245
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rb_IR_Night_Threshold_g:240
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rb_FW_NightLow_Threshold_g:184
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rb_IR_NightLow_Threshold_g:180
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rb_LSPotiStage_g:4
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.Amb_Base_Day_Threshold:255
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.Amb_Base_Night_Threshold:255
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.FW_Base_Day_Threshold:255
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.IR_Base_Day_Threshold:255
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.FW_Base_Night_Threshold:255
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.IR_Base_Night_Threshold:255
TEST.END

-- Test Case: 06_ThresholdFactor77
TEST.UNIT:G5_irlight
TEST.SUBPROGRAM:light_Threshold_cac
TEST.NEW
TEST.NAME:06_ThresholdFactor77
TEST.NOTES:
Day thresholds for rw_DayThresholdFakt_l = 26
Night thresholds for rw_NightThresholdFakt_l = 26

All EEPROM thresholds are set to 255.
Threshold testing is done by varying factors via poti stage as follows:
rb_LSPotiStage_g	factor
0		26
1		34
2		45
3		54
4		64
5		77
6		90
7		102
8		115

Limits:

FW AMB DAY
400
All IR
240
AMB night
240
FW night
245


TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_irlight.<<GLOBAL>>.rw_Amb_DayHigh_Threshold_g:<<MIN-1>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rb_Amb_NightLow_Threshold_g:<<MIN-1>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rw_FW_Day_Threshold_g:<<MAX>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rw_Amb_Day_Threshold_g:<<MAX+1>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rw_FW_DayHigh_Threshold_g:<<MIN>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rb_IR_Day_Threshold_g:<<MIN-1>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rb_Amb_Night_Threshold_g:<<MIN>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rb_IR_DayHigh_Threshold_g:<<MAX>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rb_FW_Night_Threshold_g:<<MIN>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rb_IR_Night_Threshold_g:<<MAX>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rb_FW_NightLow_Threshold_g:<<MIN>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rb_IR_NightLow_Threshold_g:<<MAX>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rb_LSPotiStage_g:5
TEST.VALUE:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.Amb_Base_Day_Threshold:255
TEST.VALUE:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.Amb_Base_Night_Threshold:255
TEST.VALUE:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.FW_Base_Day_Threshold:255
TEST.VALUE:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.IR_Base_Day_Threshold:255
TEST.VALUE:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.FW_Base_Night_Threshold:255
TEST.VALUE:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.IR_Base_Night_Threshold:255
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rw_Amb_DayHigh_Threshold_g:344
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rb_Amb_NightLow_Threshold_g:180
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rw_FW_Day_Threshold_g:306
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rw_Amb_Day_Threshold_g:306
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rw_FW_DayHigh_Threshold_g:344
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rb_IR_Day_Threshold_g:240
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rb_Amb_Night_Threshold_g:240
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rb_IR_DayHigh_Threshold_g:240
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rb_FW_Night_Threshold_g:245
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rb_IR_Night_Threshold_g:240
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rb_FW_NightLow_Threshold_g:184
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rb_IR_NightLow_Threshold_g:180
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rb_LSPotiStage_g:5
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.Amb_Base_Day_Threshold:255
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.Amb_Base_Night_Threshold:255
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.FW_Base_Day_Threshold:255
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.IR_Base_Day_Threshold:255
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.FW_Base_Night_Threshold:255
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.IR_Base_Night_Threshold:255
TEST.END

-- Test Case: 07_ThresholdFactor90
TEST.UNIT:G5_irlight
TEST.SUBPROGRAM:light_Threshold_cac
TEST.NEW
TEST.NAME:07_ThresholdFactor90
TEST.NOTES:
Day thresholds for rw_DayThresholdFakt_l = 26
Night thresholds for rw_NightThresholdFakt_l = 26

All EEPROM thresholds are set to 255.
Threshold testing is done by varying factors via poti stage as follows:
rb_LSPotiStage_g	factor
0		26
1		34
2		45
3		54
4		64
5		77
6		90
7		102
8		115

Limits:

FW AMB DAY
400
All IR
240
AMB night
240
FW night
245


TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_irlight.<<GLOBAL>>.rw_Amb_DayHigh_Threshold_g:<<MIN-1>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rb_Amb_NightLow_Threshold_g:<<MIN-1>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rw_FW_Day_Threshold_g:<<MAX>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rw_Amb_Day_Threshold_g:<<MAX+1>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rw_FW_DayHigh_Threshold_g:<<MIN>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rb_IR_Day_Threshold_g:<<MIN-1>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rb_Amb_Night_Threshold_g:<<MIN>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rb_IR_DayHigh_Threshold_g:<<MAX>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rb_FW_Night_Threshold_g:<<MIN>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rb_IR_Night_Threshold_g:<<MAX>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rb_FW_NightLow_Threshold_g:<<MIN>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rb_IR_NightLow_Threshold_g:<<MAX>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rb_LSPotiStage_g:6
TEST.VALUE:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.Amb_Base_Day_Threshold:255
TEST.VALUE:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.Amb_Base_Night_Threshold:255
TEST.VALUE:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.FW_Base_Day_Threshold:255
TEST.VALUE:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.IR_Base_Day_Threshold:255
TEST.VALUE:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.FW_Base_Night_Threshold:255
TEST.VALUE:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.IR_Base_Night_Threshold:255
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rw_Amb_DayHigh_Threshold_g:400
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rb_Amb_NightLow_Threshold_g:180
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rw_FW_Day_Threshold_g:358
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rw_Amb_Day_Threshold_g:358
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rw_FW_DayHigh_Threshold_g:400
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rb_IR_Day_Threshold_g:240
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rb_Amb_Night_Threshold_g:240
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rb_IR_DayHigh_Threshold_g:240
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rb_FW_Night_Threshold_g:245
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rb_IR_Night_Threshold_g:240
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rb_FW_NightLow_Threshold_g:184
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rb_IR_NightLow_Threshold_g:180
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rb_LSPotiStage_g:6
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.Amb_Base_Day_Threshold:255
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.Amb_Base_Night_Threshold:255
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.FW_Base_Day_Threshold:255
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.IR_Base_Day_Threshold:255
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.FW_Base_Night_Threshold:255
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.IR_Base_Night_Threshold:255
TEST.END

-- Test Case: 08_ThresholdFactor102
TEST.UNIT:G5_irlight
TEST.SUBPROGRAM:light_Threshold_cac
TEST.NEW
TEST.NAME:08_ThresholdFactor102
TEST.NOTES:
Day thresholds for rw_DayThresholdFakt_l = 26
Night thresholds for rw_NightThresholdFakt_l = 26

All EEPROM thresholds are set to 255.
Threshold testing is done by varying factors via poti stage as follows:
rb_LSPotiStage_g	factor
0		26
1		34
2		45
3		54
4		64
5		77
6		90
7		102
8		115

Limits:

FW AMB DAY
400
All IR
240
AMB night
240
FW night
245


TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_irlight.<<GLOBAL>>.rw_Amb_DayHigh_Threshold_g:<<MIN-1>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rb_Amb_NightLow_Threshold_g:<<MIN-1>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rw_FW_Day_Threshold_g:<<MAX>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rw_Amb_Day_Threshold_g:<<MAX+1>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rw_FW_DayHigh_Threshold_g:<<MIN>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rb_IR_Day_Threshold_g:<<MIN-1>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rb_Amb_Night_Threshold_g:<<MIN>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rb_IR_DayHigh_Threshold_g:<<MAX>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rb_FW_Night_Threshold_g:<<MIN>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rb_IR_Night_Threshold_g:<<MAX>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rb_FW_NightLow_Threshold_g:<<MIN>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rb_IR_NightLow_Threshold_g:<<MAX>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rb_LSPotiStage_g:7
TEST.VALUE:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.Amb_Base_Day_Threshold:255
TEST.VALUE:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.Amb_Base_Night_Threshold:255
TEST.VALUE:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.FW_Base_Day_Threshold:255
TEST.VALUE:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.IR_Base_Day_Threshold:255
TEST.VALUE:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.FW_Base_Night_Threshold:255
TEST.VALUE:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.IR_Base_Night_Threshold:255
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rw_Amb_DayHigh_Threshold_g:400
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rb_Amb_NightLow_Threshold_g:180
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rw_FW_Day_Threshold_g:400
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rw_Amb_Day_Threshold_g:400
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rw_FW_DayHigh_Threshold_g:400
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rb_IR_Day_Threshold_g:240
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rb_Amb_Night_Threshold_g:240
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rb_IR_DayHigh_Threshold_g:240
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rb_FW_Night_Threshold_g:245
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rb_IR_Night_Threshold_g:240
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rb_FW_NightLow_Threshold_g:184
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rb_IR_NightLow_Threshold_g:180
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rb_LSPotiStage_g:7
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.Amb_Base_Day_Threshold:255
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.Amb_Base_Night_Threshold:255
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.FW_Base_Day_Threshold:255
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.IR_Base_Day_Threshold:255
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.FW_Base_Night_Threshold:255
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.IR_Base_Night_Threshold:255
TEST.END

-- Test Case: 09_ThresholdFactor115
TEST.UNIT:G5_irlight
TEST.SUBPROGRAM:light_Threshold_cac
TEST.NEW
TEST.NAME:09_ThresholdFactor115
TEST.NOTES:
Day thresholds for rw_DayThresholdFakt_l = 26
Night thresholds for rw_NightThresholdFakt_l = 26

All EEPROM thresholds are set to 255.
Threshold testing is done by varying factors via poti stage as follows:
rb_LSPotiStage_g	factor
0		26
1		34
2		45
3		54
4		64
5		77
6		90
7		102
8		115

Limits:

FW AMB DAY
400
All IR
240
AMB night
240
FW night
245


TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_irlight.<<GLOBAL>>.rw_Amb_DayHigh_Threshold_g:<<MIN-1>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rb_Amb_NightLow_Threshold_g:<<MIN-1>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rw_FW_Day_Threshold_g:<<MAX>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rw_Amb_Day_Threshold_g:<<MAX+1>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rw_FW_DayHigh_Threshold_g:<<MIN>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rb_IR_Day_Threshold_g:<<MIN-1>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rb_Amb_Night_Threshold_g:<<MIN>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rb_IR_DayHigh_Threshold_g:<<MAX>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rb_FW_Night_Threshold_g:<<MIN>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rb_IR_Night_Threshold_g:<<MAX>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rb_FW_NightLow_Threshold_g:<<MIN>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rb_IR_NightLow_Threshold_g:<<MAX>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rb_LSPotiStage_g:8
TEST.VALUE:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.Amb_Base_Day_Threshold:255
TEST.VALUE:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.Amb_Base_Night_Threshold:255
TEST.VALUE:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.FW_Base_Day_Threshold:255
TEST.VALUE:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.IR_Base_Day_Threshold:255
TEST.VALUE:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.FW_Base_Night_Threshold:255
TEST.VALUE:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.IR_Base_Night_Threshold:255
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rw_Amb_DayHigh_Threshold_g:400
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rb_Amb_NightLow_Threshold_g:180
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rw_FW_Day_Threshold_g:400
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rw_Amb_Day_Threshold_g:400
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rw_FW_DayHigh_Threshold_g:400
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rb_IR_Day_Threshold_g:240
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rb_Amb_Night_Threshold_g:240
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rb_IR_DayHigh_Threshold_g:240
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rb_FW_Night_Threshold_g:245
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rb_IR_Night_Threshold_g:240
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rb_FW_NightLow_Threshold_g:184
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rb_IR_NightLow_Threshold_g:180
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rb_LSPotiStage_g:8
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.Amb_Base_Day_Threshold:255
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.Amb_Base_Night_Threshold:255
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.FW_Base_Day_Threshold:255
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.IR_Base_Day_Threshold:255
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.FW_Base_Night_Threshold:255
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.IR_Base_Night_Threshold:255
TEST.END

-- Subprogram: light_init

-- Test Case: 01_light_init
TEST.UNIT:G5_irlight
TEST.SUBPROGRAM:light_init
TEST.NEW
TEST.NAME:01_light_init
TEST.NOTES:
Initilisation test
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_irlight.<<GLOBAL>>.rb_PosSlopeCountFWLight_mg:<<MAX>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rw_highwayOFFtimer_mg:<<MID>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rw_Fasthighwaytimer_s:<<MIN-1>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rb_DARKSTARTDELAYCOUNTER_mg:<<MAX>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rb_WipeCounter_g:<<MIN-1>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rw_FwLightMul64MeanFast_g:<<MIN>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.rw_FwLightMul64MeanSlow_g:<<MAX+1>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B0:1
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B1:1
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B2:1
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B3:1
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B4:1
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B5:1
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B6:1
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B7:1
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B0:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B1:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B2:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B3:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B4:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B5:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B6:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B7:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.rb_FwLightDiv4_g:<<MAX>>
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rb_PosSlopeCountFWLight_mg:50
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rw_highwayOFFtimer_mg:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rw_Fasthighwaytimer_s:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rb_DARKSTARTDELAYCOUNTER_mg:60
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rb_WipeCounter_g:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rw_FwLightMul64MeanFast_g:0xFF00
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rw_FwLightMul64MeanSlow_g:0xFF00
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B0:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B1:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B2:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B3:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B4:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B5:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B6:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B7:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B0:1
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B1:1
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B2:1
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B3:1
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B4:1
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B5:1
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B6:1
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B7:1
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.rb_FwLightDiv4_g:<<MAX>>
TEST.END

-- Subprogram: light_rainsensor_night_bit_calc

-- Test Case: 01_dayBelowThreshold
TEST.UNIT:G5_irlight
TEST.SUBPROGRAM:light_rainsensor_night_bit_calc
TEST.NEW
TEST.NAME:01_dayBelowThreshold
TEST.NOTES:
rbi_night_g = uF_LightInternalStatus_g . Bit . B3)
            = 1
cb_THRESHOLD_RS_NIGHT_MODE_mg = ((byte)5*((EEPROM_Struct_AD . EEPROMStructAD . RainNightBitThrs_g>>4)+1))
                              = (      5*((                            255                       >>4)+1))
                              = 80

cb_THRESHOLD_RS_DAY_MODE_mg   = ((byte)5*((EEPROM_Struct_AD . EEPROMStructAD . RainNightBitThrs_g&0x0F)+1))
                              = (      5*((                            255                       &0x0F)+1))
                              = 80

get_rw_Amb_light16bit_g()     = 80
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B3:1
TEST.VALUE:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.RainNightBitThrs_g:0xFF
TEST.VALUE:uut_prototype_stubs.get_rw_Amb_light16bit_g.return:80
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B3:1
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.RainNightBitThrs_g:0xFF
TEST.END

-- Test Case: 02_dayAboveThreshold
TEST.UNIT:G5_irlight
TEST.SUBPROGRAM:light_rainsensor_night_bit_calc
TEST.NEW
TEST.NAME:02_dayAboveThreshold
TEST.NOTES:
rbi_night_g = uF_LightInternalStatus_g . Bit . B3)
            = 1 -> 0 after 250 calls
cb_THRESHOLD_RS_NIGHT_MODE_mg = ((byte)5*((EEPROM_Struct_AD . EEPROMStructAD . RainNightBitThrs_g>>4)+1))
                              = (      5*((                            255                       >>4)+1))
                              = 80

cb_THRESHOLD_RS_DAY_MODE_mg   = ((byte)5*((EEPROM_Struct_AD . EEPROMStructAD . RainNightBitThrs_g&0x0F)+1))
                              = (      5*((                            255                       &0x0F)+1))
                              = 80

get_rw_Amb_light16bit_g()     = 81
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:FALSE
TEST.VALUE:G5_irlight.<<GLOBAL>>.vc_rb_DayNightcounter_NightBit_g:<<KEEP>>
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B3:1
TEST.VALUE:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.RainNightBitThrs_g:0xFF
TEST.VALUE:uut_prototype_stubs.get_rw_Amb_light16bit_g.return:81
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.vc_rb_DayNightcounter_NightBit_g:250
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B3:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.RainNightBitThrs_g:0xFF
TEST.VALUE_USER_CODE:<<testcase>>
for(vc_rb_DayNightcounter_NightBit_g=0; vc_rb_DayNightcounter_NightBit_g<cb_NIGHTBITDELAY_mg; vc_rb_DayNightcounter_NightBit_g++)
{
    light_rainsensor_night_bit_calc();
}
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: 03_nightAboveThreshold
TEST.UNIT:G5_irlight
TEST.SUBPROGRAM:light_rainsensor_night_bit_calc
TEST.NEW
TEST.NAME:03_nightAboveThreshold
TEST.NOTES:
rbi_night_g = uF_LightInternalStatus_g . Bit . B3)
            = 1
cb_THRESHOLD_RS_NIGHT_MODE_mg = ((byte)5*((EEPROM_Struct_AD . EEPROMStructAD . RainNightBitThrs_g>>4)+1))
                              = (      5*((                            175                       >>4)+1))
                              = 55

cb_THRESHOLD_RS_DAY_MODE_mg   = ((byte)5*((EEPROM_Struct_AD . EEPROMStructAD . RainNightBitThrs_g&0x0F)+1))
                              = (      5*((                            175                       &0x0F)+1))
                              = 80

get_rw_Amb_light16bit_g()     = 80
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B3:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.RainNightBitThrs_g:175
TEST.VALUE:uut_prototype_stubs.get_rw_Amb_light16bit_g.return:55
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B3:0
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.RainNightBitThrs_g:175
TEST.END

-- Test Case: 04_nightBelowThreshold
TEST.UNIT:G5_irlight
TEST.SUBPROGRAM:light_rainsensor_night_bit_calc
TEST.NEW
TEST.NAME:04_nightBelowThreshold
TEST.NOTES:
rbi_night_g = uF_LightInternalStatus_g . Bit . B3)
            = 1
cb_THRESHOLD_RS_NIGHT_MODE_mg = ((byte)5*((EEPROM_Struct_AD . EEPROMStructAD . RainNightBitThrs_g>>4)+1))
                              = (      5*((                            175                       >>4)+1))
                              = 55

cb_THRESHOLD_RS_DAY_MODE_mg   = ((byte)5*((EEPROM_Struct_AD . EEPROMStructAD . RainNightBitThrs_g&0x0F)+1))
                              = (      5*((                            175                       &0x0F)+1))
                              = 80

get_rw_Amb_light16bit_g()     = 80
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_irlight.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B3:0
TEST.VALUE:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.RainNightBitThrs_g:175
TEST.VALUE:uut_prototype_stubs.get_rw_Amb_light16bit_g.return:54
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B3:1
TEST.EXPECTED:G5_irlight.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.RainNightBitThrs_g:175
TEST.VALUE_USER_CODE:<<testcase>>
for(vc_rb_DayNightcounter_NightBit_g=0; vc_rb_DayNightcounter_NightBit_g<cb_NIGHTBITDELAY_mg; vc_rb_DayNightcounter_NightBit_g++)
{
    light_rainsensor_night_bit_calc();
}
TEST.END_VALUE_USER_CODE:
TEST.END

-- COMPOUND TESTS

TEST.SUBPROGRAM:<<COMPOUND>>
TEST.NEW
TEST.NAME:01_afterWashingInPark
TEST.NOTES:
The after wash delay counter, rw_afterWashingTime_counter_s is a local static, therefore a 2 slot compound test is required to hit all active washing branches:
-> Slot 1: Active washing. Initialises rw_afterWashingTime_counter_s to an EEPROM parameter (500 in this case)
-> Slot 2: Inactive washing. Decrements rw_afterWashingTime_counter_s, via test case user code only once.
TEST.END_NOTES:
TEST.SLOT: "1", "G5_irlight", "IO_CalculateWiperActivity", "1", "03_washingActive"
TEST.SLOT: "2", "G5_irlight", "IO_CalculateWiperActivity", "1", "04_washingInactive"
TEST.END
--

-- COMPOUND TESTS

TEST.SUBPROGRAM:<<COMPOUND>>
TEST.NEW
TEST.NAME:02_NotInParkNoWipe
TEST.NOTES:
The after wash delay counter, rw_afterWashingTime_counter_s is a local static, therefore a 2 slot compound test is required to hit all active washing branches:
-> Slot 1: Active washing. Initialises rw_afterWashingTime_counter_s to an EEPROM parameter (500 in this case)
-> Slot 2: Inactive washing. Decrements rw_afterWashingTime_counter_s, via test case user code, twice.
    -> After washing delay time is not reached: rw_afterWashingTime_counter_s = 498
    -> No wipe time overflows: rw_NoWipeTime_g = 0xFFFE -> 0xFFFF (first function call); 0xFFFF -> 0xFFFF (second function call)
TEST.END_NOTES:
TEST.SLOT: "1", "G5_irlight", "IO_CalculateWiperActivity", "1", "03_washingActive"
TEST.SLOT: "2", "G5_irlight", "IO_CalculateWiperActivity", "1", "05_NotInParkInDelay"
TEST.END
--

-- COMPOUND TESTS

TEST.SUBPROGRAM:<<COMPOUND>>
TEST.NEW
TEST.NAME:03_NotInParkAfterWashing
TEST.NOTES:
The after wash delay counter, rw_afterWashingTime_counter_s is a local static, therefore a 2 slot compound test is required to hit all active washing branches:
-> Slot 1: Active washing. Initialises rw_afterWashingTime_counter_s to an EEPROM parameter (500 in this case)
-> Slot 2: Inactive washing. Decrements rw_afterWashingTime_counter_s, via test case user code, decremented twice.
    -> After washing delay time is not reached: rw_afterWashingTime_counter_s = 498
    -> No wipe time overflows: rw_NoWipeTime_g = 0xFFFE -> 0xFFFF (first function call); 0xFFFF -> 0xFFFF (second function call)
TEST.END_NOTES:
TEST.SLOT: "1", "G5_irlight", "IO_CalculateWiperActivity", "1", "03_washingActive"
TEST.SLOT: "2", "G5_irlight", "IO_CalculateWiperActivity", "1", "06_NotInParkDelayOver"
TEST.END
--

-- COMPOUND TESTS

TEST.SUBPROGRAM:<<COMPOUND>>
TEST.NEW
TEST.NAME:04_NotInParkPositionWiping
TEST.NOTES:
The after wash delay counter, rw_afterWashingTime_counter_s is a local static, therefore a 2 slot compound test is required to hit all active washing branches:
-> Slot 1: Active washing. Initialises rw_afterWashingTime_counter_s to an EEPROM parameter (500 in this case)
-> Slot 2: Inactive washing. Decrements rw_afterWashingTime_counter_s, via test case user code, to zero.
-> Slot 3: Last park position. Wiper has moved and wipe counter is reset after reaching maximum
TEST.END_NOTES:
TEST.SLOT: "1", "G5_irlight", "IO_CalculateWiperActivity", "1", "03_washingActive"
TEST.SLOT: "2", "G5_irlight", "IO_CalculateWiperActivity", "1", "07_NotInParkLastContact"
TEST.SLOT: "3", "G5_irlight", "IO_CalculateWiperActivity", "1", "08_NotInParkLastPosition"
TEST.END
--

-- COMPOUND TESTS

TEST.SUBPROGRAM:<<COMPOUND>>
TEST.NEW
TEST.NAME:05_NotInParkWashingActive
TEST.NOTES:
The after wash delay counter, rw_afterWashingTime_counter_s is a local static, therefore a 2 slot compound test is required to hit all active washing branches:
-> Slot 1: Active washing. Initialises rw_afterWashingTime_counter_s to an EEPROM parameter (500 in this case)
-> Slot 2: Inactive washing. Decrements rw_afterWashingTime_counter_s, via test case user code, to zero.
-> Slot 3: Active washing. Slot is executed thrice to test the no wipe time out. It is run from 0xFFFE and limited at 0xFFFF
TEST.END_NOTES:
TEST.SLOT: "1", "G5_irlight", "IO_CalculateWiperActivity", "1", "03_washingActive"
TEST.SLOT: "2", "G5_irlight", "IO_CalculateWiperActivity", "1", "07_NotInParkLastContact"
TEST.SLOT: "3", "G5_irlight", "IO_CalculateWiperActivity", "3", "09_NotInParkWashingActive"
TEST.END
--
