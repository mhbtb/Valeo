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
#define cb_HANDLE_RLS_02                  5
#define cb_HANDLE_RLS_01                  6
#define cb_HANDLE_LinReqCmd               7
#define cb_HANDLE_BCM_01                  8

#define cb_HANDLE_LinReqCmd_g     cb_HANDLE_LinReqCmd
#define cb_HANDLE_LinRespCmd_g    cb_HANDLE_LinRespCmd
#define cb_HANDLE_ASIC_Frame_04_g cb_HANDLE_ASIC_Frame_04
#define cb_HANDLE_ASIC_Frame_03_g cb_HANDLE_ASIC_Frame_03
#define cb_HANDLE_ASIC_Frame_02_g cb_HANDLE_ASIC_Frame_02
#define cb_HANDLE_ASIC_Frame_01_g cb_HANDLE_ASIC_Frame_01
#define cb_HANDLE_RLSs_02_g       cb_HANDLE_RLS_02
#define cb_HANDLE_RLSs_01_g       cb_HANDLE_RLS_01
#define cb_HANDLE_BCM1_LIN1_01_g  cb_HANDLE_BCM_01

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
  canbittype         RLS2_Status_DewPointTemp_Value_0: 8;
  canbittype         RLS2_Status_DewPointTemp_Value_1: 2;
  canbittype         RLS2_Status_WinGlassTemp_Value_0: 6;
  canbittype         RLS2_Status_WinGlassTemp_Value_1: 2;
  canbittype       RLS2_Status_RelativeHumidity_Lvl_0: 6;
  canbittype       RLS2_Status_RelativeHumidity_Lvl_1: 2;
  canbittype        RLS2_Status_PasSideSunInt_Value_0: 6;
  canbittype        RLS2_Status_PasSideSunInt_Value_1: 2;
  canbittype        RLS2_Status_DriSideSunInt_Value_0: 6;
  canbittype        RLS2_Status_DriSideSunInt_Value_1: 2;
  canbittype                                  unused0: 6;
  canbittype                                  unused1: 8;
  canbittype                                  unused2: 8;
} _c_RLS_02_msgType;

typedef struct {
  canbittype                           RLS_MsgCounter: 4;
  canbittype                          RLS_RQ_WiperSPD: 2;
  canbittype                                  unused0: 1;
  canbittype                           RLS_RQ_LowBeam: 1;
  canbittype                      RLS_RQ_PositionLamp: 1;
  canbittype                           RLS_Fault_Rain: 1;
  canbittype                          RLS_Fault_Light: 1;
  canbittype                            RLS_REP_Error: 1;
  canbittype                                  unused1: 4;
  canbittype                        RLS_Brightness_FW: 8;
  canbittype                      RLS_Brightness_IR_0: 8;
  canbittype                      RLS_Brightness_IR_1: 2;
  canbittype                       RLS_Rain_Intensity: 4;
  canbittype                                  unused2: 2;
  canbittype                                  unused3: 8;
  canbittype                                  unused4: 8;
  canbittype                                  unused5: 8;
} _c_RLS_01_msgType;


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
  canbittype                           BCM_Status_IGN: 2;
  canbittype                        BCM_CMD_AutoWiper: 1;
  canbittype                         BCM_RQ_FrontWash: 1;
  canbittype                         BCM_ParkPosition: 1;
  canbittype                      BCM_RainSensitivity: 3;
  canbittype                        BCM_CMD_AutoLight: 1;
  canbittype                                 Reserved: 7;
  canbittype                        BCM_SPD_Vehicle_0: 8;
  canbittype                        BCM_SPD_Vehicle_1: 5;
  canbittype                                  unused0: 3;
  canbittype                                  unused1: 8;
  canbittype                                  unused2: 8;
  canbittype                                  unused3: 8;
  canbittype                                  unused4: 8;
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
    _c_RLS_02_msgType rls_02;
} _c_RLS_02_buf;

typedef union {
    unsigned char _c[8];
    _c_RLS_01_msgType rls_01;
} _c_RLS_01_buf;


/* Receive messages */

typedef union {
    unsigned char _c[8];
    _c_LinReqCmd_msgType linreqcmd;
} _c_LinReqCmd_buf;

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
extern MEMORY_FAR _c_RLS_02_buf RLS_02;
extern MEMORY_FAR _c_RLS_01_buf RLS_01;

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
#define RLS_02_conf_b             uLinConfirmationFlags.w[0].b5
#define l_flg_tst_RLS_02()       (RLS_02_conf_b != 0)
#define l_flg_clr_RLS_02()       {RLS_02_conf_b = 0;}
#define RLS_01_conf_b             uLinConfirmationFlags.w[0].b6
#define l_flg_tst_RLS_01()       (RLS_01_conf_b != 0)
#define l_flg_clr_RLS_01()       {RLS_01_conf_b = 0;}

/******************************************************************************/
/*                         Databuffer for receive objects                     */
/******************************************************************************/

extern MEMORY_FAR _c_LinReqCmd_buf LinReqCmd;
extern MEMORY_FAR _c_BCM_01_buf BCM_01;

/******************************************************************************/
/*                          Databuffer for indicationflags                    */
/******************************************************************************/

#define LinReqCmd_ind_b             uLinIndicationFlags.w[0].b0
#define l_flg_tst_LinReqCmd()       (LinReqCmd_ind_b != 0)
#define l_flg_clr_LinReqCmd()       {LinReqCmd_ind_b = 0;}
#define BCM_01_ind_b             uLinIndicationFlags.w[0].b1
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
#define RLS2_Status_DewPointTemp_Value_0                                      RLS_02.rls_02.RLS2_Status_DewPointTemp_Value_0
#define RLS2_Status_DewPointTemp_Value_1                                      RLS_02.rls_02.RLS2_Status_DewPointTemp_Value_1
#define RLS2_Status_DewPointTemp_Value(c)                                     { RLS2_Status_DewPointTemp_Value_0= (uint8)(((uint16)(c) & 0xFF));\
                                                                                RLS2_Status_DewPointTemp_Value_1= (uint8)(((uint16)(c) & 0x03) >> 8);\
                                                                              }
#define RLS2_Status_WinGlassTemp_Value_0                                      RLS_02.rls_02.RLS2_Status_WinGlassTemp_Value_0
#define RLS2_Status_WinGlassTemp_Value_1                                      RLS_02.rls_02.RLS2_Status_WinGlassTemp_Value_1
#define RLS2_Status_WinGlassTemp_Value(c)                                     { RLS2_Status_WinGlassTemp_Value_0= (uint8)(((uint16)(c) & 0x3F));\
                                                                                RLS2_Status_WinGlassTemp_Value_1= (uint8)(((uint16)(c) & 0x03) >> 6);\
                                                                              }
#define RLS2_Status_RelativeHumidity_Lvl_0                                    RLS_02.rls_02.RLS2_Status_RelativeHumidity_Lvl_0
#define RLS2_Status_RelativeHumidity_Lvl_1                                    RLS_02.rls_02.RLS2_Status_RelativeHumidity_Lvl_1
#define RLS2_Status_RelativeHumidity_Lvl(c)                                   { RLS2_Status_RelativeHumidity_Lvl_0= (uint8)(((uint16)(c) & 0x3F));\
                                                                                RLS2_Status_RelativeHumidity_Lvl_1= (uint8)(((uint16)(c) & 0x03) >> 6);\
                                                                              }
#define RLS2_Status_PasSideSunInt_Value_0                                     RLS_02.rls_02.RLS2_Status_PasSideSunInt_Value_0
#define RLS2_Status_PasSideSunInt_Value_1                                     RLS_02.rls_02.RLS2_Status_PasSideSunInt_Value_1
#define RLS2_Status_PasSideSunInt_Value(c)                                    { RLS2_Status_PasSideSunInt_Value_0= (uint8)(((uint16)(c) & 0x3F));\
                                                                                RLS2_Status_PasSideSunInt_Value_1= (uint8)(((uint16)(c) & 0x03) >> 6);\
                                                                              }
#define RLS2_Status_DriSideSunInt_Value_0                                     RLS_02.rls_02.RLS2_Status_DriSideSunInt_Value_0
#define RLS2_Status_DriSideSunInt_Value_1                                     RLS_02.rls_02.RLS2_Status_DriSideSunInt_Value_1
#define RLS2_Status_DriSideSunInt_Value(c)                                    { RLS2_Status_DriSideSunInt_Value_0= (uint8)(((uint16)(c) & 0x3F));\
                                                                                RLS2_Status_DriSideSunInt_Value_1= (uint8)(((uint16)(c) & 0x03) >> 6);\
                                                                              }
#define RLS_MsgCounter                                                        RLS_01.rls_01.RLS_MsgCounter
#define RLS_RQ_WiperSPD                                                       RLS_01.rls_01.RLS_RQ_WiperSPD
#define RLS_RQ_LowBeam                                                        RLS_01.rls_01.RLS_RQ_LowBeam
#define RLS_RQ_PositionLamp                                                   RLS_01.rls_01.RLS_RQ_PositionLamp
#define RLS_Fault_Rain                                                        RLS_01.rls_01.RLS_Fault_Rain
#define RLS_Fault_Light                                                       RLS_01.rls_01.RLS_Fault_Light
#define RLS_REP_Error                                                         RLS_01.rls_01.RLS_REP_Error
#define RLS_Brightness_FW                                                     RLS_01.rls_01.RLS_Brightness_FW
#define RLS_Brightness_IR_0                                                   RLS_01.rls_01.RLS_Brightness_IR_0
#define RLS_Brightness_IR_1                                                   RLS_01.rls_01.RLS_Brightness_IR_1
#define RLS_Brightness_IR(c)                                                  { RLS_Brightness_IR_0= (uint8)(((uint16)(c) & 0xFF));\
                                                                                RLS_Brightness_IR_1= (uint8)(((uint16)(c) & 0x03) >> 8);\
                                                                              }
#define RLS_Rain_Intensity                                                    RLS_01.rls_01.RLS_Rain_Intensity
#define MasterReqB0                                                           LinReqCmd.linreqcmd.MasterReqB0
#define MasterReqB1                                                           LinReqCmd.linreqcmd.MasterReqB1
#define MasterReqB2                                                           LinReqCmd.linreqcmd.MasterReqB2
#define MasterReqB3                                                           LinReqCmd.linreqcmd.MasterReqB3
#define MasterReqB4                                                           LinReqCmd.linreqcmd.MasterReqB4
#define MasterReqB5                                                           LinReqCmd.linreqcmd.MasterReqB5
#define MasterReqB6                                                           LinReqCmd.linreqcmd.MasterReqB6
#define MasterReqB7                                                           LinReqCmd.linreqcmd.MasterReqB7
#define BCM_Status_IGN                                                        BCM_01.bcm_01.BCM_Status_IGN
#define BCM_CMD_AutoWiper                                                     BCM_01.bcm_01.BCM_CMD_AutoWiper
#define BCM_RQ_FrontWash                                                      BCM_01.bcm_01.BCM_RQ_FrontWash
#define BCM_ParkPosition                                                      BCM_01.bcm_01.BCM_ParkPosition
#define BCM_RainSensitivity                                                   BCM_01.bcm_01.BCM_RainSensitivity
#define BCM_CMD_AutoLight                                                     BCM_01.bcm_01.BCM_CMD_AutoLight
#define Reserved                                                              BCM_01.bcm_01.Reserved
#define BCM_SPD_Vehicle_0                                                     BCM_01.bcm_01.BCM_SPD_Vehicle_0
#define BCM_SPD_Vehicle_1                                                     BCM_01.bcm_01.BCM_SPD_Vehicle_1
#define BCM_SPD_Vehicle(c)                                                    { BCM_SPD_Vehicle_0= (uint8)(((uint16)(c) & 0xFF));\
                                                                                BCM_SPD_Vehicle_1= (uint8)(((uint16)(c) & 0x1F) >> 8);\
                                                                              }
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
#define l_u16_rd_LIN_rw_VILO_ICALLO_GHI_ASIC_g()                              (canuint16)(LIN_rw_VILO_ICALLO_GHI_ASIC_g_0)\
                                                                                | ((canuint16)(LIN_rw_VILO_ICALLO_GHI_ASIC_g_1)<<2)
#define l_u16_wr_LW_rw_VILO_ICALLO_GHI_ASIC_g(a)                             {LIN_rw_VILO_ICALLO_GHI_ASIC_g_0 = ((canuint8)a);\
                                                                                 LIN_rw_VILO_ICALLO_GHI_ASIC_g_1 = ((canuint8)a>>2);}
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
#define l_u16_rd_RLS2_Status_DewPointTemp_Value()                             (canuint16)(RLS2_Status_DewPointTemp_Value_0)\
                                                                                | ((canuint16)(RLS2_Status_DewPointTemp_Value_1)<<8)
#define l_u16_wr_RLS2_Status_DewPointTemp_Value(a)                            {RLS2_Status_DewPointTemp_Value_0 = (a & 0XFF);\
                                                                                 RLS2_Status_DewPointTemp_Value_1 = ((a>>8) & 0X03);}
#define l_u8_rd_RLS2_Status_WinGlassTemp_Value()                             ((RLS2_Status_WinGlassTemp_Value_0)\
                                                                                | ((RLS2_Status_WinGlassTemp_Value_1)<<6))
#define l_u8_wr_RLS2_Status_WinGlassTemp_Value(a)                            {RLS2_Status_WinGlassTemp_Value_0 = (0x3F & a);\
                                                                                 RLS2_Status_WinGlassTemp_Value_1 = ((canuint8)a>>6);}
#define l_u8_rd_RLS2_Status_RelativeHumidity_Lvl()                           ((RLS2_Status_RelativeHumidity_Lvl_0)\
                                                                                | ((RLS2_Status_RelativeHumidity_Lvl_1)<<6))
#define l_u8_wr_RLS2_Status_RelativeHumidity_Lvl(a)                          {RLS2_Status_RelativeHumidity_Lvl_0 = (0x3f & a);\
                                                                                 RLS2_Status_RelativeHumidity_Lvl_1 = (a>>6);}
#define l_u8_rd_RLS2_Status_PasSideSunInt_Value()                            (canuint8)(RLS2_Status_PasSideSunInt_Value_0)\
                                                                                | ((canuint8)(RLS2_Status_PasSideSunInt_Value_1)<<6)
#define l_u8_wr_RLS2_Status_PasSideSunInt_Value(a)                           {RLS2_Status_PasSideSunInt_Value_0 = (0x3f & a);\
                                                                                 RLS2_Status_PasSideSunInt_Value_1 = (a>>6);}
#define l_u8_rd_RLS2_Status_DriSideSunInt_Value()                            (canuint8)(RLS2_Status_DriSideSunInt_Value_0)\
                                                                                | ((canuint8)(RLS2_Status_DriSideSunInt_Value_1)<<6)
#define l_u8_wr_RLS2_Status_DriSideSunInt_Value(a)                           {RLS2_Status_DriSideSunInt_Value_0 = (0x3f & a);\
                                                                                 RLS2_Status_DriSideSunInt_Value_1 = ((canuint8)a>>6);}
#define l_u8_rd_RLS_MsgCounter()                                            RLS_MsgCounter
#define l_u8_wr_RLS_MsgCounter(a)                                           {RLS_MsgCounter = a;}
#define l_u8_rd_RLS_RQ_WiperSPD()                                           RLS_RQ_WiperSPD
#define l_u8_wr_RLS_RQ_WiperSPD(a)                                          {RLS_RQ_WiperSPD = a;}
#define l_bool_rd_RLS_RQ_LowBeam()                                              RLS_RQ_LowBeam
#define l_bool_wr_RLS_RQ_LowBeam(a)                                             {RLS_RQ_LowBeam = a;}
#define l_bool_rd_RLS_RQ_PositionLamp()                                         RLS_RQ_PositionLamp
#define l_bool_wr_RLS_RQ_PositionLamp(a)                                        {RLS_RQ_PositionLamp = a;}
#define l_bool_rd_RLS_Fault_Rain()                                              RLS_Fault_Rain
#define l_bool_wr_RLS_Fault_Rain(a)                                             {RLS_Fault_Rain = a;}
#define l_bool_rd_RLS_Fault_Light()                                             RLS_Fault_Light
#define l_bool_wr_RLS_Fault_Light(a)                                            {RLS_Fault_Light = a;}
#define l_bool_rd_RLS_REP_Error()                                               RLS_REP_Error
#define l_bool_wr_RLS_REP_Error(a)                                              {RLS_REP_Error = a;}
#define l_u8_rd_RLS_Brightness_FW()                                         RLS_Brightness_FW
#define l_u8_wr_RLS_Brightness_FW(a)                                        {RLS_Brightness_FW = a;}
#define l_u16_rd_RLS_Brightness_IR()                                          (canuint16)(RLS_Brightness_IR_0)\
                                                                                | ((canuint16)(RLS_Brightness_IR_1)<<8)
#define l_u16_wr_RLS_Brightness_IR(a)                                         {RLS_Brightness_IR_0 = ((canuint8)a);\
                                                                                 RLS_Brightness_IR_1 = ((canuint8)a>>8);}
#define l_u8_rd_RLS_Rain_Intensity()                                        RLS_Rain_Intensity
#define l_u8_wr_RLS_Rain_Intensity(a)                                       {RLS_Rain_Intensity = a;}
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
#define l_u8_rd_BCM_Status_IGN()                                            BCM_Status_IGN
#define l_u8_wr_BCM_Status_IGN(a)                                           {BCM_Status_IGN = a;}
#define l_bool_rd_BCM_CMD_AutoWiper()                                           BCM_CMD_AutoWiper
#define l_bool_wr_BCM_CMD_AutoWiper(a)                                          {BCM_CMD_AutoWiper = a;}
#define l_bool_rd_BCM_RQ_FrontWash()                                            BCM_RQ_FrontWash
#define l_bool_wr_BCM_RQ_FrontWash(a)                                           {BCM_RQ_FrontWash = a;}
#define l_bool_rd_BCM_ParkPosition()                                            BCM_ParkPosition
#define l_bool_wr_BCM_ParkPosition(a)                                           {BCM_ParkPosition = a;}
#define l_u8_rd_BCM_RainSensitivity()                                       BCM_RainSensitivity
#define l_u8_wr_BCM_RainSensitivity(a)                                      {BCM_RainSensitivity = a;}
#define l_bool_rd_BCM_CMD_AutoLight()                                           BCM_CMD_AutoLight
#define l_bool_wr_BCM_CMD_AutoLight(a)                                          {BCM_CMD_AutoLight = a;}
#define l_u8_rd_Reserved()                                                  Reserved
#define l_u8_wr_Reserved(a)                                                 {Reserved = a;}
#define l_u16_rd_BCM_SPD_Vehicle()                                            (canuint16)(BCM_SPD_Vehicle_0)\
                                                                                | ((canuint16)(BCM_SPD_Vehicle_1)<<8)
#define l_u16_wr_BCM_SPD_Vehicle(a)                                           {BCM_SPD_Vehicle_0 = ((canuint8)a);\
                                                                                 BCM_SPD_Vehicle_1 = ((canuint8)a>>8);}


#endif  /* I_LIN_RLS_H */
