#include <ESP32_IO.h>
#include <Arduino.h>


// Digital Inputs
int iPwmOnPin                  = 15;        //TODO: 6.8k resistor to ground
        
// Analog Inputs        
int iWheelSwitchPin            = 36;        
int iHighBeamsCurrentSensorPin = 34;        
int iCarVoltagePin             = 39;        //TODO: 6.8k resistor to ground
int i3v3TipFeedbackVoltage     = 32;
int i3v3RingFeedbackVoltage    = 33;
int iPotentiometer             = 35;
        
// Digital Outputs
int oLedPin                    = 14;
int o3v3RingPin                = 25; //2
int o3v3TipPin                 = 26; //4

int oBuzzerPin                 = 5;

// Analog Outputs
int oHighBeamsPwmPin           = 2;

void Init_PinMode()
{
    pinMode(iPwmOnPin,                  INPUT_PULLDOWN);
    pinMode(iWheelSwitchPin,            INPUT);
    pinMode(iHighBeamsCurrentSensorPin, INPUT);
    pinMode(iCarVoltagePin,             INPUT);
    pinMode(i3v3TipFeedbackVoltage,     INPUT);
    pinMode(i3v3RingFeedbackVoltage,    INPUT);
    pinMode(iPotentiometer,             INPUT);

    pinMode(oBuzzerPin,                 OUTPUT);
    pinMode(oHighBeamsPwmPin,           OUTPUT);
    pinMode(oLedPin,                    OUTPUT);
    pinMode(o3v3RingPin,                OUTPUT);
    pinMode(o3v3TipPin,                 OUTPUT);
}