#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "mt6835.h"
#include "ina3221.h"
#include "initGPIO.h"
#include "initTimers.h"
#include "initSPI.h"
#include "initI2C.h"
#include "esp_timer.h"

spi_device_handle_t mt6835;
i2c_master_bus_handle_t busI2C;
i2c_master_dev_handle_t ina3221;

void app_main(void) {
    ESP_ERROR_CHECK(initGPIO());
    //ESP_ERROR_CHECK(initTimers());
    //ESP_ERROR_CHECK(initSPI());
    ESP_ERROR_CHECK(initI2C());

    uint16_t config = CH1_EN | CH2_EN | CH3_EN | AVG_1_SAMPLE | SHUNT_CT_140US | MODE_SHUNT_CONT;

    printf("Config %d\n", config);

    ina3221_set_config(&ina3221, config);

    int16_t shunt1 = 0, shunt2 = 0, shunt3 = 0;

    uint64_t inicio = esp_timer_get_time();

    ina3221_get_ch1_shunt(&ina3221, &shunt1);
    ina3221_get_ch2_shunt(&ina3221, &shunt2);
    ina3221_get_ch3_shunt(&ina3221, &shunt3);

    uint64_t fin = esp_timer_get_time();

    printf("Demora: %lld\n", fin-inicio);
}