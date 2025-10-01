#include "initGPIO.h"

esp_err_t initGPIO() {
    gpio_config_t outputs = {
        .pin_bit_mask = ((uint64_t)1 << STEP),
        .mode = GPIO_MODE_OUTPUT,
        .pull_down_en = GPIO_PULLDOWN_ENABLE,
        .pull_up_en = GPIO_PULLUP_DISABLE,
        .intr_type = GPIO_INTR_DISABLE
    };

    ESP_ERROR_CHECK(gpio_config(&outputs));

    return ESP_OK;
}