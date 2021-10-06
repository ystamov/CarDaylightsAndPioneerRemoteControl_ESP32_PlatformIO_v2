#ifndef HighBeamsPWM_h
#define HighBeamsPWM_h

// Common PWM variables    
extern const int brightnessLevelInPercents;

extern const int highBeamsPwmChannel;
extern const int highBeamsPwmFrequency;
extern const int highBeamsPwmResolution;

extern int           brightnessLevel;
extern int           currentPwmLevel;
extern const int     pwmIncrementStep;
extern unsigned long pwmMillisTime;
extern bool          pwmOnSwitch;

// Car voltage measurement variables
//extern float carVoltageValue;
extern float carVoltageValueFiltered;
extern float R1;
extern float R2;


extern void Init_HighBeamsPwm();
extern void HighBeamsPwm();

#endif