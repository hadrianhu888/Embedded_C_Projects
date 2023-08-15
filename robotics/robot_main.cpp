/**
 * @file robot_main.c
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-06-13
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <stdio.h>

#include <iostream>
#include <cmath>
#include <math.h>

#include "datatypes.hpp"
#include "robot.hpp"
#include "robot.cpp"
#include "robot_cntrl.hpp"
#include "robot_cntrl.cpp"

using namespace std;

int main(void);

int main(void)
{
    // create a robot object
    Robot robot;
    robot.moveForward(1);
    cout << "Robot's current position: (" << robot.getPosX() << ", " << robot.getPosY() << ")" << endl;
    robot.turnRight(PI / 2);
    cout << "Robot's current position: (" << robot.getPosX() << ", " << robot.getPosY() << ")" << endl;
    robot.moveForward(1);
    cout << "Robot's current position: (" << robot.getPosX() << ", " << robot.getPosY() << ")" << endl;
    robot.turnLeft(PI / 2);
    cout << "Robot's current position: (" << robot.getPosX() << ", " << robot.getPosY() << ")" << endl;
    robot.moveForward(1);
    cout << "Robot's current position: (" << robot.getPosX() << ", " << robot.getPosY() << ")" << endl;
    robot.turnLeft(PI / 2);
    cout << "Robot's current position: (" << robot.getPosX() << ", " << robot.getPosY() << ")" << endl;
    robot.moveForward(1);
    cout << "Robot's current position: (" << robot.getPosX() << ", " << robot.getPosY() << ")" << endl;
    robot.getDeltaVector(1, 1);
    cout << "Robot's current position: (" << robot.getPosX() << ", " << robot.getPosY() << ")" << endl;
    robot.getDeltaTheta(1, 1);
    cout << "Robot's current position: (" << robot.getPosX() << ", " << robot.getPosY() << ")" << endl;
    // print vector and theta values
    cout << "Robot's current vector: (" << robot.getVectorX() << ", " << robot.getVectorY() << ")" << endl;
    cout << "Robot's current theta: " << robot.getTheta() << endl;
    // print robot's current position
    cout << "Robot's current position: (" << robot.getPosX() << ", " << robot.getPosY() << ")" << endl;
    return 0;
}