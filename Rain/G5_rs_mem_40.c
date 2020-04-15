/******************************************************************************
*******************************************************************************
**
** Funktion:   Mem_40()
**
**
** Bearbeiter: Bernd Schmid Abt. TKW
** Datum:      25.03.98
** geaendert:  21.04.98
**
** Funktion:   Laden und Entladen der Speicher in Abhaengigkeit von der
**             Schwelle und der aufintegrierten Signallaenge.
**             (rub_Sig_Ok_Count)
**
**             Intervallspeicher: Speicher mit langen Lade-und Entladezeiten
**                                stark integrierendes Verhalten
**                                Verantworlich fuer den harmonischen Betrieb
**
**             Overridespeicher:  Speicher mit kurzen Lade-und Entladezeiten
**                                Verantworlich fuer kurze Anspruchzeiten
**
**             Mit Hilfe des Zaehlers fuer gueltige Signale "rub_Sig_Ok_Count"
**             koennen Signalaenderungen zwischen den 40ms Task Aufrufen
**             nachgearbeitet werden.
**             Der Zaehler wird in der Routine "Signal()" bearbeitet und wird
**             nach der Auswertung, in mem_40() geloescht.
**
**
*******************************************************************************
******************************************************************************/
/* History                                                                    */
/*----------------------------------------------------------------------------*/
/* Date      VDR_Number     Description                                       */
/*----------------------------------------------------------------------------*/
/* 03.05.10  VDR_511    AL   avoid overflow*/
/* 28.09.09	 VDR_375    AL 	 do not decrement memorys during Washing */
/* 27.11.08	 VDR_296 	 Posche: The Rainsensor should be more sensitive in different conditions*/
/* 27.11.2014   VCO_200    NB      move rb_LimitMemomryNoWiperReaction_g variable from G5_sci.h to G5_rs_mem_40.h */
/* 01.04.15  VDR_866  MP    Remove of rainsens.c for no-rain-variants*/
/******************************************************************************/

#include "G5_rs_mem_40.h"
#include "G5_rs_def.h"
#include "G5_IRlight.h"
#include "G5_rs_task.h"
#include "G5_rainsens.h"
#include "G5_rs_ext.h"
/******************************************************************************
**
** void Empf_OverwipeLimitation(void)
**
** Bearbeiter: Bernd Schmid Abt. TKW
** Datum:      25.03.1998
**
** Function:   Loads and reduces the for  slow and fast interval memory
**
**
**
******************************************************************************/

unsigned char rb_LimitMemomryNoWiperReaction_g;


void Mem_40(void)
{
  //declaration of local varibles
  unsigned char rub_Dummy;
  unsigned char rub_Ovr_Potioffset_l;
  //- Speicher laden ?
  //-=================
  
  if(rub_Sig_Ok_Count > 0)      //any valid signal
  {
    //-gueltige Signale vorhanden -> Speicher laden
    //-============================================
    //-Intervall Speicher laden
    //--------------------------
    //rub_Dummy = rub_Sig_Ok_Count; //store count of valid signals in temp variable
    
    if ((rub_IntermDelayTime > 25 )&& (rbi_IntSpInc_Scal_longerInt_enabled_g))
    {
      
      rub_Dummy = (byte)(((4+rb_IntSpInc_Scal_g)*(word)(rub_Sig_Ok_Count))>>2); /*VDR_511 avoid overflow*/
    }
    else
    {
      /*count less signals for more wiping*/
      rub_Dummy = (byte)(((3+rb_IntSpInc_Scal_g)*(word)(rub_Sig_Ok_Count))>>2); /*VDR_511 avoid overflow*/
      
    }
    
    
    while(rub_Dummy > 0)          //is temp variable > 0
    {
      
      if(rub_Inc_Int_Sp_Count < CB_INC_INT_SPEICHER)//is Int_SP_Counter lower than inc. Value for slow interval memory?
        
      {
        rub_Inc_Int_Sp_Count++;                      //increment Int_SP_Counter
      }
      else
      {
        rub_Inc_Int_Sp_Count=0;                      //Reset Int_SP_Counter
        if(rub_Int_Speicher < CB_INT_SPEICHER_MAX)   //is slow interval memory at maximum
        {
          rub_Int_Speicher++;                       //increment slow interval memory
        }
      }
      rub_Dummy--;         //decrement temp variable
    }
    
    //-Override Speicher laden
    //------------------------
    rub_Dummy = ((3+rb_OvrInc_Scal_g)*rub_Sig_Ok_Count)>>2;   //store count of valid signals in temp variable
    
    while(rub_Dummy > 0)            //is temp variable > 0?
    {
      
      if(rub_Inc_Ovr_Sp_Count < CB_INC_OVR_SPEICHER)//is Ovr_SP_Counter lower than inc. Value for fast interval memory?
        
      {
        rub_Inc_Ovr_Sp_Count++;                      //increment Ovr_SP_Counter
      }
      else
      {
        rub_Inc_Ovr_Sp_Count=0;                      //Reset Ovr_SP_Counter
        if(rub_Ovr_Speicher < CB_OVR_SPEICHER_MAX)   //is fast interval memory at maximum
        {
          rub_Ovr_Speicher++;     //increment fast interval memory
        }
      }
      rub_Dummy--;          //decrement temp variable
    }
  }
  //- Speicher entladen ?
  //-====================
  if(rub_Sig_Ok_Count < CB_TASK_DIFFERENZ)              //not in every task over threshold?
  {
    //- Intervall Speicher entladen
    //difference of tasks and valid signals over thresholds in temp variable
    rub_Dummy = CB_TASK_DIFFERENZ-rub_Sig_Ok_Count; 
    while(rub_Dummy > 0)                                   //is temp variable > 0?
    {
      if(rub_Dec_Int_Sp_Count < rub_Dec_Int_Sp)            //is int_SP_DecCounter < time to reduce slow memory?
      {
        rub_Dec_Int_Sp_Count++;                            //increment int_SP_DecCounter
      }
      else
      {
        rub_Dec_Int_Sp_Count=0;                          //clear int_SP_DecCounter
        /*VDR_375*/  //is slow interval memory > 0?
        if((rub_Int_Speicher > 0) &&((rbi_LowVoltage == 0)&&(rbi_WashingActive==0)))
        {
          rub_Int_Speicher--;           //decrement slow interval memory
        }
      }
      rub_Dummy--;                                //decrement temp variable
    }
    // Override Speicher entladen
    //difference of tasks and valid signals over thresholds in temp variable
    rub_Dummy = CB_TASK_DIFFERENZ-rub_Sig_Ok_Count; 
    if (rub_PotiStage > 2)
    {
      //VDR_296 calculate offset for ovrMemory
      rub_Ovr_Potioffset_l = (CB_DEC_OVR_SPEICHER+(4* rbi_Night)+ (rub_PotiStage))-1; 
    }
    else
    {
      rub_Ovr_Potioffset_l = (4* rbi_Night)+CB_DEC_OVR_SPEICHER;
    }

    if (rb_speed_in_kmh_g < 50)
    {
      rub_Ovr_Potioffset_l  = (rub_Ovr_Potioffset_l + 5)-(rb_speed_in_kmh_g/10);//VDR_296
    }
    while(rub_Dummy > 0)          //is temp variable > 0?
    {
      
      if(rub_Dec_Ovr_Sp_Count < (rub_Ovr_Potioffset_l))    //VDR_296 is Ovr_SP_DecCounter < time to reduce fast memory?
        
        
      {
        rub_Dec_Ovr_Sp_Count++;              //increment Ovr_SP_DecCounter
      }
      else
      {
        rub_Dec_Ovr_Sp_Count=0;         //clear Ovr_SP_DecCounter
         /*VDR_375*/ //is fast interval memory > 0?
        if((rub_Ovr_Speicher > 0)&&((rbi_LowVoltage == 0)&&(rbi_WashingActive==0)))  
        {
          rub_Ovr_Speicher--;        //decrement fast interval memory
        }
      }
      
      rub_Dummy--;           //decrement temp variable
    }
  }
  //- max. Speicher Wert sichern, wenn Merker fuer gueltigen Tropfen gesetzt
  
  if (rb_LimitMemomryNoWiperReaction_g > 0)
  {
    if(rub_Int_Speicher > CB_STUFE1_UG)   //is slow interval memory higher than stored maximum value?
    {
      rub_Int_Speicher = CB_STUFE1_UG;   //store slow interval memory in slow maximum value
    }
    
    if(rub_Ovr_Speicher > CB_STUFE1_UG)   //is fast interval memory higher than stored maximum value?
    {
      rub_Ovr_Speicher = CB_STUFE1_UG;   //store fast interval memory in fast maximum value
    }
  }
  
  if(rbi_Tropfen_Merker==1)                    //Valid drop detected?
  {
    //-max. Wert fuer Intervallspeicher/Overridespeicher sichern
    
    if(rub_Int_Speicher > rub_Speicher_max)   //is slow interval memory higher than stored maximum value?
    {
      rub_Speicher_max = rub_Int_Speicher;   //store slow interval memory in slow maximum value
    }
    
    if(rub_Ovr_Speicher > rub_Speicher_max)   //is fast interval memory higher than stored maximum value?
    {
      rub_Speicher_max = rub_Ovr_Speicher;   //store fast interval memory in fast maximum value
    }
    
  }
  //- Variable ruecksetzen;
  rub_Sig_Ok_Count=0;  //reset count value for signals
}










