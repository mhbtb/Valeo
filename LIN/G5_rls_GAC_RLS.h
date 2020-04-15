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
#define cb_HANDLE_BCM_LIN1_1              8


#define cb_HANDLE_LinReqCmd_g     cb_HANDLE_LinReqCmd
#define cb_HANDLE_LinRespCmd_g    cb_HANDLE_LinRespCmd
#define cb_HANDLE_ASIC_Frame_04_g cb_HANDLE_ASIC_Frame_04
#define cb_HANDLE_ASIC_Frame_03_g cb_HANDLE_ASIC_Frame_03
#define cb_HANDLE_ASIC_Frame_02_g cb_HANDLE_ASIC_Frame_02
#define cb_HANDLE_ASIC_Frame_01_g cb_HANDLE_ASIC_Frame_01
#define cb_HANDLE_RLSs_02_g       cb_HANDLE_RLS_2
#define cb_HANDLE_RLSs_01_g       cb_HANDLE_RLS_1
#define cb_HANDLE_BCM1_LIN1_01_g  cb_HANDLE_BCM_LIN1_1

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
  canbittype                        RLS_WindShieldHum: 8;
  canbittype                        RLS_WindShieldTem: 8;
  canbittype                   RLS_SolarValueRightSns: 8;
  canbittype                    RLS_SolarValueLeftSns: 8;
  canbittype                                  unused0: 8;
  canbittype                                  unused1: 8;
  canbittype                                  unused2: 8;
  canbittype                                  unused3: 8;
} _c_RLS_2_msgType;

typedef struct {
  canbittype                             RLS_WiperSpd: 4;
  canbittype                         RLS_WiperIntTime: 3;
  canbittype                      RLS_PositionLightSt: 1;
  canbittype                        RLS_LuxValueSky_0: 8;
  canbittype                        RLS_LuxValueSky_1: 3;
  canbittype                                  unused0: 2;
  canbittype                 RLS_LuxValueHorizontal_0: 3;
  canbittype                 RLS_LuxValueHorizontal_1: 8;
  canbittype                           RLS_LightSnsSt: 1;
  canbittype                            RLS_RainSnsSt: 2;
  canbittype                     RLS_LightSwithReason: 4;
  canbittype                                  unused1: 1;
  canbittype                           RLS_LightOnReq: 1;
  canbittype                                  unused2: 1;
  canbittype                                RLS_RSErr: 1;
  canbittype                                RLS_LSErr: 1;
  canbittype                          RLS_OverTempErr: 2;
  canbittype                          RLS_OverVoltErr: 2;
  canbittype                           RLS_LINCommErr: 1;
  canbittype                        RLS_CalRainSnsErr: 1;
  canbittype                       RLS_CodeRainSnsErr: 1;
  canbittype                          RLS_SolarSnsErr: 1;
  canbittype                            RLS_HumSnsErr: 1;
  canbittype                            RLS_SignalErr: 2;
  canbittype                                  unused3: 1;
  canbittype                    RLS_AutoSRCloseReason: 3;
  canbittype                                  unused4: 5;
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
  canbittype                                BCM_KeySt: 2;
  canbittype                         BCM_APWLRMEnable: 1;
  canbittype                          BCM_ChildLockSt: 1;
  canbittype                     BCM_MasterSRCloseCmd: 2;
  canbittype                      BCM_MasterSROpenCmd: 2;
  canbittype                     BCM_DriverDoorAjarSt: 1;
  canbittype                        BCM_AnyDoorAjarSt: 1;
  canbittype                    BCM_MasterWndsOpenCmd: 2;
  canbittype                             BCS_VehSpdVD: 1;
  canbittype                             BCM_VehModel: 3;
  canbittype                             BCS_VehSpd_0: 8;
  canbittype                             BCS_VehSpd_1: 5;
  canbittype                   BCM_MasterWndsCloseCmd: 2;
  canbittype                           BCM_SpeedLight: 1;
  canbittype                  HVAC_CorrectedExterTemp: 8;
  canbittype                           BCM_ScreenType: 3;
  canbittype                               BCM_RSSens: 3;
  canbittype                             BCM_LSSens_0: 2;
  canbittype                             BCM_LSSens_1: 1;
  canbittype                                  unused0: 1;
  canbittype                         BCM_RTSWiperPark: 2;
  canbittype                             BCM_WiperCtr: 3;
  canbittype                HVAC_CorrectedExterTempVD: 1;
  canbittype                         BCM_SteerWhlType: 1;
  canbittype                            BCM_WiperType: 2;
  canbittype                    BCM_HumSensCorrection: 2;
  canbittype                                BCM_ARCSt: 1;
  canbittype                        BCM_SaleOfCountry: 1;
  canbittype                                  unused1: 1;
} _c_BCM_LIN1_1_msgType;


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
    _c_BCM_LIN1_1_msgType bcm_lin1_1;
} _c_BCM_LIN1_1_buf;


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
extern MEMORY_FAR _c_BCM_LIN1_1_buf BCM_LIN1_1;

/******************************************************************************/
/*                          Databuffer for indicationflags                    */
/******************************************************************************/

#define LinReqCmd_ind_b             uLinIndicationFlags.w[0].b0
#define l_flg_tst_LinReqCmd()       (LinReqCmd_ind_b != 0)
#define l_flg_clr_LinReqCmd()       {LinReqCmd_ind_b = 0;}
#define BCM_LIN1_1_ind_b             uLinIndicationFlags.w[0].b1
#define l_flg_tst_BCM_LIN1_1()       (BCM_LIN1_1_ind_b != 0)
#define l_flg_clr_BCM_LIN1_1()       {BCM_LIN1_1_ind_b = 0;}

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
#define RLS_WindShieldHum                                                     RLS_2.rls_2.RLS_WindShieldHum
#define RLS_WindShieldTem                                                     RLS_2.rls_2.RLS_WindShieldTem
#define RLS_SolarValueRightSns                                                RLS_2.rls_2.RLS_SolarValueRightSns
#define RLS_SolarValueLeftSns                                                 RLS_2.rls_2.RLS_SolarValueLeftSns
#define RLS_WiperSpd                                                          RLS_1.rls_1.RLS_WiperSpd
#define RLS_WiperIntTime                                                      RLS_1.rls_1.RLS_WiperIntTime
#define RLS_PositionLightSt                                                   RLS_1.rls_1.RLS_PositionLightSt
#define RLS_LuxValueSky_0                                                     RLS_1.rls_1.RLS_LuxValueSky_0
#define RLS_LuxValueSky_1                                                     RLS_1.rls_1.RLS_LuxValueSky_1
#define RLS_LuxValueSky(c)                                                    { RLS_LuxValueSky_0= (uint8)(((uint16)(c) & 0xFF));\
                                                                                RLS_LuxValueSky_1= (uint8)((((uint16)(c)>> 8)&0x07);\
                                                                              }
#define RLS_LuxValueHorizontal_0                                              RLS_1.rls_1.RLS_LuxValueHorizontal_0
#define RLS_LuxValueHorizontal_1                                              RLS_1.rls_1.RLS_LuxValueHorizontal_1
#define RLS_LuxValueHorizontal(c)                                             { RLS_LuxValueHorizontal_0= (uint8)(((uint16)(c) & 0x07));\
                                                                                RLS_LuxValueHorizontal_1= (uint8)((((uint16)(c)>> 3)&0xFF);\
                                                                              }
#define RLS_LightSnsSt                                                        RLS_1.rls_1.RLS_LightSnsSt
#define RLS_RainSnsSt                                                         RLS_1.rls_1.RLS_RainSnsSt
#define RLS_LightSwithReason                                                  RLS_1.rls_1.RLS_LightSwithReason
#define RLS_LightOnReq                                                        RLS_1.rls_1.RLS_LightOnReq
#define RLS_RSErr                                                             RLS_1.rls_1.RLS_RSErr
#define RLS_LSErr                                                             RLS_1.rls_1.RLS_LSErr
#define RLS_OverTempErr                                                       RLS_1.rls_1.RLS_OverTempErr
#define RLS_OverVoltErr                                                       RLS_1.rls_1.RLS_OverVoltErr
#define RLS_LINCommErr                                                        RLS_1.rls_1.RLS_LINCommErr
#define RLS_CalRainSnsErr                                                     RLS_1.rls_1.RLS_CalRainSnsErr
#define RLS_CodeRainSnsErr                                                    RLS_1.rls_1.RLS_CodeRainSnsErr
#define RLS_SolarSnsErr                                                       RLS_1.rls_1.RLS_SolarSnsErr
#define RLS_HumSnsErr                                                         RLS_1.rls_1.RLS_HumSnsErr
#define RLS_SignalErr                                                         RLS_1.rls_1.RLS_SignalErr
#define RLS_AutoSRCloseReason                                                 RLS_1.rls_1.RLS_AutoSRCloseReason
#define MasterReqB0                                                           LinReqCmd.linreqcmd.MasterReqB0
#define MasterReqB1                                                           LinReqCmd.linreqcmd.MasterReqB1
#define MasterReqB2                                                           LinReqCmd.linreqcmd.MasterReqB2
#define MasterReqB3                                                           LinReqCmd.linreqcmd.MasterReqB3
#define MasterReqB4                                                           LinReqCmd.linreqcmd.MasterReqB4
#define MasterReqB5                                                           LinReqCmd.linreqcmd.MasterReqB5
#define MasterReqB6                                                           LinReqCmd.linreqcmd.MasterReqB6
#define MasterReqB7                                                           LinReqCmd.linreqcmd.MasterReqB7
#define BCM_KeySt                                                             BCM_LIN1_1.bcm_lin1_1.BCM_KeySt
#define BCM_APWLRMEnable                                                      BCM_LIN1_1.bcm_lin1_1.BCM_APWLRMEnable
#define BCM_ChildLockSt                                                       BCM_LIN1_1.bcm_lin1_1.BCM_ChildLockSt
#define BCM_MasterSRCloseCmd                                                  BCM_LIN1_1.bcm_lin1_1.BCM_MasterSRCloseCmd
#define BCM_MasterSROpenCmd                                                   BCM_LIN1_1.bcm_lin1_1.BCM_MasterSROpenCmd
#define BCM_DriverDoorAjarSt                                                  BCM_LIN1_1.bcm_lin1_1.BCM_DriverDoorAjarSt
#define BCM_AnyDoorAjarSt                                                     BCM_LIN1_1.bcm_lin1_1.BCM_AnyDoorAjarSt
#define BCM_MasterWndsOpenCmd                                                 BCM_LIN1_1.bcm_lin1_1.BCM_MasterWndsOpenCmd
#define BCS_VehSpdVD                                                          BCM_LIN1_1.bcm_lin1_1.BCS_VehSpdVD
#define BCM_VehModel                                                          BCM_LIN1_1.bcm_lin1_1.BCM_VehModel
#define BCS_VehSpd_0                                                          BCM_LIN1_1.bcm_lin1_1.BCS_VehSpd_0
#define BCS_VehSpd_1                                                          BCM_LIN1_1.bcm_lin1_1.BCS_VehSpd_1
#define BCS_VehSpd(c)                                                         { BCS_VehSpd_0= (uint8)(((uint16)(c) & 0xFF));\
                                                                                BCS_VehSpd_1= (uint8)(((uint16)(c) & 0x1F) >> 8);\
                                                                              }
#define BCM_MasterWndsCloseCmd                                                BCM_LIN1_1.bcm_lin1_1.BCM_MasterWndsCloseCmd
#define BCM_SpeedLight                                                        BCM_LIN1_1.bcm_lin1_1.BCM_SpeedLight
#define HVAC_CorrectedExterTemp                                               BCM_LIN1_1.bcm_lin1_1.HVAC_CorrectedExterTemp
#define BCM_ScreenType                                                        BCM_LIN1_1.bcm_lin1_1.BCM_ScreenType
#define BCM_RSSens                                                            BCM_LIN1_1.bcm_lin1_1.BCM_RSSens
#define BCM_LSSens_0                                                          BCM_LIN1_1.bcm_lin1_1.BCM_LSSens_0
#define BCM_LSSens_1                                                          BCM_LIN1_1.bcm_lin1_1.BCM_LSSens_1
#define BCM_LSSens(c)                                                         { BCM_LSSens_0= (uint8)(((uint16)(c) & 0x03));\
                                                                                BCM_LSSens_1= (uint8)(((uint16)(c) & 0x01) >> 2);\
                                                                              }
#define BCM_RTSWiperPark                                                      BCM_LIN1_1.bcm_lin1_1.BCM_RTSWiperPark
#define BCM_WiperCtr                                                          BCM_LIN1_1.bcm_lin1_1.BCM_WiperCtr
#define HVAC_CorrectedExterTempVD                                             BCM_LIN1_1.bcm_lin1_1.HVAC_CorrectedExterTempVD
#define BCM_SteerWhlType                                                      BCM_LIN1_1.bcm_lin1_1.BCM_SteerWhlType
#define BCM_WiperType                                                         BCM_LIN1_1.bcm_lin1_1.BCM_WiperType
#define BCM_HumSensCorrection                                                 BCM_LIN1_1.bcm_lin1_1.BCM_HumSensCorrection
#define BCM_ARCSt                                                             BCM_LIN1_1.bcm_lin1_1.BCM_ARCSt
#define BCM_SaleOfCountry                                                     BCM_LIN1_1.bcm_lin1_1.BCM_SaleOfCountry
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
#define l_u8_rd_RLS_WindShieldHum()                                         RLS_WindShieldHum
#define l_u8_wr_RLS_WindShieldHum(a)                                        {RLS_WindShieldHum = a;}
#define l_u8_rd_RLS_WindShieldTem()                                         RLS_WindShieldTem
#define l_u8_wr_RLS_WindShieldTem(a)                                        {RLS_WindShieldTem = a;}
#define l_u8_rd_RLS_SolarValueRightSns()                                    RLS_SolarValueRightSns
#define l_u8_wr_RLS_SolarValueRightSns(a)                                   {RLS_SolarValueRightSns = a;}
#define l_u8_rd_RLS_SolarValueLeftSns()                                     RLS_SolarValueLeftSns
#define l_u8_wr_RLS_SolarValueLeftSns(a)                                    {RLS_SolarValueLeftSns = a;}
#define l_u8_rd_RLS_WiperSpd()                                              RLS_WiperSpd
#define l_u8_wr_RLS_WiperSpd(a)                                             {RLS_WiperSpd = a;}
#define l_u8_rd_RLS_WiperIntTime()                                          RLS_WiperIntTime
#define l_u8_wr_RLS_WiperIntTime(a)                                         {RLS_WiperIntTime = a;}
#define l_bool_rd_RLS_PositionLightSt()                                         RLS_PositionLightSt
#define l_bool_wr_RLS_PositionLightSt(a)                                        {RLS_PositionLightSt = a;}
#define l_u16_rd_RLS_LuxValueSky()                                            (canuint16)(RLS_LuxValueSky_0)\
                                                                                | ((canuint16)(RLS_LuxValueSky_1)<<8)

#define l_u16_wr_RLS_LuxValueSky(a)                                        {RLS_LuxValueSky_0 = ((canuint8)(a & 0xff));\
                                                                             RLS_LuxValueSky_1 = ((canuint8)((a & 0x700 )>>8));}                                                                                                                    
#define l_u16_rd_RLS_LuxValueHorizontal()                                     (canuint16)(RLS_LuxValueHorizontal_0)\
                                                                                | ((canuint16)(RLS_LuxValueHorizontal_1)<<3)
#define l_u16_wr_RLS_LuxValueHorizontal(a)                                         {RLS_LuxValueHorizontal_0 = (a & 0x07);\
                                                                                 RLS_LuxValueHorizontal_1 =((a>>3) & 0xff);}                                                                                                                    
#define l_bool_rd_RLS_LightSnsSt()                                              RLS_LightSnsSt
#define l_bool_wr_RLS_LightSnsSt(a)                                             {RLS_LightSnsSt = a;}
#define l_u8_rd_RLS_RainSnsSt()                                             RLS_RainSnsSt
#define l_u8_wr_RLS_RainSnsSt(a)                                            {RLS_RainSnsSt = a;}
#define l_u8_rd_RLS_LightSwithReason()                                      RLS_LightSwithReason
#define l_u8_wr_RLS_LightSwithReason(a)                                     {RLS_LightSwithReason = a;}
#define l_bool_rd_RLS_LightOnReq()                                              RLS_LightOnReq
#define l_bool_wr_RLS_LightOnReq(a)                                             {RLS_LightOnReq = a;}
#define l_bool_rd_RLS_RSErr()                                                   RLS_RSErr
#define l_bool_wr_RLS_RSErr(a)                                                  {RLS_RSErr = a;}
#define l_bool_rd_RLS_LSErr()                                                   RLS_LSErr
#define l_bool_wr_RLS_LSErr(a)                                                  {RLS_LSErr = a;}
#define l_u8_rd_RLS_OverTempErr()                                           RLS_OverTempErr
#define l_u8_wr_RLS_OverTempErr(a)                                          {RLS_OverTempErr = a;}
#define l_u8_rd_RLS_OverVoltErr()                                           RLS_OverVoltErr
#define l_u8_wr_RLS_OverVoltErr(a)                                          {RLS_OverVoltErr = a;}
#define l_bool_rd_RLS_LINCommErr()                                              RLS_LINCommErr
#define l_bool_wr_RLS_LINCommErr(a)                                             {RLS_LINCommErr = a;}
#define l_bool_rd_RLS_CalRainSnsErr()                                           RLS_CalRainSnsErr
#define l_bool_wr_RLS_CalRainSnsErr(a)                                          {RLS_CalRainSnsErr = a;}
#define l_bool_rd_RLS_CodeRainSnsErr()                                          RLS_CodeRainSnsErr
#define l_bool_wr_RLS_CodeRainSnsErr(a)                                         {RLS_CodeRainSnsErr = a;}
#define l_bool_rd_RLS_SolarSnsErr()                                             RLS_SolarSnsErr
#define l_bool_wr_RLS_SolarSnsErr(a)                                            {RLS_SolarSnsErr = a;}
#define l_bool_rd_RLS_HumSnsErr()                                               RLS_HumSnsErr
#define l_bool_wr_RLS_HumSnsErr(a)                                              {RLS_HumSnsErr = a;}
#define l_u8_rd_RLS_SignalErr()                                             RLS_SignalErr
#define l_u8_wr_RLS_SignalErr(a)                                            {RLS_SignalErr = a;}
#define l_u8_rd_RLS_AutoSRCloseReason()                                     RLS_AutoSRCloseReason
#define l_u8_wr_RLS_AutoSRCloseReason(a)                                    {RLS_AutoSRCloseReason = a;}
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
#define l_u8_rd_BCM_KeySt()                                                 BCM_KeySt
#define l_u8_wr_BCM_KeySt(a)                                                {BCM_KeySt = a;}
#define l_bool_rd_BCM_APWLRMEnable()                                            BCM_APWLRMEnable
#define l_bool_wr_BCM_APWLRMEnable(a)                                           {BCM_APWLRMEnable = a;}
#define l_bool_rd_BCM_ChildLockSt()                                             BCM_ChildLockSt
#define l_bool_wr_BCM_ChildLockSt(a)                                            {BCM_ChildLockSt = a;}
#define l_u8_rd_BCM_MasterSRCloseCmd()                                      BCM_MasterSRCloseCmd
#define l_u8_wr_BCM_MasterSRCloseCmd(a)                                     {BCM_MasterSRCloseCmd = a;}
#define l_u8_rd_BCM_MasterSROpenCmd()                                       BCM_MasterSROpenCmd
#define l_u8_wr_BCM_MasterSROpenCmd(a)                                      {BCM_MasterSROpenCmd = a;}
#define l_bool_rd_BCM_DriverDoorAjarSt()                                        BCM_DriverDoorAjarSt
#define l_bool_wr_BCM_DriverDoorAjarSt(a)                                       {BCM_DriverDoorAjarSt = a;}
#define l_bool_rd_BCM_AnyDoorAjarSt()                                           BCM_AnyDoorAjarSt
#define l_bool_wr_BCM_AnyDoorAjarSt(a)                                          {BCM_AnyDoorAjarSt = a;}
#define l_u8_rd_BCM_MasterWndsOpenCmd()                                     BCM_MasterWndsOpenCmd
#define l_u8_wr_BCM_MasterWndsOpenCmd(a)                                    {BCM_MasterWndsOpenCmd = a;}
#define l_bool_rd_BCS_VehSpdVD()                                                BCS_VehSpdVD
#define l_bool_wr_BCS_VehSpdVD(a)                                               {BCS_VehSpdVD = a;}
#define l_u8_rd_BCM_VehModel()                                              BCM_VehModel
#define l_u8_wr_BCM_VehModel(a)                                             {BCM_VehModel = a;}
#define l_u16_rd_BCS_VehSpd()                                                 (canuint16)(BCS_VehSpd_0)\
                                                                                | ((canuint16)(BCS_VehSpd_1)<<8)
#define l_u16_wr_BCS_VehSpd(a)                                                {BCS_VehSpd_0 = ((canuint8)a);\
                                                                                 BCS_VehSpd_1 = ((canuint8)a>>8);}
#define l_u8_rd_BCM_MasterWndsCloseCmd()                                    BCM_MasterWndsCloseCmd
#define l_u8_wr_BCM_MasterWndsCloseCmd(a)                                   {BCM_MasterWndsCloseCmd = a;}
#define l_bool_rd_BCM_SpeedLight()                                              BCM_SpeedLight
#define l_bool_wr_BCM_SpeedLight(a)                                             {BCM_SpeedLight = a;}
#define l_u8_rd_HVAC_CorrectedExterTemp()                                   HVAC_CorrectedExterTemp
#define l_u8_wr_HVAC_CorrectedExterTemp(a)                                  {HVAC_CorrectedExterTemp = a;}
#define l_u8_rd_BCM_ScreenType()                                            BCM_ScreenType
#define l_u8_wr_BCM_ScreenType(a)                                           {BCM_ScreenType = a;}
#define l_u8_rd_BCM_RSSens()                                                BCM_RSSens
#define l_u8_wr_BCM_RSSens(a)                                               {BCM_RSSens = a;}
#define l_u16_rd_BCM_LSSens()                                                 (canuint16)(BCM_LSSens_0)\
                                                                                | ((canuint16)(BCM_LSSens_1)<<2)
#define l_u16_wr_BCM_LSSens(a)                                                {BCM_LSSens_0 = ((canuint8)a);\
                                                                                 BCM_LSSens_1 = ((canuint8)a>>2);}
#define l_u8_rd_BCM_RTSWiperPark()                                          BCM_RTSWiperPark
#define l_u8_wr_BCM_RTSWiperPark(a)                                         {BCM_RTSWiperPark = a;}
#define l_u8_rd_BCM_WiperCtr()                                              BCM_WiperCtr
#define l_u8_wr_BCM_WiperCtr(a)                                             {BCM_WiperCtr = a;}
#define l_bool_rd_HVAC_CorrectedExterTempVD()                                   HVAC_CorrectedExterTempVD
#define l_bool_wr_HVAC_CorrectedExterTempVD(a)                                  {HVAC_CorrectedExterTempVD = a;}
#define l_bool_rd_BCM_SteerWhlType()                                            BCM_SteerWhlType
#define l_bool_wr_BCM_SteerWhlType(a)                                           {BCM_SteerWhlType = a;}
#define l_u8_rd_BCM_WiperType()                                             BCM_WiperType
#define l_u8_wr_BCM_WiperType(a)                                            {BCM_WiperType = a;}
#define l_u8_rd_BCM_HumSensCorrection()                                     BCM_HumSensCorrection
#define l_u8_wr_BCM_HumSensCorrection(a)                                    {BCM_HumSensCorrection = a;}
#define l_bool_rd_BCM_ARCSt()                                                   BCM_ARCSt
#define l_bool_wr_BCM_ARCSt(a)                                                  {BCM_ARCSt = a;}
#define l_bool_rd_BCM_SaleOfCountry()                                           BCM_SaleOfCountry
#define l_bool_wr_BCM_SaleOfCountry(a)                                          {BCM_SaleOfCountry = a;}


#endif  /* I_LIN_RLS_H */
