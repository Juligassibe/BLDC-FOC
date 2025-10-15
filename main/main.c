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

    uint16_t config = CH1_EN | CH2_EN | CH3_EN | AVG_4_SAMPLE | BUS_CT_1MS | SHUNT_CT_1MS | MODE_SHUNT_CONT | MODE_BUS_CONT;
    
    ina3221_set_config(&ina3221, config);

    int16_t shunt1 = 0, bus1 = 0, shunt2 = 0, bus2 = 0, shunt3 = 0, bus3 = 0;

    ina3221_get_ch1_shunt(&ina3221, &shunt1);
    ina3221_get_ch1_bus(&ina3221, &bus1);
    ina3221_get_ch2_shunt(&ina3221, &shunt2);
    ina3221_get_ch2_bus(&ina3221, &bus2);
    ina3221_get_ch3_shunt(&ina3221, &shunt3);
    ina3221_get_ch3_bus(&ina3221, &bus3);

    printf("Corriente 1: %f\n", shunt1*0.000040 / 0.01);
    printf("Bus 1: %f\n", bus1*0.008);
    printf("Corriente 2: %f\n", shunt2*0.000040 / 0.01);
    printf("Bus 2: %f\n", bus2*0.008);
    printf("Corriente 3: %f\n", shunt3*0.000040 / 0.01);
    printf("Bus 3: %f\n", bus3*0.008);
}