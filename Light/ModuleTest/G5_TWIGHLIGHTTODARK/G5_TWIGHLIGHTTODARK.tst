-- VectorCAST 6.2n
-- Test Case Script
-- 
-- Environment    : G5_TWIGHLIGHTTODARK
-- Unit(s) Under Test: G5_TwilightToDark
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Subprogram: darkToTwilight

-- Test Case: 01_darkFalse
TEST.UNIT:G5_TwilightToDark
TEST.SUBPROGRAM:darkToTwilight
TEST.NEW
TEST.NAME:01_darkFalse
TEST.NOTES:
isDarkActive = FALSE
- rb_darkIsActive = FALSE is passed to function isDarkActive
-> rw_DarkToTwighlightCounter_g = 0xFFFF -> 0xFFFF (NOP)
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.STUB:G5_TwilightToDark.isDarkActive
TEST.VALUE:G5_TwilightToDark.<<GLOBAL>>.rb_darkIsActive:0
TEST.VALUE:G5_TwilightToDark.<<GLOBAL>>.rw_DarkToTwilightCounter_g:<<MIN-1>>
TEST.VALUE:G5_TwilightToDark.isDarkActive.return:0
TEST.EXPECTED:G5_TwilightToDark.<<GLOBAL>>.rb_darkIsActive:0
TEST.EXPECTED:G5_TwilightToDark.<<GLOBAL>>.rw_DarkToTwilightCounter_g:<<MAX>>
TEST.END

-- Test Case: 02_darkTrueFwFalse
TEST.UNIT:G5_TwilightToDark
TEST.SUBPROGRAM:darkToTwilight
TEST.NEW
TEST.NAME:02_darkTrueFwFalse
TEST.NOTES:
isDarkActive = TRUE:
- rb_darkIsActive = TRUE

EEPROM:
- rw_DarkToTwilightTime_g = EEPROM_Struct_AD.EEPROMStructAD.darkToTwilightTime * 20 = 5100
- rw_DarkToTwilightThreshFW_g = EEPROM_Struct_AD . EEPROMStructAD . darkToTwilightThreshFW * 3 = 255 * 3 = 765
- rw_DarkToTwilightThreshAMB_g = EEPROM_Struct_AD . EEPROMStructAD . darkToTwilightThreshAMB * 3 = 255 * 3 = 765
- cb_IR_NIGHT_THRESHOLD_s /3 = 10 / 3 = 3

Light values:
get_rw_FW_light16bit_g = 766 -> makes condition false
get_rw_AMB_light16bit_g = 765
get_rw_IR_light16bit_g = 3


-> rw_DarkToTwighlightCounter_g = 0xFFFF -> 0
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.STUB:G5_TwilightToDark.isDarkActive
TEST.VALUE:G5_TwilightToDark.<<GLOBAL>>.rb_darkIsActive:1
TEST.VALUE:G5_TwilightToDark.<<GLOBAL>>.rw_DarkToTwilightCounter_g:<<MIN-1>>
TEST.VALUE:G5_TwilightToDark.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.darkToTwilightTime:<<MIN-1>>
TEST.VALUE:G5_TwilightToDark.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.darkToTwilightThreshFW:<<MIN-1>>
TEST.VALUE:G5_TwilightToDark.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.darkToTwilightThreshAMB:<<MIN-1>>
TEST.VALUE:G5_TwilightToDark.isDarkActive.return:1
TEST.VALUE:uut_prototype_stubs.get_rw_Amb_light16bit_g.return:766
TEST.VALUE:uut_prototype_stubs.get_rw_FW_light16bit_g.return:765
TEST.VALUE:uut_prototype_stubs.get_rw_IR_light16bit_g.return:4
TEST.EXPECTED:G5_TwilightToDark.<<GLOBAL>>.rb_darkIsActive:1
TEST.EXPECTED:G5_TwilightToDark.<<GLOBAL>>.rw_DarkToTwilightCounter_g:0
TEST.EXPECTED:G5_TwilightToDark.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.darkToTwilightTime:<<MAX>>
TEST.EXPECTED:G5_TwilightToDark.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.darkToTwilightThreshFW:<<MAX>>
TEST.EXPECTED:G5_TwilightToDark.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.darkToTwilightThreshAMB:<<MAX>>
TEST.END

-- Test Case: 03_darkTrueAmbFalse
TEST.UNIT:G5_TwilightToDark
TEST.SUBPROGRAM:darkToTwilight
TEST.NEW
TEST.NAME:03_darkTrueAmbFalse
TEST.NOTES:
isDarkActive = TRUE:
- rb_darkIsActive = TRUE

EEPROM:
- rw_DarkToTwilightTime_g = EEPROM_Struct_AD.EEPROMStructAD.darkToTwilightTime * 20 = 5100
- rw_DarkToTwilightThreshFW_g = EEPROM_Struct_AD . EEPROMStructAD . darkToTwilightThreshFW * 3 = 255 * 3 = 765
- rw_DarkToTwilightThreshAMB_g = EEPROM_Struct_AD . EEPROMStructAD . darkToTwilightThreshAMB * 3 = 255 * 3 = 765
- cb_IR_NIGHT_THRESHOLD_s /3 = 10 / 3 = 3

Light values:
get_rw_FW_light16bit_g = 765
get_rw_AMB_light16bit_g = 766 -> makes condition false
get_rw_IR_light16bit_g = 3


-> rw_DarkToTwighlightCounter_g = 0xFFFF -> 0
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.STUB:G5_TwilightToDark.isDarkActive
TEST.VALUE:G5_TwilightToDark.<<GLOBAL>>.rb_darkIsActive:1
TEST.VALUE:G5_TwilightToDark.<<GLOBAL>>.rw_DarkToTwilightCounter_g:<<MIN-1>>
TEST.VALUE:G5_TwilightToDark.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.darkToTwilightTime:<<MIN-1>>
TEST.VALUE:G5_TwilightToDark.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.darkToTwilightThreshFW:<<MIN-1>>
TEST.VALUE:G5_TwilightToDark.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.darkToTwilightThreshAMB:<<MIN-1>>
TEST.VALUE:G5_TwilightToDark.isDarkActive.return:1
TEST.VALUE:uut_prototype_stubs.get_rw_Amb_light16bit_g.return:765
TEST.VALUE:uut_prototype_stubs.get_rw_FW_light16bit_g.return:766
TEST.VALUE:uut_prototype_stubs.get_rw_IR_light16bit_g.return:4
TEST.EXPECTED:G5_TwilightToDark.<<GLOBAL>>.rb_darkIsActive:1
TEST.EXPECTED:G5_TwilightToDark.<<GLOBAL>>.rw_DarkToTwilightCounter_g:0
TEST.EXPECTED:G5_TwilightToDark.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.darkToTwilightTime:<<MAX>>
TEST.EXPECTED:G5_TwilightToDark.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.darkToTwilightThreshFW:<<MAX>>
TEST.EXPECTED:G5_TwilightToDark.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.darkToTwilightThreshAMB:<<MAX>>
TEST.END

-- Test Case: 04_darkTrueIrFalse
TEST.UNIT:G5_TwilightToDark
TEST.SUBPROGRAM:darkToTwilight
TEST.NEW
TEST.NAME:04_darkTrueIrFalse
TEST.NOTES:
isDarkActive = TRUE:
- rb_darkIsActive = TRUE -> TRUE

EEPROM:
- rw_DarkToTwilightTime_g = EEPROM_Struct_AD.EEPROMStructAD.darkToTwilightTime * 20 = 5100
- rw_DarkToTwilightThreshFW_g = EEPROM_Struct_AD . EEPROMStructAD . darkToTwilightThreshFW * 3 = 255 * 3 = 765
- rw_DarkToTwilightThreshAMB_g = EEPROM_Struct_AD . EEPROMStructAD . darkToTwilightThreshAMB * 3 = 255 * 3 = 765
- cb_IR_NIGHT_THRESHOLD_s /3 = 10 / 3 = 3

Light values:
get_rw_FW_light16bit_g = 765
get_rw_AMB_light16bit_g = 765
get_rw_IR_light16bit_g = 4 -> makes condition false


-> rw_DarkToTwighlightCounter_g = 0xFFFF -> 0
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.STUB:G5_TwilightToDark.isDarkActive
TEST.VALUE:G5_TwilightToDark.<<GLOBAL>>.rb_darkIsActive:1
TEST.VALUE:G5_TwilightToDark.<<GLOBAL>>.rw_DarkToTwilightCounter_g:<<MIN-1>>
TEST.VALUE:G5_TwilightToDark.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.darkToTwilightTime:<<MIN-1>>
TEST.VALUE:G5_TwilightToDark.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.darkToTwilightThreshFW:<<MIN-1>>
TEST.VALUE:G5_TwilightToDark.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.darkToTwilightThreshAMB:<<MIN-1>>
TEST.VALUE:G5_TwilightToDark.isDarkActive.return:1
TEST.VALUE:uut_prototype_stubs.get_rw_Amb_light16bit_g.return:766
TEST.VALUE:uut_prototype_stubs.get_rw_FW_light16bit_g.return:766
TEST.VALUE:uut_prototype_stubs.get_rw_IR_light16bit_g.return:3
TEST.EXPECTED:G5_TwilightToDark.<<GLOBAL>>.rb_darkIsActive:1
TEST.EXPECTED:G5_TwilightToDark.<<GLOBAL>>.rw_DarkToTwilightCounter_g:0
TEST.EXPECTED:G5_TwilightToDark.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.darkToTwilightTime:<<MAX>>
TEST.EXPECTED:G5_TwilightToDark.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.darkToTwilightThreshFW:<<MAX>>
TEST.EXPECTED:G5_TwilightToDark.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.darkToTwilightThreshAMB:<<MAX>>
TEST.END

-- Test Case: 05_darkAllTrue
TEST.UNIT:G5_TwilightToDark
TEST.SUBPROGRAM:darkToTwilight
TEST.NEW
TEST.NAME:05_darkAllTrue
TEST.COMPOUND_ONLY
TEST.NOTES:
isDarkActive = TRUE:
- rb_darkIsActive = TRUE, TRUE, FALSE (FALSE set by setDarkActive)

EEPROM:
- rw_DarkToTwilightTime_g = EEPROM_Struct_AD.EEPROMStructAD.darkToTwilightTime * 20 = 5100
- rw_DarkToTwilightThreshFW_g = EEPROM_Struct_AD . EEPROMStructAD . darkToTwilightThreshFW * 3 = 255 * 3 = 765
- rw_DarkToTwilightThreshAMB_g = EEPROM_Struct_AD . EEPROMStructAD . darkToTwilightThreshAMB * 3 = 255 * 3 = 765
- cb_IR_NIGHT_THRESHOLD_s /3 = 10 / 3 = 3

Light values:
get_rw_FW_light16bit_g = 766
get_rw_AMB_light16bit_g = 766
get_rw_IR_light16bit_g = 4
-> all light conditions true

Compound test called thrice
-> rw_DarkToTwighlightCounter_g = 5098 -> 5099 -> 5100 -> 0 (0 set by setDarkActive)
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.STUB:G5_TwilightToDark.isDarkActive
TEST.VALUE:G5_TwilightToDark.<<GLOBAL>>.rb_darkIsActive:1
TEST.VALUE:G5_TwilightToDark.<<GLOBAL>>.rw_DarkToTwilightCounter_g:5098
TEST.VALUE:G5_TwilightToDark.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.darkToTwilightTime:<<MIN-1>>
TEST.VALUE:G5_TwilightToDark.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.darkToTwilightThreshFW:<<MIN-1>>
TEST.VALUE:G5_TwilightToDark.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.darkToTwilightThreshAMB:<<MIN-1>>
TEST.VALUE:G5_TwilightToDark.isDarkActive.return:1
TEST.VALUE:uut_prototype_stubs.get_rw_Amb_light16bit_g.return:766
TEST.VALUE:uut_prototype_stubs.get_rw_FW_light16bit_g.return:766
TEST.VALUE:uut_prototype_stubs.get_rw_IR_light16bit_g.return:4
TEST.EXPECTED:G5_TwilightToDark.<<GLOBAL>>.rb_darkIsActive:(2)1,0
TEST.EXPECTED:G5_TwilightToDark.<<GLOBAL>>.rw_DarkToTwilightCounter_g:5099,5100,0
TEST.EXPECTED:G5_TwilightToDark.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.darkToTwilightTime:<<MAX>>
TEST.EXPECTED:G5_TwilightToDark.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.darkToTwilightThreshFW:<<MAX>>
TEST.EXPECTED:G5_TwilightToDark.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.darkToTwilightThreshAMB:<<MAX>>
TEST.END

-- Subprogram: initTwilightToDark

-- Test Case: 01_initTwilightToDarkOn
TEST.UNIT:G5_TwilightToDark
TEST.SUBPROGRAM:initTwilightToDark
TEST.NEW
TEST.NAME:01_initTwilightToDarkOn
TEST.NOTES:
set dark active ON:
twighlightIsOn = TRUE

Following EEPROM thresholds are set:
EEPROMStructAD.twilightToDarkThreshFW = 255
EEPROMStructAD.twilightToDarkThreshAMB = 255

As a result macros used in this init functions are expanded to:
rw_TwighlightToDarkThreshFW = 255 * 3 = 765
rw_TwightlightToDarkThreshAMB = 255 * 3 = 765

Ambient and FW light values are set as follows:
get_rw_FW_light16bit_g = 764
get_rw_AMB_light16bit_g = 764

-> function setDarkActive is passed parameter TRUE
isActive 0 -> 1
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.STUB:G5_TwilightToDark.setDarkActive
TEST.VALUE:G5_TwilightToDark.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.twilightToDarkThreshFW:<<MIN-1>>
TEST.VALUE:G5_TwilightToDark.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.twilightToDarkThreshAMB:<<MIN-1>>
TEST.VALUE:G5_TwilightToDark.setDarkActive.isActive:0
TEST.VALUE:G5_TwilightToDark.initTwilightToDark.twilightIsOn:1
TEST.VALUE:uut_prototype_stubs.get_rw_Amb_light16bit_g.return:764
TEST.VALUE:uut_prototype_stubs.get_rw_FW_light16bit_g.return:764
TEST.EXPECTED:G5_TwilightToDark.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.twilightToDarkThreshFW:<<MAX>>
TEST.EXPECTED:G5_TwilightToDark.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.twilightToDarkThreshAMB:<<MAX>>
TEST.EXPECTED:G5_TwilightToDark.setDarkActive.isActive:1
TEST.EXPECTED:G5_TwilightToDark.initTwilightToDark.twilightIsOn:1
TEST.END

-- Test Case: 02_initTwilightToDarkOffFAMB
TEST.UNIT:G5_TwilightToDark
TEST.SUBPROGRAM:initTwilightToDark
TEST.NEW
TEST.NAME:02_initTwilightToDarkOffFAMB
TEST.NOTES:
set dark active OFF by AMB light condition:
twighlightIsOn = TRUE

Following EEPROM thresholds are set:
EEPROMStructAD.twilightToDarkThreshFW = 255
EEPROMStructAD.twilightToDarkThreshAMB = 255

As a result macros used in this init functions are expanded to:
rw_TwighlightToDarkThreshFW = 255 * 3 = 765
rw_TwightlightToDarkThreshAMB = 255 * 3 = 765

Ambient and FW light values are set as follows:
get_rw_FW_light16bit_g = 764
get_rw_AMB_light16bit_g = 765 -> this sets dark active to OFF

-> function setDarkActive is passed parameter TRUE
isActive 0 -> 1
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.STUB:G5_TwilightToDark.setDarkActive
TEST.VALUE:G5_TwilightToDark.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.twilightToDarkThreshFW:<<MIN-1>>
TEST.VALUE:G5_TwilightToDark.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.twilightToDarkThreshAMB:<<MIN-1>>
TEST.VALUE:G5_TwilightToDark.setDarkActive.isActive:1
TEST.VALUE:G5_TwilightToDark.initTwilightToDark.twilightIsOn:1
TEST.VALUE:uut_prototype_stubs.get_rw_Amb_light16bit_g.return:764
TEST.VALUE:uut_prototype_stubs.get_rw_FW_light16bit_g.return:765
TEST.EXPECTED:G5_TwilightToDark.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.twilightToDarkThreshFW:<<MAX>>
TEST.EXPECTED:G5_TwilightToDark.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.twilightToDarkThreshAMB:<<MAX>>
TEST.EXPECTED:G5_TwilightToDark.setDarkActive.isActive:0
TEST.EXPECTED:G5_TwilightToDark.initTwilightToDark.twilightIsOn:1
TEST.END

-- Test Case: 03_initTwilightToDarkOffFW
TEST.UNIT:G5_TwilightToDark
TEST.SUBPROGRAM:initTwilightToDark
TEST.NEW
TEST.NAME:03_initTwilightToDarkOffFW
TEST.NOTES:
set dark active OFF by FW light condition:
twighlightIsOn = TRUE

Following EEPROM thresholds are set:
EEPROMStructAD.twilightToDarkThreshFW = 255
EEPROMStructAD.twilightToDarkThreshAMB = 255

As a result macros used in this init functions are expanded to:
rw_TwighlightToDarkThreshFW = 255 * 3 = 765
rw_TwightlightToDarkThreshAMB = 255 * 3 = 765

Ambient and FW light values are set as follows:
get_rw_FW_light16bit_g = 765 -> this sets dark active to OFF
get_rw_AMB_light16bit_g = 764

-> function setDarkActive is passed parameter TRUE
isActive 0 -> 1
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.STUB:G5_TwilightToDark.setDarkActive
TEST.VALUE:G5_TwilightToDark.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.twilightToDarkThreshFW:<<MIN-1>>
TEST.VALUE:G5_TwilightToDark.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.twilightToDarkThreshAMB:<<MIN-1>>
TEST.VALUE:G5_TwilightToDark.setDarkActive.isActive:1
TEST.VALUE:G5_TwilightToDark.initTwilightToDark.twilightIsOn:1
TEST.VALUE:uut_prototype_stubs.get_rw_Amb_light16bit_g.return:765
TEST.VALUE:uut_prototype_stubs.get_rw_FW_light16bit_g.return:764
TEST.EXPECTED:G5_TwilightToDark.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.twilightToDarkThreshFW:<<MAX>>
TEST.EXPECTED:G5_TwilightToDark.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.twilightToDarkThreshAMB:<<MAX>>
TEST.EXPECTED:G5_TwilightToDark.setDarkActive.isActive:0
TEST.EXPECTED:G5_TwilightToDark.initTwilightToDark.twilightIsOn:1
TEST.END

-- Test Case: 04_initTwilightToDarkOffParam
TEST.UNIT:G5_TwilightToDark
TEST.SUBPROGRAM:initTwilightToDark
TEST.NEW
TEST.NAME:04_initTwilightToDarkOffParam
TEST.NOTES:
set dark active OFF by passing false to function:
twighlightIsOn = FALSE -> this sets dark active to OFF

Following EEPROM thresholds are set:
EEPROMStructAD.twilightToDarkThreshFW = 255
EEPROMStructAD.twilightToDarkThreshAMB = 255

As a result macros used in this init functions are expanded to:
rw_TwighlightToDarkThreshFW = 255 * 3 = 765
rw_TwightlightToDarkThreshAMB = 255 * 3 = 765

Ambient and FW light values are set as follows:
get_rw_FW_light16bit_g = 764
get_rw_AMB_light16bit_g = 764

-> function setDarkActive is passed parameter TRUE
isActive 0 -> 1
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.STUB:G5_TwilightToDark.setDarkActive
TEST.VALUE:G5_TwilightToDark.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.twilightToDarkThreshFW:<<MIN-1>>
TEST.VALUE:G5_TwilightToDark.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.twilightToDarkThreshAMB:<<MIN-1>>
TEST.VALUE:G5_TwilightToDark.setDarkActive.isActive:1
TEST.VALUE:G5_TwilightToDark.initTwilightToDark.twilightIsOn:1
TEST.VALUE:uut_prototype_stubs.get_rw_Amb_light16bit_g.return:765
TEST.VALUE:uut_prototype_stubs.get_rw_FW_light16bit_g.return:764
TEST.EXPECTED:G5_TwilightToDark.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.twilightToDarkThreshFW:<<MAX>>
TEST.EXPECTED:G5_TwilightToDark.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.twilightToDarkThreshAMB:<<MAX>>
TEST.EXPECTED:G5_TwilightToDark.setDarkActive.isActive:0
TEST.EXPECTED:G5_TwilightToDark.initTwilightToDark.twilightIsOn:1
TEST.END

-- Subprogram: isDarkActive

-- Test Case: 01_isDarkActiveTrue
TEST.UNIT:G5_TwilightToDark
TEST.SUBPROGRAM:isDarkActive
TEST.NEW
TEST.NAME:01_isDarkActiveTrue
TEST.NOTES:
isDarkActive = TRUE
-> rbDarkActive = 1
-> return = 0->1
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_TwilightToDark.<<GLOBAL>>.rb_darkIsActive:1
TEST.VALUE:G5_TwilightToDark.isDarkActive.return:0
TEST.EXPECTED:G5_TwilightToDark.<<GLOBAL>>.rb_darkIsActive:1
TEST.EXPECTED:G5_TwilightToDark.isDarkActive.return:1
TEST.END

-- Test Case: 02_isDarkActiveFalse
TEST.UNIT:G5_TwilightToDark
TEST.SUBPROGRAM:isDarkActive
TEST.NEW
TEST.NAME:02_isDarkActiveFalse
TEST.NOTES:
isDarkActive = FALSE
-> rbDarkActive = 0
-> return = 1->0
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_TwilightToDark.<<GLOBAL>>.rb_darkIsActive:0
TEST.VALUE:G5_TwilightToDark.isDarkActive.return:1
TEST.EXPECTED:G5_TwilightToDark.<<GLOBAL>>.rb_darkIsActive:0
TEST.EXPECTED:G5_TwilightToDark.isDarkActive.return:0
TEST.END

-- Subprogram: setDarkActive

-- Test Case: 01_setDarkActiveTrue
TEST.UNIT:G5_TwilightToDark
TEST.SUBPROGRAM:setDarkActive
TEST.NEW
TEST.NAME:01_setDarkActiveTrue
TEST.NOTES:
dark active is true
-> parameter isActive = TRUE

Leads to:
-> rb_darkIsActive = true
-> rwTwighlightToDarkCounter_g = 255 -> 0
-> rw_DarkToTwighlightCounter_g = 255
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_TwilightToDark.<<GLOBAL>>.rb_darkIsActive:0
TEST.VALUE:G5_TwilightToDark.<<GLOBAL>>.rw_DarkToTwilightCounter_g:<<MIN-1>>
TEST.VALUE:G5_TwilightToDark.<<GLOBAL>>.rw_TwilightToDarkCounter_g:<<MIN-1>>
TEST.VALUE:G5_TwilightToDark.setDarkActive.isActive:1
TEST.EXPECTED:G5_TwilightToDark.<<GLOBAL>>.rb_darkIsActive:1
TEST.EXPECTED:G5_TwilightToDark.<<GLOBAL>>.rw_DarkToTwilightCounter_g:<<MAX>>
TEST.EXPECTED:G5_TwilightToDark.<<GLOBAL>>.rw_TwilightToDarkCounter_g:<<MIN>>
TEST.EXPECTED:G5_TwilightToDark.setDarkActive.isActive:1
TEST.END

-- Test Case: 02_setDarkActiveFalse
TEST.UNIT:G5_TwilightToDark
TEST.SUBPROGRAM:setDarkActive
TEST.NEW
TEST.NAME:02_setDarkActiveFalse
TEST.NOTES:
dark active is false
-> parameter isActive = FALSE

Leads to:
-> rb_darkIsActive = TRUE -> FALSE
-> rwTwighlightToDarkCounter_g = 255
-> rw_DarkToTwighlightCounter_g = 255 -> 0
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_TwilightToDark.<<GLOBAL>>.rb_darkIsActive:1
TEST.VALUE:G5_TwilightToDark.<<GLOBAL>>.rw_DarkToTwilightCounter_g:<<MIN-1>>
TEST.VALUE:G5_TwilightToDark.<<GLOBAL>>.rw_TwilightToDarkCounter_g:<<MIN-1>>
TEST.VALUE:G5_TwilightToDark.setDarkActive.isActive:0
TEST.EXPECTED:G5_TwilightToDark.<<GLOBAL>>.rb_darkIsActive:0
TEST.EXPECTED:G5_TwilightToDark.<<GLOBAL>>.rw_DarkToTwilightCounter_g:<<MIN>>
TEST.EXPECTED:G5_TwilightToDark.<<GLOBAL>>.rw_TwilightToDarkCounter_g:<<MAX>>
TEST.EXPECTED:G5_TwilightToDark.setDarkActive.isActive:0
TEST.END

-- Subprogram: twilightToDark

-- Test Case: 01_darkTrueNop
TEST.UNIT:G5_TwilightToDark
TEST.SUBPROGRAM:twilightToDark
TEST.NEW
TEST.NAME:01_darkTrueNop
TEST.NOTES:
Twighlight to dark is TRUE (NOP)
-> rb_isDarkActive = TRUE -> TRUE
-> rw_TwilightToDarkCounter_g = 0xFF -> 0xFF
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_TwilightToDark.<<GLOBAL>>.rb_darkIsActive:1
TEST.VALUE:G5_TwilightToDark.<<GLOBAL>>.rw_TwilightToDarkCounter_g:<<MIN-1>>
TEST.EXPECTED:G5_TwilightToDark.<<GLOBAL>>.rb_darkIsActive:1
TEST.EXPECTED:G5_TwilightToDark.<<GLOBAL>>.rw_TwilightToDarkCounter_g:<<MAX>>
TEST.END

-- Test Case: 02_darkFalseFwAmbTrue.01
TEST.UNIT:G5_TwilightToDark
TEST.SUBPROGRAM:twilightToDark
TEST.NEW
TEST.NAME:02_darkFalseFwAmbTrue.01
TEST.COMPOUND_ONLY
TEST.NOTES:
Twighlight to dark is FALSE and both FW and AMB twighlight threshold TRUE
Test of rw_TwihglightToDarkCounter_g incrementing
- rb_isDarkActive = FALSE -> FALSE

EEPROM:
- rw_TwilightToDarkThreshAMB_g = EEPROM_Struct_AD.EEPROMStructAD.twilightToDarkThreshAMB * 3 = 255 * 3 = 765
- rw_TwilightToDarkThreshFW_g = EEPROM_Struct_AD.EEPROMStructAD.twilightToDarkThreshFW * 3 = 255 * 3 = 765
- rw_TwilightToDarkTime_g = EEPROM_Struct_AD.EEPROMStructAD.twilightToDarkTime * 40 = 255 * 40 = 10200
- rw_DarkToTwilightTime_g = EEPROM_Struct_AD.EEPROMStructAD.darkToTwilightTime * 20 = 255 * 20 = 5100

Light Values:
get_rw_Amb_light16bit_g = 764
get_rw_FW_light16bit_g = 764

-> rw_TwilightToDarkCounter_g += 3 init
-> Test case is compound only and called twice:
-> rw_TwilightToDarkCounter_g = 10196 -> 10199 -> 10202
-> isDarkActive = 0 -> 0

TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.STUB:G5_TwilightToDark.isDarkActive
TEST.VALUE:G5_TwilightToDark.<<GLOBAL>>.rb_darkIsActive:0
TEST.VALUE:G5_TwilightToDark.<<GLOBAL>>.rw_TwilightToDarkCounter_g:10196
TEST.VALUE:G5_TwilightToDark.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.twilightToDarkTime:<<MIN-1>>
TEST.VALUE:G5_TwilightToDark.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.darkToTwilightTime:<<MIN-1>>
TEST.VALUE:G5_TwilightToDark.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.twilightToDarkThreshFW:<<MIN-1>>
TEST.VALUE:G5_TwilightToDark.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.twilightToDarkThreshAMB:<<MIN-1>>
TEST.VALUE:G5_TwilightToDark.isDarkActive.return:0
TEST.VALUE:uut_prototype_stubs.get_rw_Amb_light16bit_g.return:764
TEST.VALUE:uut_prototype_stubs.get_rw_FW_light16bit_g.return:764
TEST.EXPECTED:G5_TwilightToDark.<<GLOBAL>>.rb_darkIsActive:0
TEST.EXPECTED:G5_TwilightToDark.<<GLOBAL>>.rw_TwilightToDarkCounter_g:10199,10202
TEST.EXPECTED:G5_TwilightToDark.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.twilightToDarkTime:<<MAX>>
TEST.EXPECTED:G5_TwilightToDark.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.darkToTwilightTime:<<MAX>>
TEST.EXPECTED:G5_TwilightToDark.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.twilightToDarkThreshFW:<<MAX>>
TEST.EXPECTED:G5_TwilightToDark.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.twilightToDarkThreshAMB:<<MAX>>
TEST.END

-- Test Case: 02_darkFalseFwAmbTrue.02
TEST.UNIT:G5_TwilightToDark
TEST.SUBPROGRAM:twilightToDark
TEST.NEW
TEST.NAME:02_darkFalseFwAmbTrue.02
TEST.COMPOUND_ONLY
TEST.NOTES:
Twighlight to dark is FLASE and both FW and AMB twighlight threshold TRUE
Test of rw_TwihglightToDarkCounter_g reached twighlight to dark time
- rb_isDarkActive = FALSE -> TRUE

EEPROM:
- rw_TwilightToDarkThreshAMB_g = EEPROM_Struct_AD.EEPROMStructAD.twilightToDarkThreshAMB * 3 = 255 * 3 = 765
- rw_TwilightToDarkThreshFW_g = EEPROM_Struct_AD.EEPROMStructAD.twilightToDarkThreshFW * 3 = 255 * 3 = 765
- rw_TwilightToDarkTime_g = EEPROM_Struct_AD.EEPROMStructAD.twilightToDarkTime * 40 = 255 * 40 = 10200
- rw_DarkToTwilightTime_g = EEPROM_Struct_AD.EEPROMStructAD.darkToTwilightTime * 20 = 255 * 20 = 5100

Light Values:
get_rw_Amb_light16bit_g = 764
get_rw_FW_light16bit_g = 764

-> rw_TwilightToDarkCounter_g += 3 not done (over limit)
-> Test case is compound only and called once:
-> rw_TwilightToDarkCounter_g = 10200 -> 0 (reset by setDarkActive)
-> isDarkActive = 0 -> 1

TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.STUB:G5_TwilightToDark.isDarkActive
TEST.VALUE:G5_TwilightToDark.<<GLOBAL>>.rb_darkIsActive:0
TEST.VALUE:G5_TwilightToDark.<<GLOBAL>>.rw_TwilightToDarkCounter_g:10200
TEST.VALUE:G5_TwilightToDark.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.twilightToDarkTime:<<MIN-1>>
TEST.VALUE:G5_TwilightToDark.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.darkToTwilightTime:<<MIN-1>>
TEST.VALUE:G5_TwilightToDark.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.twilightToDarkThreshFW:<<MIN-1>>
TEST.VALUE:G5_TwilightToDark.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.twilightToDarkThreshAMB:<<MIN-1>>
TEST.VALUE:G5_TwilightToDark.isDarkActive.return:1
TEST.VALUE:uut_prototype_stubs.get_rw_Amb_light16bit_g.return:764
TEST.VALUE:uut_prototype_stubs.get_rw_FW_light16bit_g.return:764
TEST.EXPECTED:G5_TwilightToDark.<<GLOBAL>>.rb_darkIsActive:1
TEST.EXPECTED:G5_TwilightToDark.<<GLOBAL>>.rw_TwilightToDarkCounter_g:0
TEST.EXPECTED:G5_TwilightToDark.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.twilightToDarkTime:<<MAX>>
TEST.EXPECTED:G5_TwilightToDark.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.darkToTwilightTime:<<MAX>>
TEST.EXPECTED:G5_TwilightToDark.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.twilightToDarkThreshFW:<<MAX>>
TEST.EXPECTED:G5_TwilightToDark.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.twilightToDarkThreshAMB:<<MAX>>
TEST.END

-- Test Case: 03_darkFalseAllFalse
TEST.UNIT:G5_TwilightToDark
TEST.SUBPROGRAM:twilightToDark
TEST.NEW
TEST.NAME:03_darkFalseAllFalse
TEST.NOTES:
Twighlight to dark is FALSE and both FW and AMB twighlight threshold FALSE
Test of rw_TwihglightToDarkCounter_g reached twighlight to dark time
- rb_isDarkActive = FALSE -> FALSE

EEPROM:
- rw_TwilightToDarkThreshAMB_g = (EEPROM_Struct_AD.EEPROMStructAD.twilightToDarkThreshAMB * 3) / 3 = (255 * 3) / 3 = 255
- rw_TwilightToDarkThreshFW_g = EEPROM_Struct_AD.EEPROMStructAD.twilightToDarkThreshFW * 3 +  (EEPROM_Struct_AD.EEPROMStructAD.twilightToDarkThreshFW * 3 / 2) = 255 * 3 + (255 * 3 / 2) = 1147
- rw_TwilightToDarkThreshIR_g = EEPROM_Struct_AD.EEPROMStructAD.twilightToDarkThreshIR * 3) / 3 = (255 * 3) / 3 = 255
- rw_TwilightToDarkTime_g = EEPROM_Struct_AD.EEPROMStructAD.twilightToDarkTime * 40 = 255 * 40 = 10200
- rw_DarkToTwilightTime_g = EEPROM_Struct_AD.EEPROMStructAD.darkToTwilightTime * 20 = 255 * 20 = 5100

Light Values:
get_rw_Amb_light16bit_g = 254
get_rw_FW_light16bit_g = 1147 -> makes condition FALSE
get_rw_IR_light16bit_g = 254

-> rw_TwilightToDarkCounter_g 0xFFFF -> 0
-> Test case is compound only and called twice:


TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.STUB:G5_TwilightToDark.isDarkActive
TEST.VALUE:G5_TwilightToDark.<<GLOBAL>>.rb_darkIsActive:0
TEST.VALUE:G5_TwilightToDark.<<GLOBAL>>.rw_TwilightToDarkCounter_g:<<MIN-1>>
TEST.VALUE:G5_TwilightToDark.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.twilightToDarkTime:<<MIN-1>>
TEST.VALUE:G5_TwilightToDark.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.darkToTwilightTime:<<MIN-1>>
TEST.VALUE:G5_TwilightToDark.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.twilightToDarkThreshFW:<<MIN-1>>
TEST.VALUE:G5_TwilightToDark.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.twilightToDarkThreshAMB:<<MIN-1>>
TEST.VALUE:G5_TwilightToDark.isDarkActive.return:0
TEST.VALUE:uut_prototype_stubs.get_rw_Amb_light16bit_g.return:254
TEST.VALUE:uut_prototype_stubs.get_rw_FW_light16bit_g.return:1147
TEST.VALUE:uut_prototype_stubs.get_rw_IR_light16bit_g.return:254
TEST.EXPECTED:G5_TwilightToDark.<<GLOBAL>>.rb_darkIsActive:0
TEST.EXPECTED:G5_TwilightToDark.<<GLOBAL>>.rw_TwilightToDarkCounter_g:0
TEST.EXPECTED:G5_TwilightToDark.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.twilightToDarkTime:<<MAX>>
TEST.EXPECTED:G5_TwilightToDark.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.darkToTwilightTime:<<MAX>>
TEST.EXPECTED:G5_TwilightToDark.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.twilightToDarkThreshFW:<<MAX>>
TEST.EXPECTED:G5_TwilightToDark.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.twilightToDarkThreshAMB:<<MAX>>
TEST.END

-- Test Case: 04_darkFalseFwdAmbIrTrue.01
TEST.UNIT:G5_TwilightToDark
TEST.SUBPROGRAM:twilightToDark
TEST.NEW
TEST.NAME:04_darkFalseFwdAmbIrTrue.01
TEST.COMPOUND_ONLY
TEST.NOTES:
Twighlight to dark is FALSE and both FW and AMB twighlight threshold FALSE
Test of rw_TwihglightToDarkCounter_g reached twighlight to dark time
- rb_isDarkActive = FALSE -> FALSE

EEPROM:
- rw_TwilightToDarkThreshAMB_g = (EEPROM_Struct_AD.EEPROMStructAD.twilightToDarkThreshAMB * 3) / 3 = (255 * 3) / 3 = 255
- rw_TwilightToDarkThreshFW_g = EEPROM_Struct_AD.EEPROMStructAD.twilightToDarkThreshFW * 3 +  (EEPROM_Struct_AD.EEPROMStructAD.twilightToDarkThreshFW * 3 / 2) = 255 * 3 + (255 * 3 / 2) = 1147
- rw_TwilightToDarkThreshIR_g = EEPROM_Struct_AD.EEPROMStructAD.twilightToDarkThreshIR * 3) / 3 = (255 * 3) / 3 = 255
- rw_TwilightToDarkTime_g = EEPROM_Struct_AD.EEPROMStructAD.twilightToDarkTime * 40 = 255 * 40 = 10200
- rw_DarkToTwilightTime_g = EEPROM_Struct_AD.EEPROMStructAD.darkToTwilightTime * 20 = 255 * 20 = 5100

Light Values:
get_rw_Amb_light16bit_g = 254
get_rw_FW_light16bit_g = 1146
get_rw_IR_light16bit_g = 254
-> all conditions TRUE

-> rw_TwilightToDarkCounter_g += 2 init
-> Test case is compound only and called twice:
-> rw_TwilightToDarkCounter_g = 10197 -> 10199 -> 10201
-> isDarkActive = 0 -> 0


TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.STUB:G5_TwilightToDark.isDarkActive
TEST.VALUE:G5_TwilightToDark.<<GLOBAL>>.rb_darkIsActive:0
TEST.VALUE:G5_TwilightToDark.<<GLOBAL>>.rw_TwilightToDarkCounter_g:10197
TEST.VALUE:G5_TwilightToDark.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.twilightToDarkTime:<<MIN-1>>
TEST.VALUE:G5_TwilightToDark.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.darkToTwilightTime:<<MIN-1>>
TEST.VALUE:G5_TwilightToDark.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.twilightToDarkThreshFW:<<MIN-1>>
TEST.VALUE:G5_TwilightToDark.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.twilightToDarkThreshAMB:<<MIN-1>>
TEST.VALUE:G5_TwilightToDark.isDarkActive.return:0
TEST.VALUE:uut_prototype_stubs.get_rw_Amb_light16bit_g.return:254
TEST.VALUE:uut_prototype_stubs.get_rw_FW_light16bit_g.return:1146
TEST.VALUE:uut_prototype_stubs.get_rw_IR_light16bit_g.return:254
TEST.EXPECTED:G5_TwilightToDark.<<GLOBAL>>.rb_darkIsActive:0
TEST.EXPECTED:G5_TwilightToDark.<<GLOBAL>>.rw_TwilightToDarkCounter_g:10199,10201
TEST.EXPECTED:G5_TwilightToDark.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.twilightToDarkTime:<<MAX>>
TEST.EXPECTED:G5_TwilightToDark.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.darkToTwilightTime:<<MAX>>
TEST.EXPECTED:G5_TwilightToDark.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.twilightToDarkThreshFW:<<MAX>>
TEST.EXPECTED:G5_TwilightToDark.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.twilightToDarkThreshAMB:<<MAX>>
TEST.END

-- Test Case: 04_darkFalseFwdAmbIrTrue.02
TEST.UNIT:G5_TwilightToDark
TEST.SUBPROGRAM:twilightToDark
TEST.NEW
TEST.NAME:04_darkFalseFwdAmbIrTrue.02
TEST.COMPOUND_ONLY
TEST.NOTES:
Twighlight to dark is FALSE and both FW and AMB twighlight threshold FALSE
Test of rw_TwihglightToDarkCounter_g reached twighlight to dark time
- rb_isDarkActive = FALSE -> FALSE

EEPROM:
- rw_TwilightToDarkThreshAMB_g = (EEPROM_Struct_AD.EEPROMStructAD.twilightToDarkThreshAMB * 3) / 3 = (255 * 3) / 3 = 255
- rw_TwilightToDarkThreshFW_g = EEPROM_Struct_AD.EEPROMStructAD.twilightToDarkThreshFW * 3 +  (EEPROM_Struct_AD.EEPROMStructAD.twilightToDarkThreshFW * 3 / 2) = 255 * 3 + (255 * 3 / 2) = 1147
- rw_TwilightToDarkThreshIR_g = EEPROM_Struct_AD.EEPROMStructAD.twilightToDarkThreshIR * 3) / 3 = (255 * 3) / 3 = 255
- rw_TwilightToDarkTime_g = EEPROM_Struct_AD.EEPROMStructAD.twilightToDarkTime * 40 = 255 * 40 = 10200
- rw_DarkToTwilightTime_g = EEPROM_Struct_AD.EEPROMStructAD.darkToTwilightTime * 20 = 255 * 20 = 5100

Light Values:
get_rw_Amb_light16bit_g = 254
get_rw_FW_light16bit_g = 1146
get_rw_IR_light16bit_g = 254
-> all conditions TRUE

-> rw_TwilightToDarkCounter_g += 2 (over limit)
-> Test case is compound only and called twice:
-> rw_TwilightToDarkCounter_g = 10200 -> 0 (reset by setDarkActive)
-> isDarkActive = 0 -> 1


TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.STUB:G5_TwilightToDark.isDarkActive
TEST.VALUE:G5_TwilightToDark.<<GLOBAL>>.rb_darkIsActive:0
TEST.VALUE:G5_TwilightToDark.<<GLOBAL>>.rw_TwilightToDarkCounter_g:10200
TEST.VALUE:G5_TwilightToDark.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.twilightToDarkTime:<<MIN-1>>
TEST.VALUE:G5_TwilightToDark.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.darkToTwilightTime:<<MIN-1>>
TEST.VALUE:G5_TwilightToDark.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.twilightToDarkThreshFW:<<MIN-1>>
TEST.VALUE:G5_TwilightToDark.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.twilightToDarkThreshAMB:<<MIN-1>>
TEST.VALUE:G5_TwilightToDark.isDarkActive.return:1
TEST.VALUE:uut_prototype_stubs.get_rw_Amb_light16bit_g.return:254
TEST.VALUE:uut_prototype_stubs.get_rw_FW_light16bit_g.return:1146
TEST.VALUE:uut_prototype_stubs.get_rw_IR_light16bit_g.return:254
TEST.EXPECTED:G5_TwilightToDark.<<GLOBAL>>.rb_darkIsActive:1
TEST.EXPECTED:G5_TwilightToDark.<<GLOBAL>>.rw_TwilightToDarkCounter_g:0
TEST.EXPECTED:G5_TwilightToDark.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.twilightToDarkTime:<<MAX>>
TEST.EXPECTED:G5_TwilightToDark.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.darkToTwilightTime:<<MAX>>
TEST.EXPECTED:G5_TwilightToDark.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.twilightToDarkThreshFW:<<MAX>>
TEST.EXPECTED:G5_TwilightToDark.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.twilightToDarkThreshAMB:<<MAX>>
TEST.END

-- COMPOUND TESTS

TEST.SUBPROGRAM:<<COMPOUND>>
TEST.NEW
TEST.NAME:01_twilightToDarkCounterTest
TEST.NOTES:
-> 02_twilightToDarkFwAmbTrue.01 called twice:
-> rw_TwilightToDarkCounter_g = 10196 -> 10199
-> isDarkActive = 0 -> 0

-> 02_twilightToDarkFwAmbTrue.02 called once:
-> rw_TwilightToDarkCounter_g = 10199 -> 10202
-> isDarkActive = 0 -> 1
TEST.END_NOTES:
TEST.SLOT: "1", "G5_TwilightToDark", "twilightToDark", "2", "02_darkFalseFwAmbTrue.01"
TEST.SLOT: "2", "G5_TwilightToDark", "twilightToDark", "1", "02_darkFalseFwAmbTrue.02"
TEST.END
--

-- COMPOUND TESTS

TEST.SUBPROGRAM:<<COMPOUND>>
TEST.NEW
TEST.NAME:02_twilightToDarkCounterTest
TEST.NOTES:
-> 02_twilightToDarkFwAmbTrue.01 called twice:
-> rw_TwilightToDarkCounter_g = 10196 -> 10199
-> isDarkActive = 0 -> 0

-> 02_twilightToDarkFwAmbTrue.02 called once:
-> rw_TwilightToDarkCounter_g = 10199 -> 10202
-> isDarkActive = 0 -> 1
TEST.END_NOTES:
TEST.SLOT: "1", "G5_TwilightToDark", "twilightToDark", "2", "04_darkFalseFwdAmbIrTrue.01"
TEST.SLOT: "2", "G5_TwilightToDark", "twilightToDark", "1", "04_darkFalseFwdAmbIrTrue.02"
TEST.END
--

-- COMPOUND TESTS

TEST.SUBPROGRAM:<<COMPOUND>>
TEST.NEW
TEST.NAME:03_darkToTwighlightCounterTest
TEST.NOTES:
05_darkActive called thrice
-> rb_isDarkActive = TRUE, TRUE, FALSE
-> rw_DarkToTwighlightCounter_g = 5098 -> 5099 -> 5100 -> 0
TEST.END_NOTES:
TEST.SLOT: "1", "G5_TwilightToDark", "darkToTwilight", "3", "05_darkAllTrue"
TEST.END
--
