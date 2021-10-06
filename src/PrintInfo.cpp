#include <Arduino.h>
#include <PrintInfo.h>
#include <ESP32_IO.h>
#include <GlobalVariables.h>
#include <ResetStatesAndVariables.h>
#include <DefineButton.h>
#include <HighBeamsPwm.h>
#include <MeasureHighBeamsCurrent.h>
#include <DefineFeedback.h>

U8G2_SSD1306_128X64_NONAME_1_SW_I2C *u8g2;

void Init_PrintInfo()
{
    u8g2 = new U8G2_SSD1306_128X64_NONAME_1_SW_I2C(U8G2_R0, /* clock=*/ SCL, /* data=*/ SDA, /* reset=*/ U8X8_PIN_NONE);
    u8g2->begin();

    Serial.begin(115200);
}

void PrintToOled()
{
  //Serial.print("Core0Task running on core ");
  //Serial.println(xPortGetCoreID());
  u8g2->setFont(u8g2_font_7x13_mf);
  u8g2->firstPage();
  do 
  {
    xSemaphoreTake(batton, portMAX_DELAY);
    u8g2->drawLine(0, 16, 128, 16);  // X1 line -> X1, Y1, X2, Y2
    u8g2->drawLine(63, 0, 63, 60);   // Y1 line -> X1, Y1, X2, Y2
    u8g2->drawLine(0, 33, 128, 33);  // X2 line -> X1, Y1, X2, Y2
    u8g2->drawLine(0, 50, 128, 50);  // X3 line -> X1, Y1, X2, Y2
    u8g2->setCursor(3, 12);
    //xSemaphoreTake(batton, portMAX_DELAY);
    u8g2->print("U: ");
    u8g2->print(carVoltageValueFiltered);
    u8g2->print("V");
    u8g2->setCursor(67, 12);
    u8g2->print("I: ");
    u8g2->print(currentSensorCurrent, 1);
    u8g2->setCursor(3, 29);
    u8g2->print("PWM: ");
    u8g2->print(map(currentPwmLevel, 0, 255, 0, 100)); // converting to 0-100 %
    u8g2->print("%");
    u8g2->setCursor(67, 29);
    u8g2->print("tF: ");
    u8g2->print(tip3v3FeedbackValue);                                 
    u8g2->setCursor(3, 46);
    u8g2->print("Bn: ");
    u8g2->print(buttonValue);
    u8g2->setCursor(67, 46);
    u8g2->print("rF: ");
    u8g2->print(ring3v3FeedbackValue);
    u8g2->setCursor(3, 62);
    u8g2->print("S: ");
    u8g2->print(currentState);
    xSemaphoreGive(batton);
  }
  while ( u8g2->nextPage() );
}

void PrintToSerial()
{
  xSemaphoreTake(batton, portMAX_DELAY);

  // Serial.print("pwmOn: ");
  // Serial.print(pwmOnSwitch);
  // Serial.print("  |  ");
  // Serial.print("hb I: ");
  // Serial.print(currentSensorCurrent);
  // Serial.print(" A");
  //Serial.print("  |  ");
  Serial.print("Core0Task core: ");
  Serial.print(xPortGetCoreID());
  Serial.print("  |  ");
  Serial.print("loopTask core: ");
  Serial.print(loopCore);
  Serial.print("  |  ");
  Serial.print("commandRecognized: ");
  Serial.print(commandRecognized);
  Serial.print("  |  ");
  Serial.print("modePressed: ");
  Serial.print(modePressed);
  //Serial.print("  |  ");
  // Serial.print("currentPwmLevel: ");
  // Serial.print(map(currentPwmLevel, 0, 255, 0, 100));
  // Serial.print(" %");
  // Serial.print("  |  ");
  // Serial.print("tipF: ");
  // Serial.print(tip3v3FeedbackValue);
  // Serial.print("  |  ");
  // Serial.print("ringF: ");
  // Serial.print(ring3v3FeedbackValue);
  // Serial.print("  |  ");
  // Serial.print("millis: ");
  // Serial.print(millis());
  // Serial.print(" ms");
  // Serial.print("  |  ");
  // Serial.print("buttonPressStartTime: ");
  // Serial.print(buttonPressStartTime);
  // Serial.print(" ms");
  // Serial.print("  |  ");
  // Serial.print("carVoltageFiltered: ");
  // Serial.print(carVoltageValueFiltered);
  // Serial.print(" V");
  Serial.print("  |  ");
  Serial.print("buttonValue: ");
  Serial.print(buttonValue);
  Serial.print("  |  ");
  Serial.print("complexCommand: ");
  Serial.print(complexCommand);
  Serial.print("  |  ");
  Serial.print("currentState: ");
  Serial.print(currentState);
  Serial.print("  |  ");
  Serial.print("activatedOutput: ");
  Serial.println(activatedOutput);

  xSemaphoreGive(batton);
  vTaskDelay(1 / portTICK_PERIOD_MS);
}

void PrintInfo(void *pvParameters)
{
  for (;;)
  {
    PrintToOled();
    PrintToSerial();

    if (noButtonPressed) // Pressed and released buttons
    {
      // if (complexCommand)
      // {
      //   activatedOutput = "noOutput";
      //   tip3v3ValueToOp = 255;
      //   ring3v3ValueToOp = 255;
      //   dacWrite(o3v3RingPin, 255);
      //   dacWrite(o3v3TipPin, 255);
      // }
      // else
      // {
      //   ResetStatesAndVariables();
      // }
    }
  }
}