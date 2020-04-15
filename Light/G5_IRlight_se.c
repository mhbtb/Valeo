/*************************************************************************

Company : Valeo Wiper System

Project : RLT Sensor, RDN Sensor

Component : IRlight_se.c

Documentation reference :   Light Sensor Strategy
Overview of the component : Generates the control Signals for the
Car Headlamps and the RainSensor Software
Service Function of IRLight.c
Evolution of the component : see PVCS Version control system

Initials   date   modification

*************************************************************************/
/* History                                                                    */
/*----------------------------------------------------------------------------*/
/* Date      VDR_Number     Description                                       */
/* DD.MM.YY  */
/*----------------------------------------------------------------------------*/
/* 30.03.11  RLS_VCO_97 AL  RLS_AUDI_KS: Increase LS-Thresholds at higher Speed new formula*/
/* 10.03.11  VDR_638   AL   MISRA OPTIMISATION with corrections in Source code */
/* 23.02.11  VCO_093   AL   implement Light Veto Function and improve Avarage Calculation*/
/* 30.09.08  VDR_272   FS   Nothign changed, just to have latest item in the OPEL Baseline*/
/******************************************************************************/
/* PRQA S 2201,2215,2217,715 EOF *//*<< Indentation and line length  >>*/
/* PRQA S 0862 EOF *//*defines are used in this file*/
#include "G5_projectDefs.h"
#ifndef PC_simulation /*VDR_369*/
#include "ior5f109be.h"
#include "G5_DiagE2_projectconfig.h"
#include "G5_ASIC_Control_sr.h"
#endif

#include "G5_IRlight.h"
#include "G5_Light_Defs.h"




/**************************************************************************
Syntax   : void  light_ambientlight_mean_calc(void)
Object   : light_ambientlight_mean_calc()
Parameters : none
Return  : none
Calls   : in IRLight.c (Light_evaluation())
***************************************************************************
Inputs validation conditions:
none
***************************************************************************
Pseudo-code : Calcualtes the exponaential avarage of the signals
**************************************************************************/
 void light_ambientlight_mean_calc (void)   //Umgebungshelligkeitmittelung schnell und langsam
 {
   
  word rw_AmbLightLim2040_l;
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
   
   if  (get_rw_Amb_light16bit_g() < 2040) /*VCO_093 adapt for improved avarage Calculation*/
   {
     rw_AmbLightLim2040_l = get_rw_Amb_light16bit_g();
   }
   else
   {
     rw_AmbLightLim2040_l = 2040; /*VCO_093 adapt for improved avarage Calculation*/
   }
   
   if ((uF_modi_lightsens_g.AllBit & 0x0F) != cb_TUNNEL_mg)            //Mittelung nur auserhalb von Tunnel
   {
     
     if (get_rw_Amb_light16bit_g()<rw_AmbLightMeanFast_g)             //langsame Mittelung wenn dunkler
     {
       rw_AmbLightMul32MeanFast_g=
         ((rw_AmbLightMul32MeanFast_g - (rw_AmbLightMul32MeanFast_g >> 6)) + ((rw_AmbLightLim2040_l>>1)));
     }
     else                                                            //schnelle Mittelung wenn Heller
     {
       rw_AmbLightMul32MeanFast_g=
         ((rw_AmbLightMul32MeanFast_g - (rw_AmbLightMul32MeanFast_g >> 5)) + (rw_AmbLightLim2040_l));
     }
     
     /*Umgebungshelligkeitmittelung langsam*/
     /*VCO_093 adapt for improved avarage Calculation*/
     rw_AmbLightMul32MeanSlow_g=
       (rw_AmbLightMul32MeanSlow_g - (rb_AmbLightDiv8MeanSlow_g)) + (rw_AmbLightMul32MeanFast_g>>8) ;
     
     if (rb_FwLightDiv4_g < rb_FwLightDiv4MeanFast_g)             //langsame Mittelung wenn dunkler
     {
       rw_FwLightMul64MeanFast_g=
         ((rw_FwLightMul64MeanFast_g - (rw_FwLightMul64MeanFast_g >> 6)) + (rb_FwLightDiv4_g<<2));
     }
     else           //schnelle Mittelung wenn Heller
     {
       rw_FwLightMul64MeanFast_g=
         ((rw_FwLightMul64MeanFast_g - (rw_FwLightMul64MeanFast_g >> 5)) + (rb_FwLightDiv4_g<<3));
     }
     //Mittelung langsam
     rw_FwLightMul64MeanSlow_g=
       (rw_FwLightMul64MeanSlow_g - (rb_FwLightDiv4MeanSlow_g))+ (rb_FwLightDiv4MeanFast_g) ;
     
#if defined LIGHT_BASED_ON_FW_AND_IR
        if (rb_IRLight_high<rb_IRlight_high_mean_fast_mg)             //langsame Mittelung wenn dunkler
        {
          rw_IRlight_high_256mean_fast_mg=
                        (rw_IRlight_high_256mean_fast_mg - (rw_IRlight_high_256mean_fast_mg >> 6) + (rb_IRLight_high<<2));
        }
        else                                                            //schnelle Mittelung wenn Heller
        {
            rw_IRlight_high_256mean_fast_mg=
			    (rw_IRlight_high_256mean_fast_mg - (rw_IRlight_high_256mean_fast_mg >> 5) + (rb_IRLight_high<<3));
        }
        rw_IRlight_low_256mean_fast_mg=
                (rw_IRlight_low_256mean_fast_mg - (rw_IRlight_low_256mean_fast_mg >> 5)+ (rb_IRLight_low << 3));

        //Umgebungshelligkeitmittelung langsam
        rw_IRlight_high_256mean_slow_mg=
                rw_IRlight_high_256mean_slow_mg - (rb_IRlight_high_mean_slow_mg) + (rb_IRlight_high_mean_fast_mg) ;
//        rw_IRlight_low_256mean_slow_mg=
//                rw_IRlight_low_256mean_slow_mg - (rb_IRlight_low_mean_slow_mg) + (rb_IRlight_low_mean_fast_mg);

#endif      
   }
 }

/**************************************************************************
Syntax   : void  light_highway_detectionvoid)
Object   : light_highway_detection()
Parameters : none
Return  : none
Calls   : in IRLight.c (Light_evaluation())
***************************************************************************
Inputs validation conditions:
none
***************************************************************************
Pseudo-code :Generate the highway light on signal and the reduced
threshold for the Day Night mode
**************************************************************************/
 void light_highway_detection(void)
 {
   
   /*switch off function is used for both modes*/
   if (rb_speed_in_kmh_g < cb_MIN_HIGHWAY_SPEED_mg)         // avarage of speed < min highway speed
   {
     if (rw_highwayOFFtimer_mg > (cw_TIME_TO_REACH_NORMAL_MODE_mg))        // Highwaytimer > Delay
     {
       rbi_FastHighwayMode_g = 0;
     }                                                                  // Clear Highway mode
     else
     {
       rw_highwayOFFtimer_mg ++;                                       // increment Highwaytimer
     }
   }
   else
   {
     rw_highwayOFFtimer_mg = 0;                                       // clear Highwaytimer
   }
   
   if (rb_speed_in_kmh_g > cb_MEAN_HIGHWAY_LIGHT_SPEED_mg)           // avarage of speed > highway speed
   {                                                                   // increment   Highwaytimer
     if (rw_Fasthighwaytimer_s > (cb_TIME_TO_REACH_FASTHIGHWAY_MODE_mg))       // Highwaytimer > Delay
     {
       rbi_FastHighwayMode_g = 1;                                       // Set Highway mode
     }
     else
     {
       rw_Fasthighwaytimer_s ++;                                         // increment Highwaytimer
     }
   }
   else             // slower MIN_HIGHWAY_SPEED_mg ?
   {
     rw_Fasthighwaytimer_s = 0;                                           // clear Highwaytimer
   }
   
   
 }

