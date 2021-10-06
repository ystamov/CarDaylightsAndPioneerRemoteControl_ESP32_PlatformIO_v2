#include <Arduino.h>
#include <HighBeamsPWM.h>
#include <GlobalVariables.h>
#include <ESP32_IO.h>
#include <CalculateAverageValue.h>
#include <Beeps.h>
#include <MeasureHighBeamsCurrent.h>

// Common PWM variables      
const int brightnessLevelInPercents = 35;
  
const int highBeamsPwmChannel       = 9;
const int highBeamsPwmFrequency     = 64;
const int highBeamsPwmResolution    = 8;
  
int           brightnessLevel       = map(brightnessLevelInPercents, 0, 100, 0, 255);
int           currentPwmLevel       = 0;
const int     pwmIncrementStep      = 1;
unsigned long pwmMillisTime         = 0;
bool          pwmOnSwitch           = false;

// Car voltage measurement variables
//float carVoltageValue         = 0.0;      
float carVoltageValueFiltered       = 0.0;
float R1                            = 20000.0;  // Floats for resistor values in divider (in ohms)
float R2                            = 5000.0;   


void Init_HighBeamsPwm()
{
  ledcAttachPin(oHighBeamsPwmPin, highBeamsPwmChannel);
  ledcSetup(highBeamsPwmChannel, highBeamsPwmFrequency, highBeamsPwmResolution);
}

void HighBeamsPwm()
{
  MeasureHighBeamsCurrent();
  
  pwmOnSwitch = digitalRead(iPwmOnPin);

  float carVoltageValue = (((float)analogRead(iCarVoltagePin) / adcResolution) * refVoltage) / (R2 / (R1 + R2)); //1.084
  carVoltageValueFiltered = CalculateAverageVoltage(carVoltageValue);

  if (pwmOnSwitch == HIGH)
  {
    if (carVoltageValueFiltered > 0)    
    {
      digitalWrite(oLedPin, HIGH);

      if (currentPwmLevel < brightnessLevel)
      {
        pwmMillisTime++;

        if (pwmMillisTime % 2 == 0)
        {
          currentPwmLevel += pwmIncrementStep;

          if (currentPwmLevel == brightnessLevel)
          {
            BeepPwmFinished();
          }
        }
        
        vTaskDelay(20 / portTICK_PERIOD_MS);
      }
      else
      {
        if (currentPwmLevel > brightnessLevel)
        {
          BeepPwmFinished();
        }
        currentPwmLevel = brightnessLevel;
        pwmMillisTime = 0;
      }

      ledcWrite(highBeamsPwmChannel, currentPwmLevel);
    }
    else
    {
      digitalWrite(oLedPin, LOW);
      currentPwmLevel = 0;
      pwmMillisTime = 0;
      ledcWrite(highBeamsPwmChannel, currentPwmLevel);
    }
  }
  else
  {
    digitalWrite(oLedPin, LOW);
    currentPwmLevel = 0;
    ledcWrite(highBeamsPwmChannel, currentPwmLevel);
  }
}