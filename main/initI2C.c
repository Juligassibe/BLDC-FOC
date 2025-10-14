#include "initI2C.h"

esp_err_t initI2C() {
    i2c_master_bus_config_t busConfig = {
        .i2c_port = 1,
        .sda_io_num = SDA,
        .scl_io_num = SCL,
        .clk_source = I2C_CLK_SRC_DEFAULT,
        .glitch_ignore_cnt = 7,
        .flags.enable_internal_pullup = true
    };

    ESP_ERROR_CHECK(i2c_new_master_bus(&busConfig, &busI2C));

    i2c_device_config_t config = {
        .dev_addr_length = I2C_ADDR_BIT_LEN_7,
        .device_address = 0b1000000,
        .scl_speed_hz = 400000
    };

    ESP_ERROR_CHECK(i2c_master_bus_add_device(busI2C, &config, &ina3221));

    return ESP_OK;
}