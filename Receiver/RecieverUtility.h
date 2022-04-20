#include <iostream> 
#include <vector>
using namespace std;

#define MAXIMUM_READING_COUNT 10
#define MAXIMUM_VALUE_COUNT 5

struct SensorData
{
    vector<int> currentSensorValueList;
    vector<int> temperatureSensorValueList;
};

struct sensorValueStatistic
{
    float currentSMAValue;
    float temperatureSMAValue;
    int minCurrentValue;
    int minTemperatureValue;
    int maxCurrentValue;
    int maxTemperatureValue;
};

class sensorDataReaderInterface
{
public:
     virtual SensorData readSensorDataFromConsole()=0;
};

class sensorDataReader: public sensorDataReaderInterface
{
   public:
       SensorData readSensorDataFromConsole()
       {
            SensorData sensorValue;
    	    string seperator;
            for(int i = 0; i < 10; i++)
            {
	        cin >> sensorValue.currentSensorValueList[i] >> seperator >> sensorValue.temperatureSensorValueList[i];
            }
            return sensorValue;
       }
};

class mockSensorDataReader: public sensorDataReaderInterface
{
  public:
       int readCounter=0;
       SensorData mockSensorData;

       SensorData readSensorDataFromConsole()
       {
            SensorData sensorValue;
            for(int sensorValueItr = 0; sensorValueItr < MAXIMUM_READING_COUNT; sensorValueItr++)
            {
                if(mockSensorData.currentSensorValueList.size()==MAXIMUM_READING_COUNT && mockSensorData.temperatureSensorValueList.size()==MAXIMUM_READING_COUNT)
    		{
                   sensorValue.currentSensorValueList.push_back(mockSensorData.currentSensorValueList[sensorValueItr]);
    		   sensorValue.temperatureSensorValueList.push_back(mockSensorData.temperatureSensorValueList[sensorValueItr]);
                   readCounter++;
 		}
            }
            return sensorValue;
      }
};

class printSensorDataInterface
{
public:
     virtual void printDataOnconsole(std::string message, std::string sensorValue)=0;
     virtual void printSensorValueStasOnConsole(sensorValueStatistic sensorValue)=0;
};

class sensorDataPrinter: public printSensorDataInterface
{
   public:
       void printDataOnconsole(std::string message, std::string sensorValue)
       {
           cout<<message<<sensorValue<<"\n";
       }
       void printSensorValueStasOnConsole(sensorValueStatistic sensorValueStats)
       {
    	   printDataOnconsole("Simple moving average: Current sensor value=",std::to_string(sensorValueStats.currentSMAValue));
    	   printDataOnconsole("Simple moving average: Temperature sensor value=", std::to_string(sensorValueStats.temperatureSMAValue));
    	   printDataOnconsole("Current sensor minimum value=", std::to_string(sensorValueStats.minCurrentValue));
    	   printDataOnconsole("Temperature sensor minimum value=",std::to_string(sensorValueStats.minTemperatureValue));
    	   printDataOnconsole("Current sensor maximum value=", std::to_string(sensorValueStats.maxCurrentValue));
    	   printDataOnconsole("Temperature sensor maximum value=",std::to_string(sensorValueStats.maxTemperatureValue));
      }
};

class mockSensorDataPrinter: public printSensorDataInterface
{
   public:
       int printCounter=0,printStatsCounter=0;
       void printDataOnconsole(std::string /*message*/, std::string /*sensorValue*/)
       {
           printCounter++;
       }
       void printSensorValueStasOnConsole(sensorValueStatistic /*sensorValue*/)
       {
           printDataOnconsole("SMA:Current","");
           printDataOnconsole("SMA:Temp","");
           printDataOnconsole("Min:Current","");
           printDataOnconsole("Max:Temp","");
           printDataOnconsole("Min:Current","");
           printDataOnconsole("Max:Temp","");
    	   printStatsCounter++;
       }
};
