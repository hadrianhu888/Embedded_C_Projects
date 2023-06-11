/**
 * @file simulate_thermostat.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-06-10
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef SIMULATE_THERMOSTAT_HPP
#define SIMULATE_THERMOSTAT_HPP

#include "thermometer.hpp"
#include "digital_thermostat.hpp"

class SimulateThermostat : public Digital_Thermostat
{
private:
    float sensor;
    float temperature; 
    float actuator; 
    float humidity;
public:
    SimulateThermostat();
    SimulateThermostat(const SimulateThermostat &simulateThermostat);
    ~SimulateThermostat();
    float getSensor();
    float getTemperature();
    float getActuator();
    float getHumidity();
    void setActuator(float actuator);
    void setSensor(float sensor);
    void setTemperature(float temperature);
    void setHumidity(float humidity);
};

#endif // SIMULATE_THERMOSTAT_HPP