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
#define cb_HANDLE_RS_SENSOR_02            5
#define cb_HANDLE_RS_SENSOR_01            6
#define cb_HANDLE_LinReqCmd               7
#define cb_HANDLE_BCMLin1Fr02             8
#define cb_HANDLE_WMMLin1Fr01             9

#define cb_HANDLE_LinReqCmd_g     cb_HANDLE_LinReqCmd
#define cb_HANDLE_LinRespCmd_g    cb_HANDLE_LinRespCmd
#define cb_HANDLE_ASIC_Frame_01_g cb_HANDLE_ASIC_Frame_01
#define cb_HANDLE_ASIC_Frame_02_g cb_HANDLE_ASIC_Frame_02
#define cb_HANDLE_ASIC_Frame_03_g cb_HANDLE_ASIC_Frame_03
#define cb_HANDLE_ASIC_Frame_04_g cb_HANDLE_ASIC_Frame_04

#define cb_HANDLE_BCM1_LIN1_01_g   cb_HANDLE_WMMLin1Fr01
#define cb_HANDLE_BCM1_LIN1_02_g   cb_HANDLE_BCMLin1Fr02
#define cb_HANDLE_RLSs_01_g        cb_HANDLE_RS_SENSOR_01 
#define cb_HANDLE_RLSs_02_g        cb_HANDLE_RS_SENSOR_02 
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
  canbittype          LIN_rw_VILO_ICALLO_GHI_ASIC_g_0: 2;
  canbittype          LIN_rw_VILO_ICALLO_GHI_ASIC_g_1: 8;
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
  canbittype                   L_Err_State_Light_Sens: 2;
  canbittype                   L_Light_Switch_Request: 2;
  canbittype                      L_Status_Light_Sens: 2;
  canbittype                       L_Err_State_Coding: 2;
  canbittype                    L_Light_Switch_Reason: 8;
  canbittype               L_Light_HudBrightnessValue: 7;
  canbittype                                  unused0: 1;
  canbittype                L_Light_HudBrightnessUnit: 2;
  canbittype                                  unused1: 2;
  canbittype                    L_Err_State_Over_Volt: 2;
  canbittype                    L_Err_State_Over_Temp: 2;
  canbittype                                L_RH_Sens: 8;
  canbittype                          L_Window_Temp_0: 8;
  canbittype                          L_Window_Temp_1: 3;
  canbittype                              L_DP_Temp_0: 5;
  canbittype                              L_DP_Temp_1: 6;
  canbittype                L_Err_State_Humidity_Sens: 1;
  canbittype                                  unused2: 1;
} _c_RS_SENSOR_02_msgType;

typedef struct {
  canbittype                                  unused0: 2;
  canbittype                       L_RS_RainfallLevel: 2;
  canbittype                      L_RS_WiperAutoSpReq: 4;
  canbittype                                  unused1: 8;
  canbittype                                  unused2: 8;
  canbittype                                  unused3: 4;
  canbittype                       L_Err_State_Cal_RS: 2;
  canbittype                     L_RS_RainSensorError: 1;
  canbittype          RS_Sensor_01_LIN_Response_Error: 1;
  canbittype                       L_Status_Rain_Sens: 4;
  canbittype                   L_Sunroof_Win_CloseReq: 2;
  canbittype                            L_RLS_ModeSts: 1;
  canbittype                                  unused4: 1;
  canbittype                    L_RS_SolarSensorError: 1;
  canbittype                                  unused5: 1;
  canbittype                           L_Signal_Error: 2;
  canbittype                                  unused6: 4;
  canbittype                 L_Value_Solar_Right_Sens: 8;
  canbittype                  L_Value_Solar_Left_Sens: 8;
} _c_RS_SENSOR_01_msgType;


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
  canbittype                          L_EMS_EngStatus: 3;
  canbittype                                  unused0: 3;
  canbittype                       L_BCM_RS_ManWaInfo: 1;
  canbittype                        WiprPosnForSrvReq: 1;
  canbittype                       L_BCM_RS_RainSwSts: 4;
  canbittype                         L_RLS_ModeEnable: 2;
  canbittype                         L_All_Wdw_Closed: 2;
  canbittype                 L_PEPS_PowerModeValidity: 2;
  canbittype                         L_PEPS_PowerMode: 3;
  canbittype                           L_VCU_ePTReady: 1;
  canbittype                                  unused1: 1;
  canbittype                        L_VCU_StartActive: 1;
  canbittype                                  unused2: 3;
  canbittype                     L_BCM_VehicleSpeed_0: 5;
  canbittype                     L_BCM_VehicleSpeed_1: 8;
  canbittype                        L_BCM_OutdoorTemp: 8;
  canbittype                                  unused3: 3;
  canbittype                        WiprMotFrntOffsAg: 4;
  canbittype                                  unused4: 1;
  canbittype                                  unused5: 2;
  canbittype                       L_Rain_Sensitivity: 4;
  canbittype                                  unused6: 2;
} _c_BCMLin1Fr02_msgType;

typedef struct {
  canbittype                                  unused0: 8;
  canbittype                                 WiprActv: 1;
  canbittype                                  unused1: 1;
  canbittype                         WiprInPrkgPosnLo: 1;
  canbittype                             WiprInWipgAr: 1;
  canbittype                                  unused2: 1;
  canbittype                           WiprMotErrSafe: 2;
  canbittype                               ErrRespWMM: 1;
  canbittype                        WiprMotHiVoltDetd: 2;
  canbittype                        WiprMotLoVoltDetd: 2;
  canbittype                          WiprMotOvldDetd: 2;
  canbittype                             WshngCycActv: 1;
  canbittype                                  unused3: 1;
  canbittype                             WiprMotCrkAg: 8;
} _c_WMMLin1Fr01_msgType;


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
    _c_RS_SENSOR_02_msgType rs_sensor_02;
} _c_RS_SENSOR_02_buf;

typedef union {
    unsigned char _c[8];
    _c_RS_SENSOR_01_msgType rs_sensor_01;
} _c_RS_SENSOR_01_buf;


/* Receive messages */

typedef union {
    unsigned char _c[8];
    _c_LinReqCmd_msgType linreqcmd;
} _c_LinReqCmd_buf;

typedef union {
    unsigned char _c[8];
    _c_BCMLin1Fr02_msgType bcmlin1fr02;
} _c_BCMLin1Fr02_buf;

typedef union {
    unsigned char _c[4];
    _c_WMMLin1Fr01_msgType wmmlin1fr01;
} _c_WMMLin1Fr01_buf;


/******************************************************************************/
/*                          Databuffer for send objects                       */
/******************************************************************************/

extern MEMORY_FAR _c_LinRespCmd_buf LinRespCmd;
extern MEMORY_FAR _c_ASIC_Frame_04_buf ASIC_Frame_04;
extern MEMORY_FAR _c_ASIC_Frame_03_buf ASIC_Frame_03;
extern MEMORY_FAR _c_ASIC_Frame_02_buf ASIC_Frame_02;
extern MEMORY_FAR _c_ASIC_Frame_01_buf ASIC_Frame_01;
extern MEMORY_FAR _c_RS_SENSOR_02_buf RS_SENSOR_02;
extern MEMORY_FAR _c_RS_SENSOR_01_buf RS_SENSOR_01;

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
#define RS_SENSOR_02_conf_b             uLinConfirmationFlags.w[0].b5
#define l_flg_tst_RS_SENSOR_02()       (RS_SENSOR_02_conf_b != 0)
#define l_flg_clr_RS_SENSOR_02()       {RS_SENSOR_02_conf_b = 0;}
#define RS_SENSOR_01_conf_b             uLinConfirmationFlags.w[0].b6
#define l_flg_tst_RS_SENSOR_01()       (RS_SENSOR_01_conf_b != 0)
#define l_flg_clr_RS_SENSOR_01()       {RS_SENSOR_01_conf_b = 0;}

/******************************************************************************/
/*                         Databuffer for receive objects                     */
/******************************************************************************/

extern MEMORY_FAR _c_LinReqCmd_buf LinReqCmd;
extern MEMORY_FAR _c_BCMLin1Fr02_buf BCMLin1Fr02;
extern MEMORY_FAR _c_WMMLin1Fr01_buf WMMLin1Fr01;

/******************************************************************************/
/*                          Databuffer for indicationflags                    */
/******************************************************************************/

#define LinReqCmd_ind_b             uLinIndicationFlags.w[0].b0
#define l_flg_tst_LinReqCmd()       (LinReqCmd_ind_b != 0)
#define l_flg_clr_LinReqCmd()       {LinReqCmd_ind_b = 0;}
#define BCMLin1Fr02_ind_b             uLinIndicationFlags.w[0].b1
#define l_flg_tst_BCMLin1Fr02()       (BCMLin1Fr02_ind_b != 0)
#define l_flg_clr_BCMLin1Fr02()       {BCMLin1Fr02_ind_b = 0;}
#define WMMLin1Fr01_ind_b             uLinIndicationFlags.w[0].b2
#define l_flg_tst_WMMLin1Fr01()       (WMMLin1Fr01_ind_b != 0)
#define l_flg_clr_WMMLin1Fr01()       {WMMLin1Fr01_ind_b = 0;}

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
#define LIN_rw_VILO_ICALLO_GHI_ASIC_g_0                                       ASIC_Frame_04.asic_frame_04.LIN_rw_VILO_ICALLO_GHI_ASIC_g_0
#define LIN_rw_VILO_ICALLO_GHI_ASIC_g_1                                       ASIC_Frame_04.asic_frame_04.LIN_rw_VILO_ICALLO_GHI_ASIC_g_1
#define LIN_rw_VILO_ICALLO_GHI_ASIC_g(c)                                      { LIN_rw_VILO_ICALLO_GHI_ASIC_g_0= (uint8)(((uint16)(c) & 0x03));\
                                                                                LIN_rw_VILO_ICALLO_GHI_ASIC_g_1= (uint8)(((uint16)(c) & 0xFF) >> 2);\
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
#define L_Err_State_Light_Sens                                                RS_SENSOR_02.rs_sensor_02.L_Err_State_Light_Sens
#define L_Light_Switch_Request                                                RS_SENSOR_02.rs_sensor_02.L_Light_Switch_Request
#define L_Status_Light_Sens                                                   RS_SENSOR_02.rs_sensor_02.L_Status_Light_Sens
#define L_Err_State_Coding                                                    RS_SENSOR_02.rs_sensor_02.L_Err_State_Coding
#define L_Light_Switch_Reason                                                 RS_SENSOR_02.rs_sensor_02.L_Light_Switch_Reason
#define L_Light_HudBrightnessValue                                            RS_SENSOR_02.rs_sensor_02.L_Light_HudBrightnessValue
#define L_Light_HudBrightnessUnit                                             RS_SENSOR_02.rs_sensor_02.L_Light_HudBrightnessUnit
#define L_Err_State_Over_Volt                                                 RS_SENSOR_02.rs_sensor_02.L_Err_State_Over_Volt
#define L_Err_State_Over_Temp                                                 RS_SENSOR_02.rs_sensor_02.L_Err_State_Over_Temp
#define L_RH_Sens                                                             RS_SENSOR_02.rs_sensor_02.L_RH_Sens
#define L_Window_Temp_0                                                       RS_SENSOR_02.rs_sensor_02.L_Window_Temp_0
#define L_Window_Temp_1                                                       RS_SENSOR_02.rs_sensor_02.L_Window_Temp_1
#define L_Window_Temp(c)                                                      { L_Window_Temp_0= (uint8)(((uint16)(c) & 0xFF));\
                                                                                L_Window_Temp_1= (uint8)(((uint16)(c) & 0x07) >> 8);\
                                                                              }
#define L_DP_Temp_0                                                           RS_SENSOR_02.rs_sensor_02.L_DP_Temp_0
#define L_DP_Temp_1                                                           RS_SENSOR_02.rs_sensor_02.L_DP_Temp_1
#define L_DP_Temp(c)                                                          { L_DP_Temp_0= (uint8)(((uint16)(c) & 0x1F));\
                                                                                L_DP_Temp_1= (uint8)(((uint16)(c) & 0x3F) >> 5);\
                                                                              }
#define L_Err_State_Humidity_Sens                                             RS_SENSOR_02.rs_sensor_02.L_Err_State_Humidity_Sens
#define L_RS_RainfallLevel                                                    RS_SENSOR_01.rs_sensor_01.L_RS_RainfallLevel
#define L_RS_WiperAutoSpReq                                                   RS_SENSOR_01.rs_sensor_01.L_RS_WiperAutoSpReq
#define L_Err_State_Cal_RS                                                    RS_SENSOR_01.rs_sensor_01.L_Err_State_Cal_RS
#define L_RS_RainSensorError                                                  RS_SENSOR_01.rs_sensor_01.L_RS_RainSensorError
#define RS_Sensor_01_LIN_Response_Error                                       RS_SENSOR_01.rs_sensor_01.RS_Sensor_01_LIN_Response_Error
#define L_Status_Rain_Sens                                                    RS_SENSOR_01.rs_sensor_01.L_Status_Rain_Sens
#define L_Sunroof_Win_CloseReq                                                RS_SENSOR_01.rs_sensor_01.L_Sunroof_Win_CloseReq
#define L_RLS_ModeSts                                                         RS_SENSOR_01.rs_sensor_01.L_RLS_ModeSts
#define L_RS_SolarSensorError                                                 RS_SENSOR_01.rs_sensor_01.L_RS_SolarSensorError
#define L_Signal_Error                                                        RS_SENSOR_01.rs_sensor_01.L_Signal_Error
#define L_Value_Solar_Right_Sens                                              RS_SENSOR_01.rs_sensor_01.L_Value_Solar_Right_Sens
#define L_Value_Solar_Left_Sens                                               RS_SENSOR_01.rs_sensor_01.L_Value_Solar_Left_Sens
#define MasterReqB0                                                           LinReqCmd.linreqcmd.MasterReqB0
#define MasterReqB1                                                           LinReqCmd.linreqcmd.MasterReqB1
#define MasterReqB2                                                           LinReqCmd.linreqcmd.MasterReqB2
#define MasterReqB3                                                           LinReqCmd.linreqcmd.MasterReqB3
#define MasterReqB4                                                           LinReqCmd.linreqcmd.MasterReqB4
#define MasterReqB5                                                           LinReqCmd.linreqcmd.MasterReqB5
#define MasterReqB6                                                           LinReqCmd.linreqcmd.MasterReqB6
#define MasterReqB7                                                           LinReqCmd.linreqcmd.MasterReqB7
#define L_EMS_EngStatus                                                       BCMLin1Fr02.bcmlin1fr02.L_EMS_EngStatus
#define L_BCM_RS_ManWaInfo                                                    BCMLin1Fr02.bcmlin1fr02.L_BCM_RS_ManWaInfo
#define WiprPosnForSrvReq                                                     BCMLin1Fr02.bcmlin1fr02.WiprPosnForSrvReq
#define L_BCM_RS_RainSwSts                                                    BCMLin1Fr02.bcmlin1fr02.L_BCM_RS_RainSwSts
#define L_RLS_ModeEnable                                                      BCMLin1Fr02.bcmlin1fr02.L_RLS_ModeEnable
#define L_All_Wdw_Closed                                                      BCMLin1Fr02.bcmlin1fr02.L_All_Wdw_Closed
#define L_PEPS_PowerModeValidity                                              BCMLin1Fr02.bcmlin1fr02.L_PEPS_PowerModeValidity
#define L_PEPS_PowerMode1                                                     BCMLin1Fr02.bcmlin1fr02.L_PEPS_PowerMode
#define L_VCU_ePTReady                                                        BCMLin1Fr02.bcmlin1fr02.L_VCU_ePTReady
#define L_VCU_StartActive                                                     BCMLin1Fr02.bcmlin1fr02.L_VCU_StartActive
#define L_BCM_VehicleSpeed_0                                                  BCMLin1Fr02.bcmlin1fr02.L_BCM_VehicleSpeed_0
#define L_BCM_VehicleSpeed_1                                                  BCMLin1Fr02.bcmlin1fr02.L_BCM_VehicleSpeed_1
#define L_BCM_VehicleSpeed(c)                                                 { L_BCM_VehicleSpeed_0= (uint8)(((uint16)(c) & 0x1F));\
                                                                                L_BCM_VehicleSpeed_1= (uint8)(((uint16)(c) & 0xFF) >> 5);\
                                                                              }
#define L_BCM_OutdoorTemp                                                     BCMLin1Fr02.bcmlin1fr02.L_BCM_OutdoorTemp
#define WiprMotFrntOffsAg                                                     BCMLin1Fr02.bcmlin1fr02.WiprMotFrntOffsAg
#define L_Rain_Sensitivity                                                    BCMLin1Fr02.bcmlin1fr02.L_Rain_Sensitivity
#define WiprActv                                                              WMMLin1Fr01.wmmlin1fr01.WiprActv
#define WiprInPrkgPosnLo                                                      WMMLin1Fr01.wmmlin1fr01.WiprInPrkgPosnLo
#define WiprInWipgAr                                                          WMMLin1Fr01.wmmlin1fr01.WiprInWipgAr
#define WiprMotErrSafe                                                        WMMLin1Fr01.wmmlin1fr01.WiprMotErrSafe
#define ErrRespWMM                                                            WMMLin1Fr01.wmmlin1fr01.ErrRespWMM
#define WiprMotHiVoltDetd                                                     WMMLin1Fr01.wmmlin1fr01.WiprMotHiVoltDetd
#define WiprMotLoVoltDetd                                                     WMMLin1Fr01.wmmlin1fr01.WiprMotLoVoltDetd
#define WiprMotOvldDetd                                                       WMMLin1Fr01.wmmlin1fr01.WiprMotOvldDetd
#define WshngCycActv                                                          WMMLin1Fr01.wmmlin1fr01.WshngCycActv
#define WiprMotCrkAg                                                          WMMLin1Fr01.wmmlin1fr01.WiprMotCrkAg
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
#define l_u16_rd_LIN_rw_VILO_ICALLO_GHI_ASIC_g()                              (canuint16)(LIN_rw_VILO_ICALLO_GHI_ASIC_g_0)\
                                                                                | ((canuint16)(LIN_rw_VILO_ICALLO_GHI_ASIC_g_1)<<2)
#define l_u16_wr_LIN_rw_VILO_ICALLO_GHI_ASIC_g(a)                             {LIN_rw_VILO_ICALLO_GHI_ASIC_g_0 = ((canuint8)a);\
                                                                                 LIN_rw_VILO_ICALLO_GHI_ASIC_g_1 = ((canuint8)(a>>2));}
#define l_u16_wr_LW_rw_VILO_ICALLO_GHI_ASIC_g(a)                             {LIN_rw_VILO_ICALLO_GHI_ASIC_g_0 = ((canuint8)a);\
                                                                                 LIN_rw_VILO_ICALLO_GHI_ASIC_g_1 = ((canuint8)(a>>2));}
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
#define l_u16_wr_LIN_rw_INREC_ASIC_g(a)                                       {LIN_rw_INREC_ASIC_g_0 = ((canuint8)a);\
                                                                                 LIN_rw_INREC_ASIC_g_1 = ((canuint8)(a>>2));}
#define l_u8_rd_L_Err_State_Light_Sens()                                    L_Err_State_Light_Sens
#define l_u8_wr_L_Err_State_Light_Sens(a)                                   {L_Err_State_Light_Sens = a;}
#define l_u8_rd_L_Light_Switch_Request()                                    L_Light_Switch_Request
#define l_u8_wr_L_Light_Switch_Request(a)                                   {L_Light_Switch_Request = a;}
#define l_u8_rd_L_Status_Light_Sens()                                       L_Status_Light_Sens
#define l_u8_wr_L_Status_Light_Sens(a)                                      {L_Status_Light_Sens = a;}
#define l_u8_rd_L_Err_State_Coding()                                        L_Err_State_Coding
#define l_u8_wr_L_Err_State_Coding(a)                                       {L_Err_State_Coding = a;}
#define l_u8_rd_L_Light_Switch_Reason()                                     L_Light_Switch_Reason
#define l_u8_wr_L_Light_Switch_Reason(a)                                    {L_Light_Switch_Reason = a;}
#define l_u8_rd_L_Light_HudBrightnessValue()                                L_Light_HudBrightnessValue
#define l_u8_wr_L_Light_HudBrightnessValue(a)                               {L_Light_HudBrightnessValue = a;}
#define l_u8_rd_L_Light_HudBrightnessUnit()                                 L_Light_HudBrightnessUnit
#define l_u8_wr_L_Light_HudBrightnessUnit(a)                                {L_Light_HudBrightnessUnit = a;}
#define l_u8_rd_L_Err_State_Over_Volt()                                     L_Err_State_Over_Volt
#define l_u8_wr_L_Err_State_Over_Volt(a)                                    {L_Err_State_Over_Volt = a;}
#define l_u8_rd_L_Err_State_Over_Temp()                                     L_Err_State_Over_Temp
#define l_u8_wr_L_Err_State_Over_Temp(a)                                    {L_Err_State_Over_Temp = a;}
#define l_u8_rd_L_RH_Sens()                                                 L_RH_Sens
#define l_u8_wr_L_RH_Sens(a)                                                {L_RH_Sens = a;}
#define l_u16_rd_L_Window_Temp()                                              ((canuint16)(L_Window_Temp_0)\
                                                                                | ((canuint16)(L_Window_Temp_1)<<8))
#define l_u16_wr_L_Window_Temp(a)                                             {L_Window_Temp_0 = ((canuint8)a);\
                                                                                 L_Window_Temp_1 = ((canuint8)a>>8);}
#define l_u16_rd_L_DP_Temp()                                                  ((canuint16)(L_DP_Temp_0)\
                                                                                | ((canuint16)(L_DP_Temp_1)<<5))
#define l_u16_wr_L_DP_Temp(a)                                                 {L_DP_Temp_0 = (0x1f & a);\
                                                                                 L_DP_Temp_1 = ((a>>5) & 0x3f);}
#define l_bool_rd_L_Err_State_Humidity_Sens()                                   L_Err_State_Humidity_Sens
#define l_bool_wr_L_Err_State_Humidity_Sens(a)                                  {L_Err_State_Humidity_Sens = a;}
#define l_u8_rd_L_RS_RainfallLevel()                                        L_RS_RainfallLevel
#define l_u8_wr_L_RS_RainfallLevel(a)                                       {L_RS_RainfallLevel = a;}
#define l_u8_rd_L_RS_WiperAutoSpReq()                                       L_RS_WiperAutoSpReq
#define l_u8_wr_L_RS_WiperAutoSpReq(a)                                      {L_RS_WiperAutoSpReq = a;}
#define l_u8_rd_L_Err_State_Cal_RS()                                        L_Err_State_Cal_RS
#define l_u8_wr_L_Err_State_Cal_RS(a)                                       {L_Err_State_Cal_RS = a;}
#define l_bool_rd_L_RS_RainSensorError()                                        L_RS_RainSensorError
#define l_bool_wr_L_RS_RainSensorError(a)                                       {L_RS_RainSensorError = a;}
#define l_bool_rd_RS_Sensor_01_LIN_Response_Error()                             RS_Sensor_01_LIN_Response_Error
#define l_bool_wr_RS_Sensor_01_LIN_Response_Error(a)                            {RS_Sensor_01_LIN_Response_Error = a;}
#define l_u8_rd_L_Status_Rain_Sens()                                        L_Status_Rain_Sens
#define l_u8_wr_L_Status_Rain_Sens(a)                                       {L_Status_Rain_Sens = a;}
#define l_u8_rd_L_Sunroof_Win_CloseReq()                                    L_Sunroof_Win_CloseReq
#define l_u8_wr_L_Sunroof_Win_CloseReq(a)                                   {L_Sunroof_Win_CloseReq = a;}
#define l_bool_rd_L_RLS_ModeSts()                                               L_RLS_ModeSts
#define l_bool_wr_L_RLS_ModeSts(a)                                              {L_RLS_ModeSts = a;}
#define l_bool_rd_L_RS_SolarSensorError()                                       L_RS_SolarSensorError
#define l_bool_wr_L_RS_SolarSensorError(a)                                      {L_RS_SolarSensorError = a;}
#define l_u8_rd_L_Signal_Error()                                            L_Signal_Error
#define l_u8_wr_L_Signal_Error(a)                                           {L_Signal_Error = a;}
#define l_u8_rd_L_Value_Solar_Right_Sens()                                  L_Value_Solar_Right_Sens
#define l_u8_wr_L_Value_Solar_Right_Sens(a)                                 {L_Value_Solar_Right_Sens = a;}
#define l_u8_rd_L_Value_Solar_Left_Sens()                                   L_Value_Solar_Left_Sens
#define l_u8_wr_L_Value_Solar_Left_Sens(a)                                  {L_Value_Solar_Left_Sens = a;}
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
#define l_u8_rd_L_EMS_EngStatus()                                           L_EMS_EngStatus
#define l_u8_wr_L_EMS_EngStatus(a)                                          {L_EMS_EngStatus = a;}
#define l_bool_rd_L_BCM_RS_ManWaInfo()                                          L_BCM_RS_ManWaInfo
#define l_bool_wr_L_BCM_RS_ManWaInfo(a)                                         {L_BCM_RS_ManWaInfo = a;}
#define l_bool_rd_WiprPosnForSrvReq()                                           WiprPosnForSrvReq
#define l_bool_wr_WiprPosnForSrvReq(a)                                          {WiprPosnForSrvReq = a;}
#define l_u8_rd_L_BCM_RS_RainSwSts()                                        L_BCM_RS_RainSwSts
#define l_u8_wr_L_BCM_RS_RainSwSts(a)                                       {L_BCM_RS_RainSwSts = a;}
#define l_u8_rd_L_RLS_ModeEnable()                                          L_RLS_ModeEnable
#define l_u8_wr_L_RLS_ModeEnable(a)                                         {L_RLS_ModeEnable = a;}
#define l_u8_rd_L_All_Wdw_Closed()                                          L_All_Wdw_Closed
#define l_u8_wr_L_All_Wdw_Closed(a)                                         {L_All_Wdw_Closed = a;}
#define l_u8_rd_L_PEPS_PowerModeValidity()                                  L_PEPS_PowerModeValidity
#define l_u8_wr_L_PEPS_PowerModeValidity(a)                                 {L_PEPS_PowerModeValidity = a;}
#define l_u8_rd_L_PEPS_PowerMode1()                                         L_PEPS_PowerMode1
#define l_u8_wr_L_PEPS_PowerMode1(a)                                        {L_PEPS_PowerMode1 = a;}
#define l_bool_rd_L_VCU_ePTReady()                                              L_VCU_ePTReady
#define l_bool_wr_L_VCU_ePTReady(a)                                             {L_VCU_ePTReady = a;}
#define l_bool_rd_L_VCU_StartActive()                                           L_VCU_StartActive
#define l_bool_wr_L_VCU_StartActive(a)                                          {L_VCU_StartActive = a;}
#define l_u16_rd_L_BCM_VehicleSpeed()                                         ((canuint16)(L_BCM_VehicleSpeed_0)\
                                                                                | ((canuint16)(L_BCM_VehicleSpeed_1)<<5))
#define l_u16_wr_L_BCM_VehicleSpeed(a)                                        {L_BCM_VehicleSpeed_0 = ((canuint8)a);\
                                                                                 L_BCM_VehicleSpeed_1 = ((canuint8)a>>5);}
#define l_u8_rd_L_BCM_OutdoorTemp()                                         L_BCM_OutdoorTemp
#define l_u8_wr_L_BCM_OutdoorTemp(a)                                        {L_BCM_OutdoorTemp = a;}
#define l_u8_rd_WiprMotFrntOffsAg()                                         WiprMotFrntOffsAg
#define l_u8_wr_WiprMotFrntOffsAg(a)                                        {WiprMotFrntOffsAg = a;}
#define l_u8_rd_L_Rain_Sensitivity()                                        L_Rain_Sensitivity
#define l_u8_wr_L_Rain_Sensitivity(a)                                       {L_Rain_Sensitivity = a;}
#define l_bool_rd_WiprActv()                                                    WiprActv
#define l_bool_wr_WiprActv(a)                                                   {WiprActv = a;}
#define l_bool_rd_WiprInPrkgPosnLo()                                            WiprInPrkgPosnLo
#define l_bool_wr_WiprInPrkgPosnLo(a)                                           {WiprInPrkgPosnLo = a;}
#define l_bool_rd_WiprInWipgAr()                                                WiprInWipgAr
#define l_bool_wr_WiprInWipgAr(a)                                               {WiprInWipgAr = a;}
#define l_u8_rd_WiprMotErrSafe()                                            WiprMotErrSafe
#define l_u8_wr_WiprMotErrSafe(a)                                           {WiprMotErrSafe = a;}
#define l_bool_rd_ErrRespWMM()                                                  ErrRespWMM
#define l_bool_wr_ErrRespWMM(a)                                                 {ErrRespWMM = a;}
#define l_u8_rd_WiprMotHiVoltDetd()                                         WiprMotHiVoltDetd
#define l_u8_wr_WiprMotHiVoltDetd(a)                                        {WiprMotHiVoltDetd = a;}
#define l_u8_rd_WiprMotLoVoltDetd()                                         WiprMotLoVoltDetd
#define l_u8_wr_WiprMotLoVoltDetd(a)                                        {WiprMotLoVoltDetd = a;}
#define l_u8_rd_WiprMotOvldDetd()                                           WiprMotOvldDetd
#define l_u8_wr_WiprMotOvldDetd(a)                                          {WiprMotOvldDetd = a;}
#define l_bool_rd_WshngCycActv()                                                WshngCycActv
#define l_bool_wr_WshngCycActv(a)                                               {WshngCycActv = a;}
#define l_u8_rd_WiprMotCrkAg()                                              WiprMotCrkAg
#define l_u8_wr_WiprMotCrkAg(a)                                             {WiprMotCrkAg = a;}


#endif  /* I_LIN_RLS_H */
