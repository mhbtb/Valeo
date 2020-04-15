#ifndef G5_DIAGE2MAPPING_RD_H
#define G5_DIAGE2MAPPING_RD_H
/* PRQA S 3619 EOF */ /* << 2010 01 08, compiler allows whitespaces:due to readable code, keep whitespaces! >> */
/* PRQA S 2217 EOF */ /* << 2011 03 03, Code would be not readable >> */
/* PRQA S 750,759 EOF *//*<< 0750:union needed to reduce RAM usage >>*/
/* PRQA S 1015 EOF *//*<< 1015:__far needed for IAR compiler  >>*/
/* PRQA S 3453 EOF *//*<< Macro is more readle and convinient in this situation >>*/
/* PRQA S 857 EOF *//*<< Macro exceeds 1024 number  >>*/


/******************************************************************************/
/* History                                                                    */
/*----------------------------------------------------------------------------*/
/* Date      VDR_Number     Description                                       */
/*13.05.2015 VCO_192    NB    Audi: Activation and deactivation of Interval Operation  */
/*09.11.15   VCO_282    NB    All:Add spare LIN IDs in the EEPROM                      */


/******************************************************************************/



#define cb_NumberofEEPROMCells_RD_g 31   


#define CB_DEF_STBY_REGV_HB  0x00
#define CB_MIN_STBY_REGV_HB  0x00
#define CB_MAX_STBY_REGV_HB  0x10

#define CB_DEF_STBY_REGV_LB  0x00
#define CB_MIN_STBY_REGV_LB  0x00
#define CB_MAX_STBY_REGV_LB  0xFF

#define CB_DEF_STBY_DELTA_INTV_HB  0x09
#define CB_MIN_STBY_DELTA_INTV_HB  0x02
#define CB_MAX_STBY_DELTA_INTV_HB  0x09

#define CB_DEF_STBY_DELTA_INTV_LB  0x25
#define CB_MIN_STBY_DELTA_INTV_LB  0x00
#define CB_MAX_STBY_DELTA_INTV_LB  0xFF

#define CB_DEF_INTERVALS_WAS_ACTIVE               0x00
#define CB_MIN_INTERVALS_WAS_ACTIVE               0x00
#define CB_MAX_INTERVALS_WAS_ACTIVE               0xff

#define CB_DEF_WATCHDOGRESETCOUNTER         0
#define CB_MIN_WATCHDOGRESETCOUNTER         0
#define CB_MAX_WATCHDOGRESETCOUNTER         0xff


#define CB_DEF_SENSOR_ERRORX                0x00
#define CB_MIN_SENSOR_ERRORX                0x00
#define CB_MAX_SENSOR_ERRORX                0xff

/*Incidence Counter*/ /*VCO_31 definition of default values new EEPROM definition*/
#define CB_DEF_INCIDENTCOUNTER1 0
#define CB_MIN_INCIDENTCOUNTER1 0
#define CB_MAX_INCIDENTCOUNTER1 0xFF
/*Incidence Counter*/
#define CB_DEF_INCIDENTCOUNTER2 0
#define CB_MIN_INCIDENTCOUNTER2 0
#define CB_MAX_INCIDENTCOUNTER2 0xFF
/*Incidence Counter*/
#define CB_DEF_INCIDENTCOUNTER3 0
#define CB_MIN_INCIDENTCOUNTER3 0
#define CB_MAX_INCIDENTCOUNTER3 0xFF
/*Incidence Counter*/
#define CB_DEF_INCIDENTCOUNTER4 0
#define CB_MIN_INCIDENTCOUNTER4 0
#define CB_MAX_INCIDENTCOUNTER4 0xFF
/*Incidence Counter*/
#define CB_DEF_INCIDENTCOUNTER5 0
#define CB_MIN_INCIDENTCOUNTER5 0
#define CB_MAX_INCIDENTCOUNTER5 0xFF
/*Incidence Counter*/
#define CB_DEF_INCIDENTCOUNTER6 0
#define CB_MIN_INCIDENTCOUNTER6 0
#define CB_MAX_INCIDENTCOUNTER6 0xFF
/*Incidence Counter*/
#define CB_DEF_INCIDENTCOUNTER7 0
#define CB_MIN_INCIDENTCOUNTER7 0
#define CB_MAX_INCIDENTCOUNTER7 0xFF

#define CB_DEF_LS_RS_ERROR_ACTIVE1 0
#define CB_MIN_LS_RS_ERROR_ACTIVE1 0
#define CB_MAX_LS_RS_ERROR_ACTIVE1 0xFF

#define CB_DEF_LS_RS_ERROR_ACTIVE2 0
#define CB_MIN_LS_RS_ERROR_ACTIVE2 0
#define CB_MAX_LS_RS_ERROR_ACTIVE2 0xFF

#define CB_DEF_LIGHTLS_ERROR_ACTIVE1 0
#define CB_MIN_LIGHTLS_ERROR_ACTIVE1 0
#define CB_MAX_LIGHTLS_ERROR_ACTIVE1 0xFF

#define CB_DEF_RAINRS_ERROR_ACTIVE1 0
#define CB_MIN_RAINRS_ERROR_ACTIVE1 0
#define CB_MAX_RAINRS_ERROR_ACTIVE1 0xFF

#define CB_DEF_GAINOFFSET_E2 0
#define CB_MIN_GAINOFFSET_E2 0
#define CB_MAX_GAINOFFSET_E2 0xFF

#define CB_DEF_RELEASE_INTERVAL_MARKER 0x00
#define CB_MIN_RELEASE_INTERVAL_MARKER 0x00
#define CB_MAX_RELEASE_INTERVAL_MARKER 0xFF

#define CB_DEF_SENS_CONFIG_DATA 0x00
#define CB_MIN_SENS_CONFIG_DATA 0x00
#define CB_MAX_SENS_CONFIG_DATA 0xFF

#define CB_DEF_RESF 0x00
#define CB_MIN_RESF 0x00
#define CB_MAX_RESF 0xFF

#define CB_DEF_NOM_DELTA_INTV 0xFF
#define CB_MIN_NOM_DELTA_INTV 0x00
#define CB_MAX_NOM_DELTA_INTV 0xFF

#define CB_DEF_THR_DELTA_INTV 0xC8
#define CB_MIN_THR_DELTA_INTV 0x00
#define CB_MAX_THR_DELTA_INTV 0xFF


#ifdef _DIAGNOSE_c_
#define EXTERN /**/
#pragma constseg="BOOTSEG_TWO"             
const byte __far cb_EEPROMDataDefaultMinMax_RD_g[cb_NumberofEEPROMCells_RD_g][3] = {
  
  {CB_DEF_STBY_REGV_HB                   ,CB_MIN_STBY_REGV_HB                   ,CB_MAX_STBY_REGV_HB            },/*768*/ 
  {CB_DEF_STBY_REGV_LB                   ,CB_MIN_STBY_REGV_LB                   ,CB_MAX_STBY_REGV_LB            },/*769*/
  {CB_DEF_STBY_DELTA_INTV_HB             ,CB_MIN_STBY_DELTA_INTV_HB             ,CB_MAX_STBY_DELTA_INTV_HB      },/*770*/
  {CB_DEF_STBY_DELTA_INTV_LB             ,CB_MIN_STBY_DELTA_INTV_LB             ,CB_MAX_STBY_DELTA_INTV_LB      },/*771*/
  {CB_DEF_INTERVALS_WAS_ACTIVE           ,CB_MIN_INTERVALS_WAS_ACTIVE           ,CB_MAX_INTERVALS_WAS_ACTIVE    },/*772*/
  {CB_DEF_WATCHDOGRESETCOUNTER           ,CB_MIN_WATCHDOGRESETCOUNTER           ,CB_MAX_WATCHDOGRESETCOUNTER    },/*773*/
  {CB_DEF_SENSOR_ERRORX                  ,CB_MIN_SENSOR_ERRORX                  ,CB_MAX_SENSOR_ERRORX           },/*774*/
  {CB_DEF_SENSOR_ERRORX                  ,CB_MIN_SENSOR_ERRORX                  ,CB_MAX_SENSOR_ERRORX           },/*775*/
  {CB_DEF_SENSOR_ERRORX                  ,CB_MIN_SENSOR_ERRORX                  ,CB_MAX_SENSOR_ERRORX           },/*776*/
  {CB_DEF_SENSOR_ERRORX                  ,CB_MIN_SENSOR_ERRORX                  ,CB_MAX_SENSOR_ERRORX           },/*777*/
  {CB_DEF_SENSOR_ERRORX                  ,CB_MIN_SENSOR_ERRORX                  ,CB_MAX_SENSOR_ERRORX           },/*778*/
  {CB_DEF_SENSOR_ERRORX                  ,CB_MIN_SENSOR_ERRORX                  ,CB_MAX_SENSOR_ERRORX           },/*779*/
  {CB_DEF_INCIDENTCOUNTER1               ,CB_MIN_INCIDENTCOUNTER1               ,CB_MAX_INCIDENTCOUNTER1        },/*780*/
  {CB_DEF_INCIDENTCOUNTER2               ,CB_MIN_INCIDENTCOUNTER2               ,CB_MAX_INCIDENTCOUNTER2        },/*781*/
  {CB_DEF_INCIDENTCOUNTER3               ,CB_MIN_INCIDENTCOUNTER3               ,CB_MAX_INCIDENTCOUNTER3        },/*782*/
  {CB_DEF_INCIDENTCOUNTER4               ,CB_MIN_INCIDENTCOUNTER4               ,CB_MAX_INCIDENTCOUNTER4        },/*783*/
  {CB_DEF_INCIDENTCOUNTER5               ,CB_MIN_INCIDENTCOUNTER5               ,CB_MAX_INCIDENTCOUNTER5        },/*784*/
  {CB_DEF_INCIDENTCOUNTER6               ,CB_MIN_INCIDENTCOUNTER6               ,CB_MAX_INCIDENTCOUNTER6        },/*785*/
  {CB_DEF_INCIDENTCOUNTER7               ,CB_MIN_INCIDENTCOUNTER7               ,CB_MAX_INCIDENTCOUNTER7        },/*786*/
  {CB_DEF_LS_RS_ERROR_ACTIVE1            ,CB_MIN_LS_RS_ERROR_ACTIVE1            ,CB_MAX_LS_RS_ERROR_ACTIVE1     },/*787*/
  {CB_DEF_LS_RS_ERROR_ACTIVE2            ,CB_MIN_LS_RS_ERROR_ACTIVE2            ,CB_MAX_LS_RS_ERROR_ACTIVE2     },/*788*/
  {CB_DEF_LIGHTLS_ERROR_ACTIVE1          ,CB_MIN_LIGHTLS_ERROR_ACTIVE1          ,CB_MAX_LIGHTLS_ERROR_ACTIVE1   },/*789*/
  {CB_DEF_RAINRS_ERROR_ACTIVE1           ,CB_MIN_RAINRS_ERROR_ACTIVE1           ,CB_MAX_RAINRS_ERROR_ACTIVE1    },/*790*/
  {CB_DEF_GAINOFFSET_E2                  ,CB_MIN_GAINOFFSET_E2                  ,CB_MAX_GAINOFFSET_E2           },/*791*/
  {CB_DEF_RELEASE_INTERVAL_MARKER        ,CB_MIN_RELEASE_INTERVAL_MARKER        ,CB_MAX_RELEASE_INTERVAL_MARKER },/*792*/
  {CB_DEF_SENS_CONFIG_DATA               ,CB_MIN_SENS_CONFIG_DATA               ,CB_MAX_SENS_CONFIG_DATA        },/*793*/
  {CB_DEF_SENS_CONFIG_DATA               ,CB_MIN_SENS_CONFIG_DATA               ,CB_MAX_SENS_CONFIG_DATA        },/*794*/
  {CB_DEF_SENS_CONFIG_DATA               ,CB_MIN_SENS_CONFIG_DATA               ,CB_MAX_SENS_CONFIG_DATA        },/*795*/
  {CB_DEF_RESF                           ,CB_MIN_RESF                           ,CB_MAX_RESF                    },/*796*/
  {CB_DEF_NOM_DELTA_INTV                 ,CB_MIN_NOM_DELTA_INTV                 ,CB_MAX_NOM_DELTA_INTV          },/*797*/
  {CB_DEF_THR_DELTA_INTV                 ,CB_MIN_THR_DELTA_INTV                 ,CB_MAX_THR_DELTA_INTV          } /*798*/
};

#else



extern const byte __far cb_EEPROMDataDefaultMinMax_RD_g[cb_NumberofEEPROMCells_RD_g][3];
#define EXTERN  extern
#endif


typedef struct {
  
   
  byte STBY_REGV_HB_g ;                       /*768*/ 
  byte STBY_REGV_LB_g ;                       /*769*/ 
  byte STBY_DELTA_INTV_HB_g ;                 /*770*/ 
  byte STBY_DELTA_INTV_LB_g ;                 /*771*/ 
  byte IntervalIsWasActive_g ;                /*772*/
  byte WatchdogResetCounter;                  /*773*/ 
  byte E2_Sensor_Error1_g;                    /*774*/ 
  byte E2_Sensor_Error2_g;                    /*775*/ 
  byte E2_Sensor_Error3_g;                    /*776*/ 
  byte E2_Sensor_Error4_g;                    /*777*/  
  byte E2_Sensor_Error5_g;                    /*778*/
  byte E2_Sensor_Error6_g;                    /*779*/  
  byte IncidentCounter1_g;                    /*780*/  
  byte IncidentCounter2_g;                    /*781*/  
  byte IncidentCounter3_g;                    /*782*/  
  byte IncidentCounter4_g;                    /*783*/  
  byte IncidentCounter5_g;                    /*784*/  
  byte IncidentCounter6_g;                    /*785*/  
  byte IncidentCounter7_g;                    /*786*/
  byte RS_LS_Error_Active1_g;                 /*787*/
  byte RS_LS_Error_Active2_g;                 /*788*/
  byte LightLS_Error_Active1_g;               /*789*/
  byte RainRS_Error_Active1_g;                /*790*/
  byte GainOffsetE2_g;                        /*791*/
  byte Release_IntervalMarker_g;              /*792*/
  byte SensConfigData_g[3];                  /*793,794,795*/
  byte Resf_g;                                /*796*/
  byte NOM_DELTA_INTV_g ;                 /*797*/ 
  byte THR_DELTA_INTV_g ;                 /*798*/ 
} s_rb_EEPROMStruct_RD_g;



typedef union {
  unsigned char _c[cb_NumberofEEPROMCells_RD_g];
  s_rb_EEPROMStruct_RD_g EEPROMStructRD;
} s_rb_EEPROMStructRD_buff_g;



/* PRQA S 3116,0759 4*//*<< 3116:#pragma needed for IAR compiler and MISRA, 0759:union needed to reduce RAM usage >>*/

EXTERN  s_rb_EEPROMStructRD_buff_g EEPROM_Struct_RD;



#define rb_STBY_REGV_HB_g                               EEPROM_Struct_RD.EEPROMStructRD.STBY_REGV_HB_g                /*768*/ 
#define rb_STBY_REGV_LB_g                               EEPROM_Struct_RD.EEPROMStructRD.STBY_REGV_LB_g                /*769*/ 
#define rb_STBY_DELTA_INTV_HB_g                         EEPROM_Struct_RD.EEPROMStructRD.STBY_DELTA_INTV_HB_g          /*770*/
#define rb_STBY_DELTA_INTV_LB_g                         EEPROM_Struct_RD.EEPROMStructRD.STBY_DELTA_INTV_LB_g          /*771*/
#define rb_IntervalIsWasActive_g                        EEPROM_Struct_RD.EEPROMStructRD.IntervalIsWasActive_g         /*772*/
#define rb_WatchdogResetCounter_g                       EEPROM_Struct_RD.EEPROMStructRD.WatchdogResetCounter          /*773*/
#define rb_E2_Sensor_Error1_g                           EEPROM_Struct_RD.EEPROMStructRD.E2_Sensor_Error1_g            /*774*/
#define rb_E2_Sensor_Error2_g                           EEPROM_Struct_RD.EEPROMStructRD.E2_Sensor_Error2_g            /*775*/
#define rb_E2_Sensor_Error3_g                           EEPROM_Struct_RD.EEPROMStructRD.E2_Sensor_Error3_g            /*776*/
#define rb_E2_Sensor_Error4_g                           EEPROM_Struct_RD.EEPROMStructRD.E2_Sensor_Error4_g            /*777*/
#define rb_E2_Sensor_Error5_g                           EEPROM_Struct_RD.EEPROMStructRD.E2_Sensor_Error5_g            /*778*/
#define rb_E2_Sensor_Error6_g                           EEPROM_Struct_RD.EEPROMStructRD.E2_Sensor_Error6_g            /*779*/
#define rb_IncidentCounter1_g 				EEPROM_Struct_RD.EEPROMStructRD.IncidentCounter1_g            /*780*/
#define rb_IncidentCounter2_g 			        EEPROM_Struct_RD.EEPROMStructRD.IncidentCounter2_g            /*781*/
#define rb_IncidentCounter3_g 				EEPROM_Struct_RD.EEPROMStructRD.IncidentCounter3_g            /*782*/
#define rb_IncidentCounter4_g 				EEPROM_Struct_RD.EEPROMStructRD.IncidentCounter4_g            /*783*/
#define rb_IncidentCounter5_g 				EEPROM_Struct_RD.EEPROMStructRD.IncidentCounter5_g            /*784*/
#define rb_IncidentCounter6_g 				EEPROM_Struct_RD.EEPROMStructRD.IncidentCounter6_g            /*785*/
#define rb_IncidentCounter7_g 				EEPROM_Struct_RD.EEPROMStructRD.IncidentCounter7_g            /*786*/
#define rb_RS_LS_Error_Active1_g			EEPROM_Struct_RD.EEPROMStructRD.RS_LS_Error_Active1_g         /*787*/
#define rb_RS_LS_Error_Active2_g			EEPROM_Struct_RD.EEPROMStructRD.RS_LS_Error_Active2_g         /*788*/
#define rb_LightLS_Error_Active1_g			EEPROM_Struct_RD.EEPROMStructRD.LightLS_Error_Active1_g       /*789*/
#define rb_RainRS_Error_Active1_g			EEPROM_Struct_RD.EEPROMStructRD.RainRS_Error_Active1_g        /*790*/
#define rb_GainOffsetE2_g                               EEPROM_Struct_RD.EEPROMStructRD.GainOffsetE2_g                /*791*/
#define rb_Release_IntervalMarker_g                     EEPROM_Struct_RD.EEPROMStructRD.Release_IntervalMarker_g      /*792*/ /*VCO_192*/
#define rab_SensConfigData_g(a)                         EEPROM_Struct_RD.EEPROMStructRD.SensConfigData_g[(a)]          /*793,794,795*/

#define rb_Resf_g                                       EEPROM_Struct_RD.EEPROMStructRD.Resf_g                        /*796*/

#define rb_NOM_DELTA_INTV_g                             EEPROM_Struct_RD.EEPROMStructRD.NOM_DELTA_INTV_g                /*797*/
#define rb_THR_DELTA_INTV_g                             EEPROM_Struct_RD.EEPROMStructRD.THR_DELTA_INTV_g                /*798*/


#define CW_EEPROM_INCIDENT1_ADDRESS (780)
#define rb_RainSensorIncidentCounter_g (rb_IncidentCounter1_g&0x0F )
#define rb_LightSensorIncidentCounter_g  (rb_IncidentCounter1_g>>4)
#define INREASE_RAIN_INCIDENT()  rb_IncidentCounter1_g+=1
#define INREASE_LIGHT_INCIDENT() rb_IncidentCounter1_g+=0x10
#define CW_EEPROM_INCIDENT2_ADDRESS (781)
#define rb_CntProSeqIncidentCounter_g (rb_IncidentCounter2_g&0x0F )
#define rb_CntMemoryIncidentCounter_g  (rb_IncidentCounter2_g>>4)
#define INREASE_CNTPROSEQ_INCIDENT()  rb_IncidentCounter2_g+=1
#define INREASE_CNTMEMORY_INCIDENT() rb_IncidentCounter2_g+=0x10
#define CW_EEPROM_INCIDENT3_ADDRESS (782)
#define rb_VoltSupplyIncidentCounter_g (rb_IncidentCounter3_g&0x0F )
#define rb_WDGIncidentCounter_g  (rb_IncidentCounter3_g>>4)
#define INREASE_VOLTSUPPLY_INCIDENT()  rb_IncidentCounter3_g+=1
#define INREASE_WDG_INCIDENT() rb_IncidentCounter3_g+=0x10
#define CW_EEPROM_INCIDENT4_ADDRESS (783)
#define rb_ASICIncidentCounter_g (rb_IncidentCounter4_g&0x0F )
#define rb_CPUIncidentCounter_g  (rb_IncidentCounter4_g>>4)
#define INREASE_ASIC_INCIDENT()  rb_IncidentCounter4_g+=1
#define INREASE_CPU_INCIDENT() rb_IncidentCounter4_g+=0x10
#define CW_EEPROM_INCIDENT5_ADDRESS (784)
#define rb_TempIncidentCounter_g (rb_IncidentCounter5_g&0x0F )
#define rb_HumIncidentCounter_g  (rb_IncidentCounter5_g>>4)
#define INREASE_TEMP_INCIDENT()  rb_IncidentCounter5_g+=1
#define INREASE_HUM_INCIDENT() rb_IncidentCounter5_g+=0x10
#define CW_EEPROM_INCIDENT6_ADDRESS (785)
#define rb_DewPointIncidentCounter_g (rb_IncidentCounter6_g&0x0F )
#define rb_HT_COMIncidentCounter_g  (rb_IncidentCounter6_g>>4)
#define INREASE_DEWPOINT_INCIDENT()  rb_IncidentCounter6_g+=1
#define INREASE_HT_COM_INCIDENT() rb_IncidentCounter6_g+=0x10
#define STBY_REGV_HBYTE_ADDRESS (768)
#define STBY_REGV_LBYTE_ADDRESS (769)
#define STBY_DELTA_INTV_HBYTE_ADDRESS (770)
#define STBY_DELTA_INTV_LBYTE_ADDRESS (771)
#define GAINOFFSET_ADDRESS (word)(791)

#define NOM_DELTA_INTV_BYTE_ADDRESS (797)
#define THR_DELTA_INTV_BYTE_ADDRESS (798)

/* special access adresses*/
#define CW_E2_WATCHDOGRESETCOUTERADRESS   (773)  //Counts the Watchdog Resets
#define CW_E2_SENSOR_ERROR1_ADRESS   774
#define CW_E2_SENSOR_ERROR2_ADRESS   (word)(775)  //Errorflags
#define CW_E2_SENSOR_ERROR3_ADRESS   776
#define CW_E2_SENSOR_ERROR4_ADRESS   777  //Errorflags
#define CW_E2_SENSOR_ERROR5_ADRESS   778  //Errorflags
#define CW_E2_SENSOR_ERROR6_ADRESS   779  //Errorflags
#define CW_E2_SENSOR_RESF_ADRESS     796

#define CW_RS_LS_ERROR_ACTIVE1_ADR      (word)787
#define CW_RS_LS_ERROR_ACTIVE2_ADR      (word)788
#define CW_LIGHTLS_ERROR_ACTIVE1_ADR    (word)789
#define CW_RAINRS_ERROR_ACTIVE1_ADR     (word)790
#define CW_INTERVAL_MARKER_ADRESS       (word)792
#define CW_SENS_CONFIG_DATA_ADRESS      (word)793
#endif
