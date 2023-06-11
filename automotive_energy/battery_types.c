/**
 * @file battery_types.c
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-06-11
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "datatypes.h"
#include "battery.h"
#include "battery_types.h"

typedef struct lithium_ion_cell_t
{
    f32 voltage;
    f32 current;
    f32 temperature;
    f32 state_of_charge;
    f32 state_of_health;
    f32 state_of_power;
    f32 state_of_energy;
    f32 state_of_function;
    f32 state_of_safety;
    f32 state_of_life;
    f32 state_of_wear;
    f32 state_of_use;
    f32 state_of_storage;
    f32 state_of_freshness;
    f32 state_of_health_aging;
    f32 state_of_health_calendar;
    f32 state_of_health_cycling;
    f32 state_of_health_storage;
    f32 state_of_health_temperature;
    f32 state_of_health_voltage;
    f32 state_of_health_current;
    f32 state_of_health_power;
    f32 state_of_health_energy;
    f32 state_of_health_function;
    f32 state_of_health_safety;
    f32 state_of_health_life;
    f32 state_of_health_wear;
    f32 state_of_health_use;
    f32 state_of_health_freshness;

} lithium_ion_cell_t;
typedef struct lithium_ion_module_t
{
    f32 voltage;
    f32 current;
    f32 temperature;
    f32 state_of_charge;
    f32 state_of_health;
    f32 state_of_power;
    f32 state_of_energy;
    f32 state_of_function;
    f32 state_of_safety;
    f32 state_of_life;
    f32 state_of_wear;
    f32 state_of_use;
    f32 state_of_storage;
    f32 state_of_freshness;
    f32 state_of_health_aging;
    f32 state_of_health_calendar;
    f32 state_of_health_cycling;
    f32 state_of_health_storage;
    f32 state_of_health_temperature;
    f32 state_of_health_voltage;
    f32 state_of_health_current;
    f32 state_of_health_power;
    f32 state_of_health_energy;
    f32 state_of_health_function;
    f32 state_of_health_safety;
    f32 state_of_health_life;
    f32 state_of_health_wear;
    f32 state_of_health_use;
    f32 state_of_health_freshness;
} lithium_ion_module_t;
typedef struct lithium_ion_pack_t
{
    f32 voltage;
    f32 current;
    f32 temperature;
    f32 state_of_charge;
    f32 state_of_health;
    f32 state_of_power;
    f32 state_of_energy;
    f32 state_of_function;
    f32 state_of_safety;
    f32 state_of_life;
    f32 state_of_wear;
    f32 state_of_use;
    f32 state_of_storage;
    f32 state_of_freshness;
    f32 state_of_health_aging;
    f32 state_of_health_calendar;
    f32 state_of_health_cycling;
    f32 state_of_health_storage;
    f32 state_of_health_temperature;
    f32 state_of_health_voltage;
    f32 state_of_health_current;
    f32 state_of_health_power;
    f32 state_of_health_energy;
    f32 state_of_health_function;
    f32 state_of_health_safety;
    f32 state_of_health_life;
    f32 state_of_health_wear;
    f32 state_of_health_use;
    f32 state_of_health_freshness;
} lithium_ion_pack_t;
typedef struct lithium_ion_battery_t
{
    f32 voltage;
    f32 current;
    f32 temperature;
    f32 state_of_charge;
    f32 state_of_health;
    f32 state_of_power;
    f32 state_of_energy;
    f32 state_of_function;
    f32 state_of_safety;
    f32 state_of_life;
    f32 state_of_wear;
    f32 state_of_use;
    f32 state_of_storage;
    f32 state_of_freshness;
    f32 state_of_health_aging;
    f32 state_of_health_calendar;
    f32 state_of_health_cycling;
    f32 state_of_health_storage;
    f32 state_of_health_temperature;
    f32 state_of_health_voltage;
    f32 state_of_health_current;
    f32 state_of_health_power;
    f32 state_of_health_energy;
    f32 state_of_health_function;
    f32 state_of_health_safety;
    f32 state_of_health_life;
    f32 state_of_health_wear;
    f32 state_of_health_use;
    f32 state_of_health_freshness;
} lithium_ion_battery_t;

void get_cell_voltage(lithium_ion_cell_t *cell, f32 *voltage)
{
    *voltage = cell->voltage;
}
void get_cell_current(lithium_ion_cell_t *cell, f32 *current)
{
    *current = cell->current;
}
void get_cell_temperature(lithium_ion_cell_t *cell, f32 *temperature)
{
    *temperature = cell->temperature;
}
void get_cell_state_of_charge(lithium_ion_cell_t *cell, f32 *state_of_charge)
{
    *state_of_charge = cell->state_of_charge;
}
void get_cell_state_of_health(lithium_ion_cell_t *cell, f32 *state_of_health)
{
    *state_of_health = cell->state_of_health;
}
void get_cell_state_of_power(lithium_ion_cell_t *cell, f32 *state_of_power)
{
    *state_of_power = cell->state_of_power;
}
void get_cell_state_of_energy(lithium_ion_cell_t *cell, f32 *state_of_energy)
{
    *state_of_energy = cell->state_of_energy;
}
void get_cell_state_of_function(lithium_ion_cell_t *cell, f32 *state_of_function)
{
    *state_of_function = cell->state_of_function;
}
void get_cell_state_of_safety(lithium_ion_cell_t *cell, f32 *state_of_safety)
{
    *state_of_safety = cell->state_of_safety;
}
void get_cell_state_of_life(lithium_ion_cell_t *cell, f32 *state_of_life)
{
    *state_of_life = cell->state_of_life;
}
void get_cell_state_of_wear(lithium_ion_cell_t *cell, f32 *state_of_wear)
{
    *state_of_wear = cell->state_of_wear;
}
void get_cell_state_of_use(lithium_ion_cell_t *cell, f32 *state_of_use)
{
    *state_of_use = cell->state_of_use;
}
void get_cell_state_of_storage(lithium_ion_cell_t *cell, f32 *state_of_storage)
{
    *state_of_storage = cell->state_of_storage;
}
void get_cell_state_of_freshness(lithium_ion_cell_t *cell, f32 *state_of_freshness)
{
    *state_of_freshness = cell->state_of_freshness;
}
void get_cell_state_of_health_aging(lithium_ion_cell_t *cell, f32 *state_of_health_aging)
{
    *state_of_health_aging = cell->state_of_health_aging;
}