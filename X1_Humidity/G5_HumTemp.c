/* PRQA S 3116 EOF *//*<< 3116:#pragma needed for IAR compiler and MISRA >>*/
/* PRQA S 0861,0862,5560,5830 EOF */ /* << Compiler specific Includes cannot be analysed by QA-C>> */
/* PRQA S 1006 EOF */ /* << Assembler Code is ONLY used for NOPs>> */
/* PRQA S 0434 EOF */ /* << Compiler specific include file can not be analysed by QA-C>> */
/* PRQA S 0436,0781 EOF */ /* << have to be used this way to access the ports>> */
/* PRQA S 2201,2215,2217,715 EOF *//*<< Indentation and line length  >>*/
/* PRQA S 5900,5565,5540 EOF *//*<< Data needs to be verified  >>*/
/* PRQA S 0759 EOF *//*<< 0759:union needed to reduce RAM usage >>*/
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
/* MODULE SPECIFICATION
* %PCMS_HEADER_SUBSTITUTION_START:%
* Name:
* %PID: RLS:G5 HUMTEMP C-103456502X4196X4.A-VIT_SOURCE;1.19 %
* %PM: G5_HumTemp.c %
* Description:
* %PD: Item G5 HUMTEMP C-103456502X4196X4.A %
*
******************************************************************************/
/* %PCMS_HEADER_SUBSTITUTION_END:% */
/******************************************************************************/
/*   MODULE:  HUMTEMP                                                         */
/*   FILE:    HumTemp.c                                                       */
/******************************************************************************/
/*                                                                            */
/******************************************************************************/
/* History                                                                    */
/*----------------------------------------------------------------------------*/
/* Date      VDR_Number  Name    Description                                       */
/*----------------------------------------------------------------------------*/
/* 13.07.11  VDR_684     AL       do shift of Temptick earlier in programm*/
/* 23.02.11  RLS_VCO_96  AL       FS_Implement Selfheating Compensation */
/* 22.11.10  VDR_600     AL       limit dewpoint to temperature*/
/* 19.10.10  VC0_081     AL       dynamic compensation parameter temperature dependend*/
/* 23.07.10  VDR_548     AL       improve accuracy of dewpoint*/
/* 16.Jul10  VDR_558     FS       Correction due to implementation to NurFeuchte*/
/* 15.07.10  VDR_548     AL       improve accuracy of dewpoint*/
/* 14.07.10  VCO_060     AL       implement dynamic optimisation*/
/* 01.Jun10  VDR_529     FS       define for SensirionModule_OFF corrected */
/* 17.May19  VDR_520     AL       workaround that errorflag shows only 
the basic error*/
/* 11.May10  VDR_518     FS       Implement Define for NOPs. TESTED OK with Atmel*/
/* 10.May10  VCO_46      FS       Update due to NOP*/
/* 03.05.10  VDR_512     AL       Polyspace improvement*/
/* 23.Apr.10 VDR_501     FS       Compiler Warning eliminated*/
/* 05.03.10  VDR_463     AL       New Failure Detection correction*/
/* 23.02.10  VCO_037     AL       external needed Variables and new failure
modes for out of rang */
/* 20.01.10  VDR_427     AL       Improve linearisation for low HumTicks*/
/* 05.11.09  VDR_393     FS       Misra-Check with QA-C due to functional behavior*/
/* 04.11.09  VDR_392     FS       Update to ATA6617 environment*/
/* 15.10.09  VDR_386     AL       RLS_Audi_KS_Improvments in Dewpoint
calculation, and Port Assignment for ATMEL6617 */
/* 02.07.09  VDR_346   AL       implement V4 Parameterset*/
/* 06.02.08  VDR_133     AL      switchin active supply of SHT Module off!*/



/*29.07.2014 VDR_737    NB In case of negative temperature the sensor sends wrong value */
/* 18.07.2014 VCO_149     NB      Measurement of HT supply using ADC */
/* 24.07.2014 VCO_149     NB      Measurement of HT supply using ADC */
/* 14.11.2014 VCO_196     NB     Improve the error detection of SHT module in case of short to ground */
/* 17.11.2014 VCO_196     NB     Improve the error detection of SHT module in case of short to ground */
/* 09.12.14   VCO_205     NB     Read serieal number of SHT module */
/* 24.02.2015 VDR_850     NB     After removing HT module from sensor the HT error displayed after 40s in the LIN Bus */
/* 11.05.2015 VDR_877     NB     Keep clock and data line of SHT module high when there is no communication */
/* 19.06.2015 VDR_870     NB     Set all unused IO ports of microcontroller to Output low */
/* 25.05.2015 VDR_877     NB     Sensor reset when SHT module is not connected */
/* 01.06.2015 VDR_877     NB     Sensor reset when SHT module is not connected */
/*13.07.2015  VDR_868     NB     QAC and Polyspace fixing for SW009 Release  */
/*07.10.2015  VCO_277    SP      Modify the SHT Error Debonunce Jitter as an EEPROM parameter */
/*13.11.2015  VDR_925     NB     Humidity value shall not be considered if the status bit is not valid */
/*03.12.15    VDR_939         NB      Improvement of SHT module measurement */ 
/*30.03.2016  VDR_967     NB     Set the supply of SHT module to output low if SHT module not used */ 
/*12.05.2016  VDR_901     NB     Init Value of Dew point changes to -40 degrees and LIN initialisation */ 

/******************************************************************************/
/**
* \mainpage Interface Specification for the Humidity Temperature Module "HUMTEMP Modul"
<!-- * \htmlinclude spic.html           -->
* \section intro_sec Introduction
*
* This document is generated automatically with doxygen, with the help of tags in
* the source code.
*
* \section install_sec Description of the different tabs
*
* \subsection step1 Main Page:
* The main tab contains a small introduction over the contents of this file.
*
* \subsection step2 Module / Interface Specification:
* Gives an overview over the Interface should be renamed to Interface Specification, but at the moment
*       it is not possible to rename it.
*
* \subsection step3 Data Structures:
* The Data Structures tab contains a brief description of all specified data structures and data fields.
*
* \subsection step4 Files:
* The Files tab contains a brief description of all module files.
*
* \subsection step5 Related Pages:
* The Related Pages contains all existing pages for the HUMTEMP module e.g. Integration Guidline, Compile Options,... .
*
* \file HumTemp.c
* \brief C File for the Humidity Temperature Module "HUMTEMP Modul".
*
* This module managed the communication between the Application and the Sensirion SHT1x
* Read TemperatureTicks and HumidityTicks from Sensirion module \n
* Communication error handling \n
* Calculates Temperature, relative Humidity and dew point \n
*
* <!--  -->
* \b Source:     humtemp.c
* \version       1.14
* \author        laegler
* \author        SBA294
* \date          17-APR-2007 19:19:05
*
* <!--  -->
*/


/******************************************************************************/
/*                  Integration Guidline                                      */
/******************************************************************************/

/**
* \page integration Integration Guidline
* </p>
* <h2>Function calls</h2>
* <p>
* The application calls the Init function HumTemp_Init() once during initialization
* </p>
* <p>
* The task HumTemp_Handler() must by called cyclic e.g. ever 10ms
* </p>
* <p>
* HumTemp_Heater() and HumTemp_GetHeaterStatus() are functions used for diagnostics for more information
* about the heater refer to the datasheet of the Sensirion SHT1x module.
* </p>
* <h2>Output variables</h2>
* <p> The main output variables are rb_Humidity_raw_g, rw_Temperature_g, rw_DewPoint_g and the
* error flag rbi_HumTempComError_g <br>
* The other exported variables are mainly for diagnosis reason
* </p>
*/

/******************************************************************************/
/*                             Compile options                                */
/******************************************************************************/

/**
* page compileoptions Compile options
* <h2>#define _EMULATOR_</h2>
* <p>
* Compile option if emulator without SHT1x Module is used <br>
* HumTicks and TempTicks are not read from the Sensirion module,<br>
* Default values for the Ticks are assigned in HumTemp_Init(),<br>
* an error because of a missing module is not generated.<br>
* <b>Compile option must not be used for final code!</b>
* </p>
*
* <h2>#define _TEMP12BIT_</h2>
* <p>
* Compile option to read temperature with 12bit instead of 14bit <br>
* In this mode, the Sensirion module provides the result faster<br>
* <b>It is highly recommended to use his mode.</b>
* </p>
*/

/** \brief Compile option if emulator without SHT1x Module is used */
/*#define  _EMULATOR_*/
/** \brief Compile option to read temperature with 12bit instead of 14bit */

/******************************************************************************/
/*              Include of common and projekt definitions header              */
/******************************************************************************/
#include "ior5f109be.h" /* Standarddefinitions */
#include "ior5f109be_ext.h" /* Standarddefinitions */
#include "G5_projectDefs.h"
#include "G5_io_sen.h" /* definition for output */
#include "G5_E2ProjectConfig.h"
#include "G5_Appli_timer.h"
#include "G5_Appli_Lowinit.h"


/******************************************************************************/
/*                      Include extenal modul header                          */
/******************************************************************************/




/******************************************************************************/
/*                      Include internal modul header                         */
/******************************************************************************/

/** \brief G5_HumTemp.h checkes this define to see where the include comes from */
#include "G5_HumTemp.h" /* Own includefile */

#ifdef __NUR_FEUCHTE_ /*Use for NurFeuchte projects these defines as global defines due to __flash keyword*/
/** \brief Lookup-table for ( log10(rh)-2/0.4343 ) *(-100/2) */

__flash unsigned char cb_log10LookUpTable1_00to17_mg[18] = {255,255,230,210,196,184,175,168,161,155,150,145,\
  141,137,133,130,126,123};
/** \brief Lookup-table for ( log10(rh)-2/0.4343 ) *(-100/2) */
__flash unsigned char cb_log10LookUpTable2_18to58_mg[41] ={241,235,230,225,221,216,212,208,204,200,197,193,\
  190,186,183,180,177,174,171,169,166,163,161,158,156,154,151,149,147,145,143,141,139,137,135,133,131,129,127,126,124};
/** \brief Lookup-table for ( log10(rh)-2/0.4343 ) *(-100/2) */
__flash unsigned char  cb_log10LookUpTable4_59to108_mg[50] ={/*244,*/241,237,234,231,228,225,222,219,216,213,210,\
  207,204,202,199,196,194,191,188,186,183,181,178,176,173,171,169,166,164,162,160,157,155,153,151,149,147,145,143,\
    141,139,137,135,133,131,129,127,125,123,121};/*VDR_548 shifting table*/
/** \brief Lookup-table for ( log10(rh)-2/0.4343 ) *(-100/2) */
__flash unsigned char cb_log10LookUpTable8_109to200_mg[92] = {/*243,*/239,236,232,228,225,221,218,214,211,208,204,\
  201,198,194,191,188,185,182,179,175,172,169,166,163,160,157,154,151,148,146,143,140,137,134,131,129,126,123,120,\
    118,115,112,110,107,105,102,99,97,94,92,89,87,84,82,79,77,75,72,70,67,65,63,60,58,56,53,51,49,47,44,42,40,38,36,\
      33,31,29,27,25,23,21,18,16,14,12,10,8,6,4,2,0,0};  /*VDR_548 shifting table*/
#endif
/******************************************************************************/
/*                   Definition of local module constants                     */
/******************************************************************************/

/******************************************************************************/
/*  Comment:  Parameter for start_measurement function                        */
/*  Range  :  0...1                                                             */
/** \brief Parameter for start_measurement: send request to measure temperature */
#define TEMP    0
/** \brief Parameter for start_measurement: send request to measure humidity */
#define HUMI    1

/******************************************************************************/
/*  Comment:  Parameter for s_read_byte function                              */
/*  Range  :  0 . . . 1                                                             */
/** \brief Parameter for s_read_byte: send no acknowledge -> end of transmission */
#define noACK   0
/** \brief Parameter for s_read_byte: send acknowledge */
#define ACK     1

#ifdef SENSIRION_SHT21_USED
/******************************************************************************/
/*  Comment:  Command defines for SHT1x module                                */
/*  Range  :  0...255 */  
/*  SHT21x Command to write address */
#define I2C_ADDR_W    0x80
/*  SHT21x Command to read  address  */
#define I2C_ADDR_R    0x81
/* brief SHT1x Command to read status register */
#define STATUS_REG_W    0xE6
/*brief SHT1x Command to write status register */
#define STATUS_REG_R    0xE7
/* brief SHT1x Command to measure temperature */
#define MEASURE_TEMP    0xF3
/*brief SHT1x Command to measure humidity */
#define MEASURE_HUMI    0xF5
/* brief SHT1x Command to reset chip */
#define SOFT_RESET           0xFE
/******************************************************************************/

/*  Comment:  Mask defines for status register of SHT1x module                */
/*  Range  :  0 . . . 255                                                           */
/** \brief status register mask for low reolution mode */
#define cb_SR_LOWRESOLUTION_mg   0x01
/** \brief status register mask for low reolution mode (negated)*/ /*VDR_393*/
#define cb_SR_NEG_LOWRESOLUTION_mg 0x01 /*VDR_393*/
/** \brief status register mask for no otp load */
#define cb_SR_NO_OTP_RELOAD_mg   0x02
/** \brief status register mask for heater */
#define cb_SR_HEATER_mg     0x04
/** \brief status register mask for heater (negated due to MISRA) *//*VDR_393*/
#define cb_SR_NEG_HEATER_mg 0xFB /*VDR_393*/


#define cb_PART_1     1
#define cb_PART_2     2

/******************************************************************************/
#else
/******************************************************************************/
/*  Comment:  Command defines for SHT1x module                                */
/*  Range  :  0...255                                                           */
/** \brief SHT1x Command to read status register */
#define STATUS_REG_W    0x06
/** \brief SHT1x Command to write status register */
#define STATUS_REG_R    0x07
/** \brief SHT1x Command to measure temperature */
#define MEASURE_TEMP    0x03
/** \brief SHT1x Command to measure humidity */
#define MEASURE_HUMI    0x05
/** \brief SHT1x Command to reset chip */
#define RESET           0x1e

/******************************************************************************/
/******************************************************************************/
/*  Comment:  Mask defines for status register of SHT1x module                */
/*  Range  :  0 . . . 255                                                           */
/** \brief status register mask for low reolution mode */
#define cb_SR_LOWRESOLUTION_mg   0x01
/** \brief status register mask for low reolution mode (negated)*/ /*VDR_393*/
#define cb_SR_NEG_LOWRESOLUTION_mg 0xFE /*VDR_393*/
/** \brief status register mask for no otp load */
#define cb_SR_NO_OTP_RELOAD_mg   0x02
/** \brief status register mask for heater */
#define cb_SR_HEATER_mg     0x04
/** \brief status register mask for heater (negated due to MISRA) *//*VDR_393*/
#define cb_SR_NEG_HEATER_mg 0xFB /*VDR_393*/

/******************************************************************************/
#endif

/* VDR_850 */
/*  Comment:  Defines for HumTemp Handler and error management                */
/** \brief debounce value for error mode */
#define cb_ERROR_DEJITTER_g     rb_SHTErrorDebounceJitter_g 
/** \brief Timout for conversion 200ms */
#define cb_CONVERSIONTIMEOUT_s   3
/** \brief Loop time for periodic measurement 850ms (must be greater than 63) */
#define cb_MEASUREPERIODE_mg     85
/** \brief State to jump after failed communication */
#define cb_JUMP_AFTER_ERROR_mg   cb_MEASUREPERIODE_mg-1

/******************************************************************************/
/*                     Definition of local module macros                      */
/******************************************************************************/
#ifdef SENSIRION_SHT21_USED

#define   S_WAIT_3NOPS    s_wait(1)
#define   S_WAIT_3_5NOPS  s_wait(3)
#define   S_WAIT_9NOPS    s_wait(9)
#define S_WAIT_3NOPS_ATA_ONLY /*do nothing*/  

#else
#define   S_WAIT_3NOPS    s_wait(1)
#define   S_WAIT_3_5NOPS  s_wait(3)
#define   S_WAIT_9NOPS    s_wait(3)
#define S_WAIT_3NOPS_ATA_ONLY /*do nothing*/  
#endif


/** \brief Macro function to set data line as input */

#define DATA_IN     po_DSHT71_1_DATA_g = INPUT
/** \brief Macro function to set data line as output */
#define DATA_OUT    po_DSHT71_1_DATA_g = OUTPUT
/** \brief Macro function to set clock line as output */
#define CLK_OUT     po_DSHT71_1_CLK_g = OUTPUT
/** \brief Macro function to set clock line as input */
#define CLK_IN      po_DSHT71_1_CLK_g = INPUT

/** \brief Macro to access portpin for data line */
#define DATA po_SHT71_1_DATA_g 
/** \brief Macro to access portpin for clock line */
#define SCK  po_SHT71_1_CLK_g

/** \brief Macro function to set clock line high */
#define SHT_SCK_HIGH  SCK=1

#define SET_I2C_DATA  DATA=1 
#define CLR_I2C_DATA  DATA=0
#define GET_I2C_DATA  DATA


/******************************************************************************/
/*                     Definition of local module types                       */
/******************************************************************************/

/** \brief u32 unsigned 32-bit variable for internal calculation */
typedef unsigned long u32;

/******************************************************************************/
/*                   Definition of local module variables                     */
/******************************************************************************/
 SHORT_MEMORY  Flag uF_Humi_g; 
/** \brief TaskStatus for measurement sequence */
static unsigned char rb_TaskStatus_s;
#ifdef SENSIRION_SHT21_USED
/** \brief temp value containing Cheksum during calculation */
static unsigned char rb_CalcChkSum_mg[2];
#else
/** \brief temp value containing Cheksum during calculation */
static unsigned char rb_CalcChkSum_mg;
/** \brief Calculated checksum over the transmission */
static unsigned char rb_ChkSumCalculated_mg;
#endif
/** \brief SHT11 Status register */
static unsigned char rb_StatusReg_mg;

unsigned char rb_SHT_SupplyRetryCounter_g;
unsigned char rb_SHT_ComErrRetryCounter_g;
/**
* \ingroup external
* \brief exported variable containing Humidity.
* (Factor 0.5 Offset -0.5 [eg. 201 equals 100%%rH]) */
 unsigned char rb_Humidity_raw_g;  /*VCO_060 use only byte */
/**
* \ingroup external
* \brief exported variable containing Humidity with compensated dynamic.
* (Factor 0.5 Offset -0.5 [eg. 201 equals 100%%rH]) */
 unsigned char rb_Humidity_g;  /*VCO_060 use only byte */
/**
* \ingroup external
* \brief exported variable containing Temperature.
* (Factor 0.1 Offset -39.6 [eg. 596 equals 20GradC]) */
 unsigned int rw_Temperature_g;
 unsigned int rw_Temperature_raw_g;
#ifdef SENSIRION_SHT21_USED
 unsigned char SHT21xSerialNumber[8];
#endif

/**
* \ingroup external
* \brief exported variable containing Dewpoint.
* (Factor 0.1 Offset -39.6 [eg. 596 equals 20GradC]) */
 unsigned int rw_DewPoint_g;
/**
* \ingroup external
* \brief exported variable containing communication error code */
 unsigned char rb_HumTemp_ErrorCode_g;

/**
* \brief Temperature [Ticks] 14 Bit (TGradc = rw_TempTicks_g * 0.04-40).
* rw_TempTicks_g is the 14bit sensor readout for Temperature. Range 0-3fff*/
 unsigned int rw_TempTicks_g; /*VCO_037 external needed*/
/**
* \brief Humidity [Ticks] 12 Bit (TGradc = rw_TempTicks_g * 0.04-40)
* rw_HumiTicks_g is the 12bit sensor readout for Temperature. Range 0-0fff*/
 unsigned int rw_HumiTicks_g; /*VCO_037 external needed*/
#ifndef __NUR_FEUCHTE_

#ifdef SENSIRION_SHT21_USED
#else
/**
* \brief Filter to create the ramp up for the offset to the temperature*/
STATIC  unsigned int rw_TemperatureOffsettFilter_g;  /*RLS_VCO_96*/
/**
* \ingroup external
* \brief exported variable containing Temperature Rainsensor Selfheating is
*  substracted.
* (Factor 0.1 Offset -39.6 [eg. 596 equals 20GradC]) */  /*RLS_VCO_96*/
 unsigned int rw_CompensatedSelfheatTemperature_g;
/**
* \ingroup external
* \brief exported variable containing humidity Rainsensor Selfheating is
*  substracted.
* (Factor 0.5 Offset -0.5 [eg. 201 equals 100%%rH]) */
 unsigned char rb_CompensatedSelfheatHumidity_g;  /*RLS_VCO_96*/
#endif

/**
* \brief Humidity This variable shows how much temperature is compensated in 0.1K)*/
 unsigned char rb_negativeTemperatureOffset_g;   /*RLS_VCO_96*/
/**
* \brief Humidity This variable shows how much humidity is compensated in 0.5%RH)*/
 unsigned char rb_DeltaFTemp_g;   /*RLS_VCO_96*/


#endif




/**
* \ingroup external
* \brief Error mode debounce counter, exported to be read out in diag mode */
word rw_InErrorModeCounter_s;
/**
* \ingroup external
* \brief Error counter, increased on communication failure, exported to be read out in diag mode */
unsigned char rb_StaticHumTempErrorCounter_g;
/**
* \ingroup external
* \brief exported variable Error flag, will be written in DTC if set */
unsigned char rbi_HumTempComError_g;



/******************************************************************************/
/*                 Definition of local module constant data                   */
/******************************************************************************/

/******************************************************************************/
/*                     Definition of exported variables                       */
/******************************************************************************/

/******************************************************************************/
/*                   Definition of exported constant data                     */
/******************************************************************************/
/*void HumTemp_Init(void);
void HumTemp_Handler(void);
void HumTemp_Heater(unsigned char rb_HeaterStatus_l);
unsigned char HumTemp_GetHeaterStatus(void);*/

STATIC void s_softreset(void);      /* resets the sensor by a softreset */

/******************************************************************************/
/*                   Declaration of local module function prototyps           */
/******************************************************************************/

STATIC void s_wait(unsigned char value);
STATIC unsigned char s_write_byte(unsigned char value);    /*writes a byte on the Sensibus and checks the acknowledge*/
STATIC unsigned char s_read_byte(unsigned char ack); /*reads a byte form the Sensibus and
gives an acknowledge in case of "ack=1"*/
STATIC void s_transstart(void);      /* generates a transmission start */
//STATIC void s_connectionreset(void);  /* communication reset: DATA-line=1 and at least 9 SCK cycles */
STATIC void s_transstop(void);
#ifdef USE_READ_SHT_STATUSREGISTER___
STATIC unsigned char s_read_statusreg(unsigned char *p_value, unsigned char *p_checksum); /* reads the status*/
#endif                              /* register with checksum*/
#ifdef _DO_USE_RETURNVALUE_WRITE_STATUSREG
STATIC unsigned char s_write_statusreg(unsigned char *p_value); /* writes the status register */
#else
STATIC void s_write_statusreg(unsigned char *p_value); /* writes the status register */
#endif
STATIC unsigned char start_measurement(unsigned char mode);   /* transmit command to start measurement */
STATIC unsigned char m_finished(void);      /* checks if SHT1x has finished measurement */
STATIC unsigned char checksumOK(unsigned char rb_checksum_l);   /* compare calculated an read checksum */
STATIC void get_result(unsigned int *p_value, unsigned char *p_checksum); /* read measurement value with checksum */

STATIC unsigned int calc_dewpoint(unsigned int h,unsigned int TempTicks); /* calculate dewpoint */


STATIC void  SHT_SCK_LOW(void); 
STATIC void HumTempSensirionOFF(void); 
STATIC void HumTempSensirionON(void);  
#ifdef SENSIRION_SHT21_USED
STATIC byte SHT2x_GetSerialNumber(byte cb_part_l);
#else
STATIC void CalculatHumidityOffsett (void);   /*RLS_VCO_96*/
STATIC word dynamicCompensation(word rw_input_Humidity_l);/*VCO_060 function for dynamic compensation*/
#endif
/******************************************************************************/
/*                   Definition of local module functions                     */
/******************************************************************************/

/******************************************************************************/
/*                                                                            */
/*  Prototype:                                                                */
/*      void s_wait(unsigned char value)                                      */
/*                                                                            */
/*  Description:                                                              */
/*    This function creates a wait time for the I2C Interfcace                */
/*                                                                            */
/*  Input parameters:                                                         */
/*    value: byte to send (Range 0...0xff)                                    */
/******************************************************************************/

/**
* \brief This function creates a wait time for the I2C Interfcace  
*/
#ifdef SENSIRION_SHT21_USED
STATIC void s_wait(unsigned char value)
{
  unsigned short int cnt = (value);
  
  for (cnt=cnt;cnt>0;cnt--)
  {
    NOP();  
    
  }
}
#else

STATIC void s_wait(unsigned char value)
{
  unsigned short int cnt = (value * 3)>>1;
  
  for (cnt=cnt;cnt>0;cnt--)
  {
    NOP();
  }
}
#endif

/******************************************************************************/
/*                                                                            */
/*  Prototype:                                                                */
/*      void  SHT_SCK_LOW(void)                                               */
/*                                                                            */
/*  Description:                                                              */
/*    This function creates a wait time for the I2C Interfcace                */
/*                                                                            */
/*  Input parameters:                                                         */
/*    value: byte to send (Range 0...0xff)                                    */
/******************************************************************************/
/** \brief  function to set clock line low 
*/

STATIC void  SHT_SCK_LOW(void)
{
  CLK_OUT;
  SCK=0; 
}


/******************************************************************************/
/*                                                                            */
/*  Prototype:                                                                */
/*      void  HumTempSensirionOFF(void)                                       */
/*                                                                            */
/*  Description:                                                              */
/*    function to switch the power supply of the sensor off                   */
/*                                                                            */
/*  Input parameters:                                                         */
/*    value: byte to send (Range 0...0xff)                                    */
/******************************************************************************/
/** \brief  function to switch the power supply of the sensor off
*/

STATIC void HumTempSensirionOFF(void)
{ /*VDR_133 switch No power supply to sensirion module Port to input*/
#ifdef SENSIRION_SHT21_USED
  /* switch off the supply for SHT module */
  po_PS_SHT2_g = FALSE;
  po_D_PS_SHT2_g = OUTPUT;
  
  Change_AnalogPortToDigital();
  
  /* switch off the second supply port */
  po_PS_SHT1_g = FALSE;      
  po_D_PS_SHT1_g = OUTPUT;
  
#else 
  
  CLR_I2C_DATA;
  DATA_OUT; 
  CLR_I2C_DATA;
  SHT_SCK_LOW(); 
#ifndef __NUR_FEUCHTE_
#ifdef _VW_KONZERNSENSOR_ 
  po_D_PS_SHT1_g = INPUT;
  po_D_PS_SHT2_g = INPUT;
  po_D_PS_SHT0_g = OUTPUT; 
  po_PS_SHT0_g = false; 
  po_PS_SHT1_g = true;  
#else /*Porsche Sensor*/
  po_D_PS_SHT0_g = OUTPUT; 
  po_D_PS_SHT1_g = INPUT; 
  po_PS_SHT0_g = false; 
  po_PS_SHT1_g = true;
#endif
#else /*Nur Feuchte*/
  PORTB_PORTB1 = 0;
  DDRB_DDB1 = 1; 
#endif  
  
  
#endif  
}


/******************************************************************************/
/*                                                                            */
/*  Prototype:                                                                */
/*      void  HumTempSensirionON(void)                                       */
/*                                                                            */
/*  Description:                                                              */
/*    function to switch the power supply of the sensor ON                   */
/*                                                                            */
/*  Input parameters:                                                         */
/*    value: byte to send (Range 0...0xff)                                    */
/******************************************************************************/
/** \brief  function to switch the power supply of the sensor ON
*/
STATIC void HumTempSensirionON(void) 
{/*VDR_133 switch power supply to sensirion module*/
  
#ifdef SENSIRION_SHT21_USED
  
  /*  switch ON the first supply  */
  po_PS_SHT2_g = TRUE;  /* switch ON 1 supply */
  po_D_PS_SHT2_g = OUTPUT;
  /* change the second port to Analog */
  Change_DigitalPortToAnalog(); 
  
#else
  
#ifndef __NUR_FEUCHTE_
#ifdef _VW_KONZERNSENSOR_ 
  po_PS_SHT0_g = true;
  po_D_PS_SHT0_g = OUTPUT;
  po_D_PS_SHT1_g = OUTPUT; 
  po_PS_SHT0_g = true;  
  po_PS_SHT1_g = true;
  po_D_PS_SHT2_g = OUTPUT; 
  po_PS_SHT2_g = true;  
  
#else /*Porsche Sensor*/
  po_PS_SHT0_g = true; 
  po_D_PS_SHT0_g = OUTPUT; 
  po_D_PS_SHT1_g = OUTPUT;
  po_PS_SHT0_g = true; 
  po_PS_SHT1_g = true;
#endif 
#else /*Nur Feuchte*/
  PORTB_PORTB1 = 1;
  DDRB_DDB1 = 1; 
#endif  
  
  
#endif    
  
}

/******************************************************************************/
/*                                                                            */
/*  Prototype:                                                                */
/*      char s_write_byte(unsigned char value)                                */
/*                                                                            */
/*  Description:                                                              */
/*    This function gernerates clock and writes one byte to Sensirion bus     */
/*                                                                            */
/*  Input parameters:                                                         */
/*    value: byte to send (Range 0...0xff)                                    */
/*                                                                            */
/*  Output parameters:                                                        */
/*    return: TRUE  if acknowledge from sensirion was received                */
/*            FALSE if acknowledge was not recieved                           */
/*                                                                            */
/*  Preconditions:                                                            */
/*    s_transstart() was called once a transmission                           */
/*                                                                            */
/*  Postconditions:                                                           */
/*    none                                                                    */
/******************************************************************************/
/**
* \brief This function gernerates clock and writes one byte to Sensirion bus.
*
* \pre         s_transstart() was called once a transmission
* \param[in]   value byte to send (Range 0...0xff)
* \return
* - <em>TRUE</em> if acknowledge from sensirion was received
* - <em>FALSE</em> if acknowledge was not recieved
*/

#ifdef SENSIRION_SHT21_USED

STATIC unsigned char s_write_byte(unsigned char value)
{
  unsigned char i,error=0;
  DATA_OUT;
  for (i=0x80;i>0;i=i>>1) /*shift bit for masking*/
  {
    if ((i&value)>0)
    {
      SET_I2C_DATA; /*masking value with i , write to SENSI-BUS*/
    }
    else
    {
      CLR_I2C_DATA;
    }
    S_WAIT_9NOPS; 
    SHT_SCK_HIGH; //clk for SENSI-BUS
    S_WAIT_9NOPS;
    if(i > 1)
    {
      SHT_SCK_LOW();
      S_WAIT_9NOPS;
    }
  }
  SHT_SCK_LOW();
  DATA_IN; //release DATA-line
  S_WAIT_9NOPS;
  SHT_SCK_HIGH;  //clk #9 for ack
  S_WAIT_9NOPS;
  error=GET_I2C_DATA; //check ack (DATA will be pulled down by SHTXX)
  SHT_SCK_LOW();
  return error; //error=1 in case of no acknowledge
}
#else

STATIC unsigned char s_write_byte(unsigned char value)
{
  unsigned char i,error=0;
  unsigned char rb_BitValue_l;
  unsigned char rb_ChkMSB_l;
  
  DATA_OUT;
  for (i=0x80;i>0;i=i>>1) /*shift bit for masking*/
  {
    if ((i&value)>0)
    {
      rb_BitValue_l = 1;
      SET_I2C_DATA; /*masking value with i , write to SENSI-BUS*/
    }
    else
    {
      rb_BitValue_l = 0;
      CLR_I2C_DATA;
    }
    SHT_SCK_HIGH; //clk for SENSI-BUS
    
    // calculate CRC
    if ((rb_CalcChkSum_mg & 0x80) > 0)   // Store MSB of Cheksum
    {
      rb_ChkMSB_l = 1;
    }
    else
    {
      rb_ChkMSB_l = 0;
    }
    
    rb_CalcChkSum_mg = rb_CalcChkSum_mg << 1;  // Shift Cheksum left
    
    if (rb_ChkMSB_l != rb_BitValue_l)    // Stored MSB of Cheksum and read bit different?
    {
      rb_CalcChkSum_mg |= 0x01;        // set LSB of new checksum
      rb_CalcChkSum_mg ^= 0x30;        // invert bit 4 and 5
    }
    else
    {
      S_WAIT_3NOPS;
    }
    SHT_SCK_LOW();
    S_WAIT_9NOPS;
  }
  DATA_IN; //release DATA-line
  SHT_SCK_HIGH;  //clk #9 for ack
  S_WAIT_9NOPS;
  error=GET_I2C_DATA; //check ack (DATA will be pulled down by SHTXX)
  SHT_SCK_LOW();
  return error; //error=1 in case of no acknowledge
}
#endif



/******************************************************************************/
/*                                                                            */
/*  Prototype:                                                                */
/*      char char s_read_byte(byte ack)                                       */
/*                                                                            */
/*  Description:                                                              */
/*    This function gernerates clock and reads one byte from Sensirion bus    */
/*                                                                            */
/*  Input parameters:                                                         */
/*    ack: '1' sends acknowledge at end of byte transmission                  */
/*         '0' does not send acknowledge                                      */
/*                                                                            */
/*  Output parameters:                                                        */
/*    return: read byte                                                       */
/*                                                                            */
/*  Preconditions:                                                            */
/*    s_transstart() was called once a transmission                           */
/*    s_write_byte() with read command was called                             */
/*                                                                            */
/*  Postconditions:                                                           */
/*    none                                                                    */
/*                                                                            */
/******************************************************************************/

/**
* \brief This function gernerates clock and reads one byte from Sensirion bus.
*
* \pre  s_transstart() was called once a transmission <br>
*       s_write_byte() with read command was called
* \param[in]   ack
* - '1' sends acknowledge at end of byte transmission
* - '0' does not send acknowledge
* \return      read byte
*/

#ifdef SENSIRION_SHT21_USED

STATIC unsigned char s_read_byte(unsigned char ack)
{
  unsigned char i,val=0;
  unsigned char rb_BitValue_l;
  
  //CLK_OUT;
  DATA_IN; //release DATA-line
  for (i=0x80;i>0;i=i>>1) //shift bit for masking
  {
    S_WAIT_9NOPS;    
    SHT_SCK_HIGH; //clk for SENSI-BUS
    S_WAIT_9NOPS;
    S_WAIT_9NOPS;
    S_WAIT_9NOPS;
    S_WAIT_9NOPS;
    rb_BitValue_l = GET_I2C_DATA;   // read data line
    if (rb_BitValue_l > 0)  /*VDR_393*/ /* data line high?*/
    {
      val=(val | i);  // add to result
    }
#ifdef __NUR_FEUCHTE_
    S_WAIT_3NOPS_ATA_ONLY;
#endif
    S_WAIT_9NOPS;
    SHT_SCK_LOW();
  }
  // DATA=!ack;
  if (ack == 1)//in ca  e of "ack==1" pull down DATA-Line
  {
    DATA_OUT;
    CLR_I2C_DATA;
  }
  S_WAIT_3NOPS;
  SHT_SCK_HIGH; //clk #9 for ack
  S_WAIT_3_5NOPS;
  S_WAIT_3NOPS;
  SHT_SCK_LOW();
  S_WAIT_3NOPS;
  DATA_IN; //release DATA-line
  return val;
}
#else
STATIC unsigned char s_read_byte(unsigned char ack)
{
  unsigned char i,val=0;
  unsigned char rb_BitValue_l;
  unsigned char rb_ChkMSB_l;
  //CLK_OUT;
  DATA_IN; //release DATA-line
  for (i=0x80;i>0;i=i>>1) //shift bit for masking
  {
    S_WAIT_3NOPS;
    SHT_SCK_HIGH; //clk for SENSI-BUS
    // calculate CRC part 1
    if ((rb_CalcChkSum_mg & 0x80) > 0)
    {
      rb_ChkMSB_l = 1;
    }
    else
    {
      rb_ChkMSB_l = 0;
    }
    
    rb_CalcChkSum_mg = rb_CalcChkSum_mg << 1;
    
    rb_BitValue_l = GET_I2C_DATA;   // read data line
    if (rb_BitValue_l > 0)  /*VDR_393*/ /* data line high?*/
    {
      val=(val | i);  // add to result
    }
#ifdef __NUR_FEUCHTE_
    S_WAIT_3NOPS_ATA_ONLY;
#endif
    SHT_SCK_LOW();
    // calculate CRC part 2
    if (rb_ChkMSB_l != rb_BitValue_l)
    {
      rb_CalcChkSum_mg |= 0x01;
      rb_CalcChkSum_mg ^= 0x30;
    }
  }
  // DATA=!ack;
  if (ack == 1)//in case of "ack==1" pull down DATA-Line
  {
    DATA_OUT;
    CLR_I2C_DATA;
  }
  S_WAIT_3NOPS;
  SHT_SCK_HIGH; //clk #9 for ack
  S_WAIT_3_5NOPS;
  SHT_SCK_LOW();
  DATA_IN; //release DATA-line
  return val;
}
#endif




/******************************************************************************/
/*                                                                            */
/*  Prototype:                                                                */
/*      void s_transstart(void)                                               */
/*                                                                            */
/*  Description:                                                              */
/*    This function sends communication start sequence                        */
/*          _____         ________                                            */
/*    DATA:      |_______|                                                    */
/*              ___     ___                                                   */
/*    SCK : ___|   |___|   |______                                            */
/*                                                                            */
/*  Input parameters:                                                         */
/*    none                                                                    */
/*                                                                            */
/*  Output parameters:                                                        */
/*    none                                                                    */
/*                                                                            */
/*  Preconditions:                                                            */
/*    none                                                                    */
/*                                                                            */
/*  Postconditions:                                                           */
/*    none                                                                    */
/*                                                                            */
/******************************************************************************/

/**
* \brief This function sends communication start sequence.
* <pre>
*          _____         ________
*    DATA:      |_______|
*              ___     ___
*    SCK : ___|   |___|   |______
* </pre>
*/
#ifdef SENSIRION_SHT21_USED

STATIC void s_transstart(void)
{
  //CLK_OUT;
  SET_I2C_DATA;  /*to have correct state of port before switching to output*/
  DATA_OUT;
  SET_I2C_DATA;
  SHT_SCK_HIGH; //Initial state
  S_WAIT_9NOPS;
  CLR_I2C_DATA;
  S_WAIT_9NOPS;
  SHT_SCK_LOW();
  S_WAIT_3NOPS;
  
}
#else

STATIC void s_transstart(void)
{
  unsigned char rb_Mask_l;
  
  //CLK_OUT;
  SET_I2C_DATA;  /*to have correct state of port before switching to output*/
  DATA_OUT;
  SET_I2C_DATA;
  SHT_SCK_LOW(); //Initial state
  S_WAIT_3NOPS;
  SHT_SCK_HIGH;
  S_WAIT_3_5NOPS;
  CLR_I2C_DATA;
  S_WAIT_3NOPS;
  SHT_SCK_LOW();
  rb_CalcChkSum_mg = 0;
  // init Checksum calculation
  for (rb_Mask_l = 0x01; rb_Mask_l <= 0x08; rb_Mask_l = rb_Mask_l << 1)
  {
    rb_CalcChkSum_mg = rb_CalcChkSum_mg << 1;
    if ((rb_StatusReg_mg & rb_Mask_l) > 0)
    {
      rb_CalcChkSum_mg |= 0x10;
    }
  }
  SHT_SCK_HIGH;
  S_WAIT_3_5NOPS;
  SET_I2C_DATA;
  S_WAIT_3NOPS;
  SHT_SCK_LOW();
}

#endif

#ifdef SENSIRION_SHT21_USED

STATIC void s_transstop(void)
{
  
  //CLK_OUT;
  SET_I2C_DATA;  /*to have correct state of port before switching to output*/
  DATA_OUT;
  CLR_I2C_DATA;
  SHT_SCK_LOW(); //Initial state
  S_WAIT_9NOPS;
  SHT_SCK_HIGH;
  S_WAIT_9NOPS;
  SET_I2C_DATA;
  S_WAIT_3NOPS;
  
}
#endif



/******************************************************************************/
/*                                                                            */
/*  Prototype:                                                                */
/*      void s_connectionreset(void)                                          */
/*                                                                            */
/*  Description:                                                              */
/*    This function sends communication reset sequence                        */
/*    DATA-line=1 and at least 9 SCK cycles                                   */
/*          _________________________________________________                 */
/*    DATA:                                                                   */
/*             _    _    _    _    _    _    _    _    _                      */
/*    SCK : __| |__| |__| |__| |__| |__| |__| |__| |__| |____                 */
/*                                                                            */
/*  Input parameters:                                                         */
/*    none                                                                    */
/*                                                                            */
/*  Output parameters:                                                        */
/*    none                                                                    */
/*                                                                            */
/*  Preconditions:                                                            */
/*    none                                                                    */
/*                                                                            */
/*  Postconditions:                                                           */
/*    none                                                                    */
/*                                                                            */
/******************************************************************************/

/**
* \brief This function sends communication reset sequence. <br>
* DATA-line=1 and at least 9 SCK cycles
* <pre>
*          _________________________________________________
*    DATA:
*             _    _    _    _    _    _    _    _    _
*    SCK : __| |__| |__| |__| |__| |__| |__| |__| |__| |____
* </pre>
*/

#if 0
STATIC void s_connectionreset(void)
{
  unsigned char i;
  ///CLK_OUT;
  SET_I2C_DATA;   /*to have correct state of port before switching to output*/
  DATA_OUT;
  SET_I2C_DATA;
  SHT_SCK_LOW(); //Initial state
  for(i=0;i<9;i++) //9 SCK cycles
  {
    S_WAIT_3NOPS;
    SHT_SCK_HIGH;
    S_WAIT_3NOPS;
    SHT_SCK_LOW();
  }
}

#endif

/******************************************************************************/
/*                                                                            */
/*  Prototype:                                                                */
/*      char s_softreset(void)                                                */
/*                                                                            */
/*  Description:                                                              */
/*    This function sends command for softreset of the Sensirion module       */
/*                                                                            */
/*  Input parameters:                                                         */
/*    none                                                                    */
/*                                                                            */
/*  Output parameters:                                                        */
/*    return: Error flag                                                      */
/*                                                                            */
/*  Preconditions:                                                            */
/*    none                                                                    */
/*                                                                            */
/*  Postconditions:                                                           */
/*    none                                                                    */
/*                                                                            */
/******************************************************************************/

/**
* \brief This function sends command for softreset of the Sensirion module
*
* \return      Error Flag
*/


static void s_softreset(void)
{
  unsigned char error=0;
  s_transstart(); //transmission start
  error |= s_write_byte(I2C_ADDR_W);
  error |= s_write_byte(SOFT_RESET); //send RESET-command to sensor
  s_transstop();
}



/******************************************************************************/
/*                                                                            */
/*  Prototype:                                                                */
/*      byte s_read_statusreg(byte *p_value, byte *p_checksum)                */
/*                                                                            */
/*  Description:                                                              */
/*    This function reads the status register                                 */
/*                                                                            */
/*  Input parameters:                                                         */
/*    none                                                                    */
/*                                                                            */
/*  Output parameters:                                                        */
/*    p_value: Pointer to variable to write status register content in        */
/*    p_value: Pointer to variable to write checksum in                       */
/*    return: Error flag                                                      */
/*                                                                            */
/*  Preconditions:                                                            */
/*    none                                                                    */
/*                                                                            */
/*  Postconditions:                                                           */
/*    none                                                                    */
/*                                                                            */
/******************************************************************************/

/**
* \brief This function reads the status register
*
* \param[out]   p_value Pointer to variable to write status register content in
* \param[out]   p_checksum Pointer to variable to write checksum in
* \return      Error Flag
*/
#ifdef SENSIRION_SHT21_USED

#ifdef USE_READ_SHT_STATUSREGISTER___

STATIC unsigned char s_read_statusreg(unsigned char *p_value, unsigned char *p_checksum)
{
  unsigned char error;
  
  s_transstart(); //transmission start
  error = s_write_byte(I2C_ADDR_W);
  error |= s_write_byte(STATUS_REG_R); //send command to sensor
  *p_value=s_read_byte(ACK); //read status register (8-bit)
  *p_checksum=s_read_byte(noACK); //read checksum (8-bit)
  return error; //error=1 in case of no response form the sensor
}
#endif

#else

#ifdef USE_READ_SHT_STATUSREGISTER___

STATIC unsigned char s_read_statusreg(unsigned char *p_value, unsigned char *p_checksum)
{
  unsigned char error;
  
  s_transstart(); //transmission start
  error=s_write_byte(STATUS_REG_R); //send command to sensor
  *p_value=s_read_byte(ACK); //read status register (8-bit)
  rb_ChkSumCalculated_mg = rb_CalcChkSum_mg; // store calculated checksum
  *p_checksum=s_read_byte(noACK); //read checksum (8-bit)
  return error; //error=1 in case of no response form the sensor
}
#endif
#endif

/******************************************************************************/
/*                                                                            */
/*  Prototype:                                                                */
/*      byte s_write_statusreg(byte *p_value)                                 */
/*                                                                            */
/*  Description:                                                              */
/*    This function writes the status register                                */
/*                                                                            */
/*  Input parameters:                                                         */
/*    p_value: Pointer to variable to write to status register                */
/*                                                                            */
/*  Output parameters:                                                        */
/*    return: Error flag                                                      */
/*                                                                            */
/*  Preconditions:                                                            */
/*    none                                                                    */
/*                                                                            */
/*  Postconditions:                                                           */
/*    none                                                                    */
/*                                                                            */
/******************************************************************************/

/**
* \brief This function writes the status register
*
* \param[in]   p_value Pointer to variable to write to status register
* \return      Error Flag
*/
#ifdef SENSIRION_SHT21_USED

#ifdef _DO_USE_RETURNVALUE_WRITE_STATUSREG
/* PRQA S 3673 1 */ /* << Pointer is not allowed in compiler to set as const >> */
STATIC unsigned char s_write_statusreg(unsigned char *p_value)
#else
/* PRQA S 3673 1 */ /* << Pointer is not allowed in compiler to set as const >> */
STATIC void s_write_statusreg(unsigned char *p_value)
#endif
{
  unsigned char statuserror;
  s_transstart(); //transmission start
  statuserror=s_write_byte(I2C_ADDR_W);//send command to sensor
  statuserror=s_write_byte(STATUS_REG_W);//send command to sensor
  statuserror+=s_write_byte(*p_value); //send value of status register
  s_transstop();
#ifdef _DO_USE_RETURNVALUE_WRITE_STATUSREG
  return statuserror; //error>=1 in case of no response form the sensor
#endif
}

#else

#ifdef _DO_USE_RETURNVALUE_WRITE_STATUSREG
/* PRQA S 3673 1 */ /* << Pointer is not allowed in compiler to set as const >> */
STATIC unsigned char s_write_statusreg(unsigned char *p_value)
#else
/* PRQA S 3673 1 */ /* << Pointer is not allowed in compiler to set as const >> */
STATIC void s_write_statusreg(unsigned char *p_value)
#endif
{
  unsigned char statuserror;
  s_transstart(); //transmission start
  statuserror=s_write_byte(STATUS_REG_W);//send command to sensor
  statuserror+=s_write_byte(*p_value); //send value of status register
#ifdef _DO_USE_RETURNVALUE_WRITE_STATUSREG
  return statuserror; //error>=1 in case of no response form the sensor
#endif
}

#endif



/******************************************************************************/
/*                                                                            */
/*  Prototype:                                                                */
/*      byte start_measurement(byte mode)                                     */
/*                                                                            */
/*  Description:                                                              */
/*    This function sends a measurement command                               */
/*                                                                            */
/*  Input parameters:                                                         */
/*    mode: Type of measurement to trigger (Humidity or Temperature)          */
/*                                                                            */
/*  Output parameters:                                                        */
/*    return: Error flag                                                      */
/*                                                                            */
/*  Preconditions:                                                            */
/*    none                                                                    */
/*                                                                            */
/*  Postconditions:                                                           */
/*    none                                                                    */
/*                                                                            */
/******************************************************************************/

/**
* \brief This function sends a measurement command
*
* \param[in]   mode Type of measurement to trigger
* - TEMP (0) Temperature
* - HUMI (1) Humidity
* \return      Error Flag
*/

#ifdef SENSIRION_SHT21_USED
STATIC unsigned char start_measurement(unsigned char mode)
{
  unsigned char error=0;
  s_transstart(); //transmission start
  error=s_write_byte(I2C_ADDR_W);
  switch(mode) //send command to sensor
  {
  case TEMP : 
    error|=s_write_byte(MEASURE_TEMP);
    break;
  case HUMI : 
    error|=s_write_byte(MEASURE_HUMI);
    break;
  default :
    break;
  }
  return error;
}

#else

STATIC unsigned char start_measurement(unsigned char mode)
{
  unsigned char error=0;
  s_transstart(); //transmission start
  switch(mode) //send command to sensor
  {
  case TEMP : 
    error=s_write_byte(MEASURE_TEMP);
    break;
  case HUMI : 
    error=s_write_byte(MEASURE_HUMI);
    break;
  default :
    break;
  }
  return error;
}

#endif


/******************************************************************************/
/*                                                                            */
/*  Prototype:                                                                */
/*      byte m_finished(void)                                                 */
/*                                                                            */
/*  Description:                                                              */
/*    This function returns the status of a measurement                       */
/*    SHT11 pulls down data line if measurement is finished                   */
/*                                                                            */
/*  Input parameters:                                                         */
/*    mode: Type of measurement to trigger (Humidity or Temperature)          */
/*                                                                            */
/*  Output parameters:                                                        */
/*    return: TRUE:  measurement finished                                     */
/*            FALSE: measurement still in progress                            */
/*                                                                            */
/*  Preconditions:                                                            */
/*    start_measurement() called                                              */
/*                                                                            */
/*  Postconditions:                                                           */
/*    none                                                                    */
/*                                                                            */
/******************************************************************************/

/**
* \brief This function returns the status of a measurement
* SHT11 pulls down data line if measurement is finished
* \pre         start_measurement() called
* \return
* - <em>TRUE</em> measurement finished
* - <em>FALSE</em> measurement still in progress
*/

#ifdef SENSIRION_SHT21_USED

STATIC unsigned char m_finished(void)
{
  byte error;
  s_transstart();
  error=s_write_byte(I2C_ADDR_R);
  return (error);
}
#else

STATIC unsigned char m_finished(void)
{
  return (GET_I2C_DATA == 0);
}

#endif




/******************************************************************************/
/*                                                                            */
/*  Prototype:                                                                */
/*      byte checksumOK(byte rb_checksum_l)                                   */
/*                                                                            */
/*  Description:                                                              */
/*    This function returns the status of a measurement                       */
/*    SHT11 pulls down data line if measurement is finished                   */
/*                                                                            */
/*  Input parameters:                                                         */
/*    rb_Checksum_l:from sensirion bus read checksum of the last communication*/
/*                                                                            */
/*  Output parameters:                                                        */
/*    return: TRUE:  if read checksum is equal ro calculated                  */
/*            FALSE: if checksum error is detected                            */
/*                                                                            */
/*  Preconditions:                                                            */
/*    none                                                                    */
/*                                                                            */
/*  Postconditions:                                                           */
/*    none                                                                    */
/*                                                                            */
/******************************************************************************/

/**
* \brief This function compares the calculated and the read checksum
*
* \param[in]   rb_checksum_l  from sensirion bus read checksum of the last communication
* \return
* - <em>TRUE</em> if read checksum is equal ro calculated
* - <em>FALSE</em> if checksum error is detected
*/

#ifdef SENSIRION_SHT21_USED

STATIC unsigned char checksumOK(unsigned char rb_checksum_l)
{
  unsigned char byteCtr;
  unsigned char crc = 0;	 
  unsigned char rb_error_l = 0 ;
  unsigned char bit;
  
  /* calculates 8-Bit checksum with given polynomial */
  for (byteCtr = 0; byteCtr < 2; ++byteCtr)
  { 
    crc ^= (rb_CalcChkSum_mg[byteCtr]);
    for (bit = 8; bit > 0; --bit)
    { 
      if (crc & 0x80)
      {
        crc = (crc << 1) ^ 0x131;
      }
      else 
      {
        crc = (crc << 1);
      }
    }
  }
  
  if((crc == rb_checksum_l) && (rbi_SHT_DataLine_OK_g == TRUE)) /* check data line is OK */
  {
    if(crc == 0)
    {
      DATA_IN; /* set the direction of SHT data line to INPUT to check  short to GND */
      S_WAIT_3_5NOPS;
      if(DATA == 1) /* should read high due to pull up */ 
      {
        rb_error_l = 1; /* NO error */
      }
    }
    else
    {
      rb_error_l = 1;/* NO error */
    }
  }
  
  return(rb_error_l);  // return cheksum ok
}

#else

STATIC unsigned char checksumOK(unsigned char rb_checksum_l)
{
  unsigned char rb_Mask_l;            // mask for bit inversion
  unsigned char rb_TempChecksum_l;    // read checksum after bit inversion
  
  /*Clear variables for while-loop*/
  rb_TempChecksum_l = 0;     // clear checksum
  rb_Mask_l = 0x01;          // init mask
  
  // bit inversion of read checksum (bit0 -> bit7, bit1 -> bit6 ...)
  do
  {
    rb_TempChecksum_l = rb_TempChecksum_l << 1;
    if ((rb_checksum_l & rb_Mask_l) > 0)
    {
      rb_TempChecksum_l |= 0x01;
    }
    rb_Mask_l = (unsigned char) ( (rb_Mask_l << 1)&0xFF );
  } while (rb_Mask_l > 0);
  
  return(rb_TempChecksum_l == rb_ChkSumCalculated_mg);  // return cheksum ok
}

#endif


/******************************************************************************/
/*                                                                            */
/*  Prototype:                                                                */
/*      void get_result(word *p_value, byte *p_checksum)                      */
/*                                                                            */
/*  Description:                                                              */
/*    This function reads result of measurement from Sensirion bus            */
/*                                                                            */
/*  Input parameters:                                                         */
/*    none                                                                    */
/*                                                                            */
/*  Output parameters:                                                        */
/*    p_value:    Pointer to memory where to put read measurement data in     */
/*    p_checksum: Pointer to memory where to put read checksum in             */
/*                                                                            */
/*  Preconditions:                                                            */
/*    none                                                                    */
/*                                                                            */
/*  Postconditions:                                                           */
/*    none                                                                    */
/*                                                                            */
/******************************************************************************/

/**
* \brief Read result of measurement from Sensirion bus
*
* \param[out]  p_value     Pointer to memory where to put read measurement data in
* \param[out]  p_checksum  Pointer to memory where to put read checksum in
*/

#ifdef SENSIRION_SHT21_USED
STATIC void get_result(unsigned int *p_value, unsigned char *p_checksum)
{
  
  rb_CalcChkSum_mg[0]=s_read_byte(ACK); //read the first byte (MSB)
  *(p_value)  = (unsigned int) ( (((unsigned int)rb_CalcChkSum_mg[0])<<8) );    
  rb_CalcChkSum_mg[1]=s_read_byte(ACK);//read the second byte (LSB)
  *(p_value) += rb_CalcChkSum_mg[1];
  *p_checksum =s_read_byte(noACK); //read checksum
  s_transstop();
}

#else

STATIC void get_result(unsigned int *p_value, unsigned char *p_checksum)
{
  
  
  *(p_value)  = (unsigned int) ( (((unsigned int)s_read_byte(ACK))<<8) ); //read the first byte (MSB)
  *(p_value) += s_read_byte(ACK); //read the second byte (LSB)
  
  rb_ChkSumCalculated_mg = rb_CalcChkSum_mg; // store calculated checksum
  *p_checksum =s_read_byte(noACK); //read checksum
  
}

#endif


/******************************************************************************/
/*                                                                            */
/*  Prototype:                                                                */
/*      word calc_dewpoint(byte h,word TempTicks)                             */
/*                                                                            */
/*  Description:                                                              */
/*    This function reads result of measurement from Sensirion bus            */
/*                                                                            */
/*  Input parameters:                                                         */
/*    h:    Calculated relative humidity in [%%rH] range 0..100               */
/*    TempTicks:    Measuered Temperature in Ticks                            */
/*                                                                            */
/*  Output parameters:                                                        */
/*    return:  Calculated dewpoint                                            */
/*             (Factor 0.1 Offset -39.6 [eg. 596 equals 20GradC])                */
/*                                                                            */
/*  Preconditions:                                                            */
/*    none                                                                    */
/*                                                                            */
/*  Postconditions:                                                           */
/*    none                                                                    */
/*                                                                            */
/******************************************************************************/

/**
* \brief This function calculates the dewpoint.
*
* \param[in]   h    Calculated relative humidity in [%%rH] range 0..100
* \param[in]   TempTicks    Measuered Temperature in Ticks
* \return      Calculated dewpoint (Factor 0.1 Offset -39.6 [eg. 596 equals 20GradC])
*/


STATIC unsigned int calc_dewpoint(unsigned int h,unsigned int TempTicks)
{
  unsigned int rw_TempTicks4tel_l;
  short int DP;
  short int H,H_Nenner;
  //not used  unsigned int Temp_Celcsius;
  
  /** \brief Lookup-table for ( log10(rh)-2/0.4343 ) *(-100/2) */
  static const unsigned char cb_log10LookUpTable1_00to17_mg[18] = {255,255,230,210,196,184,175,168,161,155,150,\
    145,141,137,133,130,126,123};
  /** \brief Lookup-table for ( log10(rh)-2/0.4343 ) *(-100/2) */
  static const unsigned char cb_log10LookUpTable2_18to58_mg[41] ={241,235,230,225,221,216,212,208,204,200,197,193,\
    190,186,183,180,177,174,171,169,166,163,161,158,156,154,151,149,147,145,143,141,139,137,135,133,131,129,127,126\
      ,124};
  /** \brief Lookup-table for ( log10(rh)-2/0.4343 ) *(-100/2) */
  static const unsigned char cb_log10LookUpTable4_59to108_mg[50] ={241,237,234,231,228,225,222,219,216,213,210,\
    207,204,202,199,196,194,191,188,186,183,181,178,176,173,171,169,166,164,162,160,157,155,153,151,149,147,145,143,\
      141,139,137,135,133,131,129,127,125,123,121};/*VDR_548 shifting table*/
  /** \brief Lookup-table for ( log10(rh)-2/0.4343 ) *(-100/2) */
  static const unsigned char cb_log10LookUpTable8_109to200_mg[92] = {239,236,232,228,225,221,218,214,211,208,204,\
    201,198,194,191,188,185,182,179,175,172,169,166,163,160,157,154,151,148,146,143,140,137,134,131,129,126,123,120,\
      118,115,112,110,107,105,102,99,97,94,92,89,87,84,82,79,77,75,72,70,67,65,63,60,58,56,53,51,49,47,44,42,40,38,\
        36,33,31,29,27,25,23,21,18,16,14,12,10,8,6,4,2,0,0};  /*VDR_548 shifting table*/
  rw_TempTicks4tel_l = (TempTicks+2)>>2; //round and scale
  H_Nenner = (short int)((634+ 4 + ((TempTicks+16)>>5)) >>3); //  Caluclate Nenner with rounding
  
  
  if (rw_TempTicks4tel_l < 1000)    //avoid overflow in formula
  {
    H = ( (short int) rw_TempTicks4tel_l)-1000;
    H = (short int)((((((14*H)+((H)/16)) -((H)/4))))/H_Nenner ); /*VDR_548 rounding of variables*/
  }
  else   //use formula with less resolution but rounding
  {
    rw_TempTicks4tel_l =((rw_TempTicks4tel_l)-1000);
    H  = (short int)(((((14*rw_TempTicks4tel_l)+((rw_TempTicks4tel_l)/16)) -((rw_TempTicks4tel_l)/4)))/ \
      (unsigned int)(H_Nenner)); /*VDR_548 rounding of variables*/
  }
  
  if (h >=1)  /*VDR_548 use correct humidity*/
  {
    h--;
  }
  if (h < 1)
  {
    DP = -1000; /*humidity below 0.5%RH -> low dewpoint*/
  }
  else if (h <= 17)
  {
    H = H - cb_log10LookUpTable1_00to17_mg[h];    
    if (h==1)
    {
      H -=15; /*VDR_548 range not high enough for 0,5%RH*/
    } 
    DP = 2+((short int)((620*((long)(H)))/((short int)(221-((H+2)/4)))));
    /* VDR_548 dewpoint adder 2 for this range!*/
  }
  else if (h <= 58)
  {
    H = (H*2) - cb_log10LookUpTable2_18to58_mg[h-18];
    DP =3+( (short int)((310*((long)(H)))/((short int)(221-((H+4)/8))))); 
    /* VDR_548 dewpoint adder 1 for this range!*/
  }
  else if (h <= 108)
  {
    H = (4*H) - cb_log10LookUpTable4_59to108_mg[h-59];
    DP = (short int)((310*((long)(H)))/((short int)(442-((H+4)/8))));
  }
  else
  {
    H = (8*H); 
    if (h<200) /*check if humidity is to high!*/
    {
      H -= cb_log10LookUpTable8_109to200_mg[h-109];
    }
    DP = (short int)((155*((long)(H)))/((short int)(442-((H+7)/16))));
  }
  /* to get signed variable*/
  /*VDR_548 and additional offset for better accuracy*/
  /* temp Correction of formula for Dewpoint*/
  DP = (DP+408)-(((short int)TempTicks)/600);   /* VDR_548 improve accuracy of HT-Measurement*/
  if (DP<0)
  {
    DP = 0;
  }
  return ((unsigned int)(DP));
  
  
}


/******************************************************************************/
/*                  Definition of exported module functions                   */
/******************************************************************************/


/******************************************************************************/
/*                                                                            */
/*  Prototype:                                                                */
/*      void HumTemp_Init(void)                                               */
/*                                                                            */
/*  Description:                                                              */
/*    The application calls this function once in the init task.              */
/*    - Sets the portpins for power supply of the sensirion module.           */
/*    - Sets all output variables to init state.                              */
/*    - Sets initializes internal variables.                                  */
/*                                                                            */
/*  Input parameters:                                                         */
/*    none                                                                    */
/*                                                                            */
/*  Output parameters:                                                        */
/*    none                                                                    */
/*                                                                            */
/*  Preconditions:                                                            */
/*    none                                                                    */
/*                                                                            */
/*  Postconditions:                                                           */
/*    none                                                                    */
/*                                                                            */
/******************************************************************************/

/**
* \brief   The application calls this function once in the init task.
*
* - Sets the portpins for power supply of the sensirion module.
* - Sets all output variables to init state.
* - Sets initializes internal variables.
* \ingroup external
*/

void HumTemp_Init(void)
{
  

  rb_SHT_SupplyRetryCounter_g = 0;
  rb_SHT_ComErrRetryCounter_g = 0;
  
  
  //  HumTempSensirionOFF();
  rb_Humidity_raw_g = cw_HUMTEMP_INIT_g;         // init variables
  rb_Humidity_g = cw_HUMTEMP_INIT_g; 
  rw_Temperature_g = cw_HUMTEMP_INIT_g;
  rw_Temperature_raw_g = cw_HUMTEMP_INIT_g;
  rw_DewPoint_g = cw_HUMTEMP_INIT_g;
  rb_HumTemp_ErrorCode_g = 0;
  rb_StatusReg_mg = 0;
  rb_TaskStatus_s = 0;
#ifdef _EMULATOR_
  rw_TempTicks_g = 6000;
  rw_HumiTicks_g = 2000;
#endif
}


/******************************************************************************/
/*                                                                            */
/*  Prototype:                                                                */
/*      void HumTemp_Heater(byte rb_HeaterStatus_l)                           */
/*                                                                            */
/*  Description:                                                              */
/*    The application calls this function if there is a request to switch     */
/*    the heating element on or off.                                          */
/*                                                                            */
/*  Input parameters:                                                         */
/*    rb_HeaterStatus_l: '0' heater off <br> '1' heater on                    */
/*                                                                            */
/*  Output parameters:                                                        */
/*    none                                                                    */
/*                                                                            */
/*  Preconditions:                                                            */
/*    HumTemp_Init() was called                                               */
/*                                                                            */
/*  Postconditions:                                                           */
/*    HumTemp_Handler() cyclic call                                           */
/*                                                                            */
/******************************************************************************/

/**
* \brief   The application calls this function if there is a request to switch the heating element on or off.
* \ingroup external
* \since       Rev. 1.1
* \param[in]   rb_HeaterStatus_l
* - '0' heater off
* - '1' heater on
* \pre         HumTemp_Init() was called
* \post        HumTemp_Handler() cyclic call
*/

void HumTemp_Heater(unsigned char rb_HeaterStatus_l)
{
  if (rb_HeaterStatus_l == cb_HEATERON_g)     /* heater on requested?       */
  {
    rb_StatusReg_mg |= cb_SR_HEATER_mg;     /* set flag in status register   */
  }
  else
  {
    rb_StatusReg_mg &= (unsigned char) cb_SR_NEG_HEATER_mg;    /* clear flag in status register */
  }
}


/******************************************************************************/
/*                                                                            */
/*  Prototype:                                                                */
/*      byte HumTemp_GetHeaterStatus(void)                                    */
/*                                                                            */
/*  Description:                                                              */
/*    Read heater status.                                                     */
/*                                                                            */
/*  Input parameters:                                                         */
/*    none                                                                    */
/*                                                                            */
/*  Output parameters:                                                        */
/*    return: '0' heater off     '1' heater on                                */
/*                                                                            */
/*  Preconditions:                                                            */
/*    HumTemp_Init() was called                                               */
/*                                                                            */
/*  Postconditions:                                                           */
/*    none                                                                    */
/*                                                                            */
/******************************************************************************/

/**
* \brief   Read heater status.
* This function returns the status if the heating element of the sensor is on or off
* \ingroup external
* \since       Rev. 1.1
* \return      status of heater
* - '0' heater off
* - '1' heater on
* \pre         HumTemp_Init() was called
*/

unsigned char HumTemp_GetHeaterStatus(void)
{
  return ((rb_StatusReg_mg & cb_SR_HEATER_mg) > 0);
}


#ifdef SENSIRION_SHT21_USED

/******************************************************************************/
/*                                                                            */
/*  Prototype:                                                                */
/*      void HumTemp_Handler(void)                                            */
/*                                                                            */
/*  Description:                                                              */
/*    The application calls this function cyclic every 10ms.                  */
/*    sequence to manage the cyclic measurement of temperature and humidity   */
/*    ticks error management, communication, timeout, checksum                */
/*    calculation of temperature, rel. humidity and dew point                 */
/*                                                                            */
/*  Input parameters:                                                         */
/*    none                                                                    */
/*                                                                            */
/*  Output parameters:                                                        */
/*    none                                                                    */
/*                                                                            */
/*  Preconditions:                                                            */
/*    HumTemp_Init() was called                                               */
/*                                                                            */
/*  Postconditions:                                                           */
/*    none                                                                    */
/*                                                                            */
/******************************************************************************/

/**
* \brief   The application calls this function cyclic every 10ms.
*
* - sequence to manage the cyclic measurement of temperature and humidity ticks
* - error management, communication, timeout, checksum
* - calculation of temperature, rel. humidity and dew point
* \ingroup external
* \pre         HumTemp_Init() was called
*/
void HumTemp_Handler(void)
{
  word rw_DewPoint_l;
  static word  rw_Previous_TempTicks_g;
  static word  rw_TemperoryTicks_mg;
  static unsigned char rb_error_s; // temp error counter
  
  static unsigned char rb_checksum_s; // read checksum
  unsigned int rw_TempResult_l; // VDRtemp result for caclulation
  unsigned int rw_HumiResult_l; /*VCO_060 temporary variable for dynamic optimised humidity*/
  
  
  switch(rb_TaskStatus_s) // switch (TaskStatus)
  {
    
  case 0: /* switch on and initialize module*/
    HumTempSensirionON();/*switch sensirionmodul on */
    AD_ConversionPerIntStart(po_SHT_Supply_g);
    rb_TaskStatus_s++; /* increase TaskStatus */
    
    break; 
  case 1: 
    if(rbi_HumiSupply_OK_g == FALSE)
    {
      /* set clk to output low and skip coomunication and prepare for re attempt */
      
      po_SHT71_1_CLK_g   = FALSE;
      po_DSHT71_1_CLK_g  = OUTPUT;
      po_SHT71_1_DATA_g  = FALSE;
      po_DSHT71_1_DATA_g = INPUT; /* Keep data line as input, because of pull up data shall follow supply */
      rb_TaskStatus_s = cb_JumpAfterShtPowerFail;
    }
    else
    {
      s_softreset();
      rb_TaskStatus_s++; /* increase TaskStatus */
    }
    break; 
  case 2: 
    
    (void)SHT2x_GetSerialNumber(cb_PART_1); /* Read the serial number of sensirion module */ 
    rb_TaskStatus_s++; /* increase TaskStatus */
    s_softreset();
    break; 
  case 3: 
    
    (void)SHT2x_GetSerialNumber(cb_PART_2); /* Read the serial number of sensirion module */ 
    rb_TaskStatus_s++; /* increase TaskStatus */
    break;   
  case 4: 
    
    rb_error_s = 0; // clear temp error
    rb_StatusReg_mg = cb_SR_LOWRESOLUTION_mg; // switch in 14bit moder for temperature measurement
    s_write_statusreg(&rb_StatusReg_mg); // write status register
    rb_TaskStatus_s++; // increase TaskStatus
    
    break;
    
  case 5: // case 1: Start measurement of Temperature
    
    if(start_measurement(TEMP) > 0) // communication failure?
    {
      if(rb_HumTemp_ErrorCode_g == 0) /*VDR_520 workaround that errorflag shows only the basic error*/
      {
        rb_HumTemp_ErrorCode_g = cb_HTERR_WRITECMD_g; // set error code "Write CMD"
      }
      rb_error_s ++;
    }
    rb_TaskStatus_s++; // incrase TaskStatus
    DATA_IN;
    SHT_SCK_HIGH; 
    break;
    
  case 14: /*  Read result or timout */
    if(m_finished()==0) // Temperature measurement finished?
    {
      get_result(&rw_TemperoryTicks_mg,&rb_checksum_s); //read temperature ticks
      
      if(!checksumOK(rb_checksum_s)) // Checksum not ok?
      {
        if (rb_HumTemp_ErrorCode_g == 0) /*VDR_520 workaround that errorflag shows only the basic error*/
        {
          rb_HumTemp_ErrorCode_g = cb_HTERR_CHECKSUM_g; // Set error code "Checksum"
        }
        rb_error_s += 1;
      }
      else
      {
        if((rw_TemperoryTicks_mg & 0x02) == 0)
        {
        rw_TemperoryTicks_mg = rw_TemperoryTicks_mg&0xFFFCU; /*Remove last two status bits */
        if(rbi_First_Call_g == FALSE)
        {
          rw_Previous_TempTicks_g = rw_TemperoryTicks_mg;
          rbi_First_Call_g = TRUE;
        }
        if((rw_TemperoryTicks_mg == 0) &&(rw_Previous_TempTicks_g > 3500))
        {
          /* when Temptick is 0 then checksum is also 0. It is not possible to detect error in this case.
          To differenciate between real value and error value, the current tick is compared with previous tick. 
          it is not realistic to have around 10 degree difference from previous cycle of measurement (within 85ms). 
          this must be error */
          rb_error_s += 1; 
        }
        else
        { 
          rw_TempTicks_g = rw_TemperoryTicks_mg  ;
          rw_Previous_TempTicks_g = rw_TempTicks_g;
        }
      }
      else
      {
        /* there is error in status bit, so retain the old data */
        rb_error_s += 1;
      }
      }
    }
    else
    {
      if (rb_HumTemp_ErrorCode_g == 0) /*VDR_520 workaround that errorflag shows only the basic error*/
      {
        rb_HumTemp_ErrorCode_g = cb_HTERR_TIMEOUT_g; // set error code "Timeout"
      }
      rb_error_s += 1;

    }
     rb_TaskStatus_s++; /*/ increase TaskStatus */
    break;
    
    
  case 15: /* switch to high resolution mode */
    rb_StatusReg_mg = (unsigned char) cb_SR_NEG_LOWRESOLUTION_mg; /* switch to high 
    resolution mode for humidity measurement*/
    s_write_statusreg(&rb_StatusReg_mg); /* write status register*/
    rb_TaskStatus_s++; // increase TaskStatus
    break;
    
  case 16: /* Start humidity measurement */
    if(start_measurement(HUMI) > 0) // communication failure?
    {
      if(rb_HumTemp_ErrorCode_g == 0) /*VDR_520 workaround that errorflag shows only the basic error*/
      {
        rb_HumTemp_ErrorCode_g = cb_HTERR_WRITECMD_g; // set error code "Write CMD"
      }
      rb_error_s ++;
    }

    rb_TaskStatus_s++; // increase TaskStatus
    DATA_IN;
    SHT_SCK_HIGH; 
    break;
    
  case 19: /* Read result or timout */
    if(m_finished()==0) // Humidity measurement finished?
    {
      get_result(&rw_TemperoryTicks_mg,&rb_checksum_s); //read humidity ticks
      
      if(!checksumOK(rb_checksum_s)) // Checksum not ok?
      {
        if(rb_HumTemp_ErrorCode_g == 0) /*VDR_520 workaround that errorflag shows only the basic error*/
        {
          rb_HumTemp_ErrorCode_g = cb_HTERR_CHECKSUM_g; // Set error code "Checksum"
        }
        rb_error_s += 1;
      }
      else
      { /* checksum is OK */
        if((rw_TemperoryTicks_mg & 0x02) > 0) /* check status bit is valid ?*/
        {
          rw_HumiTicks_g = rw_TemperoryTicks_mg & 0xFFFCU; /*Remove last two status bits */
          /*  rw_HumiTicks_g &= ~0x0003;  clear bits [1..0] (status bits) */
        }
        else
        {
          /* there is error in status bit, so retain the old data */
          rb_error_s += 1;
        }
        
      }

    }
    else
    {
      if(rb_HumTemp_ErrorCode_g == 0) /*VDR_520 workaround that errorflag shows only the basic error*/
      {
        rb_HumTemp_ErrorCode_g = cb_HTERR_TIMEOUT_g; // set error code "Timeout"
      }
      rb_error_s += 1;
    }
   rb_TaskStatus_s++; // increase TaskStatus
    break;
    
  case 20:  /* calculate Humidity or make error handling */
    if (rb_error_s == 0)
    {
      if (rw_HumiTicks_g > 0xFFFCU)  // humiticks > 12bit value?
      {
        rb_error_s += 1;
        rb_HumTemp_ErrorCode_g |= cb_HTERR_HUMIOUTOFRANGE_g; /*VCO_037 out of range*/
        rw_HumiTicks_g = 0xFFFCU;    // set to maximum
      }
      if (rw_TempTicks_g > 0xFFFCU)  // tempticks > 14bit value?
      {
        rb_error_s += 1;
        rb_HumTemp_ErrorCode_g |= cb_HTERR_TEMPOUTOFRANGE_g; /*VCO_037 out of range*/
        rw_TempTicks_g = 0xFFFCU;
      }
    }
    if(rb_error_s == 0) // all previous task finished without error?
    {
      
      if( rw_HumiTicks_g < 3146) /* 0 % Humidity */
      {
        rw_HumiTicks_g = 3146;
      }
      else if(rw_HumiTicks_g > 55575) /*100 % Humidity*/
      {
        rw_HumiTicks_g = 55575;
      }
      else
      {}
      
      rw_HumiResult_l = (word)((((long)rw_HumiTicks_g*1250)/65536)-60); 
      
      rw_TempResult_l = (word)((((long)rw_TempTicks_g*17572)/65536));
      
      rb_Humidity_g = (byte)((rw_HumiResult_l/5)+1); /*201 is 100%RH and 1 is 0%RH*/
      rb_Humidity_raw_g = (byte)(rw_HumiResult_l/5); /* 0-200 => 0 to 100 % */
      
      if(rw_TempResult_l < 1) /* to avoid init values for temperatures */
      {
        rw_TempResult_l = 1;
        
      }
 rw_Temperature_g = rw_TempResult_l;
      rw_Temperature_raw_g = rw_TempResult_l;
      
      rb_TaskStatus_s++; // increase TaskStatus
    }
    else
    {  
      if (rb_StaticHumTempErrorCounter_g < 0xff)
      {
        rb_StaticHumTempErrorCounter_g++; /* increase rolling error counter for diagnosis*/
      }
      
      /* Time in mili sec = 180* number of count */
      /* for 60 sec 333*180 = 59940 */
      /* (11*60  + 60/10+1)/2 = 333 */ /* need to configure 1 digit for 1sec in EEPROM */
      if(rw_InErrorModeCounter_s < (11*(word)cb_ERROR_DEJITTER_g + ((word)cb_ERROR_DEJITTER_g/10)+1)/2) // debounce error
      {
        rw_InErrorModeCounter_s++; // increase debounce counter
      }
      else
      {
        rbi_HumTempComError_g = TRUE;       // set error flag
        rb_Humidity_raw_g = cb_HUMI_ERROR_g; // set output values to Error
        rb_Humidity_g = cb_HUMI_ERROR_g;  /*VCO_060*/
        rw_Temperature_g = cw_HUMTEMP_ERROR_g;
        rw_DewPoint_g = cw_HUMTEMP_ERROR_g;
      }
      // power supply is off, so hardreset is done     s_softreset(); // reset Chip
      rb_TaskStatus_s = cb_JUMP_AFTER_ERROR_mg; // step over calculations!
    }
    break;
    
    
  case 21:   /* calculate dewpoint */ /* VDR_850 */
    if(rb_error_s == 0) // all previous task finished without error?
    {
      rw_InErrorModeCounter_s = 0;
      rb_SHT_ComErrRetryCounter_g = 0;
      rb_SHT_SupplyRetryCounter_g = 0;
      /* put values on Bus to have all synchron*/
      
      if(rw_Temperature_g < 725)
      {
        rw_Temperature_g = 725; /* The temperature less than -39,5 the tool doesnot support */
      }
      rw_TempTicks_g = (rw_Temperature_g-725)/10 ;
      if(rw_TempTicks_g<1)
      {
        rw_TempTicks_g = 1;
      }
      rw_DewPoint_l = calc_dewpoint(rb_Humidity_g,rw_TempTicks_g*10);
      
      if(rw_DewPoint_l < 1)
      {
      rw_DewPoint_g = 1; /*VDR_346*/
      }
      else
      {
        rw_DewPoint_g = rw_DewPoint_l; 
      }
      rb_HumTemp_ErrorCode_g = 0; // clear error code
      rbi_HumTempComError_g = FALSE;
      rb_SHT_ComErrRetryCounter_g = 0;
    }
    rb_TaskStatus_s++;     // increase TaskStatus
    break;
    
    
  default:
    if(rb_TaskStatus_s < cb_MEASUREPERIODE_mg)   // Cycletime not over?
    {
      if((rbi_HumTempComError_g == TRUE)&&(rb_TaskStatus_s > 25))
      {
        HumTempSensirionOFF(); 
      }
      rb_TaskStatus_s++;  // increase task status
    }
    else
    {
      if((rb_SHT_SupplyRetryCounter_g >= SHT_SUPPLY_RETRY_ATTEMPT) ||(rb_SHT_ComErrRetryCounter_g >= SHT_COMM_ERR_RETRY_ATTEMPT) )
      {
        rb_TaskStatus_s = cb_MEASUREPERIODE_mg;
        rbi_HumTempComError_g = TRUE; /* set communication error */
        rbi_HumiSupply_OK_g = FALSE;
        HumTempSensirionOFF();
        /* Make data and clock also to OUTPUT low */
        po_SHT71_1_CLK_g   = FALSE;
        po_DSHT71_1_CLK_g  = OUTPUT;
        po_SHT71_1_DATA_g  = FALSE;
        po_DSHT71_1_DATA_g = OUTPUT;
      }
      else if((rbi_HumiSupply_OK_g == FALSE)&&(rb_SHT_SupplyRetryCounter_g < SHT_SUPPLY_RETRY_ATTEMPT))
      {
        rb_TaskStatus_s = 0; // TaskStatus = 0  start next measurement
        HumTempSensirionON(); /*Switch Power Supply on*/
        rb_SHT_SupplyRetryCounter_g++;
      }
      else if( ((rbi_HumTempComError_g == TRUE)&&(rb_SHT_ComErrRetryCounter_g < SHT_COMM_ERR_RETRY_ATTEMPT)))
      {
        rb_TaskStatus_s = 0; // TaskStatus = 0  start next measurement
        HumTempSensirionON(); /*Switch Power Supply on*/
        rb_SHT_ComErrRetryCounter_g++;
        
      }
      
      else
      {
        rb_TaskStatus_s = 4; /*  start next measurement */
      }
    }
    break; 
  }
  
}


#else


 

  /******************************************************************************/
  /*                                                                            */
  /*  Prototype:                                                                */
  /*      void HumTemp_Handler(void)                                            */
  /*                                                                            */
  /*  Description:                                                              */
  /*    The application calls this function cyclic every 10ms.                  */
  /*    sequence to manage the cyclic measurement of temperature and humidity   */
  /*    ticks error management, communication, timeout, checksum                */
  /*    calculation of temperature, rel. humidity and dew point                 */
  /*                                                                            */
  /*  Input parameters:                                                         */
  /*    none                                                                    */
  /*                                                                            */
  /*  Output parameters:                                                        */
  /*    none                                                                    */
  /*                                                                            */
  /*  Preconditions:                                                            */
  /*    HumTemp_Init() was called                                               */
  /*                                                                            */
  /*  Postconditions:                                                           */
  /*    none                                                                    */
  /*                                                                            */
  /******************************************************************************/
  
  /**
  * \brief   The application calls this function cyclic every 10ms.
  *
  * - sequence to manage the cyclic measurement of temperature and humidity ticks
  * - error management, communication, timeout, checksum
  * - calculation of temperature, rel. humidity and dew point
  * \ingroup external
  * \pre         HumTemp_Init() was called
  */
  
  void HumTemp_Handler(void)
  {
#ifdef _V3_HUMTEMP_COEFFICIENTS_ /*VDR_346*/
    const unsigned int c1Negative = 400; /*negative of C1 *100*/
    const u32 C2 = 405000; /* Constants for Humidity calculation */
    const unsigned char C3 = 28;
#else
    const unsigned int c1Negative = 205; /*negative of C1 *100*/
    const u32 C2 = 367000; /* Constants for Humidity calculation */
    const unsigned char C3 = 16;
#endif
    
    static unsigned char rb_error_s; // temp error counter
    static unsigned char rb_TimeOut_s; // Counter for Timeout
    
    static unsigned char rb_checksum_s; // read checksum
    unsigned int rw_TempResult_l; // VDRtemp result for caclulation
    unsigned int rw_HumResult_comp_l; /*VCO_060 temporary variable for dynamic optimised humidity*/
    static u32 rh_lin;
    static unsigned char rh_lin_SignNegative_s; /*this byte is used to store the
    sign of rh_lin*/
    static unsigned char rb_HumidityDynComp_temp_s /*VCO_060*/;
    u32 rh_linpart1_l;  /*VDR_427 temp result of calculation for rh_lin*/
    
    switch(rb_TaskStatus_s) // switch (TaskStatus)
    {
    case 0: //case 0: switch on and initialize module
      HumTempSensirionON();//switch sensirionmodul on
      rb_TaskStatus_s++; // increase TaskStatus
      break; 
    case 1: 
      s_connectionreset(); // Connection Reset
      rb_error_s = 0; // clear temp error
      rb_StatusReg_mg |= cb_SR_LOWRESOLUTION_mg; // switch in 12bit moder for temperature measurement
      s_write_statusreg(&rb_StatusReg_mg); // write status register
      rb_TaskStatus_s++; // increase TaskStatus
      break;
      
    case 2: // case 1: Start measurement of Temperature
      
      if(start_measurement(TEMP) > 0) // communication failure?
      {
        if(rb_HumTemp_ErrorCode_g == 0) /*VDR_520 workaround that errorflag shows only the basic error*/
        {
          rb_HumTemp_ErrorCode_g = cb_HTERR_WRITECMD_g; // set error code "Write CMD"
        }
        rb_error_s ++;
      }
      rb_TimeOut_s = cb_CONVERSIONTIMEOUT_s; // set Timeout
      rb_TaskStatus_s++; // incrase TaskStatus
      DATA_IN;
      break;
      
    case 4: // case 4: Read result or timout
#ifdef _EMULATOR_
      rb_TaskStatus_s++;
      rb_error_s = 0;
#else /* _EMULATOR_ */
      if(m_finished()>0) // Temperature measurement finished?
      {
        get_result(&rw_TempResult_l,&rb_checksum_s); //read temperature ticks
        if (rw_TempResult_l <= (0xffffU>>2)) /*VDR_684 check limits*/
        {
          rw_TempTicks_g = rw_TempResult_l<<2; 
        }
        else 
        {
          rw_TempTicks_g = 0xffffU; 
        }

        rb_TaskStatus_s++; // increase TaskStatus
      }
      if(rb_TimeOut_s > 0) // if Timeout > 0
      {
        rb_TimeOut_s--; // decrease Timeout
      }
      else
      {
        if (rb_HumTemp_ErrorCode_g == 0) /*VDR_520 workaround that errorflag shows only the basic error*/
        {
          rb_HumTemp_ErrorCode_g = cb_HTERR_TIMEOUT_g; // set error code "Timeout"
        }
        rb_error_s += 1;
        rb_TaskStatus_s += 2; // increase TaskStatus override checksum test
      }
#endif /* _EMULATOR_ */
      break;
      
    case 5:  // case 5: Checksum test
      if(!checksumOK(rb_checksum_s)) // Checksum not ok?
      {
        if (rb_HumTemp_ErrorCode_g == 0) /*VDR_520 workaround that errorflag shows only the basic error*/
        {
          rb_HumTemp_ErrorCode_g = cb_HTERR_CHECKSUM_g; // Set error code "Checksum"
        }
        rb_error_s += 1;
      }
      rb_TaskStatus_s++; // increase TaskStatus
      break;
      
    case 10: // case 10: switch to high resolution mode
      rb_StatusReg_mg &= (unsigned char) cb_SR_NEG_LOWRESOLUTION_mg; /* switch to high 
      resolution mode for humidity measurement*/
      s_write_statusreg(&rb_StatusReg_mg); /* write status register*/
      rb_TaskStatus_s++; // increase TaskStatus
      break;
      
    case 11: // case 11: Start humidity measurement
      if(start_measurement(HUMI) > 0) // communication failure?
      {
        if(rb_HumTemp_ErrorCode_g == 0) /*VDR_520 workaround that errorflag shows only the basic error*/
        {
          rb_HumTemp_ErrorCode_g = cb_HTERR_WRITECMD_g; // set error code "Write CMD"
        }
        rb_error_s ++;
      }
      rb_TimeOut_s = cb_CONVERSIONTIMEOUT_s; // set Timeout
      rb_TaskStatus_s ++; // increase TaskStatus
      DATA_IN;
      break;
      
    case 13: // case 13: Read result or timout
#ifdef _EMULATOR_
      rb_TaskStatus_s++;
#else /* _EMULATOR_ */
      if(m_finished()>0) // Humidity measurement finished?
      {
        get_result(&rw_HumiTicks_g,&rb_checksum_s); //read humidity ticks
        rb_TaskStatus_s++; // increase TaskStatus
      }
      if(rb_TimeOut_s > 0) // if Timeout > 0
      {
        rb_TimeOut_s--; // decrease Timeout
      }
      else
      {
        if(rb_HumTemp_ErrorCode_g == 0) /*VDR_520 workaround that errorflag shows only the basic error*/
        {
          rb_HumTemp_ErrorCode_g = cb_HTERR_TIMEOUT_g; // set error code "Timeout"
        }
        rb_error_s += 1;
        rb_TaskStatus_s += 2; // increase TaskStatus override checksum test
      }
#endif /* _EMULATOR_ */
      break;
      
    case 14:  // case 14: Checksum test
      if(!checksumOK(rb_checksum_s)) // Checksum not ok?
      {
        if(rb_HumTemp_ErrorCode_g == 0) /*VDR_520 workaround that errorflag shows only the basic error*/
        {
          rb_HumTemp_ErrorCode_g = cb_HTERR_CHECKSUM_g; // Set error code "Checksum"
        }
        rb_error_s += 1;
      }
      
      rb_TaskStatus_s++; // increase TaskStatus
      break;
    case 15:  // case 15: maximum check for tick values
      if (rb_error_s == 0)
      {
        if (rw_HumiTicks_g > 0x0fff)  // humiticks > 12bit value?
        {
          rb_error_s += 1;
          rb_HumTemp_ErrorCode_g |= cb_HTERR_HUMIOUTOFRANGE_g; /*VCO_037 out of range*/
          rw_HumiTicks_g = 0x0fff;    // set to maximum
        }
        else if (rw_TempTicks_g > 0x3fff)  // tempticks > 14bit value?
        {
          rb_error_s += 1;
          rb_HumTemp_ErrorCode_g |= cb_HTERR_TEMPOUTOFRANGE_g; /*VCO_037 out of range*/
          rw_TempTicks_g = 0x3fff;
        }
        else /* for MISRA*/
        {
        }
      }
      rb_TaskStatus_s++; // increase TaskStatus
      break;
      
    case 25:  // case 25: calculate Humidity or make error handling
      if(rb_error_s == 0) // all previous task finished without error?
      {
        /*linearisation of humidity VDR_427 use also negative results*/
        rh_linpart1_l = (((C2*(u32)rw_HumiTicks_g)+50000)/100000); /*VDR_427 calculate temp result*/
        /*VDR_427 calculate second temp result*/
        rh_lin = ((((C3*(u32)rw_HumiTicks_g*rw_HumiTicks_g)+50000)/100000)+c1Negative);
        if(rh_linpart1_l < rh_lin) /*check which part is higher*/
        {
          rh_lin_SignNegative_s = TRUE;  /*set Sign to negative*/
          rh_lin = rh_lin - rh_linpart1_l;/*VDR_427*/
        }
        else
        {
          rh_lin_SignNegative_s = FALSE; /*set Sign to positive*/
          rh_lin = rh_linpart1_l - rh_lin;/*VDR_427*/
        }
        rb_TaskStatus_s++; // increase TaskStatus
      }
      else
      {  
        if (rb_StaticHumTempErrorCounter_g < 0xff)
        {
          rb_StaticHumTempErrorCounter_g++; /* increase rolling error counter for diagnosis*/
        }
        HumTempSensirionOFF(); /*Switch Power Supply Off*/
        
        if(rb_InErrorModeCounter_s < cb_ERROR_DEJITTER_g) // debounce error
        {
          rb_InErrorModeCounter_s++; // increase debounce counter
        }
        else
        {
          rbi_HumTempComError_g = TRUE;       // set error flag
          rb_Humidity_raw_g = cb_HUMI_ERROR_g; // set output values to Error
          rb_Humidity_g = cb_HUMI_ERROR_g;  /*VCO_060*/
          rw_Temperature_g = cw_HUMTEMP_ERROR_g;
          rw_DewPoint_g = cw_HUMTEMP_ERROR_g;
        }
        // power supply is off, so hardreset is done     s_softreset(); // reset Chip
        rb_TaskStatus_s = cb_JUMP_AFTER_ERROR_mg; // step over calculations!
      }
      break;
      
    case 36:  // case 43: calculate temperature compensated rel humidity
      // calculate humidity, use formula so that no intermediate result becomes negative
      
      rb_InErrorModeCounter_s = 0;
      if(rw_TempTicks_g < 6500) /*Temperature lower than 25degC*/
      {
        if (rh_lin_SignNegative_s > 0) /*VDR_427*/
        {
          rw_TempResult_l = 0; /*VDR_427 Result can not be positive!*/
        }
        else
        {
          if ((rw_TempTicks_g < 500 )&&(rw_HumiTicks_g > 3900))
          {
            rw_TempResult_l = (rh_lin-((((6500-rw_TempTicks_g)/50)*(((rw_HumiTicks_g+125)/10)))/100)*4)/10;
          }
          else
          {
            rw_TempResult_l = (rh_lin-((((6500-rw_TempTicks_g)/40)*(((rw_HumiTicks_g+125)/10)))/125)*4)/10;
          }
        }
      }
      else
      {
        if (rh_lin_SignNegative_s > 0) /*VDR_427*/
        {
          rw_TempResult_l = (((((((rw_TempTicks_g -6500)/40)*((rw_HumiTicks_g+125)/10))/125)*4))-rh_lin)/10;
        }
        else
        {
          rw_TempResult_l = (((((((rw_TempTicks_g -6500)/40)*((rw_HumiTicks_g+125)/10))/125)*4))+rh_lin)/10;
        }
      }
      /*Formula for Excel xls =((((((B2-6500))/10)*(((8*B3))-1000))/10000)+E3)/10*/
      /* rh_TRUE=(t_C-25)*(T1+T2*rh)+rh_lin; //calc. temperature compensated humidity [%RH]*/
      if(rw_TempResult_l > 10000) // underflow occured?
      {
        rw_TempResult_l = 0; // 0%
      }
      else if(rw_TempResult_l > 1000) // result over 100%
      {
        rw_TempResult_l = 1000; // 100%
      }
      else
      {
        /*MISRA-Dummy*/
      }
      
      /*VCO_060 dynamic compensation*/
      rw_HumResult_comp_l = dynamicCompensation(rw_TempResult_l);
      if(rw_HumResult_comp_l > 1000) // result over 100%
      {
        rw_HumResult_comp_l = 1000; // 100%
      }
      else
      {
        /*MISRA-Dummy*/
      }
      
      if(rw_HumResult_comp_l > 2)
      {
        rb_HumidityDynComp_temp_s =(byte)(1+ ((rw_HumResult_comp_l+3)/5)); // +3 for rounding
      }
      else
      {
        rb_HumidityDynComp_temp_s= 1;
      }
      
      
      if(rw_TempResult_l > 2)
      {
        rb_Humidity_raw_g = (byte)(1+ ((rw_TempResult_l+3)/5)); // +3 for rounding
      }
      else
      {
        rb_Humidity_raw_g = 1;
      }
      rb_TaskStatus_s++;   // increase TaskStatus
      break;
#ifndef __NUR_FEUCHTE_
    case 41: // calculate offset for temperature and for humidity! 
      
      CalculatHumidityOffsett (); 
      rb_TaskStatus_s++;   // increase TaskStatus
      break; 
#endif         
    case 47:   // case 52: calculate dewpoint
      /* put values on Bus to have all synchron*/
      rb_Humidity_g = rb_HumidityDynComp_temp_s; /*use dynamic compensated humidity for LIN*/
      if(rw_TempTicks_g > 50) //calculate for Bus interface
      {
        /*offset for database starts at 39,6GradC Change done in Data Link Layer*/
        rw_Temperature_g = (rw_TempTicks_g)/10;
      }
      else
      {
        rw_Temperature_g = 1;
      }
#ifndef __NUR_FEUCHTE_          /*RLS_VCO_96 calculate corrected values*/
      if (rw_Temperature_g > rb_negativeTemperatureOffset_g)
      {
        rw_CompensatedSelfheatTemperature_g = rw_Temperature_g - rb_negativeTemperatureOffset_g; 
      }
      else 
      {
        rw_CompensatedSelfheatTemperature_g = 1; 
      }
      
      if ((rb_Humidity_g+(rb_DeltaFTemp_g)) < 201)
      {
        rb_CompensatedSelfheatHumidity_g = (rb_Humidity_g+rb_DeltaFTemp_g); 
      }
      else 
      {
        rb_CompensatedSelfheatHumidity_g = 201; 
      }
      
#endif
      
#ifdef SW0100
      rw_TempResult_l = calc_dewpoint((rb_Humidity_g>>1),rw_TempTicks_g); /*VDR_346*/
#else
      rw_TempResult_l = calc_dewpoint(rb_Humidity_g,rw_TempTicks_g); /*VDR_346*/
      /*use dynamic compensated humidity for dewpoint*/
#endif
      if(rw_TempResult_l > 1)
      {
        if (rw_Temperature_g < rw_TempResult_l)/*VDR_600 check if dewpoint is higher than temperature*/
        {
          rw_DewPoint_g = rw_Temperature_g;  /*VDR_600 limit dewpoint to temperature*/
        }
        else
        {
          rw_DewPoint_g = rw_TempResult_l; /*copy to dewpoint*/
        }
      }
      else
      {
        rw_DewPoint_g = 1;
      }
      rb_HumTemp_ErrorCode_g = 0; // clear error code
      rbi_HumTempComError_g = FALSE;
      
      rb_TaskStatus_s++;     // increase TaskStatus
      break;
      
      
      
    default:
      if(rb_TaskStatus_s < cb_MEASUREPERIODE_mg)   // Cycletime not over?
      {
        rb_TaskStatus_s++;  // increase task status
      }
      else
      {
        rb_TaskStatus_s = 0; // TaskStatus = 0  start next measurement
        HumTempSensirionON(); /*Switch Power Supply on*/
      }
      break;
    }
  }
  
  /******************************************************************************/
  /*                                                                            */
  /*  Prototype:                                                                */
  /*      void dynamicCompensation(word rw_input_Humidity_l)                    */
  /*                                                                            */
  /*  Description:                                                              */
  /*    this function have to be called in the same frequency than the          */
  /*    measurement of the humidity                                             */
  /*                                                                            */
  /*  Input parameters:                                                         */
  /*    none                                                                    */
  /*                                                                            */
  /*  Output parameters:                                                        */
  /*    none                                                                    */
  /*                                                                            */
  /*  Preconditions:                                                            */
  /*    HumTemp_Init() was called                                               */
  /*                                                                            */
  /*  Postconditions:                                                           */
  /*    none                                                                    */
  /*                                                                            */
  /******************************************************************************/
  /*VCO_060 dynamic compensation*/  
  /**
  * \brief   The has to call this function every 10ms.
  *
  * - function to improve the charakteristics of the sensor. 
  * \ingroup external
  * \pre         HumTemp_Init() was called
  */
#define DYN_COMP_DEVIDER 48
#define DYN_COMP_DEVIDER_ONE 8   
#define DYN_COMP_DEVIDER_TWO (DYN_COMP_DEVIDER/DYN_COMP_DEVIDER_ONE)
#if (cb_MEASUREPERIODE_mg == 85)
#define DYN_COMP_ACD  (byte)(DYN_COMP_DEVIDER*0.42741493) 
  /*<- value to change based on parameters only if sample time changes for HT-Modul*/
#else 
  error wrong parameter 
#endif 
#define DYN_COMP_BCD  (DYN_COMP_DEVIDER-DYN_COMP_ACD)
#define DEF_DYN_COMP_CCD_MINUS   5     /*<- value to change based on parameters set to 0 to switch function off! */
#define DYN_COMP_CCD_MINUS   (2+(rb_DYN_COMP_CCD_MINUS_l))         /*<- parameter from EEPROM */
#define DYN_COMP_DCD    (DYN_COMP_CCD_MINUS + 3)
    
#define CW_MinusFiveDegree_g  (396-50)
#define CW_TenDegree_g        (396+100)
#define CW_TwentyFiveDegree_g (396+250)
#define CW_FourtyDegree_g     (396+400)
    STATIC word dynamicCompensation(word rw_input_Humidity_l)
    {
      /* input humidity should be less than 1000 to avoid overflow*/
      unsigned short int rw_Humidity_dynComensated_l; 
      unsigned short int rw_X_alt_mal_CDD_l; 
      static unsigned short int rw_X_alt_s; 
      static unsigned char rb_HumDynComp_initialised_s; 
      unsigned char rb_DYN_COMP_CCD_MINUS_l; 
      
      
      
      /*RLS_VCO_081 adapt dynamic compensation to temperature*/
      if (rw_Temperature_g < CW_MinusFiveDegree_g)
      {
        rb_DYN_COMP_CCD_MINUS_l = rb_DYN_COMP_CCD_MINUS_belowneg5_g; 
      }
      else if (rw_Temperature_g < CW_TenDegree_g)
      {
        rb_DYN_COMP_CCD_MINUS_l = rb_DYN_COMP_CCD_MINUS_neg5to10_g; 
      }
      else if (rw_Temperature_g < CW_TwentyFiveDegree_g)
      {
        rb_DYN_COMP_CCD_MINUS_l = rb_DYN_COMP_CCD_MINUS_10to25_g; 
      }
      else if (rw_Temperature_g < CW_FourtyDegree_g)
      {
        rb_DYN_COMP_CCD_MINUS_l = rb_DYN_COMP_CCD_MINUS_25to40_g; 
      }   
      else 
      {
        rb_DYN_COMP_CCD_MINUS_l = rb_DYN_COMP_CCD_MINUS_above40_g; 
      }
      
      
      if ((rb_HumDynComp_initialised_s == TRUE)&&(DYN_COMP_CCD_MINUS >= 3))
        /* is initialised and parameter high enough (aktivated)*/
      {
        rw_X_alt_mal_CDD_l = (rw_X_alt_s * DYN_COMP_CCD_MINUS); 
        rw_Humidity_dynComensated_l = 3+(rw_input_Humidity_l*DYN_COMP_DCD); 
        if (rw_X_alt_mal_CDD_l< rw_Humidity_dynComensated_l)
        {
          rw_Humidity_dynComensated_l =  (rw_Humidity_dynComensated_l - rw_X_alt_mal_CDD_l)/3; 
        }
        else
        {
          rw_Humidity_dynComensated_l = 0;
        }
        rw_X_alt_s = ((((DYN_COMP_ACD *rw_X_alt_s)+(DYN_COMP_DEVIDER_ONE/2))/DYN_COMP_DEVIDER_ONE) + \
          (((DYN_COMP_BCD*rw_input_Humidity_l)+(DYN_COMP_DEVIDER_ONE/2))/DYN_COMP_DEVIDER_ONE)+
            (DYN_COMP_DEVIDER_TWO/2))/DYN_COMP_DEVIDER_TWO; 
      }
      else
      {
        rb_HumDynComp_initialised_s = TRUE; 
        rw_Humidity_dynComensated_l = rw_input_Humidity_l; 
        rw_X_alt_s =  rw_input_Humidity_l;
      }
      return (rw_Humidity_dynComensated_l);
    }
#ifndef __NUR_FEUCHTE_
#define ParameterB_For_H_OFFS 245
#define ParameterC_For_H_OFFS 26748
#define ParameterD_For_H_OFFS 2500
  STATIC void CalculatHumidityOffsett (void)
  {
    unsigned char rb_Temperature_l; /*local variable to store the temperature in degC+40*/
    unsigned int rw_DeltaFTemp_l;   /*local variable to calculate the offset to the humidity*/
    /* Kostanten fuer Berechnung =(-a*(rb_DeltaT_mg^2)+b*rb_DeltaT_mg-c) / D 
    smit fuer negativen Offsett =(a*(rb_DeltaT_mg^2)+c-b*rb_DeltaT_mg) */
    /* nicht benutzt #define ParameterA_For_H_OFFS 1*/
    
    
    /* Berechnung Abweichung Temperatur ---------------------------*/
    
    if (rbi_Modulator_On_g != 0)  /*Filter to create the offset for the temperature for rainsensor on*/
    {
      rw_TemperatureOffsettFilter_g =
        (rw_TemperatureOffsettFilter_g-(rw_TemperatureOffsettFilter_g>>8))+(rb_maxTemperatureOffsett_g); 
    }
    else
    {
      rw_TemperatureOffsettFilter_g =rw_TemperatureOffsettFilter_g-(rw_TemperatureOffsettFilter_g>>8);
    }
    rb_negativeTemperatureOffset_g = (byte) (rw_TemperatureOffsettFilter_g / 2560);  /* Value with 0,1K resolution*/
    
    
    /* Berechnung Abweichung Feuchte --------------------------- */
    
    rb_Temperature_l = (byte) ( rw_Temperature_g / 10);  /*calc temperature with correct scaling*/
    /*Berechne DeltaF bei 100%Feuchte pro Grad in Abhaengigkeit von der Umgebungstemperatur in degC*/
    rw_DeltaFTemp_l = 
      (((rb_Temperature_l*rb_Temperature_l)+ParameterC_For_H_OFFS)-(rb_Temperature_l*ParameterB_For_H_OFFS) )/ 250; 
    
    rb_DeltaFTemp_g = 
      (byte)((2+((((rb_Humidity_raw_g)/2)*((rw_DeltaFTemp_l*rb_negativeTemperatureOffset_g)/10))/ 100))/5); 
    /*Ergebnis ist 10*DeltaF + 2 zur Rundung weil spaeter durch 5 geteilt wird! */
  }
#endif

#endif

#ifdef SENSIRION_SHT21_USED

/******************************************************************************/
/*                                                                            */
/*  Prototype:                                                                */
/*      static byte SHT2x_GetSerialNumber(void)                               */
/*                                                                            */
/*  Description:                                                              */
/*    To read the serial number of SHT module, call ed in the startup         */
/*  Input parameters:                                                         */
/*    none                                                                    */
/*  Output parameters:                                                        */
/*    none                                                                    */
/*  Preconditions:                                                            */
/*    HumTemp_Init() was called                                               */
/*                                                                            */
/*  Postconditions:                                                           */
/*    none                                                                    */
/*                                                                            */
/******************************************************************************/
static byte SHT2x_GetSerialNumber(byte rb_part_l)

{
  byte  rb_error_l=0;                          /* error variable */
  
  if(rb_part_l == cb_PART_1)
  {
    /* Read from memory location 1 */
    s_transstart();
    rb_error_l |= s_write_byte(I2C_ADDR_W);    /* I2C address */
    rb_error_l |= s_write_byte(0xFA);         /* Command for readout on-chip memory*/
    rb_error_l |= s_write_byte(0x0F);         /* on-chip memory address */
    s_transstart();
    rb_error_l |= s_write_byte(I2C_ADDR_R);    /* I2C address */
    SHT21xSerialNumber[5] = s_read_byte(ACK);  /* Read SNB_3 */
    (void)s_read_byte(ACK);                          /* Read CRC SNB_3 (CRC is not analyzed) */
    SHT21xSerialNumber[4] = s_read_byte(ACK);  /* Read SNB_2 */
    (void)s_read_byte(ACK);                          /* Read CRC SNB_2 (CRC is not analyzed) */
    SHT21xSerialNumber[3] = s_read_byte(ACK);  /* Read SNB_1 */
    (void)s_read_byte(ACK);                          /* Read CRC SNB_1 (CRC is not analyzed) */
    SHT21xSerialNumber[2] = s_read_byte(ACK);  /* Read SNB_0 */
    (void)s_read_byte(noACK);                        /* Read CRC SNB_0 (CRC is not analyzed) */
    s_transstop();
  }
  else if(rb_part_l == cb_PART_2)
  {
    /* Read from memory location 2 */
    s_transstart();
    rb_error_l |= s_write_byte(I2C_ADDR_W);     /* I2C address */
    rb_error_l |= s_write_byte (0xFC);          /* Command for readout on-chip memory */
    rb_error_l |= s_write_byte (0xC9);          /* on-chip memory address */
    s_transstart();
    rb_error_l |= s_write_byte(I2C_ADDR_R);    /* I2C address */
    SHT21xSerialNumber[1] = s_read_byte(ACK);  /* Read SNC_1 */
    SHT21xSerialNumber[0] = s_read_byte(ACK);  /* Read SNC_0 */
    (void)s_read_byte(ACK);                          /* Read CRC SNC0/1 (CRC is not analyzed) */
    SHT21xSerialNumber[7] = s_read_byte(ACK);  /* Read SNA_1 */
    SHT21xSerialNumber[6] = s_read_byte(ACK);  /* Read SNA_0 */
    (void)s_read_byte(noACK);                        /* Read CRC SNA0/1 (CRC is not analyzed) */
    s_transstop();
  }
  else
  {}
  return rb_error_l;
}

#endif



/******************************************************************************/
/*                                            */
/* END  Source:         HumTemp.c       */
/*                                              */
/******************************************************************************/