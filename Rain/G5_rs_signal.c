/******************************************************************************
*******************************************************************************
**
** Funktion:   Signal()
**
**
** Bearbeiter: Bernd Schmid
**             Abt. TKW
**             ITT Automotive Europe GmbH
**
** Datum:      09.03.98
** geaendert:  23.09.98
**
** Funktion:   1. Berechnung der Signallaenge und Signalanzahl aus den
**                durchlaufenden Zaehlern
**
*******************************************************************************
******************************************************************************/
/*----------------------------------------------------------------------------*/
/* Date      VDR_Number     Description                                       */
/*----------------------------------------------------------------------------*/
/* 15.11.10  VCO_085    AL   implement adjustable factor for Stx. Memory sensitivity*/ 
/* 25.Oct10  VCO_76     FS   Double Overwiped Sensor: Variable added*/
/* 01.Jul.10 VDR_540    FS   Integrate Butterfly Adaptation for WiperPosition*/
/* 03.05.10  VDR_511    AL   Polyspace workaround*/
/* 18.03.10  VDR_428    AL   correct comibination of washing and undervoltage*/
/* 28.09.09  VDR_375    AL   do not decrement memorys during Washing */
/* 29.01.15  VDR_838    MP   Wrong brakets after qac fix*/
/*
Vorgehensweise bei der Signalauswertung:
========================================

Vom Steuergeraet werden folgende Variablen zur Verfuegung gestellt:

- rub_LengthCounter: Durchlaufender Zaehler (0-255), welcher bei Signalen
die groesser 1ms sind hochgezaehlt wird.
Signale <= 1ms werden nicht gezaehlt.

- rub_PulseCounter:  Durchlaufender Zaehler (0-255), welcher bei jedem
Flankenwechsel von High auf Low (inaktiv auf aktiv)
um eins erhoeht wird.


Diese Variablen muessen vor dem  ersten Task-Aufruf initialisiert sein!




Vorgehensweise:
1. Jeweils fuer Impulszaehler und Laengenzaehler die Differenz aus dem aktuellen
und dem vorhergehenden Wert bilden.

rub_SigLength:    Differenz aus alter und neuer Signallaenge;
rub_SigPulse:     Differenz aus alter und neuer Pulzahl;


2. Werte aufarbeiten:

rub_SigLength = 0 -> kein Signal > 1 ms vorhanden
-> Speicher verringern


rub_SigLength > 0 -> Signal > 1 ms vorhanden
-> Speicher in Abhaenigkeit von der Signallaenge
und der eingestellten Empfindlichkeit erhoehen



rub_SigPulse = 0  -> keine Zustandsaenderung
-> kein Signal oder Signaluebertrag aus vorhergehendem Task

rub_SigLength > 0 -> Signaluebertrag
-> Speicher erhoehen

rub_SigLength = 0 -> kein Signal
-> Speicher verringern

rub_SigPulse > 0  -> neue(s) Signal(e)

3. Signalspeicher laden bzw entladen:


4. Abfrage, ob Signal gueltig:
Signal ist dann gueltig, wenn der Wert des Signalspeichers groesser als der Wert
der Schwelle der Ueberwischausblendung ist.


Bei gueltigem Signal wird der Zaehler fuer gueltige Signale erhoeht
("rub_Sig_Ok_Count").
Diese Variable wird im 10 ms Task geschrieben und im 40ms Task ausgewertet.
Nach der Auswertung wird die Variable geloescht.
********************************************************************************/
/* History                                                                    */
/*----------------------------------------------------------------------------*/
/* Date      VDR_Number   Name   Description                                       */
/*----------------------------------------------------------------------------*/
/* 25.01.08  VDR_126      AL     Load Stufe  Memory slower */
/* 05.02.08  VDR_132      AL     improved rain sensor error detection implement timer after fastloop*/
/******************************************************************************/
/*Check in for RLFSs*/
/******************************************************************************/

#include "G5_rs_def.h"
#include "G5_rs_signal.h"
#include "G5_rainsens.h"
#include "G5_ASIC_Control.h"
#include "G5_ASIC_Control_sr.h"
#include "G5_rs_task.h"
#include "G5_rls_linst.h"
#include "G5_E2ProjectConfig.h"
#include "G5_rs_empf.h"
//Modulglobale Variablen
//======================
//Declared Variables in this
unsigned short int ruw_SigLength_fakt;
unsigned int rw_SingleDropProtectCount_g;
/* VDR_511 unsigned short int ruw_Temp_l; use local variables*/
unsigned short int ruw_CntSigLength_DownWipe_mg; //Variable zur Speicherung der Signale beim Runterwischen
unsigned short int ruw_CntSigLength_UpWipe_mg;   //Variable zur Speicherung der Signale beim Hochwischen

static unsigned int ruw_SigLength_fakt_stufeX; /*VDR_127 new signal*/



/** Rain intensity VCO_423 */  
#ifdef RAIN_INTENSITY
word rw_RS_SigVoltage_neg_int_g;
word rw_Interval_g;
static word rw_old_1msTimer_g; 
word rb_overWipeCoef;
/* Output value on LIN*/
word cb_RainInt_TransformArray_g[13] = {417,297,226,176, 79, 17, 15, 13, 11,   9,  7,  5,  2};
byte rb_RainInt_IntensityOutput_g = 0; //init value is 14 according to DOORS VW req

#endif


#ifdef _ONETIME_OR_DOUBLE_OVERWIPED_
unsigned char rub_RainSignalOverSchwelleCounter;
#endif


//Functions
static void signal_main(void);
static void signal_decrease(void);
static void signal_valid(void);
static void signal_low(void);
static void signal_limit(void);
static void signal_decreaseSP2(void);
#ifdef RAIN_INTENSITY
static void signal_time_interval(void);
#endif


void Signal(void)
{
  unsigned char rub_Temp_l;
  unsigned short int ruw_TempSignal_l;
  //Signallaenge, waehrend des letzten Tasks
  //========================================
  //Variable sichern, (Schutz vor Interrupt)
  rub_Temp_l = rub_LengthCounter;
  //Signalanderung?
  
  if(rub_Temp_l != rub_LengthCounter_alt)
  {
    //Signalaenderung bestimmen
    if(rub_Temp_l > rub_LengthCounter_alt)
    {
      rub_SigLength = rub_Temp_l - rub_LengthCounter_alt;
    }
    else
    {
      rub_LengthCounterHB ++; /*VCO_108*/
      /*VDR Wrong brakets after qac fix*/
      rub_SigLength = ((255 - rub_LengthCounter_alt) + rub_Temp_l) + 1;
    }
    //Empfindlichkeitsfaktor berucksichtigen
    // 27112001 In Abhangigkeit vom Intervall_Speicher
    // erneute Aktivierung am 30.01.02 von Al damit stufe 1 etwas spater kommt
    ruw_SigLength_fakt = rub_SigLength*rub_Empf_Faktor;
    /*VDR_127 reduce sensitivity for max values*/
    ruw_SigLength_fakt_stufeX = rub_SigLength*((1+rub_Empf_Faktor)-(rub_Empf_Faktor>>2)); 
    //aktuellen Wert sichern
    rub_LengthCounter_alt=rub_Temp_l;
  }
  else
  {
    //kein Signal
    rub_SigLength=0;
    ruw_SigLength_fakt=0;
    ruw_SigLength_fakt_stufeX = 0; /*VDR_127 clear signal*/
  }
  
  // Berechnung der Pulse Lange wahrend der Aufwartswischung und der Abwartswischung
  // Speicherung der lange in den Variablen
  if (rb_WiperPosition_g == CB_PARKTOWENDELAGEOBEN_S)
  {
    ruw_CntSigLength_UpWipe_mg +=rub_SigLength;
  }
#ifdef _ONETIME_OR_DOUBLE_OVERWIPED_ /*VDR_540*/
  else if (
           ((rb_WiperPosition_g == CB_WENDELAGEOBENTOPARK_S)
            &&(rbi_ButterflyIsEquipped<1) ) /*Normal Wiper*/
             || ( ((rb_WiperPosition_g == CB_WENDELAGEOBENTOPARK_S)
                   /*NEEDED, ParkPosition and WiperMotorTime not synchronized!*/
                   ||((rub_WiperMotorTime>Threshold_SecondOverwipe_Start) 
                      ||(AfterWiperMotorTime_counter<Threshold_AfterWiperMotorTime)))
                 &&(rbi_ButterflyIsEquipped>0)) /*Butterfly, do not care about one time or two times overwiped*/
               )
#else
  else if (rb_WiperPosition_g == CB_WENDELAGEOBENTOPARK_S)
#endif
  {
    ruw_CntSigLength_DownWipe_mg +=rub_SigLength;
  }
  else if((ruw_CntSigLength_UpWipe_mg > 0)||(ruw_CntSigLength_DownWipe_mg > 0))
  {
    ruw_SigLength_DownWipe_g = ruw_CntSigLength_DownWipe_mg ;
    ruw_SigLength_UpWipe_g = ruw_CntSigLength_UpWipe_mg;
    
    ruw_TempSignal_l=(8*ruw_SigLength_DownWipe_g) / (ruw_SigLength_UpWipe_g+5);
    if (ruw_TempSignal_l < 255)        // berechung des Verhaltinisses runter zu hochWischen
    {
      rb_Sig_DownWipe_to_upWipe_g = (byte)(ruw_TempSignal_l);
    }
    else
    {
      rb_Sig_DownWipe_to_upWipe_g = 255;
    }
    ruw_CntSigLength_DownWipe_mg = 0;
    ruw_CntSigLength_UpWipe_mg = 0;
  }
  else
  {
    /* MISRA check */
  }
  
  
  
  
  //Anzahl der Signale, waehrend des letzten Tasks
  //==============================================
  //Variable sichern, (Schutz vor Interrupt)
  rub_Temp_l = rub_PulseCounter;
  if(rub_Temp_l != rub_PulseCounter_alt)
  {
    //neuer Puls
    if(rub_Temp_l > rub_PulseCounter_alt)
    {
      rub_SigPulse = rub_Temp_l - rub_PulseCounter_alt;
    }
    else
    {
      /*VDR Wrong brakets after qac fix*/
      rub_SigPulse = ((255 - rub_PulseCounter_alt) + rub_Temp_l) + 1;
    }
    //Wert sichern
    rub_PulseCounter_alt=rub_Temp_l;
  }
  else
  {
    //kein neuer Puls
    rub_SigPulse=0;
    // Versuch uber Regenstatistik
    if (ruw_PulseLength_g < 245)
    {
      ruw_PulseLength_g += rub_SigLength ;
    }
  }
  //During low voltage reset signal-memory
  //=======================================
  if((rbi_LowVoltage==1)||(rbi_WashingActive==1)) /*VDR_428 correct comibination of washing and undervoltage*/
  {
    rub_SigPulse=0;
    rub_SigLength=0;
    ruw_SigLength_fakt=0;
    ruw_SigLength_fakt_stufeX = 0; /*VDR_428 */
    // improvment Start Stop    ruw_Signal=0;
    // improvment Start Stop      rub_SignalIntegral_g =0;
    //Test!
  }
  
  //External function 2007February21
  signal_main();
  
  // External function: Load Speed 2 memory
  signal_decreaseSP2();
  
  // Limit Signalmemory
  signal_limit();
  
  // External function 2007February21
  signal_decrease();
  
  // Signal is valid?
  signal_valid();
  
  // Signal is continuously low?
  signal_low();
  
  // Doppelt in code weil es vor dem laden und nach dem entladen gepruft werden sollte
  //Soll auf Ansammlung umgeschaltet werden?
  //========================================
  if(rbi_Sig_Ansamml_Status==0)
  {
    if(rbi_Sig_Ansammlung==0)
    {
      //Es wird auf Ansammlungsbetrieb umgeschaltet,
      //wenn die Schwelle den Wert "ruw_Schwelle_min" hat
      //und der Signalspeicher das erste mal leer ist.
      if((ruw_Schwelle<=ruw_Schwelle_min) && ((ruw_Signal+ruw_SigInt)==0))
      {
        rbi_Sig_Ansammlung=1;
        rbi_Sig_Ansamml_Status=1;
      }
    }
  }
}


/*Auslagerung fur rs_signal.c --> Metrik STPTH */

static void signal_main(void)
{
  unsigned short int ruw_MaxSiglenth_l;
  unsigned short int ruw_Temp_SigMain_l;
  
#ifdef RAIN_INTENSITY
  /** Rain intensity VCO_423 */  
  word rw_Thr_SigVoltage_l = (word)(((((word)rb_RS_Intensity_SigVoltageH_g)<<8)) + rb_RS_Intensity_SigVoltageL_g);
  word rw_idle_interval_l;
#endif
  
  //Signalspeicher laden, falls erforderlich!
  //========================================
  // Der Signalspeicher wird nur bei nicht betaetigter Waschfunktion und
  // aktiver Regensensor Funktion geladen!
  if((rbi_RainSensorEnable==1))
  {
    if (rub_SignalIntegral_g <240)
    {
      rub_SignalIntegral_g += rub_SigLength;
    }
    
#ifdef RAIN_INTENSITY
    /** Rain intensity VCO_423 */  
    /* calculate the idle interval from 1ms timer */
    if (rw_1msTimer_g > rw_old_1msTimer_g)
    {
      rw_idle_interval_l = rw_1msTimer_g - rw_old_1msTimer_g;
    }
    else
    {
      rw_idle_interval_l = rw_1msTimer_g + (0xFFFF - rw_old_1msTimer_g);
    }
    
    /* Re-initialise array element if there is no rain */
    /* trigger the proceed if reach the timeout */    
    if ((rw_idle_interval_l/1000) > rb_Intensity_Thr_IdleTime_g) 
    {
      signal_time_interval();
      rw_old_1msTimer_g = rw_1msTimer_g;
      rw_RS_SigVoltage_neg_int_g = 0; 
    }
#endif
          
          
    //Abfrage, ob neues Signal (Zustandsaenderung)?
    if(rub_SigPulse==0)
    {
      //keine Zustandsaenderung!
      //========================
      if(rub_SigLength==0)
      {
        //kein Signal vorhanden
        //-> Zaehler fuer Signalpause incrementieren
        //   (Faktor 10ms)
        if(rub_Sig_Pause<(unsigned char)(255))
        {
          rub_Sig_Pause++;
        }
      }
      else // Siglenght > 0 Sigpulse == 0
      {
        //-> Wert gehoert zum Signal aus vorhergehendem Taskaufruf
        //-> Signallaenge aufintegrieren.
        if (rub_IntermDelayTime > 25 )
        {
          ruw_MaxSiglenth_l=CW_MAX_SIGNALLAENGE + (CW_MAX_SIGNALLAENGE>>1);
        }
        else
        {
          ruw_MaxSiglenth_l=CW_MAX_SIGNALLAENGE;
        }
        if((ruw_Signal+ruw_SigLength_fakt) < (unsigned int)(ruw_MaxSiglenth_l*rub_Empf_Faktor))
        {
          ruw_Signal += ruw_SigLength_fakt;
        }
        else
        {
          ruw_Signal = ruw_MaxSiglenth_l*rub_Empf_Faktor;
        }
        
        if ( ruw_presentPulseLenght_g < (2000))
        {
          ruw_presentPulseLenght_g += rub_SigLength;
        }
        
      }
    }
    else
    {
      
      ruw_meanPulseLenght_g =  ruw_meanPulseLenght_g - ((ruw_meanPulseLenght_g >> 4) + (ruw_presentPulseLenght_g));
      ruw_presentPulseLenght_g = 0;
      //Zustandsaenderung ( rub_SigPulse <> 0 ) !
      //=========================================
      //neues Signal vorhanden
      //**********************
      //Signale zaehlen
      if(rub_Sig_Counter<(unsigned char)255)
      {
        rub_Sig_Counter++;
      }
      //Flag fuer max. Signallaenge Stufe2 ueberschritten loeschen
      rbi_SigSt2_max=0;
      //Tropfen zaehlen
      if(rub_Sig_Pause > CB_SIG_COUNT_PAUSE_MIN)
      {
        //minimale Signalpause uberschritten
        if(rub_Tropf_Count<(unsigned char)255)
        {
          rub_Tropf_Count++;
        }
      }
      //neues Signal > 0 vorhanden
      //**************************
      //aktuellen Signalwert zum aufintegrierten Signal hinzuaddieren
      //Signalspeicher
      //min. Signallaenge erreicht?
#ifdef __SIGMIN
      if(rbi_Signal_min_Ok==1)
#endif
      {
        //letztes Signal nur zum Gesamt Signalspeicher addieren,
        //wenn Signal>Signal_min.
        
        if((ruw_SigInt+ruw_Signal) <= CW_MAX_SIGSP_FAKT)
        {
          ruw_SigInt += ruw_Signal;
        }
        else
        {
          ruw_SigInt = CW_MAX_SIGSP_FAKT;
        }
#ifdef RAIN_INTENSITY
        /** Rain intensity VCO_423: increasing of signal voltage until we reach the thresold */

        if((rw_RS_SigVoltage_neg_int_g+rb_RS_SigVoltage_abs_g*rb_overWipeCoef/100.0) <= rw_Thr_SigVoltage_l)
        {
          rw_RS_SigVoltage_neg_int_g += rb_RS_SigVoltage_abs_g*rb_overWipeCoef/100.0;                
        }
        else
        {
          signal_time_interval();
          rw_RS_SigVoltage_neg_int_g = 0;
        }  
#endif 
        
#ifdef __SIGMIN
        if(rub_Sig_Pause>CB_SHORT_SIG_PAUSE)
        {
          rbi_Signal_min_Ok=0;
        }
#endif
        //Wert fuer aktuelles Signal aus aktuellem Task ermitteln
        ruw_Signal=ruw_SigLength_fakt;
      }
      rub_Sig_Pause=0;
    }
    //wurde min. Signaldauer erreicht?
    //================================
    //rbi_SingleDropProtection_g=0; // to disable the SingleDropFunction
#ifdef __SIGMIN
    if(ruw_Signal > rub_SigLength_min)
    {
      //-    if ((rbi_SingleDropProtection_g==0)||(rb_speed_in_kmh_g<50))
      {
        rbi_Signal_min_Ok=1;
      }
      /*-   else
      {   if (ruw_Signal > CB_SIG_MIN_WERT3)
      {
      ruw_Signal-=CB_SIG_MIN_WERT3;
      rbi_SingleDropProtection_g=0;
    }
      
    }
      rw_SingleDropProtectCount_g=0;*/
    }
    else
      
      if(ruw_Signal == 0)
      {
        if(rw_SingleDropProtectCount_g < cw_SINGLEDROPCOUNTEROFFSET_g)
        {
          rbi_SingleDropProtection_g=0;
          rw_SingleDropProtectCount_g++;
        }
        else
        {
          rbi_SingleDropProtection_g=1;
        }
      }
#endif
    //Soll auf Ansammlung umgeschaltet werden?
    //========================================
    if(rbi_Sig_Ansamml_Status==0)
    {
      if(rbi_Sig_Ansammlung==0)
      {
        //Es wird auf Ansammlungsbetrieb umgeschaltet,
        //wenn die Schwelle den Wert "ruw_Schwelle_min" hat
        //und der Signalspeicher das erste mal leer ist.
        if((ruw_Schwelle<=ruw_Schwelle_min) && ((ruw_Signal+ruw_SigInt)==0))
        {
          rbi_Sig_Ansammlung=1;
          rbi_Sig_Ansamml_Status=1;
        }
      }
    }
    //----------------------------------------------------------------------------------------------------------
    //Integrationsspeicher fuer mehrere Wischerstufen
    //===============================================
    //max. Signallaenge fuer Stufe1 ueberschritten?
    
    if(ruw_Signal < (CB_MAX_ST1_SIGNALLAENGE*(word)(rub_Empf_Faktor))) /*VDR_511*/
    {
      if((ruw_StX_Speicher+(ruw_SigLength_fakt_stufeX)) < CW_MAX_STX_SPEICHER) /*VDR_127 use new Variable*/
      {
        /*VDR_127 use new Variable for compensation of continious decrementing*/
        ruw_StX_Speicher += (ruw_SigLength_fakt_stufeX); 
      }
      else
      {
        ruw_StX_Speicher = CW_MAX_STX_SPEICHER;
      }
    }
    //Integrationsspeicher fuer StufeX entladen
    
    ruw_Temp_SigMain_l = (ruw_StX_Speicher >>7)+rb_Dec_Stx_Speicher_g;
    
    
    ruw_Temp_SigMain_l=((CB_TASK_MIN-rub_SigLength)*ruw_Temp_SigMain_l)>>5;
    
    if(ruw_StX_Speicher > ruw_Temp_SigMain_l)
    {
      if ((rbi_LowVoltage == 0)&&(rbi_WashingActive==0)) /*VDR_375*/
      {
        ruw_StX_Speicher -= ruw_Temp_SigMain_l;
      }
    }
    else
    {
      ruw_StX_Speicher = 0;
    }
    
    //Integrationsspeicher fuer Stufe 2
    //=================================
    //max. Signallaenge fuer Stufe2 ueberschritten?
    if((rbi_SigSt2_max==0) && (ruw_Signal < (CB_MAX_ST2_SIGNALLAENGE*(word)(rub_Empf_Faktor))))
    {
      ruw_Temp_SigMain_l = (7*(word)(rub_Empf_Faktor_St2)*(word)(rub_SigLength))/10+(20*(word)(rub_Empf_Faktor_St2)*(word)(rub_SigPulse));  /*VDR_511*/
      if((ruw_St2_Speicher) < (CW_MAX_ST2_SPEICHER-ruw_Temp_SigMain_l)) /*VDR_511*/
      {
        ruw_St2_Speicher += ruw_Temp_SigMain_l; // for compensation of continious decrementing
      }
      else
      {
        ruw_St2_Speicher = CW_MAX_ST2_SPEICHER;
      }
    }
    else
    {
      rbi_SigSt2_max=1;
    }
  }
}



#ifdef RAIN_INTENSITY
/** Rain intensity VCO_423: 
* Calcute the interval of current zero-ing of integration signal */
static void signal_time_interval(void)
{
  byte rb_LookupTable_idx_l;
  word rw_Thr_SigVoltage_l = (word)(((((word)rb_RS_Intensity_SigVoltageH_g)<<8)) + rb_RS_Intensity_SigVoltageL_g);
  /* calculate the interval from 1ms timer */
  if (rw_1msTimer_g > rw_old_1msTimer_g)
  {
    rw_Interval_g = (rw_1msTimer_g - rw_old_1msTimer_g)/1000;
  }
  else
  {
    rw_Interval_g = (rw_1msTimer_g + (0xFFFF - rw_old_1msTimer_g))/1000; //seconds
  }
  
  if(rw_RS_SigVoltage_neg_int_g != 0)
  {
    rw_Interval_g = rw_Interval_g* (rw_Thr_SigVoltage_l/rw_RS_SigVoltage_neg_int_g);
    rw_old_1msTimer_g = rw_1msTimer_g; // save the current timestamp
#if (defined (BYTON) || defined (GEELY2DOT0))    
    for (rb_LookupTable_idx_l = 13; rb_LookupTable_idx_l > 0; rb_LookupTable_idx_l--)
#else
    for (rb_LookupTable_idx_l = 14; rb_LookupTable_idx_l > 0; rb_LookupTable_idx_l--)
#endif
    {
      if(cb_RainInt_TransformArray_g[rb_LookupTable_idx_l-1] <= rw_Interval_g)
      {
#if (defined (BYTON) || defined (GEELY2DOT0)) 
        rb_RainInt_IntensityOutput_g = rb_LookupTable_idx_l;
#else
        rb_RainInt_IntensityOutput_g = rb_LookupTable_idx_l - 1;
#endif        
      }
    }
  }
  else
  {
    rb_RainInt_IntensityOutput_g= 0;
  }
  
  
  rw_old_1msTimer_g = rw_1msTimer_g;  
}
#endif

// Function for decreasing the memorys
static void signal_decrease(void)
{
  unsigned char rub_DecSigSpeicher;
  
  //Speicher entladen?
  //==================
  
  if(rub_SigLength < CB_TASK_MIN)
    
  {
    // Signal Speicher entladen
    //=========================
    //Signallaenge verlauft nicht ueber ganze Taskzeit
    //=> Signalspeicher wird entladen!
    //   Zuerst wird "ruw_SigInt" verringert, anschliessend ruw_Signal!
    //Bestimmung der Entladekonstanten:
    //Die Entladezeit ist abhaengig, ob das System im Ansammlungsmodus
    //oder im Normalbetrieb ist.
    //Ist die Signal Ansammlung aktiv?
    //================================
    if((rbi_Sig_Ansammlung==1)
       && (rub_WiperMotorTime == 0)
         && (ruw_Schwelle <= 1000))
    {
      //System ist auf Ansammlungsbetrieb geschaltet
      //->Signalspeicher wird langsam entladen
      
      if(rub_Dec_SigSp_Ans_Count < CB_DEC_SIGSP_ANS)
      {
        rub_Dec_SigSp_Ans_Count++;
        //Signalspeicher wird nicht entladen!
        rub_DecSigSpeicher=0;
      }
      else
      {
        rub_Dec_SigSp_Ans_Count=0;
        
        
        rub_DecSigSpeicher = (CB_TASK_MIN-rub_SigLength)*CB_DEC_SIGINT_SPEICHER;
        
        
        //Im Ansammlungsbetrieb wird ein nur mit einem viertel des
        //normalen wertes entladen!
        rub_DecSigSpeicher=rub_DecSigSpeicher>>2;
      }
    }
    else
    {
      //System ist nicht auf Ansammlungsbetrieb geschaltet
      //->Signalspeicher wird normal entladen
      
      rub_DecSigSpeicher = (CB_TASK_MIN-rub_SigLength)*CB_DEC_SIGINT_SPEICHER;
      
      
    }
    
    if(ruw_SigInt >= rub_DecSigSpeicher)
    {
      //ruw_SigInt ist groesser als Wert, um den verringert werden soll!
      ruw_SigInt -= rub_DecSigSpeicher;
    }
    else
    {
      //ruw_SigInt ist kleiner als Wert, um den verringert werden soll!
      
      if(ruw_Signal > (rub_DecSigSpeicher - ruw_SigInt))
      {
        ruw_Signal -= (rub_DecSigSpeicher - ruw_SigInt);
      }
      else
      {
        ruw_Signal = 0;
      }
      ruw_SigInt = 0;
    }
  }
}



static void signal_valid(void)
{
  unsigned short int ruw_Temp_valid_l;
  //****************************
  //Abfrage, ob Signal gueltig *
  //****************************
  //min. Signal Dauer erreicht?
#ifdef __SIGMIN
  if(rbi_Signal_min_Ok==1)
  {
    ruw_Temp_valid_l=ruw_SigInt+ruw_Signal;
  }
  else
  {
    ruw_Temp_valid_l=ruw_SigInt;
  }
#else
  ruw_Temp_valid_l=ruw_SigInt+ruw_Signal;
#endif
  //Signal gueltig?
  if(ruw_Temp_valid_l > ruw_Schwelle)
  {
    rbi_Signal_Merker=1;                 //Signal Merker wird nach 40 ms Task zuruckgesetzt
    if (rbi_Tropfen_Merker == 0)         // neuer Tropfen oder neue Wischung mit Wert uber schwelle
    {
      // fur leeren Speicher etwas schneller laden fur jede Uberschreitung der Schwelle
      rub_Int_Speicher += (CB_INT_SPEICHER_MAX - rub_Int_Speicher)>>rub_TropfenMerkerOffsettShift_g;  
      // oder beim Beginn einer Wischung
      rub_Ovr_Speicher += (CB_OVR_SPEICHER_MAX - rub_Ovr_Speicher)>>rub_TropfenMerkerOffsettShift_g;   
      if (rub_Ovr_Speicher < (CB_OVR_SPEICHER_MAX>>1) )
      {
         // fur leeren Speicher etwas schneller laden fur jede Uberschreitung der Schwelle
        rub_Int_Speicher += (CB_INT_SPEICHER_MAX - rub_Int_Speicher)>>rub_TropfenMerkerOffsettShift_g+1;  
         // oder beim Beginn einer Wischung
        rub_Ovr_Speicher += (CB_OVR_SPEICHER_MAX - rub_Ovr_Speicher)>>rub_TropfenMerkerOffsettShift_g;  
      }
    }
    rbi_Tropfen_Merker=1;                //Merker fuer gueltigen Tropfen
    //"rbi_Tropfen_Merker" wird beim Start des
    //naechsten Wischzyklus rueckgesetzt!
    
    
    
    
    
    rub_Sig_Ok_Count++;                  //Zaehler fuer Dauer "Signale gueltig"
    //Zaehler wird in der Routine, die den Intervallspeicher                                  //ladet zurueckgesetzt!
    //ladet bzw. entladet rueckgesetzt
    
    rbi_Sig_Ansammlung=0;            //Nach dem ersten ueberschreiten der
    //wird Ansammlungszeit beendet
    
#ifdef _ONETIME_OR_DOUBLE_OVERWIPED_
    if (rub_RainSignalOverSchwelleCounter<254)
    {
      rub_RainSignalOverSchwelleCounter ++;
    }
#endif
  }
}

//
static void signal_low(void)
{
  //******************************
  //Abfrage, ob Signal Dauer-Low *
  //Diagnose!
  //******************************
  // rub_SigPulse     = 0 => keine Signalaenderung!
  // rub_SigLength    > 0 => Signal vorhanden (keine Aussage ueber Laenge)
  //
  // keine Signalaenderung und Signal vorhanden fuer eine Zeit groesser 2 s
  // => Fehler
  //
  // Fehlerauswertung soll nur bei aktivierter Regensensorfunktion erfolgen!
  //Regensensor aktiv?
  if(rbi_RainSensorEnable==1)
  {
    //Signal aktiv & > min. Sig.Laenge
    if((rub_SigPulse==0) && (rub_SigLength>0))
    {
      // Diagnose-Zaehler fuer "Signal-Uebertraege" incremntieren
      if(rub_Dia_Count < CW_DIA_TIMEOUT)
      {
        rub_Dia_Count++;
      }
      else
      {
        //Regensensor Fehlerbit setzen
        rbi_RainSensorError=1;
      }
      if (rub_Dia_Count_dyna_Stop > 150) /*VDR_132 do not count and not reset during fastloop*/
      {
        if(rub_Dia_Count_dynamic < CW_DIA_TIMEOUT)/* VDR_132 do not count and not reset during fastloop*/
        {
          rub_Dia_Count_dynamic++;/* VDR_132 do not count and not reset during fastloop*/
        }
        else
        {
          //Regensensor Fehlerbit setzen
          rbi_RainSensorError=1;/* VDR_132 do not count and not reset during fastloop*/
        }
      }
    }
    else 
    {
      // Diagnose-Zaehler fuer "Signal-Uebertraege" loeschen
      rub_Dia_Count=0;
      if (rub_Dia_Count_dyna_Stop > 150) /*VDR_132  do not count and not reset during fastloop*/
      {
        rub_Dia_Count_dynamic = 0;     /* VDR_132 do not count and not reset during fastloop*/
      }
    }
  }
}


// Decrease sp2 memory
static void signal_decreaseSP2(void)
{
  unsigned short int ruw_Temp_decr_l;
  //Integrationsspeicher fuer Stufe2 entladen
  if(rbi_SigSt2_max==0)         // wurde bit fur langes signal nicht gesetz
  {
    
    ruw_Temp_decr_l=(word)(CB_TASK_MIN-rub_SigLength)*CB_DEC_ST2_SPEICHER; /*VDR_511*/
    
    
  }
  else
  {
    
    ruw_Temp_decr_l=(CB_TASK_MIN*CB_DEC_ST2_SPEICHER)>>2;
    
    
  }
  if(ruw_St2_Speicher > ruw_Temp_decr_l)
  {
    ruw_St2_Speicher -= ruw_Temp_decr_l;
  }
  else
  {
    ruw_St2_Speicher = 0;
  }
}




//
static void signal_limit(void)
{
  //limitierung der Speichersumme
  //===============================
  if((ruw_SigInt+ruw_Signal) > CW_MAX_SIGSP_FAKT) /* can not overrun due to cyclic check */
  {
    if (ruw_Signal <= CW_MAX_SIGSP_FAKT)
    {
      ruw_SigInt=CW_MAX_SIGSP_FAKT-ruw_Signal;
    }
    else
    {
      ruw_Signal =CW_MAX_SIGSP_FAKT-ruw_SigInt;
    }
  }
}
