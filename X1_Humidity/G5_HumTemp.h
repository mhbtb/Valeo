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
* %PID: RLS:G5 HUMTEMP H-103382522X5216X80.A-VIT_SOURCE;1.9 %
* %PM: G5_HumTemp.h %
* Description:
* %PD: Item uploaded into Dimensions %
*
******************************************************************************/

/* History                                                                    */
/*----------------------------------------------------------------------------*/
/* Date      VDR_Number  Name    Description                                       */
/*----------------------------------------------------------------------------*/
/* 23.02.11  RLS_VCO_96  AL       FS_Implement Selfheating Compensation */
/* 22.11.10  RLS_VCO_88  AL     defines for Default Parameters in EEPROM for 
                                dynamic compensation*/
/* 14.07.10  VCO_060     AL     implement dynamic optimisation*/
/* 24.02.10  VDR_450     FS     Due to Optimization for NurFeuchte update header*/
/* 14.11.2014 VCO_196     NB     Improve the error detection of SHT module in case of short to ground */
/*09.12.14   VCO_205     NB      Read serieal number of SHT module */
/* 24.02.2015 VDR_850     NB     After removing HT module from sensor the HT error displayed after 40s in the LIN Bus*/
/* 01.06.2015 VDR_877     NB     Sensor reset when SHT module is not connected */
/*02.12.15      VDR_939         NB      Improvement of SHT module measurement */                                  
/******************************************************************************/
#ifndef _HUMTEMP_H_
#define _HUMTEMP_H_
/**********************************************
 *       Projekt defines and typedefs
 ***********************************************/
/*Following line is Out-Commented due to Standard Misra Check Tool QA-C*/
/*#pragma diag_suppress=Pm093 */ /*VDR_87 switch on Misra Warning for MISRA Rule 109*/
/*#define word unsigned int*/
/*#define uByte unsigned char                *//* unsigned 8 bit type definition  */
/*#define uWord unsigned int                 *//* unsigned 16 bit type definition */

/*VDR_Following lines not needed: Out-commented*/
/*#define sbyte signed char ;
#define sword signed int ;
typedef unsigned char * pbyte;
typedef unsigned char * psbyte;
typedef unsigned int * pword;
typedef signed int * psword;
typedef const unsigned char cbyte;
typedef const signed char csbyte;
typedef const unsigned int cword;
typedef const signed int csword;*/

#define SENSIRION_SHT21_USED

#define NOP() asm("NOP")// _NOP

#define STATIC static 



/**
 * \defgroup external Interface Description
 * \file HumTemp.h
 * \brief H File for the Humidity Temperature Module "HUMTEMP Modul".
 *
 *  Contains all puplic elements like functions etc. for the application.
 *
 * <!--  -->
 * \b Source:     humtemp.h
 * \version       1.6
 * \author        laegler
 * \author        SBA294
 * \date          17-APR-2007 16:24:39
 *
 * <!--  -->
 */

/******************************************************************************/

/******************************************************************************/


/******************************************************************************/
/*                 Definition of exported symolic constants                   */
/******************************************************************************/

/******************************************************************************/
/*  Comment:  Communication Error Code  (rb_HumTemp_ErrorCode_g)              */
/*  Range  :  0-255                                                           */
/** \brief Defines error code for rb_HumTemp_ErrorCode_g 'no communication error' */
#define cb_HTERR_NONE_g          0
/** \brief Defines error code for rb_HumTemp_ErrorCode_g 'checksum error' */
#define cb_HTERR_CHECKSUM_g   0x01
/** \brief Defines error code for rb_HumTemp_ErrorCode_g 'Error during write command' */
#define cb_HTERR_WRITECMD_g   0x02
/** \brief Defines error code for rb_HumTemp_ErrorCode_g 'No respnse error' */
#define cb_HTERR_TIMEOUT_g    0x04
/** \brief Defines error code for rb_HumTemp_ErrorCode_g 'out of range' */
#define cb_HTERR_HUMIOUTOFRANGE_g 0x08 /*VCO_037 new Failure*/
/** \brief Defines error code for rb_HumTemp_ErrorCode_g 'out of range' */
#define cb_HTERR_TEMPOUTOFRANGE_g 0x10 /*VCO_037 new Failure*/
/******************************************************************************/
/*  Comment:  Init and Error value for Temperature, Humidity and Dewpoint     */
/** \brief Define for 'Init' applicable for Temperature, Humidity and Dewpoint*/
#define cw_HUMTEMP_INIT_g       0
/** \brief Define for 'Error' applicable for Temperature, and Dewpoint*/
#define cw_HUMTEMP_ERROR_g      0xFFFFU
/** \brief Define for 'Error' applicable for  Humidity*/
#define cb_HUMI_ERROR_g      0xFF /*VCO_060 use only byte */
/******************************************************************************/
/*  Comment:  Status of Heating element                                       */
/*  Range  :  0-1                                                             */
/** \brief Define for Heater off*/
#define cb_HEATEROFF_g     0
/** \brief Define for Heater on*/
#define cb_HEATERON_g      1

#define SHT_SUPPLY_RETRY_ATTEMPT  30 /* VDR_850 */
#define SHT_COMM_ERR_RETRY_ATTEMPT  255
#define cb_JumpAfterShtPowerFail    65
/******************************************************************************/
/*                Definition of exported function like macros                 */
/******************************************************************************/

/******************************************************************************/
/*          Definition of exported types (typdefs, enums, struct, union)      */
/******************************************************************************/

/******************************************************************************/
/*                    Declaration of exported variables                       */
/******************************************************************************/
/* PRQA S 0759 1*//*<< 0759:union needed to reduce RAM usage >>*/
extern SHORT_MEMORY  Flag uF_Humi_g;              // variable for flag for timer

#define rbi_HumiSupply_OK_g	   (uF_Humi_g.Bit.B0)             /* flag for Humidity module supply measurement */
#define rbi_SHT_DataLine_OK_g	   (uF_Humi_g.Bit.B1)             /* flag for Humidity module supply measurement */
#define rbi_First_Call_g	   (uF_Humi_g.Bit.B2)             /* To Indicate first call or concecutive call */
  /**
   * \ingroup external
   * \brief exported variable containing raw Humidity.
   * (Factor 0.5 Offset -0.5 [eg. 201 equals 100%%rH]) */
extern  unsigned char rb_Humidity_raw_g;  /*VCO_060 use only byte */
  /**
   * \ingroup external
   * \brief exported variable containing dyn compensated Humidity.
   * (Factor 0.5 Offset -0.5 [eg. 201 equals 100%%rH]) */
extern  unsigned char rb_Humidity_g;  /*VCO_060 use only byte */

  /**
   * \ingroup external
   * \brief exported variable containing Temperature.
   * (Factor 0.1 Offset -39.6 [eg. 596 equals 20GradC]) */
extern  unsigned int rw_Temperature_g;
extern  unsigned int rw_Temperature_raw_g;
#ifdef SENSIRION_SHT21_USED
extern unsigned char SHT21xSerialNumber[8];
#else
/**
   * \ingroup external
   * \brief exported variable containing humidity Rainsensor Selfheating is
   *  substracted.
   * (Factor 0.5 Offset -0.5 [eg. 201 equals 100%%rH]) */
extern  unsigned char rb_CompensatedSelfheatHumidity_g;
/**
   * \ingroup external
   * \brief exported variable containing Temperature Rainsensor Selfheating is
   *  substracted.
   * (Factor 0.1 Offset -39.6 [eg. 596 equals 20GradC]) */
extern  unsigned int rw_CompensatedSelfheatTemperature_g;

#endif
  /**
   * \ingroup external
   * \brief exported variable containing Dewpoint.
   * (Factor 0.1 Offset -39.6 [eg. 596 equals 20GradC]) */
extern  unsigned int rw_DewPoint_g;
/**
 * \ingroup external
 * \brief exported variable containing communication error code */
extern  unsigned char rb_HumTemp_ErrorCode_g;

/**
 * \brief Temperature [Ticks] 14 Bit (TGradc = rw_TempTicks_g * 0.04-40).
 * rw_TempTicks_g is the 14bit sensor readout for Temperature. Range 0-3fff*/
extern  unsigned int rw_TempTicks_g; /*VCO_037 external needed*/
/**
* \brief Humidity [Ticks] 12 Bit (TGradc = rw_TempTicks_g * 0.04-40)
* rw_HumiTicks_g is the 12bit sensor readout for Temperature. Range 0-0fff*/
extern  unsigned int rw_HumiTicks_g; /*VCO_037 external needed*/

extern  unsigned char rb_SHT_SupplyRetryCounter_g;
extern  unsigned char rb_SHT_ComErrRetryCounter_g;

/**
 * \ingroup external
 * \brief exported variable Error flag, will be written in DTC if set */
extern unsigned char rbi_HumTempComError_g;
/**
 * \ingroup external
 * \brief Error counter, increased on communication failure, exported to be read out in diag mode */
extern unsigned char rb_StaticHumTempErrorCounter_g;
/**
 * \ingroup external
 * \brief Error mode debounce counter, exported to be read out in diag mode */
extern word rw_InErrorModeCounter_s;


/******************************************************************************/
/*                  Declaration of exported constant data                     */
/******************************************************************************/
/*RLS_VCO88 defines for Default Parameters in EEPROM for dynamic compensation*/
#define cb_DYN_COMP_CCD_MINUS_belowneg5_DEF  0x0A
#define cb_DYN_COMP_CCD_MINUS_neg5to10_DEF   0x08
#define cb_DYN_COMP_CCD_MINUS_10to25_DEF     0x06 
#define cb_DYN_COMP_CCD_MINUS_25to40_DEF     0x03
#define cb_DYN_COMP_CCD_MINUS_above40_DEF    0x00
/* Defines for Selfheating compensation*/
#define CB_DEF_MAXTEMPERATUREOFFSET_G 70 /* 100 entspricht 1 Grad 0..255 (0K-2,55K)*/
/******************************************************************************/
/*               Declaration of exported function prototypes                  */
/******************************************************************************/

extern void HumTemp_Init(void);
extern void HumTemp_Handler(void);
extern void HumTemp_Heater(unsigned char rb_HeaterStatus_l);
extern unsigned char HumTemp_GetHeaterStatus(void);

/******************************************************************************/

/******************************************************************************/
/* PCMS_HEADER_SUBSTITUTION_START                                           */
/* END  Source:         PM       */
/* PCMS_HEADER_SUBSTITUTION_END                                             */
/******************************************************************************/


#endif /*_HUMTEMP_H_*/
