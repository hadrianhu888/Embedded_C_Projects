/**
 * @file battery.c
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-06-10
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "battery.h"

int32_t analogRead(int32_t pin)
{
    return pin;
}
void analogWrite(int32_t pin, int32_t value)
{
    pin = value;
}
int32_t digitalRead(int32_t pin)
{
    return pin;
}
void digitalWrite(int32_t pin, int32_t value)
{
    pin = value;
}

void battery_init(battery_controller_t *battery_controller)
{
    battery_controller->battery_controller_setpoint_voltage = 0;
    battery_controller->battery_controller_setpoint_current = 0;
    battery_controller->battery_controller_setpoint_power = 0;
    battery_controller->battery_controller_setpoint_resistance = 0;
    battery_controller->battery_controller_setpoint_capacity = 0;
    battery_controller->battery_controller_setpoint_soc = 0;
    battery_controller->battery_controller_setpoint_temp = 0;

    battery_controller->battery_controller_pid_kp = 0;
    battery_controller->battery_controller_pid_ki = 0;
    battery_controller->battery_controller_pid_kd = 0;
    battery_controller->battery_controller_pid_dt = 0;

    battery_controller->battery_controller_pid_max = 0;
    battery_controller->battery_controller_pid_min = 0;

    battery_controller->battery_controller_pid_pre_error = 0;
    battery_controller->battery_controller_pid_integral = 0;
}
void battery_input(battery_controller_t *battery_controller)
{
    battery_controller->battery_controller_input_voltage = analogRead(battery_controller->battery_controller_input_voltage_pin);
    battery_controller->battery_controller_input_current = analogRead(battery_controller->battery_controller_input_current_pin);
    battery_controller->battery_controller_input_power = analogRead(battery_controller->battery_controller_input_power_pin);
    battery_controller->battery_controller_input_resistance = analogRead(battery_controller->battery_controller_input_resistance_pin);
    battery_controller->battery_controller_input_capacity = analogRead(battery_controller->battery_controller_input_capacity_pin);
    battery_controller->battery_controller_input_soc = analogRead(battery_controller->battery_controller_input_soc_pin);
    battery_controller->battery_controller_input_temp = analogRead(battery_controller->battery_controller_input_temp_pin);
}
void battery_output(battery_controller_t *battery_controller)
{
    analogWrite(battery_controller->battery_controller_output_voltage_pin, battery_controller->battery_controller_output_voltage);
    analogWrite(battery_controller->battery_controller_output_current_pin, battery_controller->battery_controller_output_current);
    analogWrite(battery_controller->battery_controller_output_power_pin, battery_controller->battery_controller_output_power);
    analogWrite(battery_controller->battery_controller_output_resistance_pin, battery_controller->battery_controller_output_resistance);
    analogWrite(battery_controller->battery_controller_output_capacity_pin, battery_controller->battery_controller_output_capacity);
    analogWrite(battery_controller->battery_controller_output_soc_pin, battery_controller->battery_controller_output_soc);
    analogWrite(battery_controller->battery_controller_output_temp_pin, battery_controller->battery_controller_output_temp);
}
void battery_error(battery_controller_t *battery_controller)
{
    battery_controller->battery_controller_error_voltage = battery_controller->battery_controller_setpoint_voltage - battery_controller->battery_controller_input_voltage;
    battery_controller->battery_controller_error_current = battery_controller->battery_controller_setpoint_current - battery_controller->battery_controller_input_current;
    battery_controller->battery_controller_error_power = battery_controller->battery_controller_setpoint_power - battery_controller->battery_controller_input_power;
    battery_controller->battery_controller_error_resistance = battery_controller->battery_controller_setpoint_resistance - battery_controller->battery_controller_input_resistance;
    battery_controller->battery_controller_error_capacity = battery_controller->battery_controller_setpoint_capacity - battery_controller->battery_controller_input_capacity;
    battery_controller->battery_controller_error_soc = battery_controller->battery_controller_setpoint_soc - battery_controller->battery_controller_input_soc;
    battery_controller->battery_controller_error_temp = battery_controller->battery_controller_setpoint_temp - battery_controller->battery_controller_input_temp;
}
void battery_setpoint(battery_controller_t *battery_controller)
{
    battery_controller->battery_controller_setpoint_voltage = battery_controller->battery_controller_setpoint_voltage;
    battery_controller->battery_controller_setpoint_current = battery_controller->battery_controller_setpoint_current;
    battery_controller->battery_controller_setpoint_power = battery_controller->battery_controller_setpoint_power;
    battery_controller->battery_controller_setpoint_resistance = battery_controller->battery_controller_setpoint_resistance;
    battery_controller->battery_controller_setpoint_capacity = battery_controller->battery_controller_setpoint_capacity;
    battery_controller->battery_controller_setpoint_soc = battery_controller->battery_controller_setpoint_soc;
    battery_controller->battery_controller_setpoint_temp = battery_controller->battery_controller_setpoint_temp;
}
void battery_pid(battery_controller_t *battery_controller)
{
    battery_controller->battery_controller_pid_error = battery_controller->battery_controller_error_voltage;
    battery_controller->battery_controller_pid_integral += battery_controller->battery_controller_pid_error * battery_controller->battery_controller_pid_dt;
    battery_controller->battery_controller_pid_derivative = (battery_controller->battery_controller_pid_error - battery_controller->battery_controller_pid_pre_error) / battery_controller->battery_controller_pid_dt;
    battery_controller->battery_controller_pid_output = battery_controller->battery_controller_pid_kp * battery_controller->battery_controller_pid_error + battery_controller->battery_controller_pid_ki * battery_controller->battery_controller_pid_integral + battery_controller->battery_controller_pid_kd * battery_controller->battery_controller_pid_derivative;
    if (battery_controller->battery_controller_pid_output > battery_controller->battery_controller_pid_max)
    {
        battery_controller->battery_controller_pid_output = battery_controller->battery_controller_pid_max;
    }
    else if (battery_controller->battery_controller_pid_output < battery_controller->battery_controller_pid_min)
    {
        battery_controller->battery_controller_pid_output = battery_controller->battery_controller_pid_min;
    }
    battery_controller->battery_controller_pid_pre_error = battery_controller->battery_controller_pid_error;
}
void battery_controller(battery_controller_t *battery_controller)
{
    battery_input(battery_controller);
    battery_error(battery_controller);
    battery_setpoint(battery_controller);
    battery_pid(battery_controller);
    battery_output(battery_controller);
}

int32_t battery_controller_setpoint_voltage(battery_controller_t *battery_controller, float voltage)
{
    battery_controller->battery_controller_setpoint_voltage = voltage;
    return 0;
}
int32_t battery_controller_setpoint_current(battery_controller_t *battery_controller, float current)
{
    battery_controller->battery_controller_setpoint_current = current;
    return 0;
}
int32_t battery_controller_setpoint_power(battery_controller_t *battery_controller, float power)
{
    battery_controller->battery_controller_setpoint_power = power;
    return 0;
}
int32_t battery_controller_setpoint_resistance(battery_controller_t *battery_controller, float resistance)
{
    battery_controller->battery_controller_setpoint_resistance = resistance;
    return 0;
}
int32_t battery_controller_setpoint_capacity(battery_controller_t *battery_controller, float capacity)
{
    capacity = battery_controller->battery_controller_setpoint_voltage * battery_controller->battery_controller_setpoint_current;
    battery_controller->battery_controller_setpoint_capacity = capacity;
    return 0;
}
int32_t battery_controller_setpoint_soc(battery_controller_t *battery_controller, float soc)
{
    battery_controller->battery_controller_setpoint_soc = soc;
    return 0;
}
int32_t battery_controller_setpoint_temp(battery_controller_t *battery_controller, float temp)
{
    battery_controller->battery_controller_setpoint_temp = temp;
    return 0;
}

int32_t battery_controller_pid_kp(battery_controller_t *battery_controller, float kp)
{
    battery_controller->battery_controller_pid_kp = kp;
    return 0;
}
int32_t battery_controller_pid_ki(battery_controller_t *battery_controller, float ki)
{
    battery_controller->battery_controller_pid_ki = ki;
    return 0;
}
int32_t battery_controller_pid_kd(battery_controller_t *battery_controller, float kd)
{
    battery_controller->battery_controller_pid_kd = kd;
    return 0;
}
int32_t battery_controller_pid_dt(battery_controller_t *battery_controller, float dt)
{
    battery_controller->battery_controller_pid_dt = dt;
    return 0;
}
int32_t battery_controller_pid_max(battery_controller_t *battery_controller, float max)
{
    battery_controller->battery_controller_pid_max = max;
    return 0;
}
int32_t battery_controller_pid_min(battery_controller_t *battery_controller, float min)
{
    battery_controller->battery_controller_pid_min = min;
    return 0;
}

int32_t battery_controller_input_voltage(battery_controller_t *battery_controller, float voltage)
{
    battery_controller->battery_controller_input_voltage = voltage;
    return 0;
}
int32_t battery_controller_input_current(battery_controller_t *battery_controller, float current)
{
    battery_controller->battery_controller_input_current = current;
    return 0;
}
int32_t battery_controller_input_power(battery_controller_t *battery_controller, float power)
{
    battery_controller->battery_controller_input_power = power;
    return 0;
}
int32_t battery_controller_input_resistance(battery_controller_t *battery_controller, float resistance)
{
    battery_controller->battery_controller_input_resistance = resistance;
    return 0;
}
int32_t battery_controller_input_capacity(battery_controller_t *battery_controller, float capacity)
{
    battery_controller->battery_controller_input_capacity = capacity;
    return 0;
}
int32_t battery_controller_input_soc(battery_controller_t *battery_controller, float soc)
{
    battery_controller->battery_controller_input_soc = soc;
    return 0;
}
int32_t battery_controller_input_temp(battery_controller_t *battery_controller, float temp)
{
    battery_controller->battery_controller_input_temp = temp;
    return 0;
}

int32_t battery_controller_output_voltage(battery_controller_t *battery_controller, float voltage)
{
    battery_controller->battery_controller_output_voltage = voltage;
    return 0;
}
int32_t battery_controller_output_current(battery_controller_t *battery_controller, float current)
{
    battery_controller->battery_controller_output_current = current;
    return 0;
}
int32_t battery_controller_output_power(battery_controller_t *battery_controller, float power)
{
    battery_controller->battery_controller_output_power = power;
    return 0;
}
int32_t battery_controller_output_resistance(battery_controller_t *battery_controller, float resistance)
{
    battery_controller->battery_controller_output_resistance = resistance;
    return 0;
}
int32_t battery_controller_output_capacity(battery_controller_t *battery_controller, float capacity)
{
    battery_controller->battery_controller_output_capacity = capacity;
    return 0;
}
int32_t battery_controller_output_soc(battery_controller_t *battery_controller, float soc)
{
    battery_controller->battery_controller_output_soc = soc;
    return 0;
}
int32_t battery_controller_output_temp(battery_controller_t *battery_controller, float temp)
{
    battery_controller->battery_controller_output_temp = temp;
    return 0;
}

int32_t battery_controller_error_voltage(battery_controller_t *battery_controller, float voltage)
{
    battery_controller->battery_controller_error_voltage = voltage;
    return 0;
}
int32_t battery_controller_error_current(battery_controller_t *battery_controller, float current)
{
    battery_controller->battery_controller_error_current = current;
    return 0;
}
int32_t battery_controller_error_power(battery_controller_t *battery_controller, float power)
{
    battery_controller->battery_controller_error_power = power;
    return 0;
}
int32_t battery_controller_error_resistance(battery_controller_t *battery_controller, float resistance)
{
    battery_controller->battery_controller_error_resistance = resistance;
    return 0;
}
int32_t battery_controller_error_capacity(battery_controller_t *battery_controller, float capacity)
{
    battery_controller->battery_controller_error_capacity = capacity;
    return 0;
}
int32_t battery_controller_error_soc(battery_controller_t *battery_controller, float soc)
{
    battery_controller->battery_controller_error_soc = soc;
    return 0;
}
int32_t battery_controller_error_temp(battery_controller_t *battery_controller, float temp)
{
    battery_controller->battery_controller_error_temp = temp;
    return 0;
}

int32_t battery_controller_battery_voltage(battery_controller_t *battery_controller, float voltage)
{
    battery_controller->battery_controller_battery_voltage = voltage;
    return 0;
}
int32_t battery_controller_battery_current(battery_controller_t *battery_controller, float current)
{
    battery_controller->battery_controller_battery_current = current;
    return 0;
}
int32_t battery_controller_battery_power(battery_controller_t *battery_controller, float power)
{
    battery_controller->battery_controller_battery_power = power;
    return 0;
}
int32_t battery_controller_battery_resistance(battery_controller_t *battery_controller, float resistance)
{
    battery_controller->battery_controller_battery_resistance = resistance;
    return 0;
}
int32_t battery_controller_battery_capacity(battery_controller_t *battery_controller, float capacity)
{
    battery_controller->battery_controller_battery_capacity = capacity;
    return 0;
}
int32_t battery_controller_battery_soc(battery_controller_t *battery_controller, float soc)
{
    battery_controller->battery_controller_battery_soc = soc;
    return 0;
}
int32_t battery_controller_battery_temp(battery_controller_t *battery_controller, float temp)
{
    battery_controller->battery_controller_battery_temp = temp;
    return 0;
}

int32_t battery_controller_pid(battery_controller_t *battery_controller, float kp, float ki, float kd, float dt, float max, float min);
int32_t battery_controller_input(battery_controller_t *battery_controller, float voltage, float current, float power, float resistance, float capacity, float soc, float temp);
int32_t battery_controller_output(battery_controller_t *battery_controller, float voltage, float current, float power, float resistance, float capacity, float soc, float temp);
int32_t battery_controller_error(battery_controller_t *battery_controller, float voltage, float current, float power, float resistance, float capacity, float soc, float temp);
int32_t battery_controller_battery(battery_controller_t *battery_controller, float voltage, float current, float power, float resistance, float capacity, float soc, float temp);

int32_t battery_controller_pid_setpoint(battery_controller_t *battery_controller, float voltage, float current, float power, float resistance, float capacity, float soc, float temp);
int32_t battery_controller_pid_input(battery_controller_t *battery_controller, float voltage, float current, float power, float resistance, float capacity, float soc, float temp);
int32_t battery_controller_pid_output(battery_controller_t *battery_controller, float voltage, float current, float power, float resistance, float capacity, float soc, float temp);
int32_t battery_controller_pid_error(battery_controller_t *battery_controller, float voltage, float current, float power, float resistance, float capacity, float soc, float temp);

int32_t battery_controller_pid_setpoint_voltage(battery_controller_t *battery_controller, float voltage)
{
    battery_controller->battery_controller_pid_setpoint_voltage = voltage;
    return 0;
}
int32_t battery_controller_pid_setpoint_current(battery_controller_t *battery_controller, float current)
{
    battery_controller->battery_controller_pid_setpoint_current = current;
    return 0;
}
int32_t battery_controller_pid_setpoint_power(battery_controller_t *battery_controller, float power)
{
    battery_controller->battery_controller_pid_setpoint_power = power;
    return 0;
}
int32_t battery_controller_pid_setpoint_resistance(battery_controller_t *battery_controller, float resistance)
{
    battery_controller->battery_controller_pid_setpoint_resistance = resistance;
    return 0;
}
int32_t battery_controller_pid_setpoint_capacity(battery_controller_t *battery_controller, float capacity)
{
    battery_controller->battery_controller_pid_setpoint_capacity = capacity;
    return 0;
}
int32_t battery_controller_pid_setpoint_soc(battery_controller_t *battery_controller, float soc)
{
    battery_controller->battery_controller_pid_setpoint_soc = soc;
    return 0;
}
int32_t battery_controller_pid_setpoint_temp(battery_controller_t *battery_controller, float temp)
{
    battery_controller->battery_controller_pid_setpoint_temp = temp;
    return 0;
}

int32_t kalman_filter_init(kalman_filter_t *kalman_filter, float q, float r, float p, float x)
{
    kalman_filter->q = q;
    kalman_filter->r = r;
    kalman_filter->p = p;
    kalman_filter->x = x;
    return 0;
}
int32_t kalman_filter_update(kalman_filter_t *kalman_filter, float measurement)
{
    kalman_filter->p = kalman_filter->p + kalman_filter->q;
    kalman_filter->k = kalman_filter->p / (kalman_filter->p + kalman_filter->r);
    kalman_filter->x = kalman_filter->x + kalman_filter->k * (measurement - kalman_filter->x);
    kalman_filter->p = (1 - kalman_filter->k) * kalman_filter->p;
    return 0;
}
int32_t kalman_filter_set_q(kalman_filter_t *kalman_filter, float q)
{
    kalman_filter->q = q;
    return 0;
}
int32_t kalman_filter_set_r(kalman_filter_t *kalman_filter, float r)
{
    kalman_filter->r = r;
    return 0;
}
int32_t kalman_filter_set_p(kalman_filter_t *kalman_filter, float p)
{
    kalman_filter->p = p;
    return 0;
}
int32_t kalman_filter_set_x(kalman_filter_t *kalman_filter, float x)
{
    kalman_filter->x = x;
    return 0;
}
int32_t kalman_filter_get_q(kalman_filter_t *kalman_filter, float *q)
{
    *q = kalman_filter->q;
    return 0;
}
int32_t kalman_filter_get_r(kalman_filter_t *kalman_filter, float *r)
{
    *r = kalman_filter->r;
    return 0;
}
int32_t kalman_filter_get_p(kalman_filter_t *kalman_filter, float *p)
{
    *p = kalman_filter->p;
    return 0;
}
int32_t kalman_filter_get_x(kalman_filter_t *kalman_filter, float *x)
{
    *x = kalman_filter->x;
    return 0;
}

int32_t battery_controller_init(battery_controller_t *battery_controller, float kp, float ki, float kd, float dt, float max, float min)
{
    battery_controller->battery_controller_pid_kp = kp;
    battery_controller->battery_controller_pid_ki = ki;
    battery_controller->battery_controller_pid_kd = kd;
    battery_controller->battery_controller_pid_dt = dt;
    battery_controller->battery_controller_pid_max = max;
    battery_controller->battery_controller_pid_min = min;
    battery_controller->battery_controller_pid_last_time = 0;
    battery_controller->battery_controller_pid_last_error = 0;
    battery_controller->battery_controller_pid_integral = 0;
    return 0;
}
int32_t battery_controller_set_kp(battery_controller_t *battery_controller, float kp)
{
    battery_controller->battery_controller_pid_kp = kp;
    return 0;
}
int32_t battery_controller_set_ki(battery_controller_t *battery_controller, float ki)
{
    battery_controller->battery_controller_pid_ki = ki;
    return 0;
}
int32_t battery_controller_set_kd(battery_controller_t *battery_controller, float kd)
{
    battery_controller->battery_controller_pid_kd = kd;
    return 0;
}
int32_t battery_controller_set_dt(battery_controller_t *battery_controller, float dt)
{
    battery_controller->battery_controller_pid_dt = dt;
    return 0;
}
int32_t battery_controller_set_max(battery_controller_t *battery_controller, float max)
{
    battery_controller->battery_controller_pid_max = max;
    return 0;
}
int32_t battery_controller_set_min(battery_controller_t *battery_controller, float min)
{
    battery_controller->battery_controller_pid_min = min;
    return 0;
}
int32_t battery_controller_get_kp(battery_controller_t *battery_controller, float *kp)
{
    *kp = battery_controller->battery_controller_pid_kp;
    return 0;
}
int32_t battery_controller_get_ki(battery_controller_t *battery_controller, float *ki)
{
    *ki = battery_controller->battery_controller_pid_ki;
    return 0;
}
int32_t battery_controller_get_kd(battery_controller_t *battery_controller, float *kd)
{
    *kd = battery_controller->battery_controller_pid_kd;
    return 0;
}
int32_t battery_controller_get_dt(battery_controller_t *battery_controller, float *dt)
{
    *dt = battery_controller->battery_controller_pid_dt;
    return 0;
}
int32_t battery_controller_get_max(battery_controller_t *battery_controller, float *max)
{
    *max = battery_controller->battery_controller_pid_max;
    return 0;
}
int32_t battery_controller_get_min(battery_controller_t *battery_controller, float *min)
{
    *min = battery_controller->battery_controller_pid_min;
    return 0;
}

int32_t battery_controller_setpoint(battery_controller_t *battery_controller, float voltage, float current, float power, float resistance, float capacity, float soc, float temp)
{
    battery_controller->battery_controller_pid_setpoint_voltage = voltage;
    battery_controller->battery_controller_pid_setpoint_current = current;
    battery_controller->battery_controller_pid_setpoint_power = power;
    battery_controller->battery_controller_pid_setpoint_resistance = resistance;
    battery_controller->battery_controller_pid_setpoint_capacity = capacity;
    battery_controller->battery_controller_pid_setpoint_soc = soc;
    battery_controller->battery_controller_pid_setpoint_temp = temp;
    return 0;
}
int32_t battery_controller_input(battery_controller_t *battery_controller, float voltage, float current, float power, float resistance, float capacity, float soc, float temp)
{
    battery_controller->battery_controller_pid_input_voltage = voltage;
    battery_controller->battery_controller_pid_input_current = current;
    battery_controller->battery_controller_pid_input_power = power;
    battery_controller->battery_controller_pid_input_resistance = resistance;
    battery_controller->battery_controller_pid_input_capacity = capacity;
    battery_controller->battery_controller_pid_input_soc = soc;
    battery_controller->battery_controller_pid_input_temp = temp;
    return 0;
}
int32_t battery_controller_output(battery_controller_t *battery_controller, float voltage, float current, float power, float resistance, float capacity, float soc, float temp)
{
    battery_controller->battery_controller_pid_output_voltage = voltage;
    battery_controller->battery_controller_pid_output_current = current;
    battery_controller->battery_controller_pid_output_power = power;
    battery_controller->battery_controller_pid_output_resistance = resistance;
    battery_controller->battery_controller_pid_output_capacity = capacity;
    battery_controller->battery_controller_pid_output_soc = soc;
    battery_controller->battery_controller_pid_output_temp = temp;
    return 0;
}
int32_t battery_controller_error(battery_controller_t *battery_controller, float voltage, float current, float power, float resistance, float capacity, float soc, float temp)
{
    battery_controller->battery_controller_pid_error_voltage = voltage;
    battery_controller->battery_controller_pid_error_current = current;
    battery_controller->battery_controller_pid_error_power = power;
    battery_controller->battery_controller_pid_error_resistance = resistance;
    battery_controller->battery_controller_pid_error_capacity = capacity;
    battery_controller->battery_controller_pid_error_soc = soc;
    battery_controller->battery_controller_pid_error_temp = temp;
    return 0;
}
int32_t battery_controller_battery(battery_controller_t *battery_controller, float voltage, float current, float power, float resistance, float capacity, float soc, float temp)
{
    battery_controller->battery_controller_pid_battery_voltage = voltage;
    battery_controller->battery_controller_pid_battery_current = current;
    battery_controller->battery_controller_pid_battery_power = power;
    battery_controller->battery_controller_pid_battery_resistance = resistance;
    battery_controller->battery_controller_pid_battery_capacity = capacity;
    battery_controller->battery_controller_pid_battery_soc = soc;
    battery_controller->battery_controller_pid_battery_temp = temp;
    return 0;
}

int32_t estimate_battery_states(battery_controller_t *battery_controller, float voltage, float current, float power, float resistance, float capacity, float soc, float temp)
{
    battery_controller->battery_controller_pid_battery_voltage = voltage;
    battery_controller->battery_controller_pid_battery_current = current;
    battery_controller->battery_controller_pid_battery_power = power;
    battery_controller->battery_controller_pid_battery_resistance = resistance;
    battery_controller->battery_controller_pid_battery_capacity = capacity;
    battery_controller->battery_controller_pid_battery_soc = soc;
    battery_controller->battery_controller_pid_battery_temp = temp;
    return 0;
}

int32_t simulate_battery(battery_controller_t *battery_controller, float voltage, float current, float power, float resistance, float capacity, float soc, float temp)
{
    battery_controller->battery_controller_pid_battery_voltage = voltage;
    battery_controller->battery_controller_pid_battery_current = current;
    battery_controller->battery_controller_pid_battery_power = power;
    battery_controller->battery_controller_pid_battery_resistance = resistance;
    battery_controller->battery_controller_pid_battery_capacity = capacity;
    battery_controller->battery_controller_pid_battery_soc = soc;
    battery_controller->battery_controller_pid_battery_temp = temp;
    return 0;
}
int32_t simulate_battery_controller(battery_controller_t *battery_controller, float voltage, float current, float power, float resistance, float capacity, float soc, float temp)
{
    battery_controller->battery_controller_pid_battery_voltage = voltage;
    battery_controller->battery_controller_pid_battery_current = current;
    battery_controller->battery_controller_pid_battery_power = power;
    battery_controller->battery_controller_pid_battery_resistance = resistance;
    battery_controller->battery_controller_pid_battery_capacity = capacity;
    battery_controller->battery_controller_pid_battery_soc = soc;
    battery_controller->battery_controller_pid_battery_temp = temp;
    return 0;
}
int32_t simulate_battery_controller_pid(battery_controller_t *battery_controller, float voltage, float current, float power, float resistance, float capacity, float soc, float temp)
{
    battery_controller->battery_controller_pid_battery_voltage = voltage;
    battery_controller->battery_controller_pid_battery_current = current;
    battery_controller->battery_controller_pid_battery_power = power;
    battery_controller->battery_controller_pid_battery_resistance = resistance;
    battery_controller->battery_controller_pid_battery_capacity = capacity;
    battery_controller->battery_controller_pid_battery_soc = soc;
    battery_controller->battery_controller_pid_battery_temp = temp;
    return 0;
}

battery_controller_t *battery_controller_create(float kp, float ki, float kd, float dt, float max, float min)
{
    battery_controller_t *battery_controller = (battery_controller_t *)malloc(sizeof(battery_controller_t));
    battery_controller->battery_controller_pid_kp = kp;
    battery_controller->battery_controller_pid_ki = ki;
    battery_controller->battery_controller_pid_kd = kd;
    battery_controller->battery_controller_pid_dt = dt;
    battery_controller->battery_controller_pid_max = max;
    battery_controller->battery_controller_pid_min = min;
    battery_controller->battery_controller_pid_error_previous = 0.0;
    battery_controller->battery_controller_pid_error_sum = 0.0;
    battery_controller->battery_controller_pid_error_derivative = 0.0;
    battery_controller->battery_controller_pid_error = 0.0;
    battery_controller->battery_controller_pid_output_previous = 0.0;
    battery_controller->battery_controller_pid_output = 0.0;
    battery_controller->battery_controller_pid_output_voltage = 0.0;
    battery_controller->battery_controller_pid_output_current = 0.0;
    battery_controller->battery_controller_pid_output_power = 0.0;
    battery_controller->battery_controller_pid_output_resistance = 0.0;
    battery_controller->battery_controller_pid_output_capacity = 0.0;
    battery_controller->battery_controller_pid_output_soc = 0.0;
    battery_controller->battery_controller_pid_output_temp = 0.0;
    battery_controller->battery_controller_pid_error_voltage = 0.0;
    battery_controller->battery_controller_pid_error_current = 0.0;
    battery_controller->battery_controller_pid_error_power = 0.0;
    battery_controller->battery_controller_pid_error_resistance = 0.0;
    battery_controller->battery_controller_pid_error_capacity = 0.0;
    battery_controller->battery_controller_pid_error_soc = 0.0;
    battery_controller->battery_controller_pid_error_temp = 0.0;
    battery_controller->battery_controller_pid_battery_voltage = 0.0;
    battery_controller->battery_controller_pid_battery_current = 0.0;
    battery_controller->battery_controller_pid_battery_power = 0.0;
    battery_controller->battery_controller_pid_battery_resistance = 0.0;
    battery_controller->battery_controller_pid_battery_capacity = 0.0;
    battery_controller->battery_controller_pid_battery_soc = 0.0;
    battery_controller->battery_controller_pid_battery_temp = 0.0;
    return battery_controller;
}

int32_t battery_controller_destroy(battery_controller_t *battery_controller)
{
    if (battery_controller)
    {
        free(battery_controller);
    }
    return 0;
}

void printLiveData(battery_controller_t *battery_controller, float voltage, float current, float power, float resistance, float capacity, float soc, float temp)
{
    printf("voltage: %f\n", voltage);
    printf("current: %f\n", current);
    printf("power: %f\n", power);
    printf("resistance: %f\n", resistance);
    printf("capacity: %f\n", capacity);
    printf("soc: %f\n", soc);
    printf("temp: %f\n", temp);
}

battery_controller_t randomizeInitialParameters(battery_controller_t *battery_controller, float *voltage, float *current, float *power, float *resistance, float *capacity, float *soc, float *temp)
{
    srand(time(NULL));
    *voltage = (float)rand() / (float)(RAND_MAX / 100);
    *current = (float)rand() / (float)(RAND_MAX / 100);
    *power = (float)rand() / (float)(RAND_MAX / 100);
    *resistance = (float)rand() / (float)(RAND_MAX / 100);
    *capacity = (float)rand() / (float)(RAND_MAX / 100);
    *soc = (float)rand() / (float)(RAND_MAX / 100);
    *temp = (float)rand() / (float)(RAND_MAX / 100);
    return *battery_controller;
}

battery_controller_t simulate_kalman_filter(battery_controller_t *battery_controller, float voltage, float current, float power, float resistance, float capacity, float soc, float temp)
{
    battery_controller->battery_controller_pid_battery_voltage = voltage;
    battery_controller->battery_controller_pid_battery_current = current;
    battery_controller->battery_controller_pid_battery_power = power;
    battery_controller->battery_controller_pid_battery_resistance = resistance;
    battery_controller->battery_controller_pid_battery_capacity = capacity;
    battery_controller->battery_controller_pid_battery_soc = soc;
    battery_controller->battery_controller_pid_battery_temp = temp;
    return *battery_controller;
}

void simulate_live_test(battery_controller_t *battery_controller, float voltage, float current, float power, float resistance, float capacity, float soc, float temp)
{
    battery_controller->battery_controller_pid_battery_voltage = voltage;
    battery_controller->battery_controller_pid_battery_current = current;
    battery_controller->battery_controller_pid_battery_power = power;
    battery_controller->battery_controller_pid_battery_resistance = resistance;
    battery_controller->battery_controller_pid_battery_capacity = capacity;
    battery_controller->battery_controller_pid_battery_soc = soc;
    battery_controller->battery_controller_pid_battery_temp = temp;
    // use Kalman Filter
    battery_controller->battery_controller_pid_battery_voltage = battery_controller->battery_controller_pid_battery_voltage + (float)rand() / (float)(RAND_MAX / 100);
    battery_controller->battery_controller_pid_battery_current = battery_controller->battery_controller_pid_battery_current + (float)rand() / (float)(RAND_MAX / 100);
    battery_controller->battery_controller_pid_battery_power = battery_controller->battery_controller_pid_battery_power + (float)rand() / (float)(RAND_MAX / 100);
    battery_controller->battery_controller_pid_battery_resistance = battery_controller->battery_controller_pid_battery_resistance + (float)rand() / (float)(RAND_MAX / 100);
    battery_controller->battery_controller_pid_battery_capacity = battery_controller->battery_controller_pid_battery_capacity + (float)rand() / (float)(RAND_MAX / 100);
    battery_controller->battery_controller_pid_battery_soc = battery_controller->battery_controller_pid_battery_soc + (float)rand() / (float)(RAND_MAX / 100);
    battery_controller->battery_controller_pid_battery_temp = battery_controller->battery_controller_pid_battery_temp + (float)rand() / (float)(RAND_MAX / 100);
    // use PID Controller
    battery_controller->battery_controller_pid_error_voltage = battery_controller->battery_controller_pid_battery_voltage - battery_controller->battery_controller_pid_battery_voltage;
    battery_controller->battery_controller_pid_error_current = battery_controller->battery_controller_pid_battery_current - battery_controller->battery_controller_pid_battery_current;
    battery_controller->battery_controller_pid_error_power = battery_controller->battery_controller_pid_battery_power - battery_controller->battery_controller_pid_battery_power;
    battery_controller->battery_controller_pid_error_resistance = battery_controller->battery_controller_pid_battery_resistance - battery_controller->battery_controller_pid_battery_resistance;
    battery_controller->battery_controller_pid_error_capacity = battery_controller->battery_controller_pid_battery_capacity - battery_controller->battery_controller_pid_battery_capacity;
    battery_controller->battery_controller_pid_error_soc = battery_controller->battery_controller_pid_battery_soc - battery_controller->battery_controller_pid_battery_soc;
    battery_controller->battery_controller_pid_error_temp = battery_controller->battery_controller_pid_battery_temp - battery_controller->battery_controller_pid_battery_temp;
    battery_controller->battery_controller_pid_error_voltage_sum = battery_controller->battery_controller_pid_error_voltage_sum + battery_controller->battery_controller_pid_error_voltage;
    battery_controller->battery_controller_pid_error_current_sum = battery_controller->battery_controller_pid_error_current_sum + battery_controller->battery_controller_pid_error_current;
    battery_controller->battery_controller_pid_error_power_sum = battery_controller->battery_controller_pid_error_power_sum + battery_controller->battery_controller_pid_error_power;
    battery_controller->battery_controller_pid_error_resistance_sum = battery_controller->battery_controller_pid_error_resistance_sum + battery_controller->battery_controller_pid_error_resistance;
    battery_controller->battery_controller_pid_error_capacity_sum = battery_controller->battery_controller_pid_error_capacity_sum + battery_controller->battery_controller_pid_error_capacity;
    battery_controller->battery_controller_pid_error_soc_sum = battery_controller->battery_controller_pid_error_soc_sum + battery_controller->battery_controller_pid_error_soc;
    battery_controller->battery_controller_pid_error_temp_sum = battery_controller->battery_controller_pid_error_temp_sum + battery_controller->battery_controller_pid_error_temp;
    // print results
    printLiveData(battery_controller, voltage, current, power, resistance, capacity, soc, temp);
}

void test_battery(void)
{
    battery_controller_t *battery_controller = battery_controller_create(0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
    float voltage = 0.0;
    float current = 0.0;
    float power = 0.0;
    float resistance = 0.0;
    float capacity = 0.0;
    float soc = 0.0;
    float temp = 0.0;
    randomizeInitialParameters(battery_controller, &voltage, &current, &power, &resistance, &capacity, &soc, &temp);
    simulate_battery_controller_pid(battery_controller, voltage, current, power, resistance, capacity, soc, temp);
    simulate_kalman_filter(battery_controller, voltage, current, power, resistance, capacity, soc, temp);
    printLiveData(battery_controller, voltage, current, power, resistance, capacity, soc, temp);
    battery_controller_destroy(battery_controller);
}

int main(int argc, char *argv[])
{
    battery_controller_t *battery_controller = battery_controller_create(0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
    test_battery();
    battery_controller_destroy(battery_controller);
    return 0;
}
