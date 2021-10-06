#include <Beeps.h>
#include <GlobalVariables.h>
#include <Arduino.h>
#include <ESP32_IO.h>

void BeepPwmFinished()
{
    digitalWrite(oBuzzerPin, HIGH);
    vTaskDelay(260 / portTICK_PERIOD_MS);
    digitalWrite(oBuzzerPin, LOW);
    vTaskDelay(110 / portTICK_PERIOD_MS);
    digitalWrite(oBuzzerPin, HIGH);
    vTaskDelay(55 / portTICK_PERIOD_MS);
    digitalWrite(oBuzzerPin, LOW);
    vTaskDelay(55 / portTICK_PERIOD_MS);
    digitalWrite(oBuzzerPin, HIGH);
    vTaskDelay(25 / portTICK_PERIOD_MS);
    digitalWrite(oBuzzerPin, LOW);
}

void BeepCommandCompleted()
{
    digitalWrite(oBuzzerPin, HIGH);
    digitalWrite(oLedPin, HIGH);
    vTaskDelay(30 / portTICK_PERIOD_MS);
    digitalWrite(oBuzzerPin, LOW);
    digitalWrite(oLedPin, LOW);
}