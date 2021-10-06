#include <GlobalVariables.h>
#include <Arduino.h>
#include <ESP32_IO.h>
#include <ResetStatesAndVariables.h>
#include <MeasureButtonTime.h>

void ResetStatesAndVariables()
{
    //xSemaphoreTake(batton, portMAX_DELAY);
    currentState = "noButton";
    activatedOutput = "noOutput";
    buttonPressStartTime = 0;
    buttonPressedTime = 0;
    commandRecognized = false;

    /*
    ring3v3ValueToOp = 0;
    tip3v3ValueToOp = 0;
    tipWorkPwmFrequency = pwmFrequency1;            // TIP settings: f=15000, Res=12
    tipWorkPwmResolution = pwmResolution1;
    ringWorkPwmFrequency = pwmFrequency1;           // RING settings: f=15000, Res=12
    ringWorkPwmResolution = pwmResolution1;
    ledcWrite(ring3v3PwmChannel, ring3v3ValueToOp);
    ledcWrite(tip3v3PwmChannel, tip3v3ValueToOp);
    */

    tip3v3ValueToOp = 255;
    ring3v3ValueToOp = 255;
    dacWrite(o3v3TipPin, tip3v3ValueToOp);
    dacWrite(o3v3RingPin, ring3v3ValueToOp);
    //xSemaphoreGive(batton);
    vTaskDelay(1 / portTICK_PERIOD_MS);
}

void ResetAverageMethods(float inputArray[], int arrayCount)
{
    for (int i = 0; i < arrayCount; i++) // Reseting average method output
    {
        inputArray[i] = 0;
    }
}