-- VectorCAST 6.2n
-- Test Case Script
-- 
-- Environment    : G5_DIPPEDBEAM_SR
-- Unit(s) Under Test: G5_DippedBeam_sr
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Subprogram: <<INIT>>

-- Test Case: <<INIT>>.001
TEST.SUBPROGRAM:<<INIT>>
TEST.NEW
TEST.NAME:<<INIT>>.001
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:FALSE
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.rb_LightVetoCounter_g:5
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.rb_LightVetoCounter_g:5
TEST.END

-- Unit: G5_DippedBeam_sr

-- Subprogram: get_rb_LightVetoCounter_g

-- Test Case: returnLightVetorCounter
TEST.UNIT:G5_DippedBeam_sr
TEST.SUBPROGRAM:get_rb_LightVetoCounter_g
TEST.NEW
TEST.NAME:returnLightVetorCounter
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.rb_LightVetoCounter_g:<<MAX>>
TEST.VALUE:G5_DippedBeam_sr.get_rb_LightVetoCounter_g.return:<<MAX>>
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.rb_LightVetoCounter_g:<<MAX>>
TEST.EXPECTED:G5_DippedBeam_sr.get_rb_LightVetoCounter_g.return:<<MAX>>
TEST.END

-- Subprogram: light_VetoForLightOff

-- Test Case: allThresholdsFalse.01
TEST.UNIT:G5_DippedBeam_sr
TEST.SUBPROGRAM:light_VetoForLightOff
TEST.NEW
TEST.NAME:allThresholdsFalse.01
TEST.BASIS_PATH:1 of 3
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (((((get_rw_Amb_light16bit_g() < utest_cab_AMB_SECURE_DAY_THRESHOLD_s || get_rw_IR_light16bit_g() < utest_IR_SECURE_DAY_THRESHOLD_s) || get_rw_FW_light16bit_g() < utest_FW_SECURE_DAY_THRESHOLD_s) || get_rw_Amb_INC_light16bit_g() < utest_cab_AMB_SECURE_DAY_THRESHOLD_s) || get_rw_IR_INC_light16bit_g() 
< utest_IR_SECURE_DAY_THRESHOLD_s) || get_rw_FW_INC_light16bit_g() < utest_FW_SECURE_DAY_THRESHOLD_s) ==> FALSE
      (2) if (rb_LightVetoCounter_g > 0) ==> FALSE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.utest_IR_SECURE_DAY_THRESHOLD_s:<<MIN>>
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.utest_cab_AMB_SECURE_DAY_THRESHOLD_s:<<MIN>>
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.utest_FW_SECURE_DAY_THRESHOLD_s:<<MIN>>
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.rb_LightVetoCounter_g:<<MIN>>
TEST.VALUE:uut_prototype_stubs.get_rw_Amb_light16bit_g.return:<<MAX>>
TEST.VALUE:uut_prototype_stubs.get_rw_FW_light16bit_g.return:<<MAX>>
TEST.VALUE:uut_prototype_stubs.get_rw_IR_light16bit_g.return:<<MAX>>
TEST.VALUE:uut_prototype_stubs.get_rw_Amb_INC_light16bit_g.return:<<MAX>>
TEST.VALUE:uut_prototype_stubs.get_rw_FW_INC_light16bit_g.return:<<MAX>>
TEST.VALUE:uut_prototype_stubs.get_rw_IR_INC_light16bit_g.return:<<MAX>>
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.utest_IR_SECURE_DAY_THRESHOLD_s:<<MIN>>
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.utest_cab_AMB_SECURE_DAY_THRESHOLD_s:<<MIN>>
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.utest_FW_SECURE_DAY_THRESHOLD_s:<<MIN>>
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.rb_LightVetoCounter_g:<<MIN>>
TEST.END

-- Test Case: allThresholdsFalse.02
TEST.UNIT:G5_DippedBeam_sr
TEST.SUBPROGRAM:light_VetoForLightOff
TEST.NEW
TEST.NAME:allThresholdsFalse.02
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (((((get_rw_Amb_light16bit_g() < utest_cab_AMB_SECURE_DAY_THRESHOLD_s || get_rw_IR_light16bit_g() < utest_IR_SECURE_DAY_THRESHOLD_s) || get_rw_FW_light16bit_g() < utest_FW_SECURE_DAY_THRESHOLD_s) || get_rw_Amb_INC_light16bit_g() < utest_cab_AMB_SECURE_DAY_THRESHOLD_s) || get_rw_IR_INC_light16bit_g() 
< utest_IR_SECURE_DAY_THRESHOLD_s) || get_rw_FW_INC_light16bit_g() < utest_FW_SECURE_DAY_THRESHOLD_s) ==> FALSE
      (2) if (rb_LightVetoCounter_g > 0) ==> FALSE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.utest_IR_SECURE_DAY_THRESHOLD_s:<<MIN>>
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.utest_cab_AMB_SECURE_DAY_THRESHOLD_s:<<MIN>>
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.utest_FW_SECURE_DAY_THRESHOLD_s:<<MIN>>
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.rb_LightVetoCounter_g:2
TEST.VALUE:uut_prototype_stubs.get_rw_Amb_light16bit_g.return:<<MAX>>
TEST.VALUE:uut_prototype_stubs.get_rw_FW_light16bit_g.return:<<MAX>>
TEST.VALUE:uut_prototype_stubs.get_rw_IR_light16bit_g.return:<<MAX>>
TEST.VALUE:uut_prototype_stubs.get_rw_Amb_INC_light16bit_g.return:<<MAX>>
TEST.VALUE:uut_prototype_stubs.get_rw_FW_INC_light16bit_g.return:<<MAX>>
TEST.VALUE:uut_prototype_stubs.get_rw_IR_INC_light16bit_g.return:<<MAX>>
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.utest_IR_SECURE_DAY_THRESHOLD_s:<<MIN>>
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.utest_cab_AMB_SECURE_DAY_THRESHOLD_s:<<MIN>>
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.utest_FW_SECURE_DAY_THRESHOLD_s:<<MIN>>
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.rb_LightVetoCounter_g:1
TEST.END

-- Test Case: allThresholdsFalse.03
TEST.UNIT:G5_DippedBeam_sr
TEST.SUBPROGRAM:light_VetoForLightOff
TEST.NEW
TEST.NAME:allThresholdsFalse.03
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (((((get_rw_Amb_light16bit_g() < utest_cab_AMB_SECURE_DAY_THRESHOLD_s || get_rw_IR_light16bit_g() < utest_IR_SECURE_DAY_THRESHOLD_s) || get_rw_FW_light16bit_g() < utest_FW_SECURE_DAY_THRESHOLD_s) || get_rw_Amb_INC_light16bit_g() < utest_cab_AMB_SECURE_DAY_THRESHOLD_s) || get_rw_IR_INC_light16bit_g() 
< utest_IR_SECURE_DAY_THRESHOLD_s) || get_rw_FW_INC_light16bit_g() < utest_FW_SECURE_DAY_THRESHOLD_s) ==> FALSE
      (2) if (rb_LightVetoCounter_g > 0) ==> FALSE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.utest_IR_SECURE_DAY_THRESHOLD_s:<<MIN>>
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.utest_cab_AMB_SECURE_DAY_THRESHOLD_s:<<MIN>>
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.utest_FW_SECURE_DAY_THRESHOLD_s:<<MIN>>
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.rb_LightVetoCounter_g:1
TEST.VALUE:uut_prototype_stubs.get_rw_Amb_light16bit_g.return:<<MAX>>
TEST.VALUE:uut_prototype_stubs.get_rw_FW_light16bit_g.return:<<MAX>>
TEST.VALUE:uut_prototype_stubs.get_rw_IR_light16bit_g.return:<<MAX>>
TEST.VALUE:uut_prototype_stubs.get_rw_Amb_INC_light16bit_g.return:<<MAX>>
TEST.VALUE:uut_prototype_stubs.get_rw_FW_INC_light16bit_g.return:<<MAX>>
TEST.VALUE:uut_prototype_stubs.get_rw_IR_INC_light16bit_g.return:<<MAX>>
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.utest_IR_SECURE_DAY_THRESHOLD_s:<<MIN>>
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.utest_cab_AMB_SECURE_DAY_THRESHOLD_s:<<MIN>>
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.utest_FW_SECURE_DAY_THRESHOLD_s:<<MIN>>
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.rb_LightVetoCounter_g:0
TEST.END

-- Test Case: secureAMBIncThresholdTrue
TEST.UNIT:G5_DippedBeam_sr
TEST.SUBPROGRAM:light_VetoForLightOff
TEST.NEW
TEST.NAME:secureAMBIncThresholdTrue
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) if (((((get_rw_Amb_light16bit_g() < utest_cab_AMB_SECURE_DAY_THRESHOLD_s || get_rw_IR_light16bit_g() < utest_IR_SECURE_DAY_THRESHOLD_s) || get_rw_FW_light16bit_g() < utest_FW_SECURE_DAY_THRESHOLD_s) || get_rw_Amb_INC_light16bit_g() < utest_cab_AMB_SECURE_DAY_THRESHOLD_s) || get_rw_IR_INC_light16bit_g() 
< utest_IR_SECURE_DAY_THRESHOLD_s) || get_rw_FW_INC_light16bit_g() < utest_FW_SECURE_DAY_THRESHOLD_s) ==> TRUE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.utest_AFTERTUNNEL_DELAY_s:30
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.utest_IR_SECURE_DAY_THRESHOLD_s:<<MID>>
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.utest_cab_AMB_SECURE_DAY_THRESHOLD_s:<<MID>>
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.utest_FW_SECURE_DAY_THRESHOLD_s:<<MID>>
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.rb_LightVetoCounter_g:<<MAX>>
TEST.VALUE:uut_prototype_stubs.get_rw_Amb_light16bit_g.return:0x7F
TEST.VALUE:uut_prototype_stubs.get_rw_FW_light16bit_g.return:0x7F
TEST.VALUE:uut_prototype_stubs.get_rw_IR_light16bit_g.return:0x7F
TEST.VALUE:uut_prototype_stubs.get_rw_Amb_INC_light16bit_g.return:0x7E
TEST.VALUE:uut_prototype_stubs.get_rw_FW_INC_light16bit_g.return:0x7F
TEST.VALUE:uut_prototype_stubs.get_rw_IR_INC_light16bit_g.return:0x7F
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.utest_AFTERTUNNEL_DELAY_s:30
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.utest_IR_SECURE_DAY_THRESHOLD_s:0x7F
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.utest_cab_AMB_SECURE_DAY_THRESHOLD_s:0x7F
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.utest_FW_SECURE_DAY_THRESHOLD_s:0x7F
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.rb_LightVetoCounter_g:27
TEST.END

-- Test Case: secureAMBThresholdTrue
TEST.UNIT:G5_DippedBeam_sr
TEST.SUBPROGRAM:light_VetoForLightOff
TEST.NEW
TEST.NAME:secureAMBThresholdTrue
TEST.BASIS_PATH:3 of 3
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) if (((((get_rw_Amb_light16bit_g() < utest_cab_AMB_SECURE_DAY_THRESHOLD_s || get_rw_IR_light16bit_g() < utest_IR_SECURE_DAY_THRESHOLD_s) || get_rw_FW_light16bit_g() < utest_FW_SECURE_DAY_THRESHOLD_s) || get_rw_Amb_INC_light16bit_g() < utest_cab_AMB_SECURE_DAY_THRESHOLD_s) || get_rw_IR_INC_light16bit_g() 
< utest_IR_SECURE_DAY_THRESHOLD_s) || get_rw_FW_INC_light16bit_g() < utest_FW_SECURE_DAY_THRESHOLD_s) ==> TRUE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.utest_AFTERTUNNEL_DELAY_s:2
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.utest_IR_SECURE_DAY_THRESHOLD_s:<<MID>>
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.utest_cab_AMB_SECURE_DAY_THRESHOLD_s:<<MID>>
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.utest_FW_SECURE_DAY_THRESHOLD_s:<<MID>>
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.rb_LightVetoCounter_g:<<MAX>>
TEST.VALUE:uut_prototype_stubs.get_rw_Amb_light16bit_g.return:0x7E
TEST.VALUE:uut_prototype_stubs.get_rw_FW_light16bit_g.return:0x7F
TEST.VALUE:uut_prototype_stubs.get_rw_IR_light16bit_g.return:0x7F
TEST.VALUE:uut_prototype_stubs.get_rw_Amb_INC_light16bit_g.return:0x7F
TEST.VALUE:uut_prototype_stubs.get_rw_FW_INC_light16bit_g.return:0x7F
TEST.VALUE:uut_prototype_stubs.get_rw_IR_INC_light16bit_g.return:0x7F
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.utest_AFTERTUNNEL_DELAY_s:2
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.utest_IR_SECURE_DAY_THRESHOLD_s:0x7F
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.utest_cab_AMB_SECURE_DAY_THRESHOLD_s:0x7F
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.utest_FW_SECURE_DAY_THRESHOLD_s:0x7F
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.rb_LightVetoCounter_g:<<MAX>>
TEST.END

-- Test Case: secureFWIncThresholdTrue
TEST.UNIT:G5_DippedBeam_sr
TEST.SUBPROGRAM:light_VetoForLightOff
TEST.NEW
TEST.NAME:secureFWIncThresholdTrue
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) if (((((get_rw_Amb_light16bit_g() < utest_cab_AMB_SECURE_DAY_THRESHOLD_s || get_rw_IR_light16bit_g() < utest_IR_SECURE_DAY_THRESHOLD_s) || get_rw_FW_light16bit_g() < utest_FW_SECURE_DAY_THRESHOLD_s) || get_rw_Amb_INC_light16bit_g() < utest_cab_AMB_SECURE_DAY_THRESHOLD_s) || get_rw_IR_INC_light16bit_g() 
< utest_IR_SECURE_DAY_THRESHOLD_s) || get_rw_FW_INC_light16bit_g() < utest_FW_SECURE_DAY_THRESHOLD_s) ==> TRUE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.utest_AFTERTUNNEL_DELAY_s:30
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.utest_IR_SECURE_DAY_THRESHOLD_s:<<MID>>
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.utest_cab_AMB_SECURE_DAY_THRESHOLD_s:<<MID>>
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.utest_FW_SECURE_DAY_THRESHOLD_s:<<MID>>
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.rb_LightVetoCounter_g:<<MAX>>
TEST.VALUE:uut_prototype_stubs.get_rw_Amb_light16bit_g.return:0x7F
TEST.VALUE:uut_prototype_stubs.get_rw_FW_light16bit_g.return:0x7F
TEST.VALUE:uut_prototype_stubs.get_rw_IR_light16bit_g.return:0x7F
TEST.VALUE:uut_prototype_stubs.get_rw_Amb_INC_light16bit_g.return:0x7F
TEST.VALUE:uut_prototype_stubs.get_rw_FW_INC_light16bit_g.return:0x7E
TEST.VALUE:uut_prototype_stubs.get_rw_IR_INC_light16bit_g.return:0x7F
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.utest_AFTERTUNNEL_DELAY_s:30
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.utest_IR_SECURE_DAY_THRESHOLD_s:0x7F
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.utest_cab_AMB_SECURE_DAY_THRESHOLD_s:0x7F
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.utest_FW_SECURE_DAY_THRESHOLD_s:0x7F
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.rb_LightVetoCounter_g:27
TEST.END

-- Test Case: secureFWThresholdTrue
TEST.UNIT:G5_DippedBeam_sr
TEST.SUBPROGRAM:light_VetoForLightOff
TEST.NEW
TEST.NAME:secureFWThresholdTrue
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) if (((((get_rw_Amb_light16bit_g() < utest_cab_AMB_SECURE_DAY_THRESHOLD_s || get_rw_IR_light16bit_g() < utest_IR_SECURE_DAY_THRESHOLD_s) || get_rw_FW_light16bit_g() < utest_FW_SECURE_DAY_THRESHOLD_s) || get_rw_Amb_INC_light16bit_g() < utest_cab_AMB_SECURE_DAY_THRESHOLD_s) || get_rw_IR_INC_light16bit_g() 
< utest_IR_SECURE_DAY_THRESHOLD_s) || get_rw_FW_INC_light16bit_g() < utest_FW_SECURE_DAY_THRESHOLD_s) ==> TRUE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.utest_AFTERTUNNEL_DELAY_s:30
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.utest_IR_SECURE_DAY_THRESHOLD_s:<<MID>>
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.utest_cab_AMB_SECURE_DAY_THRESHOLD_s:<<MID>>
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.utest_FW_SECURE_DAY_THRESHOLD_s:<<MID>>
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.rb_LightVetoCounter_g:<<MAX>>
TEST.VALUE:uut_prototype_stubs.get_rw_Amb_light16bit_g.return:0x7F
TEST.VALUE:uut_prototype_stubs.get_rw_FW_light16bit_g.return:0x7E
TEST.VALUE:uut_prototype_stubs.get_rw_IR_light16bit_g.return:0x7F
TEST.VALUE:uut_prototype_stubs.get_rw_Amb_INC_light16bit_g.return:0x7F
TEST.VALUE:uut_prototype_stubs.get_rw_FW_INC_light16bit_g.return:0x7F
TEST.VALUE:uut_prototype_stubs.get_rw_IR_INC_light16bit_g.return:0x7F
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.utest_AFTERTUNNEL_DELAY_s:30
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.utest_IR_SECURE_DAY_THRESHOLD_s:0x7F
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.utest_cab_AMB_SECURE_DAY_THRESHOLD_s:0x7F
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.utest_FW_SECURE_DAY_THRESHOLD_s:0x7F
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.rb_LightVetoCounter_g:27
TEST.END

-- Test Case: secureIRIncThresholdTrue
TEST.UNIT:G5_DippedBeam_sr
TEST.SUBPROGRAM:light_VetoForLightOff
TEST.NEW
TEST.NAME:secureIRIncThresholdTrue
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) if (((((get_rw_Amb_light16bit_g() < utest_cab_AMB_SECURE_DAY_THRESHOLD_s || get_rw_IR_light16bit_g() < utest_IR_SECURE_DAY_THRESHOLD_s) || get_rw_FW_light16bit_g() < utest_FW_SECURE_DAY_THRESHOLD_s) || get_rw_Amb_INC_light16bit_g() < utest_cab_AMB_SECURE_DAY_THRESHOLD_s) || get_rw_IR_INC_light16bit_g() 
< utest_IR_SECURE_DAY_THRESHOLD_s) || get_rw_FW_INC_light16bit_g() < utest_FW_SECURE_DAY_THRESHOLD_s) ==> TRUE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.utest_AFTERTUNNEL_DELAY_s:30
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.utest_IR_SECURE_DAY_THRESHOLD_s:<<MID>>
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.utest_cab_AMB_SECURE_DAY_THRESHOLD_s:<<MID>>
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.utest_FW_SECURE_DAY_THRESHOLD_s:<<MID>>
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.rb_LightVetoCounter_g:<<MAX>>
TEST.VALUE:uut_prototype_stubs.get_rw_Amb_light16bit_g.return:0x7F
TEST.VALUE:uut_prototype_stubs.get_rw_FW_light16bit_g.return:0x7F
TEST.VALUE:uut_prototype_stubs.get_rw_IR_light16bit_g.return:0x7F
TEST.VALUE:uut_prototype_stubs.get_rw_Amb_INC_light16bit_g.return:0x7F
TEST.VALUE:uut_prototype_stubs.get_rw_FW_INC_light16bit_g.return:0x7F
TEST.VALUE:uut_prototype_stubs.get_rw_IR_INC_light16bit_g.return:0x7E
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.utest_AFTERTUNNEL_DELAY_s:30
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.utest_IR_SECURE_DAY_THRESHOLD_s:0x7F
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.utest_cab_AMB_SECURE_DAY_THRESHOLD_s:0x7F
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.utest_FW_SECURE_DAY_THRESHOLD_s:0x7F
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.rb_LightVetoCounter_g:27
TEST.END

-- Test Case: secureIRThresholdTrue
TEST.UNIT:G5_DippedBeam_sr
TEST.SUBPROGRAM:light_VetoForLightOff
TEST.NEW
TEST.NAME:secureIRThresholdTrue
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) if (((((get_rw_Amb_light16bit_g() < utest_cab_AMB_SECURE_DAY_THRESHOLD_s || get_rw_IR_light16bit_g() < utest_IR_SECURE_DAY_THRESHOLD_s) || get_rw_FW_light16bit_g() < utest_FW_SECURE_DAY_THRESHOLD_s) || get_rw_Amb_INC_light16bit_g() < utest_cab_AMB_SECURE_DAY_THRESHOLD_s) || get_rw_IR_INC_light16bit_g() 
< utest_IR_SECURE_DAY_THRESHOLD_s) || get_rw_FW_INC_light16bit_g() < utest_FW_SECURE_DAY_THRESHOLD_s) ==> TRUE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.utest_AFTERTUNNEL_DELAY_s:30
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.utest_IR_SECURE_DAY_THRESHOLD_s:<<MID>>
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.utest_cab_AMB_SECURE_DAY_THRESHOLD_s:<<MID>>
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.utest_FW_SECURE_DAY_THRESHOLD_s:<<MID>>
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.rb_LightVetoCounter_g:<<MAX>>
TEST.VALUE:uut_prototype_stubs.get_rw_Amb_light16bit_g.return:0x7F
TEST.VALUE:uut_prototype_stubs.get_rw_FW_light16bit_g.return:0x7F
TEST.VALUE:uut_prototype_stubs.get_rw_IR_light16bit_g.return:0x7E
TEST.VALUE:uut_prototype_stubs.get_rw_Amb_INC_light16bit_g.return:0x7F
TEST.VALUE:uut_prototype_stubs.get_rw_FW_INC_light16bit_g.return:0x7F
TEST.VALUE:uut_prototype_stubs.get_rw_IR_INC_light16bit_g.return:0x7F
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.utest_AFTERTUNNEL_DELAY_s:30
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.utest_IR_SECURE_DAY_THRESHOLD_s:0x7F
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.utest_cab_AMB_SECURE_DAY_THRESHOLD_s:0x7F
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.utest_FW_SECURE_DAY_THRESHOLD_s:0x7F
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.rb_LightVetoCounter_g:27
TEST.END

-- Subprogram: light_evaluation

-- Test Case: darkStartCounterFalse.01
TEST.UNIT:G5_DippedBeam_sr
TEST.SUBPROGRAM:light_evaluation
TEST.NEW
TEST.NAME:darkStartCounterFalse.01
TEST.BASIS_PATH:4 of 11
TEST.NOTES:
This is an automatically generated test case.
   Test Path 4
      (1) if ((uF_LightInternalStatus_g.Bit).B2 == 0) ==> TRUE
      (2) if (rb_PosSlopeCountFWLight_mg > 0) ==> TRUE
      (3) if (rb_DARKSTARTDELAYCOUNTER_mg > 0) ==> FALSE
      (9) if (get_rw_IR_light16bit_g() < (byte)5 * (((EEPROM_Struct_AD.EEPROMStructAD).RainNightBitThrs_g >> 4) + 1)) ==> FALSE
      (10) if (255 != uF_modi_lightsens_g.AllBit + uF_modi_lightsens_inv_g.AllBit) ==> FALSE
   Test Case Generation Notes:
      Conflict: Unable to validate expression-to-expression comparison in branch 10
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.my_CB_AMBLIGHT_100lx:5
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.rb_PosSlopeCountFWLight_mg:<<MAX>>
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.rb_DARKSTARTDELAYCOUNTER_mg:<<MIN>>
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.RainNightBitThrs_g:<<MAX>>
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.rb_WDG_LightsensorTaskCounter_g:1
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.uF_modi_lightsens_g.AllBit:105
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.uF_modi_lightsens_inv_g.AllBit:150
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B2:0
TEST.VALUE:uut_prototype_stubs.get_rw_IR_light16bit_g.return:80
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.my_CB_AMBLIGHT_100lx:5
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.rb_PosSlopeCountFWLight_mg:<<MAX>>
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.RainNightBitThrs_g:<<MAX>>
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.rb_WDG_LightsensorTaskCounter_g:2
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B0:1
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B2:0
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B3:0
TEST.END

-- Test Case: darkStartCounterFalse.02
TEST.UNIT:G5_DippedBeam_sr
TEST.SUBPROGRAM:light_evaluation
TEST.NEW
TEST.NAME:darkStartCounterFalse.02
TEST.BASIS_PATH:5 of 11
TEST.NOTES:
This is an automatically generated test case.
   Test Path 5
      (1) if ((uF_LightInternalStatus_g.Bit).B2 == 0) ==> TRUE
      (2) if (rb_PosSlopeCountFWLight_mg > 0) ==> TRUE
      (3) if (rb_DARKSTARTDELAYCOUNTER_mg > 0) ==> FALSE
      (9) if (get_rw_IR_light16bit_g() < (byte)5 * (((EEPROM_Struct_AD.EEPROMStructAD).RainNightBitThrs_g >> 4) + 1)) ==> TRUE
      (10) if (255 != uF_modi_lightsens_g.AllBit + uF_modi_lightsens_inv_g.AllBit) ==> FALSE
   Test Case Generation Notes:
      Conflict: Unable to validate expression-to-expression comparison in branch 10
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.my_CB_AMBLIGHT_100lx:5
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.rb_PosSlopeCountFWLight_mg:<<MAX>>
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.rb_DARKSTARTDELAYCOUNTER_mg:<<MIN>>
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.RainNightBitThrs_g:<<MAX>>
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.rb_WDG_LightsensorTaskCounter_g:1
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.uF_modi_lightsens_g.AllBit:105
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.uF_modi_lightsens_inv_g.AllBit:150
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B2:0
TEST.VALUE:uut_prototype_stubs.get_rw_IR_light16bit_g.return:79
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.my_CB_AMBLIGHT_100lx:5
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.rb_PosSlopeCountFWLight_mg:<<MAX>>
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.rb_DARKSTARTDELAYCOUNTER_mg:<<MIN>>
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.EEPROM_Struct_AD.EEPROMStructAD.RainNightBitThrs_g:<<MAX>>
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.rb_WDG_LightsensorTaskCounter_g:2
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B0:1
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B2:0
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B3:1
TEST.END

-- Test Case: darkStartVoltageStatus.01
TEST.UNIT:G5_DippedBeam_sr
TEST.SUBPROGRAM:light_evaluation
TEST.NEW
TEST.NAME:darkStartVoltageStatus.01
TEST.BASIS_PATH:8 of 11
TEST.NOTES:
This is an automatically generated test case.
   Test Path 8
      (1) if ((uF_LightInternalStatus_g.Bit).B2 == 0) ==> TRUE
      (2) if (rb_PosSlopeCountFWLight_mg > 0) ==> TRUE
      (3) if (rb_DARKSTARTDELAYCOUNTER_mg > 0) ==> TRUE
      (4) if ((rb_AfterVddPowerFailDelay_g | (uF_VoltageStatus_g.Bit).B1) > 0) ==> FALSE
      (5) if ((uF_ASIC_ControlFlags_g.Bit).B1 == 1 && 1 == 1) ==> FALSE
      (6) if (rb_StartLightEvaluation_s > 250) ==> TRUE
      (7) if (rb_AfterVddPowerFailDelay_g == 0) ==> TRUE
      (8) if (get_rw_Amb_light16bit_g() < (2048)) ==> FALSE
      (10) if (255 != uF_modi_lightsens_g.AllBit + uF_modi_lightsens_inv_g.AllBit) ==> FALSE
   Test Case Generation Notes:
      Conflict: Unable to validate expression-to-expression comparison in branch 4
      Cannot set local variable rb_StartLightEvaluation_s in branch 6
      Conflict: Unable to validate expression-to-expression comparison in branch 10
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.uF_VoltageStatus_g.Bit.B1:<<MIN>>
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.rb_PosSlopeCountFWLight_mg:<<MAX>>
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.rb_DARKSTARTDELAYCOUNTER_mg:<<MAX>>
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.uF_ASIC_ControlFlags_g.Bit.B1:<<MIN>>
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.rb_FwLightDiv4_g:2
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.rb_AfterVddPowerFailDelay_g:0
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.rb_WDG_LightsensorTaskCounter_g:0
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.uF_modi_lightsens_g.AllBit:155
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.uF_modi_lightsens_inv_g.AllBit:155
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B0:1
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B2:0
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B7:0
TEST.VALUE:uut_prototype_stubs.get_rw_Amb_light16bit_g.return:<<MAX>>
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.uF_VoltageStatus_g.Bit.B1:<<MIN>>
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.rb_PosSlopeCountFWLight_mg:<<MAX>>
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.rb_DARKSTARTDELAYCOUNTER_mg:0x0
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.uF_ASIC_ControlFlags_g.Bit.B1:<<MIN>>
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.rb_FwLightDiv4_g:2
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.rb_WDG_LightsensorTaskCounter_g:252
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.rw_AmbLightMul32MeanSlow_g:65280
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.rw_AmbLightMul32MeanFast_g:65280
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.rw_FwLightMul64MeanFast_g:512
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.rw_FwLightMul64MeanSlow_g:512
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B0:0
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B2:0
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B7:1
TEST.VALUE_USER_CODE:<<testcase>>
int i;
for (i=1; i<=251; i++)
{
  light_evaluation();
}
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: darkStartVoltageStatus.02
TEST.UNIT:G5_DippedBeam_sr
TEST.SUBPROGRAM:light_evaluation
TEST.NEW
TEST.NAME:darkStartVoltageStatus.02
TEST.BASIS_PATH:9 of 11
TEST.NOTES:
This is an automatically generated test case.
   Test Path 9
      (1) if ((uF_LightInternalStatus_g.Bit).B2 == 0) ==> TRUE
      (2) if (rb_PosSlopeCountFWLight_mg > 0) ==> TRUE
      (3) if (rb_DARKSTARTDELAYCOUNTER_mg > 0) ==> TRUE
      (4) if ((rb_AfterVddPowerFailDelay_g | (uF_VoltageStatus_g.Bit).B1) > 0) ==> TRUE
      (5) if ((uF_ASIC_ControlFlags_g.Bit).B1 == 1 && 1 == 1) ==> FALSE
      (6) if (rb_StartLightEvaluation_s > 250) ==> TRUE
      (7) if (rb_AfterVddPowerFailDelay_g == 0) ==> FALSE
      (8) if (get_rw_Amb_light16bit_g() < (2048)) ==> FALSE
      (10) if (255 != uF_modi_lightsens_g.AllBit + uF_modi_lightsens_inv_g.AllBit) ==> FALSE
   Test Case Generation Notes:
      Conflict: Unable to validate expression-to-expression comparison in branch 4
      Cannot set local variable rb_StartLightEvaluation_s in branch 6
      Conflict: Unable to validate expression-to-expression comparison in branch 10
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:FALSE
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.uF_VoltageStatus_g.Bit.B1:<<MIN>>
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.rb_PosSlopeCountFWLight_mg:<<MAX>>
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.rb_DARKSTARTDELAYCOUNTER_mg:<<MAX>>
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.uF_ASIC_ControlFlags_g.Bit.B1:<<MIN>>
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.rb_FwLightDiv4_g:2
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.rb_AfterVddPowerFailDelay_g:1
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.rb_WDG_LightsensorTaskCounter_g:0x0
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.uF_modi_lightsens_g.AllBit:155
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.uF_modi_lightsens_inv_g.AllBit:155
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B2:0
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B7:0
TEST.VALUE:uut_prototype_stubs.get_rw_Amb_light16bit_g.return:<<MAX>>
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.uF_VoltageStatus_g.Bit.B1:<<MIN>>
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.rb_PosSlopeCountFWLight_mg:<<MAX>>
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.rb_DARKSTARTDELAYCOUNTER_mg:0xF
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.rb_FwLightDiv4_g:2
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.rb_AfterVddPowerFailDelay_g:1
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.rb_WDG_LightsensorTaskCounter_g:252
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.rw_AmbLightMul32MeanSlow_g:65280
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.rw_AmbLightMul32MeanFast_g:65280
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.rw_FwLightMul64MeanFast_g:512
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.rw_FwLightMul64MeanSlow_g:512
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B0:0
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B2:0
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B7:1
TEST.VALUE_USER_CODE:<<testcase>>
int i;
for (i=1; i<=251; i++)
{
  light_evaluation();
}
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: darkStartVoltageStatus.03
TEST.UNIT:G5_DippedBeam_sr
TEST.SUBPROGRAM:light_evaluation
TEST.NEW
TEST.NAME:darkStartVoltageStatus.03
TEST.BASIS_PATH:10 of 11
TEST.NOTES:
This is an automatically generated test case.
   Test Path 10
      (1) if ((uF_LightInternalStatus_g.Bit).B2 == 0) ==> TRUE
      (2) if (rb_PosSlopeCountFWLight_mg > 0) ==> TRUE
      (3) if (rb_DARKSTARTDELAYCOUNTER_mg > 0) ==> TRUE
      (4) if ((rb_AfterVddPowerFailDelay_g | (uF_VoltageStatus_g.Bit).B1) > 0) ==> FALSE
      (5) if ((uF_ASIC_ControlFlags_g.Bit).B1 == 1 && 1 == 1) ==> TRUE
      (6) if (rb_StartLightEvaluation_s > 250) ==> FALSE
      (8) if (get_rw_Amb_light16bit_g() < (2048)) ==> FALSE
      (10) if (255 != uF_modi_lightsens_g.AllBit + uF_modi_lightsens_inv_g.AllBit) ==> FALSE
   Test Case Generation Notes:
      Conflict: Unable to validate expression-to-expression comparison in branch 4
      Conflict: A condition in this branch uses an operand that cannot be set (1 == 1) in branch 5
      Cannot set local variable rb_StartLightEvaluation_s in branch 6
      Conflict: Unable to validate expression-to-expression comparison in branch 10
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.rb_PosSlopeCountFWLight_mg:<<MAX>>
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.rb_DARKSTARTDELAYCOUNTER_mg:<<MAX>>
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.uF_ASIC_ControlFlags_g.Bit.B1:1
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.rb_WDG_LightsensorTaskCounter_g:<<MID>>
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B0:0
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B2:0
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B7:0
TEST.VALUE:uut_prototype_stubs.get_rw_Amb_light16bit_g.return:<<MAX>>
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.rb_PosSlopeCountFWLight_mg:<<MAX>>
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.rb_DARKSTARTDELAYCOUNTER_mg:0
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.uF_ASIC_ControlFlags_g.Bit.B1:1
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.rb_WDG_LightsensorTaskCounter_g:0x80
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B0:0
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B2:0
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B7:1
TEST.END

-- Test Case: darkStartVoltageStatus.04
TEST.UNIT:G5_DippedBeam_sr
TEST.SUBPROGRAM:light_evaluation
TEST.NEW
TEST.NAME:darkStartVoltageStatus.04
TEST.NOTES:
This is an automatically generated test case.
   Test Path 10
      (1) if ((uF_LightInternalStatus_g.Bit).B2 == 0) ==> TRUE
      (2) if (rb_PosSlopeCountFWLight_mg > 0) ==> TRUE
      (3) if (rb_DARKSTARTDELAYCOUNTER_mg > 0) ==> TRUE
      (4) if ((rb_AfterVddPowerFailDelay_g | (uF_VoltageStatus_g.Bit).B1) > 0) ==> FALSE
      (5) if ((uF_ASIC_ControlFlags_g.Bit).B1 == 1 && 1 == 1) ==> TRUE
      (6) if (rb_StartLightEvaluation_s > 250) ==> FALSE
      (8) if (get_rw_Amb_light16bit_g() < (2048)) ==> FALSE
      (10) if (255 != uF_modi_lightsens_g.AllBit + uF_modi_lightsens_inv_g.AllBit) ==> FALSE
   Test Case Generation Notes:
      Conflict: Unable to validate expression-to-expression comparison in branch 4
      Conflict: A condition in this branch uses an operand that cannot be set (1 == 1) in branch 5
      Cannot set local variable rb_StartLightEvaluation_s in branch 6
      Conflict: Unable to validate expression-to-expression comparison in branch 10
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.rb_PosSlopeCountFWLight_mg:<<MAX>>
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.rb_DARKSTARTDELAYCOUNTER_mg:<<MAX>>
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.uF_ASIC_ControlFlags_g.Bit.B1:1
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.rb_WDG_LightsensorTaskCounter_g:<<MID>>
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B0:0
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B2:0
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B7:0
TEST.VALUE:uut_prototype_stubs.get_rw_Amb_light16bit_g.return:<<MAX>>
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.rb_PosSlopeCountFWLight_mg:<<MAX>>
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.rb_DARKSTARTDELAYCOUNTER_mg:0
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.uF_ASIC_ControlFlags_g.Bit.B1:1
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.rb_WDG_LightsensorTaskCounter_g:0x80
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B0:0
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B2:0
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B7:1
TEST.VALUE_USER_CODE:<<testcase>>

TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: darkStartVoltageStatus.05
TEST.UNIT:G5_DippedBeam_sr
TEST.SUBPROGRAM:light_evaluation
TEST.NEW
TEST.NAME:darkStartVoltageStatus.05
TEST.NOTES:
This is an automatically generated test case.
   Test Path 10
      (1) if ((uF_LightInternalStatus_g.Bit).B2 == 0) ==> TRUE
      (2) if (rb_PosSlopeCountFWLight_mg > 0) ==> TRUE
      (3) if (rb_DARKSTARTDELAYCOUNTER_mg > 0) ==> TRUE
      (4) if ((rb_AfterVddPowerFailDelay_g | (uF_VoltageStatus_g.Bit).B1) > 0) ==> FALSE
      (5) if ((uF_ASIC_ControlFlags_g.Bit).B1 == 1 && 1 == 1) ==> TRUE
      (6) if (rb_StartLightEvaluation_s > 250) ==> FALSE
      (8) if (get_rw_Amb_light16bit_g() < (2048)) ==> FALSE
      (10) if (255 != uF_modi_lightsens_g.AllBit + uF_modi_lightsens_inv_g.AllBit) ==> FALSE
   Test Case Generation Notes:
      Conflict: Unable to validate expression-to-expression comparison in branch 4
      Conflict: A condition in this branch uses an operand that cannot be set (1 == 1) in branch 5
      Cannot set local variable rb_StartLightEvaluation_s in branch 6
      Conflict: Unable to validate expression-to-expression comparison in branch 10
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.rb_PosSlopeCountFWLight_mg:<<MAX>>
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.rb_DARKSTARTDELAYCOUNTER_mg:<<MAX>>
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.uF_ASIC_ControlFlags_g.Bit.B1:1
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.rb_AfterVddPowerFailDelay_g:1
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.rb_WDG_LightsensorTaskCounter_g:<<MID>>
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B0:0
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B2:0
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B7:0
TEST.VALUE:uut_prototype_stubs.get_rw_Amb_light16bit_g.return:<<MAX>>
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.rb_PosSlopeCountFWLight_mg:<<MAX>>
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.rb_DARKSTARTDELAYCOUNTER_mg:15
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.uF_ASIC_ControlFlags_g.Bit.B1:1
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.rb_AfterVddPowerFailDelay_g:1
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.rb_WDG_LightsensorTaskCounter_g:0x80
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B0:0
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B2:0
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B7:1
TEST.END

-- Test Case: doNormalCalcFalse.01
TEST.UNIT:G5_DippedBeam_sr
TEST.SUBPROGRAM:light_evaluation
TEST.NEW
TEST.NAME:doNormalCalcFalse.01
TEST.BASIS_PATH:1 of 11
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if ((uF_LightInternalStatus_g.Bit).B2 == 0) ==> FALSE
      (10) if (255 != uF_modi_lightsens_g.AllBit + uF_modi_lightsens_inv_g.AllBit) ==> FALSE
   Test Case Generation Notes:
      Conflict: Unable to validate expression-to-expression comparison in branch 10
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.rb_WDG_LightsensorTaskCounter_g:0xFF
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B0:1
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B1:0
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B2:0
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B3:0
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B4:0
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B5:1
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B6:1
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B7:0
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B0:0
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B1:1
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B2:1
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B3:1
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B4:1
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B5:0
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B6:1
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B7:1
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B0:1
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B1:0
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B2:1
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B3:0
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B4:0
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B5:0
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B6:0
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B7:0
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.rb_WDG_LightsensorTaskCounter_g:0x0
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B0:1
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B1:0
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B2:0
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B3:0
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B4:0
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B5:1
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B6:1
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B7:0
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B0:0
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B1:1
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B2:1
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B3:1
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B4:1
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B5:0
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B6:1
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B7:1
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B0:1
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B1:0
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B2:1
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B3:0
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B4:0
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B5:0
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B6:0
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B7:1
TEST.END

-- Test Case: doNormalCalcFalse.02
TEST.UNIT:G5_DippedBeam_sr
TEST.SUBPROGRAM:light_evaluation
TEST.NEW
TEST.NAME:doNormalCalcFalse.02
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if ((uF_LightInternalStatus_g.Bit).B2 == 0) ==> FALSE
      (10) if (255 != uF_modi_lightsens_g.AllBit + uF_modi_lightsens_inv_g.AllBit) ==> FALSE
   Test Case Generation Notes:
      Conflict: Unable to validate expression-to-expression comparison in branch 10
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.rb_WDG_LightsensorTaskCounter_g:0xFE
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B0:1
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B1:0
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B2:0
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B3:0
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B4:0
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B5:1
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B6:1
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B7:0
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B0:0
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B1:1
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B2:1
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B3:1
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B4:1
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B5:0
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B6:0
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B7:1
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B0:0
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B1:0
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B2:1
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B3:0
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B4:0
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B5:0
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B6:0
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B7:0
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.rb_WDG_LightsensorTaskCounter_g:0xFF
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B0:1
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B1:0
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B2:0
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B3:0
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B4:0
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B5:1
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B6:1
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B7:0
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B0:0
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B1:1
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B2:1
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B3:1
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B4:1
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B5:0
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B6:0
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B7:1
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B0:0
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B1:0
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B2:1
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B3:0
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B4:0
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B5:0
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B6:0
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B7:0
TEST.END

-- Test Case: normalCalcBeforeStartFalse
TEST.UNIT:G5_DippedBeam_sr
TEST.SUBPROGRAM:light_evaluation
TEST.NEW
TEST.NAME:normalCalcBeforeStartFalse
TEST.BASIS_PATH:3 of 11
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) if ((uF_LightInternalStatus_g.Bit).B2 == 0) ==> TRUE
      (2) if (rb_PosSlopeCountFWLight_mg > 0) ==> FALSE
      (10) if (255 != uF_modi_lightsens_g.AllBit + uF_modi_lightsens_inv_g.AllBit) ==> FALSE
   Test Case Generation Notes:
      Conflict: Unable to validate expression-to-expression comparison in branch 10
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.rb_PosSlopeCountFWLight_mg:<<MIN>>
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B0:1
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B1:1
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B2:1
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B3:1
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B4:0
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B5:0
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B6:0
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B7:0
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B0:0
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B1:0
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B2:0
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B3:0
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B4:1
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B5:1
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B6:1
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B7:1
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B0:0
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B1:0
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B2:0
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B3:0
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B4:0
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B5:0
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B6:0
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B7:0
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.rb_PosSlopeCountFWLight_mg:<<MIN>>
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B0:1
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B1:1
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B2:1
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B3:1
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B4:0
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B5:0
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B6:0
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.uF_modi_lightsens_g.Bit.B7:0
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B0:0
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B1:0
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B2:0
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B3:0
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B4:1
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B6:1
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.uF_modi_lightsens_inv_g.Bit.B7:1
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B0:0
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B1:0
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B2:1
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B3:0
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B4:0
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B5:0
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B6:0
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B7:0
TEST.END

-- Test Case: startLightEvaluationFalse.01
TEST.UNIT:G5_DippedBeam_sr
TEST.SUBPROGRAM:light_evaluation
TEST.NEW
TEST.NAME:startLightEvaluationFalse.01
TEST.BASIS_PATH:6 of 11
TEST.NOTES:
This is an automatically generated test case.
   Test Path 6
      (1) if ((uF_LightInternalStatus_g.Bit).B2 == 0) ==> TRUE
      (2) if (rb_PosSlopeCountFWLight_mg > 0) ==> TRUE
      (3) if (rb_DARKSTARTDELAYCOUNTER_mg > 0) ==> TRUE
      (4) if ((rb_AfterVddPowerFailDelay_g | (uF_VoltageStatus_g.Bit).B1) > 0) ==> FALSE
      (5) if ((uF_ASIC_ControlFlags_g.Bit).B1 == 1 && 1 == 1) ==> FALSE
      (6) if (rb_StartLightEvaluation_s > 250) ==> FALSE
      (8) if (get_rw_Amb_light16bit_g() < (2048)) ==> FALSE
      (10) if (255 != uF_modi_lightsens_g.AllBit + uF_modi_lightsens_inv_g.AllBit) ==> FALSE
   Test Case Generation Notes:
      Conflict: Unable to validate expression-to-expression comparison in branch 4
      Cannot set local variable rb_StartLightEvaluation_s in branch 6
      Conflict: Unable to validate expression-to-expression comparison in branch 10
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.rb_PosSlopeCountFWLight_mg:<<MAX>>
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.rb_DARKSTARTDELAYCOUNTER_mg:<<MAX>>
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.uF_ASIC_ControlFlags_g.Bit.B1:<<MIN>>
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B0:1
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B2:0
TEST.VALUE:uut_prototype_stubs.get_rw_Amb_light16bit_g.return:<<MAX>>
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.rb_PosSlopeCountFWLight_mg:<<MAX>>
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.rb_DARKSTARTDELAYCOUNTER_mg:0xFE
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B0:0
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B2:0
TEST.END

-- Test Case: startLightEvaluationFalse.02
TEST.UNIT:G5_DippedBeam_sr
TEST.SUBPROGRAM:light_evaluation
TEST.NEW
TEST.NAME:startLightEvaluationFalse.02
TEST.BASIS_PATH:7 of 11
TEST.NOTES:
This is an automatically generated test case.
   Test Path 7
      (1) if ((uF_LightInternalStatus_g.Bit).B2 == 0) ==> TRUE
      (2) if (rb_PosSlopeCountFWLight_mg > 0) ==> TRUE
      (3) if (rb_DARKSTARTDELAYCOUNTER_mg > 0) ==> TRUE
      (4) if ((rb_AfterVddPowerFailDelay_g | (uF_VoltageStatus_g.Bit).B1) > 0) ==> FALSE
      (5) if ((uF_ASIC_ControlFlags_g.Bit).B1 == 1 && 1 == 1) ==> FALSE
      (6) if (rb_StartLightEvaluation_s > 250) ==> FALSE
      (8) if (get_rw_Amb_light16bit_g() < (2048)) ==> TRUE
      (10) if (255 != uF_modi_lightsens_g.AllBit + uF_modi_lightsens_inv_g.AllBit) ==> FALSE
   Test Case Generation Notes:
      Conflict: Unable to validate expression-to-expression comparison in branch 4
      Cannot set local variable rb_StartLightEvaluation_s in branch 6
      Conflict: Unable to validate expression-to-expression comparison in branch 10
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.rb_PosSlopeCountFWLight_mg:<<MAX>>
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.rb_DARKSTARTDELAYCOUNTER_mg:<<MAX>>
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.uF_ASIC_ControlFlags_g.Bit.B1:<<MIN>>
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.rb_WDG_LightsensorTaskCounter_g:<<MID>>
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B0:0
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B2:0
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B7:0
TEST.VALUE:uut_prototype_stubs.get_rw_Amb_light16bit_g.return:0xFF
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.rb_PosSlopeCountFWLight_mg:<<MAX>>
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.rb_DARKSTARTDELAYCOUNTER_mg:254
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.rb_WDG_LightsensorTaskCounter_g:0x80
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B0:0
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B2:0
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.uF_LightInternalStatus_g.Bit.B7:1
TEST.END

-- Subprogram: set_rb_LightVetoCounter_g

-- Test Case: set_rb_LightVetoCounter_g
TEST.UNIT:G5_DippedBeam_sr
TEST.SUBPROGRAM:set_rb_LightVetoCounter_g
TEST.NEW
TEST.NAME:set_rb_LightVetoCounter_g
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:G5_DippedBeam_sr.<<GLOBAL>>.rb_LightVetoCounter_g:<<MIN>>
TEST.VALUE:G5_DippedBeam_sr.set_rb_LightVetoCounter_g.rb_value_l:<<MAX>>
TEST.EXPECTED:G5_DippedBeam_sr.<<GLOBAL>>.rb_LightVetoCounter_g:<<MAX>>
TEST.EXPECTED:G5_DippedBeam_sr.set_rb_LightVetoCounter_g.rb_value_l:<<MAX>>
TEST.END
