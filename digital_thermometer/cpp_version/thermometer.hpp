/**
 * @file thermometer.hpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-06-09
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef THERMOMETER_HPP
#define THERMOMETER_HPP

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cstdio>

using namespace std;

class Thermometer
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

protected:
    void setTemperature(float temperature);
    void setMaxTemperature(float maxTemperature);
    void setMinTemperature(float minTemperature);
    void setAverageTemperature(float averageTemperature);
    void setSumTemperature(float sumTemperature);
    void setCountTemperature(int countTemperature);
    void setTemperatureArray(float *temperatureArray);
    void setSizeTemperatureArray(int sizeTemperatureArray);

public:
    float getTemperature();
    float getMaxTemperature();
    float getMinTemperature();
    float getAverageTemperature();
    float getSumTemperature();
    int getCountTemperature();
    float *getTemperatureArray();
    float calculateMaxTemperature();
    float calculateMinTemperature();
    float calculateAverageTemperature();
    float calculateSumTemperature();
    int getSizeTemperatureArray();
    void addTemperature(float temperature);
    void removeTemperature(float temperature);
    void printTemperature();
    void printMaxTemperature();
    void printMinTemperature();
    void printAverageTemperature();
    void printSumTemperature();
    void printCountTemperature();
    void printTemperatureArray();
    void printSizeTemperatureArray();
    void printAll();
    void clearTemperature();
    void clearMaxTemperature();
    void clearMinTemperature();
    void clearAverageTemperature();
    void clearSumTemperature();
    void clearCountTemperature();
    void clearTemperatureArray();
    void clearSizeTemperatureArray();
    void clearAll();
    Thermometer();
    ~Thermometer();
    vector<float> temperatureVector;
    vector<float> getTemperatureVector();
    vector<float> getMaxTemperatureVector();
    vector<float> getMinTemperatureVector();
    vector<float> getAverageTemperatureVector();
    vector<float> getSumTemperatureVector();
    vector<float> getCountTemperatureVector();
    void addTemperatureVector(float temperature);
    void removeTemperatureVector(float temperature);
    void printTemperatureVector();
    void clearTemperatureVector();
    void printTemperatureVectorSize();
    void printAllVector();
};

#endif // THERMOMETER_H
