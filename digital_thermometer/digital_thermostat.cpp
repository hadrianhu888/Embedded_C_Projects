/**
 * @file digital_thermostat.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-06-10
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "thermometer.hpp"
#include "digital_thermostat.hpp"

/**
 * @brief 
 * typedef struct Thermostat_States
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
};

 * 
 */

Digital_Thermostat::Digital_Thermostat()
{
    this->temperature = 0.0;
    this->maxTemperature = 0.0;
    this->minTemperature = 0.0;
    this->averageTemperature = 0.0;
    this->sumTemperature = 0.0;
    this->countTemperature = 0;
    this->temperatureArray = NULL;
    this->sizeTemperatureArray = 0;
    this->thermostatStates.isOn = false;
    this->thermostatStates.isOff = false;
    this->thermostatStates.isIdle = false;
    this->thermostatStates.isHeating = false;
    this->thermostatStates.isCooling = false;
    this->thermostatStates.isBroken = false;
    this->thermoStat = OFF;
    this->thermoStatHWIO = OFF_HWIO;
}

Digital_Thermostat::~Digital_Thermostat()
{
    if (this->temperatureArray != NULL)
    {
        delete[] this->temperatureArray;
    }
}

void Digital_Thermostat::setTemperature(float temperature)
{
    this->temperature = temperature;
}

void Digital_Thermostat::setMaxTemperature(float maxTemperature)
{
    this->maxTemperature = maxTemperature;
}

void Digital_Thermostat::setMinTemperature(float minTemperature)
{
    this->minTemperature = minTemperature;
}

void Digital_Thermostat::setAverageTemperature(float averageTemperature)
{
    this->averageTemperature = averageTemperature;
}

void Digital_Thermostat::setSumTemperature(float sumTemperature)
{
    this->sumTemperature = sumTemperature;
}

void Digital_Thermostat::setCountTemperature(int countTemperature)
{
    this->countTemperature = countTemperature;
}

void Digital_Thermostat::setTemperatureArray(float *temperatureArray)
{
    this->temperatureArray = temperatureArray;
}

void Digital_Thermostat::setSizeTemperatureArray(int sizeTemperatureArray)
{
    this->sizeTemperatureArray = sizeTemperatureArray;
}

void Digital_Thermostat::setThermostatStates(Thermostat_States thermostatStates)
{
    this->thermostatStates = thermostatStates;
}

float Digital_Thermostat::getTemperature()
{
    return this->temperature;
}

float Digital_Thermostat::getMaxTemperature()
{
    return this->maxTemperature;
}

float Digital_Thermostat::getMinTemperature()
{
    return this->minTemperature;
}

float Digital_Thermostat::getAverageTemperature()
{
    return this->averageTemperature;
}

float Digital_Thermostat::getSumTemperature()
{
    return this->sumTemperature;
}

int Digital_Thermostat::getCountTemperature()
{
    return this->countTemperature;
}

float *Digital_Thermostat::getTemperatureArray()
{
    return this->temperatureArray;
}

int Digital_Thermostat::getSizeTemperatureArray()
{
    return this->sizeTemperatureArray;
}

Thermostat_States Digital_Thermostat::getThermostatStates()
{
    return this->thermostatStates;
}

ThermoStat Digital_Thermostat::getThermoStat()
{
    return this->thermoStat;
}

ThermoStatHWIO Digital_Thermostat::getThermoStatHWIO()
{
    return this->thermoStatHWIO;
}

void Digital_Thermostat::turnOn()
{
    this->thermostatStates.isOn = true;
    this->thermostatStates.isOff = false;
    this->thermostatStates.isIdle = false;
    this->thermostatStates.isHeating = false;
    this->thermostatStates.isCooling = false;
    this->thermostatStates.isBroken = false;
    this->thermoStat = ON;
    this->thermoStatHWIO = ON_HWIO;
}

void Digital_Thermostat::turnOff()
{
    this->thermostatStates.isOn = false;
    this->thermostatStates.isOff = true;
    this->thermostatStates.isIdle = false;
    this->thermostatStates.isHeating = false;
    this->thermostatStates.isCooling = false;
    this->thermostatStates.isBroken = false;
    this->thermoStat = OFF;
    this->thermoStatHWIO = OFF_HWIO;
}

void Digital_Thermostat::idle()
{
    this->thermostatStates.isOn = false;
    this->thermostatStates.isOff = false;
    this->thermostatStates.isIdle = true;
    this->thermostatStates.isHeating = false;
    this->thermostatStates.isCooling = false;
    this->thermostatStates.isBroken = false;
    this->thermoStat = IDLE;
    this->thermoStatHWIO = IDLE_HWIO;
}

void Digital_Thermostat::heating()
{
    this->thermostatStates.isOn = false;
    this->thermostatStates.isOff = false;
    this->thermostatStates.isIdle = false;
    this->thermostatStates.isHeating = true;
    this->thermostatStates.isCooling = false;
    this->thermostatStates.isBroken = false;
    this->thermoStat = HEATING;
    this->thermoStatHWIO = HEATING_HWIO;
}

void Digital_Thermostat::cooling()
{
    this->thermostatStates.isOn = false;
    this->thermostatStates.isOff = false;
    this->thermostatStates.isIdle = false;
    this->thermostatStates.isHeating = false;
    this->thermostatStates.isCooling = true;
    this->thermostatStates.isBroken = false;
    this->thermoStat = COOLING;
    this->thermoStatHWIO = COOLING_HWIO;
}

void Digital_Thermostat::broken()
{
    this->thermostatStates.isOn = false;
    this->thermostatStates.isOff = false;
    this->thermostatStates.isIdle = false;
    this->thermostatStates.isHeating = false;
    this->thermostatStates.isCooling = false;
    this->thermostatStates.isBroken = true;
    this->thermoStat = BROKEN;
    this->thermoStatHWIO = BROKEN_HWIO;
}

void Digital_Thermostat::updateTemperatureArray(float temperature)
{
    if (this->temperatureArray == NULL)
    {
        this->temperatureArray = new float[1];
        this->temperatureArray[0] = temperature;
        this->sizeTemperatureArray = 1;
    }
    else
    {
        float *tempArray = new float[this->sizeTemperatureArray + 1];
        for (int i = 0; i < this->sizeTemperatureArray; i++)
        {
            tempArray[i] = this->temperatureArray[i];
        }
        tempArray[this->sizeTemperatureArray] = temperature;
        delete[] this->temperatureArray;
        this->temperatureArray = tempArray;
        this->sizeTemperatureArray++;
    }
}

void Digital_Thermostat::updateMaxTemperature(float temperature)
{
    if (this->maxTemperature < temperature)
    {
        this->maxTemperature = temperature;
    }
}

void Digital_Thermostat::updateMinTemperature(float temperature)
{
    if (this->minTemperature > temperature)
    {
        this->minTemperature = temperature;
    }
}

void Digital_Thermostat::updateAverageTemperature(float temperature)
{
    this->sumTemperature += temperature;
    this->countTemperature++;
    this->averageTemperature = this->sumTemperature / this->countTemperature;
}

void Digital_Thermostat::updateTemperature(float temperature)
{
    this->temperature = temperature;
    this->updateTemperatureArray(temperature);
    this->updateMaxTemperature(temperature);
    this->updateMinTemperature(temperature);
    this->updateAverageTemperature(temperature);
}

void Digital_Thermostat::updateThermostatStates()
{
    if (this->thermostatStates.isOn)
    {
        this->turnOn();
    }
    else if (this->thermostatStates.isOff)
    {
        this->turnOff();
    }
    else if (this->thermostatStates.isIdle)
    {
        this->idle();
    }
    else if (this->thermostatStates.isHeating)
    {
        this->heating();
    }
    else if (this->thermostatStates.isCooling)
    {
        this->cooling();
    }
    else if (this->thermostatStates.isBroken)
    {
        this->broken();
    }
}

void Digital_Thermostat::updateThermostatStates(Thermostat_States thermostatStates)
{
    this->thermostatStates = thermostatStates;
    this->updateThermostatStates();
}

void Digital_Thermostat::updateThermoStat()
{
    if (this->thermoStat == ON)
    {
        this->turnOn();
    }
    else if (this->thermoStat == OFF)
    {
        this->turnOff();
    }
    else if (this->thermoStat == IDLE)
    {
        this->idle();
    }
    else if (this->thermoStat == HEATING)
    {
        this->heating();
    }
    else if (this->thermoStat == COOLING)
    {
        this->cooling();
    }
    else if (this->thermoStat == BROKEN)
    {
        this->broken();
    }
}

void Digital_Thermostat::updateThermoStat(ThermoStat thermoStat)
{
    this->thermoStat = thermoStat;
    this->updateThermoStat();
}

void Digital_Thermostat::updateThermoStatHWIO()
{
    if (this->thermoStatHWIO == ON_HWIO)
    {
        this->turnOn();
    }
    else if (this->thermoStatHWIO == OFF_HWIO)
    {
        this->turnOff();
    }
    else if (this->thermoStatHWIO == IDLE_HWIO)
    {
        this->idle();
    }
    else if (this->thermoStatHWIO == HEATING_HWIO)
    {
        this->heating();
    }
    else if (this->thermoStatHWIO == COOLING_HWIO)
    {
        this->cooling();
    }
    else if (this->thermoStatHWIO == BROKEN_HWIO)
    {
        this->broken();
    }
}

void Digital_Thermostat::updateThermoStatHWIO(ThermoStatHWIO thermoStatHWIO)
{
    this->thermoStatHWIO = thermoStatHWIO;
    this->updateThermoStatHWIO();
}




