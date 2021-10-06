#ifndef GlobalVariables_H
#define GlobalVariables_H

#include <Arduino.h>

extern uint32_t Core0TaskCore;
extern uint32_t loopCore;

extern SemaphoreHandle_t batton;
extern TaskHandle_t      PrintInfoTask;

/*
const int pwmFrequency1                 = 15000; // 15000/12  ideal:19531/12 / 78125/10
const int pwmResolution1                = 12;
const int pwmFrequency2                 = 5000; 
const int pwmResolution2                = 8;
*/

extern int       tip3v3ValueToOp;
extern int       ring3v3ValueToOp;
extern const int ring3v3ComplexCmdValueToOp;



extern int buttonValue;

// Transition times
extern const int normalOutputTime;
extern const int holdedOutputTime;

extern bool commandRecognized;

// Wheel switch buttons strings
extern String activatedOutput;
extern String currentState;

extern float  refVoltage;  
extern double adcResolution;

#endif