#ifndef CalculateAverageValue_h
#define CalculateAverageValue_h

#define      voltageReadings 25
extern int   indexx;
extern int   average;
extern float readings[];         
extern float totalReadings;
extern float CalculateAverageVoltage(float inputValue);

#define      currentReadings 50
extern int   indexx2;
extern int   average2;
extern float readings2[];         
extern float totalReadings2;
extern float CalculateAverageCurrent(float inputValue);

#endif