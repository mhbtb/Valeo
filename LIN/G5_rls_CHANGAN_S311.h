/******************************************************************************/
/*                                                                            */
/*   Valeo Schalter und Sensoren GmbH                                         */
/*   Laiernstrasse 12                                                         */
/*   74321 Bietigheim-Bissingen                                               */
/*                                                                            */
/*   All rights reserved. Distribution or duplication without previous        */
/*   written agreement of the owner prohibited.                               */
/*                                                                            */
/******************************************************************************/

/** \file
 *
 * Template of header file for LIN configuration and message definitions 
 * used with RLT-DIagnose.exe
 *
 * 
 * <table border="0" cellspacing="0" cellpadding="0">
 * <tr> <td> Source:   </td> <td> template_rls.h                  </td></tr>
 * <tr> <td> Revision: </td> <td> 1.0                  </td></tr>
 * <tr> <td> Status:   </td> <td> STORED                  </td></tr>
 * <tr> <td> Author:   </td> <td> Jochen Schenk, VDS-E-PUS  </td></tr>
 * <tr> <td> Date:     </td> <td> 07-APR-2014 07:47:17                 </td></tr>
 * </table>
 * 
 * \n
 * <table border="0" cellspacing="0" cellpadding="0">
 * <tr> <td> COMPONENT: </td> <td> RLS_LIN     </td></tr>
 * <tr> <td> SCOPE:     </td> <td> Public      </td></tr>
 * <tr> <td> TARGET:    </td> <td> NEC         </td></tr>
 * </table>
 */

#ifndef I_LIN_RLS_H
#define I_LIN_RLS_H

/******************************************************************************/
/*                        Definition of message handles                       */
/******************************************************************************/

#define cb_HANDLE_LinRespCmd              0
#define cb_HANDLE_ASIC_Frame_04           1
#define cb_HANDLE_ASIC_Frame_03           2
#define cb_HANDLE_ASIC_Frame_02           3
#define cb_HANDLE_ASIC_Frame_01           4
#define cb_HANDLE_RLS_LIN_3               5
#define cb_HANDLE_RLS_LIN_2               6
#define cb_HANDLE_RLS_LIN_1               7
#define cb_HANDLE_LinReqCmd               8
#define cb_HANDLE_BCM_Calibration         9
#define cb_HANDLE_BCM_LIN_2               10
#define cb_HANDLE_BCM_LIN_1               11

/*************The re-mapping is defined by Blake_LI 2018_12_24*****************/

#define cb_HANDLE_LinRespCmd_g        cb_HANDLE_LinRespCmd                 /******  0   RLS output******/
#define cb_HANDLE_ASIC_Frame_04_g     cb_HANDLE_ASIC_Frame_04              /*****   1   RLS output******/
#define cb_HANDLE_ASIC_Frame_03_g     cb_HANDLE_ASIC_Frame_03              /*****   2   RLS output******/
#define cb_HANDLE_ASIC_Frame_02_g     cb_HANDLE_ASIC_Frame_02              /*****   3   RLS output******/
#define cb_HANDLE_ASIC_Frame_01_g     cb_HANDLE_ASIC_Frame_01              /*****   4   RLS output******/
#define cb_HANDLE_SoSes_01            cb_HANDLE_RLS_LIN_3                  /*****   5   RLS output******/
#define cb_HANDLE_FSs_01_g            cb_HANDLE_RLS_LIN_2                  /*****   6   RLS output******/
#define cb_HANDLE_RLSs_01_g           cb_HANDLE_RLS_LIN_1                  /*****   7   RLS output******/ 

#define cb_HANDLE_LinReqCmd_g         cb_HANDLE_LinReqCmd                  /******  8   RLS Input*******/
#define cb_HANDLE_BCM_Calibration_g   cb_HANDLE_BCM_Calibration            /******  9   RLS Input*******/
#define cb_HANDLE_WWSs_01_g           cb_HANDLE_BCM_LIN_2                  /*****   10  RLS Input*******/
#define cb_HANDLE_BCM1_LIN1_01_g      cb_HANDLE_BCM_LIN_1                  /*****   11  RLS Input*******/
/******************************************************************************/
/*                    Declaration of exported variables                       */
/******************************************************************************/

extern MEMORY_ROM canuint8  cabLinRxDLCTbl[];
extern canuint8* MEMORY_ROM capbLinRxDataPtrTbl[kLinNumberOfRxObjects];
extern MEMORY_ROM canuint8  cabLinTxDataLenTbl[];
extern canuint8* MEMORY_ROM capbLinTxDataPtrTbl[kLinNumberOfTxObjects];
extern MEMORY_ROM canuint8  cabLinRxDataLenTbl[];
extern MEMORY_ROM canuint8  cabLinRxDLCTbl[];
extern MEMORY_ROM canuint8  cabLinMsgHandleTbl[kLinNumberOfObjects];

#ifdef NODECONFIGURATION
extern canuint8             rabRAMLinMsgIDToHandleTbl[0x40];
extern MEMORY_ROM canuint16 cawLINMessageID[kLinNumberOfObjects];
#else
extern MEMORY_ROM canuint8  cabLinMsgIDToHandleTbl[0x40];
#endif

/******************************************************************************/
/*                             Signal structures                              */
/******************************************************************************/


/* Send messages */

typedef struct {
  canbittype                              SlaveRespB0: 8;
  canbittype                              SlaveRespB1: 8;
  canbittype                              SlaveRespB2: 8;
  canbittype                              SlaveRespB3: 8;
  canbittype                              SlaveRespB4: 8;
  canbittype                              SlaveRespB5: 8;
  canbittype                              SlaveRespB6: 8;
  canbittype                              SlaveRespB7: 8;
} _c_LinRespCmd_msgType;

typedef struct {
  canbittype                     LIN_rw_Vref_ASIC_g_0: 8;
  canbittype                     LIN_rw_Vref_ASIC_g_1: 2;
  canbittype                     LIN_rw_VDDA_ASIC_g_0: 6;
  canbittype                     LIN_rw_VDDA_ASIC_g_1: 4;
  canbittype                     LIN_rw_VDDD_ASIC_g_0: 4;
  canbittype                     LIN_rw_VDDD_ASIC_g_1: 6;
  canbittype           LW_rw_VILO_ICALLO_GHI_ASIC_g_0: 2;
  canbittype           LW_rw_VILO_ICALLO_GHI_ASIC_g_1: 8;
  canbittype                  LIN_rw_REGV_Voltage_g_0: 8;
  canbittype                  LIN_rw_REGV_Voltage_g_1: 4;
  canbittype                                  unused0: 4;
  canbittype         LIN_rb_ASICReg_NoValidVals_cnt_g: 8;
} _c_ASIC_Frame_04_msgType;

typedef struct {
  canbittype            LIN_rw_Solar_light16bit_1_g_0: 8;
  canbittype            LIN_rw_Solar_light16bit_1_g_1: 8;
  canbittype            LIN_rw_Solar_light16bit_2_g_0: 8;
  canbittype            LIN_rw_Solar_light16bit_2_g_1: 8;
  canbittype                 LIN_rw_FW_light16bit_g_0: 8;
  canbittype                 LIN_rw_FW_light16bit_g_1: 8;
  canbittype                 LIN_rw_IR_light16bit_g_0: 8;
  canbittype                 LIN_rw_IR_light16bit_g_1: 8;
} _c_ASIC_Frame_03_msgType;

typedef struct {
  canbittype                 LIN_rw_INTV10bit_max_g_0: 8;
  canbittype                 LIN_rw_INTV10bit_max_g_1: 2;
  canbittype                 LIN_rw_INTV10bit_min_g_0: 6;
  canbittype                 LIN_rw_INTV10bit_min_g_1: 4;
  canbittype          LIN_rw_VICALLO_ILO_GHI_ASIC_g_0: 4;
  canbittype          LIN_rw_VICALLO_ILO_GHI_ASIC_g_1: 6;
  canbittype                    LIN_rw_VTEMP_ASIC_g_0: 2;
  canbittype                    LIN_rw_VTEMP_ASIC_g_1: 8;
  canbittype       LIN_rb_SPI_Active_ProblemCounter_g: 8;
  canbittype       LIN_rb_StaticHumTempErrorCounter_g: 8;
  canbittype                       LIN_rb_STATH_Reg_g: 8;
} _c_ASIC_Frame_02_msgType;

typedef struct {
  canbittype                  LIN_rb_SupplyVoltage_mg: 8;
  canbittype          LIN_rb_MaxLightSignalErrorCnt_g: 8;
  canbittype      LIN_rb_StaticNoCommunicationCounter: 8;
  canbittype                     LIN_rw_ALS2_ASIC_g_0: 8;
  canbittype                     LIN_rw_ALS2_ASIC_g_1: 2;
  canbittype                     LIN_rw_ALS5_ASIC_g_0: 6;
  canbittype                     LIN_rw_ALS5_ASIC_g_1: 4;
  canbittype                LIN_rw_Amb_light16bit_g_0: 4;
  canbittype                LIN_rw_Amb_light16bit_g_1: 6;
  canbittype                    LIN_rw_INREC_ASIC_g_0: 2;
  canbittype                    LIN_rw_INREC_ASIC_g_1: 8;
} _c_ASIC_Frame_01_msgType;

typedef struct {
  canbittype                            IR_Brightness: 8;
  canbittype                          FW_Brightness_0: 8;
  canbittype                          FW_Brightness_1: 2;
  canbittype                                  unused0: 6;
  canbittype                         AMB_Brightness_0: 8;
  canbittype                         AMB_Brightness_1: 2;
  canbittype                                  unused1: 6;
  canbittype                            PWM_Voltage_0: 8;
  canbittype                            PWM_Voltage_1: 2;
  canbittype                                  unused2: 6;
  canbittype                                  unused3: 8;
} _c_RLS_LIN_3_msgType;

typedef struct {
  canbittype                          RLS_Wiper_speed: 4;
  canbittype                   RLS_Status_rain_sensor: 4;
  canbittype                  RLS_Light_switch_reason: 8;
  canbittype                RLS_SunRoofCloseReqReason: 4;
  canbittype                                  unused0: 4;
  canbittype                                  unused1: 8;
  canbittype                 RLS_Light_switch_request: 2;
  canbittype                      RLS_Status_low_beam: 2;
  canbittype                            RLS_RLS_error: 2;
  canbittype                                  unused2: 2;
  canbittype        RLS_Error_calibration_rain_sensor: 2;
  canbittype             RLS_Error_status_rain_sensor: 2;
  canbittype      RLS_Error_status_coding_rain_sensor: 2;
  canbittype            RLS_Error_status_light_sensor: 2;
  canbittype        RLS_Error_status_over_temperature: 2;
  canbittype            RLS_Error_status_over_voltage: 2;
  canbittype                            RainfallLevel: 4;
  canbittype                                  unused3: 7;
  canbittype                  RLS_Communication_error: 1;
} _c_RLS_LIN_2_msgType;

typedef struct {
  canbittype                            RLS_SolarLeft: 8;
  canbittype                           RLS_SolarRight: 8;
  canbittype                     RLS_relativeHumidity: 8;
  canbittype                       RLS_WindshieldTemp: 8;
  canbittype                           RLS_DewPoint_0: 8;
  canbittype                           RLS_DewPoint_1: 2;
  canbittype                                  unused0: 6;
  canbittype           RLS_Offline_Calibration_Result: 2;
  canbittype                                  unused1: 6;
  canbittype                                  unused2: 8;
} _c_RLS_LIN_1_msgType;


/* Receive messages */

typedef struct {
  canbittype                              MasterReqB0: 8;
  canbittype                              MasterReqB1: 8;
  canbittype                              MasterReqB2: 8;
  canbittype                              MasterReqB3: 8;
  canbittype                              MasterReqB4: 8;
  canbittype                              MasterReqB5: 8;
  canbittype                              MasterReqB6: 8;
  canbittype                              MasterReqB7: 8;
} _c_LinReqCmd_msgType;

typedef struct {
  canbittype                        RLS_Sensitivity_0: 6;
  canbittype                      RLS_Sensitivity_1_0: 2;
  canbittype                      RLS_Sensitivity_1_1: 4;
  canbittype                      RLS_Sensitivity_2_0: 4;
  canbittype                      RLS_Sensitivity_2_1: 2;
  canbittype                        RLS_Sensitivity_3: 6;
  canbittype                        RLS_Sensitivity_4: 6;
  canbittype                      RLS_Sensitivity_5_0: 2;
  canbittype                      RLS_Sensitivity_5_1: 4;
  canbittype                      RLS_Sensitivity_6_0: 4;
  canbittype                      RLS_Sensitivity_6_1: 2;
  canbittype                        RLS_Sensitivity_7: 6;
  canbittype                        RLS_Sensitivity_8: 6;
  canbittype                     RLS_Parameter_Choice: 2;
  canbittype                                  unused0: 8;
} _c_BCM_Calibration_msgType;

typedef struct {
  canbittype              BCM_Wiper_control_operation: 8;
  canbittype                                  unused0: 4;
  canbittype                       BCM_Wiper_position: 2;
  canbittype                                  unused1: 2;
  canbittype                     BCM_Rain_sensitivity: 3;
  canbittype                                  unused2: 5;
  canbittype                   BCM_880nmTransimission: 7;
  canbittype                                  unused3: 1;
  canbittype                   BCM_550nmTransimission: 7;
  canbittype                                  unused4: 1;
  canbittype                                  unused5: 4;
  canbittype      BCM_Coding_data_low_beam_thresholds: 3;
  canbittype                                  unused6: 1;
  canbittype               BCM_Coding_type_windscreen: 3;
  canbittype                  BCM_Coding_type_vehicle: 3;
  canbittype                    BCM_RLS_RainDetectReq: 1;
  canbittype                                  unused7: 1;
  canbittype                  BCM_Coding_wiper_system: 2;
  canbittype   BCM_Coding_data_rain_sensor_activation: 2;
  canbittype      BCM_Coding_data_low_beam_high_speed: 2;
  canbittype                                  unused8: 2;
} _c_BCM_LIN_2_msgType;

typedef struct {
  canbittype                            BCM_IGNStatus: 2;
  canbittype                                  unused0: 6;
  canbittype                                  unused1: 8;
  canbittype                                  unused2: 8;
  canbittype                         BCM_VehicleSpeed: 8;
  canbittype                    BCM_EnvironmentalTemp: 8;
  canbittype                                  unused3: 8;
  canbittype                                  unused4: 8;
  canbittype                                  unused5: 8;
} _c_BCM_LIN_1_msgType;


/******************************************************************************/
/*                               Message Unions                               */
/******************************************************************************/


/* Send messages */

typedef union {
    unsigned char _c[8];
    _c_LinRespCmd_msgType linrespcmd;
} _c_LinRespCmd_buf;

typedef union {
    unsigned char _c[8];
    _c_ASIC_Frame_04_msgType asic_frame_04;
} _c_ASIC_Frame_04_buf;

typedef union {
    unsigned char _c[8];
    _c_ASIC_Frame_03_msgType asic_frame_03;
} _c_ASIC_Frame_03_buf;

typedef union {
    unsigned char _c[8];
    _c_ASIC_Frame_02_msgType asic_frame_02;
} _c_ASIC_Frame_02_buf;

typedef union {
    unsigned char _c[8];
    _c_ASIC_Frame_01_msgType asic_frame_01;
} _c_ASIC_Frame_01_buf;

typedef union {
    unsigned char _c[8];
    _c_RLS_LIN_3_msgType rls_lin_3;
} _c_RLS_LIN_3_buf;

typedef union {
    unsigned char _c[8];
    _c_RLS_LIN_2_msgType rls_lin_2;
} _c_RLS_LIN_2_buf;

typedef union {
    unsigned char _c[8];
    _c_RLS_LIN_1_msgType rls_lin_1;
} _c_RLS_LIN_1_buf;


/* Receive messages */

typedef union {
    unsigned char _c[8];
    _c_LinReqCmd_msgType linreqcmd;
} _c_LinReqCmd_buf;

typedef union {
    unsigned char _c[8];
    _c_BCM_Calibration_msgType bcm_calibration;
} _c_BCM_Calibration_buf;

typedef union {
    unsigned char _c[8];
    _c_BCM_LIN_2_msgType bcm_lin_2;
} _c_BCM_LIN_2_buf;

typedef union {
    unsigned char _c[8];
    _c_BCM_LIN_1_msgType bcm_lin_1;
} _c_BCM_LIN_1_buf;


/******************************************************************************/
/*                          Databuffer for send objects                       */
/******************************************************************************/

extern MEMORY_FAR _c_LinRespCmd_buf LinRespCmd;
extern MEMORY_FAR _c_ASIC_Frame_04_buf ASIC_Frame_04;
extern MEMORY_FAR _c_ASIC_Frame_03_buf ASIC_Frame_03;
extern MEMORY_FAR _c_ASIC_Frame_02_buf ASIC_Frame_02;
extern MEMORY_FAR _c_ASIC_Frame_01_buf ASIC_Frame_01;
extern MEMORY_FAR _c_RLS_LIN_3_buf RLS_LIN_3;
extern MEMORY_FAR _c_RLS_LIN_2_buf RLS_LIN_2;
extern MEMORY_FAR _c_RLS_LIN_1_buf RLS_LIN_1;

/******************************************************************************/
/*                        Databuffer for confirmationflags                    */
/******************************************************************************/

#define LinRespCmd_conf_b             uLinConfirmationFlags.w[0].b0
#define l_flg_tst_LinRespCmd()       (LinRespCmd_conf_b != 0)
#define l_flg_clr_LinRespCmd()       {LinRespCmd_conf_b = 0;}
#define ASIC_Frame_04_conf_b             uLinConfirmationFlags.w[0].b1
#define l_flg_tst_ASIC_Frame_04()       (ASIC_Frame_04_conf_b != 0)
#define l_flg_clr_ASIC_Frame_04()       {ASIC_Frame_04_conf_b = 0;}
#define ASIC_Frame_03_conf_b             uLinConfirmationFlags.w[0].b2
#define l_flg_tst_ASIC_Frame_03()       (ASIC_Frame_03_conf_b != 0)
#define l_flg_clr_ASIC_Frame_03()       {ASIC_Frame_03_conf_b = 0;}
#define ASIC_Frame_02_conf_b             uLinConfirmationFlags.w[0].b3
#define l_flg_tst_ASIC_Frame_02()       (ASIC_Frame_02_conf_b != 0)
#define l_flg_clr_ASIC_Frame_02()       {ASIC_Frame_02_conf_b = 0;}
#define ASIC_Frame_01_conf_b             uLinConfirmationFlags.w[0].b4
#define l_flg_tst_ASIC_Frame_01()       (ASIC_Frame_01_conf_b != 0)
#define l_flg_clr_ASIC_Frame_01()       {ASIC_Frame_01_conf_b = 0;}
#define RLS_LIN_3_conf_b             uLinConfirmationFlags.w[0].b5
#define l_flg_tst_RLS_LIN_3()       (RLS_LIN_3_conf_b != 0)
#define l_flg_clr_RLS_LIN_3()       {RLS_LIN_3_conf_b = 0;}
#define RLS_LIN_2_conf_b             uLinConfirmationFlags.w[0].b6
#define l_flg_tst_RLS_LIN_2()       (RLS_LIN_2_conf_b != 0)
#define l_flg_clr_RLS_LIN_2()       {RLS_LIN_2_conf_b = 0;}
#define RLS_LIN_1_conf_b             uLinConfirmationFlags.w[0].b7
#define l_flg_tst_RLS_LIN_1()       (RLS_LIN_1_conf_b != 0)
#define l_flg_clr_RLS_LIN_1()       {RLS_LIN_1_conf_b = 0;}

/******************************************************************************/
/*                         Databuffer for receive objects                     */
/******************************************************************************/

extern MEMORY_FAR _c_LinReqCmd_buf LinReqCmd;
extern MEMORY_FAR _c_BCM_Calibration_buf BCM_Calibration;
extern MEMORY_FAR _c_BCM_LIN_2_buf BCM_LIN_2;
extern MEMORY_FAR _c_BCM_LIN_1_buf BCM_LIN_1;

/******************************************************************************/
/*                          Databuffer for indicationflags                    */
/******************************************************************************/

#define LinReqCmd_ind_b             uLinIndicationFlags.w[0].b0
#define l_flg_tst_LinReqCmd()       (LinReqCmd_ind_b != 0)
#define l_flg_clr_LinReqCmd()       {LinReqCmd_ind_b = 0;}
#define BCM_Calibration_ind_b             uLinIndicationFlags.w[0].b1
#define l_flg_tst_BCM_Calibration()       (BCM_Calibration_ind_b != 0)
#define l_flg_clr_BCM_Calibration()       {BCM_Calibration_ind_b = 0;}
#define BCM_LIN_2_ind_b             uLinIndicationFlags.w[0].b2
#define l_flg_tst_BCM_LIN_2()       (BCM_LIN_2_ind_b != 0)
#define l_flg_clr_BCM_LIN_2()       {BCM_LIN_2_ind_b = 0;}
#define BCM_LIN_1_ind_b             uLinIndicationFlags.w[0].b3
#define l_flg_tst_BCM_LIN_1()       (BCM_LIN_1_ind_b != 0)
#define l_flg_clr_BCM_LIN_1()       {BCM_LIN_1_ind_b = 0;}

/******************************************************************************/
/*                               Definition of signals                        */
/******************************************************************************/

#define SlaveRespB0                                                           LinRespCmd.linrespcmd.SlaveRespB0
#define SlaveRespB1                                                           LinRespCmd.linrespcmd.SlaveRespB1
#define SlaveRespB2                                                           LinRespCmd.linrespcmd.SlaveRespB2
#define SlaveRespB3                                                           LinRespCmd.linrespcmd.SlaveRespB3
#define SlaveRespB4                                                           LinRespCmd.linrespcmd.SlaveRespB4
#define SlaveRespB5                                                           LinRespCmd.linrespcmd.SlaveRespB5
#define SlaveRespB6                                                           LinRespCmd.linrespcmd.SlaveRespB6
#define SlaveRespB7                                                           LinRespCmd.linrespcmd.SlaveRespB7
#define LIN_rw_Vref_ASIC_g_0                                                  ASIC_Frame_04.asic_frame_04.LIN_rw_Vref_ASIC_g_0
#define LIN_rw_Vref_ASIC_g_1                                                  ASIC_Frame_04.asic_frame_04.LIN_rw_Vref_ASIC_g_1
#define LIN_rw_Vref_ASIC_g(c)                                                 { LIN_rw_Vref_ASIC_g_0= (uint8)(((uint16)(c) & 0xFF));\
                                                                                LIN_rw_Vref_ASIC_g_1= (uint8)(((uint16)(c) & 0x03) >> 8);\
                                                                              }
#define LIN_rw_VDDA_ASIC_g_0                                                  ASIC_Frame_04.asic_frame_04.LIN_rw_VDDA_ASIC_g_0
#define LIN_rw_VDDA_ASIC_g_1                                                  ASIC_Frame_04.asic_frame_04.LIN_rw_VDDA_ASIC_g_1
#define LIN_rw_VDDA_ASIC_g(c)                                                 { LIN_rw_VDDA_ASIC_g_0= (uint8)(((uint16)(c) & 0x3F));\
                                                                                LIN_rw_VDDA_ASIC_g_1= (uint8)(((uint16)(c) & 0x0F) >> 6);\
                                                                              }
#define LIN_rw_VDDD_ASIC_g_0                                                  ASIC_Frame_04.asic_frame_04.LIN_rw_VDDD_ASIC_g_0
#define LIN_rw_VDDD_ASIC_g_1                                                  ASIC_Frame_04.asic_frame_04.LIN_rw_VDDD_ASIC_g_1
#define LIN_rw_VDDD_ASIC_g(c)                                                 { LIN_rw_VDDD_ASIC_g_0= (uint8)(((uint16)(c) & 0x0F));\
                                                                                LIN_rw_VDDD_ASIC_g_1= (uint8)(((uint16)(c) & 0x3F) >> 4);\
                                                                              }
#define LW_rw_VILO_ICALLO_GHI_ASIC_g_0                                        ASIC_Frame_04.asic_frame_04.LW_rw_VILO_ICALLO_GHI_ASIC_g_0
#define LW_rw_VILO_ICALLO_GHI_ASIC_g_1                                        ASIC_Frame_04.asic_frame_04.LW_rw_VILO_ICALLO_GHI_ASIC_g_1
#define LW_rw_VILO_ICALLO_GHI_ASIC_g(c)                                       { LW_rw_VILO_ICALLO_GHI_ASIC_g_0= (uint8)(((uint16)(c) & 0x03));\
                                                                                LW_rw_VILO_ICALLO_GHI_ASIC_g_1= (uint8)(((uint16)(c) & 0xFF) >> 2);\
                                                                              }
#define LIN_rw_REGV_Voltage_g_0                                               ASIC_Frame_04.asic_frame_04.LIN_rw_REGV_Voltage_g_0
#define LIN_rw_REGV_Voltage_g_1                                               ASIC_Frame_04.asic_frame_04.LIN_rw_REGV_Voltage_g_1
#define LIN_rw_REGV_Voltage_g(c)                                              { LIN_rw_REGV_Voltage_g_0= (uint8)(((uint16)(c) & 0xFF));\
                                                                                LIN_rw_REGV_Voltage_g_1= (uint8)(((uint16)(c) & 0x0F) >> 8);\
                                                                              }
#define LIN_rb_ASICReg_NoValidVals_cnt_g                                      ASIC_Frame_04.asic_frame_04.LIN_rb_ASICReg_NoValidVals_cnt_g
#define LIN_rw_Solar_light16bit_1_g_0                                         ASIC_Frame_03.asic_frame_03.LIN_rw_Solar_light16bit_1_g_0
#define LIN_rw_Solar_light16bit_1_g_1                                         ASIC_Frame_03.asic_frame_03.LIN_rw_Solar_light16bit_1_g_1
#define LIN_rw_Solar_light16bit_1_g(c)                                        { LIN_rw_Solar_light16bit_1_g_0= (uint8)(((uint16)(c) & 0xFF));\
                                                                                LIN_rw_Solar_light16bit_1_g_1= (uint8)(((uint16)(c) & 0xFF) >> 8);\
                                                                              }
#define LIN_rw_Solar_light16bit_2_g_0                                         ASIC_Frame_03.asic_frame_03.LIN_rw_Solar_light16bit_2_g_0
#define LIN_rw_Solar_light16bit_2_g_1                                         ASIC_Frame_03.asic_frame_03.LIN_rw_Solar_light16bit_2_g_1
#define LIN_rw_Solar_light16bit_2_g(c)                                        { LIN_rw_Solar_light16bit_2_g_0= (uint8)(((uint16)(c) & 0xFF));\
                                                                                LIN_rw_Solar_light16bit_2_g_1= (uint8)(((uint16)(c) & 0xFF) >> 8);\
                                                                              }
#define LIN_rw_FW_light16bit_g_0                                              ASIC_Frame_03.asic_frame_03.LIN_rw_FW_light16bit_g_0
#define LIN_rw_FW_light16bit_g_1                                              ASIC_Frame_03.asic_frame_03.LIN_rw_FW_light16bit_g_1
#define LIN_rw_FW_light16bit_g(c)                                             { LIN_rw_FW_light16bit_g_0= (uint8)(((uint16)(c) & 0xFF));\
                                                                                LIN_rw_FW_light16bit_g_1= (uint8)(((uint16)(c) & 0xFF) >> 8);\
                                                                              }
#define LIN_rw_IR_light16bit_g_0                                              ASIC_Frame_03.asic_frame_03.LIN_rw_IR_light16bit_g_0
#define LIN_rw_IR_light16bit_g_1                                              ASIC_Frame_03.asic_frame_03.LIN_rw_IR_light16bit_g_1
#define LIN_rw_IR_light16bit_g(c)                                             { LIN_rw_IR_light16bit_g_0= (uint8)(((uint16)(c) & 0xFF));\
                                                                                LIN_rw_IR_light16bit_g_1= (uint8)(((uint16)(c) & 0xFF) >> 8);\
                                                                              }
#define LIN_rw_INTV10bit_max_g_0                                              ASIC_Frame_02.asic_frame_02.LIN_rw_INTV10bit_max_g_0
#define LIN_rw_INTV10bit_max_g_1                                              ASIC_Frame_02.asic_frame_02.LIN_rw_INTV10bit_max_g_1
#define LIN_rw_INTV10bit_max_g(c)                                             { LIN_rw_INTV10bit_max_g_0= (uint8)(((uint16)(c) & 0xFF));\
                                                                                LIN_rw_INTV10bit_max_g_1= (uint8)(((uint16)(c) & 0x03) >> 8);\
                                                                              }
#define LIN_rw_INTV10bit_min_g_0                                              ASIC_Frame_02.asic_frame_02.LIN_rw_INTV10bit_min_g_0
#define LIN_rw_INTV10bit_min_g_1                                              ASIC_Frame_02.asic_frame_02.LIN_rw_INTV10bit_min_g_1
#define LIN_rw_INTV10bit_min_g(c)                                             { LIN_rw_INTV10bit_min_g_0= (uint8)(((uint16)(c) & 0x3F));\
                                                                                LIN_rw_INTV10bit_min_g_1= (uint8)(((uint16)(c) & 0x0F) >> 6);\
                                                                              }
#define LIN_rw_VICALLO_ILO_GHI_ASIC_g_0                                       ASIC_Frame_02.asic_frame_02.LIN_rw_VICALLO_ILO_GHI_ASIC_g_0
#define LIN_rw_VICALLO_ILO_GHI_ASIC_g_1                                       ASIC_Frame_02.asic_frame_02.LIN_rw_VICALLO_ILO_GHI_ASIC_g_1
#define LIN_rw_VICALLO_ILO_GHI_ASIC_g(c)                                      { LIN_rw_VICALLO_ILO_GHI_ASIC_g_0= (uint8)(((uint16)(c) & 0x0F));\
                                                                                LIN_rw_VICALLO_ILO_GHI_ASIC_g_1= (uint8)(((uint16)(c) & 0x3F) >> 4);\
                                                                              }
#define LIN_rw_VTEMP_ASIC_g_0                                                 ASIC_Frame_02.asic_frame_02.LIN_rw_VTEMP_ASIC_g_0
#define LIN_rw_VTEMP_ASIC_g_1                                                 ASIC_Frame_02.asic_frame_02.LIN_rw_VTEMP_ASIC_g_1
#define LIN_rw_VTEMP_ASIC_g(c)                                                { LIN_rw_VTEMP_ASIC_g_0= (uint8)(((uint16)(c) & 0x03));\
                                                                                LIN_rw_VTEMP_ASIC_g_1= (uint8)(((uint16)(c) & 0xFF) >> 2);\
                                                                              }
#define LIN_rb_SPI_Active_ProblemCounter_g                                    ASIC_Frame_02.asic_frame_02.LIN_rb_SPI_Active_ProblemCounter_g
#define LIN_rb_StaticHumTempErrorCounter_g                                    ASIC_Frame_02.asic_frame_02.LIN_rb_StaticHumTempErrorCounter_g
#define LIN_rb_STATH_Reg_g                                                    ASIC_Frame_02.asic_frame_02.LIN_rb_STATH_Reg_g
#define LIN_rb_SupplyVoltage_mg                                               ASIC_Frame_01.asic_frame_01.LIN_rb_SupplyVoltage_mg
#define LIN_rb_MaxLightSignalErrorCnt_g                                       ASIC_Frame_01.asic_frame_01.LIN_rb_MaxLightSignalErrorCnt_g
#define LIN_rb_StaticNoCommunicationCounter                                   ASIC_Frame_01.asic_frame_01.LIN_rb_StaticNoCommunicationCounter
#define LIN_rw_ALS2_ASIC_g_0                                                  ASIC_Frame_01.asic_frame_01.LIN_rw_ALS2_ASIC_g_0
#define LIN_rw_ALS2_ASIC_g_1                                                  ASIC_Frame_01.asic_frame_01.LIN_rw_ALS2_ASIC_g_1
#define LIN_rw_ALS2_ASIC_g(c)                                                 { LIN_rw_ALS2_ASIC_g_0= (uint8)(((uint16)(c) & 0xFF));\
                                                                                LIN_rw_ALS2_ASIC_g_1= (uint8)(((uint16)(c) & 0x03) >> 8);\
                                                                              }
#define LIN_rw_ALS5_ASIC_g_0                                                  ASIC_Frame_01.asic_frame_01.LIN_rw_ALS5_ASIC_g_0
#define LIN_rw_ALS5_ASIC_g_1                                                  ASIC_Frame_01.asic_frame_01.LIN_rw_ALS5_ASIC_g_1
#define LIN_rw_ALS5_ASIC_g(c)                                                 { LIN_rw_ALS5_ASIC_g_0= (uint8)(((uint16)(c) & 0x3F));\
                                                                                LIN_rw_ALS5_ASIC_g_1= (uint8)(((uint16)(c) & 0x0F) >> 6);\
                                                                              }
#define LIN_rw_Amb_light16bit_g_0                                             ASIC_Frame_01.asic_frame_01.LIN_rw_Amb_light16bit_g_0
#define LIN_rw_Amb_light16bit_g_1                                             ASIC_Frame_01.asic_frame_01.LIN_rw_Amb_light16bit_g_1
#define LIN_rw_Amb_light16bit_g(c)                                            { LIN_rw_Amb_light16bit_g_0= (uint8)(((uint16)(c) & 0x0F));\
                                                                                LIN_rw_Amb_light16bit_g_1= (uint8)(((uint16)(c) & 0x3F) >> 4);\
                                                                              }
#define LIN_rw_INREC_ASIC_g_0                                                 ASIC_Frame_01.asic_frame_01.LIN_rw_INREC_ASIC_g_0
#define LIN_rw_INREC_ASIC_g_1                                                 ASIC_Frame_01.asic_frame_01.LIN_rw_INREC_ASIC_g_1
#define LIN_rw_INREC_ASIC_g(c)                                                { LIN_rw_INREC_ASIC_g_0= (uint8)(((uint16)(c) & 0x03));\
                                                                                LIN_rw_INREC_ASIC_g_1= (uint8)(((uint16)(c) & 0xFF) >> 2);\
                                                                              }
#define IR_Brightness                                                         RLS_LIN_3.rls_lin_3.IR_Brightness
#define FW_Brightness_0                                                       RLS_LIN_3.rls_lin_3.FW_Brightness_0
#define FW_Brightness_1                                                       RLS_LIN_3.rls_lin_3.FW_Brightness_1
#define FW_Brightness(c)                                                      { FW_Brightness_0= (uint8)(((uint16)(c) & 0xFF));\
                                                                                FW_Brightness_1= (uint8)(((uint16)(c) & 0x03) >> 8);\
                                                                              }
#define AMB_Brightness_0                                                      RLS_LIN_3.rls_lin_3.AMB_Brightness_0
#define AMB_Brightness_1                                                      RLS_LIN_3.rls_lin_3.AMB_Brightness_1
#define AMB_Brightness(c)                                                     { AMB_Brightness_0= (uint8)(((uint16)(c) & 0xFF));\
                                                                                AMB_Brightness_1= (uint8)(((uint16)(c) & 0x03) >> 8);\
                                                                              }
#define PWM_Voltage_0                                                         RLS_LIN_3.rls_lin_3.PWM_Voltage_0
#define PWM_Voltage_1                                                         RLS_LIN_3.rls_lin_3.PWM_Voltage_1
#define PWM_Voltage(c)                                                        { PWM_Voltage_0= (uint8)(((uint16)(c) & 0xFF));\
                                                                                PWM_Voltage_1= (uint8)(((uint16)(c) & 0x03) >> 8);\
                                                                              }
#define RLS_Wiper_speed                                                       RLS_LIN_2.rls_lin_2.RLS_Wiper_speed
#define RLS_Status_rain_sensor                                                RLS_LIN_2.rls_lin_2.RLS_Status_rain_sensor
#define RLS_Light_switch_reason                                               RLS_LIN_2.rls_lin_2.RLS_Light_switch_reason
#define RLS_SunRoofCloseReqReason                                             RLS_LIN_2.rls_lin_2.RLS_SunRoofCloseReqReason
#define RLS_Light_switch_request                                              RLS_LIN_2.rls_lin_2.RLS_Light_switch_request
#define RLS_Status_low_beam                                                   RLS_LIN_2.rls_lin_2.RLS_Status_low_beam
#define RLS_RLS_error                                                         RLS_LIN_2.rls_lin_2.RLS_RLS_error
#define RLS_Error_calibration_rain_sensor                                     RLS_LIN_2.rls_lin_2.RLS_Error_calibration_rain_sensor
#define RLS_Error_status_rain_sensor                                          RLS_LIN_2.rls_lin_2.RLS_Error_status_rain_sensor
#define RLS_Error_status_coding_rain_sensor                                   RLS_LIN_2.rls_lin_2.RLS_Error_status_coding_rain_sensor
#define RLS_Error_status_light_sensor                                         RLS_LIN_2.rls_lin_2.RLS_Error_status_light_sensor
#define RLS_Error_status_over_temperature                                     RLS_LIN_2.rls_lin_2.RLS_Error_status_over_temperature
#define RLS_Error_status_over_voltage                                         RLS_LIN_2.rls_lin_2.RLS_Error_status_over_voltage
#define RainfallLevel                                                         RLS_LIN_2.rls_lin_2.RainfallLevel
#define RLS_Communication_error                                               RLS_LIN_2.rls_lin_2.RLS_Communication_error
#define RLS_SolarLeft                                                         RLS_LIN_1.rls_lin_1.RLS_SolarLeft
#define RLS_SolarRight                                                        RLS_LIN_1.rls_lin_1.RLS_SolarRight
#define RLS_relativeHumidity                                                  RLS_LIN_1.rls_lin_1.RLS_relativeHumidity
#define RLS_WindshieldTemp                                                    RLS_LIN_1.rls_lin_1.RLS_WindshieldTemp
#define RLS_DewPoint_0                                                        RLS_LIN_1.rls_lin_1.RLS_DewPoint_0
#define RLS_DewPoint_1                                                        RLS_LIN_1.rls_lin_1.RLS_DewPoint_1
#define RLS_DewPoint(c)                                                       { RLS_DewPoint_0= (uint8)(((uint16)(c) & 0xFF));\
                                                                                RLS_DewPoint_1= (uint8)(((uint16)(c) & 0x03) >> 8);\
                                                                              }
#define RLS_Offline_Calibration_Result                                        RLS_LIN_1.rls_lin_1.RLS_Offline_Calibration_Result
#define MasterReqB0                                                           LinReqCmd.linreqcmd.MasterReqB0
#define MasterReqB1                                                           LinReqCmd.linreqcmd.MasterReqB1
#define MasterReqB2                                                           LinReqCmd.linreqcmd.MasterReqB2
#define MasterReqB3                                                           LinReqCmd.linreqcmd.MasterReqB3
#define MasterReqB4                                                           LinReqCmd.linreqcmd.MasterReqB4
#define MasterReqB5                                                           LinReqCmd.linreqcmd.MasterReqB5
#define MasterReqB6                                                           LinReqCmd.linreqcmd.MasterReqB6
#define MasterReqB7                                                           LinReqCmd.linreqcmd.MasterReqB7
#define RLS_Sensitivity_0                                                     BCM_Calibration.bcm_calibration.RLS_Sensitivity_0
#define RLS_Sensitivity_1_0                                                   BCM_Calibration.bcm_calibration.RLS_Sensitivity_1_0
#define RLS_Sensitivity_1_1                                                   BCM_Calibration.bcm_calibration.RLS_Sensitivity_1_1
#define RLS_Sensitivity_1(c)                                                  { RLS_Sensitivity_1_0= (uint8)(((uint16)(c) & 0x03));\
                                                                                RLS_Sensitivity_1_1= (uint8)(((uint16)(c) & 0x0F) >> 2);\
                                                                              }
#define RLS_Sensitivity_2_0                                                   BCM_Calibration.bcm_calibration.RLS_Sensitivity_2_0
#define RLS_Sensitivity_2_1                                                   BCM_Calibration.bcm_calibration.RLS_Sensitivity_2_1
#define RLS_Sensitivity_2(c)                                                  { RLS_Sensitivity_2_0= (uint8)(((uint16)(c) & 0x0F));\
                                                                                RLS_Sensitivity_2_1= (uint8)(((uint16)(c) & 0x03) >> 4);\
                                                                              }
#define RLS_Sensitivity_3                                                     BCM_Calibration.bcm_calibration.RLS_Sensitivity_3
#define RLS_Sensitivity_4                                                     BCM_Calibration.bcm_calibration.RLS_Sensitivity_4
#define RLS_Sensitivity_5_0                                                   BCM_Calibration.bcm_calibration.RLS_Sensitivity_5_0
#define RLS_Sensitivity_5_1                                                   BCM_Calibration.bcm_calibration.RLS_Sensitivity_5_1
#define RLS_Sensitivity_5(c)                                                  { RLS_Sensitivity_5_0= (uint8)(((uint16)(c) & 0x03));\
                                                                                RLS_Sensitivity_5_1= (uint8)(((uint16)(c) & 0x0F) >> 2);\
                                                                              }
#define RLS_Sensitivity_6_0                                                   BCM_Calibration.bcm_calibration.RLS_Sensitivity_6_0
#define RLS_Sensitivity_6_1                                                   BCM_Calibration.bcm_calibration.RLS_Sensitivity_6_1
#define RLS_Sensitivity_6(c)                                                  { RLS_Sensitivity_6_0= (uint8)(((uint16)(c) & 0x0F));\
                                                                                RLS_Sensitivity_6_1= (uint8)(((uint16)(c) & 0x03) >> 4);\
                                                                              }
#define RLS_Sensitivity_7                                                     BCM_Calibration.bcm_calibration.RLS_Sensitivity_7
#define RLS_Sensitivity_8                                                     BCM_Calibration.bcm_calibration.RLS_Sensitivity_8
#define RLS_Parameter_Choice                                                  BCM_Calibration.bcm_calibration.RLS_Parameter_Choice
#define BCM_Wiper_control_operation                                           BCM_LIN_2.bcm_lin_2.BCM_Wiper_control_operation
#define BCM_Wiper_position                                                    BCM_LIN_2.bcm_lin_2.BCM_Wiper_position
#define BCM_Rain_sensitivity                                                  BCM_LIN_2.bcm_lin_2.BCM_Rain_sensitivity
#define BCM_880nmTransimission                                                BCM_LIN_2.bcm_lin_2.BCM_880nmTransimission
#define BCM_550nmTransimission                                                BCM_LIN_2.bcm_lin_2.BCM_550nmTransimission
#define BCM_Coding_data_low_beam_thresholds                                   BCM_LIN_2.bcm_lin_2.BCM_Coding_data_low_beam_thresholds
#define BCM_Coding_type_windscreen                                            BCM_LIN_2.bcm_lin_2.BCM_Coding_type_windscreen
#define BCM_Coding_type_vehicle                                               BCM_LIN_2.bcm_lin_2.BCM_Coding_type_vehicle
#define BCM_RLS_RainDetectReq                                                 BCM_LIN_2.bcm_lin_2.BCM_RLS_RainDetectReq
#define BCM_Coding_wiper_system                                               BCM_LIN_2.bcm_lin_2.BCM_Coding_wiper_system
#define BCM_Coding_data_rain_sensor_activation                                BCM_LIN_2.bcm_lin_2.BCM_Coding_data_rain_sensor_activation
#define BCM_Coding_data_low_beam_high_speed                                   BCM_LIN_2.bcm_lin_2.BCM_Coding_data_low_beam_high_speed
#define BCM_IGNStatus                                                         BCM_LIN_1.bcm_lin_1.BCM_IGNStatus
#define BCM_VehicleSpeed                                                      BCM_LIN_1.bcm_lin_1.BCM_VehicleSpeed
#define BCM_EnvironmentalTemp                                                 BCM_LIN_1.bcm_lin_1.BCM_EnvironmentalTemp
#define l_u8_rd_SlaveRespB0()                                               SlaveRespB0
#define l_u8_wr_SlaveRespB0(a)                                              {SlaveRespB0 = a;}
#define l_u8_rd_SlaveRespB1()                                               SlaveRespB1
#define l_u8_wr_SlaveRespB1(a)                                              {SlaveRespB1 = a;}
#define l_u8_rd_SlaveRespB2()                                               SlaveRespB2
#define l_u8_wr_SlaveRespB2(a)                                              {SlaveRespB2 = a;}
#define l_u8_rd_SlaveRespB3()                                               SlaveRespB3
#define l_u8_wr_SlaveRespB3(a)                                              {SlaveRespB3 = a;}
#define l_u8_rd_SlaveRespB4()                                               SlaveRespB4
#define l_u8_wr_SlaveRespB4(a)                                              {SlaveRespB4 = a;}
#define l_u8_rd_SlaveRespB5()                                               SlaveRespB5
#define l_u8_wr_SlaveRespB5(a)                                              {SlaveRespB5 = a;}
#define l_u8_rd_SlaveRespB6()                                               SlaveRespB6
#define l_u8_wr_SlaveRespB6(a)                                              {SlaveRespB6 = a;}
#define l_u8_rd_SlaveRespB7()                                               SlaveRespB7
#define l_u8_wr_SlaveRespB7(a)                                              {SlaveRespB7 = a;}
#define l_u16_rd_LIN_rw_Vref_ASIC_g()                                         (canuint16)(LIN_rw_Vref_ASIC_g_0)\
                                                                                | ((canuint16)(LIN_rw_Vref_ASIC_g_1)<<8)
#define l_u16_wr_LIN_rw_Vref_ASIC_g(a)                                        {LIN_rw_Vref_ASIC_g_0 = ((canuint8)a);\
                                                                                 LIN_rw_Vref_ASIC_g_1 = ((canuint8)(a>>8));}
#define l_u16_rd_LIN_rw_VDDA_ASIC_g()                                         (canuint16)(LIN_rw_VDDA_ASIC_g_0)\
                                                                                | ((canuint16)(LIN_rw_VDDA_ASIC_g_1)<<6)
#define l_u16_wr_LIN_rw_VDDA_ASIC_g(a)                                        {LIN_rw_VDDA_ASIC_g_0 = ((canuint8)a);\
                                                                                 LIN_rw_VDDA_ASIC_g_1 = ((canuint8)(a>>6));}
#define l_u16_rd_LIN_rw_VDDD_ASIC_g()                                         (canuint16)(LIN_rw_VDDD_ASIC_g_0)\
                                                                                | ((canuint16)(LIN_rw_VDDD_ASIC_g_1)<<4)
#define l_u16_wr_LIN_rw_VDDD_ASIC_g(a)                                        {LIN_rw_VDDD_ASIC_g_0 = ((canuint8)a);\
                                                                                 LIN_rw_VDDD_ASIC_g_1 = ((canuint8)(a>>4));}
#define l_u16_rd_LW_rw_VILO_ICALLO_GHI_ASIC_g()                               (canuint16)(LW_rw_VILO_ICALLO_GHI_ASIC_g_0)\
                                                                                | ((canuint16)(LW_rw_VILO_ICALLO_GHI_ASIC_g_1)<<2)
#define l_u16_wr_LW_rw_VILO_ICALLO_GHI_ASIC_g(a)                              {LW_rw_VILO_ICALLO_GHI_ASIC_g_0 = ((canuint8)a);\
                                                                                 LW_rw_VILO_ICALLO_GHI_ASIC_g_1 = ((canuint8)(a>>2));}
#define l_u16_rd_LIN_rw_REGV_Voltage_g()                                      (canuint16)(LIN_rw_REGV_Voltage_g_0)\
                                                                                | ((canuint16)(LIN_rw_REGV_Voltage_g_1)<<8)
#define l_u16_wr_LIN_rw_REGV_Voltage_g(a)                                     {LIN_rw_REGV_Voltage_g_0 = ((canuint8)a);\
                                                                                 LIN_rw_REGV_Voltage_g_1 = ((canuint8)(a>>8));}
#define l_u8_rd_LIN_rb_ASICReg_NoValidVals_cnt_g()                          LIN_rb_ASICReg_NoValidVals_cnt_g
#define l_u8_wr_LIN_rb_ASICReg_NoValidVals_cnt_g(a)                         {LIN_rb_ASICReg_NoValidVals_cnt_g = a;}
#define l_u16_rd_LIN_rw_Solar_light16bit_1_g()                                (canuint16)(LIN_rw_Solar_light16bit_1_g_0)\
                                                                                | ((canuint16)(LIN_rw_Solar_light16bit_1_g_1)<<8)
#define l_u16_wr_LIN_rw_Solar_light16bit_1_g(a)                               {LIN_rw_Solar_light16bit_1_g_0 = ((canuint8)a);\
                                                                                 LIN_rw_Solar_light16bit_1_g_1 = ((canuint8)(a>>8));}
#define l_u16_rd_LIN_rw_Solar_light16bit_2_g()                                (canuint16)(LIN_rw_Solar_light16bit_2_g_0)\
                                                                                | ((canuint16)(LIN_rw_Solar_light16bit_2_g_1)<<8)
#define l_u16_wr_LIN_rw_Solar_light16bit_2_g(a)                               {LIN_rw_Solar_light16bit_2_g_0 = ((canuint8)a);\
                                                                                 LIN_rw_Solar_light16bit_2_g_1 = ((canuint8)(a>>8));}
#define l_u16_rd_LIN_rw_FW_light16bit_g()                                     (canuint16)(LIN_rw_FW_light16bit_g_0)\
                                                                                | ((canuint16)(LIN_rw_FW_light16bit_g_1)<<8)
#define l_u16_wr_LIN_rw_FW_light16bit_g(a)                                    {LIN_rw_FW_light16bit_g_0 = ((canuint8)a);\
                                                                                 LIN_rw_FW_light16bit_g_1 = ((canuint8)(a>>8));}
#define l_u16_rd_LIN_rw_IR_light16bit_g()                                     (canuint16)(LIN_rw_IR_light16bit_g_0)\
                                                                                | ((canuint16)(LIN_rw_IR_light16bit_g_1)<<8)
#define l_u16_wr_LIN_rw_IR_light16bit_g(a)                                    {LIN_rw_IR_light16bit_g_0 = ((canuint8)a);\
                                                                                 LIN_rw_IR_light16bit_g_1 = ((canuint8)(a>>8));}
#define l_u16_rd_LIN_rw_INTV10bit_max_g()                                     (canuint16)(LIN_rw_INTV10bit_max_g_0)\
                                                                                | ((canuint16)(LIN_rw_INTV10bit_max_g_1)<<8)
#define l_u16_wr_LIN_rw_INTV10bit_max_g(a)                                    {LIN_rw_INTV10bit_max_g_0 = ((canuint8)a);\
                                                                                 LIN_rw_INTV10bit_max_g_1 = ((canuint8)(a>>8));}
#define l_u16_rd_LIN_rw_INTV10bit_min_g()                                     (canuint16)(LIN_rw_INTV10bit_min_g_0)\
                                                                                | ((canuint16)(LIN_rw_INTV10bit_min_g_1)<<6)
#define l_u16_wr_LIN_rw_INTV10bit_min_g(a)                                    {LIN_rw_INTV10bit_min_g_0 = ((canuint8)a);\
                                                                                 LIN_rw_INTV10bit_min_g_1 = ((canuint8)(a>>6));}
#define l_u16_rd_LIN_rw_VICALLO_ILO_GHI_ASIC_g()                              (canuint16)(LIN_rw_VICALLO_ILO_GHI_ASIC_g_0)\
                                                                                | ((canuint16)(LIN_rw_VICALLO_ILO_GHI_ASIC_g_1)<<4)
#define l_u16_wr_LIN_rw_VICALLO_ILO_GHI_ASIC_g(a)                             {LIN_rw_VICALLO_ILO_GHI_ASIC_g_0 = ((canuint8)a);\
                                                                                 LIN_rw_VICALLO_ILO_GHI_ASIC_g_1 = ((canuint8)(a>>4));}
#define l_u16_rd_LIN_rw_VTEMP_ASIC_g()                                        (canuint16)(LIN_rw_VTEMP_ASIC_g_0)\
                                                                                | ((canuint16)(LIN_rw_VTEMP_ASIC_g_1)<<2)
#define l_u16_wr_LIN_rw_VTEMP_ASIC_g(a)                                       {LIN_rw_VTEMP_ASIC_g_0 = ((canuint8)a);\
                                                                                 LIN_rw_VTEMP_ASIC_g_1 = ((canuint8)(a>>2));}
#define l_u8_rd_LIN_rb_SPI_Active_ProblemCounter_g()                        LIN_rb_SPI_Active_ProblemCounter_g
#define l_u8_wr_LIN_rb_SPI_Active_ProblemCounter_g(a)                       {LIN_rb_SPI_Active_ProblemCounter_g = a;}
#define l_u8_rd_LIN_rb_StaticHumTempErrorCounter_g()                        LIN_rb_StaticHumTempErrorCounter_g
#define l_u8_wr_LIN_rb_StaticHumTempErrorCounter_g(a)                       {LIN_rb_StaticHumTempErrorCounter_g = a;}
#define l_u8_rd_LIN_rb_STATH_Reg_g()                                        LIN_rb_STATH_Reg_g
#define l_u8_wr_LIN_rb_STATH_Reg_g(a)                                       {LIN_rb_STATH_Reg_g = a;}
#define l_u8_rd_LIN_rb_SupplyVoltage_mg()                                   LIN_rb_SupplyVoltage_mg
#define l_u8_wr_LIN_rb_SupplyVoltage_mg(a)                                  {LIN_rb_SupplyVoltage_mg = a;}
#define l_u8_rd_LIN_rb_MaxLightSignalErrorCnt_g()                           LIN_rb_MaxLightSignalErrorCnt_g
#define l_u8_wr_LIN_rb_MaxLightSignalErrorCnt_g(a)                          {LIN_rb_MaxLightSignalErrorCnt_g = a;}
#define l_u8_rd_LIN_rb_StaticNoCommunicationCounter()                       LIN_rb_StaticNoCommunicationCounter
#define l_u8_wr_LIN_rb_StaticNoCommunicationCounter(a)                      {LIN_rb_StaticNoCommunicationCounter = a;}
#define l_u16_rd_LIN_rw_ALS2_ASIC_g()                                         (canuint16)(LIN_rw_ALS2_ASIC_g_0)\
                                                                                | ((canuint16)(LIN_rw_ALS2_ASIC_g_1)<<8)
#define l_u16_wr_LIN_rw_ALS2_ASIC_g(a)                                        {LIN_rw_ALS2_ASIC_g_0 = ((canuint8)a);\
                                                                                 LIN_rw_ALS2_ASIC_g_1 = ((canuint8)(a>>8));}
#define l_u16_rd_LIN_rw_ALS5_ASIC_g()                                         (canuint16)(LIN_rw_ALS5_ASIC_g_0)\
                                                                                | ((canuint16)(LIN_rw_ALS5_ASIC_g_1)<<6)
#define l_u16_wr_LIN_rw_ALS5_ASIC_g(a)                                        {LIN_rw_ALS5_ASIC_g_0 = ((canuint8)a);\
                                                                                 LIN_rw_ALS5_ASIC_g_1 = ((canuint8)(a>>6));}
#define l_u16_rd_LIN_rw_Amb_light16bit_g()                                    (canuint16)(LIN_rw_Amb_light16bit_g_0)\
                                                                                | ((canuint16)(LIN_rw_Amb_light16bit_g_1)<<4)
#define l_u16_wr_LIN_rw_Amb_light16bit_g(a)                                   {LIN_rw_Amb_light16bit_g_0 = ((canuint8)a);\
                                                                                 LIN_rw_Amb_light16bit_g_1 = ((canuint8)(a>>4));}
#define l_u16_rd_LIN_rw_INREC_ASIC_g()                                        (canuint16)(LIN_rw_INREC_ASIC_g_0)\
                                                                                | ((canuint16)(LIN_rw_INREC_ASIC_g_1)<<2)
#define l_u16_wr_LIN_rw_INREC_ASIC_g(a)                                       {LIN_rw_INREC_ASIC_g_0 = ((canuint8)(a));\
                                                                                 LIN_rw_INREC_ASIC_g_1 = ((canuint8)(a>>2));}
#define l_u8_rd_IR_Brightness()                                             IR_Brightness
#define l_u8_wr_IR_Brightness(a)                                            {IR_Brightness = a;}
#define l_u16_rd_FW_Brightness()                                              (canuint16)(FW_Brightness_0)\
                                                                                | ((canuint16)(FW_Brightness_1)<<8)
#define l_u16_wr_FW_Brightness(a)                                             {FW_Brightness_0 = ((canuint8)a);\
                                                                                 FW_Brightness_1 = ((canuint8)((a)>>8));} /*******Blake_LI 2018_12_28******/
#define l_u16_rd_AMB_Brightness()                                             (canuint16)(AMB_Brightness_0)\
                                                                                | ((canuint16)(AMB_Brightness_1)<<8)
#define l_u16_wr_AMB_Brightness(a)                                            {AMB_Brightness_0 = ((canuint8)a);\
                                                                                 AMB_Brightness_1 = ((canuint8)((a)>>8));} /*******Blake_LI 2018_12_28******/
#define l_u16_rd_PWM_Voltage()                                                (canuint16)(PWM_Voltage_0)\
                                                                                | ((canuint16)(PWM_Voltage_1)<<8)
#define l_u16_wr_PWM_Voltage(a)                                               {PWM_Voltage_0 = ((canuint8)a);\
                                                                                 PWM_Voltage_1 = ((canuint8)((a)>>8));}  /******Blake_LI update 2018_12_28*****/
#define l_u8_rd_RLS_Wiper_speed()                                           RLS_Wiper_speed
#define l_u8_wr_RLS_Wiper_speed(a)                                          {RLS_Wiper_speed = a;}
#define l_u8_rd_RLS_Status_rain_sensor()                                    RLS_Status_rain_sensor
#define l_u8_wr_RLS_Status_rain_sensor(a)                                   {RLS_Status_rain_sensor = a;}
#define l_u8_rd_RLS_Light_switch_reason()                                   RLS_Light_switch_reason
#define l_u8_wr_RLS_Light_switch_reason(a)                                  {RLS_Light_switch_reason = a;}
#define l_u8_rd_RLS_SunRoofCloseReqReason()                                 RLS_SunRoofCloseReqReason
#define l_u8_wr_RLS_SunRoofCloseReqReason(a)                                {RLS_SunRoofCloseReqReason = a;}
#define l_u8_rd_RLS_Light_switch_request()                                  RLS_Light_switch_request
#define l_u8_wr_RLS_Light_switch_request(a)                                 {RLS_Light_switch_request = a;}
#define l_u8_rd_RLS_Status_low_beam()                                       RLS_Status_low_beam
#define l_u8_wr_RLS_Status_low_beam(a)                                      {RLS_Status_low_beam = a;}
#define l_u8_rd_RLS_RLS_error()                                             RLS_RLS_error
#define l_u8_wr_RLS_RLS_error(a)                                            {RLS_RLS_error = a;}
#define l_u8_rd_RLS_Error_calibration_rain_sensor()                         RLS_Error_calibration_rain_sensor
#define l_u8_wr_RLS_Error_calibration_rain_sensor(a)                        {RLS_Error_calibration_rain_sensor = a;}
#define l_u8_rd_RLS_Error_status_rain_sensor()                              RLS_Error_status_rain_sensor
#define l_u8_wr_RLS_Error_status_rain_sensor(a)                             {RLS_Error_status_rain_sensor = a;}
#define l_u8_rd_RLS_Error_status_coding_rain_sensor()                       RLS_Error_status_coding_rain_sensor
#define l_u8_wr_RLS_Error_status_coding_rain_sensor(a)                      {RLS_Error_status_coding_rain_sensor = a;}
#define l_u8_rd_RLS_Error_status_light_sensor()                             RLS_Error_status_light_sensor
#define l_u8_wr_RLS_Error_status_light_sensor(a)                            {RLS_Error_status_light_sensor = a;}
#define l_u8_rd_RLS_Error_status_over_temperature()                         RLS_Error_status_over_temperature
#define l_u8_wr_RLS_Error_status_over_temperature(a)                        {RLS_Error_status_over_temperature = a;}
#define l_u8_rd_RLS_Error_status_over_voltage()                             RLS_Error_status_over_voltage
#define l_u8_wr_RLS_Error_status_over_voltage(a)                            {RLS_Error_status_over_voltage = a;}
#define l_u8_rd_RainfallLevel()                                             RainfallLevel
#define l_u8_wr_RainfallLevel(a)                                            {RainfallLevel = a;}
#define l_bool_rd_RLS_Communication_error()                                     RLS_Communication_error
#define l_bool_wr_RLS_Communication_error(a)                                    {RLS_Communication_error = a;}
#define l_u8_rd_RLS_SolarLeft()                                             RLS_SolarLeft
#define l_u8_wr_RLS_SolarLeft(a)                                            {RLS_SolarLeft = a;}
#define l_u8_rd_RLS_SolarRight()                                            RLS_SolarRight
#define l_u8_wr_RLS_SolarRight(a)                                           {RLS_SolarRight = a;}
#define l_u8_rd_RLS_relativeHumidity()                                      RLS_relativeHumidity
#define l_u8_wr_RLS_relativeHumidity(a)                                     {RLS_relativeHumidity = a;}
#define l_u8_rd_RLS_WindshieldTemp()                                        RLS_WindshieldTemp
#define l_u8_wr_RLS_WindshieldTemp(a)                                       {RLS_WindshieldTemp = a;}
#define l_u16_rd_RLS_DewPoint()                                               (canuint16)(RLS_DewPoint_0)\
                                                                                | ((canuint16)(RLS_DewPoint_1)<<8)
#define l_u16_wr_RLS_DewPoint(a)                                              {RLS_DewPoint_0 = ((canuint8)a);\
                                                                                 RLS_DewPoint_1 = ((canuint8)((a)>>8));}  /****Blake_LI 2018_12_28 Update*****/
#define l_u8_rd_RLS_Offline_Calibration_Result()                            RLS_Offline_Calibration_Result
#define l_u8_wr_RLS_Offline_Calibration_Result(a)                           {RLS_Offline_Calibration_Result = a;}
#define l_u8_rd_MasterReqB0()                                               MasterReqB0
#define l_u8_wr_MasterReqB0(a)                                              {MasterReqB0 = a;}
#define l_u8_rd_MasterReqB1()                                               MasterReqB1
#define l_u8_wr_MasterReqB1(a)                                              {MasterReqB1 = a;}
#define l_u8_rd_MasterReqB2()                                               MasterReqB2
#define l_u8_wr_MasterReqB2(a)                                              {MasterReqB2 = a;}
#define l_u8_rd_MasterReqB3()                                               MasterReqB3
#define l_u8_wr_MasterReqB3(a)                                              {MasterReqB3 = a;}
#define l_u8_rd_MasterReqB4()                                               MasterReqB4
#define l_u8_wr_MasterReqB4(a)                                              {MasterReqB4 = a;}
#define l_u8_rd_MasterReqB5()                                               MasterReqB5
#define l_u8_wr_MasterReqB5(a)                                              {MasterReqB5 = a;}
#define l_u8_rd_MasterReqB6()                                               MasterReqB6
#define l_u8_wr_MasterReqB6(a)                                              {MasterReqB6 = a;}
#define l_u8_rd_MasterReqB7()                                               MasterReqB7
#define l_u8_wr_MasterReqB7(a)                                              {MasterReqB7 = a;}
#define l_u8_rd_RLS_Sensitivity_0()                                         RLS_Sensitivity_0
#define l_u8_wr_RLS_Sensitivity_0(a)                                        {RLS_Sensitivity_0 = a;}
#define l_u16_rd_RLS_Sensitivity_1()                                          (canuint16)(RLS_Sensitivity_1_0)\
                                                                                | ((canuint16)(RLS_Sensitivity_1_1)<<2)
#define l_u16_wr_RLS_Sensitivity_1(a)                                         {RLS_Sensitivity_1_0 = ((canuint8)a);\
                                                                                 RLS_Sensitivity_1_1 = ((canuint8)a>>2);}
#define l_u16_rd_RLS_Sensitivity_2()                                          (canuint16)(RLS_Sensitivity_2_0)\
                                                                                | ((canuint16)(RLS_Sensitivity_2_1)<<4)
#define l_u16_wr_RLS_Sensitivity_2(a)                                         {RLS_Sensitivity_2_0 = ((canuint8)a);\
                                                                                 RLS_Sensitivity_2_1 = ((canuint8)a>>4);}
#define l_u8_rd_RLS_Sensitivity_3()                                         RLS_Sensitivity_3
#define l_u8_wr_RLS_Sensitivity_3(a)                                        {RLS_Sensitivity_3 = a;}
#define l_u8_rd_RLS_Sensitivity_4()                                         RLS_Sensitivity_4
#define l_u8_wr_RLS_Sensitivity_4(a)                                        {RLS_Sensitivity_4 = a;}
#define l_u16_rd_RLS_Sensitivity_5()                                          (canuint16)(RLS_Sensitivity_5_0)\
                                                                                | ((canuint16)(RLS_Sensitivity_5_1)<<2)
#define l_u16_wr_RLS_Sensitivity_5(a)                                         {RLS_Sensitivity_5_0 = ((canuint8)a);\
                                                                                 RLS_Sensitivity_5_1 = ((canuint8)a>>2);}
#define l_u16_rd_RLS_Sensitivity_6()                                          (canuint16)(RLS_Sensitivity_6_0)\
                                                                                | ((canuint16)(RLS_Sensitivity_6_1)<<4)
#define l_u16_wr_RLS_Sensitivity_6(a)                                         {RLS_Sensitivity_6_0 = ((canuint8)a);\
                                                                                 RLS_Sensitivity_6_1 = ((canuint8)a>>4);}
#define l_u8_rd_RLS_Sensitivity_7()                                         RLS_Sensitivity_7
#define l_u8_wr_RLS_Sensitivity_7(a)                                        {RLS_Sensitivity_7 = a;}
#define l_u8_rd_RLS_Sensitivity_8()                                         RLS_Sensitivity_8
#define l_u8_wr_RLS_Sensitivity_8(a)                                        {RLS_Sensitivity_8 = a;}
#define l_u8_rd_RLS_Parameter_Choice()                                      RLS_Parameter_Choice
#define l_u8_wr_RLS_Parameter_Choice(a)                                     {RLS_Parameter_Choice = a;}
#define l_u8_rd_BCM_Wiper_control_operation()                               BCM_Wiper_control_operation
#define l_u8_wr_BCM_Wiper_control_operation(a)                              {BCM_Wiper_control_operation = a;}
#define l_u8_rd_BCM_Wiper_position()                                        BCM_Wiper_position
#define l_u8_wr_BCM_Wiper_position(a)                                       {BCM_Wiper_position = a;}
#define l_u8_rd_BCM_Rain_sensitivity()                                      BCM_Rain_sensitivity
#define l_u8_wr_BCM_Rain_sensitivity(a)                                     {BCM_Rain_sensitivity = a;}
#define l_u8_rd_BCM_880nmTransimission()                                    BCM_880nmTransimission
#define l_u8_wr_BCM_880nmTransimission(a)                                   {BCM_880nmTransimission = a;}
#define l_u8_rd_BCM_550nmTransimission()                                    BCM_550nmTransimission
#define l_u8_wr_BCM_550nmTransimission(a)                                   {BCM_550nmTransimission = a;}
#define l_u8_rd_BCM_Coding_data_low_beam_thresholds()                       BCM_Coding_data_low_beam_thresholds
#define l_u8_wr_BCM_Coding_data_low_beam_thresholds(a)                      {BCM_Coding_data_low_beam_thresholds = a;}
#define l_u8_rd_BCM_Coding_type_windscreen()                                BCM_Coding_type_windscreen
#define l_u8_wr_BCM_Coding_type_windscreen(a)                               {BCM_Coding_type_windscreen = a;}
#define l_u8_rd_BCM_Coding_type_vehicle()                                   BCM_Coding_type_vehicle
#define l_u8_wr_BCM_Coding_type_vehicle(a)                                  {BCM_Coding_type_vehicle = a;}
#define l_bool_rd_BCM_RLS_RainDetectReq()                                       BCM_RLS_RainDetectReq
#define l_bool_wr_BCM_RLS_RainDetectReq(a)                                      {BCM_RLS_RainDetectReq = a;}
#define l_u8_rd_BCM_Coding_wiper_system()                                   BCM_Coding_wiper_system
#define l_u8_wr_BCM_Coding_wiper_system(a)                                  {BCM_Coding_wiper_system = a;}
#define l_u8_rd_BCM_Coding_data_rain_sensor_activation()                    BCM_Coding_data_rain_sensor_activation
#define l_u8_wr_BCM_Coding_data_rain_sensor_activation(a)                   {BCM_Coding_data_rain_sensor_activation = a;}
#define l_u8_rd_BCM_Coding_data_low_beam_high_speed()                       BCM_Coding_data_low_beam_high_speed
#define l_u8_wr_BCM_Coding_data_low_beam_high_speed(a)                      {BCM_Coding_data_low_beam_high_speed = a;}
#define l_u8_rd_BCM_IGNStatus()                                             BCM_IGNStatus
#define l_u8_wr_BCM_IGNStatus(a)                                            {BCM_IGNStatus = a;}
#define l_u8_rd_BCM_VehicleSpeed()                                          BCM_VehicleSpeed
#define l_u8_wr_BCM_VehicleSpeed(a)                                         {BCM_VehicleSpeed = a;}
#define l_u8_rd_BCM_EnvironmentalTemp()                                     BCM_EnvironmentalTemp
#define l_u8_wr_BCM_EnvironmentalTemp(a)                                    {BCM_EnvironmentalTemp = a;}


#endif  /* I_LIN_RLS_H */
