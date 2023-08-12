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
#include <math.h>
#include <iostream>
#include "datatypes.hpp"

using namespace std;

void robot_cntrl_init(robot_cntrl_t *robot_cntrl)
{
	robot_cntrl->x = 0;
	robot_cntrl->y = 0;
	robot_cntrl->theta = 0;
	robot_cntrl->x_dot = 0;
	robot_cntrl->y_dot = 0;
	robot_cntrl->theta_dot = 0;
}

void robot_cntrl_set_pos(robot_cntrl_t *robot_cntrl, float x, float y, float theta)
{
	robot_cntrl->x = x;
	robot_cntrl->y = y;
	robot_cntrl->theta = theta;
}

void robot_cntrl_set_vel(robot_cntrl_t *robot_cntrl, float x_dot, float y_dot,
						 float theta_dot)
{
	robot_cntrl->x_dot = x_dot;
	robot_cntrl->y_dot = y_dot;
	robot_cntrl->theta_dot = theta_dot;
}
void robot_cntrl_get_pos(robot_cntrl_t *robot_cntrl, float *x, float *y,
						 float *theta)
{
	*x = robot_cntrl->x;
	*y = robot_cntrl->y;
	*theta = robot_cntrl->theta;
}

void robot_cntrl_get_vel(robot_cntrl_t *robot_cntrl, float *x_dot, float *y_dot,
						 float *theta_dot)
{
	*x_dot = robot_cntrl->x_dot;
	*y_dot = robot_cntrl->y_dot;
	*theta_dot = robot_cntrl->theta_dot;
}

void robot_cntrl_move_forward(robot_cntrl_t *robot_cntrl, robot_t *robot,
							  float distance)
{
	robot->wheel_distance = distance;
	robot->wheel_distance_m = distance / 1000;
	robot->wheel_distance_mm = distance * 1000;
	robot->wheel_speed = 0.5;
	robot->wheel_speed_rpm = 30;
	robot->wheel_speed_rps = 0.5;
	robot->wheel_speed_mps = 0.5;
	robot->wheel_direction = true;
	robot_cntrl->x = robot->wheel_distance_m;
	robot_cntrl->y = robot->wheel_distance_m;
	robot_cntrl->theta = robot->wheel_distance_m;
	robot_cntrl->x_dot = robot->wheel_speed_mps;
	robot_cntrl->y_dot = robot->wheel_speed_mps;
	robot_cntrl->theta_dot = robot->wheel_speed_mps;
}

void robot_cntrl_move_backward(robot_cntrl_t *robot_cntrl, robot_t *robot, float distance)
{
	robot->wheel_distance = distance;
	robot->wheel_distance_m = distance / 1000;
	robot->wheel_distance_mm = distance * 1000;
	robot->wheel_speed = 0.5;
	robot->wheel_speed_rpm = 30;
	robot->wheel_speed_rps = 0.5;
	robot->wheel_speed_mps = 0.5;
	robot->wheel_direction = false;
	robot_cntrl->x = robot->wheel_distance_m;
	robot_cntrl->y = robot->wheel_distance_m;
	robot_cntrl->theta = robot->wheel_distance_m;
	robot_cntrl->x_dot = robot->wheel_speed_mps;
	robot_cntrl->y_dot = robot->wheel_speed_mps;
	robot_cntrl->theta_dot = robot->wheel_speed_mps;
}

void robot_cntrl_move_left(robot_cntrl_t *robot_cntrl, robot_t *robot, float distance)
{
	robot->wheel_distance = distance;
	robot->wheel_distance_m = distance / 1000;
	robot->wheel_distance_mm = distance * 1000;
	robot->wheel_speed = 0.5;
	robot->wheel_speed_rpm = 30;
	robot->wheel_speed_rps = 0.5;
	robot->wheel_speed_mps = 0.5;
	robot->wheel_direction = false;
	robot_cntrl->x = robot->wheel_distance_m;
	robot_cntrl->y = robot->wheel_distance_m;
	robot_cntrl->theta = robot->wheel_distance_m;
	robot_cntrl->x_dot = robot->wheel_speed_mps;
	robot_cntrl->y_dot = robot->wheel_speed_mps;
	robot_cntrl->theta_dot = robot->wheel_speed_mps;
}

void robot_cntrl_move_right(robot_cntrl_t *robot_cntrl, robot_t *robot, float distance)
{
	robot->wheel_distance = distance;
	robot->wheel_distance_m = distance / 1000;
	robot->wheel_distance_mm = distance * 1000;
	robot->wheel_speed = 0.5;
	robot->wheel_speed_rpm = 30;
	robot->wheel_speed_rps = 0.5;
	robot->wheel_speed_mps = 0.5;
	robot->wheel_direction = false;
	robot_cntrl->x = robot->wheel_distance_m;
	robot_cntrl->y = robot->wheel_distance_m;
	robot_cntrl->theta = robot->wheel_distance_m;
	robot_cntrl->x_dot = robot->wheel_speed_mps;
	robot_cntrl->y_dot = robot->wheel_speed_mps;
	robot_cntrl->theta_dot = robot->wheel_speed_mps;
}

void robot_cntrl_move_up(robot_cntrl_t *robot_cntrl, robot_t *robot, float distance)
{
	robot->wheel_distance = distance;
	robot->wheel_distance_m = distance / 1000;
	robot->wheel_distance_mm = distance * 1000;
	robot->wheel_speed = 0.5;
	robot->wheel_speed_rpm = 30;
	robot->wheel_speed_rps = 0.5;
	robot->wheel_speed_mps = 0.5;
	robot->wheel_direction = false;
	robot_cntrl->x = robot->wheel_distance_m;
	robot_cntrl->y = robot->wheel_distance_m;
	robot_cntrl->theta = robot->wheel_distance_m;
	robot_cntrl->x_dot = robot->wheel_speed_mps;
	robot_cntrl->y_dot = robot->wheel_speed_mps;
	robot_cntrl->theta_dot = robot->wheel_speed_mps;
}

void robot_cntrl_move_down(robot_cntrl_t *robot_cntrl, robot_t *robot, float distance)
{
	robot->wheel_distance = distance;
	robot->wheel_distance_m = distance / 1000;
	robot->wheel_distance_mm = distance * 1000;
	robot->wheel_speed = 0.5;
	robot->wheel_speed_rpm = 30;
	robot->wheel_speed_rps = 0.5;
	robot->wheel_speed_mps = 0.5;
	robot->wheel_direction = false;
	robot_cntrl->x = robot->wheel_distance_m;
	robot_cntrl->y = robot->wheel_distance_m;
	robot_cntrl->theta = robot->wheel_distance_m;
	robot_cntrl->x_dot = robot->wheel_speed_mps;
	robot_cntrl->y_dot = robot->wheel_speed_mps;
	robot_cntrl->theta_dot = robot->wheel_speed_mps;
}

void print_robot_states(robot_cntrl_t *robot_cntrl, robot_t *robot, float distance)
{
	cout << "robot_cntrl->x: " << robot_cntrl->x << endl;
	cout << "robot_cntrl->y: " << robot_cntrl->y << endl;
	cout << "robot_cntrl->theta: " << robot_cntrl->theta << endl;
	cout << "robot_cntrl->x_dot: " << robot_cntrl->x_dot << endl;
	cout << "robot_cntrl->y_dot: " << robot_cntrl->y_dot << endl;
	cout << "robot_cntrl->theta_dot: " << robot_cntrl->theta_dot << endl;
	cout << "robot->wheel_distance: " << robot->wheel_distance << endl;
	cout << "robot->wheel_distance_m: " << robot->wheel_distance_m << endl;
	cout << "robot->wheel_distance_mm: " << robot->wheel_distance_mm << endl;
	cout << "robot->wheel_speed: " << robot->wheel_speed << endl;
	cout << "robot->wheel_speed_rpm: " << robot->wheel_speed_rpm << endl;
	cout << "robot->wheel_speed_rps: " << robot->wheel_speed_rps << endl;
	cout << "robot->wheel_speed_mps: " << robot->wheel_speed_mps << endl;
	cout << "robot->wheel_direction: " << robot->wheel_direction << endl;
	cout << "robot->wheel_base: " << robot->wheel_base << endl;
	cout << "robot->wheel_radius: " << robot->wheel_radius << endl;
	cout << "robot->wheel_circumference: " << robot->wheel_circumference << endl;
	cout << "robot->move_forward: " << robot->move_forward << endl;
	cout << "robot->move_backward: " << robot->move_backward << endl;
	cout << "robot->turn_right: " << robot->turn_right << endl;
	cout << "robot->turn_left: " << robot->turn_left << endl;
}
