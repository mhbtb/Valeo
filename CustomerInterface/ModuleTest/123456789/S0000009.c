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
 * Path: C:/Users/zhu1/Downloads/SW_Need_Change_Managemant/GEEA2.0/E4-2_SW/RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03/05_SwDev/01_SrcCode/Application/CustomerInterface/G5_RLS_LIN_GEELY2DOT0.c
 *
 * Type: uut
 *
 * Unit Number: 9
 *
 ***********************************************/
#ifndef VCAST_DRIVER_ONLY
/* Include the file which contains function prototypes
for stub processing and value/expected user code */
#include "vcast_uc_prototypes.h"
#include "vcast_basics.h"
/* STUB_DEPENDENCY_USER_CODE */
/* STUB_DEPENDENCY_USER_CODE_END */
#else
#include "vcast_env_defines.h"
#define __VCAST_BASICS_H__
#endif /* VCAST_DRIVER_ONLY */
#ifndef VCAST_DRIVER_ONLY
#ifndef VCAST_DONT_RENAME_EXIT
#ifdef __cplusplus
extern "C" {
#endif
void exit (int status);
#ifdef __cplusplus
}
#endif
/* used to capture the exit call */
#define exit VCAST_exit
#endif /* VCAST_DONT_RENAME_EXIT */
#endif /* VCAST_DRIVER_ONLY */
#ifndef VCAST_DRIVER_ONLY
#define VCAST_HEADER_EXPANSION
#ifdef VCAST_COVERAGE
#include "G5_RLS_LIN_GEELY2DOT0_inst_prefix.c"
#else
#include "G5_RLS_LIN_GEELY2DOT0_vcast_prefix.c"
#endif
#ifdef VCAST_COVERAGE
/* If coverage is enabled, include the instrumented UUT */
#include "G5_RLS_LIN_GEELY2DOT0_inst.c"
#else
/* If coverage is not enabled, include the original UUT */
#include "G5_RLS_LIN_GEELY2DOT0_vcast.c"
#endif
#ifdef VCAST_COVERAGE
#include "G5_RLS_LIN_GEELY2DOT0_inst_appendix.c"
#else
#include "G5_RLS_LIN_GEELY2DOT0_vcast_appendix.c"
#endif
#endif /* VCAST_DRIVER_ONLY */
#include "G5_RLS_LIN_GEELY2DOT0_driver_prefix.c"
#ifdef VCAST_HEADER_EXPANSION
#ifdef VCAST_COVERAGE
#include "G5_RLS_LIN_GEELY2DOT0_exp_inst_driver.c"
#else
#include "G5_RLS_LIN_GEELY2DOT0_expanded_driver.c"
#endif /*VCAST_COVERAGE*/
#else
#include "S0000009.h"
#include "vcast_undef_9.h"
/* Include the file which contains function prototypes
for stub processing and value/expected user code */
#include "vcast_uc_prototypes.h"
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
/* Begin Function Set_BCMLightOffset */
unsigned char P_9_28_1

;
/* Begin Function IsByteOddParity */
unsigned char P_9_33_1

;
unsigned char R_9_33;
#include "vcast_stubs_9.c"
/* begin declarations of inlined friends */
/* end declarations of inlined friends */
void VCAST_DRIVER_9( int VC_SUBPROGRAM, char *VC_EVENT_FLAGS, char *VC_SLOT_DESCR ) {
#ifdef VCAST_SBF_UNITS_AVAILABLE
  vCAST_MODIFY_SBF_TABLE(9, VC_SUBPROGRAM, vCAST_false);
#endif
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
      /* byte GetUpdateTimeForLightStatus(void) */
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
      /* byte CRC8SAEJ1850(const byte * u8_data, byte u8_len) */
      vCAST_SET_HISTORY_FLAGS ( 9, 24, VC_EVENT_FLAGS, VC_SLOT_DESCR );
      R_9_24 = 
      ( CRC8SAEJ1850(
        ( ((const unsigned char *)(P_9_24_1)) ),
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
      /* void Set_BCMLightOffset(byte offset) */
      vCAST_SET_HISTORY_FLAGS ( 9, 28, VC_EVENT_FLAGS, VC_SLOT_DESCR );
      ( Set_BCMLightOffset(
        ( P_9_28_1 ) ) );
      break; }
    case 29: {
      /* void SendRLSSerNo(void) */
      vCAST_SET_HISTORY_FLAGS ( 9, 29, VC_EVENT_FLAGS, VC_SLOT_DESCR );
      ( SendRLSSerNo( ) );
      break; }
    case 30: {
      /* void SendRLSMPartNo(void) */
      vCAST_SET_HISTORY_FLAGS ( 9, 30, VC_EVENT_FLAGS, VC_SLOT_DESCR );
      ( SendRLSMPartNo( ) );
      break; }
    case 31: {
      /* void SendRLSMPartNo10(void) */
      vCAST_SET_HISTORY_FLAGS ( 9, 31, VC_EVENT_FLAGS, VC_SLOT_DESCR );
      ( SendRLSMPartNo10( ) );
      break; }
    case 32: {
      /* void WipeWinterModeCheck(void) */
      vCAST_SET_HISTORY_FLAGS ( 9, 32, VC_EVENT_FLAGS, VC_SLOT_DESCR );
      ( WipeWinterModeCheck( ) );
      break; }
    case 33: {
      /* byte IsByteOddParity(byte data) */
      vCAST_SET_HISTORY_FLAGS ( 9, 33, VC_EVENT_FLAGS, VC_SLOT_DESCR );
      R_9_33 = 
      ( IsByteOddParity(
        ( P_9_33_1 ) ) );
      break; }
    case 34: {
      /* void Rain_sensitivity(void) */
      vCAST_SET_HISTORY_FLAGS ( 9, 34, VC_EVENT_FLAGS, VC_SLOT_DESCR );
      ( Rain_sensitivity( ) );
      break; }
    case 35: {
      /* void Get_Lin_Signal_From_GetLeWWS(void) */
      vCAST_SET_HISTORY_FLAGS ( 9, 35, VC_EVENT_FLAGS, VC_SLOT_DESCR );
      ( Get_Lin_Signal_From_GetLeWWS( ) );
      break; }
    case 36: {
      /* void Light_Sensitivity_In_GetLeWWS(void) */
      vCAST_SET_HISTORY_FLAGS ( 9, 36, VC_EVENT_FLAGS, VC_SLOT_DESCR );
      ( Light_Sensitivity_In_GetLeWWS( ) );
      break; }
    case 37: {
      /* void Wiper_and_Park(void) */
      vCAST_SET_HISTORY_FLAGS ( 9, 37, VC_EVENT_FLAGS, VC_SLOT_DESCR );
      ( Wiper_and_Park( ) );
      break; }
    case 38: {
      /* void Tunnel_Wipe_Decision(void) */
      vCAST_SET_HISTORY_FLAGS ( 9, 38, VC_EVENT_FLAGS, VC_SLOT_DESCR );
      ( Tunnel_Wipe_Decision( ) );
      break; }
    case 39: {
      /* void Exit_Wipe(void) */
      vCAST_SET_HISTORY_FLAGS ( 9, 39, VC_EVENT_FLAGS, VC_SLOT_DESCR );
      ( Exit_Wipe( ) );
      break; }
    case 40: {
      /* void Rain_Sensitivity_Judge(void) */
      vCAST_SET_HISTORY_FLAGS ( 9, 40, VC_EVENT_FLAGS, VC_SLOT_DESCR );
      ( Rain_Sensitivity_Judge( ) );
      break; }
    case 41: {
      /* void Standby_Judge(void) */
      vCAST_SET_HISTORY_FLAGS ( 9, 41, VC_EVENT_FLAGS, VC_SLOT_DESCR );
      ( Standby_Judge( ) );
      break; }
    case 42: {
      /* void OutdBriCntr_Counter(void) */
      vCAST_SET_HISTORY_FLAGS ( 9, 42, VC_EVENT_FLAGS, VC_SLOT_DESCR );
      ( OutdBriCntr_Counter( ) );
      break; }
    default:
      vectorcast_print_string("ERROR: Internal Tool Error\n");
      break;
  } /* switch */
}

#include "vcast_ti_decls_9.h"
void VCAST_RUN_DATA_IF_9( int VCAST_SUB_INDEX, int VCAST_PARAM_INDEX ) {
  switch ( VCAST_SUB_INDEX ) {
    case 0: /* for global objects */
      switch( VCAST_PARAM_INDEX ) {
        case 35: /* for global object EEPROM_Struct_PD */
          VCAST_TI_9_13 ( ((s_rb_EEPROMStructPD_buff_g *)(&(EEPROM_Struct_PD))));
          break;
        case 36: /* for global object rb_Humidity_raw_g */
          VCAST_TI_9_9 ( ((unsigned char *)(&(rb_Humidity_raw_g))));
          break;
        case 37: /* for global object rb_Humidity_g */
          VCAST_TI_9_9 ( ((unsigned char *)(&(rb_Humidity_g))));
          break;
        case 38: /* for global object rw_Temperature_raw_g */
          VCAST_TI_9_6 ( ((unsigned *)(&(rw_Temperature_raw_g))));
          break;
        case 39: /* for global object rw_DewPoint_g */
          VCAST_TI_9_6 ( ((unsigned *)(&(rw_DewPoint_g))));
          break;
        case 40: /* for global object rbi_HumTempComError_g */
          VCAST_TI_9_9 ( ((unsigned char *)(&(rbi_HumTempComError_g))));
          break;
        case 41: /* for global object EEPROM_Struct_AD */
          VCAST_TI_9_17 ( ((s_rb_EEPROMStructAD_buff_g *)(&(EEPROM_Struct_AD))));
          break;
        case 42: /* for global object rb_WDG_BusTaskCounter_g */
          VCAST_TI_9_9 ( ((unsigned char *)(&(rb_WDG_BusTaskCounter_g))));
          break;
        case 43: /* for global object uLinIndicationFlags */
          VCAST_TI_9_3 ( ((union tLinIndicationBits *)(&(uLinIndicationFlags))));
          break;
        case 44: /* for global object uLinConfirmationFlags */
          VCAST_TI_9_21 ( ((union tLinConfirmationBits *)(&(uLinConfirmationFlags))));
          break;
        case 45: /* for global object rb_WakeupCounter_mg */
          VCAST_TI_9_9 ( ((unsigned char *)(&(rb_WakeupCounter_mg))));
          break;
        case 1: /* for global object uF_SCIFlags_mg */
          VCAST_TI_9_7 ( ((volatile Flag *)(&(uF_SCIFlags_mg))));
          break;
        case 2: /* for global object rb_LIN_BIT_ERROR_COUNTER_g */
          VCAST_TI_9_9 ( ((unsigned char *)(&(rb_LIN_BIT_ERROR_COUNTER_g))));
          break;
        case 3: /* for global object rb_LIN_OVERTHEADERMAX_COUNTER_g */
          VCAST_TI_9_9 ( ((unsigned char *)(&(rb_LIN_OVERTHEADERMAX_COUNTER_g))));
          break;
        case 4: /* for global object rb_LIN_CHECKSUMERROR_COUNTER_g */
          VCAST_TI_9_9 ( ((unsigned char *)(&(rb_LIN_CHECKSUMERROR_COUNTER_g))));
          break;
        case 5: /* for global object rb_LIN_OVERTFRAMEMAX_COUNTER_g */
          VCAST_TI_9_9 ( ((unsigned char *)(&(rb_LIN_OVERTFRAMEMAX_COUNTER_g))));
          break;
        case 6: /* for global object rb_LIN_NORESPONSE_COUNTER_g */
          VCAST_TI_9_9 ( ((unsigned char *)(&(rb_LIN_NORESPONSE_COUNTER_g))));
          break;
        case 7: /* for global object rb_LIN_FRAMINGERROR_COUNTER_g */
          VCAST_TI_9_9 ( ((unsigned char *)(&(rb_LIN_FRAMINGERROR_COUNTER_g))));
          break;
        case 8: /* for global object uF_Communication_mg */
          VCAST_TI_9_10 ( ((Flag *)(&(uF_Communication_mg))));
          break;
        case 9: /* for global object uF_Butterfly_Flags_g */
          VCAST_TI_9_7 ( ((volatile Flag *)(&(uF_Butterfly_Flags_g))));
          break;
        case 10: /* for global object rb_LastLINErrorCode_g */
          VCAST_TI_9_9 ( ((unsigned char *)(&(rb_LastLINErrorCode_g))));
          break;
        case 11: /* for global object rw_NoCommunicationCounter_g */
          VCAST_TI_9_6 ( ((unsigned *)(&(rw_NoCommunicationCounter_g))));
          break;
        case 12: /* for global object rb_intervaltime_rainSensorOff_g */
          VCAST_TI_9_9 ( ((unsigned char *)(&(rb_intervaltime_rainSensorOff_g))));
          break;
        case 13: /* for global object rb_Release_IntervalMarker_Update_g */
          VCAST_TI_9_9 ( ((unsigned char *)(&(rb_Release_IntervalMarker_Update_g))));
          break;
        case 46: /* for global object RlsmCem_SerNrLin1Fr01_CEM_LIN1 */
          VCAST_TI_9_32 ( ((_c_RlsmCem_SerNrLin1Fr01_CEM_LIN1_buf *)(&(RlsmCem_SerNrLin1Fr01_CEM_LIN1))));
          break;
        case 47: /* for global object RlsmCem_Lin1PartNrFr02_CEM_LIN1 */
          VCAST_TI_9_34 ( ((_c_RlsmCem_Lin1PartNrFr02_CEM_LIN1_buf *)(&(RlsmCem_Lin1PartNrFr02_CEM_LIN1))));
          break;
        case 48: /* for global object RlsmCem_Lin1PartNrFr01_CEM_LIN1 */
          VCAST_TI_9_36 ( ((_c_RlsmCem_Lin1PartNrFr01_CEM_LIN1_buf *)(&(RlsmCem_Lin1PartNrFr01_CEM_LIN1))));
          break;
        case 49: /* for global object RlsmCem_Lin1Fr03_CEM_LIN1 */
          VCAST_TI_9_25 ( ((_c_RlsmCem_Lin1Fr03_CEM_LIN1_buf *)(&(RlsmCem_Lin1Fr03_CEM_LIN1))));
          break;
        case 50: /* for global object RlsmCem_Lin1Fr02_CEM_LIN1 */
          VCAST_TI_9_27 ( ((_c_RlsmCem_Lin1Fr02_CEM_LIN1_buf *)(&(RlsmCem_Lin1Fr02_CEM_LIN1))));
          break;
        case 51: /* for global object RlsmCem_Lin1Fr01_CEM_LIN1 */
          VCAST_TI_9_23 ( ((_c_RlsmCem_Lin1Fr01_CEM_LIN1_buf *)(&(RlsmCem_Lin1Fr01_CEM_LIN1))));
          break;
        case 52: /* for global object CemCem_Lin1Fr06_CEM_LIN1 */
          VCAST_TI_9_55 ( ((_c_CemCem_Lin1Fr06_CEM_LIN1_buf *)(&(CemCem_Lin1Fr06_CEM_LIN1))));
          break;
        case 53: /* for global object CemCem_Lin1Fr05_CEM_LIN1 */
          VCAST_TI_9_19 ( ((_c_CemCem_Lin1Fr05_CEM_LIN1_buf *)(&(CemCem_Lin1Fr05_CEM_LIN1))));
          break;
        case 54: /* for global object CemCem_Lin1Fr04_CEM_LIN1 */
          VCAST_TI_9_53 ( ((_c_CemCem_Lin1Fr04_CEM_LIN1_buf *)(&(CemCem_Lin1Fr04_CEM_LIN1))));
          break;
        case 55: /* for global object CemCem_Lin1Fr03_CEM_LIN1 */
          VCAST_TI_9_48 ( ((_c_CemCem_Lin1Fr03_CEM_LIN1_buf *)(&(CemCem_Lin1Fr03_CEM_LIN1))));
          break;
        case 56: /* for global object CemCem_Lin1Fr02_CEM_LIN1 */
          VCAST_TI_9_51 ( ((_c_CemCem_Lin1Fr02_CEM_LIN1_buf *)(&(CemCem_Lin1Fr02_CEM_LIN1))));
          break;
        case 57: /* for global object CemCem_Lin1Fr01_CEM_LIN1 */
          VCAST_TI_9_11 ( ((_c_CemCem_Lin1Fr01_CEM_LIN1_buf *)(&(CemCem_Lin1Fr01_CEM_LIN1))));
          break;
        case 58: /* for global object uF_VoltageStatus_g */
          VCAST_TI_9_7 ( ((volatile Flag *)(&(uF_VoltageStatus_g))));
          break;
        case 59: /* for global object rb_InternalTemperature_g */
          VCAST_TI_9_9 ( ((unsigned char *)(&(rb_InternalTemperature_g))));
          break;
        case 60: /* for global object rb_ClockFreq_Error_cnt_g */
          VCAST_TI_9_9 ( ((unsigned char *)(&(rb_ClockFreq_Error_cnt_g))));
          break;
        case 61: /* for global object uF_uC_Error_g */
          VCAST_TI_9_10 ( ((Flag *)(&(uF_uC_Error_g))));
          break;
        case 62: /* for global object uF_Diagnose_pre_Flag */
          VCAST_TI_9_10 ( ((Flag *)(&(uF_Diagnose_pre_Flag))));
          break;
        case 63: /* for global object rub_RSIntermDelayInit */
          VCAST_TI_9_9 ( ((unsigned char *)(&(rub_RSIntermDelayInit))));
          break;
        case 64: /* for global object rb_LimitMemomryNoWiperReaction_g */
          VCAST_TI_9_9 ( ((unsigned char *)(&(rb_LimitMemomryNoWiperReaction_g))));
          break;
        case 65: /* for global object rbi_WiperStarted_g */
          VCAST_TI_9_9 ( ((unsigned char *)(&(rbi_WiperStarted_g))));
          break;
        case 66: /* for global object rb_LIN_SensitivityShift_g */
          VCAST_TI_9_9 ( ((unsigned char *)(&(rb_LIN_SensitivityShift_g))));
          break;
        case 67: /* for global object RSStatus */
          VCAST_TI_9_15 ( ((volatile RS_Flag *)(&(RSStatus))));
          break;
        case 68: /* for global object rub_IntermDelayTime */
          VCAST_TI_9_9 ( ((unsigned char *)(&(rub_IntermDelayTime))));
          break;
        case 69: /* for global object rb_PotiStageFromBox_g */
          VCAST_TI_9_9 ( ((unsigned char *)(&(rb_PotiStageFromBox_g))));
          break;
        case 70: /* for global object uF_StatusRainsensor_mg */
          VCAST_TI_9_10 ( ((Flag *)(&(uF_StatusRainsensor_mg))));
          break;
        case 71: /* for global object uF_StatusRainsensor2_mg */
          VCAST_TI_9_10 ( ((Flag *)(&(uF_StatusRainsensor2_mg))));
          break;
        case 72: /* for global object rb_WiperSpeed_g */
          VCAST_TI_9_9 ( ((unsigned char *)(&(rb_WiperSpeed_g))));
          break;
        case 73: /* for global object rb_WiperSpeedAlt_g */
          VCAST_TI_9_9 ( ((unsigned char *)(&(rb_WiperSpeedAlt_g))));
          break;
        case 74: /* for global object uF_LIN_DiagReq2_mg */
          VCAST_TI_9_7 ( ((volatile Flag *)(&(uF_LIN_DiagReq2_mg))));
          break;
        case 75: /* for global object uF_Main_Flags_g */
          VCAST_TI_9_7 ( ((volatile Flag *)(&(uF_Main_Flags_g))));
          break;
        case 76: /* for global object rb_RS_LS_Error1_g */
          VCAST_TI_9_9 ( ((unsigned char *)(&(rb_RS_LS_Error1_g))));
          break;
        case 77: /* for global object rb_RS_LS_Error2_g */
          VCAST_TI_9_9 ( ((unsigned char *)(&(rb_RS_LS_Error2_g))));
          break;
        case 78: /* for global object rb_RainS_Error1_g */
          VCAST_TI_9_9 ( ((unsigned char *)(&(rb_RainS_Error1_g))));
          break;
        case 79: /* for global object rb_LightS_Error1_g */
          VCAST_TI_9_9 ( ((unsigned char *)(&(rb_LightS_Error1_g))));
          break;
        case 80: /* for global object rw_EEPROM_Address_to_Write_g */
          VCAST_TI_9_6 ( ((unsigned *)(&(rw_EEPROM_Address_to_Write_g))));
          break;
        case 81: /* for global object rb_I2C_EEPROM_bytesToWrite_g */
          VCAST_TI_9_9 ( ((unsigned char *)(&(rb_I2C_EEPROM_bytesToWrite_g))));
          break;
        case 82: /* for global object rab_EEPROM_Bytes_toWrite_g */
          VCAST_TI_9_43 ( ((unsigned char *)(rab_EEPROM_Bytes_toWrite_g)));
          break;
        case 83: /* for global object uF_E2ConfigErrorFlags_g */
          VCAST_TI_9_7 ( ((volatile Flag *)(&(uF_E2ConfigErrorFlags_g))));
          break;
        case 84: /* for global object rb_speed_in_kmh_g */
          VCAST_TI_9_9 ( ((unsigned char *)(&(rb_speed_in_kmh_g))));
          break;
        case 85: /* for global object rb_LSPotiStage_g */
          VCAST_TI_9_9 ( ((unsigned char *)(&(rb_LSPotiStage_g))));
          break;
        case 86: /* for global object uF_Check_lightsensor_g */
          VCAST_TI_9_10 ( ((Flag *)(&(uF_Check_lightsensor_g))));
          break;
        case 87: /* for global object uF_modi_lightsens_g */
          VCAST_TI_9_10 ( ((Flag *)(&(uF_modi_lightsens_g))));
          break;
        case 88: /* for global object uF_LightInternalStatus_g */
          VCAST_TI_9_10 ( ((Flag *)(&(uF_LightInternalStatus_g))));
          break;
        case 89: /* for global object rw_StandbyTimeOutCnt_g */
          VCAST_TI_9_6 ( ((unsigned *)(&(rw_StandbyTimeOutCnt_g))));
          break;
        case 90: /* for global object rb_ASIC_ALSx_ShortDetected_Error_g */
          VCAST_TI_9_9 ( ((unsigned char *)(&(rb_ASIC_ALSx_ShortDetected_Error_g))));
          break;
        case 91: /* for global object rb_ASIC_ALS2Amb_ShortDetected_cnt_g */
          VCAST_TI_9_9 ( ((unsigned char *)(&(rb_ASIC_ALS2Amb_ShortDetected_cnt_g))));
          break;
        case 92: /* for global object rb_ASIC_ALS5FW_ShortDetected_cnt_g */
          VCAST_TI_9_9 ( ((unsigned char *)(&(rb_ASIC_ALS5FW_ShortDetected_cnt_g))));
          break;
        case 93: /* for global object rb_ASIC_INRECIR_ShortDetected_cnt_g */
          VCAST_TI_9_9 ( ((unsigned char *)(&(rb_ASIC_INRECIR_ShortDetected_cnt_g))));
          break;
        case 94: /* for global object uF_ASIC_ControlFlags_g */
          VCAST_TI_9_10 ( ((Flag *)(&(uF_ASIC_ControlFlags_g))));
          break;
        case 95: /* for global object uF_GainAdjustFlags_g */
          VCAST_TI_9_10 ( ((Flag *)(&(uF_GainAdjustFlags_g))));
          break;
        case 96: /* for global object uF_ASIC_Error_Flags_g */
          VCAST_TI_9_10 ( ((Flag *)(&(uF_ASIC_Error_Flags_g))));
          break;
        case 97: /* for global object uF_ASIC_Error_Flags1_g */
          VCAST_TI_9_10 ( ((Flag *)(&(uF_ASIC_Error_Flags1_g))));
          break;
        case 98: /* for global object uF_ASIC_Ctrl_Error_Flags_g */
          VCAST_TI_9_10 ( ((Flag *)(&(uF_ASIC_Ctrl_Error_Flags_g))));
          break;
        case 99: /* for global object rw_Solar_light16bit_1_g */
          VCAST_TI_9_6 ( ((unsigned *)(&(rw_Solar_light16bit_1_g))));
          break;
        case 100: /* for global object rw_Solar_light16bit_2_g */
          VCAST_TI_9_6 ( ((unsigned *)(&(rw_Solar_light16bit_2_g))));
          break;
        case 101: /* for global object ras_ASIC_MUX_MeasAD_g */
          VCAST_TI_9_29 ( ((ASIC_ALI_Meas_t *)(ras_ASIC_MUX_MeasAD_g)));
          break;
        case 102: /* for global object rb_ASIC_initTimeout_g */
          VCAST_TI_9_9 ( ((unsigned char *)(&(rb_ASIC_initTimeout_g))));
          break;
        case 103: /* for global object rb_VIref_ErrCnt_g */
          VCAST_TI_9_9 ( ((unsigned char *)(&(rb_VIref_ErrCnt_g))));
          break;
        case 104: /* for global object rb_ASIC_SPI_ErrorCodeCnt_g */
          VCAST_TI_9_9 ( ((unsigned char *)(&(rb_ASIC_SPI_ErrorCodeCnt_g))));
          break;
        case 105: /* for global object rb_StaticNoValidAD_cnt_g */
          VCAST_TI_9_9 ( ((unsigned char *)(&(rb_StaticNoValidAD_cnt_g))));
          break;
        case 106: /* for global object rw_SPINoCommCounter_g */
          VCAST_TI_9_6 ( ((unsigned *)(&(rw_SPINoCommCounter_g))));
          break;
        case 14: /* for global object uF_StalkInPos_Flags_g */
          VCAST_TI_9_7 ( ((volatile Flag *)(&(uF_StalkInPos_Flags_g))));
          break;
        case 107: /* for global object rb_RainInt_IntensityOutput_g */
          VCAST_TI_9_9 ( ((unsigned char *)(&(rb_RainInt_IntensityOutput_g))));
          break;
        case 108: /* for global object rb_overWipeCoef */
          VCAST_TI_9_6 ( ((unsigned *)(&(rb_overWipeCoef))));
          break;
        case 15: /* for global object rb_Verglasun_ClosedDebounce_mg */
          VCAST_TI_9_9 ( ((unsigned char *)(&(rb_Verglasun_ClosedDebounce_mg))));
          break;
        case 16: /* for global object rw_CommandCloseWindowTimout_mg */
          VCAST_TI_9_6 ( ((unsigned *)(&(rw_CommandCloseWindowTimout_mg))));
          break;
        case 17: /* for global object rb_AnyErrorCounterDebounce_mg */
          VCAST_TI_9_9 ( ((unsigned char *)(&(rb_AnyErrorCounterDebounce_mg))));
          break;
        case 18: /* for global object rw_AfterRSWipeCounter_mg */
          VCAST_TI_9_6 ( ((unsigned *)(&(rw_AfterRSWipeCounter_mg))));
          break;
        case 19: /* for global object rw_AfterRSWipeCounterAlt_mg */
          VCAST_TI_9_6 ( ((unsigned *)(&(rw_AfterRSWipeCounterAlt_mg))));
          break;
        case 20: /* for global object rw_AfterWWSWipeCounter_mg */
          VCAST_TI_9_6 ( ((unsigned *)(&(rw_AfterWWSWipeCounter_mg))));
          break;
        case 21: /* for global object rw_WipeCommandTimOut_mg */
          VCAST_TI_9_6 ( ((unsigned *)(&(rw_WipeCommandTimOut_mg))));
          break;
        case 22: /* for global object rb_Err_State_Light_Sens_mg */
          VCAST_TI_9_9 ( ((unsigned char *)(&(rb_Err_State_Light_Sens_mg))));
          break;
        case 23: /* for global object rb_OutsideTemp_mg */
          VCAST_TI_9_9 ( ((unsigned char *)(&(rb_OutsideTemp_mg))));
          break;
        case 24: /* for global object rb_WipeWorkStatus_mg */
          VCAST_TI_9_9 ( ((unsigned char *)(&(rb_WipeWorkStatus_mg))));
          break;
        case 25: /* for global object HUDEverageValue */
          VCAST_TI_9_42 ( ((unsigned long *)(HUDEverageValue)));
          break;
        case 26: /* for global object rb_storeHUDValueEvery500ms */
          VCAST_TI_9_41 ( ((unsigned long *)(rb_storeHUDValueEvery500ms)));
          break;
        case 27: /* for global object RW_Amb_Fw_Result_End */
          VCAST_TI_9_31 ( ((unsigned long *)(&(RW_Amb_Fw_Result_End))));
          break;
        case 28: /* for global object rb_hud_data_update */
          VCAST_TI_9_9 ( ((unsigned char *)(&(rb_hud_data_update))));
          break;
        case 29: /* for global object rb_AfterResetCounter_l */
          VCAST_TI_9_9 ( ((unsigned char *)(&(rb_AfterResetCounter_l))));
          break;
        case 30: /* for global object rw_IgnitionOffDelay_mg */
          VCAST_TI_9_6 ( ((unsigned *)(&(rw_IgnitionOffDelay_mg))));
          break;
        case 31: /* for global object rb_tunnelWipeActive_g */
          VCAST_TI_9_9 ( ((unsigned char *)(&(rb_tunnelWipeActive_g))));
          break;
        case 32: /* for global object rb_RLS_Sensitivity_Array_l */
          VCAST_TI_9_50 ( ((unsigned char *)(rb_RLS_Sensitivity_Array_l)));
          break;
        case 33: /* for global object rb_Verglasun_offenDebounce_mg */
          VCAST_TI_9_9 ( ((unsigned char *)(&(rb_Verglasun_offenDebounce_mg))));
          break;
        case 34: /* for global object Vehicle_Speed_Decision_Flag */
          VCAST_TI_9_9 ( ((unsigned char *)(&(Vehicle_Speed_Decision_Flag))));
          break;
        default:
          vCAST_TOOL_ERROR = vCAST_true;
          break;
      } /* switch( VCAST_PARAM_INDEX ) */
      break; /* case 0 (global objects) */
    case 43: /* function sci_init */
      switch ( VCAST_PARAM_INDEX ) {
        case 1:
          VCAST_TI_9_9 ( ((unsigned char *)(&(P_10_1_1))));
          break;
      } /* switch ( VCAST_PARAM_INDEX ) */
      break; /* function sci_init */
    case 45: /* function get_rb_LightVetoCounter_g */
      switch ( VCAST_PARAM_INDEX ) {
        case 1:
          VCAST_TI_9_9 ( ((unsigned char *)(&(R_10_3))));
          break;
      } /* switch ( VCAST_PARAM_INDEX ) */
      break; /* function get_rb_LightVetoCounter_g */
    case 46: /* function get_rw_Amb_light16bit_g */
      switch ( VCAST_PARAM_INDEX ) {
        case 1:
          VCAST_TI_9_6 ( ((unsigned *)(&(R_10_4))));
          break;
      } /* switch ( VCAST_PARAM_INDEX ) */
      break; /* function get_rw_Amb_light16bit_g */
    case 47: /* function get_rl_HUD_light32bit_g */
      switch ( VCAST_PARAM_INDEX ) {
        case 1:
          VCAST_TI_9_31 ( ((unsigned long *)(&(R_10_5))));
          break;
      } /* switch ( VCAST_PARAM_INDEX ) */
      break; /* function get_rl_HUD_light32bit_g */
    case 48: /* function get_rw_IR_light16bit_g */
      switch ( VCAST_PARAM_INDEX ) {
        case 1:
          VCAST_TI_9_6 ( ((unsigned *)(&(R_10_6))));
          break;
      } /* switch ( VCAST_PARAM_INDEX ) */
      break; /* function get_rw_IR_light16bit_g */
    case 49: /* function get_rb_LightSignalErrorCnt_g */
      switch ( VCAST_PARAM_INDEX ) {
        case 1:
          VCAST_TI_9_9 ( ((unsigned char *)(&(R_10_7))));
          break;
      } /* switch ( VCAST_PARAM_INDEX ) */
      break; /* function get_rb_LightSignalErrorCnt_g */
    case 50: /* function get_rb_VDD_LightSignalErrorCnt_g */
      switch ( VCAST_PARAM_INDEX ) {
        case 1:
          VCAST_TI_9_9 ( ((unsigned char *)(&(R_10_8))));
          break;
      } /* switch ( VCAST_PARAM_INDEX ) */
      break; /* function get_rb_VDD_LightSignalErrorCnt_g */
    case 51: /* function get_rb_LEDx_LStop_error_cnt_g */
      switch ( VCAST_PARAM_INDEX ) {
        case 1:
          VCAST_TI_9_9 ( ((unsigned char *)(&(R_10_9))));
          break;
      } /* switch ( VCAST_PARAM_INDEX ) */
      break; /* function get_rb_LEDx_LStop_error_cnt_g */
    case 16: /* function ApplLinInit */
      switch ( VCAST_PARAM_INDEX ) {
        case 1:
          VCAST_TI_9_9 ( ((unsigned char *)(&(P_9_16_1))));
          break;
      } /* switch ( VCAST_PARAM_INDEX ) */
      break; /* function ApplLinInit */
    case 17: /* function ApplLinSlavePreCopy */
      switch ( VCAST_PARAM_INDEX ) {
        case 1:
          VCAST_TI_9_9 ( ((unsigned char *)(&(P_9_17_1))));
          break;
      } /* switch ( VCAST_PARAM_INDEX ) */
      break; /* function ApplLinSlavePreCopy */
    case 18: /* function GetFiveTableValue_500ms */
      switch ( VCAST_PARAM_INDEX ) {
        case 1:
          VCAST_TI_9_31 ( ((unsigned long *)(&(P_9_18_1))));
          break;
      } /* switch ( VCAST_PARAM_INDEX ) */
      break; /* function GetFiveTableValue_500ms */
    case 19: /* function AdjustOutHudValue */
      switch ( VCAST_PARAM_INDEX ) {
        case 1:
          VCAST_TI_9_31 ( ((unsigned long *)(&(P_9_19_1))));
          break;
        case 2:
          VCAST_TI_9_31 ( ((unsigned long *)(&(R_9_19))));
          break;
      } /* switch ( VCAST_PARAM_INDEX ) */
      break; /* function AdjustOutHudValue */
    case 20: /* function GetUpdateTimeForLightStatus */
      switch ( VCAST_PARAM_INDEX ) {
        case 1:
          VCAST_TI_9_9 ( ((unsigned char *)(&(R_9_20))));
          break;
      } /* switch ( VCAST_PARAM_INDEX ) */
      break; /* function GetUpdateTimeForLightStatus */
    case 21: /* function CalcHUDMean_1000ms */
      switch ( VCAST_PARAM_INDEX ) {
        case 1:
          VCAST_TI_9_31 ( ((unsigned long *)(&(R_9_21))));
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
          VCAST_TI_9_31 ( ((unsigned long *)(&(P_9_23_1))));
          break;
        case 2:
          VCAST_TI_9_31 ( ((unsigned long *)(&(P_9_23_2))));
          break;
      } /* switch ( VCAST_PARAM_INDEX ) */
      break; /* function GetFiveTableValue_50ms */
    case 24: /* function CRC8SAEJ1850 */
      switch ( VCAST_PARAM_INDEX ) {
        case 1:
          VCAST_TI_9_1 ( ((unsigned char **)(&(P_9_24_1))));
          break;
        case 2:
          VCAST_TI_9_9 ( ((unsigned char *)(&(P_9_24_2))));
          break;
        case 3:
          VCAST_TI_9_9 ( ((unsigned char *)(&(R_9_24))));
          break;
      } /* switch ( VCAST_PARAM_INDEX ) */
      break; /* function CRC8SAEJ1850 */
    case 25: /* function GetOutdBriStsCrcj1850 */
      switch ( VCAST_PARAM_INDEX ) {
        case 1:
          VCAST_TI_9_9 ( ((unsigned char *)(&(P_9_25_1))));
          break;
        case 2:
          VCAST_TI_9_9 ( ((unsigned char *)(&(R_9_25))));
          break;
      } /* switch ( VCAST_PARAM_INDEX ) */
      break; /* function GetOutdBriStsCrcj1850 */
    case 26: /* function GetHudCrcj1850 */
      switch ( VCAST_PARAM_INDEX ) {
        case 1:
          VCAST_TI_9_31 ( ((unsigned long *)(&(P_9_26_1))));
          break;
        case 2:
          VCAST_TI_9_9 ( ((unsigned char *)(&(R_9_26))));
          break;
      } /* switch ( VCAST_PARAM_INDEX ) */
      break; /* function GetHudCrcj1850 */
    case 27: /* function GetLightTransmission */
      switch ( VCAST_PARAM_INDEX ) {
        case 1:
          VCAST_TI_9_9 ( ((unsigned char *)(&(P_9_27_1))));
          break;
        case 2:
          VCAST_TI_9_9 ( ((unsigned char *)(&(P_9_27_2))));
          break;
      } /* switch ( VCAST_PARAM_INDEX ) */
      break; /* function GetLightTransmission */
    case 28: /* function Set_BCMLightOffset */
      switch ( VCAST_PARAM_INDEX ) {
        case 1:
          VCAST_TI_9_9 ( ((unsigned char *)(&(P_9_28_1))));
          break;
      } /* switch ( VCAST_PARAM_INDEX ) */
      break; /* function Set_BCMLightOffset */
    case 33: /* function IsByteOddParity */
      switch ( VCAST_PARAM_INDEX ) {
        case 1:
          VCAST_TI_9_9 ( ((unsigned char *)(&(P_9_33_1))));
          break;
        case 2:
          VCAST_TI_9_9 ( ((unsigned char *)(&(R_9_33))));
          break;
      } /* switch ( VCAST_PARAM_INDEX ) */
      break; /* function IsByteOddParity */
    default:
      vCAST_TOOL_ERROR = vCAST_true;
      break;
  } /* switch ( VCAST_SUB_INDEX ) */
}


/* A typedef */
#if (defined(VCAST_NO_TYPE_SUPPORT))
void VCAST_TI_9_13 ( s_rb_EEPROMStructPD_buff_g *vcast_param ) 
{
  /* User code: type is not supported */
  vcast_not_supported();
} /* end VCAST_TI_9_13 */
#else /*(defined(VCAST_NO_TYPE_SUPPORT))*/
void VCAST_TI_9_13 ( s_rb_EEPROMStructPD_buff_g *vcast_param ) 
{
#if ((defined(VCAST_NO_TYPE_SUPPORT))||(defined(VCAST_NO_UNION_SUPPORT)))
  /* User code: type is not supported */
  vcast_not_supported();
#else /*((defined(VCAST_NO_TYPE_SUPPORT))||(defined(VCAST_NO_UNION_SUPPORT)))*/
  {
#ifndef VCAST_VXWORKS
#ifndef VCAST_NO_SETJMP
    int VCAST_TI_9_64_jmpval;
    VCAST_TI_9_64_jmpval = setjmp ( VCAST_env );
    vcast_is_in_union = vCAST_false;
    if ( VCAST_TI_9_64_jmpval == 0 ) {
      vcast_is_in_union = vCAST_true;
#endif /* VCAST_VXWORKS */
#endif /* VCAST_NO_SETJMP */
      switch ( vcast_get_param () ) { /* Choose field member */
        /* Setting member variable vcast_param->_c */
        case 1: { 
          VCAST_TI_9_65 ( ((unsigned char *)(vcast_param->_c)));
          break; /* end case 1*/
        } /* end case */
        /* Setting member variable vcast_param->EEPROMStructPD */
        case 2: { 
          VCAST_TI_9_14 ( ((s_rb_EEPROMStruct_PD_g *)(&(vcast_param->EEPROMStructPD))));
          break; /* end case 2*/
        } /* end case */
        default:
          vCAST_TOOL_ERROR = vCAST_true;
      } /* end switch */ 
#ifndef VCAST_VXWORKS
#ifndef VCAST_NO_SETJMP
    } else if ( vCAST_COMMAND == vCAST_PRINT )
      vectorcast_fprint_string(vCAST_OUTPUT_FILE,"invalid address\n");
#endif /* VCAST_VXWORKS */
#endif /* VCAST_NO_SETJMP */
  }
#endif /*((defined(VCAST_NO_TYPE_SUPPORT))||(defined(VCAST_NO_UNION_SUPPORT)))*/

} /* end VCAST_TI_9_13 */
#endif /*(defined(VCAST_NO_TYPE_SUPPORT))*/


/* An integer */
#if (defined(VCAST_NO_TYPE_SUPPORT))
void VCAST_TI_9_9 ( unsigned char *vcast_param ) 
{
  /* User code: type is not supported */
  vcast_not_supported();
} /* end VCAST_TI_9_9 */
#else /*(defined(VCAST_NO_TYPE_SUPPORT))*/
void VCAST_TI_9_9 ( unsigned char *vcast_param ) 
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
    *vcast_param = UCHAR_MIN;
    break;
  case vCAST_MID_VAL :
    *vcast_param = (UCHAR_MIN / 2) + (UCHAR_MAX / 2);
    break;
  case vCAST_LAST_VAL :
    *vcast_param = UCHAR_MAX;
    break;
  case vCAST_MIN_MINUS_1_VAL :
    *vcast_param = UCHAR_MIN;
    *vcast_param = *vcast_param - 1;
    break;
  case vCAST_MAX_PLUS_1_VAL :
    *vcast_param = UCHAR_MAX;
    *vcast_param = *vcast_param + 1;
    break;
  case vCAST_ZERO_VAL :
    *vcast_param = 0;
    break;
  default:
    break;
} /* end switch */
} /* end VCAST_TI_9_9 */
#endif /*(defined(VCAST_NO_TYPE_SUPPORT))*/


/* An integer */
#if (defined(VCAST_NO_TYPE_SUPPORT))
void VCAST_TI_9_6 ( unsigned *vcast_param ) 
{
  /* User code: type is not supported */
  vcast_not_supported();
} /* end VCAST_TI_9_6 */
#else /*(defined(VCAST_NO_TYPE_SUPPORT))*/
void VCAST_TI_9_6 ( unsigned *vcast_param ) 
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
    *vcast_param = UINT_MIN;
    break;
  case vCAST_MID_VAL :
    *vcast_param = (UINT_MIN / 2) + (UINT_MAX / 2);
    break;
  case vCAST_LAST_VAL :
    *vcast_param = UINT_MAX;
    break;
  case vCAST_MIN_MINUS_1_VAL :
    *vcast_param = UINT_MIN;
    *vcast_param = *vcast_param - 1;
    break;
  case vCAST_MAX_PLUS_1_VAL :
    *vcast_param = UINT_MAX;
    *vcast_param = *vcast_param + 1;
    break;
  case vCAST_ZERO_VAL :
    *vcast_param = 0;
    break;
  default:
    break;
} /* end switch */
} /* end VCAST_TI_9_6 */
#endif /*(defined(VCAST_NO_TYPE_SUPPORT))*/


/* A typedef */
#if (defined(VCAST_NO_TYPE_SUPPORT))
void VCAST_TI_9_17 ( s_rb_EEPROMStructAD_buff_g *vcast_param ) 
{
  /* User code: type is not supported */
  vcast_not_supported();
} /* end VCAST_TI_9_17 */
#else /*(defined(VCAST_NO_TYPE_SUPPORT))*/
void VCAST_TI_9_17 ( s_rb_EEPROMStructAD_buff_g *vcast_param ) 
{
#if ((defined(VCAST_NO_TYPE_SUPPORT))||(defined(VCAST_NO_UNION_SUPPORT)))
  /* User code: type is not supported */
  vcast_not_supported();
#else /*((defined(VCAST_NO_TYPE_SUPPORT))||(defined(VCAST_NO_UNION_SUPPORT)))*/
  {
#ifndef VCAST_VXWORKS
#ifndef VCAST_NO_SETJMP
    int VCAST_TI_9_74_jmpval;
    VCAST_TI_9_74_jmpval = setjmp ( VCAST_env );
    vcast_is_in_union = vCAST_false;
    if ( VCAST_TI_9_74_jmpval == 0 ) {
      vcast_is_in_union = vCAST_true;
#endif /* VCAST_VXWORKS */
#endif /* VCAST_NO_SETJMP */
      switch ( vcast_get_param () ) { /* Choose field member */
        /* Setting member variable vcast_param->_c */
        case 1: { 
          VCAST_TI_9_75 ( ((unsigned char *)(vcast_param->_c)));
          break; /* end case 1*/
        } /* end case */
        /* Setting member variable vcast_param->EEPROMStructAD */
        case 2: { 
          VCAST_TI_9_18 ( ((s_rb_EEPROMStruct_AD_g *)(&(vcast_param->EEPROMStructAD))));
          break; /* end case 2*/
        } /* end case */
        default:
          vCAST_TOOL_ERROR = vCAST_true;
      } /* end switch */ 
#ifndef VCAST_VXWORKS
#ifndef VCAST_NO_SETJMP
    } else if ( vCAST_COMMAND == vCAST_PRINT )
      vectorcast_fprint_string(vCAST_OUTPUT_FILE,"invalid address\n");
#endif /* VCAST_VXWORKS */
#endif /* VCAST_NO_SETJMP */
  }
#endif /*((defined(VCAST_NO_TYPE_SUPPORT))||(defined(VCAST_NO_UNION_SUPPORT)))*/

} /* end VCAST_TI_9_17 */
#endif /*(defined(VCAST_NO_TYPE_SUPPORT))*/


/* A union */
#if ((defined(VCAST_NO_TYPE_SUPPORT))||(defined(VCAST_NO_UNION_SUPPORT)))
void VCAST_TI_9_3 ( union tLinIndicationBits *vcast_param ) 
{
  /* User code: type is not supported */
  vcast_not_supported();
} /* end VCAST_TI_9_3 */
#else /*((defined(VCAST_NO_TYPE_SUPPORT))||(defined(VCAST_NO_UNION_SUPPORT)))*/
void VCAST_TI_9_3 ( union tLinIndicationBits *vcast_param ) 
{
  {
#ifndef VCAST_VXWORKS
#ifndef VCAST_NO_SETJMP
    int VCAST_TI_9_3_jmpval;
    VCAST_TI_9_3_jmpval = setjmp ( VCAST_env );
    vcast_is_in_union = vCAST_false;
    if ( VCAST_TI_9_3_jmpval == 0 ) {
      vcast_is_in_union = vCAST_true;
#endif /* VCAST_VXWORKS */
#endif /* VCAST_NO_SETJMP */
      switch ( vcast_get_param () ) { /* Choose field member */
        /* Setting member variable vcast_param->_c */
        case 1: { 
          VCAST_TI_9_76 ( ((unsigned char *)(vcast_param->_c)));
          break; /* end case 1*/
        } /* end case */
        /* Setting member variable vcast_param->w */
        case 2: { 
          VCAST_TI_9_4 ( ((struct _c_bits8 *)(vcast_param->w)));
          break; /* end case 2*/
        } /* end case */
        default:
          vCAST_TOOL_ERROR = vCAST_true;
      } /* end switch */ 
#ifndef VCAST_VXWORKS
#ifndef VCAST_NO_SETJMP
    } else if ( vCAST_COMMAND == vCAST_PRINT )
      vectorcast_fprint_string(vCAST_OUTPUT_FILE,"invalid address\n");
#endif /* VCAST_VXWORKS */
#endif /* VCAST_NO_SETJMP */
  }
} /* end VCAST_TI_9_3 */
#endif /*((defined(VCAST_NO_TYPE_SUPPORT))||(defined(VCAST_NO_UNION_SUPPORT)))*/


/* A union */
#if ((defined(VCAST_NO_TYPE_SUPPORT))||(defined(VCAST_NO_UNION_SUPPORT)))
void VCAST_TI_9_21 ( union tLinConfirmationBits *vcast_param ) 
{
  /* User code: type is not supported */
  vcast_not_supported();
} /* end VCAST_TI_9_21 */
#else /*((defined(VCAST_NO_TYPE_SUPPORT))||(defined(VCAST_NO_UNION_SUPPORT)))*/
void VCAST_TI_9_21 ( union tLinConfirmationBits *vcast_param ) 
{
  {
#ifndef VCAST_VXWORKS
#ifndef VCAST_NO_SETJMP
    int VCAST_TI_9_21_jmpval;
    VCAST_TI_9_21_jmpval = setjmp ( VCAST_env );
    vcast_is_in_union = vCAST_false;
    if ( VCAST_TI_9_21_jmpval == 0 ) {
      vcast_is_in_union = vCAST_true;
#endif /* VCAST_VXWORKS */
#endif /* VCAST_NO_SETJMP */
      switch ( vcast_get_param () ) { /* Choose field member */
        /* Setting member variable vcast_param->_c */
        case 1: { 
          VCAST_TI_9_76 ( ((unsigned char *)(vcast_param->_c)));
          break; /* end case 1*/
        } /* end case */
        /* Setting member variable vcast_param->w */
        case 2: { 
          VCAST_TI_9_4 ( ((struct _c_bits8 *)(vcast_param->w)));
          break; /* end case 2*/
        } /* end case */
        default:
          vCAST_TOOL_ERROR = vCAST_true;
      } /* end switch */ 
#ifndef VCAST_VXWORKS
#ifndef VCAST_NO_SETJMP
    } else if ( vCAST_COMMAND == vCAST_PRINT )
      vectorcast_fprint_string(vCAST_OUTPUT_FILE,"invalid address\n");
#endif /* VCAST_VXWORKS */
#endif /* VCAST_NO_SETJMP */
  }
} /* end VCAST_TI_9_21 */
#endif /*((defined(VCAST_NO_TYPE_SUPPORT))||(defined(VCAST_NO_UNION_SUPPORT)))*/


/* A typedef */
#if (defined(VCAST_NO_TYPE_SUPPORT))
void VCAST_TI_9_7 ( volatile Flag *vcast_param ) 
{
  /* User code: type is not supported */
  vcast_not_supported();
} /* end VCAST_TI_9_7 */
#else /*(defined(VCAST_NO_TYPE_SUPPORT))*/
void VCAST_TI_9_7 ( volatile Flag *vcast_param ) 
{
#if ((defined(VCAST_NO_TYPE_SUPPORT))||(defined(VCAST_NO_UNION_SUPPORT)))
  /* User code: type is not supported */
  vcast_not_supported();
#else /*((defined(VCAST_NO_TYPE_SUPPORT))||(defined(VCAST_NO_UNION_SUPPORT)))*/
  {
#ifndef VCAST_VXWORKS
#ifndef VCAST_NO_SETJMP
    int VCAST_TI_9_59_jmpval;
    VCAST_TI_9_59_jmpval = setjmp ( VCAST_env );
    vcast_is_in_union = vCAST_false;
    if ( VCAST_TI_9_59_jmpval == 0 ) {
      vcast_is_in_union = vCAST_true;
#endif /* VCAST_VXWORKS */
#endif /* VCAST_NO_SETJMP */
      switch ( vcast_get_param () ) { /* Choose field member */
        /* Setting member variable vcast_param->Bit */
        case 1: { 
          VCAST_TI_9_8 ( ((Bit_Feld *)(&(vcast_param->Bit))));
          break; /* end case 1*/
        } /* end case */
        /* Setting member variable vcast_param->AllBit */
        case 2: { 
          VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->AllBit))));
          break; /* end case 2*/
        } /* end case */
        default:
          vCAST_TOOL_ERROR = vCAST_true;
      } /* end switch */ 
#ifndef VCAST_VXWORKS
#ifndef VCAST_NO_SETJMP
    } else if ( vCAST_COMMAND == vCAST_PRINT )
      vectorcast_fprint_string(vCAST_OUTPUT_FILE,"invalid address\n");
#endif /* VCAST_VXWORKS */
#endif /* VCAST_NO_SETJMP */
  }
#endif /*((defined(VCAST_NO_TYPE_SUPPORT))||(defined(VCAST_NO_UNION_SUPPORT)))*/

} /* end VCAST_TI_9_7 */
#endif /*(defined(VCAST_NO_TYPE_SUPPORT))*/


/* A typedef */
#if (defined(VCAST_NO_TYPE_SUPPORT))
void VCAST_TI_9_10 ( Flag *vcast_param ) 
{
  /* User code: type is not supported */
  vcast_not_supported();
} /* end VCAST_TI_9_10 */
#else /*(defined(VCAST_NO_TYPE_SUPPORT))*/
void VCAST_TI_9_10 ( Flag *vcast_param ) 
{
#if ((defined(VCAST_NO_TYPE_SUPPORT))||(defined(VCAST_NO_UNION_SUPPORT)))
  /* User code: type is not supported */
  vcast_not_supported();
#else /*((defined(VCAST_NO_TYPE_SUPPORT))||(defined(VCAST_NO_UNION_SUPPORT)))*/
  {
#ifndef VCAST_VXWORKS
#ifndef VCAST_NO_SETJMP
    int VCAST_TI_9_59_jmpval;
    VCAST_TI_9_59_jmpval = setjmp ( VCAST_env );
    vcast_is_in_union = vCAST_false;
    if ( VCAST_TI_9_59_jmpval == 0 ) {
      vcast_is_in_union = vCAST_true;
#endif /* VCAST_VXWORKS */
#endif /* VCAST_NO_SETJMP */
      switch ( vcast_get_param () ) { /* Choose field member */
        /* Setting member variable vcast_param->Bit */
        case 1: { 
          VCAST_TI_9_8 ( ((Bit_Feld *)(&(vcast_param->Bit))));
          break; /* end case 1*/
        } /* end case */
        /* Setting member variable vcast_param->AllBit */
        case 2: { 
          VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->AllBit))));
          break; /* end case 2*/
        } /* end case */
        default:
          vCAST_TOOL_ERROR = vCAST_true;
      } /* end switch */ 
#ifndef VCAST_VXWORKS
#ifndef VCAST_NO_SETJMP
    } else if ( vCAST_COMMAND == vCAST_PRINT )
      vectorcast_fprint_string(vCAST_OUTPUT_FILE,"invalid address\n");
#endif /* VCAST_VXWORKS */
#endif /* VCAST_NO_SETJMP */
  }
#endif /*((defined(VCAST_NO_TYPE_SUPPORT))||(defined(VCAST_NO_UNION_SUPPORT)))*/

} /* end VCAST_TI_9_10 */
#endif /*(defined(VCAST_NO_TYPE_SUPPORT))*/


/* A typedef */
#if (defined(VCAST_NO_TYPE_SUPPORT))
void VCAST_TI_9_32 ( _c_RlsmCem_SerNrLin1Fr01_CEM_LIN1_buf *vcast_param ) 
{
  /* User code: type is not supported */
  vcast_not_supported();
} /* end VCAST_TI_9_32 */
#else /*(defined(VCAST_NO_TYPE_SUPPORT))*/
void VCAST_TI_9_32 ( _c_RlsmCem_SerNrLin1Fr01_CEM_LIN1_buf *vcast_param ) 
{
#if ((defined(VCAST_NO_TYPE_SUPPORT))||(defined(VCAST_NO_UNION_SUPPORT)))
  /* User code: type is not supported */
  vcast_not_supported();
#else /*((defined(VCAST_NO_TYPE_SUPPORT))||(defined(VCAST_NO_UNION_SUPPORT)))*/
  {
#ifndef VCAST_VXWORKS
#ifndef VCAST_NO_SETJMP
    int VCAST_TI_9_90_jmpval;
    VCAST_TI_9_90_jmpval = setjmp ( VCAST_env );
    vcast_is_in_union = vCAST_false;
    if ( VCAST_TI_9_90_jmpval == 0 ) {
      vcast_is_in_union = vCAST_true;
#endif /* VCAST_VXWORKS */
#endif /* VCAST_NO_SETJMP */
      switch ( vcast_get_param () ) { /* Choose field member */
        /* Setting member variable vcast_param->_c */
        case 1: { 
          VCAST_TI_9_33 ( ((unsigned char *)(vcast_param->_c)));
          break; /* end case 1*/
        } /* end case */
        /* Setting member variable vcast_param->rlsmcem_sernrlin1fr01_cem_lin1 */
        case 2: { 
          VCAST_TI_9_45 ( ((_c_RlsmCem_SerNrLin1Fr01_CEM_LIN1_msgType *)(&(vcast_param->rlsmcem_sernrlin1fr01_cem_lin1))));
          break; /* end case 2*/
        } /* end case */
        default:
          vCAST_TOOL_ERROR = vCAST_true;
      } /* end switch */ 
#ifndef VCAST_VXWORKS
#ifndef VCAST_NO_SETJMP
    } else if ( vCAST_COMMAND == vCAST_PRINT )
      vectorcast_fprint_string(vCAST_OUTPUT_FILE,"invalid address\n");
#endif /* VCAST_VXWORKS */
#endif /* VCAST_NO_SETJMP */
  }
#endif /*((defined(VCAST_NO_TYPE_SUPPORT))||(defined(VCAST_NO_UNION_SUPPORT)))*/

} /* end VCAST_TI_9_32 */
#endif /*(defined(VCAST_NO_TYPE_SUPPORT))*/


/* A typedef */
#if (defined(VCAST_NO_TYPE_SUPPORT))
void VCAST_TI_9_34 ( _c_RlsmCem_Lin1PartNrFr02_CEM_LIN1_buf *vcast_param ) 
{
  /* User code: type is not supported */
  vcast_not_supported();
} /* end VCAST_TI_9_34 */
#else /*(defined(VCAST_NO_TYPE_SUPPORT))*/
void VCAST_TI_9_34 ( _c_RlsmCem_Lin1PartNrFr02_CEM_LIN1_buf *vcast_param ) 
{
#if ((defined(VCAST_NO_TYPE_SUPPORT))||(defined(VCAST_NO_UNION_SUPPORT)))
  /* User code: type is not supported */
  vcast_not_supported();
#else /*((defined(VCAST_NO_TYPE_SUPPORT))||(defined(VCAST_NO_UNION_SUPPORT)))*/
  {
#ifndef VCAST_VXWORKS
#ifndef VCAST_NO_SETJMP
    int VCAST_TI_9_91_jmpval;
    VCAST_TI_9_91_jmpval = setjmp ( VCAST_env );
    vcast_is_in_union = vCAST_false;
    if ( VCAST_TI_9_91_jmpval == 0 ) {
      vcast_is_in_union = vCAST_true;
#endif /* VCAST_VXWORKS */
#endif /* VCAST_NO_SETJMP */
      switch ( vcast_get_param () ) { /* Choose field member */
        /* Setting member variable vcast_param->_c */
        case 1: { 
          VCAST_TI_9_35 ( ((unsigned char *)(vcast_param->_c)));
          break; /* end case 1*/
        } /* end case */
        /* Setting member variable vcast_param->rlsmcem_lin1partnrfr02_cem_lin1 */
        case 2: { 
          VCAST_TI_9_47 ( ((_c_RlsmCem_Lin1PartNrFr02_CEM_LIN1_msgType *)(&(vcast_param->rlsmcem_lin1partnrfr02_cem_lin1))));
          break; /* end case 2*/
        } /* end case */
        default:
          vCAST_TOOL_ERROR = vCAST_true;
      } /* end switch */ 
#ifndef VCAST_VXWORKS
#ifndef VCAST_NO_SETJMP
    } else if ( vCAST_COMMAND == vCAST_PRINT )
      vectorcast_fprint_string(vCAST_OUTPUT_FILE,"invalid address\n");
#endif /* VCAST_VXWORKS */
#endif /* VCAST_NO_SETJMP */
  }
#endif /*((defined(VCAST_NO_TYPE_SUPPORT))||(defined(VCAST_NO_UNION_SUPPORT)))*/

} /* end VCAST_TI_9_34 */
#endif /*(defined(VCAST_NO_TYPE_SUPPORT))*/


/* A typedef */
#if (defined(VCAST_NO_TYPE_SUPPORT))
void VCAST_TI_9_36 ( _c_RlsmCem_Lin1PartNrFr01_CEM_LIN1_buf *vcast_param ) 
{
  /* User code: type is not supported */
  vcast_not_supported();
} /* end VCAST_TI_9_36 */
#else /*(defined(VCAST_NO_TYPE_SUPPORT))*/
void VCAST_TI_9_36 ( _c_RlsmCem_Lin1PartNrFr01_CEM_LIN1_buf *vcast_param ) 
{
#if ((defined(VCAST_NO_TYPE_SUPPORT))||(defined(VCAST_NO_UNION_SUPPORT)))
  /* User code: type is not supported */
  vcast_not_supported();
#else /*((defined(VCAST_NO_TYPE_SUPPORT))||(defined(VCAST_NO_UNION_SUPPORT)))*/
  {
#ifndef VCAST_VXWORKS
#ifndef VCAST_NO_SETJMP
    int VCAST_TI_9_92_jmpval;
    VCAST_TI_9_92_jmpval = setjmp ( VCAST_env );
    vcast_is_in_union = vCAST_false;
    if ( VCAST_TI_9_92_jmpval == 0 ) {
      vcast_is_in_union = vCAST_true;
#endif /* VCAST_VXWORKS */
#endif /* VCAST_NO_SETJMP */
      switch ( vcast_get_param () ) { /* Choose field member */
        /* Setting member variable vcast_param->_c */
        case 1: { 
          VCAST_TI_9_50 ( ((unsigned char *)(vcast_param->_c)));
          break; /* end case 1*/
        } /* end case */
        /* Setting member variable vcast_param->rlsmcem_lin1partnrfr01_cem_lin1 */
        case 2: { 
          VCAST_TI_9_46 ( ((_c_RlsmCem_Lin1PartNrFr01_CEM_LIN1_msgType *)(&(vcast_param->rlsmcem_lin1partnrfr01_cem_lin1))));
          break; /* end case 2*/
        } /* end case */
        default:
          vCAST_TOOL_ERROR = vCAST_true;
      } /* end switch */ 
#ifndef VCAST_VXWORKS
#ifndef VCAST_NO_SETJMP
    } else if ( vCAST_COMMAND == vCAST_PRINT )
      vectorcast_fprint_string(vCAST_OUTPUT_FILE,"invalid address\n");
#endif /* VCAST_VXWORKS */
#endif /* VCAST_NO_SETJMP */
  }
#endif /*((defined(VCAST_NO_TYPE_SUPPORT))||(defined(VCAST_NO_UNION_SUPPORT)))*/

} /* end VCAST_TI_9_36 */
#endif /*(defined(VCAST_NO_TYPE_SUPPORT))*/


/* A typedef */
#if (defined(VCAST_NO_TYPE_SUPPORT))
void VCAST_TI_9_25 ( _c_RlsmCem_Lin1Fr03_CEM_LIN1_buf *vcast_param ) 
{
  /* User code: type is not supported */
  vcast_not_supported();
} /* end VCAST_TI_9_25 */
#else /*(defined(VCAST_NO_TYPE_SUPPORT))*/
void VCAST_TI_9_25 ( _c_RlsmCem_Lin1Fr03_CEM_LIN1_buf *vcast_param ) 
{
#if ((defined(VCAST_NO_TYPE_SUPPORT))||(defined(VCAST_NO_UNION_SUPPORT)))
  /* User code: type is not supported */
  vcast_not_supported();
#else /*((defined(VCAST_NO_TYPE_SUPPORT))||(defined(VCAST_NO_UNION_SUPPORT)))*/
  {
#ifndef VCAST_VXWORKS
#ifndef VCAST_NO_SETJMP
    int VCAST_TI_9_93_jmpval;
    VCAST_TI_9_93_jmpval = setjmp ( VCAST_env );
    vcast_is_in_union = vCAST_false;
    if ( VCAST_TI_9_93_jmpval == 0 ) {
      vcast_is_in_union = vCAST_true;
#endif /* VCAST_VXWORKS */
#endif /* VCAST_NO_SETJMP */
      switch ( vcast_get_param () ) { /* Choose field member */
        /* Setting member variable vcast_param->_c */
        case 1: { 
          VCAST_TI_9_35 ( ((unsigned char *)(vcast_param->_c)));
          break; /* end case 1*/
        } /* end case */
        /* Setting member variable vcast_param->rlsmcem_lin1fr03_cem_lin1 */
        case 2: { 
          VCAST_TI_9_26 ( ((_c_RlsmCem_Lin1Fr03_CEM_LIN1_msgType *)(&(vcast_param->rlsmcem_lin1fr03_cem_lin1))));
          break; /* end case 2*/
        } /* end case */
        default:
          vCAST_TOOL_ERROR = vCAST_true;
      } /* end switch */ 
#ifndef VCAST_VXWORKS
#ifndef VCAST_NO_SETJMP
    } else if ( vCAST_COMMAND == vCAST_PRINT )
      vectorcast_fprint_string(vCAST_OUTPUT_FILE,"invalid address\n");
#endif /* VCAST_VXWORKS */
#endif /* VCAST_NO_SETJMP */
  }
#endif /*((defined(VCAST_NO_TYPE_SUPPORT))||(defined(VCAST_NO_UNION_SUPPORT)))*/

} /* end VCAST_TI_9_25 */
#endif /*(defined(VCAST_NO_TYPE_SUPPORT))*/


/* A typedef */
#if (defined(VCAST_NO_TYPE_SUPPORT))
void VCAST_TI_9_27 ( _c_RlsmCem_Lin1Fr02_CEM_LIN1_buf *vcast_param ) 
{
  /* User code: type is not supported */
  vcast_not_supported();
} /* end VCAST_TI_9_27 */
#else /*(defined(VCAST_NO_TYPE_SUPPORT))*/
void VCAST_TI_9_27 ( _c_RlsmCem_Lin1Fr02_CEM_LIN1_buf *vcast_param ) 
{
#if ((defined(VCAST_NO_TYPE_SUPPORT))||(defined(VCAST_NO_UNION_SUPPORT)))
  /* User code: type is not supported */
  vcast_not_supported();
#else /*((defined(VCAST_NO_TYPE_SUPPORT))||(defined(VCAST_NO_UNION_SUPPORT)))*/
  {
#ifndef VCAST_VXWORKS
#ifndef VCAST_NO_SETJMP
    int VCAST_TI_9_94_jmpval;
    VCAST_TI_9_94_jmpval = setjmp ( VCAST_env );
    vcast_is_in_union = vCAST_false;
    if ( VCAST_TI_9_94_jmpval == 0 ) {
      vcast_is_in_union = vCAST_true;
#endif /* VCAST_VXWORKS */
#endif /* VCAST_NO_SETJMP */
      switch ( vcast_get_param () ) { /* Choose field member */
        /* Setting member variable vcast_param->_c */
        case 1: { 
          VCAST_TI_9_35 ( ((unsigned char *)(vcast_param->_c)));
          break; /* end case 1*/
        } /* end case */
        /* Setting member variable vcast_param->rlsmcem_lin1fr02_cem_lin1 */
        case 2: { 
          VCAST_TI_9_28 ( ((_c_RlsmCem_Lin1Fr02_CEM_LIN1_msgType *)(&(vcast_param->rlsmcem_lin1fr02_cem_lin1))));
          break; /* end case 2*/
        } /* end case */
        default:
          vCAST_TOOL_ERROR = vCAST_true;
      } /* end switch */ 
#ifndef VCAST_VXWORKS
#ifndef VCAST_NO_SETJMP
    } else if ( vCAST_COMMAND == vCAST_PRINT )
      vectorcast_fprint_string(vCAST_OUTPUT_FILE,"invalid address\n");
#endif /* VCAST_VXWORKS */
#endif /* VCAST_NO_SETJMP */
  }
#endif /*((defined(VCAST_NO_TYPE_SUPPORT))||(defined(VCAST_NO_UNION_SUPPORT)))*/

} /* end VCAST_TI_9_27 */
#endif /*(defined(VCAST_NO_TYPE_SUPPORT))*/


/* A typedef */
#if (defined(VCAST_NO_TYPE_SUPPORT))
void VCAST_TI_9_23 ( _c_RlsmCem_Lin1Fr01_CEM_LIN1_buf *vcast_param ) 
{
  /* User code: type is not supported */
  vcast_not_supported();
} /* end VCAST_TI_9_23 */
#else /*(defined(VCAST_NO_TYPE_SUPPORT))*/
void VCAST_TI_9_23 ( _c_RlsmCem_Lin1Fr01_CEM_LIN1_buf *vcast_param ) 
{
#if ((defined(VCAST_NO_TYPE_SUPPORT))||(defined(VCAST_NO_UNION_SUPPORT)))
  /* User code: type is not supported */
  vcast_not_supported();
#else /*((defined(VCAST_NO_TYPE_SUPPORT))||(defined(VCAST_NO_UNION_SUPPORT)))*/
  {
#ifndef VCAST_VXWORKS
#ifndef VCAST_NO_SETJMP
    int VCAST_TI_9_95_jmpval;
    VCAST_TI_9_95_jmpval = setjmp ( VCAST_env );
    vcast_is_in_union = vCAST_false;
    if ( VCAST_TI_9_95_jmpval == 0 ) {
      vcast_is_in_union = vCAST_true;
#endif /* VCAST_VXWORKS */
#endif /* VCAST_NO_SETJMP */
      switch ( vcast_get_param () ) { /* Choose field member */
        /* Setting member variable vcast_param->_c */
        case 1: { 
          VCAST_TI_9_35 ( ((unsigned char *)(vcast_param->_c)));
          break; /* end case 1*/
        } /* end case */
        /* Setting member variable vcast_param->rlsmcem_lin1fr01_cem_lin1 */
        case 2: { 
          VCAST_TI_9_24 ( ((_c_RlsmCem_Lin1Fr01_CEM_LIN1_msgType *)(&(vcast_param->rlsmcem_lin1fr01_cem_lin1))));
          break; /* end case 2*/
        } /* end case */
        default:
          vCAST_TOOL_ERROR = vCAST_true;
      } /* end switch */ 
#ifndef VCAST_VXWORKS
#ifndef VCAST_NO_SETJMP
    } else if ( vCAST_COMMAND == vCAST_PRINT )
      vectorcast_fprint_string(vCAST_OUTPUT_FILE,"invalid address\n");
#endif /* VCAST_VXWORKS */
#endif /* VCAST_NO_SETJMP */
  }
#endif /*((defined(VCAST_NO_TYPE_SUPPORT))||(defined(VCAST_NO_UNION_SUPPORT)))*/

} /* end VCAST_TI_9_23 */
#endif /*(defined(VCAST_NO_TYPE_SUPPORT))*/


/* A typedef */
#if (defined(VCAST_NO_TYPE_SUPPORT))
void VCAST_TI_9_55 ( _c_CemCem_Lin1Fr06_CEM_LIN1_buf *vcast_param ) 
{
  /* User code: type is not supported */
  vcast_not_supported();
} /* end VCAST_TI_9_55 */
#else /*(defined(VCAST_NO_TYPE_SUPPORT))*/
void VCAST_TI_9_55 ( _c_CemCem_Lin1Fr06_CEM_LIN1_buf *vcast_param ) 
{
#if ((defined(VCAST_NO_TYPE_SUPPORT))||(defined(VCAST_NO_UNION_SUPPORT)))
  /* User code: type is not supported */
  vcast_not_supported();
#else /*((defined(VCAST_NO_TYPE_SUPPORT))||(defined(VCAST_NO_UNION_SUPPORT)))*/
  {
#ifndef VCAST_VXWORKS
#ifndef VCAST_NO_SETJMP
    int VCAST_TI_9_96_jmpval;
    VCAST_TI_9_96_jmpval = setjmp ( VCAST_env );
    vcast_is_in_union = vCAST_false;
    if ( VCAST_TI_9_96_jmpval == 0 ) {
      vcast_is_in_union = vCAST_true;
#endif /* VCAST_VXWORKS */
#endif /* VCAST_NO_SETJMP */
      switch ( vcast_get_param () ) { /* Choose field member */
        /* Setting member variable vcast_param->_c */
        case 1: { 
          VCAST_TI_9_76 ( ((unsigned char *)(vcast_param->_c)));
          break; /* end case 1*/
        } /* end case */
        /* Setting member variable vcast_param->cemcem_lin1fr06_cem_lin1 */
        case 2: { 
          VCAST_TI_9_56 ( ((_c_CemCem_Lin1Fr06_CEM_LIN1_msgType *)(&(vcast_param->cemcem_lin1fr06_cem_lin1))));
          break; /* end case 2*/
        } /* end case */
        default:
          vCAST_TOOL_ERROR = vCAST_true;
      } /* end switch */ 
#ifndef VCAST_VXWORKS
#ifndef VCAST_NO_SETJMP
    } else if ( vCAST_COMMAND == vCAST_PRINT )
      vectorcast_fprint_string(vCAST_OUTPUT_FILE,"invalid address\n");
#endif /* VCAST_VXWORKS */
#endif /* VCAST_NO_SETJMP */
  }
#endif /*((defined(VCAST_NO_TYPE_SUPPORT))||(defined(VCAST_NO_UNION_SUPPORT)))*/

} /* end VCAST_TI_9_55 */
#endif /*(defined(VCAST_NO_TYPE_SUPPORT))*/


/* A typedef */
#if (defined(VCAST_NO_TYPE_SUPPORT))
void VCAST_TI_9_19 ( _c_CemCem_Lin1Fr05_CEM_LIN1_buf *vcast_param ) 
{
  /* User code: type is not supported */
  vcast_not_supported();
} /* end VCAST_TI_9_19 */
#else /*(defined(VCAST_NO_TYPE_SUPPORT))*/
void VCAST_TI_9_19 ( _c_CemCem_Lin1Fr05_CEM_LIN1_buf *vcast_param ) 
{
#if ((defined(VCAST_NO_TYPE_SUPPORT))||(defined(VCAST_NO_UNION_SUPPORT)))
  /* User code: type is not supported */
  vcast_not_supported();
#else /*((defined(VCAST_NO_TYPE_SUPPORT))||(defined(VCAST_NO_UNION_SUPPORT)))*/
  {
#ifndef VCAST_VXWORKS
#ifndef VCAST_NO_SETJMP
    int VCAST_TI_9_98_jmpval;
    VCAST_TI_9_98_jmpval = setjmp ( VCAST_env );
    vcast_is_in_union = vCAST_false;
    if ( VCAST_TI_9_98_jmpval == 0 ) {
      vcast_is_in_union = vCAST_true;
#endif /* VCAST_VXWORKS */
#endif /* VCAST_NO_SETJMP */
      switch ( vcast_get_param () ) { /* Choose field member */
        /* Setting member variable vcast_param->_c */
        case 1: { 
          VCAST_TI_9_50 ( ((unsigned char *)(vcast_param->_c)));
          break; /* end case 1*/
        } /* end case */
        /* Setting member variable vcast_param->cemcem_lin1fr05_cem_lin1 */
        case 2: { 
          VCAST_TI_9_20 ( ((_c_CemCem_Lin1Fr05_CEM_LIN1_msgType *)(&(vcast_param->cemcem_lin1fr05_cem_lin1))));
          break; /* end case 2*/
        } /* end case */
        default:
          vCAST_TOOL_ERROR = vCAST_true;
      } /* end switch */ 
#ifndef VCAST_VXWORKS
#ifndef VCAST_NO_SETJMP
    } else if ( vCAST_COMMAND == vCAST_PRINT )
      vectorcast_fprint_string(vCAST_OUTPUT_FILE,"invalid address\n");
#endif /* VCAST_VXWORKS */
#endif /* VCAST_NO_SETJMP */
  }
#endif /*((defined(VCAST_NO_TYPE_SUPPORT))||(defined(VCAST_NO_UNION_SUPPORT)))*/

} /* end VCAST_TI_9_19 */
#endif /*(defined(VCAST_NO_TYPE_SUPPORT))*/


/* A typedef */
#if (defined(VCAST_NO_TYPE_SUPPORT))
void VCAST_TI_9_53 ( _c_CemCem_Lin1Fr04_CEM_LIN1_buf *vcast_param ) 
{
  /* User code: type is not supported */
  vcast_not_supported();
} /* end VCAST_TI_9_53 */
#else /*(defined(VCAST_NO_TYPE_SUPPORT))*/
void VCAST_TI_9_53 ( _c_CemCem_Lin1Fr04_CEM_LIN1_buf *vcast_param ) 
{
#if ((defined(VCAST_NO_TYPE_SUPPORT))||(defined(VCAST_NO_UNION_SUPPORT)))
  /* User code: type is not supported */
  vcast_not_supported();
#else /*((defined(VCAST_NO_TYPE_SUPPORT))||(defined(VCAST_NO_UNION_SUPPORT)))*/
  {
#ifndef VCAST_VXWORKS
#ifndef VCAST_NO_SETJMP
    int VCAST_TI_9_100_jmpval;
    VCAST_TI_9_100_jmpval = setjmp ( VCAST_env );
    vcast_is_in_union = vCAST_false;
    if ( VCAST_TI_9_100_jmpval == 0 ) {
      vcast_is_in_union = vCAST_true;
#endif /* VCAST_VXWORKS */
#endif /* VCAST_NO_SETJMP */
      switch ( vcast_get_param () ) { /* Choose field member */
        /* Setting member variable vcast_param->_c */
        case 1: { 
          VCAST_TI_9_50 ( ((unsigned char *)(vcast_param->_c)));
          break; /* end case 1*/
        } /* end case */
        /* Setting member variable vcast_param->cemcem_lin1fr04_cem_lin1 */
        case 2: { 
          VCAST_TI_9_54 ( ((_c_CemCem_Lin1Fr04_CEM_LIN1_msgType *)(&(vcast_param->cemcem_lin1fr04_cem_lin1))));
          break; /* end case 2*/
        } /* end case */
        default:
          vCAST_TOOL_ERROR = vCAST_true;
      } /* end switch */ 
#ifndef VCAST_VXWORKS
#ifndef VCAST_NO_SETJMP
    } else if ( vCAST_COMMAND == vCAST_PRINT )
      vectorcast_fprint_string(vCAST_OUTPUT_FILE,"invalid address\n");
#endif /* VCAST_VXWORKS */
#endif /* VCAST_NO_SETJMP */
  }
#endif /*((defined(VCAST_NO_TYPE_SUPPORT))||(defined(VCAST_NO_UNION_SUPPORT)))*/

} /* end VCAST_TI_9_53 */
#endif /*(defined(VCAST_NO_TYPE_SUPPORT))*/


/* A typedef */
#if (defined(VCAST_NO_TYPE_SUPPORT))
void VCAST_TI_9_48 ( _c_CemCem_Lin1Fr03_CEM_LIN1_buf *vcast_param ) 
{
  /* User code: type is not supported */
  vcast_not_supported();
} /* end VCAST_TI_9_48 */
#else /*(defined(VCAST_NO_TYPE_SUPPORT))*/
void VCAST_TI_9_48 ( _c_CemCem_Lin1Fr03_CEM_LIN1_buf *vcast_param ) 
{
#if ((defined(VCAST_NO_TYPE_SUPPORT))||(defined(VCAST_NO_UNION_SUPPORT)))
  /* User code: type is not supported */
  vcast_not_supported();
#else /*((defined(VCAST_NO_TYPE_SUPPORT))||(defined(VCAST_NO_UNION_SUPPORT)))*/
  {
#ifndef VCAST_VXWORKS
#ifndef VCAST_NO_SETJMP
    int VCAST_TI_9_102_jmpval;
    VCAST_TI_9_102_jmpval = setjmp ( VCAST_env );
    vcast_is_in_union = vCAST_false;
    if ( VCAST_TI_9_102_jmpval == 0 ) {
      vcast_is_in_union = vCAST_true;
#endif /* VCAST_VXWORKS */
#endif /* VCAST_NO_SETJMP */
      switch ( vcast_get_param () ) { /* Choose field member */
        /* Setting member variable vcast_param->_c */
        case 1: { 
          VCAST_TI_9_35 ( ((unsigned char *)(vcast_param->_c)));
          break; /* end case 1*/
        } /* end case */
        /* Setting member variable vcast_param->cemcem_lin1fr03_cem_lin1 */
        case 2: { 
          VCAST_TI_9_49 ( ((_c_CemCem_Lin1Fr03_CEM_LIN1_msgType *)(&(vcast_param->cemcem_lin1fr03_cem_lin1))));
          break; /* end case 2*/
        } /* end case */
        default:
          vCAST_TOOL_ERROR = vCAST_true;
      } /* end switch */ 
#ifndef VCAST_VXWORKS
#ifndef VCAST_NO_SETJMP
    } else if ( vCAST_COMMAND == vCAST_PRINT )
      vectorcast_fprint_string(vCAST_OUTPUT_FILE,"invalid address\n");
#endif /* VCAST_VXWORKS */
#endif /* VCAST_NO_SETJMP */
  }
#endif /*((defined(VCAST_NO_TYPE_SUPPORT))||(defined(VCAST_NO_UNION_SUPPORT)))*/

} /* end VCAST_TI_9_48 */
#endif /*(defined(VCAST_NO_TYPE_SUPPORT))*/


/* A typedef */
#if (defined(VCAST_NO_TYPE_SUPPORT))
void VCAST_TI_9_51 ( _c_CemCem_Lin1Fr02_CEM_LIN1_buf *vcast_param ) 
{
  /* User code: type is not supported */
  vcast_not_supported();
} /* end VCAST_TI_9_51 */
#else /*(defined(VCAST_NO_TYPE_SUPPORT))*/
void VCAST_TI_9_51 ( _c_CemCem_Lin1Fr02_CEM_LIN1_buf *vcast_param ) 
{
#if ((defined(VCAST_NO_TYPE_SUPPORT))||(defined(VCAST_NO_UNION_SUPPORT)))
  /* User code: type is not supported */
  vcast_not_supported();
#else /*((defined(VCAST_NO_TYPE_SUPPORT))||(defined(VCAST_NO_UNION_SUPPORT)))*/
  {
#ifndef VCAST_VXWORKS
#ifndef VCAST_NO_SETJMP
    int VCAST_TI_9_104_jmpval;
    VCAST_TI_9_104_jmpval = setjmp ( VCAST_env );
    vcast_is_in_union = vCAST_false;
    if ( VCAST_TI_9_104_jmpval == 0 ) {
      vcast_is_in_union = vCAST_true;
#endif /* VCAST_VXWORKS */
#endif /* VCAST_NO_SETJMP */
      switch ( vcast_get_param () ) { /* Choose field member */
        /* Setting member variable vcast_param->_c */
        case 1: { 
          VCAST_TI_9_50 ( ((unsigned char *)(vcast_param->_c)));
          break; /* end case 1*/
        } /* end case */
        /* Setting member variable vcast_param->cemcem_lin1fr02_cem_lin1 */
        case 2: { 
          VCAST_TI_9_52 ( ((_c_CemCem_Lin1Fr02_CEM_LIN1_msgType *)(&(vcast_param->cemcem_lin1fr02_cem_lin1))));
          break; /* end case 2*/
        } /* end case */
        default:
          vCAST_TOOL_ERROR = vCAST_true;
      } /* end switch */ 
#ifndef VCAST_VXWORKS
#ifndef VCAST_NO_SETJMP
    } else if ( vCAST_COMMAND == vCAST_PRINT )
      vectorcast_fprint_string(vCAST_OUTPUT_FILE,"invalid address\n");
#endif /* VCAST_VXWORKS */
#endif /* VCAST_NO_SETJMP */
  }
#endif /*((defined(VCAST_NO_TYPE_SUPPORT))||(defined(VCAST_NO_UNION_SUPPORT)))*/

} /* end VCAST_TI_9_51 */
#endif /*(defined(VCAST_NO_TYPE_SUPPORT))*/


/* A typedef */
#if (defined(VCAST_NO_TYPE_SUPPORT))
void VCAST_TI_9_11 ( _c_CemCem_Lin1Fr01_CEM_LIN1_buf *vcast_param ) 
{
  /* User code: type is not supported */
  vcast_not_supported();
} /* end VCAST_TI_9_11 */
#else /*(defined(VCAST_NO_TYPE_SUPPORT))*/
void VCAST_TI_9_11 ( _c_CemCem_Lin1Fr01_CEM_LIN1_buf *vcast_param ) 
{
#if ((defined(VCAST_NO_TYPE_SUPPORT))||(defined(VCAST_NO_UNION_SUPPORT)))
  /* User code: type is not supported */
  vcast_not_supported();
#else /*((defined(VCAST_NO_TYPE_SUPPORT))||(defined(VCAST_NO_UNION_SUPPORT)))*/
  {
#ifndef VCAST_VXWORKS
#ifndef VCAST_NO_SETJMP
    int VCAST_TI_9_106_jmpval;
    VCAST_TI_9_106_jmpval = setjmp ( VCAST_env );
    vcast_is_in_union = vCAST_false;
    if ( VCAST_TI_9_106_jmpval == 0 ) {
      vcast_is_in_union = vCAST_true;
#endif /* VCAST_VXWORKS */
#endif /* VCAST_NO_SETJMP */
      switch ( vcast_get_param () ) { /* Choose field member */
        /* Setting member variable vcast_param->_c */
        case 1: { 
          VCAST_TI_9_107 ( ((unsigned char *)(vcast_param->_c)));
          break; /* end case 1*/
        } /* end case */
        /* Setting member variable vcast_param->cemcem_lin1fr01_cem_lin1 */
        case 2: { 
          VCAST_TI_9_12 ( ((_c_CemCem_Lin1Fr01_CEM_LIN1_msgType *)(&(vcast_param->cemcem_lin1fr01_cem_lin1))));
          break; /* end case 2*/
        } /* end case */
        default:
          vCAST_TOOL_ERROR = vCAST_true;
      } /* end switch */ 
#ifndef VCAST_VXWORKS
#ifndef VCAST_NO_SETJMP
    } else if ( vCAST_COMMAND == vCAST_PRINT )
      vectorcast_fprint_string(vCAST_OUTPUT_FILE,"invalid address\n");
#endif /* VCAST_VXWORKS */
#endif /* VCAST_NO_SETJMP */
  }
#endif /*((defined(VCAST_NO_TYPE_SUPPORT))||(defined(VCAST_NO_UNION_SUPPORT)))*/

} /* end VCAST_TI_9_11 */
#endif /*(defined(VCAST_NO_TYPE_SUPPORT))*/


/* A typedef */
#if (defined(VCAST_NO_TYPE_SUPPORT))
void VCAST_TI_9_15 ( volatile RS_Flag *vcast_param ) 
{
  /* User code: type is not supported */
  vcast_not_supported();
} /* end VCAST_TI_9_15 */
#else /*(defined(VCAST_NO_TYPE_SUPPORT))*/
void VCAST_TI_9_15 ( volatile RS_Flag *vcast_param ) 
{
#if ((defined(VCAST_NO_TYPE_SUPPORT))||(defined(VCAST_NO_UNION_SUPPORT)))
  /* User code: type is not supported */
  vcast_not_supported();
#else /*((defined(VCAST_NO_TYPE_SUPPORT))||(defined(VCAST_NO_UNION_SUPPORT)))*/
  {
#ifndef VCAST_VXWORKS
#ifndef VCAST_NO_SETJMP
    int VCAST_TI_9_109_jmpval;
    VCAST_TI_9_109_jmpval = setjmp ( VCAST_env );
    vcast_is_in_union = vCAST_false;
    if ( VCAST_TI_9_109_jmpval == 0 ) {
      vcast_is_in_union = vCAST_true;
#endif /* VCAST_VXWORKS */
#endif /* VCAST_NO_SETJMP */
      switch ( vcast_get_param () ) { /* Choose field member */
        /* Setting member variable vcast_param->Bit */
        case 1: { 
          VCAST_TI_9_16 ( ((RS_Bit_Feld *)(&(vcast_param->Bit))));
          break; /* end case 1*/
        } /* end case */
        /* Setting member variable vcast_param->AllBit */
        case 2: { 
          VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->AllBit))));
          break; /* end case 2*/
        } /* end case */
        default:
          vCAST_TOOL_ERROR = vCAST_true;
      } /* end switch */ 
#ifndef VCAST_VXWORKS
#ifndef VCAST_NO_SETJMP
    } else if ( vCAST_COMMAND == vCAST_PRINT )
      vectorcast_fprint_string(vCAST_OUTPUT_FILE,"invalid address\n");
#endif /* VCAST_VXWORKS */
#endif /* VCAST_NO_SETJMP */
  }
#endif /*((defined(VCAST_NO_TYPE_SUPPORT))||(defined(VCAST_NO_UNION_SUPPORT)))*/

} /* end VCAST_TI_9_15 */
#endif /*(defined(VCAST_NO_TYPE_SUPPORT))*/


/* An array */
#if (defined(VCAST_NO_TYPE_SUPPORT))
void VCAST_TI_9_43 ( unsigned char vcast_param[5] ) 
{
  /* User code: type is not supported */
  vcast_not_supported();
} /* end VCAST_TI_9_43 */
#else /*(defined(VCAST_NO_TYPE_SUPPORT))*/
void VCAST_TI_9_43 ( unsigned char vcast_param[5] ) 
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
      vectorcast_fprint_integer (vCAST_OUTPUT_FILE,5);
      vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
      vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n");
    } else {
      int VCAST_TI_9_43_upper = 5;
      for (VCAST_TI_9_43_array_index=0; VCAST_TI_9_43_array_index< VCAST_TI_9_43_upper; VCAST_TI_9_43_array_index++){
        if ( (VCAST_TI_9_43_index >= VCAST_TI_9_43_first) && ( VCAST_TI_9_43_index <= VCAST_TI_9_43_last)){
          if ( VCAST_TI_9_43_is_string )
            VCAST_TI_STRING ( (char**)&vcast_param, sizeof ( vcast_param ), 1,VCAST_TI_9_43_upper);
          else
            VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param[VCAST_TI_9_43_index]))));
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
#endif /*(defined(VCAST_NO_TYPE_SUPPORT))*/


/* An array */
#if (defined(VCAST_NO_TYPE_SUPPORT))
void VCAST_TI_9_29 ( ASIC_ALI_Meas_t vcast_param[9] ) 
{
  /* User code: type is not supported */
  vcast_not_supported();
} /* end VCAST_TI_9_29 */
#else /*(defined(VCAST_NO_TYPE_SUPPORT))*/
void VCAST_TI_9_29 ( ASIC_ALI_Meas_t vcast_param[9] ) 
{
  {
    int VCAST_TI_9_29_array_index = 0;
    int VCAST_TI_9_29_index = 0;
    int VCAST_TI_9_29_first, VCAST_TI_9_29_last;
    int VCAST_TI_9_29_more_data; /* true if there is more data in the current command */
    int VCAST_TI_9_29_local_field = 0;
    int VCAST_TI_9_29_value_printed = 0;


    vcast_get_range_value (&VCAST_TI_9_29_first, &VCAST_TI_9_29_last, &VCAST_TI_9_29_more_data);
    VCAST_TI_9_29_local_field = vCAST_DATA_FIELD;
    if ( vCAST_SIZE && (!VCAST_TI_9_29_more_data)) { /* get the size of the array */
      vectorcast_fprint_integer (vCAST_OUTPUT_FILE,9);
      vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
      vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n");
    } else {
      int VCAST_TI_9_29_upper = 9;
      for (VCAST_TI_9_29_array_index=0; VCAST_TI_9_29_array_index< VCAST_TI_9_29_upper; VCAST_TI_9_29_array_index++){
        if ( (VCAST_TI_9_29_index >= VCAST_TI_9_29_first) && ( VCAST_TI_9_29_index <= VCAST_TI_9_29_last)){
          VCAST_TI_9_30 ( ((ASIC_ALI_Meas_t *)(&(vcast_param[VCAST_TI_9_29_index]))));
          VCAST_TI_9_29_value_printed = 1;
          vCAST_DATA_FIELD = VCAST_TI_9_29_local_field;
        } /* if */
        if (VCAST_TI_9_29_index >= VCAST_TI_9_29_last)
          break;
        VCAST_TI_9_29_index++;
      } /* loop */
      if ((vCAST_COMMAND == vCAST_PRINT)&&(!VCAST_TI_9_29_value_printed))
        vectorcast_fprint_string(vCAST_OUTPUT_FILE,"<<past end of array>>\n");
    } /* if */
  }
} /* end VCAST_TI_9_29 */
#endif /*(defined(VCAST_NO_TYPE_SUPPORT))*/


/* An array */
#if (defined(VCAST_NO_TYPE_SUPPORT))
void VCAST_TI_9_42 ( unsigned long vcast_param[2] ) 
{
  /* User code: type is not supported */
  vcast_not_supported();
} /* end VCAST_TI_9_42 */
#else /*(defined(VCAST_NO_TYPE_SUPPORT))*/
void VCAST_TI_9_42 ( unsigned long vcast_param[2] ) 
{
  {
    int VCAST_TI_9_42_array_index = 0;
    int VCAST_TI_9_42_index = 0;
    int VCAST_TI_9_42_first, VCAST_TI_9_42_last;
    int VCAST_TI_9_42_more_data; /* true if there is more data in the current command */
    int VCAST_TI_9_42_local_field = 0;
    int VCAST_TI_9_42_value_printed = 0;


    vcast_get_range_value (&VCAST_TI_9_42_first, &VCAST_TI_9_42_last, &VCAST_TI_9_42_more_data);
    VCAST_TI_9_42_local_field = vCAST_DATA_FIELD;
    if ( vCAST_SIZE && (!VCAST_TI_9_42_more_data)) { /* get the size of the array */
      vectorcast_fprint_integer (vCAST_OUTPUT_FILE,2);
      vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
      vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n");
    } else {
      int VCAST_TI_9_42_upper = 2;
      for (VCAST_TI_9_42_array_index=0; VCAST_TI_9_42_array_index< VCAST_TI_9_42_upper; VCAST_TI_9_42_array_index++){
        if ( (VCAST_TI_9_42_index >= VCAST_TI_9_42_first) && ( VCAST_TI_9_42_index <= VCAST_TI_9_42_last)){
          VCAST_TI_9_31 ( ((unsigned long *)(&(vcast_param[VCAST_TI_9_42_index]))));
          VCAST_TI_9_42_value_printed = 1;
          vCAST_DATA_FIELD = VCAST_TI_9_42_local_field;
        } /* if */
        if (VCAST_TI_9_42_index >= VCAST_TI_9_42_last)
          break;
        VCAST_TI_9_42_index++;
      } /* loop */
      if ((vCAST_COMMAND == vCAST_PRINT)&&(!VCAST_TI_9_42_value_printed))
        vectorcast_fprint_string(vCAST_OUTPUT_FILE,"<<past end of array>>\n");
    } /* if */
  }
} /* end VCAST_TI_9_42 */
#endif /*(defined(VCAST_NO_TYPE_SUPPORT))*/


/* An array */
#if (defined(VCAST_NO_TYPE_SUPPORT))
void VCAST_TI_9_41 ( unsigned long vcast_param[10] ) 
{
  /* User code: type is not supported */
  vcast_not_supported();
} /* end VCAST_TI_9_41 */
#else /*(defined(VCAST_NO_TYPE_SUPPORT))*/
void VCAST_TI_9_41 ( unsigned long vcast_param[10] ) 
{
  {
    int VCAST_TI_9_41_array_index = 0;
    int VCAST_TI_9_41_index = 0;
    int VCAST_TI_9_41_first, VCAST_TI_9_41_last;
    int VCAST_TI_9_41_more_data; /* true if there is more data in the current command */
    int VCAST_TI_9_41_local_field = 0;
    int VCAST_TI_9_41_value_printed = 0;


    vcast_get_range_value (&VCAST_TI_9_41_first, &VCAST_TI_9_41_last, &VCAST_TI_9_41_more_data);
    VCAST_TI_9_41_local_field = vCAST_DATA_FIELD;
    if ( vCAST_SIZE && (!VCAST_TI_9_41_more_data)) { /* get the size of the array */
      vectorcast_fprint_integer (vCAST_OUTPUT_FILE,10);
      vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
      vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n");
    } else {
      int VCAST_TI_9_41_upper = 10;
      for (VCAST_TI_9_41_array_index=0; VCAST_TI_9_41_array_index< VCAST_TI_9_41_upper; VCAST_TI_9_41_array_index++){
        if ( (VCAST_TI_9_41_index >= VCAST_TI_9_41_first) && ( VCAST_TI_9_41_index <= VCAST_TI_9_41_last)){
          VCAST_TI_9_31 ( ((unsigned long *)(&(vcast_param[VCAST_TI_9_41_index]))));
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
#endif /*(defined(VCAST_NO_TYPE_SUPPORT))*/


/* An integer */
#if (defined(VCAST_NO_TYPE_SUPPORT))
void VCAST_TI_9_31 ( unsigned long *vcast_param ) 
{
  /* User code: type is not supported */
  vcast_not_supported();
} /* end VCAST_TI_9_31 */
#else /*(defined(VCAST_NO_TYPE_SUPPORT))*/
void VCAST_TI_9_31 ( unsigned long *vcast_param ) 
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
    *vcast_param = ULONG_MIN;
    break;
  case vCAST_MID_VAL :
    *vcast_param = (ULONG_MIN / 2) + (ULONG_MAX / 2);
    break;
  case vCAST_LAST_VAL :
    *vcast_param = ULONG_MAX;
    break;
  case vCAST_MIN_MINUS_1_VAL :
    *vcast_param = ULONG_MIN;
    *vcast_param = *vcast_param - 1;
    break;
  case vCAST_MAX_PLUS_1_VAL :
    *vcast_param = ULONG_MAX;
    *vcast_param = *vcast_param + 1;
    break;
  case vCAST_ZERO_VAL :
    *vcast_param = 0;
    break;
  default:
    break;
} /* end switch */
} /* end VCAST_TI_9_31 */
#endif /*(defined(VCAST_NO_TYPE_SUPPORT))*/


/* An array */
#if (defined(VCAST_NO_TYPE_SUPPORT))
void VCAST_TI_9_50 ( unsigned char vcast_param[7] ) 
{
  /* User code: type is not supported */
  vcast_not_supported();
} /* end VCAST_TI_9_50 */
#else /*(defined(VCAST_NO_TYPE_SUPPORT))*/
void VCAST_TI_9_50 ( unsigned char vcast_param[7] ) 
{
  {
    int VCAST_TI_9_50_array_index = 0;
    int VCAST_TI_9_50_index = 0;
    int VCAST_TI_9_50_first, VCAST_TI_9_50_last;
    int VCAST_TI_9_50_more_data; /* true if there is more data in the current command */
    int VCAST_TI_9_50_local_field = 0;
    int VCAST_TI_9_50_value_printed = 0;
    int VCAST_TI_9_50_is_string = (VCAST_FIND_INDEX()==-1);


    vcast_get_range_value (&VCAST_TI_9_50_first, &VCAST_TI_9_50_last, &VCAST_TI_9_50_more_data);
    VCAST_TI_9_50_local_field = vCAST_DATA_FIELD;
    if ( vCAST_SIZE && (!VCAST_TI_9_50_more_data)) { /* get the size of the array */
      vectorcast_fprint_integer (vCAST_OUTPUT_FILE,7);
      vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
      vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n");
    } else {
      int VCAST_TI_9_50_upper = 7;
      for (VCAST_TI_9_50_array_index=0; VCAST_TI_9_50_array_index< VCAST_TI_9_50_upper; VCAST_TI_9_50_array_index++){
        if ( (VCAST_TI_9_50_index >= VCAST_TI_9_50_first) && ( VCAST_TI_9_50_index <= VCAST_TI_9_50_last)){
          if ( VCAST_TI_9_50_is_string )
            VCAST_TI_STRING ( (char**)&vcast_param, sizeof ( vcast_param ), 1,VCAST_TI_9_50_upper);
          else
            VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param[VCAST_TI_9_50_index]))));
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
#endif /*(defined(VCAST_NO_TYPE_SUPPORT))*/


/* A pointer */
#if (defined(VCAST_NO_TYPE_SUPPORT))
void VCAST_TI_9_1 ( unsigned char **vcast_param ) 
{
  /* User code: type is not supported */
  vcast_not_supported();
} /* end VCAST_TI_9_1 */
#else /*(defined(VCAST_NO_TYPE_SUPPORT))*/
void VCAST_TI_9_1 ( unsigned char **vcast_param ) 
{
  {
    int VCAST_TI_9_1_index;
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
          int VCAST_TI_9_1_array_size = (int) vCAST_VALUE;
          if (VCAST_FIND_INDEX() == -1) {
            void **VCAST_TI_9_1_memory_ptr = (void**)vcast_param;
            *VCAST_TI_9_1_memory_ptr = (void*)VCAST_malloc(VCAST_TI_9_1_array_size*(sizeof(unsigned char )));
            VCAST_memset((void*)*vcast_param, 0x0, VCAST_TI_9_1_array_size*(sizeof(unsigned char )));
#ifndef VCAST_NO_MALLOC
            VCAST_Add_Allocated_Data(*VCAST_TI_9_1_memory_ptr);
#endif
          }
        } else if (vCAST_VALUE_NUL == vCAST_true && vcast_proc_handles_command(1)) {
          if (VCAST_FIND_INDEX() == -1)
            *vcast_param = 0;
        } else {
          if (VCAST_FIND_INDEX() == -1 )
            VCAST_TI_STRING ( (char**)vcast_param, sizeof ( vcast_param ), 0,-1);
          else {
            VCAST_TI_9_1_index = vcast_get_param();
            VCAST_TI_9_9 ( ((unsigned char *)(&((*vcast_param)[VCAST_TI_9_1_index]))));
          }
        }
      }
    }
  }
} /* end VCAST_TI_9_1 */
#endif /*(defined(VCAST_NO_TYPE_SUPPORT))*/


/* An array */
#if (defined(VCAST_NO_TYPE_SUPPORT))
void VCAST_TI_9_65 ( unsigned char vcast_param[93] ) 
{
  /* User code: type is not supported */
  vcast_not_supported();
} /* end VCAST_TI_9_65 */
#else /*(defined(VCAST_NO_TYPE_SUPPORT))*/
void VCAST_TI_9_65 ( unsigned char vcast_param[93] ) 
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
      vectorcast_fprint_integer (vCAST_OUTPUT_FILE,93);
      vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
      vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n");
    } else {
      int VCAST_TI_9_65_upper = 93;
      for (VCAST_TI_9_65_array_index=0; VCAST_TI_9_65_array_index< VCAST_TI_9_65_upper; VCAST_TI_9_65_array_index++){
        if ( (VCAST_TI_9_65_index >= VCAST_TI_9_65_first) && ( VCAST_TI_9_65_index <= VCAST_TI_9_65_last)){
          if ( VCAST_TI_9_65_is_string )
            VCAST_TI_STRING ( (char**)&vcast_param, sizeof ( vcast_param ), 1,VCAST_TI_9_65_upper);
          else
            VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param[VCAST_TI_9_65_index]))));
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
#endif /*(defined(VCAST_NO_TYPE_SUPPORT))*/


/* A typedef */
#if (defined(VCAST_NO_TYPE_SUPPORT))
void VCAST_TI_9_14 ( s_rb_EEPROMStruct_PD_g *vcast_param ) 
{
  /* User code: type is not supported */
  vcast_not_supported();
} /* end VCAST_TI_9_14 */
#else /*(defined(VCAST_NO_TYPE_SUPPORT))*/
void VCAST_TI_9_14 ( s_rb_EEPROMStruct_PD_g *vcast_param ) 
{
#if (defined(VCAST_NO_TYPE_SUPPORT))
  /* User code: type is not supported */
  vcast_not_supported();
#else /*(defined(VCAST_NO_TYPE_SUPPORT))*/
  {
    switch ( vcast_get_param () ) { /* Choose field member */
      /* Setting member variable vcast_param->EEKodierbyte2_g */
      case 1: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->EEKodierbyte2_g))));
        break; /* end case 1*/
      } /* end case */
      /* Setting member variable vcast_param->EEKodierbyte1_g */
      case 2: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->EEKodierbyte1_g))));
        break; /* end case 2*/
      } /* end case */
      /* Setting member variable vcast_param->EEKodierbyte0_g */
      case 3: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->EEKodierbyte0_g))));
        break; /* end case 3*/
      } /* end case */
      /* Setting member variable vcast_param->ALS1_4_Setting_g */
      case 4: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->ALS1_4_Setting_g))));
        break; /* end case 4*/
      } /* end case */
      /* Setting member variable vcast_param->ALS5_6_INREC_Setting_g */
      case 5: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->ALS5_6_INREC_Setting_g))));
        break; /* end case 5*/
      } /* end case */
      /* Setting member variable vcast_param->ASIC_DIAGV_g */
      case 6: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->ASIC_DIAGV_g))));
        break; /* end case 6*/
      } /* end case */
      /* Setting member variable vcast_param->A_Factor_ALS1_g */
      case 7: { 
        VCAST_TI_9_6 ( ((unsigned *)(&(vcast_param->A_Factor_ALS1_g))));
        break; /* end case 7*/
      } /* end case */
      /* Setting member variable vcast_param->A_Factor_ALS2_g */
      case 8: { 
        VCAST_TI_9_6 ( ((unsigned *)(&(vcast_param->A_Factor_ALS2_g))));
        break; /* end case 8*/
      } /* end case */
      /* Setting member variable vcast_param->A_Factor_ALS3_g */
      case 9: { 
        VCAST_TI_9_6 ( ((unsigned *)(&(vcast_param->A_Factor_ALS3_g))));
        break; /* end case 9*/
      } /* end case */
      /* Setting member variable vcast_param->A_Factor_ALS4_g */
      case 10: { 
        VCAST_TI_9_6 ( ((unsigned *)(&(vcast_param->A_Factor_ALS4_g))));
        break; /* end case 10*/
      } /* end case */
      /* Setting member variable vcast_param->A_Factor_ALS5_g */
      case 11: { 
        VCAST_TI_9_6 ( ((unsigned *)(&(vcast_param->A_Factor_ALS5_g))));
        break; /* end case 11*/
      } /* end case */
      /* Setting member variable vcast_param->A_Factor_ALS6_g */
      case 12: { 
        VCAST_TI_9_6 ( ((unsigned *)(&(vcast_param->A_Factor_ALS6_g))));
        break; /* end case 12*/
      } /* end case */
      /* Setting member variable vcast_param->A_Factor_INREC_g */
      case 13: { 
        VCAST_TI_9_6 ( ((unsigned *)(&(vcast_param->A_Factor_INREC_g))));
        break; /* end case 13*/
      } /* end case */
      /* Setting member variable vcast_param->B_Factor_Iref_Lo_Gain_Lo_g */
      case 14: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->B_Factor_Iref_Lo_Gain_Lo_g))));
        break; /* end case 14*/
      } /* end case */
      /* Setting member variable vcast_param->B_Factor_Iref_Lo_Gain_Hi_g */
      case 15: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->B_Factor_Iref_Lo_Gain_Hi_g))));
        break; /* end case 15*/
      } /* end case */
      /* Setting member variable vcast_param->B_Factor_Iref_Hi_Gain_Lo_g */
      case 16: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->B_Factor_Iref_Hi_Gain_Lo_g))));
        break; /* end case 16*/
      } /* end case */
      /* Setting member variable vcast_param->B_Factor_Iref_Hi_Gain_Hi_g */
      case 17: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->B_Factor_Iref_Hi_Gain_Hi_g))));
        break; /* end case 17*/
      } /* end case */
      /* Setting member variable vcast_param->CRC_Checksum_calibration_g */
      case 18: { 
        VCAST_TI_9_6 ( ((unsigned *)(&(vcast_param->CRC_Checksum_calibration_g))));
        break; /* end case 18*/
      } /* end case */
      /* Setting member variable vcast_param->Standby_rain_measurement_1_g */
      case 19: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->Standby_rain_measurement_1_g))));
        break; /* end case 19*/
      } /* end case */
      /* Setting member variable vcast_param->Standby_rain_measurement_2_g */
      case 20: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->Standby_rain_measurement_2_g))));
        break; /* end case 20*/
      } /* end case */
      /* Setting member variable vcast_param->Standby_rain_measurement_3_g */
      case 21: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->Standby_rain_measurement_3_g))));
        break; /* end case 21*/
      } /* end case */
      /* Setting member variable vcast_param->Standby_rain_measurement_4_g */
      case 22: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->Standby_rain_measurement_4_g))));
        break; /* end case 22*/
      } /* end case */
      /* Setting member variable vcast_param->Standby_rain_measurement_5_g */
      case 23: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->Standby_rain_measurement_5_g))));
        break; /* end case 23*/
      } /* end case */
      /* Setting member variable vcast_param->Standby_rain_measurement_6_g */
      case 24: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->Standby_rain_measurement_6_g))));
        break; /* end case 24*/
      } /* end case */
      /* Setting member variable vcast_param->ASIC_Sched_Config_g */
      case 25: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->ASIC_Sched_Config_g))));
        break; /* end case 25*/
      } /* end case */
      /* Setting member variable vcast_param->ASIC_LCTR_g */
      case 26: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->ASIC_LCTR_g))));
        break; /* end case 26*/
      } /* end case */
      /* Setting member variable vcast_param->NO_RAIN_PRESENT_THRSH_HB_g */
      case 27: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->NO_RAIN_PRESENT_THRSH_HB_g))));
        break; /* end case 27*/
      } /* end case */
      /* Setting member variable vcast_param->NO_RAIN_PRESENT_THRSH_LB_g */
      case 28: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->NO_RAIN_PRESENT_THRSH_LB_g))));
        break; /* end case 28*/
      } /* end case */
      /* Setting member variable vcast_param->STBY_REGV_Imbalance_g */
      case 29: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->STBY_REGV_Imbalance_g))));
        break; /* end case 29*/
      } /* end case */
      /* Setting member variable vcast_param->RSControlFlags */
      case 30: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->RSControlFlags))));
        break; /* end case 30*/
      } /* end case */
      /* Setting member variable vcast_param->EEPROM_Erase_Counter */
      case 31: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->EEPROM_Erase_Counter))));
        break; /* end case 31*/
      } /* end case */
      /* Setting member variable vcast_param->HardwareStand */
      case 32: { 
        VCAST_TI_9_61 ( ((unsigned char *)(vcast_param->HardwareStand)));
        break; /* end case 32*/
      } /* end case */
      /* Setting member variable vcast_param->Produktionsdaten */
      case 33: { 
        VCAST_TI_9_33 ( ((unsigned char *)(vcast_param->Produktionsdaten)));
        break; /* end case 33*/
      } /* end case */
      /* Setting member variable vcast_param->Audi_HW_Partnumber */
      case 34: { 
        VCAST_TI_9_35 ( ((unsigned char *)(vcast_param->Audi_HW_Partnumber)));
        break; /* end case 34*/
      } /* end case */
      /* Setting member variable vcast_param->NAD */
      case 35: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->NAD))));
        break; /* end case 35*/
      } /* end case */
      /* Setting member variable vcast_param->IDFSs_01 */
      case 36: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->IDFSs_01))));
        break; /* end case 36*/
      } /* end case */
      /* Setting member variable vcast_param->IDRLSs_01 */
      case 37: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->IDRLSs_01))));
        break; /* end case 37*/
      } /* end case */
      /* Setting member variable vcast_param->IDBCM1_LIN1_01 */
      case 38: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->IDBCM1_LIN1_01))));
        break; /* end case 38*/
      } /* end case */
      /* Setting member variable vcast_param->IDWWSs_01 */
      case 39: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->IDWWSs_01))));
        break; /* end case 39*/
      } /* end case */
      /* Setting member variable vcast_param->IDSOSES_01 */
      case 40: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->IDSOSES_01))));
        break; /* end case 40*/
      } /* end case */
      /* Setting member variable vcast_param->ASIC_RCTR_REG_g */
      case 41: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->ASIC_RCTR_REG_g))));
        break; /* end case 41*/
      } /* end case */
      /* Setting member variable vcast_param->ASIC_RFCTR_REG_g */
      case 42: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->ASIC_RFCTR_REG_g))));
        break; /* end case 42*/
      } /* end case */
      /* Setting member variable vcast_param->Error_Active_1_g */
      case 43: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->Error_Active_1_g))));
        break; /* end case 43*/
      } /* end case */
      /* Setting member variable vcast_param->Error_Active_2_g */
      case 44: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->Error_Active_2_g))));
        break; /* end case 44*/
      } /* end case */
      /* Setting member variable vcast_param->Error_Active_3_g */
      case 45: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->Error_Active_3_g))));
        break; /* end case 45*/
      } /* end case */
      /* Setting member variable vcast_param->Erase_counter */
      case 46: { 
        VCAST_TI_9_33 ( ((unsigned char *)(vcast_param->Erase_counter)));
        break; /* end case 46*/
      } /* end case */
      /* Setting member variable vcast_param->VariantID_g */
      case 47: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->VariantID_g))));
        break; /* end case 47*/
      } /* end case */
      /* Setting member variable vcast_param->FunctionID_g */
      case 48: { 
        VCAST_TI_9_6 ( ((unsigned *)(&(vcast_param->FunctionID_g))));
        break; /* end case 48*/
      } /* end case */
      /* Setting member variable vcast_param->IDERRDATA_01 */
      case 49: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->IDERRDATA_01))));
        break; /* end case 49*/
      } /* end case */
      /* Setting member variable vcast_param->IDSPARE_01 */
      case 50: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->IDSPARE_01))));
        break; /* end case 50*/
      } /* end case */
      /* Setting member variable vcast_param->IDRLSs_02 */
      case 51: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->IDRLSs_02))));
        break; /* end case 51*/
      } /* end case */
      /* Setting member variable vcast_param->IDBCM1_LIN1_02 */
      case 52: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->IDBCM1_LIN1_02))));
        break; /* end case 52*/
      } /* end case */
      /* Setting member variable vcast_param->HUD_Factor_g */
      case 53: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->HUD_Factor_g))));
        break; /* end case 53*/
      } /* end case */
      /* Setting member variable vcast_param->IDRLSs_03 */
      case 54: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->IDRLSs_03))));
        break; /* end case 54*/
      } /* end case */
      /* Setting member variable vcast_param->IDRLSs_04 */
      case 55: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->IDRLSs_04))));
        break; /* end case 55*/
      } /* end case */
      /* Setting member variable vcast_param->IDRLSs_05 */
      case 56: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->IDRLSs_05))));
        break; /* end case 56*/
      } /* end case */
      /* Setting member variable vcast_param->IDRLSs_06 */
      case 57: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->IDRLSs_06))));
        break; /* end case 57*/
      } /* end case */
      /* Setting member variable vcast_param->IDBCM1_LIN1_03 */
      case 58: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->IDBCM1_LIN1_03))));
        break; /* end case 58*/
      } /* end case */
      /* Setting member variable vcast_param->IDBCM1_LIN1_04 */
      case 59: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->IDBCM1_LIN1_04))));
        break; /* end case 59*/
      } /* end case */
      /* Setting member variable vcast_param->IDBCM1_LIN1_05 */
      case 60: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->IDBCM1_LIN1_05))));
        break; /* end case 60*/
      } /* end case */
      /* Setting member variable vcast_param->HUD_MAX_Value */
      case 61: { 
        VCAST_TI_9_6 ( ((unsigned *)(&(vcast_param->HUD_MAX_Value))));
        break; /* end case 61*/
      } /* end case */
      /* Setting member variable vcast_param->HUD_MAX_Resolution */
      case 62: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->HUD_MAX_Resolution))));
        break; /* end case 62*/
      } /* end case */
      /* Setting member variable vcast_param->RS_Intensity_OverWipeCoef */
      case 63: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->RS_Intensity_OverWipeCoef))));
        break; /* end case 63*/
      } /* end case */
      /* Setting member variable vcast_param->RS_Intensity_Thr_IdleTime */
      case 64: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->RS_Intensity_Thr_IdleTime))));
        break; /* end case 64*/
      } /* end case */
      /* Setting member variable vcast_param->RS_Intensity_SigVoltageH */
      case 65: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->RS_Intensity_SigVoltageH))));
        break; /* end case 65*/
      } /* end case */
      /* Setting member variable vcast_param->RS_Intensity_SigVoltageL */
      case 66: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->RS_Intensity_SigVoltageL))));
        break; /* end case 66*/
      } /* end case */
      /* Setting member variable vcast_param->SC_ORDER12 */
      case 67: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->SC_ORDER12))));
        break; /* end case 67*/
      } /* end case */
      /* Setting member variable vcast_param->SC_ORDER3 */
      case 68: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->SC_ORDER3))));
        break; /* end case 68*/
      } /* end case */
      /* Setting member variable vcast_param->SC_MAX */
      case 69: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->SC_MAX))));
        break; /* end case 69*/
      } /* end case */
      default:
        vCAST_TOOL_ERROR = vCAST_true;
    } /* end switch */ 
  }
#endif /*(defined(VCAST_NO_TYPE_SUPPORT))*/

} /* end VCAST_TI_9_14 */
#endif /*(defined(VCAST_NO_TYPE_SUPPORT))*/


/* An array */
#if (defined(VCAST_NO_TYPE_SUPPORT))
void VCAST_TI_9_75 ( unsigned char vcast_param[194] ) 
{
  /* User code: type is not supported */
  vcast_not_supported();
} /* end VCAST_TI_9_75 */
#else /*(defined(VCAST_NO_TYPE_SUPPORT))*/
void VCAST_TI_9_75 ( unsigned char vcast_param[194] ) 
{
  {
    int VCAST_TI_9_75_array_index = 0;
    int VCAST_TI_9_75_index = 0;
    int VCAST_TI_9_75_first, VCAST_TI_9_75_last;
    int VCAST_TI_9_75_more_data; /* true if there is more data in the current command */
    int VCAST_TI_9_75_local_field = 0;
    int VCAST_TI_9_75_value_printed = 0;
    int VCAST_TI_9_75_is_string = (VCAST_FIND_INDEX()==-1);


    vcast_get_range_value (&VCAST_TI_9_75_first, &VCAST_TI_9_75_last, &VCAST_TI_9_75_more_data);
    VCAST_TI_9_75_local_field = vCAST_DATA_FIELD;
    if ( vCAST_SIZE && (!VCAST_TI_9_75_more_data)) { /* get the size of the array */
      vectorcast_fprint_integer (vCAST_OUTPUT_FILE,194);
      vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
      vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n");
    } else {
      int VCAST_TI_9_75_upper = 194;
      for (VCAST_TI_9_75_array_index=0; VCAST_TI_9_75_array_index< VCAST_TI_9_75_upper; VCAST_TI_9_75_array_index++){
        if ( (VCAST_TI_9_75_index >= VCAST_TI_9_75_first) && ( VCAST_TI_9_75_index <= VCAST_TI_9_75_last)){
          if ( VCAST_TI_9_75_is_string )
            VCAST_TI_STRING ( (char**)&vcast_param, sizeof ( vcast_param ), 1,VCAST_TI_9_75_upper);
          else
            VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param[VCAST_TI_9_75_index]))));
          VCAST_TI_9_75_value_printed = 1;
          vCAST_DATA_FIELD = VCAST_TI_9_75_local_field;
        } /* if */
        if (VCAST_TI_9_75_index >= VCAST_TI_9_75_last)
          break;
        VCAST_TI_9_75_index++;
      } /* loop */
      if ((vCAST_COMMAND == vCAST_PRINT)&&(!VCAST_TI_9_75_value_printed))
        vectorcast_fprint_string(vCAST_OUTPUT_FILE,"<<past end of array>>\n");
    } /* if */
  }
} /* end VCAST_TI_9_75 */
#endif /*(defined(VCAST_NO_TYPE_SUPPORT))*/


/* A typedef */
#if (defined(VCAST_NO_TYPE_SUPPORT))
void VCAST_TI_9_18 ( s_rb_EEPROMStruct_AD_g *vcast_param ) 
{
  /* User code: type is not supported */
  vcast_not_supported();
} /* end VCAST_TI_9_18 */
#else /*(defined(VCAST_NO_TYPE_SUPPORT))*/
void VCAST_TI_9_18 ( s_rb_EEPROMStruct_AD_g *vcast_param ) 
{
#if (defined(VCAST_NO_TYPE_SUPPORT))
  /* User code: type is not supported */
  vcast_not_supported();
#else /*(defined(VCAST_NO_TYPE_SUPPORT))*/
  {
    switch ( vcast_get_param () ) { /* Choose field member */
      /* Setting member variable vcast_param->PrametersStruct */
      case 1: { 
        VCAST_TI_9_69 ( ((s_rb_PrametersStruct_g *)(vcast_param->PrametersStruct)));
        break; /* end case 1*/
      } /* end case */
      /* Setting member variable vcast_param->RS_GainSetupArray */
      case 2: { 
        VCAST_TI_9_107 ( ((unsigned char *)(vcast_param->RS_GainSetupArray)));
        break; /* end case 2*/
      } /* end case */
      /* Setting member variable vcast_param->HALIOS_Clock_Control_Reg_g */
      case 3: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->HALIOS_Clock_Control_Reg_g))));
        break; /* end case 3*/
      } /* end case */
      /* Setting member variable vcast_param->ACTR_Reg_g */
      case 4: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->ACTR_Reg_g))));
        break; /* end case 4*/
      } /* end case */
      /* Setting member variable vcast_param->PCO_PI_Regulator_g */
      case 5: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->PCO_PI_Regulator_g))));
        break; /* end case 5*/
      } /* end case */
      /* Setting member variable vcast_param->ICO1H_g */
      case 6: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->ICO1H_g))));
        break; /* end case 6*/
      } /* end case */
      /* Setting member variable vcast_param->ICO1L_g */
      case 7: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->ICO1L_g))));
        break; /* end case 7*/
      } /* end case */
      /* Setting member variable vcast_param->ICO2H_g */
      case 8: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->ICO2H_g))));
        break; /* end case 8*/
      } /* end case */
      /* Setting member variable vcast_param->ICO2L_g */
      case 9: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->ICO2L_g))));
        break; /* end case 9*/
      } /* end case */
      /* Setting member variable vcast_param->FOSC_LEDUL_g */
      case 10: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->FOSC_LEDUL_g))));
        break; /* end case 10*/
      } /* end case */
      /* Setting member variable vcast_param->INTCO_g */
      case 11: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->INTCO_g))));
        break; /* end case 11*/
      } /* end case */
      /* Setting member variable vcast_param->StandbyTimout */
      case 12: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->StandbyTimout))));
        break; /* end case 12*/
      } /* end case */
      /* Setting member variable vcast_param->dec_st2_speicher */
      case 13: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->dec_st2_speicher))));
        break; /* end case 13*/
      } /* end case */
      /* Setting member variable vcast_param->RS_Sensitivity */
      case 14: { 
        VCAST_TI_9_57 ( ((unsigned char *)(vcast_param->RS_Sensitivity)));
        break; /* end case 14*/
      } /* end case */
      /* Setting member variable vcast_param->MaxOverwipeSensitivity */
      case 15: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->MaxOverwipeSensitivity))));
        break; /* end case 15*/
      } /* end case */
      /* Setting member variable vcast_param->StandbyModeScanTime_g */
      case 16: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->StandbyModeScanTime_g))));
        break; /* end case 16*/
      } /* end case */
      /* Setting member variable vcast_param->RainNightBitThrs_g */
      case 17: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->RainNightBitThrs_g))));
        break; /* end case 17*/
      } /* end case */
      /* Setting member variable vcast_param->Amb_Base_Day_Threshold */
      case 18: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->Amb_Base_Day_Threshold))));
        break; /* end case 18*/
      } /* end case */
      /* Setting member variable vcast_param->Amb_Base_Night_Threshold */
      case 19: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->Amb_Base_Night_Threshold))));
        break; /* end case 19*/
      } /* end case */
      /* Setting member variable vcast_param->TunnelDebounceFactor */
      case 20: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->TunnelDebounceFactor))));
        break; /* end case 20*/
      } /* end case */
      /* Setting member variable vcast_param->Customer_FW_SWA_Scaling */
      case 21: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->Customer_FW_SWA_Scaling))));
        break; /* end case 21*/
      } /* end case */
      /* Setting member variable vcast_param->Customer_IR_SWA_Scaling */
      case 22: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->Customer_IR_SWA_Scaling))));
        break; /* end case 22*/
      } /* end case */
      /* Setting member variable vcast_param->FW_Base_Day_Threshold */
      case 23: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->FW_Base_Day_Threshold))));
        break; /* end case 23*/
      } /* end case */
      /* Setting member variable vcast_param->IR_Base_Day_Threshold */
      case 24: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->IR_Base_Day_Threshold))));
        break; /* end case 24*/
      } /* end case */
      /* Setting member variable vcast_param->FW_Base_Night_Threshold */
      case 25: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->FW_Base_Night_Threshold))));
        break; /* end case 25*/
      } /* end case */
      /* Setting member variable vcast_param->IR_Base_Night_Threshold */
      case 26: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->IR_Base_Night_Threshold))));
        break; /* end case 26*/
      } /* end case */
      /* Setting member variable vcast_param->Day_Delay */
      case 27: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->Day_Delay))));
        break; /* end case 27*/
      } /* end case */
      /* Setting member variable vcast_param->Night_Delay */
      case 28: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->Night_Delay))));
        break; /* end case 28*/
      } /* end case */
      /* Setting member variable vcast_param->AfterTunnelDelayOffs */
      case 29: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->AfterTunnelDelayOffs))));
        break; /* end case 29*/
      } /* end case */
      /* Setting member variable vcast_param->p_v_autobahn_on_off_g */
      case 30: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->p_v_autobahn_on_off_g))));
        break; /* end case 30*/
      } /* end case */
      /* Setting member variable vcast_param->p_t_autobahn_delay_on_g */
      case 31: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->p_t_autobahn_delay_on_g))));
        break; /* end case 31*/
      } /* end case */
      /* Setting member variable vcast_param->Frontwaschen_Autobahndelay_g */
      case 32: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->Frontwaschen_Autobahndelay_g))));
        break; /* end case 32*/
      } /* end case */
      /* Setting member variable vcast_param->p_n_regenlichtschwelle_low_high_g */
      case 33: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->p_n_regenlichtschwelle_low_high_g))));
        break; /* end case 33*/
      } /* end case */
      /* Setting member variable vcast_param->p_n_regenlichtschwelle_Zeit_g */
      case 34: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->p_n_regenlichtschwelle_Zeit_g))));
        break; /* end case 34*/
      } /* end case */
      /* Setting member variable vcast_param->TunnelThresholdScaling_g */
      case 35: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->TunnelThresholdScaling_g))));
        break; /* end case 35*/
      } /* end case */
      /* Setting member variable vcast_param->Amb_TunnelThresholdScaling_g */
      case 36: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->Amb_TunnelThresholdScaling_g))));
        break; /* end case 36*/
      } /* end case */
      /* Setting member variable vcast_param->spare */
      case 37: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->spare))));
        break; /* end case 37*/
      } /* end case */
      /* Setting member variable vcast_param->Regulation48LightOnTime_g */
      case 38: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->Regulation48LightOnTime_g))));
        break; /* end case 38*/
      } /* end case */
      /* Setting member variable vcast_param->VeryBrightInTunnelDelay_g */
      case 39: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->VeryBrightInTunnelDelay_g))));
        break; /* end case 39*/
      } /* end case */
      /* Setting member variable vcast_param->Combined_FW_AL_THRs_g */
      case 40: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->Combined_FW_AL_THRs_g))));
        break; /* end case 40*/
      } /* end case */
      /* Setting member variable vcast_param->DYN_COMP_CCD_MINUS_1_g */
      case 41: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->DYN_COMP_CCD_MINUS_1_g))));
        break; /* end case 41*/
      } /* end case */
      /* Setting member variable vcast_param->DYN_COMP_CCD_MINUS_2_g */
      case 42: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->DYN_COMP_CCD_MINUS_2_g))));
        break; /* end case 42*/
      } /* end case */
      /* Setting member variable vcast_param->maxTemperatureOffsett_g */
      case 43: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->maxTemperatureOffsett_g))));
        break; /* end case 43*/
      } /* end case */
      /* Setting member variable vcast_param->ASIC_AFSTHR_REG_g */
      case 44: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->ASIC_AFSTHR_REG_g))));
        break; /* end case 44*/
      } /* end case */
      /* Setting member variable vcast_param->Diag_Request_Factor_g */
      case 45: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->Diag_Request_Factor_g))));
        break; /* end case 45*/
      } /* end case */
      /* Setting member variable vcast_param->cb_inc_speicher_g */
      case 46: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->cb_inc_speicher_g))));
        break; /* end case 46*/
      } /* end case */
      /* Setting member variable vcast_param->I2C_Debug_Config_g */
      case 47: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->I2C_Debug_Config_g))));
        break; /* end case 47*/
      } /* end case */
      /* Setting member variable vcast_param->Audi_SW_Partnumber */
      case 48: { 
        VCAST_TI_9_35 ( ((unsigned char *)(vcast_param->Audi_SW_Partnumber)));
        break; /* end case 48*/
      } /* end case */
      /* Setting member variable vcast_param->wiperSpeedHysteresis */
      case 49: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->wiperSpeedHysteresis))));
        break; /* end case 49*/
      } /* end case */
      /* Setting member variable vcast_param->Proj_Specific_config */
      case 50: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->Proj_Specific_config))));
        break; /* end case 50*/
      } /* end case */
      /* Setting member variable vcast_param->ALSx_Filter_g */
      case 51: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->ALSx_Filter_g))));
        break; /* end case 51*/
      } /* end case */
      /* Setting member variable vcast_param->IrLightTunnelThreshodRng */
      case 52: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->IrLightTunnelThreshodRng))));
        break; /* end case 52*/
      } /* end case */
      /* Setting member variable vcast_param->FwLightTunnelThresholdRng */
      case 53: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->FwLightTunnelThresholdRng))));
        break; /* end case 53*/
      } /* end case */
      /* Setting member variable vcast_param->AmbLightTunnelThresholdRng */
      case 54: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->AmbLightTunnelThresholdRng))));
        break; /* end case 54*/
      } /* end case */
      /* Setting member variable vcast_param->TunWischVerzAktiv */
      case 55: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->TunWischVerzAktiv))));
        break; /* end case 55*/
      } /* end case */
      /* Setting member variable vcast_param->SHTErrorDebounceJitter */
      case 56: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->SHTErrorDebounceJitter))));
        break; /* end case 56*/
      } /* end case */
      /* Setting member variable vcast_param->SolarShadowCorrFactor1 */
      case 57: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->SolarShadowCorrFactor1))));
        break; /* end case 57*/
      } /* end case */
      /* Setting member variable vcast_param->SolarShadowCorrFactor2 */
      case 58: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->SolarShadowCorrFactor2))));
        break; /* end case 58*/
      } /* end case */
      /* Setting member variable vcast_param->E2_MaxSt2SignalLaenge */
      case 59: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->E2_MaxSt2SignalLaenge))));
        break; /* end case 59*/
      } /* end case */
      /* Setting member variable vcast_param->SoftwareStand */
      case 60: { 
        VCAST_TI_9_33 ( ((unsigned char *)(vcast_param->SoftwareStand)));
        break; /* end case 60*/
      } /* end case */
      /* Setting member variable vcast_param->twilightToDarkTime */
      case 61: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->twilightToDarkTime))));
        break; /* end case 61*/
      } /* end case */
      /* Setting member variable vcast_param->darkToTwilightTime */
      case 62: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->darkToTwilightTime))));
        break; /* end case 62*/
      } /* end case */
      /* Setting member variable vcast_param->darkToTwilightThreshFW */
      case 63: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->darkToTwilightThreshFW))));
        break; /* end case 63*/
      } /* end case */
      /* Setting member variable vcast_param->darkToTwilightThreshAMB */
      case 64: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->darkToTwilightThreshAMB))));
        break; /* end case 64*/
      } /* end case */
      /* Setting member variable vcast_param->twilightToDarkThreshFW */
      case 65: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->twilightToDarkThreshFW))));
        break; /* end case 65*/
      } /* end case */
      /* Setting member variable vcast_param->twilightToDarkThreshAMB */
      case 66: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->twilightToDarkThreshAMB))));
        break; /* end case 66*/
      } /* end case */
      /* Setting member variable vcast_param->iceDetectionTemperature */
      case 67: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->iceDetectionTemperature))));
        break; /* end case 67*/
      } /* end case */
      /* Setting member variable vcast_param->Regulation48ThresholdAmb_g */
      case 68: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->Regulation48ThresholdAmb_g))));
        break; /* end case 68*/
      } /* end case */
      /* Setting member variable vcast_param->Regulation48ThresholdFw_g */
      case 69: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->Regulation48ThresholdFw_g))));
        break; /* end case 69*/
      } /* end case */
      /* Setting member variable vcast_param->Threshold_TempIceRisk */
      case 70: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->Threshold_TempIceRisk))));
        break; /* end case 70*/
      } /* end case */
      /* Setting member variable vcast_param->upperTolerance_StartupWipe */
      case 71: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->upperTolerance_StartupWipe))));
        break; /* end case 71*/
      } /* end case */
      /* Setting member variable vcast_param->unused */
      case 72: { 
        VCAST_TI_9_73 ( ((unsigned char *)(vcast_param->unused)));
        break; /* end case 72*/
      } /* end case */
      default:
        vCAST_TOOL_ERROR = vCAST_true;
    } /* end switch */ 
  }
#endif /*(defined(VCAST_NO_TYPE_SUPPORT))*/

} /* end VCAST_TI_9_18 */
#endif /*(defined(VCAST_NO_TYPE_SUPPORT))*/


/* An array */
#if (defined(VCAST_NO_TYPE_SUPPORT))
void VCAST_TI_9_76 ( unsigned char vcast_param[1] ) 
{
  /* User code: type is not supported */
  vcast_not_supported();
} /* end VCAST_TI_9_76 */
#else /*(defined(VCAST_NO_TYPE_SUPPORT))*/
void VCAST_TI_9_76 ( unsigned char vcast_param[1] ) 
{
  {
    int VCAST_TI_9_76_array_index = 0;
    int VCAST_TI_9_76_index = 0;
    int VCAST_TI_9_76_first, VCAST_TI_9_76_last;
    int VCAST_TI_9_76_more_data; /* true if there is more data in the current command */
    int VCAST_TI_9_76_local_field = 0;
    int VCAST_TI_9_76_value_printed = 0;
    int VCAST_TI_9_76_is_string = (VCAST_FIND_INDEX()==-1);


    vcast_get_range_value (&VCAST_TI_9_76_first, &VCAST_TI_9_76_last, &VCAST_TI_9_76_more_data);
    VCAST_TI_9_76_local_field = vCAST_DATA_FIELD;
    if ( vCAST_SIZE && (!VCAST_TI_9_76_more_data)) { /* get the size of the array */
      vectorcast_fprint_integer (vCAST_OUTPUT_FILE,1);
      vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
      vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n");
    } else {
      int VCAST_TI_9_76_upper = 1;
      for (VCAST_TI_9_76_array_index=0; VCAST_TI_9_76_array_index< VCAST_TI_9_76_upper; VCAST_TI_9_76_array_index++){
        if ( (VCAST_TI_9_76_index >= VCAST_TI_9_76_first) && ( VCAST_TI_9_76_index <= VCAST_TI_9_76_last)){
          if ( VCAST_TI_9_76_is_string )
            VCAST_TI_STRING ( (char**)&vcast_param, sizeof ( vcast_param ), 1,VCAST_TI_9_76_upper);
          else
            VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param[VCAST_TI_9_76_index]))));
          VCAST_TI_9_76_value_printed = 1;
          vCAST_DATA_FIELD = VCAST_TI_9_76_local_field;
        } /* if */
        if (VCAST_TI_9_76_index >= VCAST_TI_9_76_last)
          break;
        VCAST_TI_9_76_index++;
      } /* loop */
      if ((vCAST_COMMAND == vCAST_PRINT)&&(!VCAST_TI_9_76_value_printed))
        vectorcast_fprint_string(vCAST_OUTPUT_FILE,"<<past end of array>>\n");
    } /* if */
  }
} /* end VCAST_TI_9_76 */
#endif /*(defined(VCAST_NO_TYPE_SUPPORT))*/


/* An array */
#if (defined(VCAST_NO_TYPE_SUPPORT))
void VCAST_TI_9_4 ( struct _c_bits8 vcast_param[1] ) 
{
  /* User code: type is not supported */
  vcast_not_supported();
} /* end VCAST_TI_9_4 */
#else /*(defined(VCAST_NO_TYPE_SUPPORT))*/
void VCAST_TI_9_4 ( struct _c_bits8 vcast_param[1] ) 
{
  {
    int VCAST_TI_9_4_array_index = 0;
    int VCAST_TI_9_4_index = 0;
    int VCAST_TI_9_4_first, VCAST_TI_9_4_last;
    int VCAST_TI_9_4_more_data; /* true if there is more data in the current command */
    int VCAST_TI_9_4_local_field = 0;
    int VCAST_TI_9_4_value_printed = 0;


    vcast_get_range_value (&VCAST_TI_9_4_first, &VCAST_TI_9_4_last, &VCAST_TI_9_4_more_data);
    VCAST_TI_9_4_local_field = vCAST_DATA_FIELD;
    if ( vCAST_SIZE && (!VCAST_TI_9_4_more_data)) { /* get the size of the array */
      vectorcast_fprint_integer (vCAST_OUTPUT_FILE,1);
      vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
      vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n");
    } else {
      int VCAST_TI_9_4_upper = 1;
      for (VCAST_TI_9_4_array_index=0; VCAST_TI_9_4_array_index< VCAST_TI_9_4_upper; VCAST_TI_9_4_array_index++){
        if ( (VCAST_TI_9_4_index >= VCAST_TI_9_4_first) && ( VCAST_TI_9_4_index <= VCAST_TI_9_4_last)){
          VCAST_TI_9_5 ( ((struct _c_bits8 *)(&(vcast_param[VCAST_TI_9_4_index]))));
          VCAST_TI_9_4_value_printed = 1;
          vCAST_DATA_FIELD = VCAST_TI_9_4_local_field;
        } /* if */
        if (VCAST_TI_9_4_index >= VCAST_TI_9_4_last)
          break;
        VCAST_TI_9_4_index++;
      } /* loop */
      if ((vCAST_COMMAND == vCAST_PRINT)&&(!VCAST_TI_9_4_value_printed))
        vectorcast_fprint_string(vCAST_OUTPUT_FILE,"<<past end of array>>\n");
    } /* if */
  }
} /* end VCAST_TI_9_4 */
#endif /*(defined(VCAST_NO_TYPE_SUPPORT))*/


/* A typedef */
#if (defined(VCAST_NO_TYPE_SUPPORT))
void VCAST_TI_9_8 ( Bit_Feld *vcast_param ) 
{
  /* User code: type is not supported */
  vcast_not_supported();
} /* end VCAST_TI_9_8 */
#else /*(defined(VCAST_NO_TYPE_SUPPORT))*/
void VCAST_TI_9_8 ( Bit_Feld *vcast_param ) 
{
#if (defined(VCAST_NO_TYPE_SUPPORT))
  /* User code: type is not supported */
  vcast_not_supported();
#else /*(defined(VCAST_NO_TYPE_SUPPORT))*/
  {
    switch ( vcast_get_param () ) { /* Choose field member */
      /* Setting member variable vcast_param->B0 */
      case 1: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->B0;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->B0 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 1*/
      } /* end case */
      /* Setting member variable vcast_param->B1 */
      case 2: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->B1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->B1 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 2*/
      } /* end case */
      /* Setting member variable vcast_param->B2 */
      case 3: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->B2;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->B2 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 3*/
      } /* end case */
      /* Setting member variable vcast_param->B3 */
      case 4: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->B3;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->B3 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 4*/
      } /* end case */
      /* Setting member variable vcast_param->B4 */
      case 5: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->B4;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->B4 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 5*/
      } /* end case */
      /* Setting member variable vcast_param->B5 */
      case 6: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->B5;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->B5 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 6*/
      } /* end case */
      /* Setting member variable vcast_param->B6 */
      case 7: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->B6;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->B6 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 7*/
      } /* end case */
      /* Setting member variable vcast_param->B7 */
      case 8: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->B7;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->B7 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 8*/
      } /* end case */
      default:
        vCAST_TOOL_ERROR = vCAST_true;
    } /* end switch */ 
  }
#endif /*(defined(VCAST_NO_TYPE_SUPPORT))*/

} /* end VCAST_TI_9_8 */
#endif /*(defined(VCAST_NO_TYPE_SUPPORT))*/


/* An array */
#if (defined(VCAST_NO_TYPE_SUPPORT))
void VCAST_TI_9_33 ( unsigned char vcast_param[4] ) 
{
  /* User code: type is not supported */
  vcast_not_supported();
} /* end VCAST_TI_9_33 */
#else /*(defined(VCAST_NO_TYPE_SUPPORT))*/
void VCAST_TI_9_33 ( unsigned char vcast_param[4] ) 
{
  {
    int VCAST_TI_9_33_array_index = 0;
    int VCAST_TI_9_33_index = 0;
    int VCAST_TI_9_33_first, VCAST_TI_9_33_last;
    int VCAST_TI_9_33_more_data; /* true if there is more data in the current command */
    int VCAST_TI_9_33_local_field = 0;
    int VCAST_TI_9_33_value_printed = 0;
    int VCAST_TI_9_33_is_string = (VCAST_FIND_INDEX()==-1);


    vcast_get_range_value (&VCAST_TI_9_33_first, &VCAST_TI_9_33_last, &VCAST_TI_9_33_more_data);
    VCAST_TI_9_33_local_field = vCAST_DATA_FIELD;
    if ( vCAST_SIZE && (!VCAST_TI_9_33_more_data)) { /* get the size of the array */
      vectorcast_fprint_integer (vCAST_OUTPUT_FILE,4);
      vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
      vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n");
    } else {
      int VCAST_TI_9_33_upper = 4;
      for (VCAST_TI_9_33_array_index=0; VCAST_TI_9_33_array_index< VCAST_TI_9_33_upper; VCAST_TI_9_33_array_index++){
        if ( (VCAST_TI_9_33_index >= VCAST_TI_9_33_first) && ( VCAST_TI_9_33_index <= VCAST_TI_9_33_last)){
          if ( VCAST_TI_9_33_is_string )
            VCAST_TI_STRING ( (char**)&vcast_param, sizeof ( vcast_param ), 1,VCAST_TI_9_33_upper);
          else
            VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param[VCAST_TI_9_33_index]))));
          VCAST_TI_9_33_value_printed = 1;
          vCAST_DATA_FIELD = VCAST_TI_9_33_local_field;
        } /* if */
        if (VCAST_TI_9_33_index >= VCAST_TI_9_33_last)
          break;
        VCAST_TI_9_33_index++;
      } /* loop */
      if ((vCAST_COMMAND == vCAST_PRINT)&&(!VCAST_TI_9_33_value_printed))
        vectorcast_fprint_string(vCAST_OUTPUT_FILE,"<<past end of array>>\n");
    } /* if */
  }
} /* end VCAST_TI_9_33 */
#endif /*(defined(VCAST_NO_TYPE_SUPPORT))*/


/* A typedef */
#if (defined(VCAST_NO_TYPE_SUPPORT))
void VCAST_TI_9_45 ( _c_RlsmCem_SerNrLin1Fr01_CEM_LIN1_msgType *vcast_param ) 
{
  /* User code: type is not supported */
  vcast_not_supported();
} /* end VCAST_TI_9_45 */
#else /*(defined(VCAST_NO_TYPE_SUPPORT))*/
void VCAST_TI_9_45 ( _c_RlsmCem_SerNrLin1Fr01_CEM_LIN1_msgType *vcast_param ) 
{
#if (defined(VCAST_NO_TYPE_SUPPORT))
  /* User code: type is not supported */
  vcast_not_supported();
#else /*(defined(VCAST_NO_TYPE_SUPPORT))*/
  {
    switch ( vcast_get_param () ) { /* Choose field member */
      /* Setting member variable vcast_param->RLSMSerNoNr1_CEM_LIN1 */
      case 1: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->RLSMSerNoNr1_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->RLSMSerNoNr1_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 1*/
      } /* end case */
      /* Setting member variable vcast_param->RLSMSerNoNr2_CEM_LIN1 */
      case 2: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->RLSMSerNoNr2_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->RLSMSerNoNr2_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 2*/
      } /* end case */
      /* Setting member variable vcast_param->RLSMSerNoNr3_CEM_LIN1 */
      case 3: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->RLSMSerNoNr3_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->RLSMSerNoNr3_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 3*/
      } /* end case */
      /* Setting member variable vcast_param->RLSMSerNoNr4_CEM_LIN1 */
      case 4: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->RLSMSerNoNr4_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->RLSMSerNoNr4_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 4*/
      } /* end case */
      default:
        vCAST_TOOL_ERROR = vCAST_true;
    } /* end switch */ 
  }
#endif /*(defined(VCAST_NO_TYPE_SUPPORT))*/

} /* end VCAST_TI_9_45 */
#endif /*(defined(VCAST_NO_TYPE_SUPPORT))*/


/* An array */
#if (defined(VCAST_NO_TYPE_SUPPORT))
void VCAST_TI_9_35 ( unsigned char vcast_param[8] ) 
{
  /* User code: type is not supported */
  vcast_not_supported();
} /* end VCAST_TI_9_35 */
#else /*(defined(VCAST_NO_TYPE_SUPPORT))*/
void VCAST_TI_9_35 ( unsigned char vcast_param[8] ) 
{
  {
    int VCAST_TI_9_35_array_index = 0;
    int VCAST_TI_9_35_index = 0;
    int VCAST_TI_9_35_first, VCAST_TI_9_35_last;
    int VCAST_TI_9_35_more_data; /* true if there is more data in the current command */
    int VCAST_TI_9_35_local_field = 0;
    int VCAST_TI_9_35_value_printed = 0;
    int VCAST_TI_9_35_is_string = (VCAST_FIND_INDEX()==-1);


    vcast_get_range_value (&VCAST_TI_9_35_first, &VCAST_TI_9_35_last, &VCAST_TI_9_35_more_data);
    VCAST_TI_9_35_local_field = vCAST_DATA_FIELD;
    if ( vCAST_SIZE && (!VCAST_TI_9_35_more_data)) { /* get the size of the array */
      vectorcast_fprint_integer (vCAST_OUTPUT_FILE,8);
      vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
      vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n");
    } else {
      int VCAST_TI_9_35_upper = 8;
      for (VCAST_TI_9_35_array_index=0; VCAST_TI_9_35_array_index< VCAST_TI_9_35_upper; VCAST_TI_9_35_array_index++){
        if ( (VCAST_TI_9_35_index >= VCAST_TI_9_35_first) && ( VCAST_TI_9_35_index <= VCAST_TI_9_35_last)){
          if ( VCAST_TI_9_35_is_string )
            VCAST_TI_STRING ( (char**)&vcast_param, sizeof ( vcast_param ), 1,VCAST_TI_9_35_upper);
          else
            VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param[VCAST_TI_9_35_index]))));
          VCAST_TI_9_35_value_printed = 1;
          vCAST_DATA_FIELD = VCAST_TI_9_35_local_field;
        } /* if */
        if (VCAST_TI_9_35_index >= VCAST_TI_9_35_last)
          break;
        VCAST_TI_9_35_index++;
      } /* loop */
      if ((vCAST_COMMAND == vCAST_PRINT)&&(!VCAST_TI_9_35_value_printed))
        vectorcast_fprint_string(vCAST_OUTPUT_FILE,"<<past end of array>>\n");
    } /* if */
  }
} /* end VCAST_TI_9_35 */
#endif /*(defined(VCAST_NO_TYPE_SUPPORT))*/


/* A typedef */
#if (defined(VCAST_NO_TYPE_SUPPORT))
void VCAST_TI_9_47 ( _c_RlsmCem_Lin1PartNrFr02_CEM_LIN1_msgType *vcast_param ) 
{
  /* User code: type is not supported */
  vcast_not_supported();
} /* end VCAST_TI_9_47 */
#else /*(defined(VCAST_NO_TYPE_SUPPORT))*/
void VCAST_TI_9_47 ( _c_RlsmCem_Lin1PartNrFr02_CEM_LIN1_msgType *vcast_param ) 
{
#if (defined(VCAST_NO_TYPE_SUPPORT))
  /* User code: type is not supported */
  vcast_not_supported();
#else /*(defined(VCAST_NO_TYPE_SUPPORT))*/
  {
    switch ( vcast_get_param () ) { /* Choose field member */
      /* Setting member variable vcast_param->RLSMPartNo10Nr1_CEM_LIN1 */
      case 1: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->RLSMPartNo10Nr1_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->RLSMPartNo10Nr1_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 1*/
      } /* end case */
      /* Setting member variable vcast_param->RLSMPartNo10Nr2_CEM_LIN1 */
      case 2: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->RLSMPartNo10Nr2_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->RLSMPartNo10Nr2_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 2*/
      } /* end case */
      /* Setting member variable vcast_param->RLSMPartNo10Nr3_CEM_LIN1 */
      case 3: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->RLSMPartNo10Nr3_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->RLSMPartNo10Nr3_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 3*/
      } /* end case */
      /* Setting member variable vcast_param->RLSMPartNo10Nr4_CEM_LIN1 */
      case 4: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->RLSMPartNo10Nr4_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->RLSMPartNo10Nr4_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 4*/
      } /* end case */
      /* Setting member variable vcast_param->RLSMPartNo10Nr5_CEM_LIN1 */
      case 5: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->RLSMPartNo10Nr5_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->RLSMPartNo10Nr5_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 5*/
      } /* end case */
      /* Setting member variable vcast_param->RLSMPartNo10EndSgn1_CEM_LIN1 */
      case 6: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->RLSMPartNo10EndSgn1_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->RLSMPartNo10EndSgn1_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 6*/
      } /* end case */
      /* Setting member variable vcast_param->RLSMPartNo10EndSgn2_CEM_LIN1 */
      case 7: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->RLSMPartNo10EndSgn2_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->RLSMPartNo10EndSgn2_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 7*/
      } /* end case */
      /* Setting member variable vcast_param->RLSMPartNo10EndSgn3_CEM_LIN1 */
      case 8: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->RLSMPartNo10EndSgn3_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->RLSMPartNo10EndSgn3_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 8*/
      } /* end case */
      default:
        vCAST_TOOL_ERROR = vCAST_true;
    } /* end switch */ 
  }
#endif /*(defined(VCAST_NO_TYPE_SUPPORT))*/

} /* end VCAST_TI_9_47 */
#endif /*(defined(VCAST_NO_TYPE_SUPPORT))*/


/* A typedef */
#if (defined(VCAST_NO_TYPE_SUPPORT))
void VCAST_TI_9_46 ( _c_RlsmCem_Lin1PartNrFr01_CEM_LIN1_msgType *vcast_param ) 
{
  /* User code: type is not supported */
  vcast_not_supported();
} /* end VCAST_TI_9_46 */
#else /*(defined(VCAST_NO_TYPE_SUPPORT))*/
void VCAST_TI_9_46 ( _c_RlsmCem_Lin1PartNrFr01_CEM_LIN1_msgType *vcast_param ) 
{
#if (defined(VCAST_NO_TYPE_SUPPORT))
  /* User code: type is not supported */
  vcast_not_supported();
#else /*(defined(VCAST_NO_TYPE_SUPPORT))*/
  {
    switch ( vcast_get_param () ) { /* Choose field member */
      /* Setting member variable vcast_param->RLSMPartNoNr1_CEM_LIN1 */
      case 1: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->RLSMPartNoNr1_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->RLSMPartNoNr1_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 1*/
      } /* end case */
      /* Setting member variable vcast_param->RLSMPartNoNr2_CEM_LIN1 */
      case 2: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->RLSMPartNoNr2_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->RLSMPartNoNr2_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 2*/
      } /* end case */
      /* Setting member variable vcast_param->RLSMPartNoNr3_CEM_LIN1 */
      case 3: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->RLSMPartNoNr3_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->RLSMPartNoNr3_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 3*/
      } /* end case */
      /* Setting member variable vcast_param->RLSMPartNoNr4_CEM_LIN1 */
      case 4: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->RLSMPartNoNr4_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->RLSMPartNoNr4_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 4*/
      } /* end case */
      /* Setting member variable vcast_param->RLSMPartNoEndSgn1_CEM_LIN1 */
      case 5: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->RLSMPartNoEndSgn1_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->RLSMPartNoEndSgn1_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 5*/
      } /* end case */
      /* Setting member variable vcast_param->RLSMPartNoEndSgn2_CEM_LIN1 */
      case 6: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->RLSMPartNoEndSgn2_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->RLSMPartNoEndSgn2_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 6*/
      } /* end case */
      /* Setting member variable vcast_param->RLSMPartNoEndSgn3_CEM_LIN1 */
      case 7: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->RLSMPartNoEndSgn3_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->RLSMPartNoEndSgn3_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 7*/
      } /* end case */
      default:
        vCAST_TOOL_ERROR = vCAST_true;
    } /* end switch */ 
  }
#endif /*(defined(VCAST_NO_TYPE_SUPPORT))*/

} /* end VCAST_TI_9_46 */
#endif /*(defined(VCAST_NO_TYPE_SUPPORT))*/


/* A typedef */
#if (defined(VCAST_NO_TYPE_SUPPORT))
void VCAST_TI_9_26 ( _c_RlsmCem_Lin1Fr03_CEM_LIN1_msgType *vcast_param ) 
{
  /* User code: type is not supported */
  vcast_not_supported();
} /* end VCAST_TI_9_26 */
#else /*(defined(VCAST_NO_TYPE_SUPPORT))*/
void VCAST_TI_9_26 ( _c_RlsmCem_Lin1Fr03_CEM_LIN1_msgType *vcast_param ) 
{
#if (defined(VCAST_NO_TYPE_SUPPORT))
  /* User code: type is not supported */
  vcast_not_supported();
#else /*(defined(VCAST_NO_TYPE_SUPPORT))*/
  {
    switch ( vcast_get_param () ) { /* Choose field member */
      /* Setting member variable vcast_param->SolarSnsrErr_CEM_LIN1 */
      case 1: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->SolarSnsrErr_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->SolarSnsrErr_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 1*/
      } /* end case */
      /* Setting member variable vcast_param->unused0 */
      case 2: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->unused0;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 2, vCAST_false );
        vcast_param->unused0 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 2*/
      } /* end case */
      /* Setting member variable vcast_param->RainSnsrDiagcRainSnsrHiVoltDetd_CEM_LIN1 */
      case 3: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->RainSnsrDiagcRainSnsrHiVoltDetd_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->RainSnsrDiagcRainSnsrHiVoltDetd_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 3*/
      } /* end case */
      /* Setting member variable vcast_param->RainSnsrDiagcRainSnsrHiTDetd_CEM_LIN1 */
      case 4: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->RainSnsrDiagcRainSnsrHiTDetd_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->RainSnsrDiagcRainSnsrHiTDetd_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 4*/
      } /* end case */
      /* Setting member variable vcast_param->LiOprnMod_CEM_LIN1 */
      case 5: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->LiOprnMod_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 2, vCAST_false );
        vcast_param->LiOprnMod_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 5*/
      } /* end case */
      /* Setting member variable vcast_param->RainDetected_CEM_LIN1 */
      case 6: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->RainDetected_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->RainDetected_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 6*/
      } /* end case */
      /* Setting member variable vcast_param->RainfallAmnt_CEM_LIN1 */
      case 7: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->RainfallAmnt_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 4, vCAST_false );
        vcast_param->RainfallAmnt_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 7*/
      } /* end case */
      /* Setting member variable vcast_param->unused1 */
      case 8: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->unused1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 4, vCAST_false );
        vcast_param->unused1 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 8*/
      } /* end case */
      /* Setting member variable vcast_param->SolarSnsrLeValue_CEM_LIN1 */
      case 9: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->SolarSnsrLeValue_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->SolarSnsrLeValue_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 9*/
      } /* end case */
      /* Setting member variable vcast_param->SolarSnsrRiValue_CEM_LIN1 */
      case 10: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->SolarSnsrRiValue_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->SolarSnsrRiValue_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 10*/
      } /* end case */
      /* Setting member variable vcast_param->unused2 */
      case 11: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->unused2;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->unused2 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 11*/
      } /* end case */
      /* Setting member variable vcast_param->unused3 */
      case 12: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->unused3;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->unused3 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 12*/
      } /* end case */
      /* Setting member variable vcast_param->unused4 */
      case 13: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->unused4;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->unused4 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 13*/
      } /* end case */
      /* Setting member variable vcast_param->unused5 */
      case 14: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->unused5;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->unused5 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 14*/
      } /* end case */
      default:
        vCAST_TOOL_ERROR = vCAST_true;
    } /* end switch */ 
  }
#endif /*(defined(VCAST_NO_TYPE_SUPPORT))*/

} /* end VCAST_TI_9_26 */
#endif /*(defined(VCAST_NO_TYPE_SUPPORT))*/


/* A typedef */
#if (defined(VCAST_NO_TYPE_SUPPORT))
void VCAST_TI_9_28 ( _c_RlsmCem_Lin1Fr02_CEM_LIN1_msgType *vcast_param ) 
{
  /* User code: type is not supported */
  vcast_not_supported();
} /* end VCAST_TI_9_28 */
#else /*(defined(VCAST_NO_TYPE_SUPPORT))*/
void VCAST_TI_9_28 ( _c_RlsmCem_Lin1Fr02_CEM_LIN1_msgType *vcast_param ) 
{
#if (defined(VCAST_NO_TYPE_SUPPORT))
  /* User code: type is not supported */
  vcast_not_supported();
#else /*(defined(VCAST_NO_TYPE_SUPPORT))*/
  {
    switch ( vcast_get_param () ) { /* Choose field member */
      /* Setting member variable vcast_param->CmptFrntWindDewT_CEM_LIN1_0 */
      case 1: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->CmptFrntWindDewT_CEM_LIN1_0;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->CmptFrntWindDewT_CEM_LIN1_0 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 1*/
      } /* end case */
      /* Setting member variable vcast_param->CmptFrntWindDewT_CEM_LIN1_1 */
      case 2: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->CmptFrntWindDewT_CEM_LIN1_1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 3, vCAST_false );
        vcast_param->CmptFrntWindDewT_CEM_LIN1_1 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 2*/
      } /* end case */
      /* Setting member variable vcast_param->AmbIllmnFwdStsCntr_CEM_LIN1 */
      case 3: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->AmbIllmnFwdStsCntr_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 4, vCAST_false );
        vcast_param->AmbIllmnFwdStsCntr_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 3*/
      } /* end case */
      /* Setting member variable vcast_param->unused0 */
      case 4: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->unused0;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->unused0 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 4*/
      } /* end case */
      /* Setting member variable vcast_param->AmbIllmnFwdStsAmblillmn2_CEM_LIN1 */
      case 5: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->AmbIllmnFwdStsAmblillmn2_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->AmbIllmnFwdStsAmblillmn2_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 5*/
      } /* end case */
      /* Setting member variable vcast_param->AmbIllmnFwdStsChks_CEM_LIN1 */
      case 6: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->AmbIllmnFwdStsChks_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->AmbIllmnFwdStsChks_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 6*/
      } /* end case */
      /* Setting member variable vcast_param->AmbIllmnFwdStsAmblillmn1_CEM_LIN1_0 */
      case 7: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->AmbIllmnFwdStsAmblillmn1_CEM_LIN1_0;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->AmbIllmnFwdStsAmblillmn1_CEM_LIN1_0 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 7*/
      } /* end case */
      /* Setting member variable vcast_param->AmbIllmnFwdStsAmblillmn1_CEM_LIN1_1 */
      case 8: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->AmbIllmnFwdStsAmblillmn1_CEM_LIN1_1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->AmbIllmnFwdStsAmblillmn1_CEM_LIN1_1 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 8*/
      } /* end case */
      /* Setting member variable vcast_param->unused1 */
      case 9: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->unused1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->unused1 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 9*/
      } /* end case */
      /* Setting member variable vcast_param->RelHumSnsrErr_CEM_LIN1 */
      case 10: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->RelHumSnsrErr_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->RelHumSnsrErr_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 10*/
      } /* end case */
      /* Setting member variable vcast_param->unused2 */
      case 11: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->unused2;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 2, vCAST_false );
        vcast_param->unused2 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 11*/
      } /* end case */
      /* Setting member variable vcast_param->CmptFrntWindT_CEM_LIN1_0 */
      case 12: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->CmptFrntWindT_CEM_LIN1_0;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 3, vCAST_false );
        vcast_param->CmptFrntWindT_CEM_LIN1_0 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 12*/
      } /* end case */
      /* Setting member variable vcast_param->CmptFrntWindT_CEM_LIN1_1 */
      case 13: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->CmptFrntWindT_CEM_LIN1_1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->CmptFrntWindT_CEM_LIN1_1 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 13*/
      } /* end case */
      /* Setting member variable vcast_param->RelHumSnsrRelHum_CEM_LIN1 */
      case 14: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->RelHumSnsrRelHum_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->RelHumSnsrRelHum_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 14*/
      } /* end case */
      default:
        vCAST_TOOL_ERROR = vCAST_true;
    } /* end switch */ 
  }
#endif /*(defined(VCAST_NO_TYPE_SUPPORT))*/

} /* end VCAST_TI_9_28 */
#endif /*(defined(VCAST_NO_TYPE_SUPPORT))*/


/* A typedef */
#if (defined(VCAST_NO_TYPE_SUPPORT))
void VCAST_TI_9_24 ( _c_RlsmCem_Lin1Fr01_CEM_LIN1_msgType *vcast_param ) 
{
  /* User code: type is not supported */
  vcast_not_supported();
} /* end VCAST_TI_9_24 */
#else /*(defined(VCAST_NO_TYPE_SUPPORT))*/
void VCAST_TI_9_24 ( _c_RlsmCem_Lin1Fr01_CEM_LIN1_msgType *vcast_param ) 
{
#if (defined(VCAST_NO_TYPE_SUPPORT))
  /* User code: type is not supported */
  vcast_not_supported();
#else /*(defined(VCAST_NO_TYPE_SUPPORT))*/
  {
    switch ( vcast_get_param () ) { /* Choose field member */
      /* Setting member variable vcast_param->AutWinWipgCmd_CEM_LIN1 */
      case 1: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->AutWinWipgCmd_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 3, vCAST_false );
        vcast_param->AutWinWipgCmd_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 1*/
      } /* end case */
      /* Setting member variable vcast_param->HudSnsrErrParChk_CEM_LIN1 */
      case 2: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->HudSnsrErrParChk_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->HudSnsrErrParChk_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 2*/
      } /* end case */
      /* Setting member variable vcast_param->HudSnsrErrSnsrErr_CEM_LIN1 */
      case 3: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->HudSnsrErrSnsrErr_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->HudSnsrErrSnsrErr_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 3*/
      } /* end case */
      /* Setting member variable vcast_param->unused0 */
      case 4: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->unused0;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 2, vCAST_false );
        vcast_param->unused0 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 4*/
      } /* end case */
      /* Setting member variable vcast_param->RainLi_CEM_LIN1 */
      case 5: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->RainLi_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->RainLi_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 5*/
      } /* end case */
      /* Setting member variable vcast_param->RainSnsrErrCalErrActv_CEM_LIN1 */
      case 6: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->RainSnsrErrCalErrActv_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->RainSnsrErrCalErrActv_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 6*/
      } /* end case */
      /* Setting member variable vcast_param->RainSnsrErrCalErr_CEM_LIN1 */
      case 7: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->RainSnsrErrCalErr_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->RainSnsrErrCalErr_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 7*/
      } /* end case */
      /* Setting member variable vcast_param->RainSnsrErrRainDetnErr_CEM_LIN1 */
      case 8: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->RainSnsrErrRainDetnErr_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->RainSnsrErrRainDetnErr_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 8*/
      } /* end case */
      /* Setting member variable vcast_param->RainSnsrErrRainDetnErrActv_CEM_LIN1 */
      case 9: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->RainSnsrErrRainDetnErrActv_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->RainSnsrErrRainDetnErrActv_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 9*/
      } /* end case */
      /* Setting member variable vcast_param->WipgAutFrntMod_CEM_LIN1 */
      case 10: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->WipgAutFrntMod_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 2, vCAST_false );
        vcast_param->WipgAutFrntMod_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 10*/
      } /* end case */
      /* Setting member variable vcast_param->unused1 */
      case 11: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->unused1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->unused1 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 11*/
      } /* end case */
      /* Setting member variable vcast_param->ErrRespRLSM_CEM_LIN1 */
      case 12: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->ErrRespRLSM_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->ErrRespRLSM_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 12*/
      } /* end case */
      /* Setting member variable vcast_param->unused2 */
      case 13: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->unused2;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->unused2 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 13*/
      } /* end case */
      /* Setting member variable vcast_param->TwliBriRawQf_CEM_LIN1 */
      case 14: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->TwliBriRawQf_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 2, vCAST_false );
        vcast_param->TwliBriRawQf_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 14*/
      } /* end case */
      /* Setting member variable vcast_param->TwliBriRawTwliBriRaw_CEM_LIN1_0 */
      case 15: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->TwliBriRawTwliBriRaw_CEM_LIN1_0;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 6, vCAST_false );
        vcast_param->TwliBriRawTwliBriRaw_CEM_LIN1_0 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 15*/
      } /* end case */
      /* Setting member variable vcast_param->TwliBriRawTwliBriRaw_CEM_LIN1_1 */
      case 16: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->TwliBriRawTwliBriRaw_CEM_LIN1_1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->TwliBriRawTwliBriRaw_CEM_LIN1_1 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 16*/
      } /* end case */
      /* Setting member variable vcast_param->unused3 */
      case 17: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->unused3;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->unused3 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 17*/
      } /* end case */
      /* Setting member variable vcast_param->OutdBriChks_CEM_LIN1 */
      case 18: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->OutdBriChks_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->OutdBriChks_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 18*/
      } /* end case */
      /* Setting member variable vcast_param->OutdBriSts_CEM_LIN1 */
      case 19: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->OutdBriSts_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 2, vCAST_false );
        vcast_param->OutdBriSts_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 19*/
      } /* end case */
      /* Setting member variable vcast_param->OutdBriCntr_CEM_LIN1 */
      case 20: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->OutdBriCntr_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 4, vCAST_false );
        vcast_param->OutdBriCntr_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 20*/
      } /* end case */
      /* Setting member variable vcast_param->unused4 */
      case 21: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->unused4;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 2, vCAST_false );
        vcast_param->unused4 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 21*/
      } /* end case */
      default:
        vCAST_TOOL_ERROR = vCAST_true;
    } /* end switch */ 
  }
#endif /*(defined(VCAST_NO_TYPE_SUPPORT))*/

} /* end VCAST_TI_9_24 */
#endif /*(defined(VCAST_NO_TYPE_SUPPORT))*/


/* A typedef */
#if (defined(VCAST_NO_TYPE_SUPPORT))
void VCAST_TI_9_56 ( _c_CemCem_Lin1Fr06_CEM_LIN1_msgType *vcast_param ) 
{
  /* User code: type is not supported */
  vcast_not_supported();
} /* end VCAST_TI_9_56 */
#else /*(defined(VCAST_NO_TYPE_SUPPORT))*/
void VCAST_TI_9_56 ( _c_CemCem_Lin1Fr06_CEM_LIN1_msgType *vcast_param ) 
{
#if (defined(VCAST_NO_TYPE_SUPPORT))
  /* User code: type is not supported */
  vcast_not_supported();
#else /*(defined(VCAST_NO_TYPE_SUPPORT))*/
  {
    switch ( vcast_get_param () ) { /* Choose field member */
      /* Setting member variable vcast_param->unused0 */
      case 1: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->unused0;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 4, vCAST_false );
        vcast_param->unused0 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 1*/
      } /* end case */
      /* Setting member variable vcast_param->WiprActv_CEM_LIN1 */
      case 2: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->WiprActv_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->WiprActv_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 2*/
      } /* end case */
      /* Setting member variable vcast_param->WiprInPrkgPosnLo_CEM_LIN1 */
      case 3: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->WiprInPrkgPosnLo_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->WiprInPrkgPosnLo_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 3*/
      } /* end case */
      /* Setting member variable vcast_param->WiprInWipgAr_CEM_LIN1 */
      case 4: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->WiprInWipgAr_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->WiprInWipgAr_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 4*/
      } /* end case */
      /* Setting member variable vcast_param->WshngCycActv_CEM_LIN1 */
      case 5: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->WshngCycActv_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->WshngCycActv_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 5*/
      } /* end case */
      default:
        vCAST_TOOL_ERROR = vCAST_true;
    } /* end switch */ 
  }
#endif /*(defined(VCAST_NO_TYPE_SUPPORT))*/

} /* end VCAST_TI_9_56 */
#endif /*(defined(VCAST_NO_TYPE_SUPPORT))*/


/* A typedef */
#if (defined(VCAST_NO_TYPE_SUPPORT))
void VCAST_TI_9_20 ( _c_CemCem_Lin1Fr05_CEM_LIN1_msgType *vcast_param ) 
{
  /* User code: type is not supported */
  vcast_not_supported();
} /* end VCAST_TI_9_20 */
#else /*(defined(VCAST_NO_TYPE_SUPPORT))*/
void VCAST_TI_9_20 ( _c_CemCem_Lin1Fr05_CEM_LIN1_msgType *vcast_param ) 
{
#if (defined(VCAST_NO_TYPE_SUPPORT))
  /* User code: type is not supported */
  vcast_not_supported();
#else /*(defined(VCAST_NO_TYPE_SUPPORT))*/
  {
    switch ( vcast_get_param () ) { /* Choose field member */
      /* Setting member variable vcast_param->unused0 */
      case 1: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->unused0;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->unused0 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 1*/
      } /* end case */
      /* Setting member variable vcast_param->unused1 */
      case 2: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->unused1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->unused1 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 2*/
      } /* end case */
      /* Setting member variable vcast_param->unused2 */
      case 3: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->unused2;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->unused2 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 3*/
      } /* end case */
      /* Setting member variable vcast_param->EnaOfflineMonitor_CEM_LIN1 */
      case 4: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->EnaOfflineMonitor_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->EnaOfflineMonitor_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 4*/
      } /* end case */
      /* Setting member variable vcast_param->unused3 */
      case 5: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->unused3;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 6, vCAST_false );
        vcast_param->unused3 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 5*/
      } /* end case */
      /* Setting member variable vcast_param->unused4 */
      case 6: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->unused4;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->unused4 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 6*/
      } /* end case */
      /* Setting member variable vcast_param->unused5 */
      case 7: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->unused5;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->unused5 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 7*/
      } /* end case */
      /* Setting member variable vcast_param->unused6 */
      case 8: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->unused6;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->unused6 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 8*/
      } /* end case */
      /* Setting member variable vcast_param->unused7 */
      case 9: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->unused7;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->unused7 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 9*/
      } /* end case */
      default:
        vCAST_TOOL_ERROR = vCAST_true;
    } /* end switch */ 
  }
#endif /*(defined(VCAST_NO_TYPE_SUPPORT))*/

} /* end VCAST_TI_9_20 */
#endif /*(defined(VCAST_NO_TYPE_SUPPORT))*/


/* A typedef */
#if (defined(VCAST_NO_TYPE_SUPPORT))
void VCAST_TI_9_54 ( _c_CemCem_Lin1Fr04_CEM_LIN1_msgType *vcast_param ) 
{
  /* User code: type is not supported */
  vcast_not_supported();
} /* end VCAST_TI_9_54 */
#else /*(defined(VCAST_NO_TYPE_SUPPORT))*/
void VCAST_TI_9_54 ( _c_CemCem_Lin1Fr04_CEM_LIN1_msgType *vcast_param ) 
{
#if (defined(VCAST_NO_TYPE_SUPPORT))
  /* User code: type is not supported */
  vcast_not_supported();
#else /*(defined(VCAST_NO_TYPE_SUPPORT))*/
  {
    switch ( vcast_get_param () ) { /* Choose field member */
      /* Setting member variable vcast_param->unused0 */
      case 1: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->unused0;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->unused0 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 1*/
      } /* end case */
      /* Setting member variable vcast_param->unused1 */
      case 2: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->unused1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->unused1 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 2*/
      } /* end case */
      /* Setting member variable vcast_param->unused2 */
      case 3: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->unused2;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->unused2 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 3*/
      } /* end case */
      /* Setting member variable vcast_param->unused3 */
      case 4: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->unused3;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->unused3 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 4*/
      } /* end case */
      /* Setting member variable vcast_param->unused4 */
      case 5: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->unused4;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->unused4 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 5*/
      } /* end case */
      /* Setting member variable vcast_param->unused5 */
      case 6: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->unused5;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 4, vCAST_false );
        vcast_param->unused5 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 6*/
      } /* end case */
      /* Setting member variable vcast_param->RainSnsrLiThd_CEM_LIN1 */
      case 7: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->RainSnsrLiThd_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 4, vCAST_false );
        vcast_param->RainSnsrLiThd_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 7*/
      } /* end case */
      /* Setting member variable vcast_param->unused6 */
      case 8: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->unused6;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->unused6 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 8*/
      } /* end case */
      default:
        vCAST_TOOL_ERROR = vCAST_true;
    } /* end switch */ 
  }
#endif /*(defined(VCAST_NO_TYPE_SUPPORT))*/

} /* end VCAST_TI_9_54 */
#endif /*(defined(VCAST_NO_TYPE_SUPPORT))*/


/* A typedef */
#if (defined(VCAST_NO_TYPE_SUPPORT))
void VCAST_TI_9_49 ( _c_CemCem_Lin1Fr03_CEM_LIN1_msgType *vcast_param ) 
{
  /* User code: type is not supported */
  vcast_not_supported();
} /* end VCAST_TI_9_49 */
#else /*(defined(VCAST_NO_TYPE_SUPPORT))*/
void VCAST_TI_9_49 ( _c_CemCem_Lin1Fr03_CEM_LIN1_msgType *vcast_param ) 
{
#if (defined(VCAST_NO_TYPE_SUPPORT))
  /* User code: type is not supported */
  vcast_not_supported();
#else /*(defined(VCAST_NO_TYPE_SUPPORT))*/
  {
    switch ( vcast_get_param () ) { /* Choose field member */
      /* Setting member variable vcast_param->RainSnsrSnvtyForUsrSnvty0_CEM_LIN1 */
      case 1: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->RainSnsrSnvtyForUsrSnvty0_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 4, vCAST_false );
        vcast_param->RainSnsrSnvtyForUsrSnvty0_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 1*/
      } /* end case */
      /* Setting member variable vcast_param->RainSnsrSnvtyForUsrSnvty1_CEM_LIN1 */
      case 2: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->RainSnsrSnvtyForUsrSnvty1_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 4, vCAST_false );
        vcast_param->RainSnsrSnvtyForUsrSnvty1_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 2*/
      } /* end case */
      /* Setting member variable vcast_param->RainSnsrSnvtyForUsrSnvty2_CEM_LIN1 */
      case 3: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->RainSnsrSnvtyForUsrSnvty2_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 4, vCAST_false );
        vcast_param->RainSnsrSnvtyForUsrSnvty2_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 3*/
      } /* end case */
      /* Setting member variable vcast_param->RainSnsrSnvtyForUsrSnvty3_CEM_LIN1 */
      case 4: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->RainSnsrSnvtyForUsrSnvty3_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 4, vCAST_false );
        vcast_param->RainSnsrSnvtyForUsrSnvty3_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 4*/
      } /* end case */
      /* Setting member variable vcast_param->RainSnsrSnvtyForUsrSnvty4_CEM_LIN1 */
      case 5: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->RainSnsrSnvtyForUsrSnvty4_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 4, vCAST_false );
        vcast_param->RainSnsrSnvtyForUsrSnvty4_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 5*/
      } /* end case */
      /* Setting member variable vcast_param->RainSnsrSnvtyForUsrSnvty5_CEM_LIN1 */
      case 6: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->RainSnsrSnvtyForUsrSnvty5_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 4, vCAST_false );
        vcast_param->RainSnsrSnvtyForUsrSnvty5_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 6*/
      } /* end case */
      /* Setting member variable vcast_param->RainSnsrSnvtyForUsrSnvty6_CEM_LIN1 */
      case 7: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->RainSnsrSnvtyForUsrSnvty6_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 4, vCAST_false );
        vcast_param->RainSnsrSnvtyForUsrSnvty6_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 7*/
      } /* end case */
      /* Setting member variable vcast_param->VehTyp_CEM_LIN1 */
      case 8: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->VehTyp_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 4, vCAST_false );
        vcast_param->VehTyp_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 8*/
      } /* end case */
      /* Setting member variable vcast_param->WindCorrnValAmb_CEM_LIN1 */
      case 9: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->WindCorrnValAmb_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->WindCorrnValAmb_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 9*/
      } /* end case */
      /* Setting member variable vcast_param->WindCorrnValFrnt_CEM_LIN1 */
      case 10: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->WindCorrnValFrnt_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->WindCorrnValFrnt_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 10*/
      } /* end case */
      /* Setting member variable vcast_param->WindCorrnValHud_CEM_LIN1 */
      case 11: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->WindCorrnValHud_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->WindCorrnValHud_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 11*/
      } /* end case */
      /* Setting member variable vcast_param->FrqCfg_CEM_LIN1 */
      case 12: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->FrqCfg_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 4, vCAST_false );
        vcast_param->FrqCfg_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 12*/
      } /* end case */
      /* Setting member variable vcast_param->ReAdaptReq_CEM_LIN1 */
      case 13: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->ReAdaptReq_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->ReAdaptReq_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 13*/
      } /* end case */
      /* Setting member variable vcast_param->unused0 */
      case 14: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->unused0;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 3, vCAST_false );
        vcast_param->unused0 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 14*/
      } /* end case */
      default:
        vCAST_TOOL_ERROR = vCAST_true;
    } /* end switch */ 
  }
#endif /*(defined(VCAST_NO_TYPE_SUPPORT))*/

} /* end VCAST_TI_9_49 */
#endif /*(defined(VCAST_NO_TYPE_SUPPORT))*/


/* A typedef */
#if (defined(VCAST_NO_TYPE_SUPPORT))
void VCAST_TI_9_52 ( _c_CemCem_Lin1Fr02_CEM_LIN1_msgType *vcast_param ) 
{
  /* User code: type is not supported */
  vcast_not_supported();
} /* end VCAST_TI_9_52 */
#else /*(defined(VCAST_NO_TYPE_SUPPORT))*/
void VCAST_TI_9_52 ( _c_CemCem_Lin1Fr02_CEM_LIN1_msgType *vcast_param ) 
{
#if (defined(VCAST_NO_TYPE_SUPPORT))
  /* User code: type is not supported */
  vcast_not_supported();
#else /*(defined(VCAST_NO_TYPE_SUPPORT))*/
  {
    switch ( vcast_get_param () ) { /* Choose field member */
      /* Setting member variable vcast_param->AmbTForVisy_CEM_LIN1 */
      case 1: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->AmbTForVisy_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->AmbTForVisy_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 1*/
      } /* end case */
      /* Setting member variable vcast_param->unused0 */
      case 2: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->unused0;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->unused0 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 2*/
      } /* end case */
      /* Setting member variable vcast_param->unused1 */
      case 3: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->unused1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->unused1 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 3*/
      } /* end case */
      /* Setting member variable vcast_param->unused2 */
      case 4: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->unused2;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->unused2 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 4*/
      } /* end case */
      /* Setting member variable vcast_param->unused3 */
      case 5: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->unused3;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->unused3 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 5*/
      } /* end case */
      /* Setting member variable vcast_param->unused4 */
      case 6: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->unused4;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->unused4 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 6*/
      } /* end case */
      /* Setting member variable vcast_param->unused5 */
      case 7: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->unused5;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->unused5 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 7*/
      } /* end case */
      default:
        vCAST_TOOL_ERROR = vCAST_true;
    } /* end switch */ 
  }
#endif /*(defined(VCAST_NO_TYPE_SUPPORT))*/

} /* end VCAST_TI_9_52 */
#endif /*(defined(VCAST_NO_TYPE_SUPPORT))*/


/* An array */
#if (defined(VCAST_NO_TYPE_SUPPORT))
void VCAST_TI_9_107 ( unsigned char vcast_param[6] ) 
{
  /* User code: type is not supported */
  vcast_not_supported();
} /* end VCAST_TI_9_107 */
#else /*(defined(VCAST_NO_TYPE_SUPPORT))*/
void VCAST_TI_9_107 ( unsigned char vcast_param[6] ) 
{
  {
    int VCAST_TI_9_107_array_index = 0;
    int VCAST_TI_9_107_index = 0;
    int VCAST_TI_9_107_first, VCAST_TI_9_107_last;
    int VCAST_TI_9_107_more_data; /* true if there is more data in the current command */
    int VCAST_TI_9_107_local_field = 0;
    int VCAST_TI_9_107_value_printed = 0;
    int VCAST_TI_9_107_is_string = (VCAST_FIND_INDEX()==-1);


    vcast_get_range_value (&VCAST_TI_9_107_first, &VCAST_TI_9_107_last, &VCAST_TI_9_107_more_data);
    VCAST_TI_9_107_local_field = vCAST_DATA_FIELD;
    if ( vCAST_SIZE && (!VCAST_TI_9_107_more_data)) { /* get the size of the array */
      vectorcast_fprint_integer (vCAST_OUTPUT_FILE,6);
      vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
      vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n");
    } else {
      int VCAST_TI_9_107_upper = 6;
      for (VCAST_TI_9_107_array_index=0; VCAST_TI_9_107_array_index< VCAST_TI_9_107_upper; VCAST_TI_9_107_array_index++){
        if ( (VCAST_TI_9_107_index >= VCAST_TI_9_107_first) && ( VCAST_TI_9_107_index <= VCAST_TI_9_107_last)){
          if ( VCAST_TI_9_107_is_string )
            VCAST_TI_STRING ( (char**)&vcast_param, sizeof ( vcast_param ), 1,VCAST_TI_9_107_upper);
          else
            VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param[VCAST_TI_9_107_index]))));
          VCAST_TI_9_107_value_printed = 1;
          vCAST_DATA_FIELD = VCAST_TI_9_107_local_field;
        } /* if */
        if (VCAST_TI_9_107_index >= VCAST_TI_9_107_last)
          break;
        VCAST_TI_9_107_index++;
      } /* loop */
      if ((vCAST_COMMAND == vCAST_PRINT)&&(!VCAST_TI_9_107_value_printed))
        vectorcast_fprint_string(vCAST_OUTPUT_FILE,"<<past end of array>>\n");
    } /* if */
  }
} /* end VCAST_TI_9_107 */
#endif /*(defined(VCAST_NO_TYPE_SUPPORT))*/


/* A typedef */
#if (defined(VCAST_NO_TYPE_SUPPORT))
void VCAST_TI_9_12 ( _c_CemCem_Lin1Fr01_CEM_LIN1_msgType *vcast_param ) 
{
  /* User code: type is not supported */
  vcast_not_supported();
} /* end VCAST_TI_9_12 */
#else /*(defined(VCAST_NO_TYPE_SUPPORT))*/
void VCAST_TI_9_12 ( _c_CemCem_Lin1Fr01_CEM_LIN1_msgType *vcast_param ) 
{
#if (defined(VCAST_NO_TYPE_SUPPORT))
  /* User code: type is not supported */
  vcast_not_supported();
#else /*(defined(VCAST_NO_TYPE_SUPPORT))*/
  {
    switch ( vcast_get_param () ) { /* Choose field member */
      /* Setting member variable vcast_param->VehSpdForWipg_CEM_LIN1 */
      case 1: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->VehSpdForWipg_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->VehSpdForWipg_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 1*/
      } /* end case */
      /* Setting member variable vcast_param->WipgPwrActvnSafeWipgPwrAcsyModSafe_CEM_LIN1 */
      case 2: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->WipgPwrActvnSafeWipgPwrAcsyModSafe_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 2, vCAST_false );
        vcast_param->WipgPwrActvnSafeWipgPwrAcsyModSafe_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 2*/
      } /* end case */
      /* Setting member variable vcast_param->WipgPwrActvnSafeWipgPwrDrvgModSafe_CEM_LIN1 */
      case 3: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->WipgPwrActvnSafeWipgPwrDrvgModSafe_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 2, vCAST_false );
        vcast_param->WipgPwrActvnSafeWipgPwrDrvgModSafe_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 3*/
      } /* end case */
      /* Setting member variable vcast_param->RainSensActvn_CEM_LIN1 */
      case 4: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->RainSensActvn_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->RainSensActvn_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 4*/
      } /* end case */
      /* Setting member variable vcast_param->WshrLvrPosnSafe_CEM_LIN1 */
      case 5: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->WshrLvrPosnSafe_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 2, vCAST_false );
        vcast_param->WshrLvrPosnSafe_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 5*/
      } /* end case */
      /* Setting member variable vcast_param->unused0 */
      case 6: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->unused0;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->unused0 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 6*/
      } /* end case */
      /* Setting member variable vcast_param->WiprMotFrntLvrCmdSafeLvrInHiSpdPosnSafe_CEM_LIN1 */
      case 7: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->WiprMotFrntLvrCmdSafeLvrInHiSpdPosnSafe_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 2, vCAST_false );
        vcast_param->WiprMotFrntLvrCmdSafeLvrInHiSpdPosnSafe_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 7*/
      } /* end case */
      /* Setting member variable vcast_param->WiprMotFrntLvrCmdSafeLvrInLoSpdPosnSafe_CEM_LIN1 */
      case 8: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->WiprMotFrntLvrCmdSafeLvrInLoSpdPosnSafe_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 2, vCAST_false );
        vcast_param->WiprMotFrntLvrCmdSafeLvrInLoSpdPosnSafe_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 8*/
      } /* end case */
      /* Setting member variable vcast_param->WiprMotFrntLvrCmdSafeLvrInSnglStrokePos_CEM_LIN1 */
      case 9: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->WiprMotFrntLvrCmdSafeLvrInSnglStrokePos_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->WiprMotFrntLvrCmdSafeLvrInSnglStrokePos_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 9*/
      } /* end case */
      /* Setting member variable vcast_param->WiprMotFrntLvrCmdSafeLvrInIntlPosn_CEM_LIN1 */
      case 10: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->WiprMotFrntLvrCmdSafeLvrInIntlPosn_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->WiprMotFrntLvrCmdSafeLvrInIntlPosn_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 10*/
      } /* end case */
      /* Setting member variable vcast_param->HomeLinkEna_CEM_LIN1 */
      case 11: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->HomeLinkEna_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 2, vCAST_false );
        vcast_param->HomeLinkEna_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 11*/
      } /* end case */
      /* Setting member variable vcast_param->WiprMotIntlCmd_CEM_LIN1 */
      case 12: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->WiprMotIntlCmd_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 3, vCAST_false );
        vcast_param->WiprMotIntlCmd_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 12*/
      } /* end case */
      /* Setting member variable vcast_param->WiprPosnForSrvReq_CEM_LIN1 */
      case 13: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->WiprPosnForSrvReq_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->WiprPosnForSrvReq_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 13*/
      } /* end case */
      /* Setting member variable vcast_param->unused1 */
      case 14: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->unused1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 4, vCAST_false );
        vcast_param->unused1 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 14*/
      } /* end case */
      /* Setting member variable vcast_param->IntrMirrCmdIntrMirrDimSnvty_CEM_LIN1 */
      case 15: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->IntrMirrCmdIntrMirrDimSnvty_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 2, vCAST_false );
        vcast_param->IntrMirrCmdIntrMirrDimSnvty_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 15*/
      } /* end case */
      /* Setting member variable vcast_param->IntrMirrCmdDrvrSide_CEM_LIN1 */
      case 16: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->IntrMirrCmdDrvrSide_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->IntrMirrCmdDrvrSide_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 16*/
      } /* end case */
      /* Setting member variable vcast_param->IntrMirrCmdIntrMirrWindHeatrCmpMag_CEM_LIN1 */
      case 17: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->IntrMirrCmdIntrMirrWindHeatrCmpMag_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->IntrMirrCmdIntrMirrWindHeatrCmpMag_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 17*/
      } /* end case */
      /* Setting member variable vcast_param->IntrMirrCmdIntrMirrEna_CEM_LIN1 */
      case 18: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->IntrMirrCmdIntrMirrEna_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->IntrMirrCmdIntrMirrEna_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 18*/
      } /* end case */
      /* Setting member variable vcast_param->IntrMirrCmdIntrMirrInhbDim_CEM_LIN1 */
      case 19: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->IntrMirrCmdIntrMirrInhbDim_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->IntrMirrCmdIntrMirrInhbDim_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 19*/
      } /* end case */
      /* Setting member variable vcast_param->IntrMirrCmdIntrMirrDiagcRst_CEM_LIN1 */
      case 20: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->IntrMirrCmdIntrMirrDiagcRst_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->IntrMirrCmdIntrMirrDiagcRst_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 20*/
      } /* end case */
      /* Setting member variable vcast_param->IntrMirrCmdIntrMirrAsyFanCmpMag_CEM_LIN1 */
      case 21: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->IntrMirrCmdIntrMirrAsyFanCmpMag_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->IntrMirrCmdIntrMirrAsyFanCmpMag_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 21*/
      } /* end case */
      /* Setting member variable vcast_param->WiprMotFrntOffsAg_CEM_LIN1 */
      case 22: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->WiprMotFrntOffsAg_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 4, vCAST_false );
        vcast_param->WiprMotFrntOffsAg_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 22*/
      } /* end case */
      /* Setting member variable vcast_param->unused2 */
      case 23: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->unused2;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 4, vCAST_false );
        vcast_param->unused2 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 23*/
      } /* end case */
      default:
        vCAST_TOOL_ERROR = vCAST_true;
    } /* end switch */ 
  }
#endif /*(defined(VCAST_NO_TYPE_SUPPORT))*/

} /* end VCAST_TI_9_12 */
#endif /*(defined(VCAST_NO_TYPE_SUPPORT))*/


/* A typedef */
#if (defined(VCAST_NO_TYPE_SUPPORT))
void VCAST_TI_9_16 ( RS_Bit_Feld *vcast_param ) 
{
  /* User code: type is not supported */
  vcast_not_supported();
} /* end VCAST_TI_9_16 */
#else /*(defined(VCAST_NO_TYPE_SUPPORT))*/
void VCAST_TI_9_16 ( RS_Bit_Feld *vcast_param ) 
{
#if (defined(VCAST_NO_TYPE_SUPPORT))
  /* User code: type is not supported */
  vcast_not_supported();
#else /*(defined(VCAST_NO_TYPE_SUPPORT))*/
  {
    switch ( vcast_get_param () ) { /* Choose field member */
      /* Setting member variable vcast_param->B7 */
      case 1: { 
        VCAST_LONGEST_INT VCAST_TI_9_6_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->B7;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->B7 = ( unsigned  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 1*/
      } /* end case */
      /* Setting member variable vcast_param->B6 */
      case 2: { 
        VCAST_LONGEST_INT VCAST_TI_9_6_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->B6;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->B6 = ( unsigned  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 2*/
      } /* end case */
      /* Setting member variable vcast_param->B5 */
      case 3: { 
        VCAST_LONGEST_INT VCAST_TI_9_6_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->B5;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->B5 = ( unsigned  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 3*/
      } /* end case */
      /* Setting member variable vcast_param->B4 */
      case 4: { 
        VCAST_LONGEST_INT VCAST_TI_9_6_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->B4;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->B4 = ( unsigned  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 4*/
      } /* end case */
      /* Setting member variable vcast_param->B3 */
      case 5: { 
        VCAST_LONGEST_INT VCAST_TI_9_6_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->B3;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->B3 = ( unsigned  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 5*/
      } /* end case */
      /* Setting member variable vcast_param->B2 */
      case 6: { 
        VCAST_LONGEST_INT VCAST_TI_9_6_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->B2;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->B2 = ( unsigned  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 6*/
      } /* end case */
      /* Setting member variable vcast_param->B1 */
      case 7: { 
        VCAST_LONGEST_INT VCAST_TI_9_6_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->B1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->B1 = ( unsigned  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 7*/
      } /* end case */
      /* Setting member variable vcast_param->B0 */
      case 8: { 
        VCAST_LONGEST_INT VCAST_TI_9_6_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->B0;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->B0 = ( unsigned  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 8*/
      } /* end case */
      default:
        vCAST_TOOL_ERROR = vCAST_true;
    } /* end switch */ 
  }
#endif /*(defined(VCAST_NO_TYPE_SUPPORT))*/

} /* end VCAST_TI_9_16 */
#endif /*(defined(VCAST_NO_TYPE_SUPPORT))*/


/* A typedef */
#if (defined(VCAST_NO_TYPE_SUPPORT))
void VCAST_TI_9_30 ( ASIC_ALI_Meas_t *vcast_param ) 
{
  /* User code: type is not supported */
  vcast_not_supported();
} /* end VCAST_TI_9_30 */
#else /*(defined(VCAST_NO_TYPE_SUPPORT))*/
void VCAST_TI_9_30 ( ASIC_ALI_Meas_t *vcast_param ) 
{
#if (defined(VCAST_NO_TYPE_SUPPORT))
  /* User code: type is not supported */
  vcast_not_supported();
#else /*(defined(VCAST_NO_TYPE_SUPPORT))*/
  {
    switch ( vcast_get_param () ) { /* Choose field member */
      /* Setting member variable vcast_param->ad */
      case 1: { 
        VCAST_TI_9_6 ( ((unsigned *)(&(vcast_param->ad))));
        break; /* end case 1*/
      } /* end case */
      /* Setting member variable vcast_param->avg */
      case 2: { 
        VCAST_TI_9_6 ( ((unsigned *)(&(vcast_param->avg))));
        break; /* end case 2*/
      } /* end case */
      default:
        vCAST_TOOL_ERROR = vCAST_true;
    } /* end switch */ 
  }
#endif /*(defined(VCAST_NO_TYPE_SUPPORT))*/

} /* end VCAST_TI_9_30 */
#endif /*(defined(VCAST_NO_TYPE_SUPPORT))*/


/* An array */
#if (defined(VCAST_NO_TYPE_SUPPORT))
void VCAST_TI_9_61 ( unsigned char vcast_param[2] ) 
{
  /* User code: type is not supported */
  vcast_not_supported();
} /* end VCAST_TI_9_61 */
#else /*(defined(VCAST_NO_TYPE_SUPPORT))*/
void VCAST_TI_9_61 ( unsigned char vcast_param[2] ) 
{
  {
    int VCAST_TI_9_61_array_index = 0;
    int VCAST_TI_9_61_index = 0;
    int VCAST_TI_9_61_first, VCAST_TI_9_61_last;
    int VCAST_TI_9_61_more_data; /* true if there is more data in the current command */
    int VCAST_TI_9_61_local_field = 0;
    int VCAST_TI_9_61_value_printed = 0;
    int VCAST_TI_9_61_is_string = (VCAST_FIND_INDEX()==-1);


    vcast_get_range_value (&VCAST_TI_9_61_first, &VCAST_TI_9_61_last, &VCAST_TI_9_61_more_data);
    VCAST_TI_9_61_local_field = vCAST_DATA_FIELD;
    if ( vCAST_SIZE && (!VCAST_TI_9_61_more_data)) { /* get the size of the array */
      vectorcast_fprint_integer (vCAST_OUTPUT_FILE,2);
      vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
      vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n");
    } else {
      int VCAST_TI_9_61_upper = 2;
      for (VCAST_TI_9_61_array_index=0; VCAST_TI_9_61_array_index< VCAST_TI_9_61_upper; VCAST_TI_9_61_array_index++){
        if ( (VCAST_TI_9_61_index >= VCAST_TI_9_61_first) && ( VCAST_TI_9_61_index <= VCAST_TI_9_61_last)){
          if ( VCAST_TI_9_61_is_string )
            VCAST_TI_STRING ( (char**)&vcast_param, sizeof ( vcast_param ), 1,VCAST_TI_9_61_upper);
          else
            VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param[VCAST_TI_9_61_index]))));
          VCAST_TI_9_61_value_printed = 1;
          vCAST_DATA_FIELD = VCAST_TI_9_61_local_field;
        } /* if */
        if (VCAST_TI_9_61_index >= VCAST_TI_9_61_last)
          break;
        VCAST_TI_9_61_index++;
      } /* loop */
      if ((vCAST_COMMAND == vCAST_PRINT)&&(!VCAST_TI_9_61_value_printed))
        vectorcast_fprint_string(vCAST_OUTPUT_FILE,"<<past end of array>>\n");
    } /* if */
  }
} /* end VCAST_TI_9_61 */
#endif /*(defined(VCAST_NO_TYPE_SUPPORT))*/


/* An array */
#if (defined(VCAST_NO_TYPE_SUPPORT))
void VCAST_TI_9_69 ( s_rb_PrametersStruct_g vcast_param[4] ) 
{
  /* User code: type is not supported */
  vcast_not_supported();
} /* end VCAST_TI_9_69 */
#else /*(defined(VCAST_NO_TYPE_SUPPORT))*/
void VCAST_TI_9_69 ( s_rb_PrametersStruct_g vcast_param[4] ) 
{
  {
    int VCAST_TI_9_69_array_index = 0;
    int VCAST_TI_9_69_index = 0;
    int VCAST_TI_9_69_first, VCAST_TI_9_69_last;
    int VCAST_TI_9_69_more_data; /* true if there is more data in the current command */
    int VCAST_TI_9_69_local_field = 0;
    int VCAST_TI_9_69_value_printed = 0;


    vcast_get_range_value (&VCAST_TI_9_69_first, &VCAST_TI_9_69_last, &VCAST_TI_9_69_more_data);
    VCAST_TI_9_69_local_field = vCAST_DATA_FIELD;
    if ( vCAST_SIZE && (!VCAST_TI_9_69_more_data)) { /* get the size of the array */
      vectorcast_fprint_integer (vCAST_OUTPUT_FILE,4);
      vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
      vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n");
    } else {
      int VCAST_TI_9_69_upper = 4;
      for (VCAST_TI_9_69_array_index=0; VCAST_TI_9_69_array_index< VCAST_TI_9_69_upper; VCAST_TI_9_69_array_index++){
        if ( (VCAST_TI_9_69_index >= VCAST_TI_9_69_first) && ( VCAST_TI_9_69_index <= VCAST_TI_9_69_last)){
          VCAST_TI_9_67 ( ((s_rb_PrametersStruct_g *)(&(vcast_param[VCAST_TI_9_69_index]))));
          VCAST_TI_9_69_value_printed = 1;
          vCAST_DATA_FIELD = VCAST_TI_9_69_local_field;
        } /* if */
        if (VCAST_TI_9_69_index >= VCAST_TI_9_69_last)
          break;
        VCAST_TI_9_69_index++;
      } /* loop */
      if ((vCAST_COMMAND == vCAST_PRINT)&&(!VCAST_TI_9_69_value_printed))
        vectorcast_fprint_string(vCAST_OUTPUT_FILE,"<<past end of array>>\n");
    } /* if */
  }
} /* end VCAST_TI_9_69 */
#endif /*(defined(VCAST_NO_TYPE_SUPPORT))*/


/* An array */
#if (defined(VCAST_NO_TYPE_SUPPORT))
void VCAST_TI_9_57 ( unsigned char vcast_param[9] ) 
{
  /* User code: type is not supported */
  vcast_not_supported();
} /* end VCAST_TI_9_57 */
#else /*(defined(VCAST_NO_TYPE_SUPPORT))*/
void VCAST_TI_9_57 ( unsigned char vcast_param[9] ) 
{
  {
    int VCAST_TI_9_57_array_index = 0;
    int VCAST_TI_9_57_index = 0;
    int VCAST_TI_9_57_first, VCAST_TI_9_57_last;
    int VCAST_TI_9_57_more_data; /* true if there is more data in the current command */
    int VCAST_TI_9_57_local_field = 0;
    int VCAST_TI_9_57_value_printed = 0;
    int VCAST_TI_9_57_is_string = (VCAST_FIND_INDEX()==-1);


    vcast_get_range_value (&VCAST_TI_9_57_first, &VCAST_TI_9_57_last, &VCAST_TI_9_57_more_data);
    VCAST_TI_9_57_local_field = vCAST_DATA_FIELD;
    if ( vCAST_SIZE && (!VCAST_TI_9_57_more_data)) { /* get the size of the array */
      vectorcast_fprint_integer (vCAST_OUTPUT_FILE,9);
      vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
      vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n");
    } else {
      int VCAST_TI_9_57_upper = 9;
      for (VCAST_TI_9_57_array_index=0; VCAST_TI_9_57_array_index< VCAST_TI_9_57_upper; VCAST_TI_9_57_array_index++){
        if ( (VCAST_TI_9_57_index >= VCAST_TI_9_57_first) && ( VCAST_TI_9_57_index <= VCAST_TI_9_57_last)){
          if ( VCAST_TI_9_57_is_string )
            VCAST_TI_STRING ( (char**)&vcast_param, sizeof ( vcast_param ), 1,VCAST_TI_9_57_upper);
          else
            VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param[VCAST_TI_9_57_index]))));
          VCAST_TI_9_57_value_printed = 1;
          vCAST_DATA_FIELD = VCAST_TI_9_57_local_field;
        } /* if */
        if (VCAST_TI_9_57_index >= VCAST_TI_9_57_last)
          break;
        VCAST_TI_9_57_index++;
      } /* loop */
      if ((vCAST_COMMAND == vCAST_PRINT)&&(!VCAST_TI_9_57_value_printed))
        vectorcast_fprint_string(vCAST_OUTPUT_FILE,"<<past end of array>>\n");
    } /* if */
  }
} /* end VCAST_TI_9_57 */
#endif /*(defined(VCAST_NO_TYPE_SUPPORT))*/


/* An array */
#if (defined(VCAST_NO_TYPE_SUPPORT))
void VCAST_TI_9_73 ( unsigned char vcast_param[33] ) 
{
  /* User code: type is not supported */
  vcast_not_supported();
} /* end VCAST_TI_9_73 */
#else /*(defined(VCAST_NO_TYPE_SUPPORT))*/
void VCAST_TI_9_73 ( unsigned char vcast_param[33] ) 
{
  {
    int VCAST_TI_9_73_array_index = 0;
    int VCAST_TI_9_73_index = 0;
    int VCAST_TI_9_73_first, VCAST_TI_9_73_last;
    int VCAST_TI_9_73_more_data; /* true if there is more data in the current command */
    int VCAST_TI_9_73_local_field = 0;
    int VCAST_TI_9_73_value_printed = 0;
    int VCAST_TI_9_73_is_string = (VCAST_FIND_INDEX()==-1);


    vcast_get_range_value (&VCAST_TI_9_73_first, &VCAST_TI_9_73_last, &VCAST_TI_9_73_more_data);
    VCAST_TI_9_73_local_field = vCAST_DATA_FIELD;
    if ( vCAST_SIZE && (!VCAST_TI_9_73_more_data)) { /* get the size of the array */
      vectorcast_fprint_integer (vCAST_OUTPUT_FILE,33);
      vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
      vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n");
    } else {
      int VCAST_TI_9_73_upper = 33;
      for (VCAST_TI_9_73_array_index=0; VCAST_TI_9_73_array_index< VCAST_TI_9_73_upper; VCAST_TI_9_73_array_index++){
        if ( (VCAST_TI_9_73_index >= VCAST_TI_9_73_first) && ( VCAST_TI_9_73_index <= VCAST_TI_9_73_last)){
          if ( VCAST_TI_9_73_is_string )
            VCAST_TI_STRING ( (char**)&vcast_param, sizeof ( vcast_param ), 1,VCAST_TI_9_73_upper);
          else
            VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param[VCAST_TI_9_73_index]))));
          VCAST_TI_9_73_value_printed = 1;
          vCAST_DATA_FIELD = VCAST_TI_9_73_local_field;
        } /* if */
        if (VCAST_TI_9_73_index >= VCAST_TI_9_73_last)
          break;
        VCAST_TI_9_73_index++;
      } /* loop */
      if ((vCAST_COMMAND == vCAST_PRINT)&&(!VCAST_TI_9_73_value_printed))
        vectorcast_fprint_string(vCAST_OUTPUT_FILE,"<<past end of array>>\n");
    } /* if */
  }
} /* end VCAST_TI_9_73 */
#endif /*(defined(VCAST_NO_TYPE_SUPPORT))*/


/* A struct */
#if (defined(VCAST_NO_TYPE_SUPPORT))
void VCAST_TI_9_5 ( struct _c_bits8 *vcast_param ) 
{
  /* User code: type is not supported */
  vcast_not_supported();
} /* end VCAST_TI_9_5 */
#else /*(defined(VCAST_NO_TYPE_SUPPORT))*/
void VCAST_TI_9_5 ( struct _c_bits8 *vcast_param ) 
{
  {
    switch ( vcast_get_param () ) { /* Choose field member */
      /* Setting member variable vcast_param->b0 */
      case 1: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->b0;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->b0 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 1*/
      } /* end case */
      /* Setting member variable vcast_param->b1 */
      case 2: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->b1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->b1 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 2*/
      } /* end case */
      /* Setting member variable vcast_param->b2 */
      case 3: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->b2;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->b2 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 3*/
      } /* end case */
      /* Setting member variable vcast_param->b3 */
      case 4: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->b3;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->b3 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 4*/
      } /* end case */
      /* Setting member variable vcast_param->b4 */
      case 5: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->b4;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->b4 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 5*/
      } /* end case */
      /* Setting member variable vcast_param->b5 */
      case 6: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->b5;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->b5 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 6*/
      } /* end case */
      /* Setting member variable vcast_param->b6 */
      case 7: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->b6;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->b6 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 7*/
      } /* end case */
      /* Setting member variable vcast_param->b7 */
      case 8: { 
        VCAST_LONGEST_INT VCAST_TI_9_9_ti_bitfield_placeholder = (VCAST_LONGEST_INT) vcast_param->b7;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_9_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->b7 = ( unsigned char  ) VCAST_TI_9_9_ti_bitfield_placeholder;
        break; /* end case 8*/
      } /* end case */
      default:
        vCAST_TOOL_ERROR = vCAST_true;
    } /* end switch */ 
  }
} /* end VCAST_TI_9_5 */
#endif /*(defined(VCAST_NO_TYPE_SUPPORT))*/


/* A typedef */
#if (defined(VCAST_NO_TYPE_SUPPORT))
void VCAST_TI_9_67 ( s_rb_PrametersStruct_g *vcast_param ) 
{
  /* User code: type is not supported */
  vcast_not_supported();
} /* end VCAST_TI_9_67 */
#else /*(defined(VCAST_NO_TYPE_SUPPORT))*/
void VCAST_TI_9_67 ( s_rb_PrametersStruct_g *vcast_param ) 
{
#if (defined(VCAST_NO_TYPE_SUPPORT))
  /* User code: type is not supported */
  vcast_not_supported();
#else /*(defined(VCAST_NO_TYPE_SUPPORT))*/
  {
    switch ( vcast_get_param () ) { /* Choose field member */
      /* Setting member variable vcast_param->Stufe1_OG */
      case 1: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->Stufe1_OG))));
        break; /* end case 1*/
      } /* end case */
      /* Setting member variable vcast_param->Stufe1_UG */
      case 2: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->Stufe1_UG))));
        break; /* end case 2*/
      } /* end case */
      /* Setting member variable vcast_param->Ep_St2_Epr_In_St2 */
      case 3: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->Ep_St2_Epr_In_St2))));
        break; /* end case 3*/
      } /* end case */
      /* Setting member variable vcast_param->Schwelle_Schwall */
      case 4: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->Schwelle_Schwall))));
        break; /* end case 4*/
      } /* end case */
      /* Setting member variable vcast_param->CW_AnsamlungAdditOffset */
      case 5: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->CW_AnsamlungAdditOffset))));
        break; /* end case 5*/
      } /* end case */
      /* Setting member variable vcast_param->dec_Int_Sp_off */
      case 6: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->dec_Int_Sp_off))));
        break; /* end case 6*/
      } /* end case */
      /* Setting member variable vcast_param->Dec_Stx_Speicher */
      case 7: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->Dec_Stx_Speicher))));
        break; /* end case 7*/
      } /* end case */
      /* Setting member variable vcast_param->dec_Ovr_Speicher */
      case 8: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->dec_Ovr_Speicher))));
        break; /* end case 8*/
      } /* end case */
      /* Setting member variable vcast_param->Empf_Faktor_ST2_Offs */
      case 9: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->Empf_Faktor_ST2_Offs))));
        break; /* end case 9*/
      } /* end case */
      /* Setting member variable vcast_param->Max_Signallaenge */
      case 10: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->Max_Signallaenge))));
        break; /* end case 10*/
      } /* end case */
      /* Setting member variable vcast_param->rb_Stufe1_with_Int_og */
      case 11: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->rb_Stufe1_with_Int_og))));
        break; /* end case 11*/
      } /* end case */
      /* Setting member variable vcast_param->Nachwisch_4_ST1_min */
      case 12: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->Nachwisch_4_ST1_min))));
        break; /* end case 12*/
      } /* end case */
      /* Setting member variable vcast_param->Nachwisch_3 */
      case 13: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->Nachwisch_3))));
        break; /* end case 13*/
      } /* end case */
      /* Setting member variable vcast_param->Nachwisch_2 */
      case 14: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->Nachwisch_2))));
        break; /* end case 14*/
      } /* end case */
      /* Setting member variable vcast_param->RSEmpfFactorScaling */
      case 15: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->RSEmpfFactorScaling))));
        break; /* end case 15*/
      } /* end case */
      /* Setting member variable vcast_param->SchlierenFlag1 */
      case 16: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->SchlierenFlag1))));
        break; /* end case 16*/
      } /* end case */
      /* Setting member variable vcast_param->sig_ans_schw_offs */
      case 17: { 
        VCAST_TI_9_9 ( ((unsigned char *)(&(vcast_param->sig_ans_schw_offs))));
        break; /* end case 17*/
      } /* end case */
      default:
        vCAST_TOOL_ERROR = vCAST_true;
    } /* end switch */ 
  }
#endif /*(defined(VCAST_NO_TYPE_SUPPORT))*/

} /* end VCAST_TI_9_67 */
#endif /*(defined(VCAST_NO_TYPE_SUPPORT))*/


#ifdef VCAST_PARADIGM_ADD_SEGMENT
#pragma new_codesegment(1)
#endif
void VCAST_TI_RANGE_DATA_9 ( void ) {
#define VCAST_TI_SCALAR_TYPE "NEW_SCALAR\n"
#define VCAST_TI_ARRAY_TYPE  "NEW_ARRAY\n"
  /* Range Data for TI (scalar) VCAST_TI_8_2 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, VCAST_TI_SCALAR_TYPE );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"900002\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,INT_MIN );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,(INT_MIN / 2) + (INT_MAX / 2) );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,INT_MAX );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n" );
  /* Range Data for TI (array) VCAST_TI_9_4 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, VCAST_TI_ARRAY_TYPE );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"100003\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,1);
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
  /* Range Data for TI (scalar) VCAST_TI_9_6 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, VCAST_TI_SCALAR_TYPE );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"900005\n" );
  vectorcast_fprint_unsigned_integer (vCAST_OUTPUT_FILE,UINT_MIN );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n" );
  vectorcast_fprint_unsigned_integer (vCAST_OUTPUT_FILE,(UINT_MIN / 2) + (UINT_MAX / 2) );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n" );
  vectorcast_fprint_unsigned_integer (vCAST_OUTPUT_FILE,UINT_MAX );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n" );
  /* Range Data for TI (scalar) VCAST_TI_9_9 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, VCAST_TI_SCALAR_TYPE );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"900008\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,UCHAR_MIN );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,(UCHAR_MIN / 2) + (UCHAR_MAX / 2) );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,UCHAR_MAX );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n" );
  /* Range Data for TI (array) VCAST_TI_9_4 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, VCAST_TI_ARRAY_TYPE );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"100004\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,1);
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
  /* Range Data for TI (array) VCAST_TI_9_29 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, VCAST_TI_ARRAY_TYPE );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"100005\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,9);
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
  /* Range Data for TI (scalar) VCAST_TI_9_31 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, VCAST_TI_SCALAR_TYPE );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"900029\n" );
  vectorcast_fprint_unsigned_long (vCAST_OUTPUT_FILE,ULONG_MIN );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n" );
  vectorcast_fprint_unsigned_long (vCAST_OUTPUT_FILE,(ULONG_MIN / 2) + (ULONG_MAX / 2) );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n" );
  vectorcast_fprint_unsigned_long (vCAST_OUTPUT_FILE,ULONG_MAX );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n" );
  /* Range Data for TI (array) VCAST_TI_9_33 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, VCAST_TI_ARRAY_TYPE );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"100006\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,4);
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
  /* Range Data for TI (array) VCAST_TI_9_35 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, VCAST_TI_ARRAY_TYPE );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"100007\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,8);
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
  /* Range Data for TI (array) VCAST_TI_9_50 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, VCAST_TI_ARRAY_TYPE );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"100008\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,7);
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
  /* Range Data for TI (array) VCAST_TI_9_35 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, VCAST_TI_ARRAY_TYPE );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"100009\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,8);
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
  /* Range Data for TI (array) VCAST_TI_9_35 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, VCAST_TI_ARRAY_TYPE );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"100010\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,8);
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
  /* Range Data for TI (array) VCAST_TI_9_35 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, VCAST_TI_ARRAY_TYPE );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"100011\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,8);
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
  /* Range Data for TI (array) VCAST_TI_9_41 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, VCAST_TI_ARRAY_TYPE );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"100012\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,10);
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
  /* Range Data for TI (array) VCAST_TI_9_42 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, VCAST_TI_ARRAY_TYPE );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"100013\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,2);
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
  /* Range Data for TI (array) VCAST_TI_9_43 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, VCAST_TI_ARRAY_TYPE );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"100014\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,5);
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
  /* Range Data for TI (array) VCAST_TI_9_33 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, VCAST_TI_ARRAY_TYPE );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"100015\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,4);
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
  /* Range Data for TI (array) VCAST_TI_9_50 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, VCAST_TI_ARRAY_TYPE );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"100016\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,7);
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
  /* Range Data for TI (array) VCAST_TI_9_57 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, VCAST_TI_ARRAY_TYPE );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"100017\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,9);
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
  /* Range Data for TI (array) VCAST_TI_9_61 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, VCAST_TI_ARRAY_TYPE );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"100021\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,2);
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
  /* Range Data for TI (array) VCAST_TI_9_35 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, VCAST_TI_ARRAY_TYPE );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"100022\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,8);
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
  /* Range Data for TI (array) VCAST_TI_9_33 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, VCAST_TI_ARRAY_TYPE );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"100023\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,4);
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
  /* Range Data for TI (array) VCAST_TI_9_65 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, VCAST_TI_ARRAY_TYPE );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"100025\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,93);
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
  /* Range Data for TI (array) VCAST_TI_9_69 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, VCAST_TI_ARRAY_TYPE );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"100028\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,4);
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
  /* Range Data for TI (array) VCAST_TI_9_107 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, VCAST_TI_ARRAY_TYPE );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"100029\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,6);
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
  /* Range Data for TI (array) VCAST_TI_9_35 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, VCAST_TI_ARRAY_TYPE );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"100030\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,8);
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
  /* Range Data for TI (array) VCAST_TI_9_33 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, VCAST_TI_ARRAY_TYPE );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"100031\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,4);
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
  /* Range Data for TI (array) VCAST_TI_9_73 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, VCAST_TI_ARRAY_TYPE );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"100032\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,33);
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
  /* Range Data for TI (array) VCAST_TI_9_75 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, VCAST_TI_ARRAY_TYPE );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"100034\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,194);
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
  /* Range Data for TI (array) VCAST_TI_9_76 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, VCAST_TI_ARRAY_TYPE );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"100035\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,1);
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
  /* Range Data for TI (array) VCAST_TI_9_76 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, VCAST_TI_ARRAY_TYPE );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"100036\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,1);
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
  /* Range Data for TI (array) VCAST_TI_9_76 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, VCAST_TI_ARRAY_TYPE );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"100056\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,1);
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
  /* Range Data for TI (array) VCAST_TI_9_50 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, VCAST_TI_ARRAY_TYPE );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"100058\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,7);
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
  /* Range Data for TI (array) VCAST_TI_9_50 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, VCAST_TI_ARRAY_TYPE );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"100060\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,7);
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
  /* Range Data for TI (array) VCAST_TI_9_35 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, VCAST_TI_ARRAY_TYPE );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"100062\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,8);
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
  /* Range Data for TI (array) VCAST_TI_9_50 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, VCAST_TI_ARRAY_TYPE );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"100064\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,7);
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
  /* Range Data for TI (array) VCAST_TI_9_107 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, VCAST_TI_ARRAY_TYPE );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"100066\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,6);
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
}
/* Include the file which contains function implementations
for stub processing and value/expected user code */
#include "G5_RLS_LIN_GEELY2DOT0_uc.c"

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
#endif /* VCAST_HEADER_EXPANSION */
