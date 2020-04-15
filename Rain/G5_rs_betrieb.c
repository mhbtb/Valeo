/******************************************************************************
*******************************************************************************
**
** Funktion:   Betrieb()
**
**
** Bearbeiter: Bernd Schmid Abt. TKW
** Datum:      14.04.98
** geaendert:  18.03.00
**
** Funktion:   Auswahl der Betriebsart
**             - Intervallbetrieb (inkl. Direktbetrieb)
**             - Dauerwischen Stufe 1
**             - Dauerwischen Stufe 2
** Function:   Choose of the Running Mode
**             - Interval (inkl. direkt mode)
**             - Continious low speed
**             - Continious high speed
**
*******************************************************************************
******************************************************************************/

#include "G5_rs_betrieb.h"   //include of header file
#include "G5_rainsens.h"
#include "G5_rs_task.h"
#include "G5_rainsens.h"

void Betrieb(void)
{
  static unsigned int  ruw_St2_Speicher_alt;
  unsigned char rub_Speicher_Temp;            //Def. temp. Variable
  //-Auswahl des momentan groesseren Speichers
  if(rub_Ovr_Speicher >= rub_Int_Speicher)  //Fast interval memory higher?
  {
    //-Auswahl Override Speicher
    rub_Speicher_Temp=rub_Ovr_Speicher;    //use fast interval Memory
  }
  else
  {
    //-Auswahl Intervall Speicher
    rub_Speicher_Temp=rub_Int_Speicher;    //use slow interval Memory
  }
  //-Betriebsart? Intervall / Dauerwischen
  //-Dauerwischen aktiv?
  if(rbi_RSWipeSlowDmd==1)                  //countious (slow) wiping active?
  {
    //-Dauerbetrieb aktiv
    /*Choosen memory higher than lower boarder for continous wiping?*/
    if ((rub_Speicher_Temp < CB_STUFE1_UG))
    {
      //-unterer Grenzwert unterschritten
      //-oder Anzahl der max. Trockenwischungen ueberschritten
      //-=> Umschalten auf Intervallbetrieb
      
      //-Stufe 1 abschalten, wenn
      //-Stufe 2 ausgeschaltet & Trockenwischungen detektiert sind
      /*no fast wiping?*/
      if ((rbi_RSWipeFastDmd == 0))
      {

          rbi_LowSpeed_Out_g = 1;
          rb_DoneAfterwipe_g = 1; // new wipe
          //- keine Trockenwischungen detektiert
          rub_Nachwisch_Count=CB_ST1_NACHWISCH_MIN;                               //set two afterwipes
          if (rub_WiperMotorTime == 0)
          {
            rub_Nachwisch_Count++;                               //set one additional afterwipe
          }
          if (rub_Speicher_Temp < CB_STUFE1_MIN_UG)            //memories are lower than min. threshold?
          {
            rub_Nachwisch_Count++;                           //reduce afterwipes
          }
          rbi_Tropfen_Merker=0;                            //clear flag for valid drops
          //                rbi_Tropfen_Merker=1;                                //set flag for valid drops
        
        //-Zaehler fuer Trockenwischungen rucksetzen
        rub_Trock_Wisch=0;                                       //reset counter for drywipes
        if (rub_Trockwisch_memory > 0)
        {
          rub_Trockwisch_memory --;
          rub_Trockwisch_memory -= (rub_Trockwisch_memory/10);
        }
        //-Stufe 1 abschalten
        rbi_RSWipeSlowDmd=0;                                     //switch lowspeed wiping off
        
        //-Schwellwert auf Startwert fuer Intervalbetrieb setzen
        
        if(rub_Int_Speicher>160)            //has interval memory high value
        {
          ruw_Schwelle=CW_SCHWELLE_05;                          //Set signal threshold to startvalue (wiping)
        }
        else if (rub_Int_Speicher>40)
        {
          ruw_Schwelle=CW_SCHWELLE_START;                          //Set signal threshold to startvalue (wiping)
        }
        else
        {
          ruw_Schwelle=CW_SCHWELLE_LONG_INT;
        }
        
      }
      
    }
  }
  else
  {
    
    //-Stufe 1 ausgeschaltet
    //-=====================
    
    //-Abfrage, ob oberer Grenzwert ueberschritten

      
      if ((rub_Ovr_Speicher > rb_Stufe1_OG_g)                //is fast interv. memory higher than low speed threshold?
          ||((rub_Ovr_Speicher > CB_STUFE1_WITH_INT_OG)//OR (fast interv. memory higher than a lowerlow speed threshold?
             && (rub_Int_Speicher > rb_Stufe1_OG_g)))       //AND slow interv. memory higher than low speed threshold?)
        

      {
        /*enough drops (packets)?*/
        if (((rub_Tropf_Anzahl>CB_TROPF_COUNT_MIN)
             /*AND enough signals(edges)?*/
             &&((rub_Sig_Anzahl>=CB_SIG_ANZAHL_MIN)||(rub_Sig_Counter >=CB_SIG_ANZAHL_MIN)))
            /*OR higher value of signals?*/
            ||(rub_Sig_Anzahl>=CB_SIG_ANZAHL_ST1_MIN)||(rub_Sig_Counter >=CB_SIG_ANZAHL_ST1_MIN))
          /*-falls zu spaet in stufe 1 ! ||(rub_Sig_Count>=CB_SIG_ANZAHL_MIN)oder andersherum fur rub_Tropf_Anzahl 
          verodern evtl auch selectiv auf int oder over speicher!!*/
        {
          byte rb_temp_IntermDelay_l;
          if (rb_Parametersatz_Regensensorik_g <= 1)
          {
            rb_temp_IntermDelay_l = cab_INTERMDELAY_2[0][0];
          }
          else
          {
            rb_temp_IntermDelay_l = cab_INTERMDELAY[0][0];
          }
          if ( (rub_WiperMotorTime > 0) || (rub_IntermDelayTime >= rb_temp_IntermDelay_l) )/*wiper motor running OR min.
                                                                                            time since last wipe? */
          {
            //-Stufe 1 einschalten, wenn noch nicht geschehen
            rbi_RSWipeSlowDmd=1; //switch into low speed
            
            if (ruw_Schwelle < CW_SCHWELLE_DAUER)       //signal threshold lower than cont.value(cont. wiping)?
            {
              ruw_Schwelle = CW_SCHWELLE_DAUER;        //Set signal threshold to cont.value (cont. wiping)
            }
            
          }
        }
      }
  }
  
  //-Auswahl der Betriebsart Dauerwischen Stufe1/Stufe2
  //-==================================================
  
  if (ruw_St2_Speicher >= (rw_St2_OG_g/5))
  {
    rb_SplashLSWipe_g |= 1;
  }
  else
  {
    rb_SplashLSWipe_g = 0x00;
  }
  
  
  if (ruw_St2_Speicher >= rw_St2_OG_g)
    
  {
    /*       if (rub_St2_Epr > CB_EP_ST2_EPR_LS_SPLASH)       //first Debouncing done?
    //-to debounce the fast possibility to go in Low speed
    {
    //-Override Speicher auf ug Wert setzen
    rbi_RSWipeSlowDmd=1;                        //switch to low speed
    if (rub_Ovr_Speicher<(CB_STUFE1_UG+5))          //is fast memory less than lower boarder for low speed wiping
    {
    rub_Ovr_Speicher=CB_STUFE1_UG+5; //set fast memory to lower boarder for low speed wiping 
                                       to give a chance to come out again!
  }
    
  }
    */
    if (ruw_St2_Speicher > ruw_St2_Speicher_alt)
    {
      //-Entprellregister hochzaehlen
      
      if (rub_St2_Epr < rb_Ep_St2_Epr_In_St2_g)      //Debouncing not complete?
        
      {
        
        
        if (ruw_St2_Speicher >= (rw_St2_OG_g+((rw_St2_OG_g>>4)+(rw_St2_OG_g>>3))))   //higer threshold -> shorter delay
        {
          rub_St2_Epr+=3;//5;                            //increment debounce counter
        }
        else if (ruw_St2_Speicher >= (rw_St2_OG_g+(rw_St2_OG_g>>3)))    //higer threshold -> shorter delay
        {
          rub_St2_Epr+=2;//3;                            //increment debounce counter
        }
        else if (ruw_St2_Speicher >= (rw_St2_OG_g+(rw_St2_OG_g>>4)))    //higer threshold -> shorter delay
        {
          rub_St2_Epr+=1;//2;                            //increment debounce counter
        }
        else
        {
          rub_St2_Epr++;                            //increment debounce counter
        }
        
      }
      else //-Entprellung erfolgt
      {
        
        if (rub_Sig_Pause<CB_SIGPAUSE_ST2_MAX)    //signal pause less than thresh.?
        {
          //-Override Speicher auf max. Wert setzen
          //-rub_Ovr_Speicher=CB_OVR_SPEICHER_MAX;
          
          //-Stufe 1 und 2 einschalten
          rbi_RSWipeSlowDmd=1;                  //switch to high speed
          rbi_RSWipeFastDmd=1;
          
          //-Minimale Anzahl der Wischzyklen In st2!
          rub_WischZykl_Count = CB_ST2_WISCH_MIN;   //set minim. count for high speed
        }
      }
    } //wert Grosser !
  }
  else if (ruw_St2_Speicher <= CB_ST2_UG)           //is high speed memory lower than go out thresh.?
  {
    if (rub_St2_Epr > CB_EP_ST2_EPR_OUT_ST2)        //debouncing not done?
    {
      rub_St2_Epr--;                               //decrease counter
    }
    else  //-Entprellung erfolgt
    {
      if (rub_WischZykl_Count==0)                  //all wipe cycles done?
      {
        rbi_RSWipeFastDmd=0;                     //switch high speed off
      }
    }
  }
  
  else if ( (ruw_St2_Speicher> CW_ST2_EPR_UG) && (ruw_St2_Speicher<rw_St2_OG_g))  //is high speed memory neutral area?
    
  {
    rub_St2_Epr=CB_EP_ST2_EPR_STARTVALUE;           //clear debouncing
  }
  else
  {
  }
  
  ruw_St2_Speicher_alt = ruw_St2_Speicher;    // alten Wert speichern
}

