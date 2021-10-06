/*
  Ford Focus Mk1 - PWM control for high beams (daylights) and Pioneer car stereo remote control from wheel control switch via ESP32-WROOM development board
  
  Author:  Yasen Stamov
  Country: Bulgaria
  Year:    2021
*/
#include <Arduino.h>
#include <ESP32_IO.h>
#include <GlobalVariables.h>
#include <U8g2lib.h>
#include <ArduinoOTA.h>
#include <OTAUpdate.h>
#include <ResetStatesAndVariables.h>
#include <DefineButton.h>
#include <WheelSwitchesControl.h>
#include <HighBeamsPwm.h>
#include <PrintInfo.h>
#include <CalculateAverageValue.h>
#include <DefineFeedback.h>

void setup()
{
  Init_PinMode();
  Init_PrintInfo();
  Init_HighBeamsPwm();
  OTAUpdate();

  xTaskCreatePinnedToCore(
      PrintInfo,        /* Task function. */
      "PrintInfoCore0", /* name of task. */
      2500,             /* Stack size of task */
      NULL,             /* parameter of the task */
      0,                /* priority of the task */
      &PrintInfoTask,   /* Task handle to keep track of created task */
      0);               /* pin task to core 0 */

  vTaskDelay(1 / portTICK_PERIOD_MS);

  ResetAverageMethods(readings, voltageReadings);
  ResetAverageMethods(readings2, currentReadings);
}

void loop()
{
  ArduinoOTA.handle();
  WheelSwitchesControl();
  HighBeamsPwm();

  loopCore = xPortGetCoreID();
  vTaskDelay(1 / portTICK_PERIOD_MS);
}

// int PWM1_DutyCycle = 0;

// void setup()
// {
//   pinMode(i3v3TipFeedbackVoltage, INPUT);
//   pinMode(i3v3RingFeedbackVoltage, INPUT);

//   // ledcAttachPin(o3v3TipPin, tip3v3PwmChannel);
//   // ledcAttachPin(o3v3RingPin, ring3v3PwmChannel);
//   ledcAttachPin(oHighBeamsPwmPin, highBeamsPwmChannel);

//   // ledcSetup(ring3v3PwmChannel, pwmFrequency2, pwmResolution2);
//   ledcSetup(highBeamsPwmChannel, highBeamsPwmFrequency, highBeamsPwmResolution);
//   Serial.begin(9600);
// }

// void loop()
// {
//   int potValue = analogRead(iPotentiometer);

//   tip3v3FeedbackValue = ((float)analogRead(i3v3TipFeedbackVoltage) / 4096) * refVoltage;
//   ring3v3FeedbackValue = ((float)analogRead(i3v3RingFeedbackVoltage) / 4096) * refVoltage;

//   PWM1_DutyCycle = map(potValue, 0, 4095, 150, 35);

//   Serial.print("Duty: ");
//   Serial.print(PWM1_DutyCycle);
//   Serial.print("\t");
//   Serial.print("Utip: ");
//   Serial.print(tip3v3FeedbackValue);
//   Serial.print("\t");
//   Serial.print("Uring: ");
//   Serial.print(ring3v3FeedbackValue);
//   Serial.println("\t");

//   // if (PWM1_DutyCycle <= 175)
//   // {
//   //     ledcSetup(tip3v3PwmChannel, pwmFrequency1, pwmResolution1);
//   // }
//   // else
//   // {
//   //     ledcSetup(tip3v3PwmChannel, pwmFrequency2, pwmResolution2);
//   // }

//   // ledcWrite(tip3v3PwmChannel, PWM1_DutyCycle);
//   // ledcWrite(ring3v3PwmChannel, 0);
//   dacWrite(o3v3TipPin,PWM1_DutyCycle);
//   dacWrite(o3v3RingPin,35);
//   ledcWrite(highBeamsPwmChannel, map(brightnessLevelInPercents, 0, 100, 0, 255));
//   vTaskDelay(250 / portTICK_PERIOD_MS);
// }