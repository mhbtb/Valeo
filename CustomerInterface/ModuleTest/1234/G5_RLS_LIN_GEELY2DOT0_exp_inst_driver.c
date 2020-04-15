/*vcast_separate_expansion_start:C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\1234\\S0000009.c*/
/***********************************************
 *      VectorCAST Test Harness Component      *
 *     Copyright 2020 Vector Software, Inc.    *
 *               6.4t (05/31/17)               *
 ***********************************************/
/***********************************************
 * VectorCAST Unit Information
 *
 * Name: G5_RLS_LIN_GEELY2DOT0
 *
 * Path: C:/baseline/RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3/05_SwDev/01_SrcCode/Application/CustomerInterface/G5_RLS_LIN_GEELY2DOT0.c
 *
 * Type: uut
 *
 * Unit Number: 9
 *
 ***********************************************/
/*vcast_header_expansion_start:C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\1234\\vcast_env_defines.h*/
/*vcast_header_expansion_end*/
/*vcast_header_expansion_start:C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\1234\\G5_RLS_LIN_GEELY2DOT0_driver_prefix.c*/
/*vcast_header_expansion_end*/
/*vcast_header_expansion_start:C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\1234\\S0000009.h*/
/***********************************************
 *      VectorCAST Test Harness Component      *
 *     Copyright 2020 Vector Software, Inc.    *
 *               6.4t (05/31/17)               *
 ***********************************************/
/***********************************************
 *      VectorCAST Test Harness Component      *
 *     Copyright 2020 Vector Software, Inc.    *
 *               6.4t (05/31/17)               *
 ***********************************************/
/***********************************************
 *      VectorCAST Test Harness Component      *
 *     Copyright 2020 Vector Software, Inc.    *
 *               6.4t (05/31/17)               *
 ***********************************************/
/* ----------------------------------------------------------------------------
-- VectorCAST IO File
-- 
-- DISCLAIMER :
-- This file is provided "AS IS"  by  for the convenience of Vector Software.
-- Inconsistent modifications may cause VectorCAST to fail to work properly
-- 
-------------------------------------------------------------------------------*/
/* setup for "long long" capability */
/* end "long long" check */
/***********************************************
 *      VectorCAST Test Harness Component      *
 *     Copyright 2020 Vector Software, Inc.    *
 *               6.4t (05/31/17)               *
 ***********************************************/
/* ----------------------------------------------------------------------------
-- These funtions are called at the start and end of the test harenss
-- and contain conditionally compiled code to setup for the particular I/O
-- mode and in some case the particular target.
-------------------------------------------------------------------------------*/
void vectorcast_initialize_io (int inst_status, int inst_fd);
void vectorcast_terminate_io (void);
void vectorcast_write_vcast_end (void);
int  vectorcast_fflush(int fpn);
void vectorcast_fclose(int fpn);
int  vectorcast_feof(int fpn);
int  vectorcast_fopen(char *filename, char *mode);
char *vectorcast_fgets (char *line, int maxline, int fpn);
/* return failure condition if the line we read is too long */
int vectorcast_readline(char *vcast_buf, int fpn);
void vectorcast_fprint_char   (int fpn, char vcast_str);
void vectorcast_fprint_char_hex ( int fpn, char vcast_value );
void vectorcast_fprint_char_octl ( int fpn, char vcast_value );
void vectorcast_fprint_string (int fpn, const char *vcast_str);
void vectorcast_fprint_string_with_cr (int fpn, const char *vcast_str);
void vectorcast_print_string (const char *vcast_str);
void vectorcast_fprint_string_with_length(int fpn, const char *vcast_str, int length);
void vectorcast_fprint_short     (int vcast_fpn, short vcast_value );
void vectorcast_fprint_integer   (int vcast_fpn, int vcast_value );
void vectorcast_fprint_long      (int vcast_fpn, long vcast_value );
void vectorcast_fprint_long_long (int vcast_fpn, long vcast_value );
void vectorcast_fprint_unsigned_short (int vcast_fpn,
                                       unsigned short vcast_value );
void vectorcast_fprint_unsigned_integer (int vcast_fpn,
                                         unsigned int vcast_value );
void vectorcast_fprint_unsigned_long (int vcast_fpn,
                                      unsigned long vcast_value );
void vectorcast_fprint_unsigned_long_long (int vcast_fpn,
                                           unsigned long vcast_value );
void vectorcast_fprint_long_float (int fpn, vCAST_long_double);
/* numeric conversion routines */
void vcast_signed_to_string ( char vcDest[],
                              long vcSrc );
void vcast_unsigned_to_string ( char vcDest[],
                                unsigned long vcSrc );
void vcast_float_to_string ( char *mixed_str, vCAST_long_double f );
/* ----------------------------------------------------------------------------
-- API for Harness Trace Functions
-----------------------------------------------------------------------------*/
/* To write output, the normal API is: vectorcast_print_string
   vectorcast_write_to_std_out should only be used for abnormal termination
   and debug trace messages */
void vectorcast_write_to_std_out (const char *s);
/*---------------------------------------------------------------------------*/
void vcast_char_to_based_string ( char vcDest[],
                                  unsigned char vcSrc,
                                  unsigned vcUseHex );
/* ----------------------------------------------------------------------------
-- To Save Output Size, for some targets using stdout mode, we output a 
-- number rather than a filename.  So for example, we put out: 
-- "1: data" instead of: "ASCIIRES.DAT: data"
-- JJP TBD: Not sure why this needs to be in the header --
-------------------------------------------------------------------------------*/
enum vcast_env_file_kind
{
   VCAST_ASCIIRES_DAT = 1,
   VCAST_EXPECTED_DAT = 2,
   VCAST_TEMP_DIF_DAT = 3,
   VCAST_TESTINSS_DAT = 4,
   VCAST_THISTORY_DAT = 5,
   VCAST_USERDATA_DAT = 6
};
/* Get the name of the file */
char *vcast_get_filename(enum vcast_env_file_kind kind);
/* ----------------------------------------------------------------------------
-- Need to evaluate these items
-- JJP TBD
-------------------------------------------------------------------------------*/
void vectorcast_set_index(int index, int fpn);
int vectorcast_get_index(int fpn);
struct VCAST_Allocated_Data
{
  void *allocated;
  struct VCAST_Allocated_Data *next;
};
void VCAST_Add_Allocated_Data(void * vcast_data_ptr);
extern struct VCAST_Allocated_Data *VCAST_allocated_data_list;
void vectorcast_longest_int_to_str(long vcast_value, char *vcast_str);
/* -------------------------------------------------------------------------------*/
/* -------------------------------------------------------------------------------*/
/* End of File, close the Extern C block */
extern int vCAST_ITERATION_COUNTERS [3][45];
extern vCAST_array_boolean vCAST_GLOBALS_TOUCHED[6];
enum vCAST_testcase_options_type {
        vCAST_MULTI_RETURN_SPANS_RANGE,
        vCAST_MULTI_RETURN_SPANS_COMPOUND_ITERATIONS,
        vCAST_DISPLAY_INTEGER_RESULTS_IN_HEX,
        vCAST_DISPLAY_FULL_STRING_DATA,
        vCAST_HEX_NOTATION_FOR_UNPRINTABLE_CHARS,
        vCAST_DO_COMBINATION,
        vCAST_REFERENCED_GLOBALS,
        vCAST_FLOAT_POINT_DIGITS_OF_PRECISION,
        vCAST_FLOAT_POINT_TOLERANCE,
        vCAST_EVENT_LIMIT,
        vCAST_GLOBAL_DATA_DISPLAY,
        vCAST_EXPECTED_BEFORE_UUT_CALL,
        vCAST_DATA_PARTITIONS,
        vCAST_SHOW_ONLY_DATA_WITH_EXPECTED_RESULTS,
        vCAST_SHOW_ONLY_EVENTS_WITH_EXPECTED_RESULTS};
enum vCAST_globals_display_type {
        vCAST_EACH_EVENT,
        vCAST_RANGE_ITERATION,
        vCAST_SLOT_ITERATION,
        vCAST_TESTCASE};
/***********************************************
 *      VectorCAST Test Harness Component      *
 *     Copyright 2020 Vector Software, Inc.    *
 *               6.4t (05/31/17)               *
 ***********************************************/
/*************************************************************************
File : S0000004.c
Description : This file contains the declarations of functions in the 
   B0000004.c file.
***************************************************************************/
void vCAST_INITIALIZE_PARAMETERS(void);
void vCAST_USER_CODE_INITIALIZE(int vcast_slot_index, vCAST_boolean commands_read);
void vCAST_USER_CODE_CAPTURE (void);
void vCAST_USER_CODE_CAPTURE_GLOBALS (void);
void vCAST_ONE_SHOT_INIT(void);
void vCAST_ONE_SHOT_TERM(void);
void vCAST_GLOBAL_STUB_PROCESSING(void);
void vCAST_GLOBAL_BEGINNING_OF_STUB_PROCESSING(void);
typedef enum {
   VCAST_UCT_VALUE,
   VCAST_UCT_EXPECTED,
   VCAST_UCT_EXPECTED_GLOBALS
} VCAST_USER_CODE_TYPE;
void vCAST_USER_CODE( VCAST_USER_CODE_TYPE uct, int vcast_slot_index );
/***********************************************
 *      VectorCAST Test Harness Component      *
 *     Copyright 2020 Vector Software, Inc.    *
 *               6.4t (05/31/17)               *
 ***********************************************/
#include "C:/Program Files (x86)/IAR Systems/Embedded Workbench 7.0/rl78/inc/c/stdlib.h"
#include "C:/Program Files (x86)/IAR Systems/Embedded Workbench 7.0/rl78/inc/c/setjmp.h"
#include "C:/Program Files (x86)/IAR Systems/Embedded Workbench 7.0/rl78/inc/c/stdio.h"
#include "C:/Program Files (x86)/IAR Systems/Embedded Workbench 7.0/rl78/inc/c/string.h"
/* Wrappers for malloc and realloc are provided in B2.c */
void * VCAST_malloc (unsigned int vcast_size);
int VCAST_signed_strlen (const signed char *vcast_str );
void VCAST_signed_strcpy ( signed char *VC_S, const signed char *VC_T );
 extern jmp_buf VCAST_env;
/* This define use to define the temporary strings that we use
   when we are breaking down the harness commands like: "0.0.3.4%0\n"
   We use 8 because we do not expect a unit, subprogram, parameter, or field
   to be larger than 999999\n\0
*/
typedef long int vCAST_BIG_INT;
enum    vCAST_COMMAND_TYPE { vCAST_SET_VAL,
                             vCAST_PRINT,
                             vCAST_FIRST_VAL,
                             vCAST_MID_VAL,
                             vCAST_LAST_VAL,
                             vCAST_POS_INF_VAL,
                             vCAST_NEG_INF_VAL,
                             vCAST_NAN_VAL,
                             vCAST_MIN_MINUS_1_VAL,
                             vCAST_MAX_PLUS_1_VAL,
                             vCAST_ZERO_VAL,
                             vCAST_KEEP_VAL,
                             vCAST_ALLOCATE,
                             vCAST_STUB_FUNCTION,
                             vCAST_FUNCTION }; 
struct vCAST_HIST_ENTRY {
  int VC_U;
  int VC_S;
};
struct vCAST_ORDER_ENTRY {
  int  VC_I;
  char VC_N[13];
  char VC_T[64];
  char VC_SLOT_DESCR[64];
  char VC_PRINT_DATA[64];
};
enum VCAST_RANGE_DATA_TYPE { 
   VCAST_NULL_TYPE = 0,
   VCAST_RANGE_TYPE,
   VCAST_LIST_TYPE
};
/* If the max range is not set by the user at all
   we default to 20 */
/* if the user explicitly sets the max range to be 0,
   it means they don't want range processing at all */
/* vCAST function prototypes */
vCAST_double      vCAST_power (short vcast_bits);
vCAST_long_double VCAST_itod  ( char vcastStringParam[] );
void vCAST_SET_TESTCASE_CONFIGURATION_OPTIONS( int VCAST_option,int VCAST_value, int VCAST_set_default);
void vCAST_SET_TESTCASE_OPTIONS ( char vcast_options[] );
void vCAST_RUN_DATA_IF (char VCAST_PARAM[], vCAST_boolean POST_CONSTRUCTOR_USER_CODE);
void vCAST_slice (char vcast_target[], char vcast_source[], int vcast_first, int vcast_last);
void vCAST_EXTRACT_DATA_FROM_COMMAND_LINE (char *vcast_buf, char VCAST_PARAM[], int VC_POSITION);
void vCAST_STR_TO_LONG_DOUBLE(char vcastStringParam[], vCAST_long_double * vcastFloatParam);
void vCAST_DOUBLE_TO_STR (vCAST_long_double VC_F, char VC_S[], int VC_AS_INT);
void vCAST_RESET_LIST_VALUES(void);
void vCAST_ITERATION_COUNTER_RESET(void);
void vCAST_RESET_ITERATION_COUNTERS(enum vCAST_testcase_options_type );
int  vCAST_GET_ITERATION_COUNTER_VALUE(int, int);
void vCAST_INCREMENT_ITERATION_COUNTER(int, int);
void vCAST_EXECUTE_RANGE_COMMANDS (int);
/* if range processing is disabled, no need to do this stuff!*/
void vCAST_RESET_RANGE_VALUES (void);
void vCAST_INITIALIZE_RANGE_VALUES (void);
void vCAST_FREE_RANGE_VALUES(void);
void vCAST_STORE_GLOBAL_ASCII_DATA (void);
void vCAST_CREATE_EVENT_FILE (void);
void vCAST_CREATE_HIST_FILE (void);
void vCAST_OPEN_HIST_FILE (void);
void vCAST_CREATE_INST_FILE (void);
int  VCAST_test_name_cmp(char *vcast_tn);
long VCAST_convert_encoded_field(const char *vcast_str);
/* Code coverage-related functions */
void vCAST_CREATE_INST_FILE (void);
void VCAST_WRITE_TO_INST_FILE (const char VC_S[]);
/* An explanation for the number of bytes required for VectorCAST/Cover.
 * 
 * This represents the maximum amount of RAM that will be required
 * to record coverage data when 100% of your application is executed.
 * It is likely that only a percentage of this storage will be 
 * required during a single program execution.
 * 
 * Please note, when using the static memory option, all of this data 
 * must be reserved in the instrumented executable through global arrays.
 * When you are not using the static memory option, this data is not 
 * reserved in the instrumented executable, and it is allocated on 
 * demand through the use of the malloc system call.
 * 
 * When instrumenting for MCDC, the size of the variables 
 * mcdc_statement_pool and avlnode_pool are controlled with the option 
 * "Maximum MC/DC expressions". The default is set to 1000, 
 * so that a large test case can execute with out fear of 
 * over flowing these buffers. The number chosen (e.g. 1000) will 
 * provide storage for that many unique MC/DC expressions.
 * 
 * For a 16 bit executable configuration:
 *   function call bit array:.............size: 1          bytes:  0 *
 *   Total (no MC/DC pool storage):......................................bytes:  0 *
 * 
 * For a 32 bit executable configuration:
 *   function call bit array:.............size: 1          bytes:  0 *
 *   Total (no MC/DC pool storage):......................................bytes:  0 *
 * 
 * For a 64 bit executable configuration:
 *   function call bit array:.............size: 1          bytes:  0 *
 *   Total (no MC/DC pool storage):......................................bytes:  0 *
 */
void vCAST_SET_OUTPUT_TO_EVENT_FILE (void);
void vCAST_CLOSE_INST_FILE (void);
/* Coverage data */
void vCAST_SET_OUTPUT_TO_EVENT_FILE (void);
void vCAST_CLOSE_INST_FILE (void);
void vCAST_CLOSE_EVENT_FILE (void);
void vCAST_CLOSE_HIST_FILE (void);
void vCAST_WRITE_END_FILE(void);
void vCAST_OPEN_E0_FILE (void);
void vCAST_OPEN_HARNOPTS_FILE(void);
void vCAST_RESET_HARNOPTS_FILE(void);
void vCAST_OPEN_TESTORDR_FILE (void);
void VCAST_READ_TESTORDER_LINE ( char[] );
void vCAST_STORE_ASCII_DATA ( int, int, char[] );
vCAST_boolean vCAST_READ_NEXT_ORDER (void);
vCAST_boolean vCAST_SHOULD_DISPLAY_GLOBALS ( int, char[] );
extern int    vcast_user_file;
extern int    VCAST_EXP_FILE;
extern int    vCAST_UNIT;
extern int    vCAST_SUBPROGRAM;
extern vCAST_boolean    vCAST_DO_DATA_IF;
extern char   vCAST_TEST_NAME[];
extern int    vCAST_CURRENT_SLOT;
extern int    vCAST_CURRENT_ITERATION;
extern int    vCAST_HIST_INDEX;
extern int    vCAST_HIST_LIMIT;
extern int    vCAST_ENV_HIST_LIMIT;
extern vCAST_boolean vCAST_HAS_RANGE;
extern vCAST_boolean vCAST_SKIP_ITER;
extern int    vCAST_NUM_RANGE_ITERATIONS;
extern int    vCAST_RANGE_COUNTER;
extern struct vCAST_ORDER_ENTRY vCAST_ORDER_OBJECT;
extern vCAST_long_double vCAST_PARTITIONS;
extern vCAST_boolean vCAST_COMMAND_IS_MIN_MAX;
extern int vCAST_INST_FILE;
/* file identificastion number for the ASCIIRES.DAT file */
extern int vCAST_EVENT_FILE;
/* file identification number for the THISTORY.DAT file */
extern int vCAST_HIST_FILE;
extern int vCAST_ORDER_FILE;
extern int vCAST_E0_FILE;
/* file identification number for the TEMP_DIF.DAT file */
extern int vCAST_OUTPUT_FILE;
extern int vCAST_COUNT;
extern int vCAST_CURRENT_COUNT;
extern vCAST_array_boolean vCAST_TESTCASE_OPTIONS[15];
extern vCAST_boolean vcast_is_in_union;
extern vCAST_boolean vCAST_INST_FILE_OPEN;
/* true if the ASCIIRES.DAT file is open */
extern vCAST_boolean vCAST_EVENT_FILE_OPEN;
/* true if the THISTORY.DAT file is open */
extern vCAST_boolean vCAST_HIST_FILE_OPEN;
/* default harness options (from HARNOPTS.DAT) */
extern vCAST_boolean VCAST_DEFAULT_FULL_STRINGS;
extern vCAST_boolean VCAST_DEFAULT_HEX_NOTATION;
extern vCAST_boolean VCAST_DEFAULT_DO_COMBINATION;
extern unsigned short VCAST_GLOBALS_DISPLAY; /* when to capture global data */
extern vCAST_boolean VCAST_GLOBAL_FIRST_EVENT;
extern vCAST_boolean vCAST_HEX_NOTATION;  /* use hex notation or not */
extern vCAST_boolean vCAST_DO_COMBINATION_TESTING;/* generate combination or not */
struct vCAST_ORDER_ENTRY* vCAST_ORDER(void);  
void VCAST_driver_termination(int vcast_status, int eventCode);
int vcast_get_hc_id (char *vcast_command);
void vcast_get_unit_id_str (char *vcast_command, char *vcast_unit);
int vcast_get_unit_id (char *vcast_command);
void vcast_get_subprogram_id_str (char *vcast_command, char *vcast_subprogram);
int vcast_get_subprogram_id (char *vcast_command);
void vcast_get_parameter_id_str (char *vcast_command, char *vcast_subprogram);
int vcast_get_parameter_id (char *vcast_command);
int vcast_get_percent_pos (char *vcast_command);
void vCAST_END(void);
void VCAST_SLOT_SEPARATOR ( int VC_EndOfSlot, char VC_SLOT_DESCR );
/* "limits.h" and "float.h" has limits on base types
   If we don't use it, or some types do
   not have limits, define them here */
#include "C:/Program Files (x86)/IAR Systems/Embedded Workbench 7.0/rl78/inc/c/limits.h"
#include "C:/Program Files (x86)/IAR Systems/Embedded Workbench 7.0/rl78/inc/c/float.h"
/* FUNCTION PROTOTYPES */
void VCAST_get_indices(char *str_val, int *array_size);
void vcast_not_supported (void);
void vcast_get_range_value ( int *vCAST_FIRST_VAL,
                             int *vCAST_LAST_VAL,
                             int *vCAST_MORE_DATA);
int vcast_get_param (void);
int VCAST_FIND_INDEX (void);
/*------------------------------------------------------------------*/
vCAST_double vCAST_power (short vcast_bits);
void VCAST_TI_BITFIELD ( long *vc_VAL, int Bits,  vCAST_boolean is_signed );
void VCAST_TI_STRING ( 
      char **vcast_param, 
      int vCAST_Size,
      int from_bounded_array,
      int size_of_bounded_array );
int vcast_add_to_hex(int previousNumber, char latestDigit);
char vcast_get_non_numerical_escape(char character);
int vcast_convert_size(char * input);
char * VCAST_convert(char * input);
/* ASCII value of the first char that can be displayed */
/* ASCII value of the last char that can be displayed */
/**************************************************************************
Function: isUnprintable
Parameters: character - character to check
Description: This function returns true if the character it is given is
a nongraphical one. 
 *************************************************************************/
void vCAST_slice ( char vcast_target[], char source[], int vcast_first, int vcast_last );
vCAST_boolean vcast_proc_handles_command(int vc_m);
void VCAST_SET_GLOBAL_SIZE(unsigned int *vcast_size);
unsigned int *VCAST_GET_GLOBAL_SIZE(void);
/* EXTERNED VARIABLES */
extern int vCAST_FILE;
extern char vCAST_PARAMETER[64];
extern char vCAST_PARAMETER_KEY[64];
extern long vCAST_VALUE_INT;
extern unsigned long vCAST_VALUE_UNSIGNED;
extern vCAST_long_double vCAST_VALUE;
extern int vCAST_PARAM_LENGTH;
extern int vCAST_INDEX;
extern int vCAST_DATA_FIELD;
extern int  *VCAST_index_size;
extern int  VCAST_index_count;
extern enum vCAST_COMMAND_TYPE vCAST_COMMAND;
extern vCAST_boolean vCAST_VALUE_NUL;
extern vCAST_boolean vCAST_SIZE;
extern vCAST_boolean vCAST_can_print_constructor;
struct VCAST_CSU_Data_Item
{
  void *vcast_item;
  char *vcast_command;
  struct VCAST_CSU_Data_Item *vcast_next;
};
struct VCAST_CSU_Data;
void VCAST_Add_CSU_Data (struct VCAST_CSU_Data **vcast_data, 
                         struct VCAST_CSU_Data_Item *vcast_data_item);
struct VCAST_CSU_Data_Item *VCAST_Get_CSU_Data ( 
                         struct VCAST_CSU_Data **vcast_data,
                         char *vcast_command);
void VCAST_DRIVER_8( int VC_SUBPROGRAM, char *VC_EVENT_FLAGS, char *VC_SLOT_DESCR );
void VCAST_DRIVER_9( int VC_SUBPROGRAM, char *VC_EVENT_FLAGS, char *VC_SLOT_DESCR );
/*vcast_header_expansion_end*/
#include "C:/Users/zhu1/Downloads/SW_Need_Change_Managemant/GEEA2.0/E4-2_SW/RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03/05_SwDev/01_SrcCode/Application/CustomerInterface/ModuleTest/1234/vcast_undef_9.h"
/* Include the file which contains function prototypes
for stub processing and value/expected user code */
/*vcast_header_expansion_start:C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\1234\\vcast_uc_prototypes.h*/
void vCAST_VALUE_USER_CODE_8(int vcast_slot_index );
void vCAST_EXPECTED_USER_CODE_8(int vcast_slot_index );
void vCAST_EGLOBALS_USER_CODE_8(int vcast_slot_index );
void vCAST_STUB_PROCESSING_8(
        int  UnitIndex, 
        int  SubprogramIndex );
void vCAST_BEGIN_STUB_PROC_8(
        int  UnitIndex, 
        int  SubprogramIndex );
void vCAST_COMMON_STUB_PROC_8(
            int unitIndex,
            int subprogramIndex,
            int robjectIndex,
            int readEobjectData );
void vCAST_VALUE_USER_CODE_9(int vcast_slot_index );
void vCAST_EXPECTED_USER_CODE_9(int vcast_slot_index );
void vCAST_EGLOBALS_USER_CODE_9(int vcast_slot_index );
void vCAST_STUB_PROCESSING_9(
        int  UnitIndex, 
        int  SubprogramIndex );
void vCAST_BEGIN_STUB_PROC_9(
        int  UnitIndex, 
        int  SubprogramIndex );
void vCAST_COMMON_STUB_PROC_9(
            int unitIndex,
            int subprogramIndex,
            int robjectIndex,
            int readEobjectData );
void vCAST_VALUE_USER_CODE_9(int vcast_slot_index );
void vCAST_EXPECTED_USER_CODE_9(int vcast_slot_index );
void vCAST_EGLOBALS_USER_CODE_9(int vcast_slot_index );
void vCAST_STUB_PROCESSING_9(
        int  UnitIndex, 
        int  SubprogramIndex );
void vCAST_BEGIN_STUB_PROC_9(
        int  UnitIndex, 
        int  SubprogramIndex );
void vCAST_COMMON_STUB_PROC_9(
            int unitIndex,
            int subprogramIndex,
            int robjectIndex,
            int readEobjectData );
/*vcast_header_expansion_end*/
/* Begin Function ApplLinInit */
unsigned char P_9_16_1
;
/* Begin Function ApplLinSlavePreCopy */
unsigned char P_9_17_1
;
/* Begin Function GetFiveTableValue_500ms */
unsigned long P_9_18_1
;
/* Begin Function AdjustOutHudValue */
unsigned long P_9_19_1
;
unsigned long R_9_19;
/* Begin Function GetUpdateTimeForLightStatus */
unsigned char R_9_20;
/* Begin Function CalcHUDMean_1000ms */
unsigned long R_9_21;
/* Begin Function orderHUDValue */
int P_9_22_1
;
/* Begin Function GetFiveTableValue_50ms */
unsigned long P_9_23_1
;
unsigned long P_9_23_2
;
/* Begin Function CRC8SAEJ1850 */
unsigned char *P_9_24_1
;
unsigned char P_9_24_2
;
unsigned char R_9_24;
/* Begin Function GetOutdBriStsCrcj1850 */
unsigned char P_9_25_1
;
unsigned char R_9_25;
/* Begin Function GetHudCrcj1850 */
unsigned long P_9_26_1
;
unsigned char R_9_26;
/* Begin Function GetLightTransmission */
unsigned char P_9_27_1
;
unsigned char P_9_27_2
;
/* Begin Function Get_BCMVehType */
unsigned char P_9_28_1
;
/* Begin Function Set_BCMLightOffset */
unsigned char P_9_29_1
;
/* Begin Function IsByteOddParity */
unsigned char P_9_34_1
;
unsigned char R_9_34;
/*vcast_header_expansion_start:C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\1234\\vcast_stubs_9.c*/
/* Begin defined extern variables */
/* INITIALIZATION_OBJECTS_USER_CODE "1" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "1" */
s_rb_EEPROMStructPD_buff_g EEPROM_Struct_PD 
/* INITIALIZATION_CODE_USER_CODE "1" */
/* INITIALIZATION_CODE_USER_CODE_END "1" */
;
/* INITIALIZATION_OBJECTS_USER_CODE "2" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "2" */
unsigned char rb_Humidity_raw_g 
/* INITIALIZATION_CODE_USER_CODE "2" */
/* INITIALIZATION_CODE_USER_CODE_END "2" */
;
/* INITIALIZATION_OBJECTS_USER_CODE "3" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "3" */
unsigned char rb_Humidity_g 
/* INITIALIZATION_CODE_USER_CODE "3" */
/* INITIALIZATION_CODE_USER_CODE_END "3" */
;
/* INITIALIZATION_OBJECTS_USER_CODE "4" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "4" */
unsigned rw_Temperature_raw_g 
/* INITIALIZATION_CODE_USER_CODE "4" */
/* INITIALIZATION_CODE_USER_CODE_END "4" */
;
/* INITIALIZATION_OBJECTS_USER_CODE "5" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "5" */
unsigned rw_DewPoint_g 
/* INITIALIZATION_CODE_USER_CODE "5" */
/* INITIALIZATION_CODE_USER_CODE_END "5" */
;
/* INITIALIZATION_OBJECTS_USER_CODE "6" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "6" */
unsigned char rbi_HumTempComError_g 
/* INITIALIZATION_CODE_USER_CODE "6" */
/* INITIALIZATION_CODE_USER_CODE_END "6" */
;
/* INITIALIZATION_OBJECTS_USER_CODE "7" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "7" */
s_rb_EEPROMStructAD_buff_g EEPROM_Struct_AD 
/* INITIALIZATION_CODE_USER_CODE "7" */
/* INITIALIZATION_CODE_USER_CODE_END "7" */
;
/* INITIALIZATION_OBJECTS_USER_CODE "8" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "8" */
byte rb_WDG_BusTaskCounter_g 
/* INITIALIZATION_CODE_USER_CODE "8" */
/* INITIALIZATION_CODE_USER_CODE_END "8" */
;
/* INITIALIZATION_OBJECTS_USER_CODE "9" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "9" */
union tLinIndicationBits uLinIndicationFlags 
/* INITIALIZATION_CODE_USER_CODE "9" */
/* INITIALIZATION_CODE_USER_CODE_END "9" */
;
/* INITIALIZATION_OBJECTS_USER_CODE "10" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "10" */
union tLinConfirmationBits uLinConfirmationFlags 
/* INITIALIZATION_CODE_USER_CODE "10" */
/* INITIALIZATION_CODE_USER_CODE_END "10" */
;
/* INITIALIZATION_OBJECTS_USER_CODE "11" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "11" */
byte rb_WakeupCounter_mg 
/* INITIALIZATION_CODE_USER_CODE "11" */
/* INITIALIZATION_CODE_USER_CODE_END "11" */
;
/* INITIALIZATION_OBJECTS_USER_CODE "12" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "12" */
_c_RlsmCem_SerNrLin1Fr01_CEM_LIN1_buf RlsmCem_SerNrLin1Fr01_CEM_LIN1 
/* INITIALIZATION_CODE_USER_CODE "12" */
/* INITIALIZATION_CODE_USER_CODE_END "12" */
;
/* INITIALIZATION_OBJECTS_USER_CODE "13" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "13" */
_c_RlsmCem_Lin1PartNrFr02_CEM_LIN1_buf RlsmCem_Lin1PartNrFr02_CEM_LIN1 
/* INITIALIZATION_CODE_USER_CODE "13" */
/* INITIALIZATION_CODE_USER_CODE_END "13" */
;
/* INITIALIZATION_OBJECTS_USER_CODE "14" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "14" */
_c_RlsmCem_Lin1PartNrFr01_CEM_LIN1_buf RlsmCem_Lin1PartNrFr01_CEM_LIN1 
/* INITIALIZATION_CODE_USER_CODE "14" */
/* INITIALIZATION_CODE_USER_CODE_END "14" */
;
/* INITIALIZATION_OBJECTS_USER_CODE "15" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "15" */
_c_RlsmCem_Lin1Fr03_CEM_LIN1_buf RlsmCem_Lin1Fr03_CEM_LIN1 
/* INITIALIZATION_CODE_USER_CODE "15" */
/* INITIALIZATION_CODE_USER_CODE_END "15" */
;
/* INITIALIZATION_OBJECTS_USER_CODE "16" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "16" */
_c_RlsmCem_Lin1Fr02_CEM_LIN1_buf RlsmCem_Lin1Fr02_CEM_LIN1 
/* INITIALIZATION_CODE_USER_CODE "16" */
/* INITIALIZATION_CODE_USER_CODE_END "16" */
;
/* INITIALIZATION_OBJECTS_USER_CODE "17" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "17" */
_c_RlsmCem_Lin1Fr01_CEM_LIN1_buf RlsmCem_Lin1Fr01_CEM_LIN1 
/* INITIALIZATION_CODE_USER_CODE "17" */
/* INITIALIZATION_CODE_USER_CODE_END "17" */
;
/* INITIALIZATION_OBJECTS_USER_CODE "18" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "18" */
_c_CemCem_Lin1Fr06_CEM_LIN1_buf CemCem_Lin1Fr06_CEM_LIN1 
/* INITIALIZATION_CODE_USER_CODE "18" */
/* INITIALIZATION_CODE_USER_CODE_END "18" */
;
/* INITIALIZATION_OBJECTS_USER_CODE "19" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "19" */
_c_CemCem_Lin1Fr05_CEM_LIN1_buf CemCem_Lin1Fr05_CEM_LIN1 
/* INITIALIZATION_CODE_USER_CODE "19" */
/* INITIALIZATION_CODE_USER_CODE_END "19" */
;
/* INITIALIZATION_OBJECTS_USER_CODE "20" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "20" */
_c_CemCem_Lin1Fr04_CEM_LIN1_buf CemCem_Lin1Fr04_CEM_LIN1 
/* INITIALIZATION_CODE_USER_CODE "20" */
/* INITIALIZATION_CODE_USER_CODE_END "20" */
;
/* INITIALIZATION_OBJECTS_USER_CODE "21" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "21" */
_c_CemCem_Lin1Fr03_CEM_LIN1_buf CemCem_Lin1Fr03_CEM_LIN1 
/* INITIALIZATION_CODE_USER_CODE "21" */
/* INITIALIZATION_CODE_USER_CODE_END "21" */
;
/* INITIALIZATION_OBJECTS_USER_CODE "22" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "22" */
_c_CemCem_Lin1Fr02_CEM_LIN1_buf CemCem_Lin1Fr02_CEM_LIN1 
/* INITIALIZATION_CODE_USER_CODE "22" */
/* INITIALIZATION_CODE_USER_CODE_END "22" */
;
/* INITIALIZATION_OBJECTS_USER_CODE "23" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "23" */
_c_CemCem_Lin1Fr01_CEM_LIN1_buf CemCem_Lin1Fr01_CEM_LIN1 
/* INITIALIZATION_CODE_USER_CODE "23" */
/* INITIALIZATION_CODE_USER_CODE_END "23" */
;
/* INITIALIZATION_OBJECTS_USER_CODE "24" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "24" */
volatile Flag uF_VoltageStatus_g 
/* INITIALIZATION_CODE_USER_CODE "24" */
/* INITIALIZATION_CODE_USER_CODE_END "24" */
;
/* INITIALIZATION_OBJECTS_USER_CODE "25" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "25" */
byte rb_InternalTemperature_g 
/* INITIALIZATION_CODE_USER_CODE "25" */
/* INITIALIZATION_CODE_USER_CODE_END "25" */
;
/* INITIALIZATION_OBJECTS_USER_CODE "26" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "26" */
byte rb_ClockFreq_Error_cnt_g 
/* INITIALIZATION_CODE_USER_CODE "26" */
/* INITIALIZATION_CODE_USER_CODE_END "26" */
;
/* INITIALIZATION_OBJECTS_USER_CODE "27" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "27" */
Flag uF_uC_Error_g 
/* INITIALIZATION_CODE_USER_CODE "27" */
/* INITIALIZATION_CODE_USER_CODE_END "27" */
;
/* INITIALIZATION_OBJECTS_USER_CODE "28" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "28" */
Flag uF_Diagnose_pre_Flag 
/* INITIALIZATION_CODE_USER_CODE "28" */
/* INITIALIZATION_CODE_USER_CODE_END "28" */
;
/* INITIALIZATION_OBJECTS_USER_CODE "29" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "29" */
unsigned char rub_RSIntermDelayInit 
/* INITIALIZATION_CODE_USER_CODE "29" */
/* INITIALIZATION_CODE_USER_CODE_END "29" */
;
/* INITIALIZATION_OBJECTS_USER_CODE "30" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "30" */
unsigned char rb_LimitMemomryNoWiperReaction_g 
/* INITIALIZATION_CODE_USER_CODE "30" */
/* INITIALIZATION_CODE_USER_CODE_END "30" */
;
/* INITIALIZATION_OBJECTS_USER_CODE "31" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "31" */
unsigned char rbi_WiperStarted_g 
/* INITIALIZATION_CODE_USER_CODE "31" */
/* INITIALIZATION_CODE_USER_CODE_END "31" */
;
/* INITIALIZATION_OBJECTS_USER_CODE "32" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "32" */
unsigned char rb_LIN_SensitivityShift_g 
/* INITIALIZATION_CODE_USER_CODE "32" */
/* INITIALIZATION_CODE_USER_CODE_END "32" */
;
/* INITIALIZATION_OBJECTS_USER_CODE "33" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "33" */
volatile RS_Flag RSStatus 
/* INITIALIZATION_CODE_USER_CODE "33" */
/* INITIALIZATION_CODE_USER_CODE_END "33" */
;
/* INITIALIZATION_OBJECTS_USER_CODE "34" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "34" */
unsigned char rub_IntermDelayTime 
/* INITIALIZATION_CODE_USER_CODE "34" */
/* INITIALIZATION_CODE_USER_CODE_END "34" */
;
/* INITIALIZATION_OBJECTS_USER_CODE "35" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "35" */
unsigned char rb_PotiStageFromBox_g 
/* INITIALIZATION_CODE_USER_CODE "35" */
/* INITIALIZATION_CODE_USER_CODE_END "35" */
;
/* INITIALIZATION_OBJECTS_USER_CODE "36" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "36" */
unsigned rw_rain_intensitiy_g 
/* INITIALIZATION_CODE_USER_CODE "36" */
/* INITIALIZATION_CODE_USER_CODE_END "36" */
;
/* INITIALIZATION_OBJECTS_USER_CODE "37" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "37" */
Flag uF_StatusRainsensor_mg 
/* INITIALIZATION_CODE_USER_CODE "37" */
/* INITIALIZATION_CODE_USER_CODE_END "37" */
;
/* INITIALIZATION_OBJECTS_USER_CODE "38" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "38" */
Flag uF_StatusRainsensor2_mg 
/* INITIALIZATION_CODE_USER_CODE "38" */
/* INITIALIZATION_CODE_USER_CODE_END "38" */
;
/* INITIALIZATION_OBJECTS_USER_CODE "39" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "39" */
byte rb_WiperSpeed_g 
/* INITIALIZATION_CODE_USER_CODE "39" */
/* INITIALIZATION_CODE_USER_CODE_END "39" */
;
/* INITIALIZATION_OBJECTS_USER_CODE "40" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "40" */
byte rb_WiperSpeedAlt_g 
/* INITIALIZATION_CODE_USER_CODE "40" */
/* INITIALIZATION_CODE_USER_CODE_END "40" */
;
/* INITIALIZATION_OBJECTS_USER_CODE "41" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "41" */
volatile Flag uF_LIN_DiagReq2_mg 
/* INITIALIZATION_CODE_USER_CODE "41" */
/* INITIALIZATION_CODE_USER_CODE_END "41" */
;
/* INITIALIZATION_OBJECTS_USER_CODE "42" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "42" */
volatile Flag uF_Main_Flags_g 
/* INITIALIZATION_CODE_USER_CODE "42" */
/* INITIALIZATION_CODE_USER_CODE_END "42" */
;
/* INITIALIZATION_OBJECTS_USER_CODE "43" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "43" */
byte rb_RS_LS_Error1_g 
/* INITIALIZATION_CODE_USER_CODE "43" */
/* INITIALIZATION_CODE_USER_CODE_END "43" */
;
/* INITIALIZATION_OBJECTS_USER_CODE "44" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "44" */
byte rb_RS_LS_Error2_g 
/* INITIALIZATION_CODE_USER_CODE "44" */
/* INITIALIZATION_CODE_USER_CODE_END "44" */
;
/* INITIALIZATION_OBJECTS_USER_CODE "45" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "45" */
byte rb_RainS_Error1_g 
/* INITIALIZATION_CODE_USER_CODE "45" */
/* INITIALIZATION_CODE_USER_CODE_END "45" */
;
/* INITIALIZATION_OBJECTS_USER_CODE "46" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "46" */
byte rb_LightS_Error1_g 
/* INITIALIZATION_CODE_USER_CODE "46" */
/* INITIALIZATION_CODE_USER_CODE_END "46" */
;
/* INITIALIZATION_OBJECTS_USER_CODE "47" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "47" */
unsigned rw_EEPROM_Address_to_Write_g 
/* INITIALIZATION_CODE_USER_CODE "47" */
/* INITIALIZATION_CODE_USER_CODE_END "47" */
;
/* INITIALIZATION_OBJECTS_USER_CODE "48" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "48" */
byte rb_I2C_EEPROM_bytesToWrite_g 
/* INITIALIZATION_CODE_USER_CODE "48" */
/* INITIALIZATION_CODE_USER_CODE_END "48" */
;
/* INITIALIZATION_OBJECTS_USER_CODE "49" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "49" */
byte rab_EEPROM_Bytes_toWrite_g[5] 
/* INITIALIZATION_CODE_USER_CODE "49" */
/* INITIALIZATION_CODE_USER_CODE_END "49" */
;
/* INITIALIZATION_OBJECTS_USER_CODE "50" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "50" */
volatile Flag uF_E2ConfigErrorFlags_g 
/* INITIALIZATION_CODE_USER_CODE "50" */
/* INITIALIZATION_CODE_USER_CODE_END "50" */
;
/* INITIALIZATION_OBJECTS_USER_CODE "51" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "51" */
byte rb_speed_in_kmh_g 
/* INITIALIZATION_CODE_USER_CODE "51" */
/* INITIALIZATION_CODE_USER_CODE_END "51" */
;
/* INITIALIZATION_OBJECTS_USER_CODE "52" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "52" */
byte rb_LSPotiStage_g 
/* INITIALIZATION_CODE_USER_CODE "52" */
/* INITIALIZATION_CODE_USER_CODE_END "52" */
;
/* INITIALIZATION_OBJECTS_USER_CODE "53" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "53" */
Flag uF_Check_lightsensor_g 
/* INITIALIZATION_CODE_USER_CODE "53" */
/* INITIALIZATION_CODE_USER_CODE_END "53" */
;
/* INITIALIZATION_OBJECTS_USER_CODE "54" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "54" */
Flag uF_modi_lightsens_g 
/* INITIALIZATION_CODE_USER_CODE "54" */
/* INITIALIZATION_CODE_USER_CODE_END "54" */
;
/* INITIALIZATION_OBJECTS_USER_CODE "55" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "55" */
Flag uF_LightInternalStatus_g 
/* INITIALIZATION_CODE_USER_CODE "55" */
/* INITIALIZATION_CODE_USER_CODE_END "55" */
;
/* INITIALIZATION_OBJECTS_USER_CODE "56" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "56" */
unsigned rw_StandbyTimeOutCnt_g 
/* INITIALIZATION_CODE_USER_CODE "56" */
/* INITIALIZATION_CODE_USER_CODE_END "56" */
;
/* INITIALIZATION_OBJECTS_USER_CODE "57" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "57" */
byte rb_ASIC_ALSx_ShortDetected_cnt_g 
/* INITIALIZATION_CODE_USER_CODE "57" */
/* INITIALIZATION_CODE_USER_CODE_END "57" */
;
/* INITIALIZATION_OBJECTS_USER_CODE "58" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "58" */
byte rb_ASIC_ALSx_ShortDetected_Error_g 
/* INITIALIZATION_CODE_USER_CODE "58" */
/* INITIALIZATION_CODE_USER_CODE_END "58" */
;
/* INITIALIZATION_OBJECTS_USER_CODE "59" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "59" */
Flag uF_ASIC_ControlFlags_g 
/* INITIALIZATION_CODE_USER_CODE "59" */
/* INITIALIZATION_CODE_USER_CODE_END "59" */
;
/* INITIALIZATION_OBJECTS_USER_CODE "60" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "60" */
Flag uF_GainAdjustFlags_g 
/* INITIALIZATION_CODE_USER_CODE "60" */
/* INITIALIZATION_CODE_USER_CODE_END "60" */
;
/* INITIALIZATION_OBJECTS_USER_CODE "61" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "61" */
Flag uF_ASIC_Error_Flags_g 
/* INITIALIZATION_CODE_USER_CODE "61" */
/* INITIALIZATION_CODE_USER_CODE_END "61" */
;
/* INITIALIZATION_OBJECTS_USER_CODE "62" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "62" */
Flag uF_ASIC_Error_Flags1_g 
/* INITIALIZATION_CODE_USER_CODE "62" */
/* INITIALIZATION_CODE_USER_CODE_END "62" */
;
/* INITIALIZATION_OBJECTS_USER_CODE "63" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "63" */
Flag uF_ASIC_Ctrl_Error_Flags_g 
/* INITIALIZATION_CODE_USER_CODE "63" */
/* INITIALIZATION_CODE_USER_CODE_END "63" */
;
/* INITIALIZATION_OBJECTS_USER_CODE "64" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "64" */
unsigned rw_Solar_light16bit_1_g 
/* INITIALIZATION_CODE_USER_CODE "64" */
/* INITIALIZATION_CODE_USER_CODE_END "64" */
;
/* INITIALIZATION_OBJECTS_USER_CODE "65" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "65" */
unsigned rw_Solar_light16bit_2_g 
/* INITIALIZATION_CODE_USER_CODE "65" */
/* INITIALIZATION_CODE_USER_CODE_END "65" */
;
/* INITIALIZATION_OBJECTS_USER_CODE "66" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "66" */
ASIC_ALI_Meas_t ras_ASIC_MUX_MeasAD_g[9] 
/* INITIALIZATION_CODE_USER_CODE "66" */
/* INITIALIZATION_CODE_USER_CODE_END "66" */
;
/* INITIALIZATION_OBJECTS_USER_CODE "67" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "67" */
byte rb_ASIC_initTimeout_g 
/* INITIALIZATION_CODE_USER_CODE "67" */
/* INITIALIZATION_CODE_USER_CODE_END "67" */
;
/* INITIALIZATION_OBJECTS_USER_CODE "68" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "68" */
byte rb_VIref_ErrCnt_g 
/* INITIALIZATION_CODE_USER_CODE "68" */
/* INITIALIZATION_CODE_USER_CODE_END "68" */
;
/* INITIALIZATION_OBJECTS_USER_CODE "69" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "69" */
byte rb_ASIC_SPI_ErrorCodeCnt_g 
/* INITIALIZATION_CODE_USER_CODE "69" */
/* INITIALIZATION_CODE_USER_CODE_END "69" */
;
/* INITIALIZATION_OBJECTS_USER_CODE "70" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "70" */
byte rb_StaticNoValidAD_cnt_g 
/* INITIALIZATION_CODE_USER_CODE "70" */
/* INITIALIZATION_CODE_USER_CODE_END "70" */
;
/* INITIALIZATION_OBJECTS_USER_CODE "71" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "71" */
unsigned rw_SPINoCommCounter_g 
/* INITIALIZATION_CODE_USER_CODE "71" */
/* INITIALIZATION_CODE_USER_CODE_END "71" */
;
/* End defined extern variables */
/* Begin defined static member variables */
/* End defined static member variables */
/* BEGIN PROTOTYPE STUBS */
unsigned char P_10_1_1
;
void sci_init(byte rb_WakeUpFrame_l)
{
  vCAST_USER_CODE_TIMER_STOP();
  if ( vcast_is_in_driver ) {
    P_10_1_1 = rb_WakeUpFrame_l;
    vCAST_COMMON_STUB_PROC_9( 10, 1, 2, 0 );
  } /* vcast_is_in_driver */
  vCAST_USER_CODE_TIMER_START();
  return;
}
void Check_StartupActiveErrors(void)
{
  vCAST_USER_CODE_TIMER_STOP();
  if ( vcast_is_in_driver ) {
    vCAST_COMMON_STUB_PROC_9( 10, 2, 1, 0 );
  } /* vcast_is_in_driver */
  vCAST_USER_CODE_TIMER_START();
  return;
}
unsigned char R_10_3;
byte get_rb_LightVetoCounter_g(void)
{
  vCAST_USER_CODE_TIMER_STOP();
  if ( vcast_is_in_driver ) {
    vCAST_COMMON_STUB_PROC_9( 10, 3, 1, 0 );
  } /* vcast_is_in_driver */
  vCAST_USER_CODE_TIMER_START();
  return R_10_3;
}
unsigned R_10_4;
unsigned get_rw_Amb_light16bit_g(void)
{
  vCAST_USER_CODE_TIMER_STOP();
  if ( vcast_is_in_driver ) {
    vCAST_COMMON_STUB_PROC_9( 10, 4, 1, 0 );
  } /* vcast_is_in_driver */
  vCAST_USER_CODE_TIMER_START();
  return R_10_4;
}
unsigned long R_10_5;
unsigned long get_rl_HUD_light32bit_g(void)
{
  vCAST_USER_CODE_TIMER_STOP();
  if ( vcast_is_in_driver ) {
    vCAST_COMMON_STUB_PROC_9( 10, 5, 1, 0 );
  } /* vcast_is_in_driver */
  vCAST_USER_CODE_TIMER_START();
  return R_10_5;
}
unsigned R_10_6;
unsigned get_rw_IR_light16bit_g(void)
{
  vCAST_USER_CODE_TIMER_STOP();
  if ( vcast_is_in_driver ) {
    vCAST_COMMON_STUB_PROC_9( 10, 6, 1, 0 );
  } /* vcast_is_in_driver */
  vCAST_USER_CODE_TIMER_START();
  return R_10_6;
}
unsigned char R_10_7;
byte get_rb_LightSignalErrorCnt_g(void)
{
  vCAST_USER_CODE_TIMER_STOP();
  if ( vcast_is_in_driver ) {
    vCAST_COMMON_STUB_PROC_9( 10, 7, 1, 0 );
  } /* vcast_is_in_driver */
  vCAST_USER_CODE_TIMER_START();
  return R_10_7;
}
unsigned char R_10_8;
byte get_rb_VDD_LightSignalErrorCnt_g(void)
{
  vCAST_USER_CODE_TIMER_STOP();
  if ( vcast_is_in_driver ) {
    vCAST_COMMON_STUB_PROC_9( 10, 8, 1, 0 );
  } /* vcast_is_in_driver */
  vCAST_USER_CODE_TIMER_START();
  return R_10_8;
}
unsigned char R_10_9;
byte get_rb_LEDx_LStop_error_cnt_g(void)
{
  vCAST_USER_CODE_TIMER_STOP();
  if ( vcast_is_in_driver ) {
    vCAST_COMMON_STUB_PROC_9( 10, 9, 1, 0 );
  } /* vcast_is_in_driver */
  vCAST_USER_CODE_TIMER_START();
  return R_10_9;
}
void CopyRLSDataAsic(void)
{
  vCAST_USER_CODE_TIMER_STOP();
  if ( vcast_is_in_driver ) {
    vCAST_COMMON_STUB_PROC_9( 10, 10, 1, 0 );
  } /* vcast_is_in_driver */
  vCAST_USER_CODE_TIMER_START();
  return;
}
/* END PROTOTYPE STUBS */
/*vcast_header_expansion_end*/
/* begin declarations of inlined friends */
/* end declarations of inlined friends */
void VCAST_DRIVER_9( int VC_SUBPROGRAM, char *VC_EVENT_FLAGS, char *VC_SLOT_DESCR ) {
  switch( VC_SUBPROGRAM ) {
    case 0:
      vCAST_SET_HISTORY_FLAGS ( 9, 0, VC_EVENT_FLAGS, VC_SLOT_DESCR );
      break;
    case 1: {
      /* void GetLeWWS(void) */
      vCAST_SET_HISTORY_FLAGS ( 9, 1, VC_EVENT_FLAGS, VC_SLOT_DESCR );
      ( GetLeWWS( ) );
      break; }
    case 2: {
      /* void GetLsWWS(void) */
      vCAST_SET_HISTORY_FLAGS ( 9, 2, VC_EVENT_FLAGS, VC_SLOT_DESCR );
      ( GetLsWWS( ) );
      break; }
    case 3: {
      /* void CopyRLSData(void) */
      vCAST_SET_HISTORY_FLAGS ( 9, 3, VC_EVENT_FLAGS, VC_SLOT_DESCR );
      ( CopyRLSData( ) );
      break; }
    case 4: {
      /* void RainFunction(void) */
      vCAST_SET_HISTORY_FLAGS ( 9, 4, VC_EVENT_FLAGS, VC_SLOT_DESCR );
      ( RainFunction( ) );
      break; }
    case 5: {
      /* void LightFunction(void) */
      vCAST_SET_HISTORY_FLAGS ( 9, 5, VC_EVENT_FLAGS, VC_SLOT_DESCR );
      ( LightFunction( ) );
      break; }
    case 6: {
      /* void Humidity_Function(void) */
      vCAST_SET_HISTORY_FLAGS ( 9, 6, VC_EVENT_FLAGS, VC_SLOT_DESCR );
      ( Humidity_Function( ) );
      break; }
    case 7: {
      /* void StandByMode(void) */
      vCAST_SET_HISTORY_FLAGS ( 9, 7, VC_EVENT_FLAGS, VC_SLOT_DESCR );
      ( StandByMode( ) );
      break; }
    case 8: {
      /* void VoltageDetect(void) */
      vCAST_SET_HISTORY_FLAGS ( 9, 8, VC_EVENT_FLAGS, VC_SLOT_DESCR );
      ( VoltageDetect( ) );
      break; }
    case 9: {
      /* void TemperatureDetect(void) */
      vCAST_SET_HISTORY_FLAGS ( 9, 9, VC_EVENT_FLAGS, VC_SLOT_DESCR );
      ( TemperatureDetect( ) );
      break; }
    case 10: {
      /* void OutPutHudSendCount(void) */
      vCAST_SET_HISTORY_FLAGS ( 9, 10, VC_EVENT_FLAGS, VC_SLOT_DESCR );
      ( OutPutHudSendCount( ) );
      break; }
    case 11: {
      /* void OutPutHudValue(void) */
      vCAST_SET_HISTORY_FLAGS ( 9, 11, VC_EVENT_FLAGS, VC_SLOT_DESCR );
      ( OutPutHudValue( ) );
      break; }
    case 12: {
      /* void OutPutTwliBriValue(void) */
      vCAST_SET_HISTORY_FLAGS ( 9, 12, VC_EVENT_FLAGS, VC_SLOT_DESCR );
      ( OutPutTwliBriValue( ) );
      break; }
    case 13: {
      /* void OutPutSolarValue(void) */
      vCAST_SET_HISTORY_FLAGS ( 9, 13, VC_EVENT_FLAGS, VC_SLOT_DESCR );
      ( OutPutSolarValue( ) );
      break; }
    case 14: {
      /* void OutPutBrightnessValue(void) */
      vCAST_SET_HISTORY_FLAGS ( 9, 14, VC_EVENT_FLAGS, VC_SLOT_DESCR );
      ( OutPutBrightnessValue( ) );
      break; }
    case 15: {
      /* void CheckErrors(void) */
      vCAST_SET_HISTORY_FLAGS ( 9, 15, VC_EVENT_FLAGS, VC_SLOT_DESCR );
      ( CheckErrors( ) );
      break; }
    case 16: {
      /* void ApplLinInit(byte rb_LIN_State_l) */
      vCAST_SET_HISTORY_FLAGS ( 9, 16, VC_EVENT_FLAGS, VC_SLOT_DESCR );
      ( ApplLinInit(
        ( P_9_16_1 ) ) );
      break; }
    case 17: {
      /* __callt void ApplLinSlavePreCopy(byte rb_MessageID_l) */
      vCAST_SET_HISTORY_FLAGS ( 9, 17, VC_EVENT_FLAGS, VC_SLOT_DESCR );
      ( ApplLinSlavePreCopy(
        ( P_9_17_1 ) ) );
      break; }
    case 18: {
      /* void GetFiveTableValue_500ms(unsigned long rl_HUD_Brightness_50ms) */
      vCAST_SET_HISTORY_FLAGS ( 9, 18, VC_EVENT_FLAGS, VC_SLOT_DESCR );
      ( GetFiveTableValue_500ms(
        ( P_9_18_1 ) ) );
      break; }
    case 19: {
      /* unsigned long AdjustOutHudValue(unsigned long rl_CurrentHud) */
      vCAST_SET_HISTORY_FLAGS ( 9, 19, VC_EVENT_FLAGS, VC_SLOT_DESCR );
      R_9_19 = 
      ( AdjustOutHudValue(
        ( P_9_19_1 ) ) );
      break; }
    case 20: {
      /* unsigned char GetUpdateTimeForLightStatus(void) */
      vCAST_SET_HISTORY_FLAGS ( 9, 20, VC_EVENT_FLAGS, VC_SLOT_DESCR );
      R_9_20 = 
      ( GetUpdateTimeForLightStatus( ) );
      break; }
    case 21: {
      /* unsigned long CalcHUDMean_1000ms(void) */
      vCAST_SET_HISTORY_FLAGS ( 9, 21, VC_EVENT_FLAGS, VC_SLOT_DESCR );
      R_9_21 = 
      ( CalcHUDMean_1000ms( ) );
      break; }
    case 22: {
      /* void orderHUDValue(int n) */
      vCAST_SET_HISTORY_FLAGS ( 9, 22, VC_EVENT_FLAGS, VC_SLOT_DESCR );
      ( orderHUDValue(
        ( P_9_22_1 ) ) );
      break; }
    case 23: {
      /* void GetFiveTableValue_50ms(unsigned long Fw, unsigned long Amb) */
      vCAST_SET_HISTORY_FLAGS ( 9, 23, VC_EVENT_FLAGS, VC_SLOT_DESCR );
      ( GetFiveTableValue_50ms(
        ( P_9_23_1 ),
        ( P_9_23_2 ) ) );
      break; }
    case 24: {
      /* byte CRC8SAEJ1850(byte * u8_data, byte u8_len) */
      vCAST_SET_HISTORY_FLAGS ( 9, 24, VC_EVENT_FLAGS, VC_SLOT_DESCR );
      R_9_24 = 
      ( CRC8SAEJ1850(
        ( P_9_24_1 ),
        ( P_9_24_2 ) ) );
      break; }
    case 25: {
      /* byte GetOutdBriStsCrcj1850(byte OutdBriSts) */
      vCAST_SET_HISTORY_FLAGS ( 9, 25, VC_EVENT_FLAGS, VC_SLOT_DESCR );
      R_9_25 = 
      ( GetOutdBriStsCrcj1850(
        ( P_9_25_1 ) ) );
      break; }
    case 26: {
      /* byte GetHudCrcj1850(unsigned long hudSrc) */
      vCAST_SET_HISTORY_FLAGS ( 9, 26, VC_EVENT_FLAGS, VC_SLOT_DESCR );
      R_9_26 = 
      ( GetHudCrcj1850(
        ( P_9_26_1 ) ) );
      break; }
    case 27: {
      /* void GetLightTransmission(byte trans_550nm, byte trans_880nm) */
      vCAST_SET_HISTORY_FLAGS ( 9, 27, VC_EVENT_FLAGS, VC_SLOT_DESCR );
      ( GetLightTransmission(
        ( P_9_27_1 ),
        ( P_9_27_2 ) ) );
      break; }
    case 28: {
      /* void Get_BCMVehType(byte CarType) */
      vCAST_SET_HISTORY_FLAGS ( 9, 28, VC_EVENT_FLAGS, VC_SLOT_DESCR );
      ( Get_BCMVehType(
        ( P_9_28_1 ) ) );
      break; }
    case 29: {
      /* void Set_BCMLightOffset(byte offset) */
      vCAST_SET_HISTORY_FLAGS ( 9, 29, VC_EVENT_FLAGS, VC_SLOT_DESCR );
      ( Set_BCMLightOffset(
        ( P_9_29_1 ) ) );
      break; }
    case 30: {
      /* void SendRLSSerNo(void) */
      vCAST_SET_HISTORY_FLAGS ( 9, 30, VC_EVENT_FLAGS, VC_SLOT_DESCR );
      ( SendRLSSerNo( ) );
      break; }
    case 31: {
      /* void SendRLSMPartNo(void) */
      vCAST_SET_HISTORY_FLAGS ( 9, 31, VC_EVENT_FLAGS, VC_SLOT_DESCR );
      ( SendRLSMPartNo( ) );
      break; }
    case 32: {
      /* void SendRLSMPartNo10(void) */
      vCAST_SET_HISTORY_FLAGS ( 9, 32, VC_EVENT_FLAGS, VC_SLOT_DESCR );
      ( SendRLSMPartNo10( ) );
      break; }
    case 33: {
      /* void WipeWinterModeCheck(void) */
      vCAST_SET_HISTORY_FLAGS ( 9, 33, VC_EVENT_FLAGS, VC_SLOT_DESCR );
      ( WipeWinterModeCheck( ) );
      break; }
    case 34: {
      /* byte IsByteOddParity(byte data) */
      vCAST_SET_HISTORY_FLAGS ( 9, 34, VC_EVENT_FLAGS, VC_SLOT_DESCR );
      R_9_34 = 
      ( IsByteOddParity(
        ( P_9_34_1 ) ) );
      break; }
    default:
      vectorcast_print_string("ERROR: Internal Tool Error\n");
      break;
  } /* switch */
}
/*vcast_header_expansion_start:C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\1234\\vcast_ti_decls_9.h*/
void VCAST_TI_8_2 ( int *vcast_param ) ;
void VCAST_TI_9_1 ( _c_CemCem_Lin1Fr05_CEM_LIN1_buf *vcast_param ) ;
void VCAST_TI_9_10 ( _c_CemCem_Lin1Fr02_CEM_LIN1_buf *vcast_param ) ;
void VCAST_TI_9_11 ( _c_CemCem_Lin1Fr02_CEM_LIN1_msgType *vcast_param ) ;
void VCAST_TI_9_111 ( unsigned char vcast_param[6] ) ;
void VCAST_TI_9_12 ( _c_RlsmCem_Lin1Fr01_CEM_LIN1_buf *vcast_param ) ;
void VCAST_TI_9_13 ( _c_RlsmCem_Lin1Fr01_CEM_LIN1_msgType *vcast_param ) ;
void VCAST_TI_9_14 ( _c_CemCem_Lin1Fr03_CEM_LIN1_buf *vcast_param ) ;
void VCAST_TI_9_15 ( _c_CemCem_Lin1Fr03_CEM_LIN1_msgType *vcast_param ) ;
void VCAST_TI_9_16 ( _c_CemCem_Lin1Fr04_CEM_LIN1_buf *vcast_param ) ;
void VCAST_TI_9_17 ( _c_CemCem_Lin1Fr04_CEM_LIN1_msgType *vcast_param ) ;
void VCAST_TI_9_18 ( _c_CemCem_Lin1Fr06_CEM_LIN1_buf *vcast_param ) ;
void VCAST_TI_9_19 ( _c_CemCem_Lin1Fr06_CEM_LIN1_msgType *vcast_param ) ;
void VCAST_TI_9_2 ( _c_CemCem_Lin1Fr05_CEM_LIN1_msgType *vcast_param ) ;
void VCAST_TI_9_20 ( volatile RS_Flag *vcast_param ) ;
void VCAST_TI_9_21 ( RS_Bit_Feld *vcast_param ) ;
void VCAST_TI_9_22 ( unsigned *vcast_param ) ;
void VCAST_TI_9_23 ( Flag *vcast_param ) ;
void VCAST_TI_9_24 ( _c_CemCem_Lin1Fr01_CEM_LIN1_buf *vcast_param ) ;
void VCAST_TI_9_25 ( _c_CemCem_Lin1Fr01_CEM_LIN1_msgType *vcast_param ) ;
void VCAST_TI_9_26 ( s_rb_EEPROMStructPD_buff_g *vcast_param ) ;
void VCAST_TI_9_27 ( s_rb_EEPROMStruct_PD_g *vcast_param ) ;
void VCAST_TI_9_28 ( s_rb_EEPROMStructAD_buff_g *vcast_param ) ;
void VCAST_TI_9_29 ( s_rb_EEPROMStruct_AD_g *vcast_param ) ;
void VCAST_TI_9_30 ( union tLinConfirmationBits *vcast_param ) ;
void VCAST_TI_9_31 ( struct _c_bits16 vcast_param[(11 + 15) / 16] ) ;
void VCAST_TI_9_32 ( struct _c_bits16 *vcast_param ) ;
void VCAST_TI_9_33 ( _c_RlsmCem_Lin1Fr03_CEM_LIN1_buf *vcast_param ) ;
void VCAST_TI_9_34 ( _c_RlsmCem_Lin1Fr03_CEM_LIN1_msgType *vcast_param ) ;
void VCAST_TI_9_35 ( _c_RlsmCem_Lin1Fr02_CEM_LIN1_buf *vcast_param ) ;
void VCAST_TI_9_36 ( _c_RlsmCem_Lin1Fr02_CEM_LIN1_msgType *vcast_param ) ;
void VCAST_TI_9_37 ( ASIC_ALI_Meas_t vcast_param[9] ) ;
void VCAST_TI_9_38 ( ASIC_ALI_Meas_t *vcast_param ) ;
void VCAST_TI_9_39 ( unsigned long *vcast_param ) ;
void VCAST_TI_9_4 ( volatile Flag *vcast_param ) ;
void VCAST_TI_9_40 ( _c_RlsmCem_SerNrLin1Fr01_CEM_LIN1_buf *vcast_param ) ;
void VCAST_TI_9_41 ( unsigned char vcast_param[4] ) ;
void VCAST_TI_9_42 ( _c_RlsmCem_Lin1PartNrFr02_CEM_LIN1_buf *vcast_param ) ;
void VCAST_TI_9_43 ( unsigned char vcast_param[8] ) ;
void VCAST_TI_9_44 ( _c_RlsmCem_Lin1PartNrFr01_CEM_LIN1_buf *vcast_param ) ;
void VCAST_TI_9_45 ( unsigned char vcast_param[7] ) ;
void VCAST_TI_9_49 ( unsigned long vcast_param[10] ) ;
void VCAST_TI_9_5 ( Bit_Feld *vcast_param ) ;
void VCAST_TI_9_50 ( unsigned long vcast_param[2] ) ;
void VCAST_TI_9_53 ( unsigned char **vcast_param ) ;
void VCAST_TI_9_54 ( unsigned char vcast_param[5] ) ;
void VCAST_TI_9_55 ( _c_RlsmCem_SerNrLin1Fr01_CEM_LIN1_msgType *vcast_param ) ;
void VCAST_TI_9_57 ( _c_RlsmCem_Lin1PartNrFr01_CEM_LIN1_msgType *vcast_param ) ;
void VCAST_TI_9_59 ( _c_RlsmCem_Lin1PartNrFr02_CEM_LIN1_msgType *vcast_param ) ;
void VCAST_TI_9_6 ( unsigned char *vcast_param ) ;
void VCAST_TI_9_63 ( unsigned char vcast_param[12] ) ;
void VCAST_TI_9_64 ( unsigned char vcast_param[2] ) ;
void VCAST_TI_9_65 ( unsigned char vcast_param[3] ) ;
void VCAST_TI_9_68 ( unsigned char vcast_param[(93 + 4) + 10] ) ;
void VCAST_TI_9_7 ( union tLinIndicationBits *vcast_param ) ;
void VCAST_TI_9_70 ( s_rb_PrametersStruct_g *vcast_param ) ;
void VCAST_TI_9_72 ( s_rb_PrametersStruct_g vcast_param[4] ) ;
void VCAST_TI_9_74 ( unsigned char vcast_param[9] ) ;
void VCAST_TI_9_77 ( unsigned char vcast_param[33] ) ;
void VCAST_TI_9_79 ( unsigned char vcast_param[194] ) ;
void VCAST_TI_9_8 ( struct _c_bits8 vcast_param[1] ) ;
void VCAST_TI_9_80 ( unsigned char vcast_param[1] ) ;
void VCAST_TI_9_81 ( unsigned char vcast_param[(11 + 7) / 8] ) ;
void VCAST_TI_9_9 ( struct _c_bits8 *vcast_param ) ;
/*vcast_header_expansion_end*/
void VCAST_RUN_DATA_IF_9( int VCAST_SUB_INDEX, int VCAST_PARAM_INDEX ) {
  switch ( VCAST_SUB_INDEX ) {
    case 0: /* for global objects */
      switch( VCAST_PARAM_INDEX ) {
        case 39: /* for global object EEPROM_Struct_PD */
          VCAST_TI_9_26 ( ((s_rb_EEPROMStructPD_buff_g *)(&(EEPROM_Struct_PD))));
          break;
        case 40: /* for global object rb_Humidity_raw_g */
          VCAST_TI_9_6 ( ((unsigned char *)(&(rb_Humidity_raw_g))));
          break;
        case 41: /* for global object rb_Humidity_g */
          VCAST_TI_9_6 ( ((unsigned char *)(&(rb_Humidity_g))));
          break;
        case 42: /* for global object rw_Temperature_raw_g */
          VCAST_TI_9_22 ( ((unsigned *)(&(rw_Temperature_raw_g))));
          break;
        case 43: /* for global object rw_DewPoint_g */
          VCAST_TI_9_22 ( ((unsigned *)(&(rw_DewPoint_g))));
          break;
        case 44: /* for global object rbi_HumTempComError_g */
          VCAST_TI_9_6 ( ((unsigned char *)(&(rbi_HumTempComError_g))));
          break;
        case 45: /* for global object EEPROM_Struct_AD */
          VCAST_TI_9_28 ( ((s_rb_EEPROMStructAD_buff_g *)(&(EEPROM_Struct_AD))));
          break;
        case 46: /* for global object rb_WDG_BusTaskCounter_g */
          VCAST_TI_9_6 ( ((unsigned char *)(&(rb_WDG_BusTaskCounter_g))));
          break;
        case 47: /* for global object uLinIndicationFlags */
          VCAST_TI_9_7 ( ((union tLinIndicationBits *)(&(uLinIndicationFlags))));
          break;
        case 48: /* for global object uLinConfirmationFlags */
          VCAST_TI_9_30 ( ((union tLinConfirmationBits *)(&(uLinConfirmationFlags))));
          break;
        case 49: /* for global object rb_WakeupCounter_mg */
          VCAST_TI_9_6 ( ((unsigned char *)(&(rb_WakeupCounter_mg))));
          break;
        case 1: /* for global object uF_SCIFlags_mg */
          VCAST_TI_9_4 ( ((volatile Flag *)(&(uF_SCIFlags_mg))));
          break;
        case 2: /* for global object rb_LIN_BIT_ERROR_COUNTER_g */
          VCAST_TI_9_6 ( ((unsigned char *)(&(rb_LIN_BIT_ERROR_COUNTER_g))));
          break;
        case 3: /* for global object rb_LIN_OVERTHEADERMAX_COUNTER_g */
          VCAST_TI_9_6 ( ((unsigned char *)(&(rb_LIN_OVERTHEADERMAX_COUNTER_g))));
          break;
        case 4: /* for global object rb_LIN_CHECKSUMERROR_COUNTER_g */
          VCAST_TI_9_6 ( ((unsigned char *)(&(rb_LIN_CHECKSUMERROR_COUNTER_g))));
          break;
        case 5: /* for global object rb_LIN_OVERTFRAMEMAX_COUNTER_g */
          VCAST_TI_9_6 ( ((unsigned char *)(&(rb_LIN_OVERTFRAMEMAX_COUNTER_g))));
          break;
        case 6: /* for global object rb_LIN_NORESPONSE_COUNTER_g */
          VCAST_TI_9_6 ( ((unsigned char *)(&(rb_LIN_NORESPONSE_COUNTER_g))));
          break;
        case 7: /* for global object rb_LIN_FRAMINGERROR_COUNTER_g */
          VCAST_TI_9_6 ( ((unsigned char *)(&(rb_LIN_FRAMINGERROR_COUNTER_g))));
          break;
        case 8: /* for global object uF_Communication_mg */
          VCAST_TI_9_23 ( ((Flag *)(&(uF_Communication_mg))));
          break;
        case 9: /* for global object uF_Butterfly_Flags_g */
          VCAST_TI_9_4 ( ((volatile Flag *)(&(uF_Butterfly_Flags_g))));
          break;
        case 10: /* for global object rb_LastLINErrorCode_g */
          VCAST_TI_9_6 ( ((unsigned char *)(&(rb_LastLINErrorCode_g))));
          break;
        case 11: /* for global object rw_NoCommunicationCounter_g */
          VCAST_TI_9_22 ( ((unsigned *)(&(rw_NoCommunicationCounter_g))));
          break;
        case 12: /* for global object rb_intervaltime_rainSensorOff_g */
          VCAST_TI_9_6 ( ((unsigned char *)(&(rb_intervaltime_rainSensorOff_g))));
          break;
        case 13: /* for global object rb_Release_IntervalMarker_Update_g */
          VCAST_TI_9_6 ( ((unsigned char *)(&(rb_Release_IntervalMarker_Update_g))));
          break;
        case 50: /* for global object RlsmCem_SerNrLin1Fr01_CEM_LIN1 */
          VCAST_TI_9_40 ( ((_c_RlsmCem_SerNrLin1Fr01_CEM_LIN1_buf *)(&(RlsmCem_SerNrLin1Fr01_CEM_LIN1))));
          break;
        case 51: /* for global object RlsmCem_Lin1PartNrFr02_CEM_LIN1 */
          VCAST_TI_9_42 ( ((_c_RlsmCem_Lin1PartNrFr02_CEM_LIN1_buf *)(&(RlsmCem_Lin1PartNrFr02_CEM_LIN1))));
          break;
        case 52: /* for global object RlsmCem_Lin1PartNrFr01_CEM_LIN1 */
          VCAST_TI_9_44 ( ((_c_RlsmCem_Lin1PartNrFr01_CEM_LIN1_buf *)(&(RlsmCem_Lin1PartNrFr01_CEM_LIN1))));
          break;
        case 53: /* for global object RlsmCem_Lin1Fr03_CEM_LIN1 */
          VCAST_TI_9_33 ( ((_c_RlsmCem_Lin1Fr03_CEM_LIN1_buf *)(&(RlsmCem_Lin1Fr03_CEM_LIN1))));
          break;
        case 54: /* for global object RlsmCem_Lin1Fr02_CEM_LIN1 */
          VCAST_TI_9_35 ( ((_c_RlsmCem_Lin1Fr02_CEM_LIN1_buf *)(&(RlsmCem_Lin1Fr02_CEM_LIN1))));
          break;
        case 55: /* for global object RlsmCem_Lin1Fr01_CEM_LIN1 */
          VCAST_TI_9_12 ( ((_c_RlsmCem_Lin1Fr01_CEM_LIN1_buf *)(&(RlsmCem_Lin1Fr01_CEM_LIN1))));
          break;
        case 56: /* for global object CemCem_Lin1Fr06_CEM_LIN1 */
          VCAST_TI_9_18 ( ((_c_CemCem_Lin1Fr06_CEM_LIN1_buf *)(&(CemCem_Lin1Fr06_CEM_LIN1))));
          break;
        case 57: /* for global object CemCem_Lin1Fr05_CEM_LIN1 */
          VCAST_TI_9_1 ( ((_c_CemCem_Lin1Fr05_CEM_LIN1_buf *)(&(CemCem_Lin1Fr05_CEM_LIN1))));
          break;
        case 58: /* for global object CemCem_Lin1Fr04_CEM_LIN1 */
          VCAST_TI_9_16 ( ((_c_CemCem_Lin1Fr04_CEM_LIN1_buf *)(&(CemCem_Lin1Fr04_CEM_LIN1))));
          break;
        case 59: /* for global object CemCem_Lin1Fr03_CEM_LIN1 */
          VCAST_TI_9_14 ( ((_c_CemCem_Lin1Fr03_CEM_LIN1_buf *)(&(CemCem_Lin1Fr03_CEM_LIN1))));
          break;
        case 60: /* for global object CemCem_Lin1Fr02_CEM_LIN1 */
          VCAST_TI_9_10 ( ((_c_CemCem_Lin1Fr02_CEM_LIN1_buf *)(&(CemCem_Lin1Fr02_CEM_LIN1))));
          break;
        case 61: /* for global object CemCem_Lin1Fr01_CEM_LIN1 */
          VCAST_TI_9_24 ( ((_c_CemCem_Lin1Fr01_CEM_LIN1_buf *)(&(CemCem_Lin1Fr01_CEM_LIN1))));
          break;
        case 62: /* for global object uF_VoltageStatus_g */
          VCAST_TI_9_4 ( ((volatile Flag *)(&(uF_VoltageStatus_g))));
          break;
        case 63: /* for global object rb_InternalTemperature_g */
          VCAST_TI_9_6 ( ((unsigned char *)(&(rb_InternalTemperature_g))));
          break;
        case 64: /* for global object rb_ClockFreq_Error_cnt_g */
          VCAST_TI_9_6 ( ((unsigned char *)(&(rb_ClockFreq_Error_cnt_g))));
          break;
        case 65: /* for global object uF_uC_Error_g */
          VCAST_TI_9_23 ( ((Flag *)(&(uF_uC_Error_g))));
          break;
        case 66: /* for global object uF_Diagnose_pre_Flag */
          VCAST_TI_9_23 ( ((Flag *)(&(uF_Diagnose_pre_Flag))));
          break;
        case 67: /* for global object rub_RSIntermDelayInit */
          VCAST_TI_9_6 ( ((unsigned char *)(&(rub_RSIntermDelayInit))));
          break;
        case 68: /* for global object rb_LimitMemomryNoWiperReaction_g */
          VCAST_TI_9_6 ( ((unsigned char *)(&(rb_LimitMemomryNoWiperReaction_g))));
          break;
        case 69: /* for global object rbi_WiperStarted_g */
          VCAST_TI_9_6 ( ((unsigned char *)(&(rbi_WiperStarted_g))));
          break;
        case 70: /* for global object rb_LIN_SensitivityShift_g */
          VCAST_TI_9_6 ( ((unsigned char *)(&(rb_LIN_SensitivityShift_g))));
          break;
        case 71: /* for global object RSStatus */
          VCAST_TI_9_20 ( ((volatile RS_Flag *)(&(RSStatus))));
          break;
        case 72: /* for global object rub_IntermDelayTime */
          VCAST_TI_9_6 ( ((unsigned char *)(&(rub_IntermDelayTime))));
          break;
        case 73: /* for global object rb_PotiStageFromBox_g */
          VCAST_TI_9_6 ( ((unsigned char *)(&(rb_PotiStageFromBox_g))));
          break;
        case 74: /* for global object rw_rain_intensitiy_g */
          VCAST_TI_9_22 ( ((unsigned *)(&(rw_rain_intensitiy_g))));
          break;
        case 75: /* for global object uF_StatusRainsensor_mg */
          VCAST_TI_9_23 ( ((Flag *)(&(uF_StatusRainsensor_mg))));
          break;
        case 76: /* for global object uF_StatusRainsensor2_mg */
          VCAST_TI_9_23 ( ((Flag *)(&(uF_StatusRainsensor2_mg))));
          break;
        case 77: /* for global object rb_WiperSpeed_g */
          VCAST_TI_9_6 ( ((unsigned char *)(&(rb_WiperSpeed_g))));
          break;
        case 78: /* for global object rb_WiperSpeedAlt_g */
          VCAST_TI_9_6 ( ((unsigned char *)(&(rb_WiperSpeedAlt_g))));
          break;
        case 79: /* for global object uF_LIN_DiagReq2_mg */
          VCAST_TI_9_4 ( ((volatile Flag *)(&(uF_LIN_DiagReq2_mg))));
          break;
        case 80: /* for global object uF_Main_Flags_g */
          VCAST_TI_9_4 ( ((volatile Flag *)(&(uF_Main_Flags_g))));
          break;
        case 81: /* for global object rb_RS_LS_Error1_g */
          VCAST_TI_9_6 ( ((unsigned char *)(&(rb_RS_LS_Error1_g))));
          break;
        case 82: /* for global object rb_RS_LS_Error2_g */
          VCAST_TI_9_6 ( ((unsigned char *)(&(rb_RS_LS_Error2_g))));
          break;
        case 83: /* for global object rb_RainS_Error1_g */
          VCAST_TI_9_6 ( ((unsigned char *)(&(rb_RainS_Error1_g))));
          break;
        case 84: /* for global object rb_LightS_Error1_g */
          VCAST_TI_9_6 ( ((unsigned char *)(&(rb_LightS_Error1_g))));
          break;
        case 85: /* for global object rw_EEPROM_Address_to_Write_g */
          VCAST_TI_9_22 ( ((unsigned *)(&(rw_EEPROM_Address_to_Write_g))));
          break;
        case 86: /* for global object rb_I2C_EEPROM_bytesToWrite_g */
          VCAST_TI_9_6 ( ((unsigned char *)(&(rb_I2C_EEPROM_bytesToWrite_g))));
          break;
        case 87: /* for global object rab_EEPROM_Bytes_toWrite_g */
          VCAST_TI_9_54 ( ((unsigned char *)(rab_EEPROM_Bytes_toWrite_g)));
          break;
        case 88: /* for global object uF_E2ConfigErrorFlags_g */
          VCAST_TI_9_4 ( ((volatile Flag *)(&(uF_E2ConfigErrorFlags_g))));
          break;
        case 89: /* for global object rb_speed_in_kmh_g */
          VCAST_TI_9_6 ( ((unsigned char *)(&(rb_speed_in_kmh_g))));
          break;
        case 90: /* for global object rb_LSPotiStage_g */
          VCAST_TI_9_6 ( ((unsigned char *)(&(rb_LSPotiStage_g))));
          break;
        case 91: /* for global object uF_Check_lightsensor_g */
          VCAST_TI_9_23 ( ((Flag *)(&(uF_Check_lightsensor_g))));
          break;
        case 92: /* for global object uF_modi_lightsens_g */
          VCAST_TI_9_23 ( ((Flag *)(&(uF_modi_lightsens_g))));
          break;
        case 93: /* for global object uF_LightInternalStatus_g */
          VCAST_TI_9_23 ( ((Flag *)(&(uF_LightInternalStatus_g))));
          break;
        case 94: /* for global object rw_StandbyTimeOutCnt_g */
          VCAST_TI_9_22 ( ((unsigned *)(&(rw_StandbyTimeOutCnt_g))));
          break;
        case 95: /* for global object rb_ASIC_ALSx_ShortDetected_cnt_g */
          VCAST_TI_9_6 ( ((unsigned char *)(&(rb_ASIC_ALSx_ShortDetected_cnt_g))));
          break;
        case 96: /* for global object rb_ASIC_ALSx_ShortDetected_Error_g */
          VCAST_TI_9_6 ( ((unsigned char *)(&(rb_ASIC_ALSx_ShortDetected_Error_g))));
          break;
        case 97: /* for global object uF_ASIC_ControlFlags_g */
          VCAST_TI_9_23 ( ((Flag *)(&(uF_ASIC_ControlFlags_g))));
          break;
        case 98: /* for global object uF_GainAdjustFlags_g */
          VCAST_TI_9_23 ( ((Flag *)(&(uF_GainAdjustFlags_g))));
          break;
        case 99: /* for global object uF_ASIC_Error_Flags_g */
          VCAST_TI_9_23 ( ((Flag *)(&(uF_ASIC_Error_Flags_g))));
          break;
        case 100: /* for global object uF_ASIC_Error_Flags1_g */
          VCAST_TI_9_23 ( ((Flag *)(&(uF_ASIC_Error_Flags1_g))));
          break;
        case 101: /* for global object uF_ASIC_Ctrl_Error_Flags_g */
          VCAST_TI_9_23 ( ((Flag *)(&(uF_ASIC_Ctrl_Error_Flags_g))));
          break;
        case 102: /* for global object rw_Solar_light16bit_1_g */
          VCAST_TI_9_22 ( ((unsigned *)(&(rw_Solar_light16bit_1_g))));
          break;
        case 103: /* for global object rw_Solar_light16bit_2_g */
          VCAST_TI_9_22 ( ((unsigned *)(&(rw_Solar_light16bit_2_g))));
          break;
        case 104: /* for global object ras_ASIC_MUX_MeasAD_g */
          VCAST_TI_9_37 ( ((ASIC_ALI_Meas_t *)(ras_ASIC_MUX_MeasAD_g)));
          break;
        case 105: /* for global object rb_ASIC_initTimeout_g */
          VCAST_TI_9_6 ( ((unsigned char *)(&(rb_ASIC_initTimeout_g))));
          break;
        case 106: /* for global object rb_VIref_ErrCnt_g */
          VCAST_TI_9_6 ( ((unsigned char *)(&(rb_VIref_ErrCnt_g))));
          break;
        case 107: /* for global object rb_ASIC_SPI_ErrorCodeCnt_g */
          VCAST_TI_9_6 ( ((unsigned char *)(&(rb_ASIC_SPI_ErrorCodeCnt_g))));
          break;
        case 108: /* for global object rb_StaticNoValidAD_cnt_g */
          VCAST_TI_9_6 ( ((unsigned char *)(&(rb_StaticNoValidAD_cnt_g))));
          break;
        case 109: /* for global object rw_SPINoCommCounter_g */
          VCAST_TI_9_22 ( ((unsigned *)(&(rw_SPINoCommCounter_g))));
          break;
        case 14: /* for global object uF_StalkInPos_Flags_g */
          VCAST_TI_9_4 ( ((volatile Flag *)(&(uF_StalkInPos_Flags_g))));
          break;
        case 15: /* for global object rb_Verglasun_offenDebounce_mg */
          VCAST_TI_9_6 ( ((unsigned char *)(&(rb_Verglasun_offenDebounce_mg))));
          break;
        case 16: /* for global object rb_Verglasun_ClosedDebounce_mg */
          VCAST_TI_9_6 ( ((unsigned char *)(&(rb_Verglasun_ClosedDebounce_mg))));
          break;
        case 17: /* for global object rw_CommandCloseWindowTimout_mg */
          VCAST_TI_9_22 ( ((unsigned *)(&(rw_CommandCloseWindowTimout_mg))));
          break;
        case 18: /* for global object rb_KL15_mg */
          VCAST_TI_9_6 ( ((unsigned char *)(&(rb_KL15_mg))));
          break;
        case 19: /* for global object rb_AnyErrorCounterDebounce_mg */
          VCAST_TI_9_6 ( ((unsigned char *)(&(rb_AnyErrorCounterDebounce_mg))));
          break;
        case 20: /* for global object rw_AfterRSWipeCounter_mg */
          VCAST_TI_9_22 ( ((unsigned *)(&(rw_AfterRSWipeCounter_mg))));
          break;
        case 21: /* for global object rw_AfterRSWipeCounterAlt_mg */
          VCAST_TI_9_22 ( ((unsigned *)(&(rw_AfterRSWipeCounterAlt_mg))));
          break;
        case 22: /* for global object rw_AfterWWSWipeCounter_mg */
          VCAST_TI_9_22 ( ((unsigned *)(&(rw_AfterWWSWipeCounter_mg))));
          break;
        case 23: /* for global object rw_WipeCommandTimOut_mg */
          VCAST_TI_9_22 ( ((unsigned *)(&(rw_WipeCommandTimOut_mg))));
          break;
        case 24: /* for global object rb_IgnitionOndelay_mg */
          VCAST_TI_9_6 ( ((unsigned char *)(&(rb_IgnitionOndelay_mg))));
          break;
        case 25: /* for global object rb_Err_State_Light_Sens_mg */
          VCAST_TI_9_6 ( ((unsigned char *)(&(rb_Err_State_Light_Sens_mg))));
          break;
        case 26: /* for global object rb_OutsideTemp_mg */
          VCAST_TI_8_2 ( ((int *)(&(rb_OutsideTemp_mg))));
          break;
        case 27: /* for global object rb_WipeWorkStatus_mg */
          VCAST_TI_9_6 ( ((unsigned char *)(&(rb_WipeWorkStatus_mg))));
          break;
        case 28: /* for global object HUDEverageValue */
          VCAST_TI_9_50 ( ((unsigned long *)(HUDEverageValue)));
          break;
        case 29: /* for global object rb_storeHUDValueEvery500ms */
          VCAST_TI_9_49 ( ((unsigned long *)(rb_storeHUDValueEvery500ms)));
          break;
        case 30: /* for global object rb_storeFW_ValueEvery50ms */
          VCAST_TI_9_49 ( ((unsigned long *)(rb_storeFW_ValueEvery50ms)));
          break;
        case 31: /* for global object rb_storeAMB_ValueEvery50ms */
          VCAST_TI_9_49 ( ((unsigned long *)(rb_storeAMB_ValueEvery50ms)));
          break;
        case 32: /* for global object FW_Average_In_50ms */
          VCAST_TI_9_39 ( ((unsigned long *)(&(FW_Average_In_50ms))));
          break;
        case 33: /* for global object AMB_Average_In_50ms */
          VCAST_TI_9_39 ( ((unsigned long *)(&(AMB_Average_In_50ms))));
          break;
        case 34: /* for global object FW_Average_In_50ms_Old */
          VCAST_TI_9_39 ( ((unsigned long *)(&(FW_Average_In_50ms_Old))));
          break;
        case 35: /* for global object AMB_Average_In_50ms_Old */
          VCAST_TI_9_39 ( ((unsigned long *)(&(AMB_Average_In_50ms_Old))));
          break;
        case 36: /* for global object RW_Amb_Fw_Result_End */
          VCAST_TI_9_39 ( ((unsigned long *)(&(RW_Amb_Fw_Result_End))));
          break;
        case 37: /* for global object rb_hud_data_update */
          VCAST_TI_9_6 ( ((unsigned char *)(&(rb_hud_data_update))));
          break;
        case 38: /* for global object RW_Update_Time_Count */
          VCAST_TI_9_6 ( ((unsigned char *)(&(RW_Update_Time_Count))));
          break;
        default:
          vCAST_TOOL_ERROR = vCAST_true;
          break;
      } /* switch( VCAST_PARAM_INDEX ) */
      break; /* case 0 (global objects) */
    case 35: /* function sci_init */
      switch ( VCAST_PARAM_INDEX ) {
        case 1:
          VCAST_TI_9_6 ( ((unsigned char *)(&(P_10_1_1))));
          break;
      } /* switch ( VCAST_PARAM_INDEX ) */
      break; /* function sci_init */
    case 37: /* function get_rb_LightVetoCounter_g */
      switch ( VCAST_PARAM_INDEX ) {
        case 1:
          VCAST_TI_9_6 ( ((unsigned char *)(&(R_10_3))));
          break;
      } /* switch ( VCAST_PARAM_INDEX ) */
      break; /* function get_rb_LightVetoCounter_g */
    case 38: /* function get_rw_Amb_light16bit_g */
      switch ( VCAST_PARAM_INDEX ) {
        case 1:
          VCAST_TI_9_22 ( ((unsigned *)(&(R_10_4))));
          break;
      } /* switch ( VCAST_PARAM_INDEX ) */
      break; /* function get_rw_Amb_light16bit_g */
    case 39: /* function get_rl_HUD_light32bit_g */
      switch ( VCAST_PARAM_INDEX ) {
        case 1:
          VCAST_TI_9_39 ( ((unsigned long *)(&(R_10_5))));
          break;
      } /* switch ( VCAST_PARAM_INDEX ) */
      break; /* function get_rl_HUD_light32bit_g */
    case 40: /* function get_rw_IR_light16bit_g */
      switch ( VCAST_PARAM_INDEX ) {
        case 1:
          VCAST_TI_9_22 ( ((unsigned *)(&(R_10_6))));
          break;
      } /* switch ( VCAST_PARAM_INDEX ) */
      break; /* function get_rw_IR_light16bit_g */
    case 41: /* function get_rb_LightSignalErrorCnt_g */
      switch ( VCAST_PARAM_INDEX ) {
        case 1:
          VCAST_TI_9_6 ( ((unsigned char *)(&(R_10_7))));
          break;
      } /* switch ( VCAST_PARAM_INDEX ) */
      break; /* function get_rb_LightSignalErrorCnt_g */
    case 42: /* function get_rb_VDD_LightSignalErrorCnt_g */
      switch ( VCAST_PARAM_INDEX ) {
        case 1:
          VCAST_TI_9_6 ( ((unsigned char *)(&(R_10_8))));
          break;
      } /* switch ( VCAST_PARAM_INDEX ) */
      break; /* function get_rb_VDD_LightSignalErrorCnt_g */
    case 43: /* function get_rb_LEDx_LStop_error_cnt_g */
      switch ( VCAST_PARAM_INDEX ) {
        case 1:
          VCAST_TI_9_6 ( ((unsigned char *)(&(R_10_9))));
          break;
      } /* switch ( VCAST_PARAM_INDEX ) */
      break; /* function get_rb_LEDx_LStop_error_cnt_g */
    case 16: /* function ApplLinInit */
      switch ( VCAST_PARAM_INDEX ) {
        case 1:
          VCAST_TI_9_6 ( ((unsigned char *)(&(P_9_16_1))));
          break;
      } /* switch ( VCAST_PARAM_INDEX ) */
      break; /* function ApplLinInit */
    case 17: /* function ApplLinSlavePreCopy */
      switch ( VCAST_PARAM_INDEX ) {
        case 1:
          VCAST_TI_9_6 ( ((unsigned char *)(&(P_9_17_1))));
          break;
      } /* switch ( VCAST_PARAM_INDEX ) */
      break; /* function ApplLinSlavePreCopy */
    case 18: /* function GetFiveTableValue_500ms */
      switch ( VCAST_PARAM_INDEX ) {
        case 1:
          VCAST_TI_9_39 ( ((unsigned long *)(&(P_9_18_1))));
          break;
      } /* switch ( VCAST_PARAM_INDEX ) */
      break; /* function GetFiveTableValue_500ms */
    case 19: /* function AdjustOutHudValue */
      switch ( VCAST_PARAM_INDEX ) {
        case 1:
          VCAST_TI_9_39 ( ((unsigned long *)(&(P_9_19_1))));
          break;
        case 2:
          VCAST_TI_9_39 ( ((unsigned long *)(&(R_9_19))));
          break;
      } /* switch ( VCAST_PARAM_INDEX ) */
      break; /* function AdjustOutHudValue */
    case 20: /* function GetUpdateTimeForLightStatus */
      switch ( VCAST_PARAM_INDEX ) {
        case 1:
          VCAST_TI_9_6 ( ((unsigned char *)(&(R_9_20))));
          break;
      } /* switch ( VCAST_PARAM_INDEX ) */
      break; /* function GetUpdateTimeForLightStatus */
    case 21: /* function CalcHUDMean_1000ms */
      switch ( VCAST_PARAM_INDEX ) {
        case 1:
          VCAST_TI_9_39 ( ((unsigned long *)(&(R_9_21))));
          break;
      } /* switch ( VCAST_PARAM_INDEX ) */
      break; /* function CalcHUDMean_1000ms */
    case 22: /* function orderHUDValue */
      switch ( VCAST_PARAM_INDEX ) {
        case 1:
          VCAST_TI_8_2 ( ((int *)(&(P_9_22_1))));
          break;
      } /* switch ( VCAST_PARAM_INDEX ) */
      break; /* function orderHUDValue */
    case 23: /* function GetFiveTableValue_50ms */
      switch ( VCAST_PARAM_INDEX ) {
        case 1:
          VCAST_TI_9_39 ( ((unsigned long *)(&(P_9_23_1))));
          break;
        case 2:
          VCAST_TI_9_39 ( ((unsigned long *)(&(P_9_23_2))));
          break;
      } /* switch ( VCAST_PARAM_INDEX ) */
      break; /* function GetFiveTableValue_50ms */
    case 24: /* function CRC8SAEJ1850 */
      switch ( VCAST_PARAM_INDEX ) {
        case 1:
          VCAST_TI_9_53 ( ((unsigned char **)(&(P_9_24_1))));
          break;
        case 2:
          VCAST_TI_9_6 ( ((unsigned char *)(&(P_9_24_2))));
          break;
        case 3:
          VCAST_TI_9_6 ( ((unsigned char *)(&(R_9_24))));
          break;
      } /* switch ( VCAST_PARAM_INDEX ) */
      break; /* function CRC8SAEJ1850 */
    case 25: /* function GetOutdBriStsCrcj1850 */
      switch ( VCAST_PARAM_INDEX ) {
        case 1:
          VCAST_TI_9_6 ( ((unsigned char *)(&(P_9_25_1))));
          break;
        case 2:
          VCAST_TI_9_6 ( ((unsigned char *)(&(R_9_25))));
          break;
      } /* switch ( VCAST_PARAM_INDEX ) */
      break; /* function GetOutdBriStsCrcj1850 */
    case 26: /* function GetHudCrcj1850 */
      switch ( VCAST_PARAM_INDEX ) {
        case 1:
          VCAST_TI_9_39 ( ((unsigned long *)(&(P_9_26_1))));
          break;
        case 2:
          VCAST_TI_9_6 ( ((unsigned char *)(&(R_9_26))));
          break;
      } /* switch ( VCAST_PARAM_INDEX ) */
      break; /* function GetHudCrcj1850 */
    case 27: /* function GetLightTransmission */
      switch ( VCAST_PARAM_INDEX ) {
        case 1:
          VCAST_TI_9_6 ( ((unsigned char *)(&(P_9_27_1))));
          break;
        case 2:
          VCAST_TI_9_6 ( ((unsigned char *)(&(P_9_27_2))));
          break;
      } /* switch ( VCAST_PARAM_INDEX ) */
      break; /* function GetLightTransmission */
    case 28: /* function Get_BCMVehType */
      switch ( VCAST_PARAM_INDEX ) {
        case 1:
          VCAST_TI_9_6 ( ((unsigned char *)(&(P_9_28_1))));
          break;
      } /* switch ( VCAST_PARAM_INDEX ) */
      break; /* function Get_BCMVehType */
    case 29: /* function Set_BCMLightOffset */
      switch ( VCAST_PARAM_INDEX ) {
        case 1:
          VCAST_TI_9_6 ( ((unsigned char *)(&(P_9_29_1))));
          break;
      } /* switch ( VCAST_PARAM_INDEX ) */
      break; /* function Set_BCMLightOffset */
    case 34: /* function IsByteOddParity */
      switch ( VCAST_PARAM_INDEX ) {
        case 1:
          VCAST_TI_9_6 ( ((unsigned char *)(&(P_9_34_1))));
          break;
        case 2:
          VCAST_TI_9_6 ( ((unsigned char *)(&(R_9_34))));
          break;
      } /* switch ( VCAST_PARAM_INDEX ) */
      break; /* function IsByteOddParity */
    default:
      vCAST_TOOL_ERROR = vCAST_true;
      break;
  } /* switch ( VCAST_SUB_INDEX ) */
}
/* A typedef */
void VCAST_TI_9_26 ( s_rb_EEPROMStructPD_buff_g *vcast_param ) 
{
  {
    int VCAST_TI_9_67_jmpval;
    VCAST_TI_9_67_jmpval = setjmp ( VCAST_env );
    vcast_is_in_union = vCAST_false;
    if ( VCAST_TI_9_67_jmpval == 0 ) {
      vcast_is_in_union = vCAST_true;
      switch ( vcast_get_param () ) { /* Choose field member */
        /* Setting member variable vcast_param->_c */
        case 1: { 
          VCAST_TI_9_68 ( ((unsigned char *)(vcast_param->_c)));
          break; /* end case 1*/
        } /* end case */
        /* Setting member variable vcast_param->EEPROMStructPD */
        case 2: { 
          VCAST_TI_9_27 ( ((s_rb_EEPROMStruct_PD_g *)(&(vcast_param->EEPROMStructPD))));
          break; /* end case 2*/
        } /* end case */
        default:
          vCAST_TOOL_ERROR = vCAST_true;
      } /* end switch */ 
    } else if ( vCAST_COMMAND == vCAST_PRINT )
      vectorcast_fprint_string(vCAST_OUTPUT_FILE,"invalid address\n");
  }
} /* end VCAST_TI_9_26 */
/* An integer */
void VCAST_TI_9_6 ( unsigned char *vcast_param ) 
{
  switch (vCAST_COMMAND) {
    case vCAST_PRINT :
      if ( vcast_param == 0)
        vectorcast_fprint_string (vCAST_OUTPUT_FILE,"null\n");
      else {
        vectorcast_fprint_integer(vCAST_OUTPUT_FILE, *vcast_param);
        vectorcast_fprint_string(vCAST_OUTPUT_FILE, "\n");
      }
      break;
    case vCAST_KEEP_VAL:
      break; /* KEEP doesn't do anything */
  case vCAST_SET_VAL :
    *vcast_param = ( unsigned char  ) vCAST_VALUE_INT;
    break;
  case vCAST_FIRST_VAL :
    *vcast_param = 0;
    break;
  case vCAST_MID_VAL :
    *vcast_param = (0 / 2) + (0xff / 2);
    break;
  case vCAST_LAST_VAL :
    *vcast_param = 0xff;
    break;
  case vCAST_MIN_MINUS_1_VAL :
    *vcast_param = 0;
    *vcast_param = *vcast_param - 1;
    break;
  case vCAST_MAX_PLUS_1_VAL :
    *vcast_param = 0xff;
    *vcast_param = *vcast_param + 1;
    break;
  case vCAST_ZERO_VAL :
    *vcast_param = 0;
    break;
  default:
    break;
} /* end switch */
} /* end VCAST_TI_9_6 */
/* An integer */
void VCAST_TI_9_22 ( unsigned *vcast_param ) 
{
  switch (vCAST_COMMAND) {
    case vCAST_PRINT :
      if ( vcast_param == 0)
        vectorcast_fprint_string (vCAST_OUTPUT_FILE,"null\n");
      else {
        vectorcast_fprint_unsigned_integer(vCAST_OUTPUT_FILE, *vcast_param);
        vectorcast_fprint_string(vCAST_OUTPUT_FILE, "\n");
      }
      break;
    case vCAST_KEEP_VAL:
      break; /* KEEP doesn't do anything */
  case vCAST_SET_VAL :
    *vcast_param = ( unsigned  ) vCAST_VALUE_UNSIGNED;
    break;
  case vCAST_FIRST_VAL :
    *vcast_param = 0;
    break;
  case vCAST_MID_VAL :
    *vcast_param = (0 / 2) + (0xffffU / 2);
    break;
  case vCAST_LAST_VAL :
    *vcast_param = 0xffffU;
    break;
  case vCAST_MIN_MINUS_1_VAL :
    *vcast_param = 0;
    *vcast_param = *vcast_param - 1;
    break;
  case vCAST_MAX_PLUS_1_VAL :
    *vcast_param = 0xffffU;
    *vcast_param = *vcast_param + 1;
    break;
  case vCAST_ZERO_VAL :
    *vcast_param = 0;
    break;
  default:
    break;
} /* end switch */
} /* end VCAST_TI_9_22 */
/* A typedef */
void VCAST_TI_9_28 ( s_rb_EEPROMStructAD_buff_g *vcast_param ) 
{
  {
    int VCAST_TI_9_78_jmpval;
    VCAST_TI_9_78_jmpval = setjmp ( VCAST_env );
    vcast_is_in_union = vCAST_false;
    if ( VCAST_TI_9_78_jmpval == 0 ) {
      vcast_is_in_union = vCAST_true;
      switch ( vcast_get_param () ) { /* Choose field member */
        /* Setting member variable vcast_param->_c */
        case 1: { 
          VCAST_TI_9_79 ( ((unsigned char *)(vcast_param->_c)));
          break; /* end case 1*/
        } /* end case */
        /* Setting member variable vcast_param->EEPROMStructAD */
        case 2: { 
          VCAST_TI_9_29 ( ((s_rb_EEPROMStruct_AD_g *)(&(vcast_param->EEPROMStructAD))));
          break; /* end case 2*/
        } /* end case */
        default:
          vCAST_TOOL_ERROR = vCAST_true;
      } /* end switch */ 
    } else if ( vCAST_COMMAND == vCAST_PRINT )
      vectorcast_fprint_string(vCAST_OUTPUT_FILE,"invalid address\n");
  }
} /* end VCAST_TI_9_28 */
/* A union */
void VCAST_TI_9_7 ( union tLinIndicationBits *vcast_param ) 
{
  {
    int VCAST_TI_9_7_jmpval;
    VCAST_TI_9_7_jmpval = setjmp ( VCAST_env );
    vcast_is_in_union = vCAST_false;
    if ( VCAST_TI_9_7_jmpval == 0 ) {
      vcast_is_in_union = vCAST_true;
      switch ( vcast_get_param () ) { /* Choose field member */
        /* Setting member variable vcast_param->_c */
        case 1: { 
          VCAST_TI_9_80 ( ((unsigned char *)(vcast_param->_c)));
          break; /* end case 1*/
        } /* end case */
        /* Setting member variable vcast_param->w */
        case 2: { 
          VCAST_TI_9_8 ( ((struct _c_bits8 *)(vcast_param->w)));
          break; /* end case 2*/
        } /* end case */
        default:
          vCAST_TOOL_ERROR = vCAST_true;
      } /* end switch */ 
    } else if ( vCAST_COMMAND == vCAST_PRINT )
      vectorcast_fprint_string(vCAST_OUTPUT_FILE,"invalid address\n");
  }
} /* end VCAST_TI_9_7 */
/* A union */
void VCAST_TI_9_30 ( union tLinConfirmationBits *vcast_param ) 
{
  {
    int VCAST_TI_9_30_jmpval;
    VCAST_TI_9_30_jmpval = setjmp ( VCAST_env );
    vcast_is_in_union = vCAST_false;
    if ( VCAST_TI_9_30_jmpval == 0 ) {
      vcast_is_in_union = vCAST_true;
      switch ( vcast_get_param () ) { /* Choose field member */
        /* Setting member variable vcast_param->_c */
        case 1: { 
          VCAST_TI_9_81 ( ((unsigned char *)(vcast_param->_c)));
          break; /* end case 1*/
        } /* end case */
        /* Setting member variable vcast_param->w */
        case 2: { 
          VCAST_TI_9_31 ( ((struct _c_bits16 *)(vcast_param->w)));
          break; /* end case 2*/
        } /* end case */
        default:
          vCAST_TOOL_ERROR = vCAST_true;
      } /* end switch */ 
    } else if ( vCAST_COMMAND == vCAST_PRINT )
      vectorcast_fprint_string(vCAST_OUTPUT_FILE,"invalid address\n");
  }
} /* end VCAST_TI_9_30 */
/* A typedef */
void VCAST_TI_9_4 ( volatile Flag *vcast_param ) 
{
  {
    int VCAST_TI_9_61_jmpval;
    VCAST_TI_9_61_jmpval = setjmp ( VCAST_env );
    vcast_is_in_union = vCAST_false;
    if ( VCAST_TI_9_61_jmpval == 0 ) {
      vcast_is_in_union = vCAST_true;
      switch ( vcast_get_param () ) { /* Choose field member */
        /* Setting member variable vcast_param->Bit */
        case 1: { 
          VCAST_TI_9_5 ( ((Bit_Feld *)(&(vcast_param->Bit))));
          break; /* end case 1*/
        } /* end case */
        /* Setting member variable vcast_param->AllBit */
        case 2: { 
          VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->AllBit))));
          break; /* end case 2*/
        } /* end case */
        default:
          vCAST_TOOL_ERROR = vCAST_true;
      } /* end switch */ 
    } else if ( vCAST_COMMAND == vCAST_PRINT )
      vectorcast_fprint_string(vCAST_OUTPUT_FILE,"invalid address\n");
  }
} /* end VCAST_TI_9_4 */
/* A typedef */
void VCAST_TI_9_23 ( Flag *vcast_param ) 
{
  {
    int VCAST_TI_9_61_jmpval;
    VCAST_TI_9_61_jmpval = setjmp ( VCAST_env );
    vcast_is_in_union = vCAST_false;
    if ( VCAST_TI_9_61_jmpval == 0 ) {
      vcast_is_in_union = vCAST_true;
      switch ( vcast_get_param () ) { /* Choose field member */
        /* Setting member variable vcast_param->Bit */
        case 1: { 
          VCAST_TI_9_5 ( ((Bit_Feld *)(&(vcast_param->Bit))));
          break; /* end case 1*/
        } /* end case */
        /* Setting member variable vcast_param->AllBit */
        case 2: { 
          VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->AllBit))));
          break; /* end case 2*/
        } /* end case */
        default:
          vCAST_TOOL_ERROR = vCAST_true;
      } /* end switch */ 
    } else if ( vCAST_COMMAND == vCAST_PRINT )
      vectorcast_fprint_string(vCAST_OUTPUT_FILE,"invalid address\n");
  }
} /* end VCAST_TI_9_23 */
/* A typedef */
void VCAST_TI_9_40 ( _c_RlsmCem_SerNrLin1Fr01_CEM_LIN1_buf *vcast_param ) 
{
  {
    int VCAST_TI_9_94_jmpval;
    VCAST_TI_9_94_jmpval = setjmp ( VCAST_env );
    vcast_is_in_union = vCAST_false;
    if ( VCAST_TI_9_94_jmpval == 0 ) {
      vcast_is_in_union = vCAST_true;
      switch ( vcast_get_param () ) { /* Choose field member */
        /* Setting member variable vcast_param->_c */
        case 1: { 
          VCAST_TI_9_41 ( ((unsigned char *)(vcast_param->_c)));
          break; /* end case 1*/
        } /* end case */
        /* Setting member variable vcast_param->rlsmcem_sernrlin1fr01_cem_lin1 */
        case 2: { 
          VCAST_TI_9_55 ( ((_c_RlsmCem_SerNrLin1Fr01_CEM_LIN1_msgType *)(&(vcast_param->rlsmcem_sernrlin1fr01_cem_lin1))));
          break; /* end case 2*/
        } /* end case */
        default:
          vCAST_TOOL_ERROR = vCAST_true;
      } /* end switch */ 
    } else if ( vCAST_COMMAND == vCAST_PRINT )
      vectorcast_fprint_string(vCAST_OUTPUT_FILE,"invalid address\n");
  }
} /* end VCAST_TI_9_40 */
/* A typedef */
void VCAST_TI_9_42 ( _c_RlsmCem_Lin1PartNrFr02_CEM_LIN1_buf *vcast_param ) 
{
  {
    int VCAST_TI_9_95_jmpval;
    VCAST_TI_9_95_jmpval = setjmp ( VCAST_env );
    vcast_is_in_union = vCAST_false;
    if ( VCAST_TI_9_95_jmpval == 0 ) {
      vcast_is_in_union = vCAST_true;
      switch ( vcast_get_param () ) { /* Choose field member */
        /* Setting member variable vcast_param->_c */
        case 1: { 
          VCAST_TI_9_43 ( ((unsigned char *)(vcast_param->_c)));
          break; /* end case 1*/
        } /* end case */
        /* Setting member variable vcast_param->rlsmcem_lin1partnrfr02_cem_lin1 */
        case 2: { 
          VCAST_TI_9_59 ( ((_c_RlsmCem_Lin1PartNrFr02_CEM_LIN1_msgType *)(&(vcast_param->rlsmcem_lin1partnrfr02_cem_lin1))));
          break; /* end case 2*/
        } /* end case */
        default:
          vCAST_TOOL_ERROR = vCAST_true;
      } /* end switch */ 
    } else if ( vCAST_COMMAND == vCAST_PRINT )
      vectorcast_fprint_string(vCAST_OUTPUT_FILE,"invalid address\n");
  }
} /* end VCAST_TI_9_42 */
/* A typedef */
void VCAST_TI_9_44 ( _c_RlsmCem_Lin1PartNrFr01_CEM_LIN1_buf *vcast_param ) 
{
  {
    int VCAST_TI_9_96_jmpval;
    VCAST_TI_9_96_jmpval = setjmp ( VCAST_env );
    vcast_is_in_union = vCAST_false;
    if ( VCAST_TI_9_96_jmpval == 0 ) {
      vcast_is_in_union = vCAST_true;
      switch ( vcast_get_param () ) { /* Choose field member */
        /* Setting member variable vcast_param->_c */
        case 1: { 
          VCAST_TI_9_45 ( ((unsigned char *)(vcast_param->_c)));
          break; /* end case 1*/
        } /* end case */
        /* Setting member variable vcast_param->rlsmcem_lin1partnrfr01_cem_lin1 */
        case 2: { 
          VCAST_TI_9_57 ( ((_c_RlsmCem_Lin1PartNrFr01_CEM_LIN1_msgType *)(&(vcast_param->rlsmcem_lin1partnrfr01_cem_lin1))));
          break; /* end case 2*/
        } /* end case */
        default:
          vCAST_TOOL_ERROR = vCAST_true;
      } /* end switch */ 
    } else if ( vCAST_COMMAND == vCAST_PRINT )
      vectorcast_fprint_string(vCAST_OUTPUT_FILE,"invalid address\n");
  }
} /* end VCAST_TI_9_44 */
/* A typedef */
void VCAST_TI_9_33 ( _c_RlsmCem_Lin1Fr03_CEM_LIN1_buf *vcast_param ) 
{
  {
    int VCAST_TI_9_97_jmpval;
    VCAST_TI_9_97_jmpval = setjmp ( VCAST_env );
    vcast_is_in_union = vCAST_false;
    if ( VCAST_TI_9_97_jmpval == 0 ) {
      vcast_is_in_union = vCAST_true;
      switch ( vcast_get_param () ) { /* Choose field member */
        /* Setting member variable vcast_param->_c */
        case 1: { 
          VCAST_TI_9_43 ( ((unsigned char *)(vcast_param->_c)));
          break; /* end case 1*/
        } /* end case */
        /* Setting member variable vcast_param->rlsmcem_lin1fr03_cem_lin1 */
        case 2: { 
          VCAST_TI_9_34 ( ((_c_RlsmCem_Lin1Fr03_CEM_LIN1_msgType *)(&(vcast_param->rlsmcem_lin1fr03_cem_lin1))));
          break; /* end case 2*/
        } /* end case */
        default:
          vCAST_TOOL_ERROR = vCAST_true;
      } /* end switch */ 
    } else if ( vCAST_COMMAND == vCAST_PRINT )
      vectorcast_fprint_string(vCAST_OUTPUT_FILE,"invalid address\n");
  }
} /* end VCAST_TI_9_33 */
/* A typedef */
void VCAST_TI_9_35 ( _c_RlsmCem_Lin1Fr02_CEM_LIN1_buf *vcast_param ) 
{
  {
    int VCAST_TI_9_98_jmpval;
    VCAST_TI_9_98_jmpval = setjmp ( VCAST_env );
    vcast_is_in_union = vCAST_false;
    if ( VCAST_TI_9_98_jmpval == 0 ) {
      vcast_is_in_union = vCAST_true;
      switch ( vcast_get_param () ) { /* Choose field member */
        /* Setting member variable vcast_param->_c */
        case 1: { 
          VCAST_TI_9_43 ( ((unsigned char *)(vcast_param->_c)));
          break; /* end case 1*/
        } /* end case */
        /* Setting member variable vcast_param->rlsmcem_lin1fr02_cem_lin1 */
        case 2: { 
          VCAST_TI_9_36 ( ((_c_RlsmCem_Lin1Fr02_CEM_LIN1_msgType *)(&(vcast_param->rlsmcem_lin1fr02_cem_lin1))));
          break; /* end case 2*/
        } /* end case */
        default:
          vCAST_TOOL_ERROR = vCAST_true;
      } /* end switch */ 
    } else if ( vCAST_COMMAND == vCAST_PRINT )
      vectorcast_fprint_string(vCAST_OUTPUT_FILE,"invalid address\n");
  }
} /* end VCAST_TI_9_35 */
/* A typedef */
void VCAST_TI_9_12 ( _c_RlsmCem_Lin1Fr01_CEM_LIN1_buf *vcast_param ) 
{
  {
    int VCAST_TI_9_99_jmpval;
    VCAST_TI_9_99_jmpval = setjmp ( VCAST_env );
    vcast_is_in_union = vCAST_false;
    if ( VCAST_TI_9_99_jmpval == 0 ) {
      vcast_is_in_union = vCAST_true;
      switch ( vcast_get_param () ) { /* Choose field member */
        /* Setting member variable vcast_param->_c */
        case 1: { 
          VCAST_TI_9_43 ( ((unsigned char *)(vcast_param->_c)));
          break; /* end case 1*/
        } /* end case */
        /* Setting member variable vcast_param->rlsmcem_lin1fr01_cem_lin1 */
        case 2: { 
          VCAST_TI_9_13 ( ((_c_RlsmCem_Lin1Fr01_CEM_LIN1_msgType *)(&(vcast_param->rlsmcem_lin1fr01_cem_lin1))));
          break; /* end case 2*/
        } /* end case */
        default:
          vCAST_TOOL_ERROR = vCAST_true;
      } /* end switch */ 
    } else if ( vCAST_COMMAND == vCAST_PRINT )
      vectorcast_fprint_string(vCAST_OUTPUT_FILE,"invalid address\n");
  }
} /* end VCAST_TI_9_12 */
/* A typedef */
void VCAST_TI_9_18 ( _c_CemCem_Lin1Fr06_CEM_LIN1_buf *vcast_param ) 
{
  {
    int VCAST_TI_9_100_jmpval;
    VCAST_TI_9_100_jmpval = setjmp ( VCAST_env );
    vcast_is_in_union = vCAST_false;
    if ( VCAST_TI_9_100_jmpval == 0 ) {
      vcast_is_in_union = vCAST_true;
      switch ( vcast_get_param () ) { /* Choose field member */
        /* Setting member variable vcast_param->_c */
        case 1: { 
          VCAST_TI_9_80 ( ((unsigned char *)(vcast_param->_c)));
          break; /* end case 1*/
        } /* end case */
        /* Setting member variable vcast_param->cemcem_lin1fr06_cem_lin1 */
        case 2: { 
          VCAST_TI_9_19 ( ((_c_CemCem_Lin1Fr06_CEM_LIN1_msgType *)(&(vcast_param->cemcem_lin1fr06_cem_lin1))));
          break; /* end case 2*/
        } /* end case */
        default:
          vCAST_TOOL_ERROR = vCAST_true;
      } /* end switch */ 
    } else if ( vCAST_COMMAND == vCAST_PRINT )
      vectorcast_fprint_string(vCAST_OUTPUT_FILE,"invalid address\n");
  }
} /* end VCAST_TI_9_18 */
/* A typedef */
void VCAST_TI_9_1 ( _c_CemCem_Lin1Fr05_CEM_LIN1_buf *vcast_param ) 
{
  {
    int VCAST_TI_9_102_jmpval;
    VCAST_TI_9_102_jmpval = setjmp ( VCAST_env );
    vcast_is_in_union = vCAST_false;
    if ( VCAST_TI_9_102_jmpval == 0 ) {
      vcast_is_in_union = vCAST_true;
      switch ( vcast_get_param () ) { /* Choose field member */
        /* Setting member variable vcast_param->_c */
        case 1: { 
          VCAST_TI_9_45 ( ((unsigned char *)(vcast_param->_c)));
          break; /* end case 1*/
        } /* end case */
        /* Setting member variable vcast_param->cemcem_lin1fr05_cem_lin1 */
        case 2: { 
          VCAST_TI_9_2 ( ((_c_CemCem_Lin1Fr05_CEM_LIN1_msgType *)(&(vcast_param->cemcem_lin1fr05_cem_lin1))));
          break; /* end case 2*/
        } /* end case */
        default:
          vCAST_TOOL_ERROR = vCAST_true;
      } /* end switch */ 
    } else if ( vCAST_COMMAND == vCAST_PRINT )
      vectorcast_fprint_string(vCAST_OUTPUT_FILE,"invalid address\n");
  }
} /* end VCAST_TI_9_1 */
/* A typedef */
void VCAST_TI_9_16 ( _c_CemCem_Lin1Fr04_CEM_LIN1_buf *vcast_param ) 
{
  {
    int VCAST_TI_9_104_jmpval;
    VCAST_TI_9_104_jmpval = setjmp ( VCAST_env );
    vcast_is_in_union = vCAST_false;
    if ( VCAST_TI_9_104_jmpval == 0 ) {
      vcast_is_in_union = vCAST_true;
      switch ( vcast_get_param () ) { /* Choose field member */
        /* Setting member variable vcast_param->_c */
        case 1: { 
          VCAST_TI_9_45 ( ((unsigned char *)(vcast_param->_c)));
          break; /* end case 1*/
        } /* end case */
        /* Setting member variable vcast_param->cemcem_lin1fr04_cem_lin1 */
        case 2: { 
          VCAST_TI_9_17 ( ((_c_CemCem_Lin1Fr04_CEM_LIN1_msgType *)(&(vcast_param->cemcem_lin1fr04_cem_lin1))));
          break; /* end case 2*/
        } /* end case */
        default:
          vCAST_TOOL_ERROR = vCAST_true;
      } /* end switch */ 
    } else if ( vCAST_COMMAND == vCAST_PRINT )
      vectorcast_fprint_string(vCAST_OUTPUT_FILE,"invalid address\n");
  }
} /* end VCAST_TI_9_16 */
/* A typedef */
void VCAST_TI_9_14 ( _c_CemCem_Lin1Fr03_CEM_LIN1_buf *vcast_param ) 
{
  {
    int VCAST_TI_9_106_jmpval;
    VCAST_TI_9_106_jmpval = setjmp ( VCAST_env );
    vcast_is_in_union = vCAST_false;
    if ( VCAST_TI_9_106_jmpval == 0 ) {
      vcast_is_in_union = vCAST_true;
      switch ( vcast_get_param () ) { /* Choose field member */
        /* Setting member variable vcast_param->_c */
        case 1: { 
          VCAST_TI_9_43 ( ((unsigned char *)(vcast_param->_c)));
          break; /* end case 1*/
        } /* end case */
        /* Setting member variable vcast_param->cemcem_lin1fr03_cem_lin1 */
        case 2: { 
          VCAST_TI_9_15 ( ((_c_CemCem_Lin1Fr03_CEM_LIN1_msgType *)(&(vcast_param->cemcem_lin1fr03_cem_lin1))));
          break; /* end case 2*/
        } /* end case */
        default:
          vCAST_TOOL_ERROR = vCAST_true;
      } /* end switch */ 
    } else if ( vCAST_COMMAND == vCAST_PRINT )
      vectorcast_fprint_string(vCAST_OUTPUT_FILE,"invalid address\n");
  }
} /* end VCAST_TI_9_14 */
/* A typedef */
void VCAST_TI_9_10 ( _c_CemCem_Lin1Fr02_CEM_LIN1_buf *vcast_param ) 
{
  {
    int VCAST_TI_9_108_jmpval;
    VCAST_TI_9_108_jmpval = setjmp ( VCAST_env );
    vcast_is_in_union = vCAST_false;
    if ( VCAST_TI_9_108_jmpval == 0 ) {
      vcast_is_in_union = vCAST_true;
      switch ( vcast_get_param () ) { /* Choose field member */
        /* Setting member variable vcast_param->_c */
        case 1: { 
          VCAST_TI_9_45 ( ((unsigned char *)(vcast_param->_c)));
          break; /* end case 1*/
        } /* end case */
        /* Setting member variable vcast_param->cemcem_lin1fr02_cem_lin1 */
        case 2: { 
          VCAST_TI_9_11 ( ((_c_CemCem_Lin1Fr02_CEM_LIN1_msgType *)(&(vcast_param->cemcem_lin1fr02_cem_lin1))));
          break; /* end case 2*/
        } /* end case */
        default:
          vCAST_TOOL_ERROR = vCAST_true;
      } /* end switch */ 
    } else if ( vCAST_COMMAND == vCAST_PRINT )
      vectorcast_fprint_string(vCAST_OUTPUT_FILE,"invalid address\n");
  }
} /* end VCAST_TI_9_10 */
/* A typedef */
void VCAST_TI_9_24 ( _c_CemCem_Lin1Fr01_CEM_LIN1_buf *vcast_param ) 
{
  {
    int VCAST_TI_9_110_jmpval;
    VCAST_TI_9_110_jmpval = setjmp ( VCAST_env );
    vcast_is_in_union = vCAST_false;
    if ( VCAST_TI_9_110_jmpval == 0 ) {
      vcast_is_in_union = vCAST_true;
      switch ( vcast_get_param () ) { /* Choose field member */
        /* Setting member variable vcast_param->_c */
        case 1: { 
          VCAST_TI_9_111 ( ((unsigned char *)(vcast_param->_c)));
          break; /* end case 1*/
        } /* end case */
        /* Setting member variable vcast_param->cemcem_lin1fr01_cem_lin1 */
        case 2: { 
          VCAST_TI_9_25 ( ((_c_CemCem_Lin1Fr01_CEM_LIN1_msgType *)(&(vcast_param->cemcem_lin1fr01_cem_lin1))));
          break; /* end case 2*/
        } /* end case */
        default:
          vCAST_TOOL_ERROR = vCAST_true;
      } /* end switch */ 
    } else if ( vCAST_COMMAND == vCAST_PRINT )
      vectorcast_fprint_string(vCAST_OUTPUT_FILE,"invalid address\n");
  }
} /* end VCAST_TI_9_24 */
/* A typedef */
void VCAST_TI_9_20 ( volatile RS_Flag *vcast_param ) 
{
  {
    int VCAST_TI_9_113_jmpval;
    VCAST_TI_9_113_jmpval = setjmp ( VCAST_env );
    vcast_is_in_union = vCAST_false;
    if ( VCAST_TI_9_113_jmpval == 0 ) {
      vcast_is_in_union = vCAST_true;
      switch ( vcast_get_param () ) { /* Choose field member */
        /* Setting member variable vcast_param->Bit */
        case 1: { 
          VCAST_TI_9_21 ( ((RS_Bit_Feld *)(&(vcast_param->Bit))));
          break; /* end case 1*/
        } /* end case */
        /* Setting member variable vcast_param->AllBit */
        case 2: { 
          VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->AllBit))));
          break; /* end case 2*/
        } /* end case */
        default:
          vCAST_TOOL_ERROR = vCAST_true;
      } /* end switch */ 
    } else if ( vCAST_COMMAND == vCAST_PRINT )
      vectorcast_fprint_string(vCAST_OUTPUT_FILE,"invalid address\n");
  }
} /* end VCAST_TI_9_20 */
/* An array */
void VCAST_TI_9_54 ( unsigned char vcast_param[5] ) 
{
  {
    int VCAST_TI_9_54_array_index = 0;
    int VCAST_TI_9_54_index = 0;
    int VCAST_TI_9_54_first, VCAST_TI_9_54_last;
    int VCAST_TI_9_54_more_data; /* true if there is more data in the current command */
    int VCAST_TI_9_54_local_field = 0;
    int VCAST_TI_9_54_value_printed = 0;
    int VCAST_TI_9_54_is_string = (VCAST_FIND_INDEX()==-1);
    vcast_get_range_value (&VCAST_TI_9_54_first, &VCAST_TI_9_54_last, &VCAST_TI_9_54_more_data);
    VCAST_TI_9_54_local_field = vCAST_DATA_FIELD;
    if ( vCAST_SIZE && (!VCAST_TI_9_54_more_data)) { /* get the size of the array */
      vectorcast_fprint_integer (vCAST_OUTPUT_FILE,5);
      vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
      vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n");
    } else {
      int VCAST_TI_9_54_upper = 5;
      for (VCAST_TI_9_54_array_index=0; VCAST_TI_9_54_array_index< VCAST_TI_9_54_upper; VCAST_TI_9_54_array_index++){
        if ( (VCAST_TI_9_54_index >= VCAST_TI_9_54_first) && ( VCAST_TI_9_54_index <= VCAST_TI_9_54_last)){
          if ( VCAST_TI_9_54_is_string )
            VCAST_TI_STRING ( (char**)&vcast_param, sizeof ( vcast_param ), 1,VCAST_TI_9_54_upper);
          else
            VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param[VCAST_TI_9_54_index]))));
          VCAST_TI_9_54_value_printed = 1;
          vCAST_DATA_FIELD = VCAST_TI_9_54_local_field;
        } /* if */
        if (VCAST_TI_9_54_index >= VCAST_TI_9_54_last)
          break;
        VCAST_TI_9_54_index++;
      } /* loop */
      if ((vCAST_COMMAND == vCAST_PRINT)&&(!VCAST_TI_9_54_value_printed))
        vectorcast_fprint_string(vCAST_OUTPUT_FILE,"<<past end of array>>\n");
    } /* if */
  }
} /* end VCAST_TI_9_54 */
/* An array */
void VCAST_TI_9_37 ( ASIC_ALI_Meas_t vcast_param[9] ) 
{
  {
    int VCAST_TI_9_37_array_index = 0;
    int VCAST_TI_9_37_index = 0;
    int VCAST_TI_9_37_first, VCAST_TI_9_37_last;
    int VCAST_TI_9_37_more_data; /* true if there is more data in the current command */
    int VCAST_TI_9_37_local_field = 0;
    int VCAST_TI_9_37_value_printed = 0;
    vcast_get_range_value (&VCAST_TI_9_37_first, &VCAST_TI_9_37_last, &VCAST_TI_9_37_more_data);
    VCAST_TI_9_37_local_field = vCAST_DATA_FIELD;
    if ( vCAST_SIZE && (!VCAST_TI_9_37_more_data)) { /* get the size of the array */
      vectorcast_fprint_integer (vCAST_OUTPUT_FILE,9);
      vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
      vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n");
    } else {
      int VCAST_TI_9_37_upper = 9;
      for (VCAST_TI_9_37_array_index=0; VCAST_TI_9_37_array_index< VCAST_TI_9_37_upper; VCAST_TI_9_37_array_index++){
        if ( (VCAST_TI_9_37_index >= VCAST_TI_9_37_first) && ( VCAST_TI_9_37_index <= VCAST_TI_9_37_last)){
          VCAST_TI_9_38 ( ((ASIC_ALI_Meas_t *)(&(vcast_param[VCAST_TI_9_37_index]))));
          VCAST_TI_9_37_value_printed = 1;
          vCAST_DATA_FIELD = VCAST_TI_9_37_local_field;
        } /* if */
        if (VCAST_TI_9_37_index >= VCAST_TI_9_37_last)
          break;
        VCAST_TI_9_37_index++;
      } /* loop */
      if ((vCAST_COMMAND == vCAST_PRINT)&&(!VCAST_TI_9_37_value_printed))
        vectorcast_fprint_string(vCAST_OUTPUT_FILE,"<<past end of array>>\n");
    } /* if */
  }
} /* end VCAST_TI_9_37 */
/* An array */
void VCAST_TI_9_50 ( unsigned long vcast_param[2] ) 
{
  {
    int VCAST_TI_9_50_array_index = 0;
    int VCAST_TI_9_50_index = 0;
    int VCAST_TI_9_50_first, VCAST_TI_9_50_last;
    int VCAST_TI_9_50_more_data; /* true if there is more data in the current command */
    int VCAST_TI_9_50_local_field = 0;
    int VCAST_TI_9_50_value_printed = 0;
    vcast_get_range_value (&VCAST_TI_9_50_first, &VCAST_TI_9_50_last, &VCAST_TI_9_50_more_data);
    VCAST_TI_9_50_local_field = vCAST_DATA_FIELD;
    if ( vCAST_SIZE && (!VCAST_TI_9_50_more_data)) { /* get the size of the array */
      vectorcast_fprint_integer (vCAST_OUTPUT_FILE,2);
      vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
      vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n");
    } else {
      int VCAST_TI_9_50_upper = 2;
      for (VCAST_TI_9_50_array_index=0; VCAST_TI_9_50_array_index< VCAST_TI_9_50_upper; VCAST_TI_9_50_array_index++){
        if ( (VCAST_TI_9_50_index >= VCAST_TI_9_50_first) && ( VCAST_TI_9_50_index <= VCAST_TI_9_50_last)){
          VCAST_TI_9_39 ( ((unsigned long *)(&(vcast_param[VCAST_TI_9_50_index]))));
          VCAST_TI_9_50_value_printed = 1;
          vCAST_DATA_FIELD = VCAST_TI_9_50_local_field;
        } /* if */
        if (VCAST_TI_9_50_index >= VCAST_TI_9_50_last)
          break;
        VCAST_TI_9_50_index++;
      } /* loop */
      if ((vCAST_COMMAND == vCAST_PRINT)&&(!VCAST_TI_9_50_value_printed))
        vectorcast_fprint_string(vCAST_OUTPUT_FILE,"<<past end of array>>\n");
    } /* if */
  }
} /* end VCAST_TI_9_50 */
/* An array */
void VCAST_TI_9_49 ( unsigned long vcast_param[10] ) 
{
  {
    int VCAST_TI_9_49_array_index = 0;
    int VCAST_TI_9_49_index = 0;
    int VCAST_TI_9_49_first, VCAST_TI_9_49_last;
    int VCAST_TI_9_49_more_data; /* true if there is more data in the current command */
    int VCAST_TI_9_49_local_field = 0;
    int VCAST_TI_9_49_value_printed = 0;
    vcast_get_range_value (&VCAST_TI_9_49_first, &VCAST_TI_9_49_last, &VCAST_TI_9_49_more_data);
    VCAST_TI_9_49_local_field = vCAST_DATA_FIELD;
    if ( vCAST_SIZE && (!VCAST_TI_9_49_more_data)) { /* get the size of the array */
      vectorcast_fprint_integer (vCAST_OUTPUT_FILE,10);
      vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
      vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n");
    } else {
      int VCAST_TI_9_49_upper = 10;
      for (VCAST_TI_9_49_array_index=0; VCAST_TI_9_49_array_index< VCAST_TI_9_49_upper; VCAST_TI_9_49_array_index++){
        if ( (VCAST_TI_9_49_index >= VCAST_TI_9_49_first) && ( VCAST_TI_9_49_index <= VCAST_TI_9_49_last)){
          VCAST_TI_9_39 ( ((unsigned long *)(&(vcast_param[VCAST_TI_9_49_index]))));
          VCAST_TI_9_49_value_printed = 1;
          vCAST_DATA_FIELD = VCAST_TI_9_49_local_field;
        } /* if */
        if (VCAST_TI_9_49_index >= VCAST_TI_9_49_last)
          break;
        VCAST_TI_9_49_index++;
      } /* loop */
      if ((vCAST_COMMAND == vCAST_PRINT)&&(!VCAST_TI_9_49_value_printed))
        vectorcast_fprint_string(vCAST_OUTPUT_FILE,"<<past end of array>>\n");
    } /* if */
  }
} /* end VCAST_TI_9_49 */
/* An integer */
void VCAST_TI_9_39 ( unsigned long *vcast_param ) 
{
  switch (vCAST_COMMAND) {
    case vCAST_PRINT :
      if ( vcast_param == 0)
        vectorcast_fprint_string (vCAST_OUTPUT_FILE,"null\n");
      else {
        vectorcast_fprint_unsigned_long(vCAST_OUTPUT_FILE, *vcast_param);
        vectorcast_fprint_string(vCAST_OUTPUT_FILE, "\n");
      }
      break;
    case vCAST_KEEP_VAL:
      break; /* KEEP doesn't do anything */
  case vCAST_SET_VAL :
    *vcast_param = ( unsigned long  ) vCAST_VALUE_UNSIGNED;
    break;
  case vCAST_FIRST_VAL :
    *vcast_param = 0;
    break;
  case vCAST_MID_VAL :
    *vcast_param = (0 / 2) + (0xffffffffUL / 2);
    break;
  case vCAST_LAST_VAL :
    *vcast_param = 0xffffffffUL;
    break;
  case vCAST_MIN_MINUS_1_VAL :
    *vcast_param = 0;
    *vcast_param = *vcast_param - 1;
    break;
  case vCAST_MAX_PLUS_1_VAL :
    *vcast_param = 0xffffffffUL;
    *vcast_param = *vcast_param + 1;
    break;
  case vCAST_ZERO_VAL :
    *vcast_param = 0;
    break;
  default:
    break;
} /* end switch */
} /* end VCAST_TI_9_39 */
/* A pointer */
void VCAST_TI_9_53 ( unsigned char **vcast_param ) 
{
  {
    int VCAST_TI_9_53_index;
    if (((*vcast_param) == 0) && (vCAST_COMMAND != vCAST_ALLOCATE)){
      if ( vCAST_COMMAND == vCAST_PRINT )
        vectorcast_fprint_string(vCAST_OUTPUT_FILE,"null\n");
    } else {
      if ( (vCAST_COMMAND_IS_MIN_MAX == vCAST_true) &&( VCAST_FIND_INDEX() < 0 ) ) {
        switch ( vCAST_COMMAND ) {
          case vCAST_PRINT     :
            vectorcast_fprint_string(vCAST_OUTPUT_FILE,"0\n");
          case vCAST_FIRST_VAL :
          case vCAST_LAST_VAL  :
          case vCAST_POS_INF_VAL  :
          case vCAST_NEG_INF_VAL  :
          case vCAST_NAN_VAL  :
            break;
          default :
            vCAST_TOOL_ERROR = vCAST_true;
        }
      } else {
        if (vCAST_COMMAND == vCAST_ALLOCATE && vcast_proc_handles_command(1)) {
          int VCAST_TI_9_53_array_size = (int) vCAST_VALUE;
          if (VCAST_FIND_INDEX() == -1) {
            void **VCAST_TI_9_53_memory_ptr = (void**)vcast_param;
            *VCAST_TI_9_53_memory_ptr = (void*)VCAST_malloc(VCAST_TI_9_53_array_size*(sizeof(unsigned char )));
            memset((void*)*vcast_param, 0x0, VCAST_TI_9_53_array_size*(sizeof(unsigned char )));
            VCAST_Add_Allocated_Data(*VCAST_TI_9_53_memory_ptr);
          }
        } else if (vCAST_VALUE_NUL == vCAST_true && vcast_proc_handles_command(1)) {
          if (VCAST_FIND_INDEX() == -1)
            *vcast_param = 0;
        } else {
          if (VCAST_FIND_INDEX() == -1 )
            VCAST_TI_STRING ( (char**)vcast_param, sizeof ( vcast_param ), 0,-1);
          else {
            VCAST_TI_9_53_index = vcast_get_param();
            VCAST_TI_9_6 ( ((unsigned char *)(&((*vcast_param)[VCAST_TI_9_53_index]))));
          }
        }
      }
    }
  }
} /* end VCAST_TI_9_53 */
/* An array */
void VCAST_TI_9_68 ( unsigned char vcast_param[(93 + 4) + 10] ) 
{
  {
    int VCAST_TI_9_68_array_index = 0;
    int VCAST_TI_9_68_index = 0;
    int VCAST_TI_9_68_first, VCAST_TI_9_68_last;
    int VCAST_TI_9_68_more_data; /* true if there is more data in the current command */
    int VCAST_TI_9_68_local_field = 0;
    int VCAST_TI_9_68_value_printed = 0;
    int VCAST_TI_9_68_is_string = (VCAST_FIND_INDEX()==-1);
    vcast_get_range_value (&VCAST_TI_9_68_first, &VCAST_TI_9_68_last, &VCAST_TI_9_68_more_data);
    VCAST_TI_9_68_local_field = vCAST_DATA_FIELD;
    if ( vCAST_SIZE && (!VCAST_TI_9_68_more_data)) { /* get the size of the array */
      vectorcast_fprint_integer (vCAST_OUTPUT_FILE,(93 + 4) + 10);
      vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
      vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n");
    } else {
      int VCAST_TI_9_68_upper = (93 + 4) + 10;
      for (VCAST_TI_9_68_array_index=0; VCAST_TI_9_68_array_index< VCAST_TI_9_68_upper; VCAST_TI_9_68_array_index++){
        if ( (VCAST_TI_9_68_index >= VCAST_TI_9_68_first) && ( VCAST_TI_9_68_index <= VCAST_TI_9_68_last)){
          if ( VCAST_TI_9_68_is_string )
            VCAST_TI_STRING ( (char**)&vcast_param, sizeof ( vcast_param ), 1,VCAST_TI_9_68_upper);
          else
            VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param[VCAST_TI_9_68_index]))));
          VCAST_TI_9_68_value_printed = 1;
          vCAST_DATA_FIELD = VCAST_TI_9_68_local_field;
        } /* if */
        if (VCAST_TI_9_68_index >= VCAST_TI_9_68_last)
          break;
        VCAST_TI_9_68_index++;
      } /* loop */
      if ((vCAST_COMMAND == vCAST_PRINT)&&(!VCAST_TI_9_68_value_printed))
        vectorcast_fprint_string(vCAST_OUTPUT_FILE,"<<past end of array>>\n");
    } /* if */
  }
} /* end VCAST_TI_9_68 */
/* A typedef */
void VCAST_TI_9_27 ( s_rb_EEPROMStruct_PD_g *vcast_param ) 
{
  {
    switch ( vcast_get_param () ) { /* Choose field member */
      /* Setting member variable vcast_param->ProductionData_g */
      case 1: { 
        VCAST_TI_9_63 ( ((unsigned char *)(vcast_param->ProductionData_g)));
        break; /* end case 1*/
      } /* end case */
      /* Setting member variable vcast_param->EEKodierbyte2_g */
      case 2: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->EEKodierbyte2_g))));
        break; /* end case 2*/
      } /* end case */
      /* Setting member variable vcast_param->EEKodierbyte1_g */
      case 3: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->EEKodierbyte1_g))));
        break; /* end case 3*/
      } /* end case */
      /* Setting member variable vcast_param->EEKodierbyte0_g */
      case 4: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->EEKodierbyte0_g))));
        break; /* end case 4*/
      } /* end case */
      /* Setting member variable vcast_param->ALS1_4_Setting_g */
      case 5: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->ALS1_4_Setting_g))));
        break; /* end case 5*/
      } /* end case */
      /* Setting member variable vcast_param->ALS5_6_INREC_Setting_g */
      case 6: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->ALS5_6_INREC_Setting_g))));
        break; /* end case 6*/
      } /* end case */
      /* Setting member variable vcast_param->ASIC_DIAGV_g */
      case 7: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->ASIC_DIAGV_g))));
        break; /* end case 7*/
      } /* end case */
      /* Setting member variable vcast_param->A_Factor_ALS1_g */
      case 8: { 
        VCAST_TI_9_22 ( ((unsigned *)(&(vcast_param->A_Factor_ALS1_g))));
        break; /* end case 8*/
      } /* end case */
      /* Setting member variable vcast_param->A_Factor_ALS2_g */
      case 9: { 
        VCAST_TI_9_22 ( ((unsigned *)(&(vcast_param->A_Factor_ALS2_g))));
        break; /* end case 9*/
      } /* end case */
      /* Setting member variable vcast_param->A_Factor_ALS3_g */
      case 10: { 
        VCAST_TI_9_22 ( ((unsigned *)(&(vcast_param->A_Factor_ALS3_g))));
        break; /* end case 10*/
      } /* end case */
      /* Setting member variable vcast_param->A_Factor_ALS4_g */
      case 11: { 
        VCAST_TI_9_22 ( ((unsigned *)(&(vcast_param->A_Factor_ALS4_g))));
        break; /* end case 11*/
      } /* end case */
      /* Setting member variable vcast_param->A_Factor_ALS5_g */
      case 12: { 
        VCAST_TI_9_22 ( ((unsigned *)(&(vcast_param->A_Factor_ALS5_g))));
        break; /* end case 12*/
      } /* end case */
      /* Setting member variable vcast_param->A_Factor_ALS6_g */
      case 13: { 
        VCAST_TI_9_22 ( ((unsigned *)(&(vcast_param->A_Factor_ALS6_g))));
        break; /* end case 13*/
      } /* end case */
      /* Setting member variable vcast_param->A_Factor_INREC_g */
      case 14: { 
        VCAST_TI_9_22 ( ((unsigned *)(&(vcast_param->A_Factor_INREC_g))));
        break; /* end case 14*/
      } /* end case */
      /* Setting member variable vcast_param->B_Factor_Iref_Lo_Gain_Lo_g */
      case 15: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->B_Factor_Iref_Lo_Gain_Lo_g))));
        break; /* end case 15*/
      } /* end case */
      /* Setting member variable vcast_param->B_Factor_Iref_Lo_Gain_Hi_g */
      case 16: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->B_Factor_Iref_Lo_Gain_Hi_g))));
        break; /* end case 16*/
      } /* end case */
      /* Setting member variable vcast_param->B_Factor_Iref_Hi_Gain_Lo_g */
      case 17: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->B_Factor_Iref_Hi_Gain_Lo_g))));
        break; /* end case 17*/
      } /* end case */
      /* Setting member variable vcast_param->B_Factor_Iref_Hi_Gain_Hi_g */
      case 18: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->B_Factor_Iref_Hi_Gain_Hi_g))));
        break; /* end case 18*/
      } /* end case */
      /* Setting member variable vcast_param->CRC_Checksum_calibration_g */
      case 19: { 
        VCAST_TI_9_22 ( ((unsigned *)(&(vcast_param->CRC_Checksum_calibration_g))));
        break; /* end case 19*/
      } /* end case */
      /* Setting member variable vcast_param->Standby_rain_measurement_1_g */
      case 20: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->Standby_rain_measurement_1_g))));
        break; /* end case 20*/
      } /* end case */
      /* Setting member variable vcast_param->Standby_rain_measurement_2_g */
      case 21: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->Standby_rain_measurement_2_g))));
        break; /* end case 21*/
      } /* end case */
      /* Setting member variable vcast_param->Standby_rain_measurement_3_g */
      case 22: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->Standby_rain_measurement_3_g))));
        break; /* end case 22*/
      } /* end case */
      /* Setting member variable vcast_param->Standby_rain_measurement_4_g */
      case 23: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->Standby_rain_measurement_4_g))));
        break; /* end case 23*/
      } /* end case */
      /* Setting member variable vcast_param->Standby_rain_measurement_5_g */
      case 24: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->Standby_rain_measurement_5_g))));
        break; /* end case 24*/
      } /* end case */
      /* Setting member variable vcast_param->Standby_rain_measurement_6_g */
      case 25: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->Standby_rain_measurement_6_g))));
        break; /* end case 25*/
      } /* end case */
      /* Setting member variable vcast_param->ASIC_Sched_Config_g */
      case 26: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->ASIC_Sched_Config_g))));
        break; /* end case 26*/
      } /* end case */
      /* Setting member variable vcast_param->ASIC_LCTR_g */
      case 27: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->ASIC_LCTR_g))));
        break; /* end case 27*/
      } /* end case */
      /* Setting member variable vcast_param->NO_RAIN_PRESENT_THRSH_HB_g */
      case 28: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->NO_RAIN_PRESENT_THRSH_HB_g))));
        break; /* end case 28*/
      } /* end case */
      /* Setting member variable vcast_param->NO_RAIN_PRESENT_THRSH_LB_g */
      case 29: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->NO_RAIN_PRESENT_THRSH_LB_g))));
        break; /* end case 29*/
      } /* end case */
      /* Setting member variable vcast_param->STBY_REGV_Imbalance_g */
      case 30: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->STBY_REGV_Imbalance_g))));
        break; /* end case 30*/
      } /* end case */
      /* Setting member variable vcast_param->RSControlFlags */
      case 31: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->RSControlFlags))));
        break; /* end case 31*/
      } /* end case */
      /* Setting member variable vcast_param->EEPROM_Erase_Counter */
      case 32: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->EEPROM_Erase_Counter))));
        break; /* end case 32*/
      } /* end case */
      /* Setting member variable vcast_param->HardwareStand */
      case 33: { 
        VCAST_TI_9_64 ( ((unsigned char *)(vcast_param->HardwareStand)));
        break; /* end case 33*/
      } /* end case */
      /* Setting member variable vcast_param->Produktionsdaten */
      case 34: { 
        VCAST_TI_9_41 ( ((unsigned char *)(vcast_param->Produktionsdaten)));
        break; /* end case 34*/
      } /* end case */
      /* Setting member variable vcast_param->Fertigungsdatum */
      case 35: { 
        VCAST_TI_9_65 ( ((unsigned char *)(vcast_param->Fertigungsdatum)));
        break; /* end case 35*/
      } /* end case */
      /* Setting member variable vcast_param->Audi_HW_Partnumber */
      case 36: { 
        VCAST_TI_9_43 ( ((unsigned char *)(vcast_param->Audi_HW_Partnumber)));
        break; /* end case 36*/
      } /* end case */
      /* Setting member variable vcast_param->NAD */
      case 37: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->NAD))));
        break; /* end case 37*/
      } /* end case */
      /* Setting member variable vcast_param->IDFSs_01 */
      case 38: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->IDFSs_01))));
        break; /* end case 38*/
      } /* end case */
      /* Setting member variable vcast_param->IDRLSs_01 */
      case 39: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->IDRLSs_01))));
        break; /* end case 39*/
      } /* end case */
      /* Setting member variable vcast_param->IDBCM1_LIN1_01 */
      case 40: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->IDBCM1_LIN1_01))));
        break; /* end case 40*/
      } /* end case */
      /* Setting member variable vcast_param->IDWWSs_01 */
      case 41: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->IDWWSs_01))));
        break; /* end case 41*/
      } /* end case */
      /* Setting member variable vcast_param->IDSOSES_01 */
      case 42: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->IDSOSES_01))));
        break; /* end case 42*/
      } /* end case */
      /* Setting member variable vcast_param->ASIC_Frame_01_g */
      case 43: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->ASIC_Frame_01_g))));
        break; /* end case 43*/
      } /* end case */
      /* Setting member variable vcast_param->ASIC_Frame_02_g */
      case 44: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->ASIC_Frame_02_g))));
        break; /* end case 44*/
      } /* end case */
      /* Setting member variable vcast_param->ASIC_Frame_03_g */
      case 45: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->ASIC_Frame_03_g))));
        break; /* end case 45*/
      } /* end case */
      /* Setting member variable vcast_param->ASIC_Frame_04_g */
      case 46: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->ASIC_Frame_04_g))));
        break; /* end case 46*/
      } /* end case */
      /* Setting member variable vcast_param->ASIC_RCTR_REG_g */
      case 47: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->ASIC_RCTR_REG_g))));
        break; /* end case 47*/
      } /* end case */
      /* Setting member variable vcast_param->ASIC_RFCTR_REG_g */
      case 48: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->ASIC_RFCTR_REG_g))));
        break; /* end case 48*/
      } /* end case */
      /* Setting member variable vcast_param->Error_Active_1_g */
      case 49: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->Error_Active_1_g))));
        break; /* end case 49*/
      } /* end case */
      /* Setting member variable vcast_param->Error_Active_2_g */
      case 50: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->Error_Active_2_g))));
        break; /* end case 50*/
      } /* end case */
      /* Setting member variable vcast_param->Error_Active_3_g */
      case 51: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->Error_Active_3_g))));
        break; /* end case 51*/
      } /* end case */
      /* Setting member variable vcast_param->Erase_counter */
      case 52: { 
        VCAST_TI_9_41 ( ((unsigned char *)(vcast_param->Erase_counter)));
        break; /* end case 52*/
      } /* end case */
      /* Setting member variable vcast_param->VariantID_g */
      case 53: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->VariantID_g))));
        break; /* end case 53*/
      } /* end case */
      /* Setting member variable vcast_param->FunctionID_g */
      case 54: { 
        VCAST_TI_9_22 ( ((unsigned *)(&(vcast_param->FunctionID_g))));
        break; /* end case 54*/
      } /* end case */
      /* Setting member variable vcast_param->IDERRDATA_01 */
      case 55: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->IDERRDATA_01))));
        break; /* end case 55*/
      } /* end case */
      /* Setting member variable vcast_param->IDSPARE_01 */
      case 56: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->IDSPARE_01))));
        break; /* end case 56*/
      } /* end case */
      /* Setting member variable vcast_param->IDRLSs_02 */
      case 57: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->IDRLSs_02))));
        break; /* end case 57*/
      } /* end case */
      /* Setting member variable vcast_param->IDBCM1_LIN1_02 */
      case 58: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->IDBCM1_LIN1_02))));
        break; /* end case 58*/
      } /* end case */
      /* Setting member variable vcast_param->HUD_Factor_g */
      case 59: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->HUD_Factor_g))));
        break; /* end case 59*/
      } /* end case */
      /* Setting member variable vcast_param->IDRLSs_03 */
      case 60: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->IDRLSs_03))));
        break; /* end case 60*/
      } /* end case */
      /* Setting member variable vcast_param->IDRLSs_04 */
      case 61: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->IDRLSs_04))));
        break; /* end case 61*/
      } /* end case */
      /* Setting member variable vcast_param->IDRLSs_05 */
      case 62: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->IDRLSs_05))));
        break; /* end case 62*/
      } /* end case */
      /* Setting member variable vcast_param->IDRLSs_06 */
      case 63: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->IDRLSs_06))));
        break; /* end case 63*/
      } /* end case */
      /* Setting member variable vcast_param->IDBCM1_LIN1_03 */
      case 64: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->IDBCM1_LIN1_03))));
        break; /* end case 64*/
      } /* end case */
      /* Setting member variable vcast_param->IDBCM1_LIN1_04 */
      case 65: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->IDBCM1_LIN1_04))));
        break; /* end case 65*/
      } /* end case */
      /* Setting member variable vcast_param->IDBCM1_LIN1_05 */
      case 66: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->IDBCM1_LIN1_05))));
        break; /* end case 66*/
      } /* end case */
      /* Setting member variable vcast_param->HUD_MAX_Value */
      case 67: { 
        VCAST_TI_9_22 ( ((unsigned *)(&(vcast_param->HUD_MAX_Value))));
        break; /* end case 67*/
      } /* end case */
      /* Setting member variable vcast_param->HUD_MAX_Resolution */
      case 68: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->HUD_MAX_Resolution))));
        break; /* end case 68*/
      } /* end case */
      default:
        vCAST_TOOL_ERROR = vCAST_true;
    } /* end switch */ 
  }
} /* end VCAST_TI_9_27 */
/* An array */
void VCAST_TI_9_79 ( unsigned char vcast_param[194] ) 
{
  {
    int VCAST_TI_9_79_array_index = 0;
    int VCAST_TI_9_79_index = 0;
    int VCAST_TI_9_79_first, VCAST_TI_9_79_last;
    int VCAST_TI_9_79_more_data; /* true if there is more data in the current command */
    int VCAST_TI_9_79_local_field = 0;
    int VCAST_TI_9_79_value_printed = 0;
    int VCAST_TI_9_79_is_string = (VCAST_FIND_INDEX()==-1);
    vcast_get_range_value (&VCAST_TI_9_79_first, &VCAST_TI_9_79_last, &VCAST_TI_9_79_more_data);
    VCAST_TI_9_79_local_field = vCAST_DATA_FIELD;
    if ( vCAST_SIZE && (!VCAST_TI_9_79_more_data)) { /* get the size of the array */
      vectorcast_fprint_integer (vCAST_OUTPUT_FILE,194);
      vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
      vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n");
    } else {
      int VCAST_TI_9_79_upper = 194;
      for (VCAST_TI_9_79_array_index=0; VCAST_TI_9_79_array_index< VCAST_TI_9_79_upper; VCAST_TI_9_79_array_index++){
        if ( (VCAST_TI_9_79_index >= VCAST_TI_9_79_first) && ( VCAST_TI_9_79_index <= VCAST_TI_9_79_last)){
          if ( VCAST_TI_9_79_is_string )
            VCAST_TI_STRING ( (char**)&vcast_param, sizeof ( vcast_param ), 1,VCAST_TI_9_79_upper);
          else
            VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param[VCAST_TI_9_79_index]))));
          VCAST_TI_9_79_value_printed = 1;
          vCAST_DATA_FIELD = VCAST_TI_9_79_local_field;
        } /* if */
        if (VCAST_TI_9_79_index >= VCAST_TI_9_79_last)
          break;
        VCAST_TI_9_79_index++;
      } /* loop */
      if ((vCAST_COMMAND == vCAST_PRINT)&&(!VCAST_TI_9_79_value_printed))
        vectorcast_fprint_string(vCAST_OUTPUT_FILE,"<<past end of array>>\n");
    } /* if */
  }
} /* end VCAST_TI_9_79 */
/* A typedef */
void VCAST_TI_9_29 ( s_rb_EEPROMStruct_AD_g *vcast_param ) 
{
  {
    switch ( vcast_get_param () ) { /* Choose field member */
      /* Setting member variable vcast_param->PrametersStruct */
      case 1: { 
        VCAST_TI_9_72 ( ((s_rb_PrametersStruct_g *)(vcast_param->PrametersStruct)));
        break; /* end case 1*/
      } /* end case */
      /* Setting member variable vcast_param->RS_GainSetupArray */
      case 2: { 
        VCAST_TI_9_111 ( ((unsigned char *)(vcast_param->RS_GainSetupArray)));
        break; /* end case 2*/
      } /* end case */
      /* Setting member variable vcast_param->HALIOS_Clock_Control_Reg_g */
      case 3: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->HALIOS_Clock_Control_Reg_g))));
        break; /* end case 3*/
      } /* end case */
      /* Setting member variable vcast_param->ACTR_Reg_g */
      case 4: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->ACTR_Reg_g))));
        break; /* end case 4*/
      } /* end case */
      /* Setting member variable vcast_param->PCO_PI_Regulator_g */
      case 5: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->PCO_PI_Regulator_g))));
        break; /* end case 5*/
      } /* end case */
      /* Setting member variable vcast_param->ICO1H_g */
      case 6: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->ICO1H_g))));
        break; /* end case 6*/
      } /* end case */
      /* Setting member variable vcast_param->ICO1L_g */
      case 7: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->ICO1L_g))));
        break; /* end case 7*/
      } /* end case */
      /* Setting member variable vcast_param->ICO2H_g */
      case 8: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->ICO2H_g))));
        break; /* end case 8*/
      } /* end case */
      /* Setting member variable vcast_param->ICO2L_g */
      case 9: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->ICO2L_g))));
        break; /* end case 9*/
      } /* end case */
      /* Setting member variable vcast_param->FOSC_LEDUL_g */
      case 10: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->FOSC_LEDUL_g))));
        break; /* end case 10*/
      } /* end case */
      /* Setting member variable vcast_param->INTCO_g */
      case 11: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->INTCO_g))));
        break; /* end case 11*/
      } /* end case */
      /* Setting member variable vcast_param->StandbyTimout */
      case 12: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->StandbyTimout))));
        break; /* end case 12*/
      } /* end case */
      /* Setting member variable vcast_param->dec_st2_speicher */
      case 13: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->dec_st2_speicher))));
        break; /* end case 13*/
      } /* end case */
      /* Setting member variable vcast_param->RS_Sensitivity */
      case 14: { 
        VCAST_TI_9_74 ( ((unsigned char *)(vcast_param->RS_Sensitivity)));
        break; /* end case 14*/
      } /* end case */
      /* Setting member variable vcast_param->MaxOverwipeSensitivity */
      case 15: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->MaxOverwipeSensitivity))));
        break; /* end case 15*/
      } /* end case */
      /* Setting member variable vcast_param->StandbyModeScanTime_g */
      case 16: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->StandbyModeScanTime_g))));
        break; /* end case 16*/
      } /* end case */
      /* Setting member variable vcast_param->RainNightBitThrs_g */
      case 17: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->RainNightBitThrs_g))));
        break; /* end case 17*/
      } /* end case */
      /* Setting member variable vcast_param->Amb_Base_Day_Threshold */
      case 18: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->Amb_Base_Day_Threshold))));
        break; /* end case 18*/
      } /* end case */
      /* Setting member variable vcast_param->Amb_Base_Night_Threshold */
      case 19: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->Amb_Base_Night_Threshold))));
        break; /* end case 19*/
      } /* end case */
      /* Setting member variable vcast_param->TunnelDebounceFactor */
      case 20: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->TunnelDebounceFactor))));
        break; /* end case 20*/
      } /* end case */
      /* Setting member variable vcast_param->Customer_FW_SWA_Scaling */
      case 21: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->Customer_FW_SWA_Scaling))));
        break; /* end case 21*/
      } /* end case */
      /* Setting member variable vcast_param->Customer_IR_SWA_Scaling */
      case 22: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->Customer_IR_SWA_Scaling))));
        break; /* end case 22*/
      } /* end case */
      /* Setting member variable vcast_param->FW_Base_Day_Threshold */
      case 23: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->FW_Base_Day_Threshold))));
        break; /* end case 23*/
      } /* end case */
      /* Setting member variable vcast_param->IR_Base_Day_Threshold */
      case 24: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->IR_Base_Day_Threshold))));
        break; /* end case 24*/
      } /* end case */
      /* Setting member variable vcast_param->FW_Base_Night_Threshold */
      case 25: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->FW_Base_Night_Threshold))));
        break; /* end case 25*/
      } /* end case */
      /* Setting member variable vcast_param->IR_Base_Night_Threshold */
      case 26: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->IR_Base_Night_Threshold))));
        break; /* end case 26*/
      } /* end case */
      /* Setting member variable vcast_param->Day_Delay */
      case 27: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->Day_Delay))));
        break; /* end case 27*/
      } /* end case */
      /* Setting member variable vcast_param->Night_Delay */
      case 28: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->Night_Delay))));
        break; /* end case 28*/
      } /* end case */
      /* Setting member variable vcast_param->AfterTunnelDelayOffs */
      case 29: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->AfterTunnelDelayOffs))));
        break; /* end case 29*/
      } /* end case */
      /* Setting member variable vcast_param->p_v_autobahn_on_off_g */
      case 30: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->p_v_autobahn_on_off_g))));
        break; /* end case 30*/
      } /* end case */
      /* Setting member variable vcast_param->p_t_autobahn_delay_on_g */
      case 31: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->p_t_autobahn_delay_on_g))));
        break; /* end case 31*/
      } /* end case */
      /* Setting member variable vcast_param->Frontwaschen_Autobahndelay_g */
      case 32: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->Frontwaschen_Autobahndelay_g))));
        break; /* end case 32*/
      } /* end case */
      /* Setting member variable vcast_param->p_n_regenlichtschwelle_low_high_g */
      case 33: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->p_n_regenlichtschwelle_low_high_g))));
        break; /* end case 33*/
      } /* end case */
      /* Setting member variable vcast_param->p_n_regenlichtschwelle_Zeit_g */
      case 34: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->p_n_regenlichtschwelle_Zeit_g))));
        break; /* end case 34*/
      } /* end case */
      /* Setting member variable vcast_param->TunnelThresholdScaling_g */
      case 35: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->TunnelThresholdScaling_g))));
        break; /* end case 35*/
      } /* end case */
      /* Setting member variable vcast_param->Amb_TunnelThresholdScaling_g */
      case 36: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->Amb_TunnelThresholdScaling_g))));
        break; /* end case 36*/
      } /* end case */
      /* Setting member variable vcast_param->spare */
      case 37: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->spare))));
        break; /* end case 37*/
      } /* end case */
      /* Setting member variable vcast_param->Regulation48LightOnTime_g */
      case 38: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->Regulation48LightOnTime_g))));
        break; /* end case 38*/
      } /* end case */
      /* Setting member variable vcast_param->VeryBrightInTunnelDelay_g */
      case 39: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->VeryBrightInTunnelDelay_g))));
        break; /* end case 39*/
      } /* end case */
      /* Setting member variable vcast_param->Combined_FW_AL_THRs_g */
      case 40: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->Combined_FW_AL_THRs_g))));
        break; /* end case 40*/
      } /* end case */
      /* Setting member variable vcast_param->DYN_COMP_CCD_MINUS_1_g */
      case 41: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->DYN_COMP_CCD_MINUS_1_g))));
        break; /* end case 41*/
      } /* end case */
      /* Setting member variable vcast_param->DYN_COMP_CCD_MINUS_2_g */
      case 42: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->DYN_COMP_CCD_MINUS_2_g))));
        break; /* end case 42*/
      } /* end case */
      /* Setting member variable vcast_param->maxTemperatureOffsett_g */
      case 43: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->maxTemperatureOffsett_g))));
        break; /* end case 43*/
      } /* end case */
      /* Setting member variable vcast_param->ASIC_AFSTHR_REG_g */
      case 44: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->ASIC_AFSTHR_REG_g))));
        break; /* end case 44*/
      } /* end case */
      /* Setting member variable vcast_param->Diag_Request_Factor_g */
      case 45: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->Diag_Request_Factor_g))));
        break; /* end case 45*/
      } /* end case */
      /* Setting member variable vcast_param->cb_inc_speicher_g */
      case 46: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->cb_inc_speicher_g))));
        break; /* end case 46*/
      } /* end case */
      /* Setting member variable vcast_param->I2C_Debug_Config_g */
      case 47: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->I2C_Debug_Config_g))));
        break; /* end case 47*/
      } /* end case */
      /* Setting member variable vcast_param->Audi_SW_Partnumber */
      case 48: { 
        VCAST_TI_9_43 ( ((unsigned char *)(vcast_param->Audi_SW_Partnumber)));
        break; /* end case 48*/
      } /* end case */
      /* Setting member variable vcast_param->wiperSpeedHysteresis */
      case 49: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->wiperSpeedHysteresis))));
        break; /* end case 49*/
      } /* end case */
      /* Setting member variable vcast_param->Proj_Specific_config */
      case 50: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->Proj_Specific_config))));
        break; /* end case 50*/
      } /* end case */
      /* Setting member variable vcast_param->ALSx_Filter_g */
      case 51: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->ALSx_Filter_g))));
        break; /* end case 51*/
      } /* end case */
      /* Setting member variable vcast_param->IrLightTunnelThreshodRng */
      case 52: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->IrLightTunnelThreshodRng))));
        break; /* end case 52*/
      } /* end case */
      /* Setting member variable vcast_param->FwLightTunnelThresholdRng */
      case 53: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->FwLightTunnelThresholdRng))));
        break; /* end case 53*/
      } /* end case */
      /* Setting member variable vcast_param->AmbLightTunnelThresholdRng */
      case 54: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->AmbLightTunnelThresholdRng))));
        break; /* end case 54*/
      } /* end case */
      /* Setting member variable vcast_param->TunWischVerzAktiv */
      case 55: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->TunWischVerzAktiv))));
        break; /* end case 55*/
      } /* end case */
      /* Setting member variable vcast_param->SHTErrorDebounceJitter */
      case 56: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->SHTErrorDebounceJitter))));
        break; /* end case 56*/
      } /* end case */
      /* Setting member variable vcast_param->SolarShadowCorrFactor1 */
      case 57: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->SolarShadowCorrFactor1))));
        break; /* end case 57*/
      } /* end case */
      /* Setting member variable vcast_param->SolarShadowCorrFactor2 */
      case 58: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->SolarShadowCorrFactor2))));
        break; /* end case 58*/
      } /* end case */
      /* Setting member variable vcast_param->E2_MaxSt2SignalLaenge */
      case 59: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->E2_MaxSt2SignalLaenge))));
        break; /* end case 59*/
      } /* end case */
      /* Setting member variable vcast_param->SoftwareStand */
      case 60: { 
        VCAST_TI_9_41 ( ((unsigned char *)(vcast_param->SoftwareStand)));
        break; /* end case 60*/
      } /* end case */
      /* Setting member variable vcast_param->twilightToDarkTime */
      case 61: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->twilightToDarkTime))));
        break; /* end case 61*/
      } /* end case */
      /* Setting member variable vcast_param->darkToTwilightTime */
      case 62: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->darkToTwilightTime))));
        break; /* end case 62*/
      } /* end case */
      /* Setting member variable vcast_param->darkToTwilightThreshFW */
      case 63: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->darkToTwilightThreshFW))));
        break; /* end case 63*/
      } /* end case */
      /* Setting member variable vcast_param->darkToTwilightThreshAMB */
      case 64: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->darkToTwilightThreshAMB))));
        break; /* end case 64*/
      } /* end case */
      /* Setting member variable vcast_param->twilightToDarkThreshFW */
      case 65: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->twilightToDarkThreshFW))));
        break; /* end case 65*/
      } /* end case */
      /* Setting member variable vcast_param->twilightToDarkThreshAMB */
      case 66: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->twilightToDarkThreshAMB))));
        break; /* end case 66*/
      } /* end case */
      /* Setting member variable vcast_param->iceDetectionTemperature */
      case 67: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->iceDetectionTemperature))));
        break; /* end case 67*/
      } /* end case */
      /* Setting member variable vcast_param->Regulation48ThresholdAmb_g */
      case 68: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->Regulation48ThresholdAmb_g))));
        break; /* end case 68*/
      } /* end case */
      /* Setting member variable vcast_param->Regulation48ThresholdFw_g */
      case 69: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->Regulation48ThresholdFw_g))));
        break; /* end case 69*/
      } /* end case */
      /* Setting member variable vcast_param->Threshold_TempIceRisk */
      case 70: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->Threshold_TempIceRisk))));
        break; /* end case 70*/
      } /* end case */
      /* Setting member variable vcast_param->upperTolerance_StartupWipe */
      case 71: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->upperTolerance_StartupWipe))));
        break; /* end case 71*/
      } /* end case */
      /* Setting member variable vcast_param->unused */
      case 72: { 
        VCAST_TI_9_77 ( ((unsigned char *)(vcast_param->unused)));
        break; /* end case 72*/
      } /* end case */
      default:
        vCAST_TOOL_ERROR = vCAST_true;
    } /* end switch */ 
  }
} /* end VCAST_TI_9_29 */
/* An array */
void VCAST_TI_9_80 ( unsigned char vcast_param[1] ) 
{
  {
    int VCAST_TI_9_80_array_index = 0;
    int VCAST_TI_9_80_index = 0;
    int VCAST_TI_9_80_first, VCAST_TI_9_80_last;
    int VCAST_TI_9_80_more_data; /* true if there is more data in the current command */
    int VCAST_TI_9_80_local_field = 0;
    int VCAST_TI_9_80_value_printed = 0;
    int VCAST_TI_9_80_is_string = (VCAST_FIND_INDEX()==-1);
    vcast_get_range_value (&VCAST_TI_9_80_first, &VCAST_TI_9_80_last, &VCAST_TI_9_80_more_data);
    VCAST_TI_9_80_local_field = vCAST_DATA_FIELD;
    if ( vCAST_SIZE && (!VCAST_TI_9_80_more_data)) { /* get the size of the array */
      vectorcast_fprint_integer (vCAST_OUTPUT_FILE,1);
      vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
      vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n");
    } else {
      int VCAST_TI_9_80_upper = 1;
      for (VCAST_TI_9_80_array_index=0; VCAST_TI_9_80_array_index< VCAST_TI_9_80_upper; VCAST_TI_9_80_array_index++){
        if ( (VCAST_TI_9_80_index >= VCAST_TI_9_80_first) && ( VCAST_TI_9_80_index <= VCAST_TI_9_80_last)){
          if ( VCAST_TI_9_80_is_string )
            VCAST_TI_STRING ( (char**)&vcast_param, sizeof ( vcast_param ), 1,VCAST_TI_9_80_upper);
          else
            VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param[VCAST_TI_9_80_index]))));
          VCAST_TI_9_80_value_printed = 1;
          vCAST_DATA_FIELD = VCAST_TI_9_80_local_field;
        } /* if */
        if (VCAST_TI_9_80_index >= VCAST_TI_9_80_last)
          break;
        VCAST_TI_9_80_index++;
      } /* loop */
      if ((vCAST_COMMAND == vCAST_PRINT)&&(!VCAST_TI_9_80_value_printed))
        vectorcast_fprint_string(vCAST_OUTPUT_FILE,"<<past end of array>>\n");
    } /* if */
  }
} /* end VCAST_TI_9_80 */
/* An array */
void VCAST_TI_9_8 ( struct _c_bits8 vcast_param[1] ) 
{
  {
    int VCAST_TI_9_8_array_index = 0;
    int VCAST_TI_9_8_index = 0;
    int VCAST_TI_9_8_first, VCAST_TI_9_8_last;
    int VCAST_TI_9_8_more_data; /* true if there is more data in the current command */
    int VCAST_TI_9_8_local_field = 0;
    int VCAST_TI_9_8_value_printed = 0;
    vcast_get_range_value (&VCAST_TI_9_8_first, &VCAST_TI_9_8_last, &VCAST_TI_9_8_more_data);
    VCAST_TI_9_8_local_field = vCAST_DATA_FIELD;
    if ( vCAST_SIZE && (!VCAST_TI_9_8_more_data)) { /* get the size of the array */
      vectorcast_fprint_integer (vCAST_OUTPUT_FILE,1);
      vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
      vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n");
    } else {
      int VCAST_TI_9_8_upper = 1;
      for (VCAST_TI_9_8_array_index=0; VCAST_TI_9_8_array_index< VCAST_TI_9_8_upper; VCAST_TI_9_8_array_index++){
        if ( (VCAST_TI_9_8_index >= VCAST_TI_9_8_first) && ( VCAST_TI_9_8_index <= VCAST_TI_9_8_last)){
          VCAST_TI_9_9 ( ((struct _c_bits8 *)(&(vcast_param[VCAST_TI_9_8_index]))));
          VCAST_TI_9_8_value_printed = 1;
          vCAST_DATA_FIELD = VCAST_TI_9_8_local_field;
        } /* if */
        if (VCAST_TI_9_8_index >= VCAST_TI_9_8_last)
          break;
        VCAST_TI_9_8_index++;
      } /* loop */
      if ((vCAST_COMMAND == vCAST_PRINT)&&(!VCAST_TI_9_8_value_printed))
        vectorcast_fprint_string(vCAST_OUTPUT_FILE,"<<past end of array>>\n");
    } /* if */
  }
} /* end VCAST_TI_9_8 */
/* An array */
void VCAST_TI_9_81 ( unsigned char vcast_param[(11 + 7) / 8] ) 
{
  {
    int VCAST_TI_9_81_array_index = 0;
    int VCAST_TI_9_81_index = 0;
    int VCAST_TI_9_81_first, VCAST_TI_9_81_last;
    int VCAST_TI_9_81_more_data; /* true if there is more data in the current command */
    int VCAST_TI_9_81_local_field = 0;
    int VCAST_TI_9_81_value_printed = 0;
    int VCAST_TI_9_81_is_string = (VCAST_FIND_INDEX()==-1);
    vcast_get_range_value (&VCAST_TI_9_81_first, &VCAST_TI_9_81_last, &VCAST_TI_9_81_more_data);
    VCAST_TI_9_81_local_field = vCAST_DATA_FIELD;
    if ( vCAST_SIZE && (!VCAST_TI_9_81_more_data)) { /* get the size of the array */
      vectorcast_fprint_integer (vCAST_OUTPUT_FILE,(11 + 7) / 8);
      vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
      vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n");
    } else {
      int VCAST_TI_9_81_upper = (11 + 7) / 8;
      for (VCAST_TI_9_81_array_index=0; VCAST_TI_9_81_array_index< VCAST_TI_9_81_upper; VCAST_TI_9_81_array_index++){
        if ( (VCAST_TI_9_81_index >= VCAST_TI_9_81_first) && ( VCAST_TI_9_81_index <= VCAST_TI_9_81_last)){
          if ( VCAST_TI_9_81_is_string )
            VCAST_TI_STRING ( (char**)&vcast_param, sizeof ( vcast_param ), 1,VCAST_TI_9_81_upper);
          else
            VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param[VCAST_TI_9_81_index]))));
          VCAST_TI_9_81_value_printed = 1;
          vCAST_DATA_FIELD = VCAST_TI_9_81_local_field;
        } /* if */
        if (VCAST_TI_9_81_index >= VCAST_TI_9_81_last)
          break;
        VCAST_TI_9_81_index++;
      } /* loop */
      if ((vCAST_COMMAND == vCAST_PRINT)&&(!VCAST_TI_9_81_value_printed))
        vectorcast_fprint_string(vCAST_OUTPUT_FILE,"<<past end of array>>\n");
    } /* if */
  }
} /* end VCAST_TI_9_81 */
/* An array */
void VCAST_TI_9_31 ( struct _c_bits16 vcast_param[(11 + 15) / 16] ) 
{
  {
    int VCAST_TI_9_31_array_index = 0;
    int VCAST_TI_9_31_index = 0;
    int VCAST_TI_9_31_first, VCAST_TI_9_31_last;
    int VCAST_TI_9_31_more_data; /* true if there is more data in the current command */
    int VCAST_TI_9_31_local_field = 0;
    int VCAST_TI_9_31_value_printed = 0;
    vcast_get_range_value (&VCAST_TI_9_31_first, &VCAST_TI_9_31_last, &VCAST_TI_9_31_more_data);
    VCAST_TI_9_31_local_field = vCAST_DATA_FIELD;
    if ( vCAST_SIZE && (!VCAST_TI_9_31_more_data)) { /* get the size of the array */
      vectorcast_fprint_integer (vCAST_OUTPUT_FILE,(11 + 15) / 16);
      vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
      vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n");
    } else {
      int VCAST_TI_9_31_upper = (11 + 15) / 16;
      for (VCAST_TI_9_31_array_index=0; VCAST_TI_9_31_array_index< VCAST_TI_9_31_upper; VCAST_TI_9_31_array_index++){
        if ( (VCAST_TI_9_31_index >= VCAST_TI_9_31_first) && ( VCAST_TI_9_31_index <= VCAST_TI_9_31_last)){
          VCAST_TI_9_32 ( ((struct _c_bits16 *)(&(vcast_param[VCAST_TI_9_31_index]))));
          VCAST_TI_9_31_value_printed = 1;
          vCAST_DATA_FIELD = VCAST_TI_9_31_local_field;
        } /* if */
        if (VCAST_TI_9_31_index >= VCAST_TI_9_31_last)
          break;
        VCAST_TI_9_31_index++;
      } /* loop */
      if ((vCAST_COMMAND == vCAST_PRINT)&&(!VCAST_TI_9_31_value_printed))
        vectorcast_fprint_string(vCAST_OUTPUT_FILE,"<<past end of array>>\n");
    } /* if */
  }
} /* end VCAST_TI_9_31 */
/* A typedef */
void VCAST_TI_9_5 ( Bit_Feld *vcast_param ) 
{
  {
    switch ( vcast_get_param () ) { /* Choose field member */
      /* Setting member variable vcast_param->B0 */
      case 1: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->B0;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->B0 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 1*/
      } /* end case */
      /* Setting member variable vcast_param->B1 */
      case 2: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->B1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->B1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 2*/
      } /* end case */
      /* Setting member variable vcast_param->B2 */
      case 3: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->B2;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->B2 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 3*/
      } /* end case */
      /* Setting member variable vcast_param->B3 */
      case 4: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->B3;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->B3 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 4*/
      } /* end case */
      /* Setting member variable vcast_param->B4 */
      case 5: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->B4;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->B4 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 5*/
      } /* end case */
      /* Setting member variable vcast_param->B5 */
      case 6: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->B5;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->B5 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 6*/
      } /* end case */
      /* Setting member variable vcast_param->B6 */
      case 7: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->B6;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->B6 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 7*/
      } /* end case */
      /* Setting member variable vcast_param->B7 */
      case 8: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->B7;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->B7 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 8*/
      } /* end case */
      default:
        vCAST_TOOL_ERROR = vCAST_true;
    } /* end switch */ 
  }
} /* end VCAST_TI_9_5 */
/* An array */
void VCAST_TI_9_41 ( unsigned char vcast_param[4] ) 
{
  {
    int VCAST_TI_9_41_array_index = 0;
    int VCAST_TI_9_41_index = 0;
    int VCAST_TI_9_41_first, VCAST_TI_9_41_last;
    int VCAST_TI_9_41_more_data; /* true if there is more data in the current command */
    int VCAST_TI_9_41_local_field = 0;
    int VCAST_TI_9_41_value_printed = 0;
    int VCAST_TI_9_41_is_string = (VCAST_FIND_INDEX()==-1);
    vcast_get_range_value (&VCAST_TI_9_41_first, &VCAST_TI_9_41_last, &VCAST_TI_9_41_more_data);
    VCAST_TI_9_41_local_field = vCAST_DATA_FIELD;
    if ( vCAST_SIZE && (!VCAST_TI_9_41_more_data)) { /* get the size of the array */
      vectorcast_fprint_integer (vCAST_OUTPUT_FILE,4);
      vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
      vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n");
    } else {
      int VCAST_TI_9_41_upper = 4;
      for (VCAST_TI_9_41_array_index=0; VCAST_TI_9_41_array_index< VCAST_TI_9_41_upper; VCAST_TI_9_41_array_index++){
        if ( (VCAST_TI_9_41_index >= VCAST_TI_9_41_first) && ( VCAST_TI_9_41_index <= VCAST_TI_9_41_last)){
          if ( VCAST_TI_9_41_is_string )
            VCAST_TI_STRING ( (char**)&vcast_param, sizeof ( vcast_param ), 1,VCAST_TI_9_41_upper);
          else
            VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param[VCAST_TI_9_41_index]))));
          VCAST_TI_9_41_value_printed = 1;
          vCAST_DATA_FIELD = VCAST_TI_9_41_local_field;
        } /* if */
        if (VCAST_TI_9_41_index >= VCAST_TI_9_41_last)
          break;
        VCAST_TI_9_41_index++;
      } /* loop */
      if ((vCAST_COMMAND == vCAST_PRINT)&&(!VCAST_TI_9_41_value_printed))
        vectorcast_fprint_string(vCAST_OUTPUT_FILE,"<<past end of array>>\n");
    } /* if */
  }
} /* end VCAST_TI_9_41 */
/* A typedef */
void VCAST_TI_9_55 ( _c_RlsmCem_SerNrLin1Fr01_CEM_LIN1_msgType *vcast_param ) 
{
  {
    switch ( vcast_get_param () ) { /* Choose field member */
      /* Setting member variable vcast_param->RLSMSerNoNr1_CEM_LIN1 */
      case 1: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->RLSMSerNoNr1_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->RLSMSerNoNr1_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 1*/
      } /* end case */
      /* Setting member variable vcast_param->RLSMSerNoNr2_CEM_LIN1 */
      case 2: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->RLSMSerNoNr2_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->RLSMSerNoNr2_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 2*/
      } /* end case */
      /* Setting member variable vcast_param->RLSMSerNoNr3_CEM_LIN1 */
      case 3: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->RLSMSerNoNr3_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->RLSMSerNoNr3_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 3*/
      } /* end case */
      /* Setting member variable vcast_param->RLSMSerNoNr4_CEM_LIN1 */
      case 4: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->RLSMSerNoNr4_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->RLSMSerNoNr4_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 4*/
      } /* end case */
      default:
        vCAST_TOOL_ERROR = vCAST_true;
    } /* end switch */ 
  }
} /* end VCAST_TI_9_55 */
/* An array */
void VCAST_TI_9_43 ( unsigned char vcast_param[8] ) 
{
  {
    int VCAST_TI_9_43_array_index = 0;
    int VCAST_TI_9_43_index = 0;
    int VCAST_TI_9_43_first, VCAST_TI_9_43_last;
    int VCAST_TI_9_43_more_data; /* true if there is more data in the current command */
    int VCAST_TI_9_43_local_field = 0;
    int VCAST_TI_9_43_value_printed = 0;
    int VCAST_TI_9_43_is_string = (VCAST_FIND_INDEX()==-1);
    vcast_get_range_value (&VCAST_TI_9_43_first, &VCAST_TI_9_43_last, &VCAST_TI_9_43_more_data);
    VCAST_TI_9_43_local_field = vCAST_DATA_FIELD;
    if ( vCAST_SIZE && (!VCAST_TI_9_43_more_data)) { /* get the size of the array */
      vectorcast_fprint_integer (vCAST_OUTPUT_FILE,8);
      vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
      vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n");
    } else {
      int VCAST_TI_9_43_upper = 8;
      for (VCAST_TI_9_43_array_index=0; VCAST_TI_9_43_array_index< VCAST_TI_9_43_upper; VCAST_TI_9_43_array_index++){
        if ( (VCAST_TI_9_43_index >= VCAST_TI_9_43_first) && ( VCAST_TI_9_43_index <= VCAST_TI_9_43_last)){
          if ( VCAST_TI_9_43_is_string )
            VCAST_TI_STRING ( (char**)&vcast_param, sizeof ( vcast_param ), 1,VCAST_TI_9_43_upper);
          else
            VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param[VCAST_TI_9_43_index]))));
          VCAST_TI_9_43_value_printed = 1;
          vCAST_DATA_FIELD = VCAST_TI_9_43_local_field;
        } /* if */
        if (VCAST_TI_9_43_index >= VCAST_TI_9_43_last)
          break;
        VCAST_TI_9_43_index++;
      } /* loop */
      if ((vCAST_COMMAND == vCAST_PRINT)&&(!VCAST_TI_9_43_value_printed))
        vectorcast_fprint_string(vCAST_OUTPUT_FILE,"<<past end of array>>\n");
    } /* if */
  }
} /* end VCAST_TI_9_43 */
/* A typedef */
void VCAST_TI_9_59 ( _c_RlsmCem_Lin1PartNrFr02_CEM_LIN1_msgType *vcast_param ) 
{
  {
    switch ( vcast_get_param () ) { /* Choose field member */
      /* Setting member variable vcast_param->RLSMPartNo10Nr1_CEM_LIN1 */
      case 1: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->RLSMPartNo10Nr1_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->RLSMPartNo10Nr1_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 1*/
      } /* end case */
      /* Setting member variable vcast_param->RLSMPartNo10Nr2_CEM_LIN1 */
      case 2: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->RLSMPartNo10Nr2_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->RLSMPartNo10Nr2_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 2*/
      } /* end case */
      /* Setting member variable vcast_param->RLSMPartNo10Nr3_CEM_LIN1 */
      case 3: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->RLSMPartNo10Nr3_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->RLSMPartNo10Nr3_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 3*/
      } /* end case */
      /* Setting member variable vcast_param->RLSMPartNo10Nr4_CEM_LIN1 */
      case 4: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->RLSMPartNo10Nr4_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->RLSMPartNo10Nr4_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 4*/
      } /* end case */
      /* Setting member variable vcast_param->RLSMPartNo10Nr5_CEM_LIN1 */
      case 5: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->RLSMPartNo10Nr5_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->RLSMPartNo10Nr5_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 5*/
      } /* end case */
      /* Setting member variable vcast_param->RLSMPartNo10EndSgn1_CEM_LIN1 */
      case 6: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->RLSMPartNo10EndSgn1_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->RLSMPartNo10EndSgn1_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 6*/
      } /* end case */
      /* Setting member variable vcast_param->RLSMPartNo10EndSgn2_CEM_LIN1 */
      case 7: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->RLSMPartNo10EndSgn2_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->RLSMPartNo10EndSgn2_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 7*/
      } /* end case */
      /* Setting member variable vcast_param->RLSMPartNo10EndSgn3_CEM_LIN1 */
      case 8: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->RLSMPartNo10EndSgn3_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->RLSMPartNo10EndSgn3_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 8*/
      } /* end case */
      default:
        vCAST_TOOL_ERROR = vCAST_true;
    } /* end switch */ 
  }
} /* end VCAST_TI_9_59 */
/* An array */
void VCAST_TI_9_45 ( unsigned char vcast_param[7] ) 
{
  {
    int VCAST_TI_9_45_array_index = 0;
    int VCAST_TI_9_45_index = 0;
    int VCAST_TI_9_45_first, VCAST_TI_9_45_last;
    int VCAST_TI_9_45_more_data; /* true if there is more data in the current command */
    int VCAST_TI_9_45_local_field = 0;
    int VCAST_TI_9_45_value_printed = 0;
    int VCAST_TI_9_45_is_string = (VCAST_FIND_INDEX()==-1);
    vcast_get_range_value (&VCAST_TI_9_45_first, &VCAST_TI_9_45_last, &VCAST_TI_9_45_more_data);
    VCAST_TI_9_45_local_field = vCAST_DATA_FIELD;
    if ( vCAST_SIZE && (!VCAST_TI_9_45_more_data)) { /* get the size of the array */
      vectorcast_fprint_integer (vCAST_OUTPUT_FILE,7);
      vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
      vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n");
    } else {
      int VCAST_TI_9_45_upper = 7;
      for (VCAST_TI_9_45_array_index=0; VCAST_TI_9_45_array_index< VCAST_TI_9_45_upper; VCAST_TI_9_45_array_index++){
        if ( (VCAST_TI_9_45_index >= VCAST_TI_9_45_first) && ( VCAST_TI_9_45_index <= VCAST_TI_9_45_last)){
          if ( VCAST_TI_9_45_is_string )
            VCAST_TI_STRING ( (char**)&vcast_param, sizeof ( vcast_param ), 1,VCAST_TI_9_45_upper);
          else
            VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param[VCAST_TI_9_45_index]))));
          VCAST_TI_9_45_value_printed = 1;
          vCAST_DATA_FIELD = VCAST_TI_9_45_local_field;
        } /* if */
        if (VCAST_TI_9_45_index >= VCAST_TI_9_45_last)
          break;
        VCAST_TI_9_45_index++;
      } /* loop */
      if ((vCAST_COMMAND == vCAST_PRINT)&&(!VCAST_TI_9_45_value_printed))
        vectorcast_fprint_string(vCAST_OUTPUT_FILE,"<<past end of array>>\n");
    } /* if */
  }
} /* end VCAST_TI_9_45 */
/* A typedef */
void VCAST_TI_9_57 ( _c_RlsmCem_Lin1PartNrFr01_CEM_LIN1_msgType *vcast_param ) 
{
  {
    switch ( vcast_get_param () ) { /* Choose field member */
      /* Setting member variable vcast_param->RLSMPartNoNr1_CEM_LIN1 */
      case 1: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->RLSMPartNoNr1_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->RLSMPartNoNr1_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 1*/
      } /* end case */
      /* Setting member variable vcast_param->RLSMPartNoNr2_CEM_LIN1 */
      case 2: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->RLSMPartNoNr2_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->RLSMPartNoNr2_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 2*/
      } /* end case */
      /* Setting member variable vcast_param->RLSMPartNoNr3_CEM_LIN1 */
      case 3: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->RLSMPartNoNr3_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->RLSMPartNoNr3_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 3*/
      } /* end case */
      /* Setting member variable vcast_param->RLSMPartNoNr4_CEM_LIN1 */
      case 4: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->RLSMPartNoNr4_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->RLSMPartNoNr4_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 4*/
      } /* end case */
      /* Setting member variable vcast_param->RLSMPartNoEndSgn1_CEM_LIN1 */
      case 5: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->RLSMPartNoEndSgn1_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->RLSMPartNoEndSgn1_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 5*/
      } /* end case */
      /* Setting member variable vcast_param->RLSMPartNoEndSgn2_CEM_LIN1 */
      case 6: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->RLSMPartNoEndSgn2_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->RLSMPartNoEndSgn2_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 6*/
      } /* end case */
      /* Setting member variable vcast_param->RLSMPartNoEndSgn3_CEM_LIN1 */
      case 7: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->RLSMPartNoEndSgn3_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->RLSMPartNoEndSgn3_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 7*/
      } /* end case */
      default:
        vCAST_TOOL_ERROR = vCAST_true;
    } /* end switch */ 
  }
} /* end VCAST_TI_9_57 */
/* A typedef */
void VCAST_TI_9_34 ( _c_RlsmCem_Lin1Fr03_CEM_LIN1_msgType *vcast_param ) 
{
  {
    switch ( vcast_get_param () ) { /* Choose field member */
      /* Setting member variable vcast_param->SolarSnsrErr_CEM_LIN1 */
      case 1: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->SolarSnsrErr_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 3, vCAST_false );
        vcast_param->SolarSnsrErr_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 1*/
      } /* end case */
      /* Setting member variable vcast_param->RainSnsrDiagcRainSnsrHiVoltDetd_CEM_LIN1 */
      case 2: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->RainSnsrDiagcRainSnsrHiVoltDetd_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->RainSnsrDiagcRainSnsrHiVoltDetd_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 2*/
      } /* end case */
      /* Setting member variable vcast_param->RainSnsrDiagcRainSnsrHiTDetd_CEM_LIN1 */
      case 3: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->RainSnsrDiagcRainSnsrHiTDetd_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->RainSnsrDiagcRainSnsrHiTDetd_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 3*/
      } /* end case */
      /* Setting member variable vcast_param->LiOprnMod_CEM_LIN1 */
      case 4: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->LiOprnMod_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 2, vCAST_false );
        vcast_param->LiOprnMod_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 4*/
      } /* end case */
      /* Setting member variable vcast_param->RainDetected_CEM_LIN1 */
      case 5: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->RainDetected_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->RainDetected_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 5*/
      } /* end case */
      /* Setting member variable vcast_param->unused0 */
      case 6: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->unused0;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->unused0 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 6*/
      } /* end case */
      /* Setting member variable vcast_param->SolarSnsrLeValue_CEM_LIN1 */
      case 7: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->SolarSnsrLeValue_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->SolarSnsrLeValue_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 7*/
      } /* end case */
      /* Setting member variable vcast_param->SolarSnsrRiValue_CEM_LIN1 */
      case 8: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->SolarSnsrRiValue_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->SolarSnsrRiValue_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 8*/
      } /* end case */
      /* Setting member variable vcast_param->unused1 */
      case 9: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->unused1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->unused1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 9*/
      } /* end case */
      /* Setting member variable vcast_param->unused2 */
      case 10: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->unused2;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->unused2 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 10*/
      } /* end case */
      /* Setting member variable vcast_param->unused3 */
      case 11: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->unused3;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->unused3 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 11*/
      } /* end case */
      /* Setting member variable vcast_param->unused4 */
      case 12: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->unused4;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->unused4 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 12*/
      } /* end case */
      default:
        vCAST_TOOL_ERROR = vCAST_true;
    } /* end switch */ 
  }
} /* end VCAST_TI_9_34 */
/* A typedef */
void VCAST_TI_9_36 ( _c_RlsmCem_Lin1Fr02_CEM_LIN1_msgType *vcast_param ) 
{
  {
    switch ( vcast_get_param () ) { /* Choose field member */
      /* Setting member variable vcast_param->CmptFrntWindDewT_CEM_LIN1_0 */
      case 1: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->CmptFrntWindDewT_CEM_LIN1_0;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->CmptFrntWindDewT_CEM_LIN1_0 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 1*/
      } /* end case */
      /* Setting member variable vcast_param->CmptFrntWindDewT_CEM_LIN1_1 */
      case 2: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->CmptFrntWindDewT_CEM_LIN1_1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 3, vCAST_false );
        vcast_param->CmptFrntWindDewT_CEM_LIN1_1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 2*/
      } /* end case */
      /* Setting member variable vcast_param->AmbIllmnFwdStsCntr_CEM_LIN1 */
      case 3: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->AmbIllmnFwdStsCntr_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 4, vCAST_false );
        vcast_param->AmbIllmnFwdStsCntr_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 3*/
      } /* end case */
      /* Setting member variable vcast_param->unused0 */
      case 4: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->unused0;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->unused0 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 4*/
      } /* end case */
      /* Setting member variable vcast_param->AmbIllmnFwdStsAmblillmn2_CEM_LIN1 */
      case 5: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->AmbIllmnFwdStsAmblillmn2_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->AmbIllmnFwdStsAmblillmn2_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 5*/
      } /* end case */
      /* Setting member variable vcast_param->AmbIllmnFwdStsChks_CEM_LIN1 */
      case 6: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->AmbIllmnFwdStsChks_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->AmbIllmnFwdStsChks_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 6*/
      } /* end case */
      /* Setting member variable vcast_param->AmbIllmnFwdStsAmblillmn1_CEM_LIN1_0 */
      case 7: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->AmbIllmnFwdStsAmblillmn1_CEM_LIN1_0;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->AmbIllmnFwdStsAmblillmn1_CEM_LIN1_0 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 7*/
      } /* end case */
      /* Setting member variable vcast_param->AmbIllmnFwdStsAmblillmn1_CEM_LIN1_1 */
      case 8: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->AmbIllmnFwdStsAmblillmn1_CEM_LIN1_1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->AmbIllmnFwdStsAmblillmn1_CEM_LIN1_1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 8*/
      } /* end case */
      /* Setting member variable vcast_param->CmptFrntWindTErr_CEM_LIN1 */
      case 9: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->CmptFrntWindTErr_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->CmptFrntWindTErr_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 9*/
      } /* end case */
      /* Setting member variable vcast_param->RelHumSnsrErr_CEM_LIN1 */
      case 10: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->RelHumSnsrErr_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 3, vCAST_false );
        vcast_param->RelHumSnsrErr_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 10*/
      } /* end case */
      /* Setting member variable vcast_param->CmptFrntWindT_CEM_LIN1_0 */
      case 11: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->CmptFrntWindT_CEM_LIN1_0;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 3, vCAST_false );
        vcast_param->CmptFrntWindT_CEM_LIN1_0 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 11*/
      } /* end case */
      /* Setting member variable vcast_param->CmptFrntWindT_CEM_LIN1_1 */
      case 12: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->CmptFrntWindT_CEM_LIN1_1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->CmptFrntWindT_CEM_LIN1_1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 12*/
      } /* end case */
      /* Setting member variable vcast_param->RelHumSnsrRelHum_CEM_LIN1 */
      case 13: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->RelHumSnsrRelHum_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->RelHumSnsrRelHum_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 13*/
      } /* end case */
      default:
        vCAST_TOOL_ERROR = vCAST_true;
    } /* end switch */ 
  }
} /* end VCAST_TI_9_36 */
/* A typedef */
void VCAST_TI_9_13 ( _c_RlsmCem_Lin1Fr01_CEM_LIN1_msgType *vcast_param ) 
{
  {
    switch ( vcast_get_param () ) { /* Choose field member */
      /* Setting member variable vcast_param->AutWinWipgCmd_CEM_LIN1 */
      case 1: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->AutWinWipgCmd_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 3, vCAST_false );
        vcast_param->AutWinWipgCmd_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 1*/
      } /* end case */
      /* Setting member variable vcast_param->HudSnsrErrParChk_CEM_LIN1 */
      case 2: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->HudSnsrErrParChk_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->HudSnsrErrParChk_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 2*/
      } /* end case */
      /* Setting member variable vcast_param->HudSnsrErrSnsrErr_CEM_LIN1 */
      case 3: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->HudSnsrErrSnsrErr_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->HudSnsrErrSnsrErr_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 3*/
      } /* end case */
      /* Setting member variable vcast_param->unused0 */
      case 4: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->unused0;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 2, vCAST_false );
        vcast_param->unused0 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 4*/
      } /* end case */
      /* Setting member variable vcast_param->RainLi_CEM_LIN1 */
      case 5: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->RainLi_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->RainLi_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 5*/
      } /* end case */
      /* Setting member variable vcast_param->RainSnsrErrCalErrActv_CEM_LIN1 */
      case 6: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->RainSnsrErrCalErrActv_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->RainSnsrErrCalErrActv_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 6*/
      } /* end case */
      /* Setting member variable vcast_param->RainSnsrErrCalErr_CEM_LIN1 */
      case 7: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->RainSnsrErrCalErr_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->RainSnsrErrCalErr_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 7*/
      } /* end case */
      /* Setting member variable vcast_param->RainSnsrErrRainDetnErr_CEM_LIN1 */
      case 8: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->RainSnsrErrRainDetnErr_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->RainSnsrErrRainDetnErr_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 8*/
      } /* end case */
      /* Setting member variable vcast_param->RainSnsrErrRainDetnErrActv_CEM_LIN1 */
      case 9: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->RainSnsrErrRainDetnErrActv_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->RainSnsrErrRainDetnErrActv_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 9*/
      } /* end case */
      /* Setting member variable vcast_param->WipgAutFrntMod_CEM_LIN1 */
      case 10: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->WipgAutFrntMod_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 2, vCAST_false );
        vcast_param->WipgAutFrntMod_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 10*/
      } /* end case */
      /* Setting member variable vcast_param->unused1 */
      case 11: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->unused1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->unused1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 11*/
      } /* end case */
      /* Setting member variable vcast_param->ErrRespRLSM_CEM_LIN1 */
      case 12: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->ErrRespRLSM_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->ErrRespRLSM_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 12*/
      } /* end case */
      /* Setting member variable vcast_param->unused2 */
      case 13: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->unused2;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->unused2 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 13*/
      } /* end case */
      /* Setting member variable vcast_param->TwliBriRawQf_CEM_LIN1 */
      case 14: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->TwliBriRawQf_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 2, vCAST_false );
        vcast_param->TwliBriRawQf_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 14*/
      } /* end case */
      /* Setting member variable vcast_param->TwliBriRawTwliBriRaw_CEM_LIN1_0 */
      case 15: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->TwliBriRawTwliBriRaw_CEM_LIN1_0;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 6, vCAST_false );
        vcast_param->TwliBriRawTwliBriRaw_CEM_LIN1_0 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 15*/
      } /* end case */
      /* Setting member variable vcast_param->TwliBriRawTwliBriRaw_CEM_LIN1_1 */
      case 16: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->TwliBriRawTwliBriRaw_CEM_LIN1_1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->TwliBriRawTwliBriRaw_CEM_LIN1_1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 16*/
      } /* end case */
      /* Setting member variable vcast_param->unused3 */
      case 17: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->unused3;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->unused3 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 17*/
      } /* end case */
      /* Setting member variable vcast_param->OutdBriChks_CEM_LIN1 */
      case 18: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->OutdBriChks_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->OutdBriChks_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 18*/
      } /* end case */
      /* Setting member variable vcast_param->OutdBriSts_CEM_LIN1 */
      case 19: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->OutdBriSts_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 2, vCAST_false );
        vcast_param->OutdBriSts_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 19*/
      } /* end case */
      /* Setting member variable vcast_param->unused4 */
      case 20: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->unused4;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 6, vCAST_false );
        vcast_param->unused4 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 20*/
      } /* end case */
      default:
        vCAST_TOOL_ERROR = vCAST_true;
    } /* end switch */ 
  }
} /* end VCAST_TI_9_13 */
/* A typedef */
void VCAST_TI_9_19 ( _c_CemCem_Lin1Fr06_CEM_LIN1_msgType *vcast_param ) 
{
  {
    switch ( vcast_get_param () ) { /* Choose field member */
      /* Setting member variable vcast_param->unused0 */
      case 1: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->unused0;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 4, vCAST_false );
        vcast_param->unused0 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 1*/
      } /* end case */
      /* Setting member variable vcast_param->WiprActv_CEM_LIN1 */
      case 2: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->WiprActv_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->WiprActv_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 2*/
      } /* end case */
      /* Setting member variable vcast_param->WiprInPrkgPosnLo_CEM_LIN1 */
      case 3: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->WiprInPrkgPosnLo_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->WiprInPrkgPosnLo_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 3*/
      } /* end case */
      /* Setting member variable vcast_param->WiprInWipgAr_CEM_LIN1 */
      case 4: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->WiprInWipgAr_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->WiprInWipgAr_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 4*/
      } /* end case */
      /* Setting member variable vcast_param->WshngCycActv_CEM_LIN1 */
      case 5: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->WshngCycActv_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->WshngCycActv_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 5*/
      } /* end case */
      default:
        vCAST_TOOL_ERROR = vCAST_true;
    } /* end switch */ 
  }
} /* end VCAST_TI_9_19 */
/* A typedef */
void VCAST_TI_9_2 ( _c_CemCem_Lin1Fr05_CEM_LIN1_msgType *vcast_param ) 
{
  {
    switch ( vcast_get_param () ) { /* Choose field member */
      /* Setting member variable vcast_param->unused0 */
      case 1: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->unused0;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->unused0 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 1*/
      } /* end case */
      /* Setting member variable vcast_param->VehMtnStCntr_CEM_LIN1 */
      case 2: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->VehMtnStCntr_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 4, vCAST_false );
        vcast_param->VehMtnStCntr_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 2*/
      } /* end case */
      /* Setting member variable vcast_param->VehMtnStVehMtnSt_CEM_LIN1 */
      case 3: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->VehMtnStVehMtnSt_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 3, vCAST_false );
        vcast_param->VehMtnStVehMtnSt_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 3*/
      } /* end case */
      /* Setting member variable vcast_param->VehMtnStChks_CEM_LIN1 */
      case 4: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->VehMtnStChks_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->VehMtnStChks_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 4*/
      } /* end case */
      /* Setting member variable vcast_param->unused1 */
      case 5: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->unused1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->unused1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 5*/
      } /* end case */
      /* Setting member variable vcast_param->EnaOfflineMonitor_CEM_LIN1 */
      case 6: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->EnaOfflineMonitor_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->EnaOfflineMonitor_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 6*/
      } /* end case */
      /* Setting member variable vcast_param->unused2 */
      case 7: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->unused2;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 6, vCAST_false );
        vcast_param->unused2 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 7*/
      } /* end case */
      /* Setting member variable vcast_param->unused3 */
      case 8: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->unused3;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->unused3 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 8*/
      } /* end case */
      /* Setting member variable vcast_param->unused4 */
      case 9: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->unused4;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->unused4 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 9*/
      } /* end case */
      /* Setting member variable vcast_param->unused5 */
      case 10: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->unused5;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->unused5 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 10*/
      } /* end case */
      /* Setting member variable vcast_param->unused6 */
      case 11: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->unused6;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->unused6 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 11*/
      } /* end case */
      default:
        vCAST_TOOL_ERROR = vCAST_true;
    } /* end switch */ 
  }
} /* end VCAST_TI_9_2 */
/* A typedef */
void VCAST_TI_9_17 ( _c_CemCem_Lin1Fr04_CEM_LIN1_msgType *vcast_param ) 
{
  {
    switch ( vcast_get_param () ) { /* Choose field member */
      /* Setting member variable vcast_param->unused0 */
      case 1: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->unused0;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->unused0 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 1*/
      } /* end case */
      /* Setting member variable vcast_param->unused1 */
      case 2: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->unused1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->unused1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 2*/
      } /* end case */
      /* Setting member variable vcast_param->unused2 */
      case 3: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->unused2;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->unused2 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 3*/
      } /* end case */
      /* Setting member variable vcast_param->unused3 */
      case 4: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->unused3;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->unused3 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 4*/
      } /* end case */
      /* Setting member variable vcast_param->DoorDrvrSts_CEM_LIN1 */
      case 5: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->DoorDrvrSts_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 2, vCAST_false );
        vcast_param->DoorDrvrSts_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 5*/
      } /* end case */
      /* Setting member variable vcast_param->unused4 */
      case 6: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->unused4;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 6, vCAST_false );
        vcast_param->unused4 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 6*/
      } /* end case */
      /* Setting member variable vcast_param->unused5 */
      case 7: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->unused5;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 4, vCAST_false );
        vcast_param->unused5 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 7*/
      } /* end case */
      /* Setting member variable vcast_param->RainSnsrLiThd_CEM_LIN1 */
      case 8: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->RainSnsrLiThd_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 4, vCAST_false );
        vcast_param->RainSnsrLiThd_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 8*/
      } /* end case */
      /* Setting member variable vcast_param->unused6 */
      case 9: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->unused6;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->unused6 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 9*/
      } /* end case */
      default:
        vCAST_TOOL_ERROR = vCAST_true;
    } /* end switch */ 
  }
} /* end VCAST_TI_9_17 */
/* A typedef */
void VCAST_TI_9_15 ( _c_CemCem_Lin1Fr03_CEM_LIN1_msgType *vcast_param ) 
{
  {
    switch ( vcast_get_param () ) { /* Choose field member */
      /* Setting member variable vcast_param->RainSnsrSnvtyForUsrSnvty0_CEM_LIN1 */
      case 1: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->RainSnsrSnvtyForUsrSnvty0_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 4, vCAST_false );
        vcast_param->RainSnsrSnvtyForUsrSnvty0_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 1*/
      } /* end case */
      /* Setting member variable vcast_param->RainSnsrSnvtyForUsrSnvty1_CEM_LIN1 */
      case 2: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->RainSnsrSnvtyForUsrSnvty1_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 4, vCAST_false );
        vcast_param->RainSnsrSnvtyForUsrSnvty1_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 2*/
      } /* end case */
      /* Setting member variable vcast_param->RainSnsrSnvtyForUsrSnvty2_CEM_LIN1 */
      case 3: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->RainSnsrSnvtyForUsrSnvty2_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 4, vCAST_false );
        vcast_param->RainSnsrSnvtyForUsrSnvty2_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 3*/
      } /* end case */
      /* Setting member variable vcast_param->RainSnsrSnvtyForUsrSnvty3_CEM_LIN1 */
      case 4: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->RainSnsrSnvtyForUsrSnvty3_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 4, vCAST_false );
        vcast_param->RainSnsrSnvtyForUsrSnvty3_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 4*/
      } /* end case */
      /* Setting member variable vcast_param->RainSnsrSnvtyForUsrSnvty4_CEM_LIN1 */
      case 5: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->RainSnsrSnvtyForUsrSnvty4_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 4, vCAST_false );
        vcast_param->RainSnsrSnvtyForUsrSnvty4_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 5*/
      } /* end case */
      /* Setting member variable vcast_param->RainSnsrSnvtyForUsrSnvty5_CEM_LIN1 */
      case 6: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->RainSnsrSnvtyForUsrSnvty5_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 4, vCAST_false );
        vcast_param->RainSnsrSnvtyForUsrSnvty5_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 6*/
      } /* end case */
      /* Setting member variable vcast_param->RainSnsrSnvtyForUsrSnvty6_CEM_LIN1 */
      case 7: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->RainSnsrSnvtyForUsrSnvty6_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 4, vCAST_false );
        vcast_param->RainSnsrSnvtyForUsrSnvty6_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 7*/
      } /* end case */
      /* Setting member variable vcast_param->VehTyp_CEM_LIN1 */
      case 8: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->VehTyp_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 4, vCAST_false );
        vcast_param->VehTyp_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 8*/
      } /* end case */
      /* Setting member variable vcast_param->WindCorrnValAmb_CEM_LIN1 */
      case 9: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->WindCorrnValAmb_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->WindCorrnValAmb_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 9*/
      } /* end case */
      /* Setting member variable vcast_param->WindCorrnValFrnt_CEM_LIN1 */
      case 10: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->WindCorrnValFrnt_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->WindCorrnValFrnt_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 10*/
      } /* end case */
      /* Setting member variable vcast_param->WindCorrnValHud_CEM_LIN1 */
      case 11: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->WindCorrnValHud_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->WindCorrnValHud_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 11*/
      } /* end case */
      /* Setting member variable vcast_param->FrqCfg_CEM_LIN1 */
      case 12: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->FrqCfg_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 4, vCAST_false );
        vcast_param->FrqCfg_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 12*/
      } /* end case */
      /* Setting member variable vcast_param->ReAdaptReq_CEM_LIN1 */
      case 13: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->ReAdaptReq_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->ReAdaptReq_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 13*/
      } /* end case */
      /* Setting member variable vcast_param->unused0 */
      case 14: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->unused0;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 3, vCAST_false );
        vcast_param->unused0 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 14*/
      } /* end case */
      default:
        vCAST_TOOL_ERROR = vCAST_true;
    } /* end switch */ 
  }
} /* end VCAST_TI_9_15 */
/* A typedef */
void VCAST_TI_9_11 ( _c_CemCem_Lin1Fr02_CEM_LIN1_msgType *vcast_param ) 
{
  {
    switch ( vcast_get_param () ) { /* Choose field member */
      /* Setting member variable vcast_param->AmbTForVisy_CEM_LIN1 */
      case 1: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->AmbTForVisy_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->AmbTForVisy_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 1*/
      } /* end case */
      /* Setting member variable vcast_param->unused0 */
      case 2: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->unused0;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->unused0 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 2*/
      } /* end case */
      /* Setting member variable vcast_param->VehModMngtGlbSafe1FltEgyCnsWdSts_CEM_LIN1 */
      case 3: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->VehModMngtGlbSafe1FltEgyCnsWdSts_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->VehModMngtGlbSafe1FltEgyCnsWdSts_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 3*/
      } /* end case */
      /* Setting member variable vcast_param->VehModMngtGlbSafe1CarModSts1_CEM_LIN1 */
      case 4: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->VehModMngtGlbSafe1CarModSts1_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 3, vCAST_false );
        vcast_param->VehModMngtGlbSafe1CarModSts1_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 4*/
      } /* end case */
      /* Setting member variable vcast_param->VehModMngtGlbSafe1CarModSubtypWdCarModSubtyp_CEM_LIN1 */
      case 5: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->VehModMngtGlbSafe1CarModSubtypWdCarModSubtyp_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 3, vCAST_false );
        vcast_param->VehModMngtGlbSafe1CarModSubtypWdCarModSubtyp_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 5*/
      } /* end case */
      /* Setting member variable vcast_param->VehModMngtGlbSafe1Chks_CEM_LIN1 */
      case 6: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->VehModMngtGlbSafe1Chks_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->VehModMngtGlbSafe1Chks_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 6*/
      } /* end case */
      /* Setting member variable vcast_param->VehModMngtGlbSafe1EgyLvlElecMai_CEM_LIN1 */
      case 7: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->VehModMngtGlbSafe1EgyLvlElecMai_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 4, vCAST_false );
        vcast_param->VehModMngtGlbSafe1EgyLvlElecMai_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 7*/
      } /* end case */
      /* Setting member variable vcast_param->VehModMngtGlbSafe1Cntr_CEM_LIN1 */
      case 8: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->VehModMngtGlbSafe1Cntr_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 4, vCAST_false );
        vcast_param->VehModMngtGlbSafe1Cntr_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 8*/
      } /* end case */
      /* Setting member variable vcast_param->VehModMngtGlbSafe1PwrLvlElecMai_CEM_LIN1 */
      case 9: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->VehModMngtGlbSafe1PwrLvlElecMai_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 4, vCAST_false );
        vcast_param->VehModMngtGlbSafe1PwrLvlElecMai_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 9*/
      } /* end case */
      /* Setting member variable vcast_param->VehModMngtGlbSafe1EgyLvlElecSubtyp_CEM_LIN1 */
      case 10: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->VehModMngtGlbSafe1EgyLvlElecSubtyp_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 4, vCAST_false );
        vcast_param->VehModMngtGlbSafe1EgyLvlElecSubtyp_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 10*/
      } /* end case */
      /* Setting member variable vcast_param->VehModMngtGlbSafe1UsgModSts_CEM_LIN1 */
      case 11: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->VehModMngtGlbSafe1UsgModSts_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 4, vCAST_false );
        vcast_param->VehModMngtGlbSafe1UsgModSts_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 11*/
      } /* end case */
      /* Setting member variable vcast_param->VehModMngtGlbSafe1PwrLvlElecSubtyp_CEM_LIN1 */
      case 12: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->VehModMngtGlbSafe1PwrLvlElecSubtyp_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 4, vCAST_false );
        vcast_param->VehModMngtGlbSafe1PwrLvlElecSubtyp_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 12*/
      } /* end case */
      /* Setting member variable vcast_param->unused1 */
      case 13: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->unused1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->unused1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 13*/
      } /* end case */
      default:
        vCAST_TOOL_ERROR = vCAST_true;
    } /* end switch */ 
  }
} /* end VCAST_TI_9_11 */
/* An array */
void VCAST_TI_9_111 ( unsigned char vcast_param[6] ) 
{
  {
    int VCAST_TI_9_111_array_index = 0;
    int VCAST_TI_9_111_index = 0;
    int VCAST_TI_9_111_first, VCAST_TI_9_111_last;
    int VCAST_TI_9_111_more_data; /* true if there is more data in the current command */
    int VCAST_TI_9_111_local_field = 0;
    int VCAST_TI_9_111_value_printed = 0;
    int VCAST_TI_9_111_is_string = (VCAST_FIND_INDEX()==-1);
    vcast_get_range_value (&VCAST_TI_9_111_first, &VCAST_TI_9_111_last, &VCAST_TI_9_111_more_data);
    VCAST_TI_9_111_local_field = vCAST_DATA_FIELD;
    if ( vCAST_SIZE && (!VCAST_TI_9_111_more_data)) { /* get the size of the array */
      vectorcast_fprint_integer (vCAST_OUTPUT_FILE,6);
      vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
      vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n");
    } else {
      int VCAST_TI_9_111_upper = 6;
      for (VCAST_TI_9_111_array_index=0; VCAST_TI_9_111_array_index< VCAST_TI_9_111_upper; VCAST_TI_9_111_array_index++){
        if ( (VCAST_TI_9_111_index >= VCAST_TI_9_111_first) && ( VCAST_TI_9_111_index <= VCAST_TI_9_111_last)){
          if ( VCAST_TI_9_111_is_string )
            VCAST_TI_STRING ( (char**)&vcast_param, sizeof ( vcast_param ), 1,VCAST_TI_9_111_upper);
          else
            VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param[VCAST_TI_9_111_index]))));
          VCAST_TI_9_111_value_printed = 1;
          vCAST_DATA_FIELD = VCAST_TI_9_111_local_field;
        } /* if */
        if (VCAST_TI_9_111_index >= VCAST_TI_9_111_last)
          break;
        VCAST_TI_9_111_index++;
      } /* loop */
      if ((vCAST_COMMAND == vCAST_PRINT)&&(!VCAST_TI_9_111_value_printed))
        vectorcast_fprint_string(vCAST_OUTPUT_FILE,"<<past end of array>>\n");
    } /* if */
  }
} /* end VCAST_TI_9_111 */
/* A typedef */
void VCAST_TI_9_25 ( _c_CemCem_Lin1Fr01_CEM_LIN1_msgType *vcast_param ) 
{
  {
    switch ( vcast_get_param () ) { /* Choose field member */
      /* Setting member variable vcast_param->VehSpdForWipg_CEM_LIN1 */
      case 1: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->VehSpdForWipg_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->VehSpdForWipg_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 1*/
      } /* end case */
      /* Setting member variable vcast_param->WipgPwrActvnSafeWipgPwrAcsyModSafe_CEM_LIN1 */
      case 2: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->WipgPwrActvnSafeWipgPwrAcsyModSafe_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 2, vCAST_false );
        vcast_param->WipgPwrActvnSafeWipgPwrAcsyModSafe_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 2*/
      } /* end case */
      /* Setting member variable vcast_param->WipgPwrActvnSafeWipgPwrDrvgModSafe_CEM_LIN1 */
      case 3: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->WipgPwrActvnSafeWipgPwrDrvgModSafe_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 2, vCAST_false );
        vcast_param->WipgPwrActvnSafeWipgPwrDrvgModSafe_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 3*/
      } /* end case */
      /* Setting member variable vcast_param->RainSensActvn_CEM_LIN1 */
      case 4: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->RainSensActvn_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->RainSensActvn_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 4*/
      } /* end case */
      /* Setting member variable vcast_param->WshrLvrPosnSafe_CEM_LIN1 */
      case 5: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->WshrLvrPosnSafe_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 2, vCAST_false );
        vcast_param->WshrLvrPosnSafe_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 5*/
      } /* end case */
      /* Setting member variable vcast_param->unused0 */
      case 6: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->unused0;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->unused0 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 6*/
      } /* end case */
      /* Setting member variable vcast_param->WiprMotFrntLvrCmdSafeLvrInHiSpdPosnSafe_CEM_LIN1 */
      case 7: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->WiprMotFrntLvrCmdSafeLvrInHiSpdPosnSafe_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 2, vCAST_false );
        vcast_param->WiprMotFrntLvrCmdSafeLvrInHiSpdPosnSafe_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 7*/
      } /* end case */
      /* Setting member variable vcast_param->WiprMotFrntLvrCmdSafeLvrInLoSpdPosnSafe_CEM_LIN1 */
      case 8: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->WiprMotFrntLvrCmdSafeLvrInLoSpdPosnSafe_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 2, vCAST_false );
        vcast_param->WiprMotFrntLvrCmdSafeLvrInLoSpdPosnSafe_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 8*/
      } /* end case */
      /* Setting member variable vcast_param->WiprMotFrntLvrCmdSafeLvrInSnglStrokePos_CEM_LIN1 */
      case 9: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->WiprMotFrntLvrCmdSafeLvrInSnglStrokePos_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->WiprMotFrntLvrCmdSafeLvrInSnglStrokePos_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 9*/
      } /* end case */
      /* Setting member variable vcast_param->WiprMotFrntLvrCmdSafeLvrInIntlPosn_CEM_LIN1 */
      case 10: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->WiprMotFrntLvrCmdSafeLvrInIntlPosn_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->WiprMotFrntLvrCmdSafeLvrInIntlPosn_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 10*/
      } /* end case */
      /* Setting member variable vcast_param->HomeLinkEna_CEM_LIN1 */
      case 11: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->HomeLinkEna_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 2, vCAST_false );
        vcast_param->HomeLinkEna_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 11*/
      } /* end case */
      /* Setting member variable vcast_param->WiprMotIntlCmd_CEM_LIN1 */
      case 12: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->WiprMotIntlCmd_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 3, vCAST_false );
        vcast_param->WiprMotIntlCmd_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 12*/
      } /* end case */
      /* Setting member variable vcast_param->WiprPosnForSrvReq_CEM_LIN1 */
      case 13: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->WiprPosnForSrvReq_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->WiprPosnForSrvReq_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 13*/
      } /* end case */
      /* Setting member variable vcast_param->unused1 */
      case 14: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->unused1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 4, vCAST_false );
        vcast_param->unused1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 14*/
      } /* end case */
      /* Setting member variable vcast_param->IntrMirrCmdIntrMirrDimSnvty_CEM_LIN1 */
      case 15: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->IntrMirrCmdIntrMirrDimSnvty_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 2, vCAST_false );
        vcast_param->IntrMirrCmdIntrMirrDimSnvty_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 15*/
      } /* end case */
      /* Setting member variable vcast_param->IntrMirrCmdDrvrSide_CEM_LIN1 */
      case 16: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->IntrMirrCmdDrvrSide_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->IntrMirrCmdDrvrSide_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 16*/
      } /* end case */
      /* Setting member variable vcast_param->IntrMirrCmdIntrMirrWindHeatrCmpMag_CEM_LIN1 */
      case 17: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->IntrMirrCmdIntrMirrWindHeatrCmpMag_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->IntrMirrCmdIntrMirrWindHeatrCmpMag_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 17*/
      } /* end case */
      /* Setting member variable vcast_param->IntrMirrCmdIntrMirrEna_CEM_LIN1 */
      case 18: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->IntrMirrCmdIntrMirrEna_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->IntrMirrCmdIntrMirrEna_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 18*/
      } /* end case */
      /* Setting member variable vcast_param->IntrMirrCmdIntrMirrInhbDim_CEM_LIN1 */
      case 19: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->IntrMirrCmdIntrMirrInhbDim_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->IntrMirrCmdIntrMirrInhbDim_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 19*/
      } /* end case */
      /* Setting member variable vcast_param->IntrMirrCmdIntrMirrDiagcRst_CEM_LIN1 */
      case 20: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->IntrMirrCmdIntrMirrDiagcRst_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->IntrMirrCmdIntrMirrDiagcRst_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 20*/
      } /* end case */
      /* Setting member variable vcast_param->IntrMirrCmdIntrMirrAsyFanCmpMag_CEM_LIN1 */
      case 21: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->IntrMirrCmdIntrMirrAsyFanCmpMag_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->IntrMirrCmdIntrMirrAsyFanCmpMag_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 21*/
      } /* end case */
      /* Setting member variable vcast_param->WiprMotFrntOffsAg_CEM_LIN1 */
      case 22: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->WiprMotFrntOffsAg_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 4, vCAST_false );
        vcast_param->WiprMotFrntOffsAg_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 22*/
      } /* end case */
      /* Setting member variable vcast_param->unused2 */
      case 23: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->unused2;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 4, vCAST_false );
        vcast_param->unused2 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 23*/
      } /* end case */
      default:
        vCAST_TOOL_ERROR = vCAST_true;
    } /* end switch */ 
  }
} /* end VCAST_TI_9_25 */
/* A typedef */
void VCAST_TI_9_21 ( RS_Bit_Feld *vcast_param ) 
{
  {
    switch ( vcast_get_param () ) { /* Choose field member */
      /* Setting member variable vcast_param->B7 */
      case 1: { 
        long VCAST_TI_9_22_ti_bitfield_placeholder = (long) vcast_param->B7;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_22_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->B7 = ( unsigned  ) VCAST_TI_9_22_ti_bitfield_placeholder;
        break; /* end case 1*/
      } /* end case */
      /* Setting member variable vcast_param->B6 */
      case 2: { 
        long VCAST_TI_9_22_ti_bitfield_placeholder = (long) vcast_param->B6;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_22_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->B6 = ( unsigned  ) VCAST_TI_9_22_ti_bitfield_placeholder;
        break; /* end case 2*/
      } /* end case */
      /* Setting member variable vcast_param->B5 */
      case 3: { 
        long VCAST_TI_9_22_ti_bitfield_placeholder = (long) vcast_param->B5;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_22_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->B5 = ( unsigned  ) VCAST_TI_9_22_ti_bitfield_placeholder;
        break; /* end case 3*/
      } /* end case */
      /* Setting member variable vcast_param->B4 */
      case 4: { 
        long VCAST_TI_9_22_ti_bitfield_placeholder = (long) vcast_param->B4;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_22_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->B4 = ( unsigned  ) VCAST_TI_9_22_ti_bitfield_placeholder;
        break; /* end case 4*/
      } /* end case */
      /* Setting member variable vcast_param->B3 */
      case 5: { 
        long VCAST_TI_9_22_ti_bitfield_placeholder = (long) vcast_param->B3;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_22_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->B3 = ( unsigned  ) VCAST_TI_9_22_ti_bitfield_placeholder;
        break; /* end case 5*/
      } /* end case */
      /* Setting member variable vcast_param->B2 */
      case 6: { 
        long VCAST_TI_9_22_ti_bitfield_placeholder = (long) vcast_param->B2;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_22_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->B2 = ( unsigned  ) VCAST_TI_9_22_ti_bitfield_placeholder;
        break; /* end case 6*/
      } /* end case */
      /* Setting member variable vcast_param->B1 */
      case 7: { 
        long VCAST_TI_9_22_ti_bitfield_placeholder = (long) vcast_param->B1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_22_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->B1 = ( unsigned  ) VCAST_TI_9_22_ti_bitfield_placeholder;
        break; /* end case 7*/
      } /* end case */
      /* Setting member variable vcast_param->B0 */
      case 8: { 
        long VCAST_TI_9_22_ti_bitfield_placeholder = (long) vcast_param->B0;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_22_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->B0 = ( unsigned  ) VCAST_TI_9_22_ti_bitfield_placeholder;
        break; /* end case 8*/
      } /* end case */
      default:
        vCAST_TOOL_ERROR = vCAST_true;
    } /* end switch */ 
  }
} /* end VCAST_TI_9_21 */
/* A typedef */
void VCAST_TI_9_38 ( ASIC_ALI_Meas_t *vcast_param ) 
{
  {
    switch ( vcast_get_param () ) { /* Choose field member */
      /* Setting member variable vcast_param->ad */
      case 1: { 
        VCAST_TI_9_22 ( ((unsigned *)(&(vcast_param->ad))));
        break; /* end case 1*/
      } /* end case */
      /* Setting member variable vcast_param->avg */
      case 2: { 
        VCAST_TI_9_22 ( ((unsigned *)(&(vcast_param->avg))));
        break; /* end case 2*/
      } /* end case */
      default:
        vCAST_TOOL_ERROR = vCAST_true;
    } /* end switch */ 
  }
} /* end VCAST_TI_9_38 */
/* An array */
void VCAST_TI_9_63 ( unsigned char vcast_param[12] ) 
{
  {
    int VCAST_TI_9_63_array_index = 0;
    int VCAST_TI_9_63_index = 0;
    int VCAST_TI_9_63_first, VCAST_TI_9_63_last;
    int VCAST_TI_9_63_more_data; /* true if there is more data in the current command */
    int VCAST_TI_9_63_local_field = 0;
    int VCAST_TI_9_63_value_printed = 0;
    int VCAST_TI_9_63_is_string = (VCAST_FIND_INDEX()==-1);
    vcast_get_range_value (&VCAST_TI_9_63_first, &VCAST_TI_9_63_last, &VCAST_TI_9_63_more_data);
    VCAST_TI_9_63_local_field = vCAST_DATA_FIELD;
    if ( vCAST_SIZE && (!VCAST_TI_9_63_more_data)) { /* get the size of the array */
      vectorcast_fprint_integer (vCAST_OUTPUT_FILE,12);
      vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
      vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n");
    } else {
      int VCAST_TI_9_63_upper = 12;
      for (VCAST_TI_9_63_array_index=0; VCAST_TI_9_63_array_index< VCAST_TI_9_63_upper; VCAST_TI_9_63_array_index++){
        if ( (VCAST_TI_9_63_index >= VCAST_TI_9_63_first) && ( VCAST_TI_9_63_index <= VCAST_TI_9_63_last)){
          if ( VCAST_TI_9_63_is_string )
            VCAST_TI_STRING ( (char**)&vcast_param, sizeof ( vcast_param ), 1,VCAST_TI_9_63_upper);
          else
            VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param[VCAST_TI_9_63_index]))));
          VCAST_TI_9_63_value_printed = 1;
          vCAST_DATA_FIELD = VCAST_TI_9_63_local_field;
        } /* if */
        if (VCAST_TI_9_63_index >= VCAST_TI_9_63_last)
          break;
        VCAST_TI_9_63_index++;
      } /* loop */
      if ((vCAST_COMMAND == vCAST_PRINT)&&(!VCAST_TI_9_63_value_printed))
        vectorcast_fprint_string(vCAST_OUTPUT_FILE,"<<past end of array>>\n");
    } /* if */
  }
} /* end VCAST_TI_9_63 */
/* An array */
void VCAST_TI_9_64 ( unsigned char vcast_param[2] ) 
{
  {
    int VCAST_TI_9_64_array_index = 0;
    int VCAST_TI_9_64_index = 0;
    int VCAST_TI_9_64_first, VCAST_TI_9_64_last;
    int VCAST_TI_9_64_more_data; /* true if there is more data in the current command */
    int VCAST_TI_9_64_local_field = 0;
    int VCAST_TI_9_64_value_printed = 0;
    int VCAST_TI_9_64_is_string = (VCAST_FIND_INDEX()==-1);
    vcast_get_range_value (&VCAST_TI_9_64_first, &VCAST_TI_9_64_last, &VCAST_TI_9_64_more_data);
    VCAST_TI_9_64_local_field = vCAST_DATA_FIELD;
    if ( vCAST_SIZE && (!VCAST_TI_9_64_more_data)) { /* get the size of the array */
      vectorcast_fprint_integer (vCAST_OUTPUT_FILE,2);
      vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
      vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n");
    } else {
      int VCAST_TI_9_64_upper = 2;
      for (VCAST_TI_9_64_array_index=0; VCAST_TI_9_64_array_index< VCAST_TI_9_64_upper; VCAST_TI_9_64_array_index++){
        if ( (VCAST_TI_9_64_index >= VCAST_TI_9_64_first) && ( VCAST_TI_9_64_index <= VCAST_TI_9_64_last)){
          if ( VCAST_TI_9_64_is_string )
            VCAST_TI_STRING ( (char**)&vcast_param, sizeof ( vcast_param ), 1,VCAST_TI_9_64_upper);
          else
            VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param[VCAST_TI_9_64_index]))));
          VCAST_TI_9_64_value_printed = 1;
          vCAST_DATA_FIELD = VCAST_TI_9_64_local_field;
        } /* if */
        if (VCAST_TI_9_64_index >= VCAST_TI_9_64_last)
          break;
        VCAST_TI_9_64_index++;
      } /* loop */
      if ((vCAST_COMMAND == vCAST_PRINT)&&(!VCAST_TI_9_64_value_printed))
        vectorcast_fprint_string(vCAST_OUTPUT_FILE,"<<past end of array>>\n");
    } /* if */
  }
} /* end VCAST_TI_9_64 */
/* An array */
void VCAST_TI_9_65 ( unsigned char vcast_param[3] ) 
{
  {
    int VCAST_TI_9_65_array_index = 0;
    int VCAST_TI_9_65_index = 0;
    int VCAST_TI_9_65_first, VCAST_TI_9_65_last;
    int VCAST_TI_9_65_more_data; /* true if there is more data in the current command */
    int VCAST_TI_9_65_local_field = 0;
    int VCAST_TI_9_65_value_printed = 0;
    int VCAST_TI_9_65_is_string = (VCAST_FIND_INDEX()==-1);
    vcast_get_range_value (&VCAST_TI_9_65_first, &VCAST_TI_9_65_last, &VCAST_TI_9_65_more_data);
    VCAST_TI_9_65_local_field = vCAST_DATA_FIELD;
    if ( vCAST_SIZE && (!VCAST_TI_9_65_more_data)) { /* get the size of the array */
      vectorcast_fprint_integer (vCAST_OUTPUT_FILE,3);
      vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
      vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n");
    } else {
      int VCAST_TI_9_65_upper = 3;
      for (VCAST_TI_9_65_array_index=0; VCAST_TI_9_65_array_index< VCAST_TI_9_65_upper; VCAST_TI_9_65_array_index++){
        if ( (VCAST_TI_9_65_index >= VCAST_TI_9_65_first) && ( VCAST_TI_9_65_index <= VCAST_TI_9_65_last)){
          if ( VCAST_TI_9_65_is_string )
            VCAST_TI_STRING ( (char**)&vcast_param, sizeof ( vcast_param ), 1,VCAST_TI_9_65_upper);
          else
            VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param[VCAST_TI_9_65_index]))));
          VCAST_TI_9_65_value_printed = 1;
          vCAST_DATA_FIELD = VCAST_TI_9_65_local_field;
        } /* if */
        if (VCAST_TI_9_65_index >= VCAST_TI_9_65_last)
          break;
        VCAST_TI_9_65_index++;
      } /* loop */
      if ((vCAST_COMMAND == vCAST_PRINT)&&(!VCAST_TI_9_65_value_printed))
        vectorcast_fprint_string(vCAST_OUTPUT_FILE,"<<past end of array>>\n");
    } /* if */
  }
} /* end VCAST_TI_9_65 */
/* An array */
void VCAST_TI_9_72 ( s_rb_PrametersStruct_g vcast_param[4] ) 
{
  {
    int VCAST_TI_9_72_array_index = 0;
    int VCAST_TI_9_72_index = 0;
    int VCAST_TI_9_72_first, VCAST_TI_9_72_last;
    int VCAST_TI_9_72_more_data; /* true if there is more data in the current command */
    int VCAST_TI_9_72_local_field = 0;
    int VCAST_TI_9_72_value_printed = 0;
    vcast_get_range_value (&VCAST_TI_9_72_first, &VCAST_TI_9_72_last, &VCAST_TI_9_72_more_data);
    VCAST_TI_9_72_local_field = vCAST_DATA_FIELD;
    if ( vCAST_SIZE && (!VCAST_TI_9_72_more_data)) { /* get the size of the array */
      vectorcast_fprint_integer (vCAST_OUTPUT_FILE,4);
      vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
      vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n");
    } else {
      int VCAST_TI_9_72_upper = 4;
      for (VCAST_TI_9_72_array_index=0; VCAST_TI_9_72_array_index< VCAST_TI_9_72_upper; VCAST_TI_9_72_array_index++){
        if ( (VCAST_TI_9_72_index >= VCAST_TI_9_72_first) && ( VCAST_TI_9_72_index <= VCAST_TI_9_72_last)){
          VCAST_TI_9_70 ( ((s_rb_PrametersStruct_g *)(&(vcast_param[VCAST_TI_9_72_index]))));
          VCAST_TI_9_72_value_printed = 1;
          vCAST_DATA_FIELD = VCAST_TI_9_72_local_field;
        } /* if */
        if (VCAST_TI_9_72_index >= VCAST_TI_9_72_last)
          break;
        VCAST_TI_9_72_index++;
      } /* loop */
      if ((vCAST_COMMAND == vCAST_PRINT)&&(!VCAST_TI_9_72_value_printed))
        vectorcast_fprint_string(vCAST_OUTPUT_FILE,"<<past end of array>>\n");
    } /* if */
  }
} /* end VCAST_TI_9_72 */
/* An array */
void VCAST_TI_9_74 ( unsigned char vcast_param[9] ) 
{
  {
    int VCAST_TI_9_74_array_index = 0;
    int VCAST_TI_9_74_index = 0;
    int VCAST_TI_9_74_first, VCAST_TI_9_74_last;
    int VCAST_TI_9_74_more_data; /* true if there is more data in the current command */
    int VCAST_TI_9_74_local_field = 0;
    int VCAST_TI_9_74_value_printed = 0;
    int VCAST_TI_9_74_is_string = (VCAST_FIND_INDEX()==-1);
    vcast_get_range_value (&VCAST_TI_9_74_first, &VCAST_TI_9_74_last, &VCAST_TI_9_74_more_data);
    VCAST_TI_9_74_local_field = vCAST_DATA_FIELD;
    if ( vCAST_SIZE && (!VCAST_TI_9_74_more_data)) { /* get the size of the array */
      vectorcast_fprint_integer (vCAST_OUTPUT_FILE,9);
      vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
      vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n");
    } else {
      int VCAST_TI_9_74_upper = 9;
      for (VCAST_TI_9_74_array_index=0; VCAST_TI_9_74_array_index< VCAST_TI_9_74_upper; VCAST_TI_9_74_array_index++){
        if ( (VCAST_TI_9_74_index >= VCAST_TI_9_74_first) && ( VCAST_TI_9_74_index <= VCAST_TI_9_74_last)){
          if ( VCAST_TI_9_74_is_string )
            VCAST_TI_STRING ( (char**)&vcast_param, sizeof ( vcast_param ), 1,VCAST_TI_9_74_upper);
          else
            VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param[VCAST_TI_9_74_index]))));
          VCAST_TI_9_74_value_printed = 1;
          vCAST_DATA_FIELD = VCAST_TI_9_74_local_field;
        } /* if */
        if (VCAST_TI_9_74_index >= VCAST_TI_9_74_last)
          break;
        VCAST_TI_9_74_index++;
      } /* loop */
      if ((vCAST_COMMAND == vCAST_PRINT)&&(!VCAST_TI_9_74_value_printed))
        vectorcast_fprint_string(vCAST_OUTPUT_FILE,"<<past end of array>>\n");
    } /* if */
  }
} /* end VCAST_TI_9_74 */
/* An array */
void VCAST_TI_9_77 ( unsigned char vcast_param[33] ) 
{
  {
    int VCAST_TI_9_77_array_index = 0;
    int VCAST_TI_9_77_index = 0;
    int VCAST_TI_9_77_first, VCAST_TI_9_77_last;
    int VCAST_TI_9_77_more_data; /* true if there is more data in the current command */
    int VCAST_TI_9_77_local_field = 0;
    int VCAST_TI_9_77_value_printed = 0;
    int VCAST_TI_9_77_is_string = (VCAST_FIND_INDEX()==-1);
    vcast_get_range_value (&VCAST_TI_9_77_first, &VCAST_TI_9_77_last, &VCAST_TI_9_77_more_data);
    VCAST_TI_9_77_local_field = vCAST_DATA_FIELD;
    if ( vCAST_SIZE && (!VCAST_TI_9_77_more_data)) { /* get the size of the array */
      vectorcast_fprint_integer (vCAST_OUTPUT_FILE,33);
      vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
      vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n");
    } else {
      int VCAST_TI_9_77_upper = 33;
      for (VCAST_TI_9_77_array_index=0; VCAST_TI_9_77_array_index< VCAST_TI_9_77_upper; VCAST_TI_9_77_array_index++){
        if ( (VCAST_TI_9_77_index >= VCAST_TI_9_77_first) && ( VCAST_TI_9_77_index <= VCAST_TI_9_77_last)){
          if ( VCAST_TI_9_77_is_string )
            VCAST_TI_STRING ( (char**)&vcast_param, sizeof ( vcast_param ), 1,VCAST_TI_9_77_upper);
          else
            VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param[VCAST_TI_9_77_index]))));
          VCAST_TI_9_77_value_printed = 1;
          vCAST_DATA_FIELD = VCAST_TI_9_77_local_field;
        } /* if */
        if (VCAST_TI_9_77_index >= VCAST_TI_9_77_last)
          break;
        VCAST_TI_9_77_index++;
      } /* loop */
      if ((vCAST_COMMAND == vCAST_PRINT)&&(!VCAST_TI_9_77_value_printed))
        vectorcast_fprint_string(vCAST_OUTPUT_FILE,"<<past end of array>>\n");
    } /* if */
  }
} /* end VCAST_TI_9_77 */
/* A struct */
void VCAST_TI_9_9 ( struct _c_bits8 *vcast_param ) 
{
  {
    switch ( vcast_get_param () ) { /* Choose field member */
      /* Setting member variable vcast_param->b0 */
      case 1: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->b0;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->b0 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 1*/
      } /* end case */
      /* Setting member variable vcast_param->b1 */
      case 2: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->b1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->b1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 2*/
      } /* end case */
      /* Setting member variable vcast_param->b2 */
      case 3: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->b2;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->b2 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 3*/
      } /* end case */
      /* Setting member variable vcast_param->b3 */
      case 4: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->b3;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->b3 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 4*/
      } /* end case */
      /* Setting member variable vcast_param->b4 */
      case 5: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->b4;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->b4 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 5*/
      } /* end case */
      /* Setting member variable vcast_param->b5 */
      case 6: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->b5;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->b5 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 6*/
      } /* end case */
      /* Setting member variable vcast_param->b6 */
      case 7: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->b6;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->b6 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 7*/
      } /* end case */
      /* Setting member variable vcast_param->b7 */
      case 8: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->b7;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->b7 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 8*/
      } /* end case */
      default:
        vCAST_TOOL_ERROR = vCAST_true;
    } /* end switch */ 
  }
} /* end VCAST_TI_9_9 */
/* A struct */
void VCAST_TI_9_32 ( struct _c_bits16 *vcast_param ) 
{
  {
    switch ( vcast_get_param () ) { /* Choose field member */
      /* Setting member variable vcast_param->b0 */
      case 1: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->b0;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->b0 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 1*/
      } /* end case */
      /* Setting member variable vcast_param->b1 */
      case 2: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->b1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->b1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 2*/
      } /* end case */
      /* Setting member variable vcast_param->b2 */
      case 3: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->b2;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->b2 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 3*/
      } /* end case */
      /* Setting member variable vcast_param->b3 */
      case 4: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->b3;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->b3 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 4*/
      } /* end case */
      /* Setting member variable vcast_param->b4 */
      case 5: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->b4;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->b4 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 5*/
      } /* end case */
      /* Setting member variable vcast_param->b5 */
      case 6: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->b5;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->b5 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 6*/
      } /* end case */
      /* Setting member variable vcast_param->b6 */
      case 7: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->b6;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->b6 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 7*/
      } /* end case */
      /* Setting member variable vcast_param->b7 */
      case 8: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->b7;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->b7 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 8*/
      } /* end case */
      /* Setting member variable vcast_param->b8 */
      case 9: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->b8;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->b8 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 9*/
      } /* end case */
      /* Setting member variable vcast_param->b9 */
      case 10: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->b9;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->b9 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 10*/
      } /* end case */
      /* Setting member variable vcast_param->b10 */
      case 11: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->b10;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->b10 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 11*/
      } /* end case */
      /* Setting member variable vcast_param->b11 */
      case 12: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->b11;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->b11 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 12*/
      } /* end case */
      /* Setting member variable vcast_param->b12 */
      case 13: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->b12;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->b12 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 13*/
      } /* end case */
      /* Setting member variable vcast_param->b13 */
      case 14: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->b13;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->b13 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 14*/
      } /* end case */
      /* Setting member variable vcast_param->b14 */
      case 15: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->b14;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->b14 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 15*/
      } /* end case */
      /* Setting member variable vcast_param->b15 */
      case 16: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->b15;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->b15 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 16*/
      } /* end case */
      default:
        vCAST_TOOL_ERROR = vCAST_true;
    } /* end switch */ 
  }
} /* end VCAST_TI_9_32 */
/* A typedef */
void VCAST_TI_9_70 ( s_rb_PrametersStruct_g *vcast_param ) 
{
  {
    switch ( vcast_get_param () ) { /* Choose field member */
      /* Setting member variable vcast_param->Stufe1_OG */
      case 1: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->Stufe1_OG))));
        break; /* end case 1*/
      } /* end case */
      /* Setting member variable vcast_param->Stufe1_UG */
      case 2: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->Stufe1_UG))));
        break; /* end case 2*/
      } /* end case */
      /* Setting member variable vcast_param->Ep_St2_Epr_In_St2 */
      case 3: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->Ep_St2_Epr_In_St2))));
        break; /* end case 3*/
      } /* end case */
      /* Setting member variable vcast_param->Schwelle_Schwall */
      case 4: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->Schwelle_Schwall))));
        break; /* end case 4*/
      } /* end case */
      /* Setting member variable vcast_param->CW_AnsamlungAdditOffset */
      case 5: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->CW_AnsamlungAdditOffset))));
        break; /* end case 5*/
      } /* end case */
      /* Setting member variable vcast_param->dec_Int_Sp_off */
      case 6: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->dec_Int_Sp_off))));
        break; /* end case 6*/
      } /* end case */
      /* Setting member variable vcast_param->Dec_Stx_Speicher */
      case 7: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->Dec_Stx_Speicher))));
        break; /* end case 7*/
      } /* end case */
      /* Setting member variable vcast_param->dec_Ovr_Speicher */
      case 8: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->dec_Ovr_Speicher))));
        break; /* end case 8*/
      } /* end case */
      /* Setting member variable vcast_param->Empf_Faktor_ST2_Offs */
      case 9: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->Empf_Faktor_ST2_Offs))));
        break; /* end case 9*/
      } /* end case */
      /* Setting member variable vcast_param->Max_Signallaenge */
      case 10: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->Max_Signallaenge))));
        break; /* end case 10*/
      } /* end case */
      /* Setting member variable vcast_param->rb_Stufe1_with_Int_og */
      case 11: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->rb_Stufe1_with_Int_og))));
        break; /* end case 11*/
      } /* end case */
      /* Setting member variable vcast_param->Nachwisch_4_ST1_min */
      case 12: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->Nachwisch_4_ST1_min))));
        break; /* end case 12*/
      } /* end case */
      /* Setting member variable vcast_param->Nachwisch_3 */
      case 13: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->Nachwisch_3))));
        break; /* end case 13*/
      } /* end case */
      /* Setting member variable vcast_param->Nachwisch_2 */
      case 14: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->Nachwisch_2))));
        break; /* end case 14*/
      } /* end case */
      /* Setting member variable vcast_param->RSEmpfFactorScaling */
      case 15: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->RSEmpfFactorScaling))));
        break; /* end case 15*/
      } /* end case */
      /* Setting member variable vcast_param->SchlierenFlag1 */
      case 16: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->SchlierenFlag1))));
        break; /* end case 16*/
      } /* end case */
      /* Setting member variable vcast_param->sig_ans_schw_offs */
      case 17: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->sig_ans_schw_offs))));
        break; /* end case 17*/
      } /* end case */
      default:
        vCAST_TOOL_ERROR = vCAST_true;
    } /* end switch */ 
  }
} /* end VCAST_TI_9_70 */
void VCAST_TI_RANGE_DATA_9 ( void ) {
  /* Range Data for TI (scalar) VCAST_TI_8_2 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, "NEW_SCALAR\n" );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"900003\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,(-32767-1) );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,((-32767-1) / 2) + (32767 / 2) );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,32767 );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n" );
  /* Range Data for TI (scalar) VCAST_TI_9_6 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, "NEW_SCALAR\n" );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"900006\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,0 );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,(0 / 2) + (0xff / 2) );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,0xff );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n" );
  /* Range Data for TI (array) VCAST_TI_9_8 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, "NEW_ARRAY\n" );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"100003\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,1);
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
  /* Range Data for TI (scalar) VCAST_TI_9_22 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, "NEW_SCALAR\n" );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"900022\n" );
  vectorcast_fprint_unsigned_integer (vCAST_OUTPUT_FILE,0 );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n" );
  vectorcast_fprint_unsigned_integer (vCAST_OUTPUT_FILE,(0 / 2) + (0xffffU / 2) );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n" );
  vectorcast_fprint_unsigned_integer (vCAST_OUTPUT_FILE,0xffffU );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n" );
  /* Range Data for TI (array) VCAST_TI_9_31 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, "NEW_ARRAY\n" );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"100005\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,(11 + 15) / 16);
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
  /* Range Data for TI (array) VCAST_TI_9_37 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, "NEW_ARRAY\n" );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"100006\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,9);
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
  /* Range Data for TI (scalar) VCAST_TI_9_39 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, "NEW_SCALAR\n" );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"900037\n" );
  vectorcast_fprint_unsigned_long (vCAST_OUTPUT_FILE,0 );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n" );
  vectorcast_fprint_unsigned_long (vCAST_OUTPUT_FILE,(0 / 2) + (0xffffffffUL / 2) );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n" );
  vectorcast_fprint_unsigned_long (vCAST_OUTPUT_FILE,0xffffffffUL );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n" );
  /* Range Data for TI (array) VCAST_TI_9_41 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, "NEW_ARRAY\n" );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"100007\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,4);
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
  /* Range Data for TI (array) VCAST_TI_9_43 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, "NEW_ARRAY\n" );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"100008\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,8);
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
  /* Range Data for TI (array) VCAST_TI_9_45 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, "NEW_ARRAY\n" );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"100009\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,7);
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
  /* Range Data for TI (array) VCAST_TI_9_43 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, "NEW_ARRAY\n" );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"100010\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,8);
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
  /* Range Data for TI (array) VCAST_TI_9_43 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, "NEW_ARRAY\n" );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"100011\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,8);
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
  /* Range Data for TI (array) VCAST_TI_9_43 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, "NEW_ARRAY\n" );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"100012\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,8);
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
  /* Range Data for TI (array) VCAST_TI_9_49 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, "NEW_ARRAY\n" );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"100013\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,10);
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
  /* Range Data for TI (array) VCAST_TI_9_50 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, "NEW_ARRAY\n" );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"100014\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,2);
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
  /* Range Data for TI (array) VCAST_TI_9_49 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, "NEW_ARRAY\n" );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"100015\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,10);
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
  /* Range Data for TI (array) VCAST_TI_9_49 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, "NEW_ARRAY\n" );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"100016\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,10);
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
  /* Range Data for TI (array) VCAST_TI_9_54 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, "NEW_ARRAY\n" );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"100017\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,5);
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
  /* Range Data for TI (array) VCAST_TI_9_41 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, "NEW_ARRAY\n" );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"100018\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,4);
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
  /* Range Data for TI (array) VCAST_TI_9_43 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, "NEW_ARRAY\n" );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"100019\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,8);
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
  /* Range Data for TI (array) VCAST_TI_9_63 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, "NEW_ARRAY\n" );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"100023\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,12);
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
  /* Range Data for TI (array) VCAST_TI_9_64 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, "NEW_ARRAY\n" );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"100024\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,2);
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
  /* Range Data for TI (array) VCAST_TI_9_65 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, "NEW_ARRAY\n" );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"100025\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,3);
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
  /* Range Data for TI (array) VCAST_TI_9_41 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, "NEW_ARRAY\n" );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"100026\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,4);
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
  /* Range Data for TI (array) VCAST_TI_9_68 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, "NEW_ARRAY\n" );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"100028\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,(93 + 4) + 10);
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
  /* Range Data for TI (array) VCAST_TI_9_72 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, "NEW_ARRAY\n" );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"100031\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,4);
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
  /* Range Data for TI (array) VCAST_TI_9_111 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, "NEW_ARRAY\n" );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"100032\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,6);
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
  /* Range Data for TI (array) VCAST_TI_9_74 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, "NEW_ARRAY\n" );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"100033\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,9);
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
  /* Range Data for TI (array) VCAST_TI_9_43 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, "NEW_ARRAY\n" );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"100034\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,8);
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
  /* Range Data for TI (array) VCAST_TI_9_41 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, "NEW_ARRAY\n" );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"100035\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,4);
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
  /* Range Data for TI (array) VCAST_TI_9_77 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, "NEW_ARRAY\n" );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"100036\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,33);
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
  /* Range Data for TI (array) VCAST_TI_9_79 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, "NEW_ARRAY\n" );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"100038\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,194);
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
  /* Range Data for TI (array) VCAST_TI_9_80 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, "NEW_ARRAY\n" );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"100039\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,1);
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
  /* Range Data for TI (array) VCAST_TI_9_81 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, "NEW_ARRAY\n" );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"100040\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,(11 + 7) / 8);
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
  /* Range Data for TI (array) VCAST_TI_9_80 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, "NEW_ARRAY\n" );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"100060\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,1);
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
  /* Range Data for TI (array) VCAST_TI_9_45 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, "NEW_ARRAY\n" );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"100062\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,7);
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
  /* Range Data for TI (array) VCAST_TI_9_45 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, "NEW_ARRAY\n" );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"100064\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,7);
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
  /* Range Data for TI (array) VCAST_TI_9_43 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, "NEW_ARRAY\n" );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"100066\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,8);
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
  /* Range Data for TI (array) VCAST_TI_9_45 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, "NEW_ARRAY\n" );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"100068\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,7);
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
  /* Range Data for TI (array) VCAST_TI_9_111 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, "NEW_ARRAY\n" );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"100070\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,6);
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
}
/* Include the file which contains function implementations
for stub processing and value/expected user code */
/*vcast_header_expansion_start:C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\1234\\G5_RLS_LIN_GEELY2DOT0_uc.c*/
void vCAST_VALUE_USER_CODE_9(int vcast_slot_index ) {
  {
  /* INSERT VALUE_USER_CODE_9 */
  }
}
void vCAST_EXPECTED_USER_CODE_9(int vcast_slot_index ) {
  {
  /* INSERT EXPECTED_USER_CODE_9 */
  }
}
void vCAST_EGLOBALS_USER_CODE_9(int vcast_slot_index ) {
  {
  /* INSERT EXPECTED_GLOBALS_USER_CODE_9 */
  }
}
void vCAST_STUB_PROCESSING_9(
        int  UnitIndex, 
        int  SubprogramIndex ) {
  vCAST_GLOBAL_STUB_PROCESSING();
  {
  /* INSERT STUB_VAL_USER_CODE_9 */
  }
}
void vCAST_BEGIN_STUB_PROC_9(
        int  UnitIndex, 
        int  SubprogramIndex ) {
  vCAST_GLOBAL_BEGINNING_OF_STUB_PROCESSING();
  {
  /* INSERT STUB_EXP_USER_CODE_9 */
  }
}
void VCAST_USER_CODE_UNIT_9( VCAST_USER_CODE_TYPE uct, int vcast_slot_index ) {
  switch( uct ) {
    case VCAST_UCT_VALUE:
      vCAST_VALUE_USER_CODE_9(vcast_slot_index);
      break;
    case VCAST_UCT_EXPECTED:
      vCAST_EXPECTED_USER_CODE_9(vcast_slot_index);
      break;
    case VCAST_UCT_EXPECTED_GLOBALS:
      vCAST_EGLOBALS_USER_CODE_9(vcast_slot_index);
      break;
  } /* switch( uct ) */
}
/*vcast_header_expansion_end*/
void vCAST_COMMON_STUB_PROC_9(
            int unitIndex,
            int subprogramIndex,
            int robjectIndex,
            int readEobjectData )
{
   vCAST_BEGIN_STUB_PROC_9(unitIndex, subprogramIndex);
   if ( robjectIndex )
      vCAST_READ_COMMAND_DATA_FOR_ONE_PARAM( unitIndex, subprogramIndex, robjectIndex );
   if ( readEobjectData )
      vCAST_READ_COMMAND_DATA_FOR_ONE_PARAM( unitIndex, subprogramIndex, 0 );
   vCAST_SET_HISTORY( unitIndex, subprogramIndex );
   vCAST_READ_COMMAND_DATA( vCAST_CURRENT_SLOT, unitIndex, subprogramIndex, vCAST_true, vCAST_false );
   vCAST_READ_COMMAND_DATA_FOR_USER_GLOBALS();
   vCAST_STUB_PROCESSING_9(unitIndex, subprogramIndex);
}
/*vcast_separate_expansion_end*/
