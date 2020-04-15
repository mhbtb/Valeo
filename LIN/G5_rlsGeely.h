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
#define cb_HANDLE_RLSs_01_g                 5 //cb_HANDLE_RS_01_g                   5
#define cb_HANDLE_LinReqCmd_g               6
#define cb_HANDLE_BCM1_LIN1_01_g            8 //cb_HANDLE_BCM_01_g                  8
#define cb_HANDLE_WWSs_01_g                 7 //cb_HANDLE_BCM_02_g                  7

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
  canbittype                          L_RS_WiperSpeed: 4;
  canbittype                       L_RS_RainSenHealth: 2;
  canbittype                          L_RS_RainSenSts: 2;
  canbittype                     L_RS_CollectiveError: 2;
  canbittype                      L_RS_response_error: 1;
  canbittype                     Reserved_RS01_Byte01: 5;
  canbittype                       L_RS_StateCalError: 2;
  canbittype                      L_RS_RainStateError: 2;
  canbittype                       L_RS_OverTempError: 2;
  canbittype                           L_RS_VoltError: 2;
  canbittype                     Reserved_RS01_Byte03: 8;
  canbittype                   L_RS_Software_No_Count: 4;
  canbittype                       L_RS_Part_No_Count: 4;
  canbittype                         L_RS_Software_No: 8;
  canbittype                             L_RS_Part_No: 8;
  canbittype                     Reserved_RS01_Byte07: 8;
} _c_RS_01_msgType;


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
  canbittype                     L_BCM_RainFuncActive: 2;
  canbittype                          L_BCM_WiperType: 2;
  canbittype                       L_BCM_WiperControl: 4;
  canbittype                      L_BCM_WiperPosition: 2;
  canbittype                    L_BCM_RainSensitivity: 3;
  canbittype                   L_BCM_LightSensitivity: 3;
  canbittype                    Reserved_BCM02_Byte02: 8;
  canbittype                    Reserved_BCM03_Byte03: 8;
} _c_BCM_02_msgType;

typedef struct {
  canbittype                          L_BCM_WdwEnable: 1;
  canbittype                              L_BCM_KL15s: 1;
  canbittype                     L_BCM_GlobalMoveStop: 1;
  canbittype                        L_BCM_GlobalClose: 1;
  canbittype                         L_BCM_GlobalOpen: 1;
  canbittype                       L_BCM_VehicleModel: 3;
  canbittype                       L_BCM_VehicleSpeed: 8;
  canbittype                        L_BCM_OutdoorTemp: 8;
  canbittype                     L_BCM_DDCB2_WdwManUP: 1;
  canbittype                     L_BCM_DDCB3_WdwManDw: 1;
  canbittype                     L_BCM_DDCB4_WdwExpUp: 1;
  canbittype                     L_BCM_DDCB5_WdwExpDw: 1;
  canbittype                Reserved_BCM01_Byte03_4_7: 4;
  canbittype                     L_BCM_PDCB2_WdwManUP: 1;
  canbittype                     L_BCM_PDCB3_WdwManDw: 1;
  canbittype                     L_BCM_PDCB4_WdwExpUp: 1;
  canbittype                     L_BCM_PDCB5_WdwExpDw: 1;
  canbittype                Reserved_BCM01_Byte04_4_7: 4;
  canbittype                     L_BCM_RLCB2_WdwManUP: 1;
  canbittype                     L_BCM_RLCB3_WdwManDw: 1;
  canbittype                     L_BCM_RLCB4_WdwExpUp: 1;
  canbittype                     L_BCM_RLCB5_WdwExpDw: 1;
  canbittype                Reserved_BCM01_Byte05_4_7: 4;
  canbittype                     L_BCM_RRCB2_WdwManUP: 1;
  canbittype                     L_BCM_RRCB3_WdwManDw: 1;
  canbittype                     L_BCM_RRCB4_WdwExpUp: 1;
  canbittype                     L_BCM_RRCB5_WdwExpDw: 1;
  canbittype                Reserved_BCM01_Byte06_4_7: 4;
  canbittype                         L_BCM_ScreenType: 4;
  canbittype                Reserved_BCM01_Byte07_4_7: 4;
} _c_BCM_01_msgType;


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
    _c_RS_01_msgType rs_01;
} _c_RS_01_buf;


/* Receive messages */

typedef union {
    unsigned char _c[8];
    _c_LinReqCmd_msgType linreqcmd;
} _c_LinReqCmd_buf;

typedef union {
    unsigned char _c[4];
    _c_BCM_02_msgType bcm_02;
} _c_BCM_02_buf;

typedef union {
    unsigned char _c[8];
    _c_BCM_01_msgType bcm_01;
} _c_BCM_01_buf;


/******************************************************************************/
/*                          Databuffer for send objects                       */
/******************************************************************************/

extern MEMORY_FAR _c_LinRespCmd_buf LinRespCmd;
extern MEMORY_FAR _c_ASIC_Frame_04_buf ASIC_Frame_04;
extern MEMORY_FAR _c_ASIC_Frame_03_buf ASIC_Frame_03;
extern MEMORY_FAR _c_ASIC_Frame_02_buf ASIC_Frame_02;
extern MEMORY_FAR _c_ASIC_Frame_01_buf ASIC_Frame_01;
extern MEMORY_FAR _c_RS_01_buf RS_01;

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
#define RS_01_conf_b             uLinConfirmationFlags.w[0].b5
#define l_flg_tst_RS_01()       (RS_01_conf_b != 0)
#define l_flg_clr_RS_01()       {RS_01_conf_b = 0;}

/******************************************************************************/
/*                         Databuffer for receive objects                     */
/******************************************************************************/

extern MEMORY_FAR _c_LinReqCmd_buf LinReqCmd;
extern MEMORY_FAR _c_BCM_02_buf BCM_02;
extern MEMORY_FAR _c_BCM_01_buf BCM_01;

/******************************************************************************/
/*                          Databuffer for indicationflags                    */
/******************************************************************************/

#define LinReqCmd_ind_b             uLinIndicationFlags.w[0].b0
#define l_flg_tst_LinReqCmd()       (LinReqCmd_ind_b != 0)
#define l_flg_clr_LinReqCmd()       {LinReqCmd_ind_b = 0;}
#define BCM_02_ind_b             uLinIndicationFlags.w[0].b1
#define l_flg_tst_BCM_02()       (BCM_02_ind_b != 0)
#define l_flg_clr_BCM_02()       {BCM_02_ind_b = 0;}
#define BCM_01_ind_b             uLinIndicationFlags.w[0].b2
#define l_flg_tst_BCM_01()       (BCM_01_ind_b != 0)
#define l_flg_clr_BCM_01()       {BCM_01_ind_b = 0;}

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
#define L_RS_WiperSpeed                                                       RS_01.rs_01.L_RS_WiperSpeed
#define L_RS_RainSenHealth                                                    RS_01.rs_01.L_RS_RainSenHealth
#define L_RS_RainSenSts                                                       RS_01.rs_01.L_RS_RainSenSts
#define L_RS_CollectiveError                                                  RS_01.rs_01.L_RS_CollectiveError
#define L_RS_response_error                                                   RS_01.rs_01.L_RS_response_error
#define Reserved_RS01_Byte01                                                  RS_01.rs_01.Reserved_RS01_Byte01
#define L_RS_StateCalError                                                    RS_01.rs_01.L_RS_StateCalError
#define L_RS_RainStateError                                                   RS_01.rs_01.L_RS_RainStateError
#define L_RS_OverTempError                                                    RS_01.rs_01.L_RS_OverTempError
#define L_RS_VoltError                                                        RS_01.rs_01.L_RS_VoltError
#define Reserved_RS01_Byte03                                                  RS_01.rs_01.Reserved_RS01_Byte03
#define L_RS_Software_No_Count                                                RS_01.rs_01.L_RS_Software_No_Count
#define L_RS_Part_No_Count                                                    RS_01.rs_01.L_RS_Part_No_Count
#define L_RS_Software_No1                                                     RS_01.rs_01.L_RS_Software_No
#define L_RS_Part_No1                                                         RS_01.rs_01.L_RS_Part_No
#define Reserved_RS01_Byte07                                                  RS_01.rs_01.Reserved_RS01_Byte07
#define MasterReqB0                                                           LinReqCmd.linreqcmd.MasterReqB0
#define MasterReqB1                                                           LinReqCmd.linreqcmd.MasterReqB1
#define MasterReqB2                                                           LinReqCmd.linreqcmd.MasterReqB2
#define MasterReqB3                                                           LinReqCmd.linreqcmd.MasterReqB3
#define MasterReqB4                                                           LinReqCmd.linreqcmd.MasterReqB4
#define MasterReqB5                                                           LinReqCmd.linreqcmd.MasterReqB5
#define MasterReqB6                                                           LinReqCmd.linreqcmd.MasterReqB6
#define MasterReqB7                                                           LinReqCmd.linreqcmd.MasterReqB7
#define L_BCM_RainFuncActive                                                  BCM_02.bcm_02.L_BCM_RainFuncActive
#define L_BCM_WiperType                                                       BCM_02.bcm_02.L_BCM_WiperType
#define L_BCM_WiperControl                                                    BCM_02.bcm_02.L_BCM_WiperControl
#define L_BCM_WiperPosition                                                   BCM_02.bcm_02.L_BCM_WiperPosition
#define L_BCM_RainSensitivity                                                 BCM_02.bcm_02.L_BCM_RainSensitivity
#define L_BCM_LightSensitivity                                                BCM_02.bcm_02.L_BCM_LightSensitivity
#define Reserved_BCM02_Byte02                                                 BCM_02.bcm_02.Reserved_BCM02_Byte02
#define Reserved_BCM03_Byte03                                                 BCM_02.bcm_02.Reserved_BCM03_Byte03
#define L_BCM_WdwEnable                                                       BCM_01.bcm_01.L_BCM_WdwEnable
#define L_BCM_KL15s                                                           BCM_01.bcm_01.L_BCM_KL15s
#define L_BCM_GlobalMoveStop                                                  BCM_01.bcm_01.L_BCM_GlobalMoveStop
#define L_BCM_GlobalClose                                                     BCM_01.bcm_01.L_BCM_GlobalClose
#define L_BCM_GlobalOpen                                                      BCM_01.bcm_01.L_BCM_GlobalOpen
#define L_BCM_VehicleModel                                                    BCM_01.bcm_01.L_BCM_VehicleModel
#define L_BCM_VehicleSpeed                                                    BCM_01.bcm_01.L_BCM_VehicleSpeed
#define L_BCM_OutdoorTemp                                                     BCM_01.bcm_01.L_BCM_OutdoorTemp
#define L_BCM_DDCB2_WdwManUP                                                  BCM_01.bcm_01.L_BCM_DDCB2_WdwManUP
#define L_BCM_DDCB3_WdwManDw                                                  BCM_01.bcm_01.L_BCM_DDCB3_WdwManDw
#define L_BCM_DDCB4_WdwExpUp                                                  BCM_01.bcm_01.L_BCM_DDCB4_WdwExpUp
#define L_BCM_DDCB5_WdwExpDw                                                  BCM_01.bcm_01.L_BCM_DDCB5_WdwExpDw
#define Reserved_BCM01_Byte03_4_7                                             BCM_01.bcm_01.Reserved_BCM01_Byte03_4_7
#define L_BCM_PDCB2_WdwManUP                                                  BCM_01.bcm_01.L_BCM_PDCB2_WdwManUP
#define L_BCM_PDCB3_WdwManDw                                                  BCM_01.bcm_01.L_BCM_PDCB3_WdwManDw
#define L_BCM_PDCB4_WdwExpUp                                                  BCM_01.bcm_01.L_BCM_PDCB4_WdwExpUp
#define L_BCM_PDCB5_WdwExpDw                                                  BCM_01.bcm_01.L_BCM_PDCB5_WdwExpDw
#define Reserved_BCM01_Byte04_4_7                                             BCM_01.bcm_01.Reserved_BCM01_Byte04_4_7
#define L_BCM_RLCB2_WdwManUP                                                  BCM_01.bcm_01.L_BCM_RLCB2_WdwManUP
#define L_BCM_RLCB3_WdwManDw                                                  BCM_01.bcm_01.L_BCM_RLCB3_WdwManDw
#define L_BCM_RLCB4_WdwExpUp                                                  BCM_01.bcm_01.L_BCM_RLCB4_WdwExpUp
#define L_BCM_RLCB5_WdwExpDw                                                  BCM_01.bcm_01.L_BCM_RLCB5_WdwExpDw
#define Reserved_BCM01_Byte05_4_7                                             BCM_01.bcm_01.Reserved_BCM01_Byte05_4_7
#define L_BCM_RRCB2_WdwManUP                                                  BCM_01.bcm_01.L_BCM_RRCB2_WdwManUP
#define L_BCM_RRCB3_WdwManDw                                                  BCM_01.bcm_01.L_BCM_RRCB3_WdwManDw
#define L_BCM_RRCB4_WdwExpUp                                                  BCM_01.bcm_01.L_BCM_RRCB4_WdwExpUp
#define L_BCM_RRCB5_WdwExpDw                                                  BCM_01.bcm_01.L_BCM_RRCB5_WdwExpDw
#define Reserved_BCM01_Byte06_4_7                                             BCM_01.bcm_01.Reserved_BCM01_Byte06_4_7
#define L_BCM_ScreenType                                                      BCM_01.bcm_01.L_BCM_ScreenType
#define Reserved_BCM01_Byte07_4_7                                             BCM_01.bcm_01.Reserved_BCM01_Byte07_4_7
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
#define l_u8_rd_L_RS_WiperSpeed()                                           L_RS_WiperSpeed
#define l_u8_wr_L_RS_WiperSpeed(a)                                          {L_RS_WiperSpeed = a;}
#define l_u8_rd_L_RS_RainSenHealth()                                        L_RS_RainSenHealth
#define l_u8_wr_L_RS_RainSenHealth(a)                                       {L_RS_RainSenHealth = a;}
#define l_u8_rd_L_RS_RainSenSts()                                           L_RS_RainSenSts
#define l_u8_wr_L_RS_RainSenSts(a)                                          {L_RS_RainSenSts = a;}
#define l_u8_rd_L_RS_CollectiveError()                                      L_RS_CollectiveError
#define l_u8_wr_L_RS_CollectiveError(a)                                     {L_RS_CollectiveError = a;}
#define l_bool_rd_L_RS_response_error()                                         L_RS_response_error
#define l_bool_wr_L_RS_response_error(a)                                        {L_RS_response_error = a;}
#define l_u8_rd_Reserved_RS01_Byte01()                                      Reserved_RS01_Byte01
#define l_u8_wr_Reserved_RS01_Byte01(a)                                     {Reserved_RS01_Byte01 = a;}
#define l_u8_rd_L_RS_StateCalError()                                        L_RS_StateCalError
#define l_u8_wr_L_RS_StateCalError(a)                                       {L_RS_StateCalError = a;}
#define l_u8_rd_L_RS_RainStateError()                                       L_RS_RainStateError
#define l_u8_wr_L_RS_RainStateError(a)                                      {L_RS_RainStateError = a;}
#define l_u8_rd_L_RS_OverTempError()                                        L_RS_OverTempError
#define l_u8_wr_L_RS_OverTempError(a)                                       {L_RS_OverTempError = a;}
#define l_u8_rd_L_RS_VoltError()                                            L_RS_VoltError
#define l_u8_wr_L_RS_VoltError(a)                                           {L_RS_VoltError = a;}
#define l_u8_rd_Reserved_RS01_Byte03()                                      Reserved_RS01_Byte03
#define l_u8_wr_Reserved_RS01_Byte03(a)                                     {Reserved_RS01_Byte03 = a;}
#define l_u8_rd_L_RS_Software_No_Count()                                    L_RS_Software_No_Count
#define l_u8_wr_L_RS_Software_No_Count(a)                                   {L_RS_Software_No_Count = a;}
#define l_u8_rd_L_RS_Part_No_Count()                                        L_RS_Part_No_Count
#define l_u8_wr_L_RS_Part_No_Count(a)                                       {L_RS_Part_No_Count = a;}
#define l_u8_rd_L_RS_Software_No1()                                         L_RS_Software_No1
#define l_u8_wr_L_RS_Software_No1(a)                                        {L_RS_Software_No1 = a;}
#define l_u8_rd_L_RS_Part_No1()                                             L_RS_Part_No1
#define l_u8_wr_L_RS_Part_No1(a)                                            {L_RS_Part_No1 = a;}
#define l_u8_rd_Reserved_RS01_Byte07()                                      Reserved_RS01_Byte07
#define l_u8_wr_Reserved_RS01_Byte07(a)                                     {Reserved_RS01_Byte07 = a;}
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
#define l_u8_rd_L_BCM_RainFuncActive()                                      L_BCM_RainFuncActive
#define l_u8_wr_L_BCM_RainFuncActive(a)                                     {L_BCM_RainFuncActive = a;}
#define l_u8_rd_L_BCM_WiperType()                                           L_BCM_WiperType
#define l_u8_wr_L_BCM_WiperType(a)                                          {L_BCM_WiperType = a;}
#define l_u8_rd_L_BCM_WiperControl()                                        L_BCM_WiperControl
#define l_u8_wr_L_BCM_WiperControl(a)                                       {L_BCM_WiperControl = a;}
#define l_u8_rd_L_BCM_WiperPosition()                                       L_BCM_WiperPosition
#define l_u8_wr_L_BCM_WiperPosition(a)                                      {L_BCM_WiperPosition = a;}
#define l_u8_rd_L_BCM_RainSensitivity()                                     L_BCM_RainSensitivity
#define l_u8_wr_L_BCM_RainSensitivity(a)                                    {L_BCM_RainSensitivity = a;}
#define l_u8_rd_L_BCM_LightSensitivity()                                    L_BCM_LightSensitivity
#define l_u8_wr_L_BCM_LightSensitivity(a)                                   {L_BCM_LightSensitivity = a;}
#define l_u8_rd_Reserved_BCM02_Byte02()                                     Reserved_BCM02_Byte02
#define l_u8_wr_Reserved_BCM02_Byte02(a)                                    {Reserved_BCM02_Byte02 = a;}
#define l_u8_rd_Reserved_BCM03_Byte03()                                     Reserved_BCM03_Byte03
#define l_u8_wr_Reserved_BCM03_Byte03(a)                                    {Reserved_BCM03_Byte03 = a;}
#define l_bool_rd_L_BCM_WdwEnable()                                             L_BCM_WdwEnable
#define l_bool_wr_L_BCM_WdwEnable(a)                                            {L_BCM_WdwEnable = a;}
#define l_bool_rd_L_BCM_KL15s()                                                 L_BCM_KL15s
#define l_bool_wr_L_BCM_KL15s(a)                                                {L_BCM_KL15s = a;}
#define l_bool_rd_L_BCM_GlobalMoveStop()                                        L_BCM_GlobalMoveStop
#define l_bool_wr_L_BCM_GlobalMoveStop(a)                                       {L_BCM_GlobalMoveStop = a;}
#define l_bool_rd_L_BCM_GlobalClose()                                           L_BCM_GlobalClose
#define l_bool_wr_L_BCM_GlobalClose(a)                                          {L_BCM_GlobalClose = a;}
#define l_bool_rd_L_BCM_GlobalOpen()                                            L_BCM_GlobalOpen
#define l_bool_wr_L_BCM_GlobalOpen(a)                                           {L_BCM_GlobalOpen = a;}
#define l_u8_rd_L_BCM_VehicleModel()                                        L_BCM_VehicleModel
#define l_u8_wr_L_BCM_VehicleModel(a)                                       {L_BCM_VehicleModel = a;}
#define l_u8_rd_L_BCM_VehicleSpeed()                                        L_BCM_VehicleSpeed
#define l_u8_wr_L_BCM_VehicleSpeed(a)                                       {L_BCM_VehicleSpeed = a;}
#define l_u8_rd_L_BCM_OutdoorTemp()                                         L_BCM_OutdoorTemp
#define l_u8_wr_L_BCM_OutdoorTemp(a)                                        {L_BCM_OutdoorTemp = a;}
#define l_bool_rd_L_BCM_DDCB2_WdwManUP()                                        L_BCM_DDCB2_WdwManUP
#define l_bool_wr_L_BCM_DDCB2_WdwManUP(a)                                       {L_BCM_DDCB2_WdwManUP = a;}
#define l_bool_rd_L_BCM_DDCB3_WdwManDw()                                        L_BCM_DDCB3_WdwManDw
#define l_bool_wr_L_BCM_DDCB3_WdwManDw(a)                                       {L_BCM_DDCB3_WdwManDw = a;}
#define l_bool_rd_L_BCM_DDCB4_WdwExpUp()                                        L_BCM_DDCB4_WdwExpUp
#define l_bool_wr_L_BCM_DDCB4_WdwExpUp(a)                                       {L_BCM_DDCB4_WdwExpUp = a;}
#define l_bool_rd_L_BCM_DDCB5_WdwExpDw()                                        L_BCM_DDCB5_WdwExpDw
#define l_bool_wr_L_BCM_DDCB5_WdwExpDw(a)                                       {L_BCM_DDCB5_WdwExpDw = a;}
#define l_u8_rd_Reserved_BCM01_Byte03_4_7()                                 Reserved_BCM01_Byte03_4_7
#define l_u8_wr_Reserved_BCM01_Byte03_4_7(a)                                {Reserved_BCM01_Byte03_4_7 = a;}
#define l_bool_rd_L_BCM_PDCB2_WdwManUP()                                        L_BCM_PDCB2_WdwManUP
#define l_bool_wr_L_BCM_PDCB2_WdwManUP(a)                                       {L_BCM_PDCB2_WdwManUP = a;}
#define l_bool_rd_L_BCM_PDCB3_WdwManDw()                                        L_BCM_PDCB3_WdwManDw
#define l_bool_wr_L_BCM_PDCB3_WdwManDw(a)                                       {L_BCM_PDCB3_WdwManDw = a;}
#define l_bool_rd_L_BCM_PDCB4_WdwExpUp()                                        L_BCM_PDCB4_WdwExpUp
#define l_bool_wr_L_BCM_PDCB4_WdwExpUp(a)                                       {L_BCM_PDCB4_WdwExpUp = a;}
#define l_bool_rd_L_BCM_PDCB5_WdwExpDw()                                        L_BCM_PDCB5_WdwExpDw
#define l_bool_wr_L_BCM_PDCB5_WdwExpDw(a)                                       {L_BCM_PDCB5_WdwExpDw = a;}
#define l_u8_rd_Reserved_BCM01_Byte04_4_7()                                 Reserved_BCM01_Byte04_4_7
#define l_u8_wr_Reserved_BCM01_Byte04_4_7(a)                                {Reserved_BCM01_Byte04_4_7 = a;}
#define l_bool_rd_L_BCM_RLCB2_WdwManUP()                                        L_BCM_RLCB2_WdwManUP
#define l_bool_wr_L_BCM_RLCB2_WdwManUP(a)                                       {L_BCM_RLCB2_WdwManUP = a;}
#define l_bool_rd_L_BCM_RLCB3_WdwManDw()                                        L_BCM_RLCB3_WdwManDw
#define l_bool_wr_L_BCM_RLCB3_WdwManDw(a)                                       {L_BCM_RLCB3_WdwManDw = a;}
#define l_bool_rd_L_BCM_RLCB4_WdwExpUp()                                        L_BCM_RLCB4_WdwExpUp
#define l_bool_wr_L_BCM_RLCB4_WdwExpUp(a)                                       {L_BCM_RLCB4_WdwExpUp = a;}
#define l_bool_rd_L_BCM_RLCB5_WdwExpDw()                                        L_BCM_RLCB5_WdwExpDw
#define l_bool_wr_L_BCM_RLCB5_WdwExpDw(a)                                       {L_BCM_RLCB5_WdwExpDw = a;}
#define l_u8_rd_Reserved_BCM01_Byte05_4_7()                                 Reserved_BCM01_Byte05_4_7
#define l_u8_wr_Reserved_BCM01_Byte05_4_7(a)                                {Reserved_BCM01_Byte05_4_7 = a;}
#define l_bool_rd_L_BCM_RRCB2_WdwManUP()                                        L_BCM_RRCB2_WdwManUP
#define l_bool_wr_L_BCM_RRCB2_WdwManUP(a)                                       {L_BCM_RRCB2_WdwManUP = a;}
#define l_bool_rd_L_BCM_RRCB3_WdwManDw()                                        L_BCM_RRCB3_WdwManDw
#define l_bool_wr_L_BCM_RRCB3_WdwManDw(a)                                       {L_BCM_RRCB3_WdwManDw = a;}
#define l_bool_rd_L_BCM_RRCB4_WdwExpUp()                                        L_BCM_RRCB4_WdwExpUp
#define l_bool_wr_L_BCM_RRCB4_WdwExpUp(a)                                       {L_BCM_RRCB4_WdwExpUp = a;}
#define l_bool_rd_L_BCM_RRCB5_WdwExpDw()                                        L_BCM_RRCB5_WdwExpDw
#define l_bool_wr_L_BCM_RRCB5_WdwExpDw(a)                                       {L_BCM_RRCB5_WdwExpDw = a;}
#define l_u8_rd_Reserved_BCM01_Byte06_4_7()                                 Reserved_BCM01_Byte06_4_7
#define l_u8_wr_Reserved_BCM01_Byte06_4_7(a)                                {Reserved_BCM01_Byte06_4_7 = a;}
#define l_u8_rd_L_BCM_ScreenType()                                          L_BCM_ScreenType
#define l_u8_wr_L_BCM_ScreenType(a)                                         {L_BCM_ScreenType = a;}
#define l_u8_rd_Reserved_BCM01_Byte07_4_7()                                 Reserved_BCM01_Byte07_4_7
#define l_u8_wr_Reserved_BCM01_Byte07_4_7(a)                                {Reserved_BCM01_Byte07_4_7 = a;}


#endif  /* I_LIN_RLS_H */
