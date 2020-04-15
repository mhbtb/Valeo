/* PRQA S 0759 EOF */ /* << union is sopported by this compiler>>*/
/* PRQA S 3138 EOF */ /* << using of macros from automatic generated code >>*/
/* PRQA S 2201,2215,2217,715 EOF *//*<< Indentation and line length  >>*/
/* PRQA S 5540,5560,5565,5900 EOF *//*<< Data needs to be verified  >>*/
/* PRQA S 841 EOF *//*<< 841:use of #undef needed  >>*/
/* PRQA S 857 EOF *//*<< Macro exceeds 1024 number  >>*/
/*****************************************************************************************************************

Company : Valeo Wiper System

Project : RLT Sensor, RDN Sensor

Component : RLS_LINST.c

Documentation reference   : Software Requrement Specification
Overview of the component : interface to the electronics

Evolution of the component : see PVCS Version control system

Initials   date   modification
*****************************************************************************************************************/

/****************************************************************************************************************/
/****************************************************************************************************************/
/* Date      VDR_Number  Name   Description                                                                     */
/****************************************************************************************************************/
/* 27.06.11  VDR_671     AL      remove singularity for light on signals                                        */
/* 10.03.11  VDR_638     AL      MISRA OPTIMISATION with corrections in Source code                             */
/* 15.11.10  VCO_093     AL      VCO_095 use compensated humidity and temperatur                                */
/* 15.11.10  VCO_093     AL      implement Veto Function into interface file                                    */
/* 15.11.10  VCO_083     AL      ignore ignition off if speed is higher 4km/h                                   */
/* 22.07.10  VDR_526     AL      clear standby Signals at sleep command                                         */
/* 16.07.10  VCO_061     AL      name has of interface variable has changed                                     */
/* 26.05.10  VCO_050     AL      switch light on for one cylce after watchdog reset                             */
/* 26.05.10  VCO_055     AL      reomve debouncing of RAM and ROM error                                         */
/* 26.05.10  VDR_526     AL      Wake bus for sleep without closing window                                      */
/* 29.04.10  VDR_517     AL      maximum wake time of 60sec                                                     */
/* 29.04.10  VDR_507     AL      block diagnostics on corrupt response                                          */
/* 18.03.10  VDR469      AL      set for error                                                                  */
/* 02.03.10  VCO_028     AL      Adaptations for standby mode                                                   */
/* 24.02.10  VCO_031     AL      use for sleep the EEPROM idle time,actvate Standby mode                        */
/* 22.01.10  VCO_27      AL      rainlight switch of time independend from potistage                            */
/* 14.01.10  VCO_026     AL      block switching light of for any error                                         */
/* 12.01.10  VDR_408     AL      use 0 as init value for rain sensor sensitivity                                */
/* 12.01.10  VCO_24      AL      new Interval time for Konzersensor rain sensor inactive                        */
/* 23.01.08  VDR_124     AL      set rain intensity to init if rain sensor is off                               */
/* 01.02.08  VDR_129     AL      use standard algorithm for undervoltage interval                               */
/* 29.02.08  VDR_154     AL      VDR_154 change of max value from 1022 to 1000                                  */
/* 10.03.08  VDR_157     AL      Dewpoint not set correct                                                       */
/* 26.06.08  VCO_08      AL	 Add FAW Twilight detection                                                     */
/* 23.10.09  VDR_388     AL      Response Error on No Response for VW_Konzernsensor                             */
/****************************************************************************************************************/
/*29.07.2014 VDR_737    NB      In case of negative temperature the sensor sends wrong value                    */
/*11.10.2013 VDR_749    NB      Response Error for Diagnostic ID                                                */
/*04.02.2014 VCO_111    NB      SM138:Saftey:Frequency detection function                                       */
/*15.09.2014 VCO_184    NB      Checksum for calibration data                                                   */
/*17.09.2014 VCO_184    NB      Checksum for calibration data (removed calib error from rain sensor error)      */
/*22.09.2014 VCO_152    NB      Customenr part number shall be stored in EEPROM                                 */
/*24.09.2014 VCO_152    NB      LIN Conformance Test                                                            */
/*29.09.2014 VCO_172    NB      AUDI_Coding of Parkposition on LIN                                              */
/*29.09.2014 VCO_154    MP      Safety:SM139,SM140:Implement RS_Error_Aktiv,LS_Error_Aktiv flag to check after  */
/********************************Reset if an error was active before the sensor goes to sleep or reset          */
/*16.10.2014 VCO_172    NB      AUDI_Coding of Parkposition on LIN                                              */
/*18.11.2014 VDR_824    MP      Error counter for too long init of ASIC                                         */
/*19.11.2014 VCO_195    NB      QAC warning                                                                     */
/*09.02.2015 VCO_220    MP      VIrefLo/Hi monitoring                                                           */
/*11.02.2015 VCO_219    NB      Unused LIN-Bits should be recessiv (1),for solar frame.                         */
/*24.02.2015 VDR_850    NB      After removing HT module from sensor,                                           */
/********************************the HT error displayed after 40s in the LIN Bus                                */
/*25.02.2015 VDR_852    MP      Error bit of ASIC VDDx failure not stored to EEPROM                             */
/*25.02.2015 VCO_224    MP      RS_Error should be set only by RAM/ROM error,                                   */
/********************************when RS function is coded as inactive in kodierbyte0                           */
/*25.02.2015 VCO_225    MP      RS functionality detection - error when not available                           */
/*03.03.2015 VCO_227    NB      Implement RAM Guard function                                                    */
/*18.03.2015 VDR_857    MP      Phantom wipes with the no RS variants                                           */
/*24.03.2015 VDR_859    MP      Interval wipe in manual mode for no rain variant                                */
/*09.04.2015 VCO_241    NB      Implement test function for RAM Guard with one dedicated cell                   */
/*10.04.2015 VCO_241    NB      Implement test function for RAM Guard with one dedicated cell                   */
/*04.05.2015 VDR_871    NB      Safety: all reset sources from RESF should be used,                             */
/********************************except the voltage detector flag                                               */
/*12.05.2015 VDR_878    NB      ADC Error shall be removed from the LS error and included only for RS_error     */
/*13.05.2015 VCO_192    NB      Audi: Activation and deactivation of Interval Operation                         */
/*09.06.2015 VCO_192    NB      Audi: Activation and deactivation of Interval Operation                         */
/*09.06.2015 VDR_868    NB      All:QAC and Polyspace fixing for SW009 Release                                  */
/*10.06.2015 VCO_254    NB      Checking of CRC over light area shall be done cyclically                        */
/*13.07.2015 VCO_260    MP      Tunnel wipe activation and delay according to                                   */
/********************************Tunnel Verzoegerung and Aktivierung parameters                                 */
/*21.09.2015 VDR_909    NB      Fixed interval operation not started after lapsing the ignition delay           */ 
/*                                and activating again                                                          */
/*02.10.2015 VDR_911    SP      HammingErr shld be part of RS_Error/LS_Error and shld not be used for Active Err*/
/*07.10.2015 VCO_278    NB      Solar shadow correction                                                         */
/*08.10.2015 VCO_278    NB      Solar shadow correction                                                         */
/*16.11.2015 VDR_926    SP      Add Compulsary wipe when RS is deaktivated(via LIN Deaktivierung_RS             */
/*                              and Fixed Interval continuous wiping should be active when KL15=0 and speed>4kmh*/
/*25.02.16    VCO_313   NB      Create new variant Feuchte_Solar and Rain_Light_solar for SEAT            */ 
/*24.03.16    VCO_320   NB      LIN response shall not be sent untill EEPROM is loaded                         */ 
/*20.01.17    VDR_1010  NB      RLS_FORD_C1MCA: RSM Partnumber not correctly send on Bus                       */
/****************************************************************************************************************/
/*                   Common and module include-file                                                             */
/****************************************************************************************************************/


#include "ior5f109be.h"
#include "G5_projectDefs.h"
#include "G5_E2ProjectConfig.h"

#include "G5_Appli_main.h"
#define _RLS_LIN_c_         /*Define for Single include of Global Header rls_linst.h */
#include "G5_lininclude.h"
#undef  _RLS_LIN_c_
/*************************************************************************
**                   Other files included                               **
**************************************************************************/

#include "G5_io.h"
#include "G5_Appli_timer.h"
#include "G5_Check_sr.h"
#include "G5_rainsens.h"
#include "G5_diagnose.h"
#include "G5_E2Handler.h"
#include "G5_flashe2.h"

#include "G5_IRlight.h"
#include "G5_DippedBeam_sr.h"
#include "G5_ASIC_Control_sr.h"
/** /brief Declarations of modul specific parameters and variables*/
#include "G5_spi_sr.h"

#include "G5_AsicFramesLin.h"


#define CW_LIN1_3_IDLE_TIMOUT (2*130)

#define STALKPOSITION_COMPACT 1 /*VCO_44*/
#define STALKPOSITION_BITWISE 0 /*VCO_44*/

/*************************************************************************
**                   Declaration of local module variables              **
*************************************************************************/
static byte rb_IgnitionOndelay_mg;


static word rw_AfterRSWipeCounter_mg;                   /* Time after last wipe from RS*/
static word rw_AfterWWSWipeCounter_mg;                  /* Time after last wipe from WWS*/
static word rw_WipeCommandTimOut_mg;                     /*timout for requested wipe*/

static const byte cab_LS_PotistageMapping_mg[8] = {4,5,6,7,3,2,1,0}; /*mapping for potistages!*/
static const byte cab_FixIntervaltimes_mg[4][9] = {{69,78,84,88,94,98,104,112,150},
                                          {43,48,53,56,59,62,66,72,100},
                                          {23,25,27,28,30,31,33,36,56},
                                          {8,9,10,11,11,12,12,13,25}};

static const word caw_DeppressedParkDelayTable_g[4] = {500,1000,1500,2000};
static const byte cab_WiperMotorRunntime_mg[8] = {142,142,133,125,117,111,105,100}; /*VDR_362 simulated Wipe time when SCS is switched off*/


#define cw_CLEARWIPE_DELAY_s 400 /* 4 seconds (400*10ms)*/
#define cb_DEPRESSED_PARK_DEBOUNCE_s 18

static unsigned char framecounter_for_PartNo;
/* PRQA S 0759 1*//*<< 0759:union needed to reduce RAM usage >>*/
static volatile Flag uF_StalkInPos_Flags_g;

/*VDR_368*/
static unsigned char rb_550nm_EEPROM; /*Dummy Variable*/
static unsigned char rb_880nm_EEPROM; /*Dummy Variable*/

extern unsigned char rb_OffsetSigAnzahlDoubleOverwipe;
extern unsigned char rb_OffsetTropfAnzahlDoubleOverwipe;
unsigned char rb_OffsetSigAnzahlSp1DoubleOverwipe;

#define rbi_Stalkposition_CC_dependent_mg    uF_StalkInPos_Flags_g.Bit.B0
#define rbi_StalkInPosIntermittent_g    uF_StalkInPos_Flags_g.Bit.B1
#define rbi_StalkInLowSpeedPos_g    uF_StalkInPos_Flags_g.Bit.B2
#define rbi_StalkInHighSpeedPos_g            uF_StalkInPos_Flags_g.Bit.B3
#define rbi_WiperActive_old           uF_StalkInPos_Flags_g.Bit.B4 /*For rub_WiperSpeed*/
#define rbi_WiperInWipingArea_old     uF_StalkInPos_Flags_g.Bit.B5
#define rbi_WiperInWipingArea         uF_StalkInPos_Flags_g.Bit.B6
static byte rb_AnyErrorCounterDebounce_mg;

/******************************************************************************/
/*                      Definition of exported variables                      */
/******************************************************************************/


/*************************************************************************
**                   Declaration of local module Functions              **
*************************************************************************/

static void check_CarCode(void);
static void check_WindshieldTransm(void);
static void switch_Tropf_Anzahl_AND_Sig_Anzahl(void);
static void switch_Stalkinformation(void);
static void check_for_internal_RS_Mapping(void);
static void check_for_errors(void);
static void set_light_value(void);
static void check_for_RainSensorDirectMode(void);
static void set_RainSensorDirectMode(void);
static void check_for_TunnelWipe(void);
static void allocate_WiperMotorVariables(void);
static void check_for_SteeringColumnSwitch(void);
static void allocate_PartNumber(void);
static void allocate_PotiAndWipingMode(void);
static void LIN_CalculateFixIntervalTime(void);
//---------------------------------------------------------------------------------------



static void check_CarCode(void)
{
  static byte rb_carcode_l;
  /*VDR_344 CarCode adaptation*/
  /*      if (rbi_CarCode_viaEEPROM==TRUE)
  {
    rb_carcode_l = rb_FixedCarCode_g;
  }
  else
  {
    rb_carcode_l = l_bool_rd_CarCode_all();
  }*/
  rb_carcode_l = l_bool_rd_CarCode_all();
  rbi_Stalkposition_CC_dependent_mg = STALKPOSITION_BITWISE; /*Set PartNumber Auxiliary Variable to Init value*/

  switch (rb_carcode_l)
  {/*Requirement: SRD page 97 and Telephone Conference, because C346 gets camera and standalone Version
    RSM equipped with Camera: One time overwiped
    RSM without camera (Standalone): Two times overwiped */
  case 0: /*C344, Green Glass (Heated/Unheated), Stand Alone*/
    rb_550nm_EEPROM = rb_FORD_CarCode00_550nm_g;
    rb_880nm_EEPROM = rb_FORD_CarCode00_880nm_g;
    rbi_Stalkposition_CC_dependent_mg = rb_EEPROM_ldfUsedInCar_g; /*VDR_368*/
    rbi_DoubleOverwiped = rb_FORD_DoubleOverwiped00_g;
    rbi_ButterflyIsEquipped = rb_FORD_Butterfly_00_g; /*VDR_540*/
    break;
  case 1: /*CD340, Green Glass (Heated/Unheated), camera*/
    rb_550nm_EEPROM = rb_FORD_CarCode01_550nm_g;
    rb_880nm_EEPROM = rb_FORD_CarCode01_880nm_g;
    rbi_Stalkposition_CC_dependent_mg = rb_EEPROM_ldfUsedInCar_g;
    rbi_DoubleOverwiped = rb_FORD_DoubleOverwiped01_g;
    rbi_ButterflyIsEquipped = rb_FORD_Butterfly_01_g; /*VDR_540*/
    break;
  case 2: /*C344, Green Glass (Heated/Unheated), camera*/
    rb_550nm_EEPROM = rb_FORD_CarCode02_550nm_g;
    rb_880nm_EEPROM = rb_FORD_CarCode02_880nm_g;
    rbi_Stalkposition_CC_dependent_mg = rb_EEPROM_ldfUsedInCar_g;
    rbi_DoubleOverwiped = rb_FORD_DoubleOverwiped02_g;
    rbi_ButterflyIsEquipped = rb_FORD_Butterfly_02_g; /*VDR_540*/
    break;
  case 3: /*CD345, Blue, camera only*/
    rb_550nm_EEPROM = rb_FORD_CarCode03_550nm_g;
    rb_880nm_EEPROM = rb_FORD_CarCode03_880nm_g;
    rbi_Stalkposition_CC_dependent_mg = rb_EEPROM_ldfUsedInCar_g;
    rbi_DoubleOverwiped = rb_FORD_DoubleOverwiped03_g;
    rbi_ButterflyIsEquipped = rb_FORD_Butterfly_03_g; /*VDR_540*/
    break;
  case 4: /*C344, IR prot. Heated only, Standalone*/
    rb_550nm_EEPROM = rb_FORD_CarCode04_550nm_g;
    rb_880nm_EEPROM = rb_FORD_CarCode04_880nm_g;
    rbi_Stalkposition_CC_dependent_mg = rb_EEPROM_ldfUsedInCar_g;
    rbi_DoubleOverwiped = rb_FORD_DoubleOverwiped04_g;
    rbi_ButterflyIsEquipped = rb_FORD_Butterfly_04_g; /*VDR_540*/
    break;
  case 5: /*C344, IR prot. Heated only, Camera*/
    rb_550nm_EEPROM = rb_FORD_CarCode05_550nm_g;
    rb_880nm_EEPROM = rb_FORD_CarCode05_880nm_g;
    rbi_Stalkposition_CC_dependent_mg = rb_EEPROM_ldfUsedInCar_g;
    rbi_DoubleOverwiped = rb_FORD_DoubleOverwiped05_g;
    rbi_ButterflyIsEquipped = rb_FORD_Butterfly_05_g; /*VDR_540*/
    break;
  case 6:/*CD340, IR protected, camera*/
    rb_550nm_EEPROM = rb_FORD_CarCode06_550nm_g;
    rb_880nm_EEPROM = rb_FORD_CarCode06_880nm_g;
    rbi_Stalkposition_CC_dependent_mg = rb_EEPROM_ldfUsedInCar_g;
    rbi_DoubleOverwiped = rb_FORD_DoubleOverwiped06_g;
    rbi_ButterflyIsEquipped = rb_FORD_Butterfly_06_g; /*VDR_540*/
    break;
  case 7: /*CD345, Green Glass (Heated/Unheated), camera*/
    rb_550nm_EEPROM = rb_FORD_CarCode07_550nm_g;
    rb_880nm_EEPROM = rb_FORD_CarCode07_880nm_g;
    rbi_Stalkposition_CC_dependent_mg = rb_EEPROM_ldfUsedInCar_g;
    rbi_DoubleOverwiped = rb_FORD_DoubleOverwiped07_g;
    rbi_ButterflyIsEquipped = rb_FORD_Butterfly_07_g; /*VDR_540*/
    break;
  case 8: /*CD345, IR prot. (Heated/Unheated), camera*/
    rb_550nm_EEPROM = rb_FORD_CarCode08_550nm_g;
    rb_880nm_EEPROM = rb_FORD_CarCode08_880nm_g;
    rbi_Stalkposition_CC_dependent_mg = rb_EEPROM_ldfUsedInCar_g;
    rbi_DoubleOverwiped = rb_FORD_DoubleOverwiped08_g;
    rbi_ButterflyIsEquipped = rb_FORD_Butterfly_08_g; /*VDR_540*/
    break;
  case 9:/*C346, Green Glass, Standalone, Double Overwiped by default!*/
    rb_550nm_EEPROM = rb_FORD_CarCode09_550nm_g;
    rb_880nm_EEPROM = rb_FORD_CarCode09_880nm_g;
    rbi_Stalkposition_CC_dependent_mg = rb_EEPROM_ldfUsedInCar_g;
    rbi_DoubleOverwiped = rb_FORD_DoubleOverwiped09_g;
    rbi_ButterflyIsEquipped = rb_FORD_Butterfly_09_g; /*VDR_540*/
    break;
  case 10:/*C346, Green Glass, camera*/
    rb_550nm_EEPROM = rb_FORD_CarCode10_550nm_g;
    rb_880nm_EEPROM = rb_FORD_CarCode10_880nm_g;
    rbi_Stalkposition_CC_dependent_mg = rb_EEPROM_ldfUsedInCar_g;
    rbi_DoubleOverwiped = rb_FORD_DoubleOverwiped10_g;
    rbi_ButterflyIsEquipped = rb_FORD_Butterfly_10_g; /*VDR_540*/
    break;
  case 11:/*c346, IR prot. (heated/unheated), stand alone*/
    rb_550nm_EEPROM = rb_FORD_CarCode11_550nm_g;
    rb_880nm_EEPROM = rb_FORD_CarCode11_880nm_g;
    rbi_Stalkposition_CC_dependent_mg = rb_EEPROM_ldfUsedInCar_g;
    rbi_DoubleOverwiped = rb_FORD_DoubleOverwiped11_g;
    rbi_ButterflyIsEquipped = rb_FORD_Butterfly_11_g; /*VDR_540*/
    break;
  case 12:/*c346, IR prot. (heated/unheated), camera*/
    rb_550nm_EEPROM = rb_FORD_CarCode12_550nm_g;
    rb_880nm_EEPROM = rb_FORD_CarCode12_880nm_g;
    rbi_Stalkposition_CC_dependent_mg = rb_EEPROM_ldfUsedInCar_g;
    rbi_DoubleOverwiped = rb_FORD_DoubleOverwiped12_g;
    rbi_ButterflyIsEquipped = rb_FORD_Butterfly_12_g; /*VDR_540*/
    break;
  case 13: /*T6, Green Glass,??*/
    rb_550nm_EEPROM = rb_FORD_CarCode13_550nm_g;
    rb_880nm_EEPROM = rb_FORD_CarCode13_880nm_g;
    rbi_Stalkposition_CC_dependent_mg = rb_EEPROM_ldfUsedInCar_g;
    rbi_DoubleOverwiped = rb_FORD_DoubleOverwiped13_g;
    rbi_ButterflyIsEquipped = rb_FORD_Butterfly_13_g; /*VDR_540*/
    break;
  case 14: /*T6, Green Glass,??*/
    rb_550nm_EEPROM = rb_FORD_CarCode14_550nm_g;
    rb_880nm_EEPROM = rb_FORD_CarCode14_880nm_g;
    rbi_Stalkposition_CC_dependent_mg = rb_EEPROM_ldfUsedInCar_g;
    rbi_DoubleOverwiped = rb_FORD_DoubleOverwiped14_g;
    rbi_ButterflyIsEquipped = rb_FORD_Butterfly_14_g; /*VDR_540*/
    break;
  case 15: /*T6, Green Glass,??*/
    rb_550nm_EEPROM = rb_FORD_CarCode15_550nm_g;
    rb_880nm_EEPROM = rb_FORD_CarCode15_880nm_g;
    rbi_Stalkposition_CC_dependent_mg = rb_EEPROM_ldfUsedInCar_g;
    rbi_DoubleOverwiped = rb_FORD_DoubleOverwiped15_g;
    rbi_ButterflyIsEquipped = rb_FORD_Butterfly_15_g; /*VDR_540*/
    break;
  default: /*No valid Car Config, set case 15 Green Glass Parameters*/
    rb_550nm_EEPROM = rb_FORD_CarCode15_550nm_g;
    rb_880nm_EEPROM = rb_FORD_CarCode15_880nm_g;
    rbi_Stalkposition_CC_dependent_mg = rb_EEPROM_ldfUsedInCar_g;
    rbi_DoubleOverwiped = rb_FORD_DoubleOverwiped15_g;
    rbi_ButterflyIsEquipped = rb_FORD_Butterfly_15_g; /*VDR_540*/
    break;
  /*VDR_344 This Error is dependent from CarCode
  * --> In 2008-Version RainSensorEnable was linked with Adapt Active Error*/
  /*    l_bool_wr_AdaptErrRainSensActive(rbi_RainSensorEnable);*/
  }
  /* PRQA S 5830,5900 1 */ /* << This function is reduced and minimized as much as possible >> */
}


static void check_WindshieldTransm(void)
{
  byte rb_550nm_Transmission_local;
  byte rb_880nm_Transmission_local;
  /*VDR_368 check transmission values for failure code from EEPROM (Unknown Project or Rain Sensor not equipped)*/
  if ( ( (rb_550nm_EEPROM <= 20)&&(rb_880nm_EEPROM >= 95) ) /*0x0F written in EEPROM cell */
      || (rb_550nm_EEPROM < 20) || (rb_550nm_EEPROM > 95) || (rb_880nm_EEPROM > 95) || (rb_880nm_EEPROM < 20) )
  { /*Transmission values say, not defined or error of CarCode*/
    l_bool_wr_AdaptErrRainSens(TRUE);
    l_bool_wr_AdaptErrRainSensActive(TRUE);
    rb_550nm_EEPROM = 85; /*Standard Parameters in error case*/
    rb_880nm_EEPROM = 50; /*Standard Parameters in error case*/
  }
  else
  { /*Transmission values OK*/
    l_bool_wr_AdaptErrRainSens(0);
    l_bool_wr_AdaptErrRainSensActive(0);
    
  }
  
  rb_550nm_Transmission_local = (rb_550nm_EEPROM - 20)/5;
  rb_880nm_Transmission_local = (rb_880nm_EEPROM - 20)/5;
  rb_880nm_Transmission_local = (rb_880nm_Transmission_local<<4); 
  if((rb_Kodierbyte2_g != (rb_550nm_Transmission_local | rb_880nm_Transmission_local)) && ((rbi_EEPROMBytesToWrite_g == FALSE)||(rbi_EEPROMBytesWritten_g == TRUE)))
  {
    rab_EEPROM_Bytes_toWrite_g[0] = (rb_550nm_Transmission_local | rb_880nm_Transmission_local);
    rw_EEPROM_Address_to_Write_g = cw_EEPROM_CODING_ADDRESS_g; /*set adress to write*/
    rb_I2C_EEPROM_bytesToWrite_g = 1;         /*set number of bytes to 2*/
    rbi_EEPROMBytesToWrite_g = TRUE;
    rbi_EEPROMBytesWritten_g = FALSE;
  }
  
}

static void switch_Tropf_Anzahl_AND_Sig_Anzahl(void)
{
  if( (rbi_DoubleOverwiped == TRUE)&&(rbi_ButterflyIsEquipped ==TRUE) )
  {
    rb_OffsetSigAnzahlDoubleOverwipe = EEPROM_OffsetButterflyDoubleOverwipe_Sig;
    rb_OffsetTropfAnzahlDoubleOverwipe = EEPROM_OffsetButterflyDoubleOverwipe_Tropf;
    rb_OffsetSigAnzahlSp1DoubleOverwipe = EEPROM_OffsetButterflyDoubleOverwipe_SigSp1;
  }
  else
  {
    rb_OffsetSigAnzahlDoubleOverwipe = 0;
    rb_OffsetTropfAnzahlDoubleOverwipe = 0;
    rb_OffsetSigAnzahlSp1DoubleOverwipe = 0;
  }
}

static void switch_Stalkinformation(void)
{
  /*VDR_368 which Stalk-Information is sent from Master?*/
  if(rbi_Stalkposition_CC_dependent_mg==STALKPOSITION_BITWISE)
  { /*Bitwise Stalk information*/
    rbi_StalkInPosIntermittent_g=l_u8_rd_StalkInIntermittentPos();
    rbi_StalkInLowSpeedPos_g = l_bool_rd_StalkInLowSpeedPos();
    rbi_StalkInHighSpeedPos_g = l_bool_rd_StalkInHighSpeedPos();
  }
  else
  { /*Compact Stalk information*/
    switch ( l_bool_rd_StalkInPos_compact() )
    {
    case 0: /*Stalk is OFF*/
      rbi_StalkInPosIntermittent_g = 0;
      rbi_StalkInLowSpeedPos_g = 0;
      rbi_StalkInHighSpeedPos_g = 0;
      break;
    case 1: /*Intermittent Mode*/
      rbi_StalkInPosIntermittent_g = 1;
      rbi_StalkInLowSpeedPos_g = 0;
      rbi_StalkInHighSpeedPos_g = 0;
      break;
    case 2: /*LowSpeed*/
      rbi_StalkInPosIntermittent_g = 1;
      rbi_StalkInLowSpeedPos_g = 0;
      rbi_StalkInHighSpeedPos_g = 0;
      break;
    case 3: /*HighSpeed*/
      rbi_StalkInPosIntermittent_g = 1;
      rbi_StalkInLowSpeedPos_g = 0;
      rbi_StalkInHighSpeedPos_g = 0;
      break;
    case 4: /*Handle SingleStroke like Stalk is OFF*/
      rbi_StalkInPosIntermittent_g = 0;
      rbi_StalkInLowSpeedPos_g = 0;
      rbi_StalkInHighSpeedPos_g = 0;
      break;
    default: /*handle other values like Stalk Is OFF*/
      rbi_StalkInPosIntermittent_g = 0;
      rbi_StalkInLowSpeedPos_g = 0;
      rbi_StalkInHighSpeedPos_g = 0;
      break;
    }
  }
}

static void check_for_internal_RS_Mapping(void)
{
  /*VCO_33 RainSensor Mapping*/
  static unsigned char SCS_sens_is_set_to;
  static unsigned char Bit_count;
  static unsigned char Bit_is_set_count;
  static unsigned char Byte_compare;

  /* VDR_437: Mapping of Rain Sensor Sensitivity in EEPROM*/
  /* rb_PotiStageFromBox_g = cab_RS_PotistageMapping_mg[l_u8_rd_IntermittentTime()];*/
  SCS_sens_is_set_to = l_u8_rd_IntermittentTime() + 1;
  if (SCS_sens_is_set_to > 6 )   /*VDR_368: FRSI762 Allocate PotiStage to highest Value, when Unknown Value*/
  {
    SCS_sens_is_set_to = 6;
  }
  Bit_count = 0;
  Bit_is_set_count = 0;
  while (Bit_is_set_count < SCS_sens_is_set_to)
  {
    if (Bit_count<=7) /*Error Management and Misra*/
    {
      Byte_compare = rb_EEPROM_RS_Sens_Mapping_g;
      Byte_compare &= (0x01U<<Bit_count);
      if (Byte_compare >0)
      {
        Bit_is_set_count++;
      }
      Bit_count++;
      /*Misra and Compiler Warning*/
    }
    else
    { /*Error Case to leave while*/
      Bit_is_set_count = SCS_sens_is_set_to;
      /*Set Bit_Count to default!*/
      Bit_count = 4;
    }
    /*VCO_33 decrease Bit_count with 1 when While-Loop-End Condition has been reached*/
    if (Bit_is_set_count >= SCS_sens_is_set_to)
    {
      if (Bit_count >0)
      {
        rb_PotiStageFromBox_g = Bit_count - 1; /*Because always set to one when one while loop is over!*/
      }
      else
      {
        rb_PotiStageFromBox_g = 3;
      }
    }
  }/*While-Loop*/
rb_LIN_SensitivityShift_g =  9;       //adaptation Variable for sensitivity factor
}

static void check_for_errors(void)
{
  
    if(FALSE==rbi_EEPROMLoad_g)
  {
    if((FALSE==rbi_RainSensor_enabled_g) && (FALSE==rbi_RainsensorDisabled_g)) 
    {
      /*version error*/
      bi_RS_VariantError_g = TRUE;
    }
    else
    {
      bi_RS_VariantError_g = FALSE;
    }
  }
  
  /*VCO_154 Safety:SM139, SM140:Implement RS_Error_Aktiv,LS_Error_Aktiv flag  to 
  check after Reset if a error was active before the sensor goes to sleep or reset*/
  rb_RS_LS_Error1_g = (bi_ROM_CHECK_FAILURE_g | 
                       (bi_RAM_CHECK_FAILURE_g<<1) | 
                         (rbi_Check_LS_NoCommunication_g<<2) | 
                           (rbi_LS_Error_Vref_g<<3) | 
                             (rbi_ASIC_FreqTrimming_error_g<<4) | 
                               (rbi_ASIC_SPI_Error_g<<5) | 
                                 (rbi_ASIC_NoValidAD_Error_g<<6) | 
                                   (rbi_ASICReg_NoValidVals_Error_g<<7));
  /*VCO_220 VIrefLo/Hi monitoring*/ /*VDR_878*/
  rb_RS_LS_Error2_g = (rbi_VDD_LightSignalError_g | 
                       (rbi_ClockFreq_Error_g<<1) | 
                         (rbi_LEDx_LStop_error_g<<2) |
                           (rbi_ASIC_initTimeout_err_g<<3) |
                             (rbi_VIref_Error_g<<4));
  
  /*VCO_225 RS functionality detection - error when not available*/
  rb_RainS_Error1_g = (rbi_RainSensorError | 
                       (rbi_REGV_OSAT_Error_g<<1) |
                         (rbi_LEDx_LClosed_error_g<<2)|
                           (bi_RS_VariantError_g<<3)|
                             (rbi_ADC_Error_g<<4));  
  
  rb_LightS_Error1_g = (rbi_LightSensorError_g | 
                        (rb_ASIC_ALSx_ShortDetected_Error_g<<1) | 
                          (bi_CALIB_CHECK_FAILURE_g<<2) | 
                            (rbi_LS_Error_VCalib_meas_g<<3)| 
                              (bi_RAM_GUARD_Error_g << 4));
  /*VCO_224 RS_Error should be set only by RAM/ROM error, when RS function is coded as inactive in kodierbyte0*/
  
  if (rbi_oneTimeAnswerd_g == TRUE)
  {
    if((TRUE==rbi_RainSensor_enabled_g) && (FALSE==rbi_RainsensorDisabled_g))
    {
      /* VCO132: SM210 - ASIC Frequency Check (done at startup) - LS,RS_Failure */
      /* VCO 140: SM150 - ADC test */
      /* setze Lichtsensor RS-Fehler nach SRS */
      /*SM240*/
      l_bool_wr_FaultInRainSens((rb_RS_LS_Error1_g != 0)||(rb_RS_LS_Error2_g != 0)||(rb_RainS_Error1_g != 0) ||(rbi_HammingError_g != 0));
      l_bool_wr_FaultInRainSensActive((rb_RS_LS_Error1_g != 0)||(rb_RS_LS_Error2_g != 0)||(rb_RainS_Error1_g != 0) ||(rbi_HammingError_g != 0));
    }
    else 
    {
      /*only RAM/ROM error and RS version error*/
      l_bool_wr_FaultInRainSens(((rb_RS_LS_Error1_g&0x3) != 0)||(TRUE==bi_RS_VariantError_g)||(rbi_HammingError_g != 0));
        l_bool_wr_FaultInRainSensActive(((rb_RS_LS_Error1_g&0x3) != 0)||(TRUE==bi_RS_VariantError_g)||(rbi_HammingError_g != 0));
    }
  }
  else
  {
    l_bool_wr_FaultInRainSensActive(TRUE);    
  }
  
  if((rbi_LightSensorActive_g == TRUE) && (rbi_oneTimeAnswerd_g == TRUE))
  {
    l_bool_wr_FaultInAlsSensor((rb_RS_LS_Error1_g != 0)||(rb_RS_LS_Error2_g != 0)||(rb_LightS_Error1_g != 0)||(rbi_HammingError_g != 0)||(rbi_CRC_ChangedByDiagnostic_g));
    l_bool_wr_FaultInAlsSensorActive((rb_RS_LS_Error1_g != 0)||(rb_RS_LS_Error2_g != 0)||(rb_LightS_Error1_g != 0)||(rbi_HammingError_g != 0)||(rbi_CRC_ChangedByDiagnostic_g));
  }
  else
  {
    l_bool_wr_FaultInAlsSensorActive(TRUE);    
  }
  
  /* PRQA S 3415, 4112 1 */ /* << Getter functions must not have side effects >>*/
  if (((((IS_LS_ANY_ERRORCOUNTER()) > 0))||/*((l_bool_rd_LS_Error()) > 0))||*/(((rbi_UnderVoltage_g) == TRUE))
       || ((rbi_OverVoltage_g) == TRUE)))
  {
    rb_AnyErrorCounterDebounce_mg = 250;
  }
  else
  {
    if (rb_AnyErrorCounterDebounce_mg > 0)
    {
      rb_AnyErrorCounterDebounce_mg -- ;
    }
  }
  
  
}

static void set_light_value(void)
{
  byte rb_TempLightOn_l;
  
  if ((rb_RS_LS_Error1_g != 0)||(rb_RS_LS_Error2_g != 0)||(rb_LightS_Error1_g != 0)||(rbi_HammingError_g != 0)||(rbi_CRC_ChangedByDiagnostic_g))
  {
    rb_TempLightOn_l = 1;
  }
  else if(
   ((uF_modi_lightsens_g.AllBit & 0x2F)>0)
   ||((uF_modi_lightsens_inv_g.AllBit & 0x2F)< 0x2F) /*VDR_355 useSensTreatment*/ 
   ||((rbi_Freewaylight_enabled_g==TRUE) && (rbi_FastHighwayMode_g == TRUE))
   ||((rbi_modi_lightsens_rain_g == TRUE) && (rbi_RainLight_enabled_g == TRUE))) /*VDR_129 use Sensitivity Treatment*/
  {
    rb_TempLightOn_l = TRUE;
  }
  else
  {
    if ((rb_AnyErrorCounterDebounce_mg ==0)&&(get_rb_LightVetoCounter_g()==0)) /*VCO_093 use Veto of Lightsensor*/
    {
      rb_TempLightOn_l = FALSE;
    }
    else
    {
      rb_TempLightOn_l = l_bool_rd_AlsDippedBeamReq() ; /* stay in old light mode and do */
    }
  }

  l_bool_wr_AlsDippedBeamReq(rb_TempLightOn_l);                      // Licht ein = TRUE

}

static void check_for_RainSensorDirectMode(void)
{
  /*VDR_368*/
  static unsigned char Splash_Bit_debounce_counter;

  /*VDR_368, VDR_556: Set splash-bit only, when RainSensor is requested via LIN*/
  if ((l_bool_rd_RainSensorActive()!= FALSE) && (l_bool_rd_RainSensorInDirectMode() > 0))
  { /*Use rbi_RSWipeFastDmd ONLY, when AutoWipe && RainSensorInDirectMode are ACTIVE */
    l_bool_wr_SplashDetected(rbi_RSWipeFastDmd);     /*Set SPlash Bit, set WiperSpeed to 7 is done in rainsens.c*/
    Splash_Bit_debounce_counter =0;
  }
  else /*VDR_556: Do not use rbi_RSWipeFastDmd, when
        * - AutoWipe is TRUE && RainSensorInDirectMode is 0
        * - AutoWipe is FALSE && RainSensorInDirectMode is 0
        * - AutoWipe is FALSE && RainSensorInDirectMode is 1
        * --> so, else-clause is perfectly sufficient */
  {
    if (Splash_Bit_debounce_counter < 60)  /*40 means 400ms*/
    {
      Splash_Bit_debounce_counter++;
      if (l_bool_rd_SplashDetected() == 0) /*check last*/
      {
        Splash_Bit_debounce_counter = 60;
      }
      else
      {
        l_bool_wr_SplashDetected(rbi_RSWipeFastDmd);     /*Set SPlash Bit, set WiperSpeed to 7 is done in rainsens.c*/
      }
    }
    else
    {
      l_bool_wr_SplashDetected(0);            /*VDR_368: Reset splash bit, check else-clause for more comments*/
    }
  }
}


static void set_RainSensorDirectMode(void)
{
  static unsigned char rb_CounterToReset_InDirectMode;

  if (rbi_RainsensorDisabled_g == TRUE)
  {
    l_bool_wr_RainSensorInDirectMode(0); // nicht in depressed park bei festem Interval
  }
  else
  {
    /*VDR_354 DirectMode bit according FORD spec */
    if ((rbi_AutomaticWipingMode_g==FALSE)|| /*VDR_556: RainSensorAutoMode implemented*/ 
        (rw_AfterWWSWipeCounter_mg > 
         ( (caw_DeppressedParkDelayTable_g[rb_delay_depressed_park_pointer_g])<<EEPR_DepressedParkDelay_Shifter
         )
        )
       )/*VDR_344 Depressed Park*/
    {
      l_bool_wr_RainSensorInDirectMode(1);   /* Direktmodus Depressed Park bit uebergeben*/
    }
    else
    {
      if (rb_CounterToReset_InDirectMode < 0xFF)
      {
        rb_CounterToReset_InDirectMode++;
      }
      if(rb_CounterToReset_InDirectMode > 40) /*400ms == 40*/
      {
        l_bool_wr_RainSensorInDirectMode(0);   /* Direktmodus Depressed Park bit uebergeben*/
        rb_CounterToReset_InDirectMode = 0xFF;
      }
    }
    if ( (l_bool_rd_RainSensorInDirectMode() > 0)
             &&(rbi_ParkPosition_g == FALSE)
               &&(rb_CounterToReset_InDirectMode == 0xFF) )
    { /*VDR_368 Reset Counter only, when Wiper motor is out of park (debounced),
        InDirectMode set and CounterToReset Set to Max*/
      rb_CounterToReset_InDirectMode = 0;
    }
  }
}

static void check_for_TunnelWipe(void)
{
  static byte rb_TunnelWipeTimeOut_mg;

  /*VDR_368 (VDR_360) RainSensor Disabled via EEPROM, also implemented now is the "inside tunnel" wipe*/
  if( ((rw_AfterRSWipeCounter_mg < 1500)&&(rb_speed_in_kmh_g > 29)) //Afterwipe at tunnel
    &&((rbi_modi_lightsens_tunnel_g == TRUE)
      &&((rbi_modi_lightsens_tunnel_alt_mg == FALSE)
        && (rb_WiperSpeed_g == 0))) )
  {
    rb_TunnelWipeTimeOut_mg = 0;
    rbi_TunnelWipe_mg = TRUE;
    l_u8_wr_WipeSpeedRainSensor(1);   /*Transmit WiperSpeed for TunnelWipe*/
  }
  else if(rbi_TunnelWipe_mg == TRUE)
  {
    if((rbi_ParkPosition_g == FALSE)||(rb_TunnelWipeTimeOut_mg >= 50))
    {
      rbi_TunnelWipe_mg = FALSE;
      rb_TunnelWipeTimeOut_mg = 0;
    }
    else
    {
      rb_TunnelWipeTimeOut_mg++;
    }
    l_u8_wr_WipeSpeedRainSensor(1);   /*Transmit WiperSpeed for TunnelWipe*/
  }
  else
  {/*VDR_368 (VDR_360) No tunnel wipe set, Normal Case*/
    if((rbi_StalkInLowSpeedPos_g==TRUE)&&(rb_WiperSpeed_g > 1))
    {
      l_u8_wr_WipeSpeedRainSensor(1); /*VDR_362: Transmit WiperSpeed not higher than LowSpeedPos*/
    }
    else
    {
      l_u8_wr_WipeSpeedRainSensor(rb_WiperSpeed_g); /*Transmit Wiper Speed to LIN*/
    }
    if (rb_WiperSpeed_g >0)
    {
      rw_AfterRSWipeCounter_mg =0;
    }
  }
  rbi_modi_lightsens_tunnel_alt_mg = rbi_modi_lightsens_tunnel_g; //alter wert speichern
}

static void allocate_WiperMotorVariables(void)
{
  /*VCO_59 Store actual value for next cycle in Bit*/
  if (rb_WiperSpeed_g>0)
  { /*Wiper is triggered*/
    rbi_WiperActive_old = 1;
  }
  else
  { /*Wiper is not triggered*/
    rbi_WiperActive_old = 0;
  }

  /*Store actual value for next cycle*/
  rbi_WiperInWipingArea_old = rbi_WiperInWipingArea;

  /*VDR_362: Carry Over Standard Code with Ford specific update*/
  if ((rb_WiperSpeed_g > 0)&&(rbi_RealParkContact_g == TRUE))
  {
    if (rw_WipeCommandTimOut_mg <= cw_CLEARWIPE_DELAY_s)
    {
      rw_WipeCommandTimOut_mg ++;                // reset Timout if wiper motor wants not wipe
    }
    else
    {
        rb_LimitMemomryNoWiperReaction_g = TRUE;
    }
  }

}

static void check_for_SteeringColumnSwitch(void)
{
  static byte rb_parkpositioncounter_s;
  static byte SimulateParkContact_counter; /*VCO_49*/
  static word WaitForParkContact_counter; /*VCO_49*/

  if((((rbi_StalkInPosIntermittent_g == FALSE)
      && (rbi_StalkInLowSpeedPos_g == FALSE))
        && ((rbi_StalkInHighSpeedPos_g == FALSE)
          && (rbi_RealParkContact_g == TRUE)
            && (l_bool_rd_RainSensorActive()==FALSE) ))
     ||(rw_WipeCommandTimOut_mg > cw_CLEARWIPE_DELAY_s))
  { /*Do this only, when SCS is in OFF position AND when RainSensor not Active*/
    if((rb_WiperSpeed_g > 0)||(rbi_ParkPosition_g == FALSE))
    {
      if(rb_parkpositioncounter_s>20) /*Debounce*/
      {
        rbi_ParkPosition_g = FALSE;                 /*simulated "Wiper runs"*/
      }
      rb_parkpositioncounter_s++;             /* VDR_362 increment counter --> Does overflow when No Wipe detected*/
    }

    if(rb_parkpositioncounter_s > (cab_WiperMotorRunntime_mg[rb_WiperSpeed_g]))
    {
      rw_WipeCommandTimOut_mg = 0;
      rbi_ParkPosition_g = TRUE;               /* delete bit for Parkposition, Simulated "Wiper parks"*/
      rb_parkpositioncounter_s = 0;
    }
  }
  else
  {/*VDR_362 Carry over Standard Code*/
    if((rbi_RealParkContact_g == TRUE)&&(rb_WiperSpeed_g > 0))
    {
      rbi_WiperStarted_g = TRUE;
    }

    if (/*Wiper parks*/rbi_RealParkContact_g == TRUE)        /* In ParkContact?*/
    {
      if (rbi_ParkPosition_g == FALSE)
      {
        rb_parkpositioncounter_s=0;                 /* reset counter */
      }
      else if (rb_parkpositioncounter_s < 255)
      {
        rb_parkpositioncounter_s++;
      }
      else
      {
        /*Do nothing, Dummy-else for Misra Check*/
      }
      rbi_ParkPosition_g = TRUE;                     /* Wiper parks*/

      if ( (rbi_WiperActive_old==0)&&(rb_WiperSpeed_g>0) ) /*VCO_59*/
      { /*VCO_49 Wiper did not move yet, set simulate ParkContact Bit*/
        if (rbi_SimulateParkContact_g == 0)
        {
          rbi_WiperStarted_g = 1;
          rbi_SimulateParkContact_g = 1;
          WaitForParkContact_counter = 0;
          SimulateParkContact_counter = 0; /*Start or Restart Simulated Park Contact Counter*/
        }
      }
      if ( (rbi_WiperInWipingArea_old==0)&&(rbi_WiperInWipingArea>0) )
      { /*Wiper moves, Reset SimulateParkContact-Bit and Counter*/
        rbi_WiperStarted_g = 0;
        rbi_RealParkContact_g = 0;
        rbi_SimulateParkContact_g = 0;
      }
    }
    else
    {
      rb_LimitMemomryNoWiperReaction_g = FALSE;
      rw_WipeCommandTimOut_mg = 0;                /* reset Timout if wiper motor wants not wipe*/
      if (rb_parkpositioncounter_s>7)   /*Debounce*/
      {/*Wiper Runs*/
        rbi_WiperStarted_g = FALSE; /*VDR_362: Only used when RainSensorPosition near ParkContact*/
        rbi_ParkPosition_g = FALSE;                 /*Wiper runs*/
        if ( (rbi_WiperInWipingArea_old > 0)&&(rbi_WiperInWipingArea==0) )
        { /*Wiper parks*/
          rbi_RealParkContact_g = 1;
          rbi_SimulateParkContact_g = 0;
          rbi_WiperStarted_g = 0;
        }
      }
      else
      {
        rb_parkpositioncounter_s++;
      }
    }

    /*VCO_49 Logging issue*/
    if (rbi_SimulateParkContact_g>0)
    {
      if (WaitForParkContact_counter < cw_CLEARWIPE_DELAY_s)
      {
        WaitForParkContact_counter++;
      }
      else
      {
        if (SimulateParkContact_counter < 100) /*Multiply with 10ms*/
        {
          rbi_WiperStarted_g = 0;
          rbi_RealParkContact_g = 0;
          SimulateParkContact_counter++;
        }
        else
        {
          rbi_RealParkContact_g = 1;
          SimulateParkContact_counter=0;
          rbi_SimulateParkContact_g = 0; /*Reset Simulated Park Contact*/
          WaitForParkContact_counter = 0;
        }
      }
    }
    else
    {
      SimulateParkContact_counter=0;
      WaitForParkContact_counter = 0;
    }

    allocate_WiperMotorVariables();
  }

}



static void allocate_PartNumber(void)
{
#ifdef ___PHYSICAL_STACK_CALC__
  framecounter_for_PartNo = 2;
#endif
  if (framecounter_for_PartNo==0)
  {
    /*VCO_48 First frame is set in ApplLinInit()*/
    /* 0x02=Index, 0x42='B'*/
    l_u16_wr_PartNumberRSMFord_1( (( (( (word)(EEPR_FirstPrefixOfPartNumber) )<<8)&0xFF00U )+0x0002U) );
    /*0x56='V', 0x36=6*/
    l_u16_wr_PartNumberRSMFord_2( ( (((word)(EEPR_ThirdPrefixOfPartNumber) )<<8)&0xFF00U )\
                                 +(  ((word)(EEPR_SecondPrefixOfPartNumber)    )&0x00FFU ) );
    /*          0x54='T'*/
    l_u16_wr_PartNumberRSMFord_3( ((word)(EEPR_FourthPrefixOfPartNumber)) &0x00FFU  );
    l_u16_wr_PartNumberRSMFord_4(0x0000);
    framecounter_for_PartNo++;

  }
  else if (framecounter_for_PartNo==1)
  {
    l_u16_wr_PartNumberRSMFord_1(0x3103); /* 0x03=Index, 0x31=1*/
    l_u16_wr_PartNumberRSMFord_2(0x4437); /*0x37=7, 0x44='D'*/
    l_u16_wr_PartNumberRSMFord_3(0x3435); /*0x35=5, 0x34=4 */
    l_u16_wr_PartNumberRSMFord_4(0x0037); /*0x37=7 */
    framecounter_for_PartNo++;
  }
#ifdef ___PHYSICAL_STACK_CALC__
  else if (framecounter_for_PartNo >=2)
  {
    runtime_stack_calc();
    l_u16_wr_PartNumberRSMFord_1(segment_start_address_margin); /* 0x03=Index, 0x31=1*/
    l_u16_wr_PartNumberRSMFord_2( ((unsigned char)(*(segment_start_address_margin2+0x0000))&0x00FF)\
                               +((((unsigned char)(*(segment_start_address_margin2+0x0001)))<<8)&0xFF00) );
    l_u16_wr_PartNumberRSMFord_3( ((unsigned char)(*(segment_start_address_margin2+0x0002))&0x00FF)\
                               +((((unsigned char)(*(segment_start_address_margin2+0x0003)))<<8)&0xFF00) );
    l_u16_wr_PartNumberRSMFord_4( ((unsigned char)(*(segment_start_address_margin2+0x0004))&0x00FF)\
                               +((((unsigned char)(*(segment_start_address_margin2+0x0005)))<<8)&0xFF00) );
    /***************************************/
  }
#endif
  else
  {
    /* 0x04=Index, 0x41='A'*/
    l_u16_wr_PartNumberRSMFord_1( (( (( (word)(rb_Teilenummerindex2_g) )<<8)&0xFF00U )+0x0004U) );
    l_u16_wr_PartNumberRSMFord_2((word)(rb_Teilenummerindex_g)&0x00FF);
    l_u16_wr_PartNumberRSMFord_3(0x0000);
    l_u16_wr_PartNumberRSMFord_4(0x0000);
    framecounter_for_PartNo=0;
  }
}

static void allocate_PotiAndWipingMode(void)
{
  static byte rb_IntervalOnOndelay_mg;

  /*  if (l_bool_rd_Terminal_15() == TRUE)  not used for Ford*/
  {
    if (rb_IgnitionOndelay_mg < 250)
    {
      rb_IgnitionOndelay_mg++;
    }
  }

/*VDR_344 Update Potiincrementblocking due to two additional Signals: Terminal_15, IntermittentPos*/
  if (l_bool_rd_RainSensorActive()!= FALSE) /*copy automatic wiping mode*/
  {
    if (rbi_RainsensorDisabled_g == FALSE)
    {
      rbi_AutomaticWipingMode_g = TRUE; /*Rainsensor active!*/
    }
    else
    {
      rbi_AutomaticWipingMode_g = FALSE; //Rainsensor off!
    }

    if (rb_IntervalOnOndelay_mg > 3)   //50ms Delay fuer Potiinkrementierungsblocking!
    {
      rbi_LSS_Interval_g = TRUE;
    }
    else
    {
      rb_IntervalOnOndelay_mg++;
    }
  }
  else
  {
    rw_AfterWWSWipeCounter_mg = 50000;          //Direktbitdelay bei "Kl15 Aus" hochsetzen!
    rbi_AutomaticWipingMode_g = FALSE; //Rainsensor off!
    rbi_LSS_Interval_g = FALSE;
    rb_IntervalOnOndelay_mg = 0;
  }
}

/**************************************************************************
Syntax   : void  GetLeWWS(void)
Object   : GetLeWWS()
Parameters : none
Return  : none
Calls   : in main.c cyclic 10ms
***************************************************************************
Inputs validation conditions:
none
***************************************************************************
Pseudo-code : schreibt die Eingangsdaten vom Schaltermoduls von den
entsprechenden Puffern des Vector Bus Treiber in die RAM-Zellen und
setzt die internen Daten gemaess SRS um.
**************************************************************************/
void GetLeWWS(void) /*Information from SCS*/
{
  static  word rw_NoMasterCounter_mg;

  rbi_Ignition_g = TRUE;

  /*VCO_44 Partnumber read out, other than Ford --> Can be written continuously*/
  l_u16_wr_PartNumberRSM_1(0x3731); /*VDR_368 0x31=1, 0x37=7*/
  l_u16_wr_PartNumberRSM_2(0x3544); /*VDR_368 0x44=D, 0x35=5*/
  l_u16_wr_PartNumberRSM_3(0x3734); /*VDR_368 0x34=4, 0x37=7*/

  if (l_flg_tst_RSM_L8_FrP02())    /*Master Request?*/
  {
    l_flg_clr_RSM_L8_FrP02();                 /*delete flag*/
    allocate_PartNumber();
  }

  if (l_flg_tst_BCM_L8_FrP01())               /*Master Request?*/
  {
    l_flg_clr_BCM_L8_FrP01();                 /*delete flag*/
    rbi_LightSensitivityRecieved_g = TRUE;
    if (l_bool_rd_StalkInFrontWashPos() == TRUE)   /* Washpump activ?*/
    {
      rbi_WashingActive_g = TRUE;             /* set Washing activ bit */
    }
    else if (rbi_ParkPosition_g == TRUE)          /* In Parkposition ? */
    {
      rbi_WashingActive_g = FALSE;              /* Clear Washing active bit */
    }
    else
    {
      /*Do nothing, Dummy-else for Misra Check*/
    }
    
    allocate_PotiAndWipingMode();
    
    rb_speed_in_kmh_g  = l_u8_rd_VisibilityVehicleSpeed();                           // set speed
    
    check_for_internal_RS_Mapping();
    
    if (rb_PotiStageFromBox_g<=(EEPR_SensitivityBarrier+1))
    {
      rbi_ReduceIntANDOvrMemoryLoading_g =1;
    }
    else
    {
      rbi_ReduceIntANDOvrMemoryLoading_g =0;
    }
    if (rb_PotiStageFromBox_g<=EEPR_SensitivityBarrier)
    { /*Less sensitivity for lower sensitivities*/
      rbi_LessSensitivityLowSCSPotiStage_g =1;
    }
    else
    {
      rbi_LessSensitivityLowSCSPotiStage_g =0;
    }
    
    /*VDR_368: Ford Part Number*/
    rbi_CarCode_recieved_g = TRUE;
    
    check_CarCode();
    switch_Tropf_Anzahl_AND_Sig_Anzahl();
    check_WindshieldTransm();
    switch_Stalkinformation();
    
    /* Datas to switch off the sensor*/
    rw_NoCommunicationCounter_g = 0;        // reset no communication counter
    rbi_ConnectedToMaster_g = 1;            // set connected to Master Bit
    rw_NoMasterCounter_mg = 0;
    
  }
  else  //keine neue Master Nachricht!
  {    // check if system is on -> to switch off
    if (((rw_NoCommunicationCounter_g > 10))||(rbi_LowVoltage == 1))
    { /*Zuendung Aus ODER auserhalb von Betriebsspannungsbereich*/
      rw_NoMasterCounter_mg = 0;  //Zaehler zuruecksetzen
    }
    else
    {
      if (rw_NoMasterCounter_mg < 1000)  //Zaehler um zu pruefen ob Kommunikation korrekt funktioniert
      {
        rw_NoMasterCounter_mg++;      //Zaehler fuer fehlende Masternachricht incrementieren
      }
    }

    if (rw_NoCommunicationCounter_g < CW_LIN1_3_IDLE_TIMOUT)  // No Communication Counter Higher than
    {
      rw_NoCommunicationCounter_g ++;     // increment No Communication Counter
      rbi_GotoSleep_g = FALSE;         // Was Connected to Master
    }
    else
    {
      rbi_GotoSleep_g = TRUE;         // Was Connected to Master
      rbi_ConnectedToMaster_g = FALSE;         // clear connected to Master
    }
  }
  rb_LSPotiStage_g = cab_LS_PotistageMapping_mg[rb_LightSensorCoding_g];                   // set LSS to 3
}
/**************************************************************************
Syntax   : void  GetLsWWS(void)
Object   : GetLsWWS()
Parameters : none
Return  : none
Calls   : in main.c cyclic 10ms
***************************************************************************
Inputs validation conditions:
none
***************************************************************************
Pseudo-code : schreibt die Eingangsdaten vom Wischermotorin von den
entsprechenden Puffern des Vector Bus Treiber in die RAM-Zellen und
setzt die internen Daten gemaess SRS um.
**************************************************************************/
void GetLsWWS(void)
{
  static byte rb_No_BCM_L8_FrP03_Counter;

  if (l_flg_tst_BCM_L8_FrP03())                  /*Wischermotor request*/
  {
    l_flg_clr_BCM_L8_FrP03();                  //loesche flag
     
    /* Store actual value for next cycle */
    rbi_WiperInWipingArea = l_bool_rd_WiperInWipingArea_s();
    rw_NoCommunicationCounter_g = 0;        // reset no communication counter
    rbi_ConnectedToMaster_g = 1;                   // set connected to Master
    rb_No_BCM_L8_FrP03_Counter = 0;
  }
  else if (l_flg_tst_WMM_L8_FrP00())
  {
    l_flg_clr_WMM_L8_FrP00();

    /* Store actual value for next cycle */
    rbi_WiperInWipingArea = l_bool_rd_WiperInWipingArea_WWM();

    rw_NoCommunicationCounter_g = 0;        // reset no communication counter
    rbi_ConnectedToMaster_g = 1;                   // set connected to Master
    rb_No_BCM_L8_FrP03_Counter = 0;
  }
  else if (rb_No_BCM_L8_FrP03_Counter < 40)
  {
    rb_No_BCM_L8_FrP03_Counter ++;
  }
  else
  {
    /*VDR_344 Dummy Else for QA-C*/
  }
    check_for_SteeringColumnSwitch();
 }

/**************************************************************************
Syntax   : void  CopyRLSData(void)
Object   : CopyRLSData()
Parameters : none
Return  : none
Calls   : in main.c
***************************************************************************
Inputs validation conditions:
none
***************************************************************************
Pseudo-code : schreibt die Ausgangsdaten des Sensors in den
Ausgangsdatenpuffer des Vector Bus Treiber und setzt die internen Daten
gemaess SRS um.
**************************************************************************/

void CopyRLSData(void)
{

  static byte rb_OutOffParkCounter_mg;
 
  Check_StartupActiveErrors();
  
  LIN_CalculateFixIntervalTime();
  
  if((rb_IgnitionOndelay_mg<50)/*||(rbi_ConnectedToMaster_g = 0)*/)
  {
    rw_rain_intensitiy_g = 0;
    rw_AfterRSWipeCounter_mg = 50000;
  }
  if(rbi_RealParkContact_g == FALSE)     //Auserhalb vom Parkkontakt
  {
    if (rb_OutOffParkCounter_mg > cb_DEPRESSED_PARK_DEBOUNCE_s) //debounce the parkposition for depressed park
    {
      rw_AfterWWSWipeCounter_mg = 0;      //Direktbit (depressed park) zuruecksetzen
    }
    else
    {
      rb_OutOffParkCounter_mg ++;
    }
  }
  else
  {
    rb_OutOffParkCounter_mg = 0;
    if(rw_AfterWWSWipeCounter_mg < 50000) //Delay fuer Direktbit (depressed park) hochzaehlen
    {
      rw_AfterWWSWipeCounter_mg++;
    }
  }
  
  if(rw_AfterRSWipeCounter_mg < 50000)  //Delay fuer Tunnelwischung hochzaehlen
  {
    rw_AfterRSWipeCounter_mg++;
  }
  
  
  if (l_flg_tst_RSM_L8_FrP00())                            // pruefen ob eigene Nachricht korrekt empfangen wurde
  {
    l_flg_clr_RSM_L8_FrP00() ;                          // loeschen des Pruefflags
    rbi_oneTimeAnswerd_g = TRUE; /*VDR_368 Error Failure*/
    rw_NoCommunicationCounter_g = 0;              // reset no communication counter
    rbi_ConnectedToMaster_g = 1;                   // set connected to Master
  }

  
  
 
  check_for_TunnelWipe();
  check_for_RainSensorDirectMode();
  check_for_errors();
  set_light_value();
  set_RainSensorDirectMode();
  
  
  /*VDR_368: Reset Partnumbers when No CarCode has been received*/
  if(rbi_CarCode_recieved_g==FALSE)
  {
    l_bool_wr_AdaptErrRainSens(0);
    l_bool_wr_AdaptErrRainSensActive(TRUE);
    l_u16_wr_PartNumberRSM_1(0x0000);
    l_u16_wr_PartNumberRSM_2(0x0000);
    l_u16_wr_PartNumberRSM_3(0x0000);
  }
   
#if defined (ASIC_TEST)
  CopyRLSDataAsic();
#endif  
  
  rb_WDG_BusTaskCounter_g++;      //increment test counter for bus
}


void ApplLinInit(byte rb_LIN_State_l)
{
  
  
  rw_AfterRSWipeCounter_mg = 50000;
  rw_AfterWWSWipeCounter_mg = 50000;          //Direktbitdelay bei Kl15 Aus hochsetzen!
  sci_init(rb_LIN_State_l);
  rbi_RealParkContact_g = TRUE;
  rbi_ParkPosition_g = TRUE;
  rb_PotiStageFromBox_g = 3; /*VDR_408 use init value*/
  rb_AnyErrorCounterDebounce_mg = 200;
  
  framecounter_for_PartNo = 1; /*First frame needs to be set here*/

}                                              


__callt void ApplLinSlavePreCopy(byte rb_MessageID_l)    /* callt function (faster */
{
  if((rb_MessageID_l == (rb_IDRLSs_01_g & 0x3F))&&((rb_RSControlFlags_g & 0x80) == FALSE))
  {
  //  l_bool_wr_RLS_ResponseError(rbi_latched_ResponseError_mg);
    rbi_latched_ResponseError_mg = FALSE;
  }
  else
  {
    if((rb_MessageID_l == (rb_IDFSs_01_g & 0x3F))&&((rb_RSControlFlags_g & 0x80) != FALSE))
    {
      /* send response error in FS message if only humidity sensor is active */
 //     l_bool_wr_FS_ResponseError(rbi_latched_ResponseError_mg);
      rbi_latched_ResponseError_mg = FALSE;
    } 
  }
}

static void LIN_CalculateFixIntervalTime(void)
{
  byte rb_VehiSpeedIntervalTimeSect_l;


  // wipe Decision and Set!
  if ((rbi_Ignition_g == TRUE)  && (rbi_RainsensorDisabled_g == TRUE))
  {
    if (l_bool_rd_RainSensorActive() == TRUE)
    {
      //Calculation of Delay
      if (rb_speed_in_kmh_g <= 5)
      {
        rb_VehiSpeedIntervalTimeSect_l = 8;
      }
      else if (rb_speed_in_kmh_g <= 20)
      {
        rb_VehiSpeedIntervalTimeSect_l = 7;
      }
      else if (rb_speed_in_kmh_g <= 40)
      {
        rb_VehiSpeedIntervalTimeSect_l = 6;
      }
      else if (rb_speed_in_kmh_g <= 60)
      {
        rb_VehiSpeedIntervalTimeSect_l = 5;
      }
      else if (rb_speed_in_kmh_g <= 85)
      {
        rb_VehiSpeedIntervalTimeSect_l = 4;
      }
      else if (rb_speed_in_kmh_g <= 105)
      {
        rb_VehiSpeedIntervalTimeSect_l = 3;
      }
      else if (rb_speed_in_kmh_g <= 120)
      {
        rb_VehiSpeedIntervalTimeSect_l = 2;
      }
      else if (rb_speed_in_kmh_g <= 150)
      {
        rb_VehiSpeedIntervalTimeSect_l = 1;
      }
      else
      {
        rb_VehiSpeedIntervalTimeSect_l = 0;
      }

   /*VDR_368 (VDR_360) Intervaltimes need to be reached and fail save*/
      if ( (rw_AfterWWSWipeCounter_mg>>4) >= (cab_FixIntervaltimes_mg[(\
               (rb_PotiStageFromBox_g>7)? 3:(rb_PotiStageFromBox_g>>1) )][rb_VehiSpeedIntervalTimeSect_l]))
      {
        rbi_TunnelWipe_mg = TRUE;
      }
    }
  }
/* PRQA S 5540 2 */ /* << Maximum Nesting of Control Structures:\
 * It is not recommended to reduce this function>>*/
}
