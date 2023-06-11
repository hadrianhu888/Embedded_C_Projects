/**
 * @file simple_thermostat.c
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-06-10
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <time.h>
#include <stdbool.h>

#define MAX_TEMP 30.00
#define MIN_TEMP 15.00

#define MAX_HUMIDITY 100.00
#define MIN_HUMIDITY 0.00

#define MAX_PRESSURE 100.00
#define MIN_PRESSURE 0.00

#define MAX_NAME 20
#define MAX_LOGS 100
#define MAX_DEVICES 100
#define MAX_ROOMS 100
#define MAX_ROOMS_PER_DEVICE 10
#define MAX_DEVICES_PER_ROOM 10
#define MAX_LOGS_PER_DEVICE 100
#define MAX_LOGS_PER_ROOM 100
#define MAX_LOGS_PER_THERMOSTAT 100
#define MAX_LOGS_PER_SENSOR 100
#define MAX_LOGS_PER_ACTUATOR 100
#define MAX_LOGS_PER_HUMIDITY_SENSOR 100
#define MAX_LOGS_PER_DEVICE 100
#define MAX_LOGS_PER_THERMOSTAT 100
#define MAX_LOGS_PER_SENSOR 100
#define MAX_LOGS_PER_ACTUATOR 100
#define MAX_LOGS_PER_HUMIDITY_SENSOR 100
#define MAX_LOGS_PER_PRESSURE_SENSOR 100
#define MAX_LOGS_PER_TEMPERATURE_SENSOR 100
#define MAX_LOGS_PER_HEATER 100
#define MAX_LOGS_PER_COOLER 100
#define MAX_LOGS_PER_HUMIDIFIER 100
#define MAX_LOGS_PER_DEHUMIDIFIER 100
#define MAX_LOGS_PER_WINDOW 100
#define MAX_LOGS_PER_DOOR 100
#define MAX_LOGS_PER_LIGHT 100
#define MAX_LOGS_PER_BLIND 100
#define MAX_LOGS_PER_CURTAIN 100
#define MAX_LOGS_PER_FAN 100
#define MAX_LOGS_PER_AIR_CONDITIONER 100
#define MAX_LOGS_PER_HEATER_COOLER 100
#define MAX_LOGS_PER_HUMIDIFIER_DEHUMIDIFIER 100
#define MAX_LOGS_PER_WINDOW_DOOR 100
#define MAX_LOGS_PER_LIGHT_BLIND_CURTAIN 100
#define MAX_LOGS_PER_FAN_AIR_CONDITIONER 100

typedef struct
{
    int day;
    int month;
    int year;
    int hour;
    int minute;
    int second;
} DateTime;

typedef struct
{
    char name[MAX_NAME];
    DateTime date_time;
    float temperature;
    float humidity;
    float pressure;
    int id;
    int room_id;
    int device_id;
    int device_state;
    int device_type;
    int device_control_state;
    int device_control_mode;
    int user_control_state;
    int user_control_mode;
    int device_user_control_state;
    int device_user_control_mode;
} Log;

typedef struct
{
    char name[MAX_NAME];
    int id;
    int room_id;
    int logs_count;
    Log logs[MAX_LOGS_PER_DEVICE];
} Device;

typedef struct
{
    char name[MAX_NAME];
    int id;
    int devices_count;
    Device devices[MAX_DEVICES_PER_ROOM];
} Room;

typedef struct
{
    int rooms_count;
    Room rooms[MAX_ROOMS];
} House;

typedef struct
{
    int devices_count;
    Device devices[MAX_DEVICES];
} Devices;

typedef struct
{
    int rooms_count;
    Room rooms[MAX_ROOMS];
} Rooms;

typedef struct
{
    int logs_count;
    Log logs[MAX_LOGS];
} Logs;

typedef enum deviceStates
{
    OFF,
    ON
} DeviceState;

typedef enum deviceTypes
{
    THERMOSTAT,
    SENSOR,
    ACTUATOR,
    HUMIDITY_SENSOR,
    PRESSURE_SENSOR,
    TEMPERATURE_SENSOR,
    HEATER,
    COOLER,
    HUMIDIFIER,
    DEHUMIDIFIER,
    WINDOW,
    DOOR,
    LIGHT,
    BLIND,
    CURTAIN,
    FAN,
    AIR_CONDITIONER,
    HEATER_COOLER,
    HUMIDIFIER_DEHUMIDIFIER,
    WINDOW_DOOR,
    LIGHT_BLIND_CURTAIN,
    FAN_AIR_CONDITIONER
} DeviceType;

typedef enum UserControlStates
{
    USER_CONTROL_OFF,
    USER_CONTROL_ON
} UserControlState;

typedef enum deviceControlStates
{
    DEVICE_CONTROL_OFF,
    DEVICE_CONTROL_ON
} DeviceControlState;

typedef enum deviceControlModes
{
    DEVICE_CONTROL_MODE_OFF,
    DEVICE_CONTROL_MODE_AUTO,
    DEVICE_CONTROL_MODE_MANUAL,
    DEVICE_CONTROL_MODE_SCHEDULE,
    DEVICE_CONTROL_MODE_TIMER,
    DEVICE_CONTROL_MODE_SENSOR,
    DEVICE_CONTROL_MODE_SENSOR_SCHEDULE,
    DEVICE_CONTROL_MODE_SENSOR_TIMER,
    DEVICE_CONTROL_MODE_SENSOR_SCHEDULE_TIMER,
    AUTOMATIC
} DeviceControlMode;

typedef struct DeviceControl
{
    char name[MAX_NAME];
    int id;
    int room_id;
    DeviceType type;
    DeviceState state;
    DeviceState AUTOMATIC;
    DeviceControlState control_state;
    DeviceControlMode control_mode;
    UserControlState user_control_state;
    UserControlState user_control_mode;
    int logs_count;
    Log logs[MAX_LOGS_PER_DEVICE];
} DeviceControl;

typedef struct
{
    int devices_count;
    DeviceControl devices[MAX_DEVICES];
} DeviceControls;

typedef struct LCD_Display
{
    char name[MAX_NAME];
    int id;
    int room_id;
    DeviceType type;
    DeviceState state;
    DeviceControlState control_state;
    DeviceControlMode control_mode;
    UserControlState user_control_state;
    UserControlState user_control_mode;
    int logs_count;
    Log logs[MAX_LOGS_PER_DEVICE];
} LCD_Display;

typedef struct communicationInterface
{
    char name[MAX_NAME];
    int id;
    int room_id;
    DeviceType type;
    DeviceState state;
    DeviceControlState control_state;
    DeviceControlMode control_mode;
    UserControlState user_control_state;
    UserControlState user_control_mode;
    int logs_count;
    Log logs[MAX_LOGS_PER_DEVICE];
} CommunicationInterface;

void readFromDeviceControl(DeviceControl *device_control, float temperature, float humidity, float pressure);
void displayDeviceOutputs(DeviceControl *device_control, float temperature, float humidity, float pressure);
void updateDeviceControl(DeviceControl *device_control, float temperature, float humidity, float pressure);
void writeDeviceControlLogs(DeviceControl *device_control, float temperature, float humidity, float pressure);
void writeToLCD_Display(LCD_Display *lcd_display, float temperature, float humidity, float pressure);
void writeToCommunicationInterface(CommunicationInterface *communication_interface, float temperature, float humidity, float pressure);
void updateLCD_Display(LCD_Display *lcd_display, float temperature, float humidity, float pressure);
void updateCommunicationInterface(CommunicationInterface *communication_interface, float temperature, float humidity, float pressure);
void writeLCD_DisplayLogs(LCD_Display *lcd_display, float temperature, float humidity, float pressure);
void writeCommunicationInterfaceLogs(CommunicationInterface *communication_interface, float temperature, float humidity, float pressure);
void updateLCD_DisplayLogs(LCD_Display *lcd_display, float temperature, float humidity, float pressure);
void updateCommunicationInterfaceLogs(CommunicationInterface *communication_interface, float temperature, float humidity, float pressure);

int main(int argc, char **argv);

void readFromDeviceControl(DeviceControl *device_control, float temperature, float humidity, float pressure)
{
    if (device_control->control_mode == DEVICE_CONTROL_MODE_AUTO)
    {
        if (device_control->type == HEATER)
        {
            if (temperature < 20)
            {
                device_control->state = ON;
            }
            else
            {
                device_control->state = OFF;
            }
        }
        else if (device_control->type == COOLER)
        {
            if (temperature > 30)
            {
                device_control->state = ON;
            }
            else
            {
                device_control->state = OFF;
            }
        }
        else if (device_control->type == HUMIDIFIER)
        {
            if (humidity < 50)
            {
                device_control->state = ON;
            }
            else
            {
                device_control->state = OFF;
            }
        }
        else if (device_control->type == DEHUMIDIFIER)
        {
            if (humidity > 70)
            {
                device_control->state = ON;
            }
            else
            {
                device_control->state = OFF;
            }
        }
        else if (device_control->type == WINDOW)
        {
            if (temperature > 30)
            {
                device_control->state = ON;
            }
            else
            {
                device_control->state = OFF;
            }
        }
        else if (device_control->type == DOOR)
        {
            if (temperature < 20)
            {
                device_control->state = ON;
            }
            else
            {
                device_control->state = OFF;
            }
        }
        else if (device_control->type == LIGHT)
        {
            if (temperature < 20)
            {
                device_control->state = ON;
            }
            else
            {
                device_control->state = OFF;
            }
        }
        else if (device_control->type == BLIND)
        {
            if (temperature > 30)
            {
                device_control->state = ON;
            }
            else
            {
                device_control->state = OFF;
            }
        }
        else if (device_control->type == CURTAIN)
        {
            if (temperature < 20)
            {
                device_control->state = ON;
            }
            else
            {
                device_control->state = OFF;
            }
        }
        else if (device_control->type == FAN)
        {
            if (temperature > 30)
            {
                device_control->state = ON;
            }
            else
            {
                device_control->state = OFF;
            }
        }
    }
}

void displayDeviceOutputs(DeviceControl *device_control, float temperature, float humidity, float pressure)
{
    printf("Device Control: %s\n", device_control->name);
    printf("Device Control ID: %d\n", device_control->id);
    printf("Device Control Room ID: %d\n", device_control->room_id);
    printf("Device Control Type: %d\n", device_control->type);
    printf("Device Control State: %d\n", device_control->state);
    printf("Device Control Control State: %d\n", device_control->control_state);
    printf("Device Control Control Mode: %d\n", device_control->control_mode);
    printf("Device Control User Control State: %d\n", device_control->user_control_state);
    printf("Device Control User Control Mode: %d\n", device_control->user_control_mode);
    printf("Device Control Logs Count: %d\n", device_control->logs_count);
    for (int i = 0; i < device_control->logs_count; i++)
    {
        printf("Device Control Log: %d\n", i);
        printf("Device Control Log ID: %d\n", device_control->logs[i].id);
        printf("Device Control Log Device ID: %d\n", device_control->logs[i].device_id);
        printf("Device Control Log Device Type: %d\n", device_control->logs[i].device_type);
        printf("Device Control Log Device State: %d\n", device_control->logs[i].device_state);
        printf("Device Control Log Device Control State: %d\n", device_control->logs[i].device_control_state);
        printf("Device Control Log Device Control Mode: %d\n", device_control->logs[i].device_control_mode);
        printf("Device Control Log Device User Control State: %d\n", device_control->logs[i].device_user_control_state);
        printf("Device Control Log Device User Control Mode: %d\n", device_control->logs[i].device_user_control_mode);
        printf("Device Control Log Device Temperature: %f\n", device_control->logs[i].temperature);
        printf("Device Control Log Device Humidity: %f\n", device_control->logs[i].humidity);
        printf("Device Control Log Device Pressure: %f\n", device_control->logs[i].pressure);
    }
    printf("Device Control Logs:\n");
    for (int i = 0; i < device_control->logs_count; i++)
    {
        printf("Device Control Log: %");
    }
}
void updateDeviceControl(DeviceControl *device_control, float temperature, float humidity, float pressure)
{
    if (device_control->control_mode == AUTOMATIC)
    {
        if (device_control->type == HEATER)
        {
            if (temperature < 20)
            {
                device_control->state = ON;
            }
            else
            {
                device_control->state = OFF;
            }
        }
        else if (device_control->type == COOLER)
        {
            if (temperature > 30)
            {
                device_control->state = ON;
            }
            else
            {
                device_control->state = OFF;
            }
        }
        else if (device_control->type == HUMIDIFIER)
        {
            if (humidity < 50)
            {
                device_control->state = ON;
            }
            else
            {
                device_control->state = OFF;
            }
        }
        else if (device_control->type == DEHUMIDIFIER)
        {
            if (humidity > 70)
            {
                device_control->state = ON;
            }
            else
            {
                device_control->state = OFF;
            }
        }
        else if (device_control->type == WINDOW)
        {
            if (temperature > 30)
            {
                device_control->state = ON;
            }
            else
            {
                device_control->state = OFF;
            }
        }
        else if (device_control->type == DOOR)
        {
            if (temperature < 20)
            {
                device_control->state = ON;
            }
            else
            {
                device_control->state = OFF;
            }
        }
        else if (device_control->type == LIGHT)
        {
            if (temperature < 20)
            {
                device_control->state = ON;
            }
            else
            {
                device_control->state = OFF;
            }
        }
        else if (device_control->type == BLIND)
        {
            if (temperature > 30)
            {
                device_control->state = ON;
            }
            else
            {
                device_control->state = OFF;
            }
        }
        else if (device_control->type == CURTAIN)
        {
            if (temperature < 20)
            {
                device_control->state = ON;
            }
            else
            {
                device_control->state = OFF;
            }
        }
        else if (device_control->type == FAN)
        {
            if (temperature > 30)
            {
                device_control->state = ON;
            }
            else
            {
                device_control->state = OFF;
            }
        }
    }
}
void writeDeviceControlLogs(DeviceControl *device_control, float temperature, float humidity, float pressure)
{
    if (device_control->logs_count < 100)
    {
        device_control->logs[device_control->logs_count].id = device_control->logs_count;
        device_control->logs[device_control->logs_count].device_id = device_control->id;
        device_control->logs[device_control->logs_count].device_type = device_control->type;
        device_control->logs[device_control->logs_count].device_state = device_control->state;
        device_control->logs[device_control->logs_count].device_control_state = device_control->control_state;
        device_control->logs[device_control->logs_count].device_control_mode = device_control->control_mode;
        device_control->logs[device_control->logs_count].device_user_control_state = device_control->user_control_state;
        device_control->logs[device_control->logs_count].device_user_control_mode = device_control->user_control_mode;
        device_control->logs[device_control->logs_count].temperature = temperature;
        device_control->logs[device_control->logs_count].humidity = humidity;
        device_control->logs[device_control->logs_count].pressure = pressure;
        device_control->logs_count++;
    }
    else
    {
        for (int i = 0; i < 99; i++)
        {
            device_control->logs[i] = device_control->logs[i + 1];
        }
        device_control->logs[99].id = device_control->logs_count;
        device_control->logs[99].device_id = device_control->id;
        device_control->logs[99].device_type = device_control->type;
        device_control->logs[99].device_state = device_control->state;
        device_control->logs[99].device_control_state = device_control->control_state;
        device_control->logs[99].device_control_mode = device_control->control_mode;
        device_control->logs[99].device_user_control_state = device_control->user_control_state;
        device_control->logs[99].device_user_control_mode = device_control->user_control_mode;
        device_control->logs[99].temperature = temperature;
        device_control->logs[99].humidity = humidity;
        device_control->logs[99].pressure = pressure;
    }
}
void writeToLCD_Display(LCD_Display *lcd_display, float temperature, float humidity, float pressure)
{
    if (lcd_display->logs_count < 100)
    {
        lcd_display->logs[lcd_display->logs_count].id = lcd_display->logs_count;
        lcd_display->logs[lcd_display->logs_count].temperature = temperature;
        lcd_display->logs[lcd_display->logs_count].humidity = humidity;
        lcd_display->logs[lcd_display->logs_count].pressure = pressure;
        lcd_display->logs_count++;
    }
    else
    {
        for (int i = 0; i < 99; i++)
        {
            lcd_display->logs[i] = lcd_display->logs[i + 1];
        }
        lcd_display->logs[99].id = lcd_display->logs_count;
        lcd_display->logs[99].temperature = temperature;
        lcd_display->logs[99].humidity = humidity;
        lcd_display->logs[99].pressure = pressure;
    }
}
void writeToCommunicationInterface(CommunicationInterface *communication_interface, float temperature, float humidity, float pressure)
{
    if (communication_interface->logs_count < 100)
    {
        communication_interface->logs[communication_interface->logs_count].id = communication_interface->logs_count;
        communication_interface->logs[communication_interface->logs_count].temperature = temperature;
        communication_interface->logs[communication_interface->logs_count].humidity = humidity;
        communication_interface->logs[communication_interface->logs_count].pressure = pressure;
        communication_interface->logs_count++;
    }
    else
    {
        for (int i = 0; i < 99; i++)
        {
            communication_interface->logs[i] = communication_interface->logs[i + 1];
        }
        communication_interface->logs[99].id = communication_interface->logs_count;
        communication_interface->logs[99].temperature = temperature;
        communication_interface->logs[99].humidity = humidity;
        communication_interface->logs[99].pressure = pressure;
    }
}
void updateLCD_Display(LCD_Display *lcd_display, float temperature, float humidity, float pressure)
{
    if (lcd_display->logs_count < 100)
    {
        lcd_display->logs[lcd_display->logs_count].id = lcd_display->logs_count;
        lcd_display->logs[lcd_display->logs_count].temperature = temperature;
        lcd_display->logs[lcd_display->logs_count].humidity = humidity;
        lcd_display->logs[lcd_display->logs_count].pressure = pressure;
        lcd_display->logs_count++;
    }
    else
    {
        for (int i = 0; i < 99; i++)
        {
            lcd_display->logs[i] = lcd_display->logs[i + 1];
        }
        lcd_display->logs[99].id = lcd_display->logs_count;
        lcd_display->logs[99].temperature = temperature;
        lcd_display->logs[99].humidity = humidity;
        lcd_display->logs[99].pressure = pressure;
    }
}
void updateCommunicationInterface(CommunicationInterface *communication_interface, float temperature, float humidity, float pressure)
{
    if (communication_interface->logs_count < 100)
    {
        communication_interface->logs[communication_interface->logs_count].id = communication_interface->logs_count;
        communication_interface->logs[communication_interface->logs_count].temperature = temperature;
        communication_interface->logs[communication_interface->logs_count].humidity = humidity;
        communication_interface->logs[communication_interface->logs_count].pressure = pressure;
        communication_interface->logs_count++;
    }
    else
    {
        for (int i = 0; i < 99; i++)
        {
            communication_interface->logs[i] = communication_interface->logs[i + 1];
        }
        communication_interface->logs[99].id = communication_interface->logs_count;
        communication_interface->logs[99].temperature = temperature;
        communication_interface->logs[99].humidity = humidity;
        communication_interface->logs[99].pressure = pressure;
    }
}
void writeLCD_DisplayLogs(LCD_Display *lcd_display, float temperature, float humidity, float pressure)
{
    if (lcd_display->logs_count < 100)
    {
        lcd_display->logs[lcd_display->logs_count].id = lcd_display->logs_count;
        lcd_display->logs[lcd_display->logs_count].temperature = temperature;
        lcd_display->logs[lcd_display->logs_count].humidity = humidity;
        lcd_display->logs[lcd_display->logs_count].pressure = pressure;
        lcd_display->logs_count++;
    }
    else
    {
        for (int i = 0; i < 99; i++)
        {
            lcd_display->logs[i] = lcd_display->logs[i + 1];
        }
        lcd_display->logs[99].id = lcd_display->logs_count;
        lcd_display->logs[99].temperature = temperature;
        lcd_display->logs[99].humidity = humidity;
        lcd_display->logs[99].pressure = pressure;
    }
}
void writeCommunicationInterfaceLogs(CommunicationInterface *communication_interface, float temperature, float humidity, float pressure)
{
    if (communication_interface->logs_count < 100)
    {
        communication_interface->logs[communication_interface->logs_count].id = communication_interface->logs_count;
        communication_interface->logs[communication_interface->logs_count].temperature = temperature;
        communication_interface->logs[communication_interface->logs_count].humidity = humidity;
        communication_interface->logs[communication_interface->logs_count].pressure = pressure;
        communication_interface->logs_count++;
    }
    else
    {
        for (int i = 0; i < 99; i++)
        {
            communication_interface->logs[i] = communication_interface->logs[i + 1];
        }
        communication_interface->logs[99].id = communication_interface->logs_count;
        communication_interface->logs[99].temperature = temperature;
        communication_interface->logs[99].humidity = humidity;
        communication_interface->logs[99].pressure = pressure;
    }
}
void updateLCD_DisplayLogs(LCD_Display *lcd_display, float temperature, float humidity, float pressure)
{
    if (lcd_display->logs_count < 100)
    {
        lcd_display->logs[lcd_display->logs_count].id = lcd_display->logs_count;
        lcd_display->logs[lcd_display->logs_count].temperature = temperature;
        lcd_display->logs[lcd_display->logs_count].humidity = humidity;
        lcd_display->logs[lcd_display->logs_count].pressure = pressure;
        lcd_display->logs_count++;
    }
    else
    {
        for (int i = 0; i < 99; i++)
        {
            lcd_display->logs[i] = lcd_display->logs[i + 1];
        }
        lcd_display->logs[99].id = lcd_display->logs_count;
        lcd_display->logs[99].temperature = temperature;
        lcd_display->logs[99].humidity = humidity;
        lcd_display->logs[99].pressure = pressure;
    }
}
void updateCommunicationInterfaceLogs(CommunicationInterface *communication_interface, float temperature, float humidity, float pressure)
{
    if (communication_interface->logs_count < 100)
    {
        communication_interface->logs[communication_interface->logs_count].id = communication_interface->logs_count;
        communication_interface->logs[communication_interface->logs_count].temperature = temperature;
        communication_interface->logs[communication_interface->logs_count].humidity = humidity;
        communication_interface->logs[communication_interface->logs_count].pressure = pressure;
        communication_interface->logs_count++;
    }
    else
    {
        for (int i = 0; i < 99; i++)
        {
            communication_interface->logs[i] = communication_interface->logs[i + 1];
        }
        communication_interface->logs[99].id = communication_interface->logs_count;
        communication_interface->logs[99].temperature = temperature;
        communication_interface->logs[99].humidity = humidity;
        communication_interface->logs[99].pressure = pressure;
    }
}

int main(int argc, char **argv)
{
    LCD_Display lcd_display;
    CommunicationInterface communication_interface;
    lcd_display.logs_count = 0;
    communication_interface.logs_count = 0;
    float temperature = 0;
    float humidity = 0;
    float pressure = 0;
    for (int i = 0; i < 100; i++)
    {
        temperature = (float)rand() / (float)(RAND_MAX / 100);
        humidity = (float)rand() / (float)(RAND_MAX / 100);
        pressure = (float)rand() / (float)(RAND_MAX / 100);
        writeLCD_DisplayLogs(&lcd_display, temperature, humidity, pressure);
        writeCommunicationInterfaceLogs(&communication_interface, temperature, humidity, pressure);
        printf("LCD Display Logs: %d, %f, %f, %f\n", lcd_display.logs[i].id, lcd_display.logs[i].temperature, lcd_display.logs[i].humidity, lcd_display.logs[i].pressure);
    }
    for (int i = 0; i < 100; i++)
    {
        temperature = (float)rand() / (float)(RAND_MAX / 100);
        humidity = (float)rand() / (float)(RAND_MAX / 100);
        pressure = (float)rand() / (float)(RAND_MAX / 100);
        updateLCD_DisplayLogs(&lcd_display, temperature, humidity, pressure);
        updateCommunicationInterfaceLogs(&communication_interface, temperature, humidity, pressure);
        printf("Communication Interface Logs: %d, %f, %f, %f\n", communication_interface.logs[i].id, communication_interface.logs[i].temperature, communication_interface.logs[i].humidity, communication_interface.logs[i].pressure);
    }
    return 0;
}