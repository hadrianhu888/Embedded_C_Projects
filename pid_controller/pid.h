/**
 * @file pid.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-06-10
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef PID_H_
#define PID_H_

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>
#include <string.h>
#include <stdbool.h>
#include <stddef.h>

#define PI 3.14159265358979323846

#define PINS 4
#define POUTS 4
#define PIN_SETPOINT 0
#define PIN_INPUT 1
#define PIN_OUTPUT 2

typedef struct PIN
{
    int32_t pin;
    int32_t value;
} PIN_t;

typedef struct POUT
{
    int32_t pin;
    int32_t value;
} POUT_t;

typedef enum PIN_State
{
    PIN_LOW = 0,
    PIN_HIGH = 1
} PIN_State_t;

typedef struct pid
{
    float kp;
    float ki;
    float kd;
    float dt;
    float max;
    float min;
    float pre_error;
    float integral;
} pid_t;

typedef struct user_input
{
    float setpoint;
    float input;
    float output;
} user_input_t;

typedef struct pid_output
{
    float p;
    float i;
    float d;
    float output;
} pid_output_t;

typedef struct pid_error
{
    float p;
    float i;
    float d;
} pid_error_t;

typedef struct pid_feedback
{
    float error;
    float pre_error;
    float integral;
    float derivative;
} pid_feedback_t;

void pid_init(pid_t *pid, float kp, float ki, float kd, float dt, float max, float min);
void pid_set(pid_t *pid, float kp, float ki, float kd, float dt, float max, float min);
void pid_reset(pid_t *pid);
void pid_update(pid_t *pid, user_input_t *user_input, pid_output_t *pid_output, pid_error_t *pid_error, pid_feedback_t *pid_feedback);
void pid_print(pid_t *pid, user_input_t *user_input, pid_output_t *pid_output, pid_error_t *pid_error, pid_feedback_t *pid_feedback);

void pid_pin_init(pid_t *pid, float kp, float ki, float kd, float dt, float max, float min);
void pid_pin_set(pid_t *pid, float kp, float ki, float kd, float dt, float max, float min);
void pid_pin_reset(pid_t *pid);
void pid_pin_update(pid_t *pid, user_input_t *user_input, pid_output_t *pid_output, pid_error_t *pid_error, pid_feedback_t *pid_feedback);
void pid_pin_print(pid_t *pid, user_input_t *user_input, pid_output_t *pid_output, pid_error_t *pid_error, pid_feedback_t *pid_feedback);

int32_t pid_read_pins(pid_t *pid, user_input_t *user_input);
int32_t pid_write_pins(pid_t *pid, pid_output_t *pid_output);

int32_t analogRead(int32_t pin);
int32_t analogWrite(int32_t pin, int32_t value);

int32_t pid_test(void);
int32_t pid_simulate(void);

int main(int argc, char *argv[]);

#endif /* PID_H_ */