#include "ior5f109be.h"

typedef struct {
byte max;
byte min;
}BytePair;

BytePair createHysteresisValuePair(byte inValue);
byte wiperSpeed7to2(word currentSpeed0to2In,word speed0to7In, byte hysteresisEdges);
/**************************************************************************
Syntax   : byte wiperSpeed7to2(word currentSpeedIn, byte hysteresisEdges)
Object   : wiperSpeed7to2()
Parameter : currentSpeed0to2In the current wiper speed 0 to 2
Parameter : speed0to7In the calculated wiper speed 0 to 7
Parameter : hysteresisEdges the configuration of the hysteresis
Return  : new wipers speed 0 to2
Calls   : on new LIN message containing the wipers speed
***************************************************************************
Pseudo-code : transform the speed 0-7 to speed 0-2 defined by hysteresi || defined(BYTON))
**************************************************************************/

byte wiperSpeed7to2(word currentSpeed0to2In,word speed0to7In, byte hysteresisEdges){

// require the hysteresis edges between 1 and 7
BytePair hysteresisEdge = createHysteresisValuePair(hysteresisEdges);
byte egdeVal;
byte newSpeedOut;
#if (defined (HAITEC) || defined (FOTON_S700) || defined (BRILLIANCE_M8X) || defined (BAICYX_G20) || defined (CTCS_M31T) || defined (BAICYX_H50) || defined(ZOTYE_A40) || defined(Zoety_A10)  || defined(CHJ_M01) || defined(FARADAY) || defined(GREAT_WALL_CH071) || defined(ZOTYE_B01_NEW) || defined(BYTON))
if (currentSpeed0to2In < 3) {
// increasing path of hysteresis
egdeVal = hysteresisEdge.max;
}
else {
//decreasing path of hysteresis
egdeVal = hysteresisEdge.min;
}

if (speed0to7In == 0) {
newSpeedOut =0;
}
else if (speed0to7In <= egdeVal) {
newSpeedOut = 2;
}
else {
//this case is left
newSpeedOut = 3;
}
return newSpeedOut;
#else
if (currentSpeed0to2In < 2) {
// increasing path of hysteresis
egdeVal = hysteresisEdge.max;
}
else {
//decreasing path of hysteresis
egdeVal = hysteresisEdge.min;
}

if (speed0to7In == 0) {
newSpeedOut =0;
}
else if (speed0to7In <= egdeVal) {
newSpeedOut = 1;
}
else {
//this case is left
newSpeedOut = 2;
}
return newSpeedOut;
#endif
}


/**************************************************************************
Syntax   : BytePair createHysteresisValuePair(byte inValue)
Object   : createHysteresisValuePair()
Parameters : inValue
Return  : BytePair
Calls   : on demand, e.g. when input values coming from EEPROM have changed
***************************************************************************
Inputs validation conditions:
inValue must consist of two nibble values which must be different and
in range 0 to 7. Return default value pair if input not valid
***************************************************************************
Pseudo-code : split the input value. Find max and min edges of hysteresis
**************************************************************************/
#pragma inline=forced
BytePair createHysteresisValuePair(byte inValue)
{
BytePair retVal;
retVal.min = inValue & 0x0F;
retVal.max = (inValue >> 4) & 0x0F;

if(retVal.max < retVal.min){
byte a = retVal.min ;
retVal.min = retVal.max;
retVal.max = a;
}
// here the values are ordered, check the ranges
if(   (retVal.max >= retVal.min)
&& ((retVal.max >0) && (retVal.max <8 ))
&& ((retVal.min >0) && (retVal.min <8 ))
){
// every thing is OK , input is valid
return retVal;
}else{
// invalid input, give defaults back
retVal.max = 6;
retVal.min = 4;
return retVal;
}
}
