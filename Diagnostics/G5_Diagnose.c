/*************************************************************************

Company : Valeo Switches and Detection Systems

Project : RLT Sensor, RDN Sensor

Component : Diagnose .c

Documentation reference   : Software Requrement Specification
Overview of the component : This Module includes the coustomer specific
diagnostic services

Evolution of the component : see PVCS Version control system
*************************************************************************/
/******************************************************************************/
/* History                                                                    */
/*----------------------------------------------------------------------------*/
/* Date      VDR_Number Initials    Description                                       */
/* DD.MM.YY */
/*----------------------------------------------------------------------------*/
/* 18.7.2011 VDR_683   AL   correct consts for Audi Konzernsensor output */
/* 7.03.2011 VCO093 / VCO05 AL  add additional data to be read out for R&D*/
/* 15.Mar11  VSC_4    FS    Implement compiler defines project related, also QAC-defines*/
/* 12.02.10  VDR_584  PCG   negative answer when  not A-Pillar Parkposition and partnumberswitch is = 0
Write code 00 00 00  is possible*/
/* 23.11.10  VDR_604  AL    better filtering for FS-Identifiers*/
/* 18.11.10  VCO_086  AL    implement FS-Services for Diagnostics*/
/* 29.10.10 VDR_590    JS       Send additional length of every step response*/
/* 25.Oct10  VCO_76     FS       Debounced Variable rub_EmpfFaktor_Debounced*/
/* 15.07.10  VCO_061     AL      provide variables to debug*/
/* 26.05.10  VCO_055     AL      reomve debouncing of RAM and ROM error*/
/* 05.05.10  VDR_505        rework function for flexible usage */
/*03.05.10   VDR_511_7 AL   Polyspace improvements*/
/*28.05.10   VDR_508  AL    negative answer for wrong message lenght*/
/* 19.03.10  VDR_471  FS    Just to have this file in the project*/
/* 18.03.10  VDR_468  AL    limit was forgotten*/
/* 11.03.10  VCO_31   AL    new Service IDs"*/
/* 10.03.10  VCO_30   AL    Negative responses for Service 0x22 and 0x2E*/
/* 24.02.10  VCO_31   AL    New Services for Anpassung und Messwerte lesen*/
/* 23.02.10  VDR_449  FS    Update Service 0x2E that Transmission Values*/
/* 12.01.10  VCO_22   AL    New Definition of coding values for Audi Konzernsensor*/
/* 29.09.09  VDR_376  AL    new version for AUDI Konzernsensor      */
/* 02.07.09  VDR_345  AL    HT-Function and partnumber configurable in EEPROM */
/* 04.02.08  VDR_129        VDR_129 use Sensitivity Treatment*/
/* 26.06.08  VCO_08   AL    Add RAM Values for FAW Twilight detection*/
/* 15.08.08  VDR_233        FS Rework diagnostic*/
/* 18.08.08  VDR_261        Rework of NAD Assignment --> Write immediately in
EEPROM after NAD Assignment Request*/
/* 04.09.08  VCO_11         Implementation of negative response on service ECU Reset */
/* 09.09.08  RLS_VDR_267  AL RLS_OPEL_MERIVA: Read DTC with Status Mask: Status Mask not correct  */
/* 09.09.08  RLS_VDR_268  AL RLS_OPEL_MERIVA (J2602): NRC for Service 0x22 not correct */
/* 30.09.08  VDR_271  FS    Broadcast Reset Request forces the RLSpollDiagnostic
to set, correct is to not set this bit, because the sensor can not answer this request */
/* 09.10.08  VDR 262  AL    Reset Status bit for EEPROM written before writting
of new NAD or Message ID*/
/* 20.10.08   VCO_12  AL    SW-Partnumber index*/
/****************************************************************************************************************/
/****************************************************************************************************************/
/* 22.09.14     VCO_152 NB      Customenr part number shall be stored in EEPROM                                 */
/* 29.09.14     VCO_172 NB      AUDI_Coding of Parkposition on LIN                                              */
/*27.11.14      VDR_825 MP      Diagnostic pulse - change the wait time                                         */
/*28.11.14      VCO_200 NB      Adapt include structure to suit different project                               */
/*09.12.14      VCO_205 NB      Read serieal number of SHT module                                               */
/*29.01.15      VC0_213 MP      Pulse counter sent also at addr 157 to be read together with length counter     */
/********************************(for Rain sensor sensitivity test)                                             */
/*16.02.15      VDR_846 MP      Negative response for diag pulse, instead of pending, when RS is off            */
/*16.02.15      VDR_847 MP      rb_ASICGainSetup_g send with the diag pulse command                             */
/*25.02.15      VCO_223 MP      Block activation of Standby mode in RS kodierbyte0,                             */
/********************************if RS function is inactive in RSControlflag                                    */
/*03.03.15      VCO_227 NB      Implement RAM Guard function                                                    */
/* 10.03.15     VDR_854 NB      QAC and polyspace findings                                                      */
/* 20.03.15     VCO_215 NB      All: Project specific extensions in the main stream Release 8                   */
/* 09.04.15     VCO_242 NB      Remove length check of cb_REQLENGTHSID22_Multi_s for service 22                 */
/*14.04.15      VCO_243 NB      Implement Function ID and Variant ID in the EEPROM PD section                   */
/*21.05.15      VCO_253 MP      Measurement of optical coupling at start up                                     */
/*10.06.15      VCO_254 NB      Checking of CRC over light area shall be done cyclically                        */
/*29.06.15      VCO_256 NB      Introduce systembezeichnung G397_RLSS and set invalid as default                */
/*13.07.15      VDR_868 NB      QAC and Polyspace fixing for SW009 Release                                      */
/*13.07.15      VDR_891 MP      SWITS_635: SPI communication error not set when the ASIC mode is corrupted      */
/*                              only once per cycle                                                             */
/*06.08.15      VCO_264 NB      Implement common part in diagnostic file                                        */
/*09.11.15   VCO_282    NB    All:Add spare LIN IDs in the EEPROM             */
/*19.11.15   VDR_929    SP    Diagnostic Service 0x151A: Parameter Read Rainsensor Off - Not correct            */
/*03.12.15    VDR_939         NB      Improvement of SHT module measurement                                     */ 
/*25.02.16    VCO_313         NB      Create new variant Feuchte_Solar and Rain_Light_solar for SEAT            */ 
/*20.01.17    VDR_1009        NB      Ford:Single/Double Overwipe and Butterfly system                          */ 
/* 07.12.17     VCO_462    HB    FIAT 330 interfaces: parallel branch                                           */
/****************************************************************************************************************/

/* PRQA S 0434,0436,0781,4130 EOF */ /* << 0434,0436 usage of SFR >> */
/* PRQA S 3138 EOF */ /* << using of macros from automatic generated code >>*/
/* PRQA S 3116 EOF *//*<< 3116:#pragma needed for IAR compiler and MISRA >>*/
/* PRQA S 1015 EOF *//*<< 1015:__far needed for IAR compiler  >>*/
/* PRQA S 5540,5560,5565,5900 EOF *//*<< Data needs to be verified  >>*/
/* PRQA S 2201,2215,2217,715 EOF *//*<< Indentation and line length  >>*/
/* PRQA S 750,759 EOF *//*<< 0750:union needed to reduce RAM usage >>*/
/* PRQA S 841 EOF *//*<< 841:use of #undef needed  >>*/
/* PRQA S 857 EOF *//*<< Macro exceeds 1024 number  >>*/
/*****************************************************************************************************************
**                   Common and module include-file                     **
*****************************************************************************************************************/

#include "ior5f109be.h"
#include "ior5f109be_ext.h"
#include "G5_projectDefs.h"
#define _DIAGNOSE_c_          //Define for Single include of Global Header G5_diagnose.h
#include "G5_rs_def.h"
#include "G5_IRlight.h"
#include "G5_DippedBeam_sr.h"
#include "G5_lininclude.h"
#include "G5_E2ProjectConfig.h"
#include "G5_diagnose.h"
#undef  _DIAGNOSE_c_

#include "G5_rainsens.h"
#include "G5_flashe2.h"
#include "G5_E2Handler.h"

#undef LIN_INC_H

/*************************************************************************
**                   Other files included                               **
**************************************************************************/

#include "G5_ASIC_Control.h"
#include "G5_ASIC_Control_sr.h"
#include "G5_Appli_main.h"
#include "G5_io.h"
#include "G5_Check_sr.h"
#include "G5_spi_sr.h"
#include "G5_Appli_timer.h"

#include "G5_HumTemp.h"


#define NODE_STRUCTURES 1

static const byte __far*pb_Systembezeichnung_mg;

static void SetSystemBezeichnung(void);

/******************************************************************************/
/*                   Definition of local symbolic constants                   */
/******************************************************************************/
#define cb_NUMBER_OF_MW_BLOCKS_s 32
#define cb_ASCI_Blank_s                 0x20
#define cb_TEST_HARDWARE_s  cb_ASCI_Blank_s // 0x2a for Development hardware
#define cw_SupplierIDWildcard_g     0x7FFFU
#define cw_FunctionIDWildcard_g     0xFFFFU
#define cb_TA_WILDCARD_s            0x7F
#define cb_RDBLID_FORMEL_g      0x87
#define cb_RDBLID_NORMIERWERT_g 1

#define cb_READ_ECU_IDENT_REQ_s         0x1A
#define cb_IDENT_OPT_EXT_SGIDENT_S      0x86
#define cb_IDENT_OPT_SGIDENT_s          0x9B
#define cb_IDENT_OPT_AUDI_PARTNUMBER_S  0x91
#define cb_WRITEDATABYIDENTIFIER_s      0x2E
#define cb_WRITE_DATA_BY_LOCAL_IDENT_s  0x3B
#define cb_WRITE_DATA_POSITIVE_s        0x7B
#define cb_NEW_CONFIGURATION_s          0x9A
#define cb_POSITIVE_IDENT_RESPONSE_s    0x5A
#define cb_NEGATIVE_RESPONSE_s          0x7F
#define cb_CAN_NOT_UPLOAD_TO_ADDRESS_s  0x42
#define cb_IMPROPER_UPLOAD_TYPE         0x41
#define cb_TOMUCHUPLOADBYTES_s          0x43

#define cb_REQUEST_DOWNLOAD_RESPONSE_s  0x74
#define cb_REQUEST_NEGATIVE_DOWNLOAD_RESPONSE_s 0x7F
#define cb_ANSWER_UPLOAD_RESPONSE_s        0x75
#define cb_ANSWER_TRANSMISSION_s        0x76
#define cb_ILLEGALBLOCKTRANSFERTYPE_s   0x76

#define cb_WRITE_DATA_BY_LOC_ID_s       0x3B
#define cb_READ_DATA_BY_LOCAL_IDENT_s   0x21
#define cb_READDATABYIDENTIFIER_s       0x22

#define cb_READ_MEMORY_BY_ADDRESS_s     0x23
#define cb_RMBA_POSRESPONSE_s           0x63
#define cb_WRITE_MEMORY_BY_ADDRESS_s    0x3D
#define cb_READDTC_s                    0x19
#define cb_CLRDTC_s                     0x14

#define cb_LINASSIGNNAD_s               0xB0
#define cb_LINASSIGNIDENTIFIER_s        0xB1
#define cb_LINREADBYIDENTIFIER_s        0xB2
#define cb_LINCONDCHANGENAD_s           0xB3
#define cb_LINDATADUMP_s                0xB4
#define cb_LINECURST_s                  0xB5  /*VCO_11 Implementation of negative response on service ECU Reset*/

#ifdef NL_5
#define cb_LINDATADUMP_WRITE            0x01
#define cb_LINDATADUMP_READ             0x02
#endif
#if (defined FERRARI) || (defined GEN3_5A_FCA) || (defined FIAT_330)
#define cb_LINECUINFO_s                 0xC0   /*  Diag Service C0 for Chrysler PF*/
#define cb_LINPARTNUMBER1TO6_s          0xC7   /*  Diag Service C7 for Chrysler PF*/
#define cb_LINPARTNUMBER7TO10_s         0xC8   /*  Diag Service C8 for Chrysler PF*/ 
#define cb_REQLENGTHSIDC0_s                6   
#define cb_REQLENGTHSIDC7_s                6   
#define cb_REQLENGTHSIDC8_s                6 
#endif

#define CB_SID_NO_ANSWER_s              0xC0

#define cb_END_OF_TABLE_s               0xff

#define cb_SINGLE_FRAME_s               0x00
#define cb_FIRST_FRAME_s                0x10
#define cb_CONSECUTIVE_FRAME_s          0x20

#define cb_CODIERTABELLE_s              0x22

// Negative Responsens
#define cb_SERVICE_NOT_SUPPORTED_s     0x11
#define cb_SUBFUNCTION_NOT_SUPPORTED_s 0x12
#define cb_REQUEST_OUT_OF_RANGE_s      0x31
#define cb_CONDITION_NOT_CORRECT_s     0x22
#define cb_RESPONSE_PENDING            0x78
#define cb_INCORECTMESSAGELENGTH_s     0x13 /* OPEL4400 */
#define cb_TRANSFER_DATA_SUSPENDED     0x71
//EEPROM ADDRESS
#define cw_DIAGNOSEPULSEADRESS 0xffffU
#define cw_DIAGNOSEHEATERADR   0x5134U
#define cw_DIAGNOSERAINADR     0x0F0FU



#ifdef _SUPPORTSERVICE1A_
#define cb_REQLENGTHSID1A_s   2
#endif

#ifdef _SUPPORTSERVICE21_
#define cb_REQLENGTHSID21_s   2
#endif

#ifdef _SUPPORTSERVICE22_
#define cb_REQLENGTHSID22_s   3
#endif
/*************************************************************************
**                   Declaration of local module variables              **
*************************************************************************/
typedef struct 
{
  byte Id;
  byte SystemName[16];
}Systembezeichnung_t;

#ifdef _SUPPORTMWLLIGHT_
static  word rw_MemReadAddress_mg;
#endif

//--- Offsett and slope factor corrected values
static  word rw_DiagnoseEEPROM_Address_mg;     //Address of EEPROM to write or Read
#define cb_MAXRESPONSELENGTH_mg 30  /*VCO_31 increse size of sending buffer*/

#if (defined (HAITEC) || defined(FOTON_S700))
#define cb_SW_PART_NUMBER_LENGTH_mg 10
#elif defined (BAICYX_G20)
#define cb_SW_PART_NUMBER_LENGTH_mg 12
#elif defined (GEELY2DOT0)
#define cb_SW_PART_NUMBER_LENGTH_mg 13
#else
#define cb_SW_PART_NUMBER_LENGTH_mg 11
#endif
static  byte rab_DiagRespBuffer_mg[cb_MAXRESPONSELENGTH_mg];

static byte rb_I2CEEPROMCMDbytesToWrite_g;
/*************************************************************************
**                   Declaration of local module Functions              **
*************************************************************************/
static __callt byte Diagnose_TP(void);
static __callt void Diagnose_Send_EEPROM(void);
static __callt  byte Diagnose_GetEEPROMValue(word rw_VariableToSend_l);   //Reads Value from EEPROM Or RAM
static __callt  void Diagnose_clear_Answer_Message(void); //clears buffer sinc byte 4

#ifndef BRILLIANCE_M8X
static void getSwPartNumberAscii(byte * result);
#endif

static void Diagnose_NegativeResponse(byte rb_requ_ID_l,byte rb_DataLinkLayer_l);

static void Diagnose_Answer_Download(void);
static void Diagnose_Recieve_Transfer_Data(void);

#ifdef NODECONFIGURATION
static byte Diagnose_FillAnswerRBI(pbyte rab_Buffer_l,byte rb_ID_l);
#endif
static byte Diagnose_CheckE2_DownloadBytes(void);

static __callt byte Diagnose_TP(void)
{
  static byte rb_SendBuffPos_s;
  byte rb_BytesToSend_l;
  
  l_u8_wr_SlaveRespB0(l_u8_rd_MasterReqB0());
  Diagnose_clear_Answer_Message();
  
  if (rb_ResponseToSend_g == 0)   // a response to send?
  {
    rb_BytesToSend_l = 0;   // nothing to send
    l_u8_rd_MasterReqB0() = cb_OTHER_TARGET_ADDRESS_s;   // change to invalid TA
  }
  else if (rab_DiagRespBuffer_mg[0] < 7)   // fit in single frame?
  {
    l_u8_wr_SlaveRespB1(cb_SINGLE_FRAME_s|rab_DiagRespBuffer_mg[0]);    // Single frame and msg length
    // fill response buffer
    switch (rab_DiagRespBuffer_mg[0])
    {
    case 6:  l_u8_wr_SlaveRespB7(rab_DiagRespBuffer_mg[6]); /* fallthrough */
    case 5:  l_u8_wr_SlaveRespB6(rab_DiagRespBuffer_mg[5]); /* fallthrough */
    case 4:  l_u8_wr_SlaveRespB5(rab_DiagRespBuffer_mg[4]); /* fallthrough */
    case 3:  l_u8_wr_SlaveRespB4(rab_DiagRespBuffer_mg[3]); /* fallthrough */
    case 2:  l_u8_wr_SlaveRespB3(rab_DiagRespBuffer_mg[2]); /* fallthrough */
    default: l_u8_wr_SlaveRespB2(rab_DiagRespBuffer_mg[1]); /* fallthrough */
    break;
    }
    rb_BytesToSend_l = 8;
    rb_ResponseToSend_g--;
  }
  else if (rb_Diagnosticstate_g == 0) // send first frame?
  {
    {
      l_u8_wr_SlaveRespB1(cb_FIRST_FRAME_s);    // First Frame
      l_u8_wr_SlaveRespB2(rab_DiagRespBuffer_mg[0]);    // msg length
    }
    l_u8_wr_SlaveRespB3(rab_DiagRespBuffer_mg[1]);
    l_u8_wr_SlaveRespB4(rab_DiagRespBuffer_mg[2]);
    l_u8_wr_SlaveRespB5(rab_DiagRespBuffer_mg[3]);
    l_u8_wr_SlaveRespB6(rab_DiagRespBuffer_mg[4]);
    l_u8_wr_SlaveRespB7(rab_DiagRespBuffer_mg[5]);
    rb_SendBuffPos_s = 6;
    rb_Diagnosticstate_g ++;
    rb_BytesToSend_l = 8;
  }
  else    // send consecutive frame
  {
    l_u8_wr_SlaveRespB1(cb_CONSECUTIVE_FRAME_s | (rb_Diagnosticstate_g & 0x0F));// Consecutive Frame and sequence number
    
    if (rb_SendBuffPos_s > rab_DiagRespBuffer_mg[0])
    {
      rb_BytesToSend_l = 0;
    }
    else if ((rab_DiagRespBuffer_mg[0] - rb_SendBuffPos_s) > 5)
    {
      rb_BytesToSend_l = 6;
    }
    else
    {
      rb_BytesToSend_l = (rab_DiagRespBuffer_mg[0] - rb_SendBuffPos_s)+1;
    }
    
    switch (rb_BytesToSend_l)
    {
    case 6:  l_u8_wr_SlaveRespB7(rab_DiagRespBuffer_mg[rb_SendBuffPos_s+5]); /* fallthrough */
    case 5:  l_u8_wr_SlaveRespB6(rab_DiagRespBuffer_mg[rb_SendBuffPos_s+4]); /* fallthrough */
    case 4:  l_u8_wr_SlaveRespB5(rab_DiagRespBuffer_mg[rb_SendBuffPos_s+3]); /* fallthrough */
    case 3:  l_u8_wr_SlaveRespB4(rab_DiagRespBuffer_mg[rb_SendBuffPos_s+2]); /* fallthrough */
    case 2:  l_u8_wr_SlaveRespB3(rab_DiagRespBuffer_mg[rb_SendBuffPos_s+1]); /* fallthrough */
    default: l_u8_wr_SlaveRespB2(rab_DiagRespBuffer_mg[rb_SendBuffPos_s]); /* fallthrough */
    break;
    }
    if (rb_Diagnosticstate_g < 0xFF)    // No Overflow?
    {
      rb_Diagnosticstate_g ++;    // increase Diagnostic State
    }
    else
    {
      rb_Diagnosticstate_g = 1;   // set to 0 on overflow to avoid sending first frame again
    }
    rb_SendBuffPos_s += rb_BytesToSend_l;
    
    if (rb_SendBuffPos_s > rab_DiagRespBuffer_mg[0])
    {
      rb_ResponseToSend_g = 0;
    }
  }
  return (rb_BytesToSend_l > 0);
}

void ApplLinMasterReqFrmFct(void)
{
  static word rw_MessagesToWait_mg;
#ifdef RLFS_TO_FS_ENBLED /*RLS_VCO_086 implement FS-Services for Diagnostics*/
  byte rb_Requested_Service_l;
#endif

  rbi_ConnectedToMaster_g = 1;                 // set connected to Master Bit
  rb_Diagnosticstate_g = 0;               // Reset Diagnostic State
  
  if(((l_u8_rd_MasterReqB0()== cb_TARGET_ADDRESS_s)       //Check for own target address
#ifdef NODECONFIGURATION
      || ((l_u8_rd_MasterReqB2() >= cb_LINASSIGNNAD_s) && (l_u8_rd_MasterReqB2() <= cb_LINDATADUMP_s))
#endif
          || (l_u8_rd_MasterReqB0() == cb_TA_DEVELOPEMENT_s)))
  {
    if  (l_u8_rd_MasterReqB1() <= 0x06)                  //check the lenght of the message and the frame type SF
    {
#ifdef RLFS_TO_FS_ENBLED /*RLS_VCO_086 implement FS-Services for Diagnostics*/
      rb_Requested_Service_l = l_u8_rd_MasterReqB2();
      if (rbi_RLFS_is_FS_g == TRUE) // check for unsoported IDs by FS-Version
      {
        if ((l_u8_rd_MasterReqB2() < 0x30)&& (l_u8_rd_MasterReqB2()!=0x22))
        {
          rb_Requested_Service_l = 0x00; // set to undefined ID
        }
      }
      switch(rb_Requested_Service_l)
#else
        switch(l_u8_rd_MasterReqB2())
#endif
        {
        case cb_REQUEST_UPLOAD_s:               //lesen des Speichers
          if(l_u8_rd_MasterReqB0() == cb_TA_DEVELOPEMENT_s)     // service nur uber Entwickleradresse verfugbar
          {
            if (l_u8_rd_MasterReqB1() == cb_REQLENGTHSID35_s)
            {
              Diagnose_Answer_Download();
              rbi_DiagnoseWriteEEPROM_g = FALSE;
              rbi_DiagnoseReadEEPROM_g = TRUE;
            }
            else
            {
              
              Diagnose_NegativeResponse(cb_REQUEST_UPLOAD_s,cb_INCORECTMESSAGELENGTH_s);
              
            }
            
          }
          else
          {
            Diagnose_NegativeResponse(cb_REQUEST_UPLOAD_s,cb_SERVICE_NOT_SUPPORTED_s);
          }
          break;
        case cb_REQUEST_DOWNLOAD_s:               //Programieren Memory
          if(l_u8_rd_MasterReqB0() == cb_TA_DEVELOPEMENT_s)     // service nur uber Entwickleradresse verfugbar
          {
            if (l_u8_rd_MasterReqB1() == cb_REQLENGTHSID34_s)
              
            {
              Diagnose_Answer_Download();
              rbi_DiagnoseWriteEEPROM_g = TRUE;
              rbi_DiagnoseReadEEPROM_g = FALSE;
            }
            else
            {
              
              Diagnose_NegativeResponse(cb_REQUEST_DOWNLOAD_s,cb_INCORECTMESSAGELENGTH_s);
              
            }
            
          }
          else
          {
            Diagnose_NegativeResponse(cb_REQUEST_DOWNLOAD_s,cb_SERVICE_NOT_SUPPORTED_s);
          }
          break;
        case cb_TRANSFER_DATA_REQUEST_s:        //Program Memory
          if(l_u8_rd_MasterReqB0() == cb_TA_DEVELOPEMENT_s)     // service nur uber Entwickleradresse verfugbar
          {
            if(rbi_DiagnoseWriteEEPROM_g == TRUE)
            {
              Diagnose_Recieve_Transfer_Data();  // Programmieren
            }
            else
              if(rbi_DiagnoseReadEEPROM_g != TRUE)
              {
                //cb_REQUEST_OUT_OF_RANGE_s
                Diagnose_NegativeResponse(cb_TRANSFER_DATA_REQUEST_s,cb_ILLEGALBLOCKTRANSFERTYPE_s);
              }
              else {} /*Misra Rule 14.10*/
          }
          else
          {
            Diagnose_NegativeResponse(cb_TRANSFER_DATA_REQUEST_s,cb_SERVICE_NOT_SUPPORTED_s);
          }
          break;
#ifdef _SUPPORTSERVICE21_
        case cb_READ_DATA_BY_LOCAL_IDENT_s:     //Read out internal Datas
          Diagnose_ReadDataByLocalID();
          break;
#endif
#ifdef _SUPPORTSERVICE22_
        case cb_READDATABYIDENTIFIER_s:
          Diagnose_ReadDataByIdentifier();
          break;
#endif
#ifdef _SUPPORTCODING3B_
        case cb_WRITE_DATA_BY_LOCAL_IDENT_s:    //Programming off EEPROM Coding info
          Diagnose_Write_Codierinfo();
          rbi_DiagnoseWriteEEPROM_g = FALSE;
          rbi_DiagnoseReadEEPROM_g = FALSE;
          break;
#endif
#ifdef _SUPPORTCODING2E_
        case cb_WRITEDATABYIDENTIFIER_s:      //Programming off EEPROM Coding info
          Diagnose_Write_CodierinfoB8();
          rbi_DiagnoseWriteEEPROM_g = FALSE;
          rbi_DiagnoseReadEEPROM_g = FALSE;
          break;
#endif
          
#ifdef _SUPPORTSERVICE23_
        case cb_READ_MEMORY_BY_ADDRESS_s:   /*VDR_233 Rework Diagnostic  */// Read Memory by Address (OPEL4400)
          Diagnose_ReadMemoryByAddress();
          break;
#endif
          
#ifdef _SUPPORTSERVICE3D_
        case cb_WRITE_MEMORY_BY_ADDRESS_s:   /*VDR_233 Rework Diagnostic */ // Write Memory by Address (OPEL4400)
          Diagnose_WriteMemoryByAddress();
          break;
#endif
          
#ifdef _SUPPORTSERVICE19_
        case cb_READDTC_s:  // Read DTC (OPEL4400)
          Diagnose_ReadDTC();
          break;
#endif
          
#ifdef _SUPPORTSERVICE14_
        case cb_CLRDTC_s:   // Clear DTC (OPEL4400)
          Diagnose_ClearDTC();
          break;
#endif
#ifdef _SUPPORTJ2602ECURESET_       /*VCO_11 Implementation of negative response on service ECU Reset*/
        case cb_LINECURST_s:   // Clear DTC (OPEL4400)
          if ((l_u8_rd_MasterReqB0() == cb_TARGET_ADDRESS_s) || (l_u8_rd_MasterReqB0() == cb_TA_WILDCARD_s))
          {
            Diagnose_ECUReset();
            if (l_u8_rd_MasterReqB0() == cb_TA_WILDCARD_s)
            {
              l_u8_wr_MasterReqB0(0xff);
            }
          }
          else
          {
            // send nothing
            l_u8_wr_MasterReqB0(0xff);
          }
          break;
#endif
#if (defined FERRARI) || (defined GEN3_5A_FCA) || (defined FIAT_330)
        case cb_LINECUINFO_s:          /* RLS_VCS_17 Diag Service C0 for Chrysler PF*/
          
          Diagnose_ECUInfo();
          if ((l_u8_rd_MasterReqB0() == cb_TARGET_ADDRESS_s) || (l_u8_rd_MasterReqB0() == cb_TA_WILDCARD_s))
          {
            l_u8_wr_MasterReqB0(cb_TARGET_ADDRESS_s);
          }
          else
          {  
            l_u8_wr_MasterReqB0(cb_TA_DEVELOPEMENT_s);
          }                  
          break;
          
        case cb_LINPARTNUMBER1TO6_s:        /* RLS_VCS_17 Diag Service C7 for Chrysler PF*/
          Diagnose_PartNumber1To6();
          
          if ((l_u8_rd_MasterReqB0() == cb_TARGET_ADDRESS_s) || (l_u8_rd_MasterReqB0() == cb_TA_WILDCARD_s))
          {
            l_u8_wr_MasterReqB0(cb_TARGET_ADDRESS_s);
          } 
          else
          {  
            l_u8_wr_MasterReqB0(cb_TA_DEVELOPEMENT_s);
          }                    
          break;
          
        case cb_LINPARTNUMBER7TO10_s:       /* RLS_VCS_17 Diag Service C8 for Chrysler PF*/
          Diagnose_PartNumber7To10();
          
          if ((l_u8_rd_MasterReqB0() == cb_TARGET_ADDRESS_s) || (l_u8_rd_MasterReqB0() == cb_TA_WILDCARD_s))
          {
            l_u8_wr_MasterReqB0(cb_TARGET_ADDRESS_s);
          }
          else
          {  
            l_u8_wr_MasterReqB0(cb_TA_DEVELOPEMENT_s);
          }  
          
          break;          
 
#endif          
#ifdef NODECONFIGURATION
        case cb_LINASSIGNIDENTIFIER_s:
          if ((l_u8_rd_MasterReqB0() == cb_TARGET_ADDRESS_s) || (l_u8_rd_MasterReqB0() == cb_TA_WILDCARD_s))
          {
            l_u8_wr_MasterReqB0(cb_TARGET_ADDRESS_s);
            Diagnose_AssignIdentifier();
          }
          else
          {
            // send nothing
            l_u8_wr_MasterReqB0(0xff);
          }
          break;
        case cb_LINREADBYIDENTIFIER_s:
          if ((l_u8_rd_MasterReqB0() == cb_TARGET_ADDRESS_s) || (l_u8_rd_MasterReqB0() == cb_TA_WILDCARD_s))
          {
            l_u8_wr_MasterReqB0(cb_TARGET_ADDRESS_s);
            Diagnose_ReadByIdentifier();
          }
          else
          {
            // send nothing
            l_u8_wr_MasterReqB0(0xff);
          }
          break;
#ifdef _SUPPORTASSIGNNAD_
        case cb_LINASSIGNNAD_s:
          if (l_u8_rd_MasterReqB0() == cb_INITAL_TARGET_ADDRESS_s)
          {
            Diagnose_AssignNAD();
          }
          else
          {
            // send nothing
            l_u8_wr_MasterReqB0(0xff);
          }
          break;
        case cb_LINCONDCHANGENAD_s:
          if (l_u8_rd_MasterReqB0() == cb_TARGET_ADDRESS_s)
          {
            Diagnose_AssignNAD();
          }
          else
          {
            // send nothing
            l_u8_wr_MasterReqB0(0xff);
          }
          break;
#endif /* _SUPPORTASSIGNNAD_ */
        case cb_LINDATADUMP_s:
          if (l_u8_rd_MasterReqB0() == cb_TARGET_ADDRESS_s)
          {
#ifdef NL_5
            Diagnose_LINDATADUMP();
#else
            Diagnose_NegativeResponse(l_u8_rd_MasterReqB2(),cb_SERVICE_NOT_SUPPORTED_s);       //Falsche Option     
#endif
          }
          else
          {
            // send nothing
            l_u8_wr_MasterReqB0(0xff);
          }
          break;
          
#endif /* NODECONFIGURATION */
        default:
#if (defined FERRARI) || (defined GEN3_5A_FCA) || (defined FIAT_330)
          Diagnose_NegativeResponse(l_u8_rd_MasterReqB2(),cb_SERVICE_NOT_SUPPORTED_s);     /* unsupported service */
#else          
          if (l_u8_rd_MasterReqB2()< CB_SID_NO_ANSWER_s)
          {
            
            Diagnose_NegativeResponse(l_u8_rd_MasterReqB2(),cb_SERVICE_NOT_SUPPORTED_s);     //Falsche Option
          }
          else
          {
            // send nothing
            l_u8_wr_MasterReqB0(0xff);
          }
#endif          
          break;
        }
      if (l_u8_rd_MasterReqB0()!=0xFF) /*VDR_271*/
      {
        rb_ResponseToSend_g = 1; /*VDR_271: Send minimum 1 frame*/
      }
      else
      {
        rb_ResponseToSend_g = 0; /*VDR_271: Send nothing*/
      }
    }
    else // CF Farme not supported
    {
      if ((l_u8_rd_MasterReqB1()&0xF0) == 0x10)
      {
        rw_MessagesToWait_mg = ((((l_u8_rd_MasterReqB1()&0x0F)<<8)+(l_u8_rd_MasterReqB2()))/6);
        /* send nothing but set answer!*/
        Diagnose_NegativeResponse(l_u8_rd_MasterReqB3(),cb_SERVICE_NOT_SUPPORTED_s);                  //Falsche Option
      }
      else if ((l_u8_rd_MasterReqB1() == (0x20+rw_MessagesToWait_mg)))
      {
        rb_ResponseToSend_g = 1; /*VDR_271: Send minimum 1 frame*/
      }
      else
      {
        /* send nothing*/
        l_u8_wr_MasterReqB0(0xff);
      }
    }
  }
  else // invalid frame Master-Frames not supported
  {
    // send nothing
    l_u8_wr_MasterReqB0(0xff);
  }
  
  
}

/**************************************************************************
Syntax   : void  ApplLinSlaveCmdFrmFct(void)
Object   : ApplLinSlaveCmdFrmFct()
Parameters : none
Return  : none
Calls   : in LIN_drv.c
***************************************************************************
Inputs validation conditions:
none
***************************************************************************
Pseudo-code : Organisiert die DiagnoseAntworten auf dem LIN bus
**************************************************************************/
__callt byte ApplLinSlaveCmdFrmFct(void)
{
  byte rb_ReturnValue_l;
#ifdef RLFS_TO_FS_ENBLED /*RLS_VCO_086 implement FS-Services for Diagnostics*/
  byte rb_Requested_Service_l;
#endif
  rb_ReturnValue_l = 0;                         // return Value
  rbi_ConnectedToMaster_g = 1;                 // set connected to Master Bit
  
  
  if((l_u8_rd_MasterReqB0()== cb_TARGET_ADDRESS_s)       //Check for own target address
#ifdef NODECONFIGURATION
     || (((l_u8_rd_MasterReqB2() >= cb_LINASSIGNNAD_s) 
          && (l_u8_rd_MasterReqB2() <= cb_LINDATADUMP_s)) && (l_u8_rd_MasterReqB0() != 0xff))
#endif
       || (l_u8_rd_MasterReqB0() == cb_TA_DEVELOPEMENT_s))
  {
    
#ifdef RLFS_TO_FS_ENBLED /*RLS_VCO_086 implement FS-Services for Diagnostics*/
    rb_Requested_Service_l = l_u8_rd_MasterReqB2();
    if (rbi_RLFS_is_FS_g == TRUE) // check for unsoported IDs by FS-Version
    {
      if ((l_u8_rd_MasterReqB2() < 0x30)&& (l_u8_rd_MasterReqB2()!=0x22))
      {
        rb_Requested_Service_l = 0x00; // set to undefined ID
      }
    }
    switch(rb_Requested_Service_l)
#else
      switch(l_u8_rd_MasterReqB2())
#endif
        
      {
      case cb_TRANSFER_DATA_REQUEST_s:        //Program Memory
        if(l_u8_rd_MasterReqB0() == cb_TA_DEVELOPEMENT_s)     // service nur uber Entwickleradresse verfugbar
        {
          if(rbi_DiagnoseWriteEEPROM_g == TRUE)
          {
            Diagnose_Recieve_Transfer_Data();  // Programmieren
          }
          else
            if(rbi_DiagnoseReadEEPROM_g == TRUE)
            {
              Diagnose_Send_EEPROM();
            }
            else {} /*Misra Rule 14.10*/
          
        }
        break;
#ifdef _SUPPORTSERVICE1A_
      case cb_READ_ECU_IDENT_REQ_s:                 //Read the Identification
        if(l_u8_rd_MasterReqB1() == cb_REQLENGTHSID1A_s)
          
        {
          switch(l_u8_rd_MasterReqB3()) //Option ?
          {
          case cb_IDENT_OPT_SGIDENT_s:
            rb_ReturnValue_l = Diagnose_Read_SteuergIdent(); //Steuergeratenummer
            break;
          case cb_IDENT_OPT_AUDI_PARTNUMBER_S:
            rb_ReturnValue_l = Diagnose_Read_Audi_Partnumber(); //AUDI Entwicklungs Teilenummer
            break;
          case cb_IDENT_OPT_EXT_SGIDENT_S:
            rb_ReturnValue_l = Diagnose_ReadExtECUIdent(); //extended Identification
            break;
          default:
            Diagnose_NegativeResponse(cb_WRITE_DATA_BY_LOC_ID_s,cb_SUBFUNCTION_NOT_SUPPORTED_s); //Falsche Option
            break;
          }
        }
        else
        {
          
          Diagnose_NegativeResponse(cb_WRITE_DATA_BY_LOC_ID_s,cb_INCORECTMESSAGELENGTH_s);
          
        }
        
        rbi_DiagnoseWriteEEPROM_g = FALSE;
        rbi_DiagnoseReadEEPROM_g = FALSE;
        break;
#endif
#ifdef _SUPPORTSERVICE23_ /*VDR_233 Rework Diagnostic*/
      case cb_READ_MEMORY_BY_ADDRESS_s:                 //ReadMemoryByAddress --> Opel4400
        rb_ReturnValue_l = Diagnose_ReadMemoryByAddress();
        break;
#endif
#ifdef _SUPPORTCODING3B_
      case cb_WRITE_DATA_BY_LOCAL_IDENT_s:    //Programming off EEPROM Coding info
        Diagnose_Write_Codierinfo();
        rbi_DiagnoseWriteEEPROM_g = FALSE;
        rbi_DiagnoseReadEEPROM_g = FALSE;
        break;
#endif
#ifdef _SUPPORTCODING2E_
      case cb_WRITEDATABYIDENTIFIER_s:      //Programming off EEPROM Coding info
        Diagnose_Write_CodierinfoB8();
        rbi_DiagnoseWriteEEPROM_g = FALSE;
        rbi_DiagnoseReadEEPROM_g = FALSE;
        break;
#endif
#ifdef NODECONFIGURATION
      case cb_LINASSIGNIDENTIFIER_s:
        Diagnose_AssignIdentifier();
        break;
#ifdef _SUPPORTASSIGNNAD_
      case cb_LINASSIGNNAD_s:
        Diagnose_AssignNAD();
        break;
      case cb_LINCONDCHANGENAD_s:
        Diagnose_AssignNAD();
        break;
#endif /* _SUPPORTASSIGNNAD_ */
#endif /* NODECONFIGURATION */
        
#if (defined FERRARI) || (defined GEN3_5A_FCA) || (defined FIAT_330)        

      case cb_LINECUINFO_s:          /*  Diag Service C0 for Chrysler PF*/
        Diagnose_ECUInfo();
        break;
      case cb_LINPARTNUMBER1TO6_s:   /*  Diag Service C7 for Chrysler PF*/
        Diagnose_PartNumber1To6();
        break;
      case cb_LINPARTNUMBER7TO10_s:  /*  Diag Service C8 for Chrysler PF*/
        Diagnose_PartNumber7To10();
        break;      
#endif          
      default:
        break;
      }
    
#if defined (_SUPPORTSERVICE1A_) || defined (_SUPPORTSERVICE23_) /*VDR_233 Rework Diagnostic*/
    if(rb_ReturnValue_l == 0)
#endif
    {
      rb_ReturnValue_l = Diagnose_TP();
    }
  }
  else
  {
    rb_ReturnValue_l = 0;                   // other slaves are asked
  }
  
  return(rb_ReturnValue_l);
}


byte Diagnosis_BCDtoASCII(byte rb_Input_l)
{
  byte rb_Output_l;
  if (rb_Input_l < 0x0A)
  {
    rb_Output_l = rb_Input_l + '0';
  }
  else
  {
    rb_Output_l = (rb_Input_l - 0x0A) + 'A' ;
  }
  return (rb_Output_l);
}

#if (defined(BRILLIANCE_M8X) || defined(CTCS_M31T))
static byte Diagnosis_HEXtoBCD(byte rb_Input_l)
{
  /*Take_Care:Because the Year,month,day is 0~~99,so we can write like this.*/
  byte rb_Highbit_1;
  byte rb_Lowbit_1;
  byte rb_Output_l;
  
  rb_Highbit_1 = (rb_Input_l)/10;
  rb_Lowbit_1 = (rb_Input_l)%10;
  rb_Output_l =  rb_Highbit_1*16 + rb_Lowbit_1;
     
  return (rb_Output_l);
}
#endif

#ifdef _SUPPORTSERVICE22_
void Diagnose_ReadDataByIdentifier(void)
{
  byte rb_Index_l;
  word rw_Identifier_l;
#ifndef BRILLIANCE_M8X
  byte rb_SwPartNr[cb_SW_PART_NUMBER_LENGTH_mg];
#endif
#ifndef NOT_SUPPORT_SERVICE_1519TO1525
  /*VDR_683 interval times for rain sensor above 200kmph inactive in 100ms*/
  const byte cab_AchsenAbschnitt_mg[4] = {19,12,6,3};  
  /*VDR_683 interval times for rain sensor above 200kmph inactive in 100ms*/
  const byte cab_SteigungGeradengleichung_mg[4] = {0<<5,2<<5,4<<5,5<<5};   
#endif 
  
  SetSystemBezeichnung();
  if((l_u8_rd_MasterReqB1() != cb_REQLENGTHSID22_s))
  {
    Diagnose_NegativeResponse(cb_READDATABYIDENTIFIER_s,cb_INCORECTMESSAGELENGTH_s); //Falsche Option
  }
  else if (rbi_EEPROMLoad_g != FALSE)   // EEPROM Load Finished?  VCO_30
  {
    Diagnose_NegativeResponse(cb_READDATABYIDENTIFIER_s,cb_CONDITION_NOT_CORRECT_s); /*EEPROM not initialised*/
  }
  else
    
  {
    rab_DiagRespBuffer_mg[1] = cb_READDATABYIDENTIFIER_s | 0x40;
    rab_DiagRespBuffer_mg[2] = l_u8_rd_MasterReqB3();
    rab_DiagRespBuffer_mg[3] = l_u8_rd_MasterReqB4();
    
    rw_Identifier_l = (((word)l_u8_rd_MasterReqB3())<<8)+l_u8_rd_MasterReqB4();
    
#ifdef RLFS_TO_FS_ENBLED /*RLS_VCO_086 implement FS-Services for Diagnostics*/ /*RLS_VDR_604 is this for FS-Sensor?*/
    if (((rw_Identifier_l & 0x00FF) == 0x4B)||((rw_Identifier_l & 0x000F) == 0x00))
    {
      if (rbi_RLFS_is_FS_g == FALSE)
      {
        rw_Identifier_l = 0;  /*Clear Ident*/
      }
      
    }
    else /*is for RLFS*/
    {
      if (rbi_RLFS_is_FS_g == TRUE)
      {
        rw_Identifier_l = 0; /* Clear Ident*/
      }
      
    }
    
    
#endif
    switch(rw_Identifier_l)
    {
#ifdef CTCS_M31T// edited by shutian.duan
      case 0xF193:
        rab_DiagRespBuffer_mg[0] = 12;//  hardware version number

        rab_DiagRespBuffer_mg[4] = cb_HARDWARESTAND_g;
        rab_DiagRespBuffer_mg[5] = rab_HardwareStand_g(0);
        rab_DiagRespBuffer_mg[6] = rab_HardwareStand_g(1);             
        rab_DiagRespBuffer_mg[7] = 0;
        rab_DiagRespBuffer_mg[8] = 0;  
        rab_DiagRespBuffer_mg[9] = 0;
        rab_DiagRespBuffer_mg[10] = 0;  
        rab_DiagRespBuffer_mg[11] = 0;  
        rab_DiagRespBuffer_mg[12] = 0;  
        
       break;
       
       case 0xF195:
        rab_DiagRespBuffer_mg[0] = 12;//  software version number
        
        rab_DiagRespBuffer_mg[4] = rab_SoftwareStand_g(0);
        rab_DiagRespBuffer_mg[5] = rab_SoftwareStand_g(1);
        rab_DiagRespBuffer_mg[6] = (rab_SoftwareStand_g(2)>>4) +'0';
        rab_DiagRespBuffer_mg[7] = (rab_SoftwareStand_g(2)&0x0F)+'0';  
        rab_DiagRespBuffer_mg[8] = 0;
        rab_DiagRespBuffer_mg[9] = 0;
        rab_DiagRespBuffer_mg[10] = 0;
        rab_DiagRespBuffer_mg[11] = 0;
        rab_DiagRespBuffer_mg[12] = 0;
        
       break;
        
      case 0xF18A:
        rab_DiagRespBuffer_mg[0] = 6;//System supplier identifier data
        
        rab_DiagRespBuffer_mg[4+0] = rab_System_Supplier_ID_g(0);
        rab_DiagRespBuffer_mg[4+1] = rab_System_Supplier_ID_g(1);
        rab_DiagRespBuffer_mg[4+2] = rab_System_Supplier_ID_g(2);       
        break;
        
      case 0xF18B:
        rab_DiagRespBuffer_mg[0] = 6; /* Length */
        
        rab_DiagRespBuffer_mg[4+0] = Diagnosis_HEXtoBCD(rab_Fertigungsdatum_g(2));   /*yeah*/  
        rab_DiagRespBuffer_mg[4+1] = Diagnosis_HEXtoBCD(rab_Fertigungsdatum_g(1));   /*month*/    
        rab_DiagRespBuffer_mg[4+2] = Diagnosis_HEXtoBCD(rab_Fertigungsdatum_g(0));   /*day*/
        
        break;
        
      case 0xF18C:// series number
        rab_DiagRespBuffer_mg[0] = 12; /* Length */
        
        rab_DiagRespBuffer_mg[4+0] = (Diagnosis_BCDtoASCII(rab_Produktionsdaten_g(0)>>4));
        rab_DiagRespBuffer_mg[4+1] = (Diagnosis_BCDtoASCII(rab_Produktionsdaten_g(0)&0x0F)); 
        rab_DiagRespBuffer_mg[4+2] = (Diagnosis_BCDtoASCII(rab_Produktionsdaten_g(1)>>4));
        rab_DiagRespBuffer_mg[4+3] = (Diagnosis_BCDtoASCII(rab_Produktionsdaten_g(1)&0x0F));
        rab_DiagRespBuffer_mg[4+4] = (Diagnosis_BCDtoASCII(rab_Produktionsdaten_g(2)>>4));
        rab_DiagRespBuffer_mg[4+5] = (Diagnosis_BCDtoASCII(rab_Produktionsdaten_g(2)&0x0F));
        rab_DiagRespBuffer_mg[4+6] = (Diagnosis_BCDtoASCII(rab_Produktionsdaten_g(3)>>4));
        rab_DiagRespBuffer_mg[4+7] = (Diagnosis_BCDtoASCII(rab_Produktionsdaten_g(3)&0x0F));
        rab_DiagRespBuffer_mg[4+8] = 0;
      
        break ;

    case 0xF10A:
    case 0xF187:
        rab_DiagRespBuffer_mg[0] = 16; /* Length */
        
        rab_DiagRespBuffer_mg[4+0] = (rab_VehicleManufacturerLogisticAssemblyPartNumbe_g(0));
        rab_DiagRespBuffer_mg[4+1] = (rab_VehicleManufacturerLogisticAssemblyPartNumbe_g(1)); 
        rab_DiagRespBuffer_mg[4+2] = (rab_VehicleManufacturerLogisticAssemblyPartNumbe_g(2));
        rab_DiagRespBuffer_mg[4+3] = (rab_VehicleManufacturerLogisticAssemblyPartNumbe_g(3));
        rab_DiagRespBuffer_mg[4+4] = (rab_VehicleManufacturerLogisticAssemblyPartNumbe_g(4));
        rab_DiagRespBuffer_mg[4+5] = (rab_VehicleManufacturerLogisticAssemblyPartNumbe_g(5));
        rab_DiagRespBuffer_mg[4+6] = (rab_VehicleManufacturerLogisticAssemblyPartNumbe_g(6));
        rab_DiagRespBuffer_mg[4+7] = (rab_VehicleManufacturerLogisticAssemblyPartNumbe_g(7));
        rab_DiagRespBuffer_mg[4+8] = (rab_VehicleManufacturerLogisticAssemblyPartNumbe_g(8));
        rab_DiagRespBuffer_mg[4+9] = (rab_VehicleManufacturerLogisticAssemblyPartNumbe_g(9));;
        rab_DiagRespBuffer_mg[4+10] = (rab_VehicleManufacturerLogisticAssemblyPartNumbe_g(10));
        rab_DiagRespBuffer_mg[4+11] = (rab_VehicleManufacturerLogisticAssemblyPartNumbe_g(11));
        rab_DiagRespBuffer_mg[4+12] = (rab_VehicleManufacturerLogisticAssemblyPartNumbe_g(12));
        
        break;
        
     case 0xF188:
        rab_DiagRespBuffer_mg[0] = 11; /* Length */
        rab_DiagRespBuffer_mg[4+0] = (rab_VehicleManufacturingECUSoftwareVersionNumber_g(0));
        rab_DiagRespBuffer_mg[4+1] = (rab_VehicleManufacturingECUSoftwareVersionNumber_g(1)); 
        rab_DiagRespBuffer_mg[4+2] = (rab_VehicleManufacturingECUSoftwareVersionNumber_g(2));
        rab_DiagRespBuffer_mg[4+3] = (rab_VehicleManufacturingECUSoftwareVersionNumber_g(3));
        rab_DiagRespBuffer_mg[4+4] = (rab_VehicleManufacturingECUSoftwareVersionNumber_g(4));
        rab_DiagRespBuffer_mg[4+5] = (rab_VehicleManufacturingECUSoftwareVersionNumber_g(5));
        rab_DiagRespBuffer_mg[4+6] = (rab_VehicleManufacturingECUSoftwareVersionNumber_g(6));
        rab_DiagRespBuffer_mg[4+7] = (rab_VehicleManufacturingECUSoftwareVersionNumber_g(7));
        break;
        
    case 0xF191:
        rab_DiagRespBuffer_mg[0] = 8; /* Length */
        rab_DiagRespBuffer_mg[4+0] = (rab_VehicleManufacturingECUHardwareVersionNumber_g(0));
        rab_DiagRespBuffer_mg[4+1] = (rab_VehicleManufacturingECUHardwareVersionNumber_g(1)); 
        rab_DiagRespBuffer_mg[4+2] = (rab_VehicleManufacturingECUHardwareVersionNumber_g(2));
        rab_DiagRespBuffer_mg[4+3] = (rab_VehicleManufacturingECUHardwareVersionNumber_g(3));
        rab_DiagRespBuffer_mg[4+4] = (rab_VehicleManufacturingECUHardwareVersionNumber_g(4));
        
        break;
#endif
      
#ifdef BRILLIANCE_M8X
      case 0xF103:/*check by Blake_Li*/
        rab_DiagRespBuffer_mg[0] = 9; /* Length */
        
        rab_DiagRespBuffer_mg[4+0] = rab_ECU_Part_Number_g(0);     
        rab_DiagRespBuffer_mg[4+1] = rab_ECU_Part_Number_g(1);
        rab_DiagRespBuffer_mg[4+2] = rab_ECU_Part_Number_g(2);     
        rab_DiagRespBuffer_mg[4+3] = rab_ECU_Part_Number_g(3);     
        rab_DiagRespBuffer_mg[4+4] = rab_ECU_Part_Number_g(4);     
        rab_DiagRespBuffer_mg[4+5] = rab_ECU_Part_Number_g(5);               
        
       break;
        
      case 0xF18A:/*check by Blake_Li*/
        rab_DiagRespBuffer_mg[0] = 8; /* Length */ 
        
        rab_DiagRespBuffer_mg[4+0] = rab_System_Supplier_ID_g(0);
        rab_DiagRespBuffer_mg[4+1] = rab_System_Supplier_ID_g(1);
        rab_DiagRespBuffer_mg[4+2] = rab_System_Supplier_ID_g(2);
        rab_DiagRespBuffer_mg[4+3] = rab_System_Supplier_ID_g(3);  
        rab_DiagRespBuffer_mg[4+4] = rab_System_Supplier_ID_g(4);
        
        break;
        
      case 0xF18B:/*check by Blake_Li*/
        rab_DiagRespBuffer_mg[0] = 6; /* Length */
        
        rab_DiagRespBuffer_mg[4+0] = Diagnosis_HEXtoBCD(rab_Fertigungsdatum_g(2));   /*yeah*/  
        rab_DiagRespBuffer_mg[4+1] = Diagnosis_HEXtoBCD(rab_Fertigungsdatum_g(1));   /*month*/    
        rab_DiagRespBuffer_mg[4+2] = Diagnosis_HEXtoBCD(rab_Fertigungsdatum_g(0));   /*day*/
        
        break;
        
      case 0xF191:  
        rab_DiagRespBuffer_mg[0] = 10; /* Length */    
        
        rab_DiagRespBuffer_mg[4+0] = rab_Audi_HW_Partnumber_g(0);
        rab_DiagRespBuffer_mg[4+1] = rab_Audi_HW_Partnumber_g(1);
        rab_DiagRespBuffer_mg[4+2] = rab_Audi_HW_Partnumber_g(2);
        rab_DiagRespBuffer_mg[4+3] = rab_Audi_HW_Partnumber_g(3);
        rab_DiagRespBuffer_mg[4+4] = rab_Audi_HW_Partnumber_g(4);
        rab_DiagRespBuffer_mg[4+5] = rab_Audi_HW_Partnumber_g(5);
        rab_DiagRespBuffer_mg[4+6] = rab_Audi_HW_Partnumber_g(6);
        
        break;
     
      case 0xF188:
        rab_DiagRespBuffer_mg[0] = 10; /* Length */    
        
        rab_DiagRespBuffer_mg[4+0] = rab_Audi_SW_Partnumber_g(0);
        rab_DiagRespBuffer_mg[4+1] = rab_Audi_SW_Partnumber_g(1);
        rab_DiagRespBuffer_mg[4+2] = rab_Audi_SW_Partnumber_g(2);
        rab_DiagRespBuffer_mg[4+3] = rab_Audi_SW_Partnumber_g(3);
        rab_DiagRespBuffer_mg[4+4] = rab_Audi_SW_Partnumber_g(4);
        rab_DiagRespBuffer_mg[4+5] = rab_Audi_SW_Partnumber_g(5);
        rab_DiagRespBuffer_mg[4+6] = rab_Audi_SW_Partnumber_g(6);
        
        break;
             
      case 0xF110:
        rab_DiagRespBuffer_mg[0] = 18; /* Length */   
        
        rab_DiagRespBuffer_mg[4+0] = rab_ECU_Name_Data_g(0);
        rab_DiagRespBuffer_mg[4+1] = rab_ECU_Name_Data_g(1);
        rab_DiagRespBuffer_mg[4+2] = rab_ECU_Name_Data_g(2);
        rab_DiagRespBuffer_mg[4+3] = rab_ECU_Name_Data_g(3);
        rab_DiagRespBuffer_mg[4+4] = rab_ECU_Name_Data_g(4);
        rab_DiagRespBuffer_mg[4+5] = rab_ECU_Name_Data_g(5);
        rab_DiagRespBuffer_mg[4+6] = rab_ECU_Name_Data_g(6);
        rab_DiagRespBuffer_mg[4+7] = rab_ECU_Name_Data_g(7);
        rab_DiagRespBuffer_mg[4+8] = rab_ECU_Name_Data_g(8);
        rab_DiagRespBuffer_mg[4+9] = rab_ECU_Name_Data_g(9);
        rab_DiagRespBuffer_mg[4+10] = rab_ECU_Name_Data_g(10);
        rab_DiagRespBuffer_mg[4+11] = rab_ECU_Name_Data_g(11);
        rab_DiagRespBuffer_mg[4+12] = rab_ECU_Name_Data_g(12);
        rab_DiagRespBuffer_mg[4+13] = rab_ECU_Name_Data_g(13); 
        rab_DiagRespBuffer_mg[4+14] = rab_ECU_Name_Data_g(14); 
        break;    
        
      case 0xF10D:
        rab_DiagRespBuffer_mg[0] = 5; /* Length */   
        
        rab_DiagRespBuffer_mg[4+0] = rab_LDF_File_Version(0);
        rab_DiagRespBuffer_mg[4+1] = rab_LDF_File_Version(1);
        break;
            
      case 0x0731: // Read System Identification
        
      case 0x6C02:  /*VDR_376 UDS System Identification*/
  #ifdef RLFS_TO_FS_ENBLED /*RLS_VCO_086 implement FS-Services for Diagnostics*/
      case 0x3750: /* Read System Identification KWP*/
      case 0x6C4B: /* Read System Identification USD*/
  #endif
    
#ifdef  GEELY2DOT0
        rab_DiagRespBuffer_mg[0] = 3+14; // Length
        for(rb_Index_l = 0;rb_Index_l <=13;rb_Index_l++)
#elif ZOTYE_B21
         rab_DiagRespBuffer_mg[0] = 3+15; // Length
        for(rb_Index_l = 0;rb_Index_l <=14;rb_Index_l++) 
#else
        rab_DiagRespBuffer_mg[0] = 3+13; // Length
        for(rb_Index_l = 0;rb_Index_l <=12;rb_Index_l++)
       
#endif  
        {
          rab_DiagRespBuffer_mg[4+rb_Index_l] = pb_Systembezeichnung_mg[rb_Index_l];
        }
        
        break;
        
      case 0x0671: // Read SW Version
        
      case 0x6402:  /*VDR_376 UDS SW Version*/
  #ifdef RLFS_TO_FS_ENBLED /*RLS_VCO_086 implement FS-Services for Diagnostics*/
      case 0x3690: /* Read SW Version KWP*/
      case 0x644B: /* Read SW Version UDS*/
  #endif
        
        rab_DiagRespBuffer_mg[0] = 7; // Length
        
        rab_DiagRespBuffer_mg[4] = rab_SoftwareStand_g(0);
        rab_DiagRespBuffer_mg[5] = rab_SoftwareStand_g(1);
        rab_DiagRespBuffer_mg[6] = (rab_SoftwareStand_g(2)>>4) +'0';
        rab_DiagRespBuffer_mg[7] = (rab_SoftwareStand_g(2)&0x0F)+'0';
        break;
        
        
     case 0x06D1: // Read HW Version
      
     case 0x6802:  /*VDR_376 UDS*/
  #ifdef RLFS_TO_FS_ENBLED /*RLS_VCO_086 implement FS-Services for Diagnostics*/
      case 0x36F0: /* Read HW Version KWP*/
      case 0x684B: /* Read HW Version UDS*/
  #endif
        
        rab_DiagRespBuffer_mg[0] = 6; // Length
        rab_DiagRespBuffer_mg[4] = cb_HARDWARESTAND_g;
        rab_DiagRespBuffer_mg[5] = rab_HardwareStand_g(0);
        rab_DiagRespBuffer_mg[6] = rab_HardwareStand_g(1);
        break;   
    case 0x0611: // Read Coding
      
    case 0x6002:  /*VDR_376 UDS Read Coding*/
      
      rab_DiagRespBuffer_mg[0] = 6; // Length
      
      rab_DiagRespBuffer_mg[4] = rb_Kodierbyte0_g;
      rab_DiagRespBuffer_mg[5] = rb_Kodierbyte1_g;
      rab_DiagRespBuffer_mg[6] = rb_Kodierbyte2_g;
      
      break;        
                     
#else  
        
    case 0x06A1: // Read HW Partnumber
#ifdef HAITEC
    case 0x6602:  /*VDR_376 UDS*/
#ifdef RLFS_TO_FS_ENBLED /*RLS_VCO_086 implement FS-Services for Diagnostics*/
    case 0x36C0: /* Read HW Partnumber KWP*/
    case 0x664B: // Read HW Partnumber UDS*/
#endif
    rab_DiagRespBuffer_mg[0] = 13; /* Length */
    rab_DiagRespBuffer_mg[4+0] = rab_Audi_HW_Partnumber_g(0);
    rab_DiagRespBuffer_mg[4+1] = rab_Audi_HW_Partnumber_g(1);
    rab_DiagRespBuffer_mg[4+2] = rab_Audi_HW_Partnumber_g(2);    
    rab_DiagRespBuffer_mg[4+3] = Diagnosis_BCDtoASCII(rab_Audi_HW_Partnumber_g(3)>>4);
    rab_DiagRespBuffer_mg[4+4] = Diagnosis_BCDtoASCII(rab_Audi_HW_Partnumber_g(3)&0x0F);
    rab_DiagRespBuffer_mg[4+5] = rab_Audi_HW_Partnumber_g(4);
    rab_DiagRespBuffer_mg[4+6] = rab_Audi_HW_Partnumber_g(5);   
    rab_DiagRespBuffer_mg[4+7] = Diagnosis_BCDtoASCII(rab_Audi_HW_Partnumber_g(6)>>4);
    rab_DiagRespBuffer_mg[4+8] = Diagnosis_BCDtoASCII(rab_Audi_HW_Partnumber_g(6)&0x0F);   
    rab_DiagRespBuffer_mg[4+9]  = rab_Audi_HW_Partnumber_g(7); /*   HW-Partnumber index*/     
    break;
#elif defined(FOTON_S700)   
    case 0x6602:  /*VDR_376 UDS*/
#ifdef RLFS_TO_FS_ENBLED /*RLS_VCO_086 implement FS-Services for Diagnostics*/
    case 0x36C0: /* Read HW Partnumber KWP*/
    case 0x664B: // Read HW Partnumber UDS*/
#endif
      rab_DiagRespBuffer_mg[0] = 13; /* Length */
      
      rab_DiagRespBuffer_mg[4+0] = rab_Audi_HW_Partnumber_g(0);
      rab_DiagRespBuffer_mg[4+1] = rab_Audi_HW_Partnumber_g(1);
      rab_DiagRespBuffer_mg[4+2] = rab_Audi_HW_Partnumber_g(2);
      rab_DiagRespBuffer_mg[4+3] = Diagnosis_BCDtoASCII(rab_Audi_HW_Partnumber_g(3)>>4);
      rab_DiagRespBuffer_mg[4+4] = Diagnosis_BCDtoASCII(rab_Audi_HW_Partnumber_g(3)&0x0F);     
      rab_DiagRespBuffer_mg[4+5] = Diagnosis_BCDtoASCII(rab_Audi_HW_Partnumber_g(4)>>4);
      rab_DiagRespBuffer_mg[4+6] = Diagnosis_BCDtoASCII(rab_Audi_HW_Partnumber_g(4)&0x0F);
      rab_DiagRespBuffer_mg[4+7] = Diagnosis_BCDtoASCII(rab_Audi_HW_Partnumber_g(5)>>4);
      rab_DiagRespBuffer_mg[4+8] = Diagnosis_BCDtoASCII(rab_Audi_HW_Partnumber_g(5)&0x0F);
      
      rab_DiagRespBuffer_mg[4+9]  = rab_Audi_HW_Partnumber_g(6); /*   HW-Partnumber index*/
      break;  		
#elif defined (BAICYX_G20)
    case 0x6602:  /*VDR_376 UDS*/
#ifdef RLFS_TO_FS_ENBLED /*RLS_VCO_086 implement FS-Services for Diagnostics*/
    case 0x36C0: /* Read HW Partnumber KWP*/
    case 0x664B: // Read HW Partnumber UDS*/
#endif
      
      rab_DiagRespBuffer_mg[0] = 15; /* Length */
    
      rab_DiagRespBuffer_mg[4+0] = Diagnosis_BCDtoASCII(rab_Audi_HW_Partnumber_g(0)>>4);
      rab_DiagRespBuffer_mg[4+1] = Diagnosis_BCDtoASCII(rab_Audi_HW_Partnumber_g(0)&0x0F);
      rab_DiagRespBuffer_mg[4+2] = Diagnosis_BCDtoASCII(rab_Audi_HW_Partnumber_g(1)>>4);
      rab_DiagRespBuffer_mg[4+3] = Diagnosis_BCDtoASCII(rab_Audi_HW_Partnumber_g(1)&0x0F);
      rab_DiagRespBuffer_mg[4+4] = Diagnosis_BCDtoASCII(rab_Audi_HW_Partnumber_g(2)>>4);
      rab_DiagRespBuffer_mg[4+5] = Diagnosis_BCDtoASCII(rab_Audi_HW_Partnumber_g(2)&0x0F);
      rab_DiagRespBuffer_mg[4+6] = Diagnosis_BCDtoASCII(rab_Audi_HW_Partnumber_g(3)>>4);
      rab_DiagRespBuffer_mg[4+7] = Diagnosis_BCDtoASCII(rab_Audi_HW_Partnumber_g(3)&0x0F);
      rab_DiagRespBuffer_mg[4+8] = rab_Audi_HW_Partnumber_g(4);
      
      rab_DiagRespBuffer_mg[4+9]  = rab_Audi_HW_Partnumber_g(5); 
      rab_DiagRespBuffer_mg[4+10] = rab_Audi_HW_Partnumber_g(6);
      rab_DiagRespBuffer_mg[4+11] = rab_Audi_HW_Partnumber_g(7);
      break;
#elif defined (GEELY2DOT0)
    case 0x6602:  /*VDR_376 UDS*/
#ifdef RLFS_TO_FS_ENBLED /*RLS_VCO_086 implement FS-Services for Diagnostics*/
    case 0x36C0: /* Read HW Partnumber KWP*/
    case 0x664B: // Read HW Partnumber UDS*/
#endif
      
      rab_DiagRespBuffer_mg[0] = 16; /* Length */
    
      rab_DiagRespBuffer_mg[4+0] = Diagnosis_BCDtoASCII(rab_Audi_HW_Partnumber_g(0)>>4);
      rab_DiagRespBuffer_mg[4+1] = Diagnosis_BCDtoASCII(rab_Audi_HW_Partnumber_g(0)&0x0F);
      rab_DiagRespBuffer_mg[4+2] = Diagnosis_BCDtoASCII(rab_Audi_HW_Partnumber_g(1)>>4);
      rab_DiagRespBuffer_mg[4+3] = Diagnosis_BCDtoASCII(rab_Audi_HW_Partnumber_g(1)&0x0F);
      rab_DiagRespBuffer_mg[4+4] = Diagnosis_BCDtoASCII(rab_Audi_HW_Partnumber_g(2)>>4);
      rab_DiagRespBuffer_mg[4+5] = Diagnosis_BCDtoASCII(rab_Audi_HW_Partnumber_g(2)&0x0F);
      rab_DiagRespBuffer_mg[4+6] = Diagnosis_BCDtoASCII(rab_Audi_HW_Partnumber_g(3)>>4);
      rab_DiagRespBuffer_mg[4+7] = Diagnosis_BCDtoASCII(rab_Audi_HW_Partnumber_g(3)&0x0F);
      rab_DiagRespBuffer_mg[4+8] = Diagnosis_BCDtoASCII(rab_Audi_HW_Partnumber_g(4)>>4);
      rab_DiagRespBuffer_mg[4+9] = Diagnosis_BCDtoASCII(rab_Audi_HW_Partnumber_g(4)&0x0F);
      rab_DiagRespBuffer_mg[4+10] = rab_Audi_HW_Partnumber_g(5);    
      rab_DiagRespBuffer_mg[4+11] = rab_Audi_HW_Partnumber_g(6);
      rab_DiagRespBuffer_mg[4+12] = rab_Audi_HW_Partnumber_g(7);
      break;
    
#else      
    case 0x6602:  /*VDR_376 UDS*/
#ifdef RLFS_TO_FS_ENBLED /*RLS_VCO_086 implement FS-Services for Diagnostics*/
    case 0x36C0: /* Read HW Partnumber KWP*/
    case 0x664B: // Read HW Partnumber UDS*/
#endif
      
      rab_DiagRespBuffer_mg[0] = 14; /* Length */
      
      rab_DiagRespBuffer_mg[4+0] = rab_Audi_HW_Partnumber_g(0);
      rab_DiagRespBuffer_mg[4+1] = rab_Audi_HW_Partnumber_g(1);
      rab_DiagRespBuffer_mg[4+2] = rab_Audi_HW_Partnumber_g(2);
      rab_DiagRespBuffer_mg[4+3] = Diagnosis_BCDtoASCII(rab_Audi_HW_Partnumber_g(3)>>4);
      rab_DiagRespBuffer_mg[4+4] = Diagnosis_BCDtoASCII(rab_Audi_HW_Partnumber_g(3)&0x0F);     
      rab_DiagRespBuffer_mg[4+5] = Diagnosis_BCDtoASCII(rab_Audi_HW_Partnumber_g(4)>>4);
      rab_DiagRespBuffer_mg[4+6] = Diagnosis_BCDtoASCII(rab_Audi_HW_Partnumber_g(4)&0x0F);
      rab_DiagRespBuffer_mg[4+7] = Diagnosis_BCDtoASCII(rab_Audi_HW_Partnumber_g(5)>>4);
      rab_DiagRespBuffer_mg[4+8] = Diagnosis_BCDtoASCII(rab_Audi_HW_Partnumber_g(5)&0x0F);
      
      rab_DiagRespBuffer_mg[4+9]  = rab_Audi_HW_Partnumber_g(6); /*   HW-Partnumber index*/
      rab_DiagRespBuffer_mg[4+10] = rab_Audi_HW_Partnumber_g(7); /*   HW-Partnumber index*/
      break;
#endif
    case 0x06D1: // Read HW Version
      
    case 0x6802:  /*VDR_376 UDS*/
#ifdef RLFS_TO_FS_ENBLED /*RLS_VCO_086 implement FS-Services for Diagnostics*/
    case 0x36F0: /* Read HW Version KWP*/
    case 0x684B: /* Read HW Version UDS*/
#endif
      
      rab_DiagRespBuffer_mg[0] = 6; // Length
      rab_DiagRespBuffer_mg[4] = cb_HARDWARESTAND_g;
      rab_DiagRespBuffer_mg[5] = rab_HardwareStand_g(0);
      rab_DiagRespBuffer_mg[6] = rab_HardwareStand_g(1);
      break;
    case 0x0641: // Read SW Partnumber
#ifdef HAITEC
    case 0x6202:  /*VDR_376 UDS VW-Audi Teilenummer*/
#ifdef RLFS_TO_FS_ENBLED /*RLS_VCO_086 implement FS-Services for Diagnostics*/
    case 0x3660: /*Read VW-Audi Teilenummer KWP*/
    case 0x624B: /*Read VW-Audi Teilenummer UDS*/     
#endif
    rab_DiagRespBuffer_mg[0] = 13; /* Length */
    rab_DiagRespBuffer_mg[4+0] = rab_Audi_SW_Partnumber_g(0);
    rab_DiagRespBuffer_mg[4+1] = rab_Audi_SW_Partnumber_g(1);
    rab_DiagRespBuffer_mg[4+2] = rab_Audi_SW_Partnumber_g(2);    
    rab_DiagRespBuffer_mg[4+3] = Diagnosis_BCDtoASCII(rab_Audi_SW_Partnumber_g(3)>>4);
    rab_DiagRespBuffer_mg[4+4] = Diagnosis_BCDtoASCII(rab_Audi_SW_Partnumber_g(3)&0x0F);
    rab_DiagRespBuffer_mg[4+5] = rab_Audi_SW_Partnumber_g(4);
    rab_DiagRespBuffer_mg[4+6] = rab_Audi_SW_Partnumber_g(5);   
    rab_DiagRespBuffer_mg[4+7] = Diagnosis_BCDtoASCII(rab_Audi_SW_Partnumber_g(6)>>4);
    rab_DiagRespBuffer_mg[4+8] = Diagnosis_BCDtoASCII(rab_Audi_SW_Partnumber_g(6)&0x0F);   
    rab_DiagRespBuffer_mg[4+9]  = rab_Audi_SW_Partnumber_g(7); /*   HW-Partnumber index*/     
    break;  
#elif defined(FOTON_S700)
    case 0x6202:  /*VDR_376 UDS VW-Audi Teilenummer*/
#ifdef RLFS_TO_FS_ENBLED /*RLS_VCO_086 implement FS-Services for Diagnostics*/
    case 0x3660: /*Read VW-Audi Teilenummer KWP*/
    case 0x624B: /*Read VW-Audi Teilenummer UDS*/     
#endif
     rab_DiagRespBuffer_mg[0] = 13; // Length
    
    rab_DiagRespBuffer_mg[4+0] = rab_Audi_SW_Partnumber_g(0);
    rab_DiagRespBuffer_mg[4+1] = rab_Audi_SW_Partnumber_g(1);
    rab_DiagRespBuffer_mg[4+2] = rab_Audi_SW_Partnumber_g(2);
    rab_DiagRespBuffer_mg[4+3] = Diagnosis_BCDtoASCII(rab_Audi_SW_Partnumber_g(3)>>4);
    rab_DiagRespBuffer_mg[4+4] = Diagnosis_BCDtoASCII(rab_Audi_SW_Partnumber_g(3)&0x0F);
    rab_DiagRespBuffer_mg[4+5] = Diagnosis_BCDtoASCII(rab_Audi_SW_Partnumber_g(4)>>4);
    rab_DiagRespBuffer_mg[4+6] = Diagnosis_BCDtoASCII(rab_Audi_SW_Partnumber_g(4)&0x0F);
    rab_DiagRespBuffer_mg[4+7] = Diagnosis_BCDtoASCII(rab_Audi_SW_Partnumber_g(5)>>4);
    rab_DiagRespBuffer_mg[4+8] = Diagnosis_BCDtoASCII(rab_Audi_SW_Partnumber_g(5)&0x0F);
    
    rab_DiagRespBuffer_mg[4+9]  = rab_Audi_SW_Partnumber_g(6); /* SW-Partnumber index*/
    
    break;      
#elif defined (BAICYX_G20)
    case 0x6202:  /*VDR_376 UDS VW-Audi Teilenummer*/
#ifdef RLFS_TO_FS_ENBLED /*RLS_VCO_086 implement FS-Services for Diagnostics*/
    case 0x3660: /*Read VW-Audi Teilenummer KWP*/
    case 0x624B: /*Read VW-Audi Teilenummer UDS*/     
#endif
    rab_DiagRespBuffer_mg[0] = 15; /* Length */
    rab_DiagRespBuffer_mg[4+0] = Diagnosis_BCDtoASCII(rab_Audi_SW_Partnumber_g(0)>>4);
    rab_DiagRespBuffer_mg[4+1] = Diagnosis_BCDtoASCII(rab_Audi_SW_Partnumber_g(0)&0x0F);
    rab_DiagRespBuffer_mg[4+2] = Diagnosis_BCDtoASCII(rab_Audi_SW_Partnumber_g(1)>>4);
    rab_DiagRespBuffer_mg[4+3] = Diagnosis_BCDtoASCII(rab_Audi_SW_Partnumber_g(1)&0x0F);
    rab_DiagRespBuffer_mg[4+4] = Diagnosis_BCDtoASCII(rab_Audi_SW_Partnumber_g(2)>>4);
    rab_DiagRespBuffer_mg[4+5] = Diagnosis_BCDtoASCII(rab_Audi_SW_Partnumber_g(2)&0x0F);
    rab_DiagRespBuffer_mg[4+6] = Diagnosis_BCDtoASCII(rab_Audi_SW_Partnumber_g(3)>>4);
    rab_DiagRespBuffer_mg[4+7] = Diagnosis_BCDtoASCII(rab_Audi_SW_Partnumber_g(3)&0x0F);
    rab_DiagRespBuffer_mg[4+8] = rab_Audi_SW_Partnumber_g(4);

    rab_DiagRespBuffer_mg[4+9] = rab_Audi_SW_Partnumber_g(5); 
    rab_DiagRespBuffer_mg[4+10] = rab_Audi_SW_Partnumber_g(6);
    rab_DiagRespBuffer_mg[4+11] = rab_Audi_SW_Partnumber_g(7);     
    break;
#elif defined (GEELY2DOT0)
    case 0x6202:  /*VDR_376 UDS VW-Audi Teilenummer*/
#ifdef RLFS_TO_FS_ENBLED /*RLS_VCO_086 implement FS-Services for Diagnostics*/
    case 0x3660: /*Read VW-Audi Teilenummer KWP*/
    case 0x624B: /*Read VW-Audi Teilenummer UDS*/     
#endif
    rab_DiagRespBuffer_mg[0] = 16; /* Length */
    rab_DiagRespBuffer_mg[4+0] = Diagnosis_BCDtoASCII(rab_Audi_SW_Partnumber_g(0)>>4);
    rab_DiagRespBuffer_mg[4+1] = Diagnosis_BCDtoASCII(rab_Audi_SW_Partnumber_g(0)&0x0F);
    rab_DiagRespBuffer_mg[4+2] = Diagnosis_BCDtoASCII(rab_Audi_SW_Partnumber_g(1)>>4);
    rab_DiagRespBuffer_mg[4+3] = Diagnosis_BCDtoASCII(rab_Audi_SW_Partnumber_g(1)&0x0F);
    rab_DiagRespBuffer_mg[4+4] = Diagnosis_BCDtoASCII(rab_Audi_SW_Partnumber_g(2)>>4);
    rab_DiagRespBuffer_mg[4+5] = Diagnosis_BCDtoASCII(rab_Audi_SW_Partnumber_g(2)&0x0F);
    rab_DiagRespBuffer_mg[4+6] = Diagnosis_BCDtoASCII(rab_Audi_SW_Partnumber_g(3)>>4);
    rab_DiagRespBuffer_mg[4+7] = Diagnosis_BCDtoASCII(rab_Audi_SW_Partnumber_g(3)&0x0F);
    rab_DiagRespBuffer_mg[4+8] = Diagnosis_BCDtoASCII(rab_Audi_SW_Partnumber_g(4)>>4);
    rab_DiagRespBuffer_mg[4+9] = Diagnosis_BCDtoASCII(rab_Audi_SW_Partnumber_g(4)&0x0F);
    rab_DiagRespBuffer_mg[4+10] = rab_Audi_SW_Partnumber_g(5);

    rab_DiagRespBuffer_mg[4+11] = rab_Audi_SW_Partnumber_g(6); 
    rab_DiagRespBuffer_mg[4+12] = rab_Audi_SW_Partnumber_g(7);     
    break;
#else      
    case 0x6202:  /*VDR_376 UDS VW-Audi Teilenummer*/
#ifdef RLFS_TO_FS_ENBLED /*RLS_VCO_086 implement FS-Services for Diagnostics*/
    case 0x3660: /*Read VW-Audi Teilenummer KWP*/
    case 0x624B: /*Read VW-Audi Teilenummer UDS*/
#endif
      
      rab_DiagRespBuffer_mg[0] = 14; // Length
      
      rab_DiagRespBuffer_mg[4+0] = rab_Audi_SW_Partnumber_g(0);
      rab_DiagRespBuffer_mg[4+1] = rab_Audi_SW_Partnumber_g(1);
      rab_DiagRespBuffer_mg[4+2] = rab_Audi_SW_Partnumber_g(2);
      rab_DiagRespBuffer_mg[4+3] = Diagnosis_BCDtoASCII(rab_Audi_SW_Partnumber_g(3)>>4);
      rab_DiagRespBuffer_mg[4+4] = Diagnosis_BCDtoASCII(rab_Audi_SW_Partnumber_g(3)&0x0F);
      rab_DiagRespBuffer_mg[4+5] = Diagnosis_BCDtoASCII(rab_Audi_SW_Partnumber_g(4)>>4);
      rab_DiagRespBuffer_mg[4+6] = Diagnosis_BCDtoASCII(rab_Audi_SW_Partnumber_g(4)&0x0F);
      rab_DiagRespBuffer_mg[4+7] = Diagnosis_BCDtoASCII(rab_Audi_SW_Partnumber_g(5)>>4);
      rab_DiagRespBuffer_mg[4+8] = Diagnosis_BCDtoASCII(rab_Audi_SW_Partnumber_g(5)&0x0F);
      
      rab_DiagRespBuffer_mg[4+9]  = rab_Audi_SW_Partnumber_g(6); /* SW-Partnumber index*/
      rab_DiagRespBuffer_mg[4+10] = rab_Audi_SW_Partnumber_g(7); /* SW-Partnumber index*/
      
      break;
#endif      
    case 0x0671: // Read SW Version
      
    case 0x6402:  /*VDR_376 UDS SW Version*/
#ifdef RLFS_TO_FS_ENBLED /*RLS_VCO_086 implement FS-Services for Diagnostics*/
    case 0x3690: /* Read SW Version KWP*/
    case 0x644B: /* Read SW Version UDS*/
#endif
      
      rab_DiagRespBuffer_mg[0] = 7; // Length
      
      rab_DiagRespBuffer_mg[4] = rab_SoftwareStand_g(0);
      rab_DiagRespBuffer_mg[5] = rab_SoftwareStand_g(1);
      rab_DiagRespBuffer_mg[6] = (rab_SoftwareStand_g(2)>>4) +'0';
      rab_DiagRespBuffer_mg[7] = (rab_SoftwareStand_g(2)&0x0F)+'0';
      break;
#ifdef DIAG_ZSB_ENABLED
    case 0x0771:    // Read ZSB
      rab_DiagRespBuffer_mg[0] = 14; // Length
      for (rb_Index_l = 0;rb_Index_l <=10;rb_Index_l++)
      {
        rab_DiagRespBuffer_mg[4+rb_Index_l] = cab_ZSB_Teilenummer_g[rb_Index_l];
      }
      rab_DiagRespBuffer_mg[4+9] = rb_Teilenummerindex_g;
      break;
#endif
    case 0x0611: // Read Coding
      
    case 0x6002:  /*VDR_376 UDS Read Coding*/
      
      rab_DiagRespBuffer_mg[0] = 6; // Length
      
      rab_DiagRespBuffer_mg[4] = rb_Kodierbyte0_g;
      rab_DiagRespBuffer_mg[5] = rb_Kodierbyte1_g;
      rab_DiagRespBuffer_mg[6] = rb_Kodierbyte2_g;
      
      break;
    case 0x0731: // Read System Identification
      
    case 0x6C02:  /*VDR_376 UDS System Identification*/
#ifdef RLFS_TO_FS_ENBLED /*RLS_VCO_086 implement FS-Services for Diagnostics*/
    case 0x3750: /* Read System Identification KWP*/
    case 0x6C4B: /* Read System Identification USD*/
#endif
      
#ifdef  GEELY2DOT0
        rab_DiagRespBuffer_mg[0] = 3+14; // Length
        for(rb_Index_l = 0;rb_Index_l <=13;rb_Index_l++)
#elif ZOTYE_B21
         rab_DiagRespBuffer_mg[0] = 3+15; // Length
        for(rb_Index_l = 0;rb_Index_l <=14;rb_Index_l++)                    
#else
        rab_DiagRespBuffer_mg[0] = 3+13; // Length
        for(rb_Index_l = 0;rb_Index_l <=12;rb_Index_l++)
#endif
      {
        rab_DiagRespBuffer_mg[4+rb_Index_l] = pb_Systembezeichnung_mg[rb_Index_l];
      }
      break;
    case 0x0701: // Read Serial Number
      
    case 0x6A02:  /*VDR_376 UDS System Identification*/
#ifdef RLFS_TO_FS_ENBLED /*RLS_VCO_086 implement FS-Services for Diagnostics*/
    case 0x3720: /* Read Serial Number KWP*/
    case 0x6A4B: /* Read Serial Number UDS*/
#endif   
      
      
#if (defined(HAITEC) ||defined(FOTON_S700))
      rab_DiagRespBuffer_mg[0] = 22; // Length
#elif defined (BAICYX_G20)
      rab_DiagRespBuffer_mg[0] = 24; // Length      
#else
      rab_DiagRespBuffer_mg[0] = 23; // Length
#endif
      
      
      for(rb_Index_l = 0;rb_Index_l < 4;rb_Index_l++)
      {
        rab_DiagRespBuffer_mg[4+(rb_Index_l<<1)] = Diagnosis_BCDtoASCII(rab_Produktionsdaten_g(rb_Index_l)>>4);
        rab_DiagRespBuffer_mg[5+(rb_Index_l<<1)] = Diagnosis_BCDtoASCII(rab_Produktionsdaten_g(rb_Index_l)&0x0F);
      }
      rab_DiagRespBuffer_mg[12] = 'X';   
      
      getSwPartNumberAscii(&rb_SwPartNr[0]); 
#if (defined (HAITEC)  || defined (FOTON_S700))  
      for(rb_Index_l = 13;rb_Index_l <= 22;rb_Index_l++)
#elif defined (BAICYX_G20)
      for(rb_Index_l = 13;rb_Index_l <= 24;rb_Index_l++)
#else
      for(rb_Index_l = 13;rb_Index_l <= 23;rb_Index_l++)
#endif
      {
        rab_DiagRespBuffer_mg[rb_Index_l] = 0x30;
      }
      for(rb_Index_l = 0;rb_Index_l < cb_SW_PART_NUMBER_LENGTH_mg;rb_Index_l++)
      {
#ifdef BAICYX_G20
        
#else
        if((('0' <=rb_SwPartNr[rb_Index_l])  && (rb_SwPartNr[rb_Index_l] <= '9')) 
           || (('A' <=rb_SwPartNr[rb_Index_l]) && (rb_SwPartNr[rb_Index_l] <= 'Z')))
#endif
        {
          rab_DiagRespBuffer_mg[13 + rb_Index_l] = rb_SwPartNr[rb_Index_l];	
        }  
      }
   
      break;
#endif
#ifndef NOT_SUPPORT_SERVICE_1519TO1525      
    case 0x1525: /*Delay Versenkte Parklage*/
      rab_DiagRespBuffer_mg[0] = 4; // Length
      rab_DiagRespBuffer_mg[4] = rb_delay_depressed_park_pointer_g;
      break;
    case 0x1526: /*Scan time for Standby Mode*/
      rab_DiagRespBuffer_mg[0] = 4; // Length
      rab_DiagRespBuffer_mg[4] = rb_p_t_rs_abfragezyklus_g;
      break;
    case 0x1527: /*Licht an bei Autobahn*/
      rab_DiagRespBuffer_mg[0] = 6; // Length
      rab_DiagRespBuffer_mg[4] = rb_p_v_autobahn_on_off_g;
      rab_DiagRespBuffer_mg[5] = rb_p_t_autobahn_delay_on_g;
      rab_DiagRespBuffer_mg[6] = rb_p_t_autobahn_delay_off_g;
      break;
    case 0x1528: /*Frontwaschen*/
      rab_DiagRespBuffer_mg[0] = 4; // Length
      rab_DiagRespBuffer_mg[4] = rb_p_t_frontwaschen_g;
      break;
    case 0x1529: /*LIN-Kommunikation*/
      rab_DiagRespBuffer_mg[0] = 4; // Length
      rab_DiagRespBuffer_mg[4] = rb_p_t_lin_idle_g;
      break;
    case 0x152A: /*Tunnelausfahrt erkennen*/
      rab_DiagRespBuffer_mg[0] = 4; // Length
      rab_DiagRespBuffer_mg[4] = rb_p_t_tunnel_delay_g;
      break;
    case 0x152B: /*Tunnelausfahrt erkennen*/
      rab_DiagRespBuffer_mg[0] = 5; // Length
      rab_DiagRespBuffer_mg[4] = rb_p_n_regenlichtschwelle_low_high_g;
      rab_DiagRespBuffer_mg[5] = rb_p_n_regenlichtschwelle_Zeit_g;
      break;
    case 0x152C: /*Nachtbitschwellwert fur Regensensorempfindlichkteit*/
      rab_DiagRespBuffer_mg[0] = 4; // Length
      rab_DiagRespBuffer_mg[4] = rb_RainNightBitThrs_g;
      break;
    case 0x1519: /*Incidence Counter*/
      rab_DiagRespBuffer_mg[0] = 9; // Length
      rab_DiagRespBuffer_mg[4] = rb_IncidentCounter1_g;
      rab_DiagRespBuffer_mg[5] = rb_IncidentCounter2_g;
      rab_DiagRespBuffer_mg[6] = rb_IncidentCounter3_g;
      rab_DiagRespBuffer_mg[7] = rb_IncidentCounter4_g;
      rab_DiagRespBuffer_mg[8] = rb_IncidentCounter5_g;
      rab_DiagRespBuffer_mg[9] = rb_IncidentCounter6_g;
      break;
      
    case 0x151A: /*Parameter Rain-Sensor-Off*/
      rab_DiagRespBuffer_mg[0] = 5; // Length
      rab_DiagRespBuffer_mg[4] = (rb_intervaltime_rainSensorOff_g/10)|cab_SteigungGeradengleichung_mg[(l_u8_rd_WH_Intervallstufe()>>2)]; /*Intervallpausenzeit*/
      rab_DiagRespBuffer_mg[5] = cab_AchsenAbschnitt_mg[(l_u8_rd_WH_Intervallstufe()>>2)];
      break;
      
    case 0x1523: /*Valeo herstellerspezifisch Regensensorik*/
      rab_DiagRespBuffer_mg[0] = 25; // Length
      rab_DiagRespBuffer_mg[4] = rub_Ovr_Speicher;
      rab_DiagRespBuffer_mg[5] = rub_Int_Speicher;
      rab_DiagRespBuffer_mg[6] = rub_Empf_Faktor;
      rab_DiagRespBuffer_mg[7] = rb_PotiStageFromBox_g;
      rab_DiagRespBuffer_mg[8] = rb_RS_SigVoltage_g;
      rab_DiagRespBuffer_mg[9] = rub_Nachwisch_Count;
      rab_DiagRespBuffer_mg[10] = ruw_StX_Speicher>>8;
      rab_DiagRespBuffer_mg[11] = rub_LengthCounter;
      rab_DiagRespBuffer_mg[12] = rub_PulseCounter;
      rab_DiagRespBuffer_mg[13] = rub_SignalIntegral_g;
      rab_DiagRespBuffer_mg[14] = rb_CloseTypeStandby_g;
      if (rbi_HumTemp_Module_enabled_g == FALSE )
      {
        rab_DiagRespBuffer_mg[15] = 0;
        rab_DiagRespBuffer_mg[16] = 0;
        rab_DiagRespBuffer_mg[17] = 0;
        rab_DiagRespBuffer_mg[18] = 0;
      }
      else
      {
        rab_DiagRespBuffer_mg[15] = (byte)(rw_TempTicks_g>>8);
        rab_DiagRespBuffer_mg[16] = (byte)(rw_TempTicks_g&0xFF);
        rab_DiagRespBuffer_mg[17] = (byte)(rw_HumiTicks_g>>8);
        rab_DiagRespBuffer_mg[18] = (byte)(rw_HumiTicks_g&0xFF);
        
      }
      rab_DiagRespBuffer_mg[19] = rb_HumTemp_ErrorCode_g;
      rab_DiagRespBuffer_mg[20] = rb_StaticNoCommunicationCounter_g;
      rab_DiagRespBuffer_mg[21] = (byte)(rw_SPINoCommCounter_g>>8);
      rab_DiagRespBuffer_mg[22] = rb_SupplyVoltage_mg;
      rab_DiagRespBuffer_mg[23] = rb_WDGFastTaskCounterMin_g;
      rab_DiagRespBuffer_mg[24] = rb_WDGFastTaskCounterMax_g;
      rab_DiagRespBuffer_mg[25] = Diagnose_GetEEPROMValue(14);
      break;
    case 0x1522: /*Valeo herstellerspezifisch Lichtsensorik*/
      rab_DiagRespBuffer_mg[0] = 29; // Length
      rab_DiagRespBuffer_mg[4] = (byte)(get_rw_FW_light16bit_g()>>8);
      rab_DiagRespBuffer_mg[5] = (byte)(get_rw_FW_light16bit_g()&0xFF);
      rab_DiagRespBuffer_mg[6] = (byte)(get_rw_IR_light16bit_g()>>8);
      rab_DiagRespBuffer_mg[7] = (byte)(get_rw_IR_light16bit_g()&0xFF);
      rab_DiagRespBuffer_mg[8] = (byte)(get_rw_Amb_light16bit_g()>>8);
      rab_DiagRespBuffer_mg[9] = (byte)(get_rw_Amb_light16bit_g()&0xFF);
      rab_DiagRespBuffer_mg[10] = uF_modi_lightsens_g.AllBit | (rbi_night_g <<6);
      rab_DiagRespBuffer_mg[11] = (byte)(rw_Amb_Day_Threshold_g>>1); /*Overflow allowed*/
      rab_DiagRespBuffer_mg[12] = (byte)(rw_FW_Day_Threshold_g>>1); /*Overflow allowed*/
      rab_DiagRespBuffer_mg[13] = (byte)(rb_IR_Day_Threshold_g>>1); /*Overflow allowed*/
      rab_DiagRespBuffer_mg[14] = rb_Amb_Night_Threshold_g;
      rab_DiagRespBuffer_mg[15] = rb_FW_Night_Threshold_g;
      rab_DiagRespBuffer_mg[16] = rb_IR_Night_Threshold_g;
      rab_DiagRespBuffer_mg[17] = (byte)(rw_dayCounter_mg>>5);
      rab_DiagRespBuffer_mg[18] = (byte)(rw_nightCounter_mg>>5);
      rab_DiagRespBuffer_mg[19] = rb_LIN_BIT_ERROR_COUNTER_g;
      rab_DiagRespBuffer_mg[20] = rb_LIN_OVERTHEADERMAX_COUNTER_g;
      rab_DiagRespBuffer_mg[21] = rb_LIN_CHECKSUMERROR_COUNTER_g;
      rab_DiagRespBuffer_mg[22] = rb_LIN_OVERTFRAMEMAX_COUNTER_g;
      rab_DiagRespBuffer_mg[23] = rb_LIN_NORESPONSE_COUNTER_g;
      rab_DiagRespBuffer_mg[24] = rb_LIN_FRAMINGERROR_COUNTER_g;
      rab_DiagRespBuffer_mg[25] = 0;/*BRGC6;*//*Nabh*/
      rab_DiagRespBuffer_mg[26] = rb_E2_Sensor_Error1_g;
      rab_DiagRespBuffer_mg[27] = rb_E2_Sensor_Error2_g;
      rab_DiagRespBuffer_mg[28] = rb_E2_Sensor_Error3_g;
      rab_DiagRespBuffer_mg[29] = rb_E2_Sensor_Error4_g;
      break;
#endif      
    default:
      //Falsche Option /*/*RLS_VDR_268 same answer than for all other projects*/
      Diagnose_NegativeResponse(cb_READDATABYIDENTIFIER_s,cb_REQUEST_OUT_OF_RANGE_s); 
      break;
    }
    
  }
  
}
#endif



//---------------------------------------------------------------------------------------

  
/**************************************************************************
Syntax   : void  Diagnose_Read_SteuergIdent(void)
Object   : Diagnose_Read_SteuergIdent()
Parameters : none
Return  : none
Calls   : in RLS_LINST.c from ApplLinSlaveCmdFrmFct()
***************************************************************************
Inputs validation conditions:
none
***************************************************************************
Pseudo-code : Answers with the Sensornumber Softwareversion and Partnumber,
Coding Values
**************************************************************************/



#ifdef _SUPPORTSERVICE1A_
byte Diagnose_Read_SteuergIdent(void) //Dienst 1A9B
{
  //Local Variable Declaration
  byte rb_ReturnValue_l;
  rb_ReturnValue_l = 1;

  
  l_u8_wr_SlaveRespB1(0x20|(rb_Diagnosticstate_g & 0x0F));    //response with multiple Frames with sequence number
  
  rb_Diagnosticstate_g++;                                     //increase diagnostic state
  l_u8_wr_SlaveRespB0(l_u8_rd_MasterReqB0());
  
 SetSystemBezeichnung();
  switch(rb_Diagnosticstate_g-1)                             //Switch and write the answer message
  {
  case 0:                                                 //First answer
    l_u8_wr_SlaveRespB1(0x10);                            //first response with multiple Frames
    l_u8_wr_SlaveRespB2(48);                              //data lenght inclusive SID
    l_u8_wr_SlaveRespB3(cb_POSITIVE_IDENT_RESPONSE_s);    //Positive Response Ident
    l_u8_wr_SlaveRespB4(cb_IDENT_OPT_SGIDENT_s);          //Identification option steuergerate ID
    l_u8_wr_SlaveRespB5(rab_Audi_HW_Partnumber_g(0));        //SEAT Partnumber 0-3
    l_u8_wr_SlaveRespB6(rab_Audi_HW_Partnumber_g(1));
    l_u8_wr_SlaveRespB7(rab_Audi_HW_Partnumber_g(2));
    rb_Diagnosticstate_g = 1;
    break;
  case 1:
    l_u8_wr_SlaveRespB2(Diagnosis_BCDtoASCII(rab_Audi_HW_Partnumber_g(3)>>4));        //SEAT Partnumber 3-8
    l_u8_wr_SlaveRespB3(Diagnosis_BCDtoASCII(rab_Audi_HW_Partnumber_g(3)&0x0F));
    l_u8_wr_SlaveRespB4(Diagnosis_BCDtoASCII(rab_Audi_HW_Partnumber_g(4)>>4));
    l_u8_wr_SlaveRespB5(Diagnosis_BCDtoASCII(rab_Audi_HW_Partnumber_g(4)&0x0F));
    l_u8_wr_SlaveRespB6(Diagnosis_BCDtoASCII(rab_Audi_HW_Partnumber_g(5)>>4));
    l_u8_wr_SlaveRespB7(Diagnosis_BCDtoASCII(rab_Audi_HW_Partnumber_g(5)&0x0F));
    break;
  case 2:        //Third answer
    l_u8_wr_SlaveRespB2(rab_Audi_HW_Partnumber_g(6));       //SEAT Partnumber 9-10
    l_u8_wr_SlaveRespB3(rab_Audi_HW_Partnumber_g(7));
    l_u8_wr_SlaveRespB4(cb_ASCI_Blank_s);               //Write ASCI blank
    l_u8_wr_SlaveRespB5(rab_SoftwareStand_g(0));       //Software Version 0-1
    l_u8_wr_SlaveRespB6(rab_SoftwareStand_g(1));
    l_u8_wr_SlaveRespB7((rab_SoftwareStand_g(2)>>4) +'0');           //Data Version 0
    break;
  case 3:                                               //Third answer
    // Codierwerte Schreiben !
    l_u8_wr_SlaveRespB2((rab_SoftwareStand_g(2)&0x0F)+'0');           //Data Version 1
    l_u8_wr_SlaveRespB3(cb_CODIERTABELLE_s);            //Number of Codingtable
    //Coding of Function BITs
    
    
    l_u8_wr_SlaveRespB4(rb_Kodierbyte0_g);               //Coding Value 1
    l_u8_wr_SlaveRespB5(rb_Kodierbyte1_g);               //Coding Value 2
    l_u8_wr_SlaveRespB6(rb_Kodierbyte2_g);               //Coding value 3
    l_u8_wr_SlaveRespB7(0x00);                          //cab_WerkstattIdent_g (0x00)
    
    break;
  case 4:                                               //fourth answer
    l_u8_wr_SlaveRespB2(0x00);                          //cab_WerkstattIdent_g (0x00)
    l_u8_wr_SlaveRespB3(0x00);
    l_u8_wr_SlaveRespB4(0x00);
    l_u8_wr_SlaveRespB5(0x00);
    l_u8_wr_SlaveRespB6(0x00);
    l_u8_wr_SlaveRespB7(pb_Systembezeichnung_mg[0]);      //System Name 0
    break;
  case 5:                                               //5th answer
    l_u8_wr_SlaveRespB2(pb_Systembezeichnung_mg[1]);      //System Name 1-6
    l_u8_wr_SlaveRespB3(pb_Systembezeichnung_mg[2]);
    l_u8_wr_SlaveRespB4(pb_Systembezeichnung_mg[3]);
    l_u8_wr_SlaveRespB5(pb_Systembezeichnung_mg[4]);
    l_u8_wr_SlaveRespB6(pb_Systembezeichnung_mg[5]);
    l_u8_wr_SlaveRespB7(pb_Systembezeichnung_mg[6]);
    break;
  case 6:                                               //6th answer
    l_u8_wr_SlaveRespB2(pb_Systembezeichnung_mg[7]);      //System Name 7-12
    l_u8_wr_SlaveRespB3(pb_Systembezeichnung_mg[8]);
    l_u8_wr_SlaveRespB4(pb_Systembezeichnung_mg[9]);
    l_u8_wr_SlaveRespB5(pb_Systembezeichnung_mg[10]);
    l_u8_wr_SlaveRespB6(pb_Systembezeichnung_mg[11]);
    l_u8_wr_SlaveRespB7(pb_Systembezeichnung_mg[12]);
    break;
  case 7:                                               //8th answer
    l_u8_wr_SlaveRespB2(pb_Systembezeichnung_mg[13]);     //System Name 13-18
    l_u8_wr_SlaveRespB3(pb_Systembezeichnung_mg[14]);
    l_u8_wr_SlaveRespB4(pb_Systembezeichnung_mg[15]);
    l_u8_wr_SlaveRespB5(cb_HARDWARESTAND_g);
    l_u8_wr_SlaveRespB6(rab_HardwareStand_g(0));
    l_u8_wr_SlaveRespB7(rab_HardwareStand_g(1));
    break;
  case 8:                                              //9th answer
    Diagnose_clear_Answer_Message();
    l_u8_wr_SlaveRespB2(cb_ASCI_Blank_s);               //ASCI blank
    //Block Answer of next Request  (Use only when sending without Diagnoes_TP!!!)
    l_u8_rd_MasterReqB0() = cb_OTHER_TARGET_ADDRESS_s;            
    break;
  default:                                               //Default (Wrong Case)
    // negative Antwort auf Diagnoserequest
    Diagnose_NegativeResponse(cb_WRITE_DATA_BY_LOC_ID_s,cb_REQUEST_OUT_OF_RANGE_s);
    rb_ReturnValue_l = 0;
    break;
  }
  return (rb_ReturnValue_l);
}
#endif

/**************************************************************************
Syntax   : void  Diagnose_Send_EEPROM(void)
Object   : Diagnose_Send_EEPROM()
Parameters : none
Return  : none
Calls   : in RLS_LINST.c from ApplLinSlaveCmdFrmFct()
***************************************************************************
Inputs validation conditions:
none
***************************************************************************
Pseudo-code : Sends the EEPROM Datas on the LIN bus based on the
requested adress
**************************************************************************/
static __callt void Diagnose_Send_EEPROM(void)
{
  byte rb_BytesToCopy_l;
  byte rb_Index_l;
  
  
  rab_DiagRespBuffer_mg[1] = cb_ANSWER_TRANSMISSION_s;
  
  if (rb_I2CEEPROMCMDbytesToWrite_g >=5)
  {
    rb_BytesToCopy_l = 5;
    rab_DiagRespBuffer_mg[0] = 6;
  }
  else
  {
    rb_BytesToCopy_l = rb_I2CEEPROMCMDbytesToWrite_g;
    rab_DiagRespBuffer_mg[0] = rb_BytesToCopy_l+1;
  }
  
  
  if (rb_BytesToCopy_l > 0)
  {
    rb_ResponseToSend_g = 1;
    rb_Diagnosticstate_g = 1;
    
    rb_I2CEEPROMCMDbytesToWrite_g -= rb_BytesToCopy_l;
    
    rb_Index_l = 2;
    rb_BytesToCopy_l++;
    
    while (rb_Index_l <= rb_BytesToCopy_l)
    {
      rab_DiagRespBuffer_mg[rb_Index_l] = Diagnose_GetEEPROMValue(rw_DiagnoseEEPROM_Address_mg);
      rw_DiagnoseEEPROM_Address_mg++;
      rb_Index_l++;
    }
  }
  else if (rb_Diagnosticstate_g == 0)
  {
    rb_Diagnosticstate_g = 1;
    rb_ResponseToSend_g = 1;
  }
  else
  {
    rb_ResponseToSend_g = 0;
  }
  
}


/**************************************************************************
Syntax   : void  Diagnose_Read_SteuergIdent(void)
Object   : Diagnose_Read_SteuergIdent()
Parameters : none
Return  : none
Calls   : in RLS_LINST.c from ApplLinSlaveCmdFrmFct()
***************************************************************************
Inputs validation conditions:
none
***************************************************************************
Pseudo-code : Answers with the Sensornumber Softwareversion and Partnumber,
Coding Values
**************************************************************************/

#ifdef _SUPPORTSERVICE21_
void Diagnose_ReadDataByLocalID(void)
{
  //Local Variable Declaration
  
  byte rb_MW_Block_s;
  byte rb_EEPROMAddress_s;
  
  if(l_u8_rd_MasterReqB1() == cb_REQLENGTHSID21_s)
    
  {
    rb_MW_Block_s = l_u8_rd_MasterReqB3();
    if(rb_MW_Block_s < cb_NUMBER_OF_MW_BLOCKS_s)
    {
      rb_EEPROMAddress_s = rb_MW_Block_s << 2;
      if(rb_MW_Block_s >= 16)
      {
        rb_EEPROMAddress_s = 64 + rb_EEPROMAddress_s; // add offsett for EEPROM adress;
      }
      
      rab_DiagRespBuffer_mg[0] = 14; // Length
      rab_DiagRespBuffer_mg[1] = cb_READ_DATA_BY_LOCAL_IDENT_s+0x40;
      rab_DiagRespBuffer_mg[2] = rb_MW_Block_s;
      rab_DiagRespBuffer_mg[3] = cb_RDBLID_FORMEL_g;
      rab_DiagRespBuffer_mg[4] = cb_RDBLID_NORMIERWERT_g;
      rab_DiagRespBuffer_mg[5] = Diagnose_GetEEPROMValue(rb_EEPROMAddress_s);
      rb_EEPROMAddress_s++;
      rab_DiagRespBuffer_mg[6] = cb_RDBLID_FORMEL_g;
      rab_DiagRespBuffer_mg[7] = cb_RDBLID_NORMIERWERT_g;
      rab_DiagRespBuffer_mg[8] = Diagnose_GetEEPROMValue(rb_EEPROMAddress_s);
      rb_EEPROMAddress_s++;
      rab_DiagRespBuffer_mg[9] = cb_RDBLID_FORMEL_g;
      rab_DiagRespBuffer_mg[10] = cb_RDBLID_NORMIERWERT_g;
      rab_DiagRespBuffer_mg[11] = Diagnose_GetEEPROMValue(rb_EEPROMAddress_s);
      rb_EEPROMAddress_s++;
      rab_DiagRespBuffer_mg[12] = cb_RDBLID_FORMEL_g;
      rab_DiagRespBuffer_mg[13] = cb_RDBLID_NORMIERWERT_g;
      rab_DiagRespBuffer_mg[14] = Diagnose_GetEEPROMValue(rb_EEPROMAddress_s);
    }
    else
    {
      Diagnose_NegativeResponse(cb_READ_DATA_BY_LOCAL_IDENT_s,cb_REQUEST_OUT_OF_RANGE_s);
    }
  }
  
  else
  {
    
    Diagnose_NegativeResponse(cb_READ_DATA_BY_LOCAL_IDENT_s,cb_INCORECTMESSAGELENGTH_s);
    
  }
  
}
#endif

/**************************************************************************
Syntax   : void  Diagnose_GetEEPROMValue(void)
Object   : Diagnose_GetEEPROMValue()
Parameters : rb_VariableToSend_l Address to read from ROM or RAM
Return  : Parameter from ROM or RAM
Calls   : in Diagnose.c from Diagnose_Send_EEPROM()
***************************************************************************
Inputs validation conditions:
none
***************************************************************************
Pseudo-code : Returns the byte according the Adress the variables are RAM
bytes
**************************************************************************/

static __callt byte Diagnose_GetEEPROMValue(word rw_VariableToSend_l)
{
  //Local Variable Declaration
  byte rb_DatenOutput_l;  //-byte to store the aoutput data
  byte __far* pb_PointerAddress_mg;
  
  if((rw_VariableToSend_l >= 0xEF00U) && (rw_VariableToSend_l < 0xFEDFU)) /* RAM area selected*/    
  {
    pb_PointerAddress_mg = ((unsigned char __far *)((unsigned long)rw_VariableToSend_l + 0xF0000U));   /*  read data from RAM 0xFEF00h - 0xFFEDFh*/
    rb_DatenOutput_l = *pb_PointerAddress_mg;
  }

  else
  {
    switch(rw_VariableToSend_l)                          //Switch with input (adress) variable
    {
    case 0:                                            
      rb_DatenOutput_l = (byte) (get_rw_FW_light16bit_g() >> 8); /* High Byte */
      break;
    case 1:                                           
      rb_DatenOutput_l = (byte) (get_rw_FW_light16bit_g() ); /* Low Byte */
      break;
    case 2:                                            
      rb_DatenOutput_l = (byte) (get_rw_FW_INC_light16bit_g() >> 8); /* High Byte */
      break;
    case 3:                                           
      rb_DatenOutput_l = (byte) (get_rw_FW_INC_light16bit_g() ); /* Low Byte */
      break;
    case 4:                                             
      rb_DatenOutput_l = (byte) (get_rw_IR_light16bit_g() >> 8); /* High Byte */
      break;
    case 5:                                            
      rb_DatenOutput_l = (byte) (get_rw_IR_light16bit_g() ); /* Low Byte */
      break;
    case 6:                                             
      rb_DatenOutput_l = (byte) (get_rw_IR_INC_light16bit_g() >> 8); /* High Byte */
      break;
    case 7:                                            
      rb_DatenOutput_l = (byte) (get_rw_IR_INC_light16bit_g() ); /* Low Byte */
      break;
    case 8:
      rb_DatenOutput_l = (byte) (get_rw_Amb_light16bit_g() >> 8); /* High Byte */
      break;
    case 9:
      rb_DatenOutput_l = (byte) (get_rw_Amb_light16bit_g() );  /* Low Byte */
      break;
    case 10:
      rb_DatenOutput_l = (byte) (get_rw_Amb_INC_light16bit_g() >> 8); /* High Byte */
      break;
    case 11:
      rb_DatenOutput_l = (byte) (get_rw_Amb_INC_light16bit_g() );  /* Low Byte */
      break;
    case 12:                             
      rb_DatenOutput_l = (byte) (rw_Solar_light16bit_1_g >> 8) ;  /* ALS1 - looking to the right: driver side */  
      break;
    case 13:                                             
      rb_DatenOutput_l = (byte) (rw_Solar_light16bit_1_g );   /* Low Byte */           
      break;
    case 14:                                             
      rb_DatenOutput_l = (byte) (rw_Solar_light16bit_2_g >> 8); /* ALS6 - looking to the left: passenger side */  
      break;
    case 15:                                             
      rb_DatenOutput_l = (byte) (rw_Solar_light16bit_2_g );    /* Low Byte */
      break;
    case 16:                                            
      rb_DatenOutput_l = (byte) (get_rw_ALS1_ASIC_g() >> 8); /* High Byte */
      break;
    case 17:                                           
      rb_DatenOutput_l = (byte) (get_rw_ALS1_ASIC_g());    /* Low Byte */
      break;
    case 18:                                          
      rb_DatenOutput_l = (byte) (get_rw_ALS2_ASIC_g() >> 8); /* High Byte */
      break;
    case 19:
      rb_DatenOutput_l = (byte) (get_rw_ALS2_ASIC_g() ); /* Low Byte */
      break;
    case 20:                                            
      rb_DatenOutput_l = (byte) (get_rw_ALS2_INC_ASIC_g() >> 8); /* High Byte */
      break;
    case 21:
      rb_DatenOutput_l = (byte) (get_rw_ALS2_INC_ASIC_g() ); /* Low Byte */
      break;
    case 22:
      /*ALS3, ALS4 are not connected*/
      rb_DatenOutput_l = 0x3; /*(byte) (get_rw_ALS3_ASIC_g() >> 8); *//* High Byte */
      break;
    case 23:
      /*ALS3, ALS4 are not connected*/
      rb_DatenOutput_l = 0xFF; /*(byte) (get_rw_ALS3_ASIC_g() ); *//* Low Byte */
      break;
    case 24:
      /*ALS3, ALS4 are not connected*/
      rb_DatenOutput_l = 0x3; /*(byte) (get_rw_ALS4_ASIC_g() >> 8); *//* High Byte */
      break;
    case 25:
      /*ALS3, ALS4 are not connected*/
      rb_DatenOutput_l = 0xFF; /*(byte) (get_rw_ALS4_ASIC_g() ); *//* Low Byte */
      break;
    case 26:
      /*ALS3, ALS4 are not connected*/
      rb_DatenOutput_l = 0x3; /*(byte) (get_rw_ALS4_INC_ASIC_g() >> 8); *//* High Byte */
      break;
    case 27:
      /*ALS3, ALS4 are not connected*/
      rb_DatenOutput_l = 0xFF; /*(byte) (get_rw_ALS4_INC_ASIC_g() ); *//* Low Byte */
      break;
    case 28:
      rb_DatenOutput_l = (byte) (get_rw_ALS5_ASIC_g() >> 8); /* High Byte */
      break;
    case 29:
      rb_DatenOutput_l = (byte) (get_rw_ALS5_ASIC_g() ); /* Low Byte */
      break;
    case 30:
      rb_DatenOutput_l = (byte) (get_rw_ALS5_INC_ASIC_g() >> 8); /* High Byte */
      break;
    case 31:
      rb_DatenOutput_l = (byte) (get_rw_ALS5_INC_ASIC_g() ); /* Low Byte */
      break;
    case 32:
      rb_DatenOutput_l = (byte) (get_rw_ALS6_ASIC_g() >> 8); /* High Byte */
      break;
    case 33:
      rb_DatenOutput_l = (byte) (get_rw_ALS6_ASIC_g() ); /* Low Byte */
      break;
    case 34:
      rb_DatenOutput_l = (byte) (get_rw_INREC_ASIC_g() >> 8); /* High Byte */
      break;
    case 35:
      rb_DatenOutput_l = (byte) (get_rw_INREC_ASIC_g() ); /* Low Byte */
      break;
    case 36:
      rb_DatenOutput_l = (byte) (get_rw_INREC_INC_ASIC_g() >> 8); /* High Byte */
      break;
    case 37:
      rb_DatenOutput_l = (byte) (get_rw_INREC_INC_ASIC_g() ); /* Low Byte */
      break;
    case 38:
      rb_DatenOutput_l = uF_modi_lightsens_g.AllBit|(rbi_Regulation48LightOnFlag_g <<3);
      break;
    case 39:
      rb_DatenOutput_l = uF_modi_lightsens_inv_g.AllBit;
      break;
    case 40:
      rb_DatenOutput_l = rb_SupplyVoltage_mg;
      break;
    case 41:
      rb_DatenOutput_l = (byte)(rw_CDIV256_period_g >> 8); /* High Byte */
      break;
    case 42:
      rb_DatenOutput_l = (byte)(rw_CDIV256_period_g); /* Low Byte */
      break;
    case 43:
      rb_DatenOutput_l = (byte)rb_ASIC_TRIM_Reg_g;
      break;
    case 44:
      rb_DatenOutput_l = (byte)(rw_REGV_Voltage_g >> 8); /* High Byte */
      break;
    case 45:
      rb_DatenOutput_l = (byte) (rw_REGV_Voltage_g );
      break;
    case 46:                                            
      rb_DatenOutput_l = (rbi_RainSensorError|((bi_ROM_CHECK_FAILURE_g > 0)<<1)|(bi_RAM_CHECK_FAILURE_g<<2)
                          |(rbi_Check_LS_NoCommunication_g<<3)|(rbi_LightSensorError_g<<4)|
                            ((uF_ASIC_Error_Flags_g.AllBit>0)<<6));
      
      break;
    case 47:                                             
      rb_DatenOutput_l = rb_EEPROMErrFlag_g;
      break;
    case 48:                                             
      rb_DatenOutput_l = rw_DiagnoseStepResponseAnswer_g; 
      break;
    case 49:                                             
      rb_DatenOutput_l = rb_WDGFastTaskCounterMax_g;
      break;
    case 50:
      rb_DatenOutput_l = rub_LengthCounter;
      break;
    case 51:
      rb_DatenOutput_l = rub_PulseCounter;
      break;
    case 52:
      rb_DatenOutput_l = rw_dayCounter_mg;
      break;
    case 53:
      rb_DatenOutput_l = rw_nightCounter_mg;
      break;
    case 54:
      /*VDR_847 rb_ASICGainSetup_g send with the diag pulse command*/
      rb_DatenOutput_l = rb_ASICGainSetup_g;
      break;
    case 55:
      rb_DatenOutput_l = rub_Ovr_Speicher;
      break;
    case 56:
      rb_DatenOutput_l = rub_Int_Speicher;
      break;
    case 57:
      rb_DatenOutput_l = (byte) (rw_RAM_DefectCell_g >> 8);
      break;
    case 58:
      rb_DatenOutput_l = (byte) (rw_RAM_DefectCell_g ); 
      break;
    case 59:
      rb_DatenOutput_l = bi_FIRST_RAM_CHECK_DONE_g | (bi_First_ROM_CHECK_Done_g<<1); 
      break;
    case 60:
      rb_DatenOutput_l = rb_LastLINErrorCode_g;
      break;
    case 61:
      rb_DatenOutput_l = rub_Empf_Faktor;
      break;
    case 62:
      rb_DatenOutput_l = rb_PotiStageFromBox_g ; 
      break;
    case 63:
#ifdef _ONETIME_OR_DOUBLE_OVERWIPED_ 
      rb_DatenOutput_l = (rbi_night_g) | ((rbi_DoubleOverwiped)<<1) ;
      rb_DatenOutput_l |= ((rbi_ButterflyIsEquipped)<<2);
#else
      rb_DatenOutput_l = rbi_night_g; 
#endif

      break;
    case 64:
      rb_DatenOutput_l = rb_FW_Night_Threshold_g; 
      break;
    case 65:
      rb_DatenOutput_l = rb_IR_Night_Threshold_g; 
      break;
    case 66:
      rb_DatenOutput_l = rb_FW_NightLow_Threshold_g;
      break;
    case 67:
      rb_DatenOutput_l =  rb_IR_NightLow_Threshold_g ;
      break;
    case 68:
      rb_DatenOutput_l = rb_IR_Day_Threshold_g;
      break;
    case 69:
      rb_DatenOutput_l = rb_IR_DayHigh_Threshold_g;
      break;
    case 70:
      rb_DatenOutput_l = (byte)((rw_FW_DayHigh_Threshold_g>255)? 255: rw_FW_DayHigh_Threshold_g); 
      break;
    case 71:
      rb_DatenOutput_l = (byte)((rw_FW_Day_Threshold_g>255)? 255: rw_FW_Day_Threshold_g); 
      break;
    case 72:
      rb_DatenOutput_l = uF_ASIC_Error_Flags_g.AllBit;
      break;
    case 73:
      rb_DatenOutput_l = rb_RS_SigVoltage_g;
      break;
    case 74:
      rb_DatenOutput_l = rub_SignalIntegral_g;
      break;
    case 75:
      /*VDR_847 rb_ASICGainSetup_g send with the diag pulse command*/
      rb_DatenOutput_l = rb_IrLightTunnelThreshDyn_g;
      break;
    case 76:
      rb_DatenOutput_l = rb_EEPROM_Status_g; 
      break;
    case 77:
      rb_DatenOutput_l = rb_EraseStatus_g;              
      break;
    case 78:
      rb_DatenOutput_l = rb_ASICGainSetup_g;
      break;
    case 79:
      rb_DatenOutput_l = cb_SWSTANDEEPROM_23_g ;
      break;
    case 80:
      rb_DatenOutput_l = cb_SWSTAND_ADD_ON_g;
      break;
    case 81:
      rb_DatenOutput_l = (byte)(rw_StandbyTimeOutCnt_g & 0xFF);
      break;
    case 82:
      rb_DatenOutput_l = rb_CloseTypeStandby_g ;
      break;
    case 83:
      rb_DatenOutput_l = get_rb_LightSignalErrorCnt_g() ;
      break;
    case 84:
      rb_DatenOutput_l = get_rb_MaxLightSignalErrorCnt_g() ;
      break;
    case 85:
      rb_DatenOutput_l = uF_Main_Flags_g.AllBit;
      break;
    case 86:
      rb_DatenOutput_l = get_rb_VDD_LightSignalErrorCnt_g();
      break;
    case 87:
      rb_DatenOutput_l = rb_AfterVddPowerFailDelay_g;
      break;
    case 88:
      rb_DatenOutput_l = rb_LIN_BIT_ERROR_COUNTER_g;
      break;
    case 89:
      rb_DatenOutput_l = rb_LIN_OVERTHEADERMAX_COUNTER_g;
      break;
    case 90:
      rb_DatenOutput_l = rb_LIN_CHECKSUMERROR_COUNTER_g;
      break;
    case 91:
      rb_DatenOutput_l = rb_LIN_OVERTFRAMEMAX_COUNTER_g;
      break;
    case 92:
      rb_DatenOutput_l = rb_LIN_NORESPONSE_COUNTER_g;
      break;
    case 93:
      rb_DatenOutput_l = rb_LIN_FRAMINGERROR_COUNTER_g;
      break;
    case 94:
      rb_DatenOutput_l =  rb_StaticNoCommunicationCounter_g;
      break;
    case 95:
      rb_DatenOutput_l = (byte)(rw_SPINoCommCounter_g>>8);
      break;
    case 96:
      rb_DatenOutput_l = rb_SPI_Active_ProblemCounter_g; 
      break;
    case 97:
      rb_DatenOutput_l = rb_StaticNoValidAD_cnt_g;
      break;
    case 98:
      rb_DatenOutput_l = rb_FreqNotTrimmedCounter_g;
      break;
    case 99:
      rb_DatenOutput_l = get_rb_ASICReg_NoValidVals_cnt_g();
      break;
    case 100:
      rb_DatenOutput_l = (byte) (UF0CTL1 >> 8); /*LIN baud rate */  /* High Byte */
      break;
    case 101:
      rb_DatenOutput_l = (byte) (UF0CTL1); /* Low Byte */
      break;      
    case 102:
      rb_DatenOutput_l = get_rb_LightVetoCounter_g();
      break;
    case 103:
      rb_DatenOutput_l = rb_WipeCounter_g;
      break;
    case 104:
      rb_DatenOutput_l = uF_LightInternalStatus_g.AllBit ;
      break;
    case 105:
      rb_DatenOutput_l = rb_HumTemp_ErrorCode_g; 
      break;
    case 106:
      rb_DatenOutput_l = HumTemp_GetHeaterStatus();
      break;
    case 107:
      rb_DatenOutput_l = rb_StaticHumTempErrorCounter_g ;
      break;
    case 108:
      rb_DatenOutput_l = (byte)((rw_InErrorModeCounter_s*20)/111); /* counter incremented at every 1sec*/
      break;
    case 109:
      rb_DatenOutput_l = (byte)(rw_Temperature_g>>8); /* High Byte */
      break;
    case 110:
      rb_DatenOutput_l = (byte)(rw_Temperature_g); /* Low Byte */
      break;
    case 111:
      rb_DatenOutput_l = (byte)(rb_Humidity_g); /* with dynamic compensated */
      break;      
    case 112:
      rb_DatenOutput_l = (byte)(rb_Humidity_raw_g ); /* without dynamic compensated */
      break;
    case 113:
      rb_DatenOutput_l = (byte)(rw_DewPoint_g>>8); /* High Byte */
      break;
    case 114:
      rb_DatenOutput_l = (byte)(rw_DewPoint_g);  /* Low Byte */
      break;
    case 115:
      rb_DatenOutput_l = (byte)(rw_VRSI_ASIC_g>>8); /* High Byte */
      break;                          
    case 116:
      rb_DatenOutput_l = (byte)(rw_VRSI_ASIC_g); /* Low Byte */
      break;
    case 117:
      rb_DatenOutput_l = (byte)(rw_VLEDA_ASIC_g>>8) ; /* High Byte */
      break;
    case 118:
      rb_DatenOutput_l = (byte)(rw_VLEDA_ASIC_g); /* Low Byte */
      break;
    case 119:
      rb_DatenOutput_l = (byte)(rw_VLEDB_ASIC_g>>8); /* High Byte */
      break;                          
    case 120:
      rb_DatenOutput_l = (byte)(rw_VLEDB_ASIC_g); /* Low Byte */
      break;
    case 121:
      rb_DatenOutput_l = (byte)(rw_VTEMP_ASIC_g>>8); /* High Byte */
      break;
    case 122: 
      rb_DatenOutput_l = (byte)(rw_VTEMP_ASIC_g); /* Low Byte */
      break; 
    case 123:
      rb_DatenOutput_l =  (byte)(rw_Vref_ASIC_g>>8);  /* High Byte */
      break;
    case 124:
      rb_DatenOutput_l =  (byte)(rw_Vref_ASIC_g);  /* Low Byte */
      break;
    case 125:
      rb_DatenOutput_l = (byte)(rw_VIrefLo_ASIC_g>>8); /* High Byte */
      break;
    case 126:
      rb_DatenOutput_l = (byte)(rw_VIrefLo_ASIC_g); /* Low Byte */
      break;
    case 127:
      rb_DatenOutput_l = (byte)(rw_VIrefHi_ASIC_g>>8); /* High Byte */
      break;
    case 128:
      rb_DatenOutput_l = (byte)(rw_VIrefHi_ASIC_g); /* Low Byte */
      break;
    case 129:
      rb_DatenOutput_l = (byte)(rw_VDDA_ASIC_g>>8); /* High Byte */
      break;
    case 130:
      rb_DatenOutput_l = (byte)(rw_VDDA_ASIC_g); /* Low Byte */
      break;
    case 131:
      rb_DatenOutput_l =  (byte)(rw_VDDD_ASIC_g>>8); /* High Byte */
      break;
    case 132:
      rb_DatenOutput_l =  (byte)(rw_VDDD_ASIC_g); /* Low Byte */
      break;
    case 133:
      rb_DatenOutput_l = (byte)(get_rw_VILO_IHI_GLO_ASIC_g()>>8); /* High Byte */
      break;
    case 134:
      rb_DatenOutput_l = (byte)(get_rw_VILO_IHI_GLO_ASIC_g()); /* Low Byte */
      break;
    case 135:
      rb_DatenOutput_l =  (byte)(get_rw_VIHI_ILO_GLO_ASIC_g()>>8); /* High Byte */
      break;
    case 136:
      rb_DatenOutput_l = (byte)(get_rw_VIHI_ILO_GLO_ASIC_g()); /* Low Byte */
      break;
    case 137:
      rb_DatenOutput_l = (byte)(get_rw_VILO_ICALLO_GHI_ASIC_g()>>8); /* High Byte */
      break;
    case 138:
      rb_DatenOutput_l =  (byte)(get_rw_VILO_ICALLO_GHI_ASIC_g()); /* Low Byte */
      break;
    case 139:
      rb_DatenOutput_l = (byte)(get_rw_VIHI_ICALHI_GHI_ASIC_g()>>8); /* High Byte */
      break;
    case 140:
      rb_DatenOutput_l = (byte)(get_rw_VIHI_ICALHI_GHI_ASIC_g()); /* Low Byte */
      break;      
    case 141:
      rb_DatenOutput_l = (byte)(get_rw_VICALLO_ILO_GHI_ASIC_g()>>8); /* High Byte */
      break;
    case 142:
      rb_DatenOutput_l = (byte)(get_rw_VICALLO_ILO_GHI_ASIC_g()); /* Low Byte */
      break; 
    case 143:
      rb_DatenOutput_l = (byte)(get_rw_VICALHI_IHI_GHI_ASIC_g()>>8); /* High Byte */
      break;
    case 144:
      rb_DatenOutput_l = (byte)(get_rw_VICALHI_IHI_GHI_ASIC_g()); /* Low Byte */
      break;  
    case 145:
      rb_DatenOutput_l = (byte)(get_rw_VILO_IHI_GLO_INC_ASIC_g()>>8); /* High Byte */
      break;
    case 146:
      rb_DatenOutput_l = (byte)(get_rw_VILO_IHI_GLO_INC_ASIC_g()); /* Low Byte */
      break;
    case 147:
      rb_DatenOutput_l = (byte)(get_rw_VIHI_ILO_GLO_INC_ASIC_g()>>8); /* High Byte */
      break;
    case 148:
      rb_DatenOutput_l = (byte)(get_rw_VIHI_ILO_GLO_INC_ASIC_g()); /* Low Byte */
      break;      
    case 149:
      rb_DatenOutput_l = (byte)(get_rw_VIHI_ICALHI_GHI_INC_ASIC_g()>>8); /* High Byte */
      break;
    case 150:
      rb_DatenOutput_l = (byte)(get_rw_VIHI_ICALHI_GHI_INC_ASIC_g()); /* Low Byte */
      break;       
    case 151:
      rb_DatenOutput_l = (byte)(get_rw_VICALHI_IHI_GHI_INC_ASIC_g()>>8); /* High Byte */
      break;
    case 152:
      rb_DatenOutput_l = (byte)(get_rw_VICALHI_IHI_GHI_INC_ASIC_g()); /* Low Byte */
      break; 
    case 153:
      rb_DatenOutput_l = 0; /*(byte)(rw_VILO_ICALLO_GHI_INC_ASIC_g>>8);*/ /* High Byte */
      break;
    case 154:
      rb_DatenOutput_l = 0; /*(byte)(rw_VILO_ICALLO_GHI_INC_ASIC_g);*/
      break;       
    case 155:
      rb_DatenOutput_l = rb_STATH_Reg_g;
      rb_STATH_Reg_g = 0; /* Reset the status after read. other wise status shall have accumulated information */
      break;  
    case 156:
      rb_DatenOutput_l = rb_STATL_Reg_g;
      rb_STATL_Reg_g = 0; /* Reset the status after read. other wise status shall have accumulated information */
      break; 
    case 157:
      /*VC0_213 Pulse counter sent also at addr 157 to be read together with length counter (for Rain sensor sensitivity test)*/
      rb_DatenOutput_l = rub_PulseCounter;
      break; 
    case 158:
      rb_DatenOutput_l = rb_InternalTemperature_g;
      break; 
    case 159:
      rb_DatenOutput_l = rub_LengthCounterHB;
      break; 
    case 160:
      rb_DatenOutput_l = rub_LengthCounter;
      break; 
    case 161:
      rb_DatenOutput_l = rb_880nm_Transmission_g;
      break;       
    case 162:
      rb_DatenOutput_l = rb_550nm_Transmission_g;
      break;   
    case 163:
      rb_DatenOutput_l = rb_Si_Transmission_g;
      break;
    case 164:
      rb_DatenOutput_l = rb_ASIC_ID_g[0];
      break;
    case 165:
      rb_DatenOutput_l = rb_ASIC_ID_g[1];
      break;
    case 166:
      rb_DatenOutput_l = rb_ASIC_ID_g[2];
      break;
    case 167:
      rb_DatenOutput_l = (byte) ((word)((rw_EEPROMPointer_g[cb_AREA_PD_g])&(0x3ff))>>2); 
      break;
    case 168:
      rb_DatenOutput_l = (byte) ((word)((rw_EEPROMPointer_g[cb_AREA_AD_g])&(0x3ff))>>2); 
      break;
    case 169:
      rb_DatenOutput_l = (byte) ((word)((rw_EEPROMPointer_g[cb_AREA_RD_g])&(0x3ff))>>2); 
      break;
    case 170:
      rb_DatenOutput_l = (byte)rb_ClusterStatus_mg[0]; 
      break;
    case 171:
      rb_DatenOutput_l = (byte)rb_ClusterStatus_mg[1]; 
      break;
    case 172:
      rb_DatenOutput_l = (byte)rb_ClusterStatus_mg[2]; 
      break;
    case 173:
      rb_DatenOutput_l = (byte)rb_ClusterStatus_mg[3]; 
      break;
    case 174:
      rb_DatenOutput_l = (byte)uF_E2ConfigErrorFlags_g.AllBit; 
      break;
/*if the rain functionality is enabled*/
#ifndef _NO_RAIN_

    case 175:
      rb_DatenOutput_l = rb_RainMeas_cnt_total_g; 
      break;
    case 176:
      rb_DatenOutput_l = rb_RainMeas_cnt_min_g; 
      break;
    case 177:
      rb_DatenOutput_l = rb_RainMeas_cnt_max_g; 
      break;
    case 178:
      rb_DatenOutput_l = rb_LClosed_dur_total_g; 
      break;
    case 179:
      rb_DatenOutput_l = rb_LClosed_dur_min_g; 
      break;
    case 180:
      rb_DatenOutput_l = rb_LClosed_dur_max_g; 
      break;
#endif /*_NO_RAIN_*/
   case 181:
      rb_DatenOutput_l = SHT21xSerialNumber[7] ; /*  SNA_1 */
      break;      
    case 182:
      rb_DatenOutput_l = SHT21xSerialNumber[6] ; /*  SNA_0 */
      break; 
    case 183:
      rb_DatenOutput_l = SHT21xSerialNumber[5] ; /*  SNB_3 */
      break; 
    case 184:
      rb_DatenOutput_l = SHT21xSerialNumber[4] ;  /*  SNB_2 */
      break; 
    case 185:
      rb_DatenOutput_l = SHT21xSerialNumber[3] ;  /*  SNB_1 */
      break; 
    case 186:
      rb_DatenOutput_l = SHT21xSerialNumber[2] ;  /*  SNB_0 */
      break; 
    case 187:
      rb_DatenOutput_l = SHT21xSerialNumber[1] ; /*  SNC_1 */
      break; 
    case 188:
      rb_DatenOutput_l = SHT21xSerialNumber[0] ; /*  SNC_0 */
      break;
    case 189:
      /*VCO_253 Measurement of optical coupling at start up */
      rb_DatenOutput_l = rb_deltaINTV_g;
      break;
    case 190:
      rb_DatenOutput_l = (byte)(rw_SPINoCommCounter_g>>8);
      break;
    case 191:
      rb_DatenOutput_l = (byte)(rw_SPINoCommCounter_g&0xFF);
      break;
    case 192:
      rb_DatenOutput_l = rb_ASICResetCnt_g;
      break;
    case 193:
      rb_DatenOutput_l = rb_Amb_Night_Threshold_g;
      break;
    case 194:
      rb_DatenOutput_l = rb_Amb_NightLow_Threshold_g;
      break;
    case 195:
      rb_DatenOutput_l = (byte)(rw_Amb_Day_Threshold_g>>8);
      break;
    case 196:
      rb_DatenOutput_l = (byte)(rw_Amb_Day_Threshold_g&0xFF);
      break;
    case 197:
      rb_DatenOutput_l = (byte)(rw_Amb_DayHigh_Threshold_g>>8);
      break;
    case 198:
      rb_DatenOutput_l = (byte)(rw_Amb_DayHigh_Threshold_g&0xFF);
      break;
    case 199:
      rb_DatenOutput_l = (byte)(rw_FW_Day_Threshold_g>>8);
      break;
    case 200:
      rb_DatenOutput_l = (byte)(rw_FW_Day_Threshold_g&0xFF);
      break;
    case 201:
      rb_DatenOutput_l = (byte)(rw_FW_DayHigh_Threshold_g>>8);
      break;
    case 202:
      rb_DatenOutput_l = (byte)(rw_FW_DayHigh_Threshold_g&0xFF);
      break;
    case 203:
      rb_DatenOutput_l = rb_LSPotiStage_g;
      break;
    case 204:
      rb_DatenOutput_l = (byte)(rw_AmbLightMeanSlow_g>>8);
      break;
    case 205:
      rb_DatenOutput_l = (byte)(rw_AmbLightMeanSlow_g&0xFF);
      break;
    case 206:
      rb_DatenOutput_l = (byte)(rw_FwLightMeanSlow_g>>8);
      break;
    case 207:
      rb_DatenOutput_l = (byte)(rw_FwLightMeanSlow_g&0xFF);
      break;
#ifndef  GEELY_NL_3A  /*****No Light Function*****/  
#ifndef  GEELY_FS11_NOLIGHT
    case 208:
      rb_DatenOutput_l = (byte)(getNightCounter()>>8); /*fast changing*/
      break;
    case 209:
      rb_DatenOutput_l = (byte)(getNightCounter()&0xFF);/*fast changing*/
      break;
    case 210:
      rb_DatenOutput_l = (byte)(getDayCounter()>>8); /*fast changing*/
      break;
    case 211:
      rb_DatenOutput_l = (byte)(getDayCounter()&0xFF);/*fast changing*/
      break;
    case 212:
      rb_DatenOutput_l = (byte)(getRegulation48OffCounter()>>8); /*fast changing*/
      break;
    case 213:
      rb_DatenOutput_l = (byte)(getRegulation48OffCounter()&0xFF);/*fast changing*/
      break;
    case 214:
      rb_DatenOutput_l = getRegulation48OnCounter();/*fast changing*/
      break;
    case 215:
      rb_DatenOutput_l = (byte)(getVeryBrightInTunnelDistance()>>8); /*fast changing*/
      break;
    case 216:
      rb_DatenOutput_l = (byte)(getVeryBrightInTunnelDistance()&0xFF);/*fast changing*/
      break;
    case 217:
      rb_DatenOutput_l = (byte)(getBrightInTunnelDistance()>>8); /*fast changing*/
      break;
    case 218:
      rb_DatenOutput_l = (byte)(getBrightInTunnelDistance()&0xFF);/*fast changing*/
      break;
 #endif
 #endif     
    default:                                            //Default
      if ((rw_VariableToSend_l >= cw_ADRPRE_PD_mg)&&(rw_VariableToSend_l< (cw_ADRPRE_PD_mg+cb_NumberofEEPROMCells_PD_g)))
      {
        rb_DatenOutput_l = EEPROM_Struct_PD._c[(byte)(rw_VariableToSend_l&0xFF)];
      }
      else if ((rw_VariableToSend_l >= cw_ADRPRE_AD_mg)&&(rw_VariableToSend_l< (cw_ADRPRE_AD_mg+cb_NumberofEEPROMCells_AD_g)))
      {
        rb_DatenOutput_l = EEPROM_Struct_AD._c[(byte)(rw_VariableToSend_l&0xFF)];
      }
      else if ((rw_VariableToSend_l >= cw_ADRPRE_RD_mg)&&(rw_VariableToSend_l< (cw_ADRPRE_RD_mg+cb_NumberofEEPROMCells_RD_g)))
      {
        rb_DatenOutput_l = EEPROM_Struct_RD._c[(byte)(rw_VariableToSend_l&0xFF)];
      }
      else
      {
        rb_DatenOutput_l = 0xFF;                             //Clear Byte
      }
      break;
    }
  }
  return(rb_DatenOutput_l);                            //Return Data (see switch)
}
/**************************************************************************
Syntax   : void  Diagnose_Answer_Download(void)
Object   : Diagnose_Answer_Download()
Parameters : none
Return  : none
Calls   : in RLS_LINST.c from ApplLinSlaveCmdFrmFct()
***************************************************************************
Inputs validation conditions:
none
***************************************************************************
Pseudo-code : Answers a Upload and a Download Response from the Diagnosis
Master
**************************************************************************/
static void Diagnose_Answer_Download(void)
{
  //Local Variable Declaration
  byte rb_tempVariable_l;                            //-temp Variable
  
  rab_DiagRespBuffer_mg[0] = 2;   // response length
  
  rw_DiagnoseEEPROM_Address_mg = (word)(l_u8_rd_MasterReqB4())|((word)(l_u8_rd_MasterReqB3())<<8);  //set EEPROM address
  if (l_u8_rd_MasterReqB5() == 0)                    //Is Data format identifier equal 0
  {
    rb_I2CEEPROMCMDbytesToWrite_g = l_u8_rd_MasterReqB6();
    if (l_u8_rd_MasterReqB2() == cb_REQUEST_DOWNLOAD_s)  //Request Download?
    {
      
      if ((rb_I2CEEPROMCMDbytesToWrite_g > 5) ||(rb_I2CEEPROMCMDbytesToWrite_g == 0))
      {
        Diagnose_NegativeResponse(cb_REQUEST_DOWNLOAD_s,cb_TOMUCHUPLOADBYTES_s);
      }
      else if (((rw_DiagnoseEEPROM_Address_mg >= cw_ADRPRE_PD_mg)
              && (((rw_DiagnoseEEPROM_Address_mg-cw_ADRPRE_PD_mg)+ rb_I2CEEPROMCMDbytesToWrite_g) <= cb_NumberofEEPROMCells_PD_g))
             || ((rw_DiagnoseEEPROM_Address_mg >= cw_ADRPRE_AD_mg)
              && (((rw_DiagnoseEEPROM_Address_mg-cw_ADRPRE_AD_mg)+ rb_I2CEEPROMCMDbytesToWrite_g) <= cb_NumberofEEPROMCells_AD_g))               
             || ((rw_DiagnoseEEPROM_Address_mg >= cw_ADRPRE_RD_mg)
              && (((rw_DiagnoseEEPROM_Address_mg-cw_ADRPRE_RD_mg)+ rb_I2CEEPROMCMDbytesToWrite_g) <= cb_NumberofEEPROMCells_RD_g)))
      {
        //rb_I2CEEPROMCMDbytesToWrite_g = l_u8_rd_MasterReqB6();
        rab_DiagRespBuffer_mg[1] = cb_REQUEST_DOWNLOAD_RESPONSE_s; //Positive Response for Download
        rab_DiagRespBuffer_mg[2] = 5;       //maximal 5 bytes schreiben
        rbi_enable_Programming_EEPROM_g = TRUE;       // Programmieren enablen
      }
      else
      {
        Diagnose_NegativeResponse(cb_REQUEST_DOWNLOAD_s,cb_CAN_NOT_UPLOAD_TO_ADDRESS_s);
      }
    }
    else
    {
      rab_DiagRespBuffer_mg[1] = cb_ANSWER_UPLOAD_RESPONSE_s;  //Positive Response for UPLOAD
      rab_DiagRespBuffer_mg[2] = 0x05;                     //max. 5 bytes to read
    }
    rb_Diagnosticstate_g = 0;                         //Set Diagnostic State to 1
  }
  else if (l_u8_rd_MasterReqB5() == 0xFF)
  {
    if  ((rw_DiagnoseEEPROM_Address_mg == cw_DIAGNOSEPULSEADRESS)
         
         ||(rw_DiagnoseEEPROM_Address_mg == cw_DIAGNOSEHEATERADR)
           ||(cw_DIAGNOSERAINADR == rw_DiagnoseEEPROM_Address_mg))
    {
      if (l_u8_rd_MasterReqB2() == cb_REQUEST_DOWNLOAD_s)
      {
        if (l_u8_rd_MasterReqB6() == 1)                    //Uncompressed memory size for Download should be 1
        {
          rab_DiagRespBuffer_mg[1] = cb_REQUEST_DOWNLOAD_RESPONSE_s; //Positive Response for Download
          rab_DiagRespBuffer_mg[2] = 0x01;                    //maximal 1 byte schreiben
          rb_I2CEEPROMCMDbytesToWrite_g = 1;
        }
        else
        {
          rb_tempVariable_l=l_u8_rd_MasterReqB2();           //Write kind of Request into Second answer byte
          Diagnose_NegativeResponse(rb_tempVariable_l,cb_TOMUCHUPLOADBYTES_s);    //cb_REQUEST_OUT_OF_RANGE_s
        }
      }
      
      else
      {
        rab_DiagRespBuffer_mg[1] = cb_ANSWER_UPLOAD_RESPONSE_s; //Positive Response for UPLOAD
        rab_DiagRespBuffer_mg[2] = 0x01;                    //maximal 1 byte to read
      }
    }
    else
    {
      l_u8_wr_SlaveRespB2(cb_REQUEST_NEGATIVE_DOWNLOAD_RESPONSE_s);  //Negative Response
      rb_tempVariable_l=l_u8_rd_MasterReqB2();                  //Write kind of Request into Second answer byte
      Diagnose_NegativeResponse(rb_tempVariable_l,cb_CAN_NOT_UPLOAD_TO_ADDRESS_s);    //cb_REQUEST_OUT_OF_RANGE_s
    }
  }
  else
  {
    l_u8_wr_SlaveRespB2(cb_REQUEST_NEGATIVE_DOWNLOAD_RESPONSE_s);  //Negative Response
    rb_tempVariable_l=l_u8_rd_MasterReqB2();                       //Write kind of Request into Second answer byte
    Diagnose_NegativeResponse(rb_tempVariable_l,cb_IMPROPER_UPLOAD_TYPE);    //cb_REQUEST_OUT_OF_RANGE_s
  }
  
}


/**************************************************************************
Syntax   : void  Diagnose_clear_Answer_Message(void)
Object   : Diagnose_clear_Answer_Message()
Parameters : none
Return  : none
Calls   : Diagnose.c()
***************************************************************************
Pseudo-code : Clears the Diagnostic answer frame
**************************************************************************/
static __callt void Diagnose_clear_Answer_Message(void)
{
#ifdef BRILLIANCE_M8X
  l_u8_wr_SlaveRespB3(0x00);
  l_u8_wr_SlaveRespB4(0x00);
  l_u8_wr_SlaveRespB5(0x00);
  l_u8_wr_SlaveRespB6(0x00);
  l_u8_wr_SlaveRespB7(0x00);
#else
  l_u8_wr_SlaveRespB3(0xFF);
  l_u8_wr_SlaveRespB4(0xFF);
  l_u8_wr_SlaveRespB5(0xFF);
  l_u8_wr_SlaveRespB6(0xFF);
  l_u8_wr_SlaveRespB7(0xFF);  
#endif
}

/**************************************************************************
Syntax   : void  Diagnose_Read_Audi_Partnumber(void)
Object   : Diagnose_Read_Audi_Partnumber()
Parameters : none
Return  : none
Calls   : in RLS_LINST.c from ApplLinSlaveCmdFrmFct()
***************************************************************************
Inputs validation conditions:
none
***************************************************************************
Pseudo-code : Answers with the Development Partnumber of AUDI response
**************************************************************************/
#ifdef _SUPPORTSERVICE1A_
byte Diagnose_Read_Audi_Partnumber(void)
{
  byte rb_ReturnValue_l;
  rb_ReturnValue_l = 1;   // send without using Diagnose_TP
  l_u8_wr_SlaveRespB0(l_u8_rd_MasterReqB0());
  l_u8_wr_SlaveRespB1(0x20|(rb_Diagnosticstate_g & 0x0F));          //response with multiple Frames with sequence number
  switch(rb_Diagnosticstate_g)                                     //Switch with Diagnosticstate
  {
  case 0:                                                  //1st Answer
    l_u8_wr_SlaveRespB1(0x10);                             //first response with multiple Frames
    l_u8_wr_SlaveRespB2(16);                               //data lenght
    l_u8_wr_SlaveRespB3(cb_POSITIVE_IDENT_RESPONSE_s);     //positive response
    l_u8_wr_SlaveRespB4(cb_IDENT_OPT_AUDI_PARTNUMBER_S);   //Identification record value
    l_u8_wr_SlaveRespB5(0x0E);                             //Zeiger auf Tabellenende (0x0E)
    l_u8_wr_SlaveRespB6(rab_Audi_SW_Partnumber_g(0));        //SEAT Partnumber 0-3
    l_u8_wr_SlaveRespB7(rab_Audi_SW_Partnumber_g(1));        //SEAT Partnumber 0-3
    break;
  case 1:
    l_u8_wr_SlaveRespB2(rab_Audi_SW_Partnumber_g(2));        //AUDI Partnumber 2-7
    l_u8_wr_SlaveRespB3(Diagnosis_BCDtoASCII(rab_Audi_SW_Partnumber_g(3)>>4));
    l_u8_wr_SlaveRespB4(Diagnosis_BCDtoASCII(rab_Audi_SW_Partnumber_g(3)&0x0F));
    l_u8_wr_SlaveRespB5(Diagnosis_BCDtoASCII(rab_Audi_SW_Partnumber_g(4)>>4));
    l_u8_wr_SlaveRespB6(Diagnosis_BCDtoASCII(rab_Audi_SW_Partnumber_g(4)&0x0F));
    l_u8_wr_SlaveRespB7(Diagnosis_BCDtoASCII(rab_Audi_SW_Partnumber_g(5)>>4));
    
    break;
    
  case 2:
    l_u8_wr_SlaveRespB2(Diagnosis_BCDtoASCII(rab_Audi_SW_Partnumber_g(5)&0x0F));         //AUDI Partnumber 8-10
    
    l_u8_wr_SlaveRespB3(rab_Audi_SW_Partnumber_g(6));
    l_u8_wr_SlaveRespB4(rab_Audi_SW_Partnumber_g(7));
    
    l_u8_wr_SlaveRespB5(cb_ASCI_Blank_s);                   //ASCI Blank
    l_u8_wr_SlaveRespB6(cb_TEST_HARDWARE_s);                //Lable for Test Hardware
    l_u8_wr_SlaveRespB7(cb_END_OF_TABLE_s);                 //End of Table
    //Block Answer of next Request (Use only when sending without Diagnoes_TP!!!)
    l_u8_rd_MasterReqB0() = cb_OTHER_TARGET_ADDRESS_s;            
    break;
  default:                                                   //Negative Answer on diagnosticrequest
    Diagnose_NegativeResponse(cb_WRITE_DATA_BY_LOC_ID_s,cb_REQUEST_OUT_OF_RANGE_s);    //cb_REQUEST_OUT_OF_RANGE_s
    rb_ReturnValue_l = 0;
    break;
  }
  rb_Diagnosticstate_g ++;                               //Set Diagnosticstat to 1
  return (rb_ReturnValue_l);
}
#endif

/**************************************************************************
Syntax   : void  Diagnose_Read_Audi_Partnumber(void)
Object   : Diagnose_Read_Audi_Partnumber()
Parameters : none
Return  : none
Calls   : in RLS_LINST.c from ApplLinSlaveCmdFrmFct()
***************************************************************************
Inputs validation conditions:
none
***************************************************************************
Pseudo-code : Answers with the Development Partnumber of AUDI response
**************************************************************************/
#ifdef _SUPPORTSERVICE1A_
byte Diagnose_ReadExtECUIdent(void)
{
  byte rb_ReturnValue_l;
  rb_ReturnValue_l = 1;   // send without using Diagnose_TP
  l_u8_wr_SlaveRespB0(l_u8_rd_MasterReqB0());
  l_u8_wr_SlaveRespB1(0x20|(rb_Diagnosticstate_g & 0x0F));         //response with multiple Frames with sequence number
  switch(rb_Diagnosticstate_g)                                     //Switch with Diagnosticstate
  {
  case 0:                                                  //1st Answer
    l_u8_wr_SlaveRespB1(0x10);                             //first response with multiple Frames
    l_u8_wr_SlaveRespB2(45);                               //data lenght
    l_u8_wr_SlaveRespB3(cb_POSITIVE_IDENT_RESPONSE_s);     //positive response
    l_u8_wr_SlaveRespB4(cb_IDENT_OPT_EXT_SGIDENT_S);   //Identification record value
    l_u8_wr_SlaveRespB5(0x0f);                             //B1: Scaling Offsez Default 0x0f
    l_u8_wr_SlaveRespB6('0');                              //B2: Serial Number
    l_u8_wr_SlaveRespB7('0');                              //B3
    break;
  case 1:               //3-8
    l_u8_wr_SlaveRespB2('0');                          //B4
    l_u8_wr_SlaveRespB3('0');                          //B5
    l_u8_wr_SlaveRespB4('0');                          //B6
    l_u8_wr_SlaveRespB5('0');                          //B7
    l_u8_wr_SlaveRespB6(Diagnosis_BCDtoASCII(rab_Produktionsdaten_g(0)>>4));     //B8
    l_u8_wr_SlaveRespB7(Diagnosis_BCDtoASCII(rab_Produktionsdaten_g(0)&0x0F));   //B9
    break;
  case 2:             //9-14
    l_u8_wr_SlaveRespB2(Diagnosis_BCDtoASCII(rab_Produktionsdaten_g(1)>>4));      //B10
    l_u8_wr_SlaveRespB3(Diagnosis_BCDtoASCII(rab_Produktionsdaten_g(1)&0x0F));    //B11
    l_u8_wr_SlaveRespB4(Diagnosis_BCDtoASCII(rab_Produktionsdaten_g(2)>>4));      //B12
    l_u8_wr_SlaveRespB5(Diagnosis_BCDtoASCII(rab_Produktionsdaten_g(2)&0x0F));    //B13
    l_u8_wr_SlaveRespB6(Diagnosis_BCDtoASCII(rab_Produktionsdaten_g(3)>>4));      //B14
    l_u8_wr_SlaveRespB7(Diagnosis_BCDtoASCII(rab_Produktionsdaten_g(3)&0x0F));    //B15
    break;
  case 3:
    l_u8_wr_SlaveRespB2(48-16);        //B16 Scaling offsett
    l_u8_wr_SlaveRespB3('A');          //B17 Herstellerwerkskennzahl und Kennzeichnung
    l_u8_wr_SlaveRespB4('T');          //B18
    l_u8_wr_SlaveRespB5('W');          //B19
    l_u8_wr_SlaveRespB6('-');          //B20
    l_u8_wr_SlaveRespB7('0');          //B21
    break;
  case 4:
    l_u8_wr_SlaveRespB2('0');          //B22
    l_u8_wr_SlaveRespB3('1');          //B23
    l_u8_wr_SlaveRespB4(Diagnosis_BCDtoASCII(rab_Fertigungsdatum_g(0)>>4));     //B24  Tages-Fertigungsdatum <dd.mm.yy>
    l_u8_wr_SlaveRespB5(Diagnosis_BCDtoASCII(rab_Fertigungsdatum_g(0)&0x0F));      //B25
    l_u8_wr_SlaveRespB6('.');                                                      //B26
    l_u8_wr_SlaveRespB7(Diagnosis_BCDtoASCII(rab_Fertigungsdatum_g(1)>>4));        //B27
    break;
  case 5:
    l_u8_wr_SlaveRespB2(Diagnosis_BCDtoASCII(rab_Fertigungsdatum_g(1)&0x0F));      //B28
    l_u8_wr_SlaveRespB3('.');                                                      //B29
    l_u8_wr_SlaveRespB4(Diagnosis_BCDtoASCII(rab_Fertigungsdatum_g(2)>>4));        //B30
    l_u8_wr_SlaveRespB5(Diagnosis_BCDtoASCII(rab_Fertigungsdatum_g(2)&0x0F));      //B31
    l_u8_wr_SlaveRespB6('0');                                                      //B32  Steuergeratefamilie
    l_u8_wr_SlaveRespB7('0');                                                      //B33  Bestuckungsvariante
    break;
  case 6:
    l_u8_wr_SlaveRespB2(cb_HARDWARESTAND_g);                                       //B34  HW-Index
    l_u8_wr_SlaveRespB3(rab_HardwareStand_g(0));                                   //B35
    l_u8_wr_SlaveRespB4(rab_HardwareStand_g(1));                                   //B36
    l_u8_wr_SlaveRespB5(0x2D);                                                     //B37  Fertigungsstand (Init-Werte)
    l_u8_wr_SlaveRespB6(0x2D);                                                     //B38
    l_u8_wr_SlaveRespB7(0x2D);                                                     //B39
    break;
  case 7:
    l_u8_wr_SlaveRespB2('0');                                                      //B40  Prufstandnummer
    l_u8_wr_SlaveRespB3('0');                                                      //B41
    l_u8_wr_SlaveRespB4('0');                                                      //B42
    l_u8_wr_SlaveRespB5('1');                                                      //B43
    l_u8_wr_SlaveRespB6(0xFF);                                                     // not used
    l_u8_wr_SlaveRespB7(0xFF);                                                     //
    //Block Answer of next Request (Use only when sending without Diagnoes_TP!!!)
    l_u8_rd_MasterReqB0() = cb_OTHER_TARGET_ADDRESS_s; 
    break;
  default:                                                   //Negative Answer on diagnosticrequest
    Diagnose_NegativeResponse(cb_WRITE_DATA_BY_LOC_ID_s,cb_REQUEST_OUT_OF_RANGE_s);    //cb_REQUEST_OUT_OF_RANGE_s
    rb_ReturnValue_l = 0;
    break;
  }
  rb_Diagnosticstate_g ++;                               //Set Diagnosticstat to 1
  return (rb_ReturnValue_l);
}
#endif


#ifdef _SUPPORTSERVICE23_
byte Diagnose_ReadMemoryByAddress(void) /*VDR_233 Rework Diagnostic*/
{
  byte rb_MemAddressPara_l;
  byte rb_MemSizePara_l;
  word rw_StartAddress_l;
  byte rb_Size_l;
  word rw_FrameLength_l;
  byte rb_Length_l;
  byte rb_ReturnValue_l;
  
  static byte rb_SendPos_s;
  
  
  rb_ReturnValue_l = 1;   // send without using Diagnose_TP
  rb_MemAddressPara_l = l_u8_rd_MasterReqB3() & 0x0F; //s_DiagInBuf_g.Data[1] & 0x0F;      // Read address format
  rb_MemSizePara_l = (l_u8_rd_MasterReqB3()>>4) & 0x0F; // (s_DiagInBuf_g.Data[1]>>4) & 0x0F;
  // address format not supported?
  if((rb_MemAddressPara_l > 2) || (rb_MemSizePara_l > 1) || (rb_MemSizePara_l == 0) || (rb_MemAddressPara_l == 0))  
  {
    // negative Antwort auf Diagnoserequest
    Diagnose_NegativeResponse(cb_READ_MEMORY_BY_ADDRESS_s, cb_REQUEST_OUT_OF_RANGE_s); 
    rb_ReturnValue_l =0;      // use Diagnose_TP to send frame
  }
  else
  {
    if(rb_MemAddressPara_l == 2)  // address 2 byte?
    {
      //((word)s_DiagInBuf_g.Data[2] << 8) + s_DiagInBuf_g.Data[3];  // read address
      rw_StartAddress_l = ((word)l_u8_rd_MasterReqB4() <<8) + l_u8_rd_MasterReqB5();
      rb_Size_l = l_u8_rd_MasterReqB6(); //s_DiagInBuf_g.Data[4];     // read bytes to read
      rb_Length_l = 5;
    }
    else
    {
      rw_StartAddress_l = l_u8_rd_MasterReqB4(); //s_DiagInBuf_g.Data[2];   // read address
      rb_Size_l = l_u8_rd_MasterReqB5(); //s_DiagInBuf_g.Data[3];  // read bytes to read
      rb_Length_l = 4;
    }
    
    if (l_u8_rd_MasterReqB1() == rb_Length_l)//(s_DiagInBuf_g.Length == rb_Length_l)   // length of request frame ok?
    {
      if(((rw_StartAddress_l - 1 + rb_Size_l) > 0xFF) || (rb_Size_l == 0)) // address out of range?
      {
        // negative Antwort auf Diagnoserequest
        Diagnose_NegativeResponse(cb_READ_MEMORY_BY_ADDRESS_s, cb_REQUEST_OUT_OF_RANGE_s); 
        rb_ReturnValue_l =0;     // use Diagnose_TP to send frame
      }
      else
      {
        if(rb_Diagnosticstate_g == 0)    // first answer?
        {
          rb_SendPos_s = 0;    // reset send pos
          rw_FrameLength_l = (word)rb_Size_l+1;  // calculate total frame length
          
          if(rw_FrameLength_l > 6)     // multiple frames needed
          {
            l_u8_wr_SlaveRespB1(0x10|((rw_FrameLength_l >> 8) & 0x0F)); 
            l_u8_wr_SlaveRespB2((rw_FrameLength_l & 0xFF));                               //data lenght
            l_u8_wr_SlaveRespB3(cb_RMBA_POSRESPONSE_s); //(cb_RMBA_POSRESPONSE_s);     //positive response
            l_u8_wr_SlaveRespB4(Diagnose_GetEEPROMValue(rw_StartAddress_l+rb_SendPos_s)); 
            rb_SendPos_s++;
            l_u8_wr_SlaveRespB5(Diagnose_GetEEPROMValue(rw_StartAddress_l+rb_SendPos_s)); 
            rb_SendPos_s++;
            l_u8_wr_SlaveRespB6(Diagnose_GetEEPROMValue(rw_StartAddress_l+rb_SendPos_s)); 
            rb_SendPos_s++;
            l_u8_wr_SlaveRespB7(Diagnose_GetEEPROMValue(rw_StartAddress_l+rb_SendPos_s)); 
            rb_SendPos_s++;
            rb_Diagnosticstate_g ++;
          }
          else
          {
            l_u8_wr_SlaveRespB1(cb_SINGLE_FRAME_s|(rw_FrameLength_l & 0x0F));                //single frame
            l_u8_wr_SlaveRespB2(cb_RMBA_POSRESPONSE_s);     //positive response
            l_u8_wr_SlaveRespB3(Diagnose_GetEEPROMValue(rw_StartAddress_l+rb_SendPos_s)); 
            rb_SendPos_s++;
            l_u8_wr_SlaveRespB4(Diagnose_GetEEPROMValue(rw_StartAddress_l+rb_SendPos_s)); 
            rb_SendPos_s++;
            l_u8_wr_SlaveRespB5(Diagnose_GetEEPROMValue(rw_StartAddress_l+rb_SendPos_s)); 
            rb_SendPos_s++;
            l_u8_wr_SlaveRespB6(Diagnose_GetEEPROMValue(rw_StartAddress_l+rb_SendPos_s)); 
            rb_SendPos_s++;
            l_u8_wr_SlaveRespB7(Diagnose_GetEEPROMValue(rw_StartAddress_l+rb_SendPos_s)); 
            rb_SendPos_s++;
            l_u8_wr_MasterReqB7(0); //s_DiagInBuf_g.Valid = 0;   // request completely answered
          }
        }
        else
        {     //response with multiple Frames with sequence number
          l_u8_wr_SlaveRespB1(cb_CONSECUTIVE_FRAME_s|(rb_Diagnosticstate_g & 0x0F)); 
          l_u8_wr_SlaveRespB2(Diagnose_GetEEPROMValue(rw_StartAddress_l+rb_SendPos_s)); 
          rb_SendPos_s++;
          l_u8_wr_SlaveRespB3(Diagnose_GetEEPROMValue(rw_StartAddress_l+rb_SendPos_s)); 
          rb_SendPos_s++;
          l_u8_wr_SlaveRespB4(Diagnose_GetEEPROMValue(rw_StartAddress_l+rb_SendPos_s)); 
          rb_SendPos_s++;
          l_u8_wr_SlaveRespB5(Diagnose_GetEEPROMValue(rw_StartAddress_l+rb_SendPos_s)); 
          rb_SendPos_s++;
          l_u8_wr_SlaveRespB6(Diagnose_GetEEPROMValue(rw_StartAddress_l+rb_SendPos_s)); 
          rb_SendPos_s++;
          l_u8_wr_SlaveRespB7(Diagnose_GetEEPROMValue(rw_StartAddress_l+rb_SendPos_s)); 
          rb_SendPos_s++;
          
          if(rb_SendPos_s >= rb_Size_l) // all data send?
          {
            l_u8_wr_MasterReqB7(0); //s_DiagInBuf_g.Valid = 0;   // request completely answered
          }
          rb_Diagnosticstate_g++; // increase sequence number
        }
      }
    }
    else
    {
      // negative Antwort auf Diagnoserequest
      Diagnose_NegativeResponse(cb_READ_MEMORY_BY_ADDRESS_s, cb_INCORECTMESSAGELENGTH_s); 
      rb_ReturnValue_l = 0;   // use Diagnose_TP to send frame
    }
  }
  return (rb_ReturnValue_l);
}

#endif

#ifdef _SUPPORTSERVICE3D_
void Diagnose_WriteMemoryByAddress(void)
{
  Diagnose_NegativeResponse(l_u8_rd_MasterReqB2(),cb_SERVICE_NOT_SUPPORTED_s);            //noch nicht implementiert
}
#endif

#ifdef _SUPPORTSERVICE19_
void Diagnose_ReadDTC(void)
{
  static byte rb_WriteCode_s;
  static byte rb_ErrorActive_s;
  
  byte rb_ErrorStatus_l;
  if(l_u8_rd_MasterReqB1() == 3) // length of request frame ok?
  {
    if(l_u8_rd_MasterReqB3() == 0x02)  // Subfunction ReportDtcByStatusMask?
    {
      
      rb_ErrorStatus_l = (rbi_RainSensorError||bi_ROM_CHECK_FAILURE_g||bi_RAM_CHECK_FAILURE_g||rbi_Check_LS_NoCommunication_g||rbi_LS_Error_Vref_g);   // read error status RS Error
      if(((l_u8_rd_MasterReqB4()&0x01) > 0) && (rb_ErrorStatus_l>0))   // error match Status Mask? RLS_VDR_267
      {
        rb_WriteCode_s = 1;  // set marker 'write DTC'
      }
      else
      {
        rb_WriteCode_s = 0;  // clear marker 'write DTC'
      }
      rb_ErrorActive_s = rb_ErrorStatus_l;   // store status of DTC
      
      rb_ErrorStatus_l = (rbi_LightSensorError_g||bi_ROM_CHECK_FAILURE_g||bi_RAM_CHECK_FAILURE_g||(uF_ASIC_Error_Flags_g.AllBit > 0)); // read error status LS Error
      if(((l_u8_rd_MasterReqB4()&0x01) > 0) && (rb_ErrorStatus_l>0))   // error match Status Mask? RLS_VDR_267
      {
        rb_WriteCode_s |= 2;    // set marker 'write DTC'
      }
      rb_ErrorActive_s |= (rb_ErrorStatus_l<<1);   // store status of DTC
      
      if(rb_WriteCode_s == 0) // no DTC to write?
      {
        rab_DiagRespBuffer_mg[0] = 3;   // response length
        rab_DiagRespBuffer_mg[1] = cb_READDTC_s|0x40;     //positive response
        rab_DiagRespBuffer_mg[2] = l_u8_rd_MasterReqB3();        // sub function
        rab_DiagRespBuffer_mg[3] = l_u8_rd_MasterReqB4();        // DTCAvailabilityMask
      }
      else
      {
        if(rb_WriteCode_s < 3)  // one code to write?
        {
          rab_DiagRespBuffer_mg[0] = 6;                               //data lenght 6
        }
        else
        {
          rab_DiagRespBuffer_mg[0] = 9;                               //data lenght 9
        }
        
        rab_DiagRespBuffer_mg[1] = cb_READDTC_s|0x40;     //positive response
        rab_DiagRespBuffer_mg[2] = l_u8_rd_MasterReqB3();        // sub function
        rab_DiagRespBuffer_mg[3] = l_u8_rd_MasterReqB4();        // DTCAvailabilityMask
        if((rb_WriteCode_s & 0x02) > 0)    // Light Sensor Error match Mask?
        {
          rab_DiagRespBuffer_mg[4] = cb_DTC_LS_HB_s;   // write DTC LS
          rab_DiagRespBuffer_mg[5] = cb_DTC_LS_LB_s;
          rab_DiagRespBuffer_mg[6] = (rb_ErrorActive_s & 0x02)>>1; // write status of DTC
          if((rb_WriteCode_s & 0x01) > 0)  // Rain Sensor Error match Mask?
          {
            rab_DiagRespBuffer_mg[7] = cb_DTC_RS_HB_s;   // write DTC RS
            rab_DiagRespBuffer_mg[8] = cb_DTC_RS_LB_s;
            rab_DiagRespBuffer_mg[9] = (rb_ErrorActive_s & 0x01);   // write status of DTC
          }
        }
        else  // Rain Sensor Error match Mask?
        {
          rab_DiagRespBuffer_mg[4] = cb_DTC_RS_HB_s;   // write DTC RS
          rab_DiagRespBuffer_mg[5] = cb_DTC_RS_LB_s;
          rab_DiagRespBuffer_mg[6] = (rb_ErrorActive_s & 0x01);   // write status of DTC
        }
      }
    }
    else
    {
      Diagnose_NegativeResponse(cb_READDTC_s,cb_SUBFUNCTION_NOT_SUPPORTED_s); // negative Antwort auf Diagnoserequest
    }
  }
  else
  {
    Diagnose_NegativeResponse(cb_READDTC_s,cb_INCORECTMESSAGELENGTH_s); // negative Antwort auf Diagnoserequest
  }
}


#endif

#ifdef _SUPPORTSERVICE14_
void Diagnose_ClearDTC(void)
{
  if(l_u8_rd_MasterReqB1() == 4) // length of request frame ok?
  {// requested group valid?
    if((l_u8_rd_MasterReqB3() == 0xFF) && (l_u8_rd_MasterReqB4() == 0xFF) && (l_u8_rd_MasterReqB5() == 0xFF))   
    {
      rbi_RainSensorError = 0;
      bi_ROM_CHECK_FAILURE_g = 0;
      bi_RAM_CHECK_FAILURE_g = 0;
      rbi_Check_LS_NoCommunication_g = 0;
      rbi_LS_Error_Vref_g = 0;
      rbi_LightSensorError_g = 0;
      bi_ROM_CHECK_FAILURE_g = 0;
      bi_RAM_CHECK_FAILURE_g = 0;
      uF_ASIC_Error_Flags_g.AllBit = 0;
      
      
      rab_DiagRespBuffer_mg[0] = 1;   // response length
      rab_DiagRespBuffer_mg[1] = cb_CLRDTC_s|0x40;     //positive response
      rab_DiagRespBuffer_mg[2] = l_u8_rd_MasterReqB3();        // sub function
    }
    else
    {
      Diagnose_NegativeResponse(cb_CLRDTC_s,cb_REQUEST_OUT_OF_RANGE_s); // negative Antwort auf Diagnoserequest
    }
  }
  else
  {
    Diagnose_NegativeResponse(cb_CLRDTC_s,cb_INCORECTMESSAGELENGTH_s); // negative Antwort auf Diagnoserequest
  }
}
#endif


#ifdef _SUPPORTJ2602ECURESET_/*VCO_11*/
/**************************************************************************
Syntax   : void  Diagnose_ECUReset(void)
Object   : Diagnose_ECUReset()
Parameters : none
Return  : none
Calls   : in RLS_LINST.c from ApplLinMasterReqFrmFct()
***************************************************************************
Inputs validation conditions:
none
***************************************************************************
Pseudo-code : Writes the Parameter for negative Response into the output
buffer
**************************************************************************/
void Diagnose_ECUReset(void)
{
#  ifdef _ECURESETCALLBACKFKT_
  byte rb_PosResponse_l;
  
  rb_PosResponse_l = ApplEcuReset();
  
  if (rb_PosResponse_l == TRUE)
  {
    rab_DiagRespBuffer_mg[1] = cb_ECURST_s | 0x40;   //positive response
  }
  else
  {
    rab_DiagRespBuffer_mg[1] = cb_NEGATIVE_RESPONSE_s;   //negative response
  }
#  else /*_ECURESETCALLBACKFKT_*/
  rab_DiagRespBuffer_mg[1] = cb_NEGATIVE_RESPONSE_s;   //negative response
#  endif /*_ECURESETCALLBACKFKT_*/
  
  rab_DiagRespBuffer_mg[0] = 6;                                   // Length
  rab_DiagRespBuffer_mg[2] = (cw_SupplierID_g & 0x00FF);          // Supplier ID LSB
  rab_DiagRespBuffer_mg[3] = (cw_SupplierID_g >> 8);              // Supplier ID MSB
  rab_DiagRespBuffer_mg[4] = (rw_FunctionID_g & 0x00FF);          // Function ID LSB
  rab_DiagRespBuffer_mg[5] = (rw_FunctionID_g >> 8);              // Function ID MSB
  rab_DiagRespBuffer_mg[6] = rb_VariantID_g;                       // Variante
}
#endif /*_SUPPORTJ2602ECURESET_*/


/**************************************************************************
Syntax   : void  Diagnose_NegativeResponse(void)
Object   : Diagnose_NegativeResponse()
Parameters : rb_DataLinkLayer_l (kind of negative Answer)
Return  : none
Calls   : in RLS_LINST.c from ApplLinSlaveCmdFrmFct()
***************************************************************************
Inputs validation conditions:
none
***************************************************************************
Pseudo-code : Writes the Parameter for negative Response into the output
buffer
**************************************************************************/
static void Diagnose_NegativeResponse(byte rb_requ_ID_l,byte rb_DataLinkLayer_l)
{
  //Writes the following Answer into the LIN Buffer
  rab_DiagRespBuffer_mg[0] = 3; // Length
  rab_DiagRespBuffer_mg[1] = cb_NEGATIVE_RESPONSE_s;   //negative response
  rab_DiagRespBuffer_mg[2] = rb_requ_ID_l;   //negative response
  rab_DiagRespBuffer_mg[3] = rb_DataLinkLayer_l;   //negative response code
}


/**************************************************************************
Syntax   : void  Diagnose_Recieve_Transfer_Data(void)
Object   : Diagnose_Recieve_Transfer_Data()
Parameters : none
Return  : none
Calls   : in Diagnose.c from some Functions
***************************************************************************
Inputs validation conditions:
none
***************************************************************************
Pseudo-code : Recieves and Answers Transfer Datas for EEPROM programming
and triggers the writing of the EEPROM
**************************************************************************/
static void Diagnose_Recieve_Transfer_Data(void)
{
  byte rb_idx_l;
  //Clear Answer Massage!
  
  if(rbi_UnderVoltage_g == FALSE)                    //No Undervoltage?
  {
    if ((rw_DiagnoseEEPROM_Address_mg) == (((word)(cw_ADRPRE_AD_mg))+cb_POSITIONDEFAULTSOFTWARE+1))    // Write SW-Version?
    {
      if(rb_Diagnosticstate_g == 0)   // Firt call?
      {
        EEProm_LoadDefault();      //VDR_514 Load Default values to EEPROM
        rb_Diagnosticstate_g++;    // increase call counter
      }
      else if (rb_EEPROM_Status_g == cb_E2STATUS_INITIALIZATION_g)   // EEPROM in init mode?
      {
        Diagnose_NegativeResponse(cb_TRANSFER_DATA_REQUEST_s,cb_RESPONSE_PENDING);       //response pending
        rb_ResponseToSend_g ++;  // send one response more
      }
      else if (uF_E2ConfigErrorFlags_g.AllBit > 0) // Error during init?
      {
        Diagnose_NegativeResponse(cb_TRANSFER_DATA_REQUEST_s,cb_CONDITION_NOT_CORRECT_s);       //response pending
      }
      else
      {
        rab_DiagRespBuffer_mg[0] = 1; // Length
        rab_DiagRespBuffer_mg[1] = cb_ANSWER_TRANSMISSION_s;   //positive response
      }
    }
    else if((rw_DiagnoseEEPROM_Address_mg >= cw_ADREEPROM_START_g)&& (rw_DiagnoseEEPROM_Address_mg <= cw_ADREEPROM_END_g)) //adress in EEPROM?
    {
      if(rbi_enable_Programming_EEPROM_g == TRUE)                                      //programming active?
      {
        if(rbi_EEPROMBytesToWrite_g == FALSE) //no bytes to program -> new command ?
        {
          rbi_EEPROMBytesWritten_g = FALSE;    // reset EEPROM bytes Written!
        }
        
        if(rb_Diagnosticstate_g == 0)   //new Data to Programm)
        {
          //copy Data
          rab_EEPROM_Bytes_toWrite_g[0] = l_u8_rd_MasterReqB3();
          rab_EEPROM_Bytes_toWrite_g[1] = l_u8_rd_MasterReqB4();
          rab_EEPROM_Bytes_toWrite_g[2] = l_u8_rd_MasterReqB5();
          rab_EEPROM_Bytes_toWrite_g[3] = l_u8_rd_MasterReqB6();
          rab_EEPROM_Bytes_toWrite_g[4] = l_u8_rd_MasterReqB7();
          
          rw_EEPROM_Address_to_Write_g = rw_DiagnoseEEPROM_Address_mg;
          //Check datas
          if(Diagnose_CheckE2_DownloadBytes()>0)
          {
            rb_Diagnosticstate_g = 0xF0;  // Request out of range
          }
          else
          {
            rb_Diagnosticstate_g++;          //set to Datas are copied
            rbi_EEPROMWriteSuccess_g = TRUE;
            rbi_EEPROMBytesToWrite_g = TRUE;
            rbi_EEPROMBytesWritten_g = FALSE;
            if(rb_I2CEEPROMCMDbytesToWrite_g >= 5) //more than 5 bytes to write?
            {
              rb_I2C_EEPROM_bytesToWrite_g = 5;     //set the number of bytes to write to 5
              rb_I2CEEPROMCMDbytesToWrite_g -= 5;   //decrement the cmd number of bytes by 5
              rw_DiagnoseEEPROM_Address_mg +=5;     //increment Adress to write
            }
            else
            {
              /* set the number of bytes to write to the commanded */
              rb_I2C_EEPROM_bytesToWrite_g = rb_I2CEEPROMCMDbytesToWrite_g; 
              rb_I2CEEPROMCMDbytesToWrite_g = 0;                                 //clear the number of bytes
            }
            if( (rw_EEPROM_Address_to_Write_g >= CW_CALIB_CRC_START)&&(rw_EEPROM_Address_to_Write_g <= CW_CALIB_CRC_END))
            {
              rbi_CRC_ChangedByDiagnostic_g = TRUE;/* Disable CRC calculation */
            }
            
          }
        }
        
        if(rb_Diagnosticstate_g == 0xF0)
        {
          Diagnose_NegativeResponse(cb_WRITE_DATA_BY_LOC_ID_s,cb_REQUEST_OUT_OF_RANGE_s);  // coding was not possible
        }
        else
          if(rbi_EEPROMBytesWritten_g == TRUE)         //is eeprom written?
          {                                                                        //clear eeprom to write
            rbi_enable_Programming_EEPROM_g = FALSE;
            rbi_EEPROMBytesToWrite_g = FALSE;
            if(rbi_EEPROMWriteSuccess_g == TRUE)                                  //was succes
            {
              rab_DiagRespBuffer_mg[0] = 1; // Length
              rab_DiagRespBuffer_mg[1] = cb_ANSWER_TRANSMISSION_s;   //positive response
            }
            else
            {
              Diagnose_NegativeResponse(cb_TRANSFER_DATA_REQUEST_s,cb_TRANSFER_DATA_SUSPENDED);//coding was not possible
            }
          }
          else
            if(rbi_EEPROMBytesToWrite_g == TRUE)
            {
              
              Diagnose_NegativeResponse(cb_TRANSFER_DATA_REQUEST_s,cb_RESPONSE_PENDING);       //coding in work
              rb_ResponseToSend_g ++;  // send one response more
            }
            else {} /*Misra Rule 14.10*/
        
      }
    }
    
    //*******************************************************
    // Switch on/off heater
    //*******************************************************
    else
      if(rw_DiagnoseEEPROM_Address_mg == cw_DIAGNOSEHEATERADR) //is heater of SHT11
      {
        if (l_u8_rd_MasterReqB3() == 1)
        {
          HumTemp_Heater(cb_HEATERON_g);
          rab_DiagRespBuffer_mg[0] = 1; // Length
          rab_DiagRespBuffer_mg[1] = cb_ANSWER_TRANSMISSION_s;   //positive response
        }
        else if(l_u8_rd_MasterReqB3() == 0)
        {
          HumTemp_Heater(cb_HEATEROFF_g);
          rab_DiagRespBuffer_mg[0] = 1; // Length
          rab_DiagRespBuffer_mg[1] = cb_ANSWER_TRANSMISSION_s;   //positive response
        }
        else
        {
          Diagnose_NegativeResponse(cb_TRANSFER_DATA_REQUEST_s,cb_CONDITION_NOT_CORRECT_s); //cb_REQUEST_OUT_OF_RANGE_s
        }
        
      }
    /*********************************************************/
    /* Trigger LATCH UP RECOVERING TEST*/
    /*********************************************************/
    
    
    /********************************************************/
    /* Trigger Diagnostic Pulse*/
    /********************************************************/
    /*VDR_846 Negative response for diag pulse, instead of pending, when RS is off*/
      else if((rw_DiagnoseEEPROM_Address_mg == cw_DIAGNOSEPULSEADRESS)
              && ( (l_u8_rd_MasterReqB3()==0x55) || (l_u8_rd_MasterReqB3()==0xE0)) 
                && (TRUE == rbi_Modulator_On_g)) /*is diagnostic pulse requested*/
      {
        if((rbi_ASIC_Step_Response_ready == TRUE) && (rbi_ASICgainAdjustRunning_g == FALSE))
        {
          
          if (l_u8_rd_MasterReqB3()==0xE0)  /* VDR_590 send additional length of every step response*/
          {
            rab_DiagRespBuffer_mg[0] = 3 + (CB_STEPRESPPERREQUEST_G*2); /* Length   (was 1)*/
            rab_DiagRespBuffer_mg[1] = cb_ANSWER_TRANSMISSION_s;   /*positive response*/
            rab_DiagRespBuffer_mg[2] = (byte)(rw_DiagnoseStepResponseAnswer_g>>8);   /*alter Wert versenden*/
            rab_DiagRespBuffer_mg[3] = (byte)(rw_DiagnoseStepResponseAnswer_g & 0x00FF);   /*alter Wert versenden*/
            
            for (rb_idx_l = 0;rb_idx_l<CB_STEPRESPPERREQUEST_G;rb_idx_l++)
            {
              /*alter Wert versenden*/
              rab_DiagRespBuffer_mg[(rb_idx_l*2) + 4] = (byte)(rw_StepResponseRes_g[CB_STEPRESPPERREQUEST_G-1-rb_idx_l]>>8);
              /*alter Wert versenden*/
              rab_DiagRespBuffer_mg[(rb_idx_l*2) + 5] = (byte)(rw_StepResponseRes_g[CB_STEPRESPPERREQUEST_G-1-rb_idx_l] & 0x00FF);
            }
          }
          else
          {
            rab_DiagRespBuffer_mg[0] = 3; /* Length   (was 1)*/
            rab_DiagRespBuffer_mg[1] = cb_ANSWER_TRANSMISSION_s;   /*positive response*/
            rab_DiagRespBuffer_mg[2] = (byte)(rw_DiagnoseStepResponseAnswer_g>>8);   /*alter Wert versenden*/
            rab_DiagRespBuffer_mg[3] = (byte)(rw_DiagnoseStepResponseAnswer_g & 0x00FF);   /*alter Wert versenden*/
          }
          rbi_ASIC_Step_Response_ready = FALSE;
          
          rbi_DiagnoseWriteEEPROM_g = FALSE; /* not to trigger again by slave response!*/
          rbi_DiagnoseReadEEPROM_g = FALSE;
        }
        else /*lauft noch oder schon*/
        {
          if(rbi_ASICgainAdjustRunning_g == FALSE) /*if no diagnostic flag is running!*/
          {
            rbi_ASICgainAdjustRunning_g = TRUE;
          }
          
          rw_DiagRequestCounter_g = rb_Diag_Request_Factor_g;
          rw_DiagRequestCounter_g *= (word)(50);
          /*long diag pulse*/
          if(l_u8_rd_MasterReqB3()==0xE0)
          {
            rw_DiagRequestCounter_g *= 5;
          }
          else
          {
          }
            
          Diagnose_NegativeResponse(cb_TRANSFER_DATA_REQUEST_s,cb_RESPONSE_PENDING); /*cb_REQUEST_OUT_OF_RANGE_s*/
          rb_ResponseToSend_g ++;  /* send one response more*/
        }
      }
      else if((rw_DiagnoseEEPROM_Address_mg == cw_DIAGNOSERAINADR)
              && (l_u8_rd_MasterReqB3()==0x55) && (TRUE == rbi_Modulator_On_g))
        /*is diagnostic rain requested?*/
      {
        rb_DiagRain_HighTime_g = l_u8_rd_MasterReqB5();
        rw_DiagRain_LowTime_g = (((word)l_u8_rd_MasterReqB6())<<8) + l_u8_rd_MasterReqB7();
        
        rab_DiagRespBuffer_mg[0] = 1; /* Length   (was 1)*/
        rab_DiagRespBuffer_mg[1] = cb_ANSWER_TRANSMISSION_s;   /*positive response*/
        rab_DiagRespBuffer_mg[2] = 0xFF;
        rab_DiagRespBuffer_mg[3] = 0xFF;
        rab_DiagRespBuffer_mg[4] = 0xFF;
        rab_DiagRespBuffer_mg[5] = 0xFF;
        rab_DiagRespBuffer_mg[6] = 0xFF;
        rab_DiagRespBuffer_mg[7] = 0xFF;
        
        rbi_DiagnoseWriteEEPROM_g = FALSE; /* not to trigger again by slave response!*/
        rbi_DiagnoseReadEEPROM_g = FALSE;
      }
      else
      {
        /*cb_REQUEST_OUT_OF_RANGE_s*/
        Diagnose_NegativeResponse(cb_TRANSFER_DATA_REQUEST_s,cb_CONDITION_NOT_CORRECT_s);
        rbi_enable_Programming_EEPROM_g = FALSE;
      }
  }
  else
  {
    /*cb_REQUEST_OUT_OF_RANGE_s*/
    Diagnose_NegativeResponse(cb_TRANSFER_DATA_REQUEST_s,cb_CONDITION_NOT_CORRECT_s);
  }
}

static byte Diagnose_CheckE2_DownloadBytes(void)
{
  byte rb_DATA_OutOfRange_l;
  byte rb_BytesToCheck_l;
  word rw_ChkByteAddress_l;
  
  rb_DATA_OutOfRange_l = 0x00;
  
  if (rb_I2CEEPROMCMDbytesToWrite_g >= 5)
  {
    rb_BytesToCheck_l = 5;
  }
  else
  {
    rb_BytesToCheck_l = rb_I2CEEPROMCMDbytesToWrite_g;
  }
  
  while (rb_BytesToCheck_l > 0)
  {
    rb_BytesToCheck_l--;
    rw_ChkByteAddress_l = rw_EEPROM_Address_to_Write_g+rb_BytesToCheck_l;
    
    if ((rw_ChkByteAddress_l >= cw_ADRPRE_PD_mg) && (rw_ChkByteAddress_l <= (cw_ADRPRE_PD_mg + cb_NumberofEEPROMCells_PD_g)))
    {
      if ((rab_EEPROM_Bytes_toWrite_g[rb_BytesToCheck_l] < cb_EEPROMDataDefaultMinMax_PD_g[rw_ChkByteAddress_l&0xff][cb_CHK_MIN_g])
          ||(rab_EEPROM_Bytes_toWrite_g[rb_BytesToCheck_l] > cb_EEPROMDataDefaultMinMax_PD_g[rw_ChkByteAddress_l&0xff][cb_CHK_MAX_g]))
      {
        rb_DATA_OutOfRange_l = 0x01;  // data out of range
      }
      
      if(((rw_ChkByteAddress_l == cw_ALS1_4_SETTING_ADDRESS_g) && (((rab_EEPROM_Bytes_toWrite_g[rb_BytesToCheck_l]&0xC0)==0x80)||((rab_EEPROM_Bytes_toWrite_g[rb_BytesToCheck_l]&0xC)==0x8))) ||
         ((rw_ChkByteAddress_l == cw_ALS5_6_INREC_SETTING_ADDRESS_g) && (((rab_EEPROM_Bytes_toWrite_g[rb_BytesToCheck_l]&0x30)==0x20)||((rab_EEPROM_Bytes_toWrite_g[rb_BytesToCheck_l]&0x3)==0x2))))
      {
        rb_DATA_OutOfRange_l = 0x01;  /* data out of range*/
      }
    }
    else if ((rw_ChkByteAddress_l >= cw_ADRPRE_AD_mg) && (rw_ChkByteAddress_l <= (cw_ADRPRE_AD_mg + cb_NumberofEEPROMCells_AD_g)))
    {
      if ((rab_EEPROM_Bytes_toWrite_g[rb_BytesToCheck_l] < cb_EEPROMDataDefaultMinMax_AD_g[rw_ChkByteAddress_l&0xff][cb_CHK_MIN_g])
          ||(rab_EEPROM_Bytes_toWrite_g[rb_BytesToCheck_l] > cb_EEPROMDataDefaultMinMax_AD_g[rw_ChkByteAddress_l&0xff][cb_CHK_MAX_g]))
      {
        rb_DATA_OutOfRange_l = 0x01;  // data out of range
      }    
    }    
    else if ((rw_ChkByteAddress_l >= cw_ADRPRE_RD_mg) && (rw_ChkByteAddress_l <= (cw_ADRPRE_RD_mg + cb_NumberofEEPROMCells_RD_g)))
    {
      if ((rab_EEPROM_Bytes_toWrite_g[rb_BytesToCheck_l] < cb_EEPROMDataDefaultMinMax_RD_g[rw_ChkByteAddress_l&0xff][cb_CHK_MIN_g])
          ||(rab_EEPROM_Bytes_toWrite_g[rb_BytesToCheck_l] > cb_EEPROMDataDefaultMinMax_RD_g[rw_ChkByteAddress_l&0xff][cb_CHK_MAX_g]))
      {
        rb_DATA_OutOfRange_l = 0x01;  // data out of range
      }    
    }

    else {} /*Misra Rule 14.10*/
    
  }
  return(rb_DATA_OutOfRange_l);
}

/**************************************************************************
Syntax   : void  Diagnose_Write_Codierinfo(void)
Object   : Diagnose_Write_Codierinfo()
Parameters : none
Return  : none
Calls   : in RLS_LINST.c from ApplLinSlaveCmdFrmFct()
***************************************************************************
Inputs validation conditions:
none
***************************************************************************
Pseudo-code : Writes Coding info into the EEPROM
**************************************************************************/
#ifdef _SUPPORTCODING3B_
void Diagnose_Write_Codierinfo(void)
{
  Diagnose_clear_Answer_Message();
  if(l_u8_rd_MasterReqB1() == 0x06)   //coding for D3 LIN
  {
    //copy coding Data
    rab_EEPROM_Bytes_toWrite_g[0] = l_u8_rd_MasterReqB7();
    rab_EEPROM_Bytes_toWrite_g[1] = l_u8_rd_MasterReqB6();
    rab_EEPROM_Bytes_toWrite_g[2] = l_u8_rd_MasterReqB5();
  }
  else
    if(l_u8_rd_MasterReqB1() == 0x05)  //coding for C6 LIN
    {
      //copy coding Data
      rab_EEPROM_Bytes_toWrite_g[0] = l_u8_rd_MasterReqB6();
      rab_EEPROM_Bytes_toWrite_g[1] = l_u8_rd_MasterReqB5();
      rab_EEPROM_Bytes_toWrite_g[2] = l_u8_rd_MasterReqB4();
    }
    else //create wrong Condition!
    {
      l_u8_rd_MasterReqB1() = 0x06;
      l_u8_rd_MasterReqB4() = 0x00;
    }
    //D3 ->  Check the  0x20+S byte
  if((l_u8_rd_MasterReqB4()!= (0x20+cb_TARGET_ADDRESS_s))&& (l_u8_rd_MasterReqB1() == 0x06))
  {
    //Negative Response cb_CONDITION_NOT_CORRECT_s
    Diagnose_NegativeResponse(cb_WRITE_DATA_BY_LOC_ID_s,cb_CONDITION_NOT_CORRECT_s); 
  }
  else
    
    
    if((rb_Kodierbyte2_g == rab_EEPROM_Bytes_toWrite_g[0])         //bereits codiert
       && (rb_Kodierbyte1_g == rab_EEPROM_Bytes_toWrite_g[1])
         && (rb_Kodierbyte0_g == rab_EEPROM_Bytes_toWrite_g[2]))
    {
      rab_DiagRespBuffer_mg[0] = 2; // Length
      rab_DiagRespBuffer_mg[1] = cb_WRITE_DATA_POSITIVE_s;
      rab_DiagRespBuffer_mg[2] = cb_NEW_CONFIGURATION_s;
    }
    else
    {
      if(rbi_UnderVoltage_g == FALSE)            //No Undervoltage?
      {
        if(rbi_EEPROMBytesToWrite_g == FALSE)   //coding not started?
        {
          rbi_EEPROMBytesWritten_g = FALSE;      //clear bytes written
        }
        rw_EEPROM_Address_to_Write_g = cw_EEPROM_CODING_ADDRESS_g; //set adress to write
        rb_I2C_EEPROM_bytesToWrite_g = 3;         //set number of bytes to 3
        rbi_EEPROMWriteSuccess_g = TRUE;
        rbi_EEPROMBytesToWrite_g = TRUE;          //set flag for bytes to write
        if(rbi_EEPROMBytesWritten_g == TRUE)     //wait for eeprom bytes written
        {
          rbi_EEPROMBytesToWrite_g = FALSE;       //clear flags
          rbi_EEPROMBytesWritten_g = FALSE;
          if(rbi_EEPROMWriteSuccess_g == TRUE)   //for succes answer positive
          {
            rab_DiagRespBuffer_mg[0] = 2; // Length
            rab_DiagRespBuffer_mg[1] = cb_WRITE_DATA_POSITIVE_s;
            rab_DiagRespBuffer_mg[2] = cb_NEW_CONFIGURATION_s;
          }
          else
          {
            Diagnose_NegativeResponse(cb_WRITE_DATA_BY_LOC_ID_s,cb_CONDITION_NOT_CORRECT_s);  // Kodierung Geht nicht
          }
        }
        else
        {
          Diagnose_NegativeResponse(cb_WRITE_DATA_BY_LOC_ID_s,cb_RESPONSE_PENDING);
          rb_ResponseToSend_g ++;  // send one response more
        }
      }
    }
}
#endif

#ifdef _SUPPORTCODING2E_

void Diagnose_Write_CodierinfoB8(void)
{
  word rw_Identifier_l;
  
  rw_Identifier_l = (((word)l_u8_rd_MasterReqB3())<<8)+l_u8_rd_MasterReqB4();
#ifndef NOT_SUPPORT_SERVICE_1519TO1525  
  if ((((rw_Identifier_l == 0x0611)|| (rw_Identifier_l == 0x6002)|| (rw_Identifier_l == 0x1527 ))&&(l_u8_rd_MasterReqB1() != 0x06))
      ||(((rw_Identifier_l == 0x1525)||(rw_Identifier_l == 0x1526)|| ((rw_Identifier_l >= 0x1528)&&(rw_Identifier_l <= 0x152A)))&&(l_u8_rd_MasterReqB1() != 0x04))
        ||((rw_Identifier_l == 0x152B)&&(l_u8_rd_MasterReqB1() != 0x05))||((rw_Identifier_l == 0x152C)&&(l_u8_rd_MasterReqB1() != 0x04)))
#else
  if (((rw_Identifier_l == 0x0611)||(rw_Identifier_l == 0x6002))&&(l_u8_rd_MasterReqB1() != 0x06))

#endif    
    //Falsche Lange variable lange
    
  {
    //Negative Response cb_CONDITION_NOT_CORRECT_s
    Diagnose_NegativeResponse(cb_WRITEDATABYIDENTIFIER_s,cb_INCORECTMESSAGELENGTH_s); 
  }
  else if (rbi_EEPROMLoad_g != FALSE)   // EEPROM Load Finished?  VCO_30
  {
    Diagnose_NegativeResponse(cb_READDATABYIDENTIFIER_s,cb_CONDITION_NOT_CORRECT_s); /*EEPROM not initialised*/
  }
  
#ifndef NOT_SUPPORT_SERVICE_1519TO1525
  else if ((rw_Identifier_l == 0x0611)|| (rw_Identifier_l == 0x6002)|| ((rw_Identifier_l >= 0x1525)&&((rw_Identifier_l <= 0x152C))))
#else 
  else if ((rw_Identifier_l == 0x0611)|| (rw_Identifier_l == 0x6002))
#endif    
  {

    rab_EEPROM_Bytes_toWrite_g[0] = l_u8_rd_MasterReqB7();
    rab_EEPROM_Bytes_toWrite_g[1] = l_u8_rd_MasterReqB6();
    rab_EEPROM_Bytes_toWrite_g[2] = l_u8_rd_MasterReqB5();
    
    if(((rw_Identifier_l == 0x1525) && (cb_EEPROM_0X1525__MAX_g < l_u8_rd_MasterReqB5() )) /*VDR_468 was forgotten*/
         ||((rw_Identifier_l == 0x1526) && (cb_EEPROM_0X1526__MAX_g < l_u8_rd_MasterReqB5() ))
           ||((rw_Identifier_l == 0x1527) && ((cb_EEPROM_0X1527_1_On__MAX_g < (l_u8_rd_MasterReqB5()&0x0F))||((cb_EEPROM_0X1527_1_Off__MAX_g<<4) < (l_u8_rd_MasterReqB5()&0xF0))||(cb_EEPROM_0X1527_2__MAX_g < l_u8_rd_MasterReqB6())||(cb_EEPROM_0X1527_3__MAX_g < l_u8_rd_MasterReqB7()) ))
             ||((rw_Identifier_l == 0x1528) && (cb_EEPROM_0X1528__MAX_g < l_u8_rd_MasterReqB5() ))
               ||((rw_Identifier_l == 0x1529) && (cb_EEPROM_0X1529__MAX_g < l_u8_rd_MasterReqB5() ))
                 ||((rw_Identifier_l == 0x152A) && (cb_EEPROM_0X152A__MAX_g < l_u8_rd_MasterReqB5() ))
                   ||((rw_Identifier_l == 0x152B) && ((cb_EEPROM_0X152B_1_HighDelay_Max < (l_u8_rd_MasterReqB5()&0x07))||(cb_EEPROM_0X152B_1_LOWDelay_Max < (l_u8_rd_MasterReqB5()>>3))||(cb_EEPROM_0X152B_2_THRESH_Max  < (l_u8_rd_MasterReqB6()&0x0F))||((cb_EEPROM_0X152B_2_OFFDELAY_Max<<4) < (l_u8_rd_MasterReqB6()&0xF0)))))
      
      
    {
      /*Negative Response cb_REQUEST_OUT_OF_RANGE_s*/
      Diagnose_NegativeResponse(cb_WRITEDATABYIDENTIFIER_s,cb_REQUEST_OUT_OF_RANGE_s);
    }
    
    else if(((rbi_RainSensor_enabled_g == FALSE )&&((rw_Identifier_l == 0x0611)|| (rw_Identifier_l == 0x6002)))&& 
            (((rab_EEPROM_Bytes_toWrite_g[2] & 0x40) == FALSE) || ((rab_EEPROM_Bytes_toWrite_g[2] & 0x4) == 0x4)))
    {
      /*VCO_223 Block activation of Standby mode in RS kodierbyte0, if RS function is inactive in RSControlflag*/
      /* Block activating rain sensor if Rain sensor functionality is not active */
      Diagnose_NegativeResponse(cb_WRITEDATABYIDENTIFIER_s,cb_CONDITION_NOT_CORRECT_s); 
    }
 
    
    else
      
      
      if(((rb_Kodierbyte2_g == rab_EEPROM_Bytes_toWrite_g[0])         //bereits codiert
          && (rb_Kodierbyte1_g == rab_EEPROM_Bytes_toWrite_g[1])
            && (rb_Kodierbyte0_g == rab_EEPROM_Bytes_toWrite_g[2])
              &&((rw_Identifier_l == 0x0611)|| (rw_Identifier_l == 0x6002)))
         ||(((rw_Identifier_l == 0x1525) && (rb_delay_depressed_park_pointer_g == l_u8_rd_MasterReqB5() ))
            ||((rw_Identifier_l == 0x1526) && (rb_p_t_rs_abfragezyklus_g == l_u8_rd_MasterReqB5() ))
              ||((rw_Identifier_l == 0x1527) && ((rb_p_v_autobahn_on_off_g == l_u8_rd_MasterReqB5())&&(rb_p_t_autobahn_delay_on_g == l_u8_rd_MasterReqB6())&&(rb_p_t_autobahn_delay_off_g == l_u8_rd_MasterReqB7()) ))
                ||((rw_Identifier_l == 0x1528) && (rb_p_t_frontwaschen_g == l_u8_rd_MasterReqB5() ))
                  ||((rw_Identifier_l == 0x1529) && (rb_p_t_lin_idle_g == l_u8_rd_MasterReqB5() ))
                    ||((rw_Identifier_l == 0x152A) && (rb_p_t_tunnel_delay_g == l_u8_rd_MasterReqB5() ))
                      ||((rw_Identifier_l == 0x152C) && (rb_RainNightBitThrs_g == l_u8_rd_MasterReqB5() ))
                        ||((rw_Identifier_l == 0x152B) && ((rb_p_n_regenlichtschwelle_low_high_g == l_u8_rd_MasterReqB5())&&(rb_p_n_regenlichtschwelle_Zeit_g == l_u8_rd_MasterReqB6())))))
        
      {
        rab_DiagRespBuffer_mg[0] = 3; // Length
        rab_DiagRespBuffer_mg[1] = cb_WRITEDATABYIDENTIFIER_s | 0x40;
        rab_DiagRespBuffer_mg[2] = l_u8_rd_MasterReqB3();
        rab_DiagRespBuffer_mg[3] = l_u8_rd_MasterReqB4();
        rbi_EEPROMBytesToWrite_g = FALSE;       //clear flags
        rbi_EEPROMBytesWritten_g = FALSE;
      }
      else
      {
        // *allow coding at all voltages        if(rbi_UnderVoltage_g == FALSE)            //No Undervoltage?*/
        {
          if(rbi_EEPROMBytesToWrite_g == FALSE)   //coding not started?
          {
            rbi_EEPROMBytesWritten_g = FALSE;      //clear bytes written
            
            
            switch (rw_Identifier_l) /*VCO_31 copy data in write buffer for EEPROM*/
            {
              
            case 0x1525: /*0x1525: Direktmodus*/
              rw_EEPROM_Address_to_Write_g = cw_EEPROM_0X1525__ADDRESS_g; //set adress to write
              rb_I2C_EEPROM_bytesToWrite_g = cb_EEPROM_0X1525__BYTES_g;         //set number of bytes to 3
              /*Wartezeit bei Direktmodus*/
              rab_EEPROM_Bytes_toWrite_g[0] = ((l_u8_rd_MasterReqB5()<<cb_EEPROM_0X1525__POSITION_g)|(EEPROM_Struct_AD._c[(cw_EEPROM_0X1525__ADDRESS_g&0xFF)]&(~cb_EEPROM_0X1525__MASK_g)));
              break;
            case 0x1526:
              rw_EEPROM_Address_to_Write_g = cw_EEPROM_0X1526__ADDRESS_g; //set adress to write
              rb_I2C_EEPROM_bytesToWrite_g = cb_EEPROM_0X1526__BYTES_g;         //set number of bytes to 3
              rab_EEPROM_Bytes_toWrite_g[0] = ((l_u8_rd_MasterReqB5()<<cb_EEPROM_0X1526__POSITION_g)|(EEPROM_Struct_AD._c[(byte)(cw_EEPROM_0X1526__ADDRESS_g&0xFF)]&(~cb_EEPROM_0X1526__MASK_g)));
              break;
            case 0x1527:
              rw_EEPROM_Address_to_Write_g = cw_EEPROM_0X1527_1__ADDRESS_g; //set adress to write
              rb_I2C_EEPROM_bytesToWrite_g = cb_EEPROM_0X1527__BYTES_g;         //set number of bytes to 3
              rab_EEPROM_Bytes_toWrite_g[0] = ((l_u8_rd_MasterReqB5()<<cb_EEPROM_0X1527_1__POSITION_g)|(EEPROM_Struct_AD._c[(byte)(cw_EEPROM_0X1527_1__ADDRESS_g&0xFF)]&(~cb_EEPROM_0X1527_1__MASK_g)));
              rab_EEPROM_Bytes_toWrite_g[1] = ((l_u8_rd_MasterReqB6()<<cb_EEPROM_0X1527_2__POSITION_g)|(EEPROM_Struct_AD._c[(byte)(cw_EEPROM_0X1527_2__ADDRESS_g&0xFF)]&(~cb_EEPROM_0X1527_2__MASK_g)));
              rab_EEPROM_Bytes_toWrite_g[2] = ((l_u8_rd_MasterReqB7()<<cb_EEPROM_0X1527_3__POSITION_g)|(EEPROM_Struct_AD._c[(byte)(cw_EEPROM_0X1527_3__ADDRESS_g&0xFF)]&(~cb_EEPROM_0X1527_3__MASK_g)));
              break;
            case 0x1528: /*0x1528: Frontwaschen*/
              rw_EEPROM_Address_to_Write_g = cw_EEPROM_0X1528__ADDRESS_g; //set adress to write
              rb_I2C_EEPROM_bytesToWrite_g = cb_EEPROM_0X1528__BYTES_g;         //set number of bytes to 3
              rab_EEPROM_Bytes_toWrite_g[0] = ((l_u8_rd_MasterReqB5()<<cb_EEPROM_0X1528__POSITION_g)|(EEPROM_Struct_AD._c[(byte)(cw_EEPROM_0X1528__ADDRESS_g&0xFF)]&(~cb_EEPROM_0X1528__MASK_g)));
              break;
            case 0x1529:
              rw_EEPROM_Address_to_Write_g = cw_EEPROM_0X1529__ADDRESS_g; //set adress to write
              rb_I2C_EEPROM_bytesToWrite_g = cb_EEPROM_0X1529__BYTES_g;         //set number of bytes to 3
              rab_EEPROM_Bytes_toWrite_g[0] = ((l_u8_rd_MasterReqB5()<<cb_EEPROM_0X1529__POSITION_g)|(EEPROM_Struct_AD._c[(byte)(cw_EEPROM_0X1529__ADDRESS_g&0xFF)]&(~cb_EEPROM_0X1529__MASK_g)));
              break;
            case 0x152A:
              rw_EEPROM_Address_to_Write_g = cw_EEPROM_0X152A__ADDRESS_g; //set adress to write
              rb_I2C_EEPROM_bytesToWrite_g = cb_EEPROM_0X152A__BYTES_g;         //set number of bytes to 3
              rab_EEPROM_Bytes_toWrite_g[0] = ((l_u8_rd_MasterReqB5()<<cb_EEPROM_0X152A__POSITION_g)|(EEPROM_Struct_AD._c[(byte)(cw_EEPROM_0X152A__ADDRESS_g&0xFF)]&(~cb_EEPROM_0X152A__MASK_g)));
              break;
            case 0x152B:
              rw_EEPROM_Address_to_Write_g = cw_EEPROM_0X152B_1__ADDRESS_g; //set adress to write
              rb_I2C_EEPROM_bytesToWrite_g = cb_EEPROM_0X152B__BYTES_g;         //set number of bytes to 3
              rab_EEPROM_Bytes_toWrite_g[0] = ((l_u8_rd_MasterReqB5()<<cb_EEPROM_0X152B_1__POSITION_g)|(EEPROM_Struct_AD._c[(byte)(cw_EEPROM_0X152B_1__ADDRESS_g&0xFF)]&(~cb_EEPROM_0X152B_1__MASK_g)));
              rab_EEPROM_Bytes_toWrite_g[1] = ((l_u8_rd_MasterReqB6()<<cb_EEPROM_0X152B_2__POSITION_g)|(EEPROM_Struct_AD._c[(byte)(cw_EEPROM_0X152B_2__ADDRESS_g&0xFF)]&(~cb_EEPROM_0X152B_2__MASK_g)));
              break;
            case 0x152C:
              rw_EEPROM_Address_to_Write_g = cw_EEPROM_0X152C__ADDRESS_g  ; //set adress to write
              rb_I2C_EEPROM_bytesToWrite_g = cb_EEPROM_0X152C__BYTES_g;         //set number of bytes to 3
              rab_EEPROM_Bytes_toWrite_g[0] = l_u8_rd_MasterReqB5();
              break;
              
            case 0x6002:
            case 0x0611:
              rw_EEPROM_Address_to_Write_g = cw_EEPROM_CODING_ADDRESS_g; //set adress to write
              rb_I2C_EEPROM_bytesToWrite_g = 3;         //set number of bytes to 3
              break;
            default: /* not supported ID*/
              rw_EEPROM_Address_to_Write_g = 0x00; //set adress to write
              rb_I2C_EEPROM_bytesToWrite_g = 0;         //set number of bytes to 3
              break;
            }
            rbi_EEPROMWriteSuccess_g = TRUE;
            rbi_EEPROMBytesToWrite_g = TRUE;          //set flag for bytes to write
          }
          if(rbi_EEPROMBytesWritten_g == TRUE)     //wait for eeprom bytes written
          {
            rbi_EEPROMBytesToWrite_g = FALSE;       //clear flags
            rbi_EEPROMBytesWritten_g = FALSE;
            if(rbi_EEPROMWriteSuccess_g == TRUE)   //for succes answer positive
            {
              rab_DiagRespBuffer_mg[0] = 3; // Length
              rab_DiagRespBuffer_mg[1] = cb_WRITEDATABYIDENTIFIER_s | 0x40;
              rab_DiagRespBuffer_mg[2] = l_u8_rd_MasterReqB3();
              rab_DiagRespBuffer_mg[3] = l_u8_rd_MasterReqB4();
            }
            else
            {
              Diagnose_NegativeResponse(cb_WRITEDATABYIDENTIFIER_s,cb_CONDITION_NOT_CORRECT_s);  // Kodierung Geht nicht
            }
          }
          else
          {
            Diagnose_NegativeResponse(cb_WRITEDATABYIDENTIFIER_s,cb_RESPONSE_PENDING);
            rb_ResponseToSend_g ++;  // send one response more
          }
        }
      }
  }
  else
  {
    Diagnose_NegativeResponse(cb_WRITEDATABYIDENTIFIER_s,cb_REQUEST_OUT_OF_RANGE_s);                  //Falsche Option
  }
}
#endif


/**************************************************************************
Syntax   : void  Diagnose_ClearCodingResult(void)
Object   : Diagnose_ClearCodingResult()
Parameters : none
Return  : none
Calls   : in Diagnose.c()
***************************************************************************
Pseudo-code : ClearResultofWritingEEPROM
**************************************************************************/
/*void Diagnose_ClearCodingResult(void)
{
rb_Writeresult_g = 0;
rbi_CodingRequest_mg = FALSE;
//rbi_ASICReadEEPromRequest_g = TRUE;

rbi_ASIC_Step_Response_ready = FALSE;
}*/

/**************************************************************************
Syntax   : void  Diagnose_ReadMem_Init(void)
Object   : Diagnose_ReadMem_Init()
Parameters : none
Return  : none
Calls   : in RLS_LIN_B8.c on init
***************************************************************************
Pseudo-code : Read Memory init
**************************************************************************/
#ifdef _SUPPORTMWLLIGHT_
void Diagnose_ReadMem_Init(void)
{
  rw_MemReadAddress_mg = 0xFFFFU;
}
#endif

/**************************************************************************
Syntax   : void  Diagnose_ReadMem_Command(void)
Object   : Diagnose_ReadMem_Command()
Parameters : none
Return  : none
Calls   : in RLS_LIN_B8.c on reception of Message BCM1_LIN1_01
***************************************************************************
Pseudo-code : Read Memory Address to read from
**************************************************************************/
#ifdef _SUPPORTMWLLIGHT_
void Diagnose_ReadMem_Command(void)
{
  static byte rb_MultiplexerStatus_s = 0;
  static word rw_TempAddress_s = 0;
  
  if (l_u8_rd_Adressegment_WWS_RLS() == 0)    // start of new address transmission?
  {
    rb_MultiplexerStatus_s = 1;
    rw_TempAddress_s = l_u8_rd_Adressinhalt_WWS_RLS();
  }
  else if (l_u8_rd_Adressegment_WWS_RLS() == rb_MultiplexerStatus_s)  // following bits correct received?
  {
    rw_TempAddress_s |= (l_u8_rd_Adressinhalt_WWS_RLS()<<(l_u8_rd_Adressegment_WWS_RLS()<<2));
    if (l_u8_rd_Adressegment_WWS_RLS() == 3)    // last segment received?
    {
      rw_MemReadAddress_mg = rw_TempAddress_s;
    }
    else
    {
      rb_MultiplexerStatus_s++;
    }
  }
  else
  {
    rb_MultiplexerStatus_s = 0;  // not correctly received
  }
}
#endif

/**************************************************************************
Syntax   : void  Diagnose_ReadMem_Send(void)
Object   : Diagnose_ReadMem_Send()
Parameters : none
Return  : none
Calls   : in RLS_LIN_B8.c after successful transmission of RLSs_01
***************************************************************************
Pseudo-code : Read Memory send response
**************************************************************************/
#ifdef _SUPPORTMWLLIGHT_
void Diagnose_ReadMem_Send(void)
{
  static byte rb_MultiplexerStatus_s = 0;
  static word rw_TempAddress_s = 0;
  static byte rb_DataToSend_s = 0;
  
  if(rw_MemReadAddress_mg == 0xFFFFU)     // function not active
  {
    l_u8_wr_RLS_Adressegment(0x07);
    l_u8_wr_RLS_Adressinhalt(0x0F);
    rb_MultiplexerStatus_s = 0;
  }
  else
  {
    if((rw_TempAddress_s != rw_MemReadAddress_mg) || (rb_MultiplexerStatus_s == 0x08))   // new address or new cycle
    {
      rw_TempAddress_s = rw_MemReadAddress_mg;
      rb_MultiplexerStatus_s = 0;
      rb_DataToSend_s = Diagnose_GetEEPROMValue(rw_TempAddress_s);
      l_u8_wr_RLS_Adressinhalt(rb_DataToSend_s & 0x0F);
    }
    else if((rb_MultiplexerStatus_s & 0x01) > 0)   // send High Nibble?
    {
      l_u8_wr_RLS_Adressinhalt(rb_DataToSend_s >> 4);
    }
    else // send Low Nibble of next byte?
    {
      rb_DataToSend_s = Diagnose_GetEEPROMValue(rw_TempAddress_s+(rb_MultiplexerStatus_s>>1));
      l_u8_wr_RLS_Adressinhalt(rb_DataToSend_s & 0x0F);
    }
    l_u8_wr_RLS_Adressegment(rb_MultiplexerStatus_s);
    rb_MultiplexerStatus_s++;
  }
}
#endif

/**************************************************************************
Syntax   : void  Diagnose_FillAnswerRBI(void)
Object   : Diagnose_FillAnswerRBI()
Parameters : rab_Buffer_l: buffer to write in (size min. 7byte)
rb_ID_l: ID to fill data
Return  :   0: successful
cb_SUBFUNCTION_NOT_SUPPORTED_s
Calls   : Diagnose_ReadByIdentifier()
Diagnose_AssignNAD()
***************************************************************************
Pseudo-code : Fill data for LIN2.0 mandatory service ReadByIdentifier
**************************************************************************/
#ifdef NODECONFIGURATION
static byte Diagnose_FillAnswerRBI(pbyte rab_Buffer_l,byte rb_ID_l)
{
  byte rb_ReturnValue_l;
  
  rb_ReturnValue_l = 0;
  
  switch (rb_ID_l)
  {
  case 0: // LIN Product Identification
    rab_Buffer_l[0] = 6; // Length
    rab_Buffer_l[1] = cb_LINREADBYIDENTIFIER_s | 0x40;     // RSID
    rab_Buffer_l[2] = (cw_SupplierID_g & 0x00FF);          // Supplier ID LSB
    rab_Buffer_l[3] = (cw_SupplierID_g >> 8);              // Supplier ID MSB
    rab_Buffer_l[4] = (rw_FunctionID_g & 0x00FF);          // Function ID LSB
    rab_Buffer_l[5] = (rw_FunctionID_g >> 8);              // Function ID MSB
    rab_Buffer_l[6] = rb_VariantID_g;                       // Variante
    break;
  case 16:   // Message ID
    rab_Buffer_l[0] = 4; // Length
    rab_Buffer_l[1] = cb_LINREADBYIDENTIFIER_s | 0x40;     // RSID
    rab_Buffer_l[2] = (cawLINMessageID[cb_HANDLE_RLSs_01_g] & 0x00FF);          // Message ID LSB
    rab_Buffer_l[3] = (cawLINMessageID[cb_HANDLE_RLSs_01_g] >> 8);              // Message ID MSB
    rab_Buffer_l[4] = rb_IDRLSs_01_g;          // Protected ID
    rab_Buffer_l[5] = 0xFF;
    rab_Buffer_l[6] = 0xFF;
    break;
  case 17:   // Message ID
    rab_Buffer_l[0] = 4; // Length
    rab_Buffer_l[1] = cb_LINREADBYIDENTIFIER_s | 0x40;     // RSID
    rab_Buffer_l[2] = (cawLINMessageID[cb_HANDLE_BCM1_LIN1_01_g] & 0x00FF);          // Message ID LSB
    rab_Buffer_l[3] = (cawLINMessageID[cb_HANDLE_BCM1_LIN1_01_g] >> 8);              // Message ID MSB
    rab_Buffer_l[4] = rb_IDBCM1_LIN1_01_g;          // Protected ID
    rab_Buffer_l[5] = 0xFF;
    rab_Buffer_l[6] = 0xFF;
    break;
#ifdef HAITEC

#elif defined BAICYX_G20
    
//#elif defined CTCS_M31T custom add new LinID

#elif defined BAICYX_H50
    
#elif defined NL_5 
    
#elif defined ZOTYE_A40

#elif defined DFLQ_RLFSS
    
#elif Zoety_A10
    
#elif Chery_T18
    
#elif Chery_T1A_35A_Standby
    
#elif CHJ_M01
    
#elif Chery_KX63  

#elif GEELY_FS11   
 
#elif GEELY_FS11_NOLIGHT
    
#elif ZOTYE_B01_NEW 
    
#elif BYTON
#elif GEELY2DOT0NORAIN    
#elif GEELY2DOT0 
#elif SOKON
#elif defined GAC_RLS
 case 0x21://SW version
    rab_Buffer_l[0] = 6; // Length
    rab_Buffer_l[1] = cb_LINREADBYIDENTIFIER_s | 0x40;     // RSID
    rab_Buffer_l[2] = 0x21;
    rab_Buffer_l[3] = rab_SoftwareStand_g(2)+'0';
    rab_Buffer_l[4] = rb_GAC_Vehicle_Type;//(rab_SoftwareStand_g(2)>>4) +'0';
    rab_Buffer_l[5] = rb_GAC_SW_Version;
    rab_Buffer_l[6] = 0xFF;
    break;
  case 0x22://HW vERSION
    rab_Buffer_l[0] = 6; // Length
    rab_Buffer_l[1] = cb_LINREADBYIDENTIFIER_s | 0x40;     // RSID
    rab_Buffer_l[2] = 0x22;
    rab_Buffer_l[3] = rab_HardwareStand_g(1);
    rab_Buffer_l[4] = rb_GAC_Vehicle_Type;
    rab_Buffer_l[5] = rb_GAC_HW_Version;
    rab_Buffer_l[6] = 0xFF;
    break;  
#elif ZOTYE_B21    
#else
 case 18:   // Message ID
    rab_Buffer_l[0] = 4; // Length
    rab_Buffer_l[1] = cb_LINREADBYIDENTIFIER_s | 0x40;     // RSID
    rab_Buffer_l[2] = (cawLINMessageID[cb_HANDLE_WWSs_01_g] & 0x00FF);          // Message ID LSB
    rab_Buffer_l[3] = (cawLINMessageID[cb_HANDLE_WWSs_01_g] >> 8);              // Message ID MSB
    rab_Buffer_l[4] = rb_IDWWSs_01_g;          // Protected ID
    rab_Buffer_l[5] = 0xFF;
    rab_Buffer_l[6] = 0xFF;
    break;

#ifdef CS_HT_MODULE
  case 19:   // Message ID
    if ((rbi_HumTemp_Module_enabled_g == TRUE))/*VDR_345   AL    HT-Function and partnumber configurable in EEPROM */
    {
      rab_Buffer_l[0] = 4; // Length
      rab_Buffer_l[1] = cb_LINREADBYIDENTIFIER_s | 0x40;     // RSID
      rab_Buffer_l[2] = (cawLINMessageID[cb_HANDLE_FSs_01_g] & 0x00FF);          // Message ID LSB
      rab_Buffer_l[3] = (cawLINMessageID[cb_HANDLE_FSs_01_g] >> 8);              // Message ID MSB
      rab_Buffer_l[4] = rb_IDFSs_01_g;          // Protected ID
      rab_Buffer_l[5] = 0xFF;
      rab_Buffer_l[6] = 0xFF;
    }
    else
    {
      rb_ReturnValue_l = cb_SUBFUNCTION_NOT_SUPPORTED_s;                //Negative Response: Subfunction not supported
    }
    break;
#endif //CS_HT_MODULE
    
#ifdef CS_HT_ENH_MODULE
  case 21:   // Message ID
     if ((rbi_HumTemp_Module_enabled_g == TRUE))/*VDR_345   AL    HT-Function and partnumber configurable in EEPROM */
    {
      rab_Buffer_l[0] = 4; // Length
      rab_Buffer_l[1] = cb_LINREADBYIDENTIFIER_s | 0x40;     // RSID
      rab_Buffer_l[2] = (cawLINMessageID[cb_HANDLE_FSdataEnhanced_g] & 0x00FF);          // Message ID LSB
      rab_Buffer_l[3] = (cawLINMessageID[cb_HANDLE_FSdataEnhanced_g] >> 8);              // Message ID MSB
      rab_Buffer_l[4] = rb_IDFSs_Enh_01_g;          // Protected ID
      rab_Buffer_l[5] = 0xFF;
      rab_Buffer_l[6] = 0xFF;
    }
    
    else
    {
      rb_ReturnValue_l = cb_SUBFUNCTION_NOT_SUPPORTED_s;                //Negative Response: Subfunction not supported
    }
    break;  
#endif//CS_HT_ENH_MODULE 
    
#ifdef CS_SOLAR 
   case 20:   // Message ID
    if ((rbi_SoSe_Enabled_g == TRUE))/*VDR_345   AL    HT-Function and partnumber configurable in EEPROM */
    {
      rab_Buffer_l[0] = 4; // Length
      rab_Buffer_l[1] = cb_LINREADBYIDENTIFIER_s | 0x40;     // RSID
      rab_Buffer_l[2] = (cawLINMessageID[cb_HANDLE_SoSes_01] & 0x00FF);          // Message ID LSB
      rab_Buffer_l[3] = (cawLINMessageID[cb_HANDLE_SoSes_01] >> 8);              // Message ID MSB
      rab_Buffer_l[4] = rb_IDSOSES_01_g;          // Protected ID
      rab_Buffer_l[5] = 0xFF;
      rab_Buffer_l[6] = 0xFF;
    }
    else
    {
      rb_ReturnValue_l = cb_SUBFUNCTION_NOT_SUPPORTED_s;                //Negative Response: Subfunction not supported
    }
    break;
#endif//CS_SOLAR        

#ifdef CS_ERR_FRAME
  case 22:   // Message ID
    rab_Buffer_l[0] = 4; // Length
    rab_Buffer_l[1] = cb_LINREADBYIDENTIFIER_s | 0x40;     // RSID
    rab_Buffer_l[2] = (cawLINMessageID[cb_HANDLE_ERROR_DATA_RLS_g] & 0x00FF);          // Message ID LSB
    rab_Buffer_l[3] = (cawLINMessageID[cb_HANDLE_ERROR_DATA_RLS_g] >> 8);              // Message ID MSB
    rab_Buffer_l[4] = rb_IDERRDATA_01_g;          // Protected ID
    rab_Buffer_l[5] = 0xFF;
    rab_Buffer_l[6] = 0xFF;
    break;
#endif
    
#ifdef BRILLIANCE_M8X
   case 23:   // Message ID
    rab_Buffer_l[0] = 4; // Length
    rab_Buffer_l[1] = cb_LINREADBYIDENTIFIER_s | 0x40;     // RSID
    rab_Buffer_l[2] = (cawLINMessageID[cb_HANDLE_TRANSMISSION_01_g] & 0x00FF);          // Message ID LSB
    rab_Buffer_l[3] = (cawLINMessageID[cb_HANDLE_TRANSMISSION_01_g] >> 8);              // Message ID MSB
    rab_Buffer_l[4] = rb_TRANSMISSION_01_g;          // Protected ID
    rab_Buffer_l[5] = 0xFF;
    rab_Buffer_l[6] = 0xFF;
    break; 
#endif   
    
#ifdef NL_5
  case 32:
    rab_Buffer_l[0] = 6; // Length
    rab_Buffer_l[1] = cb_LINREADBYIDENTIFIER_s | 0x40;     // RSID
    rab_Buffer_l[2] = rab_SoftwareStand_g(0);
    rab_Buffer_l[3] = rab_SoftwareStand_g(1);
    rab_Buffer_l[4] = (rab_SoftwareStand_g(2)>>4) +'0';
    rab_Buffer_l[5] = (rab_SoftwareStand_g(2)&0x0F)+'0';
    rab_Buffer_l[6] = 0xFF;
    break;
  case 33:
    rab_Buffer_l[0] = 6; // Length
    rab_Buffer_l[1] = cb_LINREADBYIDENTIFIER_s | 0x40;     // RSID
    rab_Buffer_l[2] = cb_HARDWARESTAND_g;
    rab_Buffer_l[3] = 0x30;
    rab_Buffer_l[4] = rab_HardwareStand_g(0);
    rab_Buffer_l[5] = rab_HardwareStand_g(1);
    rab_Buffer_l[6] = 0xFF;
    break;
#endif
#endif    
  default:
    rb_ReturnValue_l = cb_SUBFUNCTION_NOT_SUPPORTED_s;                  //Negative Response: Subfunction not supported
    break;
  }
  
  return (rb_ReturnValue_l);
}
#endif

/**************************************************************************
Syntax   : void  Diagnose_ReadByIdentifier(void)
Object   : Diagnose_ReadByIdentifier()
Parameters : none
Return  : none
Calls   : in rls_lin_b8.c()
***************************************************************************
Pseudo-code : LIN2.0 mandatory service ReadByIdentifier
**************************************************************************/
#ifdef NODECONFIGURATION
void Diagnose_ReadByIdentifier(void)
{
  
#ifdef GAC_RLS
   if (l_u8_rd_MasterReqB1() != cb_REQLENGTHSIDB2_s)      /*VDR_508*/               // and Reqest length correct
    {
      Diagnose_NegativeResponse(cb_LINREADBYIDENTIFIER_s,cb_INCORECTMESSAGELENGTH_s);//Negative Response: 
    }
    else if (Diagnose_FillAnswerRBI(rab_DiagRespBuffer_mg,l_u8_rd_MasterReqB3()) == cb_SUBFUNCTION_NOT_SUPPORTED_s)
    {
      //Negative Response: Subfunction not supported
      Diagnose_NegativeResponse(cb_LINREADBYIDENTIFIER_s,cb_SUBFUNCTION_NOT_SUPPORTED_s);
    }
    else
    {
      /* MISRA check */
    }
#else
 word rw_SupplierID_l;
  word rw_FunctionID_l;
  rw_SupplierID_l = (((word)l_u8_rd_MasterReqB5())<<8)+l_u8_rd_MasterReqB4();     // get supplier ID from request frame
  rw_FunctionID_l = (((word)l_u8_rd_MasterReqB7())<<8)+l_u8_rd_MasterReqB6();     // get function ID from request frame
  // supplier ID correct or wildcard used?
  if((((rw_SupplierID_l == cw_SupplierID_g) || (rw_SupplierID_l == cw_SupplierIDWildcard_g))   
      // and function ID correct or wildcard used?
      && ((rw_FunctionID_l == rw_FunctionID_g) || (rw_FunctionID_l == cw_FunctionIDWildcard_g)))  
     )
  {
    
    if (l_u8_rd_MasterReqB1() != cb_REQLENGTHSIDB2_s)      /*VDR_508*/               // and Reqest length correct
    {
      Diagnose_NegativeResponse(cb_LINREADBYIDENTIFIER_s,cb_INCORECTMESSAGELENGTH_s);//Negative Response: 
    }
    else if (Diagnose_FillAnswerRBI(rab_DiagRespBuffer_mg,l_u8_rd_MasterReqB3()) == cb_SUBFUNCTION_NOT_SUPPORTED_s)
    {
      //Negative Response: Subfunction not supported
      Diagnose_NegativeResponse(cb_LINREADBYIDENTIFIER_s,cb_SUBFUNCTION_NOT_SUPPORTED_s);
    }
    else
    {
      /* MISRA check */
    }
    
  }
  else
  {
    // send nothing
    l_u8_wr_MasterReqB0(0xff);
  }
 #endif
}   
#endif
/**************************************************************************
Syntax   : void  Diagnose_AssignIdentifier(void)
Object   : Diagnose_AssignIdentifier()
Parameters : none
Return  : none
Calls   : in rls_lin_b8.c()
***************************************************************************
Pseudo-code : LIN2.0 mandatory service AssignIdentifier
**************************************************************************/
#ifdef NODECONFIGURATION
void Diagnose_AssignIdentifier(void)
{
  word rw_SupplierID_l;
  word rw_MessageID_l;
  byte rb_NewIdentifier_l;
  byte rb_MsgHandle_l;
  
  if(rb_Diagnosticstate_g == 0)
  {
    rb_Diagnosticstate_g++;
    rw_SupplierID_l = (((word)l_u8_rd_MasterReqB4())<<8)+l_u8_rd_MasterReqB3();  // get supplier ID from request frame
    rw_MessageID_l = (((word)l_u8_rd_MasterReqB6())<<8)+l_u8_rd_MasterReqB5();   // get function ID from request frame
    rb_NewIdentifier_l = l_u8_rd_MasterReqB7();
    // supplier ID correct or wildcard used?
    if(((rw_SupplierID_l == cw_SupplierID_g) || (rw_SupplierID_l == cw_SupplierIDWildcard_g)))    
    {
      if (l_u8_rd_MasterReqB1() != cb_REQLENGTHSIDB1_s)      /*VDR_508*/                  // and Reqest length correct
      {
        Diagnose_NegativeResponse(cb_LINREADBYIDENTIFIER_s,cb_INCORECTMESSAGELENGTH_s);  //Negative Response: 
      }
      else
      {
        rb_MsgHandle_l = 0;     // reset message handle
        // while Message ID not entry in list or end of list
        
        while((rw_MessageID_l != cawLINMessageID[rb_MsgHandle_l]) && (rb_MsgHandle_l < (kLinNumberOfObjects-1)))   
        {
          rb_MsgHandle_l++;   //increase message handle
        }
        
        if((rw_MessageID_l == cawLINMessageID[rb_MsgHandle_l]) && (rbi_UnderVoltage_g == FALSE)) // message ID in list?
        {
          if((rb_NewIdentifier_l != cb_UNASSIGNED_FRAMEID_g)
             && ((sci_CheckParity(rb_NewIdentifier_l) == FALSE)    // not a valid identifier?
                 || ((rb_NewIdentifier_l & 0x3F) >= 0x3C)))
          {
            rw_EEPROM_Address_to_Write_g = 0xFFFFU;        // don't write
            rb_I2C_EEPROM_bytesToWrite_g = 0;
          }
          else
          {
            rbi_EEPROMBytesWritten_g = FALSE;
            switch(rb_MsgHandle_l)      // switch to message handle
            {
            case cb_HANDLE_RLSs_01_g:
              rw_EEPROM_Address_to_Write_g = CW_E2_IDRLSS_01_ADRESS;         /* set address to write */
              rb_I2C_EEPROM_bytesToWrite_g = 1;
              break;
            case cb_HANDLE_BCM1_LIN1_01_g:
              rw_EEPROM_Address_to_Write_g = CW_E2_IDBCM1_LIN1_01_ADRESS;    /* set address to write */
              rb_I2C_EEPROM_bytesToWrite_g = 1;
              break;
#ifdef HAITEC              
#elif defined BAICYX_G20              
//#elif defined CTCS_M31T   custom add new LinID           
#elif defined BAICYX_H50             
#elif defined NL_5              
#elif defined ZOTYE_A40  
#elif defined DFLQ_RLFSS         
#elif Zoety_A10   
#elif Chery_T18
#elif Chery_T1A_35A_Standby
#elif CHJ_M01 
#elif Chery_KX63
#elif GEELY_FS11
#elif GEELY_FS11_NOLIGHT 
#elif ZOTYE_B01_NEW
#elif BYTON
#elif GEELY2DOT0NORAIN              
#elif GEELY2DOT0 
#elif SOKON
#elif defined GAC_RLS
#elif defined ZOTYE_B21             
#else
            case cb_HANDLE_WWSs_01_g:
              rw_EEPROM_Address_to_Write_g = CW_E2_IDWWSS_01_ADRESS;         /* set address to write */
              rb_I2C_EEPROM_bytesToWrite_g = 1;
              break;
#ifdef BRILLIANCE_M8X
             case cb_HANDLE_TRANSMISSION_01_g:
              rw_EEPROM_Address_to_Write_g = CW_E2_IDTRANSMISSION_01_ADDRESS;         /* set address to write */
              rb_I2C_EEPROM_bytesToWrite_g = 1;
              break;             
#endif 

#ifdef CS_SOLAR
            case cb_HANDLE_SoSes_01:
              if((rbi_SoSe_Enabled_g == TRUE))
              {
                rw_EEPROM_Address_to_Write_g = CW_E2_IDSOSES_01_ADRESS;       /* set address to write */
                rb_I2C_EEPROM_bytesToWrite_g = 1;
              }
              else
              {
                rw_EEPROM_Address_to_Write_g = 0xFFFFU;                   /* nothing to send */
                rb_I2C_EEPROM_bytesToWrite_g = 0;
                
              }
              break;
#endif //CS_SOLAR
              
#ifdef CS_HT_MODULE              
            case cb_HANDLE_FSs_01_g:
              /*VDR_345 AL HT-Function and partnumber configurable in EEPROM */
              if ((rbi_HumTemp_Module_enabled_g == TRUE))
              {
                rw_EEPROM_Address_to_Write_g = CW_E2_IDFSS_01_ADRESS;         /* set address to write */
                rb_I2C_EEPROM_bytesToWrite_g = 1;
              }
              else
              {
                rw_EEPROM_Address_to_Write_g = 0xFFFFU;                   /* nothing to send */
                rb_I2C_EEPROM_bytesToWrite_g = 0;
              }
              break;
#endif          
              
#ifdef CS_HT_ENH_MODULE            
              
            case cb_HANDLE_FSdataEnhanced_g:

                rw_EEPROM_Address_to_Write_g = CW_E2_IDFSS_ENH_01_ADRESS;         /* set address to write */
                rb_I2C_EEPROM_bytesToWrite_g = 1;

              break;

         
#endif //CS_HT_MODULE  
              
#ifdef CS_ERR_FRAME              
            case cb_HANDLE_ERROR_DATA_RLS_g:
                rw_EEPROM_Address_to_Write_g = CW_E2_IDFSS_ERR_DATA_ADRESS;         /* set address to write */
                rb_I2C_EEPROM_bytesToWrite_g = 1;
              break;
#endif 
#endif 
            default:
              rw_EEPROM_Address_to_Write_g = 0xFFFFU;                   /* nothing to send */
              rb_I2C_EEPROM_bytesToWrite_g = 0;
              break;
            }
          }
          
          if((rb_I2C_EEPROM_bytesToWrite_g > 0)&&((rw_EEPROM_Address_to_Write_g+(rb_I2C_EEPROM_bytesToWrite_g-1))< (cw_ADRPRE_PD_mg + cb_NumberofEEPROMCells_PD_g))) /*VCO_31 check max value to avoid overflow*/
          {
            if (EEPROM_Struct_PD._c[(rw_EEPROM_Address_to_Write_g & 0xff)] != rb_NewIdentifier_l)
            {
              // update RAM mirror to update Table
              EEPROM_Struct_PD._c[(rw_EEPROM_Address_to_Write_g & 0xff)] = rb_NewIdentifier_l;
              ApplTableInit();  // reinit LIN message table
              rab_EEPROM_Bytes_toWrite_g[0] = rb_NewIdentifier_l;     // set data to write
              // write different value to RAM mirror (only changed values are written in EEPROM)
              EEPROM_Struct_PD._c[(rw_EEPROM_Address_to_Write_g & 0xff)] = rab_EEPROM_Bytes_toWrite_g[0]-1;   
              rbi_EEPROMBytesWritten_g = FALSE; /* VDR 262 AL  Reset Status bit*/
              rbi_EEPROMBytesToWrite_g = TRUE;          //set flag for bytes to write
            }
            else
            {
              rbi_EEPROMWriteSuccess_g = TRUE;       //set succes bit
              rbi_EEPROMBytesWritten_g = TRUE;       //set EEPROM written flag!
            }
          }
          else
          {
            Diagnose_NegativeResponse(cb_LINASSIGNIDENTIFIER_s,cb_CONDITION_NOT_CORRECT_s);  // Schreiben geht nicht
            rb_Diagnosticstate_g = 0xFF;    // response ready
          }
        }
        else
        {
          Diagnose_NegativeResponse(cb_LINASSIGNIDENTIFIER_s,cb_CONDITION_NOT_CORRECT_s);  // Schreiben geht nicht
          rb_Diagnosticstate_g = 0xFF;    // response ready
        }
      }
    }
    else
    {
      // send nothing
      l_u8_wr_MasterReqB0(0xff);
    }
  }
  else if (rb_Diagnosticstate_g == 1)
  {
    if(rbi_EEPROMBytesWritten_g == TRUE)     //wait for eeprom bytes written
    {
      rbi_EEPROMBytesToWrite_g = FALSE;       //clear flags
      rbi_EEPROMBytesWritten_g = FALSE;
      if(rbi_EEPROMWriteSuccess_g == TRUE)   //for succes answer positive
      {
        rab_DiagRespBuffer_mg[0] = 1; // Length
        rab_DiagRespBuffer_mg[1] = cb_LINASSIGNIDENTIFIER_s+0x40;   //positive response
        rbi_ReInitTable_g = 1;  //LIN init look-up table with new ID
        rb_Diagnosticstate_g = 0xFF;    // response ready
        rb_ResponseToSend_g = 1;
      }
      else
      {
        Diagnose_NegativeResponse(cb_LINASSIGNIDENTIFIER_s,cb_CONDITION_NOT_CORRECT_s);  // Schreiben geht nicht
        rb_Diagnosticstate_g = 0xFF;    // response ready
        rb_ResponseToSend_g = 1;
      }
    }
    else
    {
      Diagnose_NegativeResponse(cb_LINASSIGNIDENTIFIER_s,cb_RESPONSE_PENDING);  // Schreiben dauert noch
      rb_ResponseToSend_g ++;  // send one response more        -> overflow not expected no risk
    }
  }
  else {} /*Misra Rule 14.10*/
}
#endif

/**************************************************************************
Syntax   : void  Diagnose_AssignNAD(void)
Object   : Diagnose_AssignNAD()
Parameters : none
Return  : none
Calls   : in rls_lin_b8.c()
***************************************************************************
Pseudo-code : LIN2.0 Optional service Assign NAD
**************************************************************************/
#ifdef NODECONFIGURATION
#ifdef _SUPPORTASSIGNNAD_
void Diagnose_AssignNAD(void)
{
  word rw_SupplierID_l;
  word rw_FunctionID_l;
  byte rb_NewNAD_l;
  byte rb_SelectedByte_l;
  
  if(rb_Diagnosticstate_g == 0)
  {
    rb_Diagnosticstate_g++;
    
    rb_NewNAD_l = l_u8_rd_MasterReqB7();
    
    if (l_u8_rd_MasterReqB2() == cb_LINASSIGNNAD_s)    // AssignNAD
    {
      
      rw_SupplierID_l = (((word)l_u8_rd_MasterReqB4())<<8)+l_u8_rd_MasterReqB3(); // get supplier ID from request frame
      rw_FunctionID_l = (((word)l_u8_rd_MasterReqB6())<<8)+l_u8_rd_MasterReqB5(); // get function ID from request frame
      // supplier ID correct or wildcard used?
      if ((((rw_SupplierID_l != cw_SupplierID_g) && (rw_SupplierID_l != cw_SupplierIDWildcard_g))   
           || ((rw_FunctionID_l != rw_FunctionID_g) && (rw_FunctionID_l != cw_FunctionIDWildcard_g))))  
      {
        l_u8_wr_MasterReqB0(0xff);           // send no answer and abort command for the above conditions
      }
    }
    else  // conditional change NAD
    {
       // get response on RDBID successful?
      if ((Diagnose_FillAnswerRBI(rab_DiagRespBuffer_mg,l_u8_rd_MasterReqB3()) != cb_SUBFUNCTION_NOT_SUPPORTED_s)   
          )
      {
        if ((l_u8_rd_MasterReqB4() >= 1) && (l_u8_rd_MasterReqB4() <= 5))          // Byte within valid range?
        {
          rb_SelectedByte_l = rab_DiagRespBuffer_mg[l_u8_rd_MasterReqB4()+1];     // extract data selected by Byte
          rb_SelectedByte_l = rb_SelectedByte_l ^ l_u8_rd_MasterReqB6();          // bitwise XOR with Invert
          rb_SelectedByte_l = rb_SelectedByte_l & l_u8_rd_MasterReqB5();          // bitwise AND with Mask
          
          if (rb_SelectedByte_l != 0)
          {
            l_u8_wr_MasterReqB0(0xff);           // send nothing
          }
        }
        else
        {
          l_u8_wr_MasterReqB0(0xff);           // send nothing
        }
      }
      else
      {
        l_u8_wr_MasterReqB0(0xff);           // send nothing
      }
    }
    if (l_u8_rd_MasterReqB1() != cb_REQLENGTHSIDB1_s)      /*VDR_508*/                  // and Reqest length correct
    {
      Diagnose_NegativeResponse(cb_LINREADBYIDENTIFIER_s,cb_INCORECTMESSAGELENGTH_s); //Negative Response: 
    }
    else if (l_u8_rd_MasterReqB0() != 0xff)   // no incorrect condition
    {
      if((rb_NewNAD_l >= CB_MIN_NAD) && (rb_NewNAD_l <= CB_MAX_NAD) && (rbi_UnderVoltage_g == FALSE))     // valid NAD?
      {
        rw_EEPROM_Address_to_Write_g = CW_E2_NAD_ADRESS;       // set address to write
        
        rb_I2C_EEPROM_bytesToWrite_g = 1;
        rab_EEPROM_Bytes_toWrite_g[0] = rb_NewNAD_l;     // set data to write
        rbi_EEPROMBytesWritten_g = FALSE; /* VDR 262 AL  Reset Status bit*/
        rbi_EEPROMBytesToWrite_g = TRUE;          //set flag for bytes to write
        Diagnose_NegativeResponse(l_u8_rd_MasterReqB2(),cb_RESPONSE_PENDING);  // Schreiben dauert noch
      }
      else
      {
        Diagnose_NegativeResponse(l_u8_rd_MasterReqB2(),cb_CONDITION_NOT_CORRECT_s);  // Schreiben geht nicht
        rb_Diagnosticstate_g = 0xFF;    // response ready
      }
    }
    else
    {
      rb_Diagnosticstate_g = 0xFF;    // response ready
    }
  }
  else if (rb_Diagnosticstate_g == 1)
  {
    if(rbi_EEPROMBytesWritten_g == TRUE)     //wait for eeprom bytes written
    {
      rbi_EEPROMBytesToWrite_g = FALSE;       //clear flags
      rbi_EEPROMBytesWritten_g = FALSE;
      if(rbi_EEPROMWriteSuccess_g == TRUE)   //for succes answer positive
      {
        rab_DiagRespBuffer_mg[0] = 1; // Length
        rab_DiagRespBuffer_mg[1] = l_u8_rd_MasterReqB2()+0x40;   //positive response
        rb_Diagnosticstate_g = 0xFF;    // response ready
        rb_ResponseToSend_g = 1;
      }
      else
      {
        Diagnose_NegativeResponse(l_u8_rd_MasterReqB2(),cb_CONDITION_NOT_CORRECT_s);  // Schreiben geht nicht
        rb_Diagnosticstate_g = 0xFF;    // response ready
        rb_ResponseToSend_g = 1;
      }
    }
    else
    {
      Diagnose_NegativeResponse(l_u8_rd_MasterReqB2(),cb_RESPONSE_PENDING);  // Schreiben dauert noch
      rb_ResponseToSend_g ++;  // send one response more
    }
    
  }
  else {} /*Misra Rule 14.10*/
  
}


#endif /* _SUPPORTASSIGNNAD_ */
#endif /* NODECONFIGURATION */


#ifdef NODECONFIGURATION
#ifdef _SUPPORTLINDATADUMP_
void Diagnose_LINDATADUMP(void)
{
#ifdef NL_5
  if(rbi_Ignition_g == TRUE)
  {
    if (l_u8_rd_MasterReqB1() == 6)      /*VDR_508*/                  // and Reqest length correct
    {
      if (l_u8_rd_MasterReqB3() == cb_LINDATADUMP_WRITE)
      { 
        if((LINDATADUMP_READ_B0 == l_u8_rd_MasterReqB4()) && \
           (LINDATADUMP_READ_B1 == l_u8_rd_MasterReqB5()) && \
           (LINDATADUMP_READ_B2 == l_u8_rd_MasterReqB6()))
        {          
          rab_DiagRespBuffer_mg[0] = 6; 
          rab_DiagRespBuffer_mg[1] = cb_LINDATADUMP_s | 0x40;
          rab_DiagRespBuffer_mg[2] = cb_LINDATADUMP_WRITE;
          rab_DiagRespBuffer_mg[3] = 0;
          rab_DiagRespBuffer_mg[4] = 255;
          rab_DiagRespBuffer_mg[5] = 255;
          rab_DiagRespBuffer_mg[6] = 255;    
        }
        else
        {
          if((rbi_EEPROMBytesWritten_g == TRUE) || (rbi_EEPROMBytesToWrite_g == FALSE))   //coding not started?
          {                              
            rab_EEPROM_Bytes_toWrite_g[0] = l_u8_rd_MasterReqB4();
            rab_EEPROM_Bytes_toWrite_g[1] = l_u8_rd_MasterReqB5();
            rab_EEPROM_Bytes_toWrite_g[2] = l_u8_rd_MasterReqB6();
            
            rw_EEPROM_Address_to_Write_g = 351;
            rb_I2C_EEPROM_bytesToWrite_g = 3;
            /***Blake_LI update this for GEELY_NL-5 project 2018_09_07***/                      
            rbi_EEPROMBytesToWrite_g = TRUE;       //set flag for bytes to write
            rbi_EEPROMBytesWritten_g = FALSE;      //clear bytes written
                                   
            rab_DiagRespBuffer_mg[0] = 6; // Length
            rab_DiagRespBuffer_mg[1] = cb_LINDATADUMP_s | 0x40;
            rab_DiagRespBuffer_mg[2] = cb_LINDATADUMP_WRITE;
            rab_DiagRespBuffer_mg[3] = 0;
            rab_DiagRespBuffer_mg[4] = 255;
            rab_DiagRespBuffer_mg[5] = 255;
            rab_DiagRespBuffer_mg[6] = 255;           
          }
          else
          {
            Diagnose_NegativeResponse(cb_LINDATADUMP_s,cb_RESPONSE_PENDING);
            rb_ResponseToSend_g ++;  // send one response more
          } 
        }
      }
      else if(l_u8_rd_MasterReqB3() == cb_LINDATADUMP_READ)
      {
        rab_DiagRespBuffer_mg[0] = 6;                                // Length
        rab_DiagRespBuffer_mg[1] = cb_LINDATADUMP_s | 0x40;          // REID
        rab_DiagRespBuffer_mg[2] = cb_LINDATADUMP_READ;              // LID
        rab_DiagRespBuffer_mg[3] = LINDATADUMP_READ_B0;              // B0
        rab_DiagRespBuffer_mg[4] = LINDATADUMP_READ_B1;              // B1
        rab_DiagRespBuffer_mg[5] = LINDATADUMP_READ_B2;              // B2
        rab_DiagRespBuffer_mg[6] = 255;
      }
      else
      {
        Diagnose_NegativeResponse(cb_LINDATADUMP_s,cb_REQUEST_OUT_OF_RANGE_s); //Negative Response:
      }                             
    }
    else
    {
      Diagnose_NegativeResponse(cb_LINDATADUMP_s,cb_INCORECTMESSAGELENGTH_s); //Negative Response: 
    }
    
  }     
  else
  {
    Diagnose_NegativeResponse(cb_LINDATADUMP_s,cb_CONDITION_NOT_CORRECT_s); //Negative Response: Ignition off
  }
#endif
} 
#endif /* _SUPPORTASSIGNNAD_ */
#endif /* NODECONFIGURATION */
/**************************************************************************
Syntax   : void  SetSystemBezeichnung(void)
Object   : SetSystemBezeichnung()
Parameters : none
Return  : none
Calls   : 
***************************************************************************
Pseudo-code : 
**************************************************************************/

static void SetSystemBezeichnung(void)  
{
  const Systembezeichnung_t  Systembezeichnung[] = {
  /* ID     Name */
  SYSTEM_NAMES_RLS
  };
  static const byte __far cab_SystembezeichnungInvalid[16] = "RLFSS_INVALID   ";
  byte rb_LoopCounter;
  byte rb_Length_l;
  byte rb_Loop_brk_l;
  pb_Systembezeichnung_mg = (byte __far*)&cab_SystembezeichnungInvalid[0];
  rb_Loop_brk_l  = FALSE;
  
  rb_Length_l = sizeof(Systembezeichnung)/sizeof(Systembezeichnung_t);
  for(rb_LoopCounter = 0;((rb_LoopCounter < rb_Length_l)&&(rb_Loop_brk_l == FALSE)) ; rb_LoopCounter++)
  {
    if((rb_RSControlFlags_g) == Systembezeichnung[rb_LoopCounter].Id)
    {
      pb_Systembezeichnung_mg =(byte __far*) &Systembezeichnung[rb_LoopCounter].SystemName[0];
      rb_Loop_brk_l = TRUE;
    }
  }

}  
#ifndef BRILLIANCE_M8X
static void getSwPartNumberAscii(byte *result){
#ifdef HAITEC
  result[0] = rab_Audi_SW_Partnumber_g(0);
  result[1] = rab_Audi_SW_Partnumber_g(1);
  result[2] = rab_Audi_SW_Partnumber_g(2);
  result[3] = Diagnosis_BCDtoASCII(rab_Audi_SW_Partnumber_g(3)>>4);
  result[4] = Diagnosis_BCDtoASCII(rab_Audi_SW_Partnumber_g(3)&0x0F);
  result[5] = rab_Audi_SW_Partnumber_g(4);
  result[6] = rab_Audi_SW_Partnumber_g(5);
  result[7] = Diagnosis_BCDtoASCII(rab_Audi_SW_Partnumber_g(6)>>4);
  result[8] = Diagnosis_BCDtoASCII(rab_Audi_SW_Partnumber_g(6)&0x0F);

  result[9]  = rab_Audi_SW_Partnumber_g(7); /* SW-Partnumber index*/
#elif defined(FOTON_S700)
  result[0] = rab_Audi_SW_Partnumber_g(0);
  result[1] = rab_Audi_SW_Partnumber_g(1);
  result[2] = rab_Audi_SW_Partnumber_g(2);
  result[3] = Diagnosis_BCDtoASCII(rab_Audi_SW_Partnumber_g(3)>>4);
  result[4] = Diagnosis_BCDtoASCII(rab_Audi_SW_Partnumber_g(3)&0x0F);
  result[5] = Diagnosis_BCDtoASCII(rab_Audi_SW_Partnumber_g(4)>>4);
  result[6] = Diagnosis_BCDtoASCII(rab_Audi_SW_Partnumber_g(4)&0x0F);
  result[7] = Diagnosis_BCDtoASCII(rab_Audi_SW_Partnumber_g(5)>>4);
  result[8] = Diagnosis_BCDtoASCII(rab_Audi_SW_Partnumber_g(5)&0x0F);    
  result[9]  = rab_Audi_SW_Partnumber_g(6); /* SW-Partnumber index*/  
#elif defined (BAICYX_G20)
  result[0] = Diagnosis_BCDtoASCII(rab_Audi_SW_Partnumber_g(0)>>4);
  result[1] = Diagnosis_BCDtoASCII(rab_Audi_SW_Partnumber_g(0)&0x0F);
  result[2] = Diagnosis_BCDtoASCII(rab_Audi_SW_Partnumber_g(1)>>4);
  result[3] = Diagnosis_BCDtoASCII(rab_Audi_SW_Partnumber_g(1)&0x0F);
  result[4] = Diagnosis_BCDtoASCII(rab_Audi_SW_Partnumber_g(2)>>4);
  result[5] = Diagnosis_BCDtoASCII(rab_Audi_SW_Partnumber_g(2)&0x0F);
  result[6] = Diagnosis_BCDtoASCII(rab_Audi_SW_Partnumber_g(3)>>4);
  result[7] = Diagnosis_BCDtoASCII(rab_Audi_SW_Partnumber_g(3)&0x0F);
  result[8] = rab_Audi_SW_Partnumber_g(4);
  
  result[9] = rab_Audi_SW_Partnumber_g(5); 
  result[10] = rab_Audi_SW_Partnumber_g(6);
  result[11] = rab_Audi_SW_Partnumber_g(7); 
  
#else  
  result[0] = rab_Audi_SW_Partnumber_g(0);
  result[1] = rab_Audi_SW_Partnumber_g(1);
  result[2] = rab_Audi_SW_Partnumber_g(2);
  result[3] = Diagnosis_BCDtoASCII(rab_Audi_SW_Partnumber_g(3)>>4);
  result[4] = Diagnosis_BCDtoASCII(rab_Audi_SW_Partnumber_g(3)&0x0F);
  result[5] = Diagnosis_BCDtoASCII(rab_Audi_SW_Partnumber_g(4)>>4);
  result[6] = Diagnosis_BCDtoASCII(rab_Audi_SW_Partnumber_g(4)&0x0F);
  result[7] = Diagnosis_BCDtoASCII(rab_Audi_SW_Partnumber_g(5)>>4);
  result[8] = Diagnosis_BCDtoASCII(rab_Audi_SW_Partnumber_g(5)&0x0F);

  result[9]  = rab_Audi_SW_Partnumber_g(6); /* SW-Partnumber index*/
  result[10] = rab_Audi_SW_Partnumber_g(7); /* SW-Partnumber index*/
#endif
}
#endif
#if (defined FERRARI) || (defined GEN3_5A_FCA) || (defined FIAT_330)
/**************************************************************************
  Syntax   : void  Diagnose_ECUInfo(void)
  Object   : Diagnose_ECUInfo()
  Parameters : none
  Return  : none
  Calls   : in rls_lin_b8.c()
***************************************************************************
  Pseudo-code : LIN2.0 Mandatory service ECU Info
**************************************************************************/


void Diagnose_ECUInfo(void)           /* Diag Service C0 for Chrysler PF*/
{
  
  if (l_u8_rd_MasterReqB1() == cb_REQLENGTHSIDC0_s)
    
  {
    rab_DiagRespBuffer_mg[0] = 6; // PCI
    rab_DiagRespBuffer_mg[1] = 0x00; // RSID
    rab_DiagRespBuffer_mg[2] = 0xC0; // only C7 and C8 are supported
    rab_DiagRespBuffer_mg[3] = 0x00; // C9, CA and CB NOT Supported
    rab_DiagRespBuffer_mg[4] = 0xFF;  // Reserved
    rab_DiagRespBuffer_mg[5] = ((rab_SoftwareStand_g(1))-'0'); // SW Version (MSB)
    rab_DiagRespBuffer_mg[6] = (rab_SoftwareStand_g(2)); // SW Version (LSB)
  }
  
  else
  {
    Diagnose_NegativeResponse(cb_LINECUINFO_s,cb_CONDITION_NOT_CORRECT_s);
  }
  
}

/**************************************************************************
  Syntax   : void  Diagnose_PartNumber1To6(void)
  Object   : Diagnose_PartNumberHigh()
  Parameters : none
  Return  : none
  Calls   : in rls_lin_b8.c()
***************************************************************************
  Pseudo-code : LIN2.0 Mandatory service PART NUMBER 1-6
**************************************************************************/


void Diagnose_PartNumber1To6(void)      /* RLS_VCS_17 Diag Service C7 for Chrysler PF*/
{
  
  if (l_u8_rd_MasterReqB1() == cb_REQLENGTHSIDC7_s)
    
  {
    rab_DiagRespBuffer_mg[0] = 6; // PCI
    rab_DiagRespBuffer_mg[1] = 0x07; // RSID
    rab_DiagRespBuffer_mg[2] = rab_Audi_SW_Partnumber_g(2); // PN Digits 1-2
    rab_DiagRespBuffer_mg[3] = rab_Audi_SW_Partnumber_g(3); // PN Digits 3-4
    rab_DiagRespBuffer_mg[4] = rab_Audi_SW_Partnumber_g(4);  // PN Digits 5-6
    rab_DiagRespBuffer_mg[5] = 0xFF;  // Reserved
    rab_DiagRespBuffer_mg[6] = 0xFF;  // Reserved
  }
  
  else
  {
    Diagnose_NegativeResponse(cb_LINPARTNUMBER1TO6_s,cb_CONDITION_NOT_CORRECT_s);
  }
  
}


/**************************************************************************
  Syntax   : void  Diagnose_PartNumber7To10(void)
  Object   : Diagnose_PartNumberLow()
  Parameters : none
  Return  : none
  Calls   : in rls_lin_b8.c()
***************************************************************************
  Pseudo-code : LIN2.0 Mandatory service PART NUMBER 7-10
**************************************************************************/

void Diagnose_PartNumber7To10(void)     /* RLS_VCS_17 Diag Service C8 for Chrysler PF*/
{
  
  if (l_u8_rd_MasterReqB1() == cb_REQLENGTHSIDC8_s)
    
  {
    rab_DiagRespBuffer_mg[0] = 6; // PCI
    rab_DiagRespBuffer_mg[1] = 0x08; // RSID
    rab_DiagRespBuffer_mg[2] = rab_Audi_SW_Partnumber_g(5); // PN Digits 7-8
    rab_DiagRespBuffer_mg[3] = rab_Audi_SW_Partnumber_g(6); // PN Digit 9
    rab_DiagRespBuffer_mg[4] = rab_Audi_SW_Partnumber_g(7);  // PN Digit 10
    rab_DiagRespBuffer_mg[5] = 0xFF;  // Reserved
    rab_DiagRespBuffer_mg[6] = 0xFF;  // Reserved
  }
  
  else
  {
    Diagnose_NegativeResponse(cb_LINPARTNUMBER7TO10_s,cb_CONDITION_NOT_CORRECT_s);
  }
  
}

#endif /* FERRARI ||  FIAT_330 */