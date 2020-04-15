  /* PRQA S 0831 EOF */ /* << 2010 01 08, 2 lines infected, Files need to be included from lower directory>> */
/******************************************************************************
*******************************************************************************
**
** Funktion:   Empfindlichkeit
**
** Datei:      Empf.c
**
** Bearbeiter: Bernd Schmid Abt. TKW
** Datum:      10.03.98
** geaendert:  11.03.98
**
** Funktion:   Empfindlichkeitseinstellung in Abhaengigkeit von der
**             Potistellung
**
*******************************************************************************
******************************************************************************/
/* History                                                                    */
/*----------------------------------------------------------------------------*/
/* Date      VDR_Number     Description                                       */
/*----------------------------------------------------------------------------*/
/* 03.05.10     VDR_511         AL Polyspace improvements*/
/* 10.02.10     VCO_33,VDR_437  FS LIN_sensitivity from Standard Sensor converted in EEPROM_Sensitivity*/
/* 09.10.09     VDR_373         FS Single or Double Overwiping -Window implemented */
/* 23.01.08     VDR_126            RLS_ALL_Continous wiper speed could be reached by change of poti stage without rain*/
/* 27.11.08     VDR_296         AL Posche: The Rainsensor should be more sensitive in different conditions*/
/* 09.07.15     VDR_889         MP Overwipe empf_faktor reduced*/
/******************************************************************************/
/*include files*/
#include "ior5f109be.h"
#include "ior5f109be_ext.h"

#include "G5_projectDefs.h"
#include "G5_rs_empf.h"
// Defines for rainsensor-constants
#include "G5_rs_def.h"
#include "G5_rs_lib.h"
#include "G5_rainsens.h"
#include "G5_IRlight.h"
#include "G5_rs_task.h"
#include "G5_rls_linst.h"
#include "G5_E2ProjectConfig.h"
/* defines */

#define CB_WENDELAGEOBENTOPARK_S 2
#define CB_INPARKPOSITION_S      0

byte AfterWiperMotorTime_counter=40;
byte Threshold_AfterWiperMotorTime; /*VDR_540*/
byte Threshold_SecondOverwipe_Start; /*VDR_540*/

static void Empf_OverwipeLimitation(void);

void Empf(void)
{
  //definition of local variable
  static unsigned char rb_TimeSinceLastSetWipe_s; /*VDR_126 1 digit is 40ms*/
  unsigned int ruw_TempEmpf2_l;                   /*VDR_126 use word not to have problems in "if causes"*/
  unsigned char rub_PotiDiff_l;
  unsigned char rub_TempEmpfPoti_l;              /*VDR_126 rename tu use byte*/
#ifdef RSS_INKREMENTWIPE_FIX_CONTINUOUS   
  byte rub_PotiStage_diff_l;
#endif
  //-Abfrage, ob Potistellung geaaendert wurde
  
  if (rub_RSIntermDelayInit > 250)  /*VDR_126 */
  {
    if (rb_TimeSinceLastSetWipe_s <255)
    {
      rb_TimeSinceLastSetWipe_s++; /*increment counter for time since last set wipe*/
    }
  }
  else
  {
    rb_TimeSinceLastSetWipe_s=0;/*clear counter for time since last set wipe*/
  }
  
  
  if((rub_PotiStage != rub_PotiStage_alt) && (rbi_LSS_Interval_g != 0))//has RS sensitivity changed and interval active?
    
  {
    //-Speicher anpassen
    if (rub_PotiStage > rub_PotiStage_alt) //is sensitivity higher?
    {
#ifdef RSS_INKREMENTWIPE_FIX_CONTINUOUS
  rub_PotiStage_diff_l = rub_PotiStage - rub_PotiStage_alt;
  if(rub_PotiStage_diff_l > 1)
  {
        rub_PotiStage_diff_l = 1;
  }
  ruw_TempEmpf2_l = rub_PotiStage_diff_l * CB_EMPF_ANPASS;
#else
  //-Empfindlichkeit wurde erhoeht!
  ruw_TempEmpf2_l = (rub_PotiStage - rub_PotiStage_alt) * CB_EMPF_ANPASS;//calculate offset for interval memories
#endif
      //-Intervallspeicher erhoehen
      if ((rub_Int_Speicher + ruw_TempEmpf2_l) < CB_INT_SPEICHER_MAX) //can offset added without overflow?
      {
        /*VDR_126 block lowSpeed wiping if last wipe was not longer than 6 seconds*/
        if ((rb_TimeSinceLastSetWipe_s > 240) && (((rub_Int_Speicher + ruw_TempEmpf2_l) > CB_STUFE1_OG)))
        {
          if (rub_Int_Speicher < CB_STUFE1_OG)
          {
            rub_Int_Speicher = CB_STUFE1_OG;
          }
        }
        else
        {
          rub_Int_Speicher += ruw_TempEmpf2_l; //add offset
        }
      }
      else
      {
        rub_Int_Speicher = CB_INT_SPEICHER_MAX; //set to max value
      }
      ruw_TempEmpf2_l = (ruw_TempEmpf2_l >> 1); //offset for fast interv. memory
      if ((rub_Ovr_Speicher + ruw_TempEmpf2_l) < CB_OVR_SPEICHER_MAX) //can fast memory overflow?
      {
        /*VDR_126 block lowSpeed wiping if last wipe was not longer than 6 seconds*/
        if ((rb_TimeSinceLastSetWipe_s > 240) && (((rub_Ovr_Speicher + ruw_TempEmpf2_l) > CB_STUFE1_OG))) 
        {
          if (rub_Ovr_Speicher < CB_STUFE1_UG)
          {
            rub_Ovr_Speicher = CB_STUFE1_OG;
          }
        }
        else
        {
          rub_Ovr_Speicher += ruw_TempEmpf2_l; //add offset
        }
      }
      else
      {
        rub_Ovr_Speicher = CB_OVR_SPEICHER_MAX; //set to max value
      }
      if (rbi_RSWipeSlowDmd == 1)
      {
        if (ruw_StX_Speicher < (CW_MAX_STX_SPEICHER - 9000))
        {
          ruw_StX_Speicher += 9000;
        }
        else
        {
          ruw_StX_Speicher = CW_MAX_STX_SPEICHER;
        }
      }
      else
      {
        ruw_StX_Speicher = CB_STXSPEICHER_INTERVAL_MAX;
      }
    }
    else
    {
      //-Empfindlichkeit wurde veringert
      
      rub_PotiDiff_l = (rub_PotiStage_alt-rub_PotiStage);
      if (rub_PotiDiff_l > 4)
      {
        rub_PotiDiff_l = 4;
      }
      /*VDR_126 rename tu use byte*/
	  
	  
      for (rub_TempEmpfPoti_l=(rub_PotiDiff_l);rub_TempEmpfPoti_l > 0;rub_TempEmpfPoti_l--)
      {
        if (ruw_StX_Speicher >CW_SCHWELLE_STUFE4) /*Change for Porsche claim 20141106*/
        {
          /*-Intervallspeicher entladen*/
          rub_Int_Speicher -= (rub_Int_Speicher / 16);                 /*sub offset-> -6,25%*/
          /*-Overridespeicher loeschen*/
          rub_Ovr_Speicher -= (rub_Ovr_Speicher / 8);  /*VDR_296 Potispeicherdecremet weniger entladen
          sub offset-> -12,5%*/
        }
        else if (ruw_StX_Speicher >CB_STXSPEICHER_INTERVAL_MAX) /*Change for Porsche claim 20141106*/
        {
          /*-Intervallspeicher entladen*/
          rub_Int_Speicher -= (rub_Int_Speicher / 12);                 /*sub offset-> -8,33%*/
          /*-Overridespeicher loeschen*/
          rub_Ovr_Speicher -= (rub_Ovr_Speicher / 6);  /*VDR_296 Potispeicherdecremet weniger entladen
          sub offset-> -16,67%*/
        }
        else
        {
        /*-Intervallspeicher entladen*/
        rub_Int_Speicher -= (rub_Int_Speicher / 8);                 /*sub offset-> -12,5%*/
        /*-Overridespeicher loeschen*/
        rub_Ovr_Speicher -= (rub_Ovr_Speicher / 4);  /*VDR_296 Potispeicherdecremet weniger entladen
        sub offset-> -25%*/
      }
      }
      /*
      //-Empfindlichkeit wurde veringert
      rub_TempEmpf_l=(rub_PotiStage_alt-rub_PotiStage)*CB_EMPF_ANPASS; //calculate negative offset
      //-Intervallspeicher entladen
      if(rub_Int_Speicher > rub_TempEmpf_l)                            //can offset substr. without underflow?
      {
      rub_Int_Speicher-=rub_TempEmpf_l;                             //sub offset
    }
      else
      {
      rub_Int_Speicher=0;                                            //clear memory
    }
      */
      //- rub_St2_Epr = (CB_EP_ST2_EPR_OUT_ST2 - 1);              // reset variables to go out of high speed
      //- ruw_SigInt=0;                 // Integrationsspeicher Signale loeschen
      ruw_Signal=0;                    //clear memory for present signal
      //- Speicher fuer aktuelles Signal loeschen
      
      //Stufe 2Speicher loeschen
      ruw_St2_Speicher=0;        //clear memory for high speed wiping
      rub_WischZykl_Count=0;     //clear counter for high speed cycles
      //-Tropfenmerker loeschen
      rbi_Tropfen_Merker=0;      //clear drop flag
      rub_Speicher_max=0;        //clear max. memory contents
      //-Nachwischzyklen verringern
      if(rub_Nachwisch_Count>1)  //more than one afterwipe
      {
        rub_Nachwisch_Count=1;  //set to one afterwipe
      }
    }
  }
  //-Wert fuer Potistellung sichern
  rub_PotiStage_alt=rub_PotiStage; //store old RS-Sensitivity
  //-Variablen entsprechend der Potistellung setzen
  Empf_Einstellung();                 //Set all sensitivity parameters
  if ((rb_speed_in_kmh_g > 135) && (rb_Speedreduct_g))
  {
    rub_Empf_Faktor -= (rub_Empf_Faktor>>3);  // Empf Faktor auf 88%
  }
  Empf_OverwipeLimitation();          //reduces Sensitivity for the OverwipeCondition
  
  
  //adjustment of sensitivity factor on Windshield
  
  //Formel wurde berechnet aus den X-Y Messwerten und ein wenig abeflacht
  //Berechnen der Scheibenabhangigen empfindlichkeit
  ruw_TempEmpf2_l = ((((unsigned int)(rb_880nm_Transmission_g)+222))*rub_Empf_Faktor);/*VDR511*/    
  rub_Empf_Faktor = (unsigned char)(((128+ruw_TempEmpf2_l)>>8));/*VDR511*/ //Runden und Skalieren der Zwischenwerte
  
  if(rub_Int_Speicher > 140)             //has interval memory high value
  {
    if (rbi_Night == 0)
    {
      rub_Dec_Int_Sp--; //decrease faster if the memory is fuller
    }
    if (rub_Int_Speicher > CB_STUFE1_UG) //has interval memory high value
    {
      rub_Dec_Int_Sp -= 3;
      if (rb_speed_in_kmh_g <= 10)
      {
        rub_Dec_Int_Sp -= 3; //decrease faster if the memory is fuller
      }
      if ((ruw_SigInt + ruw_Signal) < 100)
      {
        //decrease faster if the memory is fuller and signal empty
        if ((rbi_RSWipeSlowDmd == 1) || (rbi_RSWipeFastDmd == 1))
        {
          rub_Dec_Int_Sp -= 3;
          if (rb_speed_in_kmh_g <= 10)
          {
            rub_Dec_Int_Sp -= 3; //decrease faster if the memory is fuller
          }
        }
      }
    }
  }
  else
  {
    if (rub_Int_Speicher < 70)
    {
      rub_Dec_Int_Sp += 3;
    }
  }
  

  
  
  if ((rub_Dec_Int_Sp <= (CB_DEC_OVR_SPEICHER + 3)) || (rub_Dec_Int_Sp > 100)) /* recover underflow from before*/
  {
    rub_Dec_Int_Sp = CB_DEC_OVR_SPEICHER + 3;
  }
  
}
/******************************************************************************
**
** void Empf_Einstellung(void)
**
** Bearbeiter: Bernd Schmid Abt. TKW
** Datum:      28.04.98
** geaendert:  28.04.98
**
** Funktion:   Aktualisierung der Variablen zur Empfindlichkeitseinstellung
**             in Abhaengigkeit von der Potistellung, wenn sich diese Aendert
**
******************************************************************************/
void Empf_Einstellung(void)
{
  //definition of local variable
  unsigned char rub_PotistageNight_l;
  
  rub_PotistageNight_l = rub_PotiStage_alt+(rbi_Night);  //increase sensitivity
  if  (rub_PotistageNight_l > cb_MAXPOTISTAGE_g) // is checked in switch case
  {
    rub_PotistageNight_l = cb_MAXPOTISTAGE_g;
  }
  
  rub_Empf_Faktor = ((byte)((((rb_RSEmpfFactorScaling_g)*(((((word)(rab_RS_Sensitivity_g[rub_PotistageNight_l]))*rb_LIN_SensitivityShift_g))/9))+4)>>3))+rbi_Night;

  ruw_Schwelle_min = ((word)(cab_RS_SchwelleMin[rub_PotistageNight_l]))<<2;
  rub_Dec_Int_Sp = CB_DEC_INT_SP_OFFS + cab_RS_Dec_IntSP_Offs[rub_PotistageNight_l];
  rub_Empf_Faktor_St2 = CB_EMPF_FAKTOR_ST2_OFFS + cab_RS_Empf_Fakt_St2[rub_PotistageNight_l];
  
}
/******************************************************************************
**
** void Empf_OverwipeLimitation(void)
**
** Bearbeiter: Andreas Lagler Abt. TRS
** Datum:      16.10.2002
** geaendert:  16.10.2002
**
** Funktion:   Beschrankt die Empfindlichkeit im Moment
**             der Uberwischung des Sensors
**
**
******************************************************************************/
static void Empf_OverwipeLimitation(void)
{
  byte rb_SEATAusblendTime_l;
  static byte rb_reducedEmpfNachlauf_g;
  word rw_temp_Faktor_l;
   
  
#ifdef _ONETIME_OR_DOUBLE_OVERWIPED_
  Threshold_FirstOverwipe_Start=(byte)((word)EEPROM_Threshold_FirstOverwipe_Start*rb_LastWiperMotorTime_g/100);
  Threshold_FirstOverwipe_End=(byte)((word)EEPROM_Threshold_FirstOverwipe_End_DoubleOverwiped*rb_LastWiperMotorTime_g/100);
  Threshold_SecondOverwipe_Start=(byte)((word)EEPROM_Threshold_SecondOverwipe_Start*rb_LastWiperMotorTime_g/100);
  Threshold_AfterWiperMotorTime = (byte)((word)EEPROM_Threshold_AfterWiperMotorTime*rb_LastWiperMotorTime_g/100);
#endif /*_ONETIME_OR_DOUBLE_OVERWIPED_*/
  
  if (rbi_smearingreduct_upDown_Enabled)
  {
#ifdef _ONETIME_OR_DOUBLE_OVERWIPED_
    if(
       (
        (rub_WiperMotorTime < Threshold_FirstOverwipe_End)
          || (rub_WiperMotorTime > Threshold_SecondOverwipe_Start)
            ) && (rbi_ButterflyIsEquipped>0)&&(rbi_DoubleOverwiped>0)
         || (rbi_ButterflyIsEquipped<1)&&(rbi_DoubleOverwiped<1)
           )
#endif /*_ONETIME_OR_DOUBLE_OVERWIPED_*/
    {
    /*VDR_889 Overwipe empf_faktor reduced*/
      if((rub_WiperMotorTime>0)
#ifdef _ONETIME_OR_DOUBLE_OVERWIPED_
         &&(rbi_ButterflyIsEquipped<1)&&(rbi_DoubleOverwiped<1)
           ||(rub_WiperMotorTime > Threshold_FirstOverwipe_Start)&& (rbi_ButterflyIsEquipped>0)&&(rbi_DoubleOverwiped>0)
#endif /*_ONETIME_OR_DOUBLE_OVERWIPED_*/
             )
    {
      if (rub_IntermDelayTime_LalstWipe_g>200)
      {
        rub_Empf_Faktor /= 2;
      }
      else
      {
        rub_Empf_Faktor -= (rub_Empf_Faktor/3);
      }
    }
    
    if((rub_WiperMotorTime>=27) || (rub_IntermDelayTime<=4))
    {
      if(rub_Empf_Faktor>2)
      {
        rub_Empf_Faktor = (rub_Empf_Faktor/2);
      }
    }
    }
    
    if(
       (((rub_WiperMotorTime>0)&&(rub_WiperMotorTime < 5) && (rb_SchwelleInWipeLow_g))   // SEAT
        ||((rb_WiperPosition_g == CB_WENDELAGEOBENTOPARK_S)&& (!rb_SchwelleInWipeLow_g))) // AUDI
#ifdef _ONETIME_OR_DOUBLE_OVERWIPED_
         && (rbi_ButterflyIsEquipped<1)&&(rbi_DoubleOverwiped<1)
           || 
             ( (rub_WiperMotorTime > Threshold_SecondOverwipe_Start)
              || (AfterWiperMotorTime_counter < Threshold_AfterWiperMotorTime)
                )
               && (rbi_ButterflyIsEquipped>0)&&(rbi_DoubleOverwiped>0)
#endif /*_ONETIME_OR_DOUBLE_OVERWIPED_*/
                 )
    {
      /*reduce sensitivity liniar to 50% when rub_IntermDelayTime_LalstWipe_g > 200*/
      if ((rub_IntermDelayTime_LalstWipe_g>100) && (rub_IntermDelayTime_LalstWipe_g<=200))
      {
        rw_temp_Faktor_l = 30-20*rub_IntermDelayTime_LalstWipe_g/200;
        rub_Empf_Faktor = (rub_Empf_Faktor * rw_temp_Faktor_l)/20;
      }
      
      rub_Empf_Faktor -= (rub_Empf_Faktor/8)*(rub_Trockwisch_memory/10);
      
      if (rub_Int_Speicher < CB_INTSPEICHER_LONG_SENS_REDUCT)
      {
        rub_Empf_Faktor -= (rub_Empf_Faktor>>2);  // Empf Faktor auf 75%
      }
      if (rb_Sig_DownWipe_to_upWipe_g < 20)
      {
        rb_reducedEmpfNachlauf_g = 0;
        rub_Empf_Faktor -= (rub_Empf_Faktor>>3);  // Empf Faktor auf 88%
      }
      else if (rb_Sig_DownWipe_to_upWipe_g < 40)
      {
        rb_reducedEmpfNachlauf_g = 1;
        rub_Empf_Faktor -= (rub_Empf_Faktor>>3)+(rub_Empf_Faktor>>4);  // Empf Faktor auf 82%
      }
      else if (rb_Sig_DownWipe_to_upWipe_g < 100)
      {
        rb_reducedEmpfNachlauf_g = 3;
        rub_Empf_Faktor -= (rub_Empf_Faktor>>2);  // Empf Faktor auf 75%
      }
      else
      {
        rb_reducedEmpfNachlauf_g = 4;
        rub_Empf_Faktor -= (rub_Empf_Faktor>>2);  // Empf Faktor auf 75%
      }
      rb_reducedEmpfNachlauf_g += (rub_Trockwisch_memory/10);
    }
    else
#ifdef _ONETIME_OR_DOUBLE_OVERWIPED_
      if((rbi_ButterflyIsEquipped<1)&&(rbi_DoubleOverwiped<1))
      {
#endif /*_ONETIME_OR_DOUBLE_OVERWIPED_*/
    /*not in 2nd half of wiping or not wiping at all*/
        if( (rub_WiperMotorTime > 1)&&(rub_Int_Speicher < CB_INTSPEICHER_LONG_SENS_REDUCT))
    {
      rub_Empf_Faktor -= (rub_Empf_Faktor>>3);  // Empf Faktor auf 88%
    }
    else if (((rub_WiperMotorTime > 10) && (!rb_SchwelleInWipeLow_g))
             ||(((rub_WiperMotorTime > 15)||((rub_WiperMotorTime < 9)&&(rub_WiperMotorTime > 0))) && (rb_SchwelleInWipeLow_g)))
    {
      rub_Empf_Faktor -= (rub_Empf_Faktor>>4);  // Empf Faktor auf 94%
    }
#ifdef _ONETIME_OR_DOUBLE_OVERWIPED_
      }
#endif /*_ONETIME_OR_DOUBLE_OVERWIPED_*/
    else if (rb_reducedEmpfNachlauf_g > 0)
    {
      rb_reducedEmpfNachlauf_g--;
      rub_Empf_Faktor -= (rub_Empf_Faktor>>3);  // Empf Faktor auf 88%
    }
    else
#ifdef _ONETIME_OR_DOUBLE_OVERWIPED_
        if(rub_WiperMotorTime==0)
#endif/*_ONETIME_OR_DOUBLE_OVERWIPED_*/
    {
      rub_Empf_Faktor += (rub_Empf_Faktor>>4)+1;  // Empf Faktor auf 112% + 1 offsett for low sensitivities better
    }
    
    if ((rbi_RSWipeSlowDmd == 0)&&(rbi_RSWipeFastDmd == 0))
    { /*VDR_373 rub_Empf_Faktor for Interval Mode*/
      /*VDR_889 Overwipe empf_faktor reduced*/
      /*reduction of empf_faktor in interval, when car stopped and dry wipes are detected*/
      if((rub_WiperMotorTime>0) && (rb_speed_in_kmh_g < cb_IGNORE_IGNITION_SPEED))
      {
        rub_Empf_Faktor -= (rub_Empf_Faktor/3);
        
        if(rub_Trock_Wisch!=0)
        {
          rub_Empf_Faktor -= (rub_Empf_Faktor/5);
        }
      }
      
      if (rub_Empf_Faktor > rb_MaxOverwipeSensitivity_g)     //Is Sensitivity Faktor higher than the allowed?
        
      {
        if (rb_SchwelleInWipeLow_g)           /* SEAT*/
        {
          rb_SEATAusblendTime_l = (rub_Int_Speicher < CB_INTSPEICHER_LONG_SENS_REDUCT)? 10:8;
          if (((rub_WiperMotorTime < rb_SEATAusblendTime_l)&&(rub_WiperMotorTime > 0))      /* first overwipe*/
              ||((rub_IntermDelayTime > 0)&& (rub_IntermDelayTime < rb_SEATAusblendTime_l))) /*second overwipe*/
          {
            
            rub_Empf_Faktor=rb_MaxOverwipeSensitivity_g;                      /*Set to maximum*/
            
          }
        }
        else                                  /* AUDI*/
        {
          /*reduce Sensitivity if more than 32% of Schwelle MaxTime*/
          if((((rub_Delay_Ausbl-rub_Delay_Ausbl_count)>(rub_Delay_Ausbl>>1))
              && (rb_WiperPosition_g != CB_INPARKPOSITION_S))&&
             ((rub_Int_Speicher < CB_INTSPEICHER_LONG_SENS_REDUCT)||
#ifdef _ONETIME_OR_DOUBLE_OVERWIPED_
              ((rub_WiperMotorTime > Threshold_SecondOverwipe_Start)&& (rbi_ButterflyIsEquipped>0)&&(rbi_DoubleOverwiped>0))||
#endif /*_ONETIME_OR_DOUBLE_OVERWIPED_*/
              (((rub_Delay_Ausbl-rub_Delay_Ausbl_count)<(rub_Delay_Ausbl)))))
          {
            
            if  (rub_Int_Speicher < CB_INTSPEICHER_LONG_SENS_REDUCT)
            {
              rb_reducedEmpfNachlauf_g = 6;
            }
            if(rub_IntermDelayTime_LalstWipe_g>200)
            {
              rb_reducedEmpfNachlauf_g = 8;
            }
            
#ifdef _ONETIME_OR_DOUBLE_OVERWIPED_ /*VDR_373*/

            rub_Empf_Faktor = rb_MaxOverwipeSensitivity_g;                      //set to maximum allowed at overwipe
#else /*VDR_373 SingleOverwiped by default*/
            rub_Empf_Faktor=rb_MaxOverwipeSensitivity_g;                      //set to maximum allowed at overwipe
#endif
            
          }
        }
      }
    }
#ifdef _ONETIME_OR_DOUBLE_OVERWIPED_ /*VDR_373*/
    else
    {/*VDR_373 low speed or high speed mode*/
      /*Is Sensitivity Faktor higher than the allowed?*/
      if (rub_Empf_Faktor > (rb_MaxOverwipeSensitivity_g+rb_OffsMaxOverwipeSensContWipSpd_g) ) 
      {
        if(rb_LastWiperMotorTime_g<rub_WiperMotorTime) /*overflow*/
        {
          rb_LastWiperMotorTime_g=rub_WiperMotorTime; /*Set rb_LastWiperMotorTime_g*/
        }
        /*reduce Sensitivity if more than 32% of Schwelle MaxTime*/
        if((((rb_LastWiperMotorTime_g-rub_WiperMotorTime)<(rb_LastWiperMotorTime_g>>1))    
            && (rb_WiperPosition_g != CB_INPARKPOSITION_S))&&
           ((rub_Int_Speicher < CB_INTSPEICHER_LONG_SENS_REDUCT)||
            (((rb_LastWiperMotorTime_g-rub_WiperMotorTime)<(rb_LastWiperMotorTime_g)))))
        {
          if (rbi_OneTimeOrDoubleOverwiped == TRUE)
          { /*VDR_373 DoubleOverwiped by CarConfiguration, Reduce rub_Empf_Faktor with EEPROM Value*/
            /*Check for overflow*/
            if ((rb_MaxOverwipeSensitivity_g+rb_OffsMaxOverwipeSensContWipSpd_g) > rb_Single_Or_Double_Overwipe_dec) 
            {
              rub_Empf_Faktor= (rb_MaxOverwipeSensitivity_g+rb_OffsMaxOverwipeSensContWipSpd_g) - rb_Single_Or_Double_Overwipe_dec; /*Decrease Empf_Faktor due to EEPROM*/
            }
            else
            {
              rub_Empf_Faktor = 1;                      /*Set to minimum*/
            }
          }
          else /*SingleOverwiped by CarConfiguration*/
          {
            /*Empty due to normal Operation*/
          }
        }
      }
    }
#endif
  }
  else
  {
    if ((rbi_RSWipeSlowDmd == 1)||(rbi_RSWipeFastDmd == 1))
    {
      if (((rub_WiperMotorTime < 5) && (rb_SchwelleInWipeLow_g))   // SEAT
          ||((rb_WiperPosition_g == CB_WENDELAGEOBENTOPARK_S)&& (!rb_SchwelleInWipeLow_g))) // AUDI
      {
        rub_Empf_Faktor -= (rub_Empf_Faktor>>2);  // Empf Faktor auf 75%
      }
      else
      {
        rub_Empf_Faktor += (rub_Empf_Faktor>>4)+1;  // Empf Faktor auf 112% + 1 offsett for low sensitivities better
      }
      
    }
    else
    {    /* interval mode*/
      
      if (rub_Empf_Faktor > rb_MaxOverwipeSensitivity_g)   /*Check if limitation is necessary*/
        
      {
        if (rb_SchwelleInWipeLow_g)           // SEAT?
        {
          rb_SEATAusblendTime_l = (rub_Int_Speicher < CB_INTSPEICHER_LONG_SENS_REDUCT)? 10:8;
          if (((rub_WiperMotorTime < rb_SEATAusblendTime_l)&&(rub_WiperMotorTime > 0))      // erstes Uberwischen
              ||((rub_IntermDelayTime > 0)&& (rub_IntermDelayTime < rb_SEATAusblendTime_l))) // zweites Uberwischen
          {
            
            rub_Empf_Faktor=rb_MaxOverwipeSensitivity_g;                      //set to maximum allowed at overwipe
            
          }
        }
        else                                  // AUDI
        {
          //reduce Sensitivity if more than 32% of Schwelle MaxTime
          if((((rub_Delay_Ausbl-rub_Delay_Ausbl_count)>(rub_Delay_Ausbl>>1))    
              && (rb_WiperPosition_g != CB_INPARKPOSITION_S))&&
             ((rub_Int_Speicher < CB_INTSPEICHER_LONG_SENS_REDUCT)||
              (((rub_Delay_Ausbl-rub_Delay_Ausbl_count)<(rub_Delay_Ausbl)))))
          {
            
#ifdef _ONETIME_OR_DOUBLE_OVERWIPED_ /*VDR_373*/

            rub_Empf_Faktor = rb_MaxOverwipeSensitivity_g;                      //set to maximum allowed at overwipe
#else /*SingleOverwiped by default*/
            rub_Empf_Faktor=rb_MaxOverwipeSensitivity_g;                      //set to maximum allowed at overwipe
#endif
            
          }
        }
      }
    }
  }
  if (( rub_WiperMotorTime > 0) &&(rbi_MeanPulsLengthOverwipeEmpfreduction_g))
  {
    if ((ruw_meanPulseLenght_g>>4)< 40)
    {
    }
    else
      if ((ruw_meanPulseLenght_g>>4)< 65)
      {
        rub_Empf_Faktor -= (rub_Empf_Faktor >> 2); //-25%
      }
      else
        if ((ruw_meanPulseLenght_g>>4)< 95)
        {
          rub_Empf_Faktor -= (rub_Empf_Faktor >> 1); //-50%
        }
        else
        {
          rub_Empf_Faktor -= (rub_Empf_Faktor >> 1) + (rub_Empf_Faktor >> 3); //-62%
        }
  }
  
}


