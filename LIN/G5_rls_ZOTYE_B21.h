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
#define cb_HANDLE_RLS_2                   5
#define cb_HANDLE_RLS_1                   6
#define cb_HANDLE_LinReqCmd               7
#define cb_HANDLE_BDM_LIN1_1              8


#define cb_HANDLE_LinReqCmd_g     cb_HANDLE_LinReqCmd
#define cb_HANDLE_LinRespCmd_g    cb_HANDLE_LinRespCmd
#define cb_HANDLE_ASIC_Frame_04_g cb_HANDLE_ASIC_Frame_04
#define cb_HANDLE_ASIC_Frame_03_g cb_HANDLE_ASIC_Frame_03
#define cb_HANDLE_ASIC_Frame_02_g cb_HANDLE_ASIC_Frame_02
#define cb_HANDLE_ASIC_Frame_01_g cb_HANDLE_ASIC_Frame_01
#define cb_HANDLE_RLSs_02_g       cb_HANDLE_RLS_2
#define cb_HANDLE_RLSs_01_g       cb_HANDLE_RLS_1
#define cb_HANDLE_BCM1_LIN1_01_g  cb_HANDLE_BDM_LIN1_1

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
  canbittype                            RLS_SolarLeft: 8;
  canbittype                           RLS_SolarRight: 8;
  canbittype                             RLS_Humidity: 8;
  canbittype                     RLS_WindshieldTemp_0: 8;
  canbittype                     RLS_WindshieldTemp_1: 2;
  canbittype                           RLS_DewPoint_0: 6;
  canbittype                           RLS_DewPoint_1: 4;
  canbittype                                  unused0: 4;
  canbittype                      RLS_RollingCounter2: 4;
  canbittype                                  unused1: 4;
  canbittype                                  unused2: 8;
} _c_RLS_2_msgType;

typedef struct {
  canbittype                        RLS_ResponseError: 1;
  canbittype                                  unused0: 1;
  canbittype                             RLS_RS_Error: 1;
  canbittype                            RLS_RS_Splash: 1;
  canbittype                        RLS_RS_WiperSpeed: 2;
  canbittype                      RLS_RS_CloseRequest: 2;
  canbittype                                  unused1: 1;
  canbittype                             RLS_LS_Error: 1;
  canbittype                          RLS_LS_HeadLamp: 1;
  canbittype                      RLS_LS_SrBrightness: 1;
  canbittype                                  unused2: 4;
  canbittype                            RLS_LS_Global: 8;
  canbittype                                  unused3: 6;
  canbittype                         RLS_LS_Forward_0: 2;
  canbittype                         RLS_LS_Forward_1: 8;
  canbittype                         RLS_RS_RainLevel: 4;
  canbittype                                  unused4: 4;
  canbittype                      RLS_RollingCounter1: 4;
  canbittype                                  unused5: 4;
  canbittype                                  unused6: 8;
} _c_RLS_1_msgType;


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
  canbittype                       BDM_LIN1_PowerMode: 4;
  canbittype                      BDM_LIN1_WindowOpen: 1;
  canbittype                                  unused0: 3;
  canbittype                   BDM_LIN1_SgControlType: 2;
  canbittype                  BDM_LIN1_SgOpenPosition: 3;
  canbittype                                  unused1: 3;
  canbittype                   BDM_LIN1_ScControlType: 2;
  canbittype               BDM_LIN1_ScOpeningPosition: 3;
  canbittype                                  unused2: 3;
  canbittype            BDM_LIN1_WM_WiperHomePosition: 1;
  canbittype                      BDM_LIN1_WashStatus: 1;
  canbittype                  BDM_LIN1_RS_Sensitivity: 3;
  canbittype                            BDM_LIN1_SCCM: 3;
  canbittype                  BDM_LIN1_VehicleSpeed_0: 8;
  canbittype                  BDM_LIN1_VehicleSpeed_1: 5;
  canbittype                                  unused3: 3;
  canbittype                 BDM_LIN1_RollingCounter1: 4;
  canbittype                                  unused4: 4;
  canbittype                       BDM_LIN1_CheckSum1: 8;
} _c_BDM_LIN1_1_msgType;


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
    _c_RLS_2_msgType rls_2;
} _c_RLS_2_buf;

typedef union {
    unsigned char _c[8];
    _c_RLS_1_msgType rls_1;
} _c_RLS_1_buf;


/* Receive messages */

typedef union {
    unsigned char _c[8];
    _c_LinReqCmd_msgType linreqcmd;
} _c_LinReqCmd_buf;

typedef union {
    unsigned char _c[8];
    _c_BDM_LIN1_1_msgType bdm_lin1_1;
} _c_BDM_LIN1_1_buf;


/******************************************************************************/
/*                          Databuffer for send objects                       */
/******************************************************************************/

extern MEMORY_FAR _c_LinRespCmd_buf LinRespCmd;
extern MEMORY_FAR _c_ASIC_Frame_04_buf ASIC_Frame_04;
extern MEMORY_FAR _c_ASIC_Frame_03_buf ASIC_Frame_03;
extern MEMORY_FAR _c_ASIC_Frame_02_buf ASIC_Frame_02;
extern MEMORY_FAR _c_ASIC_Frame_01_buf ASIC_Frame_01;
extern MEMORY_FAR _c_RLS_2_buf RLS_2;
extern MEMORY_FAR _c_RLS_1_buf RLS_1;

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
#define RLS_2_conf_b             uLinConfirmationFlags.w[0].b5
#define l_flg_tst_RLS_2()       (RLS_2_conf_b != 0)
#define l_flg_clr_RLS_2()       {RLS_2_conf_b = 0;}
#define RLS_1_conf_b             uLinConfirmationFlags.w[0].b6
#define l_flg_tst_RLS_1()       (RLS_1_conf_b != 0)
#define l_flg_clr_RLS_1()       {RLS_1_conf_b = 0;}

/******************************************************************************/
/*                         Databuffer for receive objects                     */
/******************************************************************************/

extern MEMORY_FAR _c_LinReqCmd_buf LinReqCmd;
extern MEMORY_FAR _c_BDM_LIN1_1_buf BDM_LIN1_1;

/******************************************************************************/
/*                          Databuffer for indicationflags                    */
/******************************************************************************/

#define LinReqCmd_ind_b             uLinIndicationFlags.w[0].b0
#define l_flg_tst_LinReqCmd()       (LinReqCmd_ind_b != 0)
#define l_flg_clr_LinReqCmd()       {LinReqCmd_ind_b = 0;}
#define BDM_LIN1_1_ind_b             uLinIndicationFlags.w[0].b1
#define l_flg_tst_BDM_LIN1_1()       (BDM_LIN1_1_ind_b != 0)
#define l_flg_clr_BDM_LIN1_1()       {BDM_LIN1_1_ind_b = 0;}

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
#define RLS_SolarLeft                                                         RLS_2.rls_2.RLS_SolarLeft
#define RLS_SolarRight                                                        RLS_2.rls_2.RLS_SolarRight
#define RLS_Humidity                                                          RLS_2.rls_2.RLS_Humidity
#define RLS_WindshieldTemp_0                                                  RLS_2.rls_2.RLS_WindshieldTemp_0
#define RLS_WindshieldTemp_1                                                  RLS_2.rls_2.RLS_WindshieldTemp_1
#define RLS_WindshieldTemp(c)                                                 { RLS_WindshieldTemp_0= (uint8)(((uint16)(c) & 0xFF));\
                                                                                RLS_WindshieldTemp_1= (uint8)(((uint16)(c) & 0x03) >> 8);\
                                                                              }
#define RLS_DewPoint_0                                                        RLS_2.rls_2.RLS_DewPoint_0
#define RLS_DewPoint_1                                                        RLS_2.rls_2.RLS_DewPoint_1
#define RLS_DewPoint(c)                                                       { RLS_DewPoint_0= (uint8)(((uint16)(c) & 0x3F));\
                                                                                RLS_DewPoint_1= (uint8)(((uint16)(c) & 0x0F) >> 6);\
                                                                              }
#define RLS_RollingCounter2                                                   RLS_2.rls_2.RLS_RollingCounter2
#define RLS_ResponseError                                                     RLS_1.rls_1.RLS_ResponseError
#define RLS_RS_Error                                                          RLS_1.rls_1.RLS_RS_Error
#define RLS_RS_Splash                                                         RLS_1.rls_1.RLS_RS_Splash
#define RLS_RS_WiperSpeed                                                     RLS_1.rls_1.RLS_RS_WiperSpeed
#define RLS_RS_CloseRequest                                                   RLS_1.rls_1.RLS_RS_CloseRequest
#define RLS_LS_Error                                                          RLS_1.rls_1.RLS_LS_Error
#define RLS_LS_HeadLamp                                                       RLS_1.rls_1.RLS_LS_HeadLamp
#define RLS_LS_SrBrightness                                                   RLS_1.rls_1.RLS_LS_SrBrightness
#define RLS_LS_Global                                                         RLS_1.rls_1.RLS_LS_Global
#define RLS_LS_Forward_0                                                      RLS_1.rls_1.RLS_LS_Forward_0
#define RLS_LS_Forward_1                                                      RLS_1.rls_1.RLS_LS_Forward_1
#define RLS_LS_Forward(c)                                                     { RLS_LS_Forward_0= (uint8)(((uint16)(c) & 0x03));\
                                                                                RLS_LS_Forward_1= (uint8)(((uint16)(c) & 0xFF) >> 2);\
                                                                              }
#define RLS_RS_RainLevel                                                      RLS_1.rls_1.RLS_RS_RainLevel
#define RLS_RollingCounter1                                                   RLS_1.rls_1.RLS_RollingCounter1
#define MasterReqB0                                                           LinReqCmd.linreqcmd.MasterReqB0
#define MasterReqB1                                                           LinReqCmd.linreqcmd.MasterReqB1
#define MasterReqB2                                                           LinReqCmd.linreqcmd.MasterReqB2
#define MasterReqB3                                                           LinReqCmd.linreqcmd.MasterReqB3
#define MasterReqB4                                                           LinReqCmd.linreqcmd.MasterReqB4
#define MasterReqB5                                                           LinReqCmd.linreqcmd.MasterReqB5
#define MasterReqB6                                                           LinReqCmd.linreqcmd.MasterReqB6
#define MasterReqB7                                                           LinReqCmd.linreqcmd.MasterReqB7
#define BDM_LIN1_PowerMode                                                    BDM_LIN1_1.bdm_lin1_1.BDM_LIN1_PowerMode
#define BDM_LIN1_WindowOpen                                                   BDM_LIN1_1.bdm_lin1_1.BDM_LIN1_WindowOpen
#define BDM_LIN1_SgControlType                                                BDM_LIN1_1.bdm_lin1_1.BDM_LIN1_SgControlType
#define BDM_LIN1_SgOpenPosition                                               BDM_LIN1_1.bdm_lin1_1.BDM_LIN1_SgOpenPosition
#define BDM_LIN1_ScControlType                                                BDM_LIN1_1.bdm_lin1_1.BDM_LIN1_ScControlType
#define BDM_LIN1_ScOpeningPosition                                            BDM_LIN1_1.bdm_lin1_1.BDM_LIN1_ScOpeningPosition
#define BDM_LIN1_WM_WiperHomePosition                                         BDM_LIN1_1.bdm_lin1_1.BDM_LIN1_WM_WiperHomePosition
#define BDM_LIN1_WashStatus                                                   BDM_LIN1_1.bdm_lin1_1.BDM_LIN1_WashStatus
#define BDM_LIN1_RS_Sensitivity                                               BDM_LIN1_1.bdm_lin1_1.BDM_LIN1_RS_Sensitivity
#define BDM_LIN1_SCCM                                                         BDM_LIN1_1.bdm_lin1_1.BDM_LIN1_SCCM
#define BDM_LIN1_VehicleSpeed_0                                               BDM_LIN1_1.bdm_lin1_1.BDM_LIN1_VehicleSpeed_0
#define BDM_LIN1_VehicleSpeed_1                                               BDM_LIN1_1.bdm_lin1_1.BDM_LIN1_VehicleSpeed_1
#define BDM_LIN1_VehicleSpeed(c)                                              { BDM_LIN1_VehicleSpeed_0= (uint8)(((uint16)(c) & 0xFF));\
                                                                                BDM_LIN1_VehicleSpeed_1= (uint8)(((uint16)(c) & 0x1F) >> 8);\
                                                                              }
#define BDM_LIN1_RollingCounter1                                              BDM_LIN1_1.bdm_lin1_1.BDM_LIN1_RollingCounter1
#define BDM_LIN1_CheckSum1                                                    BDM_LIN1_1.bdm_lin1_1.BDM_LIN1_CheckSum1
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
#define l_u8_rd_RLS_SolarLeft()                                             RLS_SolarLeft
#define l_u8_wr_RLS_SolarLeft(a)                                            {RLS_SolarLeft = a;}
#define l_u8_rd_RLS_SolarRight()                                            RLS_SolarRight
#define l_u8_wr_RLS_SolarRight(a)                                           {RLS_SolarRight = a;}
#define l_u8_rd_RLS_Humidity()                                              RLS_Humidity
#define l_u8_wr_RLS_Humidity(a)                                             {RLS_Humidity = a;}
#define l_u16_rd_RLS_WindshieldTemp()                                         (canuint16)(RLS_WindshieldTemp_0)\
                                                                                | ((canuint16)(RLS_WindshieldTemp_1)<<8)
#define l_u16_wr_RLS_WindshieldTemp(a)                                          {RLS_WindshieldTemp_0 = (a & 0XFF);\
                                                                                 RLS_WindshieldTemp_1 = ((a>>8) & 0X03);}
#define l_u16_rd_RLS_DewPoint()                                               (canuint16)(RLS_DewPoint_0)\
                                                                                | ((canuint16)(RLS_DewPoint_1)<<6)
#define l_u16_wr_RLS_DewPoint(a)                                                {RLS_DewPoint_0 = (a & 0X3F);\
                                                                                 RLS_DewPoint_1 = ((a>>6) & 0X0F);}
#define l_u8_rd_RLS_RollingCounter2()                                       RLS_RollingCounter2
#define l_u8_wr_RLS_RollingCounter2(a)                                      {RLS_RollingCounter2 = a;}
#define l_bool_rd_RLS_ResponseError()                                           RLS_ResponseError
#define l_bool_wr_RLS_ResponseError(a)                                          {RLS_ResponseError = a;}
#define l_bool_rd_RLS_RS_Error()                                                RLS_RS_Error
#define l_bool_wr_RLS_RS_Error(a)                                               {RLS_RS_Error = a;}
#define l_bool_rd_RLS_RS_Splash()                                               RLS_RS_Splash
#define l_bool_wr_RLS_RS_Splash(a)                                              {RLS_RS_Splash = a;}
#define l_u8_rd_RLS_RS_WiperSpeed()                                         RLS_RS_WiperSpeed
#define l_u8_wr_RLS_RS_WiperSpeed(a)                                        {RLS_RS_WiperSpeed = a;}
#define l_u8_rd_RLS_RS_CloseRequest()                                       RLS_RS_CloseRequest
#define l_u8_wr_RLS_RS_CloseRequest(a)                                      {RLS_RS_CloseRequest = a;}
#define l_bool_rd_RLS_LS_Error()                                                RLS_LS_Error
#define l_bool_wr_RLS_LS_Error(a)                                               {RLS_LS_Error = a;}
#define l_bool_rd_RLS_LS_HeadLamp()                                             RLS_LS_HeadLamp
#define l_bool_wr_RLS_LS_HeadLamp(a)                                            {RLS_LS_HeadLamp = a;}
#define l_bool_rd_RLS_LS_SrBrightness()                                         RLS_LS_SrBrightness
#define l_bool_wr_RLS_LS_SrBrightness(a)                                        {RLS_LS_SrBrightness = a;}
#define l_u8_rd_RLS_LS_Global()                                             RLS_LS_Global
#define l_u8_wr_RLS_LS_Global(a)                                            {RLS_LS_Global = a;}
#define l_u16_rd_RLS_LS_Forward()                                             (canuint16)(RLS_LS_Forward_0)\
                                                                                | ((canuint16)(RLS_LS_Forward_1)<<2)
#define l_u16_wr_RLS_LS_Forward(a)                                                {RLS_LS_Forward_0 = (a & 0X03);\
                                                                                 RLS_LS_Forward_1 = ((a>>2) & 0XFF);}
#define l_u8_rd_RLS_RS_RainLevel()                                          RLS_RS_RainLevel
#define l_u8_wr_RLS_RS_RainLevel(a)                                         {RLS_RS_RainLevel = a;}
#define l_u8_rd_RLS_RollingCounter1()                                       RLS_RollingCounter1
#define l_u8_wr_RLS_RollingCounter1(a)                                      {RLS_RollingCounter1 = a;}
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
#define l_u8_rd_BDM_LIN1_PowerMode()                                        BDM_LIN1_PowerMode
#define l_u8_wr_BDM_LIN1_PowerMode(a)                                       {BDM_LIN1_PowerMode = a;}
#define l_bool_rd_BDM_LIN1_WindowOpen()                                         BDM_LIN1_WindowOpen
#define l_bool_wr_BDM_LIN1_WindowOpen(a)                                        {BDM_LIN1_WindowOpen = a;}
#define l_u8_rd_BDM_LIN1_SgControlType()                                    BDM_LIN1_SgControlType
#define l_u8_wr_BDM_LIN1_SgControlType(a)                                   {BDM_LIN1_SgControlType = a;}
#define l_u8_rd_BDM_LIN1_SgOpenPosition()                                   BDM_LIN1_SgOpenPosition
#define l_u8_wr_BDM_LIN1_SgOpenPosition(a)                                  {BDM_LIN1_SgOpenPosition = a;}
#define l_u8_rd_BDM_LIN1_ScControlType()                                    BDM_LIN1_ScControlType
#define l_u8_wr_BDM_LIN1_ScControlType(a)                                   {BDM_LIN1_ScControlType = a;}
#define l_u8_rd_BDM_LIN1_ScOpeningPosition()                                BDM_LIN1_ScOpeningPosition
#define l_u8_wr_BDM_LIN1_ScOpeningPosition(a)                               {BDM_LIN1_ScOpeningPosition = a;}
#define l_bool_rd_BDM_LIN1_WM_WiperHomePosition()                               BDM_LIN1_WM_WiperHomePosition
#define l_bool_wr_BDM_LIN1_WM_WiperHomePosition(a)                              {BDM_LIN1_WM_WiperHomePosition = a;}
#define l_bool_rd_BDM_LIN1_WashStatus()                                         BDM_LIN1_WashStatus
#define l_bool_wr_BDM_LIN1_WashStatus(a)                                        {BDM_LIN1_WashStatus = a;}
#define l_u8_rd_BDM_LIN1_RS_Sensitivity()                                   BDM_LIN1_RS_Sensitivity
#define l_u8_wr_BDM_LIN1_RS_Sensitivity(a)                                  {BDM_LIN1_RS_Sensitivity = a;}
#define l_u8_rd_BDM_LIN1_SCCM()                                             BDM_LIN1_SCCM
#define l_u8_wr_BDM_LIN1_SCCM(a)                                            {BDM_LIN1_SCCM = a;}
#define l_u16_rd_BDM_LIN1_VehicleSpeed()                                      (canuint16)(BDM_LIN1_VehicleSpeed_0)\
                                                                                | ((canuint16)(BDM_LIN1_VehicleSpeed_1)<<8)
#define l_u16_wr_BDM_LIN1_VehicleSpeed(a)                                     {BDM_LIN1_VehicleSpeed_0 = ((canuint8)a);\
                                                                                 BDM_LIN1_VehicleSpeed_1 = ((canuint8)a>>8);}
#define l_u8_rd_BDM_LIN1_RollingCounter1()                                  BDM_LIN1_RollingCounter1
#define l_u8_wr_BDM_LIN1_RollingCounter1(a)                                 {BDM_LIN1_RollingCounter1 = a;}
#define l_u8_rd_BDM_LIN1_CheckSum1()                                        BDM_LIN1_CheckSum1
#define l_u8_wr_BDM_LIN1_CheckSum1(a)                                       {BDM_LIN1_CheckSum1 = a;}


#endif  /* I_LIN_RLS_H */
