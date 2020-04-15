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
#define cb_HANDLE_RSM_state2              5
#define cb_HANDLE_RSM_state               6
#define cb_HANDLE_LinReqCmd               7
#define cb_HANDLE_BCM_LIN2_state          8


#define cb_HANDLE_LinReqCmd_g     cb_HANDLE_LinReqCmd
#define cb_HANDLE_LinRespCmd_g    cb_HANDLE_LinRespCmd
#define cb_HANDLE_ASIC_Frame_01_g cb_HANDLE_ASIC_Frame_01
#define cb_HANDLE_ASIC_Frame_02_g cb_HANDLE_ASIC_Frame_02
#define cb_HANDLE_ASIC_Frame_03_g cb_HANDLE_ASIC_Frame_03
#define cb_HANDLE_ASIC_Frame_04_g cb_HANDLE_ASIC_Frame_04
#define cb_HANDLE_RLSs_01_g       cb_HANDLE_RSM_state
#define cb_HANDLE_RLSs_02_g       cb_HANDLE_RSM_state2
#define cb_HANDLE_BCM1_LIN1_01_g  cb_HANDLE_BCM_LIN2_state

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
  canbittype                         rsm_windowTemp_0: 8;
  canbittype                         rsm_windowTemp_1: 3;
  canbittype                                  unused0: 5;
  canbittype                          rsm_relHumidity: 8;
  canbittype                       rsm_dewPointTemp_0: 8;
  canbittype                       rsm_dewPointTemp_1: 3;
  canbittype                                  unused1: 5;
  canbittype                                  unused2: 8;
  canbittype                                  unused3: 8;
  canbittype                                  unused4: 8;
} _c_RSM_state2_msgType;

typedef struct {
  canbittype                           rsm_wiperSpeed: 2;
  canbittype                      rsm_rainSensorError: 1;
  canbittype                       rsm_windowCloseReq: 1;
  canbittype                     rsm_lightSensorError: 1;
  canbittype                         rsm_lowBeamOnReq: 1;
  canbittype                   rsm_positionLightOnReq: 1;
  canbittype                                  unused0: 1;
  canbittype                        rsm_lightSWReason: 3;
  canbittype                       rsm_underVoltFault: 1;
  canbittype                        rsm_overVoltFault: 1;
  canbittype                        rsm_ResponseError: 1;
  canbittype                                  unused1: 2;
  canbittype                            rsm_SolarLeft: 8;
  canbittype                           rsm_SolarRight: 8;
  canbittype                       rsm_FwBrightness_0: 8;
  canbittype                       rsm_FwBrightness_1: 3;
  canbittype                     rsm_WiperSpeed7Level: 3;
  canbittype                      rsm_AmbBrightness_0: 2;
  canbittype                      rsm_AmbBrightness_1: 8;
  canbittype                         rsm_IRBrightness: 8;
} _c_RSM_state_msgType;


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
  canbittype                            bcm_powerMode: 3;
  canbittype                       bcm_vehicleSpeed_0: 5;
  canbittype                       bcm_vehicleSpeed_1: 8;
  canbittype                    bcm_vehicleSpeedValid: 1;
  canbittype                 bcm_frontWiperParkingSts: 1;
  canbittype                     bcm_frontWiperStatus: 3;
  canbittype               bcm_rlsAutomaticModeActive: 1;
  canbittype                     bcm_rlsSensitivity_0: 2;
  canbittype                     bcm_rlsSensitivity_1: 1;
  canbittype                       bcm_apmLearnCmd_2U: 2;
  canbittype                          bcm_wash_Status: 1;
  canbittype                                  unused0: 2;
  canbittype                    bcm_sunroofGlassCmd_0: 2;
  canbittype                    bcm_sunroofGlassCmd_1: 1;
  canbittype                                  unused1: 1;
  canbittype                  bcm_srSsOperationEnable: 1;
  canbittype                 bcm_500nmTransimission_0: 5;
  canbittype                 bcm_500nmTransimission_1: 2;
  canbittype                 bcm_800nmTransimission_0: 6;
  canbittype                 bcm_800nmTransimission_1: 1;
  canbittype                             LeftMirrorSw: 1;
  canbittype                            rightMirrorSw: 1;
  canbittype                                  unused2: 3;
  canbittype                            bcm_apmCmd_2U: 2;
  canbittype                     bcm_ivi_windowLFCtrl: 2;
  canbittype                     bcm_ivi_windowRFCtrl: 2;
  canbittype                     bcm_ivi_windowLRCtrl: 2;
  canbittype                     bcm_ivi_windowRRCtrl: 2;
} _c_BCM_LIN2_state_msgType;


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
    _c_RSM_state2_msgType rsm_state2;
} _c_RSM_state2_buf;

typedef union {
    unsigned char _c[8];
    _c_RSM_state_msgType rsm_state;
} _c_RSM_state_buf;


/* Receive messages */

typedef union {
    unsigned char _c[8];
    _c_LinReqCmd_msgType linreqcmd;
} _c_LinReqCmd_buf;

typedef union {
    unsigned char _c[8];
    _c_BCM_LIN2_state_msgType bcm_lin2_state;
} _c_BCM_LIN2_state_buf;


/******************************************************************************/
/*                          Databuffer for send objects                       */
/******************************************************************************/

extern MEMORY_FAR _c_LinRespCmd_buf LinRespCmd;
extern MEMORY_FAR _c_ASIC_Frame_04_buf ASIC_Frame_04;
extern MEMORY_FAR _c_ASIC_Frame_03_buf ASIC_Frame_03;
extern MEMORY_FAR _c_ASIC_Frame_02_buf ASIC_Frame_02;
extern MEMORY_FAR _c_ASIC_Frame_01_buf ASIC_Frame_01;
extern MEMORY_FAR _c_RSM_state2_buf RSM_state2;
extern MEMORY_FAR _c_RSM_state_buf RSM_state;

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
#define RSM_state2_conf_b             uLinConfirmationFlags.w[0].b5
#define l_flg_tst_RSM_state2()       (RSM_state2_conf_b != 0)
#define l_flg_clr_RSM_state2()       {RSM_state2_conf_b = 0;}
#define RSM_state_conf_b             uLinConfirmationFlags.w[0].b6
#define l_flg_tst_RSM_state()       (RSM_state_conf_b != 0)
#define l_flg_clr_RSM_state()       {RSM_state_conf_b = 0;}

/******************************************************************************/
/*                         Databuffer for receive objects                     */
/******************************************************************************/

extern MEMORY_FAR _c_LinReqCmd_buf LinReqCmd;
extern MEMORY_FAR _c_BCM_LIN2_state_buf BCM_LIN2_state;

/******************************************************************************/
/*                          Databuffer for indicationflags                    */
/******************************************************************************/

#define LinReqCmd_ind_b             uLinIndicationFlags.w[0].b0
#define l_flg_tst_LinReqCmd()       (LinReqCmd_ind_b != 0)
#define l_flg_clr_LinReqCmd()       {LinReqCmd_ind_b = 0;}
#define BCM_LIN2_state_ind_b             uLinIndicationFlags.w[0].b1
#define l_flg_tst_BCM_LIN2_state()       (BCM_LIN2_state_ind_b != 0)
#define l_flg_clr_BCM_LIN2_state()       {BCM_LIN2_state_ind_b = 0;}

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
#define rsm_windowTemp_0                                                      RSM_state2.rsm_state2.rsm_windowTemp_0
#define rsm_windowTemp_1                                                      RSM_state2.rsm_state2.rsm_windowTemp_1
#define rsm_windowTemp(c)                                                     { rsm_windowTemp_0= (uint8)(((uint16)(c) & 0xFF));\
                                                                                rsm_windowTemp_1= (uint8)(((uint16)(c) & 0x07) >> 8);\
                                                                              }
#define rsm_relHumidity                                                       RSM_state2.rsm_state2.rsm_relHumidity
#define rsm_dewPointTemp_0                                                    RSM_state2.rsm_state2.rsm_dewPointTemp_0
#define rsm_dewPointTemp_1                                                    RSM_state2.rsm_state2.rsm_dewPointTemp_1
#define rsm_dewPointTemp(c)                                                   { rsm_dewPointTemp_0= (uint8)(((uint16)(c) & 0xFF));\
                                                                                rsm_dewPointTemp_1= (uint8)(((uint16)(c) & 0x07) >> 8);\
                                                                              }
#define rsm_wiperSpeed                                                        RSM_state.rsm_state.rsm_wiperSpeed
#define rsm_rainSensorError                                                   RSM_state.rsm_state.rsm_rainSensorError
#define rsm_windowCloseReq                                                    RSM_state.rsm_state.rsm_windowCloseReq
#define rsm_lightSensorError                                                  RSM_state.rsm_state.rsm_lightSensorError
#define rsm_lowBeamOnReq                                                      RSM_state.rsm_state.rsm_lowBeamOnReq
#define rsm_positionLightOnReq                                                RSM_state.rsm_state.rsm_positionLightOnReq
#define rsm_lightSWReason                                                     RSM_state.rsm_state.rsm_lightSWReason
#define rsm_underVoltFault                                                    RSM_state.rsm_state.rsm_underVoltFault
#define rsm_overVoltFault                                                     RSM_state.rsm_state.rsm_overVoltFault
#define rsm_ResponseError                                                     RSM_state.rsm_state.rsm_ResponseError
#define rsm_SolarLeft                                                         RSM_state.rsm_state.rsm_SolarLeft
#define rsm_SolarRight                                                        RSM_state.rsm_state.rsm_SolarRight
#define rsm_FwBrightness_0                                                    RSM_state.rsm_state.rsm_FwBrightness_0
#define rsm_FwBrightness_1                                                    RSM_state.rsm_state.rsm_FwBrightness_1
#define rsm_FwBrightness(c)                                                   { rsm_FwBrightness_0= (uint8)(((uint16)(c) & 0xFF));\
                                                                                rsm_FwBrightness_1= (uint8)(((uint16)(c) & 0x07) >> 8);\
                                                                              }
#define rsm_WiperSpeed7Level                                                  RSM_state.rsm_state.rsm_WiperSpeed7Level
#define rsm_AmbBrightness_0                                                   RSM_state.rsm_state.rsm_AmbBrightness_0
#define rsm_AmbBrightness_1                                                   RSM_state.rsm_state.rsm_AmbBrightness_1
#define rsm_AmbBrightness(c)                                                  { rsm_AmbBrightness_0= (uint8)(((uint16)(c) & 0x03));\
                                                                                rsm_AmbBrightness_1= (uint8)(((uint16)(c) & 0xFF) >> 2);\
                                                                              }
#define rsm_IRBrightness                                                      RSM_state.rsm_state.rsm_IRBrightness
#define MasterReqB0                                                           LinReqCmd.linreqcmd.MasterReqB0
#define MasterReqB1                                                           LinReqCmd.linreqcmd.MasterReqB1
#define MasterReqB2                                                           LinReqCmd.linreqcmd.MasterReqB2
#define MasterReqB3                                                           LinReqCmd.linreqcmd.MasterReqB3
#define MasterReqB4                                                           LinReqCmd.linreqcmd.MasterReqB4
#define MasterReqB5                                                           LinReqCmd.linreqcmd.MasterReqB5
#define MasterReqB6                                                           LinReqCmd.linreqcmd.MasterReqB6
#define MasterReqB7                                                           LinReqCmd.linreqcmd.MasterReqB7
#define bcm_powerMode                                                         BCM_LIN2_state.bcm_lin2_state.bcm_powerMode
#define bcm_vehicleSpeed_0                                                    BCM_LIN2_state.bcm_lin2_state.bcm_vehicleSpeed_0
#define bcm_vehicleSpeed_1                                                    BCM_LIN2_state.bcm_lin2_state.bcm_vehicleSpeed_1
#define bcm_vehicleSpeed(c)                                                   { bcm_vehicleSpeed_0= (uint8)(((uint16)(c) & 0x1F));\
                                                                                bcm_vehicleSpeed_1= (uint8)(((uint16)(c) & 0xFF) >> 5);\
                                                                              }
#define bcm_vehicleSpeedValid                                                 BCM_LIN2_state.bcm_lin2_state.bcm_vehicleSpeedValid
#define bcm_frontWiperParkingSts                                              BCM_LIN2_state.bcm_lin2_state.bcm_frontWiperParkingSts
#define bcm_frontWiperStatus                                                  BCM_LIN2_state.bcm_lin2_state.bcm_frontWiperStatus
#define bcm_rlsAutomaticModeActive                                            BCM_LIN2_state.bcm_lin2_state.bcm_rlsAutomaticModeActive
#define bcm_rlsSensitivity_0                                                  BCM_LIN2_state.bcm_lin2_state.bcm_rlsSensitivity_0
#define bcm_rlsSensitivity_1                                                  BCM_LIN2_state.bcm_lin2_state.bcm_rlsSensitivity_1
#define bcm_rlsSensitivity(c)                                                 { bcm_rlsSensitivity_0= (uint8)(((uint16)(c) & 0x03));\
                                                                                bcm_rlsSensitivity_1= (uint8)(((uint16)(c) & 0x01) >> 2);\
                                                                              }
#define bcm_apmLearnCmd_2U                                                    BCM_LIN2_state.bcm_lin2_state.bcm_apmLearnCmd_2U
#define bcm_wash_Status                                                       BCM_LIN2_state.bcm_lin2_state.bcm_wash_Status
#define bcm_sunroofGlassCmd_0                                                 BCM_LIN2_state.bcm_lin2_state.bcm_sunroofGlassCmd_0
#define bcm_sunroofGlassCmd_1                                                 BCM_LIN2_state.bcm_lin2_state.bcm_sunroofGlassCmd_1
#define bcm_sunroofGlassCmd(c)                                                { bcm_sunroofGlassCmd_0= (uint8)(((uint16)(c) & 0x03));\
                                                                                bcm_sunroofGlassCmd_1= (uint8)(((uint16)(c) & 0x01) >> 2);\
                                                                              }
#define bcm_srSsOperationEnable                                               BCM_LIN2_state.bcm_lin2_state.bcm_srSsOperationEnable
#define bcm_500nmTransimission_0                                              BCM_LIN2_state.bcm_lin2_state.bcm_500nmTransimission_0
#define bcm_500nmTransimission_1                                              BCM_LIN2_state.bcm_lin2_state.bcm_500nmTransimission_1
#define bcm_500nmTransimission(c)                                             { bcm_500nmTransimission_0= (uint8)(((uint16)(c) & 0x1F));\
                                                                                bcm_500nmTransimission_1= (uint8)(((uint16)(c) & 0x03) >> 5);\
                                                                              }
#define bcm_800nmTransimission_0                                              BCM_LIN2_state.bcm_lin2_state.bcm_800nmTransimission_0
#define bcm_800nmTransimission_1                                              BCM_LIN2_state.bcm_lin2_state.bcm_800nmTransimission_1
#define bcm_800nmTransimission(c)                                             { bcm_800nmTransimission_0= (uint8)(((uint16)(c) & 0x3F));\
                                                                                bcm_800nmTransimission_1= (uint8)(((uint16)(c) & 0x01) >> 6);\
                                                                              }
#define LeftMirrorSw                                                          BCM_LIN2_state.bcm_lin2_state.LeftMirrorSw
#define rightMirrorSw                                                         BCM_LIN2_state.bcm_lin2_state.rightMirrorSw
#define bcm_apmCmd_2U                                                         BCM_LIN2_state.bcm_lin2_state.bcm_apmCmd_2U
#define bcm_ivi_windowLFCtrl                                                  BCM_LIN2_state.bcm_lin2_state.bcm_ivi_windowLFCtrl
#define bcm_ivi_windowRFCtrl                                                  BCM_LIN2_state.bcm_lin2_state.bcm_ivi_windowRFCtrl
#define bcm_ivi_windowLRCtrl                                                  BCM_LIN2_state.bcm_lin2_state.bcm_ivi_windowLRCtrl
#define bcm_ivi_windowRRCtrl                                                  BCM_LIN2_state.bcm_lin2_state.bcm_ivi_windowRRCtrl
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
#define l_u16_rd_rsm_windowTemp()                                             (canuint16)(rsm_windowTemp_0)\
                                                                                | ((canuint16)(rsm_windowTemp_1)<<8)
#define l_u16_wr_rsm_windowTemp(a)                                             {rsm_windowTemp_0 = (a&0xff);\
                                                                                 rsm_windowTemp_1 = ((a>>8)&0x07);}
#define l_u8_rd_rsm_relHumidity()                                           rsm_relHumidity
#define l_u8_wr_rsm_relHumidity(a)                                          {rsm_relHumidity = a;}
#define l_u16_rd_rsm_dewPointTemp()                                           (canuint16)(rsm_dewPointTemp_0)\
                                                                                | ((canuint16)(rsm_dewPointTemp_1)<<8)
#define l_u16_wr_rsm_dewPointTemp(a)                                          {rsm_dewPointTemp_0 = (a&0xff);\
                                                                              rsm_dewPointTemp_1 = ((a>>8)&0x07);} 
#define l_u8_rd_rsm_wiperSpeed()                                            rsm_wiperSpeed
#define l_u8_wr_rsm_wiperSpeed(a)                                           {rsm_wiperSpeed = a;}
#define l_bool_rd_rsm_rainSensorError()                                         rsm_rainSensorError
#define l_bool_wr_rsm_rainSensorError(a)                                        {rsm_rainSensorError = a;}
#define l_bool_rd_rsm_windowCloseReq()                                          rsm_windowCloseReq
#define l_bool_wr_rsm_windowCloseReq(a)                                         {rsm_windowCloseReq = a;}
#define l_bool_rd_rsm_lightSensorError()                                        rsm_lightSensorError
#define l_bool_wr_rsm_lightSensorError(a)                                       {rsm_lightSensorError = a;}
#define l_bool_rd_rsm_lowBeamOnReq()                                            rsm_lowBeamOnReq
#define l_bool_wr_rsm_lowBeamOnReq(a)                                           {rsm_lowBeamOnReq = a;}
#define l_bool_rd_rsm_positionLightOnReq()                                      rsm_positionLightOnReq
#define l_bool_wr_rsm_positionLightOnReq(a)                                     {rsm_positionLightOnReq = a;}
#define l_u8_rd_rsm_lightSWReason()                                         rsm_lightSWReason
#define l_u8_wr_rsm_lightSWReason(a)                                        {rsm_lightSWReason = a;}
#define l_bool_rd_rsm_underVoltFault()                                          rsm_underVoltFault
#define l_bool_wr_rsm_underVoltFault(a)                                         {rsm_underVoltFault = a;}
#define l_bool_rd_rsm_overVoltFault()                                           rsm_overVoltFault
#define l_bool_wr_rsm_overVoltFault(a)                                          {rsm_overVoltFault = a;}
#define l_bool_rd_rsm_ResponseError()                                           rsm_ResponseError
#define l_bool_wr_rsm_ResponseError(a)                                          {rsm_ResponseError = a;}
#define l_u8_rd_rsm_SolarLeft()                                             rsm_SolarLeft
#define l_u8_wr_rsm_SolarLeft(a)                                            {rsm_SolarLeft = a;}
#define l_u8_rd_rsm_SolarRight()                                            rsm_SolarRight
#define l_u8_wr_rsm_SolarRight(a)                                           {rsm_SolarRight = a;}
#define l_u16_rd_rsm_FwBrightness()                                           (canuint16)(rsm_FwBrightness_0)\
                                                                                | ((canuint16)(rsm_FwBrightness_1)<<8)
#define l_u16_wr_rsm_FwBrightness(a)                                        {rsm_FwBrightness_0 = ((canuint8)(a & 0xff));\
                                                                             rsm_FwBrightness_1 = ((canuint8)((a & 0x700 )>>8));}
#define l_u8_rd_rsm_WiperSpeed7Level()                                      rsm_WiperSpeed7Level
#define l_u8_wr_rsm_WiperSpeed7Level(a)                                     {rsm_WiperSpeed7Level = a;}
#define l_u16_rd_rsm_AmbBrightness()                                          (canuint16)(rsm_AmbBrightness_0)\
                                                                                | ((canuint16)(rsm_AmbBrightness_1)<<2)
#define l_u16_wr_rsm_AmbBrightness(a)                                         {rsm_AmbBrightness_0 = (a & 0x03);\
                                                                                 rsm_AmbBrightness_1 =((a>>2) & 0xff);}
#define l_u8_rd_rsm_IRBrightness()                                          rsm_IRBrightness
#define l_u8_wr_rsm_IRBrightness(a)                                         {rsm_IRBrightness = a;}
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
#define l_u8_rd_bcm_powerMode()                                             bcm_powerMode
#define l_u8_wr_bcm_powerMode(a)                                            {bcm_powerMode = a;}
#define l_u16_rd_bcm_vehicleSpeed()                                           ((canuint16)(bcm_vehicleSpeed_0)\
                                                                                | ((canuint16)(bcm_vehicleSpeed_1)<<5))
#define l_u16_wr_bcm_vehicleSpeed(a)                                          {bcm_vehicleSpeed_0 = ((canuint8)a);\
                                                                                 bcm_vehicleSpeed_1 = ((canuint8)a>>5);}
#define l_bool_rd_bcm_vehicleSpeedValid()                                       bcm_vehicleSpeedValid
#define l_bool_wr_bcm_vehicleSpeedValid(a)                                      {bcm_vehicleSpeedValid = a;}
#define l_bool_rd_bcm_frontWiperParkingSts()                                    bcm_frontWiperParkingSts
#define l_bool_wr_bcm_frontWiperParkingSts(a)                                   {bcm_frontWiperParkingSts = a;}
#define l_u8_rd_bcm_frontWiperStatus()                                      bcm_frontWiperStatus
#define l_u8_wr_bcm_frontWiperStatus(a)                                     {bcm_frontWiperStatus = a;}
#define l_bool_rd_bcm_rlsAutomaticModeActive()                                  bcm_rlsAutomaticModeActive
#define l_bool_wr_bcm_rlsAutomaticModeActive(a)                                 {bcm_rlsAutomaticModeActive = a;}
#define l_u16_rd_bcm_rlsSensitivity()                                         (canuint16)(bcm_rlsSensitivity_0)\
                                                                                | ((canuint16)(bcm_rlsSensitivity_1)<<2)
#define l_u16_wr_bcm_rlsSensitivity(a)                                        {bcm_rlsSensitivity_0 = ((canuint8)a);\
                                                                                 bcm_rlsSensitivity_1 = ((canuint8)a>>2);}
#define l_u8_rd_bcm_apmLearnCmd_2U()                                        bcm_apmLearnCmd_2U
#define l_u8_wr_bcm_apmLearnCmd_2U(a)                                       {bcm_apmLearnCmd_2U = a;}
#define l_bool_rd_bcm_wash_Status()                                             bcm_wash_Status
#define l_bool_wr_bcm_wash_Status(a)                                            {bcm_wash_Status = a;}
#define l_u16_rd_bcm_sunroofGlassCmd()                                        (canuint16)(bcm_sunroofGlassCmd_0)\
                                                                                | ((canuint16)(bcm_sunroofGlassCmd_1)<<2)
#define l_u16_wr_bcm_sunroofGlassCmd(a)                                       {bcm_sunroofGlassCmd_0 = ((canuint8)a);\
                                                                                 bcm_sunroofGlassCmd_1 = ((canuint8)a>>2);}
#define l_bool_rd_bcm_srSsOperationEnable()                                     bcm_srSsOperationEnable
#define l_bool_wr_bcm_srSsOperationEnable(a)                                    {bcm_srSsOperationEnable = a;}
#define l_u16_rd_bcm_500nmTransimission()                                     (canuint16)(bcm_500nmTransimission_0)\
                                                                                | ((canuint16)(bcm_500nmTransimission_1)<<5)
#define l_u16_wr_bcm_500nmTransimission(a)                                    {bcm_500nmTransimission_0 = ((canuint8)a);\
                                                                                 bcm_500nmTransimission_1 = ((canuint8)a>>5);}
#define l_u16_rd_bcm_800nmTransimission()                                     (canuint16)(bcm_800nmTransimission_0)\
                                                                                | ((canuint16)(bcm_800nmTransimission_1)<<6)
#define l_u16_wr_bcm_800nmTransimission(a)                                    {bcm_800nmTransimission_0 = ((canuint8)a);\
                                                                                 bcm_800nmTransimission_1 = ((canuint8)a>>6);}
#define l_bool_rd_LeftMirrorSw()                                                LeftMirrorSw
#define l_bool_wr_LeftMirrorSw(a)                                               {LeftMirrorSw = a;}
#define l_bool_rd_rightMirrorSw()                                               rightMirrorSw
#define l_bool_wr_rightMirrorSw(a)                                              {rightMirrorSw = a;}
#define l_u8_rd_bcm_apmCmd_2U()                                             bcm_apmCmd_2U
#define l_u8_wr_bcm_apmCmd_2U(a)                                            {bcm_apmCmd_2U = a;}
#define l_u8_rd_bcm_ivi_windowLFCtrl()                                      bcm_ivi_windowLFCtrl
#define l_u8_wr_bcm_ivi_windowLFCtrl(a)                                     {bcm_ivi_windowLFCtrl = a;}
#define l_u8_rd_bcm_ivi_windowRFCtrl()                                      bcm_ivi_windowRFCtrl
#define l_u8_wr_bcm_ivi_windowRFCtrl(a)                                     {bcm_ivi_windowRFCtrl = a;}
#define l_u8_rd_bcm_ivi_windowLRCtrl()                                      bcm_ivi_windowLRCtrl
#define l_u8_wr_bcm_ivi_windowLRCtrl(a)                                     {bcm_ivi_windowLRCtrl = a;}
#define l_u8_rd_bcm_ivi_windowRRCtrl()                                      bcm_ivi_windowRRCtrl
#define l_u8_wr_bcm_ivi_windowRRCtrl(a)                                     {bcm_ivi_windowRRCtrl = a;}


#endif  /* I_LIN_RLS_H */
