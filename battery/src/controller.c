/**
 * @file controller.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-08-12
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "controller.h"

extern int controller_init(void);
extern int controller_deinit(void);
extern int controller_start(void);
extern int controller_stop(void);
extern int controller_set(void);
extern int controller_get(void);

static int controller_init(void)
{
    printf("controller_init\n");
    return 0;
}
static int controller_deinit(void)
{
    printf("controller_deinit\n");
    return 0;
}
static int controller_start(void)
{
    printf("controller_start\n");
    return 0;
}
static int controller_stop(void)
{
    printf("controller_stop\n");
    return 0;
}
static int controller_set(void)
{
    printf("controller_set\n");
    return 0;
}
static int controller_get(void)
{
    printf("controller_get\n");
    return 0;
}

static CONTROLLER_INIT controller_init_obj = {controller_init};
static CONTROLLER_DEINIT controller_deinit_obj = {controller_deinit};
static CONTROLLER_START controller_start_obj = {controller_start};
static CONTROLLER_STOP controller_stop_obj = {controller_stop};
static CONTROLLER_SET controller_set_obj = {controller_set};
static CONTROLLER_GET controller_get_obj = {controller_get};

static CONTROLLER controller_obj = {
    .init = &controller_init_obj,
    .deinit = &controller_deinit_obj,
    .start = &controller_start_obj,
    .stop = &controller_stop_obj,
    .set = &controller_set_obj,
    .get = &controller_get_obj,
};

CONTROLLER *get_controller(void)
{
    return &controller_obj;
}

CONTROLLER *get_controller_init(void)
{
    return &controller_init_obj;
}

CONTROLLER *get_controller_deinit(void)
{
    return &controller_deinit_obj;
}

CONTROLLER *get_controller_start(void)
{
    return &controller_start_obj;
}

CONTROLLER *get_controller_stop(void)
{
    return &controller_stop_obj;
}

CONTROLLER *get_controller_set(void)
{
    return &controller_set_obj;
}

CONTROLLER *run(void)
{
    return &controller_obj;
}

CONTROLLER *get_controller_get(void)
{
    return &controller_get_obj;
}
// Path: battery\main.c

