#ifndef GenerateOutput_h
#define GenerateOutput_h

#include <Arduino.h>

// Wheel switch buttons PWM values to OPs
extern const int oBandEscapeValue;
extern const int oVolumeDownValue;
extern const int oVolumeUpValue;
extern const int oPrevTrackTuneDownValue;
extern const int oNextTrackTuneUpValue;
extern const int oFileInfoValue;
extern const int oAttValue;
extern const int oSourceOffValue;
extern const int oFolderDownValue;
extern const int oAnswerCallValue;
extern const int oEndCallValue;

extern void GenerateNormalOrHoldedOutput(int tip3v3ValueToOp, String currentState);
extern void GenerateTimedOutput(int tip3v3ValueToOp, int ring3v3ValueToOp, String currentState, int outputTime);

#endif
