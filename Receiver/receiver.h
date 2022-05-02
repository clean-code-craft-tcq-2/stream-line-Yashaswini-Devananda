#include <algorithm>
#include "RecieverUtility.h"

#define MAXIMUM_READING_COUNT 10
#define MAXIMUM_VALUE_COUNT 5

float getSMA(vector<int> sensorValueList, int numOfEntries)
{
    float total = 0;
    for(int sensorValueItr = MAXIMUM_READING_COUNT-numOfEntries; sensorValueItr < MAXIMUM_READING_COUNT; sensorValueItr++)
    {
        total += sensorValueList[sensorValueItr];
    }
    return (total/numOfEntries);
}

int getMinimumValue(vector<int> sensorValueList)
{
    return *min_element(sensorValueList.begin(),sensorValueList.end());
}

int getMaximumValue(vector<int> sensorValueList)
{
    return *max_element(sensorValueList.begin(),sensorValueList.end());
}

sensorValueStatistic computeCalculationOnSensorValue(SensorData sensorValue)
{
    sensorValueStatistic sensorValueStats;
    sensorValueStats.currentSMAValue = getSMA(sensorValue.currentSensorValueList, MAXIMUM_VALUE_COUNT);
    sensorValueStats.temperatureSMAValue = getSMA(sensorValue.temperatureSensorValueList, MAXIMUM_VALUE_COUNT);
    sensorValueStats.minCurrentValue = getMinimumValue(sensorValue.currentSensorValueList);
    sensorValueStats.minTemperatureValue = getMinimumValue(sensorValue.temperatureSensorValueList);
    sensorValueStats.maxCurrentValue = getMaximumValue(sensorValue.currentSensorValueList);
    sensorValueStats.maxTemperatureValue = getMaximumValue(sensorValue.temperatureSensorValueList);
    return sensorValueStats;
}

sensorValueStatistic getSensorValueStatics(sensorDataReaderInterface &dataReaderObject,printSensorDataInterface &sensorDataPrintObject)
{
    SensorData sensorValue=dataReaderObject.readSensorDataFromConsole();
    sensorValueStatistic sensorDataStats;
    if(!sensorValue.currentSensorValueList.empty() && !sensorValue.temperatureSensorValueList.empty())
    {
    	sensorDataStats=computeCalculationOnSensorValue(sensorValue);
    	sensorDataPrintObject.printSensorValueStasOnConsole(sensorDataStats);
    }
    return sensorDataStats;
}
