del commands.tmp
echo options WHITEBOX YES >> commands.tmp
echo options COVERAGE_IO_TYPE VCAST_COVERAGE_IO_BUFFERED >> commands.tmp
echo options VCAST_COLLAPSE_STD_HEADERS COLLAPSE_NON_SEARCH_HEADERS >> commands.tmp
echo options SBF_LOC_NONMEMBER_IN_NSP DECL_NAMESPACE >> commands.tmp
echo options SBF_LOC_MEMBER_IN_NSP DECL_NAMESPACE >> commands.tmp
echo options SBF_LOC_MEMBER_OUTSIDE_NSP DECL_NAMESPACE >> commands.tmp
echo options SBF_LOC_NONMEMBER_OUTSIDE_NSP DECL_NAMESPACE >> commands.tmp
echo options MAX_VARY_RANGE 0 >> commands.tmp
echo options VCAST_MAX_STRING_LENGTH 32 >> commands.tmp
echo options VCAST_INST_FILE_MAX_LINES 0 >> commands.tmp
echo options C_EXECUTE_CMD ^<^<iar_3x^>^> >> commands.tmp
echo options C_COMPILER_TAG IAR_RL78 >> commands.tmp
echo options C_COMPILER_HIERARCHY_STRING IAR_RL78_Generic >> commands.tmp
echo options C_COMPILER_NAME IAR RL78 Generic Simulator >> commands.tmp
echo options C_COMPILER_VERSION_CMD  >> commands.tmp
echo options C_DEFINE_LIST __saddr=\" " NDEBUG AUDI_B8 RLFS_TO_FS_ENBLED FW_RAINER ICCRL78_SUPPRESS_CORE_CHECK >> commands.tmp
echo options C_LINKER_VERSION_CMD  >> commands.tmp
echo options C_PREPROCESS_CMD iccrl78 --preprocess=nlc . --core rl78_2 >> commands.tmp
echo options C_PREPROCESS_FILE ?.i >> commands.tmp
echo options C_COMPILE_CMD iccrl78.exe --core rl78_2 --code_model far --data_model near --near_const_location rom0 --dlib_config \"C:\\Tool\\IAR Systems\\Embedded Workbench 7.0\\rl78\\LIB\\dlrl78fn2n.h" -e -Ol --no_cse --no_unroll --no_inline --no_code_motion --no_tbaa --no_crosscall --no_scheduling --no_clustering --debug >> commands.tmp
echo options C_COMPILE_CMD_NAME iccrl78 >> commands.tmp
echo options C_COMPILE_CMD_FLAG  >> commands.tmp
echo options C_COMPILE_EXCLUDE_FLAGS -o** >> commands.tmp
echo options ASSEMBLER_CMD arl78 >> commands.tmp
echo options C_MAKE_ALL_CMD ^<specify build command^> >> commands.tmp
echo options C_DEBUG_CMD $(VECTORCAST_DIR)\\DATA\\iar\\RL78_core2_sim\\execute.bat >> commands.tmp
echo options C_LINK_CMD xlink -l vcast.map -xsmn >> commands.tmp
echo options C_LINK_OPTIONS -I\"$(VCAST_IAR_INSTALL_DIR)\\LIB" -f lnkr5f10pgj.xcl -Hff -rt -s __program_start -D_NEAR_CONST_LOCATION=0 -D_NEAR_CONST_LOCATION_START=3000 -D_NEAR_CONST_LOCATION_END=AEFF \"$(VCAST_IAR_INSTALL_DIR)\\LIB\\dlrl78fn2n.r87" -e_PrintfSmall=_Printf -e_ScanfSmall=_Scanf -D_CSTACK_SIZE=400 -D_NEAR_HEAP_SIZE=400  -D_HUGE_HEAP_SIZE=200 -D_FAR_HEAP_SIZE=200 >> commands.tmp
echo options C_OUTPUT_FLAG -o^^ >> commands.tmp
echo options C_OBJECT_EXT .r87 >> commands.tmp
echo options C_EDG_FLAGS -w --c --iar --iar_version=78k --define_macro=__CORE__=__RL78_1__ >> commands.tmp
echo options EXECUTABLE_EXTENSION .d87 >> commands.tmp
echo options TI_CC_TCF_FILENAME  >> commands.tmp
echo options VCAST_ENVIRONMENT_FILES $(VECTORCAST_DIR)\\DATA\\iar\\RL78_core2_sim\\vcast_debug.dep,$(VECTORCAST_DIR)\\DATA\\iar\\RL78_core2_sim\\vcast_debug.ewd,$(VECTORCAST_DIR)\\DATA\\iar\\RL78_core2_sim\\vcast_debug.ewp,$(VECTORCAST_DIR)\\DATA\\iar\\RL78_core2_sim\\vcast_debug.eww,$(VECTORCAST_DIR)\\DATA\\iar\\RL78_core2_sim\\lnkr5f10pgj.xcl >> commands.tmp
echo options VCAST_RPTS_DEFAULT_FONT_FACE Arial(8) >> commands.tmp
echo options VCAST_PRQAC_COMPILER_SETTINGS_FILE $(PATH_QAC)/personalities/start.p_c >> commands.tmp
echo options VCAST_PRQAC_ANALYSER_BASE $(PATH_QAC) >> commands.tmp
echo options VCAST_PRQAC_MESSAGE_PERSONALITY_FILE $(PATH_QAC)\\personalities\\critical.p_s >> commands.tmp
echo options VCAST_ASSEMBLY_FILE_EXTENSIONS s26 >> commands.tmp
echo options SUBSTITUTE_CODE_FOR_C_FILE FALSE >> commands.tmp
echo options VCAST_AUTO_CLEAR_TEST_USER_CODE FALSE >> commands.tmp
echo options VCAST_COMMAND_LINE_DEBUGGER FALSE >> commands.tmp
echo options VCAST_COVER_STATEMENTS_BY_BLOCK TRUE >> commands.tmp
echo options VCAST_COVERAGE_FOR_AGGREGATE_INIT TRUE >> commands.tmp
echo options VCAST_COVERAGE_FOR_DECLARATIONS FALSE >> commands.tmp
echo options VCAST_COVERAGE_POINTS_AS_MACROS TRUE >> commands.tmp
echo options VCAST_COMPILER_SUPPORTS_CPP_CASTS FALSE >> commands.tmp
echo options VCAST_EXECUTE_WITH_STDOUT TRUE >> commands.tmp
echo options VCAST_FORCE_ELAB_TYPE_SPEC TRUE >> commands.tmp
echo options VCAST_TEST_ALL_NON_MEMBER_INLINES FALSE >> commands.tmp
echo options VCAST_TORNADO_CONSTRUCTOR_CALL_FILE FALSE >> commands.tmp
echo options VCAST_DISABLE_STD_WSTRING_DETECTION TRUE >> commands.tmp
echo options VCAST_MICROSOFT_LONG_LONG FALSE >> commands.tmp
echo options VCAST_NO_SIGNAL TRUE >> commands.tmp
echo options VCAST_NO_STD_FILES TRUE >> commands.tmp
echo options VCAST_NO_STDIN TRUE >> commands.tmp
echo clear_default_source_dirs  >> commands.tmp
echo options TESTABLE_SOURCE_DIR ..\..\..\CustomerInterface\ >> commands.tmp
echo options TESTABLE_SOURCE_DIR ..\..\..\Device\ >> commands.tmp
echo options TESTABLE_SOURCE_DIR ..\..\..\Diagnostics\ >> commands.tmp
echo options TESTABLE_SOURCE_DIR ..\..\..\EEPROM\ >> commands.tmp
echo options TESTABLE_SOURCE_DIR ..\..\..\LIN\ >> commands.tmp
echo options TESTABLE_SOURCE_DIR ..\..\..\Light\ >> commands.tmp
echo options TESTABLE_SOURCE_DIR ..\..\..\OS\ >> commands.tmp
echo options TESTABLE_SOURCE_DIR ..\..\..\Peripherals\ >> commands.tmp
echo options TESTABLE_SOURCE_DIR ..\..\..\Rain\ >> commands.tmp
echo options TESTABLE_SOURCE_DIR ..\..\..\SelfProgLibrary\ >> commands.tmp
echo options TESTABLE_SOURCE_DIR ..\..\..\X1_Humidity\ >> commands.tmp
echo options LIBRARY_INCLUDE_DIR $(VCAST_IAR_INSTALL_DIR)\lib\ >> commands.tmp
echo options LIBRARY_INCLUDE_DIR $(VCAST_IAR_INSTALL_DIR)\inc\ >> commands.tmp
echo environment build G5_APPLI_TIMER.env >> commands.tmp
echo /E:G5_APPLI_TIMER tools script run G5_APPLI_TIMER.tst >> commands.tmp
echo /E:G5_APPLI_TIMER execute batch >> commands.tmp
echo /E:G5_APPLI_TIMER reports custom management G5_APPLI_TIMER_management_report.html >> commands.tmp
"%VECTORCAST_DIR%\CLICAST"  /L:C tools execute commands.tmp false
