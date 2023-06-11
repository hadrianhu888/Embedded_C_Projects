/**
 * @file thermometer.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-06-09
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "thermometer.hpp"

#include <iostream>

using namespace std;
/**
 * @brief 
 * class Thermometer
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
};

 * 
 */

float Thermometer::getTemperature()
{
    return temperature;
}

float Thermometer::getMaxTemperature()
{
    return maxTemperature = calculateMaxTemperature();
}

float Thermometer::getMinTemperature()
{
    return minTemperature = calculateMinTemperature();
}

float Thermometer::getAverageTemperature()
{
    return averageTemperature = calculateAverageTemperature();
}

float Thermometer::getSumTemperature()
{
    return sumTemperature = calculateSumTemperature();
}

float Thermometer::calculateAverageTemperature()
{
    float sum = 0;
    for (int i = 0; i < countTemperature; i++)
    {
        sum += temperatureArray[i];
    }
    return sum / countTemperature;
}

float Thermometer::calculateSumTemperature()
{
    float sum = 0;
    for (int i = 0; i < countTemperature; i++)
    {
        sum += temperatureArray[i];
    }
    return sum;
}

float Thermometer::calculateMaxTemperature()
{
    float max = temperatureArray[0];
    for (int i = 0; i < countTemperature; i++)
    {
        if (temperatureArray[i] > max)
        {
            max = temperatureArray[i];
        }
    }
    return max;
}

float Thermometer::calculateMinTemperature()
{
    float min = temperatureArray[0];
    for (int i = 0; i < countTemperature; i++)
    {
        if (temperatureArray[i] < min)
        {
            min = temperatureArray[i];
        }
    }
    return min;
}

int Thermometer::getCountTemperature()
{
    return countTemperature;
}

float *Thermometer::getTemperatureArray()
{
    return temperatureArray;
}

int Thermometer::getSizeTemperatureArray()
{
    return sizeTemperatureArray;
}

void Thermometer::addTemperature(float temperature)
{
    if (countTemperature < sizeTemperatureArray)
    {
        temperatureArray[countTemperature] = temperature;
        countTemperature++;
        sumTemperature += temperature;
        averageTemperature = sumTemperature / countTemperature;
        if (temperature > maxTemperature)
        {
            maxTemperature = temperature;
        }
        if (temperature < minTemperature)
        {
            minTemperature = temperature;
        }
    }
    else
    {
        cout << "Error: Array is full" << endl;
    }
}

void Thermometer::removeTemperature(float temperature)
{
    if (countTemperature > 0)
    {
        for (int i = 0; i < countTemperature; i++)
        {
            if (temperatureArray[i] == temperature)
            {
                for (int j = i; j < countTemperature - 1; j++)
                {
                    temperatureArray[j] = temperatureArray[j + 1];
                }
                countTemperature--;
                sumTemperature -= temperature;
                averageTemperature = sumTemperature / countTemperature;
                if (temperature == maxTemperature)
                {
                    maxTemperature = temperatureArray[0];
                    for (int j = 0; j < countTemperature; j++)
                    {
                        if (temperatureArray[j] > maxTemperature)
                        {
                            maxTemperature = temperatureArray[j];
                        }
                    }
                }
                if (temperature == minTemperature)
                {
                    minTemperature = temperatureArray[0];
                    for (int j = 0; j < countTemperature; j++)
                    {
                        if (temperatureArray[j] < minTemperature)
                        {
                            minTemperature = temperatureArray[j];
                        }
                    }
                }
                break;
            }
        }
    }
    else
    {
        cout << "Error: Array is empty" << endl;
    }
}

void Thermometer::printTemperature()
{
    cout << "Temperature: " << temperature << endl;
}

void Thermometer::printMaxTemperature()
{
    cout << "Max Temperature: " << maxTemperature << endl;
}

void Thermometer::printMinTemperature()
{
    cout << "Min Temperature: " << minTemperature << endl;
}

void Thermometer::printAverageTemperature()
{
    cout << "Average Temperature: " << averageTemperature << endl;
}

void Thermometer::printSumTemperature()
{
    cout << "Sum Temperature: " << sumTemperature << endl;
}

void Thermometer::printCountTemperature()
{
    cout << "Count Temperature: " << countTemperature << endl;
}

void Thermometer::printTemperatureArray()
{
    cout << "Temperature Array: ";
    for (int i = 0; i < countTemperature; i++)
    {
        cout << temperatureArray[i] << " ";
    }
    cout << endl;
}

void Thermometer::printSizeTemperatureArray()
{
    cout << "Size Temperature Array: " << sizeTemperatureArray << endl;
}

void Thermometer::printAll()
{
    printTemperature();
    printMaxTemperature();
    printMinTemperature();
    printAverageTemperature();
    printSumTemperature();
    printCountTemperature();
    printTemperatureArray();
    printSizeTemperatureArray();
}

void Thermometer::clearTemperature()
{
    temperature = 0;
}

void Thermometer::clearMaxTemperature()
{
    maxTemperature = 0;
}

void Thermometer::clearMinTemperature()
{
    minTemperature = 0;
}

void Thermometer::clearAverageTemperature()
{
    averageTemperature = 0;
}

void Thermometer::clearSumTemperature()
{
    sumTemperature = 0;
}

void Thermometer::clearCountTemperature()
{
    countTemperature = 0;
}

void Thermometer::clearTemperatureArray()
{
    for (int i = 0; i < sizeTemperatureArray; i++)
    {
        temperatureArray[i] = 0;
    }
}

void Thermometer::clearSizeTemperatureArray()
{
    sizeTemperatureArray = 0;
}

void Thermometer::clearAll()
{
    clearTemperature();
    clearMaxTemperature();
    clearMinTemperature();
    clearAverageTemperature();
    clearSumTemperature();
    clearCountTemperature();
    clearTemperatureArray();
    clearSizeTemperatureArray();
}

Thermometer::Thermometer()
{
    temperature = 0;
    maxTemperature = 0;
    minTemperature = 0;
    averageTemperature = 0;
    sumTemperature = 0;
    countTemperature = 0;
    temperatureArray = new float[100];
    sizeTemperatureArray = 100;
}

Thermometer::~Thermometer()
{
    delete[] temperatureArray;
}

void Thermometer::addTemperatureVector(float temperature)
{
    temperatureVector.push_back(temperature);
}

void Thermometer::removeTemperatureVector(float temperature)
{
    for (int i = 0; i < temperatureVector.size(); i++)
    {
        if (temperatureVector[i] == temperature)
        {
            temperatureVector.erase(temperatureVector.begin() + i);
            break;
        }
    }
}

void Thermometer::printTemperatureVector()
{
    cout << "Temperature Vector: ";
    for (int i = 0; i < temperatureVector.size(); i++)
    {
        cout << temperatureVector[i] << " ";
    }
    cout << endl;
}

void Thermometer::clearTemperatureVector()
{
    temperatureVector.clear();
}

void Thermometer::printAllVector()
{
    printTemperatureVector();
}

vector<float> Thermometer::getTemperatureVector()
{
    return temperatureVector;
}

vector<float> Thermometer::getMaxTemperatureVector()
{
    vector<float> maxTemperatureVector;
    float maxTemperature = temperatureVector[0];
    for (int i = 0; i < temperatureVector.size(); i++)
    {
        if (temperatureVector[i] > maxTemperature)
        {
            maxTemperature = temperatureVector[i];
        }
    }
    for (int i = 0; i < temperatureVector.size(); i++)
    {
        if (temperatureVector[i] == maxTemperature)
        {
            maxTemperatureVector.push_back(temperatureVector[i]);
        }
    }
    return maxTemperatureVector;
}

vector<float> Thermometer::getMinTemperatureVector()
{
    vector<float> minTemperatureVector;
    float minTemperature = temperatureVector[0];
    for (int i = 0; i < temperatureVector.size(); i++)
    {
        if (temperatureVector[i] < minTemperature)
        {
            minTemperature = temperatureVector[i];
        }
    }
    for (int i = 0; i < temperatureVector.size(); i++)
    {
        if (temperatureVector[i] == minTemperature)
        {
            minTemperatureVector.push_back(temperatureVector[i]);
        }
    }
    return minTemperatureVector;
}

vector<float> Thermometer::getAverageTemperatureVector()
{
    vector<float> averageTemperatureVector;
    float averageTemperature = 0;
    for (int i = 0; i < temperatureVector.size(); i++)
    {
        averageTemperature += temperatureVector[i];
    }
    averageTemperature /= temperatureVector.size();
    for (int i = 0; i < temperatureVector.size(); i++)
    {
        if (temperatureVector[i] == averageTemperature)
        {
            averageTemperatureVector.push_back(temperatureVector[i]);
        }
    }
    return averageTemperatureVector;
}

vector<float> Thermometer::getSumTemperatureVector()
{
    vector<float> sumTemperatureVector;
    float sumTemperature = 0;
    for (int i = 0; i < temperatureVector.size(); i++)
    {
        sumTemperature += temperatureVector[i];
    }
    for (int i = 0; i < temperatureVector.size(); i++)
    {
        if (temperatureVector[i] == sumTemperature)
        {
            sumTemperatureVector.push_back(temperatureVector[i]);
        }
    }
    return sumTemperatureVector;
}

vector<float> Thermometer::getCountTemperatureVector()
{
    vector<float> countTemperatureVector;
    float countTemperature = temperatureVector.size();
    for (int i = 0; i < temperatureVector.size(); i++)
    {
        if (temperatureVector[i] == countTemperature)
        {
            countTemperatureVector.push_back(temperatureVector[i]);
        }
    }
    return countTemperatureVector;
}

/* int main(int argc, char **argv)
{
    vector<float> temperatureVector;
    Thermometer thermometer;
    thermometer.addTemperature(10);
    thermometer.addTemperature(20);
    thermometer.addTemperature(30);
    thermometer.addTemperature(40);
    thermometer.addTemperature(50);
    thermometer.addTemperature(60);
    thermometer.addTemperature(70);
    // test all other functions 
    thermometer.addTemperatureVector(10);
    thermometer.addTemperatureVector(20);
    thermometer.addTemperatureVector(30);
    thermometer.removeTemperatureVector(20);
    thermometer.calculateMaxTemperature();
    thermometer.calculateMinTemperature();
    thermometer.calculateAverageTemperature();
    thermometer.calculateSumTemperature();
    thermometer.getCountTemperature();
    thermometer.printTemperature();
    thermometer.printMaxTemperature();
    thermometer.printMinTemperature();
    thermometer.printAverageTemperature();
    thermometer.printSumTemperature();
    return 0;
} */ 