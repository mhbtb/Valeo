#line 1 "vcast_preprocess.11684.17.c"

typedef int VECTORCAST_MARKER__PREPROCESS_START;
#line 1 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\vcast_preprocess.11684.16.c"

typedef int VECTORCAST_MARKER__UNIT_PREFIX_START;

typedef int VECTORCAST_MARKER__UNIT_PREFIX_END;
#line 1 "C:\\baseline\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_RLS_LIN_GEELY2DOT0.c"
/* PRQA S 3619 EOF */ /* << IAR-Compiler allows whitespaces>> */
/* PRQA S 3116 EOF */ /* << pragma directives needed, compiler specific>>*/
/*************************************************************************

  Company : Valeo Wiper System

  Project : RLT Sensor, RDN Sensor

  Component : RLS_LINST.c

  Documentation reference   : Software Requrement Specification
  Overview of the component : LIN- Data Link layer

  Evolution of the component : see PVCS Version control system

                Initials   date   modification

*************************************************************************/
/* History                                                                    */
/*----------------------------------------------------------------------------*/
/* Date      VDR_Number     Description                                       */
/* DD.MM.YY*/
/*----------------------------------------------------------------------------*/
/* 05.09.11 VDR_705  PCG  - Send detection of Rain Sensor at any time not only when active */
/* 31.08.11 VDR_700  PCG  - Set Light Sensitivity "0" like LS "4". Set default to "4" instead of "0" 
                          - Reorganize signals related to Message CEM_L8_FrP04 */
/* 13.05.11 VDR_659  PCG  - QA-C                       */
/* 12.05.11 VDR_634  PCG  - removed changes from 10.May.11 */
/* 10.05.11 VDR_634  PCG  - set adapterrrainsensacrive failure when no master msg is received */
/* 24.03.11 VDR_647  FS   - Variable name changed*/ 
/* 18.03.11 VDR_66   PCG  - RLS_VDR_633 RLS_VOLVO_Y555 the first frame of RSM partnumber is set to 0 at startup */
/* 17.02.11 VCO_70   PCG  - reduced low limit for WS Transmission due to Blue shade band*/
/* 15.02.11 VDR_580  PCG  - splash bit no more depending on directmode */
/* 17.11.10 VDR_583  PCG  - Corrected Volvo Part Number. SWRS-RSM-001:Req14v1  */
/* 04.11.10 VDR_583  PCG  - Corrected Volvo Part Number. SWRS-RSM-001:Req14v1  */
/* 11.08.10 VCO_73   PCG  - Implemented Rain Sensor Sensitivity up to 8 sensitivities. SWRS-RSM-001:Req34v1 */
/* 06.08.10 VCO_71   PCG  - Implemented Rain Sensor Norm Value: adjust RSM sensitivity when placed on 
*                            different vehicles. SWRS-RSM-001: Req38v1  */
/* 06.08.10 VCO_73   PCG  - Implemented VCC Part Number: 31314540. SWRS-RSM-001:Req14v1  */
/* 05.08.10 VCO_72   PCG  - Implemented Light Sensor Sensitivity: RainSnsrLiSnvty. SWRS-RSM-001:Req51v2  */
/* 03.08.10 VCO_69   PCG  - Implemented new output signal RainSnsrLiMod. SWRS-RSM-001:Req39v2 */
/* 03.08.10 VCO_66   PCG  - Implemented CarCode table values according mail 26.03.2010*/
/* 02.08.10 VCO_67   PCG  - Implemented Rain Sensor active when Terminal_X is set regardless 
*                            Switch Position. SWRS-RSM-001:Req31v1 */
/* 02.08.10 VCO_68   PCG  - Implement New message CEM_L8_FrP04. SWRS-RSM-001:Req19v1 */
/* 30.06.10 VDR_540  FS   - Butterfly Option integrated*/
/* 10.06.10 VCO_49   FS   - Implement long EEPROM PLUS Logging Issues from 11.June --> Park Position corrected*/
/* 10.06.10 VCO_59   FS   - Logging files --> Rework ParkPosition Evaluation*/
/* 26.05.10  VCO_055     AL      reomve debouncing of RAM and ROM error*/
/* 29.04.10 VDR_473  FS   - QA-C*/
/* 26.04.10 VCO_48   FS   - Use "AB" Index instead of only "B" of the partnumer within EEPROM*/
/* 26.04.10 VCO_48   FS   - First Frame of Part number not correct*/
/* 26.03.10  VCO_48   FS   - Update due to Test Drive
 *                           Park contact has been send to late via LIN
                         --> Update in this file and trigger on WiperSpeed_Running Signal
                           - Update internal SCS_Signals, that both ldf can work the same*/
/* 25.03.10  VCO_44   FS   - Implement strategy for Partnumber Read Out
 *                         - delete some parts of VCO_33
 *                         - Switch Stalk Information dependent from CarCode*/
/* 11.02.10  VDR_437  FS   - Index of Ford Partnumber from EEPROM included *
  *                        - Mapping of RainSensorSensitivity not in RAM --> in EEPROM*/
/* 19.01.10  VDR_414  FS    Update due to Testdrive*/
/* 23.12.09  VDR_394  FS    REWORK: New CarCode Table to be implemented, Req: Email from 20091218*/
/* 22.12.09  VDR_362  FS    Rework: Overflow of rb_parkpositioncounter_s MUST have been implemented */
/* 18.12.09  VDR_403  FS    - rb_FixedCarCode deleted
 *                          - Set Auxillary Variable constantly to ALL-value that Ford Partnumber
 *                            can be received by Master for all CarCodes*/
/* 19.11.09  VDR_396  FS    RainSensorEnable as required in SRS*/
/* 17.11.09  VDR_394  FS    Default values windshield and comments*/
/* 01.10.09  VDR_373  FS    "OneTime or Double Overwiped"*/
/* 29.09.09  VDR_362  FS    Implement wipe cancelling when 4 seconds wiper has not moved*/
/* 25.09.09  VDR_368  FS    Requirements from FRSI, SRD, ES and Testcases. See comments in code*/
/* 28.09.09  VDR_360  FS    RainSensorDisable implementation for Ford*/
/* 31.07.09  VDR_355  AL    Changes based on results of function test and     *
           & VDR_356        Review of function from Bosch sensor             */

/* 16.07.09  VDR_344 FS     Updating complete first version to                *
                            first release version due to                      *
                            Ford Meeting in Bietigheim                        */
/* 28.08.15  VCO_268 SP     Cleanup the LIN modules  */
/*02.10.2015 VDR_911 SP     HammingErr shld be part of RS_Error/LS_Error and shld not be used for Active Err*/
/*30.05.2016 VDR_983 NB     Sporadic illegale instruction reset in the startup                              */
/******************************************************************************/


/*************************************************************************
**                   Common and module include-file                     **
**************************************************************************/


#line 1 "C:\\BASELINE\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SWDEV\\01_SRCCODE\\APPLICATION\\DEVICE\\ior5f109be.h"
/*-------------------------------------------------------------------------
 *      Declarations of SFR registers, interrupt and callt vector addresses
 *      for RL78 microcontroller R5F109BE.
 *
 *      This file can be used by both the RL78,
 *      Assembler, ARL78, and the C/C++ compiler, ICCRL78.
 *
 *      This header file is generated from the device file:
 *          DR5F109BE.DVF
 *          Copyright(C) 2011 Renesas
 *          Format version V3.00, File version V1.00
 *-------------------------------------------------------------------------*/








#line 33 "C:\\BASELINE\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SWDEV\\01_SRCCODE\\APPLICATION\\DEVICE\\ior5f109be.h"





#pragma language=save
#pragma language=extended
/**********************************************
 *       Projekt defines and typedefs
 ***********************************************/








typedef unsigned char * pbyte;
typedef unsigned char * psbyte;
typedef unsigned int * pword;
typedef signed int * psword;
typedef const unsigned char cbyte;
typedef const signed char csbyte;
typedef const unsigned int cword;
typedef const signed int csword;




typedef unsigned char byte ;
typedef struct
  {
    unsigned char B0:1;
    unsigned char B1:1;
    unsigned char B2:1;
    unsigned char B3:1;
    unsigned char B4:1;
    unsigned char B5:1;
    unsigned char B6:1;
    unsigned char B7:1;
  } Bit_Feld;

typedef union
  {
    Bit_Feld Bit;
    unsigned char AllBit;
  } Flag;





/*----------------------------------------------
 * SFR bits (default names)
 *--------------------------------------------*/



  typedef struct
  {
    unsigned char no0:1;
    unsigned char no1:1;
    unsigned char no2:1;
    unsigned char no3:1;
    unsigned char no4:1;
    unsigned char no5:1;
    unsigned char no6:1;
    unsigned char no7:1;
  } __BITS8;




  typedef struct
  {
    unsigned char no0:1;
    unsigned char no1:1;
    unsigned char no2:1;
    unsigned char no3:1;
    unsigned char no4:1;
    unsigned char no5:1;
    unsigned char no6:1;
    unsigned char no7:1;
    unsigned char no8:1;
    unsigned char no9:1;
    unsigned char no10:1;
    unsigned char no11:1;
    unsigned char no12:1;
    unsigned char no13:1;
    unsigned char no14:1;
    unsigned char no15:1;
  } __BITS16;


/*----------------------------------------------
 *       SFR declarations
 *--------------------------------------------*/
#line 236 "C:\\BASELINE\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SWDEV\\01_SRCCODE\\APPLICATION\\DEVICE\\ior5f109be.h"

 __no_init volatile union { unsigned char P0; __BITS8 P0_bit; } @ 0xFFF00;
 __no_init volatile union { unsigned char P1; __BITS8 P1_bit; } @ 0xFFF01;
 __no_init volatile union { unsigned char P2; __BITS8 P2_bit; } @ 0xFFF02;
 __no_init volatile union { unsigned char P3; __BITS8 P3_bit; } @ 0xFFF03;
 __no_init volatile union { unsigned char P4; __BITS8 P4_bit; } @ 0xFFF04;
 __no_init volatile union { unsigned char P5; __BITS8 P5_bit; } @ 0xFFF05;
 __no_init volatile union { unsigned char P6; __BITS8 P6_bit; } @ 0xFFF06;
 __no_init volatile union { unsigned char P7; __BITS8 P7_bit; } @ 0xFFF07;
 __no_init volatile union { unsigned char P12; __BITS8 P12_bit; } @ 0xFFF0C;
 __no_init volatile const union { unsigned char P13; __BITS8 P13_bit; } @ 0xFFF0D;
 __no_init volatile union { unsigned char P14; __BITS8 P14_bit; } @ 0xFFF0E;
 __no_bit_access __no_init volatile union { unsigned short SDR00; struct { union { unsigned char SIO00; __BITS8 SIO00_bit; unsigned char TXD0; __BITS8 TXD0_bit; }; }; } @ 0xFFF10;
 __no_bit_access __no_init volatile union { unsigned short SDR01; __BITS16 SDR01_bit; struct { union { unsigned char RXD0; __BITS8 RXD0_bit; }; }; } @ 0xFFF12;
 __no_bit_access __no_init volatile union { unsigned short TDR00; __BITS16 TDR00_bit; } @ 0xFFF18;
 __no_bit_access __no_init volatile union { unsigned short TDR01; __BITS16 TDR01_bit; struct { union { unsigned char TDR01L; __BITS8 TDR01L_bit; }; union { unsigned char TDR01H; __BITS8 TDR01H_bit; }; }; } @ 0xFFF1A;
 __no_bit_access __no_init volatile const union { unsigned short ADCR; __BITS16 ADCR_bit; struct { union { unsigned char dummy; __BITS8 dummy_bit; }; union { const unsigned char ADCRH; const __BITS8 ADCRH_bit; }; }; } @ 0xFFF1E;
__sfr __no_init volatile union { unsigned char PM0; __BITS8 PM0_bit; } @ 0xFFF20;
__sfr __no_init volatile union { unsigned char PM1; __BITS8 PM1_bit; } @ 0xFFF21;
__sfr __no_init volatile union { unsigned char PM2; __BITS8 PM2_bit; } @ 0xFFF22;
__sfr __no_init volatile union { unsigned char PM3; __BITS8 PM3_bit; } @ 0xFFF23;
__sfr __no_init volatile union { unsigned char PM4; __BITS8 PM4_bit; } @ 0xFFF24;
__sfr __no_init volatile union { unsigned char PM5; __BITS8 PM5_bit; } @ 0xFFF25;
__sfr __no_init volatile union { unsigned char PM6; __BITS8 PM6_bit; } @ 0xFFF26;
__sfr __no_init volatile union { unsigned char PM7; __BITS8 PM7_bit; } @ 0xFFF27;
__sfr __no_init volatile union { unsigned char PM12; __BITS8 PM12_bit; } @ 0xFFF2C;
__sfr __no_init volatile union { unsigned char PM14; __BITS8 PM14_bit; } @ 0xFFF2E;
__sfr __no_init volatile union { unsigned char ADM0; __BITS8 ADM0_bit; } @ 0xFFF30;
__sfr __no_init volatile union { unsigned char ADS; __BITS8 ADS_bit; } @ 0xFFF31;
__sfr __no_init volatile union { unsigned char ADM1; __BITS8 ADM1_bit; } @ 0xFFF32;
__sfr __no_init volatile union { unsigned char EGP0; __BITS8 EGP0_bit; } @ 0xFFF38;
__sfr __no_init volatile union { unsigned char EGN0; __BITS8 EGN0_bit; } @ 0xFFF39;
__sfr __no_bit_access __no_init volatile union { unsigned short SDR02; __BITS16 SDR02_bit; struct { union { unsigned char TXD1; __BITS8 TXD1_bit; }; }; } @ 0xFFF44;
__sfr __no_bit_access __no_init volatile union { unsigned short SDR03; struct { union { unsigned char RXD1; __BITS8 RXD1_bit; unsigned char SIO11; __BITS8 SIO11_bit; }; }; } @ 0xFFF46;
__sfr __no_bit_access __no_init volatile union { unsigned short SDR10; struct { union { unsigned char SIO20; __BITS8 SIO20_bit; unsigned char TXD2; __BITS8 TXD2_bit; }; }; } @ 0xFFF48;
__sfr __no_bit_access __no_init volatile union { unsigned short SDR11; __BITS16 SDR11_bit; struct { union { unsigned char RXD2; __BITS8 RXD2_bit; }; }; } @ 0xFFF4A;
__sfr __no_bit_access __no_init volatile union { unsigned char IICA0; __BITS8 IICA0_bit; } @ 0xFFF50;
__sfr __no_init volatile const union { unsigned char IICS0; __BITS8 IICS0_bit; } @ 0xFFF51;
__sfr __no_init volatile union { unsigned char IICF0; __BITS8 IICF0_bit; } @ 0xFFF52;
__sfr __no_bit_access __no_init volatile union { unsigned short TDR02; __BITS16 TDR02_bit; } @ 0xFFF64;
__sfr __no_bit_access __no_init volatile union { unsigned short TDR03; __BITS16 TDR03_bit; struct { union { unsigned char TDR03L; __BITS8 TDR03L_bit; }; union { unsigned char TDR03H; __BITS8 TDR03H_bit; }; }; } @ 0xFFF66;
__sfr __no_bit_access __no_init volatile union { unsigned short TDR04; __BITS16 TDR04_bit; } @ 0xFFF68;
__sfr __no_bit_access __no_init volatile union { unsigned short TDR05; __BITS16 TDR05_bit; } @ 0xFFF6A;
__sfr __no_bit_access __no_init volatile union { unsigned short TDR06; __BITS16 TDR06_bit; } @ 0xFFF6C;
__sfr __no_bit_access __no_init volatile union { unsigned short TDR07; __BITS16 TDR07_bit; } @ 0xFFF6E;
__sfr __no_bit_access __no_init volatile union { unsigned short ITMC; __BITS16 ITMC_bit; } @ 0xFFF90;
__sfr __no_bit_access __no_init volatile union { unsigned char SEC; __BITS8 SEC_bit; } @ 0xFFF92;
__sfr __no_bit_access __no_init volatile union { unsigned char MIN; __BITS8 MIN_bit; } @ 0xFFF93;
__sfr __no_bit_access __no_init volatile union { unsigned char HOUR; __BITS8 HOUR_bit; } @ 0xFFF94;
__sfr __no_bit_access __no_init volatile union { unsigned char WEEK; __BITS8 WEEK_bit; } @ 0xFFF95;
__sfr __no_bit_access __no_init volatile union { unsigned char DAY; __BITS8 DAY_bit; } @ 0xFFF96;
__sfr __no_bit_access __no_init volatile union { unsigned char MONTH; __BITS8 MONTH_bit; } @ 0xFFF97;
__sfr __no_bit_access __no_init volatile union { unsigned char YEAR; __BITS8 YEAR_bit; } @ 0xFFF98;
__sfr __no_bit_access __no_init volatile union { unsigned char SUBCUD; __BITS8 SUBCUD_bit; } @ 0xFFF99;
__sfr __no_bit_access __no_init volatile union { unsigned char ALARMWM; __BITS8 ALARMWM_bit; } @ 0xFFF9A;
__sfr __no_bit_access __no_init volatile union { unsigned char ALARMWH; __BITS8 ALARMWH_bit; } @ 0xFFF9B;
__sfr __no_bit_access __no_init volatile union { unsigned char ALARMWW; __BITS8 ALARMWW_bit; } @ 0xFFF9C;
__sfr __no_init volatile union { unsigned char RTCC0; __BITS8 RTCC0_bit; } @ 0xFFF9D;
__sfr __no_init volatile union { unsigned char RTCC1; __BITS8 RTCC1_bit; } @ 0xFFF9E;
__sfr __no_bit_access __no_init volatile union { unsigned char CMC; __BITS8 CMC_bit; } @ 0xFFFA0;
__sfr __no_init volatile union { unsigned char CSC; __BITS8 CSC_bit; } @ 0xFFFA1;
__sfr __no_init volatile const union { unsigned char OSTC; __BITS8 OSTC_bit; } @ 0xFFFA2;
__sfr __no_bit_access __no_init volatile union { unsigned char OSTS; __BITS8 OSTS_bit; } @ 0xFFFA3;
__sfr __no_init volatile union { unsigned char CKC; __BITS8 CKC_bit; } @ 0xFFFA4;
__sfr __no_init volatile union { unsigned char CKS0; __BITS8 CKS0_bit; } @ 0xFFFA5;
__sfr __no_init volatile union { unsigned char CKS1; __BITS8 CKS1_bit; } @ 0xFFFA6;
__sfr __no_bit_access __no_init volatile const union { unsigned char RESF; __BITS8 RESF_bit; } @ 0xFFFA8;
__sfr __no_init volatile union { unsigned char LVIM; __BITS8 LVIM_bit; } @ 0xFFFA9;
__sfr __no_init volatile union { unsigned char LVIS; __BITS8 LVIS_bit; } @ 0xFFFAA;
__sfr __no_bit_access __no_init volatile union { unsigned char WDTE; __BITS8 WDTE_bit; } @ 0xFFFAB;
__sfr __no_bit_access __no_init volatile union { unsigned char CRCIN; __BITS8 CRCIN_bit; } @ 0xFFFAC;
__sfr __no_bit_access __no_init volatile union { unsigned char DSA0; __BITS8 DSA0_bit; } @ 0xFFFB0;
__sfr __no_bit_access __no_init volatile union { unsigned char DSA1; __BITS8 DSA1_bit; } @ 0xFFFB1;
__sfr __no_bit_access __no_init volatile union { unsigned short DRA0; __BITS16 DRA0_bit; struct { union { unsigned char DRA0L; __BITS8 DRA0L_bit; }; union { unsigned char DRA0H; __BITS8 DRA0H_bit; }; }; } @ 0xFFFB2;
__sfr __no_bit_access __no_init volatile union { unsigned short DRA1; __BITS16 DRA1_bit; struct { union { unsigned char DRA1L; __BITS8 DRA1L_bit; }; union { unsigned char DRA1H; __BITS8 DRA1H_bit; }; }; } @ 0xFFFB4;
__sfr __no_bit_access __no_init volatile union { unsigned short DBC0; __BITS16 DBC0_bit; struct { union { unsigned char DBC0L; __BITS8 DBC0L_bit; }; union { unsigned char DBC0H; __BITS8 DBC0H_bit; }; }; } @ 0xFFFB6;
__sfr __no_bit_access __no_init volatile union { unsigned short DBC1; __BITS16 DBC1_bit; struct { union { unsigned char DBC1L; __BITS8 DBC1L_bit; }; union { unsigned char DBC1H; __BITS8 DBC1H_bit; }; }; } @ 0xFFFB8;
__sfr __no_init volatile union { unsigned char DMC0; __BITS8 DMC0_bit; } @ 0xFFFBA;
__sfr __no_init volatile union { unsigned char DMC1; __BITS8 DMC1_bit; } @ 0xFFFBB;
__sfr __no_init volatile union { unsigned char DRC0; __BITS8 DRC0_bit; } @ 0xFFFBC;
__sfr __no_init volatile union { unsigned char DRC1; __BITS8 DRC1_bit; } @ 0xFFFBD;
__sfr __no_init volatile union { unsigned short IF2; struct { union { unsigned char IF2L; __BITS8 IF2L_bit; }; union { unsigned char IF2H; __BITS8 IF2H_bit; }; }; } @ 0xFFFD0;
__sfr __no_init volatile union { unsigned short MK2; struct { union { unsigned char MK2L; __BITS8 MK2L_bit; }; union { unsigned char MK2H; __BITS8 MK2H_bit; }; }; } @ 0xFFFD4;
__sfr __no_init volatile union { unsigned short PR02; struct { union { unsigned char PR02L; __BITS8 PR02L_bit; }; union { unsigned char PR02H; __BITS8 PR02H_bit; }; }; } @ 0xFFFD8;
__sfr __no_init volatile union { unsigned short PR12; struct { union { unsigned char PR12L; __BITS8 PR12L_bit; }; union { unsigned char PR12H; __BITS8 PR12H_bit; }; }; } @ 0xFFFDC;
__sfr __no_init volatile union { unsigned short IF0; struct { union { unsigned char IF0L; __BITS8 IF0L_bit; }; union { unsigned char IF0H; __BITS8 IF0H_bit; }; }; } @ 0xFFFE0;
__sfr __no_init volatile union { unsigned short IF1; struct { union { unsigned char IF1L; __BITS8 IF1L_bit; }; union { unsigned char IF1H; __BITS8 IF1H_bit; }; }; } @ 0xFFFE2;
__sfr __no_init volatile union { unsigned short MK0; struct { union { unsigned char MK0L; __BITS8 MK0L_bit; }; union { unsigned char MK0H; __BITS8 MK0H_bit; }; }; } @ 0xFFFE4;
__sfr __no_init volatile union { unsigned short MK1; struct { union { unsigned char MK1L; __BITS8 MK1L_bit; }; union { unsigned char MK1H; __BITS8 MK1H_bit; }; }; } @ 0xFFFE6;
__sfr __no_init volatile union { unsigned short PR00; struct { union { unsigned char PR00L; __BITS8 PR00L_bit; }; union { unsigned char PR00H; __BITS8 PR00H_bit; }; }; } @ 0xFFFE8;
__sfr __no_init volatile union { unsigned short PR01; struct { union { unsigned char PR01L; __BITS8 PR01L_bit; }; union { unsigned char PR01H; __BITS8 PR01H_bit; }; }; } @ 0xFFFEA;
__sfr __no_init volatile union { unsigned short PR10; struct { union { unsigned char PR10L; __BITS8 PR10L_bit; }; union { unsigned char PR10H; __BITS8 PR10H_bit; }; }; } @ 0xFFFEC;
__sfr __no_init volatile union { unsigned short PR11; struct { union { unsigned char PR11L; __BITS8 PR11L_bit; }; union { unsigned char PR11H; __BITS8 PR11H_bit; }; }; } @ 0xFFFEE;
__sfr __no_bit_access __no_init volatile union { unsigned short MDAL; __BITS16 MDAL_bit; } @ 0xFFFF0;
__sfr __no_bit_access __no_init volatile union { unsigned short MULA; __BITS16 MULA_bit; } @ 0xFFFF0;
__sfr __no_bit_access __no_init volatile union { unsigned short MDAH; __BITS16 MDAH_bit; } @ 0xFFFF2;
__sfr __no_bit_access __no_init volatile union { unsigned short MULB; __BITS16 MULB_bit; } @ 0xFFFF2;
__sfr __no_bit_access __no_init volatile union { unsigned short MDBH; __BITS16 MDBH_bit; } @ 0xFFFF4;
__sfr __no_bit_access __no_init volatile union { unsigned short MULOH; __BITS16 MULOH_bit; } @ 0xFFFF4;
__sfr __no_bit_access __no_init volatile union { unsigned short MDBL; __BITS16 MDBL_bit; } @ 0xFFFF6;
__sfr __no_bit_access __no_init volatile union { unsigned short MULOL; __BITS16 MULOL_bit; } @ 0xFFFF6;
__sfr __no_init volatile union { unsigned char PMC; __BITS8 PMC_bit; } @ 0xFFFFE;


/*----------------------------------------------
 *       SFR bit declarations
 *--------------------------------------------*/




#line 355 "C:\\BASELINE\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SWDEV\\01_SRCCODE\\APPLICATION\\DEVICE\\ior5f109be.h"









#line 370 "C:\\BASELINE\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SWDEV\\01_SRCCODE\\APPLICATION\\DEVICE\\ior5f109be.h"

































#line 410 "C:\\BASELINE\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SWDEV\\01_SRCCODE\\APPLICATION\\DEVICE\\ior5f109be.h"




#line 421 "C:\\BASELINE\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SWDEV\\01_SRCCODE\\APPLICATION\\DEVICE\\ior5f109be.h"




#line 432 "C:\\BASELINE\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SWDEV\\01_SRCCODE\\APPLICATION\\DEVICE\\ior5f109be.h"




#line 443 "C:\\BASELINE\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SWDEV\\01_SRCCODE\\APPLICATION\\DEVICE\\ior5f109be.h"




#line 455 "C:\\BASELINE\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SWDEV\\01_SRCCODE\\APPLICATION\\DEVICE\\ior5f109be.h"

#line 469 "C:\\BASELINE\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SWDEV\\01_SRCCODE\\APPLICATION\\DEVICE\\ior5f109be.h"

#line 481 "C:\\BASELINE\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SWDEV\\01_SRCCODE\\APPLICATION\\DEVICE\\ior5f109be.h"

#line 490 "C:\\BASELINE\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SWDEV\\01_SRCCODE\\APPLICATION\\DEVICE\\ior5f109be.h"

#line 499 "C:\\BASELINE\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SWDEV\\01_SRCCODE\\APPLICATION\\DEVICE\\ior5f109be.h"

#line 513 "C:\\BASELINE\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SWDEV\\01_SRCCODE\\APPLICATION\\DEVICE\\ior5f109be.h"

#line 525 "C:\\BASELINE\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SWDEV\\01_SRCCODE\\APPLICATION\\DEVICE\\ior5f109be.h"

#line 534 "C:\\BASELINE\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SWDEV\\01_SRCCODE\\APPLICATION\\DEVICE\\ior5f109be.h"

#line 543 "C:\\BASELINE\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SWDEV\\01_SRCCODE\\APPLICATION\\DEVICE\\ior5f109be.h"

#line 557 "C:\\BASELINE\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SWDEV\\01_SRCCODE\\APPLICATION\\DEVICE\\ior5f109be.h"

#line 569 "C:\\BASELINE\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SWDEV\\01_SRCCODE\\APPLICATION\\DEVICE\\ior5f109be.h"

#line 578 "C:\\BASELINE\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SWDEV\\01_SRCCODE\\APPLICATION\\DEVICE\\ior5f109be.h"

#line 587 "C:\\BASELINE\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SWDEV\\01_SRCCODE\\APPLICATION\\DEVICE\\ior5f109be.h"

#line 601 "C:\\BASELINE\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SWDEV\\01_SRCCODE\\APPLICATION\\DEVICE\\ior5f109be.h"

#line 613 "C:\\BASELINE\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SWDEV\\01_SRCCODE\\APPLICATION\\DEVICE\\ior5f109be.h"

#line 622 "C:\\BASELINE\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SWDEV\\01_SRCCODE\\APPLICATION\\DEVICE\\ior5f109be.h"



#pragma language=restore



#line 784 "C:\\BASELINE\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SWDEV\\01_SRCCODE\\APPLICATION\\DEVICE\\ior5f109be.h"

/*----------------------------------------------
 *       Interrupt vector addresses
 *--------------------------------------------*/

#line 841 "C:\\BASELINE\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SWDEV\\01_SRCCODE\\APPLICATION\\DEVICE\\ior5f109be.h"

/*----------------------------------------------
 *       Callt vector addresses
 *--------------------------------------------*/

#line 878 "C:\\BASELINE\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SWDEV\\01_SRCCODE\\APPLICATION\\DEVICE\\ior5f109be.h"

#line 92 "C:\\baseline\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_RLS_LIN_GEELY2DOT0.c"
#line 1 "C:\\baseline\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_projectDefs.h"
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
 *  This file is designed to contain all RLS projects in order to define compiler
 * switches for the RELEASE configuration. The purpose is to have the project -
 * feature relation stored in one header file and thus available for all compilers
 * and third party tools.
 *
 * %PCMS_HEADER_SUBSTITUTION_START:%
 * <table border="0" cellspacing="0" cellpadding="0">
 * <tr> <td> Source:   </td> <td> %PM: template.h %                  </td></tr>
 * <tr> <td> Revision: </td> <td> %PR: 1.8 %                  </td></tr>
 * <tr> <td> Status:   </td> <td> %PS: UNDER_REVIEW %                  </td></tr>
 * <tr> <td> Author:   </td> <td> R.Fichtner, DUS-E-RLS  </td></tr>
 * <tr> <td> Date:     </td> <td> %PUDT: 20-FEB-2013 15:20:57 %                </td></tr>
 * </table>
 * %PCMS_HEADER_SUBSTITUTION_END:%
 * \n
 * <table border="0" cellspacing="0" cellpadding="0">
 * <tr> <td> COMPONENT: </td> <td> XXXX                            </td></tr>
 * <tr> <td> SCOPE:     </td> <td> <Public/Private/Component>      </td></tr>
 * <tr> <td> TARGET:    </td> <td> <All/Freescale S12X/S12XE/...>  </td></tr>
 * </table>
 */
/*----------------------------------------------------------------------------*/
/* Date      VDR_Number   Author   Description                                */
/*----------------------------------------------------------------------------*/
/*09.19.17   VCO_451    NB    All:Add spare LIN IDs in the EEPROM             */
/*07.12.17   VCO_462    HB    FIAT 330: parallel branch                       */
/******************************************************************************/





#line 242 "C:\\baseline\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_projectDefs.h"

#line 93 "C:\\baseline\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_RLS_LIN_GEELY2DOT0.c"
#line 1 "C:\\baseline\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_E2ProjectConfig.h"
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
 * This header file bundles the generic EEPROM configuration with the project
 * specific definitions. Thus, it represents the EEPROM configuration in the
 * context of the given project.
 *
 * <table border="0" cellspacing="0" cellpadding="0">
 * <tr> <td> Author:   </td> <td> RF, DUS-E-RLS  </td></tr>
 * </table>
 * \n
 */
/* * Date      VerNo  Auth         Description                                         */
/*09.11.15   VCO_282    NB    All:Add spare LIN IDs in the EEPROM                      */
/* 07.12.17     VCO_462    HB    FIAT 330 interfaces: parallel branch                  */




#line 1 "C:\\baseline\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_projectDefs.h"
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
 *  This file is designed to contain all RLS projects in order to define compiler
 * switches for the RELEASE configuration. The purpose is to have the project -
 * feature relation stored in one header file and thus available for all compilers
 * and third party tools.
 *
 * %PCMS_HEADER_SUBSTITUTION_START:%
 * <table border="0" cellspacing="0" cellpadding="0">
 * <tr> <td> Source:   </td> <td> %PM: template.h %                  </td></tr>
 * <tr> <td> Revision: </td> <td> %PR: 1.8 %                  </td></tr>
 * <tr> <td> Status:   </td> <td> %PS: UNDER_REVIEW %                  </td></tr>
 * <tr> <td> Author:   </td> <td> R.Fichtner, DUS-E-RLS  </td></tr>
 * <tr> <td> Date:     </td> <td> %PUDT: 20-FEB-2013 15:20:57 %                </td></tr>
 * </table>
 * %PCMS_HEADER_SUBSTITUTION_END:%
 * \n
 * <table border="0" cellspacing="0" cellpadding="0">
 * <tr> <td> COMPONENT: </td> <td> XXXX                            </td></tr>
 * <tr> <td> SCOPE:     </td> <td> <Public/Private/Component>      </td></tr>
 * <tr> <td> TARGET:    </td> <td> <All/Freescale S12X/S12XE/...>  </td></tr>
 * </table>
 */
/*----------------------------------------------------------------------------*/
/* Date      VDR_Number   Author   Description                                */
/*----------------------------------------------------------------------------*/
/*09.19.17   VCO_451    NB    All:Add spare LIN IDs in the EEPROM             */
/*07.12.17   VCO_462    HB    FIAT 330: parallel branch                       */
/******************************************************************************/


#line 285 "C:\\baseline\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_projectDefs.h"

#line 31 "C:\\baseline\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_E2ProjectConfig.h"

#line 1 "C:\\baseline\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_diagnose_GEELY2DOT0_ProjectConfig.h"


/**************VALEO WIPER SYSTEMS**SMART*SENSORS************************
*                                                                       *
*  HEADER FILE NAME : DiagnoseVWK.h              				*
*                                                                       *
*  LIBRARY ID       :                                                   *
*                                                                       *
*  DESCRIPTION      : interface LIN                                     *
*									*
*									*
*                                                                       *
*  SPECIAL LOGIC    :                                                   *
*                                                                       *
*************************************************************************
*                                                                       *
*                         MODIFICATION LOG                              *
*                                                                       *
* Date      VerNo  Description                                 Auth     *
* --------  -----  ------------------------------------------  -------- *
* 27.06.11  VDR_671  new release label                            AL    *
* 13.12.10  RLS_VCO_90  AL RS-Error Classification                      *
* 18.11.10  VCO_086  AL    implement FS-Services for Diagnostics        *
* 23.11.00   1.0   Initial Release				JS      *
* 29.02.08        VDR_152 , VDR155 new function ID              AL      *
* 10.03.08        VDR_157 , Dewpoint not set correct            AL      *
* 20.10.08  VCO_12    SW-Partnumber index and Humidity disable   AL     *
* 29.09.09  VDR_376 new version for AUDI Konzernsensor          AL      *
* 10.07.10 "RLS_VCO_63","RLS_VCO_64", AL use two default variables for RLS and RLF */
/* 22.09.14 RLS_VCO_152 : Customenr part number shall be stored in EEPROM */
/*14.04.15   VCO_243     NB      Implement Function ID and Variant ID in the EEPROM PD section */
/*29.06.15  VCO_256  NB  Introduce systembezeichnung G397_RLSS and set invalid as default      */
/*19.02.16  VCO_313  NB  Create new variant Feuchte_Solar and Rain_Light_solar for SEAT        */
/*25.02.16  VCO_313  NB  Create new variant Feuchte_Solar and Rain_Light_solar for SEAT        */ 
/*06.02.17  VCO_376  NB  Seat:Implement seat LID for service 0x22                              */ 
/************************************************************************/

#line 1 "C:\\baseline\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_projectDefs.h"
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
 *  This file is designed to contain all RLS projects in order to define compiler
 * switches for the RELEASE configuration. The purpose is to have the project -
 * feature relation stored in one header file and thus available for all compilers
 * and third party tools.
 *
 * %PCMS_HEADER_SUBSTITUTION_START:%
 * <table border="0" cellspacing="0" cellpadding="0">
 * <tr> <td> Source:   </td> <td> %PM: template.h %                  </td></tr>
 * <tr> <td> Revision: </td> <td> %PR: 1.8 %                  </td></tr>
 * <tr> <td> Status:   </td> <td> %PS: UNDER_REVIEW %                  </td></tr>
 * <tr> <td> Author:   </td> <td> R.Fichtner, DUS-E-RLS  </td></tr>
 * <tr> <td> Date:     </td> <td> %PUDT: 20-FEB-2013 15:20:57 %                </td></tr>
 * </table>
 * %PCMS_HEADER_SUBSTITUTION_END:%
 * \n
 * <table border="0" cellspacing="0" cellpadding="0">
 * <tr> <td> COMPONENT: </td> <td> XXXX                            </td></tr>
 * <tr> <td> SCOPE:     </td> <td> <Public/Private/Component>      </td></tr>
 * <tr> <td> TARGET:    </td> <td> <All/Freescale S12X/S12XE/...>  </td></tr>
 * </table>
 */
/*----------------------------------------------------------------------------*/
/* Date      VDR_Number   Author   Description                                */
/*----------------------------------------------------------------------------*/
/*09.19.17   VCO_451    NB    All:Add spare LIN IDs in the EEPROM             */
/*07.12.17   VCO_462    HB    FIAT 330: parallel branch                       */
/******************************************************************************/


#line 285 "C:\\baseline\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_projectDefs.h"

#line 39 "C:\\baseline\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_diagnose_GEELY2DOT0_ProjectConfig.h"

// ------------------ configuration for AUDI B8 Diagnose --------------


















// ------------------ defines for AUDI B8 Diagnose --------------









/*is rain function */












//#define cw_SupplierID_g             0x0066

/*--------
 00001111
 0000FLSR
Bit 7 dedicated for Response_error. if set, error shall be sent in FS frame else in RLS frame
 --------*/
#line 100 "C:\\baseline\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_diagnose_GEELY2DOT0_ProjectConfig.h"

#line 84 "C:\\baseline\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_E2ProjectConfig.h"




#line 1 "C:\\baseline\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_DiagE2_projectconfig.h"
/**************VALEO Switches and Detection Systems**SMART*SENSORS*******
*                                                                       *
*  HEADER FILE NAME : DiagE2_projectconfig.h                      *
*                                                                       *
*  LIBRARY ID       :                                                   *
*                                                                       *
*  DESCRIPTION      : - interface for all projects, when                *
*                        define "__USE_OLD_DIAGE2CONFIG_H__" is not set *
*                     - sets all EEPROM header files project related    *
*                     - sets error when project is unknown              *
*                                                                       *
*  SPECIAL LOGIC    :                                                   *
*                                                                       *
*************************************************************************
*                                                                       *
*                         MODIFICATION LOG                              *
*                                                                       *
* Date      VerNo  Description                                 Auth     *
* DD.MM.YY  -----  ------------------------------------------  -------- */
/* 27.11.2014   VCO_200    NB     Include structure  */
/* 09.11.15      VCO_282 NB      All:Add spare LIN IDs in the EEPROM    */
/* 07.12.17     VCO_462    HB    FIAT 330 interfaces: parallel branch   */
/************************************************************************/



#line 1 "C:\\baseline\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_projectDefs.h"
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
 *  This file is designed to contain all RLS projects in order to define compiler
 * switches for the RELEASE configuration. The purpose is to have the project -
 * feature relation stored in one header file and thus available for all compilers
 * and third party tools.
 *
 * %PCMS_HEADER_SUBSTITUTION_START:%
 * <table border="0" cellspacing="0" cellpadding="0">
 * <tr> <td> Source:   </td> <td> %PM: template.h %                  </td></tr>
 * <tr> <td> Revision: </td> <td> %PR: 1.8 %                  </td></tr>
 * <tr> <td> Status:   </td> <td> %PS: UNDER_REVIEW %                  </td></tr>
 * <tr> <td> Author:   </td> <td> R.Fichtner, DUS-E-RLS  </td></tr>
 * <tr> <td> Date:     </td> <td> %PUDT: 20-FEB-2013 15:20:57 %                </td></tr>
 * </table>
 * %PCMS_HEADER_SUBSTITUTION_END:%
 * \n
 * <table border="0" cellspacing="0" cellpadding="0">
 * <tr> <td> COMPONENT: </td> <td> XXXX                            </td></tr>
 * <tr> <td> SCOPE:     </td> <td> <Public/Private/Component>      </td></tr>
 * <tr> <td> TARGET:    </td> <td> <All/Freescale S12X/S12XE/...>  </td></tr>
 * </table>
 */
/*----------------------------------------------------------------------------*/
/* Date      VDR_Number   Author   Description                                */
/*----------------------------------------------------------------------------*/
/*09.19.17   VCO_451    NB    All:Add spare LIN IDs in the EEPROM             */
/*07.12.17   VCO_462    HB    FIAT 330: parallel branch                       */
/******************************************************************************/


#line 285 "C:\\baseline\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_projectDefs.h"

#line 28 "C:\\baseline\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_DiagE2_projectconfig.h"


/* Include PD first place */
#line 1 "C:\\baseline\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_GEELY2DOT0_DiagE2Mapping_PD.h"


/* PRQA S 3619 EOF */ /* << 2010 01 08, compiler allows whitespaces:due to readable code, keep whitespaces! >> */
/* PRQA S 2217 EOF */ /* << 2011 03 03, Code would be not readable >> */
/* PRQA S 750,759 EOF *//*<< 0750:union needed to reduce RAM usage >>*/
/* PRQA S 1015 EOF *//*<< 1015:__far needed for IAR compiler  >>*/
/* PRQA S 3453 EOF *//*<< Macro is more readle and convinient in this situation >>*/
/* PRQA S 857 EOF *//*<< Macro exceeds 1024 number  >>*/


/******************************************************************************/
/* History                                                                    */
/*----------------------------------------------------------------------------*/
/* Date      VDR_Number  Author   Description                                       */
/*-DD.MM.YY-------------------------------------------------------------------*/
/* see G5_DiagE2Mapping_Konzern.h for old history */
/* 15.09.14   VCO_183 NB  Rearrangement of EEPROM */
/* 15.09.14   VCO_184 NB Checksum for calibration data */
/* 22.09.14   VCO_152 NB Customenr part number shall be stored in EEPROM */
/* 29.09.14   VCO_172 NB AUDI_Coding of Parkposition on LIN */
/* 13.05.15   VCO_243 NB Implement Function ID and Variant ID in the EEPROM PD section */
/* 10.11.15     VCO_282    NB    All:Add spare LIN IDs in the EEPROM             */

#line 1 "C:\\baseline\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_projectDefs.h"
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
 *  This file is designed to contain all RLS projects in order to define compiler
 * switches for the RELEASE configuration. The purpose is to have the project -
 * feature relation stored in one header file and thus available for all compilers
 * and third party tools.
 *
 * %PCMS_HEADER_SUBSTITUTION_START:%
 * <table border="0" cellspacing="0" cellpadding="0">
 * <tr> <td> Source:   </td> <td> %PM: template.h %                  </td></tr>
 * <tr> <td> Revision: </td> <td> %PR: 1.8 %                  </td></tr>
 * <tr> <td> Status:   </td> <td> %PS: UNDER_REVIEW %                  </td></tr>
 * <tr> <td> Author:   </td> <td> R.Fichtner, DUS-E-RLS  </td></tr>
 * <tr> <td> Date:     </td> <td> %PUDT: 20-FEB-2013 15:20:57 %                </td></tr>
 * </table>
 * %PCMS_HEADER_SUBSTITUTION_END:%
 * \n
 * <table border="0" cellspacing="0" cellpadding="0">
 * <tr> <td> COMPONENT: </td> <td> XXXX                            </td></tr>
 * <tr> <td> SCOPE:     </td> <td> <Public/Private/Component>      </td></tr>
 * <tr> <td> TARGET:    </td> <td> <All/Freescale S12X/S12XE/...>  </td></tr>
 * </table>
 */
/*----------------------------------------------------------------------------*/
/* Date      VDR_Number   Author   Description                                */
/*----------------------------------------------------------------------------*/
/*09.19.17   VCO_451    NB    All:Add spare LIN IDs in the EEPROM             */
/*07.12.17   VCO_462    HB    FIAT 330: parallel branch                       */
/******************************************************************************/


#line 285 "C:\\baseline\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_projectDefs.h"

#line 25 "C:\\baseline\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_GEELY2DOT0_DiagE2Mapping_PD.h"



#line 40 "C:\\baseline\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_GEELY2DOT0_DiagE2Mapping_PD.h"


































































































































































































/*Not used in NL_5  fog ID*/



/**/






























/*Not used in NL_5 WIPER ID*/








/**/











































































































#line 508 "C:\\baseline\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_GEELY2DOT0_DiagE2Mapping_PD.h"

extern const byte cab_SI_Transmission_Offsett[8];


extern const byte __far cb_EEPROMDataDefaultMinMax_PD_g[(93+4+10)][3];




typedef struct {
  byte ProductionData_g[12];          /* 256-267 */
  byte EEKodierbyte2_g;               /* 268 */
  byte EEKodierbyte1_g;               /* 269  */
  byte EEKodierbyte0_g;               /* 270  */
  byte ALS1_4_Setting_g;              /* 271 */
  byte ALS5_6_INREC_Setting_g;        /* 272 */
  byte ASIC_DIAGV_g;                  /* 273 */
  unsigned int A_Factor_ALS1_g;               /* 274,275 */
  unsigned int A_Factor_ALS2_g;               /* 276,277 */
  unsigned int A_Factor_ALS3_g;               /* 278,279 */
  unsigned int A_Factor_ALS4_g;               /* 280,281 */
  unsigned int A_Factor_ALS5_g;               /* 282,283 */
  unsigned int A_Factor_ALS6_g;               /* 284,285 */
  unsigned int A_Factor_INREC_g;              /* 286,287 */
  byte B_Factor_Iref_Lo_Gain_Lo_g;    /* 288 */
  byte B_Factor_Iref_Lo_Gain_Hi_g;    /* 289 */
  byte B_Factor_Iref_Hi_Gain_Lo_g;    /* 290 */
  byte B_Factor_Iref_Hi_Gain_Hi_g;    /* 291 */
  unsigned int CRC_Checksum_calibration_g;    /* 292,293 */       
  byte Standby_rain_measurement_1_g;  /*294*/
  byte Standby_rain_measurement_2_g;  /*295*/
  byte Standby_rain_measurement_3_g;  /*296*/
  byte Standby_rain_measurement_4_g;  /*297*/
  byte Standby_rain_measurement_5_g;  /*298*/
  byte Standby_rain_measurement_6_g;  /*299*/
  byte ASIC_Sched_Config_g ;          /*300*/ 
  byte ASIC_LCTR_g ;                  /*301*/ 
  byte NO_RAIN_PRESENT_THRSH_HB_g ;   /*302*/ 
  byte NO_RAIN_PRESENT_THRSH_LB_g ;   /*303*/ 
  byte STBY_REGV_Imbalance_g ;        /*304*/ 
  byte RSControlFlags;                /*305*/
  byte EEPROM_Erase_Counter;          /*306  */ 
  byte HardwareStand[2];              /* 307, 308*/          
  byte Produktionsdaten[4];           /* 309, 310, 311, 312 */
  byte Fertigungsdatum[3];            /* 313, 314, 315*/ 
  byte Audi_HW_Partnumber[8];          /*316,317,318,319,320,321,322,323*/ 
  byte NAD;                           /*324*/
  byte IDFSs_01;                      /*325*/
  byte IDRLSs_01;                     /*326*/
  byte IDBCM1_LIN1_01;                /*327*/
  byte IDWWSs_01;                     /*328*/
  byte IDSOSES_01 ;                   /*329*/ 

  byte ASIC_Frame_01_g;               /*330*/ 
  byte ASIC_Frame_02_g;               /*331*/ 
  byte ASIC_Frame_03_g;               /*332*/ 
  byte ASIC_Frame_04_g;               /*333*/ 

  byte ASIC_RCTR_REG_g ;              /*334*/ 
  byte ASIC_RFCTR_REG_g ;             /*335*/ 
  byte Error_Active_1_g ;             /*336*/   
  byte Error_Active_2_g ;             /*337*/   
  byte Error_Active_3_g ;             /*338*/    
  byte Erase_counter[4] ;             /*339*/  
  byte VariantID_g;                   /*343*/ 
  unsigned int FunctionID_g;                 /*344,345*/ 
  byte IDERRDATA_01 ;                /*346*/ 
  byte IDSPARE_01 ;                  /*347*/ 
  byte IDRLSs_02;                    /*348*/
  byte IDBCM1_LIN1_02;          /*349*/

  byte HUD_Factor_g;            /*350*/

  byte IDRLSs_03;                    /*351*/
  byte IDRLSs_04;                    /*352*/
  byte IDRLSs_05;                    /*353*/
  byte IDRLSs_06;                    /*354*/
  byte IDBCM1_LIN1_03;          /*355*/
  byte IDBCM1_LIN1_04;          /*356*/
  byte IDBCM1_LIN1_05;          /*357*/ 
  unsigned int HUD_MAX_Value;          /*358,359*/
  byte HUD_MAX_Resolution;      /*360*/
  
  
} s_rb_EEPROMStruct_PD_g; 



typedef union {
  unsigned char _c[(93+4+10)];
  s_rb_EEPROMStruct_PD_g EEPROMStructPD;
} s_rb_EEPROMStructPD_buff_g;



/* PRQA S 3116,0759 4*//*<< 3116:#pragma needed for IAR compiler and MISRA, 0759:union needed to reduce RAM usage >>*/

extern  s_rb_EEPROMStructPD_buff_g EEPROM_Struct_PD;

#line 661 "C:\\baseline\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_GEELY2DOT0_DiagE2Mapping_PD.h"


#line 669 "C:\\baseline\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_GEELY2DOT0_DiagE2Mapping_PD.h"

/* PRQA S 3453 1*/ /*<< Function type is required by MISRA, but unions are already used! >>*/

#line 678 "C:\\baseline\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_GEELY2DOT0_DiagE2Mapping_PD.h"


#line 686 "C:\\baseline\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_GEELY2DOT0_DiagE2Mapping_PD.h"
/*VDR_276*/






/* Byte 0*/
#line 700 "C:\\baseline\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_GEELY2DOT0_DiagE2Mapping_PD.h"
/* Byte 1*/


















/* Byte 2*/



#line 732 "C:\\baseline\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_GEELY2DOT0_DiagE2Mapping_PD.h"



#line 743 "C:\\baseline\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_GEELY2DOT0_DiagE2Mapping_PD.h"








#line 85 "C:\\baseline\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_DiagE2_projectconfig.h"




/* Include AD second place */
#line 1 "C:\\baseline\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_DiagE2Mapping_AD.h"


/* PRQA S 3619 EOF */ /* << 2010 01 08, compiler allows whitespaces:due to readable code, keep whitespaces! >> */
/* PRQA S 2217 EOF */ /* << 2011 03 03, Code would be not readable >> */
/* PRQA S 750,759 EOF *//*<< 0750:union needed to reduce RAM usage >>*/
/* PRQA S 1015 EOF *//*<< 1015:__far needed for IAR compiler  >>*/
/* PRQA S 3453 EOF *//*<< Macro is more readle and convinient in this situation >>*/
/* PRQA S 857 EOF *//*<< Macro exceeds 1024 number  >>*/
/****************************************************************************************************************/
/* History                                                                                                      */
/****************************************************************************************************************/
/* Date         VDR_Number     Description                                                                      */
/*18.11.14      VCO_189                 DEBUG:Change the I2C debug data mapping                                 */
/*27.11.14      VDR_825         MP      Diagnostic pulse - change the wait time                                 */
/*09.12.14      VCO_204         NB      Project specific extensions in the main stream                          */
/*01.04.15      VCO_239         MP      Light values filter defined in EEPROM                                   */
/*14.04.15      VCO_243         NB      Implement Function ID and Variant ID in the EEPROM PD section           */
/*09.07.15      VCO_259         NB      change the minimal value of rb_TunnelDebounceFactor_g to 0              */
/*13.07.15      VCO_260         MP      Tunnel wipe activation and delay according to                           */
/****************************************Tunnel Verzoegerung and Aktivierung parameters                         */
/*07.10.15      VCO_277         SP      Modify the SHT Error Debonunce Jitter as an EEPROM parameter            */
/*07.10.15      VCO_278         NB      Solar shadow correction                                                 */
/*08.10.15      VCO_278         NB      Solar shadow correction                                                 */
/*11.11.15      VCO_285         NB      Adapt the default parameter for the combined solar sender optimis       */
/*13.11.15      VDR_924         SP      Licht An bei Regen - Anpass parameters are not correctly used           */
/*13.11.15      VCO_286         SP      Modify the Default EEPROM Parameter of SHT module communication Retry Counter */
/*02.12.15      VDR_939         NB      Improvement of SHT module measurement */
/*14.01.16      VCO_304         NB      Default values for solar correction factor changed for tesla         */
/*26.02.16      VCO_308         NB      EEPROM AD extension for twilight                                     */
/*12.05.16      VCO_326         NB      All:Update of default Software part number and other configuration   */
/*16.08.16      VCO_339         NB      Change the default value of EEPROM parameter                         */
/****************************************************************************************************************/

#line 1 "C:\\baseline\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_projectDefs.h"
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
 *  This file is designed to contain all RLS projects in order to define compiler
 * switches for the RELEASE configuration. The purpose is to have the project -
 * feature relation stored in one header file and thus available for all compilers
 * and third party tools.
 *
 * %PCMS_HEADER_SUBSTITUTION_START:%
 * <table border="0" cellspacing="0" cellpadding="0">
 * <tr> <td> Source:   </td> <td> %PM: template.h %                  </td></tr>
 * <tr> <td> Revision: </td> <td> %PR: 1.8 %                  </td></tr>
 * <tr> <td> Status:   </td> <td> %PS: UNDER_REVIEW %                  </td></tr>
 * <tr> <td> Author:   </td> <td> R.Fichtner, DUS-E-RLS  </td></tr>
 * <tr> <td> Date:     </td> <td> %PUDT: 20-FEB-2013 15:20:57 %                </td></tr>
 * </table>
 * %PCMS_HEADER_SUBSTITUTION_END:%
 * \n
 * <table border="0" cellspacing="0" cellpadding="0">
 * <tr> <td> COMPONENT: </td> <td> XXXX                            </td></tr>
 * <tr> <td> SCOPE:     </td> <td> <Public/Private/Component>      </td></tr>
 * <tr> <td> TARGET:    </td> <td> <All/Freescale S12X/S12XE/...>  </td></tr>
 * </table>
 */
/*----------------------------------------------------------------------------*/
/* Date      VDR_Number   Author   Description                                */
/*----------------------------------------------------------------------------*/
/*09.19.17   VCO_451    NB    All:Add spare LIN IDs in the EEPROM             */
/*07.12.17   VCO_462    HB    FIAT 330: parallel branch                       */
/******************************************************************************/


#line 285 "C:\\baseline\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_projectDefs.h"

#line 35 "C:\\baseline\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_DiagE2Mapping_AD.h"
#line 1 "C:\\BASELINE\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SWDEV\\01_SRCCODE\\APPLICATION\\X1_HUMIDITY\\G5_HumTemp.h"
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

/** \brief Defines error code for rb_HumTemp_ErrorCode_g 'checksum error' */

/** \brief Defines error code for rb_HumTemp_ErrorCode_g 'Error during write command' */

/** \brief Defines error code for rb_HumTemp_ErrorCode_g 'No respnse error' */

/** \brief Defines error code for rb_HumTemp_ErrorCode_g 'out of range' */

/** \brief Defines error code for rb_HumTemp_ErrorCode_g 'out of range' */

/******************************************************************************/
/*  Comment:  Init and Error value for Temperature, Humidity and Dewpoint     */
/** \brief Define for 'Init' applicable for Temperature, Humidity and Dewpoint*/

/** \brief Define for 'Error' applicable for Temperature, and Dewpoint*/

/** \brief Define for 'Error' applicable for  Humidity*/

/******************************************************************************/
/*  Comment:  Status of Heating element                                       */
/*  Range  :  0-1                                                             */
/** \brief Define for Heater off*/

/** \brief Define for Heater on*/





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
extern   Flag uF_Humi_g;              // variable for flag for timer




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

extern unsigned char SHT21xSerialNumber[8];
#line 178 "C:\\BASELINE\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SWDEV\\01_SRCCODE\\APPLICATION\\X1_HUMIDITY\\G5_HumTemp.h"
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
extern unsigned int rw_InErrorModeCounter_s;


/******************************************************************************/
/*                  Declaration of exported constant data                     */
/******************************************************************************/
/*RLS_VCO88 defines for Default Parameters in EEPROM for dynamic compensation*/





/* Defines for Selfheating compensation*/

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


#line 36 "C:\\baseline\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_DiagE2Mapping_AD.h"













#line 73 "C:\\baseline\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_DiagE2Mapping_AD.h"














































#line 146 "C:\\baseline\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_DiagE2Mapping_AD.h"





























































/*RS empfindlichkeit scaling faktor for Parametersatz 0*/

/*RS empfindlichkeit scaling faktor for Parametersatz 1*/
















/*rain nightbit threshold*/
















































#line 284 "C:\\baseline\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_DiagE2Mapping_AD.h"
/*Autobahn_on_off*/ /*VCO_31 definition of default values new EEPROM definition*/




/*Autobahn Delay on*/




/* Frontwaschen +Autobahndelay*/




/*regenlicht_low_high*/




/*regenlicht */












#line 347 "C:\\baseline\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_DiagE2Mapping_AD.h"





/*(about 810 lux---Value corrected for 80% transmission through glass)---(Previous Value about 1250 lux)----KI*/
// this is the old way with 4 bit resolution for thresholds
//#define CB_DEF_REGULATION48THRESHOLD 0x65
//#define CB_MIN_REGULATION48THRESHOLD 0
//#define CB_MAX_REGULATION48THRESHOLD 255

// this is the new way with 8 bit resolution for thresholds








/*VCO_094 Thresehold Set for VeryBrightTunnelDetection*/









/*default value for tunnel threshold scaling*/




/*default value for tunnel threshold scaling*/
































/*VCO_260 Tunnel wipe activation and delay according to Tunnel Verzoegerung and Aktivierung parameters*/

















#line 440 "C:\\baseline\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_DiagE2Mapping_AD.h"


#line 449 "C:\\baseline\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_DiagE2Mapping_AD.h"





#line 817 "C:\\baseline\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_DiagE2Mapping_AD.h"



































/*high nibble: right edge leading from low to high speed
low nibble: left edge leading from high to low speed
*/








































































#line 1082 "C:\\baseline\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_DiagE2Mapping_AD.h"

#line 1089 "C:\\baseline\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_DiagE2Mapping_AD.h"












#line 1360 "C:\\baseline\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_DiagE2Mapping_AD.h"

extern const byte __far cb_EEPROMDataDefaultMinMax_AD_g[194][3];



typedef struct {
 
  byte Stufe1_OG;                     
  byte Stufe1_UG;                     
  byte Ep_St2_Epr_In_St2;             
  byte Schwelle_Schwall;             
  byte CW_AnsamlungAdditOffset;      
  byte dec_Int_Sp_off;                
  byte Dec_Stx_Speicher;             
  byte dec_Ovr_Speicher;               
  byte Empf_Faktor_ST2_Offs;          
  byte Max_Signallaenge;              
  byte rb_Stufe1_with_Int_og;         
  byte Nachwisch_4_ST1_min;           
  byte Nachwisch_3;                   
  byte Nachwisch_2;                   
  byte RSEmpfFactorScaling;           
  byte SchlierenFlag1;                
  byte sig_ans_schw_offs;            
  
}s_rb_PrametersStruct_g;



typedef struct {
 s_rb_PrametersStruct_g PrametersStruct[4]; /* 512 to 579 */
  byte RS_GainSetupArray[6];          /*580,581,582,583,584,585*/    
  byte HALIOS_Clock_Control_Reg_g;    /*586*/
  byte ACTR_Reg_g;                    /*587*/
  byte PCO_PI_Regulator_g;            /*588*/
  byte ICO1H_g;                       /*589*/  
  byte ICO1L_g;                       /*590*/  
  byte ICO2H_g;                       /*591*/  
  byte ICO2L_g;                       /*592*/  
  byte FOSC_LEDUL_g;                  /*593*/ 
  byte INTCO_g;                       /*594*/  
  byte StandbyTimout;                 /*595*/ 
  byte dec_st2_speicher;              /*596*/ 
  byte RS_Sensitivity[9];             /*597,598,599,600,601,602,603,604,605*/            
  byte MaxOverwipeSensitivity;        /*606*/  
  byte StandbyModeScanTime_g;         /*607*/ 
  byte RainNightBitThrs_g;            /*608*/
  byte Amb_Base_Day_Threshold;        /*609*/
  byte Amb_Base_Night_Threshold;      /*610*/   
  byte TunnelDebounceFactor;          /*611*/                           
  byte Customer_FW_SWA_Scaling;       /*612*/
  byte Customer_IR_SWA_Scaling;       /*613*/
  byte FW_Base_Day_Threshold;         /*614*/
  byte IR_Base_Day_Threshold;         /*615*/
  byte FW_Base_Night_Threshold;       /*616*/
  byte IR_Base_Night_Threshold;       /*617*/    
  byte Day_Delay;                     /*618*/
  byte Night_Delay;                   /*619*/
  byte AfterTunnelDelayOffs;          /*620*/ 
  byte p_v_autobahn_on_off_g;         /*621*/
  byte p_t_autobahn_delay_on_g;       /*622*/
  byte Frontwaschen_Autobahndelay_g;    /*623*/  
  byte p_n_regenlichtschwelle_low_high_g;/*624*/ 
  byte p_n_regenlichtschwelle_Zeit_g;   /*625*/ 
  byte TunnelThresholdScaling_g;      /*626*/ 
  byte Amb_TunnelThresholdScaling_g;  /*627*/ 
  byte spare;                         /*628*/ /* old: Regulation48Threshold_g */
  byte Regulation48LightOnTime_g;     /*629*/ 
  byte VeryBrightInTunnelDelay_g;     /*630*/ 
  byte Combined_FW_AL_THRs_g;         /*631*/ 
  byte DYN_COMP_CCD_MINUS_1_g;        /*632*/  
  byte DYN_COMP_CCD_MINUS_2_g;        /*633*/
  byte maxTemperatureOffsett_g;       /*634*/ 
  byte ASIC_AFSTHR_REG_g;              /*635*/ 
  byte Diag_Request_Factor_g;          /*636*/ 
  byte cb_inc_speicher_g;              /*637*/ 
  byte I2C_Debug_Config_g;             /*638*/ 
  byte Audi_SW_Partnumber[8];          /*639,640,641,642,643,644,645,646*/ 
  byte wiperSpeedHysteresis;           /*647*/   
  byte Proj_Specific_config;           /*648*/   
  byte ALSx_Filter_g;                  /*649*/   
  byte IrLightTunnelThreshodRng;       /*650*/   
  byte FwLightTunnelThresholdRng;      /*651*/   
  byte AmbLightTunnelThresholdRng;     /*652*/
  /*VCO_260 Tunnel wipe activation and delay according to Tunnel Verzoegerung and Aktivierung parameters*/
  byte TunWischVerzAktiv;              /*653*/   
  byte SHTErrorDebounceJitter;         /*654*/   
  byte SolarShadowCorrFactor1;         /*655*/   
  byte SolarShadowCorrFactor2;         /*656*/   
  byte E2_MaxSt2SignalLaenge;          /*657*/   
      
  byte SoftwareStand[4];              /* 658,659,660,661 */
  
  byte twilightToDarkTime;              /*662*/
  byte darkToTwilightTime;              /*663*/
  
  byte darkToTwilightThreshFW;          /*664*/
  byte darkToTwilightThreshAMB;         /*665*/
  
  byte twilightToDarkThreshFW;          /*666*/
  byte twilightToDarkThreshAMB;         /*667*/
  byte iceDetectionTemperature;         /*668*/
  byte Regulation48ThresholdAmb_g;      /*669*/  
  byte Regulation48ThresholdFw_g;       /*670*/ 
#line 1479 "C:\\baseline\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_DiagE2Mapping_AD.h"
  byte Threshold_TempIceRisk;           /*671*/ 
  byte upperTolerance_StartupWipe;      /*672*/   
  byte unused[33];


} s_rb_EEPROMStruct_AD_g;



typedef union {
  unsigned char _c[194];
  s_rb_EEPROMStruct_AD_g EEPROMStructAD;
} s_rb_EEPROMStructAD_buff_g;




/* PRQA S 3116,0759 4*//*<< 3116:#pragma needed for IAR compiler and MISRA, 0759:union needed to reduce RAM usage >>*/

extern  s_rb_EEPROMStructAD_buff_g EEPROM_Struct_AD;


/* PRQA S 3453 1*/ /*<< Function type is required by MISRA, but unions are already used! >>*/
#line 1555 "C:\\baseline\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_DiagE2Mapping_AD.h"
/*(about 810 lux---Value corrected for 80% transmission through glass)---(Previous Value about 1250 lux)----KI*/
#line 1567 "C:\\baseline\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_DiagE2Mapping_AD.h"



#line 1576 "C:\\baseline\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_DiagE2Mapping_AD.h"


//for 0x84 it is 0x4 *2 = 8

//for 0x84 it is 8 + 2 *8 = 24

 
// for 0xC4 is 4 *3 = 12

// for 0xC4 is 12 +12*5= 72


//for 0x0C it is 24







  


  





#line 1617 "C:\\baseline\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_DiagE2Mapping_AD.h"

#line 1627 "C:\\baseline\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_DiagE2Mapping_AD.h"









/*VCO_31 new EEPROM definition*/





















#line 1766 "C:\\baseline\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_DiagE2Mapping_AD.h"




/*VCO_31 values to write into EEPROM per service 0x2E*/     












#line 1789 "C:\\baseline\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_DiagE2Mapping_AD.h"





























#line 1824 "C:\\baseline\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_DiagE2Mapping_AD.h"













/* betrachtung fur Wischanlage Parkposition unten*/
#line 1844 "C:\\baseline\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_DiagE2Mapping_AD.h"




















/* PRQA S 3453 5*/ /*<< Function type is required by MISRA, but unions are already used! >>*/
/*VDR_131 Following 4 lines correct MISRA Rule 96*/





















#line 91 "C:\\baseline\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_DiagE2_projectconfig.h"

/* Include RD Third place */
#line 1 "C:\\baseline\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_DiagE2Mapping_RD.h"


/* PRQA S 3619 EOF */ /* << 2010 01 08, compiler allows whitespaces:due to readable code, keep whitespaces! >> */
/* PRQA S 2217 EOF */ /* << 2011 03 03, Code would be not readable >> */
/* PRQA S 750,759 EOF *//*<< 0750:union needed to reduce RAM usage >>*/
/* PRQA S 1015 EOF *//*<< 1015:__far needed for IAR compiler  >>*/
/* PRQA S 3453 EOF *//*<< Macro is more readle and convinient in this situation >>*/
/* PRQA S 857 EOF *//*<< Macro exceeds 1024 number  >>*/


/******************************************************************************/
/* History                                                                    */
/*----------------------------------------------------------------------------*/
/* Date      VDR_Number     Description                                       */
/*13.05.2015 VCO_192    NB    Audi: Activation and deactivation of Interval Operation  */
/*09.11.15   VCO_282    NB    All:Add spare LIN IDs in the EEPROM                      */


/******************************************************************************/



































/*Incidence Counter*/ /*VCO_31 definition of default values new EEPROM definition*/



/*Incidence Counter*/



/*Incidence Counter*/



/*Incidence Counter*/



/*Incidence Counter*/



/*Incidence Counter*/



/*Incidence Counter*/













































#line 164 "C:\\baseline\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_DiagE2Mapping_RD.h"



extern const byte __far cb_EEPROMDataDefaultMinMax_RD_g[31][3];




typedef struct {
  
   
  byte STBY_REGV_HB_g ;                       /*768*/ 
  byte STBY_REGV_LB_g ;                       /*769*/ 
  byte STBY_DELTA_INTV_HB_g ;                 /*770*/ 
  byte STBY_DELTA_INTV_LB_g ;                 /*771*/ 
  byte IntervalIsWasActive_g ;                /*772*/
  byte WatchdogResetCounter;                  /*773*/ 
  byte E2_Sensor_Error1_g;                    /*774*/ 
  byte E2_Sensor_Error2_g;                    /*775*/ 
  byte E2_Sensor_Error3_g;                    /*776*/ 
  byte E2_Sensor_Error4_g;                    /*777*/  
  byte E2_Sensor_Error5_g;                    /*778*/
  byte E2_Sensor_Error6_g;                    /*779*/  
  byte IncidentCounter1_g;                    /*780*/  
  byte IncidentCounter2_g;                    /*781*/  
  byte IncidentCounter3_g;                    /*782*/  
  byte IncidentCounter4_g;                    /*783*/  
  byte IncidentCounter5_g;                    /*784*/  
  byte IncidentCounter6_g;                    /*785*/  
  byte IncidentCounter7_g;                    /*786*/
  byte RS_LS_Error_Active1_g;                 /*787*/
  byte RS_LS_Error_Active2_g;                 /*788*/
  byte LightLS_Error_Active1_g;               /*789*/
  byte RainRS_Error_Active1_g;                /*790*/
  byte GainOffsetE2_g;                        /*791*/
  byte Release_IntervalMarker_g;              /*792*/
  byte SensConfigData_g[3];                  /*793,794,795*/
  byte Resf_g;                                /*796*/
  byte NOM_DELTA_INTV_g ;                 /*797*/ 
  byte THR_DELTA_INTV_g ;                 /*798*/ 
} s_rb_EEPROMStruct_RD_g;



typedef union {
  unsigned char _c[31];
  s_rb_EEPROMStruct_RD_g EEPROMStructRD;
} s_rb_EEPROMStructRD_buff_g;



/* PRQA S 3116,0759 4*//*<< 3116:#pragma needed for IAR compiler and MISRA, 0759:union needed to reduce RAM usage >>*/

extern  s_rb_EEPROMStructRD_buff_g EEPROM_Struct_RD;



#line 247 "C:\\baseline\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_DiagE2Mapping_RD.h"







#line 289 "C:\\baseline\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_DiagE2Mapping_RD.h"




/* special access adresses*/
#line 302 "C:\\baseline\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_DiagE2Mapping_RD.h"

#line 94 "C:\\baseline\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_DiagE2_projectconfig.h"



#line 89 "C:\\baseline\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_E2ProjectConfig.h"


#line 94 "C:\\baseline\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_RLS_LIN_GEELY2DOT0.c"

#line 1 "C:\\BASELINE\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SWDEV\\01_SRCCODE\\APPLICATION\\OS\\G5_Appli_main.h"


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








/* bytes to check different Watchdog conditions */
extern  byte rb_WDG_500usTaskCounter_g ;
extern byte rb_WDG_IORefreshTaskCounter_g ;
extern byte rb_WDG_BusTaskCounter_g;
extern byte rb_WDG_RainsensorTaskCounter_g;
extern byte rb_WDG_SCITaskCounter_g; /*VCO_92 implement add. counter*/
extern byte rb_WDG_LVITaskCounter_g; /*VCO_92 implement add. counter*/
extern byte rb_WDG_LightsensorTaskCounter_g;
extern byte rb_SevenToZeroCounter_g;

extern __no_init byte rb_ResetSource_g;
extern __no_init byte rab_InternalResetIndicator[4]; /* VDR_871 */
/*Time in 10ms to check Watchdog counters(max: 20 definition to be checked with watchdog reset time internal/external)*/


/* min boarder of Window for 1ms Task counter */

/* max boarder of Window for 1ms Task counter */





extern  byte rb_WDGFastTaskCounterMin_g;
extern  byte rb_WDGFastTaskCounterMax_g;

/****************************************************************************/
/*              Global Contants and Makros                                  */
/****************************************************************************/
/* PRQA S 3412 8 *//*<< required for readability  >>*/









/*************************************************************************
Declaration of exported functions
**************************************************************************/
/* PRQA S 0841 7 */ /* <<for easier declaration of variable -> proven mechanism>> */




#line 96 "C:\\baseline\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_RLS_LIN_GEELY2DOT0.c"
#line 1 "C:\\baseline\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_lininclude.h"
/******************************************************************************/
/*                                                                            */
/*   Valeo Schalter und Sensoren GmbH                                         */
/*   Stuttgarter Str. 119                                                     */
/*   74321 Bietigheim-Bissingen                                               */
/*                                                                            */
/*   All rights reserved. Distribution or duplication without previous        */
/*   written agreement of the owner prohibited.                               */
/*                                                                            */
/******************************************************************************/
/*   Source: D:/ldws/software/ecu/linconf.h  */
/*   Revision:   1.7   */
/*   Author:   SBA272   */
/*   Date:   Sep 08 2003 10:58:24   */
/******************************************************************************/
/*   MODULE:                                                                  */
/*   FILE:                                                                    */
/******************************************************************************/
/*----------------------------------------------------------------------------*/
/* Date      VDR_Number   Author   Description                                       */
/*----------------------------------------------------------------------------*/
/* 25.11.2014   VCO_200    NB     Include G5_lininclude.h instead rls.h and linconf.h  */
/* 28.08.2015   VCO_268    SP     Cleanup the LIN modules  */
/* 09.11.15     VCO_282    NB    All:Add spare LIN IDs in the EEPROM                   */
/* 07.12.17     VCO_462    HB    FIAT 330 interfaces: parallel branch                  */
/******************************************************************************/



#line 1 "C:\\baseline\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_projectDefs.h"
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
 *  This file is designed to contain all RLS projects in order to define compiler
 * switches for the RELEASE configuration. The purpose is to have the project -
 * feature relation stored in one header file and thus available for all compilers
 * and third party tools.
 *
 * %PCMS_HEADER_SUBSTITUTION_START:%
 * <table border="0" cellspacing="0" cellpadding="0">
 * <tr> <td> Source:   </td> <td> %PM: template.h %                  </td></tr>
 * <tr> <td> Revision: </td> <td> %PR: 1.8 %                  </td></tr>
 * <tr> <td> Status:   </td> <td> %PS: UNDER_REVIEW %                  </td></tr>
 * <tr> <td> Author:   </td> <td> R.Fichtner, DUS-E-RLS  </td></tr>
 * <tr> <td> Date:     </td> <td> %PUDT: 20-FEB-2013 15:20:57 %                </td></tr>
 * </table>
 * %PCMS_HEADER_SUBSTITUTION_END:%
 * \n
 * <table border="0" cellspacing="0" cellpadding="0">
 * <tr> <td> COMPONENT: </td> <td> XXXX                            </td></tr>
 * <tr> <td> SCOPE:     </td> <td> <Public/Private/Component>      </td></tr>
 * <tr> <td> TARGET:    </td> <td> <All/Freescale S12X/S12XE/...>  </td></tr>
 * </table>
 */
/*----------------------------------------------------------------------------*/
/* Date      VDR_Number   Author   Description                                */
/*----------------------------------------------------------------------------*/
/*09.19.17   VCO_451    NB    All:Add spare LIN IDs in the EEPROM             */
/*07.12.17   VCO_462    HB    FIAT 330: parallel branch                       */
/******************************************************************************/


#line 285 "C:\\baseline\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_projectDefs.h"

#line 31 "C:\\baseline\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_lininclude.h"


#line 1 "C:\\baseline\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_linconf_GEELY2DOT0.h"
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
 * Template of header file for LIN configuration
 * used with RLT-DIagnose.exe
 *
 * 
 * <table border="0" cellspacing="0" cellpadding="0">
 * <tr> <td> Source:   </td> <td> template_linconf.h                  </td></tr>
 * <tr> <td> Revision: </td> <td> 1.0                  </td></tr>
 * <tr> <td> Status:   </td> <td> STORED                  </td></tr>
 * <tr> <td> Author:   </td> <td> Jochen Schenk, VDS-E-PUS  </td></tr>
 * <tr> <td> Date:     </td> <td> 07-APR-2014 07:47:15                 </td></tr>
 * </table>
 * 
 * \n
 * <table border="0" cellspacing="0" cellpadding="0">
 * <tr> <td> COMPONENT: </td> <td> RLS_LIN     </td></tr>
 * <tr> <td> SCOPE:     </td> <td> Public      </td></tr>
 * <tr> <td> TARGET:    </td> <td> NEC         </td></tr>
 * </table>
 */




/******************************************************************************/
/*                         Defines for LIN Configuration                      */
/******************************************************************************/



















/* 8X ------------- Move this part to diagnose_xxx.h -------------------------*/

/******************************************************************************/
/*                         Defines for node configuration                     */
/******************************************************************************/







/* 8X ------------------------------------------------------------------------*/


#line 87 "C:\\baseline\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_lininclude.h"




#line 1 "C:\\BASELINE\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SWDEV\\01_SRCCODE\\APPLICATION\\LIN\\G5_LINsci_sr.h"
/******************************************************************************/
/*                                                                            */
/*   Valeo Schalter und Sensoren GmbH                                         */
/*   Stuttgarter Str. 119                                                     */
/*   74321 Bietigheim-Bissingen                                               */
/*                                                                            */
/*   All rights reserved. Distribution or duplication without previous        */
/*   written agreement of the owner prohibited.                               */
/*                                                                            */
/******************************************************************************/
/******************************************************************************/
/*   MODULE:                                                                  */
/*   FILE:                                                                    */
/******************************************************************************/
/*                                                                            */
/******************************************************************************/
/* History                                                                    */
/*----------------------------------------------------------------------------*/
/* Date      VDR_Number     Description                                       */
/*----------------------------------------------------------------------------*/
/* 19.08.2014   VDR_799    NB     LIN_ResponeError on LIN_NOResponse */
/* 28.08.2015   VCO_268    SP     Cleanup the LIN modules  */
/* 03.09.2015   VDR_904    NB     Response error is set when invalid LIN header is received  */
/* 09.11.15     VCO_282    NB    All:Add spare LIN IDs in the EEPROM             */
/******************************************************************************/











/******************************************************************************/
extern void sci_init(byte rb_WakeUpFrame_l) ;
extern void sci_Communication(void);
extern byte sci_GetLINMsgID(void); /*VDR_507 */
extern __callt byte sci_CheckParity(byte rb_Data);

extern void ApplLinProtocolError(byte error);
extern __callt void ApplLinSlavePreCopy(byte rb_MessageID_l);
extern __callt byte ApplLinSlaveCmdFrmFct(void);
extern void ApplLinMasterReqFrmFct(void);
extern void ApplLinBusSleep(void);



/******************************************************************************/
/*        Hardware register and IO ports                                      */
/******************************************************************************/






/******************************************************************************/


/* 8-Bit qualifier */
typedef signed char    cansint8;
typedef unsigned char  canuint8;

/* 16-Bit qualifier */
typedef signed short   cansint16;
typedef unsigned short canuint16;

/* 32-Bit qualifier */
typedef signed long    cansint32;
typedef unsigned long  canuint32;


typedef unsigned char *TxDataPtr;              /* ptr to transmission data buffer */
typedef unsigned char *RxDataPtr;              /* ptr to receiving data buffer    */

typedef unsigned char    canbittype;

struct _c_bits8
{
  canbittype  b0:1;  /* LSB-Bits (lower adr!) */
  canbittype  b1:1;
  canbittype  b2:1;
  canbittype  b3:1;
  canbittype  b4:1;
  canbittype  b5:1;
  canbittype  b6:1;
  canbittype  b7:1;  /* MSB-Bits (higher address) unused */
};

struct _c_bits16
{
  canbittype  b0:1;  /* lower adr */
  canbittype  b1:1;
  canbittype  b2:1;
  canbittype  b3:1;
  canbittype  b4:1;
  canbittype  b5:1;
  canbittype  b6:1;
  canbittype  b7:1;
  canbittype  b8:1; /* higher adr */
  canbittype  b9:1;
  canbittype  b10:1;
  canbittype  b11:1;
  canbittype  b12:1;
  canbittype  b13:1;
  canbittype  b14:1;
  canbittype  b15:1;
};

#line 121 "C:\\BASELINE\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SWDEV\\01_SRCCODE\\APPLICATION\\LIN\\G5_LINsci_sr.h"

union tLinIndicationBits {
  canuint8 _c[1];
  struct _c_bits8 w[1];
};



extern  union tLinIndicationBits uLinIndicationFlags;



union tLinConfirmationBits {
  canuint8 _c[(11 + 7)/8];
  struct _c_bits16 w[(11 + 15)/16];
};

#line 146 "C:\\BASELINE\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SWDEV\\01_SRCCODE\\APPLICATION\\LIN\\G5_LINsci_sr.h"

extern  union tLinConfirmationBits uLinConfirmationFlags;
extern const canuint8 cabLinIndicationOffset[7];
extern const canuint8 cabLinIndicationMask[7];

extern canuint8 const cabLinConfirmationOffset[11];
extern canuint8 const cabLinConfirmationMask[11];



extern byte rb_WBPosition_mg;
extern byte rb_MessageLength_mg;
extern byte rb_WakeupCounter_mg;
extern byte rb_ResponseTime_g; /* VDR_799 */

extern  volatile Flag uF_sciState_mg;





#line 177 "C:\\BASELINE\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SWDEV\\01_SRCCODE\\APPLICATION\\LIN\\G5_LINsci_sr.h"


#line 192 "C:\\BASELINE\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SWDEV\\01_SRCCODE\\APPLICATION\\LIN\\G5_LINsci_sr.h"

// counter steps for TFrameMaxTimeoutTimer (without break and -4 (Timer starts at 0xFFFC))


/* PRQA S 3412 2 *//*<< code is OK  >>*/











/******************************************************************************/

/******************************************************************************/
/*        Hardware register and IO ports                                      */
/******************************************************************************/




/******************************************************************************/


/******************************************************************************/


/******************************************************************************/
/* END Source: G5_LINsci_sr.h  */
/******************************************************************************/
#line 92 "C:\\baseline\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_lininclude.h"
#line 1 "C:\\baseline\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_rls_linst.h"


/**************VALEO WIPER SYSTEMS**SMART*SENSORS************************
*                                                                       *
*  HEADER FILE NAME : rls_lin.h                      *
*                                                                       *
*  LIBRARY ID       :                                                   *
*                                                                       *
*  DESCRIPTION      : interface LIN                                     *
*                  *
*                  *
*                                                                       *
*  SPECIAL LOGIC    :                                                   *
*                                                                       *
*************************************************************************
*                                                                       *
*                         MODIFICATION LOG                              *
*                                                                       *
* Date      VDR  Auth     Description                                 *
* -DD.MM.YY- ---  -- ------------------------------------------  -------- **/
/* 02.Jul.10 VDR_540 FS Butterfly Option implemented*/
/* 14.Jun.10 VCO_49  FS Simulated Park Position*/
/* 29.Apr.10 VDR_473 FS Branch old Version 1.13 with 1.15*/
/* 24.02.10  VCO_031 AL external Variable needed            AL      */
/* 01.10.09  VDR_373 FS Single Or Double Overwiped*/
/* 28.09.09  VDR_368 FS Ford related Bits implemented: CarCode, LightConfigreceived, OneTimeOrDoubleOverwiped*/
/* 24.10.08  VDR_277 FS Sleep Mode without rw_NoCommunicationCounter_g*/
/* 16.10.08  VDR_276 FS  Implement Overwipe Offset*/
/* 23.11.00  Init   JS Initial Release             */


/****************************************************************************************************************/
/* 25.11.2014   VCO_200    NB   add Fiat releated code inside the compiler switch                               */
/* 13.05.2015   VCO_192    NB   Audi: Activation and deactivation of Interval Operation                         */
/* 09.06.2015   VCO_192    NB   Audi: Activation and deactivation of Interval Operation                         */
/* 13.07.2015   VDR_891    MP   SWITS_635: SPI communication error not set when the ASIC mode is corrupted      */
/********************************only once per cycle                                                            */
/* 28.08.2015   VCO_268    SP     Cleanup the LIN modules                                                       */
/* 21.09.2015   VDR_909    NB     Fixed interval operation not started after lapsing the ignition delay         */ 
/*                                and activating again                                                          */
/*24.03.16    VCO_320   NB      LIN response shall not be sent untill EEPROM is loaded                          */ 
/*12.05.16    VCO_326   NB      All:Update of default Software part number and other configuration   */
/* 07.12.17     VCO_462    HB    FIAT 330 interfaces: parallel branch                                           */
/****************************************************************************************************************/

#line 1 "C:\\baseline\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_projectDefs.h"
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
 *  This file is designed to contain all RLS projects in order to define compiler
 * switches for the RELEASE configuration. The purpose is to have the project -
 * feature relation stored in one header file and thus available for all compilers
 * and third party tools.
 *
 * %PCMS_HEADER_SUBSTITUTION_START:%
 * <table border="0" cellspacing="0" cellpadding="0">
 * <tr> <td> Source:   </td> <td> %PM: template.h %                  </td></tr>
 * <tr> <td> Revision: </td> <td> %PR: 1.8 %                  </td></tr>
 * <tr> <td> Status:   </td> <td> %PS: UNDER_REVIEW %                  </td></tr>
 * <tr> <td> Author:   </td> <td> R.Fichtner, DUS-E-RLS  </td></tr>
 * <tr> <td> Date:     </td> <td> %PUDT: 20-FEB-2013 15:20:57 %                </td></tr>
 * </table>
 * %PCMS_HEADER_SUBSTITUTION_END:%
 * \n
 * <table border="0" cellspacing="0" cellpadding="0">
 * <tr> <td> COMPONENT: </td> <td> XXXX                            </td></tr>
 * <tr> <td> SCOPE:     </td> <td> <Public/Private/Component>      </td></tr>
 * <tr> <td> TARGET:    </td> <td> <All/Freescale S12X/S12XE/...>  </td></tr>
 * </table>
 */
/*----------------------------------------------------------------------------*/
/* Date      VDR_Number   Author   Description                                */
/*----------------------------------------------------------------------------*/
/*09.19.17   VCO_451    NB    All:Add spare LIN IDs in the EEPROM             */
/*07.12.17   VCO_462    HB    FIAT 330: parallel branch                       */
/******************************************************************************/


#line 285 "C:\\baseline\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_projectDefs.h"

#line 47 "C:\\baseline\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_rls_linst.h"






/* PRQA S 0841 1 */ /* <<for easier declaration of variable -> proven mechanism>> */


/*VCO_220 VIrefLo/Hi monitoring*/ /*VDR_878*/
#line 64 "C:\\baseline\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_rls_linst.h"


/* PRQA S 750,0759 1 *//*<< 0759:union needed to reduce RAM usage >>*/
  volatile Flag uF_SCIFlags_mg;


 byte rb_LIN_BIT_ERROR_COUNTER_g;
 byte rb_LIN_OVERTHEADERMAX_COUNTER_g;
 byte rb_LIN_CHECKSUMERROR_COUNTER_g;
 byte rb_LIN_OVERTFRAMEMAX_COUNTER_g;
 byte rb_LIN_NORESPONSE_COUNTER_g;
 byte rb_LIN_FRAMINGERROR_COUNTER_g;


#line 86 "C:\\baseline\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_rls_linst.h"
/* PRQA S 750,0759 1 *//*<< 0759:union needed to reduce RAM usage >>*/
  Flag uF_Communication_mg;




#line 106 "C:\\baseline\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_rls_linst.h"







 volatile Flag uF_Butterfly_Flags_g;
#line 122 "C:\\baseline\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_rls_linst.h"





   byte rb_LastLINErrorCode_g;
   unsigned int rw_NoCommunicationCounter_g;
   byte rb_intervaltime_rainSensorOff_g;
   byte rb_Release_IntervalMarker_Update_g; /*VCO_192*/
//EXTERN byte rb_RLS_Botschaft_g;

 void CopyRLSData(void);
 void LIN_50ms_Task(void);
// EXTERN void LIN_1ms_Task(void);

 void ApplLinInit(byte rb_LIN_State_l);

 void ApplTableInit(void);


//EXTERN canuint8 LinStart (void);

 void Check_StartupActiveErrors(void);

 void GetLsWWS(void);
 void GetLeWWS(void);

/* PRQA S 0841 1 */ /* <<for easier declaration of variable -> proven mechanism>> */
#line 93 "C:\\baseline\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_lininclude.h"


#line 1 "C:\\BASELINE\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SWDEV\\01_SRCCODE\\APPLICATION\\LIN\\G5_rls_GEELY2DOT0.h"
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




/******************************************************************************/
/*                        Definition of message handles                       */
/******************************************************************************/

#line 65 "C:\\BASELINE\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SWDEV\\01_SRCCODE\\APPLICATION\\LIN\\G5_rls_GEELY2DOT0.h"






   


#line 80 "C:\\BASELINE\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SWDEV\\01_SRCCODE\\APPLICATION\\LIN\\G5_rls_GEELY2DOT0.h"

/******************************************************************************/
/*                    Declaration of exported variables                       */
/******************************************************************************/

extern const canuint8  cabLinRxDLCTbl[];
extern canuint8* const capbLinRxDataPtrTbl[7];
extern const canuint8  cabLinTxDataLenTbl[];
extern canuint8* const capbLinTxDataPtrTbl[11];
extern const canuint8  cabLinRxDataLenTbl[];
extern const canuint8  cabLinRxDLCTbl[];
extern const canuint8  cabLinMsgHandleTbl[18];


extern canuint8             rabRAMLinMsgIDToHandleTbl[0x40];
extern const canuint16 cawLINMessageID[18];




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
  canbittype                    RLSMSerNoNr1_CEM_LIN1: 8;
  canbittype                    RLSMSerNoNr2_CEM_LIN1: 8;
  canbittype                    RLSMSerNoNr3_CEM_LIN1: 8;
  canbittype                    RLSMSerNoNr4_CEM_LIN1: 8;
} _c_RlsmCem_SerNrLin1Fr01_CEM_LIN1_msgType;

typedef struct {
  canbittype                 RLSMPartNo10Nr1_CEM_LIN1: 8;
  canbittype                 RLSMPartNo10Nr2_CEM_LIN1: 8;
  canbittype                 RLSMPartNo10Nr3_CEM_LIN1: 8;
  canbittype                 RLSMPartNo10Nr4_CEM_LIN1: 8;
  canbittype                 RLSMPartNo10Nr5_CEM_LIN1: 8;
  canbittype             RLSMPartNo10EndSgn1_CEM_LIN1: 8;
  canbittype             RLSMPartNo10EndSgn2_CEM_LIN1: 8;
  canbittype             RLSMPartNo10EndSgn3_CEM_LIN1: 8;
} _c_RlsmCem_Lin1PartNrFr02_CEM_LIN1_msgType;

typedef struct {
  canbittype                   RLSMPartNoNr1_CEM_LIN1: 8;
  canbittype                   RLSMPartNoNr2_CEM_LIN1: 8;
  canbittype                   RLSMPartNoNr3_CEM_LIN1: 8;
  canbittype                   RLSMPartNoNr4_CEM_LIN1: 8;
  canbittype               RLSMPartNoEndSgn1_CEM_LIN1: 8;
  canbittype               RLSMPartNoEndSgn2_CEM_LIN1: 8;
  canbittype               RLSMPartNoEndSgn3_CEM_LIN1: 8;
} _c_RlsmCem_Lin1PartNrFr01_CEM_LIN1_msgType;

typedef struct {
  canbittype                    SolarSnsrErr_CEM_LIN1: 3;
  canbittype RainSnsrDiagcRainSnsrHiVoltDetd_CEM_LIN1: 1;
  canbittype    RainSnsrDiagcRainSnsrHiTDetd_CEM_LIN1: 1;
  canbittype                       LiOprnMod_CEM_LIN1: 2;
  canbittype                    RainDetected_CEM_LIN1: 1;
  canbittype                                  unused0: 8;
  canbittype                SolarSnsrLeValue_CEM_LIN1: 8;
  canbittype                SolarSnsrRiValue_CEM_LIN1: 8;
  canbittype                                  unused1: 8;
  canbittype                                  unused2: 8;
  canbittype                                  unused3: 8;
  canbittype                                  unused4: 8;
} _c_RlsmCem_Lin1Fr03_CEM_LIN1_msgType;

typedef struct {
  canbittype              CmptFrntWindDewT_CEM_LIN1_0: 8;
  canbittype              CmptFrntWindDewT_CEM_LIN1_1: 3;
  canbittype              AmbIllmnFwdStsCntr_CEM_LIN1: 4;
  canbittype                                  unused0: 1;
  canbittype        AmbIllmnFwdStsAmblillmn2_CEM_LIN1: 8;
  canbittype              AmbIllmnFwdStsChks_CEM_LIN1: 8;
  canbittype      AmbIllmnFwdStsAmblillmn1_CEM_LIN1_0: 8;
  canbittype      AmbIllmnFwdStsAmblillmn1_CEM_LIN1_1: 1;
  canbittype                CmptFrntWindTErr_CEM_LIN1: 1;
  canbittype                   RelHumSnsrErr_CEM_LIN1: 3;
  canbittype                 CmptFrntWindT_CEM_LIN1_0: 3;
  canbittype                 CmptFrntWindT_CEM_LIN1_1: 8;
  canbittype                RelHumSnsrRelHum_CEM_LIN1: 8;
} _c_RlsmCem_Lin1Fr02_CEM_LIN1_msgType;

typedef struct {
  canbittype                   AutWinWipgCmd_CEM_LIN1: 3;
  canbittype                HudSnsrErrParChk_CEM_LIN1: 1;
  canbittype               HudSnsrErrSnsrErr_CEM_LIN1: 1;
  canbittype                                  unused0: 2;
  canbittype                          RainLi_CEM_LIN1: 1;
  canbittype           RainSnsrErrCalErrActv_CEM_LIN1: 1;
  canbittype               RainSnsrErrCalErr_CEM_LIN1: 1;
  canbittype          RainSnsrErrRainDetnErr_CEM_LIN1: 1;
  canbittype      RainSnsrErrRainDetnErrActv_CEM_LIN1: 1;
  canbittype                  WipgAutFrntMod_CEM_LIN1: 2;
  canbittype                                  unused1: 1;
  canbittype                     ErrRespRLSM_CEM_LIN1: 1;
  canbittype                                  unused2: 8;
  canbittype                    TwliBriRawQf_CEM_LIN1: 2;
  canbittype          TwliBriRawTwliBriRaw_CEM_LIN1_0: 6;
  canbittype          TwliBriRawTwliBriRaw_CEM_LIN1_1: 8;
  canbittype                                  unused3: 8;
  canbittype                     OutdBriChks_CEM_LIN1: 8;
  canbittype                      OutdBriSts_CEM_LIN1: 2;
  canbittype                                  unused4: 6;
} _c_RlsmCem_Lin1Fr01_CEM_LIN1_msgType;


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
  canbittype                                  unused0: 4;
  canbittype                        WiprActv_CEM_LIN1: 1;
  canbittype                WiprInPrkgPosnLo_CEM_LIN1: 1;
  canbittype                    WiprInWipgAr_CEM_LIN1: 1;
  canbittype                    WshngCycActv_CEM_LIN1: 1;
} _c_CemCem_Lin1Fr06_CEM_LIN1_msgType;

typedef struct {
  canbittype                                  unused0: 1;
  canbittype                    VehMtnStCntr_CEM_LIN1: 4;
  canbittype                VehMtnStVehMtnSt_CEM_LIN1: 3;
  canbittype                    VehMtnStChks_CEM_LIN1: 8;
  canbittype                                  unused1: 1;
  canbittype               EnaOfflineMonitor_CEM_LIN1: 1;
  canbittype                                  unused2: 6;
  canbittype                                  unused3: 8;
  canbittype                                  unused4: 8;
  canbittype                                  unused5: 8;
  canbittype                                  unused6: 8;
} _c_CemCem_Lin1Fr05_CEM_LIN1_msgType;

typedef struct {
  canbittype                                  unused0: 8;
  canbittype                                  unused1: 8;
  canbittype                                  unused2: 8;
  canbittype                                  unused3: 8;
  canbittype                     DoorDrvrSts_CEM_LIN1: 2;
  canbittype                                  unused4: 6;
  canbittype                                  unused5: 4;
  canbittype                   RainSnsrLiThd_CEM_LIN1: 4;
  canbittype                                  unused6: 8;
} _c_CemCem_Lin1Fr04_CEM_LIN1_msgType;

typedef struct {
  canbittype       RainSnsrSnvtyForUsrSnvty0_CEM_LIN1: 4;
  canbittype       RainSnsrSnvtyForUsrSnvty1_CEM_LIN1: 4;
  canbittype       RainSnsrSnvtyForUsrSnvty2_CEM_LIN1: 4;
  canbittype       RainSnsrSnvtyForUsrSnvty3_CEM_LIN1: 4;
  canbittype       RainSnsrSnvtyForUsrSnvty4_CEM_LIN1: 4;
  canbittype       RainSnsrSnvtyForUsrSnvty5_CEM_LIN1: 4;
  canbittype       RainSnsrSnvtyForUsrSnvty6_CEM_LIN1: 4;
  canbittype                          VehTyp_CEM_LIN1: 4;
  canbittype                 WindCorrnValAmb_CEM_LIN1: 8;
  canbittype                WindCorrnValFrnt_CEM_LIN1: 8;
  canbittype                 WindCorrnValHud_CEM_LIN1: 8;
  canbittype                          FrqCfg_CEM_LIN1: 4;
  canbittype                      ReAdaptReq_CEM_LIN1: 1;
  canbittype                                  unused0: 3;
} _c_CemCem_Lin1Fr03_CEM_LIN1_msgType;

typedef struct {
  canbittype                     AmbTForVisy_CEM_LIN1: 8;
  canbittype                                  unused0: 1;
  canbittype VehModMngtGlbSafe1FltEgyCnsWdSts_CEM_LIN1: 1;
  canbittype    VehModMngtGlbSafe1CarModSts1_CEM_LIN1: 3;
  canbittype VehModMngtGlbSafe1CarModSubtypWdCarModSubtyp_CEM_LIN1: 3;
  canbittype          VehModMngtGlbSafe1Chks_CEM_LIN1: 8;
  canbittype VehModMngtGlbSafe1EgyLvlElecMai_CEM_LIN1: 4;
  canbittype          VehModMngtGlbSafe1Cntr_CEM_LIN1: 4;
  canbittype VehModMngtGlbSafe1PwrLvlElecMai_CEM_LIN1: 4;
  canbittype VehModMngtGlbSafe1EgyLvlElecSubtyp_CEM_LIN1: 4;
  canbittype     VehModMngtGlbSafe1UsgModSts_CEM_LIN1: 4;
  canbittype VehModMngtGlbSafe1PwrLvlElecSubtyp_CEM_LIN1: 4;
  canbittype                                  unused1: 8;
} _c_CemCem_Lin1Fr02_CEM_LIN1_msgType;

typedef struct {
  canbittype                   VehSpdForWipg_CEM_LIN1: 8;
  canbittype WipgPwrActvnSafeWipgPwrAcsyModSafe_CEM_LIN1: 2;
  canbittype WipgPwrActvnSafeWipgPwrDrvgModSafe_CEM_LIN1: 2;
  canbittype                   RainSensActvn_CEM_LIN1: 1;
  canbittype                 WshrLvrPosnSafe_CEM_LIN1: 2;
  canbittype                                  unused0: 1;
  canbittype WiprMotFrntLvrCmdSafeLvrInHiSpdPosnSafe_CEM_LIN1: 2;
  canbittype WiprMotFrntLvrCmdSafeLvrInLoSpdPosnSafe_CEM_LIN1: 2;
  canbittype WiprMotFrntLvrCmdSafeLvrInSnglStrokePos_CEM_LIN1: 1;
  canbittype WiprMotFrntLvrCmdSafeLvrInIntlPosn_CEM_LIN1: 1;
  canbittype                     HomeLinkEna_CEM_LIN1: 2;
  canbittype                  WiprMotIntlCmd_CEM_LIN1: 3;
  canbittype               WiprPosnForSrvReq_CEM_LIN1: 1;
  canbittype                                  unused1: 4;
  canbittype     IntrMirrCmdIntrMirrDimSnvty_CEM_LIN1: 2;
  canbittype             IntrMirrCmdDrvrSide_CEM_LIN1: 1;
  canbittype IntrMirrCmdIntrMirrWindHeatrCmpMag_CEM_LIN1: 1;
  canbittype          IntrMirrCmdIntrMirrEna_CEM_LIN1: 1;
  canbittype      IntrMirrCmdIntrMirrInhbDim_CEM_LIN1: 1;
  canbittype     IntrMirrCmdIntrMirrDiagcRst_CEM_LIN1: 1;
  canbittype IntrMirrCmdIntrMirrAsyFanCmpMag_CEM_LIN1: 1;
  canbittype               WiprMotFrntOffsAg_CEM_LIN1: 4;
  canbittype                                  unused2: 4;
} _c_CemCem_Lin1Fr01_CEM_LIN1_msgType;


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
    _c_RlsmCem_SerNrLin1Fr01_CEM_LIN1_msgType rlsmcem_sernrlin1fr01_cem_lin1;
} _c_RlsmCem_SerNrLin1Fr01_CEM_LIN1_buf;

typedef union {
    unsigned char _c[8];
    _c_RlsmCem_Lin1PartNrFr02_CEM_LIN1_msgType rlsmcem_lin1partnrfr02_cem_lin1;
} _c_RlsmCem_Lin1PartNrFr02_CEM_LIN1_buf;

typedef union {
    unsigned char _c[7];
    _c_RlsmCem_Lin1PartNrFr01_CEM_LIN1_msgType rlsmcem_lin1partnrfr01_cem_lin1;
} _c_RlsmCem_Lin1PartNrFr01_CEM_LIN1_buf;

typedef union {
    unsigned char _c[8];
    _c_RlsmCem_Lin1Fr03_CEM_LIN1_msgType rlsmcem_lin1fr03_cem_lin1;
} _c_RlsmCem_Lin1Fr03_CEM_LIN1_buf;

typedef union {
    unsigned char _c[8];
    _c_RlsmCem_Lin1Fr02_CEM_LIN1_msgType rlsmcem_lin1fr02_cem_lin1;
} _c_RlsmCem_Lin1Fr02_CEM_LIN1_buf;

typedef union {
    unsigned char _c[8];
    _c_RlsmCem_Lin1Fr01_CEM_LIN1_msgType rlsmcem_lin1fr01_cem_lin1;
} _c_RlsmCem_Lin1Fr01_CEM_LIN1_buf;


/* Receive messages */

typedef union {
    unsigned char _c[8];
    _c_LinReqCmd_msgType linreqcmd;
} _c_LinReqCmd_buf;

typedef union {
    unsigned char _c[1];
    _c_CemCem_Lin1Fr06_CEM_LIN1_msgType cemcem_lin1fr06_cem_lin1;
} _c_CemCem_Lin1Fr06_CEM_LIN1_buf;

typedef union {
    unsigned char _c[7];
    _c_CemCem_Lin1Fr05_CEM_LIN1_msgType cemcem_lin1fr05_cem_lin1;
} _c_CemCem_Lin1Fr05_CEM_LIN1_buf;

typedef union {
    unsigned char _c[7];
    _c_CemCem_Lin1Fr04_CEM_LIN1_msgType cemcem_lin1fr04_cem_lin1;
} _c_CemCem_Lin1Fr04_CEM_LIN1_buf;

typedef union {
    unsigned char _c[8];
    _c_CemCem_Lin1Fr03_CEM_LIN1_msgType cemcem_lin1fr03_cem_lin1;
} _c_CemCem_Lin1Fr03_CEM_LIN1_buf;

typedef union {
    unsigned char _c[7];
    _c_CemCem_Lin1Fr02_CEM_LIN1_msgType cemcem_lin1fr02_cem_lin1;
} _c_CemCem_Lin1Fr02_CEM_LIN1_buf;

typedef union {
    unsigned char _c[6];
    _c_CemCem_Lin1Fr01_CEM_LIN1_msgType cemcem_lin1fr01_cem_lin1;
} _c_CemCem_Lin1Fr01_CEM_LIN1_buf;


/******************************************************************************/
/*                          Databuffer for send objects                       */
/******************************************************************************/

extern  _c_LinRespCmd_buf LinRespCmd;
extern  _c_ASIC_Frame_04_buf ASIC_Frame_04;
extern  _c_ASIC_Frame_03_buf ASIC_Frame_03;
extern  _c_ASIC_Frame_02_buf ASIC_Frame_02;
extern  _c_ASIC_Frame_01_buf ASIC_Frame_01;
extern  _c_RlsmCem_SerNrLin1Fr01_CEM_LIN1_buf RlsmCem_SerNrLin1Fr01_CEM_LIN1;
extern  _c_RlsmCem_Lin1PartNrFr02_CEM_LIN1_buf RlsmCem_Lin1PartNrFr02_CEM_LIN1;
extern  _c_RlsmCem_Lin1PartNrFr01_CEM_LIN1_buf RlsmCem_Lin1PartNrFr01_CEM_LIN1;
extern  _c_RlsmCem_Lin1Fr03_CEM_LIN1_buf RlsmCem_Lin1Fr03_CEM_LIN1;
extern  _c_RlsmCem_Lin1Fr02_CEM_LIN1_buf RlsmCem_Lin1Fr02_CEM_LIN1;
extern  _c_RlsmCem_Lin1Fr01_CEM_LIN1_buf RlsmCem_Lin1Fr01_CEM_LIN1;

/******************************************************************************/
/*                        Databuffer for confirmationflags                    */
/******************************************************************************/

#line 516 "C:\\BASELINE\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SWDEV\\01_SRCCODE\\APPLICATION\\LIN\\G5_rls_GEELY2DOT0.h"

/******************************************************************************/
/*                         Databuffer for receive objects                     */
/******************************************************************************/

extern  _c_LinReqCmd_buf LinReqCmd;
extern  _c_CemCem_Lin1Fr06_CEM_LIN1_buf CemCem_Lin1Fr06_CEM_LIN1;
extern  _c_CemCem_Lin1Fr05_CEM_LIN1_buf CemCem_Lin1Fr05_CEM_LIN1;
extern  _c_CemCem_Lin1Fr04_CEM_LIN1_buf CemCem_Lin1Fr04_CEM_LIN1;
extern  _c_CemCem_Lin1Fr03_CEM_LIN1_buf CemCem_Lin1Fr03_CEM_LIN1;
extern  _c_CemCem_Lin1Fr02_CEM_LIN1_buf CemCem_Lin1Fr02_CEM_LIN1;
extern  _c_CemCem_Lin1Fr01_CEM_LIN1_buf CemCem_Lin1Fr01_CEM_LIN1;

/******************************************************************************/
/*                          Databuffer for indicationflags                    */
/******************************************************************************/

#line 554 "C:\\BASELINE\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SWDEV\\01_SRCCODE\\APPLICATION\\LIN\\G5_rls_GEELY2DOT0.h"

/******************************************************************************/
/*                               Definition of signals                        */
/******************************************************************************/

#line 1114 "C:\\BASELINE\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SWDEV\\01_SRCCODE\\APPLICATION\\LIN\\G5_rls_GEELY2DOT0.h"


#line 149 "C:\\baseline\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_lininclude.h"






/******************************************************************************/
/*                    Declaration of exported variables                       */
/******************************************************************************/







#line 98 "C:\\baseline\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_RLS_LIN_GEELY2DOT0.c"

/*************************************************************************
**                   Other files included                               **
**************************************************************************/
#line 1 "C:\\BASELINE\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SWDEV\\01_SRCCODE\\APPLICATION\\PERIPHERALS\\G5_io.h"
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





//#define BMW_PARAMETER








/****************************************************************************/
/** Global Variables **/
/****************************************************************************/
//EXTERN byte rb_Powerfailcyclecounter;
//EXTERN byte rb_ASIC_Diagnose_State_mg; //State for ASIC Diagnosis
//EXTERN word rw_pulsewith_alt_mg;
//EXTERN byte rb_pulsewith_stored_mg;
/* PRQA S 0759 10*//*<< 0759:union needed to reduce RAM usage >>*/
extern   volatile Flag uF_VoltageStatus_g;
#line 65 "C:\\BASELINE\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SWDEV\\01_SRCCODE\\APPLICATION\\PERIPHERALS\\G5_io.h"


extern   byte rb_SupplyVoltage_mg; //Value of Supply Voltage
extern   byte rb_InternalTemperature_g; //Value of Supply Voltage

#line 77 "C:\\BASELINE\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SWDEV\\01_SRCCODE\\APPLICATION\\PERIPHERALS\\G5_io.h"

/****************************************************************************/
/** Global Flags **/
/****************************************************************************/










/* PRQA S 0759 10*//*<< 0759:union needed to reduce RAM usage >>*/
extern  volatile Flag uF_ASIC_Communication_g;



//#define rbi_ASCI_StandByProcedureOff_g          uF_ASIC_Communication_g.Bit.B2


//#define rbi_ASIC_EEPromChecked_g                uF_ASIC_Communication_g.Bit.B5
//#define rbi_ASIC_diagnose_request_mg            uF_ASIC_Communication_g.Bit.B6
//#define rbi_ASICWriteEEPromWritten_g            uF_ASIC_Communication_g.Bit.B7




/****************************************************************************/
// Includes for different Derivates with Port definition
/****************************************************************************/


#line 1 "C:\\BASELINE\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SWDEV\\01_SRCCODE\\APPLICATION\\PERIPHERALS\\G5_io_sen.h"


/* History                                                                    */
/*----------------------------------------------------------------------------*/
/* Date      VDR_Number  Name    Description                                       */
/*----------------------------------------------------------------------------*/
/* 20.11.09  VDR_405	 AL    New Port assignment for B3 Sample */

/* 24.09.09  VDR_372	 AL      Mesurment of NTC and usage of new MicroController Ports
PWM could be switched to portpin by EEPROM
Usage of EEPROM Cell for Amb Night and DayThreshold
Remove EEPROM valeo for IR and FW scaling for VWK*/
/* 11.06.08  VDR_227      FS      Changed due to Lada Project*/
/* 08.12.2014 VCO_151  NB  Implement IC test */
/* 08.04.2015 VDR_870   NB    Set all unused IO ports of microcontroller to Output low */ 
/******************************************************************************/







/* Anlaogports */
/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
















/* Digitalports */
/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */


/* SPI */














/* UART */







/* TOOL0 */



/* WATCHDOG */





/****************************************************************************/
/** IO-Port Definition for Sensirion used in HumTemp.c                     **/

/* SHT1x Data Line */




/* SHT1x Clock Line */



/* 2 Pins for powersupply for the SHT module */

















/* Port 3 */







/* Unused Ports */






























/******************************************************************************/
/*** BINARY NUMBERS  * HEX *  *   DEC *                                     ***/
/******************************************************************************/

#line 168 "C:\\BASELINE\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SWDEV\\01_SRCCODE\\APPLICATION\\PERIPHERALS\\G5_io_sen.h"

#line 185 "C:\\BASELINE\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SWDEV\\01_SRCCODE\\APPLICATION\\PERIPHERALS\\G5_io_sen.h"

#line 202 "C:\\BASELINE\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SWDEV\\01_SRCCODE\\APPLICATION\\PERIPHERALS\\G5_io_sen.h"

#line 219 "C:\\BASELINE\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SWDEV\\01_SRCCODE\\APPLICATION\\PERIPHERALS\\G5_io_sen.h"

#line 236 "C:\\BASELINE\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SWDEV\\01_SRCCODE\\APPLICATION\\PERIPHERALS\\G5_io_sen.h"

#line 253 "C:\\BASELINE\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SWDEV\\01_SRCCODE\\APPLICATION\\PERIPHERALS\\G5_io_sen.h"

#line 270 "C:\\BASELINE\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SWDEV\\01_SRCCODE\\APPLICATION\\PERIPHERALS\\G5_io_sen.h"

#line 287 "C:\\BASELINE\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SWDEV\\01_SRCCODE\\APPLICATION\\PERIPHERALS\\G5_io_sen.h"

#line 304 "C:\\BASELINE\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SWDEV\\01_SRCCODE\\APPLICATION\\PERIPHERALS\\G5_io_sen.h"

#line 321 "C:\\BASELINE\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SWDEV\\01_SRCCODE\\APPLICATION\\PERIPHERALS\\G5_io_sen.h"

#line 338 "C:\\BASELINE\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SWDEV\\01_SRCCODE\\APPLICATION\\PERIPHERALS\\G5_io_sen.h"

#line 355 "C:\\BASELINE\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SWDEV\\01_SRCCODE\\APPLICATION\\PERIPHERALS\\G5_io_sen.h"

#line 372 "C:\\BASELINE\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SWDEV\\01_SRCCODE\\APPLICATION\\PERIPHERALS\\G5_io_sen.h"

#line 389 "C:\\BASELINE\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SWDEV\\01_SRCCODE\\APPLICATION\\PERIPHERALS\\G5_io_sen.h"

#line 406 "C:\\BASELINE\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SWDEV\\01_SRCCODE\\APPLICATION\\PERIPHERALS\\G5_io_sen.h"

#line 423 "C:\\BASELINE\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SWDEV\\01_SRCCODE\\APPLICATION\\PERIPHERALS\\G5_io_sen.h"



#line 112 "C:\\BASELINE\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SWDEV\\01_SRCCODE\\APPLICATION\\PERIPHERALS\\G5_io.h"


/*************************************************************************
Declaration of exported functions
**************************************************************************/
extern void IO_RefreshPorts(void);
extern void IO_Ports_init(void);
/*VCO_237 Supplyvoltage should not be monitored on no rain variants*/
/*is rain function enabled?*/

extern __callt void io_checkPowerSupply(void);


/*is rain function enabled?*/

extern void IO_ExternalUnderVoltageEvent(void); /*VCO_23 new function to react direct at undervoltge event*/


/* PRQA S 0841 7 */ /* <<for easier declaration of variable -> proven mechanism>> */


#line 103 "C:\\baseline\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_RLS_LIN_GEELY2DOT0.c"
#line 1 "C:\\BASELINE\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SWDEV\\01_SRCCODE\\APPLICATION\\OS\\G5_Appli_timer.h"



/*  Datum: Mittwoch, 6. Oktober 1999 und File: Timer.h
******************************************************************************
*    Modul: <Timer>
******************************************************************************
*
*    Description: Header file for timer modul
*
******************************************************************************
*/
/*************************************************************************

Company : Valeo Switches and Detection Systems

Project : RLT Sensor Generation 3.5

Component : G5_Appli_timer.h

Documentation reference : System Architectur spec.
---------------------------------------------------------------------------
Overview of the component : This module includes the hardware specific
---------------------------------------------------------------------------
Evolution of the component : */
/*----------------------------------------------------------------------------*/
/* Date         VDR_Number         Name          Description                                */
/*----------------------------------------------------------------------------*/
/* 24.03.2015   VCO_237           MP            Supplyvoltage should not be monitored on no rain variants*/
/*13.07.15      VDR_868           NB           QAC and Polyspace fixing for SW009 Release                */
/* 23.11.2015 VDR_927             NB           Wiper speed is valid on the bus only after 1.35 sec  */

/* PRQA S 0759 EOF *//*<< 0759:union needed to reduce RAM usage >>*/

















/*VCO_237 Supplyvoltage should not be monitored on no rain variants*/
/*default value for supply voltage for no rain variants*/




extern  unsigned char rb_10msTimer_s;
/* Global Interface Variables */

extern  volatile Flag uF_Timer_g;              /* variable for flag for timer */


/* for debugging global */
extern byte rb_ADC_Error_cnt_g;
extern byte rb_ClockFreq_Error_cnt_g;
extern byte rb_AfterVddPowerFailDelay_g;

/* #define rbi_TimeBase_OK_g	   uF_Timer_g.Bit.B0  */           /* flag for 30ms is over */




extern Flag uF_uC_Error_g;



/** Function Prototypes **/

extern __callt void AD_ConversionPerIntStart(byte rb_channel_l);
extern void Change_DigitalPortToAnalog(void);
extern void Change_AnalogPortToDigital(void);
/* PRQA S 0841 7 */ /* <<for easier declaration of variable -> proven mechanism>> */


#line 104 "C:\\baseline\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_RLS_LIN_GEELY2DOT0.c"
#line 1 "C:\\BASELINE\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SWDEV\\01_SRCCODE\\APPLICATION\\DIAGNOSTICS\\G5_Check_sr.h"


/*************************************************************************/
/* History                                                                    */
/*----------------------------------------------------------------------------*/
/* Date      VDR_Number     Description                                       */
/*----------------------------------------------------------------------------*/
/* 27.05.19  VCO_051    AL      Use _Callt functions to speed up initialisation*/
/* 26.05.10  VCO_055    AL      remove debouncing of RAM and ROM error*/
/* 22.03.11  VDR_638    AL      MISRA OPTIMISATION with corrections in Source code */
/* 19.09.2014 VCO_184   NB      Checksum for calibration data */
/* 29.09.2014 VCO_154   MP      Safety:SM139,SM140:Implement RS_Error_Aktiv,LS_Error_Aktiv flag  to*/
/*******************************check after Reset if a error was active before the sensor goes to sleep or reset */
/* 08.12.2014 VCO_151   NB      Implement IC test */
/* 25.02.2015 VCO_225   MP      RS functionality detection - error when not available*/
/*03.03.15   VCO_227    NB     Implement RAM Guard function */
/* 10.03.15    VCO_227    NB     Implement RAM Guard function */
/* 02.12.15    VDR_938    NB     Exclude RAM test for the area used by selfprogramming library */
/* 03.12.15    VDR_938    NB     Exclude RAM test for the area used by selfprogramming library */
/* PRQA S 0759 EOF */ /* << union is sopported by this compiler>>*/





#line 32 "C:\\BASELINE\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SWDEV\\01_SRCCODE\\APPLICATION\\DIAGNOSTICS\\G5_Check_sr.h"




/* PRQA S 1015 EOF *//*<< 1015:__far needed for IAR compiler  >>*/



extern const unsigned int __far chksum2000_FEEF;
extern const unsigned int __far chksum_mirror2000_FEEF;



/** Global Functions **/


extern unsigned int rw_RAM_DefectCell_g;

extern Flag uF_Diagnose_pre_Flag;



/*VCO_225 RS functionality detection - error when not available*/






extern unsigned int rw_CRC16_g;
extern byte rb_ReadActiveErrors_g;


extern  void check_crc16_calib(void); 
extern __callt void check_crc16(void); /*VCO_051*/
extern __callt void CheckRAM(void);  /*VCO_051*/


extern void RamGuard_init(void);
extern void RamGuardTest(void);
extern __callt void DisableRamGuard(void);
extern __callt void EnableRamGuard(void);
/* PRQA S 0841 7 */ /* <<for easier declaration of variable -> proven mechanism>> */


#line 105 "C:\\baseline\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_RLS_LIN_GEELY2DOT0.c"
#line 1 "C:\\baseline\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_rainsens.h"


/*****************************************************************************************************************

Company : Valeo Wiper Systems

Project : RLT Sensor, RDN Sensor

Component : Rainsens.h

Documentation reference :Rainsensor Software Integration

Overview of the component : variable and prottype declaration
for rainsens.c
Evolution of the component : see PVCS Version control system

Initials   date   modification
*****************************************************************************************************************/

/****************************************************************************************************************/
/****************************************************************************************************************/
/* History                                                                                                      */
/*--------------------------------------------------------------------------------------------------------------*/
/* Date      VDR_Number     Description                                                                         */
/*-DD.MM.YY-----------------------------------------------------------------------------------------------------*/
/*17.11.09      VDR_373    FS      Adaptation Sinle or DOuble Overwiped Function                                */
/*18.09.09      VDR_357    FS      No function of Under Voltage Fixed Intervall --> Corrected                   */
/*24.06.08      VDR_240    FS      Define rbi_ParkPosition_NearRLTPosition_g -->                                */
/***********************************Seat-Parameter should be usable in TMC-SW for Tata                          */
/*01.04.15      VDR_866    MP      Remove of rainsens.c for no-rain-variants                                    */
/*13.05.15      VCO_192    NB      Audi: Activation and deactivation of Interval Operation                      */
/*09.06.15      VCO_192    NB      Audi: Activation and deactivation of Interval Operation                      */
/*13.07.15      VCO_260    MP      Tunnel wipe activation and delay according to                                */
/***********************************Tunnel Verzoegerung and Aktivierung parameters                              */
/****************************************************************************************************************/
/****************************************************************************************************************/
/* Definition for Mono-Inclusion                                                                                */
/****************************************************************************************************************/



#line 54 "C:\\baseline\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_rainsens.h"


/*************************************************************************
**                   Compile options                                    **
**************************************************************************/

/*************************************************************************
**                   Declaration of exported constants                  **
**************************************************************************/
#line 1 "C:\\BASELINE\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SWDEV\\01_SRCCODE\\APPLICATION\\RAIN\\G5_rs_lib.h"
/******************************************************************************
*******************************************************************************
*******************************************************************************
**
** Datei:      RS_lib.h
**
**
** Bearbeiter: Bernd Schmid Abt. TKW
**
** Datum:      04.03.98
** geaendert:  25.06.98
**
** Inhalt:     Deklaration der Schnittstellenvariablen
**             und Funktionsprototypen.
**
**             Der Herstller des Steuergeraet muss dieses Header-File
**             zusaetzlich zur Regensensor-Libary einbinden.
**
*******************************************************************************
*******************************************************************************
******************************************************************************/




/*
//Definition des Bitfeldes
//========================
typedef struct
{
unsigned  B7:1;
unsigned  B6:1;
unsigned  B5:1;
unsigned  B4:1;
unsigned  B3:1;
unsigned  B2:1;
unsigned  B1:1;
unsigned  B0:1;
} RS_Bit_Feld;


typedef union
{
RS_Bit_Feld Bit;
unsigned int AllBit;
} RS_Flag;



//Belegung des Bitfeldes
//======================

//Input Variables for Rain Sensor
#define rbi_RainSensorEnable	 RSStatus.Bit.B0
#define	rbi_WashingActive    	 RSStatus.Bit.B1
#define rbi_LowVoltage        RSStatus.Bit.B2
#define rbi_Night              RSStatus.Bit.B3 //!!!NICHT RSStatus.Bit.B2 !!

//Output Variables from Rain Sensor
#define	rbi_RainSensorError	     RSStatus.Bit.B4
#define	rbi_RSWipeSlowDmd        RSStatus.Bit.B5
#define	rbi_RSWipeFastDmd	     RSStatus.Bit.B6

*/





//Berechnete Intervallzeit
//========================

extern unsigned char rub_RSIntermDelayInit;      //interne Regensensosr Delay Time





//Funktionsprototypen
//===================
extern void wwrainse_Init(void);
extern void wwrainse_Task10ms(void);
extern void wwrainse_Task40ms(void);




#line 65 "C:\\baseline\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_rainsens.h"
#line 1 "C:\\BASELINE\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SWDEV\\01_SRCCODE\\APPLICATION\\RAIN\\G5_rs_ext.h"



/******************************************************************************
*******************************************************************************
**                              test
** Datei:      rs_ext.h
**
** Bearbeiter: Bernd Schmid Abt. WRS
**
** Projekt:    (PQ24)/D66
**
** Datum:      10.03.98
** geaendert:  23.05.00
**
** Funktion:   Include File fuer die externen Deklaration von Variablen der
**             Regensensorauswertung
**
*******************************************************************************
******************************************************************************/
/*
230801:
defines fuer EEProm-Variablen eingefuehrt!

310501:
rub_RSIntermDelayInit_internal eingefuehrt: Interne Variable zur Berechnung
der Intervallzeit!
// 180501
// Die Variablen fuer x400 auskommentiert!

// 26.05.00
// memory=zpage bei IAR define enfernt
*/
// Variablen, die von Valeo an das Steuergeraet bereitgestellt werden
//===================================================================

/* History                                                                    */
/*----------------------------------------------------------------------------*/
/* Date         VDR_Number  Author       Description                                       */
/*----------------------------------------------------------------------------*/
/* 27.11.2014   VCO_200    NB      move rb_LimitMemomryNoWiperReaction_g variable from G5_sci.h to G5_rs_mem_40.h */
/******************************************************************************/
/* PRQA S 857 EOF *//*<< Macro exceeds 1024 number  >>*/

#line 1 "C:\\baseline\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_projectDefs.h"
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
 *  This file is designed to contain all RLS projects in order to define compiler
 * switches for the RELEASE configuration. The purpose is to have the project -
 * feature relation stored in one header file and thus available for all compilers
 * and third party tools.
 *
 * %PCMS_HEADER_SUBSTITUTION_START:%
 * <table border="0" cellspacing="0" cellpadding="0">
 * <tr> <td> Source:   </td> <td> %PM: template.h %                  </td></tr>
 * <tr> <td> Revision: </td> <td> %PR: 1.8 %                  </td></tr>
 * <tr> <td> Status:   </td> <td> %PS: UNDER_REVIEW %                  </td></tr>
 * <tr> <td> Author:   </td> <td> R.Fichtner, DUS-E-RLS  </td></tr>
 * <tr> <td> Date:     </td> <td> %PUDT: 20-FEB-2013 15:20:57 %                </td></tr>
 * </table>
 * %PCMS_HEADER_SUBSTITUTION_END:%
 * \n
 * <table border="0" cellspacing="0" cellpadding="0">
 * <tr> <td> COMPONENT: </td> <td> XXXX                            </td></tr>
 * <tr> <td> SCOPE:     </td> <td> <Public/Private/Component>      </td></tr>
 * <tr> <td> TARGET:    </td> <td> <All/Freescale S12X/S12XE/...>  </td></tr>
 * </table>
 */
/*----------------------------------------------------------------------------*/
/* Date      VDR_Number   Author   Description                                */
/*----------------------------------------------------------------------------*/
/*09.19.17   VCO_451    NB    All:Add spare LIN IDs in the EEPROM             */
/*07.12.17   VCO_462    HB    FIAT 330: parallel branch                       */
/******************************************************************************/


#line 285 "C:\\baseline\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_projectDefs.h"

#line 46 "C:\\BASELINE\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SWDEV\\01_SRCCODE\\APPLICATION\\RAIN\\G5_rs_ext.h"

extern unsigned char rb_LimitMemomryNoWiperReaction_g;
extern unsigned short int ruw_St2_Speicher;	      //Integrationsspeicher fuer Stufe2
extern unsigned short int ruw_St1_Speicher;       //Integrationsspeicher fuer Stufe1
extern unsigned short int ruw_StX_Speicher;       //Integrationsspeicher fuer Stufe1
extern unsigned char rub_SignalIntegral_g;          //Bandendetestvariable

extern unsigned short int ruw_Schwelle;		      //Schwelle fuer Ueberwischausblendung

extern unsigned short int ruw_SigInt;		      //Integrationsspeicher Signale
extern unsigned short int ruw_Signal;		  	  //Speicher fuer aktuelles Signal


extern unsigned char  rub_Int_Speicher;            //Integrationsspeicher fuer Intervall
extern unsigned char  rub_Ovr_Speicher;            //Integrationsspeicher fuer Override
extern unsigned char  rub_Speicher_max;            //max. Wert vom Intervallspeicher bzw, Override

extern unsigned char  rub_Empf_Faktor;             //Faktor, mit dem die einzelnen Signale gewichtet
//werden. Variable ist Abhaengig von der Poti-Stellung.

extern unsigned char rub_Sig_Anzahl;            //Anzahl der Signale pro Wischzyklus
extern unsigned char rub_Tropf_Anzahl;			//Anzahl der Tropfen fuer eine Wischung
extern unsigned char rub_Trock_Wisch;           //Zaehler fuer Trockenwischungen

extern unsigned char rub_Nachwisch_Count;       //Nachwischzaehler
extern unsigned char rub_St2_Epr;               //Entprell Variable fur Stufe2
extern unsigned char rbi_WiperStarted_g;        // bit to show that the wiper has started

//Fuer X400 !!!
//extern unsigned char rub_Direktbetrieb;           //Um Direktbetrieb nach einmaligem Beruehren des RS zu erkennen
//extern unsigned char rub_NormalRSBetrieb_justonetime; 
// Um Direktbetrieb bei einer einzigen Wischung feststellen zu koennen
//Fuer x400 ENDE !!!!

extern unsigned char rub_IntermDelayTime_LalstWipe_g;
extern unsigned char  rb_Sig_DownWipe_to_upWipe_g;


extern unsigned char rb_LIN_SensitivityShift_g;

/*****
EEPROM PARAMETER
****/


// Bit - Variablen
//================




/*  in "cdp.h"
extern bit rbi_Signal_min_Ok;                   //Flag fuer min. Signallaenge ueberschritten
extern bit rbi_SigSt2_max;

extern bit rbi_Tropfen_Merker;                  //Merker fuer gueltigen Tropfen

extern bit rbi_Sig_Ansammlung;                  //Merker fuer Signalansammlung
*/



//***********************************************************
//***********************************************************
//PREPROCESSOR_SWITCHES
//PART: BIT_VARIABLES OR BIT_FIELD
//***********************************************************
//***********************************************************

//AUSWAEHLEN DES COMPILERS FEHLT NOCH !!!!!!!!!
// FUR IAR KEIN (!!!!) BITFELD !!!


//Definition des Bitfeldes
//========================
typedef struct
{
  unsigned  B7:1;
  unsigned  B6:1;
  unsigned  B5:1;
  unsigned  B4:1;
  unsigned  B3:1;
  unsigned  B2:1;
  unsigned  B1:1;
  unsigned  B0:1;
} RS_Bit_Feld;

/* PRQA S 750,0759 20*//*<< 0759:union needed to reduce RAM usage >>*/
typedef union
{
  RS_Bit_Feld Bit;
  unsigned char AllBit;
} RS_Flag;

extern volatile RS_Flag RSStatus;                      //Schnittstellenbyte Flags!
extern volatile RS_Flag RS_Flags_Int;                  //Schnittstellenbyte RS-Flags!



//Belegung des Bitfeldes
//======================

//Input Variables for Rain Sensor




//Bit zum Ausblenden von Potiinkrementierungen bei nicht aktivem LSS for LIN_Sensor


//Output Variables from Rain Sensor





//Interne Regensensor Bitvariablen
//#define             RS_Flags_Int.Bit.B0
#line 173 "C:\\BASELINE\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SWDEV\\01_SRCCODE\\APPLICATION\\RAIN\\G5_rs_ext.h"


//#endif //GEHOERT NOCH ZUR OBEN VERLANGTEN PREPOCESSOR ABFRAGE !!!


//***********************************************************
//***********************************************************
// END OF PART BIT-VARIABLES OR BIT-FIELD
//***********************************************************
//***********************************************************









// Funktions-Prototypen
//=====================

extern void Motor(void);
extern void Signal(void);
extern void Empf(void);




#line 66 "C:\\baseline\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_rainsens.h"


// declaration of variables used by RS-Module in rs_task
extern unsigned char rub_WiperMotorTime;     //Time the Wiper Motor is runneing since last park
extern unsigned char rub_IntermDelayTime;    //initialed in Rainsensor_init
extern unsigned char rub_PotiStage;          //RS-Sensitivity 0-X
extern volatile unsigned char rub_LengthCounterHB;   /*VCO_108 counter for XY Table measurement*/
extern volatile unsigned char rub_PulseCounter;    //Counter for Pulses of Rainsensor Signals freerunning


extern unsigned char rb_PotiStageFromBox_g;
extern unsigned char rb_SplashLSWipe_g;

extern byte rb_LastWiperMotorTime_g; /* VDR_373 byte to simulate wendelage!*/
extern byte rb_ALInitTimer_g;

#line 88 "C:\\baseline\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_rainsens.h"
extern unsigned int rw_InitTimer_mg;                   // timer to create RS-Inidelay
extern unsigned int rw_rain_intensitiy_g;
//Input Variables for Rain Sensor


/* In and Outputs*/
/*******************/
/* PRQA S 0759 10*//*<< 0759:union needed to reduce RAM usage >>*/
extern  Flag uF_StatusRainsensor_mg;
// To be set if steering column switch is in intermittent mode

//#define rbi_Directmode_g                        uF_StatusRainsensor_mg.Bit.B1





// Last Parkposition to create Wipermotor time


/* PRQA S 0759 10*//*<< 0759:union needed to reduce RAM usage >>*/
extern  Flag uF_StatusRainsensor2_mg;
#line 116 "C:\\baseline\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_rainsens.h"
extern byte rb_WiperPosition_g;
// Defines for WiperPositionOn windshield






extern byte rb_WiperSpeed_g;
/*VCO_260 Tunnel wipe activation and delay according to Tunnel Verzoegerung and Aktivierung parameters*/
extern byte rb_WiperSpeedAlt_g;



/*************************************************************************
Declaration of exported functions
**************************************************************************/

extern void Rainsensor_evaluation(void);

extern void Rainsensor_AfterLowVoltage(void);


/* PRQA S 3458 5 *//*<< required for readability  >>*/
//function to deactivate the Rainsensor modules





/* PRQA S 0841 7 */ /* <<for easier declaration of variable -> proven mechanism>> */
#line 106 "C:\\baseline\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_RLS_LIN_GEELY2DOT0.c"
#line 1 "C:\\BASELINE\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SWDEV\\01_SRCCODE\\APPLICATION\\DIAGNOSTICS\\G5_diagnose.h"
/* PRQA S 3619 EOF */ /* << 2010 01 08, compiler allows whitespaces:due to readable code, keep whitespaces! >> */
/* PRQA S 3453 EOF *//*<< Macro is more readle and convinient in this situation >>*/
/* PRQA S 0750,759 EOF *//*<< 0759:union needed to reduce RAM usage >>*/
/**************VALEO WIPER SYSTEMS**SMART*SENSORS************************
*                                                                       *
*  HEADER FILE NAME : rls_lin.h                      *
*                                                                       *
*  LIBRARY ID       :                                                   *
*                                                                       *
*  DESCRIPTION      : interface LIN                                     *
*                  *
*                  *
*                                                                       *
*  SPECIAL LOGIC    :                                                   *
*                                                                       *
*************************************************************************
*                                                                       *
*                         MODIFICATION LOG                              *
*                                                                       *
* Date      VerNo     Auth   Description                                *
* --------  -----  ------------------------------------------  -------- */
/* 28.11.14 VCO_200   NB include structure update                       */
/* 09.04.15   VCO_242    NB     Remove length check of cb_REQLENGTHSID22_Multi_s for service 22 */
/*10.06.2015 VCO_254    NB    Checking of CRC over light area shall be done cyclically  */
/*06.08.15      VCO_264 NB      Implement common part in diagnostic file                                        */
/*28.08.15      VCO_268 SP      Cleanup the LIN modules  */
/* 07.12.17     VCO_462    HB    FIAT 330 interfaces: parallel branch                  */
/************************************************************************/




#line 1 "C:\\baseline\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_projectDefs.h"
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
 *  This file is designed to contain all RLS projects in order to define compiler
 * switches for the RELEASE configuration. The purpose is to have the project -
 * feature relation stored in one header file and thus available for all compilers
 * and third party tools.
 *
 * %PCMS_HEADER_SUBSTITUTION_START:%
 * <table border="0" cellspacing="0" cellpadding="0">
 * <tr> <td> Source:   </td> <td> %PM: template.h %                  </td></tr>
 * <tr> <td> Revision: </td> <td> %PR: 1.8 %                  </td></tr>
 * <tr> <td> Status:   </td> <td> %PS: UNDER_REVIEW %                  </td></tr>
 * <tr> <td> Author:   </td> <td> R.Fichtner, DUS-E-RLS  </td></tr>
 * <tr> <td> Date:     </td> <td> %PUDT: 20-FEB-2013 15:20:57 %                </td></tr>
 * </table>
 * %PCMS_HEADER_SUBSTITUTION_END:%
 * \n
 * <table border="0" cellspacing="0" cellpadding="0">
 * <tr> <td> COMPONENT: </td> <td> XXXX                            </td></tr>
 * <tr> <td> SCOPE:     </td> <td> <Public/Private/Component>      </td></tr>
 * <tr> <td> TARGET:    </td> <td> <All/Freescale S12X/S12XE/...>  </td></tr>
 * </table>
 */
/*----------------------------------------------------------------------------*/
/* Date      VDR_Number   Author   Description                                */
/*----------------------------------------------------------------------------*/
/*09.19.17   VCO_451    NB    All:Add spare LIN IDs in the EEPROM             */
/*07.12.17   VCO_462    HB    FIAT 330: parallel branch                       */
/******************************************************************************/


#line 285 "C:\\baseline\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_projectDefs.h"

#line 34 "C:\\BASELINE\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SWDEV\\01_SRCCODE\\APPLICATION\\DIAGNOSTICS\\G5_diagnose.h"
//#include "G5_E2ProjectConfig.h"








extern unsigned int rw_DiagnoseStepResponseAnswer_g;


extern  volatile Flag uF_LIN_Diagnosis_mg;

#line 54 "C:\\BASELINE\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SWDEV\\01_SRCCODE\\APPLICATION\\DIAGNOSTICS\\G5_diagnose.h"



/* PRQA S 0759 1*//*<< 0759:union needed to reduce RAM usage >>*/
extern  volatile Flag uF_LIN_DiagReq2_mg;







extern byte rb_ResponseToSend_g;
extern  byte rb_Diagnosticstate_g;








extern void Diagnose_ReadDataByLocalID(void);



extern void Diagnose_ReadDataByIdentifier(void);








extern void Diagnose_WriteMemoryByAddress(void);

















extern void Diagnose_ReadByIdentifier(void);
extern void Diagnose_AssignIdentifier(void);




void Diagnose_AssignNAD(void);



#line 125 "C:\\BASELINE\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SWDEV\\01_SRCCODE\\APPLICATION\\DIAGNOSTICS\\G5_diagnose.h"


extern void Diagnose_Write_CodierinfoB8(void);


#line 137 "C:\\BASELINE\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SWDEV\\01_SRCCODE\\APPLICATION\\DIAGNOSTICS\\G5_diagnose.h"

extern void diagnose_ASICstepResponse(void);

extern void Diagnose_ClearCodingResult(void);

extern byte Diagnosis_BCDtoASCII(byte rb_Input_l);








/*************************************************************************
**                   Defines for Diagnosis                              **
*************************************************************************/














#line 174 "C:\\BASELINE\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SWDEV\\01_SRCCODE\\APPLICATION\\DIAGNOSTICS\\G5_diagnose.h"






///////////////////////////////////////////////
/* PRQA S 0841 7 */ /* <<for easier declaration of variable -> proven mechanism>> */
#line 107 "C:\\baseline\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_RLS_LIN_GEELY2DOT0.c"
#line 1 "C:\\BASELINE\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SWDEV\\01_SRCCODE\\APPLICATION\\EEPROM\\G5_E2Handler.h"


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












//#define USE_STANDBY_MODE
/****************************************************************************/
/** Global Variables **/
/****************************************************************************/

/* PRQA S 0759 1*//*<< 0759:union needed to reduce RAM usage >>*/
extern  volatile Flag uF_Main_Flags_g;

#line 59 "C:\\BASELINE\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SWDEV\\01_SRCCODE\\APPLICATION\\EEPROM\\G5_E2Handler.h"

extern byte rb_RS_LS_Error1_g;
extern byte rb_RS_LS_Error2_g;
extern byte rb_RainS_Error1_g;
extern byte rb_LightS_Error1_g;

extern unsigned int rw_EEPROM_Address_to_Write_g;
extern byte rb_I2C_EEPROM_bytesToWrite_g;
extern byte rab_EEPROM_Bytes_toWrite_g[5];


extern __callt void main_EEPROM_Loader(void);
/****************************************************************************/
//              Global Contants and Makros
/****************************************************************************/


/*************************************************************************
Declaration of exported functions
**************************************************************************/
/* PRQA S 0841 1 */ /* <<for easier declaration of variable -> proven mechanism>> */




#line 108 "C:\\baseline\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_RLS_LIN_GEELY2DOT0.c"
#line 1 "C:\\BASELINE\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SWDEV\\01_SRCCODE\\APPLICATION\\EEPROM\\G5_flashe2.h"

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
/*                                            */
/*      Source:         FlashE2.h       */
/*      Revision:             */
/*      Author:         <author name>                                         */
/*      UserID:         SBA294       */
/*      Date                  */
/*                                                                            */
/*                                              */
/******************************************************************************/
/*   MODULE: FlashE2                                                          */
/*   FILE:   FlashE2.h                                                        */
/******************************************************************************/
/* History                                                                    */
/*----------------------------------------------------------------------------*/
/* Date      VDR_Number  NAME Description                                       */
/*----------------------------------------------------------------------------*/
/* 05.05.10  VDR_505       function declaration */
/* 12.08.14  VDR_797     NB   Watchdog reset due to High CPU load while erasing the EEPROM cluster */
/* 24.03.2016 VCO_316   NB   No_init RAM values shall be used to connect  bootload mode instead of EEPROM */
/**

 * \brief H File for the Flash Emulated EEPROM Handling "FlashE2 Modul"
 *
 *  Contains all puplic elements like functions etc. for the application.
 *

*/








/** brief Defines EXTERN as extern if h-File is included by another module 
than FlashE2.c to refer variables as external*/
#line 1 "C:\\BASELINE\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SWDEV\\01_SRCCODE\\APPLICATION\\SELFPROGLIBRARY\\pfdl.h"
/*================================================================================================*/
/* Project      = Flash Data Library T04 (PicoFDL)                                                */
/* Module       = pfdl.h                                                                          */
/* Device:      = RL78                                                                            */
/* Version      = V1.04                                                                           */
/* Date         = 13.04.2012                                                                      */
/*================================================================================================*/
/*                                  COPYRIGHT                                                     */
/*================================================================================================*/
/* Copyright (c) 2011-2012 by Renesas Electronics Europe GmbH, a company of the Renesas           */
/* Electronics Corporation. All rights reserved.                                                  */
/*================================================================================================*/
/*                                                                                                */
/* Purpose:     contains the C language API definition of the Flash Data Library.                 */
/*                                                                                                */
/*================================================================================================*/
/*                                                                                                */
/* Warranty Disclaimer                                                                            */
/*                                                                                                */
/* Because the Product(s) is licensed free of charge, there is no warranty of any kind whatsoever */
/* and expressly disclaimed and excluded by Renesas, either expressed or implied, including but   */
/* not limited to those for non-infringement of intellectual property, merchantability and/or     */
/* fitness for the particular purpose.                                                            */
/* Renesas shall not have any obligation to maintain, service or provide bug fixes for the        */
/* supplied Product(s) and/or the Application.                                                    */
/*                                                                                                */
/* Each User is solely responsible for determining the appropriateness of using the Product(s)    */
/* and assumes all risks associated with its exercise of rights under this Agreement, including,  */
/* but not limited to the risks and costs of program errors, compliance with applicable laws,     */
/* damage to or loss of data, programs or equipment, and unavailability or interruption of        */
/* operations.                                                                                    */
/*                                                                                                */
/* Limitation of Liability                                                                        */
/*                                                                                                */
/* In no event shall Renesas be liable to the User for any incidental, consequential, indirect,   */
/* or punitive damage (including but not limited to lost profits) regardless of whether such      */
/* liability is based on breach of contract, tort, strict liability, breach of warranties,        */
/* failure of essential purpose or otherwise and even if advised of the possibility of such       */
/* damages. Renesas shall not be liable for any services or products provided by third party      */
/* vendors, developers or consultants identified or referred to the User by Renesas in            */
/* connection with the Product(s) and/or the Application.                                         */
/*                                                                                                */
/*================================================================================================*/





/*================================================================================================*/
/* include files list                                                                             */
/*================================================================================================*/
#line 1 "C:\\BASELINE\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SWDEV\\01_SRCCODE\\APPLICATION\\SELFPROGLIBRARY\\pfdl_types.h"
/*================================================================================================*/
/* Project      = Flash Data Library T04 (PicoFDL)                                                */
/* Module       = pfdl_types.h                                                                    */
/* Device:      = RL78                                                                            */
/* Version      = V1.04                                                                           */
/* Date         = 13.04.2012                                                                      */
/*================================================================================================*/
/*                                  COPYRIGHT                                                     */
/*================================================================================================*/
/* Copyright (c) 2011-2012 by Renesas Electronics Europe GmbH, a company of the Renesas           */
/* Electronics Corporation. All rights reserved.                                                  */
/*================================================================================================*/
/*                                                                                                */
/* Purpose:     contains the type definitias used by the library.                                 */
/*                                                                                                */
/*================================================================================================*/
/*                                                                                                */
/* Warranty Disclaimer                                                                            */
/*                                                                                                */
/* Because the Product(s) is licensed free of charge, there is no warranty of any kind whatsoever */
/* and expressly disclaimed and excluded by Renesas, either expressed or implied, including but   */
/* not limited to those for non-infringement of intellectual property, merchantability and/or     */
/* fitness for the particular purpose.                                                            */
/* Renesas shall not have any obligation to maintain, service or provide bug fixes for the        */
/* supplied Product(s) and/or the Application.                                                    */
/*                                                                                                */
/* Each User is solely responsible for determining the appropriateness of using the Product(s)    */
/* and assumes all risks associated with its exercise of rights under this Agreement, including,  */
/* but not limited to the risks and costs of program errors, compliance with applicable laws,     */
/* damage to or loss of data, programs or equipment, and unavailability or interruption of        */
/* operations.                                                                                    */
/*                                                                                                */
/* Limitation of Liability                                                                        */
/*                                                                                                */
/* In no event shall Renesas be liable to the User for any incidental, consequential, indirect,   */
/* or punitive damage (including but not limited to lost profits) regardless of whether such      */
/* liability is based on breach of contract, tort, strict liability, breach of warranties,        */
/* failure of essential purpose or otherwise and even if advised of the possibility of such       */
/* damages. Renesas shall not be liable for any services or products provided by third party      */
/* vendors, developers or consultants identified or referred to the User by Renesas in            */
/* connection with the Product(s) and/or the Application.                                         */
/*                                                                                                */
/*================================================================================================*/






/*==============================================================================================*/
/* unsigned type definitions                                                                    */
/*==============================================================================================*/
typedef unsigned char                       pfdl_u08;
typedef unsigned int                        pfdl_u16;
typedef unsigned long int                   pfdl_u32;


/*==============================================================================================*/
/* global constant definitions                                                                  */
/*==============================================================================================*/



/*==============================================================================================*/
/* global type definitions                                                                      */
/*==============================================================================================*/


/* PFDL command code set */
typedef   enum  {                                               /* ---------------------------------------------- */
                  PFDL_CMD_READ_BYTES          = (0x00),        /* 0x00, reads data from flash memory             */
                  PFDL_CMD_IVERIFY_BYTES       = (0x06),        /* 0x06, verifies data if flash content is stable */
                  PFDL_CMD_BLANKCHECK_BYTES    = (0x08),        /* 0x08, checks if flash content is blank         */
                  PFDL_CMD_WRITE_BYTES         = (0x04),        /* 0x04, writes data into flash memory            */
                  PFDL_CMD_ERASE_BLOCK         = (0x03)         /* 0x03, erases one flash block                   */
                } pfdl_command_t;                               /* ---------------------------------------------- */


/* PFDL error code set */
typedef   enum  {
                  /* operation related status               */  /* ---------------------------------------------- */
                  PFDL_IDLE                     = (0x30),       /* 0x30, PFDL ready to receive requests           */
                  PFDL_OK                       = (0x00),       /* 0x00, command finished without problems        */
                  PFDL_BUSY                     = (0xFF),       /* 0xFF, command is being processed               */
                  /* flash related status                   */  /* ---------------------------------------------- */
                  PFDL_ERR_PROTECTION           = (0x10),       /* 0x10, protection error (access right conflict) */
                  PFDL_ERR_ERASE                = (0x1A),       /* 0x1A, erase error                              */
                  PFDL_ERR_MARGIN               = (0x1B),       /* 0x1B, blankcheck or verify margin violated     */
                  PFDL_ERR_WRITE                = (0x1C),       /* 0x1C, write error                              */
                  PFDL_ERR_PARAMETER            = (0x05)        /* 0x05, parameter error                          */
                } pfdl_status_t;                                /* ---------------------------------------------- */


/* PFDL request type (base type for any PFDL access) */
typedef struct {                                                /* ---------------------------------------------- */
                  pfdl_u16              index_u16;              /* 2, W, virt. byte/block index inside PFDL-pool  */
                  __near pfdl_u08*      data_pu08;              /* 2, W, pointer to the 1'st byte of data buffer  */
                  pfdl_u16              bytecount_u16;          /* 2, W, number of bytes to be transfered         */
                  pfdl_command_t        command_enu;            /* 1, W, command code                             */
                } pfdl_request_t;                               /*------------------------------------------------*/
                                                                /* 7 bytes in total                               */
                                                                /*------------------------------------------------*/

/* PFDL descriptor type */
typedef struct {                                                /* ---------------------------------------------- */
                  pfdl_u08      fx_MHz_u08;                     /* 1, system frequency expressed in MHz           */
                  pfdl_u08      wide_voltage_mode_u08;          /* 1, programming voltage mode ( full/wide )      */
                } pfdl_descriptor_t;                            /*------------------------------------------------*/
                                                                /* 2 bytes in total                               */


#line 53 "C:\\BASELINE\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SWDEV\\01_SRCCODE\\APPLICATION\\SELFPROGLIBRARY\\pfdl.h"


/* ---------------------------------------------------------------------------------------------------------------*/
/*  Block type:   standard function                                                                               */
/* ---------------------------------------------------------------------------------------------------------------*/
/*  Purpose:      Unconditional activation of the Data Flash Library.                                             */
/*                Based on the descriptor data:                                                                   */
/*                - the flash firmware will be initialized for data-flash access only                             */
/*                - the internal timing and low-voltage capability will be configured according to the descriptor */
/*                After successful initialization the data flash clock is ON and the PFDL is ready to use.        */
/*                                                                                                                */
/*                CAUTION:                                                                                        */
/*                Due to the code size minimization no plausibility checks are done by the PicoFDL.               */
/*                Neither configuration, frequency range nor data flash size will be checked by the library.      */
/*                                                                                                                */
/*  Input:        address of the PFDL descriptor variable  (RAM only)                                             */
/*  Output:       -                                                                                               */
/*  Return:       PFDL status                                                                                     */
/* ---------------------------------------------------------------------------------------------------------------*/
extern __far_func  pfdl_status_t  PFDL_Open(__near pfdl_descriptor_t __near* descriptor_pstr);




/* ---------------------------------------------------------------------------------------------------------------*/
/*  Block type:   standard function                                                                               */
/* ---------------------------------------------------------------------------------------------------------------*/
/*  Purpose:      Disable data flash access unconditionally.                                                      */
/*                If any command is just executed, PFDL_Close will stop it immediately.                           */
/*                After return the data flash clock is switched OFF.                                              */
/*  Input:        -                                                                                               */
/*  Output:       -                                                                                               */
/*  Return:       -                                                                                               */
/* ---------------------------------------------------------------------------------------------------------------*/
extern __far_func  void  PFDL_Close(void);



/* ---------------------------------------------------------------------------------------------------------------*/
/*  Block type:   standard function                                                                               */
/* ---------------------------------------------------------------------------------------------------------------*/
/*  Purpose:      Initiating execution of the PFDL request related to the data flash.                             */
/*                The corresponding request variable has to be parametrized before.                               */
/*                                                                                                                */
/*                request_pstr->index_u16        :   byte-index or block-number within PFDL-pool                  */
/*                request_pstr->data_pu08        :   start address of the RAM data that should be read/written    */
/*                request_pstr->bytecount_u16    :   number of bytes has to be read/written                       */
/*                request_pstr->command_enu      :   command code                                                 */
/*                                                                                                                */
/*                CAUTION:                                                                                        */
/*                Due to the code size minimization no plausibility checks are done by the PFDL.                  */
/*                                                                                                                */
/*  Input:        &request_pstr - pointer to PFDL request variable                                                */
/*  Output:       -                                                                                               */
/*  Return:       status of the request                                                                           */
/* ---------------------------------------------------------------------------------------------------------------*/
extern __far_func  pfdl_status_t  PFDL_Execute(__near pfdl_request_t __near* request_pstr);



/* ---------------------------------------------------------------------------------------------------------------*/
/*  Block type:   standard function                                                                               */
/* ---------------------------------------------------------------------------------------------------------------*/
/*  Purpose:      Continuation of command execution and status update of requests being under execution.          */
/*  Input:        -                                                                                               */
/*  Output:       -                                                                                               */
/*  Return:       PFDL status =                                                                                   */
/*                  PFDL_IDLE        -  no request is processed by PFDL, PFDL is ready to receive new requests    */
/*                  PFDL_OK          -  processed request/command finished without problems                       */
/*                  PFDL_BUSY        -  request/command is still being processed                                  */
/*                  other            -  flash or firmware related errors                                          */
/* ---------------------------------------------------------------------------------------------------------------*/
extern __far_func  pfdl_status_t  PFDL_Handler(void);



/* ---------------------------------------------------------------------------------------------------------------*/
/*  Block type:   standard function                                                                               */
/* ---------------------------------------------------------------------------------------------------------------*/
/*  Purpose:      Returns the start address of the library version string                                         */
/*                                                                                                                */
/*  Input:        -                                                                                               */
/*  Output:       -                                                                                               */
/*  Return:       starting address of the zero-terminated version string                                          */
/* ---------------------------------------------------------------------------------------------------------------*/
extern __far_func  pfdl_u08 __far*  PFDL_GetVersionString(void);



#line 52 "C:\\BASELINE\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SWDEV\\01_SRCCODE\\APPLICATION\\EEPROM\\G5_flashe2.h"
/******************************************************************************/
/*                 Definition of exported symbolic constants                   */
/******************************************************************************/
/*  Comment:  EEPROM Error Code (rb_EEPROMErrFlag_g)              */
/*  Range  :  0 to 255                                                           */
/** \brief Defines error code for rb_EEPROMErrFlag_g 'no error' */

/** \brief Defines error code for rb_EEPROMErrFlag_g 'single error' */

/** \brief Defines error code for rb_EEPROMErrFlag_g 'double error' */

/** \brief Defines error code for rb_EEPROMErrFlag_g 'can not read error' */

/** \brief Defines error code for reading of 0xff (empty cell) */


/*  Comment:  EEPROM Error Code (rb_EEPROM_Status_g)              */
/*  Range  :  0 to 255                                                           */
/** \brief EEPROM is not loaded   */

/** \brief EEPROM is now initializing    */

/** \brief EEPROM is like a virgin (nothing is in the eeprom)   */

/** \brief EEPROM is initialised and in autoinitialising data set is noting */

/** \brief EEPROM is initialised and the data are not default*/

/** \brief EEPROM is initialised and the data are not default*/


/** \brief number of areas in EEPROM (AD,PD, RD)*/


/** \brief defines for range selection */



/** \brief mask for range selection */





/** \brief defines for area index */




/** \brief Number of EEPROM Clusters */


/******************************************************************************/
/*                Definition of exported function like macros                 */
/******************************************************************************/

/******************************************************************************/
/*          Definition of exported types (typdefs, enums, struct, union)      */
/******************************************************************************/

/******************************************************************************/
/*                    Declaration of exported variables                       */
/******************************************************************************/
/**

 
 * \ingroup external
 * \brief exported variable Error flag, will be written in DTC if set
 * See alsoe defines for rb_EEPROMErrFlag_g */

extern pfdl_descriptor_t pfdl_descriptor;
extern pfdl_request_t pfdl_request;

extern   byte rb_EEPROMErrFlag_g;

/**
 * \ingroup external
 * this variable allows to read the used number of bytes in the emulated eeprom
 * do not write in this variable from extern*/
extern  unsigned int rw_EEPROMPointer_g[(byte)3];
/** \brief Status of the cluster*/
extern byte rb_ClusterStatus_mg[(byte)4];
/**
 * \ingroup external
 * \brief Control flags to show internal states or problems */
/* PRQA S 0759 1*//*<< 0759:union needed to reduce RAM usage >>*/
extern  volatile Flag uF_E2Flag_g;

#line 146 "C:\\BASELINE\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SWDEV\\01_SRCCODE\\APPLICATION\\EEPROM\\G5_flashe2.h"

/** \brief Are for which the cluster should be changed*/
extern byte rb_ChangeCluster_mg;






/**
 * \ingroup external
 * \brief Error flags to show emulated EEPROM problems */
/* PRQA S 0759 1*//*<< 0759:union needed to reduce RAM usage >>*/
extern   volatile Flag uF_E2ConfigErrorFlags_g;
#line 168 "C:\\BASELINE\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SWDEV\\01_SRCCODE\\APPLICATION\\EEPROM\\G5_flashe2.h"

/**
 * \ingroup external
 * \brief shows status of write process  */
extern  byte rb_EEPROM_WriteStatus_g;
/**
 * \ingroup external
 * \brief shows status of erase process  */
extern  byte rb_EraseStatus_g;

/**
 * \ingroup external
 * \brief shows status of eeprom process  */
extern  byte rb_EEPROM_Status_g;

extern  byte rb_EEPROM_EraseOngoing_g;  /* VDR_797 */

/******************************************************************************/
/*                  Declaration of exported constant data                     */
/******************************************************************************/

/******************************************************************************/
/*               Declaration of exported function prototypes                  */
/******************************************************************************/
extern void EEProm_LoadInit(void);
extern byte EEProm_InitCluster(void);
extern void EEProm_Load(void);
extern void EEProm_PreInitDefault(void);
extern void EEProm_LoadDefault(void);
extern byte EEProm_WriteCodedByte(byte ByteToWrite, unsigned int AddressToWrite);
extern void EEProm_ChangeClusterStart(void);
extern void EEProm_ChangeCluster(void);
extern void EEProm_ClearCluster(void);
extern void Enter_BootLoad_Mode(void);
extern void ClearValidateString(void);
/******************************************************************************/
/* PRQA S 0841 7 */ /* <<for easier declaration of variable -> proven mechanism>> */




/******************************************************************************/
/*                                            */
/* END  Source:         FlashE2.h       */
/*                                              */
/******************************************************************************/

#line 109 "C:\\baseline\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_RLS_LIN_GEELY2DOT0.c"
#line 1 "C:\\BASELINE\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SWDEV\\01_SRCCODE\\APPLICATION\\RAIN\\G5_rs_task.h"


/******************************************************************************
*******************************************************************************
**
** Datei:      G5_rs_Task.h
**
**
** Bearbeiter: Frank Selbmann
**             Abt. WRS
**
** Datum:      04.03.98
** geaendert:  11.05.01
**
** Inhalt:     Definitionen fuer folgende Funktionen
**
**             wwrainse_Init()        Initialisierungsroutine fuer Regensensor
**
**             wwrainse_Task10ms()    10ms Task fuer Regensensorauswertung
**
**             wwrainse_Task40ms()    40ms Task fuer Regensensorauswertung
**
**
**
*******************************************************************************
*******************************************************************************
******************************************************************************/

// Variablen nur fuer Regensensor Auswertung
//==========================================

extern const unsigned char cab_RS_SchwelleMin[9];

extern const unsigned char cab_RS_Dec_IntSP_Offs[9];
extern const unsigned char cab_RS_Empf_Fakt_St2[9];

extern unsigned char  rub_Inc_Int_Sp_Count;			  //Counter fuer Intervallspeicher Ladezeit
extern unsigned char  rub_Dec_Int_Sp_Count;   		  //Counter fuer Intervallspeicher Entladezeit

extern unsigned char  rub_Dec_Int_Sp;				  //Intervallspeicher Entladezeit
extern unsigned short int ruw_Schwelle_min;       //min Wert fuer die Schwelle der
//Ueberwischausblendung.
//Wert ist Abhaengig von der
//eingestellten Empfindlichkeit.

extern unsigned char  rub_Inc_Ovr_Sp_Count;			  //Counter fuer Overridespeicher Ladezeit
extern unsigned char  rub_Dec_Ovr_Sp_Count;			  //Counter fuer Overridespeicher Entladezeit

extern unsigned char  rub_Dec_SigSp_Ans_Count;     //Counter fuer Signalentladung waehrend der
//Ansammlungszeit
extern unsigned char  rub_Empf_Faktor_St2;          //Faktor, mit dem die einzelnen Signale gewichtet
//werden. Variable ist Abhaengig von der Poti-Ste
extern unsigned char  rub_PotiStage_alt;		   //vorhergehende Potistellung

extern unsigned char  rub_LengthCounter_alt;
extern unsigned char  rub_PulseCounter_alt;
extern unsigned char rub_Sig_Counter;           //Zaehler fuer die Anzahl der Signale pro Wischzyklus
extern unsigned char rub_Sig_Anzahl_Alt;
extern unsigned char rub_Tropf_Count;           //Tropfenzaehler
extern unsigned char rub_WischZykl_Count;       //Zaehler fuer Wischungen
//wird bei jedem Nulldurchgang decrementiert
extern unsigned char rub_Delay_Ausbl;           //Wartezeit fuer Uberwischausblendung





extern unsigned char rub_Sig_Pause;

extern unsigned char rub_SigLength;             //Laenge der Signale, waehrend des letzten Tasks
extern unsigned char rub_SigPulse;			    //Anzahl der Signale, waehrend des letzten Tasks

extern unsigned char rub_Delay_Ausbl_count;     //Zaehler fuer Wartezeit Ueberwischausblendung
extern unsigned char rub_WiperMotorTime_alt;    //Dauer eines Wischzyklus
extern unsigned short int rub_Dia_Count_dynamic;	        //Diagnose-Zaehler fuer "Signal-Uebertraege"

extern unsigned char rub_Sig_Ok_Count;          //Zaehler fuer gueltige Signale erhoehen;
extern unsigned char rub_RSIntermDelayInit_internal;      //interne Regensensosr Delay Time
extern unsigned char rb_AfterWashingTimer_mg;             //Zeit nach letztem Waschen
extern unsigned char rb_DoneAfterwipe_g;
extern unsigned char rbi_LowSpeed_Out_g;
extern unsigned char rub_Trockwisch_memory;
extern unsigned short int  ruw_PulseLength_g;
extern unsigned short int ruw_meanPulseLenght_g; /* used to reduce empf-factor for long signals*/
extern unsigned short int ruw_presentPulseLenght_g; /*used to calculate ruw_meanPulseLenght_g*/
extern unsigned short int ruw_SigLength_DownWipe_g;
extern unsigned short int ruw_SigLength_UpWipe_g;



/* Function prototype */

extern void THold(void);

extern void Sig_min(void);
extern void Mem_40(void);
extern void Betrieb(void);
extern void IntBer(void);
extern void Empf_Einstellung(void);
extern void Mot_EinAus(void);
extern void Mot_AusEin(void);








#line 110 "C:\\baseline\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_RLS_LIN_GEELY2DOT0.c"

#line 1 "C:\\BASELINE\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SWDEV\\01_SRCCODE\\APPLICATION\\LIGHT\\G5_IRlight.h"



/*************************************************************************

  Company : Valeo Wiper Systems 

  Project : RLT Sensor, RDN Sensor

  Component : IRLight.h

  Documentation reference : Lightsensor Software Stategy

  Overview of the component : variable and prottype declaration
                              for IRLight.c
   Evolution of the component : see PVCS Version control system

                Initials   date   modification

*****************************************************************************/
/**************************************************************************/
/* History                                                                    */
/*----------------------------------------------------------------------------*/
/* Date      VDR_Number  NAME Description                                       */
/*----------------------------------------------------------------------------*/
/* 10.03.11  VDR_638   AL   MISRA OPTIMISATION with corrections in Source code */
/* 21.02.11  VCO_094   AL   Tunnel detection improvement*/
/* 22.11.10  VCO_087   AL   Delay for nightmode adapted*/
/* 04.Aug.10 VCO_69    PCG  moved light mode constants: cb_NIGHT_mg, cb_DAY_mg, 
                            cb_DARKSTART_mg and cb_TUNNEL_mg from irlight.c */
/* 30.Apr10  VDR_473   FS   QA-C*/
/* 24.02.10  VCO_031   AL   new adjustable values over EEPROM*/
/* 22.01.10  VCO_27    AL   rainlight switch of time independend from potistage*/
/* 08.06.09  VDR_330        Shift parameters into header, EEPROM-RainLight defines to be set here*/
/* 07.Apr-08 VDR_175        RLS_ALL ReInit LS-Algorithm with define _REINIT_LSALGO_*/
/* 26.06.08  VCO_08   AL    Add twilight Values for FAW Twilight detection*/
/* 20.08.08  VDR_24   FS    Implement Gen 3.0 Light Thresholds */
/****************************************************************************/
/** Definition for Mono-Inclusion **/
/****************************************************************************/

#line 1 "C:\\baseline\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_projectDefs.h"
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
 *  This file is designed to contain all RLS projects in order to define compiler
 * switches for the RELEASE configuration. The purpose is to have the project -
 * feature relation stored in one header file and thus available for all compilers
 * and third party tools.
 *
 * %PCMS_HEADER_SUBSTITUTION_START:%
 * <table border="0" cellspacing="0" cellpadding="0">
 * <tr> <td> Source:   </td> <td> %PM: template.h %                  </td></tr>
 * <tr> <td> Revision: </td> <td> %PR: 1.8 %                  </td></tr>
 * <tr> <td> Status:   </td> <td> %PS: UNDER_REVIEW %                  </td></tr>
 * <tr> <td> Author:   </td> <td> R.Fichtner, DUS-E-RLS  </td></tr>
 * <tr> <td> Date:     </td> <td> %PUDT: 20-FEB-2013 15:20:57 %                </td></tr>
 * </table>
 * %PCMS_HEADER_SUBSTITUTION_END:%
 * \n
 * <table border="0" cellspacing="0" cellpadding="0">
 * <tr> <td> COMPONENT: </td> <td> XXXX                            </td></tr>
 * <tr> <td> SCOPE:     </td> <td> <Public/Private/Component>      </td></tr>
 * <tr> <td> TARGET:    </td> <td> <All/Freescale S12X/S12XE/...>  </td></tr>
 * </table>
 */
/*----------------------------------------------------------------------------*/
/* Date      VDR_Number   Author   Description                                */
/*----------------------------------------------------------------------------*/
/*09.19.17   VCO_451    NB    All:Add spare LIN IDs in the EEPROM             */
/*07.12.17   VCO_462    HB    FIAT 330: parallel branch                       */
/******************************************************************************/


#line 285 "C:\\baseline\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_projectDefs.h"

#line 43 "C:\\BASELINE\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SWDEV\\01_SRCCODE\\APPLICATION\\LIGHT\\G5_IRlight.h"
#line 49 "C:\\BASELINE\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SWDEV\\01_SRCCODE\\APPLICATION\\LIGHT\\G5_IRlight.h"








/****************************************************************************/
/** Global Variables **/
/****************************************************************************/





extern  unsigned int rw_FW_Day_Threshold_g;
extern  unsigned int rw_Amb_Day_Threshold_g;
extern  unsigned int rw_Amb_DayHigh_Threshold_g;
extern  unsigned int rw_FW_DayHigh_Threshold_g;
extern  unsigned int rw_dayCounter_mg;
extern  unsigned int rw_nightCounter_mg;
/* brief Debounce counter for the InTunneldistance */
extern unsigned int rw_InTunnelDistance_mg;
extern  byte rb_speed_in_kmh_g;                // car speed  in Km/h
extern  byte rb_WipeCounter_g; 
extern  byte rb_IR_Day_Threshold_g;
extern  byte rb_Amb_Night_Threshold_g;
extern  byte rb_Amb_NightLow_Threshold_g;
extern  byte rb_IR_DayHigh_Threshold_g;
extern  byte rb_FW_Night_Threshold_g;
extern  byte rb_IR_Night_Threshold_g;
extern  byte rb_FW_NightLow_Threshold_g;
extern  byte rb_IR_NightLow_Threshold_g;
extern  byte rb_LSPotiStage_g;                           // Sensitivity for Day Night
extern  byte rb_FW_tunnel_threshold_mg;        // only for debugging as global!! //Tunnel Thrshold for forward wide
extern  byte rb_FW_Tunnel_high_TempThresh_l;     // only for debugging as global!!
extern  byte rb_IrLightTunnelThreshDyn_g;

#line 105 "C:\\BASELINE\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SWDEV\\01_SRCCODE\\APPLICATION\\LIGHT\\G5_IRlight.h"
/****************************************************************************/
// Global Contants for Light Modes 
/****************************************************************************/




/* other defines for this are in irlight.c*/

/****************************************************************************/
// Contants for Highway (lighton) detection
/****************************************************************************/





















/*VDR_330 To use cb_WIPETHRESHOLD_mg in Flash EEPROM defines needed to be global defines
 * --> Formerly located in c-file, now located in header*/





/****************************************************************************/
/** structure for 16bit value with 8bit access !!!!!!!Compilerdendent! **/
/****************************************************************************/

extern  unsigned int rw_AmbLightMul32MeanSlow_g; /*slow mean value of Amblight_high*/



extern  unsigned int rw_AmbLightMul32MeanFast_g; /* slow mean value of IRlight_high*/


extern  unsigned int rw_FwLightMul64MeanFast_g; /* fast mean value forwardlight_high*/


extern  unsigned int rw_FwLightMul64MeanSlow_g; /* slow mean value forwardlight_high*/


// calculation from high to rb_FwLightMeanSlow_g



/****************************************************************************/
/** Global Flags **/
/****************************************************************************/
/* PRQA S 0759 1*//*<< 0759:union needed to reduce RAM usage >>*/
extern  Flag uF_Check_lightsensor_g;                 // do not change bit assignment used for error memory



/* PRQA S 0759 1*//*<< 0759:union needed to reduce RAM usage >>*/
extern  Flag uF_modi_lightsens_g;
  // Bits of uF_modi_lightsens_g                 // do not change bit assignment



/*Bit 3 not used*/
/*#define rbi_modi_lightsens_beforeTunnel_g   uF_modi_lightsens_g.Bit.B3*/

/*Bit 5 not used*/
/*#define rbi_modi_lightsens_forest_g     uF_modi_lightsens_g.Bit.B5*/

/* PRQA S 0759 1*//*<< 0759:union needed to reduce RAM usage >>*/
extern  Flag uF_modi_lightsens_inv_g;
// Bits of uF_modi_lightsens_inv_g                 // do not change bit assignment
#line 195 "C:\\BASELINE\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SWDEV\\01_SRCCODE\\APPLICATION\\LIGHT\\G5_IRlight.h"

/* PRQA S 0759 1*//*<< 0759:union needed to reduce RAM usage >>*/
extern  Flag uF_LightInternalStatus_g;

#line 205 "C:\\BASELINE\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SWDEV\\01_SRCCODE\\APPLICATION\\LIGHT\\G5_IRlight.h"





/* PRQA S 0759 1*//*<< 0759:union needed to reduce RAM usage >>*/
extern  Flag uf_LightAlgoReInit_g;






/****************************************************************************/
// Variables for bus communication
/****************************************************************************/

/** Global Constants **/

/*************************************************************************
                Declaration of exported functions
**************************************************************************/
extern void light_init(void);
extern void light_circulating_air_calc(void);
extern void lightScheduler(void);
extern unsigned int getNightCounter(void);
extern unsigned int getDayCounter(void);
extern unsigned int getRegulation48OffCounter(void);
extern byte getRegulation48OnCounter(void);
extern unsigned int getVeryBrightInTunnelDistance(void);
extern unsigned int getBrightInTunnelDistance(void);


/* PRQA S 0841 7 */ /* <<for easier declaration of variable -> proven mechanism>> */
#line 112 "C:\\baseline\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_RLS_LIN_GEELY2DOT0.c"
#line 1 "C:\\BASELINE\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SWDEV\\01_SRCCODE\\APPLICATION\\LIGHT\\G5_DippedBeam_sr.h"


/*************************************************************************

Company : Valeo Schalter und Sensoren GmbH

Project : G5 RLxS Sensor

Component : G5_DippedBeam_sr.h

Documentation reference :   Light Sensor Strategy
Overview of the component : Generates the control Signals for the
car's dipped beam headlamp. Safety relevant (sr) application logic is included
here only.


Evolution of the component : since generation 5

*************************************************************************/
/******************************************************************************/
/* History                                                                    */
/*----------------------------------------------------------------------------*/
/* Date      VDR_Number Name     Description                                       */
/*-DD.MM.YY -----------------------------------------------------------------------*/
/* 25.09.13  -          RFI     initial version*/





extern byte get_rb_LightVetoCounter_g(void);
extern void light_VetoForLightOff(void);
extern void light_evaluation(void);

#line 113 "C:\\baseline\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_RLS_LIN_GEELY2DOT0.c"
#line 1 "C:\\BASELINE\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SWDEV\\01_SRCCODE\\APPLICATION\\PERIPHERALS\\G5_ASIC_Control.h"
/*************************************************************************

Company : Valeo Switches and Detection Systems

Project : RLT Sensor Generation 5 (16 bit Micro Controller)

Component : ASIC_Control.h

*************************************************************************/

/*! \file G5_ASIC_CONTROL.h
 *   This Module contains data and function declarations for Global usage sankar.
 *   It is intended that other components will use them.
 *   Documentation reference : ASIC_Specification
 */ 




/* History                                                                       */
/*-------------------------------------------------------------------------------*/
/* Date      VDR_Number  Name    Description                                     */
/*-------------------------------------------------------------------------------*/
/*07.11.13   RLS_VCO_128 MPI     initial version (split non-safety from safety)  */
/*18.03.15   RLS_VDR_856 MPI     Min period to run the gain adjustment measurements is restricted to 10sec*/

/* PRQA S 750,759 EOF *//*<< 0750:union needed to reduce RAM usage >>*/
/* PRQA S 841 EOF *//*<< 841:use of #undef needed  >>*/







/****************************************************************************/
/** Global Variables **/
/****************************************************************************/
/*if the rain functionality is enabled*/
//#ifndef _NO_RAIN_

/*! Threshold for window comparator (1LSB = (1/255)*5V))*/


/*! Standby mode detection threshold*/

/*VDR_856 Min period to run the gain adjustment measurements is restricted to 10sec*/
/*! Threshold counter for no rain to start a WS measurement*/



/*! Gain adjustment for ASIC*/
extern byte rb_ASICGainSetup_g;
extern byte rb_Start_STBY_Meas_g;

/*! Debug information to evaluate the reason to close the window in standby mode*/
extern byte rb_CloseTypeStandby_g;
extern unsigned int rw_Stby10msTimer_g;

/*! Voltage of rain sensor signal one Task before*/
extern  byte rb_RS_SigVoltage_alt_g;
extern byte rb_RainMeas_cnt_g;

/* Rain intensity Signal voltage: VCO_423 */ 





//#endif /*_NO_RAIN_*/
extern  Flag uF_ASIC_ControlFlags_2_g;


/*! Delay for diagnostic pulse*/
extern unsigned int rw_DiagRequestCounter_g;
extern unsigned int rw_INTV10bit_min_g;
extern unsigned int rw_INTV10bit_max_g;
extern unsigned int rw_REGV_min_g;
extern unsigned int rw_REGV_max_g;
extern unsigned int rw_LIN_INTV10bit_min_g;
extern unsigned int rw_LIN_INTV10bit_max_g;
/*! TimoutCounter for standby mode*/
extern unsigned int rw_StandbyTimeOutCnt_g;
/*! Time without rain; 1 increment/sec*/
extern unsigned int rw_NoRainPresentCnt_g;
extern unsigned int rw_WasRainingCounter_g;


extern byte rb_DiagRain_HighTime_g;
extern unsigned int rw_DiagRain_LowTime_g;

extern volatile unsigned char rub_real_LengthCounter;
extern volatile unsigned char rub_real_PulseCounter;
extern volatile unsigned char rub_LengthCounter;   //Counter of Lowtime for Rainsensor Signals freerunning


/*if the rain functionality is enabled*/


extern __callt void ASIC_Control_meas_Intout(void); /*measures Intout and window comparator function*/
extern void ASIC_Control_RS_Meas(void);
extern void ASIC_Control_MeasureStandbyMode(void);
extern void ASIC_Control_CalcRSGain(void);
extern byte ASIC_Control_STBCheckRain(void);



#line 114 "C:\\baseline\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_RLS_LIN_GEELY2DOT0.c"
#line 1 "C:\\BASELINE\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SWDEV\\01_SRCCODE\\APPLICATION\\PERIPHERALS\\G5_ASIC_Control_sr.h"


/*************************************************************************

Company : Valeo Schalter und Sensoren

Project : RLT Sensor Generation 5 (16 bit Micro Controller)

Component : ASIC_Control_sr.h

Documentation reference : ASIC_Specification
---------------------------------------------------------------------------
Overview of the component : This module contains data and function declarations for global usage.
It is intended that other components will use them. The suffix _sr means "safety relevance".
---------------------------------------------------------------------------

*************************************************************************/
/* History                                                                    */
/*----------------------------------------------------------------------------*/
/* Date      VDR_Number  Name    Description                                  */
/*----------------------------------------------------------------------------*/
/*07.10.13   VCO_128 RFI     item creation                                */
/*07.11.13   VCO_128 MPI     defs, macros used globally                   */
/*09.02.15   VCO_220 MPI     VIrefLo/Hi monitoring*/
/*03.03.15   VCO_227 NB      Implement RAM Guard function */
/*16.03.15   VDR_855 MP      Fix of the findings from the review of ASIC_Control_sr*/
/*01.04.15   VDR_866 MP      Remove of rainsens.c for no-rain-variants*/

/* PRQA S 750,759 EOF *//*<< 0750:union needed to reduce RAM usage >>*/
/* PRQA S 841 EOF *//*<< 841:use of #undef needed  >>*/
/* PRQA S 2201,2215,2217,715 EOF *//*<< Indentation and line length  >>*/
/* PRQA S 857 EOF *//*<< Macro exceeds 1024 number  >>*/








typedef struct {
  const byte addr;  /*!< Address of the ASIC register*/  
  byte val;         /*!< Value of the ASIC register*/
  const byte accs;  /*!< Access type: b00 - Read2/Write2 cmd possible; b01 - no Read2/Write2 cmds; b10 - only Read cmds*/
} ASIC_Reg_t;

typedef struct {
  unsigned int ad;
  unsigned int avg;
  unsigned int adinc;
  unsigned int avginc;
} ASIC_ALSxADval_t;

typedef struct {
  unsigned int ad;
  unsigned int avg;
} ASIC_ALI_Meas_t;

typedef struct {
  unsigned int MIN;
  unsigned int MAX;
} ASIC_ALI_CalibAD_Limits_t;


extern unsigned char rub_Dia_Count_dyna_Stop;          /* VDR_132 erlaubt kein reset und zahlen des DiaCount bei < 150*/
extern unsigned short int rub_Dia_Count;		        //Diagnose-Zaehler fuer "Signal-Uebertraege"

extern byte rb_newAsicSTAT_g;
extern byte rb_firstReadComm_g;

/*! Offset for the calc of RS gain*/
extern byte rb_GainOffset_g;

/*coutners to measure the duration of the loop closed and number of rain measurements during loop closed*/

#line 87 "C:\\BASELINE\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SWDEV\\01_SRCCODE\\APPLICATION\\PERIPHERALS\\G5_ASIC_Control_sr.h"


extern byte rb_ASICResetCnt_g;
/*if the rain functionality is enabled*/



extern byte rb_RainMeas_cnt_total_g;
extern byte rb_RainMeas_cnt_min_g;
extern byte rb_RainMeas_cnt_max_g;
extern byte rb_LClosed_dur_total_g;
extern byte rb_LClosed_dur_min_g;
extern byte rb_LClosed_dur_max_g;

extern ASIC_Reg_t ras_ASIC_CtrReg_g[((byte)28)];









extern byte rb_ASIC_ALSx_ShortDetected_cnt_g;
extern byte rb_ASIC_ALSx_ShortDetected_Max_cnt_g;
extern byte rb_ASIC_ALSx_ShortDetected_Error_g;

extern Flag uF_ASIC_ControlFlags_g;
extern Flag uF_GainAdjustFlags_g;
/*! Flags for detected errors in ASIC Logamp*/
extern  Flag uF_ASIC_Error_Flags_g;
/*VCO_220 VIrefLo/Hi monitoring*/
extern  Flag uF_ASIC_Error_Flags1_g;
extern  Flag uF_ASIC_Ctrl_Error_Flags_g;


/*! CDIV256 period measured*/
extern unsigned int rw_CDIV256_period_g;
/*CDIV256 period measured; OVF flag*/
extern byte rb_CDIV256_OVF_g;
extern byte rb_ASIC_ID_g[3];

/*! 16bit Value for Solar-Light on driver side*/
extern  unsigned int rw_Solar_light16bit_1_g;
/*! 16bit Value for Solar-Light on passenger side*/
extern  unsigned int rw_Solar_light16bit_2_g;

extern  byte rb_FwLight_g;       // brightness from the front with wide spot
extern  byte rb_FwLightDiv4_g;  // brightness from the front with wide spot up to 40klx
extern byte rb_IrLightDiv8_g;


/*! ASIC instant and average AD results for voltage measurements like: temp, DAC output, V Iref Lo/Hi, VDDD, VDDA, rain sensor amplifier output*/
extern ASIC_ALI_Meas_t ras_ASIC_MUX_MeasAD_g[9];

extern  Flag uF_ASIC_Calc_Flags_g;




/*! Time to measure for rain if rain is detected in standby mode*/



/*! Sign of value for delogarithm*/

/*! Flag to monitore that the light value is minimum one time measured*/

/*! Flag that the freq. measurement is done one time*/


/*if the rain functionality is enabled*/

/*! AD value for INTV register*/










/*! Flag to control the ASIC modulator*/

/*! Flag to monitor it the light values are initialised*/

/*! Flag to monitor it the solar values are initialised*/

/*! Flag to show if in Standby mode the LIN was active*/

/*! Flag to bring the Sensor into standby mode*/

/*! Bit to make workaround after INREC measurment use 8bit command to restart modulator*/

/*! Bit to request a LOW CSB from the SPI*/



/*! Bit for rain present*/

/*! Bit for reaching once the vehicle speed 10km/h*/


/*if the rain functionality is enabled*/















/*if the rain functionality is disabled*/



/*!  AD value for REGV HB register*/



/*!  Error with VinALS1 out of specification*/
/*#define rbi_LS_Error_VinALS1_g              uF_ASIC_Error_Flags_g.Bit.B0*/
/*!  Error with VinALS2 out of specification*/

/*!  Error with VinALS5 out of specification*/

/*!  Error with VinALS6 out of specification*/
/*#define rbi_LS_Error_VinALS6_g              uF_ASIC_Error_Flags_g.Bit.B2*/
/*!  Error with Vinrec out of specification*/

/*!  Error with Vref out of specification*/

/*!  Error with ras_ASIC_ALI_CalibAD_g[] out of specification*/

/*!  Error when LEDx voltages are different then expected in LStop*/

/*!  Error when LEDx voltages are different then expected in LClosed*/

/*!  Timeout Error for the init of the ASIC*/

/* ASIC frequency out of range - not trimmed*/
#line 244 "C:\\BASELINE\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SWDEV\\01_SRCCODE\\APPLICATION\\PERIPHERALS\\G5_ASIC_Control_sr.h"
/*variables to store how is the ASIC frequency measured from the nominal, when not trimmed*/



/*VCO_220 VIrefLo/Hi monitoring*/










/*indexes for the diag AD voltages*/
#line 269 "C:\\BASELINE\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SWDEV\\01_SRCCODE\\APPLICATION\\PERIPHERALS\\G5_ASIC_Control_sr.h"

#line 280 "C:\\BASELINE\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SWDEV\\01_SRCCODE\\APPLICATION\\PERIPHERALS\\G5_ASIC_Control_sr.h"
/*VDR_839 SM250: Error counter not incrementing properly for calibration values*/
/*#define IDX_CAL_ILO_ICALLO_GHI_INC_AD                  10*/

//#define ASIC_CHD_MODE_CMD(a)  (0xC0|(a<<1))
/* possible mode selection for ASIC*/
#line 293 "C:\\BASELINE\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SWDEV\\01_SRCCODE\\APPLICATION\\PERIPHERALS\\G5_ASIC_Control_sr.h"



/*indexes for the ALSx AD voltages*/


/*#define IDX_ALS3_AD        2*/
/*#define IDX_ALS4_AD        3*/





#line 318 "C:\\BASELINE\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SWDEV\\01_SRCCODE\\APPLICATION\\PERIPHERALS\\G5_ASIC_Control_sr.h"

/*indexes for the ASIC registers*/








#line 341 "C:\\BASELINE\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SWDEV\\01_SRCCODE\\APPLICATION\\PERIPHERALS\\G5_ASIC_Control_sr.h"

















/*!  Macro to read AD Result*/

/*!  Macro to read AD Result*/

/*!  Macro to read AD Result*/

/*!  Macro to read AD Result*/

/*!  Macro to read AD Result*/

/*!  Macro to read AD Result*/

/*!  Macro to read AD Result*/

/*!  Macro to read AD Result*/

/*!  Macro to read AD Result*/





/*!  State for ASIC Control Mode*/

/*!  State for ASIC Control Mode*/

/*!  State for ASIC Control Mode*/

/*! State for ASIC Control Mode*/

/*!  State for ASIC Control Mode*/




/*#define ASIC_ALS3_READY_FLG (byte)(1<<2)
#define ASIC_ALS4_READY_FLG (byte)(1<<3)*/









/*!  AD value for TRIM register*/







/*! Start measurement of the ASIC Osc Frequency*/


/*! Number of step response pulses per diag request */


/*! Wait flag to enable coupling measurement*/
//#define rbi_Coupling_measurement_enabled_g uF_ASIC_ControlFlags_2_g.Bit.B0
/*! Wait flag to enable coupling measurement*/

/*! Wait flag to enable linearisation of measured signal*/


/*! Wait Error with loop comes not to normal point*/




// Defines for Standby Mode:
/*! Timeout if waiting for SPI*/

/*! Wait for standby time */

/*! Wait macro to wait in Standby till the SPI is ready*/
  /* PRQA S 3412 3 *//*<< required for readability  >>*/




/*! State for ASIC Control Mode*/

/*! upper boarder to allow standby measurment*/

/*! lower boarder to allow standby measurment*/

/*! upper boarder to allow standby measurment*/

/*! Lower boarder to allow standby measurment*/

/*! Threshold for standby detection*/

/*! Set the DIAG bit of STATL register*/

/*! Clear the DIAG bit of STATL register*/

/*! Threshold for the error-code (0x55) counter (error code added to cksum, when an error occured on ASIC)*/

/*! Error threshold for incorrect VDDx values*/


/*! Error Threshold for incorrect light values*/

/*! Threshold for detection of short circuit on ALSx or REC inputs ~1.5sec*/

/*! Threshold for Timeout for the init of the ASIC*/



  
  
/*! Timeout for the init of the ASIC*/
extern byte rb_ASIC_initTimeout_g;

/*! VCO_220 VIrefLo/Hi monitoring*/
/*! Definition for V_Iref_Lo/Hi limits*/
extern byte rb_VIref_ErrCnt_g;

/*! IR_LightMod on  value*/ /*VDR_365***********************/
extern  unsigned int rw_IR_light16bit_Mod_On_g;

/*! New INTV measurement was read out through SPI*/
extern byte rb_newRSconvRcv_g;
extern byte rb_LOpenIntegrationDone_g;

/*! Counter to delay the fastloop switch off*/
extern unsigned int rw_Loop1DelayCount_mg; /*VDR_365 correct name of variable*/
/*! Measurements of WS coupling*/
extern  unsigned int rw_INTV_STBY_1st_meas_g;
extern  unsigned int rw_INTV_STBY_2nd_meas_g;
extern  unsigned int  rw_TimeOutCounter_s;
/*! Store a value for every step response answer */
extern  unsigned int rw_StepResponseRes_g[2];    /* VDR_590 */
/*! Old value of length counter*/
extern  unsigned int rb_LastLengthCounter_s;
/*! Rain signal sum used for standby*/
extern  unsigned int rw_LengthSum_s;

/*! value for optical coupling measurement*/
extern byte rb_deltaINTV_g;
extern byte rb_IR_DeltaModON_g;
/*! Old value of ASIC loop in used in Standby function*/
extern byte rb_STB_LoopIn_ASIC_old_g;
extern byte rab_IntegrationTimePointer_mg;  /*VCO_028 reduce sample time if not stable*/
/*! TimoutCounter for standby mode*/
extern byte rb_StandbyTimeOutSecCnt_g;
/*! Difference to old loop voltage*/
extern byte rb_STB_LoopIn_ASIC_difference_g;
/*! Error when the checksum for read commands contains additional 0x55 (depending on errors in ASIC STAT registers)*/
extern byte rb_ASIC_SPI_ErrorFlag_g;
extern byte rb_ASIC_SPI_ErrorCodeCnt_g;

/*! Error counter for V_LEDx in Loop Closed*/
extern byte rb_LEDx_LClosed_error_cnt_g;

/*! Current & Previous Mode of the ASIC*/
extern byte rb_CurMode_g;
extern byte rb_PrevMode_g;
extern byte rb_STATH_Reg_g;
extern byte rb_STATL_Reg_g;
extern byte rb_LIN_STATH_Reg_g;
extern byte rb_NextSPI_Request_g;
extern byte rb_NextMUXCfg_g;
extern byte rb_CrtMUXCfg_g;
extern byte rb_newADconvRcv_g;
/*! Number of bytes to send with SPI to ASIC*/
extern  byte rb_SPI_Data_to_send_g;
/*! Write Buffer for SPI-Signals*/
extern byte rab_SPI_ASICWriteBuffer_mg[16];
/*! Control/Status byte for the funtion ASIC_Control_init()*/
extern  byte rb_ASIC_ControlMode_g;
extern byte rb_StaticNoValidAD_cnt_g;
extern byte rb_FreqNotTrimmedCounter_g;
extern byte rb_ASICReg_NoValidVals_cnt_g;
extern byte rb_ASIC_ALSx_Ready_g;
extern byte rb_ASIC_ALSx_INC_Ready_g;
extern unsigned int rw_REGV_OSAT_cnt_g;

/*! Loop Voltage of sensor for */
extern  byte rb_LoopVoltage_ASIC_g;
/*! ASIC loop in used in Standby function*/
extern byte rb_STB_LoopIn_ASIC_g;

/*************************************************************************
Declaration of exported functions
**************************************************************************/

extern __callt void ASIC_Control_dot5msTask(void); // 0.5ms routine to measure light values

extern void ASIC_Control_init_Caller(void);  /*VDR_436*/
extern unsigned int get_rw_Amb_light16bit_g(void);
extern unsigned int get_rw_FW_light16bit_g(void);

/*VCO_477 Blake_Used_For HUD*/
extern unsigned long get_rl_HUD_light32bit_g(void);


extern unsigned int get_rw_IR_light16bit_g(void);
extern unsigned int get_rw_Amb_INC_light16bit_g(void);
extern unsigned int get_rw_Amb_INC_light16bit_thrs_g(void);
extern unsigned int get_rw_FW_INC_light16bit_g(void);
extern unsigned int get_rw_FW_INC_light16bit_thrs_g(void);
extern unsigned int get_rw_IR_INC_light16bit_g(void);
extern unsigned int get_rw_IR_INC_light16bit_thrs_g(void);

extern unsigned int get_rw_ALS1_ASIC_g(void);
extern unsigned int get_rw_ALS2_ASIC_g(void);
extern unsigned int get_rw_ALS2_INC_ASIC_g(void);
/*ALS3, ALS4 are not connected*/
/*
EXTERN word get_rw_ALS3_ASIC_g(void);
EXTERN word get_rw_ALS4_ASIC_g(void);
EXTERN word get_rw_ALS4_INC_ASIC_g(void);
*/
extern unsigned int get_rw_ALS5_ASIC_g(void);
extern unsigned int get_rw_ALS5_INC_ASIC_g(void);
extern unsigned int get_rw_ALS6_ASIC_g(void);
extern unsigned int get_rw_INREC_ASIC_g(void);
extern unsigned int get_rw_INREC_INC_ASIC_g(void);
extern byte get_rb_LightSignalErrorCnt_g(void);
extern byte get_rb_MaxLightSignalErrorCnt_g(void);
extern byte get_rb_ASICReg_NoValidVals_cnt_g(void);
extern byte get_rb_Vref_LightSignalErrorCnt_g(void);
extern byte get_rb_VDD_LightSignalErrorCnt_g(void);
extern void set_rb_VDD_LightSignalErrorCnt_g(byte a);
extern void ASIC_Control_ASIC_ErrFlags_Check(void);
extern void set_rb_Asic_measureMode_mg(byte a);
extern byte get_rb_Asic_measureMode_mg(void);
extern void set_rb_Vref_LightSignalErrorCnt_g(byte Vref_LightSignalErrorCnt);
extern void set_rb_LightSignalErrorCnt_g(byte temp_LightSignalErrorCnt);
extern byte get_rb_LEDx_LStop_error_cnt_g(void);
extern void set_rb_LEDx_LStop_error_cnt_g(byte a);
extern void ASIC_Control_ChangeModeCmd(const byte next_mode);
extern void ASIC_Control_AsicStatus(void);


extern unsigned int get_rw_VILO_IHI_GLO_ASIC_g(void);
extern unsigned int get_rw_VIHI_ILO_GLO_ASIC_g(void);
extern unsigned int get_rw_VILO_ICALLO_GHI_ASIC_g(void);
extern unsigned int get_rw_VIHI_ICALHI_GHI_ASIC_g(void);
extern unsigned int get_rw_VICALLO_ILO_GHI_ASIC_g(void);
extern unsigned int get_rw_VICALHI_IHI_GHI_ASIC_g(void);
extern unsigned int get_rw_VILO_IHI_GLO_INC_ASIC_g(void);
extern unsigned int get_rw_VIHI_ILO_GLO_INC_ASIC_g(void);
extern unsigned int get_rw_VIHI_ICALHI_GHI_INC_ASIC_g(void);
extern unsigned int get_rw_VICALHI_IHI_GHI_INC_ASIC_g(void);
extern void set_ASIC_ALSxADval_Init(void);



/* PRQA S 3458 2 *//*<< required for readability  >>*/








#line 115 "C:\\baseline\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_RLS_LIN_GEELY2DOT0.c"
#line 1 "C:\\BASELINE\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SWDEV\\01_SRCCODE\\APPLICATION\\PERIPHERALS\\G5_spi_sr.h"


/*************************************************************************

Company : Valeo Wiper System

Project : RLT Sensor, RDN Sensor

Component : G5_SPI_SR.h

Documentation reference : ASIC specification E.140.17A
Overview of the component : interface to the RS ASIC

Evolution of the component : see PVCS Version control system
*************************************************************************/
/* Initials   date   modification*/

/*03.03.15   VCO_227    NB     Implement RAM Guard function */

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
* _b Source:     SPI.h
* _version       1.12
* _author        Andreas Laegler
* _author        SBA294
* _date          26-JUL-2007 08:08:38
* _todo          Still open points here
* <!--  -->

*/
/* PRQA S 2217 EOF */ /* << 2011 03 03, Code would be not readable >> */
/* PRQA S 750,759 EOF *//*<< 0750:union needed to reduce RAM usage >>*/
/*************************************************************************
**                   Common and module include-file                     **
**************************************************************************/












/*************************************************************************
**                   Declaration of global variables                   **
*************************************************************************/
/** \brief varible shows the actual state of no communication counter*/
extern unsigned int rw_SPINoCommCounter_g;
/** \brief varible shows the overall number of communication errors*/
extern byte rb_StaticNoCommunicationCounter_g;

/*start measurement command*/










/** \brief flags used in SPI communication*/
extern  volatile Flag uF_SPI_flags_g;
/** \brief flags monitors if SPI is active*/

/** \brief flags monitors if SPI is active and AD-conversion is not completed*/

/** \brief flags monitors that standby mode is integrating*/



/** \brief debug information for SPI Communication problems*/
extern byte rb_SPI_Active_ProblemCounter_g;

/** Function Prototypes **/
extern void spi_init(void);
extern __callt void SPI_WriteBlock(byte *rb_FirstbyteToWrite_l,byte rb_lenghtOfBlock);
//#define SPI_Write_Byte(a)  SPI_WriteBlock(&a,1)
extern __callt void SPI_Write_Byte(byte rb_byteToWrite_l);
extern void  SPI_int(void);
extern void set_rb_ASIC_SPI_ErrorFlag_g(byte a);
/* PRQA S 0841 1 */ /* <<for easier declaration of variable -> proven mechanism>> */


#line 116 "C:\\baseline\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_RLS_LIN_GEELY2DOT0.c"
#line 1 "C:\\BASELINE\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SWDEV\\01_SRCCODE\\APPLICATION\\OS\\G5_utilities.h"




extern byte wiperSpeed7to2(unsigned int currentSpeed0to2In,unsigned int speed0to7In, byte hysteresisEdges);

#line 117 "C:\\baseline\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_RLS_LIN_GEELY2DOT0.c"
#line 1 "C:\\baseline\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_AsicFramesLin.h"




extern void CopyRLSDataAsic(void);
extern void ApplTableInitAsic(void);


#line 118 "C:\\baseline\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_RLS_LIN_GEELY2DOT0.c"




/*VDR_362 Carry Over Standard Code*/
/*************************************************************************
**                   Declaration of local module variables              **
*************************************************************************/












#line 144 "C:\\baseline\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_RLS_LIN_GEELY2DOT0.c"


#line 154 "C:\\baseline\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_RLS_LIN_GEELY2DOT0.c"
//#define cb_HUD_MEASURING_RANGE_1    0x40
//#define cb_HUD_MEASURING_RANGE_2    0x80









/* PRQA S 0759 1*//*<< 0759:union needed to reduce RAM usage >>*/
static volatile Flag uF_StalkInPos_Flags_g;

/******************************************************************************/
/*                      Definition of exported variables                      */
/******************************************************************************/


/*************************************************************************
**                   Declaration of local module Macros **
*************************************************************************/










static const byte cab_PotistageMapping_mg[8] = {4,5,6,7,3,2,1,0}; /*mapping for potistages!*/

/*************************************************************************
**                   Declaration of local module Functions              **
*************************************************************************/
static void CheckErrors(void);
void RainFunction(void);

void LightFunction(void);
void Humidity_Function(void);
void StandByMode(void);
void VoltageDetect(void);
void OutPutBrightnessValue(void);
static byte rb_Verglasun_offenDebounce_mg;

static byte rb_Verglasun_ClosedDebounce_mg;
static unsigned int rw_CommandCloseWindowTimout_mg;

static byte rb_KL15_mg;
static byte rb_AnyErrorCounterDebounce_mg;
static unsigned int rw_AfterRSWipeCounter_mg;                   // Time after last wipe from RS
static unsigned int rw_AfterRSWipeCounterAlt_mg;              //Time to the last wipe from RS
static unsigned int rw_AfterWWSWipeCounter_mg;                  // Time after last wipe from WWS
static  unsigned int rw_WipeCommandTimOut_mg;                    //timout for requested wipe
static  byte rb_IgnitionOndelay_mg = 0;
static  byte rb_Err_State_Light_Sens_mg =0;// light error
static  int  rb_OutsideTemp_mg  = 1;
static  byte rb_WipeWorkStatus_mg = 1;


/******************For HUD**********************/

static unsigned long HUDEverageValue[2] = {0,0};//,0,0,0,0,0};
static unsigned long rb_storeHUDValueEvery500ms[10]={0,0,0,0,0,0,0,0,0,0};
static unsigned long rb_storeFW_ValueEvery50ms[10]={0,0,0,0,0,0,0,0,0,0};
static unsigned long rb_storeAMB_ValueEvery50ms[10]={0,0,0,0,0,0,0,0,0,0};


void GetFiveTableValue_500ms(unsigned long rl_HUD_Brightness_100ms);
unsigned long CalcHUDMean_1000ms(void);
void orderHUDValue(int n);
void GetFiveTableValue_50ms(unsigned long Fw,unsigned long Amb);
unsigned long  AdjustOutHudValue(unsigned long rl_CurrentHud);
unsigned char GetUpdateTimeForLightStatus(void);

static unsigned long FW_Average_In_50ms = 0;
static unsigned long AMB_Average_In_50ms = 0;


static  unsigned long FW_Average_In_50ms_Old = 0;
static  unsigned long AMB_Average_In_50ms_Old = 0;

static  unsigned long RW_Amb_Fw_Result_End    = 0;
static  unsigned char rb_hud_data_update      = 0;
static  unsigned char RW_Update_Time_Count = 0;


/********************End***********************/

byte CRC8SAEJ1850(byte *u8_data,byte u8_len);//crc8saej1850 
byte GetHudCrcj1850(unsigned long hudSrc);
byte GetOutdBriStsCrcj1850(byte OutdBriSts);
void GetLightTransmission(byte trans_550nm,byte trans_880nm);
void Get_BCMVehType(byte CarType);
void Set_BCMLightOffset(byte offset);
void SendRLSSerNo(void);
void SendRLSMPartNo(void);
void SendRLSMPartNo10(void);
void OutPutHudValue(void);
void OutPutHudSendCount(void);
void TemperatureDetect(void);
void WipeWinterModeCheck(void);
byte IsByteOddParity(byte data);

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
void GetLeWWS(void)
{
  static unsigned int rw_IgnitionOffDelay_mg;
  static byte rb_IntervalOnOndelay_mg;
  static byte rb_AfterResetCounter_l;
  byte rb_Empfindlichkeit_LS_l;
  byte rb_BCM_LightSns;
  
 /***********************Add the Auto_Close_Window Function in Rain Condition*************************/   

     
  if (CemCem_Lin1Fr05_CEM_LIN1 . cemcem_lin1fr05_cem_lin1 . EnaOfflineMonitor_CEM_LIN1== 1)                        //Window Open
  {
    if (uF_VoltageStatus_g . Bit . B2 == 0)                                     
    {
      if (rb_Verglasun_offenDebounce_mg < 0xff)
      {
        rb_Verglasun_offenDebounce_mg ++;
      }
    }
    rb_Verglasun_ClosedDebounce_mg = 0;
  }
  else if(CemCem_Lin1Fr05_CEM_LIN1 . cemcem_lin1fr05_cem_lin1 . EnaOfflineMonitor_CEM_LIN1 == 0)
  {
    if (rb_Verglasun_ClosedDebounce_mg < 0xff)
    {
      rb_Verglasun_ClosedDebounce_mg ++;
    }
    rb_Verglasun_offenDebounce_mg = 0;
  }
  else
  {
  
  }


  
  if((uLinIndicationFlags . w[0]. b5 != 0))
  {
     {uLinIndicationFlags . w[0]. b5 = 0;};
     uF_SCIFlags_mg . Bit . B1 = 1;
     rb_OutsideTemp_mg =  CemCem_Lin1Fr02_CEM_LIN1 . cemcem_lin1fr02_cem_lin1 . AmbTForVisy_CEM_LIN1;
     WipeWinterModeCheck(); 
  }
    
  if((uLinIndicationFlags . w[0]. b4 != 0))
  {
       {uLinIndicationFlags . w[0]. b4 = 0;};
       uF_SCIFlags_mg . Bit . B1 = 1;
       
       {RlsmCem_Lin1Fr01_CEM_LIN1 . rlsmcem_lin1fr01_cem_lin1 . RainSnsrErrCalErrActv_CEM_LIN1 = 1;};     
       Get_BCMVehType(CemCem_Lin1Fr03_CEM_LIN1 . cemcem_lin1fr03_cem_lin1 . VehTyp_CEM_LIN1);
       GetLightTransmission(CemCem_Lin1Fr03_CEM_LIN1 . cemcem_lin1fr03_cem_lin1 . WindCorrnValFrnt_CEM_LIN1,CemCem_Lin1Fr03_CEM_LIN1 . cemcem_lin1fr03_cem_lin1 . WindCorrnValAmb_CEM_LIN1);
  }
  
  if((uLinIndicationFlags . w[0]. b3 != 0))
  {
     {uLinIndicationFlags . w[0]. b3 = 0;};
     uF_SCIFlags_mg . Bit . B1 = 1;
     rb_BCM_LightSns = CemCem_Lin1Fr04_CEM_LIN1 . cemcem_lin1fr04_cem_lin1 . RainSnsrLiThd_CEM_LIN1;
     Set_BCMLightOffset(rb_BCM_LightSns);
     
  }
  
  
 if( (uLinIndicationFlags . w[0]. b2 != 0))
 {
    {uLinIndicationFlags . w[0]. b2 = 0;};
    uF_SCIFlags_mg . Bit . B1 = 1;
  
 }
   
  if((uLinIndicationFlags . w[0]. b1 != 0))
  { 
    {uLinIndicationFlags . w[0]. b1 = 0;};
    uF_SCIFlags_mg . Bit . B1 = 1;
    uF_SCIFlags_mg . Bit . B6 = !CemCem_Lin1Fr06_CEM_LIN1 . cemcem_lin1fr06_cem_lin1 . WiprInWipgAr_CEM_LIN1;        // wiper position
    
    if (CemCem_Lin1Fr06_CEM_LIN1 . cemcem_lin1fr06_cem_lin1 . WshngCycActv_CEM_LIN1)                                 /* Washpump activ? 0x5:Front washing*/
    {
      RSStatus . Bit . B1 = 1;                                       /* set Washing activ bit */
    }
    else if (uF_StatusRainsensor_mg . Bit . B7 == 1)                                /* In Parkposition ? */
    {
      RSStatus . Bit . B1 = 0;                                      /* Clear Washing active bit */
    }
    else{}                                                              /*Do nothing, Dummy-else for Misra Check*/
  }
  
  if((uLinIndicationFlags . w[0]. b6 != 0))
  { 
    {uLinIndicationFlags . w[0]. b6 = 0;};
    rw_NoCommunicationCounter_g = 0;                                 // reset no communication counter
    uF_SCIFlags_mg . Bit . B1 = 1;                                     // set connected to Master  
    uF_Communication_mg . Bit . B1 = 1;    
    
    rb_speed_in_kmh_g  = CemCem_Lin1Fr01_CEM_LIN1 . cemcem_lin1fr01_cem_lin1 . VehSpdForWipg_CEM_LIN1;   
    if(CemCem_Lin1Fr01_CEM_LIN1 . cemcem_lin1fr01_cem_lin1 . VehSpdForWipg_CEM_LIN1 == 0xFF)
    {
      rb_speed_in_kmh_g = 75;                           /* set speed to (75 km/h)*/
    }
    else 
    {
    }
    if(rb_speed_in_kmh_g>=10)
    {
      uF_GainAdjustFlags_g . Bit . B1 = 1;
    }   
    rb_KL15_mg = (CemCem_Lin1Fr01_CEM_LIN1 . cemcem_lin1fr01_cem_lin1 . WipgPwrActvnSafeWipgPwrAcsyModSafe_CEM_LIN1==2);
   /* ignore ignition off if speed higher 4km/h*/
    if((rb_KL15_mg == 1)||(rb_speed_in_kmh_g > 4)) /*VCO_083*/
    {
      uF_VoltageStatus_g . Bit . B2 = 1;
      rw_StandbyTimeOutCnt_g = 0;
      rw_IgnitionOffDelay_mg = 0;
      if(rb_IgnitionOndelay_mg < 250)
      {
        rb_IgnitionOndelay_mg++;
      }
          
      if((((EEPROM_Struct_PD . EEPROMStructPD . EEKodierbyte0_g & 0x40)>0) == 0) &&(rb_AfterResetCounter_l> 10))
      {
        if(((CemCem_Lin1Fr01_CEM_LIN1 . cemcem_lin1fr01_cem_lin1 . RainSensActvn_CEM_LIN1 == 1)&&(CemCem_Lin1Fr01_CEM_LIN1 . cemcem_lin1fr01_cem_lin1 . WiprMotFrntLvrCmdSafeLvrInIntlPosn_CEM_LIN1==1))                         //automatic
            || (((EEPROM_Struct_PD . EEPROMStructPD . RSControlFlags & 0x40)>0) != 0))
        {
          uF_StatusRainsensor_mg . Bit . B0 = 1;                            /*Rainsensor always active!*/
        }
        else
        {
          uF_StatusRainsensor_mg . Bit . B0 = 0;                           /*Rainsensor off!*/
        }
      }
      else
      {
        uF_StatusRainsensor_mg . Bit . B0 = 0;                             //Rainsensor off!
      }
      
      if(CemCem_Lin1Fr01_CEM_LIN1 . cemcem_lin1fr01_cem_lin1 . WiprMotFrntLvrCmdSafeLvrInIntlPosn_CEM_LIN1 == 1)                            // copy automatic wiping mode
      {
        if(rb_IntervalOnOndelay_mg > 15)                               //debound 150ms when turn the auto wiper on
        {
          RSStatus . Bit . B7 = 1;
        }
        else
        {
          rb_IntervalOnOndelay_mg++;
        }
      }
      else
      {
        RSStatus . Bit . B7 = 0;
        rb_IntervalOnOndelay_mg = 0;
      }
    }
    else
    {          
      uF_VoltageStatus_g . Bit . B2 = 0;
      rw_AfterWWSWipeCounter_mg = 50000;                                //Direktbitdelay bei Kl15 Aus hochsetzen!
      rw_WipeCommandTimOut_mg = 0;
      rb_IgnitionOndelay_mg = 0;
      uF_StatusRainsensor_mg . Bit . B0 = 0;                                //Rainsensor off!
    }

    rb_LIN_SensitivityShift_g =  7;                                     //adaptation Variable for sensitivity factor
    rb_PotiStageFromBox_g = (CemCem_Lin1Fr01_CEM_LIN1 . cemcem_lin1fr01_cem_lin1 . WiprMotIntlCmd_CEM_LIN1 >= 7)?3:(CemCem_Lin1Fr01_CEM_LIN1 . cemcem_lin1fr01_cem_lin1 . WiprMotIntlCmd_CEM_LIN1);
      
    
  }  
  else                                                                  //keine neue Master Nachricht!
  {                                                                     // check if system is on -> to switch off 
    if((rw_NoCommunicationCounter_g > ((((EEPROM_Struct_AD . EEPROMStructAD . p_t_autobahn_delay_on_g>>5)&0x07)*100)+200)))                               /***4S***/
    {     
      if ((uF_SCIFlags_mg . Bit . B4 == 0)||( uF_ASIC_ControlFlags_g . Bit . B4 == 0))  /*VDR_526*/
      {
        if ( ((uF_VoltageStatus_g . Bit . B2== 0)) &&((rb_Verglasun_offenDebounce_mg > 100) &&
                                           (((EEPROM_Struct_PD . EEPROMStructPD . EEKodierbyte0_g & 0x04)>0) == 1)) && (uF_SCIFlags_mg . Bit . B4 == 0) )
        {
          uF_ASIC_ControlFlags_g . Bit . B4 = 1;                             // Set Request for Standby Mode
        }
        else
        {
          uF_ASIC_ControlFlags_g . Bit . B4 = 0;
        }       
        uF_SCIFlags_mg . Bit . B2 = 1;                                         // Was Connected to Master
      }
      else 
      {

        if ((CemCem_Lin1Fr05_CEM_LIN1 . cemcem_lin1fr05_cem_lin1 . EnaOfflineMonitor_CEM_LIN1== 0)||(rw_CommandCloseWindowTimout_mg > 6000))
        {
          uF_SCIFlags_mg . Bit . B2 = 1;                                       // no need of Standby mode 
          uF_ASIC_ControlFlags_g . Bit . B4 = 0;
          uF_SCIFlags_mg . Bit . B0 = 0;                                /*VDR_526*/
          uF_SCIFlags_mg . Bit . B4 = 0;                           /*VDR_526*/
          rb_WakeupCounter_mg = 0; 
        }
        else
        {
          if (rb_WakeupCounter_mg == 0)                             /*VDR_526*/
          { 
            uF_SCIFlags_mg . Bit . B0 = 1; 
          }
        }

      }
      uF_SCIFlags_mg . Bit . B1 = 0;                                  // clear connected to Master
    }
    else
    {
      uF_SCIFlags_mg . Bit . B0 = 0;                                    /*VDR_526*/
      rw_NoCommunicationCounter_g ++;
      uF_SCIFlags_mg . Bit . B2 = 0;                                          // Was Connected to Master
      if(rw_NoCommunicationCounter_g >= (((((EEPROM_Struct_AD . EEPROMStructAD . p_t_autobahn_delay_on_g>>5)&0x07)*100)+200) - 3) )
      {
                                                                        /*clear marker in the EEPROM to indicate there is a normal sleeep command*/
        rb_Release_IntervalMarker_Update_g = 0x00;                      //send sleep command to RS
        uF_StatusRainsensor2_mg . Bit . B3 = 1;                               //indicate if rb_Release_IntervalMarker_g sholud be updated in EEPROM
      }
    }
  }
  
  rb_Empfindlichkeit_LS_l = 3;
  if((cab_PotistageMapping_mg[((EEPROM_Struct_PD . EEPROMStructPD . EEKodierbyte0_g & 0x38)>>3)]+rb_Empfindlichkeit_LS_l)>3)
  {
    rb_LSPotiStage_g = (cab_PotistageMapping_mg[((EEPROM_Struct_PD . EEPROMStructPD . EEKodierbyte0_g & 0x38)>>3)]+rb_Empfindlichkeit_LS_l)-3;
    if(rb_LSPotiStage_g>7)
    {
      rb_LSPotiStage_g=7;
    }
  }
  else
  {
    rb_LSPotiStage_g = 0;
  }
  if (rb_AfterResetCounter_l<250)
  {
    rb_AfterResetCounter_l++;                                           /* counts calls of routine to delay activation of rainsensor*/
  }
  
  if(rw_IgnitionOffDelay_mg < 1000)                                     /* 10sec delay */
  {
    rw_IgnitionOffDelay_mg++;
  }
  else
  {
    rb_Release_IntervalMarker_Update_g |= 0xA0;
    uF_StatusRainsensor2_mg . Bit . B2 = 0;
  }

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
  static byte rb_parkpositioncounter_s;
  /*simulierte Wischzeit bei LSS aus*/
  static const byte cab_WiperMotorRunntime_mg[8] ={142,142,133,125,117,111,105,100};  
  
  if ((rb_WiperSpeed_g > 0)&&(uF_SCIFlags_mg . Bit . B6== 1))
  {    
    if (rw_WipeCommandTimOut_mg <= 400)
    {
      rw_WipeCommandTimOut_mg ++;                // reset Timout if wiper motor wants not wipe
    }
    else
    {
      rb_LimitMemomryNoWiperReaction_g = 1;
    }      
  }

  if(    ((CemCem_Lin1Fr01_CEM_LIN1 . cemcem_lin1fr01_cem_lin1 . WiprMotFrntLvrCmdSafeLvrInIntlPosn_CEM_LIN1 == 0)    //NO auto wiper
       && (uF_SCIFlags_mg . Bit . B6 == 1))
       ||(rw_WipeCommandTimOut_mg > 400))
  {
    if((rb_WiperSpeed_g > 0)||(uF_StatusRainsensor_mg . Bit . B7 == 0))
    {
      if(rb_parkpositioncounter_s>10)            // Parkpositioncounter groesser 10
      {
        uF_StatusRainsensor_mg . Bit . B7 = 0;              // delete bit for Parkposition
      }
      rb_parkpositioncounter_s++;                // increase Parkpositionscounter
    }
    
    if(rb_parkpositioncounter_s > (cab_WiperMotorRunntime_mg[rb_WiperSpeed_g]))
    {
      rw_WipeCommandTimOut_mg = 0;
      uF_StatusRainsensor_mg . Bit . B7 = 1;               
      rb_parkpositioncounter_s = 0;            
    }
  }
  else    
  {
    if((uF_SCIFlags_mg . Bit . B6 == 0)&&(rb_WiperSpeed_g > 0))
    {
      rbi_WiperStarted_g = 1;
    }
    
    if(uF_SCIFlags_mg . Bit . B6 == 1)            // In Parklagensignal ?
    {
      if(uF_StatusRainsensor_mg . Bit . B7 == 0)
      {
        rb_parkpositioncounter_s=0;              // Parkpositioncounter zuruecksetzen
      }
      else
      {
        if(rb_parkpositioncounter_s < 255)
        {
          rb_parkpositioncounter_s++;
        }
      }
      uF_StatusRainsensor_mg . Bit . B7 = 1;                 // Parkposition True
      if (rub_IntermDelayTime > 5)               // clear option for Wiper Started Flag!
      {
        rbi_WiperStarted_g = 0;
      }
    }
    else
    {
      rb_LimitMemomryNoWiperReaction_g = 0;
      rbi_WiperStarted_g = 0;
      rw_WipeCommandTimOut_mg = 0;               // reset Timout if wiper motor wants not wipe
      if(rb_parkpositioncounter_s>7)             // Parkpositioncounter groesser 8
      {
        rbi_WiperStarted_g = 0;
        uF_StatusRainsensor_mg . Bit . B7 = 0;              // loesche bit fuer Parkposition
      }
      else
      {
        rb_parkpositioncounter_s++;              // inkrementiere Parkpositionscounter
      }
    }
  }
  
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
  Check_StartupActiveErrors();
  
  if((uLinConfirmationFlags . w[0]. b10 != 0))
  {
    {uLinConfirmationFlags . w[0]. b10 = 0;} ;
    uF_SCIFlags_mg . Bit . B1 = 1; 
    
  }

  if((uLinConfirmationFlags . w[0]. b9 != 0))
  {
    {uLinConfirmationFlags . w[0]. b9 = 0;} ;
    uF_SCIFlags_mg . Bit . B1 = 1;
    OutPutHudSendCount();
  }
  
  if((uLinConfirmationFlags . w[0]. b8 != 0))
  {
    {uLinConfirmationFlags . w[0]. b8 = 0;} ;
    uF_SCIFlags_mg . Bit . B1 = 1; 
  }
  
  if((uLinConfirmationFlags . w[0]. b7 != 0))
  {
    {uLinConfirmationFlags . w[0]. b7 = 0;} ;
    uF_SCIFlags_mg . Bit . B1 = 1;
    SendRLSMPartNo();
  }
  
  if((uLinConfirmationFlags . w[0]. b6 != 0))
  {
    {uLinConfirmationFlags . w[0]. b6 = 0;} ;
    uF_SCIFlags_mg . Bit . B1 = 1; 
    SendRLSMPartNo10();
  }
  if((uLinConfirmationFlags . w[0]. b5 != 0))
  {
    {uLinConfirmationFlags . w[0]. b5 = 0;} ;
    uF_SCIFlags_mg . Bit . B1 = 1; 
    SendRLSSerNo();
  }
  
  if(0==uF_Main_Flags_g . Bit . B6)
  {

    if((0==(EEPROM_Struct_PD . EEPROMStructPD . RSControlFlags & 0x01)) && (0==((EEPROM_Struct_PD . EEPROMStructPD . EEKodierbyte0_g & 0x40)>0)))



    {
      /*version error*/
      (uF_Diagnose_pre_Flag . Bit . B3) = 1;
    }
    else
    {
      (uF_Diagnose_pre_Flag . Bit . B3) = 0;
    }
  }
  
  RainFunction();                              //Tunnel wiper,auto wiper,rain level, splash mode, rain sonser error
  CheckErrors();                               //Other error signals send in this function
  VoltageDetect();                             //Send high/low voltage error
  TemperatureDetect();                         //send temperate error
  LightFunction();                             //light request and the reason of light on                            

  StandByMode();                               //Auto close window

  

  OutPutBrightnessValue();                     //output FW IR SOLAR brightness


  

  Humidity_Function();                         //dew point & Screen temperature & sensor teamperature & relative Humidity


  CopyRLSDataAsic();


  rb_WDG_BusTaskCounter_g++;                   //increment test counter for bus
}


/*0x0：OFF "WipgSpd0Rpm";
0x1：Low speed "WipgSpd40Rpm";
0x2：wipe speed "WipgSpd43Rpm";
0x3：wipe speed"WipgSpd46Rpm";
0x4：wipe speed "WipgSpd50Rpm";
0x5：wipe speed "WipgSpd54Rpm";
0x6：wipe speed "WipgSpd57Rpm";
0x7：High speed "WipgSpd60Rpm";
0x8~0xE：currently not used*/

void RainFunction(void)
{
  static byte rb_OutOffParkCounter_mg;
  static byte rb_TunnelWipeTimeOut_mg;   
  unsigned int rw_tunnelWischVerzoegerung_l=(((unsigned int)(EEPROM_Struct_AD . EEPROMStructAD . TunWischVerzAktiv>>4))*100);
  unsigned int rw_tunnelWischAktivierung_l=(((unsigned int)(EEPROM_Struct_AD . EEPROMStructAD . TunWischVerzAktiv&0x0F))*100);
  static byte rb_tunnelWipeActive_g;
  byte newWiperSpeedLin = 0;
  
  if((rb_IgnitionOndelay_mg<50))
  {
    rw_rain_intensitiy_g = 0;
    rw_AfterRSWipeCounter_mg = 50000;
  }
  if(uF_SCIFlags_mg . Bit . B6 == 0)     
  {                                            //wiper is running 
    if (rb_OutOffParkCounter_mg > 18) 
    {
      rw_AfterWWSWipeCounter_mg = 0;
    }
    else
    {
      rb_OutOffParkCounter_mg ++;
    }
  }
  else
  {                                            //wiper in park position
    rb_OutOffParkCounter_mg = 0;
    if (rw_AfterWWSWipeCounter_mg < 50000)
    {
      rw_AfterWWSWipeCounter_mg++;
    }
  }
  
  if (rw_AfterRSWipeCounter_mg < 50000)        //Delay for Tunnel wipe function
  {
    rw_AfterRSWipeCounter_mg++;   
  }
  
  /*VCO_260 Tunnel wipe activation and delay according to Tunnel Verzoegerung and Aktivierung parameters*/
  /*activation of afterwipe at tunnel*/
  if((rw_AfterRSWipeCounterAlt_mg <= rw_tunnelWischVerzoegerung_l)
     &&(rb_speed_in_kmh_g > 29)
       &&(uF_modi_lightsens_g . Bit . B2 == 1)
         &&(rub_RSIntermDelayInit == 0xFF))
  {
    if ((uF_Communication_mg . Bit . B4 == 0) && (rw_AfterRSWipeCounter_mg < rw_tunnelWischAktivierung_l))
    {
      rb_tunnelWipeActive_g = 1;
    }
  }
  else
  {
    rb_tunnelWipeActive_g = 0;
  }

  /*trigger the afterwipe at tunnel*/
  if((rw_AfterRSWipeCounter_mg >= rw_AfterRSWipeCounterAlt_mg)
       &&(rb_tunnelWipeActive_g == 1)
         &&(rb_WiperSpeed_g == 0))
  {
    rb_TunnelWipeTimeOut_mg = 0;
    uF_Communication_mg . Bit . B3 = 1;
    rb_tunnelWipeActive_g = 0;
    rw_AfterRSWipeCounterAlt_mg = 50000;
    rw_AfterRSWipeCounter_mg = 50000;
	/**********Zhiyuan HU 20190313**************/
	if(CemCem_Lin1Fr06_CEM_LIN1 . cemcem_lin1fr06_cem_lin1 . WshngCycActv_CEM_LIN1 != 1)
	{
	  {RlsmCem_Lin1Fr01_CEM_LIN1 . rlsmcem_lin1fr01_cem_lin1 . AutWinWipgCmd_CEM_LIN1 = 1;};   // wiper request
	}
	else
	{
	  {RlsmCem_Lin1Fr01_CEM_LIN1 . rlsmcem_lin1fr01_cem_lin1 . AutWinWipgCmd_CEM_LIN1 = 0;};
	}
	/**********Zhiyuan HU 20190313**************/
  }
  else if(uF_Communication_mg . Bit . B3 == 1)
  {
    if((uF_StatusRainsensor_mg . Bit . B7 == 0)||(rb_TunnelWipeTimeOut_mg >= 50))
    {
      uF_Communication_mg . Bit . B3 = 0;
      rb_TunnelWipeTimeOut_mg = 0;
    }
    else
    {
      rb_TunnelWipeTimeOut_mg++;
    }
	/**********Zhiyuan HU 20190313**************/
	if(CemCem_Lin1Fr06_CEM_LIN1 . cemcem_lin1fr06_cem_lin1 . WshngCycActv_CEM_LIN1 != 1)
	{
	  {RlsmCem_Lin1Fr01_CEM_LIN1 . rlsmcem_lin1fr01_cem_lin1 . AutWinWipgCmd_CEM_LIN1 = 1;};   // wiper request
	}
	else
	{
	  {RlsmCem_Lin1Fr01_CEM_LIN1 . rlsmcem_lin1fr01_cem_lin1 . AutWinWipgCmd_CEM_LIN1 = 0;};
	}
	/**********Zhiyuan HU 20190313**************/
  }
  else
  {
    if(CemCem_Lin1Fr01_CEM_LIN1 . cemcem_lin1fr01_cem_lin1 . WiprMotFrntLvrCmdSafeLvrInIntlPosn_CEM_LIN1 == 1)
    {
      if((rb_WiperSpeed_g != 0) &&(rb_WipeWorkStatus_mg == 1))
      {
        if ((RSStatus . Bit . B5==0)&&(RSStatus . Bit . B6==0))
        {
           newWiperSpeedLin = 1; //interval         
        }
        else
        {
           newWiperSpeedLin = rb_WiperSpeed_g;        
        }  
      }
      else
      {
        newWiperSpeedLin = 0;
      } 
    }    
	/**********Zhiyuan HU 20190313**************/
	if(CemCem_Lin1Fr06_CEM_LIN1 . cemcem_lin1fr06_cem_lin1 . WshngCycActv_CEM_LIN1 != 1)
	{
	  {RlsmCem_Lin1Fr01_CEM_LIN1 . rlsmcem_lin1fr01_cem_lin1 . AutWinWipgCmd_CEM_LIN1 = newWiperSpeedLin;};   // wiper request
	}
	else
	{
	  {RlsmCem_Lin1Fr01_CEM_LIN1 . rlsmcem_lin1fr01_cem_lin1 . AutWinWipgCmd_CEM_LIN1 = 0;};
	}
	/**********Zhiyuan HU 20190313**************/

    {RlsmCem_Lin1Fr01_CEM_LIN1 . rlsmcem_lin1fr01_cem_lin1 . WipgAutFrntMod_CEM_LIN1 = 0;}; 
    
    if(rb_WiperSpeed_g >0)
    {
      if(rb_WiperSpeedAlt_g == 0)
      {
        rw_AfterRSWipeCounterAlt_mg = rw_AfterRSWipeCounter_mg;
      }
      rw_AfterRSWipeCounter_mg = 0;
    }     
  } 
  rb_WiperSpeedAlt_g = rb_WiperSpeed_g;
  uF_Communication_mg . Bit . B4 = uF_modi_lightsens_g . Bit . B2;  
     
}

void LightFunction(void)
{
  byte rb_AnyErrorCounterDebounce_l; 
  byte rb_TempLightOn_l;
  byte rb_OpModeState = 0;
  byte rb_crc_StsOutdBriSts = 0;
  
 /* PRQA S 3415, 4112 1 */ /* << Getter functions must not have side effects >>*/
  if ((((((( (rw_SPINoCommCounter_g>0)||(get_rb_LightVetoCounter_g()>0)|| (get_rb_LightSignalErrorCnt_g()>0)|| (rb_ASIC_SPI_ErrorCodeCnt_g>0)||(rb_StaticNoValidAD_cnt_g>0)|| (get_rb_VDD_LightSignalErrorCnt_g()>0)||(get_rb_LEDx_LStop_error_cnt_g()>0)|| (rb_ClockFreq_Error_cnt_g>0) || (rb_ASIC_ALSx_ShortDetected_cnt_g!=0) || (rb_ASIC_initTimeout_g > 0) || (rb_VIref_ErrCnt_g>0) )) > 0))||(rb_Err_State_Light_Sens_mg > 0))||(((uF_VoltageStatus_g . Bit . B0) == 1))
       || ((uF_VoltageStatus_g . Bit . B3) == 1)))
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
    
  rb_AnyErrorCounterDebounce_l = rb_AnyErrorCounterDebounce_mg; 
                                                                                                                           /**The conditions for lamp on**/
  if(rb_Err_State_Light_Sens_mg == 1)                                                                               //sensor in error
  {
     // SWRS3  95106 v3 Failure to detect ambient light data, or to provide a reliable status (Day or Night) after initialization, 
     // shall result in the sensor setting the value to 'Invalid'.
     rb_TempLightOn_l = 3;  
  }
  
  else if(((uF_modi_lightsens_g.AllBit & 0x2F)>0)||(uF_Main_Flags_g . Bit . B7 > 0)||((uF_LightInternalStatus_g . Bit . B6) !=0)) //darkness/darkstart/tunnel
  {
    rb_TempLightOn_l = 1;
  }
  /*VDR_129 use Sensitivity Treatment*/
  else if((((((EEPROM_Struct_PD . EEPROMStructPD . EEKodierbyte0_g & 0x01)>0)==1))&& ((uF_LightInternalStatus_g . Bit . B4) == 1))                                        //highway/rain
          ||(((uF_modi_lightsens_g . Bit . B4 == 1)&& (((EEPROM_Struct_PD . EEPROMStructPD . EEKodierbyte0_g & 0x02)>0) == 1))))
  {
    rb_TempLightOn_l = 1;
  }
  else
  { /* PRQA S 3415 1 */ /* << Swapping expressions not feasible for performance >>*/
    if ((rb_AnyErrorCounterDebounce_l ==0)&&(get_rb_LightVetoCounter_g()==0)) /*VCO_093 use Veto of Lightsensor*/
    {
      rb_TempLightOn_l = 2;
    }
    else
    {
      rb_TempLightOn_l = RlsmCem_Lin1Fr01_CEM_LIN1 . rlsmcem_lin1fr01_cem_lin1 . OutdBriSts_CEM_LIN1;                                                               /* stay in old light mode and do */
    }
  }
  
                                                                                                                         /**Send lamp on command**/
  if((uF_Main_Flags_g . Bit . B6 == 0)
      && ((EEPROM_Struct_PD . EEPROMStructPD . RSControlFlags == 0x8A )||(EEPROM_Struct_PD . EEPROMStructPD . RSControlFlags == 0x98)))
  {
    /*Incase of only Feuchte and solar frame preset then set the light ON, FW and IR to init value for safety reason*/
    {RlsmCem_Lin1Fr01_CEM_LIN1 . rlsmcem_lin1fr01_cem_lin1 . OutdBriSts_CEM_LIN1 = rb_TempLightOn_l;};   
  } 
  else
  {
    /* PRQA S 434, 436, 781 7 */ /* <<usind Micro Controller specific command > */
    MK2L_bit . no4 = 1U;;
    {RlsmCem_Lin1Fr01_CEM_LIN1 . rlsmcem_lin1fr01_cem_lin1 . OutdBriSts_CEM_LIN1 = rb_TempLightOn_l;};                                                                    // Turn Light on = TRUE
    MK2L_bit . no4 = 0U;;
  } 
  
   rb_crc_StsOutdBriSts =  GetOutdBriStsCrcj1850(rb_TempLightOn_l);
   {RlsmCem_Lin1Fr01_CEM_LIN1 . rlsmcem_lin1fr01_cem_lin1 . OutdBriChks_CEM_LIN1 = rb_crc_StsOutdBriSts;};
   
   if((((uF_LightInternalStatus_g . Bit . B0) == 1) && (uF_Main_Flags_g . Bit . B6 == 0)) && (rb_TempLightOn_l>0))
   {
      if((uF_modi_lightsens_g . Bit . B4 == 1)&& (((EEPROM_Struct_PD . EEPROMStructPD . EEKodierbyte0_g & 0x02)>0) == 1))
      {   
        {RlsmCem_Lin1Fr01_CEM_LIN1 . rlsmcem_lin1fr01_cem_lin1 . RainLi_CEM_LIN1 = 1;};
      }
      else
      {
        {RlsmCem_Lin1Fr01_CEM_LIN1 . rlsmcem_lin1fr01_cem_lin1 . RainLi_CEM_LIN1 = 0;};
      }
   }
   else
   {
       {RlsmCem_Lin1Fr01_CEM_LIN1 . rlsmcem_lin1fr01_cem_lin1 . RainLi_CEM_LIN1 = 0;};
   }
 
   
  switch (uF_modi_lightsens_g.AllBit & 0x0F)   //Switch Lightsensor Mode
  {
    case (byte) 1 :              //Case Darkstartmode
      rb_OpModeState = 0x02;
      break;
    case (byte) 0 :                    //Case Daymode
      rb_OpModeState = 0x01;
      break;
    case (byte) 2 :                 // Case Nightmode
      rb_OpModeState = 0x00;
      break;
    case (byte) 4 :               // Case Tunnelmode
      rb_OpModeState = 0x03;
      break;
    default:
      rb_OpModeState = 0x00 ;
      break;
  }
  {RlsmCem_Lin1Fr03_CEM_LIN1 . rlsmcem_lin1fr03_cem_lin1 . LiOprnMod_CEM_LIN1 = rb_OpModeState;}; 
  
}


void Humidity_Function(void)
{
  //static word rw_Temperature_Sensor_g;
  static unsigned int rw_Temperature_Scheibe_g;
  
  if (rbi_HumTempComError_g != 0)
  {
  
    if(((rbi_HumTempComError_g&0x08) == 0x08) && ((rbi_HumTempComError_g&0x10) == 0x10))
    {
       {RlsmCem_Lin1Fr02_CEM_LIN1 . rlsmcem_lin1fr02_cem_lin1 . CmptFrntWindTErr_CEM_LIN1 = 1;};
       {RlsmCem_Lin1Fr02_CEM_LIN1 . rlsmcem_lin1fr02_cem_lin1 . RelHumSnsrErr_CEM_LIN1 = 1;};
    } 
    else if((rbi_HumTempComError_g&0x08) == 0x08)
    {
       {RlsmCem_Lin1Fr02_CEM_LIN1 . rlsmcem_lin1fr02_cem_lin1 . CmptFrntWindTErr_CEM_LIN1 = 0;};
       {RlsmCem_Lin1Fr02_CEM_LIN1 . rlsmcem_lin1fr02_cem_lin1 . RelHumSnsrErr_CEM_LIN1 = 1;};
    }
    else if((rbi_HumTempComError_g&0x10) == 0x10)
    {
       {RlsmCem_Lin1Fr02_CEM_LIN1 . rlsmcem_lin1fr02_cem_lin1 . CmptFrntWindTErr_CEM_LIN1 = 1;};
       {RlsmCem_Lin1Fr02_CEM_LIN1 . rlsmcem_lin1fr02_cem_lin1 . RelHumSnsrErr_CEM_LIN1 = 0;};;
    }
    else
    {
       {RlsmCem_Lin1Fr02_CEM_LIN1 . rlsmcem_lin1fr02_cem_lin1 . CmptFrntWindTErr_CEM_LIN1 = 1;};
       {RlsmCem_Lin1Fr02_CEM_LIN1 . rlsmcem_lin1fr02_cem_lin1 . RelHumSnsrErr_CEM_LIN1 = 1;};
    }
      
    {RlsmCem_Lin1Fr02_CEM_LIN1 . rlsmcem_lin1fr02_cem_lin1 . CmptFrntWindT_CEM_LIN1_0 = ((canuint8)(1650&0x03)); RlsmCem_Lin1Fr02_CEM_LIN1 . rlsmcem_lin1fr02_cem_lin1 . CmptFrntWindT_CEM_LIN1_1 = ((canuint8)((1650>>3)&0xff));};      //window temperature   
    {RlsmCem_Lin1Fr02_CEM_LIN1 . rlsmcem_lin1fr02_cem_lin1 . RelHumSnsrRelHum_CEM_LIN1 = 255;};     // relation hum
    {RlsmCem_Lin1Fr02_CEM_LIN1 . rlsmcem_lin1fr02_cem_lin1 . CmptFrntWindDewT_CEM_LIN1_0 = ((canuint8)(1650&0xff)); RlsmCem_Lin1Fr02_CEM_LIN1 . rlsmcem_lin1fr02_cem_lin1 . CmptFrntWindDewT_CEM_LIN1_1 = ((canuint8)((1650>>8)&0x03));};  //dew point temperature
     
  }
  else
  {
    
    {RlsmCem_Lin1Fr02_CEM_LIN1 . rlsmcem_lin1fr02_cem_lin1 . CmptFrntWindTErr_CEM_LIN1 = 0;};
    {RlsmCem_Lin1Fr02_CEM_LIN1 . rlsmcem_lin1fr02_cem_lin1 . RelHumSnsrErr_CEM_LIN1 = 0;};;  
                                                             /*the temperature of screen ,the range is -40~120*/
    if(rw_Temperature_raw_g < 0x2ad)                         // The temperature less than -40 the tool doesnot support 
    {
      rw_Temperature_Scheibe_g = 0x2ad;
    }
    else if(rw_Temperature_raw_g > 0x4321)                   // The temperature greater than 120 the tool doesnot support
    {
      rw_Temperature_Scheibe_g = 0x4321;    
    }
    else
    {
      rw_Temperature_Scheibe_g = rw_Temperature_raw_g;
    }    
           
    if(rw_Temperature_raw_g == 0)
    {
      {RlsmCem_Lin1Fr02_CEM_LIN1 . rlsmcem_lin1fr02_cem_lin1 . CmptFrntWindT_CEM_LIN1_0 = ((canuint8)(400&0x03)); RlsmCem_Lin1Fr02_CEM_LIN1 . rlsmcem_lin1fr02_cem_lin1 . CmptFrntWindT_CEM_LIN1_1 = ((canuint8)((400>>3)&0xff));};
   
    }
    else
    {
      if(((rw_Temperature_Scheibe_g -685)/10) < 1650)
      {        
        {RlsmCem_Lin1Fr02_CEM_LIN1 . rlsmcem_lin1fr02_cem_lin1 . CmptFrntWindT_CEM_LIN1_0 = ((canuint8)(((rw_Temperature_Scheibe_g -685)/10)&0x03)); RlsmCem_Lin1Fr02_CEM_LIN1 . rlsmcem_lin1fr02_cem_lin1 . CmptFrntWindT_CEM_LIN1_1 = ((canuint8)((((rw_Temperature_Scheibe_g -685)/10)>>3)&0xff));};
      }
      else
      {         
        {RlsmCem_Lin1Fr02_CEM_LIN1 . rlsmcem_lin1fr02_cem_lin1 . CmptFrntWindT_CEM_LIN1_0 = ((canuint8)(1650&0x03)); RlsmCem_Lin1Fr02_CEM_LIN1 . rlsmcem_lin1fr02_cem_lin1 . CmptFrntWindT_CEM_LIN1_1 = ((canuint8)((1650>>3)&0xff));};
      }
    } 
  
    if (rw_DewPoint_g == 0)
    {
       {RlsmCem_Lin1Fr02_CEM_LIN1 . rlsmcem_lin1fr02_cem_lin1 . CmptFrntWindDewT_CEM_LIN1_0 = ((canuint8)(400&0xff)); RlsmCem_Lin1Fr02_CEM_LIN1 . rlsmcem_lin1fr02_cem_lin1 . CmptFrntWindDewT_CEM_LIN1_1 = ((canuint8)((400>>8)&0x03));};
    }    
    else
    {
      if (rw_DewPoint_g < (1650) )                /* dew point should be less than or equal to Scheibe temperature */
      {                                                                       
        {RlsmCem_Lin1Fr02_CEM_LIN1 . rlsmcem_lin1fr02_cem_lin1 . CmptFrntWindDewT_CEM_LIN1_0 = ((canuint8)(rw_DewPoint_g&0xff)); RlsmCem_Lin1Fr02_CEM_LIN1 . rlsmcem_lin1fr02_cem_lin1 . CmptFrntWindDewT_CEM_LIN1_1 = ((canuint8)((rw_DewPoint_g>>8)&0x03));};        
      }
      else
      {
        {RlsmCem_Lin1Fr02_CEM_LIN1 . rlsmcem_lin1fr02_cem_lin1 . CmptFrntWindDewT_CEM_LIN1_0 = ((canuint8)((1650)&0xff)); RlsmCem_Lin1Fr02_CEM_LIN1 . rlsmcem_lin1fr02_cem_lin1 . CmptFrntWindDewT_CEM_LIN1_1 = ((canuint8)(((1650)>>8)&0x03));};
      }
    }
      
    if (rb_Humidity_g == 0)                   /* Relative Humidity output*/ /*VCO_061 name hase changed*/
    {
      {RlsmCem_Lin1Fr02_CEM_LIN1 . rlsmcem_lin1fr02_cem_lin1 . RelHumSnsrRelHum_CEM_LIN1 = 0;};
    }        
    else
    {        
      {RlsmCem_Lin1Fr02_CEM_LIN1 . rlsmcem_lin1fr02_cem_lin1 . RelHumSnsrRelHum_CEM_LIN1 = rb_Humidity_raw_g;};
    }
       
  }
}



void StandByMode(void)
{
  if((rb_Verglasun_ClosedDebounce_mg > 100)||(uF_VoltageStatus_g . Bit . B2== 1)||(rw_CommandCloseWindowTimout_mg > 6000))
  {
    uF_SCIFlags_mg . Bit . B4 = 0;
    uF_ASIC_ControlFlags_g . Bit . B4 = 0;
  }
    
  if(uF_SCIFlags_mg . Bit . B0 == 1)
  {
    ApplLinInit(0x01);                                  // send wakup frame
    uF_SCIFlags_mg . Bit . B0 = 0;                      
  }

  if(uF_SCIFlags_mg . Bit . B4 == 1)               // send close window command
  {
   
     {RlsmCem_Lin1Fr03_CEM_LIN1 . rlsmcem_lin1fr03_cem_lin1 . RainDetected_CEM_LIN1 = 1;}; 
    if (rw_CommandCloseWindowTimout_mg > 6000)          // last for 60s
    {
      uF_ASIC_ControlFlags_g . Bit . B4 = 0;
    }
    else
    {
      rw_CommandCloseWindowTimout_mg++;
    }
  }
  else
  {
    rw_CommandCloseWindowTimout_mg = 0;
    {RlsmCem_Lin1Fr03_CEM_LIN1 . rlsmcem_lin1fr03_cem_lin1 . RainDetected_CEM_LIN1 = 0;};
  }
  
}


void VoltageDetect(void)
{
  static byte rb_underVoltageTimer_s;
  
  if(uF_VoltageStatus_g . Bit . B0 == 1)                         //undervoltage, Overvoltage ?
  {
    if(rb_underVoltageTimer_s>249)                       // undervoltagetimer > 249 -> 2500 ms abwarten
    {
      uF_VoltageStatus_g . Bit . B7 = 1;
    }
    else
    {
      rb_underVoltageTimer_s++;                          // increase undervoltagetimer
    }
  }
  else
  {
    rb_underVoltageTimer_s=0;                            // loesche Timer
    uF_VoltageStatus_g . Bit . B7 = 0;
  }
  if(uF_VoltageStatus_g . Bit . B0 == 1)
  {
      //l_u8_wr_L_Err_State_Volt(rbi_UnderVoltage_g);    //voltage error statue
  }
  else if(uF_VoltageStatus_g . Bit . B3 == 1)
  {
    {RlsmCem_Lin1Fr03_CEM_LIN1 . rlsmcem_lin1fr03_cem_lin1 . RainSnsrDiagcRainSnsrHiVoltDetd_CEM_LIN1 = 1;};  //voltage error statue
  }
  else
  {
    {RlsmCem_Lin1Fr03_CEM_LIN1 . rlsmcem_lin1fr03_cem_lin1 . RainSnsrDiagcRainSnsrHiVoltDetd_CEM_LIN1 = 0;};
  }     
}
//SWRS4 89031 v4 Rain Sensor Diagnostics [CS Released]
// 1 (1050mV - (3.6mV x 65))/3300mV  x 256 =63 ===>90
// 1. (1050mV - (3.6mV x 70))/3300mV  x 256 =62 ===>95
// offset 25 ,because Temperature would be 25 deg C  ---> Temperature sensor voltage should be 1050mV 

//2 (1140mV - (3.9mV x 65))/2417mV  x 1024 =485 ===>90
//2. (1140mV - (3.9mV x 70))/2417mV  x 1024 =367 ===>95
// offset 25 ,because Temperature would be 25 deg C  ---> Temperature sensor voltage should be 1140mV 
void TemperatureDetect(void)
{
  static unsigned int rb_overTemperatureTimer_s;
  byte rb_temperateOver_l = 0;
  
  if(((rb_InternalTemperature_g > 0) && (rb_InternalTemperature_g < 62))  || ((ras_ASIC_MUX_MeasAD_g[3]. avg > 0) && (ras_ASIC_MUX_MeasAD_g[3]. avg < 367)))                        //undervoltage, Overvoltage ?
  {
    if(rb_overTemperatureTimer_s>10000)                       
    {
      rb_temperateOver_l = 1;
    }
    else
    {
      rb_overTemperatureTimer_s++;                          
    }
  }
  else if(((rb_InternalTemperature_g > 0) && (rb_InternalTemperature_g< 63)) || ((ras_ASIC_MUX_MeasAD_g[3]. avg > 0) && (ras_ASIC_MUX_MeasAD_g[3]. avg < 485))) 
  {
    if(rb_overTemperatureTimer_s>10000)                       
    {
      rb_temperateOver_l = 1;//continue on
    }
    else
    {
      rb_overTemperatureTimer_s=0;                            
      rb_temperateOver_l = 0;                         
    }
  }  
  else
  {
    rb_overTemperatureTimer_s=0;                            
    rb_temperateOver_l = 0;
  }
  // ASIC/MCU temperature detect,when over 95 degree,then set.
  {RlsmCem_Lin1Fr03_CEM_LIN1 . rlsmcem_lin1fr03_cem_lin1 . RainSnsrDiagcRainSnsrHiTDetd_CEM_LIN1 = rb_temperateOver_l;}; 
}



void OutPutHudSendCount(void)
{
     static byte rb_HUD_Cnt_s = 0;
     //cnt count 
    {RlsmCem_Lin1Fr02_CEM_LIN1 . rlsmcem_lin1fr02_cem_lin1 . AmbIllmnFwdStsCntr_CEM_LIN1 = rb_HUD_Cnt_s;};
    if(rb_HUD_Cnt_s < 15)
    {
      rb_HUD_Cnt_s ++;
    }
    else
    {
      rb_HUD_Cnt_s = 0;
    }
    
  
}

void OutPutHudValue(void)
{
  
   byte rb_hud_Crc8_l;
   unsigned long rl_hud_Brightness_l;
   unsigned long rl_hud_AMB_Brightness_l;
   unsigned long rl_hud_FW_Brightness_l; 
   unsigned long rl_eeprom_hud_max_l = 0;
   byte rb_hud_Low8Bit_l = 0;
   unsigned int rw_hud_high9Bit_l  = 0;
  
   /*****************Get the Real Lux for FW and AMB  Illuminance = FW*6 + AMB*15 *********************/
     
    rl_hud_AMB_Brightness_l = 15*((unsigned long)(get_rw_Amb_light16bit_g()));
    rl_hud_FW_Brightness_l = (unsigned long)((3*((unsigned long)(get_rl_HUD_light32bit_g())))>>1);
    
    /*********Pre-Process for original value get average for "rl_HUD_AMB_Brightness" and "rl_HUD_FW_Brightness"*********/
    /********100ms average for AMB and FW        1000ms for sum average      ******************/
    GetFiveTableValue_50ms(rl_hud_AMB_Brightness_l,rl_hud_FW_Brightness_l);   
    
    /*************5000ms for average output**************/
    rl_hud_Brightness_l  = CalcHUDMean_1000ms();
      
    /***********Output to LIN Interface**************/
    rl_eeprom_hud_max_l = EEPROM_Struct_PD . EEPROMStructPD . HUD_MAX_Resolution*EEPROM_Struct_PD . EEPROMStructPD . HUD_MAX_Value;
    if(rl_hud_Brightness_l >= rl_eeprom_hud_max_l)
    {
         rl_hud_Brightness_l = rl_eeprom_hud_max_l;        
    }
    
    if(rl_hud_Brightness_l > 126000)//currnet send data  length is shorter
    {
       rl_hud_Brightness_l = 126000;
    } 
    rb_hud_Low8Bit_l  = (byte)(rl_hud_Brightness_l&0xFF);
    rw_hud_high9Bit_l = (unsigned int)((rl_hud_Brightness_l>>8)&0x1ff);
    {RlsmCem_Lin1Fr02_CEM_LIN1 . rlsmcem_lin1fr02_cem_lin1 . AmbIllmnFwdStsAmblillmn2_CEM_LIN1 = rb_hud_Low8Bit_l;};
    {RlsmCem_Lin1Fr02_CEM_LIN1 . rlsmcem_lin1fr02_cem_lin1 . AmbIllmnFwdStsAmblillmn1_CEM_LIN1_0 = ((canuint8)(rw_hud_high9Bit_l&0xff)); RlsmCem_Lin1Fr02_CEM_LIN1 . rlsmcem_lin1fr02_cem_lin1 . AmbIllmnFwdStsAmblillmn1_CEM_LIN1_1 = ((canuint8)((rw_hud_high9Bit_l>>8)&0x1));};
  
    //check crc 
    rb_hud_Crc8_l = GetHudCrcj1850(rl_hud_Brightness_l);
    {RlsmCem_Lin1Fr02_CEM_LIN1 . rlsmcem_lin1fr02_cem_lin1 . AmbIllmnFwdStsChks_CEM_LIN1 = rb_hud_Crc8_l;};
    
    /*****************end hud info relation  *********************/  
}

void OutPutTwliBriValue(void)
{
    // AMB 
    if(get_rw_Amb_light16bit_g()*20 < 16383)    
    {
        {RlsmCem_Lin1Fr01_CEM_LIN1 . rlsmcem_lin1fr01_cem_lin1 . TwliBriRawTwliBriRaw_CEM_LIN1_0 = ((canuint8)(get_rw_Amb_light16bit_g()*20&0x3F)); RlsmCem_Lin1Fr01_CEM_LIN1 . rlsmcem_lin1fr01_cem_lin1 . TwliBriRawTwliBriRaw_CEM_LIN1_1 = ((canuint8)((get_rw_Amb_light16bit_g()*20>>6)&0xFF));};
    }
    else
    {
        {RlsmCem_Lin1Fr01_CEM_LIN1 . rlsmcem_lin1fr01_cem_lin1 . TwliBriRawTwliBriRaw_CEM_LIN1_0 = ((canuint8)(16383&0x3F)); RlsmCem_Lin1Fr01_CEM_LIN1 . rlsmcem_lin1fr01_cem_lin1 . TwliBriRawTwliBriRaw_CEM_LIN1_1 = ((canuint8)((16383>>6)&0xFF));};
    } 
}

void OutPutSolarValue(void)
{
  

    unsigned int rw_IrLightforSOSE_Corr1_l;
    unsigned int rw_IrLightforSOSE_Corr2_l;
    unsigned int rw_SoSe_SunInt_2D_Le_l;
    unsigned int rw_SoSe_SunInt_2D_Re_l; 
        
    if ((((EEPROM_Struct_PD . EEPROMStructPD . RSControlFlags & 0x02)>0) == 1) && (1 == uF_ASIC_ControlFlags_g . Bit . B2))
    {
      if ((EEPROM_Struct_AD . EEPROMStructAD . SolarShadowCorrFactor1 ) > 0)
      {
        rw_IrLightforSOSE_Corr1_l= get_rw_IR_light16bit_g()/(EEPROM_Struct_AD . EEPROMStructAD . SolarShadowCorrFactor1 ); 
      }
      else 
      {
        rw_IrLightforSOSE_Corr1_l = 0;  
      }

      if((rw_IrLightforSOSE_Corr1_l) > (rw_Solar_light16bit_2_g))
      {
        rw_SoSe_SunInt_2D_Le_l = rw_IrLightforSOSE_Corr1_l;
      }
      else
      {
        rw_SoSe_SunInt_2D_Le_l = rw_Solar_light16bit_2_g ;
      }


      if((rw_IrLightforSOSE_Corr1_l) > (rw_Solar_light16bit_1_g))
      {
        rw_SoSe_SunInt_2D_Re_l = rw_IrLightforSOSE_Corr1_l;
      }
      else
      {
        rw_SoSe_SunInt_2D_Re_l = rw_Solar_light16bit_1_g ;
      }    

      if ((EEPROM_Struct_AD . EEPROMStructAD . SolarShadowCorrFactor2 ) > 0)
      {
        rw_IrLightforSOSE_Corr2_l= get_rw_IR_light16bit_g()/(EEPROM_Struct_AD . EEPROMStructAD . SolarShadowCorrFactor2 ); 
      }
      else 
      {
        rw_IrLightforSOSE_Corr2_l = 0;  
      }

      if((rw_IrLightforSOSE_Corr2_l >= rw_SoSe_SunInt_2D_Le_l) && (rw_IrLightforSOSE_Corr2_l >= rw_SoSe_SunInt_2D_Re_l)) 
      {
        rw_SoSe_SunInt_2D_Le_l = rw_IrLightforSOSE_Corr2_l;
        rw_SoSe_SunInt_2D_Re_l = rw_IrLightforSOSE_Corr2_l;
      }
      rw_SoSe_SunInt_2D_Le_l=(rw_SoSe_SunInt_2D_Le_l>>3)*5;
      rw_SoSe_SunInt_2D_Le_l=((rw_SoSe_SunInt_2D_Le_l>240)?240:rw_SoSe_SunInt_2D_Le_l);
      {RlsmCem_Lin1Fr03_CEM_LIN1 . rlsmcem_lin1fr03_cem_lin1 . SolarSnsrLeValue_CEM_LIN1 = rw_SoSe_SunInt_2D_Le_l;};

      rw_SoSe_SunInt_2D_Re_l=(rw_SoSe_SunInt_2D_Re_l>>3)*5;
      rw_SoSe_SunInt_2D_Re_l=((rw_SoSe_SunInt_2D_Re_l>240)?240:rw_SoSe_SunInt_2D_Re_l);
      {RlsmCem_Lin1Fr03_CEM_LIN1 . rlsmcem_lin1fr03_cem_lin1 . SolarSnsrRiValue_CEM_LIN1 = rw_SoSe_SunInt_2D_Re_l;};       
    }
    else
    {
      {RlsmCem_Lin1Fr03_CEM_LIN1 . rlsmcem_lin1fr03_cem_lin1 . SolarSnsrLeValue_CEM_LIN1 = 0xFF;}; 
      {RlsmCem_Lin1Fr03_CEM_LIN1 . rlsmcem_lin1fr03_cem_lin1 . SolarSnsrRiValue_CEM_LIN1 = 0xFF;}; 
    }

}
void OutPutBrightnessValue(void)
{
  static byte rb_InitLightValCnt_l=100;
 
  
  if((uF_ASIC_ControlFlags_g . Bit . B1 == 0)|| (uF_Main_Flags_g . Bit . B6 == 1))
  {
                                                                         //hold the previous values
    if(rb_InitLightValCnt_l<100)
    {
      rb_InitLightValCnt_l++;
    }
    else
    { 
       {RlsmCem_Lin1Fr02_CEM_LIN1 . rlsmcem_lin1fr02_cem_lin1 . AmbIllmnFwdStsAmblillmn1_CEM_LIN1_0 = ((canuint8)(0&0xff)); RlsmCem_Lin1Fr02_CEM_LIN1 . rlsmcem_lin1fr02_cem_lin1 . AmbIllmnFwdStsAmblillmn1_CEM_LIN1_1 = ((canuint8)((0>>8)&0x1));};
       {RlsmCem_Lin1Fr02_CEM_LIN1 . rlsmcem_lin1fr02_cem_lin1 . AmbIllmnFwdStsAmblillmn2_CEM_LIN1 = 0;};
       {RlsmCem_Lin1Fr02_CEM_LIN1 . rlsmcem_lin1fr02_cem_lin1 . AmbIllmnFwdStsCntr_CEM_LIN1 = 0;};
       {RlsmCem_Lin1Fr01_CEM_LIN1 . rlsmcem_lin1fr01_cem_lin1 . TwliBriRawTwliBriRaw_CEM_LIN1_0 = ((canuint8)(0&0x3F)); RlsmCem_Lin1Fr01_CEM_LIN1 . rlsmcem_lin1fr01_cem_lin1 . TwliBriRawTwliBriRaw_CEM_LIN1_1 = ((canuint8)((0>>6)&0xFF));};
       {RlsmCem_Lin1Fr03_CEM_LIN1 . rlsmcem_lin1fr03_cem_lin1 . SolarSnsrRiValue_CEM_LIN1 = 0;};        // Init 
       {RlsmCem_Lin1Fr03_CEM_LIN1 . rlsmcem_lin1fr03_cem_lin1 . SolarSnsrLeValue_CEM_LIN1 = 0;};         // Init
    }
  }
  else
  {
    rb_InitLightValCnt_l=0;  
    if(EEPROM_Struct_PD . EEPROMStructPD . RSControlFlags == 0x98)
    {
      /*Incase of only Feuchte and solar frame preset then set the light ON, FW and IR to init value for safety reason*/ 
      {RlsmCem_Lin1Fr02_CEM_LIN1 . rlsmcem_lin1fr02_cem_lin1 . AmbIllmnFwdStsAmblillmn1_CEM_LIN1_0 = ((canuint8)(0x1FF&0xff)); RlsmCem_Lin1Fr02_CEM_LIN1 . rlsmcem_lin1fr02_cem_lin1 . AmbIllmnFwdStsAmblillmn1_CEM_LIN1_1 = ((canuint8)((0x1FF>>8)&0x1));};
       {RlsmCem_Lin1Fr02_CEM_LIN1 . rlsmcem_lin1fr02_cem_lin1 . AmbIllmnFwdStsAmblillmn2_CEM_LIN1 = 0xFF;};;
      {RlsmCem_Lin1Fr02_CEM_LIN1 . rlsmcem_lin1fr02_cem_lin1 . AmbIllmnFwdStsCntr_CEM_LIN1 = 0;};
      {RlsmCem_Lin1Fr01_CEM_LIN1 . rlsmcem_lin1fr01_cem_lin1 . TwliBriRawTwliBriRaw_CEM_LIN1_0 = ((canuint8)(16383&0x3F)); RlsmCem_Lin1Fr01_CEM_LIN1 . rlsmcem_lin1fr01_cem_lin1 . TwliBriRawTwliBriRaw_CEM_LIN1_1 = ((canuint8)((16383>>6)&0xFF));};
      {RlsmCem_Lin1Fr03_CEM_LIN1 . rlsmcem_lin1fr03_cem_lin1 . SolarSnsrRiValue_CEM_LIN1 = 0xFF;};       //Blake_Check Even never run here,but make up is better.                      /* Init*/
      {RlsmCem_Lin1Fr03_CEM_LIN1 . rlsmcem_lin1fr03_cem_lin1 . SolarSnsrLeValue_CEM_LIN1 = 0xFF;};                             /* Init*/
            
    }
    else if(rb_Err_State_Light_Sens_mg == 1)                    /*  VDR469   set for error*/
    {
                                    // IR Helligkeit Fehler
       {RlsmCem_Lin1Fr02_CEM_LIN1 . rlsmcem_lin1fr02_cem_lin1 . AmbIllmnFwdStsAmblillmn1_CEM_LIN1_0 = ((canuint8)(0x1FF&0xff)); RlsmCem_Lin1Fr02_CEM_LIN1 . rlsmcem_lin1fr02_cem_lin1 . AmbIllmnFwdStsAmblillmn1_CEM_LIN1_1 = ((canuint8)((0x1FF>>8)&0x1));};
       {RlsmCem_Lin1Fr02_CEM_LIN1 . rlsmcem_lin1fr02_cem_lin1 . AmbIllmnFwdStsAmblillmn2_CEM_LIN1 = 0xFF;};;
       {RlsmCem_Lin1Fr02_CEM_LIN1 . rlsmcem_lin1fr02_cem_lin1 . AmbIllmnFwdStsCntr_CEM_LIN1 = 0;};
       {RlsmCem_Lin1Fr01_CEM_LIN1 . rlsmcem_lin1fr01_cem_lin1 . TwliBriRawTwliBriRaw_CEM_LIN1_0 = ((canuint8)(16383&0x3F)); RlsmCem_Lin1Fr01_CEM_LIN1 . rlsmcem_lin1fr01_cem_lin1 . TwliBriRawTwliBriRaw_CEM_LIN1_1 = ((canuint8)((16383>>6)&0xFF));};
       {RlsmCem_Lin1Fr03_CEM_LIN1 . rlsmcem_lin1fr03_cem_lin1 . SolarSnsrRiValue_CEM_LIN1 = 0xFF;};                            /* Init*/
       {RlsmCem_Lin1Fr03_CEM_LIN1 . rlsmcem_lin1fr03_cem_lin1 . SolarSnsrLeValue_CEM_LIN1 = 0xFF;};                             /* Init*/
    }
    else
    {  
         OutPutHudValue(); 
         OutPutTwliBriValue();
         OutPutSolarValue();
    }
  } 
}


#pragma inline=forced
static void CheckErrors(void)
{
  //l_u8_wr_L_Err_State_Cal_RS(1);                                                 //custorm defined, but we do not support
  //l_u8_wr_L_Err_State_Coding(0);
  byte rb_hud_errorParity_l = 0;
  
  rb_RS_LS_Error1_g = ((uF_Diagnose_pre_Flag . Bit . B1) | 
                       ((uF_Diagnose_pre_Flag . Bit . B0)<<1) | 
                         ((uF_Check_lightsensor_g . Bit . B3)<<2) | 
                           (uF_ASIC_Error_Flags_g . Bit . B3<<3) | 
                             (uF_ASIC_Ctrl_Error_Flags_g . Bit . B5<<4) | 
                               (uF_ASIC_Ctrl_Error_Flags_g . Bit . B0<<5) | 
                                 (uF_ASIC_Ctrl_Error_Flags_g . Bit . B1<<6) | 
                                   (uF_ASIC_Ctrl_Error_Flags_g . Bit . B4<<7));
  /*VCO_220 VIrefLo/Hi monitoring*/ /*VDR_878*/
  rb_RS_LS_Error2_g = (uF_ASIC_Ctrl_Error_Flags_g . Bit . B3 | 
                       ((uF_uC_Error_g . Bit . B1)<<1) | 
                         (uF_ASIC_Error_Flags_g . Bit . B5<<2) |
                           (uF_ASIC_Error_Flags_g . Bit . B7<<3) |
                             (uF_ASIC_Error_Flags1_g . Bit . B0<<4));
  
  /*VCO_225 RS functionality detection - error when not available*/
  rb_RainS_Error1_g = (RSStatus . Bit . B4 | 
                       (uF_ASIC_Ctrl_Error_Flags_g . Bit . B2<<1) |
                         (uF_ASIC_Error_Flags_g . Bit . B6<<2)|
                           ((uF_Diagnose_pre_Flag . Bit . B3)<<3)|
                             ((uF_uC_Error_g . Bit . B0)<<4));  
  
  rb_LightS_Error1_g = ((uF_LightInternalStatus_g . Bit . B5) | 
                        (rb_ASIC_ALSx_ShortDetected_Error_g<<1) | 
                          ((uF_Diagnose_pre_Flag . Bit . B2)<<2) | 
                            (uF_ASIC_Error_Flags_g . Bit . B4<<3)| 
                              ((uF_Diagnose_pre_Flag . Bit . B4) << 4));
  /*VCO_224 RS_Error should be set only by RAM/ROM error, when RS function is coded as inactive in kodierbyte0*/
  {RlsmCem_Lin1Fr01_CEM_LIN1 . rlsmcem_lin1fr01_cem_lin1 . RainSnsrErrRainDetnErrActv_CEM_LIN1 = 1;};  

  if((1==(EEPROM_Struct_PD . EEPROMStructPD . RSControlFlags & 0x01)) && (0==((EEPROM_Struct_PD . EEPROMStructPD . EEKodierbyte0_g & 0x40)>0)))
  {
    /* VCO132: SM210 - ASIC Frequency Check (done at startup) - LS,RS_Failure */
    /* VCO 140: SM150 - ADC test */
    /* setze Lichtsensor RS-Fehler nach SRS */
    /*SM240*/
    {RlsmCem_Lin1Fr01_CEM_LIN1 . rlsmcem_lin1fr01_cem_lin1 . RainSnsrErrRainDetnErr_CEM_LIN1 = (uF_VoltageStatus_g . Bit . B3 != 0)||(rb_RS_LS_Error1_g != 0)||(rb_RS_LS_Error2_g != 0)||(rb_RainS_Error1_g != 0) ||(uF_E2ConfigErrorFlags_g . Bit . B6 != 0);};
  }
  else
  {
    /*only RAM/ROM error and RS version error*/
    {RlsmCem_Lin1Fr01_CEM_LIN1 . rlsmcem_lin1fr01_cem_lin1 . RainSnsrErrRainDetnErr_CEM_LIN1 = ((rb_RS_LS_Error1_g&0x3) != 0)||(1==(uF_Diagnose_pre_Flag . Bit . B3))||(uF_E2ConfigErrorFlags_g . Bit . B6 != 0);};
  }
  




  
  if(((rb_RS_LS_Error1_g != 0)||(rb_RS_LS_Error2_g != 0)||(rb_LightS_Error1_g != 0)||(uF_E2ConfigErrorFlags_g . Bit . B6 != 0)||(uF_LIN_DiagReq2_mg . Bit . B1)))
  {
    rb_Err_State_Light_Sens_mg = 1;
  }
  else
  {
    rb_Err_State_Light_Sens_mg = 0;
  }
 
  {RlsmCem_Lin1Fr03_CEM_LIN1 . rlsmcem_lin1fr03_cem_lin1 . SolarSnsrErr_CEM_LIN1 = rb_Err_State_Light_Sens_mg;};
  if(uF_ASIC_Error_Flags_g . Bit . B0 != 0)
  {
    {RlsmCem_Lin1Fr01_CEM_LIN1 . rlsmcem_lin1fr01_cem_lin1 . TwliBriRawQf_CEM_LIN1 = 2;}; //AMB ERROR
  }
  else
  {
    {RlsmCem_Lin1Fr01_CEM_LIN1 . rlsmcem_lin1fr01_cem_lin1 . TwliBriRawQf_CEM_LIN1 = 3;};//NORMAL
  }
  
  {RlsmCem_Lin1Fr01_CEM_LIN1 . rlsmcem_lin1fr01_cem_lin1 . HudSnsrErrSnsrErr_CEM_LIN1 = (uF_ASIC_Error_Flags_g . Bit . B0 != 0) || (uF_ASIC_Error_Flags_g . Bit . B1 != 0);};//AMB and FW error 
  rb_hud_errorParity_l =IsByteOddParity(RlsmCem_Lin1Fr01_CEM_LIN1 . rlsmcem_lin1fr01_cem_lin1 . HudSnsrErrSnsrErr_CEM_LIN1);
  {RlsmCem_Lin1Fr01_CEM_LIN1 . rlsmcem_lin1fr01_cem_lin1 . HudSnsrErrParChk_CEM_LIN1 = rb_hud_errorParity_l;};
    
}

void ApplLinInit(byte rb_LIN_State_l)
{
  
  // init unused bits to 1
  byte rb_Index_l; 
   
  static const byte LinMsgDefault_RlsmCem_SerNrLin1Fr01_CEM_LIN1[8] = {0,0,0,0,0,0,0,0};    /* 0x22"RlsmCem_SerNrLin1Fr01_CEM_LIN1" */
  static const byte LinMsgDefault_RlsmCem_Lin1PartNrFr02_CEM_LIN1[8] = {0,0,0,0,0,0,0,0};    /* 0x18"RlsmCem_Lin1PartNrFr02_CEM_LIN1" */
  static const byte LinMsgDefault_RlsmCem_Lin1PartNrFr01_CEM_LIN1[8] = {0,0,0,0,0,0,0,0};    /* 0x20"RlsmCem_Lin1PartNrFr01_CEM_LIN1" */
  static const byte LinMsgDefault_RlsmCem_Lin1Fr03_CEM_LIN1[8] = {0,0,0,0,0,0,0,0};          /* 0x02"RlsmCem_Lin1Fr03_CEM_LIN1" */
  static const byte LinMsgDefault_RlsmCem_Lin1Fr02_CEM_LIN1[8] = {144,1,0,0,0,0,50,0};       /* 0x2C"RlsmCem_Lin1Fr02_CEM_LIN1" */
  static const byte LinMsgDefault_RlsmCem_Lin1Fr01_CEM_LIN1[8] = {0,0,0,1,0,0,0,0};         /* 0x15"RlsmCem_Lin1Fr01_CEM_LIN1" */

  rb_Index_l = 0;
  do
  {
    RlsmCem_SerNrLin1Fr01_CEM_LIN1._c[rb_Index_l] = LinMsgDefault_RlsmCem_SerNrLin1Fr01_CEM_LIN1[rb_Index_l];
    RlsmCem_Lin1PartNrFr02_CEM_LIN1._c[rb_Index_l] = LinMsgDefault_RlsmCem_Lin1PartNrFr02_CEM_LIN1[rb_Index_l];
    RlsmCem_Lin1PartNrFr01_CEM_LIN1._c[rb_Index_l] = LinMsgDefault_RlsmCem_Lin1PartNrFr01_CEM_LIN1[rb_Index_l];
    RlsmCem_Lin1Fr03_CEM_LIN1._c[rb_Index_l] = LinMsgDefault_RlsmCem_Lin1Fr03_CEM_LIN1[rb_Index_l];
    RlsmCem_Lin1Fr02_CEM_LIN1._c[rb_Index_l] = LinMsgDefault_RlsmCem_Lin1Fr02_CEM_LIN1[rb_Index_l];
    RlsmCem_Lin1Fr01_CEM_LIN1._c[rb_Index_l] = LinMsgDefault_RlsmCem_Lin1Fr01_CEM_LIN1[rb_Index_l];
    rb_Index_l++;
  } while (rb_Index_l < 8);
    



  rw_AfterRSWipeCounter_mg = 50000;
  rw_AfterRSWipeCounterAlt_mg = 50000;
  rw_AfterWWSWipeCounter_mg = 50000;                                                      //Direktbitdelay bei Kl15 Aus hochsetzen!
  sci_init(rb_LIN_State_l);
  uF_SCIFlags_mg . Bit . B6 = 1;
  uF_StatusRainsensor_mg . Bit . B7 = 1;
  rb_PotiStageFromBox_g = 3;  
  rw_WipeCommandTimOut_mg = 0; 
  rb_AnyErrorCounterDebounce_mg = 200;  
  rb_WipeWorkStatus_mg = 1;  
}

__callt void ApplLinSlavePreCopy(byte rb_MessageID_l)                                     /* callt function faster */
{
  if(rb_MessageID_l == (EEPROM_Struct_PD . EEPROMStructPD . IDRLSs_01 & 0x3F))
  {
    {RlsmCem_Lin1Fr01_CEM_LIN1 . rlsmcem_lin1fr01_cem_lin1 . ErrRespRLSM_CEM_LIN1 = uF_Communication_mg . Bit . B6;};
    //l_u8_wr_L_Signal_Error(rbi_latched_ResponseError_mg);
    uF_Communication_mg . Bit . B6 = 0;
  } 
}

/******************************HUD Algrithm shenzhen-team 2018-05-05************************/



void GetFiveTableValue_500ms(unsigned long rl_HUD_Brightness_50ms)
{
  static unsigned char rb_k_cycleIn50ms=0;
  static unsigned char rb_k_cycleIn500ms=0;
  
  rb_storeHUDValueEvery500ms[rb_k_cycleIn50ms] = rl_HUD_Brightness_50ms;
    
  rb_k_cycleIn50ms++;
  if(rb_k_cycleIn50ms >= 10)
  {
    rb_k_cycleIn50ms = 0;
    orderHUDValue(10);
    HUDEverageValue[rb_k_cycleIn500ms]=(rb_storeHUDValueEvery500ms[3]+rb_storeHUDValueEvery500ms[4]+rb_storeHUDValueEvery500ms[5]+rb_storeHUDValueEvery500ms[6]+rb_storeHUDValueEvery500ms[7])/5;
    rb_k_cycleIn500ms++;
    if(rb_k_cycleIn500ms >= 2)
    {
      rb_k_cycleIn500ms=0;  
      rb_hud_data_update = 1;
    }    
  }
}

unsigned long  AdjustOutHudValue(unsigned long rl_CurrentHud)
{
    int currLevel = 0;
    int rw_LastCurrDiff = 0;
    unsigned long  rl_adjustAfterHud=0;
     
    if(rl_CurrentHud >= 100)
    {
      return rl_CurrentHud;
    }
    currLevel = RW_Amb_Fw_Result_End/10;  
    rw_LastCurrDiff = rl_CurrentHud -RW_Amb_Fw_Result_End;
    
    if(rw_LastCurrDiff >=-15 && rw_LastCurrDiff <=15)// less than 15 is 
    {
        return  rl_CurrentHud;
    }
    currLevel = currLevel+rw_LastCurrDiff/15;
    rw_LastCurrDiff = rw_LastCurrDiff%3;
    if(currLevel < 0)
    {   
      rl_adjustAfterHud = 5+rw_LastCurrDiff;
    }
    else if(currLevel > 9)
    {
      rl_adjustAfterHud = 92+rw_LastCurrDiff;
      
    }
    else
    {
      rl_adjustAfterHud = 5+currLevel*10+rw_LastCurrDiff;
    }
    return  rl_adjustAfterHud;    
}

unsigned char GetUpdateTimeForLightStatus(void)
{
   unsigned char  hud_refresh_time = 1;  
    //1 in tunnel and day for 1s  get data;in night and darkstart for 3s  get data 
    //2 if in tunnel and speed less 10,then 3s will upate
   if(((uF_LightInternalStatus_g . Bit . B0) == 1) && (uF_Main_Flags_g . Bit . B6 == 0))
   {
        if(uF_modi_lightsens_g.AllBit & (byte) 2)
        {
           hud_refresh_time = 3;
        }
        else if (uF_modi_lightsens_g.AllBit & (byte) 4)
        {
          if(rb_speed_in_kmh_g >= 10)
          {
            hud_refresh_time = 1;
          }
          else
          {
            hud_refresh_time = 3;
          }   
        }
        else if (uF_modi_lightsens_g.AllBit & (byte) 1)
        {
          hud_refresh_time = 3;
        }
        else
        {
          hud_refresh_time = 1;  
        }
    }
    else
    {
       hud_refresh_time = 1;  
    }  
    return  hud_refresh_time;
}

unsigned long CalcHUDMean_1000ms(void)
{  
    
    unsigned long  rl_current_hud_lux = 0;
    unsigned char  rb_hud_refresh_time = 1;
      
    if(rb_hud_data_update == 1)
    {
      rb_hud_data_update = 0;
      rb_hud_refresh_time = GetUpdateTimeForLightStatus();
      if(RW_Update_Time_Count < rb_hud_refresh_time)
      {
        RW_Update_Time_Count++;
        rl_current_hud_lux = (HUDEverageValue[0] + HUDEverageValue[1])/2; 
        if((rl_current_hud_lux < 100) && (RW_Amb_Fw_Result_End < 100))
        {        
             rl_current_hud_lux = (RW_Amb_Fw_Result_End +rl_current_hud_lux)/2;
        }
           
      }
     
      if(rb_hud_refresh_time == RW_Update_Time_Count)//refresh time is reached
      {   
         RW_Update_Time_Count = 0;         
         RW_Amb_Fw_Result_End = AdjustOutHudValue(rl_current_hud_lux);        
      }   
    }
    return RW_Amb_Fw_Result_End;//((HUDEverageValue[0] + HUDEverageValue[1])/2);// + HUDEverageValue[2] + HUDEverageValue[3] + HUDEverageValue[4]) / 5);
}


/*****Bubble Sort**********/
void orderHUDValue(int n)
{
  unsigned long rb_temp_l = 0;
  int i =0;
  int j = 0;
  
  for(i=0;i<n;i++)
   for( j=1;j<n-i;j++)
  {    
    if(rb_storeHUDValueEvery500ms[j-1]>rb_storeHUDValueEvery500ms[j])
    {
      rb_temp_l = rb_storeHUDValueEvery500ms[j];
      rb_storeHUDValueEvery500ms[j] = rb_storeHUDValueEvery500ms[j-1];
      rb_storeHUDValueEvery500ms[j-1] = rb_temp_l ;
    }
  }
}

void GetFiveTableValue_50ms(unsigned long Fw,unsigned long Amb)
{
  static unsigned char rb_k_cycleIn50ms=0;
  unsigned char rb_count = 0;
  
  rb_storeFW_ValueEvery50ms[rb_k_cycleIn50ms] = Fw;
  rb_storeAMB_ValueEvery50ms[rb_k_cycleIn50ms] = Amb;
    
  rb_k_cycleIn50ms++;
  if(rb_k_cycleIn50ms >= 5)
  {
    rb_k_cycleIn50ms = 0;
    FW_Average_In_50ms = rb_storeFW_ValueEvery50ms[0];
    for(rb_count = 1;rb_count < 5;rb_count++)
    {
      FW_Average_In_50ms =(FW_Average_In_50ms+ rb_storeFW_ValueEvery50ms[rb_count])/2;
    }
    
    AMB_Average_In_50ms=rb_storeAMB_ValueEvery50ms[0];
    for(rb_count = 1;rb_count < 5;rb_count++)
    {
      AMB_Average_In_50ms =(AMB_Average_In_50ms+ rb_storeAMB_ValueEvery50ms[rb_count])/2;
    } 
    
    FW_Average_In_50ms = (FW_Average_In_50ms_Old+FW_Average_In_50ms)/2 ;
    AMB_Average_In_50ms = (AMB_Average_In_50ms_Old +AMB_Average_In_50ms)/2; 
    GetFiveTableValue_500ms(FW_Average_In_50ms + AMB_Average_In_50ms);
    FW_Average_In_50ms_Old = FW_Average_In_50ms;
    AMB_Average_In_50ms_Old = AMB_Average_In_50ms;
 
   }  
}

/******************************************End*********************************************/

/*byte resultCrcTest = 0;
void TestCrcJ1850Info(void)
{
    byte buffer[4]={0x00,0x00,0x00,0x00};//0x59
    byte buffer1[3]={0xF2,0x01,0x83};//0x37
    byte buffer2[4]={0x0F,0xAA,0x00,0x55};//0x79
    byte buffer3[4]={0x00,0xFF,0x55,0x11};//0xB8
    byte buffer4[9]={0x33,0x22,0x55,0xAA,0xBB,0xCC,0xDD,0xEE,0xFF};//0xcb
    byte buffer5[3]={0x92,0x6B,0x55};//0x8C
    byte buffer6[4]={0xFF,0xFF,0xFF,0xFF};//0x74
    
    resultCrcTest =  CRC8SAEJ1850(buffer,4); //ok
    resultCrcTest =  CRC8SAEJ1850(buffer1,3);//ok
    resultCrcTest =  CRC8SAEJ1850(buffer2,4);//ok
    resultCrcTest =  CRC8SAEJ1850(buffer3,4);//ok
    resultCrcTest =  CRC8SAEJ1850(buffer4,9);//ok
    resultCrcTest =  CRC8SAEJ1850(buffer5,3);//ok
    resultCrcTest =  CRC8SAEJ1850(buffer6,4);//ok
    
}*/

byte CRC8SAEJ1850(byte *u8_data,byte u8_len)
{
    byte i, j;
    byte u8_crc8;
    byte u8_poly;

    u8_crc8 = 0xFF;
    u8_poly = 0x1D;

    for (i = 0; i < u8_len; i++)
    {
      u8_crc8 ^= u8_data[i];

      for (j = 0; j < 8; j++)
      {
        if (u8_crc8 & 0x80)
        {
          u8_crc8 = (u8_crc8 << 1) ^ u8_poly;
        }
        else
        {
          u8_crc8 <<= 1;
        }
     }
    }
    u8_crc8 ^= (byte)0xFF;
    return u8_crc8;
}

byte GetOutdBriStsCrcj1850(byte OutdBriSts)
{  
      byte buffer[1];
      buffer[0] = OutdBriSts;
      //TestCrcJ1850Info();
      return CRC8SAEJ1850(buffer,1);  
}

byte GetHudCrcj1850(unsigned long hudSrc)
{     
      //byte buffer[2];
      //buffer[0] = hudSrc&0xFF;
      //buffer[1] = (hudSrc>>8)&0xFF;      
      //return CRC8SAEJ1850(buffer,2);
	  /**********Zhiyuan HU 20190313**************/
	  byte buffer[3];
	  buffer[0] = hudSrc&0xFF;
	  buffer[1] = (hudSrc>>8)&0xFF;
	  buffer[2] = (hudSrc>>16)&0xFF;
	  return CRC8SAEJ1850(buffer,3);
	  /**********Zhiyuan HU 20190313**************/
}

void GetLightTransmission(byte trans_550nm,byte trans_880nm)
{
  byte rb_880nm_Transmission_local_Coding = 0;
  byte rb_550nm_Transmission_local_Coding = 0;
  byte rb_550nm_Transmission_local_Coding_outOfRangeFlag = 0;
  byte rb_880nm_Transmission_local_Coding_outOfRangeFlag = 0;
  
  rb_550nm_Transmission_local_Coding = (trans_550nm);
  rb_550nm_Transmission_local_Coding = (((rb_550nm_Transmission_local_Coding > 90) && (rb_550nm_Transmission_local_Coding <= 100))? 90 : rb_550nm_Transmission_local_Coding);
  
  rb_880nm_Transmission_local_Coding = (trans_880nm);
  rb_880nm_Transmission_local_Coding = (((rb_880nm_Transmission_local_Coding > 90) && (rb_880nm_Transmission_local_Coding <= 100))? 90 : rb_880nm_Transmission_local_Coding);
  
  if((rb_550nm_Transmission_local_Coding >= 15) && (rb_550nm_Transmission_local_Coding <= 90))
  {
    rb_550nm_Transmission_local_Coding = ((rb_550nm_Transmission_local_Coding-15) + 2) / 5; 
    rb_550nm_Transmission_local_Coding_outOfRangeFlag = 0;
    
  }
  else
  {
    rb_550nm_Transmission_local_Coding = 0 ; 
    rb_550nm_Transmission_local_Coding_outOfRangeFlag =1;
  }
  
  
  if((rb_880nm_Transmission_local_Coding >= 15) && (rb_880nm_Transmission_local_Coding <= 90))
  {
    rb_880nm_Transmission_local_Coding = ((rb_880nm_Transmission_local_Coding-15) + 2) / 5; 
    rb_880nm_Transmission_local_Coding_outOfRangeFlag = 0;
  }
  else
  {
    rb_880nm_Transmission_local_Coding = 0 ;
    rb_880nm_Transmission_local_Coding_outOfRangeFlag = 1;
  }
  
  if(rb_550nm_Transmission_local_Coding_outOfRangeFlag == 1 || rb_880nm_Transmission_local_Coding_outOfRangeFlag == 1)
  {
      {RlsmCem_Lin1Fr01_CEM_LIN1 . rlsmcem_lin1fr01_cem_lin1 . RainSnsrErrCalErr_CEM_LIN1 = 1;};    
  }
  else
  {
     {RlsmCem_Lin1Fr01_CEM_LIN1 . rlsmcem_lin1fr01_cem_lin1 . RainSnsrErrCalErr_CEM_LIN1 = 0;};
  }
  
  
  if(((rb_550nm_Transmission_local_Coding_outOfRangeFlag == 0) && (rb_880nm_Transmission_local_Coding_outOfRangeFlag == 0))
         && (EEPROM_Struct_PD . EEPROMStructPD . EEKodierbyte2_g != ((rb_880nm_Transmission_local_Coding << 4) | rb_550nm_Transmission_local_Coding))
         && ((uF_Main_Flags_g . Bit . B2 == 0)||(uF_Main_Flags_g . Bit . B1 == 1)))
  {
      rab_EEPROM_Bytes_toWrite_g[0] = ((rb_880nm_Transmission_local_Coding << 4) | rb_550nm_Transmission_local_Coding);
      rw_EEPROM_Address_to_Write_g = (268); /*set adress to write*/
      rb_I2C_EEPROM_bytesToWrite_g = 1;         /*set number of bytes to 1*/
      uF_Main_Flags_g . Bit . B2 = 1;
      uF_Main_Flags_g . Bit . B1 = 0;
  }
}

void Get_BCMVehType(byte CarType)
{
  
  static byte rb_VehTypeValueDebounce = 0;
  byte rb_Kodierbyte1_Update_g ; 
  byte rb_BaseType ;// 0 to 3 rain config
  
  if(rb_VehTypeValueDebounce < 20)//if 100MS run once ,2s delay check
  {
      rb_VehTypeValueDebounce ++;
      return ;
  }
   /*check if the E2PROM data has been loaded*/
  if(uF_Main_Flags_g . Bit . B6 == 1)
  {
    return ;
  }
  
  rb_Kodierbyte1_Update_g = EEPROM_Struct_PD . EEPROMStructPD . EEKodierbyte1_g;
  rb_BaseType  = CarType/4;
  
  if((rb_BaseType < 4)&& ( ((rb_Kodierbyte1_Update_g & 12)>>2)!= rb_BaseType)&& ((uF_Main_Flags_g . Bit . B2 == 0)||(uF_Main_Flags_g . Bit . B1 == 1)))
  {
      rb_Kodierbyte1_Update_g &=0xF3; //Clear 2 and 3 bit
      rb_Kodierbyte1_Update_g |=(rb_BaseType << 2); //set
      rab_EEPROM_Bytes_toWrite_g[0] = rb_Kodierbyte1_Update_g;
      rw_EEPROM_Address_to_Write_g = (268)+1; /*set adress to write*/
      rb_I2C_EEPROM_bytesToWrite_g = 1;         /*set number of bytes to 1*/
      uF_Main_Flags_g . Bit . B2 = 1;
      uF_Main_Flags_g . Bit . B1 = 0;
  }
  
}

void Set_BCMLightOffset(byte offset)
{
  
  static byte rb_lightValueDebounce = 0;
  byte rb_OldSensorLs ;
  byte rb_Kodierbyte0_Update_g; 
   
  if(rb_lightValueDebounce < 20)//if 100MS run once ,2s delay check
  {
      rb_lightValueDebounce ++;
      return ;
  }
  
  /*check if the E2PROM data has been loaded*/
  if(uF_Main_Flags_g . Bit . B6 == 1)
  {
     return ;
  }
  
  rb_OldSensorLs = (EEPROM_Struct_PD . EEPROMStructPD . EEKodierbyte0_g& 0x38)>>3;
  rb_Kodierbyte0_Update_g = EEPROM_Struct_PD . EEPROMStructPD . EEKodierbyte0_g; 
  
  if((offset < 8)&& (rb_OldSensorLs != offset)&& ((uF_Main_Flags_g . Bit . B2 == 0)||(uF_Main_Flags_g . Bit . B1 == 1)))
  {
      rb_Kodierbyte0_Update_g &=0xC7; 
      rb_Kodierbyte0_Update_g |=(offset << 3); 
      rab_EEPROM_Bytes_toWrite_g[0] = rb_Kodierbyte0_Update_g;
      rw_EEPROM_Address_to_Write_g = (268)+2; 
      rb_I2C_EEPROM_bytesToWrite_g = 1;         
      uF_Main_Flags_g . Bit . B2 = 1;
      uF_Main_Flags_g . Bit . B1 = 0;
  }
  
}


void SendRLSSerNo(void)
{
    {RlsmCem_SerNrLin1Fr01_CEM_LIN1 . rlsmcem_sernrlin1fr01_cem_lin1 . RLSMSerNoNr1_CEM_LIN1 = (EEPROM_Struct_PD . EEPROMStructPD . Produktionsdaten[(0)]);};
    {RlsmCem_SerNrLin1Fr01_CEM_LIN1 . rlsmcem_sernrlin1fr01_cem_lin1 . RLSMSerNoNr2_CEM_LIN1 = (EEPROM_Struct_PD . EEPROMStructPD . Produktionsdaten[(1)]);};
    {RlsmCem_SerNrLin1Fr01_CEM_LIN1 . rlsmcem_sernrlin1fr01_cem_lin1 . RLSMSerNoNr3_CEM_LIN1 = (EEPROM_Struct_PD . EEPROMStructPD . Produktionsdaten[(2)]);};
    {RlsmCem_SerNrLin1Fr01_CEM_LIN1 . rlsmcem_sernrlin1fr01_cem_lin1 . RLSMSerNoNr4_CEM_LIN1 = (EEPROM_Struct_PD . EEPROMStructPD . Produktionsdaten[(3)]);};
}


void SendRLSMPartNo(void)
{
    {RlsmCem_Lin1PartNrFr01_CEM_LIN1 . rlsmcem_lin1partnrfr01_cem_lin1 . RLSMPartNoNr1_CEM_LIN1 = (EEPROM_Struct_PD . EEPROMStructPD . Audi_HW_Partnumber[(0)]);};
    {RlsmCem_Lin1PartNrFr01_CEM_LIN1 . rlsmcem_lin1partnrfr01_cem_lin1 . RLSMPartNoNr2_CEM_LIN1 = (EEPROM_Struct_PD . EEPROMStructPD . Audi_HW_Partnumber[(1)]);};
    {RlsmCem_Lin1PartNrFr01_CEM_LIN1 . rlsmcem_lin1partnrfr01_cem_lin1 . RLSMPartNoNr3_CEM_LIN1 = (EEPROM_Struct_PD . EEPROMStructPD . Audi_HW_Partnumber[(2)]);};
    {RlsmCem_Lin1PartNrFr01_CEM_LIN1 . rlsmcem_lin1partnrfr01_cem_lin1 . RLSMPartNoNr4_CEM_LIN1 = (EEPROM_Struct_PD . EEPROMStructPD . Audi_HW_Partnumber[(3)]);};
    {RlsmCem_Lin1PartNrFr01_CEM_LIN1 . rlsmcem_lin1partnrfr01_cem_lin1 . RLSMPartNoEndSgn1_CEM_LIN1 = (EEPROM_Struct_PD . EEPROMStructPD . Audi_HW_Partnumber[(5)]);};
    {RlsmCem_Lin1PartNrFr01_CEM_LIN1 . rlsmcem_lin1partnrfr01_cem_lin1 . RLSMPartNoEndSgn2_CEM_LIN1 = (EEPROM_Struct_PD . EEPROMStructPD . Audi_HW_Partnumber[(6)]);};
    {RlsmCem_Lin1PartNrFr01_CEM_LIN1 . rlsmcem_lin1partnrfr01_cem_lin1 . RLSMPartNoEndSgn3_CEM_LIN1 = (EEPROM_Struct_PD . EEPROMStructPD . Audi_HW_Partnumber[(7)]);};
}

void SendRLSMPartNo10(void)
{
    {RlsmCem_Lin1PartNrFr02_CEM_LIN1 . rlsmcem_lin1partnrfr02_cem_lin1 . RLSMPartNo10Nr1_CEM_LIN1 = (EEPROM_Struct_PD . EEPROMStructPD . Audi_HW_Partnumber[(0)]);};
    {RlsmCem_Lin1PartNrFr02_CEM_LIN1 . rlsmcem_lin1partnrfr02_cem_lin1 . RLSMPartNo10Nr2_CEM_LIN1 = (EEPROM_Struct_PD . EEPROMStructPD . Audi_HW_Partnumber[(1)]);};
    {RlsmCem_Lin1PartNrFr02_CEM_LIN1 . rlsmcem_lin1partnrfr02_cem_lin1 . RLSMPartNo10Nr3_CEM_LIN1 = (EEPROM_Struct_PD . EEPROMStructPD . Audi_HW_Partnumber[(2)]);};
    {RlsmCem_Lin1PartNrFr02_CEM_LIN1 . rlsmcem_lin1partnrfr02_cem_lin1 . RLSMPartNo10Nr4_CEM_LIN1 = (EEPROM_Struct_PD . EEPROMStructPD . Audi_HW_Partnumber[(3)]);};
    {RlsmCem_Lin1PartNrFr02_CEM_LIN1 . rlsmcem_lin1partnrfr02_cem_lin1 . RLSMPartNo10Nr5_CEM_LIN1 = (EEPROM_Struct_PD . EEPROMStructPD . Audi_HW_Partnumber[(4)]);};
    {RlsmCem_Lin1PartNrFr02_CEM_LIN1 . rlsmcem_lin1partnrfr02_cem_lin1 . RLSMPartNo10EndSgn1_CEM_LIN1 = (EEPROM_Struct_PD . EEPROMStructPD . Audi_HW_Partnumber[(5)]);};
    {RlsmCem_Lin1PartNrFr02_CEM_LIN1 . rlsmcem_lin1partnrfr02_cem_lin1 . RLSMPartNo10EndSgn2_CEM_LIN1 = (EEPROM_Struct_PD . EEPROMStructPD . Audi_HW_Partnumber[(6)]);};
    {RlsmCem_Lin1PartNrFr02_CEM_LIN1 . rlsmcem_lin1partnrfr02_cem_lin1 . RLSMPartNo10EndSgn3_CEM_LIN1 = (EEPROM_Struct_PD . EEPROMStructPD . Audi_HW_Partnumber[(7)]);};
}

/************************************************Winter mode check************************************************/
/**************************T < 0 degree and Speed is under 5KM/H.*************************************************/
void WipeWinterModeCheck(void)
{  
  if((rb_speed_in_kmh_g < 5) && (rb_OutsideTemp_mg <= 0))
  {
     rb_WipeWorkStatus_mg = 2;
  }
  else
  {
     rb_WipeWorkStatus_mg = 1;
  }  
}

/*!
 * @brief 判断当前byte的极性是否为偶
 *
 * @param byte， 待计算奇偶性的数据.
 * @retval false  byte极性(含1的个数)为奇数.
 * @retval ture， byte极性(含1的个数)为偶数.
 */
byte IsByteOddParity(byte data)
{
    byte parity = 0;
   
    while (data)
    {
        parity = !parity;
        data &= data - 1;
    }
    return !parity;
}

#line 6 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\vcast_preprocess.11684.16.c"

typedef int VECTORCAST_MARKER__UNIT_APPENDIX_START;

typedef int VECTORCAST_MARKER__UNIT_APPENDIX_END;

typedef int VECTORCAST_MARKER__USER_GLOBALS_START;
#line 18 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\vcast_preprocess.11684.16.c"

/*****************************************************************************
S0000008.c: This file contains the definitions of variables used in user code.
Preface all variable declarations with VCAST_USER_GLOBALS_EXTERN to ensure 
that only one definition of the variable is created in the test harness. 
*****************************************************************************/








  extern int VECTORCAST_INT1;
  extern int VECTORCAST_INT2;
  extern int VECTORCAST_INT3;

  extern float VECTORCAST_FLT1;

  extern char VECTORCAST_STR1[8];

  extern int  VECTORCAST_BUFFER[4];







typedef int VECTORCAST_MARKER__USER_GLOBALS_END;

typedef int VECTORCAST_MARKER__DRIVER_START;
#line 1 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\S0000009.c"
/***********************************************
 *      VectorCAST Test Harness Component      *
 *     Copyright 2020 Vector Software, Inc.    *
 *               6.4t (05/31/17)               *
 ***********************************************/
/***********************************************
 * VectorCAST Unit Information
 *
 * Name: G5_RLS_LIN_GEELY2DOT0
 *
 * Path: C:/baseline/RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0__0006_E3/05_SwDev/01_SrcCode/Application/CustomerInterface/G5_RLS_LIN_GEELY2DOT0.c
 *
 * Type: uut
 *
 * Unit Number: 9
 *
 ***********************************************/
#line 1 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\vcast_env_defines.h"
#line 27 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\S0000009.c"
#line 1 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\G5_RLS_LIN_GEELY2DOT0_driver_prefix.c"

#line 63 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\S0000009.c"
#line 1 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\S0000009.h"
/***********************************************
 *      VectorCAST Test Harness Component      *
 *     Copyright 2020 Vector Software, Inc.    *
 *               6.4t (05/31/17)               *
 ***********************************************/



#line 1 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\B0000001.h"
/***********************************************
 *      VectorCAST Test Harness Component      *
 *     Copyright 2020 Vector Software, Inc.    *
 *               6.4t (05/31/17)               *
 ***********************************************/



#line 1 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\S0000007.h"
/***********************************************
 *      VectorCAST Test Harness Component      *
 *     Copyright 2020 Vector Software, Inc.    *
 *               6.4t (05/31/17)               *
 ***********************************************/




/* ----------------------------------------------------------------------------
-- VectorCAST IO File
-- 
-- DISCLAIMER :
-- This file is provided "AS IS"  by  for the convenience of Vector Software.
-- Inconsistent modifications may cause VectorCAST to fail to work properly
-- 
-------------------------------------------------------------------------------*/

/* setup for "long long" capability */
#line 53 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\S0000007.h"
/* end "long long" check */

#line 61 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\S0000007.h"

#line 1 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\vcast_basics.h"
/***********************************************
 *      VectorCAST Test Harness Component      *
 *     Copyright 2020 Vector Software, Inc.    *
 *               6.4t (05/31/17)               *
 ***********************************************/
#line 63 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\S0000007.h"

#line 70 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\S0000007.h"

#line 82 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\S0000007.h"








/* ----------------------------------------------------------------------------
-- These funtions are called at the start and end of the test harenss
-- and contain conditionally compiled code to setup for the particular I/O
-- mode and in some case the particular target.
-------------------------------------------------------------------------------*/
void vectorcast_initialize_io (int inst_status, int inst_fd);
void vectorcast_terminate_io (void);
void vectorcast_write_vcast_end (void);

int  vectorcast_fflush(int fpn);

void vectorcast_fclose(int fpn);
int  vectorcast_feof(int fpn);
int  vectorcast_fopen(char *filename, char *mode);
char *vectorcast_fgets (char *line, int maxline, int fpn);


/* return failure condition if the line we read is too long */
int vectorcast_readline(char *vcast_buf, int fpn);

void vectorcast_fprint_char   (int fpn, char vcast_str);
void vectorcast_fprint_char_hex ( int fpn, char vcast_value );
void vectorcast_fprint_char_octl ( int fpn, char vcast_value );

void vectorcast_fprint_string (int fpn, const char *vcast_str);
void vectorcast_fprint_string_with_cr (int fpn, const char *vcast_str);
void vectorcast_print_string (const char *vcast_str);
void vectorcast_fprint_string_with_length(int fpn, const char *vcast_str, int length);

void vectorcast_fprint_short     (int vcast_fpn, short vcast_value );
void vectorcast_fprint_integer   (int vcast_fpn, int vcast_value );
void vectorcast_fprint_long      (int vcast_fpn, long vcast_value );
void vectorcast_fprint_long_long (int vcast_fpn, long vcast_value );

void vectorcast_fprint_unsigned_short (int vcast_fpn,
                                       unsigned short vcast_value );
void vectorcast_fprint_unsigned_integer (int vcast_fpn,
                                         unsigned int vcast_value );
void vectorcast_fprint_unsigned_long (int vcast_fpn,
                                      unsigned long vcast_value );
void vectorcast_fprint_unsigned_long_long (int vcast_fpn,
                                           unsigned long vcast_value );

void vectorcast_fprint_long_float (int fpn, vCAST_long_double);

/* numeric conversion routines */
void vcast_signed_to_string ( char vcDest[],
                              long vcSrc );
void vcast_unsigned_to_string ( char vcDest[],
                                unsigned long vcSrc );
void vcast_float_to_string ( char *mixed_str, vCAST_long_double f );


/* ----------------------------------------------------------------------------
-- API for Harness Trace Functions
-----------------------------------------------------------------------------*/

/* To write output, the normal API is: vectorcast_print_string
   vectorcast_write_to_std_out should only be used for abnormal termination
   and debug trace messages */
void vectorcast_write_to_std_out (const char *s);




/*---------------------------------------------------------------------------*/


#line 164 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\S0000007.h"
void vcast_char_to_based_string ( char vcDest[],
                                  unsigned char vcSrc,
                                  unsigned vcUseHex );

/* ----------------------------------------------------------------------------
-- To Save Output Size, for some targets using stdout mode, we output a 
-- number rather than a filename.  So for example, we put out: 
-- "1: data" instead of: "ASCIIRES.DAT: data"
-- JJP TBD: Not sure why this needs to be in the header --
-------------------------------------------------------------------------------*/
enum vcast_env_file_kind
{
   VCAST_ASCIIRES_DAT = 1,
   VCAST_EXPECTED_DAT = 2,
   VCAST_TEMP_DIF_DAT = 3,
   VCAST_TESTINSS_DAT = 4,
   VCAST_THISTORY_DAT = 5,
   VCAST_USERDATA_DAT = 6
};


/* Get the name of the file */
char *vcast_get_filename(enum vcast_env_file_kind kind);




/* ----------------------------------------------------------------------------
-- Need to evaluate these items
-- JJP TBD
-------------------------------------------------------------------------------*/

void vectorcast_set_index(int index, int fpn);
int vectorcast_get_index(int fpn);








struct VCAST_Allocated_Data
{
  void *allocated;
  struct VCAST_Allocated_Data *next;
};
void VCAST_Add_Allocated_Data(void * vcast_data_ptr);
extern struct VCAST_Allocated_Data *VCAST_allocated_data_list;



void vectorcast_longest_int_to_str(long vcast_value, char *vcast_str);



/* -------------------------------------------------------------------------------*/
/* -------------------------------------------------------------------------------*/


/* End of File, close the Extern C block */




#line 236 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\S0000007.h"

#line 13 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\B0000001.h"
#line 1 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\S0000002.h"
#line 1 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\S0000008.h"
#line 4 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\S0000002.h"




extern int vCAST_ITERATION_COUNTERS [3][45];



#line 27 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\S0000002.h"
extern vCAST_array_boolean vCAST_GLOBALS_TOUCHED[6];




enum vCAST_testcase_options_type {
        vCAST_MULTI_RETURN_SPANS_RANGE,
        vCAST_MULTI_RETURN_SPANS_COMPOUND_ITERATIONS,
        vCAST_DISPLAY_INTEGER_RESULTS_IN_HEX,
        vCAST_DISPLAY_FULL_STRING_DATA,
        vCAST_HEX_NOTATION_FOR_UNPRINTABLE_CHARS,
        vCAST_DO_COMBINATION,
        vCAST_REFERENCED_GLOBALS,
        vCAST_FLOAT_POINT_DIGITS_OF_PRECISION,
        vCAST_FLOAT_POINT_TOLERANCE,
        vCAST_EVENT_LIMIT,
        vCAST_GLOBAL_DATA_DISPLAY,
        vCAST_EXPECTED_BEFORE_UUT_CALL,
        vCAST_DATA_PARTITIONS,
        vCAST_SHOW_ONLY_DATA_WITH_EXPECTED_RESULTS,
        vCAST_SHOW_ONLY_EVENTS_WITH_EXPECTED_RESULTS};

enum vCAST_globals_display_type {
        vCAST_EACH_EVENT,
        vCAST_RANGE_ITERATION,
        vCAST_SLOT_ITERATION,
        vCAST_TESTCASE};

















#line 1 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\S0000004.h"
/***********************************************
 *      VectorCAST Test Harness Component      *
 *     Copyright 2020 Vector Software, Inc.    *
 *               6.4t (05/31/17)               *
 ***********************************************/

/*************************************************************************
File : S0000004.c
Description : This file contains the declarations of functions in the 
   B0000004.c file.
***************************************************************************/



#line 1 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\S0000002.h"
#line 16 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\S0000004.h"




void vCAST_INITIALIZE_PARAMETERS(void);
void vCAST_USER_CODE_INITIALIZE(int vcast_slot_index, vCAST_boolean commands_read);
void vCAST_USER_CODE_CAPTURE (void);
void vCAST_USER_CODE_CAPTURE_GLOBALS (void);

void vCAST_ONE_SHOT_INIT(void);
void vCAST_ONE_SHOT_TERM(void);

void vCAST_GLOBAL_STUB_PROCESSING(void);
void vCAST_GLOBAL_BEGINNING_OF_STUB_PROCESSING(void);

typedef enum {
   VCAST_UCT_VALUE,
   VCAST_UCT_EXPECTED,
   VCAST_UCT_EXPECTED_GLOBALS
} VCAST_USER_CODE_TYPE;

void vCAST_USER_CODE( VCAST_USER_CODE_TYPE uct, int vcast_slot_index );

#line 47 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\S0000004.h"

#line 72 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\S0000002.h"

#line 1 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\VCAST_STRING.h"
/***********************************************
 *      VectorCAST Test Harness Component      *
 *     Copyright 2020 Vector Software, Inc.    *
 *               6.4t (05/31/17)               *
 ***********************************************/



#line 21 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\VCAST_STRING.h"

#line 1 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 7.0\\rl78\\inc\\c\\stdlib.h"
/* stdlib.h standard header */
/* Copyright 2005-2010 IAR Systems AB. */








#line 1 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 7.0\\rl78\\inc\\c\\ycheck.h"
/* ycheck.h internal checking header file. */
/* Copyright 2005-2010 IAR Systems AB. */

/* Note that there is no include guard for this header. This is intentional. */





/* __INTRINSIC
 *
 * Note: Redefined each time ycheck.h is included, i.e. for each
 * system header, to ensure that intrinsic support could be turned off
 * individually for each file.
 */










/* __RL78ABI_PORTABILITY_INTERNAL_LEVEL
 *
 * Note: Redefined each time ycheck.h is included, i.e. for each
 * system header, to ensure that ABI support could be turned off/on
 * individually for each file.
 *
 * Possible values for this preprocessor symbol:
 *
 * 0 - ABI portability mode is disabled.
 *
 * 1 - ABI portability mode (version 1) is enabled.
 *
 * All other values are reserved for future use.
 */






#line 67 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 7.0\\rl78\\inc\\c\\ycheck.h"




/* A definiton for a function of what effects it has.
   NS  = no_state, i.e. it uses no internal or external state. It may write
         to errno though
   NE  = no_state, no_errno,  i.e. it uses no internal or external state,
         not even writing to errno. 
   NRx = no_read(x), i.e. it doesn't read through pointer parameter x.
   NWx = no_write(x), i.e. it doesn't write through pointer parameter x.
*/

#line 99 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 7.0\\rl78\\inc\\c\\ycheck.h"









#line 12 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 7.0\\rl78\\inc\\c\\stdlib.h"
#line 1 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 7.0\\rl78\\inc\\c\\yvals.h"
/* yvals.h internal configuration header file. */
/* Copyright 2001-2010 IAR Systems AB. */








#line 1 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 7.0\\rl78\\inc\\c\\ycheck.h"
/* ycheck.h internal checking header file. */
/* Copyright 2005-2010 IAR Systems AB. */

/* Note that there is no include guard for this header. This is intentional. */





/* __INTRINSIC
 *
 * Note: Redefined each time ycheck.h is included, i.e. for each
 * system header, to ensure that intrinsic support could be turned off
 * individually for each file.
 */










/* __RL78ABI_PORTABILITY_INTERNAL_LEVEL
 *
 * Note: Redefined each time ycheck.h is included, i.e. for each
 * system header, to ensure that ABI support could be turned off/on
 * individually for each file.
 *
 * Possible values for this preprocessor symbol:
 *
 * 0 - ABI portability mode is disabled.
 *
 * 1 - ABI portability mode (version 1) is enabled.
 *
 * All other values are reserved for future use.
 */






#line 67 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 7.0\\rl78\\inc\\c\\ycheck.h"

#line 12 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 7.0\\rl78\\inc\\c\\yvals.h"

                /* Convenience macros */









/* Used to refer to '__rl78abi' symbols in the library. */ 


                /* Versions */










/*
 * Support for some C99 or other symbols
 *
 * This setting makes available some macros, functions, etc that are
 * beneficial.
 *
 * Default is to include them.
 *
 * Disabling this in C++ mode will not compile (some C++ functions uses C99
 * functionality).
 */


  /* Default turned on when compiling C++, EC++, or C99. */
#line 59 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 7.0\\rl78\\inc\\c\\yvals.h"





#line 70 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 7.0\\rl78\\inc\\c\\yvals.h"

                /* Configuration */
#line 1 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 7.0\\rl78\\inc\\c\\DLib_Defaults.h"
/***************************************************
 *
 * DLib_Defaults.h is the library configuration manager.
 *
 * Copyright 2003-2010 IAR Systems AB.  
 *
 * This configuration header file performs the following tasks:
 *
 * 1. Includes the configuration header file, defined by _DLIB_CONFIG_FILE,
 *    that sets up a particular runtime environment.
 *
 * 2. Includes the product configuration header file, DLib_Product.h, that
 *    specifies default values for the product and makes sure that the
 *    configuration is valid.
 *
 * 3. Sets up default values for all remaining configuration symbols.
 *
 * This configuration header file, the one defined by _DLIB_CONFIG_FILE, and
 * DLib_Product.h configures how the runtime environment should behave. This
 * includes all system headers and the library itself, i.e. all system headers
 * includes this configuration header file, and the library has been built
 * using this configuration header file.
 *
 ***************************************************
 *
 * DO NOT MODIFY THIS FILE!
 *
 ***************************************************/








/* Include the main configuration header file. */
#line 1 "C:\\\\PROGRAM FILES (X86)\\\\IAR SYSTEMS\\\\EMBEDDED WORKBENCH 7.0\\\\RL78\\\\LIB\\DLib_Config_Normal.h"
/* Customer-specific DLib configuration. */
/* Copyright (C) 2003 IAR Systems.  All rights reserved. */








/* No changes to the defaults. */

#line 40 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 7.0\\rl78\\inc\\c\\DLib_Defaults.h"
  /* _DLIB_CONFIG_FILE_STRING is the quoted variant of above */
#line 47 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 7.0\\rl78\\inc\\c\\DLib_Defaults.h"

/* Include the product specific header file. */
#line 1 "C:\\\\PROGRAM FILES (X86)\\\\IAR SYSTEMS\\\\EMBEDDED WORKBENCH 7.0\\\\RL78\\\\INC\\DLib_Product.h"
/* RL78 DLib configuration. */
/* Copyright 2011 IAR Systems AB. */










/* the DIFUNCT segment is located in far data memory */


/* No thread support in DLIB */


#line 51 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 7.0\\rl78\\inc\\c\\DLib_Defaults.h"



/*
 * The remainder of the file sets up defaults for a number of
 * configuration symbols, each corresponds to a feature in the
 * libary.
 *
 * The value of the symbols should either be 1, if the feature should
 * be supported, or 0 if it shouldn't. (Except where otherwise
 * noted.)
 */


/*
 * Small or Large target
 *
 * This define determines whether the target is large or small. It must be 
 * setup in the DLib_Product header or in the compiler itself.
 *
 * For a small target some functionality in the library will not deliver 
 * the best available results. For instance the _accurate variants will not use
 * the extra precision packet for large arguments.
 * 
 */







/*
 * File handling
 *
 * Determines whether FILE descriptors and related functions exists or not.
 * When this feature is selected, i.e. set to 1, then FILE descriptors and
 * related functions (e.g. fprintf, fopen) exist. All files, even stdin,
 * stdout, and stderr will then be handled with a file system mechanism that
 * buffers files before accessing the lowlevel I/O interface (__open, __read,
 * __write, etc).
 *
 * If not selected, i.e. set to 0, then FILE descriptors and related functions
 * (e.g. fprintf, fopen) does not exist. All functions that normally uses
 * stderr will use stdout instead. Functions that uses stdout and stdin (like
 * printf and scanf) will access the lowlevel I/O interface directly (__open,
 * __read, __write, etc), i.e. there will not be any buffering.
 *
 * The default is not to have support for FILE descriptors.
 */





/*
 * Use static buffers for stdout
 *
 * This setting controls whether the stream stdout uses a static 80 bytes
 * buffer or uses a one byte buffer allocated in the file descriptor. This
 * setting is only applicable if the FILE descriptors are enabled above.
 *
 * Default is to use a static 80 byte buffer.
 */





/*
 * Support of locale interface
 *
 * "Locale" is the system in C that support language- and
 * contry-specific settings for a number of areas, including currency
 * symbols, date and time, and multibyte encodings.
 *
 * This setting determines whether the locale interface exist or not.
 * When this feature is selected, i.e. set to 1, the locale interface exist
 * (setlocale, etc). A number of preselected locales can be activated during
 * runtime. The preselected locales and encodings is choosen by defining any
 * number of _LOCALE_USE_xxx and _ENCODING_USE_xxx symbols. The application
 * will start with the "C" locale choosen. (Single byte encoding is always
 * supported in this mode.)
 *
 *
 * If not selected, i.e. set to 0, the locale interface (setlocale, etc) does
 * not exist. One preselected locale and one preselected encoding is then used
 * directly. That locale can not be changed during runtime. The preselected
 * locale and encoding is choosen by defining at most one of _LOCALE_USE_xxx
 * and at most one of _ENCODING_USE_xxx. The default is to use the "C" locale
 * and the single byte encoding, respectively.
 *
 * The default is not to have support for the locale interface with the "C"
 * locale and the single byte encoding.
 *
 * Supported locales
 * -----------------
 * _LOCALE_USE_C                  C standard locale (the default)
 * _LOCALE_USE_POSIX ISO-8859-1   Posix locale
 * _LOCALE_USE_CS_CZ ISO-8859-2   Czech language locale for Czech Republic
 * _LOCALE_USE_DA_DK ISO-8859-1   Danish language locale for Denmark
 * _LOCALE_USE_DA_EU ISO-8859-15  Danish language locale for Europe
 * _LOCALE_USE_DE_AT ISO-8859-1   German language locale for Austria
 * _LOCALE_USE_DE_BE ISO-8859-1   German language locale for Belgium
 * _LOCALE_USE_DE_CH ISO-8859-1   German language locale for Switzerland
 * _LOCALE_USE_DE_DE ISO-8859-1   German language locale for Germany
 * _LOCALE_USE_DE_EU ISO-8859-15  German language locale for Europe
 * _LOCALE_USE_DE_LU ISO-8859-1   German language locale for Luxemburg
 * _LOCALE_USE_EL_EU ISO-8859-7x  Greek language locale for Europe
 *                                (Euro symbol added)
 * _LOCALE_USE_EL_GR ISO-8859-7   Greek language locale for Greece
 * _LOCALE_USE_EN_AU ISO-8859-1   English language locale for Australia
 * _LOCALE_USE_EN_CA ISO-8859-1   English language locale for Canada
 * _LOCALE_USE_EN_DK ISO_8859-1   English language locale for Denmark
 * _LOCALE_USE_EN_EU ISO-8859-15  English language locale for Europe
 * _LOCALE_USE_EN_GB ISO-8859-1   English language locale for United Kingdom
 * _LOCALE_USE_EN_IE ISO-8859-1   English language locale for Ireland
 * _LOCALE_USE_EN_NZ ISO-8859-1   English language locale for New Zealand
 * _LOCALE_USE_EN_US ISO-8859-1   English language locale for USA
 * _LOCALE_USE_ES_AR ISO-8859-1   Spanish language locale for Argentina
 * _LOCALE_USE_ES_BO ISO-8859-1   Spanish language locale for Bolivia
 * _LOCALE_USE_ES_CL ISO-8859-1   Spanish language locale for Chile
 * _LOCALE_USE_ES_CO ISO-8859-1   Spanish language locale for Colombia
 * _LOCALE_USE_ES_DO ISO-8859-1   Spanish language locale for Dominican Republic
 * _LOCALE_USE_ES_EC ISO-8859-1   Spanish language locale for Equador
 * _LOCALE_USE_ES_ES ISO-8859-1   Spanish language locale for Spain
 * _LOCALE_USE_ES_EU ISO-8859-15  Spanish language locale for Europe
 * _LOCALE_USE_ES_GT ISO-8859-1   Spanish language locale for Guatemala
 * _LOCALE_USE_ES_HN ISO-8859-1   Spanish language locale for Honduras
 * _LOCALE_USE_ES_MX ISO-8859-1   Spanish language locale for Mexico
 * _LOCALE_USE_ES_PA ISO-8859-1   Spanish language locale for Panama
 * _LOCALE_USE_ES_PE ISO-8859-1   Spanish language locale for Peru
 * _LOCALE_USE_ES_PY ISO-8859-1   Spanish language locale for Paraguay
 * _LOCALE_USE_ES_SV ISO-8859-1   Spanish language locale for Salvador
 * _LOCALE_USE_ES_US ISO-8859-1   Spanish language locale for USA
 * _LOCALE_USE_ES_UY ISO-8859-1   Spanish language locale for Uruguay
 * _LOCALE_USE_ES_VE ISO-8859-1   Spanish language locale for Venezuela
 * _LOCALE_USE_ET_EE ISO-8859-1   Estonian language for Estonia
 * _LOCALE_USE_EU_ES ISO-8859-1   Basque language locale for Spain
 * _LOCALE_USE_FI_EU ISO-8859-15  Finnish language locale for Europe
 * _LOCALE_USE_FI_FI ISO-8859-1   Finnish language locale for Finland
 * _LOCALE_USE_FO_FO ISO-8859-1   Faroese language locale for Faroe Islands
 * _LOCALE_USE_FR_BE ISO-8859-1   French language locale for Belgium
 * _LOCALE_USE_FR_CA ISO-8859-1   French language locale for Canada
 * _LOCALE_USE_FR_CH ISO-8859-1   French language locale for Switzerland
 * _LOCALE_USE_FR_EU ISO-8859-15  French language locale for Europe
 * _LOCALE_USE_FR_FR ISO-8859-1   French language locale for France
 * _LOCALE_USE_FR_LU ISO-8859-1   French language locale for Luxemburg
 * _LOCALE_USE_GA_EU ISO-8859-15  Irish language locale for Europe
 * _LOCALE_USE_GA_IE ISO-8859-1   Irish language locale for Ireland
 * _LOCALE_USE_GL_ES ISO-8859-1   Galician language locale for Spain
 * _LOCALE_USE_HR_HR ISO-8859-2   Croatian language locale for Croatia
 * _LOCALE_USE_HU_HU ISO-8859-2   Hungarian language locale for Hungary
 * _LOCALE_USE_ID_ID ISO-8859-1   Indonesian language locale for Indonesia
 * _LOCALE_USE_IS_EU ISO-8859-15  Icelandic language locale for Europe
 * _LOCALE_USE_IS_IS ISO-8859-1   Icelandic language locale for Iceland
 * _LOCALE_USE_IT_EU ISO-8859-15  Italian language locale for Europe
 * _LOCALE_USE_IT_IT ISO-8859-1   Italian language locale for Italy
 * _LOCALE_USE_IW_IL ISO-8859-8   Hebrew language locale for Israel
 * _LOCALE_USE_KL_GL ISO-8859-1   Greenlandic language locale for Greenland
 * _LOCALE_USE_LT_LT   BALTIC     Lithuanian languagelocale for Lithuania
 * _LOCALE_USE_LV_LV   BALTIC     Latvian languagelocale for Latvia
 * _LOCALE_USE_NL_BE ISO-8859-1   Dutch language locale for Belgium
 * _LOCALE_USE_NL_EU ISO-8859-15  Dutch language locale for Europe
 * _LOCALE_USE_NL_NL ISO-8859-9   Dutch language locale for Netherlands
 * _LOCALE_USE_NO_EU ISO-8859-15  Norwegian language locale for Europe
 * _LOCALE_USE_NO_NO ISO-8859-1   Norwegian language locale for Norway
 * _LOCALE_USE_PL_PL ISO-8859-2   Polish language locale for Poland
 * _LOCALE_USE_PT_BR ISO-8859-1   Portugese language locale for Brazil
 * _LOCALE_USE_PT_EU ISO-8859-15  Portugese language locale for Europe
 * _LOCALE_USE_PT_PT ISO-8859-1   Portugese language locale for Portugal
 * _LOCALE_USE_RO_RO ISO-8859-2   Romanian language locale for Romania
 * _LOCALE_USE_RU_RU ISO-8859-5   Russian language locale for Russia
 * _LOCALE_USE_SL_SI ISO-8859-2   Slovenian language locale for Slovenia
 * _LOCALE_USE_SV_EU ISO-8859-15  Swedish language locale for Europe
 * _LOCALE_USE_SV_FI ISO-8859-1   Swedish language locale for Finland
 * _LOCALE_USE_SV_SE ISO-8859-1   Swedish language locale for Sweden
 * _LOCALE_USE_TR_TR ISO-8859-9   Turkish language locale for Turkey
 *
 *  Supported encodings
 *  -------------------
 * n/a                            Single byte (used if no other is defined).
 * _ENCODING_USE_UTF8             UTF8 encoding.
 */






/* We need to have the "C" locale if we have full locale support. */






/*
 * Support of multibytes in printf- and scanf-like functions
 *
 * This is the default value for _DLIB_PRINTF_MULTIBYTE and
 * _DLIB_SCANF_MULTIBYTE. See them for a description.
 *
 * Default is to not have support for multibytes in printf- and scanf-like
 * functions.
 */






/*
 * Throw handling in the EC++ library
 *
 * This setting determines what happens when the EC++ part of the library
 * fails (where a normal C++ library 'throws').
 *
 * The following alternatives exists (setting of the symbol):
 * 0                - The application does nothing, i.e. continues with the
 *                    next statement.
 * 1                - The application terminates by calling the 'abort'
 *                    function directly.
 * <anything else>  - An object of class "exception" is created.  This
 *                    object contains a string describing the problem.
 *                    This string is later emitted on "stderr" before
 *                    the application terminates by calling the 'abort'
 *                    function directly.
 *
 * Default is to do nothing.
 */






/*
 * Hexadecimal floating-point numbers in strtod
 *
 * If selected, i.e. set to 1, strtod supports C99 hexadecimal floating-point
 * numbers. This also enables hexadecimal floating-points in internal functions
 * used for converting strings and wide strings to float, double, and long
 * double.
 *
 * If not selected, i.e. set to 0, C99 hexadecimal floating-point numbers
 * aren't supported.
 *
 * Default is not to support hexadecimal floating-point numbers.
 */






/*
 * Printf configuration symbols.
 *
 * All the configuration symbols described further on controls the behaviour
 * of printf, sprintf, and the other printf variants.
 *
 * The library proves four formatters for printf: 'tiny', 'small',
 * 'large', and 'default'.  The setup in this file controls all except
 * 'tiny'.  Note that both small' and 'large' explicitly removes
 * some features.
 */

/*
 * Handle multibytes in printf
 *
 * This setting controls whether multibytes and wchar_ts are supported in
 * printf. Set to 1 to support them, otherwise set to 0.
 *
 * See _DLIB_FORMATTED_MULTIBYTE for the default setting.
 */





/*
 * Long long formatting in printf
 *
 * This setting controls long long support (%lld) in printf. Set to 1 to
 * support it, otherwise set to 0.

 * Note, if long long should not be supported and 'intmax_t' is larger than
 * an ordinary 'long', then %jd and %jn will not be supported.
 *
 * Default is to support long long formatting.
 */

#line 351 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 7.0\\rl78\\inc\\c\\DLib_Defaults.h"






/*
 * Floating-point formatting in printf
 *
 * This setting controls whether printf supports floating-point formatting.
 * Set to 1 to support them, otherwise set to 0.
 *
 * Default is to support floating-point formatting.
 */





/*
 * Hexadecimal floating-point formatting in printf
 *
 * This setting controls whether the %a format, i.e. the output of
 * floating-point numbers in the C99 hexadecimal format. Set to 1 to support
 * it, otherwise set to 0.
 *
 * Default is to support %a in printf.
 */





/*
 * Output count formatting in printf
 *
 * This setting controls whether the output count specifier (%n) is supported
 * or not in printf. Set to 1 to support it, otherwise set to 0.
 *
 * Default is to support %n in printf.
 */





/*
 * Support of qualifiers in printf
 *
 * This setting controls whether qualifiers that enlarges the input value
 * [hlLjtz] is supported in printf or not. Set to 1 to support them, otherwise
 * set to 0. See also _DLIB_PRINTF_INT_TYPE_IS_INT and
 * _DLIB_PRINTF_INT_TYPE_IS_LONG.
 *
 * Default is to support [hlLjtz] qualifiers in printf.
 */





/*
 * Support of flags in printf
 *
 * This setting controls whether flags (-+ #0) is supported in printf or not.
 * Set to 1 to support them, otherwise set to 0.
 *
 * Default is to support flags in printf.
 */





/*
 * Support widths and precisions in printf
 *
 * This setting controls whether widths and precisions are supported in printf.
 * Set to 1 to support them, otherwise set to 0.
 *
 * Default is to support widths and precisions in printf.
 */





/*
 * Support of unsigned integer formatting in printf
 *
 * This setting controls whether unsigned integer formatting is supported in
 * printf. Set to 1 to support it, otherwise set to 0.
 *
 * Default is to support unsigned integer formatting in printf.
 */





/*
 * Support of signed integer formatting in printf
 *
 * This setting controls whether signed integer formatting is supported in
 * printf. Set to 1 to support it, otherwise set to 0.
 *
 * Default is to support signed integer formatting in printf.
 */





/*
 * Support of formatting anything larger than int in printf
 *
 * This setting controls if 'int' should be used internally in printf, rather
 * than the largest existing integer type. If 'int' is used, any integer or
 * pointer type formatting use 'int' as internal type even though the
 * formatted type is larger. Set to 1 to use 'int' as internal type, otherwise
 * set to 0.
 *
 * See also next configuration.
 *
 * Default is to internally use largest existing internally type.
 */





/*
 * Support of formatting anything larger than long in printf
 *
 * This setting controls if 'long' should be used internally in printf, rather
 * than the largest existing integer type. If 'long' is used, any integer or
 * pointer type formatting use 'long' as internal type even though the
 * formatted type is larger. Set to 1 to use 'long' as internal type,
 * otherwise set to 0.
 *
 * See also previous configuration.
 *
 * Default is to internally use largest existing internally type.
 */









/*
 * Emit a char a time in printf
 *
 * This setting controls internal output handling. If selected, i.e. set to 1,
 * then printf emits one character at a time, which requires less code but
 * can be slightly slower for some types of output.
 *
 * If not selected, i.e. set to 0, then printf buffers some outputs.
 *
 * Note that it is recommended to either use full file support (see
 * _DLIB_FILE_DESCRIPTOR) or -- for debug output -- use the linker
 * option "-e__write_buffered=__write" to enable buffered I/O rather
 * than deselecting this feature.
 */






/*
 * Scanf configuration symbols.
 *
 * All the configuration symbols described here controls the
 * behaviour of scanf, sscanf, and the other scanf variants.
 *
 * The library proves three formatters for scanf: 'small', 'large',
 * and 'default'.  The setup in this file controls all, however both
 * 'small' and 'large' explicitly removes some features.
 */

/*
 * Handle multibytes in scanf
 *
 * This setting controls whether multibytes and wchar_t:s are supported in
 * scanf. Set to 1 to support them, otherwise set to 0.
 *
 * See _DLIB_FORMATTED_MULTIBYTE for the default.
 */





/*
 * Long long formatting in scanf
 *
 * This setting controls whether scanf supports long long support (%lld). It
 * also controls, if 'intmax_t' is larger than an ordinary 'long', i.e. how
 * the %jd and %jn specifiers behaves. Set to 1 to support them, otherwise set
 * to 0.
 *
 * Default is to support long long formatting in scanf.
 */

#line 566 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 7.0\\rl78\\inc\\c\\DLib_Defaults.h"





/*
 * Support widths in scanf
 *
 * This controls whether scanf supports widths. Set to 1 to support them,
 * otherwise set to 0.
 *
 * Default is to support widths in scanf.
 */





/*
 * Support qualifiers [hjltzL] in scanf
 *
 * This setting controls whether scanf supports qualifiers [hjltzL] or not. Set
 * to 1 to support them, otherwise set to 0.
 *
 * Default is to support qualifiers in scanf.
 */





/*
 * Support floating-point formatting in scanf
 *
 * This setting controls whether scanf supports floating-point formatting. Set
 * to 1 to support them, otherwise set to 0.
 *
 * Default is to support floating-point formatting in scanf.
 */





/*
 * Support output count formatting (%n)
 *
 * This setting controls whether scanf supports output count formatting (%n).
 * Set to 1 to support it, otherwise set to 0.
 *
 * Default is to support output count formatting in scanf.
 */





/*
 * Support scansets ([]) in scanf
 *
 * This setting controls whether scanf supports scansets ([]) or not. Set to 1
 * to support them, otherwise set to 0.
 *
 * Default is to support scansets in scanf.
 */





/*
 * Support signed integer formatting in scanf
 *
 * This setting controls whether scanf supports signed integer formatting or
 * not. Set to 1 to support them, otherwise set to 0.
 *
 * Default is to support signed integer formatting in scanf.
 */





/*
 * Support unsigned integer formatting in scanf
 *
 * This setting controls whether scanf supports unsigned integer formatting or
 * not. Set to 1 to support them, otherwise set to 0.
 *
 * Default is to support unsigned integer formatting in scanf.
 */





/*
 * Support assignment suppressing [*] in scanf
 *
 * This setting controls whether scanf supports assignment suppressing [*] or
 * not. Set to 1 to support them, otherwise set to 0.
 *
 * Default is to support assignment suppressing in scanf.
 */





/*
 * Handle multibytes in asctime and strftime.
 *
 * This setting controls whether multibytes and wchar_ts are
 * supported.Set to 1 to support them, otherwise set to 0.
 *
 * See _DLIB_FORMATTED_MULTIBYTE for the default setting.
 */





/*
 * True if "qsort" should be implemented using bubble sort.
 *
 * Bubble sort is less efficient than quick sort but requires less RAM
 * and ROM resources.
 */





/*
 * Set Buffert size used in qsort
 */





/*
 * The default "rand" function uses an array of 32 long:s of memory to
 * store the current state.
 *
 * The simple "rand" function uses only a single long. However, the
 * quality of the generated psuedo-random numbers are not as good as
 * the default implementation.
 */





/*
 * Wide character and multi byte character support in library.
 */





/*
 * Set attributes on the function used by the C-SPY debug interface to set a
 * breakpoint in.
 */





/*
 * Support threading in the library
 *
 * 0    No thread support
 * 1    Thread support with a, b, and d.
 * 2    Thread support with a, b, and e.
 * 3    Thread support with all thread-local storage in a dynamically allocated
 *        memory area and a, and b.
 *      a. Lock on heap accesses
 *      b. Optional lock on file accesses (see _DLIB_FILE_OP_LOCKS below)
 *      d. Use an external thread-local storage interface for all the
 *         libraries static and global variables.
 *      e. Static and global variables aren't safe for access from several
 *         threads.
 *
 * Note that if locks are used the following symbols must be defined:
 *
 *   _DLIB_THREAD_LOCK_ONCE_TYPE
 *   _DLIB_THREAD_LOCK_ONCE_MACRO(control_variable, init_function)
 *   _DLIB_THREAD_LOCK_ONCE_TYPE_INIT
 *
 * They will be used to initialize the needed locks only once. TYPE is the
 * type for the static control variable, MACRO is the expression that will be
 * evaluated at each usage of a lock, and INIT is the initializer for the
 * control variable.
 *
 * Note that if thread model 3 is used the symbol _DLIB_TLS_POINTER must be
 * defined. It is a thread local pointer to a dynamic memory area that
 * contains all used TLS variables for the library. Optionally the following
 * symbols can be defined as well (default is to use the default const data
 * and data memories):
 *
 *   _DLIB_TLS_INITIALIZER_MEMORY The memory to place the initializers for the
 *                                TLS memory area
 *   _DLIB_TLS_MEMORY             The memory to use for the TLS memory area. A
 *                                pointer to this memory must be castable to a
 *                                default pointer and back.
 *   _DLIB_TLS_REQUIRE_INIT       Set to 1 to require __cstart_init_tls
 *                                when needed to initialize the TLS data
 *                                segment for the main thread.
 *   _DLIB_TLS_SEGMENT_DATA       The name of the TLS RAM data segment
 *   _DLIB_TLS_SEGMENT_INIT       The name of the used to initialize the
 *                                TLS data segment.
 *
 * See DLib_Threads.h for a description of what interfaces needs to be
 * defined for thread support.
 */





/*
 * Used by products where one runtime library can be used by applications
 * with different data models, in order to reduce the total number of
 * libraries required. Typically, this is used when the pointer types does
 * not change over the data models used, but the placement of data variables
 * or/and constant variables do.
 *
 * If defined, this symbol is typically defined to the memory attribute that
 * is used by the runtime library. The actual define must use a
 * _Pragma("type_attribute = xxx") construct. In the header files, it is used
 * on all statically linked data objects seen by the application.
 */




#line 812 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 7.0\\rl78\\inc\\c\\DLib_Defaults.h"


/*
 * Turn on support for the Target-specific ABI. The ABI is based on the
 * ARM AEABI. A target, except ARM, may deviate from it.
 */

#line 826 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 7.0\\rl78\\inc\\c\\DLib_Defaults.h"

#line 857 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 7.0\\rl78\\inc\\c\\DLib_Defaults.h"


/*
 * Turn on usage of a pragma to tell the linker the number of elements used
 * in a setjmp jmp_buf.
 */





/*
 * If true, the product supplies a "DLib_Product_string.h" file that
 * is included from "string.h".
 */





/*
 * Determine whether the math fma routines are fast or not.
 */




/*
 * Rtti support.
 */

#line 899 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 7.0\\rl78\\inc\\c\\DLib_Defaults.h"

/*
 * Use the "pointers to short" or "pointers to long" implementation of 
 * the basic floating point routines (like Dnorm, Dtest, Dscale, and Dunscale).
 */




/*
 * Use 64-bit long long as intermediary type in Dtest, and fabs.
 * Default is to do this if long long is 64-bits.
 */




/*
 * Favor speed versus some size enlargements in floating point functions.
 */




/*
 * Include dlmalloc as an alternative heap manager in product.
 *
 * Typically, an application will use a "malloc" heap manager that is
 * relatively small but not that efficient. An application can
 * optionally use the "dlmalloc" package, which provides a more
 * effective "malloc" heap manager, if it is included in the product
 * and supported by the settings.
 *
 * See the product documentation on how to use it, and whether or not
 * it is included in the product.
 */

  /* size_t/ptrdiff_t must be a 4 bytes unsigned integer. */
#line 943 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 7.0\\rl78\\inc\\c\\DLib_Defaults.h"





/*
 * Allow the 64-bit time_t interface?
 *
 * Default is yes if long long is 64 bits.
 */

  #pragma language = save 
  #pragma language = extended





  #pragma language = restore






/*
 * Is time_t 64 or 32 bits?
 *
 * Default is 32 bits.
 */




/*
 * Do we include math functions that demands lots of constant bytes?
 * (like erf, erfc, expm1, fma, lgamma, tgamma, and *_accurate)
 *
 */




/*
 * Set this to __weak, if supported.
 *
 */
#line 997 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 7.0\\rl78\\inc\\c\\DLib_Defaults.h"


/*
 * Deleted options
 *
 */







#line 73 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 7.0\\rl78\\inc\\c\\yvals.h"











                /* Floating-point */

/*
 * Whenever a floating-point type is equal to another, we try to fold those
 * two types into one. This means that if float == double then we fold float to
 * use double internally. Example sinf(float) will use _Sin(double, uint).
 *
 * _X_FNAME is a redirector for internal support routines. The X can be
 *          D (double), F (float), or L (long double). It redirects by using
 *          another prefix. Example calls to Dtest will be __iar_Dtest,
 *          __iar_FDtest, or __iarLDtest.
 * _X_FUN   is a redirector for functions visible to the customer. As above, the
 *          X can be D, F, or L. It redirects by using another suffix. Example
 *          calls to sin will be sin, sinf, or sinl.
 * _X_TYPE  The type that one type is folded to.
 * _X_PTRCAST is a redirector for a cast operation involving a pointer.
 * _X_CAST  is a redirector for a cast involving the float type.
 *
 * _FLOAT_IS_DOUBLE signals that all internal float routines aren't needed.
 * _LONG_DOUBLE_IS_DOUBLE signals that all internal long double routines
 *                        aren't needed.
 */
#line 147 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 7.0\\rl78\\inc\\c\\yvals.h"





                /* NAMING PROPERTIES */


/* Has support for fixed point types */




/* Has support for secure functions (printf_s, scanf_s, etc) */
/* Will not compile if enabled */
#line 170 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 7.0\\rl78\\inc\\c\\yvals.h"

/* Has support for complex C types */




/* If is Embedded C++ language */






/* If is true C++ language */






/* True C++ language setup */
#line 233 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 7.0\\rl78\\inc\\c\\yvals.h"











                /* NAMESPACE CONTROL */
#line 292 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 7.0\\rl78\\inc\\c\\yvals.h"









#line 308 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 7.0\\rl78\\inc\\c\\yvals.h"








#line 1 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 7.0\\rl78\\inc\\c\\xencoding_limits.h"
/* xencoding_limits.h internal header file */
/* Copyright 2003-2010 IAR Systems AB.  */








#line 1 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 7.0\\rl78\\inc\\c\\ycheck.h"
/* ycheck.h internal checking header file. */
/* Copyright 2005-2010 IAR Systems AB. */

/* Note that there is no include guard for this header. This is intentional. */





/* __INTRINSIC
 *
 * Note: Redefined each time ycheck.h is included, i.e. for each
 * system header, to ensure that intrinsic support could be turned off
 * individually for each file.
 */










/* __RL78ABI_PORTABILITY_INTERNAL_LEVEL
 *
 * Note: Redefined each time ycheck.h is included, i.e. for each
 * system header, to ensure that ABI support could be turned off/on
 * individually for each file.
 *
 * Possible values for this preprocessor symbol:
 *
 * 0 - ABI portability mode is disabled.
 *
 * 1 - ABI portability mode (version 1) is enabled.
 *
 * All other values are reserved for future use.
 */






#line 67 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 7.0\\rl78\\inc\\c\\ycheck.h"

#line 12 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 7.0\\rl78\\inc\\c\\xencoding_limits.h"
#line 1 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 7.0\\rl78\\inc\\c\\yvals.h"
/* yvals.h internal configuration header file. */
/* Copyright 2001-2010 IAR Systems AB. */

#line 706 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 7.0\\rl78\\inc\\c\\yvals.h"

/*
 * Copyright (c) 1992-2009 by P.J. Plauger.  ALL RIGHTS RESERVED.
 * Consult your license regarding permissions and restrictions.
V5.04:0576 */
#line 13 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 7.0\\rl78\\inc\\c\\xencoding_limits.h"

                                /* Multibyte encoding length. */


#line 24 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 7.0\\rl78\\inc\\c\\xencoding_limits.h"




#line 42 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 7.0\\rl78\\inc\\c\\xencoding_limits.h"

                                /* Utility macro */














#line 317 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 7.0\\rl78\\inc\\c\\yvals.h"



                /* FLOATING-POINT PROPERTIES */

                /* float properties */
#line 335 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 7.0\\rl78\\inc\\c\\yvals.h"

                /* double properties */
#line 360 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 7.0\\rl78\\inc\\c\\yvals.h"

                /* long double properties */
                /* (must be same as double) */




#line 382 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 7.0\\rl78\\inc\\c\\yvals.h"


                /* INTEGER PROPERTIES */

                                /* MB_LEN_MAX */







  #pragma language=save
  #pragma language=extended
  typedef long long _Longlong;
  typedef unsigned long long _ULonglong;
  #pragma language=restore
#line 405 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 7.0\\rl78\\inc\\c\\yvals.h"






  typedef unsigned short int _Wchart;
  typedef unsigned short int _Wintt;


#line 424 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 7.0\\rl78\\inc\\c\\yvals.h"

#line 432 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 7.0\\rl78\\inc\\c\\yvals.h"

                /* POINTER PROPERTIES */


typedef signed int  _Ptrdifft;
typedef unsigned int     _Sizet;

/* IAR doesn't support restrict  */


                /* stdarg PROPERTIES */





  typedef struct
  {
    char  *_Ap;
  } __Va_list;





__intrinsic __nounwind void __iar_Atexit(void (*)(void));


#line 470 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 7.0\\rl78\\inc\\c\\yvals.h"
  typedef struct
  {       /* state of a multibyte translation */
    unsigned long _Wchar;      /* Used as an intermediary value (up to 32-bits) */
    unsigned long _State;      /* Used as a state value (only some bits used) */
  } _Mbstatet;











typedef struct
{       /* file position */



  long _Off;    /* can be system dependent */

  _Mbstatet _Wstate;
} _Fpost;







                /* THREAD AND LOCALE CONTROL */

#line 1 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 7.0\\rl78\\inc\\c\\DLib_Threads.h"
/***************************************************
 *
 * DLib_Threads.h is the library threads manager.
 *
 * Copyright 2004-2010 IAR Systems AB.  
 *
 * This configuration header file sets up how the thread support in the library
 * should work.
 *
 ***************************************************
 *
 * DO NOT MODIFY THIS FILE!
 *
 ***************************************************/








/*
 * DLib can support a multithreaded environment. The preprocessor symbol 
 * _DLIB_THREAD_SUPPORT governs the support. It can be 0 (no support), 
 * 1 (currently not supported), 2 (locks only), and 3 (simulated TLS and locks).
 */

/*
 * This header sets the following symbols that governs the rest of the
 * library:
 * ------------------------------------------
 * _DLIB_MULTI_THREAD     0 No thread support
 *                        1 Multithread support
 * _DLIB_GLOBAL_VARIABLES 0 Use external TLS interface for the libraries global
 *                          and static variables
 *                        1 Use a lock for accesses to the locale and no 
 *                          security for accesses to other global and static
 *                          variables in the library
 * _DLIB_FILE_OP_LOCKS    0 No file-atomic locks
 *                        1 File-atomic locks

 * _DLIB_COMPILER_TLS     0 No Thread-Local-Storage support in the compiler
 *                        1 Thread-Local-Storage support in the compiler
 * _DLIB_TLS_QUAL         The TLS qualifier, define only if _COMPILER_TLS == 1
 *
 * _DLIB_THREAD_MACRO_SETUP_DONE Whether to use the standard definitions of
 *                               TLS macros defined in xtls.h or the definitions
 *                               are provided here.
 *                        0 Use default macros
 *                        1 Macros defined for xtls.h
 *
 * _DLIB_THREAD_LOCK_ONCE_TYPE
 *                        type for control variable in once-initialization of 
 *                        locks
 * _DLIB_THREAD_LOCK_ONCE_MACRO(control_variable, init_function)
 *                        expression that will be evaluated at each lock access
 *                        to determine if an initialization must be done
 * _DLIB_THREAD_LOCK_ONCE_TYPE_INIT
 *                        initial value for the control variable
 *
 ****************************************************************************
 * Description
 * -----------
 *
 * If locks are to be used (_DLIB_MULTI_THREAD != 0), the following options
 * has to be used in ilink: 
 *   --redirect __iar_Locksyslock=__iar_Locksyslock_mtx
 *   --redirect __iar_Unlocksyslock=__iar_Unlocksyslock_mtx
 *   --redirect __iar_Lockfilelock=__iar_Lockfilelock_mtx
 *   --redirect __iar_Unlockfilelock=__iar_Unlockfilelock_mtx
 *   --keep     __iar_Locksyslock_mtx
 * and, if C++ is used, also:
 *   --redirect __iar_Initdynamicfilelock=__iar_Initdynamicfilelock_mtx
 *   --redirect __iar_Dstdynamicfilelock=__iar_Dstdynamicfilelock_mtx
 *   --redirect __iar_Lockdynamicfilelock=__iar_Lockdynamicfilelock_mtx
 *   --redirect __iar_Unlockdynamicfilelock=__iar_Unlockdynamicfilelock_mtx
 * Xlink uses similar options (-e and -g). The following lock interface must
 * also be implemented: 
 *   typedef void *__iar_Rmtx;                   // Lock info object
 *
 *   void __iar_system_Mtxinit(__iar_Rmtx *);    // Initialize a system lock
 *   void __iar_system_Mtxdst(__iar_Rmtx *);     // Destroy a system lock
 *   void __iar_system_Mtxlock(__iar_Rmtx *);    // Lock a system lock
 *   void __iar_system_Mtxunlock(__iar_Rmtx *);  // Unlock a system lock
 * The interface handles locks for the heap, the locale, the file system
 * structure, the initialization of statics in functions, etc. 
 *
 * The following lock interface is optional to be implemented:
 *   void __iar_file_Mtxinit(__iar_Rmtx *);    // Initialize a file lock
 *   void __iar_file_Mtxdst(__iar_Rmtx *);     // Destroy a file lock
 *   void __iar_file_Mtxlock(__iar_Rmtx *);    // Lock a file lock
 *   void __iar_file_Mtxunlock(__iar_Rmtx *);  // Unlock a file lock
 * The interface handles locks for each file stream.
 * 
 * These three once-initialization symbols must also be defined, if the 
 * default initialization later on in this file doesn't work (done in 
 * DLib_product.h):
 *
 *   _DLIB_THREAD_LOCK_ONCE_TYPE
 *   _DLIB_THREAD_LOCK_ONCE_MACRO(control_variable, init_function)
 *   _DLIB_THREAD_LOCK_ONCE_TYPE_INIT
 *
 * If an external TLS interface is used, the following must
 * be defined:
 *   typedef int __iar_Tlskey_t;
 *   typedef void (*__iar_Tlsdtor_t)(void *);
 *   int __iar_Tlsalloc(__iar_Tlskey_t *, __iar_Tlsdtor_t); 
 *                                                    // Allocate a TLS element
 *   int __iar_Tlsfree(__iar_Tlskey_t);               // Free a TLS element
 *   int __iar_Tlsset(__iar_Tlskey_t, void *);        // Set a TLS element
 *   void *__iar_Tlsget(__iar_Tlskey_t);              // Get a TLS element
 *
 */

/* We don't have a compiler that supports tls declarations */





  /* No support for threading. */





#line 296 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 7.0\\rl78\\inc\\c\\DLib_Threads.h"

  
  typedef void *__iar_Rmtx;
  
#line 326 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 7.0\\rl78\\inc\\c\\DLib_Threads.h"



#line 348 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 7.0\\rl78\\inc\\c\\DLib_Threads.h"












#line 505 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 7.0\\rl78\\inc\\c\\yvals.h"

#line 515 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 7.0\\rl78\\inc\\c\\yvals.h"

                /* THREAD-LOCAL STORAGE */
#line 523 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 7.0\\rl78\\inc\\c\\yvals.h"


                /* MULTITHREAD PROPERTIES */
#line 563 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 7.0\\rl78\\inc\\c\\yvals.h"

                /* LOCK MACROS */
#line 571 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 7.0\\rl78\\inc\\c\\yvals.h"

#line 689 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 7.0\\rl78\\inc\\c\\yvals.h"

                /* MISCELLANEOUS MACROS AND FUNCTIONS*/





#line 704 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 7.0\\rl78\\inc\\c\\yvals.h"



/*
 * Copyright (c) 1992-2009 by P.J. Plauger.  ALL RIGHTS RESERVED.
 * Consult your license regarding permissions and restrictions.
V5.04:0576 */
#line 13 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 7.0\\rl78\\inc\\c\\stdlib.h"
#line 1 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 7.0\\rl78\\inc\\c\\ysizet.h"
/* ysizet.h internal header file. */
/* Copyright 2003-2010 IAR Systems AB.  */








#line 1 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 7.0\\rl78\\inc\\c\\ycheck.h"
/* ycheck.h internal checking header file. */
/* Copyright 2005-2010 IAR Systems AB. */

/* Note that there is no include guard for this header. This is intentional. */





/* __INTRINSIC
 *
 * Note: Redefined each time ycheck.h is included, i.e. for each
 * system header, to ensure that intrinsic support could be turned off
 * individually for each file.
 */










/* __RL78ABI_PORTABILITY_INTERNAL_LEVEL
 *
 * Note: Redefined each time ycheck.h is included, i.e. for each
 * system header, to ensure that ABI support could be turned off/on
 * individually for each file.
 *
 * Possible values for this preprocessor symbol:
 *
 * 0 - ABI portability mode is disabled.
 *
 * 1 - ABI portability mode (version 1) is enabled.
 *
 * All other values are reserved for future use.
 */






#line 67 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 7.0\\rl78\\inc\\c\\ycheck.h"

#line 12 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 7.0\\rl78\\inc\\c\\ysizet.h"



                /* type definitions */




typedef _Sizet size_t;




 typedef unsigned int __near_size_t; typedef unsigned int __far_size_t; typedef unsigned long __huge_size_t;











#line 14 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 7.0\\rl78\\inc\\c\\stdlib.h"


/* Module consistency. */
#pragma rtmodel="__dlib_full_locale_support",   "0"





extern int __rl78abi_MB_CUR_MAX(void);


#line 34 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 7.0\\rl78\\inc\\c\\stdlib.h"





                /* MACROS */













                /* TYPE DEFINITIONS */


  typedef _Wchart wchar_t;


typedef struct
{       /* result of int divide */
  int quot;
  int rem;
} div_t;

typedef struct
{       /* result of long divide */
  long quot;
  long rem;
} ldiv_t;



    #pragma language=save
    #pragma language=extended
    typedef struct
    {     /* result of long long divide */
      _Longlong quot;
      _Longlong rem;
    } lldiv_t;
    #pragma language=restore



                /* DECLARATIONS */
 /* low-level functions */
__intrinsic __nounwind int atexit(void (*)(void));

  __intrinsic __noreturn __nounwind void _Exit(int) ;

__intrinsic __noreturn __nounwind void exit(int) ;
__intrinsic __nounwind char * getenv(const char *);
__intrinsic __nounwind int system(const char *);



             __intrinsic __noreturn __nounwind void abort(void) ;
_Pragma("function_effects = no_state, no_errno")     __intrinsic __nounwind int abs(int);
             __intrinsic __nounwind void * calloc(size_t, size_t);
_Pragma("function_effects = no_state, no_errno")     __intrinsic __nounwind div_t div(int, int);
             __intrinsic __nounwind void free(void *);
_Pragma("function_effects = no_state, no_errno")     __intrinsic __nounwind long labs(long);
_Pragma("function_effects = no_state, no_errno")     __intrinsic __nounwind ldiv_t ldiv(long, long);


    #pragma language=save
    #pragma language=extended
    _Pragma("function_effects = no_state, no_errno") __intrinsic __nounwind long long llabs(long long);
    _Pragma("function_effects = no_state, no_errno") __intrinsic __nounwind lldiv_t lldiv(long long, long long);
    #pragma language=restore


             __intrinsic __nounwind void * malloc(size_t);
_Pragma("function_effects = no_write(1)")    __intrinsic __nounwind int mblen(const char *, size_t);
_Pragma("function_effects = no_read(1), no_write(2)") __intrinsic __nounwind size_t mbstowcs(wchar_t *, 
                                          const char *, size_t);
_Pragma("function_effects = no_read(1), no_write(2)") __intrinsic __nounwind int mbtowc(wchar_t *, const char *, 
                                     size_t);
             __intrinsic __nounwind int rand(void);
             __intrinsic __nounwind void srand(unsigned int);
             __intrinsic __nounwind void * realloc(void *, size_t);
_Pragma("function_effects = no_write(1), no_read(2)") __intrinsic __nounwind long strtol(const char *, 
                                      char **, int);
_Pragma("function_effects = no_write(1), no_read(2)") __intrinsic __nounwind unsigned long strtoul(const char *, char **, int);
_Pragma("function_effects = no_read(1), no_write(2)") __intrinsic __nounwind size_t wcstombs(char *, 
                                          const wchar_t *, size_t);
_Pragma("function_effects = no_read(1)")    __intrinsic __nounwind int wctomb(char *, wchar_t);


    #pragma language=save
    #pragma language=extended
    _Pragma("function_effects = no_write(1), no_read(2)") __intrinsic __nounwind long long strtoll(const char *, char **, int);
    _Pragma("function_effects = no_write(1), no_read(2)") __intrinsic __nounwind unsigned long long strtoull(const char *, 
                                                          char **, int);
    #pragma language=restore







    #pragma language=save
    #pragma language=extended






     __intrinsic __nounwind void __near_free(void __near *); __intrinsic __nounwind void __near * __near_malloc(__near_size_t); __intrinsic __nounwind void __near * __near_calloc(__near_size_t, __near_size_t); __intrinsic __nounwind void __near * __near_realloc(void __near *, __near_size_t); __intrinsic __nounwind void __far_free(void __far *); __intrinsic __nounwind void __far * __far_malloc(__far_size_t); __intrinsic __nounwind void __far * __far_calloc(__far_size_t, __far_size_t); __intrinsic __nounwind void __far * __far_realloc(void __far *, __far_size_t); __intrinsic __nounwind void __huge_free(void __huge *); __intrinsic __nounwind void __huge * __huge_malloc(__huge_size_t); __intrinsic __nounwind void __huge * __huge_calloc(__huge_size_t, __huge_size_t); __intrinsic __nounwind void __huge * __huge_realloc(void __huge *, __huge_size_t);









      #pragma inline
      void free(void * _P)
      {
        __near_free((void __near *)_P);
      }
      #pragma inline
      void * malloc(size_t _S)
      {
        return __near_malloc(_S);

      }
      #pragma inline
      void * realloc(void * _P, size_t _S)
      {
        return __near_realloc((void __near *)_P, _S);
      }
      #pragma inline
      void * calloc(size_t _N, size_t _S)
      {
        return __near_calloc(_N, _S);
      }




    #pragma language=restore





    _Pragma("function_effects = no_write(1), no_read(2)") __intrinsic __nounwind unsigned long __iar_Stoul(const char *, char **, 
                                                        int);
    _Pragma("function_effects = no_write(1), no_read(2)") __intrinsic __nounwind float         __iar_Stof(const char *, char **, long);
    _Pragma("function_effects = no_write(1), no_read(2)") __intrinsic __nounwind double        __iar_Stod(const char *, char **, long);
    _Pragma("function_effects = no_write(1), no_read(2)") __intrinsic __nounwind long double   __iar_Stold(const char *, char **, 
                                                          long);
    _Pragma("function_effects = no_write(1), no_read(2)") __intrinsic __nounwind long          __iar_Stolx(const char *, char **, int, 
                                                        int *);
    _Pragma("function_effects = no_write(1), no_read(2)") __intrinsic __nounwind unsigned long __iar_Stoulx(const char *, char **,
                                                         int, int *);
    _Pragma("function_effects = no_write(1), no_read(2)") __intrinsic __nounwind float         __iar_Stofx(const char *, char **, 
                                                        long, int *);
    _Pragma("function_effects = no_write(1), no_read(2)") __intrinsic __nounwind double        __iar_Stodx(const char *, char **, 
                                                        long, int *);
    _Pragma("function_effects = no_write(1), no_read(2)") __intrinsic __nounwind long double   __iar_Stoldx(const char *, char **, 
                                                         long, int *);

      #pragma language=save
      #pragma language=extended
      _Pragma("function_effects = no_write(1), no_read(2)") __intrinsic __nounwind _Longlong   __iar_Stoll(const char *, char **, 
                                                        int);
      _Pragma("function_effects = no_write(1), no_read(2)") __intrinsic __nounwind _ULonglong   __iar_Stoull(const char *, char **, 
                                                          int);
      _Pragma("function_effects = no_write(1), no_read(2)") __intrinsic __nounwind _Longlong    __iar_Stollx(const char *, char **, 
                                                          int, int *);
      _Pragma("function_effects = no_write(1), no_read(2)") __intrinsic __nounwind _ULonglong   __iar_Stoullx(const char *, char **, 
                                                           int, int *);
      #pragma language=restore








typedef int _Cmpfun(const void *, const void *);

_Pragma("function_effects = no_write(1,2)") __intrinsic void * bsearch(const void *, 
                                                   const void *, size_t,
                                                   size_t, _Cmpfun *);
             __intrinsic void qsort(void *, size_t, size_t, 
                                               _Cmpfun *);
             __intrinsic void __qsortbbl(void *, size_t, size_t, 
                                                    _Cmpfun *);
_Pragma("function_effects = no_write(1)")    __intrinsic __nounwind double atof(const char *);
_Pragma("function_effects = no_write(1)")    __intrinsic __nounwind int atoi(const char *);
_Pragma("function_effects = no_write(1)")    __intrinsic __nounwind long atol(const char *);


    #pragma language=save
    #pragma language=extended
    _Pragma("function_effects = no_write(1)") __intrinsic __nounwind long long atoll(const char *);
    #pragma language=restore

  _Pragma("function_effects = no_write(1), no_read(2)") __intrinsic __nounwind float strtof(const char *, 
                                         char **);
  _Pragma("function_effects = no_write(1), no_read(2)") __intrinsic __nounwind long double strtold(const char *, char **);

_Pragma("function_effects = no_write(1), no_read(2)") __intrinsic __nounwind double strtod(const char *, 
                                        char **);
                                        

                                        
               __intrinsic __nounwind size_t __iar_Mbcurmax(void);

  _Pragma("function_effects = no_state, no_errno")     __intrinsic __nounwind int __iar_DLib_library_version(void);

  


#line 276 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 7.0\\rl78\\inc\\c\\stdlib.h"



  
  typedef void _Atexfun(void);
  
#line 304 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 7.0\\rl78\\inc\\c\\stdlib.h"


                /* INLINES, FOR C and C++ */
    #pragma inline=no_body
    double atof(const char *_S)
    {      /* convert string to double */
      return (__iar_Stod(_S, 0, 0));
    }

    #pragma inline=no_body
    int atoi(const char *_S)
    {      /* convert string to int */
      return ((int)__iar_Stoul(_S, 0, 10));
    }

    #pragma inline=no_body
    long atol(const char *_S)
    {      /* convert string to long */
      return ((long)__iar_Stoul(_S, 0, 10));
    }



        #pragma language=save
        #pragma language=extended
        #pragma inline=no_body
        long long atoll(const char *_S)
        {      /* convert string to long long */



            return ((long long)__iar_Stoull(_S, 0, 10));

        }
        #pragma language=restore



    #pragma inline=no_body
    double strtod(const char * _S, char ** _Endptr)
    {      /* convert string to double, with checking */
      return (__iar_Stod(_S, _Endptr, 0));
    }


      #pragma inline=no_body
      float strtof(const char * _S, char ** _Endptr)
      {      /* convert string to float, with checking */
        return (__iar_Stof(_S, _Endptr, 0));
      }

      #pragma inline=no_body
      long double strtold(const char * _S, char ** _Endptr)
      {      /* convert string to long double, with checking */
        return (__iar_Stold(_S, _Endptr, 0));
      }


    #pragma inline=no_body
    long strtol(const char * _S, char ** _Endptr, 
                int _Base)
    {      /* convert string to unsigned long, with checking */
      return (__iar_Stolx(_S, _Endptr, _Base, 0));
    }

    #pragma inline=no_body
    unsigned long strtoul(const char * _S, char ** _Endptr, 
                          int _Base)
    {      /* convert string to unsigned long, with checking */
      return (__iar_Stoul(_S, _Endptr, _Base));
    }



        #pragma language=save
        #pragma language=extended
        #pragma inline=no_body
        long long strtoll(const char * _S, char ** _Endptr,
                          int _Base)
        {      /* convert string to long long, with checking */



            return (__iar_Stoll(_S, _Endptr, _Base));

        }

        #pragma inline=no_body
        unsigned long long strtoull(const char * _S, 
                                    char ** _Endptr, int _Base)
        {      /* convert string to unsigned long long, with checking */



            return (__iar_Stoull(_S, _Endptr, _Base));

        }
        #pragma language=restore





  #pragma inline=no_body
  int abs(int i)
  {      /* compute absolute value of int argument */
    return (i < 0 ? -i : i);
  }

  #pragma inline=no_body
  long labs(long i)
  {      /* compute absolute value of long argument */
    return (i < 0 ? -i : i);
  }



      #pragma language=save
      #pragma language=extended
      #pragma inline=no_body
      long long llabs(long long i)
      {      /* compute absolute value of long long argument */
        return (i < 0 ? -i : i);
      }
      #pragma language=restore



#line 465 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 7.0\\rl78\\inc\\c\\stdlib.h"




#line 494 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 7.0\\rl78\\inc\\c\\stdlib.h"

/*
 * Copyright (c) 1992-2009 by P.J. Plauger.  ALL RIGHTS RESERVED.
 * Consult your license regarding permissions and restrictions.
V5.04:0576 */
#line 30 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\VCAST_STRING.h"


#line 1 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 7.0\\rl78\\inc\\c\\setjmp.h"
/* setjmp.h standard header wrapper */
/* Copyright 2005-2010 IAR Systems AB. */








#line 1 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 7.0\\rl78\\inc\\c\\ycheck.h"
/* ycheck.h internal checking header file. */
/* Copyright 2005-2010 IAR Systems AB. */

/* Note that there is no include guard for this header. This is intentional. */





/* __INTRINSIC
 *
 * Note: Redefined each time ycheck.h is included, i.e. for each
 * system header, to ensure that intrinsic support could be turned off
 * individually for each file.
 */










/* __RL78ABI_PORTABILITY_INTERNAL_LEVEL
 *
 * Note: Redefined each time ycheck.h is included, i.e. for each
 * system header, to ensure that ABI support could be turned off/on
 * individually for each file.
 *
 * Possible values for this preprocessor symbol:
 *
 * 0 - ABI portability mode is disabled.
 *
 * 1 - ABI portability mode (version 1) is enabled.
 *
 * All other values are reserved for future use.
 */






#line 67 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 7.0\\rl78\\inc\\c\\ycheck.h"

#line 12 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 7.0\\rl78\\inc\\c\\setjmp.h"




#line 26 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 7.0\\rl78\\inc\\c\\setjmp.h"

/* Setup in what type we measure the size of __rl78abi_JMP_BUF_SIZE.
   Default is using the element type. */




#pragma language=save
#pragma language=extended
#line 47 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 7.0\\rl78\\inc\\c\\setjmp.h"
        /* MULTIBYTE PROPERTIES */

  typedef short int  jmp_buf[5];







#pragma language=restore


__intrinsic __nounwind int setjmp(jmp_buf);
__intrinsic __noreturn __nounwind void longjmp(jmp_buf, int) ;








#line 77 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 7.0\\rl78\\inc\\c\\setjmp.h"


/*
 * Copyright (c) 1992-2009 by P.J. Plauger.  ALL RIGHTS RESERVED.
 * Consult your license regarding permissions and restrictions.
V5.04:0576 */
#line 34 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\VCAST_STRING.h"


#line 1 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 7.0\\rl78\\inc\\c\\stdio.h"
/* stdio.h standard header */
/* Copyright 2003-2010 IAR Systems AB.  */







#line 1 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 7.0\\rl78\\inc\\c\\ycheck.h"
/* ycheck.h internal checking header file. */
/* Copyright 2005-2010 IAR Systems AB. */

/* Note that there is no include guard for this header. This is intentional. */





/* __INTRINSIC
 *
 * Note: Redefined each time ycheck.h is included, i.e. for each
 * system header, to ensure that intrinsic support could be turned off
 * individually for each file.
 */










/* __RL78ABI_PORTABILITY_INTERNAL_LEVEL
 *
 * Note: Redefined each time ycheck.h is included, i.e. for each
 * system header, to ensure that ABI support could be turned off/on
 * individually for each file.
 *
 * Possible values for this preprocessor symbol:
 *
 * 0 - ABI portability mode is disabled.
 *
 * 1 - ABI portability mode (version 1) is enabled.
 *
 * All other values are reserved for future use.
 */






#line 67 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 7.0\\rl78\\inc\\c\\ycheck.h"

#line 11 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 7.0\\rl78\\inc\\c\\stdio.h"
#line 1 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 7.0\\rl78\\inc\\c\\ysizet.h"
/* ysizet.h internal header file. */
/* Copyright 2003-2010 IAR Systems AB.  */

#line 30 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 7.0\\rl78\\inc\\c\\ysizet.h"







#line 13 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 7.0\\rl78\\inc\\c\\stdio.h"
#line 1 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 7.0\\rl78\\inc\\c\\ystdio.h"
/* ystdio.h internal header */
/* Copyright 2009-2010 IAR Systems AB. */












#line 58 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 7.0\\rl78\\inc\\c\\ystdio.h"
  
/* File system functions that have debug variants. They are agnostic on 
   whether the library is full or normal. */

__intrinsic __nounwind int remove(const char *);
__intrinsic __nounwind int rename(const char *, const char *);











/*
 * Copyright (c) 1992-2009 by P.J. Plauger.  ALL RIGHTS RESERVED.
 * Consult your license regarding permissions and restrictions.
V5.042:0576 */
#line 14 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 7.0\\rl78\\inc\\c\\stdio.h"



/* Module consistency. */
#pragma rtmodel="__dlib_file_descriptor","0"

                /* macros */








#line 66 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 7.0\\rl78\\inc\\c\\stdio.h"

#line 88 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 7.0\\rl78\\inc\\c\\stdio.h"

#line 99 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 7.0\\rl78\\inc\\c\\stdio.h"










                /* type definitions */
typedef _Fpost fpos_t;

                /* printf and scanf pragma support */
#pragma language=save
#pragma language=extended

#line 125 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 7.0\\rl78\\inc\\c\\stdio.h"

#line 177 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 7.0\\rl78\\inc\\c\\stdio.h"


             /* Corresponds to fgets(char *, int, stdin); */
_Pragma("function_effects = no_read(1)")    __intrinsic __nounwind char * __gets(char *, int);
_Pragma("function_effects = no_read(1)")    __intrinsic __nounwind char * gets(char *);
_Pragma("function_effects = no_write(1)")    __intrinsic __nounwind void perror(const char *);
_Pragma("function_effects = no_write(1)")    _Pragma("__printf_args") _Pragma("library_default_requirements _Printf = unknown") __intrinsic __nounwind int printf(const char *, ...);
_Pragma("function_effects = no_write(1)")    __intrinsic __nounwind int puts(const char *);
_Pragma("function_effects = no_write(1)")    _Pragma("__scanf_args") _Pragma("library_default_requirements _Scanf = unknown")  __intrinsic __nounwind int scanf(const char *, ...);
_Pragma("function_effects = no_read(1), no_write(2)") _Pragma("__printf_args") _Pragma("library_default_requirements _Printf = unknown") __intrinsic __nounwind int sprintf(char *, 
                                                 const char *, ...);
_Pragma("function_effects = no_write(1,2)") _Pragma("__scanf_args") _Pragma("library_default_requirements _Scanf = unknown")  __intrinsic __nounwind int sscanf(const char *, 
                                                const char *, ...);
             __intrinsic __nounwind char * tmpnam(char *);
             /* Corresponds to "ungetc(c, stdout)" */
             __intrinsic __nounwind int __ungetchar(int);
_Pragma("function_effects = no_write(1)")    _Pragma("__printf_args") _Pragma("library_default_requirements _Printf = unknown") __intrinsic __nounwind int vprintf(const char *,
                                                 __Va_list);

  _Pragma("function_effects = no_write(1)")    _Pragma("__scanf_args") _Pragma("library_default_requirements _Scanf = unknown")  __intrinsic __nounwind int vscanf(const char *, 
                                                  __Va_list);
  _Pragma("function_effects = no_write(1,2)") _Pragma("__scanf_args") _Pragma("library_default_requirements _Scanf = unknown")  __intrinsic __nounwind int vsscanf(const char *, 
                                                   const char *, 
                                                   __Va_list);

_Pragma("function_effects = no_read(1), no_write(2)")  _Pragma("__printf_args") _Pragma("library_default_requirements _Printf = unknown") __intrinsic __nounwind int vsprintf(char *, 
                                                   const char *,
                                                   __Va_list);
              /* Corresponds to fwrite(p, x, y, stdout); */
_Pragma("function_effects = no_write(1)")      __intrinsic __nounwind size_t __write_array(const void *, size_t, size_t);

  _Pragma("function_effects = no_read(1), no_write(3)") _Pragma("__printf_args") _Pragma("library_default_requirements _Printf = unknown") __intrinsic __nounwind int snprintf(char *, size_t, 
                                                    const char *, ...);
  _Pragma("function_effects = no_read(1), no_write(3)") _Pragma("__printf_args") _Pragma("library_default_requirements _Printf = unknown") __intrinsic __nounwind int vsnprintf(char *, size_t,
                                                     const char *, 
                                                     __Va_list);


              __intrinsic __nounwind int getchar(void);
              __intrinsic __nounwind int putchar(int);



#pragma language=restore

#line 236 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 7.0\\rl78\\inc\\c\\stdio.h"




#line 290 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 7.0\\rl78\\inc\\c\\stdio.h"

/*
 * Copyright (c) 1992-2002 by P.J. Plauger.  ALL RIGHTS RESERVED.
 * Consult your license regarding permissions and restrictions.
V5.04:0576 */
#line 54 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\VCAST_STRING.h"





#line 1 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 7.0\\rl78\\inc\\c\\string.h"
/* string.h standard header */
/* Copyright 2009-2010 IAR Systems AB. */







#line 1 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 7.0\\rl78\\inc\\c\\ycheck.h"
/* ycheck.h internal checking header file. */
/* Copyright 2005-2010 IAR Systems AB. */

/* Note that there is no include guard for this header. This is intentional. */





/* __INTRINSIC
 *
 * Note: Redefined each time ycheck.h is included, i.e. for each
 * system header, to ensure that intrinsic support could be turned off
 * individually for each file.
 */










/* __RL78ABI_PORTABILITY_INTERNAL_LEVEL
 *
 * Note: Redefined each time ycheck.h is included, i.e. for each
 * system header, to ensure that ABI support could be turned off/on
 * individually for each file.
 *
 * Possible values for this preprocessor symbol:
 *
 * 0 - ABI portability mode is disabled.
 *
 * 1 - ABI portability mode (version 1) is enabled.
 *
 * All other values are reserved for future use.
 */






#line 67 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 7.0\\rl78\\inc\\c\\ycheck.h"

#line 11 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 7.0\\rl78\\inc\\c\\string.h"
#line 1 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 7.0\\rl78\\inc\\c\\ysizet.h"
/* ysizet.h internal header file. */
/* Copyright 2003-2010 IAR Systems AB.  */

#line 30 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 7.0\\rl78\\inc\\c\\ysizet.h"







#line 13 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 7.0\\rl78\\inc\\c\\string.h"






                /* macros */




                /* declarations */

_Pragma("function_effects = no_state, no_errno, no_write(1,2)")   __intrinsic __nounwind int        memcmp(const void *, const void *,
                                                size_t);
_Pragma("function_effects = no_state, no_errno, no_read(1), no_write(2), returns 1") __intrinsic __nounwind void *     memcpy(void *, 
                                                const void *, size_t);
_Pragma("function_effects = no_state, no_errno, no_read(1), no_write(2), returns 1") __intrinsic __nounwind void *     memmove(void *, const void *, size_t);
_Pragma("function_effects = no_state, no_errno, no_read(1), returns 1")    __intrinsic __nounwind void *     memset(void *, int, size_t);
_Pragma("function_effects = no_state, no_errno, no_write(2), returns 1")    __intrinsic __nounwind char *     strcat(char *, 
                                                const char *);
_Pragma("function_effects = no_state, no_errno, no_write(1,2)")   __intrinsic __nounwind int        strcmp(const char *, const char *);
_Pragma("function_effects = no_write(1,2)")     __intrinsic __nounwind int        strcoll(const char *, const char *);
_Pragma("function_effects = no_state, no_errno, no_read(1), no_write(2), returns 1") __intrinsic __nounwind char *     strcpy(char *, 
                                                const char *);
_Pragma("function_effects = no_state, no_errno, no_write(1,2)")   __intrinsic __nounwind size_t     strcspn(const char *, const char *);
                 __intrinsic __nounwind char *     strerror(int);
_Pragma("function_effects = no_state, no_errno, no_write(1)")      __intrinsic __nounwind size_t     strlen(const char *);
_Pragma("function_effects = no_state, no_errno, no_write(2), returns 1")    __intrinsic __nounwind char *     strncat(char *, 
                                                 const char *, size_t);
_Pragma("function_effects = no_state, no_errno, no_write(1,2)")   __intrinsic __nounwind int        strncmp(const char *, const char *, 
                                                 size_t);
_Pragma("function_effects = no_state, no_errno, no_read(1), no_write(2), returns 1") __intrinsic __nounwind char *     strncpy(char *, 
                                                 const char *, size_t);
_Pragma("function_effects = no_state, no_errno, no_write(1,2)")   __intrinsic __nounwind size_t     strspn(const char *, const char *);
_Pragma("function_effects = no_write(2)")        __intrinsic __nounwind char *     strtok(char *, 
                                                const char *);
_Pragma("function_effects = no_write(2)")        __intrinsic __nounwind size_t     strxfrm(char *, 
                                                 const char *, size_t);


  _Pragma("function_effects = no_write(1)")      __intrinsic __nounwind char *   strdup(const char *);
  _Pragma("function_effects = no_write(1,2)")   __intrinsic __nounwind int      strcasecmp(const char *, const char *);
  _Pragma("function_effects = no_write(1,2)")   __intrinsic __nounwind int      strncasecmp(const char *, const char *, 
                                                   size_t);
  _Pragma("function_effects = no_state, no_errno, no_write(2)")    __intrinsic __nounwind char *   strtok_r(char *, const char *, char **);
  _Pragma("function_effects = no_state, no_errno, no_write(1)")    __intrinsic __nounwind size_t   strnlen(char const *, size_t);




#line 81 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 7.0\\rl78\\inc\\c\\string.h"
  _Pragma("function_effects = no_state, no_errno, no_write(1)")    __intrinsic __nounwind void *memchr(const void *_S, int _C, size_t _N);
  _Pragma("function_effects = no_state, no_errno, no_write(1)")    __intrinsic __nounwind char *strchr(const char *_S, int _C);
  _Pragma("function_effects = no_state, no_errno, no_write(1,2)") __intrinsic __nounwind char *strpbrk(const char *_S, const char *_P);
  _Pragma("function_effects = no_state, no_errno, no_write(1)")    __intrinsic __nounwind char *strrchr(const char *_S, int _C);
  _Pragma("function_effects = no_state, no_errno, no_write(1,2)") __intrinsic __nounwind char *strstr(const char *_S, const char *_P);




                /* Inline definitions. */


                /* The implementations. */

_Pragma("function_effects = no_state, no_errno, no_write(1)")    __intrinsic __nounwind void *__iar_Memchr(const void *, int, size_t);
_Pragma("function_effects = no_state, no_errno, no_write(1)")    __intrinsic __nounwind char *__iar_Strchr(const char *, int);
               __intrinsic __nounwind char *__iar_Strerror(int, char *);
_Pragma("function_effects = no_state, no_errno, no_write(1,2)") __intrinsic __nounwind char *__iar_Strpbrk(const char *, const char *);
_Pragma("function_effects = no_state, no_errno, no_write(1)")    __intrinsic __nounwind char *__iar_Strrchr(const char *, int);
_Pragma("function_effects = no_state, no_errno, no_write(1,2)") __intrinsic __nounwind char *__iar_Strstr(const char *, const char *);


                /* inlines and overloads, for C and C++ */
#line 168 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 7.0\\rl78\\inc\\c\\string.h"
                /* Then the overloads for C. */
    #pragma inline
    void *memchr(const void *_S, int _C, size_t _N)
    {
      return (__iar_Memchr(_S, _C, _N));
    }

    #pragma inline
    char *strchr(const char *_S, int _C)
    {
      return (__iar_Strchr(_S, _C));
    }

    #pragma inline
    char *strpbrk(const char *_S, const char *_P)
    {
      return (__iar_Strpbrk(_S, _P));
    }

    #pragma inline
    char *strrchr(const char *_S, int _C)
    {
      return (__iar_Strrchr(_S, _C));
    }

    #pragma inline
    char *strstr(const char *_S, const char *_P)
    {
      return (__iar_Strstr(_S, _P));
    }


  #pragma inline
  char *strerror(int _Err)
  {
    return (__iar_Strerror(_Err, 0));
  }

#line 451 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 7.0\\rl78\\inc\\c\\string.h"






#line 479 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 7.0\\rl78\\inc\\c\\string.h"

/*
 * Copyright (c) 1992-2009 by P.J. Plauger.  ALL RIGHTS RESERVED.
 * Consult your license regarding permissions and restrictions.
V5.04:0576 */
#line 61 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\VCAST_STRING.h"







#line 76 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\VCAST_STRING.h"
/* Wrappers for malloc and realloc are provided in B2.c */
void * VCAST_malloc (unsigned int vcast_size);


#line 95 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\VCAST_STRING.h"




#line 137 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\VCAST_STRING.h"
int VCAST_signed_strlen (const signed char *vcast_str );
void VCAST_signed_strcpy ( signed char *VC_S, const signed char *VC_T );





#line 74 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\S0000002.h"















 extern jmp_buf VCAST_env;















/* This define use to define the temporary strings that we use
   when we are breaking down the harness commands like: "0.0.3.4%0\n"
   We use 8 because we do not expect a unit, subprogram, parameter, or field
   to be larger than 999999\n\0
*/













typedef long int vCAST_BIG_INT;
enum    vCAST_COMMAND_TYPE { vCAST_SET_VAL,
                             vCAST_PRINT,
                             vCAST_FIRST_VAL,
                             vCAST_MID_VAL,
                             vCAST_LAST_VAL,
                             vCAST_POS_INF_VAL,
                             vCAST_NEG_INF_VAL,
                             vCAST_NAN_VAL,
                             vCAST_MIN_MINUS_1_VAL,
                             vCAST_MAX_PLUS_1_VAL,
                             vCAST_ZERO_VAL,
                             vCAST_KEEP_VAL,
                             vCAST_ALLOCATE,
                             vCAST_STUB_FUNCTION,
                             vCAST_FUNCTION }; 

struct vCAST_HIST_ENTRY {
  int VC_U;
  int VC_S;
};

struct vCAST_ORDER_ENTRY {
  int  VC_I;
  char VC_N[13];
  char VC_T[64];
  char VC_SLOT_DESCR[64];
  char VC_PRINT_DATA[64];
};

enum VCAST_RANGE_DATA_TYPE { 
   VCAST_NULL_TYPE = 0,
   VCAST_RANGE_TYPE,
   VCAST_LIST_TYPE
};





/* If the max range is not set by the user at all
   we default to 20 */




/* if the user explicitly sets the max range to be 0,
   it means they don't want range processing at all */
#line 192 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\S0000002.h"




/* vCAST function prototypes */




vCAST_double      vCAST_power (short vcast_bits);
vCAST_long_double VCAST_itod  ( char vcastStringParam[] );


void vCAST_SET_TESTCASE_CONFIGURATION_OPTIONS( int VCAST_option,int VCAST_value, int VCAST_set_default);
void vCAST_SET_TESTCASE_OPTIONS ( char vcast_options[] );
void vCAST_RUN_DATA_IF (char VCAST_PARAM[], vCAST_boolean POST_CONSTRUCTOR_USER_CODE);
void vCAST_slice (char vcast_target[], char vcast_source[], int vcast_first, int vcast_last);
void vCAST_EXTRACT_DATA_FROM_COMMAND_LINE (char *vcast_buf, char VCAST_PARAM[], int VC_POSITION);
void vCAST_STR_TO_LONG_DOUBLE(char vcastStringParam[], vCAST_long_double * vcastFloatParam);
void vCAST_DOUBLE_TO_STR (vCAST_long_double VC_F, char VC_S[], int VC_AS_INT);
void vCAST_RESET_LIST_VALUES(void);
void vCAST_ITERATION_COUNTER_RESET(void);
void vCAST_RESET_ITERATION_COUNTERS(enum vCAST_testcase_options_type );
int  vCAST_GET_ITERATION_COUNTER_VALUE(int, int);
void vCAST_INCREMENT_ITERATION_COUNTER(int, int);
void vCAST_EXECUTE_RANGE_COMMANDS (int);

/* if range processing is disabled, no need to do this stuff!*/




                              
#line 233 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\S0000002.h"

void vCAST_RESET_RANGE_VALUES (void);
void vCAST_INITIALIZE_RANGE_VALUES (void);
void vCAST_FREE_RANGE_VALUES(void);
void vCAST_STORE_GLOBAL_ASCII_DATA (void);
void vCAST_CREATE_EVENT_FILE (void);
void vCAST_CREATE_HIST_FILE (void);
void vCAST_OPEN_HIST_FILE (void);
void vCAST_CREATE_INST_FILE (void);
int  VCAST_test_name_cmp(char *vcast_tn);
long VCAST_convert_encoded_field(const char *vcast_str);

/* Code coverage-related functions */
void vCAST_CREATE_INST_FILE (void);
void VCAST_WRITE_TO_INST_FILE (const char VC_S[]);
#line 1 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\vcast_c_options.h"
#line 44 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\vcast_c_options.h"

/* An explanation for the number of bytes required for VectorCAST/Cover.
 * 
 * This represents the maximum amount of RAM that will be required
 * to record coverage data when 100% of your application is executed.
 * It is likely that only a percentage of this storage will be 
 * required during a single program execution.
 * 
 * Please note, when using the static memory option, all of this data 
 * must be reserved in the instrumented executable through global arrays.
 * When you are not using the static memory option, this data is not 
 * reserved in the instrumented executable, and it is allocated on 
 * demand through the use of the malloc system call.
 * 
 * When instrumenting for MCDC, the size of the variables 
 * mcdc_statement_pool and avlnode_pool are controlled with the option 
 * "Maximum MC/DC expressions". The default is set to 1000, 
 * so that a large test case can execute with out fear of 
 * over flowing these buffers. The number chosen (e.g. 1000) will 
 * provide storage for that many unique MC/DC expressions.
 * 
 * For a 16 bit executable configuration:
 *   function call bit array:.............size: 1          bytes:  0 *
 *   Total (no MC/DC pool storage):......................................bytes:  0 *
 * 
 * For a 32 bit executable configuration:
 *   function call bit array:.............size: 1          bytes:  0 *
 *   Total (no MC/DC pool storage):......................................bytes:  0 *
 * 
 * For a 64 bit executable configuration:
 *   function call bit array:.............size: 1          bytes:  0 *
 *   Total (no MC/DC pool storage):......................................bytes:  0 *
 */






#line 249 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\S0000002.h"

void vCAST_SET_OUTPUT_TO_EVENT_FILE (void);
void vCAST_CLOSE_INST_FILE (void);

/* Coverage data */


void vCAST_SET_OUTPUT_TO_EVENT_FILE (void);
void vCAST_CLOSE_INST_FILE (void);
void vCAST_CLOSE_EVENT_FILE (void);
void vCAST_CLOSE_HIST_FILE (void);
void vCAST_WRITE_END_FILE(void);
void vCAST_OPEN_E0_FILE (void);
void vCAST_OPEN_HARNOPTS_FILE(void);
void vCAST_RESET_HARNOPTS_FILE(void);
void vCAST_OPEN_TESTORDR_FILE (void);
void VCAST_READ_TESTORDER_LINE ( char[] );
void vCAST_STORE_ASCII_DATA ( int, int, char[] );

vCAST_boolean vCAST_READ_NEXT_ORDER (void);
vCAST_boolean vCAST_SHOULD_DISPLAY_GLOBALS ( int, char[] );

#line 358 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\S0000002.h"


extern int    vcast_user_file;
extern int    VCAST_EXP_FILE;

extern int    vCAST_UNIT;
extern int    vCAST_SUBPROGRAM;
extern vCAST_boolean    vCAST_DO_DATA_IF;
extern char   vCAST_TEST_NAME[];
extern int    vCAST_CURRENT_SLOT;
extern int    vCAST_CURRENT_ITERATION;
extern int    vCAST_HIST_INDEX;
extern int    vCAST_HIST_LIMIT;
extern int    vCAST_ENV_HIST_LIMIT;
extern vCAST_boolean vCAST_HAS_RANGE;
extern vCAST_boolean vCAST_SKIP_ITER;
extern int    vCAST_NUM_RANGE_ITERATIONS;
extern int    vCAST_RANGE_COUNTER;





extern struct vCAST_ORDER_ENTRY vCAST_ORDER_OBJECT;

extern vCAST_long_double vCAST_PARTITIONS;
extern vCAST_boolean vCAST_COMMAND_IS_MIN_MAX;

extern int vCAST_INST_FILE;
/* file identificastion number for the ASCIIRES.DAT file */
extern int vCAST_EVENT_FILE;
/* file identification number for the THISTORY.DAT file */
extern int vCAST_HIST_FILE;
extern int vCAST_ORDER_FILE;
extern int vCAST_E0_FILE;
/* file identification number for the TEMP_DIF.DAT file */
extern int vCAST_OUTPUT_FILE;
extern int vCAST_COUNT;
extern int vCAST_CURRENT_COUNT;
extern vCAST_array_boolean vCAST_TESTCASE_OPTIONS[15];
extern vCAST_boolean vcast_is_in_union;
extern vCAST_boolean vCAST_INST_FILE_OPEN;
/* true if the ASCIIRES.DAT file is open */
extern vCAST_boolean vCAST_EVENT_FILE_OPEN;
/* true if the THISTORY.DAT file is open */
extern vCAST_boolean vCAST_HIST_FILE_OPEN;

/* default harness options (from HARNOPTS.DAT) */
extern vCAST_boolean VCAST_DEFAULT_FULL_STRINGS;
extern vCAST_boolean VCAST_DEFAULT_HEX_NOTATION;
extern vCAST_boolean VCAST_DEFAULT_DO_COMBINATION;
extern unsigned short VCAST_GLOBALS_DISPLAY; /* when to capture global data */
extern vCAST_boolean VCAST_GLOBAL_FIRST_EVENT;


extern vCAST_boolean vCAST_HEX_NOTATION;  /* use hex notation or not */
extern vCAST_boolean vCAST_DO_COMBINATION_TESTING;/* generate combination or not */
struct vCAST_ORDER_ENTRY* vCAST_ORDER(void);  




void VCAST_driver_termination(int vcast_status, int eventCode);


int vcast_get_hc_id (char *vcast_command);
void vcast_get_unit_id_str (char *vcast_command, char *vcast_unit);
int vcast_get_unit_id (char *vcast_command);
void vcast_get_subprogram_id_str (char *vcast_command, char *vcast_subprogram);
int vcast_get_subprogram_id (char *vcast_command);
void vcast_get_parameter_id_str (char *vcast_command, char *vcast_subprogram);
int vcast_get_parameter_id (char *vcast_command);
int vcast_get_percent_pos (char *vcast_command);
void vCAST_END(void);
void VCAST_SLOT_SEPARATOR ( int VC_EndOfSlot, char VC_SLOT_DESCR );
#line 15 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\B0000001.h"


/* "limits.h" and "float.h" has limits on base types
   If we don't use it, or some types do
   not have limits, define them here */
#line 1 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 7.0\\rl78\\inc\\c\\limits.h"
/* limits.h standard header -- 8-bit version */
/* Copyright 2003-2010 IAR Systems AB. */







#line 1 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 7.0\\rl78\\inc\\c\\ycheck.h"
/* ycheck.h internal checking header file. */
/* Copyright 2005-2010 IAR Systems AB. */

/* Note that there is no include guard for this header. This is intentional. */





/* __INTRINSIC
 *
 * Note: Redefined each time ycheck.h is included, i.e. for each
 * system header, to ensure that intrinsic support could be turned off
 * individually for each file.
 */










/* __RL78ABI_PORTABILITY_INTERNAL_LEVEL
 *
 * Note: Redefined each time ycheck.h is included, i.e. for each
 * system header, to ensure that ABI support could be turned off/on
 * individually for each file.
 *
 * Possible values for this preprocessor symbol:
 *
 * 0 - ABI portability mode is disabled.
 *
 * 1 - ABI portability mode (version 1) is enabled.
 *
 * All other values are reserved for future use.
 */






#line 67 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 7.0\\rl78\\inc\\c\\ycheck.h"

#line 11 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 7.0\\rl78\\inc\\c\\limits.h"




#line 26 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 7.0\\rl78\\inc\\c\\limits.h"
        /* MULTIBYTE PROPERTIES */






        /* CHAR PROPERTIES */





        /* INT PROPERTIES */




        /* SIGNED CHAR PROPERTIES */



        /* SHORT PROPERTIES */



        /* LONG PROPERTIES */



        /* UNSIGNED PROPERTIES */




        /* LONG LONG PROPERTIES */
#line 69 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 7.0\\rl78\\inc\\c\\limits.h"










/*
 * Copyright (c) 1992-2009 by P.J. Plauger.  ALL RIGHTS RESERVED.
 * Consult your license regarding permissions and restrictions.
V5.04:0576 */
#line 22 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\B0000001.h"
#line 1 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 7.0\\rl78\\inc\\c\\float.h"
/* float.h standard header -- IEEE 754 version */
/* Copyright 2003-2010 IAR Systems AB. */







#line 1 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 7.0\\rl78\\inc\\c\\ycheck.h"
/* ycheck.h internal checking header file. */
/* Copyright 2005-2010 IAR Systems AB. */

/* Note that there is no include guard for this header. This is intentional. */





/* __INTRINSIC
 *
 * Note: Redefined each time ycheck.h is included, i.e. for each
 * system header, to ensure that intrinsic support could be turned off
 * individually for each file.
 */










/* __RL78ABI_PORTABILITY_INTERNAL_LEVEL
 *
 * Note: Redefined each time ycheck.h is included, i.e. for each
 * system header, to ensure that ABI support could be turned off/on
 * individually for each file.
 *
 * Possible values for this preprocessor symbol:
 *
 * 0 - ABI portability mode is disabled.
 *
 * 1 - ABI portability mode (version 1) is enabled.
 *
 * All other values are reserved for future use.
 */






#line 67 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 7.0\\rl78\\inc\\c\\ycheck.h"

#line 11 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 7.0\\rl78\\inc\\c\\float.h"



                /* TYPE DEFINITIONS */





                /* COMMON PROPERTIES */







                            /*
                             * If converting a floating-point number to
                             * and rhen back from a decimal number with
                             * DECIMAL_DIG digits then no information
                             * should be lost.
                             */

#line 41 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 7.0\\rl78\\inc\\c\\float.h"


/* Setup 4 byte floating point values */

#line 66 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 7.0\\rl78\\inc\\c\\float.h"


/* Setup 8 byte floating point values */

#line 91 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 7.0\\rl78\\inc\\c\\float.h"


                /* float properties */
#line 106 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 7.0\\rl78\\inc\\c\\float.h"

                /* double properties */
#line 131 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 7.0\\rl78\\inc\\c\\float.h"

                /* long double properties */
#line 145 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 7.0\\rl78\\inc\\c\\float.h"




/*
 * Copyright (c) 1992-2009 by P.J. Plauger.  ALL RIGHTS RESERVED.
 * Consult your license regarding permissions and restrictions.
V5.04:0576 */
#line 24 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\B0000001.h"
#line 53 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\B0000001.h"

#line 85 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\B0000001.h"

#line 154 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\B0000001.h"




/* FUNCTION PROTOTYPES */

void VCAST_get_indices(char *str_val, int *array_size);





void vcast_not_supported (void);
void vcast_get_range_value ( int *vCAST_FIRST_VAL,
                             int *vCAST_LAST_VAL,
                             int *vCAST_MORE_DATA);
int vcast_get_param (void);
int VCAST_FIND_INDEX (void);

/*------------------------------------------------------------------*/






vCAST_double vCAST_power (short vcast_bits);
void VCAST_TI_BITFIELD ( long *vc_VAL, int Bits,  vCAST_boolean is_signed );
void VCAST_TI_STRING ( 
      char **vcast_param, 
      int vCAST_Size,
      int from_bounded_array,
      int size_of_bounded_array );
int vcast_add_to_hex(int previousNumber, char latestDigit);
char vcast_get_non_numerical_escape(char character);
int vcast_convert_size(char * input);

char * VCAST_convert(char * input);

/* ASCII value of the first char that can be displayed */

/* ASCII value of the last char that can be displayed */


/**************************************************************************
Function: isUnprintable
Parameters: character - character to check
Description: This function returns true if the character it is given is
a nongraphical one. 
 *************************************************************************/



void vCAST_slice ( char vcast_target[], char source[], int vcast_first, int vcast_last );

vCAST_boolean vcast_proc_handles_command(int vc_m);
void VCAST_SET_GLOBAL_SIZE(unsigned int *vcast_size);
unsigned int *VCAST_GET_GLOBAL_SIZE(void);

/* EXTERNED VARIABLES */

extern int vCAST_FILE;


extern char vCAST_PARAMETER[64];
extern char vCAST_PARAMETER_KEY[64];

extern long vCAST_VALUE_INT;
extern unsigned long vCAST_VALUE_UNSIGNED;
extern vCAST_long_double vCAST_VALUE;

extern int vCAST_PARAM_LENGTH;
extern int vCAST_INDEX;
extern int vCAST_DATA_FIELD;
extern int  *VCAST_index_size;
extern int  VCAST_index_count;
extern enum vCAST_COMMAND_TYPE vCAST_COMMAND;


extern vCAST_boolean vCAST_VALUE_NUL;
extern vCAST_boolean vCAST_SIZE;
extern vCAST_boolean vCAST_can_print_constructor;

struct VCAST_CSU_Data_Item
{
  void *vcast_item;
  char *vcast_command;
  struct VCAST_CSU_Data_Item *vcast_next;
};

struct VCAST_CSU_Data;

void VCAST_Add_CSU_Data (struct VCAST_CSU_Data **vcast_data, 
                         struct VCAST_CSU_Data_Item *vcast_data_item);
struct VCAST_CSU_Data_Item *VCAST_Get_CSU_Data ( 
                         struct VCAST_CSU_Data **vcast_data,
                         char *vcast_command);

#line 10 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\S0000009.h"
void VCAST_DRIVER_8( int VC_SUBPROGRAM, char *VC_EVENT_FLAGS, char *VC_SLOT_DESCR );
void VCAST_DRIVER_9( int VC_SUBPROGRAM, char *VC_EVENT_FLAGS, char *VC_SLOT_DESCR );

#line 71 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\S0000009.c"
#line 1 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\vcast_undef_9.h"
/* Undefine all field names (disable by setting VCAST_DO_NOT_UNDEF_FIELDS) */
#line 72 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\S0000009.c"
/* Include the file which contains function prototypes
for stub processing and value/expected user code */
#line 1 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\vcast_uc_prototypes.h"
void vCAST_VALUE_USER_CODE_8(int vcast_slot_index );
void vCAST_EXPECTED_USER_CODE_8(int vcast_slot_index );
void vCAST_EGLOBALS_USER_CODE_8(int vcast_slot_index );
void vCAST_STUB_PROCESSING_8(
        int  UnitIndex, 
        int  SubprogramIndex );
void vCAST_BEGIN_STUB_PROC_8(
        int  UnitIndex, 
        int  SubprogramIndex );

void vCAST_COMMON_STUB_PROC_8(
            int unitIndex,
            int subprogramIndex,
            int robjectIndex,
            int readEobjectData );
void vCAST_VALUE_USER_CODE_9(int vcast_slot_index );
void vCAST_EXPECTED_USER_CODE_9(int vcast_slot_index );
void vCAST_EGLOBALS_USER_CODE_9(int vcast_slot_index );
void vCAST_STUB_PROCESSING_9(
        int  UnitIndex, 
        int  SubprogramIndex );
void vCAST_BEGIN_STUB_PROC_9(
        int  UnitIndex, 
        int  SubprogramIndex );

void vCAST_COMMON_STUB_PROC_9(
            int unitIndex,
            int subprogramIndex,
            int robjectIndex,
            int readEobjectData );
void vCAST_VALUE_USER_CODE_9(int vcast_slot_index );
void vCAST_EXPECTED_USER_CODE_9(int vcast_slot_index );
void vCAST_EGLOBALS_USER_CODE_9(int vcast_slot_index );
void vCAST_STUB_PROCESSING_9(
        int  UnitIndex, 
        int  SubprogramIndex );
void vCAST_BEGIN_STUB_PROC_9(
        int  UnitIndex, 
        int  SubprogramIndex );

void vCAST_COMMON_STUB_PROC_9(
            int unitIndex,
            int subprogramIndex,
            int robjectIndex,
            int readEobjectData );
#line 75 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\S0000009.c"
/* Begin Function ApplLinInit */
unsigned char P_9_16_1

;
/* Begin Function ApplLinSlavePreCopy */
unsigned char P_9_17_1

;
/* Begin Function GetFiveTableValue_500ms */
unsigned long P_9_18_1

;
/* Begin Function AdjustOutHudValue */
unsigned long P_9_19_1

;
unsigned long R_9_19;
/* Begin Function GetUpdateTimeForLightStatus */
unsigned char R_9_20;
/* Begin Function CalcHUDMean_1000ms */
unsigned long R_9_21;
/* Begin Function orderHUDValue */
int P_9_22_1

;
/* Begin Function GetFiveTableValue_50ms */
unsigned long P_9_23_1

;
unsigned long P_9_23_2

;
/* Begin Function CRC8SAEJ1850 */
unsigned char *P_9_24_1

;
unsigned char P_9_24_2

;
unsigned char R_9_24;
/* Begin Function GetOutdBriStsCrcj1850 */
unsigned char P_9_25_1

;
unsigned char R_9_25;
/* Begin Function GetHudCrcj1850 */
unsigned long P_9_26_1

;
unsigned char R_9_26;
/* Begin Function GetLightTransmission */
unsigned char P_9_27_1

;
unsigned char P_9_27_2

;
/* Begin Function Get_BCMVehType */
unsigned char P_9_28_1

;
/* Begin Function Set_BCMLightOffset */
unsigned char P_9_29_1

;
/* Begin Function IsByteOddParity */
unsigned char P_9_34_1

;
unsigned char R_9_34;
#line 1 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\vcast_stubs_9.c"

/* Begin defined extern variables */

/* INITIALIZATION_OBJECTS_USER_CODE "1" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "1" */
s_rb_EEPROMStructPD_buff_g EEPROM_Struct_PD 
/* INITIALIZATION_CODE_USER_CODE "1" */

/* INITIALIZATION_CODE_USER_CODE_END "1" */
;


/* INITIALIZATION_OBJECTS_USER_CODE "2" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "2" */
unsigned char rb_Humidity_raw_g 
/* INITIALIZATION_CODE_USER_CODE "2" */

/* INITIALIZATION_CODE_USER_CODE_END "2" */
;


/* INITIALIZATION_OBJECTS_USER_CODE "3" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "3" */
unsigned char rb_Humidity_g 
/* INITIALIZATION_CODE_USER_CODE "3" */

/* INITIALIZATION_CODE_USER_CODE_END "3" */
;


/* INITIALIZATION_OBJECTS_USER_CODE "4" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "4" */
unsigned rw_Temperature_raw_g 
/* INITIALIZATION_CODE_USER_CODE "4" */

/* INITIALIZATION_CODE_USER_CODE_END "4" */
;


/* INITIALIZATION_OBJECTS_USER_CODE "5" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "5" */
unsigned rw_DewPoint_g 
/* INITIALIZATION_CODE_USER_CODE "5" */

/* INITIALIZATION_CODE_USER_CODE_END "5" */
;


/* INITIALIZATION_OBJECTS_USER_CODE "6" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "6" */
unsigned char rbi_HumTempComError_g 
/* INITIALIZATION_CODE_USER_CODE "6" */

/* INITIALIZATION_CODE_USER_CODE_END "6" */
;


/* INITIALIZATION_OBJECTS_USER_CODE "7" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "7" */
s_rb_EEPROMStructAD_buff_g EEPROM_Struct_AD 
/* INITIALIZATION_CODE_USER_CODE "7" */

/* INITIALIZATION_CODE_USER_CODE_END "7" */
;


/* INITIALIZATION_OBJECTS_USER_CODE "8" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "8" */
byte rb_WDG_BusTaskCounter_g 
/* INITIALIZATION_CODE_USER_CODE "8" */

/* INITIALIZATION_CODE_USER_CODE_END "8" */
;


/* INITIALIZATION_OBJECTS_USER_CODE "9" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "9" */
union tLinIndicationBits uLinIndicationFlags 
/* INITIALIZATION_CODE_USER_CODE "9" */

/* INITIALIZATION_CODE_USER_CODE_END "9" */
;


/* INITIALIZATION_OBJECTS_USER_CODE "10" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "10" */
union tLinConfirmationBits uLinConfirmationFlags 
/* INITIALIZATION_CODE_USER_CODE "10" */

/* INITIALIZATION_CODE_USER_CODE_END "10" */
;


/* INITIALIZATION_OBJECTS_USER_CODE "11" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "11" */
byte rb_WakeupCounter_mg 
/* INITIALIZATION_CODE_USER_CODE "11" */

/* INITIALIZATION_CODE_USER_CODE_END "11" */
;


/* INITIALIZATION_OBJECTS_USER_CODE "12" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "12" */
_c_RlsmCem_SerNrLin1Fr01_CEM_LIN1_buf RlsmCem_SerNrLin1Fr01_CEM_LIN1 
/* INITIALIZATION_CODE_USER_CODE "12" */

/* INITIALIZATION_CODE_USER_CODE_END "12" */
;


/* INITIALIZATION_OBJECTS_USER_CODE "13" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "13" */
_c_RlsmCem_Lin1PartNrFr02_CEM_LIN1_buf RlsmCem_Lin1PartNrFr02_CEM_LIN1 
/* INITIALIZATION_CODE_USER_CODE "13" */

/* INITIALIZATION_CODE_USER_CODE_END "13" */
;


/* INITIALIZATION_OBJECTS_USER_CODE "14" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "14" */
_c_RlsmCem_Lin1PartNrFr01_CEM_LIN1_buf RlsmCem_Lin1PartNrFr01_CEM_LIN1 
/* INITIALIZATION_CODE_USER_CODE "14" */

/* INITIALIZATION_CODE_USER_CODE_END "14" */
;


/* INITIALIZATION_OBJECTS_USER_CODE "15" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "15" */
_c_RlsmCem_Lin1Fr03_CEM_LIN1_buf RlsmCem_Lin1Fr03_CEM_LIN1 
/* INITIALIZATION_CODE_USER_CODE "15" */

/* INITIALIZATION_CODE_USER_CODE_END "15" */
;


/* INITIALIZATION_OBJECTS_USER_CODE "16" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "16" */
_c_RlsmCem_Lin1Fr02_CEM_LIN1_buf RlsmCem_Lin1Fr02_CEM_LIN1 
/* INITIALIZATION_CODE_USER_CODE "16" */

/* INITIALIZATION_CODE_USER_CODE_END "16" */
;


/* INITIALIZATION_OBJECTS_USER_CODE "17" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "17" */
_c_RlsmCem_Lin1Fr01_CEM_LIN1_buf RlsmCem_Lin1Fr01_CEM_LIN1 
/* INITIALIZATION_CODE_USER_CODE "17" */

/* INITIALIZATION_CODE_USER_CODE_END "17" */
;


/* INITIALIZATION_OBJECTS_USER_CODE "18" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "18" */
_c_CemCem_Lin1Fr06_CEM_LIN1_buf CemCem_Lin1Fr06_CEM_LIN1 
/* INITIALIZATION_CODE_USER_CODE "18" */

/* INITIALIZATION_CODE_USER_CODE_END "18" */
;


/* INITIALIZATION_OBJECTS_USER_CODE "19" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "19" */
_c_CemCem_Lin1Fr05_CEM_LIN1_buf CemCem_Lin1Fr05_CEM_LIN1 
/* INITIALIZATION_CODE_USER_CODE "19" */

/* INITIALIZATION_CODE_USER_CODE_END "19" */
;


/* INITIALIZATION_OBJECTS_USER_CODE "20" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "20" */
_c_CemCem_Lin1Fr04_CEM_LIN1_buf CemCem_Lin1Fr04_CEM_LIN1 
/* INITIALIZATION_CODE_USER_CODE "20" */

/* INITIALIZATION_CODE_USER_CODE_END "20" */
;


/* INITIALIZATION_OBJECTS_USER_CODE "21" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "21" */
_c_CemCem_Lin1Fr03_CEM_LIN1_buf CemCem_Lin1Fr03_CEM_LIN1 
/* INITIALIZATION_CODE_USER_CODE "21" */

/* INITIALIZATION_CODE_USER_CODE_END "21" */
;


/* INITIALIZATION_OBJECTS_USER_CODE "22" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "22" */
_c_CemCem_Lin1Fr02_CEM_LIN1_buf CemCem_Lin1Fr02_CEM_LIN1 
/* INITIALIZATION_CODE_USER_CODE "22" */

/* INITIALIZATION_CODE_USER_CODE_END "22" */
;


/* INITIALIZATION_OBJECTS_USER_CODE "23" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "23" */
_c_CemCem_Lin1Fr01_CEM_LIN1_buf CemCem_Lin1Fr01_CEM_LIN1 
/* INITIALIZATION_CODE_USER_CODE "23" */

/* INITIALIZATION_CODE_USER_CODE_END "23" */
;


/* INITIALIZATION_OBJECTS_USER_CODE "24" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "24" */
volatile Flag uF_VoltageStatus_g 
/* INITIALIZATION_CODE_USER_CODE "24" */

/* INITIALIZATION_CODE_USER_CODE_END "24" */
;


/* INITIALIZATION_OBJECTS_USER_CODE "25" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "25" */
byte rb_InternalTemperature_g 
/* INITIALIZATION_CODE_USER_CODE "25" */

/* INITIALIZATION_CODE_USER_CODE_END "25" */
;


/* INITIALIZATION_OBJECTS_USER_CODE "26" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "26" */
byte rb_ClockFreq_Error_cnt_g 
/* INITIALIZATION_CODE_USER_CODE "26" */

/* INITIALIZATION_CODE_USER_CODE_END "26" */
;


/* INITIALIZATION_OBJECTS_USER_CODE "27" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "27" */
Flag uF_uC_Error_g 
/* INITIALIZATION_CODE_USER_CODE "27" */

/* INITIALIZATION_CODE_USER_CODE_END "27" */
;


/* INITIALIZATION_OBJECTS_USER_CODE "28" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "28" */
Flag uF_Diagnose_pre_Flag 
/* INITIALIZATION_CODE_USER_CODE "28" */

/* INITIALIZATION_CODE_USER_CODE_END "28" */
;


/* INITIALIZATION_OBJECTS_USER_CODE "29" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "29" */
unsigned char rub_RSIntermDelayInit 
/* INITIALIZATION_CODE_USER_CODE "29" */

/* INITIALIZATION_CODE_USER_CODE_END "29" */
;


/* INITIALIZATION_OBJECTS_USER_CODE "30" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "30" */
unsigned char rb_LimitMemomryNoWiperReaction_g 
/* INITIALIZATION_CODE_USER_CODE "30" */

/* INITIALIZATION_CODE_USER_CODE_END "30" */
;


/* INITIALIZATION_OBJECTS_USER_CODE "31" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "31" */
unsigned char rbi_WiperStarted_g 
/* INITIALIZATION_CODE_USER_CODE "31" */

/* INITIALIZATION_CODE_USER_CODE_END "31" */
;


/* INITIALIZATION_OBJECTS_USER_CODE "32" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "32" */
unsigned char rb_LIN_SensitivityShift_g 
/* INITIALIZATION_CODE_USER_CODE "32" */

/* INITIALIZATION_CODE_USER_CODE_END "32" */
;


/* INITIALIZATION_OBJECTS_USER_CODE "33" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "33" */
volatile RS_Flag RSStatus 
/* INITIALIZATION_CODE_USER_CODE "33" */

/* INITIALIZATION_CODE_USER_CODE_END "33" */
;


/* INITIALIZATION_OBJECTS_USER_CODE "34" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "34" */
unsigned char rub_IntermDelayTime 
/* INITIALIZATION_CODE_USER_CODE "34" */

/* INITIALIZATION_CODE_USER_CODE_END "34" */
;


/* INITIALIZATION_OBJECTS_USER_CODE "35" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "35" */
unsigned char rb_PotiStageFromBox_g 
/* INITIALIZATION_CODE_USER_CODE "35" */

/* INITIALIZATION_CODE_USER_CODE_END "35" */
;


/* INITIALIZATION_OBJECTS_USER_CODE "36" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "36" */
unsigned rw_rain_intensitiy_g 
/* INITIALIZATION_CODE_USER_CODE "36" */

/* INITIALIZATION_CODE_USER_CODE_END "36" */
;


/* INITIALIZATION_OBJECTS_USER_CODE "37" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "37" */
Flag uF_StatusRainsensor_mg 
/* INITIALIZATION_CODE_USER_CODE "37" */

/* INITIALIZATION_CODE_USER_CODE_END "37" */
;


/* INITIALIZATION_OBJECTS_USER_CODE "38" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "38" */
Flag uF_StatusRainsensor2_mg 
/* INITIALIZATION_CODE_USER_CODE "38" */

/* INITIALIZATION_CODE_USER_CODE_END "38" */
;


/* INITIALIZATION_OBJECTS_USER_CODE "39" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "39" */
byte rb_WiperSpeed_g 
/* INITIALIZATION_CODE_USER_CODE "39" */

/* INITIALIZATION_CODE_USER_CODE_END "39" */
;


/* INITIALIZATION_OBJECTS_USER_CODE "40" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "40" */
byte rb_WiperSpeedAlt_g 
/* INITIALIZATION_CODE_USER_CODE "40" */

/* INITIALIZATION_CODE_USER_CODE_END "40" */
;


/* INITIALIZATION_OBJECTS_USER_CODE "41" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "41" */
volatile Flag uF_LIN_DiagReq2_mg 
/* INITIALIZATION_CODE_USER_CODE "41" */

/* INITIALIZATION_CODE_USER_CODE_END "41" */
;


/* INITIALIZATION_OBJECTS_USER_CODE "42" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "42" */
volatile Flag uF_Main_Flags_g 
/* INITIALIZATION_CODE_USER_CODE "42" */

/* INITIALIZATION_CODE_USER_CODE_END "42" */
;


/* INITIALIZATION_OBJECTS_USER_CODE "43" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "43" */
byte rb_RS_LS_Error1_g 
/* INITIALIZATION_CODE_USER_CODE "43" */

/* INITIALIZATION_CODE_USER_CODE_END "43" */
;


/* INITIALIZATION_OBJECTS_USER_CODE "44" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "44" */
byte rb_RS_LS_Error2_g 
/* INITIALIZATION_CODE_USER_CODE "44" */

/* INITIALIZATION_CODE_USER_CODE_END "44" */
;


/* INITIALIZATION_OBJECTS_USER_CODE "45" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "45" */
byte rb_RainS_Error1_g 
/* INITIALIZATION_CODE_USER_CODE "45" */

/* INITIALIZATION_CODE_USER_CODE_END "45" */
;


/* INITIALIZATION_OBJECTS_USER_CODE "46" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "46" */
byte rb_LightS_Error1_g 
/* INITIALIZATION_CODE_USER_CODE "46" */

/* INITIALIZATION_CODE_USER_CODE_END "46" */
;


/* INITIALIZATION_OBJECTS_USER_CODE "47" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "47" */
unsigned rw_EEPROM_Address_to_Write_g 
/* INITIALIZATION_CODE_USER_CODE "47" */

/* INITIALIZATION_CODE_USER_CODE_END "47" */
;


/* INITIALIZATION_OBJECTS_USER_CODE "48" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "48" */
byte rb_I2C_EEPROM_bytesToWrite_g 
/* INITIALIZATION_CODE_USER_CODE "48" */

/* INITIALIZATION_CODE_USER_CODE_END "48" */
;


/* INITIALIZATION_OBJECTS_USER_CODE "49" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "49" */
byte rab_EEPROM_Bytes_toWrite_g[5] 
/* INITIALIZATION_CODE_USER_CODE "49" */

/* INITIALIZATION_CODE_USER_CODE_END "49" */
;


/* INITIALIZATION_OBJECTS_USER_CODE "50" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "50" */
volatile Flag uF_E2ConfigErrorFlags_g 
/* INITIALIZATION_CODE_USER_CODE "50" */

/* INITIALIZATION_CODE_USER_CODE_END "50" */
;


/* INITIALIZATION_OBJECTS_USER_CODE "51" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "51" */
byte rb_speed_in_kmh_g 
/* INITIALIZATION_CODE_USER_CODE "51" */

/* INITIALIZATION_CODE_USER_CODE_END "51" */
;


/* INITIALIZATION_OBJECTS_USER_CODE "52" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "52" */
byte rb_LSPotiStage_g 
/* INITIALIZATION_CODE_USER_CODE "52" */

/* INITIALIZATION_CODE_USER_CODE_END "52" */
;


/* INITIALIZATION_OBJECTS_USER_CODE "53" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "53" */
Flag uF_Check_lightsensor_g 
/* INITIALIZATION_CODE_USER_CODE "53" */

/* INITIALIZATION_CODE_USER_CODE_END "53" */
;


/* INITIALIZATION_OBJECTS_USER_CODE "54" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "54" */
Flag uF_modi_lightsens_g 
/* INITIALIZATION_CODE_USER_CODE "54" */

/* INITIALIZATION_CODE_USER_CODE_END "54" */
;


/* INITIALIZATION_OBJECTS_USER_CODE "55" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "55" */
Flag uF_LightInternalStatus_g 
/* INITIALIZATION_CODE_USER_CODE "55" */

/* INITIALIZATION_CODE_USER_CODE_END "55" */
;


/* INITIALIZATION_OBJECTS_USER_CODE "56" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "56" */
unsigned rw_StandbyTimeOutCnt_g 
/* INITIALIZATION_CODE_USER_CODE "56" */

/* INITIALIZATION_CODE_USER_CODE_END "56" */
;


/* INITIALIZATION_OBJECTS_USER_CODE "57" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "57" */
byte rb_ASIC_ALSx_ShortDetected_cnt_g 
/* INITIALIZATION_CODE_USER_CODE "57" */

/* INITIALIZATION_CODE_USER_CODE_END "57" */
;


/* INITIALIZATION_OBJECTS_USER_CODE "58" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "58" */
byte rb_ASIC_ALSx_ShortDetected_Error_g 
/* INITIALIZATION_CODE_USER_CODE "58" */

/* INITIALIZATION_CODE_USER_CODE_END "58" */
;


/* INITIALIZATION_OBJECTS_USER_CODE "59" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "59" */
Flag uF_ASIC_ControlFlags_g 
/* INITIALIZATION_CODE_USER_CODE "59" */

/* INITIALIZATION_CODE_USER_CODE_END "59" */
;


/* INITIALIZATION_OBJECTS_USER_CODE "60" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "60" */
Flag uF_GainAdjustFlags_g 
/* INITIALIZATION_CODE_USER_CODE "60" */

/* INITIALIZATION_CODE_USER_CODE_END "60" */
;


/* INITIALIZATION_OBJECTS_USER_CODE "61" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "61" */
Flag uF_ASIC_Error_Flags_g 
/* INITIALIZATION_CODE_USER_CODE "61" */

/* INITIALIZATION_CODE_USER_CODE_END "61" */
;


/* INITIALIZATION_OBJECTS_USER_CODE "62" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "62" */
Flag uF_ASIC_Error_Flags1_g 
/* INITIALIZATION_CODE_USER_CODE "62" */

/* INITIALIZATION_CODE_USER_CODE_END "62" */
;


/* INITIALIZATION_OBJECTS_USER_CODE "63" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "63" */
Flag uF_ASIC_Ctrl_Error_Flags_g 
/* INITIALIZATION_CODE_USER_CODE "63" */

/* INITIALIZATION_CODE_USER_CODE_END "63" */
;


/* INITIALIZATION_OBJECTS_USER_CODE "64" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "64" */
unsigned rw_Solar_light16bit_1_g 
/* INITIALIZATION_CODE_USER_CODE "64" */

/* INITIALIZATION_CODE_USER_CODE_END "64" */
;


/* INITIALIZATION_OBJECTS_USER_CODE "65" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "65" */
unsigned rw_Solar_light16bit_2_g 
/* INITIALIZATION_CODE_USER_CODE "65" */

/* INITIALIZATION_CODE_USER_CODE_END "65" */
;


/* INITIALIZATION_OBJECTS_USER_CODE "66" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "66" */
ASIC_ALI_Meas_t ras_ASIC_MUX_MeasAD_g[9] 
/* INITIALIZATION_CODE_USER_CODE "66" */

/* INITIALIZATION_CODE_USER_CODE_END "66" */
;


/* INITIALIZATION_OBJECTS_USER_CODE "67" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "67" */
byte rb_ASIC_initTimeout_g 
/* INITIALIZATION_CODE_USER_CODE "67" */

/* INITIALIZATION_CODE_USER_CODE_END "67" */
;


/* INITIALIZATION_OBJECTS_USER_CODE "68" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "68" */
byte rb_VIref_ErrCnt_g 
/* INITIALIZATION_CODE_USER_CODE "68" */

/* INITIALIZATION_CODE_USER_CODE_END "68" */
;


/* INITIALIZATION_OBJECTS_USER_CODE "69" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "69" */
byte rb_ASIC_SPI_ErrorCodeCnt_g 
/* INITIALIZATION_CODE_USER_CODE "69" */

/* INITIALIZATION_CODE_USER_CODE_END "69" */
;


/* INITIALIZATION_OBJECTS_USER_CODE "70" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "70" */
byte rb_StaticNoValidAD_cnt_g 
/* INITIALIZATION_CODE_USER_CODE "70" */

/* INITIALIZATION_CODE_USER_CODE_END "70" */
;


/* INITIALIZATION_OBJECTS_USER_CODE "71" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "71" */
unsigned rw_SPINoCommCounter_g 
/* INITIALIZATION_CODE_USER_CODE "71" */

/* INITIALIZATION_CODE_USER_CODE_END "71" */
;

/* End defined extern variables */
/* Begin defined static member variables */
/* End defined static member variables */

/* BEGIN PROTOTYPE STUBS */
unsigned char P_10_1_1

;
void sci_init(byte rb_WakeUpFrame_l)
{
  vCAST_USER_CODE_TIMER_STOP();
#line 1 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\vcast_configure_stub.c"

#line 655 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\vcast_stubs_9.c"

  if ( vcast_is_in_driver ) {
    P_10_1_1 = rb_WakeUpFrame_l;
    vCAST_COMMON_STUB_PROC_9( 10, 1, 2, 0 );
  } /* vcast_is_in_driver */
#line 1 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\vcast_configure_stub.c"

#line 662 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\vcast_stubs_9.c"

  vCAST_USER_CODE_TIMER_START();
  return;
}


void Check_StartupActiveErrors(void)
{
  vCAST_USER_CODE_TIMER_STOP();
#line 1 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\vcast_configure_stub.c"

#line 673 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\vcast_stubs_9.c"

  if ( vcast_is_in_driver ) {
    vCAST_COMMON_STUB_PROC_9( 10, 2, 1, 0 );
  } /* vcast_is_in_driver */
#line 1 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\vcast_configure_stub.c"

#line 679 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\vcast_stubs_9.c"

  vCAST_USER_CODE_TIMER_START();
  return;
}


unsigned char R_10_3;
byte get_rb_LightVetoCounter_g(void)
{
  vCAST_USER_CODE_TIMER_STOP();
#line 1 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\vcast_configure_stub.c"

#line 691 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\vcast_stubs_9.c"

  if ( vcast_is_in_driver ) {
    vCAST_COMMON_STUB_PROC_9( 10, 3, 1, 0 );
  } /* vcast_is_in_driver */
#line 1 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\vcast_configure_stub.c"

#line 697 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\vcast_stubs_9.c"

  vCAST_USER_CODE_TIMER_START();
  return R_10_3;
}


unsigned R_10_4;
unsigned get_rw_Amb_light16bit_g(void)
{
  vCAST_USER_CODE_TIMER_STOP();
#line 1 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\vcast_configure_stub.c"

#line 709 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\vcast_stubs_9.c"

  if ( vcast_is_in_driver ) {
    vCAST_COMMON_STUB_PROC_9( 10, 4, 1, 0 );
  } /* vcast_is_in_driver */
#line 1 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\vcast_configure_stub.c"

#line 715 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\vcast_stubs_9.c"

  vCAST_USER_CODE_TIMER_START();
  return R_10_4;
}


unsigned long R_10_5;
unsigned long get_rl_HUD_light32bit_g(void)
{
  vCAST_USER_CODE_TIMER_STOP();
#line 1 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\vcast_configure_stub.c"

#line 727 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\vcast_stubs_9.c"

  if ( vcast_is_in_driver ) {
    vCAST_COMMON_STUB_PROC_9( 10, 5, 1, 0 );
  } /* vcast_is_in_driver */
#line 1 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\vcast_configure_stub.c"

#line 733 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\vcast_stubs_9.c"

  vCAST_USER_CODE_TIMER_START();
  return R_10_5;
}


unsigned R_10_6;
unsigned get_rw_IR_light16bit_g(void)
{
  vCAST_USER_CODE_TIMER_STOP();
#line 1 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\vcast_configure_stub.c"

#line 745 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\vcast_stubs_9.c"

  if ( vcast_is_in_driver ) {
    vCAST_COMMON_STUB_PROC_9( 10, 6, 1, 0 );
  } /* vcast_is_in_driver */
#line 1 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\vcast_configure_stub.c"

#line 751 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\vcast_stubs_9.c"

  vCAST_USER_CODE_TIMER_START();
  return R_10_6;
}


unsigned char R_10_7;
byte get_rb_LightSignalErrorCnt_g(void)
{
  vCAST_USER_CODE_TIMER_STOP();
#line 1 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\vcast_configure_stub.c"

#line 763 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\vcast_stubs_9.c"

  if ( vcast_is_in_driver ) {
    vCAST_COMMON_STUB_PROC_9( 10, 7, 1, 0 );
  } /* vcast_is_in_driver */
#line 1 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\vcast_configure_stub.c"

#line 769 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\vcast_stubs_9.c"

  vCAST_USER_CODE_TIMER_START();
  return R_10_7;
}


unsigned char R_10_8;
byte get_rb_VDD_LightSignalErrorCnt_g(void)
{
  vCAST_USER_CODE_TIMER_STOP();
#line 1 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\vcast_configure_stub.c"

#line 781 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\vcast_stubs_9.c"

  if ( vcast_is_in_driver ) {
    vCAST_COMMON_STUB_PROC_9( 10, 8, 1, 0 );
  } /* vcast_is_in_driver */
#line 1 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\vcast_configure_stub.c"

#line 787 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\vcast_stubs_9.c"

  vCAST_USER_CODE_TIMER_START();
  return R_10_8;
}


unsigned char R_10_9;
byte get_rb_LEDx_LStop_error_cnt_g(void)
{
  vCAST_USER_CODE_TIMER_STOP();
#line 1 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\vcast_configure_stub.c"

#line 799 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\vcast_stubs_9.c"

  if ( vcast_is_in_driver ) {
    vCAST_COMMON_STUB_PROC_9( 10, 9, 1, 0 );
  } /* vcast_is_in_driver */
#line 1 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\vcast_configure_stub.c"

#line 805 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\vcast_stubs_9.c"

  vCAST_USER_CODE_TIMER_START();
  return R_10_9;
}


void CopyRLSDataAsic(void)
{
  vCAST_USER_CODE_TIMER_STOP();
#line 1 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\vcast_configure_stub.c"

#line 816 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\vcast_stubs_9.c"

  if ( vcast_is_in_driver ) {
    vCAST_COMMON_STUB_PROC_9( 10, 10, 1, 0 );
  } /* vcast_is_in_driver */
#line 1 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\vcast_configure_stub.c"

#line 822 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\vcast_stubs_9.c"

  vCAST_USER_CODE_TIMER_START();
  return;
}


/* END PROTOTYPE STUBS */
#line 146 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\S0000009.c"
/* begin declarations of inlined friends */
/* end declarations of inlined friends */
void VCAST_DRIVER_9( int VC_SUBPROGRAM, char *VC_EVENT_FLAGS, char *VC_SLOT_DESCR ) {



  switch( VC_SUBPROGRAM ) {
    case 0:
      vCAST_SET_HISTORY_FLAGS ( 9, 0, VC_EVENT_FLAGS, VC_SLOT_DESCR );
      break;
    case 1: {
      /* void GetLeWWS(void) */
      vCAST_SET_HISTORY_FLAGS ( 9, 1, VC_EVENT_FLAGS, VC_SLOT_DESCR );
      ( GetLeWWS( ) );
      break; }
    case 2: {
      /* void GetLsWWS(void) */
      vCAST_SET_HISTORY_FLAGS ( 9, 2, VC_EVENT_FLAGS, VC_SLOT_DESCR );
      ( GetLsWWS( ) );
      break; }
    case 3: {
      /* void CopyRLSData(void) */
      vCAST_SET_HISTORY_FLAGS ( 9, 3, VC_EVENT_FLAGS, VC_SLOT_DESCR );
      ( CopyRLSData( ) );
      break; }
    case 4: {
      /* void RainFunction(void) */
      vCAST_SET_HISTORY_FLAGS ( 9, 4, VC_EVENT_FLAGS, VC_SLOT_DESCR );
      ( RainFunction( ) );
      break; }
    case 5: {
      /* void LightFunction(void) */
      vCAST_SET_HISTORY_FLAGS ( 9, 5, VC_EVENT_FLAGS, VC_SLOT_DESCR );
      ( LightFunction( ) );
      break; }
    case 6: {
      /* void Humidity_Function(void) */
      vCAST_SET_HISTORY_FLAGS ( 9, 6, VC_EVENT_FLAGS, VC_SLOT_DESCR );
      ( Humidity_Function( ) );
      break; }
    case 7: {
      /* void StandByMode(void) */
      vCAST_SET_HISTORY_FLAGS ( 9, 7, VC_EVENT_FLAGS, VC_SLOT_DESCR );
      ( StandByMode( ) );
      break; }
    case 8: {
      /* void VoltageDetect(void) */
      vCAST_SET_HISTORY_FLAGS ( 9, 8, VC_EVENT_FLAGS, VC_SLOT_DESCR );
      ( VoltageDetect( ) );
      break; }
    case 9: {
      /* void TemperatureDetect(void) */
      vCAST_SET_HISTORY_FLAGS ( 9, 9, VC_EVENT_FLAGS, VC_SLOT_DESCR );
      ( TemperatureDetect( ) );
      break; }
    case 10: {
      /* void OutPutHudSendCount(void) */
      vCAST_SET_HISTORY_FLAGS ( 9, 10, VC_EVENT_FLAGS, VC_SLOT_DESCR );
      ( OutPutHudSendCount( ) );
      break; }
    case 11: {
      /* void OutPutHudValue(void) */
      vCAST_SET_HISTORY_FLAGS ( 9, 11, VC_EVENT_FLAGS, VC_SLOT_DESCR );
      ( OutPutHudValue( ) );
      break; }
    case 12: {
      /* void OutPutTwliBriValue(void) */
      vCAST_SET_HISTORY_FLAGS ( 9, 12, VC_EVENT_FLAGS, VC_SLOT_DESCR );
      ( OutPutTwliBriValue( ) );
      break; }
    case 13: {
      /* void OutPutSolarValue(void) */
      vCAST_SET_HISTORY_FLAGS ( 9, 13, VC_EVENT_FLAGS, VC_SLOT_DESCR );
      ( OutPutSolarValue( ) );
      break; }
    case 14: {
      /* void OutPutBrightnessValue(void) */
      vCAST_SET_HISTORY_FLAGS ( 9, 14, VC_EVENT_FLAGS, VC_SLOT_DESCR );
      ( OutPutBrightnessValue( ) );
      break; }
    case 15: {
      /* void CheckErrors(void) */
      vCAST_SET_HISTORY_FLAGS ( 9, 15, VC_EVENT_FLAGS, VC_SLOT_DESCR );
      ( CheckErrors( ) );
      break; }
    case 16: {
      /* void ApplLinInit(byte rb_LIN_State_l) */
      vCAST_SET_HISTORY_FLAGS ( 9, 16, VC_EVENT_FLAGS, VC_SLOT_DESCR );
      ( ApplLinInit(
        ( P_9_16_1 ) ) );
      break; }
    case 17: {
      /* __callt void ApplLinSlavePreCopy(byte rb_MessageID_l) */
      vCAST_SET_HISTORY_FLAGS ( 9, 17, VC_EVENT_FLAGS, VC_SLOT_DESCR );
      ( ApplLinSlavePreCopy(
        ( P_9_17_1 ) ) );
      break; }
    case 18: {
      /* void GetFiveTableValue_500ms(unsigned long rl_HUD_Brightness_50ms) */
      vCAST_SET_HISTORY_FLAGS ( 9, 18, VC_EVENT_FLAGS, VC_SLOT_DESCR );
      ( GetFiveTableValue_500ms(
        ( P_9_18_1 ) ) );
      break; }
    case 19: {
      /* unsigned long AdjustOutHudValue(unsigned long rl_CurrentHud) */
      vCAST_SET_HISTORY_FLAGS ( 9, 19, VC_EVENT_FLAGS, VC_SLOT_DESCR );
      R_9_19 = 
      ( AdjustOutHudValue(
        ( P_9_19_1 ) ) );
      break; }
    case 20: {
      /* unsigned char GetUpdateTimeForLightStatus(void) */
      vCAST_SET_HISTORY_FLAGS ( 9, 20, VC_EVENT_FLAGS, VC_SLOT_DESCR );
      R_9_20 = 
      ( GetUpdateTimeForLightStatus( ) );
      break; }
    case 21: {
      /* unsigned long CalcHUDMean_1000ms(void) */
      vCAST_SET_HISTORY_FLAGS ( 9, 21, VC_EVENT_FLAGS, VC_SLOT_DESCR );
      R_9_21 = 
      ( CalcHUDMean_1000ms( ) );
      break; }
    case 22: {
      /* void orderHUDValue(int n) */
      vCAST_SET_HISTORY_FLAGS ( 9, 22, VC_EVENT_FLAGS, VC_SLOT_DESCR );
      ( orderHUDValue(
        ( P_9_22_1 ) ) );
      break; }
    case 23: {
      /* void GetFiveTableValue_50ms(unsigned long Fw, unsigned long Amb) */
      vCAST_SET_HISTORY_FLAGS ( 9, 23, VC_EVENT_FLAGS, VC_SLOT_DESCR );
      ( GetFiveTableValue_50ms(
        ( P_9_23_1 ),
        ( P_9_23_2 ) ) );
      break; }
    case 24: {
      /* byte CRC8SAEJ1850(byte * u8_data, byte u8_len) */
      vCAST_SET_HISTORY_FLAGS ( 9, 24, VC_EVENT_FLAGS, VC_SLOT_DESCR );
      R_9_24 = 
      ( CRC8SAEJ1850(
        ( P_9_24_1 ),
        ( P_9_24_2 ) ) );
      break; }
    case 25: {
      /* byte GetOutdBriStsCrcj1850(byte OutdBriSts) */
      vCAST_SET_HISTORY_FLAGS ( 9, 25, VC_EVENT_FLAGS, VC_SLOT_DESCR );
      R_9_25 = 
      ( GetOutdBriStsCrcj1850(
        ( P_9_25_1 ) ) );
      break; }
    case 26: {
      /* byte GetHudCrcj1850(unsigned long hudSrc) */
      vCAST_SET_HISTORY_FLAGS ( 9, 26, VC_EVENT_FLAGS, VC_SLOT_DESCR );
      R_9_26 = 
      ( GetHudCrcj1850(
        ( P_9_26_1 ) ) );
      break; }
    case 27: {
      /* void GetLightTransmission(byte trans_550nm, byte trans_880nm) */
      vCAST_SET_HISTORY_FLAGS ( 9, 27, VC_EVENT_FLAGS, VC_SLOT_DESCR );
      ( GetLightTransmission(
        ( P_9_27_1 ),
        ( P_9_27_2 ) ) );
      break; }
    case 28: {
      /* void Get_BCMVehType(byte CarType) */
      vCAST_SET_HISTORY_FLAGS ( 9, 28, VC_EVENT_FLAGS, VC_SLOT_DESCR );
      ( Get_BCMVehType(
        ( P_9_28_1 ) ) );
      break; }
    case 29: {
      /* void Set_BCMLightOffset(byte offset) */
      vCAST_SET_HISTORY_FLAGS ( 9, 29, VC_EVENT_FLAGS, VC_SLOT_DESCR );
      ( Set_BCMLightOffset(
        ( P_9_29_1 ) ) );
      break; }
    case 30: {
      /* void SendRLSSerNo(void) */
      vCAST_SET_HISTORY_FLAGS ( 9, 30, VC_EVENT_FLAGS, VC_SLOT_DESCR );
      ( SendRLSSerNo( ) );
      break; }
    case 31: {
      /* void SendRLSMPartNo(void) */
      vCAST_SET_HISTORY_FLAGS ( 9, 31, VC_EVENT_FLAGS, VC_SLOT_DESCR );
      ( SendRLSMPartNo( ) );
      break; }
    case 32: {
      /* void SendRLSMPartNo10(void) */
      vCAST_SET_HISTORY_FLAGS ( 9, 32, VC_EVENT_FLAGS, VC_SLOT_DESCR );
      ( SendRLSMPartNo10( ) );
      break; }
    case 33: {
      /* void WipeWinterModeCheck(void) */
      vCAST_SET_HISTORY_FLAGS ( 9, 33, VC_EVENT_FLAGS, VC_SLOT_DESCR );
      ( WipeWinterModeCheck( ) );
      break; }
    case 34: {
      /* byte IsByteOddParity(byte data) */
      vCAST_SET_HISTORY_FLAGS ( 9, 34, VC_EVENT_FLAGS, VC_SLOT_DESCR );
      R_9_34 = 
      ( IsByteOddParity(
        ( P_9_34_1 ) ) );
      break; }
    default:
      vectorcast_print_string("ERROR: Internal Tool Error\n");
      break;
  } /* switch */
}

#line 1 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\vcast_ti_decls_9.h"




void VCAST_TI_8_2 ( int *vcast_param ) ;

void VCAST_TI_9_1 ( _c_CemCem_Lin1Fr05_CEM_LIN1_buf *vcast_param ) ;

void VCAST_TI_9_10 ( _c_CemCem_Lin1Fr02_CEM_LIN1_buf *vcast_param ) ;

void VCAST_TI_9_11 ( _c_CemCem_Lin1Fr02_CEM_LIN1_msgType *vcast_param ) ;

void VCAST_TI_9_111 ( unsigned char vcast_param[6] ) ;

void VCAST_TI_9_12 ( _c_RlsmCem_Lin1Fr01_CEM_LIN1_buf *vcast_param ) ;

void VCAST_TI_9_13 ( _c_RlsmCem_Lin1Fr01_CEM_LIN1_msgType *vcast_param ) ;

void VCAST_TI_9_14 ( _c_CemCem_Lin1Fr03_CEM_LIN1_buf *vcast_param ) ;

void VCAST_TI_9_15 ( _c_CemCem_Lin1Fr03_CEM_LIN1_msgType *vcast_param ) ;

void VCAST_TI_9_16 ( _c_CemCem_Lin1Fr04_CEM_LIN1_buf *vcast_param ) ;

void VCAST_TI_9_17 ( _c_CemCem_Lin1Fr04_CEM_LIN1_msgType *vcast_param ) ;

void VCAST_TI_9_18 ( _c_CemCem_Lin1Fr06_CEM_LIN1_buf *vcast_param ) ;

void VCAST_TI_9_19 ( _c_CemCem_Lin1Fr06_CEM_LIN1_msgType *vcast_param ) ;

void VCAST_TI_9_2 ( _c_CemCem_Lin1Fr05_CEM_LIN1_msgType *vcast_param ) ;

void VCAST_TI_9_20 ( volatile RS_Flag *vcast_param ) ;

void VCAST_TI_9_21 ( RS_Bit_Feld *vcast_param ) ;

void VCAST_TI_9_22 ( unsigned *vcast_param ) ;

void VCAST_TI_9_23 ( Flag *vcast_param ) ;

void VCAST_TI_9_24 ( _c_CemCem_Lin1Fr01_CEM_LIN1_buf *vcast_param ) ;

void VCAST_TI_9_25 ( _c_CemCem_Lin1Fr01_CEM_LIN1_msgType *vcast_param ) ;

void VCAST_TI_9_26 ( s_rb_EEPROMStructPD_buff_g *vcast_param ) ;

void VCAST_TI_9_27 ( s_rb_EEPROMStruct_PD_g *vcast_param ) ;

void VCAST_TI_9_28 ( s_rb_EEPROMStructAD_buff_g *vcast_param ) ;

void VCAST_TI_9_29 ( s_rb_EEPROMStruct_AD_g *vcast_param ) ;

void VCAST_TI_9_30 ( union tLinConfirmationBits *vcast_param ) ;

void VCAST_TI_9_31 ( struct _c_bits16 vcast_param[(11 + 15) / 16] ) ;

void VCAST_TI_9_32 ( struct _c_bits16 *vcast_param ) ;

void VCAST_TI_9_33 ( _c_RlsmCem_Lin1Fr03_CEM_LIN1_buf *vcast_param ) ;

void VCAST_TI_9_34 ( _c_RlsmCem_Lin1Fr03_CEM_LIN1_msgType *vcast_param ) ;

void VCAST_TI_9_35 ( _c_RlsmCem_Lin1Fr02_CEM_LIN1_buf *vcast_param ) ;

void VCAST_TI_9_36 ( _c_RlsmCem_Lin1Fr02_CEM_LIN1_msgType *vcast_param ) ;

void VCAST_TI_9_37 ( ASIC_ALI_Meas_t vcast_param[9] ) ;

void VCAST_TI_9_38 ( ASIC_ALI_Meas_t *vcast_param ) ;

void VCAST_TI_9_39 ( unsigned long *vcast_param ) ;

void VCAST_TI_9_4 ( volatile Flag *vcast_param ) ;

void VCAST_TI_9_40 ( _c_RlsmCem_SerNrLin1Fr01_CEM_LIN1_buf *vcast_param ) ;

void VCAST_TI_9_41 ( unsigned char vcast_param[4] ) ;

void VCAST_TI_9_42 ( _c_RlsmCem_Lin1PartNrFr02_CEM_LIN1_buf *vcast_param ) ;

void VCAST_TI_9_43 ( unsigned char vcast_param[8] ) ;

void VCAST_TI_9_44 ( _c_RlsmCem_Lin1PartNrFr01_CEM_LIN1_buf *vcast_param ) ;

void VCAST_TI_9_45 ( unsigned char vcast_param[7] ) ;

void VCAST_TI_9_49 ( unsigned long vcast_param[10] ) ;

void VCAST_TI_9_5 ( Bit_Feld *vcast_param ) ;

void VCAST_TI_9_50 ( unsigned long vcast_param[2] ) ;

void VCAST_TI_9_53 ( unsigned char **vcast_param ) ;

void VCAST_TI_9_54 ( unsigned char vcast_param[5] ) ;

void VCAST_TI_9_55 ( _c_RlsmCem_SerNrLin1Fr01_CEM_LIN1_msgType *vcast_param ) ;

void VCAST_TI_9_57 ( _c_RlsmCem_Lin1PartNrFr01_CEM_LIN1_msgType *vcast_param ) ;

void VCAST_TI_9_59 ( _c_RlsmCem_Lin1PartNrFr02_CEM_LIN1_msgType *vcast_param ) ;

void VCAST_TI_9_6 ( unsigned char *vcast_param ) ;

void VCAST_TI_9_63 ( unsigned char vcast_param[12] ) ;

void VCAST_TI_9_64 ( unsigned char vcast_param[2] ) ;

void VCAST_TI_9_65 ( unsigned char vcast_param[3] ) ;

void VCAST_TI_9_68 ( unsigned char vcast_param[(93 + 4) + 10] ) ;

void VCAST_TI_9_7 ( union tLinIndicationBits *vcast_param ) ;

void VCAST_TI_9_70 ( s_rb_PrametersStruct_g *vcast_param ) ;

void VCAST_TI_9_72 ( s_rb_PrametersStruct_g vcast_param[4] ) ;

void VCAST_TI_9_74 ( unsigned char vcast_param[9] ) ;

void VCAST_TI_9_77 ( unsigned char vcast_param[33] ) ;

void VCAST_TI_9_79 ( unsigned char vcast_param[194] ) ;

void VCAST_TI_9_8 ( struct _c_bits8 vcast_param[1] ) ;

void VCAST_TI_9_80 ( unsigned char vcast_param[1] ) ;

void VCAST_TI_9_81 ( unsigned char vcast_param[(11 + 7) / 8] ) ;

void VCAST_TI_9_9 ( struct _c_bits8 *vcast_param ) ;


#line 356 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\S0000009.c"
void VCAST_RUN_DATA_IF_9( int VCAST_SUB_INDEX, int VCAST_PARAM_INDEX ) {
  switch ( VCAST_SUB_INDEX ) {
    case 0: /* for global objects */
      switch( VCAST_PARAM_INDEX ) {
        case 39: /* for global object EEPROM_Struct_PD */
          VCAST_TI_9_26 ( ((s_rb_EEPROMStructPD_buff_g *)(&(EEPROM_Struct_PD))));
          break;
        case 40: /* for global object rb_Humidity_raw_g */
          VCAST_TI_9_6 ( ((unsigned char *)(&(rb_Humidity_raw_g))));
          break;
        case 41: /* for global object rb_Humidity_g */
          VCAST_TI_9_6 ( ((unsigned char *)(&(rb_Humidity_g))));
          break;
        case 42: /* for global object rw_Temperature_raw_g */
          VCAST_TI_9_22 ( ((unsigned *)(&(rw_Temperature_raw_g))));
          break;
        case 43: /* for global object rw_DewPoint_g */
          VCAST_TI_9_22 ( ((unsigned *)(&(rw_DewPoint_g))));
          break;
        case 44: /* for global object rbi_HumTempComError_g */
          VCAST_TI_9_6 ( ((unsigned char *)(&(rbi_HumTempComError_g))));
          break;
        case 45: /* for global object EEPROM_Struct_AD */
          VCAST_TI_9_28 ( ((s_rb_EEPROMStructAD_buff_g *)(&(EEPROM_Struct_AD))));
          break;
        case 46: /* for global object rb_WDG_BusTaskCounter_g */
          VCAST_TI_9_6 ( ((unsigned char *)(&(rb_WDG_BusTaskCounter_g))));
          break;
        case 47: /* for global object uLinIndicationFlags */
          VCAST_TI_9_7 ( ((union tLinIndicationBits *)(&(uLinIndicationFlags))));
          break;
        case 48: /* for global object uLinConfirmationFlags */
          VCAST_TI_9_30 ( ((union tLinConfirmationBits *)(&(uLinConfirmationFlags))));
          break;
        case 49: /* for global object rb_WakeupCounter_mg */
          VCAST_TI_9_6 ( ((unsigned char *)(&(rb_WakeupCounter_mg))));
          break;
        case 1: /* for global object uF_SCIFlags_mg */
          VCAST_TI_9_4 ( ((volatile Flag *)(&(uF_SCIFlags_mg))));
          break;
        case 2: /* for global object rb_LIN_BIT_ERROR_COUNTER_g */
          VCAST_TI_9_6 ( ((unsigned char *)(&(rb_LIN_BIT_ERROR_COUNTER_g))));
          break;
        case 3: /* for global object rb_LIN_OVERTHEADERMAX_COUNTER_g */
          VCAST_TI_9_6 ( ((unsigned char *)(&(rb_LIN_OVERTHEADERMAX_COUNTER_g))));
          break;
        case 4: /* for global object rb_LIN_CHECKSUMERROR_COUNTER_g */
          VCAST_TI_9_6 ( ((unsigned char *)(&(rb_LIN_CHECKSUMERROR_COUNTER_g))));
          break;
        case 5: /* for global object rb_LIN_OVERTFRAMEMAX_COUNTER_g */
          VCAST_TI_9_6 ( ((unsigned char *)(&(rb_LIN_OVERTFRAMEMAX_COUNTER_g))));
          break;
        case 6: /* for global object rb_LIN_NORESPONSE_COUNTER_g */
          VCAST_TI_9_6 ( ((unsigned char *)(&(rb_LIN_NORESPONSE_COUNTER_g))));
          break;
        case 7: /* for global object rb_LIN_FRAMINGERROR_COUNTER_g */
          VCAST_TI_9_6 ( ((unsigned char *)(&(rb_LIN_FRAMINGERROR_COUNTER_g))));
          break;
        case 8: /* for global object uF_Communication_mg */
          VCAST_TI_9_23 ( ((Flag *)(&(uF_Communication_mg))));
          break;
        case 9: /* for global object uF_Butterfly_Flags_g */
          VCAST_TI_9_4 ( ((volatile Flag *)(&(uF_Butterfly_Flags_g))));
          break;
        case 10: /* for global object rb_LastLINErrorCode_g */
          VCAST_TI_9_6 ( ((unsigned char *)(&(rb_LastLINErrorCode_g))));
          break;
        case 11: /* for global object rw_NoCommunicationCounter_g */
          VCAST_TI_9_22 ( ((unsigned *)(&(rw_NoCommunicationCounter_g))));
          break;
        case 12: /* for global object rb_intervaltime_rainSensorOff_g */
          VCAST_TI_9_6 ( ((unsigned char *)(&(rb_intervaltime_rainSensorOff_g))));
          break;
        case 13: /* for global object rb_Release_IntervalMarker_Update_g */
          VCAST_TI_9_6 ( ((unsigned char *)(&(rb_Release_IntervalMarker_Update_g))));
          break;
        case 50: /* for global object RlsmCem_SerNrLin1Fr01_CEM_LIN1 */
          VCAST_TI_9_40 ( ((_c_RlsmCem_SerNrLin1Fr01_CEM_LIN1_buf *)(&(RlsmCem_SerNrLin1Fr01_CEM_LIN1))));
          break;
        case 51: /* for global object RlsmCem_Lin1PartNrFr02_CEM_LIN1 */
          VCAST_TI_9_42 ( ((_c_RlsmCem_Lin1PartNrFr02_CEM_LIN1_buf *)(&(RlsmCem_Lin1PartNrFr02_CEM_LIN1))));
          break;
        case 52: /* for global object RlsmCem_Lin1PartNrFr01_CEM_LIN1 */
          VCAST_TI_9_44 ( ((_c_RlsmCem_Lin1PartNrFr01_CEM_LIN1_buf *)(&(RlsmCem_Lin1PartNrFr01_CEM_LIN1))));
          break;
        case 53: /* for global object RlsmCem_Lin1Fr03_CEM_LIN1 */
          VCAST_TI_9_33 ( ((_c_RlsmCem_Lin1Fr03_CEM_LIN1_buf *)(&(RlsmCem_Lin1Fr03_CEM_LIN1))));
          break;
        case 54: /* for global object RlsmCem_Lin1Fr02_CEM_LIN1 */
          VCAST_TI_9_35 ( ((_c_RlsmCem_Lin1Fr02_CEM_LIN1_buf *)(&(RlsmCem_Lin1Fr02_CEM_LIN1))));
          break;
        case 55: /* for global object RlsmCem_Lin1Fr01_CEM_LIN1 */
          VCAST_TI_9_12 ( ((_c_RlsmCem_Lin1Fr01_CEM_LIN1_buf *)(&(RlsmCem_Lin1Fr01_CEM_LIN1))));
          break;
        case 56: /* for global object CemCem_Lin1Fr06_CEM_LIN1 */
          VCAST_TI_9_18 ( ((_c_CemCem_Lin1Fr06_CEM_LIN1_buf *)(&(CemCem_Lin1Fr06_CEM_LIN1))));
          break;
        case 57: /* for global object CemCem_Lin1Fr05_CEM_LIN1 */
          VCAST_TI_9_1 ( ((_c_CemCem_Lin1Fr05_CEM_LIN1_buf *)(&(CemCem_Lin1Fr05_CEM_LIN1))));
          break;
        case 58: /* for global object CemCem_Lin1Fr04_CEM_LIN1 */
          VCAST_TI_9_16 ( ((_c_CemCem_Lin1Fr04_CEM_LIN1_buf *)(&(CemCem_Lin1Fr04_CEM_LIN1))));
          break;
        case 59: /* for global object CemCem_Lin1Fr03_CEM_LIN1 */
          VCAST_TI_9_14 ( ((_c_CemCem_Lin1Fr03_CEM_LIN1_buf *)(&(CemCem_Lin1Fr03_CEM_LIN1))));
          break;
        case 60: /* for global object CemCem_Lin1Fr02_CEM_LIN1 */
          VCAST_TI_9_10 ( ((_c_CemCem_Lin1Fr02_CEM_LIN1_buf *)(&(CemCem_Lin1Fr02_CEM_LIN1))));
          break;
        case 61: /* for global object CemCem_Lin1Fr01_CEM_LIN1 */
          VCAST_TI_9_24 ( ((_c_CemCem_Lin1Fr01_CEM_LIN1_buf *)(&(CemCem_Lin1Fr01_CEM_LIN1))));
          break;
        case 62: /* for global object uF_VoltageStatus_g */
          VCAST_TI_9_4 ( ((volatile Flag *)(&(uF_VoltageStatus_g))));
          break;
        case 63: /* for global object rb_InternalTemperature_g */
          VCAST_TI_9_6 ( ((unsigned char *)(&(rb_InternalTemperature_g))));
          break;
        case 64: /* for global object rb_ClockFreq_Error_cnt_g */
          VCAST_TI_9_6 ( ((unsigned char *)(&(rb_ClockFreq_Error_cnt_g))));
          break;
        case 65: /* for global object uF_uC_Error_g */
          VCAST_TI_9_23 ( ((Flag *)(&(uF_uC_Error_g))));
          break;
        case 66: /* for global object uF_Diagnose_pre_Flag */
          VCAST_TI_9_23 ( ((Flag *)(&(uF_Diagnose_pre_Flag))));
          break;
        case 67: /* for global object rub_RSIntermDelayInit */
          VCAST_TI_9_6 ( ((unsigned char *)(&(rub_RSIntermDelayInit))));
          break;
        case 68: /* for global object rb_LimitMemomryNoWiperReaction_g */
          VCAST_TI_9_6 ( ((unsigned char *)(&(rb_LimitMemomryNoWiperReaction_g))));
          break;
        case 69: /* for global object rbi_WiperStarted_g */
          VCAST_TI_9_6 ( ((unsigned char *)(&(rbi_WiperStarted_g))));
          break;
        case 70: /* for global object rb_LIN_SensitivityShift_g */
          VCAST_TI_9_6 ( ((unsigned char *)(&(rb_LIN_SensitivityShift_g))));
          break;
        case 71: /* for global object RSStatus */
          VCAST_TI_9_20 ( ((volatile RS_Flag *)(&(RSStatus))));
          break;
        case 72: /* for global object rub_IntermDelayTime */
          VCAST_TI_9_6 ( ((unsigned char *)(&(rub_IntermDelayTime))));
          break;
        case 73: /* for global object rb_PotiStageFromBox_g */
          VCAST_TI_9_6 ( ((unsigned char *)(&(rb_PotiStageFromBox_g))));
          break;
        case 74: /* for global object rw_rain_intensitiy_g */
          VCAST_TI_9_22 ( ((unsigned *)(&(rw_rain_intensitiy_g))));
          break;
        case 75: /* for global object uF_StatusRainsensor_mg */
          VCAST_TI_9_23 ( ((Flag *)(&(uF_StatusRainsensor_mg))));
          break;
        case 76: /* for global object uF_StatusRainsensor2_mg */
          VCAST_TI_9_23 ( ((Flag *)(&(uF_StatusRainsensor2_mg))));
          break;
        case 77: /* for global object rb_WiperSpeed_g */
          VCAST_TI_9_6 ( ((unsigned char *)(&(rb_WiperSpeed_g))));
          break;
        case 78: /* for global object rb_WiperSpeedAlt_g */
          VCAST_TI_9_6 ( ((unsigned char *)(&(rb_WiperSpeedAlt_g))));
          break;
        case 79: /* for global object uF_LIN_DiagReq2_mg */
          VCAST_TI_9_4 ( ((volatile Flag *)(&(uF_LIN_DiagReq2_mg))));
          break;
        case 80: /* for global object uF_Main_Flags_g */
          VCAST_TI_9_4 ( ((volatile Flag *)(&(uF_Main_Flags_g))));
          break;
        case 81: /* for global object rb_RS_LS_Error1_g */
          VCAST_TI_9_6 ( ((unsigned char *)(&(rb_RS_LS_Error1_g))));
          break;
        case 82: /* for global object rb_RS_LS_Error2_g */
          VCAST_TI_9_6 ( ((unsigned char *)(&(rb_RS_LS_Error2_g))));
          break;
        case 83: /* for global object rb_RainS_Error1_g */
          VCAST_TI_9_6 ( ((unsigned char *)(&(rb_RainS_Error1_g))));
          break;
        case 84: /* for global object rb_LightS_Error1_g */
          VCAST_TI_9_6 ( ((unsigned char *)(&(rb_LightS_Error1_g))));
          break;
        case 85: /* for global object rw_EEPROM_Address_to_Write_g */
          VCAST_TI_9_22 ( ((unsigned *)(&(rw_EEPROM_Address_to_Write_g))));
          break;
        case 86: /* for global object rb_I2C_EEPROM_bytesToWrite_g */
          VCAST_TI_9_6 ( ((unsigned char *)(&(rb_I2C_EEPROM_bytesToWrite_g))));
          break;
        case 87: /* for global object rab_EEPROM_Bytes_toWrite_g */
          VCAST_TI_9_54 ( ((unsigned char *)(rab_EEPROM_Bytes_toWrite_g)));
          break;
        case 88: /* for global object uF_E2ConfigErrorFlags_g */
          VCAST_TI_9_4 ( ((volatile Flag *)(&(uF_E2ConfigErrorFlags_g))));
          break;
        case 89: /* for global object rb_speed_in_kmh_g */
          VCAST_TI_9_6 ( ((unsigned char *)(&(rb_speed_in_kmh_g))));
          break;
        case 90: /* for global object rb_LSPotiStage_g */
          VCAST_TI_9_6 ( ((unsigned char *)(&(rb_LSPotiStage_g))));
          break;
        case 91: /* for global object uF_Check_lightsensor_g */
          VCAST_TI_9_23 ( ((Flag *)(&(uF_Check_lightsensor_g))));
          break;
        case 92: /* for global object uF_modi_lightsens_g */
          VCAST_TI_9_23 ( ((Flag *)(&(uF_modi_lightsens_g))));
          break;
        case 93: /* for global object uF_LightInternalStatus_g */
          VCAST_TI_9_23 ( ((Flag *)(&(uF_LightInternalStatus_g))));
          break;
        case 94: /* for global object rw_StandbyTimeOutCnt_g */
          VCAST_TI_9_22 ( ((unsigned *)(&(rw_StandbyTimeOutCnt_g))));
          break;
        case 95: /* for global object rb_ASIC_ALSx_ShortDetected_cnt_g */
          VCAST_TI_9_6 ( ((unsigned char *)(&(rb_ASIC_ALSx_ShortDetected_cnt_g))));
          break;
        case 96: /* for global object rb_ASIC_ALSx_ShortDetected_Error_g */
          VCAST_TI_9_6 ( ((unsigned char *)(&(rb_ASIC_ALSx_ShortDetected_Error_g))));
          break;
        case 97: /* for global object uF_ASIC_ControlFlags_g */
          VCAST_TI_9_23 ( ((Flag *)(&(uF_ASIC_ControlFlags_g))));
          break;
        case 98: /* for global object uF_GainAdjustFlags_g */
          VCAST_TI_9_23 ( ((Flag *)(&(uF_GainAdjustFlags_g))));
          break;
        case 99: /* for global object uF_ASIC_Error_Flags_g */
          VCAST_TI_9_23 ( ((Flag *)(&(uF_ASIC_Error_Flags_g))));
          break;
        case 100: /* for global object uF_ASIC_Error_Flags1_g */
          VCAST_TI_9_23 ( ((Flag *)(&(uF_ASIC_Error_Flags1_g))));
          break;
        case 101: /* for global object uF_ASIC_Ctrl_Error_Flags_g */
          VCAST_TI_9_23 ( ((Flag *)(&(uF_ASIC_Ctrl_Error_Flags_g))));
          break;
        case 102: /* for global object rw_Solar_light16bit_1_g */
          VCAST_TI_9_22 ( ((unsigned *)(&(rw_Solar_light16bit_1_g))));
          break;
        case 103: /* for global object rw_Solar_light16bit_2_g */
          VCAST_TI_9_22 ( ((unsigned *)(&(rw_Solar_light16bit_2_g))));
          break;
        case 104: /* for global object ras_ASIC_MUX_MeasAD_g */
          VCAST_TI_9_37 ( ((ASIC_ALI_Meas_t *)(ras_ASIC_MUX_MeasAD_g)));
          break;
        case 105: /* for global object rb_ASIC_initTimeout_g */
          VCAST_TI_9_6 ( ((unsigned char *)(&(rb_ASIC_initTimeout_g))));
          break;
        case 106: /* for global object rb_VIref_ErrCnt_g */
          VCAST_TI_9_6 ( ((unsigned char *)(&(rb_VIref_ErrCnt_g))));
          break;
        case 107: /* for global object rb_ASIC_SPI_ErrorCodeCnt_g */
          VCAST_TI_9_6 ( ((unsigned char *)(&(rb_ASIC_SPI_ErrorCodeCnt_g))));
          break;
        case 108: /* for global object rb_StaticNoValidAD_cnt_g */
          VCAST_TI_9_6 ( ((unsigned char *)(&(rb_StaticNoValidAD_cnt_g))));
          break;
        case 109: /* for global object rw_SPINoCommCounter_g */
          VCAST_TI_9_22 ( ((unsigned *)(&(rw_SPINoCommCounter_g))));
          break;
        case 14: /* for global object uF_StalkInPos_Flags_g */
          VCAST_TI_9_4 ( ((volatile Flag *)(&(uF_StalkInPos_Flags_g))));
          break;
        case 15: /* for global object rb_Verglasun_offenDebounce_mg */
          VCAST_TI_9_6 ( ((unsigned char *)(&(rb_Verglasun_offenDebounce_mg))));
          break;
        case 16: /* for global object rb_Verglasun_ClosedDebounce_mg */
          VCAST_TI_9_6 ( ((unsigned char *)(&(rb_Verglasun_ClosedDebounce_mg))));
          break;
        case 17: /* for global object rw_CommandCloseWindowTimout_mg */
          VCAST_TI_9_22 ( ((unsigned *)(&(rw_CommandCloseWindowTimout_mg))));
          break;
        case 18: /* for global object rb_KL15_mg */
          VCAST_TI_9_6 ( ((unsigned char *)(&(rb_KL15_mg))));
          break;
        case 19: /* for global object rb_AnyErrorCounterDebounce_mg */
          VCAST_TI_9_6 ( ((unsigned char *)(&(rb_AnyErrorCounterDebounce_mg))));
          break;
        case 20: /* for global object rw_AfterRSWipeCounter_mg */
          VCAST_TI_9_22 ( ((unsigned *)(&(rw_AfterRSWipeCounter_mg))));
          break;
        case 21: /* for global object rw_AfterRSWipeCounterAlt_mg */
          VCAST_TI_9_22 ( ((unsigned *)(&(rw_AfterRSWipeCounterAlt_mg))));
          break;
        case 22: /* for global object rw_AfterWWSWipeCounter_mg */
          VCAST_TI_9_22 ( ((unsigned *)(&(rw_AfterWWSWipeCounter_mg))));
          break;
        case 23: /* for global object rw_WipeCommandTimOut_mg */
          VCAST_TI_9_22 ( ((unsigned *)(&(rw_WipeCommandTimOut_mg))));
          break;
        case 24: /* for global object rb_IgnitionOndelay_mg */
          VCAST_TI_9_6 ( ((unsigned char *)(&(rb_IgnitionOndelay_mg))));
          break;
        case 25: /* for global object rb_Err_State_Light_Sens_mg */
          VCAST_TI_9_6 ( ((unsigned char *)(&(rb_Err_State_Light_Sens_mg))));
          break;
        case 26: /* for global object rb_OutsideTemp_mg */
          VCAST_TI_8_2 ( ((int *)(&(rb_OutsideTemp_mg))));
          break;
        case 27: /* for global object rb_WipeWorkStatus_mg */
          VCAST_TI_9_6 ( ((unsigned char *)(&(rb_WipeWorkStatus_mg))));
          break;
        case 28: /* for global object HUDEverageValue */
          VCAST_TI_9_50 ( ((unsigned long *)(HUDEverageValue)));
          break;
        case 29: /* for global object rb_storeHUDValueEvery500ms */
          VCAST_TI_9_49 ( ((unsigned long *)(rb_storeHUDValueEvery500ms)));
          break;
        case 30: /* for global object rb_storeFW_ValueEvery50ms */
          VCAST_TI_9_49 ( ((unsigned long *)(rb_storeFW_ValueEvery50ms)));
          break;
        case 31: /* for global object rb_storeAMB_ValueEvery50ms */
          VCAST_TI_9_49 ( ((unsigned long *)(rb_storeAMB_ValueEvery50ms)));
          break;
        case 32: /* for global object FW_Average_In_50ms */
          VCAST_TI_9_39 ( ((unsigned long *)(&(FW_Average_In_50ms))));
          break;
        case 33: /* for global object AMB_Average_In_50ms */
          VCAST_TI_9_39 ( ((unsigned long *)(&(AMB_Average_In_50ms))));
          break;
        case 34: /* for global object FW_Average_In_50ms_Old */
          VCAST_TI_9_39 ( ((unsigned long *)(&(FW_Average_In_50ms_Old))));
          break;
        case 35: /* for global object AMB_Average_In_50ms_Old */
          VCAST_TI_9_39 ( ((unsigned long *)(&(AMB_Average_In_50ms_Old))));
          break;
        case 36: /* for global object RW_Amb_Fw_Result_End */
          VCAST_TI_9_39 ( ((unsigned long *)(&(RW_Amb_Fw_Result_End))));
          break;
        case 37: /* for global object rb_hud_data_update */
          VCAST_TI_9_6 ( ((unsigned char *)(&(rb_hud_data_update))));
          break;
        case 38: /* for global object RW_Update_Time_Count */
          VCAST_TI_9_6 ( ((unsigned char *)(&(RW_Update_Time_Count))));
          break;
        default:
          vCAST_TOOL_ERROR = vCAST_true;
          break;
      } /* switch( VCAST_PARAM_INDEX ) */
      break; /* case 0 (global objects) */
    case 35: /* function sci_init */
      switch ( VCAST_PARAM_INDEX ) {
        case 1:
          VCAST_TI_9_6 ( ((unsigned char *)(&(P_10_1_1))));
          break;
      } /* switch ( VCAST_PARAM_INDEX ) */
      break; /* function sci_init */
    case 37: /* function get_rb_LightVetoCounter_g */
      switch ( VCAST_PARAM_INDEX ) {
        case 1:
          VCAST_TI_9_6 ( ((unsigned char *)(&(R_10_3))));
          break;
      } /* switch ( VCAST_PARAM_INDEX ) */
      break; /* function get_rb_LightVetoCounter_g */
    case 38: /* function get_rw_Amb_light16bit_g */
      switch ( VCAST_PARAM_INDEX ) {
        case 1:
          VCAST_TI_9_22 ( ((unsigned *)(&(R_10_4))));
          break;
      } /* switch ( VCAST_PARAM_INDEX ) */
      break; /* function get_rw_Amb_light16bit_g */
    case 39: /* function get_rl_HUD_light32bit_g */
      switch ( VCAST_PARAM_INDEX ) {
        case 1:
          VCAST_TI_9_39 ( ((unsigned long *)(&(R_10_5))));
          break;
      } /* switch ( VCAST_PARAM_INDEX ) */
      break; /* function get_rl_HUD_light32bit_g */
    case 40: /* function get_rw_IR_light16bit_g */
      switch ( VCAST_PARAM_INDEX ) {
        case 1:
          VCAST_TI_9_22 ( ((unsigned *)(&(R_10_6))));
          break;
      } /* switch ( VCAST_PARAM_INDEX ) */
      break; /* function get_rw_IR_light16bit_g */
    case 41: /* function get_rb_LightSignalErrorCnt_g */
      switch ( VCAST_PARAM_INDEX ) {
        case 1:
          VCAST_TI_9_6 ( ((unsigned char *)(&(R_10_7))));
          break;
      } /* switch ( VCAST_PARAM_INDEX ) */
      break; /* function get_rb_LightSignalErrorCnt_g */
    case 42: /* function get_rb_VDD_LightSignalErrorCnt_g */
      switch ( VCAST_PARAM_INDEX ) {
        case 1:
          VCAST_TI_9_6 ( ((unsigned char *)(&(R_10_8))));
          break;
      } /* switch ( VCAST_PARAM_INDEX ) */
      break; /* function get_rb_VDD_LightSignalErrorCnt_g */
    case 43: /* function get_rb_LEDx_LStop_error_cnt_g */
      switch ( VCAST_PARAM_INDEX ) {
        case 1:
          VCAST_TI_9_6 ( ((unsigned char *)(&(R_10_9))));
          break;
      } /* switch ( VCAST_PARAM_INDEX ) */
      break; /* function get_rb_LEDx_LStop_error_cnt_g */
    case 16: /* function ApplLinInit */
      switch ( VCAST_PARAM_INDEX ) {
        case 1:
          VCAST_TI_9_6 ( ((unsigned char *)(&(P_9_16_1))));
          break;
      } /* switch ( VCAST_PARAM_INDEX ) */
      break; /* function ApplLinInit */
    case 17: /* function ApplLinSlavePreCopy */
      switch ( VCAST_PARAM_INDEX ) {
        case 1:
          VCAST_TI_9_6 ( ((unsigned char *)(&(P_9_17_1))));
          break;
      } /* switch ( VCAST_PARAM_INDEX ) */
      break; /* function ApplLinSlavePreCopy */
    case 18: /* function GetFiveTableValue_500ms */
      switch ( VCAST_PARAM_INDEX ) {
        case 1:
          VCAST_TI_9_39 ( ((unsigned long *)(&(P_9_18_1))));
          break;
      } /* switch ( VCAST_PARAM_INDEX ) */
      break; /* function GetFiveTableValue_500ms */
    case 19: /* function AdjustOutHudValue */
      switch ( VCAST_PARAM_INDEX ) {
        case 1:
          VCAST_TI_9_39 ( ((unsigned long *)(&(P_9_19_1))));
          break;
        case 2:
          VCAST_TI_9_39 ( ((unsigned long *)(&(R_9_19))));
          break;
      } /* switch ( VCAST_PARAM_INDEX ) */
      break; /* function AdjustOutHudValue */
    case 20: /* function GetUpdateTimeForLightStatus */
      switch ( VCAST_PARAM_INDEX ) {
        case 1:
          VCAST_TI_9_6 ( ((unsigned char *)(&(R_9_20))));
          break;
      } /* switch ( VCAST_PARAM_INDEX ) */
      break; /* function GetUpdateTimeForLightStatus */
    case 21: /* function CalcHUDMean_1000ms */
      switch ( VCAST_PARAM_INDEX ) {
        case 1:
          VCAST_TI_9_39 ( ((unsigned long *)(&(R_9_21))));
          break;
      } /* switch ( VCAST_PARAM_INDEX ) */
      break; /* function CalcHUDMean_1000ms */
    case 22: /* function orderHUDValue */
      switch ( VCAST_PARAM_INDEX ) {
        case 1:
          VCAST_TI_8_2 ( ((int *)(&(P_9_22_1))));
          break;
      } /* switch ( VCAST_PARAM_INDEX ) */
      break; /* function orderHUDValue */
    case 23: /* function GetFiveTableValue_50ms */
      switch ( VCAST_PARAM_INDEX ) {
        case 1:
          VCAST_TI_9_39 ( ((unsigned long *)(&(P_9_23_1))));
          break;
        case 2:
          VCAST_TI_9_39 ( ((unsigned long *)(&(P_9_23_2))));
          break;
      } /* switch ( VCAST_PARAM_INDEX ) */
      break; /* function GetFiveTableValue_50ms */
    case 24: /* function CRC8SAEJ1850 */
      switch ( VCAST_PARAM_INDEX ) {
        case 1:
          VCAST_TI_9_53 ( ((unsigned char **)(&(P_9_24_1))));
          break;
        case 2:
          VCAST_TI_9_6 ( ((unsigned char *)(&(P_9_24_2))));
          break;
        case 3:
          VCAST_TI_9_6 ( ((unsigned char *)(&(R_9_24))));
          break;
      } /* switch ( VCAST_PARAM_INDEX ) */
      break; /* function CRC8SAEJ1850 */
    case 25: /* function GetOutdBriStsCrcj1850 */
      switch ( VCAST_PARAM_INDEX ) {
        case 1:
          VCAST_TI_9_6 ( ((unsigned char *)(&(P_9_25_1))));
          break;
        case 2:
          VCAST_TI_9_6 ( ((unsigned char *)(&(R_9_25))));
          break;
      } /* switch ( VCAST_PARAM_INDEX ) */
      break; /* function GetOutdBriStsCrcj1850 */
    case 26: /* function GetHudCrcj1850 */
      switch ( VCAST_PARAM_INDEX ) {
        case 1:
          VCAST_TI_9_39 ( ((unsigned long *)(&(P_9_26_1))));
          break;
        case 2:
          VCAST_TI_9_6 ( ((unsigned char *)(&(R_9_26))));
          break;
      } /* switch ( VCAST_PARAM_INDEX ) */
      break; /* function GetHudCrcj1850 */
    case 27: /* function GetLightTransmission */
      switch ( VCAST_PARAM_INDEX ) {
        case 1:
          VCAST_TI_9_6 ( ((unsigned char *)(&(P_9_27_1))));
          break;
        case 2:
          VCAST_TI_9_6 ( ((unsigned char *)(&(P_9_27_2))));
          break;
      } /* switch ( VCAST_PARAM_INDEX ) */
      break; /* function GetLightTransmission */
    case 28: /* function Get_BCMVehType */
      switch ( VCAST_PARAM_INDEX ) {
        case 1:
          VCAST_TI_9_6 ( ((unsigned char *)(&(P_9_28_1))));
          break;
      } /* switch ( VCAST_PARAM_INDEX ) */
      break; /* function Get_BCMVehType */
    case 29: /* function Set_BCMLightOffset */
      switch ( VCAST_PARAM_INDEX ) {
        case 1:
          VCAST_TI_9_6 ( ((unsigned char *)(&(P_9_29_1))));
          break;
      } /* switch ( VCAST_PARAM_INDEX ) */
      break; /* function Set_BCMLightOffset */
    case 34: /* function IsByteOddParity */
      switch ( VCAST_PARAM_INDEX ) {
        case 1:
          VCAST_TI_9_6 ( ((unsigned char *)(&(P_9_34_1))));
          break;
        case 2:
          VCAST_TI_9_6 ( ((unsigned char *)(&(R_9_34))));
          break;
      } /* switch ( VCAST_PARAM_INDEX ) */
      break; /* function IsByteOddParity */
    default:
      vCAST_TOOL_ERROR = vCAST_true;
      break;
  } /* switch ( VCAST_SUB_INDEX ) */
}


/* A typedef */
#line 892 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\S0000009.c"
void VCAST_TI_9_26 ( s_rb_EEPROMStructPD_buff_g *vcast_param ) 
{




  {


    int VCAST_TI_9_67_jmpval;
    VCAST_TI_9_67_jmpval = setjmp ( VCAST_env );
    vcast_is_in_union = vCAST_false;
    if ( VCAST_TI_9_67_jmpval == 0 ) {
      vcast_is_in_union = vCAST_true;


      switch ( vcast_get_param () ) { /* Choose field member */
        /* Setting member variable vcast_param->_c */
        case 1: { 
          VCAST_TI_9_68 ( ((unsigned char *)(vcast_param->_c)));
          break; /* end case 1*/
        } /* end case */
        /* Setting member variable vcast_param->EEPROMStructPD */
        case 2: { 
          VCAST_TI_9_27 ( ((s_rb_EEPROMStruct_PD_g *)(&(vcast_param->EEPROMStructPD))));
          break; /* end case 2*/
        } /* end case */
        default:
          vCAST_TOOL_ERROR = vCAST_true;
      } /* end switch */ 


    } else if ( vCAST_COMMAND == vCAST_PRINT )
      vectorcast_fprint_string(vCAST_OUTPUT_FILE,"invalid address\n");


  }


} /* end VCAST_TI_9_26 */



/* An integer */
#line 943 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\S0000009.c"
void VCAST_TI_9_6 ( unsigned char *vcast_param ) 
{
  switch (vCAST_COMMAND) {
    case vCAST_PRINT :
      if ( vcast_param == 0)
        vectorcast_fprint_string (vCAST_OUTPUT_FILE,"null\n");
      else {
        vectorcast_fprint_integer(vCAST_OUTPUT_FILE, *vcast_param);
        vectorcast_fprint_string(vCAST_OUTPUT_FILE, "\n");
      }
      break;
    case vCAST_KEEP_VAL:
      break; /* KEEP doesn't do anything */
  case vCAST_SET_VAL :
    *vcast_param = ( unsigned char  ) vCAST_VALUE_INT;
    break;
  case vCAST_FIRST_VAL :
    *vcast_param = 0;
    break;
  case vCAST_MID_VAL :
    *vcast_param = (0 / 2) + (0xff / 2);
    break;
  case vCAST_LAST_VAL :
    *vcast_param = 0xff;
    break;
  case vCAST_MIN_MINUS_1_VAL :
    *vcast_param = 0;
    *vcast_param = *vcast_param - 1;
    break;
  case vCAST_MAX_PLUS_1_VAL :
    *vcast_param = 0xff;
    *vcast_param = *vcast_param + 1;
    break;
  case vCAST_ZERO_VAL :
    *vcast_param = 0;
    break;
  default:
    break;
} /* end switch */
} /* end VCAST_TI_9_6 */



/* An integer */
#line 994 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\S0000009.c"
void VCAST_TI_9_22 ( unsigned *vcast_param ) 
{
  switch (vCAST_COMMAND) {
    case vCAST_PRINT :
      if ( vcast_param == 0)
        vectorcast_fprint_string (vCAST_OUTPUT_FILE,"null\n");
      else {
        vectorcast_fprint_unsigned_integer(vCAST_OUTPUT_FILE, *vcast_param);
        vectorcast_fprint_string(vCAST_OUTPUT_FILE, "\n");
      }
      break;
    case vCAST_KEEP_VAL:
      break; /* KEEP doesn't do anything */
  case vCAST_SET_VAL :
    *vcast_param = ( unsigned  ) vCAST_VALUE_UNSIGNED;
    break;
  case vCAST_FIRST_VAL :
    *vcast_param = 0;
    break;
  case vCAST_MID_VAL :
    *vcast_param = (0 / 2) + (0xffffU / 2);
    break;
  case vCAST_LAST_VAL :
    *vcast_param = 0xffffU;
    break;
  case vCAST_MIN_MINUS_1_VAL :
    *vcast_param = 0;
    *vcast_param = *vcast_param - 1;
    break;
  case vCAST_MAX_PLUS_1_VAL :
    *vcast_param = 0xffffU;
    *vcast_param = *vcast_param + 1;
    break;
  case vCAST_ZERO_VAL :
    *vcast_param = 0;
    break;
  default:
    break;
} /* end switch */
} /* end VCAST_TI_9_22 */



/* A typedef */
#line 1045 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\S0000009.c"
void VCAST_TI_9_28 ( s_rb_EEPROMStructAD_buff_g *vcast_param ) 
{




  {


    int VCAST_TI_9_78_jmpval;
    VCAST_TI_9_78_jmpval = setjmp ( VCAST_env );
    vcast_is_in_union = vCAST_false;
    if ( VCAST_TI_9_78_jmpval == 0 ) {
      vcast_is_in_union = vCAST_true;


      switch ( vcast_get_param () ) { /* Choose field member */
        /* Setting member variable vcast_param->_c */
        case 1: { 
          VCAST_TI_9_79 ( ((unsigned char *)(vcast_param->_c)));
          break; /* end case 1*/
        } /* end case */
        /* Setting member variable vcast_param->EEPROMStructAD */
        case 2: { 
          VCAST_TI_9_29 ( ((s_rb_EEPROMStruct_AD_g *)(&(vcast_param->EEPROMStructAD))));
          break; /* end case 2*/
        } /* end case */
        default:
          vCAST_TOOL_ERROR = vCAST_true;
      } /* end switch */ 


    } else if ( vCAST_COMMAND == vCAST_PRINT )
      vectorcast_fprint_string(vCAST_OUTPUT_FILE,"invalid address\n");


  }


} /* end VCAST_TI_9_28 */



/* A union */
#line 1096 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\S0000009.c"
void VCAST_TI_9_7 ( union tLinIndicationBits *vcast_param ) 
{
  {


    int VCAST_TI_9_7_jmpval;
    VCAST_TI_9_7_jmpval = setjmp ( VCAST_env );
    vcast_is_in_union = vCAST_false;
    if ( VCAST_TI_9_7_jmpval == 0 ) {
      vcast_is_in_union = vCAST_true;


      switch ( vcast_get_param () ) { /* Choose field member */
        /* Setting member variable vcast_param->_c */
        case 1: { 
          VCAST_TI_9_80 ( ((unsigned char *)(vcast_param->_c)));
          break; /* end case 1*/
        } /* end case */
        /* Setting member variable vcast_param->w */
        case 2: { 
          VCAST_TI_9_8 ( ((struct _c_bits8 *)(vcast_param->w)));
          break; /* end case 2*/
        } /* end case */
        default:
          vCAST_TOOL_ERROR = vCAST_true;
      } /* end switch */ 


    } else if ( vCAST_COMMAND == vCAST_PRINT )
      vectorcast_fprint_string(vCAST_OUTPUT_FILE,"invalid address\n");


  }
} /* end VCAST_TI_9_7 */



/* A union */
#line 1141 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\S0000009.c"
void VCAST_TI_9_30 ( union tLinConfirmationBits *vcast_param ) 
{
  {


    int VCAST_TI_9_30_jmpval;
    VCAST_TI_9_30_jmpval = setjmp ( VCAST_env );
    vcast_is_in_union = vCAST_false;
    if ( VCAST_TI_9_30_jmpval == 0 ) {
      vcast_is_in_union = vCAST_true;


      switch ( vcast_get_param () ) { /* Choose field member */
        /* Setting member variable vcast_param->_c */
        case 1: { 
          VCAST_TI_9_81 ( ((unsigned char *)(vcast_param->_c)));
          break; /* end case 1*/
        } /* end case */
        /* Setting member variable vcast_param->w */
        case 2: { 
          VCAST_TI_9_31 ( ((struct _c_bits16 *)(vcast_param->w)));
          break; /* end case 2*/
        } /* end case */
        default:
          vCAST_TOOL_ERROR = vCAST_true;
      } /* end switch */ 


    } else if ( vCAST_COMMAND == vCAST_PRINT )
      vectorcast_fprint_string(vCAST_OUTPUT_FILE,"invalid address\n");


  }
} /* end VCAST_TI_9_30 */



/* A typedef */
#line 1186 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\S0000009.c"
void VCAST_TI_9_4 ( volatile Flag *vcast_param ) 
{




  {


    int VCAST_TI_9_61_jmpval;
    VCAST_TI_9_61_jmpval = setjmp ( VCAST_env );
    vcast_is_in_union = vCAST_false;
    if ( VCAST_TI_9_61_jmpval == 0 ) {
      vcast_is_in_union = vCAST_true;


      switch ( vcast_get_param () ) { /* Choose field member */
        /* Setting member variable vcast_param->Bit */
        case 1: { 
          VCAST_TI_9_5 ( ((Bit_Feld *)(&(vcast_param->Bit))));
          break; /* end case 1*/
        } /* end case */
        /* Setting member variable vcast_param->AllBit */
        case 2: { 
          VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->AllBit))));
          break; /* end case 2*/
        } /* end case */
        default:
          vCAST_TOOL_ERROR = vCAST_true;
      } /* end switch */ 


    } else if ( vCAST_COMMAND == vCAST_PRINT )
      vectorcast_fprint_string(vCAST_OUTPUT_FILE,"invalid address\n");


  }


} /* end VCAST_TI_9_4 */



/* A typedef */
#line 1237 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\S0000009.c"
void VCAST_TI_9_23 ( Flag *vcast_param ) 
{




  {


    int VCAST_TI_9_61_jmpval;
    VCAST_TI_9_61_jmpval = setjmp ( VCAST_env );
    vcast_is_in_union = vCAST_false;
    if ( VCAST_TI_9_61_jmpval == 0 ) {
      vcast_is_in_union = vCAST_true;


      switch ( vcast_get_param () ) { /* Choose field member */
        /* Setting member variable vcast_param->Bit */
        case 1: { 
          VCAST_TI_9_5 ( ((Bit_Feld *)(&(vcast_param->Bit))));
          break; /* end case 1*/
        } /* end case */
        /* Setting member variable vcast_param->AllBit */
        case 2: { 
          VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->AllBit))));
          break; /* end case 2*/
        } /* end case */
        default:
          vCAST_TOOL_ERROR = vCAST_true;
      } /* end switch */ 


    } else if ( vCAST_COMMAND == vCAST_PRINT )
      vectorcast_fprint_string(vCAST_OUTPUT_FILE,"invalid address\n");


  }


} /* end VCAST_TI_9_23 */



/* A typedef */
#line 1288 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\S0000009.c"
void VCAST_TI_9_40 ( _c_RlsmCem_SerNrLin1Fr01_CEM_LIN1_buf *vcast_param ) 
{




  {


    int VCAST_TI_9_94_jmpval;
    VCAST_TI_9_94_jmpval = setjmp ( VCAST_env );
    vcast_is_in_union = vCAST_false;
    if ( VCAST_TI_9_94_jmpval == 0 ) {
      vcast_is_in_union = vCAST_true;


      switch ( vcast_get_param () ) { /* Choose field member */
        /* Setting member variable vcast_param->_c */
        case 1: { 
          VCAST_TI_9_41 ( ((unsigned char *)(vcast_param->_c)));
          break; /* end case 1*/
        } /* end case */
        /* Setting member variable vcast_param->rlsmcem_sernrlin1fr01_cem_lin1 */
        case 2: { 
          VCAST_TI_9_55 ( ((_c_RlsmCem_SerNrLin1Fr01_CEM_LIN1_msgType *)(&(vcast_param->rlsmcem_sernrlin1fr01_cem_lin1))));
          break; /* end case 2*/
        } /* end case */
        default:
          vCAST_TOOL_ERROR = vCAST_true;
      } /* end switch */ 


    } else if ( vCAST_COMMAND == vCAST_PRINT )
      vectorcast_fprint_string(vCAST_OUTPUT_FILE,"invalid address\n");


  }


} /* end VCAST_TI_9_40 */



/* A typedef */
#line 1339 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\S0000009.c"
void VCAST_TI_9_42 ( _c_RlsmCem_Lin1PartNrFr02_CEM_LIN1_buf *vcast_param ) 
{




  {


    int VCAST_TI_9_95_jmpval;
    VCAST_TI_9_95_jmpval = setjmp ( VCAST_env );
    vcast_is_in_union = vCAST_false;
    if ( VCAST_TI_9_95_jmpval == 0 ) {
      vcast_is_in_union = vCAST_true;


      switch ( vcast_get_param () ) { /* Choose field member */
        /* Setting member variable vcast_param->_c */
        case 1: { 
          VCAST_TI_9_43 ( ((unsigned char *)(vcast_param->_c)));
          break; /* end case 1*/
        } /* end case */
        /* Setting member variable vcast_param->rlsmcem_lin1partnrfr02_cem_lin1 */
        case 2: { 
          VCAST_TI_9_59 ( ((_c_RlsmCem_Lin1PartNrFr02_CEM_LIN1_msgType *)(&(vcast_param->rlsmcem_lin1partnrfr02_cem_lin1))));
          break; /* end case 2*/
        } /* end case */
        default:
          vCAST_TOOL_ERROR = vCAST_true;
      } /* end switch */ 


    } else if ( vCAST_COMMAND == vCAST_PRINT )
      vectorcast_fprint_string(vCAST_OUTPUT_FILE,"invalid address\n");


  }


} /* end VCAST_TI_9_42 */



/* A typedef */
#line 1390 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\S0000009.c"
void VCAST_TI_9_44 ( _c_RlsmCem_Lin1PartNrFr01_CEM_LIN1_buf *vcast_param ) 
{




  {


    int VCAST_TI_9_96_jmpval;
    VCAST_TI_9_96_jmpval = setjmp ( VCAST_env );
    vcast_is_in_union = vCAST_false;
    if ( VCAST_TI_9_96_jmpval == 0 ) {
      vcast_is_in_union = vCAST_true;


      switch ( vcast_get_param () ) { /* Choose field member */
        /* Setting member variable vcast_param->_c */
        case 1: { 
          VCAST_TI_9_45 ( ((unsigned char *)(vcast_param->_c)));
          break; /* end case 1*/
        } /* end case */
        /* Setting member variable vcast_param->rlsmcem_lin1partnrfr01_cem_lin1 */
        case 2: { 
          VCAST_TI_9_57 ( ((_c_RlsmCem_Lin1PartNrFr01_CEM_LIN1_msgType *)(&(vcast_param->rlsmcem_lin1partnrfr01_cem_lin1))));
          break; /* end case 2*/
        } /* end case */
        default:
          vCAST_TOOL_ERROR = vCAST_true;
      } /* end switch */ 


    } else if ( vCAST_COMMAND == vCAST_PRINT )
      vectorcast_fprint_string(vCAST_OUTPUT_FILE,"invalid address\n");


  }


} /* end VCAST_TI_9_44 */



/* A typedef */
#line 1441 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\S0000009.c"
void VCAST_TI_9_33 ( _c_RlsmCem_Lin1Fr03_CEM_LIN1_buf *vcast_param ) 
{




  {


    int VCAST_TI_9_97_jmpval;
    VCAST_TI_9_97_jmpval = setjmp ( VCAST_env );
    vcast_is_in_union = vCAST_false;
    if ( VCAST_TI_9_97_jmpval == 0 ) {
      vcast_is_in_union = vCAST_true;


      switch ( vcast_get_param () ) { /* Choose field member */
        /* Setting member variable vcast_param->_c */
        case 1: { 
          VCAST_TI_9_43 ( ((unsigned char *)(vcast_param->_c)));
          break; /* end case 1*/
        } /* end case */
        /* Setting member variable vcast_param->rlsmcem_lin1fr03_cem_lin1 */
        case 2: { 
          VCAST_TI_9_34 ( ((_c_RlsmCem_Lin1Fr03_CEM_LIN1_msgType *)(&(vcast_param->rlsmcem_lin1fr03_cem_lin1))));
          break; /* end case 2*/
        } /* end case */
        default:
          vCAST_TOOL_ERROR = vCAST_true;
      } /* end switch */ 


    } else if ( vCAST_COMMAND == vCAST_PRINT )
      vectorcast_fprint_string(vCAST_OUTPUT_FILE,"invalid address\n");


  }


} /* end VCAST_TI_9_33 */



/* A typedef */
#line 1492 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\S0000009.c"
void VCAST_TI_9_35 ( _c_RlsmCem_Lin1Fr02_CEM_LIN1_buf *vcast_param ) 
{




  {


    int VCAST_TI_9_98_jmpval;
    VCAST_TI_9_98_jmpval = setjmp ( VCAST_env );
    vcast_is_in_union = vCAST_false;
    if ( VCAST_TI_9_98_jmpval == 0 ) {
      vcast_is_in_union = vCAST_true;


      switch ( vcast_get_param () ) { /* Choose field member */
        /* Setting member variable vcast_param->_c */
        case 1: { 
          VCAST_TI_9_43 ( ((unsigned char *)(vcast_param->_c)));
          break; /* end case 1*/
        } /* end case */
        /* Setting member variable vcast_param->rlsmcem_lin1fr02_cem_lin1 */
        case 2: { 
          VCAST_TI_9_36 ( ((_c_RlsmCem_Lin1Fr02_CEM_LIN1_msgType *)(&(vcast_param->rlsmcem_lin1fr02_cem_lin1))));
          break; /* end case 2*/
        } /* end case */
        default:
          vCAST_TOOL_ERROR = vCAST_true;
      } /* end switch */ 


    } else if ( vCAST_COMMAND == vCAST_PRINT )
      vectorcast_fprint_string(vCAST_OUTPUT_FILE,"invalid address\n");


  }


} /* end VCAST_TI_9_35 */



/* A typedef */
#line 1543 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\S0000009.c"
void VCAST_TI_9_12 ( _c_RlsmCem_Lin1Fr01_CEM_LIN1_buf *vcast_param ) 
{




  {


    int VCAST_TI_9_99_jmpval;
    VCAST_TI_9_99_jmpval = setjmp ( VCAST_env );
    vcast_is_in_union = vCAST_false;
    if ( VCAST_TI_9_99_jmpval == 0 ) {
      vcast_is_in_union = vCAST_true;


      switch ( vcast_get_param () ) { /* Choose field member */
        /* Setting member variable vcast_param->_c */
        case 1: { 
          VCAST_TI_9_43 ( ((unsigned char *)(vcast_param->_c)));
          break; /* end case 1*/
        } /* end case */
        /* Setting member variable vcast_param->rlsmcem_lin1fr01_cem_lin1 */
        case 2: { 
          VCAST_TI_9_13 ( ((_c_RlsmCem_Lin1Fr01_CEM_LIN1_msgType *)(&(vcast_param->rlsmcem_lin1fr01_cem_lin1))));
          break; /* end case 2*/
        } /* end case */
        default:
          vCAST_TOOL_ERROR = vCAST_true;
      } /* end switch */ 


    } else if ( vCAST_COMMAND == vCAST_PRINT )
      vectorcast_fprint_string(vCAST_OUTPUT_FILE,"invalid address\n");


  }


} /* end VCAST_TI_9_12 */



/* A typedef */
#line 1594 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\S0000009.c"
void VCAST_TI_9_18 ( _c_CemCem_Lin1Fr06_CEM_LIN1_buf *vcast_param ) 
{




  {


    int VCAST_TI_9_100_jmpval;
    VCAST_TI_9_100_jmpval = setjmp ( VCAST_env );
    vcast_is_in_union = vCAST_false;
    if ( VCAST_TI_9_100_jmpval == 0 ) {
      vcast_is_in_union = vCAST_true;


      switch ( vcast_get_param () ) { /* Choose field member */
        /* Setting member variable vcast_param->_c */
        case 1: { 
          VCAST_TI_9_80 ( ((unsigned char *)(vcast_param->_c)));
          break; /* end case 1*/
        } /* end case */
        /* Setting member variable vcast_param->cemcem_lin1fr06_cem_lin1 */
        case 2: { 
          VCAST_TI_9_19 ( ((_c_CemCem_Lin1Fr06_CEM_LIN1_msgType *)(&(vcast_param->cemcem_lin1fr06_cem_lin1))));
          break; /* end case 2*/
        } /* end case */
        default:
          vCAST_TOOL_ERROR = vCAST_true;
      } /* end switch */ 


    } else if ( vCAST_COMMAND == vCAST_PRINT )
      vectorcast_fprint_string(vCAST_OUTPUT_FILE,"invalid address\n");


  }


} /* end VCAST_TI_9_18 */



/* A typedef */
#line 1645 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\S0000009.c"
void VCAST_TI_9_1 ( _c_CemCem_Lin1Fr05_CEM_LIN1_buf *vcast_param ) 
{




  {


    int VCAST_TI_9_102_jmpval;
    VCAST_TI_9_102_jmpval = setjmp ( VCAST_env );
    vcast_is_in_union = vCAST_false;
    if ( VCAST_TI_9_102_jmpval == 0 ) {
      vcast_is_in_union = vCAST_true;


      switch ( vcast_get_param () ) { /* Choose field member */
        /* Setting member variable vcast_param->_c */
        case 1: { 
          VCAST_TI_9_45 ( ((unsigned char *)(vcast_param->_c)));
          break; /* end case 1*/
        } /* end case */
        /* Setting member variable vcast_param->cemcem_lin1fr05_cem_lin1 */
        case 2: { 
          VCAST_TI_9_2 ( ((_c_CemCem_Lin1Fr05_CEM_LIN1_msgType *)(&(vcast_param->cemcem_lin1fr05_cem_lin1))));
          break; /* end case 2*/
        } /* end case */
        default:
          vCAST_TOOL_ERROR = vCAST_true;
      } /* end switch */ 


    } else if ( vCAST_COMMAND == vCAST_PRINT )
      vectorcast_fprint_string(vCAST_OUTPUT_FILE,"invalid address\n");


  }


} /* end VCAST_TI_9_1 */



/* A typedef */
#line 1696 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\S0000009.c"
void VCAST_TI_9_16 ( _c_CemCem_Lin1Fr04_CEM_LIN1_buf *vcast_param ) 
{




  {


    int VCAST_TI_9_104_jmpval;
    VCAST_TI_9_104_jmpval = setjmp ( VCAST_env );
    vcast_is_in_union = vCAST_false;
    if ( VCAST_TI_9_104_jmpval == 0 ) {
      vcast_is_in_union = vCAST_true;


      switch ( vcast_get_param () ) { /* Choose field member */
        /* Setting member variable vcast_param->_c */
        case 1: { 
          VCAST_TI_9_45 ( ((unsigned char *)(vcast_param->_c)));
          break; /* end case 1*/
        } /* end case */
        /* Setting member variable vcast_param->cemcem_lin1fr04_cem_lin1 */
        case 2: { 
          VCAST_TI_9_17 ( ((_c_CemCem_Lin1Fr04_CEM_LIN1_msgType *)(&(vcast_param->cemcem_lin1fr04_cem_lin1))));
          break; /* end case 2*/
        } /* end case */
        default:
          vCAST_TOOL_ERROR = vCAST_true;
      } /* end switch */ 


    } else if ( vCAST_COMMAND == vCAST_PRINT )
      vectorcast_fprint_string(vCAST_OUTPUT_FILE,"invalid address\n");


  }


} /* end VCAST_TI_9_16 */



/* A typedef */
#line 1747 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\S0000009.c"
void VCAST_TI_9_14 ( _c_CemCem_Lin1Fr03_CEM_LIN1_buf *vcast_param ) 
{




  {


    int VCAST_TI_9_106_jmpval;
    VCAST_TI_9_106_jmpval = setjmp ( VCAST_env );
    vcast_is_in_union = vCAST_false;
    if ( VCAST_TI_9_106_jmpval == 0 ) {
      vcast_is_in_union = vCAST_true;


      switch ( vcast_get_param () ) { /* Choose field member */
        /* Setting member variable vcast_param->_c */
        case 1: { 
          VCAST_TI_9_43 ( ((unsigned char *)(vcast_param->_c)));
          break; /* end case 1*/
        } /* end case */
        /* Setting member variable vcast_param->cemcem_lin1fr03_cem_lin1 */
        case 2: { 
          VCAST_TI_9_15 ( ((_c_CemCem_Lin1Fr03_CEM_LIN1_msgType *)(&(vcast_param->cemcem_lin1fr03_cem_lin1))));
          break; /* end case 2*/
        } /* end case */
        default:
          vCAST_TOOL_ERROR = vCAST_true;
      } /* end switch */ 


    } else if ( vCAST_COMMAND == vCAST_PRINT )
      vectorcast_fprint_string(vCAST_OUTPUT_FILE,"invalid address\n");


  }


} /* end VCAST_TI_9_14 */



/* A typedef */
#line 1798 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\S0000009.c"
void VCAST_TI_9_10 ( _c_CemCem_Lin1Fr02_CEM_LIN1_buf *vcast_param ) 
{




  {


    int VCAST_TI_9_108_jmpval;
    VCAST_TI_9_108_jmpval = setjmp ( VCAST_env );
    vcast_is_in_union = vCAST_false;
    if ( VCAST_TI_9_108_jmpval == 0 ) {
      vcast_is_in_union = vCAST_true;


      switch ( vcast_get_param () ) { /* Choose field member */
        /* Setting member variable vcast_param->_c */
        case 1: { 
          VCAST_TI_9_45 ( ((unsigned char *)(vcast_param->_c)));
          break; /* end case 1*/
        } /* end case */
        /* Setting member variable vcast_param->cemcem_lin1fr02_cem_lin1 */
        case 2: { 
          VCAST_TI_9_11 ( ((_c_CemCem_Lin1Fr02_CEM_LIN1_msgType *)(&(vcast_param->cemcem_lin1fr02_cem_lin1))));
          break; /* end case 2*/
        } /* end case */
        default:
          vCAST_TOOL_ERROR = vCAST_true;
      } /* end switch */ 


    } else if ( vCAST_COMMAND == vCAST_PRINT )
      vectorcast_fprint_string(vCAST_OUTPUT_FILE,"invalid address\n");


  }


} /* end VCAST_TI_9_10 */



/* A typedef */
#line 1849 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\S0000009.c"
void VCAST_TI_9_24 ( _c_CemCem_Lin1Fr01_CEM_LIN1_buf *vcast_param ) 
{




  {


    int VCAST_TI_9_110_jmpval;
    VCAST_TI_9_110_jmpval = setjmp ( VCAST_env );
    vcast_is_in_union = vCAST_false;
    if ( VCAST_TI_9_110_jmpval == 0 ) {
      vcast_is_in_union = vCAST_true;


      switch ( vcast_get_param () ) { /* Choose field member */
        /* Setting member variable vcast_param->_c */
        case 1: { 
          VCAST_TI_9_111 ( ((unsigned char *)(vcast_param->_c)));
          break; /* end case 1*/
        } /* end case */
        /* Setting member variable vcast_param->cemcem_lin1fr01_cem_lin1 */
        case 2: { 
          VCAST_TI_9_25 ( ((_c_CemCem_Lin1Fr01_CEM_LIN1_msgType *)(&(vcast_param->cemcem_lin1fr01_cem_lin1))));
          break; /* end case 2*/
        } /* end case */
        default:
          vCAST_TOOL_ERROR = vCAST_true;
      } /* end switch */ 


    } else if ( vCAST_COMMAND == vCAST_PRINT )
      vectorcast_fprint_string(vCAST_OUTPUT_FILE,"invalid address\n");


  }


} /* end VCAST_TI_9_24 */



/* A typedef */
#line 1900 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\S0000009.c"
void VCAST_TI_9_20 ( volatile RS_Flag *vcast_param ) 
{




  {


    int VCAST_TI_9_113_jmpval;
    VCAST_TI_9_113_jmpval = setjmp ( VCAST_env );
    vcast_is_in_union = vCAST_false;
    if ( VCAST_TI_9_113_jmpval == 0 ) {
      vcast_is_in_union = vCAST_true;


      switch ( vcast_get_param () ) { /* Choose field member */
        /* Setting member variable vcast_param->Bit */
        case 1: { 
          VCAST_TI_9_21 ( ((RS_Bit_Feld *)(&(vcast_param->Bit))));
          break; /* end case 1*/
        } /* end case */
        /* Setting member variable vcast_param->AllBit */
        case 2: { 
          VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->AllBit))));
          break; /* end case 2*/
        } /* end case */
        default:
          vCAST_TOOL_ERROR = vCAST_true;
      } /* end switch */ 


    } else if ( vCAST_COMMAND == vCAST_PRINT )
      vectorcast_fprint_string(vCAST_OUTPUT_FILE,"invalid address\n");


  }


} /* end VCAST_TI_9_20 */



/* An array */
#line 1951 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\S0000009.c"
void VCAST_TI_9_54 ( unsigned char vcast_param[5] ) 
{
  {
    int VCAST_TI_9_54_array_index = 0;
    int VCAST_TI_9_54_index = 0;
    int VCAST_TI_9_54_first, VCAST_TI_9_54_last;
    int VCAST_TI_9_54_more_data; /* true if there is more data in the current command */
    int VCAST_TI_9_54_local_field = 0;
    int VCAST_TI_9_54_value_printed = 0;
    int VCAST_TI_9_54_is_string = (VCAST_FIND_INDEX()==-1);


    vcast_get_range_value (&VCAST_TI_9_54_first, &VCAST_TI_9_54_last, &VCAST_TI_9_54_more_data);
    VCAST_TI_9_54_local_field = vCAST_DATA_FIELD;
    if ( vCAST_SIZE && (!VCAST_TI_9_54_more_data)) { /* get the size of the array */
      vectorcast_fprint_integer (vCAST_OUTPUT_FILE,5);
      vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
      vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n");
    } else {
      int VCAST_TI_9_54_upper = 5;
      for (VCAST_TI_9_54_array_index=0; VCAST_TI_9_54_array_index< VCAST_TI_9_54_upper; VCAST_TI_9_54_array_index++){
        if ( (VCAST_TI_9_54_index >= VCAST_TI_9_54_first) && ( VCAST_TI_9_54_index <= VCAST_TI_9_54_last)){
          if ( VCAST_TI_9_54_is_string )
            VCAST_TI_STRING ( (char**)&vcast_param, sizeof ( vcast_param ), 1,VCAST_TI_9_54_upper);
          else
            VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param[VCAST_TI_9_54_index]))));
          VCAST_TI_9_54_value_printed = 1;
          vCAST_DATA_FIELD = VCAST_TI_9_54_local_field;
        } /* if */
        if (VCAST_TI_9_54_index >= VCAST_TI_9_54_last)
          break;
        VCAST_TI_9_54_index++;
      } /* loop */
      if ((vCAST_COMMAND == vCAST_PRINT)&&(!VCAST_TI_9_54_value_printed))
        vectorcast_fprint_string(vCAST_OUTPUT_FILE,"<<past end of array>>\n");
    } /* if */
  }
} /* end VCAST_TI_9_54 */



/* An array */
#line 2000 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\S0000009.c"
void VCAST_TI_9_37 ( ASIC_ALI_Meas_t vcast_param[9] ) 
{
  {
    int VCAST_TI_9_37_array_index = 0;
    int VCAST_TI_9_37_index = 0;
    int VCAST_TI_9_37_first, VCAST_TI_9_37_last;
    int VCAST_TI_9_37_more_data; /* true if there is more data in the current command */
    int VCAST_TI_9_37_local_field = 0;
    int VCAST_TI_9_37_value_printed = 0;


    vcast_get_range_value (&VCAST_TI_9_37_first, &VCAST_TI_9_37_last, &VCAST_TI_9_37_more_data);
    VCAST_TI_9_37_local_field = vCAST_DATA_FIELD;
    if ( vCAST_SIZE && (!VCAST_TI_9_37_more_data)) { /* get the size of the array */
      vectorcast_fprint_integer (vCAST_OUTPUT_FILE,9);
      vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
      vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n");
    } else {
      int VCAST_TI_9_37_upper = 9;
      for (VCAST_TI_9_37_array_index=0; VCAST_TI_9_37_array_index< VCAST_TI_9_37_upper; VCAST_TI_9_37_array_index++){
        if ( (VCAST_TI_9_37_index >= VCAST_TI_9_37_first) && ( VCAST_TI_9_37_index <= VCAST_TI_9_37_last)){
          VCAST_TI_9_38 ( ((ASIC_ALI_Meas_t *)(&(vcast_param[VCAST_TI_9_37_index]))));
          VCAST_TI_9_37_value_printed = 1;
          vCAST_DATA_FIELD = VCAST_TI_9_37_local_field;
        } /* if */
        if (VCAST_TI_9_37_index >= VCAST_TI_9_37_last)
          break;
        VCAST_TI_9_37_index++;
      } /* loop */
      if ((vCAST_COMMAND == vCAST_PRINT)&&(!VCAST_TI_9_37_value_printed))
        vectorcast_fprint_string(vCAST_OUTPUT_FILE,"<<past end of array>>\n");
    } /* if */
  }
} /* end VCAST_TI_9_37 */



/* An array */
#line 2045 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\S0000009.c"
void VCAST_TI_9_50 ( unsigned long vcast_param[2] ) 
{
  {
    int VCAST_TI_9_50_array_index = 0;
    int VCAST_TI_9_50_index = 0;
    int VCAST_TI_9_50_first, VCAST_TI_9_50_last;
    int VCAST_TI_9_50_more_data; /* true if there is more data in the current command */
    int VCAST_TI_9_50_local_field = 0;
    int VCAST_TI_9_50_value_printed = 0;


    vcast_get_range_value (&VCAST_TI_9_50_first, &VCAST_TI_9_50_last, &VCAST_TI_9_50_more_data);
    VCAST_TI_9_50_local_field = vCAST_DATA_FIELD;
    if ( vCAST_SIZE && (!VCAST_TI_9_50_more_data)) { /* get the size of the array */
      vectorcast_fprint_integer (vCAST_OUTPUT_FILE,2);
      vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
      vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n");
    } else {
      int VCAST_TI_9_50_upper = 2;
      for (VCAST_TI_9_50_array_index=0; VCAST_TI_9_50_array_index< VCAST_TI_9_50_upper; VCAST_TI_9_50_array_index++){
        if ( (VCAST_TI_9_50_index >= VCAST_TI_9_50_first) && ( VCAST_TI_9_50_index <= VCAST_TI_9_50_last)){
          VCAST_TI_9_39 ( ((unsigned long *)(&(vcast_param[VCAST_TI_9_50_index]))));
          VCAST_TI_9_50_value_printed = 1;
          vCAST_DATA_FIELD = VCAST_TI_9_50_local_field;
        } /* if */
        if (VCAST_TI_9_50_index >= VCAST_TI_9_50_last)
          break;
        VCAST_TI_9_50_index++;
      } /* loop */
      if ((vCAST_COMMAND == vCAST_PRINT)&&(!VCAST_TI_9_50_value_printed))
        vectorcast_fprint_string(vCAST_OUTPUT_FILE,"<<past end of array>>\n");
    } /* if */
  }
} /* end VCAST_TI_9_50 */



/* An array */
#line 2090 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\S0000009.c"
void VCAST_TI_9_49 ( unsigned long vcast_param[10] ) 
{
  {
    int VCAST_TI_9_49_array_index = 0;
    int VCAST_TI_9_49_index = 0;
    int VCAST_TI_9_49_first, VCAST_TI_9_49_last;
    int VCAST_TI_9_49_more_data; /* true if there is more data in the current command */
    int VCAST_TI_9_49_local_field = 0;
    int VCAST_TI_9_49_value_printed = 0;


    vcast_get_range_value (&VCAST_TI_9_49_first, &VCAST_TI_9_49_last, &VCAST_TI_9_49_more_data);
    VCAST_TI_9_49_local_field = vCAST_DATA_FIELD;
    if ( vCAST_SIZE && (!VCAST_TI_9_49_more_data)) { /* get the size of the array */
      vectorcast_fprint_integer (vCAST_OUTPUT_FILE,10);
      vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
      vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n");
    } else {
      int VCAST_TI_9_49_upper = 10;
      for (VCAST_TI_9_49_array_index=0; VCAST_TI_9_49_array_index< VCAST_TI_9_49_upper; VCAST_TI_9_49_array_index++){
        if ( (VCAST_TI_9_49_index >= VCAST_TI_9_49_first) && ( VCAST_TI_9_49_index <= VCAST_TI_9_49_last)){
          VCAST_TI_9_39 ( ((unsigned long *)(&(vcast_param[VCAST_TI_9_49_index]))));
          VCAST_TI_9_49_value_printed = 1;
          vCAST_DATA_FIELD = VCAST_TI_9_49_local_field;
        } /* if */
        if (VCAST_TI_9_49_index >= VCAST_TI_9_49_last)
          break;
        VCAST_TI_9_49_index++;
      } /* loop */
      if ((vCAST_COMMAND == vCAST_PRINT)&&(!VCAST_TI_9_49_value_printed))
        vectorcast_fprint_string(vCAST_OUTPUT_FILE,"<<past end of array>>\n");
    } /* if */
  }
} /* end VCAST_TI_9_49 */



/* An integer */
#line 2135 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\S0000009.c"
void VCAST_TI_9_39 ( unsigned long *vcast_param ) 
{
  switch (vCAST_COMMAND) {
    case vCAST_PRINT :
      if ( vcast_param == 0)
        vectorcast_fprint_string (vCAST_OUTPUT_FILE,"null\n");
      else {
        vectorcast_fprint_unsigned_long(vCAST_OUTPUT_FILE, *vcast_param);
        vectorcast_fprint_string(vCAST_OUTPUT_FILE, "\n");
      }
      break;
    case vCAST_KEEP_VAL:
      break; /* KEEP doesn't do anything */
  case vCAST_SET_VAL :
    *vcast_param = ( unsigned long  ) vCAST_VALUE_UNSIGNED;
    break;
  case vCAST_FIRST_VAL :
    *vcast_param = 0;
    break;
  case vCAST_MID_VAL :
    *vcast_param = (0 / 2) + (0xffffffffUL / 2);
    break;
  case vCAST_LAST_VAL :
    *vcast_param = 0xffffffffUL;
    break;
  case vCAST_MIN_MINUS_1_VAL :
    *vcast_param = 0;
    *vcast_param = *vcast_param - 1;
    break;
  case vCAST_MAX_PLUS_1_VAL :
    *vcast_param = 0xffffffffUL;
    *vcast_param = *vcast_param + 1;
    break;
  case vCAST_ZERO_VAL :
    *vcast_param = 0;
    break;
  default:
    break;
} /* end switch */
} /* end VCAST_TI_9_39 */



/* A pointer */
#line 2186 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\S0000009.c"
void VCAST_TI_9_53 ( unsigned char **vcast_param ) 
{
  {
    int VCAST_TI_9_53_index;
    if (((*vcast_param) == 0) && (vCAST_COMMAND != vCAST_ALLOCATE)){
      if ( vCAST_COMMAND == vCAST_PRINT )
        vectorcast_fprint_string(vCAST_OUTPUT_FILE,"null\n");
    } else {
      if ( (vCAST_COMMAND_IS_MIN_MAX == vCAST_true) &&( VCAST_FIND_INDEX() < 0 ) ) {
        switch ( vCAST_COMMAND ) {
          case vCAST_PRINT     :
            vectorcast_fprint_string(vCAST_OUTPUT_FILE,"0\n");
          case vCAST_FIRST_VAL :
          case vCAST_LAST_VAL  :
          case vCAST_POS_INF_VAL  :
          case vCAST_NEG_INF_VAL  :
          case vCAST_NAN_VAL  :
            break;
          default :
            vCAST_TOOL_ERROR = vCAST_true;
        }
      } else {
        if (vCAST_COMMAND == vCAST_ALLOCATE && vcast_proc_handles_command(1)) {
          int VCAST_TI_9_53_array_size = (int) vCAST_VALUE;
          if (VCAST_FIND_INDEX() == -1) {
            void **VCAST_TI_9_53_memory_ptr = (void**)vcast_param;
            *VCAST_TI_9_53_memory_ptr = (void*)VCAST_malloc(VCAST_TI_9_53_array_size*(sizeof(unsigned char )));
            memset((void*)*vcast_param, 0x0, VCAST_TI_9_53_array_size*(sizeof(unsigned char )));

            VCAST_Add_Allocated_Data(*VCAST_TI_9_53_memory_ptr);

          }
        } else if (vCAST_VALUE_NUL == vCAST_true && vcast_proc_handles_command(1)) {
          if (VCAST_FIND_INDEX() == -1)
            *vcast_param = 0;
        } else {
          if (VCAST_FIND_INDEX() == -1 )
            VCAST_TI_STRING ( (char**)vcast_param, sizeof ( vcast_param ), 0,-1);
          else {
            VCAST_TI_9_53_index = vcast_get_param();
            VCAST_TI_9_6 ( ((unsigned char *)(&((*vcast_param)[VCAST_TI_9_53_index]))));
          }
        }
      }
    }
  }
} /* end VCAST_TI_9_53 */



/* An array */
#line 2244 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\S0000009.c"
void VCAST_TI_9_68 ( unsigned char vcast_param[(93 + 4) + 10] ) 
{
  {
    int VCAST_TI_9_68_array_index = 0;
    int VCAST_TI_9_68_index = 0;
    int VCAST_TI_9_68_first, VCAST_TI_9_68_last;
    int VCAST_TI_9_68_more_data; /* true if there is more data in the current command */
    int VCAST_TI_9_68_local_field = 0;
    int VCAST_TI_9_68_value_printed = 0;
    int VCAST_TI_9_68_is_string = (VCAST_FIND_INDEX()==-1);


    vcast_get_range_value (&VCAST_TI_9_68_first, &VCAST_TI_9_68_last, &VCAST_TI_9_68_more_data);
    VCAST_TI_9_68_local_field = vCAST_DATA_FIELD;
    if ( vCAST_SIZE && (!VCAST_TI_9_68_more_data)) { /* get the size of the array */
      vectorcast_fprint_integer (vCAST_OUTPUT_FILE,(93 + 4) + 10);
      vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
      vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n");
    } else {
      int VCAST_TI_9_68_upper = (93 + 4) + 10;
      for (VCAST_TI_9_68_array_index=0; VCAST_TI_9_68_array_index< VCAST_TI_9_68_upper; VCAST_TI_9_68_array_index++){
        if ( (VCAST_TI_9_68_index >= VCAST_TI_9_68_first) && ( VCAST_TI_9_68_index <= VCAST_TI_9_68_last)){
          if ( VCAST_TI_9_68_is_string )
            VCAST_TI_STRING ( (char**)&vcast_param, sizeof ( vcast_param ), 1,VCAST_TI_9_68_upper);
          else
            VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param[VCAST_TI_9_68_index]))));
          VCAST_TI_9_68_value_printed = 1;
          vCAST_DATA_FIELD = VCAST_TI_9_68_local_field;
        } /* if */
        if (VCAST_TI_9_68_index >= VCAST_TI_9_68_last)
          break;
        VCAST_TI_9_68_index++;
      } /* loop */
      if ((vCAST_COMMAND == vCAST_PRINT)&&(!VCAST_TI_9_68_value_printed))
        vectorcast_fprint_string(vCAST_OUTPUT_FILE,"<<past end of array>>\n");
    } /* if */
  }
} /* end VCAST_TI_9_68 */



/* A typedef */
#line 2293 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\S0000009.c"
void VCAST_TI_9_27 ( s_rb_EEPROMStruct_PD_g *vcast_param ) 
{




  {
    switch ( vcast_get_param () ) { /* Choose field member */
      /* Setting member variable vcast_param->ProductionData_g */
      case 1: { 
        VCAST_TI_9_63 ( ((unsigned char *)(vcast_param->ProductionData_g)));
        break; /* end case 1*/
      } /* end case */
      /* Setting member variable vcast_param->EEKodierbyte2_g */
      case 2: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->EEKodierbyte2_g))));
        break; /* end case 2*/
      } /* end case */
      /* Setting member variable vcast_param->EEKodierbyte1_g */
      case 3: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->EEKodierbyte1_g))));
        break; /* end case 3*/
      } /* end case */
      /* Setting member variable vcast_param->EEKodierbyte0_g */
      case 4: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->EEKodierbyte0_g))));
        break; /* end case 4*/
      } /* end case */
      /* Setting member variable vcast_param->ALS1_4_Setting_g */
      case 5: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->ALS1_4_Setting_g))));
        break; /* end case 5*/
      } /* end case */
      /* Setting member variable vcast_param->ALS5_6_INREC_Setting_g */
      case 6: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->ALS5_6_INREC_Setting_g))));
        break; /* end case 6*/
      } /* end case */
      /* Setting member variable vcast_param->ASIC_DIAGV_g */
      case 7: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->ASIC_DIAGV_g))));
        break; /* end case 7*/
      } /* end case */
      /* Setting member variable vcast_param->A_Factor_ALS1_g */
      case 8: { 
        VCAST_TI_9_22 ( ((unsigned *)(&(vcast_param->A_Factor_ALS1_g))));
        break; /* end case 8*/
      } /* end case */
      /* Setting member variable vcast_param->A_Factor_ALS2_g */
      case 9: { 
        VCAST_TI_9_22 ( ((unsigned *)(&(vcast_param->A_Factor_ALS2_g))));
        break; /* end case 9*/
      } /* end case */
      /* Setting member variable vcast_param->A_Factor_ALS3_g */
      case 10: { 
        VCAST_TI_9_22 ( ((unsigned *)(&(vcast_param->A_Factor_ALS3_g))));
        break; /* end case 10*/
      } /* end case */
      /* Setting member variable vcast_param->A_Factor_ALS4_g */
      case 11: { 
        VCAST_TI_9_22 ( ((unsigned *)(&(vcast_param->A_Factor_ALS4_g))));
        break; /* end case 11*/
      } /* end case */
      /* Setting member variable vcast_param->A_Factor_ALS5_g */
      case 12: { 
        VCAST_TI_9_22 ( ((unsigned *)(&(vcast_param->A_Factor_ALS5_g))));
        break; /* end case 12*/
      } /* end case */
      /* Setting member variable vcast_param->A_Factor_ALS6_g */
      case 13: { 
        VCAST_TI_9_22 ( ((unsigned *)(&(vcast_param->A_Factor_ALS6_g))));
        break; /* end case 13*/
      } /* end case */
      /* Setting member variable vcast_param->A_Factor_INREC_g */
      case 14: { 
        VCAST_TI_9_22 ( ((unsigned *)(&(vcast_param->A_Factor_INREC_g))));
        break; /* end case 14*/
      } /* end case */
      /* Setting member variable vcast_param->B_Factor_Iref_Lo_Gain_Lo_g */
      case 15: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->B_Factor_Iref_Lo_Gain_Lo_g))));
        break; /* end case 15*/
      } /* end case */
      /* Setting member variable vcast_param->B_Factor_Iref_Lo_Gain_Hi_g */
      case 16: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->B_Factor_Iref_Lo_Gain_Hi_g))));
        break; /* end case 16*/
      } /* end case */
      /* Setting member variable vcast_param->B_Factor_Iref_Hi_Gain_Lo_g */
      case 17: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->B_Factor_Iref_Hi_Gain_Lo_g))));
        break; /* end case 17*/
      } /* end case */
      /* Setting member variable vcast_param->B_Factor_Iref_Hi_Gain_Hi_g */
      case 18: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->B_Factor_Iref_Hi_Gain_Hi_g))));
        break; /* end case 18*/
      } /* end case */
      /* Setting member variable vcast_param->CRC_Checksum_calibration_g */
      case 19: { 
        VCAST_TI_9_22 ( ((unsigned *)(&(vcast_param->CRC_Checksum_calibration_g))));
        break; /* end case 19*/
      } /* end case */
      /* Setting member variable vcast_param->Standby_rain_measurement_1_g */
      case 20: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->Standby_rain_measurement_1_g))));
        break; /* end case 20*/
      } /* end case */
      /* Setting member variable vcast_param->Standby_rain_measurement_2_g */
      case 21: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->Standby_rain_measurement_2_g))));
        break; /* end case 21*/
      } /* end case */
      /* Setting member variable vcast_param->Standby_rain_measurement_3_g */
      case 22: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->Standby_rain_measurement_3_g))));
        break; /* end case 22*/
      } /* end case */
      /* Setting member variable vcast_param->Standby_rain_measurement_4_g */
      case 23: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->Standby_rain_measurement_4_g))));
        break; /* end case 23*/
      } /* end case */
      /* Setting member variable vcast_param->Standby_rain_measurement_5_g */
      case 24: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->Standby_rain_measurement_5_g))));
        break; /* end case 24*/
      } /* end case */
      /* Setting member variable vcast_param->Standby_rain_measurement_6_g */
      case 25: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->Standby_rain_measurement_6_g))));
        break; /* end case 25*/
      } /* end case */
      /* Setting member variable vcast_param->ASIC_Sched_Config_g */
      case 26: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->ASIC_Sched_Config_g))));
        break; /* end case 26*/
      } /* end case */
      /* Setting member variable vcast_param->ASIC_LCTR_g */
      case 27: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->ASIC_LCTR_g))));
        break; /* end case 27*/
      } /* end case */
      /* Setting member variable vcast_param->NO_RAIN_PRESENT_THRSH_HB_g */
      case 28: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->NO_RAIN_PRESENT_THRSH_HB_g))));
        break; /* end case 28*/
      } /* end case */
      /* Setting member variable vcast_param->NO_RAIN_PRESENT_THRSH_LB_g */
      case 29: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->NO_RAIN_PRESENT_THRSH_LB_g))));
        break; /* end case 29*/
      } /* end case */
      /* Setting member variable vcast_param->STBY_REGV_Imbalance_g */
      case 30: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->STBY_REGV_Imbalance_g))));
        break; /* end case 30*/
      } /* end case */
      /* Setting member variable vcast_param->RSControlFlags */
      case 31: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->RSControlFlags))));
        break; /* end case 31*/
      } /* end case */
      /* Setting member variable vcast_param->EEPROM_Erase_Counter */
      case 32: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->EEPROM_Erase_Counter))));
        break; /* end case 32*/
      } /* end case */
      /* Setting member variable vcast_param->HardwareStand */
      case 33: { 
        VCAST_TI_9_64 ( ((unsigned char *)(vcast_param->HardwareStand)));
        break; /* end case 33*/
      } /* end case */
      /* Setting member variable vcast_param->Produktionsdaten */
      case 34: { 
        VCAST_TI_9_41 ( ((unsigned char *)(vcast_param->Produktionsdaten)));
        break; /* end case 34*/
      } /* end case */
      /* Setting member variable vcast_param->Fertigungsdatum */
      case 35: { 
        VCAST_TI_9_65 ( ((unsigned char *)(vcast_param->Fertigungsdatum)));
        break; /* end case 35*/
      } /* end case */
      /* Setting member variable vcast_param->Audi_HW_Partnumber */
      case 36: { 
        VCAST_TI_9_43 ( ((unsigned char *)(vcast_param->Audi_HW_Partnumber)));
        break; /* end case 36*/
      } /* end case */
      /* Setting member variable vcast_param->NAD */
      case 37: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->NAD))));
        break; /* end case 37*/
      } /* end case */
      /* Setting member variable vcast_param->IDFSs_01 */
      case 38: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->IDFSs_01))));
        break; /* end case 38*/
      } /* end case */
      /* Setting member variable vcast_param->IDRLSs_01 */
      case 39: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->IDRLSs_01))));
        break; /* end case 39*/
      } /* end case */
      /* Setting member variable vcast_param->IDBCM1_LIN1_01 */
      case 40: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->IDBCM1_LIN1_01))));
        break; /* end case 40*/
      } /* end case */
      /* Setting member variable vcast_param->IDWWSs_01 */
      case 41: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->IDWWSs_01))));
        break; /* end case 41*/
      } /* end case */
      /* Setting member variable vcast_param->IDSOSES_01 */
      case 42: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->IDSOSES_01))));
        break; /* end case 42*/
      } /* end case */
      /* Setting member variable vcast_param->ASIC_Frame_01_g */
      case 43: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->ASIC_Frame_01_g))));
        break; /* end case 43*/
      } /* end case */
      /* Setting member variable vcast_param->ASIC_Frame_02_g */
      case 44: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->ASIC_Frame_02_g))));
        break; /* end case 44*/
      } /* end case */
      /* Setting member variable vcast_param->ASIC_Frame_03_g */
      case 45: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->ASIC_Frame_03_g))));
        break; /* end case 45*/
      } /* end case */
      /* Setting member variable vcast_param->ASIC_Frame_04_g */
      case 46: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->ASIC_Frame_04_g))));
        break; /* end case 46*/
      } /* end case */
      /* Setting member variable vcast_param->ASIC_RCTR_REG_g */
      case 47: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->ASIC_RCTR_REG_g))));
        break; /* end case 47*/
      } /* end case */
      /* Setting member variable vcast_param->ASIC_RFCTR_REG_g */
      case 48: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->ASIC_RFCTR_REG_g))));
        break; /* end case 48*/
      } /* end case */
      /* Setting member variable vcast_param->Error_Active_1_g */
      case 49: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->Error_Active_1_g))));
        break; /* end case 49*/
      } /* end case */
      /* Setting member variable vcast_param->Error_Active_2_g */
      case 50: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->Error_Active_2_g))));
        break; /* end case 50*/
      } /* end case */
      /* Setting member variable vcast_param->Error_Active_3_g */
      case 51: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->Error_Active_3_g))));
        break; /* end case 51*/
      } /* end case */
      /* Setting member variable vcast_param->Erase_counter */
      case 52: { 
        VCAST_TI_9_41 ( ((unsigned char *)(vcast_param->Erase_counter)));
        break; /* end case 52*/
      } /* end case */
      /* Setting member variable vcast_param->VariantID_g */
      case 53: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->VariantID_g))));
        break; /* end case 53*/
      } /* end case */
      /* Setting member variable vcast_param->FunctionID_g */
      case 54: { 
        VCAST_TI_9_22 ( ((unsigned *)(&(vcast_param->FunctionID_g))));
        break; /* end case 54*/
      } /* end case */
      /* Setting member variable vcast_param->IDERRDATA_01 */
      case 55: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->IDERRDATA_01))));
        break; /* end case 55*/
      } /* end case */
      /* Setting member variable vcast_param->IDSPARE_01 */
      case 56: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->IDSPARE_01))));
        break; /* end case 56*/
      } /* end case */
      /* Setting member variable vcast_param->IDRLSs_02 */
      case 57: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->IDRLSs_02))));
        break; /* end case 57*/
      } /* end case */
      /* Setting member variable vcast_param->IDBCM1_LIN1_02 */
      case 58: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->IDBCM1_LIN1_02))));
        break; /* end case 58*/
      } /* end case */
      /* Setting member variable vcast_param->HUD_Factor_g */
      case 59: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->HUD_Factor_g))));
        break; /* end case 59*/
      } /* end case */
      /* Setting member variable vcast_param->IDRLSs_03 */
      case 60: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->IDRLSs_03))));
        break; /* end case 60*/
      } /* end case */
      /* Setting member variable vcast_param->IDRLSs_04 */
      case 61: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->IDRLSs_04))));
        break; /* end case 61*/
      } /* end case */
      /* Setting member variable vcast_param->IDRLSs_05 */
      case 62: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->IDRLSs_05))));
        break; /* end case 62*/
      } /* end case */
      /* Setting member variable vcast_param->IDRLSs_06 */
      case 63: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->IDRLSs_06))));
        break; /* end case 63*/
      } /* end case */
      /* Setting member variable vcast_param->IDBCM1_LIN1_03 */
      case 64: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->IDBCM1_LIN1_03))));
        break; /* end case 64*/
      } /* end case */
      /* Setting member variable vcast_param->IDBCM1_LIN1_04 */
      case 65: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->IDBCM1_LIN1_04))));
        break; /* end case 65*/
      } /* end case */
      /* Setting member variable vcast_param->IDBCM1_LIN1_05 */
      case 66: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->IDBCM1_LIN1_05))));
        break; /* end case 66*/
      } /* end case */
      /* Setting member variable vcast_param->HUD_MAX_Value */
      case 67: { 
        VCAST_TI_9_22 ( ((unsigned *)(&(vcast_param->HUD_MAX_Value))));
        break; /* end case 67*/
      } /* end case */
      /* Setting member variable vcast_param->HUD_MAX_Resolution */
      case 68: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->HUD_MAX_Resolution))));
        break; /* end case 68*/
      } /* end case */
      default:
        vCAST_TOOL_ERROR = vCAST_true;
    } /* end switch */ 
  }


} /* end VCAST_TI_9_27 */



/* An array */
#line 2659 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\S0000009.c"
void VCAST_TI_9_79 ( unsigned char vcast_param[194] ) 
{
  {
    int VCAST_TI_9_79_array_index = 0;
    int VCAST_TI_9_79_index = 0;
    int VCAST_TI_9_79_first, VCAST_TI_9_79_last;
    int VCAST_TI_9_79_more_data; /* true if there is more data in the current command */
    int VCAST_TI_9_79_local_field = 0;
    int VCAST_TI_9_79_value_printed = 0;
    int VCAST_TI_9_79_is_string = (VCAST_FIND_INDEX()==-1);


    vcast_get_range_value (&VCAST_TI_9_79_first, &VCAST_TI_9_79_last, &VCAST_TI_9_79_more_data);
    VCAST_TI_9_79_local_field = vCAST_DATA_FIELD;
    if ( vCAST_SIZE && (!VCAST_TI_9_79_more_data)) { /* get the size of the array */
      vectorcast_fprint_integer (vCAST_OUTPUT_FILE,194);
      vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
      vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n");
    } else {
      int VCAST_TI_9_79_upper = 194;
      for (VCAST_TI_9_79_array_index=0; VCAST_TI_9_79_array_index< VCAST_TI_9_79_upper; VCAST_TI_9_79_array_index++){
        if ( (VCAST_TI_9_79_index >= VCAST_TI_9_79_first) && ( VCAST_TI_9_79_index <= VCAST_TI_9_79_last)){
          if ( VCAST_TI_9_79_is_string )
            VCAST_TI_STRING ( (char**)&vcast_param, sizeof ( vcast_param ), 1,VCAST_TI_9_79_upper);
          else
            VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param[VCAST_TI_9_79_index]))));
          VCAST_TI_9_79_value_printed = 1;
          vCAST_DATA_FIELD = VCAST_TI_9_79_local_field;
        } /* if */
        if (VCAST_TI_9_79_index >= VCAST_TI_9_79_last)
          break;
        VCAST_TI_9_79_index++;
      } /* loop */
      if ((vCAST_COMMAND == vCAST_PRINT)&&(!VCAST_TI_9_79_value_printed))
        vectorcast_fprint_string(vCAST_OUTPUT_FILE,"<<past end of array>>\n");
    } /* if */
  }
} /* end VCAST_TI_9_79 */



/* A typedef */
#line 2708 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\S0000009.c"
void VCAST_TI_9_29 ( s_rb_EEPROMStruct_AD_g *vcast_param ) 
{




  {
    switch ( vcast_get_param () ) { /* Choose field member */
      /* Setting member variable vcast_param->PrametersStruct */
      case 1: { 
        VCAST_TI_9_72 ( ((s_rb_PrametersStruct_g *)(vcast_param->PrametersStruct)));
        break; /* end case 1*/
      } /* end case */
      /* Setting member variable vcast_param->RS_GainSetupArray */
      case 2: { 
        VCAST_TI_9_111 ( ((unsigned char *)(vcast_param->RS_GainSetupArray)));
        break; /* end case 2*/
      } /* end case */
      /* Setting member variable vcast_param->HALIOS_Clock_Control_Reg_g */
      case 3: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->HALIOS_Clock_Control_Reg_g))));
        break; /* end case 3*/
      } /* end case */
      /* Setting member variable vcast_param->ACTR_Reg_g */
      case 4: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->ACTR_Reg_g))));
        break; /* end case 4*/
      } /* end case */
      /* Setting member variable vcast_param->PCO_PI_Regulator_g */
      case 5: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->PCO_PI_Regulator_g))));
        break; /* end case 5*/
      } /* end case */
      /* Setting member variable vcast_param->ICO1H_g */
      case 6: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->ICO1H_g))));
        break; /* end case 6*/
      } /* end case */
      /* Setting member variable vcast_param->ICO1L_g */
      case 7: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->ICO1L_g))));
        break; /* end case 7*/
      } /* end case */
      /* Setting member variable vcast_param->ICO2H_g */
      case 8: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->ICO2H_g))));
        break; /* end case 8*/
      } /* end case */
      /* Setting member variable vcast_param->ICO2L_g */
      case 9: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->ICO2L_g))));
        break; /* end case 9*/
      } /* end case */
      /* Setting member variable vcast_param->FOSC_LEDUL_g */
      case 10: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->FOSC_LEDUL_g))));
        break; /* end case 10*/
      } /* end case */
      /* Setting member variable vcast_param->INTCO_g */
      case 11: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->INTCO_g))));
        break; /* end case 11*/
      } /* end case */
      /* Setting member variable vcast_param->StandbyTimout */
      case 12: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->StandbyTimout))));
        break; /* end case 12*/
      } /* end case */
      /* Setting member variable vcast_param->dec_st2_speicher */
      case 13: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->dec_st2_speicher))));
        break; /* end case 13*/
      } /* end case */
      /* Setting member variable vcast_param->RS_Sensitivity */
      case 14: { 
        VCAST_TI_9_74 ( ((unsigned char *)(vcast_param->RS_Sensitivity)));
        break; /* end case 14*/
      } /* end case */
      /* Setting member variable vcast_param->MaxOverwipeSensitivity */
      case 15: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->MaxOverwipeSensitivity))));
        break; /* end case 15*/
      } /* end case */
      /* Setting member variable vcast_param->StandbyModeScanTime_g */
      case 16: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->StandbyModeScanTime_g))));
        break; /* end case 16*/
      } /* end case */
      /* Setting member variable vcast_param->RainNightBitThrs_g */
      case 17: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->RainNightBitThrs_g))));
        break; /* end case 17*/
      } /* end case */
      /* Setting member variable vcast_param->Amb_Base_Day_Threshold */
      case 18: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->Amb_Base_Day_Threshold))));
        break; /* end case 18*/
      } /* end case */
      /* Setting member variable vcast_param->Amb_Base_Night_Threshold */
      case 19: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->Amb_Base_Night_Threshold))));
        break; /* end case 19*/
      } /* end case */
      /* Setting member variable vcast_param->TunnelDebounceFactor */
      case 20: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->TunnelDebounceFactor))));
        break; /* end case 20*/
      } /* end case */
      /* Setting member variable vcast_param->Customer_FW_SWA_Scaling */
      case 21: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->Customer_FW_SWA_Scaling))));
        break; /* end case 21*/
      } /* end case */
      /* Setting member variable vcast_param->Customer_IR_SWA_Scaling */
      case 22: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->Customer_IR_SWA_Scaling))));
        break; /* end case 22*/
      } /* end case */
      /* Setting member variable vcast_param->FW_Base_Day_Threshold */
      case 23: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->FW_Base_Day_Threshold))));
        break; /* end case 23*/
      } /* end case */
      /* Setting member variable vcast_param->IR_Base_Day_Threshold */
      case 24: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->IR_Base_Day_Threshold))));
        break; /* end case 24*/
      } /* end case */
      /* Setting member variable vcast_param->FW_Base_Night_Threshold */
      case 25: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->FW_Base_Night_Threshold))));
        break; /* end case 25*/
      } /* end case */
      /* Setting member variable vcast_param->IR_Base_Night_Threshold */
      case 26: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->IR_Base_Night_Threshold))));
        break; /* end case 26*/
      } /* end case */
      /* Setting member variable vcast_param->Day_Delay */
      case 27: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->Day_Delay))));
        break; /* end case 27*/
      } /* end case */
      /* Setting member variable vcast_param->Night_Delay */
      case 28: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->Night_Delay))));
        break; /* end case 28*/
      } /* end case */
      /* Setting member variable vcast_param->AfterTunnelDelayOffs */
      case 29: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->AfterTunnelDelayOffs))));
        break; /* end case 29*/
      } /* end case */
      /* Setting member variable vcast_param->p_v_autobahn_on_off_g */
      case 30: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->p_v_autobahn_on_off_g))));
        break; /* end case 30*/
      } /* end case */
      /* Setting member variable vcast_param->p_t_autobahn_delay_on_g */
      case 31: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->p_t_autobahn_delay_on_g))));
        break; /* end case 31*/
      } /* end case */
      /* Setting member variable vcast_param->Frontwaschen_Autobahndelay_g */
      case 32: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->Frontwaschen_Autobahndelay_g))));
        break; /* end case 32*/
      } /* end case */
      /* Setting member variable vcast_param->p_n_regenlichtschwelle_low_high_g */
      case 33: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->p_n_regenlichtschwelle_low_high_g))));
        break; /* end case 33*/
      } /* end case */
      /* Setting member variable vcast_param->p_n_regenlichtschwelle_Zeit_g */
      case 34: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->p_n_regenlichtschwelle_Zeit_g))));
        break; /* end case 34*/
      } /* end case */
      /* Setting member variable vcast_param->TunnelThresholdScaling_g */
      case 35: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->TunnelThresholdScaling_g))));
        break; /* end case 35*/
      } /* end case */
      /* Setting member variable vcast_param->Amb_TunnelThresholdScaling_g */
      case 36: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->Amb_TunnelThresholdScaling_g))));
        break; /* end case 36*/
      } /* end case */
      /* Setting member variable vcast_param->spare */
      case 37: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->spare))));
        break; /* end case 37*/
      } /* end case */
      /* Setting member variable vcast_param->Regulation48LightOnTime_g */
      case 38: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->Regulation48LightOnTime_g))));
        break; /* end case 38*/
      } /* end case */
      /* Setting member variable vcast_param->VeryBrightInTunnelDelay_g */
      case 39: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->VeryBrightInTunnelDelay_g))));
        break; /* end case 39*/
      } /* end case */
      /* Setting member variable vcast_param->Combined_FW_AL_THRs_g */
      case 40: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->Combined_FW_AL_THRs_g))));
        break; /* end case 40*/
      } /* end case */
      /* Setting member variable vcast_param->DYN_COMP_CCD_MINUS_1_g */
      case 41: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->DYN_COMP_CCD_MINUS_1_g))));
        break; /* end case 41*/
      } /* end case */
      /* Setting member variable vcast_param->DYN_COMP_CCD_MINUS_2_g */
      case 42: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->DYN_COMP_CCD_MINUS_2_g))));
        break; /* end case 42*/
      } /* end case */
      /* Setting member variable vcast_param->maxTemperatureOffsett_g */
      case 43: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->maxTemperatureOffsett_g))));
        break; /* end case 43*/
      } /* end case */
      /* Setting member variable vcast_param->ASIC_AFSTHR_REG_g */
      case 44: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->ASIC_AFSTHR_REG_g))));
        break; /* end case 44*/
      } /* end case */
      /* Setting member variable vcast_param->Diag_Request_Factor_g */
      case 45: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->Diag_Request_Factor_g))));
        break; /* end case 45*/
      } /* end case */
      /* Setting member variable vcast_param->cb_inc_speicher_g */
      case 46: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->cb_inc_speicher_g))));
        break; /* end case 46*/
      } /* end case */
      /* Setting member variable vcast_param->I2C_Debug_Config_g */
      case 47: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->I2C_Debug_Config_g))));
        break; /* end case 47*/
      } /* end case */
      /* Setting member variable vcast_param->Audi_SW_Partnumber */
      case 48: { 
        VCAST_TI_9_43 ( ((unsigned char *)(vcast_param->Audi_SW_Partnumber)));
        break; /* end case 48*/
      } /* end case */
      /* Setting member variable vcast_param->wiperSpeedHysteresis */
      case 49: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->wiperSpeedHysteresis))));
        break; /* end case 49*/
      } /* end case */
      /* Setting member variable vcast_param->Proj_Specific_config */
      case 50: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->Proj_Specific_config))));
        break; /* end case 50*/
      } /* end case */
      /* Setting member variable vcast_param->ALSx_Filter_g */
      case 51: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->ALSx_Filter_g))));
        break; /* end case 51*/
      } /* end case */
      /* Setting member variable vcast_param->IrLightTunnelThreshodRng */
      case 52: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->IrLightTunnelThreshodRng))));
        break; /* end case 52*/
      } /* end case */
      /* Setting member variable vcast_param->FwLightTunnelThresholdRng */
      case 53: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->FwLightTunnelThresholdRng))));
        break; /* end case 53*/
      } /* end case */
      /* Setting member variable vcast_param->AmbLightTunnelThresholdRng */
      case 54: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->AmbLightTunnelThresholdRng))));
        break; /* end case 54*/
      } /* end case */
      /* Setting member variable vcast_param->TunWischVerzAktiv */
      case 55: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->TunWischVerzAktiv))));
        break; /* end case 55*/
      } /* end case */
      /* Setting member variable vcast_param->SHTErrorDebounceJitter */
      case 56: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->SHTErrorDebounceJitter))));
        break; /* end case 56*/
      } /* end case */
      /* Setting member variable vcast_param->SolarShadowCorrFactor1 */
      case 57: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->SolarShadowCorrFactor1))));
        break; /* end case 57*/
      } /* end case */
      /* Setting member variable vcast_param->SolarShadowCorrFactor2 */
      case 58: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->SolarShadowCorrFactor2))));
        break; /* end case 58*/
      } /* end case */
      /* Setting member variable vcast_param->E2_MaxSt2SignalLaenge */
      case 59: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->E2_MaxSt2SignalLaenge))));
        break; /* end case 59*/
      } /* end case */
      /* Setting member variable vcast_param->SoftwareStand */
      case 60: { 
        VCAST_TI_9_41 ( ((unsigned char *)(vcast_param->SoftwareStand)));
        break; /* end case 60*/
      } /* end case */
      /* Setting member variable vcast_param->twilightToDarkTime */
      case 61: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->twilightToDarkTime))));
        break; /* end case 61*/
      } /* end case */
      /* Setting member variable vcast_param->darkToTwilightTime */
      case 62: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->darkToTwilightTime))));
        break; /* end case 62*/
      } /* end case */
      /* Setting member variable vcast_param->darkToTwilightThreshFW */
      case 63: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->darkToTwilightThreshFW))));
        break; /* end case 63*/
      } /* end case */
      /* Setting member variable vcast_param->darkToTwilightThreshAMB */
      case 64: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->darkToTwilightThreshAMB))));
        break; /* end case 64*/
      } /* end case */
      /* Setting member variable vcast_param->twilightToDarkThreshFW */
      case 65: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->twilightToDarkThreshFW))));
        break; /* end case 65*/
      } /* end case */
      /* Setting member variable vcast_param->twilightToDarkThreshAMB */
      case 66: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->twilightToDarkThreshAMB))));
        break; /* end case 66*/
      } /* end case */
      /* Setting member variable vcast_param->iceDetectionTemperature */
      case 67: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->iceDetectionTemperature))));
        break; /* end case 67*/
      } /* end case */
      /* Setting member variable vcast_param->Regulation48ThresholdAmb_g */
      case 68: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->Regulation48ThresholdAmb_g))));
        break; /* end case 68*/
      } /* end case */
      /* Setting member variable vcast_param->Regulation48ThresholdFw_g */
      case 69: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->Regulation48ThresholdFw_g))));
        break; /* end case 69*/
      } /* end case */
      /* Setting member variable vcast_param->Threshold_TempIceRisk */
      case 70: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->Threshold_TempIceRisk))));
        break; /* end case 70*/
      } /* end case */
      /* Setting member variable vcast_param->upperTolerance_StartupWipe */
      case 71: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->upperTolerance_StartupWipe))));
        break; /* end case 71*/
      } /* end case */
      /* Setting member variable vcast_param->unused */
      case 72: { 
        VCAST_TI_9_77 ( ((unsigned char *)(vcast_param->unused)));
        break; /* end case 72*/
      } /* end case */
      default:
        vCAST_TOOL_ERROR = vCAST_true;
    } /* end switch */ 
  }


} /* end VCAST_TI_9_29 */



/* An array */
#line 3094 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\S0000009.c"
void VCAST_TI_9_80 ( unsigned char vcast_param[1] ) 
{
  {
    int VCAST_TI_9_80_array_index = 0;
    int VCAST_TI_9_80_index = 0;
    int VCAST_TI_9_80_first, VCAST_TI_9_80_last;
    int VCAST_TI_9_80_more_data; /* true if there is more data in the current command */
    int VCAST_TI_9_80_local_field = 0;
    int VCAST_TI_9_80_value_printed = 0;
    int VCAST_TI_9_80_is_string = (VCAST_FIND_INDEX()==-1);


    vcast_get_range_value (&VCAST_TI_9_80_first, &VCAST_TI_9_80_last, &VCAST_TI_9_80_more_data);
    VCAST_TI_9_80_local_field = vCAST_DATA_FIELD;
    if ( vCAST_SIZE && (!VCAST_TI_9_80_more_data)) { /* get the size of the array */
      vectorcast_fprint_integer (vCAST_OUTPUT_FILE,1);
      vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
      vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n");
    } else {
      int VCAST_TI_9_80_upper = 1;
      for (VCAST_TI_9_80_array_index=0; VCAST_TI_9_80_array_index< VCAST_TI_9_80_upper; VCAST_TI_9_80_array_index++){
        if ( (VCAST_TI_9_80_index >= VCAST_TI_9_80_first) && ( VCAST_TI_9_80_index <= VCAST_TI_9_80_last)){
          if ( VCAST_TI_9_80_is_string )
            VCAST_TI_STRING ( (char**)&vcast_param, sizeof ( vcast_param ), 1,VCAST_TI_9_80_upper);
          else
            VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param[VCAST_TI_9_80_index]))));
          VCAST_TI_9_80_value_printed = 1;
          vCAST_DATA_FIELD = VCAST_TI_9_80_local_field;
        } /* if */
        if (VCAST_TI_9_80_index >= VCAST_TI_9_80_last)
          break;
        VCAST_TI_9_80_index++;
      } /* loop */
      if ((vCAST_COMMAND == vCAST_PRINT)&&(!VCAST_TI_9_80_value_printed))
        vectorcast_fprint_string(vCAST_OUTPUT_FILE,"<<past end of array>>\n");
    } /* if */
  }
} /* end VCAST_TI_9_80 */



/* An array */
#line 3143 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\S0000009.c"
void VCAST_TI_9_8 ( struct _c_bits8 vcast_param[1] ) 
{
  {
    int VCAST_TI_9_8_array_index = 0;
    int VCAST_TI_9_8_index = 0;
    int VCAST_TI_9_8_first, VCAST_TI_9_8_last;
    int VCAST_TI_9_8_more_data; /* true if there is more data in the current command */
    int VCAST_TI_9_8_local_field = 0;
    int VCAST_TI_9_8_value_printed = 0;


    vcast_get_range_value (&VCAST_TI_9_8_first, &VCAST_TI_9_8_last, &VCAST_TI_9_8_more_data);
    VCAST_TI_9_8_local_field = vCAST_DATA_FIELD;
    if ( vCAST_SIZE && (!VCAST_TI_9_8_more_data)) { /* get the size of the array */
      vectorcast_fprint_integer (vCAST_OUTPUT_FILE,1);
      vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
      vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n");
    } else {
      int VCAST_TI_9_8_upper = 1;
      for (VCAST_TI_9_8_array_index=0; VCAST_TI_9_8_array_index< VCAST_TI_9_8_upper; VCAST_TI_9_8_array_index++){
        if ( (VCAST_TI_9_8_index >= VCAST_TI_9_8_first) && ( VCAST_TI_9_8_index <= VCAST_TI_9_8_last)){
          VCAST_TI_9_9 ( ((struct _c_bits8 *)(&(vcast_param[VCAST_TI_9_8_index]))));
          VCAST_TI_9_8_value_printed = 1;
          vCAST_DATA_FIELD = VCAST_TI_9_8_local_field;
        } /* if */
        if (VCAST_TI_9_8_index >= VCAST_TI_9_8_last)
          break;
        VCAST_TI_9_8_index++;
      } /* loop */
      if ((vCAST_COMMAND == vCAST_PRINT)&&(!VCAST_TI_9_8_value_printed))
        vectorcast_fprint_string(vCAST_OUTPUT_FILE,"<<past end of array>>\n");
    } /* if */
  }
} /* end VCAST_TI_9_8 */



/* An array */
#line 3188 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\S0000009.c"
void VCAST_TI_9_81 ( unsigned char vcast_param[(11 + 7) / 8] ) 
{
  {
    int VCAST_TI_9_81_array_index = 0;
    int VCAST_TI_9_81_index = 0;
    int VCAST_TI_9_81_first, VCAST_TI_9_81_last;
    int VCAST_TI_9_81_more_data; /* true if there is more data in the current command */
    int VCAST_TI_9_81_local_field = 0;
    int VCAST_TI_9_81_value_printed = 0;
    int VCAST_TI_9_81_is_string = (VCAST_FIND_INDEX()==-1);


    vcast_get_range_value (&VCAST_TI_9_81_first, &VCAST_TI_9_81_last, &VCAST_TI_9_81_more_data);
    VCAST_TI_9_81_local_field = vCAST_DATA_FIELD;
    if ( vCAST_SIZE && (!VCAST_TI_9_81_more_data)) { /* get the size of the array */
      vectorcast_fprint_integer (vCAST_OUTPUT_FILE,(11 + 7) / 8);
      vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
      vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n");
    } else {
      int VCAST_TI_9_81_upper = (11 + 7) / 8;
      for (VCAST_TI_9_81_array_index=0; VCAST_TI_9_81_array_index< VCAST_TI_9_81_upper; VCAST_TI_9_81_array_index++){
        if ( (VCAST_TI_9_81_index >= VCAST_TI_9_81_first) && ( VCAST_TI_9_81_index <= VCAST_TI_9_81_last)){
          if ( VCAST_TI_9_81_is_string )
            VCAST_TI_STRING ( (char**)&vcast_param, sizeof ( vcast_param ), 1,VCAST_TI_9_81_upper);
          else
            VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param[VCAST_TI_9_81_index]))));
          VCAST_TI_9_81_value_printed = 1;
          vCAST_DATA_FIELD = VCAST_TI_9_81_local_field;
        } /* if */
        if (VCAST_TI_9_81_index >= VCAST_TI_9_81_last)
          break;
        VCAST_TI_9_81_index++;
      } /* loop */
      if ((vCAST_COMMAND == vCAST_PRINT)&&(!VCAST_TI_9_81_value_printed))
        vectorcast_fprint_string(vCAST_OUTPUT_FILE,"<<past end of array>>\n");
    } /* if */
  }
} /* end VCAST_TI_9_81 */



/* An array */
#line 3237 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\S0000009.c"
void VCAST_TI_9_31 ( struct _c_bits16 vcast_param[(11 + 15) / 16] ) 
{
  {
    int VCAST_TI_9_31_array_index = 0;
    int VCAST_TI_9_31_index = 0;
    int VCAST_TI_9_31_first, VCAST_TI_9_31_last;
    int VCAST_TI_9_31_more_data; /* true if there is more data in the current command */
    int VCAST_TI_9_31_local_field = 0;
    int VCAST_TI_9_31_value_printed = 0;


    vcast_get_range_value (&VCAST_TI_9_31_first, &VCAST_TI_9_31_last, &VCAST_TI_9_31_more_data);
    VCAST_TI_9_31_local_field = vCAST_DATA_FIELD;
    if ( vCAST_SIZE && (!VCAST_TI_9_31_more_data)) { /* get the size of the array */
      vectorcast_fprint_integer (vCAST_OUTPUT_FILE,(11 + 15) / 16);
      vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
      vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n");
    } else {
      int VCAST_TI_9_31_upper = (11 + 15) / 16;
      for (VCAST_TI_9_31_array_index=0; VCAST_TI_9_31_array_index< VCAST_TI_9_31_upper; VCAST_TI_9_31_array_index++){
        if ( (VCAST_TI_9_31_index >= VCAST_TI_9_31_first) && ( VCAST_TI_9_31_index <= VCAST_TI_9_31_last)){
          VCAST_TI_9_32 ( ((struct _c_bits16 *)(&(vcast_param[VCAST_TI_9_31_index]))));
          VCAST_TI_9_31_value_printed = 1;
          vCAST_DATA_FIELD = VCAST_TI_9_31_local_field;
        } /* if */
        if (VCAST_TI_9_31_index >= VCAST_TI_9_31_last)
          break;
        VCAST_TI_9_31_index++;
      } /* loop */
      if ((vCAST_COMMAND == vCAST_PRINT)&&(!VCAST_TI_9_31_value_printed))
        vectorcast_fprint_string(vCAST_OUTPUT_FILE,"<<past end of array>>\n");
    } /* if */
  }
} /* end VCAST_TI_9_31 */



/* A typedef */
#line 3282 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\S0000009.c"
void VCAST_TI_9_5 ( Bit_Feld *vcast_param ) 
{




  {
    switch ( vcast_get_param () ) { /* Choose field member */
      /* Setting member variable vcast_param->B0 */
      case 1: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->B0;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->B0 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 1*/
      } /* end case */
      /* Setting member variable vcast_param->B1 */
      case 2: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->B1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->B1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 2*/
      } /* end case */
      /* Setting member variable vcast_param->B2 */
      case 3: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->B2;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->B2 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 3*/
      } /* end case */
      /* Setting member variable vcast_param->B3 */
      case 4: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->B3;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->B3 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 4*/
      } /* end case */
      /* Setting member variable vcast_param->B4 */
      case 5: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->B4;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->B4 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 5*/
      } /* end case */
      /* Setting member variable vcast_param->B5 */
      case 6: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->B5;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->B5 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 6*/
      } /* end case */
      /* Setting member variable vcast_param->B6 */
      case 7: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->B6;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->B6 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 7*/
      } /* end case */
      /* Setting member variable vcast_param->B7 */
      case 8: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->B7;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->B7 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 8*/
      } /* end case */
      default:
        vCAST_TOOL_ERROR = vCAST_true;
    } /* end switch */ 
  }


} /* end VCAST_TI_9_5 */



/* An array */
#line 3364 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\S0000009.c"
void VCAST_TI_9_41 ( unsigned char vcast_param[4] ) 
{
  {
    int VCAST_TI_9_41_array_index = 0;
    int VCAST_TI_9_41_index = 0;
    int VCAST_TI_9_41_first, VCAST_TI_9_41_last;
    int VCAST_TI_9_41_more_data; /* true if there is more data in the current command */
    int VCAST_TI_9_41_local_field = 0;
    int VCAST_TI_9_41_value_printed = 0;
    int VCAST_TI_9_41_is_string = (VCAST_FIND_INDEX()==-1);


    vcast_get_range_value (&VCAST_TI_9_41_first, &VCAST_TI_9_41_last, &VCAST_TI_9_41_more_data);
    VCAST_TI_9_41_local_field = vCAST_DATA_FIELD;
    if ( vCAST_SIZE && (!VCAST_TI_9_41_more_data)) { /* get the size of the array */
      vectorcast_fprint_integer (vCAST_OUTPUT_FILE,4);
      vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
      vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n");
    } else {
      int VCAST_TI_9_41_upper = 4;
      for (VCAST_TI_9_41_array_index=0; VCAST_TI_9_41_array_index< VCAST_TI_9_41_upper; VCAST_TI_9_41_array_index++){
        if ( (VCAST_TI_9_41_index >= VCAST_TI_9_41_first) && ( VCAST_TI_9_41_index <= VCAST_TI_9_41_last)){
          if ( VCAST_TI_9_41_is_string )
            VCAST_TI_STRING ( (char**)&vcast_param, sizeof ( vcast_param ), 1,VCAST_TI_9_41_upper);
          else
            VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param[VCAST_TI_9_41_index]))));
          VCAST_TI_9_41_value_printed = 1;
          vCAST_DATA_FIELD = VCAST_TI_9_41_local_field;
        } /* if */
        if (VCAST_TI_9_41_index >= VCAST_TI_9_41_last)
          break;
        VCAST_TI_9_41_index++;
      } /* loop */
      if ((vCAST_COMMAND == vCAST_PRINT)&&(!VCAST_TI_9_41_value_printed))
        vectorcast_fprint_string(vCAST_OUTPUT_FILE,"<<past end of array>>\n");
    } /* if */
  }
} /* end VCAST_TI_9_41 */



/* A typedef */
#line 3413 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\S0000009.c"
void VCAST_TI_9_55 ( _c_RlsmCem_SerNrLin1Fr01_CEM_LIN1_msgType *vcast_param ) 
{




  {
    switch ( vcast_get_param () ) { /* Choose field member */
      /* Setting member variable vcast_param->RLSMSerNoNr1_CEM_LIN1 */
      case 1: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->RLSMSerNoNr1_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->RLSMSerNoNr1_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 1*/
      } /* end case */
      /* Setting member variable vcast_param->RLSMSerNoNr2_CEM_LIN1 */
      case 2: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->RLSMSerNoNr2_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->RLSMSerNoNr2_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 2*/
      } /* end case */
      /* Setting member variable vcast_param->RLSMSerNoNr3_CEM_LIN1 */
      case 3: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->RLSMSerNoNr3_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->RLSMSerNoNr3_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 3*/
      } /* end case */
      /* Setting member variable vcast_param->RLSMSerNoNr4_CEM_LIN1 */
      case 4: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->RLSMSerNoNr4_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->RLSMSerNoNr4_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 4*/
      } /* end case */
      default:
        vCAST_TOOL_ERROR = vCAST_true;
    } /* end switch */ 
  }


} /* end VCAST_TI_9_55 */



/* An array */
#line 3467 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\S0000009.c"
void VCAST_TI_9_43 ( unsigned char vcast_param[8] ) 
{
  {
    int VCAST_TI_9_43_array_index = 0;
    int VCAST_TI_9_43_index = 0;
    int VCAST_TI_9_43_first, VCAST_TI_9_43_last;
    int VCAST_TI_9_43_more_data; /* true if there is more data in the current command */
    int VCAST_TI_9_43_local_field = 0;
    int VCAST_TI_9_43_value_printed = 0;
    int VCAST_TI_9_43_is_string = (VCAST_FIND_INDEX()==-1);


    vcast_get_range_value (&VCAST_TI_9_43_first, &VCAST_TI_9_43_last, &VCAST_TI_9_43_more_data);
    VCAST_TI_9_43_local_field = vCAST_DATA_FIELD;
    if ( vCAST_SIZE && (!VCAST_TI_9_43_more_data)) { /* get the size of the array */
      vectorcast_fprint_integer (vCAST_OUTPUT_FILE,8);
      vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
      vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n");
    } else {
      int VCAST_TI_9_43_upper = 8;
      for (VCAST_TI_9_43_array_index=0; VCAST_TI_9_43_array_index< VCAST_TI_9_43_upper; VCAST_TI_9_43_array_index++){
        if ( (VCAST_TI_9_43_index >= VCAST_TI_9_43_first) && ( VCAST_TI_9_43_index <= VCAST_TI_9_43_last)){
          if ( VCAST_TI_9_43_is_string )
            VCAST_TI_STRING ( (char**)&vcast_param, sizeof ( vcast_param ), 1,VCAST_TI_9_43_upper);
          else
            VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param[VCAST_TI_9_43_index]))));
          VCAST_TI_9_43_value_printed = 1;
          vCAST_DATA_FIELD = VCAST_TI_9_43_local_field;
        } /* if */
        if (VCAST_TI_9_43_index >= VCAST_TI_9_43_last)
          break;
        VCAST_TI_9_43_index++;
      } /* loop */
      if ((vCAST_COMMAND == vCAST_PRINT)&&(!VCAST_TI_9_43_value_printed))
        vectorcast_fprint_string(vCAST_OUTPUT_FILE,"<<past end of array>>\n");
    } /* if */
  }
} /* end VCAST_TI_9_43 */



/* A typedef */
#line 3516 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\S0000009.c"
void VCAST_TI_9_59 ( _c_RlsmCem_Lin1PartNrFr02_CEM_LIN1_msgType *vcast_param ) 
{




  {
    switch ( vcast_get_param () ) { /* Choose field member */
      /* Setting member variable vcast_param->RLSMPartNo10Nr1_CEM_LIN1 */
      case 1: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->RLSMPartNo10Nr1_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->RLSMPartNo10Nr1_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 1*/
      } /* end case */
      /* Setting member variable vcast_param->RLSMPartNo10Nr2_CEM_LIN1 */
      case 2: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->RLSMPartNo10Nr2_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->RLSMPartNo10Nr2_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 2*/
      } /* end case */
      /* Setting member variable vcast_param->RLSMPartNo10Nr3_CEM_LIN1 */
      case 3: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->RLSMPartNo10Nr3_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->RLSMPartNo10Nr3_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 3*/
      } /* end case */
      /* Setting member variable vcast_param->RLSMPartNo10Nr4_CEM_LIN1 */
      case 4: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->RLSMPartNo10Nr4_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->RLSMPartNo10Nr4_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 4*/
      } /* end case */
      /* Setting member variable vcast_param->RLSMPartNo10Nr5_CEM_LIN1 */
      case 5: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->RLSMPartNo10Nr5_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->RLSMPartNo10Nr5_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 5*/
      } /* end case */
      /* Setting member variable vcast_param->RLSMPartNo10EndSgn1_CEM_LIN1 */
      case 6: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->RLSMPartNo10EndSgn1_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->RLSMPartNo10EndSgn1_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 6*/
      } /* end case */
      /* Setting member variable vcast_param->RLSMPartNo10EndSgn2_CEM_LIN1 */
      case 7: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->RLSMPartNo10EndSgn2_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->RLSMPartNo10EndSgn2_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 7*/
      } /* end case */
      /* Setting member variable vcast_param->RLSMPartNo10EndSgn3_CEM_LIN1 */
      case 8: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->RLSMPartNo10EndSgn3_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->RLSMPartNo10EndSgn3_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 8*/
      } /* end case */
      default:
        vCAST_TOOL_ERROR = vCAST_true;
    } /* end switch */ 
  }


} /* end VCAST_TI_9_59 */



/* An array */
#line 3598 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\S0000009.c"
void VCAST_TI_9_45 ( unsigned char vcast_param[7] ) 
{
  {
    int VCAST_TI_9_45_array_index = 0;
    int VCAST_TI_9_45_index = 0;
    int VCAST_TI_9_45_first, VCAST_TI_9_45_last;
    int VCAST_TI_9_45_more_data; /* true if there is more data in the current command */
    int VCAST_TI_9_45_local_field = 0;
    int VCAST_TI_9_45_value_printed = 0;
    int VCAST_TI_9_45_is_string = (VCAST_FIND_INDEX()==-1);


    vcast_get_range_value (&VCAST_TI_9_45_first, &VCAST_TI_9_45_last, &VCAST_TI_9_45_more_data);
    VCAST_TI_9_45_local_field = vCAST_DATA_FIELD;
    if ( vCAST_SIZE && (!VCAST_TI_9_45_more_data)) { /* get the size of the array */
      vectorcast_fprint_integer (vCAST_OUTPUT_FILE,7);
      vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
      vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n");
    } else {
      int VCAST_TI_9_45_upper = 7;
      for (VCAST_TI_9_45_array_index=0; VCAST_TI_9_45_array_index< VCAST_TI_9_45_upper; VCAST_TI_9_45_array_index++){
        if ( (VCAST_TI_9_45_index >= VCAST_TI_9_45_first) && ( VCAST_TI_9_45_index <= VCAST_TI_9_45_last)){
          if ( VCAST_TI_9_45_is_string )
            VCAST_TI_STRING ( (char**)&vcast_param, sizeof ( vcast_param ), 1,VCAST_TI_9_45_upper);
          else
            VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param[VCAST_TI_9_45_index]))));
          VCAST_TI_9_45_value_printed = 1;
          vCAST_DATA_FIELD = VCAST_TI_9_45_local_field;
        } /* if */
        if (VCAST_TI_9_45_index >= VCAST_TI_9_45_last)
          break;
        VCAST_TI_9_45_index++;
      } /* loop */
      if ((vCAST_COMMAND == vCAST_PRINT)&&(!VCAST_TI_9_45_value_printed))
        vectorcast_fprint_string(vCAST_OUTPUT_FILE,"<<past end of array>>\n");
    } /* if */
  }
} /* end VCAST_TI_9_45 */



/* A typedef */
#line 3647 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\S0000009.c"
void VCAST_TI_9_57 ( _c_RlsmCem_Lin1PartNrFr01_CEM_LIN1_msgType *vcast_param ) 
{




  {
    switch ( vcast_get_param () ) { /* Choose field member */
      /* Setting member variable vcast_param->RLSMPartNoNr1_CEM_LIN1 */
      case 1: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->RLSMPartNoNr1_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->RLSMPartNoNr1_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 1*/
      } /* end case */
      /* Setting member variable vcast_param->RLSMPartNoNr2_CEM_LIN1 */
      case 2: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->RLSMPartNoNr2_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->RLSMPartNoNr2_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 2*/
      } /* end case */
      /* Setting member variable vcast_param->RLSMPartNoNr3_CEM_LIN1 */
      case 3: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->RLSMPartNoNr3_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->RLSMPartNoNr3_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 3*/
      } /* end case */
      /* Setting member variable vcast_param->RLSMPartNoNr4_CEM_LIN1 */
      case 4: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->RLSMPartNoNr4_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->RLSMPartNoNr4_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 4*/
      } /* end case */
      /* Setting member variable vcast_param->RLSMPartNoEndSgn1_CEM_LIN1 */
      case 5: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->RLSMPartNoEndSgn1_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->RLSMPartNoEndSgn1_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 5*/
      } /* end case */
      /* Setting member variable vcast_param->RLSMPartNoEndSgn2_CEM_LIN1 */
      case 6: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->RLSMPartNoEndSgn2_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->RLSMPartNoEndSgn2_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 6*/
      } /* end case */
      /* Setting member variable vcast_param->RLSMPartNoEndSgn3_CEM_LIN1 */
      case 7: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->RLSMPartNoEndSgn3_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->RLSMPartNoEndSgn3_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 7*/
      } /* end case */
      default:
        vCAST_TOOL_ERROR = vCAST_true;
    } /* end switch */ 
  }


} /* end VCAST_TI_9_57 */



/* A typedef */
#line 3722 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\S0000009.c"
void VCAST_TI_9_34 ( _c_RlsmCem_Lin1Fr03_CEM_LIN1_msgType *vcast_param ) 
{




  {
    switch ( vcast_get_param () ) { /* Choose field member */
      /* Setting member variable vcast_param->SolarSnsrErr_CEM_LIN1 */
      case 1: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->SolarSnsrErr_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 3, vCAST_false );
        vcast_param->SolarSnsrErr_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 1*/
      } /* end case */
      /* Setting member variable vcast_param->RainSnsrDiagcRainSnsrHiVoltDetd_CEM_LIN1 */
      case 2: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->RainSnsrDiagcRainSnsrHiVoltDetd_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->RainSnsrDiagcRainSnsrHiVoltDetd_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 2*/
      } /* end case */
      /* Setting member variable vcast_param->RainSnsrDiagcRainSnsrHiTDetd_CEM_LIN1 */
      case 3: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->RainSnsrDiagcRainSnsrHiTDetd_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->RainSnsrDiagcRainSnsrHiTDetd_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 3*/
      } /* end case */
      /* Setting member variable vcast_param->LiOprnMod_CEM_LIN1 */
      case 4: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->LiOprnMod_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 2, vCAST_false );
        vcast_param->LiOprnMod_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 4*/
      } /* end case */
      /* Setting member variable vcast_param->RainDetected_CEM_LIN1 */
      case 5: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->RainDetected_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->RainDetected_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 5*/
      } /* end case */
      /* Setting member variable vcast_param->unused0 */
      case 6: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->unused0;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->unused0 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 6*/
      } /* end case */
      /* Setting member variable vcast_param->SolarSnsrLeValue_CEM_LIN1 */
      case 7: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->SolarSnsrLeValue_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->SolarSnsrLeValue_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 7*/
      } /* end case */
      /* Setting member variable vcast_param->SolarSnsrRiValue_CEM_LIN1 */
      case 8: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->SolarSnsrRiValue_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->SolarSnsrRiValue_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 8*/
      } /* end case */
      /* Setting member variable vcast_param->unused1 */
      case 9: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->unused1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->unused1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 9*/
      } /* end case */
      /* Setting member variable vcast_param->unused2 */
      case 10: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->unused2;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->unused2 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 10*/
      } /* end case */
      /* Setting member variable vcast_param->unused3 */
      case 11: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->unused3;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->unused3 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 11*/
      } /* end case */
      /* Setting member variable vcast_param->unused4 */
      case 12: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->unused4;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->unused4 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 12*/
      } /* end case */
      default:
        vCAST_TOOL_ERROR = vCAST_true;
    } /* end switch */ 
  }


} /* end VCAST_TI_9_34 */



/* A typedef */
#line 3832 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\S0000009.c"
void VCAST_TI_9_36 ( _c_RlsmCem_Lin1Fr02_CEM_LIN1_msgType *vcast_param ) 
{




  {
    switch ( vcast_get_param () ) { /* Choose field member */
      /* Setting member variable vcast_param->CmptFrntWindDewT_CEM_LIN1_0 */
      case 1: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->CmptFrntWindDewT_CEM_LIN1_0;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->CmptFrntWindDewT_CEM_LIN1_0 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 1*/
      } /* end case */
      /* Setting member variable vcast_param->CmptFrntWindDewT_CEM_LIN1_1 */
      case 2: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->CmptFrntWindDewT_CEM_LIN1_1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 3, vCAST_false );
        vcast_param->CmptFrntWindDewT_CEM_LIN1_1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 2*/
      } /* end case */
      /* Setting member variable vcast_param->AmbIllmnFwdStsCntr_CEM_LIN1 */
      case 3: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->AmbIllmnFwdStsCntr_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 4, vCAST_false );
        vcast_param->AmbIllmnFwdStsCntr_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 3*/
      } /* end case */
      /* Setting member variable vcast_param->unused0 */
      case 4: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->unused0;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->unused0 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 4*/
      } /* end case */
      /* Setting member variable vcast_param->AmbIllmnFwdStsAmblillmn2_CEM_LIN1 */
      case 5: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->AmbIllmnFwdStsAmblillmn2_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->AmbIllmnFwdStsAmblillmn2_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 5*/
      } /* end case */
      /* Setting member variable vcast_param->AmbIllmnFwdStsChks_CEM_LIN1 */
      case 6: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->AmbIllmnFwdStsChks_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->AmbIllmnFwdStsChks_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 6*/
      } /* end case */
      /* Setting member variable vcast_param->AmbIllmnFwdStsAmblillmn1_CEM_LIN1_0 */
      case 7: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->AmbIllmnFwdStsAmblillmn1_CEM_LIN1_0;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->AmbIllmnFwdStsAmblillmn1_CEM_LIN1_0 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 7*/
      } /* end case */
      /* Setting member variable vcast_param->AmbIllmnFwdStsAmblillmn1_CEM_LIN1_1 */
      case 8: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->AmbIllmnFwdStsAmblillmn1_CEM_LIN1_1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->AmbIllmnFwdStsAmblillmn1_CEM_LIN1_1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 8*/
      } /* end case */
      /* Setting member variable vcast_param->CmptFrntWindTErr_CEM_LIN1 */
      case 9: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->CmptFrntWindTErr_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->CmptFrntWindTErr_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 9*/
      } /* end case */
      /* Setting member variable vcast_param->RelHumSnsrErr_CEM_LIN1 */
      case 10: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->RelHumSnsrErr_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 3, vCAST_false );
        vcast_param->RelHumSnsrErr_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 10*/
      } /* end case */
      /* Setting member variable vcast_param->CmptFrntWindT_CEM_LIN1_0 */
      case 11: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->CmptFrntWindT_CEM_LIN1_0;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 3, vCAST_false );
        vcast_param->CmptFrntWindT_CEM_LIN1_0 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 11*/
      } /* end case */
      /* Setting member variable vcast_param->CmptFrntWindT_CEM_LIN1_1 */
      case 12: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->CmptFrntWindT_CEM_LIN1_1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->CmptFrntWindT_CEM_LIN1_1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 12*/
      } /* end case */
      /* Setting member variable vcast_param->RelHumSnsrRelHum_CEM_LIN1 */
      case 13: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->RelHumSnsrRelHum_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->RelHumSnsrRelHum_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 13*/
      } /* end case */
      default:
        vCAST_TOOL_ERROR = vCAST_true;
    } /* end switch */ 
  }


} /* end VCAST_TI_9_36 */



/* A typedef */
#line 3949 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\S0000009.c"
void VCAST_TI_9_13 ( _c_RlsmCem_Lin1Fr01_CEM_LIN1_msgType *vcast_param ) 
{




  {
    switch ( vcast_get_param () ) { /* Choose field member */
      /* Setting member variable vcast_param->AutWinWipgCmd_CEM_LIN1 */
      case 1: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->AutWinWipgCmd_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 3, vCAST_false );
        vcast_param->AutWinWipgCmd_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 1*/
      } /* end case */
      /* Setting member variable vcast_param->HudSnsrErrParChk_CEM_LIN1 */
      case 2: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->HudSnsrErrParChk_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->HudSnsrErrParChk_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 2*/
      } /* end case */
      /* Setting member variable vcast_param->HudSnsrErrSnsrErr_CEM_LIN1 */
      case 3: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->HudSnsrErrSnsrErr_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->HudSnsrErrSnsrErr_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 3*/
      } /* end case */
      /* Setting member variable vcast_param->unused0 */
      case 4: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->unused0;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 2, vCAST_false );
        vcast_param->unused0 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 4*/
      } /* end case */
      /* Setting member variable vcast_param->RainLi_CEM_LIN1 */
      case 5: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->RainLi_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->RainLi_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 5*/
      } /* end case */
      /* Setting member variable vcast_param->RainSnsrErrCalErrActv_CEM_LIN1 */
      case 6: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->RainSnsrErrCalErrActv_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->RainSnsrErrCalErrActv_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 6*/
      } /* end case */
      /* Setting member variable vcast_param->RainSnsrErrCalErr_CEM_LIN1 */
      case 7: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->RainSnsrErrCalErr_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->RainSnsrErrCalErr_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 7*/
      } /* end case */
      /* Setting member variable vcast_param->RainSnsrErrRainDetnErr_CEM_LIN1 */
      case 8: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->RainSnsrErrRainDetnErr_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->RainSnsrErrRainDetnErr_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 8*/
      } /* end case */
      /* Setting member variable vcast_param->RainSnsrErrRainDetnErrActv_CEM_LIN1 */
      case 9: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->RainSnsrErrRainDetnErrActv_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->RainSnsrErrRainDetnErrActv_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 9*/
      } /* end case */
      /* Setting member variable vcast_param->WipgAutFrntMod_CEM_LIN1 */
      case 10: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->WipgAutFrntMod_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 2, vCAST_false );
        vcast_param->WipgAutFrntMod_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 10*/
      } /* end case */
      /* Setting member variable vcast_param->unused1 */
      case 11: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->unused1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->unused1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 11*/
      } /* end case */
      /* Setting member variable vcast_param->ErrRespRLSM_CEM_LIN1 */
      case 12: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->ErrRespRLSM_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->ErrRespRLSM_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 12*/
      } /* end case */
      /* Setting member variable vcast_param->unused2 */
      case 13: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->unused2;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->unused2 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 13*/
      } /* end case */
      /* Setting member variable vcast_param->TwliBriRawQf_CEM_LIN1 */
      case 14: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->TwliBriRawQf_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 2, vCAST_false );
        vcast_param->TwliBriRawQf_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 14*/
      } /* end case */
      /* Setting member variable vcast_param->TwliBriRawTwliBriRaw_CEM_LIN1_0 */
      case 15: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->TwliBriRawTwliBriRaw_CEM_LIN1_0;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 6, vCAST_false );
        vcast_param->TwliBriRawTwliBriRaw_CEM_LIN1_0 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 15*/
      } /* end case */
      /* Setting member variable vcast_param->TwliBriRawTwliBriRaw_CEM_LIN1_1 */
      case 16: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->TwliBriRawTwliBriRaw_CEM_LIN1_1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->TwliBriRawTwliBriRaw_CEM_LIN1_1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 16*/
      } /* end case */
      /* Setting member variable vcast_param->unused3 */
      case 17: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->unused3;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->unused3 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 17*/
      } /* end case */
      /* Setting member variable vcast_param->OutdBriChks_CEM_LIN1 */
      case 18: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->OutdBriChks_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->OutdBriChks_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 18*/
      } /* end case */
      /* Setting member variable vcast_param->OutdBriSts_CEM_LIN1 */
      case 19: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->OutdBriSts_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 2, vCAST_false );
        vcast_param->OutdBriSts_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 19*/
      } /* end case */
      /* Setting member variable vcast_param->unused4 */
      case 20: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->unused4;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 6, vCAST_false );
        vcast_param->unused4 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 20*/
      } /* end case */
      default:
        vCAST_TOOL_ERROR = vCAST_true;
    } /* end switch */ 
  }


} /* end VCAST_TI_9_13 */



/* A typedef */
#line 4115 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\S0000009.c"
void VCAST_TI_9_19 ( _c_CemCem_Lin1Fr06_CEM_LIN1_msgType *vcast_param ) 
{




  {
    switch ( vcast_get_param () ) { /* Choose field member */
      /* Setting member variable vcast_param->unused0 */
      case 1: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->unused0;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 4, vCAST_false );
        vcast_param->unused0 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 1*/
      } /* end case */
      /* Setting member variable vcast_param->WiprActv_CEM_LIN1 */
      case 2: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->WiprActv_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->WiprActv_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 2*/
      } /* end case */
      /* Setting member variable vcast_param->WiprInPrkgPosnLo_CEM_LIN1 */
      case 3: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->WiprInPrkgPosnLo_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->WiprInPrkgPosnLo_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 3*/
      } /* end case */
      /* Setting member variable vcast_param->WiprInWipgAr_CEM_LIN1 */
      case 4: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->WiprInWipgAr_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->WiprInWipgAr_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 4*/
      } /* end case */
      /* Setting member variable vcast_param->WshngCycActv_CEM_LIN1 */
      case 5: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->WshngCycActv_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->WshngCycActv_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 5*/
      } /* end case */
      default:
        vCAST_TOOL_ERROR = vCAST_true;
    } /* end switch */ 
  }


} /* end VCAST_TI_9_19 */



/* A typedef */
#line 4176 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\S0000009.c"
void VCAST_TI_9_2 ( _c_CemCem_Lin1Fr05_CEM_LIN1_msgType *vcast_param ) 
{




  {
    switch ( vcast_get_param () ) { /* Choose field member */
      /* Setting member variable vcast_param->unused0 */
      case 1: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->unused0;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->unused0 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 1*/
      } /* end case */
      /* Setting member variable vcast_param->VehMtnStCntr_CEM_LIN1 */
      case 2: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->VehMtnStCntr_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 4, vCAST_false );
        vcast_param->VehMtnStCntr_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 2*/
      } /* end case */
      /* Setting member variable vcast_param->VehMtnStVehMtnSt_CEM_LIN1 */
      case 3: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->VehMtnStVehMtnSt_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 3, vCAST_false );
        vcast_param->VehMtnStVehMtnSt_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 3*/
      } /* end case */
      /* Setting member variable vcast_param->VehMtnStChks_CEM_LIN1 */
      case 4: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->VehMtnStChks_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->VehMtnStChks_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 4*/
      } /* end case */
      /* Setting member variable vcast_param->unused1 */
      case 5: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->unused1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->unused1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 5*/
      } /* end case */
      /* Setting member variable vcast_param->EnaOfflineMonitor_CEM_LIN1 */
      case 6: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->EnaOfflineMonitor_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->EnaOfflineMonitor_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 6*/
      } /* end case */
      /* Setting member variable vcast_param->unused2 */
      case 7: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->unused2;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 6, vCAST_false );
        vcast_param->unused2 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 7*/
      } /* end case */
      /* Setting member variable vcast_param->unused3 */
      case 8: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->unused3;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->unused3 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 8*/
      } /* end case */
      /* Setting member variable vcast_param->unused4 */
      case 9: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->unused4;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->unused4 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 9*/
      } /* end case */
      /* Setting member variable vcast_param->unused5 */
      case 10: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->unused5;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->unused5 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 10*/
      } /* end case */
      /* Setting member variable vcast_param->unused6 */
      case 11: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->unused6;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->unused6 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 11*/
      } /* end case */
      default:
        vCAST_TOOL_ERROR = vCAST_true;
    } /* end switch */ 
  }


} /* end VCAST_TI_9_2 */



/* A typedef */
#line 4279 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\S0000009.c"
void VCAST_TI_9_17 ( _c_CemCem_Lin1Fr04_CEM_LIN1_msgType *vcast_param ) 
{




  {
    switch ( vcast_get_param () ) { /* Choose field member */
      /* Setting member variable vcast_param->unused0 */
      case 1: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->unused0;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->unused0 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 1*/
      } /* end case */
      /* Setting member variable vcast_param->unused1 */
      case 2: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->unused1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->unused1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 2*/
      } /* end case */
      /* Setting member variable vcast_param->unused2 */
      case 3: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->unused2;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->unused2 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 3*/
      } /* end case */
      /* Setting member variable vcast_param->unused3 */
      case 4: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->unused3;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->unused3 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 4*/
      } /* end case */
      /* Setting member variable vcast_param->DoorDrvrSts_CEM_LIN1 */
      case 5: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->DoorDrvrSts_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 2, vCAST_false );
        vcast_param->DoorDrvrSts_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 5*/
      } /* end case */
      /* Setting member variable vcast_param->unused4 */
      case 6: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->unused4;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 6, vCAST_false );
        vcast_param->unused4 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 6*/
      } /* end case */
      /* Setting member variable vcast_param->unused5 */
      case 7: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->unused5;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 4, vCAST_false );
        vcast_param->unused5 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 7*/
      } /* end case */
      /* Setting member variable vcast_param->RainSnsrLiThd_CEM_LIN1 */
      case 8: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->RainSnsrLiThd_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 4, vCAST_false );
        vcast_param->RainSnsrLiThd_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 8*/
      } /* end case */
      /* Setting member variable vcast_param->unused6 */
      case 9: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->unused6;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->unused6 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 9*/
      } /* end case */
      default:
        vCAST_TOOL_ERROR = vCAST_true;
    } /* end switch */ 
  }


} /* end VCAST_TI_9_17 */



/* A typedef */
#line 4368 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\S0000009.c"
void VCAST_TI_9_15 ( _c_CemCem_Lin1Fr03_CEM_LIN1_msgType *vcast_param ) 
{




  {
    switch ( vcast_get_param () ) { /* Choose field member */
      /* Setting member variable vcast_param->RainSnsrSnvtyForUsrSnvty0_CEM_LIN1 */
      case 1: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->RainSnsrSnvtyForUsrSnvty0_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 4, vCAST_false );
        vcast_param->RainSnsrSnvtyForUsrSnvty0_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 1*/
      } /* end case */
      /* Setting member variable vcast_param->RainSnsrSnvtyForUsrSnvty1_CEM_LIN1 */
      case 2: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->RainSnsrSnvtyForUsrSnvty1_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 4, vCAST_false );
        vcast_param->RainSnsrSnvtyForUsrSnvty1_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 2*/
      } /* end case */
      /* Setting member variable vcast_param->RainSnsrSnvtyForUsrSnvty2_CEM_LIN1 */
      case 3: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->RainSnsrSnvtyForUsrSnvty2_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 4, vCAST_false );
        vcast_param->RainSnsrSnvtyForUsrSnvty2_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 3*/
      } /* end case */
      /* Setting member variable vcast_param->RainSnsrSnvtyForUsrSnvty3_CEM_LIN1 */
      case 4: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->RainSnsrSnvtyForUsrSnvty3_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 4, vCAST_false );
        vcast_param->RainSnsrSnvtyForUsrSnvty3_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 4*/
      } /* end case */
      /* Setting member variable vcast_param->RainSnsrSnvtyForUsrSnvty4_CEM_LIN1 */
      case 5: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->RainSnsrSnvtyForUsrSnvty4_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 4, vCAST_false );
        vcast_param->RainSnsrSnvtyForUsrSnvty4_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 5*/
      } /* end case */
      /* Setting member variable vcast_param->RainSnsrSnvtyForUsrSnvty5_CEM_LIN1 */
      case 6: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->RainSnsrSnvtyForUsrSnvty5_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 4, vCAST_false );
        vcast_param->RainSnsrSnvtyForUsrSnvty5_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 6*/
      } /* end case */
      /* Setting member variable vcast_param->RainSnsrSnvtyForUsrSnvty6_CEM_LIN1 */
      case 7: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->RainSnsrSnvtyForUsrSnvty6_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 4, vCAST_false );
        vcast_param->RainSnsrSnvtyForUsrSnvty6_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 7*/
      } /* end case */
      /* Setting member variable vcast_param->VehTyp_CEM_LIN1 */
      case 8: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->VehTyp_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 4, vCAST_false );
        vcast_param->VehTyp_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 8*/
      } /* end case */
      /* Setting member variable vcast_param->WindCorrnValAmb_CEM_LIN1 */
      case 9: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->WindCorrnValAmb_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->WindCorrnValAmb_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 9*/
      } /* end case */
      /* Setting member variable vcast_param->WindCorrnValFrnt_CEM_LIN1 */
      case 10: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->WindCorrnValFrnt_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->WindCorrnValFrnt_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 10*/
      } /* end case */
      /* Setting member variable vcast_param->WindCorrnValHud_CEM_LIN1 */
      case 11: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->WindCorrnValHud_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->WindCorrnValHud_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 11*/
      } /* end case */
      /* Setting member variable vcast_param->FrqCfg_CEM_LIN1 */
      case 12: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->FrqCfg_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 4, vCAST_false );
        vcast_param->FrqCfg_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 12*/
      } /* end case */
      /* Setting member variable vcast_param->ReAdaptReq_CEM_LIN1 */
      case 13: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->ReAdaptReq_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->ReAdaptReq_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 13*/
      } /* end case */
      /* Setting member variable vcast_param->unused0 */
      case 14: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->unused0;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 3, vCAST_false );
        vcast_param->unused0 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 14*/
      } /* end case */
      default:
        vCAST_TOOL_ERROR = vCAST_true;
    } /* end switch */ 
  }


} /* end VCAST_TI_9_15 */



/* A typedef */
#line 4492 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\S0000009.c"
void VCAST_TI_9_11 ( _c_CemCem_Lin1Fr02_CEM_LIN1_msgType *vcast_param ) 
{




  {
    switch ( vcast_get_param () ) { /* Choose field member */
      /* Setting member variable vcast_param->AmbTForVisy_CEM_LIN1 */
      case 1: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->AmbTForVisy_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->AmbTForVisy_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 1*/
      } /* end case */
      /* Setting member variable vcast_param->unused0 */
      case 2: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->unused0;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->unused0 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 2*/
      } /* end case */
      /* Setting member variable vcast_param->VehModMngtGlbSafe1FltEgyCnsWdSts_CEM_LIN1 */
      case 3: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->VehModMngtGlbSafe1FltEgyCnsWdSts_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->VehModMngtGlbSafe1FltEgyCnsWdSts_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 3*/
      } /* end case */
      /* Setting member variable vcast_param->VehModMngtGlbSafe1CarModSts1_CEM_LIN1 */
      case 4: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->VehModMngtGlbSafe1CarModSts1_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 3, vCAST_false );
        vcast_param->VehModMngtGlbSafe1CarModSts1_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 4*/
      } /* end case */
      /* Setting member variable vcast_param->VehModMngtGlbSafe1CarModSubtypWdCarModSubtyp_CEM_LIN1 */
      case 5: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->VehModMngtGlbSafe1CarModSubtypWdCarModSubtyp_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 3, vCAST_false );
        vcast_param->VehModMngtGlbSafe1CarModSubtypWdCarModSubtyp_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 5*/
      } /* end case */
      /* Setting member variable vcast_param->VehModMngtGlbSafe1Chks_CEM_LIN1 */
      case 6: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->VehModMngtGlbSafe1Chks_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->VehModMngtGlbSafe1Chks_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 6*/
      } /* end case */
      /* Setting member variable vcast_param->VehModMngtGlbSafe1EgyLvlElecMai_CEM_LIN1 */
      case 7: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->VehModMngtGlbSafe1EgyLvlElecMai_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 4, vCAST_false );
        vcast_param->VehModMngtGlbSafe1EgyLvlElecMai_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 7*/
      } /* end case */
      /* Setting member variable vcast_param->VehModMngtGlbSafe1Cntr_CEM_LIN1 */
      case 8: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->VehModMngtGlbSafe1Cntr_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 4, vCAST_false );
        vcast_param->VehModMngtGlbSafe1Cntr_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 8*/
      } /* end case */
      /* Setting member variable vcast_param->VehModMngtGlbSafe1PwrLvlElecMai_CEM_LIN1 */
      case 9: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->VehModMngtGlbSafe1PwrLvlElecMai_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 4, vCAST_false );
        vcast_param->VehModMngtGlbSafe1PwrLvlElecMai_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 9*/
      } /* end case */
      /* Setting member variable vcast_param->VehModMngtGlbSafe1EgyLvlElecSubtyp_CEM_LIN1 */
      case 10: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->VehModMngtGlbSafe1EgyLvlElecSubtyp_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 4, vCAST_false );
        vcast_param->VehModMngtGlbSafe1EgyLvlElecSubtyp_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 10*/
      } /* end case */
      /* Setting member variable vcast_param->VehModMngtGlbSafe1UsgModSts_CEM_LIN1 */
      case 11: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->VehModMngtGlbSafe1UsgModSts_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 4, vCAST_false );
        vcast_param->VehModMngtGlbSafe1UsgModSts_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 11*/
      } /* end case */
      /* Setting member variable vcast_param->VehModMngtGlbSafe1PwrLvlElecSubtyp_CEM_LIN1 */
      case 12: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->VehModMngtGlbSafe1PwrLvlElecSubtyp_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 4, vCAST_false );
        vcast_param->VehModMngtGlbSafe1PwrLvlElecSubtyp_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 12*/
      } /* end case */
      /* Setting member variable vcast_param->unused1 */
      case 13: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->unused1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->unused1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 13*/
      } /* end case */
      default:
        vCAST_TOOL_ERROR = vCAST_true;
    } /* end switch */ 
  }


} /* end VCAST_TI_9_11 */



/* An array */
#line 4609 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\S0000009.c"
void VCAST_TI_9_111 ( unsigned char vcast_param[6] ) 
{
  {
    int VCAST_TI_9_111_array_index = 0;
    int VCAST_TI_9_111_index = 0;
    int VCAST_TI_9_111_first, VCAST_TI_9_111_last;
    int VCAST_TI_9_111_more_data; /* true if there is more data in the current command */
    int VCAST_TI_9_111_local_field = 0;
    int VCAST_TI_9_111_value_printed = 0;
    int VCAST_TI_9_111_is_string = (VCAST_FIND_INDEX()==-1);


    vcast_get_range_value (&VCAST_TI_9_111_first, &VCAST_TI_9_111_last, &VCAST_TI_9_111_more_data);
    VCAST_TI_9_111_local_field = vCAST_DATA_FIELD;
    if ( vCAST_SIZE && (!VCAST_TI_9_111_more_data)) { /* get the size of the array */
      vectorcast_fprint_integer (vCAST_OUTPUT_FILE,6);
      vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
      vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n");
    } else {
      int VCAST_TI_9_111_upper = 6;
      for (VCAST_TI_9_111_array_index=0; VCAST_TI_9_111_array_index< VCAST_TI_9_111_upper; VCAST_TI_9_111_array_index++){
        if ( (VCAST_TI_9_111_index >= VCAST_TI_9_111_first) && ( VCAST_TI_9_111_index <= VCAST_TI_9_111_last)){
          if ( VCAST_TI_9_111_is_string )
            VCAST_TI_STRING ( (char**)&vcast_param, sizeof ( vcast_param ), 1,VCAST_TI_9_111_upper);
          else
            VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param[VCAST_TI_9_111_index]))));
          VCAST_TI_9_111_value_printed = 1;
          vCAST_DATA_FIELD = VCAST_TI_9_111_local_field;
        } /* if */
        if (VCAST_TI_9_111_index >= VCAST_TI_9_111_last)
          break;
        VCAST_TI_9_111_index++;
      } /* loop */
      if ((vCAST_COMMAND == vCAST_PRINT)&&(!VCAST_TI_9_111_value_printed))
        vectorcast_fprint_string(vCAST_OUTPUT_FILE,"<<past end of array>>\n");
    } /* if */
  }
} /* end VCAST_TI_9_111 */



/* A typedef */
#line 4658 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\S0000009.c"
void VCAST_TI_9_25 ( _c_CemCem_Lin1Fr01_CEM_LIN1_msgType *vcast_param ) 
{




  {
    switch ( vcast_get_param () ) { /* Choose field member */
      /* Setting member variable vcast_param->VehSpdForWipg_CEM_LIN1 */
      case 1: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->VehSpdForWipg_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 8, vCAST_false );
        vcast_param->VehSpdForWipg_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 1*/
      } /* end case */
      /* Setting member variable vcast_param->WipgPwrActvnSafeWipgPwrAcsyModSafe_CEM_LIN1 */
      case 2: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->WipgPwrActvnSafeWipgPwrAcsyModSafe_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 2, vCAST_false );
        vcast_param->WipgPwrActvnSafeWipgPwrAcsyModSafe_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 2*/
      } /* end case */
      /* Setting member variable vcast_param->WipgPwrActvnSafeWipgPwrDrvgModSafe_CEM_LIN1 */
      case 3: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->WipgPwrActvnSafeWipgPwrDrvgModSafe_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 2, vCAST_false );
        vcast_param->WipgPwrActvnSafeWipgPwrDrvgModSafe_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 3*/
      } /* end case */
      /* Setting member variable vcast_param->RainSensActvn_CEM_LIN1 */
      case 4: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->RainSensActvn_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->RainSensActvn_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 4*/
      } /* end case */
      /* Setting member variable vcast_param->WshrLvrPosnSafe_CEM_LIN1 */
      case 5: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->WshrLvrPosnSafe_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 2, vCAST_false );
        vcast_param->WshrLvrPosnSafe_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 5*/
      } /* end case */
      /* Setting member variable vcast_param->unused0 */
      case 6: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->unused0;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->unused0 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 6*/
      } /* end case */
      /* Setting member variable vcast_param->WiprMotFrntLvrCmdSafeLvrInHiSpdPosnSafe_CEM_LIN1 */
      case 7: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->WiprMotFrntLvrCmdSafeLvrInHiSpdPosnSafe_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 2, vCAST_false );
        vcast_param->WiprMotFrntLvrCmdSafeLvrInHiSpdPosnSafe_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 7*/
      } /* end case */
      /* Setting member variable vcast_param->WiprMotFrntLvrCmdSafeLvrInLoSpdPosnSafe_CEM_LIN1 */
      case 8: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->WiprMotFrntLvrCmdSafeLvrInLoSpdPosnSafe_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 2, vCAST_false );
        vcast_param->WiprMotFrntLvrCmdSafeLvrInLoSpdPosnSafe_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 8*/
      } /* end case */
      /* Setting member variable vcast_param->WiprMotFrntLvrCmdSafeLvrInSnglStrokePos_CEM_LIN1 */
      case 9: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->WiprMotFrntLvrCmdSafeLvrInSnglStrokePos_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->WiprMotFrntLvrCmdSafeLvrInSnglStrokePos_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 9*/
      } /* end case */
      /* Setting member variable vcast_param->WiprMotFrntLvrCmdSafeLvrInIntlPosn_CEM_LIN1 */
      case 10: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->WiprMotFrntLvrCmdSafeLvrInIntlPosn_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->WiprMotFrntLvrCmdSafeLvrInIntlPosn_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 10*/
      } /* end case */
      /* Setting member variable vcast_param->HomeLinkEna_CEM_LIN1 */
      case 11: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->HomeLinkEna_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 2, vCAST_false );
        vcast_param->HomeLinkEna_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 11*/
      } /* end case */
      /* Setting member variable vcast_param->WiprMotIntlCmd_CEM_LIN1 */
      case 12: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->WiprMotIntlCmd_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 3, vCAST_false );
        vcast_param->WiprMotIntlCmd_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 12*/
      } /* end case */
      /* Setting member variable vcast_param->WiprPosnForSrvReq_CEM_LIN1 */
      case 13: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->WiprPosnForSrvReq_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->WiprPosnForSrvReq_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 13*/
      } /* end case */
      /* Setting member variable vcast_param->unused1 */
      case 14: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->unused1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 4, vCAST_false );
        vcast_param->unused1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 14*/
      } /* end case */
      /* Setting member variable vcast_param->IntrMirrCmdIntrMirrDimSnvty_CEM_LIN1 */
      case 15: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->IntrMirrCmdIntrMirrDimSnvty_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 2, vCAST_false );
        vcast_param->IntrMirrCmdIntrMirrDimSnvty_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 15*/
      } /* end case */
      /* Setting member variable vcast_param->IntrMirrCmdDrvrSide_CEM_LIN1 */
      case 16: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->IntrMirrCmdDrvrSide_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->IntrMirrCmdDrvrSide_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 16*/
      } /* end case */
      /* Setting member variable vcast_param->IntrMirrCmdIntrMirrWindHeatrCmpMag_CEM_LIN1 */
      case 17: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->IntrMirrCmdIntrMirrWindHeatrCmpMag_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->IntrMirrCmdIntrMirrWindHeatrCmpMag_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 17*/
      } /* end case */
      /* Setting member variable vcast_param->IntrMirrCmdIntrMirrEna_CEM_LIN1 */
      case 18: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->IntrMirrCmdIntrMirrEna_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->IntrMirrCmdIntrMirrEna_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 18*/
      } /* end case */
      /* Setting member variable vcast_param->IntrMirrCmdIntrMirrInhbDim_CEM_LIN1 */
      case 19: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->IntrMirrCmdIntrMirrInhbDim_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->IntrMirrCmdIntrMirrInhbDim_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 19*/
      } /* end case */
      /* Setting member variable vcast_param->IntrMirrCmdIntrMirrDiagcRst_CEM_LIN1 */
      case 20: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->IntrMirrCmdIntrMirrDiagcRst_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->IntrMirrCmdIntrMirrDiagcRst_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 20*/
      } /* end case */
      /* Setting member variable vcast_param->IntrMirrCmdIntrMirrAsyFanCmpMag_CEM_LIN1 */
      case 21: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->IntrMirrCmdIntrMirrAsyFanCmpMag_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->IntrMirrCmdIntrMirrAsyFanCmpMag_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 21*/
      } /* end case */
      /* Setting member variable vcast_param->WiprMotFrntOffsAg_CEM_LIN1 */
      case 22: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->WiprMotFrntOffsAg_CEM_LIN1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 4, vCAST_false );
        vcast_param->WiprMotFrntOffsAg_CEM_LIN1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 22*/
      } /* end case */
      /* Setting member variable vcast_param->unused2 */
      case 23: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->unused2;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 4, vCAST_false );
        vcast_param->unused2 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 23*/
      } /* end case */
      default:
        vCAST_TOOL_ERROR = vCAST_true;
    } /* end switch */ 
  }


} /* end VCAST_TI_9_25 */



/* A typedef */
#line 4845 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\S0000009.c"
void VCAST_TI_9_21 ( RS_Bit_Feld *vcast_param ) 
{




  {
    switch ( vcast_get_param () ) { /* Choose field member */
      /* Setting member variable vcast_param->B7 */
      case 1: { 
        long VCAST_TI_9_22_ti_bitfield_placeholder = (long) vcast_param->B7;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_22_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->B7 = ( unsigned  ) VCAST_TI_9_22_ti_bitfield_placeholder;
        break; /* end case 1*/
      } /* end case */
      /* Setting member variable vcast_param->B6 */
      case 2: { 
        long VCAST_TI_9_22_ti_bitfield_placeholder = (long) vcast_param->B6;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_22_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->B6 = ( unsigned  ) VCAST_TI_9_22_ti_bitfield_placeholder;
        break; /* end case 2*/
      } /* end case */
      /* Setting member variable vcast_param->B5 */
      case 3: { 
        long VCAST_TI_9_22_ti_bitfield_placeholder = (long) vcast_param->B5;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_22_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->B5 = ( unsigned  ) VCAST_TI_9_22_ti_bitfield_placeholder;
        break; /* end case 3*/
      } /* end case */
      /* Setting member variable vcast_param->B4 */
      case 4: { 
        long VCAST_TI_9_22_ti_bitfield_placeholder = (long) vcast_param->B4;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_22_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->B4 = ( unsigned  ) VCAST_TI_9_22_ti_bitfield_placeholder;
        break; /* end case 4*/
      } /* end case */
      /* Setting member variable vcast_param->B3 */
      case 5: { 
        long VCAST_TI_9_22_ti_bitfield_placeholder = (long) vcast_param->B3;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_22_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->B3 = ( unsigned  ) VCAST_TI_9_22_ti_bitfield_placeholder;
        break; /* end case 5*/
      } /* end case */
      /* Setting member variable vcast_param->B2 */
      case 6: { 
        long VCAST_TI_9_22_ti_bitfield_placeholder = (long) vcast_param->B2;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_22_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->B2 = ( unsigned  ) VCAST_TI_9_22_ti_bitfield_placeholder;
        break; /* end case 6*/
      } /* end case */
      /* Setting member variable vcast_param->B1 */
      case 7: { 
        long VCAST_TI_9_22_ti_bitfield_placeholder = (long) vcast_param->B1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_22_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->B1 = ( unsigned  ) VCAST_TI_9_22_ti_bitfield_placeholder;
        break; /* end case 7*/
      } /* end case */
      /* Setting member variable vcast_param->B0 */
      case 8: { 
        long VCAST_TI_9_22_ti_bitfield_placeholder = (long) vcast_param->B0;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_22_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->B0 = ( unsigned  ) VCAST_TI_9_22_ti_bitfield_placeholder;
        break; /* end case 8*/
      } /* end case */
      default:
        vCAST_TOOL_ERROR = vCAST_true;
    } /* end switch */ 
  }


} /* end VCAST_TI_9_21 */



/* A typedef */
#line 4927 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\S0000009.c"
void VCAST_TI_9_38 ( ASIC_ALI_Meas_t *vcast_param ) 
{




  {
    switch ( vcast_get_param () ) { /* Choose field member */
      /* Setting member variable vcast_param->ad */
      case 1: { 
        VCAST_TI_9_22 ( ((unsigned *)(&(vcast_param->ad))));
        break; /* end case 1*/
      } /* end case */
      /* Setting member variable vcast_param->avg */
      case 2: { 
        VCAST_TI_9_22 ( ((unsigned *)(&(vcast_param->avg))));
        break; /* end case 2*/
      } /* end case */
      default:
        vCAST_TOOL_ERROR = vCAST_true;
    } /* end switch */ 
  }


} /* end VCAST_TI_9_38 */



/* An array */
#line 4963 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\S0000009.c"
void VCAST_TI_9_63 ( unsigned char vcast_param[12] ) 
{
  {
    int VCAST_TI_9_63_array_index = 0;
    int VCAST_TI_9_63_index = 0;
    int VCAST_TI_9_63_first, VCAST_TI_9_63_last;
    int VCAST_TI_9_63_more_data; /* true if there is more data in the current command */
    int VCAST_TI_9_63_local_field = 0;
    int VCAST_TI_9_63_value_printed = 0;
    int VCAST_TI_9_63_is_string = (VCAST_FIND_INDEX()==-1);


    vcast_get_range_value (&VCAST_TI_9_63_first, &VCAST_TI_9_63_last, &VCAST_TI_9_63_more_data);
    VCAST_TI_9_63_local_field = vCAST_DATA_FIELD;
    if ( vCAST_SIZE && (!VCAST_TI_9_63_more_data)) { /* get the size of the array */
      vectorcast_fprint_integer (vCAST_OUTPUT_FILE,12);
      vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
      vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n");
    } else {
      int VCAST_TI_9_63_upper = 12;
      for (VCAST_TI_9_63_array_index=0; VCAST_TI_9_63_array_index< VCAST_TI_9_63_upper; VCAST_TI_9_63_array_index++){
        if ( (VCAST_TI_9_63_index >= VCAST_TI_9_63_first) && ( VCAST_TI_9_63_index <= VCAST_TI_9_63_last)){
          if ( VCAST_TI_9_63_is_string )
            VCAST_TI_STRING ( (char**)&vcast_param, sizeof ( vcast_param ), 1,VCAST_TI_9_63_upper);
          else
            VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param[VCAST_TI_9_63_index]))));
          VCAST_TI_9_63_value_printed = 1;
          vCAST_DATA_FIELD = VCAST_TI_9_63_local_field;
        } /* if */
        if (VCAST_TI_9_63_index >= VCAST_TI_9_63_last)
          break;
        VCAST_TI_9_63_index++;
      } /* loop */
      if ((vCAST_COMMAND == vCAST_PRINT)&&(!VCAST_TI_9_63_value_printed))
        vectorcast_fprint_string(vCAST_OUTPUT_FILE,"<<past end of array>>\n");
    } /* if */
  }
} /* end VCAST_TI_9_63 */



/* An array */
#line 5012 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\S0000009.c"
void VCAST_TI_9_64 ( unsigned char vcast_param[2] ) 
{
  {
    int VCAST_TI_9_64_array_index = 0;
    int VCAST_TI_9_64_index = 0;
    int VCAST_TI_9_64_first, VCAST_TI_9_64_last;
    int VCAST_TI_9_64_more_data; /* true if there is more data in the current command */
    int VCAST_TI_9_64_local_field = 0;
    int VCAST_TI_9_64_value_printed = 0;
    int VCAST_TI_9_64_is_string = (VCAST_FIND_INDEX()==-1);


    vcast_get_range_value (&VCAST_TI_9_64_first, &VCAST_TI_9_64_last, &VCAST_TI_9_64_more_data);
    VCAST_TI_9_64_local_field = vCAST_DATA_FIELD;
    if ( vCAST_SIZE && (!VCAST_TI_9_64_more_data)) { /* get the size of the array */
      vectorcast_fprint_integer (vCAST_OUTPUT_FILE,2);
      vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
      vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n");
    } else {
      int VCAST_TI_9_64_upper = 2;
      for (VCAST_TI_9_64_array_index=0; VCAST_TI_9_64_array_index< VCAST_TI_9_64_upper; VCAST_TI_9_64_array_index++){
        if ( (VCAST_TI_9_64_index >= VCAST_TI_9_64_first) && ( VCAST_TI_9_64_index <= VCAST_TI_9_64_last)){
          if ( VCAST_TI_9_64_is_string )
            VCAST_TI_STRING ( (char**)&vcast_param, sizeof ( vcast_param ), 1,VCAST_TI_9_64_upper);
          else
            VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param[VCAST_TI_9_64_index]))));
          VCAST_TI_9_64_value_printed = 1;
          vCAST_DATA_FIELD = VCAST_TI_9_64_local_field;
        } /* if */
        if (VCAST_TI_9_64_index >= VCAST_TI_9_64_last)
          break;
        VCAST_TI_9_64_index++;
      } /* loop */
      if ((vCAST_COMMAND == vCAST_PRINT)&&(!VCAST_TI_9_64_value_printed))
        vectorcast_fprint_string(vCAST_OUTPUT_FILE,"<<past end of array>>\n");
    } /* if */
  }
} /* end VCAST_TI_9_64 */



/* An array */
#line 5061 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\S0000009.c"
void VCAST_TI_9_65 ( unsigned char vcast_param[3] ) 
{
  {
    int VCAST_TI_9_65_array_index = 0;
    int VCAST_TI_9_65_index = 0;
    int VCAST_TI_9_65_first, VCAST_TI_9_65_last;
    int VCAST_TI_9_65_more_data; /* true if there is more data in the current command */
    int VCAST_TI_9_65_local_field = 0;
    int VCAST_TI_9_65_value_printed = 0;
    int VCAST_TI_9_65_is_string = (VCAST_FIND_INDEX()==-1);


    vcast_get_range_value (&VCAST_TI_9_65_first, &VCAST_TI_9_65_last, &VCAST_TI_9_65_more_data);
    VCAST_TI_9_65_local_field = vCAST_DATA_FIELD;
    if ( vCAST_SIZE && (!VCAST_TI_9_65_more_data)) { /* get the size of the array */
      vectorcast_fprint_integer (vCAST_OUTPUT_FILE,3);
      vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
      vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n");
    } else {
      int VCAST_TI_9_65_upper = 3;
      for (VCAST_TI_9_65_array_index=0; VCAST_TI_9_65_array_index< VCAST_TI_9_65_upper; VCAST_TI_9_65_array_index++){
        if ( (VCAST_TI_9_65_index >= VCAST_TI_9_65_first) && ( VCAST_TI_9_65_index <= VCAST_TI_9_65_last)){
          if ( VCAST_TI_9_65_is_string )
            VCAST_TI_STRING ( (char**)&vcast_param, sizeof ( vcast_param ), 1,VCAST_TI_9_65_upper);
          else
            VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param[VCAST_TI_9_65_index]))));
          VCAST_TI_9_65_value_printed = 1;
          vCAST_DATA_FIELD = VCAST_TI_9_65_local_field;
        } /* if */
        if (VCAST_TI_9_65_index >= VCAST_TI_9_65_last)
          break;
        VCAST_TI_9_65_index++;
      } /* loop */
      if ((vCAST_COMMAND == vCAST_PRINT)&&(!VCAST_TI_9_65_value_printed))
        vectorcast_fprint_string(vCAST_OUTPUT_FILE,"<<past end of array>>\n");
    } /* if */
  }
} /* end VCAST_TI_9_65 */



/* An array */
#line 5110 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\S0000009.c"
void VCAST_TI_9_72 ( s_rb_PrametersStruct_g vcast_param[4] ) 
{
  {
    int VCAST_TI_9_72_array_index = 0;
    int VCAST_TI_9_72_index = 0;
    int VCAST_TI_9_72_first, VCAST_TI_9_72_last;
    int VCAST_TI_9_72_more_data; /* true if there is more data in the current command */
    int VCAST_TI_9_72_local_field = 0;
    int VCAST_TI_9_72_value_printed = 0;


    vcast_get_range_value (&VCAST_TI_9_72_first, &VCAST_TI_9_72_last, &VCAST_TI_9_72_more_data);
    VCAST_TI_9_72_local_field = vCAST_DATA_FIELD;
    if ( vCAST_SIZE && (!VCAST_TI_9_72_more_data)) { /* get the size of the array */
      vectorcast_fprint_integer (vCAST_OUTPUT_FILE,4);
      vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
      vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n");
    } else {
      int VCAST_TI_9_72_upper = 4;
      for (VCAST_TI_9_72_array_index=0; VCAST_TI_9_72_array_index< VCAST_TI_9_72_upper; VCAST_TI_9_72_array_index++){
        if ( (VCAST_TI_9_72_index >= VCAST_TI_9_72_first) && ( VCAST_TI_9_72_index <= VCAST_TI_9_72_last)){
          VCAST_TI_9_70 ( ((s_rb_PrametersStruct_g *)(&(vcast_param[VCAST_TI_9_72_index]))));
          VCAST_TI_9_72_value_printed = 1;
          vCAST_DATA_FIELD = VCAST_TI_9_72_local_field;
        } /* if */
        if (VCAST_TI_9_72_index >= VCAST_TI_9_72_last)
          break;
        VCAST_TI_9_72_index++;
      } /* loop */
      if ((vCAST_COMMAND == vCAST_PRINT)&&(!VCAST_TI_9_72_value_printed))
        vectorcast_fprint_string(vCAST_OUTPUT_FILE,"<<past end of array>>\n");
    } /* if */
  }
} /* end VCAST_TI_9_72 */



/* An array */
#line 5155 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\S0000009.c"
void VCAST_TI_9_74 ( unsigned char vcast_param[9] ) 
{
  {
    int VCAST_TI_9_74_array_index = 0;
    int VCAST_TI_9_74_index = 0;
    int VCAST_TI_9_74_first, VCAST_TI_9_74_last;
    int VCAST_TI_9_74_more_data; /* true if there is more data in the current command */
    int VCAST_TI_9_74_local_field = 0;
    int VCAST_TI_9_74_value_printed = 0;
    int VCAST_TI_9_74_is_string = (VCAST_FIND_INDEX()==-1);


    vcast_get_range_value (&VCAST_TI_9_74_first, &VCAST_TI_9_74_last, &VCAST_TI_9_74_more_data);
    VCAST_TI_9_74_local_field = vCAST_DATA_FIELD;
    if ( vCAST_SIZE && (!VCAST_TI_9_74_more_data)) { /* get the size of the array */
      vectorcast_fprint_integer (vCAST_OUTPUT_FILE,9);
      vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
      vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n");
    } else {
      int VCAST_TI_9_74_upper = 9;
      for (VCAST_TI_9_74_array_index=0; VCAST_TI_9_74_array_index< VCAST_TI_9_74_upper; VCAST_TI_9_74_array_index++){
        if ( (VCAST_TI_9_74_index >= VCAST_TI_9_74_first) && ( VCAST_TI_9_74_index <= VCAST_TI_9_74_last)){
          if ( VCAST_TI_9_74_is_string )
            VCAST_TI_STRING ( (char**)&vcast_param, sizeof ( vcast_param ), 1,VCAST_TI_9_74_upper);
          else
            VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param[VCAST_TI_9_74_index]))));
          VCAST_TI_9_74_value_printed = 1;
          vCAST_DATA_FIELD = VCAST_TI_9_74_local_field;
        } /* if */
        if (VCAST_TI_9_74_index >= VCAST_TI_9_74_last)
          break;
        VCAST_TI_9_74_index++;
      } /* loop */
      if ((vCAST_COMMAND == vCAST_PRINT)&&(!VCAST_TI_9_74_value_printed))
        vectorcast_fprint_string(vCAST_OUTPUT_FILE,"<<past end of array>>\n");
    } /* if */
  }
} /* end VCAST_TI_9_74 */



/* An array */
#line 5204 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\S0000009.c"
void VCAST_TI_9_77 ( unsigned char vcast_param[33] ) 
{
  {
    int VCAST_TI_9_77_array_index = 0;
    int VCAST_TI_9_77_index = 0;
    int VCAST_TI_9_77_first, VCAST_TI_9_77_last;
    int VCAST_TI_9_77_more_data; /* true if there is more data in the current command */
    int VCAST_TI_9_77_local_field = 0;
    int VCAST_TI_9_77_value_printed = 0;
    int VCAST_TI_9_77_is_string = (VCAST_FIND_INDEX()==-1);


    vcast_get_range_value (&VCAST_TI_9_77_first, &VCAST_TI_9_77_last, &VCAST_TI_9_77_more_data);
    VCAST_TI_9_77_local_field = vCAST_DATA_FIELD;
    if ( vCAST_SIZE && (!VCAST_TI_9_77_more_data)) { /* get the size of the array */
      vectorcast_fprint_integer (vCAST_OUTPUT_FILE,33);
      vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
      vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n");
    } else {
      int VCAST_TI_9_77_upper = 33;
      for (VCAST_TI_9_77_array_index=0; VCAST_TI_9_77_array_index< VCAST_TI_9_77_upper; VCAST_TI_9_77_array_index++){
        if ( (VCAST_TI_9_77_index >= VCAST_TI_9_77_first) && ( VCAST_TI_9_77_index <= VCAST_TI_9_77_last)){
          if ( VCAST_TI_9_77_is_string )
            VCAST_TI_STRING ( (char**)&vcast_param, sizeof ( vcast_param ), 1,VCAST_TI_9_77_upper);
          else
            VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param[VCAST_TI_9_77_index]))));
          VCAST_TI_9_77_value_printed = 1;
          vCAST_DATA_FIELD = VCAST_TI_9_77_local_field;
        } /* if */
        if (VCAST_TI_9_77_index >= VCAST_TI_9_77_last)
          break;
        VCAST_TI_9_77_index++;
      } /* loop */
      if ((vCAST_COMMAND == vCAST_PRINT)&&(!VCAST_TI_9_77_value_printed))
        vectorcast_fprint_string(vCAST_OUTPUT_FILE,"<<past end of array>>\n");
    } /* if */
  }
} /* end VCAST_TI_9_77 */



/* A struct */
#line 5253 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\S0000009.c"
void VCAST_TI_9_9 ( struct _c_bits8 *vcast_param ) 
{
  {
    switch ( vcast_get_param () ) { /* Choose field member */
      /* Setting member variable vcast_param->b0 */
      case 1: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->b0;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->b0 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 1*/
      } /* end case */
      /* Setting member variable vcast_param->b1 */
      case 2: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->b1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->b1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 2*/
      } /* end case */
      /* Setting member variable vcast_param->b2 */
      case 3: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->b2;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->b2 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 3*/
      } /* end case */
      /* Setting member variable vcast_param->b3 */
      case 4: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->b3;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->b3 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 4*/
      } /* end case */
      /* Setting member variable vcast_param->b4 */
      case 5: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->b4;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->b4 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 5*/
      } /* end case */
      /* Setting member variable vcast_param->b5 */
      case 6: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->b5;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->b5 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 6*/
      } /* end case */
      /* Setting member variable vcast_param->b6 */
      case 7: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->b6;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->b6 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 7*/
      } /* end case */
      /* Setting member variable vcast_param->b7 */
      case 8: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->b7;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->b7 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 8*/
      } /* end case */
      default:
        vCAST_TOOL_ERROR = vCAST_true;
    } /* end switch */ 
  }
} /* end VCAST_TI_9_9 */



/* A struct */
#line 5329 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\S0000009.c"
void VCAST_TI_9_32 ( struct _c_bits16 *vcast_param ) 
{
  {
    switch ( vcast_get_param () ) { /* Choose field member */
      /* Setting member variable vcast_param->b0 */
      case 1: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->b0;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->b0 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 1*/
      } /* end case */
      /* Setting member variable vcast_param->b1 */
      case 2: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->b1;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->b1 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 2*/
      } /* end case */
      /* Setting member variable vcast_param->b2 */
      case 3: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->b2;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->b2 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 3*/
      } /* end case */
      /* Setting member variable vcast_param->b3 */
      case 4: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->b3;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->b3 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 4*/
      } /* end case */
      /* Setting member variable vcast_param->b4 */
      case 5: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->b4;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->b4 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 5*/
      } /* end case */
      /* Setting member variable vcast_param->b5 */
      case 6: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->b5;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->b5 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 6*/
      } /* end case */
      /* Setting member variable vcast_param->b6 */
      case 7: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->b6;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->b6 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 7*/
      } /* end case */
      /* Setting member variable vcast_param->b7 */
      case 8: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->b7;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->b7 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 8*/
      } /* end case */
      /* Setting member variable vcast_param->b8 */
      case 9: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->b8;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->b8 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 9*/
      } /* end case */
      /* Setting member variable vcast_param->b9 */
      case 10: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->b9;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->b9 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 10*/
      } /* end case */
      /* Setting member variable vcast_param->b10 */
      case 11: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->b10;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->b10 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 11*/
      } /* end case */
      /* Setting member variable vcast_param->b11 */
      case 12: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->b11;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->b11 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 12*/
      } /* end case */
      /* Setting member variable vcast_param->b12 */
      case 13: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->b12;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->b12 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 13*/
      } /* end case */
      /* Setting member variable vcast_param->b13 */
      case 14: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->b13;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->b13 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 14*/
      } /* end case */
      /* Setting member variable vcast_param->b14 */
      case 15: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->b14;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->b14 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 15*/
      } /* end case */
      /* Setting member variable vcast_param->b15 */
      case 16: { 
        long VCAST_TI_9_6_ti_bitfield_placeholder = (long) vcast_param->b15;
        VCAST_TI_BITFIELD ( & VCAST_TI_9_6_ti_bitfield_placeholder, 1, vCAST_false );
        vcast_param->b15 = ( unsigned char  ) VCAST_TI_9_6_ti_bitfield_placeholder;
        break; /* end case 16*/
      } /* end case */
      default:
        vCAST_TOOL_ERROR = vCAST_true;
    } /* end switch */ 
  }
} /* end VCAST_TI_9_32 */



/* A typedef */
#line 5461 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\S0000009.c"
void VCAST_TI_9_70 ( s_rb_PrametersStruct_g *vcast_param ) 
{




  {
    switch ( vcast_get_param () ) { /* Choose field member */
      /* Setting member variable vcast_param->Stufe1_OG */
      case 1: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->Stufe1_OG))));
        break; /* end case 1*/
      } /* end case */
      /* Setting member variable vcast_param->Stufe1_UG */
      case 2: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->Stufe1_UG))));
        break; /* end case 2*/
      } /* end case */
      /* Setting member variable vcast_param->Ep_St2_Epr_In_St2 */
      case 3: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->Ep_St2_Epr_In_St2))));
        break; /* end case 3*/
      } /* end case */
      /* Setting member variable vcast_param->Schwelle_Schwall */
      case 4: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->Schwelle_Schwall))));
        break; /* end case 4*/
      } /* end case */
      /* Setting member variable vcast_param->CW_AnsamlungAdditOffset */
      case 5: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->CW_AnsamlungAdditOffset))));
        break; /* end case 5*/
      } /* end case */
      /* Setting member variable vcast_param->dec_Int_Sp_off */
      case 6: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->dec_Int_Sp_off))));
        break; /* end case 6*/
      } /* end case */
      /* Setting member variable vcast_param->Dec_Stx_Speicher */
      case 7: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->Dec_Stx_Speicher))));
        break; /* end case 7*/
      } /* end case */
      /* Setting member variable vcast_param->dec_Ovr_Speicher */
      case 8: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->dec_Ovr_Speicher))));
        break; /* end case 8*/
      } /* end case */
      /* Setting member variable vcast_param->Empf_Faktor_ST2_Offs */
      case 9: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->Empf_Faktor_ST2_Offs))));
        break; /* end case 9*/
      } /* end case */
      /* Setting member variable vcast_param->Max_Signallaenge */
      case 10: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->Max_Signallaenge))));
        break; /* end case 10*/
      } /* end case */
      /* Setting member variable vcast_param->rb_Stufe1_with_Int_og */
      case 11: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->rb_Stufe1_with_Int_og))));
        break; /* end case 11*/
      } /* end case */
      /* Setting member variable vcast_param->Nachwisch_4_ST1_min */
      case 12: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->Nachwisch_4_ST1_min))));
        break; /* end case 12*/
      } /* end case */
      /* Setting member variable vcast_param->Nachwisch_3 */
      case 13: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->Nachwisch_3))));
        break; /* end case 13*/
      } /* end case */
      /* Setting member variable vcast_param->Nachwisch_2 */
      case 14: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->Nachwisch_2))));
        break; /* end case 14*/
      } /* end case */
      /* Setting member variable vcast_param->RSEmpfFactorScaling */
      case 15: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->RSEmpfFactorScaling))));
        break; /* end case 15*/
      } /* end case */
      /* Setting member variable vcast_param->SchlierenFlag1 */
      case 16: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->SchlierenFlag1))));
        break; /* end case 16*/
      } /* end case */
      /* Setting member variable vcast_param->sig_ans_schw_offs */
      case 17: { 
        VCAST_TI_9_6 ( ((unsigned char *)(&(vcast_param->sig_ans_schw_offs))));
        break; /* end case 17*/
      } /* end case */
      default:
        vCAST_TOOL_ERROR = vCAST_true;
    } /* end switch */ 
  }


} /* end VCAST_TI_9_70 */






void VCAST_TI_RANGE_DATA_9 ( void ) {


  /* Range Data for TI (scalar) VCAST_TI_8_2 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, "NEW_SCALAR\n" );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"900003\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,(-32767-1) );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,((-32767-1) / 2) + (32767 / 2) );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,32767 );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n" );
  /* Range Data for TI (scalar) VCAST_TI_9_6 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, "NEW_SCALAR\n" );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"900006\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,0 );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,(0 / 2) + (0xff / 2) );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,0xff );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n" );
  /* Range Data for TI (array) VCAST_TI_9_8 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, "NEW_ARRAY\n" );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"100003\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,1);
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
  /* Range Data for TI (scalar) VCAST_TI_9_22 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, "NEW_SCALAR\n" );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"900022\n" );
  vectorcast_fprint_unsigned_integer (vCAST_OUTPUT_FILE,0 );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n" );
  vectorcast_fprint_unsigned_integer (vCAST_OUTPUT_FILE,(0 / 2) + (0xffffU / 2) );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n" );
  vectorcast_fprint_unsigned_integer (vCAST_OUTPUT_FILE,0xffffU );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n" );
  /* Range Data for TI (array) VCAST_TI_9_31 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, "NEW_ARRAY\n" );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"100005\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,(11 + 15) / 16);
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
  /* Range Data for TI (array) VCAST_TI_9_37 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, "NEW_ARRAY\n" );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"100006\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,9);
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
  /* Range Data for TI (scalar) VCAST_TI_9_39 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, "NEW_SCALAR\n" );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"900037\n" );
  vectorcast_fprint_unsigned_long (vCAST_OUTPUT_FILE,0 );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n" );
  vectorcast_fprint_unsigned_long (vCAST_OUTPUT_FILE,(0 / 2) + (0xffffffffUL / 2) );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n" );
  vectorcast_fprint_unsigned_long (vCAST_OUTPUT_FILE,0xffffffffUL );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n" );
  /* Range Data for TI (array) VCAST_TI_9_41 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, "NEW_ARRAY\n" );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"100007\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,4);
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
  /* Range Data for TI (array) VCAST_TI_9_43 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, "NEW_ARRAY\n" );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"100008\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,8);
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
  /* Range Data for TI (array) VCAST_TI_9_45 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, "NEW_ARRAY\n" );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"100009\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,7);
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
  /* Range Data for TI (array) VCAST_TI_9_43 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, "NEW_ARRAY\n" );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"100010\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,8);
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
  /* Range Data for TI (array) VCAST_TI_9_43 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, "NEW_ARRAY\n" );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"100011\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,8);
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
  /* Range Data for TI (array) VCAST_TI_9_43 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, "NEW_ARRAY\n" );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"100012\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,8);
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
  /* Range Data for TI (array) VCAST_TI_9_49 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, "NEW_ARRAY\n" );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"100013\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,10);
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
  /* Range Data for TI (array) VCAST_TI_9_50 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, "NEW_ARRAY\n" );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"100014\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,2);
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
  /* Range Data for TI (array) VCAST_TI_9_49 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, "NEW_ARRAY\n" );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"100015\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,10);
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
  /* Range Data for TI (array) VCAST_TI_9_49 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, "NEW_ARRAY\n" );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"100016\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,10);
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
  /* Range Data for TI (array) VCAST_TI_9_54 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, "NEW_ARRAY\n" );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"100017\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,5);
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
  /* Range Data for TI (array) VCAST_TI_9_41 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, "NEW_ARRAY\n" );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"100018\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,4);
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
  /* Range Data for TI (array) VCAST_TI_9_43 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, "NEW_ARRAY\n" );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"100019\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,8);
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
  /* Range Data for TI (array) VCAST_TI_9_63 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, "NEW_ARRAY\n" );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"100023\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,12);
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
  /* Range Data for TI (array) VCAST_TI_9_64 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, "NEW_ARRAY\n" );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"100024\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,2);
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
  /* Range Data for TI (array) VCAST_TI_9_65 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, "NEW_ARRAY\n" );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"100025\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,3);
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
  /* Range Data for TI (array) VCAST_TI_9_41 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, "NEW_ARRAY\n" );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"100026\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,4);
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
  /* Range Data for TI (array) VCAST_TI_9_68 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, "NEW_ARRAY\n" );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"100028\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,(93 + 4) + 10);
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
  /* Range Data for TI (array) VCAST_TI_9_72 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, "NEW_ARRAY\n" );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"100031\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,4);
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
  /* Range Data for TI (array) VCAST_TI_9_111 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, "NEW_ARRAY\n" );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"100032\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,6);
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
  /* Range Data for TI (array) VCAST_TI_9_74 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, "NEW_ARRAY\n" );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"100033\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,9);
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
  /* Range Data for TI (array) VCAST_TI_9_43 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, "NEW_ARRAY\n" );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"100034\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,8);
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
  /* Range Data for TI (array) VCAST_TI_9_41 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, "NEW_ARRAY\n" );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"100035\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,4);
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
  /* Range Data for TI (array) VCAST_TI_9_77 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, "NEW_ARRAY\n" );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"100036\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,33);
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
  /* Range Data for TI (array) VCAST_TI_9_79 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, "NEW_ARRAY\n" );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"100038\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,194);
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
  /* Range Data for TI (array) VCAST_TI_9_80 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, "NEW_ARRAY\n" );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"100039\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,1);
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
  /* Range Data for TI (array) VCAST_TI_9_81 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, "NEW_ARRAY\n" );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"100040\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,(11 + 7) / 8);
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
  /* Range Data for TI (array) VCAST_TI_9_80 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, "NEW_ARRAY\n" );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"100060\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,1);
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
  /* Range Data for TI (array) VCAST_TI_9_45 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, "NEW_ARRAY\n" );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"100062\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,7);
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
  /* Range Data for TI (array) VCAST_TI_9_45 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, "NEW_ARRAY\n" );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"100064\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,7);
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
  /* Range Data for TI (array) VCAST_TI_9_43 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, "NEW_ARRAY\n" );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"100066\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,8);
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
  /* Range Data for TI (array) VCAST_TI_9_45 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, "NEW_ARRAY\n" );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"100068\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,7);
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
  /* Range Data for TI (array) VCAST_TI_9_111 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, "NEW_ARRAY\n" );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"100070\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,6);
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
}
/* Include the file which contains function implementations
for stub processing and value/expected user code */
#line 1 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\G5_RLS_LIN_GEELY2DOT0_uc.c"

void vCAST_VALUE_USER_CODE_9(int vcast_slot_index ) {
  {
  /* INSERT VALUE_USER_CODE_9 */
  }
}

void vCAST_EXPECTED_USER_CODE_9(int vcast_slot_index ) {
  {
  /* INSERT EXPECTED_USER_CODE_9 */
  }
}

void vCAST_EGLOBALS_USER_CODE_9(int vcast_slot_index ) {
  {
  /* INSERT EXPECTED_GLOBALS_USER_CODE_9 */
  }
}

void vCAST_STUB_PROCESSING_9(
        int  UnitIndex, 
        int  SubprogramIndex ) {
  vCAST_GLOBAL_STUB_PROCESSING();
  {
  /* INSERT STUB_VAL_USER_CODE_9 */
  }
}

void vCAST_BEGIN_STUB_PROC_9(
        int  UnitIndex, 
        int  SubprogramIndex ) {
  vCAST_GLOBAL_BEGINNING_OF_STUB_PROCESSING();
  {
  /* INSERT STUB_EXP_USER_CODE_9 */
  }
}

void VCAST_USER_CODE_UNIT_9( VCAST_USER_CODE_TYPE uct, int vcast_slot_index ) {
  switch( uct ) {
    case VCAST_UCT_VALUE:
      vCAST_VALUE_USER_CODE_9(vcast_slot_index);
      break;
    case VCAST_UCT_EXPECTED:
      vCAST_EXPECTED_USER_CODE_9(vcast_slot_index);
      break;
    case VCAST_UCT_EXPECTED_GLOBALS:
      vCAST_EGLOBALS_USER_CODE_9(vcast_slot_index);
      break;
  } /* switch( uct ) */
}
#line 5790 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\S0000009.c"

void vCAST_COMMON_STUB_PROC_9(
            int unitIndex,
            int subprogramIndex,
            int robjectIndex,
            int readEobjectData )
{
   vCAST_BEGIN_STUB_PROC_9(unitIndex, subprogramIndex);
   if ( robjectIndex )
      vCAST_READ_COMMAND_DATA_FOR_ONE_PARAM( unitIndex, subprogramIndex, robjectIndex );
   if ( readEobjectData )
      vCAST_READ_COMMAND_DATA_FOR_ONE_PARAM( unitIndex, subprogramIndex, 0 );
   vCAST_SET_HISTORY( unitIndex, subprogramIndex );
   vCAST_READ_COMMAND_DATA( vCAST_CURRENT_SLOT, unitIndex, subprogramIndex, vCAST_true, vCAST_false );
   vCAST_READ_COMMAND_DATA_FOR_USER_GLOBALS();
   vCAST_STUB_PROCESSING_9(unitIndex, subprogramIndex);
}
#line 53 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123\\vcast_preprocess.11684.16.c"

typedef int VECTORCAST_MARKER__DRIVER_END;
#line 4 "vcast_preprocess.11684.17.c"

typedef int VECTORCAST_MARKER__PREPROCESS_END;
