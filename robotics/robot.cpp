/**
 * @file robot.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-06-13
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <math.h>
#include <iostream>
#include "datatypes.hpp"
#include "robot.hpp"
#include "robot_cntrl.hpp"
#include <cmath>
#include <complex>
#include <string>

#include "robot.hpp"

using namespace std;

// constructor
Robot::Robot(double x, double y) : posX(x), posY(y) {}

// forward movement
void Robot::moveForward(double distance)
{
  // We assume the robot moves in the positive y-direction when moving forward
  posY += distance;
}

// backward movement
void Robot::moveBackward(double distance)
{
  // We assume the robot moves in the negative y-direction when moving backward
  posY -= distance;
}

// right turn
void Robot::turnRight(double angle)
{
  // The robot stays at the same position but turns a certain angle to the right
  // In a real-life scenario, you'd need to implement how to control the robot's
  // direction
  posX += cos(angle);
}

// left turn
void Robot::turnLeft(double angle)
{
  // The robot stays at the same position but turns a certain angle to the left
  // In a real-life scenario, you'd need to implement how to control the robot's
  // direction
  posX -= sin(angle);
}

// get current x position
double Robot::getPosX() { return posX; }

// get current y position
double Robot::getPosY() { return posY; }

// get the delta vector between the robot's current position and a given position

double Robot::getDeltaVector(double x, double y)
{
  double deltaX = x - posX;
  double deltaY = y - posY;
  return sqrt(pow(deltaX, 2) + pow(deltaY, 2));
}

// get the delta angle between the robot's current position and a given position

double Robot::getDeltaTheta(double x, double y)
{
  double deltaX = x - posX;
  double deltaY = y - posY;
  return atan2(deltaY, deltaX);
}

/* int main(int argc, char **argv)
{
  Robot robot;
  robot.moveForward(10);
  robot.moveBackward(10);
  robot.turnRight(90);
  robot.turnLeft(90);
  cout << "Hello World!" << endl;
  return 0;
} */