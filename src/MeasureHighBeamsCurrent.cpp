#include <Arduino.h>
#include <ESP32_IO.h>
#include <GlobalVariables.h>
#include <MeasureHighBeamsCurrent.h>
#include <CalculateAverageValue.h>

// High beams current measurement
double       currentSensorVoltageOut  = 0.0;
double       currentSensorCurrent     = 0.0;

double       currentSensorResolution  = refVoltage / adcResolution;
double       currentSensorZeroPoint   = 2.5;
double       currentSensorSamples     = 0.0;
const double currentSensorScaleFactor = 0.066;

void MeasureHighBeamsCurrent()
{
    currentSensorVoltageOut = ((analogRead(iHighBeamsCurrentSensorPin) / adcResolution) * refVoltage) - currentSensorZeroPoint;
    double _current = currentSensorVoltageOut / currentSensorScaleFactor;
    currentSensorCurrent = CalculateAverageCurrent(abs(_current));
}