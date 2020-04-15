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
#define cb_HANDLE_RlsmCem_SerNrLin1Fr01_CEM_LIN1 1
#define cb_HANDLE_RlsmCem_Lin1PartNrFr02_CEM_LIN1 2
#define cb_HANDLE_RlsmCem_Lin1PartNrFr01_CEM_LIN1 3
#define cb_HANDLE_RlsmCem_Lin1Fr03_CEM_LIN1 4
#define cb_HANDLE_RlsmCem_Lin1Fr02_CEM_LIN1 5
#define cb_HANDLE_RlsmCem_Lin1Fr01_CEM_LIN1 6
#define cb_HANDLE_LinReqCmd               7
#define cb_HANDLE_CemCem_Lin1Fr06_CEM_LIN1 8
#define cb_HANDLE_CemCem_Lin1Fr05_CEM_LIN1 9
#define cb_HANDLE_CemCem_Lin1Fr04_CEM_LIN1 10
#define cb_HANDLE_CemCem_Lin1Fr03_CEM_LIN1 11
#define cb_HANDLE_CemCem_Lin1Fr02_CEM_LIN1 12
#define cb_HANDLE_CemCem_Lin1Fr01_CEM_LIN1 13

#define cb_HANDLE_LinReqCmd_g     cb_HANDLE_LinReqCmd
#define cb_HANDLE_LinRespCmd_g    cb_HANDLE_LinRespCmd
#define cb_HANDLE_BCM1_LIN1_01_g   cb_HANDLE_CemCem_Lin1Fr01_CEM_LIN1
#define cb_HANDLE_BCM1_LIN1_02_g   cb_HANDLE_CemCem_Lin1Fr02_CEM_LIN1
#define cb_HANDLE_BCM1_LIN1_03_g   cb_HANDLE_CemCem_Lin1Fr03_CEM_LIN1
#define cb_HANDLE_BCM1_LIN1_04_g   cb_HANDLE_CemCem_Lin1Fr04_CEM_LIN1
#define cb_HANDLE_BCM1_LIN1_05_g   cb_HANDLE_CemCem_Lin1Fr05_CEM_LIN1
#define cb_HANDLE_WWSs_01_g        cb_HANDLE_CemCem_Lin1Fr06_CEM_LIN1
#define cb_HANDLE_RLSs_01_g        cb_HANDLE_RlsmCem_Lin1Fr01_CEM_LIN1 
#define cb_HANDLE_RLSs_02_g        cb_HANDLE_RlsmCem_Lin1PartNrFr01_CEM_LIN1 
#define cb_HANDLE_RLSs_03_g        cb_HANDLE_RlsmCem_SerNrLin1Fr01_CEM_LIN1 
#define cb_HANDLE_RLSs_04_g        cb_HANDLE_RlsmCem_Lin1PartNrFr02_CEM_LIN1 
#define cb_HANDLE_RLSs_05_g        cb_HANDLE_RlsmCem_Lin1Fr02_CEM_LIN1 
#define cb_HANDLE_RLSs_06_g        cb_HANDLE_RlsmCem_Lin1Fr03_CEM_LIN1 

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
  canbittype                    RLSMSerNoNr1_CEM_LIN1: 8;
  canbittype                    RLSMSerNoNr2_CEM_LIN1: 8;
  canbittype                    RLSMSerNoNr3_CEM_LIN1: 8;
  canbittype                    RLSMSerNoNr4_CEM_LIN1: 8;
} _c_RlsmCem_SerNrLin1Fr01_CEM_LIN1_msgType;

typedef struct {
  canbittype                 RLSMPartNo10Nr1_CEM_LIN1: 8;
  canbittype                 RLSMPartNo10Nr2_CEM_LIN1: 8;
  canbittype                 RLSMPartNo10Nr3_CEM_LIN1: 8;
  canbittype                 RLSMPartNo10Nr4_CEM_LIN1: 8;
  canbittype                 RLSMPartNo10Nr5_CEM_LIN1: 8;
  canbittype             RLSMPartNo10EndSgn1_CEM_LIN1: 8;
  canbittype             RLSMPartNo10EndSgn2_CEM_LIN1: 8;
  canbittype             RLSMPartNo10EndSgn3_CEM_LIN1: 8;
} _c_RlsmCem_Lin1PartNrFr02_CEM_LIN1_msgType;

typedef struct {
  canbittype                   RLSMPartNoNr1_CEM_LIN1: 8;
  canbittype                   RLSMPartNoNr2_CEM_LIN1: 8;
  canbittype                   RLSMPartNoNr3_CEM_LIN1: 8;
  canbittype                   RLSMPartNoNr4_CEM_LIN1: 8;
  canbittype               RLSMPartNoEndSgn1_CEM_LIN1: 8;
  canbittype               RLSMPartNoEndSgn2_CEM_LIN1: 8;
  canbittype               RLSMPartNoEndSgn3_CEM_LIN1: 8;
} _c_RlsmCem_Lin1PartNrFr01_CEM_LIN1_msgType;

typedef struct {
  canbittype                    SolarSnsrErr_CEM_LIN1: 1;
  canbittype                                  unused0: 2;
  canbittype RainSnsrDiagcRainSnsrHiVoltDetd_CEM_LIN1: 1;
  canbittype    RainSnsrDiagcRainSnsrHiTDetd_CEM_LIN1: 1;
  canbittype                       LiOprnMod_CEM_LIN1: 2;
  canbittype                    RainDetected_CEM_LIN1: 1;
  canbittype                    RainfallAmnt_CEM_LIN1: 4;
  canbittype                                  unused1: 4;
  canbittype                SolarSnsrLeValue_CEM_LIN1: 8;
  canbittype                SolarSnsrRiValue_CEM_LIN1: 8;
  canbittype                                  unused2: 8;
  canbittype                                  unused3: 8;
  canbittype                                  unused4: 8;
  canbittype                                  unused5: 8;
} _c_RlsmCem_Lin1Fr03_CEM_LIN1_msgType;

typedef struct {
  canbittype              CmptFrntWindDewT_CEM_LIN1_0: 8;
  canbittype              CmptFrntWindDewT_CEM_LIN1_1: 3;
  canbittype              AmbIllmnFwdStsCntr_CEM_LIN1: 4;
  canbittype                                  unused0: 1;
  canbittype        AmbIllmnFwdStsAmblillmn2_CEM_LIN1: 8;
  canbittype              AmbIllmnFwdStsChks_CEM_LIN1: 8;
  canbittype      AmbIllmnFwdStsAmblillmn1_CEM_LIN1_0: 8;
  canbittype      AmbIllmnFwdStsAmblillmn1_CEM_LIN1_1: 1;
  canbittype                                  unused1: 1;
  canbittype                   RelHumSnsrErr_CEM_LIN1: 1;
  canbittype                                  unused2: 2;
  canbittype                 CmptFrntWindT_CEM_LIN1_0: 3;
  canbittype                 CmptFrntWindT_CEM_LIN1_1: 8;
  canbittype                RelHumSnsrRelHum_CEM_LIN1: 8;
} _c_RlsmCem_Lin1Fr02_CEM_LIN1_msgType;

typedef struct {
  canbittype                   AutWinWipgCmd_CEM_LIN1: 3;
  canbittype                HudSnsrErrParChk_CEM_LIN1: 1;
  canbittype               HudSnsrErrSnsrErr_CEM_LIN1: 1;
  canbittype                                  unused0: 2;
  canbittype                          RainLi_CEM_LIN1: 1;
  canbittype           RainSnsrErrCalErrActv_CEM_LIN1: 1;
  canbittype               RainSnsrErrCalErr_CEM_LIN1: 1;
  canbittype          RainSnsrErrRainDetnErr_CEM_LIN1: 1;
  canbittype      RainSnsrErrRainDetnErrActv_CEM_LIN1: 1;
  canbittype                  WipgAutFrntMod_CEM_LIN1: 2;
  canbittype                                  unused1: 1;
  canbittype                     ErrRespRLSM_CEM_LIN1: 1;
  canbittype                                  unused2: 8;
  canbittype                    TwliBriRawQf_CEM_LIN1: 2;
  canbittype          TwliBriRawTwliBriRaw_CEM_LIN1_0: 6;
  canbittype          TwliBriRawTwliBriRaw_CEM_LIN1_1: 8;
  canbittype                                  unused3: 8;
  canbittype                     OutdBriChks_CEM_LIN1: 8;
  canbittype                      OutdBriSts_CEM_LIN1: 2;
  canbittype                     OutdBriCntr_CEM_LIN1: 4;
  canbittype                                  unused4: 2;
} _c_RlsmCem_Lin1Fr01_CEM_LIN1_msgType;


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
  canbittype                                  unused0: 4;
  canbittype                        WiprActv_CEM_LIN1: 1;
  canbittype                WiprInPrkgPosnLo_CEM_LIN1: 1;
  canbittype                    WiprInWipgAr_CEM_LIN1: 1;
  canbittype                    WshngCycActv_CEM_LIN1: 1;
} _c_CemCem_Lin1Fr06_CEM_LIN1_msgType;

typedef struct {
  canbittype                                  unused0: 8;
  canbittype                                  unused1: 8;
  canbittype                                  unused2: 1;
  canbittype               EnaOfflineMonitor_CEM_LIN1: 1;
  canbittype                                  unused3: 6;
  canbittype                                  unused4: 8;
  canbittype                                  unused5: 8;
  canbittype                                  unused6: 8;
  canbittype                                  unused7: 8;
} _c_CemCem_Lin1Fr05_CEM_LIN1_msgType;

typedef struct {
  canbittype                                  unused0: 8;
  canbittype                                  unused1: 8;
  canbittype                                  unused2: 8;
  canbittype                                  unused3: 8;
  canbittype                                  unused4: 8;
  canbittype                                  unused5: 4;
  canbittype                   RainSnsrLiThd_CEM_LIN1: 4;
  canbittype                                  unused6: 8;
} _c_CemCem_Lin1Fr04_CEM_LIN1_msgType;

typedef struct {
  canbittype       RainSnsrSnvtyForUsrSnvty0_CEM_LIN1: 4;
  canbittype       RainSnsrSnvtyForUsrSnvty1_CEM_LIN1: 4;
  canbittype       RainSnsrSnvtyForUsrSnvty2_CEM_LIN1: 4;
  canbittype       RainSnsrSnvtyForUsrSnvty3_CEM_LIN1: 4;
  canbittype       RainSnsrSnvtyForUsrSnvty4_CEM_LIN1: 4;
  canbittype       RainSnsrSnvtyForUsrSnvty5_CEM_LIN1: 4;
  canbittype       RainSnsrSnvtyForUsrSnvty6_CEM_LIN1: 4;
  canbittype                          VehTyp_CEM_LIN1: 4;
  canbittype                 WindCorrnValAmb_CEM_LIN1: 8;
  canbittype                WindCorrnValFrnt_CEM_LIN1: 8;
  canbittype                 WindCorrnValHud_CEM_LIN1: 8;
  canbittype                          FrqCfg_CEM_LIN1: 4;
  canbittype                      ReAdaptReq_CEM_LIN1: 1;
  canbittype                                  unused0: 3;
} _c_CemCem_Lin1Fr03_CEM_LIN1_msgType;

typedef struct {
  canbittype                     AmbTForVisy_CEM_LIN1: 8;
  canbittype                                  unused0: 8;
  canbittype                                  unused1: 8;
  canbittype                                  unused2: 8;
  canbittype                                  unused3: 8;
  canbittype                                  unused4: 8;
  canbittype                                  unused5: 8;
} _c_CemCem_Lin1Fr02_CEM_LIN1_msgType;

typedef struct {
  canbittype                   VehSpdForWipg_CEM_LIN1: 8;
  canbittype WipgPwrActvnSafeWipgPwrAcsyModSafe_CEM_LIN1: 2;
  canbittype WipgPwrActvnSafeWipgPwrDrvgModSafe_CEM_LIN1: 2;
  canbittype                   RainSensActvn_CEM_LIN1: 1;
  canbittype                 WshrLvrPosnSafe_CEM_LIN1: 2;
  canbittype                                  unused0: 1;
  canbittype WiprMotFrntLvrCmdSafeLvrInHiSpdPosnSafe_CEM_LIN1: 2;
  canbittype WiprMotFrntLvrCmdSafeLvrInLoSpdPosnSafe_CEM_LIN1: 2;
  canbittype WiprMotFrntLvrCmdSafeLvrInSnglStrokePos_CEM_LIN1: 1;
  canbittype WiprMotFrntLvrCmdSafeLvrInIntlPosn_CEM_LIN1: 1;
  canbittype                     HomeLinkEna_CEM_LIN1: 2;
  canbittype                  WiprMotIntlCmd_CEM_LIN1: 3;
  canbittype               WiprPosnForSrvReq_CEM_LIN1: 1;
  canbittype                                  unused1: 4;
  canbittype     IntrMirrCmdIntrMirrDimSnvty_CEM_LIN1: 2;
  canbittype             IntrMirrCmdDrvrSide_CEM_LIN1: 1;
  canbittype IntrMirrCmdIntrMirrWindHeatrCmpMag_CEM_LIN1: 1;
  canbittype          IntrMirrCmdIntrMirrEna_CEM_LIN1: 1;
  canbittype      IntrMirrCmdIntrMirrInhbDim_CEM_LIN1: 1;
  canbittype     IntrMirrCmdIntrMirrDiagcRst_CEM_LIN1: 1;
  canbittype IntrMirrCmdIntrMirrAsyFanCmpMag_CEM_LIN1: 1;
  canbittype               WiprMotFrntOffsAg_CEM_LIN1: 4;
  canbittype                                  unused2: 4;
} _c_CemCem_Lin1Fr01_CEM_LIN1_msgType;


/******************************************************************************/
/*                               Message Unions                               */
/******************************************************************************/


/* Send messages */

typedef union {
    unsigned char _c[8];
    _c_LinRespCmd_msgType linrespcmd;
} _c_LinRespCmd_buf;

typedef union {
    unsigned char _c[4];
    _c_RlsmCem_SerNrLin1Fr01_CEM_LIN1_msgType rlsmcem_sernrlin1fr01_cem_lin1;
} _c_RlsmCem_SerNrLin1Fr01_CEM_LIN1_buf;

typedef union {
    unsigned char _c[8];
    _c_RlsmCem_Lin1PartNrFr02_CEM_LIN1_msgType rlsmcem_lin1partnrfr02_cem_lin1;
} _c_RlsmCem_Lin1PartNrFr02_CEM_LIN1_buf;

typedef union {
    unsigned char _c[7];
    _c_RlsmCem_Lin1PartNrFr01_CEM_LIN1_msgType rlsmcem_lin1partnrfr01_cem_lin1;
} _c_RlsmCem_Lin1PartNrFr01_CEM_LIN1_buf;

typedef union {
    unsigned char _c[8];
    _c_RlsmCem_Lin1Fr03_CEM_LIN1_msgType rlsmcem_lin1fr03_cem_lin1;
} _c_RlsmCem_Lin1Fr03_CEM_LIN1_buf;

typedef union {
    unsigned char _c[8];
    _c_RlsmCem_Lin1Fr02_CEM_LIN1_msgType rlsmcem_lin1fr02_cem_lin1;
} _c_RlsmCem_Lin1Fr02_CEM_LIN1_buf;

typedef union {
    unsigned char _c[8];
    _c_RlsmCem_Lin1Fr01_CEM_LIN1_msgType rlsmcem_lin1fr01_cem_lin1;
} _c_RlsmCem_Lin1Fr01_CEM_LIN1_buf;


/* Receive messages */

typedef union {
    unsigned char _c[8];
    _c_LinReqCmd_msgType linreqcmd;
} _c_LinReqCmd_buf;

typedef union {
    unsigned char _c[1];
    _c_CemCem_Lin1Fr06_CEM_LIN1_msgType cemcem_lin1fr06_cem_lin1;
} _c_CemCem_Lin1Fr06_CEM_LIN1_buf;

typedef union {
    unsigned char _c[7];
    _c_CemCem_Lin1Fr05_CEM_LIN1_msgType cemcem_lin1fr05_cem_lin1;
} _c_CemCem_Lin1Fr05_CEM_LIN1_buf;

typedef union {
    unsigned char _c[7];
    _c_CemCem_Lin1Fr04_CEM_LIN1_msgType cemcem_lin1fr04_cem_lin1;
} _c_CemCem_Lin1Fr04_CEM_LIN1_buf;

typedef union {
    unsigned char _c[8];
    _c_CemCem_Lin1Fr03_CEM_LIN1_msgType cemcem_lin1fr03_cem_lin1;
} _c_CemCem_Lin1Fr03_CEM_LIN1_buf;

typedef union {
    unsigned char _c[7];
    _c_CemCem_Lin1Fr02_CEM_LIN1_msgType cemcem_lin1fr02_cem_lin1;
} _c_CemCem_Lin1Fr02_CEM_LIN1_buf;

typedef union {
    unsigned char _c[6];
    _c_CemCem_Lin1Fr01_CEM_LIN1_msgType cemcem_lin1fr01_cem_lin1;
} _c_CemCem_Lin1Fr01_CEM_LIN1_buf;


/******************************************************************************/
/*                          Databuffer for send objects                       */
/******************************************************************************/

extern MEMORY_FAR _c_LinRespCmd_buf LinRespCmd;
extern MEMORY_FAR _c_RlsmCem_SerNrLin1Fr01_CEM_LIN1_buf RlsmCem_SerNrLin1Fr01_CEM_LIN1;
extern MEMORY_FAR _c_RlsmCem_Lin1PartNrFr02_CEM_LIN1_buf RlsmCem_Lin1PartNrFr02_CEM_LIN1;
extern MEMORY_FAR _c_RlsmCem_Lin1PartNrFr01_CEM_LIN1_buf RlsmCem_Lin1PartNrFr01_CEM_LIN1;
extern MEMORY_FAR _c_RlsmCem_Lin1Fr03_CEM_LIN1_buf RlsmCem_Lin1Fr03_CEM_LIN1;
extern MEMORY_FAR _c_RlsmCem_Lin1Fr02_CEM_LIN1_buf RlsmCem_Lin1Fr02_CEM_LIN1;
extern MEMORY_FAR _c_RlsmCem_Lin1Fr01_CEM_LIN1_buf RlsmCem_Lin1Fr01_CEM_LIN1;

/******************************************************************************/
/*                        Databuffer for confirmationflags                    */
/******************************************************************************/

#define LinRespCmd_conf_b             uLinConfirmationFlags.w[0].b0
#define l_flg_tst_LinRespCmd()       (LinRespCmd_conf_b != 0)
#define l_flg_clr_LinRespCmd()       {LinRespCmd_conf_b = 0;}
#define RlsmCem_SerNrLin1Fr01_CEM_LIN1_conf_b             uLinConfirmationFlags.w[0].b1
#define l_flg_tst_RlsmCem_SerNrLin1Fr01_CEM_LIN1()       (RlsmCem_SerNrLin1Fr01_CEM_LIN1_conf_b != 0)
#define l_flg_clr_RlsmCem_SerNrLin1Fr01_CEM_LIN1()       {RlsmCem_SerNrLin1Fr01_CEM_LIN1_conf_b = 0;}
#define RlsmCem_Lin1PartNrFr02_CEM_LIN1_conf_b             uLinConfirmationFlags.w[0].b2
#define l_flg_tst_RlsmCem_Lin1PartNrFr02_CEM_LIN1()       (RlsmCem_Lin1PartNrFr02_CEM_LIN1_conf_b != 0)
#define l_flg_clr_RlsmCem_Lin1PartNrFr02_CEM_LIN1()       {RlsmCem_Lin1PartNrFr02_CEM_LIN1_conf_b = 0;}
#define RlsmCem_Lin1PartNrFr01_CEM_LIN1_conf_b             uLinConfirmationFlags.w[0].b3
#define l_flg_tst_RlsmCem_Lin1PartNrFr01_CEM_LIN1()       (RlsmCem_Lin1PartNrFr01_CEM_LIN1_conf_b != 0)
#define l_flg_clr_RlsmCem_Lin1PartNrFr01_CEM_LIN1()       {RlsmCem_Lin1PartNrFr01_CEM_LIN1_conf_b = 0;}
#define RlsmCem_Lin1Fr03_CEM_LIN1_conf_b             uLinConfirmationFlags.w[0].b4
#define l_flg_tst_RlsmCem_Lin1Fr03_CEM_LIN1()       (RlsmCem_Lin1Fr03_CEM_LIN1_conf_b != 0)
#define l_flg_clr_RlsmCem_Lin1Fr03_CEM_LIN1()       {RlsmCem_Lin1Fr03_CEM_LIN1_conf_b = 0;}
#define RlsmCem_Lin1Fr02_CEM_LIN1_conf_b             uLinConfirmationFlags.w[0].b5
#define l_flg_tst_RlsmCem_Lin1Fr02_CEM_LIN1()       (RlsmCem_Lin1Fr02_CEM_LIN1_conf_b != 0)
#define l_flg_clr_RlsmCem_Lin1Fr02_CEM_LIN1()       {RlsmCem_Lin1Fr02_CEM_LIN1_conf_b = 0;}
#define RlsmCem_Lin1Fr01_CEM_LIN1_conf_b             uLinConfirmationFlags.w[0].b6
#define l_flg_tst_RlsmCem_Lin1Fr01_CEM_LIN1()       (RlsmCem_Lin1Fr01_CEM_LIN1_conf_b != 0)
#define l_flg_clr_RlsmCem_Lin1Fr01_CEM_LIN1()       {RlsmCem_Lin1Fr01_CEM_LIN1_conf_b = 0;}

/******************************************************************************/
/*                         Databuffer for receive objects                     */
/******************************************************************************/

extern MEMORY_FAR _c_LinReqCmd_buf LinReqCmd;
extern MEMORY_FAR _c_CemCem_Lin1Fr06_CEM_LIN1_buf CemCem_Lin1Fr06_CEM_LIN1;
extern MEMORY_FAR _c_CemCem_Lin1Fr05_CEM_LIN1_buf CemCem_Lin1Fr05_CEM_LIN1;
extern MEMORY_FAR _c_CemCem_Lin1Fr04_CEM_LIN1_buf CemCem_Lin1Fr04_CEM_LIN1;
extern MEMORY_FAR _c_CemCem_Lin1Fr03_CEM_LIN1_buf CemCem_Lin1Fr03_CEM_LIN1;
extern MEMORY_FAR _c_CemCem_Lin1Fr02_CEM_LIN1_buf CemCem_Lin1Fr02_CEM_LIN1;
extern MEMORY_FAR _c_CemCem_Lin1Fr01_CEM_LIN1_buf CemCem_Lin1Fr01_CEM_LIN1;

/******************************************************************************/
/*                          Databuffer for indicationflags                    */
/******************************************************************************/

#define LinReqCmd_ind_b             uLinIndicationFlags.w[0].b0
#define l_flg_tst_LinReqCmd()       (LinReqCmd_ind_b != 0)
#define l_flg_clr_LinReqCmd()       {LinReqCmd_ind_b = 0;}
#define CemCem_Lin1Fr06_CEM_LIN1_ind_b             uLinIndicationFlags.w[0].b1
#define l_flg_tst_CemCem_Lin1Fr06_CEM_LIN1()       (CemCem_Lin1Fr06_CEM_LIN1_ind_b != 0)
#define l_flg_clr_CemCem_Lin1Fr06_CEM_LIN1()       {CemCem_Lin1Fr06_CEM_LIN1_ind_b = 0;}
#define CemCem_Lin1Fr05_CEM_LIN1_ind_b             uLinIndicationFlags.w[0].b2
#define l_flg_tst_CemCem_Lin1Fr05_CEM_LIN1()       (CemCem_Lin1Fr05_CEM_LIN1_ind_b != 0)
#define l_flg_clr_CemCem_Lin1Fr05_CEM_LIN1()       {CemCem_Lin1Fr05_CEM_LIN1_ind_b = 0;}
#define CemCem_Lin1Fr04_CEM_LIN1_ind_b             uLinIndicationFlags.w[0].b3
#define l_flg_tst_CemCem_Lin1Fr04_CEM_LIN1()       (CemCem_Lin1Fr04_CEM_LIN1_ind_b != 0)
#define l_flg_clr_CemCem_Lin1Fr04_CEM_LIN1()       {CemCem_Lin1Fr04_CEM_LIN1_ind_b = 0;}
#define CemCem_Lin1Fr03_CEM_LIN1_ind_b             uLinIndicationFlags.w[0].b4
#define l_flg_tst_CemCem_Lin1Fr03_CEM_LIN1()       (CemCem_Lin1Fr03_CEM_LIN1_ind_b != 0)
#define l_flg_clr_CemCem_Lin1Fr03_CEM_LIN1()       {CemCem_Lin1Fr03_CEM_LIN1_ind_b = 0;}
#define CemCem_Lin1Fr02_CEM_LIN1_ind_b             uLinIndicationFlags.w[0].b5
#define l_flg_tst_CemCem_Lin1Fr02_CEM_LIN1()       (CemCem_Lin1Fr02_CEM_LIN1_ind_b != 0)
#define l_flg_clr_CemCem_Lin1Fr02_CEM_LIN1()       {CemCem_Lin1Fr02_CEM_LIN1_ind_b = 0;}
#define CemCem_Lin1Fr01_CEM_LIN1_ind_b             uLinIndicationFlags.w[0].b6
#define l_flg_tst_CemCem_Lin1Fr01_CEM_LIN1()       (CemCem_Lin1Fr01_CEM_LIN1_ind_b != 0)
#define l_flg_clr_CemCem_Lin1Fr01_CEM_LIN1()       {CemCem_Lin1Fr01_CEM_LIN1_ind_b = 0;}

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
#define RLSMSerNoNr1_CEM_LIN1                                                 RlsmCem_SerNrLin1Fr01_CEM_LIN1.rlsmcem_sernrlin1fr01_cem_lin1.RLSMSerNoNr1_CEM_LIN1
#define RLSMSerNoNr2_CEM_LIN1                                                 RlsmCem_SerNrLin1Fr01_CEM_LIN1.rlsmcem_sernrlin1fr01_cem_lin1.RLSMSerNoNr2_CEM_LIN1
#define RLSMSerNoNr3_CEM_LIN1                                                 RlsmCem_SerNrLin1Fr01_CEM_LIN1.rlsmcem_sernrlin1fr01_cem_lin1.RLSMSerNoNr3_CEM_LIN1
#define RLSMSerNoNr4_CEM_LIN1                                                 RlsmCem_SerNrLin1Fr01_CEM_LIN1.rlsmcem_sernrlin1fr01_cem_lin1.RLSMSerNoNr4_CEM_LIN1
#define RLSMPartNo10Nr1_CEM_LIN1                                              RlsmCem_Lin1PartNrFr02_CEM_LIN1.rlsmcem_lin1partnrfr02_cem_lin1.RLSMPartNo10Nr1_CEM_LIN1
#define RLSMPartNo10Nr2_CEM_LIN1                                              RlsmCem_Lin1PartNrFr02_CEM_LIN1.rlsmcem_lin1partnrfr02_cem_lin1.RLSMPartNo10Nr2_CEM_LIN1
#define RLSMPartNo10Nr3_CEM_LIN1                                              RlsmCem_Lin1PartNrFr02_CEM_LIN1.rlsmcem_lin1partnrfr02_cem_lin1.RLSMPartNo10Nr3_CEM_LIN1
#define RLSMPartNo10Nr4_CEM_LIN1                                              RlsmCem_Lin1PartNrFr02_CEM_LIN1.rlsmcem_lin1partnrfr02_cem_lin1.RLSMPartNo10Nr4_CEM_LIN1
#define RLSMPartNo10Nr5_CEM_LIN1                                              RlsmCem_Lin1PartNrFr02_CEM_LIN1.rlsmcem_lin1partnrfr02_cem_lin1.RLSMPartNo10Nr5_CEM_LIN1
#define RLSMPartNo10EndSgn1_CEM_LIN1                                          RlsmCem_Lin1PartNrFr02_CEM_LIN1.rlsmcem_lin1partnrfr02_cem_lin1.RLSMPartNo10EndSgn1_CEM_LIN1
#define RLSMPartNo10EndSgn2_CEM_LIN1                                          RlsmCem_Lin1PartNrFr02_CEM_LIN1.rlsmcem_lin1partnrfr02_cem_lin1.RLSMPartNo10EndSgn2_CEM_LIN1
#define RLSMPartNo10EndSgn3_CEM_LIN1                                          RlsmCem_Lin1PartNrFr02_CEM_LIN1.rlsmcem_lin1partnrfr02_cem_lin1.RLSMPartNo10EndSgn3_CEM_LIN1
#define RLSMPartNoNr1_CEM_LIN1                                                RlsmCem_Lin1PartNrFr01_CEM_LIN1.rlsmcem_lin1partnrfr01_cem_lin1.RLSMPartNoNr1_CEM_LIN1
#define RLSMPartNoNr2_CEM_LIN1                                                RlsmCem_Lin1PartNrFr01_CEM_LIN1.rlsmcem_lin1partnrfr01_cem_lin1.RLSMPartNoNr2_CEM_LIN1
#define RLSMPartNoNr3_CEM_LIN1                                                RlsmCem_Lin1PartNrFr01_CEM_LIN1.rlsmcem_lin1partnrfr01_cem_lin1.RLSMPartNoNr3_CEM_LIN1
#define RLSMPartNoNr4_CEM_LIN1                                                RlsmCem_Lin1PartNrFr01_CEM_LIN1.rlsmcem_lin1partnrfr01_cem_lin1.RLSMPartNoNr4_CEM_LIN1
#define RLSMPartNoEndSgn1_CEM_LIN1                                            RlsmCem_Lin1PartNrFr01_CEM_LIN1.rlsmcem_lin1partnrfr01_cem_lin1.RLSMPartNoEndSgn1_CEM_LIN1
#define RLSMPartNoEndSgn2_CEM_LIN1                                            RlsmCem_Lin1PartNrFr01_CEM_LIN1.rlsmcem_lin1partnrfr01_cem_lin1.RLSMPartNoEndSgn2_CEM_LIN1
#define RLSMPartNoEndSgn3_CEM_LIN1                                            RlsmCem_Lin1PartNrFr01_CEM_LIN1.rlsmcem_lin1partnrfr01_cem_lin1.RLSMPartNoEndSgn3_CEM_LIN1
#define SolarSnsrErr_CEM_LIN1                                                 RlsmCem_Lin1Fr03_CEM_LIN1.rlsmcem_lin1fr03_cem_lin1.SolarSnsrErr_CEM_LIN1
#define RainSnsrDiagcRainSnsrHiVoltDetd_CEM_LIN1                              RlsmCem_Lin1Fr03_CEM_LIN1.rlsmcem_lin1fr03_cem_lin1.RainSnsrDiagcRainSnsrHiVoltDetd_CEM_LIN1
#define RainSnsrDiagcRainSnsrHiTDetd_CEM_LIN1                                 RlsmCem_Lin1Fr03_CEM_LIN1.rlsmcem_lin1fr03_cem_lin1.RainSnsrDiagcRainSnsrHiTDetd_CEM_LIN1
#define LiOprnMod_CEM_LIN1                                                    RlsmCem_Lin1Fr03_CEM_LIN1.rlsmcem_lin1fr03_cem_lin1.LiOprnMod_CEM_LIN1
#define RainDetected_CEM_LIN1                                                 RlsmCem_Lin1Fr03_CEM_LIN1.rlsmcem_lin1fr03_cem_lin1.RainDetected_CEM_LIN1
#define RainfallAmnt_CEM_LIN1                                                 RlsmCem_Lin1Fr03_CEM_LIN1.rlsmcem_lin1fr03_cem_lin1.RainfallAmnt_CEM_LIN1
#define SolarSnsrLeValue_CEM_LIN1                                             RlsmCem_Lin1Fr03_CEM_LIN1.rlsmcem_lin1fr03_cem_lin1.SolarSnsrLeValue_CEM_LIN1
#define SolarSnsrRiValue_CEM_LIN1                                             RlsmCem_Lin1Fr03_CEM_LIN1.rlsmcem_lin1fr03_cem_lin1.SolarSnsrRiValue_CEM_LIN1
#define CmptFrntWindDewT_CEM_LIN1_0                                           RlsmCem_Lin1Fr02_CEM_LIN1.rlsmcem_lin1fr02_cem_lin1.CmptFrntWindDewT_CEM_LIN1_0
#define CmptFrntWindDewT_CEM_LIN1_1                                           RlsmCem_Lin1Fr02_CEM_LIN1.rlsmcem_lin1fr02_cem_lin1.CmptFrntWindDewT_CEM_LIN1_1
#define CmptFrntWindDewT_CEM_LIN1(c)                                          { CmptFrntWindDewT_CEM_LIN1_0= (uint8)(((uint16)(c) & 0xFF));\
                                                                                CmptFrntWindDewT_CEM_LIN1_1= (uint8)(((uint16)(c) & 0x07) >> 8);\
                                                                              }
#define AmbIllmnFwdStsCntr_CEM_LIN1                                           RlsmCem_Lin1Fr02_CEM_LIN1.rlsmcem_lin1fr02_cem_lin1.AmbIllmnFwdStsCntr_CEM_LIN1
#define AmbIllmnFwdStsAmblillmn2_CEM_LIN1                                     RlsmCem_Lin1Fr02_CEM_LIN1.rlsmcem_lin1fr02_cem_lin1.AmbIllmnFwdStsAmblillmn2_CEM_LIN1
#define AmbIllmnFwdStsChks_CEM_LIN1                                           RlsmCem_Lin1Fr02_CEM_LIN1.rlsmcem_lin1fr02_cem_lin1.AmbIllmnFwdStsChks_CEM_LIN1
#define AmbIllmnFwdStsAmblillmn1_CEM_LIN1_0                                   RlsmCem_Lin1Fr02_CEM_LIN1.rlsmcem_lin1fr02_cem_lin1.AmbIllmnFwdStsAmblillmn1_CEM_LIN1_0
#define AmbIllmnFwdStsAmblillmn1_CEM_LIN1_1                                   RlsmCem_Lin1Fr02_CEM_LIN1.rlsmcem_lin1fr02_cem_lin1.AmbIllmnFwdStsAmblillmn1_CEM_LIN1_1
#define AmbIllmnFwdStsAmblillmn1_CEM_LIN1(c)                                  { AmbIllmnFwdStsAmblillmn1_CEM_LIN1_0= (uint8)(((uint16)(c) & 0xFF));\
                                                                                AmbIllmnFwdStsAmblillmn1_CEM_LIN1_1= (uint8)(((uint16)(c) & 0x01) >> 8);\
                                                                              }
#define RelHumSnsrErr_CEM_LIN1                                                RlsmCem_Lin1Fr02_CEM_LIN1.rlsmcem_lin1fr02_cem_lin1.RelHumSnsrErr_CEM_LIN1
#define CmptFrntWindT_CEM_LIN1_0                                              RlsmCem_Lin1Fr02_CEM_LIN1.rlsmcem_lin1fr02_cem_lin1.CmptFrntWindT_CEM_LIN1_0
#define CmptFrntWindT_CEM_LIN1_1                                              RlsmCem_Lin1Fr02_CEM_LIN1.rlsmcem_lin1fr02_cem_lin1.CmptFrntWindT_CEM_LIN1_1
#define CmptFrntWindT_CEM_LIN1(c)                                             { CmptFrntWindT_CEM_LIN1_0= (uint8)(((uint16)(c) & 0x07));\
                                                                                CmptFrntWindT_CEM_LIN1_1= (uint8)(((uint16)(c) & 0xFF) >> 3);\
                                                                              }
#define RelHumSnsrRelHum_CEM_LIN1                                             RlsmCem_Lin1Fr02_CEM_LIN1.rlsmcem_lin1fr02_cem_lin1.RelHumSnsrRelHum_CEM_LIN1
#define AutWinWipgCmd_CEM_LIN1                                                RlsmCem_Lin1Fr01_CEM_LIN1.rlsmcem_lin1fr01_cem_lin1.AutWinWipgCmd_CEM_LIN1
#define HudSnsrErrParChk_CEM_LIN1                                             RlsmCem_Lin1Fr01_CEM_LIN1.rlsmcem_lin1fr01_cem_lin1.HudSnsrErrParChk_CEM_LIN1
#define HudSnsrErrSnsrErr_CEM_LIN1                                            RlsmCem_Lin1Fr01_CEM_LIN1.rlsmcem_lin1fr01_cem_lin1.HudSnsrErrSnsrErr_CEM_LIN1
#define RainLi_CEM_LIN1                                                       RlsmCem_Lin1Fr01_CEM_LIN1.rlsmcem_lin1fr01_cem_lin1.RainLi_CEM_LIN1
#define RainSnsrErrCalErrActv_CEM_LIN1                                        RlsmCem_Lin1Fr01_CEM_LIN1.rlsmcem_lin1fr01_cem_lin1.RainSnsrErrCalErrActv_CEM_LIN1
#define RainSnsrErrCalErr_CEM_LIN1                                            RlsmCem_Lin1Fr01_CEM_LIN1.rlsmcem_lin1fr01_cem_lin1.RainSnsrErrCalErr_CEM_LIN1
#define RainSnsrErrRainDetnErr_CEM_LIN1                                       RlsmCem_Lin1Fr01_CEM_LIN1.rlsmcem_lin1fr01_cem_lin1.RainSnsrErrRainDetnErr_CEM_LIN1
#define RainSnsrErrRainDetnErrActv_CEM_LIN1                                   RlsmCem_Lin1Fr01_CEM_LIN1.rlsmcem_lin1fr01_cem_lin1.RainSnsrErrRainDetnErrActv_CEM_LIN1
#define WipgAutFrntMod_CEM_LIN1                                               RlsmCem_Lin1Fr01_CEM_LIN1.rlsmcem_lin1fr01_cem_lin1.WipgAutFrntMod_CEM_LIN1
#define ErrRespRLSM_CEM_LIN1                                                  RlsmCem_Lin1Fr01_CEM_LIN1.rlsmcem_lin1fr01_cem_lin1.ErrRespRLSM_CEM_LIN1
#define TwliBriRawQf_CEM_LIN1                                                 RlsmCem_Lin1Fr01_CEM_LIN1.rlsmcem_lin1fr01_cem_lin1.TwliBriRawQf_CEM_LIN1
#define TwliBriRawTwliBriRaw_CEM_LIN1_0                                       RlsmCem_Lin1Fr01_CEM_LIN1.rlsmcem_lin1fr01_cem_lin1.TwliBriRawTwliBriRaw_CEM_LIN1_0
#define TwliBriRawTwliBriRaw_CEM_LIN1_1                                       RlsmCem_Lin1Fr01_CEM_LIN1.rlsmcem_lin1fr01_cem_lin1.TwliBriRawTwliBriRaw_CEM_LIN1_1
#define TwliBriRawTwliBriRaw_CEM_LIN1(c)                                      { TwliBriRawTwliBriRaw_CEM_LIN1_0= (uint8)(((uint16)(c) & 0x3F));\
                                                                                TwliBriRawTwliBriRaw_CEM_LIN1_1= (uint8)(((uint16)(c) & 0xFF) >> 6);\
                                                                              }
#define OutdBriChks_CEM_LIN1                                                  RlsmCem_Lin1Fr01_CEM_LIN1.rlsmcem_lin1fr01_cem_lin1.OutdBriChks_CEM_LIN1
#define OutdBriSts_CEM_LIN1                                                   RlsmCem_Lin1Fr01_CEM_LIN1.rlsmcem_lin1fr01_cem_lin1.OutdBriSts_CEM_LIN1
#define OutdBriCntr_CEM_LIN1                                                  RlsmCem_Lin1Fr01_CEM_LIN1.rlsmcem_lin1fr01_cem_lin1.OutdBriCntr_CEM_LIN1
#define MasterReqB0                                                           LinReqCmd.linreqcmd.MasterReqB0
#define MasterReqB1                                                           LinReqCmd.linreqcmd.MasterReqB1
#define MasterReqB2                                                           LinReqCmd.linreqcmd.MasterReqB2
#define MasterReqB3                                                           LinReqCmd.linreqcmd.MasterReqB3
#define MasterReqB4                                                           LinReqCmd.linreqcmd.MasterReqB4
#define MasterReqB5                                                           LinReqCmd.linreqcmd.MasterReqB5
#define MasterReqB6                                                           LinReqCmd.linreqcmd.MasterReqB6
#define MasterReqB7                                                           LinReqCmd.linreqcmd.MasterReqB7
#define WiprActv_CEM_LIN1                                                     CemCem_Lin1Fr06_CEM_LIN1.cemcem_lin1fr06_cem_lin1.WiprActv_CEM_LIN1
#define WiprInPrkgPosnLo_CEM_LIN1                                             CemCem_Lin1Fr06_CEM_LIN1.cemcem_lin1fr06_cem_lin1.WiprInPrkgPosnLo_CEM_LIN1
#define WiprInWipgAr_CEM_LIN1                                                 CemCem_Lin1Fr06_CEM_LIN1.cemcem_lin1fr06_cem_lin1.WiprInWipgAr_CEM_LIN1
#define WshngCycActv_CEM_LIN1                                                 CemCem_Lin1Fr06_CEM_LIN1.cemcem_lin1fr06_cem_lin1.WshngCycActv_CEM_LIN1
#define EnaOfflineMonitor_CEM_LIN1                                            CemCem_Lin1Fr05_CEM_LIN1.cemcem_lin1fr05_cem_lin1.EnaOfflineMonitor_CEM_LIN1
#define RainSnsrLiThd_CEM_LIN1                                                CemCem_Lin1Fr04_CEM_LIN1.cemcem_lin1fr04_cem_lin1.RainSnsrLiThd_CEM_LIN1
#define RainSnsrSnvtyForUsrSnvty0_CEM_LIN1                                    CemCem_Lin1Fr03_CEM_LIN1.cemcem_lin1fr03_cem_lin1.RainSnsrSnvtyForUsrSnvty0_CEM_LIN1
#define RainSnsrSnvtyForUsrSnvty1_CEM_LIN1                                    CemCem_Lin1Fr03_CEM_LIN1.cemcem_lin1fr03_cem_lin1.RainSnsrSnvtyForUsrSnvty1_CEM_LIN1
#define RainSnsrSnvtyForUsrSnvty2_CEM_LIN1                                    CemCem_Lin1Fr03_CEM_LIN1.cemcem_lin1fr03_cem_lin1.RainSnsrSnvtyForUsrSnvty2_CEM_LIN1
#define RainSnsrSnvtyForUsrSnvty3_CEM_LIN1                                    CemCem_Lin1Fr03_CEM_LIN1.cemcem_lin1fr03_cem_lin1.RainSnsrSnvtyForUsrSnvty3_CEM_LIN1
#define RainSnsrSnvtyForUsrSnvty4_CEM_LIN1                                    CemCem_Lin1Fr03_CEM_LIN1.cemcem_lin1fr03_cem_lin1.RainSnsrSnvtyForUsrSnvty4_CEM_LIN1
#define RainSnsrSnvtyForUsrSnvty5_CEM_LIN1                                    CemCem_Lin1Fr03_CEM_LIN1.cemcem_lin1fr03_cem_lin1.RainSnsrSnvtyForUsrSnvty5_CEM_LIN1
#define RainSnsrSnvtyForUsrSnvty6_CEM_LIN1                                    CemCem_Lin1Fr03_CEM_LIN1.cemcem_lin1fr03_cem_lin1.RainSnsrSnvtyForUsrSnvty6_CEM_LIN1
#define VehTyp_CEM_LIN1                                                       CemCem_Lin1Fr03_CEM_LIN1.cemcem_lin1fr03_cem_lin1.VehTyp_CEM_LIN1
#define WindCorrnValAmb_CEM_LIN1                                              CemCem_Lin1Fr03_CEM_LIN1.cemcem_lin1fr03_cem_lin1.WindCorrnValAmb_CEM_LIN1
#define WindCorrnValFrnt_CEM_LIN1                                             CemCem_Lin1Fr03_CEM_LIN1.cemcem_lin1fr03_cem_lin1.WindCorrnValFrnt_CEM_LIN1
#define WindCorrnValHud_CEM_LIN1                                              CemCem_Lin1Fr03_CEM_LIN1.cemcem_lin1fr03_cem_lin1.WindCorrnValHud_CEM_LIN1
#define FrqCfg_CEM_LIN1                                                       CemCem_Lin1Fr03_CEM_LIN1.cemcem_lin1fr03_cem_lin1.FrqCfg_CEM_LIN1
#define ReAdaptReq_CEM_LIN1                                                   CemCem_Lin1Fr03_CEM_LIN1.cemcem_lin1fr03_cem_lin1.ReAdaptReq_CEM_LIN1
#define AmbTForVisy_CEM_LIN1                                                  CemCem_Lin1Fr02_CEM_LIN1.cemcem_lin1fr02_cem_lin1.AmbTForVisy_CEM_LIN1
#define VehSpdForWipg_CEM_LIN1                                                CemCem_Lin1Fr01_CEM_LIN1.cemcem_lin1fr01_cem_lin1.VehSpdForWipg_CEM_LIN1
#define WipgPwrActvnSafeWipgPwrAcsyModSafe_CEM_LIN1                           CemCem_Lin1Fr01_CEM_LIN1.cemcem_lin1fr01_cem_lin1.WipgPwrActvnSafeWipgPwrAcsyModSafe_CEM_LIN1
#define WipgPwrActvnSafeWipgPwrDrvgModSafe_CEM_LIN1                           CemCem_Lin1Fr01_CEM_LIN1.cemcem_lin1fr01_cem_lin1.WipgPwrActvnSafeWipgPwrDrvgModSafe_CEM_LIN1
#define RainSensActvn_CEM_LIN1                                                CemCem_Lin1Fr01_CEM_LIN1.cemcem_lin1fr01_cem_lin1.RainSensActvn_CEM_LIN1
#define WshrLvrPosnSafe_CEM_LIN1                                              CemCem_Lin1Fr01_CEM_LIN1.cemcem_lin1fr01_cem_lin1.WshrLvrPosnSafe_CEM_LIN1
#define WiprMotFrntLvrCmdSafeLvrInHiSpdPosnSafe_CEM_LIN1                      CemCem_Lin1Fr01_CEM_LIN1.cemcem_lin1fr01_cem_lin1.WiprMotFrntLvrCmdSafeLvrInHiSpdPosnSafe_CEM_LIN1
#define WiprMotFrntLvrCmdSafeLvrInLoSpdPosnSafe_CEM_LIN1                      CemCem_Lin1Fr01_CEM_LIN1.cemcem_lin1fr01_cem_lin1.WiprMotFrntLvrCmdSafeLvrInLoSpdPosnSafe_CEM_LIN1
#define WiprMotFrntLvrCmdSafeLvrInSnglStrokePos_CEM_LIN1                      CemCem_Lin1Fr01_CEM_LIN1.cemcem_lin1fr01_cem_lin1.WiprMotFrntLvrCmdSafeLvrInSnglStrokePos_CEM_LIN1
#define WiprMotFrntLvrCmdSafeLvrInIntlPosn_CEM_LIN1                           CemCem_Lin1Fr01_CEM_LIN1.cemcem_lin1fr01_cem_lin1.WiprMotFrntLvrCmdSafeLvrInIntlPosn_CEM_LIN1
#define HomeLinkEna_CEM_LIN1                                                  CemCem_Lin1Fr01_CEM_LIN1.cemcem_lin1fr01_cem_lin1.HomeLinkEna_CEM_LIN1
#define WiprMotIntlCmd_CEM_LIN1                                               CemCem_Lin1Fr01_CEM_LIN1.cemcem_lin1fr01_cem_lin1.WiprMotIntlCmd_CEM_LIN1
#define WiprPosnForSrvReq_CEM_LIN1                                            CemCem_Lin1Fr01_CEM_LIN1.cemcem_lin1fr01_cem_lin1.WiprPosnForSrvReq_CEM_LIN1
#define IntrMirrCmdIntrMirrDimSnvty_CEM_LIN1                                  CemCem_Lin1Fr01_CEM_LIN1.cemcem_lin1fr01_cem_lin1.IntrMirrCmdIntrMirrDimSnvty_CEM_LIN1
#define IntrMirrCmdDrvrSide_CEM_LIN1                                          CemCem_Lin1Fr01_CEM_LIN1.cemcem_lin1fr01_cem_lin1.IntrMirrCmdDrvrSide_CEM_LIN1
#define IntrMirrCmdIntrMirrWindHeatrCmpMag_CEM_LIN1                           CemCem_Lin1Fr01_CEM_LIN1.cemcem_lin1fr01_cem_lin1.IntrMirrCmdIntrMirrWindHeatrCmpMag_CEM_LIN1
#define IntrMirrCmdIntrMirrEna_CEM_LIN1                                       CemCem_Lin1Fr01_CEM_LIN1.cemcem_lin1fr01_cem_lin1.IntrMirrCmdIntrMirrEna_CEM_LIN1
#define IntrMirrCmdIntrMirrInhbDim_CEM_LIN1                                   CemCem_Lin1Fr01_CEM_LIN1.cemcem_lin1fr01_cem_lin1.IntrMirrCmdIntrMirrInhbDim_CEM_LIN1
#define IntrMirrCmdIntrMirrDiagcRst_CEM_LIN1                                  CemCem_Lin1Fr01_CEM_LIN1.cemcem_lin1fr01_cem_lin1.IntrMirrCmdIntrMirrDiagcRst_CEM_LIN1
#define IntrMirrCmdIntrMirrAsyFanCmpMag_CEM_LIN1                              CemCem_Lin1Fr01_CEM_LIN1.cemcem_lin1fr01_cem_lin1.IntrMirrCmdIntrMirrAsyFanCmpMag_CEM_LIN1
#define WiprMotFrntOffsAg_CEM_LIN1                                            CemCem_Lin1Fr01_CEM_LIN1.cemcem_lin1fr01_cem_lin1.WiprMotFrntOffsAg_CEM_LIN1
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
#define l_u8_rd_RLSMSerNoNr1_CEM_LIN1()                                     RLSMSerNoNr1_CEM_LIN1
#define l_u8_wr_RLSMSerNoNr1_CEM_LIN1(a)                                    {RLSMSerNoNr1_CEM_LIN1 = a;}
#define l_u8_rd_RLSMSerNoNr2_CEM_LIN1()                                     RLSMSerNoNr2_CEM_LIN1
#define l_u8_wr_RLSMSerNoNr2_CEM_LIN1(a)                                    {RLSMSerNoNr2_CEM_LIN1 = a;}
#define l_u8_rd_RLSMSerNoNr3_CEM_LIN1()                                     RLSMSerNoNr3_CEM_LIN1
#define l_u8_wr_RLSMSerNoNr3_CEM_LIN1(a)                                    {RLSMSerNoNr3_CEM_LIN1 = a;}
#define l_u8_rd_RLSMSerNoNr4_CEM_LIN1()                                     RLSMSerNoNr4_CEM_LIN1
#define l_u8_wr_RLSMSerNoNr4_CEM_LIN1(a)                                    {RLSMSerNoNr4_CEM_LIN1 = a;}
#define l_u8_rd_RLSMPartNo10Nr1_CEM_LIN1()                                  RLSMPartNo10Nr1_CEM_LIN1
#define l_u8_wr_RLSMPartNo10Nr1_CEM_LIN1(a)                                 {RLSMPartNo10Nr1_CEM_LIN1 = a;}
#define l_u8_rd_RLSMPartNo10Nr2_CEM_LIN1()                                  RLSMPartNo10Nr2_CEM_LIN1
#define l_u8_wr_RLSMPartNo10Nr2_CEM_LIN1(a)                                 {RLSMPartNo10Nr2_CEM_LIN1 = a;}
#define l_u8_rd_RLSMPartNo10Nr3_CEM_LIN1()                                  RLSMPartNo10Nr3_CEM_LIN1
#define l_u8_wr_RLSMPartNo10Nr3_CEM_LIN1(a)                                 {RLSMPartNo10Nr3_CEM_LIN1 = a;}
#define l_u8_rd_RLSMPartNo10Nr4_CEM_LIN1()                                  RLSMPartNo10Nr4_CEM_LIN1
#define l_u8_wr_RLSMPartNo10Nr4_CEM_LIN1(a)                                 {RLSMPartNo10Nr4_CEM_LIN1 = a;}
#define l_u8_rd_RLSMPartNo10Nr5_CEM_LIN1()                                  RLSMPartNo10Nr5_CEM_LIN1
#define l_u8_wr_RLSMPartNo10Nr5_CEM_LIN1(a)                                 {RLSMPartNo10Nr5_CEM_LIN1 = a;}
#define l_u8_rd_RLSMPartNo10EndSgn1_CEM_LIN1()                              RLSMPartNo10EndSgn1_CEM_LIN1
#define l_u8_wr_RLSMPartNo10EndSgn1_CEM_LIN1(a)                             {RLSMPartNo10EndSgn1_CEM_LIN1 = a;}
#define l_u8_rd_RLSMPartNo10EndSgn2_CEM_LIN1()                              RLSMPartNo10EndSgn2_CEM_LIN1
#define l_u8_wr_RLSMPartNo10EndSgn2_CEM_LIN1(a)                             {RLSMPartNo10EndSgn2_CEM_LIN1 = a;}
#define l_u8_rd_RLSMPartNo10EndSgn3_CEM_LIN1()                              RLSMPartNo10EndSgn3_CEM_LIN1
#define l_u8_wr_RLSMPartNo10EndSgn3_CEM_LIN1(a)                             {RLSMPartNo10EndSgn3_CEM_LIN1 = a;}
#define l_u8_rd_RLSMPartNoNr1_CEM_LIN1()                                    RLSMPartNoNr1_CEM_LIN1
#define l_u8_wr_RLSMPartNoNr1_CEM_LIN1(a)                                   {RLSMPartNoNr1_CEM_LIN1 = a;}
#define l_u8_rd_RLSMPartNoNr2_CEM_LIN1()                                    RLSMPartNoNr2_CEM_LIN1
#define l_u8_wr_RLSMPartNoNr2_CEM_LIN1(a)                                   {RLSMPartNoNr2_CEM_LIN1 = a;}
#define l_u8_rd_RLSMPartNoNr3_CEM_LIN1()                                    RLSMPartNoNr3_CEM_LIN1
#define l_u8_wr_RLSMPartNoNr3_CEM_LIN1(a)                                   {RLSMPartNoNr3_CEM_LIN1 = a;}
#define l_u8_rd_RLSMPartNoNr4_CEM_LIN1()                                    RLSMPartNoNr4_CEM_LIN1
#define l_u8_wr_RLSMPartNoNr4_CEM_LIN1(a)                                   {RLSMPartNoNr4_CEM_LIN1 = a;}
#define l_u8_rd_RLSMPartNoEndSgn1_CEM_LIN1()                                RLSMPartNoEndSgn1_CEM_LIN1
#define l_u8_wr_RLSMPartNoEndSgn1_CEM_LIN1(a)                               {RLSMPartNoEndSgn1_CEM_LIN1 = a;}
#define l_u8_rd_RLSMPartNoEndSgn2_CEM_LIN1()                                RLSMPartNoEndSgn2_CEM_LIN1
#define l_u8_wr_RLSMPartNoEndSgn2_CEM_LIN1(a)                               {RLSMPartNoEndSgn2_CEM_LIN1 = a;}
#define l_u8_rd_RLSMPartNoEndSgn3_CEM_LIN1()                                RLSMPartNoEndSgn3_CEM_LIN1
#define l_u8_wr_RLSMPartNoEndSgn3_CEM_LIN1(a)                               {RLSMPartNoEndSgn3_CEM_LIN1 = a;}
#define l_bool_rd_SolarSnsrErr_CEM_LIN1()                                       SolarSnsrErr_CEM_LIN1
#define l_bool_wr_SolarSnsrErr_CEM_LIN1(a)                                      {SolarSnsrErr_CEM_LIN1 = a;}
#define l_bool_rd_RainSnsrDiagcRainSnsrHiVoltDetd_CEM_LIN1()                    RainSnsrDiagcRainSnsrHiVoltDetd_CEM_LIN1
#define l_bool_wr_RainSnsrDiagcRainSnsrHiVoltDetd_CEM_LIN1(a)                   {RainSnsrDiagcRainSnsrHiVoltDetd_CEM_LIN1 = a;}
#define l_bool_rd_RainSnsrDiagcRainSnsrHiTDetd_CEM_LIN1()                       RainSnsrDiagcRainSnsrHiTDetd_CEM_LIN1
#define l_bool_wr_RainSnsrDiagcRainSnsrHiTDetd_CEM_LIN1(a)                      {RainSnsrDiagcRainSnsrHiTDetd_CEM_LIN1 = a;}
#define l_u8_rd_LiOprnMod_CEM_LIN1()                                        LiOprnMod_CEM_LIN1
#define l_u8_wr_LiOprnMod_CEM_LIN1(a)                                       {LiOprnMod_CEM_LIN1 = a;}
#define l_bool_rd_RainDetected_CEM_LIN1()                                       RainDetected_CEM_LIN1
#define l_bool_wr_RainDetected_CEM_LIN1(a)                                      {RainDetected_CEM_LIN1 = a;}
#define l_u8_rd_RainfallAmnt_CEM_LIN1()                                     RainfallAmnt_CEM_LIN1
#define l_u8_wr_RainfallAmnt_CEM_LIN1(a)                                    {RainfallAmnt_CEM_LIN1 = a;}
#define l_u8_rd_SolarSnsrLeValue_CEM_LIN1()                                 SolarSnsrLeValue_CEM_LIN1
#define l_u8_wr_SolarSnsrLeValue_CEM_LIN1(a)                                {SolarSnsrLeValue_CEM_LIN1 = a;}
#define l_u8_rd_SolarSnsrRiValue_CEM_LIN1()                                 SolarSnsrRiValue_CEM_LIN1
#define l_u8_wr_SolarSnsrRiValue_CEM_LIN1(a)                                {SolarSnsrRiValue_CEM_LIN1 = a;}
#define l_u16_rd_CmptFrntWindDewT_CEM_LIN1()                                  (canuint16)(CmptFrntWindDewT_CEM_LIN1_0)\
                                                                                | ((canuint16)(CmptFrntWindDewT_CEM_LIN1_1)<<8)
#define l_u16_wr_CmptFrntWindDewT_CEM_LIN1(a)                                 {CmptFrntWindDewT_CEM_LIN1_0 = (a & 0xff);\
                                                                                 CmptFrntWindDewT_CEM_LIN1_1 = ((a >> 8) & 0x07);}
#define l_u8_rd_AmbIllmnFwdStsCntr_CEM_LIN1()                               AmbIllmnFwdStsCntr_CEM_LIN1
#define l_u8_wr_AmbIllmnFwdStsCntr_CEM_LIN1(a)                              {AmbIllmnFwdStsCntr_CEM_LIN1 = a;}
#define l_u8_rd_AmbIllmnFwdStsAmblillmn2_CEM_LIN1()                         AmbIllmnFwdStsAmblillmn2_CEM_LIN1
#define l_u8_wr_AmbIllmnFwdStsAmblillmn2_CEM_LIN1(a)                        {AmbIllmnFwdStsAmblillmn2_CEM_LIN1 = a;}
#define l_u8_rd_AmbIllmnFwdStsChks_CEM_LIN1()                               AmbIllmnFwdStsChks_CEM_LIN1
#define l_u8_wr_AmbIllmnFwdStsChks_CEM_LIN1(a)                              {AmbIllmnFwdStsChks_CEM_LIN1 = a;}
#define l_u16_rd_AmbIllmnFwdStsAmblillmn1_CEM_LIN1()                          (canuint16)(AmbIllmnFwdStsAmblillmn1_CEM_LIN1_0)\
                                                                                | ((canuint16)(AmbIllmnFwdStsAmblillmn1_CEM_LIN1_1)<<8)
#define l_u16_wr_AmbIllmnFwdStsAmblillmn1_CEM_LIN1(a)                         {AmbIllmnFwdStsAmblillmn1_CEM_LIN1_0 = (a & 0xff);\
                                                                                 AmbIllmnFwdStsAmblillmn1_CEM_LIN1_1 = ((a >> 8) & 0x1);}
#define l_bool_rd_RelHumSnsrErr_CEM_LIN1()                                      RelHumSnsrErr_CEM_LIN1
#define l_bool_wr_RelHumSnsrErr_CEM_LIN1(a)                                     {RelHumSnsrErr_CEM_LIN1 = a;}
#define l_u16_rd_CmptFrntWindT_CEM_LIN1()                                     (canuint16)(CmptFrntWindT_CEM_LIN1_0)\
                                                                                | ((canuint16)(CmptFrntWindT_CEM_LIN1_1)<<3)
#define l_u16_wr_CmptFrntWindT_CEM_LIN1(a)                                    {CmptFrntWindT_CEM_LIN1_0 = (a & 0x07);\
                                                                                 CmptFrntWindT_CEM_LIN1_1 = ((a >> 3) & 0xff);}
#define l_u8_rd_RelHumSnsrRelHum_CEM_LIN1()                                 RelHumSnsrRelHum_CEM_LIN1
#define l_u8_wr_RelHumSnsrRelHum_CEM_LIN1(a)                                {RelHumSnsrRelHum_CEM_LIN1 = a;}
#define l_u8_rd_AutWinWipgCmd_CEM_LIN1()                                    AutWinWipgCmd_CEM_LIN1
#define l_u8_wr_AutWinWipgCmd_CEM_LIN1(a)                                   {AutWinWipgCmd_CEM_LIN1 = a;}
#define l_bool_rd_HudSnsrErrParChk_CEM_LIN1()                                   HudSnsrErrParChk_CEM_LIN1
#define l_bool_wr_HudSnsrErrParChk_CEM_LIN1(a)                                  {HudSnsrErrParChk_CEM_LIN1 = a;}
#define l_bool_rd_HudSnsrErrSnsrErr_CEM_LIN1()                                  HudSnsrErrSnsrErr_CEM_LIN1
#define l_bool_wr_HudSnsrErrSnsrErr_CEM_LIN1(a)                                 {HudSnsrErrSnsrErr_CEM_LIN1 = a;}
#define l_bool_rd_RainLi_CEM_LIN1()                                             RainLi_CEM_LIN1
#define l_bool_wr_RainLi_CEM_LIN1(a)                                            {RainLi_CEM_LIN1 = a;}
#define l_bool_rd_RainSnsrErrCalErrActv_CEM_LIN1()                              RainSnsrErrCalErrActv_CEM_LIN1
#define l_bool_wr_RainSnsrErrCalErrActv_CEM_LIN1(a)                             {RainSnsrErrCalErrActv_CEM_LIN1 = a;}
#define l_bool_rd_RainSnsrErrCalErr_CEM_LIN1()                                  RainSnsrErrCalErr_CEM_LIN1
#define l_bool_wr_RainSnsrErrCalErr_CEM_LIN1(a)                                 {RainSnsrErrCalErr_CEM_LIN1 = a;}
#define l_bool_rd_RainSnsrErrRainDetnErr_CEM_LIN1()                             RainSnsrErrRainDetnErr_CEM_LIN1
#define l_bool_wr_RainSnsrErrRainDetnErr_CEM_LIN1(a)                            {RainSnsrErrRainDetnErr_CEM_LIN1 = a;}
#define l_bool_rd_RainSnsrErrRainDetnErrActv_CEM_LIN1()                         RainSnsrErrRainDetnErrActv_CEM_LIN1
#define l_bool_wr_RainSnsrErrRainDetnErrActv_CEM_LIN1(a)                        {RainSnsrErrRainDetnErrActv_CEM_LIN1 = a;}
#define l_u8_rd_WipgAutFrntMod_CEM_LIN1()                                   WipgAutFrntMod_CEM_LIN1
#define l_u8_wr_WipgAutFrntMod_CEM_LIN1(a)                                  {WipgAutFrntMod_CEM_LIN1 = a;}
#define l_bool_rd_ErrRespRLSM_CEM_LIN1()                                        ErrRespRLSM_CEM_LIN1
#define l_bool_wr_ErrRespRLSM_CEM_LIN1(a)                                       {ErrRespRLSM_CEM_LIN1 = a;}
#define l_u8_rd_TwliBriRawQf_CEM_LIN1()                                     TwliBriRawQf_CEM_LIN1
#define l_u8_wr_TwliBriRawQf_CEM_LIN1(a)                                    {TwliBriRawQf_CEM_LIN1 = a;}
#define l_u16_rd_TwliBriRawTwliBriRaw_CEM_LIN1()                              (canuint16)(TwliBriRawTwliBriRaw_CEM_LIN1_0)\
                                                                                | ((canuint16)(TwliBriRawTwliBriRaw_CEM_LIN1_1)<<6)
#define l_u16_wr_TwliBriRawTwliBriRaw_CEM_LIN1(a)                             {TwliBriRawTwliBriRaw_CEM_LIN1_0 = (a & 0x3F);\
                                                                                 TwliBriRawTwliBriRaw_CEM_LIN1_1 = ((a >> 6) & 0xFF);}
#define l_u8_rd_OutdBriChks_CEM_LIN1()                                      OutdBriChks_CEM_LIN1
#define l_u8_wr_OutdBriChks_CEM_LIN1(a)                                     {OutdBriChks_CEM_LIN1 = a;}
#define l_u8_rd_OutdBriSts_CEM_LIN1()                                       OutdBriSts_CEM_LIN1
#define l_u8_wr_OutdBriSts_CEM_LIN1(a)                                      {OutdBriSts_CEM_LIN1 = a;}
#define l_u8_rd_OutdBriCntr_CEM_LIN1()                                      OutdBriCntr_CEM_LIN1
#define l_u8_wr_OutdBriCntr_CEM_LIN1(a)                                     {OutdBriCntr_CEM_LIN1 = a;}
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
#define l_bool_rd_WiprActv_CEM_LIN1()                                           WiprActv_CEM_LIN1
#define l_bool_wr_WiprActv_CEM_LIN1(a)                                          {WiprActv_CEM_LIN1 = a;}
#define l_bool_rd_WiprInPrkgPosnLo_CEM_LIN1()                                   WiprInPrkgPosnLo_CEM_LIN1
#define l_bool_wr_WiprInPrkgPosnLo_CEM_LIN1(a)                                  {WiprInPrkgPosnLo_CEM_LIN1 = a;}
#define l_bool_rd_WiprInWipgAr_CEM_LIN1()                                       WiprInWipgAr_CEM_LIN1
#define l_bool_wr_WiprInWipgAr_CEM_LIN1(a)                                      {WiprInWipgAr_CEM_LIN1 = a;}
#define l_bool_rd_WshngCycActv_CEM_LIN1()                                       WshngCycActv_CEM_LIN1
#define l_bool_wr_WshngCycActv_CEM_LIN1(a)                                      {WshngCycActv_CEM_LIN1 = a;}
#define l_bool_rd_EnaOfflineMonitor_CEM_LIN1()                                  EnaOfflineMonitor_CEM_LIN1
#define l_bool_wr_EnaOfflineMonitor_CEM_LIN1(a)                                 {EnaOfflineMonitor_CEM_LIN1 = a;}
#define l_u8_rd_RainSnsrLiThd_CEM_LIN1()                                    RainSnsrLiThd_CEM_LIN1
#define l_u8_wr_RainSnsrLiThd_CEM_LIN1(a)                                   {RainSnsrLiThd_CEM_LIN1 = a;}
#define l_u8_rd_RainSnsrSnvtyForUsrSnvty0_CEM_LIN1()                        RainSnsrSnvtyForUsrSnvty0_CEM_LIN1
#define l_u8_wr_RainSnsrSnvtyForUsrSnvty0_CEM_LIN1(a)                       {RainSnsrSnvtyForUsrSnvty0_CEM_LIN1 = a;}
#define l_u8_rd_RainSnsrSnvtyForUsrSnvty1_CEM_LIN1()                        RainSnsrSnvtyForUsrSnvty1_CEM_LIN1
#define l_u8_wr_RainSnsrSnvtyForUsrSnvty1_CEM_LIN1(a)                       {RainSnsrSnvtyForUsrSnvty1_CEM_LIN1 = a;}
#define l_u8_rd_RainSnsrSnvtyForUsrSnvty2_CEM_LIN1()                        RainSnsrSnvtyForUsrSnvty2_CEM_LIN1
#define l_u8_wr_RainSnsrSnvtyForUsrSnvty2_CEM_LIN1(a)                       {RainSnsrSnvtyForUsrSnvty2_CEM_LIN1 = a;}
#define l_u8_rd_RainSnsrSnvtyForUsrSnvty3_CEM_LIN1()                        RainSnsrSnvtyForUsrSnvty3_CEM_LIN1
#define l_u8_wr_RainSnsrSnvtyForUsrSnvty3_CEM_LIN1(a)                       {RainSnsrSnvtyForUsrSnvty3_CEM_LIN1 = a;}
#define l_u8_rd_RainSnsrSnvtyForUsrSnvty4_CEM_LIN1()                        RainSnsrSnvtyForUsrSnvty4_CEM_LIN1
#define l_u8_wr_RainSnsrSnvtyForUsrSnvty4_CEM_LIN1(a)                       {RainSnsrSnvtyForUsrSnvty4_CEM_LIN1 = a;}
#define l_u8_rd_RainSnsrSnvtyForUsrSnvty5_CEM_LIN1()                        RainSnsrSnvtyForUsrSnvty5_CEM_LIN1
#define l_u8_wr_RainSnsrSnvtyForUsrSnvty5_CEM_LIN1(a)                       {RainSnsrSnvtyForUsrSnvty5_CEM_LIN1 = a;}
#define l_u8_rd_RainSnsrSnvtyForUsrSnvty6_CEM_LIN1()                        RainSnsrSnvtyForUsrSnvty6_CEM_LIN1
#define l_u8_wr_RainSnsrSnvtyForUsrSnvty6_CEM_LIN1(a)                       {RainSnsrSnvtyForUsrSnvty6_CEM_LIN1 = a;}
#define l_u8_rd_VehTyp_CEM_LIN1()                                           VehTyp_CEM_LIN1
#define l_u8_wr_VehTyp_CEM_LIN1(a)                                          {VehTyp_CEM_LIN1 = a;}
#define l_u8_rd_WindCorrnValAmb_CEM_LIN1()                                  WindCorrnValAmb_CEM_LIN1
#define l_u8_wr_WindCorrnValAmb_CEM_LIN1(a)                                 {WindCorrnValAmb_CEM_LIN1 = a;}
#define l_u8_rd_WindCorrnValFrnt_CEM_LIN1()                                 WindCorrnValFrnt_CEM_LIN1
#define l_u8_wr_WindCorrnValFrnt_CEM_LIN1(a)                                {WindCorrnValFrnt_CEM_LIN1 = a;}
#define l_u8_rd_WindCorrnValHud_CEM_LIN1()                                  WindCorrnValHud_CEM_LIN1
#define l_u8_wr_WindCorrnValHud_CEM_LIN1(a)                                 {WindCorrnValHud_CEM_LIN1 = a;}
#define l_u8_rd_FrqCfg_CEM_LIN1()                                           FrqCfg_CEM_LIN1
#define l_u8_wr_FrqCfg_CEM_LIN1(a)                                          {FrqCfg_CEM_LIN1 = a;}
#define l_bool_rd_ReAdaptReq_CEM_LIN1()                                         ReAdaptReq_CEM_LIN1
#define l_bool_wr_ReAdaptReq_CEM_LIN1(a)                                        {ReAdaptReq_CEM_LIN1 = a;}
#define l_u8_rd_AmbTForVisy_CEM_LIN1()                                      AmbTForVisy_CEM_LIN1
#define l_u8_wr_AmbTForVisy_CEM_LIN1(a)                                     {AmbTForVisy_CEM_LIN1 = a;}
#define l_u8_rd_VehSpdForWipg_CEM_LIN1()                                    VehSpdForWipg_CEM_LIN1
#define l_u8_wr_VehSpdForWipg_CEM_LIN1(a)                                   {VehSpdForWipg_CEM_LIN1 = a;}
#define l_u8_rd_WipgPwrActvnSafeWipgPwrAcsyModSafe_CEM_LIN1()               WipgPwrActvnSafeWipgPwrAcsyModSafe_CEM_LIN1
#define l_u8_wr_WipgPwrActvnSafeWipgPwrAcsyModSafe_CEM_LIN1(a)              {WipgPwrActvnSafeWipgPwrAcsyModSafe_CEM_LIN1 = a;}
#define l_u8_rd_WipgPwrActvnSafeWipgPwrDrvgModSafe_CEM_LIN1()               WipgPwrActvnSafeWipgPwrDrvgModSafe_CEM_LIN1
#define l_u8_wr_WipgPwrActvnSafeWipgPwrDrvgModSafe_CEM_LIN1(a)              {WipgPwrActvnSafeWipgPwrDrvgModSafe_CEM_LIN1 = a;}
#define l_bool_rd_RainSensActvn_CEM_LIN1()                                      RainSensActvn_CEM_LIN1
#define l_bool_wr_RainSensActvn_CEM_LIN1(a)                                     {RainSensActvn_CEM_LIN1 = a;}
#define l_u8_rd_WshrLvrPosnSafe_CEM_LIN1()                                  WshrLvrPosnSafe_CEM_LIN1
#define l_u8_wr_WshrLvrPosnSafe_CEM_LIN1(a)                                 {WshrLvrPosnSafe_CEM_LIN1 = a;}
#define l_u8_rd_WiprMotFrntLvrCmdSafeLvrInHiSpdPosnSafe_CEM_LIN1()          WiprMotFrntLvrCmdSafeLvrInHiSpdPosnSafe_CEM_LIN1
#define l_u8_wr_WiprMotFrntLvrCmdSafeLvrInHiSpdPosnSafe_CEM_LIN1(a)         {WiprMotFrntLvrCmdSafeLvrInHiSpdPosnSafe_CEM_LIN1 = a;}
#define l_u8_rd_WiprMotFrntLvrCmdSafeLvrInLoSpdPosnSafe_CEM_LIN1()          WiprMotFrntLvrCmdSafeLvrInLoSpdPosnSafe_CEM_LIN1
#define l_u8_wr_WiprMotFrntLvrCmdSafeLvrInLoSpdPosnSafe_CEM_LIN1(a)         {WiprMotFrntLvrCmdSafeLvrInLoSpdPosnSafe_CEM_LIN1 = a;}
#define l_bool_rd_WiprMotFrntLvrCmdSafeLvrInSnglStrokePos_CEM_LIN1()            WiprMotFrntLvrCmdSafeLvrInSnglStrokePos_CEM_LIN1
#define l_bool_wr_WiprMotFrntLvrCmdSafeLvrInSnglStrokePos_CEM_LIN1(a)           {WiprMotFrntLvrCmdSafeLvrInSnglStrokePos_CEM_LIN1 = a;}
#define l_bool_rd_WiprMotFrntLvrCmdSafeLvrInIntlPosn_CEM_LIN1()                 WiprMotFrntLvrCmdSafeLvrInIntlPosn_CEM_LIN1
#define l_bool_wr_WiprMotFrntLvrCmdSafeLvrInIntlPosn_CEM_LIN1(a)                {WiprMotFrntLvrCmdSafeLvrInIntlPosn_CEM_LIN1 = a;}
#define l_u8_rd_HomeLinkEna_CEM_LIN1()                                      HomeLinkEna_CEM_LIN1
#define l_u8_wr_HomeLinkEna_CEM_LIN1(a)                                     {HomeLinkEna_CEM_LIN1 = a;}
#define l_u8_rd_WiprMotIntlCmd_CEM_LIN1()                                   WiprMotIntlCmd_CEM_LIN1
#define l_u8_wr_WiprMotIntlCmd_CEM_LIN1(a)                                  {WiprMotIntlCmd_CEM_LIN1 = a;}
#define l_bool_rd_WiprPosnForSrvReq_CEM_LIN1()                                  WiprPosnForSrvReq_CEM_LIN1
#define l_bool_wr_WiprPosnForSrvReq_CEM_LIN1(a)                                 {WiprPosnForSrvReq_CEM_LIN1 = a;}
#define l_u8_rd_IntrMirrCmdIntrMirrDimSnvty_CEM_LIN1()                      IntrMirrCmdIntrMirrDimSnvty_CEM_LIN1
#define l_u8_wr_IntrMirrCmdIntrMirrDimSnvty_CEM_LIN1(a)                     {IntrMirrCmdIntrMirrDimSnvty_CEM_LIN1 = a;}
#define l_bool_rd_IntrMirrCmdDrvrSide_CEM_LIN1()                                IntrMirrCmdDrvrSide_CEM_LIN1
#define l_bool_wr_IntrMirrCmdDrvrSide_CEM_LIN1(a)                               {IntrMirrCmdDrvrSide_CEM_LIN1 = a;}
#define l_bool_rd_IntrMirrCmdIntrMirrWindHeatrCmpMag_CEM_LIN1()                 IntrMirrCmdIntrMirrWindHeatrCmpMag_CEM_LIN1
#define l_bool_wr_IntrMirrCmdIntrMirrWindHeatrCmpMag_CEM_LIN1(a)                {IntrMirrCmdIntrMirrWindHeatrCmpMag_CEM_LIN1 = a;}
#define l_bool_rd_IntrMirrCmdIntrMirrEna_CEM_LIN1()                             IntrMirrCmdIntrMirrEna_CEM_LIN1
#define l_bool_wr_IntrMirrCmdIntrMirrEna_CEM_LIN1(a)                            {IntrMirrCmdIntrMirrEna_CEM_LIN1 = a;}
#define l_bool_rd_IntrMirrCmdIntrMirrInhbDim_CEM_LIN1()                         IntrMirrCmdIntrMirrInhbDim_CEM_LIN1
#define l_bool_wr_IntrMirrCmdIntrMirrInhbDim_CEM_LIN1(a)                        {IntrMirrCmdIntrMirrInhbDim_CEM_LIN1 = a;}
#define l_bool_rd_IntrMirrCmdIntrMirrDiagcRst_CEM_LIN1()                        IntrMirrCmdIntrMirrDiagcRst_CEM_LIN1
#define l_bool_wr_IntrMirrCmdIntrMirrDiagcRst_CEM_LIN1(a)                       {IntrMirrCmdIntrMirrDiagcRst_CEM_LIN1 = a;}
#define l_bool_rd_IntrMirrCmdIntrMirrAsyFanCmpMag_CEM_LIN1()                    IntrMirrCmdIntrMirrAsyFanCmpMag_CEM_LIN1
#define l_bool_wr_IntrMirrCmdIntrMirrAsyFanCmpMag_CEM_LIN1(a)                   {IntrMirrCmdIntrMirrAsyFanCmpMag_CEM_LIN1 = a;}
#define l_u8_rd_WiprMotFrntOffsAg_CEM_LIN1()                                WiprMotFrntOffsAg_CEM_LIN1
#define l_u8_wr_WiprMotFrntOffsAg_CEM_LIN1(a)                               {WiprMotFrntOffsAg_CEM_LIN1 = a;}


#endif  /* I_LIN_RLS_H */
