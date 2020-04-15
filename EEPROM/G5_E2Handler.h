#ifndef G5_E2HANDLER_H
#define G5_E2HANDLER_H
/*************************************************************************

  Company : Valeo Wiper System

  Project : RLT Sensor, RDN Sensor

  Component : E2Handler.h

  Documentation reference : Software Specification
  Overview of the component : interface to the electronics

  Evolution of the component : see PVCS Version control system

                Initials   date   modification

*************************************************************************/
/* History                                                                    */
/*----------------------------------------------------------------------------*/
/* Date      VDR_Number     Description                                       */
/*----------------------------------------------------------------------------*/
/*04.05.2015 VDR_871    NB     :Safety: all reset sources from RESF should be used except the voltage detector flag */
/* 02.12.2015 VDR_940   NB      write reset source in EEPROM                 */
/*                                                                              */

/******************************************************************************/
/****************************************************************************/
/** Definition for Mono-Inclusion **/
/****************************************************************************/


#ifdef _E2Handler_c_
#define EXTERN /**/
#else
#define EXTERN  extern
#endif





//#define USE_STANDBY_MODE
/****************************************************************************/
/** Global Variables **/
/****************************************************************************/

/* PRQA S 0759 1*//*<< 0759:union needed to reduce RAM usage >>*/
EXTERN SHORT_MEMORY volatile Flag uF_Main_Flags_g;

#define rbi_EEPROMWriteSuccess_g       uF_Main_Flags_g.Bit.B0
#define rbi_EEPROMBytesWritten_g       uF_Main_Flags_g.Bit.B1
#define rbi_EEPROMBytesToWrite_g       uF_Main_Flags_g.Bit.B2
#define rbi_ResetSourceWasInternal_g   uF_Main_Flags_g.Bit.B3 /*VCO_050*/ /* VDR_871 */
#define rbi_WatchdogCheckEnabel_g      uF_Main_Flags_g.Bit.B4
#define rbi_WriteResetSource_g         uF_Main_Flags_g.Bit.B5
#define rbi_EEPROMLoad_g               uF_Main_Flags_g.Bit.B6
#define rbi_InternalResetOccured_g     uF_Main_Flags_g.Bit.B7

EXTERN byte rb_RS_LS_Error1_g;
EXTERN byte rb_RS_LS_Error2_g;
EXTERN byte rb_RainS_Error1_g;
EXTERN byte rb_LightS_Error1_g;

EXTERN word rw_EEPROM_Address_to_Write_g;
EXTERN byte rb_I2C_EEPROM_bytesToWrite_g;

#ifdef CHANG_AN_S311
EXTERN byte rab_EEPROM_Bytes_toWrite_g[9];   //Used to Configure RS_Sensitivity_0~8: Change 5 to 9  Tianyang WANG 2019_02_02 
#else
EXTERN byte rab_EEPROM_Bytes_toWrite_g[5];	
#endif 

EXTERN __callt void main_EEPROM_Loader(void);
/****************************************************************************/
//              Global Contants and Makros
/****************************************************************************/


/*************************************************************************
Declaration of exported functions
**************************************************************************/
/* PRQA S 0841 1 */ /* <<for easier declaration of variable -> proven mechanism>> */
#undef EXTERN



#endif