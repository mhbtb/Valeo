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
#ifndef LIN_RLS_H
#define LIN_RLS_H

#define __RLS__

/******************************************************************************/
/*                        Definition of message handles                       */
/******************************************************************************/

#define cb_HANDLE_LinRespCmd_g              0
#define cb_HANDLE_ASIC_Frame_04_g           1
#define cb_HANDLE_ASIC_Frame_03_g           2
#define cb_HANDLE_ASIC_Frame_02_g           3
#define cb_HANDLE_ASIC_Frame_01_g           4
#define cb_HANDLE_SoSes_01                  5
#define cb_HANDLE_RLSs_01_g                 6
#define cb_HANDLE_FSs_01_g                  7
#define cb_HANDLE_LinReqCmd_g               8
#define cb_HANDLE_WWSs_01_g                 9
#define cb_HANDLE_BCM1_LIN1_01_g            10

/******************************************************************************/
/*                    Declaration of exported variables                       */
/******************************************************************************/

extern MEMORY_ROM canuint8  cabLinRxDLCTbl[kLinNumberOfRxObjects];
extern canuint8* MEMORY_ROM capbLinRxDataPtrTbl[kLinNumberOfRxObjects];
extern MEMORY_ROM canuint8  cabLinTxDataLenTbl[kLinNumberOfTxObjects];
extern canuint8* MEMORY_ROM capbLinTxDataPtrTbl[kLinNumberOfTxObjects];
extern MEMORY_ROM canuint8  cabLinRxDataLenTbl[kLinNumberOfRxObjects];
//extern MEMORY_ROM canuint8  cabLinRxDLCTbl[];
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
/* PRQA S 0602 EOF *//*<< automatic generated code  >>*/
/* PRQA S 0635 EOF *//*<< automatic generated code  >>*/
/* PRQA S 750,759 EOF *//*<< 0750:union needed to reduce RAM usage >>*/
/* PRQA S 841 EOF *//*<< 841:use of #undef needed  >>*/

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
  canbittype                        SoSe_SunInt_2D_Li: 8;
  canbittype                        SoSe_SunInt_2D_Re: 8;
  canbittype                                  unused0: 8;
  canbittype                                  unused1: 8;
  canbittype                                  unused2: 8;
  canbittype                                  unused3: 8;
  canbittype                                  unused4: 8;
  canbittype                                  unused5: 8;
} _c_SoSes_01_msgType;

typedef struct {
  canbittype                              RLS_Zaehler: 4;
  canbittype                   RLS_Qualifizierungsbit: 1;
  canbittype                RS_Wischergeschwindigkeit: 3;
  canbittype                               RS_Schwall: 1;
  canbittype                 RS_Verglasung_schliessen: 1;
  canbittype                  RS_versParklage_Wischer: 1;
  canbittype                             LS_Licht_ein: 1;
  canbittype                      LS_Licht_ein_invers: 1;
  canbittype                                LS_Dunkel: 1;
  canbittype                     LS_Autobahnfahrlicht: 1;
  canbittype                        RS_Regenfahrlicht: 1;
  canbittype                      RS_AdaptierungError: 1;
  canbittype                                 RS_Error: 1;
  canbittype                                 LS_Error: 1;
  canbittype                        RLS_ResponseError: 1;
  canbittype                   LS_Helligkeit_FW_boost: 4;
  canbittype                         LS_Helligkeit_IR: 8;
  canbittype                       LS_Helligkeit_FW_0: 8;
  canbittype                       LS_Helligkeit_FW_1: 2;
  canbittype                                  unused1: 2;
  canbittype                            RS_Regenmenge: 4;
  canbittype                                  unused2: 8;
  canbittype                                  unused3: 1;
  canbittype                         RLS_Adressegment: 3;
  canbittype                         RLS_AdressInhalt: 4;
} _c_RLSs_01_msgType;

typedef struct {
  canbittype                            FS_Taupunkt_0: 8;
  canbittype                            FS_Taupunkt_1: 2;
  canbittype                                  unused0: 5;
  canbittype                         FS_ResponseError: 1;
  canbittype                        FS_Temp_Scheibe_0: 8;
  canbittype                        FS_Temp_Scheibe_1: 2;
  canbittype                                  unused1: 6;
  canbittype                           FS_Temp_Sensor: 8;
  canbittype                       FS_Luftfeuchte_rel: 8;
  canbittype                                  unused2: 8;
  canbittype                                  unused3: 8;
} _c_FSs_01_msgType;


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
  canbittype                            Wischer_aktiv: 1;
  canbittype                                  unused0: 1;
  canbittype                        Wischer_Wendelage: 1;
  canbittype                         Wischer_Parklage: 1;
  canbittype                  Wischer_Servicestellung: 1;
  canbittype                                  unused1: 3;
  canbittype                     Wischzykluszaehler_0: 8;
  canbittype                     Wischzykluszaehler_1: 8;
  canbittype                           Wischer1_Error: 1;
  canbittype                       Wischer1_Ueberlast: 1;
  canbittype                Wischer1_ErrorGueltigkeit: 1;
  canbittype                           Wischer2_Error: 1;
  canbittype                       Wischer2_Ueberlast: 1;
  canbittype                Wischer2_ErrorGueltigkeit: 1;
  canbittype                                  unused2: 1;
  canbittype                    Wischer_ResponseError: 1;
  canbittype            Wischer1_Wischgeschwindigkeit: 6;
  canbittype                                  unused3: 2;
  canbittype                                  unused4: 1;
  canbittype                         WWS_Adressegment: 3;
  canbittype                         WWS_AdressInhalt: 4;
} _c_WWSs_01_msgType;

typedef struct {
  canbittype                           Master_Zaehler: 4;
  canbittype                                Klemme_15: 1;
  canbittype                                 Klemme_X: 1;
  canbittype                         Verglasung_offen: 1;
  canbittype                     Fronthaube_geoeffnet: 1;
  canbittype                       WH_Intervallstufen: 4;
  canbittype                           WH_Tippwischen: 1;
  canbittype                             WH_Intervall: 1;
  canbittype                         WH_WischerStufe1: 1;
  canbittype                         WH_WischerStufe2: 1;
  canbittype                          WH_Frontwaschen: 1;
  canbittype                  Servicestellung_Wischer: 1;
  canbittype                   Winterstellung_Wischer: 1;
  canbittype                  Wendelage_unten_Wischer: 1;
  canbittype                   Wendelage_oben_Wischer: 1;
  canbittype                                 SMLS_alt: 1;
  canbittype                             Autoaktiv_RS: 1;
  canbittype                                  unused0: 1;
  canbittype                                  unused1: 4;
  canbittype                        BCM_Wischer_aktiv: 1;
  canbittype                     BCM_Wischer_Parklage: 1;
  canbittype                    BCM_Wischer_Wendelage: 1;
  canbittype                          BCM_Wischer_Art: 1;
  canbittype                        ESP_v_Signal_8Bit: 8;
  canbittype                           Aussentemp_gef: 8;
  canbittype                       Empfindlichkeit_LS: 3;
  canbittype                         Deaktivierung_RS: 1;
  canbittype                       Empfindlichkeit_RS: 3;
  canbittype                                  unused2: 1;
  canbittype                                  unused3: 2;
  canbittype                     Adressegment_WWS_RLS: 2;
  canbittype                     Adressinhalt_WWS_RLS: 4;
} _c_BCM1_LIN1_01_msgType;


/******************************************************************************/
/*                               Message Unions                               */
/******************************************************************************/


/* Send messages */
/* PRQA S 0750,759 50  *//*<< 0750:union needed to reduce RAM usage >>*/

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
    _c_SoSes_01_msgType soses_01;
} _c_SoSes_01_buf;

typedef union {
    unsigned char _c[8];
    _c_RLSs_01_msgType rlss_01;
} _c_RLSs_01_buf;

typedef union {
    unsigned char _c[8];
    _c_FSs_01_msgType fss_01;
} _c_FSs_01_buf;


/* Receive messages */

typedef union {
    unsigned char _c[8];
    _c_LinReqCmd_msgType linreqcmd;
} _c_LinReqCmd_buf;

typedef union {
    unsigned char _c[6];
    _c_WWSs_01_msgType wwss_01;
} _c_WWSs_01_buf;

typedef union {
    unsigned char _c[8];
    _c_BCM1_LIN1_01_msgType bcm1_lin1_01;
} _c_BCM1_LIN1_01_buf;


/******************************************************************************/
/*                          Databuffer for send objects                       */
/******************************************************************************/

extern MEMORY_FAR _c_LinRespCmd_buf LinRespCmd;
extern MEMORY_FAR _c_ASIC_Frame_04_buf ASIC_Frame_04;
extern MEMORY_FAR _c_ASIC_Frame_03_buf ASIC_Frame_03;
extern MEMORY_FAR _c_ASIC_Frame_02_buf ASIC_Frame_02;
extern MEMORY_FAR _c_ASIC_Frame_01_buf ASIC_Frame_01;
extern MEMORY_FAR _c_SoSes_01_buf SoSes_01;
extern MEMORY_FAR _c_RLSs_01_buf RLSs_01;
extern MEMORY_FAR _c_FSs_01_buf FSs_01;

/******************************************************************************/
/*                        Databuffer for confirmationflags                    */
/******************************************************************************/
/* PRQA S 3458 EOF *//*<< required for readability  >>*/
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
#define SoSes_01_conf_b             uLinConfirmationFlags.w[0].b5
#define l_flg_tst_SoSes_01()       (SoSes_01_conf_b != 0)
#define l_flg_clr_SoSes_01()       {SoSes_01_conf_b = 0;}
#define RLSs_01_conf_b             uLinConfirmationFlags.w[0].b6
#define l_flg_tst_RLSs_01()       (RLSs_01_conf_b != 0)
#define l_flg_clr_RLSs_01()       {RLSs_01_conf_b = 0;}
#define FSs_01_conf_b             uLinConfirmationFlags.w[0].b7
#define l_flg_tst_FSs_01()       (FSs_01_conf_b != 0)
#define l_flg_clr_FSs_01()       {FSs_01_conf_b = 0;}

/******************************************************************************/
/*                         Databuffer for receive objects                     */
/******************************************************************************/

extern MEMORY_FAR _c_LinReqCmd_buf LinReqCmd;
extern MEMORY_FAR _c_WWSs_01_buf WWSs_01;
extern MEMORY_FAR _c_BCM1_LIN1_01_buf BCM1_LIN1_01;

/******************************************************************************/
/*                          Databuffer for indicationflags                    */
/******************************************************************************/

#define LinReqCmd_ind_b             uLinIndicationFlags.w[0].b0
#define l_flg_tst_LinReqCmd()       (LinReqCmd_ind_b != 0)
#define l_flg_clr_LinReqCmd()       {LinReqCmd_ind_b = 0;}
#define WWSs_01_ind_b             uLinIndicationFlags.w[0].b1
#define l_flg_tst_WWSs_01()       (WWSs_01_ind_b != 0)
#define l_flg_clr_WWSs_01()       {WWSs_01_ind_b = 0;}
#define BCM1_LIN1_01_ind_b             uLinIndicationFlags.w[0].b2
#define l_flg_tst_BCM1_LIN1_01()       (BCM1_LIN1_01_ind_b != 0)
#define l_flg_clr_BCM1_LIN1_01()       {BCM1_LIN1_01_ind_b = 0;}

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
#define SoSe_SunInt_2D_Li                                                     SoSes_01.soses_01.SoSe_SunInt_2D_Li
#define SoSe_SunInt_2D_Re                                                     SoSes_01.soses_01.SoSe_SunInt_2D_Re
#define RLS_Zaehler                                                           RLSs_01.rlss_01.RLS_Zaehler
#define RLS_Qualifizierungsbit                                                RLSs_01.rlss_01.RLS_Qualifizierungsbit
#define RS_Wischergeschwindigkeit                                             RLSs_01.rlss_01.RS_Wischergeschwindigkeit
#define RS_Schwall                                                            RLSs_01.rlss_01.RS_Schwall
#define RS_Verglasung_schliessen                                              RLSs_01.rlss_01.RS_Verglasung_schliessen
#define RS_versParklage_Wischer                                               RLSs_01.rlss_01.RS_versParklage_Wischer
#define LS_Licht_ein                                                          RLSs_01.rlss_01.LS_Licht_ein
#define LS_Licht_ein_invers                                                   RLSs_01.rlss_01.LS_Licht_ein_invers
#define LS_Dunkel                                                             RLSs_01.rlss_01.LS_Dunkel
#define LS_Autobahnfahrlicht                                                  RLSs_01.rlss_01.LS_Autobahnfahrlicht
#define RS_Regenfahrlicht                                                     RLSs_01.rlss_01.RS_Regenfahrlicht
#define RS_AdaptierungError                                                   RLSs_01.rlss_01.RS_AdaptierungError
#define RS_Error                                                              RLSs_01.rlss_01.RS_Error
#define LS_Error                                                              RLSs_01.rlss_01.LS_Error
#define RLS_ResponseError                                                     RLSs_01.rlss_01.RLS_ResponseError
#define LS_Helligkeit_FW_boost                                                RLSs_01.rlss_01.LS_Helligkeit_FW_boost
#define LS_Helligkeit_IR                                                      RLSs_01.rlss_01.LS_Helligkeit_IR
#define LS_Helligkeit_FW_0                                                    RLSs_01.rlss_01.LS_Helligkeit_FW_0
#define LS_Helligkeit_FW_1                                                    RLSs_01.rlss_01.LS_Helligkeit_FW_1
#define LS_Helligkeit_FW(c)                                                   { LS_Helligkeit_FW_0= (uint8)(((uint16)(c) & 0xFF));\
                                                                                LS_Helligkeit_FW_1= (uint8)(((uint16)(c) & 0x03) >> 8);\
                                                                              }
#define RS_Regenmenge                                                         RLSs_01.rlss_01.RS_Regenmenge
#define RLS_Adressegment                                                      RLSs_01.rlss_01.RLS_Adressegment
#define RLS_AdressInhalt                                                      RLSs_01.rlss_01.RLS_AdressInhalt


#define FS_Taupunkt_0                                                FSs_01.fss_01.FS_Taupunkt_0
#define FS_Taupunkt_1                                                FSs_01.fss_01.FS_Taupunkt_1
#define FS_Taupunkt(c)                                               { FS_Taupunkt_0 = (uint8)(((uint16)(c) & 0xff));\
  FS_Taupunkt_1 = (uint8)(((uint16)(c) & 0xff00) >> 8);\
                                                                     }
#define FS_ResponseError                                             FSs_01.fss_01.FS_ResponseError
#define FS_Temp_Scheibe_0                                            FSs_01.fss_01.FS_Temp_Scheibe_0
#define FS_Temp_Scheibe_1                                            FSs_01.fss_01.FS_Temp_Scheibe_1
#define FS_Temp_Scheibe(c)                                           { FS_Temp_Scheibe_0 = (uint8)(((uint16)(c) & 0xff));\
  FS_Temp_Scheibe_1 = (uint8)(((uint16)(c) & 0xff00) >> 8);\
                                                                     }
#define FS_Temp_Sensor                                               FSs_01.fss_01.FS_Temp_Sensor
#define FS_Luftfeuchte_rel                                           FSs_01.fss_01.FS_Luftfeuchte_rel

#define l_u16_rd_FS_Taupunkt()                                      (canuint16)(((canuint16)(FS_Taupunkt_1) << 8)\
  | (FS_Taupunkt_0))
#define l_u16_wr_FS_Taupunkt(a)                                     {FS_Taupunkt_1 = ((canuint8)((a) >> 8));\
  FS_Taupunkt_0 = ((canuint8)(a));}
#define l_bool_rd_FS_ResponseError()                               FS_ResponseError
#define l_bool_wr_FS_ResponseError(a)                              {FS_ResponseError = (a);}
#define l_u16_rd_FS_Temp_Scheibe()                                  (canuint16)(((canuint16)(FS_Temp_Scheibe_1) << 8)\
  | (FS_Temp_Scheibe_0))
#define l_u16_wr_FS_Temp_Scheibe(a)                                 {FS_Temp_Scheibe_1 = ((canuint8)((a) >> 8));\
  FS_Temp_Scheibe_0 = ((canuint8)(a));}
#define l_u8_rd_FS_Temp_Sensor()                                   FS_Temp_Sensor
#define l_u8_wr_FS_Temp_Sensor(a)                                  {FS_Temp_Sensor = (a);}
#define l_u8_rd_FS_Luftfeuchte_rel()                               FS_Luftfeuchte_rel
#define l_u8_wr_FS_Luftfeuchte_rel(a)                              {FS_Luftfeuchte_rel = (a);}


#define MasterReqB0                                                           LinReqCmd.linreqcmd.MasterReqB0
#define MasterReqB1                                                           LinReqCmd.linreqcmd.MasterReqB1
#define MasterReqB2                                                           LinReqCmd.linreqcmd.MasterReqB2
#define MasterReqB3                                                           LinReqCmd.linreqcmd.MasterReqB3
#define MasterReqB4                                                           LinReqCmd.linreqcmd.MasterReqB4
#define MasterReqB5                                                           LinReqCmd.linreqcmd.MasterReqB5
#define MasterReqB6                                                           LinReqCmd.linreqcmd.MasterReqB6
#define MasterReqB7                                                           LinReqCmd.linreqcmd.MasterReqB7
#define Wischer_aktiv                                                         WWSs_01.wwss_01.Wischer_aktiv
#define Wischer_Wendelage                                                     WWSs_01.wwss_01.Wischer_Wendelage
#define Wischer_Parklage                                                      WWSs_01.wwss_01.Wischer_Parklage
#define Wischer_Servicestellung                                               WWSs_01.wwss_01.Wischer_Servicestellung
#define Wischzykluszaehler_0                                                  WWSs_01.wwss_01.Wischzykluszaehler_0
#define Wischzykluszaehler_1                                                  WWSs_01.wwss_01.Wischzykluszaehler_1
#define Wischzykluszaehler(c)                                                 { Wischzykluszaehler_0= (uint8)(((uint16)(c) & 0xFF));\
                                                                                Wischzykluszaehler_1= (uint8)(((uint16)(c) & 0xFF) >> 8);\
                                                                              }
#define Wischer1_Error                                                        WWSs_01.wwss_01.Wischer1_Error
#define Wischer1_Ueberlast                                                    WWSs_01.wwss_01.Wischer1_Ueberlast
#define Wischer1_ErrorGueltigkeit                                             WWSs_01.wwss_01.Wischer1_ErrorGueltigkeit
#define Wischer2_Error                                                        WWSs_01.wwss_01.Wischer2_Error
#define Wischer2_Ueberlast                                                    WWSs_01.wwss_01.Wischer2_Ueberlast
#define Wischer2_ErrorGueltigkeit                                             WWSs_01.wwss_01.Wischer2_ErrorGueltigkeit
#define Wischer_ResponseError                                                 WWSs_01.wwss_01.Wischer_ResponseError
#define Wischer1_Wischgeschwindigkeit                                         WWSs_01.wwss_01.Wischer1_Wischgeschwindigkeit
#define WWS_Adressegment                                                      WWSs_01.wwss_01.WWS_Adressegment
#define WWS_AdressInhalt                                                      WWSs_01.wwss_01.WWS_AdressInhalt
#define Master_Zaehler                                                        BCM1_LIN1_01.bcm1_lin1_01.Master_Zaehler
#define Klemme_15                                                             BCM1_LIN1_01.bcm1_lin1_01.Klemme_15
#define Klemme_X                                                              BCM1_LIN1_01.bcm1_lin1_01.Klemme_X
#define Verglasung_offen                                                      BCM1_LIN1_01.bcm1_lin1_01.Verglasung_offen
#define Fronthaube_geoeffnet                                                  BCM1_LIN1_01.bcm1_lin1_01.Fronthaube_geoeffnet
#define WH_Intervallstufen                                                    BCM1_LIN1_01.bcm1_lin1_01.WH_Intervallstufen
#define WH_Tippwischen                                                        BCM1_LIN1_01.bcm1_lin1_01.WH_Tippwischen
#define WH_Intervall1                                                         BCM1_LIN1_01.bcm1_lin1_01.WH_Intervall
#define WH_WischerStufe1                                                      BCM1_LIN1_01.bcm1_lin1_01.WH_WischerStufe1
#define WH_WischerStufe2                                                      BCM1_LIN1_01.bcm1_lin1_01.WH_WischerStufe2
#define WH_Frontwaschen                                                       BCM1_LIN1_01.bcm1_lin1_01.WH_Frontwaschen
#define Servicestellung_Wischer                                               BCM1_LIN1_01.bcm1_lin1_01.Servicestellung_Wischer
#define Winterstellung_Wischer                                                BCM1_LIN1_01.bcm1_lin1_01.Winterstellung_Wischer
#define Wendelage_unten_Wischer                                               BCM1_LIN1_01.bcm1_lin1_01.Wendelage_unten_Wischer
#define Wendelage_oben_Wischer                                                BCM1_LIN1_01.bcm1_lin1_01.Wendelage_oben_Wischer
#define SMLS_alt                                                              BCM1_LIN1_01.bcm1_lin1_01.SMLS_alt
#define Autoaktiv_RS                                                          BCM1_LIN1_01.bcm1_lin1_01.Autoaktiv_RS
#define BCM_Wischer_aktiv                                                     BCM1_LIN1_01.bcm1_lin1_01.BCM_Wischer_aktiv
#define BCM_Wischer_Parklage                                                  BCM1_LIN1_01.bcm1_lin1_01.BCM_Wischer_Parklage
#define BCM_Wischer_Wendelage                                                 BCM1_LIN1_01.bcm1_lin1_01.BCM_Wischer_Wendelage
#define BCM_Wischer_Art                                                       BCM1_LIN1_01.bcm1_lin1_01.BCM_Wischer_Art
#define ESP_v_Signal_8Bit                                                     BCM1_LIN1_01.bcm1_lin1_01.ESP_v_Signal_8Bit
#define Aussentemp_gef                                                        BCM1_LIN1_01.bcm1_lin1_01.Aussentemp_gef
#define Empfindlichkeit_LS                                                    BCM1_LIN1_01.bcm1_lin1_01.Empfindlichkeit_LS
#define Deaktivierung_RS                                                      BCM1_LIN1_01.bcm1_lin1_01.Deaktivierung_RS
#define Empfindlichkeit_RS                                                    BCM1_LIN1_01.bcm1_lin1_01.Empfindlichkeit_RS
#define Adressegment_WWS_RLS                                                  BCM1_LIN1_01.bcm1_lin1_01.Adressegment_WWS_RLS
#define Adressinhalt_WWS_RLS                                                  BCM1_LIN1_01.bcm1_lin1_01.Adressinhalt_WWS_RLS
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
#define l_u8_rd_SoSe_SunInt_2D_Li()                                         SoSe_SunInt_2D_Li
#define l_u8_wr_SoSe_SunInt_2D_Li(a)                                        {SoSe_SunInt_2D_Li = (a);}
#define l_u8_rd_SoSe_SunInt_2D_Re()                                         SoSe_SunInt_2D_Re
#define l_u8_wr_SoSe_SunInt_2D_Re(a)                                        {SoSe_SunInt_2D_Re = (a);}
#define l_u8_rd_RLS_Zaehler()                                               RLS_Zaehler
#define l_u8_wr_RLS_Zaehler(a)                                              {RLS_Zaehler = (a);}
#define l_bool_rd_RLS_Qualifizierungsbit()                                      RLS_Qualifizierungsbit
#define l_bool_wr_RLS_Qualifizierungsbit(a)                                     {RLS_Qualifizierungsbit = (a);}
#define l_u8_rd_RS_Wischergeschwindigkeit()                                 RS_Wischergeschwindigkeit
#define l_u8_wr_RS_Wischergeschwindigkeit(a)                                {RS_Wischergeschwindigkeit = (a);}
#define l_bool_rd_RS_Schwall()                                                  RS_Schwall
#define l_bool_wr_RS_Schwall(a)                                                 {RS_Schwall = (a);}
#define l_bool_rd_RS_Verglasung_schliesen()                                    RS_Verglasung_schliessen
#define l_bool_wr_RS_Verglasung_schliesen(a)                                   {RS_Verglasung_schliessen = (a);}
#define l_bool_rd_RS_versParklage_Wischer()                                     RS_versParklage_Wischer
#define l_bool_wr_RS_versParklage_Wischer(a)                                    {RS_versParklage_Wischer = (a);}
#define l_bool_rd_LS_Licht_ein()                                                LS_Licht_ein
#define l_bool_wr_LS_Licht_ein(a)                                               {LS_Licht_ein = (a);}
#define l_bool_rd_LS_Licht_ein_invers()                                         LS_Licht_ein_invers
#define l_bool_wr_LS_Licht_ein_invers(a)                                        {LS_Licht_ein_invers = (a);}
#define l_bool_rd_LS_Dunkel()                                                   LS_Dunkel
#define l_bool_wr_LS_Dunkel(a)                                                  {LS_Dunkel = (a);}
#define l_bool_rd_LS_Autobahnfahrlicht()                                        LS_Autobahnfahrlicht
#define l_bool_wr_LS_Autobahnfahrlicht(a)                                       {LS_Autobahnfahrlicht = (a);}
#define l_bool_rd_RS_Regenfahrlicht()                                           RS_Regenfahrlicht
#define l_bool_wr_RS_Regenfahrlicht(a)                                          {RS_Regenfahrlicht = (a);}
#define l_bool_rd_RS_AdaptierungError()                                         RS_AdaptierungError
#define l_bool_wr_RS_AdaptierungError(a)                                        {RS_AdaptierungError = (a);}
#define l_bool_rd_RS_Error()                                                    RS_Error
#define l_bool_wr_RS_Error(a)                                                   {RS_Error = (a);}
#define l_bool_rd_LS_Error()                                                    LS_Error
#define l_bool_wr_LS_Error(a)                                                   {LS_Error = (a);}
#define l_bool_rd_RLS_ResponseError()                                           RLS_ResponseError
#define l_bool_wr_RLS_ResponseError(a)                                          {RLS_ResponseError = (a);}
#define l_u8_rd_LS_Helligkeit_IR()                                           LS_Helligkeit_IR
#define l_u8_wr_LS_Helligkeit_IR(a)                                         {LS_Helligkeit_IR = (a);}
#define l_u4_wr_LS_Helligkeit_FW_boost(a)                                    {LS_Helligkeit_FW_boost = (a) ;}
#define l_u16_rd_LS_Helligkeit_FW()                                           (canuint16)(LS_Helligkeit_FW_0)\
                                                                                | ((canuint16)(LS_Helligkeit_FW_1)<<8)
#define l_u16_wr_LS_Helligkeit_FW(a)                                          {LS_Helligkeit_FW_0 = ((canuint8)(a));\
                                                                                 LS_Helligkeit_FW_1 = ((canuint8)((a)>>8));}
#define l_u8_rd_RS_Regenmenge()                                             RS_Regenmenge
#define l_u8_wr_RS_Regenmenge(a)                                            {RS_Regenmenge = (a);}
#define l_u8_rd_RLS_Adressegment()                                          RLS_Adressegment
#define l_u8_wr_RLS_Adressegment(a)                                         {RLS_Adressegment = (a);}
#define l_u8_rd_RLS_Adressinhalt()                                          RLS_AdressInhalt
#define l_u8_wr_RLS_Adressinhalt(a)                                         {RLS_AdressInhalt = (a);}



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
#define l_bool_rd_Wischer_aktiv()                                               Wischer_aktiv
#define l_bool_wr_Wischer_aktiv(a)                                              {Wischer_aktiv = (a);}
#define l_bool_rd_Wischer_Wendelage()                                           Wischer_Wendelage
#define l_bool_wr_Wischer_Wendelage(a)                                          {Wischer_Wendelage = (a);}
#define l_bool_rd_Wischer_Parklage()                                            Wischer_Parklage
#define l_bool_wr_Wischer_Parklage(a)                                           {Wischer_Parklage = (a);}
#define l_bool_rd_Wischer_Servicestellung()                                     Wischer_Servicestellung
#define l_bool_wr_Wischer_Servicestellung(a)                                    {Wischer_Servicestellung = (a);}
#define l_u16_rd_Wischzykluszaehler()                                         (canuint16)(Wischzykluszaehler_0)\
                                                                                | ((canuint16)(Wischzykluszaehler_1)<<8)
#define l_u16_wr_Wischzykluszaehler(a)                                        {Wischzykluszaehler_0 = ((canuint8)(a));\
                                                                                 Wischzykluszaehler_1 = ((canuint8)((a)>>8));}
#define l_bool_rd_Wischer1_Error()                                              Wischer1_Error
#define l_bool_wr_Wischer1_Error(a)                                             {Wischer1_Error = (a);}
#define l_bool_rd_Wischer1_Ueberlast()                                          Wischer1_Ueberlast
#define l_bool_wr_Wischer1_Ueberlast(a)                                         {Wischer1_Ueberlast = (a);}
#define l_bool_rd_Wischer1_ErrorGueltigkeit()                                   Wischer1_ErrorGueltigkeit
#define l_bool_wr_Wischer1_ErrorGueltigkeit(a)                                  {Wischer1_ErrorGueltigkeit = (a);}
#define l_bool_rd_Wischer2_Error()                                              Wischer2_Error
#define l_bool_wr_Wischer2_Error(a)                                             {Wischer2_Error = (a);}
#define l_bool_rd_Wischer2_Ueberlast()                                          Wischer2_Ueberlast
#define l_bool_wr_Wischer2_Ueberlast(a)                                         {Wischer2_Ueberlast = (a);}
#define l_bool_rd_Wischer2_ErrorGueltigkeit()                                   Wischer2_ErrorGueltigkeit
#define l_bool_wr_Wischer2_ErrorGueltigkeit(a)                                  {Wischer2_ErrorGueltigkeit = (a);}
#define l_bool_rd_Wischer_ResponseError()                                       Wischer_ResponseError
#define l_bool_wr_Wischer_ResponseError(a)                                      {Wischer_ResponseError = (a);}
#define l_u8_rd_Wischer1_Wischgeschwindigkeit()                             Wischer1_Wischgeschwindigkeit
#define l_u8_wr_Wischer1_Wischgeschwindigkeit(a)                            {Wischer1_Wischgeschwindigkeit = (a);}
#define l_u8_rd_WWS_Adressegment()                                          WWS_Adressegment
#define l_u8_wr_WWS_Adressegment(a)                                         {WWS_Adressegment = (a);}
#define l_u8_rd_WWS_AdressInhalt()                                          WWS_AdressInhalt
#define l_u8_wr_WWS_AdressInhalt(a)                                         {WWS_AdressInhalt = (a);}
#define l_u8_rd_Master_Zaehler()                                            Master_Zaehler
#define l_u8_wr_Master_Zaehler(a)                                           {Master_Zaehler = (a);}
#define l_bool_rd_Klemme_15()                                                   Klemme_15
#define l_bool_wr_Klemme_15(a)                                                  {Klemme_15 = (a);}
#define l_bool_rd_Klemme_X()                                                    Klemme_X
#define l_bool_wr_Klemme_X(a)                                                   {Klemme_X = (a);}
#define l_bool_rd_Verglasung_offen()                                            Verglasung_offen
#define l_bool_wr_Verglasung_offen(a)                                           {Verglasung_offen = (a);}
#define l_bool_rd_Fronthaube_geoeffnet()                                        Fronthaube_geoeffnet
#define l_bool_wr_Fronthaube_geoeffnet(a)                                       {Fronthaube_geoeffnet = (a);}
#define l_u8_rd_WH_Intervallstufe()                                        WH_Intervallstufen
#define l_u8_wr_WH_Intervallstufe(a)                                       {WH_Intervallstufen = (a);}
#define l_bool_rd_WH_Tippwischen()                                              WH_Tippwischen
#define l_bool_wr_WH_Tippwischen(a)                                             {WH_Tippwischen = (a);}
#define l_bool_rd_WH_Intervall()                                               WH_Intervall1
#define l_bool_wr_WH_Intervall(a)                                              {WH_Intervall1 = (a);}
#define l_bool_rd_WH_WischerStufe1()                                            WH_WischerStufe1
#define l_bool_wr_WH_WischerStufe1(a)                                           {WH_WischerStufe1 = (a);}
#define l_bool_rd_WH_WischerStufe2()                                            WH_WischerStufe2
#define l_bool_wr_WH_WischerStufe2(a)                                           {WH_WischerStufe2 = (a);}
#define l_bool_rd_WH_Frontwaschen()                                             WH_Frontwaschen
#define l_bool_wr_WH_Frontwaschen(a)                                            {WH_Frontwaschen = (a);}
#define l_bool_rd_Servicestellung_Wischer()                                     Servicestellung_Wischer
#define l_bool_wr_Servicestellung_Wischer(a)                                    {Servicestellung_Wischer = (a);}
#define l_bool_rd_Winterstellung_Wischer()                                      Winterstellung_Wischer
#define l_bool_wr_Winterstellung_Wischer(a)                                     {Winterstellung_Wischer = (a);}
#define l_bool_rd_Wendelage_unten_Wischer()                                     Wendelage_unten_Wischer
#define l_bool_wr_Wendelage_unten_Wischer(a)                                    {Wendelage_unten_Wischer = (a);}
#define l_bool_rd_Wendelage_oben_Wischer()                                      Wendelage_oben_Wischer
#define l_bool_wr_Wendelage_oben_Wischer(a)                                     {Wendelage_oben_Wischer = (a);}
#define l_bool_rd_SMLS_alt()                                                    SMLS_alt
#define l_bool_wr_SMLS_alt(a)                                                   {SMLS_alt = (a);}
#define l_bool_rd_Autoaktiv_RS()                                                Autoaktiv_RS
#define l_bool_wr_Autoaktiv_RS(a)                                               {Autoaktiv_RS = (a);}
#define l_bool_rd_BCM_Wischer_aktiv()                                           BCM_Wischer_aktiv
#define l_bool_wr_BCM_Wischer_aktiv(a)                                          {BCM_Wischer_aktiv = (a);}
#define l_bool_rd_BCM_Wischer_Parklage()                                        BCM_Wischer_Parklage
#define l_bool_wr_BCM_Wischer_Parklage(a)                                       {BCM_Wischer_Parklage = (a);}
#define l_bool_rd_BCM_Wischer_Wendelage()                                       BCM_Wischer_Wendelage
#define l_bool_wr_BCM_Wischer_Wendelage(a)                                      {BCM_Wischer_Wendelage = (a);}
#define l_bool_rd_BCM_Wischer_Art()                                             BCM_Wischer_Art
#define l_bool_wr_BCM_Wischer_Art(a)                                            {BCM_Wischer_Art = (a);}
#define l_u8_rd_ESP_v_Signal_8Bit()                                         ESP_v_Signal_8Bit
#define l_u8_wr_ESP_v_Signal_8Bit(a)                                        {ESP_v_Signal_8Bit = (a);}
#define l_u8_rd_Aussentemp_gef()                                            Aussentemp_gef
#define l_u8_wr_Aussentemp_gef(a)                                           {Aussentemp_gef = (a);}
#define l_u8_rd_Empfindlichkeit_LS()                                        Empfindlichkeit_LS
#define l_u8_wr_Empfindlichkeit_LS(a)                                       {Empfindlichkeit_LS = (a);}
#define l_u8_rd_Deaktivierung_RS()                                            Deaktivierung_RS
#define l_u8_wr_Deaktivierung_RS(a)                                           {Deaktivierung_RS = (a);}
#define l_u8_rd_Empfindlichkeit_RS()                                        Empfindlichkeit_RS
#define l_u8_wr_Empfindlichkeit_RS(a)                                       {Empfindlichkeit_RS = (a);}
#define l_u8_rd_Adressegment_WWS_RLS()                                      Adressegment_WWS_RLS
#define l_u8_wr_Adressegment_WWS_RLS(a)                                     {Adressegment_WWS_RLS = (a);}
#define l_u8_rd_Adressinhalt_WWS_RLS()                                      Adressinhalt_WWS_RLS
#define l_u8_wr_Adressinhalt_WWS_RLS(a)                                     {Adressinhalt_WWS_RLS = (a);}


#endif  /* I_LIN_RLS_H */
