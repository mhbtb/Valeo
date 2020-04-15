#ifndef G5_RS_TASK_H 
#define G5_RS_TASK_H
/******************************************************************************
*******************************************************************************
**
** Datei:      G5_rs_Task.h
**
**
** Bearbeiter: Frank Selbmann
**             Abt. WRS
**
** Datum:      04.03.98
** geaendert:  11.05.01
**
** Inhalt:     Definitionen fuer folgende Funktionen
**
**             wwrainse_Init()        Initialisierungsroutine fuer Regensensor
**
**             wwrainse_Task10ms()    10ms Task fuer Regensensorauswertung
**
**             wwrainse_Task40ms()    40ms Task fuer Regensensorauswertung
**
**
**
*******************************************************************************
*******************************************************************************
******************************************************************************/

// Variablen nur fuer Regensensor Auswertung
//==========================================

extern const unsigned char cab_RS_SchwelleMin[9];

extern const unsigned char cab_RS_Dec_IntSP_Offs[9];
extern const unsigned char cab_RS_Empf_Fakt_St2[9];

extern unsigned char  rub_Inc_Int_Sp_Count;			  //Counter fuer Intervallspeicher Ladezeit
extern unsigned char  rub_Dec_Int_Sp_Count;   		  //Counter fuer Intervallspeicher Entladezeit

extern unsigned char  rub_Dec_Int_Sp;				  //Intervallspeicher Entladezeit
extern unsigned short int ruw_Schwelle_min;       //min Wert fuer die Schwelle der
//Ueberwischausblendung.
//Wert ist Abhaengig von der
//eingestellten Empfindlichkeit.

extern unsigned char  rub_Inc_Ovr_Sp_Count;			  //Counter fuer Overridespeicher Ladezeit
extern unsigned char  rub_Dec_Ovr_Sp_Count;			  //Counter fuer Overridespeicher Entladezeit

extern unsigned char  rub_Dec_SigSp_Ans_Count;     //Counter fuer Signalentladung waehrend der
//Ansammlungszeit
extern unsigned char  rub_Empf_Faktor_St2;          //Faktor, mit dem die einzelnen Signale gewichtet
//werden. Variable ist Abhaengig von der Poti-Ste
extern unsigned char  rub_PotiStage_alt;		   //vorhergehende Potistellung

extern unsigned char  rub_LengthCounter_alt;
extern unsigned char  rub_PulseCounter_alt;
extern unsigned char rub_Sig_Counter;           //Zaehler fuer die Anzahl der Signale pro Wischzyklus
extern unsigned char rub_Sig_Anzahl_Alt;
extern unsigned char rub_Tropf_Count;           //Tropfenzaehler
extern unsigned char rub_WischZykl_Count;       //Zaehler fuer Wischungen
//wird bei jedem Nulldurchgang decrementiert
extern unsigned char rub_Delay_Ausbl;           //Wartezeit fuer Uberwischausblendung


#ifdef __SIGMIN
extern unsigned short int rub_SigLength_min;         //min. gueltige Signaldauer
#endif
extern unsigned char rub_Sig_Pause;

extern unsigned char rub_SigLength;             //Laenge der Signale, waehrend des letzten Tasks
extern unsigned char rub_SigPulse;			    //Anzahl der Signale, waehrend des letzten Tasks

extern unsigned char rub_Delay_Ausbl_count;     //Zaehler fuer Wartezeit Ueberwischausblendung
extern unsigned char rub_WiperMotorTime_alt;    //Dauer eines Wischzyklus
extern unsigned short int rub_Dia_Count_dynamic;	        //Diagnose-Zaehler fuer "Signal-Uebertraege"

extern unsigned char rub_Sig_Ok_Count;          //Zaehler fuer gueltige Signale erhoehen;
extern unsigned char rub_RSIntermDelayInit_internal;      //interne Regensensosr Delay Time
extern unsigned char rb_AfterWashingTimer_mg;             //Zeit nach letztem Waschen
extern unsigned char rb_DoneAfterwipe_g;
extern unsigned char rbi_LowSpeed_Out_g;
extern unsigned char rub_Trockwisch_memory;
extern unsigned short int  ruw_PulseLength_g;
extern unsigned short int ruw_meanPulseLenght_g; /* used to reduce empf-factor for long signals*/
extern unsigned short int ruw_presentPulseLenght_g; /*used to calculate ruw_meanPulseLenght_g*/
extern unsigned short int ruw_SigLength_DownWipe_g;
extern unsigned short int ruw_SigLength_UpWipe_g;



/* Function prototype */

extern void THold(void);

extern void Sig_min(void);
extern void Mem_40(void);
extern void Betrieb(void);
extern void IntBer(void);
extern void Empf_Einstellung(void);
extern void Mot_EinAus(void);
extern void Mot_AusEin(void);


#endif





