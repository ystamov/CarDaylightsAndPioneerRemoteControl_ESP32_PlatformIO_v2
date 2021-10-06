#ifndef PrintInfo_h
#define PrintInfo_h

#include <U8g2lib.h>

extern U8G2_SSD1306_128X64_NONAME_1_SW_I2C *u8g2;
extern void Init_PrintInfo();
extern void PrintToOled();
extern void PrintToSerial();
extern void PrintInfo(void *pvParameters);

#endif