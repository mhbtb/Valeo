void VCAST_RUN_DATA_IF_8( int, int );
void VCAST_RUN_DATA_IF_9( int, int );
void VCAST_TI_RANGE_DATA_8(void);
void VCAST_TI_RANGE_DATA_9(void);
#include "B0000001.h"
#include "S0000002.h"
void vcast_B1_switch( int VCAST_UNIT_INDEX, int VCAST_SUB_INDEX, int VCAST_PARAM_INDEX, char *work )
{
  switch( VCAST_UNIT_INDEX ) {
    case 0:
      switch( VCAST_PARAM_INDEX ) {
        case 0:
          vCAST_SUBPROGRAM = (int)vCAST_VALUE;
          break;
        case 2:
        /* deprecated */
      break;
    case 3:
      vCAST_UNIT = (int)vCAST_VALUE;
      break;
    case 4:
      vCAST_SET_TESTCASE_CONFIGURATION_OPTIONS( VCAST_SUB_INDEX, VCAST_atoi(work), 0 );
      break;
    case 9:
      vCAST_SET_TESTCASE_OPTIONS ( work );
      break;
    default:
      vCAST_TOOL_ERROR = vCAST_true;
      break;
  } /* switch VCAST_PARAM_INDEX */
  break; /* case 0 */
case 1: /* TI RANGE DATA */
  VCAST_TI_RANGE_DATA_8();
  VCAST_TI_RANGE_DATA_9();
  break;
case 8:
  VCAST_RUN_DATA_IF_8(VCAST_SUB_INDEX, VCAST_PARAM_INDEX);
  break;
case 9:
  VCAST_RUN_DATA_IF_9(VCAST_SUB_INDEX, VCAST_PARAM_INDEX);
  break;
case 10: /* PROTOTYPES */
  switch( VCAST_SUB_INDEX ) {
    case 0: /* Defined externs */
      switch( VCAST_PARAM_INDEX ) {
            case 1:
              /* For EEPROM_Struct_PD */
              VCAST_RUN_DATA_IF_9( 0, 35 );
              break;
            case 2:
              /* For rb_Humidity_raw_g */
              VCAST_RUN_DATA_IF_9( 0, 36 );
              break;
            case 3:
              /* For rb_Humidity_g */
              VCAST_RUN_DATA_IF_9( 0, 37 );
              break;
            case 4:
              /* For rw_Temperature_raw_g */
              VCAST_RUN_DATA_IF_9( 0, 38 );
              break;
            case 5:
              /* For rw_DewPoint_g */
              VCAST_RUN_DATA_IF_9( 0, 39 );
              break;
            case 6:
              /* For rbi_HumTempComError_g */
              VCAST_RUN_DATA_IF_9( 0, 40 );
              break;
            case 7:
              /* For EEPROM_Struct_AD */
              VCAST_RUN_DATA_IF_9( 0, 41 );
              break;
            case 8:
              /* For rb_WDG_BusTaskCounter_g */
              VCAST_RUN_DATA_IF_9( 0, 42 );
              break;
            case 9:
              /* For uLinIndicationFlags */
              VCAST_RUN_DATA_IF_9( 0, 43 );
              break;
            case 10:
              /* For uLinConfirmationFlags */
              VCAST_RUN_DATA_IF_9( 0, 44 );
              break;
            case 11:
              /* For rb_WakeupCounter_mg */
              VCAST_RUN_DATA_IF_9( 0, 45 );
              break;
            case 12:
              /* For RlsmCem_SerNrLin1Fr01_CEM_LIN1 */
              VCAST_RUN_DATA_IF_9( 0, 46 );
              break;
            case 13:
              /* For RlsmCem_Lin1PartNrFr02_CEM_LIN1 */
              VCAST_RUN_DATA_IF_9( 0, 47 );
              break;
            case 14:
              /* For RlsmCem_Lin1PartNrFr01_CEM_LIN1 */
              VCAST_RUN_DATA_IF_9( 0, 48 );
              break;
            case 15:
              /* For RlsmCem_Lin1Fr03_CEM_LIN1 */
              VCAST_RUN_DATA_IF_9( 0, 49 );
              break;
            case 16:
              /* For RlsmCem_Lin1Fr02_CEM_LIN1 */
              VCAST_RUN_DATA_IF_9( 0, 50 );
              break;
            case 17:
              /* For RlsmCem_Lin1Fr01_CEM_LIN1 */
              VCAST_RUN_DATA_IF_9( 0, 51 );
              break;
            case 18:
              /* For CemCem_Lin1Fr06_CEM_LIN1 */
              VCAST_RUN_DATA_IF_9( 0, 52 );
              break;
            case 19:
              /* For CemCem_Lin1Fr05_CEM_LIN1 */
              VCAST_RUN_DATA_IF_9( 0, 53 );
              break;
            case 20:
              /* For CemCem_Lin1Fr04_CEM_LIN1 */
              VCAST_RUN_DATA_IF_9( 0, 54 );
              break;
            case 21:
              /* For CemCem_Lin1Fr03_CEM_LIN1 */
              VCAST_RUN_DATA_IF_9( 0, 55 );
              break;
            case 22:
              /* For CemCem_Lin1Fr02_CEM_LIN1 */
              VCAST_RUN_DATA_IF_9( 0, 56 );
              break;
            case 23:
              /* For CemCem_Lin1Fr01_CEM_LIN1 */
              VCAST_RUN_DATA_IF_9( 0, 57 );
              break;
            case 24:
              /* For uF_VoltageStatus_g */
              VCAST_RUN_DATA_IF_9( 0, 58 );
              break;
            case 25:
              /* For rb_InternalTemperature_g */
              VCAST_RUN_DATA_IF_9( 0, 59 );
              break;
            case 26:
              /* For rb_ClockFreq_Error_cnt_g */
              VCAST_RUN_DATA_IF_9( 0, 60 );
              break;
            case 27:
              /* For uF_uC_Error_g */
              VCAST_RUN_DATA_IF_9( 0, 61 );
              break;
            case 28:
              /* For uF_Diagnose_pre_Flag */
              VCAST_RUN_DATA_IF_9( 0, 62 );
              break;
            case 29:
              /* For rub_RSIntermDelayInit */
              VCAST_RUN_DATA_IF_9( 0, 63 );
              break;
            case 30:
              /* For rb_LimitMemomryNoWiperReaction_g */
              VCAST_RUN_DATA_IF_9( 0, 64 );
              break;
            case 31:
              /* For rbi_WiperStarted_g */
              VCAST_RUN_DATA_IF_9( 0, 65 );
              break;
            case 32:
              /* For rb_LIN_SensitivityShift_g */
              VCAST_RUN_DATA_IF_9( 0, 66 );
              break;
            case 33:
              /* For RSStatus */
              VCAST_RUN_DATA_IF_9( 0, 67 );
              break;
            case 34:
              /* For rub_IntermDelayTime */
              VCAST_RUN_DATA_IF_9( 0, 68 );
              break;
            case 35:
              /* For rb_PotiStageFromBox_g */
              VCAST_RUN_DATA_IF_9( 0, 69 );
              break;
            case 36:
              /* For uF_StatusRainsensor_mg */
              VCAST_RUN_DATA_IF_9( 0, 70 );
              break;
            case 37:
              /* For uF_StatusRainsensor2_mg */
              VCAST_RUN_DATA_IF_9( 0, 71 );
              break;
            case 38:
              /* For rb_WiperSpeed_g */
              VCAST_RUN_DATA_IF_9( 0, 72 );
              break;
            case 39:
              /* For rb_WiperSpeedAlt_g */
              VCAST_RUN_DATA_IF_9( 0, 73 );
              break;
            case 40:
              /* For uF_LIN_DiagReq2_mg */
              VCAST_RUN_DATA_IF_9( 0, 74 );
              break;
            case 41:
              /* For uF_Main_Flags_g */
              VCAST_RUN_DATA_IF_9( 0, 75 );
              break;
            case 42:
              /* For rb_RS_LS_Error1_g */
              VCAST_RUN_DATA_IF_9( 0, 76 );
              break;
            case 43:
              /* For rb_RS_LS_Error2_g */
              VCAST_RUN_DATA_IF_9( 0, 77 );
              break;
            case 44:
              /* For rb_RainS_Error1_g */
              VCAST_RUN_DATA_IF_9( 0, 78 );
              break;
            case 45:
              /* For rb_LightS_Error1_g */
              VCAST_RUN_DATA_IF_9( 0, 79 );
              break;
            case 46:
              /* For rw_EEPROM_Address_to_Write_g */
              VCAST_RUN_DATA_IF_9( 0, 80 );
              break;
            case 47:
              /* For rb_I2C_EEPROM_bytesToWrite_g */
              VCAST_RUN_DATA_IF_9( 0, 81 );
              break;
            case 48:
              /* For rab_EEPROM_Bytes_toWrite_g */
              VCAST_RUN_DATA_IF_9( 0, 82 );
              break;
            case 49:
              /* For uF_E2ConfigErrorFlags_g */
              VCAST_RUN_DATA_IF_9( 0, 83 );
              break;
            case 50:
              /* For rb_speed_in_kmh_g */
              VCAST_RUN_DATA_IF_9( 0, 84 );
              break;
            case 51:
              /* For rb_LSPotiStage_g */
              VCAST_RUN_DATA_IF_9( 0, 85 );
              break;
            case 52:
              /* For uF_Check_lightsensor_g */
              VCAST_RUN_DATA_IF_9( 0, 86 );
              break;
            case 53:
              /* For uF_modi_lightsens_g */
              VCAST_RUN_DATA_IF_9( 0, 87 );
              break;
            case 54:
              /* For uF_LightInternalStatus_g */
              VCAST_RUN_DATA_IF_9( 0, 88 );
              break;
            case 55:
              /* For rw_StandbyTimeOutCnt_g */
              VCAST_RUN_DATA_IF_9( 0, 89 );
              break;
            case 56:
              /* For rb_ASIC_ALSx_ShortDetected_Error_g */
              VCAST_RUN_DATA_IF_9( 0, 90 );
              break;
            case 57:
              /* For rb_ASIC_ALS2Amb_ShortDetected_cnt_g */
              VCAST_RUN_DATA_IF_9( 0, 91 );
              break;
            case 58:
              /* For rb_ASIC_ALS5FW_ShortDetected_cnt_g */
              VCAST_RUN_DATA_IF_9( 0, 92 );
              break;
            case 59:
              /* For rb_ASIC_INRECIR_ShortDetected_cnt_g */
              VCAST_RUN_DATA_IF_9( 0, 93 );
              break;
            case 60:
              /* For uF_ASIC_ControlFlags_g */
              VCAST_RUN_DATA_IF_9( 0, 94 );
              break;
            case 61:
              /* For uF_GainAdjustFlags_g */
              VCAST_RUN_DATA_IF_9( 0, 95 );
              break;
            case 62:
              /* For uF_ASIC_Error_Flags_g */
              VCAST_RUN_DATA_IF_9( 0, 96 );
              break;
            case 63:
              /* For uF_ASIC_Error_Flags1_g */
              VCAST_RUN_DATA_IF_9( 0, 97 );
              break;
            case 64:
              /* For uF_ASIC_Ctrl_Error_Flags_g */
              VCAST_RUN_DATA_IF_9( 0, 98 );
              break;
            case 65:
              /* For rw_Solar_light16bit_1_g */
              VCAST_RUN_DATA_IF_9( 0, 99 );
              break;
            case 66:
              /* For rw_Solar_light16bit_2_g */
              VCAST_RUN_DATA_IF_9( 0, 100 );
              break;
            case 67:
              /* For ras_ASIC_MUX_MeasAD_g */
              VCAST_RUN_DATA_IF_9( 0, 101 );
              break;
            case 68:
              /* For rb_ASIC_initTimeout_g */
              VCAST_RUN_DATA_IF_9( 0, 102 );
              break;
            case 69:
              /* For rb_VIref_ErrCnt_g */
              VCAST_RUN_DATA_IF_9( 0, 103 );
              break;
            case 70:
              /* For rb_ASIC_SPI_ErrorCodeCnt_g */
              VCAST_RUN_DATA_IF_9( 0, 104 );
              break;
            case 71:
              /* For rb_StaticNoValidAD_cnt_g */
              VCAST_RUN_DATA_IF_9( 0, 105 );
              break;
            case 72:
              /* For rw_SPINoCommCounter_g */
              VCAST_RUN_DATA_IF_9( 0, 106 );
              break;
            case 73:
              /* For rb_RainInt_IntensityOutput_g */
              VCAST_RUN_DATA_IF_9( 0, 107 );
              break;
            case 74:
              /* For rb_overWipeCoef */
              VCAST_RUN_DATA_IF_9( 0, 108 );
              break;
        default:
          vCAST_TOOL_ERROR = vCAST_true;
          break;
      } /* switch */
      break;
        case 1:
          /* For sci_init */
          VCAST_RUN_DATA_IF_9( 43, VCAST_PARAM_INDEX );
          break;
        case 2:
          /* For Check_StartupActiveErrors */
          VCAST_RUN_DATA_IF_9( 44, VCAST_PARAM_INDEX );
          break;
        case 3:
          /* For get_rb_LightVetoCounter_g */
          VCAST_RUN_DATA_IF_9( 45, VCAST_PARAM_INDEX );
          break;
        case 4:
          /* For get_rw_Amb_light16bit_g */
          VCAST_RUN_DATA_IF_9( 46, VCAST_PARAM_INDEX );
          break;
        case 5:
          /* For get_rl_HUD_light32bit_g */
          VCAST_RUN_DATA_IF_9( 47, VCAST_PARAM_INDEX );
          break;
        case 6:
          /* For get_rw_IR_light16bit_g */
          VCAST_RUN_DATA_IF_9( 48, VCAST_PARAM_INDEX );
          break;
        case 7:
          /* For get_rb_LightSignalErrorCnt_g */
          VCAST_RUN_DATA_IF_9( 49, VCAST_PARAM_INDEX );
          break;
        case 8:
          /* For get_rb_VDD_LightSignalErrorCnt_g */
          VCAST_RUN_DATA_IF_9( 50, VCAST_PARAM_INDEX );
          break;
        case 9:
          /* For get_rb_LEDx_LStop_error_cnt_g */
          VCAST_RUN_DATA_IF_9( 51, VCAST_PARAM_INDEX );
          break;
        case 10:
          /* For CopyRLSDataAsic */
          VCAST_RUN_DATA_IF_9( 52, VCAST_PARAM_INDEX );
          break;
    default:
      vCAST_TOOL_ERROR = vCAST_true;
      break;
  } /* switch */
  break; /* case 10 */
} /* switch */
} /* vcast_B1_switch */
