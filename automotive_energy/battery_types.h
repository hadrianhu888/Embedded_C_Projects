/**
 * @file battery_types.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-06-11
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef BATTERY_TYPES_H_
#define BATTERY_TYPES_H_

#include "battery.h"

typedef struct lithium_ion_cell_t lithium_ion_cell_t;
typedef struct lithium_ion_module_t lithium_ion_module_t;
typedef struct lithium_ion_pack_t lithium_ion_pack_t;
typedef struct lithium_ion_battery_t lithium_ion_battery_t;

// function prototypes

void get_cell_voltage(lithium_ion_cell_t *cell, f32 *voltage);
void get_cell_current(lithium_ion_cell_t *cell, f32 *current);
void get_cell_temperature(lithium_ion_cell_t *cell, f32 *temperature);
void get_cell_state_of_charge(lithium_ion_cell_t *cell, f32 *state_of_charge);
void get_cell_state_of_health(lithium_ion_cell_t *cell, f32 *state_of_health);
void get_cell_state_of_power(lithium_ion_cell_t *cell, f32 *state_of_power);
void get_cell_state_of_energy(lithium_ion_cell_t *cell, f32 *state_of_energy);
void get_cell_state_of_function(lithium_ion_cell_t *cell, f32 *state_of_function);
void get_cell_state_of_safety(lithium_ion_cell_t *cell, f32 *state_of_safety);
void get_cell_state_of_life(lithium_ion_cell_t *cell, f32 *state_of_life);
void get_cell_state_of_wear(lithium_ion_cell_t *cell, f32 *state_of_wear);
void get_cell_state_of_use(lithium_ion_cell_t *cell, f32 *state_of_use);
void get_cell_state_of_storage(lithium_ion_cell_t *cell, f32 *state_of_storage);
void get_cell_state_of_freshness(lithium_ion_cell_t *cell, f32 *state_of_freshness);
void get_cell_state_of_health_aging(lithium_ion_cell_t *cell, f32 *state_of_health_aging);

#endif /* BATTERY_TYPES_H_ */