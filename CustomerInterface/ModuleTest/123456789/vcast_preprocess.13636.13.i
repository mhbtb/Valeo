#line 1 "vcast_preprocess.13636.13.c"

typedef int VECTORCAST_MARKER__PREPROCESS_START;
#line 1 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123456789\\vcast_preprocess.13636.12.c"
#line 1 "C:/Users/zhu1/Downloads/SW_Need_Change_Managemant/GEEA2.0/E4-2_SW/RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03/05_SwDev/01_SrcCode/Application/CustomerInterface/G5_RLS_LIN_GEELY2DOT0.c"
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
#line 1 "C:\\USERS\\ZHU1\\DOWNLOADS\\SW_NEED_CHANGE_MANAGEMANT\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SWDEV\\01_SRCCODE\\APPLICATION\\DEVICE\\ior5f109be.h"
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








#line 33 "C:\\USERS\\ZHU1\\DOWNLOADS\\SW_NEED_CHANGE_MANAGEMANT\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SWDEV\\01_SRCCODE\\APPLICATION\\DEVICE\\ior5f109be.h"





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
#line 236 "C:\\USERS\\ZHU1\\DOWNLOADS\\SW_NEED_CHANGE_MANAGEMANT\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SWDEV\\01_SRCCODE\\APPLICATION\\DEVICE\\ior5f109be.h"

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




#line 355 "C:\\USERS\\ZHU1\\DOWNLOADS\\SW_NEED_CHANGE_MANAGEMANT\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SWDEV\\01_SRCCODE\\APPLICATION\\DEVICE\\ior5f109be.h"









#line 370 "C:\\USERS\\ZHU1\\DOWNLOADS\\SW_NEED_CHANGE_MANAGEMANT\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SWDEV\\01_SRCCODE\\APPLICATION\\DEVICE\\ior5f109be.h"

































#line 410 "C:\\USERS\\ZHU1\\DOWNLOADS\\SW_NEED_CHANGE_MANAGEMANT\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SWDEV\\01_SRCCODE\\APPLICATION\\DEVICE\\ior5f109be.h"




#line 421 "C:\\USERS\\ZHU1\\DOWNLOADS\\SW_NEED_CHANGE_MANAGEMANT\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SWDEV\\01_SRCCODE\\APPLICATION\\DEVICE\\ior5f109be.h"




#line 432 "C:\\USERS\\ZHU1\\DOWNLOADS\\SW_NEED_CHANGE_MANAGEMANT\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SWDEV\\01_SRCCODE\\APPLICATION\\DEVICE\\ior5f109be.h"




#line 443 "C:\\USERS\\ZHU1\\DOWNLOADS\\SW_NEED_CHANGE_MANAGEMANT\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SWDEV\\01_SRCCODE\\APPLICATION\\DEVICE\\ior5f109be.h"




#line 455 "C:\\USERS\\ZHU1\\DOWNLOADS\\SW_NEED_CHANGE_MANAGEMANT\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SWDEV\\01_SRCCODE\\APPLICATION\\DEVICE\\ior5f109be.h"

#line 469 "C:\\USERS\\ZHU1\\DOWNLOADS\\SW_NEED_CHANGE_MANAGEMANT\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SWDEV\\01_SRCCODE\\APPLICATION\\DEVICE\\ior5f109be.h"

#line 481 "C:\\USERS\\ZHU1\\DOWNLOADS\\SW_NEED_CHANGE_MANAGEMANT\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SWDEV\\01_SRCCODE\\APPLICATION\\DEVICE\\ior5f109be.h"

#line 490 "C:\\USERS\\ZHU1\\DOWNLOADS\\SW_NEED_CHANGE_MANAGEMANT\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SWDEV\\01_SRCCODE\\APPLICATION\\DEVICE\\ior5f109be.h"

#line 499 "C:\\USERS\\ZHU1\\DOWNLOADS\\SW_NEED_CHANGE_MANAGEMANT\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SWDEV\\01_SRCCODE\\APPLICATION\\DEVICE\\ior5f109be.h"

#line 513 "C:\\USERS\\ZHU1\\DOWNLOADS\\SW_NEED_CHANGE_MANAGEMANT\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SWDEV\\01_SRCCODE\\APPLICATION\\DEVICE\\ior5f109be.h"

#line 525 "C:\\USERS\\ZHU1\\DOWNLOADS\\SW_NEED_CHANGE_MANAGEMANT\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SWDEV\\01_SRCCODE\\APPLICATION\\DEVICE\\ior5f109be.h"

#line 534 "C:\\USERS\\ZHU1\\DOWNLOADS\\SW_NEED_CHANGE_MANAGEMANT\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SWDEV\\01_SRCCODE\\APPLICATION\\DEVICE\\ior5f109be.h"

#line 543 "C:\\USERS\\ZHU1\\DOWNLOADS\\SW_NEED_CHANGE_MANAGEMANT\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SWDEV\\01_SRCCODE\\APPLICATION\\DEVICE\\ior5f109be.h"

#line 557 "C:\\USERS\\ZHU1\\DOWNLOADS\\SW_NEED_CHANGE_MANAGEMANT\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SWDEV\\01_SRCCODE\\APPLICATION\\DEVICE\\ior5f109be.h"

#line 569 "C:\\USERS\\ZHU1\\DOWNLOADS\\SW_NEED_CHANGE_MANAGEMANT\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SWDEV\\01_SRCCODE\\APPLICATION\\DEVICE\\ior5f109be.h"

#line 578 "C:\\USERS\\ZHU1\\DOWNLOADS\\SW_NEED_CHANGE_MANAGEMANT\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SWDEV\\01_SRCCODE\\APPLICATION\\DEVICE\\ior5f109be.h"

#line 587 "C:\\USERS\\ZHU1\\DOWNLOADS\\SW_NEED_CHANGE_MANAGEMANT\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SWDEV\\01_SRCCODE\\APPLICATION\\DEVICE\\ior5f109be.h"

#line 601 "C:\\USERS\\ZHU1\\DOWNLOADS\\SW_NEED_CHANGE_MANAGEMANT\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SWDEV\\01_SRCCODE\\APPLICATION\\DEVICE\\ior5f109be.h"

#line 613 "C:\\USERS\\ZHU1\\DOWNLOADS\\SW_NEED_CHANGE_MANAGEMANT\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SWDEV\\01_SRCCODE\\APPLICATION\\DEVICE\\ior5f109be.h"

#line 622 "C:\\USERS\\ZHU1\\DOWNLOADS\\SW_NEED_CHANGE_MANAGEMANT\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SWDEV\\01_SRCCODE\\APPLICATION\\DEVICE\\ior5f109be.h"



#pragma language=restore



#line 784 "C:\\USERS\\ZHU1\\DOWNLOADS\\SW_NEED_CHANGE_MANAGEMANT\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SWDEV\\01_SRCCODE\\APPLICATION\\DEVICE\\ior5f109be.h"

/*----------------------------------------------
 *       Interrupt vector addresses
 *--------------------------------------------*/

#line 841 "C:\\USERS\\ZHU1\\DOWNLOADS\\SW_NEED_CHANGE_MANAGEMANT\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SWDEV\\01_SRCCODE\\APPLICATION\\DEVICE\\ior5f109be.h"

/*----------------------------------------------
 *       Callt vector addresses
 *--------------------------------------------*/

#line 878 "C:\\USERS\\ZHU1\\DOWNLOADS\\SW_NEED_CHANGE_MANAGEMANT\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SWDEV\\01_SRCCODE\\APPLICATION\\DEVICE\\ior5f109be.h"

#line 90 "C:/Users/zhu1/Downloads/SW_Need_Change_Managemant/GEEA2.0/E4-2_SW/RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03/05_SwDev/01_SrcCode/Application/CustomerInterface/G5_RLS_LIN_GEELY2DOT0.c"
#line 1 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_projectDefs.h"
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
/*For check in RLFSs*/




#line 281 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_projectDefs.h"
//#define ASIC_TEST







#line 91 "C:/Users/zhu1/Downloads/SW_Need_Change_Managemant/GEEA2.0/E4-2_SW/RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03/05_SwDev/01_SrcCode/Application/CustomerInterface/G5_RLS_LIN_GEELY2DOT0.c"
#line 1 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_E2ProjectConfig.h"
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






#line 1 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_diagnose_GEELY2DOT0_ProjectConfig.h"


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



// ------------------ configuration for AUDI B8 Diagnose --------------


















// ------------------ defines for AUDI B8 Diagnose --------------









/*is rain function */












//#define cw_SupplierID_g             0x0066

/*--------
 00001111
 0000FLSR
Bit 7 dedicated for Response_error. if set, error shall be sent in FS frame else in RLS frame
 --------*/
#line 100 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_diagnose_GEELY2DOT0_ProjectConfig.h"

#line 84 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_E2ProjectConfig.h"




#line 1 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_DiagE2_projectconfig.h"
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






/* Include PD first place */
#line 1 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_GEELY2DOT0_DiagE2Mapping_PD.h"


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
/* For check in RLFSs*/




#line 40 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_GEELY2DOT0_DiagE2Mapping_PD.h"

/*Rain intensity VCO_423: EEPROM coefficient use for the processing of rain intensity during overwipe (default: 40)*/




/*Rain intensity VCO_423: EEPROM thresold for idle time delay (default: 60)*/




/* Rain intensity VCO_423: Threshold for Signal voltage  (default: 3600) */



























































































































































#line 220 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_GEELY2DOT0_DiagE2Mapping_PD.h"




































/*Not used in NL_5  fog ID*/



/**/






























/*Not used in NL_5 WIPER ID*/








/**/























































































































#line 552 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_GEELY2DOT0_DiagE2Mapping_PD.h"

extern const byte cab_SI_Transmission_Offsett[8];


extern const byte __far cb_EEPROMDataDefaultMinMax_PD_g[(93)][3];




typedef struct {
  /*20191226*/
  //byte ProductionData_g[12];          /* 256-267 */
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
	//20191226
  //byte Fertigungsdatum[3];            /* 313, 314, 315*/ 
  byte Audi_HW_Partnumber[8];          /*316,317,318,319,320,321,322,323*/ 
  byte NAD;                           /*324*/
  byte IDFSs_01;                      /*325*/
  byte IDRLSs_01;                     /*326*/
  byte IDBCM1_LIN1_01;                /*327*/
  byte IDWWSs_01;                     /*328*/
  byte IDSOSES_01 ;                   /*329*/
#line 614 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_GEELY2DOT0_DiagE2Mapping_PD.h"
  byte ASIC_RCTR_REG_g ;              /*334*/      /*330*/
  byte ASIC_RFCTR_REG_g ;             /*335*/      /*331*/
  byte Error_Active_1_g ;             /*336*/      /*332*/
  byte Error_Active_2_g ;             /*337*/      /*333*/
  byte Error_Active_3_g ;             /*338*/      /*334*/
  byte Erase_counter[4] ;             /*339*/      /*335*/
  byte VariantID_g;                   /*343*/      /*339*/
  unsigned int FunctionID_g;                 /*344,345*/   /*340,341*/
  byte IDERRDATA_01 ;                /*346*/       /*342*/
  byte IDSPARE_01 ;                  /*347*/       /*343*/
  byte IDRLSs_02;                    /*348*/       /*344*/
  byte IDBCM1_LIN1_02;          /*349*/            /*345*/

  byte HUD_Factor_g;            /*350*/            /*346*/

  byte IDRLSs_03;                    /*351*/       /*347*/
  byte IDRLSs_04;                    /*352*/       /*348*/
  byte IDRLSs_05;                    /*353*/       /*349*/
  byte IDRLSs_06;                    /*354*/       /*350*/
  byte IDBCM1_LIN1_03;          /*355*/            /*351*/   
  byte IDBCM1_LIN1_04;          /*356*/            /*352*/
  byte IDBCM1_LIN1_05;          /*357*/            /*353*/
  unsigned int HUD_MAX_Value;          /*358,359*/         /*354,355*/ 
  byte HUD_MAX_Resolution;      /*360*/            /*356*/
  byte RS_Intensity_OverWipeCoef;                  /*357*/
  byte RS_Intensity_Thr_IdleTime;                  /*358*/
  byte RS_Intensity_SigVoltageH;                   /*359*/
  byte RS_Intensity_SigVoltageL;                   /*360*/ 
  byte SC_ORDER12 ;                   /*361*/
  byte SC_ORDER3 ;                    /*362*/
  byte SC_MAX ;                       /*363*/
} s_rb_EEPROMStruct_PD_g; 



typedef union {
  unsigned char _c[(93)];
  s_rb_EEPROMStruct_PD_g EEPROMStructPD;
} s_rb_EEPROMStructPD_buff_g;



/* PRQA S 3116,0759 4*//*<< 3116:#pragma needed for IAR compiler and MISRA, 0759:union needed to reduce RAM usage >>*/

extern  s_rb_EEPROMStructPD_buff_g EEPROM_Struct_PD;

#line 686 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_GEELY2DOT0_DiagE2Mapping_PD.h"









//#define rab_Fertigungsdatum_g(a)                        (EEPROM_Struct_PD.EEPROMStructPD.Fertigungsdatum[(a)])
#line 716 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_GEELY2DOT0_DiagE2Mapping_PD.h"


/*20191224_Zhiyuan HU_Jiri*/





/*20191224_Zhiyuan HU_Jiri*/


#line 733 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_GEELY2DOT0_DiagE2Mapping_PD.h"

/* PRQA S 3453 1*/ /*<< Function type is required by MISRA, but unions are already used! >>*/

#line 742 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_GEELY2DOT0_DiagE2Mapping_PD.h"


#line 750 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_GEELY2DOT0_DiagE2Mapping_PD.h"
/*VDR_276*/






/* Byte 0*/
#line 764 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_GEELY2DOT0_DiagE2Mapping_PD.h"
/* Byte 1*/
























/* Byte 2*/



#line 802 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_GEELY2DOT0_DiagE2Mapping_PD.h"



#line 815 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_GEELY2DOT0_DiagE2Mapping_PD.h"


#line 85 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_DiagE2_projectconfig.h"




/* Include AD second place */
#line 1 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_DiagE2Mapping_AD.h"


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

#line 1 "C:\\USERS\\ZHU1\\DOWNLOADS\\SW_NEED_CHANGE_MANAGEMANT\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SWDEV\\01_SRCCODE\\APPLICATION\\X1_HUMIDITY\\G5_HumTemp.h"
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
#line 178 "C:\\USERS\\ZHU1\\DOWNLOADS\\SW_NEED_CHANGE_MANAGEMANT\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SWDEV\\01_SRCCODE\\APPLICATION\\X1_HUMIDITY\\G5_HumTemp.h"
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


#line 36 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_DiagE2Mapping_AD.h"













#line 73 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_DiagE2Mapping_AD.h"














































#line 146 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_DiagE2Mapping_AD.h"





























































/*RS empfindlichkeit scaling faktor for Parametersatz 0*/

/*RS empfindlichkeit scaling faktor for Parametersatz 1*/
















/*rain nightbit threshold*/
















































#line 284 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_DiagE2Mapping_AD.h"
/*Autobahn_on_off*/ /*VCO_31 definition of default values new EEPROM definition*/




/*Autobahn Delay on*/




/* Frontwaschen +Autobahndelay*/




/*regenlicht_low_high*/




/*regenlicht */












#line 347 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_DiagE2Mapping_AD.h"





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

















#line 440 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_DiagE2Mapping_AD.h"


#line 449 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_DiagE2Mapping_AD.h"





#line 817 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_DiagE2Mapping_AD.h"



































/*high nibble: right edge leading from low to high speed
low nibble: left edge leading from high to low speed
*/








































































#line 1082 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_DiagE2Mapping_AD.h"

#line 1089 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_DiagE2Mapping_AD.h"












#line 1360 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_DiagE2Mapping_AD.h"

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
#line 1479 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_DiagE2Mapping_AD.h"
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
#line 1555 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_DiagE2Mapping_AD.h"
/*(about 810 lux---Value corrected for 80% transmission through glass)---(Previous Value about 1250 lux)----KI*/
#line 1567 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_DiagE2Mapping_AD.h"



#line 1576 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_DiagE2Mapping_AD.h"


//for 0x84 it is 0x4 *2 = 8

//for 0x84 it is 8 + 2 *8 = 24

 
// for 0xC4 is 4 *3 = 12

// for 0xC4 is 12 +12*5= 72


//for 0x0C it is 24







  


  





#line 1617 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_DiagE2Mapping_AD.h"

#line 1627 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_DiagE2Mapping_AD.h"









/*VCO_31 new EEPROM definition*/





















#line 1766 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_DiagE2Mapping_AD.h"




/*VCO_31 values to write into EEPROM per service 0x2E*/     












#line 1789 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_DiagE2Mapping_AD.h"





























#line 1824 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_DiagE2Mapping_AD.h"













/* betrachtung fur Wischanlage Parkposition unten*/
#line 1844 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_DiagE2Mapping_AD.h"




















/* PRQA S 3453 5*/ /*<< Function type is required by MISRA, but unions are already used! >>*/
/*VDR_131 Following 4 lines correct MISRA Rule 96*/





















#line 91 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_DiagE2_projectconfig.h"

/* Include RD Third place */
#line 1 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_DiagE2Mapping_RD.h"


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













































#line 164 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_DiagE2Mapping_RD.h"



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



#line 247 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_DiagE2Mapping_RD.h"







#line 289 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_DiagE2Mapping_RD.h"




/* special access adresses*/
#line 302 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_DiagE2Mapping_RD.h"

#line 94 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_DiagE2_projectconfig.h"



#line 89 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_E2ProjectConfig.h"


#line 92 "C:/Users/zhu1/Downloads/SW_Need_Change_Managemant/GEEA2.0/E4-2_SW/RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03/05_SwDev/01_SrcCode/Application/CustomerInterface/G5_RLS_LIN_GEELY2DOT0.c"
#line 1 "C:\\USERS\\ZHU1\\DOWNLOADS\\SW_NEED_CHANGE_MANAGEMANT\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SWDEV\\01_SRCCODE\\APPLICATION\\OS\\G5_Appli_main.h"


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




#line 93 "C:/Users/zhu1/Downloads/SW_Need_Change_Managemant/GEEA2.0/E4-2_SW/RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03/05_SwDev/01_SrcCode/Application/CustomerInterface/G5_RLS_LIN_GEELY2DOT0.c"
#line 1 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_lininclude.h"
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






#line 1 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_linconf_GEELY2DOT0.h"
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


#line 87 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_lininclude.h"




#line 1 "C:\\USERS\\ZHU1\\DOWNLOADS\\SW_NEED_CHANGE_MANAGEMANT\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SWDEV\\01_SRCCODE\\APPLICATION\\LIN\\G5_LINsci_sr.h"
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

#line 121 "C:\\USERS\\ZHU1\\DOWNLOADS\\SW_NEED_CHANGE_MANAGEMANT\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SWDEV\\01_SRCCODE\\APPLICATION\\LIN\\G5_LINsci_sr.h"

union tLinIndicationBits {
  canuint8 _c[1];
  struct _c_bits8 w[1];
};



extern  union tLinIndicationBits uLinIndicationFlags;

#line 139 "C:\\USERS\\ZHU1\\DOWNLOADS\\SW_NEED_CHANGE_MANAGEMANT\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SWDEV\\01_SRCCODE\\APPLICATION\\LIN\\G5_LINsci_sr.h"

union tLinConfirmationBits {
  canuint8 _c[1];
  struct _c_bits8 w[1];
};



extern  union tLinConfirmationBits uLinConfirmationFlags;
extern const canuint8 cabLinIndicationOffset[7];
extern const canuint8 cabLinIndicationMask[7];

extern canuint8 const cabLinConfirmationOffset[7];
extern canuint8 const cabLinConfirmationMask[7];



extern byte rb_WBPosition_mg;
extern byte rb_MessageLength_mg;
extern byte rb_WakeupCounter_mg;
extern byte rb_ResponseTime_g; /* VDR_799 */

extern  volatile Flag uF_sciState_mg;





#line 177 "C:\\USERS\\ZHU1\\DOWNLOADS\\SW_NEED_CHANGE_MANAGEMANT\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SWDEV\\01_SRCCODE\\APPLICATION\\LIN\\G5_LINsci_sr.h"


#line 192 "C:\\USERS\\ZHU1\\DOWNLOADS\\SW_NEED_CHANGE_MANAGEMANT\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SWDEV\\01_SRCCODE\\APPLICATION\\LIN\\G5_LINsci_sr.h"

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
#line 92 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_lininclude.h"
#line 1 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_rls_linst.h"


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








/* PRQA S 0841 1 */ /* <<for easier declaration of variable -> proven mechanism>> */


/*VCO_220 VIrefLo/Hi monitoring*/ /*VDR_878*/
#line 72 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_rls_linst.h"


/* PRQA S 750,0759 1 *//*<< 0759:union needed to reduce RAM usage >>*/
  volatile Flag uF_SCIFlags_mg;


 byte rb_LIN_BIT_ERROR_COUNTER_g;
 byte rb_LIN_OVERTHEADERMAX_COUNTER_g;
 byte rb_LIN_CHECKSUMERROR_COUNTER_g;
 byte rb_LIN_OVERTFRAMEMAX_COUNTER_g;
 byte rb_LIN_NORESPONSE_COUNTER_g;
 byte rb_LIN_FRAMINGERROR_COUNTER_g;


#line 94 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_rls_linst.h"
/* PRQA S 750,0759 1 *//*<< 0759:union needed to reduce RAM usage >>*/
  Flag uF_Communication_mg;




#line 114 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_rls_linst.h"







 volatile Flag uF_Butterfly_Flags_g;
#line 130 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_rls_linst.h"





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
#line 93 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_lininclude.h"


#line 1 "C:\\USERS\\ZHU1\\DOWNLOADS\\SW_NEED_CHANGE_MANAGEMANT\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SWDEV\\01_SRCCODE\\APPLICATION\\LIN\\G5_rls_GEELY2DOT0.h"
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

#line 55 "C:\\USERS\\ZHU1\\DOWNLOADS\\SW_NEED_CHANGE_MANAGEMANT\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SWDEV\\01_SRCCODE\\APPLICATION\\LIN\\G5_rls_GEELY2DOT0.h"

#line 70 "C:\\USERS\\ZHU1\\DOWNLOADS\\SW_NEED_CHANGE_MANAGEMANT\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SWDEV\\01_SRCCODE\\APPLICATION\\LIN\\G5_rls_GEELY2DOT0.h"

/******************************************************************************/
/*                    Declaration of exported variables                       */
/******************************************************************************/

extern const canuint8  cabLinRxDLCTbl[];
extern canuint8* const capbLinRxDataPtrTbl[7];
extern const canuint8  cabLinTxDataLenTbl[];
extern canuint8* const capbLinTxDataPtrTbl[7];
extern const canuint8  cabLinRxDataLenTbl[];
extern const canuint8  cabLinRxDLCTbl[];
extern const canuint8  cabLinMsgHandleTbl[14];


extern canuint8             rabRAMLinMsgIDToHandleTbl[0x40];
extern const canuint16 cawLINMessageID[14];




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
  canbittype                    SolarSnsrErr_CEM_LIN1: 1;
  canbittype                                  unused0: 2;
  canbittype RainSnsrDiagcRainSnsrHiVoltDetd_CEM_LIN1: 1;
  canbittype    RainSnsrDiagcRainSnsrHiTDetd_CEM_LIN1: 1;
  canbittype                       LiOprnMod_CEM_LIN1: 2;
  canbittype                    RainDetected_CEM_LIN1: 1;
  canbittype                    RainfallAmnt_CEM_LIN1: 4;
  canbittype                                  unused1: 4;
  canbittype                SolarSnsrLeValue_CEM_LIN1: 8;
  canbittype                SolarSnsrRiValue_CEM_LIN1: 8;
  canbittype                                  unused2: 8;
  canbittype                                  unused3: 8;
  canbittype                                  unused4: 8;
  canbittype                                  unused5: 8;
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
  canbittype                                  unused1: 1;
  canbittype                   RelHumSnsrErr_CEM_LIN1: 1;
  canbittype                                  unused2: 2;
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
  canbittype                     OutdBriCntr_CEM_LIN1: 4;
  canbittype                                  unused4: 2;
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
  canbittype                                  unused0: 8;
  canbittype                                  unused1: 8;
  canbittype                                  unused2: 1;
  canbittype               EnaOfflineMonitor_CEM_LIN1: 1;
  canbittype                                  unused3: 6;
  canbittype                                  unused4: 8;
  canbittype                                  unused5: 8;
  canbittype                                  unused6: 8;
  canbittype                                  unused7: 8;
} _c_CemCem_Lin1Fr05_CEM_LIN1_msgType;

typedef struct {
  canbittype                                  unused0: 8;
  canbittype                                  unused1: 8;
  canbittype                                  unused2: 8;
  canbittype                                  unused3: 8;
  canbittype                                  unused4: 8;
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
  canbittype                                  unused0: 8;
  canbittype                                  unused1: 8;
  canbittype                                  unused2: 8;
  canbittype                                  unused3: 8;
  canbittype                                  unused4: 8;
  canbittype                                  unused5: 8;
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
extern  _c_RlsmCem_SerNrLin1Fr01_CEM_LIN1_buf RlsmCem_SerNrLin1Fr01_CEM_LIN1;
extern  _c_RlsmCem_Lin1PartNrFr02_CEM_LIN1_buf RlsmCem_Lin1PartNrFr02_CEM_LIN1;
extern  _c_RlsmCem_Lin1PartNrFr01_CEM_LIN1_buf RlsmCem_Lin1PartNrFr01_CEM_LIN1;
extern  _c_RlsmCem_Lin1Fr03_CEM_LIN1_buf RlsmCem_Lin1Fr03_CEM_LIN1;
extern  _c_RlsmCem_Lin1Fr02_CEM_LIN1_buf RlsmCem_Lin1Fr02_CEM_LIN1;
extern  _c_RlsmCem_Lin1Fr01_CEM_LIN1_buf RlsmCem_Lin1Fr01_CEM_LIN1;

/******************************************************************************/
/*                        Databuffer for confirmationflags                    */
/******************************************************************************/

#line 411 "C:\\USERS\\ZHU1\\DOWNLOADS\\SW_NEED_CHANGE_MANAGEMANT\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SWDEV\\01_SRCCODE\\APPLICATION\\LIN\\G5_rls_GEELY2DOT0.h"

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

#line 449 "C:\\USERS\\ZHU1\\DOWNLOADS\\SW_NEED_CHANGE_MANAGEMANT\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SWDEV\\01_SRCCODE\\APPLICATION\\LIN\\G5_rls_GEELY2DOT0.h"

/******************************************************************************/
/*                               Definition of signals                        */
/******************************************************************************/

#line 796 "C:\\USERS\\ZHU1\\DOWNLOADS\\SW_NEED_CHANGE_MANAGEMANT\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SWDEV\\01_SRCCODE\\APPLICATION\\LIN\\G5_rls_GEELY2DOT0.h"


#line 149 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_lininclude.h"






/******************************************************************************/
/*                    Declaration of exported variables                       */
/******************************************************************************/







#line 95 "C:/Users/zhu1/Downloads/SW_Need_Change_Managemant/GEEA2.0/E4-2_SW/RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03/05_SwDev/01_SrcCode/Application/CustomerInterface/G5_RLS_LIN_GEELY2DOT0.c"



/*************************************************************************
**                   Other files included                               **
**************************************************************************/
#line 1 "C:\\USERS\\ZHU1\\DOWNLOADS\\SW_NEED_CHANGE_MANAGEMANT\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SWDEV\\01_SRCCODE\\APPLICATION\\PERIPHERALS\\G5_io.h"
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
#line 65 "C:\\USERS\\ZHU1\\DOWNLOADS\\SW_NEED_CHANGE_MANAGEMANT\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SWDEV\\01_SRCCODE\\APPLICATION\\PERIPHERALS\\G5_io.h"


extern   byte rb_SupplyVoltage_mg; //Value of Supply Voltage
extern   byte rb_InternalTemperature_g; //Value of Supply Voltage

#line 77 "C:\\USERS\\ZHU1\\DOWNLOADS\\SW_NEED_CHANGE_MANAGEMANT\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SWDEV\\01_SRCCODE\\APPLICATION\\PERIPHERALS\\G5_io.h"

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


#line 1 "C:\\USERS\\ZHU1\\DOWNLOADS\\SW_NEED_CHANGE_MANAGEMANT\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SWDEV\\01_SRCCODE\\APPLICATION\\PERIPHERALS\\G5_io_sen.h"


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

#line 168 "C:\\USERS\\ZHU1\\DOWNLOADS\\SW_NEED_CHANGE_MANAGEMANT\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SWDEV\\01_SRCCODE\\APPLICATION\\PERIPHERALS\\G5_io_sen.h"

#line 185 "C:\\USERS\\ZHU1\\DOWNLOADS\\SW_NEED_CHANGE_MANAGEMANT\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SWDEV\\01_SRCCODE\\APPLICATION\\PERIPHERALS\\G5_io_sen.h"

#line 202 "C:\\USERS\\ZHU1\\DOWNLOADS\\SW_NEED_CHANGE_MANAGEMANT\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SWDEV\\01_SRCCODE\\APPLICATION\\PERIPHERALS\\G5_io_sen.h"

#line 219 "C:\\USERS\\ZHU1\\DOWNLOADS\\SW_NEED_CHANGE_MANAGEMANT\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SWDEV\\01_SRCCODE\\APPLICATION\\PERIPHERALS\\G5_io_sen.h"

#line 236 "C:\\USERS\\ZHU1\\DOWNLOADS\\SW_NEED_CHANGE_MANAGEMANT\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SWDEV\\01_SRCCODE\\APPLICATION\\PERIPHERALS\\G5_io_sen.h"

#line 253 "C:\\USERS\\ZHU1\\DOWNLOADS\\SW_NEED_CHANGE_MANAGEMANT\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SWDEV\\01_SRCCODE\\APPLICATION\\PERIPHERALS\\G5_io_sen.h"

#line 270 "C:\\USERS\\ZHU1\\DOWNLOADS\\SW_NEED_CHANGE_MANAGEMANT\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SWDEV\\01_SRCCODE\\APPLICATION\\PERIPHERALS\\G5_io_sen.h"

#line 287 "C:\\USERS\\ZHU1\\DOWNLOADS\\SW_NEED_CHANGE_MANAGEMANT\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SWDEV\\01_SRCCODE\\APPLICATION\\PERIPHERALS\\G5_io_sen.h"

#line 304 "C:\\USERS\\ZHU1\\DOWNLOADS\\SW_NEED_CHANGE_MANAGEMANT\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SWDEV\\01_SRCCODE\\APPLICATION\\PERIPHERALS\\G5_io_sen.h"

#line 321 "C:\\USERS\\ZHU1\\DOWNLOADS\\SW_NEED_CHANGE_MANAGEMANT\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SWDEV\\01_SRCCODE\\APPLICATION\\PERIPHERALS\\G5_io_sen.h"

#line 338 "C:\\USERS\\ZHU1\\DOWNLOADS\\SW_NEED_CHANGE_MANAGEMANT\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SWDEV\\01_SRCCODE\\APPLICATION\\PERIPHERALS\\G5_io_sen.h"

#line 355 "C:\\USERS\\ZHU1\\DOWNLOADS\\SW_NEED_CHANGE_MANAGEMANT\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SWDEV\\01_SRCCODE\\APPLICATION\\PERIPHERALS\\G5_io_sen.h"

#line 372 "C:\\USERS\\ZHU1\\DOWNLOADS\\SW_NEED_CHANGE_MANAGEMANT\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SWDEV\\01_SRCCODE\\APPLICATION\\PERIPHERALS\\G5_io_sen.h"

#line 389 "C:\\USERS\\ZHU1\\DOWNLOADS\\SW_NEED_CHANGE_MANAGEMANT\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SWDEV\\01_SRCCODE\\APPLICATION\\PERIPHERALS\\G5_io_sen.h"

#line 406 "C:\\USERS\\ZHU1\\DOWNLOADS\\SW_NEED_CHANGE_MANAGEMANT\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SWDEV\\01_SRCCODE\\APPLICATION\\PERIPHERALS\\G5_io_sen.h"

#line 423 "C:\\USERS\\ZHU1\\DOWNLOADS\\SW_NEED_CHANGE_MANAGEMANT\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SWDEV\\01_SRCCODE\\APPLICATION\\PERIPHERALS\\G5_io_sen.h"



#line 112 "C:\\USERS\\ZHU1\\DOWNLOADS\\SW_NEED_CHANGE_MANAGEMANT\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SWDEV\\01_SRCCODE\\APPLICATION\\PERIPHERALS\\G5_io.h"


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


#line 102 "C:/Users/zhu1/Downloads/SW_Need_Change_Managemant/GEEA2.0/E4-2_SW/RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03/05_SwDev/01_SrcCode/Application/CustomerInterface/G5_RLS_LIN_GEELY2DOT0.c"
#line 1 "C:\\USERS\\ZHU1\\DOWNLOADS\\SW_NEED_CHANGE_MANAGEMANT\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SWDEV\\01_SRCCODE\\APPLICATION\\OS\\G5_Appli_timer.h"



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


#line 103 "C:/Users/zhu1/Downloads/SW_Need_Change_Managemant/GEEA2.0/E4-2_SW/RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03/05_SwDev/01_SrcCode/Application/CustomerInterface/G5_RLS_LIN_GEELY2DOT0.c"
#line 1 "C:\\USERS\\ZHU1\\DOWNLOADS\\SW_NEED_CHANGE_MANAGEMANT\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SWDEV\\01_SRCCODE\\APPLICATION\\DIAGNOSTICS\\G5_Check_sr.h"


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





#line 32 "C:\\USERS\\ZHU1\\DOWNLOADS\\SW_NEED_CHANGE_MANAGEMANT\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SWDEV\\01_SRCCODE\\APPLICATION\\DIAGNOSTICS\\G5_Check_sr.h"




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


#line 104 "C:/Users/zhu1/Downloads/SW_Need_Change_Managemant/GEEA2.0/E4-2_SW/RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03/05_SwDev/01_SrcCode/Application/CustomerInterface/G5_RLS_LIN_GEELY2DOT0.c"
#line 1 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_rainsens.h"


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



#line 54 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_rainsens.h"


/*************************************************************************
**                   Compile options                                    **
**************************************************************************/

/*************************************************************************
**                   Declaration of exported constants                  **
**************************************************************************/
#line 1 "C:\\USERS\\ZHU1\\DOWNLOADS\\SW_NEED_CHANGE_MANAGEMANT\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SWDEV\\01_SRCCODE\\APPLICATION\\RAIN\\G5_rs_lib.h"
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




#line 65 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_rainsens.h"
#line 1 "C:\\USERS\\ZHU1\\DOWNLOADS\\SW_NEED_CHANGE_MANAGEMANT\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SWDEV\\01_SRCCODE\\APPLICATION\\RAIN\\G5_rs_ext.h"



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
#line 173 "C:\\USERS\\ZHU1\\DOWNLOADS\\SW_NEED_CHANGE_MANAGEMANT\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SWDEV\\01_SRCCODE\\APPLICATION\\RAIN\\G5_rs_ext.h"


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




#line 66 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_rainsens.h"


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

#line 88 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_rainsens.h"
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
#line 116 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_rainsens.h"
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
#line 105 "C:/Users/zhu1/Downloads/SW_Need_Change_Managemant/GEEA2.0/E4-2_SW/RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03/05_SwDev/01_SrcCode/Application/CustomerInterface/G5_RLS_LIN_GEELY2DOT0.c"
#line 1 "C:\\USERS\\ZHU1\\DOWNLOADS\\SW_NEED_CHANGE_MANAGEMANT\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SWDEV\\01_SRCCODE\\APPLICATION\\DIAGNOSTICS\\G5_diagnose.h"
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





//#include "G5_E2ProjectConfig.h"








extern unsigned int rw_DiagnoseStepResponseAnswer_g;


extern  volatile Flag uF_LIN_Diagnosis_mg;

#line 54 "C:\\USERS\\ZHU1\\DOWNLOADS\\SW_NEED_CHANGE_MANAGEMANT\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SWDEV\\01_SRCCODE\\APPLICATION\\DIAGNOSTICS\\G5_diagnose.h"



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



#line 125 "C:\\USERS\\ZHU1\\DOWNLOADS\\SW_NEED_CHANGE_MANAGEMANT\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SWDEV\\01_SRCCODE\\APPLICATION\\DIAGNOSTICS\\G5_diagnose.h"


extern void Diagnose_Write_CodierinfoB8(void);


#line 137 "C:\\USERS\\ZHU1\\DOWNLOADS\\SW_NEED_CHANGE_MANAGEMANT\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SWDEV\\01_SRCCODE\\APPLICATION\\DIAGNOSTICS\\G5_diagnose.h"

extern void diagnose_ASICstepResponse(void);

extern void Diagnose_ClearCodingResult(void);

extern byte Diagnosis_BCDtoASCII(byte rb_Input_l);








/*************************************************************************
**                   Defines for Diagnosis                              **
*************************************************************************/














#line 174 "C:\\USERS\\ZHU1\\DOWNLOADS\\SW_NEED_CHANGE_MANAGEMANT\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SWDEV\\01_SRCCODE\\APPLICATION\\DIAGNOSTICS\\G5_diagnose.h"






///////////////////////////////////////////////
/* PRQA S 0841 7 */ /* <<for easier declaration of variable -> proven mechanism>> */
#line 106 "C:/Users/zhu1/Downloads/SW_Need_Change_Managemant/GEEA2.0/E4-2_SW/RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03/05_SwDev/01_SrcCode/Application/CustomerInterface/G5_RLS_LIN_GEELY2DOT0.c"
#line 1 "C:\\USERS\\ZHU1\\DOWNLOADS\\SW_NEED_CHANGE_MANAGEMANT\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SWDEV\\01_SRCCODE\\APPLICATION\\EEPROM\\G5_E2Handler.h"


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

#line 59 "C:\\USERS\\ZHU1\\DOWNLOADS\\SW_NEED_CHANGE_MANAGEMANT\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SWDEV\\01_SRCCODE\\APPLICATION\\EEPROM\\G5_E2Handler.h"

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




#line 107 "C:/Users/zhu1/Downloads/SW_Need_Change_Managemant/GEEA2.0/E4-2_SW/RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03/05_SwDev/01_SrcCode/Application/CustomerInterface/G5_RLS_LIN_GEELY2DOT0.c"
#line 1 "C:\\USERS\\ZHU1\\DOWNLOADS\\SW_NEED_CHANGE_MANAGEMANT\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SWDEV\\01_SRCCODE\\APPLICATION\\EEPROM\\G5_flashe2.h"

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
#line 1 "C:\\USERS\\ZHU1\\DOWNLOADS\\SW_NEED_CHANGE_MANAGEMANT\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SWDEV\\01_SRCCODE\\APPLICATION\\SELFPROGLIBRARY\\pfdl.h"
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
#line 1 "C:\\USERS\\ZHU1\\DOWNLOADS\\SW_NEED_CHANGE_MANAGEMANT\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SWDEV\\01_SRCCODE\\APPLICATION\\SELFPROGLIBRARY\\pfdl_types.h"
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


#line 53 "C:\\USERS\\ZHU1\\DOWNLOADS\\SW_NEED_CHANGE_MANAGEMANT\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SWDEV\\01_SRCCODE\\APPLICATION\\SELFPROGLIBRARY\\pfdl.h"


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



#line 52 "C:\\USERS\\ZHU1\\DOWNLOADS\\SW_NEED_CHANGE_MANAGEMANT\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SWDEV\\01_SRCCODE\\APPLICATION\\EEPROM\\G5_flashe2.h"
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

#line 146 "C:\\USERS\\ZHU1\\DOWNLOADS\\SW_NEED_CHANGE_MANAGEMANT\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SWDEV\\01_SRCCODE\\APPLICATION\\EEPROM\\G5_flashe2.h"

/** \brief Are for which the cluster should be changed*/
extern byte rb_ChangeCluster_mg;






/**
 * \ingroup external
 * \brief Error flags to show emulated EEPROM problems */
/* PRQA S 0759 1*//*<< 0759:union needed to reduce RAM usage >>*/
extern   volatile Flag uF_E2ConfigErrorFlags_g;
#line 168 "C:\\USERS\\ZHU1\\DOWNLOADS\\SW_NEED_CHANGE_MANAGEMANT\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SWDEV\\01_SRCCODE\\APPLICATION\\EEPROM\\G5_flashe2.h"

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

#line 108 "C:/Users/zhu1/Downloads/SW_Need_Change_Managemant/GEEA2.0/E4-2_SW/RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03/05_SwDev/01_SrcCode/Application/CustomerInterface/G5_RLS_LIN_GEELY2DOT0.c"
#line 1 "C:\\USERS\\ZHU1\\DOWNLOADS\\SW_NEED_CHANGE_MANAGEMANT\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SWDEV\\01_SRCCODE\\APPLICATION\\RAIN\\G5_rs_task.h"


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








#line 109 "C:/Users/zhu1/Downloads/SW_Need_Change_Managemant/GEEA2.0/E4-2_SW/RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03/05_SwDev/01_SrcCode/Application/CustomerInterface/G5_RLS_LIN_GEELY2DOT0.c"
#line 1 "C:\\USERS\\ZHU1\\DOWNLOADS\\SW_NEED_CHANGE_MANAGEMANT\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SWDEV\\01_SRCCODE\\APPLICATION\\LIGHT\\G5_IRlight.h"



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

#line 49 "C:\\USERS\\ZHU1\\DOWNLOADS\\SW_NEED_CHANGE_MANAGEMANT\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SWDEV\\01_SRCCODE\\APPLICATION\\LIGHT\\G5_IRlight.h"








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

#line 105 "C:\\USERS\\ZHU1\\DOWNLOADS\\SW_NEED_CHANGE_MANAGEMANT\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SWDEV\\01_SRCCODE\\APPLICATION\\LIGHT\\G5_IRlight.h"
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
#line 195 "C:\\USERS\\ZHU1\\DOWNLOADS\\SW_NEED_CHANGE_MANAGEMANT\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SWDEV\\01_SRCCODE\\APPLICATION\\LIGHT\\G5_IRlight.h"

/* PRQA S 0759 1*//*<< 0759:union needed to reduce RAM usage >>*/
extern  Flag uF_LightInternalStatus_g;

#line 205 "C:\\USERS\\ZHU1\\DOWNLOADS\\SW_NEED_CHANGE_MANAGEMANT\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SWDEV\\01_SRCCODE\\APPLICATION\\LIGHT\\G5_IRlight.h"





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
#line 110 "C:/Users/zhu1/Downloads/SW_Need_Change_Managemant/GEEA2.0/E4-2_SW/RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03/05_SwDev/01_SrcCode/Application/CustomerInterface/G5_RLS_LIN_GEELY2DOT0.c"
#line 1 "C:\\USERS\\ZHU1\\DOWNLOADS\\SW_NEED_CHANGE_MANAGEMANT\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SWDEV\\01_SRCCODE\\APPLICATION\\LIGHT\\G5_DippedBeam_sr.h"


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

#line 111 "C:/Users/zhu1/Downloads/SW_Need_Change_Managemant/GEEA2.0/E4-2_SW/RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03/05_SwDev/01_SrcCode/Application/CustomerInterface/G5_RLS_LIN_GEELY2DOT0.c"
#line 1 "C:\\USERS\\ZHU1\\DOWNLOADS\\SW_NEED_CHANGE_MANAGEMANT\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SWDEV\\01_SRCCODE\\APPLICATION\\PERIPHERALS\\G5_ASIC_Control.h"
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

extern byte rb_RS_SigVoltage_neg_g;
extern byte rb_RS_SigVoltage_abs_g;


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



#line 112 "C:/Users/zhu1/Downloads/SW_Need_Change_Managemant/GEEA2.0/E4-2_SW/RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03/05_SwDev/01_SrcCode/Application/CustomerInterface/G5_RLS_LIN_GEELY2DOT0.c"
#line 1 "C:\\USERS\\ZHU1\\DOWNLOADS\\SW_NEED_CHANGE_MANAGEMANT\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SWDEV\\01_SRCCODE\\APPLICATION\\PERIPHERALS\\G5_ASIC_Control_sr.h"


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









//EXTERN byte Enter_Prestandby_Add_Time;



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

extern byte rb_ASICResetCnt_g;
/*if the rain functionality is enabled*/



extern byte rb_RainMeas_cnt_total_g;
extern byte rb_RainMeas_cnt_min_g;
extern byte rb_RainMeas_cnt_max_g;
extern byte rb_LClosed_dur_total_g;
extern byte rb_LClosed_dur_min_g;
extern byte rb_LClosed_dur_max_g;

extern ASIC_Reg_t ras_ASIC_CtrReg_g[((byte)28)];










extern byte rb_ASIC_ALSx_ShortDetected_Max_cnt_g;
extern byte rb_ASIC_ALSx_ShortDetected_Error_g;

extern byte rb_ASIC_ALS2Amb_ShortDetected_cnt_g;
extern byte rb_ASIC_ALS5FW_ShortDetected_cnt_g;
extern byte rb_ASIC_INRECIR_ShortDetected_cnt_g;
extern byte rb_ASIC_ALS2Amb_ShortDetected_Debounce_g;
extern byte rb_ASIC_ALS5FW_ShortDetected_Debounce_g;
extern byte rb_ASIC_INRECIR_ShortDetected_Debounce_g;


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
#line 247 "C:\\USERS\\ZHU1\\DOWNLOADS\\SW_NEED_CHANGE_MANAGEMANT\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SWDEV\\01_SRCCODE\\APPLICATION\\PERIPHERALS\\G5_ASIC_Control_sr.h"
/*variables to store how is the ASIC frequency measured from the nominal, when not trimmed*/



/*VCO_220 VIrefLo/Hi monitoring*/










/*indexes for the diag AD voltages*/
#line 272 "C:\\USERS\\ZHU1\\DOWNLOADS\\SW_NEED_CHANGE_MANAGEMANT\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SWDEV\\01_SRCCODE\\APPLICATION\\PERIPHERALS\\G5_ASIC_Control_sr.h"

#line 283 "C:\\USERS\\ZHU1\\DOWNLOADS\\SW_NEED_CHANGE_MANAGEMANT\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SWDEV\\01_SRCCODE\\APPLICATION\\PERIPHERALS\\G5_ASIC_Control_sr.h"
/*VDR_839 SM250: Error counter not incrementing properly for calibration values*/
/*#define IDX_CAL_ILO_ICALLO_GHI_INC_AD                  10*/

//#define ASIC_CHD_MODE_CMD(a)  (0xC0|(a<<1))
/* possible mode selection for ASIC*/
#line 296 "C:\\USERS\\ZHU1\\DOWNLOADS\\SW_NEED_CHANGE_MANAGEMANT\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SWDEV\\01_SRCCODE\\APPLICATION\\PERIPHERALS\\G5_ASIC_Control_sr.h"



/*indexes for the ALSx AD voltages*/


/*#define IDX_ALS3_AD        2*/
/*#define IDX_ALS4_AD        3*/





#line 321 "C:\\USERS\\ZHU1\\DOWNLOADS\\SW_NEED_CHANGE_MANAGEMANT\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SWDEV\\01_SRCCODE\\APPLICATION\\PERIPHERALS\\G5_ASIC_Control_sr.h"

/*indexes for the ASIC registers*/








#line 344 "C:\\USERS\\ZHU1\\DOWNLOADS\\SW_NEED_CHANGE_MANAGEMANT\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SWDEV\\01_SRCCODE\\APPLICATION\\PERIPHERALS\\G5_ASIC_Control_sr.h"

















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





/*#define ASIC_ALS4_INC_READY_FLG (byte)(1<<3)*/




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
extern byte rb_ASIC_ALSx_Shortcut_Asked_g;
extern byte rb_ASIC_ALSx_Shortcut_Ready_g;
extern byte rb_ASIC_ALSx_Shortcut_INC_Ready_g;
extern unsigned int rw_REGV_OSAT_cnt_g;

/*! Loop Voltage of sensor for */
extern  byte rb_LoopVoltage_ASIC_g;
/*! ASIC loop in used in Standby function*/
extern byte rb_STB_LoopIn_ASIC_g;

extern unsigned int rw_STB_LoopIn_ASIC_g;
/*************************************************************************
Declaration of exported functions
**************************************************************************/

extern __callt void ASIC_Control_dot5msTask(void); // 0.5ms routine to measure light values

extern void ASIC_Control_init_Caller(void);  /*VDR_436*/
extern unsigned int get_rw_Amb_light16bit_g(void);
extern unsigned int get_rw_FW_light16bit_g(void);
/*Blake_Used_For HUD*/
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








#line 113 "C:/Users/zhu1/Downloads/SW_Need_Change_Managemant/GEEA2.0/E4-2_SW/RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03/05_SwDev/01_SrcCode/Application/CustomerInterface/G5_RLS_LIN_GEELY2DOT0.c"
#line 1 "C:\\USERS\\ZHU1\\DOWNLOADS\\SW_NEED_CHANGE_MANAGEMANT\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SWDEV\\01_SRCCODE\\APPLICATION\\PERIPHERALS\\G5_spi_sr.h"


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


#line 114 "C:/Users/zhu1/Downloads/SW_Need_Change_Managemant/GEEA2.0/E4-2_SW/RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03/05_SwDev/01_SrcCode/Application/CustomerInterface/G5_RLS_LIN_GEELY2DOT0.c"
#line 1 "C:\\USERS\\ZHU1\\DOWNLOADS\\SW_NEED_CHANGE_MANAGEMANT\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SWDEV\\01_SRCCODE\\APPLICATION\\OS\\G5_utilities.h"




extern byte wiperSpeed7to2(unsigned int currentSpeed0to2In,unsigned int speed0to7In, byte hysteresisEdges);

#line 115 "C:/Users/zhu1/Downloads/SW_Need_Change_Managemant/GEEA2.0/E4-2_SW/RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03/05_SwDev/01_SrcCode/Application/CustomerInterface/G5_RLS_LIN_GEELY2DOT0.c"
#line 1 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\G5_AsicFramesLin.h"




extern void CopyRLSDataAsic(void);
extern void ApplTableInitAsic(void);


#line 116 "C:/Users/zhu1/Downloads/SW_Need_Change_Managemant/GEEA2.0/E4-2_SW/RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03/05_SwDev/01_SrcCode/Application/CustomerInterface/G5_RLS_LIN_GEELY2DOT0.c"





/*************************************************************************
**                   Declaration of local module variables              **
*************************************************************************/
#line 153 "C:/Users/zhu1/Downloads/SW_Need_Change_Managemant/GEEA2.0/E4-2_SW/RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03/05_SwDev/01_SrcCode/Application/CustomerInterface/G5_RLS_LIN_GEELY2DOT0.c"
/* PRQA S 0759 1*//*<< 0759:union needed to reduce RAM usage >>*/
static volatile Flag uF_StalkInPos_Flags_g;


/*************************************************************************
**                   Declaration of local module Macros **
*************************************************************************/
#line 167 "C:/Users/zhu1/Downloads/SW_Need_Change_Managemant/GEEA2.0/E4-2_SW/RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03/05_SwDev/01_SrcCode/Application/CustomerInterface/G5_RLS_LIN_GEELY2DOT0.c"


/*************************************************************************
**                   Declaration of local module Functions              **
*************************************************************************/

extern byte rb_RainInt_IntensityOutput_g;
extern unsigned int rb_overWipeCoef;



static void CheckErrors(void);
static void RainFunction(void);
static void LightFunction(void);
static void Humidity_Function(void);
static void StandByMode(void);
static void VoltageDetect(void);
static void OutPutBrightnessValue(void);



static byte rb_Verglasun_ClosedDebounce_mg;
static unsigned int rw_CommandCloseWindowTimout_mg;



static byte rb_AnyErrorCounterDebounce_mg;
static unsigned int rw_AfterRSWipeCounter_mg;                   // Time after last wipe from RS
static unsigned int rw_AfterRSWipeCounterAlt_mg;              //Time to the last wipe from RS
static unsigned int rw_AfterWWSWipeCounter_mg;                  // Time after last wipe from WWS
static  unsigned int rw_WipeCommandTimOut_mg;                    //timout for requested wipe
static  byte rb_Err_State_Light_Sens_mg =0;// light error
static  byte  rb_OutsideTemp_mg  = 0;
static  byte rb_WipeWorkStatus_mg = 1;


/******************For HUD**********************/

static unsigned long HUDEverageValue[2] = {0,0};
static unsigned long rb_storeHUDValueEvery500ms[10]={0,0,0,0,0,0,0,0,0,0};
static void GetFiveTableValue_500ms(unsigned long rl_HUD_Brightness_50ms);
static unsigned long CalcHUDMean_1000ms(void);
static void orderHUDValue(int n);
static void GetFiveTableValue_50ms(unsigned long Fw,unsigned long Amb);
static unsigned long  AdjustOutHudValue(unsigned long rl_CurrentHud);
static byte GetUpdateTimeForLightStatus(void);
static  unsigned long RW_Amb_Fw_Result_End    = 0;
static  byte rb_hud_data_update      = 0;

/********************End***********************/


static void OutPutSolarValue(void);
static void OutPutTwliBriValue(void);
static byte CRC8SAEJ1850(const byte * u8_data,byte u8_len);//crc8saej1850 
static byte GetHudCrcj1850(unsigned long hudSrc);
static byte GetOutdBriStsCrcj1850(byte OutdBriSts);
static void GetLightTransmission(byte trans_550nm,byte trans_880nm);
//static void Get_BCMVehType(byte CarType);
static void Set_BCMLightOffset(byte offset);
static void SendRLSSerNo(void);
static void SendRLSMPartNo(void);
static void SendRLSMPartNo10(void);
static void OutPutHudValue(void);
static void OutPutHudSendCount(void);
static void TemperatureDetect(void);
static void WipeWinterModeCheck(void);
static byte IsByteOddParity(byte data);


static void Rain_sensitivity(void);
static void Get_Lin_Signal_From_GetLeWWS(void);
static void Light_Sensitivity_In_GetLeWWS(void);
static void Wiper_and_Park(void);
static void Tunnel_Wipe_Decision(void);
static void Exit_Wipe(void);
static void Rain_Sensitivity_Judge(void);
static void Standby_Judge(void);
static void OutdBriCntr_Counter(void);
static byte rb_AfterResetCounter_l;
static unsigned int rw_IgnitionOffDelay_mg;
static byte rb_tunnelWipeActive_g;  
static byte rb_RLS_Sensitivity_Array_l[7];
static byte rb_Verglasun_offenDebounce_mg;
static byte Vehicle_Speed_Decision_Flag = 0;


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
  static byte rb_IgnitionOndelay_mg = 0;
  static byte rb_IntervalOnOndelay_mg;

  
  
  
  
  if((uLinIndicationFlags . w[0]. b6 != 0))
  { 
    {uLinIndicationFlags . w[0]. b6 = 0;};
    rw_NoCommunicationCounter_g = 0;                                 // reset no communication counter
    uF_SCIFlags_mg . Bit . B1 = 1;                                     // set connected to Master  
    uF_Communication_mg . Bit . B1 = 1;    
    rb_speed_in_kmh_g = CemCem_Lin1Fr01_CEM_LIN1 . cemcem_lin1fr01_cem_lin1 . VehSpdForWipg_CEM_LIN1;//needsys   

    
    if(rb_speed_in_kmh_g>=10)
    {
      uF_GainAdjustFlags_g . Bit . B1 = 1;
    }   
    else{}

   
    uF_VoltageStatus_g . Bit . B2 = 1;
    rw_IgnitionOffDelay_mg = 0;
    if(rb_IgnitionOndelay_mg < 250)
    {
      rb_IgnitionOndelay_mg++;
    }
    else{}
    
    
    if((((EEPROM_Struct_PD . EEPROMStructPD . EEKodierbyte0_g & 0x40)>0) == 0) &&(rb_AfterResetCounter_l> 10))
    {
      if((CemCem_Lin1Fr01_CEM_LIN1 . cemcem_lin1fr01_cem_lin1 . RainSensActvn_CEM_LIN1 == 1) || (((EEPROM_Struct_PD . EEPROMStructPD . RSControlFlags & 0x40)>0) != 0))
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

    if(CemCem_Lin1Fr01_CEM_LIN1 . cemcem_lin1fr01_cem_lin1 . RainSensActvn_CEM_LIN1 == 1)                            // copy automatic wiping mode
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

    rb_LIN_SensitivityShift_g =  9;                                     //adaptation Variable for sensitivity factor
    if(CemCem_Lin1Fr01_CEM_LIN1 . cemcem_lin1fr01_cem_lin1 . WiprMotIntlCmd_CEM_LIN1 < 7)
    {
      rb_PotiStageFromBox_g = CemCem_Lin1Fr01_CEM_LIN1 . cemcem_lin1fr01_cem_lin1 . WiprMotIntlCmd_CEM_LIN1;
    }
    else if(CemCem_Lin1Fr01_CEM_LIN1 . cemcem_lin1fr01_cem_lin1 . WiprMotIntlCmd_CEM_LIN1 == 7)
    {
      rb_PotiStageFromBox_g = 3;
    }
    else{}
  }  
  else                                                                  //keine neue Master Nachricht!
  {                                                                     // check if system is on -> to switch off 
    if(rw_NoCommunicationCounter_g > ((((EEPROM_Struct_AD . EEPROMStructAD . p_t_autobahn_delay_on_g>>5)&0x07)*100)+200))                               /***4S***/
    {     
      if ((uF_SCIFlags_mg . Bit . B4 == 0)||( uF_ASIC_ControlFlags_g . Bit . B4 == 0))  /*VDR_526*/
      {
        if ((rb_Verglasun_offenDebounce_mg > 100) 
            && (((EEPROM_Struct_PD . EEPROMStructPD . EEKodierbyte0_g & 0x04)>0) == 1) 
            && (uF_SCIFlags_mg . Bit . B4 == 0))
        {
          uF_ASIC_ControlFlags_g . Bit . B4 = 1;                             // Set Request for Standby Mode
          /*******20191112_Zhiyuan HU_Only_for_Winter_Mode********/
          Vehicle_Speed_Decision_Flag = 0;
          /*******************End*******************************/
        }
        else
        {
          uF_ASIC_ControlFlags_g . Bit . B4 = 0;
        }       
        uF_SCIFlags_mg . Bit . B2 = 1;                                         // Was Connected to Master
      }
      else 
      {

        if ((CemCem_Lin1Fr05_CEM_LIN1 . cemcem_lin1fr05_cem_lin1 . EnaOfflineMonitor_CEM_LIN1 == 0) || (rw_CommandCloseWindowTimout_mg > 6000))
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
        rb_Release_IntervalMarker_Update_g = 0x00;
        uF_StatusRainsensor2_mg . Bit . B3 = 1;
      }
    }
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

  Get_Lin_Signal_From_GetLeWWS();
  Standby_Judge();
  Light_Sensitivity_In_GetLeWWS();
  
  
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


  if(((CemCem_Lin1Fr01_CEM_LIN1 . cemcem_lin1fr01_cem_lin1 . RainSensActvn_CEM_LIN1 == 0) && (uF_SCIFlags_mg . Bit . B6 == 1))
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
  
  
  if((uLinConfirmationFlags . w[0]. b6 != 0))
  {
    {uLinConfirmationFlags . w[0]. b6 = 0;} ;
    uF_SCIFlags_mg . Bit . B1 = 1;
    OutdBriCntr_Counter();
  }

  
  if((uLinConfirmationFlags . w[0]. b5 != 0))
  {
    {uLinConfirmationFlags . w[0]. b5 = 0;} ;
    uF_SCIFlags_mg . Bit . B1 = 1;
    OutPutHudSendCount();
  }
  
  
  if((uLinConfirmationFlags . w[0]. b4 != 0))
  {
    {uLinConfirmationFlags . w[0]. b4 = 0;} ;
    uF_SCIFlags_mg . Bit . B1 = 1; 
  }
  
  
  if((uLinConfirmationFlags . w[0]. b3 != 0))
  {
    {uLinConfirmationFlags . w[0]. b3 = 0;} ;
    uF_SCIFlags_mg . Bit . B1 = 1;
    SendRLSMPartNo();
  }
  
  
  if((uLinConfirmationFlags . w[0]. b2 != 0))
  {
    {uLinConfirmationFlags . w[0]. b2 = 0;} ;
    uF_SCIFlags_mg . Bit . B1 = 1; 
    SendRLSMPartNo10();
  }
  
  
  if((uLinConfirmationFlags . w[0]. b1 != 0))
  {
    {uLinConfirmationFlags . w[0]. b1 = 0;} ;
    uF_SCIFlags_mg . Bit . B1 = 1; 
    SendRLSSerNo();
  }


#line 587 "C:/Users/zhu1/Downloads/SW_Need_Change_Managemant/GEEA2.0/E4-2_SW/RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03/05_SwDev/01_SrcCode/Application/CustomerInterface/G5_RLS_LIN_GEELY2DOT0.c"

  

  /* Rain intensity VCO_423: Interval mode defined*/  
  if(uF_StatusRainsensor_mg . Bit . B0 == 1)
  {
    rb_overWipeCoef = EEPROM_Struct_PD . EEPROMStructPD . RS_Intensity_OverWipeCoef;
  }
  else
  {
    rb_overWipeCoef = 100;
  }

  
  
  RainFunction();//Tunnel wiper,auto wiper,rain level, splash mode, rain sonser error
  CheckErrors();//Other error signals send in this function
  VoltageDetect();//Send high/low voltage error
  TemperatureDetect();//send temperate error
  LightFunction();//light request and the reason of light on                            

  StandByMode();//Auto close window

  
  

  OutPutBrightnessValue();//output FW IR SOLAR brightness

  
  

  Humidity_Function();//dew point & Screen temperature & sensor teamperature & relative Humidity

  
  

  CopyRLSDataAsic();


  
  rb_WDG_BusTaskCounter_g++;//increment test counter for bus
}


static void RainFunction(void)
{
  static byte rb_TunnelWipeTimeOut_mg;   
  byte Wiper_speed_l = 0;
  
  
  Wiper_and_Park();
  Tunnel_Wipe_Decision();
    
    
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
    if(uF_StatusRainsensor_mg . Bit . B0 == 1)
    {
      {RlsmCem_Lin1Fr01_CEM_LIN1 . rlsmcem_lin1fr01_cem_lin1 . WipgAutFrntMod_CEM_LIN1 = 1;};
      {RlsmCem_Lin1Fr01_CEM_LIN1 . rlsmcem_lin1fr01_cem_lin1 . AutWinWipgCmd_CEM_LIN1 = 1;};
    }
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
    if(uF_StatusRainsensor_mg . Bit . B0 == 1)
    {
      {RlsmCem_Lin1Fr01_CEM_LIN1 . rlsmcem_lin1fr01_cem_lin1 . WipgAutFrntMod_CEM_LIN1 = 1;};
      {RlsmCem_Lin1Fr01_CEM_LIN1 . rlsmcem_lin1fr01_cem_lin1 . AutWinWipgCmd_CEM_LIN1 = 1;};
    }
  }
  else
  {
    if((uF_StatusRainsensor_mg . Bit . B0 == 1) 
       && (rb_WiperSpeed_g != 0) 
         && (rb_WipeWorkStatus_mg == 1))
    {
      if((RSStatus . Bit . B5 == 0) && (RSStatus . Bit . B6 == 0))
      {
        if(rw_AfterWWSWipeCounter_mg > 500)
        {
          {RlsmCem_Lin1Fr01_CEM_LIN1 . rlsmcem_lin1fr01_cem_lin1 . WipgAutFrntMod_CEM_LIN1 = 1;};
          {RlsmCem_Lin1Fr01_CEM_LIN1 . rlsmcem_lin1fr01_cem_lin1 . AutWinWipgCmd_CEM_LIN1 = 1;};
        }
        else          
        {
          {RlsmCem_Lin1Fr01_CEM_LIN1 . rlsmcem_lin1fr01_cem_lin1 . WipgAutFrntMod_CEM_LIN1 = 2;};
          {RlsmCem_Lin1Fr01_CEM_LIN1 . rlsmcem_lin1fr01_cem_lin1 . AutWinWipgCmd_CEM_LIN1 = 2;};
        }
      }
      else
      {
        {RlsmCem_Lin1Fr01_CEM_LIN1 . rlsmcem_lin1fr01_cem_lin1 . WipgAutFrntMod_CEM_LIN1 = 3;};
        if(rb_WiperSpeed_g == 1)
        {
          Wiper_speed_l = 2;
        }
        else
        {
          Wiper_speed_l = rb_WiperSpeed_g;
        }
        {RlsmCem_Lin1Fr01_CEM_LIN1 . rlsmcem_lin1fr01_cem_lin1 . AutWinWipgCmd_CEM_LIN1 = Wiper_speed_l;};
      }
    }
    else
    {
      Exit_Wipe();
    }  
    
    
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
  
  

  if(RlsmCem_Lin1Fr01_CEM_LIN1 . rlsmcem_lin1fr01_cem_lin1 . RainSnsrErrRainDetnErr_CEM_LIN1 == 1)
  {
    {RlsmCem_Lin1Fr03_CEM_LIN1 . rlsmcem_lin1fr03_cem_lin1 . RainfallAmnt_CEM_LIN1 = 15;};
  }
  else
  {
    {RlsmCem_Lin1Fr03_CEM_LIN1 . rlsmcem_lin1fr03_cem_lin1 . RainfallAmnt_CEM_LIN1 = rb_RainInt_IntensityOutput_g;};
  }

}


static void LightFunction(void)
{
  byte rb_AnyErrorCounterDebounce_l; 
  byte rb_TempLightOn_l = 0;
  byte rb_OpModeState = 0;
  byte rb_crc_StsOutdBriSts = 0;


 /* PRQA S 3415, 4112 1 */ /* << Getter functions must not have side effects >>*/
  if ((((((( (rw_SPINoCommCounter_g > 0) || (get_rb_LightVetoCounter_g() > 0) || (get_rb_LightSignalErrorCnt_g() > 0) || (rb_ASIC_SPI_ErrorCodeCnt_g > 0) || (rb_StaticNoValidAD_cnt_g > 0) || (get_rb_VDD_LightSignalErrorCnt_g() > 0) || (get_rb_LEDx_LStop_error_cnt_g() > 0) || (rb_ClockFreq_Error_cnt_g > 0) || (rb_ASIC_ALS2Amb_ShortDetected_cnt_g > 0) || (rb_ASIC_ALS5FW_ShortDetected_cnt_g > 0) || (rb_ASIC_INRECIR_ShortDetected_cnt_g > 0) || (rb_ASIC_initTimeout_g > 0) || (rb_VIref_ErrCnt_g > 0) )) > 0))||(rb_Err_State_Light_Sens_mg > 0))||(((uF_VoltageStatus_g . Bit . B0) == 1))
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
  
  
  if(rb_Err_State_Light_Sens_mg == 1)
  {
    rb_TempLightOn_l = 3;  
  }
  else if(((uF_modi_lightsens_g.AllBit & 0x2F) > 0) 
          || (uF_Main_Flags_g . Bit . B7 > 0) 
            || ((uF_LightInternalStatus_g . Bit . B6) !=0))
  {
    rb_TempLightOn_l = 1;
  }
  else
  {
    if ((rb_AnyErrorCounterDebounce_l == 0) && ((get_rb_LightVetoCounter_g()) == 0))
    {
      rb_TempLightOn_l = 2;
    }
    else
    {
      rb_TempLightOn_l = RlsmCem_Lin1Fr01_CEM_LIN1 . rlsmcem_lin1fr01_cem_lin1 . OutdBriSts_CEM_LIN1;
    }
  }
  

  if((uF_Main_Flags_g . Bit . B6 == 0)
      && ((EEPROM_Struct_PD . EEPROMStructPD . RSControlFlags == 0x8A ) 
          ||(EEPROM_Struct_PD . EEPROMStructPD . RSControlFlags == 0x98)))
  {
    rb_TempLightOn_l = 1;
    {RlsmCem_Lin1Fr01_CEM_LIN1 . rlsmcem_lin1fr01_cem_lin1 . OutdBriSts_CEM_LIN1 = rb_TempLightOn_l;};   
  } 
  else
  {
    /* PRQA S 434, 436, 781 7 */ /* <<usind Micro Controller specific command > */
    MK2L_bit . no4 = 1U;;
    {RlsmCem_Lin1Fr01_CEM_LIN1 . rlsmcem_lin1fr01_cem_lin1 . OutdBriSts_CEM_LIN1 = rb_TempLightOn_l;};
    MK2L_bit . no4 = 0U;;
  } 
  
  
  if(uF_ASIC_ControlFlags_g . Bit . B1 == 0)
  {
    rb_TempLightOn_l = 0;
    {RlsmCem_Lin1Fr01_CEM_LIN1 . rlsmcem_lin1fr01_cem_lin1 . OutdBriSts_CEM_LIN1 = rb_TempLightOn_l;};
  }
  else{}
  
  
  rb_crc_StsOutdBriSts =  GetOutdBriStsCrcj1850(rb_TempLightOn_l);
  {RlsmCem_Lin1Fr01_CEM_LIN1 . rlsmcem_lin1fr01_cem_lin1 . OutdBriChks_CEM_LIN1 = rb_crc_StsOutdBriSts;};


  if((uF_modi_lightsens_g . Bit . B4 == 1) && (((EEPROM_Struct_PD . EEPROMStructPD . EEKodierbyte0_g & 0x02)>0) == 1))
  {
    {RlsmCem_Lin1Fr01_CEM_LIN1 . rlsmcem_lin1fr01_cem_lin1 . RainLi_CEM_LIN1 = 1;};
  }
  else
  {
    {RlsmCem_Lin1Fr01_CEM_LIN1 . rlsmcem_lin1fr01_cem_lin1 . RainLi_CEM_LIN1 = 0;};
  }


  if((uF_modi_lightsens_g.AllBit & 0x0F) == (byte) 0)
  {
    rb_OpModeState = 1;
  }
  else if(((uF_modi_lightsens_g.AllBit & 0x0F) == (byte) 2) 
          || ((uF_modi_lightsens_g.AllBit & 0x0F) == (byte) 1))
  {
    rb_OpModeState = 0;
  }
  else if((uF_modi_lightsens_g.AllBit & 0x0F) == (byte) 4)
  {
    rb_OpModeState = 3;
  }
  else{}
  {RlsmCem_Lin1Fr03_CEM_LIN1 . rlsmcem_lin1fr03_cem_lin1 . LiOprnMod_CEM_LIN1 = rb_OpModeState;};
}



static void Humidity_Function(void)
{
  //static word rw_Temperature_Sensor_g;
  static unsigned int rw_Temperature_Scheibe_g;
  
  
  if (rbi_HumTempComError_g != 0)
  {
    {RlsmCem_Lin1Fr02_CEM_LIN1 . rlsmcem_lin1fr02_cem_lin1 . RelHumSnsrErr_CEM_LIN1 = 1;};    
    {RlsmCem_Lin1Fr02_CEM_LIN1 . rlsmcem_lin1fr02_cem_lin1 . CmptFrntWindT_CEM_LIN1_0 = (1360 & 0x07); RlsmCem_Lin1Fr02_CEM_LIN1 . rlsmcem_lin1fr02_cem_lin1 . CmptFrntWindT_CEM_LIN1_1 = ((1360 >> 3) & 0xff);};      //window temperature   
    {RlsmCem_Lin1Fr02_CEM_LIN1 . rlsmcem_lin1fr02_cem_lin1 . RelHumSnsrRelHum_CEM_LIN1 = 255;};     // relation hum
    {RlsmCem_Lin1Fr02_CEM_LIN1 . rlsmcem_lin1fr02_cem_lin1 . CmptFrntWindDewT_CEM_LIN1_0 = (2047 & 0xff); RlsmCem_Lin1Fr02_CEM_LIN1 . rlsmcem_lin1fr02_cem_lin1 . CmptFrntWindDewT_CEM_LIN1_1 = ((2047 >> 8) & 0x07);};  //dew point temperature    
  }
  else
  {
    //l_bool_wr_CmptFrntWindTErr_CEM_LIN1(0);
    {RlsmCem_Lin1Fr02_CEM_LIN1 . rlsmcem_lin1fr02_cem_lin1 . RelHumSnsrErr_CEM_LIN1 = 0;};  

    
    if(rw_Temperature_raw_g < 0x2ad)                         // The temperature less than -40 the tool doesnot support 
    {
      rw_Temperature_Scheibe_g = 0x2ad;
    }
    else if(rw_Temperature_raw_g > 0x4321)
    {
      rw_Temperature_Scheibe_g = 0x4321;    
    }
    else
    {
      rw_Temperature_Scheibe_g = rw_Temperature_raw_g;
    }    
      
    
    if(rw_Temperature_raw_g == 0)
    {
      {RlsmCem_Lin1Fr02_CEM_LIN1 . rlsmcem_lin1fr02_cem_lin1 . CmptFrntWindT_CEM_LIN1_0 = (1351 & 0x07); RlsmCem_Lin1Fr02_CEM_LIN1 . rlsmcem_lin1fr02_cem_lin1 . CmptFrntWindT_CEM_LIN1_1 = ((1351 >> 3) & 0xff);};
    }
    else
    {
      if(((rw_Temperature_Scheibe_g -685)/10) < 1650)
      {        
        {RlsmCem_Lin1Fr02_CEM_LIN1 . rlsmcem_lin1fr02_cem_lin1 . CmptFrntWindT_CEM_LIN1_0 = (((rw_Temperature_Scheibe_g -685)/10) & 0x07); RlsmCem_Lin1Fr02_CEM_LIN1 . rlsmcem_lin1fr02_cem_lin1 . CmptFrntWindT_CEM_LIN1_1 = ((((rw_Temperature_Scheibe_g -685)/10) >> 3) & 0xff);};
      }
      else
      {         
        {RlsmCem_Lin1Fr02_CEM_LIN1 . rlsmcem_lin1fr02_cem_lin1 . CmptFrntWindT_CEM_LIN1_0 = (1350 & 0x07); RlsmCem_Lin1Fr02_CEM_LIN1 . rlsmcem_lin1fr02_cem_lin1 . CmptFrntWindT_CEM_LIN1_1 = ((1350 >> 3) & 0xff);};
      }
    } 
  
    
    if (rw_DewPoint_g == 0)
    {
      {RlsmCem_Lin1Fr02_CEM_LIN1 . rlsmcem_lin1fr02_cem_lin1 . CmptFrntWindDewT_CEM_LIN1_0 = (1651 & 0xff); RlsmCem_Lin1Fr02_CEM_LIN1 . rlsmcem_lin1fr02_cem_lin1 . CmptFrntWindDewT_CEM_LIN1_1 = ((1651 >> 8) & 0x07);};
    }    
    else
    {
      if (rw_DewPoint_g < 1650)
      {                                                                       
        {RlsmCem_Lin1Fr02_CEM_LIN1 . rlsmcem_lin1fr02_cem_lin1 . CmptFrntWindDewT_CEM_LIN1_0 = ((rw_DewPoint_g + 4) & 0xff); RlsmCem_Lin1Fr02_CEM_LIN1 . rlsmcem_lin1fr02_cem_lin1 . CmptFrntWindDewT_CEM_LIN1_1 = (((rw_DewPoint_g + 4) >> 8) & 0x07);};        
      }
      else
      {
        {RlsmCem_Lin1Fr02_CEM_LIN1 . rlsmcem_lin1fr02_cem_lin1 . CmptFrntWindDewT_CEM_LIN1_0 = (1650 & 0xff); RlsmCem_Lin1Fr02_CEM_LIN1 . rlsmcem_lin1fr02_cem_lin1 . CmptFrntWindDewT_CEM_LIN1_1 = ((1650 >> 8) & 0x07);};
      }
    }
      
    
    if (rb_Humidity_g == 0)
    {
      {RlsmCem_Lin1Fr02_CEM_LIN1 . rlsmcem_lin1fr02_cem_lin1 . RelHumSnsrRelHum_CEM_LIN1 = 201;};
    }        
    else
    {        
      {RlsmCem_Lin1Fr02_CEM_LIN1 . rlsmcem_lin1fr02_cem_lin1 . RelHumSnsrRelHum_CEM_LIN1 = rb_Humidity_raw_g - 1;};
    }   
  }
}




static void StandByMode(void)
{
  if((rb_Verglasun_ClosedDebounce_mg > 100) 
     ||(CemCem_Lin1Fr05_CEM_LIN1 . cemcem_lin1fr05_cem_lin1 . EnaOfflineMonitor_CEM_LIN1 != 1) 
       || (rw_CommandCloseWindowTimout_mg > 6000))
  {
    uF_SCIFlags_mg . Bit . B4 = 0;
    uF_ASIC_ControlFlags_g . Bit . B4 = 0;
  }
  else{}  
  
  
  if(uF_SCIFlags_mg . Bit . B0 == 1)
  {
    ApplLinInit(0x01);
    uF_SCIFlags_mg . Bit . B0 = 0;                      
  }
  else{}
  
  
  if(uF_SCIFlags_mg . Bit . B4 == 1)
  {
    {RlsmCem_Lin1Fr03_CEM_LIN1 . rlsmcem_lin1fr03_cem_lin1 . RainDetected_CEM_LIN1 = 1;}; 
    if (rw_CommandCloseWindowTimout_mg > 6000)
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



static void VoltageDetect(void)
{
  static byte rb_underVoltageTimer_s;
  
  
  if(uF_VoltageStatus_g . Bit . B0 == 1)
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
  
  
  //if(rbi_UnderVoltage_g == TRUE)
  //{
  //  //l_u8_wr_L_Err_State_Volt(rbi_UnderVoltage_g);    //voltage error statue
  //}
  if(uF_VoltageStatus_g . Bit . B3 == 1)
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
static void TemperatureDetect(void)
{
  static unsigned int rb_overTemperatureTimer_s;
  byte rb_temperateOver_l = 0;
  
  
  if(((rb_InternalTemperature_g > 0) && (rb_InternalTemperature_g < 62)) 
        || ((ras_ASIC_MUX_MeasAD_g[3]. avg > 0) && (ras_ASIC_MUX_MeasAD_g[3]. avg < 367)))
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
  else if(((rb_InternalTemperature_g > 0) && (rb_InternalTemperature_g< 63)) 
          || ((ras_ASIC_MUX_MeasAD_g[3]. avg > 0) && (ras_ASIC_MUX_MeasAD_g[3]. avg < 485))) 
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



static void OutPutHudSendCount(void)
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


static void OutPutHudValue(void)
{
  byte rb_hud_Crc8_l;
  unsigned long rl_hud_Brightness_l;
  unsigned long rl_hud_AMB_Brightness_l;
  unsigned long rl_hud_FW_Brightness_l; 
  unsigned long rl_eeprom_hud_max_l = 0;
  byte rb_hud_High8Bit_l = 0;
  unsigned int rw_hud_Low9Bit_l  = 0;

  
  /*Get the Real Lux for FW and AMB  Illuminance = FW*6 + AMB*15*/
  rl_hud_AMB_Brightness_l = 15*((unsigned long)(get_rw_Amb_light16bit_g()));
  rl_hud_FW_Brightness_l = (unsigned long)((3*((unsigned long)(get_rl_HUD_light32bit_g())))>>1);

  
  /*Pre-Process for original value get average for "rl_HUD_AMB_Brightness" and "rl_HUD_FW_Brightness"*/
  /*100ms average for AMB and FW        1000ms for sum average      */
  GetFiveTableValue_50ms(rl_hud_AMB_Brightness_l,rl_hud_FW_Brightness_l);   
    
  
  /*5000ms for average output*/
  rl_hud_Brightness_l  = CalcHUDMean_1000ms();
      
  
  /*Output to LIN Interface*/
  rl_eeprom_hud_max_l = (unsigned long)((unsigned long)EEPROM_Struct_PD . EEPROMStructPD . HUD_MAX_Resolution * ((unsigned long)EEPROM_Struct_PD . EEPROMStructPD . HUD_MAX_Value));
  if(rl_hud_Brightness_l >= rl_eeprom_hud_max_l)
  {
    rl_hud_Brightness_l = rl_eeprom_hud_max_l;        
  }
  else{}
  
  
  if(rl_hud_Brightness_l > 126000)//currnet send data  length is shorter
  {
    rl_hud_Brightness_l = 126000;
  } 
  else{}

  
  rw_hud_Low9Bit_l = (unsigned int)((rl_hud_Brightness_l&0x1ff));
  rb_hud_High8Bit_l  = (byte)((rl_hud_Brightness_l>>9)&0xFF);

  
  {RlsmCem_Lin1Fr02_CEM_LIN1 . rlsmcem_lin1fr02_cem_lin1 . AmbIllmnFwdStsAmblillmn1_CEM_LIN1_0 = (rw_hud_Low9Bit_l & 0xff); RlsmCem_Lin1Fr02_CEM_LIN1 . rlsmcem_lin1fr02_cem_lin1 . AmbIllmnFwdStsAmblillmn1_CEM_LIN1_1 = ((rw_hud_Low9Bit_l >> 8) & 0x1);};
  {RlsmCem_Lin1Fr02_CEM_LIN1 . rlsmcem_lin1fr02_cem_lin1 . AmbIllmnFwdStsAmblillmn2_CEM_LIN1 = rb_hud_High8Bit_l;};

  
  //check crc 
  rb_hud_Crc8_l = GetHudCrcj1850(rl_hud_Brightness_l);
  {RlsmCem_Lin1Fr02_CEM_LIN1 . rlsmcem_lin1fr02_cem_lin1 . AmbIllmnFwdStsChks_CEM_LIN1 = rb_hud_Crc8_l;};
  /*end hud info relation*/  
}


static void OutPutTwliBriValue(void)
{
  if((get_rw_Amb_light16bit_g() * 20) < 16382)    
  {
    {RlsmCem_Lin1Fr01_CEM_LIN1 . rlsmcem_lin1fr01_cem_lin1 . TwliBriRawTwliBriRaw_CEM_LIN1_0 = ((get_rw_Amb_light16bit_g() * 20) & 0x3F); RlsmCem_Lin1Fr01_CEM_LIN1 . rlsmcem_lin1fr01_cem_lin1 . TwliBriRawTwliBriRaw_CEM_LIN1_1 = (((get_rw_Amb_light16bit_g() * 20) >> 6) & 0xFF);};
  }
  else
  {
    {RlsmCem_Lin1Fr01_CEM_LIN1 . rlsmcem_lin1fr01_cem_lin1 . TwliBriRawTwliBriRaw_CEM_LIN1_0 = (16382 & 0x3F); RlsmCem_Lin1Fr01_CEM_LIN1 . rlsmcem_lin1fr01_cem_lin1 . TwliBriRawTwliBriRaw_CEM_LIN1_1 = ((16382 >> 6) & 0xFF);};
  } 
}


static void OutPutSolarValue(void)
{
  

  unsigned int rw_IrLightforSOSE_Corr1_l;
  unsigned int rw_IrLightforSOSE_Corr2_l;
  unsigned int rw_SoSe_SunInt_2D_Le_l;
  unsigned int rw_SoSe_SunInt_2D_Re_l; 
        
  if (((EEPROM_Struct_PD . EEPROMStructPD . RSControlFlags & 0x02)>0) == 1)
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
  else{}


  if(uF_ASIC_ControlFlags_g . Bit . B2 == 0)
  {
    {RlsmCem_Lin1Fr03_CEM_LIN1 . rlsmcem_lin1fr03_cem_lin1 . SolarSnsrLeValue_CEM_LIN1 = 254;};
    {RlsmCem_Lin1Fr03_CEM_LIN1 . rlsmcem_lin1fr03_cem_lin1 . SolarSnsrRiValue_CEM_LIN1 = 254;};
  }

}


static void OutPutBrightnessValue(void)
{
  static byte rb_InitLightValCnt_l=100;
 
  
  if((uF_ASIC_ControlFlags_g . Bit . B1 == 0)|| (uF_Main_Flags_g . Bit . B6 == 1))
  {
    if(rb_InitLightValCnt_l<100)
    {
      rb_InitLightValCnt_l++;
    }
    else
    { 
      {RlsmCem_Lin1Fr02_CEM_LIN1 . rlsmcem_lin1fr02_cem_lin1 . AmbIllmnFwdStsAmblillmn1_CEM_LIN1_0 = (0 & 0xff); RlsmCem_Lin1Fr02_CEM_LIN1 . rlsmcem_lin1fr02_cem_lin1 . AmbIllmnFwdStsAmblillmn1_CEM_LIN1_1 = ((0 >> 8) & 0x1);};
      {RlsmCem_Lin1Fr02_CEM_LIN1 . rlsmcem_lin1fr02_cem_lin1 . AmbIllmnFwdStsAmblillmn2_CEM_LIN1 = 0;};
			{RlsmCem_Lin1Fr02_CEM_LIN1 . rlsmcem_lin1fr02_cem_lin1 . AmbIllmnFwdStsChks_CEM_LIN1 = 0xF1;};
      {RlsmCem_Lin1Fr01_CEM_LIN1 . rlsmcem_lin1fr01_cem_lin1 . TwliBriRawTwliBriRaw_CEM_LIN1_0 = (0 & 0x3F); RlsmCem_Lin1Fr01_CEM_LIN1 . rlsmcem_lin1fr01_cem_lin1 . TwliBriRawTwliBriRaw_CEM_LIN1_1 = ((0 >> 6) & 0xFF);};
      {RlsmCem_Lin1Fr01_CEM_LIN1 . rlsmcem_lin1fr01_cem_lin1 . TwliBriRawQf_CEM_LIN1 = 1;};
      {RlsmCem_Lin1Fr03_CEM_LIN1 . rlsmcem_lin1fr03_cem_lin1 . SolarSnsrRiValue_CEM_LIN1 = 254;};        // Init 
      {RlsmCem_Lin1Fr03_CEM_LIN1 . rlsmcem_lin1fr03_cem_lin1 . SolarSnsrLeValue_CEM_LIN1 = 254;};         // Init
    }
  }
  else
  {
    rb_InitLightValCnt_l=0;
#line 1253 "C:/Users/zhu1/Downloads/SW_Need_Change_Managemant/GEEA2.0/E4-2_SW/RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03/05_SwDev/01_SrcCode/Application/CustomerInterface/G5_RLS_LIN_GEELY2DOT0.c"
    if(rb_Err_State_Light_Sens_mg == 1)                    /*  VDR469   set for error*/
    {
      {RlsmCem_Lin1Fr02_CEM_LIN1 . rlsmcem_lin1fr02_cem_lin1 . AmbIllmnFwdStsAmblillmn1_CEM_LIN1_0 = (0x1FF & 0xff); RlsmCem_Lin1Fr02_CEM_LIN1 . rlsmcem_lin1fr02_cem_lin1 . AmbIllmnFwdStsAmblillmn1_CEM_LIN1_1 = ((0x1FF >> 8) & 0x1);};
      {RlsmCem_Lin1Fr02_CEM_LIN1 . rlsmcem_lin1fr02_cem_lin1 . AmbIllmnFwdStsAmblillmn2_CEM_LIN1 = 0xFF;};
      {RlsmCem_Lin1Fr02_CEM_LIN1 . rlsmcem_lin1fr02_cem_lin1 . AmbIllmnFwdStsChks_CEM_LIN1 = 0xA3;};
      {RlsmCem_Lin1Fr01_CEM_LIN1 . rlsmcem_lin1fr01_cem_lin1 . TwliBriRawTwliBriRaw_CEM_LIN1_0 = (16383 & 0x3F); RlsmCem_Lin1Fr01_CEM_LIN1 . rlsmcem_lin1fr01_cem_lin1 . TwliBriRawTwliBriRaw_CEM_LIN1_1 = ((16383 >> 6) & 0xFF);};
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
  (uF_Diagnose_pre_Flag . Bit . B3) = 0;
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
  

  {RlsmCem_Lin1Fr01_CEM_LIN1 . rlsmcem_lin1fr01_cem_lin1 . RainSnsrErrRainDetnErrActv_CEM_LIN1 = 1;};  
  


  //15:RLFS 7:RLS
  if((EEPROM_Struct_PD . EEPROMStructPD . RSControlFlags == 15) || (EEPROM_Struct_PD . EEPROMStructPD . RSControlFlags == 7))
  {
    /* VCO132: SM210 - ASIC Frequency Check (done at startup) - LS,RS_Failure */
    /* VCO 140: SM150 - ADC test */
    /* setze Lichtsensor RS-Fehler nach SRS */
    /*SM240*/
    {RlsmCem_Lin1Fr01_CEM_LIN1 . rlsmcem_lin1fr01_cem_lin1 . RainSnsrErrRainDetnErr_CEM_LIN1 = (rb_RS_LS_Error1_g != 0) || (rb_RS_LS_Error2_g != 0) || (rb_RainS_Error1_g != 0) || (uF_E2ConfigErrorFlags_g . Bit . B6 != 0);};



  }




  
  
  if(((rb_RS_LS_Error1_g != 0) 
      || (rb_RS_LS_Error2_g != 0) 
        || (rb_LightS_Error1_g != 0) 
          || (uF_E2ConfigErrorFlags_g . Bit . B6 != 0) 
            || (uF_LIN_DiagReq2_mg . Bit . B1)))
  {
    rb_Err_State_Light_Sens_mg = 1;
    {RlsmCem_Lin1Fr01_CEM_LIN1 . rlsmcem_lin1fr01_cem_lin1 . TwliBriRawQf_CEM_LIN1 = 0;};
    {RlsmCem_Lin1Fr03_CEM_LIN1 . rlsmcem_lin1fr03_cem_lin1 . SolarSnsrErr_CEM_LIN1 = 1;};
    {RlsmCem_Lin1Fr01_CEM_LIN1 . rlsmcem_lin1fr01_cem_lin1 . HudSnsrErrSnsrErr_CEM_LIN1 = 1;};
  }
  else
  {
    rb_Err_State_Light_Sens_mg = 0;
    {RlsmCem_Lin1Fr01_CEM_LIN1 . rlsmcem_lin1fr01_cem_lin1 . TwliBriRawQf_CEM_LIN1 = 3;};
    {RlsmCem_Lin1Fr03_CEM_LIN1 . rlsmcem_lin1fr03_cem_lin1 . SolarSnsrErr_CEM_LIN1 = 0;};
    {RlsmCem_Lin1Fr01_CEM_LIN1 . rlsmcem_lin1fr01_cem_lin1 . HudSnsrErrSnsrErr_CEM_LIN1 = 0;};
  }
  
  
  rb_hud_errorParity_l = IsByteOddParity(RlsmCem_Lin1Fr01_CEM_LIN1 . rlsmcem_lin1fr01_cem_lin1 . HudSnsrErrSnsrErr_CEM_LIN1);
  {RlsmCem_Lin1Fr01_CEM_LIN1 . rlsmcem_lin1fr01_cem_lin1 . HudSnsrErrParChk_CEM_LIN1 = rb_hud_errorParity_l;};
}

void ApplLinInit(byte rb_LIN_State_l)
{
  byte rb_Index_l; 
   
  
  static const byte LinMsgDefault_RlsmCem_SerNrLin1Fr01_CEM_LIN1[4] = {0,0,0,0};/*0x22*/
  static const byte LinMsgDefault_RlsmCem_Lin1PartNrFr02_CEM_LIN1[8] = {0,0,0,0,0,0,0,0};/*0x18*/
  static const byte LinMsgDefault_RlsmCem_Lin1PartNrFr01_CEM_LIN1[7] = {0,0,0,0,0,0,0};/*0x20*/
  static const byte LinMsgDefault_RlsmCem_Lin1Fr03_CEM_LIN1[8] = {0,14,50,50,0,0,0,0};/*0x02*/
  static const byte LinMsgDefault_RlsmCem_Lin1Fr02_CEM_LIN1[8] = {88,2,0,0,0,0,75,80};/*0x2C*/
  static const byte LinMsgDefault_RlsmCem_Lin1Fr01_CEM_LIN1[8] = {0,0,0,1,0,0,0,0};/*0x15*/

  
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
  rw_AfterWWSWipeCounter_mg = 50000;//Direktbitdelay bei Kl15 Aus hochsetzen!
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
  else{}
}


/*HUD Algrithm shenzhen-team 2018-05-05*/

static void GetFiveTableValue_500ms(unsigned long rl_HUD_Brightness_50ms)
{
  static byte rb_k_cycleIn50ms=0;
  static byte rb_k_cycleIn500ms=0;
  
  
  rb_storeHUDValueEvery500ms[rb_k_cycleIn50ms] = rl_HUD_Brightness_50ms;
    
  
  rb_k_cycleIn50ms++;
  if(rb_k_cycleIn50ms >= 10)
  {
    rb_k_cycleIn50ms = 0;
    orderHUDValue(10);
    HUDEverageValue[rb_k_cycleIn500ms] = ((rb_storeHUDValueEvery500ms[3] 
                                           + rb_storeHUDValueEvery500ms[4] 
                                             + rb_storeHUDValueEvery500ms[5] 
                                               + rb_storeHUDValueEvery500ms[6] 
                                                 + rb_storeHUDValueEvery500ms[7]) 
                                                   / 5);
    rb_k_cycleIn500ms++;
    if(rb_k_cycleIn500ms >= 2)
    {
      rb_k_cycleIn500ms=0;  
      rb_hud_data_update = 1;
    }    
  }
}


static unsigned long AdjustOutHudValue(unsigned long rl_CurrentHud)
{
  unsigned int currLevel = 0;
  unsigned int rw_LastCurrDiff = 0;
  unsigned long  rl_adjustAfterHud = 0;

  
  if(rl_CurrentHud >= 100)
  {
    return rl_CurrentHud;
  }
  else{}
  
  
  currLevel = RW_Amb_Fw_Result_End / 10;  
  if(rl_CurrentHud >= RW_Amb_Fw_Result_End)
  {
    rw_LastCurrDiff = rl_CurrentHud - RW_Amb_Fw_Result_End;
  }
  else
  {
    rw_LastCurrDiff = RW_Amb_Fw_Result_End - rl_CurrentHud;
  }
  if(rw_LastCurrDiff <= 15)
  {
    return  rl_CurrentHud;
  }
  else{}
  

  if(rl_CurrentHud >= RW_Amb_Fw_Result_End)
  {
    currLevel = currLevel + (rw_LastCurrDiff / 15);
    rw_LastCurrDiff = rw_LastCurrDiff % 3;
    if(currLevel > 9)
    {
      rl_adjustAfterHud = 92 + (unsigned long)rw_LastCurrDiff;
    }
    else
    {
      rl_adjustAfterHud = 5 + (currLevel * 10) + (unsigned long)rw_LastCurrDiff;
    }
  }
  else
  {
    if(currLevel >= (rw_LastCurrDiff / 15))
    {
      currLevel = currLevel - (rw_LastCurrDiff / 15);
      rw_LastCurrDiff = rw_LastCurrDiff % 3;
      if(currLevel > 9)
      {
        rl_adjustAfterHud = 92 - (unsigned long)rw_LastCurrDiff;
      }
      else
      {
        rl_adjustAfterHud = ((5 + (currLevel * 10)) - (unsigned long)rw_LastCurrDiff);
      }
    }
    else
    {
      rw_LastCurrDiff = rw_LastCurrDiff % 3;
      rl_adjustAfterHud = 5 - (unsigned long)rw_LastCurrDiff;
    }
  }
  
  
  return  rl_adjustAfterHud;    
}


static byte GetUpdateTimeForLightStatus(void)
{
  unsigned char  hud_refresh_time = 1;  
  //1 in tunnel and day for 1s  get data;in night and darkstart for 3s  get data 
  //2 if in tunnel and speed less 10,then 3s will upate
  if(((uF_LightInternalStatus_g . Bit . B0) == 1) && (uF_Main_Flags_g . Bit . B6 == 0))
  {
    if((uF_modi_lightsens_g.AllBit & (byte) 2) > 0)
    {
      hud_refresh_time = 3;
    }
    else if ((uF_modi_lightsens_g.AllBit & (byte) 4) > 0)
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
    else if ((uF_modi_lightsens_g.AllBit & (byte) 1) > 0)
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


static unsigned long CalcHUDMean_1000ms(void)
{  
  static  unsigned char RW_Update_Time_Count = 0;
  unsigned long  rl_current_hud_lux = 0;
  unsigned char  rb_hud_refresh_time = 1;
      
  if(rb_hud_data_update == 1)
  {
    rb_hud_data_update = 0;
    
    
    rb_hud_refresh_time = GetUpdateTimeForLightStatus();
    if(RW_Update_Time_Count < rb_hud_refresh_time)
    {
      RW_Update_Time_Count++;  
    }
    else{}
     
    
    //internal data updata time is 1s
    //Data send to BCM is decided for  RW_Update_Time_Count and rb_hud_refresh_time
    //if rl_current_hud_lux and RW_Amb_Fw_Result_End  are less than 100, we will get average value
    rl_current_hud_lux = (HUDEverageValue[0] + HUDEverageValue[1])/2; 
    if((rl_current_hud_lux < 100) && (RW_Amb_Fw_Result_End < 100))
    {        
      rl_current_hud_lux = (RW_Amb_Fw_Result_End +rl_current_hud_lux)/2;
    }  
      
    if(rb_hud_refresh_time <= RW_Update_Time_Count)//refresh time is reached
    {   
      RW_Update_Time_Count = 0;        
      RW_Amb_Fw_Result_End = AdjustOutHudValue(rl_current_hud_lux);         
    }
    else{}    
  }  
  return RW_Amb_Fw_Result_End;
}


/*****Bubble Sort**********/
static void orderHUDValue(int n)
{
  unsigned long rb_temp_l = 0;
  int i =0;
  int j = 0;
  
  for(i = 0;i < n;i++)
  {
    for(j = 1;j < (n-i);j++)
    {    
      if(rb_storeHUDValueEvery500ms[j-1] > rb_storeHUDValueEvery500ms[j])
      {
        rb_temp_l = rb_storeHUDValueEvery500ms[j];
        rb_storeHUDValueEvery500ms[j] = rb_storeHUDValueEvery500ms[j-1];
        rb_storeHUDValueEvery500ms[j-1] = rb_temp_l ;
      }
      else{}
    }
  }
}


static void GetFiveTableValue_50ms(unsigned long Fw,unsigned long Amb)
{
  static unsigned long FW_Average_In_50ms = 0;
  static unsigned long AMB_Average_In_50ms = 0;
  static unsigned long FW_Average_In_50ms_Old = 0;
  static unsigned long AMB_Average_In_50ms_Old = 0;
  static unsigned long rb_storeFW_ValueEvery50ms[10]={0,0,0,0,0,0,0,0,0,0};
  static unsigned long rb_storeAMB_ValueEvery50ms[10]={0,0,0,0,0,0,0,0,0,0};
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


static byte CRC8SAEJ1850(const byte * u8_data,byte u8_len)
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
      if ((u8_crc8 & 0x80) > 0)
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


static byte GetOutdBriStsCrcj1850(byte OutdBriSts)
{  
  byte buffer[1];
  buffer[0] = OutdBriSts;
  //TestCrcJ1850Info();
  return CRC8SAEJ1850(buffer,1);  
}

static byte GetHudCrcj1850(unsigned long hudSrc)
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


static void GetLightTransmission(byte trans_550nm,byte trans_880nm)
{
  byte rb_880nm_Transmission_local_Coding = 0;
  byte rb_550nm_Transmission_local_Coding = 0;
  //byte rb_550nm_Transmission_local_Coding_outOfRangeFlag = 0;
  //byte rb_880nm_Transmission_local_Coding_outOfRangeFlag = 0;
  {RlsmCem_Lin1Fr01_CEM_LIN1 . rlsmcem_lin1fr01_cem_lin1 . RainSnsrErrCalErr_CEM_LIN1 = 0;};
  
  
  if(((trans_550nm >= 15) && (trans_550nm <= 90)) && ((trans_880nm >= 15) && (trans_880nm <= 90)))
  {
    rb_550nm_Transmission_local_Coding = ((trans_550nm - 15 ) + 2) / 5;
    rb_880nm_Transmission_local_Coding = ((trans_880nm - 15 ) + 2) / 5;

    if((EEPROM_Struct_PD . EEPROMStructPD . EEKodierbyte2_g != ((rb_880nm_Transmission_local_Coding << 4) | rb_550nm_Transmission_local_Coding)) 
       && ((uF_Main_Flags_g . Bit . B2 == 0)||(uF_Main_Flags_g . Bit . B1 == 1)))
    {
      rab_EEPROM_Bytes_toWrite_g[0] = ((rb_880nm_Transmission_local_Coding << 4) | rb_550nm_Transmission_local_Coding);
      rw_EEPROM_Address_to_Write_g = (268); /*set adress to write*/
      rb_I2C_EEPROM_bytesToWrite_g = 1;         /*set number of bytes to 1*/
      uF_Main_Flags_g . Bit . B2 = 1;
      uF_Main_Flags_g . Bit . B1 = 0;
    }
  }
}

#line 1803 "C:/Users/zhu1/Downloads/SW_Need_Change_Managemant/GEEA2.0/E4-2_SW/RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03/05_SwDev/01_SrcCode/Application/CustomerInterface/G5_RLS_LIN_GEELY2DOT0.c"

static void Set_BCMLightOffset(byte offset)
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
  
  
  if((offset < 8) 
     && (rb_OldSensorLs != offset) 
       && ((uF_Main_Flags_g . Bit . B2 == 0)||(uF_Main_Flags_g . Bit . B1 == 1)))
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


static void SendRLSSerNo(void)
{
  unsigned long d = 0;
  byte a,b,c,e,f,g,h;

  a = ((EEPROM_Struct_PD . EEPROMStructPD . Produktionsdaten[(0)]));
  b = a / 16;
  c = a % 16;
  d = (b * 10000000) + (c * 1000000);


  a = ((EEPROM_Struct_PD . EEPROMStructPD . Produktionsdaten[(1)]));
  b = a / 16;
  c = a % 16;
  d = (b * 100000) + (c * 10000) + d;


  a = ((EEPROM_Struct_PD . EEPROMStructPD . Produktionsdaten[(2)]));
  b = a / 16;
  c = a % 16;
  d = (b * 1000) + (c * 100) + d;


  a = ((EEPROM_Struct_PD . EEPROMStructPD . Produktionsdaten[(3)]));
  b = a / 16;
  c = a % 16;
  d = (b * 10) + (c * 1) + d;


  e = (d >> 0) & 0xff;
  f = (d >> 8) & 0xff;
  g = (d >> 16) & 0xff;
  h = (d >> 24) & 0xff;


  {RlsmCem_SerNrLin1Fr01_CEM_LIN1 . rlsmcem_sernrlin1fr01_cem_lin1 . RLSMSerNoNr1_CEM_LIN1 = h;};
  {RlsmCem_SerNrLin1Fr01_CEM_LIN1 . rlsmcem_sernrlin1fr01_cem_lin1 . RLSMSerNoNr2_CEM_LIN1 = g;};
  {RlsmCem_SerNrLin1Fr01_CEM_LIN1 . rlsmcem_sernrlin1fr01_cem_lin1 . RLSMSerNoNr3_CEM_LIN1 = f;};
  {RlsmCem_SerNrLin1Fr01_CEM_LIN1 . rlsmcem_sernrlin1fr01_cem_lin1 . RLSMSerNoNr4_CEM_LIN1 = e;};
}


static void SendRLSMPartNo(void)
{
#line 1897 "C:/Users/zhu1/Downloads/SW_Need_Change_Managemant/GEEA2.0/E4-2_SW/RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03/05_SwDev/01_SrcCode/Application/CustomerInterface/G5_RLS_LIN_GEELY2DOT0.c"

    
  {RlsmCem_Lin1PartNrFr01_CEM_LIN1 . rlsmcem_lin1partnrfr01_cem_lin1 . RLSMPartNoNr1_CEM_LIN1 = 0;};
  {RlsmCem_Lin1PartNrFr01_CEM_LIN1 . rlsmcem_lin1partnrfr01_cem_lin1 . RLSMPartNoNr2_CEM_LIN1 = 0;};
  {RlsmCem_Lin1PartNrFr01_CEM_LIN1 . rlsmcem_lin1partnrfr01_cem_lin1 . RLSMPartNoNr3_CEM_LIN1 = 0;};
  {RlsmCem_Lin1PartNrFr01_CEM_LIN1 . rlsmcem_lin1partnrfr01_cem_lin1 . RLSMPartNoNr4_CEM_LIN1 = 0;};
  {RlsmCem_Lin1PartNrFr01_CEM_LIN1 . rlsmcem_lin1partnrfr01_cem_lin1 . RLSMPartNoEndSgn1_CEM_LIN1 = 0x20;};
  {RlsmCem_Lin1PartNrFr01_CEM_LIN1 . rlsmcem_lin1partnrfr01_cem_lin1 . RLSMPartNoEndSgn2_CEM_LIN1 = 0x20;};
  {RlsmCem_Lin1PartNrFr01_CEM_LIN1 . rlsmcem_lin1partnrfr01_cem_lin1 . RLSMPartNoEndSgn3_CEM_LIN1 = 0x20;};
}


static void SendRLSMPartNo10(void)
{
  if(EEPROM_Struct_PD . EEPROMStructPD . RSControlFlags == 15)
  {
    //15:RLFS
    {RlsmCem_Lin1PartNrFr02_CEM_LIN1 . rlsmcem_lin1partnrfr02_cem_lin1 . RLSMPartNo10Nr1_CEM_LIN1 = 0x88;};
    {RlsmCem_Lin1PartNrFr02_CEM_LIN1 . rlsmcem_lin1partnrfr02_cem_lin1 . RLSMPartNo10Nr2_CEM_LIN1 = 0x89;};
    {RlsmCem_Lin1PartNrFr02_CEM_LIN1 . rlsmcem_lin1partnrfr02_cem_lin1 . RLSMPartNo10Nr3_CEM_LIN1 = 0x07;};
    {RlsmCem_Lin1PartNrFr02_CEM_LIN1 . rlsmcem_lin1partnrfr02_cem_lin1 . RLSMPartNo10Nr4_CEM_LIN1 = 0x24;};
    {RlsmCem_Lin1PartNrFr02_CEM_LIN1 . rlsmcem_lin1partnrfr02_cem_lin1 . RLSMPartNo10Nr5_CEM_LIN1 = 0x28;};
    {RlsmCem_Lin1PartNrFr02_CEM_LIN1 . rlsmcem_lin1partnrfr02_cem_lin1 . RLSMPartNo10EndSgn1_CEM_LIN1 = 0x20;};
    {RlsmCem_Lin1PartNrFr02_CEM_LIN1 . rlsmcem_lin1partnrfr02_cem_lin1 . RLSMPartNo10EndSgn2_CEM_LIN1 = 0x20;};
    {RlsmCem_Lin1PartNrFr02_CEM_LIN1 . rlsmcem_lin1partnrfr02_cem_lin1 . RLSMPartNo10EndSgn3_CEM_LIN1 = 0x46;};
  }
  else if(EEPROM_Struct_PD . EEPROMStructPD . RSControlFlags == 7)
  {
    //7:RLS
    {RlsmCem_Lin1PartNrFr02_CEM_LIN1 . rlsmcem_lin1partnrfr02_cem_lin1 . RLSMPartNo10Nr1_CEM_LIN1 = 0x88;};
    {RlsmCem_Lin1PartNrFr02_CEM_LIN1 . rlsmcem_lin1partnrfr02_cem_lin1 . RLSMPartNo10Nr2_CEM_LIN1 = 0x88;};
    {RlsmCem_Lin1PartNrFr02_CEM_LIN1 . rlsmcem_lin1partnrfr02_cem_lin1 . RLSMPartNo10Nr3_CEM_LIN1 = 0x99;};
    {RlsmCem_Lin1PartNrFr02_CEM_LIN1 . rlsmcem_lin1partnrfr02_cem_lin1 . RLSMPartNo10Nr4_CEM_LIN1 = 0x81;};
    {RlsmCem_Lin1PartNrFr02_CEM_LIN1 . rlsmcem_lin1partnrfr02_cem_lin1 . RLSMPartNo10Nr5_CEM_LIN1 = 0x20;};
    {RlsmCem_Lin1PartNrFr02_CEM_LIN1 . rlsmcem_lin1partnrfr02_cem_lin1 . RLSMPartNo10EndSgn1_CEM_LIN1 = 0x20;};
    {RlsmCem_Lin1PartNrFr02_CEM_LIN1 . rlsmcem_lin1partnrfr02_cem_lin1 . RLSMPartNo10EndSgn2_CEM_LIN1 = 0x20;};
    {RlsmCem_Lin1PartNrFr02_CEM_LIN1 . rlsmcem_lin1partnrfr02_cem_lin1 . RLSMPartNo10EndSgn3_CEM_LIN1 = 66;};
  }
  else if(EEPROM_Struct_PD . EEPROMStructPD . RSControlFlags == 14)
  {
    //14:LFS
    {RlsmCem_Lin1PartNrFr02_CEM_LIN1 . rlsmcem_lin1partnrfr02_cem_lin1 . RLSMPartNo10Nr1_CEM_LIN1 = 0x88;};
    {RlsmCem_Lin1PartNrFr02_CEM_LIN1 . rlsmcem_lin1partnrfr02_cem_lin1 . RLSMPartNo10Nr2_CEM_LIN1 = 0x88;};
    {RlsmCem_Lin1PartNrFr02_CEM_LIN1 . rlsmcem_lin1partnrfr02_cem_lin1 . RLSMPartNo10Nr3_CEM_LIN1 = 0x99;};
    {RlsmCem_Lin1PartNrFr02_CEM_LIN1 . rlsmcem_lin1partnrfr02_cem_lin1 . RLSMPartNo10Nr4_CEM_LIN1 = 0x81;};
    {RlsmCem_Lin1PartNrFr02_CEM_LIN1 . rlsmcem_lin1partnrfr02_cem_lin1 . RLSMPartNo10Nr5_CEM_LIN1 = 0x23;};
    {RlsmCem_Lin1PartNrFr02_CEM_LIN1 . rlsmcem_lin1partnrfr02_cem_lin1 . RLSMPartNo10EndSgn1_CEM_LIN1 = 0x20;};
    {RlsmCem_Lin1PartNrFr02_CEM_LIN1 . rlsmcem_lin1partnrfr02_cem_lin1 . RLSMPartNo10EndSgn2_CEM_LIN1 = 0x20;};
    {RlsmCem_Lin1PartNrFr02_CEM_LIN1 . rlsmcem_lin1partnrfr02_cem_lin1 . RLSMPartNo10EndSgn3_CEM_LIN1 = 66;};
  }
  else if(EEPROM_Struct_PD . EEPROMStructPD . RSControlFlags == 6)
  {
    //6:LS
    {RlsmCem_Lin1PartNrFr02_CEM_LIN1 . rlsmcem_lin1partnrfr02_cem_lin1 . RLSMPartNo10Nr1_CEM_LIN1 = 0x88;};
    {RlsmCem_Lin1PartNrFr02_CEM_LIN1 . rlsmcem_lin1partnrfr02_cem_lin1 . RLSMPartNo10Nr2_CEM_LIN1 = 0x88;};
    {RlsmCem_Lin1PartNrFr02_CEM_LIN1 . rlsmcem_lin1partnrfr02_cem_lin1 . RLSMPartNo10Nr3_CEM_LIN1 = 0x99;};
    {RlsmCem_Lin1PartNrFr02_CEM_LIN1 . rlsmcem_lin1partnrfr02_cem_lin1 . RLSMPartNo10Nr4_CEM_LIN1 = 0x81;};
    {RlsmCem_Lin1PartNrFr02_CEM_LIN1 . rlsmcem_lin1partnrfr02_cem_lin1 . RLSMPartNo10Nr5_CEM_LIN1 = 0x13;};
    {RlsmCem_Lin1PartNrFr02_CEM_LIN1 . rlsmcem_lin1partnrfr02_cem_lin1 . RLSMPartNo10EndSgn1_CEM_LIN1 = 0x20;};
    {RlsmCem_Lin1PartNrFr02_CEM_LIN1 . rlsmcem_lin1partnrfr02_cem_lin1 . RLSMPartNo10EndSgn2_CEM_LIN1 = 0x20;};
    {RlsmCem_Lin1PartNrFr02_CEM_LIN1 . rlsmcem_lin1partnrfr02_cem_lin1 . RLSMPartNo10EndSgn3_CEM_LIN1 = 66;};
  }
  else{}
}


/*T < 0 degree and Speed is under 5KM/H.*/
static void WipeWinterModeCheck(void)
{  
  if(rb_speed_in_kmh_g > 5)
  {
    Vehicle_Speed_Decision_Flag = 1;
  }


  if((Vehicle_Speed_Decision_Flag == 0) && (rb_OutsideTemp_mg < 80))
  {
    rb_WipeWorkStatus_mg = 2;
  }
  else
  {
    rb_WipeWorkStatus_mg = 1;
  } 
}


static byte IsByteOddParity(byte data)
{
  byte parity = 0;

  
  while (data != 0)
  {
    parity = !parity;
    data = 0;
  }
  return (!parity);
}


static void Rain_sensitivity(void)
{ 
  if(CemCem_Lin1Fr03_CEM_LIN1 . cemcem_lin1fr03_cem_lin1 . RainSnsrSnvtyForUsrSnvty0_CEM_LIN1 == 0)
  {
    rb_RLS_Sensitivity_Array_l[0] = 1;
  }
  else
  {
    rb_RLS_Sensitivity_Array_l[0] = CemCem_Lin1Fr03_CEM_LIN1 . cemcem_lin1fr03_cem_lin1 . RainSnsrSnvtyForUsrSnvty0_CEM_LIN1*2;
  }


  if(CemCem_Lin1Fr03_CEM_LIN1 . cemcem_lin1fr03_cem_lin1 . RainSnsrSnvtyForUsrSnvty1_CEM_LIN1 == 0)
  {
    rb_RLS_Sensitivity_Array_l[1] = 1;
  }
  else
  {
    rb_RLS_Sensitivity_Array_l[1] = CemCem_Lin1Fr03_CEM_LIN1 . cemcem_lin1fr03_cem_lin1 . RainSnsrSnvtyForUsrSnvty1_CEM_LIN1*2; 
  }


  if(CemCem_Lin1Fr03_CEM_LIN1 . cemcem_lin1fr03_cem_lin1 . RainSnsrSnvtyForUsrSnvty2_CEM_LIN1 == 0)
  {
    rb_RLS_Sensitivity_Array_l[2] = 1;
  }
  else
  {
    rb_RLS_Sensitivity_Array_l[2] = CemCem_Lin1Fr03_CEM_LIN1 . cemcem_lin1fr03_cem_lin1 . RainSnsrSnvtyForUsrSnvty2_CEM_LIN1*2;
  }


  if(CemCem_Lin1Fr03_CEM_LIN1 . cemcem_lin1fr03_cem_lin1 . RainSnsrSnvtyForUsrSnvty3_CEM_LIN1 == 0)
  {
    rb_RLS_Sensitivity_Array_l[3] = 1;
  }
  else
  {
    rb_RLS_Sensitivity_Array_l[3] = CemCem_Lin1Fr03_CEM_LIN1 . cemcem_lin1fr03_cem_lin1 . RainSnsrSnvtyForUsrSnvty3_CEM_LIN1*2; 
  }


  if(CemCem_Lin1Fr03_CEM_LIN1 . cemcem_lin1fr03_cem_lin1 . RainSnsrSnvtyForUsrSnvty4_CEM_LIN1 == 0)
  {
    rb_RLS_Sensitivity_Array_l[4] = 1;
  }
  else
  {
    rb_RLS_Sensitivity_Array_l[4] = CemCem_Lin1Fr03_CEM_LIN1 . cemcem_lin1fr03_cem_lin1 . RainSnsrSnvtyForUsrSnvty4_CEM_LIN1*2;
  }


  if(CemCem_Lin1Fr03_CEM_LIN1 . cemcem_lin1fr03_cem_lin1 . RainSnsrSnvtyForUsrSnvty5_CEM_LIN1 == 0)
  {
    rb_RLS_Sensitivity_Array_l[5] = 1;
  }
  else
  {
    rb_RLS_Sensitivity_Array_l[5] = CemCem_Lin1Fr03_CEM_LIN1 . cemcem_lin1fr03_cem_lin1 . RainSnsrSnvtyForUsrSnvty5_CEM_LIN1*2;
  }


  if(CemCem_Lin1Fr03_CEM_LIN1 . cemcem_lin1fr03_cem_lin1 . RainSnsrSnvtyForUsrSnvty6_CEM_LIN1 == 0)
  {
    rb_RLS_Sensitivity_Array_l[6] = 1;
  }
  else
  {
    rb_RLS_Sensitivity_Array_l[6] = CemCem_Lin1Fr03_CEM_LIN1 . cemcem_lin1fr03_cem_lin1 . RainSnsrSnvtyForUsrSnvty6_CEM_LIN1*2;
  }      
  
  
  Rain_Sensitivity_Judge();
}


static void Get_Lin_Signal_From_GetLeWWS(void)
{  
  if((uLinIndicationFlags . w[0]. b5 != 0))
  {
    {uLinIndicationFlags . w[0]. b5 = 0;};
    uF_SCIFlags_mg . Bit . B1 = 1;
    if(CemCem_Lin1Fr02_CEM_LIN1 . cemcem_lin1fr02_cem_lin1 . AmbTForVisy_CEM_LIN1 != 255)
    {
      rb_OutsideTemp_mg = CemCem_Lin1Fr02_CEM_LIN1 . cemcem_lin1fr02_cem_lin1 . AmbTForVisy_CEM_LIN1;
    }
    WipeWinterModeCheck(); 
  }
    
  
  if((uLinIndicationFlags . w[0]. b4 != 0))
  {
    {uLinIndicationFlags . w[0]. b4 = 0;};
    uF_SCIFlags_mg . Bit . B1 = 1;
    {RlsmCem_Lin1Fr01_CEM_LIN1 . rlsmcem_lin1fr01_cem_lin1 . RainSnsrErrCalErrActv_CEM_LIN1 = 1;};     
    //Get_BCMVehType(l_u8_rd_VehTyp_CEM_LIN1());
    GetLightTransmission(CemCem_Lin1Fr03_CEM_LIN1 . cemcem_lin1fr03_cem_lin1 . WindCorrnValFrnt_CEM_LIN1,CemCem_Lin1Fr03_CEM_LIN1 . cemcem_lin1fr03_cem_lin1 . WindCorrnValAmb_CEM_LIN1);
    Rain_sensitivity();
  }
  
  
  if((uLinIndicationFlags . w[0]. b3 != 0))
  {
    {uLinIndicationFlags . w[0]. b3 = 0;};
    uF_SCIFlags_mg . Bit . B1 = 1;
    Set_BCMLightOffset(CemCem_Lin1Fr04_CEM_LIN1 . cemcem_lin1fr04_cem_lin1 . RainSnsrLiThd_CEM_LIN1);
  }
  
  
  if((uLinIndicationFlags . w[0]. b2 != 0))
  {
    {uLinIndicationFlags . w[0]. b2 = 0;};
    uF_SCIFlags_mg . Bit . B1 = 1;
  }
  
  
  if((uLinIndicationFlags . w[0]. b1 != 0))
  { 
    {uLinIndicationFlags . w[0]. b1 = 0;};
    uF_SCIFlags_mg . Bit . B1 = 1;
    uF_SCIFlags_mg . Bit . B6 = !(CemCem_Lin1Fr06_CEM_LIN1 . cemcem_lin1fr06_cem_lin1 . WiprInWipgAr_CEM_LIN1);        // wiper position
    
    
    if (CemCem_Lin1Fr06_CEM_LIN1 . cemcem_lin1fr06_cem_lin1 . WshngCycActv_CEM_LIN1 == 1)                                 /* Washpump activ? 0x5:Front washing*/
    {
      RSStatus . Bit . B1 = 1;                                       /* set Washing activ bit */
    }
    else if (uF_StatusRainsensor_mg . Bit . B7 == 1)                                /* In Parkposition ? */
    {
      RSStatus . Bit . B1 = 0;                                      /* Clear Washing active bit */
    }
    else{}                                                              /*Do nothing, Dummy-else for Misra Check*/
  }  
}


static void Light_Sensitivity_In_GetLeWWS(void)
{
  static const byte cab_PotistageMapping_mg[8] = {4,5,6,7,3,2,1,0}; /*mapping for potistages!*/  
  byte rb_Empfindlichkeit_LS_l;
  
  
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
    rb_AfterResetCounter_l++;
  }
  else{}
  
  
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


static void Wiper_and_Park(void)
{
  static byte rb_OutOffParkCounter_mg;
  
  
  if(CemCem_Lin1Fr01_CEM_LIN1 . cemcem_lin1fr01_cem_lin1 . RainSensActvn_CEM_LIN1 == 0)
  {
    rw_AfterRSWipeCounter_mg = 50000;
    rw_AfterWWSWipeCounter_mg = 50000;
    rw_WipeCommandTimOut_mg = 0;
  }
  else{}
  

  if(uF_SCIFlags_mg . Bit . B6 == 0)     
  {
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
}


static void Tunnel_Wipe_Decision(void)
{
  if((rw_AfterRSWipeCounterAlt_mg <= (((unsigned int)(EEPROM_Struct_AD . EEPROMStructAD . TunWischVerzAktiv>>4))*100))
     &&(rb_speed_in_kmh_g > 29)
       &&(uF_modi_lightsens_g . Bit . B2 == 1)
         &&(rub_RSIntermDelayInit == 0xFF))
  {
    if ((uF_Communication_mg . Bit . B4 == 0) && (rw_AfterRSWipeCounter_mg < (((unsigned int)(EEPROM_Struct_AD . EEPROMStructAD . TunWischVerzAktiv&0x0F))*100)))
    {
      rb_tunnelWipeActive_g = 1;
    }
  }
  else
  {
    rb_tunnelWipeActive_g = 0;
  }  
}

static void Exit_Wipe(void)
{
  if(uF_SCIFlags_mg . Bit . B6 == 0)
  {
  }
  else
  {
    if(rw_AfterWWSWipeCounter_mg > 3000)
    {
      if(RlsmCem_Lin1Fr01_CEM_LIN1 . rlsmcem_lin1fr01_cem_lin1 . WipgAutFrntMod_CEM_LIN1 > 0)
      {
        {RlsmCem_Lin1Fr01_CEM_LIN1 . rlsmcem_lin1fr01_cem_lin1 . WipgAutFrntMod_CEM_LIN1 = 0;};
      }
    }
    else if(rw_AfterWWSWipeCounter_mg > 500)
    {
      if(RlsmCem_Lin1Fr01_CEM_LIN1 . rlsmcem_lin1fr01_cem_lin1 . WipgAutFrntMod_CEM_LIN1 > 1)
      {
        {RlsmCem_Lin1Fr01_CEM_LIN1 . rlsmcem_lin1fr01_cem_lin1 . WipgAutFrntMod_CEM_LIN1 = 1;};
      }
    }
    else
    {
      if(RlsmCem_Lin1Fr01_CEM_LIN1 . rlsmcem_lin1fr01_cem_lin1 . WipgAutFrntMod_CEM_LIN1 > 2)
      {
        {RlsmCem_Lin1Fr01_CEM_LIN1 . rlsmcem_lin1fr01_cem_lin1 . WipgAutFrntMod_CEM_LIN1 = 2;};
      }
    }
  }
  
  
  if(uF_StatusRainsensor_mg . Bit . B0 == 0)
  {
    {RlsmCem_Lin1Fr01_CEM_LIN1 . rlsmcem_lin1fr01_cem_lin1 . WipgAutFrntMod_CEM_LIN1 = 0;};
  }
  {RlsmCem_Lin1Fr01_CEM_LIN1 . rlsmcem_lin1fr01_cem_lin1 . AutWinWipgCmd_CEM_LIN1 = 0;};
  
  
  if(rb_WipeWorkStatus_mg == 2)
  {
    {RlsmCem_Lin1Fr01_CEM_LIN1 . rlsmcem_lin1fr01_cem_lin1 . AutWinWipgCmd_CEM_LIN1 = 0;};
    {RlsmCem_Lin1Fr01_CEM_LIN1 . rlsmcem_lin1fr01_cem_lin1 . WipgAutFrntMod_CEM_LIN1 = 0;};
  }
}


static void Rain_Sensitivity_Judge(void)
{
  byte rb_Loop_Counter = 0;
  
  
  if((rb_RLS_Sensitivity_Array_l[0] < rb_RLS_Sensitivity_Array_l[1]) 
       && (rb_RLS_Sensitivity_Array_l[1] < rb_RLS_Sensitivity_Array_l[2]) 
         && (rb_RLS_Sensitivity_Array_l[2] < rb_RLS_Sensitivity_Array_l[3]) 
           && (rb_RLS_Sensitivity_Array_l[3] < rb_RLS_Sensitivity_Array_l[4])
             && (rb_RLS_Sensitivity_Array_l[4] < rb_RLS_Sensitivity_Array_l[5]) 
               && (rb_RLS_Sensitivity_Array_l[5] < rb_RLS_Sensitivity_Array_l[6]))
  {
    if((rb_RLS_Sensitivity_Array_l[0] != EEPROM_Struct_AD . EEPROMStructAD . RS_Sensitivity[0]) 
        || (rb_RLS_Sensitivity_Array_l[1] != EEPROM_Struct_AD . EEPROMStructAD . RS_Sensitivity[1]) 
          || (rb_RLS_Sensitivity_Array_l[2] != EEPROM_Struct_AD . EEPROMStructAD . RS_Sensitivity[2]) 
            || (rb_RLS_Sensitivity_Array_l[3] != EEPROM_Struct_AD . EEPROMStructAD . RS_Sensitivity[3]) 
              || (rb_RLS_Sensitivity_Array_l[4] != EEPROM_Struct_AD . EEPROMStructAD . RS_Sensitivity[4]))
    {
      if((uF_Main_Flags_g . Bit . B1 == 1) || (uF_Main_Flags_g . Bit . B2 == 0))
      {
        for(rb_Loop_Counter = 0;rb_Loop_Counter < 5;rb_Loop_Counter++)
        {
          rab_EEPROM_Bytes_toWrite_g[rb_Loop_Counter] = rb_RLS_Sensitivity_Array_l[rb_Loop_Counter];
        }  
        rw_EEPROM_Address_to_Write_g = 597;
        rb_I2C_EEPROM_bytesToWrite_g = 5;         /*set number of bytes to 5*/
        uF_Main_Flags_g . Bit . B2 = 1;    //set flag for bytes to write
        uF_Main_Flags_g . Bit . B1 = 0;   //clear bytes written (reset EEPROM bytes Written!)          
      }
      else{}
    }
    else{}

  
    if((rb_RLS_Sensitivity_Array_l[5] != EEPROM_Struct_AD . EEPROMStructAD . RS_Sensitivity[5]) 
       || (rb_RLS_Sensitivity_Array_l[6] != EEPROM_Struct_AD . EEPROMStructAD . RS_Sensitivity[6])) 
    {
      if((uF_Main_Flags_g . Bit . B1 == 1) || (uF_Main_Flags_g . Bit . B2 == 0))
      {
        for(rb_Loop_Counter = 0;rb_Loop_Counter < 2;rb_Loop_Counter++)
        {
          rab_EEPROM_Bytes_toWrite_g[rb_Loop_Counter] = rb_RLS_Sensitivity_Array_l[rb_Loop_Counter + 5];
        }  
        rw_EEPROM_Address_to_Write_g = 602;
        rb_I2C_EEPROM_bytesToWrite_g = 2;         /*set number of bytes to 4*/
        uF_Main_Flags_g . Bit . B2 = 1;    //set flag for bytes to write
        uF_Main_Flags_g . Bit . B1 = 0;   //clear bytes written (reset EEPROM bytes Written!)      
      }
      else{}
    }
    else{}
  }
  else{}
}


static void Standby_Judge(void)
{

  if (CemCem_Lin1Fr05_CEM_LIN1 . cemcem_lin1fr05_cem_lin1 . EnaOfflineMonitor_CEM_LIN1 == 1)
  {
    if (rb_Verglasun_offenDebounce_mg < 0xff)
    {
      rb_Verglasun_offenDebounce_mg ++;
    }
    rb_Verglasun_ClosedDebounce_mg = 0;
  }
  else if(CemCem_Lin1Fr05_CEM_LIN1 . cemcem_lin1fr05_cem_lin1 . EnaOfflineMonitor_CEM_LIN1 == 0)
  {
    rw_StandbyTimeOutCnt_g = 0;
    if (rb_Verglasun_ClosedDebounce_mg < 0xff)
    {
      rb_Verglasun_ClosedDebounce_mg ++;
    }
    rb_Verglasun_offenDebounce_mg = 0;
  }
  else{}

}


static void OutdBriCntr_Counter(void)
{
  static byte rb_Cnt_l = 0;

  {RlsmCem_Lin1Fr01_CEM_LIN1 . rlsmcem_lin1fr01_cem_lin1 . OutdBriCntr_CEM_LIN1 = rb_Cnt_l;};
  if(rb_Cnt_l < 15)
  {
    rb_Cnt_l ++;
  }
  else
  {
    rb_Cnt_l = 0;
  }
}
#line 2 "C:\\Users\\zhu1\\Downloads\\SW_Need_Change_Managemant\\GEEA2.0\\E4-2_SW\\RLS_SYS_RLS_GP_RLXS_GEN5_DEV_APL_GEELY2.0_RLFS_FOR_E4_03\\05_SwDev\\01_SrcCode\\Application\\CustomerInterface\\ModuleTest\\123456789\\vcast_preprocess.13636.12.c"
typedef int VECTORCAST_MARKER__MACRO_START_ASIC_ALS1_READY_FLG;
(byte)(1<<0)
typedef int VECTORCAST_MARKER__MACRO_END_ASIC_ALS1_READY_FLG;

typedef int VECTORCAST_MARKER__MACRO_START_ASIC_ALS2_INC_READY_FLG;
(byte)(1<<1)
typedef int VECTORCAST_MARKER__MACRO_END_ASIC_ALS2_INC_READY_FLG;

typedef int VECTORCAST_MARKER__MACRO_START_ASIC_ALS2_READY_FLG;
(byte)(1<<1)
typedef int VECTORCAST_MARKER__MACRO_END_ASIC_ALS2_READY_FLG;

typedef int VECTORCAST_MARKER__MACRO_START_ASIC_ALS5_INC_READY_FLG;
(byte)(1<<4)
typedef int VECTORCAST_MARKER__MACRO_END_ASIC_ALS5_INC_READY_FLG;

typedef int VECTORCAST_MARKER__MACRO_START_ASIC_ALS5_READY_FLG;
(byte)(1<<4)
typedef int VECTORCAST_MARKER__MACRO_END_ASIC_ALS5_READY_FLG;

typedef int VECTORCAST_MARKER__MACRO_START_ASIC_ALS6_READY_FLG;
(byte)(1<<5)
typedef int VECTORCAST_MARKER__MACRO_END_ASIC_ALS6_READY_FLG;

typedef int VECTORCAST_MARKER__MACRO_START_ASIC_MEAS_FREQ;
0x64
typedef int VECTORCAST_MARKER__MACRO_END_ASIC_MEAS_FREQ;

typedef int VECTORCAST_MARKER__MACRO_START_ASIC_REC_INC_READY_FLG;
(byte)(1<<6)
typedef int VECTORCAST_MARKER__MACRO_END_ASIC_REC_INC_READY_FLG;

typedef int VECTORCAST_MARKER__MACRO_START_ASIC_REC_READY_FLG;
(byte)(1<<6)
typedef int VECTORCAST_MARKER__MACRO_END_ASIC_REC_READY_FLG;

typedef int VECTORCAST_MARKER__MACRO_START_ASIC_START_MEAS;
0x12
typedef int VECTORCAST_MARKER__MACRO_END_ASIC_START_MEAS;

typedef int VECTORCAST_MARKER__MACRO_START_AmbIllmnFwdStsAmblillmn1_CEM_LIN1_0;
RlsmCem_Lin1Fr02_CEM_LIN1 . rlsmcem_lin1fr02_cem_lin1 . AmbIllmnFwdStsAmblillmn1_CEM_LIN1_0
typedef int VECTORCAST_MARKER__MACRO_END_AmbIllmnFwdStsAmblillmn1_CEM_LIN1_0;

typedef int VECTORCAST_MARKER__MACRO_START_AmbIllmnFwdStsAmblillmn1_CEM_LIN1_1;
RlsmCem_Lin1Fr02_CEM_LIN1 . rlsmcem_lin1fr02_cem_lin1 . AmbIllmnFwdStsAmblillmn1_CEM_LIN1_1
typedef int VECTORCAST_MARKER__MACRO_END_AmbIllmnFwdStsAmblillmn1_CEM_LIN1_1;

typedef int VECTORCAST_MARKER__MACRO_START_AmbIllmnFwdStsAmblillmn2_CEM_LIN1;
RlsmCem_Lin1Fr02_CEM_LIN1 . rlsmcem_lin1fr02_cem_lin1 . AmbIllmnFwdStsAmblillmn2_CEM_LIN1
typedef int VECTORCAST_MARKER__MACRO_END_AmbIllmnFwdStsAmblillmn2_CEM_LIN1;

typedef int VECTORCAST_MARKER__MACRO_START_AmbIllmnFwdStsChks_CEM_LIN1;
RlsmCem_Lin1Fr02_CEM_LIN1 . rlsmcem_lin1fr02_cem_lin1 . AmbIllmnFwdStsChks_CEM_LIN1
typedef int VECTORCAST_MARKER__MACRO_END_AmbIllmnFwdStsChks_CEM_LIN1;

typedef int VECTORCAST_MARKER__MACRO_START_AmbIllmnFwdStsCntr_CEM_LIN1;
RlsmCem_Lin1Fr02_CEM_LIN1 . rlsmcem_lin1fr02_cem_lin1 . AmbIllmnFwdStsCntr_CEM_LIN1
typedef int VECTORCAST_MARKER__MACRO_END_AmbIllmnFwdStsCntr_CEM_LIN1;

typedef int VECTORCAST_MARKER__MACRO_START_AmbTForVisy_CEM_LIN1;
CemCem_Lin1Fr02_CEM_LIN1 . cemcem_lin1fr02_cem_lin1 . AmbTForVisy_CEM_LIN1
typedef int VECTORCAST_MARKER__MACRO_END_AmbTForVisy_CEM_LIN1;

typedef int VECTORCAST_MARKER__MACRO_START_AutWinWipgCmd_CEM_LIN1;
RlsmCem_Lin1Fr01_CEM_LIN1 . rlsmcem_lin1fr01_cem_lin1 . AutWinWipgCmd_CEM_LIN1
typedef int VECTORCAST_MARKER__MACRO_END_AutWinWipgCmd_CEM_LIN1;

typedef int VECTORCAST_MARKER__MACRO_START_BRK_I_vect;
(0x7E)
typedef int VECTORCAST_MARKER__MACRO_END_BRK_I_vect;

typedef int VECTORCAST_MARKER__MACRO_START_CALLT_80_vect;
(0x80)
typedef int VECTORCAST_MARKER__MACRO_END_CALLT_80_vect;

typedef int VECTORCAST_MARKER__MACRO_START_CALLT_82_vect;
(0x82)
typedef int VECTORCAST_MARKER__MACRO_END_CALLT_82_vect;

typedef int VECTORCAST_MARKER__MACRO_START_CALLT_84_vect;
(0x84)
typedef int VECTORCAST_MARKER__MACRO_END_CALLT_84_vect;

typedef int VECTORCAST_MARKER__MACRO_START_CALLT_86_vect;
(0x86)
typedef int VECTORCAST_MARKER__MACRO_END_CALLT_86_vect;

typedef int VECTORCAST_MARKER__MACRO_START_CALLT_88_vect;
(0x88)
typedef int VECTORCAST_MARKER__MACRO_END_CALLT_88_vect;

typedef int VECTORCAST_MARKER__MACRO_START_CALLT_8A_vect;
(0x8A)
typedef int VECTORCAST_MARKER__MACRO_END_CALLT_8A_vect;

typedef int VECTORCAST_MARKER__MACRO_START_CALLT_8C_vect;
(0x8C)
typedef int VECTORCAST_MARKER__MACRO_END_CALLT_8C_vect;

typedef int VECTORCAST_MARKER__MACRO_START_CALLT_8E_vect;
(0x8E)
typedef int VECTORCAST_MARKER__MACRO_END_CALLT_8E_vect;

typedef int VECTORCAST_MARKER__MACRO_START_CALLT_90_vect;
(0x90)
typedef int VECTORCAST_MARKER__MACRO_END_CALLT_90_vect;

typedef int VECTORCAST_MARKER__MACRO_START_CALLT_92_vect;
(0x92)
typedef int VECTORCAST_MARKER__MACRO_END_CALLT_92_vect;

typedef int VECTORCAST_MARKER__MACRO_START_CALLT_94_vect;
(0x94)
typedef int VECTORCAST_MARKER__MACRO_END_CALLT_94_vect;

typedef int VECTORCAST_MARKER__MACRO_START_CALLT_96_vect;
(0x96)
typedef int VECTORCAST_MARKER__MACRO_END_CALLT_96_vect;

typedef int VECTORCAST_MARKER__MACRO_START_CALLT_98_vect;
(0x98)
typedef int VECTORCAST_MARKER__MACRO_END_CALLT_98_vect;

typedef int VECTORCAST_MARKER__MACRO_START_CALLT_9A_vect;
(0x9A)
typedef int VECTORCAST_MARKER__MACRO_END_CALLT_9A_vect;

typedef int VECTORCAST_MARKER__MACRO_START_CALLT_9C_vect;
(0x9C)
typedef int VECTORCAST_MARKER__MACRO_END_CALLT_9C_vect;

typedef int VECTORCAST_MARKER__MACRO_START_CALLT_9E_vect;
(0x9E)
typedef int VECTORCAST_MARKER__MACRO_END_CALLT_9E_vect;

typedef int VECTORCAST_MARKER__MACRO_START_CALLT_A0_vect;
(0xA0)
typedef int VECTORCAST_MARKER__MACRO_END_CALLT_A0_vect;

typedef int VECTORCAST_MARKER__MACRO_START_CALLT_A2_vect;
(0xA2)
typedef int VECTORCAST_MARKER__MACRO_END_CALLT_A2_vect;

typedef int VECTORCAST_MARKER__MACRO_START_CALLT_A4_vect;
(0xA4)
typedef int VECTORCAST_MARKER__MACRO_END_CALLT_A4_vect;

typedef int VECTORCAST_MARKER__MACRO_START_CALLT_A6_vect;
(0xA6)
typedef int VECTORCAST_MARKER__MACRO_END_CALLT_A6_vect;

typedef int VECTORCAST_MARKER__MACRO_START_CALLT_A8_vect;
(0xA8)
typedef int VECTORCAST_MARKER__MACRO_END_CALLT_A8_vect;

typedef int VECTORCAST_MARKER__MACRO_START_CALLT_AA_vect;
(0xAA)
typedef int VECTORCAST_MARKER__MACRO_END_CALLT_AA_vect;

typedef int VECTORCAST_MARKER__MACRO_START_CALLT_AC_vect;
(0xAC)
typedef int VECTORCAST_MARKER__MACRO_END_CALLT_AC_vect;

typedef int VECTORCAST_MARKER__MACRO_START_CALLT_AE_vect;
(0xAE)
typedef int VECTORCAST_MARKER__MACRO_END_CALLT_AE_vect;

typedef int VECTORCAST_MARKER__MACRO_START_CALLT_B0_vect;
(0xB0)
typedef int VECTORCAST_MARKER__MACRO_END_CALLT_B0_vect;

typedef int VECTORCAST_MARKER__MACRO_START_CALLT_B2_vect;
(0xB2)
typedef int VECTORCAST_MARKER__MACRO_END_CALLT_B2_vect;

typedef int VECTORCAST_MARKER__MACRO_START_CALLT_B4_vect;
(0xB4)
typedef int VECTORCAST_MARKER__MACRO_END_CALLT_B4_vect;

typedef int VECTORCAST_MARKER__MACRO_START_CALLT_B6_vect;
(0xB6)
typedef int VECTORCAST_MARKER__MACRO_END_CALLT_B6_vect;

typedef int VECTORCAST_MARKER__MACRO_START_CALLT_B8_vect;
(0xB8)
typedef int VECTORCAST_MARKER__MACRO_END_CALLT_B8_vect;

typedef int VECTORCAST_MARKER__MACRO_START_CALLT_BA_vect;
(0xBA)
typedef int VECTORCAST_MARKER__MACRO_END_CALLT_BA_vect;

typedef int VECTORCAST_MARKER__MACRO_START_CALLT_BC_vect;
(0xBC)
typedef int VECTORCAST_MARKER__MACRO_END_CALLT_BC_vect;

typedef int VECTORCAST_MARKER__MACRO_START_CALLT_BE_vect;
(0xBE)
typedef int VECTORCAST_MARKER__MACRO_END_CALLT_BE_vect;

typedef int VECTORCAST_MARKER__MACRO_START_CASE_ASIC_CNT_MD_NORMAL;
12
typedef int VECTORCAST_MARKER__MACRO_END_CASE_ASIC_CNT_MD_NORMAL;

typedef int VECTORCAST_MARKER__MACRO_START_CASE_ASIC_CNT_MD_PRE_STANDBY;
50
typedef int VECTORCAST_MARKER__MACRO_END_CASE_ASIC_CNT_MD_PRE_STANDBY;

typedef int VECTORCAST_MARKER__MACRO_START_CASE_ASIC_CNT_MD_RESET;
0
typedef int VECTORCAST_MARKER__MACRO_END_CASE_ASIC_CNT_MD_RESET;

typedef int VECTORCAST_MARKER__MACRO_START_CASE_ASIC_CNT_MD_STANDBY;
51
typedef int VECTORCAST_MARKER__MACRO_END_CASE_ASIC_CNT_MD_STANDBY;

typedef int VECTORCAST_MARKER__MACRO_START_CASE_ASIC_CNT_MD_STANDBY_CLOSE_WD;
60
typedef int VECTORCAST_MARKER__MACRO_END_CASE_ASIC_CNT_MD_STANDBY_CLOSE_WD;

typedef int VECTORCAST_MARKER__MACRO_START_CASE_ASIC_CNT_TEST_EN_RESET;
10
typedef int VECTORCAST_MARKER__MACRO_END_CASE_ASIC_CNT_TEST_EN_RESET;

typedef int VECTORCAST_MARKER__MACRO_START_CB_AMBLIGHT_100lx;
(byte)5
typedef int VECTORCAST_MARKER__MACRO_END_CB_AMBLIGHT_100lx;

typedef int VECTORCAST_MARKER__MACRO_START_CB_ANBHIGH_TO_LOW_FAKT;
8
typedef int VECTORCAST_MARKER__MACRO_END_CB_ANBHIGH_TO_LOW_FAKT;

typedef int VECTORCAST_MARKER__MACRO_START_CB_ASIC_CLEAR_DIAG;
0x08
typedef int VECTORCAST_MARKER__MACRO_END_CB_ASIC_CLEAR_DIAG;

typedef int VECTORCAST_MARKER__MACRO_START_CB_ASIC_INIT_MD;
0
typedef int VECTORCAST_MARKER__MACRO_END_CB_ASIC_INIT_MD;

typedef int VECTORCAST_MARKER__MACRO_START_CB_ASIC_LOOP1_MD;
1
typedef int VECTORCAST_MARKER__MACRO_END_CB_ASIC_LOOP1_MD;

typedef int VECTORCAST_MARKER__MACRO_START_CB_ASIC_LOOP2_MD;
2
typedef int VECTORCAST_MARKER__MACRO_END_CB_ASIC_LOOP2_MD;

typedef int VECTORCAST_MARKER__MACRO_START_CB_ASIC_LOPEN_MD;
5
typedef int VECTORCAST_MARKER__MACRO_END_CB_ASIC_LOPEN_MD;

typedef int VECTORCAST_MARKER__MACRO_START_CB_ASIC_LRAMP_MD;
3
typedef int VECTORCAST_MARKER__MACRO_END_CB_ASIC_LRAMP_MD;

typedef int VECTORCAST_MARKER__MACRO_START_CB_ASIC_LRETURN;
0xC6
typedef int VECTORCAST_MARKER__MACRO_END_CB_ASIC_LRETURN;

typedef int VECTORCAST_MARKER__MACRO_START_CB_ASIC_LSTOP_MD;
4
typedef int VECTORCAST_MARKER__MACRO_END_CB_ASIC_LSTOP_MD;

typedef int VECTORCAST_MARKER__MACRO_START_CB_ASIC_NOVALID_ADVALUES_THRSHD;
9
typedef int VECTORCAST_MARKER__MACRO_END_CB_ASIC_NOVALID_ADVALUES_THRSHD;

typedef int VECTORCAST_MARKER__MACRO_START_CB_ASIC_SET_DIAG;
0x0A
typedef int VECTORCAST_MARKER__MACRO_END_CB_ASIC_SET_DIAG;

typedef int VECTORCAST_MARKER__MACRO_START_CB_ASIC_SLEEP_MD;
7
typedef int VECTORCAST_MARKER__MACRO_END_CB_ASIC_SLEEP_MD;

typedef int VECTORCAST_MARKER__MACRO_START_CB_ASIC_WAKEUP_MD;
6
typedef int VECTORCAST_MARKER__MACRO_END_CB_ASIC_WAKEUP_MD;

typedef int VECTORCAST_MARKER__MACRO_START_CB_CHG_MUX_STMEAS_RQ;
(byte)0x0C
typedef int VECTORCAST_MARKER__MACRO_END_CB_CHG_MUX_STMEAS_RQ;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_ACTR_REG;
0x8F
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_ACTR_REG;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_AFTERTUNNELDELAYOFFS;
11
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_AFTERTUNNELDELAYOFFS;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_ALS1_4_SETTING;
0x24
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_ALS1_4_SETTING;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_ALS5_6_INREC_SETTING;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_ALS5_6_INREC_SETTING;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_ALSX_FILTER;
0x01
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_ALSX_FILTER;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_AMB_BASE_DAY_THRESHOLD;
187
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_AMB_BASE_DAY_THRESHOLD;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_AMB_BASE_NIGHT_THRESHOLD;
135
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_AMB_BASE_NIGHT_THRESHOLD;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_AMB_TUNNELTHRESHOLDSCALING;
0x04
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_AMB_TUNNELTHRESHOLDSCALING;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_ANSAMLUN_ADIT_OFFS;
0
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_ANSAMLUN_ADIT_OFFS;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_ASIC_AFSTHR_REG;
0x99
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_ASIC_AFSTHR_REG;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_ASIC_DIAGV;
0x78
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_ASIC_DIAGV;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_ASIC_FRAME_01;
0x40
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_ASIC_FRAME_01;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_ASIC_FRAME_02;
0x40
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_ASIC_FRAME_02;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_ASIC_FRAME_03;
0x40
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_ASIC_FRAME_03;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_ASIC_FRAME_04;
0x40
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_ASIC_FRAME_04;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_ASIC_LCTR;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_ASIC_LCTR;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_ASIC_RCTR_REG;
0xA4
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_ASIC_RCTR_REG;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_ASIC_RFCTR_REG;
0x80
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_ASIC_RFCTR_REG;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_ASIC_SCHED_CONFIG;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_ASIC_SCHED_CONFIG;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_AUDI_HW_PART_NUMBER_1;
'0'
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_AUDI_HW_PART_NUMBER_1;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_AUDI_HW_PART_NUMBER_10_INDEX;
' '
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_AUDI_HW_PART_NUMBER_10_INDEX;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_AUDI_HW_PART_NUMBER_11_INDEX;
' '
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_AUDI_HW_PART_NUMBER_11_INDEX;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_AUDI_HW_PART_NUMBER_2;
'1'
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_AUDI_HW_PART_NUMBER_2;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_AUDI_HW_PART_NUMBER_3;
'7'
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_AUDI_HW_PART_NUMBER_3;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_AUDI_HW_PART_NUMBER_4_5;
0x72
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_AUDI_HW_PART_NUMBER_4_5;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_AUDI_HW_PART_NUMBER_6_7;
0x07
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_AUDI_HW_PART_NUMBER_6_7;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_AUDI_HW_PART_NUMBER_8_9;
0x90
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_AUDI_HW_PART_NUMBER_8_9;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_AUDI_SW_PART_NUMBER_1;
'8'
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_AUDI_SW_PART_NUMBER_1;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_AUDI_SW_PART_NUMBER_10_INDEX;
' '
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_AUDI_SW_PART_NUMBER_10_INDEX;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_AUDI_SW_PART_NUMBER_11_INDEX;
' '
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_AUDI_SW_PART_NUMBER_11_INDEX;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_AUDI_SW_PART_NUMBER_2;
'1'
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_AUDI_SW_PART_NUMBER_2;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_AUDI_SW_PART_NUMBER_3;
'A'
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_AUDI_SW_PART_NUMBER_3;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_AUDI_SW_PART_NUMBER_4_5;
0x95
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_AUDI_SW_PART_NUMBER_4_5;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_AUDI_SW_PART_NUMBER_6_7;
0x55
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_AUDI_SW_PART_NUMBER_6_7;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_AUDI_SW_PART_NUMBER_8_9;
0x55
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_AUDI_SW_PART_NUMBER_8_9;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_AUTOBAHN_DELAY_ON;
0x49
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_AUTOBAHN_DELAY_ON;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_AUTOBAHN_ON_OFF;
0x54
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_AUTOBAHN_ON_OFF;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_BCM1_LIN1_01;
0x85
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_BCM1_LIN1_01;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_BCM1_LIN1_02;
0x47
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_BCM1_LIN1_02;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_BCM1_LIN1_03;
0x97
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_BCM1_LIN1_03;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_BCM1_LIN1_04;
0x49
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_BCM1_LIN1_04;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_BCM1_LIN1_05;
0xCA
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_BCM1_LIN1_05;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_B_FACTOR_IREF_HI_GAIN_HI;
0x40
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_B_FACTOR_IREF_HI_GAIN_HI;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_B_FACTOR_IREF_HI_GAIN_LO;
0xD8
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_B_FACTOR_IREF_HI_GAIN_LO;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_B_FACTOR_IREF_LO_GAIN_HI;
0x40
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_B_FACTOR_IREF_LO_GAIN_HI;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_B_FACTOR_IREF_LO_GAIN_LO;
0xD8
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_B_FACTOR_IREF_LO_GAIN_LO;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_COMBINED_FW_AL_THRS;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_COMBINED_FW_AL_THRS;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_CUSTOMER_FW_SWA_SCALING;
128
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_CUSTOMER_FW_SWA_SCALING;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_CUSTOMER_IR_SWA_SCALING;
128
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_CUSTOMER_IR_SWA_SCALING;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_DARK_TO_TWILIGHT_THRESH_AMB;
10
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_DARK_TO_TWILIGHT_THRESH_AMB;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_DARK_TO_TWILIGHT_THRESH_FW;
10
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_DARK_TO_TWILIGHT_THRESH_FW;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_DARK_TO_TWILIGHT_TIME;
15
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_DARK_TO_TWILIGHT_TIME;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_DAY_DELAY;
(byte)((unsigned int)(2*3000)>>6)
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_DAY_DELAY;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_DEC_INT_SP_OFF;
CB_DEC_INT_SP_OFFS_DEF | 0x20
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_DEC_INT_SP_OFF;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_DEC_OVR_SPEICHER;
CB_DEC_OVR_SPEICHER_DEF+((2)<<5)
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_DEC_OVR_SPEICHER;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_DEC_ST2_SPEICHER;
31
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_DEC_ST2_SPEICHER;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_DEC_STX_SPEICHER;
CB_DEC_STX_SPEICHER
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_DEC_STX_SPEICHER;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_DIAG_REQUEST_FACTOR;
0x07
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_DIAG_REQUEST_FACTOR;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_DYN_COMP_CCD_MINUS_1;
((0x08<<4)+0x06)
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_DYN_COMP_CCD_MINUS_1;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_DYN_COMP_CCD_MINUS_2;
((0x03 << 4)+0x00)
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_DYN_COMP_CCD_MINUS_2;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_E2_MAXST2SIGNALLAENGE;
140
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_E2_MAXST2SIGNALLAENGE;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_E2_RESERVED;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_E2_RESERVED;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_EEPROM_ERASE_COUNTER;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_EEPROM_ERASE_COUNTER;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_EMPF_FAKTOR_ST2_OFFS;
CB_EMPF_FAKTOR_ST2_OFFS_DEF + (2<<6)
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_EMPF_FAKTOR_ST2_OFFS;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_EP_ST2_EPR_IN_ST2;
CB_EP_ST2_EPR_IN_ST2
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_EP_ST2_EPR_IN_ST2;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_ERASE_COUNTER;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_ERASE_COUNTER;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_ERROR_ACTIVE_1;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_ERROR_ACTIVE_1;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_ERROR_ACTIVE_2;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_ERROR_ACTIVE_2;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_ERROR_ACTIVE_3;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_ERROR_ACTIVE_3;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_ERR_DATA_01;
0x40
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_ERR_DATA_01;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_FOSC_LEDUL;
0x81
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_FOSC_LEDUL;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_FRONTWASCHEN_AUTOBAHNDELAY;
0x57
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_FRONTWASCHEN_AUTOBAHNDELAY;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_FW_BASE_DAY_THRESHOLD;
180
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_FW_BASE_DAY_THRESHOLD;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_FW_BASE_NIGHT_THRESHOLD;
135
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_FW_BASE_NIGHT_THRESHOLD;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_GAINOFFSET_E2;
0
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_GAINOFFSET_E2;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_GAINSETUP_0_1;
0x01
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_GAINSETUP_0_1;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_GAINSETUP_10_MOD;
0xA0
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_GAINSETUP_10_MOD;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_GAINSETUP_2_3;
0x23
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_GAINSETUP_2_3;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_GAINSETUP_4_5;
0x45
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_GAINSETUP_4_5;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_GAINSETUP_6_7;
0x67
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_GAINSETUP_6_7;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_GAINSETUP_8_9;
0x89
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_GAINSETUP_8_9;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_HALIOS_CLOCK_CONTROL_REG;
0x90
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_HALIOS_CLOCK_CONTROL_REG;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_HARDWARESTAND_0;
'0'
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_HARDWARESTAND_0;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_HARDWARESTAND_1;
'1'
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_HARDWARESTAND_1;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_HUD_FACTOR;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_HUD_FACTOR;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_HUD_RESOLUTION;
0x64
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_HUD_RESOLUTION;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_HUD_VALUE;
(unsigned int)0x028fU
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_HUD_VALUE;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_I2C_DEBUG_CONFIG;
0xFF
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_I2C_DEBUG_CONFIG;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_ICE_DETECTION_TEMPERATURE;
80
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_ICE_DETECTION_TEMPERATURE;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_ICO1H;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_ICO1H;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_ICO1L;
0x80
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_ICO1L;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_ICO2H;
0
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_ICO2H;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_ICO2L;
0x70
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_ICO2L;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_IDFSS_01;
0x40
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_IDFSS_01;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_IDRLSS_01;
0x55
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_IDRLSS_01;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_IDRLSS_02;
0x20
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_IDRLSS_02;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_IDRLSS_03;
0xE2
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_IDRLSS_03;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_IDRLSS_04;
0xD8
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_IDRLSS_04;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_IDRLSS_05;
0xEC
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_IDRLSS_05;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_IDRLSS_06;
0x42
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_IDRLSS_06;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_INCIDENTCOUNTER1;
0
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_INCIDENTCOUNTER1;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_INCIDENTCOUNTER2;
0
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_INCIDENTCOUNTER2;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_INCIDENTCOUNTER3;
0
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_INCIDENTCOUNTER3;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_INCIDENTCOUNTER4;
0
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_INCIDENTCOUNTER4;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_INCIDENTCOUNTER5;
0
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_INCIDENTCOUNTER5;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_INCIDENTCOUNTER6;
0
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_INCIDENTCOUNTER6;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_INCIDENTCOUNTER7;
0
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_INCIDENTCOUNTER7;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_INC_SPEICHER;
0x64
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_INC_SPEICHER;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_INTCO;
0x10
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_INTCO;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_INTENSITY_OVERWIPECOEF;
0x28
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_INTENSITY_OVERWIPECOEF;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_INTENSITY_THR_IDLETIME;
0x3C
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_INTENSITY_THR_IDLETIME;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_INTERVALS_WAS_ACTIVE;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_INTERVALS_WAS_ACTIVE;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_IR_BASE_DAY_THRESHOLD;
90
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_IR_BASE_DAY_THRESHOLD;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_IR_BASE_NIGHT_THRESHOLD;
68
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_IR_BASE_NIGHT_THRESHOLD;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_KODIERBYTE_0;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_KODIERBYTE_0;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_KODIERBYTE_1;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_KODIERBYTE_1;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_KODIERBYTE_2;
0x6C
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_KODIERBYTE_2;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_LIGHTLS_ERROR_ACTIVE1;
0
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_LIGHTLS_ERROR_ACTIVE1;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_LIGHT_CTRL_SETTINGS1;
0x84
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_LIGHT_CTRL_SETTINGS1;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_LIGHT_CTRL_SETTINGS2;
0xC4
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_LIGHT_CTRL_SETTINGS2;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_LIGHT_CTRL_SETTINGS3;
0x8C
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_LIGHT_CTRL_SETTINGS3;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_LINID_SPARE_01;
0x40
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_LINID_SPARE_01;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_LS_RS_ERROR_ACTIVE1;
0
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_LS_RS_ERROR_ACTIVE1;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_LS_RS_ERROR_ACTIVE2;
0
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_LS_RS_ERROR_ACTIVE2;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_MAXOVERWIPESENSITIVITY;
cb_MAX_OVERWIPE_SENSITIVITY
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_MAXOVERWIPESENSITIVITY;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_MAXTEMPERATUREOFFSETT;
70
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_MAXTEMPERATUREOFFSETT;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_MAXTEMPERATUREOFFSET_G;
70
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_MAXTEMPERATUREOFFSET_G;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_MAX_SIGNALLAENGE;
CW_MAX_SIGNALLAENGE_DEF
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_MAX_SIGNALLAENGE;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_NACHWISCH_2;
CB_NACHWISCH_2_DEF
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_NACHWISCH_2;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_NACHWISCH_3;
CB_NACHWISCH_3_DEF | 0x80
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_NACHWISCH_3;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_NACHWISCH_4_ST1_MIN;
CB_NACHWISCH_4_DEF+(CB_ST1_NACHWISCH_MIN_DEF<<5)
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_NACHWISCH_4_ST1_MIN;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_NAD;
0x7B
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_NAD;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_NIGHT_DELAY;
(byte)((unsigned int)(2*3000)>>6)
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_NIGHT_DELAY;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_NOM_DELTA_INTV;
0xFF
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_NOM_DELTA_INTV;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_PCO_PI_REGULATOR;
0x60
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_PCO_PI_REGULATOR;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_PRJ_SPECIFIC_CONFIG;
0x03
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_PRJ_SPECIFIC_CONFIG;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_PRODUKTIONSNUMMER_0;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_PRODUKTIONSNUMMER_0;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_PRODUKTIONSNUMMER_1;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_PRODUKTIONSNUMMER_1;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_PRODUKTIONSNUMMER_2;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_PRODUKTIONSNUMMER_2;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_PRODUKTIONSNUMMER_3;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_PRODUKTIONSNUMMER_3;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_PROD_DATA;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_PROD_DATA;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_RAINNIGHTBITTHRS;
0x01
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_RAINNIGHTBITTHRS;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_RAINRS_ERROR_ACTIVE1;
0
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_RAINRS_ERROR_ACTIVE1;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_RB_STUFE1_WITH_INT_OG;
CB_STUFE1_WITH_INT_OG_DEF
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_RB_STUFE1_WITH_INT_OG;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_REGENLICHTSCHWELLE_LOW_HIGH;
0x1B
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_REGENLICHTSCHWELLE_LOW_HIGH;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_REGENLICHTSCHWELLE_ZEIT;
68
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_REGENLICHTSCHWELLE_ZEIT;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_REGULATION48LIGHTONTIME;
0x6C
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_REGULATION48LIGHTONTIME;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_REGULATION48THRESHOLD_AMB;
30
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_REGULATION48THRESHOLD_AMB;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_REGULATION48THRESHOLD_FW;
25
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_REGULATION48THRESHOLD_FW;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_RELEASE_INTERVAL_MARKER;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_RELEASE_INTERVAL_MARKER;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_RESF;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_RESF;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_RSCONTROLFLAGS;
0x01
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_RSCONTROLFLAGS;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_RSEMPFFACTORSCALING;
(0x80+0x40+0x07)
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_RSEMPFFACTORSCALING;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_RSEMPFFACTORSCALING_1;
(0x80+0x40+0x09)
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_RSEMPFFACTORSCALING_1;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_RS_SENSITIVITY_0;
CB_EMPF_FAKTOR_E1
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_RS_SENSITIVITY_0;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_RS_SENSITIVITY_1;
CB_EMPF_FAKTOR_E2
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_RS_SENSITIVITY_1;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_RS_SENSITIVITY_2;
CB_EMPF_FAKTOR_E3
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_RS_SENSITIVITY_2;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_RS_SENSITIVITY_3;
CB_EMPF_FAKTOR_E4
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_RS_SENSITIVITY_3;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_RS_SENSITIVITY_4;
CB_EMPF_FAKTOR_E5
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_RS_SENSITIVITY_4;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_RS_SENSITIVITY_5;
CB_EMPF_FAKTOR_E6
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_RS_SENSITIVITY_5;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_RS_SENSITIVITY_6;
CB_EMPF_FAKTOR_E7
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_RS_SENSITIVITY_6;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_RS_SENSITIVITY_7;
CB_EMPF_FAKTOR_E8
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_RS_SENSITIVITY_7;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_RS_SENSITIVITY_8;
CB_EMPF_FAKTOR_E9
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_RS_SENSITIVITY_8;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_SCHLIEREN_FLAG;
104
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_SCHLIEREN_FLAG;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_SCHWELLE_SCHWALL;
(byte)(CW_ST2_OG>>6)
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_SCHWELLE_SCHWALL;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_SCORDER12;
0x31
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_SCORDER12;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_SCORDER3;
0x07
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_SCORDER3;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_SCORDERMAX;
0x28
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_SCORDERMAX;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_SENSOR_ERRORX;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_SENSOR_ERRORX;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_SENS_CONFIG_DATA;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_SENS_CONFIG_DATA;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_SERIAL_NUMMER;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_SERIAL_NUMMER;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_SHTERRDEBOUNCEJITTER;
60
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_SHTERRDEBOUNCEJITTER;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_SIG_ANS_SCHW_OFFS;
CB_SIG_ANS_SCHW_OFFS_DEF
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_SIG_ANS_SCHW_OFFS;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_SLOAR_SHADOW_CORR_FACTOR1;
0
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_SLOAR_SHADOW_CORR_FACTOR1;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_SLOAR_SHADOW_CORR_FACTOR2;
7
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_SLOAR_SHADOW_CORR_FACTOR2;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_SOFTWARESTAND_0;
'0'
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_SOFTWARESTAND_0;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_SOFTWARESTAND_1;
'0'
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_SOFTWARESTAND_1;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_SOFTWARESTAND_2;
((('0' - '0')*16)+('1' - '0'))
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_SOFTWARESTAND_2;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_SOFTWARESTAND_3;
0
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_SOFTWARESTAND_3;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_SOSES_01;
0x40
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_SOSES_01;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_SPARE;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_SPARE;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_STANDBYMODESCANTIME;
36
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_STANDBYMODESCANTIME;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_STANDBYTIMOUT;
43
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_STANDBYTIMOUT;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_STANDBY_RAIN_MEASUREMENT_1;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_STANDBY_RAIN_MEASUREMENT_1;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_STANDBY_RAIN_MEASUREMENT_2;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_STANDBY_RAIN_MEASUREMENT_2;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_STANDBY_RAIN_MEASUREMENT_3;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_STANDBY_RAIN_MEASUREMENT_3;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_STANDBY_RAIN_MEASUREMENT_4;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_STANDBY_RAIN_MEASUREMENT_4;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_STANDBY_RAIN_MEASUREMENT_5;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_STANDBY_RAIN_MEASUREMENT_5;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_STANDBY_RAIN_MEASUREMENT_6;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_STANDBY_RAIN_MEASUREMENT_6;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_STBY_DELTA_INTV_HB;
0x09
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_STBY_DELTA_INTV_HB;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_STBY_DELTA_INTV_LB;
0x25
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_STBY_DELTA_INTV_LB;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_STBY_REGV_HB;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_STBY_REGV_HB;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_STBY_REGV_IMBALANCE;
0x14
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_STBY_REGV_IMBALANCE;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_STBY_REGV_LB;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_STBY_REGV_LB;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_STUFE1_OG;
CB_STUFE1_OG
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_STUFE1_OG;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_STUFE1_UG;
CB_STUFE1_UG_DEFINITION
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_STUFE1_UG;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_TEILENUMMERN_INDEX;
CB_TEILENUMMERIDX
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_TEILENUMMERN_INDEX;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_THRESHOLD_TEMPICERISK;
0x6A
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_THRESHOLD_TEMPICERISK;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_THR_DELTA_INTV;
0xC8
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_THR_DELTA_INTV;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_THR_SIGVOLTAGEH;
0x0E
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_THR_SIGVOLTAGEH;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_THR_SIGVOLTAGEL;
0x10
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_THR_SIGVOLTAGEL;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_TUNNELDEBOUNCEFACTOR;
45
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_TUNNELDEBOUNCEFACTOR;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_TUNNELTHRESHOLDSCALING;
0x44
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_TUNNELTHRESHOLDSCALING;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_TUNWISCHVERZAKTIV;
0x88
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_TUNWISCHVERZAKTIV;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_TWILIGHT_TO_DARK_THRESH_AMB;
4
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_TWILIGHT_TO_DARK_THRESH_AMB;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_TWILIGHT_TO_DARK_THRESH_FW;
4
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_TWILIGHT_TO_DARK_THRESH_FW;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_TWILIGHT_TO_DARK_TIME;
37
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_TWILIGHT_TO_DARK_TIME;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_UPPER_TOL_SUW;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_UPPER_TOL_SUW;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_VARIANT_ID;
0x01
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_VARIANT_ID;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_VERYBRIGHTINTUNL_DIST_THRS_g;
70
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_VERYBRIGHTINTUNL_DIST_THRS_g;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_VERYBRIGHTINTUNNELDELAY;
70
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_VERYBRIGHTINTUNNELDELAY;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_WATCHDOGRESETCOUNTER;
0
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_WATCHDOGRESETCOUNTER;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_WIPER_SPEED_HYSTERESIS;
0x64
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_WIPER_SPEED_HYSTERESIS;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_WWSS_01;
0xE7
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_WWSS_01;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEF_ZUSPLATE;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEF_ZUSPLATE;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DEPRESSED_PARK_POINTER_DEF;
2
typedef int VECTORCAST_MARKER__MACRO_END_CB_DEPRESSED_PARK_POINTER_DEF;

typedef int VECTORCAST_MARKER__MACRO_START_CB_DIAG_DEF_NAD;
0x7B
typedef int VECTORCAST_MARKER__MACRO_END_CB_DIAG_DEF_NAD;

typedef int VECTORCAST_MARKER__MACRO_START_CB_FREQ_NOTTRIMMED_CNT_THRSHD;
100
typedef int VECTORCAST_MARKER__MACRO_END_CB_FREQ_NOTTRIMMED_CNT_THRSHD;

typedef int VECTORCAST_MARKER__MACRO_START_CB_INPARKPOSITION_S;
0
typedef int VECTORCAST_MARKER__MACRO_END_CB_INPARKPOSITION_S;

typedef int VECTORCAST_MARKER__MACRO_START_CB_INREC_ABS_LOWER1_LEVEL;
(50)
typedef int VECTORCAST_MARKER__MACRO_END_CB_INREC_ABS_LOWER1_LEVEL;

typedef int VECTORCAST_MARKER__MACRO_START_CB_INREC_ABS_LOWER_LEVEL;
(1.5*20)
typedef int VECTORCAST_MARKER__MACRO_END_CB_INREC_ABS_LOWER_LEVEL;

typedef int VECTORCAST_MARKER__MACRO_START_CB_INREC_ABS_UPPER1_LEVEL;
(200)
typedef int VECTORCAST_MARKER__MACRO_END_CB_INREC_ABS_UPPER1_LEVEL;

typedef int VECTORCAST_MARKER__MACRO_START_CB_INREC_ABS_UPPER_LEVEL;
(255 - (1.5*20))
typedef int VECTORCAST_MARKER__MACRO_END_CB_INREC_ABS_UPPER_LEVEL;

typedef int VECTORCAST_MARKER__MACRO_START_CB_LIGHT_ERROR_THRESHOLD_MG;
40
typedef int VECTORCAST_MARKER__MACRO_END_CB_LIGHT_ERROR_THRESHOLD_MG;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_ACTR_REG;
0xff
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_ACTR_REG;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_AFTERTUNNELDELAYOFFS;
0x1f
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_AFTERTUNNELDELAYOFFS;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_ALS1_4_SETTING;
0xFF
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_ALS1_4_SETTING;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_ALS5_6_INREC_SETTING;
0xFF
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_ALS5_6_INREC_SETTING;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_ALSX_FILTER;
0x01
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_ALSX_FILTER;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_AMB_BASE_DAY_THRESHOLD;
254
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_AMB_BASE_DAY_THRESHOLD;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_AMB_BASE_NIGHT_THRESHOLD;
190
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_AMB_BASE_NIGHT_THRESHOLD;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_AMB_TUNNELTHRESHOLDSCALING;
0xff
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_AMB_TUNNELTHRESHOLDSCALING;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_ANSAMLUN_ADIT_OFFS;
180
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_ANSAMLUN_ADIT_OFFS;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_ASIC_AFSTHR_REG;
0xFF
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_ASIC_AFSTHR_REG;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_ASIC_DIAGV;
0xff
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_ASIC_DIAGV;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_ASIC_FRAME_01;
0xFF
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_ASIC_FRAME_01;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_ASIC_FRAME_02;
0xFF
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_ASIC_FRAME_02;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_ASIC_FRAME_03;
0xFF
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_ASIC_FRAME_03;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_ASIC_FRAME_04;
0xFF
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_ASIC_FRAME_04;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_ASIC_LCTR;
0xFF
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_ASIC_LCTR;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_ASIC_RCTR_REG;
0xFF
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_ASIC_RCTR_REG;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_ASIC_RFCTR_REG;
0xFF
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_ASIC_RFCTR_REG;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_ASIC_SCHED_CONFIG;
0xFF
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_ASIC_SCHED_CONFIG;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_AUDI_HW_PART_NUMBER_1;
0xFF
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_AUDI_HW_PART_NUMBER_1;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_AUDI_HW_PART_NUMBER_10_INDEX;
0xFF
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_AUDI_HW_PART_NUMBER_10_INDEX;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_AUDI_HW_PART_NUMBER_11_INDEX;
0xFF
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_AUDI_HW_PART_NUMBER_11_INDEX;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_AUDI_HW_PART_NUMBER_2;
0xFF
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_AUDI_HW_PART_NUMBER_2;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_AUDI_HW_PART_NUMBER_3;
0xFF
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_AUDI_HW_PART_NUMBER_3;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_AUDI_HW_PART_NUMBER_4_5;
0xFF
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_AUDI_HW_PART_NUMBER_4_5;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_AUDI_HW_PART_NUMBER_6_7;
0xFF
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_AUDI_HW_PART_NUMBER_6_7;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_AUDI_HW_PART_NUMBER_8_9;
0xFF
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_AUDI_HW_PART_NUMBER_8_9;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_AUDI_SW_PART_NUMBER_1;
0xFF
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_AUDI_SW_PART_NUMBER_1;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_AUDI_SW_PART_NUMBER_10_INDEX;
0xFF
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_AUDI_SW_PART_NUMBER_10_INDEX;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_AUDI_SW_PART_NUMBER_11_INDEX;
0xFF
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_AUDI_SW_PART_NUMBER_11_INDEX;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_AUDI_SW_PART_NUMBER_2;
0xFF
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_AUDI_SW_PART_NUMBER_2;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_AUDI_SW_PART_NUMBER_3;
0xFF
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_AUDI_SW_PART_NUMBER_3;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_AUDI_SW_PART_NUMBER_4_5;
0xFF
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_AUDI_SW_PART_NUMBER_4_5;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_AUDI_SW_PART_NUMBER_6_7;
0xFF
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_AUDI_SW_PART_NUMBER_6_7;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_AUDI_SW_PART_NUMBER_8_9;
0xFF
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_AUDI_SW_PART_NUMBER_8_9;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_AUTOBAHN_DELAY_ON;
0xFF
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_AUTOBAHN_DELAY_ON;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_AUTOBAHN_ON_OFF;
0xFF
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_AUTOBAHN_ON_OFF;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_BCM1_LIN1_01;
0xff
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_BCM1_LIN1_01;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_BCM1_LIN1_02;
0xff
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_BCM1_LIN1_02;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_BCM1_LIN1_03;
0xff
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_BCM1_LIN1_03;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_BCM1_LIN1_04;
0xff
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_BCM1_LIN1_04;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_BCM1_LIN1_05;
0xff
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_BCM1_LIN1_05;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_B_FACTOR_IREF_HI_GAIN_HI;
0xFF
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_B_FACTOR_IREF_HI_GAIN_HI;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_B_FACTOR_IREF_HI_GAIN_LO;
0xFF
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_B_FACTOR_IREF_HI_GAIN_LO;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_B_FACTOR_IREF_LO_GAIN_HI;
0xFF
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_B_FACTOR_IREF_LO_GAIN_HI;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_B_FACTOR_IREF_LO_GAIN_LO;
0xFF
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_B_FACTOR_IREF_LO_GAIN_LO;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_COMBINED_FW_AL_THRS;
0xFF
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_COMBINED_FW_AL_THRS;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_CUSTOMER_FW_SWA_SCALING;
220
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_CUSTOMER_FW_SWA_SCALING;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_CUSTOMER_IR_SWA_SCALING;
220
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_CUSTOMER_IR_SWA_SCALING;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_DARK_TO_TWILIGHT_THRESH_AMB;
255
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_DARK_TO_TWILIGHT_THRESH_AMB;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_DARK_TO_TWILIGHT_THRESH_FW;
255
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_DARK_TO_TWILIGHT_THRESH_FW;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_DARK_TO_TWILIGHT_TIME;
0xFF
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_DARK_TO_TWILIGHT_TIME;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_DAY_DELAY;
200
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_DAY_DELAY;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_DEC_INT_SP_OFF;
0xff
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_DEC_INT_SP_OFF;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_DEC_OVR_SPEICHER;
0x7F
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_DEC_OVR_SPEICHER;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_DEC_ST2_SPEICHER;
255
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_DEC_ST2_SPEICHER;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_DEC_STX_SPEICHER;
100
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_DEC_STX_SPEICHER;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_DIAG_REQUEST_FACTOR;
0x10
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_DIAG_REQUEST_FACTOR;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_DYN_COMP_CCD_MINUS_1;
0xFF
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_DYN_COMP_CCD_MINUS_1;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_DYN_COMP_CCD_MINUS_2;
0xFF
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_DYN_COMP_CCD_MINUS_2;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_E2_MAXST2SIGNALLAENGE;
255
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_E2_MAXST2SIGNALLAENGE;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_E2_RESERVED;
0xFF
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_E2_RESERVED;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_EEPROM_ERASE_COUNTER;
0xFF
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_EEPROM_ERASE_COUNTER;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_EMPF_FAKTOR_ST2_OFFS;
0xff
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_EMPF_FAKTOR_ST2_OFFS;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_EP_ST2_EPR_IN_ST2;
180
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_EP_ST2_EPR_IN_ST2;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_ERASE_COUNTER;
0xFF
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_ERASE_COUNTER;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_ERROR_ACTIVE_1;
0xFF
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_ERROR_ACTIVE_1;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_ERROR_ACTIVE_2;
0xFF
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_ERROR_ACTIVE_2;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_ERROR_ACTIVE_3;
0xFF
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_ERROR_ACTIVE_3;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_ERR_DATA_01;
0xFF
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_ERR_DATA_01;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_FOSC_LEDUL;
0xff
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_FOSC_LEDUL;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_FRONTWASCHEN_AUTOBAHNDELAY;
0xFF
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_FRONTWASCHEN_AUTOBAHNDELAY;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_FW_BASE_DAY_THRESHOLD;
210
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_FW_BASE_DAY_THRESHOLD;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_FW_BASE_NIGHT_THRESHOLD;
200
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_FW_BASE_NIGHT_THRESHOLD;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_GAINOFFSET_E2;
0xFF
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_GAINOFFSET_E2;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_GAINSETUP;
0xE0
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_GAINSETUP;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_HALIOS_CLOCK_CONTROL_REG;
0xff
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_HALIOS_CLOCK_CONTROL_REG;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_HARDWARESTAND_0;
0xff
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_HARDWARESTAND_0;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_HARDWARESTAND_1;
0xff
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_HARDWARESTAND_1;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_HUD_FACTOR;
0xFF
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_HUD_FACTOR;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_HUD_RESOLUTION;
0xff
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_HUD_RESOLUTION;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_HUD_VALUE;
(unsigned int)0xFFFFU
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_HUD_VALUE;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_I2C_DEBUG_CONFIG;
0xFF
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_I2C_DEBUG_CONFIG;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_ICE_DETECTION_TEMPERATURE;
255
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_ICE_DETECTION_TEMPERATURE;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_ICO1H;
0xff
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_ICO1H;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_ICO1L;
0xff
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_ICO1L;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_ICO2H;
0xff
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_ICO2H;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_ICO2L;
0xff
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_ICO2L;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_IDFSS_01;
0xff
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_IDFSS_01;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_IDRLSS_01;
0xff
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_IDRLSS_01;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_IDRLSS_02;
0xff
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_IDRLSS_02;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_IDRLSS_03;
0xff
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_IDRLSS_03;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_IDRLSS_04;
0xff
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_IDRLSS_04;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_IDRLSS_05;
0xff
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_IDRLSS_05;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_IDRLSS_06;
0xff
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_IDRLSS_06;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_INCIDENTCOUNTER1;
0xFF
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_INCIDENTCOUNTER1;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_INCIDENTCOUNTER2;
0xFF
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_INCIDENTCOUNTER2;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_INCIDENTCOUNTER3;
0xFF
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_INCIDENTCOUNTER3;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_INCIDENTCOUNTER4;
0xFF
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_INCIDENTCOUNTER4;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_INCIDENTCOUNTER5;
0xFF
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_INCIDENTCOUNTER5;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_INCIDENTCOUNTER6;
0xFF
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_INCIDENTCOUNTER6;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_INCIDENTCOUNTER7;
0xFF
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_INCIDENTCOUNTER7;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_INC_SPEICHER;
0xFF
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_INC_SPEICHER;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_INTCO;
0xff
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_INTCO;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_INTENSITY_FAST_IDLETIME;
0xFF
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_INTENSITY_FAST_IDLETIME;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_INTENSITY_OVERWIPECOEF;
0xFF
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_INTENSITY_OVERWIPECOEF;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_INTERVALS_WAS_ACTIVE;
0xff
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_INTERVALS_WAS_ACTIVE;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_IR_BASE_DAY_THRESHOLD;
170
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_IR_BASE_DAY_THRESHOLD;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_IR_BASE_NIGHT_THRESHOLD;
190
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_IR_BASE_NIGHT_THRESHOLD;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_KODIERBYTE_0;
0xFF
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_KODIERBYTE_0;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_KODIERBYTE_1;
0xFF
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_KODIERBYTE_1;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_KODIERBYTE_2;
0xFF
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_KODIERBYTE_2;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_LIGHTLS_ERROR_ACTIVE1;
0xFF
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_LIGHTLS_ERROR_ACTIVE1;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_LIGHT_CTRL_SETTINGS1;
0xFF
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_LIGHT_CTRL_SETTINGS1;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_LIGHT_CTRL_SETTINGS2;
0xFF
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_LIGHT_CTRL_SETTINGS2;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_LIGHT_CTRL_SETTINGS3;
0xFF
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_LIGHT_CTRL_SETTINGS3;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_LINID_SPARE_01;
0xFF
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_LINID_SPARE_01;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_LS_RS_ERROR_ACTIVE1;
0xFF
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_LS_RS_ERROR_ACTIVE1;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_LS_RS_ERROR_ACTIVE2;
0xFF
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_LS_RS_ERROR_ACTIVE2;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_MAXOVERWIPESENSITIVITY;
35
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_MAXOVERWIPESENSITIVITY;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_MAXTEMPERATUREOFFSETT;
0xFF
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_MAXTEMPERATUREOFFSETT;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_MAX_SIGNALLAENGE;
250
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_MAX_SIGNALLAENGE;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_NACHWISCH_2;
0xFF
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_NACHWISCH_2;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_NACHWISCH_3;
0xFF
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_NACHWISCH_3;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_NACHWISCH_4_ST1_MIN;
0xFF
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_NACHWISCH_4_ST1_MIN;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_NAD;
0x7E
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_NAD;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_NIGHT_DELAY;
200
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_NIGHT_DELAY;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_NOM_DELTA_INTV;
0xFF
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_NOM_DELTA_INTV;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_PCO_PI_REGULATOR;
0xff
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_PCO_PI_REGULATOR;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_PRJ_SPECIFIC_CONFIG;
0xFF
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_PRJ_SPECIFIC_CONFIG;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_PRODUKTIONSNUMMER_0;
0xff
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_PRODUKTIONSNUMMER_0;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_PRODUKTIONSNUMMER_1;
0xff
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_PRODUKTIONSNUMMER_1;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_PRODUKTIONSNUMMER_2;
0xff
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_PRODUKTIONSNUMMER_2;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_PRODUKTIONSNUMMER_3;
0xff
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_PRODUKTIONSNUMMER_3;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_PROD_DATA;
0xFF
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_PROD_DATA;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_RAINNIGHTBITTHRS;
0xff
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_RAINNIGHTBITTHRS;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_RAINRS_ERROR_ACTIVE1;
0xFF
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_RAINRS_ERROR_ACTIVE1;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_RB_STUFE1_WITH_INT_OG;
0xff
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_RB_STUFE1_WITH_INT_OG;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_REGENLICHTSCHWELLE_LOW_HIGH;
0xFF
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_REGENLICHTSCHWELLE_LOW_HIGH;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_REGENLICHTSCHWELLE_ZEIT;
0xFF
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_REGENLICHTSCHWELLE_ZEIT;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_REGULATION48LIGHTONTIME;
255
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_REGULATION48LIGHTONTIME;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_REGULATION48THRESHOLD_AMB;
255
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_REGULATION48THRESHOLD_AMB;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_REGULATION48THRESHOLD_FW;
255
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_REGULATION48THRESHOLD_FW;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_RELEASE_INTERVAL_MARKER;
0xFF
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_RELEASE_INTERVAL_MARKER;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_RESF;
0xFF
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_RESF;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_RSCONTROLFLAGS;
0xff
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_RSCONTROLFLAGS;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_RSEMPFFACTORSCALING;
255
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_RSEMPFFACTORSCALING;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_RS_SENSITIVITY_0;
35
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_RS_SENSITIVITY_0;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_RS_SENSITIVITY_1;
35
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_RS_SENSITIVITY_1;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_RS_SENSITIVITY_2;
35
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_RS_SENSITIVITY_2;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_RS_SENSITIVITY_3;
40
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_RS_SENSITIVITY_3;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_RS_SENSITIVITY_4;
40
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_RS_SENSITIVITY_4;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_RS_SENSITIVITY_5;
40
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_RS_SENSITIVITY_5;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_RS_SENSITIVITY_6;
40
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_RS_SENSITIVITY_6;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_RS_SENSITIVITY_7;
40
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_RS_SENSITIVITY_7;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_RS_SENSITIVITY_8;
40
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_RS_SENSITIVITY_8;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_SCHLIEREN_FLAG;
255
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_SCHLIEREN_FLAG;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_SCHWELLE_SCHWALL;
140
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_SCHWELLE_SCHWALL;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_SCORDER12;
0x7F
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_SCORDER12;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_SCORDER3;
0x7F
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_SCORDER3;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_SCORDERMAX;
0x7F
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_SCORDERMAX;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_SENSOR_ERRORX;
0xff
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_SENSOR_ERRORX;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_SENS_CONFIG_DATA;
0xFF
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_SENS_CONFIG_DATA;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_SERIAL_NUMMER;
0xFF
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_SERIAL_NUMMER;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_SHTERRDEBOUNCEJITTER;
0xFF
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_SHTERRDEBOUNCEJITTER;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_SIG_ANS_SCHW_OFFS;
0xff
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_SIG_ANS_SCHW_OFFS;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_SLOAR_SHADOW_CORR_FACTOR1;
0xFF
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_SLOAR_SHADOW_CORR_FACTOR1;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_SLOAR_SHADOW_CORR_FACTOR2;
0xFF
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_SLOAR_SHADOW_CORR_FACTOR2;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_SOFTWARESTAND_0;
0xff
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_SOFTWARESTAND_0;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_SOFTWARESTAND_1;
0xff
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_SOFTWARESTAND_1;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_SOFTWARESTAND_2;
0xff
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_SOFTWARESTAND_2;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_SOFTWARESTAND_3;
0xff
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_SOFTWARESTAND_3;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_SOSES_01;
0xFF
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_SOSES_01;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_SPARE;
0xFF
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_SPARE;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_STANDBYMODESCANTIME;
0xff
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_STANDBYMODESCANTIME;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_STANDBYTIMOUT;
0xff
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_STANDBYTIMOUT;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_STANDBY_RAIN_MEASUREMENT_1;
0xFF
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_STANDBY_RAIN_MEASUREMENT_1;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_STANDBY_RAIN_MEASUREMENT_2;
0xFF
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_STANDBY_RAIN_MEASUREMENT_2;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_STANDBY_RAIN_MEASUREMENT_3;
0xFF
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_STANDBY_RAIN_MEASUREMENT_3;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_STANDBY_RAIN_MEASUREMENT_4;
0xFF
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_STANDBY_RAIN_MEASUREMENT_4;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_STANDBY_RAIN_MEASUREMENT_5;
0xFF
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_STANDBY_RAIN_MEASUREMENT_5;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_STANDBY_RAIN_MEASUREMENT_6;
0xFF
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_STANDBY_RAIN_MEASUREMENT_6;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_STBY_DELTA_INTV_HB;
0x09
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_STBY_DELTA_INTV_HB;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_STBY_DELTA_INTV_LB;
0xFF
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_STBY_DELTA_INTV_LB;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_STBY_REGV_HB;
0x10
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_STBY_REGV_HB;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_STBY_REGV_IMBALANCE;
0xFF
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_STBY_REGV_IMBALANCE;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_STBY_REGV_LB;
0xFF
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_STBY_REGV_LB;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_STUFE1_OG;
230
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_STUFE1_OG;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_STUFE1_UG;
210
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_STUFE1_UG;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_TEILENUMMERN_INDEX;
0xff
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_TEILENUMMERN_INDEX;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_THRESHOLD_TEMPICERISK;
0xFF
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_THRESHOLD_TEMPICERISK;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_THR_DELTA_INTV;
0xFF
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_THR_DELTA_INTV;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_THR_SIGVOLTAGEH;
0xFF
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_THR_SIGVOLTAGEH;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_THR_SIGVOLTAGEL;
0xFF
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_THR_SIGVOLTAGEL;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_TUNNELDEBOUNCEFACTOR;
230
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_TUNNELDEBOUNCEFACTOR;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_TUNNELTHRESHOLDSCALING;
0xff
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_TUNNELTHRESHOLDSCALING;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_TUNWISCHVERZAKTIV;
0xFF
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_TUNWISCHVERZAKTIV;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_TWILIGHT_TO_DARK_THRESH_AMB;
255
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_TWILIGHT_TO_DARK_THRESH_AMB;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_TWILIGHT_TO_DARK_THRESH_FW;
255
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_TWILIGHT_TO_DARK_THRESH_FW;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_TWILIGHT_TO_DARK_TIME;
0xFF
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_TWILIGHT_TO_DARK_TIME;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_UPPER_TOL_SUW;
0x01
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_UPPER_TOL_SUW;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_VARIANT_ID;
0xFF
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_VARIANT_ID;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_VERYBRIGHTINTUNL_DIST_THRS_g;
255
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_VERYBRIGHTINTUNL_DIST_THRS_g;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_VERYBRIGHTINTUNNELDELAY;
255
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_VERYBRIGHTINTUNNELDELAY;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_WATCHDOGRESETCOUNTER;
0xff
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_WATCHDOGRESETCOUNTER;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_WIPER_SPEED_HYSTERESIS;
0x77
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_WIPER_SPEED_HYSTERESIS;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_WWSS_01;
0xff
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_WWSS_01;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MAX_ZUSPLATE;
0xFF
typedef int VECTORCAST_MARKER__MACRO_END_CB_MAX_ZUSPLATE;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_ACTR_REG;
0
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_ACTR_REG;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_AFTERTUNNELDELAYOFFS;
0
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_AFTERTUNNELDELAYOFFS;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_ALS1_4_SETTING;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_ALS1_4_SETTING;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_ALS5_6_INREC_SETTING;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_ALS5_6_INREC_SETTING;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_ALSX_FILTER;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_ALSX_FILTER;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_AMB_BASE_DAY_THRESHOLD;
50
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_AMB_BASE_DAY_THRESHOLD;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_AMB_BASE_NIGHT_THRESHOLD;
40
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_AMB_BASE_NIGHT_THRESHOLD;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_AMB_TUNNELTHRESHOLDSCALING;
0
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_AMB_TUNNELTHRESHOLDSCALING;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_ANSAMLUN_ADIT_OFFS;
0
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_ANSAMLUN_ADIT_OFFS;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_ASIC_AFSTHR_REG;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_ASIC_AFSTHR_REG;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_ASIC_DIAGV;
0
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_ASIC_DIAGV;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_ASIC_FRAME_01;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_ASIC_FRAME_01;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_ASIC_FRAME_02;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_ASIC_FRAME_02;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_ASIC_FRAME_03;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_ASIC_FRAME_03;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_ASIC_FRAME_04;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_ASIC_FRAME_04;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_ASIC_LCTR;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_ASIC_LCTR;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_ASIC_RCTR_REG;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_ASIC_RCTR_REG;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_ASIC_RFCTR_REG;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_ASIC_RFCTR_REG;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_ASIC_SCHED_CONFIG;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_ASIC_SCHED_CONFIG;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_AUDI_HW_PART_NUMBER_1;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_AUDI_HW_PART_NUMBER_1;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_AUDI_HW_PART_NUMBER_10_INDEX;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_AUDI_HW_PART_NUMBER_10_INDEX;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_AUDI_HW_PART_NUMBER_11_INDEX;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_AUDI_HW_PART_NUMBER_11_INDEX;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_AUDI_HW_PART_NUMBER_2;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_AUDI_HW_PART_NUMBER_2;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_AUDI_HW_PART_NUMBER_3;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_AUDI_HW_PART_NUMBER_3;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_AUDI_HW_PART_NUMBER_4_5;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_AUDI_HW_PART_NUMBER_4_5;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_AUDI_HW_PART_NUMBER_6_7;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_AUDI_HW_PART_NUMBER_6_7;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_AUDI_HW_PART_NUMBER_8_9;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_AUDI_HW_PART_NUMBER_8_9;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_AUDI_SW_PART_NUMBER_1;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_AUDI_SW_PART_NUMBER_1;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_AUDI_SW_PART_NUMBER_10_INDEX;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_AUDI_SW_PART_NUMBER_10_INDEX;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_AUDI_SW_PART_NUMBER_11_INDEX;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_AUDI_SW_PART_NUMBER_11_INDEX;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_AUDI_SW_PART_NUMBER_2;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_AUDI_SW_PART_NUMBER_2;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_AUDI_SW_PART_NUMBER_3;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_AUDI_SW_PART_NUMBER_3;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_AUDI_SW_PART_NUMBER_4_5;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_AUDI_SW_PART_NUMBER_4_5;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_AUDI_SW_PART_NUMBER_6_7;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_AUDI_SW_PART_NUMBER_6_7;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_AUDI_SW_PART_NUMBER_8_9;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_AUDI_SW_PART_NUMBER_8_9;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_AUTOBAHN_DELAY_ON;
0
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_AUTOBAHN_DELAY_ON;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_AUTOBAHN_ON_OFF;
0
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_AUTOBAHN_ON_OFF;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_BCM1_LIN1_01;
0
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_BCM1_LIN1_01;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_BCM1_LIN1_02;
0
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_BCM1_LIN1_02;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_BCM1_LIN1_03;
0
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_BCM1_LIN1_03;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_BCM1_LIN1_04;
0
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_BCM1_LIN1_04;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_BCM1_LIN1_05;
0
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_BCM1_LIN1_05;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_B_FACTOR_IREF_HI_GAIN_HI;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_B_FACTOR_IREF_HI_GAIN_HI;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_B_FACTOR_IREF_HI_GAIN_LO;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_B_FACTOR_IREF_HI_GAIN_LO;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_B_FACTOR_IREF_LO_GAIN_HI;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_B_FACTOR_IREF_LO_GAIN_HI;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_B_FACTOR_IREF_LO_GAIN_LO;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_B_FACTOR_IREF_LO_GAIN_LO;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_COMBINED_FW_AL_THRS;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_COMBINED_FW_AL_THRS;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_CUSTOMER_FW_SWA_SCALING;
50
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_CUSTOMER_FW_SWA_SCALING;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_CUSTOMER_IR_SWA_SCALING;
50
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_CUSTOMER_IR_SWA_SCALING;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_DARK_TO_TWILIGHT_THRESH_AMB;
1
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_DARK_TO_TWILIGHT_THRESH_AMB;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_DARK_TO_TWILIGHT_THRESH_FW;
1
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_DARK_TO_TWILIGHT_THRESH_FW;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_DARK_TO_TWILIGHT_TIME;
0x01
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_DARK_TO_TWILIGHT_TIME;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_DAY_DELAY;
50
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_DAY_DELAY;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_DEC_INT_SP_OFF;
0x05
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_DEC_INT_SP_OFF;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_DEC_OVR_SPEICHER;
6
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_DEC_OVR_SPEICHER;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_DEC_ST2_SPEICHER;
10
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_DEC_ST2_SPEICHER;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_DEC_STX_SPEICHER;
30
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_DEC_STX_SPEICHER;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_DIAG_REQUEST_FACTOR;
0x05
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_DIAG_REQUEST_FACTOR;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_DYN_COMP_CCD_MINUS_1;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_DYN_COMP_CCD_MINUS_1;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_DYN_COMP_CCD_MINUS_2;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_DYN_COMP_CCD_MINUS_2;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_E2_MAXST2SIGNALLAENGE;
20
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_E2_MAXST2SIGNALLAENGE;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_E2_RESERVED;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_E2_RESERVED;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_EEPROM_ERASE_COUNTER;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_EEPROM_ERASE_COUNTER;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_EMPF_FAKTOR_ST2_OFFS;
3
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_EMPF_FAKTOR_ST2_OFFS;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_EP_ST2_EPR_IN_ST2;
128
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_EP_ST2_EPR_IN_ST2;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_ERASE_COUNTER;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_ERASE_COUNTER;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_ERROR_ACTIVE_1;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_ERROR_ACTIVE_1;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_ERROR_ACTIVE_2;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_ERROR_ACTIVE_2;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_ERROR_ACTIVE_3;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_ERROR_ACTIVE_3;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_ERR_DATA_01;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_ERR_DATA_01;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_FOSC_LEDUL;
0
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_FOSC_LEDUL;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_FRONTWASCHEN_AUTOBAHNDELAY;
0
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_FRONTWASCHEN_AUTOBAHNDELAY;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_FW_BASE_DAY_THRESHOLD;
70
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_FW_BASE_DAY_THRESHOLD;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_FW_BASE_NIGHT_THRESHOLD;
50
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_FW_BASE_NIGHT_THRESHOLD;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_GAINOFFSET_E2;
0
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_GAINOFFSET_E2;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_GAINSETUP;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_GAINSETUP;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_HALIOS_CLOCK_CONTROL_REG;
0
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_HALIOS_CLOCK_CONTROL_REG;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_HARDWARESTAND_0;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_HARDWARESTAND_0;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_HARDWARESTAND_1;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_HARDWARESTAND_1;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_HUD_FACTOR;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_HUD_FACTOR;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_HUD_RESOLUTION;
0
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_HUD_RESOLUTION;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_HUD_VALUE;
(unsigned int)0x0000U
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_HUD_VALUE;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_I2C_DEBUG_CONFIG;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_I2C_DEBUG_CONFIG;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_ICE_DETECTION_TEMPERATURE;
0
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_ICE_DETECTION_TEMPERATURE;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_ICO1H;
0
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_ICO1H;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_ICO1L;
0
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_ICO1L;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_ICO2H;
0
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_ICO2H;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_ICO2L;
0
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_ICO2L;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_IDFSS_01;
0
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_IDFSS_01;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_IDRLSS_01;
0
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_IDRLSS_01;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_IDRLSS_02;
0
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_IDRLSS_02;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_IDRLSS_03;
0
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_IDRLSS_03;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_IDRLSS_04;
0
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_IDRLSS_04;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_IDRLSS_05;
0
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_IDRLSS_05;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_IDRLSS_06;
0
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_IDRLSS_06;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_INCIDENTCOUNTER1;
0
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_INCIDENTCOUNTER1;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_INCIDENTCOUNTER2;
0
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_INCIDENTCOUNTER2;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_INCIDENTCOUNTER3;
0
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_INCIDENTCOUNTER3;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_INCIDENTCOUNTER4;
0
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_INCIDENTCOUNTER4;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_INCIDENTCOUNTER5;
0
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_INCIDENTCOUNTER5;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_INCIDENTCOUNTER6;
0
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_INCIDENTCOUNTER6;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_INCIDENTCOUNTER7;
0
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_INCIDENTCOUNTER7;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_INC_SPEICHER;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_INC_SPEICHER;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_INTCO;
0
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_INTCO;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_INTENSITY_FAST_IDLETIME;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_INTENSITY_FAST_IDLETIME;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_INTENSITY_OVERWIPECOEF;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_INTENSITY_OVERWIPECOEF;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_INTERVALS_WAS_ACTIVE;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_INTERVALS_WAS_ACTIVE;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_IR_BASE_DAY_THRESHOLD;
40
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_IR_BASE_DAY_THRESHOLD;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_IR_BASE_NIGHT_THRESHOLD;
30
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_IR_BASE_NIGHT_THRESHOLD;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_KODIERBYTE_0;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_KODIERBYTE_0;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_KODIERBYTE_1;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_KODIERBYTE_1;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_KODIERBYTE_2;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_KODIERBYTE_2;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_LIGHTLS_ERROR_ACTIVE1;
0
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_LIGHTLS_ERROR_ACTIVE1;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_LIGHT_CTRL_SETTINGS1;
0x01
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_LIGHT_CTRL_SETTINGS1;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_LIGHT_CTRL_SETTINGS2;
0x01
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_LIGHT_CTRL_SETTINGS2;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_LIGHT_CTRL_SETTINGS3;
0x01
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_LIGHT_CTRL_SETTINGS3;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_LINID_SPARE_01;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_LINID_SPARE_01;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_LS_RS_ERROR_ACTIVE1;
0
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_LS_RS_ERROR_ACTIVE1;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_LS_RS_ERROR_ACTIVE2;
0
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_LS_RS_ERROR_ACTIVE2;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_MAXOVERWIPESENSITIVITY;
2
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_MAXOVERWIPESENSITIVITY;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_MAXTEMPERATUREOFFSETT;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_MAXTEMPERATUREOFFSETT;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_MAX_SIGNALLAENGE;
120
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_MAX_SIGNALLAENGE;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_NACHWISCH_2;
11
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_NACHWISCH_2;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_NACHWISCH_3;
11
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_NACHWISCH_3;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_NACHWISCH_4_ST1_MIN;
11
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_NACHWISCH_4_ST1_MIN;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_NAD;
0x01
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_NAD;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_NIGHT_DELAY;
50
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_NIGHT_DELAY;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_NOM_DELTA_INTV;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_NOM_DELTA_INTV;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_PCO_PI_REGULATOR;
0
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_PCO_PI_REGULATOR;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_PRJ_SPECIFIC_CONFIG;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_PRJ_SPECIFIC_CONFIG;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_PRODUKTIONSNUMMER_0;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_PRODUKTIONSNUMMER_0;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_PRODUKTIONSNUMMER_1;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_PRODUKTIONSNUMMER_1;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_PRODUKTIONSNUMMER_2;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_PRODUKTIONSNUMMER_2;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_PRODUKTIONSNUMMER_3;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_PRODUKTIONSNUMMER_3;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_PROD_DATA;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_PROD_DATA;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_RAINNIGHTBITTHRS;
0
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_RAINNIGHTBITTHRS;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_RAINRS_ERROR_ACTIVE1;
0
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_RAINRS_ERROR_ACTIVE1;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_RB_STUFE1_WITH_INT_OG;
0
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_RB_STUFE1_WITH_INT_OG;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_REGENLICHTSCHWELLE_LOW_HIGH;
0
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_REGENLICHTSCHWELLE_LOW_HIGH;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_REGENLICHTSCHWELLE_ZEIT;
0
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_REGENLICHTSCHWELLE_ZEIT;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_REGULATION48LIGHTONTIME;
20
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_REGULATION48LIGHTONTIME;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_REGULATION48THRESHOLD_AMB;
0
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_REGULATION48THRESHOLD_AMB;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_REGULATION48THRESHOLD_FW;
0
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_REGULATION48THRESHOLD_FW;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_RELEASE_INTERVAL_MARKER;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_RELEASE_INTERVAL_MARKER;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_RESF;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_RESF;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_RSCONTROLFLAGS;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_RSCONTROLFLAGS;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_RSEMPFFACTORSCALING;
0
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_RSEMPFFACTORSCALING;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_RS_SENSITIVITY_0;
2
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_RS_SENSITIVITY_0;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_RS_SENSITIVITY_1;
2
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_RS_SENSITIVITY_1;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_RS_SENSITIVITY_2;
2
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_RS_SENSITIVITY_2;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_RS_SENSITIVITY_3;
2
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_RS_SENSITIVITY_3;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_RS_SENSITIVITY_4;
2
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_RS_SENSITIVITY_4;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_RS_SENSITIVITY_5;
2
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_RS_SENSITIVITY_5;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_RS_SENSITIVITY_6;
2
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_RS_SENSITIVITY_6;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_RS_SENSITIVITY_7;
2
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_RS_SENSITIVITY_7;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_RS_SENSITIVITY_8;
2
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_RS_SENSITIVITY_8;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_SCHLIEREN_FLAG;
4
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_SCHLIEREN_FLAG;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_SCHWELLE_SCHWALL;
25
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_SCHWELLE_SCHWALL;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_SCORDER12;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_SCORDER12;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_SCORDER3;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_SCORDER3;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_SCORDERMAX;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_SCORDERMAX;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_SENSOR_ERRORX;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_SENSOR_ERRORX;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_SENS_CONFIG_DATA;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_SENS_CONFIG_DATA;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_SERIAL_NUMMER;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_SERIAL_NUMMER;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_SHTERRDEBOUNCEJITTER;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_SHTERRDEBOUNCEJITTER;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_SIG_ANS_SCHW_OFFS;
10
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_SIG_ANS_SCHW_OFFS;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_SLOAR_SHADOW_CORR_FACTOR1;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_SLOAR_SHADOW_CORR_FACTOR1;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_SLOAR_SHADOW_CORR_FACTOR2;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_SLOAR_SHADOW_CORR_FACTOR2;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_SOFTWARESTAND_0;
0
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_SOFTWARESTAND_0;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_SOFTWARESTAND_1;
0
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_SOFTWARESTAND_1;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_SOFTWARESTAND_2;
0
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_SOFTWARESTAND_2;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_SOFTWARESTAND_3;
0
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_SOFTWARESTAND_3;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_SOSES_01;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_SOSES_01;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_SPARE;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_SPARE;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_STANDBYMODESCANTIME;
0
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_STANDBYMODESCANTIME;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_STANDBYTIMOUT;
0
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_STANDBYTIMOUT;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_STANDBY_RAIN_MEASUREMENT_1;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_STANDBY_RAIN_MEASUREMENT_1;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_STANDBY_RAIN_MEASUREMENT_2;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_STANDBY_RAIN_MEASUREMENT_2;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_STANDBY_RAIN_MEASUREMENT_3;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_STANDBY_RAIN_MEASUREMENT_3;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_STANDBY_RAIN_MEASUREMENT_4;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_STANDBY_RAIN_MEASUREMENT_4;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_STANDBY_RAIN_MEASUREMENT_5;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_STANDBY_RAIN_MEASUREMENT_5;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_STANDBY_RAIN_MEASUREMENT_6;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_STANDBY_RAIN_MEASUREMENT_6;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_STBY_DELTA_INTV_HB;
0x02
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_STBY_DELTA_INTV_HB;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_STBY_DELTA_INTV_LB;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_STBY_DELTA_INTV_LB;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_STBY_REGV_HB;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_STBY_REGV_HB;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_STBY_REGV_IMBALANCE;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_STBY_REGV_IMBALANCE;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_STBY_REGV_LB;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_STBY_REGV_LB;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_STUFE1_OG;
170
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_STUFE1_OG;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_STUFE1_UG;
150
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_STUFE1_UG;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_TEILENUMMERN_INDEX;
0
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_TEILENUMMERN_INDEX;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_THRESHOLD_TEMPICERISK;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_THRESHOLD_TEMPICERISK;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_THR_DELTA_INTV;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_THR_DELTA_INTV;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_THR_SIGVOLTAGEH;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_THR_SIGVOLTAGEH;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_THR_SIGVOLTAGEL;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_THR_SIGVOLTAGEL;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_TUNNELDEBOUNCEFACTOR;
0
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_TUNNELDEBOUNCEFACTOR;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_TUNNELTHRESHOLDSCALING;
0
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_TUNNELTHRESHOLDSCALING;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_TUNWISCHVERZAKTIV;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_TUNWISCHVERZAKTIV;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_TWILIGHT_TO_DARK_THRESH_AMB;
1
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_TWILIGHT_TO_DARK_THRESH_AMB;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_TWILIGHT_TO_DARK_THRESH_FW;
1
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_TWILIGHT_TO_DARK_THRESH_FW;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_TWILIGHT_TO_DARK_TIME;
0x01
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_TWILIGHT_TO_DARK_TIME;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_UPPER_TOL_SUW;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_UPPER_TOL_SUW;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_VARIANT_ID;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_VARIANT_ID;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_VERYBRIGHTINTUNL_DIST_THRS_g;
20
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_VERYBRIGHTINTUNL_DIST_THRS_g;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_VERYBRIGHTINTUNNELDELAY;
20
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_VERYBRIGHTINTUNNELDELAY;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_WATCHDOGRESETCOUNTER;
0
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_WATCHDOGRESETCOUNTER;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_WIPER_SPEED_HYSTERESIS;
0x11
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_WIPER_SPEED_HYSTERESIS;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_WWSS_01;
0
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_WWSS_01;

typedef int VECTORCAST_MARKER__MACRO_START_CB_MIN_ZUSPLATE;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CB_MIN_ZUSPLATE;

typedef int VECTORCAST_MARKER__MACRO_START_CB_NO_NEXT_RQ;
(byte)0x0
typedef int VECTORCAST_MARKER__MACRO_END_CB_NO_NEXT_RQ;

typedef int VECTORCAST_MARKER__MACRO_START_CB_NUMBER_OF_REG_ASIC10112_g;
((byte)28)
typedef int VECTORCAST_MARKER__MACRO_END_CB_NUMBER_OF_REG_ASIC10112_g;

typedef int VECTORCAST_MARKER__MACRO_START_CB_OFFSETT_ADDIT_NOM;
64
typedef int VECTORCAST_MARKER__MACRO_END_CB_OFFSETT_ADDIT_NOM;

typedef int VECTORCAST_MARKER__MACRO_START_CB_PARKTOWENDELAGEOBEN_S;
1
typedef int VECTORCAST_MARKER__MACRO_END_CB_PARKTOWENDELAGEOBEN_S;

typedef int VECTORCAST_MARKER__MACRO_START_CB_RS_WINDOW_COMP_THRESHOLD;
(((EEPROM_Struct_AD . EEPROMStructAD . PrametersStruct[((EEPROM_Struct_PD . EEPROMStructPD . EEKodierbyte1_g & 12)>>2)]. dec_Int_Sp_off & 0xE0)>>4) + 18)
typedef int VECTORCAST_MARKER__MACRO_END_CB_RS_WINDOW_COMP_THRESHOLD;

typedef int VECTORCAST_MARKER__MACRO_START_CB_SIZEOF_ASIC_CTRREG_G;
((byte)28)
typedef int VECTORCAST_MARKER__MACRO_END_CB_SIZEOF_ASIC_CTRREG_G;

typedef int VECTORCAST_MARKER__MACRO_START_CB_SIZE_OF_MUX_MEASAD_g;
9
typedef int VECTORCAST_MARKER__MACRO_END_CB_SIZE_OF_MUX_MEASAD_g;

typedef int VECTORCAST_MARKER__MACRO_START_CB_STANDBY_THRESHOLD;
20
typedef int VECTORCAST_MARKER__MACRO_END_CB_STANDBY_THRESHOLD;

typedef int VECTORCAST_MARKER__MACRO_START_CB_STEPRESPPERREQUEST_G;
2
typedef int VECTORCAST_MARKER__MACRO_END_CB_STEPRESPPERREQUEST_G;

typedef int VECTORCAST_MARKER__MACRO_START_CB_STMEAS_RQ;
(byte)0x3
typedef int VECTORCAST_MARKER__MACRO_END_CB_STMEAS_RQ;

typedef int VECTORCAST_MARKER__MACRO_START_CB_TIMFORAFWTHRS_INC_g;
2
typedef int VECTORCAST_MARKER__MACRO_END_CB_TIMFORAFWTHRS_INC_g;

typedef int VECTORCAST_MARKER__MACRO_START_CB_TUNWISCHAKTIV_MG;
(EEPROM_Struct_AD . EEPROMStructAD . TunWischVerzAktiv&0x0F)
typedef int VECTORCAST_MARKER__MACRO_END_CB_TUNWISCHAKTIV_MG;

typedef int VECTORCAST_MARKER__MACRO_START_CB_TUNWISCHVERZ_MG;
(EEPROM_Struct_AD . EEPROMStructAD . TunWischVerzAktiv>>4)
typedef int VECTORCAST_MARKER__MACRO_END_CB_TUNWISCHVERZ_MG;

typedef int VECTORCAST_MARKER__MACRO_START_CB_VDDX_ERRORCNT_THRESHOLD_MG;
40
typedef int VECTORCAST_MARKER__MACRO_END_CB_VDDX_ERRORCNT_THRESHOLD_MG;

typedef int VECTORCAST_MARKER__MACRO_START_CB_WENDELAGEOBENTOPARK_S;
2
typedef int VECTORCAST_MARKER__MACRO_END_CB_WENDELAGEOBENTOPARK_S;

typedef int VECTORCAST_MARKER__MACRO_START_CLEAR_EEPROM;
0xff
typedef int VECTORCAST_MARKER__MACRO_END_CLEAR_EEPROM;

typedef int VECTORCAST_MARKER__MACRO_START_CS_HT_MODULE;

typedef int VECTORCAST_MARKER__MACRO_END_CS_HT_MODULE;

typedef int VECTORCAST_MARKER__MACRO_START_CS_STANDBY;

typedef int VECTORCAST_MARKER__MACRO_END_CS_STANDBY;

typedef int VECTORCAST_MARKER__MACRO_START_CW_CALIB_CRC_END;
291
typedef int VECTORCAST_MARKER__MACRO_END_CW_CALIB_CRC_END;

typedef int VECTORCAST_MARKER__MACRO_START_CW_CALIB_CRC_START;
271
typedef int VECTORCAST_MARKER__MACRO_END_CW_CALIB_CRC_START;

typedef int VECTORCAST_MARKER__MACRO_START_CW_DEF_A_FACTOR_ALS1;
(unsigned int)0x0164U
typedef int VECTORCAST_MARKER__MACRO_END_CW_DEF_A_FACTOR_ALS1;

typedef int VECTORCAST_MARKER__MACRO_START_CW_DEF_A_FACTOR_ALS2;
(unsigned int)0x028CU
typedef int VECTORCAST_MARKER__MACRO_END_CW_DEF_A_FACTOR_ALS2;

typedef int VECTORCAST_MARKER__MACRO_START_CW_DEF_A_FACTOR_ALS3;
(unsigned int)0x0200U
typedef int VECTORCAST_MARKER__MACRO_END_CW_DEF_A_FACTOR_ALS3;

typedef int VECTORCAST_MARKER__MACRO_START_CW_DEF_A_FACTOR_ALS4;
(unsigned int)0x0200U
typedef int VECTORCAST_MARKER__MACRO_END_CW_DEF_A_FACTOR_ALS4;

typedef int VECTORCAST_MARKER__MACRO_START_CW_DEF_A_FACTOR_ALS5;
(unsigned int)0x01AAU
typedef int VECTORCAST_MARKER__MACRO_END_CW_DEF_A_FACTOR_ALS5;

typedef int VECTORCAST_MARKER__MACRO_START_CW_DEF_A_FACTOR_ALS6;
(unsigned int)0x0200U
typedef int VECTORCAST_MARKER__MACRO_END_CW_DEF_A_FACTOR_ALS6;

typedef int VECTORCAST_MARKER__MACRO_START_CW_DEF_A_FACTOR_INREC;
(unsigned int)0x01A8U
typedef int VECTORCAST_MARKER__MACRO_END_CW_DEF_A_FACTOR_INREC;

typedef int VECTORCAST_MARKER__MACRO_START_CW_DEF_CRC_CHECKSUM_CALIBRATION;
(unsigned int)0xFFFFU
typedef int VECTORCAST_MARKER__MACRO_END_CW_DEF_CRC_CHECKSUM_CALIBRATION;

typedef int VECTORCAST_MARKER__MACRO_START_CW_DEF_FUNCTION_ID;
0x000BU
typedef int VECTORCAST_MARKER__MACRO_END_CW_DEF_FUNCTION_ID;

typedef int VECTORCAST_MARKER__MACRO_START_CW_DEF_NO_RAIN_PRESENT_THRSH_HB;
0x01
typedef int VECTORCAST_MARKER__MACRO_END_CW_DEF_NO_RAIN_PRESENT_THRSH_HB;

typedef int VECTORCAST_MARKER__MACRO_START_CW_DEF_NO_RAIN_PRESENT_THRSH_LB;
0x2C
typedef int VECTORCAST_MARKER__MACRO_END_CW_DEF_NO_RAIN_PRESENT_THRSH_LB;

typedef int VECTORCAST_MARKER__MACRO_START_CW_DEWPOINT_MIN_mg;
1
typedef int VECTORCAST_MARKER__MACRO_END_CW_DEWPOINT_MIN_mg;

typedef int VECTORCAST_MARKER__MACRO_START_CW_DEWPOINT_OFFSETT_mg;
4
typedef int VECTORCAST_MARKER__MACRO_END_CW_DEWPOINT_OFFSETT_mg;

typedef int VECTORCAST_MARKER__MACRO_START_CW_E2_ERASECOUNTER_ADRESS;
(339)
typedef int VECTORCAST_MARKER__MACRO_END_CW_E2_ERASECOUNTER_ADRESS;

typedef int VECTORCAST_MARKER__MACRO_START_CW_E2_IDBCM1_LIN1_01_ADRESS;
(327)
typedef int VECTORCAST_MARKER__MACRO_END_CW_E2_IDBCM1_LIN1_01_ADRESS;

typedef int VECTORCAST_MARKER__MACRO_START_CW_E2_IDFSS_01_ADRESS;
(325)
typedef int VECTORCAST_MARKER__MACRO_END_CW_E2_IDFSS_01_ADRESS;

typedef int VECTORCAST_MARKER__MACRO_START_CW_E2_IDFSS_ENH_01_ADRESS;
(306)
typedef int VECTORCAST_MARKER__MACRO_END_CW_E2_IDFSS_ENH_01_ADRESS;

typedef int VECTORCAST_MARKER__MACRO_START_CW_E2_IDFSS_ERR_DATA_ADRESS;
(346)
typedef int VECTORCAST_MARKER__MACRO_END_CW_E2_IDFSS_ERR_DATA_ADRESS;

typedef int VECTORCAST_MARKER__MACRO_START_CW_E2_IDRLSS_01_ADRESS;
(326)
typedef int VECTORCAST_MARKER__MACRO_END_CW_E2_IDRLSS_01_ADRESS;

typedef int VECTORCAST_MARKER__MACRO_START_CW_E2_IDSOSES_01_ADRESS;
(329)
typedef int VECTORCAST_MARKER__MACRO_END_CW_E2_IDSOSES_01_ADRESS;

typedef int VECTORCAST_MARKER__MACRO_START_CW_E2_IDWWSS_01_ADRESS;
(328)
typedef int VECTORCAST_MARKER__MACRO_END_CW_E2_IDWWSS_01_ADRESS;

typedef int VECTORCAST_MARKER__MACRO_START_CW_E2_NAD_ADRESS;
(324)
typedef int VECTORCAST_MARKER__MACRO_END_CW_E2_NAD_ADRESS;

typedef int VECTORCAST_MARKER__MACRO_START_CW_E2_SENSOR_ERROR1_ADRESS;
774
typedef int VECTORCAST_MARKER__MACRO_END_CW_E2_SENSOR_ERROR1_ADRESS;

typedef int VECTORCAST_MARKER__MACRO_START_CW_E2_SENSOR_ERROR2_ADRESS;
(unsigned int)(775)
typedef int VECTORCAST_MARKER__MACRO_END_CW_E2_SENSOR_ERROR2_ADRESS;

typedef int VECTORCAST_MARKER__MACRO_START_CW_E2_SENSOR_ERROR3_ADRESS;
776
typedef int VECTORCAST_MARKER__MACRO_END_CW_E2_SENSOR_ERROR3_ADRESS;

typedef int VECTORCAST_MARKER__MACRO_START_CW_E2_SENSOR_ERROR4_ADRESS;
777
typedef int VECTORCAST_MARKER__MACRO_END_CW_E2_SENSOR_ERROR4_ADRESS;

typedef int VECTORCAST_MARKER__MACRO_START_CW_E2_SENSOR_ERROR5_ADRESS;
778
typedef int VECTORCAST_MARKER__MACRO_END_CW_E2_SENSOR_ERROR5_ADRESS;

typedef int VECTORCAST_MARKER__MACRO_START_CW_E2_SENSOR_ERROR6_ADRESS;
779
typedef int VECTORCAST_MARKER__MACRO_END_CW_E2_SENSOR_ERROR6_ADRESS;

typedef int VECTORCAST_MARKER__MACRO_START_CW_E2_SENSOR_RESF_ADRESS;
796
typedef int VECTORCAST_MARKER__MACRO_END_CW_E2_SENSOR_RESF_ADRESS;

typedef int VECTORCAST_MARKER__MACRO_START_CW_E2_WATCHDOGRESETCOUTERADRESS;
(773)
typedef int VECTORCAST_MARKER__MACRO_END_CW_E2_WATCHDOGRESETCOUTERADRESS;

typedef int VECTORCAST_MARKER__MACRO_START_CW_EEPROM_INCIDENT1_ADDRESS;
(780)
typedef int VECTORCAST_MARKER__MACRO_END_CW_EEPROM_INCIDENT1_ADDRESS;

typedef int VECTORCAST_MARKER__MACRO_START_CW_EEPROM_INCIDENT2_ADDRESS;
(781)
typedef int VECTORCAST_MARKER__MACRO_END_CW_EEPROM_INCIDENT2_ADDRESS;

typedef int VECTORCAST_MARKER__MACRO_START_CW_EEPROM_INCIDENT3_ADDRESS;
(782)
typedef int VECTORCAST_MARKER__MACRO_END_CW_EEPROM_INCIDENT3_ADDRESS;

typedef int VECTORCAST_MARKER__MACRO_START_CW_EEPROM_INCIDENT4_ADDRESS;
(783)
typedef int VECTORCAST_MARKER__MACRO_END_CW_EEPROM_INCIDENT4_ADDRESS;

typedef int VECTORCAST_MARKER__MACRO_START_CW_EEPROM_INCIDENT5_ADDRESS;
(784)
typedef int VECTORCAST_MARKER__MACRO_END_CW_EEPROM_INCIDENT5_ADDRESS;

typedef int VECTORCAST_MARKER__MACRO_START_CW_EEPROM_INCIDENT6_ADDRESS;
(785)
typedef int VECTORCAST_MARKER__MACRO_END_CW_EEPROM_INCIDENT6_ADDRESS;

typedef int VECTORCAST_MARKER__MACRO_START_CW_EEPROM_PD_START_ADR;
256
typedef int VECTORCAST_MARKER__MACRO_END_CW_EEPROM_PD_START_ADR;

typedef int VECTORCAST_MARKER__MACRO_START_CW_FOSC_LEDUL_ADDR_g;
(593)
typedef int VECTORCAST_MARKER__MACRO_END_CW_FOSC_LEDUL_ADDR_g;

typedef int VECTORCAST_MARKER__MACRO_START_CW_INTERVAL_MARKER_ADRESS;
(unsigned int)792
typedef int VECTORCAST_MARKER__MACRO_END_CW_INTERVAL_MARKER_ADRESS;

typedef int VECTORCAST_MARKER__MACRO_START_CW_LIGHTLS_ERROR_ACTIVE1_ADR;
(unsigned int)789
typedef int VECTORCAST_MARKER__MACRO_END_CW_LIGHTLS_ERROR_ACTIVE1_ADR;

typedef int VECTORCAST_MARKER__MACRO_START_CW_LIN1_3_IDLE_TIMOUT;
(2*130)
typedef int VECTORCAST_MARKER__MACRO_END_CW_LIN1_3_IDLE_TIMOUT;

typedef int VECTORCAST_MARKER__MACRO_START_CW_LIN2_0_IDLE_TIMOUT;
400
typedef int VECTORCAST_MARKER__MACRO_END_CW_LIN2_0_IDLE_TIMOUT;

typedef int VECTORCAST_MARKER__MACRO_START_CW_LIN_E2_IDLE_TIMOUT;
((((EEPROM_Struct_AD . EEPROMStructAD . p_t_autobahn_delay_on_g>>5)&0x07)*100)+200)
typedef int VECTORCAST_MARKER__MACRO_END_CW_LIN_E2_IDLE_TIMOUT;

typedef int VECTORCAST_MARKER__MACRO_START_CW_MAX_A_FACTOR_ALS1;
(unsigned int)0xFFFFU
typedef int VECTORCAST_MARKER__MACRO_END_CW_MAX_A_FACTOR_ALS1;

typedef int VECTORCAST_MARKER__MACRO_START_CW_MAX_A_FACTOR_ALS2;
(unsigned int)0xFFFFU
typedef int VECTORCAST_MARKER__MACRO_END_CW_MAX_A_FACTOR_ALS2;

typedef int VECTORCAST_MARKER__MACRO_START_CW_MAX_A_FACTOR_ALS3;
(unsigned int)0xFFFFU
typedef int VECTORCAST_MARKER__MACRO_END_CW_MAX_A_FACTOR_ALS3;

typedef int VECTORCAST_MARKER__MACRO_START_CW_MAX_A_FACTOR_ALS4;
(unsigned int)0xFFFFU
typedef int VECTORCAST_MARKER__MACRO_END_CW_MAX_A_FACTOR_ALS4;

typedef int VECTORCAST_MARKER__MACRO_START_CW_MAX_A_FACTOR_ALS5;
(unsigned int)0xBFFFU
typedef int VECTORCAST_MARKER__MACRO_END_CW_MAX_A_FACTOR_ALS5;

typedef int VECTORCAST_MARKER__MACRO_START_CW_MAX_A_FACTOR_ALS6;
(unsigned int)0xFFFFU
typedef int VECTORCAST_MARKER__MACRO_END_CW_MAX_A_FACTOR_ALS6;

typedef int VECTORCAST_MARKER__MACRO_START_CW_MAX_A_FACTOR_INREC;
(unsigned int)0xFFFFU
typedef int VECTORCAST_MARKER__MACRO_END_CW_MAX_A_FACTOR_INREC;

typedef int VECTORCAST_MARKER__MACRO_START_CW_MAX_CRC_CHECKSUM_CALIBRATION;
(unsigned int)0xFFFFU
typedef int VECTORCAST_MARKER__MACRO_END_CW_MAX_CRC_CHECKSUM_CALIBRATION;

typedef int VECTORCAST_MARKER__MACRO_START_CW_MAX_FUNCTION_ID;
0xFFFFU
typedef int VECTORCAST_MARKER__MACRO_END_CW_MAX_FUNCTION_ID;

typedef int VECTORCAST_MARKER__MACRO_START_CW_MAX_NO_RAIN_PRESENT_THRSH_HB;
0xFF
typedef int VECTORCAST_MARKER__MACRO_END_CW_MAX_NO_RAIN_PRESENT_THRSH_HB;

typedef int VECTORCAST_MARKER__MACRO_START_CW_MAX_NO_RAIN_PRESENT_THRSH_LB;
0xFF
typedef int VECTORCAST_MARKER__MACRO_END_CW_MAX_NO_RAIN_PRESENT_THRSH_LB;

typedef int VECTORCAST_MARKER__MACRO_START_CW_MIN_A_FACTOR_ALS1;
(unsigned int)0x0000U
typedef int VECTORCAST_MARKER__MACRO_END_CW_MIN_A_FACTOR_ALS1;

typedef int VECTORCAST_MARKER__MACRO_START_CW_MIN_A_FACTOR_ALS2;
(unsigned int)0x0000U
typedef int VECTORCAST_MARKER__MACRO_END_CW_MIN_A_FACTOR_ALS2;

typedef int VECTORCAST_MARKER__MACRO_START_CW_MIN_A_FACTOR_ALS3;
(unsigned int)0x0000U
typedef int VECTORCAST_MARKER__MACRO_END_CW_MIN_A_FACTOR_ALS3;

typedef int VECTORCAST_MARKER__MACRO_START_CW_MIN_A_FACTOR_ALS4;
(unsigned int)0x0000U
typedef int VECTORCAST_MARKER__MACRO_END_CW_MIN_A_FACTOR_ALS4;

typedef int VECTORCAST_MARKER__MACRO_START_CW_MIN_A_FACTOR_ALS5;
(unsigned int)0x0000U
typedef int VECTORCAST_MARKER__MACRO_END_CW_MIN_A_FACTOR_ALS5;

typedef int VECTORCAST_MARKER__MACRO_START_CW_MIN_A_FACTOR_ALS6;
(unsigned int)0x0000U
typedef int VECTORCAST_MARKER__MACRO_END_CW_MIN_A_FACTOR_ALS6;

typedef int VECTORCAST_MARKER__MACRO_START_CW_MIN_A_FACTOR_INREC;
(unsigned int)0x0000U
typedef int VECTORCAST_MARKER__MACRO_END_CW_MIN_A_FACTOR_INREC;

typedef int VECTORCAST_MARKER__MACRO_START_CW_MIN_CRC_CHECKSUM_CALIBRATION;
(unsigned int)0x0000U
typedef int VECTORCAST_MARKER__MACRO_END_CW_MIN_CRC_CHECKSUM_CALIBRATION;

typedef int VECTORCAST_MARKER__MACRO_START_CW_MIN_FUNCTION_ID;
0x0000U
typedef int VECTORCAST_MARKER__MACRO_END_CW_MIN_FUNCTION_ID;

typedef int VECTORCAST_MARKER__MACRO_START_CW_MIN_NO_RAIN_PRESENT_THRSH_HB;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CW_MIN_NO_RAIN_PRESENT_THRSH_HB;

typedef int VECTORCAST_MARKER__MACRO_START_CW_MIN_NO_RAIN_PRESENT_THRSH_LB;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_CW_MIN_NO_RAIN_PRESENT_THRSH_LB;

typedef int VECTORCAST_MARKER__MACRO_START_CW_NO_RAIN_PRESENT_THRSH_HB_g;
EEPROM_Struct_PD . EEPROMStructPD . NO_RAIN_PRESENT_THRSH_HB_g
typedef int VECTORCAST_MARKER__MACRO_END_CW_NO_RAIN_PRESENT_THRSH_HB_g;

typedef int VECTORCAST_MARKER__MACRO_START_CW_NO_RAIN_PRESENT_THRSH_LB_g;
EEPROM_Struct_PD . EEPROMStructPD . NO_RAIN_PRESENT_THRSH_LB_g
typedef int VECTORCAST_MARKER__MACRO_END_CW_NO_RAIN_PRESENT_THRSH_LB_g;

typedef int VECTORCAST_MARKER__MACRO_START_CW_NO_RAIN_PRESENT_THRSH_g;
((unsigned int)(((unsigned int)EEPROM_Struct_PD . EEPROMStructPD . NO_RAIN_PRESENT_THRSH_HB_g<<8)+EEPROM_Struct_PD . EEPROMStructPD . NO_RAIN_PRESENT_THRSH_LB_g)>10?(unsigned int)(((unsigned int)EEPROM_Struct_PD . EEPROMStructPD . NO_RAIN_PRESENT_THRSH_HB_g<<8)+EEPROM_Struct_PD . EEPROMStructPD . NO_RAIN_PRESENT_THRSH_LB_g):10)
typedef int VECTORCAST_MARKER__MACRO_END_CW_NO_RAIN_PRESENT_THRSH_g;

typedef int VECTORCAST_MARKER__MACRO_START_CW_RAINRS_ERROR_ACTIVE1_ADR;
(unsigned int)790
typedef int VECTORCAST_MARKER__MACRO_END_CW_RAINRS_ERROR_ACTIVE1_ADR;

typedef int VECTORCAST_MARKER__MACRO_START_CW_REGV_OSAT_CNT_THRSHD;
(unsigned int)(1400)
typedef int VECTORCAST_MARKER__MACRO_END_CW_REGV_OSAT_CNT_THRSHD;

typedef int VECTORCAST_MARKER__MACRO_START_CW_RS_LS_ERROR_ACTIVE1_ADR;
(unsigned int)787
typedef int VECTORCAST_MARKER__MACRO_END_CW_RS_LS_ERROR_ACTIVE1_ADR;

typedef int VECTORCAST_MARKER__MACRO_START_CW_RS_LS_ERROR_ACTIVE2_ADR;
(unsigned int)788
typedef int VECTORCAST_MARKER__MACRO_END_CW_RS_LS_ERROR_ACTIVE2_ADR;

typedef int VECTORCAST_MARKER__MACRO_START_CW_SENS_CONFIG_DATA_ADRESS;
(unsigned int)793
typedef int VECTORCAST_MARKER__MACRO_END_CW_SENS_CONFIG_DATA_ADRESS;

typedef int VECTORCAST_MARKER__MACRO_START_CW_TEMPERATURE_MIN_mg;
1
typedef int VECTORCAST_MARKER__MACRO_END_CW_TEMPERATURE_MIN_mg;

typedef int VECTORCAST_MARKER__MACRO_START_CW_TEMPERATURE_OFFSETT_mg;
4
typedef int VECTORCAST_MARKER__MACRO_END_CW_TEMPERATURE_OFFSETT_mg;

typedef int VECTORCAST_MARKER__MACRO_START_CW_WAIT_FOR_SPI_TIMOUT;
200
typedef int VECTORCAST_MARKER__MACRO_END_CW_WAIT_FOR_SPI_TIMOUT;

typedef int VECTORCAST_MARKER__MACRO_START_CW_WAIT_FOR_STANDBY;
1000
typedef int VECTORCAST_MARKER__MACRO_END_CW_WAIT_FOR_STANDBY;

typedef int VECTORCAST_MARKER__MACRO_START_CW_chksum2000_FEEF_END;
0xFEEFU
typedef int VECTORCAST_MARKER__MACRO_END_CW_chksum2000_FEEF_END;

typedef int VECTORCAST_MARKER__MACRO_START_CW_chksum2000_FEEF_START;
0x2000U
typedef int VECTORCAST_MARKER__MACRO_END_CW_chksum2000_FEEF_START;

typedef int VECTORCAST_MARKER__MACRO_START_CemCem_Lin1Fr01_CEM_LIN1_ind_b;
uLinIndicationFlags . w[0]. b6
typedef int VECTORCAST_MARKER__MACRO_END_CemCem_Lin1Fr01_CEM_LIN1_ind_b;

typedef int VECTORCAST_MARKER__MACRO_START_CemCem_Lin1Fr02_CEM_LIN1_ind_b;
uLinIndicationFlags . w[0]. b5
typedef int VECTORCAST_MARKER__MACRO_END_CemCem_Lin1Fr02_CEM_LIN1_ind_b;

typedef int VECTORCAST_MARKER__MACRO_START_CemCem_Lin1Fr03_CEM_LIN1_ind_b;
uLinIndicationFlags . w[0]. b4
typedef int VECTORCAST_MARKER__MACRO_END_CemCem_Lin1Fr03_CEM_LIN1_ind_b;

typedef int VECTORCAST_MARKER__MACRO_START_CemCem_Lin1Fr04_CEM_LIN1_ind_b;
uLinIndicationFlags . w[0]. b3
typedef int VECTORCAST_MARKER__MACRO_END_CemCem_Lin1Fr04_CEM_LIN1_ind_b;

typedef int VECTORCAST_MARKER__MACRO_START_CemCem_Lin1Fr05_CEM_LIN1_ind_b;
uLinIndicationFlags . w[0]. b2
typedef int VECTORCAST_MARKER__MACRO_END_CemCem_Lin1Fr05_CEM_LIN1_ind_b;

typedef int VECTORCAST_MARKER__MACRO_START_CemCem_Lin1Fr06_CEM_LIN1_ind_b;
uLinIndicationFlags . w[0]. b1
typedef int VECTORCAST_MARKER__MACRO_END_CemCem_Lin1Fr06_CEM_LIN1_ind_b;

typedef int VECTORCAST_MARKER__MACRO_START_CmptFrntWindDewT_CEM_LIN1_0;
RlsmCem_Lin1Fr02_CEM_LIN1 . rlsmcem_lin1fr02_cem_lin1 . CmptFrntWindDewT_CEM_LIN1_0
typedef int VECTORCAST_MARKER__MACRO_END_CmptFrntWindDewT_CEM_LIN1_0;

typedef int VECTORCAST_MARKER__MACRO_START_CmptFrntWindDewT_CEM_LIN1_1;
RlsmCem_Lin1Fr02_CEM_LIN1 . rlsmcem_lin1fr02_cem_lin1 . CmptFrntWindDewT_CEM_LIN1_1
typedef int VECTORCAST_MARKER__MACRO_END_CmptFrntWindDewT_CEM_LIN1_1;

typedef int VECTORCAST_MARKER__MACRO_START_CmptFrntWindT_CEM_LIN1_0;
RlsmCem_Lin1Fr02_CEM_LIN1 . rlsmcem_lin1fr02_cem_lin1 . CmptFrntWindT_CEM_LIN1_0
typedef int VECTORCAST_MARKER__MACRO_END_CmptFrntWindT_CEM_LIN1_0;

typedef int VECTORCAST_MARKER__MACRO_START_CmptFrntWindT_CEM_LIN1_1;
RlsmCem_Lin1Fr02_CEM_LIN1 . rlsmcem_lin1fr02_cem_lin1 . CmptFrntWindT_CEM_LIN1_1
typedef int VECTORCAST_MARKER__MACRO_END_CmptFrntWindT_CEM_LIN1_1;

typedef int VECTORCAST_MARKER__MACRO_START_EnaOfflineMonitor_CEM_LIN1;
CemCem_Lin1Fr05_CEM_LIN1 . cemcem_lin1fr05_cem_lin1 . EnaOfflineMonitor_CEM_LIN1
typedef int VECTORCAST_MARKER__MACRO_END_EnaOfflineMonitor_CEM_LIN1;

typedef int VECTORCAST_MARKER__MACRO_START_ErrRespRLSM_CEM_LIN1;
RlsmCem_Lin1Fr01_CEM_LIN1 . rlsmcem_lin1fr01_cem_lin1 . ErrRespRLSM_CEM_LIN1
typedef int VECTORCAST_MARKER__MACRO_END_ErrRespRLSM_CEM_LIN1;

typedef int VECTORCAST_MARKER__MACRO_START_FrqCfg_CEM_LIN1;
CemCem_Lin1Fr03_CEM_LIN1 . cemcem_lin1fr03_cem_lin1 . FrqCfg_CEM_LIN1
typedef int VECTORCAST_MARKER__MACRO_END_FrqCfg_CEM_LIN1;

typedef int VECTORCAST_MARKER__MACRO_START_G5_APPLI_MAIN_H;

typedef int VECTORCAST_MARKER__MACRO_END_G5_APPLI_MAIN_H;

typedef int VECTORCAST_MARKER__MACRO_START_G5_APPLI_TIMER_H;

typedef int VECTORCAST_MARKER__MACRO_END_G5_APPLI_TIMER_H;

typedef int VECTORCAST_MARKER__MACRO_START_G5_ASIC_CONTROL_H;

typedef int VECTORCAST_MARKER__MACRO_END_G5_ASIC_CONTROL_H;

typedef int VECTORCAST_MARKER__MACRO_START_G5_ASIC_CONTROL_SR_H;

typedef int VECTORCAST_MARKER__MACRO_END_G5_ASIC_CONTROL_SR_H;

typedef int VECTORCAST_MARKER__MACRO_START_G5_ASIC_FRAMES_LIN;

typedef int VECTORCAST_MARKER__MACRO_END_G5_ASIC_FRAMES_LIN;

typedef int VECTORCAST_MARKER__MACRO_START_G5_CHECK_SR_H;

typedef int VECTORCAST_MARKER__MACRO_END_G5_CHECK_SR_H;

typedef int VECTORCAST_MARKER__MACRO_START_G5_DIAGE2MAPPING_AD_H;

typedef int VECTORCAST_MARKER__MACRO_END_G5_DIAGE2MAPPING_AD_H;

typedef int VECTORCAST_MARKER__MACRO_START_G5_DIAGE2MAPPING_RD_H;

typedef int VECTORCAST_MARKER__MACRO_END_G5_DIAGE2MAPPING_RD_H;

typedef int VECTORCAST_MARKER__MACRO_START_G5_DIAGNOSE_PROJECTCONFIG_H;

typedef int VECTORCAST_MARKER__MACRO_END_G5_DIAGNOSE_PROJECTCONFIG_H;

typedef int VECTORCAST_MARKER__MACRO_START_G5_DIPPED_BEAM_SR_H;

typedef int VECTORCAST_MARKER__MACRO_END_G5_DIPPED_BEAM_SR_H;

typedef int VECTORCAST_MARKER__MACRO_START_G5_E2HANDLER_H;

typedef int VECTORCAST_MARKER__MACRO_END_G5_E2HANDLER_H;

typedef int VECTORCAST_MARKER__MACRO_START_G5_E2PROJECT_CONFIG_h;

typedef int VECTORCAST_MARKER__MACRO_END_G5_E2PROJECT_CONFIG_h;

typedef int VECTORCAST_MARKER__MACRO_START_G5_FLASHE2_H;

typedef int VECTORCAST_MARKER__MACRO_END_G5_FLASHE2_H;

typedef int VECTORCAST_MARKER__MACRO_START_G5_GEELY_DIAGE2MAPPING_PD_H;

typedef int VECTORCAST_MARKER__MACRO_END_G5_GEELY_DIAGE2MAPPING_PD_H;

typedef int VECTORCAST_MARKER__MACRO_START_G5_IO_H;

typedef int VECTORCAST_MARKER__MACRO_END_G5_IO_H;

typedef int VECTORCAST_MARKER__MACRO_START_G5_IO_SEN_H;

typedef int VECTORCAST_MARKER__MACRO_END_G5_IO_SEN_H;

typedef int VECTORCAST_MARKER__MACRO_START_G5_IRLIGHT_H;

typedef int VECTORCAST_MARKER__MACRO_END_G5_IRLIGHT_H;

typedef int VECTORCAST_MARKER__MACRO_START_G5_LINSCI_SR_H;

typedef int VECTORCAST_MARKER__MACRO_END_G5_LINSCI_SR_H;

typedef int VECTORCAST_MARKER__MACRO_START_G5_PROJECT_DEFS_H;

typedef int VECTORCAST_MARKER__MACRO_END_G5_PROJECT_DEFS_H;

typedef int VECTORCAST_MARKER__MACRO_START_G5_RAINSENS_H;

typedef int VECTORCAST_MARKER__MACRO_END_G5_RAINSENS_H;

typedef int VECTORCAST_MARKER__MACRO_START_G5_RLS_LINST_H;

typedef int VECTORCAST_MARKER__MACRO_END_G5_RLS_LINST_H;

typedef int VECTORCAST_MARKER__MACRO_START_G5_RS_EXT_H;

typedef int VECTORCAST_MARKER__MACRO_END_G5_RS_EXT_H;

typedef int VECTORCAST_MARKER__MACRO_START_G5_RS_TASK_H;

typedef int VECTORCAST_MARKER__MACRO_END_G5_RS_TASK_H;

typedef int VECTORCAST_MARKER__MACRO_START_G5_SPI_SR_H;

typedef int VECTORCAST_MARKER__MACRO_END_G5_SPI_SR_H;

typedef int VECTORCAST_MARKER__MACRO_START_G5_UTILITIES_H;

typedef int VECTORCAST_MARKER__MACRO_END_G5_UTILITIES_H;

typedef int VECTORCAST_MARKER__MACRO_START_G6_Standby;

typedef int VECTORCAST_MARKER__MACRO_END_G6_Standby;

typedef int VECTORCAST_MARKER__MACRO_START_GAINOFFSET_ADDRESS;
(unsigned int)(791)
typedef int VECTORCAST_MARKER__MACRO_END_GAINOFFSET_ADDRESS;

typedef int VECTORCAST_MARKER__MACRO_START_HIGH;
1
typedef int VECTORCAST_MARKER__MACRO_END_HIGH;

typedef int VECTORCAST_MARKER__MACRO_START_HUD_FUNCTION;

typedef int VECTORCAST_MARKER__MACRO_END_HUD_FUNCTION;

typedef int VECTORCAST_MARKER__MACRO_START_HomeLinkEna_CEM_LIN1;
CemCem_Lin1Fr01_CEM_LIN1 . cemcem_lin1fr01_cem_lin1 . HomeLinkEna_CEM_LIN1
typedef int VECTORCAST_MARKER__MACRO_END_HomeLinkEna_CEM_LIN1;

typedef int VECTORCAST_MARKER__MACRO_START_HudSnsrErrParChk_CEM_LIN1;
RlsmCem_Lin1Fr01_CEM_LIN1 . rlsmcem_lin1fr01_cem_lin1 . HudSnsrErrParChk_CEM_LIN1
typedef int VECTORCAST_MARKER__MACRO_END_HudSnsrErrParChk_CEM_LIN1;

typedef int VECTORCAST_MARKER__MACRO_START_HudSnsrErrSnsrErr_CEM_LIN1;
RlsmCem_Lin1Fr01_CEM_LIN1 . rlsmcem_lin1fr01_cem_lin1 . HudSnsrErrSnsrErr_CEM_LIN1
typedef int VECTORCAST_MARKER__MACRO_END_HudSnsrErrSnsrErr_CEM_LIN1;

typedef int VECTORCAST_MARKER__MACRO_START_IDX_ACTR_REG;
0x3
typedef int VECTORCAST_MARKER__MACRO_END_IDX_ACTR_REG;

typedef int VECTORCAST_MARKER__MACRO_START_IDX_ADCVH_REG;
0x18
typedef int VECTORCAST_MARKER__MACRO_END_IDX_ADCVH_REG;

typedef int VECTORCAST_MARKER__MACRO_START_IDX_ADCVL_REG;
0x19
typedef int VECTORCAST_MARKER__MACRO_END_IDX_ADCVL_REG;

typedef int VECTORCAST_MARKER__MACRO_START_IDX_AFSTHR_REG;
0x17
typedef int VECTORCAST_MARKER__MACRO_END_IDX_AFSTHR_REG;

typedef int VECTORCAST_MARKER__MACRO_START_IDX_ALS1_AD;
0
typedef int VECTORCAST_MARKER__MACRO_END_IDX_ALS1_AD;

typedef int VECTORCAST_MARKER__MACRO_START_IDX_ALS2_AD;
1
typedef int VECTORCAST_MARKER__MACRO_END_IDX_ALS2_AD;

typedef int VECTORCAST_MARKER__MACRO_START_IDX_ALS5_AD;
4
typedef int VECTORCAST_MARKER__MACRO_END_IDX_ALS5_AD;

typedef int VECTORCAST_MARKER__MACRO_START_IDX_ALS6_AD;
5
typedef int VECTORCAST_MARKER__MACRO_END_IDX_ALS6_AD;

typedef int VECTORCAST_MARKER__MACRO_START_IDX_AVGVH_REG;
0x1A
typedef int VECTORCAST_MARKER__MACRO_END_IDX_AVGVH_REG;

typedef int VECTORCAST_MARKER__MACRO_START_IDX_AVGVL_REG;
0x1B
typedef int VECTORCAST_MARKER__MACRO_END_IDX_AVGVL_REG;

typedef int VECTORCAST_MARKER__MACRO_START_IDX_CAL_ICALHI_IHI_GHI_AD;
5
typedef int VECTORCAST_MARKER__MACRO_END_IDX_CAL_ICALHI_IHI_GHI_AD;

typedef int VECTORCAST_MARKER__MACRO_START_IDX_CAL_ICALHI_IHI_GHI_INC_AD;
9
typedef int VECTORCAST_MARKER__MACRO_END_IDX_CAL_ICALHI_IHI_GHI_INC_AD;

typedef int VECTORCAST_MARKER__MACRO_START_IDX_CAL_ICALLO_ILO_GHI_AD;
4
typedef int VECTORCAST_MARKER__MACRO_END_IDX_CAL_ICALLO_ILO_GHI_AD;

typedef int VECTORCAST_MARKER__MACRO_START_IDX_CAL_IHI_ICALHI_GHI_AD;
3
typedef int VECTORCAST_MARKER__MACRO_END_IDX_CAL_IHI_ICALHI_GHI_AD;

typedef int VECTORCAST_MARKER__MACRO_START_IDX_CAL_IHI_ICALHI_GHI_INC_AD;
8
typedef int VECTORCAST_MARKER__MACRO_END_IDX_CAL_IHI_ICALHI_GHI_INC_AD;

typedef int VECTORCAST_MARKER__MACRO_START_IDX_CAL_IHI_ILO_GLO_AD;
1
typedef int VECTORCAST_MARKER__MACRO_END_IDX_CAL_IHI_ILO_GLO_AD;

typedef int VECTORCAST_MARKER__MACRO_START_IDX_CAL_IHI_ILO_GLO_INC_AD;
7
typedef int VECTORCAST_MARKER__MACRO_END_IDX_CAL_IHI_ILO_GLO_INC_AD;

typedef int VECTORCAST_MARKER__MACRO_START_IDX_CAL_ILO_ICALLO_GHI_AD;
2
typedef int VECTORCAST_MARKER__MACRO_END_IDX_CAL_ILO_ICALLO_GHI_AD;

typedef int VECTORCAST_MARKER__MACRO_START_IDX_CAL_ILO_IHI_GLO_AD;
0
typedef int VECTORCAST_MARKER__MACRO_END_IDX_CAL_ILO_IHI_GLO_AD;

typedef int VECTORCAST_MARKER__MACRO_START_IDX_CAL_ILO_IHI_GLO_INC_AD;
6
typedef int VECTORCAST_MARKER__MACRO_END_IDX_CAL_ILO_IHI_GLO_INC_AD;

typedef int VECTORCAST_MARKER__MACRO_START_IDX_DIAGV_REG;
0xF
typedef int VECTORCAST_MARKER__MACRO_END_IDX_DIAGV_REG;

typedef int VECTORCAST_MARKER__MACRO_START_IDX_GCTR_REG;
0x0
typedef int VECTORCAST_MARKER__MACRO_END_IDX_GCTR_REG;

typedef int VECTORCAST_MARKER__MACRO_START_IDX_HCTR_REG;
0x1
typedef int VECTORCAST_MARKER__MACRO_END_IDX_HCTR_REG;

typedef int VECTORCAST_MARKER__MACRO_START_IDX_ICO1H_REG;
0x7
typedef int VECTORCAST_MARKER__MACRO_END_IDX_ICO1H_REG;

typedef int VECTORCAST_MARKER__MACRO_START_IDX_ICO1L_REG;
0x8
typedef int VECTORCAST_MARKER__MACRO_END_IDX_ICO1L_REG;

typedef int VECTORCAST_MARKER__MACRO_START_IDX_ICO2H_REG;
0x9
typedef int VECTORCAST_MARKER__MACRO_END_IDX_ICO2H_REG;

typedef int VECTORCAST_MARKER__MACRO_START_IDX_ICO2L_REG;
0xA
typedef int VECTORCAST_MARKER__MACRO_END_IDX_ICO2L_REG;

typedef int VECTORCAST_MARKER__MACRO_START_IDX_INREC_AD;
6
typedef int VECTORCAST_MARKER__MACRO_END_IDX_INREC_AD;

typedef int VECTORCAST_MARKER__MACRO_START_IDX_INTCO_REG;
0x16
typedef int VECTORCAST_MARKER__MACRO_END_IDX_INTCO_REG;

typedef int VECTORCAST_MARKER__MACRO_START_IDX_INTVH_REG;
0x14
typedef int VECTORCAST_MARKER__MACRO_END_IDX_INTVH_REG;

typedef int VECTORCAST_MARKER__MACRO_START_IDX_INTVL_REG;
0x15
typedef int VECTORCAST_MARKER__MACRO_END_IDX_INTVL_REG;

typedef int VECTORCAST_MARKER__MACRO_START_IDX_INVALID_AD;
255
typedef int VECTORCAST_MARKER__MACRO_END_IDX_INVALID_AD;

typedef int VECTORCAST_MARKER__MACRO_START_IDX_LCTR_REG;
0x4
typedef int VECTORCAST_MARKER__MACRO_END_IDX_LCTR_REG;

typedef int VECTORCAST_MARKER__MACRO_START_IDX_MCTR_REG;
0x2
typedef int VECTORCAST_MARKER__MACRO_END_IDX_MCTR_REG;

typedef int VECTORCAST_MARKER__MACRO_START_IDX_PCO_REG;
0x6
typedef int VECTORCAST_MARKER__MACRO_END_IDX_PCO_REG;

typedef int VECTORCAST_MARKER__MACRO_START_IDX_RCTR_REG;
0x5
typedef int VECTORCAST_MARKER__MACRO_END_IDX_RCTR_REG;

typedef int VECTORCAST_MARKER__MACRO_START_IDX_REGVH_REG;
0xD
typedef int VECTORCAST_MARKER__MACRO_END_IDX_REGVH_REG;

typedef int VECTORCAST_MARKER__MACRO_START_IDX_REGVL_REG;
0xE
typedef int VECTORCAST_MARKER__MACRO_END_IDX_REGVL_REG;

typedef int VECTORCAST_MARKER__MACRO_START_IDX_RFCTR_REG;
0x13
typedef int VECTORCAST_MARKER__MACRO_END_IDX_RFCTR_REG;

typedef int VECTORCAST_MARKER__MACRO_START_IDX_RREGH_REG;
0xB
typedef int VECTORCAST_MARKER__MACRO_END_IDX_RREGH_REG;

typedef int VECTORCAST_MARKER__MACRO_START_IDX_RREGL_REG;
0xC
typedef int VECTORCAST_MARKER__MACRO_END_IDX_RREGL_REG;

typedef int VECTORCAST_MARKER__MACRO_START_IDX_RSI_AD;
0
typedef int VECTORCAST_MARKER__MACRO_END_IDX_RSI_AD;

typedef int VECTORCAST_MARKER__MACRO_START_IDX_STATH_REG;
0x10
typedef int VECTORCAST_MARKER__MACRO_END_IDX_STATH_REG;

typedef int VECTORCAST_MARKER__MACRO_START_IDX_STATL_REG;
0x11
typedef int VECTORCAST_MARKER__MACRO_END_IDX_STATL_REG;

typedef int VECTORCAST_MARKER__MACRO_START_IDX_TRIM_REG;
0x12
typedef int VECTORCAST_MARKER__MACRO_END_IDX_TRIM_REG;

typedef int VECTORCAST_MARKER__MACRO_START_IDX_VDDA_AD;
7
typedef int VECTORCAST_MARKER__MACRO_END_IDX_VDDA_AD;

typedef int VECTORCAST_MARKER__MACRO_START_IDX_VDDD_AD;
8
typedef int VECTORCAST_MARKER__MACRO_END_IDX_VDDD_AD;

typedef int VECTORCAST_MARKER__MACRO_START_IDX_VDIAG_LEDA_AD;
1
typedef int VECTORCAST_MARKER__MACRO_END_IDX_VDIAG_LEDA_AD;

typedef int VECTORCAST_MARKER__MACRO_START_IDX_VDIAG_LEDB_AD;
2
typedef int VECTORCAST_MARKER__MACRO_END_IDX_VDIAG_LEDB_AD;

typedef int VECTORCAST_MARKER__MACRO_START_IDX_VIREF_HI_AD;
6
typedef int VECTORCAST_MARKER__MACRO_END_IDX_VIREF_HI_AD;

typedef int VECTORCAST_MARKER__MACRO_START_IDX_VIREF_LO_AD;
5
typedef int VECTORCAST_MARKER__MACRO_END_IDX_VIREF_LO_AD;

typedef int VECTORCAST_MARKER__MACRO_START_IDX_VREF_AD;
4
typedef int VECTORCAST_MARKER__MACRO_END_IDX_VREF_AD;

typedef int VECTORCAST_MARKER__MACRO_START_IDX_VTEMP_AD;
3
typedef int VECTORCAST_MARKER__MACRO_END_IDX_VTEMP_AD;

typedef int VECTORCAST_MARKER__MACRO_START_INIT_E2VARIABLES;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_INIT_E2VARIABLES;

typedef int VECTORCAST_MARKER__MACRO_START_INPUT;
1
typedef int VECTORCAST_MARKER__MACRO_END_INPUT;

typedef int VECTORCAST_MARKER__MACRO_START_INTAD_vect;
(0x34)
typedef int VECTORCAST_MARKER__MACRO_END_INTAD_vect;

typedef int VECTORCAST_MARKER__MACRO_START_INTCSI00_vect;
(0x1E)
typedef int VECTORCAST_MARKER__MACRO_END_INTCSI00_vect;

typedef int VECTORCAST_MARKER__MACRO_START_INTCSI11_vect;
(0x26)
typedef int VECTORCAST_MARKER__MACRO_END_INTCSI11_vect;

typedef int VECTORCAST_MARKER__MACRO_START_INTCSI20_vect;
(0x14)
typedef int VECTORCAST_MARKER__MACRO_END_INTCSI20_vect;

typedef int VECTORCAST_MARKER__MACRO_START_INTCSIS0_vect;
(0x3C)
typedef int VECTORCAST_MARKER__MACRO_END_INTCSIS0_vect;

typedef int VECTORCAST_MARKER__MACRO_START_INTDBG_vect;
(0x02)
typedef int VECTORCAST_MARKER__MACRO_END_INTDBG_vect;

typedef int VECTORCAST_MARKER__MACRO_START_INTDMA0_vect;
(0x1A)
typedef int VECTORCAST_MARKER__MACRO_END_INTDMA0_vect;

typedef int VECTORCAST_MARKER__MACRO_START_INTDMA1_vect;
(0x1C)
typedef int VECTORCAST_MARKER__MACRO_END_INTDMA1_vect;

typedef int VECTORCAST_MARKER__MACRO_START_INTFL_vect;
(0x62)
typedef int VECTORCAST_MARKER__MACRO_END_INTFL_vect;

typedef int VECTORCAST_MARKER__MACRO_START_INTIIC00_vect;
(0x1E)
typedef int VECTORCAST_MARKER__MACRO_END_INTIIC00_vect;

typedef int VECTORCAST_MARKER__MACRO_START_INTIIC11_vect;
(0x26)
typedef int VECTORCAST_MARKER__MACRO_END_INTIIC11_vect;

typedef int VECTORCAST_MARKER__MACRO_START_INTIIC20_vect;
(0x14)
typedef int VECTORCAST_MARKER__MACRO_END_INTIIC20_vect;

typedef int VECTORCAST_MARKER__MACRO_START_INTIICA0_vect;
(0x2A)
typedef int VECTORCAST_MARKER__MACRO_END_INTIICA0_vect;

typedef int VECTORCAST_MARKER__MACRO_START_INTIT_vect;
(0x38)
typedef int VECTORCAST_MARKER__MACRO_END_INTIT_vect;

typedef int VECTORCAST_MARKER__MACRO_START_INTLR_vect;
(0x4E)
typedef int VECTORCAST_MARKER__MACRO_END_INTLR_vect;

typedef int VECTORCAST_MARKER__MACRO_START_INTLS_vect;
(0x50)
typedef int VECTORCAST_MARKER__MACRO_END_INTLS_vect;

typedef int VECTORCAST_MARKER__MACRO_START_INTLT_vect;
(0x4C)
typedef int VECTORCAST_MARKER__MACRO_END_INTLT_vect;

typedef int VECTORCAST_MARKER__MACRO_START_INTLVI_vect;
(0x06)
typedef int VECTORCAST_MARKER__MACRO_END_INTLVI_vect;

typedef int VECTORCAST_MARKER__MACRO_START_INTMD_vect;
(0x5E)
typedef int VECTORCAST_MARKER__MACRO_END_INTMD_vect;

typedef int VECTORCAST_MARKER__MACRO_START_INTP0_vect;
(0x08)
typedef int VECTORCAST_MARKER__MACRO_END_INTP0_vect;

typedef int VECTORCAST_MARKER__MACRO_START_INTP1_vect;
(0x0A)
typedef int VECTORCAST_MARKER__MACRO_END_INTP1_vect;

typedef int VECTORCAST_MARKER__MACRO_START_INTP2_vect;
(0x0C)
typedef int VECTORCAST_MARKER__MACRO_END_INTP2_vect;

typedef int VECTORCAST_MARKER__MACRO_START_INTP3_vect;
(0x0E)
typedef int VECTORCAST_MARKER__MACRO_END_INTP3_vect;

typedef int VECTORCAST_MARKER__MACRO_START_INTP4_vect;
(0x10)
typedef int VECTORCAST_MARKER__MACRO_END_INTP4_vect;

typedef int VECTORCAST_MARKER__MACRO_START_INTP5_vect;
(0x12)
typedef int VECTORCAST_MARKER__MACRO_END_INTP5_vect;

typedef int VECTORCAST_MARKER__MACRO_START_INTRTC_vect;
(0x36)
typedef int VECTORCAST_MARKER__MACRO_END_INTRTC_vect;

typedef int VECTORCAST_MARKER__MACRO_START_INTSR0_vect;
(0x20)
typedef int VECTORCAST_MARKER__MACRO_END_INTSR0_vect;

typedef int VECTORCAST_MARKER__MACRO_START_INTSR1_vect;
(0x26)
typedef int VECTORCAST_MARKER__MACRO_END_INTSR1_vect;

typedef int VECTORCAST_MARKER__MACRO_START_INTSR2_vect;
(0x16)
typedef int VECTORCAST_MARKER__MACRO_END_INTSR2_vect;

typedef int VECTORCAST_MARKER__MACRO_START_INTSRE0_vect;
(0x22)
typedef int VECTORCAST_MARKER__MACRO_END_INTSRE0_vect;

typedef int VECTORCAST_MARKER__MACRO_START_INTSRE1_vect;
(0x28)
typedef int VECTORCAST_MARKER__MACRO_END_INTSRE1_vect;

typedef int VECTORCAST_MARKER__MACRO_START_INTSRE2_vect;
(0x18)
typedef int VECTORCAST_MARKER__MACRO_END_INTSRE2_vect;

typedef int VECTORCAST_MARKER__MACRO_START_INTSRES0_vect;
(0x52)
typedef int VECTORCAST_MARKER__MACRO_END_INTSRES0_vect;

typedef int VECTORCAST_MARKER__MACRO_START_INTSRS0_vect;
(0x3E)
typedef int VECTORCAST_MARKER__MACRO_END_INTSRS0_vect;

typedef int VECTORCAST_MARKER__MACRO_START_INTST0_vect;
(0x1E)
typedef int VECTORCAST_MARKER__MACRO_END_INTST0_vect;

typedef int VECTORCAST_MARKER__MACRO_START_INTST1_vect;
(0x24)
typedef int VECTORCAST_MARKER__MACRO_END_INTST1_vect;

typedef int VECTORCAST_MARKER__MACRO_START_INTST2_vect;
(0x14)
typedef int VECTORCAST_MARKER__MACRO_END_INTST2_vect;

typedef int VECTORCAST_MARKER__MACRO_START_INTSTS0_vect;
(0x3C)
typedef int VECTORCAST_MARKER__MACRO_END_INTSTS0_vect;

typedef int VECTORCAST_MARKER__MACRO_START_INTTM00_vect;
(0x2C)
typedef int VECTORCAST_MARKER__MACRO_END_INTTM00_vect;

typedef int VECTORCAST_MARKER__MACRO_START_INTTM01H_vect;
(0x22)
typedef int VECTORCAST_MARKER__MACRO_END_INTTM01H_vect;

typedef int VECTORCAST_MARKER__MACRO_START_INTTM01_vect;
(0x2E)
typedef int VECTORCAST_MARKER__MACRO_END_INTTM01_vect;

typedef int VECTORCAST_MARKER__MACRO_START_INTTM02_vect;
(0x30)
typedef int VECTORCAST_MARKER__MACRO_END_INTTM02_vect;

typedef int VECTORCAST_MARKER__MACRO_START_INTTM03H_vect;
(0x28)
typedef int VECTORCAST_MARKER__MACRO_END_INTTM03H_vect;

typedef int VECTORCAST_MARKER__MACRO_START_INTTM03_vect;
(0x32)
typedef int VECTORCAST_MARKER__MACRO_END_INTTM03_vect;

typedef int VECTORCAST_MARKER__MACRO_START_INTTM04_vect;
(0x42)
typedef int VECTORCAST_MARKER__MACRO_END_INTTM04_vect;

typedef int VECTORCAST_MARKER__MACRO_START_INTTM05_vect;
(0x44)
typedef int VECTORCAST_MARKER__MACRO_END_INTTM05_vect;

typedef int VECTORCAST_MARKER__MACRO_START_INTTM06_vect;
(0x46)
typedef int VECTORCAST_MARKER__MACRO_END_INTTM06_vect;

typedef int VECTORCAST_MARKER__MACRO_START_INTTM07_vect;
(0x48)
typedef int VECTORCAST_MARKER__MACRO_END_INTTM07_vect;

typedef int VECTORCAST_MARKER__MACRO_START_INTWDTI_vect;
(0x04)
typedef int VECTORCAST_MARKER__MACRO_END_INTWDTI_vect;

typedef int VECTORCAST_MARKER__MACRO_START_INTWUTM_vect;
(0x40)
typedef int VECTORCAST_MARKER__MACRO_END_INTWUTM_vect;

typedef int VECTORCAST_MARKER__MACRO_START_I_LINCONF_H;

typedef int VECTORCAST_MARKER__MACRO_END_I_LINCONF_H;

typedef int VECTORCAST_MARKER__MACRO_START_I_LININC_H;

typedef int VECTORCAST_MARKER__MACRO_END_I_LININC_H;

typedef int VECTORCAST_MARKER__MACRO_START_I_LIN_RLS_H;

typedef int VECTORCAST_MARKER__MACRO_END_I_LIN_RLS_H;

typedef int VECTORCAST_MARKER__MACRO_START_IntrMirrCmdDrvrSide_CEM_LIN1;
CemCem_Lin1Fr01_CEM_LIN1 . cemcem_lin1fr01_cem_lin1 . IntrMirrCmdDrvrSide_CEM_LIN1
typedef int VECTORCAST_MARKER__MACRO_END_IntrMirrCmdDrvrSide_CEM_LIN1;

typedef int VECTORCAST_MARKER__MACRO_START_IntrMirrCmdIntrMirrAsyFanCmpMag_CEM_LIN1;
CemCem_Lin1Fr01_CEM_LIN1 . cemcem_lin1fr01_cem_lin1 . IntrMirrCmdIntrMirrAsyFanCmpMag_CEM_LIN1
typedef int VECTORCAST_MARKER__MACRO_END_IntrMirrCmdIntrMirrAsyFanCmpMag_CEM_LIN1;

typedef int VECTORCAST_MARKER__MACRO_START_IntrMirrCmdIntrMirrDiagcRst_CEM_LIN1;
CemCem_Lin1Fr01_CEM_LIN1 . cemcem_lin1fr01_cem_lin1 . IntrMirrCmdIntrMirrDiagcRst_CEM_LIN1
typedef int VECTORCAST_MARKER__MACRO_END_IntrMirrCmdIntrMirrDiagcRst_CEM_LIN1;

typedef int VECTORCAST_MARKER__MACRO_START_IntrMirrCmdIntrMirrDimSnvty_CEM_LIN1;
CemCem_Lin1Fr01_CEM_LIN1 . cemcem_lin1fr01_cem_lin1 . IntrMirrCmdIntrMirrDimSnvty_CEM_LIN1
typedef int VECTORCAST_MARKER__MACRO_END_IntrMirrCmdIntrMirrDimSnvty_CEM_LIN1;

typedef int VECTORCAST_MARKER__MACRO_START_IntrMirrCmdIntrMirrEna_CEM_LIN1;
CemCem_Lin1Fr01_CEM_LIN1 . cemcem_lin1fr01_cem_lin1 . IntrMirrCmdIntrMirrEna_CEM_LIN1
typedef int VECTORCAST_MARKER__MACRO_END_IntrMirrCmdIntrMirrEna_CEM_LIN1;

typedef int VECTORCAST_MARKER__MACRO_START_IntrMirrCmdIntrMirrInhbDim_CEM_LIN1;
CemCem_Lin1Fr01_CEM_LIN1 . cemcem_lin1fr01_cem_lin1 . IntrMirrCmdIntrMirrInhbDim_CEM_LIN1
typedef int VECTORCAST_MARKER__MACRO_END_IntrMirrCmdIntrMirrInhbDim_CEM_LIN1;

typedef int VECTORCAST_MARKER__MACRO_START_IntrMirrCmdIntrMirrWindHeatrCmpMag_CEM_LIN1;
CemCem_Lin1Fr01_CEM_LIN1 . cemcem_lin1fr01_cem_lin1 . IntrMirrCmdIntrMirrWindHeatrCmpMag_CEM_LIN1
typedef int VECTORCAST_MARKER__MACRO_END_IntrMirrCmdIntrMirrWindHeatrCmpMag_CEM_LIN1;

typedef int VECTORCAST_MARKER__MACRO_START_LEDx_CNT_ERR_THRS;
(byte)20
typedef int VECTORCAST_MARKER__MACRO_END_LEDx_CNT_ERR_THRS;

typedef int VECTORCAST_MARKER__MACRO_START_LIN20CHECKSUM;

typedef int VECTORCAST_MARKER__MACRO_END_LIN20CHECKSUM;

typedef int VECTORCAST_MARKER__MACRO_START_LINBAUDRATE;
19200
typedef int VECTORCAST_MARKER__MACRO_END_LINBAUDRATE;

typedef int VECTORCAST_MARKER__MACRO_START_LOW;
0
typedef int VECTORCAST_MARKER__MACRO_END_LOW;

typedef int VECTORCAST_MARKER__MACRO_START_LiOprnMod_CEM_LIN1;
RlsmCem_Lin1Fr03_CEM_LIN1 . rlsmcem_lin1fr03_cem_lin1 . LiOprnMod_CEM_LIN1
typedef int VECTORCAST_MARKER__MACRO_END_LiOprnMod_CEM_LIN1;

typedef int VECTORCAST_MARKER__MACRO_START_LinReqCmd_ind_b;
uLinIndicationFlags . w[0]. b0
typedef int VECTORCAST_MARKER__MACRO_END_LinReqCmd_ind_b;

typedef int VECTORCAST_MARKER__MACRO_START_LinRespCmd_conf_b;
uLinConfirmationFlags . w[0]. b0
typedef int VECTORCAST_MARKER__MACRO_END_LinRespCmd_conf_b;

typedef int VECTORCAST_MARKER__MACRO_START_MAX_SPI_NO_COMM_CNT;
0x7F80
typedef int VECTORCAST_MARKER__MACRO_END_MAX_SPI_NO_COMM_CNT;

typedef int VECTORCAST_MARKER__MACRO_START_MEMORY_FAR;

typedef int VECTORCAST_MARKER__MACRO_END_MEMORY_FAR;

typedef int VECTORCAST_MARKER__MACRO_START_MEMORY_NEAR;

typedef int VECTORCAST_MARKER__MACRO_END_MEMORY_NEAR;

typedef int VECTORCAST_MARKER__MACRO_START_MEMORY_ROM;
const
typedef int VECTORCAST_MARKER__MACRO_END_MEMORY_ROM;

typedef int VECTORCAST_MARKER__MACRO_START_MasterReqB0;
LinReqCmd . linreqcmd . MasterReqB0
typedef int VECTORCAST_MARKER__MACRO_END_MasterReqB0;

typedef int VECTORCAST_MARKER__MACRO_START_MasterReqB1;
LinReqCmd . linreqcmd . MasterReqB1
typedef int VECTORCAST_MARKER__MACRO_END_MasterReqB1;

typedef int VECTORCAST_MARKER__MACRO_START_MasterReqB2;
LinReqCmd . linreqcmd . MasterReqB2
typedef int VECTORCAST_MARKER__MACRO_END_MasterReqB2;

typedef int VECTORCAST_MARKER__MACRO_START_MasterReqB3;
LinReqCmd . linreqcmd . MasterReqB3
typedef int VECTORCAST_MARKER__MACRO_END_MasterReqB3;

typedef int VECTORCAST_MARKER__MACRO_START_MasterReqB4;
LinReqCmd . linreqcmd . MasterReqB4
typedef int VECTORCAST_MARKER__MACRO_END_MasterReqB4;

typedef int VECTORCAST_MARKER__MACRO_START_MasterReqB5;
LinReqCmd . linreqcmd . MasterReqB5
typedef int VECTORCAST_MARKER__MACRO_END_MasterReqB5;

typedef int VECTORCAST_MARKER__MACRO_START_MasterReqB6;
LinReqCmd . linreqcmd . MasterReqB6
typedef int VECTORCAST_MARKER__MACRO_END_MasterReqB6;

typedef int VECTORCAST_MARKER__MACRO_START_MasterReqB7;
LinReqCmd . linreqcmd . MasterReqB7
typedef int VECTORCAST_MARKER__MACRO_END_MasterReqB7;

typedef int VECTORCAST_MARKER__MACRO_START_NODECONFIGURATION;

typedef int VECTORCAST_MARKER__MACRO_END_NODECONFIGURATION;

typedef int VECTORCAST_MARKER__MACRO_START_NOM_DELTA_INTV_BYTE_ADDRESS;
(797)
typedef int VECTORCAST_MARKER__MACRO_END_NOM_DELTA_INTV_BYTE_ADDRESS;

typedef int VECTORCAST_MARKER__MACRO_START_NOT_SUPPORT_SERVICE_1519TO1525;

typedef int VECTORCAST_MARKER__MACRO_END_NOT_SUPPORT_SERVICE_1519TO1525;

typedef int VECTORCAST_MARKER__MACRO_START_NO_CURRENT_MEAS;
0xFF
typedef int VECTORCAST_MARKER__MACRO_END_NO_CURRENT_MEAS;

typedef int VECTORCAST_MARKER__MACRO_START_OUTPUT;
0
typedef int VECTORCAST_MARKER__MACRO_END_OUTPUT;

typedef int VECTORCAST_MARKER__MACRO_START_OutdBriChks_CEM_LIN1;
RlsmCem_Lin1Fr01_CEM_LIN1 . rlsmcem_lin1fr01_cem_lin1 . OutdBriChks_CEM_LIN1
typedef int VECTORCAST_MARKER__MACRO_END_OutdBriChks_CEM_LIN1;

typedef int VECTORCAST_MARKER__MACRO_START_OutdBriCntr_CEM_LIN1;
RlsmCem_Lin1Fr01_CEM_LIN1 . rlsmcem_lin1fr01_cem_lin1 . OutdBriCntr_CEM_LIN1
typedef int VECTORCAST_MARKER__MACRO_END_OutdBriCntr_CEM_LIN1;

typedef int VECTORCAST_MARKER__MACRO_START_OutdBriSts_CEM_LIN1;
RlsmCem_Lin1Fr01_CEM_LIN1 . rlsmcem_lin1fr01_cem_lin1 . OutdBriSts_CEM_LIN1
typedef int VECTORCAST_MARKER__MACRO_END_OutdBriSts_CEM_LIN1;

typedef int VECTORCAST_MARKER__MACRO_START_RAIN_INTENSITY;

typedef int VECTORCAST_MARKER__MACRO_END_RAIN_INTENSITY;

typedef int VECTORCAST_MARKER__MACRO_START_RLSMPartNo10EndSgn1_CEM_LIN1;
RlsmCem_Lin1PartNrFr02_CEM_LIN1 . rlsmcem_lin1partnrfr02_cem_lin1 . RLSMPartNo10EndSgn1_CEM_LIN1
typedef int VECTORCAST_MARKER__MACRO_END_RLSMPartNo10EndSgn1_CEM_LIN1;

typedef int VECTORCAST_MARKER__MACRO_START_RLSMPartNo10EndSgn2_CEM_LIN1;
RlsmCem_Lin1PartNrFr02_CEM_LIN1 . rlsmcem_lin1partnrfr02_cem_lin1 . RLSMPartNo10EndSgn2_CEM_LIN1
typedef int VECTORCAST_MARKER__MACRO_END_RLSMPartNo10EndSgn2_CEM_LIN1;

typedef int VECTORCAST_MARKER__MACRO_START_RLSMPartNo10EndSgn3_CEM_LIN1;
RlsmCem_Lin1PartNrFr02_CEM_LIN1 . rlsmcem_lin1partnrfr02_cem_lin1 . RLSMPartNo10EndSgn3_CEM_LIN1
typedef int VECTORCAST_MARKER__MACRO_END_RLSMPartNo10EndSgn3_CEM_LIN1;

typedef int VECTORCAST_MARKER__MACRO_START_RLSMPartNo10Nr1_CEM_LIN1;
RlsmCem_Lin1PartNrFr02_CEM_LIN1 . rlsmcem_lin1partnrfr02_cem_lin1 . RLSMPartNo10Nr1_CEM_LIN1
typedef int VECTORCAST_MARKER__MACRO_END_RLSMPartNo10Nr1_CEM_LIN1;

typedef int VECTORCAST_MARKER__MACRO_START_RLSMPartNo10Nr2_CEM_LIN1;
RlsmCem_Lin1PartNrFr02_CEM_LIN1 . rlsmcem_lin1partnrfr02_cem_lin1 . RLSMPartNo10Nr2_CEM_LIN1
typedef int VECTORCAST_MARKER__MACRO_END_RLSMPartNo10Nr2_CEM_LIN1;

typedef int VECTORCAST_MARKER__MACRO_START_RLSMPartNo10Nr3_CEM_LIN1;
RlsmCem_Lin1PartNrFr02_CEM_LIN1 . rlsmcem_lin1partnrfr02_cem_lin1 . RLSMPartNo10Nr3_CEM_LIN1
typedef int VECTORCAST_MARKER__MACRO_END_RLSMPartNo10Nr3_CEM_LIN1;

typedef int VECTORCAST_MARKER__MACRO_START_RLSMPartNo10Nr4_CEM_LIN1;
RlsmCem_Lin1PartNrFr02_CEM_LIN1 . rlsmcem_lin1partnrfr02_cem_lin1 . RLSMPartNo10Nr4_CEM_LIN1
typedef int VECTORCAST_MARKER__MACRO_END_RLSMPartNo10Nr4_CEM_LIN1;

typedef int VECTORCAST_MARKER__MACRO_START_RLSMPartNo10Nr5_CEM_LIN1;
RlsmCem_Lin1PartNrFr02_CEM_LIN1 . rlsmcem_lin1partnrfr02_cem_lin1 . RLSMPartNo10Nr5_CEM_LIN1
typedef int VECTORCAST_MARKER__MACRO_END_RLSMPartNo10Nr5_CEM_LIN1;

typedef int VECTORCAST_MARKER__MACRO_START_RLSMPartNoEndSgn1_CEM_LIN1;
RlsmCem_Lin1PartNrFr01_CEM_LIN1 . rlsmcem_lin1partnrfr01_cem_lin1 . RLSMPartNoEndSgn1_CEM_LIN1
typedef int VECTORCAST_MARKER__MACRO_END_RLSMPartNoEndSgn1_CEM_LIN1;

typedef int VECTORCAST_MARKER__MACRO_START_RLSMPartNoEndSgn2_CEM_LIN1;
RlsmCem_Lin1PartNrFr01_CEM_LIN1 . rlsmcem_lin1partnrfr01_cem_lin1 . RLSMPartNoEndSgn2_CEM_LIN1
typedef int VECTORCAST_MARKER__MACRO_END_RLSMPartNoEndSgn2_CEM_LIN1;

typedef int VECTORCAST_MARKER__MACRO_START_RLSMPartNoEndSgn3_CEM_LIN1;
RlsmCem_Lin1PartNrFr01_CEM_LIN1 . rlsmcem_lin1partnrfr01_cem_lin1 . RLSMPartNoEndSgn3_CEM_LIN1
typedef int VECTORCAST_MARKER__MACRO_END_RLSMPartNoEndSgn3_CEM_LIN1;

typedef int VECTORCAST_MARKER__MACRO_START_RLSMPartNoNr1_CEM_LIN1;
RlsmCem_Lin1PartNrFr01_CEM_LIN1 . rlsmcem_lin1partnrfr01_cem_lin1 . RLSMPartNoNr1_CEM_LIN1
typedef int VECTORCAST_MARKER__MACRO_END_RLSMPartNoNr1_CEM_LIN1;

typedef int VECTORCAST_MARKER__MACRO_START_RLSMPartNoNr2_CEM_LIN1;
RlsmCem_Lin1PartNrFr01_CEM_LIN1 . rlsmcem_lin1partnrfr01_cem_lin1 . RLSMPartNoNr2_CEM_LIN1
typedef int VECTORCAST_MARKER__MACRO_END_RLSMPartNoNr2_CEM_LIN1;

typedef int VECTORCAST_MARKER__MACRO_START_RLSMPartNoNr3_CEM_LIN1;
RlsmCem_Lin1PartNrFr01_CEM_LIN1 . rlsmcem_lin1partnrfr01_cem_lin1 . RLSMPartNoNr3_CEM_LIN1
typedef int VECTORCAST_MARKER__MACRO_END_RLSMPartNoNr3_CEM_LIN1;

typedef int VECTORCAST_MARKER__MACRO_START_RLSMPartNoNr4_CEM_LIN1;
RlsmCem_Lin1PartNrFr01_CEM_LIN1 . rlsmcem_lin1partnrfr01_cem_lin1 . RLSMPartNoNr4_CEM_LIN1
typedef int VECTORCAST_MARKER__MACRO_END_RLSMPartNoNr4_CEM_LIN1;

typedef int VECTORCAST_MARKER__MACRO_START_RLSMSerNoNr1_CEM_LIN1;
RlsmCem_SerNrLin1Fr01_CEM_LIN1 . rlsmcem_sernrlin1fr01_cem_lin1 . RLSMSerNoNr1_CEM_LIN1
typedef int VECTORCAST_MARKER__MACRO_END_RLSMSerNoNr1_CEM_LIN1;

typedef int VECTORCAST_MARKER__MACRO_START_RLSMSerNoNr2_CEM_LIN1;
RlsmCem_SerNrLin1Fr01_CEM_LIN1 . rlsmcem_sernrlin1fr01_cem_lin1 . RLSMSerNoNr2_CEM_LIN1
typedef int VECTORCAST_MARKER__MACRO_END_RLSMSerNoNr2_CEM_LIN1;

typedef int VECTORCAST_MARKER__MACRO_START_RLSMSerNoNr3_CEM_LIN1;
RlsmCem_SerNrLin1Fr01_CEM_LIN1 . rlsmcem_sernrlin1fr01_cem_lin1 . RLSMSerNoNr3_CEM_LIN1
typedef int VECTORCAST_MARKER__MACRO_END_RLSMSerNoNr3_CEM_LIN1;

typedef int VECTORCAST_MARKER__MACRO_START_RLSMSerNoNr4_CEM_LIN1;
RlsmCem_SerNrLin1Fr01_CEM_LIN1 . rlsmcem_sernrlin1fr01_cem_lin1 . RLSMSerNoNr4_CEM_LIN1
typedef int VECTORCAST_MARKER__MACRO_END_RLSMSerNoNr4_CEM_LIN1;

typedef int VECTORCAST_MARKER__MACRO_START_RSS_INKREMENTWIPE_FIX_CONTINUOUS;

typedef int VECTORCAST_MARKER__MACRO_END_RSS_INKREMENTWIPE_FIX_CONTINUOUS;

typedef int VECTORCAST_MARKER__MACRO_START_RST_vect;
(0x00)
typedef int VECTORCAST_MARKER__MACRO_END_RST_vect;

typedef int VECTORCAST_MARKER__MACRO_START_RainDetected_CEM_LIN1;
RlsmCem_Lin1Fr03_CEM_LIN1 . rlsmcem_lin1fr03_cem_lin1 . RainDetected_CEM_LIN1
typedef int VECTORCAST_MARKER__MACRO_END_RainDetected_CEM_LIN1;

typedef int VECTORCAST_MARKER__MACRO_START_RainLi_CEM_LIN1;
RlsmCem_Lin1Fr01_CEM_LIN1 . rlsmcem_lin1fr01_cem_lin1 . RainLi_CEM_LIN1
typedef int VECTORCAST_MARKER__MACRO_END_RainLi_CEM_LIN1;

typedef int VECTORCAST_MARKER__MACRO_START_RainSensActvn_CEM_LIN1;
CemCem_Lin1Fr01_CEM_LIN1 . cemcem_lin1fr01_cem_lin1 . RainSensActvn_CEM_LIN1
typedef int VECTORCAST_MARKER__MACRO_END_RainSensActvn_CEM_LIN1;

typedef int VECTORCAST_MARKER__MACRO_START_RainSnsrDiagcRainSnsrHiTDetd_CEM_LIN1;
RlsmCem_Lin1Fr03_CEM_LIN1 . rlsmcem_lin1fr03_cem_lin1 . RainSnsrDiagcRainSnsrHiTDetd_CEM_LIN1
typedef int VECTORCAST_MARKER__MACRO_END_RainSnsrDiagcRainSnsrHiTDetd_CEM_LIN1;

typedef int VECTORCAST_MARKER__MACRO_START_RainSnsrDiagcRainSnsrHiVoltDetd_CEM_LIN1;
RlsmCem_Lin1Fr03_CEM_LIN1 . rlsmcem_lin1fr03_cem_lin1 . RainSnsrDiagcRainSnsrHiVoltDetd_CEM_LIN1
typedef int VECTORCAST_MARKER__MACRO_END_RainSnsrDiagcRainSnsrHiVoltDetd_CEM_LIN1;

typedef int VECTORCAST_MARKER__MACRO_START_RainSnsrErrCalErrActv_CEM_LIN1;
RlsmCem_Lin1Fr01_CEM_LIN1 . rlsmcem_lin1fr01_cem_lin1 . RainSnsrErrCalErrActv_CEM_LIN1
typedef int VECTORCAST_MARKER__MACRO_END_RainSnsrErrCalErrActv_CEM_LIN1;

typedef int VECTORCAST_MARKER__MACRO_START_RainSnsrErrCalErr_CEM_LIN1;
RlsmCem_Lin1Fr01_CEM_LIN1 . rlsmcem_lin1fr01_cem_lin1 . RainSnsrErrCalErr_CEM_LIN1
typedef int VECTORCAST_MARKER__MACRO_END_RainSnsrErrCalErr_CEM_LIN1;

typedef int VECTORCAST_MARKER__MACRO_START_RainSnsrErrRainDetnErrActv_CEM_LIN1;
RlsmCem_Lin1Fr01_CEM_LIN1 . rlsmcem_lin1fr01_cem_lin1 . RainSnsrErrRainDetnErrActv_CEM_LIN1
typedef int VECTORCAST_MARKER__MACRO_END_RainSnsrErrRainDetnErrActv_CEM_LIN1;

typedef int VECTORCAST_MARKER__MACRO_START_RainSnsrErrRainDetnErr_CEM_LIN1;
RlsmCem_Lin1Fr01_CEM_LIN1 . rlsmcem_lin1fr01_cem_lin1 . RainSnsrErrRainDetnErr_CEM_LIN1
typedef int VECTORCAST_MARKER__MACRO_END_RainSnsrErrRainDetnErr_CEM_LIN1;

typedef int VECTORCAST_MARKER__MACRO_START_RainSnsrLiThd_CEM_LIN1;
CemCem_Lin1Fr04_CEM_LIN1 . cemcem_lin1fr04_cem_lin1 . RainSnsrLiThd_CEM_LIN1
typedef int VECTORCAST_MARKER__MACRO_END_RainSnsrLiThd_CEM_LIN1;

typedef int VECTORCAST_MARKER__MACRO_START_RainSnsrSnvtyForUsrSnvty0_CEM_LIN1;
CemCem_Lin1Fr03_CEM_LIN1 . cemcem_lin1fr03_cem_lin1 . RainSnsrSnvtyForUsrSnvty0_CEM_LIN1
typedef int VECTORCAST_MARKER__MACRO_END_RainSnsrSnvtyForUsrSnvty0_CEM_LIN1;

typedef int VECTORCAST_MARKER__MACRO_START_RainSnsrSnvtyForUsrSnvty1_CEM_LIN1;
CemCem_Lin1Fr03_CEM_LIN1 . cemcem_lin1fr03_cem_lin1 . RainSnsrSnvtyForUsrSnvty1_CEM_LIN1
typedef int VECTORCAST_MARKER__MACRO_END_RainSnsrSnvtyForUsrSnvty1_CEM_LIN1;

typedef int VECTORCAST_MARKER__MACRO_START_RainSnsrSnvtyForUsrSnvty2_CEM_LIN1;
CemCem_Lin1Fr03_CEM_LIN1 . cemcem_lin1fr03_cem_lin1 . RainSnsrSnvtyForUsrSnvty2_CEM_LIN1
typedef int VECTORCAST_MARKER__MACRO_END_RainSnsrSnvtyForUsrSnvty2_CEM_LIN1;

typedef int VECTORCAST_MARKER__MACRO_START_RainSnsrSnvtyForUsrSnvty3_CEM_LIN1;
CemCem_Lin1Fr03_CEM_LIN1 . cemcem_lin1fr03_cem_lin1 . RainSnsrSnvtyForUsrSnvty3_CEM_LIN1
typedef int VECTORCAST_MARKER__MACRO_END_RainSnsrSnvtyForUsrSnvty3_CEM_LIN1;

typedef int VECTORCAST_MARKER__MACRO_START_RainSnsrSnvtyForUsrSnvty4_CEM_LIN1;
CemCem_Lin1Fr03_CEM_LIN1 . cemcem_lin1fr03_cem_lin1 . RainSnsrSnvtyForUsrSnvty4_CEM_LIN1
typedef int VECTORCAST_MARKER__MACRO_END_RainSnsrSnvtyForUsrSnvty4_CEM_LIN1;

typedef int VECTORCAST_MARKER__MACRO_START_RainSnsrSnvtyForUsrSnvty5_CEM_LIN1;
CemCem_Lin1Fr03_CEM_LIN1 . cemcem_lin1fr03_cem_lin1 . RainSnsrSnvtyForUsrSnvty5_CEM_LIN1
typedef int VECTORCAST_MARKER__MACRO_END_RainSnsrSnvtyForUsrSnvty5_CEM_LIN1;

typedef int VECTORCAST_MARKER__MACRO_START_RainSnsrSnvtyForUsrSnvty6_CEM_LIN1;
CemCem_Lin1Fr03_CEM_LIN1 . cemcem_lin1fr03_cem_lin1 . RainSnsrSnvtyForUsrSnvty6_CEM_LIN1
typedef int VECTORCAST_MARKER__MACRO_END_RainSnsrSnvtyForUsrSnvty6_CEM_LIN1;

typedef int VECTORCAST_MARKER__MACRO_START_RainfallAmnt_CEM_LIN1;
RlsmCem_Lin1Fr03_CEM_LIN1 . rlsmcem_lin1fr03_cem_lin1 . RainfallAmnt_CEM_LIN1
typedef int VECTORCAST_MARKER__MACRO_END_RainfallAmnt_CEM_LIN1;

typedef int VECTORCAST_MARKER__MACRO_START_ReAdaptReq_CEM_LIN1;
CemCem_Lin1Fr03_CEM_LIN1 . cemcem_lin1fr03_cem_lin1 . ReAdaptReq_CEM_LIN1
typedef int VECTORCAST_MARKER__MACRO_END_ReAdaptReq_CEM_LIN1;

typedef int VECTORCAST_MARKER__MACRO_START_RelHumSnsrErr_CEM_LIN1;
RlsmCem_Lin1Fr02_CEM_LIN1 . rlsmcem_lin1fr02_cem_lin1 . RelHumSnsrErr_CEM_LIN1
typedef int VECTORCAST_MARKER__MACRO_END_RelHumSnsrErr_CEM_LIN1;

typedef int VECTORCAST_MARKER__MACRO_START_RelHumSnsrRelHum_CEM_LIN1;
RlsmCem_Lin1Fr02_CEM_LIN1 . rlsmcem_lin1fr02_cem_lin1 . RelHumSnsrRelHum_CEM_LIN1
typedef int VECTORCAST_MARKER__MACRO_END_RelHumSnsrRelHum_CEM_LIN1;

typedef int VECTORCAST_MARKER__MACRO_START_RlsmCem_Lin1Fr01_CEM_LIN1_conf_b;
uLinConfirmationFlags . w[0]. b6
typedef int VECTORCAST_MARKER__MACRO_END_RlsmCem_Lin1Fr01_CEM_LIN1_conf_b;

typedef int VECTORCAST_MARKER__MACRO_START_RlsmCem_Lin1Fr02_CEM_LIN1_conf_b;
uLinConfirmationFlags . w[0]. b5
typedef int VECTORCAST_MARKER__MACRO_END_RlsmCem_Lin1Fr02_CEM_LIN1_conf_b;

typedef int VECTORCAST_MARKER__MACRO_START_RlsmCem_Lin1Fr03_CEM_LIN1_conf_b;
uLinConfirmationFlags . w[0]. b4
typedef int VECTORCAST_MARKER__MACRO_END_RlsmCem_Lin1Fr03_CEM_LIN1_conf_b;

typedef int VECTORCAST_MARKER__MACRO_START_RlsmCem_Lin1PartNrFr01_CEM_LIN1_conf_b;
uLinConfirmationFlags . w[0]. b3
typedef int VECTORCAST_MARKER__MACRO_END_RlsmCem_Lin1PartNrFr01_CEM_LIN1_conf_b;

typedef int VECTORCAST_MARKER__MACRO_START_RlsmCem_Lin1PartNrFr02_CEM_LIN1_conf_b;
uLinConfirmationFlags . w[0]. b2
typedef int VECTORCAST_MARKER__MACRO_END_RlsmCem_Lin1PartNrFr02_CEM_LIN1_conf_b;

typedef int VECTORCAST_MARKER__MACRO_START_RlsmCem_SerNrLin1Fr01_CEM_LIN1_conf_b;
uLinConfirmationFlags . w[0]. b1
typedef int VECTORCAST_MARKER__MACRO_END_RlsmCem_SerNrLin1Fr01_CEM_LIN1_conf_b;

typedef int VECTORCAST_MARKER__MACRO_START_SENSIRION_SHT21_USED;

typedef int VECTORCAST_MARKER__MACRO_END_SENSIRION_SHT21_USED;

typedef int VECTORCAST_MARKER__MACRO_START_SHT_COMM_ERR_RETRY_ATTEMPT;
255
typedef int VECTORCAST_MARKER__MACRO_END_SHT_COMM_ERR_RETRY_ATTEMPT;

typedef int VECTORCAST_MARKER__MACRO_START_SHT_SUPPLY_RETRY_ATTEMPT;
30
typedef int VECTORCAST_MARKER__MACRO_END_SHT_SUPPLY_RETRY_ATTEMPT;

typedef int VECTORCAST_MARKER__MACRO_START_SPI_NO_COMM_INCREMENT;
0x40
typedef int VECTORCAST_MARKER__MACRO_END_SPI_NO_COMM_INCREMENT;

typedef int VECTORCAST_MARKER__MACRO_START_STANDBY_LIN_WAKE_UP_ISSUE;

typedef int VECTORCAST_MARKER__MACRO_END_STANDBY_LIN_WAKE_UP_ISSUE;

typedef int VECTORCAST_MARKER__MACRO_START_STATIC;
static
typedef int VECTORCAST_MARKER__MACRO_END_STATIC;

typedef int VECTORCAST_MARKER__MACRO_START_STBY_DELTA_INTV_HBYTE_ADDRESS;
(770)
typedef int VECTORCAST_MARKER__MACRO_END_STBY_DELTA_INTV_HBYTE_ADDRESS;

typedef int VECTORCAST_MARKER__MACRO_START_STBY_DELTA_INTV_LBYTE_ADDRESS;
(771)
typedef int VECTORCAST_MARKER__MACRO_END_STBY_DELTA_INTV_LBYTE_ADDRESS;

typedef int VECTORCAST_MARKER__MACRO_START_STBY_REGV_HBYTE_ADDRESS;
(768)
typedef int VECTORCAST_MARKER__MACRO_END_STBY_REGV_HBYTE_ADDRESS;

typedef int VECTORCAST_MARKER__MACRO_START_STBY_REGV_LBYTE_ADDRESS;
(769)
typedef int VECTORCAST_MARKER__MACRO_END_STBY_REGV_LBYTE_ADDRESS;

typedef int VECTORCAST_MARKER__MACRO_START_SYSTEM_NAMES_RLS;
{0x01,"GEELY2.0_RS    "}, {0x04,"GEELY2.0_LS    "}, {0x05,"GEELY2.0_RLS   "}, {0x07,"GEELY2.0_RLSS  "}, {0x98,"GEELY2.0_F     "}, {0x8A,"GEELY2.0_FSS   "}, {0x0C,"GEELY2.0_LFS   "}, {0x0D,"GEELY2.0_RLFS  "}, {0x0E,"GEELY2.0_LFSS  "}, {0x0F,"GEELY2.0_RLFSS  "}
typedef int VECTORCAST_MARKER__MACRO_END_SYSTEM_NAMES_RLS;

typedef int VECTORCAST_MARKER__MACRO_START_SlaveRespB0;
LinRespCmd . linrespcmd . SlaveRespB0
typedef int VECTORCAST_MARKER__MACRO_END_SlaveRespB0;

typedef int VECTORCAST_MARKER__MACRO_START_SlaveRespB1;
LinRespCmd . linrespcmd . SlaveRespB1
typedef int VECTORCAST_MARKER__MACRO_END_SlaveRespB1;

typedef int VECTORCAST_MARKER__MACRO_START_SlaveRespB2;
LinRespCmd . linrespcmd . SlaveRespB2
typedef int VECTORCAST_MARKER__MACRO_END_SlaveRespB2;

typedef int VECTORCAST_MARKER__MACRO_START_SlaveRespB3;
LinRespCmd . linrespcmd . SlaveRespB3
typedef int VECTORCAST_MARKER__MACRO_END_SlaveRespB3;

typedef int VECTORCAST_MARKER__MACRO_START_SlaveRespB4;
LinRespCmd . linrespcmd . SlaveRespB4
typedef int VECTORCAST_MARKER__MACRO_END_SlaveRespB4;

typedef int VECTORCAST_MARKER__MACRO_START_SlaveRespB5;
LinRespCmd . linrespcmd . SlaveRespB5
typedef int VECTORCAST_MARKER__MACRO_END_SlaveRespB5;

typedef int VECTORCAST_MARKER__MACRO_START_SlaveRespB6;
LinRespCmd . linrespcmd . SlaveRespB6
typedef int VECTORCAST_MARKER__MACRO_END_SlaveRespB6;

typedef int VECTORCAST_MARKER__MACRO_START_SlaveRespB7;
LinRespCmd . linrespcmd . SlaveRespB7
typedef int VECTORCAST_MARKER__MACRO_END_SlaveRespB7;

typedef int VECTORCAST_MARKER__MACRO_START_SolarSnsrErr_CEM_LIN1;
RlsmCem_Lin1Fr03_CEM_LIN1 . rlsmcem_lin1fr03_cem_lin1 . SolarSnsrErr_CEM_LIN1
typedef int VECTORCAST_MARKER__MACRO_END_SolarSnsrErr_CEM_LIN1;

typedef int VECTORCAST_MARKER__MACRO_START_SolarSnsrLeValue_CEM_LIN1;
RlsmCem_Lin1Fr03_CEM_LIN1 . rlsmcem_lin1fr03_cem_lin1 . SolarSnsrLeValue_CEM_LIN1
typedef int VECTORCAST_MARKER__MACRO_END_SolarSnsrLeValue_CEM_LIN1;

typedef int VECTORCAST_MARKER__MACRO_START_SolarSnsrRiValue_CEM_LIN1;
RlsmCem_Lin1Fr03_CEM_LIN1 . rlsmcem_lin1fr03_cem_lin1 . SolarSnsrRiValue_CEM_LIN1
typedef int VECTORCAST_MARKER__MACRO_END_SolarSnsrRiValue_CEM_LIN1;

typedef int VECTORCAST_MARKER__MACRO_START_TFRAMEMAX_with_TIMER;

typedef int VECTORCAST_MARKER__MACRO_END_TFRAMEMAX_with_TIMER;

typedef int VECTORCAST_MARKER__MACRO_START_THR_DELTA_INTV_BYTE_ADDRESS;
(798)
typedef int VECTORCAST_MARKER__MACRO_END_THR_DELTA_INTV_BYTE_ADDRESS;

typedef int VECTORCAST_MARKER__MACRO_START_TIME_FOR_STANDBY_NORMAL_MEASURE;
1000
typedef int VECTORCAST_MARKER__MACRO_END_TIME_FOR_STANDBY_NORMAL_MEASURE;

typedef int VECTORCAST_MARKER__MACRO_START_TwliBriRawQf_CEM_LIN1;
RlsmCem_Lin1Fr01_CEM_LIN1 . rlsmcem_lin1fr01_cem_lin1 . TwliBriRawQf_CEM_LIN1
typedef int VECTORCAST_MARKER__MACRO_END_TwliBriRawQf_CEM_LIN1;

typedef int VECTORCAST_MARKER__MACRO_START_TwliBriRawTwliBriRaw_CEM_LIN1_0;
RlsmCem_Lin1Fr01_CEM_LIN1 . rlsmcem_lin1fr01_cem_lin1 . TwliBriRawTwliBriRaw_CEM_LIN1_0
typedef int VECTORCAST_MARKER__MACRO_END_TwliBriRawTwliBriRaw_CEM_LIN1_0;

typedef int VECTORCAST_MARKER__MACRO_START_TwliBriRawTwliBriRaw_CEM_LIN1_1;
RlsmCem_Lin1Fr01_CEM_LIN1 . rlsmcem_lin1fr01_cem_lin1 . TwliBriRawTwliBriRaw_CEM_LIN1_1
typedef int VECTORCAST_MARKER__MACRO_END_TwliBriRawTwliBriRaw_CEM_LIN1_1;

typedef int VECTORCAST_MARKER__MACRO_START_UCONTROLLER_STANDBY_SLEEP_TIME;
((EEPROM_Struct_AD . EEPROMStructAD . StandbyModeScanTime_g&0x1F)+1)
typedef int VECTORCAST_MARKER__MACRO_END_UCONTROLLER_STANDBY_SLEEP_TIME;

typedef int VECTORCAST_MARKER__MACRO_START_UNUSED;
0xFF
typedef int VECTORCAST_MARKER__MACRO_END_UNUSED;

typedef int VECTORCAST_MARKER__MACRO_START_VehSpdForWipg_CEM_LIN1;
CemCem_Lin1Fr01_CEM_LIN1 . cemcem_lin1fr01_cem_lin1 . VehSpdForWipg_CEM_LIN1
typedef int VECTORCAST_MARKER__MACRO_END_VehSpdForWipg_CEM_LIN1;

typedef int VECTORCAST_MARKER__MACRO_START_VehTyp_CEM_LIN1;
CemCem_Lin1Fr03_CEM_LIN1 . cemcem_lin1fr03_cem_lin1 . VehTyp_CEM_LIN1
typedef int VECTORCAST_MARKER__MACRO_END_VehTyp_CEM_LIN1;

typedef int VECTORCAST_MARKER__MACRO_START_WindCorrnValAmb_CEM_LIN1;
CemCem_Lin1Fr03_CEM_LIN1 . cemcem_lin1fr03_cem_lin1 . WindCorrnValAmb_CEM_LIN1
typedef int VECTORCAST_MARKER__MACRO_END_WindCorrnValAmb_CEM_LIN1;

typedef int VECTORCAST_MARKER__MACRO_START_WindCorrnValFrnt_CEM_LIN1;
CemCem_Lin1Fr03_CEM_LIN1 . cemcem_lin1fr03_cem_lin1 . WindCorrnValFrnt_CEM_LIN1
typedef int VECTORCAST_MARKER__MACRO_END_WindCorrnValFrnt_CEM_LIN1;

typedef int VECTORCAST_MARKER__MACRO_START_WindCorrnValHud_CEM_LIN1;
CemCem_Lin1Fr03_CEM_LIN1 . cemcem_lin1fr03_cem_lin1 . WindCorrnValHud_CEM_LIN1
typedef int VECTORCAST_MARKER__MACRO_END_WindCorrnValHud_CEM_LIN1;

typedef int VECTORCAST_MARKER__MACRO_START_WipgAutFrntMod_CEM_LIN1;
RlsmCem_Lin1Fr01_CEM_LIN1 . rlsmcem_lin1fr01_cem_lin1 . WipgAutFrntMod_CEM_LIN1
typedef int VECTORCAST_MARKER__MACRO_END_WipgAutFrntMod_CEM_LIN1;

typedef int VECTORCAST_MARKER__MACRO_START_WipgPwrActvnSafeWipgPwrAcsyModSafe_CEM_LIN1;
CemCem_Lin1Fr01_CEM_LIN1 . cemcem_lin1fr01_cem_lin1 . WipgPwrActvnSafeWipgPwrAcsyModSafe_CEM_LIN1
typedef int VECTORCAST_MARKER__MACRO_END_WipgPwrActvnSafeWipgPwrAcsyModSafe_CEM_LIN1;

typedef int VECTORCAST_MARKER__MACRO_START_WipgPwrActvnSafeWipgPwrDrvgModSafe_CEM_LIN1;
CemCem_Lin1Fr01_CEM_LIN1 . cemcem_lin1fr01_cem_lin1 . WipgPwrActvnSafeWipgPwrDrvgModSafe_CEM_LIN1
typedef int VECTORCAST_MARKER__MACRO_END_WipgPwrActvnSafeWipgPwrDrvgModSafe_CEM_LIN1;

typedef int VECTORCAST_MARKER__MACRO_START_WiprActv_CEM_LIN1;
CemCem_Lin1Fr06_CEM_LIN1 . cemcem_lin1fr06_cem_lin1 . WiprActv_CEM_LIN1
typedef int VECTORCAST_MARKER__MACRO_END_WiprActv_CEM_LIN1;

typedef int VECTORCAST_MARKER__MACRO_START_WiprInPrkgPosnLo_CEM_LIN1;
CemCem_Lin1Fr06_CEM_LIN1 . cemcem_lin1fr06_cem_lin1 . WiprInPrkgPosnLo_CEM_LIN1
typedef int VECTORCAST_MARKER__MACRO_END_WiprInPrkgPosnLo_CEM_LIN1;

typedef int VECTORCAST_MARKER__MACRO_START_WiprInWipgAr_CEM_LIN1;
CemCem_Lin1Fr06_CEM_LIN1 . cemcem_lin1fr06_cem_lin1 . WiprInWipgAr_CEM_LIN1
typedef int VECTORCAST_MARKER__MACRO_END_WiprInWipgAr_CEM_LIN1;

typedef int VECTORCAST_MARKER__MACRO_START_WiprMotFrntLvrCmdSafeLvrInHiSpdPosnSafe_CEM_LIN1;
CemCem_Lin1Fr01_CEM_LIN1 . cemcem_lin1fr01_cem_lin1 . WiprMotFrntLvrCmdSafeLvrInHiSpdPosnSafe_CEM_LIN1
typedef int VECTORCAST_MARKER__MACRO_END_WiprMotFrntLvrCmdSafeLvrInHiSpdPosnSafe_CEM_LIN1;

typedef int VECTORCAST_MARKER__MACRO_START_WiprMotFrntLvrCmdSafeLvrInIntlPosn_CEM_LIN1;
CemCem_Lin1Fr01_CEM_LIN1 . cemcem_lin1fr01_cem_lin1 . WiprMotFrntLvrCmdSafeLvrInIntlPosn_CEM_LIN1
typedef int VECTORCAST_MARKER__MACRO_END_WiprMotFrntLvrCmdSafeLvrInIntlPosn_CEM_LIN1;

typedef int VECTORCAST_MARKER__MACRO_START_WiprMotFrntLvrCmdSafeLvrInLoSpdPosnSafe_CEM_LIN1;
CemCem_Lin1Fr01_CEM_LIN1 . cemcem_lin1fr01_cem_lin1 . WiprMotFrntLvrCmdSafeLvrInLoSpdPosnSafe_CEM_LIN1
typedef int VECTORCAST_MARKER__MACRO_END_WiprMotFrntLvrCmdSafeLvrInLoSpdPosnSafe_CEM_LIN1;

typedef int VECTORCAST_MARKER__MACRO_START_WiprMotFrntLvrCmdSafeLvrInSnglStrokePos_CEM_LIN1;
CemCem_Lin1Fr01_CEM_LIN1 . cemcem_lin1fr01_cem_lin1 . WiprMotFrntLvrCmdSafeLvrInSnglStrokePos_CEM_LIN1
typedef int VECTORCAST_MARKER__MACRO_END_WiprMotFrntLvrCmdSafeLvrInSnglStrokePos_CEM_LIN1;

typedef int VECTORCAST_MARKER__MACRO_START_WiprMotFrntOffsAg_CEM_LIN1;
CemCem_Lin1Fr01_CEM_LIN1 . cemcem_lin1fr01_cem_lin1 . WiprMotFrntOffsAg_CEM_LIN1
typedef int VECTORCAST_MARKER__MACRO_END_WiprMotFrntOffsAg_CEM_LIN1;

typedef int VECTORCAST_MARKER__MACRO_START_WiprMotIntlCmd_CEM_LIN1;
CemCem_Lin1Fr01_CEM_LIN1 . cemcem_lin1fr01_cem_lin1 . WiprMotIntlCmd_CEM_LIN1
typedef int VECTORCAST_MARKER__MACRO_END_WiprMotIntlCmd_CEM_LIN1;

typedef int VECTORCAST_MARKER__MACRO_START_WiprPosnForSrvReq_CEM_LIN1;
CemCem_Lin1Fr01_CEM_LIN1 . cemcem_lin1fr01_cem_lin1 . WiprPosnForSrvReq_CEM_LIN1
typedef int VECTORCAST_MARKER__MACRO_END_WiprPosnForSrvReq_CEM_LIN1;

typedef int VECTORCAST_MARKER__MACRO_START_WshngCycActv_CEM_LIN1;
CemCem_Lin1Fr06_CEM_LIN1 . cemcem_lin1fr06_cem_lin1 . WshngCycActv_CEM_LIN1
typedef int VECTORCAST_MARKER__MACRO_END_WshngCycActv_CEM_LIN1;

typedef int VECTORCAST_MARKER__MACRO_START_WshrLvrPosnSafe_CEM_LIN1;
CemCem_Lin1Fr01_CEM_LIN1 . cemcem_lin1fr01_cem_lin1 . WshrLvrPosnSafe_CEM_LIN1
typedef int VECTORCAST_MARKER__MACRO_END_WshrLvrPosnSafe_CEM_LIN1;

typedef int VECTORCAST_MARKER__MACRO_START__0000_0000b;
0x00U
typedef int VECTORCAST_MARKER__MACRO_END__0000_0000b;

typedef int VECTORCAST_MARKER__MACRO_START__0000_0001b;
0x01U
typedef int VECTORCAST_MARKER__MACRO_END__0000_0001b;

typedef int VECTORCAST_MARKER__MACRO_START__0000_0010b;
0x02U
typedef int VECTORCAST_MARKER__MACRO_END__0000_0010b;

typedef int VECTORCAST_MARKER__MACRO_START__0000_0011b;
0x03U
typedef int VECTORCAST_MARKER__MACRO_END__0000_0011b;

typedef int VECTORCAST_MARKER__MACRO_START__0000_0100b;
0x04U
typedef int VECTORCAST_MARKER__MACRO_END__0000_0100b;

typedef int VECTORCAST_MARKER__MACRO_START__0000_0101b;
0x05U
typedef int VECTORCAST_MARKER__MACRO_END__0000_0101b;

typedef int VECTORCAST_MARKER__MACRO_START__0000_0110b;
0x06U
typedef int VECTORCAST_MARKER__MACRO_END__0000_0110b;

typedef int VECTORCAST_MARKER__MACRO_START__0000_0111b;
0x07U
typedef int VECTORCAST_MARKER__MACRO_END__0000_0111b;

typedef int VECTORCAST_MARKER__MACRO_START__0000_1000b;
0x08U
typedef int VECTORCAST_MARKER__MACRO_END__0000_1000b;

typedef int VECTORCAST_MARKER__MACRO_START__0000_1001b;
0x09U
typedef int VECTORCAST_MARKER__MACRO_END__0000_1001b;

typedef int VECTORCAST_MARKER__MACRO_START__0000_1010b;
0x0aU
typedef int VECTORCAST_MARKER__MACRO_END__0000_1010b;

typedef int VECTORCAST_MARKER__MACRO_START__0000_1011b;
0x0bU
typedef int VECTORCAST_MARKER__MACRO_END__0000_1011b;

typedef int VECTORCAST_MARKER__MACRO_START__0000_1100b;
0x0cU
typedef int VECTORCAST_MARKER__MACRO_END__0000_1100b;

typedef int VECTORCAST_MARKER__MACRO_START__0000_1101b;
0x0dU
typedef int VECTORCAST_MARKER__MACRO_END__0000_1101b;

typedef int VECTORCAST_MARKER__MACRO_START__0000_1110b;
0x0eU
typedef int VECTORCAST_MARKER__MACRO_END__0000_1110b;

typedef int VECTORCAST_MARKER__MACRO_START__0000_1111b;
0x0fU
typedef int VECTORCAST_MARKER__MACRO_END__0000_1111b;

typedef int VECTORCAST_MARKER__MACRO_START__0001_0000b;
0x10U
typedef int VECTORCAST_MARKER__MACRO_END__0001_0000b;

typedef int VECTORCAST_MARKER__MACRO_START__0001_0001b;
0x11U
typedef int VECTORCAST_MARKER__MACRO_END__0001_0001b;

typedef int VECTORCAST_MARKER__MACRO_START__0001_0010b;
0x12U
typedef int VECTORCAST_MARKER__MACRO_END__0001_0010b;

typedef int VECTORCAST_MARKER__MACRO_START__0001_0011b;
0x13U
typedef int VECTORCAST_MARKER__MACRO_END__0001_0011b;

typedef int VECTORCAST_MARKER__MACRO_START__0001_0100b;
0x14U
typedef int VECTORCAST_MARKER__MACRO_END__0001_0100b;

typedef int VECTORCAST_MARKER__MACRO_START__0001_0101b;
0x15U
typedef int VECTORCAST_MARKER__MACRO_END__0001_0101b;

typedef int VECTORCAST_MARKER__MACRO_START__0001_0110b;
0x16U
typedef int VECTORCAST_MARKER__MACRO_END__0001_0110b;

typedef int VECTORCAST_MARKER__MACRO_START__0001_0111b;
0x17U
typedef int VECTORCAST_MARKER__MACRO_END__0001_0111b;

typedef int VECTORCAST_MARKER__MACRO_START__0001_1000b;
0x18U
typedef int VECTORCAST_MARKER__MACRO_END__0001_1000b;

typedef int VECTORCAST_MARKER__MACRO_START__0001_1001b;
0x19U
typedef int VECTORCAST_MARKER__MACRO_END__0001_1001b;

typedef int VECTORCAST_MARKER__MACRO_START__0001_1010b;
0x1aU
typedef int VECTORCAST_MARKER__MACRO_END__0001_1010b;

typedef int VECTORCAST_MARKER__MACRO_START__0001_1011b;
0x1bU
typedef int VECTORCAST_MARKER__MACRO_END__0001_1011b;

typedef int VECTORCAST_MARKER__MACRO_START__0001_1100b;
0x1cU
typedef int VECTORCAST_MARKER__MACRO_END__0001_1100b;

typedef int VECTORCAST_MARKER__MACRO_START__0001_1101b;
0x1dU
typedef int VECTORCAST_MARKER__MACRO_END__0001_1101b;

typedef int VECTORCAST_MARKER__MACRO_START__0001_1110b;
0x1eU
typedef int VECTORCAST_MARKER__MACRO_END__0001_1110b;

typedef int VECTORCAST_MARKER__MACRO_START__0001_1111b;
0x1fU
typedef int VECTORCAST_MARKER__MACRO_END__0001_1111b;

typedef int VECTORCAST_MARKER__MACRO_START__0010_0000b;
0x20U
typedef int VECTORCAST_MARKER__MACRO_END__0010_0000b;

typedef int VECTORCAST_MARKER__MACRO_START__0010_0001b;
0x21U
typedef int VECTORCAST_MARKER__MACRO_END__0010_0001b;

typedef int VECTORCAST_MARKER__MACRO_START__0010_0010b;
0x22U
typedef int VECTORCAST_MARKER__MACRO_END__0010_0010b;

typedef int VECTORCAST_MARKER__MACRO_START__0010_0011b;
0x23U
typedef int VECTORCAST_MARKER__MACRO_END__0010_0011b;

typedef int VECTORCAST_MARKER__MACRO_START__0010_0100b;
0x24U
typedef int VECTORCAST_MARKER__MACRO_END__0010_0100b;

typedef int VECTORCAST_MARKER__MACRO_START__0010_0101b;
0x25U
typedef int VECTORCAST_MARKER__MACRO_END__0010_0101b;

typedef int VECTORCAST_MARKER__MACRO_START__0010_0110b;
0x26U
typedef int VECTORCAST_MARKER__MACRO_END__0010_0110b;

typedef int VECTORCAST_MARKER__MACRO_START__0010_0111b;
0x27U
typedef int VECTORCAST_MARKER__MACRO_END__0010_0111b;

typedef int VECTORCAST_MARKER__MACRO_START__0010_1000b;
0x28U
typedef int VECTORCAST_MARKER__MACRO_END__0010_1000b;

typedef int VECTORCAST_MARKER__MACRO_START__0010_1001b;
0x29U
typedef int VECTORCAST_MARKER__MACRO_END__0010_1001b;

typedef int VECTORCAST_MARKER__MACRO_START__0010_1010b;
0x2aU
typedef int VECTORCAST_MARKER__MACRO_END__0010_1010b;

typedef int VECTORCAST_MARKER__MACRO_START__0010_1011b;
0x2bU
typedef int VECTORCAST_MARKER__MACRO_END__0010_1011b;

typedef int VECTORCAST_MARKER__MACRO_START__0010_1100b;
0x2cU
typedef int VECTORCAST_MARKER__MACRO_END__0010_1100b;

typedef int VECTORCAST_MARKER__MACRO_START__0010_1101b;
0x2dU
typedef int VECTORCAST_MARKER__MACRO_END__0010_1101b;

typedef int VECTORCAST_MARKER__MACRO_START__0010_1110b;
0x2eU
typedef int VECTORCAST_MARKER__MACRO_END__0010_1110b;

typedef int VECTORCAST_MARKER__MACRO_START__0010_1111b;
0x2fU
typedef int VECTORCAST_MARKER__MACRO_END__0010_1111b;

typedef int VECTORCAST_MARKER__MACRO_START__0011_0000b;
0x30U
typedef int VECTORCAST_MARKER__MACRO_END__0011_0000b;

typedef int VECTORCAST_MARKER__MACRO_START__0011_0001b;
0x31U
typedef int VECTORCAST_MARKER__MACRO_END__0011_0001b;

typedef int VECTORCAST_MARKER__MACRO_START__0011_0010b;
0x32U
typedef int VECTORCAST_MARKER__MACRO_END__0011_0010b;

typedef int VECTORCAST_MARKER__MACRO_START__0011_0011b;
0x33U
typedef int VECTORCAST_MARKER__MACRO_END__0011_0011b;

typedef int VECTORCAST_MARKER__MACRO_START__0011_0100b;
0x34U
typedef int VECTORCAST_MARKER__MACRO_END__0011_0100b;

typedef int VECTORCAST_MARKER__MACRO_START__0011_0101b;
0x35U
typedef int VECTORCAST_MARKER__MACRO_END__0011_0101b;

typedef int VECTORCAST_MARKER__MACRO_START__0011_0110b;
0x36U
typedef int VECTORCAST_MARKER__MACRO_END__0011_0110b;

typedef int VECTORCAST_MARKER__MACRO_START__0011_0111b;
0x37U
typedef int VECTORCAST_MARKER__MACRO_END__0011_0111b;

typedef int VECTORCAST_MARKER__MACRO_START__0011_1000b;
0x38U
typedef int VECTORCAST_MARKER__MACRO_END__0011_1000b;

typedef int VECTORCAST_MARKER__MACRO_START__0011_1001b;
0x39U
typedef int VECTORCAST_MARKER__MACRO_END__0011_1001b;

typedef int VECTORCAST_MARKER__MACRO_START__0011_1010b;
0x3aU
typedef int VECTORCAST_MARKER__MACRO_END__0011_1010b;

typedef int VECTORCAST_MARKER__MACRO_START__0011_1011b;
0x3bU
typedef int VECTORCAST_MARKER__MACRO_END__0011_1011b;

typedef int VECTORCAST_MARKER__MACRO_START__0011_1100b;
0x3cU
typedef int VECTORCAST_MARKER__MACRO_END__0011_1100b;

typedef int VECTORCAST_MARKER__MACRO_START__0011_1101b;
0x3dU
typedef int VECTORCAST_MARKER__MACRO_END__0011_1101b;

typedef int VECTORCAST_MARKER__MACRO_START__0011_1110b;
0x3eU
typedef int VECTORCAST_MARKER__MACRO_END__0011_1110b;

typedef int VECTORCAST_MARKER__MACRO_START__0011_1111b;
0x3fU
typedef int VECTORCAST_MARKER__MACRO_END__0011_1111b;

typedef int VECTORCAST_MARKER__MACRO_START__0100_0000b;
0x40U
typedef int VECTORCAST_MARKER__MACRO_END__0100_0000b;

typedef int VECTORCAST_MARKER__MACRO_START__0100_0001b;
0x41U
typedef int VECTORCAST_MARKER__MACRO_END__0100_0001b;

typedef int VECTORCAST_MARKER__MACRO_START__0100_0010b;
0x42U
typedef int VECTORCAST_MARKER__MACRO_END__0100_0010b;

typedef int VECTORCAST_MARKER__MACRO_START__0100_0011b;
0x43U
typedef int VECTORCAST_MARKER__MACRO_END__0100_0011b;

typedef int VECTORCAST_MARKER__MACRO_START__0100_0100b;
0x44U
typedef int VECTORCAST_MARKER__MACRO_END__0100_0100b;

typedef int VECTORCAST_MARKER__MACRO_START__0100_0101b;
0x45U
typedef int VECTORCAST_MARKER__MACRO_END__0100_0101b;

typedef int VECTORCAST_MARKER__MACRO_START__0100_0110b;
0x46U
typedef int VECTORCAST_MARKER__MACRO_END__0100_0110b;

typedef int VECTORCAST_MARKER__MACRO_START__0100_0111b;
0x47U
typedef int VECTORCAST_MARKER__MACRO_END__0100_0111b;

typedef int VECTORCAST_MARKER__MACRO_START__0100_1000b;
0x48U
typedef int VECTORCAST_MARKER__MACRO_END__0100_1000b;

typedef int VECTORCAST_MARKER__MACRO_START__0100_1001b;
0x49U
typedef int VECTORCAST_MARKER__MACRO_END__0100_1001b;

typedef int VECTORCAST_MARKER__MACRO_START__0100_1010b;
0x4aU
typedef int VECTORCAST_MARKER__MACRO_END__0100_1010b;

typedef int VECTORCAST_MARKER__MACRO_START__0100_1011b;
0x4bU
typedef int VECTORCAST_MARKER__MACRO_END__0100_1011b;

typedef int VECTORCAST_MARKER__MACRO_START__0100_1100b;
0x4cU
typedef int VECTORCAST_MARKER__MACRO_END__0100_1100b;

typedef int VECTORCAST_MARKER__MACRO_START__0100_1101b;
0x4dU
typedef int VECTORCAST_MARKER__MACRO_END__0100_1101b;

typedef int VECTORCAST_MARKER__MACRO_START__0100_1110b;
0x4eU
typedef int VECTORCAST_MARKER__MACRO_END__0100_1110b;

typedef int VECTORCAST_MARKER__MACRO_START__0100_1111b;
0x4fU
typedef int VECTORCAST_MARKER__MACRO_END__0100_1111b;

typedef int VECTORCAST_MARKER__MACRO_START__0101_0000b;
0x50U
typedef int VECTORCAST_MARKER__MACRO_END__0101_0000b;

typedef int VECTORCAST_MARKER__MACRO_START__0101_0001b;
0x51U
typedef int VECTORCAST_MARKER__MACRO_END__0101_0001b;

typedef int VECTORCAST_MARKER__MACRO_START__0101_0010b;
0x52U
typedef int VECTORCAST_MARKER__MACRO_END__0101_0010b;

typedef int VECTORCAST_MARKER__MACRO_START__0101_0011b;
0x53U
typedef int VECTORCAST_MARKER__MACRO_END__0101_0011b;

typedef int VECTORCAST_MARKER__MACRO_START__0101_0100b;
0x54U
typedef int VECTORCAST_MARKER__MACRO_END__0101_0100b;

typedef int VECTORCAST_MARKER__MACRO_START__0101_0101b;
0x55U
typedef int VECTORCAST_MARKER__MACRO_END__0101_0101b;

typedef int VECTORCAST_MARKER__MACRO_START__0101_0110b;
0x56U
typedef int VECTORCAST_MARKER__MACRO_END__0101_0110b;

typedef int VECTORCAST_MARKER__MACRO_START__0101_0111b;
0x57U
typedef int VECTORCAST_MARKER__MACRO_END__0101_0111b;

typedef int VECTORCAST_MARKER__MACRO_START__0101_1000b;
0x58U
typedef int VECTORCAST_MARKER__MACRO_END__0101_1000b;

typedef int VECTORCAST_MARKER__MACRO_START__0101_1001b;
0x59U
typedef int VECTORCAST_MARKER__MACRO_END__0101_1001b;

typedef int VECTORCAST_MARKER__MACRO_START__0101_1010b;
0x5aU
typedef int VECTORCAST_MARKER__MACRO_END__0101_1010b;

typedef int VECTORCAST_MARKER__MACRO_START__0101_1011b;
0x5bU
typedef int VECTORCAST_MARKER__MACRO_END__0101_1011b;

typedef int VECTORCAST_MARKER__MACRO_START__0101_1100b;
0x5cU
typedef int VECTORCAST_MARKER__MACRO_END__0101_1100b;

typedef int VECTORCAST_MARKER__MACRO_START__0101_1101b;
0x5dU
typedef int VECTORCAST_MARKER__MACRO_END__0101_1101b;

typedef int VECTORCAST_MARKER__MACRO_START__0101_1110b;
0x5eU
typedef int VECTORCAST_MARKER__MACRO_END__0101_1110b;

typedef int VECTORCAST_MARKER__MACRO_START__0101_1111b;
0x5fU
typedef int VECTORCAST_MARKER__MACRO_END__0101_1111b;

typedef int VECTORCAST_MARKER__MACRO_START__0110_0000b;
0x60U
typedef int VECTORCAST_MARKER__MACRO_END__0110_0000b;

typedef int VECTORCAST_MARKER__MACRO_START__0110_0001b;
0x61U
typedef int VECTORCAST_MARKER__MACRO_END__0110_0001b;

typedef int VECTORCAST_MARKER__MACRO_START__0110_0010b;
0x62U
typedef int VECTORCAST_MARKER__MACRO_END__0110_0010b;

typedef int VECTORCAST_MARKER__MACRO_START__0110_0011b;
0x63U
typedef int VECTORCAST_MARKER__MACRO_END__0110_0011b;

typedef int VECTORCAST_MARKER__MACRO_START__0110_0100b;
0x64U
typedef int VECTORCAST_MARKER__MACRO_END__0110_0100b;

typedef int VECTORCAST_MARKER__MACRO_START__0110_0101b;
0x65U
typedef int VECTORCAST_MARKER__MACRO_END__0110_0101b;

typedef int VECTORCAST_MARKER__MACRO_START__0110_0110b;
0x66U
typedef int VECTORCAST_MARKER__MACRO_END__0110_0110b;

typedef int VECTORCAST_MARKER__MACRO_START__0110_0111b;
0x67U
typedef int VECTORCAST_MARKER__MACRO_END__0110_0111b;

typedef int VECTORCAST_MARKER__MACRO_START__0110_1000b;
0x68U
typedef int VECTORCAST_MARKER__MACRO_END__0110_1000b;

typedef int VECTORCAST_MARKER__MACRO_START__0110_1001b;
0x69U
typedef int VECTORCAST_MARKER__MACRO_END__0110_1001b;

typedef int VECTORCAST_MARKER__MACRO_START__0110_1010b;
0x6aU
typedef int VECTORCAST_MARKER__MACRO_END__0110_1010b;

typedef int VECTORCAST_MARKER__MACRO_START__0110_1011b;
0x6bU
typedef int VECTORCAST_MARKER__MACRO_END__0110_1011b;

typedef int VECTORCAST_MARKER__MACRO_START__0110_1100b;
0x6cU
typedef int VECTORCAST_MARKER__MACRO_END__0110_1100b;

typedef int VECTORCAST_MARKER__MACRO_START__0110_1101b;
0x6dU
typedef int VECTORCAST_MARKER__MACRO_END__0110_1101b;

typedef int VECTORCAST_MARKER__MACRO_START__0110_1110b;
0x6eU
typedef int VECTORCAST_MARKER__MACRO_END__0110_1110b;

typedef int VECTORCAST_MARKER__MACRO_START__0110_1111b;
0x6fU
typedef int VECTORCAST_MARKER__MACRO_END__0110_1111b;

typedef int VECTORCAST_MARKER__MACRO_START__0111_0000b;
0x70U
typedef int VECTORCAST_MARKER__MACRO_END__0111_0000b;

typedef int VECTORCAST_MARKER__MACRO_START__0111_0001b;
0x71U
typedef int VECTORCAST_MARKER__MACRO_END__0111_0001b;

typedef int VECTORCAST_MARKER__MACRO_START__0111_0010b;
0x72U
typedef int VECTORCAST_MARKER__MACRO_END__0111_0010b;

typedef int VECTORCAST_MARKER__MACRO_START__0111_0011b;
0x73U
typedef int VECTORCAST_MARKER__MACRO_END__0111_0011b;

typedef int VECTORCAST_MARKER__MACRO_START__0111_0100b;
0x74U
typedef int VECTORCAST_MARKER__MACRO_END__0111_0100b;

typedef int VECTORCAST_MARKER__MACRO_START__0111_0101b;
0x75U
typedef int VECTORCAST_MARKER__MACRO_END__0111_0101b;

typedef int VECTORCAST_MARKER__MACRO_START__0111_0110b;
0x76U
typedef int VECTORCAST_MARKER__MACRO_END__0111_0110b;

typedef int VECTORCAST_MARKER__MACRO_START__0111_0111b;
0x77U
typedef int VECTORCAST_MARKER__MACRO_END__0111_0111b;

typedef int VECTORCAST_MARKER__MACRO_START__0111_1000b;
0x78U
typedef int VECTORCAST_MARKER__MACRO_END__0111_1000b;

typedef int VECTORCAST_MARKER__MACRO_START__0111_1001b;
0x79U
typedef int VECTORCAST_MARKER__MACRO_END__0111_1001b;

typedef int VECTORCAST_MARKER__MACRO_START__0111_1010b;
0x7aU
typedef int VECTORCAST_MARKER__MACRO_END__0111_1010b;

typedef int VECTORCAST_MARKER__MACRO_START__0111_1011b;
0x7bU
typedef int VECTORCAST_MARKER__MACRO_END__0111_1011b;

typedef int VECTORCAST_MARKER__MACRO_START__0111_1100b;
0x7cU
typedef int VECTORCAST_MARKER__MACRO_END__0111_1100b;

typedef int VECTORCAST_MARKER__MACRO_START__0111_1101b;
0x7dU
typedef int VECTORCAST_MARKER__MACRO_END__0111_1101b;

typedef int VECTORCAST_MARKER__MACRO_START__0111_1110b;
0x7eU
typedef int VECTORCAST_MARKER__MACRO_END__0111_1110b;

typedef int VECTORCAST_MARKER__MACRO_START__0111_1111b;
0x7fU
typedef int VECTORCAST_MARKER__MACRO_END__0111_1111b;

typedef int VECTORCAST_MARKER__MACRO_START__1000_0000b;
0x80U
typedef int VECTORCAST_MARKER__MACRO_END__1000_0000b;

typedef int VECTORCAST_MARKER__MACRO_START__1000_0001b;
0x81U
typedef int VECTORCAST_MARKER__MACRO_END__1000_0001b;

typedef int VECTORCAST_MARKER__MACRO_START__1000_0010b;
0x82U
typedef int VECTORCAST_MARKER__MACRO_END__1000_0010b;

typedef int VECTORCAST_MARKER__MACRO_START__1000_0011b;
0x83U
typedef int VECTORCAST_MARKER__MACRO_END__1000_0011b;

typedef int VECTORCAST_MARKER__MACRO_START__1000_0100b;
0x84U
typedef int VECTORCAST_MARKER__MACRO_END__1000_0100b;

typedef int VECTORCAST_MARKER__MACRO_START__1000_0101b;
0x85U
typedef int VECTORCAST_MARKER__MACRO_END__1000_0101b;

typedef int VECTORCAST_MARKER__MACRO_START__1000_0110b;
0x86U
typedef int VECTORCAST_MARKER__MACRO_END__1000_0110b;

typedef int VECTORCAST_MARKER__MACRO_START__1000_0111b;
0x87U
typedef int VECTORCAST_MARKER__MACRO_END__1000_0111b;

typedef int VECTORCAST_MARKER__MACRO_START__1000_1000b;
0x88U
typedef int VECTORCAST_MARKER__MACRO_END__1000_1000b;

typedef int VECTORCAST_MARKER__MACRO_START__1000_1001b;
0x89U
typedef int VECTORCAST_MARKER__MACRO_END__1000_1001b;

typedef int VECTORCAST_MARKER__MACRO_START__1000_1010b;
0x8aU
typedef int VECTORCAST_MARKER__MACRO_END__1000_1010b;

typedef int VECTORCAST_MARKER__MACRO_START__1000_1011b;
0x8bU
typedef int VECTORCAST_MARKER__MACRO_END__1000_1011b;

typedef int VECTORCAST_MARKER__MACRO_START__1000_1100b;
0x8cU
typedef int VECTORCAST_MARKER__MACRO_END__1000_1100b;

typedef int VECTORCAST_MARKER__MACRO_START__1000_1101b;
0x8dU
typedef int VECTORCAST_MARKER__MACRO_END__1000_1101b;

typedef int VECTORCAST_MARKER__MACRO_START__1000_1110b;
0x8eU
typedef int VECTORCAST_MARKER__MACRO_END__1000_1110b;

typedef int VECTORCAST_MARKER__MACRO_START__1000_1111b;
0x8fU
typedef int VECTORCAST_MARKER__MACRO_END__1000_1111b;

typedef int VECTORCAST_MARKER__MACRO_START__1001_0000b;
0x90U
typedef int VECTORCAST_MARKER__MACRO_END__1001_0000b;

typedef int VECTORCAST_MARKER__MACRO_START__1001_0001b;
0x91U
typedef int VECTORCAST_MARKER__MACRO_END__1001_0001b;

typedef int VECTORCAST_MARKER__MACRO_START__1001_0010b;
0x92U
typedef int VECTORCAST_MARKER__MACRO_END__1001_0010b;

typedef int VECTORCAST_MARKER__MACRO_START__1001_0011b;
0x93U
typedef int VECTORCAST_MARKER__MACRO_END__1001_0011b;

typedef int VECTORCAST_MARKER__MACRO_START__1001_0100b;
0x94U
typedef int VECTORCAST_MARKER__MACRO_END__1001_0100b;

typedef int VECTORCAST_MARKER__MACRO_START__1001_0101b;
0x95U
typedef int VECTORCAST_MARKER__MACRO_END__1001_0101b;

typedef int VECTORCAST_MARKER__MACRO_START__1001_0110b;
0x96U
typedef int VECTORCAST_MARKER__MACRO_END__1001_0110b;

typedef int VECTORCAST_MARKER__MACRO_START__1001_0111b;
0x97U
typedef int VECTORCAST_MARKER__MACRO_END__1001_0111b;

typedef int VECTORCAST_MARKER__MACRO_START__1001_1000b;
0x98U
typedef int VECTORCAST_MARKER__MACRO_END__1001_1000b;

typedef int VECTORCAST_MARKER__MACRO_START__1001_1001b;
0x99U
typedef int VECTORCAST_MARKER__MACRO_END__1001_1001b;

typedef int VECTORCAST_MARKER__MACRO_START__1001_1010b;
0x9aU
typedef int VECTORCAST_MARKER__MACRO_END__1001_1010b;

typedef int VECTORCAST_MARKER__MACRO_START__1001_1011b;
0x9bU
typedef int VECTORCAST_MARKER__MACRO_END__1001_1011b;

typedef int VECTORCAST_MARKER__MACRO_START__1001_1100b;
0x9cU
typedef int VECTORCAST_MARKER__MACRO_END__1001_1100b;

typedef int VECTORCAST_MARKER__MACRO_START__1001_1101b;
0x9dU
typedef int VECTORCAST_MARKER__MACRO_END__1001_1101b;

typedef int VECTORCAST_MARKER__MACRO_START__1001_1110b;
0x9eU
typedef int VECTORCAST_MARKER__MACRO_END__1001_1110b;

typedef int VECTORCAST_MARKER__MACRO_START__1001_1111b;
0x9fU
typedef int VECTORCAST_MARKER__MACRO_END__1001_1111b;

typedef int VECTORCAST_MARKER__MACRO_START__1010_0000b;
0xa0U
typedef int VECTORCAST_MARKER__MACRO_END__1010_0000b;

typedef int VECTORCAST_MARKER__MACRO_START__1010_0001b;
0xa1U
typedef int VECTORCAST_MARKER__MACRO_END__1010_0001b;

typedef int VECTORCAST_MARKER__MACRO_START__1010_0010b;
0xa2U
typedef int VECTORCAST_MARKER__MACRO_END__1010_0010b;

typedef int VECTORCAST_MARKER__MACRO_START__1010_0011b;
0xa3U
typedef int VECTORCAST_MARKER__MACRO_END__1010_0011b;

typedef int VECTORCAST_MARKER__MACRO_START__1010_0100b;
0xa4U
typedef int VECTORCAST_MARKER__MACRO_END__1010_0100b;

typedef int VECTORCAST_MARKER__MACRO_START__1010_0101b;
0xa5U
typedef int VECTORCAST_MARKER__MACRO_END__1010_0101b;

typedef int VECTORCAST_MARKER__MACRO_START__1010_0110b;
0xa6U
typedef int VECTORCAST_MARKER__MACRO_END__1010_0110b;

typedef int VECTORCAST_MARKER__MACRO_START__1010_0111b;
0xa7U
typedef int VECTORCAST_MARKER__MACRO_END__1010_0111b;

typedef int VECTORCAST_MARKER__MACRO_START__1010_1000b;
0xa8U
typedef int VECTORCAST_MARKER__MACRO_END__1010_1000b;

typedef int VECTORCAST_MARKER__MACRO_START__1010_1001b;
0xa9U
typedef int VECTORCAST_MARKER__MACRO_END__1010_1001b;

typedef int VECTORCAST_MARKER__MACRO_START__1010_1010b;
0xaaU
typedef int VECTORCAST_MARKER__MACRO_END__1010_1010b;

typedef int VECTORCAST_MARKER__MACRO_START__1010_1011b;
0xabU
typedef int VECTORCAST_MARKER__MACRO_END__1010_1011b;

typedef int VECTORCAST_MARKER__MACRO_START__1010_1100b;
0xacU
typedef int VECTORCAST_MARKER__MACRO_END__1010_1100b;

typedef int VECTORCAST_MARKER__MACRO_START__1010_1101b;
0xadU
typedef int VECTORCAST_MARKER__MACRO_END__1010_1101b;

typedef int VECTORCAST_MARKER__MACRO_START__1010_1110b;
0xaeU
typedef int VECTORCAST_MARKER__MACRO_END__1010_1110b;

typedef int VECTORCAST_MARKER__MACRO_START__1010_1111b;
0xafU
typedef int VECTORCAST_MARKER__MACRO_END__1010_1111b;

typedef int VECTORCAST_MARKER__MACRO_START__1011_0000b;
0xb0U
typedef int VECTORCAST_MARKER__MACRO_END__1011_0000b;

typedef int VECTORCAST_MARKER__MACRO_START__1011_0001b;
0xb1U
typedef int VECTORCAST_MARKER__MACRO_END__1011_0001b;

typedef int VECTORCAST_MARKER__MACRO_START__1011_0010b;
0xb2U
typedef int VECTORCAST_MARKER__MACRO_END__1011_0010b;

typedef int VECTORCAST_MARKER__MACRO_START__1011_0011b;
0xb3U
typedef int VECTORCAST_MARKER__MACRO_END__1011_0011b;

typedef int VECTORCAST_MARKER__MACRO_START__1011_0100b;
0xb4U
typedef int VECTORCAST_MARKER__MACRO_END__1011_0100b;

typedef int VECTORCAST_MARKER__MACRO_START__1011_0101b;
0xb5U
typedef int VECTORCAST_MARKER__MACRO_END__1011_0101b;

typedef int VECTORCAST_MARKER__MACRO_START__1011_0110b;
0xb6U
typedef int VECTORCAST_MARKER__MACRO_END__1011_0110b;

typedef int VECTORCAST_MARKER__MACRO_START__1011_0111b;
0xb7U
typedef int VECTORCAST_MARKER__MACRO_END__1011_0111b;

typedef int VECTORCAST_MARKER__MACRO_START__1011_1000b;
0xb8U
typedef int VECTORCAST_MARKER__MACRO_END__1011_1000b;

typedef int VECTORCAST_MARKER__MACRO_START__1011_1001b;
0xb9U
typedef int VECTORCAST_MARKER__MACRO_END__1011_1001b;

typedef int VECTORCAST_MARKER__MACRO_START__1011_1010b;
0xbaU
typedef int VECTORCAST_MARKER__MACRO_END__1011_1010b;

typedef int VECTORCAST_MARKER__MACRO_START__1011_1011b;
0xbbU
typedef int VECTORCAST_MARKER__MACRO_END__1011_1011b;

typedef int VECTORCAST_MARKER__MACRO_START__1011_1100b;
0xbcU
typedef int VECTORCAST_MARKER__MACRO_END__1011_1100b;

typedef int VECTORCAST_MARKER__MACRO_START__1011_1101b;
0xbdU
typedef int VECTORCAST_MARKER__MACRO_END__1011_1101b;

typedef int VECTORCAST_MARKER__MACRO_START__1011_1110b;
0xbeU
typedef int VECTORCAST_MARKER__MACRO_END__1011_1110b;

typedef int VECTORCAST_MARKER__MACRO_START__1011_1111b;
0xbfU
typedef int VECTORCAST_MARKER__MACRO_END__1011_1111b;

typedef int VECTORCAST_MARKER__MACRO_START__1100_0000b;
0xc0U
typedef int VECTORCAST_MARKER__MACRO_END__1100_0000b;

typedef int VECTORCAST_MARKER__MACRO_START__1100_0001b;
0xc1U
typedef int VECTORCAST_MARKER__MACRO_END__1100_0001b;

typedef int VECTORCAST_MARKER__MACRO_START__1100_0010b;
0xc2U
typedef int VECTORCAST_MARKER__MACRO_END__1100_0010b;

typedef int VECTORCAST_MARKER__MACRO_START__1100_0011b;
0xc3U
typedef int VECTORCAST_MARKER__MACRO_END__1100_0011b;

typedef int VECTORCAST_MARKER__MACRO_START__1100_0100b;
0xc4U
typedef int VECTORCAST_MARKER__MACRO_END__1100_0100b;

typedef int VECTORCAST_MARKER__MACRO_START__1100_0101b;
0xc5U
typedef int VECTORCAST_MARKER__MACRO_END__1100_0101b;

typedef int VECTORCAST_MARKER__MACRO_START__1100_0110b;
0xc6U
typedef int VECTORCAST_MARKER__MACRO_END__1100_0110b;

typedef int VECTORCAST_MARKER__MACRO_START__1100_0111b;
0xc7U
typedef int VECTORCAST_MARKER__MACRO_END__1100_0111b;

typedef int VECTORCAST_MARKER__MACRO_START__1100_1000b;
0xc8U
typedef int VECTORCAST_MARKER__MACRO_END__1100_1000b;

typedef int VECTORCAST_MARKER__MACRO_START__1100_1001b;
0xc9U
typedef int VECTORCAST_MARKER__MACRO_END__1100_1001b;

typedef int VECTORCAST_MARKER__MACRO_START__1100_1010b;
0xcaU
typedef int VECTORCAST_MARKER__MACRO_END__1100_1010b;

typedef int VECTORCAST_MARKER__MACRO_START__1100_1011b;
0xcbU
typedef int VECTORCAST_MARKER__MACRO_END__1100_1011b;

typedef int VECTORCAST_MARKER__MACRO_START__1100_1100b;
0xccU
typedef int VECTORCAST_MARKER__MACRO_END__1100_1100b;

typedef int VECTORCAST_MARKER__MACRO_START__1100_1101b;
0xcdU
typedef int VECTORCAST_MARKER__MACRO_END__1100_1101b;

typedef int VECTORCAST_MARKER__MACRO_START__1100_1110b;
0xceU
typedef int VECTORCAST_MARKER__MACRO_END__1100_1110b;

typedef int VECTORCAST_MARKER__MACRO_START__1100_1111b;
0xcfU
typedef int VECTORCAST_MARKER__MACRO_END__1100_1111b;

typedef int VECTORCAST_MARKER__MACRO_START__1101_0000b;
0xd0U
typedef int VECTORCAST_MARKER__MACRO_END__1101_0000b;

typedef int VECTORCAST_MARKER__MACRO_START__1101_0001b;
0xd1U
typedef int VECTORCAST_MARKER__MACRO_END__1101_0001b;

typedef int VECTORCAST_MARKER__MACRO_START__1101_0010b;
0xd2U
typedef int VECTORCAST_MARKER__MACRO_END__1101_0010b;

typedef int VECTORCAST_MARKER__MACRO_START__1101_0011b;
0xd3U
typedef int VECTORCAST_MARKER__MACRO_END__1101_0011b;

typedef int VECTORCAST_MARKER__MACRO_START__1101_0100b;
0xd4U
typedef int VECTORCAST_MARKER__MACRO_END__1101_0100b;

typedef int VECTORCAST_MARKER__MACRO_START__1101_0101b;
0xd5U
typedef int VECTORCAST_MARKER__MACRO_END__1101_0101b;

typedef int VECTORCAST_MARKER__MACRO_START__1101_0110b;
0xd6U
typedef int VECTORCAST_MARKER__MACRO_END__1101_0110b;

typedef int VECTORCAST_MARKER__MACRO_START__1101_0111b;
0xd7U
typedef int VECTORCAST_MARKER__MACRO_END__1101_0111b;

typedef int VECTORCAST_MARKER__MACRO_START__1101_1000b;
0xd8U
typedef int VECTORCAST_MARKER__MACRO_END__1101_1000b;

typedef int VECTORCAST_MARKER__MACRO_START__1101_1001b;
0xd9U
typedef int VECTORCAST_MARKER__MACRO_END__1101_1001b;

typedef int VECTORCAST_MARKER__MACRO_START__1101_1010b;
0xdaU
typedef int VECTORCAST_MARKER__MACRO_END__1101_1010b;

typedef int VECTORCAST_MARKER__MACRO_START__1101_1011b;
0xdbU
typedef int VECTORCAST_MARKER__MACRO_END__1101_1011b;

typedef int VECTORCAST_MARKER__MACRO_START__1101_1100b;
0xdcU
typedef int VECTORCAST_MARKER__MACRO_END__1101_1100b;

typedef int VECTORCAST_MARKER__MACRO_START__1101_1101b;
0xddU
typedef int VECTORCAST_MARKER__MACRO_END__1101_1101b;

typedef int VECTORCAST_MARKER__MACRO_START__1101_1110b;
0xdeU
typedef int VECTORCAST_MARKER__MACRO_END__1101_1110b;

typedef int VECTORCAST_MARKER__MACRO_START__1101_1111b;
0xdfU
typedef int VECTORCAST_MARKER__MACRO_END__1101_1111b;

typedef int VECTORCAST_MARKER__MACRO_START__1110_0000b;
0xe0U
typedef int VECTORCAST_MARKER__MACRO_END__1110_0000b;

typedef int VECTORCAST_MARKER__MACRO_START__1110_0001b;
0xe1U
typedef int VECTORCAST_MARKER__MACRO_END__1110_0001b;

typedef int VECTORCAST_MARKER__MACRO_START__1110_0010b;
0xe2U
typedef int VECTORCAST_MARKER__MACRO_END__1110_0010b;

typedef int VECTORCAST_MARKER__MACRO_START__1110_0011b;
0xe3U
typedef int VECTORCAST_MARKER__MACRO_END__1110_0011b;

typedef int VECTORCAST_MARKER__MACRO_START__1110_0100b;
0xe4U
typedef int VECTORCAST_MARKER__MACRO_END__1110_0100b;

typedef int VECTORCAST_MARKER__MACRO_START__1110_0101b;
0xe5U
typedef int VECTORCAST_MARKER__MACRO_END__1110_0101b;

typedef int VECTORCAST_MARKER__MACRO_START__1110_0110b;
0xe6U
typedef int VECTORCAST_MARKER__MACRO_END__1110_0110b;

typedef int VECTORCAST_MARKER__MACRO_START__1110_0111b;
0xe7U
typedef int VECTORCAST_MARKER__MACRO_END__1110_0111b;

typedef int VECTORCAST_MARKER__MACRO_START__1110_1000b;
0xe8U
typedef int VECTORCAST_MARKER__MACRO_END__1110_1000b;

typedef int VECTORCAST_MARKER__MACRO_START__1110_1001b;
0xe9U
typedef int VECTORCAST_MARKER__MACRO_END__1110_1001b;

typedef int VECTORCAST_MARKER__MACRO_START__1110_1010b;
0xeaU
typedef int VECTORCAST_MARKER__MACRO_END__1110_1010b;

typedef int VECTORCAST_MARKER__MACRO_START__1110_1011b;
0xebU
typedef int VECTORCAST_MARKER__MACRO_END__1110_1011b;

typedef int VECTORCAST_MARKER__MACRO_START__1110_1100b;
0xecU
typedef int VECTORCAST_MARKER__MACRO_END__1110_1100b;

typedef int VECTORCAST_MARKER__MACRO_START__1110_1101b;
0xedU
typedef int VECTORCAST_MARKER__MACRO_END__1110_1101b;

typedef int VECTORCAST_MARKER__MACRO_START__1110_1110b;
0xeeU
typedef int VECTORCAST_MARKER__MACRO_END__1110_1110b;

typedef int VECTORCAST_MARKER__MACRO_START__1110_1111b;
0xefU
typedef int VECTORCAST_MARKER__MACRO_END__1110_1111b;

typedef int VECTORCAST_MARKER__MACRO_START__1111_0000b;
0xf0U
typedef int VECTORCAST_MARKER__MACRO_END__1111_0000b;

typedef int VECTORCAST_MARKER__MACRO_START__1111_0001b;
0xf1U
typedef int VECTORCAST_MARKER__MACRO_END__1111_0001b;

typedef int VECTORCAST_MARKER__MACRO_START__1111_0010b;
0xf2U
typedef int VECTORCAST_MARKER__MACRO_END__1111_0010b;

typedef int VECTORCAST_MARKER__MACRO_START__1111_0011b;
0xf3U
typedef int VECTORCAST_MARKER__MACRO_END__1111_0011b;

typedef int VECTORCAST_MARKER__MACRO_START__1111_0100b;
0xf4U
typedef int VECTORCAST_MARKER__MACRO_END__1111_0100b;

typedef int VECTORCAST_MARKER__MACRO_START__1111_0101b;
0xf5U
typedef int VECTORCAST_MARKER__MACRO_END__1111_0101b;

typedef int VECTORCAST_MARKER__MACRO_START__1111_0110b;
0xf6U
typedef int VECTORCAST_MARKER__MACRO_END__1111_0110b;

typedef int VECTORCAST_MARKER__MACRO_START__1111_0111b;
0xf7U
typedef int VECTORCAST_MARKER__MACRO_END__1111_0111b;

typedef int VECTORCAST_MARKER__MACRO_START__1111_1000b;
0xf8U
typedef int VECTORCAST_MARKER__MACRO_END__1111_1000b;

typedef int VECTORCAST_MARKER__MACRO_START__1111_1001b;
0xf9U
typedef int VECTORCAST_MARKER__MACRO_END__1111_1001b;

typedef int VECTORCAST_MARKER__MACRO_START__1111_1010b;
0xfaU
typedef int VECTORCAST_MARKER__MACRO_END__1111_1010b;

typedef int VECTORCAST_MARKER__MACRO_START__1111_1011b;
0xfbU
typedef int VECTORCAST_MARKER__MACRO_END__1111_1011b;

typedef int VECTORCAST_MARKER__MACRO_START__1111_1100b;
0xfcU
typedef int VECTORCAST_MARKER__MACRO_END__1111_1100b;

typedef int VECTORCAST_MARKER__MACRO_START__1111_1101b;
0xfdU
typedef int VECTORCAST_MARKER__MACRO_END__1111_1101b;

typedef int VECTORCAST_MARKER__MACRO_START__1111_1110b;
0xfeU
typedef int VECTORCAST_MARKER__MACRO_END__1111_1110b;

typedef int VECTORCAST_MARKER__MACRO_START__1111_1111b;
0xffU
typedef int VECTORCAST_MARKER__MACRO_END__1111_1111b;

typedef int VECTORCAST_MARKER__MACRO_START__DIAGE2_PROJECTCONFIG_H_;

typedef int VECTORCAST_MARKER__MACRO_END__DIAGE2_PROJECTCONFIG_H_;

typedef int VECTORCAST_MARKER__MACRO_START__DIAGNOSE_H_;

typedef int VECTORCAST_MARKER__MACRO_END__DIAGNOSE_H_;

typedef int VECTORCAST_MARKER__MACRO_START__EMPF_FACTOR_SCAL;
0x07
typedef int VECTORCAST_MARKER__MACRO_END__EMPF_FACTOR_SCAL;

typedef int VECTORCAST_MARKER__MACRO_START__EMPF_FACTOR_SCAL_1;
0x09
typedef int VECTORCAST_MARKER__MACRO_END__EMPF_FACTOR_SCAL_1;

typedef int VECTORCAST_MARKER__MACRO_START__HUMTEMP_H_;

typedef int VECTORCAST_MARKER__MACRO_END__HUMTEMP_H_;

typedef int VECTORCAST_MARKER__MACRO_START__OVR_INT_SCAL_OFFS;
0x40
typedef int VECTORCAST_MARKER__MACRO_END__OVR_INT_SCAL_OFFS;

typedef int VECTORCAST_MARKER__MACRO_START__SUPPORTASSIGNNAD_;

typedef int VECTORCAST_MARKER__MACRO_END__SUPPORTASSIGNNAD_;

typedef int VECTORCAST_MARKER__MACRO_START__SUPPORTCODING2E_;

typedef int VECTORCAST_MARKER__MACRO_END__SUPPORTCODING2E_;

typedef int VECTORCAST_MARKER__MACRO_START__SUPPORTSERVICE21_;

typedef int VECTORCAST_MARKER__MACRO_END__SUPPORTSERVICE21_;

typedef int VECTORCAST_MARKER__MACRO_START__SUPPORTSERVICE22_;

typedef int VECTORCAST_MARKER__MACRO_END__SUPPORTSERVICE22_;

typedef int VECTORCAST_MARKER__MACRO_START__SUPPORTSERVICE3D_;

typedef int VECTORCAST_MARKER__MACRO_END__SUPPORTSERVICE3D_;

typedef int VECTORCAST_MARKER__MACRO_START___IOR5F109BE_H__;

typedef int VECTORCAST_MARKER__MACRO_END___IOR5F109BE_H__;

typedef int VECTORCAST_MARKER__MACRO_START___PFDL_H_INCLUDED;

typedef int VECTORCAST_MARKER__MACRO_END___PFDL_H_INCLUDED;

typedef int VECTORCAST_MARKER__MACRO_START___PFDL_TYPES_H_INCLUDED;

typedef int VECTORCAST_MARKER__MACRO_END___PFDL_TYPES_H_INCLUDED;

typedef int VECTORCAST_MARKER__MACRO_START___RS_LIB_H__;

typedef int VECTORCAST_MARKER__MACRO_END___RS_LIB_H__;

typedef int VECTORCAST_MARKER__MACRO_START__main_;

typedef int VECTORCAST_MARKER__MACRO_END__main_;

typedef int VECTORCAST_MARKER__MACRO_START__timer_;

typedef int VECTORCAST_MARKER__MACRO_END__timer_;

typedef int VECTORCAST_MARKER__MACRO_START_bi_CALIB_CHECK_FAILURE_g;
(uF_Diagnose_pre_Flag . Bit . B2)
typedef int VECTORCAST_MARKER__MACRO_END_bi_CALIB_CHECK_FAILURE_g;

typedef int VECTORCAST_MARKER__MACRO_START_bi_FIRST_RAM_CHECK_DONE_g;
(uF_Diagnose_pre_Flag . Bit . B5)
typedef int VECTORCAST_MARKER__MACRO_END_bi_FIRST_RAM_CHECK_DONE_g;

typedef int VECTORCAST_MARKER__MACRO_START_bi_First_CALIB_CHECK_Done_g;
(uF_Diagnose_pre_Flag . Bit . B7)
typedef int VECTORCAST_MARKER__MACRO_END_bi_First_CALIB_CHECK_Done_g;

typedef int VECTORCAST_MARKER__MACRO_START_bi_First_ROM_CHECK_Done_g;
(uF_Diagnose_pre_Flag . Bit . B6)
typedef int VECTORCAST_MARKER__MACRO_END_bi_First_ROM_CHECK_Done_g;

typedef int VECTORCAST_MARKER__MACRO_START_bi_RAM_CHECK_FAILURE_g;
(uF_Diagnose_pre_Flag . Bit . B0)
typedef int VECTORCAST_MARKER__MACRO_END_bi_RAM_CHECK_FAILURE_g;

typedef int VECTORCAST_MARKER__MACRO_START_bi_RAM_GUARD_Error_g;
(uF_Diagnose_pre_Flag . Bit . B4)
typedef int VECTORCAST_MARKER__MACRO_END_bi_RAM_GUARD_Error_g;

typedef int VECTORCAST_MARKER__MACRO_START_bi_ROM_CHECK_FAILURE_g;
(uF_Diagnose_pre_Flag . Bit . B1)
typedef int VECTORCAST_MARKER__MACRO_END_bi_ROM_CHECK_FAILURE_g;

typedef int VECTORCAST_MARKER__MACRO_START_bi_RS_VariantError_g;
(uF_Diagnose_pre_Flag . Bit . B3)
typedef int VECTORCAST_MARKER__MACRO_END_bi_RS_VariantError_g;

typedef int VECTORCAST_MARKER__MACRO_START_cab_AMB_SECURE_DAY_THRESHOLD_s;
(byte) 50
typedef int VECTORCAST_MARKER__MACRO_END_cab_AMB_SECURE_DAY_THRESHOLD_s;

typedef int VECTORCAST_MARKER__MACRO_START_cab_FW_SECURE_DAY_THRESHOLD_s;
(byte) 50
typedef int VECTORCAST_MARKER__MACRO_END_cab_FW_SECURE_DAY_THRESHOLD_s;

typedef int VECTORCAST_MARKER__MACRO_START_cab_IR_SECURE_DAY_THRESHOLD_s;
(byte) 15
typedef int VECTORCAST_MARKER__MACRO_END_cab_IR_SECURE_DAY_THRESHOLD_s;

typedef int VECTORCAST_MARKER__MACRO_START_cb_ADC_ERROR_CNT_THRESHOLD_g;
5
typedef int VECTORCAST_MARKER__MACRO_END_cb_ADC_ERROR_CNT_THRESHOLD_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_AMB_DAY_THRESHOLD_DEF_s;
187
typedef int VECTORCAST_MARKER__MACRO_END_cb_AMB_DAY_THRESHOLD_DEF_s;

typedef int VECTORCAST_MARKER__MACRO_START_cb_AMB_NIGHT_THRESHOLD_DEF_s;
135
typedef int VECTORCAST_MARKER__MACRO_END_cb_AMB_NIGHT_THRESHOLD_DEF_s;

typedef int VECTORCAST_MARKER__MACRO_START_cb_AREA_AD_g;
(byte)0x01
typedef int VECTORCAST_MARKER__MACRO_END_cb_AREA_AD_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_AREA_PD_g;
(byte)0x00
typedef int VECTORCAST_MARKER__MACRO_END_cb_AREA_PD_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_AREA_RD_g;
(byte)0x02
typedef int VECTORCAST_MARKER__MACRO_END_cb_AREA_RD_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_ASICAnalogTestbus_g;
(byte) 0x03
typedef int VECTORCAST_MARKER__MACRO_END_cb_ASICAnalogTestbus_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_ASICDiagnoseConfirmation_g;
(byte) 0x06
typedef int VECTORCAST_MARKER__MACRO_END_cb_ASICDiagnoseConfirmation_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_ASICDiagnosisRequest_g;
(byte) 0x05
typedef int VECTORCAST_MARKER__MACRO_END_cb_ASICDiagnosisRequest_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_ASICReadEEPromRequest_g;
(byte) 0x02
typedef int VECTORCAST_MARKER__MACRO_END_cb_ASICReadEEPromRequest_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_ASICStandByModeRequest_g;
(byte) 0x01
typedef int VECTORCAST_MARKER__MACRO_END_cb_ASICStandByModeRequest_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_ASICWriteConfirmation_g;
(byte) 0x07
typedef int VECTORCAST_MARKER__MACRO_END_cb_ASICWriteConfirmation_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_ASICWriteEEPromRequest_g;
(byte) 0x04
typedef int VECTORCAST_MARKER__MACRO_END_cb_ASICWriteEEPromRequest_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_ASIC_INITTIMEOUT_THRSH_g;
200
typedef int VECTORCAST_MARKER__MACRO_END_cb_ASIC_INITTIMEOUT_THRSH_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_ASIC_RS_OVERVOLTAGE_HIGH_OFF_mg;
220
typedef int VECTORCAST_MARKER__MACRO_END_cb_ASIC_RS_OVERVOLTAGE_HIGH_OFF_mg;

typedef int VECTORCAST_MARKER__MACRO_START_cb_ASIC_RS_OVERVOLTAGE_OFF_mg;
219
typedef int VECTORCAST_MARKER__MACRO_END_cb_ASIC_RS_OVERVOLTAGE_OFF_mg;

typedef int VECTORCAST_MARKER__MACRO_START_cb_ASIC_RS_OVERVOLTAGE_ON_mg;
207
typedef int VECTORCAST_MARKER__MACRO_END_cb_ASIC_RS_OVERVOLTAGE_ON_mg;

typedef int VECTORCAST_MARKER__MACRO_START_cb_ASIC_SPI_ERRORCODE_CNT_THRSHD_g;
100
typedef int VECTORCAST_MARKER__MACRO_END_cb_ASIC_SPI_ERRORCODE_CNT_THRSHD_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_AUDI_KS_THRESHOLD_RS_DAY_MODE_mg;
((byte)5*((EEPROM_Struct_AD . EEPROMStructAD . RainNightBitThrs_g&0x0F)+1))
typedef int VECTORCAST_MARKER__MACRO_END_cb_AUDI_KS_THRESHOLD_RS_DAY_MODE_mg;

typedef int VECTORCAST_MARKER__MACRO_START_cb_AUDI_KS_THRESHOLD_RS_NIGHT_MODE_mg;
((byte)5*((EEPROM_Struct_AD . EEPROMStructAD . RainNightBitThrs_g>>4)+1))
typedef int VECTORCAST_MARKER__MACRO_END_cb_AUDI_KS_THRESHOLD_RS_NIGHT_MODE_mg;

typedef int VECTORCAST_MARKER__MACRO_START_cb_CHK_MAX_g;
2
typedef int VECTORCAST_MARKER__MACRO_END_cb_CHK_MAX_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_CHK_MIN_g;
1
typedef int VECTORCAST_MARKER__MACRO_END_cb_CHK_MIN_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_CLOCKFREQ_ERROR_CNT_THRESHOLD_g;
5
typedef int VECTORCAST_MARKER__MACRO_END_cb_CLOCKFREQ_ERROR_CNT_THRESHOLD_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_ChangeCluster_AD_mg;
(byte)0x02
typedef int VECTORCAST_MARKER__MACRO_END_cb_ChangeCluster_AD_mg;

typedef int VECTORCAST_MARKER__MACRO_START_cb_ChangeCluster_PD_mg;
(byte)0x01
typedef int VECTORCAST_MARKER__MACRO_END_cb_ChangeCluster_PD_mg;

typedef int VECTORCAST_MARKER__MACRO_START_cb_ChangeCluster_RD_mg;
(byte)0x04
typedef int VECTORCAST_MARKER__MACRO_END_cb_ChangeCluster_RD_mg;

typedef int VECTORCAST_MARKER__MACRO_START_cb_DARKSTART_mg;
(byte) 1
typedef int VECTORCAST_MARKER__MACRO_END_cb_DARKSTART_mg;

typedef int VECTORCAST_MARKER__MACRO_START_cb_DAY;
0x01
typedef int VECTORCAST_MARKER__MACRO_END_cb_DAY;

typedef int VECTORCAST_MARKER__MACRO_START_cb_DAY_mg;
(byte) 0
typedef int VECTORCAST_MARKER__MACRO_END_cb_DAY_mg;

typedef int VECTORCAST_MARKER__MACRO_START_cb_DEFAULT_g;
0
typedef int VECTORCAST_MARKER__MACRO_END_cb_DEFAULT_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_DEPRESSED_PARK_DEBOUNCE_s;
18
typedef int VECTORCAST_MARKER__MACRO_END_cb_DEPRESSED_PARK_DEBOUNCE_s;

typedef int VECTORCAST_MARKER__MACRO_START_cb_DYN_COMP_CCD_MINUS_10to25_DEF;
0x06
typedef int VECTORCAST_MARKER__MACRO_END_cb_DYN_COMP_CCD_MINUS_10to25_DEF;

typedef int VECTORCAST_MARKER__MACRO_START_cb_DYN_COMP_CCD_MINUS_25to40_DEF;
0x03
typedef int VECTORCAST_MARKER__MACRO_END_cb_DYN_COMP_CCD_MINUS_25to40_DEF;

typedef int VECTORCAST_MARKER__MACRO_START_cb_DYN_COMP_CCD_MINUS_above40_DEF;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_cb_DYN_COMP_CCD_MINUS_above40_DEF;

typedef int VECTORCAST_MARKER__MACRO_START_cb_DYN_COMP_CCD_MINUS_belowneg5_DEF;
0x0A
typedef int VECTORCAST_MARKER__MACRO_END_cb_DYN_COMP_CCD_MINUS_belowneg5_DEF;

typedef int VECTORCAST_MARKER__MACRO_START_cb_DYN_COMP_CCD_MINUS_neg5to10_DEF;
0x08
typedef int VECTORCAST_MARKER__MACRO_END_cb_DYN_COMP_CCD_MINUS_neg5to10_DEF;

typedef int VECTORCAST_MARKER__MACRO_START_cb_E2STATUS_CLUSTERINIT_g;
5
typedef int VECTORCAST_MARKER__MACRO_END_cb_E2STATUS_CLUSTERINIT_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_E2STATUS_INITIALIZATION_g;
1
typedef int VECTORCAST_MARKER__MACRO_END_cb_E2STATUS_INITIALIZATION_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_E2STATUS_INITIALIZED_g;
3
typedef int VECTORCAST_MARKER__MACRO_END_cb_E2STATUS_INITIALIZED_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_E2STATUS_LIKEAVIRGIN_g;
2
typedef int VECTORCAST_MARKER__MACRO_END_cb_E2STATUS_LIKEAVIRGIN_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_E2STATUS_NONDEFAULT_g;
4
typedef int VECTORCAST_MARKER__MACRO_END_cb_E2STATUS_NONDEFAULT_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_E2STATUS_NOTLOADED_g;
0
typedef int VECTORCAST_MARKER__MACRO_END_cb_E2STATUS_NOTLOADED_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_E2_MaxSt2SignalLaenge_g;
(EEPROM_Struct_AD . EEPROMStructAD . E2_MaxSt2SignalLaenge)
typedef int VECTORCAST_MARKER__MACRO_END_cb_E2_MaxSt2SignalLaenge_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_EEPROM_0X1525__BYTES_g;
1
typedef int VECTORCAST_MARKER__MACRO_END_cb_EEPROM_0X1525__BYTES_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_EEPROM_0X1525__MASK_g;
0x60
typedef int VECTORCAST_MARKER__MACRO_END_cb_EEPROM_0X1525__MASK_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_EEPROM_0X1525__MAX_g;
3
typedef int VECTORCAST_MARKER__MACRO_END_cb_EEPROM_0X1525__MAX_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_EEPROM_0X1525__POSITION_g;
5
typedef int VECTORCAST_MARKER__MACRO_END_cb_EEPROM_0X1525__POSITION_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_EEPROM_0X1526__BYTES_g;
1
typedef int VECTORCAST_MARKER__MACRO_END_cb_EEPROM_0X1526__BYTES_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_EEPROM_0X1526__MASK_g;
0x1F
typedef int VECTORCAST_MARKER__MACRO_END_cb_EEPROM_0X1526__MASK_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_EEPROM_0X1526__MAX_g;
19
typedef int VECTORCAST_MARKER__MACRO_END_cb_EEPROM_0X1526__MAX_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_EEPROM_0X1526__POSITION_g;
0
typedef int VECTORCAST_MARKER__MACRO_END_cb_EEPROM_0X1526__POSITION_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_EEPROM_0X1527_1_Off__MAX_g;
10
typedef int VECTORCAST_MARKER__MACRO_END_cb_EEPROM_0X1527_1_Off__MAX_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_EEPROM_0X1527_1_On__MAX_g;
5
typedef int VECTORCAST_MARKER__MACRO_END_cb_EEPROM_0X1527_1_On__MAX_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_EEPROM_0X1527_1__MASK_g;
0xFF
typedef int VECTORCAST_MARKER__MACRO_END_cb_EEPROM_0X1527_1__MASK_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_EEPROM_0X1527_1__POSITION_g;
0
typedef int VECTORCAST_MARKER__MACRO_END_cb_EEPROM_0X1527_1__POSITION_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_EEPROM_0X1527_2__MASK_g;
0x1F
typedef int VECTORCAST_MARKER__MACRO_END_cb_EEPROM_0X1527_2__MASK_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_EEPROM_0X1527_2__MAX_g;
19
typedef int VECTORCAST_MARKER__MACRO_END_cb_EEPROM_0X1527_2__MAX_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_EEPROM_0X1527_2__POSITION_g;
0
typedef int VECTORCAST_MARKER__MACRO_END_cb_EEPROM_0X1527_2__POSITION_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_EEPROM_0X1527_3__MASK_g;
0x0F
typedef int VECTORCAST_MARKER__MACRO_END_cb_EEPROM_0X1527_3__MASK_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_EEPROM_0X1527_3__MAX_g;
10
typedef int VECTORCAST_MARKER__MACRO_END_cb_EEPROM_0X1527_3__MAX_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_EEPROM_0X1527_3__POSITION_g;
0
typedef int VECTORCAST_MARKER__MACRO_END_cb_EEPROM_0X1527_3__POSITION_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_EEPROM_0X1527__BYTES_g;
3
typedef int VECTORCAST_MARKER__MACRO_END_cb_EEPROM_0X1527__BYTES_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_EEPROM_0X1528__BYTES_g;
1
typedef int VECTORCAST_MARKER__MACRO_END_cb_EEPROM_0X1528__BYTES_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_EEPROM_0X1528__MASK_g;
0xF0
typedef int VECTORCAST_MARKER__MACRO_END_cb_EEPROM_0X1528__MASK_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_EEPROM_0X1528__MAX_g;
10
typedef int VECTORCAST_MARKER__MACRO_END_cb_EEPROM_0X1528__MAX_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_EEPROM_0X1528__POSITION_g;
4
typedef int VECTORCAST_MARKER__MACRO_END_cb_EEPROM_0X1528__POSITION_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_EEPROM_0X1529__BYTES_g;
1
typedef int VECTORCAST_MARKER__MACRO_END_cb_EEPROM_0X1529__BYTES_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_EEPROM_0X1529__MASK_g;
0xE0
typedef int VECTORCAST_MARKER__MACRO_END_cb_EEPROM_0X1529__MASK_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_EEPROM_0X1529__MAX_g;
4
typedef int VECTORCAST_MARKER__MACRO_END_cb_EEPROM_0X1529__MAX_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_EEPROM_0X1529__POSITION_g;
5
typedef int VECTORCAST_MARKER__MACRO_END_cb_EEPROM_0X1529__POSITION_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_EEPROM_0X152A__BYTES_g;
1
typedef int VECTORCAST_MARKER__MACRO_END_cb_EEPROM_0X152A__BYTES_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_EEPROM_0X152A__MASK_g;
0x18
typedef int VECTORCAST_MARKER__MACRO_END_cb_EEPROM_0X152A__MASK_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_EEPROM_0X152A__MAX_g;
3
typedef int VECTORCAST_MARKER__MACRO_END_cb_EEPROM_0X152A__MAX_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_EEPROM_0X152A__POSITION_g;
3
typedef int VECTORCAST_MARKER__MACRO_END_cb_EEPROM_0X152A__POSITION_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_EEPROM_0X152B_1_HighDelay_Max;
6
typedef int VECTORCAST_MARKER__MACRO_END_cb_EEPROM_0X152B_1_HighDelay_Max;

typedef int VECTORCAST_MARKER__MACRO_START_cb_EEPROM_0X152B_1_LOWDelay_Max;
7
typedef int VECTORCAST_MARKER__MACRO_END_cb_EEPROM_0X152B_1_LOWDelay_Max;

typedef int VECTORCAST_MARKER__MACRO_START_cb_EEPROM_0X152B_1__MASK_g;
0x3F
typedef int VECTORCAST_MARKER__MACRO_END_cb_EEPROM_0X152B_1__MASK_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_EEPROM_0X152B_1__POSITION_g;
0
typedef int VECTORCAST_MARKER__MACRO_END_cb_EEPROM_0X152B_1__POSITION_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_EEPROM_0X152B_2_OFFDELAY_Max;
8
typedef int VECTORCAST_MARKER__MACRO_END_cb_EEPROM_0X152B_2_OFFDELAY_Max;

typedef int VECTORCAST_MARKER__MACRO_START_cb_EEPROM_0X152B_2_THRESH_Max;
8
typedef int VECTORCAST_MARKER__MACRO_END_cb_EEPROM_0X152B_2_THRESH_Max;

typedef int VECTORCAST_MARKER__MACRO_START_cb_EEPROM_0X152B_2__MASK_g;
0xFF
typedef int VECTORCAST_MARKER__MACRO_END_cb_EEPROM_0X152B_2__MASK_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_EEPROM_0X152B_2__POSITION_g;
0
typedef int VECTORCAST_MARKER__MACRO_END_cb_EEPROM_0X152B_2__POSITION_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_EEPROM_0X152B__BYTES_g;
2
typedef int VECTORCAST_MARKER__MACRO_END_cb_EEPROM_0X152B__BYTES_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_EEPROM_0X152C__BYTES_g;
1
typedef int VECTORCAST_MARKER__MACRO_END_cb_EEPROM_0X152C__BYTES_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_EEPROM_0X152C__MASK_g;
0xFF
typedef int VECTORCAST_MARKER__MACRO_END_cb_EEPROM_0X152C__MASK_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_EEPROM_0X152C__MAX_g;
0xFF
typedef int VECTORCAST_MARKER__MACRO_END_cb_EEPROM_0X152C__MAX_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_EEPROM_0X152C__POSITION_g;
0
typedef int VECTORCAST_MARKER__MACRO_END_cb_EEPROM_0X152C__POSITION_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_EEPROM_CANTREAD_g;
4
typedef int VECTORCAST_MARKER__MACRO_END_cb_EEPROM_CANTREAD_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_EEPROM_CELLEMPTY_g;
8
typedef int VECTORCAST_MARKER__MACRO_END_cb_EEPROM_CELLEMPTY_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_EEPROM_DOUBLEERROR_INVALIDCORRECTION_g;
2
typedef int VECTORCAST_MARKER__MACRO_END_cb_EEPROM_DOUBLEERROR_INVALIDCORRECTION_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_EEPROM_NOERROR_g;
0
typedef int VECTORCAST_MARKER__MACRO_END_cb_EEPROM_NOERROR_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_EEPROM_SINGLEERROR_CORRECTED_g;
1
typedef int VECTORCAST_MARKER__MACRO_END_cb_EEPROM_SINGLEERROR_CORRECTED_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_FASTTASKCALLS_MAX_mg;
((byte)((((byte)7)*20) + (byte)10))
typedef int VECTORCAST_MARKER__MACRO_END_cb_FASTTASKCALLS_MAX_mg;

typedef int VECTORCAST_MARKER__MACRO_START_cb_FASTTASKCALLS_MIN_mg;
((byte)((((byte)7)*20) - (byte)10))
typedef int VECTORCAST_MARKER__MACRO_END_cb_FASTTASKCALLS_MIN_mg;

typedef int VECTORCAST_MARKER__MACRO_START_cb_FASTTASKCALL_TOLERANCE_mg;
(byte)10
typedef int VECTORCAST_MARKER__MACRO_END_cb_FASTTASKCALL_TOLERANCE_mg;

typedef int VECTORCAST_MARKER__MACRO_START_cb_FOUR_SECOND_DELAY_mg;
25
typedef int VECTORCAST_MARKER__MACRO_END_cb_FOUR_SECOND_DELAY_mg;

typedef int VECTORCAST_MARKER__MACRO_START_cb_FW_DAY_THRESHOLD_DEF_s;
180
typedef int VECTORCAST_MARKER__MACRO_END_cb_FW_DAY_THRESHOLD_DEF_s;

typedef int VECTORCAST_MARKER__MACRO_START_cb_FW_NIGHT_THRESHOLD_DEF_s;
135
typedef int VECTORCAST_MARKER__MACRO_END_cb_FW_NIGHT_THRESHOLD_DEF_s;

typedef int VECTORCAST_MARKER__MACRO_START_cb_GOTOSLEEPVOLTAGE_mg;
(byte) 52
typedef int VECTORCAST_MARKER__MACRO_END_cb_GOTOSLEEPVOLTAGE_mg;

typedef int VECTORCAST_MARKER__MACRO_START_cb_HANDLE_BCM1_LIN1_01_g;
13
typedef int VECTORCAST_MARKER__MACRO_END_cb_HANDLE_BCM1_LIN1_01_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_HANDLE_BCM1_LIN1_02_g;
12
typedef int VECTORCAST_MARKER__MACRO_END_cb_HANDLE_BCM1_LIN1_02_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_HANDLE_BCM1_LIN1_03_g;
11
typedef int VECTORCAST_MARKER__MACRO_END_cb_HANDLE_BCM1_LIN1_03_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_HANDLE_BCM1_LIN1_04_g;
10
typedef int VECTORCAST_MARKER__MACRO_END_cb_HANDLE_BCM1_LIN1_04_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_HANDLE_BCM1_LIN1_05_g;
9
typedef int VECTORCAST_MARKER__MACRO_END_cb_HANDLE_BCM1_LIN1_05_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_HANDLE_CemCem_Lin1Fr01_CEM_LIN1;
13
typedef int VECTORCAST_MARKER__MACRO_END_cb_HANDLE_CemCem_Lin1Fr01_CEM_LIN1;

typedef int VECTORCAST_MARKER__MACRO_START_cb_HANDLE_CemCem_Lin1Fr02_CEM_LIN1;
12
typedef int VECTORCAST_MARKER__MACRO_END_cb_HANDLE_CemCem_Lin1Fr02_CEM_LIN1;

typedef int VECTORCAST_MARKER__MACRO_START_cb_HANDLE_CemCem_Lin1Fr03_CEM_LIN1;
11
typedef int VECTORCAST_MARKER__MACRO_END_cb_HANDLE_CemCem_Lin1Fr03_CEM_LIN1;

typedef int VECTORCAST_MARKER__MACRO_START_cb_HANDLE_CemCem_Lin1Fr04_CEM_LIN1;
10
typedef int VECTORCAST_MARKER__MACRO_END_cb_HANDLE_CemCem_Lin1Fr04_CEM_LIN1;

typedef int VECTORCAST_MARKER__MACRO_START_cb_HANDLE_CemCem_Lin1Fr05_CEM_LIN1;
9
typedef int VECTORCAST_MARKER__MACRO_END_cb_HANDLE_CemCem_Lin1Fr05_CEM_LIN1;

typedef int VECTORCAST_MARKER__MACRO_START_cb_HANDLE_CemCem_Lin1Fr06_CEM_LIN1;
8
typedef int VECTORCAST_MARKER__MACRO_END_cb_HANDLE_CemCem_Lin1Fr06_CEM_LIN1;

typedef int VECTORCAST_MARKER__MACRO_START_cb_HANDLE_LinReqCmd;
7
typedef int VECTORCAST_MARKER__MACRO_END_cb_HANDLE_LinReqCmd;

typedef int VECTORCAST_MARKER__MACRO_START_cb_HANDLE_LinReqCmd_g;
7
typedef int VECTORCAST_MARKER__MACRO_END_cb_HANDLE_LinReqCmd_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_HANDLE_LinRespCmd;
0
typedef int VECTORCAST_MARKER__MACRO_END_cb_HANDLE_LinRespCmd;

typedef int VECTORCAST_MARKER__MACRO_START_cb_HANDLE_LinRespCmd_g;
0
typedef int VECTORCAST_MARKER__MACRO_END_cb_HANDLE_LinRespCmd_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_HANDLE_RLSs_01_g;
6
typedef int VECTORCAST_MARKER__MACRO_END_cb_HANDLE_RLSs_01_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_HANDLE_RLSs_02_g;
3
typedef int VECTORCAST_MARKER__MACRO_END_cb_HANDLE_RLSs_02_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_HANDLE_RLSs_03_g;
1
typedef int VECTORCAST_MARKER__MACRO_END_cb_HANDLE_RLSs_03_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_HANDLE_RLSs_04_g;
2
typedef int VECTORCAST_MARKER__MACRO_END_cb_HANDLE_RLSs_04_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_HANDLE_RLSs_05_g;
5
typedef int VECTORCAST_MARKER__MACRO_END_cb_HANDLE_RLSs_05_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_HANDLE_RLSs_06_g;
4
typedef int VECTORCAST_MARKER__MACRO_END_cb_HANDLE_RLSs_06_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_HANDLE_RlsmCem_Lin1Fr01_CEM_LIN1;
6
typedef int VECTORCAST_MARKER__MACRO_END_cb_HANDLE_RlsmCem_Lin1Fr01_CEM_LIN1;

typedef int VECTORCAST_MARKER__MACRO_START_cb_HANDLE_RlsmCem_Lin1Fr02_CEM_LIN1;
5
typedef int VECTORCAST_MARKER__MACRO_END_cb_HANDLE_RlsmCem_Lin1Fr02_CEM_LIN1;

typedef int VECTORCAST_MARKER__MACRO_START_cb_HANDLE_RlsmCem_Lin1Fr03_CEM_LIN1;
4
typedef int VECTORCAST_MARKER__MACRO_END_cb_HANDLE_RlsmCem_Lin1Fr03_CEM_LIN1;

typedef int VECTORCAST_MARKER__MACRO_START_cb_HANDLE_RlsmCem_Lin1PartNrFr01_CEM_LIN1;
3
typedef int VECTORCAST_MARKER__MACRO_END_cb_HANDLE_RlsmCem_Lin1PartNrFr01_CEM_LIN1;

typedef int VECTORCAST_MARKER__MACRO_START_cb_HANDLE_RlsmCem_Lin1PartNrFr02_CEM_LIN1;
2
typedef int VECTORCAST_MARKER__MACRO_END_cb_HANDLE_RlsmCem_Lin1PartNrFr02_CEM_LIN1;

typedef int VECTORCAST_MARKER__MACRO_START_cb_HANDLE_RlsmCem_SerNrLin1Fr01_CEM_LIN1;
1
typedef int VECTORCAST_MARKER__MACRO_END_cb_HANDLE_RlsmCem_SerNrLin1Fr01_CEM_LIN1;

typedef int VECTORCAST_MARKER__MACRO_START_cb_HANDLE_WWSs_01_g;
8
typedef int VECTORCAST_MARKER__MACRO_END_cb_HANDLE_WWSs_01_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_HARDWARESTAND_0_g;
'0'
typedef int VECTORCAST_MARKER__MACRO_END_cb_HARDWARESTAND_0_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_HARDWARESTAND_1_g;
'1'
typedef int VECTORCAST_MARKER__MACRO_END_cb_HARDWARESTAND_1_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_HARDWARESTAND_g;
'H'
typedef int VECTORCAST_MARKER__MACRO_END_cb_HARDWARESTAND_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_HEATEROFF_g;
0
typedef int VECTORCAST_MARKER__MACRO_END_cb_HEATEROFF_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_HEATERON_g;
1
typedef int VECTORCAST_MARKER__MACRO_END_cb_HEATERON_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_HIGH_SPEED;
0x20
typedef int VECTORCAST_MARKER__MACRO_END_cb_HIGH_SPEED;

typedef int VECTORCAST_MARKER__MACRO_START_cb_HTERR_CHECKSUM_g;
0x01
typedef int VECTORCAST_MARKER__MACRO_END_cb_HTERR_CHECKSUM_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_HTERR_HUMIOUTOFRANGE_g;
0x08
typedef int VECTORCAST_MARKER__MACRO_END_cb_HTERR_HUMIOUTOFRANGE_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_HTERR_NONE_g;
0
typedef int VECTORCAST_MARKER__MACRO_END_cb_HTERR_NONE_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_HTERR_TEMPOUTOFRANGE_g;
0x10
typedef int VECTORCAST_MARKER__MACRO_END_cb_HTERR_TEMPOUTOFRANGE_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_HTERR_TIMEOUT_g;
0x04
typedef int VECTORCAST_MARKER__MACRO_END_cb_HTERR_TIMEOUT_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_HTERR_WRITECMD_g;
0x02
typedef int VECTORCAST_MARKER__MACRO_END_cb_HTERR_WRITECMD_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_HUMIDITY_SOLAR;
0x8A
typedef int VECTORCAST_MARKER__MACRO_END_cb_HUMIDITY_SOLAR;

typedef int VECTORCAST_MARKER__MACRO_START_cb_HUMI_ERROR_g;
0xFF
typedef int VECTORCAST_MARKER__MACRO_END_cb_HUMI_ERROR_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_IGNORE_IGNITION_SPEED;
4
typedef int VECTORCAST_MARKER__MACRO_END_cb_IGNORE_IGNITION_SPEED;

typedef int VECTORCAST_MARKER__MACRO_START_cb_INITAL_TARGET_ADDRESS_s;
0x03
typedef int VECTORCAST_MARKER__MACRO_END_cb_INITAL_TARGET_ADDRESS_s;

typedef int VECTORCAST_MARKER__MACRO_START_cb_IR_DAY_THRESHOLD_DEF_s;
90
typedef int VECTORCAST_MARKER__MACRO_END_cb_IR_DAY_THRESHOLD_DEF_s;

typedef int VECTORCAST_MARKER__MACRO_START_cb_IR_NIGHT_THRESHOLD_DEF_s;
68
typedef int VECTORCAST_MARKER__MACRO_END_cb_IR_NIGHT_THRESHOLD_DEF_s;

typedef int VECTORCAST_MARKER__MACRO_START_cb_JumpAfterShtPowerFail;
65
typedef int VECTORCAST_MARKER__MACRO_END_cb_JumpAfterShtPowerFail;

typedef int VECTORCAST_MARKER__MACRO_START_cb_LCLOSED_45perCent_THRS_g;
10
typedef int VECTORCAST_MARKER__MACRO_END_cb_LCLOSED_45perCent_THRS_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_LIN_BITERROR_g;
(byte) 0x01
typedef int VECTORCAST_MARKER__MACRO_END_cb_LIN_BITERROR_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_LIN_CHECKSUMERROR_g;
(byte) 0x10
typedef int VECTORCAST_MARKER__MACRO_END_cb_LIN_CHECKSUMERROR_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_LIN_FRAMINGERROR_g;
(byte) 0x80
typedef int VECTORCAST_MARKER__MACRO_END_cb_LIN_FRAMINGERROR_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_LIN_IDPARITYERROR_g;
(byte) 0x02
typedef int VECTORCAST_MARKER__MACRO_END_cb_LIN_IDPARITYERROR_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_LIN_INCOMPLETEMSGERROR_g;
(byte) 0x08
typedef int VECTORCAST_MARKER__MACRO_END_cb_LIN_INCOMPLETEMSGERROR_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_LIN_NOERROR_g;
(byte) 0x00
typedef int VECTORCAST_MARKER__MACRO_END_cb_LIN_NOERROR_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_LIN_NORESPONSE_g;
(byte) 0x40
typedef int VECTORCAST_MARKER__MACRO_END_cb_LIN_NORESPONSE_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_LIN_OVERTFRAMEMAX_g;
(byte) 0x04
typedef int VECTORCAST_MARKER__MACRO_END_cb_LIN_OVERTFRAMEMAX_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_LIN_OVERTHEADERMAX_g;
(byte) 0x20
typedef int VECTORCAST_MARKER__MACRO_END_cb_LIN_OVERTHEADERMAX_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_LIN_PHYSICALBUSERROR_g;
(byte) 0x81
typedef int VECTORCAST_MARKER__MACRO_END_cb_LIN_PHYSICALBUSERROR_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_LOWER_RAM_BOARDER_s;
0xFF30AU
typedef int VECTORCAST_MARKER__MACRO_END_cb_LOWER_RAM_BOARDER_s;

typedef int VECTORCAST_MARKER__MACRO_START_cb_MEAN_HIGHWAY_LIGHT_SPEED_DEF_mg;
(byte)140
typedef int VECTORCAST_MARKER__MACRO_END_cb_MEAN_HIGHWAY_LIGHT_SPEED_DEF_mg;

typedef int VECTORCAST_MARKER__MACRO_START_cb_MIN_HIGHWAY_SPEED_DEF_mg;
(byte)65
typedef int VECTORCAST_MARKER__MACRO_END_cb_MIN_HIGHWAY_SPEED_DEF_mg;

typedef int VECTORCAST_MARKER__MACRO_START_cb_MS_DELAY_OVERVOLTAGE_s;
2000
typedef int VECTORCAST_MARKER__MACRO_END_cb_MS_DELAY_OVERVOLTAGE_s;

typedef int VECTORCAST_MARKER__MACRO_START_cb_NIGHT_mg;
(byte) 2
typedef int VECTORCAST_MARKER__MACRO_END_cb_NIGHT_mg;

typedef int VECTORCAST_MARKER__MACRO_START_cb_NORMAL_WIPE_MODE;
1
typedef int VECTORCAST_MARKER__MACRO_END_cb_NORMAL_WIPE_MODE;

typedef int VECTORCAST_MARKER__MACRO_START_cb_NUM_CLUSTER_mg;
(byte)4
typedef int VECTORCAST_MARKER__MACRO_END_cb_NUM_CLUSTER_mg;

typedef int VECTORCAST_MARKER__MACRO_START_cb_NUM_EEPROM_AREAS_g;
(byte)3
typedef int VECTORCAST_MARKER__MACRO_END_cb_NUM_EEPROM_AREAS_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_Night;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_cb_Night;

typedef int VECTORCAST_MARKER__MACRO_START_cb_NumberofEEPROMCells_AD_g;
194
typedef int VECTORCAST_MARKER__MACRO_END_cb_NumberofEEPROMCells_AD_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_NumberofEEPROMCells_PD_g;
(93)
typedef int VECTORCAST_MARKER__MACRO_END_cb_NumberofEEPROMCells_PD_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_NumberofEEPROMCells_RD_g;
31
typedef int VECTORCAST_MARKER__MACRO_END_cb_NumberofEEPROMCells_RD_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_ONLY_HUMIDITY;
0x98
typedef int VECTORCAST_MARKER__MACRO_END_cb_ONLY_HUMIDITY;

typedef int VECTORCAST_MARKER__MACRO_START_cb_ONLY_RAIN;
0x01
typedef int VECTORCAST_MARKER__MACRO_END_cb_ONLY_RAIN;

typedef int VECTORCAST_MARKER__MACRO_START_cb_OTHERRSEAN;
0x40
typedef int VECTORCAST_MARKER__MACRO_END_cb_OTHERRSEAN;

typedef int VECTORCAST_MARKER__MACRO_START_cb_OTHER_TARGET_ADDRESS_s;
0xF0
typedef int VECTORCAST_MARKER__MACRO_END_cb_OTHER_TARGET_ADDRESS_s;

typedef int VECTORCAST_MARKER__MACRO_START_cb_POSITIONDEFAULTSOFTWARE;
(148)
typedef int VECTORCAST_MARKER__MACRO_END_cb_POSITIONDEFAULTSOFTWARE;

typedef int VECTORCAST_MARKER__MACRO_START_cb_RAIN_LIGHT;
0x04
typedef int VECTORCAST_MARKER__MACRO_END_cb_RAIN_LIGHT;

typedef int VECTORCAST_MARKER__MACRO_START_cb_RAIN_ON_BRIGHTNESS_KS_g;
(byte)( (((EEPROM_Struct_AD . EEPROMStructAD . p_n_regenlichtschwelle_Zeit_g&0x0f)*((5*(byte)5)/8))+((unsigned int)(40*(byte)5)/8)))
typedef int VECTORCAST_MARKER__MACRO_END_cb_RAIN_ON_BRIGHTNESS_KS_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_RAM_GUARD_LENGTH_g;
256
typedef int VECTORCAST_MARKER__MACRO_END_cb_RAM_GUARD_LENGTH_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_RAM_GUARD_START_g;
0xFF000U
typedef int VECTORCAST_MARKER__MACRO_END_cb_RAM_GUARD_START_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_REQLENGTHSID34_s;
5
typedef int VECTORCAST_MARKER__MACRO_END_cb_REQLENGTHSID34_s;

typedef int VECTORCAST_MARKER__MACRO_START_cb_REQLENGTHSID35_s;
5
typedef int VECTORCAST_MARKER__MACRO_END_cb_REQLENGTHSID35_s;

typedef int VECTORCAST_MARKER__MACRO_START_cb_REQLENGTHSIDB0_s;
6
typedef int VECTORCAST_MARKER__MACRO_END_cb_REQLENGTHSIDB0_s;

typedef int VECTORCAST_MARKER__MACRO_START_cb_REQLENGTHSIDB1_s;
6
typedef int VECTORCAST_MARKER__MACRO_END_cb_REQLENGTHSIDB1_s;

typedef int VECTORCAST_MARKER__MACRO_START_cb_REQLENGTHSIDB2_s;
6
typedef int VECTORCAST_MARKER__MACRO_END_cb_REQLENGTHSIDB2_s;

typedef int VECTORCAST_MARKER__MACRO_START_cb_REQLENGTHSIDB3_s;
6
typedef int VECTORCAST_MARKER__MACRO_END_cb_REQLENGTHSIDB3_s;

typedef int VECTORCAST_MARKER__MACRO_START_cb_REQUEST_DOWNLOAD_s;
0x34
typedef int VECTORCAST_MARKER__MACRO_END_cb_REQUEST_DOWNLOAD_s;

typedef int VECTORCAST_MARKER__MACRO_START_cb_REQUEST_UPLOAD_s;
0x35
typedef int VECTORCAST_MARKER__MACRO_END_cb_REQUEST_UPLOAD_s;

typedef int VECTORCAST_MARKER__MACRO_START_cb_Regulation48LightOnTime_g;
EEPROM_Struct_AD . EEPROMStructAD . Regulation48LightOnTime_g
typedef int VECTORCAST_MARKER__MACRO_END_cb_Regulation48LightOnTime_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_SOFTWARESTAND_0_g;
'0'
typedef int VECTORCAST_MARKER__MACRO_END_cb_SOFTWARESTAND_0_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_SOFTWARESTAND_1_g;
'0'
typedef int VECTORCAST_MARKER__MACRO_END_cb_SOFTWARESTAND_1_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_SOFTWARESTAND_2_g;
'0'
typedef int VECTORCAST_MARKER__MACRO_END_cb_SOFTWARESTAND_2_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_SOFTWARESTAND_3_g;
'1'
typedef int VECTORCAST_MARKER__MACRO_END_cb_SOFTWARESTAND_3_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_START_RS_ASICVOLTAGE_mg;
(byte) 99
typedef int VECTORCAST_MARKER__MACRO_END_cb_START_RS_ASICVOLTAGE_mg;

typedef int VECTORCAST_MARKER__MACRO_START_cb_STOP_RS_ASICVOLTAGE_mg;
AD_ADUL_VALUE
typedef int VECTORCAST_MARKER__MACRO_END_cb_STOP_RS_ASICVOLTAGE_mg;

typedef int VECTORCAST_MARKER__MACRO_START_cb_SUPPLYVOLTAGE_DEF_g;
160
typedef int VECTORCAST_MARKER__MACRO_END_cb_SUPPLYVOLTAGE_DEF_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_SWSTANDEEPROM_23_g;
((('0' - '0')*16)+('1' - '0'))
typedef int VECTORCAST_MARKER__MACRO_END_cb_SWSTANDEEPROM_23_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_SWSTAND_ADD_ON_NO_RAIN_g;
('D' +32)
typedef int VECTORCAST_MARKER__MACRO_END_cb_SWSTAND_ADD_ON_NO_RAIN_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_SWSTAND_ADD_ON_WITH_RAIN_g;
'D'
typedef int VECTORCAST_MARKER__MACRO_END_cb_SWSTAND_ADD_ON_WITH_RAIN_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_SWSTAND_ADD_ON_g;
'D'
typedef int VECTORCAST_MARKER__MACRO_END_cb_SWSTAND_ADD_ON_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_TARGET_ADDRESS_s;
EEPROM_Struct_PD . EEPROMStructPD . NAD
typedef int VECTORCAST_MARKER__MACRO_END_cb_TARGET_ADDRESS_s;

typedef int VECTORCAST_MARKER__MACRO_START_cb_TA_DEVELOPEMENT_s;
0xA0
typedef int VECTORCAST_MARKER__MACRO_END_cb_TA_DEVELOPEMENT_s;

typedef int VECTORCAST_MARKER__MACRO_START_cb_TEMPSENSOR_MAX_mg;
254
typedef int VECTORCAST_MARKER__MACRO_END_cb_TEMPSENSOR_MAX_mg;

typedef int VECTORCAST_MARKER__MACRO_START_cb_TEMP_ASIC_AD65DEGREES_THRS_g;
527
typedef int VECTORCAST_MARKER__MACRO_END_cb_TEMP_ASIC_AD65DEGREES_THRS_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_TEMP_ASIC_AD90DEGREES_THRS_g;
485
typedef int VECTORCAST_MARKER__MACRO_END_cb_TEMP_ASIC_AD90DEGREES_THRS_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_TEMP_ASIC_AD95DEGREES_THRS_g;
367
typedef int VECTORCAST_MARKER__MACRO_END_cb_TEMP_ASIC_AD95DEGREES_THRS_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_TEMP_uC_AD65DEGREES_THRS_g;
70
typedef int VECTORCAST_MARKER__MACRO_END_cb_TEMP_uC_AD65DEGREES_THRS_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_TEMP_uC_AD90DEGREES_THRS_g;
63
typedef int VECTORCAST_MARKER__MACRO_END_cb_TEMP_uC_AD90DEGREES_THRS_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_TEMP_uC_AD95DEGREES_THRS_g;
62
typedef int VECTORCAST_MARKER__MACRO_END_cb_TEMP_uC_AD95DEGREES_THRS_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_THRES_RSACTION_mg;
50
typedef int VECTORCAST_MARKER__MACRO_END_cb_THRES_RSACTION_mg;

typedef int VECTORCAST_MARKER__MACRO_START_cb_TIMETOREACH_FASTHIGHWAY_MODE_Def_mg;
208
typedef int VECTORCAST_MARKER__MACRO_END_cb_TIMETOREACH_FASTHIGHWAY_MODE_Def_mg;

typedef int VECTORCAST_MARKER__MACRO_START_cb_TIME_TO_WAIT_FOR_VDD_g;
3
typedef int VECTORCAST_MARKER__MACRO_END_cb_TIME_TO_WAIT_FOR_VDD_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_TIME_TO_WAIT_LONG_FOR_VDD_g;
5
typedef int VECTORCAST_MARKER__MACRO_END_cb_TIME_TO_WAIT_LONG_FOR_VDD_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_TRANSFER_DATA_REQUEST_s;
0x36
typedef int VECTORCAST_MARKER__MACRO_END_cb_TRANSFER_DATA_REQUEST_s;

typedef int VECTORCAST_MARKER__MACRO_START_cb_TUNNEL;
0x03
typedef int VECTORCAST_MARKER__MACRO_END_cb_TUNNEL;

typedef int VECTORCAST_MARKER__MACRO_START_cb_TUNNEL_mg;
(byte) 4
typedef int VECTORCAST_MARKER__MACRO_END_cb_TUNNEL_mg;

typedef int VECTORCAST_MARKER__MACRO_START_cb_TWILIGHT;
0x02
typedef int VECTORCAST_MARKER__MACRO_END_cb_TWILIGHT;

typedef int VECTORCAST_MARKER__MACRO_START_cb_UNASSIGNED_FRAMEID_g;
0x40
typedef int VECTORCAST_MARKER__MACRO_END_cb_UNASSIGNED_FRAMEID_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_UNDERGROUND;
0x10
typedef int VECTORCAST_MARKER__MACRO_END_cb_UNDERGROUND;

typedef int VECTORCAST_MARKER__MACRO_START_cb_UPPER_RAM_BOARDER_s;
0xFFE1FU
typedef int VECTORCAST_MARKER__MACRO_END_cb_UPPER_RAM_BOARDER_s;

typedef int VECTORCAST_MARKER__MACRO_START_cb_VARIANTE_g;
0x00
typedef int VECTORCAST_MARKER__MACRO_END_cb_VARIANTE_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_VERGLSUNG_CLOSE_DELAY_mg;
100
typedef int VECTORCAST_MARKER__MACRO_END_cb_VERGLSUNG_CLOSE_DELAY_mg;

typedef int VECTORCAST_MARKER__MACRO_START_cb_VERGLSUNG_OPEN_DELAY_mg;
100
typedef int VECTORCAST_MARKER__MACRO_END_cb_VERGLSUNG_OPEN_DELAY_mg;

typedef int VECTORCAST_MARKER__MACRO_START_cb_VERYLOWVOLTAGE_mg;
(byte) 7
typedef int VECTORCAST_MARKER__MACRO_END_cb_VERYLOWVOLTAGE_mg;

typedef int VECTORCAST_MARKER__MACRO_START_cb_VIREF_ERRCNT_MAX_g;
50
typedef int VECTORCAST_MARKER__MACRO_END_cb_VIREF_ERRCNT_MAX_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_WDGCALLCOUNTERCYCLE_mg;
(byte)7
typedef int VECTORCAST_MARKER__MACRO_END_cb_WDGCALLCOUNTERCYCLE_mg;

typedef int VECTORCAST_MARKER__MACRO_START_cb_WDG_STB_10MSTIMEOUT_g;
7
typedef int VECTORCAST_MARKER__MACRO_END_cb_WDG_STB_10MSTIMEOUT_g;

typedef int VECTORCAST_MARKER__MACRO_START_cb_WINTER_WIPE_MODE;
2
typedef int VECTORCAST_MARKER__MACRO_END_cb_WINTER_WIPE_MODE;

typedef int VECTORCAST_MARKER__MACRO_START_cb_WIPETHRESHOLD_RAINLIGHT_BRIGHT_KS_mg;
((EEPROM_Struct_AD . EEPROMStructAD . p_n_regenlichtschwelle_low_high_g & 0x07)+9)
typedef int VECTORCAST_MARKER__MACRO_END_cb_WIPETHRESHOLD_RAINLIGHT_BRIGHT_KS_mg;

typedef int VECTORCAST_MARKER__MACRO_START_cb_WIPETHRESHOLD_RAINLIGHT_BRIGHT_mg;
((EEPROM_Struct_AD . EEPROMStructAD . p_n_regenlichtschwelle_low_high_g & 0x07)+9)
typedef int VECTORCAST_MARKER__MACRO_END_cb_WIPETHRESHOLD_RAINLIGHT_BRIGHT_mg;

typedef int VECTORCAST_MARKER__MACRO_START_cb_WIPETHRESHOLD_RAINLIGHT_DARK_KS_mg;
(((EEPROM_Struct_AD . EEPROMStructAD . p_n_regenlichtschwelle_low_high_g >>3)& 0x07)+3)
typedef int VECTORCAST_MARKER__MACRO_END_cb_WIPETHRESHOLD_RAINLIGHT_DARK_KS_mg;

typedef int VECTORCAST_MARKER__MACRO_START_cb_WIPETHRESHOLD_RAINLIGHT_DARK_mg;
(((EEPROM_Struct_AD . EEPROMStructAD . p_n_regenlichtschwelle_low_high_g >>3)& 0x07)+3)
typedef int VECTORCAST_MARKER__MACRO_END_cb_WIPETHRESHOLD_RAINLIGHT_DARK_mg;

typedef int VECTORCAST_MARKER__MACRO_START_cw_ADREEPROM_END_g;
(unsigned int)0x3FF
typedef int VECTORCAST_MARKER__MACRO_END_cw_ADREEPROM_END_g;

typedef int VECTORCAST_MARKER__MACRO_START_cw_ADREEPROM_START_g;
(unsigned int)0x100
typedef int VECTORCAST_MARKER__MACRO_END_cw_ADREEPROM_START_g;

typedef int VECTORCAST_MARKER__MACRO_START_cw_ADRPRE_AD_mg;
(unsigned int)0x0200
typedef int VECTORCAST_MARKER__MACRO_END_cw_ADRPRE_AD_mg;

typedef int VECTORCAST_MARKER__MACRO_START_cw_ADRPRE_PD_mg;
(unsigned int)0x0100
typedef int VECTORCAST_MARKER__MACRO_END_cw_ADRPRE_PD_mg;

typedef int VECTORCAST_MARKER__MACRO_START_cw_ADRPRE_RD_mg;
(unsigned int)0x0300
typedef int VECTORCAST_MARKER__MACRO_END_cw_ADRPRE_RD_mg;

typedef int VECTORCAST_MARKER__MACRO_START_cw_ADRSELMASK_mg;
(unsigned int)0x0300
typedef int VECTORCAST_MARKER__MACRO_END_cw_ADRSELMASK_mg;

typedef int VECTORCAST_MARKER__MACRO_START_cw_ALS1_4_SETTING_ADDRESS_g;
271
typedef int VECTORCAST_MARKER__MACRO_END_cw_ALS1_4_SETTING_ADDRESS_g;

typedef int VECTORCAST_MARKER__MACRO_START_cw_ALS5_6_INREC_SETTING_ADDRESS_g;
272
typedef int VECTORCAST_MARKER__MACRO_END_cw_ALS5_6_INREC_SETTING_ADDRESS_g;

typedef int VECTORCAST_MARKER__MACRO_START_cw_CLEARWIPE_DELAY_s;
400
typedef int VECTORCAST_MARKER__MACRO_END_cw_CLEARWIPE_DELAY_s;

typedef int VECTORCAST_MARKER__MACRO_START_cw_DAY_DELAY_DEF_s;
(unsigned int)(2*3000)
typedef int VECTORCAST_MARKER__MACRO_END_cw_DAY_DELAY_DEF_s;

typedef int VECTORCAST_MARKER__MACRO_START_cw_DEWPOINT_MAX_mg;
(1650)
typedef int VECTORCAST_MARKER__MACRO_END_cw_DEWPOINT_MAX_mg;

typedef int VECTORCAST_MARKER__MACRO_START_cw_EEPROM_0X1525__ADDRESS_g;
(519 + (((EEPROM_Struct_PD . EEPROMStructPD . EEKodierbyte1_g & 12)>>2) * 17))
typedef int VECTORCAST_MARKER__MACRO_END_cw_EEPROM_0X1525__ADDRESS_g;

typedef int VECTORCAST_MARKER__MACRO_START_cw_EEPROM_0X1526__ADDRESS_g;
607
typedef int VECTORCAST_MARKER__MACRO_END_cw_EEPROM_0X1526__ADDRESS_g;

typedef int VECTORCAST_MARKER__MACRO_START_cw_EEPROM_0X1527_1__ADDRESS_g;
621
typedef int VECTORCAST_MARKER__MACRO_END_cw_EEPROM_0X1527_1__ADDRESS_g;

typedef int VECTORCAST_MARKER__MACRO_START_cw_EEPROM_0X1527_2__ADDRESS_g;
622
typedef int VECTORCAST_MARKER__MACRO_END_cw_EEPROM_0X1527_2__ADDRESS_g;

typedef int VECTORCAST_MARKER__MACRO_START_cw_EEPROM_0X1527_3__ADDRESS_g;
623
typedef int VECTORCAST_MARKER__MACRO_END_cw_EEPROM_0X1527_3__ADDRESS_g;

typedef int VECTORCAST_MARKER__MACRO_START_cw_EEPROM_0X1528__ADDRESS_g;
623
typedef int VECTORCAST_MARKER__MACRO_END_cw_EEPROM_0X1528__ADDRESS_g;

typedef int VECTORCAST_MARKER__MACRO_START_cw_EEPROM_0X1529__ADDRESS_g;
622
typedef int VECTORCAST_MARKER__MACRO_END_cw_EEPROM_0X1529__ADDRESS_g;

typedef int VECTORCAST_MARKER__MACRO_START_cw_EEPROM_0X152A__ADDRESS_g;
620
typedef int VECTORCAST_MARKER__MACRO_END_cw_EEPROM_0X152A__ADDRESS_g;

typedef int VECTORCAST_MARKER__MACRO_START_cw_EEPROM_0X152B_1__ADDRESS_g;
624
typedef int VECTORCAST_MARKER__MACRO_END_cw_EEPROM_0X152B_1__ADDRESS_g;

typedef int VECTORCAST_MARKER__MACRO_START_cw_EEPROM_0X152B_2__ADDRESS_g;
625
typedef int VECTORCAST_MARKER__MACRO_END_cw_EEPROM_0X152B_2__ADDRESS_g;

typedef int VECTORCAST_MARKER__MACRO_START_cw_EEPROM_0X152C__ADDRESS_g;
608
typedef int VECTORCAST_MARKER__MACRO_END_cw_EEPROM_0X152C__ADDRESS_g;

typedef int VECTORCAST_MARKER__MACRO_START_cw_EEPROM_CODING_ADDRESS_g;
(268)
typedef int VECTORCAST_MARKER__MACRO_END_cw_EEPROM_CODING_ADDRESS_g;

typedef int VECTORCAST_MARKER__MACRO_START_cw_FunctionID_g;
0x0000U
typedef int VECTORCAST_MARKER__MACRO_END_cw_FunctionID_g;

typedef int VECTORCAST_MARKER__MACRO_START_cw_HUMTEMP_ERROR_g;
0xFFFFU
typedef int VECTORCAST_MARKER__MACRO_END_cw_HUMTEMP_ERROR_g;

typedef int VECTORCAST_MARKER__MACRO_START_cw_HUMTEMP_INIT_g;
0
typedef int VECTORCAST_MARKER__MACRO_END_cw_HUMTEMP_INIT_g;

typedef int VECTORCAST_MARKER__MACRO_START_cw_NIGHT_DELAY_DEF_s;
(unsigned int)(2*3000)
typedef int VECTORCAST_MARKER__MACRO_END_cw_NIGHT_DELAY_DEF_s;

typedef int VECTORCAST_MARKER__MACRO_START_cw_RAIN_ON_DELAY_KS_g;
(((EEPROM_Struct_AD . EEPROMStructAD . p_n_regenlichtschwelle_Zeit_g>>4)*100)+200)
typedef int VECTORCAST_MARKER__MACRO_END_cw_RAIN_ON_DELAY_KS_g;

typedef int VECTORCAST_MARKER__MACRO_START_cw_SupplierID_g;
0x0007U
typedef int VECTORCAST_MARKER__MACRO_END_cw_SupplierID_g;

typedef int VECTORCAST_MARKER__MACRO_START_cw_TEMPSCHEIBE_MAX_mg;
(1000+4)
typedef int VECTORCAST_MARKER__MACRO_END_cw_TEMPSCHEIBE_MAX_mg;

typedef int VECTORCAST_MARKER__MACRO_START_cw_TIME_TO_REACH_NORMAL_MODE_DEF_mg;
(int) 2400
typedef int VECTORCAST_MARKER__MACRO_END_cw_TIME_TO_REACH_NORMAL_MODE_DEF_mg;

typedef int VECTORCAST_MARKER__MACRO_START_kLinNumberOfConfFlags;
7
typedef int VECTORCAST_MARKER__MACRO_END_kLinNumberOfConfFlags;

typedef int VECTORCAST_MARKER__MACRO_START_kLinNumberOfIndFlags;
7
typedef int VECTORCAST_MARKER__MACRO_END_kLinNumberOfIndFlags;

typedef int VECTORCAST_MARKER__MACRO_START_kLinNumberOfObjects;
14
typedef int VECTORCAST_MARKER__MACRO_END_kLinNumberOfObjects;

typedef int VECTORCAST_MARKER__MACRO_START_kLinNumberOfRxObjects;
7
typedef int VECTORCAST_MARKER__MACRO_END_kLinNumberOfRxObjects;

typedef int VECTORCAST_MARKER__MACRO_START_kLinNumberOfTxObjects;
7
typedef int VECTORCAST_MARKER__MACRO_END_kLinNumberOfTxObjects;

typedef int VECTORCAST_MARKER__MACRO_START_kLinProtocolMainVersion;
2
typedef int VECTORCAST_MARKER__MACRO_END_kLinProtocolMainVersion;

typedef int VECTORCAST_MARKER__MACRO_START_kLinProtocolSubVersion;
0
typedef int VECTORCAST_MARKER__MACRO_END_kLinProtocolSubVersion;

typedef int VECTORCAST_MARKER__MACRO_START_kLinTBusIdle;
130
typedef int VECTORCAST_MARKER__MACRO_END_kLinTBusIdle;

typedef int VECTORCAST_MARKER__MACRO_START_kLinTFrame0;
4
typedef int VECTORCAST_MARKER__MACRO_END_kLinTFrame0;

typedef int VECTORCAST_MARKER__MACRO_START_kLinTFrame1;
5
typedef int VECTORCAST_MARKER__MACRO_END_kLinTFrame1;

typedef int VECTORCAST_MARKER__MACRO_START_kLinTFrame2;
5
typedef int VECTORCAST_MARKER__MACRO_END_kLinTFrame2;

typedef int VECTORCAST_MARKER__MACRO_START_kLinTFrame3;
6
typedef int VECTORCAST_MARKER__MACRO_END_kLinTFrame3;

typedef int VECTORCAST_MARKER__MACRO_START_kLinTFrame4;
7
typedef int VECTORCAST_MARKER__MACRO_END_kLinTFrame4;

typedef int VECTORCAST_MARKER__MACRO_START_kLinTFrame5;
7
typedef int VECTORCAST_MARKER__MACRO_END_kLinTFrame5;

typedef int VECTORCAST_MARKER__MACRO_START_kLinTFrame6;
8
typedef int VECTORCAST_MARKER__MACRO_END_kLinTFrame6;

typedef int VECTORCAST_MARKER__MACRO_START_kLinTFrame7;
9
typedef int VECTORCAST_MARKER__MACRO_END_kLinTFrame7;

typedef int VECTORCAST_MARKER__MACRO_START_kLinTFrame8;
10
typedef int VECTORCAST_MARKER__MACRO_END_kLinTFrame8;

typedef int VECTORCAST_MARKER__MACRO_START_kLinTHeaderMax;
3
typedef int VECTORCAST_MARKER__MACRO_END_kLinTHeaderMax;

typedef int VECTORCAST_MARKER__MACRO_START_kLinTWakeup0;
17
typedef int VECTORCAST_MARKER__MACRO_END_kLinTWakeup0;

typedef int VECTORCAST_MARKER__MACRO_START_kLinTWakeup3;
159
typedef int VECTORCAST_MARKER__MACRO_END_kLinTWakeup3;

typedef int VECTORCAST_MARKER__MACRO_START_p_lx_rs_dawn;
(EEPROM_Struct_AD . EEPROMStructAD . RainNightBitThrs_g>>4)
typedef int VECTORCAST_MARKER__MACRO_END_p_lx_rs_dawn;

typedef int VECTORCAST_MARKER__MACRO_START_p_lx_rs_day;
(EEPROM_Struct_AD . EEPROMStructAD . RainNightBitThrs_g&0x0F)
typedef int VECTORCAST_MARKER__MACRO_END_p_lx_rs_day;

typedef int VECTORCAST_MARKER__MACRO_START_po_ADC_TEST_g;
0x81
typedef int VECTORCAST_MARKER__MACRO_END_po_ADC_TEST_g;

typedef int VECTORCAST_MARKER__MACRO_START_po_ASIC_AnalogOut_Ana_g;
P2_bit . no6
typedef int VECTORCAST_MARKER__MACRO_END_po_ASIC_AnalogOut_Ana_g;

typedef int VECTORCAST_MARKER__MACRO_START_po_ASIC_AnalogOut_g;
6
typedef int VECTORCAST_MARKER__MACRO_END_po_ASIC_AnalogOut_g;

typedef int VECTORCAST_MARKER__MACRO_START_po_ASIC_LOOP_Ana_g;
P2_bit . no4
typedef int VECTORCAST_MARKER__MACRO_END_po_ASIC_LOOP_Ana_g;

typedef int VECTORCAST_MARKER__MACRO_START_po_ASIC_LOOP_g;
4
typedef int VECTORCAST_MARKER__MACRO_END_po_ASIC_LOOP_g;

typedef int VECTORCAST_MARKER__MACRO_START_po_DExternalWDG_g;
PM3_bit . no0
typedef int VECTORCAST_MARKER__MACRO_END_po_DExternalWDG_g;

typedef int VECTORCAST_MARKER__MACRO_START_po_DSHT71_1_CLK_g;
PM1_bit . no5
typedef int VECTORCAST_MARKER__MACRO_END_po_DSHT71_1_CLK_g;

typedef int VECTORCAST_MARKER__MACRO_START_po_DSHT71_1_DATA_g;
PM1_bit . no4
typedef int VECTORCAST_MARKER__MACRO_END_po_DSHT71_1_DATA_g;

typedef int VECTORCAST_MARKER__MACRO_START_po_DVoltageRegulatorEnable_g;
PM3_bit . no1
typedef int VECTORCAST_MARKER__MACRO_END_po_DVoltageRegulatorEnable_g;

typedef int VECTORCAST_MARKER__MACRO_START_po_D_ASIC_AnalogOut_Ana_g;
PM2_bit . no6
typedef int VECTORCAST_MARKER__MACRO_END_po_D_ASIC_AnalogOut_Ana_g;

typedef int VECTORCAST_MARKER__MACRO_START_po_D_ASIC_LOOP_Ana_g;
PM2_bit . no4
typedef int VECTORCAST_MARKER__MACRO_END_po_D_ASIC_LOOP_Ana_g;

typedef int VECTORCAST_MARKER__MACRO_START_po_D_Div_ON_g;
PM0_bit . no0
typedef int VECTORCAST_MARKER__MACRO_END_po_D_Div_ON_g;

typedef int VECTORCAST_MARKER__MACRO_START_po_D_I2C_Debug_CLK_g;
PM6_bit . no0
typedef int VECTORCAST_MARKER__MACRO_END_po_D_I2C_Debug_CLK_g;

typedef int VECTORCAST_MARKER__MACRO_START_po_D_I2C_Debug_DATA_g;
PM6_bit . no1
typedef int VECTORCAST_MARKER__MACRO_END_po_D_I2C_Debug_DATA_g;

typedef int VECTORCAST_MARKER__MACRO_START_po_D_PS_SHT1_g;
PM0_bit . no1
typedef int VECTORCAST_MARKER__MACRO_END_po_D_PS_SHT1_g;

typedef int VECTORCAST_MARKER__MACRO_START_po_D_PS_SHT2_g;
PM1_bit . no3
typedef int VECTORCAST_MARKER__MACRO_END_po_D_PS_SHT2_g;

typedef int VECTORCAST_MARKER__MACRO_START_po_D_PowerSupplyAna_g;
PM2_bit . no2
typedef int VECTORCAST_MARKER__MACRO_END_po_D_PowerSupplyAna_g;

typedef int VECTORCAST_MARKER__MACRO_START_po_D_RXD0_g;
PM5_bit . no0
typedef int VECTORCAST_MARKER__MACRO_END_po_D_RXD0_g;

typedef int VECTORCAST_MARKER__MACRO_START_po_D_SPIClock_g;
PM1_bit . no0
typedef int VECTORCAST_MARKER__MACRO_END_po_D_SPIClock_g;

typedef int VECTORCAST_MARKER__MACRO_START_po_D_SPI_MasterIn_g;
PM1_bit . no1
typedef int VECTORCAST_MARKER__MACRO_END_po_D_SPI_MasterIn_g;

typedef int VECTORCAST_MARKER__MACRO_START_po_D_SPI_MasterOut_g;
PM1_bit . no2
typedef int VECTORCAST_MARKER__MACRO_END_po_D_SPI_MasterOut_g;

typedef int VECTORCAST_MARKER__MACRO_START_po_D_TOOL0_g;
PM4_bit . no0
typedef int VECTORCAST_MARKER__MACRO_END_po_D_TOOL0_g;

typedef int VECTORCAST_MARKER__MACRO_START_po_D_TXD0_g;
PM5_bit . no1
typedef int VECTORCAST_MARKER__MACRO_END_po_D_TXD0_g;

typedef int VECTORCAST_MARKER__MACRO_START_po_D_unused12_0_g;
PM12_bit . no0
typedef int VECTORCAST_MARKER__MACRO_END_po_D_unused12_0_g;

typedef int VECTORCAST_MARKER__MACRO_START_po_D_unused1_6_g;
PM1_bit . no6
typedef int VECTORCAST_MARKER__MACRO_END_po_D_unused1_6_g;

typedef int VECTORCAST_MARKER__MACRO_START_po_D_unused1_7_g;
PM1_bit . no7
typedef int VECTORCAST_MARKER__MACRO_END_po_D_unused1_7_g;

typedef int VECTORCAST_MARKER__MACRO_START_po_D_unused2_3_g;
PM2_bit . no3
typedef int VECTORCAST_MARKER__MACRO_END_po_D_unused2_3_g;

typedef int VECTORCAST_MARKER__MACRO_START_po_D_unused6_0_g;
PM6_bit . no0
typedef int VECTORCAST_MARKER__MACRO_END_po_D_unused6_0_g;

typedef int VECTORCAST_MARKER__MACRO_START_po_D_unused6_1_g;
PM6_bit . no1
typedef int VECTORCAST_MARKER__MACRO_END_po_D_unused6_1_g;

typedef int VECTORCAST_MARKER__MACRO_START_po_D_unused6_2_g;
PM6_bit . no2
typedef int VECTORCAST_MARKER__MACRO_END_po_D_unused6_2_g;

typedef int VECTORCAST_MARKER__MACRO_START_po_D_unused7_0_g;
PM7_bit . no0
typedef int VECTORCAST_MARKER__MACRO_END_po_D_unused7_0_g;

typedef int VECTORCAST_MARKER__MACRO_START_po_Direction_Slave_Select_g;
PM14_bit . no7
typedef int VECTORCAST_MARKER__MACRO_END_po_Direction_Slave_Select_g;

typedef int VECTORCAST_MARKER__MACRO_START_po_Div_ON_g;
P0_bit . no0
typedef int VECTORCAST_MARKER__MACRO_END_po_Div_ON_g;

typedef int VECTORCAST_MARKER__MACRO_START_po_ExternalWDG_g;
P3_bit . no0
typedef int VECTORCAST_MARKER__MACRO_END_po_ExternalWDG_g;

typedef int VECTORCAST_MARKER__MACRO_START_po_I2C_Debug_CLK_g;
P6_bit . no0
typedef int VECTORCAST_MARKER__MACRO_END_po_I2C_Debug_CLK_g;

typedef int VECTORCAST_MARKER__MACRO_START_po_I2C_Debug_DATA_g;
P6_bit . no1
typedef int VECTORCAST_MARKER__MACRO_END_po_I2C_Debug_DATA_g;

typedef int VECTORCAST_MARKER__MACRO_START_po_LINTx_g;
P5_bit . no1
typedef int VECTORCAST_MARKER__MACRO_END_po_LINTx_g;

typedef int VECTORCAST_MARKER__MACRO_START_po_NTC_INPUT_g;
0x80
typedef int VECTORCAST_MARKER__MACRO_END_po_NTC_INPUT_g;

typedef int VECTORCAST_MARKER__MACRO_START_po_PS_SHT1_g;
P0_bit . no1
typedef int VECTORCAST_MARKER__MACRO_END_po_PS_SHT1_g;

typedef int VECTORCAST_MARKER__MACRO_START_po_PS_SHT2_g;
P1_bit . no3
typedef int VECTORCAST_MARKER__MACRO_END_po_PS_SHT2_g;

typedef int VECTORCAST_MARKER__MACRO_START_po_PowerSupplyAna_g;
P2_bit . no2
typedef int VECTORCAST_MARKER__MACRO_END_po_PowerSupplyAna_g;

typedef int VECTORCAST_MARKER__MACRO_START_po_PowerSupply_g;
2
typedef int VECTORCAST_MARKER__MACRO_END_po_PowerSupply_g;

typedef int VECTORCAST_MARKER__MACRO_START_po_RXD0_g;
P5_bit . no0
typedef int VECTORCAST_MARKER__MACRO_END_po_RXD0_g;

typedef int VECTORCAST_MARKER__MACRO_START_po_SHT71_1_CLK_g;
P1_bit . no5
typedef int VECTORCAST_MARKER__MACRO_END_po_SHT71_1_CLK_g;

typedef int VECTORCAST_MARKER__MACRO_START_po_SHT71_1_DATA_g;
P1_bit . no4
typedef int VECTORCAST_MARKER__MACRO_END_po_SHT71_1_DATA_g;

typedef int VECTORCAST_MARKER__MACRO_START_po_SHT_Supply_g;
0x10
typedef int VECTORCAST_MARKER__MACRO_END_po_SHT_Supply_g;

typedef int VECTORCAST_MARKER__MACRO_START_po_SPIClock_g;
P1_bit . no0
typedef int VECTORCAST_MARKER__MACRO_END_po_SPIClock_g;

typedef int VECTORCAST_MARKER__MACRO_START_po_SPI_MasterIn_g;
P1_bit . no1
typedef int VECTORCAST_MARKER__MACRO_END_po_SPI_MasterIn_g;

typedef int VECTORCAST_MARKER__MACRO_START_po_SPI_MasterOut_g;
P1_bit . no2
typedef int VECTORCAST_MARKER__MACRO_END_po_SPI_MasterOut_g;

typedef int VECTORCAST_MARKER__MACRO_START_po_Slave_Select_g;
P14_bit . no7
typedef int VECTORCAST_MARKER__MACRO_END_po_Slave_Select_g;

typedef int VECTORCAST_MARKER__MACRO_START_po_TOOL0_g;
P4_bit . no0
typedef int VECTORCAST_MARKER__MACRO_END_po_TOOL0_g;

typedef int VECTORCAST_MARKER__MACRO_START_po_TXD0_g;
P5_bit . no1
typedef int VECTORCAST_MARKER__MACRO_END_po_TXD0_g;

typedef int VECTORCAST_MARKER__MACRO_START_po_VoltageRegulatorEnable_g;
P3_bit . no1
typedef int VECTORCAST_MARKER__MACRO_END_po_VoltageRegulatorEnable_g;

typedef int VECTORCAST_MARKER__MACRO_START_po_unused12_0_g;
P12_bit . no0
typedef int VECTORCAST_MARKER__MACRO_END_po_unused12_0_g;

typedef int VECTORCAST_MARKER__MACRO_START_po_unused1_6_g;
P1_bit . no6
typedef int VECTORCAST_MARKER__MACRO_END_po_unused1_6_g;

typedef int VECTORCAST_MARKER__MACRO_START_po_unused1_7_g;
P1_bit . no7
typedef int VECTORCAST_MARKER__MACRO_END_po_unused1_7_g;

typedef int VECTORCAST_MARKER__MACRO_START_po_unused2_3_g;
P2_bit . no3
typedef int VECTORCAST_MARKER__MACRO_END_po_unused2_3_g;

typedef int VECTORCAST_MARKER__MACRO_START_po_unused6_0_g;
P6_bit . no0
typedef int VECTORCAST_MARKER__MACRO_END_po_unused6_0_g;

typedef int VECTORCAST_MARKER__MACRO_START_po_unused6_1_g;
P6_bit . no1
typedef int VECTORCAST_MARKER__MACRO_END_po_unused6_1_g;

typedef int VECTORCAST_MARKER__MACRO_START_po_unused6_2_g;
P6_bit . no2
typedef int VECTORCAST_MARKER__MACRO_END_po_unused6_2_g;

typedef int VECTORCAST_MARKER__MACRO_START_po_unused7_0_g;
P7_bit . no0
typedef int VECTORCAST_MARKER__MACRO_END_po_unused7_0_g;

typedef int VECTORCAST_MARKER__MACRO_START_rab_RS_Sensitivity_g;
EEPROM_Struct_AD . EEPROMStructAD . RS_Sensitivity
typedef int VECTORCAST_MARKER__MACRO_END_rab_RS_Sensitivity_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_2_5SecondsDelay_g;
((EEPROM_Struct_AD . EEPROMStructAD . StandbyTimout & 0xF8)>>3)
typedef int VECTORCAST_MARKER__MACRO_END_rb_2_5SecondsDelay_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_550nm_Transmission_g;
(((EEPROM_Struct_PD . EEPROMStructPD . EEKodierbyte2_g & 0x0F)*5)+15)
typedef int VECTORCAST_MARKER__MACRO_END_rb_550nm_Transmission_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_880nm_Transmission_g;
((((EEPROM_Struct_PD . EEPROMStructPD . EEKodierbyte2_g & 0xF0)>>4)*5)+15)
typedef int VECTORCAST_MARKER__MACRO_END_rb_880nm_Transmission_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_ACTR_Reg_g;
EEPROM_Struct_AD . EEPROMStructAD . ACTR_Reg_g
typedef int VECTORCAST_MARKER__MACRO_END_rb_ACTR_Reg_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_ALS1_4_Setting_g;
EEPROM_Struct_PD . EEPROMStructPD . ALS1_4_Setting_g
typedef int VECTORCAST_MARKER__MACRO_END_rb_ALS1_4_Setting_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_ALS5_6_INREC_Setting_g;
EEPROM_Struct_PD . EEPROMStructPD . ALS5_6_INREC_Setting_g
typedef int VECTORCAST_MARKER__MACRO_END_rb_ALS5_6_INREC_Setting_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_ALSx_Filter_g;
(EEPROM_Struct_AD . EEPROMStructAD . ALSx_Filter_g )
typedef int VECTORCAST_MARKER__MACRO_END_rb_ALSx_Filter_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_ASICIncidentCounter_g;
(EEPROM_Struct_RD . EEPROMStructRD . IncidentCounter4_g&0x0F )
typedef int VECTORCAST_MARKER__MACRO_END_rb_ASICIncidentCounter_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_ASIC_AFSTHR_REG_g;
(EEPROM_Struct_AD . EEPROMStructAD . ASIC_AFSTHR_REG_g )
typedef int VECTORCAST_MARKER__MACRO_END_rb_ASIC_AFSTHR_REG_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_ASIC_DIAGV_g;
EEPROM_Struct_PD . EEPROMStructPD . ASIC_DIAGV_g
typedef int VECTORCAST_MARKER__MACRO_END_rb_ASIC_DIAGV_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_ASIC_FREQ_invalid_HIGH_g;
uF_ASIC_Ctrl_Error_Flags_g . Bit . B7
typedef int VECTORCAST_MARKER__MACRO_END_rb_ASIC_FREQ_invalid_HIGH_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_ASIC_FREQ_invalid_LOW_g;
uF_ASIC_Ctrl_Error_Flags_g . Bit . B6
typedef int VECTORCAST_MARKER__MACRO_END_rb_ASIC_FREQ_invalid_LOW_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_ASIC_Frame_01_g;
EEPROM_Struct_PD . EEPROMStructPD . ASIC_Frame_01_g
typedef int VECTORCAST_MARKER__MACRO_END_rb_ASIC_Frame_01_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_ASIC_Frame_02_g;
EEPROM_Struct_PD . EEPROMStructPD . ASIC_Frame_02_g
typedef int VECTORCAST_MARKER__MACRO_END_rb_ASIC_Frame_02_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_ASIC_Frame_03_g;
EEPROM_Struct_PD . EEPROMStructPD . ASIC_Frame_03_g
typedef int VECTORCAST_MARKER__MACRO_END_rb_ASIC_Frame_03_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_ASIC_Frame_04_g;
EEPROM_Struct_PD . EEPROMStructPD . ASIC_Frame_04_g
typedef int VECTORCAST_MARKER__MACRO_END_rb_ASIC_Frame_04_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_ASIC_INTCNT_ACTR_g;
(byte)(ras_ASIC_CtrReg_g[0x3]. val&0x0F)
typedef int VECTORCAST_MARKER__MACRO_END_rb_ASIC_INTCNT_ACTR_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_ASIC_LCTR_g;
EEPROM_Struct_PD . EEPROMStructPD . ASIC_LCTR_g
typedef int VECTORCAST_MARKER__MACRO_END_rb_ASIC_LCTR_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_ASIC_RCTR_REG_g;
EEPROM_Struct_PD . EEPROMStructPD . ASIC_RCTR_REG_g
typedef int VECTORCAST_MARKER__MACRO_END_rb_ASIC_RCTR_REG_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_ASIC_RFCTR_REG_g;
EEPROM_Struct_PD . EEPROMStructPD . ASIC_RFCTR_REG_g
typedef int VECTORCAST_MARKER__MACRO_END_rb_ASIC_RFCTR_REG_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_ASIC_Sched_Config_g;
EEPROM_Struct_PD . EEPROMStructPD . ASIC_Sched_Config_g
typedef int VECTORCAST_MARKER__MACRO_END_rb_ASIC_Sched_Config_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_ASIC_TRIM_Reg_g;
ras_ASIC_CtrReg_g[0x12]. val
typedef int VECTORCAST_MARKER__MACRO_END_rb_ASIC_TRIM_Reg_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_AfterTunnelDelayOffs_g;
(((((unsigned int)EEPROM_Struct_AD . EEPROMStructAD . AfterTunnelDelayOffs*25))>120)? ((((unsigned int)EEPROM_Struct_AD . EEPROMStructAD . AfterTunnelDelayOffs*25)-120)>>1):0)
typedef int VECTORCAST_MARKER__MACRO_END_rb_AfterTunnelDelayOffs_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_AfterTunnelThrsIsNightThrs_g;
(EEPROM_Struct_AD . EEPROMStructAD . AmbLightTunnelThresholdRng & 0x80)
typedef int VECTORCAST_MARKER__MACRO_END_rb_AfterTunnelThrsIsNightThrs_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_AmbLightDiv8MeanSlow_g;
(byte)(rw_AmbLightMul32MeanSlow_g >> 8)
typedef int VECTORCAST_MARKER__MACRO_END_rb_AmbLightDiv8MeanSlow_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_AmbLightTunnelThresholdMin_g;
((EEPROM_Struct_AD . EEPROMStructAD . AmbLightTunnelThresholdRng & 0xF) *2 )
typedef int VECTORCAST_MARKER__MACRO_END_rb_AmbLightTunnelThresholdMin_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_Amb_Base_Day_Threshold_g;
EEPROM_Struct_AD . EEPROMStructAD . Amb_Base_Day_Threshold
typedef int VECTORCAST_MARKER__MACRO_END_rb_Amb_Base_Day_Threshold_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_Amb_Base_Night_Threshold_g;
EEPROM_Struct_AD . EEPROMStructAD . Amb_Base_Night_Threshold
typedef int VECTORCAST_MARKER__MACRO_END_rb_Amb_Base_Night_Threshold_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_Amb_TunnelThresholdScaling_g;
((EEPROM_Struct_AD . EEPROMStructAD . Amb_TunnelThresholdScaling_g&0x0F)+4)
typedef int VECTORCAST_MARKER__MACRO_END_rb_Amb_TunnelThresholdScaling_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_B_Factor_Iref_Hi_Gain_Hi_g;
EEPROM_Struct_PD . EEPROMStructPD . B_Factor_Iref_Hi_Gain_Hi_g
typedef int VECTORCAST_MARKER__MACRO_END_rb_B_Factor_Iref_Hi_Gain_Hi_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_B_Factor_Iref_Hi_Gain_Lo_g;
EEPROM_Struct_PD . EEPROMStructPD . B_Factor_Iref_Hi_Gain_Lo_g
typedef int VECTORCAST_MARKER__MACRO_END_rb_B_Factor_Iref_Hi_Gain_Lo_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_B_Factor_Iref_Lo_Gain_Hi_g;
EEPROM_Struct_PD . EEPROMStructPD . B_Factor_Iref_Lo_Gain_Hi_g
typedef int VECTORCAST_MARKER__MACRO_END_rb_B_Factor_Iref_Lo_Gain_Hi_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_B_Factor_Iref_Lo_Gain_Lo_g;
EEPROM_Struct_PD . EEPROMStructPD . B_Factor_Iref_Lo_Gain_Lo_g
typedef int VECTORCAST_MARKER__MACRO_END_rb_B_Factor_Iref_Lo_Gain_Lo_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_CPUIncidentCounter_g;
(EEPROM_Struct_RD . EEPROMStructRD . IncidentCounter4_g>>4)
typedef int VECTORCAST_MARKER__MACRO_END_rb_CPUIncidentCounter_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_CRC_Checksum_calibration_g;
EEPROM_Struct_PD . EEPROMStructPD . CRC_Checksum_calibration_g
typedef int VECTORCAST_MARKER__MACRO_END_rb_CRC_Checksum_calibration_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_CW_AnsamlungAdditOffsett_g;
EEPROM_Struct_AD . EEPROMStructAD . PrametersStruct[((EEPROM_Struct_PD . EEPROMStructPD . EEKodierbyte1_g & 12)>>2)]. CW_AnsamlungAdditOffset
typedef int VECTORCAST_MARKER__MACRO_END_rb_CW_AnsamlungAdditOffsett_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_CntMemoryIncidentCounter_g;
(EEPROM_Struct_RD . EEPROMStructRD . IncidentCounter2_g>>4)
typedef int VECTORCAST_MARKER__MACRO_END_rb_CntMemoryIncidentCounter_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_CntProSeqIncidentCounter_g;
(EEPROM_Struct_RD . EEPROMStructRD . IncidentCounter2_g&0x0F )
typedef int VECTORCAST_MARKER__MACRO_END_rb_CntProSeqIncidentCounter_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_Combined_FW_AL_THRs_g;
(EEPROM_Struct_AD . EEPROMStructAD . Combined_FW_AL_THRs_g)
typedef int VECTORCAST_MARKER__MACRO_END_rb_Combined_FW_AL_THRs_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_Customer_FW_SWA_Scaling_g;
EEPROM_Struct_AD . EEPROMStructAD . Customer_FW_SWA_Scaling
typedef int VECTORCAST_MARKER__MACRO_END_rb_Customer_FW_SWA_Scaling_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_Customer_IR_SWA_Scaling_g;
EEPROM_Struct_AD . EEPROMStructAD . Customer_IR_SWA_Scaling
typedef int VECTORCAST_MARKER__MACRO_END_rb_Customer_IR_SWA_Scaling_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_DYN_COMP_CCD_MINUS_10to25_g;
((EEPROM_Struct_AD . EEPROMStructAD . DYN_COMP_CCD_MINUS_1_g&0x0F))
typedef int VECTORCAST_MARKER__MACRO_END_rb_DYN_COMP_CCD_MINUS_10to25_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_DYN_COMP_CCD_MINUS_1_g;
(EEPROM_Struct_AD . EEPROMStructAD . DYN_COMP_CCD_MINUS_1_g)
typedef int VECTORCAST_MARKER__MACRO_END_rb_DYN_COMP_CCD_MINUS_1_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_DYN_COMP_CCD_MINUS_25to40_g;
((EEPROM_Struct_AD . EEPROMStructAD . DYN_COMP_CCD_MINUS_2_g&0xF0)>>4)
typedef int VECTORCAST_MARKER__MACRO_END_rb_DYN_COMP_CCD_MINUS_25to40_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_DYN_COMP_CCD_MINUS_2_g;
(EEPROM_Struct_AD . EEPROMStructAD . DYN_COMP_CCD_MINUS_2_g)
typedef int VECTORCAST_MARKER__MACRO_END_rb_DYN_COMP_CCD_MINUS_2_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_DYN_COMP_CCD_MINUS_above40_g;
((EEPROM_Struct_AD . EEPROMStructAD . DYN_COMP_CCD_MINUS_2_g&0x0F))
typedef int VECTORCAST_MARKER__MACRO_END_rb_DYN_COMP_CCD_MINUS_above40_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_DYN_COMP_CCD_MINUS_belowneg5_g;
((EEPROM_Struct_AD . EEPROMStructAD . Amb_TunnelThresholdScaling_g&0xF0)>>4)
typedef int VECTORCAST_MARKER__MACRO_END_rb_DYN_COMP_CCD_MINUS_belowneg5_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_DYN_COMP_CCD_MINUS_neg5to10_g;
((EEPROM_Struct_AD . EEPROMStructAD . DYN_COMP_CCD_MINUS_1_g&0xF0)>>4)
typedef int VECTORCAST_MARKER__MACRO_END_rb_DYN_COMP_CCD_MINUS_neg5to10_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_Day_Delay_g;
EEPROM_Struct_AD . EEPROMStructAD . Day_Delay
typedef int VECTORCAST_MARKER__MACRO_END_rb_Day_Delay_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_Dec_Stx_Speicher_g;
EEPROM_Struct_AD . EEPROMStructAD . PrametersStruct[((EEPROM_Struct_PD . EEPROMStructPD . EEKodierbyte1_g & 12)>>2)]. Dec_Stx_Speicher
typedef int VECTORCAST_MARKER__MACRO_END_rb_Dec_Stx_Speicher_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_DewPointIncidentCounter_g;
(EEPROM_Struct_RD . EEPROMStructRD . IncidentCounter6_g&0x0F )
typedef int VECTORCAST_MARKER__MACRO_END_rb_DewPointIncidentCounter_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_Diag_Request_Factor_g;
(EEPROM_Struct_AD . EEPROMStructAD . Diag_Request_Factor_g )
typedef int VECTORCAST_MARKER__MACRO_END_rb_Diag_Request_Factor_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_E2_Sensor_Error1_g;
EEPROM_Struct_RD . EEPROMStructRD . E2_Sensor_Error1_g
typedef int VECTORCAST_MARKER__MACRO_END_rb_E2_Sensor_Error1_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_E2_Sensor_Error2_g;
EEPROM_Struct_RD . EEPROMStructRD . E2_Sensor_Error2_g
typedef int VECTORCAST_MARKER__MACRO_END_rb_E2_Sensor_Error2_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_E2_Sensor_Error3_g;
EEPROM_Struct_RD . EEPROMStructRD . E2_Sensor_Error3_g
typedef int VECTORCAST_MARKER__MACRO_END_rb_E2_Sensor_Error3_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_E2_Sensor_Error4_g;
EEPROM_Struct_RD . EEPROMStructRD . E2_Sensor_Error4_g
typedef int VECTORCAST_MARKER__MACRO_END_rb_E2_Sensor_Error4_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_E2_Sensor_Error5_g;
EEPROM_Struct_RD . EEPROMStructRD . E2_Sensor_Error5_g
typedef int VECTORCAST_MARKER__MACRO_END_rb_E2_Sensor_Error5_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_E2_Sensor_Error6_g;
EEPROM_Struct_RD . EEPROMStructRD . E2_Sensor_Error6_g
typedef int VECTORCAST_MARKER__MACRO_END_rb_E2_Sensor_Error6_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_EEPROM_Erase_Counter_g;
EEPROM_Struct_PD . EEPROMStructPD . EEPROM_Erase_Counter
typedef int VECTORCAST_MARKER__MACRO_END_rb_EEPROM_Erase_Counter_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_Empf_Faktor_ST2_Offs_g;
(EEPROM_Struct_AD . EEPROMStructAD . PrametersStruct[((EEPROM_Struct_PD . EEPROMStructPD . EEKodierbyte1_g & 12)>>2)]. Empf_Faktor_ST2_Offs &0x3F)
typedef int VECTORCAST_MARKER__MACRO_END_rb_Empf_Faktor_ST2_Offs_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_Ep_St2_Epr_In_St2_g;
EEPROM_Struct_AD . EEPROMStructAD . PrametersStruct[((EEPROM_Struct_PD . EEPROMStructPD . EEKodierbyte1_g & 12)>>2)]. Ep_St2_Epr_In_St2
typedef int VECTORCAST_MARKER__MACRO_END_rb_Ep_St2_Epr_In_St2_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_Error_Active_1_g;
EEPROM_Struct_PD . EEPROMStructPD . Error_Active_1_g
typedef int VECTORCAST_MARKER__MACRO_END_rb_Error_Active_1_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_Error_Active_2_g;
EEPROM_Struct_PD . EEPROMStructPD . Error_Active_2_g
typedef int VECTORCAST_MARKER__MACRO_END_rb_Error_Active_2_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_Error_Active_3_g;
EEPROM_Struct_PD . EEPROMStructPD . Error_Active_3_g
typedef int VECTORCAST_MARKER__MACRO_END_rb_Error_Active_3_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_FOSC_LEDUL_g;
EEPROM_Struct_AD . EEPROMStructAD . FOSC_LEDUL_g
typedef int VECTORCAST_MARKER__MACRO_END_rb_FOSC_LEDUL_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_FW_Base_Day_Threshold_g;
EEPROM_Struct_AD . EEPROMStructAD . FW_Base_Day_Threshold
typedef int VECTORCAST_MARKER__MACRO_END_rb_FW_Base_Day_Threshold_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_FW_Base_Night_Threshold_g;
EEPROM_Struct_AD . EEPROMStructAD . FW_Base_Night_Threshold
typedef int VECTORCAST_MARKER__MACRO_END_rb_FW_Base_Night_Threshold_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_FW_TunnelThresholdScaling_g;
((EEPROM_Struct_AD . EEPROMStructAD . TunnelThresholdScaling_g&0x0F)+4)
typedef int VECTORCAST_MARKER__MACRO_END_rb_FW_TunnelThresholdScaling_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_Frontwaschen_Autobahndelay_g;
(EEPROM_Struct_AD . EEPROMStructAD . Frontwaschen_Autobahndelay_g)
typedef int VECTORCAST_MARKER__MACRO_END_rb_Frontwaschen_Autobahndelay_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_FwLightDiv4MeanFast_g;
(byte)(rw_FwLightMul64MeanFast_g >> 8)
typedef int VECTORCAST_MARKER__MACRO_END_rb_FwLightDiv4MeanFast_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_FwLightDiv4MeanSlow_g;
(byte)(rw_FwLightMul64MeanSlow_g >> 8)
typedef int VECTORCAST_MARKER__MACRO_END_rb_FwLightDiv4MeanSlow_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_FwLightMeanSlow_g;
(((byte)(rw_FwLightMul64MeanSlow_g >> 8) >= 64)? (byte)(0xff):((byte)(rw_FwLightMul64MeanSlow_g >> 8)<<2))
typedef int VECTORCAST_MARKER__MACRO_END_rb_FwLightMeanSlow_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_FwLightTunnelThresholdBase_g;
((EEPROM_Struct_AD . EEPROMStructAD . FwLightTunnelThresholdRng & 0xF) *3 )
typedef int VECTORCAST_MARKER__MACRO_END_rb_FwLightTunnelThresholdBase_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_FwLightTunnelThresholdMax_g;
(((EEPROM_Struct_AD . EEPROMStructAD . FwLightTunnelThresholdRng & 0xF) *3 ) +((EEPROM_Struct_AD . EEPROMStructAD . FwLightTunnelThresholdRng >> 4) *5 ))
typedef int VECTORCAST_MARKER__MACRO_END_rb_FwLightTunnelThresholdMax_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_GainOffsetE2_g;
EEPROM_Struct_RD . EEPROMStructRD . GainOffsetE2_g
typedef int VECTORCAST_MARKER__MACRO_END_rb_GainOffsetE2_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_Gegenlaufwischeranlage_g;
((EEPROM_Struct_PD . EEPROMStructPD . EEKodierbyte1_g & 0x10)>0)
typedef int VECTORCAST_MARKER__MACRO_END_rb_Gegenlaufwischeranlage_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_HALIOS_Clock_Control_Reg_g;
EEPROM_Struct_AD . EEPROMStructAD . HALIOS_Clock_Control_Reg_g
typedef int VECTORCAST_MARKER__MACRO_END_rb_HALIOS_Clock_Control_Reg_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_HT_COMIncidentCounter_g;
(EEPROM_Struct_RD . EEPROMStructRD . IncidentCounter6_g>>4)
typedef int VECTORCAST_MARKER__MACRO_END_rb_HT_COMIncidentCounter_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_HUD_Factor_g;
EEPROM_Struct_PD . EEPROMStructPD . HUD_Factor_g
typedef int VECTORCAST_MARKER__MACRO_END_rb_HUD_Factor_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_HUD_MAX_Resolution_g;
EEPROM_Struct_PD . EEPROMStructPD . HUD_MAX_Resolution
typedef int VECTORCAST_MARKER__MACRO_END_rb_HUD_MAX_Resolution_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_HumIncidentCounter_g;
(EEPROM_Struct_RD . EEPROMStructRD . IncidentCounter5_g>>4)
typedef int VECTORCAST_MARKER__MACRO_END_rb_HumIncidentCounter_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_I2C_Debug_Config_g;
(EEPROM_Struct_AD . EEPROMStructAD . I2C_Debug_Config_g )
typedef int VECTORCAST_MARKER__MACRO_END_rb_I2C_Debug_Config_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_ICO1H_g;
EEPROM_Struct_AD . EEPROMStructAD . ICO1H_g
typedef int VECTORCAST_MARKER__MACRO_END_rb_ICO1H_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_ICO1L_g;
EEPROM_Struct_AD . EEPROMStructAD . ICO1L_g
typedef int VECTORCAST_MARKER__MACRO_END_rb_ICO1L_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_ICO2H_g;
EEPROM_Struct_AD . EEPROMStructAD . ICO2H_g
typedef int VECTORCAST_MARKER__MACRO_END_rb_ICO2H_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_ICO2L_g;
EEPROM_Struct_AD . EEPROMStructAD . ICO2L_g
typedef int VECTORCAST_MARKER__MACRO_END_rb_ICO2L_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_IDBCM1_LIN1_01_g;
EEPROM_Struct_PD . EEPROMStructPD . IDBCM1_LIN1_01
typedef int VECTORCAST_MARKER__MACRO_END_rb_IDBCM1_LIN1_01_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_IDBCM1_LIN1_02_g;
EEPROM_Struct_PD . EEPROMStructPD . IDBCM1_LIN1_02
typedef int VECTORCAST_MARKER__MACRO_END_rb_IDBCM1_LIN1_02_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_IDBCM1_LIN1_03_g;
EEPROM_Struct_PD . EEPROMStructPD . IDBCM1_LIN1_03
typedef int VECTORCAST_MARKER__MACRO_END_rb_IDBCM1_LIN1_03_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_IDBCM1_LIN1_04_g;
EEPROM_Struct_PD . EEPROMStructPD . IDBCM1_LIN1_04
typedef int VECTORCAST_MARKER__MACRO_END_rb_IDBCM1_LIN1_04_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_IDBCM1_LIN1_05_g;
EEPROM_Struct_PD . EEPROMStructPD . IDBCM1_LIN1_05
typedef int VECTORCAST_MARKER__MACRO_END_rb_IDBCM1_LIN1_05_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_IDERRDATA_01_g;
EEPROM_Struct_PD . EEPROMStructPD . IDERRDATA_01
typedef int VECTORCAST_MARKER__MACRO_END_rb_IDERRDATA_01_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_IDFSs_01_g;
EEPROM_Struct_PD . EEPROMStructPD . IDFSs_01
typedef int VECTORCAST_MARKER__MACRO_END_rb_IDFSs_01_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_IDRLSs_01_g;
EEPROM_Struct_PD . EEPROMStructPD . IDRLSs_01
typedef int VECTORCAST_MARKER__MACRO_END_rb_IDRLSs_01_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_IDRLSs_02_g;
EEPROM_Struct_PD . EEPROMStructPD . IDRLSs_02
typedef int VECTORCAST_MARKER__MACRO_END_rb_IDRLSs_02_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_IDRLSs_03_g;
EEPROM_Struct_PD . EEPROMStructPD . IDRLSs_03
typedef int VECTORCAST_MARKER__MACRO_END_rb_IDRLSs_03_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_IDRLSs_04_g;
EEPROM_Struct_PD . EEPROMStructPD . IDRLSs_04
typedef int VECTORCAST_MARKER__MACRO_END_rb_IDRLSs_04_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_IDRLSs_05_g;
EEPROM_Struct_PD . EEPROMStructPD . IDRLSs_05
typedef int VECTORCAST_MARKER__MACRO_END_rb_IDRLSs_05_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_IDRLSs_06_g;
EEPROM_Struct_PD . EEPROMStructPD . IDRLSs_06
typedef int VECTORCAST_MARKER__MACRO_END_rb_IDRLSs_06_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_IDSOSES_01_g;
EEPROM_Struct_PD . EEPROMStructPD . IDSOSES_01
typedef int VECTORCAST_MARKER__MACRO_END_rb_IDSOSES_01_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_IDSPARE_01_g;
EEPROM_Struct_PD . EEPROMStructPD . IDSPARE_01
typedef int VECTORCAST_MARKER__MACRO_END_rb_IDSPARE_01_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_IDWWSs_01_g;
EEPROM_Struct_PD . EEPROMStructPD . IDWWSs_01
typedef int VECTORCAST_MARKER__MACRO_END_rb_IDWWSs_01_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_INTCO_g;
EEPROM_Struct_AD . EEPROMStructAD . INTCO_g
typedef int VECTORCAST_MARKER__MACRO_END_rb_INTCO_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_IR_Base_Day_Threshold_g;
EEPROM_Struct_AD . EEPROMStructAD . IR_Base_Day_Threshold
typedef int VECTORCAST_MARKER__MACRO_END_rb_IR_Base_Day_Threshold_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_IR_Base_Night_Threshold_g;
EEPROM_Struct_AD . EEPROMStructAD . IR_Base_Night_Threshold
typedef int VECTORCAST_MARKER__MACRO_END_rb_IR_Base_Night_Threshold_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_IR_TunnelThresholdScaling_g;
(((EEPROM_Struct_AD . EEPROMStructAD . TunnelThresholdScaling_g&0xF0)>>4)+4)
typedef int VECTORCAST_MARKER__MACRO_END_rb_IR_TunnelThresholdScaling_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_IncidentCounter1_g;
EEPROM_Struct_RD . EEPROMStructRD . IncidentCounter1_g
typedef int VECTORCAST_MARKER__MACRO_END_rb_IncidentCounter1_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_IncidentCounter2_g;
EEPROM_Struct_RD . EEPROMStructRD . IncidentCounter2_g
typedef int VECTORCAST_MARKER__MACRO_END_rb_IncidentCounter2_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_IncidentCounter3_g;
EEPROM_Struct_RD . EEPROMStructRD . IncidentCounter3_g
typedef int VECTORCAST_MARKER__MACRO_END_rb_IncidentCounter3_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_IncidentCounter4_g;
EEPROM_Struct_RD . EEPROMStructRD . IncidentCounter4_g
typedef int VECTORCAST_MARKER__MACRO_END_rb_IncidentCounter4_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_IncidentCounter5_g;
EEPROM_Struct_RD . EEPROMStructRD . IncidentCounter5_g
typedef int VECTORCAST_MARKER__MACRO_END_rb_IncidentCounter5_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_IncidentCounter6_g;
EEPROM_Struct_RD . EEPROMStructRD . IncidentCounter6_g
typedef int VECTORCAST_MARKER__MACRO_END_rb_IncidentCounter6_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_IncidentCounter7_g;
EEPROM_Struct_RD . EEPROMStructRD . IncidentCounter7_g
typedef int VECTORCAST_MARKER__MACRO_END_rb_IncidentCounter7_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_IntSpInc_Scal_g;
(EEPROM_Struct_AD . EEPROMStructAD . PrametersStruct[((EEPROM_Struct_PD . EEPROMStructPD . EEKodierbyte1_g & 12)>>2)]. SchlierenFlag1&0x03)
typedef int VECTORCAST_MARKER__MACRO_END_rb_IntSpInc_Scal_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_Intensity_OverWipeCoef_g;
EEPROM_Struct_PD . EEPROMStructPD . RS_Intensity_OverWipeCoef
typedef int VECTORCAST_MARKER__MACRO_END_rb_Intensity_OverWipeCoef_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_Intensity_Thr_IdleTime_g;
EEPROM_Struct_PD . EEPROMStructPD . RS_Intensity_Thr_IdleTime
typedef int VECTORCAST_MARKER__MACRO_END_rb_Intensity_Thr_IdleTime_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_IntervalIsWasActive_g;
EEPROM_Struct_RD . EEPROMStructRD . IntervalIsWasActive_g
typedef int VECTORCAST_MARKER__MACRO_END_rb_IntervalIsWasActive_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_IntervalTimereductLimitFact_g;
((EEPROM_Struct_AD . EEPROMStructAD . StandbyModeScanTime_g>>5)+1)
typedef int VECTORCAST_MARKER__MACRO_END_rb_IntervalTimereductLimitFact_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_IrLightTunnelThreshodHigh_g;
(((EEPROM_Struct_AD . EEPROMStructAD . IrLightTunnelThreshodRng & 0xF) *2 ) + ((EEPROM_Struct_AD . EEPROMStructAD . IrLightTunnelThreshodRng >> 4) *2 ))
typedef int VECTORCAST_MARKER__MACRO_END_rb_IrLightTunnelThreshodHigh_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_IrLightTunnelThreshodLow_g;
((EEPROM_Struct_AD . EEPROMStructAD . IrLightTunnelThreshodRng & 0xF) *2 )
typedef int VECTORCAST_MARKER__MACRO_END_rb_IrLightTunnelThreshodLow_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_Kodierbyte0_g;
EEPROM_Struct_PD . EEPROMStructPD . EEKodierbyte0_g
typedef int VECTORCAST_MARKER__MACRO_END_rb_Kodierbyte0_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_Kodierbyte1_g;
EEPROM_Struct_PD . EEPROMStructPD . EEKodierbyte1_g
typedef int VECTORCAST_MARKER__MACRO_END_rb_Kodierbyte1_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_Kodierbyte2_g;
EEPROM_Struct_PD . EEPROMStructPD . EEKodierbyte2_g
typedef int VECTORCAST_MARKER__MACRO_END_rb_Kodierbyte2_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_LightLS_Error_Active1_g;
EEPROM_Struct_RD . EEPROMStructRD . LightLS_Error_Active1_g
typedef int VECTORCAST_MARKER__MACRO_END_rb_LightLS_Error_Active1_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_LightSensorCoding_g;
((EEPROM_Struct_PD . EEPROMStructPD . EEKodierbyte0_g & 0x38)>>3)
typedef int VECTORCAST_MARKER__MACRO_END_rb_LightSensorCoding_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_LightSensorIncidentCounter_g;
(EEPROM_Struct_RD . EEPROMStructRD . IncidentCounter1_g>>4)
typedef int VECTORCAST_MARKER__MACRO_END_rb_LightSensorIncidentCounter_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_MaxOverwipeSensitivity_g;
(EEPROM_Struct_AD . EEPROMStructAD . MaxOverwipeSensitivity&0x1F)
typedef int VECTORCAST_MARKER__MACRO_END_rb_MaxOverwipeSensitivity_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_Max_Signallaenge_g;
EEPROM_Struct_AD . EEPROMStructAD . PrametersStruct[((EEPROM_Struct_PD . EEPROMStructPD . EEKodierbyte1_g & 12)>>2)]. Max_Signallaenge
typedef int VECTORCAST_MARKER__MACRO_END_rb_Max_Signallaenge_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_Mean_HighwayLightOnSpeed_g;
((((EEPROM_Struct_AD . EEPROMStructAD . p_v_autobahn_on_off_g)&0x0f)*10)+100)
typedef int VECTORCAST_MARKER__MACRO_END_rb_Mean_HighwayLightOnSpeed_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_NAD_g;
EEPROM_Struct_PD . EEPROMStructPD . NAD
typedef int VECTORCAST_MARKER__MACRO_END_rb_NAD_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_NOM_DELTA_INTV_g;
EEPROM_Struct_RD . EEPROMStructRD . NOM_DELTA_INTV_g
typedef int VECTORCAST_MARKER__MACRO_END_rb_NOM_DELTA_INTV_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_Nachwisch_2_g;
(EEPROM_Struct_AD . EEPROMStructAD . PrametersStruct[((EEPROM_Struct_PD . EEPROMStructPD . EEKodierbyte1_g & 12)>>2)]. Nachwisch_2 & 0x7F)
typedef int VECTORCAST_MARKER__MACRO_END_rb_Nachwisch_2_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_Nachwisch_3_g;
(EEPROM_Struct_AD . EEPROMStructAD . PrametersStruct[((EEPROM_Struct_PD . EEPROMStructPD . EEKodierbyte1_g & 12)>>2)]. Nachwisch_3&0x7F)
typedef int VECTORCAST_MARKER__MACRO_END_rb_Nachwisch_3_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_Nachwisch_4_g;
((EEPROM_Struct_AD . EEPROMStructAD . PrametersStruct[((EEPROM_Struct_PD . EEPROMStructPD . EEKodierbyte1_g & 12)>>2)]. Nachwisch_4_ST1_min)& 0x1F)
typedef int VECTORCAST_MARKER__MACRO_END_rb_Nachwisch_4_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_Night_Delay_g;
EEPROM_Struct_AD . EEPROMStructAD . Night_Delay
typedef int VECTORCAST_MARKER__MACRO_END_rb_Night_Delay_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_OvrInc_Scal_g;
(((EEPROM_Struct_AD . EEPROMStructAD . PrametersStruct[((EEPROM_Struct_PD . EEPROMStructPD . EEKodierbyte1_g & 12)>>2)]. SchlierenFlag1)>>2)& 0x03)
typedef int VECTORCAST_MARKER__MACRO_END_rb_OvrInc_Scal_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_PCO_PI_Regulator_g;
EEPROM_Struct_AD . EEPROMStructAD . PCO_PI_Regulator_g
typedef int VECTORCAST_MARKER__MACRO_END_rb_PCO_PI_Regulator_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_Parametersatz_Regensensorik_g;
((EEPROM_Struct_PD . EEPROMStructPD . EEKodierbyte1_g & 12)>>2)
typedef int VECTORCAST_MARKER__MACRO_END_rb_Parametersatz_Regensensorik_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_Proj_Specific_config_g;
(EEPROM_Struct_AD . EEPROMStructAD . Proj_Specific_config )
typedef int VECTORCAST_MARKER__MACRO_END_rb_Proj_Specific_config_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_REGV_OSAT_g;
(byte)((ras_ASIC_CtrReg_g[0x15]. val>>1)&0x01)
typedef int VECTORCAST_MARKER__MACRO_END_rb_REGV_OSAT_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_RLTPositionnearParkposition_E2_g;
((((EEPROM_Struct_PD . EEPROMStructPD . EEKodierbyte1_g & 0x01)>0) == 0)&& (((EEPROM_Struct_PD . EEPROMStructPD . EEKodierbyte1_g & 0x02)>0) == 1))
typedef int VECTORCAST_MARKER__MACRO_END_rb_RLTPositionnearParkposition_E2_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_RSControlFlags_g;
EEPROM_Struct_PD . EEPROMStructPD . RSControlFlags
typedef int VECTORCAST_MARKER__MACRO_END_rb_RSControlFlags_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_RSEmpfFactorScaling_g;
(EEPROM_Struct_AD . EEPROMStructAD . PrametersStruct[((EEPROM_Struct_PD . EEPROMStructPD . EEKodierbyte1_g & 12)>>2)]. RSEmpfFactorScaling&0x0f)
typedef int VECTORCAST_MARKER__MACRO_END_rb_RSEmpfFactorScaling_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_RS_Intensity_SigVoltageH_g;
EEPROM_Struct_PD . EEPROMStructPD . RS_Intensity_SigVoltageH
typedef int VECTORCAST_MARKER__MACRO_END_rb_RS_Intensity_SigVoltageH_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_RS_Intensity_SigVoltageL_g;
EEPROM_Struct_PD . EEPROMStructPD . RS_Intensity_SigVoltageL
typedef int VECTORCAST_MARKER__MACRO_END_rb_RS_Intensity_SigVoltageL_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_RS_LS_Error_Active1_g;
EEPROM_Struct_RD . EEPROMStructRD . RS_LS_Error_Active1_g
typedef int VECTORCAST_MARKER__MACRO_END_rb_RS_LS_Error_Active1_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_RS_LS_Error_Active2_g;
EEPROM_Struct_RD . EEPROMStructRD . RS_LS_Error_Active2_g
typedef int VECTORCAST_MARKER__MACRO_END_rb_RS_LS_Error_Active2_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_RS_SigVoltage_g;
ras_ASIC_CtrReg_g[0x14]. val
typedef int VECTORCAST_MARKER__MACRO_END_rb_RS_SigVoltage_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_RainNightBitThrs_g;
EEPROM_Struct_AD . EEPROMStructAD . RainNightBitThrs_g
typedef int VECTORCAST_MARKER__MACRO_END_rb_RainNightBitThrs_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_RainRS_Error_Active1_g;
EEPROM_Struct_RD . EEPROMStructRD . RainRS_Error_Active1_g
typedef int VECTORCAST_MARKER__MACRO_END_rb_RainRS_Error_Active1_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_RainSensorIncidentCounter_g;
(EEPROM_Struct_RD . EEPROMStructRD . IncidentCounter1_g&0x0F )
typedef int VECTORCAST_MARKER__MACRO_END_rb_RainSensorIncidentCounter_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_Regensensorposition_horizontal_g;
((EEPROM_Struct_PD . EEPROMStructPD . EEKodierbyte1_g & 0x01)>0)
typedef int VECTORCAST_MARKER__MACRO_END_rb_Regensensorposition_horizontal_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_Regensensorposition_vertikal_g;
((EEPROM_Struct_PD . EEPROMStructPD . EEKodierbyte1_g & 0x02)>0)
typedef int VECTORCAST_MARKER__MACRO_END_rb_Regensensorposition_vertikal_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_Regulation48Threshold_g;
(EEPROM_Struct_AD . EEPROMStructAD . Regulation48ThresholdAmb_g)
typedef int VECTORCAST_MARKER__MACRO_END_rb_Regulation48Threshold_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_Regulation48_FW_Threshold_g;
(EEPROM_Struct_AD . EEPROMStructAD . Regulation48ThresholdFw_g)
typedef int VECTORCAST_MARKER__MACRO_END_rb_Regulation48_FW_Threshold_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_Release_IntervalMarker_g;
EEPROM_Struct_RD . EEPROMStructRD . Release_IntervalMarker_g
typedef int VECTORCAST_MARKER__MACRO_END_rb_Release_IntervalMarker_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_Resf_g;
EEPROM_Struct_RD . EEPROMStructRD . Resf_g
typedef int VECTORCAST_MARKER__MACRO_END_rb_Resf_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_SC_debounce_g;
(2 * EEPROM_Struct_PD . EEPROMStructPD . SC_MAX)
typedef int VECTORCAST_MARKER__MACRO_END_rb_SC_debounce_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_SC_max_g;
EEPROM_Struct_PD . EEPROMStructPD . SC_MAX
typedef int VECTORCAST_MARKER__MACRO_END_rb_SC_max_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_SC_order1_g;
(EEPROM_Struct_PD . EEPROMStructPD . SC_ORDER12 & 0x0F)
typedef int VECTORCAST_MARKER__MACRO_END_rb_SC_order1_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_SC_order2_g;
((EEPROM_Struct_PD . EEPROMStructPD . SC_ORDER12 & 0xF0) >> 4)
typedef int VECTORCAST_MARKER__MACRO_END_rb_SC_order2_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_SC_order3_g;
EEPROM_Struct_PD . EEPROMStructPD . SC_ORDER3
typedef int VECTORCAST_MARKER__MACRO_END_rb_SC_order3_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_SHTErrorDebounceJitter_g;
(EEPROM_Struct_AD . EEPROMStructAD . SHTErrorDebounceJitter)
typedef int VECTORCAST_MARKER__MACRO_END_rb_SHTErrorDebounceJitter_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_SI_880nmWavelenght_factor_g;
0xFF
typedef int VECTORCAST_MARKER__MACRO_END_rb_SI_880nmWavelenght_factor_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_SI_Transmission_Korrektur_g;
((EEPROM_Struct_PD . EEPROMStructPD . EEKodierbyte1_g & 0xE0)>>5)
typedef int VECTORCAST_MARKER__MACRO_END_rb_SI_Transmission_Korrektur_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_ST1_Nachwisch_min_g;
(((EEPROM_Struct_AD . EEPROMStructAD . PrametersStruct[((EEPROM_Struct_PD . EEPROMStructPD . EEKodierbyte1_g & 12)>>2)]. Nachwisch_4_ST1_min)& 0x60)>>5)
typedef int VECTORCAST_MARKER__MACRO_END_rb_ST1_Nachwisch_min_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_STATH_flags_g;
(byte)(ras_ASIC_CtrReg_g[0x10]. val&0x1F)
typedef int VECTORCAST_MARKER__MACRO_END_rb_STATH_flags_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_STBY_DELTA_INTV_HB_g;
EEPROM_Struct_RD . EEPROMStructRD . STBY_DELTA_INTV_HB_g
typedef int VECTORCAST_MARKER__MACRO_END_rb_STBY_DELTA_INTV_HB_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_STBY_DELTA_INTV_LB_g;
EEPROM_Struct_RD . EEPROMStructRD . STBY_DELTA_INTV_LB_g
typedef int VECTORCAST_MARKER__MACRO_END_rb_STBY_DELTA_INTV_LB_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_STBY_REGV_HB_g;
EEPROM_Struct_RD . EEPROMStructRD . STBY_REGV_HB_g
typedef int VECTORCAST_MARKER__MACRO_END_rb_STBY_REGV_HB_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_STBY_REGV_Imbalance_g;
EEPROM_Struct_PD . EEPROMStructPD . STBY_REGV_Imbalance_g
typedef int VECTORCAST_MARKER__MACRO_END_rb_STBY_REGV_Imbalance_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_STBY_REGV_LB_g;
EEPROM_Struct_RD . EEPROMStructRD . STBY_REGV_LB_g
typedef int VECTORCAST_MARKER__MACRO_END_rb_STBY_REGV_LB_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_SW_TeilenummerindexE2_g;
EEPROM_Struct_AD . EEPROMStructAD . Teilenummerindex
typedef int VECTORCAST_MARKER__MACRO_END_rb_SW_TeilenummerindexE2_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_SchlierenFlag1_g;
EEPROM_Struct_AD . EEPROMStructAD . PrametersStruct[((EEPROM_Struct_PD . EEPROMStructPD . EEKodierbyte1_g & 12)>>2)]. SchlierenFlag1
typedef int VECTORCAST_MARKER__MACRO_END_rb_SchlierenFlag1_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_SchwelleInWipeLow_g;
((((EEPROM_Struct_PD . EEPROMStructPD . EEKodierbyte1_g & 0x01)>0) == 0)&& (((EEPROM_Struct_PD . EEPROMStructPD . EEKodierbyte1_g & 0x02)>0) == 1))
typedef int VECTORCAST_MARKER__MACRO_END_rb_SchwelleInWipeLow_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_Schwelle_Schwall_g;
EEPROM_Struct_AD . EEPROMStructAD . PrametersStruct[((EEPROM_Struct_PD . EEPROMStructPD . EEKodierbyte1_g & 12)>>2)]. Schwelle_Schwall
typedef int VECTORCAST_MARKER__MACRO_END_rb_Schwelle_Schwall_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_Si_Transmission_1_g;
(byte)((((unsigned int)((((EEPROM_Struct_PD . EEPROMStructPD . EEKodierbyte2_g & 0x0F)*5)+15) + (cab_SI_Transmission_Offsett[((EEPROM_Struct_PD . EEPROMStructPD . EEKodierbyte1_g & 0xE0)>>5)]-15)) )*9)/(15))
typedef int VECTORCAST_MARKER__MACRO_END_rb_Si_Transmission_1_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_Si_Transmission_g;
(((byte)((((unsigned int)((((EEPROM_Struct_PD . EEPROMStructPD . EEKodierbyte2_g & 0x0F)*5)+15) + (cab_SI_Transmission_Offsett[((EEPROM_Struct_PD . EEPROMStructPD . EEKodierbyte1_g & 0xE0)>>5)]-15)) )*9)/(15)) >= 5)? (byte)((((unsigned int)((((EEPROM_Struct_PD . EEPROMStructPD . EEKodierbyte2_g & 0x0F)*5)+15) + (cab_SI_Transmission_Offsett[((EEPROM_Struct_PD . EEPROMStructPD . EEKodierbyte1_g & 0xE0)>>5)]-15)) )*9)/(15)): 5)
typedef int VECTORCAST_MARKER__MACRO_END_rb_Si_Transmission_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_SolarShadowCorrFactor1_g;
(EEPROM_Struct_AD . EEPROMStructAD . SolarShadowCorrFactor1 )
typedef int VECTORCAST_MARKER__MACRO_END_rb_SolarShadowCorrFactor1_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_SolarShadowCorrFactor2_g;
(EEPROM_Struct_AD . EEPROMStructAD . SolarShadowCorrFactor2 )
typedef int VECTORCAST_MARKER__MACRO_END_rb_SolarShadowCorrFactor2_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_Speedreduct_g;
(((EEPROM_Struct_AD . EEPROMStructAD . PrametersStruct[((EEPROM_Struct_PD . EEPROMStructPD . EEKodierbyte1_g & 12)>>2)]. SchlierenFlag1)&0x10)> 0)
typedef int VECTORCAST_MARKER__MACRO_END_rb_Speedreduct_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_StandbyModeScanTime_g;
EEPROM_Struct_AD . EEPROMStructAD . StandbyModeScanTime_g
typedef int VECTORCAST_MARKER__MACRO_END_rb_StandbyModeScanTime_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_StandbyTimout_g;
(EEPROM_Struct_AD . EEPROMStructAD . StandbyTimout & 0x07)
typedef int VECTORCAST_MARKER__MACRO_END_rb_StandbyTimout_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_Standby_rain_measurement_1_g;
EEPROM_Struct_PD . EEPROMStructPD . Standby_rain_measurement_1_g
typedef int VECTORCAST_MARKER__MACRO_END_rb_Standby_rain_measurement_1_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_Standby_rain_measurement_2_g;
EEPROM_Struct_PD . EEPROMStructPD . Standby_rain_measurement_2_g
typedef int VECTORCAST_MARKER__MACRO_END_rb_Standby_rain_measurement_2_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_Standby_rain_measurement_3_g;
EEPROM_Struct_PD . EEPROMStructPD . Standby_rain_measurement_3_g
typedef int VECTORCAST_MARKER__MACRO_END_rb_Standby_rain_measurement_3_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_Standby_rain_measurement_4_g;
EEPROM_Struct_PD . EEPROMStructPD . Standby_rain_measurement_4_g
typedef int VECTORCAST_MARKER__MACRO_END_rb_Standby_rain_measurement_4_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_Standby_rain_measurement_5_g;
EEPROM_Struct_PD . EEPROMStructPD . Standby_rain_measurement_5_g
typedef int VECTORCAST_MARKER__MACRO_END_rb_Standby_rain_measurement_5_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_Standby_rain_measurement_6_g;
EEPROM_Struct_PD . EEPROMStructPD . Standby_rain_measurement_6_g
typedef int VECTORCAST_MARKER__MACRO_END_rb_Standby_rain_measurement_6_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_Stufe1_OG_g;
EEPROM_Struct_AD . EEPROMStructAD . PrametersStruct[((EEPROM_Struct_PD . EEPROMStructPD . EEKodierbyte1_g & 12)>>2)]. Stufe1_OG
typedef int VECTORCAST_MARKER__MACRO_END_rb_Stufe1_OG_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_Stufe1_UG_g;
EEPROM_Struct_AD . EEPROMStructAD . PrametersStruct[((EEPROM_Struct_PD . EEPROMStructPD . EEKodierbyte1_g & 12)>>2)]. Stufe1_UG
typedef int VECTORCAST_MARKER__MACRO_END_rb_Stufe1_UG_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_Stufe1_with_Int_og_g;
EEPROM_Struct_AD . EEPROMStructAD . PrametersStruct[((EEPROM_Struct_PD . EEPROMStructPD . EEKodierbyte1_g & 12)>>2)]. rb_Stufe1_with_Int_og
typedef int VECTORCAST_MARKER__MACRO_END_rb_Stufe1_with_Int_og_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_THR_DELTA_INTV_g;
EEPROM_Struct_RD . EEPROMStructRD . THR_DELTA_INTV_g
typedef int VECTORCAST_MARKER__MACRO_END_rb_THR_DELTA_INTV_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_TempIncidentCounter_g;
(EEPROM_Struct_RD . EEPROMStructRD . IncidentCounter5_g&0x0F )
typedef int VECTORCAST_MARKER__MACRO_END_rb_TempIncidentCounter_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_Threshold_TempIceRisk_g;
(EEPROM_Struct_AD . EEPROMStructAD . Threshold_TempIceRisk)
typedef int VECTORCAST_MARKER__MACRO_END_rb_Threshold_TempIceRisk_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_TimeForAfterwipeThrs_DelayScal_g;
(((EEPROM_Struct_AD . EEPROMStructAD . PrametersStruct[((EEPROM_Struct_PD . EEPROMStructPD . EEKodierbyte1_g & 12)>>2)]. Empf_Faktor_ST2_Offs & 0xC0)>>6)+1)
typedef int VECTORCAST_MARKER__MACRO_END_rb_TimeForAfterwipeThrs_DelayScal_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_TunnelDebounceFactor_g;
EEPROM_Struct_AD . EEPROMStructAD . TunnelDebounceFactor
typedef int VECTORCAST_MARKER__MACRO_END_rb_TunnelDebounceFactor_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_TunnelThresholdScaling_g;
EEPROM_Struct_AD . EEPROMStructAD . TunnelThresholdScaling_g
typedef int VECTORCAST_MARKER__MACRO_END_rb_TunnelThresholdScaling_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_VariantID_g;
EEPROM_Struct_PD . EEPROMStructPD . VariantID_g
typedef int VECTORCAST_MARKER__MACRO_END_rb_VariantID_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_VeryBrightInTunnelDelay_g;
(EEPROM_Struct_AD . EEPROMStructAD . VeryBrightInTunnelDelay_g)
typedef int VECTORCAST_MARKER__MACRO_END_rb_VeryBrightInTunnelDelay_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_VoltSupplyIncidentCounter_g;
(EEPROM_Struct_RD . EEPROMStructRD . IncidentCounter3_g&0x0F )
typedef int VECTORCAST_MARKER__MACRO_END_rb_VoltSupplyIncidentCounter_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_WDGIncidentCounter_g;
(EEPROM_Struct_RD . EEPROMStructRD . IncidentCounter3_g>>4)
typedef int VECTORCAST_MARKER__MACRO_END_rb_WDGIncidentCounter_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_WatchdogResetCounter_g;
EEPROM_Struct_RD . EEPROMStructRD . WatchdogResetCounter
typedef int VECTORCAST_MARKER__MACRO_END_rb_WatchdogResetCounter_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_WiperAPillarParkposition_E2_g;
((((EEPROM_Struct_PD . EEPROMStructPD . EEKodierbyte1_g & 0x01)>0) == 0)&& (((EEPROM_Struct_PD . EEPROMStructPD . EEKodierbyte1_g & 0x02)>0) == 1))
typedef int VECTORCAST_MARKER__MACRO_END_rb_WiperAPillarParkposition_E2_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_b_Correction_Inamb1_g;
0xFF
typedef int VECTORCAST_MARKER__MACRO_END_rb_b_Correction_Inamb1_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_b_Correction_Inamb2_g;
0xFF
typedef int VECTORCAST_MARKER__MACRO_END_rb_b_Correction_Inamb2_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_b_Correction_Inrec_g;
0xFF
typedef int VECTORCAST_MARKER__MACRO_END_rb_b_Correction_Inrec_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_dec_Int_Sp_off_g;
(EEPROM_Struct_AD . EEPROMStructAD . PrametersStruct[((EEPROM_Struct_PD . EEPROMStructPD . EEKodierbyte1_g & 12)>>2)]. dec_Int_Sp_off & 0x1F)
typedef int VECTORCAST_MARKER__MACRO_END_rb_dec_Int_Sp_off_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_dec_Ovr_Speicher_g;
((EEPROM_Struct_AD . EEPROMStructAD . PrametersStruct[((EEPROM_Struct_PD . EEPROMStructPD . EEKodierbyte1_g & 12)>>2)]. dec_Ovr_Speicher)&0x1F)
typedef int VECTORCAST_MARKER__MACRO_END_rb_dec_Ovr_Speicher_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_dec_st2_speicher_g;
(EEPROM_Struct_AD . EEPROMStructAD . dec_st2_speicher)
typedef int VECTORCAST_MARKER__MACRO_END_rb_dec_st2_speicher_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_delay_depressed_park_pointer_g;
(((EEPROM_Struct_AD . EEPROMStructAD . PrametersStruct[((EEPROM_Struct_PD . EEPROMStructPD . EEKodierbyte1_g & 12)>>2)]. dec_Ovr_Speicher)&0x60)>>5)
typedef int VECTORCAST_MARKER__MACRO_END_rb_delay_depressed_park_pointer_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_iceDetectionTemperature_g;
(EEPROM_Struct_AD . EEPROMStructAD . iceDetectionTemperature)
typedef int VECTORCAST_MARKER__MACRO_END_rb_iceDetectionTemperature_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_inc_int_speicher_g;
((EEPROM_Struct_AD . EEPROMStructAD . cb_inc_speicher_g )>>4)
typedef int VECTORCAST_MARKER__MACRO_END_rb_inc_int_speicher_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_inc_ovr_speicher_g;
((EEPROM_Struct_AD . EEPROMStructAD . cb_inc_speicher_g )& 0x0F)
typedef int VECTORCAST_MARKER__MACRO_END_rb_inc_ovr_speicher_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_maxTemperatureOffsett_g;
(EEPROM_Struct_AD . EEPROMStructAD . maxTemperatureOffsett_g )
typedef int VECTORCAST_MARKER__MACRO_END_rb_maxTemperatureOffsett_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_p_n_regenlichtschwelle_Zeit_g;
(EEPROM_Struct_AD . EEPROMStructAD . p_n_regenlichtschwelle_Zeit_g)
typedef int VECTORCAST_MARKER__MACRO_END_rb_p_n_regenlichtschwelle_Zeit_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_p_n_regenlichtschwelle_high_g;
(EEPROM_Struct_AD . EEPROMStructAD . p_n_regenlichtschwelle_low_high_g & 0x07)
typedef int VECTORCAST_MARKER__MACRO_END_rb_p_n_regenlichtschwelle_high_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_p_n_regenlichtschwelle_low_g;
((EEPROM_Struct_AD . EEPROMStructAD . p_n_regenlichtschwelle_low_high_g >>3)& 0x07)
typedef int VECTORCAST_MARKER__MACRO_END_rb_p_n_regenlichtschwelle_low_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_p_n_regenlichtschwelle_low_high_g;
(EEPROM_Struct_AD . EEPROMStructAD . p_n_regenlichtschwelle_low_high_g & 0x3F)
typedef int VECTORCAST_MARKER__MACRO_END_rb_p_n_regenlichtschwelle_low_high_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_p_t_autobahn_delay_off_g;
((EEPROM_Struct_AD . EEPROMStructAD . Frontwaschen_Autobahndelay_g)&0x0F)
typedef int VECTORCAST_MARKER__MACRO_END_rb_p_t_autobahn_delay_off_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_p_t_autobahn_delay_on_g;
((EEPROM_Struct_AD . EEPROMStructAD . p_t_autobahn_delay_on_g)&0x1F)
typedef int VECTORCAST_MARKER__MACRO_END_rb_p_t_autobahn_delay_on_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_p_t_frontwaschen_g;
((EEPROM_Struct_AD . EEPROMStructAD . Frontwaschen_Autobahndelay_g>>4)&0x0F)
typedef int VECTORCAST_MARKER__MACRO_END_rb_p_t_frontwaschen_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_p_t_lin_idle_g;
((EEPROM_Struct_AD . EEPROMStructAD . p_t_autobahn_delay_on_g>>5)&0x07)
typedef int VECTORCAST_MARKER__MACRO_END_rb_p_t_lin_idle_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_p_t_rs_abfragezyklus_g;
(EEPROM_Struct_AD . EEPROMStructAD . StandbyModeScanTime_g&0x1F)
typedef int VECTORCAST_MARKER__MACRO_END_rb_p_t_rs_abfragezyklus_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_p_t_tunnel_delay_g;
((EEPROM_Struct_AD . EEPROMStructAD . AfterTunnelDelayOffs >> 3)&0x03)
typedef int VECTORCAST_MARKER__MACRO_END_rb_p_t_tunnel_delay_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_p_v_autobahn_off_g;
((EEPROM_Struct_AD . EEPROMStructAD . p_v_autobahn_on_off_g)>>4)
typedef int VECTORCAST_MARKER__MACRO_END_rb_p_v_autobahn_off_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_p_v_autobahn_off_kmph_g;
(40+(((EEPROM_Struct_AD . EEPROMStructAD . p_v_autobahn_on_off_g)>>4)*5))
typedef int VECTORCAST_MARKER__MACRO_END_rb_p_v_autobahn_off_kmph_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_p_v_autobahn_on_g;
((EEPROM_Struct_AD . EEPROMStructAD . p_v_autobahn_on_off_g)&0x0f)
typedef int VECTORCAST_MARKER__MACRO_END_rb_p_v_autobahn_on_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_p_v_autobahn_on_off_g;
(EEPROM_Struct_AD . EEPROMStructAD . p_v_autobahn_on_off_g)
typedef int VECTORCAST_MARKER__MACRO_END_rb_p_v_autobahn_on_off_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_rs_WINDOW_COMP_THRESHOLD_g;
(((EEPROM_Struct_AD . EEPROMStructAD . PrametersStruct[((EEPROM_Struct_PD . EEPROMStructPD . EEKodierbyte1_g & 12)>>2)]. dec_Int_Sp_off & 0xE0)>>4) + 18)
typedef int VECTORCAST_MARKER__MACRO_END_rb_rs_WINDOW_COMP_THRESHOLD_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_sig_ans_schw_offs_g;
EEPROM_Struct_AD . EEPROMStructAD . PrametersStruct[((EEPROM_Struct_PD . EEPROMStructPD . EEKodierbyte1_g & 12)>>2)]. sig_ans_schw_offs
typedef int VECTORCAST_MARKER__MACRO_END_rb_sig_ans_schw_offs_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_upperTolerance_StartupWipe_g;
(EEPROM_Struct_AD . EEPROMStructAD . upperTolerance_StartupWipe)
typedef int VECTORCAST_MARKER__MACRO_END_rb_upperTolerance_StartupWipe_g;

typedef int VECTORCAST_MARKER__MACRO_START_rb_wiperSpeedHysteresis;
(EEPROM_Struct_AD . EEPROMStructAD . wiperSpeedHysteresis )
typedef int VECTORCAST_MARKER__MACRO_END_rb_wiperSpeedHysteresis;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_ADC_Error_g;
(uF_uC_Error_g . Bit . B0)
typedef int VECTORCAST_MARKER__MACRO_END_rbi_ADC_Error_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_AD_Conversion_OR_SPI_Active_g;
uF_SPI_flags_g . Bit . B1
typedef int VECTORCAST_MARKER__MACRO_END_rbi_AD_Conversion_OR_SPI_Active_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_ASICReg_NoValidVals_Error_g;
uF_ASIC_Ctrl_Error_Flags_g . Bit . B4
typedef int VECTORCAST_MARKER__MACRO_END_rbi_ASICReg_NoValidVals_Error_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_ASICStandByModeRequest_g;
uF_ASIC_ControlFlags_g . Bit . B4
typedef int VECTORCAST_MARKER__MACRO_END_rbi_ASICStandByModeRequest_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_ASIC_Communication_not_possible_g;
uF_ASIC_Communication_g . Bit . B0
typedef int VECTORCAST_MARKER__MACRO_END_rbi_ASIC_Communication_not_possible_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_ASIC_DiagnosisRequest2_g;
uF_ASIC_Communication_g . Bit . B1
typedef int VECTORCAST_MARKER__MACRO_END_rbi_ASIC_DiagnosisRequest2_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_ASIC_FreqTrimming_error_g;
uF_ASIC_Ctrl_Error_Flags_g . Bit . B5
typedef int VECTORCAST_MARKER__MACRO_END_rbi_ASIC_FreqTrimming_error_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_ASIC_NoValidAD_Error_g;
uF_ASIC_Ctrl_Error_Flags_g . Bit . B1
typedef int VECTORCAST_MARKER__MACRO_END_rbi_ASIC_NoValidAD_Error_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_ASIC_SPI_Error_g;
uF_ASIC_Ctrl_Error_Flags_g . Bit . B0
typedef int VECTORCAST_MARKER__MACRO_END_rbi_ASIC_SPI_Error_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_ASIC_StandByModeOn_g;
uF_ASIC_Communication_g . Bit . B3
typedef int VECTORCAST_MARKER__MACRO_END_rbi_ASIC_StandByModeOn_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_ASIC_Step_Response_ready;
uF_ASIC_Communication_g . Bit . B4
typedef int VECTORCAST_MARKER__MACRO_END_rbi_ASIC_Step_Response_ready;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_ASIC_initTimeout_err_g;
uF_ASIC_Error_Flags_g . Bit . B7
typedef int VECTORCAST_MARKER__MACRO_END_rbi_ASIC_initTimeout_err_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_ASICgainAdjustRunning_g;
uF_LIN_DiagReq2_mg . Bit . B5
typedef int VECTORCAST_MARKER__MACRO_END_rbi_ASICgainAdjustRunning_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_AlwaysIntervalThrs_g;
((EEPROM_Struct_PD . EEPROMStructPD . RSControlFlags & 0x80)>0)
typedef int VECTORCAST_MARKER__MACRO_END_rbi_AlwaysIntervalThrs_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_AminuBMaxPositiv_g;
uF_LIN_DiagReq2_mg . Bit . B6
typedef int VECTORCAST_MARKER__MACRO_END_rbi_AminuBMaxPositiv_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_AutomaticWipingModeInv_g;
uF_StatusRainsensor_mg . Bit . B4
typedef int VECTORCAST_MARKER__MACRO_END_rbi_AutomaticWipingModeInv_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_AutomaticWipingMode_g;
uF_StatusRainsensor_mg . Bit . B0
typedef int VECTORCAST_MARKER__MACRO_END_rbi_AutomaticWipingMode_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_BlankBetweenError_g;
uF_E2ConfigErrorFlags_g . Bit . B4
typedef int VECTORCAST_MARKER__MACRO_END_rbi_BlankBetweenError_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_BlankCell_mg;
uF_E2Flag_g . Bit . B4
typedef int VECTORCAST_MARKER__MACRO_END_rbi_BlankCell_mg;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_ButterflyIsEquipped;
(uF_Butterfly_Flags_g . Bit . B1)
typedef int VECTORCAST_MARKER__MACRO_END_rbi_ButterflyIsEquipped;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_CRC_ChangedByDiagnostic_g;
uF_LIN_DiagReq2_mg . Bit . B1
typedef int VECTORCAST_MARKER__MACRO_END_rbi_CRC_ChangedByDiagnostic_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_CarCode_recieved_g;
(uF_Butterfly_Flags_g . Bit . B7)
typedef int VECTORCAST_MARKER__MACRO_END_rbi_CarCode_recieved_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_ChangingCluster_mg;
uF_E2Flag_g . Bit . B1
typedef int VECTORCAST_MARKER__MACRO_END_rbi_ChangingCluster_mg;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_Check_LS_NoCommunication_g;
(uF_Check_lightsensor_g . Bit . B3)
typedef int VECTORCAST_MARKER__MACRO_END_rbi_Check_LS_NoCommunication_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_ClearCluster_mg;
uF_E2Flag_g . Bit . B2
typedef int VECTORCAST_MARKER__MACRO_END_rbi_ClearCluster_mg;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_ClearNewCluster_mg;
uF_E2Flag_g . Bit . B3
typedef int VECTORCAST_MARKER__MACRO_END_rbi_ClearNewCluster_mg;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_ClockFreq_Error_g;
(uF_uC_Error_g . Bit . B1)
typedef int VECTORCAST_MARKER__MACRO_END_rbi_ClockFreq_Error_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_ClusterError_g;
uF_E2ConfigErrorFlags_g . Bit . B3
typedef int VECTORCAST_MARKER__MACRO_END_rbi_ClusterError_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_ClusterFormatError_g;
uF_E2ConfigErrorFlags_g . Bit . B7
typedef int VECTORCAST_MARKER__MACRO_END_rbi_ClusterFormatError_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_CodingRequest_mg;
uF_LIN_Diagnosis_mg . Bit . B0
typedef int VECTORCAST_MARKER__MACRO_END_rbi_CodingRequest_mg;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_Command_CloseWindows_g;
uF_SCIFlags_mg . Bit . B4
typedef int VECTORCAST_MARKER__MACRO_END_rbi_Command_CloseWindows_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_ConnectedToMaster_g;
uF_SCIFlags_mg . Bit . B1
typedef int VECTORCAST_MARKER__MACRO_END_rbi_ConnectedToMaster_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_ContSP2WipeBeforeError_g;
uF_StatusRainsensor_mg . Bit . B1
typedef int VECTORCAST_MARKER__MACRO_END_rbi_ContSP2WipeBeforeError_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_ContWipeBeforeError_g;
uF_StatusRainsensor_mg . Bit . B5
typedef int VECTORCAST_MARKER__MACRO_END_rbi_ContWipeBeforeError_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_Coupling_measurement_active_g;
uF_ASIC_ControlFlags_2_g . Bit . B1
typedef int VECTORCAST_MARKER__MACRO_END_rbi_Coupling_measurement_active_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_Coupling_measurement_to_linearise_g;
uF_ASIC_ControlFlags_2_g . Bit . B2
typedef int VECTORCAST_MARKER__MACRO_END_rbi_Coupling_measurement_to_linearise_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_DefaultValues_mg;
uF_E2Flag_g . Bit . B6
typedef int VECTORCAST_MARKER__MACRO_END_rbi_DefaultValues_mg;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_DiagnoseReadEEPROM_g;
uF_LIN_Diagnosis_mg . Bit . B4
typedef int VECTORCAST_MARKER__MACRO_END_rbi_DiagnoseReadEEPROM_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_DiagnoseWriteEEPROM_g;
uF_LIN_Diagnosis_mg . Bit . B3
typedef int VECTORCAST_MARKER__MACRO_END_rbi_DiagnoseWriteEEPROM_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_DiagnosisPulseValid_g;
uF_LIN_DiagReq2_mg . Bit . B0
typedef int VECTORCAST_MARKER__MACRO_END_rbi_DiagnosisPulseValid_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_DoNormalCalculation_g;
(uF_LightInternalStatus_g . Bit . B2)
typedef int VECTORCAST_MARKER__MACRO_END_rbi_DoNormalCalculation_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_DoubleOverwiped;
(uF_Butterfly_Flags_g . Bit . B3)
typedef int VECTORCAST_MARKER__MACRO_END_rbi_DoubleOverwiped;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_EEPROMBytesToWrite_g;
uF_Main_Flags_g . Bit . B2
typedef int VECTORCAST_MARKER__MACRO_END_rbi_EEPROMBytesToWrite_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_EEPROMBytesWritten_g;
uF_Main_Flags_g . Bit . B1
typedef int VECTORCAST_MARKER__MACRO_END_rbi_EEPROMBytesWritten_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_EEPROMLoad_g;
uF_Main_Flags_g . Bit . B6
typedef int VECTORCAST_MARKER__MACRO_END_rbi_EEPROMLoad_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_EEPROMWriteSuccess_g;
uF_Main_Flags_g . Bit . B0
typedef int VECTORCAST_MARKER__MACRO_END_rbi_EEPROMWriteSuccess_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_EraseError_g;
uF_E2ConfigErrorFlags_g . Bit . B1
typedef int VECTORCAST_MARKER__MACRO_END_rbi_EraseError_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_FastHighwayMode_g;
(uF_LightInternalStatus_g . Bit . B4)
typedef int VECTORCAST_MARKER__MACRO_END_rbi_FastHighwayMode_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_First_Call_g;
(uF_Humi_g . Bit . B2)
typedef int VECTORCAST_MARKER__MACRO_END_rbi_First_Call_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_FrameValid_mg;
uF_sciState_mg . Bit . B7
typedef int VECTORCAST_MARKER__MACRO_END_rbi_FrameValid_mg;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_Freewaylight_enabled_g;
((EEPROM_Struct_PD . EEPROMStructPD . EEKodierbyte0_g & 0x01)>0)
typedef int VECTORCAST_MARKER__MACRO_END_rbi_Freewaylight_enabled_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_FreqMeasureDone;
uF_ASIC_Calc_Flags_g . Bit . B4
typedef int VECTORCAST_MARKER__MACRO_END_rbi_FreqMeasureDone;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_GotoSleep_g;
uF_SCIFlags_mg . Bit . B2
typedef int VECTORCAST_MARKER__MACRO_END_rbi_GotoSleep_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_HammingError_g;
uF_E2ConfigErrorFlags_g . Bit . B6
typedef int VECTORCAST_MARKER__MACRO_END_rbi_HammingError_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_HammingWarning_g;
uF_E2ConfigErrorFlags_g . Bit . B5
typedef int VECTORCAST_MARKER__MACRO_END_rbi_HammingWarning_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_HeaderExpected_mg;
uF_sciState_mg . Bit . B3
typedef int VECTORCAST_MARKER__MACRO_END_rbi_HeaderExpected_mg;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_HumTemp_Module_enabled_g;
((EEPROM_Struct_PD . EEPROMStructPD . RSControlFlags & 0x08)>0)
typedef int VECTORCAST_MARKER__MACRO_END_rbi_HumTemp_Module_enabled_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_HumiSupply_OK_g;
(uF_Humi_g . Bit . B0)
typedef int VECTORCAST_MARKER__MACRO_END_rbi_HumiSupply_OK_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_I2C_OUTPUT_Enabled_g;
((EEPROM_Struct_AD . EEPROMStructAD . MaxOverwipeSensitivity&0x40)>0)
typedef int VECTORCAST_MARKER__MACRO_END_rbi_I2C_OUTPUT_Enabled_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_Ignition_g;
uF_VoltageStatus_g . Bit . B2
typedef int VECTORCAST_MARKER__MACRO_END_rbi_Ignition_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_IntSpInc_Scal_longerInt_enabled_g;
((EEPROM_Struct_AD . EEPROMStructAD . PrametersStruct[((EEPROM_Struct_PD . EEPROMStructPD . EEKodierbyte1_g & 12)>>2)]. RSEmpfFactorScaling&0x80)> 0 )
typedef int VECTORCAST_MARKER__MACRO_END_rbi_IntSpInc_Scal_longerInt_enabled_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_InternalResetOccured_g;
uF_Main_Flags_g . Bit . B7
typedef int VECTORCAST_MARKER__MACRO_END_rbi_InternalResetOccured_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_LEDx_LClosed_error_g;
uF_ASIC_Error_Flags_g . Bit . B6
typedef int VECTORCAST_MARKER__MACRO_END_rbi_LEDx_LClosed_error_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_LEDx_LStop_error_g;
uF_ASIC_Error_Flags_g . Bit . B5
typedef int VECTORCAST_MARKER__MACRO_END_rbi_LEDx_LStop_error_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_LINRainsensorDisabled_g;
uF_Communication_mg . Bit . B5
typedef int VECTORCAST_MARKER__MACRO_END_rbi_LINRainsensorDisabled_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_LINTableInitialised_g;
uF_SCIFlags_mg . Bit . B3
typedef int VECTORCAST_MARKER__MACRO_END_rbi_LINTableInitialised_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_LIN_CommunicationEvent_g;
uF_ASIC_ControlFlags_g . Bit . B3
typedef int VECTORCAST_MARKER__MACRO_END_rbi_LIN_CommunicationEvent_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_LSPotiStageChanged_g;
uf_LightAlgoReInit_g . Bit . B1
typedef int VECTORCAST_MARKER__MACRO_END_rbi_LSPotiStageChanged_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_LSS_Interval_g;
RSStatus . Bit . B7
typedef int VECTORCAST_MARKER__MACRO_END_rbi_LSS_Interval_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_LS_Error_ALS2_g;
uF_ASIC_Error_Flags_g . Bit . B0
typedef int VECTORCAST_MARKER__MACRO_END_rbi_LS_Error_ALS2_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_LS_Error_ALS5_g;
uF_ASIC_Error_Flags_g . Bit . B1
typedef int VECTORCAST_MARKER__MACRO_END_rbi_LS_Error_ALS5_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_LS_Error_REC_g;
uF_ASIC_Error_Flags_g . Bit . B2
typedef int VECTORCAST_MARKER__MACRO_END_rbi_LS_Error_REC_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_LS_Error_VCalib_meas_g;
uF_ASIC_Error_Flags_g . Bit . B4
typedef int VECTORCAST_MARKER__MACRO_END_rbi_LS_Error_VCalib_meas_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_LS_Error_Vref_g;
uF_ASIC_Error_Flags_g . Bit . B3
typedef int VECTORCAST_MARKER__MACRO_END_rbi_LS_Error_Vref_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_LS_reinit_g;
uf_LightAlgoReInit_g . Bit . B0
typedef int VECTORCAST_MARKER__MACRO_END_rbi_LS_reinit_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_LS_reinit_init_g;
uf_LightAlgoReInit_g . Bit . B3
typedef int VECTORCAST_MARKER__MACRO_END_rbi_LS_reinit_init_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_LastAminuBMaxPositiv_g;
uF_LIN_DiagReq2_mg . Bit . B7
typedef int VECTORCAST_MARKER__MACRO_END_rbi_LastAminuBMaxPositiv_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_LastParkPosition_g;
uF_StatusRainsensor_mg . Bit . B6
typedef int VECTORCAST_MARKER__MACRO_END_rbi_LastParkPosition_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_LessSensitivityLowSCSPotiStage_g;
(uF_Butterfly_Flags_g . Bit . B2)
typedef int VECTORCAST_MARKER__MACRO_END_rbi_LessSensitivityLowSCSPotiStage_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_LightConfigRecieved;
1
typedef int VECTORCAST_MARKER__MACRO_END_rbi_LightConfigRecieved;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_LightSensitivityRecieved_g;
uF_Communication_mg . Bit . B1
typedef int VECTORCAST_MARKER__MACRO_END_rbi_LightSensitivityRecieved_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_LightSensorActiveChange_FromBus_g;
uf_LightAlgoReInit_g . Bit . B2
typedef int VECTORCAST_MARKER__MACRO_END_rbi_LightSensorActiveChange_FromBus_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_LightSensorActive_g;
(uF_LightInternalStatus_g . Bit . B0)
typedef int VECTORCAST_MARKER__MACRO_END_rbi_LightSensorActive_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_LightSensorError_g;
(uF_LightInternalStatus_g . Bit . B5)
typedef int VECTORCAST_MARKER__MACRO_END_rbi_LightSensorError_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_LightSensorInactive_g;
0xFF
typedef int VECTORCAST_MARKER__MACRO_END_rbi_LightSensorInactive_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_LightSensorVetoConflict_g;
(uF_LightInternalStatus_g . Bit . B1)
typedef int VECTORCAST_MARKER__MACRO_END_rbi_LightSensorVetoConflict_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_LightValuesInitialised_g;
uF_ASIC_ControlFlags_g . Bit . B1
typedef int VECTORCAST_MARKER__MACRO_END_rbi_LightValuesInitialised_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_LightValuesMeasured_mg;
uF_ASIC_Calc_Flags_g . Bit . B1
typedef int VECTORCAST_MARKER__MACRO_END_rbi_LightValuesMeasured_mg;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_LongUnderVoltage_g;
uF_VoltageStatus_g . Bit . B7
typedef int VECTORCAST_MARKER__MACRO_END_rbi_LongUnderVoltage_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_LowVoltage;
RSStatus . Bit . B2
typedef int VECTORCAST_MARKER__MACRO_END_rbi_LowVoltage;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_MasterMessageFlag_mg;
uF_LIN_Diagnosis_mg . Bit . B2
typedef int VECTORCAST_MARKER__MACRO_END_rbi_MasterMessageFlag_mg;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_MasterMessageRecieved_g;
uF_Communication_mg . Bit . B1
typedef int VECTORCAST_MARKER__MACRO_END_rbi_MasterMessageRecieved_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_MeanPulsLengthOverwipeEmpfreduction_g;
(((EEPROM_Struct_AD . EEPROMStructAD . PrametersStruct[((EEPROM_Struct_PD . EEPROMStructPD . EEKodierbyte1_g & 12)>>2)]. SchlierenFlag1)&0x80)> 0)
typedef int VECTORCAST_MARKER__MACRO_END_rbi_MeanPulsLengthOverwipeEmpfreduction_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_ModulatorOff_ForINAMB1_meas_g;
0xFF
typedef int VECTORCAST_MARKER__MACRO_END_rbi_ModulatorOff_ForINAMB1_meas_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_Modulator_On_g;
uF_ASIC_ControlFlags_g . Bit . B0
typedef int VECTORCAST_MARKER__MACRO_END_rbi_Modulator_On_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_Night;
RSStatus . Bit . B3
typedef int VECTORCAST_MARKER__MACRO_END_rbi_Night;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_NonDefaultValues_mg;
uF_E2Flag_g . Bit . B7
typedef int VECTORCAST_MARKER__MACRO_END_rbi_NonDefaultValues_mg;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_OneTimeOrDoubleOverwiped;
(uF_Butterfly_Flags_g . Bit . B0)
typedef int VECTORCAST_MARKER__MACRO_END_rbi_OneTimeOrDoubleOverwiped;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_OutOfRangeError_g;
uF_E2ConfigErrorFlags_g . Bit . B2
typedef int VECTORCAST_MARKER__MACRO_END_rbi_OutOfRangeError_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_OverVoltage_g;
uF_VoltageStatus_g . Bit . B3
typedef int VECTORCAST_MARKER__MACRO_END_rbi_OverVoltage_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_PWM_OUTPUT_Enabled_g;
((EEPROM_Struct_AD . EEPROMStructAD . MaxOverwipeSensitivity&0x80)>0)
typedef int VECTORCAST_MARKER__MACRO_END_rbi_PWM_OUTPUT_Enabled_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_ParkPosition_NearRLTPosition_g;
uF_StatusRainsensor2_mg . Bit . B0
typedef int VECTORCAST_MARKER__MACRO_END_rbi_ParkPosition_NearRLTPosition_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_ParkPosition_g;
uF_StatusRainsensor_mg . Bit . B7
typedef int VECTORCAST_MARKER__MACRO_END_rbi_ParkPosition_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_Powerfail_g;
uF_VoltageStatus_g . Bit . B1
typedef int VECTORCAST_MARKER__MACRO_END_rbi_Powerfail_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_REGV_OSAT_Error_g;
uF_ASIC_Ctrl_Error_Flags_g . Bit . B2
typedef int VECTORCAST_MARKER__MACRO_END_rbi_REGV_OSAT_Error_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_RLFS_is_FS_g;
((EEPROM_Struct_PD . EEPROMStructPD . RSControlFlags & 0x10)>0)
typedef int VECTORCAST_MARKER__MACRO_END_rbi_RLFS_is_FS_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_RSWipeFastDmd;
RSStatus . Bit . B6
typedef int VECTORCAST_MARKER__MACRO_END_rbi_RSWipeFastDmd;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_RSWipeSlowDmd;
RSStatus . Bit . B5
typedef int VECTORCAST_MARKER__MACRO_END_rbi_RSWipeSlowDmd;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_RS_Error_Loop_g;
uF_ASIC_ControlFlags_2_g . Bit . B3
typedef int VECTORCAST_MARKER__MACRO_END_rbi_RS_Error_Loop_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_RainIsPresent_g;
uF_GainAdjustFlags_g . Bit . B0
typedef int VECTORCAST_MARKER__MACRO_END_rbi_RainIsPresent_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_RainLight_enabled_g;
((EEPROM_Struct_PD . EEPROMStructPD . EEKodierbyte0_g & 0x02)>0)
typedef int VECTORCAST_MARKER__MACRO_END_rbi_RainLight_enabled_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_RainSensorEnable;
RSStatus . Bit . B0
typedef int VECTORCAST_MARKER__MACRO_END_rbi_RainSensorEnable;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_RainSensorError;
RSStatus . Bit . B4
typedef int VECTORCAST_MARKER__MACRO_END_rbi_RainSensorError;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_RainSensor_enabled_g;
(EEPROM_Struct_PD . EEPROMStructPD . RSControlFlags & 0x01)
typedef int VECTORCAST_MARKER__MACRO_END_rbi_RainSensor_enabled_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_RainsensorAlwaysOn_g;
((EEPROM_Struct_PD . EEPROMStructPD . RSControlFlags & 0x40)>0)
typedef int VECTORCAST_MARKER__MACRO_END_rbi_RainsensorAlwaysOn_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_RainsensorDisabled_g;
((EEPROM_Struct_PD . EEPROMStructPD . EEKodierbyte0_g & 0x40)>0)
typedef int VECTORCAST_MARKER__MACRO_END_rbi_RainsensorDisabled_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_ReInitTable_g;
uF_Communication_mg . Bit . B7
typedef int VECTORCAST_MARKER__MACRO_END_rbi_ReInitTable_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_RealParkContact_g;
uF_SCIFlags_mg . Bit . B6
typedef int VECTORCAST_MARKER__MACRO_END_rbi_RealParkContact_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_ReduceIntANDOvrMemoryLoading_g;
(uF_Butterfly_Flags_g . Bit . B5)
typedef int VECTORCAST_MARKER__MACRO_END_rbi_ReduceIntANDOvrMemoryLoading_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_Regulation48LightOnFlag_g;
(uF_LightInternalStatus_g . Bit . B6)
typedef int VECTORCAST_MARKER__MACRO_END_rbi_Regulation48LightOnFlag_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_Relase_FixedIntervalTime_g;
uF_StatusRainsensor2_mg . Bit . B2
typedef int VECTORCAST_MARKER__MACRO_END_rbi_Relase_FixedIntervalTime_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_Req_InrecWorkaround_g;
uF_ASIC_ControlFlags_g . Bit . B5
typedef int VECTORCAST_MARKER__MACRO_END_rbi_Req_InrecWorkaround_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_ResetSourceWasInternal_g;
uF_Main_Flags_g . Bit . B3
typedef int VECTORCAST_MARKER__MACRO_END_rbi_ResetSourceWasInternal_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_ResponsePending_g;
uF_LIN_Diagnosis_mg . Bit . B5
typedef int VECTORCAST_MARKER__MACRO_END_rbi_ResponsePending_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_SHT_DataLine_OK_g;
(uF_Humi_g . Bit . B1)
typedef int VECTORCAST_MARKER__MACRO_END_rbi_SHT_DataLine_OK_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_SPI_LOW_CSB_g;
uF_ASIC_ControlFlags_g . Bit . B6
typedef int VECTORCAST_MARKER__MACRO_END_rbi_SPI_LOW_CSB_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_SPI_activ_g;
uF_SPI_flags_g . Bit . B0
typedef int VECTORCAST_MARKER__MACRO_END_rbi_SPI_activ_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_SendWakeUpFrame_g;
uF_SCIFlags_mg . Bit . B0
typedef int VECTORCAST_MARKER__MACRO_END_rbi_SendWakeUpFrame_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_SensitivityTreatmentError_g;
(uF_LightInternalStatus_g . Bit . B7)
typedef int VECTORCAST_MARKER__MACRO_END_rbi_SensitivityTreatmentError_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_SigSt2_max;
RS_Flags_Int . Bit . B5
typedef int VECTORCAST_MARKER__MACRO_END_rbi_SigSt2_max;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_Sig_Ansamml_Status;
RS_Flags_Int . Bit . B4
typedef int VECTORCAST_MARKER__MACRO_END_rbi_Sig_Ansamml_Status;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_Sig_Ansammlung;
RS_Flags_Int . Bit . B3
typedef int VECTORCAST_MARKER__MACRO_END_rbi_Sig_Ansammlung;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_Sig_Ansammlung_Ford;
(uF_Butterfly_Flags_g . Bit . B4)
typedef int VECTORCAST_MARKER__MACRO_END_rbi_Sig_Ansammlung_Ford;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_SignalQuelleWischerParklage_g;
((EEPROM_Struct_PD . EEPROMStructPD . EEKodierbyte0_g & 0x80)>0)
typedef int VECTORCAST_MARKER__MACRO_END_rbi_SignalQuelleWischerParklage_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_Signal_Merker;
RS_Flags_Int . Bit . B6
typedef int VECTORCAST_MARKER__MACRO_END_rbi_Signal_Merker;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_SimulateParkContact_g;
(uF_Butterfly_Flags_g . Bit . B6)
typedef int VECTORCAST_MARKER__MACRO_END_rbi_SimulateParkContact_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_SingleDropProtection_g;
RS_Flags_Int . Bit . B7
typedef int VECTORCAST_MARKER__MACRO_END_rbi_SingleDropProtection_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_SoSe_Enabled_g;
((EEPROM_Struct_PD . EEPROMStructPD . RSControlFlags & 0x02)>0)
typedef int VECTORCAST_MARKER__MACRO_END_rbi_SoSe_Enabled_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_SoftwareBug_g;
uF_Check_lightsensor_g . Bit . B4
typedef int VECTORCAST_MARKER__MACRO_END_rbi_SoftwareBug_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_SolarValuesInitialised_g;
uF_ASIC_ControlFlags_g . Bit . B2
typedef int VECTORCAST_MARKER__MACRO_END_rbi_SolarValuesInitialised_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_SpeicherDecAtDryWipe_g;
(((EEPROM_Struct_AD . EEPROMStructAD . PrametersStruct[((EEPROM_Struct_PD . EEPROMStructPD . EEKodierbyte1_g & 12)>>2)]. SchlierenFlag1)&0x40)> 0)
typedef int VECTORCAST_MARKER__MACRO_END_rbi_SpeicherDecAtDryWipe_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_StandbyFunction_enabled_g;
((EEPROM_Struct_PD . EEPROMStructPD . EEKodierbyte0_g & 0x04)>0)
typedef int VECTORCAST_MARKER__MACRO_END_rbi_StandbyFunction_enabled_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_StandbyModulatorIntegrating_g;
uF_SPI_flags_g . Bit . B2
typedef int VECTORCAST_MARKER__MACRO_END_rbi_StandbyModulatorIntegrating_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_StartTransmission_mg;
uF_sciState_mg . Bit . B4
typedef int VECTORCAST_MARKER__MACRO_END_rbi_StartTransmission_mg;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_Timer10ms_OK_g;
(uF_Timer_g . Bit . B1)
typedef int VECTORCAST_MARKER__MACRO_END_rbi_Timer10ms_OK_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_Timer1s_OK_g;
(uF_Timer_g . Bit . B2)
typedef int VECTORCAST_MARKER__MACRO_END_rbi_Timer1s_OK_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_Tropfen_Merker;
RS_Flags_Int . Bit . B2
typedef int VECTORCAST_MARKER__MACRO_END_rbi_Tropfen_Merker;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_TunnelWipe_mg;
uF_Communication_mg . Bit . B3
typedef int VECTORCAST_MARKER__MACRO_END_rbi_TunnelWipe_mg;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_UnderVoltage_g;
uF_VoltageStatus_g . Bit . B0
typedef int VECTORCAST_MARKER__MACRO_END_rbi_UnderVoltage_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_VDD_LightSignalError_g;
uF_ASIC_Ctrl_Error_Flags_g . Bit . B3
typedef int VECTORCAST_MARKER__MACRO_END_rbi_VDD_LightSignalError_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_VIref_Error_g;
uF_ASIC_Error_Flags1_g . Bit . B0
typedef int VECTORCAST_MARKER__MACRO_END_rbi_VIref_Error_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_VW_BritghtnessScaling_g;
((EEPROM_Struct_PD . EEPROMStructPD . RSControlFlags & 0x01)>0)
typedef int VECTORCAST_MARKER__MACRO_END_rbi_VW_BritghtnessScaling_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_WasInOperatingRange_g;
uF_VoltageStatus_g . Bit . B4
typedef int VECTORCAST_MARKER__MACRO_END_rbi_WasInOperatingRange_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_WashingActive;
RSStatus . Bit . B1
typedef int VECTORCAST_MARKER__MACRO_END_rbi_WashingActive;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_WashingActive_g;
RSStatus . Bit . B1
typedef int VECTORCAST_MARKER__MACRO_END_rbi_WashingActive_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_WatchdogCheckEnabel_g;
uF_Main_Flags_g . Bit . B4
typedef int VECTORCAST_MARKER__MACRO_END_rbi_WatchdogCheckEnabel_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_WindowOpenIgnitionWasOn_g;
uF_VoltageStatus_g . Bit . B5
typedef int VECTORCAST_MARKER__MACRO_END_rbi_WindowOpenIgnitionWasOn_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_WiperMotorMessageFlag_mg;
uF_LIN_Diagnosis_mg . Bit . B1
typedef int VECTORCAST_MARKER__MACRO_END_rbi_WiperMotorMessageFlag_mg;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_WischerWendelage_g;
uF_StatusRainsensor_mg . Bit . B2
typedef int VECTORCAST_MARKER__MACRO_END_rbi_WischerWendelage_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_WriteError_g;
uF_E2ConfigErrorFlags_g . Bit . B0
typedef int VECTORCAST_MARKER__MACRO_END_rbi_WriteError_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_WriteResetSource_g;
uF_Main_Flags_g . Bit . B5
typedef int VECTORCAST_MARKER__MACRO_END_rbi_WriteResetSource_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_Write_ReleaseMarker_g;
uF_StatusRainsensor2_mg . Bit . B3
typedef int VECTORCAST_MARKER__MACRO_END_rbi_Write_ReleaseMarker_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_WrongEEPROM_Parameter_g;
uF_SCIFlags_mg . Bit . B5
typedef int VECTORCAST_MARKER__MACRO_END_rbi_WrongEEPROM_Parameter_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_checkWischerWendelage_old_g;
uF_StatusRainsensor_mg . Bit . B3
typedef int VECTORCAST_MARKER__MACRO_END_rbi_checkWischerWendelage_old_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_enable_Programming_EEPROM_g;
uF_LIN_Diagnosis_mg . Bit . B7
typedef int VECTORCAST_MARKER__MACRO_END_rbi_enable_Programming_EEPROM_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_latched_ResponseError_mg;
uF_Communication_mg . Bit . B6
typedef int VECTORCAST_MARKER__MACRO_END_rbi_latched_ResponseError_mg;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_modi_lightsens_beforeTunnel_inv_g;
uF_modi_lightsens_inv_g . Bit . B3
typedef int VECTORCAST_MARKER__MACRO_END_rbi_modi_lightsens_beforeTunnel_inv_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_modi_lightsens_darkStart_g;
(uF_modi_lightsens_g . Bit . B0)
typedef int VECTORCAST_MARKER__MACRO_END_rbi_modi_lightsens_darkStart_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_modi_lightsens_darkStart_inv_g;
uF_modi_lightsens_inv_g . Bit . B0
typedef int VECTORCAST_MARKER__MACRO_END_rbi_modi_lightsens_darkStart_inv_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_modi_lightsens_forest_inv_g;
uF_modi_lightsens_inv_g . Bit . B5
typedef int VECTORCAST_MARKER__MACRO_END_rbi_modi_lightsens_forest_inv_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_modi_lightsens_night_g;
uF_modi_lightsens_g . Bit . B1
typedef int VECTORCAST_MARKER__MACRO_END_rbi_modi_lightsens_night_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_modi_lightsens_night_inv_g;
uF_modi_lightsens_inv_g . Bit . B1
typedef int VECTORCAST_MARKER__MACRO_END_rbi_modi_lightsens_night_inv_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_modi_lightsens_rain_g;
uF_modi_lightsens_g . Bit . B4
typedef int VECTORCAST_MARKER__MACRO_END_rbi_modi_lightsens_rain_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_modi_lightsens_rain_inv_g;
uF_modi_lightsens_inv_g . Bit . B4
typedef int VECTORCAST_MARKER__MACRO_END_rbi_modi_lightsens_rain_inv_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_modi_lightsens_tunnel_alt_mg;
uF_Communication_mg . Bit . B4
typedef int VECTORCAST_MARKER__MACRO_END_rbi_modi_lightsens_tunnel_alt_mg;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_modi_lightsens_tunnel_g;
uF_modi_lightsens_g . Bit . B2
typedef int VECTORCAST_MARKER__MACRO_END_rbi_modi_lightsens_tunnel_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_modi_lightsens_tunnel_inv_g;
uF_modi_lightsens_inv_g . Bit . B2
typedef int VECTORCAST_MARKER__MACRO_END_rbi_modi_lightsens_tunnel_inv_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_negativeSign_mg;
uF_ASIC_Calc_Flags_g . Bit . B0
typedef int VECTORCAST_MARKER__MACRO_END_rbi_negativeSign_mg;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_night_g;
(uF_LightInternalStatus_g . Bit . B3)
typedef int VECTORCAST_MARKER__MACRO_END_rbi_night_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_oneTimeAnswerd_g;
uF_SCIFlags_mg . Bit . B7
typedef int VECTORCAST_MARKER__MACRO_END_rbi_oneTimeAnswerd_g;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_smearingreduct_upDown_Enabled;
(((EEPROM_Struct_AD . EEPROMStructAD . PrametersStruct[((EEPROM_Struct_PD . EEPROMStructPD . EEKodierbyte1_g & 12)>>2)]. SchlierenFlag1)&0x20)> 0)
typedef int VECTORCAST_MARKER__MACRO_END_rbi_smearingreduct_upDown_Enabled;

typedef int VECTORCAST_MARKER__MACRO_START_rbi_speedWasAbove10kmh_g;
uF_GainAdjustFlags_g . Bit . B1
typedef int VECTORCAST_MARKER__MACRO_END_rbi_speedWasAbove10kmh_g;

typedef int VECTORCAST_MARKER__MACRO_START_rub_TropfenMerkerOffsettShift_g;
(((EEPROM_Struct_AD . EEPROMStructAD . PrametersStruct[((EEPROM_Struct_PD . EEPROMStructPD . EEKodierbyte1_g & 12)>>2)]. RSEmpfFactorScaling&0x70)>>4)+1)
typedef int VECTORCAST_MARKER__MACRO_END_rub_TropfenMerkerOffsettShift_g;

typedef int VECTORCAST_MARKER__MACRO_START_rw_A_Factor_ALS1_g;
EEPROM_Struct_PD . EEPROMStructPD . A_Factor_ALS1_g
typedef int VECTORCAST_MARKER__MACRO_END_rw_A_Factor_ALS1_g;

typedef int VECTORCAST_MARKER__MACRO_START_rw_A_Factor_ALS2_g;
EEPROM_Struct_PD . EEPROMStructPD . A_Factor_ALS2_g
typedef int VECTORCAST_MARKER__MACRO_END_rw_A_Factor_ALS2_g;

typedef int VECTORCAST_MARKER__MACRO_START_rw_A_Factor_ALS3_g;
EEPROM_Struct_PD . EEPROMStructPD . A_Factor_ALS3_g
typedef int VECTORCAST_MARKER__MACRO_END_rw_A_Factor_ALS3_g;

typedef int VECTORCAST_MARKER__MACRO_START_rw_A_Factor_ALS4_g;
EEPROM_Struct_PD . EEPROMStructPD . A_Factor_ALS4_g
typedef int VECTORCAST_MARKER__MACRO_END_rw_A_Factor_ALS4_g;

typedef int VECTORCAST_MARKER__MACRO_START_rw_A_Factor_ALS5_g;
EEPROM_Struct_PD . EEPROMStructPD . A_Factor_ALS5_g
typedef int VECTORCAST_MARKER__MACRO_END_rw_A_Factor_ALS5_g;

typedef int VECTORCAST_MARKER__MACRO_START_rw_A_Factor_ALS6_g;
EEPROM_Struct_PD . EEPROMStructPD . A_Factor_ALS6_g
typedef int VECTORCAST_MARKER__MACRO_END_rw_A_Factor_ALS6_g;

typedef int VECTORCAST_MARKER__MACRO_START_rw_A_Factor_INREC_g;
EEPROM_Struct_PD . EEPROMStructPD . A_Factor_INREC_g
typedef int VECTORCAST_MARKER__MACRO_END_rw_A_Factor_INREC_g;

typedef int VECTORCAST_MARKER__MACRO_START_rw_AmbLightMeanFast_g;
(rw_AmbLightMul32MeanFast_g >> 5)
typedef int VECTORCAST_MARKER__MACRO_END_rw_AmbLightMeanFast_g;

typedef int VECTORCAST_MARKER__MACRO_START_rw_AmbLightMeanSlow_g;
(rw_AmbLightMul32MeanSlow_g >> 5)
typedef int VECTORCAST_MARKER__MACRO_END_rw_AmbLightMeanSlow_g;

typedef int VECTORCAST_MARKER__MACRO_START_rw_DarkToTwilightThreshAMB_g;
((unsigned int)(EEPROM_Struct_AD . EEPROMStructAD . darkToTwilightThreshAMB * 3))
typedef int VECTORCAST_MARKER__MACRO_END_rw_DarkToTwilightThreshAMB_g;

typedef int VECTORCAST_MARKER__MACRO_START_rw_DarkToTwilightThreshFW_g;
((unsigned int)(EEPROM_Struct_AD . EEPROMStructAD . darkToTwilightThreshFW * 3))
typedef int VECTORCAST_MARKER__MACRO_END_rw_DarkToTwilightThreshFW_g;

typedef int VECTORCAST_MARKER__MACRO_START_rw_DarkToTwilightTime_g;
((unsigned int)(EEPROM_Struct_AD . EEPROMStructAD . darkToTwilightTime * 20))
typedef int VECTORCAST_MARKER__MACRO_END_rw_DarkToTwilightTime_g;

typedef int VECTORCAST_MARKER__MACRO_START_rw_FunctionID_g;
EEPROM_Struct_PD . EEPROMStructPD . FunctionID_g
typedef int VECTORCAST_MARKER__MACRO_END_rw_FunctionID_g;

typedef int VECTORCAST_MARKER__MACRO_START_rw_FwLightMeanSlow_g;
(rw_FwLightMul64MeanSlow_g >> 6)
typedef int VECTORCAST_MARKER__MACRO_END_rw_FwLightMeanSlow_g;

typedef int VECTORCAST_MARKER__MACRO_START_rw_HUD_MAX_Value_g;
EEPROM_Struct_PD . EEPROMStructPD . HUD_MAX_Value
typedef int VECTORCAST_MARKER__MACRO_END_rw_HUD_MAX_Value_g;

typedef int VECTORCAST_MARKER__MACRO_START_rw_INTV10bit_g;
(unsigned int)((ras_ASIC_CtrReg_g[0x14]. val<<2) + (ras_ASIC_CtrReg_g[0x15]. val>>6))
typedef int VECTORCAST_MARKER__MACRO_END_rw_INTV10bit_g;

typedef int VECTORCAST_MARKER__MACRO_START_rw_REGV_Voltage_g;
((unsigned int)(ras_ASIC_CtrReg_g[0xD]. val<<4) + (ras_ASIC_CtrReg_g[0xE]. val>>4))
typedef int VECTORCAST_MARKER__MACRO_END_rw_REGV_Voltage_g;

typedef int VECTORCAST_MARKER__MACRO_START_rw_St2_OG_g;
(((unsigned int)(EEPROM_Struct_AD . EEPROMStructAD . PrametersStruct[((EEPROM_Struct_PD . EEPROMStructPD . EEKodierbyte1_g & 12)>>2)]. Schwelle_Schwall))<<6)
typedef int VECTORCAST_MARKER__MACRO_END_rw_St2_OG_g;

typedef int VECTORCAST_MARKER__MACRO_START_rw_TimeToReachFastHighwayMode_g;
((((unsigned int)(((EEPROM_Struct_AD . EEPROMStructAD . p_t_autobahn_delay_on_g)&0x1F)*1)+1)*20))
typedef int VECTORCAST_MARKER__MACRO_END_rw_TimeToReachFastHighwayMode_g;

typedef int VECTORCAST_MARKER__MACRO_START_rw_TimeToReachNormalSpeedMode_g;
((((unsigned int)(((EEPROM_Struct_AD . EEPROMStructAD . Frontwaschen_Autobahndelay_g)&0x0F)*10)+50)*20))
typedef int VECTORCAST_MARKER__MACRO_END_rw_TimeToReachNormalSpeedMode_g;

typedef int VECTORCAST_MARKER__MACRO_START_rw_TwilightToDarkThreshAMB_g;
((unsigned int)(EEPROM_Struct_AD . EEPROMStructAD . twilightToDarkThreshAMB * 3))
typedef int VECTORCAST_MARKER__MACRO_END_rw_TwilightToDarkThreshAMB_g;

typedef int VECTORCAST_MARKER__MACRO_START_rw_TwilightToDarkThreshFW_g;
((unsigned int)(EEPROM_Struct_AD . EEPROMStructAD . twilightToDarkThreshFW * 3))
typedef int VECTORCAST_MARKER__MACRO_END_rw_TwilightToDarkThreshFW_g;

typedef int VECTORCAST_MARKER__MACRO_START_rw_TwilightToDarkTime_g;
((unsigned int)(EEPROM_Struct_AD . EEPROMStructAD . twilightToDarkTime * 40))
typedef int VECTORCAST_MARKER__MACRO_END_rw_TwilightToDarkTime_g;

typedef int VECTORCAST_MARKER__MACRO_START_rw_VDDA_ASIC_g;
ras_ASIC_MUX_MeasAD_g[7]. avg
typedef int VECTORCAST_MARKER__MACRO_END_rw_VDDA_ASIC_g;

typedef int VECTORCAST_MARKER__MACRO_START_rw_VDDD_ASIC_g;
ras_ASIC_MUX_MeasAD_g[8]. avg
typedef int VECTORCAST_MARKER__MACRO_END_rw_VDDD_ASIC_g;

typedef int VECTORCAST_MARKER__MACRO_START_rw_VIrefHi_ASIC_g;
ras_ASIC_MUX_MeasAD_g[6]. avg
typedef int VECTORCAST_MARKER__MACRO_END_rw_VIrefHi_ASIC_g;

typedef int VECTORCAST_MARKER__MACRO_START_rw_VIrefLo_ASIC_g;
ras_ASIC_MUX_MeasAD_g[5]. avg
typedef int VECTORCAST_MARKER__MACRO_END_rw_VIrefLo_ASIC_g;

typedef int VECTORCAST_MARKER__MACRO_START_rw_VLEDA_ASIC_g;
ras_ASIC_MUX_MeasAD_g[1]. avg
typedef int VECTORCAST_MARKER__MACRO_END_rw_VLEDA_ASIC_g;

typedef int VECTORCAST_MARKER__MACRO_START_rw_VLEDB_ASIC_g;
ras_ASIC_MUX_MeasAD_g[2]. avg
typedef int VECTORCAST_MARKER__MACRO_END_rw_VLEDB_ASIC_g;

typedef int VECTORCAST_MARKER__MACRO_START_rw_VRSI_ASIC_g;
ras_ASIC_MUX_MeasAD_g[0]. avg
typedef int VECTORCAST_MARKER__MACRO_END_rw_VRSI_ASIC_g;

typedef int VECTORCAST_MARKER__MACRO_START_rw_VTEMP_ASIC_g;
ras_ASIC_MUX_MeasAD_g[3]. avg
typedef int VECTORCAST_MARKER__MACRO_END_rw_VTEMP_ASIC_g;

typedef int VECTORCAST_MARKER__MACRO_START_rw_Vref_ASIC_g;
ras_ASIC_MUX_MeasAD_g[4]. avg
typedef int VECTORCAST_MARKER__MACRO_END_rw_Vref_ASIC_g;

typedef int VECTORCAST_MARKER__MACRO_START_rw_a_Correction_Inamb1_g;
0xFF
typedef int VECTORCAST_MARKER__MACRO_END_rw_a_Correction_Inamb1_g;

typedef int VECTORCAST_MARKER__MACRO_START_rw_a_Correction_Inamb2_g;
0xFF
typedef int VECTORCAST_MARKER__MACRO_END_rw_a_Correction_Inamb2_g;

typedef int VECTORCAST_MARKER__MACRO_START_rw_a_Correction_Inrec_g;
0xFF
typedef int VECTORCAST_MARKER__MACRO_END_rw_a_Correction_Inrec_g;

typedef int VECTORCAST_MARKER__MACRO_START_rw_p_t_frontwaschen_Ausblend_g;
((((unsigned int)(((EEPROM_Struct_AD . EEPROMStructAD . Frontwaschen_Autobahndelay_g>>4)&0x0F))*1)+10)*20)
typedef int VECTORCAST_MARKER__MACRO_END_rw_p_t_frontwaschen_Ausblend_g;
#line 4 "vcast_preprocess.13636.13.c"

typedef int VECTORCAST_MARKER__PREPROCESS_END;
