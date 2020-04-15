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
#define cb_HANDLE_RLS_LIN_3               5
#define cb_HANDLE_RLS_LIN_2               6
#define cb_HANDLE_RLS_LIN_1               7
#define cb_HANDLE_LinReqCmd               8
#define cb_HANDLE_BCM_LIN_2               9
#define cb_HANDLE_BCM_LIN_1               10

/*************The re-mapping is defined by Blake_LI 2018_12_24*****************/

#define cb_HANDLE_LinRespCmd_g        cb_HANDLE_LinRespCmd                 /******  0   RLS output******/
#define cb_HANDLE_ASIC_Frame_04_g     cb_HANDLE_ASIC_Frame_04              /*****   1   RLS output******/
#define cb_HANDLE_ASIC_Frame_03_g     cb_HANDLE_ASIC_Frame_03              /*****   2   RLS output******/
#define cb_HANDLE_ASIC_Frame_02_g     cb_HANDLE_ASIC_Frame_02              /*****   3   RLS output******/
#define cb_HANDLE_ASIC_Frame_01_g     cb_HANDLE_ASIC_Frame_01              /*****   4   RLS output******/
#define cb_HANDLE_SoSes_01            cb_HANDLE_RLS_LIN_3                  /*****   5   RLS output******/
#define cb_HANDLE_FSs_01_g            cb_HANDLE_RLS_LIN_2                  /*****   6   RLS output******/
#define cb_HANDLE_RLSs_01_g           cb_HANDLE_RLS_LIN_1                  /*****   7   RLS output******/ 

#define cb_HANDLE_LinReqCmd_g         cb_HANDLE_LinReqCmd                  /******  8   RLS Input*******/
#define cb_HANDLE_WWSs_01_g           cb_HANDLE_BCM_LIN_2                  /*****   10  RLS Input*******/
#define cb_HANDLE_BCM1_LIN1_01_g      cb_HANDLE_BCM_LIN_1                  /*****   11  RLS Input*******/

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
  canbittype                                  unused0: 8;
  canbittype                                  unused1: 8;
  canbittype                           RLS_SupplierID: 4;
  canbittype                 RLS_Close_window_command: 2;
  canbittype                           RLS_Rain_error: 2;
  canbittype                      RLS_Parameter_group: 3;
  canbittype                          RLS_Wiper_speed: 3;
  canbittype                   RLS_Solar_sensor_error: 2;
  canbittype                           RLS_Open_light: 2;
  canbittype                          RLS_Light_error: 2;
  canbittype                                  unused2: 2;
  canbittype                        RLS_Voltage_error: 2;
  canbittype                RLS_Humidity_sensor_error: 2;
  canbittype                                  unused3: 6;
  canbittype                                  unused4: 8;
  canbittype                                  unused5: 7;
  canbittype              RLS_LIN_communication_error: 1;
} _c_RLS_LIN_3_msgType;

typedef struct {
  canbittype                            IR_Brightness: 8;
  canbittype                         AMB_Brightness_0: 8;
  canbittype                         AMB_Brightness_1: 2;
  canbittype                                  unused0: 6;
  canbittype                          FW_Brightness_0: 8;
  canbittype                          FW_Brightness_1: 2;
  canbittype                                  unused1: 6;
  canbittype                                  unused2: 8;
  canbittype                                  unused3: 8;
  canbittype                                  unused4: 8;
} _c_RLS_LIN_2_msgType;

typedef struct {
  canbittype                     RLS_relativeHumidity: 8;
  canbittype                       RLS_WindshieldTemp: 8;
  canbittype                           RLS_SolarRight: 8;
  canbittype                            RLS_SolarLeft: 8;
  canbittype                            RainfallLevel: 4;
  canbittype                                  unused0: 4;
  canbittype                                  unused1: 8;
  canbittype                                  unused2: 8;
  canbittype                                  unused3: 8;
} _c_RLS_LIN_1_msgType;


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
  canbittype                        BCM_Wiper_control: 3;
  canbittype                       BCM_Wiper_position: 2;
  canbittype                                 BCM_Wash: 2;
  canbittype                                  unused0: 1;
  canbittype                       BCM_VehicleSpeed_0: 8;
  canbittype                       BCM_VehicleSpeed_1: 4;
  canbittype                            BCM_IGNStatus: 2;
  canbittype                                  unused1: 2;
  canbittype                     BCM_Rain_sensitivity: 4;
  canbittype                      BCM_Standby_request: 2;
  canbittype                                  unused2: 2;
  canbittype                                  unused3: 8;
  canbittype                                  unused4: 8;
  canbittype                                BCM_550nm: 8;
  canbittype                                BCM_880nm: 8;
} _c_BCM_LIN_2_msgType;

typedef struct {
  canbittype                        BCM_Position_lamp: 2;
  canbittype           BCM_Turn_left_rear_lamp_status: 2;
  canbittype          BCM_Turn_right_rear_lamp_status: 2;
  canbittype                        BCM_Stream_enable: 2;
  canbittype                 BCM_Break_lamp_highlight: 2;
  canbittype                   BCM_Backup_lamp_status: 2;
  canbittype                 BCM_Courtesy_lamp_status: 2;
  canbittype                                  unused0: 2;
  canbittype                         BCM_Vehicle_type: 8;
  canbittype                                  unused1: 8;
  canbittype                                  unused2: 8;
  canbittype                                  unused3: 8;
  canbittype                                  unused4: 8;
  canbittype                                  unused5: 8;
} _c_BCM_LIN_1_msgType;


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
    _c_RLS_LIN_3_msgType rls_lin_3;
} _c_RLS_LIN_3_buf;

typedef union {
    unsigned char _c[5];
    _c_RLS_LIN_2_msgType rls_lin_2;
} _c_RLS_LIN_2_buf;

typedef union {
    unsigned char _c[5];
    _c_RLS_LIN_1_msgType rls_lin_1;
} _c_RLS_LIN_1_buf;


/* Receive messages */

typedef union {
    unsigned char _c[8];
    _c_LinReqCmd_msgType linreqcmd;
} _c_LinReqCmd_buf;

typedef union {
    unsigned char _c[8];
    _c_BCM_LIN_2_msgType bcm_lin_2;
} _c_BCM_LIN_2_buf;

typedef union {
    unsigned char _c[8];
    _c_BCM_LIN_1_msgType bcm_lin_1;
} _c_BCM_LIN_1_buf;


/******************************************************************************/
/*                          Databuffer for send objects                       */
/******************************************************************************/

extern MEMORY_FAR _c_LinRespCmd_buf LinRespCmd;
extern MEMORY_FAR _c_ASIC_Frame_04_buf ASIC_Frame_04;
extern MEMORY_FAR _c_ASIC_Frame_03_buf ASIC_Frame_03;
extern MEMORY_FAR _c_ASIC_Frame_02_buf ASIC_Frame_02;
extern MEMORY_FAR _c_ASIC_Frame_01_buf ASIC_Frame_01;
extern MEMORY_FAR _c_RLS_LIN_3_buf RLS_LIN_3;
extern MEMORY_FAR _c_RLS_LIN_2_buf RLS_LIN_2;
extern MEMORY_FAR _c_RLS_LIN_1_buf RLS_LIN_1;

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
#define RLS_LIN_3_conf_b             uLinConfirmationFlags.w[0].b5
#define l_flg_tst_RLS_LIN_3()       (RLS_LIN_3_conf_b != 0)
#define l_flg_clr_RLS_LIN_3()       {RLS_LIN_3_conf_b = 0;}
#define RLS_LIN_2_conf_b             uLinConfirmationFlags.w[0].b6
#define l_flg_tst_RLS_LIN_2()       (RLS_LIN_2_conf_b != 0)
#define l_flg_clr_RLS_LIN_2()       {RLS_LIN_2_conf_b = 0;}
#define RLS_LIN_1_conf_b             uLinConfirmationFlags.w[0].b7
#define l_flg_tst_RLS_LIN_1()       (RLS_LIN_1_conf_b != 0)
#define l_flg_clr_RLS_LIN_1()       {RLS_LIN_1_conf_b = 0;}

/******************************************************************************/
/*                         Databuffer for receive objects                     */
/******************************************************************************/

extern MEMORY_FAR _c_LinReqCmd_buf LinReqCmd;
extern MEMORY_FAR _c_BCM_LIN_2_buf BCM_LIN_2;
extern MEMORY_FAR _c_BCM_LIN_1_buf BCM_LIN_1;

/******************************************************************************/
/*                          Databuffer for indicationflags                    */
/******************************************************************************/

#define LinReqCmd_ind_b             uLinIndicationFlags.w[0].b0
#define l_flg_tst_LinReqCmd()       (LinReqCmd_ind_b != 0)
#define l_flg_clr_LinReqCmd()       {LinReqCmd_ind_b = 0;}
#define BCM_LIN_2_ind_b             uLinIndicationFlags.w[0].b1
#define l_flg_tst_BCM_LIN_2()       (BCM_LIN_2_ind_b != 0)
#define l_flg_clr_BCM_LIN_2()       {BCM_LIN_2_ind_b = 0;}
#define BCM_LIN_1_ind_b             uLinIndicationFlags.w[0].b2
#define l_flg_tst_BCM_LIN_1()       (BCM_LIN_1_ind_b != 0)
#define l_flg_clr_BCM_LIN_1()       {BCM_LIN_1_ind_b = 0;}

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
#define RLS_SupplierID                                                        RLS_LIN_3.rls_lin_3.RLS_SupplierID
#define RLS_Close_window_command                                              RLS_LIN_3.rls_lin_3.RLS_Close_window_command
#define RLS_Rain_error                                                        RLS_LIN_3.rls_lin_3.RLS_Rain_error
#define RLS_Parameter_group                                                   RLS_LIN_3.rls_lin_3.RLS_Parameter_group
#define RLS_Wiper_speed                                                       RLS_LIN_3.rls_lin_3.RLS_Wiper_speed
#define RLS_Solar_sensor_error                                                RLS_LIN_3.rls_lin_3.RLS_Solar_sensor_error
#define RLS_Open_light                                                        RLS_LIN_3.rls_lin_3.RLS_Open_light
#define RLS_Light_error                                                       RLS_LIN_3.rls_lin_3.RLS_Light_error
#define RLS_Voltage_error                                                     RLS_LIN_3.rls_lin_3.RLS_Voltage_error
#define RLS_Humidity_sensor_error                                             RLS_LIN_3.rls_lin_3.RLS_Humidity_sensor_error
#define RLS_LIN_communication_error                                           RLS_LIN_3.rls_lin_3.RLS_LIN_communication_error
#define IR_Brightness                                                         RLS_LIN_2.rls_lin_2.IR_Brightness
#define AMB_Brightness_0                                                      RLS_LIN_2.rls_lin_2.AMB_Brightness_0
#define AMB_Brightness_1                                                      RLS_LIN_2.rls_lin_2.AMB_Brightness_1
#define AMB_Brightness(c)                                                     { AMB_Brightness_0= (uint8)(((uint16)(c) & 0xFF));\
                                                                                AMB_Brightness_1= (uint8)(((uint16)(c) & 0x03) >> 8);\
                                                                              }
#define FW_Brightness_0                                                       RLS_LIN_2.rls_lin_2.FW_Brightness_0
#define FW_Brightness_1                                                       RLS_LIN_2.rls_lin_2.FW_Brightness_1
#define FW_Brightness(c)                                                      { FW_Brightness_0= (uint8)(((uint16)(c) & 0xFF));\
                                                                                FW_Brightness_1= (uint8)(((uint16)(c) & 0x03) >> 8);\
                                                                              }
#define RLS_relativeHumidity                                                  RLS_LIN_1.rls_lin_1.RLS_relativeHumidity
#define RLS_WindshieldTemp                                                    RLS_LIN_1.rls_lin_1.RLS_WindshieldTemp
#define RLS_SolarRight                                                        RLS_LIN_1.rls_lin_1.RLS_SolarRight
#define RLS_SolarLeft                                                         RLS_LIN_1.rls_lin_1.RLS_SolarLeft
#define RainfallLevel                                                         RLS_LIN_1.rls_lin_1.RainfallLevel
#define MasterReqB0                                                           LinReqCmd.linreqcmd.MasterReqB0
#define MasterReqB1                                                           LinReqCmd.linreqcmd.MasterReqB1
#define MasterReqB2                                                           LinReqCmd.linreqcmd.MasterReqB2
#define MasterReqB3                                                           LinReqCmd.linreqcmd.MasterReqB3
#define MasterReqB4                                                           LinReqCmd.linreqcmd.MasterReqB4
#define MasterReqB5                                                           LinReqCmd.linreqcmd.MasterReqB5
#define MasterReqB6                                                           LinReqCmd.linreqcmd.MasterReqB6
#define MasterReqB7                                                           LinReqCmd.linreqcmd.MasterReqB7
#define BCM_Wiper_control                                                     BCM_LIN_2.bcm_lin_2.BCM_Wiper_control
#define BCM_Wiper_position                                                    BCM_LIN_2.bcm_lin_2.BCM_Wiper_position
#define BCM_Wash                                                              BCM_LIN_2.bcm_lin_2.BCM_Wash
#define BCM_VehicleSpeed_0                                                    BCM_LIN_2.bcm_lin_2.BCM_VehicleSpeed_0
#define BCM_VehicleSpeed_1                                                    BCM_LIN_2.bcm_lin_2.BCM_VehicleSpeed_1
#define BCM_VehicleSpeed(c)                                                   { BCM_VehicleSpeed_0= (uint8)(((uint16)(c) & 0xFF));\
                                                                                BCM_VehicleSpeed_1= (uint8)(((uint16)(c) & 0x0F) >> 8);\
                                                                              }
#define BCM_IGNStatus                                                         BCM_LIN_2.bcm_lin_2.BCM_IGNStatus
#define BCM_Rain_sensitivity                                                  BCM_LIN_2.bcm_lin_2.BCM_Rain_sensitivity
#define BCM_Standby_request                                                   BCM_LIN_2.bcm_lin_2.BCM_Standby_request
#define BCM_550nm                                                             BCM_LIN_2.bcm_lin_2.BCM_550nm
#define BCM_880nm                                                             BCM_LIN_2.bcm_lin_2.BCM_880nm
#define BCM_Position_lamp                                                     BCM_LIN_1.bcm_lin_1.BCM_Position_lamp
#define BCM_Turn_left_rear_lamp_status                                        BCM_LIN_1.bcm_lin_1.BCM_Turn_left_rear_lamp_status
#define BCM_Turn_right_rear_lamp_status                                       BCM_LIN_1.bcm_lin_1.BCM_Turn_right_rear_lamp_status
#define BCM_Stream_enable                                                     BCM_LIN_1.bcm_lin_1.BCM_Stream_enable
#define BCM_Break_lamp_highlight                                              BCM_LIN_1.bcm_lin_1.BCM_Break_lamp_highlight
#define BCM_Backup_lamp_status                                                BCM_LIN_1.bcm_lin_1.BCM_Backup_lamp_status
#define BCM_Courtesy_lamp_status                                              BCM_LIN_1.bcm_lin_1.BCM_Courtesy_lamp_status
#define BCM_Vehicle_type                                                      BCM_LIN_1.bcm_lin_1.BCM_Vehicle_type
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
#define l_u8_rd_RLS_SupplierID()                                            RLS_SupplierID
#define l_u8_wr_RLS_SupplierID(a)                                           {RLS_SupplierID = a;}
#define l_u8_rd_RLS_Close_window_command()                                  RLS_Close_window_command
#define l_u8_wr_RLS_Close_window_command(a)                                 {RLS_Close_window_command = a;}
#define l_u8_rd_RLS_Rain_error()                                            RLS_Rain_error
#define l_u8_wr_RLS_Rain_error(a)                                           {RLS_Rain_error = a;}
#define l_u8_rd_RLS_Parameter_group()                                       RLS_Parameter_group
#define l_u8_wr_RLS_Parameter_group(a)                                      {RLS_Parameter_group = a;}
#define l_u8_rd_RLS_Wiper_speed()                                           RLS_Wiper_speed
#define l_u8_wr_RLS_Wiper_speed(a)                                          {RLS_Wiper_speed = a;}
#define l_u8_rd_RLS_Solar_sensor_error()                                    RLS_Solar_sensor_error
#define l_u8_wr_RLS_Solar_sensor_error(a)                                   {RLS_Solar_sensor_error = a;}
#define l_u8_rd_RLS_Open_light()                                            RLS_Open_light
#define l_u8_wr_RLS_Open_light(a)                                           {RLS_Open_light = a;}
#define l_u8_rd_RLS_Light_error()                                           RLS_Light_error
#define l_u8_wr_RLS_Light_error(a)                                          {RLS_Light_error = a;}
#define l_u8_rd_RLS_Voltage_error()                                         RLS_Voltage_error
#define l_u8_wr_RLS_Voltage_error(a)                                        {RLS_Voltage_error = a;}
#define l_u8_rd_RLS_Humidity_sensor_error()                                 RLS_Humidity_sensor_error
#define l_u8_wr_RLS_Humidity_sensor_error(a)                                {RLS_Humidity_sensor_error = a;}
#define l_bool_rd_RLS_LIN_communication_error()                                 RLS_LIN_communication_error
#define l_bool_wr_RLS_LIN_communication_error(a)                                {RLS_LIN_communication_error = a;}
#define l_u8_rd_IR_Brightness()                                             IR_Brightness
#define l_u8_wr_IR_Brightness(a)                                            {IR_Brightness = a;}
#define l_u16_rd_AMB_Brightness()                                             ((canuint16)(AMB_Brightness_0)\
                                                                                | ((canuint16)(AMB_Brightness_1)<<8))
#define l_u16_wr_AMB_Brightness(a)                                            {AMB_Brightness_0 = (a & 0xff);\
                                                                                    AMB_Brightness_1 = ((a>>8) & 0x03);}
#define l_u16_rd_FW_Brightness()                                              ((canuint16)(FW_Brightness_0)\
                                                                                | ((canuint16)(FW_Brightness_1)<<8))
#define l_u16_wr_FW_Brightness(a)                                             {FW_Brightness_0 = (a & 0xff);\
                                                                                   FW_Brightness_1 = ((a>>8) & 0x03);}
#define l_u8_rd_RLS_relativeHumidity()                                      RLS_relativeHumidity
#define l_u8_wr_RLS_relativeHumidity(a)                                     {RLS_relativeHumidity = a;}
#define l_u8_rd_RLS_WindshieldTemp()                                        RLS_WindshieldTemp
#define l_u8_wr_RLS_WindshieldTemp(a)                                       {RLS_WindshieldTemp = a;}
#define l_u8_rd_RLS_SolarRight()                                            RLS_SolarRight
#define l_u8_wr_RLS_SolarRight(a)                                           {RLS_SolarRight = a;}
#define l_u8_rd_RLS_SolarLeft()                                             RLS_SolarLeft
#define l_u8_wr_RLS_SolarLeft(a)                                            {RLS_SolarLeft = a;}
#define l_u8_rd_RainfallLevel()                                             RainfallLevel
#define l_u8_wr_RainfallLevel(a)                                            {RainfallLevel = a;}
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
#define l_u8_rd_BCM_Wiper_control()                                         BCM_Wiper_control
#define l_u8_wr_BCM_Wiper_control(a)                                        {BCM_Wiper_control = a;}
#define l_u8_rd_BCM_Wiper_position()                                        BCM_Wiper_position
#define l_u8_wr_BCM_Wiper_position(a)                                       {BCM_Wiper_position = a;}
#define l_u8_rd_BCM_Wash()                                                  BCM_Wash
#define l_u8_wr_BCM_Wash(a)                                                 {BCM_Wash = a;}
#define l_u16_rd_BCM_VehicleSpeed()                                           ((canuint16)(BCM_VehicleSpeed_0)\
                                                                                | ((canuint16)(BCM_VehicleSpeed_1)<<8))
#define l_u16_wr_BCM_VehicleSpeed(a)                                          {BCM_VehicleSpeed_0 = ((canuint8)a);\
                                                                                 BCM_VehicleSpeed_1 = ((canuint8)a>>8);}
#define l_u8_rd_BCM_IGNStatus()                                             BCM_IGNStatus
#define l_u8_wr_BCM_IGNStatus(a)                                            {BCM_IGNStatus = a;}
#define l_u8_rd_BCM_Rain_sensitivity()                                      BCM_Rain_sensitivity
#define l_u8_wr_BCM_Rain_sensitivity(a)                                     {BCM_Rain_sensitivity = a;}
#define l_u8_rd_BCM_Standby_request()                                       BCM_Standby_request
#define l_u8_wr_BCM_Standby_request(a)                                      {BCM_Standby_request = a;}
#define l_u8_rd_BCM_550nm()                                                 BCM_550nm
#define l_u8_wr_BCM_550nm(a)                                                {BCM_550nm = a;}
#define l_u8_rd_BCM_880nm()                                                 BCM_880nm
#define l_u8_wr_BCM_880nm(a)                                                {BCM_880nm = a;}
#define l_u8_rd_BCM_Position_lamp()                                         BCM_Position_lamp
#define l_u8_wr_BCM_Position_lamp(a)                                        {BCM_Position_lamp = a;}
#define l_u8_rd_BCM_Turn_left_rear_lamp_status()                            BCM_Turn_left_rear_lamp_status
#define l_u8_wr_BCM_Turn_left_rear_lamp_status(a)                           {BCM_Turn_left_rear_lamp_status = a;}
#define l_u8_rd_BCM_Turn_right_rear_lamp_status()                           BCM_Turn_right_rear_lamp_status
#define l_u8_wr_BCM_Turn_right_rear_lamp_status(a)                          {BCM_Turn_right_rear_lamp_status = a;}
#define l_u8_rd_BCM_Stream_enable()                                         BCM_Stream_enable
#define l_u8_wr_BCM_Stream_enable(a)                                        {BCM_Stream_enable = a;}
#define l_u8_rd_BCM_Break_lamp_highlight()                                  BCM_Break_lamp_highlight
#define l_u8_wr_BCM_Break_lamp_highlight(a)                                 {BCM_Break_lamp_highlight = a;}
#define l_u8_rd_BCM_Backup_lamp_status()                                    BCM_Backup_lamp_status
#define l_u8_wr_BCM_Backup_lamp_status(a)                                   {BCM_Backup_lamp_status = a;}
#define l_u8_rd_BCM_Courtesy_lamp_status()                                  BCM_Courtesy_lamp_status
#define l_u8_wr_BCM_Courtesy_lamp_status(a)                                 {BCM_Courtesy_lamp_status = a;}
#define l_u8_rd_BCM_Vehicle_type()                                          BCM_Vehicle_type
#define l_u8_wr_BCM_Vehicle_type(a)                                         {BCM_Vehicle_type = a;}


#endif  /* I_LIN_RLS_H */

