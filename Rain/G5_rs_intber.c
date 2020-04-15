/******************************************************************************
*******************************************************************************
**
** Funktion:   IntBer()
**
**
** Bearbeiter: Bernd Schmid Abt. TKW
** Datum:      25.03.98
** geaendert:  25.03.98
**
** Funktion:   - Berechnung der Intervallzeit
**             - Berechnung der Nachwischzyklen
**
*******************************************************************************
******************************************************************************/
/******************************************************************************/
/* History                                                                    */
/*----------------------------------------------------------------------------*/
/* Date      VDR_Number     Description                                       */
/*----------------------------------------------------------------------------*/
/* 13.07.11  VDR_686  AL    correct not initialised local variable*/
/* 15.03.11  VSC_4    FS    Implement compiler defines project related, also QAC-defines*/
/* 10.06.10  VC0_58   AL    limited interval decreasment more homogenous rain
sensor interval*/
/* 19.03.08  VDR_168        TMC request, 1 second should be the shortest Interval*/
/* 01.04.15  VDR_866  MP    Remove of rainsens.c for no-rain-variants*/
/******************************************************************************/
#include "G5_rs_def.h"
#include "G5_rs_intber.h"
#include "G5_rs_task.h"
#include "G5_rainsens.h"
#include "G5_rs_ext.h"
/*
const unsigned char cab_INTERMDELAY[9][9] = {
                                               {10,14,25,36,59,78,105,137,165},
                                               {10,14,25,36,56,75,100,130,155},
                                               {10,14,22,33,53,66,85,113,130},
                                               {10,14,22,33,45,61,78,100,117},
                                               {10,14,22,33,44,59,72,93,108},
                                               {10,14,22,33,42,55,67,85,97},
                                               {10,14,22,33,41,54,63,78,80},
                                               {10,14,22,33,38,51,75,72,87},
                                               {10,14,22,33,37,49,56,70,82}};
*/
const unsigned char cab_INTERMDELAY_2[9][9] = {
                                              {10,14,25,37,75,93,105,172,200},
                                              {10,14,25,37,72,90,105,163,192},
                                              {10,14,25,37,69,87,100,157,185},
                                              {10,14,25,37,66,84,95,150,177},
                                              {10,14,25,37,63,81,88,142,170},
                                              {10,14,25,36,59,78,105,137,165},
                                              {10,14,25,36,56,75,100,130,155},
                                              {10,14,25,36,53,72,95,123,145},
                                              {10,14,25,36,50,67,88,110,130}};
const unsigned char cab_INTERMDELAY[9][9] = {
                                               {10,14,25,36,59,78,105,137,165},
                                               {10,14,25,36,56,75,100,130,155},
                                               {10,14,25,36,53,72,95,123,145},
                                               {10,14,25,36,50,67,88,110,130},
                                               {10,14,25,36,49,64,82,103,120},
                                               {10,14,25,36,47,61,77,93,107},
                                               {10,14,25,36,46,60,73,85,100},
                                               {10,14,25,36,43,57,65,80,95},
                                               {10,14,25,36,42,55,62,78,90}};


static void IntTab(unsigned char rub_Speicher);      /*Table for Interval Time*/

void IntBer(void)
{
  unsigned char rub_TempIntBer_l;
  unsigned char rub_LimitedLastWiperSpeed_l;
  unsigned short int ruw_InternlIntervalTimeRes_l;    /*use variable to be sure that no overflow occures*/
  if(rbi_Tropfen_Merker==1)
  {
    /* Merker fuer gueltigen Tropfen gesetzt
    Anzahl der Nachwischzyklen nur bei stehendem Motor, bzw.
    wenn Motor schon laenger als 200ms laeuft (5*40) aktualisieren.*/
    if((rub_WiperMotorTime==0)||(rub_WiperMotorTime>5))
    {
      /* Berechnung der Nachwischzyklen
      ==============================
      Nachwischzaehler neu setzten, wenn gueltiges Signal vorhanden
      Wert ist Abhaengig von der Intervallzeit, die sich
      lange Intervallzeit: wenig Nachwischen
      kurze Intervallzeit: oefter Nachwischen */
      
      if(rub_Int_Speicher >= rub_Ovr_Speicher)     /*Overridespeicher < Intervallspeicher*/
      {
        
        /*=> nachlassender Regen, somit weniger Nachwischen*/
        rub_TempIntBer_l=(rub_Int_Speicher >> 1) + (rub_Ovr_Speicher >>1);
      }
      else
      {
        rub_TempIntBer_l=rub_Int_Speicher; /*use slow int memory */
      }
      
      IntTab(rub_TempIntBer_l);             /*call interval table with memory contents*/
      /*Nachwischzaehler wird aus der oben berechneten Intervallzeit bestimmt*/
      if (rbi_Night == 1)
      {
        /*The here used Interval Time does not represent the actual interval time of the wiper.
        Here the Interval Time  is only used to calculate more after wipes at night,
        that is why, the interval time is shortened at night*/
        if (rub_RSIntermDelayInit_internal > CB_NACHWISCH_NIGHT_INTTAB_DEC)
        {
          rub_RSIntermDelayInit_internal -=CB_NACHWISCH_NIGHT_INTTAB_DEC;
          
        }
        else
        {
          rub_RSIntermDelayInit_internal = 0;
        }
      }
      /*With the Interval Time (at night a shorter Interval Time is used,
      see above) After Wipes are calculated */
      
        if (rub_RSIntermDelayInit_internal <= CB_NACHWISCH_4)
        {
          /*4 Wischungen*/
          rub_Nachwisch_Count = 4;
        }
        else
          if(rub_RSIntermDelayInit_internal <= CB_NACHWISCH_3)
          {
            /*drei Wischungen*/
            rub_Nachwisch_Count = 3;
          }
          else
            if(rub_RSIntermDelayInit_internal <= CB_NACHWISCH_2)
            {
              /*zwei Wischungen*/
              rub_Nachwisch_Count = 2;
            }
            else
            {
              /*eine Wischung*/
              rub_Nachwisch_Count = 1;
            }
    }
    /* Intervallzeit wird bei gueltigem Signal aus max. Speicher Wert berechnet,
    Wert fuer max. Speicher wird bei jedem Wischzyklus neu bestimmt*/
    IntTab(rub_Speicher_max); /*At night, a special Interval Time is
    calculated. So, at night, it is necessary to override the Interval Time
    with actual Interval Time of the Rain Sensor Software*/
    if (rb_IntervalTimereductLimitFact_g >=2)  /*VC0_58 to adjust interval calculation disabled for < 2 */
    {
      byte rb_temp_IntermDelay_l;
      if (rb_Parametersatz_Regensensorik_g <= 1)
      {
        rb_temp_IntermDelay_l = cab_INTERMDELAY_2[rub_PotiStage][8];
      }
      else
      {
        rb_temp_IntermDelay_l = cab_INTERMDELAY[rub_PotiStage][8];
      }
      if (rub_IntermDelayTime_LalstWipe_g > rb_temp_IntermDelay_l/*cab_INTERMDELAY[rub_PotiStage][8]*/) /*is interval time longer than longest
        interval time in this potistage*/
      {
        /*calculate minimum allowed interval time */
        rub_LimitedLastWiperSpeed_l =  rb_temp_IntermDelay_l/*cab_INTERMDELAY[rub_PotiStage][8]*/ / rb_IntervalTimereductLimitFact_g;  
      }
      else
      {
        /*calculate minimum allowed interval time */
        rub_LimitedLastWiperSpeed_l = rub_IntermDelayTime_LalstWipe_g / rb_IntervalTimereductLimitFact_g; 
      }
      if (rub_RSIntermDelayInit_internal < (rub_LimitedLastWiperSpeed_l)) /*check limitation */
      {
        rub_RSIntermDelayInit_internal = rub_LimitedLastWiperSpeed_l;  /*limit interval time reduction*/
      }
    }    
    rbi_LowSpeed_Out_g = 0;
    rb_DoneAfterwipe_g = 0; /* new wipe*/
  }
  else
  {
    /*Nachwischen
    ***********
    Merker fuer gueltigen Tropfen nicht gesetzt => Nachwischen
    Abfrage, ob Nachwischungen gewuenscht*/
    if(rub_Nachwisch_Count>0)
    {
      /*Intervallzeit fuer Nachwischzyklen wird aus dem Intervallspeicher
      bestimmt*/
      if (rbi_LowSpeed_Out_g > 0)
      {
        
        rub_RSIntermDelayInit_internal = ((rb_2_5SecondsDelay_g + CB_FIX_INTERVALBREAK)<<1);
        
      }
      else
      {
        
        IntTab(rub_Int_Speicher);
        if  (rb_DoneAfterwipe_g < 1)
        {
          /*rub_RSIntermDelayInit_internal =  (rub_RSIntermDelayInit_internal>>1)+(rub_IntermDelayTime_LalstWipe_g>>1);*/
          /*(rub_RSIntermDelayInit_internal>>2)+(rub_IntermDelayTime_LalstWipe_g>>1)+(rub_IntermDelayTime_LalstWipe_g>>2);*/
          ruw_InternlIntervalTimeRes_l = rub_IntermDelayTime_LalstWipe_g;
        }
        else if (rb_DoneAfterwipe_g < 2)
        {
          ruw_InternlIntervalTimeRes_l = (unsigned int) (rub_IntermDelayTime_LalstWipe_g)+(rub_IntermDelayTime_LalstWipe_g/CB_AFTERWIPE_0_INCREASE_DIVIDER);
        }
        else if  (rb_DoneAfterwipe_g < 3)
        {
          ruw_InternlIntervalTimeRes_l = (unsigned int) (rub_IntermDelayTime_LalstWipe_g)+(rub_IntermDelayTime_LalstWipe_g/CB_AFTERWIPE_1_INCREASE_DIVIDER);
        }
        else
        {
          ruw_InternlIntervalTimeRes_l =  (unsigned int)(rub_IntermDelayTime_LalstWipe_g)+(rub_IntermDelayTime_LalstWipe_g/CB_AFTERWIPE_2_INCREASE_DIVIDER);
        }
        if (ruw_InternlIntervalTimeRes_l > CB_INTERMDELAY_MAX)
        {
          rub_RSIntermDelayInit_internal = CB_INTERMDELAY_DIREKT;
          rub_Nachwisch_Count = 0;
        }
        else
        {
          rub_RSIntermDelayInit_internal = (unsigned char)ruw_InternlIntervalTimeRes_l;
        }
        
      }
    }
    else
    {
      /*Direktbetrieb
      *************
      Nachwischzaehler = 0 =>Direktbetrieb
      Variable fuer Intervallzeit mit Wert fuer Direktbetrieb laden*/
      rub_RSIntermDelayInit_internal=CB_INTERMDELAY_DIREKT;
    }
  }
}

/*******************************************
*
* Funktion zur Bestimmung der Intervallzeit
* Function to get the interval time input is the memory contents
* normaly interval memory output will be written in global variable
********************************************/
static void IntTab(unsigned char rub_Speicher)
{
  /*Declaration of local variables*/
  unsigned char rub_number_of_interval_areas;
  unsigned char rub_IntTabPotistageNight_l; /*VDR_686 correct not initialised local variable*/
  /*- Intervall  zeit bestimmen
  - Intervall-Bereiche zaehlen
  - SPEICHER kleiner als 119?  (Abweisende Schleife !!)
  - Zaehler der Intervall-Bereiche loeschen*/
  rub_number_of_interval_areas=0;           /*clear local count value*/
  while(rub_Speicher < CB_INTERVALL_GRENZE)   /*input value lower Interval boarder*/
  {
    rub_Speicher+=CB_INTERVAL_AREA;          /*increment input value with the area for intervals*/
    rub_number_of_interval_areas++;          /*increment count value*/
  }
  if (rub_number_of_interval_areas > CB_MAX_NUMBER_OF_INTAREAS )
  {
    rub_number_of_interval_areas=CB_MAX_NUMBER_OF_INTAREAS ;
  }
  
  if (rbi_Night > 0)
  {
    rub_IntTabPotistageNight_l = rub_PotiStage_alt+2;  /*increase sensitivity*/
  }
  else 
  {
    rub_IntTabPotistageNight_l = rub_PotiStage_alt;  /*VDR_686 correct not initialised local variable*/
  }
  
  if(rub_IntTabPotistageNight_l > cb_MAXPOTISTAGE_g)    /*is sensitivity higher then allowed?*/
  {
    rub_IntTabPotistageNight_l = cb_MAXPOTISTAGE_g;    /*set sensitivity to maximum*/
  }
  
  if(rb_Parametersatz_Regensensorik_g <= 1)
  {
    rub_RSIntermDelayInit_internal=cab_INTERMDELAY_2[rub_IntTabPotistageNight_l][rub_number_of_interval_areas];
  }
  else /*if(rb_Parametersatz_Regensensorik_g == 1)*/
  {
    /*Get interval time from table with sensitivity and memory value*/
    rub_RSIntermDelayInit_internal=cab_INTERMDELAY[rub_IntTabPotistageNight_l][rub_number_of_interval_areas];
  }
}