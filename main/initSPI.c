#include "initSPI.h"

esp_err_t initSPI() {
    spi_bus_config_t spiConfig = {
        .mosi_io_num = MOSI,
        .miso_io_num = MISO,
        .sclk_io_num = SCLK,
        .quadhd_io_num = -1,
        .quadwp_io_num = -1,
        .max_transfer_sz = 24
    };

    ESP_ERROR_CHECK(spi_bus_initialize(SPI3_HOST, &spiConfig, SPI_DMA_CH_AUTO));

    spi_device_interface_config_t mt6835Config = {
        .clock_speed_hz = 100000, // 1MHz, 16MHz max
        .duty_cycle_pos = 128,
        .mode = 3, // CLK high en idle
        .spics_io_num = MT6835_CS,
        .queue_size = 1,
        .command_bits = 4, // Solo 4bits de comando
        .address_bits = 12, // Solo 12bits de direccion
    };

    ESP_ERROR_CHECK(spi_bus_add_device(SPI3_HOST, &mt6835Config, &mt6835));

    return ESP_OK;
}

