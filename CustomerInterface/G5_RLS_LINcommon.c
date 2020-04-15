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
 * LIN common routines.
 *
 * %PCMS_HEADER_SUBSTITUTION_START:%
 * <table border="0" cellspacing="0" cellpadding="0">
 * <tr> <td> Source:   </td> <td> %PM: G5_RLS_LINcommon.c %                  </td></tr>
 * <tr> <td> Revision: </td> <td> %PR: 1.1 %                  </td></tr>
 * <tr> <td> Status:   </td> <td> %PS: UNDER_REVIEW %                  </td></tr>
 * <tr> <td> Author:   </td> <td> RF, DUS-E-RLS  </td></tr>
 * <tr> <td> Date:     </td> <td> %PUDT: 20-FEB-2013 15:20:23 %                </td></tr>
 * </table>
 * %PCMS_HEADER_SUBSTITUTION_END:%
 * \n
 * <table border="0" cellspacing="0" cellpadding="0">
 * <tr> <td> COMPONENT: </td> <td> XXXX                            </td></tr>
 * <tr> <td> TARGET:    </td> <td> <All>  </td></tr>
 * </table>
 */

/****************************************************************************************************************/
/*13.05.15      VDR_880 MP      Current consumption and wakeup fast response in standby mode                    */
/*26.06.15      VDR_878 NB      ADC Error shall be removed from the LS error and included only for RS_error     */
/*13.07.15      VDR_891 MP      SWITS_635: SPI communication error not set when the ASIC mode is corrupted      */
/********************************only once per cycle                                                            */
/*09.11.15      VCO_282 NB      All:Add spare LIN IDs in the EEPROM                                             */
/*24.03.16      VCO_320   NB      LIN response shall not be sent untill EEPROM is loaded                        */
/*20.01.17      VDR_1010  NB      RLS_FORD_C1MCA: RSM Partnumber not correctly send on Bus                      */
/****************************************************************************************************************/



/* PRQA S 3138 EOF */ /* << using of macros from automatic generated code >>*/
/* PRQA S 5900,5565,5540 EOF *//*<< Data needs to be verified  >>*/
/******************************************************************************/
/*                      Common and module include file                        */
/******************************************************************************/
#include "ior5f109be.h"
#include "G5_projectDefs.h"
/******************************************************************************/
/*                           Other files included                             */
/******************************************************************************/
#include "G5_Appli_timer.h"
#include "G5_Check_sr.h"
#include "G5_ASIC_Control_sr.h"
#include "G5_E2Handler.h"
#include "G5_IRlight.h"
#include "G5_lininclude.h"
#include "G5_AsicFramesLin.h"
#include "G5_Appli_lowinit.h"
#include "G5_spi_sr.h"
#include "G5_rs_ext.h"
#include "G5_rs_def.h"
#include "G5_rs_task.h"

/******************************************************************************/
/*                     Declaration of local module macros                     */
/******************************************************************************/


/******************************************************************************/
/*                   Declaration of local module variables                    */
/******************************************************************************/


/******************************************************************************/
/*                     Prototypes of local functions                          */
/******************************************************************************/


/**************************************************************************
Syntax   : void ApplTableInit(void)
Object   : ApplTableInit()
Parameters : none
Return  : none
Calls   :
***************************************************************************
Inputs validation conditions: none
***************************************************************************
Pseudo-code : init LIN intercafe structures
*************************************************************************/
#ifdef NODECONFIGURATION
void ApplTableInit(void)
{
  byte rb_ID_l;
  for(rb_ID_l=0;rb_ID_l<0x40;rb_ID_l++)
  {
    rabRAMLinMsgIDToHandleTbl[rb_ID_l] = 0xFF;
  }
  rabRAMLinMsgIDToHandleTbl[0x3C] = cb_HANDLE_LinReqCmd_g;
  rabRAMLinMsgIDToHandleTbl[0x3D] = cb_HANDLE_LinRespCmd_g;


  if (rb_IDRLSs_01_g != cb_UNASSIGNED_FRAMEID_g)
  {
    if(sci_CheckParity(rb_IDRLSs_01_g) != TRUE)
    {
      rb_IDRLSs_01_g = CB_DEF_IDRLSS_01;
    }
    rabRAMLinMsgIDToHandleTbl[rb_IDRLSs_01_g & 0x3F] = cb_HANDLE_RLSs_01_g;/***Message ID must mapping to generate ID.***/
  }
#ifdef CHANG_AN_S311 
  if (rb_IDBCM1_LIN1_02_g != cb_UNASSIGNED_FRAMEID_g)
  {
    if(sci_CheckParity(rb_IDBCM1_LIN1_02_g) != TRUE)
    {
      rb_IDBCM1_LIN1_02_g = CB_DEF_BCM1_LIN1_02;
    }
    rabRAMLinMsgIDToHandleTbl[rb_IDBCM1_LIN1_02_g & 0x3F] =  cb_HANDLE_BCM_Calibration_g;/***Message ID must mapping to generate ID.***/
  }
#endif  
  
#if (defined(NL_5) || defined(DFLQ_RLFSS) || defined(GEELY_FS11)|| defined(GEELY_FS11_NOLIGHT) || defined(BYTON)||defined(SOKON)||defined(GAC_RLS) ||defined(ZOTYE_B21))
  if (rb_IDRLSs_02_g != cb_UNASSIGNED_FRAMEID_g)
  {//added in EEPROM
    if(sci_CheckParity(rb_IDRLSs_02_g) != TRUE)
    {
      rb_IDRLSs_02_g = CB_DEF_IDRLSS_02;
    }
    rabRAMLinMsgIDToHandleTbl[rb_IDRLSs_02_g & 0x3F] = cb_HANDLE_RLSs_02_g;/***Message ID must mapping to generate ID.***/
  }
#endif
#if defined(GEELY2DOT0)
   if (rb_IDRLSs_02_g != cb_UNASSIGNED_FRAMEID_g)
  {//added in EEPROM
    if(sci_CheckParity(rb_IDRLSs_02_g) != TRUE)
    {
      rb_IDRLSs_02_g = CB_DEF_IDRLSS_02;
    }
    rabRAMLinMsgIDToHandleTbl[rb_IDRLSs_02_g & 0x3F] = cb_HANDLE_RLSs_02_g;/***Message ID must mapping to generate ID.***/
  }
   if (rb_IDRLSs_03_g != cb_UNASSIGNED_FRAMEID_g)
  {//added in EEPROM
    if(sci_CheckParity(rb_IDRLSs_03_g) != TRUE)
    {
      rb_IDRLSs_03_g = CB_DEF_IDRLSS_03;
    }
    rabRAMLinMsgIDToHandleTbl[rb_IDRLSs_03_g & 0x3F] = cb_HANDLE_RLSs_03_g;/***Message ID must mapping to generate ID.***/
  }
   if (rb_IDRLSs_04_g != cb_UNASSIGNED_FRAMEID_g)
  {//added in EEPROM
    if(sci_CheckParity(rb_IDRLSs_04_g) != TRUE)
    {
      rb_IDRLSs_04_g = CB_DEF_IDRLSS_04;
    }
    rabRAMLinMsgIDToHandleTbl[rb_IDRLSs_04_g & 0x3F] = cb_HANDLE_RLSs_04_g;/***Message ID must mapping to generate ID.***/
  }
   if (rb_IDRLSs_05_g != cb_UNASSIGNED_FRAMEID_g)
  {//added in EEPROM
    if(sci_CheckParity(rb_IDRLSs_05_g) != TRUE)
    {
      rb_IDRLSs_05_g = CB_DEF_IDRLSS_05;//190130
    }
    rabRAMLinMsgIDToHandleTbl[rb_IDRLSs_05_g & 0x3F] = cb_HANDLE_RLSs_05_g;/***Message ID must mapping to generate ID.***/
  }
   if (rb_IDRLSs_06_g != cb_UNASSIGNED_FRAMEID_g)
  {//added in EEPROM
    if(sci_CheckParity(rb_IDRLSs_06_g) != TRUE)
    {
      rb_IDRLSs_06_g = CB_DEF_IDRLSS_06;
    }
    rabRAMLinMsgIDToHandleTbl[rb_IDRLSs_06_g & 0x3F] = cb_HANDLE_RLSs_06_g;/***Message ID must mapping to generate ID.***/
  }
#endif  
  if (rb_IDBCM1_LIN1_01_g != cb_UNASSIGNED_FRAMEID_g)
  {
    if(sci_CheckParity(rb_IDBCM1_LIN1_01_g) != TRUE)
    {
      rb_IDBCM1_LIN1_01_g = CB_DEF_BCM1_LIN1_01;
    }
    rabRAMLinMsgIDToHandleTbl[rb_IDBCM1_LIN1_01_g & 0x3F] = cb_HANDLE_BCM1_LIN1_01_g;/***Message ID must mapping to generate ID.***/
  }
  
#if (defined(Chery_T18) || defined(Chery_KA63) || defined(GEELY_FS11) || defined(GEELY_FS11_NOLIGHT)) 
  if (rb_IDBCM1_LIN1_02_g != cb_UNASSIGNED_FRAMEID_g)
  {
    if(sci_CheckParity(rb_IDBCM1_LIN1_02_g) != TRUE)
    {
      rb_IDBCM1_LIN1_02_g = CB_DEF_BCM1_LIN1_02;
    }
    rabRAMLinMsgIDToHandleTbl[rb_IDBCM1_LIN1_02_g & 0x3F] = cb_HANDLE_BCM1_LIN1_02_g;/***Message ID must mapping to generate ID.***/
  }
#endif
  
#if defined(GEELY2DOT0)
if (rb_IDBCM1_LIN1_02_g != cb_UNASSIGNED_FRAMEID_g)
  {
    if(sci_CheckParity(rb_IDBCM1_LIN1_02_g) != TRUE)
    {
      rb_IDBCM1_LIN1_02_g = CB_DEF_BCM1_LIN1_02;
    }
    rabRAMLinMsgIDToHandleTbl[rb_IDBCM1_LIN1_02_g & 0x3F] = cb_HANDLE_BCM1_LIN1_02_g;/***Message ID must mapping to generate ID.***/
  }
  
  if (rb_IDBCM1_LIN1_03_g != cb_UNASSIGNED_FRAMEID_g)
  {
    if(sci_CheckParity(rb_IDBCM1_LIN1_03_g) != TRUE)
    {
      rb_IDBCM1_LIN1_03_g = CB_DEF_BCM1_LIN1_03;
    }
    rabRAMLinMsgIDToHandleTbl[rb_IDBCM1_LIN1_03_g & 0x3F] = cb_HANDLE_BCM1_LIN1_03_g;/***Message ID must mapping to generate ID.***/
  }
  
  if (rb_IDBCM1_LIN1_04_g != cb_UNASSIGNED_FRAMEID_g)
  {
    if(sci_CheckParity(rb_IDBCM1_LIN1_04_g) != TRUE)
    {
      rb_IDBCM1_LIN1_04_g = CB_DEF_BCM1_LIN1_04;
    }
    rabRAMLinMsgIDToHandleTbl[rb_IDBCM1_LIN1_04_g & 0x3F] = cb_HANDLE_BCM1_LIN1_04_g;/***Message ID must mapping to generate ID.***/
  }
  
  if (rb_IDBCM1_LIN1_05_g != cb_UNASSIGNED_FRAMEID_g)
  {
    if(sci_CheckParity(rb_IDBCM1_LIN1_05_g) != TRUE)
    {
      rb_IDBCM1_LIN1_05_g = CB_DEF_BCM1_LIN1_05;
    }
    rabRAMLinMsgIDToHandleTbl[rb_IDBCM1_LIN1_05_g & 0x3F] = cb_HANDLE_BCM1_LIN1_05_g;/***Message ID must mapping to generate ID.***/
  }
  
#endif 
  
#ifdef HAITEC

#elif defined BAICYX_G20
  
//#elif defined CTCS_M31T  custom add new LinID
  
#elif defined BAICYX_H50
  
#elif NL_5
  
#elif ZOTYE_A40

#elif DFLQ_RLFSS
  
#elif Zoety_A10

#elif Chery_T18
  
#elif CHJ_M01  
  
#elif Chery_KX63
  
#elif GEELY_FS11  
  
#elif GEELY_FS11_NOLIGHT  
 
#elif  ZOTYE_B01_NEW 
  
#elif  BYTON
  
#elif  GEELY2DOT0NORAIN   
  if (rb_IDWWSs_01_g != cb_UNASSIGNED_FRAMEID_g)
  {
      if(sci_CheckParity(rb_IDWWSs_01_g) != TRUE)
      {
        rb_IDWWSs_01_g = CB_DEF_WWSS_01;
      }
      rabRAMLinMsgIDToHandleTbl[rb_IDWWSs_01_g & 0x3F] = cb_HANDLE_WWSs_01_g;
    } 
#elif  GEELY2DOT0 
  if (rb_IDWWSs_01_g != cb_UNASSIGNED_FRAMEID_g)
  {
      if(sci_CheckParity(rb_IDWWSs_01_g) != TRUE)
      {
        rb_IDWWSs_01_g = CB_DEF_WWSS_01;
      }
      rabRAMLinMsgIDToHandleTbl[rb_IDWWSs_01_g & 0x3F] = cb_HANDLE_WWSs_01_g;
    }
#elif  SOKON 
  
#elif  GAC_RLS 
  
#elif  ZOTYE_B21  
  
#else
  if (rb_IDWWSs_01_g != cb_UNASSIGNED_FRAMEID_g)
  {
    if(sci_CheckParity(rb_IDWWSs_01_g) != TRUE)
    {
      rb_IDWWSs_01_g = CB_DEF_WWSS_01;
    }
    rabRAMLinMsgIDToHandleTbl[rb_IDWWSs_01_g & 0x3F] = cb_HANDLE_WWSs_01_g;
  } 
#ifdef BRILLIANCE_M8X
  if (rb_TRANSMISSION_01_g != cb_UNASSIGNED_FRAMEID_g)
  {
    if(sci_CheckParity(rb_TRANSMISSION_01_g) != TRUE)
    {
      rb_TRANSMISSION_01_g = CB_DEF_LINID_TRANSMISSION_01;
    }
    rabRAMLinMsgIDToHandleTbl[rb_TRANSMISSION_01_g & 0x3F] = cb_HANDLE_TRANSMISSION_01_g;
  }  
#endif
  
#ifdef CS_HT_MODULE
  if (rb_IDFSs_01_g != cb_UNASSIGNED_FRAMEID_g)
  {
    if(sci_CheckParity(rb_IDFSs_01_g) != TRUE)
    {
      rb_IDFSs_01_g = CB_DEF_IDFSS_01;
    }
    rabRAMLinMsgIDToHandleTbl[rb_IDFSs_01_g & 0x3F] = cb_HANDLE_FSs_01_g;
  }
#endif

#ifdef CS_HT_ENH_MODULE
  if (rb_IDFSs_Enh_01_g != cb_UNASSIGNED_FRAMEID_g)
  {
   	if(sci_CheckParity(rb_IDFSs_Enh_01_g) != TRUE)
        {
          rb_IDFSs_Enh_01_g = CB_DEF_IDFSS_ENH_01;
        }
        rabRAMLinMsgIDToHandleTbl[rb_IDFSs_Enh_01_g & 0x3F] = cb_HANDLE_FSdataEnhanced_g;
  }

#endif //CS_HT_MODULE

#ifdef CS_SOLAR
  if (rb_IDSOSES_01_g != cb_UNASSIGNED_FRAMEID_g)
  {
    if(sci_CheckParity(rb_IDSOSES_01_g) != TRUE)
    {
      rb_IDSOSES_01_g = CB_DEF_SOSES_01;
    }
    rabRAMLinMsgIDToHandleTbl[rb_IDSOSES_01_g & 0x3F] = cb_HANDLE_SoSes_01;
  }
#endif // CS_SOLAR

#ifdef CS_ERR_FRAME

  if (rb_IDERRDATA_01_g != cb_UNASSIGNED_FRAMEID_g)
  {
    if(sci_CheckParity(rb_IDERRDATA_01_g) != TRUE)
    {
      rb_IDERRDATA_01_g = CB_DEF_ERR_DATA_01;
    }
    rabRAMLinMsgIDToHandleTbl[rb_IDERRDATA_01_g & 0x3F] = cb_HANDLE_ERROR_DATA_RLS_g;
  }
#endif
  
#ifdef  CS_PART_NUMBER_FRAME
  if (rb_IDSPARE_01_g != cb_UNASSIGNED_FRAMEID_g)
  {
    if(sci_CheckParity(rb_IDSPARE_01_g) != TRUE)
    {
      rb_IDSPARE_01_g = CB_DEF_LINID_SPARE_01;
    }
    rabRAMLinMsgIDToHandleTbl[rb_IDSPARE_01_g & 0x3F] = cb_HANDLE_SPARE_01_g;
  }
#endif  
  
#endif  
  
#ifdef ASIC_TEST
  ApplTableInitAsic();
#endif
rbi_LINTableInitialised_g = TRUE;
#ifdef FORD
      l_u16_wr_PartNumberRSMFord_1( (( (( (word)(EEPR_FirstPrefixOfPartNumber) )<<8)&0xFF00U )+0x0002U) );
    /*0x56='V', 0x36=6*/
    l_u16_wr_PartNumberRSMFord_2( ( (((word)(EEPR_ThirdPrefixOfPartNumber) )<<8)&0xFF00U )\
                                 +(  ((word)(EEPR_SecondPrefixOfPartNumber)    )&0x00FFU ) );
    /*          0x54='T'*/
    l_u16_wr_PartNumberRSMFord_3( ((word)(EEPR_FourthPrefixOfPartNumber)) &0x00FFU  );
    l_u16_wr_PartNumberRSMFord_4(0x0000);
#endif

}
#endif


/**************************************************************************
Syntax   : void ApplLinProtocolError(byte error)
Object   : ApplLinProtocolError()
Parameters : error: the internally detected LIN error
Return  : none
Calls   :
***************************************************************************
Inputs validation conditions: none
***************************************************************************
Pseudo-code : process error flag mapping
*************************************************************************/
void ApplLinProtocolError(byte error)
{
  switch (error)
  {
  case cb_LIN_BITERROR_g:             // stops sending if own Msg is corrupted
    if (rb_LIN_BIT_ERROR_COUNTER_g < 255)
    {rb_LIN_BIT_ERROR_COUNTER_g ++;}
    rbi_latched_ResponseError_mg = TRUE;
    break;
  case cb_LIN_OVERTHEADERMAX_g:       // header too long (time)
    if (rb_LIN_OVERTHEADERMAX_COUNTER_g < 255)
    {rb_LIN_OVERTHEADERMAX_COUNTER_g ++;}
    rbi_latched_ResponseError_mg = TRUE;
    break;
  case cb_LIN_CHECKSUMERROR_g:        // for all
    if (rb_LIN_CHECKSUMERROR_COUNTER_g < 255)
    {rb_LIN_CHECKSUMERROR_COUNTER_g ++;}
    rbi_latched_ResponseError_mg = TRUE;
    break;
  case cb_LIN_OVERTFRAMEMAX_g:        // received message too long
    if (rb_LIN_OVERTFRAMEMAX_COUNTER_g < 255)
    {rb_LIN_OVERTFRAMEMAX_COUNTER_g ++;}
    rbi_latched_ResponseError_mg = TRUE;
    break;
  case cb_LIN_NORESPONSE_g:           // no response from slave
    if (rb_LIN_NORESPONSE_COUNTER_g < 255)
    {rb_LIN_NORESPONSE_COUNTER_g ++;}
    break;
  case cb_LIN_FRAMINGERROR_g:         // framing error
    if (rb_LIN_FRAMINGERROR_COUNTER_g < 255)
    {rb_LIN_FRAMINGERROR_COUNTER_g ++;}
    rbi_latched_ResponseError_mg = TRUE;
    break;
  case cb_LIN_INCOMPLETEMSGERROR_g:   // incomplete message received
    rbi_latched_ResponseError_mg = TRUE;
    break;
  case cb_LIN_IDPARITYERROR_g:           // parity wrong in ID

    break;
  default:
    break;
  }
  rb_LastLINErrorCode_g = error;
  /* PRQA S 3415 1 */ /* << Swapping expressions not feasible for performance >>*/
  if(((rbi_latched_ResponseError_mg) == TRUE) && ((sci_GetLINMsgID()) == 0x3C)) /*VDR_507*/
  {
    //block next diagnostic answer!
    l_u8_wr_MasterReqB0(0xff);
  }
}

/**************************************************************************
Syntax   : void ApplLinBusSleep(void)
Object   : ApplLinBusSleep()
Parameters : none
Return  : none
Calls   :
***************************************************************************
Inputs validation conditions: none
***************************************************************************
Pseudo-code : execute a LIN bus sleep
*************************************************************************/

void ApplLinBusSleep(void)
{
  if ((rw_NoCommunicationCounter_g < CW_LIN_E2_IDLE_TIMOUT)
      ||(CASE_ASIC_CNT_MD_STANDBY==rb_ASIC_ControlMode_g)) /*VCO_031 in EEPROM*/
  {
    /* Time required to write error code in EEPROM before sleep */
    rw_NoCommunicationCounter_g = CW_LIN_E2_IDLE_TIMOUT - 3;
    /* In Auto baudrate mode wake up pattern is not detected so
    Activate external Interrupt pin to detect any wake up pattern during sleep process */
    /* Set INTP1 high priority */
    /* PRQA S 434, 436, 781 7 */ /* <<usind Micro Controller specific command > */
    PPR11 = 0U;
    PPR01 = 0U;
    EGN0 = _02_INTP1_EDGE_FALLING_SEL;
    PIF1 = 0U;    /* clear INTP1 interrupt flag */
    PMK1 = 0U;    /* enable INTP1 interrupt */
  }
}                                              //ApplLinSleep
//---------------------------------------------------------------------------------------


void Check_StartupActiveErrors(void)
{

  if ((rb_ReadActiveErrors_g==FALSE)&&(rbi_EEPROMLoad_g==FALSE))
  {

/*if the rain functionality is disabled*/
#ifdef _NO_RAIN_

    if((TRUE==rbi_RainSensor_enabled_g) || (FALSE==rbi_RainsensorDisabled_g))
    {
      bi_RS_VariantError_g = TRUE;
    }
    else
    {
      bi_RS_VariantError_g = FALSE;
    }
#endif /*_NO_RAIN_*/

    /*load the error flags and the error counter values that affect both RS and/or LS_Error signals*/
    rb_ReadActiveErrors_g = TRUE;

    rb_GainOffset_g = rb_GainOffsetE2_g;

    bi_ROM_CHECK_FAILURE_g = (rb_RS_LS_Error_Active1_g & 0x1);
    bi_RAM_CHECK_FAILURE_g = ((rb_RS_LS_Error_Active1_g>>1) & 0x1);

    rbi_Check_LS_NoCommunication_g = ((rb_RS_LS_Error_Active1_g>>2) & 0x1);
    rw_SPINoCommCounter_g = (rbi_Check_LS_NoCommunication_g*(MAX_SPI_NO_COMM_CNT/2));

    rbi_LS_Error_Vref_g = ((rb_RS_LS_Error_Active1_g>>3) & 0x1);
    if(rbi_LS_Error_Vref_g == TRUE)
    {
      set_rb_Vref_LightSignalErrorCnt_g(CB_LIGHT_ERROR_THRESHOLD_MG/2);
    }


    rbi_ASIC_FreqTrimming_error_g = ((rb_RS_LS_Error_Active1_g>>4) & 0x1);
    if(rbi_ASIC_FreqTrimming_error_g == TRUE)
    {
      rb_FreqNotTrimmedCounter_g = (CB_FREQ_NOTTRIMMED_CNT_THRSHD/2);
    }


    rbi_ASIC_SPI_Error_g = ((rb_RS_LS_Error_Active1_g>>5) & 0x1);
    if(rbi_ASIC_SPI_Error_g == TRUE)
    {
      rb_ASIC_SPI_ErrorCodeCnt_g = (cb_ASIC_SPI_ERRORCODE_CNT_THRSHD_g/4);
    }


    rbi_ASIC_NoValidAD_Error_g = ((rb_RS_LS_Error_Active1_g>>6) & 0x1);
    if(rbi_ASIC_NoValidAD_Error_g == TRUE)
    {
      rb_StaticNoValidAD_cnt_g = ((CB_ASIC_NOVALID_ADVALUES_THRSHD/2)+1);
    }

    rbi_ASICReg_NoValidVals_Error_g = ((rb_RS_LS_Error_Active1_g>>7) & 0x1);


    rbi_VDD_LightSignalError_g = (rb_RS_LS_Error_Active2_g & 0x1);
    if(rbi_VDD_LightSignalError_g == TRUE)
    {
      set_rb_VDD_LightSignalErrorCnt_g((CB_VDDX_ERRORCNT_THRESHOLD_MG/2));
    }


    rbi_ClockFreq_Error_g = ((rb_RS_LS_Error_Active2_g>>1) & 0x1);
    if(rbi_ClockFreq_Error_g == TRUE)
    {
      rb_ClockFreq_Error_cnt_g = (cb_CLOCKFREQ_ERROR_CNT_THRESHOLD_g/2);
    }

    rbi_LEDx_LStop_error_g = ((rb_RS_LS_Error_Active2_g>>2) & 0x1);
    if(rbi_LEDx_LStop_error_g == TRUE)
    {
      set_rb_LEDx_LStop_error_cnt_g((LEDx_CNT_ERR_THRS/2));
    }

    rbi_ASIC_initTimeout_err_g = ((rb_RS_LS_Error_Active2_g>>3)&0x1);
    if(rbi_ASIC_initTimeout_err_g == TRUE)
    {
      rb_ASIC_initTimeout_g = (cb_ASIC_INITTIMEOUT_THRSH_g/2);
    }

    /*VCO_220 VIrefLo/Hi monitoring*/
    rbi_VIref_Error_g = ((rb_RS_LS_Error_Active2_g>>4)&0x1);
    if(rbi_VIref_Error_g == TRUE)
    {
      rb_VIref_ErrCnt_g = (cb_VIREF_ERRCNT_MAX_g/2);
    }


/*if the rain functionality is enabled*/
#ifndef _NO_RAIN_

    rbi_RainSensorError = (rb_RainRS_Error_Active1_g & 0x01);
    if(rbi_RainSensorError== TRUE)
    {
      rub_Dia_Count = CW_DIA_TIMEOUT/8;
    }
#endif /*_NO_RAIN_*/

    rbi_REGV_OSAT_Error_g = ((rb_RainRS_Error_Active1_g>>1) & 0x01);
    if(rbi_REGV_OSAT_Error_g == TRUE)
    {
      rw_REGV_OSAT_cnt_g = CW_REGV_OSAT_CNT_THRSHD/2;
    }

    rbi_LEDx_LClosed_error_g = ((rb_RainRS_Error_Active1_g>>2) & 0x01);
    if(rbi_LEDx_LClosed_error_g == TRUE)
    {
      rb_LEDx_LClosed_error_cnt_g = LEDx_CNT_ERR_THRS/2;
    }

    bi_RS_VariantError_g = ((rb_RainRS_Error_Active1_g>>3) & 0x1);


    rbi_ADC_Error_g = ((rb_RainRS_Error_Active1_g>>4) & 0x1);
    if(rbi_ADC_Error_g == TRUE)
    {
      rb_ADC_Error_cnt_g = (cb_ADC_ERROR_CNT_THRESHOLD_g/2);
    }

    rbi_LightSensorError_g = (rb_LightLS_Error_Active1_g & 0x01);

    rb_ASIC_ALSx_ShortDetected_Error_g = ((rb_LightLS_Error_Active1_g>>1) & 0x01);
    if(rb_ASIC_ALSx_ShortDetected_Error_g == TRUE)
    {
      rb_ASIC_ALS2Amb_ShortDetected_Debounce_g = rb_SC_debounce_g;
      rb_ASIC_ALS5FW_ShortDetected_Debounce_g = rb_SC_debounce_g;
      rb_ASIC_INRECIR_ShortDetected_Debounce_g = rb_SC_debounce_g;
    }

    bi_CALIB_CHECK_FAILURE_g = ((rb_LightLS_Error_Active1_g>>2) & 0x01);

    rbi_LS_Error_VCalib_meas_g = ((rb_LightLS_Error_Active1_g>>3) & 0x01);
    if(rbi_LS_Error_VCalib_meas_g == TRUE)
    {
      set_rb_LightSignalErrorCnt_g((CB_LIGHT_ERROR_THRESHOLD_MG/2));
    }

    bi_RAM_GUARD_Error_g  = ((rb_LightLS_Error_Active1_g>>4) & 0x01);

  }
}
