#ifndef G5_SPI_H
#define G5_SPI_H
/*************************************************************************

Company : Valeo Wiper System

Project : RLT Sensor, RDN Sensor

Component : SPI.h

Documentation reference : ASIC specification E.140.17A
Overview of the component : interface to the RS ASIC

Evolution of the component : see PVCS Version control system

Initials   date   modification

*************************************************************************/
/**
* \mainpage Rain Light Anti-Fogging Sensor
<!-- * \htmlinclude spi.h.html           -->
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
* Gives an overview over the Interface should be renamed to Interface Specification, but at the moment it is not possible to rename it.
*
* \subsection step3 Data Structures:
* The Data Structures tab contains a brief description of all specified data structures and data fields.
*
* \subsection step4 Files:
* The Files tab contains a brief description of all module files.
*
* \subsection step5 Related Pages:
* The Related Pages contains all existing pages for the FlashE2 module e.g. Integration Guidline, Compile Options,... .
*
* \file SPI.h
* \brief h File for the serieal peripheral interface "SPI.c".
*
* This is the header file for SPI.c

* <!--  -->
* @b Source:     SPI.h
* @version       1.12
* @author        Andreas Lägler
* @author        SBA294
* @date          26-JUL-2007 08:08:38
* @todo          Still open points here
* <!--  -->

*/
/*************************************************************************
**                   Common and module include-file                     **
**************************************************************************/






#ifdef _spi_h_
#define EXTERN	/**/
#else
#define EXTERN	extern
#endif

/*************************************************************************
**                   Declaration of global variables                   **
*************************************************************************/
/** \brief varible shows the actual state of no communication counter*/
EXTERN volatile byte rb_NoCommunicationCounter_g;
/** \brief varible shows the overall number of communication errors*/
EXTERN byte rb_StaticNoCommunicationCounter_g;

#ifdef PC_simulation
EXTERN volatile Flag uF_SPI_flags_g;
#define rbi_SPI_activ_g	    	     	uF_SPI_flags_g.Bit.B0
#define rbi_StandbyModulatorIntegrating_g   uF_SPI_flags_g.Bit.B2
#else
/** \brief flags used in SPI communication*/
EXTERN SHORT_MEMORY volatile Flag uF_SPI_flags_g;
/** \brief flags monitors if SPI is active*/
#define rbi_SPI_activ_g  	    	     	uF_SPI_flags_g.Bit.B0
/** \brief flags monitors if SPI is active and AD-conversion is not completed*/
#define rbi_AD_Conversion_OR_SPI_Active_g                 uF_SPI_flags_g.Bit.B1
/** \brief flags monitors that standby mode is integrating*/
#define rbi_StandbyModulatorIntegrating_g   uF_SPI_flags_g.Bit.B2
#endif

/** \brief debug information for SPI Communication problems*/
EXTERN byte rb_SPI_Active_ProblemCounter_g;

/** Function Prototypes **/
EXTERN void spi_init(void);
EXTERN __callt void SPI_WriteBlock(byte *rb_FirstbyteToWrite_l,byte rb_lenghtOfBlock);
//#define SPI_Write_Byte(a)  SPI_WriteBlock(&a,1)
EXTERN __callt void SPI_Write_Byte(byte rb_byteToWrite_l);
EXTERN void  SPI_int(void);
#undef EXTERN

#endif