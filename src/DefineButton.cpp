#include <DefineButton.h>
#include <Arduino.h>
#include <GlobalVariables.h>
#include <ESP32_IO.h>
#include <PrintInfo.h>
#include <MeasureButtonTime.h>

// Wheel switch buttons booleans
bool noButtonPressed   = false;
bool seekUpPressed     = false;
bool seekDownPressed   = false;
bool volumeUpPressed   = false;
bool volumeDownPressed = false;
bool modePressed       = false;

// Command recognized booleans              
bool sourceCommandRecognized           = false;
bool offCommandRecognized              = false;
bool answerCallCommandRecognized       = false;
bool endCallCommandRecognized          = false;
bool bandCommandRecognized             = false;
bool bandRepeatCommandRecognized       = false;
bool fileInfoCommandRecognized         = false;
bool attCommandRecognized              = false;
bool folderDownCommandRecognized       = false;
bool folderDownRepeatCommandRecognized = false;
bool seekUpCommandRecognized           = false;
bool seekDownCommandRecognized         = false;
bool volumeUpCommandRecognized         = false;
bool volumeDownCommandRecognized       = false;
bool complexCommand                    = false;

void DefineButton()
{
    buttonValue = analogRead(iWheelSwitchPin);
    buttonValue = map(buttonValue, 0, 4095, 0, 255);
    
    noButtonPressed   = buttonValue > 0   && buttonValue < 30;
    modePressed       = buttonValue > 55  && buttonValue < 80;
    seekDownPressed   = buttonValue > 95  && buttonValue < 120;
    seekUpPressed     = buttonValue > 130 && buttonValue < 150;
    volumeUpPressed   = buttonValue > 160 && buttonValue < 188;
    volumeDownPressed = buttonValue > 193 && buttonValue < 230;

    sourceCommandRecognized           = noButtonPressed   && inMonitoredWindow && currentState == "modePressed";
    offCommandRecognized              = buttonHolded      && currentState == "modePressed";
    answerCallCommandRecognized       = volumeUpPressed   && currentState.indexOf("mode") > -1;
    endCallCommandRecognized          = volumeDownPressed && currentState.indexOf("mode") > -1;
    folderDownCommandRecognized       = seekUpPressed     && currentState.indexOf("mode") > -1;
    bandCommandRecognized             = seekDownPressed   && currentState.indexOf("mode") > -1;
    //fileInfoCommandRecognized         = seekDownPressed   && currentState.indexOf("mode") > -1;
    //attCommandRecognized              = seekDownPressed   && currentState.indexOf("mode") > -1;
    folderDownRepeatCommandRecognized = seekUpPressed     && (currentState == "folderDown" || currentState == "folderDownRepeat");
    bandRepeatCommandRecognized       = seekDownPressed   && (currentState == "band"       || currentState == "bandRepeat");
    seekUpCommandRecognized           = seekUpPressed     && currentState == "noButton";
    seekDownCommandRecognized         = seekDownPressed   && currentState == "noButton";
    volumeUpCommandRecognized         = volumeUpPressed   && currentState == "noButton";
    volumeDownCommandRecognized       = volumeDownPressed && currentState == "noButton";
    
    complexCommand                    = answerCallCommandRecognized         || 
                                        endCallCommandRecognized            || 
                                        bandCommandRecognized               ||
                                        bandRepeatCommandRecognized         || 
                                        folderDownCommandRecognized         ||
                                        folderDownRepeatCommandRecognized;
}
