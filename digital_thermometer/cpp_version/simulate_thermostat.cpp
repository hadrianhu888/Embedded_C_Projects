/**
 * @file simulate_thermostate.cpp
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
#include "simulate_thermostat.hpp"

SimulateThermostat::SimulateThermostat()
{
    this->sensor = 0.0;
    this->temperature = 0.0;
    this->actuator = 0.0;
}

SimulateThermostat::SimulateThermostat(const SimulateThermostat &simulateThermostat)
{
    this->sensor = simulateThermostat.sensor;
    this->temperature = simulateThermostat.temperature;
    this->actuator = simulateThermostat.actuator;
}

SimulateThermostat::~SimulateThermostat()
{
}

float SimulateThermostat::getSensor()
{
    return this->sensor;
}

float SimulateThermostat::getTemperature()
{
    return this->temperature;
}

float SimulateThermostat::getActuator()
{
    return this->actuator;
}

float SimulateThermostat::getHumidity()
{
    return this->humidity;
}

void SimulateThermostat::setActuator(float actuator)
{
    this->actuator = actuator;
}

void SimulateThermostat::setSensor(float sensor)
{
    this->sensor = sensor;
}

void SimulateThermostat::setTemperature(float temperature)
{
    this->temperature = temperature;
}

void SimulateThermostat::setHumidity(float humidity)
{
    this->humidity = humidity;
}


