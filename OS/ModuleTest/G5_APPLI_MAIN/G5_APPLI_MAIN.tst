-- VectorCAST 6.2n
-- Test Case Script
-- 
-- Environment    : G5_APPLI_MAIN
-- Unit(s) Under Test: G5_Appli_main
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Subprogram: Get_ResetSource

-- Test Case: 01_noReset
TEST.UNIT:G5_Appli_main
TEST.SUBPROGRAM:Get_ResetSource
TEST.NEW
TEST.NAME:01_noReset
TEST.NOTES:
No reset and none has previously occured:
RESF = 0x0
rab_InternalResetIndicator[0..3] = 0
uF_Main_Flags not set
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.my_RESF:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.rb_ResetSource_g:<<MIN-1>>
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.rab_InternalResetIndicator[0]:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.rab_InternalResetIndicator[1]:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.rab_InternalResetIndicator[2]:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.rab_InternalResetIndicator[3]:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B0:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B1:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B2:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B3:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B4:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B5:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B6:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B7:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.my_RESF:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.rb_ResetSource_g:<<MAX>>
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.rab_InternalResetIndicator[0]:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.rab_InternalResetIndicator[1]:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.rab_InternalResetIndicator[2]:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.rab_InternalResetIndicator[3]:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B0:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B1:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B2:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B3:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B4:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B5:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B6:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B7:0
TEST.ATTRIBUTES:G5_Appli_main.<<GLOBAL>>.rb_ResetSource_g:INPUT_BASE=16,EXPECTED_BASE=16
TEST.END

-- Test Case: 02_resetOccurs
TEST.UNIT:G5_Appli_main
TEST.SUBPROGRAM:Get_ResetSource
TEST.NEW
TEST.NAME:02_resetOccurs
TEST.NOTES:
Reset occurs
RESF = 0x96
rab_InternalResetIndicator[0..3] = 0xAA, 0xBB, 0xCC and 0xDD respectively
uF_Main_Flags[3] = 0 -> 1 incident counter increment
uF_Main_Flags[5] = 0 -> 1
uF_Main_Flags[7] = 0 -> 1 light switch on
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.my_RESF:0x96
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.rb_ResetSource_g:<<MIN-1>>
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.rab_InternalResetIndicator[0]:<<MAX>>
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.rab_InternalResetIndicator[1]:<<MAX+1>>
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.rab_InternalResetIndicator[2]:<<MIN-1>>
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.rab_InternalResetIndicator[3]:<<MIN>>
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B0:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B1:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B2:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B3:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B4:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B5:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B6:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B7:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.my_RESF:0x96
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.rb_ResetSource_g:0x96
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.rab_InternalResetIndicator[0]:0xAA
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.rab_InternalResetIndicator[1]:0xBB
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.rab_InternalResetIndicator[2]:0xCC
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.rab_InternalResetIndicator[3]:0xDD
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B0:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B1:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B2:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B3:1
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B4:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B5:1
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B6:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B7:1
TEST.ATTRIBUTES:G5_Appli_main.<<GLOBAL>>.rab_InternalResetIndicator[0]:INPUT_BASE=16
TEST.ATTRIBUTES:G5_Appli_main.<<GLOBAL>>.rab_InternalResetIndicator[1]:INPUT_BASE=16
TEST.ATTRIBUTES:G5_Appli_main.<<GLOBAL>>.rab_InternalResetIndicator[2]:INPUT_BASE=16
TEST.ATTRIBUTES:G5_Appli_main.<<GLOBAL>>.rab_InternalResetIndicator[3]:INPUT_BASE=16
TEST.END

-- Test Case: 03_previousReset
TEST.UNIT:G5_Appli_main
TEST.SUBPROGRAM:Get_ResetSource
TEST.NEW
TEST.NAME:03_previousReset
TEST.NOTES:
No reset:
RESF = ~0x96 = 0x69
rab_InternalResetIndicator[0..3] = 0xAA, 0xBB, 0xCC and 0xDD respectively
uF_Main_Flags[3] = 0 -> 1 incident counter increment
uF_Main_Flags[5] = 0 -> 1
uF_Main_Flags[7] = 0 -> 1 light switch on
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.my_RESF:0x69
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.rab_InternalResetIndicator[0]:0xAA
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.rab_InternalResetIndicator[1]:0xBB
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.rab_InternalResetIndicator[2]:0xCC
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.rab_InternalResetIndicator[3]:0xDD
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B0:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B1:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B2:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B3:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B4:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B5:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B6:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B7:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.my_RESF:0x69
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.rab_InternalResetIndicator[0]:0xAA
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.rab_InternalResetIndicator[1]:0xBB
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.rab_InternalResetIndicator[2]:0xCC
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.rab_InternalResetIndicator[3]:0xDD
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B0:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B1:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B2:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B3:1
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B4:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B5:1
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B6:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B7:1
TEST.END

-- Subprogram: VCAST_main

-- Test Case: mainStateCheck
TEST.UNIT:G5_Appli_main
TEST.SUBPROGRAM:VCAST_main
TEST.NEW
TEST.NAME:mainStateCheck
TEST.NOTES:
chack main state:
main_Loop is stubbed by function, otherwise endless loop
Not main loop cannot be tested because it is an endless loop
RAM parity check bit is stubbed by user code for testability
TEST.END_NOTES:
TEST.STUB:G5_Appli_main.main_Loop
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:FALSE
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.my_RPERDIS:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.rb_MainState_mg:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.my_RPERDIS:1
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.rb_MainState_mg:1
TEST.END

-- Subprogram: main_LVI_detection

-- Test Case: 01_noLowVoltageNoVddDelay
TEST.UNIT:G5_Appli_main
TEST.SUBPROGRAM:main_LVI_detection
TEST.NEW
TEST.NAME:01_noLowVoltageNoVddDelay
TEST.NOTES:
No low voltage
get_rb_VDD_LightSignalErrorCnt_g = 0
rb_AfterVddPowerFailDelay_g = 5
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.rb_WDG_LVITaskCounter_g:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.rb_AfterVddPowerFailDelay_g:0
TEST.VALUE:uut_prototype_stubs.get_rb_VDD_LightSignalErrorCnt_g.return:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.rb_WDG_LVITaskCounter_g:1
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.rb_AfterVddPowerFailDelay_g:0
TEST.END

-- Test Case: 02_noLowVoltageVddDelayCount_
TEST.UNIT:G5_Appli_main
TEST.SUBPROGRAM:main_LVI_detection
TEST.NEW
TEST.NAME:02_noLowVoltageVddDelayCount_
TEST.NOTES:
No low voltage
rb_WDG_LVITaskCounter_g = 1 -> 2
get_rb_VDD_LightSignalErrorCnt_g = 0
rb_AfterVddPowerFailDelay_g = 5 -> 4
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.rb_WDG_LVITaskCounter_g:1
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.rb_AfterVddPowerFailDelay_g:0x5
TEST.VALUE:uut_prototype_stubs.get_rb_VDD_LightSignalErrorCnt_g.return:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.rb_WDG_LVITaskCounter_g:2
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.rb_AfterVddPowerFailDelay_g:0x4
TEST.END

-- Test Case: 03_LowVoltageVddDelayMax
TEST.UNIT:G5_Appli_main
TEST.SUBPROGRAM:main_LVI_detection
TEST.NEW
TEST.NAME:03_LowVoltageVddDelayMax
TEST.NOTES:
No low voltage
rb_WDG_LVITaskCounter_g = 0xFF -> 0
get_rb_VDD_LightSignalErrorCnt_g = 1
rb_AfterVddPowerFailDelay_g = 0xFF -> 5
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.rb_WDG_LVITaskCounter_g:<<MAX>>
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.rb_AfterVddPowerFailDelay_g:<<MIN-1>>
TEST.VALUE:uut_prototype_stubs.get_rb_VDD_LightSignalErrorCnt_g.return:1
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.rb_WDG_LVITaskCounter_g:<<MIN>>
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.rb_AfterVddPowerFailDelay_g:5
TEST.END

-- Subprogram: main_Watchdog_check

-- Test Case: 01_watchdogEnableCheckMinMax
TEST.UNIT:G5_Appli_main
TEST.SUBPROGRAM:main_Watchdog_check
TEST.NEW
TEST.NAME:01_watchdogEnableCheckMinMax
TEST.NOTES:
1. rbi_WatchdogCheckEnabel_g = TRUE -> F_Main_Flags_g . Bit . B4 = 1

2. Min and Max conditions not met:
rb_WDGFastTaskCounterMin_g = 0
rb_WDGFastTaskCounterMax_g = 0
rb_WDG_500usTaskCounter_g = 0
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.rb_WDG_500usTaskCounter_g:<<MAX+1>>
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.rb_WDGFastTaskCounterMin_g:<<MIN>>
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.rb_WDGFastTaskCounterMax_g:<<MIN>>
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B0:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B1:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B2:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B3:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B4:1
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B5:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B6:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B7:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.rb_WDG_500usTaskCounter_g:<<MIN>>
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.rb_WDGFastTaskCounterMin_g:<<MIN>>
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.rb_WDGFastTaskCounterMax_g:<<MIN>>
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B0:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B1:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B2:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B3:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B4:1
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B5:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B6:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B7:0
TEST.END

-- Test Case: 02_watchdogEnableCheckMinTrue
TEST.UNIT:G5_Appli_main
TEST.SUBPROGRAM:main_Watchdog_check
TEST.NEW
TEST.NAME:02_watchdogEnableCheckMinTrue
TEST.NOTES:
1. rbi_WatchdogCheckEnabel_g = TRUE -> F_Main_Flags_g . Bit . B4 = 1

2. Min check:
rb_WDG_500usTaskCounter_g = 0
-> rb_WDGFastTaskCounterMax_g = 0
-> rb_WDGFastTaskCounterMin_g = 1 -> 0
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.rb_WDG_500usTaskCounter_g:<<MAX+1>>
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.rb_WDGFastTaskCounterMin_g:<<MIN-1>>
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.rb_WDGFastTaskCounterMax_g:<<MIN>>
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B0:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B1:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B2:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B3:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B4:1
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B5:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B6:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B7:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.rb_WDG_500usTaskCounter_g:0x0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.rb_WDGFastTaskCounterMin_g:<<MIN>>
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.rb_WDGFastTaskCounterMax_g:<<MIN>>
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B0:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B1:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B2:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B3:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B4:1
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B5:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B6:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B7:0
TEST.ATTRIBUTES:G5_Appli_main.<<GLOBAL>>.rb_WDGFastTaskCounterMin_g:INPUT_BASE=16,EXPECTED_BASE=16
TEST.ATTRIBUTES:G5_Appli_main.<<GLOBAL>>.rb_WDG_500usTaskCounter_g:INPUT_BASE=16
TEST.END

-- Test Case: 03_watchdogEnableCheckMaxTrue
TEST.UNIT:G5_Appli_main
TEST.SUBPROGRAM:main_Watchdog_check
TEST.NEW
TEST.NAME:03_watchdogEnableCheckMaxTrue
TEST.NOTES:
1. rbi_WatchdogCheckEnabel_g = TRUE -> F_Main_Flags_g . Bit . B4 = 1

2. Max check:
rb_WDG_500usTaskCounter_g = 0xFF
-> rb_WDGFastTaskCounterMax_g = 0xFE -> 0xFF
-> rb_WDGFastTaskCounterMin_g = 0 -> 0
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.rb_WDG_500usTaskCounter_g:<<MIN-1>>
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.rb_WDGFastTaskCounterMin_g:<<MAX+1>>
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.rb_WDGFastTaskCounterMax_g:0xFE
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B0:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B1:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B2:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B3:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B4:1
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B5:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B6:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B7:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.rb_WDG_500usTaskCounter_g:<<MAX>>
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.rb_WDGFastTaskCounterMin_g:<<MIN>>
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.rb_WDGFastTaskCounterMax_g:<<MAX>>
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B0:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B1:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B2:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B3:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B4:1
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B5:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B6:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B7:0
TEST.ATTRIBUTES:G5_Appli_main.<<GLOBAL>>.rb_WDGFastTaskCounterMin_g:INPUT_BASE=16,EXPECTED_BASE=16
TEST.ATTRIBUTES:G5_Appli_main.<<GLOBAL>>.rb_WDGFastTaskCounterMax_g:EXPECTED_BASE=16
TEST.ATTRIBUTES:G5_Appli_main.<<GLOBAL>>.rb_WDG_500usTaskCounter_g:INPUT_BASE=16,EXPECTED_BASE=16
TEST.END

-- Test Case: 04_taskCounterFalse
TEST.UNIT:G5_Appli_main
TEST.SUBPROGRAM:main_Watchdog_check
TEST.NEW
TEST.NAME:04_taskCounterFalse
TEST.NOTES:
1. rbi_WatchdogCheckEnabel_g = FALSE -> F_Main_Flags_g . Bit . B4 = 1

2. Min and Max conditions not checked:
rb_WDG_500usTaskCounter_g = 0
-> rb_WDGFastTaskCounterMax_g = 0
-> rb_WDGFastTaskCounterMin_g = 0

3. ioRefreshCounter equal 7:
WDTE = 0x50 (REFRESH_INTERNAL_WATCHDOG)
rb_WDG_IORefreshTaskCounter_g = 6
rb_WDG_BusTaskCounter_g = 6
rb_WDG_RainsensorTaskCounter_g = 6
rb_WDG_SCITaskCounter_g = 6
rb_WDG_LVITaskCounter_g = 6
rb_WDG_LightsensorTaskCounter_g = 6
rb_ASIC_ControlMode_g = 50

4. Sensor error 1 and Incident counter 3:
E2_Sensor_Error1_g = 0xF0 (=True) -> 
IncidentCounter3_g = 0xF0 (=FALSE)
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.my_WDTE:<<MIN-1>>
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.my_P3_bit.no0:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.my_P3_bit.no1:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.my_P3_bit.no2:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.my_P3_bit.no3:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.my_P3_bit.no4:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.my_P3_bit.no5:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.my_P3_bit.no6:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.my_P3_bit.no7:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.my_PM3_bit.no0:1
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.my_PM3_bit.no1:1
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.my_PM3_bit.no2:1
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.my_PM3_bit.no3:1
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.my_PM3_bit.no4:1
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.my_PM3_bit.no5:1
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.my_PM3_bit.no6:1
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.my_PM3_bit.no7:1
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.rb_WDG_500usTaskCounter_g:<<MIN>>
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.rb_WDG_IORefreshTaskCounter_g:6
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.rb_WDG_BusTaskCounter_g:6
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.rb_WDG_RainsensorTaskCounter_g:6
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.rb_WDG_SCITaskCounter_g:6
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.rb_WDG_LVITaskCounter_g:6
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.rb_WDG_LightsensorTaskCounter_g:6
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.rb_WDGFastTaskCounterMin_g:<<MIN>>
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.rb_WDGFastTaskCounterMax_g:<<MIN>>
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.rb_ASIC_ControlMode_g:50
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B0:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B1:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B2:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B3:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B4:1
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B5:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B6:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B7:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.my_WDTE:0x50
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.my_P3_bit.no0:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.my_P3_bit.no1:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.my_P3_bit.no2:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.my_P3_bit.no3:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.my_P3_bit.no4:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.my_P3_bit.no5:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.my_P3_bit.no6:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.my_P3_bit.no7:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.my_PM3_bit.no0:1
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.my_PM3_bit.no1:1
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.my_PM3_bit.no2:1
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.my_PM3_bit.no3:1
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.my_PM3_bit.no4:1
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.my_PM3_bit.no5:1
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.my_PM3_bit.no6:1
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.my_PM3_bit.no7:1
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.rb_WDG_500usTaskCounter_g:<<MIN>>
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.rb_WDG_IORefreshTaskCounter_g:6
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.rb_WDG_BusTaskCounter_g:6
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.rb_WDG_RainsensorTaskCounter_g:6
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.rb_WDG_SCITaskCounter_g:6
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.rb_WDG_LVITaskCounter_g:6
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.rb_WDG_LightsensorTaskCounter_g:6
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.rb_WDGFastTaskCounterMin_g:<<MIN>>
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.rb_WDGFastTaskCounterMax_g:<<MIN>>
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.rb_ASIC_ControlMode_g:50
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B0:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B1:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B2:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B3:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B4:1
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B5:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B6:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B7:0
TEST.ATTRIBUTES:G5_Appli_main.<<GLOBAL>>.rb_WDGFastTaskCounterMin_g:INPUT_BASE=16,EXPECTED_BASE=16
TEST.ATTRIBUTES:G5_Appli_main.<<GLOBAL>>.rb_WDGFastTaskCounterMax_g:INPUT_BASE=16,EXPECTED_BASE=16
TEST.ATTRIBUTES:G5_Appli_main.<<GLOBAL>>.rb_WDG_500usTaskCounter_g:INPUT_BASE=16,EXPECTED_BASE=16
TEST.END

-- Test Case: 05_taskCounterFalseWdCheck
TEST.UNIT:G5_Appli_main
TEST.SUBPROGRAM:main_Watchdog_check
TEST.NEW
TEST.NAME:05_taskCounterFalseWdCheck
TEST.NOTES:
1. rbi_WatchdogCheckEnabel_g = FALSE -> F_Main_Flags_g . Bit . B4 = 0 -> 1

2. Min and Max conditions not checked:
rb_WDG_500usTaskCounter_g = 0
-> rb_WDGFastTaskCounterMax_g = 0
-> rb_WDGFastTaskCounterMin_g = 0

3. ioRefreshCounter equal 7 :
WDTE = 0xAC (REFRESH_INTERNAL_WATCHDOG)
po_ExternalWDG_g = TRUE (REFRESH_EXTERNAL_WATCHDOG)
po_DExternalWDG_g = OUTPUT (REFRESH_EXTERNAL_WATCHDOG)
rb_WDG_IORefreshTaskCounter_g = 6 -> 0
rb_WDG_BusTaskCounter_g = 6 -> 0
rb_WDG_RainsensorTaskCounter_g = 6 -> 0
rb_WDG_SCITaskCounter_g = 6 -> 0
rb_WDG_LVITaskCounter_g = 6 -> 0
rb_WDG_LightsensorTaskCounter_g = 6 -> 0
rb_ASIC_ControlMode_g = 51
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.my_WDTE:<<MIN-1>>
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.my_P3_bit.no0:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.my_P3_bit.no1:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.my_P3_bit.no2:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.my_P3_bit.no3:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.my_P3_bit.no4:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.my_P3_bit.no5:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.my_P3_bit.no6:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.my_P3_bit.no7:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.my_PM3_bit.no0:1
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.my_PM3_bit.no1:1
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.my_PM3_bit.no2:1
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.my_PM3_bit.no3:1
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.my_PM3_bit.no4:1
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.my_PM3_bit.no5:1
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.my_PM3_bit.no6:1
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.my_PM3_bit.no7:1
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.rb_WDG_500usTaskCounter_g:<<MIN>>
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.rb_WDG_IORefreshTaskCounter_g:6
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.rb_WDG_BusTaskCounter_g:6
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.rb_WDG_RainsensorTaskCounter_g:6
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.rb_WDG_SCITaskCounter_g:6
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.rb_WDG_LVITaskCounter_g:6
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.rb_WDG_LightsensorTaskCounter_g:6
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.rb_WDGFastTaskCounterMin_g:<<MIN>>
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.rb_WDGFastTaskCounterMax_g:<<MIN>>
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.rb_ASIC_ControlMode_g:51
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B0:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B1:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B2:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B3:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B4:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B5:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B6:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B7:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.my_WDTE:0xAC
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.my_P3_bit.no0:1
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.my_P3_bit.no1:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.my_P3_bit.no2:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.my_P3_bit.no3:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.my_P3_bit.no4:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.my_P3_bit.no5:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.my_P3_bit.no6:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.my_P3_bit.no7:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.my_PM3_bit.no0:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.my_PM3_bit.no1:1
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.my_PM3_bit.no2:1
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.my_PM3_bit.no3:1
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.my_PM3_bit.no4:1
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.my_PM3_bit.no5:1
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.my_PM3_bit.no6:1
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.my_PM3_bit.no7:1
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.rb_WDG_500usTaskCounter_g:<<MIN>>
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.rb_WDG_IORefreshTaskCounter_g:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.rb_WDG_BusTaskCounter_g:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.rb_WDG_RainsensorTaskCounter_g:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.rb_WDG_SCITaskCounter_g:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.rb_WDG_LVITaskCounter_g:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.rb_WDG_LightsensorTaskCounter_g:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.rb_WDGFastTaskCounterMin_g:<<MIN>>
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.rb_WDGFastTaskCounterMax_g:<<MIN>>
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.rb_ASIC_ControlMode_g:51
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B0:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B1:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B2:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B3:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B4:1
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B5:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B6:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B7:0
TEST.ATTRIBUTES:G5_Appli_main.<<GLOBAL>>.rb_WDGFastTaskCounterMin_g:INPUT_BASE=16,EXPECTED_BASE=16
TEST.ATTRIBUTES:G5_Appli_main.<<GLOBAL>>.rb_WDGFastTaskCounterMax_g:INPUT_BASE=16,EXPECTED_BASE=16
TEST.ATTRIBUTES:G5_Appli_main.<<GLOBAL>>.rb_WDG_500usTaskCounter_g:INPUT_BASE=16,EXPECTED_BASE=16
TEST.END

-- Test Case: 06_Wd500usTaskFalse
TEST.UNIT:G5_Appli_main
TEST.SUBPROGRAM:main_Watchdog_check
TEST.NEW
TEST.NAME:06_Wd500usTaskFalse
TEST.NOTES:
1. rbi_WatchdogCheckEnabel_g = FALSE -> F_Main_Flags_g . Bit . B4 = 1

2. Min and Max conditions not checked:
rb_WDG_500usTaskCounter_g = 129
-> rb_WDGFastTaskCounterMax_g = 0
-> rb_WDGFastTaskCounterMin_g = 0

3. ioRefreshCounter equal 7 :
WDTE = 0x50 (REFRESH_INTERNAL_WATCHDOG)
po_ExternalWDG_g = TRUE (REFRESH_EXTERNAL_WATCHDOG)
po_DExternalWDG_g = OUTPUT (REFRESH_EXTERNAL_WATCHDOG)
rb_WDG_IORefreshTaskCounter_g = 7
rb_WDG_BusTaskCounter_g = 7
rb_WDG_RainsensorTaskCounter_g = 7
rb_WDG_SCITaskCounter_g = 7
rb_WDG_LVITaskCounter_g = 7
rb_WDG_LightsensorTaskCounter_g = 7
rb_ASIC_ControlMode_g = 51

4. Sensor error 1 and Incident counter 3:
E2_Sensor_Error1_g = 0x80 (=FALSE)
IncidentCounter3_g = 0xEE (=TRUE) -> 0xFE
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.my_WDTE:<<MIN-1>>
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.my_P3_bit.no0:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.my_P3_bit.no1:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.my_P3_bit.no2:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.my_P3_bit.no3:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.my_P3_bit.no4:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.my_P3_bit.no5:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.my_P3_bit.no6:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.my_P3_bit.no7:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.my_PM3_bit.no0:1
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.my_PM3_bit.no1:1
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.my_PM3_bit.no2:1
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.my_PM3_bit.no3:1
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.my_PM3_bit.no4:1
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.my_PM3_bit.no5:1
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.my_PM3_bit.no6:1
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.my_PM3_bit.no7:1
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.rb_WDG_500usTaskCounter_g:129
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.rb_WDG_IORefreshTaskCounter_g:7
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.rb_WDG_BusTaskCounter_g:7
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.rb_WDG_RainsensorTaskCounter_g:7
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.rb_WDG_SCITaskCounter_g:7
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.rb_WDG_LVITaskCounter_g:7
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.rb_WDG_LightsensorTaskCounter_g:7
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.rb_WDGFastTaskCounterMin_g:<<MIN>>
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.rb_WDGFastTaskCounterMax_g:<<MIN>>
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.EEPROM_Struct_RD.EEPROMStructRD.E2_Sensor_Error1_g:0x80
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.EEPROM_Struct_RD.EEPROMStructRD.IncidentCounter3_g:0xEE
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.rb_ASIC_ControlMode_g:51
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B0:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B1:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B2:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B3:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B4:1
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B5:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B6:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B7:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.my_WDTE:0x50
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.my_P3_bit.no0:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.my_P3_bit.no1:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.my_P3_bit.no2:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.my_P3_bit.no4:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.my_P3_bit.no5:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.my_P3_bit.no6:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.my_P3_bit.no7:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.my_PM3_bit.no0:1
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.my_PM3_bit.no1:1
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.my_PM3_bit.no2:1
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.my_PM3_bit.no3:1
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.my_PM3_bit.no4:1
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.my_PM3_bit.no5:1
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.my_PM3_bit.no6:1
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.my_PM3_bit.no7:1
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.rb_WDG_500usTaskCounter_g:129
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.rb_WDG_IORefreshTaskCounter_g:7
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.rb_WDG_BusTaskCounter_g:7
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.rb_WDG_RainsensorTaskCounter_g:7
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.rb_WDG_SCITaskCounter_g:7
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.rb_WDG_LVITaskCounter_g:7
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.rb_WDG_LightsensorTaskCounter_g:7
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.rb_WDGFastTaskCounterMin_g:<<MIN>>
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.rb_WDGFastTaskCounterMax_g:129
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.EEPROM_Struct_RD.EEPROMStructRD.E2_Sensor_Error1_g:0x80
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.EEPROM_Struct_RD.EEPROMStructRD.IncidentCounter3_g:0xFE
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.rb_ASIC_ControlMode_g:51
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B0:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B1:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B2:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B3:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B4:1
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B5:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B6:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B7:0
TEST.ATTRIBUTES:G5_Appli_main.<<GLOBAL>>.rb_WDGFastTaskCounterMin_g:INPUT_BASE=16,EXPECTED_BASE=16
TEST.ATTRIBUTES:G5_Appli_main.<<GLOBAL>>.rb_WDGFastTaskCounterMax_g:INPUT_BASE=16
TEST.END

-- Test Case: 07_Wd500usTaskTrue
TEST.UNIT:G5_Appli_main
TEST.SUBPROGRAM:main_Watchdog_check
TEST.NEW
TEST.NAME:07_Wd500usTaskTrue
TEST.NOTES:
1. rbi_WatchdogCheckEnabel_g = FALSE -> F_Main_Flags_g . Bit . B4 = 1

2. Min and Max conditions not checked:
rb_WDG_500usTaskCounter_g = 130
-> rb_WDGFastTaskCounterMax_g = 0
-> rb_WDGFastTaskCounterMin_g = 0

3. ioRefreshCounter equal 7 :
WDTE = 0xAC (REFRESH_INTERNAL_WATCHDOG)
po_ExternalWDG_g = TRUE (REFRESH_EXTERNAL_WATCHDOG)
po_DExternalWDG_g = OUTPUT (REFRESH_EXTERNAL_WATCHDOG)
rb_WDG_IORefreshTaskCounter_g = 7 -> 0
rb_WDG_BusTaskCounter_g = 7 -> 0
rb_WDG_RainsensorTaskCounter_g = 7 -> 0
rb_WDG_SCITaskCounter_g = 7 -> 0
rb_WDG_LVITaskCounter_g = 7 -> 0
rb_WDG_LightsensorTaskCounter_g = 7 -> 0
rb_ASIC_ControlMode_g = 51
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.my_WDTE:<<MIN-1>>
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.my_P3_bit.no0:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.my_P3_bit.no1:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.my_P3_bit.no2:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.my_P3_bit.no3:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.my_P3_bit.no4:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.my_P3_bit.no5:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.my_P3_bit.no6:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.my_P3_bit.no7:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.my_PM3_bit.no0:1
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.my_PM3_bit.no1:1
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.my_PM3_bit.no2:1
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.my_PM3_bit.no3:1
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.my_PM3_bit.no4:1
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.my_PM3_bit.no5:1
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.my_PM3_bit.no6:1
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.my_PM3_bit.no7:1
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.rb_WDG_500usTaskCounter_g:130
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.rb_WDG_IORefreshTaskCounter_g:7
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.rb_WDG_BusTaskCounter_g:7
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.rb_WDG_RainsensorTaskCounter_g:7
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.rb_WDG_SCITaskCounter_g:7
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.rb_WDG_LVITaskCounter_g:7
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.rb_WDG_LightsensorTaskCounter_g:7
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.rb_WDGFastTaskCounterMin_g:<<MIN>>
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.rb_WDGFastTaskCounterMax_g:<<MIN>>
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.rb_ASIC_ControlMode_g:51
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B0:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B1:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B2:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B3:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B4:1
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B5:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B6:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B7:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.my_WDTE:0xAC
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.my_P3_bit.no0:1
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.my_P3_bit.no1:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.my_P3_bit.no2:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.my_P3_bit.no4:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.my_P3_bit.no5:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.my_P3_bit.no6:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.my_P3_bit.no7:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.my_PM3_bit.no0:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.my_PM3_bit.no1:1
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.my_PM3_bit.no2:1
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.my_PM3_bit.no3:1
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.my_PM3_bit.no4:1
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.my_PM3_bit.no5:1
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.my_PM3_bit.no6:1
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.my_PM3_bit.no7:1
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.rb_WDG_500usTaskCounter_g:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.rb_WDG_IORefreshTaskCounter_g:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.rb_WDG_BusTaskCounter_g:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.rb_WDG_RainsensorTaskCounter_g:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.rb_WDG_SCITaskCounter_g:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.rb_WDG_LVITaskCounter_g:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.rb_WDG_LightsensorTaskCounter_g:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.rb_WDGFastTaskCounterMin_g:<<MIN>>
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.rb_WDGFastTaskCounterMax_g:130
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.rb_ASIC_ControlMode_g:51
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B0:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B1:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B2:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B3:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B4:1
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B5:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B6:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B7:0
TEST.ATTRIBUTES:G5_Appli_main.<<GLOBAL>>.rb_WDGFastTaskCounterMin_g:INPUT_BASE=16,EXPECTED_BASE=16
TEST.ATTRIBUTES:G5_Appli_main.<<GLOBAL>>.rb_WDGFastTaskCounterMax_g:INPUT_BASE=16
TEST.END

-- Test Case: 08_Wd500usTaskAndInc3False
TEST.UNIT:G5_Appli_main
TEST.SUBPROGRAM:main_Watchdog_check
TEST.NEW
TEST.NAME:08_Wd500usTaskAndInc3False
TEST.NOTES:
1. rbi_WatchdogCheckEnabel_g = FALSE -> F_Main_Flags_g . Bit . B4 = 1

2. Min and Max conditions not checked:
rb_WDG_500usTaskCounter_g = 150
-> rb_WDGFastTaskCounterMax_g = 0
-> rb_WDGFastTaskCounterMin_g = 0

3. ioRefreshCounter equal 7 :
WDTE = 0x50 (REFRESH_INTERNAL_WATCHDOG)
po_ExternalWDG_g = TRUE (REFRESH_EXTERNAL_WATCHDOG)
po_DExternalWDG_g = OUTPUT (REFRESH_EXTERNAL_WATCHDOG)
rb_WDG_IORefreshTaskCounter_g = 7
rb_WDG_BusTaskCounter_g = 7
rb_WDG_RainsensorTaskCounter_g = 7
rb_WDG_SCITaskCounter_g = 7
rb_WDG_LVITaskCounter_g = 7
rb_WDG_LightsensorTaskCounter_g = 7
rb_ASIC_ControlMode_g = 51

4. Sensor error 1 and Incident counter 3:
E2_Sensor_Error1_g = 0x7F (=TRUE)
IncidentCounter3_g = 0xF0 (=FALSE)
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.my_WDTE:<<MIN-1>>
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.my_P3_bit.no0:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.my_P3_bit.no1:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.my_P3_bit.no2:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.my_P3_bit.no3:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.my_P3_bit.no4:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.my_P3_bit.no5:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.my_P3_bit.no6:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.my_P3_bit.no7:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.my_PM3_bit.no0:1
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.my_PM3_bit.no1:1
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.my_PM3_bit.no2:1
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.my_PM3_bit.no3:1
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.my_PM3_bit.no4:1
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.my_PM3_bit.no5:1
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.my_PM3_bit.no6:1
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.my_PM3_bit.no7:1
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.rb_WDG_500usTaskCounter_g:150
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.rb_WDG_IORefreshTaskCounter_g:7
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.rb_WDG_BusTaskCounter_g:7
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.rb_WDG_RainsensorTaskCounter_g:7
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.rb_WDG_SCITaskCounter_g:7
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.rb_WDG_LVITaskCounter_g:7
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.rb_WDG_LightsensorTaskCounter_g:7
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.rb_WDGFastTaskCounterMin_g:<<MIN>>
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.rb_WDGFastTaskCounterMax_g:<<MIN>>
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.EEPROM_Struct_RD.EEPROMStructRD.E2_Sensor_Error1_g:0x7F
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.EEPROM_Struct_RD.EEPROMStructRD.IncidentCounter3_g:0xF0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.rb_ASIC_ControlMode_g:51
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B0:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B1:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B2:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B3:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B4:1
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B5:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B6:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B7:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.my_WDTE:0x50
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.my_P3_bit.no0:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.my_P3_bit.no1:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.my_P3_bit.no2:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.my_P3_bit.no4:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.my_P3_bit.no5:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.my_P3_bit.no6:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.my_P3_bit.no7:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.my_PM3_bit.no0:1
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.my_PM3_bit.no1:1
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.my_PM3_bit.no2:1
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.my_PM3_bit.no3:1
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.my_PM3_bit.no4:1
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.my_PM3_bit.no5:1
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.my_PM3_bit.no6:1
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.my_PM3_bit.no7:1
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.rb_WDG_500usTaskCounter_g:150
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.rb_WDG_IORefreshTaskCounter_g:7
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.rb_WDG_BusTaskCounter_g:7
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.rb_WDG_RainsensorTaskCounter_g:7
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.rb_WDG_SCITaskCounter_g:7
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.rb_WDG_LVITaskCounter_g:7
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.rb_WDG_LightsensorTaskCounter_g:7
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.rb_WDGFastTaskCounterMin_g:<<MIN>>
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.rb_WDGFastTaskCounterMax_g:150
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.EEPROM_Struct_RD.EEPROMStructRD.E2_Sensor_Error1_g:0x7F
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.EEPROM_Struct_RD.EEPROMStructRD.IncidentCounter3_g:0xF0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.rb_ASIC_ControlMode_g:51
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B0:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B1:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B2:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B3:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B4:1
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B5:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B6:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B7:0
TEST.ATTRIBUTES:G5_Appli_main.<<GLOBAL>>.rb_WDGFastTaskCounterMin_g:INPUT_BASE=16,EXPECTED_BASE=16
TEST.ATTRIBUTES:G5_Appli_main.<<GLOBAL>>.rb_WDGFastTaskCounterMax_g:INPUT_BASE=16
TEST.END

-- Test Case: 09_TaskCounterTrue
TEST.UNIT:G5_Appli_main
TEST.SUBPROGRAM:main_Watchdog_check
TEST.NEW
TEST.NAME:09_TaskCounterTrue
TEST.NOTES:
1. rbi_WatchdogCheckEnabel_g = FALSE -> F_Main_Flags_g . Bit . B4 = 1

2. Min and Max conditions not checked:
rb_WDG_500usTaskCounter_g = 0
-> rb_WDGFastTaskCounterMax_g = 0
-> rb_WDGFastTaskCounterMin_g = 0

3. ioRefreshCounter unequal 7 
rb_WDG_IORefreshTaskCounter_g = 7
rb_WDG_BusTaskCounter_g = 7
rb_WDG_RainsensorTaskCounter_g = 7
rb_WDG_SCITaskCounter_g = 7
rb_WDG_LVITaskCounter_g = 7
rb_WDG_LightsensorTaskCounter_g = 7
rb_ASIC_ControlMode_g = 50
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.rb_WDG_500usTaskCounter_g:<<MIN>>
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.rb_WDG_IORefreshTaskCounter_g:7
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.rb_WDG_BusTaskCounter_g:7
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.rb_WDG_RainsensorTaskCounter_g:7
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.rb_WDG_SCITaskCounter_g:7
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.rb_WDG_LVITaskCounter_g:7
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.rb_WDG_LightsensorTaskCounter_g:7
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.rb_WDGFastTaskCounterMin_g:<<MIN>>
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.rb_WDGFastTaskCounterMax_g:<<MIN>>
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.rb_ASIC_ControlMode_g:50
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B0:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B1:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B2:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B3:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B4:1
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B5:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B6:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B7:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.rb_WDG_500usTaskCounter_g:<<MIN>>
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.rb_WDG_IORefreshTaskCounter_g:7
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.rb_WDG_BusTaskCounter_g:7
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.rb_WDG_RainsensorTaskCounter_g:7
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.rb_WDG_SCITaskCounter_g:7
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.rb_WDG_LVITaskCounter_g:7
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.rb_WDG_LightsensorTaskCounter_g:7
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.rb_WDGFastTaskCounterMin_g:<<MIN>>
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.rb_WDGFastTaskCounterMax_g:<<MIN>>
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.rb_ASIC_ControlMode_g:50
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B0:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B1:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B2:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B3:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B4:1
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B5:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B6:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B7:0
TEST.ATTRIBUTES:G5_Appli_main.<<GLOBAL>>.rb_WDGFastTaskCounterMin_g:INPUT_BASE=16,EXPECTED_BASE=16
TEST.ATTRIBUTES:G5_Appli_main.<<GLOBAL>>.rb_WDGFastTaskCounterMax_g:INPUT_BASE=16,EXPECTED_BASE=16
TEST.ATTRIBUTES:G5_Appli_main.<<GLOBAL>>.rb_WDG_500usTaskCounter_g:INPUT_BASE=16,EXPECTED_BASE=16
TEST.END

-- Test Case: 10_IncidentCounter2Inc
TEST.UNIT:G5_Appli_main
TEST.SUBPROGRAM:main_Watchdog_check
TEST.NEW
TEST.NAME:10_IncidentCounter2Inc
TEST.NOTES:
1. rbi_WatchdogCheckEnabel_g = FALSE -> F_Main_Flags_g . Bit . B4 = 1

2. Min and Max conditions not checked:
rb_WDG_500usTaskCounter_g = 0
-> rb_WDGFastTaskCounterMax_g = 0
-> rb_WDGFastTaskCounterMin_g = 0

3. ioRefreshCounter equaunl 7 
rb_WDG_IORefreshTaskCounter_g = 6
rb_WDG_BusTaskCounter_g = 6
rb_WDG_RainsensorTaskCounter_g = 6
rb_WDG_SCITaskCounter_g = 6
rb_WDG_LVITaskCounter_g = 6
rb_WDG_LightsensorTaskCounter_g = 6
rb_ASIC_ControlMode_g = 50

4. Incident Counter 2 is less that 0xF
EEPROMStructRD.IncidentCounter2_g = 0xE -> 0xF

5. SensorError 1 not set
EEPROMStructRD.E2_Sensor_Error1_g = 0x0
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.rb_WDG_500usTaskCounter_g:<<MIN>>
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.rb_WDG_IORefreshTaskCounter_g:6
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.rb_WDG_BusTaskCounter_g:6
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.rb_WDG_RainsensorTaskCounter_g:6
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.rb_WDG_SCITaskCounter_g:6
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.rb_WDG_LVITaskCounter_g:6
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.rb_WDG_LightsensorTaskCounter_g:6
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.rb_WDGFastTaskCounterMin_g:<<MIN>>
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.rb_WDGFastTaskCounterMax_g:<<MIN>>
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.EEPROM_Struct_RD.EEPROMStructRD.E2_Sensor_Error1_g:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.EEPROM_Struct_RD.EEPROMStructRD.IncidentCounter2_g:0xE
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.rb_ASIC_ControlMode_g:50
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B0:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B1:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B2:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B3:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B4:1
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B5:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B6:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B7:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.rb_WDG_500usTaskCounter_g:<<MIN>>
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.rb_WDG_IORefreshTaskCounter_g:6
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.rb_WDG_BusTaskCounter_g:6
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.rb_WDG_RainsensorTaskCounter_g:6
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.rb_WDG_SCITaskCounter_g:6
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.rb_WDG_LVITaskCounter_g:6
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.rb_WDG_LightsensorTaskCounter_g:6
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.rb_WDGFastTaskCounterMin_g:<<MIN>>
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.rb_WDGFastTaskCounterMax_g:<<MIN>>
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.EEPROM_Struct_RD.EEPROMStructRD.E2_Sensor_Error1_g:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.EEPROM_Struct_RD.EEPROMStructRD.IncidentCounter2_g:0xF
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.rb_ASIC_ControlMode_g:50
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B0:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B1:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B2:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B3:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B4:1
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B5:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B6:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B7:0
TEST.ATTRIBUTES:G5_Appli_main.<<GLOBAL>>.rb_WDGFastTaskCounterMin_g:INPUT_BASE=16,EXPECTED_BASE=16
TEST.ATTRIBUTES:G5_Appli_main.<<GLOBAL>>.rb_WDGFastTaskCounterMax_g:INPUT_BASE=16,EXPECTED_BASE=16
TEST.ATTRIBUTES:G5_Appli_main.<<GLOBAL>>.rb_WDG_500usTaskCounter_g:INPUT_BASE=16,EXPECTED_BASE=16
TEST.END

-- Test Case: 11_IncidentCounter2Lim
TEST.UNIT:G5_Appli_main
TEST.SUBPROGRAM:main_Watchdog_check
TEST.NEW
TEST.NAME:11_IncidentCounter2Lim
TEST.NOTES:
1. rbi_WatchdogCheckEnabel_g = FALSE -> F_Main_Flags_g . Bit . B4 = 1

2. Min and Max conditions not checked:
rb_WDG_500usTaskCounter_g = 0
-> rb_WDGFastTaskCounterMax_g = 0
-> rb_WDGFastTaskCounterMin_g = 0

3. ioRefreshCounter equaunl 7 
rb_WDG_IORefreshTaskCounter_g = 6
rb_WDG_BusTaskCounter_g = 6
rb_WDG_RainsensorTaskCounter_g = 6
rb_WDG_SCITaskCounter_g = 6
rb_WDG_LVITaskCounter_g = 6
rb_WDG_LightsensorTaskCounter_g = 6
rb_ASIC_ControlMode_g = 50


4. Incident Counter 2 is 0xF
EEPROMStructRD.IncidentCounter2_g = 0xF

5. SensorError 1 not set
EEPROMStructRD.E2_Sensor_Error1_g = 0x0
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.rb_WDG_500usTaskCounter_g:<<MIN>>
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.rb_WDG_IORefreshTaskCounter_g:6
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.rb_WDG_BusTaskCounter_g:6
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.rb_WDG_RainsensorTaskCounter_g:6
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.rb_WDG_SCITaskCounter_g:6
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.rb_WDG_LVITaskCounter_g:6
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.rb_WDG_LightsensorTaskCounter_g:6
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.rb_WDGFastTaskCounterMin_g:<<MIN>>
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.rb_WDGFastTaskCounterMax_g:<<MIN>>
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.EEPROM_Struct_RD.EEPROMStructRD.E2_Sensor_Error1_g:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.EEPROM_Struct_RD.EEPROMStructRD.IncidentCounter2_g:0xF
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.rb_ASIC_ControlMode_g:50
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B0:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B1:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B2:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B3:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B4:1
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B5:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B6:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B7:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.rb_WDG_500usTaskCounter_g:<<MIN>>
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.rb_WDG_IORefreshTaskCounter_g:6
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.rb_WDG_BusTaskCounter_g:6
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.rb_WDG_RainsensorTaskCounter_g:6
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.rb_WDG_SCITaskCounter_g:6
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.rb_WDG_LVITaskCounter_g:6
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.rb_WDG_LightsensorTaskCounter_g:6
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.rb_WDGFastTaskCounterMin_g:<<MIN>>
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.rb_WDGFastTaskCounterMax_g:<<MIN>>
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.EEPROM_Struct_RD.EEPROMStructRD.E2_Sensor_Error1_g:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.EEPROM_Struct_RD.EEPROMStructRD.IncidentCounter2_g:0xF
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.rb_ASIC_ControlMode_g:50
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B0:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B1:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B2:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B3:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B4:1
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B5:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B6:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B7:0
TEST.ATTRIBUTES:G5_Appli_main.<<GLOBAL>>.rb_WDGFastTaskCounterMin_g:INPUT_BASE=16,EXPECTED_BASE=16
TEST.ATTRIBUTES:G5_Appli_main.<<GLOBAL>>.rb_WDGFastTaskCounterMax_g:INPUT_BASE=16,EXPECTED_BASE=16
TEST.ATTRIBUTES:G5_Appli_main.<<GLOBAL>>.rb_WDG_500usTaskCounter_g:INPUT_BASE=16,EXPECTED_BASE=16
TEST.END

-- Test Case: 12_SensorError1True
TEST.UNIT:G5_Appli_main
TEST.SUBPROGRAM:main_Watchdog_check
TEST.NEW
TEST.NAME:12_SensorError1True
TEST.NOTES:
1. rbi_WatchdogCheckEnabel_g = FALSE -> F_Main_Flags_g . Bit . B4 = 1

2. Min and Max conditions not checked:
rb_WDG_500usTaskCounter_g = 0
-> rb_WDGFastTaskCounterMax_g = 0
-> rb_WDGFastTaskCounterMin_g = 0

3. ioRefreshCounter equaunl 7 
rb_WDG_IORefreshTaskCounter_g = 6
rb_WDG_BusTaskCounter_g = 6
rb_WDG_RainsensorTaskCounter_g = 6
rb_WDG_SCITaskCounter_g = 6
rb_WDG_LVITaskCounter_g = 6
rb_WDG_LightsensorTaskCounter_g = 6
rb_ASIC_ControlMode_g = 50


4. Incident Counter 2 is 0xF
EEPROMStructRD.IncidentCounter2_g = 0xF

5. SensorError 1 set
EEPROMStructRD.E2_Sensor_Error1_g = 0x80
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.rb_WDG_500usTaskCounter_g:<<MIN>>
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.rb_WDG_IORefreshTaskCounter_g:6
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.rb_WDG_BusTaskCounter_g:6
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.rb_WDG_RainsensorTaskCounter_g:6
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.rb_WDG_SCITaskCounter_g:6
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.rb_WDG_LVITaskCounter_g:6
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.rb_WDG_LightsensorTaskCounter_g:6
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.rb_WDGFastTaskCounterMin_g:<<MIN>>
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.rb_WDGFastTaskCounterMax_g:<<MIN>>
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.EEPROM_Struct_RD.EEPROMStructRD.E2_Sensor_Error1_g:0x80
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.EEPROM_Struct_RD.EEPROMStructRD.IncidentCounter2_g:0xF
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.rb_ASIC_ControlMode_g:50
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B0:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B1:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B2:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B3:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B4:1
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B5:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B6:0
TEST.VALUE:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B7:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.rb_WDG_500usTaskCounter_g:<<MIN>>
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.rb_WDG_IORefreshTaskCounter_g:6
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.rb_WDG_BusTaskCounter_g:6
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.rb_WDG_RainsensorTaskCounter_g:6
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.rb_WDG_SCITaskCounter_g:6
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.rb_WDG_LVITaskCounter_g:6
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.rb_WDG_LightsensorTaskCounter_g:6
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.rb_WDGFastTaskCounterMin_g:<<MIN>>
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.rb_WDGFastTaskCounterMax_g:<<MIN>>
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.EEPROM_Struct_RD.EEPROMStructRD.E2_Sensor_Error1_g:0x80
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.EEPROM_Struct_RD.EEPROMStructRD.IncidentCounter2_g:0xF
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.rb_ASIC_ControlMode_g:50
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B0:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B1:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B2:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B3:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B4:1
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B5:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B6:0
TEST.EXPECTED:G5_Appli_main.<<GLOBAL>>.uF_Main_Flags_g.Bit.B7:0
TEST.ATTRIBUTES:G5_Appli_main.<<GLOBAL>>.rb_WDGFastTaskCounterMin_g:INPUT_BASE=16,EXPECTED_BASE=16
TEST.ATTRIBUTES:G5_Appli_main.<<GLOBAL>>.rb_WDGFastTaskCounterMax_g:INPUT_BASE=16,EXPECTED_BASE=16
TEST.ATTRIBUTES:G5_Appli_main.<<GLOBAL>>.rb_WDG_500usTaskCounter_g:INPUT_BASE=16,EXPECTED_BASE=16
TEST.END
