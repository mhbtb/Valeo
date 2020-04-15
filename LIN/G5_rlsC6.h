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
#define cb_HANDLE_SoSes_01                1  /* cb_HANDLE_LsRLS_2 */
#define cb_HANDLE_RLSs_01_g               2  /* cb_HANDLE_RLSs_01*/
#define cb_HANDLE_LinReqCmd_g             3 /* cb_HANDLE_LinReqCmd*/
#define cb_HANDLE_WWSs_01_g               4  /* cb_HANDLE_WWSs_01 */
#define cb_HANDLE_BCM1_LIN1_01_g          5 /* cb_HANDLE_BCM1s_01 */

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
  canbittype                            Helligkeit_IR: 8;
  canbittype                          Helligkeit_FW_0: 8;
  canbittype                          Helligkeit_FW_1: 2;
  canbittype                                  unused0: 6;
} _c_LsRLS_2_msgType;

typedef struct {
  canbittype                              RLS_Zaehler: 4;
  canbittype                   Wischergeschwindigkeit: 3;
  canbittype                                  unused0: 1;
  canbittype                                Licht_ein: 1;
  canbittype                         Licht_ein_invers: 1;
  canbittype                               RS_Schwall: 1;
  canbittype                           RS_Direktmodus: 1;
  canbittype                    Verglasung_schliessen: 1;
  canbittype                              Dunkel_Hell: 1;
  canbittype                                  unused1: 2;
  canbittype                                   RS_Err: 1;
  canbittype                                   LS_Err: 1;
  canbittype                            RLS_Err_Aktiv: 1;
  canbittype                        RLS_Kommunikation: 1;
  canbittype                        RLS_Unterspannung: 1;
  canbittype                        RLS_Ueberspannung: 1;
  canbittype                      RLS_Adaptierung_Err: 1;
  canbittype                    Adaptierung_Err_Aktiv: 1;
  canbittype                               Helligkeit: 3;
  canbittype                               Regenmenge: 3;
  canbittype                                  unused2: 2;
} _c_RLSs_01_msgType;


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
  canbittype                         Frontwischer_ein: 1;
  canbittype                         Frontwaschen_ein: 1;
  canbittype                         Wendelagensignal: 1;
  canbittype                          Parklagensignal: 1;
  canbittype                          Wischer_Service: 1;
  canbittype                                  unused0: 3;
  canbittype                    Wischzyklus_Zaehler_0: 8;
  canbittype                    Wischzyklus_Zaehler_1: 8;
  canbittype                             Wischer1_Err: 1;
  canbittype                   Wischer1_Kommunikation: 1;
  canbittype                   Wischer1_Unterspannung: 1;
  canbittype                   Wischer1_Ueberspannung: 1;
  canbittype                     Wischer1_Ueberlastet: 1;
  canbittype                     Ueberlast1_Err_Aktiv: 1;
  canbittype                                  unused1: 2;
  canbittype                             Wischer2_Err: 1;
  canbittype                   Wischer2_Kommunikation: 1;
  canbittype                   Wischer2_Unterspannung: 1;
  canbittype                   Wischer2_Ueberspannung: 1;
  canbittype                     Wischer2_Ueberlastet: 1;
  canbittype                     Ueberlast2_Err_Aktiv: 1;
  canbittype                                  unused2: 2;
} _c_WWSs_01_msgType;

typedef struct {
  canbittype                           Master_Zaehler: 4;
  canbittype                             LSS_Int_Time: 4;
  canbittype                         LSS_Tipp_Wischen: 1;
  canbittype                            LSS_Intervall: 1;
  canbittype                       LSS_WischerStufe_1: 1;
  canbittype                       LSS_WischerStufe_2: 1;
  canbittype                         LSS_Frontwaschen: 1;
  canbittype                          Servicestellung: 1;
  canbittype                      Frontklappenkontakt: 1;
  canbittype                           Winterstellung: 1;
  canbittype                           Klemme_15_LIN1: 1;
  canbittype                                Klemme_50: 1;
  canbittype                           Wendelage_oben: 1;
  canbittype                          Wendelage_unten: 1;
  canbittype                         Verglasung_offen: 1;
  canbittype                                  unused0: 3;
  canbittype                             FzgGeschw_VW: 8;
  canbittype                           Aussentemp_gef: 8;
} _c_BCM1s_01_msgType;


/******************************************************************************/
/*                               Message Unions                               */
/******************************************************************************/


/* Send messages */

typedef union {
    unsigned char _c[8];
    _c_LinRespCmd_msgType linrespcmd;
} _c_LinRespCmd_buf;

typedef union {
    unsigned char _c[3];
    _c_LsRLS_2_msgType lsrls_2;
} _c_LsRLS_2_buf;

typedef union {
    unsigned char _c[4];
    _c_RLSs_01_msgType rlss_01;
} _c_RLSs_01_buf;


/* Receive messages */

typedef union {
    unsigned char _c[8];
    _c_LinReqCmd_msgType linreqcmd;
} _c_LinReqCmd_buf;

typedef union {
    unsigned char _c[5];
    _c_WWSs_01_msgType wwss_01;
} _c_WWSs_01_buf;

typedef union {
    unsigned char _c[5];
    _c_BCM1s_01_msgType bcm1s_01;
} _c_BCM1s_01_buf;


/******************************************************************************/
/*                          Databuffer for send objects                       */
/******************************************************************************/

extern MEMORY_FAR _c_LinRespCmd_buf LinRespCmd;
extern MEMORY_FAR _c_LsRLS_2_buf LsRLS_2;
extern MEMORY_FAR _c_RLSs_01_buf RLSs_01;

/******************************************************************************/
/*                        Databuffer for confirmationflags                    */
/******************************************************************************/

#define LinRespCmd_conf_b             uLinConfirmationFlags.w[0].b0
#define l_flg_tst_LinRespCmd()       (LinRespCmd_conf_b != 0)
#define l_flg_clr_LinRespCmd()       {LinRespCmd_conf_b = 0;}
#define LsRLS_2_conf_b             uLinConfirmationFlags.w[0].b1
#define l_flg_tst_LsRLS_2()       (LsRLS_2_conf_b != 0)
#define l_flg_clr_LsRLS_2()       {LsRLS_2_conf_b = 0;}
#define RLSs_01_conf_b             uLinConfirmationFlags.w[0].b2
#define l_flg_tst_RLSs_01()       (RLSs_01_conf_b != 0)
#define l_flg_clr_RLSs_01()       {RLSs_01_conf_b = 0;}

/******************************************************************************/
/*                         Databuffer for receive objects                     */
/******************************************************************************/

extern MEMORY_FAR _c_LinReqCmd_buf LinReqCmd;
extern MEMORY_FAR _c_WWSs_01_buf WWSs_01;
extern MEMORY_FAR _c_BCM1s_01_buf BCM1s_01;

/******************************************************************************/
/*                          Databuffer for indicationflags                    */
/******************************************************************************/

#define LinReqCmd_ind_b             uLinIndicationFlags.w[0].b0
#define l_flg_tst_LinReqCmd()       (LinReqCmd_ind_b != 0)
#define l_flg_clr_LinReqCmd()       {LinReqCmd_ind_b = 0;}
#define WWSs_01_ind_b             uLinIndicationFlags.w[0].b1
#define l_flg_tst_WWSs_01()       (WWSs_01_ind_b != 0)
#define l_flg_clr_WWSs_01()       {WWSs_01_ind_b = 0;}
#define BCM1s_01_ind_b             uLinIndicationFlags.w[0].b2
#define l_flg_tst_BCM1s_01()       (BCM1s_01_ind_b != 0)
#define l_flg_clr_BCM1s_01()       {BCM1s_01_ind_b = 0;}

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
#define Helligkeit_IR                                                         LsRLS_2.lsrls_2.Helligkeit_IR
#define Helligkeit_FW_0                                                       LsRLS_2.lsrls_2.Helligkeit_FW_0
#define Helligkeit_FW_1                                                       LsRLS_2.lsrls_2.Helligkeit_FW_1
#define Helligkeit_FW(c)                                                      { Helligkeit_FW_0= (uint8)(((uint16)(c) & 0xFF));\
                                                                                Helligkeit_FW_1= (uint8)(((uint16)(c) & 0x03) >> 8);\
                                                                              }
#define RLS_Zaehler                                                           RLSs_01.rlss_01.RLS_Zaehler
#define Wischergeschwindigkeit                                                RLSs_01.rlss_01.Wischergeschwindigkeit
#define Licht_ein                                                             RLSs_01.rlss_01.Licht_ein
#define Licht_ein_invers                                                      RLSs_01.rlss_01.Licht_ein_invers
#define RS_Schwall                                                            RLSs_01.rlss_01.RS_Schwall
#define RS_Direktmodus                                                        RLSs_01.rlss_01.RS_Direktmodus
#define Verglasung_schliessen                                                 RLSs_01.rlss_01.Verglasung_schliessen
#define Dunkel_Hell                                                           RLSs_01.rlss_01.Dunkel_Hell
#define RS_Err                                                                RLSs_01.rlss_01.RS_Err
#define LS_Err                                                                RLSs_01.rlss_01.LS_Err
#define RLS_Err_Aktiv                                                         RLSs_01.rlss_01.RLS_Err_Aktiv
#define RLS_Kommunikation                                                     RLSs_01.rlss_01.RLS_Kommunikation
#define RLS_Unterspannung                                                     RLSs_01.rlss_01.RLS_Unterspannung
#define RLS_Ueberspannung                                                     RLSs_01.rlss_01.RLS_Ueberspannung
#define RLS_Adaptierung_Err                                                   RLSs_01.rlss_01.RLS_Adaptierung_Err
#define Adaptierung_Err_Aktiv                                                 RLSs_01.rlss_01.Adaptierung_Err_Aktiv
#define Helligkeit4                                                           RLSs_01.rlss_01.Helligkeit
#define Regenmenge                                                            RLSs_01.rlss_01.Regenmenge
#define MasterReqB0                                                           LinReqCmd.linreqcmd.MasterReqB0
#define MasterReqB1                                                           LinReqCmd.linreqcmd.MasterReqB1
#define MasterReqB2                                                           LinReqCmd.linreqcmd.MasterReqB2
#define MasterReqB3                                                           LinReqCmd.linreqcmd.MasterReqB3
#define MasterReqB4                                                           LinReqCmd.linreqcmd.MasterReqB4
#define MasterReqB5                                                           LinReqCmd.linreqcmd.MasterReqB5
#define MasterReqB6                                                           LinReqCmd.linreqcmd.MasterReqB6
#define MasterReqB7                                                           LinReqCmd.linreqcmd.MasterReqB7
#define Frontwischer_ein                                                      WWSs_01.wwss_01.Frontwischer_ein
#define Frontwaschen_ein                                                      WWSs_01.wwss_01.Frontwaschen_ein
#define Wendelagensignal                                                      WWSs_01.wwss_01.Wendelagensignal
#define Parklagensignal                                                       WWSs_01.wwss_01.Parklagensignal
#define Wischer_Service                                                       WWSs_01.wwss_01.Wischer_Service
#define Wischzyklus_Zaehler_0                                                 WWSs_01.wwss_01.Wischzyklus_Zaehler_0
#define Wischzyklus_Zaehler_1                                                 WWSs_01.wwss_01.Wischzyklus_Zaehler_1
#define Wischzyklus_Zaehler(c)                                                { Wischzyklus_Zaehler_0= (uint8)(((uint16)(c) & 0xFF));\
                                                                                Wischzyklus_Zaehler_1= (uint8)(((uint16)(c) & 0xFF) >> 8);\
                                                                              }
#define Wischer1_Err                                                          WWSs_01.wwss_01.Wischer1_Err
#define Wischer1_Kommunikation                                                WWSs_01.wwss_01.Wischer1_Kommunikation
#define Wischer1_Unterspannung                                                WWSs_01.wwss_01.Wischer1_Unterspannung
#define Wischer1_Ueberspannung                                                WWSs_01.wwss_01.Wischer1_Ueberspannung
#define Wischer1_Ueberlastet                                                  WWSs_01.wwss_01.Wischer1_Ueberlastet
#define Ueberlast1_Err_Aktiv                                                  WWSs_01.wwss_01.Ueberlast1_Err_Aktiv
#define Wischer2_Err                                                          WWSs_01.wwss_01.Wischer2_Err
#define Wischer2_Kommunikation                                                WWSs_01.wwss_01.Wischer2_Kommunikation
#define Wischer2_Unterspannung                                                WWSs_01.wwss_01.Wischer2_Unterspannung
#define Wischer2_Ueberspannung                                                WWSs_01.wwss_01.Wischer2_Ueberspannung
#define Wischer2_Ueberlastet                                                  WWSs_01.wwss_01.Wischer2_Ueberlastet
#define Ueberlast2_Err_Aktiv                                                  WWSs_01.wwss_01.Ueberlast2_Err_Aktiv
#define Master_Zaehler                                                        BCM1s_01.bcm1s_01.Master_Zaehler
#define LSS_Int_Time                                                          BCM1s_01.bcm1s_01.LSS_Int_Time
#define LSS_Tipp_Wischen                                                      BCM1s_01.bcm1s_01.LSS_Tipp_Wischen
#define LSS_Intervall                                                         BCM1s_01.bcm1s_01.LSS_Intervall
#define LSS_WischerStufe_1                                                    BCM1s_01.bcm1s_01.LSS_WischerStufe_1
#define LSS_WischerStufe_2                                                    BCM1s_01.bcm1s_01.LSS_WischerStufe_2
#define LSS_Frontwaschen                                                      BCM1s_01.bcm1s_01.LSS_Frontwaschen
#define Servicestellung                                                       BCM1s_01.bcm1s_01.Servicestellung
#define Frontklappenkontakt                                                   BCM1s_01.bcm1s_01.Frontklappenkontakt
#define Winterstellung                                                        BCM1s_01.bcm1s_01.Winterstellung
#define Klemme_15_LIN1                                                        BCM1s_01.bcm1s_01.Klemme_15_LIN1
#define Klemme_50                                                             BCM1s_01.bcm1s_01.Klemme_50
#define Wendelage_oben                                                        BCM1s_01.bcm1s_01.Wendelage_oben
#define Wendelage_unten                                                       BCM1s_01.bcm1s_01.Wendelage_unten
#define Verglasung_offen                                                      BCM1s_01.bcm1s_01.Verglasung_offen
#define FzgGeschw_VW                                                          BCM1s_01.bcm1s_01.FzgGeschw_VW
#define Aussentemp_gef                                                        BCM1s_01.bcm1s_01.Aussentemp_gef
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
#define l_u8_rd_Helligkeit_IR()                                             Helligkeit_IR
#define l_u8_wr_Helligkeit_IR(a)                                            {Helligkeit_IR = a;}
#define l_u16_rd_Helligkeit_FW()                                              (canuint16)(Helligkeit_FW_0)\
                                                                                | ((canuint16)(Helligkeit_FW_1)<<8)
#define l_u16_wr_Helligkeit_FW(a)                                             {Helligkeit_FW_0 = ((canuint8)a);\
                                                                                 Helligkeit_FW_1 = ((canuint8)a>>8);}
#define l_u8_rd_RLS_Botschaftszaehler()                                               RLS_Zaehler
#define l_u8_wr_RLS_Botschaftszaehler(a)                                              {RLS_Zaehler = a;}
#define l_u8_rd_Wischergeschwindigkeit()                                    Wischergeschwindigkeit
#define l_u8_wr_Wischergeschwindigkeit(a)                                   {Wischergeschwindigkeit = a;}
#define l_bool_rd_Licht_ein()                                                   Licht_ein
#define l_bool_wr_Licht_ein(a)                                                  {Licht_ein = a;}
#define l_bool_rd_Licht_ein_invers()                                            Licht_ein_invers
#define l_bool_wr_Licht_ein_invers(a)                                           {Licht_ein_invers = a;}
#define l_bool_rd_RS_Schwall()                                                  RS_Schwall
#define l_bool_wr_RS_Schwall(a)                                                 {RS_Schwall = a;}
#define l_bool_rd_RS_Direktmodus()                                              RS_Direktmodus
#define l_bool_wr_RS_Direktmodus(a)                                             {RS_Direktmodus = a;}
#define l_bool_rd_Verglasung_schliessen()                                       Verglasung_schliessen
#define l_bool_wr_Verglasung_schliessen(a)                                      {Verglasung_schliessen = a;}
#define l_bool_rd_Dunkel_Hell()                                                 Dunkel_Hell
#define l_bool_wr_Dunkel_Hell(a)                                                {Dunkel_Hell = a;}
#define l_bool_rd_RS_Err()                                                      RS_Err
#define l_bool_wr_RS_Err(a)                                                     {RS_Err = a;}
#define l_bool_rd_LS_Err()                                                      LS_Err
#define l_bool_wr_LS_Err(a)                                                     {LS_Err = a;}
#define l_bool_rd_RLS_Err_Aktiv()                                               RLS_Err_Aktiv
#define l_bool_wr_RLS_Err_Aktiv(a)                                              {RLS_Err_Aktiv = a;}
#define l_bool_rd_RLS_Kommunikation()                                           RLS_Kommunikation
#define l_bool_wr_RLS_Kommunikation(a)                                          {RLS_Kommunikation = a;}
#define l_bool_rd_RLS_Unterspannung()                                           RLS_Unterspannung
#define l_bool_wr_RLS_Unterspannung(a)                                          {RLS_Unterspannung = a;}
#define l_bool_rd_RLS_Ueberspannung()                                           RLS_Ueberspannung
#define l_bool_wr_RLS_Ueberspannung(a)                                          {RLS_Ueberspannung = a;}
#define l_bool_rd_RLS_Adaptierung_Err()                                         RLS_Adaptierung_Err
#define l_bool_wr_RLS_Adaptierung_Err(a)                                        {RLS_Adaptierung_Err = a;}
#define l_bool_rd_Adaptierung_Err_Aktiv()                                       Adaptierung_Err_Aktiv
#define l_bool_wr_Adaptierung_Err_Aktiv(a)                                      {Adaptierung_Err_Aktiv = a;}
#define l_u8_rd_Helligkeit()                                               Helligkeit4
#define l_u8_wr_Helligkeit(a)                                              {Helligkeit4 = a;}
#define l_u8_rd_Regenmenge()                                                Regenmenge
#define l_u8_wr_Regenmenge(a)                                               {Regenmenge = a;}
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
#define l_bool_rd_Frontwischer_ein()                                            Frontwischer_ein
#define l_bool_wr_Frontwischer_ein(a)                                           {Frontwischer_ein = a;}
#define l_bool_rd_Frontwaschen_ein()                                            Frontwaschen_ein
#define l_bool_wr_Frontwaschen_ein(a)                                           {Frontwaschen_ein = a;}
#define l_bool_rd_Wendelagensignal()                                            Wendelagensignal
#define l_bool_wr_Wendelagensignal(a)                                           {Wendelagensignal = a;}
#define l_bool_rd_Parklagensignal()                                             Parklagensignal
#define l_bool_wr_Parklagensignal(a)                                            {Parklagensignal = a;}
#define l_bool_rd_Wischer_Service()                                             Wischer_Service
#define l_bool_wr_Wischer_Service(a)                                            {Wischer_Service = a;}
#define l_u16_rd_Wischzyklus_Zaehler()                                        (canuint16)(Wischzyklus_Zaehler_0)\
                                                                                | ((canuint16)(Wischzyklus_Zaehler_1)<<8)
#define l_u16_wr_Wischzyklus_Zaehler(a)                                       {Wischzyklus_Zaehler_0 = ((canuint8)a);\
                                                                                 Wischzyklus_Zaehler_1 = ((canuint8)a>>8);}
#define l_bool_rd_Wischer1_Err()                                                Wischer1_Err
#define l_bool_wr_Wischer1_Err(a)                                               {Wischer1_Err = a;}
#define l_bool_rd_Wischer1_Kommunikation()                                      Wischer1_Kommunikation
#define l_bool_wr_Wischer1_Kommunikation(a)                                     {Wischer1_Kommunikation = a;}
#define l_bool_rd_Wischer1_Unterspannung()                                      Wischer1_Unterspannung
#define l_bool_wr_Wischer1_Unterspannung(a)                                     {Wischer1_Unterspannung = a;}
#define l_bool_rd_Wischer1_Ueberspannung()                                      Wischer1_Ueberspannung
#define l_bool_wr_Wischer1_Ueberspannung(a)                                     {Wischer1_Ueberspannung = a;}
#define l_bool_rd_Wischer1_Ueberlastet()                                        Wischer1_Ueberlastet
#define l_bool_wr_Wischer1_Ueberlastet(a)                                       {Wischer1_Ueberlastet = a;}
#define l_bool_rd_Ueberlast1_Err_Aktiv()                                        Ueberlast1_Err_Aktiv
#define l_bool_wr_Ueberlast1_Err_Aktiv(a)                                       {Ueberlast1_Err_Aktiv = a;}
#define l_bool_rd_Wischer2_Err()                                                Wischer2_Err
#define l_bool_wr_Wischer2_Err(a)                                               {Wischer2_Err = a;}
#define l_bool_rd_Wischer2_Kommunikation()                                      Wischer2_Kommunikation
#define l_bool_wr_Wischer2_Kommunikation(a)                                     {Wischer2_Kommunikation = a;}
#define l_bool_rd_Wischer2_Unterspannung()                                      Wischer2_Unterspannung
#define l_bool_wr_Wischer2_Unterspannung(a)                                     {Wischer2_Unterspannung = a;}
#define l_bool_rd_Wischer2_Ueberspannung()                                      Wischer2_Ueberspannung
#define l_bool_wr_Wischer2_Ueberspannung(a)                                     {Wischer2_Ueberspannung = a;}
#define l_bool_rd_Wischer2_Ueberlastet()                                        Wischer2_Ueberlastet
#define l_bool_wr_Wischer2_Ueberlastet(a)                                       {Wischer2_Ueberlastet = a;}
#define l_bool_rd_Ueberlast2_Err_Aktiv()                                        Ueberlast2_Err_Aktiv
#define l_bool_wr_Ueberlast2_Err_Aktiv(a)                                       {Ueberlast2_Err_Aktiv = a;}
#define l_u8_rd_Master_Zaehler()                                            Master_Zaehler
#define l_u8_wr_Master_Zaehler(a)                                           {Master_Zaehler = a;}
#define l_u8_rd_LSS_Int_Time()                                              LSS_Int_Time
#define l_u8_wr_LSS_Int_Time(a)                                             {LSS_Int_Time = a;}
#define l_bool_rd_LSS_Tipp_Wischen()                                            LSS_Tipp_Wischen
#define l_bool_wr_LSS_Tipp_Wischen(a)                                           {LSS_Tipp_Wischen = a;}
#define l_bool_rd_LSS_Intervall()                                               LSS_Intervall
#define l_bool_wr_LSS_Intervall(a)                                              {LSS_Intervall = a;}
#define l_bool_rd_LSS_WischerStufe_1()                                          LSS_WischerStufe_1
#define l_bool_wr_LSS_WischerStufe_1(a)                                         {LSS_WischerStufe_1 = a;}
#define l_bool_rd_LSS_WischerStufe_2()                                          LSS_WischerStufe_2
#define l_bool_wr_LSS_WischerStufe_2(a)                                         {LSS_WischerStufe_2 = a;}
#define l_bool_rd_LSS_Frontwaschen()                                            LSS_Frontwaschen
#define l_bool_wr_LSS_Frontwaschen(a)                                           {LSS_Frontwaschen = a;}
#define l_bool_rd_Servicestellung()                                             Servicestellung
#define l_bool_wr_Servicestellung(a)                                            {Servicestellung = a;}
#define l_bool_rd_Frontklappenkontakt()                                         Frontklappenkontakt
#define l_bool_wr_Frontklappenkontakt(a)                                        {Frontklappenkontakt = a;}
#define l_bool_rd_Winterstellung()                                              Winterstellung
#define l_bool_wr_Winterstellung(a)                                             {Winterstellung = a;}
#define l_bool_rd_Klemme_15()                                              Klemme_15_LIN1
#define l_bool_wr_Klemme_15(a)                                             {Klemme_15_LIN1 = a;}
#define l_bool_rd_Klemme_50()                                                   Klemme_50
#define l_bool_wr_Klemme_50(a)                                                  {Klemme_50 = a;}
#define l_bool_rd_Wendelage_oben()                                              Wendelage_oben
#define l_bool_wr_Wendelage_oben(a)                                             {Wendelage_oben = a;}
#define l_bool_rd_Wendelage_unten()                                             Wendelage_unten
#define l_bool_wr_Wendelage_unten(a)                                            {Wendelage_unten = a;}
#define l_bool_rd_Verglasung_offen()                                            Verglasung_offen
#define l_bool_wr_Verglasung_offen(a)                                           {Verglasung_offen = a;}
#define l_u8_rd_FzgGeschw()                                              FzgGeschw_VW
#define l_u8_wr_FzgGeschw(a)                                             {FzgGeschw_VW = a;}
#define l_u8_rd_Aussentemp_gef()                                            Aussentemp_gef
#define l_u8_wr_Aussentemp_gef(a)                                           {Aussentemp_gef = a;}


#endif  /* I_LIN_RLS_H */
