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

#ifndef ROBOT_CNTRL_HPP
#define ROBOT_CNTRL_HPP

#include <stdio.h>

#define PI 3.14159265358979323846

typedef struct robot_cntrl
{
    float x, y, theta;
    float x_dot, y_dot, theta_dot;
} robot_cntrl_t;

void robot_cntrl_init(robot_cntrl_t *robot_cntrl);
void robot_cntrl_set_pos(robot_cntrl_t *robot_cntrl, float x, float y, float theta);
void robot_cntrl_set_vel(robot_cntrl_t *robot_cntrl, float x_dot, float y_dot, float theta_dot);
void robot_cntrl_get_pos(robot_cntrl_t *robot_cntrl, float *x, float *y, float *theta);
void robot_cntrl_get_vel(robot_cntrl_t *robot_cntrl, float *x_dot, float *y_dot, float *theta_dot);

#endif // ROBOT_CNTRL_H
