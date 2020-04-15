/*************************************************************************

Company : Valeo Wiper System

Project : RLT Sensor, RDN Sensor

Component : io.h

Documentation reference : Hardware Software Interface File
Overview of the component : interface to the electronics

Evolution of the component : see PVCS Version control system

Initials   date   modification

*************************************************************************/
/**************************************************************************/
/* History                                                                    */
/*----------------------------------------------------------------------------*/
/* Date      VDR_Number  NAME Description                                       */
/*----------------------------------------------------------------------------*/
/* 16.02.10   VDR_438        adapt voltage level for Hardware H02 avoid Problems 
at short voltage interrupts*/ 
/* 18.01.10   VCO_23         new function to react direct at undervoltge event*/
/* 08.06.09   VDR_330        VDR_20 had shifted rw_afterWashingTime_counter_g
into this header, this file is needed for VDR_330 --> No change in code to this file*/
/* 09.12.09   VDR411          adapt threhsolds for voltage measurement*/
/* 16.03.15   VDR_855    MP     Fix of the findings from the review of ASIC_Control_sr*/
/* 24.03.15 VCO_237  MP  Supplyvoltage should not be monitored on no rain variants*/
/****************************************************************************/

/****************************************************************************/
/** Definition for Mono-Inclusion **/
/****************************************************************************/
#ifndef G5_IO_H
#define G5_IO_H



//#define BMW_PARAMETER

#ifdef _io_c_
#define EXTERN /**/
#else
#define EXTERN  extern
#endif


/****************************************************************************/
/** Global Variables **/
/****************************************************************************/
//EXTERN byte rb_Powerfailcyclecounter;
//EXTERN byte rb_ASIC_Diagnose_State_mg; //State for ASIC Diagnosis
//EXTERN word rw_pulsewith_alt_mg;
//EXTERN byte rb_pulsewith_stored_mg;
/* PRQA S 0759 10*//*<< 0759:union needed to reduce RAM usage >>*/
EXTERN  SHORT_MEMORY volatile Flag uF_VoltageStatus_g;
#define rbi_UnderVoltage_g  uF_VoltageStatus_g.Bit.B0
#define rbi_Powerfail_g    uF_VoltageStatus_g.Bit.B1
#define rbi_Ignition_g    uF_VoltageStatus_g.Bit.B2
#define rbi_OverVoltage_g      uF_VoltageStatus_g.Bit.B3
#define rbi_WasInOperatingRange_g        uF_VoltageStatus_g.Bit.B4
#define rbi_WindowOpenIgnitionWasOn_g    uF_VoltageStatus_g.Bit.B5
#define rbi_LongUnderVoltage_g              uF_VoltageStatus_g.Bit.B7


EXTERN   byte rb_SupplyVoltage_mg; //Value of Supply Voltage
EXTERN   byte rb_InternalTemperature_g; //Value of Supply Voltage

#define cb_ASICStandByModeRequest_g     (byte) 0x01
#define cb_ASICReadEEPromRequest_g      (byte) 0x02
#define cb_ASICAnalogTestbus_g          (byte) 0x03
#define cb_ASICWriteEEPromRequest_g     (byte) 0x04
#define cb_ASICDiagnosisRequest_g       (byte) 0x05
#define cb_ASICDiagnoseConfirmation_g   (byte) 0x06
#define cb_ASICWriteConfirmation_g      (byte) 0x07

/****************************************************************************/
/** Global Flags **/
/****************************************************************************/

#define cb_VERYLOWVOLTAGE_mg (byte)        7       /* 0,5V */
#define cb_GOTOSLEEPVOLTAGE_mg (byte)      52       /* 4V */ /*VDR_438*/
#define cb_STOP_RS_ASICVOLTAGE_mg          AD_ADUL_VALUE       /* 8,0V  97 decimal */
#define cb_START_RS_ASICVOLTAGE_mg (byte)  99       /* 8,1V */

#define cb_ASIC_RS_OVERVOLTAGE_ON_mg       207       /* 16 V */
#define cb_ASIC_RS_OVERVOLTAGE_OFF_mg      219      /* 16.93V; on Bat~17.4V */
#define cb_ASIC_RS_OVERVOLTAGE_HIGH_OFF_mg 220      /* 17.01V; on Bat~17.5V */

/* PRQA S 0759 10*//*<< 0759:union needed to reduce RAM usage >>*/
EXTERN  volatile Flag uF_ASIC_Communication_g;

#define rbi_ASIC_Communication_not_possible_g  uF_ASIC_Communication_g.Bit.B0
#define rbi_ASIC_DiagnosisRequest2_g            uF_ASIC_Communication_g.Bit.B1
//#define rbi_ASCI_StandByProcedureOff_g          uF_ASIC_Communication_g.Bit.B2
#define rbi_ASIC_StandByModeOn_g                uF_ASIC_Communication_g.Bit.B3
#define rbi_ASIC_Step_Response_ready            uF_ASIC_Communication_g.Bit.B4
//#define rbi_ASIC_EEPromChecked_g                uF_ASIC_Communication_g.Bit.B5
//#define rbi_ASIC_diagnose_request_mg            uF_ASIC_Communication_g.Bit.B6
//#define rbi_ASICWriteEEPromWritten_g            uF_ASIC_Communication_g.Bit.B7


#define cb_MS_DELAY_OVERVOLTAGE_s 2000

/****************************************************************************/
// Includes for different Derivates with Port definition
/****************************************************************************/


#include "G5_io_sen.h"


/*************************************************************************
Declaration of exported functions
**************************************************************************/
EXTERN void IO_RefreshPorts(void);
EXTERN void IO_Ports_init(void);
/*VCO_237 Supplyvoltage should not be monitored on no rain variants*/
/*is rain function enabled?*/
#ifndef _NO_RAIN_
EXTERN __callt void io_checkPowerSupply(void);
#endif /*_NO_RAIN_*/

/*is rain function enabled?*/
#ifndef _NO_RAIN_
EXTERN void IO_ExternalUnderVoltageEvent(void); /*VCO_23 new function to react direct at undervoltge event*/
#endif /*_NO_RAIN_*/

/* PRQA S 0841 7 */ /* <<for easier declaration of variable -> proven mechanism>> */
#undef EXTERN

#endif