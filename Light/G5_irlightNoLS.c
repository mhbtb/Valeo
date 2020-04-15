/* PRQA S 0861,0862,5560,5830 EOF */ /* << Compiler specific Includes cannot be analysed by QA-C>> */
/* PRQA S 3619 EOF */ /* << Whitespace accepted by IAR-compiler>> */
/* PRQA S 3116 EOF */ /* << pragma directives needed, compiler specific>>*/
/* PRQA S 0759 EOF */ /* << union is sopported by this compiler>>*/
/*************************************************************************

Company : Valeo Wiper System

Project : RLT Sensor, RDN Sensor

Component : G5_IRlightNoLS.c

Documentation reference :   This variant has no light features. It provides 
the signal(s) required the rain sensor
Overview of the component : Replaces the full light sensor functionality. 
Provides the night bit based on IR signal only.

Evolution of the component : see PVCS Version control system

Initials   date   modification

*************************************************************************/
/******************************************************************************/
/* History                                                                    */
/*----------------------------------------------------------------------------*/
/* Date      VDR_Number Name     Description                                       */
/*-DD.MM.YY -----------------------------------------------------------------------*/

/*************************************************************************
**                   Common and module include-file                     **
**************************************************************************/
#include "G5_projectDefs.h"
#ifndef PC_simulation /*VDR_369*/
#include "ior5f109be.h"
#include "G5_E2ProjectConfig.h"
#include "G5_Appli_timer.h"
#include "G5_Appli_main.h"
#include "G5_rls_linst.h"
#include "G5_io.h"
#include "G5_ASIC_Control_sr.h"

#endif


#define _light_c_       //Define for Single include of Global Header G5_IRlight.h
#include "G5_IRlight.h"
#undef _light_c_

#define _light_defs_c_       //Define for Single include of Global Header G5_Light_Defs.h
#include "G5_Light_Defs.h"
#undef _light_defs_c_

#include "G5_DippedBeam_sr.h"

/*************************************************************************
**                   Other files included                               **
**************************************************************************/
static byte rb_DayNightcounter_NightBit_g;              // Counter for rainsensor Nightbit

/** Function Prototypes **/
//-******Modi Calculations*********************************************************

//-******Threshold calculations****************************************************


 void MODI_LIGHTSENS_RAIN_CLEAR(void)                                                             
{                                                                                                       
  rbi_modi_lightsens_rain_g = FALSE;                                                                    
  rbi_modi_lightsens_rain_inv_g = TRUE; /*VDR_129 use sensitivity treatment*/                           
}               

 void MODI_LIGHTSENS_NIGHT_DARKST_CLEAR(void)                                                     
{                                                                                                       
  rbi_modi_lightsens_darkStart_g = FALSE;                                                               
  rbi_modi_lightsens_darkStart_inv_g = TRUE;                                                            
  CHECK_VETO_COUNTER(); /*VDR_129 use sensitivity treatment*/
}                     

 void MODI_LIGHTSENS_TUNNEL_CLEAR(int doCheckLightVeto)                                                           
{                                                                                                       
  rbi_modi_lightsens_tunnel_g = FALSE;                                                                  
  rbi_modi_lightsens_tunnel_inv_g = TRUE;                                                               
  if(FALSE != doCheckLightVeto){
    CHECK_VETO_COUNTER(); /*VDR_129 use sensitivity treatment*/
  }
}                                          

 void MODI_LIGHTSENS_RAIN_SET(void)                                                               
{                                                                                                       
  rbi_modi_lightsens_rain_g = TRUE;                                                                     
  rbi_modi_lightsens_rain_inv_g = FALSE; /*VDR_129 use sensitivity treatment*/                          
}                                                                                                       

 void MODI_LIGHTSENS_NIGHT_BIT_CLEAR(void)                                                        
{                                                                                                       
  rbi_modi_lightsens_night_g=FALSE;                                                                     
  rbi_modi_lightsens_night_inv_g = TRUE;                                                                
  CHECK_VETO_COUNTER();   /*VDR_129 use sensitivity treatment*/
}                                                                                                       

 void MODI_LIGHTSENS_NIGHT_BIT_SET(void)                                                          
{                                                                                                       
  rbi_modi_lightsens_night_g=TRUE;                                                                      
  rbi_modi_lightsens_night_inv_g = FALSE;                                                                                                                           
  rbi_modi_lightsens_tunnel_g = FALSE;                                                                  
  rbi_modi_lightsens_tunnel_inv_g = TRUE; 
  /*Bit not used*/
  /*rbi_modi_lightsens_beforeTunnel_g=FALSE;*/
  rbi_modi_lightsens_beforeTunnel_inv_g=TRUE;  /*VDR_129 use sensitivity treatment*/                                                                 
  rbi_modi_lightsens_darkStart_g = FALSE;                                                               
  rbi_modi_lightsens_darkStart_inv_g = TRUE;
  /*Bit not used*/
  /*rbi_modi_lightsens_forest_g=FALSE;*/
  rbi_modi_lightsens_forest_inv_g=TRUE;                                  
}      

 void MODI_LIGHTSENS_TUNNEL_SET(void)                                                             
{                                                                                                       
  rbi_modi_lightsens_tunnel_g = TRUE;                                                                   
  rbi_modi_lightsens_tunnel_inv_g = FALSE;
  /*Bit not used*/
  /*rbi_modi_lightsens_forest_g=FALSE;*/
  rbi_modi_lightsens_forest_inv_g=TRUE;
  /*Bit not used*/
  /*rbi_modi_lightsens_beforeTunnel_g=FALSE;*/
  rbi_modi_lightsens_beforeTunnel_inv_g=TRUE;  /*VDR_129 use sensitivity treatment*/                                                              
  rbi_modi_lightsens_night_g=FALSE;                                                                     
  rbi_modi_lightsens_night_inv_g = TRUE;                                                                        
  rbi_modi_lightsens_darkStart_g = FALSE;                                                               
  rbi_modi_lightsens_darkStart_inv_g = TRUE;                             
}           

/**************************************************************************
Syntax   : void  Light_init(void)
Object   : Light_init()
Parameters : none
Return  : none
Calls   : in main.c
***************************************************************************
Inputs validation conditions:
none
***************************************************************************
Pseudo-code : Initialize all Varibles for the light evaluation
**************************************************************************/
void light_init(void)
{
    //Initial Variables
  rb_BEFORESTARTCOUNTER_mg = cb_BEFORESTARTTIME_mg;             
  //-rb_BEFORESTARTCOUNTER_mg linked to rb_PosSlopeCountIRLight_mg
  rb_DARKSTARTDELAYCOUNTER_mg = cb_WAITFORCOMMUNICATIONTIME_mg; 
  //-rb_DARKSTARTDELAYCOUNTER_mg linked to rw_TUNNEL_TO_NIGHT_COUNTER_mg!!!!!!!!!!!!!
  rb_WipeCounter_g=cb_WIPECOUNTERINI_mg;
  //rb_LSPotiStage_g=0; //-to be sure that it is initialiesed
  //- Initialisation of Variables to zero (is also done in Bootload)
  /*-
  
  rbi_DoNormalCalculation_g = 0; */ /*VDR_369 to init darkstart counter*/
  
  /*initialise Counters in external RAM*/
  rw_highwayOFFtimer_mg = 0; 
  rw_Fasthighwaytimer_s = 0;
  
  
  uF_modi_lightsens_g.AllBit=cb_DAY_mg;    //-Go to Day Mode
  /* PRQA S 0277 1 */ /* << Sensitivity treatment>> */
  uF_modi_lightsens_inv_g.AllBit =~cb_DAY_mg;    /*VDR_129 use sensitivity treatment*/
  rw_FwLightMul64MeanFast_g =((word)rb_FwLightDiv4_g)<<8; //Initialize average values
  rw_FwLightMul64MeanSlow_g =((word)rb_FwLightDiv4_g)<<8;

  MODI_LIGHTSENS_NIGHT_BIT_SET();
}


/**************************************************************************
Syntax   : void  light_rainsensor_night_bit_calc(void)
Object   : light_rainsensor_night_bit_calc()
Parameters : none
Return  : none
Calls   : in rainsens.c / light_evaluation (rainsensor active())
***************************************************************************
Inputs validation conditions:
none
***************************************************************************
Pseudo-code : Calculation of the Night Bit for the Rainsensor Mode
**************************************************************************/
void light_rainsensor_night_bit_calc(void)
{
  static byte rb_NightcountNightBit_s; // counter for Nightbit
  
  if (rbi_night_g == FALSE)
  {
    rb_DayNightcounter_NightBit_g = 0;             //reset Daycounter
    if (get_rw_IR_light16bit_g() < cb_THRESHOLD_RS_NIGHT_MODE_mg)//light value lower than night Threshold?
      {
        if (rb_NightcountNightBit_s >= cb_NIGHTBITDELAY_mg)//NightDelay reached?
        {
          rbi_night_g = TRUE;                                    //set nightbit
        }
        else
        {
          rb_NightcountNightBit_s ++;                      //increment night counter
        }
      }
      else
      {
        rb_NightcountNightBit_s = 0;
      }
    
  }
  else
  {   
    rb_NightcountNightBit_s = 0;
    /*light value lower than night Threshold?*/
    if (get_rw_IR_light16bit_g() >  (cb_THRESHOLD_RS_DAY_MODE_mg ))
      {
        if (rb_DayNightcounter_NightBit_g >= cb_NIGHTBITDELAY_mg)//NightDelay reached?
        {
          rbi_night_g = FALSE;                                    //set nightbit
        }
        else
        {
          rb_DayNightcounter_NightBit_g ++;                      //increment night counter
        }
      }
      else
      {
        rb_DayNightcounter_NightBit_g = 0;
      }
  }
}



/**************************************************************************
Syntax   : void  lightScheduler(void)
Object   : lightScheduler()
Parameters : none
Return  : none
Calls   : in G5_DippedBeam_sr.c
***************************************************************************
Inputs validation conditions:
none
***************************************************************************
Pseudo-code : Schedules all functions for light evaluation
**************************************************************************/
void lightScheduler(void) {
  if(rb_WDG_LightsensorTaskCounter_g %5 == 0){
    light_rainsensor_night_bit_calc();  //set or clear night bit for rain sensor
  }
}

/**************************************************************************
Syntax   : byte get_rb_LightVetoCounter_g(void)
Object   : get_rb_LightVetoCounter_g
Parameters : none
Return  : dummy value
Calls   : in G5_DippedBeam_sr.c
***************************************************************************
Inputs validation conditions:
none
***************************************************************************
Pseudo-code : Stub implementation
**************************************************************************/
byte get_rb_LightVetoCounter_g(void){
  return 0;
}

void light_evaluation(void){
  static byte rb_StartLightEvaluation_s;
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
        
        if  (get_rw_Amb_light16bit_g() < 2048)
        {
          rw_AmbLightMul32MeanFast_g = get_rw_Amb_light16bit_g()<<5; //initial meanValues
        }
        else
        {
          rw_AmbLightMul32MeanFast_g = 0xff00U; //initial meanValues
        }
        rw_AmbLightMul32MeanSlow_g = rw_AmbLightMul32MeanFast_g;
        rw_FwLightMul64MeanFast_g =((word)(rb_FwLightDiv4_g))<<8; //Initialize average values
        rw_FwLightMul64MeanSlow_g = rw_FwLightMul64MeanFast_g;
      }
      else
      {
//        light_Threshold_cac(); /*VDR_565 move call of first threshold calculation*/
//        light_IniToDarkstart();        //Init Darkstart mode
        
        /*IR_Light Value lower than night Threshold*/
        if (get_rw_IR_light16bit_g() < cb_THRESHOLD_RS_NIGHT_MODE_mg)
          
        {
          rbi_night_g = 1;           //Set Night bit for Rainssensor
        }
        else
        {
          rbi_night_g = 0;           //Clear Night bit for Rainsensor
        }
//        light_ambientlight_mean_calc(); //Calculate light averages
        rbi_LightSensorActive_g= TRUE;  //Lightsensor running
      }
    }
    else
    {
      rbi_DoNormalCalculation_g=1; //Set mode to normal
    }
  }
  else{
    lightScheduler();
  }
  
  rb_WDG_LightsensorTaskCounter_g++;      //Checkcounter for Lighsensor routine
  
}

word getNightCounter()
{
  return 0;
}
word getDayCounter()
{
  return 0;
}

word getRegulation48OffCounter()
{
  return 0 ;
}

byte getRegulation48OnCounter()
{
  return 0;
}
