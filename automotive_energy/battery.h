/**
 * @file battery.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-06-10
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef BATTERY_H_
#define BATTERY_H_

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>
#include <string.h>
#include <stdbool.h>
#include <stddef.h>
#include <time.h>
#include "datatypes.h"

#define PI 3.14159265358979323846

#define PINS 4
#define POUTS 4
#define PIN_SETPOINT 0
#define PIN_INPUT 1
#define BATTERIES 10
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

typedef struct kalman
{
    float q;
    float r;
    float x;
    float p;
    float k;
} kalman_t;

typedef struct kalman_filter
{
    float q;
    float r;
    float x;
    float p;
    float k;
} kalman_filter_t;

typedef struct battery
{
    float voltage;
    float current;
    float power;
    float resistance;
    float capacity;
    float soc;
    float temp;
    float max_voltage;
    float min_voltage;
    float max_current;
    float min_current;
    float max_power;
    float min_power;
    float max_resistance;
    float min_resistance;
    float max_capacity;
    float min_capacity;
    float max_soc;
    float min_soc;
    float max_temp;
    float min_temp;
    float temperature;
    float soh;
    float max_soh;
    float min_soh;
} battery_t;

typedef struct battery_input
{
    float voltage;
    float current;
    float power;
    float resistance;
    float capacity;
    float soc;
    float temp;
} battery_input_t;

typedef struct battery_output
{
    float voltage;
    float current;
    float power;
    float resistance;
    float capacity;
    float soc;
    float temp;
} battery_output_t;

typedef struct battery_error
{
    float voltage;
    float current;
    float power;
    float resistance;
    float capacity;
    float soc;
    float temp;
} battery_error_t;

typedef struct battery_setpoint
{
    float voltage;
    float current;
    float power;
    float resistance;
    float capacity;
    float soc;
    float temp;
} battery_setpoint_t;

typedef struct battery_pid
{
    float kp;
    float ki;
    float kd;
    float dt;
    float max;
    float min;
    float pre_error;
    float integral;
} battery_pid_t;

typedef struct battery_controller
{
    battery_t battery;
    battery_input_t input;
    battery_output_t output;
    battery_error_t error;
    battery_setpoint_t setpoint;
    battery_pid_t pid;
    kalman_t kalman;
    float dt;
    float max;
    float min;
    float pre_error;
    float integral;
    float q;
    float r;
    float x;
    float p;
    float k;
    float kp;
    float ki;
    float kd;
    float max_voltage;
    float min_voltage;
    float max_current;
    float min_current;
    float max_power;
    float min_power;
    float max_resistance;
    float min_resistance;
    float max_capacity;
    float min_capacity;
    float max_soc;
    float min_soc;
    float max_temp;
    float min_temp;
    float temperature;
    float soh;
    float max_soh;
    float min_soh;
    float battery_controller_pid_error_previous;
    float battery_controller_pid_error_sum;
    float battery_controller_pid_error_derivative;
    float battery_controller_pid_output_previous;
    float battery_controller_pid_last_time;
    float battery_controller_pid_last_error;
    float battery_controller_pid_current_time;
    float battery_controller_setpoint_voltage;
    float battery_controller_setpoint_current;
    float battery_controller_setpoint_power;
    float battery_controller_setpoint_resistance;
    float battery_controller_setpoint_capacity;
    float battery_controller_setpoint_soc;
    float battery_controller_setpoint_temp;
    float battery_controller_input_voltage;
    float battery_controller_input_current;
    float battery_controller_input_power;
    float battery_controller_input_resistance;
    float battery_controller_input_capacity;
    float battery_controller_input_soc;
    float battery_controller_input_temp;
    float battery_controller_output_voltage;
    float battery_controller_output_current;
    float battery_controller_output_power;
    float battery_controller_output_resistance;
    float battery_controller_output_capacity;
    float battery_controller_output_soc;
    float battery_controller_output_temp;
    float battery_controller_error_voltage;
    float battery_controller_error_current;
    float battery_controller_error_power;
    float battery_controller_error_resistance;
    float battery_controller_error_capacity;
    float battery_controller_error_soc;
    float battery_controller_error_temp;
    float battery_controller_pid_kp;
    float battery_controller_pid_ki;
    float battery_controller_pid_kd;
    float battery_controller_pid_dt;
    float battery_controller_pid_max;
    float battery_controller_pid_min;
    float battery_controller_pid_pre_error;
    float battery_controller_pid_integral;
    float battery_controller_input_voltage_pin;
    float battery_controller_input_current_pin;
    float battery_controller_input_power_pin;
    float battery_controller_input_resistance_pin;
    float battery_controller_input_capacity_pin;
    float battery_controller_input_soc_pin;
    float battery_controller_input_temp_pin;
    float battery_controller_output_voltage_pin;
    float battery_controller_output_current_pin;
    float battery_controller_output_power_pin;
    float battery_controller_output_resistance_pin;
    float battery_controller_output_capacity_pin;
    float battery_controller_output_soc_pin;
    float battery_controller_output_temp_pin;
    float battery_controller_error_voltage_pin;
    float battery_controller_error_current_pin;
    float battery_controller_error_power_pin;
    float battery_controller_error_resistance_pin;
    float battery_controller_error_capacity_pin;
    float battery_controller_error_soc_pin;
    float battery_controller_error_temp_pin;
    float battery_controller_setpoint_voltage_pin;
    float battery_controller_setpoint_current_pin;
    float battery_controller_setpoint_power_pin;
    float battery_controller_setpoint_resistance_pin;
    float battery_controller_setpoint_capacity_pin;
    float battery_controller_setpoint_soc_pin;
    float battery_controller_setpoint_temp_pin;
    float battery_controller_pid_kp_pin;
    float battery_controller_pid_ki_pin;
    float battery_controller_pid_kd_pin;
    float battery_controller_pid_dt_pin;
    float battery_controller_pid_max_pin;
    float battery_controller_pid_min_pin;
    float battery_controller_pid_pre_error_pin;
    float battery_controller_pid_integral_pin;
    float battery_controller_pid_error;
    float battery_controller_pid_proportional;
    float battery_controller_pid_derivative;
    float battery_controller_pid_output;
    float battery_controller_battery_voltage;
    float battery_controller_battery_current;
    float battery_controller_battery_power;
    float battery_controller_battery_resistance;
    float battery_controller_battery_capacity;
    float battery_controller_battery_soc;
    float battery_controller_battery_temp;
    float battery_controller_battery_soh;
    float battery_controller_battery_max_voltage;
    float battery_controller_battery_min_voltage;
    float battery_controller_battery_max_current;
    float battery_controller_battery_min_current;
    float battery_controller_battery_max_power;
    float battery_controller_battery_min_power;
    float battery_controller_battery_max_resistance;
    float battery_controller_battery_min_resistance;
    float battery_controller_battery_max_capacity;
    float battery_controller_battery_min_capacity;
    float battery_controller_battery_max_soc;
    float battery_controller_battery_min_soc;
    float battery_controller_battery_max_temp;
    float battery_controller_battery_min_temp;
    float battery_controller_battery_max_soh;
    float battery_controller_battery_min_soh;
    float battery_controller_pid_setpoint_voltage;
    float battery_controller_pid_setpoint_current;
    float battery_controller_pid_setpoint_power;
    float battery_controller_pid_setpoint_resistance;
    float battery_controller_pid_setpoint_capacity;
    float battery_controller_pid_setpoint_soc;
    float battery_controller_pid_setpoint_temp;
    float battery_controller_pid_input_voltage;
    float battery_controller_pid_input_current;
    float battery_controller_pid_input_power;
    float battery_controller_pid_input_resistance;
    float battery_controller_pid_input_capacity;
    float battery_controller_pid_input_soc;
    float battery_controller_pid_input_temp;
    float battery_controller_pid_output_voltage;
    float battery_controller_pid_output_current;
    float battery_controller_pid_output_power;
    float battery_controller_pid_output_resistance;
    float battery_controller_pid_output_capacity;
    float battery_controller_pid_output_soc;
    float battery_controller_pid_output_temp;
    float battery_controller_pid_error_voltage;
    float battery_controller_pid_error_current;
    float battery_controller_pid_error_power;
    float battery_controller_pid_error_resistance;
    float battery_controller_pid_error_capacity;
    float battery_controller_pid_error_soc;
    float battery_controller_pid_error_temp;
    float battery_controller_pid_battery_voltage;
    float battery_controller_pid_battery_current;
    float battery_controller_pid_battery_power;
    float battery_controller_pid_battery_resistance;
    float battery_controller_pid_battery_capacity;
    float battery_controller_pid_battery_soc;
    float battery_controller_pid_battery_temp;
    float battery_controller_pid_error_voltage_sum;
    float battery_controller_pid_error_current_sum;
    float battery_controller_pid_error_power_sum;
    float battery_controller_pid_error_resistance_sum;
    float battery_controller_pid_error_capacity_sum;
    float battery_controller_pid_error_soc_sum;
    float battery_controller_pid_error_temp_sum;
    float battery_controller_pid_error_voltage_previous;
    float battery_controller_pid_error_current_previous;
    float battery_controller_pid_error_voltage_diff;
    float battery_controller_pid_error_current_diff;
    float battery_controller_pid_error_voltage_diff_previous;
    float battery_controller_pid_error_current_diff_previous;
    float battery_controller_pid_error_voltage_diff_sum;
    float battery_controller_pid_error_current_diff_sum;
    float battery_controller_pid_error_voltage_diff_average;
    float battery_controller_pid_error_current_diff_average;
    float battery_controller_pid_error_voltage_diff_previous_average;
    float battery_controller_pid_error_current_diff_previous_average;
    float battery_controller_pid_error_voltage_diff_sum_average;
    float battery_controller_pid_error_current_diff_sum_average;
    float battery_controller_pid_error_voltage_diff_average_previous;
    float battery_controller_pid_error_current_diff_average_previous;
    float battery_controller_pid_error_voltage_diff_sum_average_previous;
    float battery_controller_pid_error_current_diff_sum_average_previous;
    float battery_controller_pid_error_voltage_diff_average_diff;
    float battery_controller_pid_error_current_diff_average_diff;
    float battery_controller_pid_error_voltage_diff_sum_average_diff;
    float battery_controller_pid_error_power_diff;
    float battery_controller_pid_error_power_diff_previous;
    float battery_controller_pid_error_power_diff_sum;
    float battery_controller_pid_error_power_diff_average;
} battery_controller_t;

int32_t analogRead(int32_t pin);
void analogWrite(int32_t pin, int32_t value);
int32_t digitalRead(int32_t pin);
void digitalWrite(int32_t pin, int32_t value);

void battery_init(battery_controller_t *battery_controller);
void battery_input(battery_controller_t *battery_controller);
void battery_output(battery_controller_t *battery_controller);
void battery_error(battery_controller_t *battery_controller);
void battery_setpoint(battery_controller_t *battery_controller);
void battery_pid(battery_controller_t *battery_controller);
void battery_controller(battery_controller_t *battery_controller);

int32_t battery_controller_setpoint_voltage(battery_controller_t *battery_controller, float voltage);
int32_t battery_controller_setpoint_current(battery_controller_t *battery_controller, float current);
int32_t battery_controller_setpoint_power(battery_controller_t *battery_controller, float power);
int32_t battery_controller_setpoint_resistance(battery_controller_t *battery_controller, float resistance);
int32_t battery_controller_setpoint_capacity(battery_controller_t *battery_controller, float capacity);
int32_t battery_controller_setpoint_soc(battery_controller_t *battery_controller, float soc);
int32_t battery_controller_setpoint_temp(battery_controller_t *battery_controller, float temp);

int32_t battery_controller_pid_kp(battery_controller_t *battery_controller, float kp);
int32_t battery_controller_pid_ki(battery_controller_t *battery_controller, float ki);
int32_t battery_controller_pid_kd(battery_controller_t *battery_controller, float kd);
int32_t battery_controller_pid_dt(battery_controller_t *battery_controller, float dt);
int32_t battery_controller_pid_max(battery_controller_t *battery_controller, float max);
int32_t battery_controller_pid_min(battery_controller_t *battery_controller, float min);

int32_t battery_controller_input_voltage(battery_controller_t *battery_controller, float voltage);
int32_t battery_controller_input_current(battery_controller_t *battery_controller, float current);
int32_t battery_controller_input_power(battery_controller_t *battery_controller, float power);
int32_t battery_controller_input_resistance(battery_controller_t *battery_controller, float resistance);
int32_t battery_controller_input_capacity(battery_controller_t *battery_controller, float capacity);
int32_t battery_controller_input_soc(battery_controller_t *battery_controller, float soc);
int32_t battery_controller_input_temp(battery_controller_t *battery_controller, float temp);

int32_t battery_controller_output_voltage(battery_controller_t *battery_controller, float voltage);
int32_t battery_controller_output_current(battery_controller_t *battery_controller, float current);
int32_t battery_controller_output_power(battery_controller_t *battery_controller, float power);
int32_t battery_controller_output_resistance(battery_controller_t *battery_controller, float resistance);
int32_t battery_controller_output_capacity(battery_controller_t *battery_controller, float capacity);
int32_t battery_controller_output_soc(battery_controller_t *battery_controller, float soc);
int32_t battery_controller_output_temp(battery_controller_t *battery_controller, float temp);

int32_t battery_controller_error_voltage(battery_controller_t *battery_controller, float voltage);
int32_t battery_controller_error_current(battery_controller_t *battery_controller, float current);
int32_t battery_controller_error_power(battery_controller_t *battery_controller, float power);
int32_t battery_controller_error_resistance(battery_controller_t *battery_controller, float resistance);
int32_t battery_controller_error_capacity(battery_controller_t *battery_controller, float capacity);
int32_t battery_controller_error_soc(battery_controller_t *battery_controller, float soc);
int32_t battery_controller_error_temp(battery_controller_t *battery_controller, float temp);

int32_t battery_controller_battery_voltage(battery_controller_t *battery_controller, float voltage);
int32_t battery_controller_battery_current(battery_controller_t *battery_controller, float current);
int32_t battery_controller_battery_power(battery_controller_t *battery_controller, float power);
int32_t battery_controller_battery_resistance(battery_controller_t *battery_controller, float resistance);
int32_t battery_controller_battery_capacity(battery_controller_t *battery_controller, float capacity);
int32_t battery_controller_battery_soc(battery_controller_t *battery_controller, float soc);
int32_t battery_controller_battery_temp(battery_controller_t *battery_controller, float temp);

int32_t battery_controller_pid(battery_controller_t *battery_controller, float kp, float ki, float kd, float dt, float max, float min);
int32_t battery_controller_input(battery_controller_t *battery_controller, float voltage, float current, float power, float resistance, float capacity, float soc, float temp);
int32_t battery_controller_output(battery_controller_t *battery_controller, float voltage, float current, float power, float resistance, float capacity, float soc, float temp);
int32_t battery_controller_error(battery_controller_t *battery_controller, float voltage, float current, float power, float resistance, float capacity, float soc, float temp);
int32_t battery_controller_battery(battery_controller_t *battery_controller, float voltage, float current, float power, float resistance, float capacity, float soc, float temp);

int32_t battery_controller_pid_setpoint(battery_controller_t *battery_controller, float voltage, float current, float power, float resistance, float capacity, float soc, float temp);
int32_t battery_controller_pid_input(battery_controller_t *battery_controller, float voltage, float current, float power, float resistance, float capacity, float soc, float temp);
int32_t battery_controller_pid_output(battery_controller_t *battery_controller, float voltage, float current, float power, float resistance, float capacity, float soc, float temp);
int32_t battery_controller_pid_error(battery_controller_t *battery_controller, float voltage, float current, float power, float resistance, float capacity, float soc, float temp);

int32_t battery_controller_pid_setpoint_voltage(battery_controller_t *battery_controller, float voltage);
int32_t battery_controller_pid_setpoint_current(battery_controller_t *battery_controller, float current);
int32_t battery_controller_pid_setpoint_power(battery_controller_t *battery_controller, float power);
int32_t battery_controller_pid_setpoint_resistance(battery_controller_t *battery_controller, float resistance);
int32_t battery_controller_pid_setpoint_capacity(battery_controller_t *battery_controller, float capacity);
int32_t battery_controller_pid_setpoint_soc(battery_controller_t *battery_controller, float soc);
int32_t battery_controller_pid_setpoint_temp(battery_controller_t *battery_controller, float temp);

int32_t kalman_filter_init(kalman_filter_t *kalman_filter, float q, float r, float p, float x);
int32_t kalman_filter_update(kalman_filter_t *kalman_filter, float measurement);
int32_t kalman_filter_set_q(kalman_filter_t *kalman_filter, float q);
int32_t kalman_filter_set_r(kalman_filter_t *kalman_filter, float r);
int32_t kalman_filter_set_p(kalman_filter_t *kalman_filter, float p);
int32_t kalman_filter_set_x(kalman_filter_t *kalman_filter, float x);
int32_t kalman_filter_get_q(kalman_filter_t *kalman_filter, float *q);
int32_t kalman_filter_get_r(kalman_filter_t *kalman_filter, float *r);
int32_t kalman_filter_get_p(kalman_filter_t *kalman_filter, float *p);
int32_t kalman_filter_get_x(kalman_filter_t *kalman_filter, float *x);

int32_t battery_controller_init(battery_controller_t *battery_controller, float kp, float ki, float kd, float dt, float max, float min);
int32_t battery_controller_set_kp(battery_controller_t *battery_controller, float kp);
int32_t battery_controller_set_ki(battery_controller_t *battery_controller, float ki);
int32_t battery_controller_set_kd(battery_controller_t *battery_controller, float kd);
int32_t battery_controller_set_dt(battery_controller_t *battery_controller, float dt);
int32_t battery_controller_set_max(battery_controller_t *battery_controller, float max);
int32_t battery_controller_set_min(battery_controller_t *battery_controller, float min);
int32_t battery_controller_get_kp(battery_controller_t *battery_controller, float *kp);
int32_t battery_controller_get_ki(battery_controller_t *battery_controller, float *ki);
int32_t battery_controller_get_kd(battery_controller_t *battery_controller, float *kd);
int32_t battery_controller_get_dt(battery_controller_t *battery_controller, float *dt);
int32_t battery_controller_get_max(battery_controller_t *battery_controller, float *max);
int32_t battery_controller_get_min(battery_controller_t *battery_controller, float *min);

int32_t battery_controller_setpoint(battery_controller_t *battery_controller, float voltage, float current, float power, float resistance, float capacity, float soc, float temp);
int32_t battery_controller_input(battery_controller_t *battery_controller, float voltage, float current, float power, float resistance, float capacity, float soc, float temp);
int32_t battery_controller_output(battery_controller_t *battery_controller, float voltage, float current, float power, float resistance, float capacity, float soc, float temp);
int32_t battery_controller_error(battery_controller_t *battery_controller, float voltage, float current, float power, float resistance, float capacity, float soc, float temp);
int32_t battery_controller_battery(battery_controller_t *battery_controller, float voltage, float current, float power, float resistance, float capacity, float soc, float temp);

int32_t estimate_battery_states(battery_controller_t *battery_controller, float voltage, float current, float power, float resistance, float capacity, float soc, float temp);

int32_t simulate_battery(battery_controller_t *battery_controller, float voltage, float current, float power, float resistance, float capacity, float soc, float temp);
int32_t simulate_battery_controller(battery_controller_t *battery_controller, float voltage, float current, float power, float resistance, float capacity, float soc, float temp);
int32_t simulate_battery_controller_pid(battery_controller_t *battery_controller, float voltage, float current, float power, float resistance, float capacity, float soc, float temp);
int32_t battery_controller_output(battery_controller_t *battery_controller, float voltage, float current, float power, float resistance, float capacity, float soc, float temp);

battery_controller_t *battery_controller_create(float kp, float ki, float kd, float dt, float max, float min);
int32_t battery_controller_destroy(battery_controller_t *battery_controller);

void printLiveData(battery_controller_t *battery_controller, float voltage, float current, float power, float resistance, float capacity, float soc, float temp);

battery_controller_t randomizeInitialParameters(battery_controller_t *battery_controller, float *voltage, float *current, float *power, float *resistance, float *capacity, float *soc, float *temp);

battery_controller_t simulate_kalman_filter(battery_controller_t *battery_controller, float voltage, float current, float power, float resistance, float capacity, float soc, float temp);

void simulate_live_test(battery_controller_t *battery_controller, float voltage, float current, float power, float resistance, float capacity, float soc, float temp);

void test_battery(void);

int main(int argc, char *argv[]);

#endif /* BATTERY_H_ */