#define CATCH_CONFIG_MAIN
#include "test/catch.hpp"
#include "Receiver/receiver.h"

SCENARIO("Test the computation of Simple Moving Average")
{
    GIVEN("Sensor value list set")
    {
        vector<int> sensorValueList={10,30,20,20,45,25,70,30,70,35};
        WHEN("Compute SMA for the last 5 entries of the list")
        {
            float avg=getSMA(sensorValueList,5);
            THEN("Verify if the computed average is as expected")
            {
                REQUIRE(avg==46.000000);
            }
        }
    }
}

SCENARIO("Test the computation of minimum value in the sensor data list")
{
    GIVEN("Sensor value list set")
    {
        vector<int> sensorValueList={10,30,20,30,45,25,70,30,70,35};
        WHEN("Compute minimum value for the entries of the list")
        {
            int minValue=getMinimumValue(sensorValueList);
            THEN("Verify if the computed min value is as expected")
            {
                REQUIRE(minValue==10);
            }
        }
    }
}

SCENARIO("Test the computation of minimum value in the sensor data list where the list contains single element")
{
    GIVEN("Sensor value list set")
    {
        vector<int> sensorValueList={20};
        WHEN("Compute minimum value for the entries of the list")
        {
            int minValue=getMinimumValue(sensorValueList);
            THEN("Verify if the computed min value is as expected")
            {
                REQUIRE(minValue==20);
            }
        }
    }
}

SCENARIO("Test the computation of maximum value in the sensor data list")
{
    GIVEN("Sensor value list set")
    {
        vector<int> sensorValueList={10,30,20,40,45,25,70,30,70,35};
        WHEN("Compute maximum value for the entries of the list")
        {
            int maxValue=getMaximumValue(sensorValueList);
            THEN("Verify if the computed max value is as expected")
            {
                REQUIRE(maxValue==70);
            }
        }
    }
}

SCENARIO("Test the computation of maximum value in the sensor data list where the list contains single element")
{
    GIVEN("Sensor value list set")
    {
        vector<int> sensorValueList={10};
        WHEN("Compute maximum value for the entries of the list")
        {
            int maxValue=getMaximumValue(sensorValueList);
            THEN("Verify if the computed max value is as expected")
            {
                REQUIRE(maxValue==10);
            }
        }
    }
}

SCENARIO("Test functionality to read Sensor data from Console using mock functionality")
{
    GIVEN("Mock current and temperature value list")
    {
        SensorData mockSensorDataValue;
        mockSensorDataValue.currentSensorValueList={100,30,20,20,45,25,70,30,90,25};
        mockSensorDataValue.temperatureSensorValueList={60,80,20,30,45,10,70,40,70,50};

        WHEN("Before generating the sensor statics, sensor values need to be read from console")
        {
            mockSensorDataReader dataReaderObject;
            dataReaderObject.mockSensorData=mockSensorDataValue;
            THEN("After creating the mock object, get the sensor data")
            {
                SensorData obtainedSensorData=dataReaderObject.readSensorDataFromConsole();
                REQUIRE(obtainedSensorData.currentSensorValueList==mockSensorDataValue.currentSensorValueList);
                REQUIRE(obtainedSensorData.temperatureSensorValueList==mockSensorDataValue.temperatureSensorValueList);
            }
        }
    }
}

SCENARIO("Test functionality to print Sensor statistics data using mock functionality")
{
    GIVEN("Mock current and temperature value list")
    {
        SensorData mockSensorValue;
        mockSensorValue.currentSensorValueList={100,30,20,20,45,25,80,30,90,35};
        mockSensorValue.temperatureSensorValueList={60,80,20,30,45,70,70,40,90,50};
        mockSensorDataReader dataReaderObject;
        dataReaderObject.mockSensorData=mockSensorValue;
        WHEN("Before generating the sensor statics, sensor values need to be read from console")
        {
            mockSensorDataPrinter dataPrinterObject;
            getSensorValueStatics(dataReaderObject,dataPrinterObject); 
            THEN("After creating the mock object, check the print functionality using behavioural testing")
            {
                REQUIRE(dataPrinterObject.printCounter==6);
                REQUIRE(dataPrinterObject.printStatsCounter==1);
            }
        }
    }
}

SCENARIO("Test the Sensor Value Statics obtained")
{
    GIVEN("Mock current and temperature value list")
    {
        SensorData mockSensorValue;
        mockSensorValue.currentSensorValueList={100,30,20,20,45,25,70,30,90,35};
        mockSensorValue.temperatureSensorValueList={60,80,20,30,45,10,70,40,90,50};
        mockSensorDataReader mockDataReaderObject;
        mockDataReaderObject.mockSensorData=mockSensorValue;
        WHEN("Before generating the sensor statics, sensor values need to be read from console and then compute the stats")
        {
            sensorDataPrinter dataPrinterObject;
            sensorValueStatistic sensorDataStats=getSensorValueStatics(mockDataReaderObject,dataPrinterObject); 
            THEN("After computing the stats, verify them")
            {
                REQUIRE(sensorDataStats.currentSMAValue==50.000000);  
    		    REQUIRE(sensorDataStats.temperatureSMAValue==52.000000);
    		    REQUIRE(sensorDataStats.minCurrentValue==20);
    		    REQUIRE(sensorDataStats.minTemperatureValue==10);
    		    REQUIRE(sensorDataStats.maxCurrentValue==100);
    		    REQUIRE(sensorDataStats.maxTemperatureValue==90);
            }
        }
    }
}
