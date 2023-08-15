/**
 * @file battery.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-08-12
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "battery.hpp"
#include "datatypes.hpp"

using namespace std;

float Battery::getBatteryVoltage(void)
{
    return batteryVoltage;
}

float Battery::getBatteryCurrent(void)
{
    return batteryCurrent;
}

float Battery::getBatteryCapacity(void)
{
    return batteryCapacity;
}

float Battery::getBatteryCharge(void)
{
    return batteryCharge;
}

void Battery::setBatteryVoltage(float voltage)
{
    batteryVoltage = voltage;
}

void Battery::setBatteryCurrent(float current)
{
    batteryCurrent = current;
}

void Battery::setBatteryCapacity(float capacity)
{
    batteryCapacity = capacity;
}

void Battery::setBatteryCharge(float charge)
{
    batteryCharge = charge;
}

// Path: battery\datatypes.hpp

int main(int argc, char **argv)
{
    // create a battery object
    Battery battery;
    battery.setBatteryVoltage(12);
    cout << "Battery's current voltage: " << battery.getBatteryVoltage() << endl;
    battery.setBatteryCurrent(1);
    cout << "Battery's current current: " << battery.getBatteryCurrent() << endl;
    battery.setBatteryCapacity(100);
    cout << "Battery's current capacity: " << battery.getBatteryCapacity() << endl;
    battery.setBatteryCharge(100);
    cout << "Battery's current charge: " << battery.getBatteryCharge() << endl;
    return 0;
}