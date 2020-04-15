-- VectorCAST 6.2n
-- Test Case Script
-- 
-- Environment    : G5_CHECK_SR
-- Unit(s) Under Test: G5_Check_sr
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Unit: G5_Check_sr

-- Subprogram: CheckRAM

-- Test Case: lowerRamBoarderCheck
TEST.UNIT:G5_Check_sr
TEST.SUBPROGRAM:CheckRAM
TEST.NEW
TEST.NAME:lowerRamBoarderCheck
TEST.COMPOUND_ONLY
TEST.NOTES:
Set upper RAM boarder to cb_LOWER_RAM_BOARDER_s - 1 (see test case user code)
Set lower RAM boarder to cb_LOWER_RAM_BOARDER_s (see test case user code)
Compound only test with 2 iterations:
Iteration 1
-> RAM test address pointer points to lower RAM boader, cb_LOWER_RAM_BOARDER_s
-> Lower RAM boarder condition is true
-> Upper RAM boarder condition is false
-> RAM test address pointer is not incremented (stays at start address = cb_LOWER_RAM_BOARDER_s)

Iteration 2
-> RAM test address pointer points address cb_LOWER_RAM_BOARDER_s
-> Lower RAM boarder condition is false
-> Upper RAM boarder condition is true
-> RAM test address pointer is reset to point to start address, 0xFEF00U
-> Bit 5 of uF_Diagnose_pre_Flag to indicate end of RAM test
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_Check_sr.<<GLOBAL>>.my_LOWER_RAM_BOARDER_s:<<MAX>>
TEST.VALUE:G5_Check_sr.<<GLOBAL>>.my_UPPER_RAM_BOARDER_s:<<MAX>>
TEST.VALUE:G5_Check_sr.<<GLOBAL>>.rw_RAM_DefectCell_g:<<MID>>
TEST.VALUE:G5_Check_sr.<<GLOBAL>>.uF_Diagnose_pre_Flag.Bit.B0:0
TEST.VALUE:G5_Check_sr.<<GLOBAL>>.uF_Diagnose_pre_Flag.Bit.B1:0
TEST.VALUE:G5_Check_sr.<<GLOBAL>>.uF_Diagnose_pre_Flag.Bit.B2:0
TEST.VALUE:G5_Check_sr.<<GLOBAL>>.uF_Diagnose_pre_Flag.Bit.B3:0
TEST.VALUE:G5_Check_sr.<<GLOBAL>>.uF_Diagnose_pre_Flag.Bit.B4:0
TEST.VALUE:G5_Check_sr.<<GLOBAL>>.uF_Diagnose_pre_Flag.Bit.B5:0
TEST.VALUE:G5_Check_sr.<<GLOBAL>>.uF_Diagnose_pre_Flag.Bit.B6:0
TEST.VALUE:G5_Check_sr.<<GLOBAL>>.uF_Diagnose_pre_Flag.Bit.B7:0
TEST.EXPECTED:G5_Check_sr.<<GLOBAL>>.my_LOWER_RAM_BOARDER_s:cb_LOWER_RAM_BOARDER_s
TEST.EXPECTED:G5_Check_sr.<<GLOBAL>>.rw_RAM_DefectCell_g:0x7FFF
TEST.EXPECTED:G5_Check_sr.<<GLOBAL>>.uF_Diagnose_pre_Flag.Bit.B0:0
TEST.EXPECTED:G5_Check_sr.<<GLOBAL>>.uF_Diagnose_pre_Flag.Bit.B1:0
TEST.EXPECTED:G5_Check_sr.<<GLOBAL>>.uF_Diagnose_pre_Flag.Bit.B2:0
TEST.EXPECTED:G5_Check_sr.<<GLOBAL>>.uF_Diagnose_pre_Flag.Bit.B3:0
TEST.EXPECTED:G5_Check_sr.<<GLOBAL>>.uF_Diagnose_pre_Flag.Bit.B4:0
TEST.EXPECTED:G5_Check_sr.<<GLOBAL>>.uF_Diagnose_pre_Flag.Bit.B5:1
TEST.EXPECTED:G5_Check_sr.<<GLOBAL>>.uF_Diagnose_pre_Flag.Bit.B6:0
TEST.EXPECTED:G5_Check_sr.<<GLOBAL>>.uF_Diagnose_pre_Flag.Bit.B7:0
TEST.ATTRIBUTES:G5_Check_sr.<<GLOBAL>>.my_LOWER_RAM_BOARDER_s:EXPECTED_BASE=16
TEST.ATTRIBUTES:G5_Check_sr.<<GLOBAL>>.my_UPPER_RAM_BOARDER_s:INPUT_BASE=16,EXPECTED_BASE=16
TEST.VALUE_USER_CODE:<<testcase>>
my_LOWER_RAM_BOARDER_s = my_cb_LOWER_RAM_BOARDER_s;
my_UPPER_RAM_BOARDER_s = my_cb_LOWER_RAM_BOARDER_s-1;
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:G5_Check_sr.<<GLOBAL>>.my_UPPER_RAM_BOARDER_s
{{ <<G5_Check_sr.<<GLOBAL>>.my_UPPER_RAM_BOARDER_s>> == ( my_cb_LOWER_RAM_BOARDER_s -1 ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Test Case: pointerOutOfAllBoarders
TEST.UNIT:G5_Check_sr
TEST.SUBPROGRAM:CheckRAM
TEST.NEW
TEST.NAME:pointerOutOfAllBoarders
TEST.COMPOUND_ONLY
TEST.NOTES:
Set both lower and upper RAM boarder to 0
-> RAM test address pointer is 0, no meaningful test
-> Just for coverage purposes only
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_Check_sr.<<GLOBAL>>.my_LOWER_RAM_BOARDER_s:0
TEST.VALUE:G5_Check_sr.<<GLOBAL>>.my_UPPER_RAM_BOARDER_s:0
TEST.VALUE:G5_Check_sr.<<GLOBAL>>.rw_RAM_DefectCell_g:<<MAX>>
TEST.VALUE:G5_Check_sr.<<GLOBAL>>.uF_Diagnose_pre_Flag.Bit.B0:0
TEST.VALUE:G5_Check_sr.<<GLOBAL>>.uF_Diagnose_pre_Flag.Bit.B1:0
TEST.VALUE:G5_Check_sr.<<GLOBAL>>.uF_Diagnose_pre_Flag.Bit.B2:1
TEST.VALUE:G5_Check_sr.<<GLOBAL>>.uF_Diagnose_pre_Flag.Bit.B3:0
TEST.VALUE:G5_Check_sr.<<GLOBAL>>.uF_Diagnose_pre_Flag.Bit.B4:0
TEST.VALUE:G5_Check_sr.<<GLOBAL>>.uF_Diagnose_pre_Flag.Bit.B5:0
TEST.VALUE:G5_Check_sr.<<GLOBAL>>.uF_Diagnose_pre_Flag.Bit.B6:0
TEST.VALUE:G5_Check_sr.<<GLOBAL>>.uF_Diagnose_pre_Flag.Bit.B7:0
TEST.EXPECTED:G5_Check_sr.<<GLOBAL>>.my_LOWER_RAM_BOARDER_s:0
TEST.EXPECTED:G5_Check_sr.<<GLOBAL>>.my_UPPER_RAM_BOARDER_s:0
TEST.EXPECTED:G5_Check_sr.<<GLOBAL>>.rw_RAM_DefectCell_g:<<MAX>>
TEST.EXPECTED:G5_Check_sr.<<GLOBAL>>.uF_Diagnose_pre_Flag.Bit.B0:0
TEST.EXPECTED:G5_Check_sr.<<GLOBAL>>.uF_Diagnose_pre_Flag.Bit.B1:0
TEST.EXPECTED:G5_Check_sr.<<GLOBAL>>.uF_Diagnose_pre_Flag.Bit.B2:1
TEST.EXPECTED:G5_Check_sr.<<GLOBAL>>.uF_Diagnose_pre_Flag.Bit.B3:0
TEST.EXPECTED:G5_Check_sr.<<GLOBAL>>.uF_Diagnose_pre_Flag.Bit.B4:0
TEST.EXPECTED:G5_Check_sr.<<GLOBAL>>.uF_Diagnose_pre_Flag.Bit.B5:0
TEST.EXPECTED:G5_Check_sr.<<GLOBAL>>.uF_Diagnose_pre_Flag.Bit.B6:0
TEST.EXPECTED:G5_Check_sr.<<GLOBAL>>.uF_Diagnose_pre_Flag.Bit.B7:0
TEST.END

-- Test Case: upperRamBoarderCheck
TEST.UNIT:G5_Check_sr
TEST.SUBPROGRAM:CheckRAM
TEST.NEW
TEST.NAME:upperRamBoarderCheck
TEST.COMPOUND_ONLY
TEST.NOTES:
Set upper RAM boarder at cb_UPPER_RAM_BOARDER_s   (see test case user code)
Set lower RAM boarder to cb_UPPER_RAM_BOARDER_s-1 (see test case user code)
Compound only test with 2 iterations:
Iteration 1
-> RAM test address pointer points to lower RAM boader, cb_UPPER_RAM_BOARDER_s-1
-> Lower RAM boarder condition is true
-> Upper RAM boarder condition is false
-> RAM test address pointer stays at start address (cb_UPPER_RAM_BOARDER_s-1)

Iteration 2
-> RAM test address pointer points to upper RAM boader, cb_UPPER_RAM_BOARDER_s
-> Lower RAM boarder condition is false
-> Upper RAM boarder condition is false
-> RAM test address pointer is incremented by 4

Iteration 3
-> RAM test address pointer is greater than the upper RAM boader, 0xFEF04U
-> Lower RAM boarder condition is false
-> Upper RAM boarder condition is true
-> Bit 5 of uF_Diagnose_pre_Flag to indicate end of RAM test
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_Check_sr.<<GLOBAL>>.my_LOWER_RAM_BOARDER_s:<<MAX>>
TEST.VALUE:G5_Check_sr.<<GLOBAL>>.my_UPPER_RAM_BOARDER_s:<<MAX>>
TEST.VALUE:G5_Check_sr.<<GLOBAL>>.rw_RAM_DefectCell_g:<<MIN>>
TEST.VALUE:G5_Check_sr.<<GLOBAL>>.uF_Diagnose_pre_Flag.Bit.B0:0
TEST.VALUE:G5_Check_sr.<<GLOBAL>>.uF_Diagnose_pre_Flag.Bit.B1:0
TEST.VALUE:G5_Check_sr.<<GLOBAL>>.uF_Diagnose_pre_Flag.Bit.B2:0
TEST.VALUE:G5_Check_sr.<<GLOBAL>>.uF_Diagnose_pre_Flag.Bit.B3:0
TEST.VALUE:G5_Check_sr.<<GLOBAL>>.uF_Diagnose_pre_Flag.Bit.B4:0
TEST.VALUE:G5_Check_sr.<<GLOBAL>>.uF_Diagnose_pre_Flag.Bit.B5:0
TEST.VALUE:G5_Check_sr.<<GLOBAL>>.uF_Diagnose_pre_Flag.Bit.B6:0
TEST.VALUE:G5_Check_sr.<<GLOBAL>>.uF_Diagnose_pre_Flag.Bit.B7:0
TEST.EXPECTED:G5_Check_sr.<<GLOBAL>>.my_UPPER_RAM_BOARDER_s:cb_UPPER_RAM_BOARDER_s
TEST.EXPECTED:G5_Check_sr.<<GLOBAL>>.rw_RAM_DefectCell_g:<<MIN>>
TEST.EXPECTED:G5_Check_sr.<<GLOBAL>>.uF_Diagnose_pre_Flag.Bit.B0:0
TEST.EXPECTED:G5_Check_sr.<<GLOBAL>>.uF_Diagnose_pre_Flag.Bit.B1:0
TEST.EXPECTED:G5_Check_sr.<<GLOBAL>>.uF_Diagnose_pre_Flag.Bit.B2:0
TEST.EXPECTED:G5_Check_sr.<<GLOBAL>>.uF_Diagnose_pre_Flag.Bit.B3:0
TEST.EXPECTED:G5_Check_sr.<<GLOBAL>>.uF_Diagnose_pre_Flag.Bit.B4:0
TEST.EXPECTED:G5_Check_sr.<<GLOBAL>>.uF_Diagnose_pre_Flag.Bit.B5:1
TEST.EXPECTED:G5_Check_sr.<<GLOBAL>>.uF_Diagnose_pre_Flag.Bit.B6:0
TEST.EXPECTED:G5_Check_sr.<<GLOBAL>>.uF_Diagnose_pre_Flag.Bit.B7:0
TEST.ATTRIBUTES:G5_Check_sr.<<GLOBAL>>.my_LOWER_RAM_BOARDER_s:INPUT_BASE=16,EXPECTED_BASE=16
TEST.ATTRIBUTES:G5_Check_sr.<<GLOBAL>>.my_UPPER_RAM_BOARDER_s:INPUT_BASE=16,EXPECTED_BASE=16
TEST.VALUE_USER_CODE:<<testcase>>
my_LOWER_RAM_BOARDER_s = my_cb_UPPER_RAM_BOARDER_s-1;
my_UPPER_RAM_BOARDER_s = my_cb_UPPER_RAM_BOARDER_s;
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:G5_Check_sr.<<GLOBAL>>.my_LOWER_RAM_BOARDER_s
{{ <<G5_Check_sr.<<GLOBAL>>.my_LOWER_RAM_BOARDER_s>> == ( cb_UPPER_RAM_BOARDER_s-1 ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Subprogram: DisableRamGuard

-- Test Case: DisableRamGuard
TEST.UNIT:G5_Check_sr
TEST.SUBPROGRAM:DisableRamGuard
TEST.NEW
TEST.NAME:DisableRamGuard
TEST.NOTES:
IAWCTL register bits 4 and 5 are RAM guard bits
To enable write access to RAM guard area set both bits to 0 and diable interrupts
-> Input 01111111 (0x7F)
-> Expected 10000000 (0x80)

Note: IAWCTL bit 7 (IAWEN) is always set to enable the illegal access detection function
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_Check_sr.<<GLOBAL>>.my_IAWCTL:0x7F
TEST.EXPECTED:G5_Check_sr.<<GLOBAL>>.my_IAWCTL:0x80
TEST.END

-- Subprogram: EnableRamGuard

-- Test Case: EnableRamGuard
TEST.UNIT:G5_Check_sr
TEST.SUBPROGRAM:EnableRamGuard
TEST.NEW
TEST.NAME:EnableRamGuard
TEST.NOTES:
IAWCTL register bits 4 and 5 are RAM guard bits
To enable write access to RAM guard area set both bits to 0 and diable interrupts
-> Input 01001111 (0x4F)
-> Expected 10110000 (0xB0)

Note: IAWCTL bit 7 (IAWEN) is always set to enable the illegal access detection function
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_Check_sr.<<GLOBAL>>.my_IAWCTL:0x4F
TEST.EXPECTED:G5_Check_sr.<<GLOBAL>>.my_IAWCTL:0xB0
TEST.END

-- Subprogram: RamGuardTest

-- Test Case: RamGuardTestEnabled
TEST.UNIT:G5_Check_sr
TEST.SUBPROGRAM:RamGuardTest
TEST.NEW
TEST.NAME:RamGuardTestEnabled
TEST.NOTES:
RAM guard only present on target. There enabling and disabling cannot be tested
This implies that only the RAM guard is alway enabled on PC.
Therefore, only the error case is covered by the test case.
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_Check_sr.<<GLOBAL>>.rb_RamGuardTestCell_mg:<<MIN-1>>
TEST.VALUE:G5_Check_sr.<<GLOBAL>>.uF_Diagnose_pre_Flag.Bit.B4:0
TEST.EXPECTED:G5_Check_sr.<<GLOBAL>>.rb_RamGuardTestCell_mg:0xAA
TEST.EXPECTED:G5_Check_sr.<<GLOBAL>>.uF_Diagnose_pre_Flag.Bit.B4:1
TEST.END

-- Subprogram: RamGuard_init

-- Test Case: ramGuardInit
TEST.UNIT:G5_Check_sr
TEST.SUBPROGRAM:RamGuard_init
TEST.NEW
TEST.NAME:ramGuardInit
TEST.NOTES:
IAWCTL register bits 4 and 5 are RAM guard bits
To enable write access to RAM guard area set both bits to 0 and diable interrupts
-> Input 00000000 (0x00)
-> Expected 10110000 (0x80)

Note: IAWCTL bit 7 (IAWEN) is always set to enable the illegal access detection function
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_Check_sr.<<GLOBAL>>.my_IAWCTL:<<MIN>>
TEST.EXPECTED:G5_Check_sr.<<GLOBAL>>.my_IAWCTL:0xB0
TEST.END

-- Subprogram: check_crc16

-- Test Case: romCheck.01
TEST.UNIT:G5_Check_sr
TEST.SUBPROGRAM:check_crc16
TEST.NEW
TEST.NAME:romCheck.01
TEST.COMPOUND_ONLY
TEST.NOTES:
Compound only with 4 iterations to complete one ROM check cycle.
Iteration 1:
-> ROM address pointer is at start address, 0x2000
Iteration 2:
-> 8 bytes are of ROM are checked
-> ROM address pointer is incremented 0x2008
Iteration 3:
-> Next ROM byte is checked
-> ROM address now address, 0x2009
Iteration 4:
-> Last ROM byte is checked
-> ROM address now address is reset to start address, 0x2000
-> Bit 5 of uF_Diagnose_pre_Flag is set to 1
-> ROM check error: calculated checksum, build check sum and mirror check sum are all 0
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_Check_sr.<<GLOBAL>>.my_chksum2000_FEEF:0
TEST.VALUE:G5_Check_sr.<<GLOBAL>>.my_chksum_mirror2000_FEEF:0
TEST.VALUE:G5_Check_sr.<<GLOBAL>>.MY_chksum2000_FEEF_START:8192
TEST.VALUE:G5_Check_sr.<<GLOBAL>>.MY_chksum2000_FEEF_END:8201
TEST.VALUE:G5_Check_sr.<<GLOBAL>>.rw_RAM_DefectCell_g:0
TEST.VALUE:G5_Check_sr.<<GLOBAL>>.uF_Diagnose_pre_Flag.Bit.B0:0
TEST.VALUE:G5_Check_sr.<<GLOBAL>>.uF_Diagnose_pre_Flag.Bit.B1:0
TEST.VALUE:G5_Check_sr.<<GLOBAL>>.uF_Diagnose_pre_Flag.Bit.B2:0
TEST.VALUE:G5_Check_sr.<<GLOBAL>>.uF_Diagnose_pre_Flag.Bit.B3:0
TEST.VALUE:G5_Check_sr.<<GLOBAL>>.uF_Diagnose_pre_Flag.Bit.B4:0
TEST.VALUE:G5_Check_sr.<<GLOBAL>>.uF_Diagnose_pre_Flag.Bit.B5:0
TEST.VALUE:G5_Check_sr.<<GLOBAL>>.uF_Diagnose_pre_Flag.Bit.B6:0
TEST.VALUE:G5_Check_sr.<<GLOBAL>>.uF_Diagnose_pre_Flag.Bit.B7:0
TEST.VALUE:G5_Check_sr.<<GLOBAL>>.rw_CRC16_g:0
TEST.EXPECTED:G5_Check_sr.<<GLOBAL>>.my_chksum2000_FEEF:0
TEST.EXPECTED:G5_Check_sr.<<GLOBAL>>.my_chksum_mirror2000_FEEF:0
TEST.EXPECTED:G5_Check_sr.<<GLOBAL>>.MY_chksum2000_FEEF_START:8192
TEST.EXPECTED:G5_Check_sr.<<GLOBAL>>.MY_chksum2000_FEEF_END:8201
TEST.EXPECTED:G5_Check_sr.<<GLOBAL>>.rw_RAM_DefectCell_g:0
TEST.EXPECTED:G5_Check_sr.<<GLOBAL>>.uF_Diagnose_pre_Flag.Bit.B0:0
TEST.EXPECTED:G5_Check_sr.<<GLOBAL>>.uF_Diagnose_pre_Flag.Bit.B1:1
TEST.EXPECTED:G5_Check_sr.<<GLOBAL>>.uF_Diagnose_pre_Flag.Bit.B2:0
TEST.EXPECTED:G5_Check_sr.<<GLOBAL>>.uF_Diagnose_pre_Flag.Bit.B3:0
TEST.EXPECTED:G5_Check_sr.<<GLOBAL>>.uF_Diagnose_pre_Flag.Bit.B4:0
TEST.EXPECTED:G5_Check_sr.<<GLOBAL>>.uF_Diagnose_pre_Flag.Bit.B5:0
TEST.EXPECTED:G5_Check_sr.<<GLOBAL>>.uF_Diagnose_pre_Flag.Bit.B6:1
TEST.EXPECTED:G5_Check_sr.<<GLOBAL>>.uF_Diagnose_pre_Flag.Bit.B7:0
TEST.EXPECTED:G5_Check_sr.<<GLOBAL>>.rw_CRC16_g:0
TEST.END

-- Test Case: romCheck.02
TEST.UNIT:G5_Check_sr
TEST.SUBPROGRAM:check_crc16
TEST.NEW
TEST.NAME:romCheck.02
TEST.COMPOUND_ONLY
TEST.NOTES:
Compound only with 2 iterations
Iteration 1:
-> ROM address pointer is initialised to start address, 0x2000
-> CRC is reset
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_Check_sr.<<GLOBAL>>.my_chksum2000_FEEF:0
TEST.VALUE:G5_Check_sr.<<GLOBAL>>.my_chksum_mirror2000_FEEF:0
TEST.VALUE:G5_Check_sr.<<GLOBAL>>.MY_chksum2000_FEEF_START:8192
TEST.VALUE:G5_Check_sr.<<GLOBAL>>.MY_chksum2000_FEEF_END:8191
TEST.VALUE:G5_Check_sr.<<GLOBAL>>.rw_RAM_DefectCell_g:0
TEST.VALUE:G5_Check_sr.<<GLOBAL>>.uF_Diagnose_pre_Flag.Bit.B0:0
TEST.VALUE:G5_Check_sr.<<GLOBAL>>.uF_Diagnose_pre_Flag.Bit.B1:0
TEST.VALUE:G5_Check_sr.<<GLOBAL>>.uF_Diagnose_pre_Flag.Bit.B2:0
TEST.VALUE:G5_Check_sr.<<GLOBAL>>.uF_Diagnose_pre_Flag.Bit.B3:0
TEST.VALUE:G5_Check_sr.<<GLOBAL>>.uF_Diagnose_pre_Flag.Bit.B4:0
TEST.VALUE:G5_Check_sr.<<GLOBAL>>.uF_Diagnose_pre_Flag.Bit.B5:0
TEST.VALUE:G5_Check_sr.<<GLOBAL>>.uF_Diagnose_pre_Flag.Bit.B6:0
TEST.VALUE:G5_Check_sr.<<GLOBAL>>.uF_Diagnose_pre_Flag.Bit.B7:0
TEST.VALUE:G5_Check_sr.<<GLOBAL>>.rw_CRC16_g:0
TEST.EXPECTED:G5_Check_sr.<<GLOBAL>>.my_chksum2000_FEEF:0
TEST.EXPECTED:G5_Check_sr.<<GLOBAL>>.my_chksum_mirror2000_FEEF:0
TEST.EXPECTED:G5_Check_sr.<<GLOBAL>>.MY_chksum2000_FEEF_START:8192
TEST.EXPECTED:G5_Check_sr.<<GLOBAL>>.MY_chksum2000_FEEF_END:8191
TEST.EXPECTED:G5_Check_sr.<<GLOBAL>>.rw_RAM_DefectCell_g:0
TEST.EXPECTED:G5_Check_sr.<<GLOBAL>>.uF_Diagnose_pre_Flag.Bit.B0:0
TEST.EXPECTED:G5_Check_sr.<<GLOBAL>>.uF_Diagnose_pre_Flag.Bit.B1:0
TEST.EXPECTED:G5_Check_sr.<<GLOBAL>>.uF_Diagnose_pre_Flag.Bit.B2:0
TEST.EXPECTED:G5_Check_sr.<<GLOBAL>>.uF_Diagnose_pre_Flag.Bit.B3:0
TEST.EXPECTED:G5_Check_sr.<<GLOBAL>>.uF_Diagnose_pre_Flag.Bit.B4:0
TEST.EXPECTED:G5_Check_sr.<<GLOBAL>>.uF_Diagnose_pre_Flag.Bit.B5:0
TEST.EXPECTED:G5_Check_sr.<<GLOBAL>>.uF_Diagnose_pre_Flag.Bit.B6:0
TEST.EXPECTED:G5_Check_sr.<<GLOBAL>>.uF_Diagnose_pre_Flag.Bit.B7:0
TEST.EXPECTED:G5_Check_sr.<<GLOBAL>>.rw_CRC16_g:0
TEST.END

-- Test Case: romCheck.03
TEST.UNIT:G5_Check_sr
TEST.SUBPROGRAM:check_crc16
TEST.NEW
TEST.NAME:romCheck.03
TEST.COMPOUND_ONLY
TEST.NOTES:
Compound only with 5 iterations to complete one ROM check cycle.
-> Stubbed crc_calc by function to emulate no CRC16 error
-> For coverage only
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.STUB:G5_Check_sr.crc_calc
TEST.VALUE:G5_Check_sr.<<GLOBAL>>.my_chksum2000_FEEF:0
TEST.VALUE:G5_Check_sr.<<GLOBAL>>.my_chksum_mirror2000_FEEF:0
TEST.VALUE:G5_Check_sr.<<GLOBAL>>.MY_chksum2000_FEEF_START:8192
TEST.VALUE:G5_Check_sr.<<GLOBAL>>.MY_chksum2000_FEEF_END:8201
TEST.VALUE:G5_Check_sr.<<GLOBAL>>.rw_RAM_DefectCell_g:0
TEST.VALUE:G5_Check_sr.<<GLOBAL>>.uF_Diagnose_pre_Flag.Bit.B0:0
TEST.VALUE:G5_Check_sr.<<GLOBAL>>.uF_Diagnose_pre_Flag.Bit.B1:0
TEST.VALUE:G5_Check_sr.<<GLOBAL>>.uF_Diagnose_pre_Flag.Bit.B2:0
TEST.VALUE:G5_Check_sr.<<GLOBAL>>.uF_Diagnose_pre_Flag.Bit.B3:0
TEST.VALUE:G5_Check_sr.<<GLOBAL>>.uF_Diagnose_pre_Flag.Bit.B4:0
TEST.VALUE:G5_Check_sr.<<GLOBAL>>.uF_Diagnose_pre_Flag.Bit.B5:0
TEST.VALUE:G5_Check_sr.<<GLOBAL>>.uF_Diagnose_pre_Flag.Bit.B6:0
TEST.VALUE:G5_Check_sr.<<GLOBAL>>.uF_Diagnose_pre_Flag.Bit.B7:0
TEST.VALUE:G5_Check_sr.<<GLOBAL>>.rw_CRC16_g:0
TEST.VALUE:G5_Check_sr.crc_calc.rb_InputByte_l:0xAA
TEST.VALUE:G5_Check_sr.crc_calc.rw_CRC_Init_Value_l:0
TEST.EXPECTED:G5_Check_sr.<<GLOBAL>>.my_chksum2000_FEEF:0
TEST.EXPECTED:G5_Check_sr.<<GLOBAL>>.my_chksum_mirror2000_FEEF:0
TEST.EXPECTED:G5_Check_sr.<<GLOBAL>>.MY_chksum2000_FEEF_START:8192
TEST.EXPECTED:G5_Check_sr.<<GLOBAL>>.MY_chksum2000_FEEF_END:8201
TEST.EXPECTED:G5_Check_sr.<<GLOBAL>>.rw_RAM_DefectCell_g:0
TEST.EXPECTED:G5_Check_sr.<<GLOBAL>>.uF_Diagnose_pre_Flag.Bit.B0:0
TEST.EXPECTED:G5_Check_sr.<<GLOBAL>>.uF_Diagnose_pre_Flag.Bit.B1:0
TEST.EXPECTED:G5_Check_sr.<<GLOBAL>>.uF_Diagnose_pre_Flag.Bit.B2:0
TEST.EXPECTED:G5_Check_sr.<<GLOBAL>>.uF_Diagnose_pre_Flag.Bit.B3:0
TEST.EXPECTED:G5_Check_sr.<<GLOBAL>>.uF_Diagnose_pre_Flag.Bit.B4:0
TEST.EXPECTED:G5_Check_sr.<<GLOBAL>>.uF_Diagnose_pre_Flag.Bit.B5:0
TEST.EXPECTED:G5_Check_sr.<<GLOBAL>>.uF_Diagnose_pre_Flag.Bit.B6:1
TEST.EXPECTED:G5_Check_sr.<<GLOBAL>>.uF_Diagnose_pre_Flag.Bit.B7:0
TEST.EXPECTED:G5_Check_sr.<<GLOBAL>>.rw_CRC16_g:0x0
TEST.END

-- Subprogram: check_crc16_calib

-- Test Case: calibCheckError
TEST.UNIT:G5_Check_sr
TEST.SUBPROGRAM:check_crc16_calib
TEST.NEW
TEST.NAME:calibCheckError
TEST.NOTES:
Calculated checksum, 60122, is checked against the wrong checksum, 60121
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_Check_sr.<<GLOBAL>>.uF_Diagnose_pre_Flag.Bit.B2:0
TEST.VALUE:G5_Check_sr.<<GLOBAL>>.rw_CRC16_g:<<MIN-1>>
TEST.VALUE:G5_Check_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ALS1_4_Setting_g:36
TEST.VALUE:G5_Check_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ALS5_6_INREC_Setting_g:0
TEST.VALUE:G5_Check_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ASIC_DIAGV_g:120
TEST.VALUE:G5_Check_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.A_Factor_ALS1_g:267
TEST.VALUE:G5_Check_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.A_Factor_ALS2_g:650
TEST.VALUE:G5_Check_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.A_Factor_ALS3_g:512
TEST.VALUE:G5_Check_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.A_Factor_ALS4_g:512
TEST.VALUE:G5_Check_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.A_Factor_ALS5_g:467
TEST.VALUE:G5_Check_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.A_Factor_ALS6_g:267
TEST.VALUE:G5_Check_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.A_Factor_INREC_g:390
TEST.VALUE:G5_Check_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.B_Factor_Iref_Lo_Gain_Lo_g:216
TEST.VALUE:G5_Check_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.B_Factor_Iref_Lo_Gain_Hi_g:64
TEST.VALUE:G5_Check_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.B_Factor_Iref_Hi_Gain_Lo_g:216
TEST.VALUE:G5_Check_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.B_Factor_Iref_Hi_Gain_Hi_g:64
TEST.VALUE:G5_Check_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.CRC_Checksum_calibration_g:60121
TEST.EXPECTED:G5_Check_sr.<<GLOBAL>>.uF_Diagnose_pre_Flag.Bit.B2:1
TEST.EXPECTED:G5_Check_sr.<<GLOBAL>>.rw_CRC16_g:0xFFFF
TEST.EXPECTED:G5_Check_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ALS1_4_Setting_g:36
TEST.EXPECTED:G5_Check_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ALS5_6_INREC_Setting_g:0
TEST.EXPECTED:G5_Check_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ASIC_DIAGV_g:120
TEST.EXPECTED:G5_Check_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.A_Factor_ALS1_g:267
TEST.EXPECTED:G5_Check_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.A_Factor_ALS2_g:650
TEST.EXPECTED:G5_Check_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.A_Factor_ALS3_g:512
TEST.EXPECTED:G5_Check_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.A_Factor_ALS4_g:512
TEST.EXPECTED:G5_Check_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.A_Factor_ALS5_g:467
TEST.EXPECTED:G5_Check_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.A_Factor_ALS6_g:267
TEST.EXPECTED:G5_Check_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.A_Factor_INREC_g:390
TEST.EXPECTED:G5_Check_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.B_Factor_Iref_Lo_Gain_Lo_g:216
TEST.EXPECTED:G5_Check_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.B_Factor_Iref_Lo_Gain_Hi_g:64
TEST.EXPECTED:G5_Check_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.B_Factor_Iref_Hi_Gain_Lo_g:216
TEST.EXPECTED:G5_Check_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.B_Factor_Iref_Hi_Gain_Hi_g:64
TEST.EXPECTED:G5_Check_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.CRC_Checksum_calibration_g:60121
TEST.END

-- Test Case: calibCheckNoError
TEST.UNIT:G5_Check_sr
TEST.SUBPROGRAM:check_crc16_calib
TEST.NEW
TEST.NAME:calibCheckNoError
TEST.NOTES:
Calculated checksum, 60122, is checked against the correct checksum, 60122
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_Check_sr.<<GLOBAL>>.uF_Diagnose_pre_Flag.Bit.B2:1
TEST.VALUE:G5_Check_sr.<<GLOBAL>>.rw_CRC16_g:<<MAX+1>>
TEST.VALUE:G5_Check_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ALS1_4_Setting_g:36
TEST.VALUE:G5_Check_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ALS5_6_INREC_Setting_g:0
TEST.VALUE:G5_Check_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ASIC_DIAGV_g:120
TEST.VALUE:G5_Check_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.A_Factor_ALS1_g:267
TEST.VALUE:G5_Check_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.A_Factor_ALS2_g:650
TEST.VALUE:G5_Check_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.A_Factor_ALS3_g:512
TEST.VALUE:G5_Check_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.A_Factor_ALS4_g:512
TEST.VALUE:G5_Check_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.A_Factor_ALS5_g:467
TEST.VALUE:G5_Check_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.A_Factor_ALS6_g:267
TEST.VALUE:G5_Check_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.A_Factor_INREC_g:390
TEST.VALUE:G5_Check_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.B_Factor_Iref_Lo_Gain_Lo_g:216
TEST.VALUE:G5_Check_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.B_Factor_Iref_Lo_Gain_Hi_g:64
TEST.VALUE:G5_Check_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.B_Factor_Iref_Hi_Gain_Lo_g:216
TEST.VALUE:G5_Check_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.B_Factor_Iref_Hi_Gain_Hi_g:64
TEST.VALUE:G5_Check_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.CRC_Checksum_calibration_g:60122
TEST.EXPECTED:G5_Check_sr.<<GLOBAL>>.uF_Diagnose_pre_Flag.Bit.B2:0
TEST.EXPECTED:G5_Check_sr.<<GLOBAL>>.rw_CRC16_g:0x0
TEST.EXPECTED:G5_Check_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ALS1_4_Setting_g:36
TEST.EXPECTED:G5_Check_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ALS5_6_INREC_Setting_g:0
TEST.EXPECTED:G5_Check_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ASIC_DIAGV_g:120
TEST.EXPECTED:G5_Check_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.A_Factor_ALS1_g:267
TEST.EXPECTED:G5_Check_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.A_Factor_ALS2_g:650
TEST.EXPECTED:G5_Check_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.A_Factor_ALS3_g:512
TEST.EXPECTED:G5_Check_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.A_Factor_ALS4_g:512
TEST.EXPECTED:G5_Check_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.A_Factor_ALS5_g:467
TEST.EXPECTED:G5_Check_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.A_Factor_ALS6_g:267
TEST.EXPECTED:G5_Check_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.A_Factor_INREC_g:390
TEST.EXPECTED:G5_Check_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.B_Factor_Iref_Lo_Gain_Lo_g:216
TEST.EXPECTED:G5_Check_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.B_Factor_Iref_Lo_Gain_Hi_g:64
TEST.EXPECTED:G5_Check_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.B_Factor_Iref_Hi_Gain_Lo_g:216
TEST.EXPECTED:G5_Check_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.B_Factor_Iref_Hi_Gain_Hi_g:64
TEST.EXPECTED:G5_Check_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.CRC_Checksum_calibration_g:60122
TEST.END

-- Subprogram: crc_calc

-- Test Case: calculateCRCWithNextBit
TEST.UNIT:G5_Check_sr
TEST.SUBPROGRAM:crc_calc
TEST.NEW
TEST.NAME:calculateCRCWithNextBit
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_Check_sr.<<GLOBAL>>.rw_CRC16_g:<<MIN-1>>
TEST.VALUE:G5_Check_sr.crc_calc.rb_InputByte_l:0x80
TEST.EXPECTED:G5_Check_sr.<<GLOBAL>>.rw_CRC16_g:0xFFFF
TEST.EXPECTED:G5_Check_sr.crc_calc.rb_InputByte_l:0x80
TEST.END

-- Test Case: calculateCRCWithPolynomial
TEST.UNIT:G5_Check_sr
TEST.SUBPROGRAM:crc_calc
TEST.NEW
TEST.NAME:calculateCRCWithPolynomial
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_Check_sr.<<GLOBAL>>.rw_CRC16_g:<<MAX+1>>
TEST.VALUE:G5_Check_sr.crc_calc.rb_InputByte_l:0x0
TEST.EXPECTED:G5_Check_sr.<<GLOBAL>>.rw_CRC16_g:0x0
TEST.EXPECTED:G5_Check_sr.crc_calc.rb_InputByte_l:0x0
TEST.ATTRIBUTES:G5_Check_sr.<<GLOBAL>>.rw_CRC16_g:INPUT_BASE=16
TEST.END

-- COMPOUND TESTS

TEST.SUBPROGRAM:<<COMPOUND>>
TEST.NEW
TEST.NAME:01_check_crc16
TEST.NOTES:
Stub CRC16 calculation to emulate no 
TEST.END_NOTES:
TEST.SLOT: "1", "G5_Check_sr", "check_crc16", "5", "romCheck.03"
TEST.END
--

-- COMPOUND TESTS

TEST.SUBPROGRAM:<<COMPOUND>>
TEST.NEW
TEST.NAME:02_check_crc16
TEST.SLOT: "1", "G5_Check_sr", "check_crc16", "4", "romCheck.01"
TEST.SLOT: "2", "G5_Check_sr", "check_crc16", "2", "romCheck.02"
TEST.END
--

-- COMPOUND TESTS

TEST.SUBPROGRAM:<<COMPOUND>>
TEST.NEW
TEST.NAME:checkRAM
TEST.SLOT: "1", "G5_Check_sr", "CheckRAM", "1", "pointerOutOfAllBoarders"
TEST.SLOT: "2", "G5_Check_sr", "CheckRAM", "2", "lowerRamBoarderCheck"
TEST.SLOT: "3", "G5_Check_sr", "CheckRAM", "3", "upperRamBoarderCheck"
TEST.END
--
