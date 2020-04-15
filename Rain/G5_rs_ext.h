#ifndef G5_RS_EXT_H
#define G5_RS_EXT_H

/******************************************************************************
*******************************************************************************
**                              test
** Datei:      rs_ext.h
**
** Bearbeiter: Bernd Schmid Abt. WRS
**
** Projekt:    (PQ24)/D66
**
** Datum:      10.03.98
** geaendert:  23.05.00
**
** Funktion:   Include File fuer die externen Deklaration von Variablen der
**             Regensensorauswertung
**
*******************************************************************************
******************************************************************************/
/*
230801:
defines fuer EEProm-Variablen eingefuehrt!

310501:
rub_RSIntermDelayInit_internal eingefuehrt: Interne Variable zur Berechnung
der Intervallzeit!
// 180501
// Die Variablen fuer x400 auskommentiert!

// 26.05.00
// memory=zpage bei IAR define enfernt
*/
// Variablen, die von Valeo an das Steuergeraet bereitgestellt werden
//===================================================================

/* History                                                                    */
/*----------------------------------------------------------------------------*/
/* Date         VDR_Number  Author       Description                                       */
/*----------------------------------------------------------------------------*/
/* 27.11.2014   VCO_200    NB      move rb_LimitMemomryNoWiperReaction_g variable from G5_sci.h to G5_rs_mem_40.h */
/******************************************************************************/
/* PRQA S 857 EOF *//*<< Macro exceeds 1024 number  >>*/

#include "G5_projectDefs.h"

extern unsigned char rb_LimitMemomryNoWiperReaction_g;
extern unsigned short int ruw_St2_Speicher;	      //Integrationsspeicher fuer Stufe2
extern unsigned short int ruw_St1_Speicher;       //Integrationsspeicher fuer Stufe1
extern unsigned short int ruw_StX_Speicher;       //Integrationsspeicher fuer Stufe1
extern unsigned char rub_SignalIntegral_g;          //Bandendetestvariable

extern unsigned short int ruw_Schwelle;		      //Schwelle fuer Ueberwischausblendung

extern unsigned short int ruw_SigInt;		      //Integrationsspeicher Signale
extern unsigned short int ruw_Signal;		  	  //Speicher fuer aktuelles Signal


extern unsigned char  rub_Int_Speicher;            //Integrationsspeicher fuer Intervall
extern unsigned char  rub_Ovr_Speicher;            //Integrationsspeicher fuer Override
extern unsigned char  rub_Speicher_max;            //max. Wert vom Intervallspeicher bzw, Override

extern unsigned char  rub_Empf_Faktor;             //Faktor, mit dem die einzelnen Signale gewichtet
//werden. Variable ist Abhaengig von der Poti-Stellung.

extern unsigned char rub_Sig_Anzahl;            //Anzahl der Signale pro Wischzyklus
extern unsigned char rub_Tropf_Anzahl;			//Anzahl der Tropfen fuer eine Wischung
extern unsigned char rub_Trock_Wisch;           //Zaehler fuer Trockenwischungen

extern unsigned char rub_Nachwisch_Count;       //Nachwischzaehler
extern unsigned char rub_St2_Epr;               //Entprell Variable fur Stufe2
extern unsigned char rbi_WiperStarted_g;        // bit to show that the wiper has started

//Fuer X400 !!!
//extern unsigned char rub_Direktbetrieb;           //Um Direktbetrieb nach einmaligem Beruehren des RS zu erkennen
//extern unsigned char rub_NormalRSBetrieb_justonetime; 
// Um Direktbetrieb bei einer einzigen Wischung feststellen zu koennen
//Fuer x400 ENDE !!!!

extern unsigned char rub_IntermDelayTime_LalstWipe_g;
extern unsigned char  rb_Sig_DownWipe_to_upWipe_g;

#ifdef AUDI_B8
extern unsigned char rb_LIN_SensitivityShift_g;
#endif
/*****
EEPROM PARAMETER
****/


// Bit - Variablen
//================




/*  in "cdp.h"
extern bit rbi_Signal_min_Ok;                   //Flag fuer min. Signallaenge ueberschritten
extern bit rbi_SigSt2_max;

extern bit rbi_Tropfen_Merker;                  //Merker fuer gueltigen Tropfen

extern bit rbi_Sig_Ansammlung;                  //Merker fuer Signalansammlung
*/



//***********************************************************
//***********************************************************
//PREPROCESSOR_SWITCHES
//PART: BIT_VARIABLES OR BIT_FIELD
//***********************************************************
//***********************************************************

//AUSWAEHLEN DES COMPILERS FEHLT NOCH !!!!!!!!!
// FUR IAR KEIN (!!!!) BITFELD !!!


//Definition des Bitfeldes
//========================
typedef struct
{
  unsigned  B7:1;
  unsigned  B6:1;
  unsigned  B5:1;
  unsigned  B4:1;
  unsigned  B3:1;
  unsigned  B2:1;
  unsigned  B1:1;
  unsigned  B0:1;
} RS_Bit_Feld;

/* PRQA S 750,0759 20*//*<< 0759:union needed to reduce RAM usage >>*/
typedef union
{
  RS_Bit_Feld Bit;
  unsigned char AllBit;
} RS_Flag;

extern volatile RS_Flag RSStatus;                      //Schnittstellenbyte Flags!
extern volatile RS_Flag RS_Flags_Int;                  //Schnittstellenbyte RS-Flags!



//Belegung des Bitfeldes
//======================

//Input Variables for Rain Sensor
#define rbi_RainSensorEnable	 RSStatus.Bit.B0
#define	rbi_WashingActive    	 RSStatus.Bit.B1
#define rbi_LowVoltage        RSStatus.Bit.B2
#define rbi_Night              RSStatus.Bit.B3 //!!!NICHT RSStatus.Bit.B2 !!
//Bit zum Ausblenden von Potiinkrementierungen bei nicht aktivem LSS for LIN_Sensor
#define rbi_LSS_Interval_g     RSStatus.Bit.B7 

//Output Variables from Rain Sensor
#define	rbi_RainSensorError	     RSStatus.Bit.B4
#define	rbi_RSWipeSlowDmd    	 RSStatus.Bit.B5
#define	rbi_RSWipeFastDmd	     RSStatus.Bit.B6


//Interne Regensensor Bitvariablen
//#define             RS_Flags_Int.Bit.B0
#ifdef __SIGMIN
#define rbi_Signal_min_Ok        RS_Flags_Int.Bit.B1      //Flag fuer min. Signallaenge ueberschritten
#endif
#define rbi_Tropfen_Merker       RS_Flags_Int.Bit.B2	  //Merker fuer gueltige Tropfen
#define rbi_Sig_Ansammlung       RS_Flags_Int.Bit.B3      //Merker fuer Signalansammlung
#define rbi_Sig_Ansamml_Status   RS_Flags_Int.Bit.B4      //Merker fuer Signalansammlung
#define rbi_SigSt2_max           RS_Flags_Int.Bit.B5      //Flag fuer gueltiges Signal
#define rbi_Signal_Merker        RS_Flags_Int.Bit.B6      //Flag fuer gueltiges Signal
#define rbi_SingleDropProtection_g  RS_Flags_Int.Bit.B7//Flag fuer schutz gegen kleine Tropfen bei hoher Geschwindigkeit


//#endif //GEHOERT NOCH ZUR OBEN VERLANGTEN PREPOCESSOR ABFRAGE !!!


//***********************************************************
//***********************************************************
// END OF PART BIT-VARIABLES OR BIT-FIELD
//***********************************************************
//***********************************************************









// Funktions-Prototypen
//=====================

extern void Motor(void);
extern void Signal(void);
extern void Empf(void);




#endif