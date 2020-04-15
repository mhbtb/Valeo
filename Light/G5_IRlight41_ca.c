/*************************************************************************

Company : Valeo Wiper System

Project : RLT Sensor, RDN Sensor

Component : IRlight41_ca.c

Documentation reference :   Light Sensor Strategy
Overview of the component : Generates the control Signals for the
Car Head lamps and the RainSensor Software
Calculation Function of IRLight41.c
Evolution of the component : see PVCS Version control system

Initials   date   modification

*************************************************************************/
/******************************************************************************/
/* History                                                                    */
/*----------------------------------------------------------------------------*/
/* Date      VDR_Number Name     Description                                       */
/*-DD.MM.YY------------------------------------------------------------------------*/
/* 11.11.15  VDR_924   SP     Licht An bei Regen - Anpass parameters are not correctly used*/
/* 10.03.11  VDR_638   AL     MISRA OPTIMISATION with corrections in Source code */
/* 23.02.11  VCO_093   AL     implement Light Veto Function and improve Avarage Calculation*/
/* 21.02.11  VCO_094   AL     Tunnel detection improvement*/
/* 15.11.10  VCO_087   AL     adapt Threshold for better function at blue sky*/
/* 21.09.10  VCO_077   AL     adapt tunnel detection */ 
/* 27.07.10  VDR_565   AL     make function easier */
/* 15.07.10  VDR_560   AL     use bit to adjust tunnel to day Threshold*/
/* 11.05.10  VCO_041   AL     Faster initialisation after LS_Sensitivity Change */
/* 04.05.10  VDR_510   AL     Tunnel thresholds adjustable per EEPROM*/
/* 24.02.10  VCO_031   AL     link rain light brightness to ambient light*/
/* 26.01.10  VDR_421   AL     WiperCounter < Threshold combination with coding and rain light*/
/* 22.01.10  VCO_27    AL     rain light switch of time independend from potistage*/
/* 12.01.10  VDR_421   AL     Delaytime after darkstart to high*/
/* 16.09.09  VDR_401   AL     night threshold for darkstart*/
/* 16.09.09  VDR_3xx   AL     new Version for Generation4.1*/
/******************************************************************************/

/* PRQA S 2201,2215,2217,715 EOF *//*<< Indentation and line length  >>*/
#include "G5_projectDefs.h"
#ifndef PC_simulation /*VDR_369*/
#include "ior5f109be.h"
#include "G5_rls_linst.h"
#include "G5_io.h"
#include "G5_ASIC_Control_sr.h"

#include "G5_DiagE2_projectconfig.h"

#endif

#include "G5_IRlight.h"
#include "G5_Light_Defs.h"
#include "G5_DippedBeam_sr.h"

#ifdef CS_TWILIGHT_TO_DARK
#include "G5_TwilightToDark.h"
#endif


static word rw_Regulation48_OFF_Counter_g = 0; /*VCO109 VDR_773*/
static byte rb_Regulation48_ON_Counter_g = 0; /*VCO109 VDR_773*/
static word rw_VeryBrightIntunneldistance_mg = 0;
static word rw_brightInTunneldistance_mg = 0;

/**************************************************************************
Syntax   : void  light_IniToDarkstart(void)
Object   : light_IniToDarkstart()
Parameters : none
Return  : none
Calls   : in IRLight.c (Light_evaluation())
***************************************************************************
Inputs validation conditions:
none
***************************************************************************
Pseudo-code : Special Init Function for start at dark environment
**************************************************************************/
void light_IniToDarkstart(void)
{
  /* PRQA S 3415 4 */ /*Checked, no side effects*/
  if((get_rw_Amb_light16bit_g() < rb_Amb_NightLow_Threshold_g) /*VDR_401 night threshold for darkstart*/
     ||(BELOW_NIGHT_THRESHOLDS()))        /* VDR_565 make function easier frontal light lower secure threshold*/
  {
    uF_modi_lightsens_g.AllBit = cb_DARKSTART_mg;  /*set cb_DARKSTART_mg*/
    /* PRQA S 0277 1*//*<< 0277:used to generate invers flag! >>*/
    uF_modi_lightsens_inv_g.AllBit = ~cb_DARKSTART_mg;
    rb_BEFORESTARTCOUNTER_mg = 0;                  /*clear rb_BEFORESTARTCOUNTER_mg*/
    rw_nightCounter_mg=0;                          /*clear rw_nightCounter_mg*/
  }
  else
  {
    if (rbi_LightSensitivityRecieved_g == TRUE)
    {
      rb_BEFORESTARTCOUNTER_mg --;                        /* decrement rb_BEFORESTARTCOUNTER_mg*/
    }
    uF_modi_lightsens_g.AllBit = cb_DAY_mg;            /*set cb_DAY_mg*/
    /* PRQA S 0277 1*//*<< 0277:used to generate invers flag! >>*/
    uF_modi_lightsens_inv_g.AllBit =~cb_DAY_mg;    /*VDR_xxx write modilightsens_inverse when using modilightsens
    and _REINIT_LSALOG_*/
  }
  
#ifdef CS_TWILIGHT_TO_DARK
  /*this is giving a hint about if day or dark-start mode is active*/
  initTwilightToDark(uF_modi_lightsens_g.AllBit);
#endif
}
/**************************************************************************
Syntax   : void  light_darkstart_calculations(void)
Object   : light_darkstart_calculations()
Parameters : none
Return  : none
Calls   : in IRLight.c (Light_evaluation())
***************************************************************************
Inputs validation conditions:
none
***************************************************************************
Pseudo-code : Calculations in Darkstart mode to come
into Night or Day mode
**************************************************************************/
void light_darkstart_calc(void)
{
  if(rb_DARKSTARTDELAYCOUNTER_mg > 10) /*if(rb_DARKSTARTDELAYCOUNTER_mg > 10) */
  {
    /* PRQA S 3415 1 */ /*Checked, no side effects*/
    if(BELOW_NIGHT_THRESHOLDS())  /*BELOW_NIGHT_THRESHOLDS()*/
    {
      rw_nightCounter_mg++;                    /* increase rw_nightCounter_mg*/
      if(rw_nightCounter_mg > cw_DARKSTART_NIGHT_DELAY_s) 
      {
        MODI_LIGHTSENS_NIGHT_BIT_SET(); /*set NightBit*/
        rb_DARKSTARTDELAYCOUNTER_mg=0;   /* clear rb_DARKSTARTDELAYCOUNTER_mg*/
      }
    }
    else
    {
      rw_nightCounter_mg=0x00;                 /*reset rw_nightCounter_mg*/
    }
  }
  else
  {
    // Speed > DarkstartSpeed ?
    if(rb_speed_in_kmh_g > cw_SPEED_DARKSTART_s)
    {
      rb_DARKSTARTDELAYCOUNTER_mg ++;                //increment rb_DarkstartCounter_s
    }
  }
  // darkstart -> day
  if(light_isAboveDarkstartThresholds() > 0) /*VDR_421 ABOVE_DARKSTART_THRESHOLDS?*/
  {
    if((rb_WipeCounter_g <= (cb_WIPECOUNTERINI_mg+1))
       ||((rbi_modi_lightsens_rain_g== TRUE)||(rbi_RainLight_enabled_g == FALSE)))  
      /*VDR_421 WiperCounter < Threshold combination with coding and rainlight*/
    {
      rw_dayCounter_mg++;                      /* increase rw_dayCounter_mg*/
    }
    if(rw_dayCounter_mg > (cw_DARKSTART_DAY_DELAY_s))
    {
      
      MODI_LIGHTSENS_NIGHT_BIT_CLEAR();/*VDR_129 use sensitivity treatment*/
      MODI_LIGHTSENS_NIGHT_DARKST_CLEAR();  /* clear darkstartmode VDR_129 use sensitivity treatment*/
      rb_DARKSTARTDELAYCOUNTER_mg=0;       
      /*clear the TnTunnelCounter, rb_DARKSTARTDELAYCOUNTER_mg linked to rb_InTunnelCounter_mg!!!!!!!!!!!!!*/
    }
  }
  else
  {
    rw_dayCounter_mg = 0x0000;                  // reset counter
  }
}
/**************************************************************************
Syntax   : void  light_day_to_night_calculations(void)
Object   : light_day_to_night_calculations()
Parameters : none
Return  : none
Calls   : in IRLight.c (Light_evaluation())
***************************************************************************
Inputs validation conditions:
none
***************************************************************************
Pseudo-code : Transient Calculations in Darkstart mode to come
from Day to Night Mode
**************************************************************************/
void light_day_to_night_calc(void)
{
  word rw_DreiViertelNightDelay_l; /*VCO_041 faster change from day to night if sensitivity is increased*/
  /* PRQA S 3415 9 */ /*Checked, no side effects*/  
  if((get_rw_Amb_light16bit_g() < rb_Amb_NightLow_Threshold_g)
     ||((get_rw_Amb_light16bit_g() < rb_Amb_Night_Threshold_g)      /*ambient light lower night threshold*/
        &&(get_rw_FW_light16bit_g()<rb_FW_Night_Threshold_g)) /*frontal light lower night threshold*/
       ||((get_rw_Amb_light16bit_g() < (5*((word)rb_Amb_Night_Threshold_g/4)))/* VCO_087 ambient light lower night threshold+25%*/
          &&(get_rw_FW_light16bit_g()<rb_FW_NightLow_Threshold_g)) /*frontal light lower low night threshold*/
         
         ||((get_rw_IR_light16bit_g() <  cab_SECURE_IR_NIGHT_THRESHOLD_s)     /*ambient light lower secure threshold*/
            ||(get_rw_FW_light16bit_g() < cab_SECURE_NIGHT_THRESHOLD_s)
              ||(get_rw_Amb_light16bit_g() <  cab_SECURE_NIGHT_THRESHOLD_s)))    /*frontal light lower secure threshold*/
  {
    if(rw_nightCounter_mg > cw_NIGHT_DELAY_s)    /* rw_nightCounter_mg > threshold*/
    {
      if (rbi_Ignition_g == TRUE)
      {
        MODI_LIGHTSENS_NIGHT_BIT_SET();/*VDR_129 use sensitivity treatment*/
        rw_dayCounter_mg = 0x0000; // reset counter
      }
      else
      {
        rbi_DoNormalCalculation_g = 0;           //reinit to get in Darkstart and not in Night
        rb_DARKSTARTDELAYCOUNTER_mg = 0;
        rw_nightCounter_mg = 0;
      }
    }
    else
    {
      /*VCO_041 faster change from day to night if sensitivity is increased*/
      if (rb_LS_Potistage_alt_g < rb_LSPotiStage_g) 
      {
        rw_DreiViertelNightDelay_l = (cw_NIGHT_DELAY_s-(cw_NIGHT_DELAY_s/4));
        if (rw_nightCounter_mg < rw_DreiViertelNightDelay_l )
        {
          rw_nightCounter_mg = rw_DreiViertelNightDelay_l;
        }
      }
      rw_nightCounter_mg +=1;                    // increment rw_nightCounter_mg
      
      if(rb_speed_in_kmh_g > cb_MIN_SPEED_FASTERCOUNTING_s)     // faster minmum speed
      {
        rw_nightCounter_mg += 2;                   // night counter +4
      }
/* PRQA S 3415 2 */ /*Checked, no side effects*/      
      if((get_rw_Amb_light16bit_g() < rb_Amb_Night_Threshold_g)
         &&(get_rw_FW_light16bit_g()<rb_FW_NightLow_Threshold_g)) 
        
      {
        rw_nightCounter_mg +=1;                    // increment rw_nightCounter_mg
        
        if(rb_speed_in_kmh_g > cb_MIN_SPEED_FASTERCOUNTING_s)     // faster minmum speed
        {
          rw_nightCounter_mg += 2;                   // night counter +4
        }
      }
          /* PRQA S 3415 3 */ /*Checked, no side effects*/
      if ((get_rw_IR_light16bit_g() <= cab_SECURE_IR_NIGHT_THRESHOLD_s) //values lower than secure threshold
          ||(get_rw_FW_light16bit_g()  < cab_SECURE_NIGHT_THRESHOLD_s)
            ||(get_rw_Amb_light16bit_g() <  cab_SECURE_NIGHT_THRESHOLD_s))
      {
        rw_nightCounter_mg += 4;                   // night counter +4
      }
/* PRQA S 3415 2 */ /*Checked, no side effects*/            
      if((get_rw_Amb_light16bit_g() < rb_Amb_NightLow_Threshold_g)
         &&(get_rw_FW_light16bit_g()<rb_FW_Night_Threshold_g)) // rb_ambientlight_low_g < cab_IR_NIGHT_THRESHOLD_s
      {
        rw_nightCounter_mg +=5; /*to go faster in Night mode if it is very dark (count 3 times)*/
        if(rb_speed_in_kmh_g > cb_MIN_SPEED_FASTERCOUNTING_s)     // faster minmum speed
        {
          rw_nightCounter_mg += 2;                   // night counter +4
        }
      }
    }
  }
  /* PRQA S 3415 1 */ /*Checked, no side effects*/      
  else  if(get_rw_Amb_light16bit_g()>(13 + (word)rb_Amb_Night_Threshold_g)) /*VCO_087 increase Hysteresis for nightcounter reset!*/
  {
    rw_nightCounter_mg=0x00;                    // reset  rw_nightCounter_mg
  }
  else
  {
    if(rw_nightCounter_mg >=4)
    {
      rw_nightCounter_mg -=4;                    // reset  rw_nightCounter_mg
    }
    else
    {
      rw_nightCounter_mg=0x00;                    // reset  rw_nightCounter_mg
    }
  }
  
}
/**************************************************************************
Syntax   : void  light_night_to_day_calculations(void)
Object   : light_night_to_day_calculations()
Parameters : none
Return  : none
Calls   : in IRLight.c (Light_evaluation())
***************************************************************************
Inputs validation conditions:
none
***************************************************************************
Pseudo-code : Transient Calculations in Darkstart mode to come
from Night to Day Mode
**************************************************************************/
void light_night_to_day_calc(void)
{
  word rw_DreiViertelDayDelay_l;
  
  if(light_isAboveDayThreshold()> 0)
  {
    if(rw_dayCounter_mg > cw_DAY_DELAY_s)          // DayCounter > Day Delay
    {
      MODI_LIGHTSENS_NIGHT_BIT_CLEAR();/*VDR_129 use sensitivity treatment*/
      rw_nightCounter_mg = 0; // clear nightcounter to have defined start!
    }
    else
    {
      /*faster change from night to day if sensitivity is decreased*/
      if (rb_LS_Potistage_alt_g > rb_LSPotiStage_g) /*VCO_041 */
      {
        rw_DreiViertelDayDelay_l = (cw_DAY_DELAY_s-(cw_DAY_DELAY_s/4));
        if (rw_dayCounter_mg < rw_DreiViertelDayDelay_l )
        {
          rw_dayCounter_mg = rw_DreiViertelDayDelay_l;
        }
      }
      else /*to satisfy Misra 14.10*/
      {
      }
      rw_dayCounter_mg +=2;                   // increment daycounter
      if(rb_speed_in_kmh_g > cb_MIN_SPEED_FASTERCOUNTING_s)     // faster minmum speed
      {
        rw_dayCounter_mg += 4;                        // daycounter
      }
      /* VCO_093 improved Avarage*/
      if((rw_AmbLightMeanSlow_g > rw_Amb_DayHigh_Threshold_g)&&(rw_FwLightMeanSlow_g>rw_FW_Day_Threshold_g))
      {
        rw_dayCounter_mg += 4;   //daycounter+4 ot go faster in day mode if it is very bright (count 4 times)
      }
    }
  }
  else
        /* PRQA S 3415 2 */ /*Checked, no side effects*/
    if((get_rw_FW_light16bit_g()<(rb_FW_Night_Threshold_g))||
       (get_rw_Amb_light16bit_g() < (rb_Amb_Night_Threshold_g)))
      
    {
      if(rw_AmbLightMeanSlow_g<(rb_Amb_NightLow_Threshold_g>>1)) /* VCO_093 improved Avarage*/
      {
        rw_dayCounter_mg=0x00;                   // reset Daycounter
      }
      else if (rw_dayCounter_mg > 20)
      {
        rw_dayCounter_mg -= 20;
      }
      else
      {
        rw_dayCounter_mg = 0 ;
      }
      
    }
    else /* to satisfy Misra 14.10*/
    {
      
    }
  
}
/**************************************************************************
Syntax   : void  light_tunnel_to_day_calculations(void)
Object   : light_tunnel_to_day_calculations()
Parameters : none
Return  : none
Calls   : in IRLight.c (Light_evaluation())
***************************************************************************
Inputs validation conditions:
none
***************************************************************************
Pseudo-code : Transient Calculations in Darkstart mode to come
from Tunnel to Day Mode
**************************************************************************/
void light_tunnel_to_day_calc(void)
{
  word rw_Amb_Tunnel_To_DayThrs_l; 
  /*VDR_560 use Night or Day Threshold for tunnel to day*/ 
  rw_Amb_Tunnel_To_DayThrs_l = (rb_AfterTunnelThrsIsNightThrs_g>0)? rb_Amb_Night_Threshold_g:rw_Amb_Day_Threshold_g;
  /* PRQA S 3395, 3415 8 *//*Code checked manually*/
  if(((((get_rw_FW_light16bit_g() > cab_FW_TUNNEL_TO_DAY_THRESHOLD_s)/*Ambientlight higher than Tunnel to Day Threshold*/
       &&(get_rw_Amb_light16bit_g() > rw_Amb_Tunnel_To_DayThrs_l) /*AND Forwardlight higher Day threshold*/
       )
       ||
        ((get_rw_Amb_light16bit_g() > (rb_Amb_Night_Threshold_g))
         &&(get_rw_FW_light16bit_g() > (rb_FW_Night_Threshold_g))
           &&((get_rw_Amb_light16bit_g()/2 + get_rw_FW_light16bit_g()/2)
              >((rw_Amb_Day_Threshold_g)/2 + (rw_FW_Day_Threshold_g)/2)))
      )
     )&&(get_rw_IR_light16bit_g() > cab_IR_SECURE_DAY_THRESHOLD_s)
    )
  {
    if(rw_AFTERTUNNELCOUNTER_mg >= CW_AFTERTUNNELDELAY_G) // Aftertunnelcounter > Delay ?
    {
      // after tunnel counter and veto counter running in parallel
      if(get_rb_LightVetoCounter_g() == 0)
      {
        MODI_LIGHTSENS_NIGHT_BIT_CLEAR();
        MODI_LIGHTSENS_NIGHT_DARKST_CLEAR(); //clear darkstartmode /*VDR_129 use sensitivity treatment*/
        MODI_LIGHTSENS_TUNNEL_CLEAR(TRUE);  /*VDR_129 use sensitivity treatment*/
        rw_TUNNEL_TO_NIGHT_COUNTER_mg=0;          //clear counter for nightrecognition
      }
    }
    else
    {
      rw_AFTERTUNNELCOUNTER_mg++;                 // increment  rw_AFTERTUNNELCOUNTER_mg
    }
  }
  else
  {
    rw_AFTERTUNNELCOUNTER_mg=0x00;              // Reset AfterTunnelcounter
  }
}
/**************************************************************************
Syntax   : void  light_day_to_tunnel_calculations(void)
Object   : light_day_to_tunnel_calculations()
Parameters : none
Return  : none
Calls   : in IRLight.c (Light_evaluation())
***************************************************************************
Inputs validation conditions:
none
***************************************************************************
Pseudo-code : Transient Calculations in Darkstart mode to come
from Day to Tunnel Mode
**************************************************************************/
#define cb_MaxTunnelthrs_l 200
#define cb_TUNNEL_TRESHOLD_FORWARD_MIN_mg                  (byte) 13 //Min Threshold for Forward
#define cb_EASYCOMEINTUNNEL                                (byte) 7  //Threshold to come easy into tunnel

#if defined (LIGHT_BASED_ON_FW_AND_IR)
void light_day_to_tunnel_calc(void)
{
  static word rw_forwardlight_wide_alt_mg;
  static word rw_IntunnelDetectionMinValue_s;
  static  word rw_ThresholdInTunnelDistance_l;
  word rw_IRLight_low;
  word rw_forwardlight_wide;
  rw_IRLight_low = get_rw_IR_light16bit_g();
  rw_forwardlight_wide = get_rw_FW_light16bit_g();
  
  if(get_rw_FW_light16bit_g() > rw_forwardlight_wide_alt_mg)  //old Value for Forwardlight is lower then present
  {
    if(rb_PosSlopeCountFWLight_mg<0xff)             //slopeCounter lower than 0xff
    {
      rb_PosSlopeCountFWLight_mg++;                //increment slope counter
    }
  }
  else
  {
    rb_PosSlopeCountFWLight_mg=0;                //reset Slope counter
  }

  rw_forwardlight_wide_alt_mg = get_rw_FW_light16bit_g();     //store present value of Forwardlight in Old Value
  
  if(rb_FwLight_g<rw_IntunnelDetectionMinValue_s) //compare forwardlight lower than intunneldetection minValue
  {
    rw_IntunnelDetectionMinValue_s=rb_FwLight_g;  //store present Value in intunneldetection minValue
  }
  
  //- >>>>>>>>>>> FW Tunnel Threshold calculation
  
  if (rb_AmbLightDiv8MeanSlow_g > (1000/8) )
  {
    rb_FW_tunnel_threshold_mg = rb_FwLightTunnelThresholdBase_g + ((rb_AmbLightDiv8MeanSlow_g /10)
                                                                     + (rb_FwLightDiv4MeanSlow_g / 10)); //calculate FW Tunnel Threshold
  }
  if (rb_AmbLightDiv8MeanSlow_g > (700/8) )
  {
    rb_FW_tunnel_threshold_mg = rb_FwLightTunnelThresholdBase_g + ((rb_AmbLightDiv8MeanSlow_g /15)
                                                                     + (rb_FwLightDiv4MeanSlow_g / 15)); //calculate FW Tunnel Threshold
  }
  else if (rb_AmbLightDiv8MeanSlow_g > (500/8) )
  {
    rb_FW_tunnel_threshold_mg = rb_FwLightTunnelThresholdBase_g + ((rb_AmbLightDiv8MeanSlow_g / 20)
                                                                     + (rb_FwLightDiv4MeanSlow_g / 20)); //calculate FW Tunnel Threshold
  }
  else if (rb_AmbLightDiv8MeanSlow_g > (300/8) )
  {
    rb_FW_tunnel_threshold_mg = rb_FwLightTunnelThresholdBase_g + ((rb_AmbLightDiv8MeanSlow_g / 25)
                                                                     + (rb_FwLightDiv4MeanSlow_g / 25)); //calculate FW Tunnel Threshold
  }
  else
  {
    rb_FW_tunnel_threshold_mg = rb_FwLightTunnelThresholdBase_g + ((rb_AmbLightDiv8MeanSlow_g / 30)
                                                                     + (rb_FwLightDiv4MeanSlow_g /30)); //calculate FW Tunnel Threshold
  }
  
  /* PRQA S 3201,3356, 3359 2 */ /*Checked. Code is not reachable. This is true. But there is risk that it will become reachable by changing
  tunnel threshold*/
  if(rb_FW_tunnel_threshold_mg > rb_FwLightTunnelThresholdMax_g) //FW Tunnel Threshold higher then maximum
  {
    rb_FW_tunnel_threshold_mg = rb_FwLightTunnelThresholdMax_g; //Set to maximum
  }
  rb_FW_Tunnel_high_TempThresh_l = (rb_FwLightTunnelThresholdBase_g+4)+(rb_AmbLightDiv8MeanSlow_g >> 3)
    + (rb_FwLightDiv4MeanSlow_g >> 3);       //Calculate high tunnel threshold

    

//- >>>>>>>>>>> IR  Threshold calculation
  if(rb_IRlight_high_mean_slow_mg > 235) // langsamer Mittelwert Umgebungslicht > 235
  {
    rb_tunnel_threshold_IR = (rb_IRlight_high_mean_slow_mg >> 2) + (rb_IRlight_high_mean_slow_mg-235); // Berechnung des Tunnelschwellwerts f¸r Umgebungslicht wenn es sehr Hell ist
  }
  else
   {
    rb_tunnel_threshold_IR = (rb_IRlight_high_mean_slow_mg >> 2) + (rb_IRlight_high_mean_slow_mg / 20); // // Berechnung des Tunnelschwellwerts
  }
  if(rb_tunnel_threshold_IR < cb_TUNNEL_MIN_TRESHOLD_AMBIENT_s) // Tunnel umgebungslichtschwellwert > Minimaler Tunnelschwellwert
  {
    rb_tunnel_threshold_IR = cb_TUNNEL_MIN_TRESHOLD_AMBIENT_s; // auf minimalen Tunnelschwellwert setzen
  }

  rb_IR_TunnelHighTmpThresh_l = cb_TUNNEL_MIN_TRESHOLD_AMBIENT_s+(cb_TUNNEL_MIN_TRESHOLD_AMBIENT_s>>2)+(rb_IRlight_low_mean_fast_mg >> 1)+ (rb_IRlight_high_mean_slow_mg / 15);// + (rb_IRlight_low_mean_fast_mg >> 3);
    

    
  if (rb_IR_TunnelHighTmpThresh_l < rb_tunnel_threshold_IR)
  {
    rb_IR_TunnelHighTmpThresh_l = rb_tunnel_threshold_IR;
  }
   
  rb_tunnel_threshold_IR = (byte)(((word)rb_tunnel_threshold_IR * rb_IR_TunnelThresholdScaling_g) / 8); 
  rb_IR_TunnelHighTmpThresh_l = (byte)(((word)rb_IR_TunnelHighTmpThresh_l * rb_IR_TunnelThresholdScaling_g) / 8); 
     /*- >>>>>>>>>>> Tunnelthreshold scaling with EEPROM variables VDR_510*/

   
  
//- >>>>>>>>>>> Tunnel Detection

 // nnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnn

 
  
  if(((rw_IRLight_low < rb_IR_TunnelHighTmpThresh_l)               //Irlight lower high tunnel-Threshold
    &&(rw_forwardlight_wide<(rb_FW_Tunnel_high_TempThresh_l+(rb_FW_Tunnel_high_TempThresh_l/4))))  //Forwardlight lower high tunnel threshold
    ||((rw_IRLight_low < (rb_IR_TunnelHighTmpThresh_l + (rb_IR_TunnelHighTmpThresh_l/4)))               //Irlight lower high tunnel-Threshold
    &&(rw_forwardlight_wide<rb_FW_Tunnel_high_TempThresh_l)))  //Forwardlight lower high tunnel thres
    {
      /*Parallelerkennung if activated!*/
      if ((rb_PosSlopeCountFWLight_mg < 2)&&(rb_VeryBrightInTunnelDelay_g < 255)) /*VCO_094 */
      {
        rw_VeryBrightIntunneldistance_mg += rb_speed_in_kmh_g / 10; /*VCO_094 parallelerkennung*/
      }
    }
  
  
 // nnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnn  
  

  if((rw_IRLight_low < rb_IR_TunnelHighTmpThresh_l)               //Irlight lower high tunnel-Threshold
    &&(rw_forwardlight_wide<rb_FW_Tunnel_high_TempThresh_l))  //Forwardlight lower high tunnel threshold
  {

    if (((rw_InTunnelDistance_mg > 0)||(rw_brightInTunneldistance_mg > 0)) )//muﬂ einmal unter der unteren schwelle sein !
    {
      if (rw_brightInTunneldistance_mg < 0xff00U) /*VDR_511_8 avoid overflow*/
      {
        rw_brightInTunneldistance_mg += rb_speed_in_kmh_g /6;
      }
    }

    if((rw_forwardlight_wide < rb_FW_tunnel_threshold_mg) && (rw_InTunnelDistance_mg == 0))//forwardlight lower tunnelminthreshold AND intunneldistance Zero
    {
      rw_InTunnelDistance_mg = 1; //set intunneldistance to one
    }
    if((((rb_PosSlopeCountFWLight_mg < 2)||(rw_forwardlight_wide<cb_TUNNEL_TRESHOLD_NO_SLOPE_FORWARD_MIN_mg)) //Tunnel Condition?
      &&(rw_forwardlight_wide < rb_FW_tunnel_threshold_mg) )
      &&((rw_forwardlight_wide<=(rw_IntunnelDetectionMinValue_s+7))
      &&((rw_IRLight_low<cb_EASYCOMEINTUNNEL)||(rw_forwardlight_wide<=(rw_IntunnelDetectionMinValue_s+6)))))
    {
      if((rw_InTunnelDistance_mg > 0) && (rw_InTunnelDistance_mg < 0xFF00))         // Check if a overflow can occur on the next calculation of rw_InTunnelCounter_mg
      {
          // if there can not occur an overflow calculate the length of the tunnel
        if(rb_speed_in_kmh_g > cb_TUNNELMINIMUMSPEED_s)
        {
          rw_InTunnelDistance_mg += (rb_speed_in_kmh_g>>1); // Calculate rw_InTunnelDistance_mg
        }
        else
        {
          rw_InTunnelDistance_mg += cb_TUNNELMINIMUMSPEED_s>>1;
        }
      }
    }

  }
  else
  {
    if (((rw_forwardlight_wide > (rb_FW_Tunnel_high_TempThresh_l + (rb_FW_Tunnel_high_TempThresh_l/4)))
        ||(rb_PosSlopeCountFWLight_mg > 5))
        &&(rw_IRLight_low > rb_IR_TunnelHighTmpThresh_l))
    {
      rw_brightInTunneldistance_mg = 0;
      rw_VeryBrightIntunneldistance_mg = 0; 
    }
    else if (rw_brightInTunneldistance_mg > 0)
    {
      rw_brightInTunneldistance_mg += rb_speed_in_kmh_g >> 4;
    }
    rw_IntunnelDetectionMinValue_s=0xff;
    rw_InTunnelDistance_mg=0x00;                 // reset way and time counter
  }
  
  rw_ThresholdInTunnelDistance_l = ((cw_MIN_INTUNNEL_LENGTH_s>>7)*rb_TunnelDebounceFactor_g);
  /* Tunnel Decision*/
  if(((rw_InTunnelDistance_mg > rw_ThresholdInTunnelDistance_l-(rw_ThresholdInTunnelDistance_l/4))&&(rw_IRLight_low<cb_EASYCOMEINTUNNEL))// || (rb_InTunnelDistance_mg > cb_MIN_INTUNNEL_COUNTER_mg) // is Way OR time delay reached
    ||(rw_InTunnelDistance_mg > (rw_ThresholdInTunnelDistance_l))
    ||(rw_brightInTunneldistance_mg >rw_ThresholdInTunnelDistance_l)
    ||(rw_VeryBrightIntunneldistance_mg >rb_VeryBrightInTunnelDelay_g))
  {
    MODI_LIGHTSENS_TUNNEL_SET();  /*VDR_129 use sensitivity treatment*/
    rw_TUNNEL_TO_NIGHT_COUNTER_mg=0;          //clear counter for tunnel to night recognition
    rw_brightInTunneldistance_mg = 0;
    rw_VeryBrightIntunneldistance_mg = 0; 
  }
}
#else
void light_day_to_tunnel_calc(void)
{
#ifndef PC_simulation
  byte rb_tunnel_threshold_ambient2_l; /*VCO_077 used for advanced tunnel detection*/

#endif
  static  word rw_ThresholdInTunnelDistance_l;            
  
  
  static word rw_forwardlight_wide_alt_mg;
  
  /* brief higher Threshold for the Tunnel mode */
  static byte rb_Amb_TunnelHighTmpThresh_mg; /*VDR_369*/
  static  byte rb_IR_TunnelHighTmpThresh_l;          // for day to tunnel calculation
  
  word rw_tempthresholds_l;
  
  static word rw_IntunnelDetectionMinValue_s;
  
  //- >>>>>>>>>>> slope Calculation
  
  
  if(get_rw_FW_light16bit_g() > rw_forwardlight_wide_alt_mg)  //old Value for Forwardlight is lower then present
  {
    if(rb_PosSlopeCountFWLight_mg<0xff)             //slopeCounter lower than 0xff
    {
      rb_PosSlopeCountFWLight_mg++;                //increment slope counter
    }
  }
  else
  if(get_rw_FW_light16bit_g() < rw_forwardlight_wide_alt_mg) //old Value for Forwardlight is higher then present
  {
    rb_PosSlopeCountFWLight_mg=0;                //reset Slope counter
  }
  else /* to satisfy Misra 14.10*/ 
  {
  }
  rw_forwardlight_wide_alt_mg = get_rw_FW_light16bit_g();     //store present value of Forwardlight in Old Value
  
  if(rb_FwLight_g<rw_IntunnelDetectionMinValue_s) //compare forwardlight lower than intunneldetection minValue
  {
    rw_IntunnelDetectionMinValue_s=rb_FwLight_g;  //store present Value in intunneldetection minValue
  }
  
  //- >>>>>>>>>>> FW Tunnel Threshold calculation
  
  if (rb_AmbLightDiv8MeanSlow_g > (1000/8) )
  {
    rb_FW_tunnel_threshold_mg = rb_FwLightTunnelThresholdBase_g + ((rb_AmbLightDiv8MeanSlow_g /10)
                                                                     + (rb_FwLightDiv4MeanSlow_g / 10)); //calculate FW Tunnel Threshold
  }
  if (rb_AmbLightDiv8MeanSlow_g > (700/8) )
  {
    rb_FW_tunnel_threshold_mg = rb_FwLightTunnelThresholdBase_g + ((rb_AmbLightDiv8MeanSlow_g /15)
                                                                     + (rb_FwLightDiv4MeanSlow_g / 15)); //calculate FW Tunnel Threshold
  }
  else if (rb_AmbLightDiv8MeanSlow_g > (500/8) )
  {
    rb_FW_tunnel_threshold_mg = rb_FwLightTunnelThresholdBase_g + ((rb_AmbLightDiv8MeanSlow_g / 20)
                                                                     + (rb_FwLightDiv4MeanSlow_g / 20)); //calculate FW Tunnel Threshold
  }
  else if (rb_AmbLightDiv8MeanSlow_g > (300/8) )
  {
    rb_FW_tunnel_threshold_mg = rb_FwLightTunnelThresholdBase_g + ((rb_AmbLightDiv8MeanSlow_g / 25)
                                                                     + (rb_FwLightDiv4MeanSlow_g / 25)); //calculate FW Tunnel Threshold
  }
  else
  {
    rb_FW_tunnel_threshold_mg = rb_FwLightTunnelThresholdBase_g + ((rb_AmbLightDiv8MeanSlow_g / 30)
                                                                     + (rb_FwLightDiv4MeanSlow_g /30)); //calculate FW Tunnel Threshold
  }
  
  /* PRQA S 3201,3356, 3359 2 */ /*Checked. Code is not reachable. This is true. But there is risk that it will become reachable by changing
  tunnel threshold*/
  if(rb_FW_tunnel_threshold_mg > rb_FwLightTunnelThresholdMax_g) //FW Tunnel Threshold higher then maximum
  {
    rb_FW_tunnel_threshold_mg = rb_FwLightTunnelThresholdMax_g; //Set to maximum
  }
  rb_FW_Tunnel_high_TempThresh_l = (rb_FwLightTunnelThresholdBase_g+4)+(rb_AmbLightDiv8MeanSlow_g >> 3)
    + (rb_FwLightDiv4MeanSlow_g >> 3);       //Calculate high tunnel threshold
  
  
  //- >>>>>>>>>>> Amb  Threshold calculation
  rb_tunnel_threshold_ambient2_l = rb_AmbLightDiv8MeanSlow_g >> 2; 

  /* Tunnel umgebungslichtschwellwert > Minimaler Tunnelschwellwert*/
  if(rb_tunnel_threshold_ambient2_l < rb_AmbLightTunnelThresholdMin_g) 
  {
    /* auf minimalen Tunnelschwellwert setzen*/
    rb_tunnel_threshold_ambient2_l = rb_AmbLightTunnelThresholdMin_g; 
  }
  rb_Amb_TunnelHighTmpThresh_mg= cb_TUNNEL_MIN_TRESHOLD_AMBIENT_s
    +(rb_AmbLightTunnelThresholdMin_g/4)+(rb_AmbLightDiv8MeanSlow_g /2);/*VCO_077*/
  
  /*- >>>>>>>>>>> IR  Threshold calculation*/
  rb_IrLightTunnelThreshDyn_g= (rb_AmbLightDiv8MeanSlow_g > 235)? ((rb_AmbLightDiv8MeanSlow_g >> 2)
                                                                         + (rb_AmbLightDiv8MeanSlow_g-232)):((rb_AmbLightDiv8MeanSlow_g >> 2)+3); /*VCO_077*/ 
  /* Tunnel IR threshold should have a min value*/
  if(rb_IrLightTunnelThreshDyn_g < rb_IrLightTunnelThreshodLow_g) 
  {
   rb_IrLightTunnelThreshDyn_g = rb_IrLightTunnelThreshodLow_g; 
  }

  rb_IR_TunnelHighTmpThresh_l = rb_IrLightTunnelThreshodLow_g+(rb_IrLightTunnelThreshodLow_g>>2)
   +(rb_AmbLightDiv8MeanSlow_g >> 1);/* + (rb_IRlight_low_mean_fast_mg >> 3);*/
                                                                         
  /*- >>>>>>>>>>> Tunnelthreshold scaling with EEPROM variables VDR_510*/
  rw_tempthresholds_l = ((word)rb_IR_TunnelHighTmpThresh_l * rb_IR_TunnelThresholdScaling_g) / 8; 
  rb_IR_TunnelHighTmpThresh_l=(rw_tempthresholds_l>cb_MaxTunnelthrs_l)? cb_MaxTunnelthrs_l:((byte)rw_tempthresholds_l);

  /*VCO_094 erhoehte Tunnelschwelle*/
  rw_tempthresholds_l=((word)rb_FW_Tunnel_high_TempThresh_l*(rb_FW_TunnelThresholdScaling_g+2))/7;
  rb_FW_Tunnel_high_TempThresh_l=(rw_tempthresholds_l>cb_MaxTunnelthrs_l)?
  cb_MaxTunnelthrs_l:((byte)rw_tempthresholds_l);

  rw_tempthresholds_l = ((word)rb_FW_tunnel_threshold_mg * (rb_FW_TunnelThresholdScaling_g+2)) / 8;
  rb_FW_tunnel_threshold_mg = (rw_tempthresholds_l >  cb_MaxTunnelthrs_l)? 
  cb_MaxTunnelthrs_l:((byte)rw_tempthresholds_l);

  rw_tempthresholds_l = (((word)rb_Amb_TunnelHighTmpThresh_mg * rb_Amb_TunnelThresholdScaling_g)+1) / 8;
  rb_Amb_TunnelHighTmpThresh_mg = (rw_tempthresholds_l >  cb_MaxTunnelthrs_l)?
  cb_MaxTunnelthrs_l:((byte)rw_tempthresholds_l);


  /* Einschaltbare Paralleltunnelerkennung ueber EEPROM mit hoeheren Schwellen fuers FW-Licht 
  fuer Tunnel mit heller Beleuchtung an der Einfahrt*/

  /*- >>>>>>>>>>> Tunnel Detection*/
  /* PRQA S 3415 5 */ /*Checked, no side effects*/
  if(  (get_rw_FW_light16bit_g()<rb_FW_Tunnel_high_TempThresh_l) 
       &&( (  (get_rw_IR_light16bit_g() < rb_IR_TunnelHighTmpThresh_l)               /*Irlight lower high tunnel-Threshold*/
              &&(get_rw_Amb_light16bit_g() < rb_Amb_TunnelHighTmpThresh_mg)
           )  /*Forwardlight lower high tunnel threshold*/
           ||(get_rw_IR_light16bit_g() < rb_IrLightTunnelThreshDyn_g)
           ||(get_rw_Amb_light16bit_g() < rb_tunnel_threshold_ambient2_l )
         )
    ) /*VCO_077*/
  {
    /*Parallelerkennung if activated!*/
    if ((rb_PosSlopeCountFWLight_mg <= 2)&&(rb_VeryBrightInTunnelDelay_g < 255)) /*VCO_094 */
    {
      rw_VeryBrightIntunneldistance_mg += (rb_speed_in_kmh_g / 10 ); /*VCO_094 parallelerkennung*/
    }
    /*muss einmal unter der unteren schwelle sein !*/
    if (((rw_InTunnelDistance_mg > 0)||(rw_brightInTunneldistance_mg > 0)) )
    {
      if (rw_brightInTunneldistance_mg < 0xff00U) /*VDR_511_8 avoid overflow*/
      {
        rw_brightInTunneldistance_mg += rb_speed_in_kmh_g/6;
      }
    }
    /*forwardlight lower tunnelminthreshold AND intunneldistance Zero*/
    if((get_rw_FW_light16bit_g() < rb_FW_tunnel_threshold_mg) && (rw_InTunnelDistance_mg == 0))
    {
      rw_InTunnelDistance_mg = 1; /*set intunneldistance to one*/
    }
    /*Tunnel Condition?*/
    /* PRQA S 3415 4 */ /*Checked, no side effects*/
    if((((rb_PosSlopeCountFWLight_mg <= 2)||(get_rw_FW_light16bit_g()<cb_TUNNEL_TRESHOLD_NO_SLOPE_FORWARD_MIN_mg)) 
        &&(get_rw_FW_light16bit_g() < rb_FW_tunnel_threshold_mg) )
       &&(
          // easyComeIntoTunnel
          ((get_rw_IR_light16bit_g()<rb_IrLightTunnelThreshodHigh_g)||(rb_FwLight_g<=(rw_IntunnelDetectionMinValue_s+6)))))
      
    {
      /* Check if a overflow can occur on the next calculation of rw_InTunnelCounter_mg*/
      if(rw_InTunnelDistance_mg < 0xFF00U) 
      {
        /* if there can not occur an overflow calculate the length of the tunnel*/
        if(rb_speed_in_kmh_g > cb_TUNNELMINIMUMSPEED_s)
        {
          rw_InTunnelDistance_mg += (rb_speed_in_kmh_g>>1); /*Calculate rw_InTunnelDistance_mg*/
        }
        else
        {
          rw_InTunnelDistance_mg += (cb_TUNNELMINIMUMSPEED_s>>1);
        }
      }
    }
    rw_ThresholdInTunnelDistance_l = ((cw_MIN_INTUNNEL_LENGTH_s>>7)*rb_TunnelDebounceFactor_g);
    
    /* is Way OR time delay reached*/
    if(((rw_InTunnelDistance_mg > (rw_ThresholdInTunnelDistance_l))
        ||(rw_brightInTunneldistance_mg >rw_ThresholdInTunnelDistance_l)
          ||((rw_VeryBrightIntunneldistance_mg >rb_VeryBrightInTunnelDelay_g))))
    {
      MODI_LIGHTSENS_TUNNEL_SET();  /*VDR_129 use sensitivity treatment*/
      rw_TUNNEL_TO_NIGHT_COUNTER_mg=0;          //clear counter for tunnel to night recognition
      rw_brightInTunneldistance_mg = 0;
      rw_VeryBrightIntunneldistance_mg = 0; 
    }
  }
  else
  {
    /* PRQA S 3415 1 */ /*Checked, no side effects*/
    if (((get_rw_FW_light16bit_g() > (rb_FW_Tunnel_high_TempThresh_l + (rb_FW_Tunnel_high_TempThresh_l/4)))
         ||(rb_PosSlopeCountFWLight_mg > 5))
        &&(get_rw_IR_light16bit_g() > rb_IR_TunnelHighTmpThresh_l))
    {
      rw_VeryBrightIntunneldistance_mg = 0; 
      rw_brightInTunneldistance_mg = 0;
    }
    else if (rw_brightInTunneldistance_mg > 0)
    {
      if (rw_brightInTunneldistance_mg < 0xff00U) /*VDR_511_8 avoid overflow*/
      {
        rw_brightInTunneldistance_mg += rb_speed_in_kmh_g >> 4;
      }
    }
    else if((get_rw_FW_light16bit_g() < (rb_FW_Tunnel_high_TempThresh_l + (rb_FW_Tunnel_high_TempThresh_l/3)))
            &&(rw_VeryBrightIntunneldistance_mg>(4+(rb_speed_in_kmh_g/20)))
              &&(rb_PosSlopeCountFWLight_mg<2))
    {
      rw_VeryBrightIntunneldistance_mg += (rb_speed_in_kmh_g/30);
    }
    else /* to satisfy MISRA Rule 14.10*/
    {
    }
    rw_IntunnelDetectionMinValue_s=0xff;
    rw_InTunnelDistance_mg=0x00;                 // reset way and time counter
  }

}
#endif
/**************************************************************************
Syntax   : void  light_tunnel_to_night_calculation(void)
Object   : light_tunnel_to_night_calculation()
Parameters : none
Return  : none
Calls   : in IRLight.c (Light_evaluation())
***************************************************************************
Inputs validation conditions:
none
***************************************************************************
Pseudo-code : Transient Calculations in Tunnel mode to come
from Tunnel to Night Mode
**************************************************************************/
void light_tunnel_to_night_calc(void)
{
  /* Check Counter before increment -> change because of Polyspace warning */
  if(rw_TUNNEL_TO_NIGHT_COUNTER_mg >= cw_TUNNEL_TO_NIGHT_DELAY_s)   
  {
    rw_TUNNEL_TO_NIGHT_COUNTER_mg=0;             //clear counter for night-recognition
    MODI_LIGHTSENS_NIGHT_BIT_SET();/*VDR_129 use sensitivity treatment*/
    MODI_LIGHTSENS_TUNNEL_CLEAR(FALSE);  /*VDR_129 use sensitivity treatment*/
  }
  else
  {
    /* PRQA S 3415 2 */ /*Checked, no side effects*/      
    if(  (get_rw_IR_light16bit_g() > cb_IR_LONG_TUNNEL_THRESHOLD_AMBIENT_s)
       &&(get_rw_Amb_light16bit_g() < rb_Amb_Night_Threshold_g )
      )
    {
      rw_TUNNEL_TO_NIGHT_COUNTER_mg++;             //increase only if it is not completely dark
    }
    if(((rw_AmbLightMeanSlow_g < (rb_Amb_Night_Threshold_g>>1))
        &&((rb_FwLightMeanSlow_g) < (rb_FW_Night_Threshold_g>>1)))
       ||(rb_FwLightMeanSlow_g < cab_SECURE_NIGHT_THRESHOLD_s))
    {
      if (rbi_Ignition_g== TRUE)
      {
        rw_TUNNEL_TO_NIGHT_COUNTER_mg += cb_TUNNEL_TO_NIGHT_MEAN_INC_s;
      }
    }
  }
}

/**************************************************************************
Syntax   : void  light_rain_lighton_calculation(void)
Object   : light_rain_lighton_calculation()
Parameters : none
Return  : none
Calls   : in IRLight.c (Light_evaluation())
***************************************************************************
Inputs validation conditions:
none
***************************************************************************
Pseudo-code : Calculation Rain mode to switch the light parameter on
**************************************************************************/
void light_rain_lighton_calculation(void)        // light on and off during rain
{
  if((rw_AmbLightMeanSlow_g >>3) < cb_RainDetectionBrightness_mg) /* Attention Light Value is adapterd to Threshold*/
  {/*DARK*/
    /* wipe time > Delay/2 and wipeCounter > Threshold/2 */
    if(rb_WipeCounter_g >= cb_WIPETHRESHOLD_RAINLIGHT_DARK_mg) /*VDR_330*/
      /* OR wipe time > Delay and wipeCounter > Threshold*/
    {
      MODI_LIGHTSENS_RAIN_SET(); /* RAIN Mode VDR_129 use sensitivity treatment*/
    }
  }
  else
  {/*BRIGHT*/
    /* Threshold is normally twice as much as the DARK Threshold */
    if(rb_WipeCounter_g >= cb_WIPETHRESHOLD_RAINLIGHT_BRIGHT_mg)/*VDR_330*/ 
      /* OR wipe time > Delay and wipeCounter > Threshold*/
    {
      MODI_LIGHTSENS_RAIN_SET(); /* RAIN Mode VDR_129 use sensitivity treatment*/
    }
  }
  if(rw_WipeTime_g > cw_RAIN_ON_DELAY_mg)
  {
    rw_WipeTime_g =0;       /* decrement wipe time by rain_on_delay*/
    if(rb_WipeCounter_g > 0) /*wipe counter < Wiperthreshold-fadeconstant*/
    {
      rb_WipeCounter_g --;                    // reset wipe counter
    }
  }
  /*NoWipe Time > RainOffDelay*/
  /* PRQA S 3415 3 */ /*Checked, no side effects*/
  if(((rw_NoWipeTime_g>>6) > cab_RAIN_OFF_DELAY_mg)&&(rbi_modi_lightsens_rain_g==1)/*VCO_027 */
     && ((((cb_DARKSTART_mg | cb_NIGHT_mg | cb_TUNNEL_mg) &  uF_modi_lightsens_g.AllBit) !=0)
         || (get_rb_LightVetoCounter_g() == 0)
        )
    )
  {
    rw_WipeTime_g = 0;                          /* reset wipe Counter and Wipe Time*/
    rb_WipeCounter_g = 0;
    MODI_LIGHTSENS_RAIN_CLEAR(); /* RAIN Mode VDR_129 use sensitivity treatment*/
  }
  else
  { /* only to satisfy MISRA Rules*/
  }
}

/**************************************************************************
Syntax   : bool  light_isAboveDayThresholdVar4(void)
Object   : light_aboveDayThresholdVar4()

Parameters : none
Return  : true or false
Calls   : in IRLight.c (Light_evaluation())
***************************************************************************
Inputs validation conditions:
none
***************************************************************************
Pseudo-code : Calculation if the light values triple is above certain thresholds
**************************************************************************/
int light_isAboveDayThresholdVar4(void){
  return (rw_FwLightMeanSlow_g > rw_FW_DayHigh_Threshold_g)
    && (rw_AmbLightMeanSlow_g > rb_Amb_Night_Threshold_g);
}

/**************************************************************************
Syntax   : bool  light_isAboveDayThresholdVar2(void)
Object   : light_aboveDayThresholdVar2()
Parameters : none
Return  : true or false
Calls   : Light_evaluation()
***************************************************************************
Inputs validation conditions:
none
***************************************************************************
Pseudo-code : Calculation if the light values is above certain thresholds
**************************************************************************/
INLINE int light_isAboveDayThresholdVar2(void){
  /* PRQA S 761, 3415, 3395 4 */ /*Checked, no side effects*/
  return (rw_AmbLightMeanSlow_g > rb_Amb_Night_Threshold_g)
    &&(rw_FwLightMeanSlow_g>rb_FW_Night_Threshold_g)
      &&((get_rw_Amb_light16bit_g()/2 + get_rw_FW_light16bit_g()/2)
         >(rw_Amb_Day_Threshold_g/2 + rw_FW_Day_Threshold_g/2)) ;
}
/**************************************************************************
Syntax   : void  light_Regulation48(void)
Object   : light_Regulation48()
Parameters : none
Return  : none
Calls   : in G5_IRLight.c (Light_evaluation())
***************************************************************************
Inputs validation conditions:
none
***************************************************************************
Pseudo-code : Provides light control values according to Regulation48 requirements
**************************************************************************/

INLINE void light_Regulation48(void) /*VCO109 VDR_773*/
{
  word rw_Reg48__To_DayThrs_l;
  if (rbi_Regulation48LightOnFlag_g == FALSE) 
  {
    /* PRQA S 3415 1 */ /*Checked, no side effects*/
    if ((get_rw_Amb_light16bit_g() < rb_Regulation48Threshold_g)
        /*(Ambient light lower than Regulation 48 allowed threshold)*/
        && (get_rw_FW_light16bit_g() < rb_Regulation48_FW_Threshold_g))
      /*AND(Forward light lower than optimized threshold)*/
      /*(to avoid unnecessary switching ON of Lights)---(VW Konzernsensor only!!!)----KI*/
    {
      if (rb_Regulation48_ON_Counter_g > cb_Regulation48LightOnTime_g)
      {
        rbi_Regulation48LightOnFlag_g = TRUE;
      }
      else if (rb_Regulation48_ON_Counter_g < 250) 
      {
        rb_Regulation48_ON_Counter_g += 3;
      }
      else
      {// comply MISRA
      }
    } /* this is a optional variant to switch regulation 48*/
     /* PRQA S 3415 1 */ /*Checked, no side effects*/
    else if ((get_rw_Amb_light16bit_g() < (rb_Regulation48Threshold_g / 3))
             /*(Ambientlight lower than Regulation 48 allowed threshold)*/
             && (get_rw_FW_light16bit_g() < (rb_Regulation48_FW_Threshold_g + (rb_Regulation48_FW_Threshold_g / 2)))
               && (get_rw_IR_light16bit_g() < (rb_Regulation48Threshold_g / 3)))/*AND(Forwardlight lower than optimised threshold)*/
      /*(to avoid unnecessary switching ON of Lights)---(VW Konzernsensor only!!!)----KI*/
    {
      if (rb_Regulation48_ON_Counter_g > cb_Regulation48LightOnTime_g) 
      {
        rbi_Regulation48LightOnFlag_g = TRUE;
      }
      else if (rb_Regulation48_ON_Counter_g < 250) 
      {
        rb_Regulation48_ON_Counter_g += 2;
      }
      else
      {// comply MISRA
      }
    }
    else 
    {
      rb_Regulation48_ON_Counter_g = 0;
    }
  }
  else 
  {
    rw_Reg48__To_DayThrs_l = (rb_AfterTunnelThrsIsNightThrs_g !=0) ? rb_Amb_Night_Threshold_g : rw_Amb_Day_Threshold_g;
    /* PRQA S 3415 1 */ /*Checked, no side effects*/
    if ((((get_rw_FW_light16bit_g() > cab_FW_TUNNEL_TO_DAY_THRESHOLD_s)/*Ambientlight higher than Tunnel to Day Threshold */
          && (get_rw_Amb_light16bit_g() > rw_Reg48__To_DayThrs_l)) /*AND Forwardlight higher Day threshold*/
         && (get_rw_IR_light16bit_g() > cb_IR_NIGHT_THRESHOLD_s ))) {
           if (rw_Regulation48_OFF_Counter_g >= CW_AFTERTUNNELDELAY_G) // Aftertunnelcounter > Delay ?
           {
             rbi_Regulation48LightOnFlag_g = FALSE;
           }
           else 
           {
             rw_Regulation48_OFF_Counter_g++;
           }
         }
    else 
    {
      rw_Regulation48_OFF_Counter_g = 0x00;              // Reset AfterTunnelcounter
    }
  }
}


INLINE int light_isAboveDayThreshold(void){
    /* PRQA S 3415, 3398, 3390 6 */ /*Checked*/
  return (( ABOVE_DAY_THRS_VAR_ONE
             ||light_isAboveDayThresholdVar2()
             ||light_isAboveDayThresholdVar4()
          )
          &&(get_rw_IR_light16bit_g() > cab_IR_SECURE_DAY_THRESHOLD_s)
            &&(get_rb_LightVetoCounter_g() == 0)
              /*&&ABOVE_NIGHT_THRESHOLD*/
         );
}


/*VDR_421*/ /*VDR_369*/ /*VCO_93 new Threshold*/
INLINE int light_isAboveDarkstartThresholds(void){ 
      /* PRQA S 3415 1 */ /*Checked, no side effects*/
  return ((((get_rw_FW_light16bit_g()>rw_FW_Day_Threshold_g) 
            &&(get_rw_Amb_light16bit_g() > rw_Amb_Day_Threshold_g))||((get_rw_Amb_light16bit_g() > rw_Amb_DayHigh_Threshold_g)
                                                                      &&(get_rw_FW_light16bit_g()>rb_FW_Night_Threshold_g)))&&(get_rb_LightVetoCounter_g() == 0));
}

word getNightCounter(void)
{
  return rw_nightCounter_mg;
}
word getDayCounter(void)
{
  return rw_dayCounter_mg;
}

word getRegulation48OffCounter(void)
{
  return rw_Regulation48_OFF_Counter_g ;
}

byte getRegulation48OnCounter(void)
{
  return rb_Regulation48_ON_Counter_g;
}

word getVeryBrightInTunnelDistance(void)
{
  return rw_VeryBrightIntunneldistance_mg;
}

word getBrightInTunnelDistance(void)
{
  return rw_brightInTunneldistance_mg;
}


