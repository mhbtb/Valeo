-- VectorCAST 6.2n
-- Test Case Script
-- 
-- Environment    : G5_SPI_SR
-- Unit(s) Under Test: G5_spi_sr
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Subprogram: SPI_WriteBlock

-- Test Case: spiActiveISRCall
TEST.UNIT:G5_spi_sr
TEST.SUBPROGRAM:SPI_WriteBlock
TEST.NEW
TEST.NAME:spiActiveISRCall
TEST.NOTES:
uF_SPI_flags_g.Bit.B0 = 1 is reset in SPI_int
Serial status: 0 -> communication stopped / suspended
Exit while loop by timeout.
Set bit 0 of SE0 to 1 to avoid endless loop in interrupt call.
 
TEST.END_NOTES:
TEST.REQUIREMENT_KEY:188
TEST.STUB:G5_spi_sr.set_rab_SPI_WriteBuffer_mg
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no5:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no6:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SIR00:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SS0:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SDR00:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SE0:0x1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.uF_SPI_flags_g.Bit.B0:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_Active_ProblemCounter_g:0xFE
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_bytes_to_send_mg:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_WBPosition_mg:<<MAX>>
TEST.VALUE:G5_spi_sr.SPI_WriteBlock.rb_FirstbyteToWrite_l:<<malloc 4>>
TEST.VALUE:G5_spi_sr.SPI_WriteBlock.rb_FirstbyteToWrite_l[0]:0
TEST.VALUE:G5_spi_sr.SPI_WriteBlock.rb_FirstbyteToWrite_l[1]:1
TEST.VALUE:G5_spi_sr.SPI_WriteBlock.rb_FirstbyteToWrite_l[2]:2
TEST.VALUE:G5_spi_sr.SPI_WriteBlock.rb_FirstbyteToWrite_l[3]:3
TEST.VALUE:G5_spi_sr.SPI_WriteBlock.rb_lenghtOfBlock:4
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.vc_P14_bit.no7:0
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.vc_MK0H_bit.no5:0
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.vc_IF0H_bit.no5:0
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no6:0
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.vc_SIR00:7
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.vc_SOE0:1
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.vc_SS0:0x1
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.vc_SDR00:0x1000
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.vc_SE0:0x1
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.uF_SPI_flags_g.Bit.B0:1
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rb_SPI_Active_ProblemCounter_g:0xFF
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rb_SPI_bytes_to_send_mg:4
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rb_SPI_WBPosition_mg:0
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rb_SPI_Data_to_send_g:0
TEST.EXPECTED:G5_spi_sr.set_rab_SPI_WriteBuffer_mg.rb_position_l:0,1,2,3
TEST.EXPECTED:G5_spi_sr.set_rab_SPI_WriteBuffer_mg.rb_Value_l:0,1,2,3
TEST.EXPECTED:G5_spi_sr.SPI_WriteBlock.rb_lenghtOfBlock:4
TEST.END

-- Test Case: spiActiveNoISRCall.001
TEST.UNIT:G5_spi_sr
TEST.SUBPROGRAM:SPI_WriteBlock
TEST.NEW
TEST.NAME:spiActiveNoISRCall.001
TEST.NOTES:
uF_SPI_flags_g.Bit.B0 = 1 is reset input clock supply stop
Exit while loop by timeout.
Set bit 6 of SSR00 to 1 (communication in progress) otherwise endless loop in interrupt call.
PER0_bit.no2 = 0 (stop input clock supply)
MK0H_bit.no5 = 0 (Interrupt masking disable)
TEST.END_NOTES:
TEST.REQUIREMENT_KEY:188
TEST.STUB:G5_spi_sr.set_rab_SPI_WriteBuffer_mg
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_MK0H_bit.no5:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no6:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_PER0_bit.no2:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SIR00:0x0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SS0:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SE0:0x1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.uF_SPI_flags_g.Bit.B0:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_Active_ProblemCounter_g:0xFE
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_bytes_to_send_mg:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_WBPosition_mg:<<MAX>>
TEST.VALUE:G5_spi_sr.SPI_WriteBlock.rb_FirstbyteToWrite_l:<<malloc 4>>
TEST.VALUE:G5_spi_sr.SPI_WriteBlock.rb_FirstbyteToWrite_l[0]:0x1
TEST.VALUE:G5_spi_sr.SPI_WriteBlock.rb_FirstbyteToWrite_l[1]:0x2
TEST.VALUE:G5_spi_sr.SPI_WriteBlock.rb_FirstbyteToWrite_l[2]:0x3
TEST.VALUE:G5_spi_sr.SPI_WriteBlock.rb_FirstbyteToWrite_l[3]:0x4
TEST.VALUE:G5_spi_sr.SPI_WriteBlock.rb_lenghtOfBlock:4
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.vc_P14_bit.no7:0
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.vc_MK0H_bit.no5:0
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.vc_IF0H_bit.no5:0
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no6:1
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.vc_PER0_bit.no2:0
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.vc_SIR00:0x7
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.vc_SOE0:1
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.vc_SS0:0x1
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.vc_SDR00:0x1000
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.vc_SE0:0x1
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.uF_SPI_flags_g.Bit.B0:1
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rb_SPI_Active_ProblemCounter_g:0xFF
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rb_SPI_bytes_to_send_mg:4
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rb_SPI_WBPosition_mg:0
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rb_SPI_Data_to_send_g:0
TEST.EXPECTED:G5_spi_sr.set_rab_SPI_WriteBuffer_mg.rb_position_l:0,1,2,3
TEST.EXPECTED:G5_spi_sr.set_rab_SPI_WriteBuffer_mg.rb_Value_l:0x1,0x2,0x3,0x4
TEST.EXPECTED:G5_spi_sr.SPI_WriteBlock.rb_lenghtOfBlock:4
TEST.END

-- Test Case: spiActiveNoISRCall.002
TEST.UNIT:G5_spi_sr
TEST.SUBPROGRAM:SPI_WriteBlock
TEST.NEW
TEST.NAME:spiActiveNoISRCall.002
TEST.NOTES:
uF_SPI_flags_g.Bit.B0 = 1, reset at interrupt enable
Exit while loop by timeout.
Set bit 6 of SSR00 to 1 (communication in progress) otherwise endless loop in interrupt call.
PER0_bit.no2 = 1 (input clock supply)
MK0H_bit.no5 = 1 (Interrupt masking enable)
TEST.END_NOTES:
TEST.REQUIREMENT_KEY:188
TEST.STUB:G5_spi_sr.set_rab_SPI_WriteBuffer_mg
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_MK0H_bit.no5:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no6:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_PER0_bit.no2:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SIR00:0x0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SS0:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SE0:0x1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.uF_SPI_flags_g.Bit.B0:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_Active_ProblemCounter_g:0xFF
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_bytes_to_send_mg:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_WBPosition_mg:<<MAX>>
TEST.VALUE:G5_spi_sr.SPI_WriteBlock.rb_FirstbyteToWrite_l:<<malloc 4>>
TEST.VALUE:G5_spi_sr.SPI_WriteBlock.rb_FirstbyteToWrite_l[0]:0
TEST.VALUE:G5_spi_sr.SPI_WriteBlock.rb_FirstbyteToWrite_l[1]:1
TEST.VALUE:G5_spi_sr.SPI_WriteBlock.rb_FirstbyteToWrite_l[2]:2
TEST.VALUE:G5_spi_sr.SPI_WriteBlock.rb_FirstbyteToWrite_l[3]:3
TEST.VALUE:G5_spi_sr.SPI_WriteBlock.rb_lenghtOfBlock:4
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.vc_P14_bit.no7:0
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.vc_MK0H_bit.no5:0
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.vc_IF0H_bit.no5:0
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no6:1
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.vc_PER0_bit.no2:1
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.vc_SIR00:0x7
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.vc_SS0:0x1
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.vc_SE0:0x1
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.uF_SPI_flags_g.Bit.B0:1
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rb_SPI_bytes_to_send_mg:4
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rb_SPI_WBPosition_mg:0
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rb_SPI_Data_to_send_g:0
TEST.EXPECTED:G5_spi_sr.set_rab_SPI_WriteBuffer_mg.rb_position_l:0,1,2,3
TEST.EXPECTED:G5_spi_sr.set_rab_SPI_WriteBuffer_mg.rb_Value_l:0,1,2,3
TEST.EXPECTED:G5_spi_sr.SPI_WriteBlock.rb_lenghtOfBlock:4
TEST.END

-- Subprogram: SPI_Write_Byte

-- Test Case: SPI_Write_Byte
TEST.UNIT:G5_spi_sr
TEST.SUBPROGRAM:SPI_Write_Byte
TEST.NEW
TEST.NAME:SPI_Write_Byte
TEST.NOTES:
SPI_Write_Byte calls SPI_WriteBlock.
If bits 0 and 2 of SSR00, are not 0 there could be an endless loop.
If bit 0 of SE0 is not set, there could be an endless loop.
User prefix code is used to manipulate the above mentioned values:
vc_SSR00_bit.0 = 0
vc_SSR00_bit.2 = 0
vc_SE0 = 0x1

SPI_WriteBlock itself is tested separately.
TEST.END_NOTES:
TEST.REQUIREMENT_KEY:186
TEST.STUB:G5_spi_sr.SPI_WriteBlock
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no0:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no2:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.uF_SPI_flags_g.Bit.B0:0
TEST.VALUE:G5_spi_sr.SPI_Write_Byte.rb_byteToWrite_l:2
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no0:0
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no2:0
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.uF_SPI_flags_g.Bit.B0:<<ANY>>
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rb_SPI_Data_to_send_g:0
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rab_SPI_ASICWriteBuffer_mg[0]:2
TEST.EXPECTED:G5_spi_sr.SPI_Write_Byte.rb_byteToWrite_l:2
TEST.EXPECTED:G5_spi_sr.SPI_WriteBlock.rb_FirstbyteToWrite_l[0]:2
TEST.EXPECTED:G5_spi_sr.SPI_WriteBlock.rb_lenghtOfBlock:1
TEST.END

-- Subprogram: SPI_int

-- Test Case: BASIS-PATH-001-PARTIAL
TEST.UNIT:G5_spi_sr
TEST.SUBPROGRAM:SPI_int
TEST.NEW
TEST.NAME:BASIS-PATH-001-PARTIAL
TEST.BASIS_PATH:1 of 67
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) while (vc_SSR00_bit.no6 == 1 && vc_SSR00_bit.no5 == 1) ==> FALSE
      (2) if (rb_SPI_WBPosition_mg < rb_SPI_bytes_to_send_mg) ==> FALSE
      (5) if (rab_SPI_RcvCmd_l == ((rab_SPI_WriteBuffer_mg)[0] & 0xfe)) ==> FALSE
      (42) if (rb_SPI_error_l != 1 && rb_ASIC_SPI_ErrorFlag_g != 1) ==> FALSE
      (57) if (rb_ASIC_SPI_ErrorFlag_g == 0) ==> FALSE
      (58) if (51 == rb_ASIC_ControlMode_g) ==> FALSE
      (60) while ((vc_SE0 & 0x1) == 0) ==> FALSE
      (61) if (rw_SPINoCommCounter_g < (0xff00)) ==> FALSE
      (62) if (rw_SPINoCommCounter_g >= (0xff00)) ==> FALSE
      (63) if (rb_StaticNoCommunicationCounter_g < 255) ==> FALSE
      (64) if (1 == rb_firstReadComm_g) ==> FALSE
      (66) if (vc_SSR00_bit.no6 == 0) ==> FALSE
   Test Case Generation Notes:
      Cannot set variable to unknown value in branch 5
      Cannot set rb_SPI_error_l due to assignment
      Conflict: Trying to set variable G5_spi_sr.<<GLOBAL>>.rw_SPINoCommCounter_g 'less than' and 'greater than' same value in branches 61/62
TEST.END_NOTES:
TEST.REQUIREMENT_KEY:191
TEST.STUB:G5_spi_sr.set_rb_ASIC_SPI_ErrorFlag_g
TEST.STUB:G5_spi_sr.set_rab_SPI_WriteBuffer_mg
TEST.STUB:G5_spi_sr.set_rab_SPI_ReadBuffer_mg
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:FALSE
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no5:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no6:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SS0:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SDR00:0x10
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SE0:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_SPINoCommCounter_g:<<MAX>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_StaticNoCommunicationCounter_g:<<MAX>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]:0x10
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[0]:0x4F
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_bytes_to_send_mg:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_WBPosition_mg:3
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_firstReadComm_g:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_ASIC_SPI_ErrorFlag_g:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:<<MIN>>
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.vc_P14_bit.no7:0
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.vc_MK0H_bit.no5:0
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.vc_IF0H_bit.no5:0
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.vc_SIR00:7
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.vc_SOE0:1
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.vc_SS0:0x1
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.vc_SE0:1
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]:0x10
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[0]:0x4F
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rb_SPI_bytes_to_send_mg:4
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rb_SPI_WBPosition_mg:0
TEST.EXPECTED:G5_spi_sr.set_rb_ASIC_SPI_ErrorFlag_g.a:0
TEST.EXPECTED:G5_spi_sr.set_rab_SPI_WriteBuffer_mg.rb_position_l:0,1,2,3
TEST.EXPECTED:G5_spi_sr.set_rab_SPI_ReadBuffer_mg.rb_position_l:3
TEST.EXPECTED:G5_spi_sr.set_rab_SPI_ReadBuffer_mg.rb_Value_l:0x10
TEST.END

-- Test Case: BASIS-PATH-002-PARTIAL
TEST.UNIT:G5_spi_sr
TEST.SUBPROGRAM:SPI_int
TEST.NEW
TEST.NAME:BASIS-PATH-002-PARTIAL
TEST.BASIS_PATH:2 of 67
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) while (vc_SSR00_bit.no6 == 1 && vc_SSR00_bit.no5 == 1) ==> FALSE
      (2) if (rb_SPI_WBPosition_mg < rb_SPI_bytes_to_send_mg) ==> FALSE
      (5) if (rab_SPI_RcvCmd_l == ((rab_SPI_WriteBuffer_mg)[0] & 0xfe)) ==> FALSE
      (42) if (rb_SPI_error_l != 1 && rb_ASIC_SPI_ErrorFlag_g != 1) ==> FALSE
      (57) if (rb_ASIC_SPI_ErrorFlag_g == 0) ==> FALSE
      (58) if (51 == rb_ASIC_ControlMode_g) ==> FALSE
      (60) while ((vc_SE0 & 0x1) == 0) ==> FALSE
      (61) if (rw_SPINoCommCounter_g < (0xff00)) ==> FALSE
      (62) if (rw_SPINoCommCounter_g >= (0xff00)) ==> FALSE
      (63) if (rb_StaticNoCommunicationCounter_g < 255) ==> FALSE
      (64) if (1 == rb_firstReadComm_g) ==> FALSE
      (66) if (vc_SSR00_bit.no6 == 0) ==> TRUE
   Test Case Generation Notes:
      Cannot set variable to unknown value in branch 5
      Cannot set rb_SPI_error_l due to assignment
      Conflict: Trying to set variable G5_spi_sr.<<GLOBAL>>.rw_SPINoCommCounter_g 'less than' and 'greater than' same value in branches 61/62
TEST.END_NOTES:
TEST.REQUIREMENT_KEY:191
TEST.STUB:G5_spi_sr.set_rb_ASIC_SPI_ErrorFlag_g
TEST.STUB:G5_spi_sr.set_rab_SPI_WriteBuffer_mg
TEST.STUB:G5_spi_sr.set_rab_SPI_ReadBuffer_mg
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no5:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no6:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SOE0:0x1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SS0:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SDR00:0x10
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SE0:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_SPINoCommCounter_g:<<MAX>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_StaticNoCommunicationCounter_g:<<MAX>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]:0x10
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[0]:0x4F
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_bytes_to_send_mg:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_WBPosition_mg:3
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_firstReadComm_g:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_ASIC_SPI_ErrorFlag_g:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:<<MIN>>
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.vc_P14_bit.no7:0
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.vc_MK0H_bit.no5:1
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.vc_IF0H_bit.no5:0
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.vc_SIR00:7
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.vc_SOE0:0x0
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.vc_SS0:0x1
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.vc_SDR00:0x1010
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.uF_SPI_flags_g.Bit.B0:0
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]:0x10
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[0]:0x4F
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rb_SPI_bytes_to_send_mg:4
TEST.EXPECTED:G5_spi_sr.set_rb_ASIC_SPI_ErrorFlag_g.a:0
TEST.EXPECTED:G5_spi_sr.set_rab_SPI_WriteBuffer_mg.rb_position_l:0,1,2,3
TEST.EXPECTED:G5_spi_sr.set_rab_SPI_ReadBuffer_mg.rb_position_l:3
TEST.EXPECTED:G5_spi_sr.set_rab_SPI_ReadBuffer_mg.rb_Value_l:0x10
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL
TEST.UNIT:G5_spi_sr
TEST.SUBPROGRAM:SPI_int
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL
TEST.BASIS_PATH:3 of 67
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) while (vc_SSR00_bit.no6 == 1 && vc_SSR00_bit.no5 == 1) ==> FALSE
      (2) if (rb_SPI_WBPosition_mg < rb_SPI_bytes_to_send_mg) ==> FALSE
      (5) if (rab_SPI_RcvCmd_l == ((rab_SPI_WriteBuffer_mg)[0] & 0xfe)) ==> FALSE
      (42) if (rb_SPI_error_l != 1 && rb_ASIC_SPI_ErrorFlag_g != 1) ==> FALSE
      (57) if (rb_ASIC_SPI_ErrorFlag_g == 0) ==> FALSE
      (58) if (51 == rb_ASIC_ControlMode_g) ==> FALSE
      (60) while ((vc_SE0 & 0x1) == 0) ==> FALSE
      (61) if (rw_SPINoCommCounter_g < (0xff00)) ==> FALSE
      (62) if (rw_SPINoCommCounter_g >= (0xff00)) ==> FALSE
      (63) if (rb_StaticNoCommunicationCounter_g < 255) ==> FALSE
      (64) if (1 == rb_firstReadComm_g) ==> TRUE
      (66) if (vc_SSR00_bit.no6 == 0) ==> FALSE
   Test Case Generation Notes:
      Cannot set variable to unknown value in branch 5
      Cannot set rb_SPI_error_l due to assignment
      Conflict: Trying to set variable G5_spi_sr.<<GLOBAL>>.rw_SPINoCommCounter_g 'less than' and 'greater than' same value in branches 61/62
TEST.END_NOTES:
TEST.REQUIREMENT_KEY:191
TEST.STUB:G5_spi_sr.set_rb_ASIC_SPI_ErrorFlag_g
TEST.STUB:G5_spi_sr.set_rab_SPI_WriteBuffer_mg
TEST.STUB:G5_spi_sr.set_rab_SPI_ReadBuffer_mg
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no5:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no6:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SS0:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SDR00:0x10
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SE0:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_SPINoCommCounter_g:<<MAX>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_StaticNoCommunicationCounter_g:<<MAX>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]:0x10
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[0]:0x4F
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_bytes_to_send_mg:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_WBPosition_mg:3
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_firstReadComm_g:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_ASIC_SPI_ErrorFlag_g:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:<<MIN>>
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.vc_P14_bit.no7:0
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.vc_MK0H_bit.no5:0
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.vc_IF0H_bit.no5:0
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.vc_SIR00:7
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.vc_SOE0:1
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.vc_SS0:0x1
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rw_SPINoCommCounter_g:0xFFBF
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]:0x10
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[0]:0x4F
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rb_SPI_bytes_to_send_mg:4
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rb_firstReadComm_g:0
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.uF_Check_lightsensor_g.Bit.B3:1
TEST.EXPECTED:G5_spi_sr.set_rb_ASIC_SPI_ErrorFlag_g.a:0
TEST.EXPECTED:G5_spi_sr.set_rab_SPI_WriteBuffer_mg.rb_position_l:0,1,2,3
TEST.EXPECTED:G5_spi_sr.set_rab_SPI_ReadBuffer_mg.rb_position_l:3
TEST.EXPECTED:G5_spi_sr.set_rab_SPI_ReadBuffer_mg.rb_Value_l:0x10
TEST.ATTRIBUTES:G5_spi_sr.<<GLOBAL>>.vc_SDR00:EXPECTED_BASE=16
TEST.END

-- Test Case: BASIS-PATH-004-PARTIAL
TEST.UNIT:G5_spi_sr
TEST.SUBPROGRAM:SPI_int
TEST.NEW
TEST.NAME:BASIS-PATH-004-PARTIAL
TEST.BASIS_PATH:4 of 67
TEST.NOTES:
This is an automatically generated test case.
   Test Path 4
      (1) while (vc_SSR00_bit.no6 == 1 && vc_SSR00_bit.no5 == 1) ==> FALSE
      (2) if (rb_SPI_WBPosition_mg < rb_SPI_bytes_to_send_mg) ==> FALSE
      (5) if (rab_SPI_RcvCmd_l == ((rab_SPI_WriteBuffer_mg)[0] & 0xfe)) ==> FALSE
      (42) if (rb_SPI_error_l != 1 && rb_ASIC_SPI_ErrorFlag_g != 1) ==> FALSE
      (57) if (rb_ASIC_SPI_ErrorFlag_g == 0) ==> FALSE
      (58) if (51 == rb_ASIC_ControlMode_g) ==> FALSE
      (60) while ((vc_SE0 & 0x1) == 0) ==> FALSE
      (61) if (rw_SPINoCommCounter_g < (0xff00)) ==> FALSE
      (62) if (rw_SPINoCommCounter_g >= (0xff00)) ==> FALSE
      (63) if (rb_StaticNoCommunicationCounter_g < 255) ==> FALSE
      (64) if (1 == rb_firstReadComm_g) ==> TRUE
      (65) if (rb_StaticNoCommunicationCounter_g < 255) ==> TRUE
      (66) if (vc_SSR00_bit.no6 == 0) ==> FALSE
   Test Case Generation Notes:
      Cannot set variable to unknown value in branch 5
      Cannot set rb_SPI_error_l due to assignment
      Conflict: Trying to set variable G5_spi_sr.<<GLOBAL>>.rw_SPINoCommCounter_g 'less than' and 'greater than' same value in branches 61/62
      Conflict: Trying to set variable G5_spi_sr.<<GLOBAL>>.rb_StaticNoCommunicationCounter_g 'less than' and 'greater than' same value in branches 63/65
TEST.END_NOTES:
TEST.REQUIREMENT_KEY:191
TEST.STUB:G5_spi_sr.set_rb_ASIC_SPI_ErrorFlag_g
TEST.STUB:G5_spi_sr.set_rab_SPI_WriteBuffer_mg
TEST.STUB:G5_spi_sr.set_rab_SPI_ReadBuffer_mg
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no5:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no6:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SS0:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SDR00:0x10
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SE0:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_SPINoCommCounter_g:<<MAX>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_StaticNoCommunicationCounter_g:0x2
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]:0x10
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[0]:0x4F
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_bytes_to_send_mg:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_WBPosition_mg:3
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_firstReadComm_g:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_ASIC_SPI_ErrorFlag_g:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:<<MIN>>
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.vc_P14_bit.no7:0
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.vc_MK0H_bit.no5:0
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.vc_IF0H_bit.no5:0
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.vc_SIR00:7
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.vc_SOE0:1
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.vc_SS0:0x1
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.vc_SDR00:0x1010
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rb_StaticNoCommunicationCounter_g:0x2
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]:0x10
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[0]:0x4F
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rb_SPI_bytes_to_send_mg:4
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.uF_Check_lightsensor_g.Bit.B3:1
TEST.EXPECTED:G5_spi_sr.set_rb_ASIC_SPI_ErrorFlag_g.a:0
TEST.EXPECTED:G5_spi_sr.set_rab_SPI_WriteBuffer_mg.rb_position_l:0,1,2,3
TEST.EXPECTED:G5_spi_sr.set_rab_SPI_ReadBuffer_mg.rb_position_l:3
TEST.EXPECTED:G5_spi_sr.set_rab_SPI_ReadBuffer_mg.rb_Value_l:0x10
TEST.END

-- Test Case: BASIS-PATH-005-PARTIAL
TEST.UNIT:G5_spi_sr
TEST.SUBPROGRAM:SPI_int
TEST.NEW
TEST.NAME:BASIS-PATH-005-PARTIAL
TEST.BASIS_PATH:5 of 67
TEST.NOTES:
This is an automatically generated test case.
   Test Path 5
      (1) while (vc_SSR00_bit.no6 == 1 && vc_SSR00_bit.no5 == 1) ==> FALSE
      (2) if (rb_SPI_WBPosition_mg < rb_SPI_bytes_to_send_mg) ==> FALSE
      (5) if (rab_SPI_RcvCmd_l == ((rab_SPI_WriteBuffer_mg)[0] & 0xfe)) ==> FALSE
      (42) if (rb_SPI_error_l != 1 && rb_ASIC_SPI_ErrorFlag_g != 1) ==> FALSE
      (57) if (rb_ASIC_SPI_ErrorFlag_g == 0) ==> FALSE
      (58) if (51 == rb_ASIC_ControlMode_g) ==> FALSE
      (60) while ((vc_SE0 & 0x1) == 0) ==> FALSE
      (61) if (rw_SPINoCommCounter_g < (0xff00)) ==> FALSE
      (62) if (rw_SPINoCommCounter_g >= (0xff00)) ==> FALSE
      (63) if (rb_StaticNoCommunicationCounter_g < 255) ==> TRUE
      (64) if (1 == rb_firstReadComm_g) ==> FALSE
      (66) if (vc_SSR00_bit.no6 == 0) ==> FALSE
   Test Case Generation Notes:
      Cannot set variable to unknown value in branch 5
      Cannot set rb_SPI_error_l due to assignment
      Conflict: Trying to set variable G5_spi_sr.<<GLOBAL>>.rw_SPINoCommCounter_g 'less than' and 'greater than' same value in branches 61/62
TEST.END_NOTES:
TEST.REQUIREMENT_KEY:191
TEST.STUB:G5_spi_sr.set_rb_ASIC_SPI_ErrorFlag_g
TEST.STUB:G5_spi_sr.set_rab_SPI_WriteBuffer_mg
TEST.STUB:G5_spi_sr.set_rab_SPI_ReadBuffer_mg
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no5:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no6:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SS0:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SDR00:0x10
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SE0:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_SPINoCommCounter_g:<<MAX>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_StaticNoCommunicationCounter_g:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]:0x10
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[0]:0x4F
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_bytes_to_send_mg:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_WBPosition_mg:3
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_firstReadComm_g:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_ASIC_SPI_ErrorFlag_g:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:<<MIN>>
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.vc_P14_bit.no7:0
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.vc_MK0H_bit.no5:0
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.vc_IF0H_bit.no5:0
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.vc_SIR00:7
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.vc_SOE0:1
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.vc_SS0:0x1
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.vc_SDR00:0x1010
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rb_StaticNoCommunicationCounter_g:1
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]:0x10
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[0]:0x4F
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rb_SPI_bytes_to_send_mg:4
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rb_SPI_WBPosition_mg:0
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.uF_Check_lightsensor_g.Bit.B3:1
TEST.EXPECTED:G5_spi_sr.set_rb_ASIC_SPI_ErrorFlag_g.a:0
TEST.EXPECTED:G5_spi_sr.set_rab_SPI_WriteBuffer_mg.rb_position_l:0,1,2,3
TEST.EXPECTED:G5_spi_sr.set_rab_SPI_ReadBuffer_mg.rb_position_l:3
TEST.EXPECTED:G5_spi_sr.set_rab_SPI_ReadBuffer_mg.rb_Value_l:0x10
TEST.END

-- Test Case: BASIS-PATH-006-PARTIAL
TEST.UNIT:G5_spi_sr
TEST.SUBPROGRAM:SPI_int
TEST.NEW
TEST.NAME:BASIS-PATH-006-PARTIAL
TEST.BASIS_PATH:6 of 67
TEST.NOTES:
This is an automatically generated test case.
   Test Path 6
      (1) while (vc_SSR00_bit.no6 == 1 && vc_SSR00_bit.no5 == 1) ==> FALSE
      (2) if (rb_SPI_WBPosition_mg < rb_SPI_bytes_to_send_mg) ==> FALSE
      (5) if (rab_SPI_RcvCmd_l == ((rab_SPI_WriteBuffer_mg)[0] & 0xfe)) ==> FALSE
      (42) if (rb_SPI_error_l != 1 && rb_ASIC_SPI_ErrorFlag_g != 1) ==> FALSE
      (57) if (rb_ASIC_SPI_ErrorFlag_g == 0) ==> FALSE
      (58) if (51 == rb_ASIC_ControlMode_g) ==> FALSE
      (60) while ((vc_SE0 & 0x1) == 0) ==> FALSE
      (61) if (rw_SPINoCommCounter_g < (0xff00)) ==> FALSE
      (62) if (rw_SPINoCommCounter_g >= (0xff00)) ==> TRUE
      (63) if (rb_StaticNoCommunicationCounter_g < 255) ==> FALSE
      (64) if (1 == rb_firstReadComm_g) ==> FALSE
      (66) if (vc_SSR00_bit.no6 == 0) ==> FALSE
   Test Case Generation Notes:
      Cannot set variable to unknown value in branch 5
      Cannot set rb_SPI_error_l due to assignment
TEST.END_NOTES:
TEST.REQUIREMENT_KEY:191
TEST.STUB:G5_spi_sr.set_rb_ASIC_SPI_ErrorFlag_g
TEST.STUB:G5_spi_sr.set_rab_SPI_WriteBuffer_mg
TEST.STUB:G5_spi_sr.set_rab_SPI_ReadBuffer_mg
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no5:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no6:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SS0:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SDR00:0x10
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SE0:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_SPINoCommCounter_g:<<MAX>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_StaticNoCommunicationCounter_g:<<MAX>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]:0x10
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[0]:0x4F
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_bytes_to_send_mg:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_WBPosition_mg:3
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_firstReadComm_g:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_ASIC_SPI_ErrorFlag_g:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:<<MIN>>
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.vc_P14_bit.no7:0
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.vc_MK0H_bit.no5:0
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.vc_IF0H_bit.no5:0
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.vc_SIR00:7
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.vc_SOE0:1
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.vc_SS0:0x1
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.vc_SDR00:0x1010
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]:0x10
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[0]:0x4F
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rb_SPI_bytes_to_send_mg:4
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rb_SPI_WBPosition_mg:0
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.uF_Check_lightsensor_g.Bit.B3:1
TEST.EXPECTED:G5_spi_sr.set_rb_ASIC_SPI_ErrorFlag_g.a:0
TEST.EXPECTED:G5_spi_sr.set_rab_SPI_WriteBuffer_mg.rb_position_l:0,1,2,3
TEST.EXPECTED:G5_spi_sr.set_rab_SPI_ReadBuffer_mg.rb_position_l:3
TEST.EXPECTED:G5_spi_sr.set_rab_SPI_ReadBuffer_mg.rb_Value_l:0x10
TEST.END

-- Test Case: BASIS-PATH-007-PARTIAL
TEST.UNIT:G5_spi_sr
TEST.SUBPROGRAM:SPI_int
TEST.NEW
TEST.NAME:BASIS-PATH-007-PARTIAL
TEST.BASIS_PATH:7 of 67
TEST.NOTES:
This is an automatically generated test case.
   Test Path 7
      (1) while (vc_SSR00_bit.no6 == 1 && vc_SSR00_bit.no5 == 1) ==> FALSE
      (2) if (rb_SPI_WBPosition_mg < rb_SPI_bytes_to_send_mg) ==> FALSE
      (5) if (rab_SPI_RcvCmd_l == ((rab_SPI_WriteBuffer_mg)[0] & 0xfe)) ==> FALSE
      (42) if (rb_SPI_error_l != 1 && rb_ASIC_SPI_ErrorFlag_g != 1) ==> FALSE
      (57) if (rb_ASIC_SPI_ErrorFlag_g == 0) ==> FALSE
      (58) if (51 == rb_ASIC_ControlMode_g) ==> FALSE
      (60) while ((vc_SE0 & 0x1) == 0) ==> FALSE
      (61) if (rw_SPINoCommCounter_g < (0xff00)) ==> TRUE
      (62) if (rw_SPINoCommCounter_g >= (0xff00)) ==> FALSE
      (63) if (rb_StaticNoCommunicationCounter_g < 255) ==> FALSE
      (64) if (1 == rb_firstReadComm_g) ==> FALSE
      (66) if (vc_SSR00_bit.no6 == 0) ==> FALSE
   Test Case Generation Notes:
      Cannot set variable to unknown value in branch 5
      Cannot set rb_SPI_error_l due to assignment
      Cannot set rw_SPINoCommCounter_g due to assignment
TEST.END_NOTES:
TEST.REQUIREMENT_KEY:191
TEST.STUB:G5_spi_sr.set_rb_ASIC_SPI_ErrorFlag_g
TEST.STUB:G5_spi_sr.set_rab_SPI_WriteBuffer_mg
TEST.STUB:G5_spi_sr.set_rab_SPI_ReadBuffer_mg
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no5:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no6:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SS0:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SDR00:0x10
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SE0:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_SPINoCommCounter_g:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_StaticNoCommunicationCounter_g:<<MAX>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]:0x10
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[0]:0x4F
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_bytes_to_send_mg:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_WBPosition_mg:3
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_firstReadComm_g:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_ASIC_SPI_ErrorFlag_g:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:<<MIN>>
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.vc_P14_bit.no7:0
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.vc_MK0H_bit.no5:0
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.vc_IF0H_bit.no5:0
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.vc_SIR00:7
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.vc_SOE0:1
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.vc_SS0:0x1
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.vc_SDR00:0x1010
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rw_SPINoCommCounter_g:0x40
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]:0x10
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[0]:0x4F
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rb_SPI_bytes_to_send_mg:4
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rb_SPI_WBPosition_mg:0
TEST.EXPECTED:G5_spi_sr.set_rb_ASIC_SPI_ErrorFlag_g.a:0
TEST.EXPECTED:G5_spi_sr.set_rab_SPI_WriteBuffer_mg.rb_position_l:0,1,2,3
TEST.EXPECTED:G5_spi_sr.set_rab_SPI_ReadBuffer_mg.rb_position_l:3
TEST.EXPECTED:G5_spi_sr.set_rab_SPI_ReadBuffer_mg.rb_Value_l:0x10
TEST.END

-- Test Case: BASIS-PATH-008-PARTIAL
TEST.UNIT:G5_spi_sr
TEST.SUBPROGRAM:SPI_int
TEST.NEW
TEST.NAME:BASIS-PATH-008-PARTIAL
TEST.BASIS_PATH:8 of 67
TEST.NOTES:
This is an automatically generated test case.
   Test Path 8
      (1) while (vc_SSR00_bit.no6 == 1 && vc_SSR00_bit.no5 == 1) ==> FALSE
      (2) if (rb_SPI_WBPosition_mg < rb_SPI_bytes_to_send_mg) ==> FALSE
      (5) if (rab_SPI_RcvCmd_l == ((rab_SPI_WriteBuffer_mg)[0] & 0xfe)) ==> FALSE
      (42) if (rb_SPI_error_l != 1 && rb_ASIC_SPI_ErrorFlag_g != 1) ==> FALSE
      (57) if (rb_ASIC_SPI_ErrorFlag_g == 0) ==> FALSE
      (58) if (51 == rb_ASIC_ControlMode_g) ==> FALSE
      (60) while ((vc_SE0 & 0x1) == 0) ==> TRUE
      (61) if (rw_SPINoCommCounter_g < (0xff00)) ==> FALSE
      (62) if (rw_SPINoCommCounter_g >= (0xff00)) ==> FALSE
      (63) if (rb_StaticNoCommunicationCounter_g < 255) ==> FALSE
      (64) if (1 == rb_firstReadComm_g) ==> FALSE
      (66) if (vc_SSR00_bit.no6 == 0) ==> FALSE
   Test Case Generation Notes:
      Cannot set variable to unknown value in branch 5
      Cannot set rb_SPI_error_l due to assignment
      Conflict: Trying to set variable G5_spi_sr.<<GLOBAL>>.rw_SPINoCommCounter_g 'less than' and 'greater than' same value in branches 61/62
TEST.END_NOTES:
TEST.REQUIREMENT_KEY:191
TEST.STUB:G5_spi_sr.set_rb_ASIC_SPI_ErrorFlag_g
TEST.STUB:G5_spi_sr.set_rab_SPI_WriteBuffer_mg
TEST.STUB:G5_spi_sr.set_rab_SPI_ReadBuffer_mg
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no5:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no6:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SS0:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SDR00:0x10
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SE0:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_SPINoCommCounter_g:<<MAX>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_StaticNoCommunicationCounter_g:<<MAX>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]:0x10
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[0]:0x4F
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_bytes_to_send_mg:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_WBPosition_mg:3
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_firstReadComm_g:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_ASIC_SPI_ErrorFlag_g:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:<<MIN>>
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.vc_P14_bit.no7:0
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.vc_MK0H_bit.no5:0
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.vc_IF0H_bit.no5:0
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.vc_SIR00:7
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.vc_SOE0:1
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.vc_SS0:0x1
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.vc_SDR00:0x1010
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]:0x10
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[0]:0x4F
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rb_SPI_bytes_to_send_mg:4
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rb_SPI_WBPosition_mg:0
TEST.EXPECTED:G5_spi_sr.set_rb_ASIC_SPI_ErrorFlag_g.a:0
TEST.EXPECTED:G5_spi_sr.set_rab_SPI_WriteBuffer_mg.rb_position_l:0,1,2,3
TEST.EXPECTED:G5_spi_sr.set_rab_SPI_ReadBuffer_mg.rb_position_l:3
TEST.EXPECTED:G5_spi_sr.set_rab_SPI_ReadBuffer_mg.rb_Value_l:0x10
TEST.END

-- Test Case: BASIS-PATH-010-PARTIAL
TEST.UNIT:G5_spi_sr
TEST.SUBPROGRAM:SPI_int
TEST.NEW
TEST.NAME:BASIS-PATH-010-PARTIAL
TEST.BASIS_PATH:10 of 67
TEST.NOTES:
This is an automatically generated test case.
   Test Path 10
      (1) while (vc_SSR00_bit.no6 == 1 && vc_SSR00_bit.no5 == 1) ==> FALSE
      (2) if (rb_SPI_WBPosition_mg < rb_SPI_bytes_to_send_mg) ==> FALSE
      (5) if (rab_SPI_RcvCmd_l == ((rab_SPI_WriteBuffer_mg)[0] & 0xfe)) ==> FALSE
      (42) if (rb_SPI_error_l != 1 && rb_ASIC_SPI_ErrorFlag_g != 1) ==> FALSE
      (57) if (rb_ASIC_SPI_ErrorFlag_g == 0) ==> FALSE
      (58) if (51 == rb_ASIC_ControlMode_g) ==> TRUE
      (60) while ((vc_SE0 & 0x1) == 0) ==> FALSE
      (61) if (rw_SPINoCommCounter_g < (0xff00)) ==> FALSE
      (62) if (rw_SPINoCommCounter_g >= (0xff00)) ==> FALSE
      (63) if (rb_StaticNoCommunicationCounter_g < 255) ==> FALSE
      (64) if (1 == rb_firstReadComm_g) ==> FALSE
      (66) if (vc_SSR00_bit.no6 == 0) ==> FALSE
   Test Case Generation Notes:
      Cannot set variable to unknown value in branch 5
      Cannot set rb_SPI_error_l due to assignment
      Conflict: Trying to set variable G5_spi_sr.<<GLOBAL>>.rw_SPINoCommCounter_g 'less than' and 'greater than' same value in branches 61/62
TEST.END_NOTES:
TEST.REQUIREMENT_KEY:191
TEST.STUB:G5_spi_sr.set_rb_ASIC_SPI_ErrorFlag_g
TEST.STUB:G5_spi_sr.set_rab_SPI_WriteBuffer_mg
TEST.STUB:G5_spi_sr.set_rab_SPI_ReadBuffer_mg
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no5:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no6:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SS0:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SDR00:0x10
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SE0:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_SPINoCommCounter_g:<<MAX>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_StaticNoCommunicationCounter_g:<<MAX>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]:0x10
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[0]:0x4F
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_bytes_to_send_mg:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_WBPosition_mg:3
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_firstReadComm_g:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_ASIC_SPI_ErrorFlag_g:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:51
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.vc_P14_bit.no7:0
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.vc_MK0H_bit.no5:0
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.vc_IF0H_bit.no5:0
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.vc_SIR00:7
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.vc_SOE0:1
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.vc_SS0:0x1
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.vc_SDR00:0x1010
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]:0x10
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[0]:0x4F
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rb_SPI_bytes_to_send_mg:4
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rb_SPI_WBPosition_mg:0
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rb_NextSPI_Request_g:0x3
TEST.EXPECTED:G5_spi_sr.set_rb_ASIC_SPI_ErrorFlag_g.a:0
TEST.EXPECTED:G5_spi_sr.set_rab_SPI_WriteBuffer_mg.rb_position_l:0,1,2,3
TEST.EXPECTED:G5_spi_sr.set_rab_SPI_ReadBuffer_mg.rb_position_l:3
TEST.EXPECTED:G5_spi_sr.set_rab_SPI_ReadBuffer_mg.rb_Value_l:0x10
TEST.END

-- Test Case: BASIS-PATH-011-PARTIAL
TEST.UNIT:G5_spi_sr
TEST.SUBPROGRAM:SPI_int
TEST.NEW
TEST.NAME:BASIS-PATH-011-PARTIAL
TEST.BASIS_PATH:11 of 67
TEST.NOTES:
This is an automatically generated test case.
   Test Path 11
      (1) while (vc_SSR00_bit.no6 == 1 && vc_SSR00_bit.no5 == 1) ==> FALSE
      (2) if (rb_SPI_WBPosition_mg < rb_SPI_bytes_to_send_mg) ==> FALSE
      (5) if (rab_SPI_RcvCmd_l == ((rab_SPI_WriteBuffer_mg)[0] & 0xfe)) ==> FALSE
      (42) if (rb_SPI_error_l != 1 && rb_ASIC_SPI_ErrorFlag_g != 1) ==> FALSE
      (57) if (rb_ASIC_SPI_ErrorFlag_g == 0) ==> TRUE
      (61) if (rw_SPINoCommCounter_g < (0xff00)) ==> FALSE
      (62) if (rw_SPINoCommCounter_g >= (0xff00)) ==> FALSE
      (63) if (rb_StaticNoCommunicationCounter_g < 255) ==> FALSE
      (64) if (1 == rb_firstReadComm_g) ==> FALSE
      (66) if (vc_SSR00_bit.no6 == 0) ==> FALSE
   Test Case Generation Notes:
      Cannot set variable to unknown value in branch 5
      Cannot set rb_SPI_error_l due to assignment
      Conflict: Trying to set variable G5_spi_sr.<<GLOBAL>>.rw_SPINoCommCounter_g 'less than' and 'greater than' same value in branches 61/62
TEST.END_NOTES:
TEST.REQUIREMENT_KEY:191
TEST.STUB:G5_spi_sr.set_rab_SPI_ReadBuffer_mg
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no5:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no6:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SS0:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SDR00:0x10
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SE0:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_SPINoCommCounter_g:<<MAX>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_StaticNoCommunicationCounter_g:<<MAX>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]:0x10
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[0]:0x4F
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_bytes_to_send_mg:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_WBPosition_mg:3
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_communication_retries_mg:2
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_firstReadComm_g:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_ASIC_SPI_ErrorFlag_g:0
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.vc_P14_bit.no7:0
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.vc_MK0H_bit.no5:0
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.vc_IF0H_bit.no5:0
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.vc_SIR00:7
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.vc_SOE0:1
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.vc_SS0:0x1
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.vc_SDR00:0x1010
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]:0x10
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[0]:0x4F
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rb_SPI_WBPosition_mg:0
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rb_communication_retries_mg:3
TEST.EXPECTED:G5_spi_sr.set_rab_SPI_ReadBuffer_mg.rb_position_l:3
TEST.EXPECTED:G5_spi_sr.set_rab_SPI_ReadBuffer_mg.rb_Value_l:0x10
TEST.END

-- Test Case: BASIS-PATH-013-PARTIAL
TEST.UNIT:G5_spi_sr
TEST.SUBPROGRAM:SPI_int
TEST.NEW
TEST.NAME:BASIS-PATH-013-PARTIAL
TEST.BASIS_PATH:13 of 67
TEST.NOTES:
This is an automatically generated test case.
   Test Path 13
      (1) while (vc_SSR00_bit.no6 == 1 && vc_SSR00_bit.no5 == 1) ==> FALSE
      (2) if (rb_SPI_WBPosition_mg < rb_SPI_bytes_to_send_mg) ==> FALSE
      (5) if (rab_SPI_RcvCmd_l == ((rab_SPI_WriteBuffer_mg)[0] & 0xfe)) ==> TRUE
      (42) if (rb_SPI_error_l != 1 && rb_ASIC_SPI_ErrorFlag_g != 1) ==> TRUE
      (43) if (rw_SPINoCommCounter_g > (0)) ==> FALSE
      (44) if ((rab_SPI_RcvCmd_l & 0xc0) != 0x80) ==> FALSE
      (52) if (rb_NextSPI_Request_g == (byte)0x3) ==> TRUE
      (53) if (((EEPROM_Struct_PD.EEPROMStructPD).ASIC_Sched_Config_g & 0x20) == 0) ==> FALSE
      (56) while ((vc_SE0 & 0x1) == 0) ==> FALSE
      (66) if (vc_SSR00_bit.no6 == 0) ==> FALSE
   Test Case Generation Notes:
      Cannot set variable to unknown value in branch 5
      Cannot set rb_SPI_error_l due to assignment
      Cannot set rab_SPI_RcvCmd_l due to assignment
TEST.END_NOTES:
TEST.REQUIREMENT_KEY:191
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no5:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no6:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SE0:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_SPINoCommCounter_g:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]:0x41
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[0]:0xDF
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_bytes_to_send_mg:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_WBPosition_mg:3
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_ASIC_SPI_ErrorFlag_g:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_NextSPI_Request_g:3
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g:32
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rb_SPI_WBPosition_mg:0
TEST.END

-- Test Case: BASIS-PATH-015-PARTIAL
TEST.UNIT:G5_spi_sr
TEST.SUBPROGRAM:SPI_int
TEST.NEW
TEST.NAME:BASIS-PATH-015-PARTIAL
TEST.COMPOUND_ONLY
TEST.BASIS_PATH:15 of 67
TEST.NOTES:
This is an automatically generated test case.
   Test Path 15
      (1) while (vc_SSR00_bit.no6 == 1 && vc_SSR00_bit.no5 == 1) ==> FALSE
      (2) if (rb_SPI_WBPosition_mg < rb_SPI_bytes_to_send_mg) ==> FALSE
      (5) if (rab_SPI_RcvCmd_l == ((rab_SPI_WriteBuffer_mg)[0] & 0xfe)) ==> FALSE
      (42) if (rb_SPI_error_l != 1 && rb_ASIC_SPI_ErrorFlag_g != 1) ==> TRUE
      (43) if (rw_SPINoCommCounter_g > (0)) ==> FALSE
      (44) if ((rab_SPI_RcvCmd_l & 0xc0) != 0x80) ==> FALSE
      (52) if (rb_NextSPI_Request_g == (byte)0x3) ==> TRUE
      (53) if (((EEPROM_Struct_PD.EEPROMStructPD).ASIC_Sched_Config_g & 0x20) == 0) ==> FALSE
      (55) while (vc_SSR00_bit.no6 == 1 && vc_SSR00_bit.no5 == 1) ==> TRUE
      (56) while ((vc_SE0 & 0x1) == 0) ==> FALSE
      (66) if (vc_SSR00_bit.no6 == 0) ==> FALSE
   Test Case Generation Notes:
      Cannot set variable to unknown value in branch 5
      Cannot set rb_SPI_error_l due to assignment
      Cannot set rab_SPI_RcvCmd_l due to assignment
      Conflict: Trying to set variable G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no6 'equal to' and 'not equal to' same value in branches 1/55
      Conflict: Trying to set variable G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no5 'equal to' and 'not equal to' same value in branches 1/55
TEST.END_NOTES:
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no5:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no6:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SE0:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_SPINoCommCounter_g:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_bytes_to_send_mg:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_ASIC_SPI_ErrorFlag_g:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_NextSPI_Request_g:3
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g:32
TEST.END

-- Test Case: BASIS-PATH-016-PARTIAL
TEST.UNIT:G5_spi_sr
TEST.SUBPROGRAM:SPI_int
TEST.NEW
TEST.NAME:BASIS-PATH-016-PARTIAL
TEST.COMPOUND_ONLY
TEST.BASIS_PATH:16 of 67
TEST.NOTES:
This is an automatically generated test case.
   Test Path 16
      (1) while (vc_SSR00_bit.no6 == 1 && vc_SSR00_bit.no5 == 1) ==> FALSE
      (2) if (rb_SPI_WBPosition_mg < rb_SPI_bytes_to_send_mg) ==> FALSE
      (5) if (rab_SPI_RcvCmd_l == ((rab_SPI_WriteBuffer_mg)[0] & 0xfe)) ==> FALSE
      (42) if (rb_SPI_error_l != 1 && rb_ASIC_SPI_ErrorFlag_g != 1) ==> TRUE
      (43) if (rw_SPINoCommCounter_g > (0)) ==> FALSE
      (44) if ((rab_SPI_RcvCmd_l & 0xc0) != 0x80) ==> FALSE
      (52) if (rb_NextSPI_Request_g == (byte)0x3) ==> TRUE
      (53) if (((EEPROM_Struct_PD.EEPROMStructPD).ASIC_Sched_Config_g & 0x20) == 0) ==> TRUE
      (54) if (5 == rb_CurMode_g) ==> FALSE
      (56) while ((vc_SE0 & 0x1) == 0) ==> FALSE
      (66) if (vc_SSR00_bit.no6 == 0) ==> FALSE
   Test Case Generation Notes:
      Cannot set variable to unknown value in branch 5
      Cannot set rb_SPI_error_l due to assignment
      Cannot set rab_SPI_RcvCmd_l due to assignment
TEST.END_NOTES:
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no5:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no6:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SE0:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_SPINoCommCounter_g:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_bytes_to_send_mg:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_ASIC_SPI_ErrorFlag_g:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_CurMode_g:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_NextSPI_Request_g:3
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g:0
TEST.END

-- Test Case: BASIS-PATH-017-PARTIAL
TEST.UNIT:G5_spi_sr
TEST.SUBPROGRAM:SPI_int
TEST.NEW
TEST.NAME:BASIS-PATH-017-PARTIAL
TEST.COMPOUND_ONLY
TEST.BASIS_PATH:17 of 67
TEST.NOTES:
This is an automatically generated test case.
   Test Path 17
      (1) while (vc_SSR00_bit.no6 == 1 && vc_SSR00_bit.no5 == 1) ==> FALSE
      (2) if (rb_SPI_WBPosition_mg < rb_SPI_bytes_to_send_mg) ==> FALSE
      (5) if (rab_SPI_RcvCmd_l == ((rab_SPI_WriteBuffer_mg)[0] & 0xfe)) ==> FALSE
      (42) if (rb_SPI_error_l != 1 && rb_ASIC_SPI_ErrorFlag_g != 1) ==> TRUE
      (43) if (rw_SPINoCommCounter_g > (0)) ==> FALSE
      (44) if ((rab_SPI_RcvCmd_l & 0xc0) != 0x80) ==> FALSE
      (52) if (rb_NextSPI_Request_g == (byte)0x3) ==> TRUE
      (53) if (((EEPROM_Struct_PD.EEPROMStructPD).ASIC_Sched_Config_g & 0x20) == 0) ==> TRUE
      (54) if (5 == rb_CurMode_g) ==> TRUE
      (56) while ((vc_SE0 & 0x1) == 0) ==> FALSE
      (66) if (vc_SSR00_bit.no6 == 0) ==> FALSE
   Test Case Generation Notes:
      Cannot set variable to unknown value in branch 5
      Cannot set rb_SPI_error_l due to assignment
      Cannot set rab_SPI_RcvCmd_l due to assignment
TEST.END_NOTES:
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no5:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no6:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SE0:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_SPINoCommCounter_g:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_bytes_to_send_mg:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_ASIC_SPI_ErrorFlag_g:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_CurMode_g:5
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_NextSPI_Request_g:3
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.EEPROM_Struct_PD.EEPROMStructPD.ASIC_Sched_Config_g:0
TEST.END

-- Test Case: BASIS-PATH-018-PARTIAL
TEST.UNIT:G5_spi_sr
TEST.SUBPROGRAM:SPI_int
TEST.NEW
TEST.NAME:BASIS-PATH-018-PARTIAL
TEST.COMPOUND_ONLY
TEST.BASIS_PATH:18 of 67
TEST.NOTES:
This is an automatically generated test case.
   Test Path 18
      (1) while (vc_SSR00_bit.no6 == 1 && vc_SSR00_bit.no5 == 1) ==> FALSE
      (2) if (rb_SPI_WBPosition_mg < rb_SPI_bytes_to_send_mg) ==> FALSE
      (5) if (rab_SPI_RcvCmd_l == ((rab_SPI_WriteBuffer_mg)[0] & 0xfe)) ==> FALSE
      (42) if (rb_SPI_error_l != 1 && rb_ASIC_SPI_ErrorFlag_g != 1) ==> TRUE
      (43) if (rw_SPINoCommCounter_g > (0)) ==> FALSE
      (44) if ((rab_SPI_RcvCmd_l & 0xc0) != 0x80) ==> FALSE
      (51) if (rw_SPINoCommCounter_g > (0)) ==> TRUE
      (52) if (rb_NextSPI_Request_g == (byte)0x3) ==> FALSE
      (66) if (vc_SSR00_bit.no6 == 0) ==> FALSE
   Test Case Generation Notes:
      Cannot set variable to unknown value in branch 5
      Cannot set rb_SPI_error_l due to assignment
      Cannot set rab_SPI_RcvCmd_l due to assignment
      Conflict: Trying to set variable G5_spi_sr.<<GLOBAL>>.rw_SPINoCommCounter_g 'less than' and 'greater than' same value in branches 43/51
TEST.END_NOTES:
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no5:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no6:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_SPINoCommCounter_g:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_bytes_to_send_mg:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_ASIC_SPI_ErrorFlag_g:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_NextSPI_Request_g:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-019-PARTIAL
TEST.UNIT:G5_spi_sr
TEST.SUBPROGRAM:SPI_int
TEST.NEW
TEST.NAME:BASIS-PATH-019-PARTIAL
TEST.COMPOUND_ONLY
TEST.BASIS_PATH:19 of 67
TEST.NOTES:
This is an automatically generated test case.
   Test Path 19
      (1) while (vc_SSR00_bit.no6 == 1 && vc_SSR00_bit.no5 == 1) ==> FALSE
      (2) if (rb_SPI_WBPosition_mg < rb_SPI_bytes_to_send_mg) ==> FALSE
      (5) if (rab_SPI_RcvCmd_l == ((rab_SPI_WriteBuffer_mg)[0] & 0xfe)) ==> FALSE
      (42) if (rb_SPI_error_l != 1 && rb_ASIC_SPI_ErrorFlag_g != 1) ==> TRUE
      (43) if (rw_SPINoCommCounter_g > (0)) ==> FALSE
      (44) if ((rab_SPI_RcvCmd_l & 0xc0) != 0x80) ==> TRUE
      (45) if ((rab_SPI_RcvCmd_l & 0xd0) == 0xc0) ==> FALSE
      (49) if (0x64 == rab_SPI_RcvCmd_l) ==> FALSE
      (52) if (rb_NextSPI_Request_g == (byte)0x3) ==> FALSE
      (66) if (vc_SSR00_bit.no6 == 0) ==> FALSE
   Test Case Generation Notes:
      Cannot set variable to unknown value in branch 5
      Cannot set rb_SPI_error_l due to assignment
      Cannot set rab_SPI_RcvCmd_l due to assignment
      Cannot set rab_SPI_RcvCmd_l due to assignment
      Cannot set rab_SPI_RcvCmd_l due to assignment
TEST.END_NOTES:
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no5:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no6:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_SPINoCommCounter_g:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_bytes_to_send_mg:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_ASIC_SPI_ErrorFlag_g:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_NextSPI_Request_g:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-020-PARTIAL
TEST.UNIT:G5_spi_sr
TEST.SUBPROGRAM:SPI_int
TEST.NEW
TEST.NAME:BASIS-PATH-020-PARTIAL
TEST.COMPOUND_ONLY
TEST.BASIS_PATH:20 of 67
TEST.NOTES:
This is an automatically generated test case.
   Test Path 20
      (1) while (vc_SSR00_bit.no6 == 1 && vc_SSR00_bit.no5 == 1) ==> FALSE
      (2) if (rb_SPI_WBPosition_mg < rb_SPI_bytes_to_send_mg) ==> FALSE
      (5) if (rab_SPI_RcvCmd_l == ((rab_SPI_WriteBuffer_mg)[0] & 0xfe)) ==> FALSE
      (42) if (rb_SPI_error_l != 1 && rb_ASIC_SPI_ErrorFlag_g != 1) ==> TRUE
      (43) if (rw_SPINoCommCounter_g > (0)) ==> FALSE
      (44) if ((rab_SPI_RcvCmd_l & 0xc0) != 0x80) ==> TRUE
      (45) if ((rab_SPI_RcvCmd_l & 0xd0) == 0xc0) ==> FALSE
      (49) if (0x64 == rab_SPI_RcvCmd_l) ==> TRUE
      (50) if (((rab_SPI_WriteBuffer_mg)[rb_SPI_bytes_to_send_mg - 1] & 0x7) == 2) ==> FALSE
      (52) if (rb_NextSPI_Request_g == (byte)0x3) ==> FALSE
      (66) if (vc_SSR00_bit.no6 == 0) ==> FALSE
   Test Case Generation Notes:
      Cannot set variable to unknown value in branch 5
      Cannot set rb_SPI_error_l due to assignment
      Cannot set rab_SPI_RcvCmd_l due to assignment
      Cannot set rab_SPI_RcvCmd_l due to assignment
      Cannot set rab_SPI_RcvCmd_l due to assignment
      Conflict: Cannot resolve multiple comparisons ( G5_spi_sr.<<GLOBAL>>.rb_SPI_bytes_to_send_mg ) in branches 2/50
TEST.END_NOTES:
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no5:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no6:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_SPINoCommCounter_g:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_bytes_to_send_mg:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_ASIC_SPI_ErrorFlag_g:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_NextSPI_Request_g:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-021-PARTIAL
TEST.UNIT:G5_spi_sr
TEST.SUBPROGRAM:SPI_int
TEST.NEW
TEST.NAME:BASIS-PATH-021-PARTIAL
TEST.COMPOUND_ONLY
TEST.BASIS_PATH:21 of 67
TEST.NOTES:
This is an automatically generated test case.
   Test Path 21
      (1) while (vc_SSR00_bit.no6 == 1 && vc_SSR00_bit.no5 == 1) ==> FALSE
      (2) if (rb_SPI_WBPosition_mg < rb_SPI_bytes_to_send_mg) ==> FALSE
      (5) if (rab_SPI_RcvCmd_l == ((rab_SPI_WriteBuffer_mg)[0] & 0xfe)) ==> FALSE
      (42) if (rb_SPI_error_l != 1 && rb_ASIC_SPI_ErrorFlag_g != 1) ==> TRUE
      (43) if (rw_SPINoCommCounter_g > (0)) ==> FALSE
      (44) if ((rab_SPI_RcvCmd_l & 0xc0) != 0x80) ==> TRUE
      (45) if ((rab_SPI_RcvCmd_l & 0xd0) == 0xc0) ==> FALSE
      (49) if (0x64 == rab_SPI_RcvCmd_l) ==> TRUE
      (50) if (((rab_SPI_WriteBuffer_mg)[rb_SPI_bytes_to_send_mg - 1] & 0x7) == 2) ==> TRUE
      (52) if (rb_NextSPI_Request_g == (byte)0x3) ==> FALSE
      (66) if (vc_SSR00_bit.no6 == 0) ==> FALSE
   Test Case Generation Notes:
      Cannot set variable to unknown value in branch 5
      Cannot set rb_SPI_error_l due to assignment
      Cannot set rab_SPI_RcvCmd_l due to assignment
      Cannot set rab_SPI_RcvCmd_l due to assignment
      Cannot set rab_SPI_RcvCmd_l due to assignment
      Conflict: Cannot resolve multiple comparisons ( G5_spi_sr.<<GLOBAL>>.rb_SPI_bytes_to_send_mg ) in branches 2/50
TEST.END_NOTES:
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no5:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no6:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_SPINoCommCounter_g:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_bytes_to_send_mg:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_ASIC_SPI_ErrorFlag_g:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_NextSPI_Request_g:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-022-PARTIAL
TEST.UNIT:G5_spi_sr
TEST.SUBPROGRAM:SPI_int
TEST.NEW
TEST.NAME:BASIS-PATH-022-PARTIAL
TEST.COMPOUND_ONLY
TEST.BASIS_PATH:22 of 67
TEST.NOTES:
This is an automatically generated test case.
   Test Path 22
      (1) while (vc_SSR00_bit.no6 == 1 && vc_SSR00_bit.no5 == 1) ==> FALSE
      (2) if (rb_SPI_WBPosition_mg < rb_SPI_bytes_to_send_mg) ==> FALSE
      (5) if (rab_SPI_RcvCmd_l == ((rab_SPI_WriteBuffer_mg)[0] & 0xfe)) ==> FALSE
      (42) if (rb_SPI_error_l != 1 && rb_ASIC_SPI_ErrorFlag_g != 1) ==> TRUE
      (43) if (rw_SPINoCommCounter_g > (0)) ==> FALSE
      (44) if ((rab_SPI_RcvCmd_l & 0xc0) != 0x80) ==> TRUE
      (45) if ((rab_SPI_RcvCmd_l & 0xd0) == 0xc0) ==> TRUE
      (46) if ((rab_SPI_WriteBuffer_mg)[0] == 0xc6) ==> FALSE
      (48) if (rb_CurMode_g != ((rab_SPI_WriteBuffer_mg)[0] >> 1 & 0x7)) ==> FALSE
      (52) if (rb_NextSPI_Request_g == (byte)0x3) ==> FALSE
      (66) if (vc_SSR00_bit.no6 == 0) ==> FALSE
   Test Case Generation Notes:
      Cannot set variable to unknown value in branch 5
      Cannot set rb_SPI_error_l due to assignment
      Cannot set rab_SPI_RcvCmd_l due to assignment
      Cannot set rab_SPI_RcvCmd_l due to assignment
      Cannot set variable to unknown value in branch 48
TEST.END_NOTES:
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no5:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no6:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_SPINoCommCounter_g:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_bytes_to_send_mg:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_ASIC_SPI_ErrorFlag_g:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_NextSPI_Request_g:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-023-PARTIAL
TEST.UNIT:G5_spi_sr
TEST.SUBPROGRAM:SPI_int
TEST.NEW
TEST.NAME:BASIS-PATH-023-PARTIAL
TEST.COMPOUND_ONLY
TEST.BASIS_PATH:23 of 67
TEST.NOTES:
This is an automatically generated test case.
   Test Path 23
      (1) while (vc_SSR00_bit.no6 == 1 && vc_SSR00_bit.no5 == 1) ==> FALSE
      (2) if (rb_SPI_WBPosition_mg < rb_SPI_bytes_to_send_mg) ==> FALSE
      (5) if (rab_SPI_RcvCmd_l == ((rab_SPI_WriteBuffer_mg)[0] & 0xfe)) ==> FALSE
      (42) if (rb_SPI_error_l != 1 && rb_ASIC_SPI_ErrorFlag_g != 1) ==> TRUE
      (43) if (rw_SPINoCommCounter_g > (0)) ==> FALSE
      (44) if ((rab_SPI_RcvCmd_l & 0xc0) != 0x80) ==> TRUE
      (45) if ((rab_SPI_RcvCmd_l & 0xd0) == 0xc0) ==> TRUE
      (46) if ((rab_SPI_WriteBuffer_mg)[0] == 0xc6) ==> FALSE
      (48) if (rb_CurMode_g != ((rab_SPI_WriteBuffer_mg)[0] >> 1 & 0x7)) ==> TRUE
      (52) if (rb_NextSPI_Request_g == (byte)0x3) ==> FALSE
      (66) if (vc_SSR00_bit.no6 == 0) ==> FALSE
   Test Case Generation Notes:
      Cannot set variable to unknown value in branch 5
      Cannot set rb_SPI_error_l due to assignment
      Cannot set rab_SPI_RcvCmd_l due to assignment
      Cannot set rab_SPI_RcvCmd_l due to assignment
      Cannot set variable to unknown value in branch 48
TEST.END_NOTES:
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no5:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no6:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_SPINoCommCounter_g:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_bytes_to_send_mg:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_ASIC_SPI_ErrorFlag_g:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_NextSPI_Request_g:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-024-PARTIAL
TEST.UNIT:G5_spi_sr
TEST.SUBPROGRAM:SPI_int
TEST.NEW
TEST.NAME:BASIS-PATH-024-PARTIAL
TEST.COMPOUND_ONLY
TEST.BASIS_PATH:24 of 67
TEST.NOTES:
This is an automatically generated test case.
   Test Path 24
      (1) while (vc_SSR00_bit.no6 == 1 && vc_SSR00_bit.no5 == 1) ==> FALSE
      (2) if (rb_SPI_WBPosition_mg < rb_SPI_bytes_to_send_mg) ==> FALSE
      (5) if (rab_SPI_RcvCmd_l == ((rab_SPI_WriteBuffer_mg)[0] & 0xfe)) ==> FALSE
      (42) if (rb_SPI_error_l != 1 && rb_ASIC_SPI_ErrorFlag_g != 1) ==> TRUE
      (43) if (rw_SPINoCommCounter_g > (0)) ==> FALSE
      (44) if ((rab_SPI_RcvCmd_l & 0xc0) != 0x80) ==> TRUE
      (45) if ((rab_SPI_RcvCmd_l & 0xd0) == 0xc0) ==> TRUE
      (46) if ((rab_SPI_WriteBuffer_mg)[0] == 0xc6) ==> TRUE
      (47) if ((rb_PrevMode_g != 4 && rb_CurMode_g != 1) && rb_CurMode_g != 2) ==> FALSE
      (52) if (rb_NextSPI_Request_g == (byte)0x3) ==> FALSE
      (66) if (vc_SSR00_bit.no6 == 0) ==> FALSE
   Test Case Generation Notes:
      Cannot set variable to unknown value in branch 5
      Cannot set rb_SPI_error_l due to assignment
      Cannot set rab_SPI_RcvCmd_l due to assignment
      Cannot set rab_SPI_RcvCmd_l due to assignment
TEST.END_NOTES:
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no5:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no6:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_SPINoCommCounter_g:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]:198
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_bytes_to_send_mg:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_ASIC_SPI_ErrorFlag_g:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_CurMode_g:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_PrevMode_g:4
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_NextSPI_Request_g:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-025-PARTIAL
TEST.UNIT:G5_spi_sr
TEST.SUBPROGRAM:SPI_int
TEST.NEW
TEST.NAME:BASIS-PATH-025-PARTIAL
TEST.COMPOUND_ONLY
TEST.BASIS_PATH:25 of 67
TEST.NOTES:
This is an automatically generated test case.
   Test Path 25
      (1) while (vc_SSR00_bit.no6 == 1 && vc_SSR00_bit.no5 == 1) ==> FALSE
      (2) if (rb_SPI_WBPosition_mg < rb_SPI_bytes_to_send_mg) ==> FALSE
      (5) if (rab_SPI_RcvCmd_l == ((rab_SPI_WriteBuffer_mg)[0] & 0xfe)) ==> FALSE
      (42) if (rb_SPI_error_l != 1 && rb_ASIC_SPI_ErrorFlag_g != 1) ==> TRUE
      (43) if (rw_SPINoCommCounter_g > (0)) ==> FALSE
      (44) if ((rab_SPI_RcvCmd_l & 0xc0) != 0x80) ==> TRUE
      (45) if ((rab_SPI_RcvCmd_l & 0xd0) == 0xc0) ==> TRUE
      (46) if ((rab_SPI_WriteBuffer_mg)[0] == 0xc6) ==> TRUE
      (47) if ((rb_PrevMode_g != 4 && rb_CurMode_g != 1) && rb_CurMode_g != 2) ==> TRUE
      (52) if (rb_NextSPI_Request_g == (byte)0x3) ==> FALSE
      (66) if (vc_SSR00_bit.no6 == 0) ==> FALSE
   Test Case Generation Notes:
      Cannot set variable to unknown value in branch 5
      Cannot set rb_SPI_error_l due to assignment
      Cannot set rab_SPI_RcvCmd_l due to assignment
      Cannot set rab_SPI_RcvCmd_l due to assignment
TEST.END_NOTES:
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no5:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no6:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_SPINoCommCounter_g:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]:198
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_bytes_to_send_mg:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_ASIC_SPI_ErrorFlag_g:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_CurMode_g:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_PrevMode_g:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_NextSPI_Request_g:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-026-PARTIAL
TEST.UNIT:G5_spi_sr
TEST.SUBPROGRAM:SPI_int
TEST.NEW
TEST.NAME:BASIS-PATH-026-PARTIAL
TEST.COMPOUND_ONLY
TEST.BASIS_PATH:26 of 67
TEST.NOTES:
This is an automatically generated test case.
   Test Path 26
      (1) while (vc_SSR00_bit.no6 == 1 && vc_SSR00_bit.no5 == 1) ==> FALSE
      (2) if (rb_SPI_WBPosition_mg < rb_SPI_bytes_to_send_mg) ==> FALSE
      (5) if (rab_SPI_RcvCmd_l == ((rab_SPI_WriteBuffer_mg)[0] & 0xfe)) ==> FALSE
      (42) if (rb_SPI_error_l != 1 && rb_ASIC_SPI_ErrorFlag_g != 1) ==> TRUE
      (43) if (rw_SPINoCommCounter_g > (0)) ==> TRUE
      (44) if ((rab_SPI_RcvCmd_l & 0xc0) != 0x80) ==> FALSE
      (51) if (rw_SPINoCommCounter_g > (0)) ==> FALSE
      (52) if (rb_NextSPI_Request_g == (byte)0x3) ==> FALSE
      (66) if (vc_SSR00_bit.no6 == 0) ==> FALSE
   Test Case Generation Notes:
      Cannot set variable to unknown value in branch 5
      Cannot set rb_SPI_error_l due to assignment
      Cannot set rab_SPI_RcvCmd_l due to assignment
      Cannot set rw_SPINoCommCounter_g due to assignment
TEST.END_NOTES:
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no5:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no6:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_SPINoCommCounter_g:<<MAX>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_bytes_to_send_mg:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_ASIC_SPI_ErrorFlag_g:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_NextSPI_Request_g:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-027-PARTIAL
TEST.UNIT:G5_spi_sr
TEST.SUBPROGRAM:SPI_int
TEST.NEW
TEST.NAME:BASIS-PATH-027-PARTIAL
TEST.COMPOUND_ONLY
TEST.BASIS_PATH:27 of 67
TEST.NOTES:
This is an automatically generated test case.
   Test Path 27
      (1) while (vc_SSR00_bit.no6 == 1 && vc_SSR00_bit.no5 == 1) ==> FALSE
      (2) if (rb_SPI_WBPosition_mg < rb_SPI_bytes_to_send_mg) ==> FALSE
      (5) if (rab_SPI_RcvCmd_l == ((rab_SPI_WriteBuffer_mg)[0] & 0xfe)) ==> TRUE
      (6) if ((rab_SPI_RcvCmd_l & 0xf0) == 0xd0) ==> FALSE
      (8) if ((((rab_SPI_WriteBuffer_mg)[0] & 0xc0) == 0x40 || ((rab_SPI_WriteBuffer_mg)[0] & 0xc0) == 0x80) || ((rab_SPI_WriteBuffer_mg)[0] & 0xf8) == 0x10) ==> FALSE
      (40) if (rb_SPI_RcvCmdByte_l == (rb_SPI_WrCmdByte_l & 0xfe)) ==> FALSE
      (42) if (rb_SPI_error_l != 1 && rb_ASIC_SPI_ErrorFlag_g != 1) ==> FALSE
      (57) if (rb_ASIC_SPI_ErrorFlag_g == 0) ==> FALSE
      (58) if (51 == rb_ASIC_ControlMode_g) ==> FALSE
      (60) while ((vc_SE0 & 0x1) == 0) ==> FALSE
      (61) if (rw_SPINoCommCounter_g < (0xff00)) ==> FALSE
      (62) if (rw_SPINoCommCounter_g >= (0xff00)) ==> FALSE
      (63) if (rb_StaticNoCommunicationCounter_g < 255) ==> FALSE
      (64) if (1 == rb_firstReadComm_g) ==> FALSE
      (66) if (vc_SSR00_bit.no6 == 0) ==> FALSE
   Test Case Generation Notes:
      Cannot set variable to unknown value in branch 5
      Cannot set rab_SPI_RcvCmd_l due to assignment
      Cannot set variable to unknown value in branch 40
      Cannot set rb_SPI_error_l due to assignment
      Conflict: Trying to set variable G5_spi_sr.<<GLOBAL>>.rw_SPINoCommCounter_g 'less than' and 'greater than' same value in branches 61/62
TEST.END_NOTES:
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no5:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no6:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SE0:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_SPINoCommCounter_g:<<MAX>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_StaticNoCommunicationCounter_g:<<MAX>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_bytes_to_send_mg:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_firstReadComm_g:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_ASIC_SPI_ErrorFlag_g:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-028-PARTIAL
TEST.UNIT:G5_spi_sr
TEST.SUBPROGRAM:SPI_int
TEST.NEW
TEST.NAME:BASIS-PATH-028-PARTIAL
TEST.COMPOUND_ONLY
TEST.BASIS_PATH:28 of 67
TEST.NOTES:
This is an automatically generated test case.
   Test Path 28
      (1) while (vc_SSR00_bit.no6 == 1 && vc_SSR00_bit.no5 == 1) ==> FALSE
      (2) if (rb_SPI_WBPosition_mg < rb_SPI_bytes_to_send_mg) ==> FALSE
      (5) if (rab_SPI_RcvCmd_l == ((rab_SPI_WriteBuffer_mg)[0] & 0xfe)) ==> TRUE
      (6) if ((rab_SPI_RcvCmd_l & 0xf0) == 0xd0) ==> FALSE
      (8) if ((((rab_SPI_WriteBuffer_mg)[0] & 0xc0) == 0x40 || ((rab_SPI_WriteBuffer_mg)[0] & 0xc0) == 0x80) || ((rab_SPI_WriteBuffer_mg)[0] & 0xf8) == 0x10) ==> FALSE
      (40) if (rb_SPI_RcvCmdByte_l == (rb_SPI_WrCmdByte_l & 0xfe)) ==> TRUE
      (41) if (rb_i_bytes_rcv_l != rb_SPI_bytes_to_send_mg - 1) ==> FALSE
      (42) if (rb_SPI_error_l != 1 && rb_ASIC_SPI_ErrorFlag_g != 1) ==> FALSE
      (57) if (rb_ASIC_SPI_ErrorFlag_g == 0) ==> FALSE
      (58) if (51 == rb_ASIC_ControlMode_g) ==> FALSE
      (60) while ((vc_SE0 & 0x1) == 0) ==> FALSE
      (61) if (rw_SPINoCommCounter_g < (0xff00)) ==> FALSE
      (62) if (rw_SPINoCommCounter_g >= (0xff00)) ==> FALSE
      (63) if (rb_StaticNoCommunicationCounter_g < 255) ==> FALSE
      (64) if (1 == rb_firstReadComm_g) ==> FALSE
      (66) if (vc_SSR00_bit.no6 == 0) ==> FALSE
   Test Case Generation Notes:
      Cannot set variable to unknown value in branch 5
      Cannot set rab_SPI_RcvCmd_l due to assignment
      Cannot set variable to unknown value in branch 40
      Cannot set variable to unknown value in branch 41
      Cannot set local variable rb_SPI_error_l in branch 42
      Conflict: Trying to set variable G5_spi_sr.<<GLOBAL>>.rw_SPINoCommCounter_g 'less than' and 'greater than' same value in branches 61/62
TEST.END_NOTES:
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no5:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no6:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SE0:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_SPINoCommCounter_g:<<MAX>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_StaticNoCommunicationCounter_g:<<MAX>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_bytes_to_send_mg:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_firstReadComm_g:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_ASIC_SPI_ErrorFlag_g:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-029-PARTIAL
TEST.UNIT:G5_spi_sr
TEST.SUBPROGRAM:SPI_int
TEST.NEW
TEST.NAME:BASIS-PATH-029-PARTIAL
TEST.COMPOUND_ONLY
TEST.BASIS_PATH:29 of 67
TEST.NOTES:
This is an automatically generated test case.
   Test Path 29
      (1) while (vc_SSR00_bit.no6 == 1 && vc_SSR00_bit.no5 == 1) ==> FALSE
      (2) if (rb_SPI_WBPosition_mg < rb_SPI_bytes_to_send_mg) ==> FALSE
      (5) if (rab_SPI_RcvCmd_l == ((rab_SPI_WriteBuffer_mg)[0] & 0xfe)) ==> TRUE
      (6) if ((rab_SPI_RcvCmd_l & 0xf0) == 0xd0) ==> FALSE
      (8) if ((((rab_SPI_WriteBuffer_mg)[0] & 0xc0) == 0x40 || ((rab_SPI_WriteBuffer_mg)[0] & 0xc0) == 0x80) || ((rab_SPI_WriteBuffer_mg)[0] & 0xf8) == 0x10) ==> FALSE
      (40) if (rb_SPI_RcvCmdByte_l == (rb_SPI_WrCmdByte_l & 0xfe)) ==> TRUE
      (41) if (rb_i_bytes_rcv_l != rb_SPI_bytes_to_send_mg - 1) ==> TRUE
      (42) if (rb_SPI_error_l != 1 && rb_ASIC_SPI_ErrorFlag_g != 1) ==> FALSE
      (57) if (rb_ASIC_SPI_ErrorFlag_g == 0) ==> FALSE
      (58) if (51 == rb_ASIC_ControlMode_g) ==> FALSE
      (60) while ((vc_SE0 & 0x1) == 0) ==> FALSE
      (61) if (rw_SPINoCommCounter_g < (0xff00)) ==> FALSE
      (62) if (rw_SPINoCommCounter_g >= (0xff00)) ==> FALSE
      (63) if (rb_StaticNoCommunicationCounter_g < 255) ==> FALSE
      (64) if (1 == rb_firstReadComm_g) ==> FALSE
      (66) if (vc_SSR00_bit.no6 == 0) ==> FALSE
   Test Case Generation Notes:
      Cannot set variable to unknown value in branch 5
      Cannot set rab_SPI_RcvCmd_l due to assignment
      Cannot set variable to unknown value in branch 40
      Cannot set variable to unknown value in branch 41
      Cannot set rb_SPI_error_l due to assignment
      Conflict: Trying to set variable G5_spi_sr.<<GLOBAL>>.rw_SPINoCommCounter_g 'less than' and 'greater than' same value in branches 61/62
TEST.END_NOTES:
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no5:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no6:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SE0:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_SPINoCommCounter_g:<<MAX>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_StaticNoCommunicationCounter_g:<<MAX>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_bytes_to_send_mg:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_firstReadComm_g:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_ASIC_SPI_ErrorFlag_g:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-030-PARTIAL
TEST.UNIT:G5_spi_sr
TEST.SUBPROGRAM:SPI_int
TEST.NEW
TEST.NAME:BASIS-PATH-030-PARTIAL
TEST.COMPOUND_ONLY
TEST.BASIS_PATH:30 of 67
TEST.NOTES:
This is an automatically generated test case.
   Test Path 30
      (1) while (vc_SSR00_bit.no6 == 1 && vc_SSR00_bit.no5 == 1) ==> FALSE
      (2) if (rb_SPI_WBPosition_mg < rb_SPI_bytes_to_send_mg) ==> FALSE
      (5) if (rab_SPI_RcvCmd_l == ((rab_SPI_WriteBuffer_mg)[0] & 0xfe)) ==> TRUE
      (6) if ((rab_SPI_RcvCmd_l & 0xf0) == 0xd0) ==> FALSE
      (8) if ((((rab_SPI_WriteBuffer_mg)[0] & 0xc0) == 0x40 || ((rab_SPI_WriteBuffer_mg)[0] & 0xc0) == 0x80) || ((rab_SPI_WriteBuffer_mg)[0] & 0xf8) == 0x10) ==> TRUE
      (9) for (rb_i_bytes_rcv_l < rb_SPI_bytes_to_send_mg - 1) ==> FALSE
      (42) if (rb_SPI_error_l != 1 && rb_ASIC_SPI_ErrorFlag_g != 1) ==> FALSE
      (57) if (rb_ASIC_SPI_ErrorFlag_g == 0) ==> FALSE
      (58) if (51 == rb_ASIC_ControlMode_g) ==> FALSE
      (60) while ((vc_SE0 & 0x1) == 0) ==> FALSE
      (61) if (rw_SPINoCommCounter_g < (0xff00)) ==> FALSE
      (62) if (rw_SPINoCommCounter_g >= (0xff00)) ==> FALSE
      (63) if (rb_StaticNoCommunicationCounter_g < 255) ==> FALSE
      (64) if (1 == rb_firstReadComm_g) ==> FALSE
      (66) if (vc_SSR00_bit.no6 == 0) ==> FALSE
   Test Case Generation Notes:
      Cannot set variable to unknown value in branch 5
      Cannot set rab_SPI_RcvCmd_l due to assignment
      Conflict: Unable to validate expression-to-expression comparison in branch 9
      Cannot set local variable rb_SPI_error_l in branch 42
      Conflict: Trying to set variable G5_spi_sr.<<GLOBAL>>.rw_SPINoCommCounter_g 'less than' and 'greater than' same value in branches 61/62
TEST.END_NOTES:
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no5:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no6:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SE0:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_SPINoCommCounter_g:<<MAX>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_StaticNoCommunicationCounter_g:<<MAX>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]:64
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_bytes_to_send_mg:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_firstReadComm_g:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_ASIC_SPI_ErrorFlag_g:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-031-PARTIAL
TEST.UNIT:G5_spi_sr
TEST.SUBPROGRAM:SPI_int
TEST.NEW
TEST.NAME:BASIS-PATH-031-PARTIAL
TEST.COMPOUND_ONLY
TEST.BASIS_PATH:31 of 67
TEST.NOTES:
This is an automatically generated test case.
   Test Path 31
      (1) while (vc_SSR00_bit.no6 == 1 && vc_SSR00_bit.no5 == 1) ==> FALSE
      (2) if (rb_SPI_WBPosition_mg < rb_SPI_bytes_to_send_mg) ==> FALSE
      (5) if (rab_SPI_RcvCmd_l == ((rab_SPI_WriteBuffer_mg)[0] & 0xfe)) ==> TRUE
      (6) if ((rab_SPI_RcvCmd_l & 0xf0) == 0xd0) ==> FALSE
      (8) if ((((rab_SPI_WriteBuffer_mg)[0] & 0xc0) == 0x40 || ((rab_SPI_WriteBuffer_mg)[0] & 0xc0) == 0x80) || ((rab_SPI_WriteBuffer_mg)[0] & 0xf8) == 0x10) ==> TRUE
      (9) for (rb_i_bytes_rcv_l < rb_SPI_bytes_to_send_mg - 1) ==> TRUE
      (10) if ((rb_SPI_WrCmdByte_l & 0xc0) != 0x80) ==> TRUE
      (11) if (rb_SPI_RcvCmdByte_l == (rb_SPI_WrCmdByte_l & 0xfe) || 1 == rb_read_cmd_l) ==> FALSE
      (42) if (rb_SPI_error_l != 1 && rb_ASIC_SPI_ErrorFlag_g != 1) ==> FALSE
      (57) if (rb_ASIC_SPI_ErrorFlag_g == 0) ==> FALSE
      (58) if (51 == rb_ASIC_ControlMode_g) ==> FALSE
      (60) while ((vc_SE0 & 0x1) == 0) ==> FALSE
      (61) if (rw_SPINoCommCounter_g < (0xff00)) ==> FALSE
      (62) if (rw_SPINoCommCounter_g >= (0xff00)) ==> FALSE
      (63) if (rb_StaticNoCommunicationCounter_g < 255) ==> FALSE
      (64) if (1 == rb_firstReadComm_g) ==> FALSE
      (66) if (vc_SSR00_bit.no6 == 0) ==> FALSE
   Test Case Generation Notes:
      Cannot set variable to unknown value in branch 5
      Cannot set rab_SPI_RcvCmd_l due to assignment
      Conflict: Unable to validate expression-to-expression comparison in branch 9
      Cannot set variable to unknown value in branch 11
      Cannot set local variable rb_read_cmd_l in branch 11
      Cannot set rb_SPI_error_l due to assignment
      Conflict: Trying to set variable G5_spi_sr.<<GLOBAL>>.rw_SPINoCommCounter_g 'less than' and 'greater than' same value in branches 61/62
TEST.END_NOTES:
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no5:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no6:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SE0:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_SPINoCommCounter_g:<<MAX>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_StaticNoCommunicationCounter_g:<<MAX>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_bytes_to_send_mg:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_firstReadComm_g:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_ASIC_SPI_ErrorFlag_g:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-032-PARTIAL
TEST.UNIT:G5_spi_sr
TEST.SUBPROGRAM:SPI_int
TEST.NEW
TEST.NAME:BASIS-PATH-032-PARTIAL
TEST.COMPOUND_ONLY
TEST.BASIS_PATH:32 of 67
TEST.NOTES:
This is an automatically generated test case.
   Test Path 32
      (1) while (vc_SSR00_bit.no6 == 1 && vc_SSR00_bit.no5 == 1) ==> FALSE
      (2) if (rb_SPI_WBPosition_mg < rb_SPI_bytes_to_send_mg) ==> FALSE
      (5) if (rab_SPI_RcvCmd_l == ((rab_SPI_WriteBuffer_mg)[0] & 0xfe)) ==> TRUE
      (6) if ((rab_SPI_RcvCmd_l & 0xf0) == 0xd0) ==> FALSE
      (8) if ((((rab_SPI_WriteBuffer_mg)[0] & 0xc0) == 0x40 || ((rab_SPI_WriteBuffer_mg)[0] & 0xc0) == 0x80) || ((rab_SPI_WriteBuffer_mg)[0] & 0xf8) == 0x10) ==> TRUE
      (9) for (rb_i_bytes_rcv_l < rb_SPI_bytes_to_send_mg - 1) ==> TRUE
      (10) if ((rb_SPI_WrCmdByte_l & 0xc0) != 0x80) ==> TRUE
      (11) if (rb_SPI_RcvCmdByte_l == (rb_SPI_WrCmdByte_l & 0xfe) || 1 == rb_read_cmd_l) ==> TRUE
      (12) if ((rb_SPI_WrCmdByte_l & 0xc0) == 0x40) ==> FALSE
      (16) if (rb_i_bytes_rcv_l != rb_SPI_bytes_to_send_mg - 1) ==> TRUE
      (42) if (rb_SPI_error_l != 1 && rb_ASIC_SPI_ErrorFlag_g != 1) ==> FALSE
      (57) if (rb_ASIC_SPI_ErrorFlag_g == 0) ==> FALSE
      (58) if (51 == rb_ASIC_ControlMode_g) ==> FALSE
      (60) while ((vc_SE0 & 0x1) == 0) ==> FALSE
      (61) if (rw_SPINoCommCounter_g < (0xff00)) ==> FALSE
      (62) if (rw_SPINoCommCounter_g >= (0xff00)) ==> FALSE
      (63) if (rb_StaticNoCommunicationCounter_g < 255) ==> FALSE
      (64) if (1 == rb_firstReadComm_g) ==> FALSE
      (66) if (vc_SSR00_bit.no6 == 0) ==> FALSE
   Test Case Generation Notes:
      Cannot set variable to unknown value in branch 5
      Cannot set rab_SPI_RcvCmd_l due to assignment
      Conflict: Unable to validate expression-to-expression comparison in branch 9
      Cannot set variable to unknown value in branch 11
      Cannot set local variable rb_read_cmd_l in branch 11
      Cannot set local variable rb_read_cmd_l in branch 11
      Cannot set variable to unknown value in branch 16
      Cannot set rb_SPI_error_l due to assignment
      Conflict: Trying to set variable G5_spi_sr.<<GLOBAL>>.rw_SPINoCommCounter_g 'less than' and 'greater than' same value in branches 61/62
TEST.END_NOTES:
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no5:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no6:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SE0:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_SPINoCommCounter_g:<<MAX>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_StaticNoCommunicationCounter_g:<<MAX>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_bytes_to_send_mg:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_firstReadComm_g:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_ASIC_SPI_ErrorFlag_g:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-033-PARTIAL
TEST.UNIT:G5_spi_sr
TEST.SUBPROGRAM:SPI_int
TEST.NEW
TEST.NAME:BASIS-PATH-033-PARTIAL
TEST.COMPOUND_ONLY
TEST.BASIS_PATH:33 of 67
TEST.NOTES:
This is an automatically generated test case.
   Test Path 33
      (1) while (vc_SSR00_bit.no6 == 1 && vc_SSR00_bit.no5 == 1) ==> FALSE
      (2) if (rb_SPI_WBPosition_mg < rb_SPI_bytes_to_send_mg) ==> FALSE
      (5) if (rab_SPI_RcvCmd_l == ((rab_SPI_WriteBuffer_mg)[0] & 0xfe)) ==> TRUE
      (6) if ((rab_SPI_RcvCmd_l & 0xf0) == 0xd0) ==> FALSE
      (8) if ((((rab_SPI_WriteBuffer_mg)[0] & 0xc0) == 0x40 || ((rab_SPI_WriteBuffer_mg)[0] & 0xc0) == 0x80) || ((rab_SPI_WriteBuffer_mg)[0] & 0xf8) == 0x10) ==> TRUE
      (9) for (rb_i_bytes_rcv_l < rb_SPI_bytes_to_send_mg - 1) ==> TRUE
      (10) if ((rb_SPI_WrCmdByte_l & 0xc0) != 0x80) ==> TRUE
      (11) if (rb_SPI_RcvCmdByte_l == (rb_SPI_WrCmdByte_l & 0xfe) || 1 == rb_read_cmd_l) ==> TRUE
      (12) if ((rb_SPI_WrCmdByte_l & 0xc0) == 0x40) ==> FALSE
      (16) if (rb_i_bytes_rcv_l != rb_SPI_bytes_to_send_mg - 1) ==> FALSE
      (42) if (rb_SPI_error_l != 1 && rb_ASIC_SPI_ErrorFlag_g != 1) ==> FALSE
      (57) if (rb_ASIC_SPI_ErrorFlag_g == 0) ==> FALSE
      (58) if (51 == rb_ASIC_ControlMode_g) ==> FALSE
      (60) while ((vc_SE0 & 0x1) == 0) ==> FALSE
      (61) if (rw_SPINoCommCounter_g < (0xff00)) ==> FALSE
      (62) if (rw_SPINoCommCounter_g >= (0xff00)) ==> FALSE
      (63) if (rb_StaticNoCommunicationCounter_g < 255) ==> FALSE
      (64) if (1 == rb_firstReadComm_g) ==> FALSE
      (66) if (vc_SSR00_bit.no6 == 0) ==> FALSE
   Test Case Generation Notes:
      Cannot set variable to unknown value in branch 5
      Cannot set rab_SPI_RcvCmd_l due to assignment
      Conflict: Unable to validate expression-to-expression comparison in branch 9
      Cannot set variable to unknown value in branch 11
      Cannot set local variable rb_read_cmd_l in branch 11
      Cannot set local variable rb_read_cmd_l in branch 11
      Cannot set variable to unknown value in branch 16
      Cannot set local variable rb_SPI_error_l in branch 42
      Conflict: Trying to set variable G5_spi_sr.<<GLOBAL>>.rw_SPINoCommCounter_g 'less than' and 'greater than' same value in branches 61/62
TEST.END_NOTES:
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no5:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no6:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SE0:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_SPINoCommCounter_g:<<MAX>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_StaticNoCommunicationCounter_g:<<MAX>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_bytes_to_send_mg:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_firstReadComm_g:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_ASIC_SPI_ErrorFlag_g:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-034-PARTIAL
TEST.UNIT:G5_spi_sr
TEST.SUBPROGRAM:SPI_int
TEST.NEW
TEST.NAME:BASIS-PATH-034-PARTIAL
TEST.COMPOUND_ONLY
TEST.BASIS_PATH:34 of 67
TEST.NOTES:
This is an automatically generated test case.
   Test Path 34
      (1) while (vc_SSR00_bit.no6 == 1 && vc_SSR00_bit.no5 == 1) ==> FALSE
      (2) if (rb_SPI_WBPosition_mg < rb_SPI_bytes_to_send_mg) ==> FALSE
      (5) if (rab_SPI_RcvCmd_l == ((rab_SPI_WriteBuffer_mg)[0] & 0xfe)) ==> TRUE
      (6) if ((rab_SPI_RcvCmd_l & 0xf0) == 0xd0) ==> FALSE
      (8) if ((((rab_SPI_WriteBuffer_mg)[0] & 0xc0) == 0x40 || ((rab_SPI_WriteBuffer_mg)[0] & 0xc0) == 0x80) || ((rab_SPI_WriteBuffer_mg)[0] & 0xf8) == 0x10) ==> TRUE
      (9) for (rb_i_bytes_rcv_l < rb_SPI_bytes_to_send_mg - 1) ==> TRUE
      (10) if ((rb_SPI_WrCmdByte_l & 0xc0) != 0x80) ==> TRUE
      (11) if (rb_SPI_RcvCmdByte_l == (rb_SPI_WrCmdByte_l & 0xfe) || 1 == rb_read_cmd_l) ==> TRUE
      (12) if ((rb_SPI_WrCmdByte_l & 0xc0) == 0x40) ==> TRUE
      (13) if (((rab_SPI_WriteBuffer_mg)[rb_i_bytes_rcv_l] & 0xfe) != (byte)(~(rab_SPI_ReadBuffer_mg)[rb_i_bytes_rcv_l] << 1)) ==> TRUE
      (42) if (rb_SPI_error_l != 1 && rb_ASIC_SPI_ErrorFlag_g != 1) ==> FALSE
      (57) if (rb_ASIC_SPI_ErrorFlag_g == 0) ==> FALSE
      (58) if (51 == rb_ASIC_ControlMode_g) ==> FALSE
      (60) while ((vc_SE0 & 0x1) == 0) ==> FALSE
      (61) if (rw_SPINoCommCounter_g < (0xff00)) ==> FALSE
      (62) if (rw_SPINoCommCounter_g >= (0xff00)) ==> FALSE
      (63) if (rb_StaticNoCommunicationCounter_g < 255) ==> FALSE
      (64) if (1 == rb_firstReadComm_g) ==> FALSE
      (66) if (vc_SSR00_bit.no6 == 0) ==> FALSE
   Test Case Generation Notes:
      Cannot set variable to unknown value in branch 5
      Cannot set rab_SPI_RcvCmd_l due to assignment
      Conflict: Unable to validate expression-to-expression comparison in branch 9
      Cannot set variable to unknown value in branch 11
      Cannot set local variable rb_read_cmd_l in branch 11
      Cannot set local variable rb_read_cmd_l in branch 11
      Conflict: Multiple equality operators with different values (G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]) in branches 10/12
      Conflict: Unable to validate expression-to-expression comparison in branch 13
      Cannot set rb_SPI_error_l due to assignment
      Conflict: Trying to set variable G5_spi_sr.<<GLOBAL>>.rw_SPINoCommCounter_g 'less than' and 'greater than' same value in branches 61/62
TEST.END_NOTES:
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no5:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no6:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SE0:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_SPINoCommCounter_g:<<MAX>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_StaticNoCommunicationCounter_g:<<MAX>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_bytes_to_send_mg:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_firstReadComm_g:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_ASIC_SPI_ErrorFlag_g:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-035-PARTIAL
TEST.UNIT:G5_spi_sr
TEST.SUBPROGRAM:SPI_int
TEST.NEW
TEST.NAME:BASIS-PATH-035-PARTIAL
TEST.COMPOUND_ONLY
TEST.BASIS_PATH:35 of 67
TEST.NOTES:
This is an automatically generated test case.
   Test Path 35
      (1) while (vc_SSR00_bit.no6 == 1 && vc_SSR00_bit.no5 == 1) ==> FALSE
      (2) if (rb_SPI_WBPosition_mg < rb_SPI_bytes_to_send_mg) ==> FALSE
      (5) if (rab_SPI_RcvCmd_l == ((rab_SPI_WriteBuffer_mg)[0] & 0xfe)) ==> TRUE
      (6) if ((rab_SPI_RcvCmd_l & 0xf0) == 0xd0) ==> FALSE
      (8) if ((((rab_SPI_WriteBuffer_mg)[0] & 0xc0) == 0x40 || ((rab_SPI_WriteBuffer_mg)[0] & 0xc0) == 0x80) || ((rab_SPI_WriteBuffer_mg)[0] & 0xf8) == 0x10) ==> TRUE
      (9) for (rb_i_bytes_rcv_l < rb_SPI_bytes_to_send_mg - 1) ==> TRUE
      (10) if ((rb_SPI_WrCmdByte_l & 0xc0) != 0x80) ==> TRUE
      (11) if (rb_SPI_RcvCmdByte_l == (rb_SPI_WrCmdByte_l & 0xfe) || 1 == rb_read_cmd_l) ==> TRUE
      (12) if ((rb_SPI_WrCmdByte_l & 0xc0) == 0x40) ==> TRUE
      (13) if (((rab_SPI_WriteBuffer_mg)[rb_i_bytes_rcv_l] & 0xfe) != (byte)(~(rab_SPI_ReadBuffer_mg)[rb_i_bytes_rcv_l] << 1)) ==> FALSE
      (14) if ((rb_SPI_WrCmdByte_l & 0xc1) == 0x41) ==> FALSE
      (42) if (rb_SPI_error_l != 1 && rb_ASIC_SPI_ErrorFlag_g != 1) ==> FALSE
      (57) if (rb_ASIC_SPI_ErrorFlag_g == 0) ==> FALSE
      (58) if (51 == rb_ASIC_ControlMode_g) ==> FALSE
      (60) while ((vc_SE0 & 0x1) == 0) ==> FALSE
      (61) if (rw_SPINoCommCounter_g < (0xff00)) ==> FALSE
      (62) if (rw_SPINoCommCounter_g >= (0xff00)) ==> FALSE
      (63) if (rb_StaticNoCommunicationCounter_g < 255) ==> FALSE
      (64) if (1 == rb_firstReadComm_g) ==> FALSE
      (66) if (vc_SSR00_bit.no6 == 0) ==> FALSE
   Test Case Generation Notes:
      Cannot set variable to unknown value in branch 5
      Cannot set rab_SPI_RcvCmd_l due to assignment
      Conflict: Unable to validate expression-to-expression comparison in branch 9
      Cannot set variable to unknown value in branch 11
      Cannot set local variable rb_read_cmd_l in branch 11
      Cannot set local variable rb_read_cmd_l in branch 11
      Conflict: Multiple equality operators with different values (G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]) in branches 10/12
      Conflict: Unable to validate expression-to-expression comparison in branch 13
      Cannot set local variable rb_SPI_error_l in branch 42
      Conflict: Trying to set variable G5_spi_sr.<<GLOBAL>>.rw_SPINoCommCounter_g 'less than' and 'greater than' same value in branches 61/62
TEST.END_NOTES:
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no5:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no6:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SE0:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_SPINoCommCounter_g:<<MAX>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_StaticNoCommunicationCounter_g:<<MAX>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_bytes_to_send_mg:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_firstReadComm_g:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_ASIC_SPI_ErrorFlag_g:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-036-PARTIAL
TEST.UNIT:G5_spi_sr
TEST.SUBPROGRAM:SPI_int
TEST.NEW
TEST.NAME:BASIS-PATH-036-PARTIAL
TEST.COMPOUND_ONLY
TEST.BASIS_PATH:36 of 67
TEST.NOTES:
This is an automatically generated test case.
   Test Path 36
      (1) while (vc_SSR00_bit.no6 == 1 && vc_SSR00_bit.no5 == 1) ==> FALSE
      (2) if (rb_SPI_WBPosition_mg < rb_SPI_bytes_to_send_mg) ==> FALSE
      (5) if (rab_SPI_RcvCmd_l == ((rab_SPI_WriteBuffer_mg)[0] & 0xfe)) ==> TRUE
      (6) if ((rab_SPI_RcvCmd_l & 0xf0) == 0xd0) ==> FALSE
      (8) if ((((rab_SPI_WriteBuffer_mg)[0] & 0xc0) == 0x40 || ((rab_SPI_WriteBuffer_mg)[0] & 0xc0) == 0x80) || ((rab_SPI_WriteBuffer_mg)[0] & 0xf8) == 0x10) ==> TRUE
      (9) for (rb_i_bytes_rcv_l < rb_SPI_bytes_to_send_mg - 1) ==> TRUE
      (10) if ((rb_SPI_WrCmdByte_l & 0xc0) != 0x80) ==> TRUE
      (11) if (rb_SPI_RcvCmdByte_l == (rb_SPI_WrCmdByte_l & 0xfe) || 1 == rb_read_cmd_l) ==> TRUE
      (12) if ((rb_SPI_WrCmdByte_l & 0xc0) == 0x40) ==> TRUE
      (13) if (((rab_SPI_WriteBuffer_mg)[rb_i_bytes_rcv_l] & 0xfe) != (byte)(~(rab_SPI_ReadBuffer_mg)[rb_i_bytes_rcv_l] << 1)) ==> FALSE
      (14) if ((rb_SPI_WrCmdByte_l & 0xc1) == 0x41) ==> TRUE
      (15) if (((rab_SPI_WriteBuffer_mg)[rb_i_bytes_rcv_l] & 0xfe) != (byte)(~(rab_SPI_ReadBuffer_mg)[rb_i_bytes_rcv_l] << 1)) ==> TRUE
      (42) if (rb_SPI_error_l != 1 && rb_ASIC_SPI_ErrorFlag_g != 1) ==> FALSE
      (57) if (rb_ASIC_SPI_ErrorFlag_g == 0) ==> FALSE
      (58) if (51 == rb_ASIC_ControlMode_g) ==> FALSE
      (60) while ((vc_SE0 & 0x1) == 0) ==> FALSE
      (61) if (rw_SPINoCommCounter_g < (0xff00)) ==> FALSE
      (62) if (rw_SPINoCommCounter_g >= (0xff00)) ==> FALSE
      (63) if (rb_StaticNoCommunicationCounter_g < 255) ==> FALSE
      (64) if (1 == rb_firstReadComm_g) ==> FALSE
      (66) if (vc_SSR00_bit.no6 == 0) ==> FALSE
   Test Case Generation Notes:
      Cannot set variable to unknown value in branch 5
      Cannot set rab_SPI_RcvCmd_l due to assignment
      Conflict: Unable to validate expression-to-expression comparison in branch 9
      Cannot set variable to unknown value in branch 11
      Cannot set local variable rb_read_cmd_l in branch 11
      Cannot set local variable rb_read_cmd_l in branch 11
      Conflict: Unable to validate expression-to-expression comparison in branch 13
      Conflict: Multiple equality operators with different values (G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]) in branches 10/12
      Conflict: Multiple equality operators with different values (G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]) in branches 10/14
      Conflict: Unable to validate expression-to-expression comparison in branch 15
      Cannot set rb_SPI_error_l due to assignment
      Conflict: Trying to set variable G5_spi_sr.<<GLOBAL>>.rw_SPINoCommCounter_g 'less than' and 'greater than' same value in branches 61/62
TEST.END_NOTES:
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no5:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no6:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SE0:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_SPINoCommCounter_g:<<MAX>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_StaticNoCommunicationCounter_g:<<MAX>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_bytes_to_send_mg:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_firstReadComm_g:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_ASIC_SPI_ErrorFlag_g:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-037-PARTIAL
TEST.UNIT:G5_spi_sr
TEST.SUBPROGRAM:SPI_int
TEST.NEW
TEST.NAME:BASIS-PATH-037-PARTIAL
TEST.COMPOUND_ONLY
TEST.BASIS_PATH:37 of 67
TEST.NOTES:
This is an automatically generated test case.
   Test Path 37
      (1) while (vc_SSR00_bit.no6 == 1 && vc_SSR00_bit.no5 == 1) ==> FALSE
      (2) if (rb_SPI_WBPosition_mg < rb_SPI_bytes_to_send_mg) ==> FALSE
      (5) if (rab_SPI_RcvCmd_l == ((rab_SPI_WriteBuffer_mg)[0] & 0xfe)) ==> TRUE
      (6) if ((rab_SPI_RcvCmd_l & 0xf0) == 0xd0) ==> FALSE
      (8) if ((((rab_SPI_WriteBuffer_mg)[0] & 0xc0) == 0x40 || ((rab_SPI_WriteBuffer_mg)[0] & 0xc0) == 0x80) || ((rab_SPI_WriteBuffer_mg)[0] & 0xf8) == 0x10) ==> TRUE
      (9) for (rb_i_bytes_rcv_l < rb_SPI_bytes_to_send_mg - 1) ==> TRUE
      (10) if ((rb_SPI_WrCmdByte_l & 0xc0) != 0x80) ==> TRUE
      (11) if (rb_SPI_RcvCmdByte_l == (rb_SPI_WrCmdByte_l & 0xfe) || 1 == rb_read_cmd_l) ==> TRUE
      (12) if ((rb_SPI_WrCmdByte_l & 0xc0) == 0x40) ==> TRUE
      (13) if (((rab_SPI_WriteBuffer_mg)[rb_i_bytes_rcv_l] & 0xfe) != (byte)(~(rab_SPI_ReadBuffer_mg)[rb_i_bytes_rcv_l] << 1)) ==> FALSE
      (14) if ((rb_SPI_WrCmdByte_l & 0xc1) == 0x41) ==> TRUE
      (42) if (rb_SPI_error_l != 1 && rb_ASIC_SPI_ErrorFlag_g != 1) ==> FALSE
      (57) if (rb_ASIC_SPI_ErrorFlag_g == 0) ==> FALSE
      (58) if (51 == rb_ASIC_ControlMode_g) ==> FALSE
      (60) while ((vc_SE0 & 0x1) == 0) ==> FALSE
      (61) if (rw_SPINoCommCounter_g < (0xff00)) ==> FALSE
      (62) if (rw_SPINoCommCounter_g >= (0xff00)) ==> FALSE
      (63) if (rb_StaticNoCommunicationCounter_g < 255) ==> FALSE
      (64) if (1 == rb_firstReadComm_g) ==> FALSE
      (66) if (vc_SSR00_bit.no6 == 0) ==> FALSE
   Test Case Generation Notes:
      Cannot set variable to unknown value in branch 5
      Cannot set rab_SPI_RcvCmd_l due to assignment
      Conflict: Unable to validate expression-to-expression comparison in branch 9
      Cannot set variable to unknown value in branch 11
      Cannot set local variable rb_read_cmd_l in branch 11
      Cannot set local variable rb_read_cmd_l in branch 11
      Conflict: Unable to validate expression-to-expression comparison in branch 13
      Conflict: Multiple equality operators with different values (G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]) in branches 10/12
      Conflict: Multiple equality operators with different values (G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]) in branches 10/14
      Conflict: Unable to validate expression-to-expression comparison in branch 15
      Cannot set local variable rb_SPI_error_l in branch 42
      Conflict: Trying to set variable G5_spi_sr.<<GLOBAL>>.rw_SPINoCommCounter_g 'less than' and 'greater than' same value in branches 61/62
TEST.END_NOTES:
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no5:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no6:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SE0:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_SPINoCommCounter_g:<<MAX>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_StaticNoCommunicationCounter_g:<<MAX>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_bytes_to_send_mg:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_firstReadComm_g:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_ASIC_SPI_ErrorFlag_g:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-038-PARTIAL
TEST.UNIT:G5_spi_sr
TEST.SUBPROGRAM:SPI_int
TEST.NEW
TEST.NAME:BASIS-PATH-038-PARTIAL
TEST.COMPOUND_ONLY
TEST.BASIS_PATH:38 of 67
TEST.NOTES:
This is an automatically generated test case.
   Test Path 38
      (1) while (vc_SSR00_bit.no6 == 1 && vc_SSR00_bit.no5 == 1) ==> FALSE
      (2) if (rb_SPI_WBPosition_mg < rb_SPI_bytes_to_send_mg) ==> FALSE
      (5) if (rab_SPI_RcvCmd_l == ((rab_SPI_WriteBuffer_mg)[0] & 0xfe)) ==> TRUE
      (6) if ((rab_SPI_RcvCmd_l & 0xf0) == 0xd0) ==> FALSE
      (8) if ((((rab_SPI_WriteBuffer_mg)[0] & 0xc0) == 0x40 || ((rab_SPI_WriteBuffer_mg)[0] & 0xc0) == 0x80) || ((rab_SPI_WriteBuffer_mg)[0] & 0xf8) == 0x10) ==> TRUE
      (9) for (rb_i_bytes_rcv_l < rb_SPI_bytes_to_send_mg - 1) ==> TRUE
      (10) if ((rb_SPI_WrCmdByte_l & 0xc0) != 0x80) ==> FALSE
      (17) if ((rb_SPI_WrCmdByte_l & 0x80) == 0x80) ==> FALSE
      (42) if (rb_SPI_error_l != 1 && rb_ASIC_SPI_ErrorFlag_g != 1) ==> FALSE
      (57) if (rb_ASIC_SPI_ErrorFlag_g == 0) ==> FALSE
      (58) if (51 == rb_ASIC_ControlMode_g) ==> FALSE
      (60) while ((vc_SE0 & 0x1) == 0) ==> FALSE
      (61) if (rw_SPINoCommCounter_g < (0xff00)) ==> FALSE
      (62) if (rw_SPINoCommCounter_g >= (0xff00)) ==> FALSE
      (63) if (rb_StaticNoCommunicationCounter_g < 255) ==> FALSE
      (64) if (1 == rb_firstReadComm_g) ==> FALSE
      (66) if (vc_SSR00_bit.no6 == 0) ==> FALSE
   Test Case Generation Notes:
      Cannot set variable to unknown value in branch 5
      Cannot set rab_SPI_RcvCmd_l due to assignment
      Conflict: Unable to validate expression-to-expression comparison in branch 9
      Conflict: Multiple equality operators with different values (G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]) in branches 10/17
      Cannot set rb_SPI_error_l due to assignment
      Conflict: Trying to set variable G5_spi_sr.<<GLOBAL>>.rw_SPINoCommCounter_g 'less than' and 'greater than' same value in branches 61/62
TEST.END_NOTES:
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no5:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no6:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SE0:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_SPINoCommCounter_g:<<MAX>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_StaticNoCommunicationCounter_g:<<MAX>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]:128
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_bytes_to_send_mg:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_firstReadComm_g:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_ASIC_SPI_ErrorFlag_g:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-039-PARTIAL
TEST.UNIT:G5_spi_sr
TEST.SUBPROGRAM:SPI_int
TEST.NEW
TEST.NAME:BASIS-PATH-039-PARTIAL
TEST.COMPOUND_ONLY
TEST.BASIS_PATH:39 of 67
TEST.NOTES:
This is an automatically generated test case.
   Test Path 39
      (1) while (vc_SSR00_bit.no6 == 1 && vc_SSR00_bit.no5 == 1) ==> FALSE
      (2) if (rb_SPI_WBPosition_mg < rb_SPI_bytes_to_send_mg) ==> FALSE
      (5) if (rab_SPI_RcvCmd_l == ((rab_SPI_WriteBuffer_mg)[0] & 0xfe)) ==> TRUE
      (6) if ((rab_SPI_RcvCmd_l & 0xf0) == 0xd0) ==> FALSE
      (8) if ((((rab_SPI_WriteBuffer_mg)[0] & 0xc0) == 0x40 || ((rab_SPI_WriteBuffer_mg)[0] & 0xc0) == 0x80) || ((rab_SPI_WriteBuffer_mg)[0] & 0xf8) == 0x10) ==> TRUE
      (9) for (rb_i_bytes_rcv_l < rb_SPI_bytes_to_send_mg - 1) ==> TRUE
      (10) if ((rb_SPI_WrCmdByte_l & 0xc0) != 0x80) ==> FALSE
      (17) if ((rb_SPI_WrCmdByte_l & 0x80) == 0x80) ==> TRUE
      (18) if ((rab_SPI_WriteBuffer_mg)[rb_idx_cksum_l] & 0x1) ==> FALSE
      (19) if ((rw_ChksumCalc_l & (0xff)) != (rab_SPI_ReadBuffer_mg)[rb_idx_cksum_l] && (rw_ChksumCalc_l + (0x55) & (0xff)) != (rab_SPI_ReadBuffer_mg)[rb_idx_cksum_l]) ==> FALSE
      (23) if ((rw_ChksumCalc_l + (0x55) & (0xff)) == (rab_SPI_ReadBuffer_mg)[rb_idx_cksum_l]) ==> TRUE
      (42) if (rb_SPI_error_l != 1 && rb_ASIC_SPI_ErrorFlag_g != 1) ==> FALSE
      (57) if (rb_ASIC_SPI_ErrorFlag_g == 0) ==> FALSE
      (58) if (51 == rb_ASIC_ControlMode_g) ==> FALSE
      (60) while ((vc_SE0 & 0x1) == 0) ==> FALSE
      (61) if (rw_SPINoCommCounter_g < (0xff00)) ==> FALSE
      (62) if (rw_SPINoCommCounter_g >= (0xff00)) ==> FALSE
      (63) if (rb_StaticNoCommunicationCounter_g < 255) ==> FALSE
      (64) if (1 == rb_firstReadComm_g) ==> FALSE
      (66) if (vc_SSR00_bit.no6 == 0) ==> FALSE
   Test Case Generation Notes:
      Cannot set variable to unknown value in branch 5
      Cannot set rab_SPI_RcvCmd_l due to assignment
      Conflict: Unable to validate expression-to-expression comparison in branch 9
      Conflict: Multiple equality operators with different values (G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]) in branches 10/18
      Cannot set variable to unknown value in branch 19
      Cannot set rb_idx_cksum_l due to assignment
      Cannot set variable to unknown value in branch 23
      Cannot set rb_idx_cksum_l due to assignment
      Cannot set rb_SPI_error_l due to assignment
      Conflict: Trying to set variable G5_spi_sr.<<GLOBAL>>.rw_SPINoCommCounter_g 'less than' and 'greater than' same value in branches 61/62
TEST.END_NOTES:
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no5:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no6:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SE0:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_SPINoCommCounter_g:<<MAX>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_StaticNoCommunicationCounter_g:<<MAX>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]:128
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_bytes_to_send_mg:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_firstReadComm_g:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_ASIC_SPI_ErrorFlag_g:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-040-PARTIAL
TEST.UNIT:G5_spi_sr
TEST.SUBPROGRAM:SPI_int
TEST.NEW
TEST.NAME:BASIS-PATH-040-PARTIAL
TEST.COMPOUND_ONLY
TEST.BASIS_PATH:40 of 67
TEST.NOTES:
This is an automatically generated test case.
   Test Path 40
      (1) while (vc_SSR00_bit.no6 == 1 && vc_SSR00_bit.no5 == 1) ==> FALSE
      (2) if (rb_SPI_WBPosition_mg < rb_SPI_bytes_to_send_mg) ==> FALSE
      (5) if (rab_SPI_RcvCmd_l == ((rab_SPI_WriteBuffer_mg)[0] & 0xfe)) ==> TRUE
      (6) if ((rab_SPI_RcvCmd_l & 0xf0) == 0xd0) ==> FALSE
      (8) if ((((rab_SPI_WriteBuffer_mg)[0] & 0xc0) == 0x40 || ((rab_SPI_WriteBuffer_mg)[0] & 0xc0) == 0x80) || ((rab_SPI_WriteBuffer_mg)[0] & 0xf8) == 0x10) ==> TRUE
      (9) for (rb_i_bytes_rcv_l < rb_SPI_bytes_to_send_mg - 1) ==> TRUE
      (10) if ((rb_SPI_WrCmdByte_l & 0xc0) != 0x80) ==> FALSE
      (17) if ((rb_SPI_WrCmdByte_l & 0x80) == 0x80) ==> TRUE
      (18) if ((rab_SPI_WriteBuffer_mg)[rb_idx_cksum_l] & 0x1) ==> FALSE
      (19) if ((rw_ChksumCalc_l & (0xff)) != (rab_SPI_ReadBuffer_mg)[rb_idx_cksum_l] && (rw_ChksumCalc_l + (0x55) & (0xff)) != (rab_SPI_ReadBuffer_mg)[rb_idx_cksum_l]) ==> FALSE
      (23) if ((rw_ChksumCalc_l + (0x55) & (0xff)) == (rab_SPI_ReadBuffer_mg)[rb_idx_cksum_l]) ==> FALSE
      (24) if (0 == rb_SPI_error_l && 0 == rb_ASIC_SPI_ErrorFlag_g) ==> FALSE
      (42) if (rb_SPI_error_l != 1 && rb_ASIC_SPI_ErrorFlag_g != 1) ==> FALSE
      (57) if (rb_ASIC_SPI_ErrorFlag_g == 0) ==> FALSE
      (58) if (51 == rb_ASIC_ControlMode_g) ==> FALSE
      (60) while ((vc_SE0 & 0x1) == 0) ==> FALSE
      (61) if (rw_SPINoCommCounter_g < (0xff00)) ==> FALSE
      (62) if (rw_SPINoCommCounter_g >= (0xff00)) ==> FALSE
      (63) if (rb_StaticNoCommunicationCounter_g < 255) ==> FALSE
      (64) if (1 == rb_firstReadComm_g) ==> FALSE
      (66) if (vc_SSR00_bit.no6 == 0) ==> FALSE
   Test Case Generation Notes:
      Cannot set variable to unknown value in branch 5
      Cannot set rab_SPI_RcvCmd_l due to assignment
      Conflict: Unable to validate expression-to-expression comparison in branch 9
      Conflict: Multiple equality operators with different values (G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]) in branches 10/18
      Cannot set variable to unknown value in branch 19
      Cannot set rb_idx_cksum_l due to assignment
      Cannot set variable to unknown value in branch 23
      Cannot set rb_idx_cksum_l due to assignment
      Cannot set local variable rb_SPI_error_l in branch 24
      Cannot set local variable rb_SPI_error_l in branch 42
      Conflict: Trying to set variable G5_spi_sr.<<GLOBAL>>.rw_SPINoCommCounter_g 'less than' and 'greater than' same value in branches 61/62
TEST.END_NOTES:
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no5:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no6:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SE0:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_SPINoCommCounter_g:<<MAX>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_StaticNoCommunicationCounter_g:<<MAX>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]:128
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_bytes_to_send_mg:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_firstReadComm_g:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_ASIC_SPI_ErrorFlag_g:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-041-PARTIAL
TEST.UNIT:G5_spi_sr
TEST.SUBPROGRAM:SPI_int
TEST.NEW
TEST.NAME:BASIS-PATH-041-PARTIAL
TEST.COMPOUND_ONLY
TEST.BASIS_PATH:41 of 67
TEST.NOTES:
This is an automatically generated test case.
   Test Path 41
      (1) while (vc_SSR00_bit.no6 == 1 && vc_SSR00_bit.no5 == 1) ==> FALSE
      (2) if (rb_SPI_WBPosition_mg < rb_SPI_bytes_to_send_mg) ==> FALSE
      (5) if (rab_SPI_RcvCmd_l == ((rab_SPI_WriteBuffer_mg)[0] & 0xfe)) ==> TRUE
      (6) if ((rab_SPI_RcvCmd_l & 0xf0) == 0xd0) ==> FALSE
      (8) if ((((rab_SPI_WriteBuffer_mg)[0] & 0xc0) == 0x40 || ((rab_SPI_WriteBuffer_mg)[0] & 0xc0) == 0x80) || ((rab_SPI_WriteBuffer_mg)[0] & 0xf8) == 0x10) ==> TRUE
      (9) for (rb_i_bytes_rcv_l < rb_SPI_bytes_to_send_mg - 1) ==> TRUE
      (10) if ((rb_SPI_WrCmdByte_l & 0xc0) != 0x80) ==> FALSE
      (17) if ((rb_SPI_WrCmdByte_l & 0x80) == 0x80) ==> TRUE
      (18) if ((rab_SPI_WriteBuffer_mg)[rb_idx_cksum_l] & 0x1) ==> FALSE
      (19) if ((rw_ChksumCalc_l & (0xff)) != (rab_SPI_ReadBuffer_mg)[rb_idx_cksum_l] && (rw_ChksumCalc_l + (0x55) & (0xff)) != (rab_SPI_ReadBuffer_mg)[rb_idx_cksum_l]) ==> FALSE
      (23) if ((rw_ChksumCalc_l + (0x55) & (0xff)) == (rab_SPI_ReadBuffer_mg)[rb_idx_cksum_l]) ==> FALSE
      (24) if (0 == rb_SPI_error_l && 0 == rb_ASIC_SPI_ErrorFlag_g) ==> TRUE
      (25) for (j < rb_idx_Max_l) ==> FALSE
      (42) if (rb_SPI_error_l != 1 && rb_ASIC_SPI_ErrorFlag_g != 1) ==> FALSE
      (57) if (rb_ASIC_SPI_ErrorFlag_g == 0) ==> FALSE
      (58) if (51 == rb_ASIC_ControlMode_g) ==> FALSE
      (60) while ((vc_SE0 & 0x1) == 0) ==> FALSE
      (61) if (rw_SPINoCommCounter_g < (0xff00)) ==> FALSE
      (62) if (rw_SPINoCommCounter_g >= (0xff00)) ==> FALSE
      (63) if (rb_StaticNoCommunicationCounter_g < 255) ==> FALSE
      (64) if (1 == rb_firstReadComm_g) ==> FALSE
      (66) if (vc_SSR00_bit.no6 == 0) ==> FALSE
   Test Case Generation Notes:
      Cannot set variable to unknown value in branch 5
      Cannot set rab_SPI_RcvCmd_l due to assignment
      Conflict: Unable to validate expression-to-expression comparison in branch 9
      Conflict: Multiple equality operators with different values (G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]) in branches 10/18
      Cannot set variable to unknown value in branch 19
      Cannot set rb_idx_cksum_l due to assignment
      Cannot set variable to unknown value in branch 23
      Cannot set rb_idx_cksum_l due to assignment
      Cannot set local variable rb_SPI_error_l in branch 24
      Cannot set local variable rb_idx_Max_l in branch 25
      Cannot set local variable rb_SPI_error_l in branch 42
      Conflict: Multiple equality operators with different values (G5_spi_sr.<<GLOBAL>>.rb_ASIC_SPI_ErrorFlag_g) in branches 24/42
      Conflict: Trying to set variable G5_spi_sr.<<GLOBAL>>.rb_ASIC_SPI_ErrorFlag_g 'equal to' and 'not equal to' same value in branches 24/57
      Conflict: Trying to set variable G5_spi_sr.<<GLOBAL>>.rw_SPINoCommCounter_g 'less than' and 'greater than' same value in branches 61/62
TEST.END_NOTES:
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no5:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no6:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SE0:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_SPINoCommCounter_g:<<MAX>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_StaticNoCommunicationCounter_g:<<MAX>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]:128
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_bytes_to_send_mg:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_firstReadComm_g:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_ASIC_SPI_ErrorFlag_g:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-042-PARTIAL
TEST.UNIT:G5_spi_sr
TEST.SUBPROGRAM:SPI_int
TEST.NEW
TEST.NAME:BASIS-PATH-042-PARTIAL
TEST.COMPOUND_ONLY
TEST.BASIS_PATH:42 of 67
TEST.NOTES:
This is an automatically generated test case.
   Test Path 42
      (1) while (vc_SSR00_bit.no6 == 1 && vc_SSR00_bit.no5 == 1) ==> FALSE
      (2) if (rb_SPI_WBPosition_mg < rb_SPI_bytes_to_send_mg) ==> FALSE
      (5) if (rab_SPI_RcvCmd_l == ((rab_SPI_WriteBuffer_mg)[0] & 0xfe)) ==> TRUE
      (6) if ((rab_SPI_RcvCmd_l & 0xf0) == 0xd0) ==> FALSE
      (8) if ((((rab_SPI_WriteBuffer_mg)[0] & 0xc0) == 0x40 || ((rab_SPI_WriteBuffer_mg)[0] & 0xc0) == 0x80) || ((rab_SPI_WriteBuffer_mg)[0] & 0xf8) == 0x10) ==> TRUE
      (9) for (rb_i_bytes_rcv_l < rb_SPI_bytes_to_send_mg - 1) ==> TRUE
      (10) if ((rb_SPI_WrCmdByte_l & 0xc0) != 0x80) ==> FALSE
      (17) if ((rb_SPI_WrCmdByte_l & 0x80) == 0x80) ==> TRUE
      (18) if ((rab_SPI_WriteBuffer_mg)[rb_idx_cksum_l] & 0x1) ==> FALSE
      (19) if ((rw_ChksumCalc_l & (0xff)) != (rab_SPI_ReadBuffer_mg)[rb_idx_cksum_l] && (rw_ChksumCalc_l + (0x55) & (0xff)) != (rab_SPI_ReadBuffer_mg)[rb_idx_cksum_l]) ==> FALSE
      (23) if ((rw_ChksumCalc_l + (0x55) & (0xff)) == (rab_SPI_ReadBuffer_mg)[rb_idx_cksum_l]) ==> FALSE
      (24) if (0 == rb_SPI_error_l && 0 == rb_ASIC_SPI_ErrorFlag_g) ==> TRUE
      (25) for (j < rb_idx_Max_l) ==> TRUE
      (26) if (((ras_ASIC_CtrReg_g)[j]).addr == (rb_SPI_WrCmdByte_l >> 1 & 0x1f)) ==> TRUE
      (27) if (1 == (rb_SPI_WrCmdByte_l & 0x1)) ==> FALSE
      (37) if (0x18 == j || 0x1a == j) ==> FALSE
      (39) if (0x10 == j) ==> FALSE
      (42) if (rb_SPI_error_l != 1 && rb_ASIC_SPI_ErrorFlag_g != 1) ==> FALSE
      (57) if (rb_ASIC_SPI_ErrorFlag_g == 0) ==> FALSE
      (58) if (51 == rb_ASIC_ControlMode_g) ==> FALSE
      (60) while ((vc_SE0 & 0x1) == 0) ==> FALSE
      (61) if (rw_SPINoCommCounter_g < (0xff00)) ==> FALSE
      (62) if (rw_SPINoCommCounter_g >= (0xff00)) ==> FALSE
      (63) if (rb_StaticNoCommunicationCounter_g < 255) ==> FALSE
      (64) if (1 == rb_firstReadComm_g) ==> FALSE
      (66) if (vc_SSR00_bit.no6 == 0) ==> FALSE
   Test Case Generation Notes:
      Cannot set variable to unknown value in branch 5
      Cannot set rab_SPI_RcvCmd_l due to assignment
      Conflict: Unable to validate expression-to-expression comparison in branch 9
      Cannot set variable to unknown value in branch 19
      Cannot set rb_idx_cksum_l due to assignment
      Cannot set variable to unknown value in branch 23
      Cannot set rb_idx_cksum_l due to assignment
      Cannot set local variable rb_SPI_error_l in branch 24
      Cannot set local variable rb_idx_Max_l in branch 25
      Cannot set variable to unknown value in branch 26
      Conflict: Multiple equality operators with different values (G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]) in branches 10/18
      Conflict: Multiple equality operators with different values (G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]) in branches 10/27
      Cannot set j due to assignment
      Cannot set j due to assignment
      Cannot set local variable rb_SPI_error_l in branch 42
      Conflict: Multiple equality operators with different values (G5_spi_sr.<<GLOBAL>>.rb_ASIC_SPI_ErrorFlag_g) in branches 24/42
      Conflict: Trying to set variable G5_spi_sr.<<GLOBAL>>.rb_ASIC_SPI_ErrorFlag_g 'equal to' and 'not equal to' same value in branches 24/57
      Conflict: Trying to set variable G5_spi_sr.<<GLOBAL>>.rw_SPINoCommCounter_g 'less than' and 'greater than' same value in branches 61/62
TEST.END_NOTES:
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no5:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no6:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SE0:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_SPINoCommCounter_g:<<MAX>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_StaticNoCommunicationCounter_g:<<MAX>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]:128
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_bytes_to_send_mg:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_firstReadComm_g:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_ASIC_SPI_ErrorFlag_g:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-043-PARTIAL
TEST.UNIT:G5_spi_sr
TEST.SUBPROGRAM:SPI_int
TEST.NEW
TEST.NAME:BASIS-PATH-043-PARTIAL
TEST.COMPOUND_ONLY
TEST.BASIS_PATH:43 of 67
TEST.NOTES:
This is an automatically generated test case.
   Test Path 43
      (1) while (vc_SSR00_bit.no6 == 1 && vc_SSR00_bit.no5 == 1) ==> FALSE
      (2) if (rb_SPI_WBPosition_mg < rb_SPI_bytes_to_send_mg) ==> FALSE
      (5) if (rab_SPI_RcvCmd_l == ((rab_SPI_WriteBuffer_mg)[0] & 0xfe)) ==> TRUE
      (6) if ((rab_SPI_RcvCmd_l & 0xf0) == 0xd0) ==> FALSE
      (8) if ((((rab_SPI_WriteBuffer_mg)[0] & 0xc0) == 0x40 || ((rab_SPI_WriteBuffer_mg)[0] & 0xc0) == 0x80) || ((rab_SPI_WriteBuffer_mg)[0] & 0xf8) == 0x10) ==> TRUE
      (9) for (rb_i_bytes_rcv_l < rb_SPI_bytes_to_send_mg - 1) ==> TRUE
      (10) if ((rb_SPI_WrCmdByte_l & 0xc0) != 0x80) ==> FALSE
      (17) if ((rb_SPI_WrCmdByte_l & 0x80) == 0x80) ==> TRUE
      (18) if ((rab_SPI_WriteBuffer_mg)[rb_idx_cksum_l] & 0x1) ==> FALSE
      (19) if ((rw_ChksumCalc_l & (0xff)) != (rab_SPI_ReadBuffer_mg)[rb_idx_cksum_l] && (rw_ChksumCalc_l + (0x55) & (0xff)) != (rab_SPI_ReadBuffer_mg)[rb_idx_cksum_l]) ==> FALSE
      (23) if ((rw_ChksumCalc_l + (0x55) & (0xff)) == (rab_SPI_ReadBuffer_mg)[rb_idx_cksum_l]) ==> FALSE
      (24) if (0 == rb_SPI_error_l && 0 == rb_ASIC_SPI_ErrorFlag_g) ==> TRUE
      (25) for (j < rb_idx_Max_l) ==> TRUE
      (26) if (((ras_ASIC_CtrReg_g)[j]).addr == (rb_SPI_WrCmdByte_l >> 1 & 0x1f)) ==> TRUE
      (27) if (1 == (rb_SPI_WrCmdByte_l & 0x1)) ==> FALSE
      (37) if (0x18 == j || 0x1a == j) ==> FALSE
      (39) if (0x10 == j) ==> TRUE
      (42) if (rb_SPI_error_l != 1 && rb_ASIC_SPI_ErrorFlag_g != 1) ==> FALSE
      (57) if (rb_ASIC_SPI_ErrorFlag_g == 0) ==> FALSE
      (58) if (51 == rb_ASIC_ControlMode_g) ==> FALSE
      (60) while ((vc_SE0 & 0x1) == 0) ==> FALSE
      (61) if (rw_SPINoCommCounter_g < (0xff00)) ==> FALSE
      (62) if (rw_SPINoCommCounter_g >= (0xff00)) ==> FALSE
      (63) if (rb_StaticNoCommunicationCounter_g < 255) ==> FALSE
      (64) if (1 == rb_firstReadComm_g) ==> FALSE
      (66) if (vc_SSR00_bit.no6 == 0) ==> FALSE
   Test Case Generation Notes:
      Cannot set variable to unknown value in branch 5
      Cannot set rab_SPI_RcvCmd_l due to assignment
      Conflict: Unable to validate expression-to-expression comparison in branch 9
      Cannot set variable to unknown value in branch 19
      Cannot set rb_idx_cksum_l due to assignment
      Cannot set variable to unknown value in branch 23
      Cannot set rb_idx_cksum_l due to assignment
      Cannot set local variable rb_SPI_error_l in branch 24
      Cannot set local variable rb_idx_Max_l in branch 25
      Cannot set variable to unknown value in branch 26
      Conflict: Multiple equality operators with different values (G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]) in branches 10/18
      Conflict: Multiple equality operators with different values (G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]) in branches 10/27
      Cannot set j due to assignment
      Cannot set j due to assignment
      Cannot set local variable rb_SPI_error_l in branch 42
      Conflict: Multiple equality operators with different values (G5_spi_sr.<<GLOBAL>>.rb_ASIC_SPI_ErrorFlag_g) in branches 24/42
      Conflict: Trying to set variable G5_spi_sr.<<GLOBAL>>.rb_ASIC_SPI_ErrorFlag_g 'equal to' and 'not equal to' same value in branches 24/57
      Conflict: Trying to set variable G5_spi_sr.<<GLOBAL>>.rw_SPINoCommCounter_g 'less than' and 'greater than' same value in branches 61/62
TEST.END_NOTES:
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no5:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no6:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SE0:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_SPINoCommCounter_g:<<MAX>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_StaticNoCommunicationCounter_g:<<MAX>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]:128
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_bytes_to_send_mg:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_firstReadComm_g:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_ASIC_SPI_ErrorFlag_g:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-044-PARTIAL
TEST.UNIT:G5_spi_sr
TEST.SUBPROGRAM:SPI_int
TEST.NEW
TEST.NAME:BASIS-PATH-044-PARTIAL
TEST.COMPOUND_ONLY
TEST.BASIS_PATH:44 of 67
TEST.NOTES:
This is an automatically generated test case.
   Test Path 44
      (1) while (vc_SSR00_bit.no6 == 1 && vc_SSR00_bit.no5 == 1) ==> FALSE
      (2) if (rb_SPI_WBPosition_mg < rb_SPI_bytes_to_send_mg) ==> FALSE
      (5) if (rab_SPI_RcvCmd_l == ((rab_SPI_WriteBuffer_mg)[0] & 0xfe)) ==> TRUE
      (6) if ((rab_SPI_RcvCmd_l & 0xf0) == 0xd0) ==> FALSE
      (8) if ((((rab_SPI_WriteBuffer_mg)[0] & 0xc0) == 0x40 || ((rab_SPI_WriteBuffer_mg)[0] & 0xc0) == 0x80) || ((rab_SPI_WriteBuffer_mg)[0] & 0xf8) == 0x10) ==> TRUE
      (9) for (rb_i_bytes_rcv_l < rb_SPI_bytes_to_send_mg - 1) ==> TRUE
      (10) if ((rb_SPI_WrCmdByte_l & 0xc0) != 0x80) ==> FALSE
      (17) if ((rb_SPI_WrCmdByte_l & 0x80) == 0x80) ==> TRUE
      (18) if ((rab_SPI_WriteBuffer_mg)[rb_idx_cksum_l] & 0x1) ==> FALSE
      (19) if ((rw_ChksumCalc_l & (0xff)) != (rab_SPI_ReadBuffer_mg)[rb_idx_cksum_l] && (rw_ChksumCalc_l + (0x55) & (0xff)) != (rab_SPI_ReadBuffer_mg)[rb_idx_cksum_l]) ==> FALSE
      (23) if ((rw_ChksumCalc_l + (0x55) & (0xff)) == (rab_SPI_ReadBuffer_mg)[rb_idx_cksum_l]) ==> FALSE
      (24) if (0 == rb_SPI_error_l && 0 == rb_ASIC_SPI_ErrorFlag_g) ==> TRUE
      (25) for (j < rb_idx_Max_l) ==> TRUE
      (26) if (((ras_ASIC_CtrReg_g)[j]).addr == (rb_SPI_WrCmdByte_l >> 1 & 0x1f)) ==> TRUE
      (27) if (1 == (rb_SPI_WrCmdByte_l & 0x1)) ==> FALSE
      (37) if (0x18 == j || 0x1a == j) ==> TRUE
      (38) if (rb_NextMUXCfg_g != 0xff) ==> FALSE
      (39) if (0x10 == j) ==> FALSE
      (42) if (rb_SPI_error_l != 1 && rb_ASIC_SPI_ErrorFlag_g != 1) ==> FALSE
      (57) if (rb_ASIC_SPI_ErrorFlag_g == 0) ==> FALSE
      (58) if (51 == rb_ASIC_ControlMode_g) ==> FALSE
      (60) while ((vc_SE0 & 0x1) == 0) ==> FALSE
      (61) if (rw_SPINoCommCounter_g < (0xff00)) ==> FALSE
      (62) if (rw_SPINoCommCounter_g >= (0xff00)) ==> FALSE
      (63) if (rb_StaticNoCommunicationCounter_g < 255) ==> FALSE
      (64) if (1 == rb_firstReadComm_g) ==> FALSE
      (66) if (vc_SSR00_bit.no6 == 0) ==> FALSE
   Test Case Generation Notes:
      Cannot set variable to unknown value in branch 5
      Cannot set rab_SPI_RcvCmd_l due to assignment
      Conflict: Unable to validate expression-to-expression comparison in branch 9
      Cannot set variable to unknown value in branch 19
      Cannot set rb_idx_cksum_l due to assignment
      Cannot set variable to unknown value in branch 23
      Cannot set rb_idx_cksum_l due to assignment
      Cannot set local variable rb_SPI_error_l in branch 24
      Cannot set local variable rb_idx_Max_l in branch 25
      Cannot set variable to unknown value in branch 26
      Conflict: Multiple equality operators with different values (G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]) in branches 10/18
      Conflict: Multiple equality operators with different values (G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]) in branches 10/27
      Cannot set j due to assignment
      Cannot set j due to assignment
      Cannot set local variable rb_SPI_error_l in branch 42
      Conflict: Multiple equality operators with different values (G5_spi_sr.<<GLOBAL>>.rb_ASIC_SPI_ErrorFlag_g) in branches 24/42
      Conflict: Trying to set variable G5_spi_sr.<<GLOBAL>>.rb_ASIC_SPI_ErrorFlag_g 'equal to' and 'not equal to' same value in branches 24/57
      Conflict: Trying to set variable G5_spi_sr.<<GLOBAL>>.rw_SPINoCommCounter_g 'less than' and 'greater than' same value in branches 61/62
TEST.END_NOTES:
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no5:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no6:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SE0:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_SPINoCommCounter_g:<<MAX>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_StaticNoCommunicationCounter_g:<<MAX>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]:128
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_bytes_to_send_mg:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_firstReadComm_g:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_ASIC_SPI_ErrorFlag_g:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_NextMUXCfg_g:255
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-045-PARTIAL
TEST.UNIT:G5_spi_sr
TEST.SUBPROGRAM:SPI_int
TEST.NEW
TEST.NAME:BASIS-PATH-045-PARTIAL
TEST.COMPOUND_ONLY
TEST.BASIS_PATH:45 of 67
TEST.NOTES:
This is an automatically generated test case.
   Test Path 45
      (1) while (vc_SSR00_bit.no6 == 1 && vc_SSR00_bit.no5 == 1) ==> FALSE
      (2) if (rb_SPI_WBPosition_mg < rb_SPI_bytes_to_send_mg) ==> FALSE
      (5) if (rab_SPI_RcvCmd_l == ((rab_SPI_WriteBuffer_mg)[0] & 0xfe)) ==> TRUE
      (6) if ((rab_SPI_RcvCmd_l & 0xf0) == 0xd0) ==> FALSE
      (8) if ((((rab_SPI_WriteBuffer_mg)[0] & 0xc0) == 0x40 || ((rab_SPI_WriteBuffer_mg)[0] & 0xc0) == 0x80) || ((rab_SPI_WriteBuffer_mg)[0] & 0xf8) == 0x10) ==> TRUE
      (9) for (rb_i_bytes_rcv_l < rb_SPI_bytes_to_send_mg - 1) ==> TRUE
      (10) if ((rb_SPI_WrCmdByte_l & 0xc0) != 0x80) ==> FALSE
      (17) if ((rb_SPI_WrCmdByte_l & 0x80) == 0x80) ==> TRUE
      (18) if ((rab_SPI_WriteBuffer_mg)[rb_idx_cksum_l] & 0x1) ==> FALSE
      (19) if ((rw_ChksumCalc_l & (0xff)) != (rab_SPI_ReadBuffer_mg)[rb_idx_cksum_l] && (rw_ChksumCalc_l + (0x55) & (0xff)) != (rab_SPI_ReadBuffer_mg)[rb_idx_cksum_l]) ==> FALSE
      (23) if ((rw_ChksumCalc_l + (0x55) & (0xff)) == (rab_SPI_ReadBuffer_mg)[rb_idx_cksum_l]) ==> FALSE
      (24) if (0 == rb_SPI_error_l && 0 == rb_ASIC_SPI_ErrorFlag_g) ==> TRUE
      (25) for (j < rb_idx_Max_l) ==> TRUE
      (26) if (((ras_ASIC_CtrReg_g)[j]).addr == (rb_SPI_WrCmdByte_l >> 1 & 0x1f)) ==> TRUE
      (27) if (1 == (rb_SPI_WrCmdByte_l & 0x1)) ==> FALSE
      (37) if (0x18 == j || 0x1a == j) ==> TRUE
      (38) if (rb_NextMUXCfg_g != 0xff) ==> TRUE
      (39) if (0x10 == j) ==> FALSE
      (42) if (rb_SPI_error_l != 1 && rb_ASIC_SPI_ErrorFlag_g != 1) ==> FALSE
      (57) if (rb_ASIC_SPI_ErrorFlag_g == 0) ==> FALSE
      (58) if (51 == rb_ASIC_ControlMode_g) ==> FALSE
      (60) while ((vc_SE0 & 0x1) == 0) ==> FALSE
      (61) if (rw_SPINoCommCounter_g < (0xff00)) ==> FALSE
      (62) if (rw_SPINoCommCounter_g >= (0xff00)) ==> FALSE
      (63) if (rb_StaticNoCommunicationCounter_g < 255) ==> FALSE
      (64) if (1 == rb_firstReadComm_g) ==> FALSE
      (66) if (vc_SSR00_bit.no6 == 0) ==> FALSE
   Test Case Generation Notes:
      Cannot set variable to unknown value in branch 5
      Cannot set rab_SPI_RcvCmd_l due to assignment
      Conflict: Unable to validate expression-to-expression comparison in branch 9
      Cannot set variable to unknown value in branch 19
      Cannot set rb_idx_cksum_l due to assignment
      Cannot set variable to unknown value in branch 23
      Cannot set rb_idx_cksum_l due to assignment
      Cannot set local variable rb_SPI_error_l in branch 24
      Cannot set local variable rb_idx_Max_l in branch 25
      Cannot set variable to unknown value in branch 26
      Conflict: Multiple equality operators with different values (G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]) in branches 10/18
      Conflict: Multiple equality operators with different values (G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]) in branches 10/27
      Cannot set j due to assignment
      Cannot set j due to assignment
      Cannot set local variable rb_SPI_error_l in branch 42
      Conflict: Multiple equality operators with different values (G5_spi_sr.<<GLOBAL>>.rb_ASIC_SPI_ErrorFlag_g) in branches 24/42
      Conflict: Trying to set variable G5_spi_sr.<<GLOBAL>>.rb_ASIC_SPI_ErrorFlag_g 'equal to' and 'not equal to' same value in branches 24/57
      Conflict: Trying to set variable G5_spi_sr.<<GLOBAL>>.rw_SPINoCommCounter_g 'less than' and 'greater than' same value in branches 61/62
TEST.END_NOTES:
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no5:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no6:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SE0:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_SPINoCommCounter_g:<<MAX>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_StaticNoCommunicationCounter_g:<<MAX>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]:128
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_bytes_to_send_mg:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_firstReadComm_g:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_ASIC_SPI_ErrorFlag_g:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_NextMUXCfg_g:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-046-PARTIAL
TEST.UNIT:G5_spi_sr
TEST.SUBPROGRAM:SPI_int
TEST.NEW
TEST.NAME:BASIS-PATH-046-PARTIAL
TEST.COMPOUND_ONLY
TEST.BASIS_PATH:46 of 67
TEST.NOTES:
This is an automatically generated test case.
   Test Path 46
      (1) while (vc_SSR00_bit.no6 == 1 && vc_SSR00_bit.no5 == 1) ==> FALSE
      (2) if (rb_SPI_WBPosition_mg < rb_SPI_bytes_to_send_mg) ==> FALSE
      (5) if (rab_SPI_RcvCmd_l == ((rab_SPI_WriteBuffer_mg)[0] & 0xfe)) ==> TRUE
      (6) if ((rab_SPI_RcvCmd_l & 0xf0) == 0xd0) ==> FALSE
      (8) if ((((rab_SPI_WriteBuffer_mg)[0] & 0xc0) == 0x40 || ((rab_SPI_WriteBuffer_mg)[0] & 0xc0) == 0x80) || ((rab_SPI_WriteBuffer_mg)[0] & 0xf8) == 0x10) ==> TRUE
      (9) for (rb_i_bytes_rcv_l < rb_SPI_bytes_to_send_mg - 1) ==> TRUE
      (10) if ((rb_SPI_WrCmdByte_l & 0xc0) != 0x80) ==> FALSE
      (17) if ((rb_SPI_WrCmdByte_l & 0x80) == 0x80) ==> TRUE
      (18) if ((rab_SPI_WriteBuffer_mg)[rb_idx_cksum_l] & 0x1) ==> FALSE
      (19) if ((rw_ChksumCalc_l & (0xff)) != (rab_SPI_ReadBuffer_mg)[rb_idx_cksum_l] && (rw_ChksumCalc_l + (0x55) & (0xff)) != (rab_SPI_ReadBuffer_mg)[rb_idx_cksum_l]) ==> FALSE
      (23) if ((rw_ChksumCalc_l + (0x55) & (0xff)) == (rab_SPI_ReadBuffer_mg)[rb_idx_cksum_l]) ==> FALSE
      (24) if (0 == rb_SPI_error_l && 0 == rb_ASIC_SPI_ErrorFlag_g) ==> TRUE
      (25) for (j < rb_idx_Max_l) ==> TRUE
      (26) if (((ras_ASIC_CtrReg_g)[j]).addr == (rb_SPI_WrCmdByte_l >> 1 & 0x1f)) ==> TRUE
      (27) if (1 == (rb_SPI_WrCmdByte_l & 0x1)) ==> TRUE
      (28) if (0x14 == j || 0x15 == j) ==> FALSE
      (37) if (0x18 == j || 0x1a == j) ==> FALSE
      (39) if (0x10 == j) ==> FALSE
      (42) if (rb_SPI_error_l != 1 && rb_ASIC_SPI_ErrorFlag_g != 1) ==> FALSE
      (57) if (rb_ASIC_SPI_ErrorFlag_g == 0) ==> FALSE
      (58) if (51 == rb_ASIC_ControlMode_g) ==> FALSE
      (60) while ((vc_SE0 & 0x1) == 0) ==> FALSE
      (61) if (rw_SPINoCommCounter_g < (0xff00)) ==> FALSE
      (62) if (rw_SPINoCommCounter_g >= (0xff00)) ==> FALSE
      (63) if (rb_StaticNoCommunicationCounter_g < 255) ==> FALSE
      (64) if (1 == rb_firstReadComm_g) ==> FALSE
      (66) if (vc_SSR00_bit.no6 == 0) ==> FALSE
   Test Case Generation Notes:
      Cannot set variable to unknown value in branch 5
      Cannot set rab_SPI_RcvCmd_l due to assignment
      Conflict: Unable to validate expression-to-expression comparison in branch 9
      Cannot set variable to unknown value in branch 19
      Cannot set rb_idx_cksum_l due to assignment
      Cannot set variable to unknown value in branch 23
      Cannot set rb_idx_cksum_l due to assignment
      Cannot set local variable rb_SPI_error_l in branch 24
      Cannot set local variable rb_idx_Max_l in branch 25
      Cannot set variable to unknown value in branch 26
      Conflict: Multiple equality operators with different values (G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]) in branches 10/18
      Conflict: Multiple equality operators with different values (G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]) in branches 10/27
      Cannot set j due to assignment
      Cannot set j due to assignment
      Cannot set j due to assignment
      Cannot set local variable rb_SPI_error_l in branch 42
      Conflict: Multiple equality operators with different values (G5_spi_sr.<<GLOBAL>>.rb_ASIC_SPI_ErrorFlag_g) in branches 24/42
      Conflict: Trying to set variable G5_spi_sr.<<GLOBAL>>.rb_ASIC_SPI_ErrorFlag_g 'equal to' and 'not equal to' same value in branches 24/57
      Conflict: Trying to set variable G5_spi_sr.<<GLOBAL>>.rw_SPINoCommCounter_g 'less than' and 'greater than' same value in branches 61/62
TEST.END_NOTES:
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no5:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no6:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SE0:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_SPINoCommCounter_g:<<MAX>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_StaticNoCommunicationCounter_g:<<MAX>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]:128
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_bytes_to_send_mg:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_firstReadComm_g:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_ASIC_SPI_ErrorFlag_g:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-047-PARTIAL
TEST.UNIT:G5_spi_sr
TEST.SUBPROGRAM:SPI_int
TEST.NEW
TEST.NAME:BASIS-PATH-047-PARTIAL
TEST.COMPOUND_ONLY
TEST.BASIS_PATH:47 of 67
TEST.NOTES:
This is an automatically generated test case.
   Test Path 47
      (1) while (vc_SSR00_bit.no6 == 1 && vc_SSR00_bit.no5 == 1) ==> FALSE
      (2) if (rb_SPI_WBPosition_mg < rb_SPI_bytes_to_send_mg) ==> FALSE
      (5) if (rab_SPI_RcvCmd_l == ((rab_SPI_WriteBuffer_mg)[0] & 0xfe)) ==> TRUE
      (6) if ((rab_SPI_RcvCmd_l & 0xf0) == 0xd0) ==> FALSE
      (8) if ((((rab_SPI_WriteBuffer_mg)[0] & 0xc0) == 0x40 || ((rab_SPI_WriteBuffer_mg)[0] & 0xc0) == 0x80) || ((rab_SPI_WriteBuffer_mg)[0] & 0xf8) == 0x10) ==> TRUE
      (9) for (rb_i_bytes_rcv_l < rb_SPI_bytes_to_send_mg - 1) ==> TRUE
      (10) if ((rb_SPI_WrCmdByte_l & 0xc0) != 0x80) ==> FALSE
      (17) if ((rb_SPI_WrCmdByte_l & 0x80) == 0x80) ==> TRUE
      (18) if ((rab_SPI_WriteBuffer_mg)[rb_idx_cksum_l] & 0x1) ==> FALSE
      (19) if ((rw_ChksumCalc_l & (0xff)) != (rab_SPI_ReadBuffer_mg)[rb_idx_cksum_l] && (rw_ChksumCalc_l + (0x55) & (0xff)) != (rab_SPI_ReadBuffer_mg)[rb_idx_cksum_l]) ==> FALSE
      (23) if ((rw_ChksumCalc_l + (0x55) & (0xff)) == (rab_SPI_ReadBuffer_mg)[rb_idx_cksum_l]) ==> FALSE
      (24) if (0 == rb_SPI_error_l && 0 == rb_ASIC_SPI_ErrorFlag_g) ==> TRUE
      (25) for (j < rb_idx_Max_l) ==> TRUE
      (26) if (((ras_ASIC_CtrReg_g)[j]).addr == (rb_SPI_WrCmdByte_l >> 1 & 0x1f)) ==> TRUE
      (27) if (1 == (rb_SPI_WrCmdByte_l & 0x1)) ==> TRUE
      (28) if (0x14 == j || 0x15 == j) ==> TRUE
      (29) if ((((ras_ASIC_CtrReg_g)[0x15]).val & 0x1) == 1) ==> FALSE
      (30) if (5 == rb_CurMode_g) ==> FALSE
      (31) if (rw_INTV10bit_min_g > (unsigned)((((ras_ASIC_CtrReg_g)[0x14]).val << 2) + (((ras_ASIC_CtrReg_g)[0x15]).val >> 6))) ==> FALSE
      (32) if ((unsigned)((((ras_ASIC_CtrReg_g)[0x14]).val << 2) + (((ras_ASIC_CtrReg_g)[0x15]).val >> 6)) > rw_INTV10bit_max_g) ==> FALSE
      (33) if (rw_REGV_min_g > (unsigned)(((ras_ASIC_CtrReg_g)[0xd]).val << 4) + (((ras_ASIC_CtrReg_g)[0xe]).val >> 4)) ==> FALSE
      (34) if ((unsigned)(((ras_ASIC_CtrReg_g)[0xd]).val << 4) + (((ras_ASIC_CtrReg_g)[0xe]).val >> 4) > rw_REGV_max_g) ==> FALSE
      (35) if (rw_LIN_INTV10bit_min_g > (unsigned)((((ras_ASIC_CtrReg_g)[0x14]).val << 2) + (((ras_ASIC_CtrReg_g)[0x15]).val >> 6))) ==> FALSE
      (36) if ((unsigned)((((ras_ASIC_CtrReg_g)[0x14]).val << 2) + (((ras_ASIC_CtrReg_g)[0x15]).val >> 6)) > rw_LIN_INTV10bit_max_g) ==> FALSE
      (37) if (0x18 == j || 0x1a == j) ==> FALSE
      (39) if (0x10 == j) ==> FALSE
      (42) if (rb_SPI_error_l != 1 && rb_ASIC_SPI_ErrorFlag_g != 1) ==> FALSE
      (57) if (rb_ASIC_SPI_ErrorFlag_g == 0) ==> FALSE
      (58) if (51 == rb_ASIC_ControlMode_g) ==> FALSE
      (60) while ((vc_SE0 & 0x1) == 0) ==> FALSE
      (61) if (rw_SPINoCommCounter_g < (0xff00)) ==> FALSE
      (62) if (rw_SPINoCommCounter_g >= (0xff00)) ==> FALSE
      (63) if (rb_StaticNoCommunicationCounter_g < 255) ==> FALSE
      (64) if (1 == rb_firstReadComm_g) ==> FALSE
      (66) if (vc_SSR00_bit.no6 == 0) ==> FALSE
   Test Case Generation Notes:
      Cannot set variable to unknown value in branch 5
      Cannot set rab_SPI_RcvCmd_l due to assignment
      Conflict: Unable to validate expression-to-expression comparison in branch 9
      Cannot set variable to unknown value in branch 19
      Cannot set rb_idx_cksum_l due to assignment
      Cannot set variable to unknown value in branch 23
      Cannot set rb_idx_cksum_l due to assignment
      Cannot set local variable rb_SPI_error_l in branch 24
      Cannot set local variable rb_idx_Max_l in branch 25
      Cannot set variable to unknown value in branch 26
      Conflict: Multiple equality operators with different values (G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]) in branches 10/18
      Conflict: Multiple equality operators with different values (G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]) in branches 10/27
      Cannot set j due to assignment
      Cannot set j due to assignment
      Cannot set j due to assignment
      Cannot set local variable rb_SPI_error_l in branch 42
      Conflict: Multiple equality operators with different values (G5_spi_sr.<<GLOBAL>>.rb_ASIC_SPI_ErrorFlag_g) in branches 24/42
      Conflict: Trying to set variable G5_spi_sr.<<GLOBAL>>.rb_ASIC_SPI_ErrorFlag_g 'equal to' and 'not equal to' same value in branches 24/57
      Conflict: Trying to set variable G5_spi_sr.<<GLOBAL>>.rw_SPINoCommCounter_g 'less than' and 'greater than' same value in branches 61/62
TEST.END_NOTES:
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no5:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no6:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SE0:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_SPINoCommCounter_g:<<MAX>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_StaticNoCommunicationCounter_g:<<MAX>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]:128
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_bytes_to_send_mg:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_firstReadComm_g:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_ASIC_SPI_ErrorFlag_g:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_CurMode_g:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_INTV10bit_min_g:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_INTV10bit_max_g:<<MAX>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_REGV_min_g:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_REGV_max_g:<<MAX>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_LIN_INTV10bit_min_g:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_LIN_INTV10bit_max_g:<<MAX>>
TEST.END

-- Test Case: BASIS-PATH-048-PARTIAL
TEST.UNIT:G5_spi_sr
TEST.SUBPROGRAM:SPI_int
TEST.NEW
TEST.NAME:BASIS-PATH-048-PARTIAL
TEST.COMPOUND_ONLY
TEST.BASIS_PATH:48 of 67
TEST.NOTES:
This is an automatically generated test case.
   Test Path 48
      (1) while (vc_SSR00_bit.no6 == 1 && vc_SSR00_bit.no5 == 1) ==> FALSE
      (2) if (rb_SPI_WBPosition_mg < rb_SPI_bytes_to_send_mg) ==> FALSE
      (5) if (rab_SPI_RcvCmd_l == ((rab_SPI_WriteBuffer_mg)[0] & 0xfe)) ==> TRUE
      (6) if ((rab_SPI_RcvCmd_l & 0xf0) == 0xd0) ==> FALSE
      (8) if ((((rab_SPI_WriteBuffer_mg)[0] & 0xc0) == 0x40 || ((rab_SPI_WriteBuffer_mg)[0] & 0xc0) == 0x80) || ((rab_SPI_WriteBuffer_mg)[0] & 0xf8) == 0x10) ==> TRUE
      (9) for (rb_i_bytes_rcv_l < rb_SPI_bytes_to_send_mg - 1) ==> TRUE
      (10) if ((rb_SPI_WrCmdByte_l & 0xc0) != 0x80) ==> FALSE
      (17) if ((rb_SPI_WrCmdByte_l & 0x80) == 0x80) ==> TRUE
      (18) if ((rab_SPI_WriteBuffer_mg)[rb_idx_cksum_l] & 0x1) ==> FALSE
      (19) if ((rw_ChksumCalc_l & (0xff)) != (rab_SPI_ReadBuffer_mg)[rb_idx_cksum_l] && (rw_ChksumCalc_l + (0x55) & (0xff)) != (rab_SPI_ReadBuffer_mg)[rb_idx_cksum_l]) ==> FALSE
      (23) if ((rw_ChksumCalc_l + (0x55) & (0xff)) == (rab_SPI_ReadBuffer_mg)[rb_idx_cksum_l]) ==> FALSE
      (24) if (0 == rb_SPI_error_l && 0 == rb_ASIC_SPI_ErrorFlag_g) ==> TRUE
      (25) for (j < rb_idx_Max_l) ==> TRUE
      (26) if (((ras_ASIC_CtrReg_g)[j]).addr == (rb_SPI_WrCmdByte_l >> 1 & 0x1f)) ==> TRUE
      (27) if (1 == (rb_SPI_WrCmdByte_l & 0x1)) ==> TRUE
      (28) if (0x14 == j || 0x15 == j) ==> TRUE
      (29) if ((((ras_ASIC_CtrReg_g)[0x15]).val & 0x1) == 1) ==> FALSE
      (30) if (5 == rb_CurMode_g) ==> FALSE
      (31) if (rw_INTV10bit_min_g > (unsigned)((((ras_ASIC_CtrReg_g)[0x14]).val << 2) + (((ras_ASIC_CtrReg_g)[0x15]).val >> 6))) ==> FALSE
      (32) if ((unsigned)((((ras_ASIC_CtrReg_g)[0x14]).val << 2) + (((ras_ASIC_CtrReg_g)[0x15]).val >> 6)) > rw_INTV10bit_max_g) ==> FALSE
      (33) if (rw_REGV_min_g > (unsigned)(((ras_ASIC_CtrReg_g)[0xd]).val << 4) + (((ras_ASIC_CtrReg_g)[0xe]).val >> 4)) ==> FALSE
      (34) if ((unsigned)(((ras_ASIC_CtrReg_g)[0xd]).val << 4) + (((ras_ASIC_CtrReg_g)[0xe]).val >> 4) > rw_REGV_max_g) ==> FALSE
      (35) if (rw_LIN_INTV10bit_min_g > (unsigned)((((ras_ASIC_CtrReg_g)[0x14]).val << 2) + (((ras_ASIC_CtrReg_g)[0x15]).val >> 6))) ==> FALSE
      (36) if ((unsigned)((((ras_ASIC_CtrReg_g)[0x14]).val << 2) + (((ras_ASIC_CtrReg_g)[0x15]).val >> 6)) > rw_LIN_INTV10bit_max_g) ==> TRUE
      (37) if (0x18 == j || 0x1a == j) ==> FALSE
      (39) if (0x10 == j) ==> FALSE
      (42) if (rb_SPI_error_l != 1 && rb_ASIC_SPI_ErrorFlag_g != 1) ==> FALSE
      (57) if (rb_ASIC_SPI_ErrorFlag_g == 0) ==> FALSE
      (58) if (51 == rb_ASIC_ControlMode_g) ==> FALSE
      (60) while ((vc_SE0 & 0x1) == 0) ==> FALSE
      (61) if (rw_SPINoCommCounter_g < (0xff00)) ==> FALSE
      (62) if (rw_SPINoCommCounter_g >= (0xff00)) ==> FALSE
      (63) if (rb_StaticNoCommunicationCounter_g < 255) ==> FALSE
      (64) if (1 == rb_firstReadComm_g) ==> FALSE
      (66) if (vc_SSR00_bit.no6 == 0) ==> FALSE
   Test Case Generation Notes:
      Cannot set variable to unknown value in branch 5
      Cannot set rab_SPI_RcvCmd_l due to assignment
      Conflict: Unable to validate expression-to-expression comparison in branch 9
      Cannot set variable to unknown value in branch 19
      Cannot set rb_idx_cksum_l due to assignment
      Cannot set variable to unknown value in branch 23
      Cannot set rb_idx_cksum_l due to assignment
      Cannot set local variable rb_SPI_error_l in branch 24
      Cannot set local variable rb_idx_Max_l in branch 25
      Cannot set variable to unknown value in branch 26
      Conflict: Multiple equality operators with different values (G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]) in branches 10/18
      Conflict: Multiple equality operators with different values (G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]) in branches 10/27
      Cannot set j due to assignment
      Cannot set j due to assignment
      Cannot set j due to assignment
      Cannot set local variable rb_SPI_error_l in branch 42
      Conflict: Multiple equality operators with different values (G5_spi_sr.<<GLOBAL>>.rb_ASIC_SPI_ErrorFlag_g) in branches 24/42
      Conflict: Trying to set variable G5_spi_sr.<<GLOBAL>>.rb_ASIC_SPI_ErrorFlag_g 'equal to' and 'not equal to' same value in branches 24/57
      Conflict: Trying to set variable G5_spi_sr.<<GLOBAL>>.rw_SPINoCommCounter_g 'less than' and 'greater than' same value in branches 61/62
TEST.END_NOTES:
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no5:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no6:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SE0:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_SPINoCommCounter_g:<<MAX>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_StaticNoCommunicationCounter_g:<<MAX>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]:128
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_bytes_to_send_mg:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_firstReadComm_g:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_ASIC_SPI_ErrorFlag_g:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_CurMode_g:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_INTV10bit_min_g:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_INTV10bit_max_g:<<MAX>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_REGV_min_g:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_REGV_max_g:<<MAX>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_LIN_INTV10bit_min_g:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_LIN_INTV10bit_max_g:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-049-PARTIAL
TEST.UNIT:G5_spi_sr
TEST.SUBPROGRAM:SPI_int
TEST.NEW
TEST.NAME:BASIS-PATH-049-PARTIAL
TEST.COMPOUND_ONLY
TEST.BASIS_PATH:49 of 67
TEST.NOTES:
This is an automatically generated test case.
   Test Path 49
      (1) while (vc_SSR00_bit.no6 == 1 && vc_SSR00_bit.no5 == 1) ==> FALSE
      (2) if (rb_SPI_WBPosition_mg < rb_SPI_bytes_to_send_mg) ==> FALSE
      (5) if (rab_SPI_RcvCmd_l == ((rab_SPI_WriteBuffer_mg)[0] & 0xfe)) ==> TRUE
      (6) if ((rab_SPI_RcvCmd_l & 0xf0) == 0xd0) ==> FALSE
      (8) if ((((rab_SPI_WriteBuffer_mg)[0] & 0xc0) == 0x40 || ((rab_SPI_WriteBuffer_mg)[0] & 0xc0) == 0x80) || ((rab_SPI_WriteBuffer_mg)[0] & 0xf8) == 0x10) ==> TRUE
      (9) for (rb_i_bytes_rcv_l < rb_SPI_bytes_to_send_mg - 1) ==> TRUE
      (10) if ((rb_SPI_WrCmdByte_l & 0xc0) != 0x80) ==> FALSE
      (17) if ((rb_SPI_WrCmdByte_l & 0x80) == 0x80) ==> TRUE
      (18) if ((rab_SPI_WriteBuffer_mg)[rb_idx_cksum_l] & 0x1) ==> FALSE
      (19) if ((rw_ChksumCalc_l & (0xff)) != (rab_SPI_ReadBuffer_mg)[rb_idx_cksum_l] && (rw_ChksumCalc_l + (0x55) & (0xff)) != (rab_SPI_ReadBuffer_mg)[rb_idx_cksum_l]) ==> FALSE
      (23) if ((rw_ChksumCalc_l + (0x55) & (0xff)) == (rab_SPI_ReadBuffer_mg)[rb_idx_cksum_l]) ==> FALSE
      (24) if (0 == rb_SPI_error_l && 0 == rb_ASIC_SPI_ErrorFlag_g) ==> TRUE
      (25) for (j < rb_idx_Max_l) ==> TRUE
      (26) if (((ras_ASIC_CtrReg_g)[j]).addr == (rb_SPI_WrCmdByte_l >> 1 & 0x1f)) ==> TRUE
      (27) if (1 == (rb_SPI_WrCmdByte_l & 0x1)) ==> TRUE
      (28) if (0x14 == j || 0x15 == j) ==> TRUE
      (29) if ((((ras_ASIC_CtrReg_g)[0x15]).val & 0x1) == 1) ==> FALSE
      (30) if (5 == rb_CurMode_g) ==> FALSE
      (31) if (rw_INTV10bit_min_g > (unsigned)((((ras_ASIC_CtrReg_g)[0x14]).val << 2) + (((ras_ASIC_CtrReg_g)[0x15]).val >> 6))) ==> FALSE
      (32) if ((unsigned)((((ras_ASIC_CtrReg_g)[0x14]).val << 2) + (((ras_ASIC_CtrReg_g)[0x15]).val >> 6)) > rw_INTV10bit_max_g) ==> FALSE
      (33) if (rw_REGV_min_g > (unsigned)(((ras_ASIC_CtrReg_g)[0xd]).val << 4) + (((ras_ASIC_CtrReg_g)[0xe]).val >> 4)) ==> FALSE
      (34) if ((unsigned)(((ras_ASIC_CtrReg_g)[0xd]).val << 4) + (((ras_ASIC_CtrReg_g)[0xe]).val >> 4) > rw_REGV_max_g) ==> FALSE
      (35) if (rw_LIN_INTV10bit_min_g > (unsigned)((((ras_ASIC_CtrReg_g)[0x14]).val << 2) + (((ras_ASIC_CtrReg_g)[0x15]).val >> 6))) ==> TRUE
      (36) if ((unsigned)((((ras_ASIC_CtrReg_g)[0x14]).val << 2) + (((ras_ASIC_CtrReg_g)[0x15]).val >> 6)) > rw_LIN_INTV10bit_max_g) ==> FALSE
      (37) if (0x18 == j || 0x1a == j) ==> FALSE
      (39) if (0x10 == j) ==> FALSE
      (42) if (rb_SPI_error_l != 1 && rb_ASIC_SPI_ErrorFlag_g != 1) ==> FALSE
      (57) if (rb_ASIC_SPI_ErrorFlag_g == 0) ==> FALSE
      (58) if (51 == rb_ASIC_ControlMode_g) ==> FALSE
      (60) while ((vc_SE0 & 0x1) == 0) ==> FALSE
      (61) if (rw_SPINoCommCounter_g < (0xff00)) ==> FALSE
      (62) if (rw_SPINoCommCounter_g >= (0xff00)) ==> FALSE
      (63) if (rb_StaticNoCommunicationCounter_g < 255) ==> FALSE
      (64) if (1 == rb_firstReadComm_g) ==> FALSE
      (66) if (vc_SSR00_bit.no6 == 0) ==> FALSE
   Test Case Generation Notes:
      Cannot set variable to unknown value in branch 5
      Cannot set rab_SPI_RcvCmd_l due to assignment
      Conflict: Unable to validate expression-to-expression comparison in branch 9
      Cannot set variable to unknown value in branch 19
      Cannot set rb_idx_cksum_l due to assignment
      Cannot set variable to unknown value in branch 23
      Cannot set rb_idx_cksum_l due to assignment
      Cannot set local variable rb_SPI_error_l in branch 24
      Cannot set local variable rb_idx_Max_l in branch 25
      Cannot set variable to unknown value in branch 26
      Conflict: Multiple equality operators with different values (G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]) in branches 10/18
      Conflict: Multiple equality operators with different values (G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]) in branches 10/27
      Cannot set j due to assignment
      Cannot set j due to assignment
      Cannot set j due to assignment
      Cannot set local variable rb_SPI_error_l in branch 42
      Conflict: Multiple equality operators with different values (G5_spi_sr.<<GLOBAL>>.rb_ASIC_SPI_ErrorFlag_g) in branches 24/42
      Conflict: Trying to set variable G5_spi_sr.<<GLOBAL>>.rb_ASIC_SPI_ErrorFlag_g 'equal to' and 'not equal to' same value in branches 24/57
      Conflict: Trying to set variable G5_spi_sr.<<GLOBAL>>.rw_SPINoCommCounter_g 'less than' and 'greater than' same value in branches 61/62
TEST.END_NOTES:
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no5:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no6:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SE0:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_SPINoCommCounter_g:<<MAX>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_StaticNoCommunicationCounter_g:<<MAX>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]:128
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_bytes_to_send_mg:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_firstReadComm_g:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_ASIC_SPI_ErrorFlag_g:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_CurMode_g:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_INTV10bit_min_g:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_INTV10bit_max_g:<<MAX>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_REGV_min_g:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_REGV_max_g:<<MAX>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_LIN_INTV10bit_min_g:<<MAX>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_LIN_INTV10bit_max_g:<<MAX>>
TEST.END

-- Test Case: BASIS-PATH-050-PARTIAL
TEST.UNIT:G5_spi_sr
TEST.SUBPROGRAM:SPI_int
TEST.NEW
TEST.NAME:BASIS-PATH-050-PARTIAL
TEST.COMPOUND_ONLY
TEST.BASIS_PATH:50 of 67
TEST.NOTES:
This is an automatically generated test case.
   Test Path 50
      (1) while (vc_SSR00_bit.no6 == 1 && vc_SSR00_bit.no5 == 1) ==> FALSE
      (2) if (rb_SPI_WBPosition_mg < rb_SPI_bytes_to_send_mg) ==> FALSE
      (5) if (rab_SPI_RcvCmd_l == ((rab_SPI_WriteBuffer_mg)[0] & 0xfe)) ==> TRUE
      (6) if ((rab_SPI_RcvCmd_l & 0xf0) == 0xd0) ==> FALSE
      (8) if ((((rab_SPI_WriteBuffer_mg)[0] & 0xc0) == 0x40 || ((rab_SPI_WriteBuffer_mg)[0] & 0xc0) == 0x80) || ((rab_SPI_WriteBuffer_mg)[0] & 0xf8) == 0x10) ==> TRUE
      (9) for (rb_i_bytes_rcv_l < rb_SPI_bytes_to_send_mg - 1) ==> TRUE
      (10) if ((rb_SPI_WrCmdByte_l & 0xc0) != 0x80) ==> FALSE
      (17) if ((rb_SPI_WrCmdByte_l & 0x80) == 0x80) ==> TRUE
      (18) if ((rab_SPI_WriteBuffer_mg)[rb_idx_cksum_l] & 0x1) ==> FALSE
      (19) if ((rw_ChksumCalc_l & (0xff)) != (rab_SPI_ReadBuffer_mg)[rb_idx_cksum_l] && (rw_ChksumCalc_l + (0x55) & (0xff)) != (rab_SPI_ReadBuffer_mg)[rb_idx_cksum_l]) ==> FALSE
      (23) if ((rw_ChksumCalc_l + (0x55) & (0xff)) == (rab_SPI_ReadBuffer_mg)[rb_idx_cksum_l]) ==> FALSE
      (24) if (0 == rb_SPI_error_l && 0 == rb_ASIC_SPI_ErrorFlag_g) ==> TRUE
      (25) for (j < rb_idx_Max_l) ==> TRUE
      (26) if (((ras_ASIC_CtrReg_g)[j]).addr == (rb_SPI_WrCmdByte_l >> 1 & 0x1f)) ==> TRUE
      (27) if (1 == (rb_SPI_WrCmdByte_l & 0x1)) ==> TRUE
      (28) if (0x14 == j || 0x15 == j) ==> TRUE
      (29) if ((((ras_ASIC_CtrReg_g)[0x15]).val & 0x1) == 1) ==> FALSE
      (30) if (5 == rb_CurMode_g) ==> FALSE
      (31) if (rw_INTV10bit_min_g > (unsigned)((((ras_ASIC_CtrReg_g)[0x14]).val << 2) + (((ras_ASIC_CtrReg_g)[0x15]).val >> 6))) ==> FALSE
      (32) if ((unsigned)((((ras_ASIC_CtrReg_g)[0x14]).val << 2) + (((ras_ASIC_CtrReg_g)[0x15]).val >> 6)) > rw_INTV10bit_max_g) ==> FALSE
      (33) if (rw_REGV_min_g > (unsigned)(((ras_ASIC_CtrReg_g)[0xd]).val << 4) + (((ras_ASIC_CtrReg_g)[0xe]).val >> 4)) ==> FALSE
      (34) if ((unsigned)(((ras_ASIC_CtrReg_g)[0xd]).val << 4) + (((ras_ASIC_CtrReg_g)[0xe]).val >> 4) > rw_REGV_max_g) ==> TRUE
      (35) if (rw_LIN_INTV10bit_min_g > (unsigned)((((ras_ASIC_CtrReg_g)[0x14]).val << 2) + (((ras_ASIC_CtrReg_g)[0x15]).val >> 6))) ==> FALSE
      (36) if ((unsigned)((((ras_ASIC_CtrReg_g)[0x14]).val << 2) + (((ras_ASIC_CtrReg_g)[0x15]).val >> 6)) > rw_LIN_INTV10bit_max_g) ==> FALSE
      (37) if (0x18 == j || 0x1a == j) ==> FALSE
      (39) if (0x10 == j) ==> FALSE
      (42) if (rb_SPI_error_l != 1 && rb_ASIC_SPI_ErrorFlag_g != 1) ==> FALSE
      (57) if (rb_ASIC_SPI_ErrorFlag_g == 0) ==> FALSE
      (58) if (51 == rb_ASIC_ControlMode_g) ==> FALSE
      (60) while ((vc_SE0 & 0x1) == 0) ==> FALSE
      (61) if (rw_SPINoCommCounter_g < (0xff00)) ==> FALSE
      (62) if (rw_SPINoCommCounter_g >= (0xff00)) ==> FALSE
      (63) if (rb_StaticNoCommunicationCounter_g < 255) ==> FALSE
      (64) if (1 == rb_firstReadComm_g) ==> FALSE
      (66) if (vc_SSR00_bit.no6 == 0) ==> FALSE
   Test Case Generation Notes:
      Cannot set variable to unknown value in branch 5
      Cannot set rab_SPI_RcvCmd_l due to assignment
      Conflict: Unable to validate expression-to-expression comparison in branch 9
      Cannot set variable to unknown value in branch 19
      Cannot set rb_idx_cksum_l due to assignment
      Cannot set variable to unknown value in branch 23
      Cannot set rb_idx_cksum_l due to assignment
      Cannot set local variable rb_SPI_error_l in branch 24
      Cannot set local variable rb_idx_Max_l in branch 25
      Cannot set variable to unknown value in branch 26
      Conflict: Multiple equality operators with different values (G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]) in branches 10/18
      Conflict: Multiple equality operators with different values (G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]) in branches 10/27
      Cannot set j due to assignment
      Cannot set j due to assignment
      Cannot set j due to assignment
      Cannot set local variable rb_SPI_error_l in branch 42
      Conflict: Multiple equality operators with different values (G5_spi_sr.<<GLOBAL>>.rb_ASIC_SPI_ErrorFlag_g) in branches 24/42
      Conflict: Trying to set variable G5_spi_sr.<<GLOBAL>>.rb_ASIC_SPI_ErrorFlag_g 'equal to' and 'not equal to' same value in branches 24/57
      Conflict: Trying to set variable G5_spi_sr.<<GLOBAL>>.rw_SPINoCommCounter_g 'less than' and 'greater than' same value in branches 61/62
TEST.END_NOTES:
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no5:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no6:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SE0:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_SPINoCommCounter_g:<<MAX>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_StaticNoCommunicationCounter_g:<<MAX>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]:128
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_bytes_to_send_mg:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_firstReadComm_g:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_ASIC_SPI_ErrorFlag_g:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_CurMode_g:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_INTV10bit_min_g:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_INTV10bit_max_g:<<MAX>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_REGV_min_g:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_REGV_max_g:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_LIN_INTV10bit_min_g:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_LIN_INTV10bit_max_g:<<MAX>>
TEST.END

-- Test Case: BASIS-PATH-051-PARTIAL
TEST.UNIT:G5_spi_sr
TEST.SUBPROGRAM:SPI_int
TEST.NEW
TEST.NAME:BASIS-PATH-051-PARTIAL
TEST.COMPOUND_ONLY
TEST.BASIS_PATH:51 of 67
TEST.NOTES:
This is an automatically generated test case.
   Test Path 51
      (1) while (vc_SSR00_bit.no6 == 1 && vc_SSR00_bit.no5 == 1) ==> FALSE
      (2) if (rb_SPI_WBPosition_mg < rb_SPI_bytes_to_send_mg) ==> FALSE
      (5) if (rab_SPI_RcvCmd_l == ((rab_SPI_WriteBuffer_mg)[0] & 0xfe)) ==> TRUE
      (6) if ((rab_SPI_RcvCmd_l & 0xf0) == 0xd0) ==> FALSE
      (8) if ((((rab_SPI_WriteBuffer_mg)[0] & 0xc0) == 0x40 || ((rab_SPI_WriteBuffer_mg)[0] & 0xc0) == 0x80) || ((rab_SPI_WriteBuffer_mg)[0] & 0xf8) == 0x10) ==> TRUE
      (9) for (rb_i_bytes_rcv_l < rb_SPI_bytes_to_send_mg - 1) ==> TRUE
      (10) if ((rb_SPI_WrCmdByte_l & 0xc0) != 0x80) ==> FALSE
      (17) if ((rb_SPI_WrCmdByte_l & 0x80) == 0x80) ==> TRUE
      (18) if ((rab_SPI_WriteBuffer_mg)[rb_idx_cksum_l] & 0x1) ==> FALSE
      (19) if ((rw_ChksumCalc_l & (0xff)) != (rab_SPI_ReadBuffer_mg)[rb_idx_cksum_l] && (rw_ChksumCalc_l + (0x55) & (0xff)) != (rab_SPI_ReadBuffer_mg)[rb_idx_cksum_l]) ==> FALSE
      (23) if ((rw_ChksumCalc_l + (0x55) & (0xff)) == (rab_SPI_ReadBuffer_mg)[rb_idx_cksum_l]) ==> FALSE
      (24) if (0 == rb_SPI_error_l && 0 == rb_ASIC_SPI_ErrorFlag_g) ==> TRUE
      (25) for (j < rb_idx_Max_l) ==> TRUE
      (26) if (((ras_ASIC_CtrReg_g)[j]).addr == (rb_SPI_WrCmdByte_l >> 1 & 0x1f)) ==> TRUE
      (27) if (1 == (rb_SPI_WrCmdByte_l & 0x1)) ==> TRUE
      (28) if (0x14 == j || 0x15 == j) ==> TRUE
      (29) if ((((ras_ASIC_CtrReg_g)[0x15]).val & 0x1) == 1) ==> FALSE
      (30) if (5 == rb_CurMode_g) ==> FALSE
      (31) if (rw_INTV10bit_min_g > (unsigned)((((ras_ASIC_CtrReg_g)[0x14]).val << 2) + (((ras_ASIC_CtrReg_g)[0x15]).val >> 6))) ==> FALSE
      (32) if ((unsigned)((((ras_ASIC_CtrReg_g)[0x14]).val << 2) + (((ras_ASIC_CtrReg_g)[0x15]).val >> 6)) > rw_INTV10bit_max_g) ==> FALSE
      (33) if (rw_REGV_min_g > (unsigned)(((ras_ASIC_CtrReg_g)[0xd]).val << 4) + (((ras_ASIC_CtrReg_g)[0xe]).val >> 4)) ==> TRUE
      (34) if ((unsigned)(((ras_ASIC_CtrReg_g)[0xd]).val << 4) + (((ras_ASIC_CtrReg_g)[0xe]).val >> 4) > rw_REGV_max_g) ==> FALSE
      (35) if (rw_LIN_INTV10bit_min_g > (unsigned)((((ras_ASIC_CtrReg_g)[0x14]).val << 2) + (((ras_ASIC_CtrReg_g)[0x15]).val >> 6))) ==> FALSE
      (36) if ((unsigned)((((ras_ASIC_CtrReg_g)[0x14]).val << 2) + (((ras_ASIC_CtrReg_g)[0x15]).val >> 6)) > rw_LIN_INTV10bit_max_g) ==> FALSE
      (37) if (0x18 == j || 0x1a == j) ==> FALSE
      (39) if (0x10 == j) ==> FALSE
      (42) if (rb_SPI_error_l != 1 && rb_ASIC_SPI_ErrorFlag_g != 1) ==> FALSE
      (57) if (rb_ASIC_SPI_ErrorFlag_g == 0) ==> FALSE
      (58) if (51 == rb_ASIC_ControlMode_g) ==> FALSE
      (60) while ((vc_SE0 & 0x1) == 0) ==> FALSE
      (61) if (rw_SPINoCommCounter_g < (0xff00)) ==> FALSE
      (62) if (rw_SPINoCommCounter_g >= (0xff00)) ==> FALSE
      (63) if (rb_StaticNoCommunicationCounter_g < 255) ==> FALSE
      (64) if (1 == rb_firstReadComm_g) ==> FALSE
      (66) if (vc_SSR00_bit.no6 == 0) ==> FALSE
   Test Case Generation Notes:
      Cannot set variable to unknown value in branch 5
      Cannot set rab_SPI_RcvCmd_l due to assignment
      Conflict: Unable to validate expression-to-expression comparison in branch 9
      Cannot set variable to unknown value in branch 19
      Cannot set rb_idx_cksum_l due to assignment
      Cannot set variable to unknown value in branch 23
      Cannot set rb_idx_cksum_l due to assignment
      Cannot set local variable rb_SPI_error_l in branch 24
      Cannot set local variable rb_idx_Max_l in branch 25
      Cannot set variable to unknown value in branch 26
      Conflict: Multiple equality operators with different values (G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]) in branches 10/18
      Conflict: Multiple equality operators with different values (G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]) in branches 10/27
      Cannot set j due to assignment
      Cannot set j due to assignment
      Cannot set j due to assignment
      Cannot set local variable rb_SPI_error_l in branch 42
      Conflict: Multiple equality operators with different values (G5_spi_sr.<<GLOBAL>>.rb_ASIC_SPI_ErrorFlag_g) in branches 24/42
      Conflict: Trying to set variable G5_spi_sr.<<GLOBAL>>.rb_ASIC_SPI_ErrorFlag_g 'equal to' and 'not equal to' same value in branches 24/57
      Conflict: Trying to set variable G5_spi_sr.<<GLOBAL>>.rw_SPINoCommCounter_g 'less than' and 'greater than' same value in branches 61/62
TEST.END_NOTES:
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no5:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no6:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SE0:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_SPINoCommCounter_g:<<MAX>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_StaticNoCommunicationCounter_g:<<MAX>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]:128
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_bytes_to_send_mg:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_firstReadComm_g:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_ASIC_SPI_ErrorFlag_g:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_CurMode_g:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_INTV10bit_min_g:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_INTV10bit_max_g:<<MAX>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_REGV_min_g:<<MAX>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_REGV_max_g:<<MAX>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_LIN_INTV10bit_min_g:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_LIN_INTV10bit_max_g:<<MAX>>
TEST.END

-- Test Case: BASIS-PATH-052-PARTIAL
TEST.UNIT:G5_spi_sr
TEST.SUBPROGRAM:SPI_int
TEST.NEW
TEST.NAME:BASIS-PATH-052-PARTIAL
TEST.COMPOUND_ONLY
TEST.BASIS_PATH:52 of 67
TEST.NOTES:
This is an automatically generated test case.
   Test Path 52
      (1) while (vc_SSR00_bit.no6 == 1 && vc_SSR00_bit.no5 == 1) ==> FALSE
      (2) if (rb_SPI_WBPosition_mg < rb_SPI_bytes_to_send_mg) ==> FALSE
      (5) if (rab_SPI_RcvCmd_l == ((rab_SPI_WriteBuffer_mg)[0] & 0xfe)) ==> TRUE
      (6) if ((rab_SPI_RcvCmd_l & 0xf0) == 0xd0) ==> FALSE
      (8) if ((((rab_SPI_WriteBuffer_mg)[0] & 0xc0) == 0x40 || ((rab_SPI_WriteBuffer_mg)[0] & 0xc0) == 0x80) || ((rab_SPI_WriteBuffer_mg)[0] & 0xf8) == 0x10) ==> TRUE
      (9) for (rb_i_bytes_rcv_l < rb_SPI_bytes_to_send_mg - 1) ==> TRUE
      (10) if ((rb_SPI_WrCmdByte_l & 0xc0) != 0x80) ==> FALSE
      (17) if ((rb_SPI_WrCmdByte_l & 0x80) == 0x80) ==> TRUE
      (18) if ((rab_SPI_WriteBuffer_mg)[rb_idx_cksum_l] & 0x1) ==> FALSE
      (19) if ((rw_ChksumCalc_l & (0xff)) != (rab_SPI_ReadBuffer_mg)[rb_idx_cksum_l] && (rw_ChksumCalc_l + (0x55) & (0xff)) != (rab_SPI_ReadBuffer_mg)[rb_idx_cksum_l]) ==> FALSE
      (23) if ((rw_ChksumCalc_l + (0x55) & (0xff)) == (rab_SPI_ReadBuffer_mg)[rb_idx_cksum_l]) ==> FALSE
      (24) if (0 == rb_SPI_error_l && 0 == rb_ASIC_SPI_ErrorFlag_g) ==> TRUE
      (25) for (j < rb_idx_Max_l) ==> TRUE
      (26) if (((ras_ASIC_CtrReg_g)[j]).addr == (rb_SPI_WrCmdByte_l >> 1 & 0x1f)) ==> TRUE
      (27) if (1 == (rb_SPI_WrCmdByte_l & 0x1)) ==> TRUE
      (28) if (0x14 == j || 0x15 == j) ==> TRUE
      (29) if ((((ras_ASIC_CtrReg_g)[0x15]).val & 0x1) == 1) ==> FALSE
      (30) if (5 == rb_CurMode_g) ==> FALSE
      (31) if (rw_INTV10bit_min_g > (unsigned)((((ras_ASIC_CtrReg_g)[0x14]).val << 2) + (((ras_ASIC_CtrReg_g)[0x15]).val >> 6))) ==> FALSE
      (32) if ((unsigned)((((ras_ASIC_CtrReg_g)[0x14]).val << 2) + (((ras_ASIC_CtrReg_g)[0x15]).val >> 6)) > rw_INTV10bit_max_g) ==> TRUE
      (33) if (rw_REGV_min_g > (unsigned)(((ras_ASIC_CtrReg_g)[0xd]).val << 4) + (((ras_ASIC_CtrReg_g)[0xe]).val >> 4)) ==> FALSE
      (34) if ((unsigned)(((ras_ASIC_CtrReg_g)[0xd]).val << 4) + (((ras_ASIC_CtrReg_g)[0xe]).val >> 4) > rw_REGV_max_g) ==> FALSE
      (35) if (rw_LIN_INTV10bit_min_g > (unsigned)((((ras_ASIC_CtrReg_g)[0x14]).val << 2) + (((ras_ASIC_CtrReg_g)[0x15]).val >> 6))) ==> FALSE
      (36) if ((unsigned)((((ras_ASIC_CtrReg_g)[0x14]).val << 2) + (((ras_ASIC_CtrReg_g)[0x15]).val >> 6)) > rw_LIN_INTV10bit_max_g) ==> FALSE
      (37) if (0x18 == j || 0x1a == j) ==> FALSE
      (39) if (0x10 == j) ==> FALSE
      (42) if (rb_SPI_error_l != 1 && rb_ASIC_SPI_ErrorFlag_g != 1) ==> FALSE
      (57) if (rb_ASIC_SPI_ErrorFlag_g == 0) ==> FALSE
      (58) if (51 == rb_ASIC_ControlMode_g) ==> FALSE
      (60) while ((vc_SE0 & 0x1) == 0) ==> FALSE
      (61) if (rw_SPINoCommCounter_g < (0xff00)) ==> FALSE
      (62) if (rw_SPINoCommCounter_g >= (0xff00)) ==> FALSE
      (63) if (rb_StaticNoCommunicationCounter_g < 255) ==> FALSE
      (64) if (1 == rb_firstReadComm_g) ==> FALSE
      (66) if (vc_SSR00_bit.no6 == 0) ==> FALSE
   Test Case Generation Notes:
      Cannot set variable to unknown value in branch 5
      Cannot set rab_SPI_RcvCmd_l due to assignment
      Conflict: Unable to validate expression-to-expression comparison in branch 9
      Cannot set variable to unknown value in branch 19
      Cannot set rb_idx_cksum_l due to assignment
      Cannot set variable to unknown value in branch 23
      Cannot set rb_idx_cksum_l due to assignment
      Cannot set local variable rb_SPI_error_l in branch 24
      Cannot set local variable rb_idx_Max_l in branch 25
      Cannot set variable to unknown value in branch 26
      Conflict: Multiple equality operators with different values (G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]) in branches 10/18
      Conflict: Multiple equality operators with different values (G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]) in branches 10/27
      Cannot set j due to assignment
      Cannot set j due to assignment
      Cannot set j due to assignment
      Cannot set local variable rb_SPI_error_l in branch 42
      Conflict: Multiple equality operators with different values (G5_spi_sr.<<GLOBAL>>.rb_ASIC_SPI_ErrorFlag_g) in branches 24/42
      Conflict: Trying to set variable G5_spi_sr.<<GLOBAL>>.rb_ASIC_SPI_ErrorFlag_g 'equal to' and 'not equal to' same value in branches 24/57
      Conflict: Trying to set variable G5_spi_sr.<<GLOBAL>>.rw_SPINoCommCounter_g 'less than' and 'greater than' same value in branches 61/62
TEST.END_NOTES:
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no5:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no6:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SE0:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_SPINoCommCounter_g:<<MAX>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_StaticNoCommunicationCounter_g:<<MAX>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]:128
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_bytes_to_send_mg:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_firstReadComm_g:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_ASIC_SPI_ErrorFlag_g:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_CurMode_g:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_INTV10bit_min_g:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_INTV10bit_max_g:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_REGV_min_g:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_REGV_max_g:<<MAX>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_LIN_INTV10bit_min_g:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_LIN_INTV10bit_max_g:<<MAX>>
TEST.END

-- Test Case: BASIS-PATH-053-PARTIAL
TEST.UNIT:G5_spi_sr
TEST.SUBPROGRAM:SPI_int
TEST.NEW
TEST.NAME:BASIS-PATH-053-PARTIAL
TEST.COMPOUND_ONLY
TEST.BASIS_PATH:53 of 67
TEST.NOTES:
This is an automatically generated test case.
   Test Path 53
      (1) while (vc_SSR00_bit.no6 == 1 && vc_SSR00_bit.no5 == 1) ==> FALSE
      (2) if (rb_SPI_WBPosition_mg < rb_SPI_bytes_to_send_mg) ==> FALSE
      (5) if (rab_SPI_RcvCmd_l == ((rab_SPI_WriteBuffer_mg)[0] & 0xfe)) ==> TRUE
      (6) if ((rab_SPI_RcvCmd_l & 0xf0) == 0xd0) ==> FALSE
      (8) if ((((rab_SPI_WriteBuffer_mg)[0] & 0xc0) == 0x40 || ((rab_SPI_WriteBuffer_mg)[0] & 0xc0) == 0x80) || ((rab_SPI_WriteBuffer_mg)[0] & 0xf8) == 0x10) ==> TRUE
      (9) for (rb_i_bytes_rcv_l < rb_SPI_bytes_to_send_mg - 1) ==> TRUE
      (10) if ((rb_SPI_WrCmdByte_l & 0xc0) != 0x80) ==> FALSE
      (17) if ((rb_SPI_WrCmdByte_l & 0x80) == 0x80) ==> TRUE
      (18) if ((rab_SPI_WriteBuffer_mg)[rb_idx_cksum_l] & 0x1) ==> FALSE
      (19) if ((rw_ChksumCalc_l & (0xff)) != (rab_SPI_ReadBuffer_mg)[rb_idx_cksum_l] && (rw_ChksumCalc_l + (0x55) & (0xff)) != (rab_SPI_ReadBuffer_mg)[rb_idx_cksum_l]) ==> FALSE
      (23) if ((rw_ChksumCalc_l + (0x55) & (0xff)) == (rab_SPI_ReadBuffer_mg)[rb_idx_cksum_l]) ==> FALSE
      (24) if (0 == rb_SPI_error_l && 0 == rb_ASIC_SPI_ErrorFlag_g) ==> TRUE
      (25) for (j < rb_idx_Max_l) ==> TRUE
      (26) if (((ras_ASIC_CtrReg_g)[j]).addr == (rb_SPI_WrCmdByte_l >> 1 & 0x1f)) ==> TRUE
      (27) if (1 == (rb_SPI_WrCmdByte_l & 0x1)) ==> TRUE
      (28) if (0x14 == j || 0x15 == j) ==> TRUE
      (29) if ((((ras_ASIC_CtrReg_g)[0x15]).val & 0x1) == 1) ==> FALSE
      (30) if (5 == rb_CurMode_g) ==> FALSE
      (31) if (rw_INTV10bit_min_g > (unsigned)((((ras_ASIC_CtrReg_g)[0x14]).val << 2) + (((ras_ASIC_CtrReg_g)[0x15]).val >> 6))) ==> TRUE
      (32) if ((unsigned)((((ras_ASIC_CtrReg_g)[0x14]).val << 2) + (((ras_ASIC_CtrReg_g)[0x15]).val >> 6)) > rw_INTV10bit_max_g) ==> FALSE
      (33) if (rw_REGV_min_g > (unsigned)(((ras_ASIC_CtrReg_g)[0xd]).val << 4) + (((ras_ASIC_CtrReg_g)[0xe]).val >> 4)) ==> FALSE
      (34) if ((unsigned)(((ras_ASIC_CtrReg_g)[0xd]).val << 4) + (((ras_ASIC_CtrReg_g)[0xe]).val >> 4) > rw_REGV_max_g) ==> FALSE
      (35) if (rw_LIN_INTV10bit_min_g > (unsigned)((((ras_ASIC_CtrReg_g)[0x14]).val << 2) + (((ras_ASIC_CtrReg_g)[0x15]).val >> 6))) ==> FALSE
      (36) if ((unsigned)((((ras_ASIC_CtrReg_g)[0x14]).val << 2) + (((ras_ASIC_CtrReg_g)[0x15]).val >> 6)) > rw_LIN_INTV10bit_max_g) ==> FALSE
      (37) if (0x18 == j || 0x1a == j) ==> FALSE
      (39) if (0x10 == j) ==> FALSE
      (42) if (rb_SPI_error_l != 1 && rb_ASIC_SPI_ErrorFlag_g != 1) ==> FALSE
      (57) if (rb_ASIC_SPI_ErrorFlag_g == 0) ==> FALSE
      (58) if (51 == rb_ASIC_ControlMode_g) ==> FALSE
      (60) while ((vc_SE0 & 0x1) == 0) ==> FALSE
      (61) if (rw_SPINoCommCounter_g < (0xff00)) ==> FALSE
      (62) if (rw_SPINoCommCounter_g >= (0xff00)) ==> FALSE
      (63) if (rb_StaticNoCommunicationCounter_g < 255) ==> FALSE
      (64) if (1 == rb_firstReadComm_g) ==> FALSE
      (66) if (vc_SSR00_bit.no6 == 0) ==> FALSE
   Test Case Generation Notes:
      Cannot set variable to unknown value in branch 5
      Cannot set rab_SPI_RcvCmd_l due to assignment
      Conflict: Unable to validate expression-to-expression comparison in branch 9
      Cannot set variable to unknown value in branch 19
      Cannot set rb_idx_cksum_l due to assignment
      Cannot set variable to unknown value in branch 23
      Cannot set rb_idx_cksum_l due to assignment
      Cannot set local variable rb_SPI_error_l in branch 24
      Cannot set local variable rb_idx_Max_l in branch 25
      Cannot set variable to unknown value in branch 26
      Conflict: Multiple equality operators with different values (G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]) in branches 10/18
      Conflict: Multiple equality operators with different values (G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]) in branches 10/27
      Cannot set j due to assignment
      Cannot set j due to assignment
      Cannot set j due to assignment
      Cannot set local variable rb_SPI_error_l in branch 42
      Conflict: Multiple equality operators with different values (G5_spi_sr.<<GLOBAL>>.rb_ASIC_SPI_ErrorFlag_g) in branches 24/42
      Conflict: Trying to set variable G5_spi_sr.<<GLOBAL>>.rb_ASIC_SPI_ErrorFlag_g 'equal to' and 'not equal to' same value in branches 24/57
      Conflict: Trying to set variable G5_spi_sr.<<GLOBAL>>.rw_SPINoCommCounter_g 'less than' and 'greater than' same value in branches 61/62
TEST.END_NOTES:
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no5:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no6:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SE0:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_SPINoCommCounter_g:<<MAX>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_StaticNoCommunicationCounter_g:<<MAX>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]:128
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_bytes_to_send_mg:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_firstReadComm_g:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_ASIC_SPI_ErrorFlag_g:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_CurMode_g:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_INTV10bit_min_g:<<MAX>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_INTV10bit_max_g:<<MAX>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_REGV_min_g:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_REGV_max_g:<<MAX>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_LIN_INTV10bit_min_g:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_LIN_INTV10bit_max_g:<<MAX>>
TEST.END

-- Test Case: BASIS-PATH-054-PARTIAL
TEST.UNIT:G5_spi_sr
TEST.SUBPROGRAM:SPI_int
TEST.NEW
TEST.NAME:BASIS-PATH-054-PARTIAL
TEST.COMPOUND_ONLY
TEST.BASIS_PATH:54 of 67
TEST.NOTES:
This is an automatically generated test case.
   Test Path 54
      (1) while (vc_SSR00_bit.no6 == 1 && vc_SSR00_bit.no5 == 1) ==> FALSE
      (2) if (rb_SPI_WBPosition_mg < rb_SPI_bytes_to_send_mg) ==> FALSE
      (5) if (rab_SPI_RcvCmd_l == ((rab_SPI_WriteBuffer_mg)[0] & 0xfe)) ==> TRUE
      (6) if ((rab_SPI_RcvCmd_l & 0xf0) == 0xd0) ==> FALSE
      (8) if ((((rab_SPI_WriteBuffer_mg)[0] & 0xc0) == 0x40 || ((rab_SPI_WriteBuffer_mg)[0] & 0xc0) == 0x80) || ((rab_SPI_WriteBuffer_mg)[0] & 0xf8) == 0x10) ==> TRUE
      (9) for (rb_i_bytes_rcv_l < rb_SPI_bytes_to_send_mg - 1) ==> TRUE
      (10) if ((rb_SPI_WrCmdByte_l & 0xc0) != 0x80) ==> FALSE
      (17) if ((rb_SPI_WrCmdByte_l & 0x80) == 0x80) ==> TRUE
      (18) if ((rab_SPI_WriteBuffer_mg)[rb_idx_cksum_l] & 0x1) ==> FALSE
      (19) if ((rw_ChksumCalc_l & (0xff)) != (rab_SPI_ReadBuffer_mg)[rb_idx_cksum_l] && (rw_ChksumCalc_l + (0x55) & (0xff)) != (rab_SPI_ReadBuffer_mg)[rb_idx_cksum_l]) ==> FALSE
      (23) if ((rw_ChksumCalc_l + (0x55) & (0xff)) == (rab_SPI_ReadBuffer_mg)[rb_idx_cksum_l]) ==> FALSE
      (24) if (0 == rb_SPI_error_l && 0 == rb_ASIC_SPI_ErrorFlag_g) ==> TRUE
      (25) for (j < rb_idx_Max_l) ==> TRUE
      (26) if (((ras_ASIC_CtrReg_g)[j]).addr == (rb_SPI_WrCmdByte_l >> 1 & 0x1f)) ==> TRUE
      (27) if (1 == (rb_SPI_WrCmdByte_l & 0x1)) ==> TRUE
      (28) if (0x14 == j || 0x15 == j) ==> TRUE
      (29) if ((((ras_ASIC_CtrReg_g)[0x15]).val & 0x1) == 1) ==> FALSE
      (30) if (5 == rb_CurMode_g) ==> TRUE
      (31) if (rw_INTV10bit_min_g > (unsigned)((((ras_ASIC_CtrReg_g)[0x14]).val << 2) + (((ras_ASIC_CtrReg_g)[0x15]).val >> 6))) ==> FALSE
      (32) if ((unsigned)((((ras_ASIC_CtrReg_g)[0x14]).val << 2) + (((ras_ASIC_CtrReg_g)[0x15]).val >> 6)) > rw_INTV10bit_max_g) ==> FALSE
      (33) if (rw_REGV_min_g > (unsigned)(((ras_ASIC_CtrReg_g)[0xd]).val << 4) + (((ras_ASIC_CtrReg_g)[0xe]).val >> 4)) ==> FALSE
      (34) if ((unsigned)(((ras_ASIC_CtrReg_g)[0xd]).val << 4) + (((ras_ASIC_CtrReg_g)[0xe]).val >> 4) > rw_REGV_max_g) ==> FALSE
      (35) if (rw_LIN_INTV10bit_min_g > (unsigned)((((ras_ASIC_CtrReg_g)[0x14]).val << 2) + (((ras_ASIC_CtrReg_g)[0x15]).val >> 6))) ==> FALSE
      (36) if ((unsigned)((((ras_ASIC_CtrReg_g)[0x14]).val << 2) + (((ras_ASIC_CtrReg_g)[0x15]).val >> 6)) > rw_LIN_INTV10bit_max_g) ==> FALSE
      (37) if (0x18 == j || 0x1a == j) ==> FALSE
      (39) if (0x10 == j) ==> FALSE
      (42) if (rb_SPI_error_l != 1 && rb_ASIC_SPI_ErrorFlag_g != 1) ==> FALSE
      (57) if (rb_ASIC_SPI_ErrorFlag_g == 0) ==> FALSE
      (58) if (51 == rb_ASIC_ControlMode_g) ==> FALSE
      (60) while ((vc_SE0 & 0x1) == 0) ==> FALSE
      (61) if (rw_SPINoCommCounter_g < (0xff00)) ==> FALSE
      (62) if (rw_SPINoCommCounter_g >= (0xff00)) ==> FALSE
      (63) if (rb_StaticNoCommunicationCounter_g < 255) ==> FALSE
      (64) if (1 == rb_firstReadComm_g) ==> FALSE
      (66) if (vc_SSR00_bit.no6 == 0) ==> FALSE
   Test Case Generation Notes:
      Cannot set variable to unknown value in branch 5
      Cannot set rab_SPI_RcvCmd_l due to assignment
      Conflict: Unable to validate expression-to-expression comparison in branch 9
      Cannot set variable to unknown value in branch 19
      Cannot set rb_idx_cksum_l due to assignment
      Cannot set variable to unknown value in branch 23
      Cannot set rb_idx_cksum_l due to assignment
      Cannot set local variable rb_SPI_error_l in branch 24
      Cannot set local variable rb_idx_Max_l in branch 25
      Cannot set variable to unknown value in branch 26
      Conflict: Multiple equality operators with different values (G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]) in branches 10/18
      Conflict: Multiple equality operators with different values (G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]) in branches 10/27
      Cannot set j due to assignment
      Cannot set j due to assignment
      Cannot set j due to assignment
      Cannot set local variable rb_SPI_error_l in branch 42
      Conflict: Multiple equality operators with different values (G5_spi_sr.<<GLOBAL>>.rb_ASIC_SPI_ErrorFlag_g) in branches 24/42
      Conflict: Trying to set variable G5_spi_sr.<<GLOBAL>>.rb_ASIC_SPI_ErrorFlag_g 'equal to' and 'not equal to' same value in branches 24/57
      Conflict: Trying to set variable G5_spi_sr.<<GLOBAL>>.rw_SPINoCommCounter_g 'less than' and 'greater than' same value in branches 61/62
TEST.END_NOTES:
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no5:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no6:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SE0:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_SPINoCommCounter_g:<<MAX>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_StaticNoCommunicationCounter_g:<<MAX>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]:128
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_bytes_to_send_mg:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_firstReadComm_g:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_ASIC_SPI_ErrorFlag_g:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_CurMode_g:5
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_INTV10bit_min_g:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_INTV10bit_max_g:<<MAX>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_REGV_min_g:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_REGV_max_g:<<MAX>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_LIN_INTV10bit_min_g:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_LIN_INTV10bit_max_g:<<MAX>>
TEST.END

-- Test Case: BASIS-PATH-055-PARTIAL
TEST.UNIT:G5_spi_sr
TEST.SUBPROGRAM:SPI_int
TEST.NEW
TEST.NAME:BASIS-PATH-055-PARTIAL
TEST.COMPOUND_ONLY
TEST.BASIS_PATH:55 of 67
TEST.NOTES:
This is an automatically generated test case.
   Test Path 55
      (1) while (vc_SSR00_bit.no6 == 1 && vc_SSR00_bit.no5 == 1) ==> FALSE
      (2) if (rb_SPI_WBPosition_mg < rb_SPI_bytes_to_send_mg) ==> FALSE
      (5) if (rab_SPI_RcvCmd_l == ((rab_SPI_WriteBuffer_mg)[0] & 0xfe)) ==> TRUE
      (6) if ((rab_SPI_RcvCmd_l & 0xf0) == 0xd0) ==> FALSE
      (8) if ((((rab_SPI_WriteBuffer_mg)[0] & 0xc0) == 0x40 || ((rab_SPI_WriteBuffer_mg)[0] & 0xc0) == 0x80) || ((rab_SPI_WriteBuffer_mg)[0] & 0xf8) == 0x10) ==> TRUE
      (9) for (rb_i_bytes_rcv_l < rb_SPI_bytes_to_send_mg - 1) ==> TRUE
      (10) if ((rb_SPI_WrCmdByte_l & 0xc0) != 0x80) ==> FALSE
      (17) if ((rb_SPI_WrCmdByte_l & 0x80) == 0x80) ==> TRUE
      (18) if ((rab_SPI_WriteBuffer_mg)[rb_idx_cksum_l] & 0x1) ==> FALSE
      (19) if ((rw_ChksumCalc_l & (0xff)) != (rab_SPI_ReadBuffer_mg)[rb_idx_cksum_l] && (rw_ChksumCalc_l + (0x55) & (0xff)) != (rab_SPI_ReadBuffer_mg)[rb_idx_cksum_l]) ==> FALSE
      (23) if ((rw_ChksumCalc_l + (0x55) & (0xff)) == (rab_SPI_ReadBuffer_mg)[rb_idx_cksum_l]) ==> FALSE
      (24) if (0 == rb_SPI_error_l && 0 == rb_ASIC_SPI_ErrorFlag_g) ==> TRUE
      (25) for (j < rb_idx_Max_l) ==> TRUE
      (26) if (((ras_ASIC_CtrReg_g)[j]).addr == (rb_SPI_WrCmdByte_l >> 1 & 0x1f)) ==> TRUE
      (27) if (1 == (rb_SPI_WrCmdByte_l & 0x1)) ==> TRUE
      (28) if (0x14 == j || 0x15 == j) ==> TRUE
      (29) if ((((ras_ASIC_CtrReg_g)[0x15]).val & 0x1) == 1) ==> TRUE
      (31) if (rw_INTV10bit_min_g > (unsigned)((((ras_ASIC_CtrReg_g)[0x14]).val << 2) + (((ras_ASIC_CtrReg_g)[0x15]).val >> 6))) ==> FALSE
      (32) if ((unsigned)((((ras_ASIC_CtrReg_g)[0x14]).val << 2) + (((ras_ASIC_CtrReg_g)[0x15]).val >> 6)) > rw_INTV10bit_max_g) ==> FALSE
      (33) if (rw_REGV_min_g > (unsigned)(((ras_ASIC_CtrReg_g)[0xd]).val << 4) + (((ras_ASIC_CtrReg_g)[0xe]).val >> 4)) ==> FALSE
      (34) if ((unsigned)(((ras_ASIC_CtrReg_g)[0xd]).val << 4) + (((ras_ASIC_CtrReg_g)[0xe]).val >> 4) > rw_REGV_max_g) ==> FALSE
      (35) if (rw_LIN_INTV10bit_min_g > (unsigned)((((ras_ASIC_CtrReg_g)[0x14]).val << 2) + (((ras_ASIC_CtrReg_g)[0x15]).val >> 6))) ==> FALSE
      (36) if ((unsigned)((((ras_ASIC_CtrReg_g)[0x14]).val << 2) + (((ras_ASIC_CtrReg_g)[0x15]).val >> 6)) > rw_LIN_INTV10bit_max_g) ==> FALSE
      (37) if (0x18 == j || 0x1a == j) ==> FALSE
      (39) if (0x10 == j) ==> FALSE
      (42) if (rb_SPI_error_l != 1 && rb_ASIC_SPI_ErrorFlag_g != 1) ==> FALSE
      (57) if (rb_ASIC_SPI_ErrorFlag_g == 0) ==> FALSE
      (58) if (51 == rb_ASIC_ControlMode_g) ==> FALSE
      (60) while ((vc_SE0 & 0x1) == 0) ==> FALSE
      (61) if (rw_SPINoCommCounter_g < (0xff00)) ==> FALSE
      (62) if (rw_SPINoCommCounter_g >= (0xff00)) ==> FALSE
      (63) if (rb_StaticNoCommunicationCounter_g < 255) ==> FALSE
      (64) if (1 == rb_firstReadComm_g) ==> FALSE
      (66) if (vc_SSR00_bit.no6 == 0) ==> FALSE
   Test Case Generation Notes:
      Cannot set variable to unknown value in branch 5
      Cannot set rab_SPI_RcvCmd_l due to assignment
      Conflict: Unable to validate expression-to-expression comparison in branch 9
      Cannot set variable to unknown value in branch 19
      Cannot set rb_idx_cksum_l due to assignment
      Cannot set variable to unknown value in branch 23
      Cannot set rb_idx_cksum_l due to assignment
      Cannot set local variable rb_SPI_error_l in branch 24
      Cannot set local variable rb_idx_Max_l in branch 25
      Cannot set variable to unknown value in branch 26
      Conflict: Multiple equality operators with different values (G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]) in branches 10/18
      Conflict: Multiple equality operators with different values (G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]) in branches 10/27
      Cannot set j due to assignment
      Cannot set j due to assignment
      Cannot set j due to assignment
      Cannot set local variable rb_SPI_error_l in branch 42
      Conflict: Multiple equality operators with different values (G5_spi_sr.<<GLOBAL>>.rb_ASIC_SPI_ErrorFlag_g) in branches 24/42
      Conflict: Trying to set variable G5_spi_sr.<<GLOBAL>>.rb_ASIC_SPI_ErrorFlag_g 'equal to' and 'not equal to' same value in branches 24/57
      Conflict: Trying to set variable G5_spi_sr.<<GLOBAL>>.rw_SPINoCommCounter_g 'less than' and 'greater than' same value in branches 61/62
TEST.END_NOTES:
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no5:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no6:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SE0:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_SPINoCommCounter_g:<<MAX>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_StaticNoCommunicationCounter_g:<<MAX>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]:128
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_bytes_to_send_mg:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_firstReadComm_g:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_ASIC_SPI_ErrorFlag_g:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_INTV10bit_min_g:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_INTV10bit_max_g:<<MAX>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_REGV_min_g:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_REGV_max_g:<<MAX>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_LIN_INTV10bit_min_g:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_LIN_INTV10bit_max_g:<<MAX>>
TEST.END

-- Test Case: BASIS-PATH-056-PARTIAL
TEST.UNIT:G5_spi_sr
TEST.SUBPROGRAM:SPI_int
TEST.NEW
TEST.NAME:BASIS-PATH-056-PARTIAL
TEST.COMPOUND_ONLY
TEST.BASIS_PATH:56 of 67
TEST.NOTES:
This is an automatically generated test case.
   Test Path 56
      (1) while (vc_SSR00_bit.no6 == 1 && vc_SSR00_bit.no5 == 1) ==> FALSE
      (2) if (rb_SPI_WBPosition_mg < rb_SPI_bytes_to_send_mg) ==> FALSE
      (5) if (rab_SPI_RcvCmd_l == ((rab_SPI_WriteBuffer_mg)[0] & 0xfe)) ==> TRUE
      (6) if ((rab_SPI_RcvCmd_l & 0xf0) == 0xd0) ==> FALSE
      (8) if ((((rab_SPI_WriteBuffer_mg)[0] & 0xc0) == 0x40 || ((rab_SPI_WriteBuffer_mg)[0] & 0xc0) == 0x80) || ((rab_SPI_WriteBuffer_mg)[0] & 0xf8) == 0x10) ==> TRUE
      (9) for (rb_i_bytes_rcv_l < rb_SPI_bytes_to_send_mg - 1) ==> TRUE
      (10) if ((rb_SPI_WrCmdByte_l & 0xc0) != 0x80) ==> FALSE
      (17) if ((rb_SPI_WrCmdByte_l & 0x80) == 0x80) ==> TRUE
      (18) if ((rab_SPI_WriteBuffer_mg)[rb_idx_cksum_l] & 0x1) ==> FALSE
      (19) if ((rw_ChksumCalc_l & (0xff)) != (rab_SPI_ReadBuffer_mg)[rb_idx_cksum_l] && (rw_ChksumCalc_l + (0x55) & (0xff)) != (rab_SPI_ReadBuffer_mg)[rb_idx_cksum_l]) ==> FALSE
      (23) if ((rw_ChksumCalc_l + (0x55) & (0xff)) == (rab_SPI_ReadBuffer_mg)[rb_idx_cksum_l]) ==> FALSE
      (24) if (0 == rb_SPI_error_l && 0 == rb_ASIC_SPI_ErrorFlag_g) ==> TRUE
      (25) for (j < rb_idx_Max_l) ==> TRUE
      (26) if (((ras_ASIC_CtrReg_g)[j]).addr == (rb_SPI_WrCmdByte_l >> 1 & 0x1f)) ==> FALSE
      (42) if (rb_SPI_error_l != 1 && rb_ASIC_SPI_ErrorFlag_g != 1) ==> FALSE
      (57) if (rb_ASIC_SPI_ErrorFlag_g == 0) ==> FALSE
      (58) if (51 == rb_ASIC_ControlMode_g) ==> FALSE
      (60) while ((vc_SE0 & 0x1) == 0) ==> FALSE
      (61) if (rw_SPINoCommCounter_g < (0xff00)) ==> FALSE
      (62) if (rw_SPINoCommCounter_g >= (0xff00)) ==> FALSE
      (63) if (rb_StaticNoCommunicationCounter_g < 255) ==> FALSE
      (64) if (1 == rb_firstReadComm_g) ==> FALSE
      (66) if (vc_SSR00_bit.no6 == 0) ==> FALSE
   Test Case Generation Notes:
      Cannot set variable to unknown value in branch 5
      Cannot set rab_SPI_RcvCmd_l due to assignment
      Conflict: Unable to validate expression-to-expression comparison in branch 9
      Conflict: Multiple equality operators with different values (G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]) in branches 10/18
      Cannot set variable to unknown value in branch 19
      Cannot set rb_idx_cksum_l due to assignment
      Cannot set variable to unknown value in branch 23
      Cannot set rb_idx_cksum_l due to assignment
      Cannot set local variable rb_SPI_error_l in branch 24
      Cannot set local variable rb_idx_Max_l in branch 25
      Cannot set variable to unknown value in branch 26
      Cannot set local variable rb_SPI_error_l in branch 42
      Conflict: Multiple equality operators with different values (G5_spi_sr.<<GLOBAL>>.rb_ASIC_SPI_ErrorFlag_g) in branches 24/42
      Conflict: Trying to set variable G5_spi_sr.<<GLOBAL>>.rb_ASIC_SPI_ErrorFlag_g 'equal to' and 'not equal to' same value in branches 24/57
      Conflict: Trying to set variable G5_spi_sr.<<GLOBAL>>.rw_SPINoCommCounter_g 'less than' and 'greater than' same value in branches 61/62
TEST.END_NOTES:
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no5:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no6:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SE0:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_SPINoCommCounter_g:<<MAX>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_StaticNoCommunicationCounter_g:<<MAX>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]:128
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_bytes_to_send_mg:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_firstReadComm_g:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_ASIC_SPI_ErrorFlag_g:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-057-PARTIAL
TEST.UNIT:G5_spi_sr
TEST.SUBPROGRAM:SPI_int
TEST.NEW
TEST.NAME:BASIS-PATH-057-PARTIAL
TEST.COMPOUND_ONLY
TEST.BASIS_PATH:57 of 67
TEST.NOTES:
This is an automatically generated test case.
   Test Path 57
      (1) while (vc_SSR00_bit.no6 == 1 && vc_SSR00_bit.no5 == 1) ==> FALSE
      (2) if (rb_SPI_WBPosition_mg < rb_SPI_bytes_to_send_mg) ==> FALSE
      (5) if (rab_SPI_RcvCmd_l == ((rab_SPI_WriteBuffer_mg)[0] & 0xfe)) ==> TRUE
      (6) if ((rab_SPI_RcvCmd_l & 0xf0) == 0xd0) ==> FALSE
      (8) if ((((rab_SPI_WriteBuffer_mg)[0] & 0xc0) == 0x40 || ((rab_SPI_WriteBuffer_mg)[0] & 0xc0) == 0x80) || ((rab_SPI_WriteBuffer_mg)[0] & 0xf8) == 0x10) ==> TRUE
      (9) for (rb_i_bytes_rcv_l < rb_SPI_bytes_to_send_mg - 1) ==> TRUE
      (10) if ((rb_SPI_WrCmdByte_l & 0xc0) != 0x80) ==> FALSE
      (17) if ((rb_SPI_WrCmdByte_l & 0x80) == 0x80) ==> TRUE
      (18) if ((rab_SPI_WriteBuffer_mg)[rb_idx_cksum_l] & 0x1) ==> FALSE
      (19) if ((rw_ChksumCalc_l & (0xff)) != (rab_SPI_ReadBuffer_mg)[rb_idx_cksum_l] && (rw_ChksumCalc_l + (0x55) & (0xff)) != (rab_SPI_ReadBuffer_mg)[rb_idx_cksum_l]) ==> TRUE
      (20) if (rb_CurMode_g != 3) ==> TRUE
      (42) if (rb_SPI_error_l != 1 && rb_ASIC_SPI_ErrorFlag_g != 1) ==> FALSE
      (57) if (rb_ASIC_SPI_ErrorFlag_g == 0) ==> FALSE
      (58) if (51 == rb_ASIC_ControlMode_g) ==> FALSE
      (60) while ((vc_SE0 & 0x1) == 0) ==> FALSE
      (61) if (rw_SPINoCommCounter_g < (0xff00)) ==> FALSE
      (62) if (rw_SPINoCommCounter_g >= (0xff00)) ==> FALSE
      (63) if (rb_StaticNoCommunicationCounter_g < 255) ==> FALSE
      (64) if (1 == rb_firstReadComm_g) ==> FALSE
      (66) if (vc_SSR00_bit.no6 == 0) ==> FALSE
   Test Case Generation Notes:
      Cannot set variable to unknown value in branch 5
      Cannot set rab_SPI_RcvCmd_l due to assignment
      Conflict: Unable to validate expression-to-expression comparison in branch 9
      Conflict: Multiple equality operators with different values (G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]) in branches 10/18
      Cannot set variable to unknown value in branch 19
      Cannot set rb_idx_cksum_l due to assignment
      Cannot set rb_SPI_error_l due to assignment
      Conflict: Trying to set variable G5_spi_sr.<<GLOBAL>>.rw_SPINoCommCounter_g 'less than' and 'greater than' same value in branches 61/62
TEST.END_NOTES:
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no5:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no6:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SE0:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_SPINoCommCounter_g:<<MAX>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_StaticNoCommunicationCounter_g:<<MAX>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]:128
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_bytes_to_send_mg:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_firstReadComm_g:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_ASIC_SPI_ErrorFlag_g:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_CurMode_g:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-058-PARTIAL
TEST.UNIT:G5_spi_sr
TEST.SUBPROGRAM:SPI_int
TEST.NEW
TEST.NAME:BASIS-PATH-058-PARTIAL
TEST.COMPOUND_ONLY
TEST.BASIS_PATH:58 of 67
TEST.NOTES:
This is an automatically generated test case.
   Test Path 58
      (1) while (vc_SSR00_bit.no6 == 1 && vc_SSR00_bit.no5 == 1) ==> FALSE
      (2) if (rb_SPI_WBPosition_mg < rb_SPI_bytes_to_send_mg) ==> FALSE
      (5) if (rab_SPI_RcvCmd_l == ((rab_SPI_WriteBuffer_mg)[0] & 0xfe)) ==> TRUE
      (6) if ((rab_SPI_RcvCmd_l & 0xf0) == 0xd0) ==> FALSE
      (8) if ((((rab_SPI_WriteBuffer_mg)[0] & 0xc0) == 0x40 || ((rab_SPI_WriteBuffer_mg)[0] & 0xc0) == 0x80) || ((rab_SPI_WriteBuffer_mg)[0] & 0xf8) == 0x10) ==> TRUE
      (9) for (rb_i_bytes_rcv_l < rb_SPI_bytes_to_send_mg - 1) ==> TRUE
      (10) if ((rb_SPI_WrCmdByte_l & 0xc0) != 0x80) ==> FALSE
      (17) if ((rb_SPI_WrCmdByte_l & 0x80) == 0x80) ==> TRUE
      (18) if ((rab_SPI_WriteBuffer_mg)[rb_idx_cksum_l] & 0x1) ==> FALSE
      (19) if ((rw_ChksumCalc_l & (0xff)) != (rab_SPI_ReadBuffer_mg)[rb_idx_cksum_l] && (rw_ChksumCalc_l + (0x55) & (0xff)) != (rab_SPI_ReadBuffer_mg)[rb_idx_cksum_l]) ==> TRUE
      (20) if (rb_CurMode_g != 3) ==> FALSE
      (42) if (rb_SPI_error_l != 1 && rb_ASIC_SPI_ErrorFlag_g != 1) ==> FALSE
      (57) if (rb_ASIC_SPI_ErrorFlag_g == 0) ==> FALSE
      (58) if (51 == rb_ASIC_ControlMode_g) ==> FALSE
      (60) while ((vc_SE0 & 0x1) == 0) ==> FALSE
      (61) if (rw_SPINoCommCounter_g < (0xff00)) ==> FALSE
      (62) if (rw_SPINoCommCounter_g >= (0xff00)) ==> FALSE
      (63) if (rb_StaticNoCommunicationCounter_g < 255) ==> FALSE
      (64) if (1 == rb_firstReadComm_g) ==> FALSE
      (66) if (vc_SSR00_bit.no6 == 0) ==> FALSE
   Test Case Generation Notes:
      Cannot set variable to unknown value in branch 5
      Cannot set rab_SPI_RcvCmd_l due to assignment
      Conflict: Unable to validate expression-to-expression comparison in branch 9
      Conflict: Multiple equality operators with different values (G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]) in branches 10/18
      Cannot set variable to unknown value in branch 19
      Cannot set rb_idx_cksum_l due to assignment
      Cannot set variable to unknown value in branch 21
      Cannot set rb_idx_cksum_l due to assignment
      Cannot set rb_SPI_error_l due to assignment
      Conflict: Trying to set variable G5_spi_sr.<<GLOBAL>>.rw_SPINoCommCounter_g 'less than' and 'greater than' same value in branches 61/62
TEST.END_NOTES:
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no5:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no6:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SE0:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_SPINoCommCounter_g:<<MAX>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_StaticNoCommunicationCounter_g:<<MAX>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]:128
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_bytes_to_send_mg:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_firstReadComm_g:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_ASIC_SPI_ErrorFlag_g:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_CurMode_g:3
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-059-PARTIAL
TEST.UNIT:G5_spi_sr
TEST.SUBPROGRAM:SPI_int
TEST.NEW
TEST.NAME:BASIS-PATH-059-PARTIAL
TEST.COMPOUND_ONLY
TEST.BASIS_PATH:59 of 67
TEST.NOTES:
This is an automatically generated test case.
   Test Path 59
      (1) while (vc_SSR00_bit.no6 == 1 && vc_SSR00_bit.no5 == 1) ==> FALSE
      (2) if (rb_SPI_WBPosition_mg < rb_SPI_bytes_to_send_mg) ==> FALSE
      (5) if (rab_SPI_RcvCmd_l == ((rab_SPI_WriteBuffer_mg)[0] & 0xfe)) ==> TRUE
      (6) if ((rab_SPI_RcvCmd_l & 0xf0) == 0xd0) ==> FALSE
      (8) if ((((rab_SPI_WriteBuffer_mg)[0] & 0xc0) == 0x40 || ((rab_SPI_WriteBuffer_mg)[0] & 0xc0) == 0x80) || ((rab_SPI_WriteBuffer_mg)[0] & 0xf8) == 0x10) ==> TRUE
      (9) for (rb_i_bytes_rcv_l < rb_SPI_bytes_to_send_mg - 1) ==> TRUE
      (10) if ((rb_SPI_WrCmdByte_l & 0xc0) != 0x80) ==> FALSE
      (17) if ((rb_SPI_WrCmdByte_l & 0x80) == 0x80) ==> TRUE
      (18) if ((rab_SPI_WriteBuffer_mg)[rb_idx_cksum_l] & 0x1) ==> FALSE
      (19) if ((rw_ChksumCalc_l & (0xff)) != (rab_SPI_ReadBuffer_mg)[rb_idx_cksum_l] && (rw_ChksumCalc_l + (0x55) & (0xff)) != (rab_SPI_ReadBuffer_mg)[rb_idx_cksum_l]) ==> TRUE
      (20) if (rb_CurMode_g != 3) ==> FALSE
      (21) if ((rw_ChksumCalc_l & (0xff)) != (rab_SPI_ReadBuffer_mg)[rb_idx_cksum_l] && (rw_ChksumCalc_l + (0x55) & (0xff)) != (rab_SPI_ReadBuffer_mg)[rb_idx_cksum_l]) ==> FALSE
      (22) if ((rab_SPI_ReadBuffer_mg)[rb_idx_cksum_l] == (rw_ChksumCalc_l + (0x55) & (0xff))) ==> TRUE
      (42) if (rb_SPI_error_l != 1 && rb_ASIC_SPI_ErrorFlag_g != 1) ==> FALSE
      (57) if (rb_ASIC_SPI_ErrorFlag_g == 0) ==> FALSE
      (58) if (51 == rb_ASIC_ControlMode_g) ==> FALSE
      (60) while ((vc_SE0 & 0x1) == 0) ==> FALSE
      (61) if (rw_SPINoCommCounter_g < (0xff00)) ==> FALSE
      (62) if (rw_SPINoCommCounter_g >= (0xff00)) ==> FALSE
      (63) if (rb_StaticNoCommunicationCounter_g < 255) ==> FALSE
      (64) if (1 == rb_firstReadComm_g) ==> FALSE
      (66) if (vc_SSR00_bit.no6 == 0) ==> FALSE
   Test Case Generation Notes:
      Cannot set variable to unknown value in branch 5
      Cannot set rab_SPI_RcvCmd_l due to assignment
      Conflict: Unable to validate expression-to-expression comparison in branch 9
      Conflict: Multiple equality operators with different values (G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]) in branches 10/18
      Cannot set variable to unknown value in branch 19
      Cannot set rb_idx_cksum_l due to assignment
      Cannot set variable to unknown value in branch 21
      Cannot set rb_idx_cksum_l due to assignment
      Cannot set variable to unknown value in branch 22
      Cannot set rb_SPI_error_l due to assignment
      Conflict: Trying to set variable G5_spi_sr.<<GLOBAL>>.rw_SPINoCommCounter_g 'less than' and 'greater than' same value in branches 61/62
TEST.END_NOTES:
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no5:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no6:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SE0:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_SPINoCommCounter_g:<<MAX>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_StaticNoCommunicationCounter_g:<<MAX>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]:128
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_bytes_to_send_mg:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_firstReadComm_g:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_ASIC_SPI_ErrorFlag_g:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_CurMode_g:3
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-060-PARTIAL
TEST.UNIT:G5_spi_sr
TEST.SUBPROGRAM:SPI_int
TEST.NEW
TEST.NAME:BASIS-PATH-060-PARTIAL
TEST.COMPOUND_ONLY
TEST.BASIS_PATH:60 of 67
TEST.NOTES:
This is an automatically generated test case.
   Test Path 60
      (1) while (vc_SSR00_bit.no6 == 1 && vc_SSR00_bit.no5 == 1) ==> FALSE
      (2) if (rb_SPI_WBPosition_mg < rb_SPI_bytes_to_send_mg) ==> FALSE
      (5) if (rab_SPI_RcvCmd_l == ((rab_SPI_WriteBuffer_mg)[0] & 0xfe)) ==> TRUE
      (6) if ((rab_SPI_RcvCmd_l & 0xf0) == 0xd0) ==> FALSE
      (8) if ((((rab_SPI_WriteBuffer_mg)[0] & 0xc0) == 0x40 || ((rab_SPI_WriteBuffer_mg)[0] & 0xc0) == 0x80) || ((rab_SPI_WriteBuffer_mg)[0] & 0xf8) == 0x10) ==> TRUE
      (9) for (rb_i_bytes_rcv_l < rb_SPI_bytes_to_send_mg - 1) ==> TRUE
      (10) if ((rb_SPI_WrCmdByte_l & 0xc0) != 0x80) ==> FALSE
      (17) if ((rb_SPI_WrCmdByte_l & 0x80) == 0x80) ==> TRUE
      (18) if ((rab_SPI_WriteBuffer_mg)[rb_idx_cksum_l] & 0x1) ==> FALSE
      (19) if ((rw_ChksumCalc_l & (0xff)) != (rab_SPI_ReadBuffer_mg)[rb_idx_cksum_l] && (rw_ChksumCalc_l + (0x55) & (0xff)) != (rab_SPI_ReadBuffer_mg)[rb_idx_cksum_l]) ==> TRUE
      (20) if (rb_CurMode_g != 3) ==> FALSE
      (21) if ((rw_ChksumCalc_l & (0xff)) != (rab_SPI_ReadBuffer_mg)[rb_idx_cksum_l] && (rw_ChksumCalc_l + (0x55) & (0xff)) != (rab_SPI_ReadBuffer_mg)[rb_idx_cksum_l]) ==> FALSE
      (22) if ((rab_SPI_ReadBuffer_mg)[rb_idx_cksum_l] == (rw_ChksumCalc_l + (0x55) & (0xff))) ==> FALSE
      (24) if (0 == rb_SPI_error_l && 0 == rb_ASIC_SPI_ErrorFlag_g) ==> FALSE
      (42) if (rb_SPI_error_l != 1 && rb_ASIC_SPI_ErrorFlag_g != 1) ==> FALSE
      (57) if (rb_ASIC_SPI_ErrorFlag_g == 0) ==> FALSE
      (58) if (51 == rb_ASIC_ControlMode_g) ==> FALSE
      (60) while ((vc_SE0 & 0x1) == 0) ==> FALSE
      (61) if (rw_SPINoCommCounter_g < (0xff00)) ==> FALSE
      (62) if (rw_SPINoCommCounter_g >= (0xff00)) ==> FALSE
      (63) if (rb_StaticNoCommunicationCounter_g < 255) ==> FALSE
      (64) if (1 == rb_firstReadComm_g) ==> FALSE
      (66) if (vc_SSR00_bit.no6 == 0) ==> FALSE
   Test Case Generation Notes:
      Cannot set variable to unknown value in branch 5
      Cannot set rab_SPI_RcvCmd_l due to assignment
      Conflict: Unable to validate expression-to-expression comparison in branch 9
      Conflict: Multiple equality operators with different values (G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]) in branches 10/18
      Cannot set variable to unknown value in branch 19
      Cannot set rb_idx_cksum_l due to assignment
      Cannot set variable to unknown value in branch 21
      Cannot set rb_idx_cksum_l due to assignment
      Cannot set variable to unknown value in branch 22
      Cannot set local variable rb_SPI_error_l in branch 24
      Cannot set local variable rb_SPI_error_l in branch 42
      Conflict: Trying to set variable G5_spi_sr.<<GLOBAL>>.rw_SPINoCommCounter_g 'less than' and 'greater than' same value in branches 61/62
TEST.END_NOTES:
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no5:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no6:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SE0:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_SPINoCommCounter_g:<<MAX>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_StaticNoCommunicationCounter_g:<<MAX>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]:128
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_bytes_to_send_mg:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_firstReadComm_g:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_ASIC_SPI_ErrorFlag_g:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_CurMode_g:3
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-061-PARTIAL
TEST.UNIT:G5_spi_sr
TEST.SUBPROGRAM:SPI_int
TEST.NEW
TEST.NAME:BASIS-PATH-061-PARTIAL
TEST.COMPOUND_ONLY
TEST.BASIS_PATH:61 of 67
TEST.NOTES:
This is an automatically generated test case.
   Test Path 61
      (1) while (vc_SSR00_bit.no6 == 1 && vc_SSR00_bit.no5 == 1) ==> FALSE
      (2) if (rb_SPI_WBPosition_mg < rb_SPI_bytes_to_send_mg) ==> FALSE
      (5) if (rab_SPI_RcvCmd_l == ((rab_SPI_WriteBuffer_mg)[0] & 0xfe)) ==> TRUE
      (6) if ((rab_SPI_RcvCmd_l & 0xf0) == 0xd0) ==> FALSE
      (8) if ((((rab_SPI_WriteBuffer_mg)[0] & 0xc0) == 0x40 || ((rab_SPI_WriteBuffer_mg)[0] & 0xc0) == 0x80) || ((rab_SPI_WriteBuffer_mg)[0] & 0xf8) == 0x10) ==> TRUE
      (9) for (rb_i_bytes_rcv_l < rb_SPI_bytes_to_send_mg - 1) ==> TRUE
      (10) if ((rb_SPI_WrCmdByte_l & 0xc0) != 0x80) ==> FALSE
      (17) if ((rb_SPI_WrCmdByte_l & 0x80) == 0x80) ==> TRUE
      (18) if ((rab_SPI_WriteBuffer_mg)[rb_idx_cksum_l] & 0x1) ==> TRUE
      (19) if ((rw_ChksumCalc_l & (0xff)) != (rab_SPI_ReadBuffer_mg)[rb_idx_cksum_l] && (rw_ChksumCalc_l + (0x55) & (0xff)) != (rab_SPI_ReadBuffer_mg)[rb_idx_cksum_l]) ==> FALSE
      (23) if ((rw_ChksumCalc_l + (0x55) & (0xff)) == (rab_SPI_ReadBuffer_mg)[rb_idx_cksum_l]) ==> TRUE
      (42) if (rb_SPI_error_l != 1 && rb_ASIC_SPI_ErrorFlag_g != 1) ==> FALSE
      (57) if (rb_ASIC_SPI_ErrorFlag_g == 0) ==> FALSE
      (58) if (51 == rb_ASIC_ControlMode_g) ==> FALSE
      (60) while ((vc_SE0 & 0x1) == 0) ==> FALSE
      (61) if (rw_SPINoCommCounter_g < (0xff00)) ==> FALSE
      (62) if (rw_SPINoCommCounter_g >= (0xff00)) ==> FALSE
      (63) if (rb_StaticNoCommunicationCounter_g < 255) ==> FALSE
      (64) if (1 == rb_firstReadComm_g) ==> FALSE
      (66) if (vc_SSR00_bit.no6 == 0) ==> FALSE
   Test Case Generation Notes:
      Cannot set variable to unknown value in branch 5
      Cannot set rab_SPI_RcvCmd_l due to assignment
      Conflict: Unable to validate expression-to-expression comparison in branch 9
      Conflict: Multiple equality operators with different values (G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]) in branches 10/18
      Cannot set variable to unknown value in branch 19
      Cannot set rb_idx_cksum_l due to assignment
      Cannot set variable to unknown value in branch 23
      Cannot set rb_idx_cksum_l due to assignment
      Cannot set rb_SPI_error_l due to assignment
      Conflict: Trying to set variable G5_spi_sr.<<GLOBAL>>.rw_SPINoCommCounter_g 'less than' and 'greater than' same value in branches 61/62
TEST.END_NOTES:
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no5:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no6:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SE0:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_SPINoCommCounter_g:<<MAX>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_StaticNoCommunicationCounter_g:<<MAX>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]:128
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_bytes_to_send_mg:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_firstReadComm_g:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_ASIC_SPI_ErrorFlag_g:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-062-PARTIAL
TEST.UNIT:G5_spi_sr
TEST.SUBPROGRAM:SPI_int
TEST.NEW
TEST.NAME:BASIS-PATH-062-PARTIAL
TEST.COMPOUND_ONLY
TEST.BASIS_PATH:62 of 67
TEST.NOTES:
This is an automatically generated test case.
   Test Path 62
      (1) while (vc_SSR00_bit.no6 == 1 && vc_SSR00_bit.no5 == 1) ==> FALSE
      (2) if (rb_SPI_WBPosition_mg < rb_SPI_bytes_to_send_mg) ==> FALSE
      (5) if (rab_SPI_RcvCmd_l == ((rab_SPI_WriteBuffer_mg)[0] & 0xfe)) ==> TRUE
      (6) if ((rab_SPI_RcvCmd_l & 0xf0) == 0xd0) ==> TRUE
      (7) for (rb_ID_idx_l < 3) ==> FALSE
      (42) if (rb_SPI_error_l != 1 && rb_ASIC_SPI_ErrorFlag_g != 1) ==> FALSE
      (57) if (rb_ASIC_SPI_ErrorFlag_g == 0) ==> FALSE
      (58) if (51 == rb_ASIC_ControlMode_g) ==> FALSE
      (60) while ((vc_SE0 & 0x1) == 0) ==> FALSE
      (61) if (rw_SPINoCommCounter_g < (0xff00)) ==> FALSE
      (62) if (rw_SPINoCommCounter_g >= (0xff00)) ==> FALSE
      (63) if (rb_StaticNoCommunicationCounter_g < 255) ==> FALSE
      (64) if (1 == rb_firstReadComm_g) ==> FALSE
      (66) if (vc_SSR00_bit.no6 == 0) ==> FALSE
   Test Case Generation Notes:
      Cannot set variable to unknown value in branch 5
      Cannot set rab_SPI_RcvCmd_l due to assignment
      Conflict: Unable to validate expression-to-expression comparison in branch 7
      Cannot set local variable rb_SPI_error_l in branch 42
      Conflict: Trying to set variable G5_spi_sr.<<GLOBAL>>.rw_SPINoCommCounter_g 'less than' and 'greater than' same value in branches 61/62
TEST.END_NOTES:
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no5:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no6:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SE0:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_SPINoCommCounter_g:<<MAX>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_StaticNoCommunicationCounter_g:<<MAX>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_bytes_to_send_mg:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_firstReadComm_g:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_ASIC_SPI_ErrorFlag_g:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-063-PARTIAL
TEST.UNIT:G5_spi_sr
TEST.SUBPROGRAM:SPI_int
TEST.NEW
TEST.NAME:BASIS-PATH-063-PARTIAL
TEST.COMPOUND_ONLY
TEST.BASIS_PATH:63 of 67
TEST.NOTES:
This is an automatically generated test case.
   Test Path 63
      (1) while (vc_SSR00_bit.no6 == 1 && vc_SSR00_bit.no5 == 1) ==> FALSE
      (2) if (rb_SPI_WBPosition_mg < rb_SPI_bytes_to_send_mg) ==> FALSE
      (5) if (rab_SPI_RcvCmd_l == ((rab_SPI_WriteBuffer_mg)[0] & 0xfe)) ==> TRUE
      (6) if ((rab_SPI_RcvCmd_l & 0xf0) == 0xd0) ==> TRUE
      (7) for (rb_ID_idx_l < 3) ==> TRUE
      (42) if (rb_SPI_error_l != 1 && rb_ASIC_SPI_ErrorFlag_g != 1) ==> FALSE
      (57) if (rb_ASIC_SPI_ErrorFlag_g == 0) ==> FALSE
      (58) if (51 == rb_ASIC_ControlMode_g) ==> FALSE
      (60) while ((vc_SE0 & 0x1) == 0) ==> FALSE
      (61) if (rw_SPINoCommCounter_g < (0xff00)) ==> FALSE
      (62) if (rw_SPINoCommCounter_g >= (0xff00)) ==> FALSE
      (63) if (rb_StaticNoCommunicationCounter_g < 255) ==> FALSE
      (64) if (1 == rb_firstReadComm_g) ==> FALSE
      (66) if (vc_SSR00_bit.no6 == 0) ==> FALSE
   Test Case Generation Notes:
      Cannot set variable to unknown value in branch 5
      Cannot set rab_SPI_RcvCmd_l due to assignment
      Conflict: Unable to validate expression-to-expression comparison in branch 7
      Cannot set local variable rb_SPI_error_l in branch 42
      Conflict: Trying to set variable G5_spi_sr.<<GLOBAL>>.rw_SPINoCommCounter_g 'less than' and 'greater than' same value in branches 61/62
TEST.END_NOTES:
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no5:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no6:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SE0:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_SPINoCommCounter_g:<<MAX>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_StaticNoCommunicationCounter_g:<<MAX>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_bytes_to_send_mg:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_firstReadComm_g:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_ASIC_SPI_ErrorFlag_g:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-064
TEST.UNIT:G5_spi_sr
TEST.SUBPROGRAM:SPI_int
TEST.NEW
TEST.NAME:BASIS-PATH-064
TEST.COMPOUND_ONLY
TEST.BASIS_PATH:64 of 67
TEST.NOTES:
This is an automatically generated test case.
   Test Path 64
      (1) while (vc_SSR00_bit.no6 == 1 && vc_SSR00_bit.no5 == 1) ==> FALSE
      (2) if (rb_SPI_WBPosition_mg < rb_SPI_bytes_to_send_mg) ==> TRUE
      (4) while ((vc_SE0 & 0x1) == 0) ==> FALSE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no5:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no6:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SE0:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_bytes_to_send_mg:<<MAX>>
TEST.END

-- Test Case: BASIS-PATH-065
TEST.UNIT:G5_spi_sr
TEST.SUBPROGRAM:SPI_int
TEST.NEW
TEST.NAME:BASIS-PATH-065
TEST.COMPOUND_ONLY
TEST.BASIS_PATH:65 of 67
TEST.NOTES:
This is an automatically generated test case.
   Test Path 65
      (1) while (vc_SSR00_bit.no6 == 1 && vc_SSR00_bit.no5 == 1) ==> FALSE
      (2) if (rb_SPI_WBPosition_mg < rb_SPI_bytes_to_send_mg) ==> TRUE
      (4) while ((vc_SE0 & 0x1) == 0) ==> TRUE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no5:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no6:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SE0:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_bytes_to_send_mg:<<MAX>>
TEST.END

-- Test Case: BASIS-PATH-066-PARTIAL
TEST.UNIT:G5_spi_sr
TEST.SUBPROGRAM:SPI_int
TEST.NEW
TEST.NAME:BASIS-PATH-066-PARTIAL
TEST.COMPOUND_ONLY
TEST.BASIS_PATH:66 of 67
TEST.NOTES:
This is an automatically generated test case.
   Test Path 66
      (1) while (vc_SSR00_bit.no6 == 1 && vc_SSR00_bit.no5 == 1) ==> FALSE
      (2) if (rb_SPI_WBPosition_mg < rb_SPI_bytes_to_send_mg) ==> TRUE
      (3) while (vc_SSR00_bit.no6 == 1 && vc_SSR00_bit.no5 == 1) ==> TRUE
      (4) while ((vc_SE0 & 0x1) == 0) ==> FALSE
   Test Case Generation Notes:
      Conflict: Trying to set variable G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no6 'equal to' and 'not equal to' same value in branches 1/3
      Conflict: Trying to set variable G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no5 'equal to' and 'not equal to' same value in branches 1/3
TEST.END_NOTES:
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no5:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no6:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SE0:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_bytes_to_send_mg:<<MAX>>
TEST.END

-- Test Case: BASIS-PATH-067-PARTIAL
TEST.UNIT:G5_spi_sr
TEST.SUBPROGRAM:SPI_int
TEST.NEW
TEST.NAME:BASIS-PATH-067-PARTIAL
TEST.COMPOUND_ONLY
TEST.BASIS_PATH:67 of 67
TEST.NOTES:
This is an automatically generated test case.
   Test Path 67
      (1) while (vc_SSR00_bit.no6 == 1 && vc_SSR00_bit.no5 == 1) ==> TRUE
      (2) if (rb_SPI_WBPosition_mg < rb_SPI_bytes_to_send_mg) ==> FALSE
      (5) if (rab_SPI_RcvCmd_l == ((rab_SPI_WriteBuffer_mg)[0] & 0xfe)) ==> FALSE
      (42) if (rb_SPI_error_l != 1 && rb_ASIC_SPI_ErrorFlag_g != 1) ==> FALSE
      (57) if (rb_ASIC_SPI_ErrorFlag_g == 0) ==> FALSE
      (58) if (51 == rb_ASIC_ControlMode_g) ==> FALSE
      (59) while (vc_SSR00_bit.no6 == 1 && vc_SSR00_bit.no5 == 1) ==> FALSE
      (60) while ((vc_SE0 & 0x1) == 0) ==> FALSE
      (61) if (rw_SPINoCommCounter_g < (0xff00)) ==> FALSE
      (62) if (rw_SPINoCommCounter_g >= (0xff00)) ==> FALSE
      (63) if (rb_StaticNoCommunicationCounter_g < 255) ==> FALSE
      (64) if (1 == rb_firstReadComm_g) ==> FALSE
      (66) if (vc_SSR00_bit.no6 == 0) ==> FALSE
   Test Case Generation Notes:
      Cannot set variable to unknown value in branch 5
      Cannot set rb_SPI_error_l due to assignment
      Conflict: Trying to set variable G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no6 'equal to' and 'not equal to' same value in branches 1/59
      Conflict: Trying to set variable G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no5 'equal to' and 'not equal to' same value in branches 1/59
      Conflict: Trying to set variable G5_spi_sr.<<GLOBAL>>.rw_SPINoCommCounter_g 'less than' and 'greater than' same value in branches 61/62
TEST.END_NOTES:
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no5:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no6:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SE0:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_SPINoCommCounter_g:<<MAX>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_StaticNoCommunicationCounter_g:<<MAX>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_bytes_to_send_mg:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_firstReadComm_g:<<MIN>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_ASIC_SPI_ErrorFlag_g:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_ASIC_ControlMode_g:<<MIN>>
TEST.END

-- Test Case: SPIErrorFlagActive
TEST.UNIT:G5_spi_sr
TEST.SUBPROGRAM:SPI_int
TEST.NEW
TEST.NAME:SPIErrorFlagActive
TEST.NOTES:
SPI Interrupt - SPIErrorFlagActive
Input:
-Set communication is ready
-Set all bytes are sent (ie.Validate Data)
-Set SPI Error (i.e Invalid Receive Cmd)
-Set rb_ASIC_SPI_ErrorFlag_g as TRUE
Expected Result:
-Check fallback mechanism 4 bytes data is sent
TEST.END_NOTES:
TEST.STUB:G5_spi_sr.spi_CommunicationFaultHandl
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_MK0H_bit.no5:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no6:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SE0:0x1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_StaticNoCommunicationCounter_g:10
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.uF_SPI_flags_g.Bit.B0:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]:0x41
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[1]:255
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[2]:<<MIN-1>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[3]:<<ZERO>>
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[0]:0xDF
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_bytes_to_send_mg:2
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_WBPosition_mg:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_ASIC_SPI_ErrorFlag_g:1
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.vc_MK0H_bit.no5:1
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no6:0
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.vc_SE0:0x1
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rb_StaticNoCommunicationCounter_g:0xB
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.uF_SPI_flags_g.Bit.B0:0
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[1]:0x2A
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[2]:0x2A
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[3]:0x2A
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[0]:0xDF
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rb_SPI_bytes_to_send_mg:4
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rb_SPI_WBPosition_mg:0
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rb_ASIC_SPI_ErrorFlag_g:0
TEST.ATTRIBUTES:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]::EXPECTED_BASE=16
TEST.END

-- Test Case: SPI_int.ChgMode
TEST.UNIT:G5_spi_sr
TEST.SUBPROGRAM:SPI_int
TEST.NEW
TEST.NAME:SPI_int.ChgMode
TEST.NOTES:
SPI:int SPI_int.ChgMode
Inputs
Stub the function set_rad_SPI_ReadBuffer_mg
Set vc_SSR00_bit.no5 = 0 and vc_SSR00_bit.no6 =1
Set VC_SE0 = 0xF1
Set rab_SPI_WriteBuffer_mg = { 0xC0 }
Set rab_SPI_ReadBuffer_mg = { 0x9F }
Set rb_SPI_bytes_to_send_mg = 1
Set rb_SPI_WBPosition_mg = 1
TEST.END_NOTES:
TEST.STUB:G5_spi_sr.set_rab_SPI_ReadBuffer_mg
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no5:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no6:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SE0:0xF1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]:0xC0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[0]:0x9F
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_bytes_to_send_mg:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_WBPosition_mg:1
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[0]:0x9F
TEST.END

-- Test Case: SPI_int.ChgMode.001
TEST.UNIT:G5_spi_sr
TEST.SUBPROGRAM:SPI_int
TEST.NEW
TEST.NAME:SPI_int.ChgMode.001
TEST.NOTES:
SPI:int SPI_int.ChgMode
Inputs
Stub the function set_rad_SPI_ReadBuffer_mg
Set vc_SSR00_bit.no5 = 0 and vc_SSR00_bit.no6 =1
Set VC_SE0 = 0xF1
Set rab_SPI_WriteBuffer_mg = { 0xC6 }
Set rab_SPI_ReadBuffer_mg = { 0x9C }
Set rb_SPI_bytes_to_send_mg = 1
Set rb_SPI_WBPosition_mg = 1
TEST.END_NOTES:
TEST.STUB:G5_spi_sr.set_rab_SPI_ReadBuffer_mg
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no5:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no6:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SE0:0xF1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]:0xC6
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[0]:0x9C
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_bytes_to_send_mg:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_WBPosition_mg:1
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[0]:0x9C
TEST.END

-- Test Case: SPI_int.ChgMode.002
TEST.UNIT:G5_spi_sr
TEST.SUBPROGRAM:SPI_int
TEST.NEW
TEST.NAME:SPI_int.ChgMode.002
TEST.NOTES:
SPI:int SPI_int.ChgMode
Inputs
SPI:int SPI_int.ChgMode
Inputs
Stub the function set_rad_SPI_ReadBuffer_mg
Set vc_SSR00_bit.no5 = 0 and vc_SSR00_bit.no6 =1
Set VC_SE0 = 0xF1
Set rab_SPI_WriteBuffer_mg = { 0xC0 }
Set rab_SPI_ReadBuffer_mg = { 0x9F }
Set rb_SPI_bytes_to_send_mg = 1
Set rb_SPI_WBPosition_mg = 1
rb_CurMode_g = 3
TEST.END_NOTES:
TEST.STUB:G5_spi_sr.set_rab_SPI_ReadBuffer_mg
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no5:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no6:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SE0:0xF1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]:0xC0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[0]:0x9F
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_bytes_to_send_mg:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_WBPosition_mg:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_CurMode_g:3
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[0]:0x9F
TEST.END

-- Test Case: SPI_int.ChgMode.003
TEST.UNIT:G5_spi_sr
TEST.SUBPROGRAM:SPI_int
TEST.NEW
TEST.NAME:SPI_int.ChgMode.003
TEST.NOTES:
SPI:int SPI_int.ChgMode
Inputs
Stub the function set_rad_SPI_ReadBuffer_mg
Set vc_SSR00_bit.no5 = 0 and vc_SSR00_bit.no6 =1
Set VC_SE0 = 0xF1
Set rab_SPI_WriteBuffer_mg = { 0x64 }
Set rab_SPI_ReadBuffer_mg = { 0xCD }
Set rb_SPI_bytes_to_send_mg = 1
Set rb_SPI_WBPosition_mg = 1
rb_CurMode_g = 1
TEST.END_NOTES:
TEST.STUB:G5_spi_sr.set_rab_SPI_ReadBuffer_mg
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no5:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no6:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SE0:0xF1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]:0x64
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[0]:0xCD
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_bytes_to_send_mg:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_WBPosition_mg:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_CurMode_g:1
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[0]:0xCD
TEST.END

-- Test Case: SPI_int.ChgMode.004
TEST.UNIT:G5_spi_sr
TEST.SUBPROGRAM:SPI_int
TEST.NEW
TEST.NAME:SPI_int.ChgMode.004
TEST.NOTES:
SPI:int SPI_int.ChgMode
Inputs
Stub the function set_rad_SPI_ReadBuffer_mg
Set vc_SSR00_bit.no5 = 0 and vc_SSR00_bit.no6 =1
Set VC_SE0 = 0xF1
Set rab_SPI_WriteBuffer_mg = { 0x64.0x65 }
Set rab_SPI_ReadBuffer_mg = { 0xCD }
Set rb_SPI_bytes_to_send_mg = 1
Set rb_SPI_WBPosition_mg = 1
rb_CurMode_g = 1
TEST.END_NOTES:
TEST.STUB:G5_spi_sr.set_rab_SPI_ReadBuffer_mg
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no5:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no6:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SE0:0xF1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]:0x64
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[1]:0x65
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[0]:0xCD
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_bytes_to_send_mg:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_WBPosition_mg:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_CurMode_g:1
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[0]:0xCD
TEST.END

-- Test Case: SPI_int.InvalidCmd.001
TEST.UNIT:G5_spi_sr
TEST.SUBPROGRAM:SPI_int
TEST.NEW
TEST.NAME:SPI_int.InvalidCmd.001
TEST.NOTES:
SPI:int SPI_int.InvalidCmd.001
Inputs
Stub the function set_rad_SPI_ReadBuffer_mg
Set vc_SSR00_bit.no5 = 0 and vc_SSR00_bit.no6 =1
Set VC_SE0 = 0xF1
Set rab_SPI_WriteBuffer_mg = { 0xC6 }
Set rab_SPI_ReadBuffer_mg = { 0x63 }
Set rb_SPI_bytes_to_send_mg = 1
Set rb_SPI_WBPosition_mg = 2
TEST.END_NOTES:
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no5:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no6:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SE0:0xF1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_SPINoCommCounter_g:5
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]:0xC6
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[0]:0x63
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_bytes_to_send_mg:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_WBPosition_mg:2
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[0]:99
TEST.END

-- Test Case: SPI_int.InvalidCmd_SpiError
TEST.UNIT:G5_spi_sr
TEST.SUBPROGRAM:SPI_int
TEST.NEW
TEST.NAME:SPI_int.InvalidCmd_SpiError
TEST.NOTES:
SPI:int SPI_int.InvalidCmd_SpiError
Inputs
Stub the function set_rad_SPI_ReadBuffer_mg
Set vc_SSR00_bit.no5 = 0 and vc_SSR00_bit.no6 =1
Set VC_SE0 = 0xF1
Set rab_SPI_WriteBuffer_mg = { 0x22 }
Set rab_SPI_ReadBuffer_mg = { 0xEE }
Set rb_SPI_bytes_to_send_mg = 3
Set rb_SPI_WBPosition_mg = 2
Set rb_firstReadComm_g
rb_StaticNoCommunicationCounter_g = 0
Output
rb_StaticNoCommunicationCounter_g = 0
rb_firstReadComm_g = 0
TEST.END_NOTES:
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no5:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no6:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SE0:0xF1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_SPINoCommCounter_g:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_StaticNoCommunicationCounter_g:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]:0x22
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[0]:0xEE
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_bytes_to_send_mg:3
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_WBPosition_mg:2
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_firstReadComm_g:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_ASIC_SPI_ErrorFlag_g:0
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rw_SPINoCommCounter_g:0x0
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rb_StaticNoCommunicationCounter_g:0
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rb_firstReadComm_g:0
TEST.END

-- Test Case: SPI_int.Read1Byte
TEST.UNIT:G5_spi_sr
TEST.SUBPROGRAM:SPI_int
TEST.NEW
TEST.NAME:SPI_int.Read1Byte
TEST.NOTES:
SPI:int SPI_int.Read1Byte
Inputs
Stub the function set_rad_SPI_ReadBuffer_mg
Set vc_SSR00_bit.no5 = 0 and vc_SSR00_bit.no6 =1
Set VC_SE0 = 0xF1
Set rab_SPI_WriteBuffer_mg = { 0x9E,0x2A, 0x2A }
Set rab_SPI_ReadBuffer_mg = { 0xB0, 0x5A, 0xFD }
Set rb_SPI_bytes_to_send_mg = 3
Set rb_SPI_WBPosition_mg = 3
Set rb_CurMode_g = 4
Set rb_NextSPI_Request_g = 0x03
TEST.END_NOTES:
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no5:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no6:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SE0:0xF1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]:0x9E
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[1]:0x2A
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[2]:0x2A
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[0]:0xB0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[1]:0x5A
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[2]:0xFD
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_bytes_to_send_mg:3
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_WBPosition_mg:3
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_CurMode_g:4
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_NextSPI_Request_g:0x3
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[0]:0xB0
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[1]:0x5A
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[2]:0xFD
TEST.END

-- Test Case: SPI_int.Read1ByteError
TEST.UNIT:G5_spi_sr
TEST.SUBPROGRAM:SPI_int
TEST.NEW
TEST.NAME:SPI_int.Read1ByteError
TEST.NOTES:
SPI:int SPI_int.Read1Error
Inputs
Stub the function set_rad_SPI_ReadBuffer_mg
Set vc_SSR00_bit.no5 = 0 and vc_SSR00_bit.no6 =1
Set VC_SE0 = 0xF1
Set rab_SPI_WriteBuffer_mg = { 0x80,0x2A, 0x2A }
Set rab_SPI_ReadBuffer_mg = { 0xBF, 0xAA, 0x6D }
Set rb_SPI_bytes_to_send_mg = 3
Set rb_SPI_WBPosition_mg = 2
Set rb_CurMode_g = 4
Set rb_NextSPI_Request_g = 0x03
Output
rab_SPI_ReadBuffer = { 0xBF, 0xAA, 0x6D }
TEST.END_NOTES:
TEST.STUB:G5_spi_sr.set_rab_SPI_ReadBuffer_mg
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no5:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no6:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SE0:0xF1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]:0x80
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[1]:0x2A
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[2]:0x2A
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[0]:0xBF
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[1]:0xAA
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[2]:0x6D
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_bytes_to_send_mg:3
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_WBPosition_mg:2
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_CurMode_g:3
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[0]:0xBF
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[1]:0xAA
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[2]:0x6D
TEST.END

-- Test Case: SPI_int.Read2Byte
TEST.UNIT:G5_spi_sr
TEST.SUBPROGRAM:SPI_int
TEST.NEW
TEST.NAME:SPI_int.Read2Byte
TEST.NOTES:
SPI:int SPI_int.Read2Byte
Inputs
Stub the function set_rad_SPI_ReadBuffer_mg
Set vc_SSR00_bit.no5 = 0 and vc_SSR00_bit.no6 =1
Set VC_SE0 = 0xF1
Set rab_SPI_WriteBuffer_mg = { 0x8F,0x2A, 0x2A. 0x2A }
Set rab_SPI_ReadBuffer_mg = { 0xB8, 0x5A, 0x20,0x0E }
Set rb_SPI_bytes_to_send_mg = 3
Set rb_SPI_WBPosition_mg = 3
Set rb_CurMode_g = 4
Set rb_NextSPI_Request_g = 0x03
Output
rab_SPI_ReadBuffer = {0xB8,0x5A,0x20,0x0E}
TEST.END_NOTES:
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no5:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no6:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SE0:0xF1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]:0x8F
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[1]:0x2A
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[2]:0x2A
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[3]:0x2A
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[0]:0xB8
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[1]:0x5A
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[2]:0x20
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[3]:0xE
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_bytes_to_send_mg:4
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_WBPosition_mg:4
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_CurMode_g:4
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[0]:0xB8
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[1]:0x5A
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[2]:0x20
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[3]:0xE
TEST.END

-- Test Case: SPI_int.Read2Byte1
TEST.UNIT:G5_spi_sr
TEST.SUBPROGRAM:SPI_int
TEST.NEW
TEST.NAME:SPI_int.Read2Byte1
TEST.NOTES:
SPI:int SPI_int.Read2Byte1
Inputs
Stub the function set_rad_SPI_ReadBuffer_mg
Set vc_SSR00_bit.no5 = 0 and vc_SSR00_bit.no6 =1
Set VC_SE0 = 0xF1
Set rab_SPI_WriteBuffer_mg = { 0x8F,0x2A, 0x2A, 0x2A }
Set rab_SPI_ReadBuffer_mg = { 0xB8, 0x5A, 0x20,0x63 }
Set rb_SPI_bytes_to_send_mg = 4
Set rb_SPI_WBPosition_mg = 4
Set rb_CurMode_g = 4
Set rb_NextSPI_Request_g = 0x03
Output
rab_SPI_ReadBuffer = { 0xB8, 0x5A, 0x20,0x63 }
TEST.END_NOTES:
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no5:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no6:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SE0:0xF1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]:0x8F
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[1]:0x2A
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[2]:0x2A
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[3]:0x2A
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[0]:0xB8
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[1]:0x5A
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[2]:0x20
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[3]:0x63
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_bytes_to_send_mg:4
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_WBPosition_mg:4
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_CurMode_g:4
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[0]:0xB8
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[1]:0x5A
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[2]:0x20
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[3]:0x63
TEST.END

-- Test Case: SPI_int.Read2ByteError
TEST.UNIT:G5_spi_sr
TEST.SUBPROGRAM:SPI_int
TEST.NEW
TEST.NAME:SPI_int.Read2ByteError
TEST.NOTES:
SPI:int SPI_int.Read2ByteError
Inputs
Stub the function set_rad_SPI_ReadBuffer_mg
Set vc_SSR00_bit.no5 = 0 and vc_SSR00_bit.no6 =1
Set VC_SE0 = 0xF1
Set rab_SPI_WriteBuffer_mg = { 0x8F,0x2A, 0x2A }
Set rab_SPI_ReadBuffer_mg = { 0xB8, 0x5A, 0x20,0x0E }
Set rb_SPI_bytes_to_send_mg = 3
Set rb_SPI_WBPosition_mg = 2
Set rb_CurMode_g = 4

Output
rab_SPI_ReadBuffer = { 0xB8, 0x5A, 0x20,0x0E }
TEST.END_NOTES:
TEST.STUB:G5_spi_sr.set_rab_SPI_ReadBuffer_mg
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no5:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no6:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SE0:0xF1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]:0x8F
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[1]:0x2A
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[2]:0x2A
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[0]:0xB8
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[1]:0x5A
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[2]:0x20
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[3]:0xE
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_bytes_to_send_mg:3
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_WBPosition_mg:2
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_CurMode_g:4
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[0]:184
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[1]:90
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[2]:32
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[3]:14
TEST.END

-- Test Case: SPI_int.Read2ByteError.001
TEST.UNIT:G5_spi_sr
TEST.SUBPROGRAM:SPI_int
TEST.NEW
TEST.NAME:SPI_int.Read2ByteError.001
TEST.NOTES:
SPI:int SPI_int.Read2ByteError.001
Inputs
Stub the function set_rad_SPI_ReadBuffer_mg
Set vc_SSR00_bit.no5 = 0 and vc_SSR00_bit.no6 =1
Set VC_SE0 = 0xF1
Set rab_SPI_WriteBuffer_mg = { 0x8F,0x2A, 0x2A }
Set rab_SPI_ReadBuffer_mg = { 0xB8, 0x5A, 0x20,800E }
Set rb_SPI_bytes_to_send_mg = 3
Set rb_SPI_WBPosition_mg = 2
Set rb_CurMode_g = 3
Set rb_NextSPI_Request_g = 0x03
Output
rab_SPI_ReadBuffer = { 0xB8, 0x5A, 0x20,800E }
TEST.END_NOTES:
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no5:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no6:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SE0:0xF1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]:0x8F
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[1]:0x2A
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[2]:0x2A
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[0]:0xB8
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[1]:0x5A
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[2]:0x20
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[3]:0xE
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_bytes_to_send_mg:3
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_WBPosition_mg:2
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_CurMode_g:3
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]:0x8F
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[1]:0x2A
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[2]:0x2A
TEST.ATTRIBUTES:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[0]:EXPECTED_BASE=16
TEST.ATTRIBUTES:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[1]:EXPECTED_BASE=16
TEST.ATTRIBUTES:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[2]:EXPECTED_BASE=16
TEST.ATTRIBUTES:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[3]:EXPECTED_BASE=16
TEST.END

-- Test Case: SPI_int.Read2ByteRain1
TEST.UNIT:G5_spi_sr
TEST.SUBPROGRAM:SPI_int
TEST.NEW
TEST.NAME:SPI_int.Read2ByteRain1
TEST.NOTES:
SPI_init

1.if (rb_SPI_WBPosition_mg < rb_SPI_bytes_to_send_mg) ==> TRUE
2.The SRD Register will be written with the next value to send from write buffer
TEST.END_NOTES:
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no5:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no6:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SE0:0xF1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]:0xA9
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[1]:0x2A
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[2]:0x2A
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[3]:0x2A
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[0]:0xAB
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[1]:0x5A
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[2]:0x20
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[3]:0x29
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_bytes_to_send_mg:4
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_WBPosition_mg:4
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_CurMode_g:5
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_INTV10bit_min_g:0x1FF
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_REGV_min_g:0xFFFF
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_LIN_INTV10bit_min_g:0xFFFF
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[0]:0xAB
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[1]:0x5A
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[2]:0x20
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[3]:0x29
TEST.END

-- Test Case: SPI_int.Read2ByteRain2
TEST.UNIT:G5_spi_sr
TEST.SUBPROGRAM:SPI_int
TEST.NEW
TEST.NAME:SPI_int.Read2ByteRain2
TEST.NOTES:
SPI_init

1.if (rb_SPI_WBPosition_mg < rb_SPI_bytes_to_send_mg) ==> TRUE
2.The SRD Register will be written with the next value to send from write buffer
TEST.END_NOTES:
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no5:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no6:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SE0:0xF1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]:0xA9
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[1]:0x2A
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[2]:0x2A
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[3]:0x2A
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[0]:0xAB
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[1]:0x5A
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[2]:0x20
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[3]:0x28
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_bytes_to_send_mg:4
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_WBPosition_mg:4
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_CurMode_g:4
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_INTV10bit_min_g:0x0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_REGV_min_g:0x0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_LIN_INTV10bit_min_g:0x0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.rw_INTV10bit_max_g:0xFFFF
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.rw_REGV_max_g:0xFFFF
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.rw_LIN_INTV10bit_max_g:0xFFFF
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[0]:0xAB
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[1]:0x5A
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[2]:0x20
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[3]:0x28
TEST.END

-- Test Case: SPI_int.Read2ByteRain3
TEST.UNIT:G5_spi_sr
TEST.SUBPROGRAM:SPI_int
TEST.NEW
TEST.NAME:SPI_int.Read2ByteRain3
TEST.NOTES:
SPI_init

1.if (rb_SPI_WBPosition_mg < rb_SPI_bytes_to_send_mg) ==> TRUE
2.The SRD Register will be written with the next value to send from write buffer
TEST.END_NOTES:
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no5:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no6:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SE0:0xF1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]:0xB1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[1]:0x2A
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[2]:0x2A
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[3]:0x2A
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[0]:0xA7
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[1]:0x5A
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[2]:0x20
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[3]:0x30
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_bytes_to_send_mg:4
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_WBPosition_mg:4
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_CurMode_g:4
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_INTV10bit_min_g:0x0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_REGV_min_g:0x0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_LIN_INTV10bit_min_g:0x0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.rw_INTV10bit_max_g:0xFFFF
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.rw_REGV_max_g:0xFFFF
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.rw_LIN_INTV10bit_max_g:0xFFFF
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[0]:0xA7
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[1]:0x5A
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[2]:0x20
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[3]:0x30
TEST.END

-- Test Case: SPI_int.Read2ByteRain4
TEST.UNIT:G5_spi_sr
TEST.SUBPROGRAM:SPI_int
TEST.NEW
TEST.NAME:SPI_int.Read2ByteRain4
TEST.NOTES:
SPI_init

1.if (rb_SPI_WBPosition_mg < rb_SPI_bytes_to_send_mg) ==> TRUE
2.The SRD Register will be written with the next value to send from write buffer
TEST.END_NOTES:
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no5:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no6:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SE0:0xF1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]:0xB1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[1]:0x2A
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[2]:0x2A
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[3]:0x2A
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[0]:0xA7
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[1]:0x5A
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[2]:0x20
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[3]:0x30
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_bytes_to_send_mg:4
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_WBPosition_mg:4
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_CurMode_g:4
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_NextMUXCfg_g:0xFF
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_INTV10bit_min_g:0x0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_REGV_min_g:0x0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_LIN_INTV10bit_min_g:0x0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.rw_INTV10bit_max_g:0xFFFF
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.rw_REGV_max_g:0xFFFF
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.rw_LIN_INTV10bit_max_g:0xFFFF
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[0]:0xA7
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[1]:0x5A
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[2]:0x20
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[3]:0x30
TEST.END

-- Test Case: SPI_int.Read2ByteRain5
TEST.UNIT:G5_spi_sr
TEST.SUBPROGRAM:SPI_int
TEST.NEW
TEST.NAME:SPI_int.Read2ByteRain5
TEST.NOTES:
SPI_init

1.if (rb_SPI_WBPosition_mg < rb_SPI_bytes_to_send_mg) ==> TRUE
2.The SRD Register will be written with the next value to send from write buffer
TEST.END_NOTES:
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no5:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no6:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SE0:0xF1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]:0xA1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[1]:0x2A
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[2]:0x2A
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[3]:0x2A
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[0]:0xAF
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[1]:0x5A
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[2]:0x20
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[3]:0x20
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_bytes_to_send_mg:4
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_WBPosition_mg:4
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_CurMode_g:4
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_NextMUXCfg_g:0xFF
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_INTV10bit_min_g:0x0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_REGV_min_g:0x0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_LIN_INTV10bit_min_g:0x0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.rw_INTV10bit_max_g:0xFFFF
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.rw_REGV_max_g:0xFFFF
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.rw_LIN_INTV10bit_max_g:0xFFFF
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[0]:0xAF
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[1]:0x5A
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[2]:0x20
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[3]:0x20
TEST.END

-- Test Case: SPI_int.ReadID
TEST.UNIT:G5_spi_sr
TEST.SUBPROGRAM:SPI_int
TEST.NEW
TEST.NAME:SPI_int.ReadID
TEST.NOTES:
SPI:int SPI_int.ReadID
Inputs
Stub the function set_rad_SPI_ReadBuffer_mg
Set vc_SSR00_bit.no5 = 0 and vc_SSR00_bit.no6 =1
Set VC_SE0 = 0xF1
Set rab_SPI_WriteBuffer_mg = { 0xD0}
Set rab_SPI_ReadBuffer_mg = { 0x97,0x51,0x52,0x53 }
Set rb_SPI_bytes_to_send_mg = 3
Set rb_SPI_WBPosition_mg = 2
Set rb_ASIC_ID_g[] = {51,52,53}

Output
rb_ASIC_ID_g[] = {51,52,53}
TEST.END_NOTES:
TEST.STUB:G5_spi_sr.set_rab_SPI_ReadBuffer_mg
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no5:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no6:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SE0:0xF1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]:0xD0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[0]:0x97
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[1]:0x51
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[2]:0x52
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[3]:0x53
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_bytes_to_send_mg:3
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_WBPosition_mg:2
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_ASIC_ID_g[0]:0x0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_ASIC_ID_g[1]:0x0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_ASIC_ID_g[2]:0
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rb_ASIC_ID_g[0]:0x51
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rb_ASIC_ID_g[1]:0x52
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rb_ASIC_ID_g[2]:0x53
TEST.END

-- Test Case: SPI_int.SendNextByte
TEST.UNIT:G5_spi_sr
TEST.SUBPROGRAM:SPI_int
TEST.NEW
TEST.NAME:SPI_int.SendNextByte
TEST.NOTES:
SPI:int SPI_int.SendNextByte
Inputs
Stub the function set_rad_SPI_ReadBuffer_mg
Set vc_SSR00_bit.no5 = 0 and vc_SSR00_bit.no6 =0
Set VC_SE0 = 0xF1
Set rb_SPI_byts_to_send_mg = 3
Set rb_SPI_WBPosition_mg = 1
Output
Test
vc_SDR00 = 0x10FF
TEST.END_NOTES:
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no5:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no6:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SE0:0xF1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_bytes_to_send_mg:3
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_WBPosition_mg:1
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.vc_SDR00:0x10FF
TEST.END

-- Test Case: SPI_int.SpiError.001
TEST.UNIT:G5_spi_sr
TEST.SUBPROGRAM:SPI_int
TEST.NEW
TEST.NAME:SPI_int.SpiError.001
TEST.NOTES:
SPI:int SPI_int.SpiError1
Inputs
Stub the function set_rad_SPI_ReadBuffer_mg
Set vc_SSR00_bit.no5 = 0 and vc_SSR00_bit.no6 =1
Set VC_SE0 = 0xF1
Set rab_SPI_WriteBuffer_mg = { 0x22 }
Set rab_SPI_ReadBuffer_mg = { 0xEE}
Set rb_SPI_bytes_to_send_mg = 3
Set rb_SPI_WBPosition_mg = 2
Set rb_StaticNoCommunicationCounter_g = 0
TEST.END_NOTES:
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no5:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no6:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SE0:0xF1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_SPINoCommCounter_g:0xFF00
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_StaticNoCommunicationCounter_g:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]:0x22
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[0]:0xEE
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_bytes_to_send_mg:3
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_WBPosition_mg:2
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_firstReadComm_g:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_ASIC_SPI_ErrorFlag_g:0
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rb_StaticNoCommunicationCounter_g:1
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.uF_SPI_flags_g.Bit.B0:0
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.uF_Check_lightsensor_g.Bit.B3:1
TEST.ATTRIBUTES:G5_spi_sr.<<GLOBAL>>.rw_SPINoCommCounter_g:EXPECTED_BASE=16
TEST.END

-- Test Case: SPI_int.SpiError.002
TEST.UNIT:G5_spi_sr
TEST.SUBPROGRAM:SPI_int
TEST.NEW
TEST.NAME:SPI_int.SpiError.002
TEST.NOTES:
SPI:int SPI_int.SpiError2
Inputs
Stub the function set_rad_SPI_ReadBuffer_mg
Set vc_SSR00_bit.no5 = 0 and vc_SSR00_bit.no6 =1
Set VC_SE0 = 0xF1
Set rab_SPI_WriteBuffer_mg = { 0x22 }
Set rab_SPI_ReadBuffer_mg = { 0xEE}
Set rb_SPI_bytes_to_send_mg = 3
Set rb_SPI_WBPosition_mg = 2
Set rb_StaticNoCommunicationCounter_g = 0
Set rb_firstReadComm_g = 0
Set rb_ASIC_SPI_ErrorFlag_g = 1
Output
uF_Check_lightsensor_g . Bit . B3 = 1
TEST.END_NOTES:
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no5:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no6:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SE0:0xF1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rw_SPINoCommCounter_g:0xFF00
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]:0x22
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[0]:0xEE
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_bytes_to_send_mg:3
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_WBPosition_mg:2
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_firstReadComm_g:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_ASIC_SPI_ErrorFlag_g:1
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.uF_SPI_flags_g.Bit.B0:0
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.uF_Check_lightsensor_g.Bit.B3:1
TEST.ATTRIBUTES:G5_spi_sr.<<GLOBAL>>.rw_SPINoCommCounter_g:EXPECTED_BASE=16
TEST.END

-- Test Case: SPI_int.Write1Byte
TEST.UNIT:G5_spi_sr
TEST.SUBPROGRAM:SPI_int
TEST.NEW
TEST.NAME:SPI_int.Write1Byte
TEST.NOTES:
SPI:int SPI_int.Write1Byte
Inputs
Stub the function set_rad_SPI_ReadBuffer_mg
Set vc_SSR00_bit.no5 = 0 and vc_SSR00_bit.no6 =1
Set VC_SE0 = 0xF1
Set rab_SPI_WriteBuffer_mg = { 0x57,0xC8,0xC8,0x2A }
Set rab_SPI_ReadBuffer_mg = { 0xD4,0x9B,0x9B,0xEA }
Set rb_SPI_bytes_to_send_mg = 4
Set rb_SPI_WBPosition_mg = 4
Set rb_StaticNoCommunicationCounter_g = 0
rb_communication_retries_mg = 0

Output
Set uF_Check_lightsensor_g . Bit . B3 = 0
Set rb_StaticNoCommunicationCounter_g = 1
rb_communication_retries_mg = 1
TEST.END_NOTES:
TEST.STUB:G5_spi_sr.set_rab_SPI_ReadBuffer_mg
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no5:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no6:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SE0:0xF1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_StaticNoCommunicationCounter_g:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]:0x56
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[1]:0xC8
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[2]:0xC8
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[3]:0x2A
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[0]:0xD4
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[1]:0x9B
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[2]:0x9B
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[3]:0xEA
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_bytes_to_send_mg:4
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_WBPosition_mg:4
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_communication_retries_mg:0
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rb_StaticNoCommunicationCounter_g:1
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[0]:0xD4
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[1]:0x9B
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[2]:0x9B
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[3]:0xEA
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rb_communication_retries_mg:1
TEST.END

-- Test Case: SPI_int.Write1ByteError
TEST.UNIT:G5_spi_sr
TEST.SUBPROGRAM:SPI_int
TEST.NEW
TEST.NAME:SPI_int.Write1ByteError
TEST.NOTES:
SPI:int SPI_int.Write1ByteError
Inputs
Stub the function set_rad_SPI_ReadBuffer_mg
Set vc_SSR00_bit.no5 = 0 and vc_SSR00_bit.no6 =1
Set VC_SE0 = 0xF1
Set rab_SPI_WriteBuffer_mg = { 0x57,0xC8,0xC8,0x2A }
Set rab_SPI_ReadBuffer_mg = { 0xD4,0x9B,0x9B,0xEA }
Set rb_SPI_bytes_to_send_mg = 4
Set rb_SPI_WBPosition_mg = 4
Set rb_StaticNoCommunicationCounter_g = 0
rb_communication_retries_mg = 0

Output
Set uF_Check_lightsensor_g . Bit . B3 = 0
Set rb_StaticNoCommunicationCounter_g = 1
rb_communication_retries_mg = 1
TEST.END_NOTES:
TEST.STUB:G5_spi_sr.set_rab_SPI_ReadBuffer_mg
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no5:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no6:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SE0:0xF1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_StaticNoCommunicationCounter_g:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]:0x56
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[1]:0xC8
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[2]:0xC8
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[3]:0x2A
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[0]:0xD4
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[1]:0x9B
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[2]:0x9B
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[3]:0xEA
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_bytes_to_send_mg:4
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_WBPosition_mg:4
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_communication_retries_mg:0
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rb_StaticNoCommunicationCounter_g:1
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[0]:0xD4
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[1]:0x9B
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[2]:0x9B
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[3]:0xEA
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rb_communication_retries_mg:1
TEST.END

-- Test Case: SPI_int.Write2Byte
TEST.UNIT:G5_spi_sr
TEST.SUBPROGRAM:SPI_int
TEST.NEW
TEST.NAME:SPI_int.Write2Byte
TEST.NOTES:
SPI:int SPI_int.Write2Byte
Inputs
Stub the function set_rad_SPI_ReadBuffer_mg
Set vc_SSR00_bit.no5 = 0 and vc_SSR00_bit.no6 =1
Set VC_SE0 = 0xF1
Set rab_SPI_WriteBuffer_mg = { 0x57,0xC8,0xC8,0x2A }
Set rab_SPI_ReadBuffer_mg = { 0xD4,0x9B,0x9B,0xEA }
Set rb_SPI_bytes_to_send_mg = 4
Set rb_SPI_WBPosition_mg = 4
Set uF_Check_lightsensor_g . Bit . B3 = 1

Output
Set uF_Check_lightsensor_g . Bit . B3 = 0
TEST.END_NOTES:
TEST.STUB:G5_spi_sr.set_rab_SPI_ReadBuffer_mg
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no5:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no6:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SE0:0xF1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]:0x57
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[1]:0xC8
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[2]:0xC8
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[3]:0x2A
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[0]:0xD4
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[1]:0x9B
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[2]:0x9B
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[3]:0xEA
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_bytes_to_send_mg:4
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_WBPosition_mg:4
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.uF_Check_lightsensor_g.Bit.B3:1
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[0]:0xD4
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[1]:0x9B
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[2]:0x9B
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[3]:0xEA
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.uF_Check_lightsensor_g.Bit.B3:0
TEST.END

-- Test Case: SPI_int.WriteError1
TEST.UNIT:G5_spi_sr
TEST.SUBPROGRAM:SPI_int
TEST.NEW
TEST.NAME:SPI_int.WriteError1
TEST.NOTES:
SPI:int SPI_int.WriteError1
Inputs
Stub the function set_rad_SPI_ReadBuffer_mg
Set vc_SSR00_bit.no5 = 0 and vc_SSR00_bit.no6 =1
Set VC_SE0 = 0xF1
Set rab_SPI_WriteBuffer_mg = { 0x57,0xC8,0xC8,0x2A }
Set rab_SPI_ReadBuffer_mg = { 0xD4,0x9B,0x9A,0xEA }
Set rb_SPI_bytes_to_send_mg = 4
Set rb_SPI_WBPosition_mg = 4
Set rb_StaticNoCommunicationCounter_g = 0
rb_communication_retries_mg = 0
Output
rb_StaticNoCommunicationCounter_g =1
rb_communication_retries_mg = 1
TEST.END_NOTES:
TEST.STUB:G5_spi_sr.set_rab_SPI_ReadBuffer_mg
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no5:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no6:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SE0:0xF1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_StaticNoCommunicationCounter_g:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]:0x57
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[1]:0xC8
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[2]:0xC8
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[3]:0x2A
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[0]:0xD4
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[1]:0x9B
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[2]:0x9A
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[3]:0xEA
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_bytes_to_send_mg:4
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_WBPosition_mg:4
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_communication_retries_mg:0
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rb_StaticNoCommunicationCounter_g:1
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[0]:0xD4
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[1]:0x9B
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[2]:0x9A
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[3]:0xEA
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rb_communication_retries_mg:1
TEST.END

-- Test Case: SPI_int.WriteError2
TEST.UNIT:G5_spi_sr
TEST.SUBPROGRAM:SPI_int
TEST.NEW
TEST.NAME:SPI_int.WriteError2
TEST.NOTES:
SPI:int SPI_int.WriteError2
Inputs
Stub the function set_rad_SPI_ReadBuffer_mg
Set vc_SSR00_bit.no5 = 0 and vc_SSR00_bit.no6 =1
Set VC_SE0 = 0xF1
Set rab_SPI_WriteBuffer_mg = { 0x57,0xC8,0xC8,0x2A }
Set rab_SPI_ReadBuffer_mg = { 0xD4,0x9A,0x9B,0xEA }
Set rb_SPI_bytes_to_send_mg = 4
Set rb_SPI_WBPosition_mg = 4
Set rb_StaticNoCommunicationCounter_g = 0
rb_communication_retries_mg = 0
Output
rb_StaticNoCommunicationCounter_g =1
rb_communication_retries_mg = 1
TEST.END_NOTES:
TEST.STUB:G5_spi_sr.set_rab_SPI_ReadBuffer_mg
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no5:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no6:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SE0:0xF1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_StaticNoCommunicationCounter_g:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]:0x57
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[1]:0xC8
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[2]:0xC8
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[3]:0x2A
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[0]:0xD4
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[1]:0x9A
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[2]:0x9B
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[3]:0xEA
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_bytes_to_send_mg:4
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_SPI_WBPosition_mg:4
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_communication_retries_mg:0
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rb_StaticNoCommunicationCounter_g:1
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[0]:0xD4
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[1]:0x9A
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[2]:0x9B
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[3]:0xEA
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rb_communication_retries_mg:1
TEST.END

-- Subprogram: set_rab_SPI_ReadBuffer_mg

-- Test Case: Set_ReadBuff_MaxValue
TEST.UNIT:G5_spi_sr
TEST.SUBPROGRAM:set_rab_SPI_ReadBuffer_mg
TEST.NEW
TEST.NAME:Set_ReadBuff_MaxValue
TEST.NOTES:
set_rab_SPI_ReadBuffer_mg - Set_ReadBuff_MaxValue
-check whether the max buffer limit is set
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_spi_sr.set_rab_SPI_ReadBuffer_mg.rb_position_l:15
TEST.VALUE:G5_spi_sr.set_rab_SPI_ReadBuffer_mg.rb_Value_l:0xFF
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[15]:0xFF
TEST.EXPECTED:G5_spi_sr.set_rab_SPI_ReadBuffer_mg.rb_position_l:15
TEST.EXPECTED:G5_spi_sr.set_rab_SPI_ReadBuffer_mg.rb_Value_l:255
TEST.END

-- Test Case: Set_ReadBuff_MinValue
TEST.UNIT:G5_spi_sr
TEST.SUBPROGRAM:set_rab_SPI_ReadBuffer_mg
TEST.NEW
TEST.NAME:Set_ReadBuff_MinValue
TEST.NOTES:
set_rab_SPI_ReadBuffer_mg - Set_ReadBuff_MinValue
-check whether the min buffer limit is set
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_spi_sr.set_rab_SPI_ReadBuffer_mg.rb_position_l:0
TEST.VALUE:G5_spi_sr.set_rab_SPI_ReadBuffer_mg.rb_Value_l:0xFF
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rab_SPI_ReadBuffer_mg[0]:0xFF
TEST.EXPECTED:G5_spi_sr.set_rab_SPI_ReadBuffer_mg.rb_position_l:0
TEST.EXPECTED:G5_spi_sr.set_rab_SPI_ReadBuffer_mg.rb_Value_l:0xFF
TEST.END

-- Subprogram: set_rab_SPI_WriteBuffer_mg

-- Test Case: set_WriteBuff_MaxValue
TEST.UNIT:G5_spi_sr
TEST.SUBPROGRAM:set_rab_SPI_WriteBuffer_mg
TEST.NEW
TEST.NAME:set_WriteBuff_MaxValue
TEST.NOTES:
set_rab_SPI_WriteBuffer_mg - Set_WriteBuff_MaxValue
-check whether the max buffer limit is set
TEST.END_NOTES:
TEST.REQUIREMENT_KEY:194
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[15]:0
TEST.VALUE:G5_spi_sr.set_rab_SPI_WriteBuffer_mg.rb_position_l:15
TEST.VALUE:G5_spi_sr.set_rab_SPI_WriteBuffer_mg.rb_Value_l:255
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[15]:255
TEST.EXPECTED:G5_spi_sr.set_rab_SPI_WriteBuffer_mg.rb_position_l:15
TEST.EXPECTED:G5_spi_sr.set_rab_SPI_WriteBuffer_mg.rb_Value_l:255
TEST.END

-- Test Case: set_WriteBuff_MinValue
TEST.UNIT:G5_spi_sr
TEST.SUBPROGRAM:set_rab_SPI_WriteBuffer_mg
TEST.NEW
TEST.NAME:set_WriteBuff_MinValue
TEST.NOTES:
set_rab_SPI_WriteBuffer_mg - Set_WriteBuff_MinValue
-check whether the min buffer limit is set
TEST.END_NOTES:
TEST.REQUIREMENT_KEY:194
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]:0
TEST.VALUE:G5_spi_sr.set_rab_SPI_WriteBuffer_mg.rb_position_l:0
TEST.VALUE:G5_spi_sr.set_rab_SPI_WriteBuffer_mg.rb_Value_l:255
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rab_SPI_WriteBuffer_mg[0]:255
TEST.EXPECTED:G5_spi_sr.set_rab_SPI_WriteBuffer_mg.rb_position_l:0
TEST.EXPECTED:G5_spi_sr.set_rab_SPI_WriteBuffer_mg.rb_Value_l:0xFF
TEST.END

-- Subprogram: set_rb_ASIC_SPI_ErrorFlag_g

-- Test Case: set_FALSE
TEST.UNIT:G5_spi_sr
TEST.SUBPROGRAM:set_rb_ASIC_SPI_ErrorFlag_g
TEST.NEW
TEST.NAME:set_FALSE
TEST.REQUIREMENT_KEY:189
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_ASIC_SPI_ErrorFlag_g:1
TEST.VALUE:G5_spi_sr.set_rb_ASIC_SPI_ErrorFlag_g.a:0
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rb_ASIC_SPI_ErrorFlag_g:0
TEST.EXPECTED:G5_spi_sr.set_rb_ASIC_SPI_ErrorFlag_g.a:0
TEST.END

-- Test Case: set_TRUE
TEST.UNIT:G5_spi_sr
TEST.SUBPROGRAM:set_rb_ASIC_SPI_ErrorFlag_g
TEST.NEW
TEST.NAME:set_TRUE
TEST.REQUIREMENT_KEY:189
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_ASIC_SPI_ErrorFlag_g:0
TEST.VALUE:G5_spi_sr.set_rb_ASIC_SPI_ErrorFlag_g.a:1
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rb_ASIC_SPI_ErrorFlag_g:1
TEST.EXPECTED:G5_spi_sr.set_rb_ASIC_SPI_ErrorFlag_g.a:1
TEST.END

-- Subprogram: spi_CommunicationFaultHandl

-- Test Case: MaximumRetry
TEST.UNIT:G5_spi_sr
TEST.SUBPROGRAM:spi_CommunicationFaultHandl
TEST.NEW
TEST.NAME:MaximumRetry
TEST.NOTES:
spi_CommunicationFaultHandl - Maximum Retry
-Check whether retry counter is incremented.
-SPI is initialised (spi bus aktiv is reset)
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no5:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no6:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SE0:0x1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.uF_SPI_flags_g.Bit.B0:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_communication_retries_mg:3
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no5:0
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no6:0
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.vc_SE0:0x1
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.uF_SPI_flags_g.Bit.B0:0
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rb_communication_retries_mg:4
TEST.END

-- Test Case: NormalRetry
TEST.UNIT:G5_spi_sr
TEST.SUBPROGRAM:spi_CommunicationFaultHandl
TEST.NEW
TEST.NAME:NormalRetry
TEST.NOTES:
spi_CommunicationFaultHandl - Normal Retry
Scope:
-To check whether the retry counter is incremented.
-SPI start Flags are set
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:FALSE
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no5:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no6:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_SE0:0x1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.uF_SPI_flags_g.Bit.B0:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_communication_retries_mg:2
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no5:0
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.vc_SSR00_bit.no6:0
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.vc_SE0:0x1
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.uF_SPI_flags_g.Bit.B0:1
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rb_communication_retries_mg:3
TEST.END

-- Test Case: RetryExceeded
TEST.UNIT:G5_spi_sr
TEST.SUBPROGRAM:spi_CommunicationFaultHandl
TEST.NEW
TEST.NAME:RetryExceeded
TEST.NOTES:
spi_CommunicationFaultHandl - RetryExceeded.
- check the retry counter.
- check wheather SPI bus active flag is reset.
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.uF_SPI_flags_g.Bit.B0:1
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.rb_communication_retries_mg:4
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.uF_SPI_flags_g.Bit.B0:0
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.rb_communication_retries_mg:4
TEST.END

-- Subprogram: spi_init

-- Test Case: spi_init
TEST.UNIT:G5_spi_sr
TEST.SUBPROGRAM:spi_init
TEST.NEW
TEST.NAME:spi_init
TEST.NOTES:
void spi_init(void) test:
User Prefix Code to test P1_bit and P14_bit
TEST.END_NOTES:
TEST.REQUIREMENT_KEY:185
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_P14_bit.no7:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_P1_bit.no0:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.vc_P1_bit.no2:0
TEST.VALUE:G5_spi_sr.<<GLOBAL>>.uF_SPI_flags_g.Bit.B0:1
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.vc_P14_bit.no7:1
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.vc_P1_bit.no0:1
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.vc_P1_bit.no2:1
TEST.EXPECTED:G5_spi_sr.<<GLOBAL>>.uF_SPI_flags_g.Bit.B0:0
TEST.END
