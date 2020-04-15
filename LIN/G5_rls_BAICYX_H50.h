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
#define cb_HANDLE_RS                      5
#define cb_HANDLE_LinReqCmd               6
#define cb_HANDLE_FBCM_ControlCommand     7


#define cb_HANDLE_ASIC_Frame_01_g cb_HANDLE_ASIC_Frame_01
#define cb_HANDLE_ASIC_Frame_02_g cb_HANDLE_ASIC_Frame_02
#define cb_HANDLE_ASIC_Frame_03_g cb_HANDLE_ASIC_Frame_03
#define cb_HANDLE_ASIC_Frame_04_g cb_HANDLE_ASIC_Frame_04
#define cb_HANDLE_RLSs_01_g cb_HANDLE_RS
#define cb_HANDLE_BCM1_LIN1_01_g cb_HANDLE_FBCM_ControlCommand
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
  canbittype                            RS_WprSpdRqst: 3;
  canbittype                                  unused0: 1;
  canbittype                               RS_RainSts: 1;
  canbittype                           RS_TwlgtLvlSts: 3;
  canbittype                              RS_RSensSts: 2;
  canbittype                       RS_OptcIntiFailSts: 1;
  canbittype                           RS_VoltFailSts: 2;
  canbittype                         RS_ResponseError: 1;
  canbittype                   RS_WndShldWashSwStsRsp: 1;
  canbittype                                  unused1: 1;
  canbittype                                  unused2: 8;
  canbittype                                  unused3: 8;
} _c_RS_msgType;


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
  canbittype                           FBCM_IGN_State: 2;
  canbittype                        FBCM_APWLRMEnable: 1;
  canbittype                                  unused0: 1;
  canbittype                           FBCM_FLDoorSts: 1;
  canbittype                           FBCM_FRDoorSts: 1;
  canbittype                           FBCM_RLDoorSts: 1;
  canbittype                           FBCM_RRDoorSts: 1;
  canbittype               FBCM_RemoteWindowFLControl: 2;
  canbittype               FBCM_RemoteWindowFRControl: 2;
  canbittype               FBCM_RemoteWindowRLControl: 2;
  canbittype               FBCM_RemoteWindowRRControl: 2;
  canbittype                     FBCM_DoorLockCommand: 3;
  canbittype                       FBCM_DoorLockkType: 5;
  canbittype               FBCM_SunroofInitializedCmd: 1;
  canbittype                   Vehicle_Model_reserved: 3;
  canbittype                     BCM_RSensSenstvtySts: 3;
  canbittype                     BCM_WndShldWashSwSts: 1;
  canbittype                       OutsideTemperature: 8;
  canbittype                           FBCM_VehSpdLgt: 8;
  canbittype                             BCM_WiperSts: 3;
  canbittype              BCM_RSSysIntlzRqst_Reserved: 1;
  canbittype                           BCM_WprPkSwSts: 2;
  canbittype                       BCM_TailGateStatus: 1;
  canbittype                   BCM_TailGateOpenStatus: 1;
  canbittype                FBCM_RemoteSunroofControl: 3;
  canbittype                      FBCM_HoodDoorStatus: 1;
  canbittype                                  unused1: 4;
} _c_FBCM_ControlCommand_msgType;


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
    _c_RS_msgType rs;
} _c_RS_buf;


/* Receive messages */

typedef union {
    unsigned char _c[8];
    _c_LinReqCmd_msgType linreqcmd;
} _c_LinReqCmd_buf;

typedef union {
    unsigned char _c[8];
    _c_FBCM_ControlCommand_msgType fbcm_controlcommand;
} _c_FBCM_ControlCommand_buf;


/******************************************************************************/
/*                          Databuffer for send objects                       */
/******************************************************************************/

extern MEMORY_FAR _c_LinRespCmd_buf LinRespCmd;
extern MEMORY_FAR _c_ASIC_Frame_04_buf ASIC_Frame_04;
extern MEMORY_FAR _c_ASIC_Frame_03_buf ASIC_Frame_03;
extern MEMORY_FAR _c_ASIC_Frame_02_buf ASIC_Frame_02;
extern MEMORY_FAR _c_ASIC_Frame_01_buf ASIC_Frame_01;
extern MEMORY_FAR _c_RS_buf RS;

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
#define RS_conf_b             uLinConfirmationFlags.w[0].b5
#define l_flg_tst_RS()       (RS_conf_b != 0)
#define l_flg_clr_RS()       {RS_conf_b = 0;}

/******************************************************************************/
/*                         Databuffer for receive objects                     */
/******************************************************************************/

extern MEMORY_FAR _c_LinReqCmd_buf LinReqCmd;
extern MEMORY_FAR _c_FBCM_ControlCommand_buf FBCM_ControlCommand;

/******************************************************************************/
/*                          Databuffer for indicationflags                    */
/******************************************************************************/

#define LinReqCmd_ind_b             uLinIndicationFlags.w[0].b0
#define l_flg_tst_LinReqCmd()       (LinReqCmd_ind_b != 0)
#define l_flg_clr_LinReqCmd()       {LinReqCmd_ind_b = 0;}
#define FBCM_ControlCommand_ind_b             uLinIndicationFlags.w[0].b1
#define l_flg_tst_FBCM_ControlCommand()       (FBCM_ControlCommand_ind_b != 0)
#define l_flg_clr_FBCM_ControlCommand()       {FBCM_ControlCommand_ind_b = 0;}

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
#define RS_WprSpdRqst                                                         RS.rs.RS_WprSpdRqst
#define RS_RainSts                                                            RS.rs.RS_RainSts
#define RS_TwlgtLvlSts                                                        RS.rs.RS_TwlgtLvlSts
#define RS_RSensSts                                                           RS.rs.RS_RSensSts
#define RS_OptcIntiFailSts                                                    RS.rs.RS_OptcIntiFailSts
#define RS_VoltFailSts                                                        RS.rs.RS_VoltFailSts
#define RS_ResponseError                                                      RS.rs.RS_ResponseError
#define RS_WndShldWashSwStsRsp                                                RS.rs.RS_WndShldWashSwStsRsp
#define MasterReqB0                                                           LinReqCmd.linreqcmd.MasterReqB0
#define MasterReqB1                                                           LinReqCmd.linreqcmd.MasterReqB1
#define MasterReqB2                                                           LinReqCmd.linreqcmd.MasterReqB2
#define MasterReqB3                                                           LinReqCmd.linreqcmd.MasterReqB3
#define MasterReqB4                                                           LinReqCmd.linreqcmd.MasterReqB4
#define MasterReqB5                                                           LinReqCmd.linreqcmd.MasterReqB5
#define MasterReqB6                                                           LinReqCmd.linreqcmd.MasterReqB6
#define MasterReqB7                                                           LinReqCmd.linreqcmd.MasterReqB7
#define FBCM_IGN_State                                                        FBCM_ControlCommand.fbcm_controlcommand.FBCM_IGN_State
#define FBCM_APWLRMEnable                                                     FBCM_ControlCommand.fbcm_controlcommand.FBCM_APWLRMEnable
#define FBCM_FLDoorSts                                                        FBCM_ControlCommand.fbcm_controlcommand.FBCM_FLDoorSts
#define FBCM_FRDoorSts                                                        FBCM_ControlCommand.fbcm_controlcommand.FBCM_FRDoorSts
#define FBCM_RLDoorSts                                                        FBCM_ControlCommand.fbcm_controlcommand.FBCM_RLDoorSts
#define FBCM_RRDoorSts                                                        FBCM_ControlCommand.fbcm_controlcommand.FBCM_RRDoorSts
#define FBCM_RemoteWindowFLControl                                            FBCM_ControlCommand.fbcm_controlcommand.FBCM_RemoteWindowFLControl
#define FBCM_RemoteWindowFRControl                                            FBCM_ControlCommand.fbcm_controlcommand.FBCM_RemoteWindowFRControl
#define FBCM_RemoteWindowRLControl                                            FBCM_ControlCommand.fbcm_controlcommand.FBCM_RemoteWindowRLControl
#define FBCM_RemoteWindowRRControl                                            FBCM_ControlCommand.fbcm_controlcommand.FBCM_RemoteWindowRRControl
#define FBCM_DoorLockCommand                                                  FBCM_ControlCommand.fbcm_controlcommand.FBCM_DoorLockCommand
#define FBCM_DoorLockkType                                                    FBCM_ControlCommand.fbcm_controlcommand.FBCM_DoorLockkType
#define FBCM_SunroofInitializedCmd                                            FBCM_ControlCommand.fbcm_controlcommand.FBCM_SunroofInitializedCmd
#define Vehicle_Model_reserved                                                FBCM_ControlCommand.fbcm_controlcommand.Vehicle_Model_reserved
#define BCM_RSensSenstvtySts                                                  FBCM_ControlCommand.fbcm_controlcommand.BCM_RSensSenstvtySts
#define BCM_WndShldWashSwSts                                                  FBCM_ControlCommand.fbcm_controlcommand.BCM_WndShldWashSwSts
#define OutsideTemperature                                                    FBCM_ControlCommand.fbcm_controlcommand.OutsideTemperature
#define FBCM_VehSpdLgt                                                        FBCM_ControlCommand.fbcm_controlcommand.FBCM_VehSpdLgt
#define BCM_WiperSts                                                          FBCM_ControlCommand.fbcm_controlcommand.BCM_WiperSts
#define BCM_RSSysIntlzRqst_Reserved                                           FBCM_ControlCommand.fbcm_controlcommand.BCM_RSSysIntlzRqst_Reserved
#define BCM_WprPkSwSts                                                        FBCM_ControlCommand.fbcm_controlcommand.BCM_WprPkSwSts
#define BCM_TailGateStatus                                                    FBCM_ControlCommand.fbcm_controlcommand.BCM_TailGateStatus
#define BCM_TailGateOpenStatus                                                FBCM_ControlCommand.fbcm_controlcommand.BCM_TailGateOpenStatus
#define FBCM_RemoteSunroofControl                                             FBCM_ControlCommand.fbcm_controlcommand.FBCM_RemoteSunroofControl
#define FBCM_HoodDoorStatus                                                   FBCM_ControlCommand.fbcm_controlcommand.FBCM_HoodDoorStatus
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
#define l_u8_rd_RS_WprSpdRqst()                                             RS_WprSpdRqst
#define l_u8_wr_RS_WprSpdRqst(a)                                            {RS_WprSpdRqst = a;}
#define l_bool_rd_RS_RainSts()                                                  RS_RainSts
#define l_bool_wr_RS_RainSts(a)                                                 {RS_RainSts = a;}
#define l_u8_rd_RS_TwlgtLvlSts()                                            RS_TwlgtLvlSts
#define l_u8_wr_RS_TwlgtLvlSts(a)                                           {RS_TwlgtLvlSts = a;}
#define l_u8_rd_RS_RSensSts()                                               RS_RSensSts
#define l_u8_wr_RS_RSensSts(a)                                              {RS_RSensSts = a;}
#define l_bool_rd_RS_OptcIntiFailSts()                                          RS_OptcIntiFailSts
#define l_bool_wr_RS_OptcIntiFailSts(a)                                         {RS_OptcIntiFailSts = a;}
#define l_u8_rd_RS_VoltFailSts()                                            RS_VoltFailSts
#define l_u8_wr_RS_VoltFailSts(a)                                           {RS_VoltFailSts = a;}
#define l_bool_rd_RS_ResponseError()                                            RS_ResponseError
#define l_bool_wr_RS_ResponseError(a)                                           {RS_ResponseError = a;}
#define l_bool_rd_RS_WndShldWashSwStsRsp()                                      RS_WndShldWashSwStsRsp
#define l_bool_wr_RS_WndShldWashSwStsRsp(a)                                     {RS_WndShldWashSwStsRsp = a;}
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
#define l_u8_rd_FBCM_IGN_State()                                            FBCM_IGN_State
#define l_u8_wr_FBCM_IGN_State(a)                                           {FBCM_IGN_State = a;}
#define l_bool_rd_FBCM_APWLRMEnable()                                           FBCM_APWLRMEnable
#define l_bool_wr_FBCM_APWLRMEnable(a)                                          {FBCM_APWLRMEnable = a;}
#define l_bool_rd_FBCM_FLDoorSts()                                              FBCM_FLDoorSts
#define l_bool_wr_FBCM_FLDoorSts(a)                                             {FBCM_FLDoorSts = a;}
#define l_bool_rd_FBCM_FRDoorSts()                                              FBCM_FRDoorSts
#define l_bool_wr_FBCM_FRDoorSts(a)                                             {FBCM_FRDoorSts = a;}
#define l_bool_rd_FBCM_RLDoorSts()                                              FBCM_RLDoorSts
#define l_bool_wr_FBCM_RLDoorSts(a)                                             {FBCM_RLDoorSts = a;}
#define l_bool_rd_FBCM_RRDoorSts()                                              FBCM_RRDoorSts
#define l_bool_wr_FBCM_RRDoorSts(a)                                             {FBCM_RRDoorSts = a;}
#define l_u8_rd_FBCM_RemoteWindowFLControl()                                FBCM_RemoteWindowFLControl
#define l_u8_wr_FBCM_RemoteWindowFLControl(a)                               {FBCM_RemoteWindowFLControl = a;}
#define l_u8_rd_FBCM_RemoteWindowFRControl()                                FBCM_RemoteWindowFRControl
#define l_u8_wr_FBCM_RemoteWindowFRControl(a)                               {FBCM_RemoteWindowFRControl = a;}
#define l_u8_rd_FBCM_RemoteWindowRLControl()                                FBCM_RemoteWindowRLControl
#define l_u8_wr_FBCM_RemoteWindowRLControl(a)                               {FBCM_RemoteWindowRLControl = a;}
#define l_u8_rd_FBCM_RemoteWindowRRControl()                                FBCM_RemoteWindowRRControl
#define l_u8_wr_FBCM_RemoteWindowRRControl(a)                               {FBCM_RemoteWindowRRControl = a;}
#define l_u8_rd_FBCM_DoorLockCommand()                                      FBCM_DoorLockCommand
#define l_u8_wr_FBCM_DoorLockCommand(a)                                     {FBCM_DoorLockCommand = a;}
#define l_u8_rd_FBCM_DoorLockkType()                                        FBCM_DoorLockkType
#define l_u8_wr_FBCM_DoorLockkType(a)                                       {FBCM_DoorLockkType = a;}
#define l_bool_rd_FBCM_SunroofInitializedCmd()                                  FBCM_SunroofInitializedCmd
#define l_bool_wr_FBCM_SunroofInitializedCmd(a)                                 {FBCM_SunroofInitializedCmd = a;}
#define l_u8_rd_Vehicle_Model_reserved()                                    Vehicle_Model_reserved
#define l_u8_wr_Vehicle_Model_reserved(a)                                   {Vehicle_Model_reserved = a;}
#define l_u8_rd_BCM_RSensSenstvtySts()                                      BCM_RSensSenstvtySts
#define l_u8_wr_BCM_RSensSenstvtySts(a)                                     {BCM_RSensSenstvtySts = a;}
#define l_bool_rd_BCM_WndShldWashSwSts()                                        BCM_WndShldWashSwSts
#define l_bool_wr_BCM_WndShldWashSwSts(a)                                       {BCM_WndShldWashSwSts = a;}
#define l_u8_rd_OutsideTemperature()                                        OutsideTemperature
#define l_u8_wr_OutsideTemperature(a)                                       {OutsideTemperature = a;}
#define l_u8_rd_FBCM_VehSpdLgt()                                            FBCM_VehSpdLgt
#define l_u8_wr_FBCM_VehSpdLgt(a)                                           {FBCM_VehSpdLgt = a;}
#define l_u8_rd_BCM_WiperSts()                                              BCM_WiperSts
#define l_u8_wr_BCM_WiperSts(a)                                             {BCM_WiperSts = a;}
#define l_bool_rd_BCM_RSSysIntlzRqst_Reserved()                                 BCM_RSSysIntlzRqst_Reserved
#define l_bool_wr_BCM_RSSysIntlzRqst_Reserved(a)                                {BCM_RSSysIntlzRqst_Reserved = a;}
#define l_u8_rd_BCM_WprPkSwSts()                                            BCM_WprPkSwSts
#define l_u8_wr_BCM_WprPkSwSts(a)                                           {BCM_WprPkSwSts = a;}
#define l_bool_rd_BCM_TailGateStatus()                                          BCM_TailGateStatus
#define l_bool_wr_BCM_TailGateStatus(a)                                         {BCM_TailGateStatus = a;}
#define l_bool_rd_BCM_TailGateOpenStatus()                                      BCM_TailGateOpenStatus
#define l_bool_wr_BCM_TailGateOpenStatus(a)                                     {BCM_TailGateOpenStatus = a;}
#define l_u8_rd_FBCM_RemoteSunroofControl()                                 FBCM_RemoteSunroofControl
#define l_u8_wr_FBCM_RemoteSunroofControl(a)                                {FBCM_RemoteSunroofControl = a;}
#define l_bool_rd_FBCM_HoodDoorStatus()                                         FBCM_HoodDoorStatus
#define l_bool_wr_FBCM_HoodDoorStatus(a)                                        {FBCM_HoodDoorStatus = a;}


#endif  /* I_LIN_RLS_H */
