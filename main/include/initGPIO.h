#ifndef INITGPIO_H
#define INITGPIO_H

#include "driver/gpio.h"
#include "esp_err.h"

#define STEP GPIO_NUM_21

esp_err_t initGPIO();

#endif