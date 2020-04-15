-- VectorCAST 6.2n
-- Test Case Script
-- 
-- Environment    : G5_APPLI_TIMER
-- Unit(s) Under Test: G5_Appli_timer
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Unit: G5_Appli_timer

-- Subprogram: AD_ConversionPerIntStart

-- Test Case: AD_ConversionPerIntStart.001
TEST.UNIT:G5_Appli_timer
TEST.SUBPROGRAM:AD_ConversionPerIntStart
TEST.NEW
TEST.NAME:AD_ConversionPerIntStart.001
TEST.VALUE:G5_Appli_timer.<<GLOBAL>>.rb_ASIC_ControlMode_g:5
TEST.VALUE:G5_Appli_timer.AD_ConversionPerIntStart.rb_channel_l:2
TEST.EXPECTED:G5_Appli_timer.AD_ConversionPerIntStart.rb_channel_l:2
TEST.END

-- Test Case: AD_ConversionPerIntStart.002
TEST.UNIT:G5_Appli_timer
TEST.SUBPROGRAM:AD_ConversionPerIntStart
TEST.NEW
TEST.NAME:AD_ConversionPerIntStart.002
TEST.VALUE:G5_Appli_timer.<<GLOBAL>>.rb_ASIC_ControlMode_g:51
TEST.VALUE:G5_Appli_timer.AD_ConversionPerIntStart.rb_channel_l:3
TEST.EXPECTED:G5_Appli_timer.AD_ConversionPerIntStart.rb_channel_l:3
TEST.END

-- Subprogram: AD_ConversionSupplyVoltageUpdate

-- Test Case: AD_ConversionSupplyVU.001
TEST.UNIT:G5_Appli_timer
TEST.SUBPROGRAM:AD_ConversionSupplyVoltageUpdate
TEST.NEW
TEST.NAME:AD_ConversionSupplyVU.001
TEST.VALUE:G5_Appli_timer.<<GLOBAL>>.rb_10msTimer_s:5
TEST.VALUE:G5_Appli_timer.<<GLOBAL>>.rb_ClockFreq_Error_cnt_g:4
TEST.VALUE:G5_Appli_timer.<<GLOBAL>>.rub_PulseCounter:6
TEST.VALUE:G5_Appli_timer.<<GLOBAL>>.rb_SupplyVoltage_mg:10
TEST.EXPECTED:G5_Appli_timer.<<GLOBAL>>.rb_10msTimer_s:5
TEST.EXPECTED:G5_Appli_timer.<<GLOBAL>>.rb_ClockFreq_Error_cnt_g:4
TEST.EXPECTED:G5_Appli_timer.<<GLOBAL>>.rub_PulseCounter:6
TEST.EXPECTED:G5_Appli_timer.<<GLOBAL>>.rb_SupplyVoltage_mg:10
TEST.END

-- Subprogram: Change_AnalogPortToDigital

-- Test Case: Change_AnalogPortToDigital.001
TEST.UNIT:G5_Appli_timer
TEST.SUBPROGRAM:Change_AnalogPortToDigital
TEST.NEW
TEST.NAME:Change_AnalogPortToDigital.001
TEST.VALUE:G5_Appli_timer.<<GLOBAL>>.rb_10msTimer_s:10
TEST.VALUE:G5_Appli_timer.<<GLOBAL>>.rb_ClockFreq_Error_cnt_g:5
TEST.VALUE:G5_Appli_timer.<<GLOBAL>>.rub_PulseCounter:7
TEST.VALUE:G5_Appli_timer.<<GLOBAL>>.rb_InternalTemperature_g:8
TEST.EXPECTED:G5_Appli_timer.<<GLOBAL>>.rb_10msTimer_s:10
TEST.EXPECTED:G5_Appli_timer.<<GLOBAL>>.rb_ClockFreq_Error_cnt_g:5
TEST.EXPECTED:G5_Appli_timer.<<GLOBAL>>.rub_PulseCounter:7
TEST.EXPECTED:G5_Appli_timer.<<GLOBAL>>.rb_InternalTemperature_g:8
TEST.END

-- Subprogram: Change_DigitalPortToAnalog

-- Test Case: Change_DigitalPortToAnalog.001
TEST.UNIT:G5_Appli_timer
TEST.SUBPROGRAM:Change_DigitalPortToAnalog
TEST.NEW
TEST.NAME:Change_DigitalPortToAnalog.001
TEST.VALUE:G5_Appli_timer.<<GLOBAL>>.rb_10msTimer_s:10
TEST.VALUE:G5_Appli_timer.<<GLOBAL>>.rb_ClockFreq_Error_cnt_g:1
TEST.VALUE:G5_Appli_timer.<<GLOBAL>>.uF_uC_Error_g.AllBit:8
TEST.VALUE:G5_Appli_timer.<<GLOBAL>>.rb_SupplyVoltage_mg:5
TEST.EXPECTED:G5_Appli_timer.<<GLOBAL>>.rb_10msTimer_s:10
TEST.EXPECTED:G5_Appli_timer.<<GLOBAL>>.rb_ClockFreq_Error_cnt_g:1
TEST.EXPECTED:G5_Appli_timer.<<GLOBAL>>.uF_uC_Error_g.AllBit:8
TEST.EXPECTED:G5_Appli_timer.<<GLOBAL>>.rb_SupplyVoltage_mg:5
TEST.END
