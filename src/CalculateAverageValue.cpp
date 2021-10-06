#include <CalculateAverageValue.h>
#include <GlobalVariables.h>

// Car voltage measurement average method

int indexx = 0;                  // promenliva za poreden nomer na poslednoto otchitane
int average = 0;                 // promenliva za srednata, izgladena stojnost
float readings[voltageReadings]; // promenliva za broya otchitaniya
float totalReadings = 0;         // promenliva za obshtiya broj otchitaniya

float CalculateAverageVoltage(float inputValue)
{
    totalReadings -= readings[indexx]; // izvajda poslednata otchetena stojnost
    readings[indexx] = inputValue;     // otchita danni ot senzora...
    totalReadings += readings[indexx]; // ...pribavya gi kam sbora...
    indexx++;                          // ...i preminava kam otchitane na sledvashta stojnost
    if (indexx >= voltageReadings)
    {
        indexx = 0;
    }

    return totalReadings / voltageReadings; // * 2.36271
}

// High beams current measurement average method

int indexx2 = 0;                  // promenliva za poreden nomer na poslednoto otchitane
int average2 = 0;                 // promenliva za srednata, izgladena stojnost
float readings2[currentReadings]; // promenliva za broya otchitaniya
float totalReadings2 = 0;         // promenliva za obshtiya broj otchitaniya

float CalculateAverageCurrent(float inputValue)
{
    totalReadings2 -= readings2[indexx2]; // izvajda poslednata otchetena stojnost
    readings2[indexx2] = inputValue;      // otchita danni ot senzora...
    totalReadings2 += readings2[indexx2]; // ...pribavya gi kam sbora...
    indexx2++;                            // ...i preminava kam otchitane na sledvashta stojnost
    if (indexx2 >= currentReadings)
    {
        indexx2 = 0;
    }

    float _result = totalReadings2 / currentReadings;

    return abs((_result - 0.91) * (2.77 - 0.0) / (2.53 - 0.91) + 0.0);

    //return totalReadings2 / currentReadings; // * 2.36271
}
