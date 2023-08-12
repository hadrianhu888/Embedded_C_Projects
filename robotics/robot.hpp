/**
 * @file robot.hpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-06-19
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef ROBOT_HPP
#define ROBOT_HPP

#include <iostream>
#include <cmath>
#include <math.h>

using namespace std;

class Robot
{
private:
    // assuming we can control the robot's position through these values
    double posX;
    double posY;

public:
    Robot(double x = 0, double y = 0); // constructor with default position (0,0)

    // methods to control the robot
    void moveForward(double distance);
    void moveBackward(double distance);
    void turnRight(double angle);
    void turnLeft(double angle);

    // methods to get the robot's position
    double getPosX();
    double getPosY();
};

#endif // ROBOT_HPP
