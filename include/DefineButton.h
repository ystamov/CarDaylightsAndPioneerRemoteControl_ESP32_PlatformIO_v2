#ifndef DefineButton_h
#define DefineButton_h

// // Wheel switch buttons booleans
extern bool noButtonPressed;
extern bool seekUpPressed;
extern bool seekDownPressed;
extern bool volumeUpPressed;
extern bool volumeDownPressed;
extern bool modePressed;

// Command recognized booleans 
extern bool sourceCommandRecognized;
extern bool offCommandRecognized;
extern bool answerCallCommandRecognized;
extern bool endCallCommandRecognized;
extern bool bandCommandRecognized;
extern bool bandRepeatCommandRecognized;
extern bool fileInfoCommandRecognized;
extern bool attCommandRecognized;
extern bool folderDownCommandRecognized;
extern bool folderDownRepeatCommandRecognized;
extern bool seekUpCommandRecognized;
extern bool seekDownCommandRecognized;
extern bool volumeUpCommandRecognized;
extern bool volumeDownCommandRecognized;
extern bool complexCommand;

extern void DefineButton();

#endif