#ifndef ESP32_IO_H
#define ESP32_IO_H

// Digital Inputs
extern int iPwmOnPin;

// Analog Inputs
extern int iWheelSwitchPin;
extern int iHighBeamsCurrentSensorPin;
extern int iCarVoltagePin;
extern int i3v3TipFeedbackVoltage;
extern int i3v3RingFeedbackVoltage;
extern int iPotentiometer;

// Digital Outputs
extern int oLedPin;
extern int o3v3RingPin;
extern int o3v3TipPin;

extern int oBuzzerPin;

// Analog Outputs
extern int oHighBeamsPwmPin;

extern void Init_PinMode();

#endif

