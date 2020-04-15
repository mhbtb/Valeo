/*************************************************************************

Company : Valeo Schalter und Sensoren GmbH

Project : G5 RLxS Sensor

Component : G5_TwilightToDark.c

Documentation reference :   Light Sensor Strategy
Overview of the component : Generates the light states for twilight and
darkness. No safety relevant code shall be included here.

Evolution of the component : since generation 5

*************************************************************************/
/******************************************************************************/
/* History                                                                    */

/* PRQA S 2201,2215,2217,715 EOF *//*<< Indentation and line length  >>*/
/******************************************************************************/
/*                Include common and project definition header                */
/******************************************************************************/

#include "G5_TwilightToDark.h"
#include "G5_ASIC_Control_sr.h"
#include "G5_Light_Defs.h"
#include "G5_DiagE2_projectconfig.h"

/******************************************************************************/
/*                       Definition of local variables                        */
/******************************************************************************/
static byte rb_darkIsActive = FALSE;

static word rw_DarkToTwilightCounter_g = 0; 
static word rw_TwilightToDarkCounter_g = 0; 

/******************************************************************************/
/*                  Declaration of local function prototypes                  */
/******************************************************************************/

static void setDarkActive(byte isActive);

/******************************************************************************/
/*                       Definition of local functions                        */
/******************************************************************************/
static void setDarkActive(byte isActive){
  if(isActive != 0)
  {  
    rb_darkIsActive = TRUE;
    rw_TwilightToDarkCounter_g = 0;
  }else
  {
    rb_darkIsActive = FALSE;
    rw_DarkToTwilightCounter_g = 0;
  }
}

/**************************************************************************
Syntax   : void  initTwilightToDark(byte twilightIsOn)
Object   : initTwilightToDark(byte twilightIsOn)
Parameters : twilightIsOn defines if the initial state is on or off 
Return  : none
Calls   : by init routine
***************************************************************************
Inputs validation conditions:
none
***************************************************************************
Pseudo-code : State machine for the light sensor software
**************************************************************************/
void initTwilightToDark(byte twilightIsOn){
  /* here we get the info about the twilight which is on. We need to check if
  also the dark must be active*/
  /* PRQA S 3415 3 */ /*Checked, no side effects*/
  if((twilightIsOn != FALSE)
     && (get_rw_Amb_light16bit_g() < rw_TwilightToDarkThreshAMB_g)
        && (get_rw_FW_light16bit_g() < rw_TwilightToDarkThreshFW_g)
          )
  {
     setDarkActive(TRUE);
  }else
  {
     setDarkActive(FALSE);
  }
  
}

/**************************************************************************
Syntax   : void  twilightToDark(void)
Object   : twilightToDark(void)
Parameters : none 
Return  : none
Calls   : every 50 ms
***************************************************************************
Inputs validation conditions:
none
***************************************************************************
Pseudo-code : State machine for the light sensor software
**************************************************************************/

void twilightToDark(void) /*VCO109 VDR_773*/
{

  if (rb_darkIsActive == FALSE) 
  {
    /* PRQA S 3415 1 */ /*Checked, no side effects*/
    if ((get_rw_Amb_light16bit_g() < rw_TwilightToDarkThreshAMB_g)
        && (get_rw_FW_light16bit_g() < rw_TwilightToDarkThreshFW_g))
    {
      if (rw_TwilightToDarkCounter_g >= rw_TwilightToDarkTime_g)
      {
        setDarkActive(TRUE);
      }
      else 
      {
        rw_TwilightToDarkCounter_g += 3;
      }
    } 
     /* PRQA S 3415 1 */ /*Checked, no side effects*/
    else if ((get_rw_Amb_light16bit_g() < (rw_TwilightToDarkThreshAMB_g / 3))
             && (get_rw_FW_light16bit_g() < (rw_TwilightToDarkThreshFW_g + (rw_TwilightToDarkThreshFW_g / 2)))
               && (get_rw_IR_light16bit_g() < (rw_TwilightToDarkThreshAMB_g / 3)))
    {
      if (rw_TwilightToDarkCounter_g >= rw_TwilightToDarkTime_g) 
      {
        setDarkActive(TRUE);
      }
      else 
      {
        rw_TwilightToDarkCounter_g += 2;
      }
    }
    else 
    {
      rw_TwilightToDarkCounter_g = 0;
    }
  }
}

/**************************************************************************
Syntax   : void  darkToTwilight(void)
Object   : darkToTwilight(void)
Parameters : none 
Return  : none
Calls   : every 50 ms
***************************************************************************
Inputs validation conditions:
none
***************************************************************************
Pseudo-code : State machine for the light sensor software
**************************************************************************/

void darkToTwilight(void) 
{
  if(rb_darkIsActive != 0)
  {
    /* PRQA S 3415 1 */ /*Checked, no side effects*/
    if ((((get_rw_FW_light16bit_g() > rw_DarkToTwilightThreshFW_g)
          && (get_rw_Amb_light16bit_g() > rw_DarkToTwilightThreshAMB_g)) 
         && (get_rw_IR_light16bit_g() > cb_IR_NIGHT_THRESHOLD_s /3 ))) 
    {
           if (rw_DarkToTwilightCounter_g >= rw_DarkToTwilightTime_g) 
           {
              setDarkActive(FALSE);
           }
           else 
           {
             rw_DarkToTwilightCounter_g++;
           }
    }
    else 
    {
      rw_DarkToTwilightCounter_g = 0;
    }
  }
}

/*word getDarkToTwilightCounter_g(){return rw_DarkToTwilightCounter_g;}
word getTwilightToDarkCounter_g(){return rw_TwilightToDarkCounter_g;}*/
/**************************************************************************
Syntax   : byte  isDarkActive(void)
Object   : isDarkActive(void)
Parameters : none 
Return  : TRUE if the dark state is on, FALSE otherwise
Calls   : on demand 
***************************************************************************
Inputs validation conditions:
none
***************************************************************************
Pseudo-code : getter function
**************************************************************************/
byte isDarkActive(void){
  return rb_darkIsActive;
}