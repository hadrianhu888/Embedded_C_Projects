/**
 * @file controller.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-08-12
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef CONTROLLER_H
#define CONTROLLER_H

typedef struct CONTROLLER
{
    int (*init)(void);
    int (*deinit)(void);
    int (*start)(void);
    int (*stop)(void);
    int (*set)(void);
    int (*get)(void);
    int (*run)(void);
} CONTROLLER;

typedef struct CONTROLLER_INIT
{
    int (*init)(void);
} CONTROLLER_INIT;

typedef struct CONTROLLER_DEINIT
{
    int (*deinit)(void);
} CONTROLLER_DEINIT;

typedef struct CONTROLLER_START
{
    int (*start)(void);
} CONTROLLER_START;

typedef struct CONTROLLER_STOP
{
    int (*stop)(void);
} CONTROLLER_STOP;

typedef struct CONTROLLER_SET
{
    int (*set)(void);
} CONTROLLER_SET;

typedef struct CONTROLLER_GET
{
    int (*get)(void);
} CONTROLLER_GET;

typedef struct CONTROLLER_RUN
{
    int (*run)(void);
} CONTROLLER_RUN;

CONTROLLER *get_controller(void);

#endif // CONTROLLER_H