/**
 * @file battery_hwio.c
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-06-11
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "battery.h"
#include "datatypes.h"
#include "battery_types.h"
#include "battery_hwio.h"

void read_hardware_input(hardware_input *hw_input)
{
    hw_input->voltage = 0.0f;
    hw_input->current = 0.0f;
    hw_input->temperature = 0.0f;
}
void write_hardware_output(hardware_output *hw_output)
{
    hw_output->voltage = 0.0f;
    hw_output->current = 0.0f;
    hw_output->temperature = 0.0f;
}
void get_hardware_input_state(hwio_interface_states *hwio_state)
{
    *hwio_state = HWIO_INTERFACE_STATE_IDLE;
}
void get_hardware_output_state(hwio_interface_states *hwio_state)
{
    *hwio_state = HWIO_INTERFACE_STATE_IDLE;
}
void set_hardware_input_state(hwio_interface_states hwio_state)
{
    hwio_state = HWIO_INTERFACE_STATE_IDLE;
}
void set_hardware_output_state(hwio_interface_states hwio_state)
{
    hwio_state = HWIO_INTERFACE_STATE_IDLE;
}
void put_hardware_input_state(hwio_interface_states *hwio_state)
{
    *hwio_state = HWIO_INTERFACE_STATE_IDLE;
}
void put_hardware_output_state(hwio_interface_states *hwio_state)
{
    *hwio_state = HWIO_INTERFACE_STATE_IDLE;
}
void update_hardware_input_state(hwio_interface_states *hwio_state)
{
    if (*hwio_state = HWIO_INTERFACE_STATE_IDLE)
    {
        *hwio_state = HWIO_INTERFACE_STATE_READ;
    }
    else if (*hwio_state = HWIO_INTERFACE_STATE_READ)
    {
        *hwio_state = HWIO_INTERFACE_STATE_IDLE;
    }
    else
    {
        *hwio_state = HWIO_INTERFACE_STATE_ERROR;
    }
}
void update_hardware_output_state(hwio_interface_states *hwio_state)
{
    if (*hwio_state = HWIO_INTERFACE_STATE_IDLE)
    {
        *hwio_state = HWIO_INTERFACE_STATE_WRITE;
    }
    else if (*hwio_state = HWIO_INTERFACE_STATE_WRITE)
    {
        *hwio_state = HWIO_INTERFACE_STATE_IDLE;
    }
    else
    {
        *hwio_state = HWIO_INTERFACE_STATE_ERROR;
    }
}

void read_hardware_input_raster(hardware_input *hw_input)
{
    hw_input->voltage = 0.0f;
    hw_input->current = 0.0f;
    hw_input->temperature = 0.0f;
}
void write_hardware_output_raster(hardware_output *hw_output)
{
    hw_output->voltage = 0.0f;
    hw_output->current = 0.0f;
    hw_output->temperature = 0.0f;
}
void get_hardware_input_state_raster(hwio_interface_states *hwio_state)
{
    *hwio_state = HWIO_INTERFACE_STATE_IDLE;
}
void get_hardware_output_state_raster(hwio_interface_states *hwio_state)
{
    *hwio_state = HWIO_INTERFACE_STATE_IDLE;
}