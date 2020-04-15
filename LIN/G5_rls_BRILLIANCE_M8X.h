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
#define cb_HANDLE_RS_SENSOR_01            5
#define cb_HANDLE_LinReqCmd               6
#define cb_HANDLE_SCM_Information         7
#define cb_HANDLE_BCM_TransmissionWiper   8
#define cb_HANDLE_BCM_GENERAL_STATUS      9

#define cb_HANDLE_ASIC_Frame_01_g cb_HANDLE_ASIC_Frame_01
#define cb_HANDLE_ASIC_Frame_02_g cb_HANDLE_ASIC_Frame_02
#define cb_HANDLE_ASIC_Frame_03_g cb_HANDLE_ASIC_Frame_03
#define cb_HANDLE_ASIC_Frame_04_g cb_HANDLE_ASIC_Frame_04
#define cb_HANDLE_RLSs_01_g cb_HANDLE_RS_SENSOR_01
#define cb_HANDLE_BCM1_LIN1_01_g cb_HANDLE_BCM_GENERAL_STATUS
#define cb_HANDLE_WWSs_01_g cb_HANDLE_SCM_Information
#define cb_HANDLE_LinReqCmd_g  cb_HANDLE_LinReqCmd
#define cb_HANDLE_LinRespCmd_g cb_HANDLE_LinRespCmd
#define cb_HANDLE_TRANSMISSION_01_g cb_HANDLE_BCM_TransmissionWiper

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
  canbittype                          RS_L_WiperSpeed: 3;
  canbittype                         RS_F_LightSensor: 2;
  canbittype                          RS_F_RainSensor: 2;
  canbittype                       RS_F_Communication: 1;
  canbittype                             RS_F_Voltage: 2;
  canbittype                                  unused0: 1;
  canbittype                            RS_St_LampReq: 2;
  canbittype                        RS_St_CurrentRain: 3;
  canbittype                        RS_N_Irbrightness: 8;
  canbittype                          RS_St_SplashCmd: 2;
  canbittype                                  unused1: 6;
} _c_RS_SENSOR_01_msgType;


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
  canbittype                    TelephoneCall_EndCall: 2;
  canbittype                     MultiMediaButtonMode: 2;
  canbittype                                      ASR: 2;
  canbittype                                 HighBeam: 2;
  canbittype                                   Volume: 3;
  canbittype                       BordcomputerButton: 3;
  canbittype                              ParkService: 2;
  canbittype                             AudioControl: 3;
  canbittype                         STAT_AudioButton: 3;
  canbittype                               FlashLight: 2;
  canbittype                 WiperSensitivityInterval: 3;
  canbittype                             FogLampFront: 2;
  canbittype                              FogLampRear: 2;
  canbittype                                  unused0: 1;
  canbittype                               WiperFront: 3;
  canbittype                              WashMode_FW: 2;
  canbittype                           TurnIndication: 3;
  canbittype                              WashMode_RW: 2;
  canbittype                          LightActivation: 3;
  canbittype                                WiperRear: 2;
  canbittype                             SCM_failure1: 1;
  canbittype                                  unused1: 8;
  canbittype                                  unused2: 8;
} _c_SCM_Information_msgType;

typedef struct {
  canbittype                         Transmission_550: 8;
  canbittype                         Transmission_880: 8;
  canbittype                                  unused0: 8;
  canbittype                                  unused1: 8;
  canbittype                                  unused2: 8;
} _c_BCM_TransmissionWiper_msgType;

typedef struct {
  canbittype                           VehicleSpeed_0: 8;
  canbittype                           VehicleSpeed_1: 8;
  canbittype                            STAT_Ignition: 3;
  canbittype                          GearInformation: 4;
  canbittype                                  unused0: 1;
  canbittype                              Temperature: 8;
  canbittype                                Mileage_0: 8;
  canbittype                                Mileage_1: 8;
  canbittype                          PDCEnableSignal: 2;
  canbittype                  SwitchButtonInformation: 2;
  canbittype                             Vehicle_Type: 2;
  canbittype                                 WiperPos: 2;
  canbittype                           ReservedForPDC: 4;
  canbittype                             Global_Close: 1;
  canbittype                              Global_Open: 1;
  canbittype                           SUNroof_Enable: 1;
  canbittype                              Global_Stop: 1;
} _c_BCM_GENERAL_STATUS_msgType;


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
    unsigned char _c[4];
    _c_RS_SENSOR_01_msgType rs_sensor_01;
} _c_RS_SENSOR_01_buf;


/* Receive messages */

typedef union {
    unsigned char _c[8];
    _c_LinReqCmd_msgType linreqcmd;
} _c_LinReqCmd_buf;

typedef union {
    unsigned char _c[8];
    _c_SCM_Information_msgType scm_information;
} _c_SCM_Information_buf;

typedef union {
    unsigned char _c[5];
    _c_BCM_TransmissionWiper_msgType bcm_transmissionwiper;
} _c_BCM_TransmissionWiper_buf;

typedef union {
    unsigned char _c[8];
    _c_BCM_GENERAL_STATUS_msgType bcm_general_status;
} _c_BCM_GENERAL_STATUS_buf;


/******************************************************************************/
/*                          Databuffer for send objects                       */
/******************************************************************************/

extern MEMORY_FAR _c_LinRespCmd_buf LinRespCmd;
extern MEMORY_FAR _c_ASIC_Frame_04_buf ASIC_Frame_04;
extern MEMORY_FAR _c_ASIC_Frame_03_buf ASIC_Frame_03;
extern MEMORY_FAR _c_ASIC_Frame_02_buf ASIC_Frame_02;
extern MEMORY_FAR _c_ASIC_Frame_01_buf ASIC_Frame_01;
extern MEMORY_FAR _c_RS_SENSOR_01_buf RS_SENSOR_01;

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
#define RS_SENSOR_01_conf_b             uLinConfirmationFlags.w[0].b5
#define l_flg_tst_RS_SENSOR_01()       (RS_SENSOR_01_conf_b != 0)
#define l_flg_clr_RS_SENSOR_01()       {RS_SENSOR_01_conf_b = 0;}

/******************************************************************************/
/*                         Databuffer for receive objects                     */
/******************************************************************************/

extern MEMORY_FAR _c_LinReqCmd_buf LinReqCmd;
extern MEMORY_FAR _c_SCM_Information_buf SCM_Information;
extern MEMORY_FAR _c_BCM_TransmissionWiper_buf BCM_TransmissionWiper;
extern MEMORY_FAR _c_BCM_GENERAL_STATUS_buf BCM_GENERAL_STATUS;

/******************************************************************************/
/*                          Databuffer for indicationflags                    */
/******************************************************************************/

#define LinReqCmd_ind_b             uLinIndicationFlags.w[0].b0
#define l_flg_tst_LinReqCmd()       (LinReqCmd_ind_b != 0)
#define l_flg_clr_LinReqCmd()       {LinReqCmd_ind_b = 0;}
#define SCM_Information_ind_b             uLinIndicationFlags.w[0].b1
#define l_flg_tst_SCM_Information()       (SCM_Information_ind_b != 0)
#define l_flg_clr_SCM_Information()       {SCM_Information_ind_b = 0;}
#define BCM_TransmissionWiper_ind_b             uLinIndicationFlags.w[0].b2
#define l_flg_tst_BCM_TransmissionWiper()       (BCM_TransmissionWiper_ind_b != 0)
#define l_flg_clr_BCM_TransmissionWiper()       {BCM_TransmissionWiper_ind_b = 0;}
#define BCM_GENERAL_STATUS_ind_b             uLinIndicationFlags.w[0].b3
#define l_flg_tst_BCM_GENERAL_STATUS()       (BCM_GENERAL_STATUS_ind_b != 0)
#define l_flg_clr_BCM_GENERAL_STATUS()       {BCM_GENERAL_STATUS_ind_b = 0;}

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
#define RS_L_WiperSpeed                                                       RS_SENSOR_01.rs_sensor_01.RS_L_WiperSpeed
#define RS_F_LightSensor                                                      RS_SENSOR_01.rs_sensor_01.RS_F_LightSensor
#define RS_F_RainSensor                                                       RS_SENSOR_01.rs_sensor_01.RS_F_RainSensor
#define RS_F_Communication                                                    RS_SENSOR_01.rs_sensor_01.RS_F_Communication
#define RS_F_Voltage                                                          RS_SENSOR_01.rs_sensor_01.RS_F_Voltage
#define RS_St_LampReq                                                         RS_SENSOR_01.rs_sensor_01.RS_St_LampReq
#define RS_St_CurrentRain                                                     RS_SENSOR_01.rs_sensor_01.RS_St_CurrentRain
#define RS_N_Irbrightness                                                     RS_SENSOR_01.rs_sensor_01.RS_N_Irbrightness
#define RS_St_SplashCmd                                                       RS_SENSOR_01.rs_sensor_01.RS_St_SplashCmd
#define MasterReqB0                                                           LinReqCmd.linreqcmd.MasterReqB0
#define MasterReqB1                                                           LinReqCmd.linreqcmd.MasterReqB1
#define MasterReqB2                                                           LinReqCmd.linreqcmd.MasterReqB2
#define MasterReqB3                                                           LinReqCmd.linreqcmd.MasterReqB3
#define MasterReqB4                                                           LinReqCmd.linreqcmd.MasterReqB4
#define MasterReqB5                                                           LinReqCmd.linreqcmd.MasterReqB5
#define MasterReqB6                                                           LinReqCmd.linreqcmd.MasterReqB6
#define MasterReqB7                                                           LinReqCmd.linreqcmd.MasterReqB7
#define TelephoneCall_EndCall                                                 SCM_Information.scm_information.TelephoneCall_EndCall
#define MultiMediaButtonMode                                                  SCM_Information.scm_information.MultiMediaButtonMode
#define ASR                                                                   SCM_Information.scm_information.ASR
#define HighBeam                                                              SCM_Information.scm_information.HighBeam
#define Volume                                                                SCM_Information.scm_information.Volume
#define BordcomputerButton                                                    SCM_Information.scm_information.BordcomputerButton
#define ParkService                                                           SCM_Information.scm_information.ParkService
#define AudioControl                                                          SCM_Information.scm_information.AudioControl
#define STAT_AudioButton                                                      SCM_Information.scm_information.STAT_AudioButton
#define FlashLight                                                            SCM_Information.scm_information.FlashLight
#define WiperSensitivityInterval                                              SCM_Information.scm_information.WiperSensitivityInterval
#define FogLampFront                                                          SCM_Information.scm_information.FogLampFront
#define FogLampRear                                                           SCM_Information.scm_information.FogLampRear
#define WiperFront                                                            SCM_Information.scm_information.WiperFront
#define WashMode_FW                                                           SCM_Information.scm_information.WashMode_FW
#define TurnIndication                                                        SCM_Information.scm_information.TurnIndication
#define WashMode_RW                                                           SCM_Information.scm_information.WashMode_RW
#define LightActivation                                                       SCM_Information.scm_information.LightActivation
#define WiperRear                                                             SCM_Information.scm_information.WiperRear
#define SCM_failure1                                                          SCM_Information.scm_information.SCM_failure1
#define Transmission_550                                                      BCM_TransmissionWiper.bcm_transmissionwiper.Transmission_550
#define Transmission_880                                                      BCM_TransmissionWiper.bcm_transmissionwiper.Transmission_880
#define VehicleSpeed_0                                                        BCM_GENERAL_STATUS.bcm_general_status.VehicleSpeed_0
#define VehicleSpeed_1                                                        BCM_GENERAL_STATUS.bcm_general_status.VehicleSpeed_1
#define VehicleSpeed(c)                                                       { VehicleSpeed_0= (uint8)(((uint16)(c) & 0xFF));\
                                                                                VehicleSpeed_1= (uint8)(((uint16)(c) & 0xFF) >> 8);\
                                                                              }
#define STAT_Ignition                                                         BCM_GENERAL_STATUS.bcm_general_status.STAT_Ignition
#define GearInformation                                                       BCM_GENERAL_STATUS.bcm_general_status.GearInformation
#define Temperature                                                           BCM_GENERAL_STATUS.bcm_general_status.Temperature
#define Mileage_0                                                             BCM_GENERAL_STATUS.bcm_general_status.Mileage_0
#define Mileage_1                                                             BCM_GENERAL_STATUS.bcm_general_status.Mileage_1
#define Mileage(c)                                                            { Mileage_0= (uint8)(((uint16)(c) & 0xFF));\
                                                                                Mileage_1= (uint8)(((uint16)(c) & 0xFF) >> 8);\
                                                                              }
#define PDCEnableSignal                                                       BCM_GENERAL_STATUS.bcm_general_status.PDCEnableSignal
#define SwitchButtonInformation                                               BCM_GENERAL_STATUS.bcm_general_status.SwitchButtonInformation
#define Vehicle_Type                                                          BCM_GENERAL_STATUS.bcm_general_status.Vehicle_Type
#define WiperPos                                                              BCM_GENERAL_STATUS.bcm_general_status.WiperPos
#define ReservedForPDC                                                        BCM_GENERAL_STATUS.bcm_general_status.ReservedForPDC
#define Global_Close                                                          BCM_GENERAL_STATUS.bcm_general_status.Global_Close
#define Global_Open                                                           BCM_GENERAL_STATUS.bcm_general_status.Global_Open
#define SUNroof_Enable                                                        BCM_GENERAL_STATUS.bcm_general_status.SUNroof_Enable
#define Global_Stop                                                           BCM_GENERAL_STATUS.bcm_general_status.Global_Stop
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
#define l_u8_rd_RS_L_WiperSpeed()                                           RS_L_WiperSpeed
#define l_u8_wr_RS_L_WiperSpeed(a)                                          {RS_L_WiperSpeed = a;}
#define l_u8_rd_RS_F_LightSensor()                                          RS_F_LightSensor
#define l_u8_wr_RS_F_LightSensor(a)                                         {RS_F_LightSensor = a;}
#define l_u8_rd_RS_F_RainSensor()                                           RS_F_RainSensor
#define l_u8_wr_RS_F_RainSensor(a)                                          {RS_F_RainSensor = a;}
#define l_bool_rd_RS_F_Communication()                                          RS_F_Communication
#define l_bool_wr_RS_F_Communication(a)                                         {RS_F_Communication = a;}
#define l_u8_rd_RS_F_Voltage()                                              RS_F_Voltage
#define l_u8_wr_RS_F_Voltage(a)                                             {RS_F_Voltage = a;}
#define l_u8_rd_RS_St_LampReq()                                             RS_St_LampReq
#define l_u8_wr_RS_St_LampReq(a)                                            {RS_St_LampReq = a;}
#define l_u8_rd_RS_St_CurrentRain()                                         RS_St_CurrentRain
#define l_u8_wr_RS_St_CurrentRain(a)                                        {RS_St_CurrentRain = a;}
#define l_u8_rd_RS_N_Irbrightness()                                         RS_N_Irbrightness
#define l_u8_wr_RS_N_Irbrightness(a)                                        {RS_N_Irbrightness = a;}
#define l_u8_rd_RS_St_SplashCmd()                                           RS_St_SplashCmd
#define l_u8_wr_RS_St_SplashCmd(a)                                          {RS_St_SplashCmd = a;}
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
#define l_u8_rd_TelephoneCall_EndCall()                                     TelephoneCall_EndCall
#define l_u8_wr_TelephoneCall_EndCall(a)                                    {TelephoneCall_EndCall = a;}
#define l_u8_rd_MultiMediaButtonMode()                                      MultiMediaButtonMode
#define l_u8_wr_MultiMediaButtonMode(a)                                     {MultiMediaButtonMode = a;}
#define l_u8_rd_ASR()                                                       ASR
#define l_u8_wr_ASR(a)                                                      {ASR = a;}
#define l_u8_rd_HighBeam()                                                  HighBeam
#define l_u8_wr_HighBeam(a)                                                 {HighBeam = a;}
#define l_u8_rd_Volume()                                                    Volume
#define l_u8_wr_Volume(a)                                                   {Volume = a;}
#define l_u8_rd_BordcomputerButton()                                        BordcomputerButton
#define l_u8_wr_BordcomputerButton(a)                                       {BordcomputerButton = a;}
#define l_u8_rd_ParkService()                                               ParkService
#define l_u8_wr_ParkService(a)                                              {ParkService = a;}
#define l_u8_rd_AudioControl()                                              AudioControl
#define l_u8_wr_AudioControl(a)                                             {AudioControl = a;}
#define l_u8_rd_STAT_AudioButton()                                          STAT_AudioButton
#define l_u8_wr_STAT_AudioButton(a)                                         {STAT_AudioButton = a;}
#define l_u8_rd_FlashLight()                                                FlashLight
#define l_u8_wr_FlashLight(a)                                               {FlashLight = a;}
#define l_u8_rd_WiperSensitivityInterval()                                  WiperSensitivityInterval
#define l_u8_wr_WiperSensitivityInterval(a)                                 {WiperSensitivityInterval = a;}
#define l_u8_rd_FogLampFront()                                              FogLampFront
#define l_u8_wr_FogLampFront(a)                                             {FogLampFront = a;}
#define l_u8_rd_FogLampRear()                                               FogLampRear
#define l_u8_wr_FogLampRear(a)                                              {FogLampRear = a;}
#define l_u8_rd_WiperFront()                                                WiperFront
#define l_u8_wr_WiperFront(a)                                               {WiperFront = a;}
#define l_u8_rd_WashMode_FW()                                               WashMode_FW
#define l_u8_wr_WashMode_FW(a)                                              {WashMode_FW = a;}
#define l_u8_rd_TurnIndication()                                            TurnIndication
#define l_u8_wr_TurnIndication(a)                                           {TurnIndication = a;}
#define l_u8_rd_WashMode_RW()                                               WashMode_RW
#define l_u8_wr_WashMode_RW(a)                                              {WashMode_RW = a;}
#define l_u8_rd_LightActivation()                                           LightActivation
#define l_u8_wr_LightActivation(a)                                          {LightActivation = a;}
#define l_u8_rd_WiperRear()                                                 WiperRear
#define l_u8_wr_WiperRear(a)                                                {WiperRear = a;}
#define l_bool_rd_SCM_failure1()                                                SCM_failure1
#define l_bool_wr_SCM_failure1(a)                                               {SCM_failure1 = a;}
#define l_u8_rd_Transmission_550()                                          Transmission_550
#define l_u8_wr_Transmission_550(a)                                         {Transmission_550 = a;}
#define l_u8_rd_Transmission_880()                                          Transmission_880
#define l_u8_wr_Transmission_880(a)                                         {Transmission_880 = a;}
#define l_u16_rd_VehicleSpeed()                                               (canuint16)(VehicleSpeed_0)\
                                                                                | ((canuint16)(VehicleSpeed_1)<<8)
#define l_u16_wr_VehicleSpeed(a)                                              {VehicleSpeed_0 = ((canuint8)a);\
                                                                                 VehicleSpeed_1 = ((canuint8)a>>8);}
#define l_u8_rd_STAT_Ignition()                                             STAT_Ignition
#define l_u8_wr_STAT_Ignition(a)                                            {STAT_Ignition = a;}
#define l_u8_rd_GearInformation()                                           GearInformation
#define l_u8_wr_GearInformation(a)                                          {GearInformation = a;}
#define l_u8_rd_Temperature()                                               Temperature
#define l_u8_wr_Temperature(a)                                              {Temperature = a;}
#define l_u16_rd_Mileage()                                                    (canuint16)(Mileage_0)\
                                                                                | ((canuint16)(Mileage_1)<<8)
#define l_u16_wr_Mileage(a)                                                   {Mileage_0 = ((canuint8)a);\
                                                                                 Mileage_1 = ((canuint8)a>>8);}
#define l_u8_rd_PDCEnableSignal()                                           PDCEnableSignal
#define l_u8_wr_PDCEnableSignal(a)                                          {PDCEnableSignal = a;}
#define l_u8_rd_SwitchButtonInformation()                                   SwitchButtonInformation
#define l_u8_wr_SwitchButtonInformation(a)                                  {SwitchButtonInformation = a;}
#define l_u8_rd_Vehicle_Type()                                              Vehicle_Type
#define l_u8_wr_Vehicle_Type(a)                                             {Vehicle_Type = a;}
#define l_u8_rd_WiperPos()                                                  WiperPos
#define l_u8_wr_WiperPos(a)                                                 {WiperPos = a;}
#define l_u8_rd_ReservedForPDC()                                            ReservedForPDC
#define l_u8_wr_ReservedForPDC(a)                                           {ReservedForPDC = a;}
#define l_bool_rd_Global_Close()                                                Global_Close
#define l_bool_wr_Global_Close(a)                                               {Global_Close = a;}
#define l_bool_rd_Global_Open()                                                 Global_Open
#define l_bool_wr_Global_Open(a)                                                {Global_Open = a;}
#define l_bool_rd_SUNroof_Enable()                                              SUNroof_Enable
#define l_bool_wr_SUNroof_Enable(a)                                             {SUNroof_Enable = a;}
#define l_bool_rd_Global_Stop()                                                 Global_Stop
#define l_bool_wr_Global_Stop(a)                                                {Global_Stop = a;}


#endif  /* I_LIN_RLS_H */
