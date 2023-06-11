/**
 * @file pid.c
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-06-10
 *
 * @copyright Copyright (c) 2023
 *
 */

/**
 * @brief
 * #define PI 3.14159265358979323846

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

int32_t pid_test(void);
int32_t pid_simulate(void);

int main(int argc, char *argv[]);
 *
 */

#include "pid.h"

void pid_init(pid_t *pid, float kp, float ki, float kd, float dt, float max, float min)
{
    pid->kp = kp;
    pid->ki = ki;
    pid->kd = kd;
    pid->dt = dt;
    pid->max = max;
    pid->min = min;
    pid->pre_error = 0;
    pid->integral = 0;
}

void pid_set(pid_t *pid, float kp, float ki, float kd, float dt, float max, float min)
{
    pid->kp = kp;
    pid->ki = ki;
    pid->kd = kd;
    pid->dt = dt;
    pid->max = max;
    pid->min = min;
}

void pid_reset(pid_t *pid)
{
    pid->pre_error = 0;
    pid->integral = 0;
}

void pid_update(pid_t *pid, user_input_t *user_input, pid_output_t *pid_output, pid_error_t *pid_error, pid_feedback_t *pid_feedback)
{
    // Calculate error
    pid_feedback->error = user_input->setpoint - user_input->input;

    // Proportional term
    pid_output->p = pid->kp * pid_feedback->error;

    // Integral term
    pid->integral += pid_feedback->error * pid->dt;
    pid_output->i = pid->ki * pid->integral;

    // Derivative term
    pid_output->d = pid->kd * (pid_feedback->error - pid->pre_error) / pid->dt;

    // Calculate total output
    user_input->output = pid_output->p + pid_output->i + pid_output->d;

    // Restrict to max/min
    if (user_input->output > pid->max)
        user_input->output = pid->max;
    else if (user_input->output < pid->min)
        user_input->output = pid->min;

    // Save error to previous error
    pid->pre_error = pid_feedback->error;
}

void pid_print(pid_t *pid, user_input_t *user_input, pid_output_t *pid_output, pid_error_t *pid_error, pid_feedback_t *pid_feedback)
{
    printf("kp: %f, ki: %f, kd: %f, dt: %f, max: %f, min: %f\n", pid->kp, pid->ki, pid->kd, pid->dt, pid->max, pid->min);
    printf("setpoint: %f, input: %f, output: %f\n", user_input->setpoint, user_input->input, user_input->output);
    printf("p: %f, i: %f, d: %f\n", pid_output->p, pid_output->i, pid_output->d);
    printf("p: %f, i: %f, d: %f\n", pid_error->p, pid_error->i, pid_error->d);
    printf("error: %f, pre_error: %f, integral: %f, derivative: %f\n", pid_feedback->error, pid_feedback->pre_error, pid_feedback->integral, pid_feedback->derivative);
}

void pid_pin_init(pid_t *pid, float kp, float ki, float kd, float dt, float max, float min)
{
    pid->kp = kp;
    pid->ki = ki;
    pid->kd = kd;
    pid->dt = dt;
    pid->max = max;
    pid->min = min;
    pid->pre_error = 0;
    pid->integral = 0;
}
void pid_pin_set(pid_t *pid, float kp, float ki, float kd, float dt, float max, float min)
{
    pid->kp = kp;
    pid->ki = ki;
    pid->kd = kd;
    pid->dt = dt;
    pid->max = max;
    pid->min = min;
}
void pid_pin_reset(pid_t *pid)
{
    pid->pre_error = 0;
    pid->integral = 0;
}
void pid_pin_update(pid_t *pid, user_input_t *user_input, pid_output_t *pid_output, pid_error_t *pid_error, pid_feedback_t *pid_feedback)
{
    // Calculate error
    pid_feedback->error = user_input->setpoint - user_input->input;

    // Proportional term
    pid_output->p = pid->kp * pid_feedback->error;

    // Integral term
    pid->integral += pid_feedback->error * pid->dt;
    pid_output->i = pid->ki * pid->integral;

    // Derivative term
    pid_output->d = pid->kd * (pid_feedback->error - pid->pre_error) / pid->dt;

    // Calculate total output
    user_input->output = pid_output->p + pid_output->i + pid_output->d;

    // Restrict to max/min
    if (user_input->output > pid->max)
        user_input->output = pid->max;
    else if (user_input->output < pid->min)
        user_input->output = pid->min;

    // Save error to previous error
    pid->pre_error = pid_feedback->error;
}
void pid_pin_print(pid_t *pid, user_input_t *user_input, pid_output_t *pid_output, pid_error_t *pid_error, pid_feedback_t *pid_feedback)
{
    printf("kp: %f, ki: %f, kd: %f, dt: %f, max: %f, min: %f\n", pid->kp, pid->ki, pid->kd, pid->dt, pid->max, pid->min);
    printf("setpoint: %f, input: %f, output: %f\n", user_input->setpoint, user_input->input, user_input->output);
    printf("p: %f, i: %f, d: %f\n", pid_output->p, pid_output->i, pid_output->d);
    printf("p: %f, i: %f, d: %f\n", pid_error->p, pid_error->i, pid_error->d);
    printf("error: %f, pre_error: %f, integral: %f, derivative: %f\n", pid_feedback->error, pid_feedback->pre_error, pid_feedback->integral, pid_feedback->derivative);
}

int32_t analogRead(int32_t pin)
{
    return pin;
}
int32_t analogWrite(int32_t pin, int32_t value)
{
    return pin = value;
}

int32_t pid_read_pins(pid_t *pid, user_input_t *user_input)
{
    user_input->setpoint = analogRead(PIN_SETPOINT);
    user_input->input = analogRead(PIN_INPUT);
    return 0;
}
int32_t pid_write_pins(pid_t *pid, pid_output_t *pid_output)
{
    analogWrite(PIN_OUTPUT, pid_output->output);
    return 0;
}

int32_t pid_test(void)
{
    pid_t pid;
    user_input_t user_input;
    pid_output_t pid_output;
    pid_error_t pid_error;
    pid_feedback_t pid_feedback;

    pid_init(&pid, 0.1, 0.01, 0.5, 0.1, 100, -100);
    pid_reset(&pid);

    user_input.setpoint = 1;
    user_input.input = 0;
    user_input.output = 0;

    for (int i = 0; i < 100; i++)
    {
        pid_update(&pid, &user_input, &pid_output, &pid_error, &pid_feedback);
        pid_print(&pid, &user_input, &pid_output, &pid_error, &pid_feedback);
    }

    return 0;
}

int32_t pid_simulate(void)
{
    pid_t pid;
    user_input_t user_input;
    pid_output_t pid_output;
    pid_error_t pid_error;
    pid_feedback_t pid_feedback;

    pid_init(&pid, 0.1, 0.01, 0.5, 0.1, 100, -100);
    pid_reset(&pid);

    user_input.setpoint = 1;
    user_input.input = 0;
    user_input.output = 0;

    for (int i = 0; i < 100; i++)
    {
        pid_update(&pid, &user_input, &pid_output, &pid_error, &pid_feedback);
        pid_print(&pid, &user_input, &pid_output, &pid_error, &pid_feedback);
    }

    return 0;
}

int main(int argc, char *argv[])
{
    pid_test();
    return 0;
}