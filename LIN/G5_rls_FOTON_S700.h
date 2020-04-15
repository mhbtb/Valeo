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
#define cb_HANDLE_RainSensor              5
#define cb_HANDLE_LinReqCmd               6
#define cb_HANDLE_BCM_Com2                7
#define cb_HANDLE_BCM_Com                 8
   
#define cb_HANDLE_ASIC_Frame_01_g cb_HANDLE_ASIC_Frame_01
#define cb_HANDLE_ASIC_Frame_02_g cb_HANDLE_ASIC_Frame_02
#define cb_HANDLE_ASIC_Frame_03_g cb_HANDLE_ASIC_Frame_03
#define cb_HANDLE_ASIC_Frame_04_g cb_HANDLE_ASIC_Frame_04
#define cb_HANDLE_RLSs_01_g cb_HANDLE_RainSensor
#define cb_HANDLE_BCM1_LIN1_01_g cb_HANDLE_BCM_Com
#define cb_HANDLE_WWSs_01_g cb_HANDLE_BCM_Com2 
#define cb_HANDLE_LinReqCmd_g cb_HANDLE_LinReqCmd
#define cb_HANDLE_LinRespCmd_g cb_HANDLE_LinRespCmd
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
  canbittype                            RS_St_LampReq: 1;
  canbittype                           RS_St_WiperReq: 3;
  canbittype                        RS_St_CurrentRain: 4;
  canbittype                          RS_St_SplashCmd: 1;
  canbittype                         RS_F_LightSensor: 1;
  canbittype                          RS_F_RainSensor: 1;
  canbittype                                  unused0: 1;
  canbittype                             RS_F_Voltage: 2;
  canbittype                                  unused1: 2;
  canbittype                       RS_F_Communication: 1;
  canbittype                                  unused2: 3;
  canbittype                        RS_RollingCounter: 4;
  canbittype                        RS_N_Irbrightness: 8;
} _c_RainSensor_msgType;


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
  canbittype                      BCMLC2_N_GlassPara1: 8;
  canbittype                      BCMLC2_N_GlassPara2: 8;
  canbittype                 BCMLC2_St_LMirrorLevel_0: 8;
  canbittype                 BCMLC2_St_LMirrorLevel_1: 2;
  canbittype                                  unused0: 6;
  canbittype                BCMLC2_St_LMirrorHeight_0: 8;
  canbittype                BCMLC2_St_LMirrorHeight_1: 2;
  canbittype                                  unused1: 6;
  canbittype                    BCMLC2_St_MirSwSStCMD: 2;
  canbittype                    BCMLC2_St_MirSwVStCMD: 2;
  canbittype                    BCMLC2_St_MirSwHStCMD: 2;
  canbittype                                  unused2: 2;
  canbittype                                  unused3: 8;
} _c_BCM_Com2_msgType;

typedef struct {
  canbittype                                  unused0: 4;
  canbittype                             BCMLC_St_KLS: 1;
  canbittype                            BCMLC_St_KL15: 1;
  canbittype                             BCMLC_St_KLR: 1;
  canbittype                            BCMLC_St_KL50: 1;
  canbittype                     BCMLC_N_VehicleSpeed: 6;
  canbittype                         BCMLC_St_GearPos: 2;
  canbittype                           BCMLC_St_Crash: 1;
  canbittype                   BCMLC_St_DriveDoorAjar: 1;
  canbittype                  BCMLC_St_MirrorAutoDecl: 1;
  canbittype                 BCMLC_St_MirrorAdjustSyn: 1;
  canbittype                        BCMLC_N_KeyNumber: 3;
  canbittype                         BCMLC_St_Transit: 1;
  canbittype                 BCMLC_St_EesyEntryEnable: 1;
  canbittype                 BCMLC_St_RKEMemoryEnable: 1;
  canbittype                                  unused1: 1;
  canbittype                          BCMLC_St_BPedal: 1;
  canbittype                           BCMLC_F_BPedal: 1;
  canbittype                   BCMLC_St_LowVoltageReq: 1;
  canbittype                BCMLC_St_UrgentVoltageReq: 1;
  canbittype                                  unused2: 1;
  canbittype                     BCMLC_St_WiperHandle: 3;
  canbittype                 BCMLC_St_WiperSenstivity: 4;
  canbittype                     BCMLC_St_FrontWasher: 1;
  canbittype                      BCMLC_St_ParkSwitch: 2;
  canbittype                    BCMLC_St_NationalCode: 1;
  canbittype                                  unused3: 5;
  canbittype                                  unused4: 8;
  canbittype                     BCMLC_St_VehicleType: 4;
  canbittype                         BCMLC_St_ReadPos: 2;
  canbittype                                  unused5: 2;
} _c_BCM_Com_msgType;


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
    unsigned char _c[4];
    _c_RainSensor_msgType rainsensor;
} _c_RainSensor_buf;


/* Receive messages */

typedef union {
    unsigned char _c[8];
    _c_LinReqCmd_msgType linreqcmd;
} _c_LinReqCmd_buf;

typedef union {
    unsigned char _c[8];
    _c_BCM_Com2_msgType bcm_com2;
} _c_BCM_Com2_buf;

typedef union {
    unsigned char _c[8];
    _c_BCM_Com_msgType bcm_com;
} _c_BCM_Com_buf;


/******************************************************************************/
/*                          Databuffer for send objects                       */
/******************************************************************************/

extern MEMORY_FAR _c_LinRespCmd_buf LinRespCmd;
extern MEMORY_FAR _c_ASIC_Frame_04_buf ASIC_Frame_04;
extern MEMORY_FAR _c_ASIC_Frame_03_buf ASIC_Frame_03;
extern MEMORY_FAR _c_ASIC_Frame_02_buf ASIC_Frame_02;
extern MEMORY_FAR _c_ASIC_Frame_01_buf ASIC_Frame_01;
extern MEMORY_FAR _c_RainSensor_buf RainSensor;

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
#define RainSensor_conf_b             uLinConfirmationFlags.w[0].b5
#define l_flg_tst_RainSensor()       (RainSensor_conf_b != 0)
#define l_flg_clr_RainSensor()       {RainSensor_conf_b = 0;}

/******************************************************************************/
/*                         Databuffer for receive objects                     */
/******************************************************************************/

extern MEMORY_FAR _c_LinReqCmd_buf LinReqCmd;
extern MEMORY_FAR _c_BCM_Com2_buf BCM_Com2;
extern MEMORY_FAR _c_BCM_Com_buf BCM_Com;

/******************************************************************************/
/*                          Databuffer for indicationflags                    */
/******************************************************************************/

#define LinReqCmd_ind_b             uLinIndicationFlags.w[0].b0
#define l_flg_tst_LinReqCmd()       (LinReqCmd_ind_b != 0)
#define l_flg_clr_LinReqCmd()       {LinReqCmd_ind_b = 0;}
#define BCM_Com2_ind_b             uLinIndicationFlags.w[0].b1
#define l_flg_tst_BCM_Com2()       (BCM_Com2_ind_b != 0)
#define l_flg_clr_BCM_Com2()       {BCM_Com2_ind_b = 0;}
#define BCM_Com_ind_b             uLinIndicationFlags.w[0].b2
#define l_flg_tst_BCM_Com()       (BCM_Com_ind_b != 0)
#define l_flg_clr_BCM_Com()       {BCM_Com_ind_b = 0;}

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
#define RS_St_LampReq                                                         RainSensor.rainsensor.RS_St_LampReq
#define RS_St_WiperReq                                                        RainSensor.rainsensor.RS_St_WiperReq
#define RS_St_CurrentRain                                                     RainSensor.rainsensor.RS_St_CurrentRain
#define RS_St_SplashCmd                                                       RainSensor.rainsensor.RS_St_SplashCmd
#define RS_F_LightSensor                                                      RainSensor.rainsensor.RS_F_LightSensor
#define RS_F_RainSensor                                                       RainSensor.rainsensor.RS_F_RainSensor
#define RS_F_Voltage                                                          RainSensor.rainsensor.RS_F_Voltage
#define RS_F_Communication                                                    RainSensor.rainsensor.RS_F_Communication
#define RS_RollingCounter                                                     RainSensor.rainsensor.RS_RollingCounter
#define RS_N_Irbrightness                                                     RainSensor.rainsensor.RS_N_Irbrightness
#define MasterReqB0                                                           LinReqCmd.linreqcmd.MasterReqB0
#define MasterReqB1                                                           LinReqCmd.linreqcmd.MasterReqB1
#define MasterReqB2                                                           LinReqCmd.linreqcmd.MasterReqB2
#define MasterReqB3                                                           LinReqCmd.linreqcmd.MasterReqB3
#define MasterReqB4                                                           LinReqCmd.linreqcmd.MasterReqB4
#define MasterReqB5                                                           LinReqCmd.linreqcmd.MasterReqB5
#define MasterReqB6                                                           LinReqCmd.linreqcmd.MasterReqB6
#define MasterReqB7                                                           LinReqCmd.linreqcmd.MasterReqB7
#define BCMLC2_N_GlassPara1                                                   BCM_Com2.bcm_com2.BCMLC2_N_GlassPara1
#define BCMLC2_N_GlassPara2                                                   BCM_Com2.bcm_com2.BCMLC2_N_GlassPara2
#define BCMLC2_St_LMirrorLevel_0                                              BCM_Com2.bcm_com2.BCMLC2_St_LMirrorLevel_0
#define BCMLC2_St_LMirrorLevel_1                                              BCM_Com2.bcm_com2.BCMLC2_St_LMirrorLevel_1
#define BCMLC2_St_LMirrorLevel(c)                                             { BCMLC2_St_LMirrorLevel_0= (uint8)(((uint16)(c) & 0xFF));\
                                                                                BCMLC2_St_LMirrorLevel_1= (uint8)(((uint16)(c) & 0x03) >> 8);\
                                                                              }
#define BCMLC2_St_LMirrorHeight_0                                             BCM_Com2.bcm_com2.BCMLC2_St_LMirrorHeight_0
#define BCMLC2_St_LMirrorHeight_1                                             BCM_Com2.bcm_com2.BCMLC2_St_LMirrorHeight_1
#define BCMLC2_St_LMirrorHeight(c)                                            { BCMLC2_St_LMirrorHeight_0= (uint8)(((uint16)(c) & 0xFF));\
                                                                                BCMLC2_St_LMirrorHeight_1= (uint8)(((uint16)(c) & 0x03) >> 8);\
                                                                              }
#define BCMLC2_St_MirSwSStCMD                                                 BCM_Com2.bcm_com2.BCMLC2_St_MirSwSStCMD
#define BCMLC2_St_MirSwVStCMD                                                 BCM_Com2.bcm_com2.BCMLC2_St_MirSwVStCMD
#define BCMLC2_St_MirSwHStCMD                                                 BCM_Com2.bcm_com2.BCMLC2_St_MirSwHStCMD
#define BCMLC_St_KLS                                                          BCM_Com.bcm_com.BCMLC_St_KLS
#define BCMLC_St_KL15                                                         BCM_Com.bcm_com.BCMLC_St_KL15
#define BCMLC_St_KLR                                                          BCM_Com.bcm_com.BCMLC_St_KLR
#define BCMLC_St_KL50                                                         BCM_Com.bcm_com.BCMLC_St_KL50
#define BCMLC_N_VehicleSpeed                                                  BCM_Com.bcm_com.BCMLC_N_VehicleSpeed
#define BCMLC_St_GearPos                                                      BCM_Com.bcm_com.BCMLC_St_GearPos
#define BCMLC_St_Crash                                                        BCM_Com.bcm_com.BCMLC_St_Crash
#define BCMLC_St_DriveDoorAjar                                                BCM_Com.bcm_com.BCMLC_St_DriveDoorAjar
#define BCMLC_St_MirrorAutoDecl                                               BCM_Com.bcm_com.BCMLC_St_MirrorAutoDecl
#define BCMLC_St_MirrorAdjustSyn                                              BCM_Com.bcm_com.BCMLC_St_MirrorAdjustSyn
#define BCMLC_N_KeyNumber                                                     BCM_Com.bcm_com.BCMLC_N_KeyNumber
#define BCMLC_St_Transit                                                      BCM_Com.bcm_com.BCMLC_St_Transit
#define BCMLC_St_EesyEntryEnable                                              BCM_Com.bcm_com.BCMLC_St_EesyEntryEnable
#define BCMLC_St_RKEMemoryEnable                                              BCM_Com.bcm_com.BCMLC_St_RKEMemoryEnable
#define BCMLC_St_BPedal                                                       BCM_Com.bcm_com.BCMLC_St_BPedal
#define BCMLC_F_BPedal                                                        BCM_Com.bcm_com.BCMLC_F_BPedal
#define BCMLC_St_LowVoltageReq                                                BCM_Com.bcm_com.BCMLC_St_LowVoltageReq
#define BCMLC_St_UrgentVoltageReq                                             BCM_Com.bcm_com.BCMLC_St_UrgentVoltageReq
#define BCMLC_St_WiperHandle                                                  BCM_Com.bcm_com.BCMLC_St_WiperHandle
#define BCMLC_St_WiperSenstivity                                              BCM_Com.bcm_com.BCMLC_St_WiperSenstivity
#define BCMLC_St_FrontWasher                                                  BCM_Com.bcm_com.BCMLC_St_FrontWasher
#define BCMLC_St_ParkSwitch                                                   BCM_Com.bcm_com.BCMLC_St_ParkSwitch
#define BCMLC_St_NationalCode                                                 BCM_Com.bcm_com.BCMLC_St_NationalCode
#define BCMLC_St_VehicleType                                                  BCM_Com.bcm_com.BCMLC_St_VehicleType
#define BCMLC_St_ReadPos                                                      BCM_Com.bcm_com.BCMLC_St_ReadPos
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
                                                                                 LIN_rw_Vref_ASIC_g_1 = ((canuint8)a>>8);}
#define l_u16_rd_LIN_rw_VDDA_ASIC_g()                                         (canuint16)(LIN_rw_VDDA_ASIC_g_0)\
                                                                                | ((canuint16)(LIN_rw_VDDA_ASIC_g_1)<<6)
#define l_u16_wr_LIN_rw_VDDA_ASIC_g(a)                                        {LIN_rw_VDDA_ASIC_g_0 = ((canuint8)a);\
                                                                                 LIN_rw_VDDA_ASIC_g_1 = ((canuint8)a>>6);}
#define l_u16_rd_LIN_rw_VDDD_ASIC_g()                                         (canuint16)(LIN_rw_VDDD_ASIC_g_0)\
                                                                                | ((canuint16)(LIN_rw_VDDD_ASIC_g_1)<<4)
#define l_u16_wr_LIN_rw_VDDD_ASIC_g(a)                                        {LIN_rw_VDDD_ASIC_g_0 = ((canuint8)a);\
                                                                                 LIN_rw_VDDD_ASIC_g_1 = ((canuint8)a>>4);}
#define l_u16_rd_LW_rw_VILO_ICALLO_GHI_ASIC_g()                               (canuint16)(LW_rw_VILO_ICALLO_GHI_ASIC_g_0)\
                                                                                | ((canuint16)(LW_rw_VILO_ICALLO_GHI_ASIC_g_1)<<2)
#define l_u16_wr_LW_rw_VILO_ICALLO_GHI_ASIC_g(a)                              {LW_rw_VILO_ICALLO_GHI_ASIC_g_0 = ((canuint8)a);\
                                                                                 LW_rw_VILO_ICALLO_GHI_ASIC_g_1 = ((canuint8)a>>2);}
#define l_u16_rd_LIN_rw_REGV_Voltage_g()                                      (canuint16)(LIN_rw_REGV_Voltage_g_0)\
                                                                                | ((canuint16)(LIN_rw_REGV_Voltage_g_1)<<8)
#define l_u16_wr_LIN_rw_REGV_Voltage_g(a)                                     {LIN_rw_REGV_Voltage_g_0 = ((canuint8)a);\
                                                                                 LIN_rw_REGV_Voltage_g_1 = ((canuint8)a>>8);}
#define l_u8_rd_LIN_rb_ASICReg_NoValidVals_cnt_g()                          LIN_rb_ASICReg_NoValidVals_cnt_g
#define l_u8_wr_LIN_rb_ASICReg_NoValidVals_cnt_g(a)                         {LIN_rb_ASICReg_NoValidVals_cnt_g = a;}
#define l_u16_rd_LIN_rw_Solar_light16bit_1_g()                                (canuint16)(LIN_rw_Solar_light16bit_1_g_0)\
                                                                                | ((canuint16)(LIN_rw_Solar_light16bit_1_g_1)<<8)
#define l_u16_wr_LIN_rw_Solar_light16bit_1_g(a)                               {LIN_rw_Solar_light16bit_1_g_0 = ((canuint8)a);\
                                                                                 LIN_rw_Solar_light16bit_1_g_1 = ((canuint8)a>>8);}
#define l_u16_rd_LIN_rw_Solar_light16bit_2_g()                                (canuint16)(LIN_rw_Solar_light16bit_2_g_0)\
                                                                                | ((canuint16)(LIN_rw_Solar_light16bit_2_g_1)<<8)
#define l_u16_wr_LIN_rw_Solar_light16bit_2_g(a)                               {LIN_rw_Solar_light16bit_2_g_0 = ((canuint8)a);\
                                                                                 LIN_rw_Solar_light16bit_2_g_1 = ((canuint8)a>>8);}
#define l_u16_rd_LIN_rw_FW_light16bit_g()                                     (canuint16)(LIN_rw_FW_light16bit_g_0)\
                                                                                | ((canuint16)(LIN_rw_FW_light16bit_g_1)<<8)
#define l_u16_wr_LIN_rw_FW_light16bit_g(a)                                    {LIN_rw_FW_light16bit_g_0 = ((canuint8)a);\
                                                                                 LIN_rw_FW_light16bit_g_1 = ((canuint8)a>>8);}
#define l_u16_rd_LIN_rw_IR_light16bit_g()                                     (canuint16)(LIN_rw_IR_light16bit_g_0)\
                                                                                | ((canuint16)(LIN_rw_IR_light16bit_g_1)<<8)
#define l_u16_wr_LIN_rw_IR_light16bit_g(a)                                    {LIN_rw_IR_light16bit_g_0 = ((canuint8)a);\
                                                                                 LIN_rw_IR_light16bit_g_1 = ((canuint8)a>>8);}
#define l_u16_rd_LIN_rw_INTV10bit_max_g()                                     (canuint16)(LIN_rw_INTV10bit_max_g_0)\
                                                                                | ((canuint16)(LIN_rw_INTV10bit_max_g_1)<<8)
#define l_u16_wr_LIN_rw_INTV10bit_max_g(a)                                    {LIN_rw_INTV10bit_max_g_0 = ((canuint8)a);\
                                                                                 LIN_rw_INTV10bit_max_g_1 = ((canuint8)a>>8);}
#define l_u16_rd_LIN_rw_INTV10bit_min_g()                                     (canuint16)(LIN_rw_INTV10bit_min_g_0)\
                                                                                | ((canuint16)(LIN_rw_INTV10bit_min_g_1)<<6)
#define l_u16_wr_LIN_rw_INTV10bit_min_g(a)                                    {LIN_rw_INTV10bit_min_g_0 = ((canuint8)a);\
                                                                                 LIN_rw_INTV10bit_min_g_1 = ((canuint8)a>>6);}
#define l_u16_rd_LIN_rw_VICALLO_ILO_GHI_ASIC_g()                              (canuint16)(LIN_rw_VICALLO_ILO_GHI_ASIC_g_0)\
                                                                                | ((canuint16)(LIN_rw_VICALLO_ILO_GHI_ASIC_g_1)<<4)
#define l_u16_wr_LIN_rw_VICALLO_ILO_GHI_ASIC_g(a)                             {LIN_rw_VICALLO_ILO_GHI_ASIC_g_0 = ((canuint8)a);\
                                                                                 LIN_rw_VICALLO_ILO_GHI_ASIC_g_1 = ((canuint8)a>>4);}
#define l_u16_rd_LIN_rw_VTEMP_ASIC_g()                                        (canuint16)(LIN_rw_VTEMP_ASIC_g_0)\
                                                                                | ((canuint16)(LIN_rw_VTEMP_ASIC_g_1)<<2)
#define l_u16_wr_LIN_rw_VTEMP_ASIC_g(a)                                       {LIN_rw_VTEMP_ASIC_g_0 = ((canuint8)a);\
                                                                                 LIN_rw_VTEMP_ASIC_g_1 = ((canuint8)a>>2);}
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
                                                                                 LIN_rw_ALS2_ASIC_g_1 = ((canuint8)a>>8);}
#define l_u16_rd_LIN_rw_ALS5_ASIC_g()                                         (canuint16)(LIN_rw_ALS5_ASIC_g_0)\
                                                                                | ((canuint16)(LIN_rw_ALS5_ASIC_g_1)<<6)
#define l_u16_wr_LIN_rw_ALS5_ASIC_g(a)                                        {LIN_rw_ALS5_ASIC_g_0 = ((canuint8)a);\
                                                                                 LIN_rw_ALS5_ASIC_g_1 = ((canuint8)a>>6);}
#define l_u16_rd_LIN_rw_Amb_light16bit_g()                                    (canuint16)(LIN_rw_Amb_light16bit_g_0)\
                                                                                | ((canuint16)(LIN_rw_Amb_light16bit_g_1)<<4)
#define l_u16_wr_LIN_rw_Amb_light16bit_g(a)                                   {LIN_rw_Amb_light16bit_g_0 = ((canuint8)a);\
                                                                                 LIN_rw_Amb_light16bit_g_1 = ((canuint8)a>>4);}
#define l_u16_rd_LIN_rw_INREC_ASIC_g()                                        (canuint16)(LIN_rw_INREC_ASIC_g_0)\
                                                                                | ((canuint16)(LIN_rw_INREC_ASIC_g_1)<<2)
#define l_u16_wr_LIN_rw_INREC_ASIC_g(a)                                       {LIN_rw_INREC_ASIC_g_0 = ((canuint8)a);\
                                                                                 LIN_rw_INREC_ASIC_g_1 = ((canuint8)a>>2);}
#define l_bool_rd_RS_St_LampReq()                                               RS_St_LampReq
#define l_bool_wr_RS_St_LampReq(a)                                              {RS_St_LampReq = a;}
#define l_u8_rd_RS_St_WiperReq()                                            RS_St_WiperReq
#define l_u8_wr_RS_St_WiperReq(a)                                           {RS_St_WiperReq = a;}
#define l_u8_rd_RS_St_CurrentRain()                                         RS_St_CurrentRain
#define l_u8_wr_RS_St_CurrentRain(a)                                        {RS_St_CurrentRain = a;}
#define l_bool_rd_RS_St_SplashCmd()                                             RS_St_SplashCmd
#define l_bool_wr_RS_St_SplashCmd(a)                                            {RS_St_SplashCmd = a;}
#define l_bool_rd_RS_F_LightSensor()                                            RS_F_LightSensor
#define l_bool_wr_RS_F_LightSensor(a)                                           {RS_F_LightSensor = a;}
#define l_bool_rd_RS_F_RainSensor()                                             RS_F_RainSensor
#define l_bool_wr_RS_F_RainSensor(a)                                            {RS_F_RainSensor = a;}
#define l_u8_rd_RS_F_Voltage()                                              RS_F_Voltage
#define l_u8_wr_RS_F_Voltage(a)                                             {RS_F_Voltage = a;}
#define l_bool_rd_RS_F_Communication()                                          RS_F_Communication
#define l_bool_wr_RS_F_Communication(a)                                         {RS_F_Communication = a;}
#define l_u8_rd_RS_RollingCounter()                                         RS_RollingCounter
#define l_u8_wr_RS_RollingCounter(a)                                        {RS_RollingCounter = a;}
#define l_u8_rd_RS_N_Irbrightness()                                         RS_N_Irbrightness
#define l_u8_wr_RS_N_Irbrightness(a)                                        {RS_N_Irbrightness = a;}
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
#define l_u8_rd_BCMLC2_N_GlassPara1()                                       BCMLC2_N_GlassPara1
#define l_u8_wr_BCMLC2_N_GlassPara1(a)                                      {BCMLC2_N_GlassPara1 = a;}
#define l_u8_rd_BCMLC2_N_GlassPara2()                                       BCMLC2_N_GlassPara2
#define l_u8_wr_BCMLC2_N_GlassPara2(a)                                      {BCMLC2_N_GlassPara2 = a;}
#define l_u16_rd_BCMLC2_St_LMirrorLevel()                                     (canuint16)(BCMLC2_St_LMirrorLevel_0)\
                                                                                | ((canuint16)(BCMLC2_St_LMirrorLevel_1)<<8)
#define l_u16_wr_BCMLC2_St_LMirrorLevel(a)                                    {BCMLC2_St_LMirrorLevel_0 = ((canuint8)a);\
                                                                                 BCMLC2_St_LMirrorLevel_1 = ((canuint8)a>>8);}
#define l_u16_rd_BCMLC2_St_LMirrorHeight()                                    (canuint16)(BCMLC2_St_LMirrorHeight_0)\
                                                                                | ((canuint16)(BCMLC2_St_LMirrorHeight_1)<<8)
#define l_u16_wr_BCMLC2_St_LMirrorHeight(a)                                   {BCMLC2_St_LMirrorHeight_0 = ((canuint8)a);\
                                                                                 BCMLC2_St_LMirrorHeight_1 = ((canuint8)a>>8);}
#define l_u8_rd_BCMLC2_St_MirSwSStCMD()                                     BCMLC2_St_MirSwSStCMD
#define l_u8_wr_BCMLC2_St_MirSwSStCMD(a)                                    {BCMLC2_St_MirSwSStCMD = a;}
#define l_u8_rd_BCMLC2_St_MirSwVStCMD()                                     BCMLC2_St_MirSwVStCMD
#define l_u8_wr_BCMLC2_St_MirSwVStCMD(a)                                    {BCMLC2_St_MirSwVStCMD = a;}
#define l_u8_rd_BCMLC2_St_MirSwHStCMD()                                     BCMLC2_St_MirSwHStCMD
#define l_u8_wr_BCMLC2_St_MirSwHStCMD(a)                                    {BCMLC2_St_MirSwHStCMD = a;}
#define l_bool_rd_BCMLC_St_KLS()                                                BCMLC_St_KLS
#define l_bool_wr_BCMLC_St_KLS(a)                                               {BCMLC_St_KLS = a;}
#define l_bool_rd_BCMLC_St_KL15()                                               BCMLC_St_KL15
#define l_bool_wr_BCMLC_St_KL15(a)                                              {BCMLC_St_KL15 = a;}
#define l_bool_rd_BCMLC_St_KLR()                                                BCMLC_St_KLR
#define l_bool_wr_BCMLC_St_KLR(a)                                               {BCMLC_St_KLR = a;}
#define l_bool_rd_BCMLC_St_KL50()                                               BCMLC_St_KL50
#define l_bool_wr_BCMLC_St_KL50(a)                                              {BCMLC_St_KL50 = a;}
#define l_u8_rd_BCMLC_N_VehicleSpeed()                                      BCMLC_N_VehicleSpeed
#define l_u8_wr_BCMLC_N_VehicleSpeed(a)                                     {BCMLC_N_VehicleSpeed = a;}
#define l_u8_rd_BCMLC_St_GearPos()                                          BCMLC_St_GearPos
#define l_u8_wr_BCMLC_St_GearPos(a)                                         {BCMLC_St_GearPos = a;}
#define l_bool_rd_BCMLC_St_Crash()                                              BCMLC_St_Crash
#define l_bool_wr_BCMLC_St_Crash(a)                                             {BCMLC_St_Crash = a;}
#define l_bool_rd_BCMLC_St_DriveDoorAjar()                                      BCMLC_St_DriveDoorAjar
#define l_bool_wr_BCMLC_St_DriveDoorAjar(a)                                     {BCMLC_St_DriveDoorAjar = a;}
#define l_bool_rd_BCMLC_St_MirrorAutoDecl()                                     BCMLC_St_MirrorAutoDecl
#define l_bool_wr_BCMLC_St_MirrorAutoDecl(a)                                    {BCMLC_St_MirrorAutoDecl = a;}
#define l_bool_rd_BCMLC_St_MirrorAdjustSyn()                                    BCMLC_St_MirrorAdjustSyn
#define l_bool_wr_BCMLC_St_MirrorAdjustSyn(a)                                   {BCMLC_St_MirrorAdjustSyn = a;}
#define l_u8_rd_BCMLC_N_KeyNumber()                                         BCMLC_N_KeyNumber
#define l_u8_wr_BCMLC_N_KeyNumber(a)                                        {BCMLC_N_KeyNumber = a;}
#define l_bool_rd_BCMLC_St_Transit()                                            BCMLC_St_Transit
#define l_bool_wr_BCMLC_St_Transit(a)                                           {BCMLC_St_Transit = a;}
#define l_bool_rd_BCMLC_St_EesyEntryEnable()                                    BCMLC_St_EesyEntryEnable
#define l_bool_wr_BCMLC_St_EesyEntryEnable(a)                                   {BCMLC_St_EesyEntryEnable = a;}
#define l_bool_rd_BCMLC_St_RKEMemoryEnable()                                    BCMLC_St_RKEMemoryEnable
#define l_bool_wr_BCMLC_St_RKEMemoryEnable(a)                                   {BCMLC_St_RKEMemoryEnable = a;}
#define l_bool_rd_BCMLC_St_BPedal()                                             BCMLC_St_BPedal
#define l_bool_wr_BCMLC_St_BPedal(a)                                            {BCMLC_St_BPedal = a;}
#define l_bool_rd_BCMLC_F_BPedal()                                              BCMLC_F_BPedal
#define l_bool_wr_BCMLC_F_BPedal(a)                                             {BCMLC_F_BPedal = a;}
#define l_bool_rd_BCMLC_St_LowVoltageReq()                                      BCMLC_St_LowVoltageReq
#define l_bool_wr_BCMLC_St_LowVoltageReq(a)                                     {BCMLC_St_LowVoltageReq = a;}
#define l_bool_rd_BCMLC_St_UrgentVoltageReq()                                   BCMLC_St_UrgentVoltageReq
#define l_bool_wr_BCMLC_St_UrgentVoltageReq(a)                                  {BCMLC_St_UrgentVoltageReq = a;}
#define l_u8_rd_BCMLC_St_WiperHandle()                                      BCMLC_St_WiperHandle
#define l_u8_wr_BCMLC_St_WiperHandle(a)                                     {BCMLC_St_WiperHandle = a;}
#define l_u8_rd_BCMLC_St_WiperSenstivity()                                  BCMLC_St_WiperSenstivity
#define l_u8_wr_BCMLC_St_WiperSenstivity(a)                                 {BCMLC_St_WiperSenstivity = a;}
#define l_bool_rd_BCMLC_St_FrontWasher()                                        BCMLC_St_FrontWasher
#define l_bool_wr_BCMLC_St_FrontWasher(a)                                       {BCMLC_St_FrontWasher = a;}
#define l_u8_rd_BCMLC_St_ParkSwitch()                                       BCMLC_St_ParkSwitch
#define l_u8_wr_BCMLC_St_ParkSwitch(a)                                      {BCMLC_St_ParkSwitch = a;}
#define l_bool_rd_BCMLC_St_NationalCode()                                       BCMLC_St_NationalCode
#define l_bool_wr_BCMLC_St_NationalCode(a)                                      {BCMLC_St_NationalCode = a;}
#define l_u8_rd_BCMLC_St_VehicleType()                                      BCMLC_St_VehicleType
#define l_u8_wr_BCMLC_St_VehicleType(a)                                     {BCMLC_St_VehicleType = a;}
#define l_u8_rd_BCMLC_St_ReadPos()                                          BCMLC_St_ReadPos
#define l_u8_wr_BCMLC_St_ReadPos(a)                                         {BCMLC_St_ReadPos = a;}


#endif  /* I_LIN_RLS_H */
