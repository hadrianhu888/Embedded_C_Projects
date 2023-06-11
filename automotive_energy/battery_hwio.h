/**
 * @file battery_hwio.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-06-11
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef BATTERY_HWIO_H_
#define BATTERY_HWIO_H_

#include "battery.h"
#include "datatypes.h"
#include "battery_types.h"

typedef struct hardware_input
{
    f32 voltage;
    f32 current;
    f32 temperature;
} hardware_input;
typedef struct hardware_output
{
    f32 voltage;
    f32 current;
    f32 temperature;
} hardware_output;
typedef enum hwio_interface_states
{
    HWIO_INTERFACE_STATE_IDLE,
    HWIO_INTERFACE_STATE_READ,
    HWIO_INTERFACE_STATE_WRITE,
    HWIO_INTERFACE_STATE_ERROR,
} hwio_interface_states;

// function prototypes

void read_hardware_input(hardware_input *hw_input);
void write_hardware_output(hardware_output *hw_output);
void get_hardware_input_state(hwio_interface_states *hwio_state);
void get_hardware_output_state(hwio_interface_states *hwio_state);
void set_hardware_input_state(hwio_interface_states hwio_state);
void set_hardware_output_state(hwio_interface_states hwio_state);
void put_hardware_input_state(hwio_interface_states *hwio_state);
void put_hardware_output_state(hwio_interface_states *hwio_state);
void update_hardware_input_state(hwio_interface_states *hwio_state);
void update_hardware_output_state(hwio_interface_states *hwio_state);

// OS raster functions

void read_hardware_input_raster(hardware_input *hw_input);
void write_hardware_output_raster(hardware_output *hw_output);
void get_hardware_input_state_raster(hwio_interface_states *hwio_state);
void get_hardware_output_state_raster(hwio_interface_states *hwio_state);

#endif /* BATTERY_HWIO_H_ */