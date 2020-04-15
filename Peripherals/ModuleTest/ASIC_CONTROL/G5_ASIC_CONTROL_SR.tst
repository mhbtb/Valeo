-- VectorCAST 6.2n
-- Test Case Script
-- 
-- Environment    : G5_ASIC_CONTROL_SR
-- Unit(s) Under Test: G5_ASIC_Control_sr
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Unit: G5_ASIC_Control_sr

-- Subprogram: ASIC_Control_ALS1_LightValScl

-- Test Case: ACl_ALS1_LightValScl1
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_ALS1_LightValScl
TEST.NEW
TEST.NAME:ACl_ALS1_LightValScl1
TEST.NOTES:
TestCase1:
Stub ASIC_Control_DelogLightValue and set the return value > 0x8000 (here 40000)
Set rb_filter_l as 0
Set rw_Solar_light16bit_1_g as 0
Check the Global rw_Solar_light16bit_1_g value for 0x7FFF
TEST.END_NOTES:
TEST.STUB:G5_ASIC_Control_sr.ASIC_Control_DelogLightValue
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rw_Solar_light16bit_1_g:0
TEST.VALUE:G5_ASIC_Control_sr.ASIC_Control_ALS1_LightValScl.rb_filter_l:0
TEST.VALUE:G5_ASIC_Control_sr.ASIC_Control_DelogLightValue.return:40000
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rw_Solar_light16bit_1_g:0x7FFF
TEST.END

-- Test Case: ACl_ALS1_LightValScl2
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_ALS1_LightValScl
TEST.NEW
TEST.NAME:ACl_ALS1_LightValScl2
TEST.NOTES:
TestCase2:
Stub ASIC_Control_DelogLightValue and set the return value < 0x8000 (here 500)
Set rb_filter_l as 5
set rw_Solar_light16bit_1_g as zero
Check the Global rw_Solar_light16bit_1_g value for 250
TEST.END_NOTES:
TEST.STUB:G5_ASIC_Control_sr.ASIC_Control_DelogLightValue
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rw_Solar_light16bit_1_g:0
TEST.VALUE:G5_ASIC_Control_sr.ASIC_Control_ALS1_LightValScl.rb_filter_l:5
TEST.VALUE:G5_ASIC_Control_sr.ASIC_Control_DelogLightValue.return:500
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rw_Solar_light16bit_1_g:0xFA
TEST.END

-- Subprogram: ASIC_Control_ALS2_INC_LightValScl

-- Test Case: AC_ALS2_INC_LightValScl1
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_ALS2_INC_LightValScl
TEST.NEW
TEST.NAME:AC_ALS2_INC_LightValScl1
TEST.NOTES:
TestCase1:
Stub the fn ASIC_Control_DelogLightValue and set the return value > 0x8000 (here 40000)
Set rb_filter_l as 0
Set rw_Amb_INC_light16bit_g as 0 (check if unchanged)
check the return value for 0x7FFF
TEST.END_NOTES:
TEST.STUB:G5_ASIC_Control_sr.ASIC_Control_DelogLightValue
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rw_Amb_INC_light16bit_g:0
TEST.VALUE:G5_ASIC_Control_sr.ASIC_Control_ALS2_INC_LightValScl.rb_filter_l:0
TEST.VALUE:G5_ASIC_Control_sr.ASIC_Control_DelogLightValue.return:40000
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rw_Amb_INC_light16bit_g:0
TEST.EXPECTED:G5_ASIC_Control_sr.ASIC_Control_ALS2_INC_LightValScl.return:0x7FFF
TEST.END

-- Test Case: AC_ALS2_INC_LightValScl2
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_ALS2_INC_LightValScl
TEST.NEW
TEST.NAME:AC_ALS2_INC_LightValScl2
TEST.NOTES:
TestCase2:
Stub the fn ASIC_Control_DelogLightValue and set the return value < 0x8000 (here 60)
Set rb_filter_l as 5
Set rw_Amb_INC_light16bit_g as 0 (check if unchanged)
check the return value for 30
TEST.END_NOTES:
TEST.STUB:G5_ASIC_Control_sr.ASIC_Control_DelogLightValue
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rw_Amb_INC_light16bit_g:0
TEST.VALUE:G5_ASIC_Control_sr.ASIC_Control_ALS2_INC_LightValScl.rb_filter_l:5
TEST.VALUE:G5_ASIC_Control_sr.ASIC_Control_DelogLightValue.return:60
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rw_Amb_INC_light16bit_g:0
TEST.EXPECTED:G5_ASIC_Control_sr.ASIC_Control_ALS2_INC_LightValScl.return:30
TEST.END

-- Test Case: AC_ALS2_INC_LightValScl3
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_ALS2_INC_LightValScl
TEST.NEW
TEST.NAME:AC_ALS2_INC_LightValScl3
TEST.NOTES:
TestCase3:
Stub the fn ASIC_Control_DelogLightValue and set the return value < 0x8000 (here 15)
Set rb_filter_l as 5
Set rw_Amb_INC_light16bit_g as 0 (check if unchanged)
check the return value for 14
TEST.END_NOTES:
TEST.STUB:G5_ASIC_Control_sr.ASIC_Control_DelogLightValue
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rw_Amb_INC_light16bit_g:0
TEST.VALUE:G5_ASIC_Control_sr.ASIC_Control_ALS2_INC_LightValScl.rb_filter_l:5
TEST.VALUE:G5_ASIC_Control_sr.ASIC_Control_DelogLightValue.return:15
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rw_Amb_INC_light16bit_g:0
TEST.EXPECTED:G5_ASIC_Control_sr.ASIC_Control_ALS2_INC_LightValScl.return:14
TEST.END

-- Test Case: AC_ALS2_INC_LightValScl4
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_ALS2_INC_LightValScl
TEST.NEW
TEST.NAME:AC_ALS2_INC_LightValScl4
TEST.NOTES:
TestCase4:
Stub the fn ASIC_Control_DelogLightValue and set the return value < 0x8000 (here 3)
Set rb_filter_l as 5
Set rw_Amb_INC_light16bit_g as 0 (check if unchanged)
check the return value for 0
TEST.END_NOTES:
TEST.STUB:G5_ASIC_Control_sr.ASIC_Control_DelogLightValue
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rw_Amb_INC_light16bit_g:0
TEST.VALUE:G5_ASIC_Control_sr.ASIC_Control_ALS2_INC_LightValScl.rb_filter_l:5
TEST.VALUE:G5_ASIC_Control_sr.ASIC_Control_DelogLightValue.return:3
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rw_Amb_INC_light16bit_g:0
TEST.EXPECTED:G5_ASIC_Control_sr.ASIC_Control_ALS2_INC_LightValScl.return:0x0
TEST.END

-- Subprogram: ASIC_Control_ALS2_LightValScl

-- Test Case: AC_ALS2_LightValScl1
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_ALS2_LightValScl
TEST.NEW
TEST.NAME:AC_ALS2_LightValScl1
TEST.NOTES:
TestCase1:
Stub the fn ASIC_Control_DelogLightValue and set the return value as 40000
Set rb_filter_l as 0
Set rw_Amb_light16bit_g as 0
check the global rw_Amb_light16bit_g for the value 0x7FFF
TEST.END_NOTES:
TEST.STUB:G5_ASIC_Control_sr.ASIC_Control_DelogLightValue
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rw_Amb_light16bit_g:0
TEST.VALUE:G5_ASIC_Control_sr.ASIC_Control_ALS2_LightValScl.rb_filter_l:0
TEST.VALUE:G5_ASIC_Control_sr.ASIC_Control_DelogLightValue.return:40000
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rw_Amb_light16bit_g:32767
TEST.END

-- Test Case: AC_ALS2_LightValScl2
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_ALS2_LightValScl
TEST.NEW
TEST.NAME:AC_ALS2_LightValScl2
TEST.NOTES:
TestCase2:
Stub the fn ASIC_Control_DelogLightValue and set the return value as 51
Set rb_filter_l as 1
Set rw_Amb_light16bit_g as 0
check the global rw_Amb_light16bit_g for the value 25
TEST.END_NOTES:
TEST.STUB:G5_ASIC_Control_sr.ASIC_Control_DelogLightValue
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rw_Amb_light16bit_g:0
TEST.VALUE:G5_ASIC_Control_sr.ASIC_Control_ALS2_LightValScl.rb_filter_l:1
TEST.VALUE:G5_ASIC_Control_sr.ASIC_Control_DelogLightValue.return:51
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rw_Amb_light16bit_g:25
TEST.END

-- Test Case: AC_ALS2_LightValScl3
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_ALS2_LightValScl
TEST.NEW
TEST.NAME:AC_ALS2_LightValScl3
TEST.NOTES:
TestCase3:
Stub the fn ASIC_Control_DelogLightValue and set the return value as 25
Set rb_filter_l as 1
Set rw_Amb_light16bit_g as 0
check the global rw_Amb_light16bit_g for the value 14
TEST.END_NOTES:
TEST.STUB:G5_ASIC_Control_sr.ASIC_Control_DelogLightValue
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rw_Amb_light16bit_g:0
TEST.VALUE:G5_ASIC_Control_sr.ASIC_Control_ALS2_LightValScl.rb_filter_l:1
TEST.VALUE:G5_ASIC_Control_sr.ASIC_Control_DelogLightValue.return:15
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rw_Amb_light16bit_g:14
TEST.END

-- Test Case: AC_ALS2_LightValScl4
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_ALS2_LightValScl
TEST.NEW
TEST.NAME:AC_ALS2_LightValScl4
TEST.NOTES:
TestCase4:
Stub the fn ASIC_Control_DelogLightValue and set the return value as 3
Set rb_filter_l as 1
Set rw_Amb_light16bit_g as 100
check the global rw_Amb_light16bit_g for the value 0
TEST.END_NOTES:
TEST.STUB:G5_ASIC_Control_sr.ASIC_Control_DelogLightValue
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rw_Amb_light16bit_g:100
TEST.VALUE:G5_ASIC_Control_sr.ASIC_Control_ALS2_LightValScl.rb_filter_l:1
TEST.VALUE:G5_ASIC_Control_sr.ASIC_Control_DelogLightValue.return:3
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rw_Amb_light16bit_g:0
TEST.END

-- Subprogram: ASIC_Control_ALS5_INC_LightValScl

-- Test Case: AC_ALS5_INC_LightValScl1
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_ALS5_INC_LightValScl
TEST.NEW
TEST.NAME:AC_ALS5_INC_LightValScl1
TEST.NOTES:
TestCase1:
Stub the fn ASIC_Control_DelogLightValue and set the return value > 0x8000 (here 40000)
Set rb_filter_l as 0
Set rw_FW_INC_light16bit_g as 0 (check if unchanged)
check the return value for 0x7FFF
TEST.END_NOTES:
TEST.STUB:G5_ASIC_Control_sr.ASIC_Control_DelogLightValue
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rw_FW_INC_light16bit_g:0
TEST.VALUE:G5_ASIC_Control_sr.ASIC_Control_ALS5_INC_LightValScl.rb_filter_l:0
TEST.VALUE:G5_ASIC_Control_sr.ASIC_Control_DelogLightValue.return:40000
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rw_FW_INC_light16bit_g:0
TEST.EXPECTED:G5_ASIC_Control_sr.ASIC_Control_ALS5_INC_LightValScl.return:0x7FFF
TEST.END

-- Test Case: AC_ALS5_INC_LightValScl2
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_ALS5_INC_LightValScl
TEST.NEW
TEST.NAME:AC_ALS5_INC_LightValScl2
TEST.NOTES:
TestCase2:
Stub the fn ASIC_Control_DelogLightValue and set the return value < 0x8000 (here 500)
Set rb_filter_l as 1
Set rw_FW_INC_light16bit_g as 0 (check if unchanged)
check the return value for 250
TEST.END_NOTES:
TEST.STUB:G5_ASIC_Control_sr.ASIC_Control_DelogLightValue
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rw_FW_INC_light16bit_g:0
TEST.VALUE:G5_ASIC_Control_sr.ASIC_Control_ALS5_INC_LightValScl.rb_filter_l:1
TEST.VALUE:G5_ASIC_Control_sr.ASIC_Control_DelogLightValue.return:500
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rw_FW_INC_light16bit_g:0
TEST.EXPECTED:G5_ASIC_Control_sr.ASIC_Control_ALS5_INC_LightValScl.return:250
TEST.END

-- Test Case: AC_ALS5_INC_LightValScl3
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_ALS5_INC_LightValScl
TEST.NEW
TEST.NAME:AC_ALS5_INC_LightValScl3
TEST.NOTES:
TestCase3:
Stub the fn ASIC_Control_DelogLightValue and set the return value < 0x8000 (here 50)
Set rb_filter_l as 1
Set rw_FW_INC_light16bit_g as 0 (check if unchanged)
check the return value for 49
TEST.END_NOTES:
TEST.STUB:G5_ASIC_Control_sr.ASIC_Control_DelogLightValue
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rw_FW_INC_light16bit_g:0
TEST.VALUE:G5_ASIC_Control_sr.ASIC_Control_ALS5_INC_LightValScl.rb_filter_l:1
TEST.VALUE:G5_ASIC_Control_sr.ASIC_Control_DelogLightValue.return:50
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rw_FW_INC_light16bit_g:0
TEST.EXPECTED:G5_ASIC_Control_sr.ASIC_Control_ALS5_INC_LightValScl.return:49
TEST.END

-- Test Case: AC_ALS5_INC_LightValScl4
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_ALS5_INC_LightValScl
TEST.NEW
TEST.NAME:AC_ALS5_INC_LightValScl4
TEST.NOTES:
TestCase4:
Stub the fn ASIC_Control_DelogLightValue and set the return value < 0x8000 (here 5)
Set rb_filter_l as 1
Set rw_FW_INC_light16bit_g as 0 (check if unchanged)
check the return value for 0
TEST.END_NOTES:
TEST.STUB:G5_ASIC_Control_sr.ASIC_Control_DelogLightValue
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rw_FW_INC_light16bit_g:0
TEST.VALUE:G5_ASIC_Control_sr.ASIC_Control_ALS5_INC_LightValScl.rb_filter_l:1
TEST.VALUE:G5_ASIC_Control_sr.ASIC_Control_DelogLightValue.return:5
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rw_FW_INC_light16bit_g:0
TEST.EXPECTED:G5_ASIC_Control_sr.ASIC_Control_ALS5_INC_LightValScl.return:0x0
TEST.END

-- Subprogram: ASIC_Control_ALS5_LightValScl

-- Test Case: AControl_ALS5_LightValScl1
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_ALS5_LightValScl
TEST.NEW
TEST.NAME:AControl_ALS5_LightValScl1
TEST.NOTES:
TestCase1:
Stub the fn ASIC_Control_DelogLightValue and set the return value > 0x8000 (here 40000)
Set rb_filter_l as 0
Set rw_FW_light16bit_g as 0
check the global rw_FW_light16bit_g for the value 0x7FFF
TEST.END_NOTES:
TEST.STUB:G5_ASIC_Control_sr.ASIC_Control_DelogLightValue
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rw_FW_light16bit_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_FwLight_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_FwLightDiv4_g:0
TEST.VALUE:G5_ASIC_Control_sr.ASIC_Control_ALS5_LightValScl.rb_filter_l:0
TEST.VALUE:G5_ASIC_Control_sr.ASIC_Control_DelogLightValue.return:40000
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rw_FW_light16bit_g:0x7FFF
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_FwLight_g:255
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_FwLightDiv4_g:255
TEST.END

-- Test Case: AControl_ALS5_LightValScl2
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_ALS5_LightValScl
TEST.NEW
TEST.NAME:AControl_ALS5_LightValScl2
TEST.NOTES:
TestCase2:
Stub the fn ASIC_Control_DelogLightValue and set the return value < 0x8000 (here 500)
Set rb_filter_l as 1
Set rw_FW_light16bit_g as 0
check the global rw_FW_light16bit_g for the value 250
TEST.END_NOTES:
TEST.STUB:G5_ASIC_Control_sr.ASIC_Control_DelogLightValue
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rw_FW_light16bit_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_FwLight_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_FwLightDiv4_g:0
TEST.VALUE:G5_ASIC_Control_sr.ASIC_Control_ALS5_LightValScl.rb_filter_l:1
TEST.VALUE:G5_ASIC_Control_sr.ASIC_Control_DelogLightValue.return:500
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rw_FW_light16bit_g:250
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_FwLight_g:250
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_FwLightDiv4_g:62
TEST.END

-- Test Case: AControl_ALS5_LightValScl3
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_ALS5_LightValScl
TEST.NEW
TEST.NAME:AControl_ALS5_LightValScl3
TEST.NOTES:
TestCase3:
Stub the fn ASIC_Control_DelogLightValue and set the return value < 0x8000 (here 50)
Set rb_filter_l as 1
Set rw_FW_light16bit_g as 0
check the global rw_FW_light16bit_g for the value 49
TEST.END_NOTES:
TEST.STUB:G5_ASIC_Control_sr.ASIC_Control_DelogLightValue
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rw_FW_light16bit_g:0
TEST.VALUE:G5_ASIC_Control_sr.ASIC_Control_ALS5_LightValScl.rb_filter_l:1
TEST.VALUE:G5_ASIC_Control_sr.ASIC_Control_DelogLightValue.return:50
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rw_FW_light16bit_g:49
TEST.END

-- Test Case: AControl_ALS5_LightValScl4
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_ALS5_LightValScl
TEST.NEW
TEST.NAME:AControl_ALS5_LightValScl4
TEST.NOTES:
TestCase4:
Stub the fn ASIC_Control_DelogLightValue and set the return value < 0x8000 (here 7)
Set rb_filter_l as 1
Set rw_FW_light16bit_g as 0
check the global rw_FW_light16bit_g for the value 0
TEST.END_NOTES:
TEST.STUB:G5_ASIC_Control_sr.ASIC_Control_DelogLightValue
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rw_FW_light16bit_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_FwLight_g:100
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_FwLightDiv4_g:100
TEST.VALUE:G5_ASIC_Control_sr.ASIC_Control_ALS5_LightValScl.rb_filter_l:1
TEST.VALUE:G5_ASIC_Control_sr.ASIC_Control_DelogLightValue.return:7
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rw_FW_light16bit_g:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_FwLight_g:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_FwLightDiv4_g:0
TEST.END

-- Test Case: AControl_ALS5_LightValScl5
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_ALS5_LightValScl
TEST.NEW
TEST.NAME:AControl_ALS5_LightValScl5
TEST.NOTES:
TestCase5:
Stub the fn ASIC_Control_DelogLightValue and set the return value < 0x8000 (here 300)
Set rb_filter_l as 0
Set rw_FW_light16bit_g as 0
check the global rw_FW_light16bit_g for the value 300
TEST.END_NOTES:
TEST.STUB:G5_ASIC_Control_sr.ASIC_Control_DelogLightValue
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rw_FW_light16bit_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_FwLight_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_FwLightDiv4_g:0
TEST.VALUE:G5_ASIC_Control_sr.ASIC_Control_ALS5_LightValScl.rb_filter_l:0
TEST.VALUE:G5_ASIC_Control_sr.ASIC_Control_DelogLightValue.return:300
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rw_FW_light16bit_g:300
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_FwLight_g:0xFF
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_FwLightDiv4_g:75
TEST.END

-- Subprogram: ASIC_Control_ALS6_LightValScl

-- Test Case: ACl_ALS6_LightValScl1
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_ALS6_LightValScl
TEST.NEW
TEST.NAME:ACl_ALS6_LightValScl1
TEST.NOTES:
TestCase1:
Stub ASIC_Control_DelogLightValue and set the return value > 0x8000 (here 40000)
Set rb_filter_l as 0
Set rw_Solar_light16bit_2_g as 0
Check the Global rw_Solar_light16bit_2_g value for 0x7FFF
TEST.END_NOTES:
TEST.STUB:G5_ASIC_Control_sr.ASIC_Control_DelogLightValue
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rw_Solar_light16bit_2_g:0
TEST.VALUE:G5_ASIC_Control_sr.ASIC_Control_ALS6_LightValScl.rb_filter_l:0
TEST.VALUE:G5_ASIC_Control_sr.ASIC_Control_DelogLightValue.return:40000
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rw_Solar_light16bit_2_g:0x7FFF
TEST.END

-- Test Case: ACl_ALS6_LightValScl2
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_ALS6_LightValScl
TEST.NEW
TEST.NAME:ACl_ALS6_LightValScl2
TEST.NOTES:
TestCase2:
Stub ASIC_Control_DelogLightValue and set the return value < 0x8000 (here 500)
Set rb_filter_l as 5
Set rw_Solar_light16bit_2_g as 0
Check the Global rw_Solar_light16bit_2_g value for 250
TEST.END_NOTES:
TEST.STUB:G5_ASIC_Control_sr.ASIC_Control_DelogLightValue
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rw_Solar_light16bit_2_g:0
TEST.VALUE:G5_ASIC_Control_sr.ASIC_Control_ALS6_LightValScl.rb_filter_l:5
TEST.VALUE:G5_ASIC_Control_sr.ASIC_Control_DelogLightValue.return:500
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rw_Solar_light16bit_2_g:250
TEST.END

-- Subprogram: ASIC_Control_ALSxINCShortDetect

-- Test Case: AC_ALSxINCShortDetect.ALS2.1
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_ALSxINCShortDetect
TEST.NEW
TEST.NAME:AC_ALSxINCShortDetect.ALS2.1
TEST.NOTES:
TestCase1:
Set rb_ASIC_ALSx_INC_Ready_g to 0x1
Stub ASIC_Control_ALS2_INC_LightValScl and set the return value to input parameter rw_temp_ALS2_INC_ASIC_l
Set ADC value ras_ASIC_ALSxADval_g[1].avg to 300
Set ADC value ras_ASIC_ALSxADval_g[1].avginc to 200
Check the Global rw_Amb_INC_light16bit_g value has changed to 200
Check the Global rw_Amb_INC_light16bit_thrs_g value has changed to 350
Check if the Global rb_ASIC_ALSx_ShortDetected_cnt_g has been increased by 3
Check if the Global rb_ASIC_ALSx_ShortDetected_Max_cnt_g is equal to rb_ASIC_ALSx_ShortDetected_cnt_g
Check if the Global rb_ASIC_ALSx_ShortDetected_Error_g has not been changed
Check if the Global uF_ASIC_Error_Flags_g.Bit.B0 has not been set
Check if rb_ASIC_ALSx_INC_Ready_g has been reset to 0
TEST.END_NOTES:
TEST.STUB:G5_ASIC_Control_sr.ASIC_Control_ALS2_INC_LightValScl
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:FALSE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rw_Amb_INC_light16bit_g:7
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALSxADval_g[1].avg:300
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALSxADval_g[1].avginc:200
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rw_Amb_INC_light16bit_thrs_g:7
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ALSx_ShortDetected_cnt_g:7
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ALSx_ShortDetected_Max_cnt_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ALSx_ShortDetected_Error_g:7
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_Error_Flags_g.Bit.B0:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ALSx_INC_Ready_g:0x1
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rw_Amb_INC_light16bit_g:200
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rw_Amb_INC_light16bit_thrs_g:350
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ALSx_ShortDetected_cnt_g:10
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ALSx_ShortDetected_Max_cnt_g:10
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ALSx_ShortDetected_Error_g:7
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_Error_Flags_g.Bit.B0:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ALSx_INC_Ready_g:0
TEST.VALUE_USER_CODE:<<testcase>>
ASIC_Control_ALSxINCShortDetect();
rb_ASIC_ALSx_INC_Ready_g = 0x1;
ASIC_Control_ALSxINCShortDetect();
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: AC_ALSxINCShortDetect.ALS2.2
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_ALSxINCShortDetect
TEST.NEW
TEST.NAME:AC_ALSxINCShortDetect.ALS2.2
TEST.NOTES:
TestCase2:
Testcase User Code required!
Set rb_ASIC_ALSx_INC_Ready_g to 0x1
Stub ASIC_Control_ALS2_INC_LightValScl and set the return value to input parameter rw_temp_ALS2_INC_ASIC_l
Set ADC value ras_ASIC_ALSxADval_g[1].avg to 300
Set ADC value ras_ASIC_ALSxADval_g[1].avginc to 200
Set rb_ASIC_ALSx_ShortDetected_cnt_g to cb_ASIC_ALSx_SHORTDET_THS_g-1 (here 59)
Check the Global rw_Amb_INC_light16bit_g value has changed to 200
Check the Global rw_Amb_INC_light16bit_thrs_g value has changed to 350
Check if the Global rb_ASIC_ALSx_ShortDetected_cnt_g has been set to cb_ASIC_ALSx_SHORTDET_THS_g
Check if the Global rb_ASIC_ALSx_ShortDetected_Max_cnt_g is equal to rb_ASIC_ALSx_ShortDetected_cnt_g
Check if the Global rb_ASIC_ALSx_ShortDetected_Error_g has been set to 1 (TRUE)
Check if the Global uF_ASIC_Error_Flags_g.Bit.B0 has been set
Check if rb_ASIC_ALSx_INC_Ready_g has been reset to 0
TEST.END_NOTES:
TEST.STUB:G5_ASIC_Control_sr.ASIC_Control_ALS2_INC_LightValScl
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rw_Amb_INC_light16bit_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALSxADval_g[1].avg:300
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALSxADval_g[1].avginc:200
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rw_Amb_INC_light16bit_thrs_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ALSx_ShortDetected_cnt_g:59
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ALSx_ShortDetected_Max_cnt_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ALSx_ShortDetected_Error_g:7
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_Error_Flags_g.Bit.B0:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ALSx_INC_Ready_g:0x1
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rw_Amb_INC_light16bit_g:200
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rw_Amb_INC_light16bit_thrs_g:350
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ALSx_ShortDetected_cnt_g:60
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ALSx_ShortDetected_Max_cnt_g:60
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ALSx_ShortDetected_Error_g:1
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_Error_Flags_g.Bit.B0:1
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ALSx_INC_Ready_g:0
TEST.VALUE_USER_CODE:<<testcase>>
ASIC_Control_ALSxINCShortDetect();
rb_ASIC_ALSx_INC_Ready_g = 0x1;

TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: AC_ALSxINCShortDetect.ALS2.3
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_ALSxINCShortDetect
TEST.NEW
TEST.NAME:AC_ALSxINCShortDetect.ALS2.3
TEST.NOTES:
TestCase3:
Set rb_ASIC_ALSx_INC_Ready_g to 0x1
Stub ASIC_Control_ALS2_INC_LightValScl and set the return value to input parameter rw_temp_ALS2_INC_ASIC_l
Set ADC value ras_ASIC_ALSxADval_g[1].avg to 300
Set ADC value ras_ASIC_ALSxADval_g[1].avginc to 344
Check the Global rw_Amb_INC_light16bit_g value has changed to 344
Check the Global rw_Amb_INC_light16bit_thrs_g value has changed to 350
Check if the Global rb_ASIC_ALSx_ShortDetected_cnt_g has been decreased by 1
Check if the Global rb_ASIC_ALSx_ShortDetected_Max_cnt_g is equal to rb_ASIC_ALSx_ShortDetected_cnt_g
Check if the Global rb_ASIC_ALSx_ShortDetected_Error_g has not been changed
Check if the Global uF_ASIC_Error_Flags_g.Bit.B0 has not been set
Check if rb_ASIC_ALSx_INC_Ready_g has been reset to 0
TEST.END_NOTES:
TEST.STUB:G5_ASIC_Control_sr.ASIC_Control_ALS2_INC_LightValScl
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rw_Amb_INC_light16bit_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALSxADval_g[1].avg:300
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALSxADval_g[1].avginc:344
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rw_Amb_INC_light16bit_thrs_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ALSx_ShortDetected_cnt_g:7
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ALSx_ShortDetected_Max_cnt_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ALSx_ShortDetected_Error_g:7
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_Error_Flags_g.Bit.B0:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ALSx_INC_Ready_g:0x1
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rw_Amb_INC_light16bit_g:344
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rw_Amb_INC_light16bit_thrs_g:350
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ALSx_ShortDetected_cnt_g:6
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ALSx_ShortDetected_Max_cnt_g:6
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ALSx_ShortDetected_Error_g:7
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_Error_Flags_g.Bit.B0:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ALSx_INC_Ready_g:0
TEST.END

-- Test Case: AC_ALSxINCShortDetect.ALS2.4
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_ALSxINCShortDetect
TEST.NEW
TEST.NAME:AC_ALSxINCShortDetect.ALS2.4
TEST.NOTES:
TestCase4:
Set rb_ASIC_ALSx_INC_Ready_g to 0x1
Stub ASIC_Control_ALS2_INC_LightValScl and set the return value to input parameter rw_temp_ALS2_INC_ASIC_l
Set ADC value ras_ASIC_ALSxADval_g[1].avg to 240
Set ADC value ras_ASIC_ALSxADval_g[1].avginc to 344
Check the Global rw_Amb_INC_light16bit_g value has changed to 344
Check the Global rw_Amb_INC_light16bit_thrs_g value has changed to 0
Check if the Global rb_ASIC_ALSx_ShortDetected_cnt_g has been decreased by 1
Check if the Global rb_ASIC_ALSx_ShortDetected_Max_cnt_g is equal to rb_ASIC_ALSx_ShortDetected_cnt_g
Check if the Global rb_ASIC_ALSx_ShortDetected_Error_g has not been changed
Check if the Global uF_ASIC_Error_Flags_g.Bit.B0 has not been set
Check if rb_ASIC_ALSx_INC_Ready_g has been reset to 0
TEST.END_NOTES:
TEST.STUB:G5_ASIC_Control_sr.ASIC_Control_ALS2_INC_LightValScl
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rw_Amb_INC_light16bit_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALSxADval_g[1].avg:240
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALSxADval_g[1].avginc:344
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rw_Amb_INC_light16bit_thrs_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ALSx_ShortDetected_cnt_g:7
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ALSx_ShortDetected_Max_cnt_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ALSx_ShortDetected_Error_g:7
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_Error_Flags_g.Bit.B0:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ALSx_INC_Ready_g:0x1
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rw_Amb_INC_light16bit_g:344
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rw_Amb_INC_light16bit_thrs_g:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ALSx_ShortDetected_cnt_g:6
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ALSx_ShortDetected_Max_cnt_g:6
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ALSx_ShortDetected_Error_g:7
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_Error_Flags_g.Bit.B0:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ALSx_INC_Ready_g:0
TEST.END

-- Test Case: AC_ALSxINCShortDetect.ALS2.5
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_ALSxINCShortDetect
TEST.NEW
TEST.NAME:AC_ALSxINCShortDetect.ALS2.5
TEST.NOTES:
TestCase5:
Set rb_ASIC_ALSx_INC_Ready_g to 0x1
Stub ASIC_Control_ALS2_INC_LightValScl and set the return value to input parameter rw_temp_ALS2_INC_ASIC_l
Set ADC value ras_ASIC_ALSxADval_g[1].avg to 240
Set ADC value ras_ASIC_ALSxADval_g[1].avginc to 344
Check the Global rw_Amb_INC_light16bit_g value has changed to 344
Check the Global rw_Amb_INC_light16bit_thrs_g value has changed to 0
Check if the Global rb_ASIC_ALSx_ShortDetected_cnt_g remains 0
Check if the Global rb_ASIC_ALSx_ShortDetected_Max_cnt_g is equal to rb_ASIC_ALSx_ShortDetected_cnt_g
Check if the Global rb_ASIC_ALSx_ShortDetected_Error_g has been set to 0
Check if the Global uF_ASIC_Error_Flags_g.Bit.B0 has not been set
Check if rb_ASIC_ALSx_INC_Ready_g has been reset to 0
TEST.END_NOTES:
TEST.STUB:G5_ASIC_Control_sr.ASIC_Control_ALS2_INC_LightValScl
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rw_Amb_INC_light16bit_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALSxADval_g[1].avg:240
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALSxADval_g[1].avginc:344
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rw_Amb_INC_light16bit_thrs_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ALSx_ShortDetected_cnt_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ALSx_ShortDetected_Max_cnt_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ALSx_ShortDetected_Error_g:7
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_Error_Flags_g.Bit.B0:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ALSx_INC_Ready_g:0x1
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rw_Amb_INC_light16bit_g:344
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rw_Amb_INC_light16bit_thrs_g:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ALSx_ShortDetected_cnt_g:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ALSx_ShortDetected_Max_cnt_g:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ALSx_ShortDetected_Error_g:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_Error_Flags_g.Bit.B0:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ALSx_INC_Ready_g:0
TEST.END

-- Test Case: AC_ALSxINCShortDetect.ALS5.1
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_ALSxINCShortDetect
TEST.NEW
TEST.NAME:AC_ALSxINCShortDetect.ALS5.1
TEST.NOTES:
TestCase1:
Set rb_ASIC_ALSx_INC_Ready_g to 0x4
Stub ASIC_Control_ALS5_INC_LightValScl and set the return value to input parameter rw_temp_ALS5_INC_ASIC_l
Set ADC value ras_ASIC_ALSxADval_g[4].avg to 300
Set ADC value ras_ASIC_ALSxADval_g[4].avginc to 200
Check the Global rw_FW_INC_light16bit_g value has changed to 200
Check the Global rw_FW_INC_light16bit_thrs_g value has changed to 350
Check if the Global rb_ASIC_ALSx_ShortDetected_cnt_g has been increased by 3
Check if the Global rb_ASIC_ALSx_ShortDetected_Max_cnt_g is equal to rb_ASIC_ALSx_ShortDetected_cnt_g
Check if the Global rb_ASIC_ALSx_ShortDetected_Error_g has not been changed
Check if the Global uF_ASIC_Error_Flags_g.Bit.B1 has not been set
Check if rb_ASIC_ALSx_INC_Ready_g has been reset to 0
TEST.END_NOTES:
TEST.STUB:G5_ASIC_Control_sr.ASIC_Control_ALS5_INC_LightValScl
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:FALSE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rw_FW_INC_light16bit_g:7
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALSxADval_g[4].avg:300
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALSxADval_g[4].avginc:200
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rw_FW_INC_light16bit_thrs_g:7
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ALSx_ShortDetected_cnt_g:7
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ALSx_ShortDetected_Max_cnt_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ALSx_ShortDetected_Error_g:7
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_Error_Flags_g.Bit.B1:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ALSx_INC_Ready_g:0x4
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rw_FW_INC_light16bit_g:200
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rw_FW_INC_light16bit_thrs_g:350
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ALSx_ShortDetected_cnt_g:10
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ALSx_ShortDetected_Max_cnt_g:10
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ALSx_ShortDetected_Error_g:7
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_Error_Flags_g.Bit.B1:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ALSx_INC_Ready_g:0
TEST.VALUE_USER_CODE:<<testcase>>
ASIC_Control_ALSxINCShortDetect();
rb_ASIC_ALSx_INC_Ready_g = 0x4;
ASIC_Control_ALSxINCShortDetect();
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: AC_ALSxINCShortDetect.ALS5.2
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_ALSxINCShortDetect
TEST.NEW
TEST.NAME:AC_ALSxINCShortDetect.ALS5.2
TEST.NOTES:
TestCase2:
Testcase User Code required!
Set rb_ASIC_ALSx_INC_Ready_g to 0x4
Stub ASIC_Control_ALS5_INC_LightValScl and set the return value to input parameter rw_temp_ALS5_INC_ASIC_l
Set ADC value ras_ASIC_ALSxADval_g[4].avg to 300
Set ADC value ras_ASIC_ALSxADval_g[4].avginc to 200
Set rb_ASIC_ALSx_ShortDetected_cnt_g to cb_ASIC_ALSx_SHORTDET_THS_g-1 (here 59)
Check the Global rw_FW_INC_light16bit_g value has changed to 200
Check the Global rw_FW_INC_light16bit_thrs_g value has changed to 350
Check if the Global rb_ASIC_ALSx_ShortDetected_cnt_g has been set to cb_ASIC_ALSx_SHORTDET_THS_g
Check if the Global rb_ASIC_ALSx_ShortDetected_Max_cnt_g is equal to rb_ASIC_ALSx_ShortDetected_cnt_g
Check if the Global rb_ASIC_ALSx_ShortDetected_Error_g has been set to 1 (TRUE)
Check if the Global uF_ASIC_Error_Flags_g.Bit.B1 has been set
Check if rb_ASIC_ALSx_INC_Ready_g has been reset to 0
TEST.END_NOTES:
TEST.STUB:G5_ASIC_Control_sr.ASIC_Control_ALS5_INC_LightValScl
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rw_FW_INC_light16bit_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALSxADval_g[4].avg:300
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALSxADval_g[4].avginc:200
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rw_FW_INC_light16bit_thrs_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ALSx_ShortDetected_cnt_g:59
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ALSx_ShortDetected_Max_cnt_g:59
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ALSx_ShortDetected_Error_g:7
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_Error_Flags_g.Bit.B1:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ALSx_INC_Ready_g:0x4
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rw_FW_INC_light16bit_g:200
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rw_FW_INC_light16bit_thrs_g:350
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ALSx_ShortDetected_cnt_g:60
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ALSx_ShortDetected_Max_cnt_g:60
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ALSx_ShortDetected_Error_g:1
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_Error_Flags_g.Bit.B1:1
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ALSx_INC_Ready_g:0
TEST.VALUE_USER_CODE:<<testcase>>
ASIC_Control_ALSxINCShortDetect();
rb_ASIC_ALSx_INC_Ready_g = 0x4;

TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: AC_ALSxINCShortDetect.ALS5.3
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_ALSxINCShortDetect
TEST.NEW
TEST.NAME:AC_ALSxINCShortDetect.ALS5.3
TEST.NOTES:
TestCase3:
Set rb_ASIC_ALSx_INC_Ready_g to 0x4
Stub ASIC_Control_ALS5_INC_LightValScl and set the return value to input parameter rw_temp_ALS5_INC_ASIC_l
Set ADC value ras_ASIC_ALSxADval_g[4].avg to 300
Set ADC value ras_ASIC_ALSxADval_g[4].avginc to 344
Check the Global rw_FW_INC_light16bit_g value has changed to 344
Check the Global rw_FW_INC_light16bit_thrs_g value has changed to 350
Check if the Global rb_ASIC_ALSx_ShortDetected_cnt_g has been decreased by 1
Check if the Global rb_ASIC_ALSx_ShortDetected_Max_cnt_g is equal to rb_ASIC_ALSx_ShortDetected_cnt_g
Check if the Global rb_ASIC_ALSx_ShortDetected_Error_g has not been changed
Check if the Global uF_ASIC_Error_Flags_g.Bit.B1 has not been set
Check if rb_ASIC_ALSx_INC_Ready_g has been reset to 0
TEST.END_NOTES:
TEST.STUB:G5_ASIC_Control_sr.ASIC_Control_ALS5_INC_LightValScl
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rw_FW_INC_light16bit_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALSxADval_g[4].avg:300
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALSxADval_g[4].avginc:344
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rw_FW_INC_light16bit_thrs_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ALSx_ShortDetected_cnt_g:7
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ALSx_ShortDetected_Max_cnt_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ALSx_ShortDetected_Error_g:7
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_Error_Flags_g.Bit.B1:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ALSx_INC_Ready_g:0x4
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rw_FW_INC_light16bit_g:344
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rw_FW_INC_light16bit_thrs_g:350
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ALSx_ShortDetected_cnt_g:6
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ALSx_ShortDetected_Max_cnt_g:6
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ALSx_ShortDetected_Error_g:7
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_Error_Flags_g.Bit.B1:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ALSx_INC_Ready_g:0
TEST.END

-- Test Case: AC_ALSxINCShortDetect.ALS5.4
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_ALSxINCShortDetect
TEST.NEW
TEST.NAME:AC_ALSxINCShortDetect.ALS5.4
TEST.NOTES:
TestCase4:
Set rb_ASIC_ALSx_INC_Ready_g to 0x4
Stub ASIC_Control_ALS5_INC_LightValScl and set the return value to input parameter rw_temp_ALS5_INC_ASIC_l
Set ADC value ras_ASIC_ALSxADval_g[4].avg to 240
Set ADC value ras_ASIC_ALSxADval_g[4].avginc to 344
Check the Global rw_FW_INC_light16bit_g value has changed to 344
Check the Global rw_FW_INC_light16bit_thrs_g value has changed to 0
Check if the Global rb_ASIC_ALSx_ShortDetected_cnt_g has been decreased by 1
Check if the Global rb_ASIC_ALSx_ShortDetected_Max_cnt_g is equal to rb_ASIC_ALSx_ShortDetected_cnt_g
Check if the Global rb_ASIC_ALSx_ShortDetected_Error_g has not been changed
Check if the Global uF_ASIC_Error_Flags_g.Bit.B1 has not been set
Check if rb_ASIC_ALSx_INC_Ready_g has been reset to 0
TEST.END_NOTES:
TEST.STUB:G5_ASIC_Control_sr.ASIC_Control_ALS5_INC_LightValScl
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rw_FW_INC_light16bit_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALSxADval_g[4].avg:240
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALSxADval_g[4].avginc:344
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rw_FW_INC_light16bit_thrs_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ALSx_ShortDetected_cnt_g:7
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ALSx_ShortDetected_Max_cnt_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ALSx_ShortDetected_Error_g:7
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_Error_Flags_g.Bit.B1:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ALSx_INC_Ready_g:0x4
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rw_FW_INC_light16bit_g:344
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rw_FW_INC_light16bit_thrs_g:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ALSx_ShortDetected_cnt_g:6
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ALSx_ShortDetected_Max_cnt_g:6
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ALSx_ShortDetected_Error_g:7
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_Error_Flags_g.Bit.B1:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ALSx_INC_Ready_g:0
TEST.END

-- Test Case: AC_ALSxINCShortDetect.ALS5.5
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_ALSxINCShortDetect
TEST.NEW
TEST.NAME:AC_ALSxINCShortDetect.ALS5.5
TEST.NOTES:
TestCase5:
Set rb_ASIC_ALSx_INC_Ready_g to 0x4
Stub ASIC_Control_ALS5_INC_LightValScl and set the return value to input parameter rw_temp_ALS5_INC_ASIC_l
Set ADC value ras_ASIC_ALSxADval_g[4].avg to 240
Set ADC value ras_ASIC_ALSxADval_g[4].avginc to 344
Check the Global rw_FW_INC_light16bit_g value has changed to 344
Check the Global rw_FW_INC_light16bit_thrs_g value has changed to 0
Check if the Global rb_ASIC_ALSx_ShortDetected_cnt_g remains 0
Check if the Global rb_ASIC_ALSx_ShortDetected_Max_cnt_g is equal to rb_ASIC_ALSx_ShortDetected_cnt_g
Check if the Global rb_ASIC_ALSx_ShortDetected_Error_g has been set to 0
Check if the Global uF_ASIC_Error_Flags_g.Bit.B1 has not been set
Check if rb_ASIC_ALSx_INC_Ready_g has been reset to 0
TEST.END_NOTES:
TEST.STUB:G5_ASIC_Control_sr.ASIC_Control_ALS5_INC_LightValScl
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rw_FW_INC_light16bit_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALSxADval_g[4].avg:240
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALSxADval_g[4].avginc:344
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rw_FW_INC_light16bit_thrs_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ALSx_ShortDetected_cnt_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ALSx_ShortDetected_Max_cnt_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ALSx_ShortDetected_Error_g:7
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_Error_Flags_g.Bit.B1:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ALSx_INC_Ready_g:0x4
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rw_FW_INC_light16bit_g:344
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rw_FW_INC_light16bit_thrs_g:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ALSx_ShortDetected_cnt_g:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ALSx_ShortDetected_Max_cnt_g:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ALSx_ShortDetected_Error_g:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_Error_Flags_g.Bit.B1:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ALSx_INC_Ready_g:0
TEST.END

-- Test Case: AC_ALSxINCShortDetect.INREC.1
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_ALSxINCShortDetect
TEST.NEW
TEST.NAME:AC_ALSxINCShortDetect.INREC.1
TEST.NOTES:
TestCase1:
Set rb_ASIC_ALSx_INC_Ready_g to 0x8
Stub ASIC_Control_INREC_INC_LightValScl and set the return value to input parameter rw_temp_INREC_INC_ASIC_l
Set ADC value ras_ASIC_ALSxADval_g[6].avg to 300
Set ADC value ras_ASIC_ALSxADval_g[6].avginc to 200
Check the Global rw_IR_INC_light16bit_g value has changed to 200
Check the Global rw_IR_INC_light16bit_thrs_g value has changed to 350
Check if the Global rb_ASIC_ALSx_ShortDetected_cnt_g has been increased by 3
Check if the Global rb_ASIC_ALSx_ShortDetected_Max_cnt_g is equal to rb_ASIC_ALSx_ShortDetected_cnt_g
Check if the Global rb_ASIC_ALSx_ShortDetected_Error_g has not been changed
Check if the Global uF_ASIC_Error_Flags_g.Bit.B2 has not been set
Check if rb_ASIC_ALSx_INC_Ready_g has been reset to 0
TEST.END_NOTES:
TEST.STUB:G5_ASIC_Control_sr.ASIC_Control_INREC_INC_LightValScl
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:FALSE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rw_IR_INC_light16bit_g:7
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALSxADval_g[6].avg:300
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALSxADval_g[6].avginc:200
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rw_IR_INC_light16bit_thrs_g:7
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ALSx_ShortDetected_cnt_g:7
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ALSx_ShortDetected_Max_cnt_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ALSx_ShortDetected_Error_g:7
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_Error_Flags_g.Bit.B2:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ALSx_INC_Ready_g:0x8
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rw_IR_INC_light16bit_g:200
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rw_IR_INC_light16bit_thrs_g:350
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ALSx_ShortDetected_cnt_g:10
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ALSx_ShortDetected_Max_cnt_g:10
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ALSx_ShortDetected_Error_g:7
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_Error_Flags_g.Bit.B2:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ALSx_INC_Ready_g:0
TEST.VALUE_USER_CODE:<<testcase>>
ASIC_Control_ALSxINCShortDetect();
rb_ASIC_ALSx_INC_Ready_g = 0x8;
ASIC_Control_ALSxINCShortDetect();
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: AC_ALSxINCShortDetect.INREC.2
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_ALSxINCShortDetect
TEST.NEW
TEST.NAME:AC_ALSxINCShortDetect.INREC.2
TEST.NOTES:
TestCase2:
Testcase User Code required!
Set rb_ASIC_ALSx_INC_Ready_g to 0x8
Stub ASIC_Control_INREC_INC_LightValScl and set the return value to input parameter rw_temp_INREC_INC_ASIC_l
Set ADC value ras_ASIC_ALSxADval_g[6].avg to 300
Set ADC value ras_ASIC_ALSxADval_g[6].avginc to 200
Set rb_ASIC_ALSx_ShortDetected_cnt_g to cb_ASIC_ALSx_SHORTDET_THS_g-1 (here 59)
Check the Global rw_IR_INC_light16bit_g value has changed to 200
Check the Global rw_IR_INC_light16bit_thrs_g value has changed to 350
Check if the Global rb_ASIC_ALSx_ShortDetected_cnt_g has been set to cb_ASIC_ALSx_SHORTDET_THS_g
Check if the Global rb_ASIC_ALSx_ShortDetected_Max_cnt_g is equal to rb_ASIC_ALSx_ShortDetected_cnt_g
Check if the Global rb_ASIC_ALSx_ShortDetected_Error_g has been set to 1 (TRUE)
Check if the Global uF_ASIC_Error_Flags_g.Bit.B2 has been set
Check if rb_ASIC_ALSx_INC_Ready_g has been reset to 0
TEST.END_NOTES:
TEST.STUB:G5_ASIC_Control_sr.ASIC_Control_INREC_INC_LightValScl
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rw_IR_INC_light16bit_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALSxADval_g[6].avg:300
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALSxADval_g[6].avginc:200
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rw_IR_INC_light16bit_thrs_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ALSx_ShortDetected_cnt_g:59
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ALSx_ShortDetected_Max_cnt_g:59
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ALSx_ShortDetected_Error_g:7
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_Error_Flags_g.Bit.B2:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ALSx_INC_Ready_g:0x8
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rw_IR_INC_light16bit_g:200
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rw_IR_INC_light16bit_thrs_g:350
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ALSx_ShortDetected_cnt_g:60
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ALSx_ShortDetected_Max_cnt_g:60
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ALSx_ShortDetected_Error_g:1
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_Error_Flags_g.Bit.B2:1
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ALSx_INC_Ready_g:0
TEST.VALUE_USER_CODE:<<testcase>>
ASIC_Control_ALSxINCShortDetect();
rb_ASIC_ALSx_INC_Ready_g = 0x8;

TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: AC_ALSxINCShortDetect.INREC.3
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_ALSxINCShortDetect
TEST.NEW
TEST.NAME:AC_ALSxINCShortDetect.INREC.3
TEST.NOTES:
TestCase3:
Set rb_ASIC_ALSx_INC_Ready_g to 0x8
Stub ASIC_Control_INREC_INC_LightValScl and set the return value to input parameter rw_temp_INREC_INC_ASIC_l
Set ADC value ras_ASIC_ALSxADval_g[6].avg to 300
Set ADC value ras_ASIC_ALSxADval_g[6].avginc to 344
Check the Global rw_IR_INC_light16bit_g value has changed to 344
Check the Global rw_IR_INC_light16bit_thrs_g value has changed to 350
Check if the Global rb_ASIC_ALSx_ShortDetected_cnt_g has been decreased by 1
Check if the Global rb_ASIC_ALSx_ShortDetected_Max_cnt_g is equal to rb_ASIC_ALSx_ShortDetected_cnt_g
Check if the Global rb_ASIC_ALSx_ShortDetected_Error_g has not been changed
Check if the Global uF_ASIC_Error_Flags_g.Bit.B2 has not been set
Check if rb_ASIC_ALSx_INC_Ready_g has been reset to 0
TEST.END_NOTES:
TEST.STUB:G5_ASIC_Control_sr.ASIC_Control_INREC_INC_LightValScl
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rw_IR_INC_light16bit_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALSxADval_g[6].avg:300
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALSxADval_g[6].avginc:344
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rw_IR_INC_light16bit_thrs_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ALSx_ShortDetected_cnt_g:7
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ALSx_ShortDetected_Max_cnt_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ALSx_ShortDetected_Error_g:7
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_Error_Flags_g.Bit.B2:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ALSx_INC_Ready_g:0x8
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rw_IR_INC_light16bit_g:344
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rw_IR_INC_light16bit_thrs_g:350
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ALSx_ShortDetected_cnt_g:6
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ALSx_ShortDetected_Max_cnt_g:6
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ALSx_ShortDetected_Error_g:7
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_Error_Flags_g.Bit.B2:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ALSx_INC_Ready_g:0
TEST.END

-- Test Case: AC_ALSxINCShortDetect.INREC.4
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_ALSxINCShortDetect
TEST.NEW
TEST.NAME:AC_ALSxINCShortDetect.INREC.4
TEST.NOTES:
TestCase4:
Set rb_ASIC_ALSx_INC_Ready_g to 0x8
Stub ASIC_Control_INREC_INC_LightValScl and set the return value to input parameter rw_temp_INREC_INC_ASIC_l
Set ADC value ras_ASIC_ALSxADval_g[6].avg to 240
Set ADC value ras_ASIC_ALSxADval_g[6].avginc to 344
Check the Global rw_IR_INC_light16bit_g value has changed to 344
Check the Global rw_IR_INC_light16bit_thrs_g value has changed to 0
Check if the Global rb_ASIC_ALSx_ShortDetected_cnt_g has been decreased by 1
Check if the Global rb_ASIC_ALSx_ShortDetected_Max_cnt_g is equal to rb_ASIC_ALSx_ShortDetected_cnt_g
Check if the Global rb_ASIC_ALSx_ShortDetected_Error_g has not been changed
Check if the Global uF_ASIC_Error_Flags_g.Bit.B2 has not been set
Check if rb_ASIC_ALSx_INC_Ready_g has been reset to 0
TEST.END_NOTES:
TEST.STUB:G5_ASIC_Control_sr.ASIC_Control_INREC_INC_LightValScl
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rw_IR_INC_light16bit_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALSxADval_g[6].avg:240
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALSxADval_g[6].avginc:344
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rw_IR_INC_light16bit_thrs_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ALSx_ShortDetected_cnt_g:7
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ALSx_ShortDetected_Max_cnt_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ALSx_ShortDetected_Error_g:7
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_Error_Flags_g.Bit.B2:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ALSx_INC_Ready_g:0x8
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rw_IR_INC_light16bit_g:344
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rw_IR_INC_light16bit_thrs_g:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ALSx_ShortDetected_cnt_g:6
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ALSx_ShortDetected_Max_cnt_g:6
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ALSx_ShortDetected_Error_g:7
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_Error_Flags_g.Bit.B2:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ALSx_INC_Ready_g:0
TEST.END

-- Test Case: AC_ALSxINCShortDetect.INREC.5
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_ALSxINCShortDetect
TEST.NEW
TEST.NAME:AC_ALSxINCShortDetect.INREC.5
TEST.NOTES:
TestCase5:
Set rb_ASIC_ALSx_INC_Ready_g to 0x8
Stub ASIC_Control_INREC_INC_LightValScl and set the return value to input parameter rw_temp_INREC_INC_ASIC_l
Set ADC value ras_ASIC_ALSxADval_g[6].avg to 240
Set ADC value ras_ASIC_ALSxADval_g[6].avginc to 344
Check the Global rw_IR_INC_light16bit_g value has changed to 344
Check the Global rw_IR_INC_light16bit_thrs_g value has changed to 0
Check if the Global rb_ASIC_ALSx_ShortDetected_cnt_g remains 0
Check if the Global rb_ASIC_ALSx_ShortDetected_Max_cnt_g is equal to rb_ASIC_ALSx_ShortDetected_cnt_g
Check if the Global rb_ASIC_ALSx_ShortDetected_Error_g has been set to 0
Check if the Global uF_ASIC_Error_Flags_g.Bit.B2 has not been set
Check if rb_ASIC_ALSx_INC_Ready_g has been reset to 0
TEST.END_NOTES:
TEST.STUB:G5_ASIC_Control_sr.ASIC_Control_INREC_INC_LightValScl
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rw_IR_INC_light16bit_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALSxADval_g[6].avg:240
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALSxADval_g[6].avginc:344
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rw_IR_INC_light16bit_thrs_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ALSx_ShortDetected_cnt_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ALSx_ShortDetected_Max_cnt_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ALSx_ShortDetected_Error_g:7
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_Error_Flags_g.Bit.B2:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ALSx_INC_Ready_g:0x8
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rw_IR_INC_light16bit_g:344
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rw_IR_INC_light16bit_thrs_g:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ALSx_ShortDetected_cnt_g:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ALSx_ShortDetected_Max_cnt_g:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ALSx_ShortDetected_Error_g:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_Error_Flags_g.Bit.B2:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ALSx_INC_Ready_g:0
TEST.END

-- Subprogram: ASIC_Control_ASIC_ErrFlags_Check

-- Test Case: SPIErrorFlagErrorCountzero
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_ASIC_ErrFlags_Check
TEST.NEW
TEST.NAME:SPIErrorFlagErrorCountzero
TEST.NOTES:
Testcase2:
Set rb_ASIC_SPI_ErrorFlag_g as FALSE (0)
Set ras_ASIC_CtrReg[IDY_STATH_REG].val as 0
Set rb_ASIC_ControlMode_g to CASE_ASIC_CNT_MD_STANDBY (51)
Set rb_ASIC_SPI_ErrorCodeCnt_g as 0
Check if rb_ASIC_SPI_ErrorCodeCnt_g remains unchanged
Check if rbi_ASIC_SPI_Error_g (uF_ASIC_Ctrl_Error_Flags_g.Bit.B0) is set to FALSE (0)
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_SPI_ErrorFlag_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_CtrReg_g[16].val:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_Ctrl_Error_Flags_g.Bit.B0:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_SPI_ErrorCodeCnt_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:51
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_Ctrl_Error_Flags_g.Bit.B0:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_SPI_ErrorCodeCnt_g:0
TEST.END

-- Test Case: SPIErrorFlagErrorcountnotzero
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_ASIC_ErrFlags_Check
TEST.NEW
TEST.NAME:SPIErrorFlagErrorcountnotzero
TEST.NOTES:
Testcase1:
Set rb_ASIC_SPI_ErrorFlag_g to FALSE (0)
Set ras_ASIC_CtrReg[IDY_STATH_REG].val to 0
Set rb_ASIC_ControlMode_g to a value != CASE_ASIC_CNT_MD_STANDBY (here 0)
Check if rb_ASIC_SPI_ErrorCodeCnt_g is decreased by 1
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_SPI_ErrorFlag_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_CtrReg_g[16].val:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_SPI_ErrorCodeCnt_g:5
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_SPI_ErrorCodeCnt_g:4
TEST.END

-- Test Case: SPIErrorFlagTrue
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_ASIC_ErrFlags_Check
TEST.NEW
TEST.NAME:SPIErrorFlagTrue
TEST.NOTES:
Testcase3:
Set rb_ASIC_SPI_ErrorFlag_g as TRUE (1)
Set ras_ASIC_CtrReg[IDY_STATH_REG].val as 16
Set rb_ASIC_ControlMode_g unequal to CASE_ASIC_CNT_MD_STANDBY (here 52)
Set rb_newAsicSTAT_g as 3
Check if Global rb_ASIC_SPI_ErrorCodeCnt_g has been increased by 10
Check Global rb_ASIC_SPI_ErrorFlag_g for TRUE (1)
Check Global rb_ASIC_ControlMode_g for 0
Check Global rb_newAsicSTAT_g for 0
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_SPI_ErrorFlag_g:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_CtrReg_g[16].val:16
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_newAsicSTAT_g:3
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_SPI_ErrorCodeCnt_g:50
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:52
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_SPI_ErrorFlag_g:1
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_newAsicSTAT_g:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_SPI_ErrorCodeCnt_g:60
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:0
TEST.END

-- Test Case: SPIErrorFlagTrue_HighErrorCnt
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_ASIC_ErrFlags_Check
TEST.NEW
TEST.NAME:SPIErrorFlagTrue_HighErrorCnt
TEST.NOTES:
Testcase4:
Set rb_ASIC_SPI_ErrorFlag_g as TRUE (1)
Set ras_ASIC_CtrReg[IDY_STATH_REG].val as 16
Set rb_ASIC_ControlMode_g unequal to CASE_ASIC_CNT_MD_STANDBY (here 52)
Set rb_newAsicSTAT_g as 3
Check if Global rb_ASIC_SPI_ErrorCodeCnt_g has been increased by 5
Check Global rb_ASIC_SPI_ErrorFlag_g for TRUE (1)
Check if rbi_ASIC_SPI_Error_g (uF_ASIC_Ctrl_Error_Flags_g.Bit.B0) is set to TRUE (1)
Check Global rb_ASIC_ControlMode_g for 0
Check Global rb_newAsicSTAT_g for 0
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_SPI_ErrorFlag_g:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_CtrReg_g[16].val:16
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_newAsicSTAT_g:3
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_Ctrl_Error_Flags_g.Bit.B0:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_SPI_ErrorCodeCnt_g:100
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:52
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_SPI_ErrorFlag_g:1
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_newAsicSTAT_g:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_Ctrl_Error_Flags_g.Bit.B0:1
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_SPI_ErrorCodeCnt_g:105
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:0
TEST.END

-- Test Case: SPIErrorFlagTrue_HighErrorCnt.001
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_ASIC_ErrFlags_Check
TEST.NEW
TEST.NAME:SPIErrorFlagTrue_HighErrorCnt.001
TEST.NOTES:
Testcase4:
Set rb_ASIC_SPI_ErrorFlag_g as TRUE (1)
Set ras_ASIC_CtrReg[IDY_STATH_REG].val as 10
Set rb_ASIC_SPI_ErrorCodeCnt_g to a value less the 50 (here 40)
Set rb_ASIC_ControlMode_g unequal to CASE_ASIC_CNT_MD_STANDBY (here 52)
Set rb_newAsicSTAT_g as 3
Check if Global rb_ASIC_SPI_ErrorCodeCnt_g is increased by 5
Check Global rb_ASIC_SPI_ErrorFlag_g for TRUE (1)
Check if rbi_ASIC_SPI_Error_g (uF_ASIC_Ctrl_Error_Flags_g.Bit.B0) remains unchanged
Check Global rb_ASIC_ControlMode_g remains unchanged
Check Global rb_newAsicSTAT_g for 0
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_SPI_ErrorFlag_g:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_CtrReg_g[16].val:10
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_newAsicSTAT_g:3
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_Ctrl_Error_Flags_g.Bit.B0:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_SPI_ErrorCodeCnt_g:40
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:52
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_SPI_ErrorFlag_g:1
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_newAsicSTAT_g:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_Ctrl_Error_Flags_g.Bit.B0:1
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_SPI_ErrorCodeCnt_g:45
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:52
TEST.END

-- Subprogram: ASIC_Control_AsicStatus

-- Test Case: ASIC_Control_AsicStatus1
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_AsicStatus
TEST.NEW
TEST.NAME:ASIC_Control_AsicStatus1
TEST.NOTES:
Testcase1:
Set rb_NextSPI_Request_g as 1
Set rb_CurMode_g as 1
Set rb_SPI_Data_to_send as 0
Set rab_SPI_ASICWriteBuffer_mg[0...3] as 0
Set parameter rb_lengthOfBlock to stub SPI_WriteBlock() as 0
Check Global rb_NextSPI_Request_g remains 1
Check Global rb_SPI_Data_to_send is set to 4
Check Global rab_SPI_ASICWriteBuffer_mg[0...3] is set to {0xA1, 0x2A, 0x2A, 0x2A}
Check Global parameter rb_lengthOfBlock to stub SPI_WriteBlock() is set to 4
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_CurMode_g:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_SPI_Data_to_send_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[0]:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[1]:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[2]:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[3]:0
TEST.VALUE:uut_prototype_stubs.SPI_WriteBlock.rb_lenghtOfBlock:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:1
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_SPI_Data_to_send_g:4
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[0]:0xA1
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[1]:0x2A
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[2]:0x2A
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[3]:0x2A
TEST.EXPECTED:uut_prototype_stubs.SPI_WriteBlock.rb_lenghtOfBlock:4
TEST.END

-- Test Case: ASIC_Control_AsicStatus2
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_AsicStatus
TEST.NEW
TEST.NAME:ASIC_Control_AsicStatus2
TEST.NOTES:
Testcase2:
Set rb_NextSPI_Request_g as 3
Set rb_CurMode_g as 1
Set rb_SPI_Data_to_send as 0
Set rab_SPI_ASICWriteBuffer_mg[0...3] as 0
Set parameter rb_lengthOfBlock to stub SPI_WriteBlock() as 0
Check Global rb_NextSPI_Request_g remains is reset to 0
Check Global rb_SPI_Data_to_send is set to 4
Check Global rab_SPI_ASICWriteBuffer_mg[0...3] is set to {0xA1, 0x2A, 0x2A, 0x16}
Check Global parameter rb_lengthOfBlock to stub SPI_WriteBlock() is set to 4
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:3
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_CurMode_g:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_SPI_Data_to_send_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[0]:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[1]:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[2]:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[3]:0
TEST.VALUE:uut_prototype_stubs.SPI_WriteBlock.rb_lenghtOfBlock:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_SPI_Data_to_send_g:4
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[0]:161
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[1]:0x2A
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[2]:0x2A
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[3]:0x16
TEST.EXPECTED:uut_prototype_stubs.SPI_WriteBlock.rb_lenghtOfBlock:4
TEST.END

-- Test Case: ASIC_Control_AsicStatus3
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_AsicStatus
TEST.NEW
TEST.NAME:ASIC_Control_AsicStatus3
TEST.NOTES:
Testcase3:
Set rb_NextSPI_Request_g as 3
Set rb_CurMode_g as 5 (CB_ASIC_LOPEN_MD)
Set rb_SPI_Data_to_send as 0
Set rab_SPI_ASICWriteBuffer_mg[0...3] as 0
Set EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g (rb_ASIC_Sched_Config_g) to 0
Set uF_SPI_flag_g.Bit.B2 (rbi_StandbyModulatorIntegrating_g) to FALSE (0)
Set parameter rb_lengthOfBlock to stub SPI_WriteBlock() as 0
Check Global rb_NextSPI_Request_g remains is reset to 0
Check Global rb_SPI_Data_to_send is set to 4
Check Global rab_SPI_ASICWriteBuffer_mg[0...3] is set to {0xA1, 0x2A, 0x2A, 0x16}
Check flag uF_SPI_flag_g.Bit.B2 (rbi_StandbyModulatorIntegrating_g) is set to TRUE (1)
Check Global parameter rb_lengthOfBlock to stub SPI_WriteBlock() is set to 4
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:3
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_CurMode_g:5
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_SPI_Data_to_send_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[0]:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[1]:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[2]:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[3]:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_SPI_flags_g.Bit.B2:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g:0
TEST.VALUE:uut_prototype_stubs.SPI_WriteBlock.rb_lenghtOfBlock:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_SPI_Data_to_send_g:4
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[0]:161
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[1]:0x2A
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[2]:0x2A
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[3]:0x16
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.uF_SPI_flags_g.Bit.B2:1
TEST.EXPECTED:uut_prototype_stubs.SPI_WriteBlock.rb_lenghtOfBlock:4
TEST.END

-- Test Case: ASIC_Control_AsicStatus4
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_AsicStatus
TEST.NEW
TEST.NAME:ASIC_Control_AsicStatus4
TEST.NOTES:
Testcase4:
Set rb_NextSPI_Request_g as 3
Set rb_CurMode_g as 5 (CB_ASIC_LOPEN_MD)
Set rb_SPI_Data_to_send as 0
Set rab_SPI_ASICWriteBuffer_mg[0...3] as 0
Set EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g (rb_ASIC_Sched_Config_g) to 0x20
Set uF_SPI_flag_g.Bit.B2 (rbi_StandbyModulatorIntegrating_g) to FALSE (0)
Set parameter rb_lengthOfBlock to stub SPI_WriteBlock() as 0
Check Global rb_NextSPI_Request_g remains is reset to 0
Check Global rb_SPI_Data_to_send is set to 4
Check Global rab_SPI_ASICWriteBuffer_mg[0...3] is set to {0xA1, 0x2A, 0x2A, 0x12}
Check flag uF_SPI_flag_g.Bit.B2 (rbi_StandbyModulatorIntegrating_g) remains set to FALSE (0)
Check Global parameter rb_lengthOfBlock to stub SPI_WriteBlock() is set to 4
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:3
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_CurMode_g:5
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_SPI_Data_to_send_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[0]:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[1]:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[2]:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[3]:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_SPI_flags_g.Bit.B2:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g:0x20
TEST.VALUE:uut_prototype_stubs.SPI_WriteBlock.rb_lenghtOfBlock:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_SPI_Data_to_send_g:4
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[1]:0x2A
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[2]:0x2A
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[3]:0x12
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.uF_SPI_flags_g.Bit.B2:0
TEST.EXPECTED:uut_prototype_stubs.SPI_WriteBlock.rb_lenghtOfBlock:4
TEST.END

-- Test Case: ASIC_Control_AsicStatus5
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_AsicStatus
TEST.NEW
TEST.NAME:ASIC_Control_AsicStatus5
TEST.NOTES:
Testcase5:
Set rb_CurMode_g as 7
Set rb_SPI_Data_to_send_g as 0
Check Global rb_SPI_Data_to_send_g remains 0
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_CurMode_g:7
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_SPI_Data_to_send_g:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_SPI_Data_to_send_g:0
TEST.END

-- Subprogram: ASIC_Control_ChangeModeCmd

-- Test Case: ASIC_Control_ChangeModeCmd1
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_ChangeModeCmd
TEST.NEW
TEST.NAME:ASIC_Control_ChangeModeCmd1
TEST.NOTES:
Testcase1:
Set parameter next_mode to CB_ASIC_SLEEP_MD (7)
set rb_wait500zs_g as 100
set rb_CurMode_g as 1
set rb_PrevMode_g as 0
set parameter rb_byteToWrite_l of stub SPI_Write_Byte as 0
Check Global rb_wait500zs_g remains 100
Check Global rb_CurMode_g for CB_ASIC_SLEEP_MD (7)
Check Global rb_PrevMode_g for 1
Check Global parameter rb_byteToWrite_l of stub SPI_Write_Byte for 206
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_wait500us_g:100
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_CurMode_g:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_PrevMode_g:0
TEST.VALUE:G5_ASIC_Control_sr.ASIC_Control_ChangeModeCmd.next_mode:CB_ASIC_SLEEP_MD
TEST.VALUE:uut_prototype_stubs.SPI_Write_Byte.rb_byteToWrite_l:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_wait500us_g:100
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_CurMode_g:CB_ASIC_SLEEP_MD
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_PrevMode_g:1
TEST.EXPECTED:uut_prototype_stubs.SPI_Write_Byte.rb_byteToWrite_l:206
TEST.END

-- Test Case: ASIC_Control_ChangeModeCmd2
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_ChangeModeCmd
TEST.NEW
TEST.NAME:ASIC_Control_ChangeModeCmd2
TEST.NOTES:
Testcase2:
Set parameter next_mode to CB_ASIC_LSTOP_MD (4)
set rb_wait500zs_g as 100
set rb_CurMode_g as 1
set rb_PrevMode_g as 2
set parameter rb_byteToWrite_l of stub SPI_Write_Byte as 0
Check Global rb_wait500zs_g is reset to 0
Check Global rb_CurMode_g remains 1
Check Global rb_PrevMode_g remains 2
Check Global parameter rb_byteToWrite_l of stub SPI_Write_Byte for 200
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_wait500us_g:100
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_CurMode_g:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_PrevMode_g:2
TEST.VALUE:G5_ASIC_Control_sr.ASIC_Control_ChangeModeCmd.next_mode:CB_ASIC_LSTOP_MD
TEST.VALUE:uut_prototype_stubs.SPI_Write_Byte.rb_byteToWrite_l:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_wait500us_g:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_CurMode_g:1
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_PrevMode_g:2
TEST.EXPECTED:uut_prototype_stubs.SPI_Write_Byte.rb_byteToWrite_l:200
TEST.END

-- Test Case: ASIC_Control_ChangeModeCmd3
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_ChangeModeCmd
TEST.NEW
TEST.NAME:ASIC_Control_ChangeModeCmd3
TEST.NOTES:
Testcase3:
Set parameter next_mode as CB_ASIC_LSTOP_MD (4)
set rb_wait500zs_g as 100
set rb_CurMode_g as CB_ASIC_LSTOP_MD (4)
Check Global rb_wait500zs_g is reset to 0
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_wait500us_g:100
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_CurMode_g:CB_ASIC_LSTOP_MD
TEST.VALUE:G5_ASIC_Control_sr.ASIC_Control_ChangeModeCmd.next_mode:CB_ASIC_LSTOP_MD
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_wait500us_g:0
TEST.END

-- Subprogram: ASIC_Control_DelogLightValue

-- Test Case: NegativeExponent
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_DelogLightValue
TEST.NEW
TEST.NAME:NegativeExponent
TEST.NOTES:
Testcase1:
Set rw_CorrectedVoltage_l as 0
Set rw_PotenzScalingfaktor_l as 5
Set rb_WindShieldTransPerCent_l as 1
Set rb_negativeSign_l as 0
Check return value for 5
TEST.END_NOTES:
TEST.VALUE:G5_ASIC_Control_sr.ASIC_Control_DelogLightValue.rw_CorrectedVoltage_l:0
TEST.VALUE:G5_ASIC_Control_sr.ASIC_Control_DelogLightValue.rw_PotenzScalingfaktor_l:5
TEST.VALUE:G5_ASIC_Control_sr.ASIC_Control_DelogLightValue.rb_WindshieldTransPerCent_l:1
TEST.VALUE:G5_ASIC_Control_sr.ASIC_Control_DelogLightValue.rb_negativeSign_l:0
TEST.EXPECTED:G5_ASIC_Control_sr.ASIC_Control_DelogLightValue.return:5
TEST.END

-- Test Case: NegativeExponentMaxValue
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_DelogLightValue
TEST.NEW
TEST.NAME:NegativeExponentMaxValue
TEST.NOTES:
Testcase2:
Set rw_CorrectedVoltage_l as 10000
Set rw_PotenzScalingfaktor_l as 5
Set rb_WindShieldTransPerCent_l as 1
Set rb_negativeSign_l as 0
Check return value for 0xFFFFFFFF
TEST.END_NOTES:
TEST.VALUE:G5_ASIC_Control_sr.ASIC_Control_DelogLightValue.rw_CorrectedVoltage_l:10000
TEST.VALUE:G5_ASIC_Control_sr.ASIC_Control_DelogLightValue.rw_PotenzScalingfaktor_l:5
TEST.VALUE:G5_ASIC_Control_sr.ASIC_Control_DelogLightValue.rb_WindshieldTransPerCent_l:1
TEST.VALUE:G5_ASIC_Control_sr.ASIC_Control_DelogLightValue.rb_negativeSign_l:0
TEST.EXPECTED:G5_ASIC_Control_sr.ASIC_Control_DelogLightValue.return:0xFFFFFFFF
TEST.END

-- Test Case: PositiveExponent
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_DelogLightValue
TEST.NEW
TEST.NAME:PositiveExponent
TEST.NOTES:
Testcase1:
Set rw_CorrectedVoltage_l as 4096
Set rw_PotenzScalingfaktor_l as 10
Set rb_WindShieldTransPerCent_l as 1
Set rb_negativeSign_l as 1
Check return value for 0
TEST.END_NOTES:
TEST.VALUE:G5_ASIC_Control_sr.ASIC_Control_DelogLightValue.rw_CorrectedVoltage_l:4096
TEST.VALUE:G5_ASIC_Control_sr.ASIC_Control_DelogLightValue.rw_PotenzScalingfaktor_l:10
TEST.VALUE:G5_ASIC_Control_sr.ASIC_Control_DelogLightValue.rb_WindshieldTransPerCent_l:1
TEST.VALUE:G5_ASIC_Control_sr.ASIC_Control_DelogLightValue.rb_negativeSign_l:1
TEST.EXPECTED:G5_ASIC_Control_sr.ASIC_Control_DelogLightValue.return:0
TEST.END

-- Subprogram: ASIC_Control_INMODON_LightValScl

-- Test Case: INMODON_LightValScl1
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_INMODON_LightValScl
TEST.NEW
TEST.NAME:INMODON_LightValScl1
TEST.NOTES:
TestCase1:
Stub ASIC_Control_DelogLightValue and set the return value > 0xFFFF (here 0x10000)
Set rw_IR_light16bit_g to 600
Set rw_IR_light16bit_Mod_On_g as 0
Check the Global rw_IR_light16bit_Mod_On_g value for 0xFFFF
Check the Global rw_IR_DeltaModON_g for 255
TEST.END_NOTES:
TEST.STUB:G5_ASIC_Control_sr.ASIC_Control_DelogLightValue
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rw_IR_light16bit_g:600
TEST.VALUE:G5_ASIC_Control_sr.ASIC_Control_DelogLightValue.return:65536
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rw_IR_light16bit_Mod_On_g:65535
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_IR_DeltaModON_g:255
TEST.END

-- Test Case: INMODON_LightValScl2
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_INMODON_LightValScl
TEST.NEW
TEST.NAME:INMODON_LightValScl2
TEST.NOTES:
TestCase2:
Stub ASIC_Control_DelogLightValue and set the return value < 0xFFFF (here 500)
Set rw_IR_light16bit_g to 400
Set rw_IR_light16bit_Mod_On_g as 0
Check the Global rw_IR_light16bit_Mod_On_g value for 500
Check the Global rw_IR_DeltaModON_g for 100
TEST.END_NOTES:
TEST.STUB:G5_ASIC_Control_sr.ASIC_Control_DelogLightValue
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rw_IR_light16bit_g:400
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rw_IR_light16bit_Mod_On_g:0
TEST.VALUE:G5_ASIC_Control_sr.ASIC_Control_DelogLightValue.return:500
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rw_IR_light16bit_Mod_On_g:500
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_IR_DeltaModON_g:100
TEST.END

-- Test Case: INMODON_LightValScl3
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_INMODON_LightValScl
TEST.NEW
TEST.NAME:INMODON_LightValScl3
TEST.NOTES:
TestCase2:
Stub ASIC_Control_DelogLightValue and set the return value < 0xFFFF (here 500)
Set rw_IR_light16bit_g to 600
Set rw_IR_light16bit_Mod_On_g as 0
Check the Global rw_IR_light16bit_Mod_On_g value for 500
Check the Global rw_IR_DeltaModON_g for 0
TEST.END_NOTES:
TEST.STUB:G5_ASIC_Control_sr.ASIC_Control_DelogLightValue
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rw_IR_light16bit_g:600
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rw_IR_light16bit_Mod_On_g:0
TEST.VALUE:G5_ASIC_Control_sr.ASIC_Control_DelogLightValue.return:500
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rw_IR_light16bit_Mod_On_g:500
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_IR_DeltaModON_g:0
TEST.END

-- Subprogram: ASIC_Control_INREC_INC_LightValScl

-- Test Case: AC_INREC_INC_LightValScl
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_INREC_INC_LightValScl
TEST.NEW
TEST.NAME:AC_INREC_INC_LightValScl
TEST.NOTES:
TestCase1:
Stub fn ASIC_Control_DelogLightValue
set fn ASIC_Control_DelogLightValue return value < 0x8000 and less than 36 (here 35)
set the parameter rw_filterInrec_l to 0
Check the return value for 34 
TEST.END_NOTES:
TEST.STUB:G5_ASIC_Control_sr.ASIC_Control_DelogLightValue
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.ASIC_Control_INREC_INC_LightValScl.rb_filterInrec_l:0
TEST.VALUE:G5_ASIC_Control_sr.ASIC_Control_DelogLightValue.return:35
TEST.EXPECTED:G5_ASIC_Control_sr.ASIC_Control_INREC_INC_LightValScl.return:34
TEST.END

-- Test Case: AC_INREC_INC_LightValScl2
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_INREC_INC_LightValScl
TEST.NEW
TEST.NAME:AC_INREC_INC_LightValScl2
TEST.NOTES:
TestCase2:
Stub fn ASIC_Control_DelogLightValue
set fn ASIC_Control_DelogLightValue return value < 0x8000 and less than 36 and less than 6 (here 5)
set the parameter rb_filterInrec_l to 0
Check the return value for zero
TEST.END_NOTES:
TEST.STUB:G5_ASIC_Control_sr.ASIC_Control_DelogLightValue
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.ASIC_Control_INREC_INC_LightValScl.rb_filterInrec_l:0
TEST.VALUE:G5_ASIC_Control_sr.ASIC_Control_DelogLightValue.return:5
TEST.EXPECTED:G5_ASIC_Control_sr.ASIC_Control_INREC_INC_LightValScl.return:0
TEST.END

-- Test Case: AC_INREC_INC_LightValScl3
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_INREC_INC_LightValScl
TEST.NEW
TEST.NAME:AC_INREC_INC_LightValScl3
TEST.NOTES:
TestCase1:
Stub fn ASIC_Control_DelogLightValue
set fn ASIC_Control_DelogLightValue return value < 0x8000 (here 500)
set parameter rb_filterInrec_l to 5
Set rw_IR_INC_light16bit_g to 201
Check the return value
it should be ((rw_IR_INC_light16bit_g)+(rw_V_INREC_INC_ASIC_Corr_l))/2 -> 350
TEST.END_NOTES:
TEST.STUB:G5_ASIC_Control_sr.ASIC_Control_DelogLightValue
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rw_IR_INC_light16bit_g:201
TEST.VALUE:G5_ASIC_Control_sr.ASIC_Control_INREC_INC_LightValScl.rb_filterInrec_l:5
TEST.VALUE:G5_ASIC_Control_sr.ASIC_Control_DelogLightValue.return:500
TEST.EXPECTED:G5_ASIC_Control_sr.ASIC_Control_INREC_INC_LightValScl.return:350
TEST.END

-- Test Case: AC_INREC_INC_LightValScl4
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_INREC_INC_LightValScl
TEST.NEW
TEST.NAME:AC_INREC_INC_LightValScl4
TEST.NOTES:
TestCase:
Stub fn ASIC_Control_DelogLightValue
set fn ASIC_Control_DelogLightValue return value > 0x8000 (here 40000)
set parameter rb_filterInrec_l to 0
Check the return value for 0x7FFF
TEST.END_NOTES:
TEST.STUB:G5_ASIC_Control_sr.ASIC_Control_DelogLightValue
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.ASIC_Control_INREC_INC_LightValScl.rb_filterInrec_l:0
TEST.VALUE:G5_ASIC_Control_sr.ASIC_Control_DelogLightValue.return:40000
TEST.EXPECTED:G5_ASIC_Control_sr.ASIC_Control_INREC_INC_LightValScl.return:32767
TEST.END

-- Subprogram: ASIC_Control_INREC_LightValScl

-- Test Case: AC_INREC_LightValScl1
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_INREC_LightValScl
TEST.NEW
TEST.NAME:AC_INREC_LightValScl1
TEST.NOTES:
TestCase1:
Stub the fn ASIC_Control_DelogLightValue and set the return value as 35
Set parameter rb_filterInrec_l as 0
Check the Global rw_IR_light16bit_g for rw_IR_light16bit_g -(36/rw_IR_light16bit_g) -> 34
TEST.END_NOTES:
TEST.STUB:G5_ASIC_Control_sr.ASIC_Control_DelogLightValue
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rw_IR_light16bit_g:55
TEST.VALUE:G5_ASIC_Control_sr.ASIC_Control_INREC_LightValScl.rb_filterInrec_l:0
TEST.VALUE:G5_ASIC_Control_sr.ASIC_Control_DelogLightValue.return:35
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rw_IR_light16bit_g:34
TEST.END

-- Test Case: AC_INREC_LightValScl2
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_INREC_LightValScl
TEST.NEW
TEST.NAME:AC_INREC_LightValScl2
TEST.NOTES:
TestCase2:
Stub the fn ASIC_Control_DelogLightValue and set the return value as 5
Set parameter rb_filterInrec_l as 0
Check the Global rw_IR_light16bit_g for 0
TEST.END_NOTES:
TEST.STUB:G5_ASIC_Control_sr.ASIC_Control_DelogLightValue
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rw_IR_light16bit_g:55
TEST.VALUE:G5_ASIC_Control_sr.ASIC_Control_INREC_LightValScl.rb_filterInrec_l:0
TEST.VALUE:G5_ASIC_Control_sr.ASIC_Control_DelogLightValue.return:5
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rw_IR_light16bit_g:0
TEST.END

-- Test Case: AC_INREC_LightValScl3
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_INREC_LightValScl
TEST.NEW
TEST.NAME:AC_INREC_LightValScl3
TEST.NOTES:
TestCase3.
Stub the fn ASIC_Control_DelogLightValue and set the return value as 500
Set parameter rb_filterInrec_l as 5
Check the Global rw_IR_light16bit_g for 249
TEST.END_NOTES:
TEST.STUB:G5_ASIC_Control_sr.ASIC_Control_DelogLightValue
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.ASIC_Control_INREC_LightValScl.rb_filterInrec_l:5
TEST.VALUE:G5_ASIC_Control_sr.ASIC_Control_DelogLightValue.return:500
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rw_IR_light16bit_g:249
TEST.END

-- Test Case: AC_INREC_LightValScl4
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_INREC_LightValScl
TEST.NEW
TEST.NAME:AC_INREC_LightValScl4
TEST.NOTES:
TestCase4:
Stub the fn ASIC_Control_DelogLightValue and set the return value as 40000
Set parameter rb_filterInrec_l as 0
Check the Global rw_IR_light16bit_g for 32767
TEST.END_NOTES:
TEST.STUB:G5_ASIC_Control_sr.ASIC_Control_DelogLightValue
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.ASIC_Control_INREC_LightValScl.rb_filterInrec_l:0
TEST.VALUE:G5_ASIC_Control_sr.ASIC_Control_DelogLightValue.return:40000
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rw_IR_light16bit_g:32767
TEST.END

-- Subprogram: ASIC_Control_LightValueCorrect

-- Test Case: AC_LightValueCorrect
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_LightValueCorrect
TEST.NEW
TEST.NAME:AC_LightValueCorrect
TEST.NOTES:
Set parameter rb_MUX_cfg_ALSx_l as 0x50 to select index as 2 for calibration current/B_Factor and as 4 for Iref to Ical
Set parameter rw_a_Faktor_l as 199 to get defined result
Set parameter rw_Light_Voltage_l as 0
Set ras_ASIC_ALI_CalibAD_g[2] and ras_ASIC_ALI_CalibAD_g[4] as 0 to get values out of limíts
Set EEPROM_Struct_PD.EEPROMStructPD.B_Factor_Iref_Lo_Gain_Hi_g (rb_B_Factor_Iref_Lo_Gain_Hi_g) as 2
Check Global uF_ASIC_CALC_Flags.Bit.B0 (rbi_negativeSign_mg) is set to TRUE (1)
Check Return = 321
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALI_CalibAD_g[2].avg:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALI_CalibAD_g[4].avg:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_Calc_Flags_g.Bit.B0:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.B_Factor_Iref_Lo_Gain_Hi_g:2
TEST.VALUE:G5_ASIC_Control_sr.ASIC_Control_LightValueCorrect.rw_LightVoltage_l:0
TEST.VALUE:G5_ASIC_Control_sr.ASIC_Control_LightValueCorrect.rw_a_Faktor_l:199
TEST.VALUE:G5_ASIC_Control_sr.ASIC_Control_LightValueCorrect.rb_MUX_cfg_ALSx_l:0x50
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_Calc_Flags_g.Bit.B0:1
TEST.EXPECTED:G5_ASIC_Control_sr.ASIC_Control_LightValueCorrect.return:321
TEST.END

-- Test Case: AC_LightValueCorrect2
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_LightValueCorrect
TEST.NEW
TEST.NAME:AC_LightValueCorrect2
TEST.NOTES:
Set parameter rb_MUX_cfg_ALSx_l as 0x50 to select index as 2 for calibration current/B_Factor and as 4 for Iref to Ical
Set parameter rw_a_Faktor_l as 199 to get defined result
Set parameter rw_Light_Voltage_l as 650
Set ras_ASIC_ALI_CalibAD_g[2] as 300 and ras_ASIC_ALI_CalibAD_g[4] as 700 to get values within limíts
Set EEPROM_Struct_PD.EEPROMStructPD.B_Factor_Iref_Lo_Gain_Hi_g (rb_B_Factor_Iref_Lo_Gain_Hi_g) as 2
Check Global rw_Vref_plusVoff_g = 500
Check Global uF_ASIC_CALC_Flags.Bit.B0 (rbi_negativeSign_mg) is set to TRUE (1)
Check Return = 314
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALI_CalibAD_g[2].avg:300
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALI_CalibAD_g[4].avg:700
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rw_Vref_plusVoff_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_Calc_Flags_g.Bit.B0:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.B_Factor_Iref_Lo_Gain_Hi_g:2
TEST.VALUE:G5_ASIC_Control_sr.ASIC_Control_LightValueCorrect.rw_LightVoltage_l:650
TEST.VALUE:G5_ASIC_Control_sr.ASIC_Control_LightValueCorrect.rw_a_Faktor_l:199
TEST.VALUE:G5_ASIC_Control_sr.ASIC_Control_LightValueCorrect.rb_MUX_cfg_ALSx_l:0x50
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rw_Vref_plusVoff_g:500
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_Calc_Flags_g.Bit.B0:1
TEST.EXPECTED:G5_ASIC_Control_sr.ASIC_Control_LightValueCorrect.return:314
TEST.END

-- Test Case: AC_LightValueCorrect3
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_LightValueCorrect
TEST.NEW
TEST.NAME:AC_LightValueCorrect3
TEST.NOTES:
Set parameter rb_MUX_cfg_ALSx_l as 0x80 to select index as 6 for calibration current, as 7 for Iref to Ical and 0 for B_Factor 
Set parameter rw_a_Faktor_l as 199 to get defined result
Set parameter rw_Light_Voltage_l as 650
Set ras_ASIC_ALI_CalibAD_g[6] as 300 and ras_ASIC_ALI_CalibAD_g[7] as 700 to get values within limíts
Set EEPROM_Struct_PD.EEPROMStructPD.B_Factor_Iref_Lo_Gain_Hi_g (rb_B_Factor_Iref_Lo_Gain_Hi_g) as 2
Check Global rw_Vref_plusVoff_g = 501
Check Global uF_ASIC_CALC_Flags.Bit.B0 (rbi_negativeSign_mg) is set to TRUE (1)
Check Return = 313
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALI_CalibAD_g[6].avg:300
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALI_CalibAD_g[7].avg:701
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rw_Vref_plusVoff_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_Calc_Flags_g.Bit.B0:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.B_Factor_Iref_Lo_Gain_Hi_g:2
TEST.VALUE:G5_ASIC_Control_sr.ASIC_Control_LightValueCorrect.rw_LightVoltage_l:650
TEST.VALUE:G5_ASIC_Control_sr.ASIC_Control_LightValueCorrect.rw_a_Faktor_l:199
TEST.VALUE:G5_ASIC_Control_sr.ASIC_Control_LightValueCorrect.rb_MUX_cfg_ALSx_l:0x80
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rw_Vref_plusVoff_g:501
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_Calc_Flags_g.Bit.B0:1
TEST.EXPECTED:G5_ASIC_Control_sr.ASIC_Control_LightValueCorrect.return:313
TEST.END

-- Test Case: AC_LightValueCorrect4
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_LightValueCorrect
TEST.NEW
TEST.NAME:AC_LightValueCorrect4
TEST.NOTES:
Set parameter rb_MUX_cfg_ALSx_l as 0x8C to select index as 8 for calibration current, as 9 for Iref to Ical and 3 for B_Factor 
Set parameter rw_a_Faktor_l as 199 to get defined result
Set parameter rw_Light_Voltage_l as 500
Set ras_ASIC_ALI_CalibAD_g[8] as 700 and ras_ASIC_ALI_CalibAD_g[9] as 400 to get values within limíts
Set EEPROM_Struct_PD.EEPROMStructPD.B_Factor_Iref_Hi_Gain_Hi_g (rb_B_Factor_Iref_Hi_Gain_Hi_g) as 100
Check Global rw_Vref_plusVoff_g = 550
Check Global uF_ASIC_CALC_Flags.Bit.B0 (rbi_negativeSign_mg) is set to TRUE (1)
Check Return = 280
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALI_CalibAD_g[8].avg:700
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALI_CalibAD_g[9].avg:400
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rw_Vref_plusVoff_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_Calc_Flags_g.Bit.B0:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.B_Factor_Iref_Hi_Gain_Hi_g:100
TEST.VALUE:G5_ASIC_Control_sr.ASIC_Control_LightValueCorrect.rw_LightVoltage_l:500
TEST.VALUE:G5_ASIC_Control_sr.ASIC_Control_LightValueCorrect.rw_a_Faktor_l:199
TEST.VALUE:G5_ASIC_Control_sr.ASIC_Control_LightValueCorrect.rb_MUX_cfg_ALSx_l:0x8C
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rw_Vref_plusVoff_g:550
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_Calc_Flags_g.Bit.B0:1
TEST.EXPECTED:G5_ASIC_Control_sr.ASIC_Control_LightValueCorrect.return:280
TEST.END

-- Test Case: AC_LightValueCorrect5
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_LightValueCorrect
TEST.NEW
TEST.NAME:AC_LightValueCorrect5
TEST.NOTES:
Set parameter rb_MUX_cfg_ALSx_l as 0x8C to select index as 8 for calibration current, as 9 for Iref to Ical and 3 for B_Factor 
Set parameter rw_a_Faktor_l as 550 to get defined result
Set parameter rw_Light_Voltage_l as 500
Set ras_ASIC_ALI_CalibAD_g[8] as 700 and ras_ASIC_ALI_CalibAD_g[9] as 400 to get values within limíts
Set EEPROM_Struct_PD.EEPROMStructPD.B_Factor_Iref_Lo_Gain_Hi_g (rb_B_Factor_Iref_Lo_Gain_Hi_g) as 2
Check Global rw_Vref_plusVoff_g = 550
Check Global uF_ASIC_CALC_Flags.Bit.B0 (rbi_negativeSign_mg) is set to FALSE (0)
Check Return = 38
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALI_CalibAD_g[8].avg:700
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALI_CalibAD_g[9].avg:400
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rw_Vref_plusVoff_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_Calc_Flags_g.Bit.B0:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.B_Factor_Iref_Lo_Gain_Hi_g:2
TEST.VALUE:G5_ASIC_Control_sr.ASIC_Control_LightValueCorrect.rw_LightVoltage_l:500
TEST.VALUE:G5_ASIC_Control_sr.ASIC_Control_LightValueCorrect.rw_a_Faktor_l:550
TEST.VALUE:G5_ASIC_Control_sr.ASIC_Control_LightValueCorrect.rb_MUX_cfg_ALSx_l:0x8C
TEST.VALUE:G5_ASIC_Control_sr.ASIC_Control_LightValueCorrect.return:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rw_Vref_plusVoff_g:550
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_Calc_Flags_g.Bit.B0:0
TEST.EXPECTED:G5_ASIC_Control_sr.ASIC_Control_LightValueCorrect.return:38
TEST.END

-- Test Case: AC_LightValueCorrect6
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_LightValueCorrect
TEST.NEW
TEST.NAME:AC_LightValueCorrect6
TEST.NOTES:
Set parameter rb_MUX_cfg_ALSx_l as 0x8C to select index as 8 for calibration current, as 9 for Iref to Ical and 3 for B_Factor 
Set parameter rw_a_Faktor_l as 550 to get defined result
Set parameter rw_Light_Voltage_l as 650
Set ras_ASIC_ALI_CalibAD_g[8] as 700 and ras_ASIC_ALI_CalibAD_g[9] as 400 to get values within limíts
Set EEPROM_Struct_PD.EEPROMStructPD.B_Factor_Iref_Hi_Gain_Hi_g (rb_B_Factor_Iref_Hi_Gain_Hi_g) as 10
Check Global rw_Vref_plusVoff_g = 550
Check Global uF_ASIC_CALC_Flags.Bit.B0 (rbi_negativeSign_mg) is set to FALSE (0)
Check Return = 32
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALI_CalibAD_g[8].avg:700
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALI_CalibAD_g[9].avg:400
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rw_Vref_plusVoff_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_Calc_Flags_g.Bit.B0:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.B_Factor_Iref_Hi_Gain_Hi_g:10
TEST.VALUE:G5_ASIC_Control_sr.ASIC_Control_LightValueCorrect.rw_LightVoltage_l:650
TEST.VALUE:G5_ASIC_Control_sr.ASIC_Control_LightValueCorrect.rw_a_Faktor_l:550
TEST.VALUE:G5_ASIC_Control_sr.ASIC_Control_LightValueCorrect.rb_MUX_cfg_ALSx_l:0x8C
TEST.VALUE:G5_ASIC_Control_sr.ASIC_Control_LightValueCorrect.return:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rw_Vref_plusVoff_g:550
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_Calc_Flags_g.Bit.B0:0
TEST.EXPECTED:G5_ASIC_Control_sr.ASIC_Control_LightValueCorrect.return:32
TEST.END

-- Test Case: AC_LightValueCorrect7
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_LightValueCorrect
TEST.NEW
TEST.NAME:AC_LightValueCorrect7
TEST.NOTES:
Set parameter rb_MUX_cfg_ALSx_l as 0x8C to select index as 8 for calibration current, as 9 for Iref to Ical and 3 for B_Factor 
Set parameter rw_a_Faktor_l as 550 to get defined result
Set parameter rw_Light_Voltage_l as 650
Set ras_ASIC_ALI_CalibAD_g[8] as 700 and ras_ASIC_ALI_CalibAD_g[9] as 400 to get values within limíts
Set EEPROM_Struct_PD.EEPROMStructPD.B_Factor_Iref_Hi_Gain_Hi_g (rb_B_Factor_Iref_Hi_Gain_Hi_g) as 200
Check Global rw_Vref_plusVoff_g = 550)
Check Global uF_ASIC_CALC_Flags.Bit.B0 (rbi_negativeSign_mg) is set to TRUE (1)
Check Return = 95
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALI_CalibAD_g[8].avg:700
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALI_CalibAD_g[9].avg:400
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rw_Vref_plusVoff_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_Calc_Flags_g.Bit.B0:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.B_Factor_Iref_Hi_Gain_Hi_g:200
TEST.VALUE:G5_ASIC_Control_sr.ASIC_Control_LightValueCorrect.rw_LightVoltage_l:650
TEST.VALUE:G5_ASIC_Control_sr.ASIC_Control_LightValueCorrect.rw_a_Faktor_l:550
TEST.VALUE:G5_ASIC_Control_sr.ASIC_Control_LightValueCorrect.rb_MUX_cfg_ALSx_l:0x8C
TEST.VALUE:G5_ASIC_Control_sr.ASIC_Control_LightValueCorrect.return:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rw_Vref_plusVoff_g:550
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_Calc_Flags_g.Bit.B0:1
TEST.EXPECTED:G5_ASIC_Control_sr.ASIC_Control_LightValueCorrect.return:95
TEST.END

-- Test Case: AC_LightValueCorrect8
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_LightValueCorrect
TEST.NEW
TEST.NAME:AC_LightValueCorrect8
TEST.NOTES:
Set parameter rb_MUX_cfg_ALSx_l as 0x8C to select index as 8 for calibration current, as 9 for Iref to Ical and 3 for B_Factor 
Set parameter rw_a_Faktor_l as 500 to get defined result
Set parameter rw_Light_Voltage_l as 500
Set ras_ASIC_ALI_CalibAD_g[8] as 700 and ras_ASIC_ALI_CalibAD_g[9] as 400 to get values within limíts
Set EEPROM_Struct_PD.EEPROMStructPD.B_Factor_Iref_Hi_Gain_Hi_g (rb_B_Factor_Iref_Hi_Gain_Hi_g) as 100
Check Global rw_Vref_plusVoff_g = 550
Check Global uF_ASIC_CALC_Flags.Bit.B0 (rbi_negativeSign_mg) is set to FALSE (0)
Check Return = 21
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALI_CalibAD_g[8].avg:700
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALI_CalibAD_g[9].avg:400
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rw_Vref_plusVoff_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_Calc_Flags_g.Bit.B0:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.B_Factor_Iref_Hi_Gain_Hi_g:100
TEST.VALUE:G5_ASIC_Control_sr.ASIC_Control_LightValueCorrect.rw_LightVoltage_l:500
TEST.VALUE:G5_ASIC_Control_sr.ASIC_Control_LightValueCorrect.rw_a_Faktor_l:500
TEST.VALUE:G5_ASIC_Control_sr.ASIC_Control_LightValueCorrect.rb_MUX_cfg_ALSx_l:0x8C
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rw_Vref_plusVoff_g:550
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_Calc_Flags_g.Bit.B0:0
TEST.EXPECTED:G5_ASIC_Control_sr.ASIC_Control_LightValueCorrect.return:21
TEST.END

-- Subprogram: ASIC_Control_LoadEEP_RegDefVal

-- Test Case: LoadEEP.001
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_LoadEEP_RegDefVal
TEST.NEW
TEST.NAME:LoadEEP.001
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_CtrReg_g[0].val:0x0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_CtrReg_g[1].val:0x0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_CtrReg_g[3].val:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_CtrReg_g[13].val:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ASIC_DIAGV_g:0xFF
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g:0x40
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ASIC_LCTR_g:0xF0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.HALIOS_Clock_Control_Reg_g:0xC
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.ACTR_Reg_g:0xD
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.FOSC_LEDUL_g:0x3
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.rb_ASICGainSetup_g:0x3
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_CtrReg_g[0].val:0x3
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_CtrReg_g[1].val:0xC
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_CtrReg_g[3].val:0xD
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_CtrReg_g[4].val:0xFC
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_CtrReg_g[13].val:0x80
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_CtrReg_g[15].val:0xF8
TEST.END

-- Subprogram: ASIC_Control_LoopMode

-- Test Case: ASIC_Control_LoopMode.001
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_LoopMode
TEST.NEW
TEST.NAME:ASIC_Control_LoopMode.001
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_wait500us_g:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_ControlFlags_g.Bit.B0:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g:0x0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_wait500us_g:2
TEST.END

-- Test Case: ASIC_Control_LoopMode.002
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_LoopMode
TEST.NEW
TEST.NAME:ASIC_Control_LoopMode.002
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_wait500us_g:2
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_CurMode_g:4
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_ControlFlags_g.Bit.B0:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rw_Loop1DelayCount_mg:400
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_SPI_flags_g.Bit.B0:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g:0x0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_wait500us_g:2
TEST.END

-- Test Case: ASIC_Control_LoopMode.003
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_LoopMode
TEST.NEW
TEST.NAME:ASIC_Control_LoopMode.003
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_wait500us_g:2
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_CurMode_g:3
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_PrevMode_g:2
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_ControlFlags_g.Bit.B0:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rw_Loop1DelayCount_mg:650
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_SPI_flags_g.Bit.B0:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g:0x0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_wait500us_g:2
TEST.END

-- Test Case: ASIC_Control_LoopMode.004
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_LoopMode
TEST.NEW
TEST.NAME:ASIC_Control_LoopMode.004
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_wait500us_g:2
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_CurMode_g:4
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_ControlFlags_g.Bit.B0:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rw_Loop1DelayCount_mg:400
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_SPI_flags_g.Bit.B0:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g:0x0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_wait500us_g:2
TEST.END

-- Test Case: ASIC_Control_LoopMode.005
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_LoopMode
TEST.NEW
TEST.NAME:ASIC_Control_LoopMode.005
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_wait500us_g:2
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_CurMode_g:2
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_ControlFlags_g.Bit.B0:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rw_Loop1DelayCount_mg:400
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_Timer_g.Bit.B2:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_InternalTemperature_g:60
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_SPI_flags_g.Bit.B0:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g:0x0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_wait500us_g:2
TEST.END

-- Test Case: ASIC_Control_LoopMode.006
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_LoopMode
TEST.NEW
TEST.NAME:ASIC_Control_LoopMode.006
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_wait500us_g:2
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_CurMode_g:2
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_ControlFlags_g.Bit.B0:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rw_Loop1DelayCount_mg:400
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_Timer_g.Bit.B2:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_InternalTemperature_g:95
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_SPI_flags_g.Bit.B0:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g:0x0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_wait500us_g:2
TEST.END

-- Subprogram: ASIC_Control_NormalOperation

-- Test Case: AC_NormalOperation.001
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_NormalOperation
TEST.NEW
TEST.NAME:AC_NormalOperation.001
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_ControlFlags_g.Bit.B0:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_ControlFlags_g.Bit.B1:1
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_ControlFlags_g.Bit.B0:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_ControlFlags_g.Bit.B1:0
TEST.END

-- Test Case: AC_NormalOperation.002
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_NormalOperation
TEST.NEW
TEST.NAME:AC_NormalOperation.002
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_ControlFlags_g.Bit.B0:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_Calc_Flags_g.Bit.B1:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_StatusRainsensor_mg.Bit.B0:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.uF_VoltageStatus_g.Bit.B0:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.uF_VoltageStatus_g.Bit.B3:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_ControlFlags_g.Bit.B0:1
TEST.END

-- Test Case: AC_NormalOperation.003
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_NormalOperation
TEST.NEW
TEST.NAME:AC_NormalOperation.003
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_ControlFlags_g.Bit.B0:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_Calc_Flags_g.Bit.B1:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_StatusRainsensor_mg.Bit.B0:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.uF_VoltageStatus_g.Bit.B0:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.uF_VoltageStatus_g.Bit.B3:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_ControlFlags_g.Bit.B0:1
TEST.END

-- Test Case: AC_NormalOperation.004
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_NormalOperation
TEST.NEW
TEST.NAME:AC_NormalOperation.004
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_ControlFlags_g.Bit.B0:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_Calc_Flags_g.Bit.B1:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ALSx_Ready_g:0x2
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_StatusRainsensor_mg.Bit.B0:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.uF_VoltageStatus_g.Bit.B0:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.uF_VoltageStatus_g.Bit.B3:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_ControlFlags_g.Bit.B0:1
TEST.END

-- Test Case: AC_NormalOperation.005
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_NormalOperation
TEST.NEW
TEST.NAME:AC_NormalOperation.005
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_ControlFlags_g.Bit.B0:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_Calc_Flags_g.Bit.B1:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ALSx_Ready_g:0x10
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_StatusRainsensor_mg.Bit.B0:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.uF_VoltageStatus_g.Bit.B0:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.uF_VoltageStatus_g.Bit.B3:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_ControlFlags_g.Bit.B0:1
TEST.END

-- Test Case: AC_NormalOperation.006
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_NormalOperation
TEST.NEW
TEST.NAME:AC_NormalOperation.006
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_ControlFlags_g.Bit.B0:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_Calc_Flags_g.Bit.B1:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ALSx_Ready_g:0x40
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_StatusRainsensor_mg.Bit.B0:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.uF_VoltageStatus_g.Bit.B0:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.uF_VoltageStatus_g.Bit.B3:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_ControlFlags_g.Bit.B0:1
TEST.END

-- Test Case: AC_NormalOperation.007
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_NormalOperation
TEST.NEW
TEST.NAME:AC_NormalOperation.007
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_ControlFlags_g.Bit.B0:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_Calc_Flags_g.Bit.B1:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ALSx_Ready_g:0x1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_StatusRainsensor_mg.Bit.B0:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.uF_VoltageStatus_g.Bit.B0:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.uF_VoltageStatus_g.Bit.B3:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_ControlFlags_g.Bit.B0:1
TEST.END

-- Test Case: AC_NormalOperation.008
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_NormalOperation
TEST.NEW
TEST.NAME:AC_NormalOperation.008
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rub_Dia_Count_dyna_Stop:0xFF
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rub_Dia_Count:250
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_ControlFlags_g.Bit.B0:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_Calc_Flags_g.Bit.B1:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ALSx_Ready_g:0x20
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_StatusRainsensor_mg.Bit.B0:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.uF_VoltageStatus_g.Bit.B0:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.uF_VoltageStatus_g.Bit.B3:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_ControlFlags_g.Bit.B0:1
TEST.END

-- Test Case: AC_NormalOperation.009
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_NormalOperation
TEST.NEW
TEST.NAME:AC_NormalOperation.009
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_LightSignalErrorCnt_g:0x7
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rub_Dia_Count_dyna_Stop:0xFF
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rub_Dia_Count:250
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_ControlFlags_g.Bit.B0:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_ControlFlags_g.Bit.B2:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_Calc_Flags_g.Bit.B1:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ALSx_Ready_g:0x20
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_ControlFlags_2_g.Bit.B2:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_StatusRainsensor_mg.Bit.B0:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.uF_VoltageStatus_g.Bit.B0:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.uF_VoltageStatus_g.Bit.B3:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_ControlFlags_g.Bit.B0:1
TEST.VALUE_USER_CODE:<<testcase>>
int i;
for (i=0;i<4;i++)
{
ASIC_Control_NormalOperation();
}
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: ASIC_Control_STBY_Meas

-- Test Case: 01_ASIC_Control_STBY_Meas
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_STBY_Meas
TEST.NEW
TEST.NAME:01_ASIC_Control_STBY_Meas
TEST.NOTES:
No rain present counter < 2:
rw_NoRainPresentCntThrsh_g = 1 -> 2

All other conditions false:
rb_Start_STBY_Meas_g = 0
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rw_NoRainPresentCntThrsh_g:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Start_STBY_Meas_g:<<MIN-1>>
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rw_NoRainPresentCntThrsh_g:2
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Start_STBY_Meas_g:<<MIN>>
TEST.END

-- Test Case: 02_ASIC_Control_STBY_Meas
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_STBY_Meas
TEST.NEW
TEST.NAME:02_ASIC_Control_STBY_Meas
TEST.NOTES:
Rain present counter == 2:
rw_NoRainPresentCntThrsh_g = 2 -> 2

All other conditions false:
rb_Start_STBY_Meas_g = 0
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rw_NoRainPresentCntThrsh_g:2
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Start_STBY_Meas_g:<<MIN-1>>
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rw_NoRainPresentCntThrsh_g:2
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Start_STBY_Meas_g:<<MIN>>
TEST.END

-- Test Case: 03_ASIC_Control_STBY_Meas
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_STBY_Meas
TEST.NEW
TEST.NAME:03_ASIC_Control_STBY_Meas
TEST.NOTES:
Rain present counter == 2:
rw_NoRainPresentCntThrsh_g = 2

Start STBY measurement true:
uF_SPI_flags_g.Bit.B0 = 0 -> 0
rb_Asic_measureMode_mg = 196 -> 196
RSStatus.Bit.B2 = 0 -> 0
b_CurMode_g = 2 -> 2
rw_NoRainPresentCnt_g >= rw_NoRainPresentCntThrsh_g: 2 >= 2
EEPROMStructPD.NO_RAIN_PRESENT_THRSH_HB_g = 0
EEPROMStructPD.NO_RAIN_PRESENT_THRSH_HB_g = 10
-> (0 << 8) + 10 = 10
Therefore:
rb_Start_STBY_Meas_g = 0 -> 1
rw_NoRainPresentCntThrsh_g = 2 -> 10 (Minimum of EEPROM)
rw_NoRainPresentCnt_g = 2 -> 0
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:196
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_CurMode_g:2
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rw_NoRainPresentCntThrsh_g:2
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Start_STBY_Meas_g:<<MIN-1>>
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rw_NoRainPresentCnt_g:2
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_SPI_flags_g.Bit.B0:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.NO_RAIN_PRESENT_THRSH_HB_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.NO_RAIN_PRESENT_THRSH_LB_g:10
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:196
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_CurMode_g:2
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rw_NoRainPresentCntThrsh_g:10
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Start_STBY_Meas_g:<<MIN>>
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rw_NoRainPresentCnt_g:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.uF_SPI_flags_g.Bit.B0:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.NO_RAIN_PRESENT_THRSH_HB_g:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.NO_RAIN_PRESENT_THRSH_LB_g:10
TEST.END

-- Test Case: 04_ASIC_Control_STBY_Meas
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_STBY_Meas
TEST.NEW
TEST.NAME:04_ASIC_Control_STBY_Meas
TEST.NOTES:
Rain present counter == 2:
rw_NoRainPresentCntThrsh_g = 2

Start STBY measurement true:
uF_SPI_flags_g.Bit.B0 = 0 -> 0
rb_Asic_measureMode_mg = 196 -> 196
RSStatus.Bit.B2 = 0 -> 0
b_CurMode_g = 2 -> 2
rw_NoRainPresentCnt_g >= rw_NoRainPresentCntThrsh_g: 2 >= 2
EEPROMStructPD.NO_RAIN_PRESENT_THRSH_HB_g = 0x1
EEPROMStructPD.NO_RAIN_PRESENT_THRSH_HB_g = 0x0
-> (0 << 8) + 10 = 256
Therefore:
rb_Start_STBY_Meas_g = 0 -> 1
rw_NoRainPresentCntThrsh_g = 2 -> 256 (EEPROM)
rw_NoRainPresentCnt_g = 2 -> 0
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:196
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_CurMode_g:2
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rw_NoRainPresentCntThrsh_g:2
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Start_STBY_Meas_g:<<MIN-1>>
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rw_NoRainPresentCnt_g:2
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_SPI_flags_g.Bit.B0:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.NO_RAIN_PRESENT_THRSH_HB_g:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.NO_RAIN_PRESENT_THRSH_LB_g:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:196
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_CurMode_g:2
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rw_NoRainPresentCntThrsh_g:256
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Start_STBY_Meas_g:<<MIN>>
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rw_NoRainPresentCnt_g:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.uF_SPI_flags_g.Bit.B0:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.NO_RAIN_PRESENT_THRSH_HB_g:1
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.NO_RAIN_PRESENT_THRSH_LB_g:0
TEST.END

-- Test Case: 05_ASIC_Control_STBY_Meas
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_STBY_Meas
TEST.NEW
TEST.NAME:05_ASIC_Control_STBY_Meas
TEST.NOTES:
Rain present counter == 2:
rw_NoRainPresentCntThrsh_g = 2

Timeout of STBY measurement:
rb_Start_STBY_Meas_g = 0
-> rb_Timeout_STBY_Meas_l = 35 -> 34

Start STBY measurement true:
uF_SPI_flags_g.Bit.B0 = 0 -> 0
rb_Asic_measureMode_mg = 196 -> 196
RSStatus.Bit.B2 = 0 -> 0
b_CurMode_g = 2 -> 2
rw_NoRainPresentCnt_g >= rw_NoRainPresentCntThrsh_g: 2 >= 2
EEPROMStructPD.NO_RAIN_PRESENT_THRSH_HB_g = 0x1
EEPROMStructPD.NO_RAIN_PRESENT_THRSH_HB_g = 0x0
-> (0 << 8) + 10 = 256
Therefore:
rb_Start_STBY_Meas_g = 0 -> 1
rw_NoRainPresentCntThrsh_g = 2 -> 256 (EEPROM)
rw_NoRainPresentCnt_g = 2 -> 0
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:196
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_CurMode_g:2
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rw_NoRainPresentCntThrsh_g:2
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Start_STBY_Meas_g:<<MIN>>
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rw_NoRainPresentCnt_g:2
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_SPI_flags_g.Bit.B0:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.NO_RAIN_PRESENT_THRSH_HB_g:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.NO_RAIN_PRESENT_THRSH_LB_g:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:196
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_CurMode_g:2
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rw_NoRainPresentCntThrsh_g:256
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Start_STBY_Meas_g:1
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rw_NoRainPresentCnt_g:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.uF_SPI_flags_g.Bit.B0:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.NO_RAIN_PRESENT_THRSH_HB_g:1
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.NO_RAIN_PRESENT_THRSH_LB_g:0
TEST.END

-- Test Case: 06_ASIC_Control_STBY_Meas
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_STBY_Meas
TEST.NEW
TEST.NAME:06_ASIC_Control_STBY_Meas
TEST.NOTES:
Rain present counter == 2:
rw_NoRainPresentCntThrsh_g = 2

Timeout of STBY measurement:
rb_Start_STBY_Meas_g = 0
-> rb_Timeout_STBY_Meas_l = 35 -> 34

Start STBY measurement true:
uF_SPI_flags_g.Bit.B0 = 0 -> 0
rb_Asic_measureMode_mg = 196 -> 196
RSStatus.Bit.B2 = 0 -> 0
b_CurMode_g = 2 -> 2
rw_NoRainPresentCnt_g >= rw_NoRainPresentCntThrsh_g: 2 >= 2
EEPROMStructPD.NO_RAIN_PRESENT_THRSH_HB_g = 0x1
EEPROMStructPD.NO_RAIN_PRESENT_THRSH_HB_g = 0x0
-> (0 << 8) + 10 = 256
Therefore:
rb_Start_STBY_Meas_g = 0 -> 1
rw_NoRainPresentCntThrsh_g = 2 -> 256 (EEPROM)
rw_NoRainPresentCnt_g = 2 -> 0


Test case user code with two loops:
First loop: CASE 0: execution
Second loop: CASE 1: execution
-> rab_SPI_ASICWriteBuffer_mg is filled and written via SPI
-> Initialise wait for integration time:
-> ras_ASIC_CtrReg_g[3] = 9:

TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:196
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_CurMode_g:<<KEEP>>
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rw_NoRainPresentCntThrsh_g:2
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_CtrReg_g[3].val:9
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_CtrReg_g[13].val:<<MIN-1>>
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_CtrReg_g[14].val:<<MIN-1>>
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_CtrReg_g[15].val:8
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_CtrReg_g[20].val:<<MAX>>
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_CtrReg_g[21].val:<<MIN-1>>
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_SPI_Data_to_send_g:<<MAX>>
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[0]:<<MIN>>
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[1]:<<MAX>>
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[3]:<<MIN-1>>
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[4]:<<MIN>>
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[5]:<<MAX>>
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[6]:<<MIN-1>>
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Start_STBY_Meas_g:<<MIN>>
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rw_NoRainPresentCnt_g:2
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_SPI_flags_g.Bit.B0:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.NO_RAIN_PRESENT_THRSH_HB_g:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.NO_RAIN_PRESENT_THRSH_LB_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.STBY_REGV_Imbalance_g:<<MIN-1>>
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:196
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_CurMode_g:5
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rw_NoRainPresentCntThrsh_g:256
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_CtrReg_g[3].val:9
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_CtrReg_g[13].val:<<MAX>>
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_CtrReg_g[14].val:<<MAX>>
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_CtrReg_g[15].val:8
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_CtrReg_g[20].val:<<MAX>>
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_CtrReg_g[21].val:<<MAX>>
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_SPI_Data_to_send_g:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[0]:91
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[1]:0x3F
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[3]:105
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[4]:0xFF
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[5]:0xF0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[6]:20
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Start_STBY_Meas_g:1
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rw_NoRainPresentCnt_g:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.uF_SPI_flags_g.Bit.B0:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.NO_RAIN_PRESENT_THRSH_HB_g:1
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.NO_RAIN_PRESENT_THRSH_LB_g:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.STBY_REGV_Imbalance_g:<<MAX>>
TEST.VALUE_USER_CODE:<<testcase>>
for(int i=0; i<2; i++)
{
     // current mode is set first to two and then to one
    (0 == i) ? (rb_CurMode_g = 2) : (rb_CurMode_g = 5);

    // call function under test with different current modes
    ASIC_Control_STBY_Meas();
}
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: 07_ASIC_Control_STBY_Meas
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_STBY_Meas
TEST.NEW
TEST.NAME:07_ASIC_Control_STBY_Meas
TEST.NOTES:
Rain present counter == 2:
rw_NoRainPresentCntThrsh_g = 2

Timeout of STBY measurement:
rb_Start_STBY_Meas_g = 0
-> rb_Timeout_STBY_Meas_l = 35 -> 34

Start STBY measurement true:
uF_SPI_flags_g.Bit.B0 = 0 -> 0
rb_Asic_measureMode_mg = 196 -> 196
RSStatus.Bit.B2 = 0 -> 0
b_CurMode_g = 2 -> 2
rw_NoRainPresentCnt_g >= rw_NoRainPresentCntThrsh_g: 2 >= 2
EEPROMStructPD.NO_RAIN_PRESENT_THRSH_HB_g = 0x1
EEPROMStructPD.NO_RAIN_PRESENT_THRSH_HB_g = 0x0
-> (0 << 8) + 10 = 256
Therefore:
rb_Start_STBY_Meas_g = 0 -> 1
rw_NoRainPresentCntThrsh_g = 2 -> 256 (EEPROM)
rw_NoRainPresentCnt_g = 2 -> 0

Test case user code with two loops:
First loop: CASE 0: execution
Second loop: if(rb_CurMode_g == 5) is false (3)
-> Aim is to branch coverage
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:196
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_CurMode_g:<<KEEP>>
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rw_NoRainPresentCntThrsh_g:2
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_CtrReg_g[3].val:8
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_CtrReg_g[13].val:<<MIN-1>>
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_CtrReg_g[14].val:<<MIN-1>>
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_CtrReg_g[15].val:8
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_CtrReg_g[20].val:<<MAX>>
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_CtrReg_g[21].val:<<MIN-1>>
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_SPI_Data_to_send_g:<<MAX>>
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[0]:<<MIN>>
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[1]:<<MAX>>
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[3]:<<MIN-1>>
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[4]:<<MIN>>
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[5]:<<MAX>>
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[6]:<<MIN-1>>
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Start_STBY_Meas_g:<<MIN>>
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rw_NoRainPresentCnt_g:2
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_SPI_flags_g.Bit.B0:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.NO_RAIN_PRESENT_THRSH_HB_g:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.NO_RAIN_PRESENT_THRSH_LB_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.STBY_REGV_Imbalance_g:<<MIN-1>>
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:196
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_CurMode_g:3
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rw_NoRainPresentCntThrsh_g:256
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_CtrReg_g[3].val:8
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_CtrReg_g[13].val:<<MAX>>
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_CtrReg_g[14].val:<<MAX>>
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_CtrReg_g[15].val:8
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_CtrReg_g[20].val:<<MAX>>
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_CtrReg_g[21].val:<<MAX>>
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_SPI_Data_to_send_g:<<MAX>>
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[0]:<<MIN>>
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[1]:<<MAX>>
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[3]:<<MAX>>
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[4]:<<MIN>>
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[5]:<<MAX>>
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[6]:<<MAX>>
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Start_STBY_Meas_g:1
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rw_NoRainPresentCnt_g:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.uF_SPI_flags_g.Bit.B0:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.NO_RAIN_PRESENT_THRSH_HB_g:1
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.NO_RAIN_PRESENT_THRSH_LB_g:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.STBY_REGV_Imbalance_g:<<MAX>>
TEST.ATTRIBUTES:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[1]:EXPECTED_BASE=16
TEST.ATTRIBUTES:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[4]:EXPECTED_BASE=16
TEST.ATTRIBUTES:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[5]:EXPECTED_BASE=16
TEST.VALUE_USER_CODE:<<testcase>>
for(int i=0; i<2; i++)
{
     // current mode is set first to two and then to one
    (0 == i) ? (rb_CurMode_g = 2) : (rb_CurMode_g = 3);

    // call function under test with different current modes
    ASIC_Control_STBY_Meas();
}
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: 08_ASIC_Control_STBY_Meas
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_STBY_Meas
TEST.NEW
TEST.NAME:08_ASIC_Control_STBY_Meas
TEST.NOTES:
(rb_Asic_measureMode_mg <= 96) ||(rb_Asic_measureMode_mg >= 96) is false
-> No measurement
-> STBY mode counter is incremented
-> STBY timeout counter is decremented

Test case user code with four (4) loops:
Loop 1: rb_wait4integration_l = 4->3
Loop 2: rb_wait4integration_l = 3->2
Loop 3: rb_wait4integration_l = 2->1
Loop 0: rb_wait4integration_l = 1->0
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:197
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Start_STBY_Meas_g:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_VoltageStatus_g.Bit.B0:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_VoltageStatus_g.Bit.B3:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:197
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Start_STBY_Meas_g:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.uF_VoltageStatus_g.Bit.B0:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.uF_VoltageStatus_g.Bit.B3:0
TEST.VALUE_USER_CODE:<<testcase>>
for(int i=4; i>0; i--)
{
   ASIC_Control_STBY_Meas();
}
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: 09_ASIC_Control_STBY_Meas
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_STBY_Meas
TEST.NEW
TEST.NAME:09_ASIC_Control_STBY_Meas
TEST.NOTES:
Rain present counter == 2:
rw_NoRainPresentCntThrsh_g = 2

Timeout of STBY measurement:
rb_Start_STBY_Meas_g = 0
-> rb_Timeout_STBY_Meas_l = 35 -> 34

Start STBY measurement true:
uF_SPI_flags_g.Bit.B0 = 0 -> 0
rb_Asic_measureMode_mg = 196 -> 196
RSStatus.Bit.B2 = 0 -> 0
b_CurMode_g = 2 -> 2
rw_NoRainPresentCnt_g >= rw_NoRainPresentCntThrsh_g: 2 >= 2
EEPROMStructPD.NO_RAIN_PRESENT_THRSH_HB_g = 0x1
EEPROMStructPD.NO_RAIN_PRESENT_THRSH_HB_g = 0x0
-> (0 << 8) + 10 = 256
Therefore:
rb_Start_STBY_Meas_g = 0 -> 1
rw_NoRainPresentCntThrsh_g = 2 -> 256 (EEPROM)
rw_NoRainPresentCnt_g = 2 -> 0


Test case user code with two loops:
First loop: CASE 0: execution
Second loop: CASE 1: execution
-> rab_SPI_ASICWriteBuffer_mg is filled and written via SPI
-> Initialise wait for integration time to 4:
-> ras_ASIC_CtrReg_g[3] = 8:

TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:196
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_CurMode_g:<<KEEP>>
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rw_NoRainPresentCntThrsh_g:2
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_CtrReg_g[3].val:9
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_CtrReg_g[13].val:<<MIN-1>>
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_CtrReg_g[14].val:<<MIN-1>>
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_CtrReg_g[15].val:8
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_CtrReg_g[20].val:<<MAX>>
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_CtrReg_g[21].val:<<MIN-1>>
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_SPI_Data_to_send_g:<<MAX>>
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[0]:<<MIN>>
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[1]:<<MAX>>
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[3]:<<MIN-1>>
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[4]:<<MIN>>
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[5]:<<MAX>>
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[6]:<<MIN-1>>
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Start_STBY_Meas_g:<<MIN>>
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rw_NoRainPresentCnt_g:2
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_SPI_flags_g.Bit.B0:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.NO_RAIN_PRESENT_THRSH_HB_g:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.NO_RAIN_PRESENT_THRSH_LB_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.STBY_REGV_Imbalance_g:<<MIN-1>>
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:196
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_CurMode_g:5
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rw_NoRainPresentCntThrsh_g:256
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_CtrReg_g[3].val:9
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_CtrReg_g[13].val:<<MAX>>
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_CtrReg_g[14].val:<<MAX>>
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_CtrReg_g[15].val:8
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_CtrReg_g[20].val:<<MAX>>
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_CtrReg_g[21].val:<<MAX>>
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_SPI_Data_to_send_g:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[0]:91
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[1]:0x3F
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[3]:105
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[4]:0xFF
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[5]:0xF0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[6]:20
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Start_STBY_Meas_g:1
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rw_NoRainPresentCnt_g:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.uF_SPI_flags_g.Bit.B0:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.NO_RAIN_PRESENT_THRSH_HB_g:1
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.NO_RAIN_PRESENT_THRSH_LB_g:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.STBY_REGV_Imbalance_g:<<MAX>>
TEST.VALUE_USER_CODE:<<testcase>>
for(int i=0; i<2; i++)
{
     // current mode is set first to two and then to one
    (0 == i) ? (rb_CurMode_g = 2) : (rb_CurMode_g = 5);

    // call function under test with different current modes
    ASIC_Control_STBY_Meas();
}
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: 10_ASIC_Control_STBY_Meas
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_STBY_Meas
TEST.NEW
TEST.NAME:10_ASIC_Control_STBY_Meas
TEST.NOTES:
Rain present counter == 2:
rw_NoRainPresentCntThrsh_g = 2

Timeout of STBY measurement:
rb_Start_STBY_Meas_g = 0
-> rb_Timeout_STBY_Meas_l = 35 -> 34

Start STBY measurement true:
uF_SPI_flags_g.Bit.B0 = 0 -> 0
rb_Asic_measureMode_mg = 196 -> 196
RSStatus.Bit.B2 = 0 -> 0
b_CurMode_g = 2 -> 2
rw_NoRainPresentCnt_g >= rw_NoRainPresentCntThrsh_g: 2 >= 2
EEPROMStructPD.NO_RAIN_PRESENT_THRSH_HB_g = 0x1
EEPROMStructPD.NO_RAIN_PRESENT_THRSH_HB_g = 0x0
-> (0 << 8) + 10 = 256
Therefore:
rb_Start_STBY_Meas_g = 0 -> 1
rw_NoRainPresentCntThrsh_g = 2 -> 256 (EEPROM)
rw_NoRainPresentCnt_g = 2 -> 0


Test case user code with six loops:
First loop: CASE 0: execution
Five loops: CASE 1: execution
-> rab_SPI_ASICWriteBuffer_mg is filled and written via SPI
-> rb_wait4integration_l reached 0

TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:196
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_CurMode_g:<<KEEP>>
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rw_NoRainPresentCntThrsh_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_CtrReg_g[3].val:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_CtrReg_g[13].val:<<MIN-1>>
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_CtrReg_g[14].val:<<MIN-1>>
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_CtrReg_g[15].val:8
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_CtrReg_g[20].val:<<MAX>>
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_CtrReg_g[21].val:<<MIN-1>>
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_SPI_Data_to_send_g:<<MAX>>
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[0]:<<MIN>>
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[1]:<<MAX>>
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[3]:<<MIN-1>>
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[4]:<<MIN>>
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[5]:<<MAX>>
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[6]:<<MIN-1>>
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Start_STBY_Meas_g:<<KEEP>>
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rw_NoRainPresentCnt_g:2
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_SPI_flags_g.Bit.B0:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.RSStatus.Bit.B2:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.NO_RAIN_PRESENT_THRSH_HB_g:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.NO_RAIN_PRESENT_THRSH_LB_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.STBY_REGV_Imbalance_g:<<MIN-1>>
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:196
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_CurMode_g:1
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rw_NoRainPresentCntThrsh_g:256
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_CtrReg_g[3].val:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_CtrReg_g[13].val:<<MAX>>
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_CtrReg_g[14].val:<<MAX>>
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_CtrReg_g[15].val:8
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_CtrReg_g[20].val:<<MAX>>
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_CtrReg_g[21].val:<<MAX>>
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_SPI_Data_to_send_g:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[0]:91
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[1]:0x3F
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[3]:105
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[4]:0xFF
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[5]:0xF0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[6]:20
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Start_STBY_Meas_g:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rw_NoRainPresentCnt_g:2
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.uF_SPI_flags_g.Bit.B0:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.RSStatus.Bit.B2:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.NO_RAIN_PRESENT_THRSH_HB_g:1
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.NO_RAIN_PRESENT_THRSH_LB_g:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.STBY_REGV_Imbalance_g:<<MAX>>
TEST.VALUE_USER_CODE:<<testcase>>
for(int i=0; i<7; i++)
{
    if(0==1)
    {
      rb_CurMode_g = 2;
      rb_Start_STBY_Meas_g = 0;
    }
    else if(1==i)
    {
       rb_CurMode_g = 5;
       rb_Start_STBY_Meas_g = 1;
    }
    else
    {
      rb_CurMode_g = 1;
      rb_Start_STBY_Meas_g = 1;
    }
    ASIC_Control_STBY_Meas();
}
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: ASIC_Control_SendReadADCmd

-- Test Case: ASIC_Control_SendReadADCmd.001
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_SendReadADCmd
TEST.NEW
TEST.NAME:ASIC_Control_SendReadADCmd.001
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_wait500us_g:<<MAX>>
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:0x90
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_newADconvRcv_g:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[0]:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[1]:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[2]:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[3]:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[4]:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[5]:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[6]:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_wait500us_g:<<MIN>>
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:0x90
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_newADconvRcv_g:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[1]:0x2A
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[2]:0x2A
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[4]:0x2A
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[5]:0x2A
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[6]:0x2A
TEST.END

-- Test Case: ASIC_Control_SendReadADCmd.002
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_SendReadADCmd
TEST.NEW
TEST.NAME:ASIC_Control_SendReadADCmd.002
TEST.NOTES:
No send and read:
rb_ASIC_ControlMode_g = 50
-> Implicit else is true. All inputs are kept
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_wait500us_g:<<MIN-1>>
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:0x90
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_newADconvRcv_g:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[0]:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[1]:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[2]:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[3]:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[4]:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[5]:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[6]:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:50
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_wait500us_g:<<MAX>>
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:0x90
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_newADconvRcv_g:1
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[0]:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[1]:0x0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[2]:0x0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[4]:0x0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[5]:0x0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[6]:0x0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:50
TEST.END

-- Test Case: ASIC_Control_SendReadADCmd.003
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_SendReadADCmd
TEST.NEW
TEST.NAME:ASIC_Control_SendReadADCmd.003
TEST.NOTES:
Next MUX configuration not active:
- rb_NextMUXCfg_g = 32 -> ( (rb_NextMUXCfg_g < 0x80) && (rb_NextMUXCfg_g %8 != 0) ) is false!
rb_wait500us_g is set to zero (0)
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_wait500us_g:<<MIN-1>>
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:32
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_newADconvRcv_g:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[0]:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[1]:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[2]:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[3]:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[4]:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[5]:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[6]:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_wait500us_g:<<MAX>>
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:0x20
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_newADconvRcv_g:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[1]:0x2A
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[2]:0x2A
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[4]:0x2A
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[5]:0x2A
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[6]:0x2A
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:0
TEST.END

-- Test Case: ASIC_Control_SendReadADCmd.004
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_SendReadADCmd
TEST.NEW
TEST.NAME:ASIC_Control_SendReadADCmd.004
TEST.NOTES:
Next MUX configuration not active:
- rb_NextMUXCfg_g = 32 -> ( (rb_NextMUXCfg_g < 0x80) && (rb_NextMUXCfg_g %8 != 0) ) is false!
rb_wait500us_g is not set to zero (0), remains <<MAX>>

Next SPI request present
-> rb_NextSPI_Request_g = 0xC

(EEPROM.ASIC_Sched_Config && 0x20) != 0
-> rab_SPI_ASICWriteBuffer_mg[rb_SPI_Data_to_send_g] = 0x12
-> rb_SPI_Data_to_send_g: 255->9
->rab_SPI_ASICWriteBuffer_mg[8] = 0x12
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_wait500us_g:<<MIN-1>>
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:0xC
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:32
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_newADconvRcv_g:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_SPI_Data_to_send_g:<<MIN-1>>
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[0]:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[1]:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[2]:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[3]:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[4]:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[5]:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[6]:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[7]:<<MIN-1>>
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[8]:<<MAX+1>>
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[15]:0x12
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g:0x20
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_wait500us_g:<<MAX>>
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:0x0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:0x20
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_newADconvRcv_g:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_SPI_Data_to_send_g:9
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[1]:0x2A
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[2]:0x2A
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[4]:0x2A
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[5]:0x2A
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[6]:0x44
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[8]:0x12
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[15]:0x12
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g:0x20
TEST.ATTRIBUTES:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[7]:EXPECTED_BASE=16
TEST.EXPECTED_GLOBALS_USER_CODE:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg.rab_SPI_ASICWriteBuffer_mg.rab_SPI_ASICWriteBuffer_mg[7]
{{ <<G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg>>[7] == ( <<G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g>> ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Test Case: ASIC_Control_SendReadADCmd.005
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_SendReadADCmd
TEST.NEW
TEST.NAME:ASIC_Control_SendReadADCmd.005
TEST.NOTES:
Next MUX configuration not active:
- rb_NextMUXCfg_g = 32 -> ( (rb_NextMUXCfg_g < 0x80) && (rb_NextMUXCfg_g %8 != 0) ) is false!
rb_wait500us_g is not set to zero (0), remains <<MAX>>

Next SPI request present
-> rb_NextSPI_Request_g = 0xC

(EEPROM.ASIC_Sched_Config && 0x20) == 0 -> by setting 0xDF
-> rab_SPI_ASICWriteBuffer_mg[rb_SPI_Data_to_send_g] = 0x12
-> rb_SPI_Data_to_send_g: 255->9
->rab_SPI_ASICWriteBuffer_mg[8] = 0x16
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_wait500us_g:<<MIN-1>>
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:0xC
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:32
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_newADconvRcv_g:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_SPI_Data_to_send_g:<<MIN-1>>
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[0]:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[1]:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[2]:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[3]:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[4]:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[5]:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[6]:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[7]:<<MIN-1>>
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[8]:<<MAX+1>>
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[15]:0x12
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g:0xDF
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_wait500us_g:<<MAX>>
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:0x0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:0x20
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_newADconvRcv_g:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_SPI_Data_to_send_g:9
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[1]:0x2A
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[2]:0x2A
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[4]:0x2A
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[5]:0x2A
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[6]:0x44
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[8]:0x16
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[15]:0x12
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g:0xDF
TEST.ATTRIBUTES:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[7]:EXPECTED_BASE=16
TEST.EXPECTED_GLOBALS_USER_CODE:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg.rab_SPI_ASICWriteBuffer_mg.rab_SPI_ASICWriteBuffer_mg[7]
{{ <<G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg>>[7] == ( <<G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g>> ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Test Case: ASIC_Control_SendReadADCmd.006
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_SendReadADCmd
TEST.NEW
TEST.NAME:ASIC_Control_SendReadADCmd.006
TEST.NOTES:
Next MUX configuration not active:
- rb_NextMUXCfg_g = 32 -> ( (rb_NextMUXCfg_g < 0x80) && (rb_NextMUXCfg_g %8 != 0) ) is false!
rb_wait500us_g is not set to zero (0), remains <<MAX>>

Next SPI request present
-> rb_NextSPI_Request_g = 0xC

(EEPROM.ASIC_Sched_Config && 0x20) == 0 -> by setting 0xDF
-> rab_SPI_ASICWriteBuffer_mg[rb_SPI_Data_to_send_g] = 0x12
-> rb_SPI_Data_to_send_g: 255->9
->rab_SPI_ASICWriteBuffer_mg[8] = 0x16

5 == rb_CurMode_g
-> uF_SPI_flags_g . Bit . B2 = 1
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_wait500us_g:<<MIN-1>>
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:0xC
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:32
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_newADconvRcv_g:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_CurMode_g:5
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_SPI_Data_to_send_g:<<MIN-1>>
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[0]:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[1]:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[2]:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[3]:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[4]:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[5]:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[6]:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[7]:<<MIN-1>>
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[8]:<<MAX+1>>
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[15]:0x12
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_SPI_flags_g.Bit.B2:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g:0xDF
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_wait500us_g:<<MAX>>
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:0x0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:0x20
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_newADconvRcv_g:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_CurMode_g:5
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_SPI_Data_to_send_g:9
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[1]:0x2A
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[2]:0x2A
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[4]:0x2A
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[5]:0x2A
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[6]:0x44
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[8]:0x16
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[15]:0x12
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.uF_SPI_flags_g.Bit.B2:1
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g:0xDF
TEST.ATTRIBUTES:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[7]:EXPECTED_BASE=16
TEST.EXPECTED_GLOBALS_USER_CODE:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg.rab_SPI_ASICWriteBuffer_mg.rab_SPI_ASICWriteBuffer_mg[7]
{{ <<G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg>>[7] == ( <<G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g>> ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Test Case: ASIC_Control_SendReadADCmd.007
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_SendReadADCmd
TEST.NEW
TEST.NAME:ASIC_Control_SendReadADCmd.007
TEST.NOTES:
Next MUX configuration not active:
- rb_NextMUXCfg_g = 32 -> ( (rb_NextMUXCfg_g < 0x80) && (rb_NextMUXCfg_g %8 != 0) ) is false!
rb_wait500us_g is not set to zero (0), remains <<MAX>>

Next SPI request = 0x3
-> rb_NextSPI_Request_g = 0x3

(EEPROM.ASIC_Sched_Config && 0x20) == 0 -> by setting 0xDF
-> rab_SPI_ASICWriteBuffer_mg[rb_SPI_Data_to_send_g] = 0x12
-> rb_SPI_Data_to_send_g: 255->7
-> ->rab_SPI_ASICWriteBuffer_mg[6] = 0x16
->rab_SPI_ASICWriteBuffer_mg[8] = 0x0 (remains unchanged)

5 == rb_CurMode_g
-> uF_SPI_flags_g . Bit . B2 = 1
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_wait500us_g:<<MIN-1>>
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:0x3
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:32
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_newADconvRcv_g:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_CurMode_g:5
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_SPI_Data_to_send_g:<<MIN-1>>
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[0]:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[1]:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[2]:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[3]:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[4]:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[5]:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[6]:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[7]:<<MIN-1>>
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[8]:<<MAX+1>>
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[15]:0x12
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_SPI_flags_g.Bit.B2:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g:0xDF
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_wait500us_g:<<MAX>>
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:0x0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:0x20
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_newADconvRcv_g:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_CurMode_g:5
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_SPI_Data_to_send_g:7
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[1]:0x2A
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[2]:0x2A
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[4]:0x2A
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[5]:0x2A
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[6]:0x16
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[7]:<<MAX>>
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[8]:<<MIN>>
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[15]:0x12
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.uF_SPI_flags_g.Bit.B2:1
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g:0xDF
TEST.ATTRIBUTES:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[7]:EXPECTED_BASE=16
TEST.ATTRIBUTES:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[8]:EXPECTED_BASE=16
TEST.END

-- Test Case: ASIC_Control_SendReadADCmd.008
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_SendReadADCmd
TEST.NEW
TEST.NAME:ASIC_Control_SendReadADCmd.008
TEST.NOTES:
Next MUX configuration not active:
- rb_NextMUXCfg_g = 32 -> ( (rb_NextMUXCfg_g < 0x80) && (rb_NextMUXCfg_g %8 != 0) ) is false!
rb_wait500us_g is not set to zero (0), remains <<MAX>>

Next SPI request = 0x3
-> rb_NextSPI_Request_g = 0x3

(EEPROM.ASIC_Sched_Config && 0x20) == 0 -> by setting 0xDF
-> rab_SPI_ASICWriteBuffer_mg[rb_SPI_Data_to_send_g] = 0x16
-> rb_SPI_Data_to_send_g: 255->7
-> ->rab_SPI_ASICWriteBuffer_mg[6] = 0x16
->rab_SPI_ASICWriteBuffer_mg[8] = 0x0 (remains unchanged)

4 == rb_CurMode_g
-> uF_SPI_flags_g . Bit . B2 = 0 (remains unchanged)
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_wait500us_g:<<MIN-1>>
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:0x3
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:32
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_newADconvRcv_g:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_CurMode_g:4
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_SPI_Data_to_send_g:<<MIN-1>>
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[0]:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[1]:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[2]:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[3]:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[4]:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[5]:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[6]:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[7]:<<MIN-1>>
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[8]:<<MAX+1>>
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[15]:0x12
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_SPI_flags_g.Bit.B2:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g:0xDF
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_wait500us_g:<<MAX>>
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:0x0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:0x20
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_newADconvRcv_g:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_CurMode_g:4
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_SPI_Data_to_send_g:7
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[1]:0x2A
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[2]:0x2A
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[4]:0x2A
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[5]:0x2A
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[6]:0x16
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[7]:<<MAX>>
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[8]:<<MIN>>
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[15]:0x12
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.uF_SPI_flags_g.Bit.B2:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g:0xDF
TEST.ATTRIBUTES:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[7]:EXPECTED_BASE=16
TEST.ATTRIBUTES:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[8]:EXPECTED_BASE=16
TEST.END

-- Test Case: ASIC_Control_SendReadADCmd.009
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_SendReadADCmd
TEST.NEW
TEST.NAME:ASIC_Control_SendReadADCmd.009
TEST.NOTES:
Next MUX configuration not active:
- rb_NextMUXCfg_g = 32 -> ( (rb_NextMUXCfg_g < 0x80) && (rb_NextMUXCfg_g %8 != 0) ) is false!
rb_wait500us_g is not set to zero (0), remains <<MAX>>

Next SPI request = 0x3
-> rb_NextSPI_Request_g = 0x3

(EEPROM.ASIC_Sched_Config && 0x20) != 0 -> by setting 0x20
-> rab_SPI_ASICWriteBuffer_mg[rb_SPI_Data_to_send_g] = 0x12
-> rb_SPI_Data_to_send_g: 255->7
-> ->rab_SPI_ASICWriteBuffer_mg[6] = 0x16
->rab_SPI_ASICWriteBuffer_mg[8] = 0x0 (remains unchanged)

4 == rb_CurMode_g
-> uF_SPI_flags_g . Bit . B2 = 0 (remains unchanged)
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_wait500us_g:<<MIN-1>>
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:0x3
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:32
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_newADconvRcv_g:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_CurMode_g:4
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_SPI_Data_to_send_g:<<MIN-1>>
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[0]:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[1]:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[2]:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[3]:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[4]:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[5]:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[6]:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[7]:<<MIN-1>>
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[8]:<<MAX+1>>
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[15]:0x12
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_SPI_flags_g.Bit.B2:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g:0x20
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_wait500us_g:<<MAX>>
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:0x0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:0x20
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_newADconvRcv_g:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_CurMode_g:4
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_SPI_Data_to_send_g:7
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[1]:0x2A
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[2]:0x2A
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[4]:0x2A
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[5]:0x2A
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[6]:0x12
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[7]:<<MAX>>
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[8]:<<MIN>>
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[15]:0x12
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.uF_SPI_flags_g.Bit.B2:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g:0x20
TEST.ATTRIBUTES:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[7]:EXPECTED_BASE=16
TEST.ATTRIBUTES:G5_ASIC_Control_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[8]:EXPECTED_BASE=16
TEST.END

-- Subprogram: ASIC_Control_Signal_Check

-- Test Case: ASIC_Control_Signal_Check.001
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_Signal_Check
TEST.NEW
TEST.NAME:ASIC_Control_Signal_Check.001
TEST.NOTES:
Set rbi_LightValuesMeasured_mg = TRUE
Mock get_rb_Vref_LightSignalErrorCnt_g() return value as 50  
check rbi_LS_Error_Vref_g is TRUE
TEST.END_NOTES:
TEST.STUB:G5_ASIC_Control_sr.get_rb_Vref_LightSignalErrorCnt_g
TEST.VALUE:G5_ASIC_Control_sr.get_rb_Vref_LightSignalErrorCnt_g.return:50
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.uF_ASIC_Calc_Flags_g.Bit.B1:1
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_Error_Flags_g.Bit.B3:1
TEST.END

-- Test Case: ASIC_Control_Signal_Check.002
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_Signal_Check
TEST.NEW
TEST.NAME:ASIC_Control_Signal_Check.002
TEST.NOTES:
Set rbi_LightValuesMeasured_mg = TRUE
Mock get_rb_Vref_LightSignalErrorCnt_g() return value as 30  
check rb_Vref_LightSignalErrorCnt_g is incremented
TEST.END_NOTES:
TEST.STUB:G5_ASIC_Control_sr.get_rb_Vref_LightSignalErrorCnt_g
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Vref_LightSignalErrorCnt_g:5
TEST.VALUE:G5_ASIC_Control_sr.get_rb_Vref_LightSignalErrorCnt_g.return:30
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.uF_ASIC_Calc_Flags_g.Bit.B1:1
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Vref_LightSignalErrorCnt_g:6
TEST.END

-- Test Case: ASIC_Control_Signal_Check.003
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_Signal_Check
TEST.NEW
TEST.NAME:ASIC_Control_Signal_Check.003
TEST.NOTES:
Set ras_ASIC_MUX_MeasAD_g[4].ad = 600
Mock get_rb_Vref_LightSignalErrorCnt_g() return value as 30  
check rb_Vref_LightSignalErrorCnt_g is decremented
TEST.END_NOTES:
TEST.STUB:G5_ASIC_Control_sr.get_rb_Vref_LightSignalErrorCnt_g
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Vref_LightSignalErrorCnt_g:5
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_MUX_MeasAD_g[4].ad:600
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_MUX_MeasAD_g[4].avg:600
TEST.VALUE:G5_ASIC_Control_sr.get_rb_Vref_LightSignalErrorCnt_g.return:30
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.uF_ASIC_Calc_Flags_g.Bit.B1:1
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Vref_LightSignalErrorCnt_g:4
TEST.END

-- Test Case: ASIC_Control_Signal_Check.004
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_Signal_Check
TEST.NEW
TEST.NAME:ASIC_Control_Signal_Check.004
TEST.NOTES:
Set rb_Vref_LightSignalErrorCnt_g as = zero 
check rbi_LS_Error_Vref_g is FAlSE
TEST.END_NOTES:
TEST.STUB:G5_ASIC_Control_sr.get_rb_Vref_LightSignalErrorCnt_g
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Vref_LightSignalErrorCnt_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_Error_Flags_g.Bit.B3:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_MUX_MeasAD_g[4].ad:600
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_MUX_MeasAD_g[4].avg:600
TEST.VALUE:G5_ASIC_Control_sr.get_rb_Vref_LightSignalErrorCnt_g.return:30
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.uF_ASIC_Calc_Flags_g.Bit.B1:1
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_Error_Flags_g.Bit.B3:0
TEST.END

-- Test Case: ASIC_Control_Signal_Check.005
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_Signal_Check
TEST.NEW
TEST.NAME:ASIC_Control_Signal_Check.005
TEST.NOTES:
Set rbi_UnderVoltage_g = TRUE and rb_LightSignalErrorCnt_g < CB_LIGHT_ERROR_THRESHOLD_MG  
Set rb_VDD_LightSignalErrorCnt_g as 5
Set rb_LEDx_newval_g as TRUE
check rb_LightSignalErrorCnt_g is 0
check rb_VDD_LightSignalErrorCnt_g for value 7
TEST.END_NOTES:
TEST.STUB:G5_ASIC_Control_sr.get_rb_Vref_LightSignalErrorCnt_g
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_LEDx_newval_g:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_VDD_LightSignalErrorCnt_g:5
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_LightSignalErrorCnt_g:30
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.uF_VoltageStatus_g.Bit.B0:1
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_VDD_LightSignalErrorCnt_g:5
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_LightSignalErrorCnt_g:0
TEST.END

-- Test Case: ASIC_Control_Signal_Check.006
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_Signal_Check
TEST.NEW
TEST.NAME:ASIC_Control_Signal_Check.006
TEST.NOTES:
Set rbi_UnderVoltage_g = TRUE and rb_LightSignalErrorCnt_g < CB_LIGHT_ERROR_THRESHOLD_MG  
Set rb_VDD_LightSignalErrorCnt_g as 5
Set rb_LEDx_newval_g as TRUE
Set rw_VLEDA_ASIC_g as 25 and rw_VLEDB_ASIC_g as 15 
check rbi_LEDx_LStop_error_g for FALSE
TEST.END_NOTES:
TEST.STUB:G5_ASIC_Control_sr.get_rb_Vref_LightSignalErrorCnt_g
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_LEDx_newval_g:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_VDD_LightSignalErrorCnt_g:5
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_LightSignalErrorCnt_g:30
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_MUX_MeasAD_g[1].avg:15
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_MUX_MeasAD_g[2].avg:15
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.uF_VoltageStatus_g.Bit.B0:1
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_VDD_LightSignalErrorCnt_g:5
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_LightSignalErrorCnt_g:0
TEST.END

-- Test Case: ASIC_Control_Signal_Check.007
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_Signal_Check
TEST.NEW
TEST.NAME:ASIC_Control_Signal_Check.007
TEST.NOTES:
Set rbi_UnderVoltage_g = TRUE and rb_LightSignalErrorCnt_g < CB_LIGHT_ERROR_THRESHOLD_MG  
Set rb_VDD_LightSignalErrorCnt_g as 5
Set rb_LEDx_newval_g as TRUE
Set rw_VLEDA_ASIC_g as 25 and rw_VLEDB_ASIC_g as 15 
Set rb_LEDx_LStop_error_cnt_g as 10
check rb_LEDx_LStop_error_cnt_g for 13
TEST.END_NOTES:
TEST.STUB:G5_ASIC_Control_sr.get_rb_Vref_LightSignalErrorCnt_g
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_LEDx_newval_g:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_VDD_LightSignalErrorCnt_g:5
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_LightSignalErrorCnt_g:30
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_LEDx_LStop_error_cnt_g:10
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_MUX_MeasAD_g[1].avg:15
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_MUX_MeasAD_g[2].avg:15
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.uF_VoltageStatus_g.Bit.B0:1
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_VDD_LightSignalErrorCnt_g:5
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_LightSignalErrorCnt_g:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_LEDx_LStop_error_cnt_g:13
TEST.END

-- Test Case: ASIC_Control_Signal_Check.008
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_Signal_Check
TEST.NEW
TEST.NAME:ASIC_Control_Signal_Check.008
TEST.NOTES:
Set rb_LEDx_LStop_error_cnt_g as 0
TEST.END_NOTES:
TEST.STUB:G5_ASIC_Control_sr.get_rb_Vref_LightSignalErrorCnt_g
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_LEDx_newval_g:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_VDD_LightSignalErrorCnt_g:5
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_LightSignalErrorCnt_g:30
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_LEDx_LStop_error_cnt_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_ControlFlags_g.Bit.B0:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.uF_VoltageStatus_g.Bit.B0:1
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_VDD_LightSignalErrorCnt_g:5
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_LightSignalErrorCnt_g:0
TEST.END

-- Test Case: ASIC_Control_Signal_Check.009
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_Signal_Check
TEST.NEW
TEST.NAME:ASIC_Control_Signal_Check.009
TEST.NOTES:
Set rb_LEDx_LStop_error_cnt_g as 0
rb_VLEDx_inLClosed_g as FALSE
check rb_LEDx_LClosed_error_cnt_g
TEST.END_NOTES:
TEST.STUB:G5_ASIC_Control_sr.get_rb_Vref_LightSignalErrorCnt_g
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_VLEDx_inLClosed_g:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_LEDx_newval_g:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_VDD_LightSignalErrorCnt_g:5
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_LightSignalErrorCnt_g:30
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_LEDx_LStop_error_cnt_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_ControlFlags_g.Bit.B0:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_LEDx_LClosed_error_cnt_g:5
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.uF_VoltageStatus_g.Bit.B0:1
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_VDD_LightSignalErrorCnt_g:5
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_LightSignalErrorCnt_g:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_LEDx_LClosed_error_cnt_g:6
TEST.END

-- Test Case: ASIC_Control_Signal_Check.010
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_Signal_Check
TEST.NEW
TEST.NAME:ASIC_Control_Signal_Check.010
TEST.NOTES:
Set rb_LEDx_LStop_error_cnt_g as 0
Set rb_LEDx_LClosed_error_cnt_g as 25
rb_VLEDx_inLClosed_g as FALSE
check rb_LEDx_LClosed_error_cnt_g
TEST.END_NOTES:
TEST.STUB:G5_ASIC_Control_sr.get_rb_Vref_LightSignalErrorCnt_g
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_VLEDx_inLClosed_g:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_LEDx_newval_g:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_VDD_LightSignalErrorCnt_g:5
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_LightSignalErrorCnt_g:30
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_LEDx_LStop_error_cnt_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_ControlFlags_g.Bit.B0:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_LEDx_LClosed_error_cnt_g:25
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.uF_VoltageStatus_g.Bit.B0:1
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_VDD_LightSignalErrorCnt_g:5
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_LightSignalErrorCnt_g:0
TEST.END

-- Test Case: ASIC_Control_Signal_Check.011
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_Signal_Check
TEST.NEW
TEST.NAME:ASIC_Control_Signal_Check.011
TEST.NOTES:

Set rb_LEDx_LClosed_error_cnt_g as 25
rb_VLEDx_inLClosed_g as FALSE
Set rw_VLEDA_ASIC_g > LEDX_LOL_THRS and  rw_VLEDB_ASIC_g > LEDX_LOL_THRS
Set rb_LEDx_LClosed_error_cnt_g = 0
check rbi_LEDx_LClosed_error_g for FALSE
TEST.END_NOTES:
TEST.STUB:G5_ASIC_Control_sr.get_rb_Vref_LightSignalErrorCnt_g
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_VLEDx_inLClosed_g:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_LEDx_newval_g:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_VDD_LightSignalErrorCnt_g:5
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_LightSignalErrorCnt_g:30
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_LEDx_LStop_error_cnt_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_ControlFlags_g.Bit.B0:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_MUX_MeasAD_g[1].avg:300
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_MUX_MeasAD_g[2].avg:300
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_LEDx_LClosed_error_cnt_g:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.uF_ASIC_Error_Flags_g.Bit.B6:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.uF_VoltageStatus_g.Bit.B0:1
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_VDD_LightSignalErrorCnt_g:5
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_LightSignalErrorCnt_g:0
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.uF_ASIC_Error_Flags_g.Bit.B6:0
TEST.END

-- Test Case: ASIC_Control_Signal_Check.012
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_Signal_Check
TEST.NEW
TEST.NAME:ASIC_Control_Signal_Check.012
TEST.NOTES:
Set rb_LEDx_LClosed_error_cnt_g as 25
rb_VLEDx_inLClosed_g as FALSE
Set rw_VLEDA_ASIC_g > LEDX_LOL_THRS and  rw_VLEDB_ASIC_g > LEDX_LOL_THRS
check rb_LEDx_LClosed_error_cnt_g is decremented
TEST.END_NOTES:
TEST.STUB:G5_ASIC_Control_sr.get_rb_Vref_LightSignalErrorCnt_g
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_VLEDx_inLClosed_g:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_LEDx_newval_g:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_VDD_LightSignalErrorCnt_g:5
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_LightSignalErrorCnt_g:30
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_LEDx_LStop_error_cnt_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_ControlFlags_g.Bit.B0:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_MUX_MeasAD_g[1].avg:300
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_MUX_MeasAD_g[2].avg:300
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_LEDx_LClosed_error_cnt_g:25
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.uF_ASIC_Error_Flags_g.Bit.B6:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.uF_VoltageStatus_g.Bit.B0:1
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_VDD_LightSignalErrorCnt_g:5
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_LightSignalErrorCnt_g:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_LEDx_LClosed_error_cnt_g:24
TEST.END

-- Test Case: ASIC_Control_Signal_Check.013
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_Signal_Check
TEST.NEW
TEST.NAME:ASIC_Control_Signal_Check.013
TEST.NOTES:

Set rb_LEDx_LClosed_error_cnt_g as 25
rb_VLEDx_inLClosed_g as FALSE
Set rw_VLEDA_ASIC_g > LEDX_LOL_THRS and  rw_VLEDB_ASIC_g > LEDX_LOL_THRS
Set rb_LEDx_LClosed_error_cnt_g = 0
check rb_LEDx_LClosed_error_cnt_g is incremented
TEST.END_NOTES:
TEST.STUB:G5_ASIC_Control_sr.get_rb_Vref_LightSignalErrorCnt_g
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_VLEDx_inLClosed_g:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_LEDx_newval_g:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_VDD_LightSignalErrorCnt_g:5
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_LightSignalErrorCnt_g:30
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_LEDx_LStop_error_cnt_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_ControlFlags_g.Bit.B0:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_MUX_MeasAD_g[1].avg:300
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_MUX_MeasAD_g[2].avg:300
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_LEDx_LClosed_error_cnt_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.FOSC_LEDUL_g:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.uF_ASIC_Error_Flags_g.Bit.B6:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.ras_ASIC_MUX_MeasAD_g[1].avg:600
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.ras_ASIC_MUX_MeasAD_g[2].avg:600
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.rb_LEDx_LClosed_error_cnt_g:5
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.uF_VoltageStatus_g.Bit.B0:1
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_VDD_LightSignalErrorCnt_g:5
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_LightSignalErrorCnt_g:0
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.rb_LEDx_LClosed_error_cnt_g:6
TEST.END

-- Test Case: ASIC_Control_Signal_Check.014
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_Signal_Check
TEST.NEW
TEST.NAME:ASIC_Control_Signal_Check.014
TEST.NOTES:

Set rb_LEDx_LClosed_error_cnt_g as 25
rb_VLEDx_inLClosed_g as FALSE
Set rw_VLEDA_ASIC_g > LEDX_LOL_THRS and  rw_VLEDB_ASIC_g > LEDX_LOL_THRS
Set rb_LEDx_LClosed_error_cnt_g = 0
check rb_LEDx_LClosed_error_cnt_g is incremented
TEST.END_NOTES:
TEST.STUB:G5_ASIC_Control_sr.get_rb_Vref_LightSignalErrorCnt_g
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_VLEDx_inLClosed_g:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_LEDx_newval_g:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_VDD_LightSignalErrorCnt_g:5
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_LightSignalErrorCnt_g:30
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_LEDx_LStop_error_cnt_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_ControlFlags_g.Bit.B0:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_MUX_MeasAD_g[1].avg:300
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_MUX_MeasAD_g[2].avg:300
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_LEDx_LClosed_error_cnt_g:25
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.FOSC_LEDUL_g:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.uF_ASIC_Error_Flags_g.Bit.B6:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.ras_ASIC_MUX_MeasAD_g[1].avg:600
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.ras_ASIC_MUX_MeasAD_g[2].avg:600
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.rb_LEDx_LClosed_error_cnt_g:5
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.uF_VoltageStatus_g.Bit.B0:1
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_VDD_LightSignalErrorCnt_g:5
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_LightSignalErrorCnt_g:0
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.rb_LEDx_LClosed_error_cnt_g:6
TEST.END

-- Test Case: ASIC_Control_Signal_Check.015
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_Signal_Check
TEST.NEW
TEST.NAME:ASIC_Control_Signal_Check.015
TEST.NOTES:
Set rbi_LightValuesMeasured_mg as TRUE
TEST.END_NOTES:
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALI_CalibAD_g[0].ad:200
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALI_CalibAD_g[0].avg:200
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALI_CalibAD_g[1].ad:700
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALI_CalibAD_g[1].avg:700
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALI_CalibAD_g[2].ad:300
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALI_CalibAD_g[2].avg:300
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALI_CalibAD_g[3].ad:700
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALI_CalibAD_g[3].avg:700
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALI_CalibAD_g[4].ad:700
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALI_CalibAD_g[4].avg:700
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALI_CalibAD_g[5].ad:200
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALI_CalibAD_g[5].avg:200
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALI_CalibAD_g[6].ad:200
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALI_CalibAD_g[6].avg:200
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALI_CalibAD_g[7].ad:700
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALI_CalibAD_g[7].avg:700
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALI_CalibAD_g[8].ad:700
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALI_CalibAD_g[8].avg:700
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALI_CalibAD_g[9].ad:200
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALI_CalibAD_g[9].avg:200
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_Calc_Flags_g.Bit.B1:1
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_Error_Flags_g.Bit.B4:0
TEST.END

-- Test Case: ASIC_Control_Signal_Check.016
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_Signal_Check
TEST.NEW
TEST.NAME:ASIC_Control_Signal_Check.016
TEST.NOTES:
Set rbi_LightValuesMeasured_mg as TRUE
TEST.END_NOTES:
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_LightSignalErrorCnt_g:5
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALI_CalibAD_g[0].ad:200
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALI_CalibAD_g[0].avg:200
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALI_CalibAD_g[1].ad:700
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALI_CalibAD_g[1].avg:700
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALI_CalibAD_g[2].ad:300
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALI_CalibAD_g[2].avg:300
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALI_CalibAD_g[3].ad:700
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALI_CalibAD_g[3].avg:700
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALI_CalibAD_g[4].ad:700
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALI_CalibAD_g[4].avg:700
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALI_CalibAD_g[5].ad:200
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALI_CalibAD_g[5].avg:200
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALI_CalibAD_g[6].ad:200
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALI_CalibAD_g[6].avg:200
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALI_CalibAD_g[7].ad:700
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALI_CalibAD_g[7].avg:700
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALI_CalibAD_g[8].ad:700
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALI_CalibAD_g[8].avg:700
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALI_CalibAD_g[9].ad:200
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALI_CalibAD_g[9].avg:200
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_Calc_Flags_g.Bit.B1:1
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_LightSignalErrorCnt_g:4
TEST.END

-- Test Case: ASIC_Control_Signal_Check.017
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_Signal_Check
TEST.NEW
TEST.NAME:ASIC_Control_Signal_Check.017
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_VDD_LightSignalErrorCnt_g:30
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_LightSignalErrorCnt_g:50
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_Calc_Flags_g.Bit.B1:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.uF_ASIC_Error_Flags_g.Bit.B4:1
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_Error_Flags_g.Bit.B4:1
TEST.END

-- Test Case: ASIC_Control_Signal_Check.018
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_Signal_Check
TEST.NEW
TEST.NAME:ASIC_Control_Signal_Check.018
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_VDD_LightSignalErrorCnt_g:30
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_LightSignalErrorCnt_g:50
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_CtrReg_g[16].val:0x0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_MUX_MeasAD_g[7].ad:400
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_MUX_MeasAD_g[7].avg:400
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_MUX_MeasAD_g[8].ad:400
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_MUX_MeasAD_g[8].avg:400
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_Calc_Flags_g.Bit.B1:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.uF_ASIC_Error_Flags_g.Bit.B4:1
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_Error_Flags_g.Bit.B4:1
TEST.END

-- Test Case: ASIC_Control_Signal_Check.019
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_Signal_Check
TEST.NEW
TEST.NAME:ASIC_Control_Signal_Check.019
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_VDD_LightSignalErrorCnt_g:12
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_LightSignalErrorCnt_g:50
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_CtrReg_g[16].val:0x0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_MUX_MeasAD_g[7].ad:400
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_MUX_MeasAD_g[7].avg:400
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_MUX_MeasAD_g[8].ad:400
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_MUX_MeasAD_g[8].avg:400
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_Calc_Flags_g.Bit.B1:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_VIref_ErrCnt_g:60
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_VoltageStatus_g.Bit.B0:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_VoltageStatus_g.Bit.B3:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.uF_ASIC_Error_Flags_g.Bit.B4:1
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_Error_Flags_g.Bit.B4:1
TEST.END

-- Subprogram: ASIC_Control_Startup_Init

-- Test Case: ACl_Startup_Init_Mode02
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_Startup_Init
TEST.NEW
TEST.NAME:ACl_Startup_Init_Mode02
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:2
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:3
TEST.END

-- Test Case: ACl_Startup_Init_Mode05
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_Startup_Init
TEST.NEW
TEST.NAME:ACl_Startup_Init_Mode05
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:5
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:6
TEST.END

-- Test Case: ACl_Startup_Init_Mode06
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_Startup_Init
TEST.NEW
TEST.NAME:ACl_Startup_Init_Mode06
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:6
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:7
TEST.END

-- Test Case: ACl_Startup_Init_Mode08
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_Startup_Init
TEST.NEW
TEST.NAME:ACl_Startup_Init_Mode08
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:8
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:9
TEST.END

-- Test Case: ACl_Startup_Init_Mode10
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_Startup_Init
TEST.NEW
TEST.NAME:ACl_Startup_Init_Mode10
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:10
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:11
TEST.END

-- Test Case: ACl_Startup_Init_Mode11
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_Startup_Init
TEST.NEW
TEST.NAME:ACl_Startup_Init_Mode11
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:11
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:12
TEST.END

-- Test Case: ACl_Startup_Init_Mode15
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_Startup_Init
TEST.NEW
TEST.NAME:ACl_Startup_Init_Mode15
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:15
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:16
TEST.END

-- Test Case: ACl_Startup_Init_Mode17
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_Startup_Init
TEST.NEW
TEST.NAME:ACl_Startup_Init_Mode17
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:17
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:14
TEST.END

-- Test Case: ACl_Startup_Init_Mode19
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_Startup_Init
TEST.NEW
TEST.NAME:ACl_Startup_Init_Mode19
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:19
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:20
TEST.END

-- Test Case: ACl_Startup_Init_Mode21
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_Startup_Init
TEST.NEW
TEST.NAME:ACl_Startup_Init_Mode21
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:21
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:22
TEST.END

-- Test Case: ACl_Startup_Init_Mode33
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_Startup_Init
TEST.NEW
TEST.NAME:ACl_Startup_Init_Mode33
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:33
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:34
TEST.END

-- Test Case: ACl_Startup_Init_Mode35
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_Startup_Init
TEST.NEW
TEST.NAME:ACl_Startup_Init_Mode35
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:35
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:36
TEST.END

-- Test Case: ACl_Startup_Init_Mode37
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_Startup_Init
TEST.NEW
TEST.NAME:ACl_Startup_Init_Mode37
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:37
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:38
TEST.END

-- Test Case: ACl_Startup_Init_Mode39
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_Startup_Init
TEST.NEW
TEST.NAME:ACl_Startup_Init_Mode39
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:39
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:40
TEST.END

-- Test Case: ACl_Startup_Init_Mode41
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_Startup_Init
TEST.NEW
TEST.NAME:ACl_Startup_Init_Mode41
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:41
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:42
TEST.END

-- Test Case: ACl_Startup_Init_Mode43
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_Startup_Init
TEST.NEW
TEST.NAME:ACl_Startup_Init_Mode43
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:43
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:44
TEST.END

-- Test Case: ACl_Startup_Init_Mode45
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_Startup_Init
TEST.NEW
TEST.NAME:ACl_Startup_Init_Mode45
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:45
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:46
TEST.END

-- Test Case: ACl_Startup_Init_Mode47
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_Startup_Init
TEST.NEW
TEST.NAME:ACl_Startup_Init_Mode47
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:47
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:48
TEST.END

-- Test Case: ACl_Startup_Init_Mode49
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_Startup_Init
TEST.NEW
TEST.NAME:ACl_Startup_Init_Mode49
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:49
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:50
TEST.END

-- Test Case: ACl_Startup_Init_Mode51
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_Startup_Init
TEST.NEW
TEST.NAME:ACl_Startup_Init_Mode51
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:51
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:52
TEST.END

-- Test Case: ACl_Startup_Init_Mode53
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_Startup_Init
TEST.NEW
TEST.NAME:ACl_Startup_Init_Mode53
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:53
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:54
TEST.END

-- Test Case: ACl_Startup_Init_Mode55
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_Startup_Init
TEST.NEW
TEST.NAME:ACl_Startup_Init_Mode55
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:55
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:56
TEST.END

-- Test Case: ACl_Startup_Init_Mode57
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_Startup_Init
TEST.NEW
TEST.NAME:ACl_Startup_Init_Mode57
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:57
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:58
TEST.END

-- Test Case: ACl_Startup_Init_Mode59
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_Startup_Init
TEST.NEW
TEST.NAME:ACl_Startup_Init_Mode59
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:59
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:60
TEST.END

-- Test Case: ACl_Startup_Init_Mode61
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_Startup_Init
TEST.NEW
TEST.NAME:ACl_Startup_Init_Mode61
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:61
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:62
TEST.END

-- Test Case: ACl_Startup_Init_Mode63
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_Startup_Init
TEST.NEW
TEST.NAME:ACl_Startup_Init_Mode63
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:63
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:64
TEST.END

-- Test Case: ACl_Startup_Init_Mode65
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_Startup_Init
TEST.NEW
TEST.NAME:ACl_Startup_Init_Mode65
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:65
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:66
TEST.END

-- Test Case: ACl_Startup_Init_Mode67
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_Startup_Init
TEST.NEW
TEST.NAME:ACl_Startup_Init_Mode67
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:67
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:68
TEST.END

-- Test Case: ACl_Startup_Init_Mode69
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_Startup_Init
TEST.NEW
TEST.NAME:ACl_Startup_Init_Mode69
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:69
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:70
TEST.END

-- Test Case: ACl_Startup_Init_Mode71
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_Startup_Init
TEST.NEW
TEST.NAME:ACl_Startup_Init_Mode71
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:71
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:72
TEST.END

-- Test Case: ACl_Startup_Init_Mode73
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_Startup_Init
TEST.NEW
TEST.NAME:ACl_Startup_Init_Mode73
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:73
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:74
TEST.END

-- Test Case: ACl_Startup_Init_Mode75
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_Startup_Init
TEST.NEW
TEST.NAME:ACl_Startup_Init_Mode75
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:75
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:76
TEST.END

-- Test Case: ACl_Startup_Init_Mode77
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_Startup_Init
TEST.NEW
TEST.NAME:ACl_Startup_Init_Mode77
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:77
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:78
TEST.END

-- Test Case: ACl_Startup_Init_Mode79
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_Startup_Init
TEST.NEW
TEST.NAME:ACl_Startup_Init_Mode79
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:79
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:80
TEST.END

-- Test Case: ACl_Startup_Init_Mode81
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_Startup_Init
TEST.NEW
TEST.NAME:ACl_Startup_Init_Mode81
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:81
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:82
TEST.END

-- Test Case: ACl_Startup_Init_Mode83
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_Startup_Init
TEST.NEW
TEST.NAME:ACl_Startup_Init_Mode83
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:83
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:84
TEST.END

-- Subprogram: ASIC_Control_StoreADVal

-- Test Case: ASIC_Control_StoreADVal.001
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_StoreADVal
TEST.NEW
TEST.NAME:ASIC_Control_StoreADVal.001
TEST.NOTES:
Set rb_CrtMUXCfg_g as 0xFA
Set rb_newADconvRcv_g as TRUE
Set rb_StaticNoValidAD_cnt_g as 7
Check rb_ASIC_ControlMode_g for 0
TEST.END_NOTES:
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_CrtMUXCfg_g:0xFA
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_newADconvRcv_g:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_StaticNoValidAD_cnt_g:7
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:0
TEST.END

-- Test Case: ASIC_Control_StoreADVal.002
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_StoreADVal
TEST.NEW
TEST.NAME:ASIC_Control_StoreADVal.002
TEST.NOTES:
Set rb_CrtMUXCfg_g as 0xFA
Set rb_newADconvRcv_g as TRUE
Set rb_StaticNoValidAD_cnt_g as 3
Check rb_ASIC_ControlMode_g for 0
TEST.END_NOTES:
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_CrtMUXCfg_g:0xFA
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_newADconvRcv_g:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_StaticNoValidAD_cnt_g:3
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:0
TEST.END

-- Test Case: ASIC_Control_StoreADVal.003
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_StoreADVal
TEST.NEW
TEST.NAME:ASIC_Control_StoreADVal.003
TEST.NOTES:
Set rb_CrtMUXCfg_g as 0xFA
Set rb_newADconvRcv_g as TRUE
Set rb_StaticNoValidAD_cnt_g as 13
Check rb_ASIC_ControlMode_g for 0
TEST.END_NOTES:
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_CrtMUXCfg_g:0xFA
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_newADconvRcv_g:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_StaticNoValidAD_cnt_g:13
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:0
TEST.END

-- Test Case: ASIC_Control_StoreADVal.004
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_StoreADVal
TEST.NEW
TEST.NAME:ASIC_Control_StoreADVal.004
TEST.NOTES:
Set rb_CrtMUXCfg_g as 0xFA
Set rb_newADconvRcv_g as FALSE
Set rb_StaticNoValidAD_cnt_g as 7
Check rb_ASIC_ControlMode_g for 0
TEST.END_NOTES:
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_CrtMUXCfg_g:0xFA
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_newADconvRcv_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_StaticNoValidAD_cnt_g:7
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:0
TEST.END

-- Test Case: ASIC_Control_StoreADVal.005
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_StoreADVal
TEST.NEW
TEST.NAME:ASIC_Control_StoreADVal.005
TEST.NOTES:
Set ras_ASIC_CtrReg_g[18] as 0x64
Set ras_ASIC_CtrReg_g[1A] as 0x64
Set rb_CrtMUXCfg_g as 0x64
Set rb_newADconvRcv_g as 1
check rb_ASIC_ALSx_Ready_g for 1
TEST.END_NOTES:
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_CrtMUXCfg_g:0x64
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_newADconvRcv_g:0x1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_CtrReg_g[24].val:100
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_CtrReg_g[26].val:0x64
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ALS1_4_Setting_g:0x3
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ALSx_Ready_g:1
TEST.ATTRIBUTES:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_CtrReg_g[18].val:INPUT_BASE=16
TEST.END

-- Test Case: ASIC_Control_StoreADVal.006
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_StoreADVal
TEST.NEW
TEST.NAME:ASIC_Control_StoreADVal.006
TEST.NOTES:
Set ras_ASIC_CtrReg_g[18] as 0x68
Set ras_ASIC_CtrReg_g[1A] as 0x68
Set rb_newADconvRcv_g as 1
Set rb_CrtMUXCfg_g as 0x68
Set CHG_MUX_ALS2 as 0x0C

Check rb_ASIC_ALSx_Ready_g for 2
TEST.END_NOTES:
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_CrtMUXCfg_g:0x68
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_newADconvRcv_g:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_CtrReg_g[24].val:0x68
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_CtrReg_g[26].val:0x68
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ALS1_4_Setting_g:0xC
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ALSx_Ready_g:2
TEST.ATTRIBUTES:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_CtrReg_g[18].val:INPUT_BASE=16
TEST.END

-- Test Case: ASIC_Control_StoreADVal.007
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_StoreADVal
TEST.NEW
TEST.NAME:ASIC_Control_StoreADVal.007
TEST.NOTES:
Set ras_ASIC_CtrReg_g[18] as 0x74
Set ras_ASIC_CtrReg_g[1A] as 0x74
Set rb_newADconvRcv_g as 1
Set rb_CrtMUXCfg_g as 0x74
Set CHG_MUX_ALS2 as 0x03

Check rb_ASIC_ALSx_Ready_g for 0x10
TEST.END_NOTES:
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_CrtMUXCfg_g:0x74
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_newADconvRcv_g:0x1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_CtrReg_g[24].val:0x74
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_CtrReg_g[26].val:0x74
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ALS5_6_INREC_Setting_g:0x3
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.rb_ASIC_ALSx_Ready_g:0x10
TEST.ATTRIBUTES:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ALS1_4_Setting_g:INPUT_BASE=16
TEST.ATTRIBUTES:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_CtrReg_g[18].val:INPUT_BASE=16
TEST.END

-- Test Case: ASIC_Control_StoreADVal.008
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_StoreADVal
TEST.NEW
TEST.NAME:ASIC_Control_StoreADVal.008
TEST.NOTES:
Set ras_ASIC_CtrReg_g[18] as 0x78
Set ras_ASIC_CtrReg_g[1A] as 0x78
Set rb_newADconvRcv_g as 1
Set rb_CrtMUXCfg_g as 0x78
Set CHG_MUX_ALS2 as 0x0C

Check rb_ASIC_ALSx_Ready_g for 0x20
TEST.END_NOTES:
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_CrtMUXCfg_g:0x78
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_newADconvRcv_g:0x1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_CtrReg_g[24].val:0x78
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_CtrReg_g[26].val:0x78
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ALS5_6_INREC_Setting_g:0xC
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.rb_ASIC_ALSx_Ready_g:0x20
TEST.ATTRIBUTES:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ALS1_4_Setting_g:INPUT_BASE=16
TEST.ATTRIBUTES:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_CtrReg_g[18].val:INPUT_BASE=16
TEST.END

-- Test Case: ASIC_Control_StoreADVal.009
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_StoreADVal
TEST.NEW
TEST.NAME:ASIC_Control_StoreADVal.009
TEST.NOTES:
Set ras_ASIC_CtrReg_g[18] as 0x7C
Set ras_ASIC_CtrReg_g[1A] as 0x7C
Set rb_newADconvRcv_g as 1
Set rb_CrtMUXCfg_g as 0x7C
Set CHG_MUX_ALS2 as 0x30

Check rb_ASIC_ALSx_Ready_g for 0x40
TEST.END_NOTES:
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_CrtMUXCfg_g:0x7C
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_newADconvRcv_g:0x1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_CtrReg_g[24].val:0x7C
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_CtrReg_g[26].val:0x7C
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ALS5_6_INREC_Setting_g:0x30
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.rb_ASIC_ALSx_Ready_g:0x40
TEST.ATTRIBUTES:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ALS1_4_Setting_g:INPUT_BASE=16
TEST.ATTRIBUTES:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_CtrReg_g[18].val:INPUT_BASE=16
TEST.END

-- Test Case: ASIC_Control_StoreADVal.010
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_StoreADVal
TEST.NEW
TEST.NAME:ASIC_Control_StoreADVal.010
TEST.NOTES:
Set ras_ASIC_CtrReg_g[18] as 0x8C
Set ras_ASIC_CtrReg_g[1A] as 0x8C
Set rb_newADconvRcv_g as 1
Set rb_CrtMUXCfg_g as 0x78
Set CHG_MUX_ALS2 as 0x0C

Check rb_ASIC_ALSx_INC_Ready_g for 1
TEST.END_NOTES:
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_CrtMUXCfg_g:0x8C
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_newADconvRcv_g:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_CtrReg_g[24].val:0x8C
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_CtrReg_g[26].val:0x8C
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ALS1_4_Setting_g:0xC
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.rb_ASIC_ALSx_INC_Ready_g:1
TEST.ATTRIBUTES:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_CtrReg_g[18].val:INPUT_BASE=16
TEST.END

-- Test Case: ASIC_Control_StoreADVal.011
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_StoreADVal
TEST.NEW
TEST.NAME:ASIC_Control_StoreADVal.011
TEST.NOTES:
Set ras_ASIC_CtrReg_g[18] as 0xAC
Set ras_ASIC_CtrReg_g[1A] as 0xAC
Set rb_newADconvRcv_g as 1
Set rb_CrtMUXCfg_g as 0xAC
Set CHG_MUX_ALS2 as 0x03

Check rb_ASIC_ALSx_INC_Ready_g for 4
TEST.END_NOTES:
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_CrtMUXCfg_g:0xAC
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_newADconvRcv_g:0x1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_CtrReg_g[24].val:0xAC
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_CtrReg_g[26].val:0xAC
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ALS5_6_INREC_Setting_g:0x3
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.rb_ASIC_ALSx_INC_Ready_g:4
TEST.ATTRIBUTES:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ALS1_4_Setting_g:INPUT_BASE=16
TEST.ATTRIBUTES:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_CtrReg_g[18].val:INPUT_BASE=16
TEST.END

-- Test Case: ASIC_Control_StoreADVal.012
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_StoreADVal
TEST.NEW
TEST.NAME:ASIC_Control_StoreADVal.012
TEST.NOTES:
Set ras_ASIC_CtrReg_g[18] as 0xBC
Set ras_ASIC_CtrReg_g[1A] as 0xBC
Set rb_newADconvRcv_g as 1
Set rb_CrtMUXCfg_g as 0xBC
Set CHG_MUX_ALS2 as 0x30

Check rb_ASIC_ALSx_INC_Ready_g for 8
TEST.END_NOTES:
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_CrtMUXCfg_g:0xBC
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_newADconvRcv_g:0x1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_CtrReg_g[24].val:0xBC
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_CtrReg_g[26].val:0xBC
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ALS5_6_INREC_Setting_g:0x30
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.rb_ASIC_ALSx_INC_Ready_g:8
TEST.ATTRIBUTES:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ALS1_4_Setting_g:INPUT_BASE=16
TEST.ATTRIBUTES:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_CtrReg_g[18].val:INPUT_BASE=16
TEST.END

-- Test Case: ASIC_Control_StoreADVal.013
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_StoreADVal
TEST.NEW
TEST.NAME:ASIC_Control_StoreADVal.013
TEST.NOTES:
Set ras_ASIC_CtrReg_g[18] as 0xBC
Set ras_ASIC_CtrReg_g[1A] as 0xBC
Set rb_newADconvRcv_g as 1
Set rb_CrtMUXCfg_g as 0xBC
Set CHG_MUX_ALS2 as 0x30

Check rb_ASIC_ALSx_INC_Ready_g for 8
TEST.END_NOTES:
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_CrtMUXCfg_g:0xE4
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_newADconvRcv_g:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_CtrReg_g[24].val:0xE4
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_CtrReg_g[26].val:0xE4
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_LEDx_newval_g:1
TEST.ATTRIBUTES:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_CtrReg_g[18].val:INPUT_BASE=16
TEST.ATTRIBUTES:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ALS1_4_Setting_g:INPUT_BASE=16
TEST.END

-- Test Case: ASIC_Control_StoreADVal.014
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_StoreADVal
TEST.NEW
TEST.NAME:ASIC_Control_StoreADVal.014
TEST.NOTES:
Set ras_ASIC_CtrReg_g[18] as 0xBC
Set ras_ASIC_CtrReg_g[1A] as 0xBC
Set rb_newADconvRcv_g as 1
Set rb_CrtMUXCfg_g as 0xBC
Set CHG_MUX_ALS2 as 0x30

Check rb_ASIC_ALSx_INC_Ready_g for 8
TEST.END_NOTES:
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_CrtMUXCfg_g:0xE3
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_newADconvRcv_g:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_CtrReg_g[24].val:0xE3
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_CtrReg_g[26].val:0xE3
TEST.ATTRIBUTES:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_CtrReg_g[18].val:INPUT_BASE=16
TEST.ATTRIBUTES:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ALS1_4_Setting_g:INPUT_BASE=16
TEST.END

-- Test Case: ASIC_Control_StoreADVal.015
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_StoreADVal
TEST.NEW
TEST.NAME:ASIC_Control_StoreADVal.015
TEST.NOTES:
Set ras_ASIC_CtrReg_g[18] as 0xBC
Set ras_ASIC_CtrReg_g[1A] as 0xBC
Set rb_newADconvRcv_g as 1
Set rb_CrtMUXCfg_g as 0xBC
Set CHG_MUX_ALS2 as 0x30

Check rb_ASIC_ALSx_INC_Ready_g for 8
TEST.END_NOTES:
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_CrtMUXCfg_g:0x60
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_newADconvRcv_g:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_CtrReg_g[24].val:0x60
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_CtrReg_g[26].val:0x60
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_CrtMUXCfg_g:0xFF
TEST.ATTRIBUTES:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_CtrReg_g[18].val:INPUT_BASE=16
TEST.ATTRIBUTES:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ALS1_4_Setting_g:INPUT_BASE=16
TEST.END

-- Test Case: ASIC_Control_StoreADVal.016
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_StoreADVal
TEST.NEW
TEST.NAME:ASIC_Control_StoreADVal.016
TEST.NOTES:
Set ras_ASIC_CtrReg_g[18] as 0xBC
Set ras_ASIC_CtrReg_g[1A] as 0xBC
Set rb_newADconvRcv_g as 1
Set rb_CrtMUXCfg_g as 0xBC
Set CHG_MUX_ALS2 as 0x30

Check rb_ASIC_ALSx_INC_Ready_g for 8
TEST.END_NOTES:
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_CrtMUXCfg_g:0xC8
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_newADconvRcv_g:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_CtrReg_g[24].val:0xC8
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_CtrReg_g[26].val:0xC8
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_CrtMUXCfg_g:0xFF
TEST.ATTRIBUTES:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_CtrReg_g[18].val:INPUT_BASE=16
TEST.ATTRIBUTES:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ALS1_4_Setting_g:INPUT_BASE=16
TEST.END

-- Test Case: ASIC_Control_StoreADVal.017
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_StoreADVal
TEST.NEW
TEST.NAME:ASIC_Control_StoreADVal.017
TEST.NOTES:
Set ras_ASIC_CtrReg_g[18] as 0xBC
Set ras_ASIC_CtrReg_g[1A] as 0xBC
Set rb_newADconvRcv_g as 1
Set rb_CrtMUXCfg_g as 0xBC
Set CHG_MUX_ALS2 as 0x30

Check rb_ASIC_ALSx_INC_Ready_g for 8
TEST.END_NOTES:
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_CrtMUXCfg_g:0xC8
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_newADconvRcv_g:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_CtrReg_g[24].val:0xC8
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_CtrReg_g[26].val:0xC8
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_CrtMUXCfg_g:0xFF
TEST.ATTRIBUTES:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_CtrReg_g[18].val:INPUT_BASE=16
TEST.ATTRIBUTES:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ALS1_4_Setting_g:INPUT_BASE=16
TEST.END

-- Subprogram: ASIC_Control_dot5msTask

-- Test Case: LightValuesInitialized
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_dot5msTask
TEST.NEW
TEST.NAME:LightValuesInitialized
TEST.NOTES:
Testcase1: normal mode
Code coverage only - 3 function calls have to be checked!
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_Calc_Flags_g.Bit.B1:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_Calc_Flags_g.Bit.B4:1
TEST.END

-- Test Case: LightValuesInitialized_noAction
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_dot5msTask
TEST.NEW
TEST.NAME:LightValuesInitialized_noAction
TEST.NOTES:
Testcase2: normal mode no action
Code coverage only - 3 function not called has to be checked!
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:FALSE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_Calc_Flags_g.Bit.B1:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_Calc_Flags_g.Bit.B4:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Start_STBY_Meas_g:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g:4
TEST.END

-- Test Case: NoLightValues
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_dot5msTask
TEST.NEW
TEST.NAME:NoLightValues
TEST.NOTES:
TestCase3: No light Values Initialised
Code coverage only - 1 function calls has to be checked!
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_Calc_Flags_g.Bit.B1:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_Calc_Flags_g.Bit.B4:0
TEST.END

-- Test Case: PowerFailMode
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_dot5msTask
TEST.NEW
TEST.NAME:PowerFailMode
TEST.NOTES:
Testcas4: PowerFail mode
Check if Globals rb_ASIC_ControlMode_g, rb_ASIC_measureMode_mg and rb_Loop1DelayCount_mg are reset to 0
TEST.END_NOTES:
TEST.STUB:G5_ASIC_Control_sr.get_rb_Asic_measureMode_mg
TEST.STUB:G5_ASIC_Control_sr.set_rb_Asic_measureMode_mg
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_Ctrl_Error_Flags_g.Bit.B3:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rw_Loop1DelayCount_mg:100
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:7
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_AfterVddPowerFailDelay_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_VoltageStatus_g.Bit.B1:1
TEST.VALUE:G5_ASIC_Control_sr.get_rb_Asic_measureMode_mg.return:5
TEST.VALUE:G5_ASIC_Control_sr.set_rb_Asic_measureMode_mg.a:7
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rw_Loop1DelayCount_mg:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:0
TEST.EXPECTED:G5_ASIC_Control_sr.set_rb_Asic_measureMode_mg.a:0
TEST.END

-- Test Case: PowerFailMode_noAction
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_dot5msTask
TEST.NEW
TEST.NAME:PowerFailMode_noAction
TEST.NOTES:
Testcas5: PowerFail mode no action
Check if Globals rb_ASIC_ControlMode_g and rb_Loop1DelayCount_mg are reset to 0
TEST.END_NOTES:
TEST.STUB:G5_ASIC_Control_sr.get_rb_Asic_measureMode_mg
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_Ctrl_Error_Flags_g.Bit.B3:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rw_Loop1DelayCount_mg:100
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:7
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_AfterVddPowerFailDelay_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_VoltageStatus_g.Bit.B1:1
TEST.VALUE:G5_ASIC_Control_sr.get_rb_Asic_measureMode_mg.return:2
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rw_Loop1DelayCount_mg:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:0
TEST.END

-- Subprogram: ASIC_Control_init

-- Test Case: AC_init.Default
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_init
TEST.NEW
TEST.NAME:AC_init.Default
TEST.NOTES:
Set rb_ASIC_ControlMode_g to unknown value (to catch default)
Check rb_ASIC_ControlMode_g is set to CASE_ASIC_CNT_MD_RESET
rb_WDG_IORefreshTaskCounter_g is increased by 1
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:254
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_WDG_IORefreshTaskCounter_g:88
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_WDG_IORefreshTaskCounter_g:89
TEST.END

-- Test Case: AC_init.ModeInitLight
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_init
TEST.NEW
TEST.NAME:AC_init.ModeInitLight
TEST.NOTES:
TestCase: Mode wait init light
Set rb_ASIC_ControlMode_g as CASE_WAIT_INIT_LIGHT
Set rbi_LightValuesMeasured_mg as TRUE
Expected
rbi_ASIC_initTimeout_err_g = FALSE
rb_ASIC_initTimeout_g = 0
rb_ASIC_ControlMode_g = CASE_WAIT_INIT_LIGHT_2
### ASIC_Control_CalcRSGain() has been called
ASIC_Control_ALS5_LightValScl(0) has been called
rb_WDG_IORefreshTaskCounter_g is increased by 1
TEST.END_NOTES:
TEST.STUB:G5_ASIC_Control_sr.ASIC_Control_ALS5_LightValScl
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_Error_Flags_g.Bit.B7:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_Calc_Flags_g.Bit.B1:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_initTimeout_g:7
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:CASE_WAIT_INIT_LIGHT
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_WDG_IORefreshTaskCounter_g:88
TEST.VALUE:G5_ASIC_Control_sr.ASIC_Control_ALS5_LightValScl.rb_filter_l:1
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_Error_Flags_g.Bit.B7:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_initTimeout_g:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:CASE_WAIT_INIT_LIGHT_2
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_WDG_IORefreshTaskCounter_g:89
TEST.EXPECTED:G5_ASIC_Control_sr.ASIC_Control_ALS5_LightValScl.rb_filter_l:0
TEST.END

-- Test Case: AC_init.ModeInitLight.001
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_init
TEST.NEW
TEST.NAME:AC_init.ModeInitLight.001
TEST.NOTES:
TestCase: Mode wait init light
Set rb_ASIC_ControlMode_g as CASE_WAIT_INIT_LIGHT
Set rbi_LightValuesMeasured_mg as FALSE
Set rbi_GotoSleep_g as TRUE
Expected
rb_ASIC_ControlMode_g = CASE_ASIC_CNT_MD_SLEEP
rb_WDG_IORefreshTaskCounter_g is increased by 1
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_Calc_Flags_g.Bit.B1:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:CASE_WAIT_INIT_LIGHT
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_SCIFlags_mg.Bit.B2:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_WDG_IORefreshTaskCounter_g:88
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:CASE_ASIC_CNT_MD_SLEEP
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_WDG_IORefreshTaskCounter_g:89
TEST.END

-- Test Case: AC_init.ModeInitLight.002
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_init
TEST.NEW
TEST.NAME:AC_init.ModeInitLight.002
TEST.NOTES:
TestCase: Mode wait init light
Set rb_ASIC_ControlMode_g as CASE_WAIT_INIT_LIGHT
Set rbi_LightValuesMeasured_mg as FALSE
Set rbi_GotoSleep_g as FALSE
Set rb_ASIC_intTimeout_g less than cb_ASIC_INITTIMEOUT_THRSH_g (here 100)
Expected
rb_ASIC_ControlMode_g = CASE_WAIT_INIT_LIGHT
check if rb_ASIC_intTimeout_g has been increased by 1
rb_WDG_IORefreshTaskCounter_g is increased by 1
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_Calc_Flags_g.Bit.B1:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_initTimeout_g:100
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:CASE_WAIT_INIT_LIGHT
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_SCIFlags_mg.Bit.B2:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_WDG_IORefreshTaskCounter_g:88
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_initTimeout_g:101
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:CASE_WAIT_INIT_LIGHT
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_WDG_IORefreshTaskCounter_g:89
TEST.END

-- Test Case: AC_init.ModeInitLight.003
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_init
TEST.NEW
TEST.NAME:AC_init.ModeInitLight.003
TEST.NOTES:
TestCase: Mode wait init light
Set rb_ASIC_ControlMode_g as CASE_WAIT_INIT_LIGHT
Set rbi_LightValuesMeasured_mg as FALSE
Set rbi_GotoSleep_g as FALSE
Set rb_ASIC_intTimeout_g as cb_ASIC_INITTIMEOUT_THRSH_g (here 200)
Expected
rb_ASIC_ControlMode_g = CASE_WAIT_INIT_LIGHT
check if rb_ASIC_intTimeout_g has not been increased
check if uF_ASIC_Error_Flags_g.Bit.B7 (rbi_ASIC_initTimeout_err_g) has been set
rb_WDG_IORefreshTaskCounter_g is increased by 1
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_Error_Flags_g.Bit.B7:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_Calc_Flags_g.Bit.B1:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_initTimeout_g:200
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:CASE_WAIT_INIT_LIGHT
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_SCIFlags_mg.Bit.B2:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_WDG_IORefreshTaskCounter_g:88
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_Error_Flags_g.Bit.B7:1
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_initTimeout_g:200
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:CASE_WAIT_INIT_LIGHT
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_WDG_IORefreshTaskCounter_g:89
TEST.END

-- Test Case: AC_init.ModeInitLight2
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_init
TEST.NEW
TEST.NAME:AC_init.ModeInitLight2
TEST.NOTES:
TestCase: Mode wait init light3
Set rb_ASIC_ControlMode_g as CASE_WAIT_INIT_LIGHT_2
Expected
rb_ASIC_ControlMode_g = CASE_WAIT_INIT_LIGHT_3
ASIC_Control_ALS2_LightValScl(0) has been called
rb_WDG_IORefreshTaskCounter_g is increased by 1
TEST.END_NOTES:
TEST.STUB:G5_ASIC_Control_sr.ASIC_Control_ALS2_LightValScl
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:6
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_WDG_IORefreshTaskCounter_g:88
TEST.VALUE:G5_ASIC_Control_sr.ASIC_Control_ALS2_LightValScl.rb_filter_l:1
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:7
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_WDG_IORefreshTaskCounter_g:89
TEST.EXPECTED:G5_ASIC_Control_sr.ASIC_Control_ALS2_LightValScl.rb_filter_l:0
TEST.END

-- Test Case: AC_init.ModeInitLight3
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_init
TEST.NEW
TEST.NAME:AC_init.ModeInitLight3
TEST.NOTES:
TestCase: Mode wait init light3
Set rb_ASIC_ControlMode_g as CASE_WAIT_INIT_LIGHT_3
Expected
rb_ASIC_ControlMode_g = CASE_WAIT_INIT_LIGHT_4
ASIC_Control_INREC_LightValScl(0) has been called
rb_WDG_IORefreshTaskCounter_g is increased by 1
TEST.END_NOTES:
TEST.STUB:G5_ASIC_Control_sr.ASIC_Control_INREC_LightValScl
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_ControlFlags_g.Bit.B1:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:CASE_WAIT_INIT_LIGHT_3
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_WDG_IORefreshTaskCounter_g:88
TEST.VALUE:G5_ASIC_Control_sr.ASIC_Control_INREC_LightValScl.rb_filterInrec_l:1
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_ControlFlags_g.Bit.B1:1
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:CASE_WAIT_INIT_LIGHT_4
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_WDG_IORefreshTaskCounter_g:89
TEST.EXPECTED:G5_ASIC_Control_sr.ASIC_Control_INREC_LightValScl.rb_filterInrec_l:0
TEST.END

-- Test Case: AC_init.ModeInitLight4
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_init
TEST.NEW
TEST.NAME:AC_init.ModeInitLight4
TEST.NOTES:
TestCase: Mode wait init light4
Set rb_ASIC_ControlMode_g as CASE_WAIT_INIT_LIGHT_4
Expected
rb_ASIC_ControlMode_g = CASE_ASIC_CNT_TEST_EN_RESET
ASIC_Control_ALS1_LightValScl(0) has been called
rb_WDG_IORefreshTaskCounter_g is increased by 1
TEST.END_NOTES:
TEST.STUB:G5_ASIC_Control_sr.ASIC_Control_ALS1_LightValScl
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_Error_Flags_g.Bit.B7:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:CASE_WAIT_INIT_LIGHT_4
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_WDG_IORefreshTaskCounter_g:88
TEST.VALUE:G5_ASIC_Control_sr.ASIC_Control_ALS1_LightValScl.rb_filter_l:1
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:CASE_ASIC_CNT_TEST_EN_RESET
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_WDG_IORefreshTaskCounter_g:89
TEST.EXPECTED:G5_ASIC_Control_sr.ASIC_Control_ALS1_LightValScl.rb_filter_l:0
TEST.END

-- Test Case: AC_init.ModeNormalOper1
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_init
TEST.NEW
TEST.NAME:AC_init.ModeNormalOper1
TEST.NOTES:
TestCase: Mode NormalOperation1
Set rb_ASIC_ControlMode_g as CASE_ASIC_CNT_MD_NORMAL
Set uF_SCIFlags_mg.Bit.B1 (rbi_ConnectedToMaster_g) as FALSE (0)
Set uF_SCIFlags_mg.Bit.B2 (rbi_GotoSleep_g) as TRUE (1)
Set uF_Main_Flags_g.Bit.B2 (rbi_EEPROMBytesToWrite_g) as TRUE (1)
Set uF_Main_Flags_g.Bit.B1 (rbi_EEPROMBytesWritten_g) as TRUE (1)
Set uF_ASIC_ControlFlags_g.Bit.B4 (rbi_ASICStandByModeRequest_g) as FALSE (0)
Expected
rb_ASIC_ControlMode_g = CASE_ASIC_CNT_MD_SLEEP
rw_TimeOutCounter_s = 1050
rw_LengthSum_s = 0
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rw_TimeOutCounter_s:67
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_ControlFlags_g.Bit.B4:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rw_LengthSum_s:22
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:CASE_ASIC_CNT_MD_NORMAL
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_SCIFlags_mg.Bit.B1:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_SCIFlags_mg.Bit.B2:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_Main_Flags_g.Bit.B1:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_Main_Flags_g.Bit.B2:1
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rw_TimeOutCounter_s:1050
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rw_LengthSum_s:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:CASE_ASIC_CNT_MD_SLEEP
TEST.END

-- Test Case: AC_init.ModeNormalOper2
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_init
TEST.NEW
TEST.NAME:AC_init.ModeNormalOper2
TEST.NOTES:
TestCase: Mode NormalOperation2
Set rb_ASIC_ControlMode_g as CASE_ASIC_CNT_MD_NORMAL
Set uF_SCIFlags_mg.Bit.B1 (rbi_ConnectedToMaster_g) as FALSE (0)
Set uF_SCIFlags_mg.Bit.B2 (rbi_GotoSleep_g) as TRUE (1)
Set uF_Main_Flags_g.Bit.B2 (rbi_EEPROMBytesToWrite_g) as TRUE (1)
Set uF_Main_Flags_g.Bit.B1 (rbi_EEPROMBytesWritten_g) as TRUE (1)
Set uF_ASIC_ControlFlags_g.Bit.B4 (rbi_ASICStandByModeRequest_g) as TRUE (1)
Set rub_LengthCounter as 87
Expected
rb_ASIC_ControlMode_g = CASE_ASIC_CNT_MD_PRE_STANDBY
rw_TimeOutCounter_s = 999
rw_LengthSum_s = 0
Check rb_LastLengthCounter_s = 87
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rw_TimeOutCounter_s:33
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_ControlFlags_g.Bit.B4:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_LastLengthCounter_s:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rw_LengthSum_s:100
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:CASE_ASIC_CNT_MD_NORMAL
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rub_LengthCounter:87
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_SCIFlags_mg.Bit.B1:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_SCIFlags_mg.Bit.B2:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_Main_Flags_g.Bit.B1:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_Main_Flags_g.Bit.B2:1
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rw_TimeOutCounter_s:999
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_LastLengthCounter_s:87
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rw_LengthSum_s:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:CASE_ASIC_CNT_MD_PRE_STANDBY
TEST.END

-- Test Case: AC_init.ModeNormalOper3
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_init
TEST.NEW
TEST.NAME:AC_init.ModeNormalOper3
TEST.NOTES:
TestCase: Mode NormalOperation3
Set rb_ASIC_ControlMode_g as CASE_ASIC_CNT_MD_NORMAL
Set uF_SCIFlags_mg.Bit.B1 (rbi_ConnectedToMaster_g) as FALSE (0)
Set uF_SCIFlags_mg.Bit.B2 (rbi_GotoSleep_g) as TRUE (1)
Set uF_Main_Flags_g.Bit.B2 (rbi_EEPROMBytesToWrite_g) as TRUE (1)
Set uF_Main_Flags_g.Bit.B1 (rbi_EEPROMBytesWritten_g) as TRUE (1)
Set uF_ASIC_ControlFlags_g.Bit.B4 (rbi_ASICStandByModeRequest_g) as TRUE (1)
Set rb_AfterVddPowerFailDelay_g > 0 (here 5)
Set rub_LengthCounter as 87
Expected
rb_ASIC_ControlMode_g = CASE_ASIC_CNT_MD_STANDBY_CLOSE_WD
Check rb_LastLengthCounter_s = 87
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_ControlFlags_g.Bit.B4:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_LastLengthCounter_s:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:CASE_ASIC_CNT_MD_NORMAL
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rub_LengthCounter:87
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_AfterVddPowerFailDelay_g:5
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_SCIFlags_mg.Bit.B1:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_SCIFlags_mg.Bit.B2:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_Main_Flags_g.Bit.B1:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_Main_Flags_g.Bit.B2:1
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_LastLengthCounter_s:87
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:CASE_ASIC_CNT_MD_STANDBY_CLOSE_WD
TEST.END

-- Test Case: AC_init.ModeNormalOper4
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_init
TEST.NEW
TEST.NAME:AC_init.ModeNormalOper4
TEST.NOTES:
TestCase: Mode NormalOperation4
Set rb_ASIC_ControlMode_g as CASE_ASIC_CNT_MD_NORMAL
Set uF_SCIFlags_mg.Bit.B1 (rbi_ConnectedToMaster_g) as FALSE (0)
Set uF_SCIFlags_mg.Bit.B2 (rbi_GotoSleep_g) as TRUE (1)
Set uF_Main_Flags_g.Bit.B2 (rbi_EEPROMBytesToWrite_g) as FALSE (0)
Set uF_Main_Flags_g.Bit.B1 (rbi_EEPROMBytesWritten_g) as FALSE (0)
Set uF_E2Flag_g.Bit.B2 (rbi_EEPROMBytesWritten_g) as TRUE (1)
Expected
rb_ASIC_ControlMode_g as CASE_ASIC_CNT_MD_NORMAL
rw_TimeOutCounter_s = 1050
rw_LengthSum_s = 0
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rw_LengthSum_s:55
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:CASE_ASIC_CNT_MD_NORMAL
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_SCIFlags_mg.Bit.B1:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_SCIFlags_mg.Bit.B2:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_E2Flag_g.Bit.B2:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_Main_Flags_g.Bit.B1:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_Main_Flags_g.Bit.B2:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rw_TimeOutCounter_s:1050
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rw_LengthSum_s:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:CASE_ASIC_CNT_MD_NORMAL
TEST.END

-- Test Case: AC_init.ModeNormalOper5
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_init
TEST.NEW
TEST.NAME:AC_init.ModeNormalOper5
TEST.NOTES:
TestCase: Mode NormalOperation5
Testcase User Code required!
Set rb_ASIC_ControlMode_g as CASE_ASIC_CNT_TEST_EN_RESET
Set rb_ASICGainSetup_g as 77
and call ASIC_Control_init() once to set Static rb_Set_ASIC_Gaindef_g equal to rb_ASICGainSetup_g

Set uF_ASIC_ControlFlags_g.Bit.B4 (rbi_ASICStandByModeRequest_g) as TRUE (1)
Set rw_TimeOutCounter_s as 500
stub ASIC_Control_STBCheckRain with return 5
and call ASIC_Control_init() 100 times (STANDBY_TIMEOUT redefined to 100 in environment user code)

Expected
rw_TimeOutCounter_s as 899
rw_StandbyTimeOutCnt_g incremented
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rw_TimeOutCounter_s:500
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_ControlFlags_g.Bit.B4:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:CASE_ASIC_CNT_TEST_EN_RESET
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASICGainSetup_g:77
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rw_StandbyTimeOutCnt_g:1
TEST.VALUE:uut_prototype_stubs.ASIC_Control_STBCheckRain.return:5
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rw_TimeOutCounter_s:899
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:CASE_ASIC_CNT_MD_NORMAL
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rw_StandbyTimeOutCnt_g:1
TEST.VALUE_USER_CODE:<<testcase>>
int i;

// 1st call with control mode CASE_ASIC_CNT_TEST_EN_RESET to set rb_Set_ASIC_Gaindef_g
ASIC_Control_init();

for(i=0; i<100; i++)
   ASIC_Control_init();
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: AC_init.ModeNormalOper6
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_init
TEST.NEW
TEST.NAME:AC_init.ModeNormalOper6
TEST.NOTES:
TestCase: Mode NormalOperation6
Set rb_ASIC_ControlMode_g as CASE_ASIC_CNT_MD_NORMAL
Set uF_SCIFlags_mg.Bit.B1 (rbi_ConnectedToMaster_g) as FALSE (0)
Set uF_SCIFlags_mg.Bit.B2 (rbi_GotoSleep_g) as FALSE (0)
Set uF_ASIC_ControlFlags_g.Bit.B4 (rbi_ASICStandByModeRequest_g) as TRUE (1)
Set rw_TimeOutCounter_s as 500
stub ASIC_Control_STBCheckRain with return 5
Set rub_LengthCounter as 87
Set rb_ASIC_GainSetup_g as 77
Expected
rb_ASIC_ControlMode_g = CASE_ASIC_CNT_MD_RESET
rw_TimeOutCounter_s as 499
uF_SCIFlags_mg.Bit.B2 (rbi_Command_CloseWindows_g) = TRUE (1)
Check rb_LastLengthCounter_s = 87
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rw_TimeOutCounter_s:500
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_ControlFlags_g.Bit.B4:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:CASE_ASIC_CNT_MD_NORMAL
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASICGainSetup_g:77
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rub_LengthCounter:87
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_SCIFlags_mg.Bit.B1:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_SCIFlags_mg.Bit.B2:0
TEST.VALUE:uut_prototype_stubs.ASIC_Control_STBCheckRain.return:5
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rw_TimeOutCounter_s:499
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_LastLengthCounter_s:87
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:CASE_ASIC_CNT_MD_RESET
TEST.END

-- Test Case: AC_init.ModePrestandby1
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_init
TEST.NEW
TEST.NAME:AC_init.ModePrestandby1
TEST.NOTES:
Set rb_ASIC_ControlMode_g as CASE_ASIC_CNT_MD_PRE_STANDBY
Set uF_SCIFlags_mg.Bit.B1 (rbi_ConnectedToMaster_g) as TRUE (1)
Check rb_ASIC_ControlMode_g = CASE_ASIC_CNT_MD_RESET
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:CASE_ASIC_CNT_MD_PRE_STANDBY
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_SCIFlags_mg.Bit.B1:1
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:CASE_ASIC_CNT_MD_RESET
TEST.END

-- Test Case: AC_init.ModePrestandby2
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_init
TEST.NEW
TEST.NAME:AC_init.ModePrestandby2
TEST.NOTES:
Set rb_ASIC_ControlMode_g as CASE_ASIC_CNT_MD_PRE_STANDBY
Set uF_SCIFlags_mg.Bit.B1 (rbi_ConnectedToMaster_g) as FALSE (0)
Set rw_TimeOutCounter_s as 500
Set rub_LengthCounter as 78
Stub ASIC_Control_STBCheckRain return as 5
Check rw_TimeOutCounter_s is decremented
Check rb_ASIC_ControlMode_g for CASE_ASIC_CNT_MD_STANDBY_CLOSE_WD
Check rb_CloseTypeStandby_g = 2
Check rb_LastLengthCounter_s = 78
### Check ASIC_Control_NormalOperation() has been called
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rw_TimeOutCounter_s:500
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:CASE_ASIC_CNT_MD_PRE_STANDBY
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_CloseTypeStandby_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rub_LengthCounter:78
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_SCIFlags_mg.Bit.B1:0
TEST.VALUE:uut_prototype_stubs.ASIC_Control_STBCheckRain.return:5
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rw_TimeOutCounter_s:499
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_LastLengthCounter_s:78
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:CASE_ASIC_CNT_MD_STANDBY_CLOSE_WD
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_CloseTypeStandby_g:2
TEST.END

-- Test Case: AC_init.ModePrestandby3
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_init
TEST.NEW
TEST.NAME:AC_init.ModePrestandby3
TEST.NOTES:
Set rb_ASIC_ControlMode_g as CASE_ASIC_CNT_MD_PRE_STANDBY
Set uF_SCIFlags_mg.Bit.B1 (rbi_ConnectedToMaster_g) as FALSE (0)
Set rw_TimeOutCounter_s as 500
Set rub_LengthCounter as 78
Stub ASIC_Control_STBCheckRain return as 0
Check rw_TimeOutCounter_s is decremented
Check rb_LastLengthCounter_s = 78
Check rb_ASIC_ControlMode_g remains CASE_ASIC_CNT_MD_PRE_STANDBY
### Check ASIC_Control_NormalOperation() has been called
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rw_TimeOutCounter_s:500
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:CASE_ASIC_CNT_MD_PRE_STANDBY
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rub_LengthCounter:78
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_SCIFlags_mg.Bit.B1:0
TEST.VALUE:uut_prototype_stubs.ASIC_Control_STBCheckRain.return:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rw_TimeOutCounter_s:499
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_LastLengthCounter_s:78
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:CASE_ASIC_CNT_MD_PRE_STANDBY
TEST.END

-- Test Case: AC_init.ModePrestandby4
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_init
TEST.NEW
TEST.NAME:AC_init.ModePrestandby4
TEST.NOTES:
Set rb_ASIC_ControlMode_g as CASE_ASIC_CNT_MD_PRE_STANDBY
Set rw_TimeOutCounter_s as 1
Set rub_LengthCounter as 78
Check uF_ASIC_ControlFlags.Bit.B3 is reset to 0
Check rb_StandbyTimeOutSecCnt_g is increased by 10
Check rb_ASIC_ControlMode_g for CASE_ASIC_CNT_MD_STANDBY
### Check ASIC_Control_NormalOperation() has been called
Check rb_LastLengthCounter_s = 78
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rw_TimeOutCounter_s:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_ControlFlags_g.Bit.B3:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_StandbyTimeOutSecCnt_g:80
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:CASE_ASIC_CNT_MD_PRE_STANDBY
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rub_LengthCounter:78
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rw_TimeOutCounter_s:1000
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_ControlFlags_g.Bit.B3:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_LastLengthCounter_s:78
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_StandbyTimeOutSecCnt_g:90
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:CASE_ASIC_CNT_MD_STANDBY
TEST.END

-- Test Case: AC_init.ModePrestandby5
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_init
TEST.NEW
TEST.NAME:AC_init.ModePrestandby5
TEST.NOTES:
Set rb_ASIC_ControlMode_g as CASE_ASIC_CNT_MD_PRE_STANDBY
Set uF_SCIFlags_mg.Bit.B1 (rbi_ConnectedToMaster_g) as FALSE (0)
Set rw_TimeOutCounter_s as 1000
Set rub_LengthCounter as 78
Check rw_TimeOutCounter_s is decremented
Check rb_ASIC_ControlMode_g remains CASE_ASIC_CNT_MD_PRE_STANDBY
### Check ASIC_Control_NormalOperation() has been called
Check rw_LengthSum_s is reset to 0
Check rb_LastLengthCounter_s = 78
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rw_TimeOutCounter_s:1000
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rw_LengthSum_s:3
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:CASE_ASIC_CNT_MD_PRE_STANDBY
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rub_LengthCounter:78
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rw_TimeOutCounter_s:999
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_LastLengthCounter_s:78
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rw_LengthSum_s:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:CASE_ASIC_CNT_MD_PRE_STANDBY
TEST.END

-- Test Case: AC_init.ModeReset
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_init
TEST.NEW
TEST.NAME:AC_init.ModeReset
TEST.NOTES:
TestCase: Mode Reset
Set rb_ASIC_ControlMode_g as CASE_ASIC_CNT_MD_RESET
Set rbi_FreqMeasureDone as TRUE
Set rbi_LightValuesMeasured_mg as TRUE
Expected
rbi_FreqMeasureDone = FALSE
rbi_LightValuesMeasured_mg = FALSE
rb_ASIC_ControlMode_g = CASE_WAIT_INIT_LIGHT
rb_Loop1DelayCount_mg is reset to 0
rb_Asic_measureMode_mg is reset to 0
rb_WDG_IORefreshTaskCounter_g is increased by 1
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:7
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_Calc_Flags_g.Bit.B1:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_Calc_Flags_g.Bit.B4:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rw_Loop1DelayCount_mg:100
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_WDG_IORefreshTaskCounter_g:88
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_Calc_Flags_g.Bit.B1:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_Calc_Flags_g.Bit.B4:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rw_Loop1DelayCount_mg:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:5
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_WDG_IORefreshTaskCounter_g:89
TEST.END

-- Test Case: AC_init.ModeReset_noReinit
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_init
TEST.NEW
TEST.NAME:AC_init.ModeReset_noReinit
TEST.NOTES:
TestCase: Mode Reset
Set rb_ASIC_ControlMode_g as CASE_ASIC_CNT_MD_RESET
Set rbi_FreqMeasureDone as FALSE
Set rbi_LightValuesMeasured_mg as FALSE
Expected
rbi_FreqMeasureDone = FALSE
rbi_LightValuesMeasured_mg = FALSE
rb_ASIC_ControlMode_g = CASE_WAIT_INIT_LIGHT
rb_Loop1DelayCount_mg is reset to 0
rb_Asic_measureMode_mg is not reset to 0
rb_WDG_IORefreshTaskCounter_g is increased by 1
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:7
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_Calc_Flags_g.Bit.B1:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_Calc_Flags_g.Bit.B4:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rw_Loop1DelayCount_mg:100
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_WDG_IORefreshTaskCounter_g:88
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:7
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_Calc_Flags_g.Bit.B1:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_Calc_Flags_g.Bit.B4:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rw_Loop1DelayCount_mg:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:5
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_WDG_IORefreshTaskCounter_g:89
TEST.END

-- Test Case: AC_init.ModeSTNDBYCloseWD
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_init
TEST.NEW
TEST.NAME:AC_init.ModeSTNDBYCloseWD
TEST.NOTES:
TestCase: Mode Standby Close WD
Set rb_ASIC_ControlMode_g as CASE_ASIC_CNT_MD_STANDBY_CLOSE_WD
Expected
rbi_SendWakeUpFrame_g = TRUE
rbi_Command_CloseWindows_g = TRUE
rbi_GotoSleep_g = FALSE
rb_ASIC_ControlMode_g = CASE_ASIC_CNT_MD_RESET
rb_WDG_IORefreshTaskCounter_g is increased by 1
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:CASE_ASIC_CNT_MD_STANDBY_CLOSE_WD
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_SCIFlags_mg.Bit.B0:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_SCIFlags_mg.Bit.B2:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_SCIFlags_mg.Bit.B4:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_WDG_IORefreshTaskCounter_g:88
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:CASE_ASIC_CNT_MD_RESET
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.uF_SCIFlags_mg.Bit.B0:1
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.uF_SCIFlags_mg.Bit.B2:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.uF_SCIFlags_mg.Bit.B4:1
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_WDG_IORefreshTaskCounter_g:89
TEST.END

-- Test Case: AC_init.ModeSleep
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_init
TEST.NEW
TEST.NAME:AC_init.ModeSleep
TEST.NOTES:
TestCase: Mode Sleep (1st call)
Set rb_ASIC_ControlMode_g as CASE_ASIC_CNT_MD_SLEEP
Set po_VoltageRegulatorEnable_g as TRUE
Expected
po_DVoltageRegulatorEnable_g = OUTPUT
po_VoltageRegulatorEnable_g = FALSE
rb_ASIC_ControlMode_g = CASE_ASIC_CNT_MD_SLEEP
rb_WDG_IORefreshTaskCounter_g is increased by 1
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.my_P3.no1:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:CASE_ASIC_CNT_MD_SLEEP
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_WDG_IORefreshTaskCounter_g:88
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.my_P3.no1:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:CASE_ASIC_CNT_MD_SLEEP
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_WDG_IORefreshTaskCounter_g:89
TEST.END

-- Test Case: AC_init.ModeSleep_noreturn
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_init
TEST.NEW
TEST.NAME:AC_init.ModeSleep_noreturn
TEST.NOTES:
TestCase: Mode Sleep (1st call)
Set rb_ASIC_ControlMode_g as CASE_ASIC_CNT_MD_SLEEP
Set po_VoltageRegulatorEnable_g as FALSE (never returns without using #define _break_)
Expected
rb_ASIC_ControlMode_g remains CASE_ASIC_CNT_MD_SLEEP
rab_InternalResetIndicator is set to empty string
### normally never returns
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:FALSE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.my_P3.no1:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:CASE_ASIC_CNT_MD_SLEEP
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rab_InternalResetIndicator:<<malloc 4>>
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rab_InternalResetIndicator:"111"
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.my_P3.no1:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:CASE_ASIC_CNT_MD_SLEEP
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rab_InternalResetIndicator:"111"
TEST.END

-- Test Case: AC_init.ModeStandby1
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_init
TEST.NEW
TEST.NAME:AC_init.ModeStandby1
TEST.NOTES:
TestCase: Mode Standby
Set rb_ASIC_ControlMode_g as CASE_ASIC_CNT_MD_STANDBY
Set rb_SevenToZeroCounter_g as cb_WDGCALLCOUNTERCYCLE_mg-2
Set uF_ASIC_ControlFlags.Bit.B3 (rbi_LIN_CommunicationsEvent_g) as FALSE (0)
Set uF_VoltageStatus.Bit.B0 (rbi_UnderVoltage_g) as FALSE (0)
Expected
Check P3_bit.no1 (po_VoltageRegulatorEnable_g) = FALSE (0)
Check if __stop() is called (my_dummy = 0xFE)
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:FALSE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.my_P3.no1:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.my_dummy:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_ControlFlags_g.Bit.B3:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:CASE_ASIC_CNT_MD_STANDBY
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_VoltageStatus_g.Bit.B0:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_SevenToZeroCounter_g:5
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.my_P3.no1:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.my_dummy:0xFE
TEST.END

-- Test Case: AC_init.ModeStandby1_noaction
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_init
TEST.NEW
TEST.NAME:AC_init.ModeStandby1_noaction
TEST.NOTES:
TestCase: Mode Standby
Set rb_ASIC_ControlMode_g as CASE_ASIC_CNT_MD_STANDBY
Set rb_SevenToZeroCounter_g as 1
Set uF_ASIC_ControlFlags.Bit.B3 (rbi_LIN_CommunicationsEvent_g) as FALSE (0)
Set uF_VoltageStatus.Bit.B0 (rbi_UnderVoltage_g) as FALSE (0)
Expected
Check if __stop() is not called (my_dummy unchanged)
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:FALSE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.my_dummy:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_ControlFlags_g.Bit.B3:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:CASE_ASIC_CNT_MD_STANDBY
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_VoltageStatus_g.Bit.B0:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_SevenToZeroCounter_g:1
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.my_dummy:0x1
TEST.END

-- Test Case: AC_init.ModeStandby2
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_init
TEST.NEW
TEST.NAME:AC_init.ModeStandby2
TEST.NOTES:
TestCase: Mode Standby
Set rb_ASIC_ControlMode_g as CASE_ASIC_CNT_MD_STANDBY
Set uF_ASIC_ControlFlags.Bit.B3 (rbi_LIN_CommunicationsEvent_g) as TRUE (1)
Set uF_VoltageStatus.Bit.B0 (rbi_UnderVoltage_g) as TRUE (1)
set rb_SevenToZeroCounter_g as 6
Expected
P3_bit.no1 (po_VoltageRegulatorEnable_g) = TRUE (1)
rb_firstReadComm_g = TRUE (1)
rb_newAsicSTAT_g = FALSE (0)
rb_WDG_RainsensorTaskCounter_g is incremented
rb_WDG_LightsensorTaskCounter_g is incremented
rb_ASIC_ControlMode_g = CASE_ASIC_CNT_MD_STANDBY_CLOSE_WD
### functions are called
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.my_P3.no1:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_newAsicSTAT_g:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_firstReadComm_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_ControlFlags_g.Bit.B3:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:CASE_ASIC_CNT_MD_STANDBY
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_VoltageStatus_g.Bit.B0:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_SPI_flags_g.Bit.B0:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_WDG_RainsensorTaskCounter_g:79
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_WDG_LightsensorTaskCounter_g:59
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_SevenToZeroCounter_g:6
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.my_P3.no1:1
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_newAsicSTAT_g:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_firstReadComm_g:1
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:CASE_ASIC_CNT_MD_STANDBY_CLOSE_WD
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_WDG_RainsensorTaskCounter_g:80
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_WDG_LightsensorTaskCounter_g:60
TEST.END

-- Test Case: AC_init.ModeStandby2_noaction
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_init
TEST.NEW
TEST.NAME:AC_init.ModeStandby2_noaction
TEST.NOTES:
TestCase: Mode Standby
Set rb_ASIC_ControlMode_g as CASE_ASIC_CNT_MD_STANDBY
Set uF_ASIC_ControlFlags.Bit.B3 (rbi_LIN_CommunicationsEvent_g) as TRUE (1)
Set uF_VoltageStatus.Bit.B0 (rbi_UnderVoltage_g) as TRUE (1)
set rb_SevenToZeroCounter_g as 1
Expected
P3_bit.no1 (po_VoltageRegulatorEnable_g) remains unchanged
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.my_P3.no1:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_ControlFlags_g.Bit.B3:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:CASE_ASIC_CNT_MD_STANDBY
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_VoltageStatus_g.Bit.B0:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_SPI_flags_g.Bit.B0:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_SevenToZeroCounter_g:1
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.my_P3.no1:1
TEST.END

-- Test Case: AC_init.ModeStandby2_reset
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_init
TEST.NEW
TEST.NAME:AC_init.ModeStandby2_reset
TEST.NOTES:
TestCase: Mode Standby
Set rb_ASIC_ControlMode_g as CASE_ASIC_CNT_MD_STANDBY
Set uF_ASIC_ControlFlags.Bit.B3 (rbi_LIN_CommunicationsEvent_g) as TRUE (1)
Set uF_VoltageStatus.Bit.B0 (rbi_UnderVoltage_g) as FALSE (0)
set rb_SevenToZeroCounter_g as 6
Expected
P3_bit.no1 (po_VoltageRegulatorEnable_g) = TRUE (1)
rb_firstReadComm_g = TRUE (1)
rb_newAsicSTAT_g = FALSE (0)
rb_WDG_RainsensorTaskCounter_g is incremented
rb_WDG_LightsensorTaskCounter_g is incremented
rb_ASIC_ControlMode_g = CASE_ASIC_CNT_MD_STANDBY_RESET
### functions are called
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.my_P3.no1:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_newAsicSTAT_g:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_firstReadComm_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_ControlFlags_g.Bit.B3:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:CASE_ASIC_CNT_MD_STANDBY
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_VoltageStatus_g.Bit.B0:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_SPI_flags_g.Bit.B0:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_WDG_RainsensorTaskCounter_g:79
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_WDG_LightsensorTaskCounter_g:59
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_SevenToZeroCounter_g:6
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.my_P3.no1:1
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_newAsicSTAT_g:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_firstReadComm_g:1
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:CASE_ASIC_CNT_MD_RESET
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_WDG_RainsensorTaskCounter_g:80
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_WDG_LightsensorTaskCounter_g:60
TEST.END

-- Test Case: AC_init.ModeTestENReset
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_init
TEST.NEW
TEST.NAME:AC_init.ModeTestENReset
TEST.NOTES:
TestCase: Mode test en Reset
Set rb_ASIC_ControlMode_g as CASE_ASIC_CNT_TEST_EN_RESET
Expected
rbi_Modulator_On_g = TRUE (1)
rb_ASIC_ControlMode_g = CASE_ASIC_CNT_MD_NORMAL
rw_TimeOutCounter = TIME_FOR_STANDBY_NORMAL_MEASURE
rw_LengthSum_s = 0
ASIC_Control_ALS6_LightValScl(0) has been called
rb_WDG_IORefreshTaskCounter_g is increased by 1
TEST.END_NOTES:
TEST.STUB:G5_ASIC_Control_sr.ASIC_Control_ALS6_LightValScl
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rw_TimeOutCounter_s:50
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_ControlFlags_g.Bit.B0:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rw_LengthSum_s:7
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:CASE_ASIC_CNT_TEST_EN_RESET
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_WDG_IORefreshTaskCounter_g:88
TEST.VALUE:G5_ASIC_Control_sr.ASIC_Control_ALS6_LightValScl.rb_filter_l:7
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rw_TimeOutCounter_s:1000
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_ControlFlags_g.Bit.B0:1
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rw_LengthSum_s:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:CASE_ASIC_CNT_MD_NORMAL
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_WDG_IORefreshTaskCounter_g:89
TEST.EXPECTED:G5_ASIC_Control_sr.ASIC_Control_ALS6_LightValScl.rb_filter_l:0
TEST.END

-- Subprogram: ASIC_Control_init_Caller

-- Test Case: NoReset
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_init_Caller
TEST.NEW
TEST.NAME:NoReset
TEST.NOTES:
Testcase1:
Set rb_AfterVddPowerFailDelay_g as 1
Set uF_SCIFlags_mg.Bit.B1 (rbi_ConnectedToMaster_g) as FALSE (0) and
    uF_SCIFlags_mg.Bit.B2 (rbi_GotoSleep_g) as TRUE (1)
Set rb_ASIC_ControlMode_g as 60 to prevent 'Allow to go to reset'
Check Global rb_ASIC_ControlMode_g for 0 (set by ASIC_Control_init() when rb_ASIC_ControlMode_g is set to 60)
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:60
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_AfterVddPowerFailDelay_g:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_SCIFlags_mg.Bit.B1:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_SCIFlags_mg.Bit.B2:1
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:0
TEST.END

-- Test Case: NoSleepNoPowerfail
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_init_Caller
TEST.NEW
TEST.NAME:NoSleepNoPowerfail
TEST.NOTES:
Testcase2: Test the No Sleep and Powerfail or Slowtimer
Set rb_AfterVddPowerFailDelay_g as 1
Set uF_SCIFlags_mg.Bit.B2 (rbi_GotoSleep_g) as FALSE (0)
Expected:
The rb_WDG_IORefreshTaskCounter_g is incremented
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_AfterVddPowerFailDelay_g:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_SCIFlags_mg.Bit.B2:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_WDG_IORefreshTaskCounter_g:5
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_WDG_IORefreshTaskCounter_g:6
TEST.END

-- Test Case: NotConnectedToMaster
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_init_Caller
TEST.NEW
TEST.NAME:NotConnectedToMaster
TEST.NOTES:
Testcase3: Test Not Connected to Master and allow to go to reset
Set rb_AfterVddPowerFailDelay_g as 1
Set uF_SCIFlags_mg.Bit.B1 (rbi_ConnectedToMaster_g) as FALSE (0) and
    uF_SCIFlags_mg.Bit.B2 (rbi_GotoSleep_g) as TRUE (1)
Set rb_ASIC_ControlMode_g as 77 to allow 'Allow to go to reset'
Expected:
rb_ASIC_ControlMode_g is set to CASE_ASIC_CNT_MD_NORMAL (12)
TEST.END_NOTES:
TEST.STUB:G5_ASIC_Control_sr.ASIC_Control_init
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:77
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_AfterVddPowerFailDelay_g:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_SCIFlags_mg.Bit.B1:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_SCIFlags_mg.Bit.B2:1
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:CASE_ASIC_CNT_MD_NORMAL
TEST.END

-- Test Case: PowerFailDelay
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_init_Caller
TEST.NEW
TEST.NAME:PowerFailDelay
TEST.NOTES:
Testcase4: Vdd power fail delay is 0
TEST.END_NOTES:
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_AfterVddPowerFailDelay_g:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_AfterVddPowerFailDelay_g:0
TEST.END

-- Subprogram: ASIC_Control_measure

-- Test Case: AC_measureCase00
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_measure
TEST.NEW
TEST.NAME:AC_measureCase00
TEST.NOTES:
Set rb_Asic_measureMode_mg as 0
Set EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g (rb_ASIC_Sched_Config_g) as 0
Set rb_RainMeas_cnt_g a value not 100 and not 0 (here 23)
Check rb_RainMeas_cnt_min_g is set to rb_RainMeas_cnt_g (here 23)
Check rb_LClosed_dur_min_g is set to 0 (from initialized static rb_LClosed_dur_cnt_l)
Check rb_NextSPI_Request_g for CB_STMEAS_RQ (3)
Check function ASIC_Control_ChangeModeCmd(4) is called
TEST.END_NOTES:
TEST.STUB:G5_ASIC_Control_sr.ASIC_Control_ChangeModeCmd
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_RainMeas_cnt_min_g:66
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_LClosed_dur_min_g:45
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_RainMeas_cnt_g:23
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:CB_STMEAS_RQ
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_RainMeas_cnt_min_g:23
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_LClosed_dur_min_g:0
TEST.EXPECTED:G5_ASIC_Control_sr.ASIC_Control_ChangeModeCmd.next_mode:4
TEST.ATTRIBUTES:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:EXPECTED_BASE=16
TEST.END

-- Test Case: AC_measureCase00.01
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_measure
TEST.NEW
TEST.NAME:AC_measureCase00.01
TEST.NOTES:
Set rb_Asic_measureMode_mg as 40
Set EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g (rb_ASIC_Sched_Config_g) as 0x40
Set rb_NextSPI_Request_g as 1
Set rb_NextMUXCfg_g as 3
Check rb_CrtMUXCfg_g is set to rb_NextMUXCfg_g (here 3)
Check rb_ASIC_ControlMode_g is set to CASE_ASIC_CNT_MD_RESET (0)
Check rw_SPINoCommCounter_g is increased by 0xF00
Check rb_old_ASIC_Sched_Config_g is set to rb_ASIC_Sched_Config_g (here 0x40)
Check rb_NextSPI_Request_g remains unchanged
Check if rb_Asic_measureMode_mg is increased
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:40
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_old_ASIC_Sched_Config_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:0x1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:3
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_CrtMUXCfg_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:33
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rw_SPINoCommCounter_g:0xF00
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g:0x40
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:41
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_old_ASIC_Sched_Config_g:0x40
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:0x1
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_CrtMUXCfg_g:3
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:CASE_ASIC_CNT_MD_RESET
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rw_SPINoCommCounter_g:0xF00
TEST.END

-- Test Case: AC_measureCase01
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_measure
TEST.NEW
TEST.NAME:AC_measureCase01
TEST.NOTES:
Set rb_Asic_measureMode_mg as 1
Set EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g (rb_ASIC_Sched_Config_g) as 0
Stub function ASIC_Control_SendReadADCmd()
Check rb_RainMeas_cnt_total_g is set to 0 (from initialized static rb_tempRainMeas_cnt_l)
Check rb_LClosed_dur_total_g is set to 0 (from initialized static rb_tempLClosed_dur_total_l)
Check rb_NextMUXCfg_g is set to CHG_MUX_ALS1 setting (4)
Check rb_NextSPI_Request_g for CB_CHG_MUX_STMEAS_RQ (0xC)
Check rb_Asic_measureMode is increased
TEST.END_NOTES:
TEST.STUB:G5_ASIC_Control_sr.ASIC_Control_SendReadADCmd
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_RainMeas_cnt_total_g:22
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_LClosed_dur_total_g:33
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:2
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:CB_CHG_MUX_STMEAS_RQ
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:4
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_RainMeas_cnt_total_g:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_LClosed_dur_total_g:0
TEST.ATTRIBUTES:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:EXPECTED_BASE=16
TEST.END

-- Test Case: AC_measureCase01.01
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_measure
TEST.NEW
TEST.NAME:AC_measureCase01.01
TEST.NOTES:
Set rb_Asic_measureMode_mg as 1
Set EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g (rb_ASIC_Sched_Config_g) as 0x1
Stub function ASIC_Control_SendReadADCmd()
Check rb_NextMUXCfg_g remains unchanged
Check rb_NextSPI_Request_g remains unchanged
Check rb_Asic_measureMode is increased
TEST.END_NOTES:
TEST.STUB:G5_ASIC_Control_sr.ASIC_Control_SendReadADCmd
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:7
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:8
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g:0x1
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:2
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:0x7
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:8
TEST.END

-- Test Case: AC_measureCase03
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_measure
TEST.NEW
TEST.NAME:AC_measureCase03
TEST.NOTES:
Set rb_Asic_measureMode_mg as 3
Set EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g (rb_ASIC_Sched_Config_g) as 0
Stub function ASIC_Control_SendReadADCmd()
Check rb_NextMUXCfg_g is set to MEAS_RSI_AMP setting (220)
Check rb_NextSPI_Request_g for CB_CHG_MUX_STMEAS_RQ (0xC)
TEST.END_NOTES:
TEST.STUB:G5_ASIC_Control_sr.ASIC_Control_SendReadADCmd
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:3
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:0xC
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:220
TEST.END

-- Test Case: AC_measureCase03.01
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_measure
TEST.NEW
TEST.NAME:AC_measureCase03.01
TEST.NOTES:
Set rb_Asic_measureMode_mg as 3
Set EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g (rb_ASIC_Sched_Config_g) as 0x2
Stub function ASIC_Control_SendReadADCmd()
Check rb_NextMUXCfg_g remains unchanged
Check rb_NextSPI_Request_g remains unchanged
TEST.END_NOTES:
TEST.STUB:G5_ASIC_Control_sr.ASIC_Control_SendReadADCmd
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:3
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:7
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:8
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g:0x2
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:0x7
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:8
TEST.END

-- Test Case: AC_measureCase05
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_measure
TEST.NEW
TEST.NAME:AC_measureCase05
TEST.NOTES:
Set rb_Asic_measureMode_mg as 5
Set EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g (rb_ASIC_Sched_Config_g) as 0
Stub function ASIC_Control_SendReadADCmd()
Check rb_wait500us is set to 0
Check rb_NextMUXCfg_g is set to MEAS_VDIAG_LEDA setting (224)
Check rb_NextSPI_Request_g for CB_CHG_MUX_STMEAS_RQ (0xC)
TEST.END_NOTES:
TEST.STUB:G5_ASIC_Control_sr.ASIC_Control_SendReadADCmd
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:5
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_wait500us_g:100
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_wait500us_g:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:0xC
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:224
TEST.END

-- Test Case: AC_measureCase05.01
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_measure
TEST.NEW
TEST.NAME:AC_measureCase05.01
TEST.NOTES:
Set rb_Asic_measureMode_mg as 5
Set EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g (rb_ASIC_Sched_Config_g) as 0x2
Stub function ASIC_Control_SendReadADCmd()
Check rb_NextMUXCfg_g remains unchanged
Check rb_NextSPI_Request_g remains unchanged
TEST.END_NOTES:
TEST.STUB:G5_ASIC_Control_sr.ASIC_Control_SendReadADCmd
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:5
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:7
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:8
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g:0x2
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:7
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:8
TEST.END

-- Test Case: AC_measureCase07
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_measure
TEST.NEW
TEST.NAME:AC_measureCase07
TEST.NOTES:
Set rb_Asic_measureMode_mg as 7
Set EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g (rb_ASIC_Sched_Config_g) as 0
Set rb_CurMode_g as CB_ASIC_LSTOP_MD (4)
Stub function ASIC_Control_SendReadADCmd()
Check rb_wait500us is set to 0
Check rb_NextMUXCfg_g is set to MEAS_VDIAG_LEDB setting (228)
Check rb_NextSPI_Request_g for CB_CHG_MUX_STMEAS_RQ (0xC)
TEST.END_NOTES:
TEST.STUB:G5_ASIC_Control_sr.ASIC_Control_SendReadADCmd
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:7
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_wait500us_g:33
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_CurMode_g:CB_ASIC_LSTOP_MD
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_wait500us_g:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:0xC
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:228
TEST.END

-- Test Case: AC_measureCase07.01
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_measure
TEST.NEW
TEST.NAME:AC_measureCase07.01
TEST.NOTES:
Set rb_Asic_measureMode_mg as 7
Set EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g (rb_ASIC_Sched_Config_g) as 0
Set rb_CurMode_g != CB_ASIC_LSTOP_MD (here 3)
Stub function ASIC_Control_SendReadADCmd()
Check rb_wait500us is set to 0
Check rb_NextMUXCfg_g is set to MEAS_VDIAG_LEDB setting (228)
Check rb_NextSPI_Request_g for CB_CHG_MUX_STMEAS_RQ (0xC)
TEST.END_NOTES:
TEST.STUB:G5_ASIC_Control_sr.ASIC_Control_SendReadADCmd
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:7
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_wait500us_g:33
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_CurMode_g:3
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_wait500us_g:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:0xC
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:228
TEST.END

-- Test Case: AC_measureCase07.02
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_measure
TEST.NEW
TEST.NAME:AC_measureCase07.02
TEST.NOTES:
Set rb_Asic_measureMode_mg as 7
Set EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g (rb_ASIC_Sched_Config_g) as 0x2
Stub function ASIC_Control_SendReadADCmd()
Check rb_NextMUXCfg_g remains unchanged
Check rb_NextSPI_Request_g remains unchanged
TEST.END_NOTES:
TEST.STUB:G5_ASIC_Control_sr.ASIC_Control_SendReadADCmd
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:7
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:3
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:8
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_CurMode_g:4
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g:0x2
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:3
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:8
TEST.END

-- Test Case: AC_measureCase09
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_measure
TEST.NEW
TEST.NAME:AC_measureCase09
TEST.NOTES:
Set rb_Asic_measureMode_mg as 9
Set EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g (rb_ASIC_Sched_Config_g) as 0
Stub function ASIC_Control_SendReadADCmd()
Check rb_NextMUXCfg_g is set to CAL_IHI_ILO_GLO setting (32)
Check rb_NextSPI_Request_g for CB_CHG_MUX_STMEAS_RQ (0xC)
TEST.END_NOTES:
TEST.STUB:G5_ASIC_Control_sr.ASIC_Control_SendReadADCmd
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:9
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:0xC
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:32
TEST.END

-- Test Case: AC_measureCase09.01
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_measure
TEST.NEW
TEST.NAME:AC_measureCase09.01
TEST.NOTES:
Set rb_Asic_measureMode_mg as 9
Set EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g (rb_ASIC_Sched_Config_g) as 0x2
Stub function ASIC_Control_SendReadADCmd()
Check rb_NextMUXCfg_g remains unchanged
Check rb_NextSPI_Request_g remains unchanged
TEST.END_NOTES:
TEST.STUB:G5_ASIC_Control_sr.ASIC_Control_SendReadADCmd
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:9
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:3
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:8
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g:0x2
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:3
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:8
TEST.END

-- Test Case: AC_measureCase101
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_measure
TEST.NEW
TEST.NAME:AC_measureCase101
TEST.NOTES:
Set rb_Asic_measureMode_mg as 101
Set EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g (rb_ASIC_Sched_Config_g) as 0
Stub function ASIC_Control_SendReadADCmd()
Check rb_NextMUXCfg_g is set to CHG_MUX_ALS1 setting (4)
Check rb_NextSPI_Request_g for CB_CHG_MUX_STMEAS_RQ (0xC)
TEST.END_NOTES:
TEST.STUB:G5_ASIC_Control_sr.ASIC_Control_SendReadADCmd
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:101
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:0xC
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:4
TEST.END

-- Test Case: AC_measureCase101.01
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_measure
TEST.NEW
TEST.NAME:AC_measureCase101.01
TEST.NOTES:
Set rb_Asic_measureMode_mg as 101
Set EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g (rb_ASIC_Sched_Config_g) as 0x1
Check rb_NextMUXCfg_g remains unchanged
Check rb_NextSPI_Request_g remains unchanged
TEST.END_NOTES:
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:101
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:3
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:8
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g:0x1
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:3
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:8
TEST.END

-- Test Case: AC_measureCase103
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_measure
TEST.NEW
TEST.NAME:AC_measureCase103
TEST.NOTES:
Set rb_Asic_measureMode_mg as 103
Set EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g (rb_ASIC_Sched_Config_g) as 0
Stub function ASIC_Control_SendReadADCmd()
Check rb_NextMUXCfg_g is set to MEAS_VDIAG_VREF setting (236)
Check rb_NextSPI_Request_g for CB_CHG_MUX_STMEAS_RQ (0xC)
TEST.END_NOTES:
TEST.STUB:G5_ASIC_Control_sr.ASIC_Control_SendReadADCmd
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:103
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:0xC
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:236
TEST.END

-- Test Case: AC_measureCase103.01
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_measure
TEST.NEW
TEST.NAME:AC_measureCase103.01
TEST.NOTES:
Set rb_Asic_measureMode_mg as 103
Set EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g (rb_ASIC_Sched_Config_g) as 0x2
Check rb_NextMUXCfg_g remains unchanged
Check rb_NextSPI_Request_g remains unchanged
TEST.END_NOTES:
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:103
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:3
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:7
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g:0x2
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:3
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:7
TEST.END

-- Test Case: AC_measureCase119
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_measure
TEST.NEW
TEST.NAME:AC_measureCase119
TEST.NOTES:
Set rb_Asic_measureMode_mg as 119
Set EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g (rb_ASIC_Sched_Config_g) as 0
Stub function ASIC_Control_SendReadADCmd()
Check rb_NextMUXCfg_g is set to CHG_MUX_ALS2 setting (8)
Check rb_NextSPI_Request_g for CB_CHG_MUX_STMEAS_RQ (0xC)
TEST.END_NOTES:
TEST.STUB:G5_ASIC_Control_sr.ASIC_Control_SendReadADCmd
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:119
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:0xC
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:8
TEST.END

-- Test Case: AC_measureCase119.01
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_measure
TEST.NEW
TEST.NAME:AC_measureCase119.01
TEST.NOTES:
Set rb_Asic_measureMode_mg as 119
Set EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g (rb_ASIC_Sched_Config_g) as 0x1
Check rb_NextMUXCfg_g remains unchanged
Check rb_NextSPI_Request_g remains unchanged
TEST.END_NOTES:
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:119
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:3
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:5
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g:0x1
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:3
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:5
TEST.END

-- Test Case: AC_measureCase121
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_measure
TEST.NEW
TEST.NAME:AC_measureCase121
TEST.NOTES:
Set rb_Asic_measureMode_mg as 121
Check rb_wait500us_g for 0
TEST.END_NOTES:
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:121
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_wait500us_g:97
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_wait500us_g:0
TEST.END

-- Test Case: AC_measureCase123
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_measure
TEST.NEW
TEST.NAME:AC_measureCase123
TEST.NOTES:
Set rb_Asic_measureMode_mg as 123
Set EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g (rb_ASIC_Sched_Config_g) as 0
Stub function ASIC_Control_SendReadADCmd()
Check rb_NextMUXCfg_g is set to CAL_ICALHI_IHI_GHI setting (196)
Check rb_NextSPI_Request_g for CB_CHG_MUX_STMEAS_RQ (0xC)
TEST.END_NOTES:
TEST.STUB:G5_ASIC_Control_sr.ASIC_Control_SendReadADCmd
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:123
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:0xC
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:196
TEST.END

-- Test Case: AC_measureCase123.01
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_measure
TEST.NEW
TEST.NAME:AC_measureCase123.01
TEST.NOTES:
Set rb_Asic_measureMode_mg as 123
Set EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g (rb_ASIC_Sched_Config_g) as 0x2
Check rb_NextMUXCfg_g remains unchanged
Check rb_NextSPI_Request_g remains unchanged
TEST.END_NOTES:
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:123
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:3
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:7
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g:0x2
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:3
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:7
TEST.END

-- Test Case: AC_measureCase125
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_measure
TEST.NEW
TEST.NAME:AC_measureCase125
TEST.NOTES:
Set rb_Asic_measureMode_mg as 125
Set EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g (rb_ASIC_Sched_Config_g) as 0
Stub function ASIC_Control_SendReadADCmd()
Check rb_NextMUXCfg_g is set to CAL_ILO_IHI_GLO_INC setting (200)
Check rb_NextSPI_Request_g for CB_CHG_MUX_STMEAS_RQ (0xC)
TEST.END_NOTES:
TEST.STUB:G5_ASIC_Control_sr.ASIC_Control_SendReadADCmd
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:125
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:0xC
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:200
TEST.END

-- Test Case: AC_measureCase125.01
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_measure
TEST.NEW
TEST.NAME:AC_measureCase125.01
TEST.NOTES:
Set rb_Asic_measureMode_mg as 125
Set EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g (rb_ASIC_Sched_Config_g) as 0x2
Check rb_NextMUXCfg_g remains unchanged
Check rb_NextSPI_Request_g remains unchanged
TEST.END_NOTES:
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:125
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:3
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:7
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g:0x2
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:3
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:7
TEST.END

-- Test Case: AC_measureCase127
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_measure
TEST.NEW
TEST.NAME:AC_measureCase127
TEST.NOTES:
Set rb_Asic_measureMode_mg as 127
Set EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g (rb_ASIC_Sched_Config_g) as 0
Stub function ASIC_Control_SendReadADCmd()
Check rb_NextMUXCfg_g is set to MEAS_VDIAG_VDDA setting (248)
Check rb_NextSPI_Request_g for CB_CHG_MUX_STMEAS_RQ (0xC)
TEST.END_NOTES:
TEST.STUB:G5_ASIC_Control_sr.ASIC_Control_SendReadADCmd
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:127
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:0xC
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:248
TEST.END

-- Test Case: AC_measureCase127.01
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_measure
TEST.NEW
TEST.NAME:AC_measureCase127.01
TEST.NOTES:
Set rb_Asic_measureMode_mg as 127
Set EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g (rb_ASIC_Sched_Config_g) as 0x2
Check rb_NextMUXCfg_g remains unchanged
Check rb_NextSPI_Request_g remains unchanged
TEST.END_NOTES:
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:127
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:3
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:7
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g:0x2
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:0x3
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:7
TEST.END

-- Test Case: AC_measureCase139
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_measure
TEST.NEW
TEST.NAME:AC_measureCase139
TEST.NOTES:
Set rb_Asic_measureMode_mg as 139
Set EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g (rb_ASIC_Sched_Config_g) as 0
Stub function ASIC_Control_SendReadADCmd()
Check rb_NextMUXCfg_g is set to CHG_MUX_ALS5 setting (20)
Check rb_NextSPI_Request_g for CB_CHG_MUX_STMEAS_RQ (0xC)
TEST.END_NOTES:
TEST.STUB:G5_ASIC_Control_sr.ASIC_Control_SendReadADCmd
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:139
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:0xC
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:20
TEST.END

-- Test Case: AC_measureCase139.01
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_measure
TEST.NEW
TEST.NAME:AC_measureCase139.01
TEST.NOTES:
Set rb_Asic_measureMode_mg as 139
Set EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g (rb_ASIC_Sched_Config_g) as 0x1
Check rb_NextMUXCfg_g remains unchanged
Check rb_NextSPI_Request_g remains unchanged
TEST.END_NOTES:
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:139
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:3
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:7
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g:0x1
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:3
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:7
TEST.END

-- Test Case: AC_measureCase141
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_measure
TEST.NEW
TEST.NAME:AC_measureCase141
TEST.NOTES:

Set rb_Asic_measureMode_mg as 141
Check rb_wait500us_g for 0
TEST.END_NOTES:
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:141
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_wait500us_g:98
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_wait500us_g:0
TEST.END

-- Test Case: AC_measureCase143
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_measure
TEST.NEW
TEST.NAME:AC_measureCase143
TEST.NOTES:
Set rb_Asic_measureMode_mg as 143
Set EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g (rb_ASIC_Sched_Config_g) as 0
Stub function ASIC_Control_SendReadADCmd()
Check rb_NextMUXCfg_g is set to CHG_MUX_ALS5_INC setting (160)
Check rb_NextSPI_Request_g for CB_CHG_MUX_STMEAS_RQ (0xC)
TEST.END_NOTES:
TEST.STUB:G5_ASIC_Control_sr.ASIC_Control_SendReadADCmd
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:143
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:0xC
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:160
TEST.END

-- Test Case: AC_measureCase143.01
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_measure
TEST.NEW
TEST.NAME:AC_measureCase143.01
TEST.NOTES:
Set rb_Asic_measureMode_mg as 143
Set EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g (rb_ASIC_Sched_Config_g) as 0x1
Check rb_NextMUXCfg_g remains unchanged
Check rb_NextSPI_Request_g remains unchanged
TEST.END_NOTES:
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:143
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:3
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:7
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g:0x1
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:3
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:7
TEST.END

-- Test Case: AC_measureCase145
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_measure
TEST.NEW
TEST.NAME:AC_measureCase145
TEST.NOTES:
Set rb_Asic_measureMode_mg as 145
Set EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g (rb_ASIC_Sched_Config_g) as 0
Stub function ASIC_Control_SendReadADCmd()
Check rb_NextMUXCfg_g is set to CAL_IHI_ILO_GLO_INC setting (204)
Check rb_NextSPI_Request_g for CB_CHG_MUX_STMEAS_RQ (0xC)
TEST.END_NOTES:
TEST.STUB:G5_ASIC_Control_sr.ASIC_Control_SendReadADCmd
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:145
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:0xC
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:204
TEST.END

-- Test Case: AC_measureCase145.01
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_measure
TEST.NEW
TEST.NAME:AC_measureCase145.01
TEST.NOTES:
Set rb_Asic_measureMode_mg as 145
Set EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g (rb_ASIC_Sched_Config_g) as 0x2
Check rb_NextMUXCfg_g remains unchanged
Check rb_NextSPI_Request_g remains unchanged
TEST.END_NOTES:
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:145
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:3
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:7
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g:0x2
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:3
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:7
TEST.END

-- Test Case: AC_measureCase147
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_measure
TEST.NEW
TEST.NAME:AC_measureCase147
TEST.NOTES:
Set rb_Asic_measureMode_mg as 147
Set EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g (rb_ASIC_Sched_Config_g) as 0
Stub function ASIC_Control_SendReadADCmd()
Check rb_NextMUXCfg_g is set to MEAS_VTEMP setting (232)
Check rb_NextSPI_Request_g for CB_CHG_MUX_STMEAS_RQ (0xC)
TEST.END_NOTES:
TEST.STUB:G5_ASIC_Control_sr.ASIC_Control_SendReadADCmd
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:147
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:0xC
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:232
TEST.END

-- Test Case: AC_measureCase147.01
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_measure
TEST.NEW
TEST.NAME:AC_measureCase147.01
TEST.NOTES:
Set rb_Asic_measureMode_mg as 147
Set EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g (rb_ASIC_Sched_Config_g) as 0x2
Check rb_NextMUXCfg_g remains unchanged
Check rb_NextSPI_Request_g remains unchanged
TEST.END_NOTES:
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:147
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:3
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:7
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g:0x2
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:3
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:7
TEST.END

-- Test Case: AC_measureCase159
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_measure
TEST.NEW
TEST.NAME:AC_measureCase159
TEST.NOTES:
Set rb_Asic_measureMode_mg as 159
Set EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g (rb_ASIC_Sched_Config_g) as 0
Stub function ASIC_Control_SendReadADCmd()
Check rb_NextMUXCfg_g is set to CHG_MUX_ALS6 setting (24)
Check rb_NextSPI_Request_g for CB_CHG_MUX_STMEAS_RQ (0xC)
TEST.END_NOTES:
TEST.STUB:G5_ASIC_Control_sr.ASIC_Control_SendReadADCmd
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:159
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:0xC
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:24
TEST.END

-- Test Case: AC_measureCase159.01
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_measure
TEST.NEW
TEST.NAME:AC_measureCase159.01
TEST.NOTES:
Set rb_Asic_measureMode_mg as 159
Set EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g (rb_ASIC_Sched_Config_g) as 0x1
Check rb_NextMUXCfg_g remains unchanged
Check rb_NextSPI_Request_g remains unchanged
TEST.END_NOTES:
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:159
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:3
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:7
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g:0x1
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:3
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:7
TEST.END

-- Test Case: AC_measureCase161
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_measure
TEST.NEW
TEST.NAME:AC_measureCase161
TEST.NOTES:
Set rb_Asic_measureMode_mg as 161
Check rb_wait500us_g for 0
TEST.END_NOTES:
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:161
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_wait500us_g:89
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:162
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_wait500us_g:0
TEST.END

-- Test Case: AC_measureCase163
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_measure
TEST.NEW
TEST.NAME:AC_measureCase163
TEST.NOTES:
Set rb_Asic_measureMode_mg as 163
Set EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g (rb_ASIC_Sched_Config_g) as 0
Stub function ASIC_Control_SendReadADCmd()
Check rb_NextMUXCfg_g is set to MEAS_VDIAG_VDDA setting (248)
Check rb_NextSPI_Request_g for CB_CHG_MUX_STMEAS_RQ (0xC)
Check rb_Asic_measureMode_mg is increased
TEST.END_NOTES:
TEST.STUB:G5_ASIC_Control_sr.ASIC_Control_SendReadADCmd
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:163
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:164
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:0xC
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:248
TEST.END

-- Test Case: AC_measureCase163.01
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_measure
TEST.NEW
TEST.NAME:AC_measureCase163.01
TEST.NOTES:
Set rb_Asic_measureMode_mg as 163
Set EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g (rb_ASIC_Sched_Config_g) as 0x2
Check rb_NextMUXCfg_g remains unchanged
Check rb_NextSPI_Request_g remains unchanged
Check rb_Asic_measureMode_mg is increased
TEST.END_NOTES:
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:163
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:3
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:7
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g:0x2
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:164
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:3
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:7
TEST.END

-- Test Case: AC_measureCase165
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_measure
TEST.NEW
TEST.NAME:AC_measureCase165
TEST.NOTES:
Set rb_Asic_measureMode_mg as 165
Set EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g (rb_ASIC_Sched_Config_g) as 0
Stub function ASIC_Control_SendReadADCmd()
Check rb_NextMUXCfg_g is set to MEAS_VDIAG_VDDD setting (252)
Check rb_NextSPI_Request_g for CB_CHG_MUX_STMEAS_RQ (0xC)
Check rb_Asic_measureMode_mg is increased
TEST.END_NOTES:
TEST.STUB:G5_ASIC_Control_sr.ASIC_Control_SendReadADCmd
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:165
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:166
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:0xC
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:252
TEST.END

-- Test Case: AC_measureCase165.01
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_measure
TEST.NEW
TEST.NAME:AC_measureCase165.01
TEST.NOTES:
Set rb_Asic_measureMode_mg as 165
Set EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g (rb_ASIC_Sched_Config_g) as 0x2
Check rb_NextMUXCfg_g remains unchanged
Check rb_NextSPI_Request_g remains unchanged
Check rb_Asic_measureMode_mg is increased
TEST.END_NOTES:
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:165
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:3
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:7
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g:0x2
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:166
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:3
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:7
TEST.END

-- Test Case: AC_measureCase167
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_measure
TEST.NEW
TEST.NAME:AC_measureCase167
TEST.NOTES:
Set rb_Asic_measureMode_mg as 167
Set EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g (rb_ASIC_Sched_Config_g) as 0
Stub function ASIC_Control_SendReadADCmd()
Check rb_NextMUXCfg_g is set to CAL_ICALHI_IHI_GHI_INC setting (212)
Check rb_NextSPI_Request_g for CB_CHG_MUX_STMEAS_RQ (0xC)
Check rb_Asic_measureMode_mg is increased
TEST.END_NOTES:
TEST.STUB:G5_ASIC_Control_sr.ASIC_Control_SendReadADCmd
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:167
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:168
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:0xC
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:212
TEST.END

-- Test Case: AC_measureCase167.01
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_measure
TEST.NEW
TEST.NAME:AC_measureCase167.01
TEST.NOTES:
Set rb_Asic_measureMode_mg as 167
Set EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g (rb_ASIC_Sched_Config_g) as 0x2
Check rb_NextMUXCfg_g remains unchanged
Check rb_NextSPI_Request_g remains unchanged
Check rb_Asic_measureMode_mg is increased
TEST.END_NOTES:
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:167
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:3
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:7
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g:0x2
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:168
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:3
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:7
TEST.END

-- Test Case: AC_measureCase181
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_measure
TEST.NEW
TEST.NAME:AC_measureCase181
TEST.NOTES:
Set rb_Asic_measureMode_mg as 181
Set EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g (rb_ASIC_Sched_Config_g) as 0
Stub function ASIC_Control_SendReadADCmd()
Check rb_NextMUXCfg_g is set to CHG_MUX_REC setting (28)
Check rb_NextSPI_Request_g for CB_CHG_MUX_STMEAS_RQ (0xC)
Check rb_Asic_measureMode_mg is increased
TEST.END_NOTES:
TEST.STUB:G5_ASIC_Control_sr.ASIC_Control_SendReadADCmd
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:181
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:182
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:0xC
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:28
TEST.END

-- Test Case: AC_measureCase181.01
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_measure
TEST.NEW
TEST.NAME:AC_measureCase181.01
TEST.NOTES:
Set rb_Asic_measureMode_mg as 181
Set EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g (rb_ASIC_Sched_Config_g) as 0xC1
Check rb_NextMUXCfg_g remains unchanged
Check rb_NextSPI_Request_g remains unchanged
Check rb_Asic_measureMode_mg is increased
TEST.END_NOTES:
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:181
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:3
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:7
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g:0xC1
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:182
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:3
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:7
TEST.END

-- Test Case: AC_measureCase183
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_measure
TEST.NEW
TEST.NAME:AC_measureCase183
TEST.NOTES:
Set rb_Asic_measureMode_mg as 183
Check rb_wait500us_g for 0
Check rb_Asic_measureMode_mg is increased
TEST.END_NOTES:
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:183
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_wait500us_g:76
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:184
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_wait500us_g:0
TEST.END

-- Test Case: AC_measureCase185
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_measure
TEST.NEW
TEST.NAME:AC_measureCase185
TEST.NOTES:
Set rb_Asic_measureMode_mg as 185
Set EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g (rb_ASIC_Sched_Config_g) as 0
Stub function ASIC_Control_SendReadADCmd()
Check rb_NextMUXCfg_g is set to CHG_MUX_REC_INC setting (176)
Check rb_NextSPI_Request_g for CB_CHG_MUX_STMEAS_RQ (0xC)
Check rb_Asic_measureMode_mg is increased
TEST.END_NOTES:
TEST.STUB:G5_ASIC_Control_sr.ASIC_Control_SendReadADCmd
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:185
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:186
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:CB_CHG_MUX_STMEAS_RQ
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:176
TEST.END

-- Test Case: AC_measureCase185.01
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_measure
TEST.NEW
TEST.NAME:AC_measureCase185.01
TEST.NOTES:
Set rb_Asic_measureMode_mg as 185
Set EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g (rb_ASIC_Sched_Config_g) as 0xC1
Check rb_NextMUXCfg_g remains unchanged
Check rb_NextSPI_Request_g remains unchanged
Check rb_Asic_measureMode_mg is increased
TEST.END_NOTES:
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:185
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:3
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:7
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g:0xC1
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:186
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:3
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:7
TEST.END

-- Test Case: AC_measureCase187
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_measure
TEST.NEW
TEST.NAME:AC_measureCase187
TEST.NOTES:
Set rb_Asic_measureMode_mg as 187
Set EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g (rb_ASIC_Sched_Config_g) as 0
Stub function ASIC_Control_SendReadADCmd()
Check rb_NextMUXCfg_g is set to CAL_IHI_ICALHI_GHI_INC setting (208)
Check rb_NextSPI_Request_g for CB_CHG_MUX_STMEAS_RQ (0xC)
Check rb_Asic_measureMode_mg is increased
TEST.END_NOTES:
TEST.STUB:G5_ASIC_Control_sr.ASIC_Control_SendReadADCmd
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:187
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:188
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:CB_CHG_MUX_STMEAS_RQ
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:208
TEST.END

-- Test Case: AC_measureCase187.01
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_measure
TEST.NEW
TEST.NAME:AC_measureCase187.01
TEST.NOTES:
Set rb_Asic_measureMode_mg as 187
Set EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g (rb_ASIC_Sched_Config_g) as 0x2
Check rb_NextMUXCfg_g remains unchanged
Check rb_NextSPI_Request_g remains unchanged
Check rb_Asic_measureMode_mg is increased
TEST.END_NOTES:
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:187
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:3
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:7
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g:0x2
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:188
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:3
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:7
TEST.END

-- Test Case: AC_measureCase19
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_measure
TEST.NEW
TEST.NAME:AC_measureCase19
TEST.NOTES:
Set rb_Asic_measureMode_mg as 19
Set EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g (rb_ASIC_Sched_Config_g) as 0
Stub function ASIC_Control_SendReadADCmd()
Check rb_NextMUXCfg_g is set to CHG_MUX_ALS2 setting (8)
Check rb_NextSPI_Request_g for CB_CHG_MUX_STMEAS_RQ (0xC)
Check rb_Asic_measureMode_mg is increased
TEST.END_NOTES:
TEST.STUB:G5_ASIC_Control_sr.ASIC_Control_SendReadADCmd
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:19
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:20
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:0xC
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:8
TEST.END

-- Test Case: AC_measureCase19.01
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_measure
TEST.NEW
TEST.NAME:AC_measureCase19.01
TEST.NOTES:
Set rb_Asic_measureMode_mg as 19
Set EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g (rb_ASIC_Sched_Config_g) as 0x1
Check rb_NextMUXCfg_g remains unchanged
Check rb_NextSPI_Request_g remains unchanged
Check rb_Asic_measureMode_mg is increased
TEST.END_NOTES:
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:19
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:3
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:7
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g:0x1
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:20
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:3
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:7
TEST.END

-- Test Case: AC_measureCase200
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_measure
TEST.NEW
TEST.NAME:AC_measureCase200
TEST.NOTES:
Set rb_Asic_measureMode_mg as 200
Set EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g (rb_ASIC_Sched_Config_g) as 0
Check rb_Asic_measureMode_mg = 0
Check uF_ASIC_Ctrl_Error_Flags_g.Bit.B1 (rbi_ASIC_NoValidAD_Error_g) = FALSE (0)
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:200
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_Ctrl_Error_Flags_g.Bit.B1:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_Ctrl_Error_Flags_g.Bit.B1:0
TEST.END

-- Test Case: AC_measureCase200.01
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_measure
TEST.NEW
TEST.NAME:AC_measureCase200.01
TEST.NOTES:
# Testcase User Code required
Set rb_Asic_measureMode_mg as 200
Set EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g (rb_ASIC_Sched_Config_g) as 0
Set rb_StaticNoValidAD_cnt_g as 76
Call two times with rb_Asic_measureMode set as 200 (to have static variable rb_OldStaticNoValidAD_cnt_l set)
Check rb_Asic_measureMode_mg = 0
Check rb_StaticNoValidAD_cnt_g is decreased
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:200
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_StaticNoValidAD_cnt_g:76
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_StaticNoValidAD_cnt_g:75
TEST.VALUE_USER_CODE:<<testcase>>
ASIC_Control_measure();
rb_Asic_measureMode_mg = 200;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: AC_measureCase21
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_measure
TEST.NEW
TEST.NAME:AC_measureCase21
TEST.NOTES:
Set rb_Asic_measureMode_mg as 21
Check rb_wait500us_g for 0
Check rb_Asic_measureMode_mg is increased
TEST.END_NOTES:
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:21
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_wait500us_g:54
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:22
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_wait500us_g:0
TEST.END

-- Test Case: AC_measureCase23
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_measure
TEST.NEW
TEST.NAME:AC_measureCase23
TEST.NOTES:
Set rb_Asic_measureMode_mg as 23
Set EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g (rb_ASIC_Sched_Config_g) as 0
Stub function ASIC_Control_SendReadADCmd()
Check rb_NextMUXCfg_g is set to CHG_MUX_ALS2_INC setting (128)
Check rb_NextSPI_Request_g for CB_CHG_MUX_STMEAS_RQ (0xC)
Check rb_Asic_measureMode_mg is increased
TEST.END_NOTES:
TEST.STUB:G5_ASIC_Control_sr.ASIC_Control_SendReadADCmd
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:23
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:24
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:0xC
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:128
TEST.END

-- Test Case: AC_measureCase23.01
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_measure
TEST.NEW
TEST.NAME:AC_measureCase23.01
TEST.NOTES:
Set rb_Asic_measureMode_mg as 23
Set EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g (rb_ASIC_Sched_Config_g) as 0x1
Check rb_NextMUXCfg_g remains unchanged
Check rb_NextSPI_Request_g remains unchanged
Check rb_Asic_measureMode_mg is increased
TEST.END_NOTES:
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:23
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:3
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:7
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g:0x1
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:24
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:3
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:7
TEST.END

-- Test Case: AC_measureCase25
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_measure
TEST.NEW
TEST.NAME:AC_measureCase25
TEST.NOTES:
Set rb_Asic_measureMode_mg as 25
Set EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g (rb_ASIC_Sched_Config_g) as 0
Stub function ASIC_Control_SendReadADCmd()
Check rb_NextMUXCfg_g is set to CAL_ILO_IHI_GLO setting (0)
Check rb_NextSPI_Request_g for CB_CHG_MUX_STMEAS_RQ (0xC)
Check rb_Asic_measureMode_mg is increased
TEST.END_NOTES:
TEST.STUB:G5_ASIC_Control_sr.ASIC_Control_SendReadADCmd
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:25
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:7
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:26
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:0xC
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:0
TEST.END

-- Test Case: AC_measureCase25.01
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_measure
TEST.NEW
TEST.NAME:AC_measureCase25.01
TEST.NOTES:
Set rb_Asic_measureMode_mg as 25
Set EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g (rb_ASIC_Sched_Config_g) as 0x2
Check rb_NextMUXCfg_g remains unchanged
Check rb_NextSPI_Request_g remains unchanged
Check rb_Asic_measureMode_mg is increased
TEST.END_NOTES:
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:25
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:3
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:7
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g:0x2
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:26
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:3
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:7
TEST.END

-- Test Case: AC_measureCase39
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_measure
TEST.NEW
TEST.NAME:AC_measureCase39
TEST.NOTES:
Set rb_Asic_measureMode_mg as 39
Set EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g (rb_ASIC_Sched_Config_g) as 0
Stub function ASIC_Control_SendReadADCmd()
Check rb_NextMUXCfg_g is set to CHG_MUX_ALS5 setting (20)
Check rb_NextSPI_Request_g for CB_CHG_MUX_STMEAS_RQ (0xC)
Check rb_Asic_measureMode_mg is increased
TEST.END_NOTES:
TEST.STUB:G5_ASIC_Control_sr.ASIC_Control_SendReadADCmd
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:39
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:40
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:0xC
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:20
TEST.END

-- Test Case: AC_measureCase39.01
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_measure
TEST.NEW
TEST.NAME:AC_measureCase39.01
TEST.NOTES:
Set rb_Asic_measureMode_mg as 39
Set EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g (rb_ASIC_Sched_Config_g) as 0x1
Check rb_NextMUXCfg_g remains unchanged
Check rb_NextSPI_Request_g remains unchanged
Check rb_Asic_measureMode_mg is increased
TEST.END_NOTES:
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:39
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:3
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:7
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g:0x1
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:40
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:3
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:7
TEST.END

-- Test Case: AC_measureCase41
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_measure
TEST.NEW
TEST.NAME:AC_measureCase41
TEST.NOTES:
Set rb_Asic_measureMode_mg as 41
Check rb_wait500us_g for 0
Check rb_Asic_measureMode_mg is increased
TEST.END_NOTES:
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:41
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_wait500us_g:87
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:42
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_wait500us_g:0
TEST.END

-- Test Case: AC_measureCase43
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_measure
TEST.NEW
TEST.NAME:AC_measureCase43
TEST.NOTES:
Set rb_Asic_measureMode_mg as 43
Set EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g (rb_ASIC_Sched_Config_g) as 0
Stub function ASIC_Control_SendReadADCmd()
Check rb_wait500us is set to 0
Check rb_NextMUXCfg_g is set to MEAS_V_IREF_LO setting (240)
Check rb_NextSPI_Request_g for CB_CHG_MUX_STMEAS_RQ (0xC)
Check rb_Asic_measureMode_mg is increased
TEST.END_NOTES:
TEST.STUB:G5_ASIC_Control_sr.ASIC_Control_SendReadADCmd
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:43
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_wait500us_g:55
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:44
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_wait500us_g:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:0xC
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:240
TEST.END

-- Test Case: AC_measureCase43.01
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_measure
TEST.NEW
TEST.NAME:AC_measureCase43.01
TEST.NOTES:
Set rb_Asic_measureMode_mg as 43
Set EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g (rb_ASIC_Sched_Config_g) as 0x2
Check rb_NextMUXCfg_g remains unchanged
Check rb_NextSPI_Request_g remains unchanged
Check rb_Asic_measureMode_mg is increased
TEST.END_NOTES:
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:43
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:3
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:7
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g:0x2
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:44
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:3
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:7
TEST.END

-- Test Case: AC_measureCase45
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_measure
TEST.NEW
TEST.NAME:AC_measureCase45
TEST.NOTES:
Set rb_Asic_measureMode_mg as 45
Set EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g (rb_ASIC_Sched_Config_g) as 0
Stub function ASIC_Control_SendReadADCmd()
Check rb_NextMUXCfg_g is set to MEAS_V_IREF_HI setting (244)
Check rb_NextSPI_Request_g for CB_CHG_MUX_STMEAS_RQ (0xC)
Check rb_Asic_measureMode_mg is increased
TEST.END_NOTES:
TEST.STUB:G5_ASIC_Control_sr.ASIC_Control_SendReadADCmd
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:45
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:46
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:0xC
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:244
TEST.END

-- Test Case: AC_measureCase45.01
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_measure
TEST.NEW
TEST.NAME:AC_measureCase45.01
TEST.NOTES:
Set rb_Asic_measureMode_mg as 43
Set EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g (rb_ASIC_Sched_Config_g) as 0x2
Stub function ASIC_Control_SendReadADCmd()
Check rb_NextMUXCfg_g remains unchanged
Check rb_NextSPI_Request_g remains unchanged
Check rb_Asic_measureMode_mg is increased
TEST.END_NOTES:
TEST.STUB:G5_ASIC_Control_sr.ASIC_Control_SendReadADCmd
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:45
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:3
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:7
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g:0x2
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:46
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:3
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:7
TEST.END

-- Test Case: AC_measureCase59
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_measure
TEST.NEW
TEST.NAME:AC_measureCase59
TEST.NOTES:
Set rb_Asic_measureMode_mg as 59
Set EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g (rb_ASIC_Sched_Config_g) as 0
Stub function ASIC_Control_SendReadADCmd()
Check rb_NextMUXCfg_g is set to CHG_MUX_ALS6 setting (24)
Check rb_NextSPI_Request_g for CB_CHG_MUX_STMEAS_RQ (0xC)
Check rb_Asic_measureMode_mg is increased
TEST.END_NOTES:
TEST.STUB:G5_ASIC_Control_sr.ASIC_Control_SendReadADCmd
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:59
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:60
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:0xC
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:24
TEST.END

-- Test Case: AC_measureCase59.01
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_measure
TEST.NEW
TEST.NAME:AC_measureCase59.01
TEST.NOTES:
Set rb_Asic_measureMode_mg as 59
Set EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g (rb_ASIC_Sched_Config_g) as 0x1
Check rb_NextMUXCfg_g remains unchanged
Check rb_NextSPI_Request_g remains unchanged
Check rb_Asic_measureMode_mg is increased
TEST.END_NOTES:
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:59
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:3
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:7
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g:0x1
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:60
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:3
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:7
TEST.END

-- Test Case: AC_measureCase61
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_measure
TEST.NEW
TEST.NAME:AC_measureCase61
TEST.NOTES:
Set rb_Asic_measureMode_mg as 61
Check rb_wait500us_g for 0
Check rb_Asic_measureMode_mg is increased
TEST.END_NOTES:
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:61
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_wait500us_g:33
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:62
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_wait500us_g:0
TEST.END

-- Test Case: AC_measureCase63
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_measure
TEST.NEW
TEST.NAME:AC_measureCase63
TEST.NOTES:
Set rb_Asic_measureMode_mg as 63
Set EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g (rb_ASIC_Sched_Config_g) as 0
Stub function ASIC_Control_SendReadADCmd()
Check rb_NextMUXCfg_g is set to CAL_ILO_ICALLO_GHI setting (64)
Check rb_NextSPI_Request_g for CB_CHG_MUX_STMEAS_RQ (0xC)
Check rb_Asic_measureMode_mg is increased
TEST.END_NOTES:
TEST.STUB:G5_ASIC_Control_sr.ASIC_Control_SendReadADCmd
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:63
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:64
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:0xC
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:64
TEST.END

-- Test Case: AC_measureCase63.01
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_measure
TEST.NEW
TEST.NAME:AC_measureCase63.01
TEST.NOTES:
Set rb_Asic_measureMode_mg as 63
Set EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g (rb_ASIC_Sched_Config_g) as 0x2
Check rb_NextMUXCfg_g remains unchanged
Check rb_NextSPI_Request_g remains unchanged
Check rb_Asic_measureMode_mg is increased
TEST.END_NOTES:
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:63
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:3
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:7
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g:0x2
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:64
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:3
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:7
TEST.END

-- Test Case: AC_measureCase65
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_measure
TEST.NEW
TEST.NAME:AC_measureCase65
TEST.NOTES:
Set rb_Asic_measureMode_mg as 65
Set EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g (rb_ASIC_Sched_Config_g) as 0
Stub function ASIC_Control_SendReadADCmd()
Check rb_NextMUXCfg_g is set to CAL_IHI_ICALHI_GHI setting (96)
Check rb_NextSPI_Request_g for CB_CHG_MUX_STMEAS_RQ (0xC)
Check rb_Asic_measureMode_mg is increased
TEST.END_NOTES:
TEST.STUB:G5_ASIC_Control_sr.ASIC_Control_SendReadADCmd
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:65
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:66
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:0xC
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:96
TEST.END

-- Test Case: AC_measureCase65.01
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_measure
TEST.NEW
TEST.NAME:AC_measureCase65.01
TEST.NOTES:
Set rb_Asic_measureMode_mg as 65
Set EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g (rb_ASIC_Sched_Config_g) as 0x2
Check rb_NextMUXCfg_g remains unchanged
Check rb_NextSPI_Request_g remains unchanged
Check rb_Asic_measureMode_mg is increased
TEST.END_NOTES:
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:65
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:3
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:7
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g:0x2
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:66
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:3
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:7
TEST.END

-- Test Case: AC_measureCase81
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_measure
TEST.NEW
TEST.NAME:AC_measureCase81
TEST.NOTES:
Set rb_Asic_measureMode_mg as 81
Set EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g (rb_ASIC_Sched_Config_g) as 0
Stub function ASIC_Control_SendReadADCmd()
Check rb_NextMUXCfg_g is set to CHG_MUX_REC setting (28)
Check rb_NextSPI_Request_g for CB_CHG_MUX_STMEAS_RQ (0xC)
Check rb_Asic_measureMode_mg is increased
TEST.END_NOTES:
TEST.STUB:G5_ASIC_Control_sr.ASIC_Control_SendReadADCmd
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:81
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g:0x0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:82
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:0xC
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:28
TEST.END

-- Test Case: AC_measureCase81.01
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_measure
TEST.NEW
TEST.NAME:AC_measureCase81.01
TEST.NOTES:
Set rb_Asic_measureMode_mg as 81
Set EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g (rb_ASIC_Sched_Config_g) as 193	
Check rb_NextMUXCfg_g remains unchanged
Check rb_NextSPI_Request_g remains unchanged
Check rb_Asic_measureMode_mg is increased
TEST.END_NOTES:
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:81
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:3
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:7
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g:193
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:82
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:0x3
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:7
TEST.END

-- Test Case: AC_measureCase83
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_measure
TEST.NEW
TEST.NAME:AC_measureCase83
TEST.NOTES:
Set rb_Asic_measureMode_mg as 83
Check rb_wait500us_g for 0
Check rb_Asic_measureMode_mg is increased
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:83
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_wait500us_g:43
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:84
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_wait500us_g:0
TEST.END

-- Test Case: AC_measureCase85
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_measure
TEST.NEW
TEST.NAME:AC_measureCase85
TEST.NOTES:
Set rb_Asic_measureMode_mg as 85
Set EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g (rb_ASIC_Sched_Config_g) as 0
Stub function ASIC_Control_SendReadADCmd()
Check rb_NextMUXCfg_g is set to CAL_ICALLO_ILO_GHI setting (192)
Check rb_NextSPI_Request_g for CB_CHG_MUX_STMEAS_RQ (0xC)
Check rb_Asic_measureMode_mg is increased
TEST.END_NOTES:
TEST.STUB:G5_ASIC_Control_sr.ASIC_Control_SendReadADCmd
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:85
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:86
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:0xC
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:192
TEST.END

-- Test Case: AC_measureCase85.01
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_measure
TEST.NEW
TEST.NAME:AC_measureCase85.01
TEST.NOTES:
Set rb_Asic_measureMode_mg as 85
Set EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g (rb_ASIC_Sched_Config_g) as 0x2
Check rb_NextMUXCfg_g remains unchanged
Check rb_NextSPI_Request_g remains unchanged
Check rb_Asic_measureMode_mg is increased
TEST.END_NOTES:
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:85
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:3
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:7
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g:0x2
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:86
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:3
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:7
TEST.END

-- Test Case: AC_measureCase87
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_measure
TEST.NEW
TEST.NAME:AC_measureCase87
TEST.NOTES:
Set rb_Asic_measureMode_mg as 87
Set EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g (rb_ASIC_Sched_Config_g) as 0
Stub function ASIC_Control_SendReadADCmd()
Check rb_NextMUXCfg_g is set to MEAS_VDIAG_VDDD setting (252)
Check rb_NextSPI_Request_g for CB_CHG_MUX_STMEAS_RQ (0xC)
Check rb_Asic_measureMode_mg is increased
TEST.END_NOTES:
TEST.STUB:G5_ASIC_Control_sr.ASIC_Control_SendReadADCmd
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:87
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:88
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:0xC
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:252
TEST.END

-- Test Case: AC_measureCase87.01
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_measure
TEST.NEW
TEST.NAME:AC_measureCase87.01
TEST.NOTES:
Set rb_Asic_measureMode_mg as 87
Set EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g (rb_ASIC_Sched_Config_g) as 0x2
Check rb_NextMUXCfg_g remains unchanged
Check rb_NextSPI_Request_g remains unchanged
Check rb_Asic_measureMode_mg is increased
TEST.END_NOTES:
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:87
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:3
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:7
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g:0x2
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:88
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:0x3
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextMUXCfg_g:7
TEST.END

-- Test Case: AC_measureDefault
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_measure
TEST.NEW
TEST.NAME:AC_measureDefault
TEST.NOTES:
Set rb_Asic_measureMode_mg as 191
Set rbi_ASICgainAdjustRunning_g (uF_LIN_Diag_Req2_mg) as 0
Check rb_NextSPI_Request_g for CB_STMEAS_RQ (3)
Check rb_Asic_measureMode_mg is increased
TEST.END_NOTES:
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:191
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_LIN_DiagReq2_mg.Bit.B5:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:192
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_NextSPI_Request_g:3
TEST.END

-- Test Case: AC_measureDefault.01
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_measure
TEST.NEW
TEST.NAME:AC_measureDefault.01
TEST.NOTES:
Set rb_Asic_measureMode_mg as 191
Set EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g (rb_ASIC_Sched_Config_g) as 0
Set rb_CurMode_g as 0
Set uF_LIN_DiagReq2_mg.Bit.B5 (rbi_ASICgainAdjustRunning_g) as 1
Check rb_Asic_measureMode_mg is increased by 2
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:191
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_CurMode_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_LIN_DiagReq2_mg.Bit.B5:1
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:193
TEST.END

-- Test Case: AC_measureDefault.02
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_measure
TEST.NEW
TEST.NAME:AC_measureDefault.02
TEST.NOTES:
Set rb_Asic_measureMode_mg as 191
Set EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g (rb_ASIC_Sched_Config_g) as 0
Set rb_CurMode_g as 4
Set uF_LIN_DiagReq2_mg.Bit.B5 (rbi_ASICgainAdjustRunning_g) as 1
Check rb_Asic_measureMode_mg is increased
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:191
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_CurMode_g:4
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_LIN_DiagReq2_mg.Bit.B5:1
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:192
TEST.END

-- Test Case: AC_measureDefault.03
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_measure
TEST.NEW
TEST.NAME:AC_measureDefault.03
TEST.NOTES:
Set rb_Asic_measureMode_mg as 193
Set EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g (rb_ASIC_Sched_Config_g) as 0
Set rb_CurMode_g as CB_ASIC_LOOP1_MD (1)
Set rb_newRSconvRcv_g as TRUE (1)
Set ras_ASIC_CtrReg_g[0x15].val (rb_REGV_OSAT_g) as 0
Check rb_newRSconvRcv_g = FALSE (0)
Check uF_ASIC_Control_Error_Flags_g.Bit.B2 (rbi_REGV_OSAT_Error_g) = FALSE (0)
Check rb_Asic_measureMode_mg is increased
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:193
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_CurMode_g:CB_ASIC_LOOP1_MD
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_CtrReg_g[21].val:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_Ctrl_Error_Flags_g.Bit.B2:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_newRSconvRcv_g:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:194
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_Ctrl_Error_Flags_g.Bit.B2:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_newRSconvRcv_g:0
TEST.END

-- Test Case: AC_measureDefault.04
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_measure
TEST.NEW
TEST.NAME:AC_measureDefault.04
TEST.NOTES:
Set rb_Asic_measureMode_mg as 193
Set EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g (rb_ASIC_Sched_Config_g) as 0
Set rb_CurMode_g as CB_ASIC_LOOP1_MD (1)
Set rb_newRSconvRcv_g as TRUE (1)
Set rw_REGV_OSAT_cnt_g as 87
Check rb_newRSconvRcv_g = FALSE (0)
Check rw_REGV_OSAT_cnt_g is decreased
Check rb_Asic_measureMode_mg is increased
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:193
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_CurMode_g:CB_ASIC_LOOP1_MD
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_newRSconvRcv_g:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rw_REGV_OSAT_cnt_g:87
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:194
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_newRSconvRcv_g:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rw_REGV_OSAT_cnt_g:86
TEST.END

-- Test Case: AC_measureDefault.05
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_measure
TEST.NEW
TEST.NAME:AC_measureDefault.05
TEST.NOTES:
Set rb_Asic_measureMode_mg as 193
Set EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g (rb_ASIC_Sched_Config_g) as 0
Set rb_CurMode_g as CB_ASIC_LOOP1_MD (1)
Set rb_newRSconvRcv_g as TRUE (1)
Set ras_ASIC_CtrReg_g[0x15].val (rb_REGV_OSAT_g) as 2
Set rw_REGV_OSAT_cnt_g greater than CW_REGV_OSAT_CNT_THRSHD (here 1500)
Check rb_newRSconvRcv_g = FALSE (0)
Check uF_ASIC_Control_Error_Flags_g.Bit.B2 (rbi_REGV_OSAT_Error_g) = TRUE (1)
Check rb_Asic_measureMode_mg is increased
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:193
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_CurMode_g:CB_ASIC_LOOP1_MD
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_CtrReg_g[21].val:2
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_Ctrl_Error_Flags_g.Bit.B2:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_newRSconvRcv_g:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rw_REGV_OSAT_cnt_g:1500
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:194
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.uF_ASIC_Ctrl_Error_Flags_g.Bit.B2:1
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_newRSconvRcv_g:0
TEST.END

-- Test Case: AC_measureDefault.06
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_measure
TEST.NEW
TEST.NAME:AC_measureDefault.06
TEST.NOTES:
Set rb_Asic_measureMode_mg as 193
Set EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g (rb_ASIC_Sched_Config_g) as 0
Set rb_CurMode_g as CB_ASIC_LOOP1_MD (1)
Set rb_newRSconvRcv_g as TRUE (1)
Set ras_ASIC_CtrReg_g[0x15].val (rb_REGV_OSAT_g) as 2
Set rw_REGV_OSAT_cnt_g as 87
Check rb_newRSconvRcv_g = FALSE (0)
Check rw_REGV_OSAT_cnt_g is increased
Check rb_Asic_measureMode_mg is increased
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:193
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_CurMode_g:CB_ASIC_LOOP1_MD
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_CtrReg_g[21].val:2
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_newRSconvRcv_g:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rw_REGV_OSAT_cnt_g:87
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:194
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_newRSconvRcv_g:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rw_REGV_OSAT_cnt_g:88
TEST.END

-- Test Case: AC_measureDefault.07
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_measure
TEST.NEW
TEST.NAME:AC_measureDefault.07
TEST.NOTES:
Set rb_Asic_measureMode_mg as 193
Set EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g (rb_ASIC_Sched_Config_g) as 0
Set rb_CurMode_g as 0
Set uF_LIN_DiagReq2_mg.Bit.B5 (rbi_ASICgainAdjustRunning_g) as 1
Check rb_Asic_measureMode_mg is increased
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:193
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_CurMode_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.uF_LIN_DiagReq2_mg.Bit.B5:1
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:194
TEST.END

-- Test Case: AC_measureLoop2_LStop
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_measure
TEST.NEW
TEST.NAME:AC_measureLoop2_LStop
TEST.NOTES:
# Testcase User Code required
Set rb_Asic_measureMode_mg as 1
Set EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g (rb_ASIC_Sched_Config_g) as 1
Set rb_CurMode_g as CB_ASIC_LOOP2_MD (2)
Set rb_RainMeas_cnt_g as 53
Call ASIC_Control_measure() first time to increase static variable rb_LClosed_dur_cnt_l
Set rb_CurMode_g as CB_ASIC_LSTOP_MD (4)
Check rb_RainMeas_cnt_g = 0
Check rb_RainMeas_cnt_max_g = 53
Check rb_LClosed_dur_max_g = 1
Check rb_Asic_measureMode_mg is increased by 2
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_CurMode_g:CB_ASIC_LOOP2_MD
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_RainMeas_cnt_max_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_LClosed_dur_max_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_RainMeas_cnt_g:53
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g:0x1
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:3
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_RainMeas_cnt_max_g:53
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_LClosed_dur_max_g:1
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_RainMeas_cnt_g:0
TEST.VALUE_USER_CODE:<<testcase>>
ASIC_Control_measure();
rb_CurMode_g = CB_ASIC_LSTOP_MD;

TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: AC_measureMode200
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_measure
TEST.NEW
TEST.NAME:AC_measureMode200
TEST.NOTES:
Set rb_Asic_measureMode_mg as 1
Set EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g (rb_ASIC_Sched_Config_g) as 0x9
Check rb_Asic_measureMode_mg is increased
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g:0x9
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:2
TEST.END

-- Test Case: AC_measureMode200.01
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_measure
TEST.NEW
TEST.NAME:AC_measureMode200.01
TEST.NOTES:
Set rb_Asic_measureMode_mg as 1
Set EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g (rb_ASIC_Sched_Config_g) as 0x9
Set rb_CurMode_g as CB_ASIC_LOOP2_MD (2)
Set RSStatus.Bit.B0 (rbi_RainSensorEnable) as 1
# Testcase User Code Required
Call ASIC_Control_measure twice to set local variable RSI_out to 1
Check rb_Asic_measureMode_mg = 0
Check rb_SPI_Data_to_send_g is set to 2
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_CurMode_g:CB_ASIC_LOOP2_MD
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_SPI_Data_to_send_g:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.RSStatus.Bit.B0:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g:0x9
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_SPI_Data_to_send_g:2
TEST.VALUE_USER_CODE:<<testcase>>
ASIC_Control_measure();
ASIC_Control_measure();

TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: AC_measureMode200.02
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:ASIC_Control_measure
TEST.NEW
TEST.NAME:AC_measureMode200.02
TEST.NOTES:
Set rb_Asic_measureMode_mg as 1
Set EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g (rb_ASIC_Sched_Config_g) as 0x9
Set rb_CurMode_g as CB_ASIC_LOOP2_MD (2)
Set RSStatus.Bit.B0 (rbi_RainSensorEnable) as 1
Check rb_Asic_measureMode_mg = 0
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_CurMode_g:CB_ASIC_LOOP2_MD
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.RSStatus.Bit.B0:1
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g:0x9
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:0
TEST.EXPECTED:uut_prototype_stubs.SPI_Write_Byte.rb_byteToWrite_l:CB_ASIC_SET_TEST_ENABLE
TEST.END

-- Subprogram: get_rb_ASICReg_NoValidVals_cnt_g

-- Test Case: rb_ASICReg_NoValidVals_cnt_g
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:get_rb_ASICReg_NoValidVals_cnt_g
TEST.NEW
TEST.NAME:rb_ASICReg_NoValidVals_cnt_g
TEST.NOTES:
Set value to get and check return value
TEST.END_NOTES:
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_ASICReg_NoValidVals_cnt_g:0x3F
TEST.EXPECTED:G5_ASIC_Control_sr.get_rb_ASICReg_NoValidVals_cnt_g.return:0x3F
TEST.END

-- Subprogram: get_rb_Asic_measureMode_mg

-- Test Case: rb_Asic_measureMode_mg
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:get_rb_Asic_measureMode_mg
TEST.NEW
TEST.NAME:rb_Asic_measureMode_mg
TEST.NOTES:
Set value to get and check return value
TEST.END_NOTES:
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:0x3F
TEST.EXPECTED:G5_ASIC_Control_sr.get_rb_Asic_measureMode_mg.return:0x3F
TEST.END

-- Subprogram: get_rb_LEDx_LStop_error_cnt_g

-- Test Case: rb_LEDx_LStop_error_cnt_g
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:get_rb_LEDx_LStop_error_cnt_g
TEST.NEW
TEST.NAME:rb_LEDx_LStop_error_cnt_g
TEST.NOTES:
Set value to get and check return value
TEST.END_NOTES:
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_LEDx_LStop_error_cnt_g:0x3F
TEST.EXPECTED:G5_ASIC_Control_sr.get_rb_LEDx_LStop_error_cnt_g.return:0x3F
TEST.END

-- Subprogram: get_rb_LightSignalErrorCnt_g

-- Test Case: rb_LightSignalErrorCnt_g
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:get_rb_LightSignalErrorCnt_g
TEST.NEW
TEST.NAME:rb_LightSignalErrorCnt_g
TEST.NOTES:
Set value to get and check return value
TEST.END_NOTES:
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_LightSignalErrorCnt_g:0x3F
TEST.EXPECTED:G5_ASIC_Control_sr.get_rb_LightSignalErrorCnt_g.return:0x3F
TEST.END

-- Subprogram: get_rb_MaxLightSignalErrorCnt_g

-- Test Case: rb_MaxLightSignalErrorCnt_g
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:get_rb_MaxLightSignalErrorCnt_g
TEST.NEW
TEST.NAME:rb_MaxLightSignalErrorCnt_g
TEST.NOTES:
Set value to get and check return value
TEST.END_NOTES:
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_MaxLightSignalErrorCnt_g:0x3F
TEST.EXPECTED:G5_ASIC_Control_sr.get_rb_MaxLightSignalErrorCnt_g.return:0x3F
TEST.END

-- Subprogram: get_rb_VDD_LightSignalErrorCnt_g

-- Test Case: rb_VDD_LightSignalErrorCnt_g
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:get_rb_VDD_LightSignalErrorCnt_g
TEST.NEW
TEST.NAME:rb_VDD_LightSignalErrorCnt_g
TEST.NOTES:
Set value to get and check return value
TEST.END_NOTES:
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_VDD_LightSignalErrorCnt_g:0x3F
TEST.EXPECTED:G5_ASIC_Control_sr.get_rb_VDD_LightSignalErrorCnt_g.return:0x3F
TEST.END

-- Subprogram: get_rb_Vref_LightSignalErrorCnt_g

-- Test Case: rb_Vref_LightSignalErrorCnt_g
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:get_rb_Vref_LightSignalErrorCnt_g
TEST.NEW
TEST.NAME:rb_Vref_LightSignalErrorCnt_g
TEST.NOTES:
Set value to get and check return value
TEST.END_NOTES:
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Vref_LightSignalErrorCnt_g:0x3F
TEST.EXPECTED:G5_ASIC_Control_sr.get_rb_Vref_LightSignalErrorCnt_g.return:0x3F
TEST.END

-- Subprogram: get_rw_ALS1_ASIC_g

-- Test Case: rw_ALS1_ASIC_g
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:get_rw_ALS1_ASIC_g
TEST.NEW
TEST.NAME:rw_ALS1_ASIC_g
TEST.NOTES:
Set value to get and check return value
TEST.END_NOTES:
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALSxADval_g[0].avg:0x3F
TEST.EXPECTED:G5_ASIC_Control_sr.get_rw_ALS1_ASIC_g.return:0x3F
TEST.END

-- Subprogram: get_rw_ALS2_ASIC_g

-- Test Case: rw_ALS2_ASIC_g
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:get_rw_ALS2_ASIC_g
TEST.NEW
TEST.NAME:rw_ALS2_ASIC_g
TEST.NOTES:
Set value to get and check return value
TEST.END_NOTES:
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALSxADval_g[1].avg:0x3F
TEST.EXPECTED:G5_ASIC_Control_sr.get_rw_ALS2_ASIC_g.return:0x3F
TEST.END

-- Subprogram: get_rw_ALS2_INC_ASIC_g

-- Test Case: rw_ALS2_INC_ASIC_g
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:get_rw_ALS2_INC_ASIC_g
TEST.NEW
TEST.NAME:rw_ALS2_INC_ASIC_g
TEST.NOTES:
Set value to get and check return value
TEST.END_NOTES:
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALSxADval_g[1].avginc:0x3F
TEST.EXPECTED:G5_ASIC_Control_sr.get_rw_ALS2_INC_ASIC_g.return:0x3F
TEST.END

-- Subprogram: get_rw_ALS5_ASIC_g

-- Test Case: rw_ALS5_ASIC_g
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:get_rw_ALS5_ASIC_g
TEST.NEW
TEST.NAME:rw_ALS5_ASIC_g
TEST.NOTES:
Set value to get and check return value
TEST.END_NOTES:
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALSxADval_g[4].avg:0x3F
TEST.EXPECTED:G5_ASIC_Control_sr.get_rw_ALS5_ASIC_g.return:0x3F
TEST.END

-- Subprogram: get_rw_ALS5_INC_ASIC_g

-- Test Case: rw_ALS5_INC_ASIC_g
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:get_rw_ALS5_INC_ASIC_g
TEST.NEW
TEST.NAME:rw_ALS5_INC_ASIC_g
TEST.NOTES:
Set value to get and check return value
TEST.END_NOTES:
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALSxADval_g[4].avginc:0x3F
TEST.EXPECTED:G5_ASIC_Control_sr.get_rw_ALS5_INC_ASIC_g.return:0x3F
TEST.END

-- Subprogram: get_rw_ALS6_ASIC_g

-- Test Case: rw_ALS6_ASIC_g
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:get_rw_ALS6_ASIC_g
TEST.NEW
TEST.NAME:rw_ALS6_ASIC_g
TEST.NOTES:
Set value to get and check return value
TEST.END_NOTES:
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALSxADval_g[5].avg:0x3F
TEST.EXPECTED:G5_ASIC_Control_sr.get_rw_ALS6_ASIC_g.return:0x3F
TEST.END

-- Subprogram: get_rw_Amb_INC_light16bit_g

-- Test Case: rw_Amb_INC_light16bit
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:get_rw_Amb_INC_light16bit_g
TEST.NEW
TEST.NAME:rw_Amb_INC_light16bit
TEST.NOTES:
Set value to get and check return value
TEST.END_NOTES:
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rw_Amb_INC_light16bit_g:0x3F
TEST.EXPECTED:G5_ASIC_Control_sr.get_rw_Amb_INC_light16bit_g.return:0x3F
TEST.END

-- Subprogram: get_rw_Amb_INC_light16bit_thrs_g

-- Test Case: rw_Amb_INC_light16bit_thrs_g
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:get_rw_Amb_INC_light16bit_thrs_g
TEST.NEW
TEST.NAME:rw_Amb_INC_light16bit_thrs_g
TEST.NOTES:
Set value to get and check return value
TEST.END_NOTES:
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rw_Amb_INC_light16bit_thrs_g:0x3F
TEST.EXPECTED:G5_ASIC_Control_sr.get_rw_Amb_INC_light16bit_thrs_g.return:0x3F
TEST.END

-- Subprogram: get_rw_Amb_light16bit_g

-- Test Case: get_rw_Amb_light16bit_g.001
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:get_rw_Amb_light16bit_g
TEST.NEW
TEST.NAME:get_rw_Amb_light16bit_g.001
TEST.NOTES:
Set value to get and check return value
TEST.END_NOTES:
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rw_Amb_light16bit_g:0x3F
TEST.EXPECTED:G5_ASIC_Control_sr.get_rw_Amb_light16bit_g.return:63
TEST.ATTRIBUTES:G5_ASIC_Control_sr.<<GLOBAL>>.rw_Amb_light16bit_g:EXPECTED_BASE=16
TEST.END

-- Subprogram: get_rw_FW_INC_light16bit_g

-- Test Case: rw_FW_INC_light16bit_g
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:get_rw_FW_INC_light16bit_g
TEST.NEW
TEST.NAME:rw_FW_INC_light16bit_g
TEST.NOTES:
Set value to get and check return value
TEST.END_NOTES:
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rw_FW_INC_light16bit_g:0x3F
TEST.EXPECTED:G5_ASIC_Control_sr.get_rw_FW_INC_light16bit_g.return:0x3F
TEST.END

-- Subprogram: get_rw_FW_INC_light16bit_thrs_g

-- Test Case: rw_FW_INC_light16bit_thrs_g
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:get_rw_FW_INC_light16bit_thrs_g
TEST.NEW
TEST.NAME:rw_FW_INC_light16bit_thrs_g
TEST.NOTES:
Set value to get and check return value
TEST.END_NOTES:
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rw_FW_INC_light16bit_thrs_g:0x3F
TEST.EXPECTED:G5_ASIC_Control_sr.get_rw_FW_INC_light16bit_thrs_g.return:0x3F
TEST.END

-- Subprogram: get_rw_FW_light16bit_g

-- Test Case: get_rw_FW_light16bit_g.001
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:get_rw_FW_light16bit_g
TEST.NEW
TEST.NAME:get_rw_FW_light16bit_g.001
TEST.NOTES:
Set value to get and check return value
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rw_FW_light16bit_g:0x3F
TEST.EXPECTED:G5_ASIC_Control_sr.get_rw_FW_light16bit_g.return:0x3F
TEST.END

-- Subprogram: get_rw_INREC_ASIC_g

-- Test Case: rw_INREC_ASIC_g
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:get_rw_INREC_ASIC_g
TEST.NEW
TEST.NAME:rw_INREC_ASIC_g
TEST.NOTES:
Set value to get and check return value
TEST.END_NOTES:
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALSxADval_g[6].avg:0x3F
TEST.EXPECTED:G5_ASIC_Control_sr.get_rw_INREC_ASIC_g.return:0x3F
TEST.END

-- Subprogram: get_rw_INREC_INC_ASIC_g

-- Test Case: rw_INREC_INC_ASIC_g
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:get_rw_INREC_INC_ASIC_g
TEST.NEW
TEST.NAME:rw_INREC_INC_ASIC_g
TEST.NOTES:
Set value to get and check return value
TEST.END_NOTES:
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALSxADval_g[6].avginc:0x3F
TEST.EXPECTED:G5_ASIC_Control_sr.get_rw_INREC_INC_ASIC_g.return:0x3F
TEST.END

-- Subprogram: get_rw_IR_INC_light16bit_g

-- Test Case: rw_IR_INC_light16bit_g
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:get_rw_IR_INC_light16bit_g
TEST.NEW
TEST.NAME:rw_IR_INC_light16bit_g
TEST.NOTES:
Set value to get and check return value
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rw_IR_INC_light16bit_g:0x3F
TEST.EXPECTED:G5_ASIC_Control_sr.get_rw_IR_INC_light16bit_g.return:0x3F
TEST.END

-- Subprogram: get_rw_IR_INC_light16bit_thrs_g

-- Test Case: rw_IR_INC_light16bit_thrs_g
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:get_rw_IR_INC_light16bit_thrs_g
TEST.NEW
TEST.NAME:rw_IR_INC_light16bit_thrs_g
TEST.NOTES:
Set value to get and check return value
TEST.END_NOTES:
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rw_IR_INC_light16bit_thrs_g:0x3F
TEST.EXPECTED:G5_ASIC_Control_sr.get_rw_IR_INC_light16bit_thrs_g.return:0x3F
TEST.END

-- Subprogram: get_rw_IR_light16bit_g

-- Test Case: get_rw_IR_light16bit_g.001
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:get_rw_IR_light16bit_g
TEST.NEW
TEST.NAME:get_rw_IR_light16bit_g.001
TEST.NOTES:
Set value to get and check return value
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rw_IR_light16bit_g:0x3F
TEST.EXPECTED:G5_ASIC_Control_sr.get_rw_IR_light16bit_g.return:0x3F
TEST.END

-- Subprogram: get_rw_VICALHI_IHI_GHI_ASIC_g

-- Test Case: rw_VICALHI_IHI_GHI_ASIC_g
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:get_rw_VICALHI_IHI_GHI_ASIC_g
TEST.NEW
TEST.NAME:rw_VICALHI_IHI_GHI_ASIC_g
TEST.NOTES:
Set value to get and check return value
TEST.END_NOTES:
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALI_CalibAD_g[5].avg:0x3F
TEST.EXPECTED:G5_ASIC_Control_sr.get_rw_VICALHI_IHI_GHI_ASIC_g.return:0x3F
TEST.END

-- Subprogram: get_rw_VICALHI_IHI_GHI_INC_ASIC_g

-- Test Case: rw_VICALHI_IHI_GHI_INC_ASIC_g
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:get_rw_VICALHI_IHI_GHI_INC_ASIC_g
TEST.NEW
TEST.NAME:rw_VICALHI_IHI_GHI_INC_ASIC_g
TEST.NOTES:
Set value to get and check return value
TEST.END_NOTES:
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALI_CalibAD_g[9].avg:0x3F
TEST.EXPECTED:G5_ASIC_Control_sr.get_rw_VICALHI_IHI_GHI_INC_ASIC_g.return:0x3F
TEST.END

-- Subprogram: get_rw_VICALLO_ILO_GHI_ASIC_g

-- Test Case: rw_VICALLO_ILO_GHI_ASIC_g
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:get_rw_VICALLO_ILO_GHI_ASIC_g
TEST.NEW
TEST.NAME:rw_VICALLO_ILO_GHI_ASIC_g
TEST.NOTES:
Set value to get and check return value
TEST.END_NOTES:
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALI_CalibAD_g[4].avg:0x3F
TEST.EXPECTED:G5_ASIC_Control_sr.get_rw_VICALLO_ILO_GHI_ASIC_g.return:0x3F
TEST.END

-- Subprogram: get_rw_VIHI_ICALHI_GHI_ASIC_g

-- Test Case: rw_VIHI_ICALHI_GHI_ASIC_g
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:get_rw_VIHI_ICALHI_GHI_ASIC_g
TEST.NEW
TEST.NAME:rw_VIHI_ICALHI_GHI_ASIC_g
TEST.NOTES:
Set value to get and check return value
TEST.END_NOTES:
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALI_CalibAD_g[3].avg:0x3F
TEST.EXPECTED:G5_ASIC_Control_sr.get_rw_VIHI_ICALHI_GHI_ASIC_g.return:0x3F
TEST.END

-- Subprogram: get_rw_VIHI_ICALHI_GHI_INC_ASIC_g

-- Test Case: rw_VIHI_ICALHI_GHI_INC_ASIC_g
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:get_rw_VIHI_ICALHI_GHI_INC_ASIC_g
TEST.NEW
TEST.NAME:rw_VIHI_ICALHI_GHI_INC_ASIC_g
TEST.NOTES:
Set value to get and check return value
TEST.END_NOTES:
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALI_CalibAD_g[8].avg:0x3F
TEST.EXPECTED:G5_ASIC_Control_sr.get_rw_VIHI_ICALHI_GHI_INC_ASIC_g.return:0x3F
TEST.END

-- Subprogram: get_rw_VIHI_ILO_GLO_ASIC_g

-- Test Case: rw_VIHI_ILO_GLO_ASIC_g
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:get_rw_VIHI_ILO_GLO_ASIC_g
TEST.NEW
TEST.NAME:rw_VIHI_ILO_GLO_ASIC_g
TEST.NOTES:
Set value to get and check return value
TEST.END_NOTES:
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALI_CalibAD_g[1].avg:0x3F
TEST.EXPECTED:G5_ASIC_Control_sr.get_rw_VIHI_ILO_GLO_ASIC_g.return:0x3F
TEST.END

-- Subprogram: get_rw_VIHI_ILO_GLO_INC_ASIC_g

-- Test Case: rw_VIHI_ILO_GLO_INC_ASIC_g
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:get_rw_VIHI_ILO_GLO_INC_ASIC_g
TEST.NEW
TEST.NAME:rw_VIHI_ILO_GLO_INC_ASIC_g
TEST.NOTES:
Set value to get and check return value
TEST.END_NOTES:
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALI_CalibAD_g[7].avg:0x3F
TEST.EXPECTED:G5_ASIC_Control_sr.get_rw_VIHI_ILO_GLO_INC_ASIC_g.return:0x3F
TEST.END

-- Subprogram: get_rw_VILO_ICALLO_GHI_ASIC_g

-- Test Case: rw_VILO_ICALLO_GHI_ASIC_g
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:get_rw_VILO_ICALLO_GHI_ASIC_g
TEST.NEW
TEST.NAME:rw_VILO_ICALLO_GHI_ASIC_g
TEST.NOTES:
Set value to get and check return value
TEST.END_NOTES:
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALI_CalibAD_g[2].avg:0x3F
TEST.EXPECTED:G5_ASIC_Control_sr.get_rw_VILO_ICALLO_GHI_ASIC_g.return:0x3F
TEST.END

-- Subprogram: get_rw_VILO_IHI_GLO_ASIC_g

-- Test Case: rw_VILO_IHI_GLO_ASIC_g
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:get_rw_VILO_IHI_GLO_ASIC_g
TEST.NEW
TEST.NAME:rw_VILO_IHI_GLO_ASIC_g
TEST.NOTES:
Set value to get and check return value
TEST.END_NOTES:
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALI_CalibAD_g[0].avg:0x3F
TEST.EXPECTED:G5_ASIC_Control_sr.get_rw_VILO_IHI_GLO_ASIC_g.return:0x3F
TEST.END

-- Subprogram: get_rw_VILO_IHI_GLO_INC_ASIC_g

-- Test Case: rw_VILO_IHI_GLO_INC_ASIC_g
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:get_rw_VILO_IHI_GLO_INC_ASIC_g
TEST.NEW
TEST.NAME:rw_VILO_IHI_GLO_INC_ASIC_g
TEST.NOTES:
Set value to get and check return value
TEST.END_NOTES:
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALI_CalibAD_g[6].avg:0x3F
TEST.EXPECTED:G5_ASIC_Control_sr.get_rw_VILO_IHI_GLO_INC_ASIC_g.return:0x3F
TEST.END

-- Subprogram: myStop

-- Test Case: myStop
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:myStop
TEST.NEW
TEST.NAME:myStop
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.my_dummy:33
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.my_dummy:0xFE
TEST.END

-- Subprogram: set_ASIC_ALSxADval_Init

-- Test Case: set_ASIC_ALSxADval_Init.001
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:set_ASIC_ALSxADval_Init
TEST.NEW
TEST.NAME:set_ASIC_ALSxADval_Init.001
TEST.NOTES:
Check if all ADC value are initialized to 0x3FF
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALSxADval_g[0].ad:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALSxADval_g[0].avg:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALSxADval_g[0].adinc:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALSxADval_g[0].avginc:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALSxADval_g[1].ad:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALSxADval_g[1].avg:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALSxADval_g[1].adinc:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALSxADval_g[1].avginc:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALSxADval_g[2].ad:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALSxADval_g[2].avg:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALSxADval_g[2].adinc:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALSxADval_g[2].avginc:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALSxADval_g[3].ad:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALSxADval_g[3].avg:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALSxADval_g[3].adinc:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALSxADval_g[3].avginc:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALSxADval_g[4].ad:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALSxADval_g[4].avg:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALSxADval_g[4].adinc:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALSxADval_g[4].avginc:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALSxADval_g[5].ad:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALSxADval_g[5].avg:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALSxADval_g[5].adinc:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALSxADval_g[5].avginc:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALSxADval_g[6].ad:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALSxADval_g[6].avg:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALSxADval_g[6].adinc:0
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALSxADval_g[6].avginc:0
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALSxADval_g[0].ad:0x3FF
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALSxADval_g[0].avg:0x3FF
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALSxADval_g[0].adinc:0x3FF
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALSxADval_g[0].avginc:0x3FF
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALSxADval_g[1].ad:0x3FF
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALSxADval_g[1].avg:0x3FF
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALSxADval_g[1].adinc:0x3FF
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALSxADval_g[1].avginc:0x3FF
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALSxADval_g[2].ad:0x3FF
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALSxADval_g[2].avg:0x3FF
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALSxADval_g[2].adinc:0x3FF
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALSxADval_g[2].avginc:0x3FF
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALSxADval_g[3].ad:0x3FF
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALSxADval_g[3].avg:0x3FF
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALSxADval_g[3].adinc:0x3FF
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALSxADval_g[3].avginc:0x3FF
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALSxADval_g[4].ad:0x3FF
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALSxADval_g[4].avg:0x3FF
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALSxADval_g[4].adinc:0x3FF
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALSxADval_g[4].avginc:0x3FF
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALSxADval_g[5].ad:0x3FF
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALSxADval_g[5].avg:0x3FF
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALSxADval_g[5].adinc:0x3FF
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALSxADval_g[5].avginc:0x3FF
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALSxADval_g[6].ad:0x3FF
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALSxADval_g[6].avg:0x3FF
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALSxADval_g[6].adinc:0x3FF
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALSxADval_g[6].avginc:0x3FF
TEST.END

-- Subprogram: set_ras_ASIC_ALI_CalibAD_g_AD

-- Test Case: ras_ASIC_ALI_CalibAD_g_AD
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:set_ras_ASIC_ALI_CalibAD_g_AD
TEST.NEW
TEST.NAME:ras_ASIC_ALI_CalibAD_g_AD
TEST.NOTES:
Set parameter for position and value and check this value
TEST.END_NOTES:
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALI_CalibAD_g[9].ad:1023
TEST.VALUE:G5_ASIC_Control_sr.set_ras_ASIC_ALI_CalibAD_g_AD.rb_position_l:9
TEST.VALUE:G5_ASIC_Control_sr.set_ras_ASIC_ALI_CalibAD_g_AD.rw_value_l:0x233
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALI_CalibAD_g[9].ad:0x233
TEST.END

-- Subprogram: set_ras_ASIC_ALI_CalibAD_g_AVG

-- Test Case: ras_ASIC_ALI_CalibAD_g_AVG
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:set_ras_ASIC_ALI_CalibAD_g_AVG
TEST.NEW
TEST.NAME:ras_ASIC_ALI_CalibAD_g_AVG
TEST.NOTES:
Set parameter for position and value and check this value
TEST.END_NOTES:
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALI_CalibAD_g[9].avg:0x3FF
TEST.VALUE:G5_ASIC_Control_sr.set_ras_ASIC_ALI_CalibAD_g_AVG.rb_position_l:9
TEST.VALUE:G5_ASIC_Control_sr.set_ras_ASIC_ALI_CalibAD_g_AVG.rw_value_l:0x233
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALI_CalibAD_g[9].avg:0x233
TEST.END

-- Subprogram: set_ras_ASIC_ALSxADval_g_AD

-- Test Case: ras_ASIC_ALSxADval_g_AD
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:set_ras_ASIC_ALSxADval_g_AD
TEST.NEW
TEST.NAME:ras_ASIC_ALSxADval_g_AD
TEST.NOTES:
Set parameter for position and value and check this value
TEST.END_NOTES:
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALSxADval_g[0].ad:0x3FF
TEST.VALUE:G5_ASIC_Control_sr.set_ras_ASIC_ALSxADval_g_AD.rb_position_l:0
TEST.VALUE:G5_ASIC_Control_sr.set_ras_ASIC_ALSxADval_g_AD.rw_value_l:0x233
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALSxADval_g[0].ad:0x233
TEST.END

-- Subprogram: set_ras_ASIC_ALSxADval_g_AVG

-- Test Case: ras_ASIC_ALSxADval_g_AVG
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:set_ras_ASIC_ALSxADval_g_AVG
TEST.NEW
TEST.NAME:ras_ASIC_ALSxADval_g_AVG
TEST.NOTES:
Set parameter for position and value and check this value
TEST.END_NOTES:
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALSxADval_g[6].avg:0x3FF
TEST.VALUE:G5_ASIC_Control_sr.set_ras_ASIC_ALSxADval_g_AVG.rb_position_l:6
TEST.VALUE:G5_ASIC_Control_sr.set_ras_ASIC_ALSxADval_g_AVG.rw_value_l:0x233
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALSxADval_g[6].avg:0x233
TEST.END

-- Subprogram: set_ras_ASIC_ALSxADval_g_INC_AD

-- Test Case: ras_ASIC_ALSxADval_g_INC_AD
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:set_ras_ASIC_ALSxADval_g_INC_AD
TEST.NEW
TEST.NAME:ras_ASIC_ALSxADval_g_INC_AD
TEST.NOTES:
Set parameter for position and value and check this value
TEST.END_NOTES:
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALSxADval_g[6].adinc:1023
TEST.VALUE:G5_ASIC_Control_sr.set_ras_ASIC_ALSxADval_g_INC_AD.rb_position_l:6
TEST.VALUE:G5_ASIC_Control_sr.set_ras_ASIC_ALSxADval_g_INC_AD.rw_value_l:0x233
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALSxADval_g[6].adinc:0x233
TEST.END

-- Subprogram: set_ras_ASIC_ALSxADval_g_INC_AVG

-- Test Case: ras_ASIC_ALSxADval_g_INC_AVG
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:set_ras_ASIC_ALSxADval_g_INC_AVG
TEST.NEW
TEST.NAME:ras_ASIC_ALSxADval_g_INC_AVG
TEST.NOTES:
Set parameter for position and value and check this value
TEST.END_NOTES:
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALSxADval_g[6].avginc:0x3FF
TEST.VALUE:G5_ASIC_Control_sr.set_ras_ASIC_ALSxADval_g_INC_AVG.rb_position_l:6
TEST.VALUE:G5_ASIC_Control_sr.set_ras_ASIC_ALSxADval_g_INC_AVG.rw_value_l:0x233
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.ras_ASIC_ALSxADval_g[6].avginc:0x233
TEST.ATTRIBUTES:G5_ASIC_Control_sr.set_ras_ASIC_ALSxADval_g_INC_AD.rw_value_l:INPUT_BASE=16
TEST.END

-- Subprogram: set_rb_Asic_measureMode_mg

-- Test Case: rb_Asic_measureMode_mg
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:set_rb_Asic_measureMode_mg
TEST.NEW
TEST.NAME:rb_Asic_measureMode_mg
TEST.NOTES:
Set parameter value and check this value
TEST.END_NOTES:
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:63
TEST.VALUE:G5_ASIC_Control_sr.set_rb_Asic_measureMode_mg.a:0x23
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Asic_measureMode_mg:0x23
TEST.END

-- Subprogram: set_rb_LEDx_LStop_error_cnt_g

-- Test Case: rb_LEDx_LStop_error_cnt_g
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:set_rb_LEDx_LStop_error_cnt_g
TEST.NEW
TEST.NAME:rb_LEDx_LStop_error_cnt_g
TEST.NOTES:
Set parameter value and check this value
TEST.END_NOTES:
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_LEDx_LStop_error_cnt_g:63
TEST.VALUE:G5_ASIC_Control_sr.set_rb_LEDx_LStop_error_cnt_g.a:0x23
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_LEDx_LStop_error_cnt_g:0x23
TEST.END

-- Subprogram: set_rb_LightSignalErrorCnt_g

-- Test Case: rb_LightSignalErrorCnt_g
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:set_rb_LightSignalErrorCnt_g
TEST.NEW
TEST.NAME:rb_LightSignalErrorCnt_g
TEST.NOTES:
Set parameter value and check this value
TEST.END_NOTES:
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_LightSignalErrorCnt_g:63
TEST.VALUE:G5_ASIC_Control_sr.set_rb_LightSignalErrorCnt_g.temp_LightSignalErrorCnt:0x23
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_LightSignalErrorCnt_g:0x23
TEST.END

-- Subprogram: set_rb_VDD_LightSignalErrorCnt_g

-- Test Case: rb_VDD_LightSignalErrorCnt_g
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:set_rb_VDD_LightSignalErrorCnt_g
TEST.NEW
TEST.NAME:rb_VDD_LightSignalErrorCnt_g
TEST.NOTES:
Set parameter value and check this value
TEST.END_NOTES:
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_VDD_LightSignalErrorCnt_g:0x3F
TEST.VALUE:G5_ASIC_Control_sr.set_rb_VDD_LightSignalErrorCnt_g.a:0x23
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_VDD_LightSignalErrorCnt_g:0x23
TEST.ATTRIBUTES:G5_ASIC_Control_sr.set_rb_LightSignalErrorCnt_g.temp_LightSignalErrorCnt:INPUT_BASE=16
TEST.ATTRIBUTES:G5_ASIC_Control_sr.set_rb_LEDx_LStop_error_cnt_g.a:INPUT_BASE=16
TEST.END

-- Subprogram: set_rb_Vref_LightSignalErrorCnt_g

-- Test Case: rb_Vref_LightSignalErrorCnt_g
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:set_rb_Vref_LightSignalErrorCnt_g
TEST.NEW
TEST.NAME:rb_Vref_LightSignalErrorCnt_g
TEST.NOTES:
Set parameter value and check this value
TEST.END_NOTES:
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Vref_LightSignalErrorCnt_g:0x3F
TEST.VALUE:G5_ASIC_Control_sr.set_rb_Vref_LightSignalErrorCnt_g.Vref_LightSignalErrorCnt:0x23
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rb_Vref_LightSignalErrorCnt_g:0x23
TEST.END

-- Subprogram: set_rw_Amb_INC_light16bit_g

-- Test Case: rw_Amb_INC_light16bit_g
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:set_rw_Amb_INC_light16bit_g
TEST.NEW
TEST.NAME:rw_Amb_INC_light16bit_g
TEST.NOTES:
Set parameter value and check this value
TEST.END_NOTES:
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rw_Amb_INC_light16bit_g:63
TEST.VALUE:G5_ASIC_Control_sr.set_rw_Amb_INC_light16bit_g.rw_Value_l:0x23
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rw_Amb_INC_light16bit_g:0x23
TEST.END

-- Subprogram: set_rw_Amb_light16bit_g

-- Test Case: rw_Amb_light16bit_g
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:set_rw_Amb_light16bit_g
TEST.NEW
TEST.NAME:rw_Amb_light16bit_g
TEST.NOTES:
Set parameter value and check this value
TEST.END_NOTES:
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rw_Amb_light16bit_g:16383
TEST.VALUE:G5_ASIC_Control_sr.set_rw_Amb_light16bit_g.rw_Value_l:0x2333
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rw_Amb_light16bit_g:0x2333
TEST.END

-- Subprogram: set_rw_FW_INC_light16bit_g

-- Test Case: rw_FW_INC_light16bit_g
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:set_rw_FW_INC_light16bit_g
TEST.NEW
TEST.NAME:rw_FW_INC_light16bit_g
TEST.NOTES:
Set parameter value and check this value
TEST.END_NOTES:
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rw_FW_INC_light16bit_g:0x3F
TEST.VALUE:G5_ASIC_Control_sr.set_rw_FW_INC_light16bit_g.rw_Value_l:0x23
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rw_FW_INC_light16bit_g:0x23
TEST.END

-- Subprogram: set_rw_FW_light16bit_g

-- Test Case: rw_FW_light16bit_g
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:set_rw_FW_light16bit_g
TEST.NEW
TEST.NAME:rw_FW_light16bit_g
TEST.NOTES:
Set parameter value and check this value
TEST.END_NOTES:
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rw_FW_light16bit_g:0x3FFF
TEST.VALUE:G5_ASIC_Control_sr.set_rw_FW_light16bit_g.rw_Value_l:0x2333
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rw_FW_light16bit_g:0x2333
TEST.END

-- Subprogram: set_rw_IR_light16bit_g

-- Test Case: rw_IR_light16bit_g
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:set_rw_IR_light16bit_g
TEST.NEW
TEST.NAME:rw_IR_light16bit_g
TEST.NOTES:
Set parameter value and check this value
TEST.END_NOTES:
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rw_IR_light16bit_g:0x3FFF
TEST.VALUE:G5_ASIC_Control_sr.set_rw_IR_light16bit_g.rw_Value_l:0x2333
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rw_IR_light16bit_g:0x2333
TEST.END

-- Subprogram: set_rw_rw_IR_INC_light16bit_g

-- Test Case: rw_rw_IR_INC_light16bit_g
TEST.UNIT:G5_ASIC_Control_sr
TEST.SUBPROGRAM:set_rw_rw_IR_INC_light16bit_g
TEST.NEW
TEST.NAME:rw_rw_IR_INC_light16bit_g
TEST.NOTES:
Set parameter value and check this value
TEST.END_NOTES:
TEST.VALUE:G5_ASIC_Control_sr.<<GLOBAL>>.rw_IR_INC_light16bit_g:0x3F
TEST.VALUE:G5_ASIC_Control_sr.set_rw_rw_IR_INC_light16bit_g.rw_Value_l:0x23
TEST.EXPECTED:G5_ASIC_Control_sr.<<GLOBAL>>.rw_IR_INC_light16bit_g:0x23
TEST.END
