#ifndef MeasureButtonTime_h
#define MeasureButtonTime_h

extern unsigned long buttonPressStartTime;
extern unsigned long buttonPressedTime;
extern const int     buttonHoldMaxTime;
extern const int     buttonPressMaxTime;
extern bool          inMonitoredWindow;
extern bool          buttonHolded;

extern void MeasureButtonTime();

#endif