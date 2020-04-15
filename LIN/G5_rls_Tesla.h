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
/* Date        VDR_Number  Author  Description                                                                        */
/* 30.03.2016  VDR_968     NB      TESLA:Vehicle speed is not ignored when the value is invalid                       */

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
#define cb_HANDLE_SoSes_01                  5 /*cb_HANDLE_SOLAR_DATA_g*/
#define cb_HANDLE_RLSs_01_g                 6 /* cb_HANDLE_RAIN_LIGHT_DATA_g */
#define cb_HANDLE_FSdataEnhanced_g          7 /* cb_HANDLE_LIGHT_DATA_RAW_g*/
#define cb_HANDLE_FSs_01_g                  8 /* cb_HANDLE_CLIMATE_DATA_g*/
#define cb_HANDLE_ERROR_DATA_RLS_g          9
#define cb_HANDLE_LinReqCmd_g               10
#define cb_HANDLE_WWSs_01_g                 11 /* cb_HANDLE_SENS_CONFIG_DATA_g*/
#define cb_HANDLE_BCM1_LIN1_01_g            12 /*cb_HANDLE_VEH_DATA_g*/

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
  canbittype                   VALUE_SOLAR_RIGHT_SENS: 8;
  canbittype                    VALUE_SOLAR_LEFT_SENS: 8;
} _c_SOLAR_DATA_msgType;

typedef struct {
  canbittype                              WIPER_SPEED: 4;
  canbittype                         STATUS_RAIN_SENS: 4;
  canbittype                      LIGHT_SWITCH_REASON: 8;
  canbittype                           VALUE_HUD_SENS: 8;
  canbittype                                  unused0: 8;
  canbittype                     LIGHT_SWITCH_REQUEST: 2;
  canbittype                        STATUS_LIGHT_SENS: 2;
  canbittype                             SIGNAL_ERROR: 2;
  canbittype                                  unused1: 2;
  canbittype                                  unused2: 8;
  canbittype                                  unused3: 8;
  canbittype                                  unused4: 7;
  canbittype                               COMM_ERROR: 1;
} _c_RAIN_LIGHT_DATA_msgType;

typedef struct {
  canbittype                      VALUE_LIGHT_AMBIENT: 8;
  canbittype                        VALUE_LIGHT_FRONT: 8;
} _c_LIGHT_DATA_RAW_msgType;

typedef struct {
  canbittype                      WINDSHIELD_HUMIDITY: 8;
  canbittype                   WINDSHIELD_TEMPERATURE: 8;
} _c_CLIMATE_DATA_msgType;

typedef struct {
  canbittype                  ERR_STATE_CAL_RAIN_SENS: 2;
  canbittype                      ERR_STATE_RAIN_SENS: 2;
  canbittype                         ERR_STATE_CODING: 2;
  canbittype                     ERR_STATE_LIGHT_SENS: 2;
  canbittype                       ERR_STATE_SOL_SENS: 2;
  canbittype                       ERR_STATE_HUM_SENS: 2;
  canbittype                      ERR_STATE_OVER_TEMP: 2;
  canbittype                      ERR_STATE_OVER_VOLT: 2;
} _c_ERROR_DATA_RLS_msgType;


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
  canbittype                              SCREEN_TYPE: 3;
  canbittype                                 VEH_TYPE: 3;
  canbittype                           STEER_WHL_TYPE: 2;
  canbittype                               WIPER_TYPE: 2;
  canbittype                           RAIN_FUNC_ACTV: 2;
  canbittype                      HUM_SENS_CORRECTION: 2;
  canbittype                              SPEED_LIGHT: 2;
  canbittype                        LIGHT_SENSITIVITY: 3;
  canbittype                                  unused0: 5;
  canbittype                                  unused1: 8;
  canbittype                                  unused2: 8;
  canbittype                                  unused3: 8;
  canbittype                                  unused4: 8;
  canbittype                                  unused5: 8;
} _c_SENS_CONFIG_DATA_msgType;

typedef struct {
  canbittype                            WIPER_CONTROL: 8;
  canbittype                                  unused0: 4;
  canbittype                           WIPER_POSITION: 4;
  canbittype                           STATE_IGNITION: 4;
  canbittype                                  unused1: 2;
  canbittype                        STATUS_HUD_SENSOR: 2;
  canbittype                                  TEMP_EX: 8;
  canbittype                              VEH_SPEED_0: 8;
  canbittype                              VEH_SPEED_1: 4;
  canbittype                                  unused2: 4;
  canbittype                         RAIN_SENSITIVITY: 4;
  canbittype                                  unused3: 4;
  canbittype                                  unused4: 8;
} _c_VEH_DATA_msgType;


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
    _c_SOLAR_DATA_msgType solar_data;
} _c_SOLAR_DATA_buf;

typedef union {
    unsigned char _c[8];
    _c_RAIN_LIGHT_DATA_msgType rain_light_data;
} _c_RAIN_LIGHT_DATA_buf;

typedef union {
    unsigned char _c[2];
    _c_LIGHT_DATA_RAW_msgType light_data_raw;
} _c_LIGHT_DATA_RAW_buf;

typedef union {
    unsigned char _c[2];
    _c_CLIMATE_DATA_msgType climate_data;
} _c_CLIMATE_DATA_buf;

typedef union {
    unsigned char _c[2];
    _c_ERROR_DATA_RLS_msgType error_data_rls;
} _c_ERROR_DATA_RLS_buf;


/* Receive messages */

typedef union {
    unsigned char _c[8];
    _c_LinReqCmd_msgType linreqcmd;
} _c_LinReqCmd_buf;

typedef union {
    unsigned char _c[8];
    _c_SENS_CONFIG_DATA_msgType sens_config_data;
} _c_SENS_CONFIG_DATA_buf;

typedef union {
    unsigned char _c[8];
    _c_VEH_DATA_msgType veh_data;
} _c_VEH_DATA_buf;


/******************************************************************************/
/*                          Databuffer for send objects                       */
/******************************************************************************/

extern MEMORY_FAR _c_LinRespCmd_buf LinRespCmd;
extern MEMORY_FAR _c_ASIC_Frame_04_buf ASIC_Frame_04;
extern MEMORY_FAR _c_ASIC_Frame_03_buf ASIC_Frame_03;
extern MEMORY_FAR _c_ASIC_Frame_02_buf ASIC_Frame_02;
extern MEMORY_FAR _c_ASIC_Frame_01_buf ASIC_Frame_01;
extern MEMORY_FAR _c_SOLAR_DATA_buf SOLAR_DATA;
extern MEMORY_FAR _c_RAIN_LIGHT_DATA_buf RAIN_LIGHT_DATA;
extern MEMORY_FAR _c_LIGHT_DATA_RAW_buf LIGHT_DATA_RAW;
extern MEMORY_FAR _c_CLIMATE_DATA_buf CLIMATE_DATA;
extern MEMORY_FAR _c_ERROR_DATA_RLS_buf ERROR_DATA_RLS;

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
#define SOLAR_DATA_conf_b             uLinConfirmationFlags.w[0].b5
#define l_flg_tst_SOLAR_DATA()       (SOLAR_DATA_conf_b != 0)
#define l_flg_clr_SOLAR_DATA()       {SOLAR_DATA_conf_b = 0;}
#define RAIN_LIGHT_DATA_conf_b             uLinConfirmationFlags.w[0].b6
#define l_flg_tst_RAIN_LIGHT_DATA()       (RAIN_LIGHT_DATA_conf_b != 0)
#define l_flg_clr_RAIN_LIGHT_DATA()       {RAIN_LIGHT_DATA_conf_b = 0;}
#define LIGHT_DATA_RAW_conf_b             uLinConfirmationFlags.w[0].b7
#define l_flg_tst_LIGHT_DATA_RAW()       (LIGHT_DATA_RAW_conf_b != 0)
#define l_flg_clr_LIGHT_DATA_RAW()       {LIGHT_DATA_RAW_conf_b = 0;}
#define CLIMATE_DATA_conf_b             uLinConfirmationFlags.w[0].b8
#define l_flg_tst_CLIMATE_DATA()       (CLIMATE_DATA_conf_b != 0)
#define l_flg_clr_CLIMATE_DATA()       {CLIMATE_DATA_conf_b = 0;}
#define ERROR_DATA_RLS_conf_b             uLinConfirmationFlags.w[0].b9
#define l_flg_tst_ERROR_DATA_RLS()       (ERROR_DATA_RLS_conf_b != 0)
#define l_flg_clr_ERROR_DATA_RLS()       {ERROR_DATA_RLS_conf_b = 0;}

/******************************************************************************/
/*                         Databuffer for receive objects                     */
/******************************************************************************/

extern MEMORY_FAR _c_LinReqCmd_buf LinReqCmd;
extern MEMORY_FAR _c_SENS_CONFIG_DATA_buf SENS_CONFIG_DATA;
extern MEMORY_FAR _c_VEH_DATA_buf VEH_DATA;

/******************************************************************************/
/*                          Databuffer for indicationflags                    */
/******************************************************************************/

#define LinReqCmd_ind_b             uLinIndicationFlags.w[0].b0
#define l_flg_tst_LinReqCmd()       (LinReqCmd_ind_b != 0)
#define l_flg_clr_LinReqCmd()       {LinReqCmd_ind_b = 0;}
#define SENS_CONFIG_DATA_ind_b             uLinIndicationFlags.w[0].b1
#define l_flg_tst_SENS_CONFIG_DATA()       (SENS_CONFIG_DATA_ind_b != 0)
#define l_flg_clr_SENS_CONFIG_DATA()       {SENS_CONFIG_DATA_ind_b = 0;}
#define VEH_DATA_ind_b             uLinIndicationFlags.w[0].b2
#define l_flg_tst_VEH_DATA()       (VEH_DATA_ind_b != 0)
#define l_flg_clr_VEH_DATA()       {VEH_DATA_ind_b = 0;}

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
#define VALUE_SOLAR_RIGHT_SENS                                                SOLAR_DATA.solar_data.VALUE_SOLAR_RIGHT_SENS
#define VALUE_SOLAR_LEFT_SENS                                                 SOLAR_DATA.solar_data.VALUE_SOLAR_LEFT_SENS
#define WIPER_SPEED                                                           RAIN_LIGHT_DATA.rain_light_data.WIPER_SPEED
#define STATUS_RAIN_SENS                                                      RAIN_LIGHT_DATA.rain_light_data.STATUS_RAIN_SENS
#define LIGHT_SWITCH_REASON                                                   RAIN_LIGHT_DATA.rain_light_data.LIGHT_SWITCH_REASON
#define VALUE_HUD_SENS                                                        RAIN_LIGHT_DATA.rain_light_data.VALUE_HUD_SENS
#define LIGHT_SWITCH_REQUEST                                                  RAIN_LIGHT_DATA.rain_light_data.LIGHT_SWITCH_REQUEST
#define STATUS_LIGHT_SENS                                                     RAIN_LIGHT_DATA.rain_light_data.STATUS_LIGHT_SENS
#define SIGNAL_ERROR                                                          RAIN_LIGHT_DATA.rain_light_data.SIGNAL_ERROR
#define COMM_ERROR                                                            RAIN_LIGHT_DATA.rain_light_data.COMM_ERROR
#define VALUE_LIGHT_AMBIENT                                                   LIGHT_DATA_RAW.light_data_raw.VALUE_LIGHT_AMBIENT
#define VALUE_LIGHT_FRONT                                                     LIGHT_DATA_RAW.light_data_raw.VALUE_LIGHT_FRONT
#define WINDSHIELD_HUMIDITY                                                   CLIMATE_DATA.climate_data.WINDSHIELD_HUMIDITY
#define WINDSHIELD_TEMPERATURE                                                CLIMATE_DATA.climate_data.WINDSHIELD_TEMPERATURE
#define ERR_STATE_CAL_RAIN_SENS                                               ERROR_DATA_RLS.error_data_rls.ERR_STATE_CAL_RAIN_SENS
#define ERR_STATE_RAIN_SENS                                                   ERROR_DATA_RLS.error_data_rls.ERR_STATE_RAIN_SENS
#define ERR_STATE_CODING                                                      ERROR_DATA_RLS.error_data_rls.ERR_STATE_CODING
#define ERR_STATE_LIGHT_SENS                                                  ERROR_DATA_RLS.error_data_rls.ERR_STATE_LIGHT_SENS
#define ERR_STATE_SOL_SENS                                                    ERROR_DATA_RLS.error_data_rls.ERR_STATE_SOL_SENS
#define ERR_STATE_HUM_SENS                                                    ERROR_DATA_RLS.error_data_rls.ERR_STATE_HUM_SENS
#define ERR_STATE_OVER_TEMP                                                   ERROR_DATA_RLS.error_data_rls.ERR_STATE_OVER_TEMP
#define ERR_STATE_OVER_VOLT                                                   ERROR_DATA_RLS.error_data_rls.ERR_STATE_OVER_VOLT
#define MasterReqB0                                                           LinReqCmd.linreqcmd.MasterReqB0
#define MasterReqB1                                                           LinReqCmd.linreqcmd.MasterReqB1
#define MasterReqB2                                                           LinReqCmd.linreqcmd.MasterReqB2
#define MasterReqB3                                                           LinReqCmd.linreqcmd.MasterReqB3
#define MasterReqB4                                                           LinReqCmd.linreqcmd.MasterReqB4
#define MasterReqB5                                                           LinReqCmd.linreqcmd.MasterReqB5
#define MasterReqB6                                                           LinReqCmd.linreqcmd.MasterReqB6
#define MasterReqB7                                                           LinReqCmd.linreqcmd.MasterReqB7
#define SCREEN_TYPE                                                           SENS_CONFIG_DATA.sens_config_data.SCREEN_TYPE
#define VEH_TYPE                                                              SENS_CONFIG_DATA.sens_config_data.VEH_TYPE
#define STEER_WHL_TYPE                                                        SENS_CONFIG_DATA.sens_config_data.STEER_WHL_TYPE
#define WIPER_TYPE                                                            SENS_CONFIG_DATA.sens_config_data.WIPER_TYPE
#define RAIN_FUNC_ACTV                                                        SENS_CONFIG_DATA.sens_config_data.RAIN_FUNC_ACTV
#define HUM_SENS_CORRECTION                                                   SENS_CONFIG_DATA.sens_config_data.HUM_SENS_CORRECTION
#define SPEED_LIGHT                                                           SENS_CONFIG_DATA.sens_config_data.SPEED_LIGHT
#define LIGHT_SENSITIVITY                                                     SENS_CONFIG_DATA.sens_config_data.LIGHT_SENSITIVITY
#define WIPER_CONTROL                                                         VEH_DATA.veh_data.WIPER_CONTROL
#define WIPER_POSITION                                                        VEH_DATA.veh_data.WIPER_POSITION
#define STATE_IGNITION                                                        VEH_DATA.veh_data.STATE_IGNITION
#define STATUS_HUD_SENSOR                                                     VEH_DATA.veh_data.STATUS_HUD_SENSOR
#define TEMP_EX                                                               VEH_DATA.veh_data.TEMP_EX
#define VEH_SPEED_0                                                           VEH_DATA.veh_data.VEH_SPEED_0
#define VEH_SPEED_1                                                           VEH_DATA.veh_data.VEH_SPEED_1
#define VEH_SPEED(c)                                                          { VEH_SPEED_0= (uint8)(((uint16)(c) & 0xFF));\
                                                                                VEH_SPEED_1= (uint8)(((uint16)(c) & 0x0F) >> 8);\
                                                                              }
#define RAIN_SENSITIVITY                                                      VEH_DATA.veh_data.RAIN_SENSITIVITY
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
#define l_u8_rd_VALUE_SOLAR_RIGHT_SENS()                                    VALUE_SOLAR_RIGHT_SENS
#define l_u8_wr_VALUE_SOLAR_RIGHT_SENS(a)                                   {VALUE_SOLAR_RIGHT_SENS = a;}
#define l_u8_rd_VALUE_SOLAR_LEFT_SENS()                                     VALUE_SOLAR_LEFT_SENS
#define l_u8_wr_VALUE_SOLAR_LEFT_SENS(a)                                    {VALUE_SOLAR_LEFT_SENS = a;}
#define l_u8_rd_WIPER_SPEED()                                               WIPER_SPEED
#define l_u8_wr_WIPER_SPEED(a)                                              {WIPER_SPEED = a;}
#define l_u8_rd_STATUS_RAIN_SENS()                                          STATUS_RAIN_SENS
#define l_u8_wr_STATUS_RAIN_SENS(a)                                         {STATUS_RAIN_SENS = a;}
#define l_u8_rd_LIGHT_SWITCH_REASON()                                       LIGHT_SWITCH_REASON
#define l_u8_wr_LIGHT_SWITCH_REASON(a)                                      {LIGHT_SWITCH_REASON = a;}
#define l_u8_rd_VALUE_HUD_SENS()                                            VALUE_HUD_SENS
#define l_u8_wr_VALUE_HUD_SENS(a)                                           {VALUE_HUD_SENS = a;}
#define l_u8_rd_LIGHT_SWITCH_REQUEST()                                      LIGHT_SWITCH_REQUEST
#define l_u8_wr_LIGHT_SWITCH_REQUEST(a)                                     {LIGHT_SWITCH_REQUEST = a;}
#define l_u8_rd_STATUS_LIGHT_SENS()                                         STATUS_LIGHT_SENS
#define l_u8_wr_STATUS_LIGHT_SENS(a)                                        {STATUS_LIGHT_SENS = a;}
#define l_u8_rd_SIGNAL_ERROR()                                              SIGNAL_ERROR
#define l_u8_wr_SIGNAL_ERROR(a)                                             {SIGNAL_ERROR = a;}
#define l_bool_rd_COMM_ERROR()                                                  COMM_ERROR
#define l_bool_wr_COMM_ERROR(a)                                                 {COMM_ERROR = a;}
#define l_u8_rd_VALUE_LIGHT_AMBIENT()                                       VALUE_LIGHT_AMBIENT
#define l_u8_wr_VALUE_LIGHT_AMBIENT(a)                                      {VALUE_LIGHT_AMBIENT = a;}
#define l_u8_rd_VALUE_LIGHT_FRONT()                                         VALUE_LIGHT_FRONT
#define l_u8_wr_VALUE_LIGHT_FRONT(a)                                        {VALUE_LIGHT_FRONT = a;}
#define l_u8_rd_WINDSHIELD_HUMIDITY()                                       WINDSHIELD_HUMIDITY
#define l_u8_wr_WINDSHIELD_HUMIDITY(a)                                      {WINDSHIELD_HUMIDITY = a;}
#define l_u8_rd_WINDSHIELD_TEMPERATURE()                                    WINDSHIELD_TEMPERATURE
#define l_u8_wr_WINDSHIELD_TEMPERATURE(a)                                   {WINDSHIELD_TEMPERATURE = a;}
#define l_u8_rd_ERR_STATE_CAL_RAIN_SENS()                                   ERR_STATE_CAL_RAIN_SENS
#define l_u8_wr_ERR_STATE_CAL_RAIN_SENS(a)                                  {ERR_STATE_CAL_RAIN_SENS = a;}
#define l_u8_rd_ERR_STATE_RAIN_SENS()                                       ERR_STATE_RAIN_SENS
#define l_u8_wr_ERR_STATE_RAIN_SENS(a)                                      {ERR_STATE_RAIN_SENS = a;}
#define l_u8_rd_ERR_STATE_CODING()                                          ERR_STATE_CODING
#define l_u8_wr_ERR_STATE_CODING(a)                                         {ERR_STATE_CODING = a;}
#define l_u8_rd_ERR_STATE_LIGHT_SENS()                                      ERR_STATE_LIGHT_SENS
#define l_u8_wr_ERR_STATE_LIGHT_SENS(a)                                     {ERR_STATE_LIGHT_SENS = a;}
#define l_u8_rd_ERR_STATE_SOL_SENS()                                        ERR_STATE_SOL_SENS
#define l_u8_wr_ERR_STATE_SOL_SENS(a)                                       {ERR_STATE_SOL_SENS = a;}
#define l_u8_rd_ERR_STATE_HUM_SENS()                                        ERR_STATE_HUM_SENS
#define l_u8_wr_ERR_STATE_HUM_SENS(a)                                       {ERR_STATE_HUM_SENS = a;}
#define l_u8_rd_ERR_STATE_OVER_TEMP()                                       ERR_STATE_OVER_TEMP
#define l_u8_wr_ERR_STATE_OVER_TEMP(a)                                      {ERR_STATE_OVER_TEMP = a;}
#define l_u8_rd_ERR_STATE_OVER_VOLT()                                       ERR_STATE_OVER_VOLT
#define l_u8_wr_ERR_STATE_OVER_VOLT(a)                                      {ERR_STATE_OVER_VOLT = a;}
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
#define l_u8_rd_SCREEN_TYPE()                                               SCREEN_TYPE
#define l_u8_wr_SCREEN_TYPE(a)                                              {SCREEN_TYPE = a;}
#define l_u8_rd_VEH_TYPE()                                                  VEH_TYPE
#define l_u8_wr_VEH_TYPE(a)                                                 {VEH_TYPE = a;}
#define l_u8_rd_STEER_WHL_TYPE()                                            STEER_WHL_TYPE
#define l_u8_wr_STEER_WHL_TYPE(a)                                           {STEER_WHL_TYPE = a;}
#define l_u8_rd_WIPER_TYPE()                                                WIPER_TYPE
#define l_u8_wr_WIPER_TYPE(a)                                               {WIPER_TYPE = a;}
#define l_u8_rd_RAIN_FUNC_ACTV()                                            RAIN_FUNC_ACTV
#define l_u8_wr_RAIN_FUNC_ACTV(a)                                           {RAIN_FUNC_ACTV = a;}
#define l_u8_rd_HUM_SENS_CORRECTION()                                       HUM_SENS_CORRECTION
#define l_u8_wr_HUM_SENS_CORRECTION(a)                                      {HUM_SENS_CORRECTION = a;}
#define l_u8_rd_SPEED_LIGHT()                                               SPEED_LIGHT
#define l_u8_wr_SPEED_LIGHT(a)                                              {SPEED_LIGHT = a;}
#define l_u8_rd_LIGHT_SENSITIVITY()                                         LIGHT_SENSITIVITY
#define l_u8_wr_LIGHT_SENSITIVITY(a)                                        {LIGHT_SENSITIVITY = a;}
#define l_u8_rd_WIPER_CONTROL()                                             WIPER_CONTROL
#define l_u8_wr_WIPER_CONTROL(a)                                            {WIPER_CONTROL = a;}
#define l_u8_rd_WIPER_POSITION()                                            WIPER_POSITION
#define l_u8_wr_WIPER_POSITION(a)                                           {WIPER_POSITION = a;}
#define l_u8_rd_STATE_IGNITION()                                            STATE_IGNITION
#define l_u8_wr_STATE_IGNITION(a)                                           {STATE_IGNITION = a;}
#define l_u8_rd_STATUS_HUD_SENSOR()                                         STATUS_HUD_SENSOR
#define l_u8_wr_STATUS_HUD_SENSOR(a)                                        {STATUS_HUD_SENSOR = a;}
#define l_u8_rd_TEMP_EX()                                                   TEMP_EX
#define l_u8_wr_TEMP_EX(a)                                                  {TEMP_EX = a;}
#define l_u16_rd_VEH_SPEED()                                                  ((canuint16)(VEH_SPEED_0)\
                                                                                | (((canuint16)VEH_SPEED_1)<<8))
#define l_u16_wr_VEH_SPEED(a)                                                 {VEH_SPEED_0 = ((canuint8)a);\
                                                                                 VEH_SPEED_1 = ((canuint8)a>>8);}
#define l_u8_rd_RAIN_SENSITIVITY()                                          RAIN_SENSITIVITY
#define l_u8_wr_RAIN_SENSITIVITY(a)                                         {RAIN_SENSITIVITY = a;}


#endif  /* I_LIN_RLS_H */
