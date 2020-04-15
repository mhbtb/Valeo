/*************************************************************************

Company : Valeo Wiper System

Project : RLT Sensor, RDN Sensor

Component : IRlight.c

Documentation reference :   Light Sensor Strategy
Overview of the component : Generates the control Signals for the
Car Headlamps and the RainSensor Software

Evolution of the component : see PVCS Version control system

Initials   date   modification

*************************************************************************/
/******************************************************************************/
/* History                                                                    */
/*----------------------------------------------------------------------------*/
/* Date      VDR_Number Name     Description                                       */
/*-DD.MM.YY -----------------------------------------------------------------------*/
/* 30.03.11  RLS_VCO_97 AL  RLS_AUDI_KS: Increase LS-Thresholds at higher Speed*/
/* 12.03.11  VDR_638   AL   MISRA OPTIMISATION with corrections in Source code */
/* 15.Mar11  VSC_4    FS    Implement compiler defines project related, also QAC-defines*/
/* 21.02.11  VCO_094   AL   Variable Initialisation for Tunnel detection improvement*/
/* 22.11.10  VCO_69    PCG  moved light mode constants: cb_NIGHT_mg, cb_DAY_mg, cb_DARKSTART_mg 
and cb_TUNNEL_mg from irlight.c */
/* 15.11.10  VCO_087   AL   adapt Day Threshold for better function at blue sky*/
/* 21.09.10  VCO_077   AL   adapt tunnel detection threshold and adapt for offline simulation*/ 
/* 26.05.10  VCO_055   AL   reomve debouncing of RAM and ROM error*/
/* 11.05.10  VCO_41    AL   remove unsused code and implement faster reaction on LS_Sensitivity change*/
/* 29.04.10  VDR511_2  AL   correct threshold overflow*/
/* 24.02.10  VCO_031   AL   new adjustable values over EEPROM*/
/* 26.01.10  VDR_421   AL   adapt delay for rain light*/
/* 22.01.10  VCO_27    AL   rainlight switch of time independend from potistage*/
/* 12.01.10	 VDR_421   AL   Delaytime after darkstart to high*/
/* 24.09.09	 VDR_369   AL   Adaptation for Light Algorithm*/
/* 08.06.09  VDR_330        Shift parameters into header, EEPROM-RainLight needed to be defined*/
/* 07.Apr-08 VDR_175        RLS_ALL ReInit LS-Algorithm with define _REINIT_LSALGO_*/
/* 04.Feb.08 VDR_129        use sensitivity treatment*/
/* 26.06.08  VCO_08    AL   Add FAW Twilight detection*/
/* 19.08.08  VDR_20    FS   OPEL RAIN LIGHT added*/
/* 21.09.08  VDR_908   SP   Rain Light Timeout Reset durinng Frontwashen bug fix*/
/******************************************************************************/
/* PRQA S 0861,0862,5560,5830 EOF */ /* << Compiler specific Includes cannot be analysed by QA-C>> */
/* PRQA S 3619 EOF */ /* << Whitespace accepted by IAR-compiler>> */
/* PRQA S 3116 EOF */ /* << pragma directives needed, compiler specific>>*/
/* PRQA S 0759 EOF */ /* << union is sopported by this compiler>>*/
/* PRQA S 2201,2215,2217,715 EOF *//*<< Indentation and line length  >>*/
/* PRQA S 841 EOF *//*<< 841:use of #undef needed  >>*/

/*************************************************************************
**                   Common and module include-file                     **
**************************************************************************/
#include "G5_projectDefs.h"
#ifndef PC_simulation /*VDR_369*/
#include "ior5f109be.h"
#include "G5_E2ProjectConfig.h"
#include "G5_Appli_timer.h"
#include "G5_rls_linst.h"
#include "G5_rainsens.h"
#include "G5_ASIC_Control_sr.h"


#endif

#define _light_c_       //Define for Single include of Global Header G5_IRlight.h
#include "G5_IRlight.h"
#undef _light_c_

#define _light_defs_c_       //Define for Single include of Global Header G5_Light_Defs.h
#include "G5_Light_Defs.h"
#undef _light_defs_c_

#include "G5_DippedBeam_sr.h"

#ifdef CS_TWILIGHT_TO_DARK
#include "G5_TwilightToDark.h"
#endif

/*************************************************************************
**                   Other files included                               **
**************************************************************************/


/******************************************************************************/
/*                  Declaration of local function prototypes                  */
/******************************************************************************/
static void light_rainsensor_night_bit_calc(void);

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
  if(FALSE != doCheckLightVeto)
  {
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
static void light_rainsensor_night_bit_calc(void)
{
  static byte rb_NightcountNightBit_s; // counter for Nightbit
  static byte rb_DayNightcounter_NightBit_g; // Counter for rainsensor Nightbit
  
  if (rbi_night_g == FALSE)
  {
    rb_DayNightcounter_NightBit_g = 0;             //reset Daycounter
    if (get_rw_Amb_light16bit_g() < (cb_THRESHOLD_RS_NIGHT_MODE_mg ))//light value higher than day Threshold?
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
    /*light value higher than day Threshold?*/
    if (get_rw_Amb_light16bit_g() > (cb_THRESHOLD_RS_DAY_MODE_mg ))
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
Syntax   : void  light_Threshold_cac(void)
Object   : light_Threshold_cac()
Parameters : none
Return  : none
Calls   : light_evaluation (rainsensor active())
***************************************************************************
Inputs validation conditions:
none
***************************************************************************
Pseudo-code : Light threshold calculation
**************************************************************************/
void light_Threshold_cac(void)
{
  /*Forward Day Thresholds default is 4 (64) !*/
  
  static const byte cab_ThresholdFactors[9] =   {26,34,45,54,64,77,90,102,115};  
  word rw_DayThresholdFakt_l, rw_NightThresholdFakt_l;
  
  rw_DayThresholdFakt_l = cab_ThresholdFactors[(rb_LSPotiStage_g)];
  rw_NightThresholdFakt_l = rw_DayThresholdFakt_l;
  
  rw_FW_Day_Threshold_g = ((((rb_FW_Base_Day_Threshold_g*rw_DayThresholdFakt_l)>>6)>400)?
                           400:((rb_FW_Base_Day_Threshold_g*rw_DayThresholdFakt_l)>>6));
  rb_IR_Day_Threshold_g = (byte)((((rb_IR_Base_Day_Threshold_g*rw_DayThresholdFakt_l)>>6)>240)?
                                 240:((rb_IR_Base_Day_Threshold_g*rw_DayThresholdFakt_l)>>6));
  
  rw_Amb_Day_Threshold_g = (word)((((rb_Amb_Base_Day_Threshold_g*rw_DayThresholdFakt_l)>>6)>400)?
                                  400:((rb_Amb_Base_Day_Threshold_g*rw_DayThresholdFakt_l)>>6)); /*VDR511_2*/
  
  rw_Amb_DayHigh_Threshold_g = (word) (((rw_Amb_Day_Threshold_g + (rw_Amb_Day_Threshold_g >> 3))>400)? 
                                       400:(rw_Amb_Day_Threshold_g + (rw_Amb_Day_Threshold_g >> 3))); /*VDR511_2*/
  
  rb_Amb_Night_Threshold_g = (byte)((((rb_Amb_Base_Night_Threshold_g*rw_NightThresholdFakt_l)>>6)>240)?
                                    240:((rb_Amb_Base_Night_Threshold_g*rw_NightThresholdFakt_l)>>6));
  
  rb_Amb_NightLow_Threshold_g = rb_Amb_Night_Threshold_g- (rb_Amb_Night_Threshold_g>>2);
  
  
  rb_IR_DayHigh_Threshold_g = (byte) ((((word)(rb_IR_Day_Threshold_g) + (rb_IR_Day_Threshold_g >> 3))>240)? 
                                      240:(rb_IR_Day_Threshold_g + (rb_IR_Day_Threshold_g >> 3)));
  
  rw_FW_DayHigh_Threshold_g = ((rw_FW_Day_Threshold_g + (rw_FW_Day_Threshold_g >> 3))>400)? 
    400:(rw_FW_Day_Threshold_g + (rw_FW_Day_Threshold_g >> 3));
    
    rb_FW_Night_Threshold_g  =(byte)((((rb_FW_Base_Night_Threshold_g*rw_NightThresholdFakt_l)>>6)>245)?
                                     245:((rb_FW_Base_Night_Threshold_g*rw_NightThresholdFakt_l)>>6));
    
    rb_IR_Night_Threshold_g = (byte)((((rb_IR_Base_Night_Threshold_g*rw_NightThresholdFakt_l)>>6)>240)?
                                     240:((rb_IR_Base_Night_Threshold_g*rw_NightThresholdFakt_l)>>6));
    
    
    rb_FW_NightLow_Threshold_g = rb_FW_Night_Threshold_g- (rb_FW_Night_Threshold_g>>2);
    rb_IR_NightLow_Threshold_g = rb_IR_Night_Threshold_g- (rb_IR_Night_Threshold_g>>2);
    
    
}
/**************************************************************************
Syntax   : void  IO_CalculateWiperActivity(void)
Object   : IO_CalculateWiperActivity()
Parameters : none
Return  : none
Calls   : in main.c (cyclic every 10ms)
***************************************************************************
Inputs validation conditions:
none
***************************************************************************
Pseudo-code : Measures the ADC-Ports and copies the Value into the
Variable Light Valaues are only measured if the wiper
is not in front of the sensor
**************************************************************************/
void IO_CalculateWiperActivity(void)
{
  static word rw_afterWashingTime_counter_s; /*VDR_369*/
  static byte rb_LastParkPosition_s;
  
  
  // do every 50ms
  {
    if (rw_WipeTime_g < 0xFFFFU)               //Wipe Time does not overflow
    {
      rw_WipeTime_g ++;                       //increase Wipe Time
    }
    if (rbi_WashingActive_g == 0)     //Washing not Active?
    {
      if (rw_afterWashingTime_counter_s > 0)  //Washing not Active and was not set before?
      {
        rw_afterWashingTime_counter_s--;              //Reduce after Washing Delay
      }
    }
    else                //-Wiper is Washing
    {
      rw_afterWashingTime_counter_s = cw_DURATION_WIPE_AFTER_WASH_mg; //Set Afterwashing delay
    }
    if (rbi_RealParkContact_g == 0)   //Wiper out of parkposition?
    {
      if (rw_afterWashingTime_counter_s==0)               //After Washing Time delay reached
      {
        /*System was before in Parkposition and the Wipecounter will not overflow?*/
        if ((rb_LastParkPosition_s != 0) && (rb_WipeCounter_g < 0xFF)) 
        {
          rb_WipeCounter_g ++;                            //Increase Wipe Counter
        }
      }
           
      if (rbi_WashingActive_g == 1)
      {
        if (rw_NoWipeTime_g < 0xFFFFU)     //Is No Wipe time near Overflow
        {
          rw_NoWipeTime_g ++;                //Increase NoWipeTime
        }
      }
      else
      {
         if (rw_afterWashingTime_counter_s==0)               //After Washing Time delay reached
         {
           rw_NoWipeTime_g = 0;                    //Clear Time with no Wipe
         }
         else
         {
           if (rw_NoWipeTime_g < 0xFFFFU)     //Is No Wipe time near Overflow
           {
             rw_NoWipeTime_g ++;                //Increase NoWipeTime
           }
         }
      }
      
    }
    else  // in parkposition
    {
      if (rw_NoWipeTime_g < 0xFFFFU)     //Is No Wipe time near Overflow
      {
        rw_NoWipeTime_g ++;                //Increase NoWipeTime
      }
    }
    rb_LastParkPosition_s = rbi_RealParkContact_g;  //store current status of parkcontact in old
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
  static byte rb_Irligth10ms_to4_counter_mg; //-Counter to Generate Task Scheduling
  static  byte rb_SoftwareErrorCounter_g;
  
  if (rb_AfterVddPowerFailDelay_g == 0)
  {
    /*VDR_175: 1.) ReInit when LightSensorActive has changed on bus (call Ini_ToDarkStart() )*/
    
    /*VDR_175: 2.) Change Debounce Variables for day and night when LightSensorSensitivity
    has changed on bus or in EEPROM*/
    if (rbi_LSPotiStageChanged_g == 1) /*Light Sensor Sensitivity on bus has changed?*/
    {
      if ((rbi_modi_lightsens_night_g == 1) && (rw_dayCounter_mg < (cw_DAY_DELAY_s - 100)))
      {
        /*When night adapt daycounter!*/
        rw_dayCounter_mg = cw_DAY_DELAY_s - 100; /* DayCounter > Day Delay*/
      }
      if ((rbi_modi_lightsens_night_g == 0) && (rw_nightCounter_mg < (cw_NIGHT_DELAY_s - 100)))
      {
        /*When day adapt nightcounter*/
        rw_nightCounter_mg = cw_NIGHT_DELAY_s - 100;
      }
      rbi_LSPotiStageChanged_g = 0;
    }
    // 10ms Program- scheduling with diagnosis
    rb_Irligth10ms_to4_counter_mg++; /*increment Taskcounter*/
    switch (rb_Irligth10ms_to4_counter_mg)
    {
    case 1: //case block zero  Day-Night Detection
      IO_CalculateWiperActivity();        // (provides the wipecounters for LS-Software)
      switch (uF_modi_lightsens_g.AllBit & 0x0F)
        //Switch Lightsensor Mode
      {
      case cb_DARKSTART_mg :               //Case Darkstartmode
        light_darkstart_calc();              //light_darkstart_calculations day/night recognition
        break;
      case cb_DAY_mg :                         //Case Daymode
        light_day_to_night_calc();      //light_day_to_night_calculations
        break;
      case cb_NIGHT_mg :                 // Case Nightmode
        light_night_to_day_calc();        //light_night_to_day_calculations
        break;
      case cb_TUNNEL_mg :                    // Case Tunnelmode
        light_tunnel_to_night_calc();      // light_tunnel_to_night_calculation
        break;
      default:
        uF_modi_lightsens_g.AllBit = cb_NIGHT_mg;  // ERROR ->go to Night
        /* PRQA S 0277 1 *//* << Sensitivity treatment>> */
        uF_modi_lightsens_inv_g.AllBit = ~cb_NIGHT_mg; /*VDR_129 use sensitivity treatment*/
        if (rb_SoftwareErrorCounter_g < 0xff)
        {
          rb_SoftwareErrorCounter_g++;
        }
        break;
      }
      break;
    case 2:    // case block one    Tunneldetection
      switch (uF_modi_lightsens_g.AllBit & 0x0F)
        //Switch Lightsensor Mode
      {
      case cb_DARKSTART_mg :        //case Darkstart
        break;
      case cb_NIGHT_mg :          //case Night
        break;
      case cb_TUNNEL_mg :      //case Tunnel
        light_tunnel_to_day_calc();    //light_tunnel_to_day_calc
        break;
      case cb_DAY_mg :
        light_day_to_tunnel_calc();        //tunnel recognition from day
        break;
      default:
        uF_modi_lightsens_g.AllBit = cb_NIGHT_mg;  //ERROR ->go to Night
        /* PRQA S 0277 1 *//* << Sensitivity treatment>> */
        uF_modi_lightsens_inv_g.AllBit = ~cb_NIGHT_mg; /*VDR_129 use sensitivity treatment*/
        if (rb_SoftwareErrorCounter_g < 0xff)
        {
          rb_SoftwareErrorCounter_g++;
        }
        break;
      }
      rb_LS_Potistage_alt_g = rb_LSPotiStage_g; /*VCO_41 set old value Value is checked */
      break;
    case 3:     /* case block two*/
      light_VetoForLightOff(); /*call Veto Function for lightsensor algorithm*/
      light_highway_detection();   //light_highway_detection
      //unused function   light_circulating_air_calc();     //calculate circulating air flag
      break;
    case 4:    // case block three
      light_Threshold_cac();
      light_rainsensor_night_bit_calc();  //set or clear night bit for rain sensor
      break;
    default:     // case block four
      light_Regulation48();
#ifdef CS_TWILIGHT_TO_DARK
      twilightToDark();
      darkToTwilight();
#endif
      
      rb_Irligth10ms_to4_counter_mg = 0;     //Reset Taskcounter
      if (rb_SoftwareErrorCounter_g >= 3)
      {
        rbi_SoftwareBug_g = TRUE;
      }
      else if (rb_SoftwareErrorCounter_g > 0)
      {
        uF_modi_lightsens_g.AllBit = cb_NIGHT_mg;  //ERROR ->go to Night
        /* PRQA S 0277 1 *//* << Sensitivity treatment>> */
        uF_modi_lightsens_inv_g.AllBit = ~cb_NIGHT_mg; /*VDR_129 use sensitivity treatment*/
      }
      else 
      {
      } /*for Misra Compliance*/
      
      if ((uF_Check_lightsensor_g.AllBit & 0x7F) > 0) /*VDR_129 do not create Errorbit for treatment*/
      {
        rbi_LightSensorError_g = 1;
      }
      else 
      {
        rbi_LightSensorError_g = 0;
      }
      light_ambientlight_mean_calc();        //light_ambientlight_mean_calc ()
      light_rain_lighton_calculation();    // light_rain_lighton_calculation()
      break;
    }
  }
}
