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

    uint16_t config = CH1_EN | AVG_4_SAMPLE | SHUNT_CT_1MS | MODE_SHUNT_CONT;
    
    ina3221_set_config(&ina3221, config);

    int16_t ch1Shunt = 0;

    ina3221_get_ch1_shunt(&ina3221, &ch1Shunt);

    printf("Voltaje shunt: %f\n", ch1Shunt*0.000040);
    printf("Corriente: %f\n", ch1Shunt*0.000040 / 0.1);
}