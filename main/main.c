#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "mt6835.h"
#include "initGPIO.h"
#include "initTimers.h"
#include "initSPI.h"

spi_device_handle_t mt6835;

void app_main(void) {
    ESP_ERROR_CHECK(initGPIO());
    //ESP_ERROR_CHECK(initTimers());
    ESP_ERROR_CHECK(initSPI());

    uint8_t num = 0;
    
    while (1) {
        mt6835_set_user_id(&mt6835, num);
        mt6835_get_user_id(&mt6835, &num);
        num++;
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}