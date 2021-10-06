#include <GlobalVariables.h>
#include <DefineButton.h>
#include <ResetStatesAndVariables.h>
#include <GenerateOutput.h>
#include <PrintInfo.h>
#include <MeasureButtonTime.h>
#include <WheelSwitchesControl.h>
#include <DefineButton.h>
#include <DefineFeedback.h>
#include <ESP32_IO.h>

void WheelSwitchesControl()
{
    DefineButton();
    DefineFeedback();

    if (noButtonPressed) // Pressed and released buttons
    {
        if (sourceCommandRecognized)
        {
            tip3v3ValueToOp = oSourceOffValue;
            ring3v3ValueToOp = ring3v3ComplexCmdValueToOp;
            GenerateTimedOutput(tip3v3ValueToOp, ring3v3ValueToOp, currentState, normalOutputTime);
        }
        else
        {
            ResetStatesAndVariables();
        }
    }
    else
    {
        MeasureButtonTime();

        if (inMonitoredWindow) // modePressed (radio source), answerCall, endCall, folderDown, folderDown, seekUp, seekDown, volumeUp, volumeDown
        {
            if (sourceCommandRecognized)
            {
                currentState = "modePressed";
                tip3v3ValueToOp = oSourceOffValue;
            }
            else if (offCommandRecognized)
            {
                currentState = "modeHolded";
                tip3v3ValueToOp = oSourceOffValue;
            }
            else if (bandCommandRecognized)
            {
                currentState = "band";
                tip3v3ValueToOp = oBandEscapeValue;
            }
            else if (volumeDownCommandRecognized)
            {
                currentState = "volumeDown";
                tip3v3ValueToOp = oVolumeDownValue;
            }
            else if (volumeUpCommandRecognized)
            {
                currentState = "volumeUp";
                tip3v3ValueToOp = oVolumeUpValue;
            }
            else if (seekDownCommandRecognized)
            {
                currentState = "seekDown";
                tip3v3ValueToOp = oPrevTrackTuneDownValue;
            }
            else if (seekUpCommandRecognized)
            {
                currentState = "seekUp";
                tip3v3ValueToOp = oNextTrackTuneUpValue;
            }
            else if (fileInfoCommandRecognized)
            {
                currentState = "fileInfo";
                tip3v3ValueToOp = oFileInfoValue;
            }
            else if (attCommandRecognized)
            {
                currentState = "att";
                tip3v3ValueToOp = oAttValue;
            }
            else if (folderDownCommandRecognized)
            {
                currentState = "folderDown";
                tip3v3ValueToOp = oFolderDownValue;
            }
            else if (answerCallCommandRecognized)
            {
                currentState = "answerCall";
                tip3v3ValueToOp = oAnswerCallValue;
            }
            else if (endCallCommandRecognized)
            {
                currentState = "endCall";
                tip3v3ValueToOp = oEndCallValue;
            }

            // Repeats
            if (folderDownRepeatCommandRecognized)
            {
                currentState = "folderDownRepeat";
                tip3v3ValueToOp = oFolderDownValue;
            }
            else if (bandRepeatCommandRecognized)
            {
                currentState = "bandRepeat";
                tip3v3ValueToOp = oBandEscapeValue;
            }
        }
        else // modeHolded above monitored window = radio off
        {
            // if (currentState == "modeHolded")
            // {
            //     tip3v3ValueToOp = oSourceOffValue;
            // }
            if (folderDownRepeatCommandRecognized)
            {
                currentState = "folderDownRepeat";
                tip3v3ValueToOp = oFolderDownValue;
            }
            else if (bandRepeatCommandRecognized)
            {
                currentState = "bandRepeat";
                tip3v3ValueToOp = oBandEscapeValue;
            }
        }

        // Generate output
        if (volumeDownCommandRecognized ||
            volumeUpCommandRecognized ||
            seekDownCommandRecognized ||
            seekUpCommandRecognized)
        {
            GenerateNormalOrHoldedOutput(tip3v3ValueToOp, currentState);
            commandRecognized = true;
        }
        else if (offCommandRecognized ||
                 bandCommandRecognized ||
                 bandRepeatCommandRecognized ||
                 fileInfoCommandRecognized ||
                 attCommandRecognized ||
                 answerCallCommandRecognized ||
                 endCallCommandRecognized ||
                 folderDownCommandRecognized ||
                 folderDownRepeatCommandRecognized)
        {
            if (answerCallCommandRecognized ||
                endCallCommandRecognized ||
                folderDownCommandRecognized ||
                folderDownRepeatCommandRecognized)
            {
                ring3v3ValueToOp = ring3v3ComplexCmdValueToOp;
            }

            GenerateTimedOutput(tip3v3ValueToOp, ring3v3ValueToOp, currentState, normalOutputTime);
        }
    }
}