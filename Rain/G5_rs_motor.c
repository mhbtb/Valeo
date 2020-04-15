/******************************************************************************
*******************************************************************************
**
**
** Datei:      Motor.c
**
** Bearbeiter: Bernd Schmid
**             Abt. TKW
**             ITT Automotive Europe GmbH
**
** Datum:      09.03.98
** geaendert:  23.09.98
**
** Funktion:   Motor()
**
**             Erkennung, ob der Motor ein- oder ausgeschaltet wurde
**
**             Intervallbetrieb:
**          =================
**          Motor wurde ausgeschaltet:
**             - Bestimmung der Motorlaufzeit
**          - Berechnung der Wartezeit fuer Ueberwischausblendung
**
**          Motor wurde eingeschaltet:
**          - Auswertung, ob vorhergehende Wischung eine Trockenwischung war
**          - Nachwischzaehler decrementieren
**             - Schwellwert fuer ueberwischausblendung auf Startwert setzen
**             - Merker fuer gueltigen Tropfen loeschen
**             - Tropfenzaehler loeschen
**             - Wert fuer Intervallspeicher max. Wert loeschen
**
**             Dauerbetrieb:
**          =============
**
**          tbd
**
*******************************************************************************
******************************************************************************/
/******************************************************************************/
/* History                                                                    */
/*----------------------------------------------------------------------------*/
/* Date      VDR_Number Initials    Description                                       */
/* DD.MM.YY */
/*----------------------------------------------------------------------------*/
/* Date      VDR_Number     Description                                       */
/*----------------------------------------------------------------------------*/
/* 15.11.10  VCO_084   AL  drywipe decrement on Ovr_Speicher and Int_Speicher
depending on sensitivity level*/
/* 25.Oct10   VCO_76     FS    Variables for Double Overwiper needed*/
/* 28.09.09	 VDR_375    AL 	 do not decrement memorys during Washing */
/* 16.10.08  VDR_276 FS  Implement Overwipe Offset*/
/* 01.04.15  VDR_866  MP    Remove of rainsens.c for no-rain-variants*/
/******************************************************************************/

#include "G5_rs_def.h"
#include "G5_rs_motor.h"  //Definition der Zustandswerte
#include "G5_rs_task.h"
#include "G5_rainsens.h"
#include "G5_rs_ext.h"
/*************************************************************************
**                   Declaration of global variables                    **
*************************************************************************/
#ifdef _ONETIME_OR_DOUBLE_OVERWIPED_
unsigned char rb_OffsetSigAnzahlDoubleOverwipe;
unsigned char rb_OffsetTropfAnzahlDoubleOverwipe;
extern unsigned char rub_RainSignalOverSchwelleCounter;
#endif

void Motor(void)
{
  //Funktionszustand detektieren
  //============================
  //wurde Motor abgeschaltet?
  //=========================
  if((rub_WiperMotorTime_alt > rub_WiperMotorTime)&& (rub_WiperMotorTime_alt >10))
  {
    //Motor wurde ausgeschaltet
    //=========================
    Mot_EinAus();
  }
  //wurde Motor eingeschaltet?
  //==========================
  if((rub_WiperMotorTime_alt==0)&&(rub_WiperMotorTime>0))
  {
    //Motor wurde eingeschaltet
    //=========================
    Mot_AusEin();
    rbi_LowSpeed_Out_g = 0;
  }
  //Wert fuer Motorlaufzeit sichern
  rub_WiperMotorTime_alt=rub_WiperMotorTime;
}
//Funktionszustand bearbeiten
//============================
//Einlaufen in die Parkposition
//=============================
void Mot_EinAus(void)
{
  //Wischermotor wurde Ausgeschaltet
  //Unterscheidung zwischen Intervall und Dauerwischen
  if(rbi_RSWipeSlowDmd == 0)
  {

    //Intervallbetrieb: Wischermotor wurde Ausgeschaltet
    //Wartezeit berechnen
    //Wartezeitausblendung aus 87% der Motorlaufzeit und der vorhergehenden
    rub_Delay_Ausbl=(rub_Delay_Ausbl >> 1)+(rub_Delay_Ausbl >> 3)+( (rub_WiperMotorTime_alt >> 3)*3); 
    /*rub_Delay_Ausbl=(rub_Delay_Ausbl >> 1)+(rub_Delay_Ausbl >> 3)+(rub_WiperMotorTime_alt >> 2)+
         (rub_WiperMotorTime_alt >> 4);      ////Wartezeitausblendung aus 82% der Motorlaufzeit und der vorhergehenden*/
  }
  else
  {
    //Dauerbetrieb => Einlauf in die Parkposition
    if(rub_WischZykl_Count > 0)
    {
      rub_WischZykl_Count--;
    }
  }
}
//Verlassen der Parkposition
//==========================


void Mot_AusEin(void)
{
  //Wischermotor wurde Eingeschaltet
  //#ifdef FORD /*VDR_375 remove unused code*/
  //	
  //        if(ruw_St1_Speicher > CB_WIPEDECREMENT_ST1)
  //	{
  //		ruw_St1_Speicher -= CB_WIPEDECREMENT_ST1;
  //	}
  //	else
  //	{
  //		ruw_St1_Speicher = 0;
  //	}
  //#endif
  if(ruw_StX_Speicher > CB_WIPEDECREMENT_STX)
  {
    if ((rbi_LowVoltage == 0)&&(rbi_WashingActive==0)) /*VDR_375 do only decrement if there is no washing*/
    {
      ruw_StX_Speicher -= CB_WIPEDECREMENT_STX;
    }
  }
  else
  {
    ruw_StX_Speicher = 0;
  }
  //Trockenwischungen detektieren
#ifdef _ONETIME_OR_DOUBLE_OVERWIPED_ /*VDR_276 OverWipeSignalAdaptation*/
    if( (rub_Tropf_Count > (CB_TROPF_COUNT_MIN + rb_OffsetTropfAnzahlDoubleOverwipe)) \
      || (rub_Sig_Counter > (CB_SIG_ANZAHL_MIN + rb_OffsetSigAnzahlDoubleOverwipe)) )
#else
     if( (rub_Tropf_Count > CB_TROPF_COUNT_MIN) || (rub_Sig_Counter>CB_SIG_ANZAHL_MIN) )
#endif
      {
        //keine Trockenwischung
        rub_Trock_Wisch = 0;
        if (rub_Trockwisch_memory > 0)
        {
          rub_Trockwisch_memory --;
          rub_Trockwisch_memory -= (rub_Trockwisch_memory/10);
        }
        
      }
     else
      {
        //Trockenwischungen nicht in Stufe 2 messen
        if(rbi_RSWipeFastDmd == 0)
        {
          if (rub_Trock_Wisch < 0xff)
          {
            if ((rbi_LowVoltage == 0)&&(rbi_WashingActive==0)) /*VDR_375 do only increment if there is no washing*/
            {
#ifdef _ONETIME_OR_DOUBLE_OVERWIPED_
              if ( (rbi_RSWipeSlowDmd == 1) && (rub_RainSignalOverSchwelleCounter>0) )
              {
                rub_Trock_Wisch = 0;
                if (rub_Trockwisch_memory > 0)
                {
                  rub_Trockwisch_memory --;
                }
                
              }
              else
              {
                rub_Trock_Wisch++;
              }
#else
              rub_Trock_Wisch++;
#endif
            }
          }
          /*VDR_375 do only decrement if there is no washing*/
          if ((rbi_SpeicherDecAtDryWipe_g)&&((rbi_LowVoltage == 0)&&(rbi_WashingActive==0))) 
          {
            if (ruw_StX_Speicher > 8000)
            {
              ruw_StX_Speicher -= 2000;
            }
            if (rub_Int_Speicher > 140)
            {
              /*VCO_084 drywipe decrement on Ovr_Speicher and Int_Speicher depending on sensitivity level*/
              if (rub_PotiStage < 3 ) 
              {  
                rub_Int_Speicher -= CB_INT_SPEICHER_DEC_AT_DRYWIPE_HIGH; // decrement due to drywipe
              }
              /*VCO_084 drywipe decrement on Ovr_Speicher and Int_Speicher depending on sensitivity level*/
              else if (rub_PotiStage < 4 ) 
              {  
                // decrement due to drywipe
                rub_Int_Speicher -= ((CB_INT_SPEICHER_DEC_AT_DRYWIPE_HIGH+CB_INT_SPEICHER_DEC_AT_DRYWIPE)/2); 
              }
              else  
              {  
                rub_Int_Speicher -= CB_INT_SPEICHER_DEC_AT_DRYWIPE; // decrement due to drywipe
              }
              
            }  
            if (  rub_Ovr_Speicher > 140)
            {
              /*VCO_084 drywipe decrement on Ovr_Speicher and Int_Speicher depending on sensitivity level*/
              if (rub_PotiStage < 3 ) 
              {  
                rub_Ovr_Speicher -= CB_OVR_SPEICHER_DEC_AT_DRYWIPE_HIGH; //decrement due to drywipe
              }
              /*VCO_084 drywipe decrement on Ovr_Speicher and Int_Speicher depending on sensitivity level*/
              else if (rub_PotiStage < 4 )  
              {  
                //decrement due to drywipe
                rub_Ovr_Speicher -= ((CB_OVR_SPEICHER_DEC_AT_DRYWIPE_HIGH+CB_OVR_SPEICHER_DEC_AT_DRYWIPE)/2) ;
              } 
              else 
              {  
                rub_Ovr_Speicher -= CB_OVR_SPEICHER_DEC_AT_DRYWIPE; //decrement due to drywipe
              } 
              
            }
            if (ruw_St2_Speicher > 3000)
            {
              ruw_St2_Speicher -= 300;
            }
          }
          if (rub_Trockwisch_memory < 45)
          {
            if ((rbi_LowVoltage == 0)&&(rbi_WashingActive==0))
            {
              rub_Trockwisch_memory += 1;
            }
          }
        }
      }
  //Merker fuer gueltigen Tropfen loeschen
  //      rbi_Tropfen_Merker=0;
  //max. Wert fuer Intervall/Override-Speicher loeschen
  rub_Speicher_max=0;
  //Anzahl der Signale fuer den vorhergehenden Wischzyklus bestimmen
  rub_Sig_Anzahl_Alt = rub_Sig_Anzahl;
  rub_Sig_Anzahl=rub_Sig_Counter;
  rub_Sig_Counter=0;
  //Anzahl der Tropfen fuer den vorhergehenden Wischzyklus bestimmen
  rub_Tropf_Anzahl=rub_Tropf_Count;
  rub_Tropf_Count=0;
  //Startwert fuer Ueberwischausblendung setzten
  rub_Delay_Ausbl_count=rub_Delay_Ausbl;
  //Variablen fuer Signalansammlungszeit ruecksetzen
  rbi_Sig_Ansammlung=0;
  rbi_Sig_Ansamml_Status=0;
  rub_Dec_SigSp_Ans_Count=0;
  
  //Unterscheidung zwischen Intervall und Dauerwischen
  if(rbi_RSWipeSlowDmd == 0)
  {
    //Wischermotor wurde Eingeschaltet Intervallbetrieb
    //Trockenwischungen auswerten
    if(rub_Trock_Wisch > CB_TROCK_WISCH_MAX_INT)
    {
      //kein Nachwischen, wenn Anzahl fuer max Trockenwischungen
      //ueberschritten wird
      rub_Nachwisch_Count=0;
    }
    //neue Wischung -> Nachwischzaehler decrementieren
    if(rub_Nachwisch_Count>0)
    {
      rub_Nachwisch_Count--;
      rb_DoneAfterwipe_g ++;
    }
    
    //Schwellwert auf Startwert setzen
    
    if(rbi_Tropfen_Merker == 1)
    {
      if(rub_Int_Speicher>160)            //has interval memory high value
      {
        ruw_Schwelle=CW_SCHWELLE_05;                          //Set signal threshold to startvalue (wiping)
      }
      else if (rub_Int_Speicher>40)
      {
        
        ruw_Schwelle=CW_SCHWELLE_START;
        
      }
      else
      {
        ruw_Schwelle=CW_SCHWELLE_LONG_INT;
      }
    }
  }
  else
  {
    // Dauerbetrieb => Verlassen der Parkposition
    // Wischermotor wurde Ausgeschaltet Dauerbetrieb
    // tbd
  }
  
  rbi_Tropfen_Merker=0;   //Merker fuer gueltigen Tropfen loeschen
#ifdef _ONETIME_OR_DOUBLE_OVERWIPED_
  rub_RainSignalOverSchwelleCounter =0;
#endif
}







