/******************************************************************************
*******************************************************************************
**
** Funktion:   THold()
**
**
** Bearbeiter: Bernd Schmid
**             Abt. TKW
**             ITT Automotive Europe GmbH
**
** Datum:      09.03.98
** geaendert:  23.09.98
**
** Funktion:   Berechnung der Schwelle fuer die Ueberwischausblendung
**
** Beschreibung:
** Im Intervallbetrieb wird nach Ablauf einer Delayzeit nach dem Motorstart
** die Schwelle der Ueberwischausblendung verringert.
** Die Schwelle wird bis auf ihren min_Wert verringert.
** Im Dauerbetrieb bleibt der Wert konstant.
** Bei aktivierter Waschfunktion wird die Schwelle nicht verringert.
**
**
*******************************************************************************
******************************************************************************/
/* History                                                                    */
/*----------------------------------------------------------------------------*/
/* Date      VDR_Number     Description                                       */
/*----------------------------------------------------------------------------*/
/* 15.11.10  VCO_598        reduced threshold in below 70km/h*/
/* 04.Oct.10 VCO_76         FS Variable renamed*/
/* 2.Jul.10  VDR_540        Butterfly Option implemented*/
/* 27.11.08  VDR_296        Porsche: The Rainsensor should be more sensitive in different conditions*/
/* 16.02.15  VDR_845        In interval, less sensitive if vehicle is not driving if first wipe was performend*/
/* 01.04.15  VDR_866  MP    Remove of rainsens.c for no-rain-variants*/
/******************************************************************************/
#include "G5_rs_def.h"
#include "G5_rs_thold.h"
#include "G5_ASIC_Control_sr.h"
#include "G5_IRlight.h"
#include "G5_rs_task.h"
#include "G5_rainsens.h"
#include "G5_rs_ext.h"
#include "G5_rls_linst.h"

#define cb_UpperBoarderNoWipeTime_s 45000          //Upper Boarder for NoWipeTime to caluclate RS Threshold
#define cb_SpeedtoHalfThreshold_s   10             //Upper Boarder to half the RS Threhold

void THold(void)
{
  //Variable Declaration
  static unsigned short int rw_nowipetimer_s;            //-Time with no Wipe to adapt the RS-Threshold
  unsigned char rb_speedLimit_in_kmh_l;                  //-local Speed Variable to adapt the Threshold
  unsigned short int rw_sig_ans_schw_offs_l;             //-offset at collection mode
  static word ruw_Schwelle_min_l;
  
  
  //- Schwelle nur verringern, wenn Waschen nicht aktiv!
  if(rbi_WashingActive==0)                               //is Washing not active?
  {
    if (rb_AfterWashingTimer_mg < 255) // kleiner 10,2 sekunden!
    {
      rb_AfterWashingTimer_mg ++;
    }
    //- Unterscheidung zwischen Intervall und Dauerwischen
    if((rbi_RSWipeSlowDmd==0)|| (rbi_AlwaysIntervalThrs_g))                          //is Wiper not in Countinous slow
    {
      //-Intervallbetrieb
      //-================
      //-Abfrage, ob Wartezeit abgelaufen?
      if((rub_Delay_Ausbl_count==0)&&(rbi_WiperStarted_g == 0))              //is Delaytime over or SEAT Wiper Started
        
      {
        //-Schwellen Geschwindigkeitsabhangig
        rb_speedLimit_in_kmh_l=(rb_speed_in_kmh_g>140)? 140:rb_speed_in_kmh_g;//Calculate Speed for threshold adaptation
        ruw_Schwelle_min_l=(ruw_Schwelle_min+((((ruw_Schwelle_min)*rb_speedLimit_in_kmh_l))/24))>>2;
        //Threshold =Threhsold*(1+Speed/64)/2
        //-rw_sig_ans_schw_offs_l=(CW_SIG_ANS_SCHW_OFFS>>1)+((((CW_SIG_ANS_SCHW_OFFS>>2)*((unsigned short int)(rb_speedLimit_in_kmh_l))))>>5);  //Schwelle =Schwelle*(1+Speed/64)/2
        
        if(rub_WiperMotorTime>0)      //Wiper Running
        {
          rw_nowipetimer_s=0;        //Reset Time with no Wipe
        }
        else
        {
          if(rw_nowipetimer_s < cb_UpperBoarderNoWipeTime_s)  //is No Wipe time At upper Boarder
          {
            rw_nowipetimer_s += (2+(rb_IrLightDiv8_g>>5));   //counts faster the threshold high for high ambient light
          }
        }
        
        if ((rbi_Night == FALSE)&&(rub_PotiStage < 2))
        {
          rw_sig_ans_schw_offs_l = ((word)(rb_CW_AnsamlungAdditOffsett_g)+(word)(CW_SIG_ANS_SCHW_OFFS));
        }
        else
        {
          rw_sig_ans_schw_offs_l = ((word)(rb_CW_AnsamlungAdditOffsett_g)+(word)(CW_SIG_ANS_SCHW_OFFS))-CB_OFFSETT_ADDIT_NOM;
          if ((rbi_Night == TRUE) && (rub_PotiStage > 1))
          {
            rw_sig_ans_schw_offs_l = (rw_sig_ans_schw_offs_l>>1);
          }
        }
        //Calculate Threshold with NoWipeTimeInformation
        rw_sig_ans_schw_offs_l=(rw_sig_ans_schw_offs_l)+(((rw_sig_ans_schw_offs_l>>4)*(rw_nowipetimer_s>>5) )>>6); 
        if ((rbi_Night == TRUE)&&(rb_speedLimit_in_kmh_l < (cb_SpeedtoHalfThreshold_s*3)))
        {
          rw_sig_ans_schw_offs_l = CW_SIG_ANS_SCHW_OFFS>>3;          //reduce the Collection Threshold Offset
        }
        
        if(rb_speedLimit_in_kmh_l < cb_SpeedtoHalfThreshold_s)//is speed lower then Boarder to Half the min RS-Threshold
        {
          //  ruw_Schwelle_min = ruw_Schwelle_min>>1;                  //Half the min RS-Threshold
          rw_sig_ans_schw_offs_l = (CW_SIG_ANS_SCHW_OFFS>>4)+10;       //VDR_296 reduce the Collection Threshold Offset
        }
        //is speed lower then Boarder to 3/4 the min RS-Threshold
        else if (rb_speedLimit_in_kmh_l < (cb_SpeedtoHalfThreshold_s*2))      
        {
          //ruw_Schwelle_min -= ruw_Schwelle_min>>2;                  //reduce the min RS-Threshold
          rw_sig_ans_schw_offs_l = (rw_sig_ans_schw_offs_l>>3)+10;     //VDR_296 reduce the Collection Threshold Offset
        }
        //is speed lower then Boarder to 3/4 the min RS-Threshold
        else if (rb_speedLimit_in_kmh_l < (cb_SpeedtoHalfThreshold_s*3))      
        {
          //ruw_Schwelle_min -= ruw_Schwelle_min>>2;                  //reduce the min RS-Threshold
          rw_sig_ans_schw_offs_l = (rw_sig_ans_schw_offs_l >>2);      //VDR_296 reduce the Collection Threshold Offset
        }
        else if  (rb_speedLimit_in_kmh_l < 50)        //empfindlicher unter 50
        {
          rw_sig_ans_schw_offs_l -= rw_sig_ans_schw_offs_l>>3;      //reduce the Collection Threshold Offset
        }
        else if  (rb_speedLimit_in_kmh_l < 70)        //empfindlicher unter 50  -> VCO_598
        {
          rw_sig_ans_schw_offs_l -= rw_sig_ans_schw_offs_l>>3;      //reduce the Collection Threshold Offset
        }
        else if (rb_speedLimit_in_kmh_l > 100)
        {
          rw_sig_ans_schw_offs_l += rw_sig_ans_schw_offs_l>>2;      //increase the Collection Threshold Offset
        }
        else if (rb_speedLimit_in_kmh_l > 75)
        {
          //increase the Collection Threshold Offset
          rw_sig_ans_schw_offs_l += (rw_sig_ans_schw_offs_l>>3)+(rw_sig_ans_schw_offs_l>>4);    
        }
        else
        {
          /* For MISRA check */
        }
        //-Schwelle wird um den Wert "c_Dec_Schwelle" verringert
#ifdef _ONETIME_OR_DOUBLE_OVERWIPED_ /*VDR_373*/
        //RS-Threhold Higher than min Value (after Overwipe
        if(ruw_Schwelle > (ruw_Schwelle_min + EEPROM_OverwipeThres_FadeOut_StandardWiper) )   
        {
          if ( (rb_SchwelleInWipeLow_g > 0) || (rbi_ButterflyIsEquipped>0) )
          { /*Do not care if one time or double overwiped*/
            ruw_Schwelle -= (((word)EEPROM_OverwipeThres_FadeOut_Butterfly * 3)>>2); /*reduce Threshold -->60*/
          }
          else
          {
            ruw_Schwelle -= EEPROM_OverwipeThres_FadeOut_StandardWiper;                         //reduce Threshold
          }
#else
        if(ruw_Schwelle > (ruw_Schwelle_min_l + CB_DEC_SCHWELLE))  //RS-Threhold Higher than min Value (after Overwipe
        {
          if (rb_SchwelleInWipeLow_g > 0)
          {
            ruw_Schwelle -= (((word)CB_DEC_SCHWELLE * 3)>>2); /*reduce Threshold -->75*/
          }
          else
          {
            ruw_Schwelle -= CB_DEC_SCHWELLE;                         //reduce Threshold
          }
#endif
        }
        else
        {
          //-Schwelle auf min. Wert setzen
          
          ruw_Schwelle = ruw_Schwelle_min_l;                         //set to min RS-Threshold
        }
        //-Ist auf Ansammlung umgeschalt?
        if(rbi_Sig_Ansammlung == 1)                                   //Collection Mode ?
        {
          //Threshold lower then min RS-Threhold + collection Offset
          if(ruw_Schwelle < (ruw_Schwelle_min_l + rw_sig_ans_schw_offs_l)) 
          {
            //-Bei eingeschaltetem Ansammlungsbetrieb wird der
            //-untere Schwellwert erhoeht
            //Set RS-Threshold to min RS-Threhold + Collection Offset
            ruw_Schwelle=ruw_Schwelle_min_l+rw_sig_ans_schw_offs_l;        
          }
        }
        /*VDR_845 In interval, less sensitive if vehicle is not driving if first wipe was performend*/
        else if ((TRUE == rbi_Tropfen_Merker) && (ruw_Schwelle < (ruw_Schwelle_min+((((ruw_Schwelle_min)*10))/3))>>2))
        {
          ruw_Schwelle = (ruw_Schwelle_min+((((ruw_Schwelle_min)*10))/3))>>2;
        }
        else
        {
          /*set to min RS-Threshold*/
          ruw_Schwelle_min = ruw_Schwelle_min_l;
        }
        
      }
      else   //-Wartezeit nicht abgelaufen?
      {
        //-Thold muss im Zeitraster von 40ms aufgerufen werden
        if ((rub_Delay_Ausbl_count > 0)&&((rub_WiperMotorTime>0)||(rbi_WiperStarted_g == 0)))
        { rub_Delay_Ausbl_count--;} //Reduce Delay Time
        
        //- Bei Nachwischungen die Schwelle Spaeter und mit Flanke hochsetzen
        
#ifdef _ONETIME_OR_DOUBLE_OVERWIPED_ /*VDR_373*/
          if( ( //reduce Sensitivity if more than 32% of Schwelle MaxTime
               (rb_SchwelleInWipeLow_g)&&(((rub_Delay_Ausbl-rub_Delay_Ausbl_count)>(rub_Delay_Ausbl>>1))   
                                          && ((rub_Delay_Ausbl-rub_Delay_Ausbl_count)<(rub_Delay_Ausbl)))
                 )
             ||(//reduce Sensitivity if more than 32% of Schwelle MaxTime
                (((rub_Delay_Ausbl-rub_Delay_Ausbl_count)>(rub_Delay_Ausbl>>1))    
                 && ((rub_Delay_Ausbl-rub_Delay_Ausbl_count)<(rub_Delay_Ausbl)))
                  &&(rbi_ButterflyIsEquipped>0)&&(rbi_DoubleOverwiped<1) /*One TIme overwiped, Butterfly*/
                    ) )//and less than 75% of Schwelle MaxTime
          {
            if(rbi_ButterflyIsEquipped>0)
            {
              ruw_Schwelle -= (((word)EEPROM_OverwipeThres_FadeOut_Butterfly * 3)>>2);        //reduce Threshold
            }
            else
            {
              ruw_Schwelle -= EEPROM_OverwipeThres_FadeOut_StandardWiper;                    //reduce Threshold
            }
#else
        //reduce Sensitivity if more than 32% of Schwelle MaxTime
        if ((rb_SchwelleInWipeLow_g)&&(((rub_Delay_Ausbl-rub_Delay_Ausbl_count)>(rub_Delay_Ausbl>>1))    
                                       && ((rub_Delay_Ausbl-rub_Delay_Ausbl_count)<(rub_Delay_Ausbl)))) //and less than 75% of Schwelle MaxTime
        {
          ruw_Schwelle -= CB_DEC_SCHWELLE;                         //reduce Threshold
#endif
        }
        else
          if ((rbi_Tropfen_Merker == 1)||(ruw_Schwelle > CW_SCHWELLE_05)||(rb_AfterWashingTimer_mg < 100))
          {
            if (rub_Int_Speicher>40)
            {
              ruw_Schwelle=CW_SCHWELLE_START;                          //Set signal threshold to startvalue (wiping)
            }
            else
            {
              ruw_Schwelle=CW_SCHWELLE_LONG_INT;
            }
          }
        //Threshold near Overwipe Value
          else if((ruw_Schwelle>(CW_SCHWELLE_05-CW_INC_SCHWELLE)||(rb_WiperAPillarParkposition_E2_g))) 
          {
            ruw_Schwelle=CW_SCHWELLE_05;              //Set Threshold to Overwipe Value
          }
        
          else
            if((((rub_Delay_Ausbl>>3)*rb_TimeForAfterwipeThrs_DelayScal_g)>>2) < (rub_Delay_Ausbl-rub_Delay_Ausbl_count)) //Delay to increment Threshold reached
            {
              ruw_Schwelle += CW_INC_SCHWELLE;                               //Increase Threshold for Afterwipes
            }
            else
            {            //for MISRA
            }
      }
    }
    else
    {
      //-Dauerbetrieb
      //-============
      
      ruw_Schwelle=CW_SCHWELLE_DAUER;     //Set Threshold to Contious Value
    }
  }
  else
  {
    rb_AfterWashingTimer_mg = 0;                       // Timer nach dem Waschen zuruecksetzten
    ruw_Schwelle=CW_SCHWELLE_START;                    // Schwelle Start waehrend dem Waschen!
  }
  
}





