/**
 * @file battery_main.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-08-12
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "controller.h"
#include "battery_main.h" 
#include <stdio.h>

extern int main(void);

extern CONTROLLER *get_controller(void);

int main(void)
{
    CONTROLLER *controller = get_controller();
    controller->init();
    controller->run();
    controller->deinit();
    return 0;
}

