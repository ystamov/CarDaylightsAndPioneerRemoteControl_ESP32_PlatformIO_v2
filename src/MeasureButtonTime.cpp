#include <MeasureButtonTime.h>
#include <Arduino.h>

unsigned long buttonPressStartTime = 0;
unsigned long buttonPressedTime    = 0;
const int     buttonHoldMaxTime    = 1300;
const int     buttonPressMaxTime   = 650;
bool          inMonitoredWindow    = false;
bool          buttonHolded         = false;

void MeasureButtonTime()
{
    if (buttonPressStartTime == 0)
    {
        buttonPressStartTime = millis();
    }

    buttonPressedTime = millis() - buttonPressStartTime;
    inMonitoredWindow = buttonPressedTime <= buttonHoldMaxTime;
    buttonHolded = buttonPressedTime > buttonPressMaxTime;
}