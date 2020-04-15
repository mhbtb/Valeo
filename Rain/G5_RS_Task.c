/******************************************************************************
*******************************************************************************
**
** Datei:      rs_Task.c
**
** Funktionen: wwrainse_Init()
**
**             wwrainse_Task10ms()
**             wwrainse_Task40ms()
**
**
** Bearbeiter: Bernd Schmid
**             Abt. WRS
**
** Datum:      04.03.98
** geaendert:  23.05.00
**
** Inhalt:     wwrainse_Init()        Initialisierungsroutine fuer Regensensor
**
**             wwrainse_Task10ms()    10ms Task fuer Regensensorauswertung
**
**             wwrainse_Task40ms()    40ms Task fuer Regensensorauswertung
**
**
**
*****************************************************************************************************************/
/* History                                                                                                      */
/****************************************************************************************************************/
/* Date      VDR_Number     Description                                                                         */
/****************************************************************************************************************/
/*19.03.2008 VDR_168            TMC request, 1 second should be the shortest Interval                           */
/*20.07.2009 VDR_344            Ford First Version                                                              */
/*01.04.2015 VDR_866    MP      Remove of rainsens.c for no-rain-variants                                       */
/*14.07.2015 VDR_893    MP      When short of LEDA or LEDB to GND, ASIC resets continuously                     */
/****************************************************************************************************************/

#include "G5_projectDefs.h"
#include "G5_rs_task.h"
#include "G5_rainsens.h"
#include "G5_ASIC_Control.h"
#include "G5_rs_def.h"

/* PRQA S 0759 2 *//*<< 0759:union needed to reduce RAM usage >>*/
volatile RS_Flag RSStatus;                      //Schnittstellenbyte Flags!
volatile RS_Flag RS_Flags_Int;                  //Schnittstellenbyte RS-Flags!

unsigned char rub_RSIntermDelayInit;      //Regensensosr Delay Time
unsigned char rub_RSIntermDelayInit_internal;      //interne Regensensosr Delay Time
unsigned short int ruw_St2_Speicher;       //Integrationsspeicher fuer Stufe2
unsigned short int ruw_St1_Speicher;       //Integrationsspeicher fuer Stufe1
unsigned short int ruw_StX_Speicher;       //Integrationsspeicher fuer Stufe1

unsigned short int ruw_Schwelle;           //Schwelle fuer Ueberwischausblendung

unsigned short int ruw_Schwelle_min; 	     //min Wert fuer die Schwelle der
unsigned char rb_AfterWashingTimer_mg;     /*Zeit nach letztem Waschen  
                                            set to max value after start not to change ruw_Schwelle */
                                           //Ueberwischausblendung.
                                           //Wert ist Abhaengig von der
                                           //eingestellten Empfindlichkeit.

unsigned short int ruw_SigInt;             //Integrationsspeicher Signale
unsigned short int ruw_Signal;             //Speicher fuer aktuelles Signal

unsigned char  rub_Inc_Int_Sp_Count;        //Counter fuer Intervallspeicher Ladezeit
unsigned char  rub_Dec_Int_Sp_Count;        //Counter fuer Intervallspeicher Entladezeit
unsigned char  rub_Dec_Int_Sp;              //Intervallspeicher Entladezeit
unsigned char  rub_Inc_Ovr_Sp_Count;        //Counter fuer Overridespeicher Ladezeit
unsigned char  rub_Dec_Ovr_Sp_Count;        //Counter fuer Overridespeicher Entladezeit

unsigned char  rub_Dec_SigSp_Ans_Count;     //Counter fuer Signalentladung waehrend der
                                            //Ansammlungszeit
unsigned char rub_SignalIntegral_g;          //Bandendetestvariable
unsigned char  rub_Int_Speicher;            //Integrationsspeicher fuer Intervall
unsigned char  rub_Ovr_Speicher;            //Integrationsspeicher fuer Override
unsigned char  rub_Speicher_max;            //max. Wert vom Intervallspeicher bzw, Override
unsigned char  rub_Empf_Faktor;             //Faktor, mit dem die einzelnen Signale gewichtet
                                            //werden. Variable ist Abhaengig von der Poti-Stellung.
unsigned char  rub_Empf_Faktor_St2;          //Faktor, mit dem die einzelnen Signale gewichtet
                                             //werden. Variable ist Abhaengig von der Poti-Ste
unsigned char  rub_PotiStage_alt;           //vorhergehende Potistellung
unsigned char  rub_LengthCounter_alt;
unsigned char  rub_PulseCounter_alt;
unsigned char rub_SigLength;               //Laenge der Signale, waehrend des letzten Tasks
unsigned char rub_SigPulse;                //Anzahl der Signale, waehrend des letzten Tasks

//unsigned char rub_SigLength_min;           //min. gueltige Signaldauer
#ifdef __SIGMIN
unsigned short int rub_SigLength_min;           //min. gueltige Signaldauer
#endif
unsigned char rub_Sig_Pause;

unsigned char rub_Sig_Counter;             //Zaehler fuer die Anzahl der Signale pro Wischzyklus
unsigned char rub_Sig_Anzahl;              //Anzahl der Signale pro Wischzyklus
unsigned char rub_Sig_Anzahl_Alt;

unsigned char rub_Tropf_Count;             //Tropfenzaehler
unsigned char rub_Tropf_Anzahl;            //Anzahl der Tropfen fuer eine Wischung

unsigned char rub_Trock_Wisch;             //Zaehler fuer Trockenwischungen
unsigned char rub_Delay_Ausbl_count;       //Zaehler fuer Wartezeit Ueberwischausblendung
unsigned char rub_WiperMotorTime_alt;      //Dauer eines Wischzyklus

unsigned short int rub_Dia_Count_dynamic;	/*VDR_132 Diagnose-Zaehler fuer "Signal-Uebertraege"*/

unsigned char rub_Sig_Ok_Count;            //Zaehler fuer gueltige Signale
unsigned char rub_Nachwisch_Count;         //Nachwischzaehler
unsigned char rub_WischZykl_Count;         //Zaehler fuer Wischungen
                                         //wird bei jedem Nulldurchgang decrementiert
unsigned char rub_Delay_Ausbl;             //Wartezeit fuer Uberwischausblendung
unsigned char rub_St2_Epr;                 //Entprell Variable fur Stufe2
unsigned char rbi_WiperStarted_g;          // bit to show that the wiper has started
unsigned char rb_DoneAfterwipe_g;
unsigned char rbi_LowSpeed_Out_g;
unsigned char rub_IntermDelayTime_LalstWipe_g;
unsigned short int  ruw_PulseLength_g;
unsigned short int  ruw_SigLength_PerWipe_Count_g;
unsigned char rub_Trockwisch_memory;
unsigned short int ruw_meanPulseLenght_g;
unsigned short int ruw_presentPulseLenght_g;
unsigned short int ruw_SigLength_DownWipe_g;
unsigned short int ruw_SigLength_UpWipe_g;
unsigned char  rb_Sig_DownWipe_to_upWipe_g;

#if (defined(AUDI_B8))    // VCO_71
unsigned char rb_LIN_SensitivityShift_g;
#endif

const unsigned char cab_RS_SchwelleMin[9]   = {CW_SCHWELLE_MIN_E1>>2, CW_SCHWELLE_MIN_E2>>2, CW_SCHWELLE_MIN_E3>>2, CW_SCHWELLE_MIN_E4>>2,CW_SCHWELLE_MIN_E5>>2,CW_SCHWELLE_MIN_E6>>2,CW_SCHWELLE_MIN_E7>>2,CW_SCHWELLE_MIN_E8>>2,CW_SCHWELLE_MIN_E9>>2};
const unsigned char cab_RS_Dec_IntSP_Offs[9] = {CB_DEC_INT_SP_OFFS_E1,CB_DEC_INT_SP_OFFS_E2,CB_DEC_INT_SP_OFFS_E3,CB_DEC_INT_SP_OFFS_E4,CB_DEC_INT_SP_OFFS_E5,CB_DEC_INT_SP_OFFS_E6,CB_DEC_INT_SP_OFFS_E7,CB_DEC_INT_SP_OFFS_E8,CB_DEC_INT_SP_OFFS_E9};
const unsigned char cab_RS_Empf_Fakt_St2[9] = {CB_EMPF_FAKTOR_ST2_E1,CB_EMPF_FAKTOR_ST2_E2,CB_EMPF_FAKTOR_ST2_E3,CB_EMPF_FAKTOR_ST2_E4,CB_EMPF_FAKTOR_ST2_E5,CB_EMPF_FAKTOR_ST2_E6,CB_EMPF_FAKTOR_ST2_E7,CB_EMPF_FAKTOR_ST2_E8,CB_EMPF_FAKTOR_ST2_E9};


/******************************************************************************
*******************************************************************************
**
** Funktion:   wwrainse_Init()
**
**
** Bearbeiter: Bernd Schmid Abt. TKW
** Datum:      09.03.98
** geaendert:  20.05.99
**
** Funktion:   - Initialisierung der Variablen, die ungleich 0 sind.
**
**             - Initialisierung von Variablen, die nach dem Aus- Einschalten
**               der Intervallstellung neu gesetzt werden muessen.
**
**             - Die Initialisierungsroutine wird vom Betriebsystem
**               (Steuergeraet) aufgerufen bevor das Enable Bit gesetzt wird.
**               D.h. vor dem Einschalten der Intervallfunktion.
**
**             - Die Variablen des Steuergeraetes die von der Regensensor-
**               Auswertung verwendet werden, muessen einen gueltigen
**               Wert haben (z.B. rub_PotiStage).
**               D.h. die Werte muessen bereits entprellte Werte haben.
**
**
*******************************************************************************
******************************************************************************/
// Initialisierung-Funktion muss immer ausgefuehrt, bevor das Regensensor
// Enable-Bit aktiviert wird!

void wwrainse_Init(void)
{
  // Speicher fuer Signalbearbeitung initalisieren
  rub_LengthCounter_alt=rub_LengthCounter;
  rub_PulseCounter_alt=rub_PulseCounter;
  //Wert fuer vorhergehende Potistellung sichern
  rub_PotiStage_alt=rub_PotiStage;
  //Variablen fuer Empfindlichkeitseinstellung setzen
  Empf_Einstellung();
  //Vorgabewerte laden, weil Berechnung erst nach
  //Beendigung der ersten Wischung erfolgt.
  //Wartezeit fuer Ueberwischausblendung Vorgabe-Wert setzen
  rub_Delay_Ausbl=CB_DELAY_AUSBL_VORGABE;
  //Wert fuer min. Signallaenge mit Vorgabewert laden
  
  rub_Ovr_Speicher = CB_OVR_STARTWERT;       //Overridespeicher auf hoeheren Startwert setzen
#ifdef __SIGMIN
  //schnelleres Ansprechverhalten nach dem Einschalten
  rub_SigLength_min=1;
#endif
  rub_RSIntermDelayInit = CB_INTERMDELAY_DIREKT;
  //Variablen, die vor dem "Wieder Einschalten" geloescht werden muesen


  rbi_RainSensorError=0;                     //Fehlerbit loeschen
  
  
  rub_Trock_Wisch=0;                         //Zaehler fuer Trockenwischungen loeschen
  rub_Trockwisch_memory = 0;
  
  rbi_Tropfen_Merker=0;                      //Tropfenmerker loeschen
  
  
  rub_Int_Speicher=0;                        //Intervallspeicher loeschen
  
  ruw_St2_Speicher=0;                        //Speicher fuer Stufe 2 loeschen
  
  
  rub_Sig_Ok_Count=0;                        //Zaehler fuer gueltige Signale loeschen
  
  rub_Nachwisch_Count=0;                     //Nachwischzaehler loeschen
  
  
  
  rbi_RSWipeFastDmd=0;                       //Stufe 2 ausschalten
  rbi_RSWipeSlowDmd=0;                       //Stufe 1 abschalten
  //rbi_LowVoltage=0;    //reset low voltage-bit
  rbi_Night=0;
  //Variablen fuer Signalansammlungszeit ruecksetzen
  rbi_Sig_Ansammlung=0;
  rbi_Sig_Ansamml_Status=0;
  rub_Dec_SigSp_Ans_Count=0;
  rub_SignalIntegral_g = 0;

  
  
}
/******************************************************************************
*******************************************************************************
**
** Funktion:   wwrainse_Task10ms
**
** Bearbeiter: Bernd Schmid Abt. TKW
** Datum:      04.03.98
** geaendert:  18.06.98
**
** Inhalt:     10ms Task fuer Regensensorauswertung
**
**
**             In diesem Task werden alle Regensensorfunktionen, die im 10ms
**             abgearbeitet werden aufgerufen.
**
** Aufruf:     Dieser Task wird alle 10ms vom Betriebsystem (Steuergeraet)
**             aufgerufen.
**
*******************************************************************************
******************************************************************************/



void wwrainse_Task10ms(void)
{
  // Berechnet die Signallaenge und die Anzahl der Signale zwischen zwei Taskaufrufen
  Signal();
}
/******************************************************************************
*******************************************************************************
**
** Funktion:   wwrainse_Task40ms
**
** Bearbeiter: Bernd Schmid Abt. TKW
** Datum:      04.03.98
** geaendert:  18.06.98
**
** Inhalt:     40ms Task fuer Regensensorauswertung
**
**
**             In diesem Task werden alle Regensensorfunktionen, die im 40ms
**             abgearbeitet werden aufgerufen.
**
**
** Aufruf:     Dieser Task wird alle 40ms vom Betriebsystem (Steuergeraet)
**             aufgerufen.
*******************************************************************************
******************************************************************************/


void wwrainse_Task40ms(void)
{
  //Deklaration der Variablen in extern.h//
  //aktuelle Intervallzeit in interne Intervallzeit laden
  rub_RSIntermDelayInit_internal = rub_RSIntermDelayInit;
#ifdef __SIGMIN
  //Bestimmung der min. Signallaenge
  Sig_min();
#endif
  //Regensensor Funktion aktiviert?
  if(rbi_RainSensorEnable==1)
  {
    //Empfindlichkeit an Potistellung anpassen
    Empf();
  }
  // Erkennen von Aenderungen des Motor Zustandes.
  // Aus -> Ein bzw. Ein -> Aus
  // Bestimmung der Motorlaufzeit
  Motor();
  // Verringern und Setzen der Schwelle fuer die Ueberwischausblendung
  THold();
  // Laden bzw. Entladen des Override/Intervallspeichers
  Mem_40();
  //Bestimmung der Betriebsart
  Betrieb();
  //Berechnung der Intervallzeit
  IntBer();
  //Merker fuer gueltiges Signal ruecksetzen
  rbi_Signal_Merker=0;
  // Zuweisen des berechneten Intervallzeit

  rub_RSIntermDelayInit = rub_RSIntermDelayInit_internal;
  
}

