#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "mt6835.h"
#include "ina3221.h"
#include "initGPIO.h"
#include "initTimers.h"
#include "initSPI.h"
#include "initI2C.h"

spi_device_handle_t mt6835;
i2c_master_bus_handle_t busI2C;
i2c_master_dev_handle_t ina3221;

void app_main(void) {
    ESP_ERROR_CHECK(initGPIO());
    //ESP_ERROR_CHECK(initTimers());
    ESP_ERROR_CHECK(initSPI());
    ESP_ERROR_CHECK(initI2C());

    uint16_t config = 0;
    
    ina3221_get_config(&ina3221, &config);

    printf("Config: %d\n", config);
}