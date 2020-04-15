#ifndef G5_ICTEST_H 
#define G5_ICTEST_H

/*************************************************************************

Company : Valeo Wiper System

Project : RLT Sensor, RDN Sensor

Component : ictest.h

Documentation reference : Hardware Software Interface File
Overview of the component : interface to the electronics

Evolution of the component : see PVCS Version control system

Initials   date   modification

*************************************************************************/

/****************************************************************************/
/** Definition for Mono-Inclusion **/
/* Date      VDR_Number     Description                                       */
/* 08.12.2014 VCO_151  NB  Implement IC test */
/****************************************************************************/
#ifndef _ictest_c_
#define _ictest_
#endif


#ifdef _ictest_c_
#define EXTERN /**/
#else
#define EXTERN  extern
#endif

/****************************************************************************/
/** Global Variables **/
/****************************************************************************/
EXTERN byte rb_ICTest_state_g;

/* PRQA S 0759 5 *//*<< 0759:union needed to reduce RAM usage >>*/
EXTERN SHORT_MEMORY volatile Flag uF_ICT_Flags_g;

#define rbi_ICClock_old_g     	          uF_ICT_Flags_g.Bit.B0
#define rbi_ICTClkPinState_l		  uF_ICT_Flags_g.Bit.B1


/****************************************************************************/
/** Global Flags **/
/****************************************************************************/


/****************************************************************************/
// Global Contants and Makros
/****************************************************************************/
#define CB_NO_ICTEST_S 0

/****************************************************************************/
// Includes for different Derivates with Port definition
/****************************************************************************/


/*************************************************************************
               Declaration of exported functions
**************************************************************************/
EXTERN void ICTEST_Task(void);
EXTERN void ICTEST_init(void);
/* PRQA S 0841 1 */ /* <<for easier declaration of variable -> proven mechanism>> */
#undef EXTERN
#endif