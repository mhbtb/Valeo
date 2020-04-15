#ifndef G5_APPLI_MAIN_H
#define G5_APPLI_MAIN_H
/*************************************************************************

  Company : Valeo Wiper System

  Project : RLT Sensor, RDN Sensor

  Component : main.h

  Documentation reference : Software Specification
  Overview of the component : interface to the electronics

  Evolution of the component : see PVCS Version control system

                Initials   date   modification

*************************************************************************/
/* History                                                                    */
/*----------------------------------------------------------------------------*/
/* Date      VDR_Number     Description                                       */
/*----------------------------------------------------------------------------*/
/*                                                                              */
/* 31.03.11  VCO_092   AL   Add additional counters for SW-Watchdog */
/* 24.03.11  VDR_638   AL   MISRA OPTIMISATION with corrections in Source code PARTLY */
/* 03.02.08  VDR_87          no Software hangup*/
/* 26.05.10  VCO_050     AL      switch light on for one cylce after watchdog reset*/
/******************************************************************************/
/* 26.08.2014  VDR_801    NB    Findings from Integration test               */
/* 04.05.2015  VDR_871    NB    :Safety: all reset sources from RESF should be used except the voltage detector flag */
/* 10.06.2015  VDR_868    NB    All:QAC and Polyspace fixing for SW009 Release  */  
/* 02.12.2015 VDR_940   NB      write reset source in EEPROM                 */
/****************************************************************************/
/** Definition for Mono-Inclusion **/
/****************************************************************************/

#ifdef _main_c_
#define EXTERN /**/
#else
#define EXTERN  extern
#endif


/* bytes to check different Watchdog conditions */
EXTERN SHORT_MEMORY byte rb_WDG_500usTaskCounter_g ;
EXTERN byte rb_WDG_IORefreshTaskCounter_g ;
EXTERN byte rb_WDG_BusTaskCounter_g;
EXTERN byte rb_WDG_RainsensorTaskCounter_g;
EXTERN byte rb_WDG_SCITaskCounter_g; /*VCO_92 implement add. counter*/
EXTERN byte rb_WDG_LVITaskCounter_g; /*VCO_92 implement add. counter*/
EXTERN byte rb_WDG_LightsensorTaskCounter_g;
EXTERN byte rb_SevenToZeroCounter_g;

EXTERN __no_init byte rb_ResetSource_g;
EXTERN __no_init byte rab_InternalResetIndicator[4]; /* VDR_871 */
/*Time in 10ms to check Watchdog counters(max: 20 definition to be checked with watchdog reset time internal/external)*/
#define cb_WDGCALLCOUNTERCYCLE_mg    (byte)7        
#define cb_FASTTASKCALL_TOLERANCE_mg (byte)10        /* Tolerance for 1ms Task [1ms]*/
/* min boarder of Window for 1ms Task counter */
#define cb_FASTTASKCALLS_MIN_mg      ((byte)(((cb_WDGCALLCOUNTERCYCLE_mg)*20) - cb_FASTTASKCALL_TOLERANCE_mg))  
/* max boarder of Window for 1ms Task counter */
#define cb_FASTTASKCALLS_MAX_mg      ((byte)(((cb_WDGCALLCOUNTERCYCLE_mg)*20) + cb_FASTTASKCALL_TOLERANCE_mg))  
#define cb_WDG_STB_10MSTIMEOUT_g      7



EXTERN  byte rb_WDGFastTaskCounterMin_g;
EXTERN  byte rb_WDGFastTaskCounterMax_g;

/****************************************************************************/
/*              Global Contants and Makros                                  */
/****************************************************************************/
/* PRQA S 3412 8 *//*<< required for readability  >>*/
#define INITIAL_WATCHDOG() WDTM = 0x7F; WDTE = 0xAC
#define REFRESH_INTERNAL_WATCHDOG() WDTE = 0xAC
#define REFRESH_EXTERNAL_WATCHDOG()   po_ExternalWDG_g = TRUE; po_DExternalWDG_g = OUTPUT
#define SETLOW_EXTERNAL_WATCHDOG()   po_ExternalWDG_g =FALSE

#define ENABLE_INTERRUPT() _EI ()                /* enable interrupts */
#define DISABLE_INTERRUPT() _DI ()               /* Disable Interrupt */
#define SOFTWARE_RESET() WDTE = 0x50;  WDTE = 0x05;WDTE = 0x50 /*VDR_87 request reset of Watchdog*/

/*************************************************************************
Declaration of exported functions
**************************************************************************/
/* PRQA S 0841 7 */ /* <<for easier declaration of variable -> proven mechanism>> */
#undef EXTERN



#endif