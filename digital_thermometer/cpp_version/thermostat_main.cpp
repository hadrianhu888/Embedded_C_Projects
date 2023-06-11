/**
 * @file thermostat_main.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-06-10
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "thermometer.cpp"
#include "digital_thermostat.cpp"
#include "simulate_thermostat.cpp"

int main(int argc, char **argv); 

int main(int argc, char **argv)
{
    SimulateThermostat simulateThermostat;
    Digital_Thermostat digitalThermostat;
    Thermometer thermometer;
    vector<float> temperatureArray;
    float temperature = 0.0;
    float temperatureAverage = 0.0;
    float temperatureSum = 0.0;
    float temperatureMax = 0.0;
    float temperatureMin = 0.0;
    float temperatureRange = 0.0;
    float temperatureStandardDeviation = 0.0;
    return 0;
}

