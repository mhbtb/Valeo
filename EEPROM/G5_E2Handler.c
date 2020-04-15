/* PRQA S 3116 EOF *//*<< 3116:#pragma needed for IAR compiler and MISRA >>*/
/* PRQA S 0781,759,436 EOF */ /* << 0781,436 03 03, unions needed >> */
/* PRQA S 2217 EOF */ /* << 2011 03 03, Code would be not readable >> */
/* PRQA S 0434,0436 EOF */ /* << 0434,0436 usage of SFR >> */  
/* PRQA S 841 EOF *//*<< 841:use of #undef needed  >>*/
/* PRQA S 5900,5565,5560,5540 EOF *//*<< Data needs to be verified  >>*/

/*************************************************************************

Company : Valeo Switches and Detection Systems

Project : RLT Sensor Generation 3.5

Component : E2Handler.c

Documentation reference : System Architectur spec.
---------------------------------------------------------------------------
Overview of the component : Handling of EEPROM variables and Error handling.
---------------------------------------------------------------------------
Evolution of the component : see PVCS Version control system

*************************************************************************/
/* History                                                                    */
/*----------------------------------------------------------------------------*/
/* Date         VDR_Number     NAME         Description                       */
/*21.05.2013 VCO_121    NB      initial revision                      */
/*15.09.2014 VCO_184    NB      Checksum for calibration data */
/*23.09.2014 VCO_187    MPI     error for short detection added to rb_E2_Sensor_Error4_g*/
/*18.11.2014 VDR_824    MPI     Error counter for too long init of ASIC*/
/*09.02.2015 VCO_220    MPI     VIrefLo/Hi monitoring*/
/*25.02.2015 VCO_225    MPI     RS functionality detection - error when not available*/
/*09.04.2015 VCO_241    NB      Implement test function for RAM Guard with one dedicated cell */
/*04.05.2015 VDR_871    NB     :Safety: all reset sources from RESF should be used except the voltage detector flag */
/*13.05.2015 VCO_192    NB    Audi: Activation and deactivation of Interval Operation  */
/*09.06.2015 VCO_192    NB    Audi: Activation and deactivation of Interval Operation  */
/*03.07.2015 VCO_258    NB    Use 4 bytes of cluster ID for PD,AD and RD sections */
/* 02.10.2015 VCO_276   NB      Initialise LIN ID's after loading PD section */
/* 02.12.2015 VDR_940   NB      write reset source in EEPROM                 */
/*----------------------------------------------------------------------------*/


#include "ior5f109be.h"
#include "ior5f109be_ext.h"
#include "G5_projectDefs.h"

#define _E2Handler_c_
#include "G5_E2Handler.h"
#undef _E2Handler_c_   

#include "G5_E2ProjectConfig.h"
#include "G5_flashe2.h"
#include "G5_ASIC_Control.h"
#include "G5_ASIC_Control_sr.h"
#include "G5_Check_sr.h"
#include "G5_IRlight.h"
#include "G5_lininclude.h"
#include "G5_io.h"
#include "G5_rainsens.h"
#include "G5_Appli_timer.h"
#include "G5_Appli_main.h"

/* PRQA S 3218 15 */ /* <<needed at this level for better debugging>> */
/* PRQA S 0759 1*//*<< 0759:union needed to reduce RAM usage >>*/
static Flag uF_Error_CounterIncr_mg; /*Flags to show that during this run-cycle the errorcounter was incremented*/
#define rbi_RainSensoreError_CounterIncr_g      uF_Error_CounterIncr_mg.Bit.B0
#define rbi_LightSensoreError_CounterIncr_g     uF_Error_CounterIncr_mg.Bit.B1
#define rb_HT_COMEr_CounterIncr_g               uF_Error_CounterIncr_mg.Bit.B2
#define rb_DewPointErr_CounterIncr_g            uF_Error_CounterIncr_mg.Bit.B3
#define rb_HUMEr_CounterIncr_g                  uF_Error_CounterIncr_mg.Bit.B4
#define rb_TEMPEr_CounterIncr_g                 uF_Error_CounterIncr_mg.Bit.B5
#define rb_CPUEr_CounterIncr_g                  uF_Error_CounterIncr_mg.Bit.B6
#define rb_ASICEr_CounterIncr_g                 uF_Error_CounterIncr_mg.Bit.B7
/**
* \ingroup external
* \brief exported variable containing flag2 to monitor if incidient was written.
* (Factor 1 Offset 0 [eg. none only flags) */
/* PRQA S 3218 7 */ /* <<needed at this level for better debugging>> */
/* PRQA S 0759 1*//*<< 0759:union needed to reduce RAM usage >>*/
static Flag uF_Error_CounterIncr2_mg; /*Flags to show that during this run-cycle the errorcounter was incremented*/
#define rbi_VoltSupplyEr_CounterIncr_g      uF_Error_CounterIncr2_mg.Bit.B0
#define rbi_CntMemoryError_CounterIncr_g    uF_Error_CounterIncr2_mg.Bit.B1

#ifdef STARTUP_WIPE 
/* Startup-Wipe */  
extern word aw_ref_deltaINTV_buffer[4];
extern word rw_Nom_deltaINTV_l;
extern word rw_ref2_deltaINTV_g;
extern byte rd_Aussentemp_g;
byte rb_deltaINTV_buffer_idx;
#endif

/**************************************************************************
Syntax   : void  EEPROM_Loader(void)
Object   : EEPROM_Handler()
Parameters : none
Return  : none
Calls   : in main.c   every 10ms
***************************************************************************
Inputs validation conditions:
none
***************************************************************************
Pseudo-code : loades EEPROM variables and stores default Data in EEPROM
for SoftwareChanges
**************************************************************************/

__callt void main_EEPROM_Loader(void)
{
  byte rb_i2_l;
  byte rb_WriteStatus_l = 0;
  byte rb_RelAdr_l = 0;
  pbyte pb_EEPROMMirrorData_l;
  
  if (rb_EEPROM_Status_g == cb_E2STATUS_CLUSTERINIT_g)
  {
    if(rbi_ClearCluster_mg == TRUE)
    {
      EEProm_ClearCluster();     /* Clear Cluster */
    }    
    else
    {
      EEProm_InitCluster();
    }
  }
  else if(rbi_EEPROMLoad_g == TRUE)     /* Load EEPROM? */
  {
    EEProm_Load();       /* Read next cell */
  }
  else
  {
    
    if (rbi_ClearNewCluster_mg > 0)   /* Request for Clear new cluster? */
    {
      EEProm_ClearCluster();     /* Clear Cluster    -> See main */
    }
    else if(rbi_ChangingCluster_mg == TRUE)  /* Changing Cluster in progress? */
    {
      EEProm_ChangeCluster();    /* Change Cluster */
    }
    /* EEPROM bytes to write (diagnostics)*/
    else if((rbi_EEPROMBytesToWrite_g == TRUE)&&(rbi_EEPROMBytesWritten_g == FALSE))   
    {
      if (rb_I2C_EEPROM_bytesToWrite_g > 0)
      {
        
        /* Select range to write to */
        rb_RelAdr_l = rw_EEPROM_Address_to_Write_g & 0xFF;
        
        if ((rw_EEPROM_Address_to_Write_g&cw_ADRSELMASK_mg) == cw_ADRPRE_PD_mg)
        {
          pb_EEPROMMirrorData_l = &EEPROM_Struct_PD._c[((rb_RelAdr_l+rb_I2C_EEPROM_bytesToWrite_g)-1)];
        }
        else if ((rw_EEPROM_Address_to_Write_g&cw_ADRSELMASK_mg) == cw_ADRPRE_AD_mg)
        {
          pb_EEPROMMirrorData_l = &EEPROM_Struct_AD._c[((rb_RelAdr_l+rb_I2C_EEPROM_bytesToWrite_g)-1)];
        }
        else if ((rw_EEPROM_Address_to_Write_g&cw_ADRSELMASK_mg) == cw_ADRPRE_RD_mg)
        {
          pb_EEPROMMirrorData_l = &EEPROM_Struct_RD._c[((rb_RelAdr_l+rb_I2C_EEPROM_bytesToWrite_g)-1)];
        }
        else
        {
          pb_EEPROMMirrorData_l = 0;
        }
        
        if (pb_EEPROMMirrorData_l != 0)
        {
          if (*pb_EEPROMMirrorData_l != rab_EEPROM_Bytes_toWrite_g[(rb_I2C_EEPROM_bytesToWrite_g-1)])    /* new data is different? */
          {
            rb_EEPROM_WriteStatus_g = EEProm_WriteCodedByte(rab_EEPROM_Bytes_toWrite_g[(rb_I2C_EEPROM_bytesToWrite_g-1)],((rw_EEPROM_Address_to_Write_g+rb_I2C_EEPROM_bytesToWrite_g)-1));  // write to eeprom
            if (rb_EEPROM_WriteStatus_g == 0) /* was successful? */
            {
              *pb_EEPROMMirrorData_l = rab_EEPROM_Bytes_toWrite_g[(rb_I2C_EEPROM_bytesToWrite_g-1)];
            }
          }
          else
          {
            rb_EEPROM_WriteStatus_g = 0;  /* set status to successful - nothing to do */
          }
        }
        else
        {
          rb_EEPROM_WriteStatus_g = 0x2E;     /* error illegal address */
        }
        
        if(rb_EEPROM_WriteStatus_g == 0) /* status is successful? */
        {
          
          if(rb_I2C_EEPROM_bytesToWrite_g <= 1)  /* all data written? */
          {
            rbi_EEPROMWriteSuccess_g = TRUE;       /* set succes bit */
            rbi_EEPROMBytesWritten_g = TRUE;       /* set EEPROM written flag! */
            rb_I2C_EEPROM_bytesToWrite_g = 0;      /* clear number */
          }
          else
          {
            rb_I2C_EEPROM_bytesToWrite_g --;   /* next cell */
          }
        }
        else
        {
          rbi_EEPROMWriteSuccess_g = FALSE;      /*clear succes bit */
          rbi_EEPROMBytesWritten_g = TRUE;       /* set EEPROM written flag! */
        }
        
      }
      else    /* number of bytes to write not correct */
      {
        rbi_EEPROMWriteSuccess_g = FALSE;      /*clear succes bit*/
        rbi_EEPROMBytesWritten_g = TRUE;       /*set EEPROM written flag!*/
      }
    }
    else if(rbi_ClearCluster_mg == TRUE)
    {
      EEProm_ClearCluster();     /* Clear Cluster */
    }    
    else if(rb_ChangeCluster_mg > 0)     /* request to change cluster? */
    {
      EEProm_ChangeClusterStart();     /* start changing cluster */
    }
    /* request to clear old cluster after change? */
    /* Todo check whether it is necessary to handle clear cluster request before changing cluster */
    else if (rb_EEPROM_Status_g == cb_E2STATUS_INITIALIZATION_g)   /* EEPROM Status is Initialization? */
    {
      EEProm_LoadInit(); /* reload EEPROM */
    }
    
    
    else if ((rbi_HumTempComError_g > 0)&&((rb_HumTemp_ErrorCode_g&(cb_HTERR_CHECKSUM_g|cb_HTERR_WRITECMD_g|cb_HTERR_TIMEOUT_g))>0) && (rb_HT_COMEr_CounterIncr_g == FALSE)&& (rb_HT_COMIncidentCounter_g < 0x0F))
    {
      INREASE_HT_COM_INCIDENT();
      rb_HT_COMEr_CounterIncr_g = TRUE;
      
      rb_WriteStatus_l = EEProm_WriteCodedByte(((rb_HT_COMIncidentCounter_g<<4)|rb_DewPointIncidentCounter_g),CW_EEPROM_INCIDENT6_ADDRESS);
      
    }
    
    
    else if ((rbi_HumTempComError_g > 0)&&((rb_HumTemp_ErrorCode_g&cb_HTERR_HUMIOUTOFRANGE_g)>0) && (rb_HUMEr_CounterIncr_g == FALSE)&& (rb_HumIncidentCounter_g < 0x0F))
    {
      INREASE_HUM_INCIDENT();
      rb_HUMEr_CounterIncr_g = TRUE;
      
      rb_WriteStatus_l = EEProm_WriteCodedByte(((rb_HumIncidentCounter_g<<4)|rb_TempIncidentCounter_g),CW_EEPROM_INCIDENT5_ADDRESS);
      
    }
    else if ((rbi_HumTempComError_g > 0)&&((rb_HumTemp_ErrorCode_g&cb_HTERR_TEMPOUTOFRANGE_g)>0) && (rb_TEMPEr_CounterIncr_g == FALSE)&& (rb_TempIncidentCounter_g < 0x0F))
    {
      INREASE_TEMP_INCIDENT();
      rb_TEMPEr_CounterIncr_g = TRUE;
      
      rb_WriteStatus_l = EEProm_WriteCodedByte(((rb_HumIncidentCounter_g<<4)|rb_TempIncidentCounter_g),CW_EEPROM_INCIDENT5_ADDRESS);
      
    }
    
    else if ((bi_RAM_CHECK_FAILURE_g>0) && (rb_CPUEr_CounterIncr_g == FALSE)&& (rb_CPUIncidentCounter_g < 0x0F))
    {
      
      INREASE_CPU_INCIDENT();
      rb_CPUEr_CounterIncr_g = TRUE;
      
      rb_WriteStatus_l = EEProm_WriteCodedByte(((rb_CPUIncidentCounter_g<<4)|rb_ASICIncidentCounter_g),CW_EEPROM_INCIDENT4_ADDRESS);
    }
    else if ((uF_ASIC_Error_Flags_g.AllBit>0) && (rb_ASICEr_CounterIncr_g == FALSE)&& (rb_ASICIncidentCounter_g < 0x0F))
    {
      INREASE_ASIC_INCIDENT();
      rb_ASICEr_CounterIncr_g = TRUE;
      
      rb_WriteStatus_l = EEProm_WriteCodedByte(((rb_CPUIncidentCounter_g<<4)|rb_ASICIncidentCounter_g),CW_EEPROM_INCIDENT4_ADDRESS);
      
    }
    else if (((get_rb_VDD_LightSignalErrorCnt_g() > CB_VDDX_ERRORCNT_THRESHOLD_MG)) && (rbi_VoltSupplyEr_CounterIncr_g == FALSE)&& (rb_VoltSupplyIncidentCounter_g < 0x0F))
    {
      INREASE_VOLTSUPPLY_INCIDENT();
      rbi_VoltSupplyEr_CounterIncr_g = TRUE;
      
      rb_WriteStatus_l = EEProm_WriteCodedByte(((rb_WDGIncidentCounter_g<<4)|rb_VoltSupplyIncidentCounter_g),CW_EEPROM_INCIDENT3_ADDRESS);
      
    }
    
    else if ((bi_ROM_CHECK_FAILURE_g) && (rbi_CntMemoryError_CounterIncr_g == FALSE)&& (rb_CntMemoryIncidentCounter_g < 0x0F))
    {
      INREASE_CNTMEMORY_INCIDENT();
      rbi_CntMemoryError_CounterIncr_g = TRUE;
      
      rb_WriteStatus_l = EEProm_WriteCodedByte(((rb_CntMemoryIncidentCounter_g<<4)|rb_CntProSeqIncidentCounter_g),CW_EEPROM_INCIDENT2_ADDRESS);
      
    }
    else if( (((rbi_RainSensorError>0)||(rbi_RS_Error_Loop_g>0)) && (rbi_RainSensoreError_CounterIncr_g == FALSE))&& (rb_RainSensorIncidentCounter_g < 0x0F) )
    {
      
      INREASE_RAIN_INCIDENT();
      rbi_RainSensoreError_CounterIncr_g = TRUE;
      
      rb_WriteStatus_l = EEProm_WriteCodedByte(((rb_LightSensorIncidentCounter_g<<4)|rb_RainSensorIncidentCounter_g),CW_EEPROM_INCIDENT1_ADDRESS);
      
    }
    else if ((rbi_LightSensorError_g) && (rbi_LightSensoreError_CounterIncr_g == FALSE)&& (rb_LightSensorIncidentCounter_g < 0x0F))
    {
      INREASE_LIGHT_INCIDENT();
      rbi_LightSensoreError_CounterIncr_g = TRUE;
      
      rb_WriteStatus_l = EEProm_WriteCodedByte(((rb_LightSensorIncidentCounter_g<<4)|rb_RainSensorIncidentCounter_g),CW_EEPROM_INCIDENT1_ADDRESS);
      
    }
    
    else if( (rb_E2_Sensor_Error1_g | (rbi_RainSensorError)|(bi_ROM_CHECK_FAILURE_g<<1)|(bi_RAM_CHECK_FAILURE_g<<2)
              |(uF_Check_lightsensor_g.AllBit) | (bi_CALIB_CHECK_FAILURE_g << 6) ) != (rb_E2_Sensor_Error1_g) )  /* any error detected? */
    {
      /* shift error flag into temp variable!*/
      rb_i2_l =(rbi_RainSensorError
                |(bi_ROM_CHECK_FAILURE_g<<1)
                  |(bi_RAM_CHECK_FAILURE_g<<2)
                    |(uF_Check_lightsensor_g.AllBit)    /*b3-rbi_Check_LS_NoCommunication_g, b4-rbi_SoftwareBug_g, b5-rbi_Check_LS_ambient_HighToLow_notOK_g*/
                      | (bi_CALIB_CHECK_FAILURE_g << 6) );
      /*b7-used for Software reset!!*/
      if ((rb_E2_Sensor_Error1_g | rb_i2_l) != rb_E2_Sensor_Error1_g)      /* is failuren not present in EEPROM? */
      {
        rb_E2_Sensor_Error1_g |=  rb_i2_l;           /* store failure in EEPROM */
        
        rb_WriteStatus_l = EEProm_WriteCodedByte((rb_E2_Sensor_Error1_g),CW_E2_SENSOR_ERROR1_ADRESS);
        
      }
    }
    /*is LS failure not present in EEPROM?*/
    /* uF_ASIC_Error_Flags_g: B0-rbi_LS_Error_VinALS2_g, B1-rbi_LS_Error_VinALS5_g, B2-rbi_LS_Error_Vinrec_g,
    B3-rbi_LS_Error_Vref_g, B4-rbi_LS_Error_VCalib_meas_g, B5-rb_LEDx_LStop_error_g, B6-rb_LEDx_LClosed_error_g,
    B7-rb_ASIC_initTimeout_err_g*/
    else  if( (rb_E2_Sensor_Error2_g | uF_ASIC_Error_Flags_g.AllBit) != rb_E2_Sensor_Error2_g )
    {
      /*store failure in EEPROM*/
      rb_E2_Sensor_Error2_g |= uF_ASIC_Error_Flags_g.AllBit;        
      
      rb_WriteStatus_l = EEProm_WriteCodedByte((rb_E2_Sensor_Error2_g),CW_E2_SENSOR_ERROR2_ADRESS);
      
    }
    
    /*is LS failure not present in EEPROM?*/
    /*b0-rbi_WriteError_g,b1-rbi_EraseError_g,b2-rbi_OutOfRangeError_g,b3-rbi_ClusterError_g,b4-rbi_BlankBetweenError_g,
    b5-rbi_HammingWarning_g,b6-rbi_HammingError_g,b7-NOT USED*/
    else if ((rb_E2_Sensor_Error3_g | (uF_E2ConfigErrorFlags_g.AllBit)) != rb_E2_Sensor_Error3_g) 
    {
      rb_E2_Sensor_Error3_g |= uF_E2ConfigErrorFlags_g.AllBit;        /* store failure in EEPROM */
      
      rb_WriteStatus_l = EEProm_WriteCodedByte((rb_E2_Sensor_Error3_g),CW_E2_SENSOR_ERROR3_ADRESS);
      
    }
    /*VCO_225 RS functionality detection - error when not available*/
    /*B0-rbi_HumTempComError_g, B1-rbi_SensitivityTreatmentError_g, B2-rbi_LightSensorVetoConflict_g, 
    B3-rbi_LightSensorError_g, B4-rbi_ADC_Error_g, B5-rbi_ClockFreq_Error_g,
    B6-rb_ASIC_ALSx_ShortDetected_Error_g, B7-bi_RS_VariantError_g*/
    else if ( (rb_E2_Sensor_Error4_g|((rbi_HumTempComError_g)|(rbi_SensitivityTreatmentError_g<<1)|
                                      (rbi_LightSensorVetoConflict_g<<2)|(rbi_LightSensorError_g<<3)|
                                        (rbi_ADC_Error_g<<4)|(rbi_ClockFreq_Error_g<<5)|
                                          (rb_ASIC_ALSx_ShortDetected_Error_g<<6)|
                                            (bi_RS_VariantError_g<<7))) != rb_E2_Sensor_Error4_g )
    {
      /*store failure in EEPROM*/
      rb_E2_Sensor_Error4_g |= ((rbi_HumTempComError_g)|(rbi_SensitivityTreatmentError_g<<1)|(rbi_LightSensorVetoConflict_g<<2)|
                                (rbi_LightSensorError_g<<3)|(rbi_ADC_Error_g<<4)|(rbi_ClockFreq_Error_g<<5)|
                                  (rb_ASIC_ALSx_ShortDetected_Error_g<<6)|(bi_RS_VariantError_g<<7));
      rb_WriteStatus_l = EEProm_WriteCodedByte((rb_E2_Sensor_Error4_g),CW_E2_SENSOR_ERROR4_ADRESS);
      
    }
    /*b0-rb_ASIC_SPI_Error_g,b1-rb_ASIC_NoValidAD_Error_g,b2-rb_REGV_OSAT_Error_g,b3-rb_VDD_LightSignalError_g,
    b4-rb_ASICReg_NoValidVals_Error_g,b5-rbi_ASIC_FreqTrimming_error_g,b6-rb_ASIC_FREQ_invalid_Low_g,b7-rb_ASIC_FREQ_invalid_High_g*/
    else if( (rb_E2_Sensor_Error5_g | (uF_ASIC_Ctrl_Error_Flags_g.AllBit)) != rb_E2_Sensor_Error5_g )
    {
      rb_E2_Sensor_Error5_g |= (uF_ASIC_Ctrl_Error_Flags_g.AllBit);
      rb_WriteStatus_l = EEProm_WriteCodedByte((rb_E2_Sensor_Error5_g),CW_E2_SENSOR_ERROR5_ADRESS);
    }
    /*VCO_220 VIrefLo/Hi monitoring*/
    else if((rb_E2_Sensor_Error6_g | (uF_ASIC_Error_Flags1_g.AllBit) | (bi_RAM_GUARD_Error_g << 1)) != rb_E2_Sensor_Error6_g)
    {
      rb_E2_Sensor_Error6_g |= (uF_ASIC_Error_Flags1_g.AllBit) |(bi_RAM_GUARD_Error_g << 1) ;
      rb_WriteStatus_l = EEProm_WriteCodedByte((rb_E2_Sensor_Error6_g),CW_E2_SENSOR_ERROR6_ADRESS);
    }
    else if(((rb_Release_IntervalMarker_Update_g&0x0f) != (rb_Release_IntervalMarker_g)) && (rbi_Write_ReleaseMarker_g == TRUE) ) /*VCO_192*/
    {
      rb_Release_IntervalMarker_g = (rb_Release_IntervalMarker_Update_g&0x0f);
      rb_WriteStatus_l = EEProm_WriteCodedByte((rb_Release_IntervalMarker_g),CW_INTERVAL_MARKER_ADRESS);
      rbi_Write_ReleaseMarker_g = FALSE;
    }
    else if((rbi_WriteResetSource_g != FALSE ))
    {
      if((rb_Resf_g|rb_ResetSource_g)!=rb_Resf_g)
      {
        rb_Resf_g |= rb_ResetSource_g;
        rb_WriteStatus_l = EEProm_WriteCodedByte((rb_Resf_g),CW_E2_SENSOR_RESF_ADRESS);
     }
      rbi_WriteResetSource_g = FALSE;
    }
    else if (rbi_ResetSourceWasInternal_g != FALSE) /* Was watchdog reset?*/
    {
      if (rb_WatchdogResetCounter_g<15)/* is watchdog counter on upper limit? */
      {
        rb_WatchdogResetCounter_g++;   /* inkrement watchdog counter */
        /* write counter into EEPROM */
        rb_WriteStatus_l = EEProm_WriteCodedByte((rb_WatchdogResetCounter_g),CW_E2_WATCHDOGRESETCOUTERADRESS);    
        
      }
      rbi_ResetSourceWasInternal_g = FALSE;  /* clear reset source bit *//* VDR_871 */
      rab_InternalResetIndicator[0]=0x00;
      rab_InternalResetIndicator[1]=0x00;
      rab_InternalResetIndicator[2]=0x00;
      rab_InternalResetIndicator[3]=0x00;
    }
    else if ( (rb_ReadActiveErrors_g == TRUE) && (rb_RS_LS_Error_Active1_g != rb_RS_LS_Error1_g) )
    {
      rb_WriteStatus_l = EEProm_WriteCodedByte(rb_RS_LS_Error1_g,CW_RS_LS_ERROR_ACTIVE1_ADR);
      
      if (rb_WriteStatus_l == 0)
      {
        rb_RS_LS_Error_Active1_g = rb_RS_LS_Error1_g;
      }
    }
    else if ( (rb_ReadActiveErrors_g == TRUE) && (rb_RS_LS_Error_Active2_g != rb_RS_LS_Error2_g) )
    {
      rb_WriteStatus_l = EEProm_WriteCodedByte(rb_RS_LS_Error2_g,CW_RS_LS_ERROR_ACTIVE2_ADR);
      
      if (rb_WriteStatus_l == 0)
      {
        rb_RS_LS_Error_Active2_g = rb_RS_LS_Error2_g;
      }
    }
    else if ( (rb_ReadActiveErrors_g == TRUE) && (rb_LightLS_Error_Active1_g != rb_LightS_Error1_g) )
    {
      rb_WriteStatus_l = EEProm_WriteCodedByte(rb_LightS_Error1_g,CW_LIGHTLS_ERROR_ACTIVE1_ADR);
      
      if (rb_WriteStatus_l == 0)
      {
        rb_LightLS_Error_Active1_g = rb_LightS_Error1_g;
      }
    }
    else if ( (rb_ReadActiveErrors_g == TRUE) && (rb_RainRS_Error_Active1_g != rb_RainS_Error1_g) )
    {
      rb_WriteStatus_l = EEProm_WriteCodedByte(rb_RainS_Error1_g,CW_RAINRS_ERROR_ACTIVE1_ADR);
      
      if (rb_WriteStatus_l == 0)
      {
        rb_RainRS_Error_Active1_g = rb_RainS_Error1_g;
      }
    }
#ifndef _NO_RAIN_
    else if ((rb_ReadActiveErrors_g == TRUE)
             && (rb_GainOffset_g != rb_GainOffsetE2_g) 
              && (((rb_GainOffset_g|rb_GainOffsetE2_g)&0x0F)!=0)
               && ((rb_ASIC_Sched_Config_g & 0x4) != 4))
    {
      rb_WriteStatus_l = EEProm_WriteCodedByte((rb_GainOffset_g&0x8F), GAINOFFSET_ADDRESS);
      
      if (rb_WriteStatus_l == 0)
      {
        rb_GainOffsetE2_g = rb_GainOffset_g;
      }
    }
#ifdef STARTUP_WIPE 
      /* Startup-Wipe */
    else if(aw_ref_deltaINTV_buffer[3] != 0x00)
    {
      rw_ref2_deltaINTV_g =  0x00;
      for(rb_deltaINTV_buffer_idx = 0; rb_deltaINTV_buffer_idx < 4; rb_deltaINTV_buffer_idx++)
      {
        rw_ref2_deltaINTV_g += aw_ref_deltaINTV_buffer[rb_deltaINTV_buffer_idx] ;
      }
      rw_ref2_deltaINTV_g = rw_ref2_deltaINTV_g  >>2;
      
      if (rw_Nom_deltaINTV_l != rw_ref2_deltaINTV_g ) 
      {
        if((l_u8_rd_Aussentemp_gef() > rb_Threshold_TempIceRisk_g) && (l_u8_rd_Aussentemp_gef() < 0xFE))
        {
          rb_WriteStatus_l = EEProm_WriteCodedByte((rw_ref2_deltaINTV_g>>5), NOM_DELTA_INTV_BYTE_ADDRESS);
          if (rb_WriteStatus_l == 0)
          {
            rw_Nom_deltaINTV_l = rw_ref2_deltaINTV_g; 
          }
        }
      }
    }
#endif
    
#endif /*_NO_RAIN_*/
    else /*MISRA*/
    {}
    
    if (rb_WriteStatus_l != 0)   /* Error during writing occured? */
    {
      rbi_WriteError_g = 1;    /* set write error flag */
    }
    
  } 
}

/* ===========================================================================
** end of file
** ===========================================================================
*/
