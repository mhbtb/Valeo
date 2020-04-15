/*************************************************************************

Company : Valeo Schalter und Sensoren GmbH

Project : G5 RLxS Sensor

Component : G5_DippedBeam_sr.c

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
/* 25.09.13  -          RFI     initial version */
/*03.03.15   VCO_227    NB     Implement RAM Guard function */
/* 10.03.15   VCO_227    NB     Implement RAM Guard function */
/******************************************************************************/
/*                Include common and project definition header                */
/******************************************************************************/
#include "G5_projectDefs.h"
#ifndef PC_simulation /*VDR_369*/
#include "ior5f109be.h"
#include "G5_Appli_timer.h"
#include "G5_Appli_main.h"
#include "G5_rls_linst.h"
#include "G5_io.h"
#include "G5_ASIC_Control_sr.h"
#include "G5_check_sr.h"
#include "G5_DiagE2_projectconfig.h"

#else
#include "RltLightSimu.h"
#endif

#include "G5_IRlight.h"
#include "G5_Light_Defs.h"
#include "G5_DippedBeam_sr.h"

/******************************************************************************/
/*                       Definition of local variables                        */
/******************************************************************************/
/* PRQA S 3116 4 *//*<< 3116:#pragma needed for IAR compiler*/
#pragma dataseg="RAM_GUARD" 
/** \brief this byte counts to zero; for zero the light can be switched OFF*/
static __no_init byte rb_LightVetoCounter_g;
#pragma dataseg=default


/******************************************************************************/
/*                  Declaration of local function prototypes                  */
/******************************************************************************/
static void set_rb_LightVetoCounter_g(byte rb_value_l);


/******************************************************************************/
/*                       Definition of local functions                        */
/******************************************************************************/

byte get_rb_LightVetoCounter_g(void){
  return rb_LightVetoCounter_g;
}

static void set_rb_LightVetoCounter_g(byte rb_value_l){
  DisableRamGuard();
  rb_LightVetoCounter_g = rb_value_l;
  EnableRamGuard();
}

/**************************************************************************
Syntax   : void  light_evaluation(void)
Object   : light_evaluation()
Parameters : none
Return  : none
Calls   : in main.c (10ms cyclic)
***************************************************************************
Inputs validation conditions:
none
***************************************************************************
Pseudo-code : State machine for the light sensor software
**************************************************************************/
void light_evaluation(void)         //all Calculations for Lightsensing
{
  static byte rb_StartLightEvaluation_s;
#if defined LIGHT_BASED_ON_FW_AND_IR
  word rw_IrLight;
  byte rb_IRLight_high;
  byte rb_IRLight_low;
  rw_IrLight = get_rw_IR_light16bit_g();
  
  if ((rw_IrLight>>3) < 255)         // higher than limit of high value?
  {
    rb_IRLight_high = (rw_IrLight>>3);       //copy for LS-Application
  }
  else
  {
    rb_IRLight_high = 0xff;                        // set to max-value
  }

  if (rw_IrLight < 255)
  {
    rb_IRLight_low = rw_IrLight;
  }else
  {
    rb_IRLight_low = 255;
  }
#endif  
  if (rbi_DoNormalCalculation_g==0)     //Mode is Darkstart?
  {
    /*Delay reached for stable light //-rb_BEFORESTARTCOUNTER_mg linked to rb_PosSlopeCountIRLight_mg*/
    if (rb_BEFORESTARTCOUNTER_mg > 0)  
    {
      
      if (rb_DARKSTARTDELAYCOUNTER_mg > 0)//wait if rbi_ASIC_Communication is possible_g
        //-, rb_DARKSTARTDELAYCOUNTER_mg linked to rw_TUNNEL_TO_NIGHT_COUNTER_mg!!!!!!!!!!!!!
      {
        rbi_LightSensorActive_g= FALSE;  //Lightsensor not active
        if ((rb_AfterVddPowerFailDelay_g|rbi_Powerfail_g) > 0) //not  undervoltage?
        {
          rb_DARKSTARTDELAYCOUNTER_mg=15;             //wait 60ms to initialise Light
        }
        else
        {
          
          if ((rbi_LightValuesInitialised_g == TRUE)&& (rbi_LightConfigRecieved == TRUE))
          {
            rb_DARKSTARTDELAYCOUNTER_mg = 0;
          }
          else
          {
            rb_DARKSTARTDELAYCOUNTER_mg--;          //reduce Delaycounter rb_DARKSTARTDELAYCOUNTER_mg
          }
        }
        
        if  (rb_StartLightEvaluation_s > 250)
        {
          if (rb_AfterVddPowerFailDelay_g == 0) //timout if long time Powerfail
          {
            rb_DARKSTARTDELAYCOUNTER_mg=0;                  //Set Start Delay to 0
          }
        }
        else
        {
          rb_StartLightEvaluation_s ++;
        }
        
        //-linked to rw_TUNNEL_TO_NIGHT_COUNTER_mg!!!!!!!!!!!!!
        
        //init
        
        if  (get_rw_Amb_light16bit_g() < 2040)
        {
          rw_AmbLightMul32MeanFast_g = get_rw_Amb_light16bit_g()<<5; //initial meanValues
        }
        else
        {
          rw_AmbLightMul32MeanFast_g = (2040U <<5) ; //initial meanValues
        }
        rw_AmbLightMul32MeanSlow_g = rw_AmbLightMul32MeanFast_g;
        rw_FwLightMul64MeanFast_g =((word)(rb_FwLightDiv4_g))<<8; //Initialize average values
        rw_FwLightMul64MeanSlow_g = rw_FwLightMul64MeanFast_g;

#if defined (LIGHT_BASED_ON_FW_AND_IR)
        rw_IRlight_high_256mean_fast_mg = ((word)(rb_IRLight_high)) << 8; //initial meanValues
        rw_IRlight_low_256mean_fast_mg = ((word)(rb_IRLight_low)) << 8;
        rw_IRlight_high_256mean_slow_mg = ((word)(rb_IRLight_high)) << 8;
//        rw_IRlight_low_256mean_slow_mg = ((word)(rb_IRLight_low_g)) << 8;
#endif

      }
      else
      {
        light_Threshold_cac(); /*VDR_565 move call of first threshold calculation*/
        light_IniToDarkstart();        //Init Darkstart mode
        
        /*IR_Light Value lower than night Threshold*/
        if (get_rw_IR_light16bit_g() < cb_THRESHOLD_RS_NIGHT_MODE_mg)
          
        {
          rbi_night_g = 1;           //Set Night bit for Rainssensor
        }
        else
        {
          rbi_night_g = 0;           //Clear Night bit for Rainsensor
        }
        light_ambientlight_mean_calc(); //Calculate light averages
        rbi_LightSensorActive_g= TRUE;  //Lightsensor running
      }
    }
    else
    {
      rbi_DoNormalCalculation_g=1; //Set mode to normal
    }
  }
  else
  {
    lightScheduler();
  }
  
  if (0xFF != (uF_modi_lightsens_g.AllBit + uF_modi_lightsens_inv_g.AllBit)) /*VDR_129 Check of Sensitivity treatment*/
  {
    rbi_SensitivityTreatmentError_g = TRUE;
  }
  /*if (rbi_night_g == FALSE)*/ //Instrumentierung fuer WDG Test
  {
    rb_WDG_LightsensorTaskCounter_g++;      //Checkcounter for Lighsensor routine
  }
  
}

/**************************************************************************
Syntax   : void  light_VetoForLightOff()
Object   : light_VetoForLightOff()
Parameters : none
Return  : none
Calls   : in IRLight.c (Light_evaluation()) every 50 ms
***************************************************************************
Inputs validation conditions:
none
***************************************************************************/
/**
* \brief this Function checkes based on minimum Thresholds if the light
can be deactivated. The counter rb_LightVetoCounter_g hae to be 0 that the
light can be secure switched OFF!*/
/*************************************************************************/
/*VCO_093 implement Veor Function for Lightsensor Algorithm*/
  /** \brief Timout to load the vetocounter if the lightvalues are to high */
#define CB_LIGHT_VETODELAY_g (cb_AFTERTUNNEL_DELAY_s-3) /*minimal switch off Delay*/
/*SM252*/
void light_VetoForLightOff(void)
{
  /* PRQA S 3415 7 */ /* << Getter functions must not have side effects >>*/
  if ((get_rw_Amb_light16bit_g() < cab_AMB_SECURE_DAY_THRESHOLD_s)
     ||(get_rw_IR_light16bit_g() < cab_IR_SECURE_DAY_THRESHOLD_s)
     ||(get_rw_FW_light16bit_g() < cab_FW_SECURE_DAY_THRESHOLD_s)
      /*SM260: Light values from ALSx_INC used in the veto_counter*/
     ||(get_rw_Amb_INC_light16bit_g() < cab_AMB_SECURE_DAY_THRESHOLD_s)
     ||(get_rw_IR_INC_light16bit_g() < cab_IR_SECURE_DAY_THRESHOLD_s)
     ||(get_rw_FW_INC_light16bit_g() < cab_FW_SECURE_DAY_THRESHOLD_s))
  {
    set_rb_LightVetoCounter_g(CB_LIGHT_VETODELAY_g);
   
  }
  else if (rb_LightVetoCounter_g > 0)
  {
    set_rb_LightVetoCounter_g(rb_LightVetoCounter_g -1); 
   
  }
  else /*MISRA 14.10*/
  {
  }
  
}
