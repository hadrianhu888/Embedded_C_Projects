/**
 * @file robot_cntrl.hpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-06-13
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef ROBOT_CNTRL_H
#define ROBOT_CNTRL_H

#include <stdio.h>

#define PI 3.14159265358979323846

typedef struct robot_cntrl
{
  float x, y, theta;
  float x_dot, y_dot, theta_dot;
} robot_cntrl_t;

typedef struct robot_t
{
  float x, y, theta;
  float x_dot, y_dot, theta_dot;
  float wheel_radius;
  float wheel_base;
  float wheel_circumference;
  float wheel_speed;
  float wheel_speed_rpm;
  float wheel_speed_rps;
  float wheel_speed_mps;
  bool wheel_direction;
  float wheel_distance;
  float wheel_distance_m;
  float wheel_distance_mm;
  float move_forward;
  float move_backward;
  float turn_right;
  float turn_left;
} robot_t;

void robot_cntrl_init(robot_cntrl_t *robot_cntrl);
void robot_cntrl_set_pos(robot_cntrl_t *robot_cntrl, float x, float y,
                         float theta);
void robot_cntrl_set_vel(robot_cntrl_t *robot_cntrl, float x_dot, float y_dot,
                         float theta_dot);
void robot_cntrl_get_pos(robot_cntrl_t *robot_cntrl, float *x, float *y,
                         float *theta);
void robot_cntrl_get_vel(robot_cntrl_t *robot_cntrl, float *x_dot, float *y_dot,
                         float *theta_dot);
void robot_cntrl_move_forward(robot_cntrl_t *robot_cntrl, robot_t *robot,
                              float distance);
void robot_cntrl_move_backward(robot_cntrl_t *robot_cntrl, robot_t *robot,
                               float distance);
void robot_cntrl_turn_right(robot_cntrl_t *robot_cntrl, robot_t *robot,
                            float angle);
void robot_cntrl_turn_left(robot_cntrl_t *robot_cntrl, robot_t *robot,
                           float angle);

#endif // ROBOT_CNTRL_H
