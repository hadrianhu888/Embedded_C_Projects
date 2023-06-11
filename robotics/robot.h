/**
 * @file robot.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-06-11
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef ROBOT_H
#define ROBOT_H

#include "datatypes.h"

typedef struct robot_architecture
{
    f32 voltage;
    f32 current;
    f32 temperature;
    f32 speed;
    f32 torque;
    f32 position;
    f32 acceleration;
    f32 jerk;
} robot_architecture;

typedef enum robot_state
{
    ROBOT_STATE_IDLE,
    ROBOT_STATE_READ,
    ROBOT_STATE_WRITE,
    ROBOT_STATE_UPDATE,
    ROBOT_STATE_PUT,
    ROBOT_STATE_GET,
    ROBOT_STATE_SET,
    ROBOT_STATE_ERROR,
} robot_state;

typedef enum robot_mode
{
    ROBOT_MODE_IDLE,
    ROBOT_MODE_READ,
    ROBOT_MODE_WRITE,
    ROBOT_MODE_UPDATE,
    ROBOT_MODE_PUT,
    ROBOT_MODE_GET,
    ROBOT_MODE_SET,
    ROBOT_MODE_ERROR,
} robot_mode;

typedef enum robot_error
{
    ROBOT_ERROR_NONE,
    ROBOT_ERROR_READ,
    ROBOT_ERROR_WRITE,
    ROBOT_ERROR_UPDATE,
    ROBOT_ERROR_PUT,
    ROBOT_ERROR_GET,
    ROBOT_ERROR_SET,
    ROBOT_ERROR_ERROR,
} robot_error;

typedef enum robot_interface_states
{
    ROBOT_INTERFACE_STATE_IDLE,
    ROBOT_INTERFACE_STATE_READ,
    ROBOT_INTERFACE_STATE_WRITE,
    ROBOT_INTERFACE_STATE_UPDATE,
    ROBOT_INTERFACE_STATE_PUT,
    ROBOT_INTERFACE_STATE_GET,
    ROBOT_INTERFACE_STATE_SET,
    ROBOT_INTERFACE_STATE_ERROR,
} robot_interface_states;

typedef struct robot_input
{
    f32 voltage;
    f32 current;
    f32 temperature;
    f32 speed;
    f32 torque;
    f32 position;
    f32 acceleration;
    f32 jerk;
} robot_input;

typedef struct robot_output
{
    f32 voltage;
    f32 current;
    f32 temperature;
    f32 speed;
    f32 torque;
    f32 position;
    f32 acceleration;
    f32 jerk;
} robot_output;

typedef struct robot_cntrl_fdbk
{
    f32 voltage;
    f32 current;
    f32 temperature;
    f32 speed;
    f32 torque;
    f32 position;
    f32 acceleration;
    f32 jerk;
} robot_cntrl_fdbk;

typedef struct robot_setpoints
{
    f32 voltage;
    f32 current;
    f32 temperature;
    f32 speed;
    f32 torque;
    f32 position;
    f32 acceleration;
    f32 jerk;
} robot_setpoints;

typedef struct controller
{
    f32 voltage;
    f32 current;
    f32 temperature;
    f32 speed;
    f32 torque;
    f32 position;
    f32 acceleration;
    f32 jerk;
} controller;

// prototype functions

void read_robot_input(robot_input *input);
void write_robot_output(robot_output *output);
void get_robot_input_state(robot_interface_states *robot_state);
void get_robot_output_state(robot_interface_states *robot_state);
void set_robot_input_state(robot_interface_states robot_state);
void set_robot_output_state(robot_interface_states robot_state);
void update_robot_input(robot_input *input);
void update_robot_output(robot_output *output);
void put_robot_input(robot_input *input);
void put_robot_output(robot_output *output);
void get_robot_input(robot_input *input);
void get_robot_output(robot_output *output);
void set_robot_input(robot_input *input);
void set_robot_output(robot_output *output);
void error_robot_input(robot_input *input);
void error_robot_output(robot_output *output);
void idle_robot_input(robot_input *input);
void idle_robot_output(robot_output *output);
void read_robot_input_voltage(f32 *voltage);
void read_robot_input_current(f32 *current);
void read_robot_input_temperature(f32 *temperature);
void read_robot_input_speed(f32 *speed);
void read_robot_input_torque(f32 *torque);
void read_robot_input_position(f32 *position);
void read_robot_input_acceleration(f32 *acceleration);
void read_robot_input_jerk(f32 *jerk);
void write_robot_output_voltage(f32 voltage);
void write_robot_output_current(f32 current);
void write_robot_output_temperature(f32 temperature);
void write_robot_output_speed(f32 speed);
void write_robot_output_torque(f32 torque);
void write_robot_output_position(f32 position);
void write_robot_output_acceleration(f32 acceleration);

#endif // ROBOT_H