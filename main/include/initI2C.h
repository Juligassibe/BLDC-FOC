#ifndef INITI2C_H
#define INITI2C_H

#include "driver/i2c_master.h"
#include "driver/gpio.h"
#include "esp_err.h"

#define SCL GPIO_NUM_26
#define SDA GPIO_NUM_27

extern i2c_master_bus_handle_t busI2C;
extern i2c_master_dev_handle_t ina3221;

esp_err_t initI2C();

#endif