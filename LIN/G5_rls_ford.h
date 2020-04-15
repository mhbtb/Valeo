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
 * <tr> <td> Source:   </td> <td> G5_rls.h                  </td></tr>
 * <tr> <td> Revision: </td> <td> 1.8                  </td></tr>
 * <tr> <td> Status:   </td> <td> ACCEPTED                  </td></tr>
 * <tr> <td> Author:   </td> <td> Jochen Schenk, VDS-E-PUS  </td></tr>
 * <tr> <td> Date:     </td> <td> 30-SEP-2013 14:06:49                 </td></tr>
 * </table>
 * 
 * \n
 * <table border="0" cellspacing="0" cellpadding="0">
 * <tr> <td> COMPONENT: </td> <td> RLS_LIN     </td></tr>
 * <tr> <td> SCOPE:     </td> <td> Public      </td></tr>
 * <tr> <td> TARGET:    </td> <td> NEC         </td></tr>
 * </table>
 */
 /* PRQA S 2217 EOF */ /* << 2011 03 03, Code would be not readable >> */
/* PRQA S 3458,3412 EOF *//*<< required for readability  >>*/
/* PRQA S 750,0759 EOF *//*<< 0759:union needed to reduce RAM usage >>*/
/* PRQA S 3453 EOF *//*<< Macro is more readle and convinient in this situation >>*/
#ifndef LIN_RLS_H
#define LIN_RLS_H

#define __RLS__

/******************************************************************************/
/*                        Definition of message handles                       */
/******************************************************************************/

/*#define cb_HANDLE_LinRespCmd_g              0
#define cb_HANDLE_ASIC_Frame_04_g           1
#define cb_HANDLE_ASIC_Frame_03_g           2
#define cb_HANDLE_ASIC_Frame_02_g           3
#define cb_HANDLE_ASIC_Frame_01_g           4
#define cb_HANDLE_SoSes_01                  5
#define cb_HANDLE_RLSs_01_g                 6
#define cb_HANDLE_FSs_01_g                  7
#define cb_HANDLE_LinReqCmd_g               8
#define cb_HANDLE_WWSs_01_g                 9
#define cb_HANDLE_BCM1_LIN1_01_g            10*/

   
#define cb_HANDLE_LinRespCmd_g       0 /* LinTxLinRespCmd */
#define cb_HANDLE_SPARE_01_g         1 /* cb_HANDLE_LinTxRSM_L8_FrP02*/
#define cb_HANDLE_ERROR_DATA_RLS_g   2 /* cb_HANDLE_LinTxRSM_L8_FrP01*/
#define cb_HANDLE_RLSs_01_g          3 /* LinTxRSM_L8_FrP00 */
#define cb_HANDLE_ASIC_Frame_04_g    4
#define cb_HANDLE_ASIC_Frame_03_g    5
#define cb_HANDLE_ASIC_Frame_02_g    6
#define cb_HANDLE_ASIC_Frame_01_g    7
#define cb_HANDLE_LinReqCmd_g        8 /* LinRxLinReqCmd*/
#define cb_HANDLE_BCM1_LIN1_01_g     9 /* LinRxBCM_L8_FrP01*/
#define cb_HANDLE_WWSs_01_g          10 /*LinRxBCM_L8_FrP03*/
#define cb_HANDLE_FSdataEnhanced_g   11 /* cb_HANDLE_LinRxWMM_L8_FrP00*/
   
/******************************************************************************/
/*                    Declaration of exported variables                       */
/******************************************************************************/

/* start skeleton LIN H-File ----------------------------------------*/

extern MEMORY_ROM canuint8 cabLinRxDLCTbl[];
extern canuint8* MEMORY_ROM capbLinRxDataPtrTbl[kLinNumberOfRxObjects];
extern MEMORY_ROM canuint8 cabLinTxDataLenTbl[];
extern canuint8* MEMORY_ROM capbLinTxDataPtrTbl[kLinNumberOfTxObjects];
extern MEMORY_ROM canuint8 cabLinMsgIDToHandleTbl[0x40];
extern MEMORY_ROM canuint8 cabLinRxDataLenTbl[];
extern MEMORY_ROM canuint8 cabLinRxDLCTbl[];

#ifdef NODECONFIGURATION
extern canuint8             rabRAMLinMsgIDToHandleTbl[0x40];
extern MEMORY_ROM canuint16 cawLINMessageID[kLinNumberOfObjects];
#else
extern MEMORY_ROM canuint8  cabLinMsgIDToHandleTbl[0x40];
#endif

extern canuint8 MEMORY_ROM cabLinMsgHandleTbl[kLinNumberOfObjects];

/* end   skeleton LIN H-File ----------------------------------------*/



/*************************************************************/
/* Signal structures                                          */
/*************************************************************/

/* Send messages */

typedef struct {
  canbittype                    SlaveRespB0: 8;
  canbittype                    SlaveRespB1: 8;
  canbittype                    SlaveRespB2: 8;
  canbittype                    SlaveRespB3: 8;
  canbittype                    SlaveRespB4: 8;
  canbittype                    SlaveRespB5: 8;
  canbittype                    SlaveRespB6: 8;
  canbittype                    SlaveRespB7: 8;
} _c_LinRespCmd_msgType;

typedef struct {
  canbittype          PartNumberRSMFord_1_0: 8;
  canbittype          PartNumberRSMFord_1_1: 8;
  canbittype          PartNumberRSMFord_2_0: 8;
  canbittype          PartNumberRSMFord_2_1: 8;
  canbittype          PartNumberRSMFord_3_0: 8;
  canbittype          PartNumberRSMFord_3_1: 8;
  canbittype          PartNumberRSMFord_4_0: 8;
  canbittype          PartNumberRSMFord_4_1: 8;
} _c_RSM_L8_FrP02_msgType;

typedef struct {
  canbittype              PartNumberRSM_1_0: 8;
  canbittype              PartNumberRSM_1_1: 8;
  canbittype              PartNumberRSM_2_0: 8;
  canbittype              PartNumberRSM_2_1: 8;
  canbittype              PartNumberRSM_3_0: 8;
  canbittype              PartNumberRSM_3_1: 8;
  canbittype                        unused0: 8;
  canbittype                        unused1: 8;
} _c_RSM_L8_FrP01_msgType;

typedef struct {
  canbittype            WipeSpeedRainSensor: 3;
  canbittype                FaultInRainSens: 1;
  canbittype          FaultInRainSensActive: 1;
  canbittype                 SplashDetected: 1;
  canbittype         RainSensorInDirectMode: 1;
  canbittype               AdaptErrRainSens: 1;
  canbittype         AdaptErrRainSensActive: 1;
  canbittype               AlsDippedBeamReq: 1;
  canbittype               FaultInAlsSensor: 1;
  canbittype         FaultInAlsSensorActive: 1;
  canbittype                        unused0: 4;
} _c_RSM_L8_FrP00_msgType;


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

/* Receive messages */

typedef struct {
  canbittype                    MasterReqB0: 8;
  canbittype                    MasterReqB1: 8;
  canbittype                    MasterReqB2: 8;
  canbittype                    MasterReqB3: 8;
  canbittype                    MasterReqB4: 8;
  canbittype                    MasterReqB5: 8;
  canbittype                    MasterReqB6: 8;
  canbittype                    MasterReqB7: 8;
} _c_LinReqCmd_msgType;

typedef struct {
  canbittype                        unused0: 8;
  canbittype         WashingCycleActive_WWM: 1;
  canbittype                WiperActive_WWM: 1;
  canbittype          WiperInWipingArea_WWM: 1;
  canbittype                        unused2: 5;
} _c_WMM_L8_FrP00_msgType;


typedef struct {
  canbittype               IntermittentTime: 4;
  canbittype               RainSensorActive: 1;
  canbittype                        unused0: 2;
  canbittype                      CarCode_0: 1;
  canbittype         StalkInSingleStrokePos: 1;
  canbittype         StalkInIntermittentPos: 1;
  canbittype             StalkInLowSpeedPos: 1;
  canbittype            StalkInHighSpeedPos: 1;
  canbittype            StalkInFrontWashPos: 1;
  canbittype                        unused3: 2;
  canbittype                      CarCode_1: 1;
  canbittype                    Terminal_15: 1;
  canbittype                     Terminal_X: 1;
  canbittype                      CarCode_2: 1;
  canbittype                      CarCode_3: 1;
  canbittype                        unused4: 4;
  canbittype         VisibilityVehicleSpeed: 8;
} _c_BCM_L8_FrP01_msgType;

typedef struct {
  canbittype                        unused0: 8;
  canbittype           WashingCycleActive_s: 1;
  canbittype                  WiperActive_s: 1;
  canbittype            WiperInWipingArea_s: 1;
  canbittype                        unused1: 5;
} _c_BCM_L8_FrP03_msgType;

/*************************************************************/
/* Message unions              */
/*************************************************************/

/* Send messages */

typedef union {
  unsigned char _c[8];
  _c_LinRespCmd_msgType  linrespcmd;
} _c_LinRespCmd_buf;

typedef union {
  unsigned char _c[8];
  _c_RSM_L8_FrP02_msgType  rsm_l8_frp02;
} _c_RSM_L8_FrP02_buf;

typedef union {
  unsigned char _c[8];
  _c_RSM_L8_FrP01_msgType  rsm_l8_frp01;
} _c_RSM_L8_FrP01_buf;

typedef union {
  unsigned char _c[2];
  _c_RSM_L8_FrP00_msgType  rsm_l8_frp00;
} _c_RSM_L8_FrP00_buf;
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

/* Receive messages */

typedef union {
  unsigned char _c[8];
  _c_LinReqCmd_msgType  linreqcmd;
} _c_LinReqCmd_buf;

typedef union {
  unsigned char _c[4];
  _c_BCM_L8_FrP01_msgType  bcm_l8_frp01;
} _c_BCM_L8_FrP01_buf;

typedef union {
  unsigned char _c[2];
  _c_BCM_L8_FrP03_msgType  bcm_l8_frp03;
} _c_BCM_L8_FrP03_buf;

typedef union {
  unsigned char _c[2];
  _c_WMM_L8_FrP00_msgType  wmm_l8_frp00;
} _c_WMM_L8_FrP00_buf;

/* Pretransmit functions */

/* Confirmation functions */


/* Precopy functions */


/* Indication functions */


/*************************************************************/
/* Databuffer for send objects                               */
/*************************************************************/
extern MEMORY_FAR _c_LinRespCmd_buf LinRespCmd;
extern MEMORY_FAR _c_RSM_L8_FrP02_buf RSM_L8_FrP02;
extern MEMORY_FAR _c_RSM_L8_FrP01_buf RSM_L8_FrP01;
extern MEMORY_FAR _c_RSM_L8_FrP00_buf RSM_L8_FrP00;
extern MEMORY_FAR _c_ASIC_Frame_04_buf ASIC_Frame_04;
extern MEMORY_FAR _c_ASIC_Frame_03_buf ASIC_Frame_03;
extern MEMORY_FAR _c_ASIC_Frame_02_buf ASIC_Frame_02;
extern MEMORY_FAR _c_ASIC_Frame_01_buf ASIC_Frame_01;
/*************************************************************/
/* Byte access to databuffer of send objects                 */
/*************************************************************/





/*************************************************************/
/* Handles of send objects                                   */
/*************************************************************/



/*************************************************************/
/* Databuffer for confirmationflags                          */
/*************************************************************/

#define LinRespCmd_conf_b                          uLinConfirmationFlags.w[0].b0
#define l_flg_tst_LinRespCmd()          (LinRespCmd_conf_b != 0)
#define l_flg_clr_LinRespCmd()          LinRespCmd_conf_b = 0
#define RSM_L8_FrP02_conf_b                        uLinConfirmationFlags.w[0].b1
#define l_flg_tst_RSM_L8_FrP02()          (RSM_L8_FrP02_conf_b != 0)
#define l_flg_clr_RSM_L8_FrP02()          RSM_L8_FrP02_conf_b = 0
#define RSM_L8_FrP01_conf_b                        uLinConfirmationFlags.w[0].b2
#define l_flg_tst_RSM_L8_FrP01()          (RSM_L8_FrP01_conf_b != 0)
#define l_flg_clr_RSM_L8_FrP01()          RSM_L8_FrP01_conf_b = 0
#define RSM_L8_FrP00_conf_b                        uLinConfirmationFlags.w[0].b3
#define l_flg_tst_RSM_L8_FrP00()          (RSM_L8_FrP00_conf_b != 0)
#define l_flg_clr_RSM_L8_FrP00()          RSM_L8_FrP00_conf_b = 0

#define ASIC_Frame_04_conf_b             uLinConfirmationFlags.w[0].b4
#define l_flg_tst_ASIC_Frame_04()       (ASIC_Frame_04_conf_b != 0)
#define l_flg_clr_ASIC_Frame_04()       {ASIC_Frame_04_conf_b = 0;}
#define ASIC_Frame_03_conf_b             uLinConfirmationFlags.w[0].b5
#define l_flg_tst_ASIC_Frame_03()       (ASIC_Frame_03_conf_b != 0)
#define l_flg_clr_ASIC_Frame_03()       {ASIC_Frame_03_conf_b = 0;}
#define ASIC_Frame_02_conf_b             uLinConfirmationFlags.w[0].b6
#define l_flg_tst_ASIC_Frame_02()       (ASIC_Frame_02_conf_b != 0)
#define l_flg_clr_ASIC_Frame_02()       {ASIC_Frame_02_conf_b = 0;}
#define ASIC_Frame_01_conf_b             uLinConfirmationFlags.w[0].b7
#define l_flg_tst_ASIC_Frame_01()       (ASIC_Frame_01_conf_b != 0)
#define l_flg_clr_ASIC_Frame_01()       {ASIC_Frame_01_conf_b = 0;}


/*************************************************************/
/* Databuffer for receive objects                            */
/*************************************************************/
extern MEMORY_FAR _c_LinReqCmd_buf LinReqCmd;
extern MEMORY_FAR _c_BCM_L8_FrP01_buf BCM_L8_FrP01;
extern MEMORY_FAR _c_BCM_L8_FrP03_buf BCM_L8_FrP03;
extern MEMORY_FAR _c_WMM_L8_FrP00_buf WMM_L8_FrP00;
/*************************************************************/
/* Byte access to databuffer of receive objects              */
/*************************************************************/




/*************************************************************/
/* Handles of  receive objects                               */
/*************************************************************/




/*************************************************************/
/* Databuffer for indicationflags                                */
/*************************************************************/
#define LinReqCmd_ind_b                            uLinIndicationFlags.w[0].b0
#define l_flg_tst_LinReqCmd()  (LinReqCmd_ind_b != 0)
#define l_flg_clr_LinReqCmd()  LinReqCmd_ind_b = 0
#define BCM_L8_FrP01_ind_b                         uLinIndicationFlags.w[0].b1
#define l_flg_tst_BCM_L8_FrP01()  (BCM_L8_FrP01_ind_b != 0)
#define l_flg_clr_BCM_L8_FrP01()  BCM_L8_FrP01_ind_b = 0
#define BCM_L8_FrP03_ind_b                         uLinIndicationFlags.w[0].b2
#define l_flg_tst_BCM_L8_FrP03()  (BCM_L8_FrP03_ind_b != 0)
#define l_flg_clr_BCM_L8_FrP03()  BCM_L8_FrP03_ind_b = 0
#define WMM_L8_FrP00_ind_b                         uLinIndicationFlags.w[0].b3
#define l_flg_tst_WMM_L8_FrP00()  (WMM_L8_FrP00_ind_b != 0)
#define l_flg_clr_WMM_L8_FrP00()  WMM_L8_FrP00_ind_b = 0

/*************************************************************/
/* Signals of send messages                                  */
/*************************************************************/

#define SlaveRespB0                                                  LinRespCmd.linrespcmd.SlaveRespB0
#define SlaveRespB1                                                  LinRespCmd.linrespcmd.SlaveRespB1
#define SlaveRespB2                                                  LinRespCmd.linrespcmd.SlaveRespB2
#define SlaveRespB3                                                  LinRespCmd.linrespcmd.SlaveRespB3
#define SlaveRespB4                                                  LinRespCmd.linrespcmd.SlaveRespB4
#define SlaveRespB5                                                  LinRespCmd.linrespcmd.SlaveRespB5
#define SlaveRespB6                                                  LinRespCmd.linrespcmd.SlaveRespB6
#define SlaveRespB7                                                  LinRespCmd.linrespcmd.SlaveRespB7


#define l_u8_rd_SlaveRespB0()                                               SlaveRespB0
#define l_u8_wr_SlaveRespB0(a)                                              {SlaveRespB0 = (a);}
#define l_u8_rd_SlaveRespB1()                                               SlaveRespB1
#define l_u8_wr_SlaveRespB1(a)                                              {SlaveRespB1 = (a);}
#define l_u8_rd_SlaveRespB2()                                               SlaveRespB2
#define l_u8_wr_SlaveRespB2(a)                                              {SlaveRespB2 = (a);}
#define l_u8_rd_SlaveRespB3()                                               SlaveRespB3
#define l_u8_wr_SlaveRespB3(a)                                              {SlaveRespB3 = (a);}
#define l_u8_rd_SlaveRespB4()                                               SlaveRespB4
#define l_u8_wr_SlaveRespB4(a)                                              {SlaveRespB4 = (a);}
#define l_u8_rd_SlaveRespB5()                                               SlaveRespB5
#define l_u8_wr_SlaveRespB5(a)                                              {SlaveRespB5 = (a);}
#define l_u8_rd_SlaveRespB6()                                               SlaveRespB6
#define l_u8_wr_SlaveRespB6(a)                                              {SlaveRespB6 = (a);}
#define l_u8_rd_SlaveRespB7()                                               SlaveRespB7
#define l_u8_wr_SlaveRespB7(a)                                              {SlaveRespB7 = (a);}

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

#define PartNumberRSMFord_1_0                                        RSM_L8_FrP02.rsm_l8_frp02.PartNumberRSMFord_1_0
#define PartNumberRSMFord_1_1                                        RSM_L8_FrP02.rsm_l8_frp02.PartNumberRSMFord_1_1
#define PartNumberRSMFord_1(c)                                       PartNumberRSMFord_1_0 = (uint8)(((uint16)(c) & 0xff));\
                                                                     PartNumberRSMFord_1_1 = (uint8)(((uint16)(c) & 0xff00) >> 8)
#define PartNumberRSMFord_2_0                                        RSM_L8_FrP02.rsm_l8_frp02.PartNumberRSMFord_2_0
#define PartNumberRSMFord_2_1                                        RSM_L8_FrP02.rsm_l8_frp02.PartNumberRSMFord_2_1
#define PartNumberRSMFord_2(c)                                       PartNumberRSMFord_2_0 = (uint8)(((uint16)(c) & 0xff));\
                                                                     PartNumberRSMFord_2_1 = (uint8)(((uint16)(c) & 0xff00) >> 8)

#define PartNumberRSMFord_3_0                                        RSM_L8_FrP02.rsm_l8_frp02.PartNumberRSMFord_3_0
#define PartNumberRSMFord_3_1                                        RSM_L8_FrP02.rsm_l8_frp02.PartNumberRSMFord_3_1
#define PartNumberRSMFord_3(c)                                       PartNumberRSMFord_3_0 = (uint8)(((uint16)(c) & 0xff));\
                                                                     PartNumberRSMFord_3_1 = (uint8)(((uint16)(c) & 0xff00) >> 8)

#define PartNumberRSMFord_4_0                                        RSM_L8_FrP02.rsm_l8_frp02.PartNumberRSMFord_4_0
#define PartNumberRSMFord_4_1                                        RSM_L8_FrP02.rsm_l8_frp02.PartNumberRSMFord_4_1
#define PartNumberRSMFord_4(c)                                       PartNumberRSMFord_4_0 = (uint8)(((uint16)(c) & 0xff));\
                                                                     PartNumberRSMFord_4_1 = (uint8)(((uint16)(c) & 0xff00) >> 8)


#define PartNumberRSM_1_0                                            RSM_L8_FrP01.rsm_l8_frp01.PartNumberRSM_1_0
#define PartNumberRSM_1_1                                            RSM_L8_FrP01.rsm_l8_frp01.PartNumberRSM_1_1
#define PartNumberRSM_1(c)                                           PartNumberRSM_1_0 = (uint8)(((uint16)(c) & 0xff));\
                                                                     PartNumberRSM_1_1 = (uint8)(((uint16)(c) & 0xff00) >> 8)

#define PartNumberRSM_2_0                                            RSM_L8_FrP01.rsm_l8_frp01.PartNumberRSM_2_0
#define PartNumberRSM_2_1                                            RSM_L8_FrP01.rsm_l8_frp01.PartNumberRSM_2_1
#define PartNumberRSM_2(c)                                           PartNumberRSM_2_0 = (uint8)(((uint16)(c) & 0xff));\
                                                                     PartNumberRSM_2_1 = (uint8)(((uint16)(c) & 0xff00) >> 8)

#define PartNumberRSM_3_0                                            RSM_L8_FrP01.rsm_l8_frp01.PartNumberRSM_3_0
#define PartNumberRSM_3_1                                            RSM_L8_FrP01.rsm_l8_frp01.PartNumberRSM_3_1
#define PartNumberRSM_3(c)                                           PartNumberRSM_3_0 = (uint8)(((uint16)(c) & 0xff));\
                                                                     PartNumberRSM_3_1 = (uint8)(((uint16)(c) & 0xff00) >> 8)


#define WipeSpeedRainSensor                                          RSM_L8_FrP00.rsm_l8_frp00.WipeSpeedRainSensor
#define FaultInRainSens                                              RSM_L8_FrP00.rsm_l8_frp00.FaultInRainSens
#define FaultInRainSensActive                                        RSM_L8_FrP00.rsm_l8_frp00.FaultInRainSensActive
#define SplashDetected                                               RSM_L8_FrP00.rsm_l8_frp00.SplashDetected
#define RainSensorInDirectMode                                       RSM_L8_FrP00.rsm_l8_frp00.RainSensorInDirectMode
#define AdaptErrRainSens                                             RSM_L8_FrP00.rsm_l8_frp00.AdaptErrRainSens
#define AdaptErrRainSensActive                                       RSM_L8_FrP00.rsm_l8_frp00.AdaptErrRainSensActive
#define AlsDippedBeamReq                                             RSM_L8_FrP00.rsm_l8_frp00.AlsDippedBeamReq
#define FaultInAlsSensor                                             RSM_L8_FrP00.rsm_l8_frp00.FaultInAlsSensor
#define FaultInAlsSensorActive                                       RSM_L8_FrP00.rsm_l8_frp00.FaultInAlsSensorActive


#define l_u16_rd_PartNumberRSMFord_1()                              (canuint16)(((canuint16)(PartNumberRSMFord_1_1) << 8)\
                                                                  | (PartNumberRSMFord_1_0))
#define l_u16_wr_PartNumberRSMFord_1(a)                             PartNumberRSMFord_1_1 = ((canuint8)(a >> 8));\
                                                                  PartNumberRSMFord_1_0 = ((canuint8)a)
#define l_u16_rd_PartNumberRSMFord_2()                              (canuint16)(((canuint16)(PartNumberRSMFord_2_1) << 8)\
                                                                  | (PartNumberRSMFord_2_0))
#define l_u16_wr_PartNumberRSMFord_2(a)                             PartNumberRSMFord_2_1 = ((canuint8)((a) >> 8));\
                                                                  PartNumberRSMFord_2_0 = ((canuint8)(a))
#define l_u16_rd_PartNumberRSMFord_3()                              (canuint16)(((canuint16)(PartNumberRSMFord_3_1) << 8)\
                                                                  | (PartNumberRSMFord_3_0))
#define l_u16_wr_PartNumberRSMFord_3(a)                             PartNumberRSMFord_3_1 = ((canuint8)((a) >> 8));\
                                                                  PartNumberRSMFord_3_0 = ((canuint8)(a))
#define l_u16_rd_PartNumberRSMFord_4()                              (canuint16)(((canuint16)(PartNumberRSMFord_4_1) << 8)\
                                                                  | (PartNumberRSMFord_4_0))
#define l_u16_wr_PartNumberRSMFord_4(a)                             PartNumberRSMFord_4_1 = ((canuint8)(a >> 8));\
                                                                    PartNumberRSMFord_4_0 = ((canuint8)a)

#define l_u16_rd_PartNumberRSM_1()                                  (canuint16)(((canuint16)(PartNumberRSM_1_1) << 8)\
                                                                  | (PartNumberRSM_1_0))
#define l_u16_wr_PartNumberRSM_1(a)                                 PartNumberRSM_1_1 = ((canuint8)(a >> 8));\
                                                                  PartNumberRSM_1_0 = ((canuint8)a)
#define l_u16_rd_PartNumberRSM_2()                                  (canuint16)(((canuint16)(PartNumberRSM_2_1) << 8)\
                                                                  | (PartNumberRSM_2_0))
#define l_u16_wr_PartNumberRSM_2(a)                                 PartNumberRSM_2_1 = ((canuint8)(a >> 8));\
                                                                  PartNumberRSM_2_0 = ((canuint8)a)
#define l_u16_rd_PartNumberRSM_3()                                  (canuint16)(((canuint16)(PartNumberRSM_3_1) << 8)\
                                                                  | (PartNumberRSM_3_0))
#define l_u16_wr_PartNumberRSM_3(a)                                 PartNumberRSM_3_1 = ((canuint8)(a >> 8));\
                                                                  PartNumberRSM_3_0 = ((canuint8)a)

#define l_u8_rd_WipeSpeedRainSensor()                              WipeSpeedRainSensor
#define l_u8_wr_WipeSpeedRainSensor(a)                             WipeSpeedRainSensor = (a)
#define l_bool_rd_FaultInRainSens()                                FaultInRainSens
#define l_bool_wr_FaultInRainSens(a)                               FaultInRainSens = (a)
#define l_bool_rd_FaultInRainSensActive()                          FaultInRainSensActive
#define l_bool_wr_FaultInRainSensActive(a)                         FaultInRainSensActive = (a)
#define l_bool_rd_SplashDetected()                                 SplashDetected
#define l_bool_wr_SplashDetected(a)                                SplashDetected = (a)
#define l_bool_rd_RainSensorInDirectMode()                         RainSensorInDirectMode
#define l_bool_wr_RainSensorInDirectMode(a)                        RainSensorInDirectMode = (a)
#define l_bool_rd_AdaptErrRainSens()                               AdaptErrRainSens
#define l_bool_wr_AdaptErrRainSens(a)                              AdaptErrRainSens = (a)
#define l_bool_rd_AdaptErrRainSensActive()                         AdaptErrRainSensActive
#define l_bool_wr_AdaptErrRainSensActive(a)                        AdaptErrRainSensActive = (a)
#define l_bool_rd_AlsDippedBeamReq()                               AlsDippedBeamReq
#define l_bool_wr_AlsDippedBeamReq(a)                              AlsDippedBeamReq = (a)
#define l_bool_rd_FaultInAlsSensor()                               FaultInAlsSensor
#define l_bool_wr_FaultInAlsSensor(a)                              FaultInAlsSensor = (a)
#define l_bool_rd_FaultInAlsSensorActive()                         FaultInAlsSensorActive
#define l_bool_wr_FaultInAlsSensorActive(a)                        FaultInAlsSensorActive = (a)


/*************************************************************/
/* Signals of receive messages                               */
/*************************************************************/

#define MasterReqB0                                                  LinReqCmd.linreqcmd.MasterReqB0
#define MasterReqB1                                                  LinReqCmd.linreqcmd.MasterReqB1
#define MasterReqB2                                                  LinReqCmd.linreqcmd.MasterReqB2
#define MasterReqB3                                                  LinReqCmd.linreqcmd.MasterReqB3
#define MasterReqB4                                                  LinReqCmd.linreqcmd.MasterReqB4
#define MasterReqB5                                                  LinReqCmd.linreqcmd.MasterReqB5
#define MasterReqB6                                                  LinReqCmd.linreqcmd.MasterReqB6
#define MasterReqB7                                                  LinReqCmd.linreqcmd.MasterReqB7

#define l_u8_rd_MasterReqB0()                                               MasterReqB0
#define l_u8_wr_MasterReqB0(a)                                              {MasterReqB0 = (a);}
#define l_u8_rd_MasterReqB1()                                               MasterReqB1
#define l_u8_wr_MasterReqB1(a)                                              {MasterReqB1 = (a);}
#define l_u8_rd_MasterReqB2()                                               MasterReqB2
#define l_u8_wr_MasterReqB2(a)                                              {MasterReqB2 = (a);}
#define l_u8_rd_MasterReqB3()                                               MasterReqB3
#define l_u8_wr_MasterReqB3(a)                                              {MasterReqB3 = (a);}
#define l_u8_rd_MasterReqB4()                                               MasterReqB4
#define l_u8_wr_MasterReqB4(a)                                              {MasterReqB4 = (a);}
#define l_u8_rd_MasterReqB5()                                               MasterReqB5
#define l_u8_wr_MasterReqB5(a)                                              {MasterReqB5 = (a);}
#define l_u8_rd_MasterReqB6()                                               MasterReqB6
#define l_u8_wr_MasterReqB6(a)                                              {MasterReqB6 = (a);}
#define l_u8_rd_MasterReqB7()                                               MasterReqB7
#define l_u8_wr_MasterReqB7(a)                                              {MasterReqB7 = (a);}

#define IntermittentTime                                           BCM_L8_FrP01.bcm_l8_frp01.IntermittentTime
#define RainSensorActive                                             BCM_L8_FrP01.bcm_l8_frp01.RainSensorActive
#define CarCode_0                                                    BCM_L8_FrP01.bcm_l8_frp01.CarCode_0
#define StalkInIntermittentPos                                       BCM_L8_FrP01.bcm_l8_frp01.StalkInIntermittentPos
#define StalkInSingleStrokePos                                       BCM_L8_FrP01.bcm_l8_frp01.StalkInSingleStrokePos
#define StalkInLowSpeedPos                                           BCM_L8_FrP01.bcm_l8_frp01.StalkInLowSpeedPos
#define StalkInHighSpeedPos                                          BCM_L8_FrP01.bcm_l8_frp01.StalkInHighSpeedPos
#define StalkInFrontWashPos                                          BCM_L8_FrP01.bcm_l8_frp01.StalkInFrontWashPos
#define CarCode_1                                                    BCM_L8_FrP01.bcm_l8_frp01.CarCode_1
#define Terminal_15                                                  BCM_L8_FrP01.bcm_l8_frp01.Terminal_15
#define Terminal_X                                                   BCM_L8_FrP01.bcm_l8_frp01.Terminal_X
#define CarCode_2                                                    BCM_L8_FrP01.bcm_l8_frp01.CarCode_2
#define CarCode_3                                                    BCM_L8_FrP01.bcm_l8_frp01.CarCode_3
#define VisibilityVehicleSpeed                                       BCM_L8_FrP01.bcm_l8_frp01.VisibilityVehicleSpeed

#define WashingCycleActive_WWM                                       WMM_L8_FrP00.wmm_l8_frp00.WashingCycleActive_WWM
#define WiperActive_WWM                                              WMM_L8_FrP00.wmm_l8_frp00.WiperActive_WWM
#define WiperInWipingArea_WWM                                        WMM_L8_FrP00.wmm_l8_frp00.WiperInWipingArea_WWM

#define WashingCycleActive_s                                         BCM_L8_FrP03.bcm_l8_frp03.WashingCycleActive_s
#define WiperActive_s                                                BCM_L8_FrP03.bcm_l8_frp03.WiperActive_s
#define WiperInWipingArea_s                                          BCM_L8_FrP03.bcm_l8_frp03.WiperInWipingArea_s


#define l_u8_rd_IntermittentTime()                                 IntermittentTime
#define l_u8_wr_IntermittentTime(a)                                IntermittentTime = (a)
#define l_bool_rd_RainSensorActive()                               RainSensorActive
#define l_bool_wr_RainSensorActive(a)                              RainSensorActive = (a)
#define l_u8_rd_StalkInSingleStrokePos()                           StalkInSingleStrokePos
#define l_u8_rd_StalkInIntermittentPos()                           StalkInIntermittentPos
#define l_bool_rd_StalkInLowSpeedPos()                             StalkInLowSpeedPos
#define l_bool_rd_StalkInHighSpeedPos()                            StalkInHighSpeedPos
#define l_bool_rd_StalkInPos_compact()                             (canuint8) ( (canuint8)(StalkInSingleStrokePos)\
  |((canuint8)(StalkInIntermittentPos<<1))\
  |((canuint8)(StalkInLowSpeedPos<<2)) )& 0x07
#define l_bool_rd_CarCode_all()                                    (canuint8) ( (canuint8)(CarCode_0)\
                                                                               |((canuint8)(CarCode_1<<1))\
                                                                               |((canuint8)(CarCode_2<<2))\
                                                                               |((canuint8)(CarCode_3<<3)) )&0x0F
#define l_bool_rd_CarCode_0()                                      CarCode_0
#define l_bool_wr_CarCode_0(a)                                     CarCode_0 = (a)
#define l_bool_rd_StalkInFrontWashPos()                            StalkInFrontWashPos
#define l_bool_wr_StalkInFrontWashPos(a)                           StalkInFrontWashPos = (a)
#define l_bool_rd_CarCode_1()                                      CarCode_1
#define l_bool_wr_CarCode_1(a)                                     CarCode_1 = (a)
#define l_bool_rd_Terminal_15()                                    Terminal_15
#define l_bool_wr_Terminal_15(a)                                   Terminal_15 = (a)
#define l_bool_rd_Terminal_X()                                     Terminal_X
#define l_bool_wr_Terminal_X(a)                                    Terminal_X = (a)
#define l_bool_rd_CarCode_2()                                      CarCode_2
#define l_bool_wr_CarCode_2(a)                                     CarCode_2 = (a)
#define l_bool_rd_CarCode_3()                                      CarCode_3
#define l_bool_wr_CarCode_3(a)                                     CarCode_3 = (a)
#define l_u8_rd_VisibilityVehicleSpeed()                           VisibilityVehicleSpeed
#define l_u8_wr_VisibilityVehicleSpeed(a)                          VisibilityVehicleSpeed = (a)

#define l_bool_rd_WashingCycleActive_s()                           WashingCycleActive_s
#define l_bool_wr_WashingCycleActive_s(a)                          WashingCycleActive_s = (a)
#define l_bool_rd_WiperActive_s()                                  WiperActive_s
#define l_bool_wr_WiperActive_s(a)                                 WiperActive_s = (a)
#define l_bool_rd_WiperInWipingArea_s()                            WiperInWipingArea_s
#define l_bool_wr_WiperInWipingArea_s(a)                           WiperInWipingArea_s = (a)

#define l_bool_rd_WashingCycleActive_WWM()                         WashingCycleActive_WWM
#define l_bool_rd_WiperActive_WWM()                                WiperActive_WWM
#define l_bool_rd_WiperInWipingArea_WWM()                          WiperInWipingArea_WWM
#define l_bool_wr_WiperInWipingArea_WWM(a)                         WiperInWipingArea_WWM = (a)



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
#endif
