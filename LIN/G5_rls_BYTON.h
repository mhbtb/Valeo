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
#define cb_HANDLE_BCM_Status              8

#define cb_HANDLE_LinReqCmd_g     cb_HANDLE_LinReqCmd
#define cb_HANDLE_LinRespCmd_g    cb_HANDLE_LinRespCmd
#define cb_HANDLE_ASIC_Frame_01_g cb_HANDLE_ASIC_Frame_01
#define cb_HANDLE_ASIC_Frame_02_g cb_HANDLE_ASIC_Frame_02
#define cb_HANDLE_ASIC_Frame_03_g cb_HANDLE_ASIC_Frame_03
#define cb_HANDLE_ASIC_Frame_04_g cb_HANDLE_ASIC_Frame_04
#define cb_HANDLE_RLSs_01_g       cb_HANDLE_RLS_01
#define cb_HANDLE_RLSs_02_g       cb_HANDLE_RLS_02
#define cb_HANDLE_BCM1_LIN1_01_g  cb_HANDLE_BCM_Status
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
  canbittype                 RLS_DewPointTemp_Value_0: 8;
  canbittype                 RLS_DewPointTemp_Value_1: 2;
  canbittype                 RLS_WinGlassTemp_Value_0: 6;
  canbittype                 RLS_WinGlassTemp_Value_1: 2;
  canbittype             RLS_RelativeHumidity_value_0: 6;
  canbittype             RLS_RelativeHumidity_value_1: 2;
  canbittype               RLS_PassgSideSolar_Value_0: 6;
  canbittype               RLS_PassgSideSolar_Value_1: 2;
  canbittype               RLS_DriveSideSolar_Value_0: 6;
  canbittype               RLS_DriveSideSolar_Value_1: 2;
  canbittype                                  unused0: 6;
  canbittype                                  unused1: 8;
  canbittype                                  unused2: 8;
} _c_RLS_02_msgType;

typedef struct {
  canbittype                           RLS_WiperSpeed: 2;
  canbittype                      RLS_RainSensorFault: 1;
  canbittype                       RLS_WindowCloseReq: 1;
  canbittype                     RLS_LightSensorFault: 1;
  canbittype                         RLS_LowBeamOnReq: 1;
  canbittype                            RLS_VoltFault: 2;
  canbittype                        RLS_ResponseError: 1;
  canbittype                        RLS_RainIntensity: 4;
  canbittype                                  unused0: 3;
  canbittype                       RLS_FwBrightness_0: 8;
  canbittype                       RLS_FwBrightness_1: 3;
  canbittype                                  unused1: 5;
  canbittype                      RLS_AmbBrightness_0: 8;
  canbittype                      RLS_AmbBrightness_1: 3;
  canbittype                                  unused2: 5;
  canbittype                         RLS_IRBrightness: 8;
  canbittype                                  unused3: 8;
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
  canbittype                    BCM_WiperParkPosition: 1;
  canbittype                    BCM_WiperSwitchStatus: 4;
  canbittype                    BCM_FrontWasherStatus: 1;
  canbittype                         BCM_WindowStatus: 1;
  canbittype                                  unused0: 1;
  canbittype                            BCM_PowerMode: 2;
  canbittype                                  unused1: 1;
  canbittype                      BCM_RainSensitivity: 3;
  canbittype                                  unused2: 2;
  canbittype                       BCM_VehicleSpeed_0: 8;
  canbittype                       BCM_VehicleSpeed_1: 5;
  canbittype                    BCM_VehicleSpeedValid: 1;
  canbittype                                  unused3: 2;
  canbittype                   BCM_500nmTransimission: 7;
  canbittype                                  unused4: 1;
  canbittype                   BCM_800nmTransimission: 7;
  canbittype                                  unused5: 1;
  canbittype                                  unused6: 8;
  canbittype                                  unused7: 8;
} _c_BCM_Status_msgType;


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
    _c_BCM_Status_msgType bcm_status;
} _c_BCM_Status_buf;


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
extern MEMORY_FAR _c_BCM_Status_buf BCM_Status;

/******************************************************************************/
/*                          Databuffer for indicationflags                    */
/******************************************************************************/

#define LinReqCmd_ind_b             uLinIndicationFlags.w[0].b0
#define l_flg_tst_LinReqCmd()       (LinReqCmd_ind_b != 0)
#define l_flg_clr_LinReqCmd()       {LinReqCmd_ind_b = 0;}
#define BCM_Status_ind_b             uLinIndicationFlags.w[0].b1
#define l_flg_tst_BCM_Status()       (BCM_Status_ind_b != 0)
#define l_flg_clr_BCM_Status()       {BCM_Status_ind_b = 0;}

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
#define RLS_DewPointTemp_Value_0                                              RLS_02.rls_02.RLS_DewPointTemp_Value_0
#define RLS_DewPointTemp_Value_1                                              RLS_02.rls_02.RLS_DewPointTemp_Value_1
#define RLS_DewPointTemp_Value(c)                                             { RLS_DewPointTemp_Value_0= (uint8)(((uint16)(c) & 0xFF));\
                                                                                RLS_DewPointTemp_Value_1= (uint8)(((uint16)(c) & 0x03) >> 8);\
                                                                              }
#define RLS_WinGlassTemp_Value_0                                              RLS_02.rls_02.RLS_WinGlassTemp_Value_0
#define RLS_WinGlassTemp_Value_1                                              RLS_02.rls_02.RLS_WinGlassTemp_Value_1
#define RLS_WinGlassTemp_Value(c)                                             { RLS_WinGlassTemp_Value_0= (uint8)(((uint16)(c) & 0x3F));\
                                                                                RLS_WinGlassTemp_Value_1= (uint8)(((uint16)(c) & 0x03) >> 6);\
                                                                              }
#define RLS_RelativeHumidity_value_0                                          RLS_02.rls_02.RLS_RelativeHumidity_value_0
#define RLS_RelativeHumidity_value_1                                          RLS_02.rls_02.RLS_RelativeHumidity_value_1
#define RLS_RelativeHumidity_value(c)                                         { RLS_RelativeHumidity_value_0= (uint8)(((uint16)(c) & 0x3F));\
                                                                                RLS_RelativeHumidity_value_1= (uint8)(((uint16)(c) & 0x03) >> 6);\
                                                                              }
#define RLS_PassgSideSolar_Value_0                                            RLS_02.rls_02.RLS_PassgSideSolar_Value_0
#define RLS_PassgSideSolar_Value_1                                            RLS_02.rls_02.RLS_PassgSideSolar_Value_1
#define RLS_PassgSideSolar_Value(c)                                           { RLS_PassgSideSolar_Value_0= (uint8)(((uint16)(c) & 0x3F));\
                                                                                RLS_PassgSideSolar_Value_1= (uint8)(((uint16)(c) & 0x03) >> 6);\
                                                                              }
#define RLS_DriveSideSolar_Value_0                                            RLS_02.rls_02.RLS_DriveSideSolar_Value_0
#define RLS_DriveSideSolar_Value_1                                            RLS_02.rls_02.RLS_DriveSideSolar_Value_1
#define RLS_DriveSideSolar_Value(c)                                           { RLS_DriveSideSolar_Value_0= (uint8)(((uint16)(c) & 0x3F));\
                                                                                RLS_DriveSideSolar_Value_1= (uint8)(((uint16)(c) & 0x03) >> 6);\
                                                                              }
#define RLS_WiperSpeed                                                        RLS_01.rls_01.RLS_WiperSpeed
#define RLS_RainSensorFault                                                   RLS_01.rls_01.RLS_RainSensorFault
#define RLS_WindowCloseReq                                                    RLS_01.rls_01.RLS_WindowCloseReq
#define RLS_LightSensorFault                                                  RLS_01.rls_01.RLS_LightSensorFault
#define RLS_LowBeamOnReq                                                      RLS_01.rls_01.RLS_LowBeamOnReq
#define RLS_VoltFault                                                         RLS_01.rls_01.RLS_VoltFault
#define RLS_ResponseError                                                     RLS_01.rls_01.RLS_ResponseError
#define RLS_RainIntensity                                                     RLS_01.rls_01.RLS_RainIntensity
#define RLS_FwBrightness_0                                                    RLS_01.rls_01.RLS_FwBrightness_0
#define RLS_FwBrightness_1                                                    RLS_01.rls_01.RLS_FwBrightness_1
#define RLS_FwBrightness(c)                                                   { RLS_FwBrightness_0= (uint8)(((uint16)(c) & 0xFF));\
                                                                                RLS_FwBrightness_1= (uint8)(((uint16)(c) & 0x07) >> 8);\
                                                                              }
#define RLS_AmbBrightness_0                                                   RLS_01.rls_01.RLS_AmbBrightness_0
#define RLS_AmbBrightness_1                                                   RLS_01.rls_01.RLS_AmbBrightness_1
#define RLS_AmbBrightness(c)                                                  { RLS_AmbBrightness_0= (uint8)(((uint16)(c) & 0xFF));\
                                                                                RLS_AmbBrightness_1= (uint8)(((uint16)(c) & 0x07) >> 8);\
                                                                              }
#define RLS_IRBrightness                                                      RLS_01.rls_01.RLS_IRBrightness
#define MasterReqB0                                                           LinReqCmd.linreqcmd.MasterReqB0
#define MasterReqB1                                                           LinReqCmd.linreqcmd.MasterReqB1
#define MasterReqB2                                                           LinReqCmd.linreqcmd.MasterReqB2
#define MasterReqB3                                                           LinReqCmd.linreqcmd.MasterReqB3
#define MasterReqB4                                                           LinReqCmd.linreqcmd.MasterReqB4
#define MasterReqB5                                                           LinReqCmd.linreqcmd.MasterReqB5
#define MasterReqB6                                                           LinReqCmd.linreqcmd.MasterReqB6
#define MasterReqB7                                                           LinReqCmd.linreqcmd.MasterReqB7
#define BCM_WiperParkPosition                                                 BCM_Status.bcm_status.BCM_WiperParkPosition
#define BCM_WiperSwitchStatus                                                 BCM_Status.bcm_status.BCM_WiperSwitchStatus
#define BCM_FrontWasherStatus                                                 BCM_Status.bcm_status.BCM_FrontWasherStatus
#define BCM_WindowStatus                                                      BCM_Status.bcm_status.BCM_WindowStatus
#define BCM_PowerMode                                                         BCM_Status.bcm_status.BCM_PowerMode
#define BCM_RainSensitivity                                                   BCM_Status.bcm_status.BCM_RainSensitivity
#define BCM_VehicleSpeed_0                                                    BCM_Status.bcm_status.BCM_VehicleSpeed_0
#define BCM_VehicleSpeed_1                                                    BCM_Status.bcm_status.BCM_VehicleSpeed_1
#define BCM_VehicleSpeed(c)                                                   { BCM_VehicleSpeed_0= (uint8)(((uint16)(c) & 0xFF));\
                                                                                BCM_VehicleSpeed_1= (uint8)(((uint16)(c) & 0x1F) >> 8);\
                                                                              }
#define BCM_VehicleSpeedValid                                                 BCM_Status.bcm_status.BCM_VehicleSpeedValid
#define BCM_500nmTransimission                                                BCM_Status.bcm_status.BCM_500nmTransimission
#define BCM_800nmTransimission                                                BCM_Status.bcm_status.BCM_800nmTransimission
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
#define l_u16_rd_RLS_DewPointTemp_Value()                                     (canuint16)(RLS_DewPointTemp_Value_0)\
                                                                                | ((canuint16)(RLS_DewPointTemp_Value_1)<<8)
#define l_u16_wr_RLS_DewPointTemp_Value(a)                                    {RLS_DewPointTemp_Value_0 = ((canuint8)(a & 0xff));\
                                                                                 RLS_DewPointTemp_Value_1 = (((a>>8) & 0x03));}
#define l_u8_rd_RLS_WinGlassTemp_Value()                                     (canuint16)(RLS_WinGlassTemp_Value_0)\
                                                                                | ((canuint16)(RLS_WinGlassTemp_Value_1)<<6)
#define l_u8_wr_RLS_WinGlassTemp_Value(a)                                    {RLS_WinGlassTemp_Value_0 = ((a) & 0x3f);\
                                                                                 RLS_WinGlassTemp_Value_1 = ((a>>6) & 0x03);}
#define l_u8_rd_RLS_RelativeHumidity_value()                                 (canuint8)(RLS_RelativeHumidity_value_0)\
                                                                                | ((canuint8)(RLS_RelativeHumidity_value_1)<<6)
#define l_u8_wr_RLS_RelativeHumidity_value(a)                                {RLS_RelativeHumidity_value_0 = (a & 0x3f);\
                                                                                 RLS_RelativeHumidity_value_1 = ((a>>6) & 0x03);}
#define l_u8_rd_RLS_PassgSideSolar_Value()                                   (canuint8)(RLS_PassgSideSolar_Value_0)\
                                                                                | ((canuint8)(RLS_PassgSideSolar_Value_1)<<6)
#define l_u8_wr_RLS_PassgSideSolar_Value(a)                                  {RLS_PassgSideSolar_Value_0 = (0x3f & a);\
                                                                                 RLS_PassgSideSolar_Value_1 = ((a>>6) & 0x03);}
#define l_u8_rd_RLS_DriveSideSolar_Value()                                   (canuint8)(RLS_DriveSideSolar_Value_0)\
                                                                                | ((canuint8)(RLS_DriveSideSolar_Value_1)<<6)
#define l_u8_wr_RLS_DriveSideSolar_Value(a)                                  {RLS_DriveSideSolar_Value_0 = (a & 0x3f);\
                                                                                 RLS_DriveSideSolar_Value_1 = ((a>>6) & 0x03);}
#define l_u8_rd_RLS_WiperSpeed()                                            RLS_WiperSpeed
#define l_u8_wr_RLS_WiperSpeed(a)                                           {RLS_WiperSpeed = a;}
#define l_bool_rd_RLS_RainSensorFault()                                         RLS_RainSensorFault
#define l_bool_wr_RLS_RainSensorFault(a)                                        {RLS_RainSensorFault = a;}
#define l_bool_rd_RLS_WindowCloseReq()                                          RLS_WindowCloseReq
#define l_bool_wr_RLS_WindowCloseReq(a)                                         {RLS_WindowCloseReq = a;}
#define l_bool_rd_RLS_LightSensorFault()                                        RLS_LightSensorFault
#define l_bool_wr_RLS_LightSensorFault(a)                                       {RLS_LightSensorFault = a;}
#define l_bool_rd_RLS_LowBeamOnReq()                                            RLS_LowBeamOnReq
#define l_bool_wr_RLS_LowBeamOnReq(a)                                           {RLS_LowBeamOnReq = a;}
#define l_u8_rd_RLS_VoltFault()                                             RLS_VoltFault
#define l_u8_wr_RLS_VoltFault(a)                                            {RLS_VoltFault = a;}
#define l_bool_rd_RLS_ResponseError()                                           RLS_ResponseError
#define l_bool_wr_RLS_ResponseError(a)                                          {RLS_ResponseError = a;}
#define l_u8_rd_RLS_RainIntensity()                                         RLS_RainIntensity
#define l_u8_wr_RLS_RainIntensity(a)                                        {RLS_RainIntensity = a;}
#define l_u16_rd_RLS_FwBrightness()                                           (canuint16)(RLS_FwBrightness_0)\
                                                                                | ((canuint16)(RLS_FwBrightness_1)<<8)
#define l_u16_wr_RLS_FwBrightness(a)                                          {RLS_FwBrightness_0 = (a & 0xff);\
                                                                                 RLS_FwBrightness_1 = ((a>>8) & 0x07);}
#define l_u16_rd_RLS_AmbBrightness()                                          (canuint16)(RLS_AmbBrightness_0)\
                                                                                | ((canuint16)(RLS_AmbBrightness_1)<<8)
#define l_u16_wr_RLS_AmbBrightness(a)                                         {RLS_AmbBrightness_0 = (a & 0xff);\
                                                                                 RLS_AmbBrightness_1 = ((a>>8) & 0x07);}
#define l_u8_rd_RLS_IRBrightness()                                          RLS_IRBrightness
#define l_u8_wr_RLS_IRBrightness(a)                                         {RLS_IRBrightness = a;}
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
#define l_bool_rd_BCM_WiperParkPosition()                                       BCM_WiperParkPosition
#define l_bool_wr_BCM_WiperParkPosition(a)                                      {BCM_WiperParkPosition = a;}
#define l_u8_rd_BCM_WiperSwitchStatus()                                     BCM_WiperSwitchStatus
#define l_u8_wr_BCM_WiperSwitchStatus(a)                                    {BCM_WiperSwitchStatus = a;}
#define l_bool_rd_BCM_FrontWasherStatus()                                       BCM_FrontWasherStatus
#define l_bool_wr_BCM_FrontWasherStatus(a)                                      {BCM_FrontWasherStatus = a;}
#define l_bool_rd_BCM_WindowStatus()                                            BCM_WindowStatus
#define l_bool_wr_BCM_WindowStatus(a)                                           {BCM_WindowStatus = a;}
#define l_u8_rd_BCM_PowerMode()                                             BCM_PowerMode
#define l_u8_wr_BCM_PowerMode(a)                                            {BCM_PowerMode = a;}
#define l_u8_rd_BCM_RainSensitivity()                                       BCM_RainSensitivity
#define l_u8_wr_BCM_RainSensitivity(a)                                      {BCM_RainSensitivity = a;}
#define l_u16_rd_BCM_VehicleSpeed()                                           (canuint16)(BCM_VehicleSpeed_0)\
                                                                                | ((canuint16)(BCM_VehicleSpeed_1)<<8)
#define l_u16_wr_BCM_VehicleSpeed(a)                                          {BCM_VehicleSpeed_0 = ((canuint8)a);\
                                                                                 BCM_VehicleSpeed_1 = ((canuint8)a>>8);}
#define l_bool_rd_BCM_VehicleSpeedValid()                                       BCM_VehicleSpeedValid
#define l_bool_wr_BCM_VehicleSpeedValid(a)                                      {BCM_VehicleSpeedValid = a;}
#define l_u8_rd_BCM_500nmTransimission()                                    BCM_500nmTransimission
#define l_u8_wr_BCM_500nmTransimission(a)                                   {BCM_500nmTransimission = a;}
#define l_u8_rd_BCM_800nmTransimission()                                    BCM_800nmTransimission
#define l_u8_wr_BCM_800nmTransimission(a)                                   {BCM_800nmTransimission = a;}

#define IsWdwOpen()                   (byte)(l_bool_rd_BCM_WindowStatus() == 1)

#define IsInParkPosition()            (byte)((l_bool_rd_BCM_WiperParkPosition()) == 0)
#define ReadVehicleSpeed()            (byte)((((l_bool_rd_BCM_VehicleSpeedValid()) == 1) || ((l_u16_rd_BCM_VehicleSpeed()) == 8191)) ? 75:((l_u16_rd_BCM_VehicleSpeed()) > 4444 ? 250 : ((l_u16_rd_BCM_VehicleSpeed()))*0.05625))
#define IsIgnitionOn()                (byte)(((l_u8_rd_BCM_PowerMode()) == 1) || ((l_u8_rd_BCM_PowerMode()) == 2))

#define IsAutoWiper()                 (byte)((l_u8_rd_BCM_WiperSwitchStatus()) == 4)
#define ReadRainSensitivity()         (byte)(((l_u8_rd_BCM_RainSensitivity()) > 6)?6:(l_u8_rd_BCM_RainSensitivity()))
#define IsWashMode()                  (byte)(((l_bool_rd_BCM_FrontWasherStatus()) == 1))


#define SendClosedWindowCmd_Close()   {l_bool_wr_RLS_WindowCloseReq(1);}
#define SendClosedWindowCmd_NClose()  {l_bool_wr_RLS_WindowCloseReq(0);}

#define SendHighVoltageError()        {l_u8_wr_RLS_VoltFault(2);}
#define SendLowVoltageError()         {l_u8_wr_RLS_VoltFault(1);}
#define SendNoVoltageError()          {l_u8_wr_RLS_VoltFault(0);}
#define SendRainSensorError()         {l_bool_wr_RLS_RainSensorFault(1);}
#define SendLightSensorError()        {l_bool_wr_RLS_LightSensorFault(1);}
#endif  /* I_LIN_RLS_H */
