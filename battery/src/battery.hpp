/**
 * @file battery.hpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-08-12
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef BATTERY_HPP_
#define BATTERY_HPP_

#include <assert.h>
#include <ctype.h>
#include <float.h>

#include <iostream>
#include <limits.h>
#include <math.h>

#include <stdbool.h>
#include <stddef.h>

#include "datatypes.hpp"

using namespace std;

class Battery
{
private:
    float batteryVoltage;
    float batteryCurrent;
    float batteryCapacity;
    float batteryCharge;

public:
    float getBatteryVoltage(void);
    float getBatteryCurrent(void);
    float getBatteryCapacity(void);
    float getBatteryCharge(void);
    void setBatteryVoltage(float voltage);
    void setBatteryCurrent(float current);
    void setBatteryCapacity(float capacity);
    void setBatteryCharge(float charge);
};

#endif /* BATTERY_HPP_ */
