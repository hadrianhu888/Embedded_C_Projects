/**
 * @file robot_cntrl.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-06-24
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "robot_cntrl.hpp"

void robot_cntrl_init(robot_cntrl_t *robot_cntrl) {
	robot_cntrl->x = 0;
	robot_cntrl->y = 0;
	robot_cntrl->theta = 0;
	robot_cntrl->x_dot = 0;
	robot_cntrl->y_dot = 0;
	robot_cntrl->theta_dot = 0;
}

void robot_cntrl_set_pos(robot_cntrl_t *robot_cntrl, float x, float y,float theta) 
{
	robot_cntrl->x = x;
	robot_cntrl->y = y;
	robot_cntrl->theta = theta;
}

void robot_cntrl_set_vel(robot_cntrl_t *robot_cntrl, float x_dot, float y_dot,
                         float theta_dot) {
  robot_cntrl->x_dot = x_dot;
  robot_cntrl->y_dot = y_dot;
  robot_cntrl->theta_dot = theta_dot;
}
void robot_cntrl_get_pos(robot_cntrl_t *robot_cntrl, float *x, float *y,
                         float *theta) {
  *x = robot_cntrl->x;
  *y = robot_cntrl->y;
  *theta = robot_cntrl->theta;
}

void robot_cntrl_get_vel(robot_cntrl_t *robot_cntrl, float *x_dot, float *y_dot,
                         float *theta_dot) {
  *x_dot = robot_cntrl->x_dot;
  *y_dot = robot_cntrl->y_dot;
  *theta_dot = robot_cntrl->theta_dot;
}

void robot_cntrl_move_forward(robot_cntrl_t *robot_cntrl, robot_t *robot,
                              float distance) {
  robot->moveForward(distance);
  robot_cntrl->y += distance;
}

void robot_cntrl_move_backward(robot_cntrl_t *robot_cntrl, robot_t *robot,
                               float distance) {
  robot->moveBackward(distance);
  robot_cntrl->y -= distance;
}

void robot_cntrl_turn_right(robot_cntrl_t *robot_cntrl, robot_t *robot,
                            float angle) {
  robot->turnRight(angle);
  robot_cntrl->x += cos(angle);
}

void robot_cntrl_turn_left(robot_cntrl_t *robot_cntrl, robot_t *robot,
                           float angle) {
  robot->turnLeft(angle);
  robot_cntrl->x -= sin(angle);
}