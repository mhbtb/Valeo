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
#define cb_HANDLE_ASIC_Frame_04_g           1
#define cb_HANDLE_ASIC_Frame_03_g           2
#define cb_HANDLE_ASIC_Frame_02_g           3
#define cb_HANDLE_ASIC_Frame_01_g           4
#define cb_HANDLE_RLSs_01_g               5  /* cb_HANDLE_RLSData */ 
#define cb_HANDLE_FSs_01_g                6  /* cb_HANDLE_HRLSData */ 
#define cb_HANDLE_LinReqCmd_g               7  
#define cb_HANDLE_WWSs_01_g               8  /* cb_HANDLE_RLSCfgData */ 
#define cb_HANDLE_BCM1_LIN1_01_g         9  /* cb_HANDLE_ComToRLS */ 
#define cb_HANDLE_SoSes_01               10 /* cb_HANDLE_ComToHRLS*/ 


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
  canbittype                                  unused0: 3;
  canbittype                       LightSensorFailSts: 1;
  canbittype                        RainSensorFailSts: 1;
  canbittype                      HeadLampsActivation: 1;
  canbittype                                WiperMode: 1;
  canbittype                             WiperSpeed_0: 1;
  canbittype                             WiperSpeed_1: 2;
  canbittype                      LightSensorSelected: 1;
  canbittype                       RainSensorSelected: 1;
  canbittype                      ResponseErrorStsRLS: 1;
  canbittype                        GenericFailStsRLS: 1;
  canbittype                        CurrentFailStsRLS: 1;
  canbittype                             KeepAliveRLS: 1;
} _c_RLSData_msgType;

typedef struct {
  canbittype                                  unused0: 3;
  canbittype                       LightSensorFailSts: 1;
  canbittype                        RainSensorFailSts: 1;
  canbittype                      HeadLampsActivation: 1;
  canbittype                             WiperSpeed_0: 2;
  canbittype                             WiperSpeed_1: 1;
  canbittype                      LightSensorSelected: 1;
  canbittype                       RainSensorSelected: 1;
  canbittype                     ResponseErrorStsHRLS: 1;
  canbittype                        SolarSensorLeft_0: 4;
  canbittype                        SolarSensorLeft_1: 4;
  canbittype                       SolarSensorRight_0: 4;
  canbittype                       SolarSensorRight_1: 4;
  canbittype                              GlassTemp_0: 4;
  canbittype                              GlassTemp_1: 7;
  canbittype                                  unused1: 1;
  canbittype                            DewpointTmp_0: 8;
  canbittype                            DewpointTmp_1: 3;
  canbittype                            RelHumidity_0: 5;
  canbittype                            RelHumidity_1: 3;
  canbittype                          HumSns_Int_flt1: 1;
  canbittype                                  unused2: 4;
} _c_HRLSData_msgType;


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
  canbittype                                  unused0: 8;
  canbittype                       Transmission_550nm: 4;
  canbittype                       Transmission_880nm: 4;
} _c_RLSCfgData_msgType;

typedef struct {
  canbittype                                  unused0: 6;
  canbittype                   SelectedSensitivityL_0: 2;
  canbittype                   SelectedSensitivityL_1: 1;
  canbittype                        LightSensorActive: 1;
  canbittype                         RainSensorActive: 1;
  canbittype                     SelectedSensitivityR: 3;
  canbittype                        WiperWasherActive: 1;
  canbittype                              WiperInPark: 1;
  canbittype                           VehicleSpeed_0: 8;
  canbittype                           VehicleSpeed_1: 5;
  canbittype                        GenericFailStsBCM: 1;
  canbittype                        CurrentFailStsBCM: 1;
  canbittype                             KeepAliveBCM: 1;
} _c_ComToRLS_msgType;

typedef struct {
  canbittype                     SelectedSensitivityL: 3;
  canbittype                        LightSensorActive: 1;
  canbittype                         RainSensorActive: 1;
  canbittype                     SelectedSensitivityR: 3;
  canbittype                        WiperWasherActive: 1;
  canbittype                              WiperInPark: 1;
  canbittype                           VehicleSpeed_0: 6;
  canbittype                           VehicleSpeed_1: 7;
  canbittype                                  unused0: 1;
  canbittype                       Transmission_880nm: 4;
  canbittype                       Transmission_550nm: 4;
  canbittype                                  unused1: 8;
  canbittype                                  unused2: 8;
  canbittype                                  unused3: 8;
  canbittype                                  unused4: 8;
} _c_ComToHRLS_msgType;


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
    unsigned char _c[2];
    _c_RLSData_msgType rlsdata;
} _c_RLSData_buf;

typedef union {
    unsigned char _c[8];
    _c_HRLSData_msgType hrlsdata;
} _c_HRLSData_buf;


/* Receive messages */

typedef union {
    unsigned char _c[8];
    _c_LinReqCmd_msgType linreqcmd;
} _c_LinReqCmd_buf;

typedef union {
    unsigned char _c[2];
    _c_RLSCfgData_msgType rlscfgdata;
} _c_RLSCfgData_buf;

typedef union {
    unsigned char _c[4];
    _c_ComToRLS_msgType comtorls;
} _c_ComToRLS_buf;

typedef union {
    unsigned char _c[8];
    _c_ComToHRLS_msgType comtohrls;
} _c_ComToHRLS_buf;


/******************************************************************************/
/*                          Databuffer for send objects                       */
/******************************************************************************/

extern MEMORY_FAR _c_LinRespCmd_buf LinRespCmd;
extern MEMORY_FAR _c_ASIC_Frame_04_buf ASIC_Frame_04;
extern MEMORY_FAR _c_ASIC_Frame_03_buf ASIC_Frame_03;
extern MEMORY_FAR _c_ASIC_Frame_02_buf ASIC_Frame_02;
extern MEMORY_FAR _c_ASIC_Frame_01_buf ASIC_Frame_01;
extern MEMORY_FAR _c_RLSData_buf RLSData;
extern MEMORY_FAR _c_HRLSData_buf HRLSData;

/******************************************************************************/
/*                        Databuffer for confirmationflags                    */
/******************************************************************************/

#define LinRespCmd_conf_b               uLinConfirmationFlags.w[0].b0
#define l_flg_tst_LinRespCmd()          (LinRespCmd_conf_b != 0)
#define l_flg_clr_LinRespCmd()          {LinRespCmd_conf_b = 0;}
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
#define RLSData_conf_b                  uLinConfirmationFlags.w[0].b5
#define l_flg_tst_RLSData()             (RLSData_conf_b != 0)
#define l_flg_clr_RLSData()             {RLSData_conf_b = 0;}
#define HRLSData_conf_b                 uLinConfirmationFlags.w[0].b6
#define l_flg_tst_HRLSData()            (HRLSData_conf_b != 0)    
#define l_flg_clr_HRLSData()            {HRLSData_conf_b = 0;}        

/******************************************************************************/
/*                         Databuffer for receive objects                     */
/******************************************************************************/

extern MEMORY_FAR _c_LinReqCmd_buf LinReqCmd;
extern MEMORY_FAR _c_RLSCfgData_buf RLSCfgData;
extern MEMORY_FAR _c_ComToRLS_buf ComToRLS;
extern MEMORY_FAR _c_ComToHRLS_buf ComToHRLS;

/******************************************************************************/
/*                          Databuffer for indicationflags                    */
/******************************************************************************/

#define LinReqCmd_ind_b             uLinIndicationFlags.w[0].b0
#define l_flg_tst_LinReqCmd()       (LinReqCmd_ind_b != 0)
#define l_flg_clr_LinReqCmd()       {LinReqCmd_ind_b = 0;}
#define RLSCfgData_ind_b             uLinIndicationFlags.w[0].b1
//#define l_flg_tst_RLSCfgData()       (RLSCfgData_ind_b != 0)
//#define l_flg_clr_RLSCfgData()       {RLSCfgData_ind_b = 0;}
#define l_flg_tst_RLSDCfgData()       (RLSCfgData_ind_b != 0) /* FIAT_330 Adaptation to generic code in RLS_LIN_FIAT_330 */ 
#define l_flg_clr_RLSDCfgData()       {RLSCfgData_ind_b = 0;} /* FIAT_330 Adaptation to generic code in RLS_LIN_FIAT_330 */ 
#define ComToRLS_ind_b             uLinIndicationFlags.w[0].b2
#define l_flg_tst_ComToRLS()       (ComToRLS_ind_b != 0)
#define l_flg_clr_ComToRLS()       {ComToRLS_ind_b = 0;}
#define ComToHRLS_ind_b             uLinIndicationFlags.w[0].b3
#define l_flg_tst_ComToHRLS()       (ComToHRLS_ind_b != 0)
#define l_flg_clr_ComToHRLS()       {ComToHRLS_ind_b = 0;}

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
#define LightSensorFailSts_RLS                                                    RLSData.rlsdata.LightSensorFailSts
#define RainSensorFailSts_RLS                                                     RLSData.rlsdata.RainSensorFailSts
#define HeadLampsActivation_RLS                                                   RLSData.rlsdata.HeadLampsActivation
#define WiperMode                                                             RLSData.rlsdata.WiperMode
#define WiperSpeed_0_RLS                                                          RLSData.rlsdata.WiperSpeed_0
#define WiperSpeed_1_RLS                                                          RLSData.rlsdata.WiperSpeed_1
#define WiperSpeed_RLS(c)                                                         { WiperSpeed_0_RLS= (uint8)(((uint16)(c) & 0x01));\
                                                                                    WiperSpeed_1_RLS= (uint8)(((uint16)(c) & 0x1fe) >> 1);\
                                                                                  }
#define LightSensorSelected_RLS                                                   RLSData.rlsdata.LightSensorSelected
#define RainSensorSelected_RLS                                                    RLSData.rlsdata.RainSensorSelected
#define ResponseErrorStsRLS                                                   RLSData.rlsdata.ResponseErrorStsRLS
#define GenericFailStsRLS                                                     RLSData.rlsdata.GenericFailStsRLS
#define CurrentFailStsRLS                                                     RLSData.rlsdata.CurrentFailStsRLS
#define KeepAliveRLS                                                          RLSData.rlsdata.KeepAliveRLS
#define LightSensorFailSts_HRLS                                                   HRLSData.hrlsdata.LightSensorFailSts
#define RainSensorFailSts_HRLS                                                    HRLSData.hrlsdata.RainSensorFailSts
#define HeadLampsActivation_HRLS                                                  HRLSData.hrlsdata.HeadLampsActivation
#define WiperSpeed_0_HRLS                                                          HRLSData.hrlsdata.WiperSpeed_0
#define WiperSpeed_1_HRLS                                                          HRLSData.hrlsdata.WiperSpeed_1
#define WiperSpeed_HRLS(c)                                                         { WiperSpeed_0_HRLS= (uint8)(((uint16)(c) & 0x03));\
                                                                                     WiperSpeed_1_HRLS= (uint8)(((uint16)(c) & 0xFC) >> 2);\
                                                                                   }
#define LightSensorSelected_HRLS                                                  HRLSData.hrlsdata.LightSensorSelected
#define RainSensorSelected_HRLS                                                   HRLSData.hrlsdata.RainSensorSelected
#define ResponseErrorStsHRLS                                                  HRLSData.hrlsdata.ResponseErrorStsHRLS
#define SolarSensorLeft_0                                                     HRLSData.hrlsdata.SolarSensorLeft_0
#define SolarSensorLeft_1                                                     HRLSData.hrlsdata.SolarSensorLeft_1
#define SolarSensorLeft(c)                                                    { SolarSensorLeft_0= (uint8)(((uint16)(c) & 0x0F));\
                                                                                SolarSensorLeft_1= (uint8)(((uint16)(c) & 0xF0) >> 4);\
                                                                              }
#define SolarSensorRight_0                                                    HRLSData.hrlsdata.SolarSensorRight_0
#define SolarSensorRight_1                                                    HRLSData.hrlsdata.SolarSensorRight_1
#define SolarSensorRight(c)                                                   { SolarSensorRight_0= (uint8)(((uint16)(c) & 0x0F));\
                                                                                SolarSensorRight_1= (uint8)(((uint16)(c) & 0xF0) >> 4);\
                                                                              }
#define GlassTemp_0                                                           HRLSData.hrlsdata.GlassTemp_0
#define GlassTemp_1                                                           HRLSData.hrlsdata.GlassTemp_1
#define GlassTemp(c)                                                          { GlassTemp_0= (uint8)(((uint16)(c) & 0x0F));\
                                                                                GlassTemp_1= (uint8)(((uint16)(c) & 0x7FF) >> 4);\
                                                                              }
#define DewpointTmp_0                                                         HRLSData.hrlsdata.DewpointTmp_0
#define DewpointTmp_1                                                         HRLSData.hrlsdata.DewpointTmp_1
#define DewpointTmp(c)                                                        { DewpointTmp_0= (uint8)(((uint16)(c) & 0xFF));\
                                                                                DewpointTmp_1= (uint8)(((uint16)(c) & 0x07) >> 8);\
                                                                              }
#define RelHumidity_0                                                         HRLSData.hrlsdata.RelHumidity_0
#define RelHumidity_1                                                         HRLSData.hrlsdata.RelHumidity_1
#define RelHumidity(c)                                                        { RelHumidity_0= (uint8)(((uint16)(c) & 0x1F));\
                                                                                RelHumidity_1= (uint8)(((uint16)(c) & 0xE0) >> 5);\
                                                                              }
#define HumSns_Int_flt1                                                       HRLSData.hrlsdata.HumSns_Int_flt1
#define MasterReqB0                                                           LinReqCmd.linreqcmd.MasterReqB0
#define MasterReqB1                                                           LinReqCmd.linreqcmd.MasterReqB1
#define MasterReqB2                                                           LinReqCmd.linreqcmd.MasterReqB2
#define MasterReqB3                                                           LinReqCmd.linreqcmd.MasterReqB3
#define MasterReqB4                                                           LinReqCmd.linreqcmd.MasterReqB4
#define MasterReqB5                                                           LinReqCmd.linreqcmd.MasterReqB5
#define MasterReqB6                                                           LinReqCmd.linreqcmd.MasterReqB6
#define MasterReqB7                                                           LinReqCmd.linreqcmd.MasterReqB7
#define Transmission_550nm_RLSCfg                                                    RLSCfgData.rlscfgdata.Transmission_550nm
#define Transmission_880nm_RLSCfg                                                     RLSCfgData.rlscfgdata.Transmission_880nm
#define SelectedSensitivityL_0                                                ComToRLS.comtorls.SelectedSensitivityL_0
#define SelectedSensitivityL_1                                                ComToRLS.comtorls.SelectedSensitivityL_1
/* #define SelectedSensitivityL(c)                                               { SelectedSensitivityL_0= (uint8)(((uint16)(c) & 0x03));\
                                                                                SelectedSensitivityL_1= (uint8)(((uint16)(c) & 0x04) >> 2);\
                                                                              } */
 #define SelectedSensitivityL_RLS                                                      (uint16)(((uint16)(SelectedSensitivityL_1) << 2)\
                                                                                   | (SelectedSensitivityL_0))																			  
#define LightSensorActive_RLS                                                     ComToRLS.comtorls.LightSensorActive
#define RainSensorActive_RLS                                                      ComToRLS.comtorls.RainSensorActive
#define SelectedSensitivityR_RLS                                                  ComToRLS.comtorls.SelectedSensitivityR
#define WiperWasherActive_RLS                                                     ComToRLS.comtorls.WiperWasherActive
#define WiperInPark_RLS                                                           ComToRLS.comtorls.WiperInPark
#define VehicleSpeed_0_RLS                                                        ComToRLS.comtorls.VehicleSpeed_0
#define VehicleSpeed_1_RLS                                                        ComToRLS.comtorls.VehicleSpeed_1
/* #define VehicleSpeed_RLS(c)                                                       { VehicleSpeed_0_RLS= (uint8)(((uint16)(c) & 0xFF));\
                                                                                     VehicleSpeed_1_RLS= (uint8)(((uint16)(c) & 0x1F) >> 8);\
                                                                                     } */ 
#define VehicleSpeed_RLS                                                              (uint16)(((uint16)(VehicleSpeed_1_RLS) << 8)\
                                                                                  | (VehicleSpeed_0_RLS))																					 																					 
#define GenericFailStsBCM                                                     ComToRLS.comtorls.GenericFailStsBCM
#define CurrentFailStsBCM                                                     ComToRLS.comtorls.CurrentFailStsBCM
#define KeepAliveBCM                                                          ComToRLS.comtorls.KeepAliveBCM
#define SelectedSensitivityL_HRLS                                                 ComToHRLS.comtohrls.SelectedSensitivityL
#define LightSensorActive_HRLS                                                    ComToHRLS.comtohrls.LightSensorActive
#define RainSensorActive_HRLS                                                     ComToHRLS.comtohrls.RainSensorActive
#define SelectedSensitivityR_HRLS                                                 ComToHRLS.comtohrls.SelectedSensitivityR
#define WiperWasherActive_HRLS                                                    ComToHRLS.comtohrls.WiperWasherActive
#define WiperInPark_HRLS                                                          ComToHRLS.comtohrls.WiperInPark
#define VehicleSpeed_0_HRLS                                                      ComToHRLS.comtohrls.VehicleSpeed_0
#define VehicleSpeed_1_HRLS                                                       ComToHRLS.comtohrls.VehicleSpeed_1
#define VehicleSpeed_HRLS(c)                                                     { VehicleSpeed_0_HRLS= (uint8)(((uint16)(c) & 0x3F));\
                                                                                    VehicleSpeed_1_HRLS= (uint8)(((uint16)(c) & 0x1FFF) >> 6);\
                                                                                    }
#define Transmission_880nm_ComHRLS                                                   ComToHRLS.comtohrls.Transmission_880nm
#define Transmission_550nm_ComHRLS                                                   ComToHRLS.comtohrls.Transmission_550nm
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
#define l_bool_rd_LightSensorFailSts_RLS()                                          LightSensorFailSts_RLS
#define l_bool_wr_LightSensorFailSts_RLS(a)                                         {LightSensorFailSts_RLS = a;}
#define l_bool_rd_RainSensorFailSts_RLS()                                           RainSensorFailSts_RLS
#define l_bool_wr_RainSensorFailSts_RLS(a)                                          {RainSensorFailSts_RLS = a;}
#define l_bool_rd_HeadLampsActivation_RLS()                                         HeadLampsActivation_RLS
#define l_bool_wr_HeadLampsActivation_RLS(a)                                        {HeadLampsActivation_RLS = a;}
#define l_bool_rd_WiperMode()                                                   WiperMode
#define l_bool_wr_WiperMode(a)                                                  {WiperMode = a;}
/* #define l_u8_rd_WiperSpeed_RLS()                                                 (canuint16)(WiperSpeed_0_RLS)\
                                                                                | ((canuint16)(WiperSpeed_1_RLS)<<1) */
#define l_u8_rd_WiperSpeed_RLS()                                        		(canuint16)(((canuint16)(WiperSpeed_1_RLS) << 1)\
                                                                  				| (WiperSpeed_0_RLS))																				
#define l_u8_wr_WiperSpeed_RLS(a)                                               {WiperSpeed_0_RLS  = ((canuint8)(a & 0x01));\
                                                                                 WiperSpeed_1_RLS = ((canuint8)((a >>1) & 0x03));}
#define l_bool_rd_LightSensorSelected_RLS()                                         LightSensorSelected_RLS
#define l_bool_wr_LightSensorSelected_RLS(a)                                        {LightSensorSelected_RLS = a;}
#define l_bool_rd_RainSensorSelected_RLS()                                          RainSensorSelected_RLS
#define l_bool_wr_RainSensorSelected_RLS(a)                                         {RainSensorSelected_RLS = a;}
#define l_bool_rd_ResponseErrorStsRLS()                                         ResponseErrorStsRLS
#define l_bool_wr_ResponseErrorStsRLS(a)                                        {ResponseErrorStsRLS = a;}
#define l_bool_rd_RLSGenericFailSts()                                           GenericFailStsRLS
#define l_bool_wr_RLSGenericFailSts(a)                                          {GenericFailStsRLS = a;}
#define l_bool_rd_RLSCurrentFailSts()                                           CurrentFailStsRLS
#define l_bool_wr_RLSCurrentFailSts(a)                                          {CurrentFailStsRLS = a;}
#define l_bool_rd_KeepAliveRLS()                                                KeepAliveRLS
#define l_bool_wr_KeepAliveRLS(a)                                               {KeepAliveRLS = a;}
#define l_bool_rd_LightSensorFailSts_HRLS()                                         LightSensorFailSts_HRLS
#define l_bool_wr_LightSensorFailSts_HRLS(a)                                        {LightSensorFailSts_HRLS = a;}
#define l_bool_rd_RainSensorFailSts_HRLS()                                          RainSensorFailSts_HRLS
#define l_bool_wr_RainSensorFailSts_HRLS(a)                                         {RainSensorFailSts_HRLS = a;}
#define l_bool_rd_HeadLampsActivation_HRLS()                                        HeadLampsActivation_HRLS
#define l_bool_wr_HeadLampsActivation_HRLS(a)                                       {HeadLampsActivation_HRLS = a;}
#define l_u8_rd_WiperSpeed_HRLS()                                                 (canuint16)(WiperSpeed_0_HRLS)\
                                                                                | ((canuint16)(WiperSpeed_1_HRLS)<<2)
#define l_u8_wr_WiperSpeed_HRLS(a)                                                {WiperSpeed_0_HRLS = ((canuint8)a);\
                                                                                 WiperSpeed_1_HRLS = ((canuint8)a>>2);}
#define l_bool_rd_LightSensorSelected_HRLS()                                        LightSensorSelected_HRLS
#define l_bool_wr_LightSensorSelected_HRLS(a)                                       {LightSensorSelected_HRLS = a;}
#define l_bool_rd_RainSensorSelected_HRLS()                                         RainSensorSelected_HRLS
#define l_bool_wr_RainSensorSelected_HRLS(a)                                        {RainSensorSelected_HRLS = a;}
#define l_bool_rd_ResponseErrorStsHRLS()                                        ResponseErrorStsHRLS
#define l_bool_wr_ResponseErrorStsHRLS(a)                                       {ResponseErrorStsHRLS = a;}

//#define l_u8_rd_SolarSensorLeft()                                            (canuint16)(SolarSensorLeft_0)\
//                                                                                | ((canuint16)(SolarSensorLeft_1)<<4)

#define l_u8_rd_SolarSensorLeft()                                        (canuint16)(((canuint16)(SolarSensorLeft_1) << 4)\
                                                                  | (SolarSensorLeft_0))

//#define l_u8_wr_SolarSensorLeft(a)                                           {SolarSensorLeft_0 = ((canuint8)(a & 0x0F));\
//                                                                                 SolarSensorLeft_1 = ((canuint8)((a>>4) & 0x0F));}

#define l_u8_wr_SolarSensorLeft(a)                                       {SolarSensorLeft_0  = ((canuint8)(a & 0x0F));\
                                                                     SolarSensorLeft_1 = ((canuint8)((a >>4) & 0x0F));}

//#define l_u8_rd_SolarSensorRight()                                           (canuint16)(SolarSensorRight_0)\
//                                                                                | ((canuint16)(SolarSensorRight_1)<<4)

#define l_u8_rd_SolarSensorRight()                                        (canuint16)(((canuint16)(SolarSensorRight_1) << 4)\
                                                                  | (SolarSensorRight_0))

#define l_u8_wr_SolarSensorRight(a)                                          {SolarSensorRight_0 = ((canuint8)(a & 0x0F));\
                                                                                 SolarSensorRight_1 = ((canuint8)((a>>4) & 0x0F));}

//#define l_u16_rd_GlassTemp()                                                  (canuint16)(GlassTemp_0)\
//                                                                                | ((canuint16)(GlassTemp_1)<<4)
                                                                                  
#define l_u16_rd_GlassTemp()                                                  (canuint16)(GlassTemp_1)<<4)\
                                                                                | ((canuint16)(GlassTemp_0)                                                                                  
                                                                                  
#define l_u16_wr_GlassTemp(a)                                                 {GlassTemp_0 = ((canuint8) (a & 0x0F));\
                                                                                 GlassTemp_1 = ((canuint8) ((a>>4) & 0x7F));}
                                                                                    
#define l_u16_rd_DewpointTmp()                                                (canuint16)(DewpointTmp_0)\
                                                                                | ((canuint16)(DewpointTmp_1)<<8)
//#define l_u16_wr_DewpointTmp(a)                                               {DewpointTmp_0 = ((canuint8)a);\
//                                                                                 DewpointTmp_1 = ((canuint8)a>>8);}

#define l_u16_wr_DewpointTmp(a)                                                 {DewpointTmp_0 = ((canuint8) (a & 0xFF));\
                                                                                 DewpointTmp_1 = ((canuint8) ((a>>8) & 0x07));}
                                                                                    
#define l_u8_rd_RelHumidity()                                                (canuint16)(RelHumidity_0)\
                                                                                | ((canuint16)(RelHumidity_1)<<5)
#define l_u8_wr_RelHumidity(a)                                               {RelHumidity_0 = ((canuint8) (a & 0x1F));\
                                                                                 RelHumidity_1 = ((canuint8)(a>>5) & 0x07);}
#define l_bool_rd_HumSns_Int_flt()                                             HumSns_Int_flt1
#define l_bool_wr_HumSns_Int_flt(a)                                            {HumSns_Int_flt1 = a;}
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
// #define l_u8_rd_Transmission_550nm()                                        Transmission_550nm  /* FIAT_330 Adaptation to generic code in RLS_LIN_FIAT_330 */ 
// #define l_u8_wr_Transmission_550nm(a)                                       {Transmission_550nm = a;}
// #define l_u8_rd_Transmission_880nm()                                        Transmission_880nm  
// #define l_u8_wr_Transmission_880nm(a)                                       {Transmission_880nm = a;} /* FIAT_330 Adaptation to generic code in RLS_LIN_FIAT_330 */
#define l_u8_rd_FW_550nmTransmission_RLSCfg()                                        Transmission_550nm_RLSCfg
#define l_u8_wr_FW_550nmTransmission_RLSCfg(a)                                       {Transmission_550nm_RLSCfg = a;}
#define l_u8_rd_IR_880nmTransmission_RLSCfg()                                        Transmission_880nm_RLSCfg
#define l_u8_wr_IR_880nmTransmission_RLSCfg(a)                                       {Transmission_880nm_RLSCfg = a;}


//#define l_u16_rd_SelectedSensitivityL()                                       (canuint16)(SelectedSensitivityL_0)\                  /* Bad auto-generation : taken from Ferrari*/ 
//                                                                                | ((canuint16)(SelectedSensitivityL_1)<<2)
//#define l_u16_wr_SelectedSensitivityL(a)                                      {SelectedSensitivityL_0 = ((canuint8)a);\
//                                                                                 SelectedSensitivityL_1 = ((canuint8)a>>2);}

#define l_u8_rd_SelectedSensitivityL_RLS()                              (canuint16)(((canuint16)(SelectedSensitivityL_1) << 2)\
                                                                  | (SelectedSensitivityL_0))
#define l_u8_wr_SelectedSensitivityL_RLS(a)                             {SelectedSensitivityL_1 = ((canuint8)(a >> 2));\
                                                                  SelectedSensitivityL_0 = ((canuint8)a);}

#define l_bool_rd_LightSensorActive_RLS()                                           LightSensorActive_RLS
#define l_bool_wr_LightSensorActive_RLS(a)                                          {LightSensorActive_RLS = a;}
#define l_bool_rd_RainSensorActive_RLS()                                            RainSensorActive_RLS
#define l_bool_wr_RainSensorActive_RLS(a)                                           {RainSensorActive_RLS = a;}
#define l_u8_rd_SelectedSensitivityR_RLS()                                      SelectedSensitivityR_RLS
#define l_u8_wr_SelectedSensitivityR_RLS(a)                                     {SelectedSensitivityR_RLS = a;}
#define l_bool_rd_WiperWasherActive_RLS()                                           WiperWasherActive_RLS
#define l_bool_wr_WiperWasherActive_RLS(a)                                          {WiperWasherActive_RLS = a;}
#define l_bool_rd_WiperInPark_RLS()                                                 WiperInPark_RLS
#define l_bool_wr_WiperInPark_RLS(a)                                                {WiperInPark_RLS = a;}
/* #define l_u16_rd_VehicleSpeed_RLS()                                               (canuint16)(VehicleSpeed_0_HRLS)\
                                                                                | ((canuint16)(VehicleSpeed_1_HRLS)<<8)
#define l_u16_wr_VehicleSpeed_RLS(a)                                              {VehicleSpeed_0_RLS = ((canuint8)a);\
                                                                                 VehicleSpeed_1_RLS = ((canuint8)a>>8);} */ 
#define l_u16_rd_VehicleSpeed_RLS()                                                 (canuint16)(((canuint16)(VehicleSpeed_1_RLS) << 8)\
                                                                                | (VehicleSpeed_0_RLS))
#define l_u16_wr_VehicleSpeed_RLS(a)                                                {VehicleSpeed_1_RLS = ((canuint8)(a >> 8));\
                                                                                 VehicleSpeed_0_RLS = ((canuint8)a);}																  																				 
#define l_bool_rd_GenericFailStsBCM()                                           GenericFailStsBCM
#define l_bool_wr_GenericFailStsBCM(a)                                          {GenericFailStsBCM = a;} 
#define l_bool_rd_CurrentFailStsBCM()                                           CurrentFailStsBCM
#define l_bool_wr_CurrentFailStsBCM(a)                                          {CurrentFailStsBCM = a;} 
#define l_bool_rd_KeepAliveBCM()                                                KeepAliveBCM
#define l_bool_wr_KeepAliveBCM(a)                                               {KeepAliveBCM = a;}
#define l_u8_rd_SelectedSensitivityL_HRLS()                                     SelectedSensitivityL_HRLS
#define l_u8_wr_SelectedSensitivityL_HRLS(a)                                    {SelectedSensitivityL_HRLS = a;}
#define l_bool_rd_LightSensorActive_HRLS()                                          LightSensorActive_HRLS
#define l_bool_wr_LightSensorActive_HRLS(a)                                         {LightSensorActive_HRLS = a;}
#define l_bool_rd_RainSensorActive_HRLS()                                           RainSensorActive_HRLS
#define l_bool_wr_RainSensorActive_HRLS(a)                                          {RainSensorActive_HRLS = a;}
#define l_u8_rd_SelectedSensitivityR_HRLS()                                     SelectedSensitivityR_HRLS
#define l_u8_wr_SelectedSensitivityR_HRLS(a)                                    {SelectedSensitivityR_HRLS = a;}
#define l_bool_rd_WiperWasherActive_HRLS()                                          WiperWasherActive_HRLS
#define l_bool_wr_WiperWasherActive_HRLS(a)                                         {WiperWasherActive_HRLS = a;}
#define l_bool_rd_WiperInPark_HRLS()                                                WiperInPark_HRLS
#define l_bool_wr_WiperInPark_HRLS(a)                                               {WiperInPark_HRLS = a;}

//#define l_u16_rd_VehicleSpeed_HRLS()                                               (canuint16)(VehicleSpeed_0_HRLS)\
//                                                                                | ((canuint16)(VehicleSpeed_1_HRLS)<<6)

#define l_u16_rd_VehicleSpeed_HRLS()                                     (canuint16)(((canuint16)(VehicleSpeed_1_HRLS) << 6)\
                                                                  | (VehicleSpeed_0_HRLS))

//#define l_u16_wr_VehicleSpeed_HRLS(a)                                              {VehicleSpeed_0_HRLS = ((canuint8)a);\
//                                                                                 VehicleSpeed_1_HRLS = ((canuint8)a>>6);}

#define l_u16_wr_VehicleSpeed_HRLS(a)                                    {VehicleSpeed_1_HRLS = ((canuint8)((a >> 6)& 0x7F) );\
                                                                  VehicleSpeed_0_HRLS = ((canuint8)(a& 0x3F));}

#define l_u8_rd_Transmission_880nm_ComHRLS()                                       Transmission_880nm_ComHRLS
#define l_u8_wr_Transmission_880nm_ComHRLS(a)                                      {Transmission_880nm_ComHRLS = a;}
#define l_u8_rd_Transmission_550nm_ComHRLS()                                       Transmission_550nm_ComHRLS
#define l_u8_wr_Transmission_550nm_ComHRLS(a)                                      {Transmission_550nm_ComHRLS = a;}


#endif  /* I_LIN_RLS_H */
