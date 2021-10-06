#include <Arduino.h>
#include <GlobalVariables.h>

uint32_t Core0TaskCore = 5;
uint32_t loopCore      = 5;

SemaphoreHandle_t batton        = xSemaphoreCreateMutex();
TaskHandle_t      PrintInfoTask = NULL;

/*
const int pwmFrequency1                 = 15000; // 15000/12  ideal:19531/12 / 78125/10
const int pwmResolution1                = 12;
const int pwmFrequency2                 = 5000; 
const int pwmResolution2                = 8;
*/

int       tip3v3ValueToOp            = 255;
int       ring3v3ValueToOp           = 255;
const int ring3v3ComplexCmdValueToOp = 35;



int buttonValue            = 0;

// Transition times
const int normalOutputTime = 25;
const int holdedOutputTime = 1200;

bool   commandRecognized   = false;
String activatedOutput     = "noOutput";
String currentState        = "noButton";

float  refVoltage          = 3.3;      // Float for Reference Voltage
double adcResolution       = 4096;