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

#define cb_HANDLE_LinRespCmd_g              0
#define cb_HANDLE_ASIC_Frame_04_g           1
#define cb_HANDLE_ASIC_Frame_03_g           2
#define cb_HANDLE_ASIC_Frame_02_g           3
#define cb_HANDLE_ASIC_Frame_01_g           4
#define cb_HANDLE_FSs_01_g                   5 /*cb_HANDLE_FSdata*/
#define cb_HANDLE_SoSes_01                6 /*cb_HANDLE_SoSe*/
#define cb_HANDLE_FSdataEnhanced_g              7 /*cb_HANDLE_LsRLS_light*/
#define cb_HANDLE_RLSs_01_g               8 /* cb_HANDLE_LsRLS_data */
#define cb_HANDLE_LinReqCmd_g               9
#define cb_HANDLE_WWSs_01_g               10 /* cb_HANDLE_WWECU_data */
#define cb_HANDLE_BCM1_LIN1_01_g          11 /*cb_HANDLE_LightECU_Config*/

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
  canbittype                               GLASS_TEMP: 8;
  canbittype                          HumidityAirTemp: 8;
  canbittype                             DewpointTemp: 8;
  canbittype                             REL_HUMIDITY: 8;
  canbittype                           RsErr_HumSense: 1;
  canbittype                          Hum_Sns_Int_flt: 1;
  canbittype                               Reserved_4: 3;
  canbittype                                  unused0: 3;
} _c_FSdata_msgType;

typedef struct {
  canbittype                        SoSe_SunInt_2D_Li: 8;
  canbittype                        SoSe_SunInt_2D_Re: 8;
  canbittype                             Reserved_1_0: 8;
  canbittype                             Reserved_1_1: 8;
  canbittype                             Reserved_2_0: 8;
  canbittype                             Reserved_2_1: 8;
  canbittype                             Reserved_3_0: 8;
  canbittype                             Reserved_3_1: 8;
} _c_SoSe_msgType;

typedef struct {
  canbittype                          Helligkeit_IR_0: 8;
  canbittype                          Helligkeit_IR_1: 3;
  canbittype                          Helligkeit_FW_0: 5;
  canbittype                          Helligkeit_FW_1: 6;
  canbittype                                  unused0: 2;
} _c_LsRLS_light_msgType;

typedef struct {
  canbittype                       RLS_MessageCounter: 3;
  canbittype                             Twilight_RLS: 1;
  canbittype                               WiperSpeed: 2;
  canbittype                            HeadLights_on: 1;
  canbittype                               RS_Schwall: 1;
  canbittype                      AmbientBrightness_0: 8;
  canbittype                      AmbientBrightness_1: 3;
  canbittype                               RLS_status: 2;
  canbittype                                   RS_Err: 1;
  canbittype                                   LS_Err: 1;
  canbittype                        RLS_Communication: 1;
} _c_LsRLS_data_msgType;


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
  canbittype                             WiperRunning: 1;
  canbittype                           ParkingContact: 1;
  canbittype                               Reserved_5: 1;
  canbittype                            SCS_Automatic: 1;
  canbittype                            SCS_Int_level: 3;
  canbittype                        SCS_FrontWishWash: 1;
  canbittype                             SCS_LowSpeed: 1;
  canbittype                            SCS_HighSpeed: 1;
  canbittype                                  unused0: 6;
} _c_WWECU_data_msgType;

typedef struct {
  canbittype                  LightECU_MessageCounter: 3;
  canbittype                           LS_Sensitivity: 3;
  canbittype                                 Ignition: 1;
  canbittype                               Use_Config: 1;
  canbittype                             VehicleSpeed: 8;
  canbittype                     WindshielTransm880nm: 4;
  canbittype                     WindshielTransm550nm: 4;
} _c_LightECU_Config_msgType;


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
    unsigned char _c[5];
    _c_FSdata_msgType fsdata;
} _c_FSdata_buf;

typedef union {
    unsigned char _c[8];
    _c_SoSe_msgType sose;
} _c_SoSe_buf;

typedef union {
    unsigned char _c[3];
    _c_LsRLS_light_msgType lsrls_light;
} _c_LsRLS_light_buf;

typedef union {
    unsigned char _c[3];
    _c_LsRLS_data_msgType lsrls_data;
} _c_LsRLS_data_buf;


/* Receive messages */

typedef union {
    unsigned char _c[8];
    _c_LinReqCmd_msgType linreqcmd;
} _c_LinReqCmd_buf;

typedef union {
    unsigned char _c[2];
    _c_WWECU_data_msgType wwecu_data;
} _c_WWECU_data_buf;

typedef union {
    unsigned char _c[3];
    _c_LightECU_Config_msgType lightecu_config;
} _c_LightECU_Config_buf;


/******************************************************************************/
/*                          Databuffer for send objects                       */
/******************************************************************************/

extern MEMORY_FAR _c_LinRespCmd_buf LinRespCmd;
extern MEMORY_FAR _c_ASIC_Frame_04_buf ASIC_Frame_04;
extern MEMORY_FAR _c_ASIC_Frame_03_buf ASIC_Frame_03;
extern MEMORY_FAR _c_ASIC_Frame_02_buf ASIC_Frame_02;
extern MEMORY_FAR _c_ASIC_Frame_01_buf ASIC_Frame_01;
extern MEMORY_FAR _c_FSdata_buf FSdata;
extern MEMORY_FAR _c_SoSe_buf SoSe;
extern MEMORY_FAR _c_LsRLS_light_buf LsRLS_light;
extern MEMORY_FAR _c_LsRLS_data_buf LsRLS_data;

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
#define FSdata_conf_b             uLinConfirmationFlags.w[0].b5
#define l_flg_tst_FSdata()       (FSdata_conf_b != 0)
#define l_flg_clr_FSdata()       {FSdata_conf_b = 0;}
#define SoSe_conf_b             uLinConfirmationFlags.w[0].b6
#define l_flg_tst_SoSe()       (SoSe_conf_b != 0)
#define l_flg_clr_SoSe()       {SoSe_conf_b = 0;}
#define LsRLS_light_conf_b             uLinConfirmationFlags.w[0].b7
#define l_flg_tst_LsRLS_light()       (LsRLS_light_conf_b != 0)
#define l_flg_clr_LsRLS_light()       {LsRLS_light_conf_b = 0;}
#define LsRLS_data_conf_b             uLinConfirmationFlags.w[0].b8
#define l_flg_tst_LsRLS_data()       (LsRLS_data_conf_b != 0)
#define l_flg_clr_LsRLS_data()       {LsRLS_data_conf_b = 0;}

/******************************************************************************/
/*                         Databuffer for receive objects                     */
/******************************************************************************/

extern MEMORY_FAR _c_LinReqCmd_buf LinReqCmd;
extern MEMORY_FAR _c_WWECU_data_buf WWECU_data;
extern MEMORY_FAR _c_LightECU_Config_buf LightECU_Config;

/******************************************************************************/
/*                          Databuffer for indicationflags                    */
/******************************************************************************/

#define LinReqCmd_ind_b             uLinIndicationFlags.w[0].b0
#define l_flg_tst_LinReqCmd()       (LinReqCmd_ind_b != 0)
#define l_flg_clr_LinReqCmd()       {LinReqCmd_ind_b = 0;}
#define WWECU_data_ind_b             uLinIndicationFlags.w[0].b1
#define l_flg_tst_WWECU_data()       (WWECU_data_ind_b != 0)
#define l_flg_clr_WWECU_data()       {WWECU_data_ind_b = 0;}
#define LightECU_Config_ind_b             uLinIndicationFlags.w[0].b2
#define l_flg_tst_LightECU_Config()       (LightECU_Config_ind_b != 0)
#define l_flg_clr_LightECU_Config()       {LightECU_Config_ind_b = 0;}

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
#define GLASS_TEMP                                                            FSdata.fsdata.GLASS_TEMP
#define HumidityAirTemp                                                       FSdata.fsdata.HumidityAirTemp
#define DewpointTemp                                                          FSdata.fsdata.DewpointTemp
#define REL_HUMIDITY                                                          FSdata.fsdata.REL_HUMIDITY
#define RsErr_HumSense                                                        FSdata.fsdata.RsErr_HumSense
#define Hum_Sns_Int_flt                                                       FSdata.fsdata.Hum_Sns_Int_flt
#define Reserved_4                                                            FSdata.fsdata.Reserved_4
#define SoSe_SunInt_2D_Li                                                     SoSe.sose.SoSe_SunInt_2D_Li
#define SoSe_SunInt_2D_Re                                                     SoSe.sose.SoSe_SunInt_2D_Re
#define Reserved_1_0                                                          SoSe.sose.Reserved_1_0
#define Reserved_1_1                                                          SoSe.sose.Reserved_1_1
#define Reserved_1(c)                                                         { Reserved_1_0= (uint8)(((uint16)(c) & 0xFF));\
                                                                                Reserved_1_1= (uint8)(((uint16)(c) & 0xFF) >> 8);\
                                                                              }
#define Reserved_2_0                                                          SoSe.sose.Reserved_2_0
#define Reserved_2_1                                                          SoSe.sose.Reserved_2_1
#define Reserved_2(c)                                                         { Reserved_2_0= (uint8)(((uint16)(c) & 0xFF));\
                                                                                Reserved_2_1= (uint8)(((uint16)(c) & 0xFF) >> 8);\
                                                                              }
#define Reserved_3_0                                                          SoSe.sose.Reserved_3_0
#define Reserved_3_1                                                          SoSe.sose.Reserved_3_1
#define Reserved_3(c)                                                         { Reserved_3_0= (uint8)(((uint16)(c) & 0xFF));\
                                                                                Reserved_3_1= (uint8)(((uint16)(c) & 0xFF) >> 8);\
                                                                              }
#define Helligkeit_IR_0                                                       LsRLS_light.lsrls_light.Helligkeit_IR_0
#define Helligkeit_IR_1                                                       LsRLS_light.lsrls_light.Helligkeit_IR_1
#define Helligkeit_IR(c)                                                      { Helligkeit_IR_0= (uint8)(((uint16)(c) & 0xFF));\
                                                                                Helligkeit_IR_1= (uint8)(((uint16)(c) & 0x07) >> 8);\
                                                                              }
#define Helligkeit_FW_0                                                       LsRLS_light.lsrls_light.Helligkeit_FW_0
#define Helligkeit_FW_1                                                       LsRLS_light.lsrls_light.Helligkeit_FW_1
#define Helligkeit_FW(c)                                                      { Helligkeit_FW_0= (uint8)(((uint16)(c) & 0x1F));\
                                                                                Helligkeit_FW_1= (uint8)(((uint16)(c) & 0x3F) >> 5);\
                                                                              }
#define RLS_MessageCounter                                                    LsRLS_data.lsrls_data.RLS_MessageCounter
#define Twilight_RLS                                                          LsRLS_data.lsrls_data.Twilight_RLS
#define WiperSpeed                                                            LsRLS_data.lsrls_data.WiperSpeed
#define HeadLights_on                                                         LsRLS_data.lsrls_data.HeadLights_on
#define RS_Schwall                                                            LsRLS_data.lsrls_data.RS_Schwall
#define AmbientBrightness_0                                                   LsRLS_data.lsrls_data.AmbientBrightness_0
#define AmbientBrightness_1                                                   LsRLS_data.lsrls_data.AmbientBrightness_1
#define AmbientBrightness(c)                                                  { AmbientBrightness_0= (uint8)(((uint16)(c) & 0xFF));\
                                                                                AmbientBrightness_1= (uint8)(((uint16)(c) & 0x07) >> 8);\
                                                                              }
#define RLS_status                                                            LsRLS_data.lsrls_data.RLS_status
#define RS_Err                                                                LsRLS_data.lsrls_data.RS_Err
#define LS_Err                                                                LsRLS_data.lsrls_data.LS_Err
#define RLS_Communication                                                     LsRLS_data.lsrls_data.RLS_Communication
#define MasterReqB0                                                           LinReqCmd.linreqcmd.MasterReqB0
#define MasterReqB1                                                           LinReqCmd.linreqcmd.MasterReqB1
#define MasterReqB2                                                           LinReqCmd.linreqcmd.MasterReqB2
#define MasterReqB3                                                           LinReqCmd.linreqcmd.MasterReqB3
#define MasterReqB4                                                           LinReqCmd.linreqcmd.MasterReqB4
#define MasterReqB5                                                           LinReqCmd.linreqcmd.MasterReqB5
#define MasterReqB6                                                           LinReqCmd.linreqcmd.MasterReqB6
#define MasterReqB7                                                           LinReqCmd.linreqcmd.MasterReqB7
#define WiperRunning                                                          WWECU_data.wwecu_data.WiperRunning
#define ParkingContact                                                        WWECU_data.wwecu_data.ParkingContact
#define Reserved_5                                                            WWECU_data.wwecu_data.Reserved_5
#define SCS_Automatic                                                         WWECU_data.wwecu_data.SCS_Automatic
#define SCS_Int_level                                                         WWECU_data.wwecu_data.SCS_Int_level
#define SCS_FrontWishWash                                                     WWECU_data.wwecu_data.SCS_FrontWishWash
#define SCS_LowSpeed                                                          WWECU_data.wwecu_data.SCS_LowSpeed
#define SCS_HighSpeed                                                         WWECU_data.wwecu_data.SCS_HighSpeed
#define LightECU_MessageCounter                                               LightECU_Config.lightecu_config.LightECU_MessageCounter
#define LS_Sensitivity                                                        LightECU_Config.lightecu_config.LS_Sensitivity
#define Ignition                                                              LightECU_Config.lightecu_config.Ignition
#define Use_Config                                                            LightECU_Config.lightecu_config.Use_Config
#define VehicleSpeed                                                          LightECU_Config.lightecu_config.VehicleSpeed
#define WindshielTransm880nm                                                  LightECU_Config.lightecu_config.WindshielTransm880nm
#define WindshielTransm550nm                                                  LightECU_Config.lightecu_config.WindshielTransm550nm
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
#define l_u16_wr_LIN_rw_Vref_ASIC_g(a)                                        {LIN_rw_Vref_ASIC_g_0 = ((canuint8)(a));\
                                                                                 LIN_rw_Vref_ASIC_g_1 = ((canuint8)((a)>>8));}
#define l_u16_rd_LIN_rw_VDDA_ASIC_g()                                         (canuint16)(LIN_rw_VDDA_ASIC_g_0)\
                                                                                | ((canuint16)(LIN_rw_VDDA_ASIC_g_1)<<6)
#define l_u16_wr_LIN_rw_VDDA_ASIC_g(a)                                        {LIN_rw_VDDA_ASIC_g_0 = ((canuint8)((a) & 0x3F));\
                                                                                 LIN_rw_VDDA_ASIC_g_1 = ((canuint8)((a)>>6));}
#define l_u16_rd_LIN_rw_VDDD_ASIC_g()                                         (canuint16)(LIN_rw_VDDD_ASIC_g_0)\
                                                                                | ((canuint16)(LIN_rw_VDDD_ASIC_g_1)<<4)
#define l_u16_wr_LIN_rw_VDDD_ASIC_g(a)                                        {LIN_rw_VDDD_ASIC_g_0 = ((canuint8)((a) & 0x0F));\
                                                                                 LIN_rw_VDDD_ASIC_g_1 = ((canuint8)((a)>>4));}
#define l_u16_rd_LW_rw_VILO_ICALLO_GHI_ASIC_g()                               (canuint16)(LW_rw_VILO_ICALLO_GHI_ASIC_g_0)\
                                                                                | ((canuint16)(LW_rw_VILO_ICALLO_GHI_ASIC_g_1)<<2)
#define l_u16_wr_LW_rw_VILO_ICALLO_GHI_ASIC_g(a)                              {LW_rw_VILO_ICALLO_GHI_ASIC_g_0 = ((canuint8)(a));\
                                                                                 LW_rw_VILO_ICALLO_GHI_ASIC_g_1 = ((canuint8)((a)>>2));}
#define l_u16_rd_LIN_rw_REGV_Voltage_g()                                      (canuint16)(LIN_rw_REGV_Voltage_g_0)\
                                                                                | ((canuint16)(LIN_rw_REGV_Voltage_g_1)<<8)
#define l_u16_wr_LIN_rw_REGV_Voltage_g(a)                                     {LIN_rw_REGV_Voltage_g_0 = ((canuint8)(a));\
                                                                                 LIN_rw_REGV_Voltage_g_1 = ((canuint8)((a)>>8));}
#define l_u8_rd_LIN_rb_ASICReg_NoValidVals_cnt_g()                          LIN_rb_ASICReg_NoValidVals_cnt_g
#define l_u8_wr_LIN_rb_ASICReg_NoValidVals_cnt_g(a)                         {LIN_rb_ASICReg_NoValidVals_cnt_g = (a);}
#define l_u16_rd_LIN_rw_Solar_light16bit_1_g()                                (canuint16)(LIN_rw_Solar_light16bit_1_g_0)\
                                                                                | ((canuint16)(LIN_rw_Solar_light16bit_1_g_1)<<8)
#define l_u16_wr_LIN_rw_Solar_light16bit_1_g(a)                               {LIN_rw_Solar_light16bit_1_g_0 = ((canuint8)(a));\
                                                                                 LIN_rw_Solar_light16bit_1_g_1 = ((canuint8)((a)>>8));}
#define l_u16_rd_LIN_rw_Solar_light16bit_2_g()                                (canuint16)(LIN_rw_Solar_light16bit_2_g_0)\
                                                                                | ((canuint16)(LIN_rw_Solar_light16bit_2_g_1)<<8)
#define l_u16_wr_LIN_rw_Solar_light16bit_2_g(a)                               {LIN_rw_Solar_light16bit_2_g_0 = ((canuint8)(a));\
                                                                                 LIN_rw_Solar_light16bit_2_g_1 = ((canuint8)((a)>>8));}
#define l_u16_rd_LIN_rw_FW_light16bit_g()                                     (canuint16)(LIN_rw_FW_light16bit_g_0)\
                                                                                | ((canuint16)(LIN_rw_FW_light16bit_g_1)<<8)
#define l_u16_wr_LIN_rw_FW_light16bit_g(a)                                    {LIN_rw_FW_light16bit_g_0 = ((canuint8)(a));\
                                                                                 LIN_rw_FW_light16bit_g_1 = ((canuint8)((a)>>8));}
#define l_u16_rd_LIN_rw_IR_light16bit_g()                                     (canuint16)(LIN_rw_IR_light16bit_g_0)\
                                                                                | ((canuint16)(LIN_rw_IR_light16bit_g_1)<<8)
#define l_u16_wr_LIN_rw_IR_light16bit_g(a)                                    {LIN_rw_IR_light16bit_g_0 = ((canuint8)(a));\
                                                                                 LIN_rw_IR_light16bit_g_1 = ((canuint8)((a)>>8));}
#define l_u16_rd_LIN_rw_INTV10bit_max_g()                                     (canuint16)(LIN_rw_INTV10bit_max_g_0)\
                                                                                | ((canuint16)(LIN_rw_INTV10bit_max_g_1)<<8)
#define l_u16_wr_LIN_rw_INTV10bit_max_g(a)                                    {LIN_rw_INTV10bit_max_g_0 = ((canuint8)(a));\
                                                                                 LIN_rw_INTV10bit_max_g_1 = ((canuint8)((a)>>8));}


#define l_u16_rd_LIN_rw_INTV10bit_min_g()                                     (canuint16)(LIN_rw_INTV10bit_min_g_0)\
                                                                                | ((canuint16)(LIN_rw_INTV10bit_min_g_1)<<6)
#define l_u16_wr_LIN_rw_INTV10bit_min_g(a)                                    {LIN_rw_INTV10bit_min_g_0 = ((canuint8)((a) & 0x3F));\
                                                                                 LIN_rw_INTV10bit_min_g_1 = ((canuint8)((a)>>6));}
#define l_u16_rd_LIN_rw_VICALLO_ILO_GHI_ASIC_g()                              (canuint16)(LIN_rw_VICALLO_ILO_GHI_ASIC_g_0)\
                                                                                | ((canuint16)(LIN_rw_VICALLO_ILO_GHI_ASIC_g_1)<<4)
#define l_u16_wr_LIN_rw_VICALLO_ILO_GHI_ASIC_g(a)                             {LIN_rw_VICALLO_ILO_GHI_ASIC_g_0 = ((canuint8)((a) & 0x0F));\
                                                                                 LIN_rw_VICALLO_ILO_GHI_ASIC_g_1 = ((canuint8)((a)>>4));}
#define l_u16_rd_LIN_rw_VTEMP_ASIC_g()                                        (canuint16)(LIN_rw_VTEMP_ASIC_g_0)\
                                                                                | ((canuint16)(LIN_rw_VTEMP_ASIC_g_1)<<2)
#define l_u16_wr_LIN_rw_VTEMP_ASIC_g(a)                                       {LIN_rw_VTEMP_ASIC_g_0 = ((canuint8)((a) & 0x03));\
                                                                                 LIN_rw_VTEMP_ASIC_g_1 = ((canuint8)((a)>>2));}
#define l_u8_rd_LIN_rb_SPI_Active_ProblemCounter_g()                        LIN_rb_SPI_Active_ProblemCounter_g
#define l_u8_wr_LIN_rb_SPI_Active_ProblemCounter_g(a)                       {LIN_rb_SPI_Active_ProblemCounter_g = (a);}
#define l_u8_rd_LIN_rb_StaticHumTempErrorCounter_g()                        LIN_rb_StaticHumTempErrorCounter_g
#define l_u8_wr_LIN_rb_StaticHumTempErrorCounter_g(a)                       {LIN_rb_StaticHumTempErrorCounter_g = (a);}
#define l_u8_rd_LIN_rb_STATH_Reg_g()                                        LIN_rb_STATH_Reg_g
#define l_u8_wr_LIN_rb_STATH_Reg_g(a)                                       {LIN_rb_STATH_Reg_g = (a);}
#define l_u8_rd_LIN_rb_SupplyVoltage_mg()                                   LIN_rb_SupplyVoltage_mg
#define l_u8_wr_LIN_rb_SupplyVoltage_mg(a)                                  {LIN_rb_SupplyVoltage_mg = (a);}
#define l_u8_rd_LIN_rb_MaxLightSignalErrorCnt_g()                           LIN_rb_MaxLightSignalErrorCnt_g
#define l_u8_wr_LIN_rb_MaxLightSignalErrorCnt_g(a)                          {LIN_rb_MaxLightSignalErrorCnt_g = (a);}
#define l_u8_rd_LIN_rb_StaticNoCommunicationCounter()                       LIN_rb_StaticNoCommunicationCounter
#define l_u8_wr_LIN_rb_StaticNoCommunicationCounter(a)                      {LIN_rb_StaticNoCommunicationCounter = (a);}
#define l_u16_rd_LIN_rw_ALS2_ASIC_g()                                         (canuint16)(LIN_rw_ALS2_ASIC_g_0)\
                                                                                | ((canuint16)(LIN_rw_ALS2_ASIC_g_1)<<8)
#define l_u16_wr_LIN_rw_ALS2_ASIC_g(a)                                        {LIN_rw_ALS2_ASIC_g_0 = ((canuint8)(a));\
                                                                                 LIN_rw_ALS2_ASIC_g_1 = ((canuint8)((a)>>8));}
#define l_u16_rd_LIN_rw_ALS5_ASIC_g()                                         (canuint16)(LIN_rw_ALS5_ASIC_g_0)\
                                                                                | ((canuint16)(LIN_rw_ALS5_ASIC_g_1)<<6)
#define l_u16_wr_LIN_rw_ALS5_ASIC_g(a)                                        {LIN_rw_ALS5_ASIC_g_0 = ((canuint8)((a) & 0x3F));\
                                                                                 LIN_rw_ALS5_ASIC_g_1 = ((canuint8)((a)>>6));}
#define l_u16_rd_LIN_rw_Amb_light16bit_g()                                    (canuint16)(LIN_rw_Amb_light16bit_g_0)\
                                                                                | ((canuint16)(LIN_rw_Amb_light16bit_g_1)<<4)
#define l_u16_wr_LIN_rw_Amb_light16bit_g(a)                                   {LIN_rw_Amb_light16bit_g_0 = ((canuint8)((a) & 0x0F));\
                                                                                 LIN_rw_Amb_light16bit_g_1 = ((canuint8)((a)>>4));}
#define l_u16_rd_LIN_rw_INREC_ASIC_g()                                        (canuint16)(LIN_rw_INREC_ASIC_g_0)\
                                                                                | ((canuint16)(LIN_rw_INREC_ASIC_g_1)<<2)
#define l_u16_wr_LIN_rw_INREC_ASIC_g(a)                                       {LIN_rw_INREC_ASIC_g_0 = ((canuint8)((a) & 0x03));\
                                                                                 LIN_rw_INREC_ASIC_g_1 = ((canuint8)((a)>>2));}
#define l_u8_rd_GLASS_TEMP()                                                GLASS_TEMP
#define l_u8_wr_GLASS_TEMP(a)                                               {GLASS_TEMP = a;}
#define l_u8_rd_HumidityAirTemp()                                           HumidityAirTemp
#define l_u8_wr_HumidityAirTemp(a)                                          {HumidityAirTemp = a;}
#define l_u8_rd_DewpointTemp()                                              DewpointTemp
#define l_u8_wr_DewpointTemp(a)                                             {DewpointTemp = a;}
#define l_u8_rd_REL_HUMIDITY()                                              REL_HUMIDITY
#define l_u8_wr_REL_HUMIDITY(a)                                             {REL_HUMIDITY = a;}
#define l_bool_rd_RsErr_HumSense()                                              RsErr_HumSense
#define l_bool_wr_RsErr_HumSense(a)                                             {RsErr_HumSense = a;}
#define l_bool_rd_Hum_Sns_Int_flt()                                             Hum_Sns_Int_flt
#define l_bool_wr_Hum_Sns_Int_flt(a)                                            {Hum_Sns_Int_flt = a;}
#define l_u8_rd_Reserved_4()                                                Reserved_4
#define l_u8_wr_Reserved_4(a)                                               {Reserved_4 = a;}
#define l_u8_rd_SoSe_SunInt_2D_Li()                                         SoSe_SunInt_2D_Li
#define l_u8_wr_SoSe_SunInt_2D_Li(a)                                        {SoSe_SunInt_2D_Li = a;}
#define l_u8_rd_SoSe_SunInt_2D_Re()                                         SoSe_SunInt_2D_Re
#define l_u8_wr_SoSe_SunInt_2D_Re(a)                                        {SoSe_SunInt_2D_Re = a;}

#define l_u16_rd_Helligkeit_IR()                                              (canuint16)(Helligkeit_IR_0)\
                                                                                | (((canuint16)(Helligkeit_IR_1))<<8)
#define l_u16_wr_Helligkeit_IR(a)                                             {Helligkeit_IR_0 = ((canuint8)a);\
                                                                                 Helligkeit_IR_1 = (((canuint16)a)>>8);}
#define l_u16_rd_Helligkeit_FW()                                              (canuint16)(Helligkeit_FW_0)\
                                                                                | ((canuint16)(Helligkeit_FW_1)<<5)
#define l_u16_wr_Helligkeit_FW(a)                                             {Helligkeit_FW_0 = ((canuint8)((a)& (0x1F)));\
                                                                                 Helligkeit_FW_1 = ((canuint8)(((a)>>5) & 0x3F));}
#define l_u8_rd_RLS_MessageCounter()                                        RLS_MessageCounter
#define l_u8_wr_RLS_MessageCounter(a)                                       {RLS_MessageCounter = a;}
#define l_bool_rd_Twilight_RLS()                                                Twilight_RLS
#define l_bool_wr_Twilight_RLS(a)                                               {Twilight_RLS = a;}
#define l_u8_rd_WiperSpeed()                                                WiperSpeed
#define l_u8_wr_WiperSpeed(a)                                               {WiperSpeed = a;}
#define l_bool_rd_HeadLights_on()                                               HeadLights_on
#define l_bool_wr_HeadLights_on(a)                                              {HeadLights_on = a;}
#define l_bool_rd_RS_Schwall()                                                  RS_Schwall
#define l_bool_wr_RS_Schwall(a)                                                 {RS_Schwall = a;}
#define l_u16_rd_AmbientBrightness()                                          (canuint16)(AmbientBrightness_0)\
                                                                                | ((canuint16)(AmbientBrightness_1)<<8)
#define l_u16_wr_AmbientBrightness(a)                                         {AmbientBrightness_0 = ((canuint8)a);\
                                                                                 AmbientBrightness_1 = ((canuint16)a>>8);}
#define l_u8_rd_RLS_status()                                                RLS_status
#define l_u8_wr_RLS_status(a)                                               {RLS_status = a;}
#define l_bool_rd_RS_Err()                                                      RS_Err
#define l_bool_wr_RS_Err(a)                                                     {RS_Err = a;}
#define l_bool_rd_LS_Err()                                                      LS_Err
#define l_bool_wr_LS_Err(a)                                                     {LS_Err = a;}
#define l_bool_rd_RLS_Communication()                                           RLS_Communication
#define l_bool_wr_RLS_Communication(a)                                          {RLS_Communication = a;}
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
#define l_bool_rd_WiperRunning()                                                WiperRunning
#define l_bool_wr_WiperRunning(a)                                               {WiperRunning = a;}
#define l_bool_rd_ParkingContact()                                              ParkingContact
#define l_bool_wr_ParkingContact(a)                                             {ParkingContact = a;}
#define l_bool_rd_Reserved_5()                                                  Reserved_5
#define l_bool_wr_Reserved_5(a)                                                 {Reserved_5 = a;}
#define l_bool_rd_SCS_Automatic()                                               SCS_Automatic
#define l_bool_wr_SCS_Automatic(a)                                              {SCS_Automatic = a;}
#define l_u8_rd_SCS_Int_level()                                             SCS_Int_level
#define l_u8_wr_SCS_Int_level(a)                                            {SCS_Int_level = a;}
#define l_bool_rd_SCS_FrontWishWash()                                           SCS_FrontWishWash
#define l_bool_wr_SCS_FrontWishWash(a)                                          {SCS_FrontWishWash = a;}
#define l_bool_rd_SCS_LowSpeed()                                                SCS_LowSpeed
#define l_bool_wr_SCS_LowSpeed(a)                                               {SCS_LowSpeed = a;}
#define l_bool_rd_SCS_HighSpeed()                                               SCS_HighSpeed
#define l_bool_wr_SCS_HighSpeed(a)                                              {SCS_HighSpeed = a;}
#define l_u8_rd_LightECU_MessageCounter()                                   LightECU_MessageCounter
#define l_u8_wr_LightECU_MessageCounter(a)                                  {LightECU_MessageCounter = a;}
#define l_u8_rd_LS_Sensitivity()                                            LS_Sensitivity
#define l_u8_wr_LS_Sensitivity(a)                                           {LS_Sensitivity = a;}
#define l_bool_rd_Ignition()                                                    Ignition
#define l_bool_wr_Ignition(a)                                                   {Ignition = a;}
#define l_bool_rd_Use_Config()                                                  Use_Config
#define l_bool_wr_Use_Config(a)                                                 {Use_Config = a;}
#define l_u8_rd_VehicleSpeed()                                              VehicleSpeed
#define l_u8_wr_VehicleSpeed(a)                                             {VehicleSpeed = a;}
#define l_u8_rd_WindshielTransm880nm()                                      WindshielTransm880nm
#define l_u8_wr_WindshielTransm880nm(a)                                     {WindshielTransm880nm = a;}
#define l_u8_rd_WindshielTransm550nm()                                      WindshielTransm550nm
#define l_u8_wr_WindshielTransm550nm(a)                                     {WindshielTransm550nm = a;}


#endif  /* I_LIN_RLS_H */

