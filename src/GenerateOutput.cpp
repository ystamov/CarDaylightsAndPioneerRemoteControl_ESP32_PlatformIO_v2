#include <GenerateOutput.h>
#include <GlobalVariables.h>
#include <Arduino.h>
#include <PrintInfo.h>
#include <Beeps.h>
#include <ResetStatesAndVariables.h>
#include <DefineButton.h>
#include <DefineFeedback.h>
#include <ESP32_IO.h>

const int oBandEscapeValue        = 219;
const int oVolumeDownValue        = 181;
const int oVolumeUpValue          = 157;
const int oPrevTrackTuneDownValue = 134;
const int oNextTrackTuneUpValue   = 111;
const int oFileInfoValue          = 88;
const int oAttValue               = 62;
const int oSourceOffValue         = 22;
const int oFolderDownValue        = 132;
const int oAnswerCallValue        = 255;
const int oEndCallValue           = 43;


void GenerateNormalOrHoldedOutput(int _tip3v3ValueToOp, String _currentState)
{
    activatedOutput = _currentState;
    dacWrite(o3v3TipPin, _tip3v3ValueToOp);

    BeepCommandCompleted();
    DefineButton();

    if (noButtonPressed)
    {
      ResetStatesAndVariables();
    }
}

void GenerateTimedOutput(int _tip3v3ValueToOp, int _ring3v3ValueToOp, String _currentState, int _delayTime)
{
    //xSemaphoreTake(batton, portMAX_DELAY);

    activatedOutput = _currentState;
    dacWrite(o3v3RingPin, _ring3v3ValueToOp);
    dacWrite(o3v3TipPin, _tip3v3ValueToOp);

    // if (complexCommand)
    // {
    //   activatedOutput = "noOutput";
    //   tip3v3ValueToOp = 255;
    //   ring3v3ValueToOp = 255;
    //   dacWrite(o3v3RingPin, 255);
    //   dacWrite(o3v3TipPin, 255);
    // }

    //xSemaphoreGive(batton);

    BeepCommandCompleted();
    vTaskDelay(_delayTime / portTICK_PERIOD_MS);
}