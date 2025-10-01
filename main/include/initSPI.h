#include "driver/spi_master.h"
#include "driver/gpio.h"
#include "esp_err.h"

#define MISO            GPIO_NUM_19
#define MOSI            GPIO_NUM_23
#define SCLK            GPIO_NUM_18
#define MT6835_CS       GPIO_NUM_25

extern spi_device_handle_t mt6835;

esp_err_t initSPI();




