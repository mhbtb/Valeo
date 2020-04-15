#ifndef G5_RS_DEF_H                               /* To avoid double inclusion */
#define G5_RS_DEF_H
/******************************************************************************
*******************************************************************************
**
** Datei:      rs_def.h
**
** Bearbeiter: Bernd Schmid Abt. WRS
** Datum:      09.03.98
** geaendert:  18.08.00
**
** Inhalt:     Konstanten fuer Regensensorauswertung
**
**
*******************************************************************************
******************************************************************************/

/* History                                                                    */
/*----------------------------------------------------------------------------*/
/* Date      VDR_Number  Name    Description                                  */
/*-DD.MM.YY-------------------------------------------------------------------*/
/* 10.12.10  VCO_090    AL  optimise Error detection not to detect water on loop*/
/* 15.11.10  VCO_085  AL    reduce sensitivity and decrement for Stx. Memory 
                            for Konzernsensor*/ 
/* 15.11.10  VCO_084  AL    drywipe decrement on Ovr_Speicher and Int_Speicher
                            depending on sensitivity level*/
/* 28.10.10  VC075    AL    short interval*/
/* 20.09.10  VCO_76   FS    Double Overwiping Fine Tuning*/
/* 19.03.10  VDR_467  FS    Sensitivity Change should be reduced for about 30%*/
/* 17.02.10  VDR_437  FS    Update due to wrong Parametersetting*/
/* 19.01.10  VDR_414  FS    Update due to Testdrive*/
/* 20.07.09  VDR_344  FS    Ford uses 7 wiper speeds for STandard Wiper motor
 *                          with two Wiper Speeds*/
/* 27.11.08   VDR_296    AL  Posche: The Rainsensor should be more sensitive in different conditions*/
/* 24.04.08  VDR_209         MAXPOTISTAGE is defined not correct --> Should be 8*/
/* 19.03.08  VDR_168         TMC request, 1 second should be the shortest Interval*/
/* 03.02.08  VDR_127         Parameterset from Testdrive to use for VRO9*/

/******************************************************************************/

//***********************************************************


//#define Sie_Reg

// EEPROM_
//Auswahl ob die Parametrierung ueber Variablen(gespiegelte EEPROM-Zellen)
//oder DEFINE erfolgt



//***********************************************************


// Regensensor Parameter als Constanten
//=====================================
#include "G5_projectDefs.h"
#ifndef _DIAGNOSE_c_
#include "ior5f109be.h"
#include "G5_E2ProjectConfig.h"
#endif
// Adjustment of WipeOptions
//=====================================

//=====================================

// Regensensor Parameter als Constanten
//=====================================
/*************************************************************************
**                Empfindlichkeitsabhangige Parameter                   **
**************************************************************************/

#define CB_EMPF_FAKTOR       0//3//2   //Grundwert Empfindlichkeitsfakor


#define CB_EMPF_OFFSETT_E1      2     /*Ladefaktor-offsett fur Signalspeicher bei Empfindlichkeit 1(intern 0)*/
#define CB_EMPF_OFFSETT_E2      3     /*Ladefaktor-offsett fur Signalspeicher bei Empfindlichkeit 2(intern 1)*/
#define CB_EMPF_OFFSETT_E3      4     /*Ladefaktor-offsett fur Signalspeicher bei Empfindlichkeit 3(intern 2)*/
#define CB_EMPF_OFFSETT_E8      17    /*Ladefaktor-offsett fur Signalspeicher bei Empfindlichkeit 8(intern 7)*/
#define CB_EMPF_OFFSETT_E9      18    /*Ladefaktor-offsett fur Signalspeicher bei Empfindlichkeit 7(intern 6)*/

#ifndef FORD

#define CB_EMPF_OFFSETT_E4      7     /*Ladefaktor-offsett fur Signalspeicher bei Empfindlichkeit 4(intern 3)*/
#define CB_EMPF_OFFSETT_E5      9     /*Ladefaktor-offsett fur Signalspeicher bei Empfindlichkeit 5(intern 4)*/
#define CB_EMPF_OFFSETT_E6      11    /*Ladefaktor-offsett fur Signalspeicher bei Empfindlichkeit 6(intern 5)*/
#define CB_EMPF_OFFSETT_E7      13    /*Ladefaktor-offsett fur Signalspeicher bei Empfindlichkeit 7(intern 6)*/

#else /*if FORD*/

#define CB_EMPF_OFFSETT_E4      8     /*Ladefaktor-offsett fur Signalspeicher bei Empfindlichkeit 4(intern 3)*/
#define CB_EMPF_OFFSETT_E5      11    /*Ladefaktor-offsett fur Signalspeicher bei Empfindlichkeit 5(intern 4)*/
#define CB_EMPF_OFFSETT_E6      13    /*Ladefaktor-offsett fur Signalspeicher bei Empfindlichkeit 6(intern 5)*/
#define CB_EMPF_OFFSETT_E7      15    /*Ladefaktor-offsett fur Signalspeicher bei Empfindlichkeit 7(intern 6)*/

#endif /*FORD*/

#define cb_MAXPOTISTAGE_g         8      /*VDR_209*/// 8 Potisatages 0-7

#define cb_MAX_OVERWIPE_SENSITIVITY  (7 *CB_EmpfGlobalSkal)/16 //reduced Sensitivity at intervalwipe

#define CB_EmpfGlobalSkal   28

#ifndef FORD

#define CB_EMPF_FAKTOR_E2        (byte) ((((word)CB_EmpfGlobalSkal*(word)(CB_EMPF_FAKTOR+CB_EMPF_OFFSETT_E2)))/16)
#define CB_EMPF_FAKTOR_E3        (((CB_EmpfGlobalSkal*(CB_EMPF_FAKTOR+CB_EMPF_OFFSETT_E3))+4)/16)
#define CB_EMPF_FAKTOR_E6        ((CB_EmpfGlobalSkal*(CB_EMPF_FAKTOR+CB_EMPF_OFFSETT_E6))/16)
#define CB_EMPF_FAKTOR_E8        ((CB_EmpfGlobalSkal*(CB_EMPF_FAKTOR+CB_EMPF_OFFSETT_E8))/16)
#define CB_EMPF_FAKTOR_E9        ((CB_EmpfGlobalSkal*(CB_EMPF_FAKTOR+CB_EMPF_OFFSETT_E9))/16)

#else /*if FORD*/

#define CB_EMPF_FAKTOR_E2        (byte) ((((word)CB_EmpfGlobalSkal*(word)(CB_EMPF_FAKTOR+CB_EMPF_OFFSETT_E2)))/16+1)
#define CB_EMPF_FAKTOR_E3        (((CB_EmpfGlobalSkal*(CB_EMPF_FAKTOR+CB_EMPF_OFFSETT_E3)))/16+1)
#define CB_EMPF_FAKTOR_E6        ((CB_EmpfGlobalSkal*(CB_EMPF_FAKTOR+CB_EMPF_OFFSETT_E6))/16+1)
#define CB_EMPF_FAKTOR_E8        ((CB_EmpfGlobalSkal*(CB_EMPF_FAKTOR+CB_EMPF_OFFSETT_E8))/16+1)
#define CB_EMPF_FAKTOR_E9        ((CB_EmpfGlobalSkal*(CB_EMPF_FAKTOR+CB_EMPF_OFFSETT_E9))/16+1)

#endif /*FORD*/

#define CB_EMPF_FAKTOR_E1        (byte) (((((word)CB_EmpfGlobalSkal* (word)(CB_EMPF_FAKTOR+CB_EMPF_OFFSETT_E1)))/16)/*-1*/)
#define CB_EMPF_FAKTOR_E4        ((CB_EmpfGlobalSkal*(CB_EMPF_FAKTOR+CB_EMPF_OFFSETT_E4))/16)
#define CB_EMPF_FAKTOR_E5        ((CB_EmpfGlobalSkal*(CB_EMPF_FAKTOR+CB_EMPF_OFFSETT_E5))/16)
#define CB_EMPF_FAKTOR_E7        ((CB_EmpfGlobalSkal*(CB_EMPF_FAKTOR+CB_EMPF_OFFSETT_E7))/16)







#define CB_EMPF_FAKTOR_ST2_OFFS_DEF 4 /*10*/


#define CB_EMPF_FAKTOR_ST2_OFFS   rb_Empf_Faktor_ST2_Offs_g


#define CB_EMPF_FAKTOR_ST2_E1        0//9//10//CB_EMPF_FAKTOR_ST2_E6//9//CB_EMPF_FAKTOR_E1+2
#define CB_EMPF_FAKTOR_ST2_E2        1//9//10//CB_EMPF_FAKTOR_ST2_E6//10//CB_EMPF_FAKTOR_E2+2
#define CB_EMPF_FAKTOR_ST2_E3        2//10//11//CB_EMPF_FAKTOR_ST2_E6//11//CB_EMPF_FAKTOR_E3+1
#define CB_EMPF_FAKTOR_ST2_E4        3//CB_EMPF_FAKTOR_ST2_E6//10//11//CB_EMPF_FAKTOR_ST2_E6//12//CB_EMPF_FAKTOR_E4+0
#define CB_EMPF_FAKTOR_ST2_E5        CB_EMPF_FAKTOR_ST2_E6//13//CB_EMPF_FAKTOR_E5-1
#define CB_EMPF_FAKTOR_ST2_E6        4//12//14//CB_EMPF_FAKTOR_E6-2
#define CB_EMPF_FAKTOR_ST2_E7        CB_EMPF_FAKTOR_ST2_E6//15//CB_EMPF_FAKTOR_E5-1
#define CB_EMPF_FAKTOR_ST2_E8        CB_EMPF_FAKTOR_ST2_E6//16//CB_EMPF_FAKTOR_E6-2
#define CB_EMPF_FAKTOR_ST2_E9        CB_EMPF_FAKTOR_ST2_E6+1//15//CB_EMPF_FAKTOR_E5-1




//Entladeschleifen fur Intervalspeicher
//************************************************************************

#define  CB_DEC_INT_SP_OFFS_E1   4//3//5        //Die Werte werden in Abhaengigkeit der gewaehlten
#define  CB_DEC_INT_SP_OFFS_E2   5//6//8        //Empfindlichkeitsstufe zu der Konstanten
#define  CB_DEC_INT_SP_OFFS_E3   7//10//12         //c_Dec_Int_Speicher addiert
#define  CB_DEC_INT_SP_OFFS_E4   10//12//15
#define  CB_DEC_INT_SP_OFFS_E5   12//13//15
#define  CB_DEC_INT_SP_OFFS_E6   14//15//13//15
#define  CB_DEC_INT_SP_OFFS_E7   16//15
#define  CB_DEC_INT_SP_OFFS_E8   18//13//15
#define  CB_DEC_INT_SP_OFFS_E9   20//13//15

/*Schwellen im Intervalbetrieb*/
/************************************************************************/
/*!!!Should be lower than 400  overflow caould occour*/
#define   CW_SCHWELLE_MIN_E1     260  //40ms Schwelle
#define   CW_SCHWELLE_MIN_E2     250  //
#define   CW_SCHWELLE_MIN_E3     200  //"
#define   CW_SCHWELLE_MIN_E4     180  //"
#define   CW_SCHWELLE_MIN_E5     140 //"
#define   CW_SCHWELLE_MIN_E6     120  //"
#define   CW_SCHWELLE_MIN_E7     110  //"
#define   CW_SCHWELLE_MIN_E8     105  //"
#define   CW_SCHWELLE_MIN_E9     105  //"


//Parameter fuer Ansammlungszeit
//************************************************************************

#define CB_SIG_ANS_SCHW_OFFS_DEF   195
#define CW_SIG_ANS_SCHW_OFFS  (word)(rb_sig_ans_schw_offs_g)


#define CB_DEC_SIGSP_ANS        254            //Entladefaktor fuer Ansammlungszeit Signalspeicher
                                               //(Schleifenzahler 10ms)
                                               //Signalspeicher wird all X*10ms verringert.

/*************************************************************************
**                Ueberwischausblendung Werte fur Schwelle              **
**************************************************************************/
#define  CW_SCHWELLE_LONG_INT   3400
#define  CW_SCHWELLE_START      3200//3300//3200         //Startwert fuer Intervallbetrieb
#define  CW_SCHWELLE_05         3000//3300//3200         //Startwert fuer kurzes Interval und Nachwischungen
#define  CW_SCHWELLE_DAUER      2600//2800//2600         //Schwelle fuer Dauerbetrieb



#define   CB_DEC_SCHWELLE        100          //Entladekonstante fuer Schwelle
                                             //40ms Raster
//Verzogerte UberwischSchwelle bei Nachwischungen
#define  CW_INC_SCHWELLE       440//350//250  //Ladekonstante fur Schwelle bei Nachwischungen
                                             //40ms Raster

/*************************************************************************
**                Signallaengen, Signalspeicher UND  Begrenzung         **
**************************************************************************/

#define  CW_MAX_SIGNALLAENGE_DEF    200      //max. Signallaenge in ms -> Achtung Byte

#define CW_MAX_SIGNALLAENGE   rb_Max_Signallaenge_g


#define  CW_MAX_SIGSP_FAKT      3600      //max. Wert fuer faktorisiertern Wert von
//"c_max_SignalSpeicher"
// c_max_SignalSpeicher*rub_Empf_Fakt"

#define CB_DEC_SIGINT_SPEICHER    5        //Entladefaktor Signalspeicher
//Multiplikator
                                          //Aenderung der Empfindlichkeit fuer Intervall
                                          //und Dauerwischen. Dieser Wert hat keinen
                                          //Einfluss auf Stufe2
                                          //je groesse, desto schneler wird entladen


/*************************************************************************
**                Intervall- und Overridespeicher                       **
**************************************************************************/
#define  CB_OVR_STARTWERT       120        //Startwert fuer Overridespeicher

#define  CB_MAX_SP_TROCK_WISCH  130        //oberer Wert nach Trockenwischen
                                           //-> aus Dauerwischen

#define  CB_EMPF_ANPASS          37        /*Wert der Bei der Aenderung der
                                           Empfindlichkeit mit den Speichern
                                           verechnet wird fuer ovr-Speicher
                                           wird die haelfte benutzt*/

#define CB_INC_INT_SPEICHER        rb_inc_int_speicher_g     //Schleifenzaehler
                                          //je groesser, desto langsamer wird geladen,
                                          //d.h. desto traeger geht das System ins kurze Interval

#define CB_DEC_INT_SP_OFFS_DEF    20//16//15//  15//12// 14//12//15        //Entladezeit ergibt sich aus der Summe aus

                                          //"c_Dec_Int_Sp_Offs + c_Dec_Int_Sp_Offs_Ex"
                                          //je groesser, desto langsamer wird entladen
                                          //d.h. das System verhaelts ich traeger und
                                          //benoetigt somit laenger um wieder in den
                                          //Urzustand zurueck zu gelangen
#define CB_INC_OVR_SPEICHER        rb_inc_ovr_speicher_g        //Ladefaktor Overridespeicher

#define CB_DEC_OVR_SPEICHER_DEF       10//8//offsett is addet in code beforE 9
//Entladefaktor Overridespeicher
//(Schleifenzaehler)


#define   CB_DEC_OVR_SPEICHER  rb_dec_Ovr_Speicher_g
#define   CB_DEC_INT_SP_OFFS   rb_dec_Int_Sp_off_g

/*************************************************************************
**                Stufe 1 Speicher Schwellen                            **
**************************************************************************/
#ifndef SHORT_INTERVAL_VERSION /*VC075*/
#define  CB_INT_SPEICHER_MAX  (rb_Stufe1_OG_g+8)
#define  CB_STUFE1_MIN_UG     (rb_Stufe1_UG_g-20)                    //to come out of low speed without drywipe
#define  CB_STUFE1_WITH_INT_OG_DEF  80//85
#else
#define  CB_INT_SPEICHER_MAX  (rb_Stufe1_OG_g+10)
#define  CB_STUFE1_MIN_UG     (rb_Stufe1_UG_g-20)                    //to come out of low speed without drywipe
#define  CB_STUFE1_WITH_INT_OG_DEF  45//85
#endif
#define  CB_STUFE1_WITH_INT_OG rb_Stufe1_with_Int_og_g

#define  CB_STUFE1_UG     rb_Stufe1_UG_g


#define  CB_OVR_SPEICHER_MAX  CB_INT_SPEICHER_MAX          //Begrenzung rub_Ovr_Speicher

#ifndef SHORT_INTERVAL_VERSION /*VC075*/
#define  CB_STUFE1_OG   	    212//225//245//215// 175     //oberer Grenzwert fuer Dauerwischen
#define  CB_STUFE1_UG_DEFINITION  185
#else
#define  CB_STUFE1_OG   	    200//225//245//215// 175     //oberer Grenzwert fuer Dauerwischen
#define  CB_STUFE1_UG_DEFINITION  170
#endif

#define  CB_INTSPEICHER_LONG_SENS_REDUCT 30

/*************************************************************************
**          Zustazspeicher zur Verzoegerung des Dauerwischen (FORD_USA)  **
**************************************************************************/

/*************************************************************************
**                X-Speicher fuer Wischerstufen Stufe 2-7               **
**************************************************************************/
/*
Die Folgenden Schwellen werden mit dem rub_Int_Speicher oder ruw_StX_Speicher
verglichen die Berechnung erfolgt in der rainsens.c

Mit den folgenden Werten fuer rub_Intspeicher wird zwangsweise aus den Wischerstufen heruntergeschaltet
Der Bereich zwischen CB_STUFE1_UG und CB_STUFE1_OG ist linear aufgeteilt
*/

#define CB_STUFEX2_UG           (CB_STUFE1_UG+((CB_STUFE1_OG-CB_STUFE1_UG)/5))     // go out from Wiper Speed 2
#define CB_STUFEX3_UG           (CB_STUFE1_UG+((2*(CB_STUFE1_OG-CB_STUFE1_UG))/5)) // go out from Wiper Speed 3
#define CB_STUFEX4_UG           (CB_STUFE1_UG+((3*(CB_STUFE1_OG-CB_STUFE1_UG))/5)) // go out from Wiper Speed 4
#define CB_STUFEX5_UG           (CB_STUFE1_UG+((4*(CB_STUFE1_OG-CB_STUFE1_UG))/5)) //go out from Wiper Speed 5
#define CB_STUFEX6_UG           CB_STUFE1_OG // go out from Wiper Speed 6 or 7

//Maximum Counted Raindroplenght for rub_Stx_Speicher and rub_St1_Speicher
#define  CB_MAX_ST1_SIGNALLAENGE CW_MAX_SIGNALLAENGE  
#define  CW_MAX_STX_SPEICHER     63000           //Maximum Value for X-Speed Memory

#define  CB_DEC_STX_SPEICHER     57               //Decrement Value for X-Speed Memory (10ms)
#define cb_STUFE_X_DECREMENT_DIVIDER 3           /*VCO_085 reduce sensitivity and decrement for Stx. Memory*/ 

#ifdef SHORT_INTERVAL_VERSION /*VC075*/
#define  CB_STXSPEICHER_INTERVAL_MAX 3000        //highest Startvalue in Low Speed Wiping
#define  CW_SCHWELLE_STUFE1      10000          //Threshold for X - Speed1  not used
#define  CW_SCHWELLE_STUFE2      19500           //Threshold for X - Speed2
#else
#define  CB_STXSPEICHER_INTERVAL_MAX 6000        //highest Startvalue in Low Speed Wiping
//#define  CW_SCHWELLE_STUFEX1      15000        //Threshold for X - Speed1  not used
#define  CW_SCHWELLE_STUFE2      18500           //Threshold for X - Speed2
#endif
#define  CW_SCHWELLE_STUFE3      25500           //Threshold for X - Speed3
#define  CW_SCHWELLE_STUFE4      35500           //Threshold for X - Speed4
#define  CW_SCHWELLE_STUFE5      44000           //Threshold for X - Speed5
#define  CW_SCHWELLE_STUFE6      52000           //Threshold for X - Speed6
#define  CW_SCHWELLE_STUFE7      59000           //Threshold for X - Speed6
#define CW_SCHWELLE_STUFEX_OFFSETT 4500          //Hysteresies for changing Wiper Speed
#define  CB_WIPEDECREMENT_STX    280//50         //Decrement Value per Wipe for ruw_StX_Speicher




/*************************************************************************
**                  Speicher fuer Stufe2                                **
**************************************************************************/
#define  CB_MAX_ST2_SIGNALLAENGE   cb_E2_MaxSt2SignalLaenge_g//180 //Wert bei denen der SigSt2Speicher nicht mehr geladen wird und langsam entladen

#define  CB_SIGPAUSE_ST2_MAX       10        //max. Signalpause vor Umschalten
                                            //auf Stufe 2
#define  CW_MAX_ST2_SPEICHER       13500    //obere Begrenzung des ruw_St2_Speicher
//    6300      //5500//6000//4500//5300 // 6100//5900//6600//7600//bis 06.09.01    6000  //bis 05.09.01 4500
#define  CW_ST2_OG            5696
                                 //Schwelle fuer ruw_St2_Speicher bei der nach Delay in Schnell Wischen geschaltet wird

#define  CB_ST2_UG               500// 825//750   //900//750//500// 630 //750  //bis 05.09.01  500
                                     //Schwelle fuer ruw_St2_Speicher bei der Schnell Wischen nach Delay verlassen wird

#define CB_EP_ST2_EPR_STARTVALUE  127       //Startwert fuer Stufe2 Entprellvariable

#define CB_EP_ST2_EPR_IN_ST2     (CB_EP_ST2_EPR_STARTVALUE + 26)//30//ca. 1sec   30 // Value to go into High speed
#define CB_EP_ST2_EPR_OUT_ST2    (CB_EP_ST2_EPR_STARTVALUE - 5)                    // Value to go out of high speed
#define CB_EP_ST2_EPR_LS_SPLASH  (CB_EP_ST2_EPR_STARTVALUE +3)//+ 15                // Value to go direct in lowspeed

#define  CB_DEC_ST2_SPEICHER      rb_dec_st2_speicher_g//40//50      /*bis 05.09.01 40*/

#define  CB_ST2_WISCH_MIN          0//1//4         //min. Anzahl der Wischzyklen in Stufe2

// Folgende Werte sind fuer die Entprellvariable rub_St2_Epr:
// Vergleichwerte zum Stufe 2-Speicher! Der Entprellzaehler wird nach erfolger Entprellung auf den Startwert gesetzt
#define CW_ST2_EPR_UG 1000             // Unterer Grenzwert fuer rub_St2_Epr=127
#define CW_ST2_EPR_OG CW_ST2_OG        // Oberer Grenzwert fuer rub_St2_Epr=127

// Um die Entprellvariable auf den neutralen Wert von 127 zu setzen:
// 255 aus irgendeinem Zustand auf Stufe 2 ----- 0 aus Stufe 2 auf Stufe 1 zurueck


/*************************************************************************
**                  Konstanten fuer die Intervallbestimmung             **
**************************************************************************/
// Intervallzeiten (40ms Zeitraster)
// max. Werte 255 -> 10.2s max. Intervallzeit

#define   CB_INTERMDELAY_DIREKT    0xFF       //Wert fuer Direktbetrieb

#define   CB_INTERMDELAY_MAX     180        //max. Intervallzeit (7.2s) maximale Nachwischzeit die bei der
                                           //Verlaengerung der Intervalzeit eingestellt wird


#define   CB_FIX_INTERVALBREAK         5     /*FIX Interval Pause for FIX Interval CB_2_5SECONDSDELAY*/
//Array zur Intervalzeitbestimmung in Abhaengigkeit von der Empfindlichkeitseinstellung und des
//rub_Intspeicher bzw. rub_Ovrspeicher

extern const unsigned char cab_INTERMDELAY[9][9];
extern const unsigned char cab_INTERMDELAY_2[9][9];


//Konstanten fuer rub_Int_Speicher mit den folgenden Variablen wird der Uebergabewert von rub_IntTab() unterteilt
//in die Intervalzeiten von cab_INTERMDELAY[8][8]
#define CB_INTERVAL_AREA           19                           // Der Speicher ist in 8 Abschnitte geteilt 125 durch 7
#define CB_INTERVALL_GRENZE        ((CB_INTERVAL_AREA*8)-1) // die oberen zwei Bereiche werden zu einem zusammengefasst
#define CB_MAX_NUMBER_OF_INTAREAS   8     /*number of interval areas*/

/*************************************************************************
**                  Schwellen fuer Nachwischzyklen                      **
**************************************************************************/

#define   CB_NACHWISCH_4_DEF   15                  //4 Wischungen, wenn Intervall-Zeit kleiner/gleich
                                            //Wert <  c_IntermDelay_min -> keine Wischung
#define   CB_NACHWISCH_3_DEF   23                 //3 Wischungen, ... if intermdelay_min <= 600ms

#define   CB_NACHWISCH_2_DEF   75                 //2 Wischungen, ...
                                            //1 Wischung erfolgt automatisch bei gueltigem Signal!
#define CB_NACHWISCH_NIGHT_INTTAB_DEC 12 //
//#define  CB_ANZAH_NW_VERL  3//2                 //Bei weniger als CB_ANZAH_NW_VERL Nachwischungen,
 //wird die Intervallzeit verlaengert wenn keine trockenwischung oder rub_intspeicher nicht ganz voll
#define  CB_ST1_NACHWISCH_MIN_DEF    3          //min. Nachwischungen nach umschalten von Dauerwischen auf Intervall


#if defined(AUDI_B8)
/*this is the devider of the last intervaltime the new intervaltime will be 
  (1+1/CB_AFTERWIPE_0_INCREASE_DIVIDER)*lastintervaltime)*/
#define CB_AFTERWIPE_0_INCREASE_DIVIDER 8 
#else
/*this is the devider of the last intervaltime the new intervaltime will be 
  (1+1/CB_AFTERWIPE_0_INCREASE_DIVIDER)*lastintervaltime)*/  
#define CB_AFTERWIPE_0_INCREASE_DIVIDER 255 
#endif
/*this is the devider of the last intervaltime the new intervaltime will be 
  (1+1/CB_AFTERWIPE_1_INCREASE_DIVIDER)*lastintervaltime)*/  
#define CB_AFTERWIPE_1_INCREASE_DIVIDER 4 
/*this is the devider of the last intervaltime the new intervaltime will be 
  (1+1/CB_AFTERWIPE_2_INCREASE_DIVIDER)*lastintervaltime)*/  
#define CB_AFTERWIPE_2_INCREASE_DIVIDER 2 


#define   CB_NACHWISCH_4   rb_Nachwisch_4_g      /*4 Wischungen, wenn Intervall-Zeit kleiner/gleich
                                               Wert <  c_IntermDelay_min -> keine Wischung*/

#define   CB_NACHWISCH_3   rb_Nachwisch_3_g      /*3 Wischungen, ... if intermdelay_min <= 600ms*/

#define   CB_NACHWISCH_2   rb_Nachwisch_2_g      /*2 Wischungen, ...*/
                                          /*1 Wischung erfolgt automatisch bei gueltigem Signal!*/
   /*min. Nachwischungen nach umschalten von Dauerwischen auf Intervall*/
#define  CB_ST1_NACHWISCH_MIN     rb_ST1_Nachwisch_min_g 




/*************************************************************************
**                  Schwellen und Werte fuer min. Signallaenge          **
**************************************************************************
    Schwellen und Werte fuer min. Signallaenge
    mit zunehmender Wischfrequenz soll das System unempfindlicher
    auf kleine Tropfen werden. Tropfen , die groesser sind,
    werden normal behandelt.
    Werte in ms/Empf-Faktor, bereits multipliziert mit Empf-Faktor
**************************************************************************/
#define  CB_SHORT_SIG_PAUSE  5          //rbi_Signal_min_Ok wird gesetzt wenn rub_Sig_Pause <= CB_SHORT_SIG_PAUSE*10ms

#define  CB_SIG_MIN_WERT1_DEF     25//45//40//50//70//100//20        //Wert fuer Intervallzeit < c_IntermDelay_1
#define  CB_SIG_MIN_WERT2_DEF     30  //c_IntermDelay_1 < Wert fuer Intervallzeit < c_IntermDelay_3
#define  CB_SIG_MIN_WERT3_DEF     35  //c_IntermDelay_3 < Wert fuer Intervallzeit < c_IntermDelay_5
#define  CB_SIG_MIN_WERT4_DEF     40//250//220//475//490//250         //c_IntermDelay_5 < Wert fuer Intervallzeit


#define  CB_SIG_MIN_WERT1    CB_SIG_MIN_WERT1_DEF        //Wert fuer Intervallzeit < c_IntermDelay_1
#define  CB_SIG_MIN_WERT2     CB_SIG_MIN_WERT2_DEF  //c_IntermDelay_1 < Wert fuer Intervallzeit < c_IntermDelay_3
#define  CB_SIG_MIN_WERT3    CB_SIG_MIN_WERT3_DEF    //c_IntermDelay_3 < Wert fuer Intervallzeit < c_IntermDelay_5
#define  CB_SIG_MIN_WERT4     CB_SIG_MIN_WERT4_DEF        //c_IntermDelay_5 < Wert fuer Intervallzeit
  
  
  // die folgenden Werte werden anstatt der o.g Werte benutzt bei sehr niedriger Empfindlichkeit
#define CB_SIG_MIN_WERT_LOW_FAKT_WERT1   12//20
#define CB_SIG_MIN_WERT_LOW_FAKT_WERT2   22//45
#define CB_SIG_MIN_WERT_LOW_FAKT_WERT3   32//70
#define CB_SIG_MIN_WERT_LOW_FAKT_WERT4   40//85
  
  // Die Folgenden Variabeln werden Benutzt um den Wert fuer die Mindestsignallaenge
  // abhaengig von der intervalzeit zu setzen siehe rs_sig_min.c
  
#define   CB_INTERMDELAY_1         105  //4,2s     Intervallzeit 1   0-15
  //#define   CB_INTERMDELAY_2         90   //3,6s     Intervallzeit 2  15-30
#define   CB_INTERMDELAY_3         77   //3,1s     Intervallzeit 3  45-60
  //#define   CB_INTERMDELAY_4         54   //2,6s     Intervallzeit 4  65-80
#define   CB_INTERMDELAY_5         50   //2s       Intervallzeit 4  80-95
  //#define   CB_INTERMDELAY_6         36   //1,5s     Intervallzeit 4  95-110
  //#define   CB_INTERMDELAY_7         25   //1s       Intervallzeit 5  110-125
  //#define   CB_INTERMDELAY_MIN       10   //0,5s-busdelay  Intervallzeit 9 120-max
  
  /*************************************************************************
  **                  Tropfen Auswertung                                  **
  **************************************************************************/
  
#define  CB_SIG_COUNT_PAUSE_MIN	   3	  //Wert fuer min. Pausenzeit zwischen zwei Signalen,
                                          //damit diese als verschiedene Tropfen gewertet werden
                                          //Multiplikator 10ms => 100ms

#define  CB_TROPF_COUNT_MIN 	     2      //min. Wert fuer entprellte Tropfensignale waehrend
                                          //einer Wischung

#define  CB_SIG_ANZAHL_MIN		  3       //Ab dieser Signalanzahl, wird keine Trockenwischung gewertet
#define  CB_SIG_ANZAHL_ST1_MIN	  4		  //Ab dieser Signalanzahl, wird keine Trockenwischung gewertet

#define  CB_TROCK_WISCH_MAX_INT    3//3      //Anzahl der max. Trockenwischungen	Intervallbetrieb
#define  CB_TROCK_WISCH_MAX_CONT   5//5      //Anzahl der max. Trockenwischungen Dauerbetrieb

#define  CB_INT_SPEICHER_DEC_AT_DRYWIPE 1 /*decrement value of intspeicher for high value at detected drywipe */
#define  CB_OVR_SPEICHER_DEC_AT_DRYWIPE 2   /*decrement value of intspeicher for high value at detected drywipe */
/*VCO_084 drywipe decrement on Ovr_Speicher and Int_Speicher depending on sensitivity level*/
#define  CB_INT_SPEICHER_DEC_AT_DRYWIPE_HIGH 3 /*decrement value of intspeicher for high value at detected drywipe */
#define  CB_OVR_SPEICHER_DEC_AT_DRYWIPE_HIGH 5   /*decrement value of intspeicher for high value at detected drywipe */


/*************************************************************************
**               Time Out fuer Diagnosezaehler                          **
**************************************************************************/

#define  CW_DIA_TIMEOUT_PRECHECK 0 

#define CW_DIA_TIMOUT_LOOPTEST  500   
#define  CW_DIA_TIMEOUT           (CW_DIA_TIMOUT_LOOPTEST + CW_DIA_TIMEOUT_PRECHECK)  //max. Wert fuer Diagnose-Zaehler
 
                                            //254 => 3s Timeout

/*************************************************************************
**               Taskzeiten                                             **
**************************************************************************/
#define  CB_TASK_MIN          10              //Taskzeit in ms (Task10)
#define  CB_TASK_DIFFERENZ    (40/CB_TASK_MIN)  //Verhaeltnis der Taskzeiten Task40/Task10
#define CB_MAX_SIGNALLENGTH   CB_TASK_MIN     //Max. Signallaenge beim 10ms Task

/*************************************************************************
**               Motorlaufzeit                                          **
**************************************************************************/
#define  CB_DELAY_AUSBL_VORGABE  25       //75% von normaler Motorlaufzeit
                                          //zur Initilisierung von rub_Delay_Ausbl
                                          //=> 25*40ms => 1s
#endif
