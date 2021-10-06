#ifndef MeasureHighBeamsCurrent_h
#define MeasureHighBeamsCurrent_h

// High beams current measurement
extern double       currentSensorVoltageOut;
extern double       currentSensorCurrent;

extern double       currentSensorResolution;
extern double       currentSensorZeroPoint;
extern double       currentSensorSamples;
extern const double currentSensorScaleFactor;

extern void         MeasureHighBeamsCurrent();

#endif