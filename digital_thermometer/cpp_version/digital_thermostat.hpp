/**
 * @file digital_thermostat.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-06-10
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef DIGITAL_THERMOSTAT_HPP
#define DIGITAL_THERMOSTAT_HPP

#include <stdio.h>
#include <iostream>
#include <string>
#include <stdbool.h>
#include <assert.h>
#include <vector>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <stdlib.h>
#include <stddef.h> 
#include <cmath> 

#include "thermometer.hpp"

using namespace std;

#define MAX_TEMPERATURE 100.0
#define MIN_TEMPERATURE 0.0
#define MAX_TEMPERATURE_ARRAY 100
#define MIN_TEMPERATURE_ARRAY 0

typedef struct Thermostat_States
{
    bool isOn;
    bool isOff;
    bool isIdle;
    bool isHeating;
    bool isCooling;
    bool isBroken;
} Thermostat_States;

typedef enum ThermoStat
{
    ON,
    OFF,
    IDLE,
    HEATING,
    COOLING,
    BROKEN
} ThermoStat;

typedef enum ThermoStatHWIO
{
    ON_HWIO,
    OFF_HWIO,
    IDLE_HWIO,
    HEATING_HWIO,
    COOLING_HWIO,
    BROKEN_HWIO
} ThermoStatHWIO;

class Digital_Thermostat: public Thermometer
{
private:
    float temperature;
    float maxTemperature;
    float minTemperature;
    float averageTemperature;
    float sumTemperature;
    int countTemperature;
    float *temperatureArray;
    int sizeTemperatureArray;
    Thermostat_States thermostatStates;
    ThermoStat thermoStat;
    ThermoStatHWIO thermoStatHWIO;
public:
    Digital_Thermostat();
    ~Digital_Thermostat();
    void setTemperature(float temperature);
    void setMaxTemperature(float maxTemperature);
    void setMinTemperature(float minTemperature);
    void setAverageTemperature(float averageTemperature);
    void setSumTemperature(float sumTemperature);
    void setCountTemperature(int countTemperature);
    void setTemperatureArray(float *temperatureArray);
    void setSizeTemperatureArray(int sizeTemperatureArray);
    void setThermostatStates(Thermostat_States thermostatStates);
    float getTemperature();
    float getMaxTemperature();
    float getMinTemperature();
    float getAverageTemperature();
    float getSumTemperature();
    int getCountTemperature();
    float *getTemperatureArray();
    int getSizeTemperatureArray();
    Thermostat_States getThermostatStates();
    ThermoStat getThermoStat();
    ThermoStatHWIO getThermoStatHWIO();
    void turnOn();
    void turnOff();
    void idle();
    void heating();
    void cooling();
    void broken();
    void printThermostatStates();
    void printTemperatureArray();
    void printTemperatureArray(int sizeTemperatureArray);
    void printTemperatureArray(float *temperatureArray);
    void updateTemperatureArray(float temperature);
    void updateMaxTemperature(float temperature);
    void updateMinTemperature(float temperature);
    void updateAverageTemperature(float temperature);
    void updateSumTemperature(float temperature);
    void updateCountTemperature();
    void updateThermostatStates();
    void updateThermoStat();
    void updateThermoStatHWIO();
    void updateThermostatStates(Thermostat_States thermostatStates);
    void updateThermoStat(ThermoStat thermoStat);
    void updateThermoStatHWIO(ThermoStatHWIO thermoStatHWIO);
    void updateTemperature(float temperature);
    void updateThermostat(float temperature, Thermostat_States state);
    void updateThermostat(float temperature, ThermoStat thermoStat); 
    void updateThermostat(float temperature, ThermoStatHWIO thermoStatHWIO);
    void updateThermostat(float temperature, Thermostat_States state, ThermoStatHWIO thermoStatHWIO);
    void updateThermostat(float temperature, Thermostat_States state, ThermoStat thermoStat);
    void updateThermostat(float temperature, Thermostat_States state, ThermoStat thermoStat, ThermoStatHWIO thermoStatHWIO);
    void updateThermostat(float temperature, ThermoStatHWIO thermoStatHWIO, ThermoStat thermoStat);
};

#endif // DIGITAL_THERMOSTAT_HPP