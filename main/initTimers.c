#include "initTimers.h"

gptimer_handle_t timerPulsos;

esp_err_t initTimers() {
    gptimer_config_t config = {
        .clk_src = GPTIMER_CLK_SRC_DEFAULT,
        .direction = GPTIMER_COUNT_UP,
        .resolution_hz = 1000000,
        .intr_priority = 0
    };

    ESP_ERROR_CHECK(gptimer_new_timer(&config, &timerPulsos));

    gptimer_alarm_config_t config_top = {
        // El timer contara hasta 1000000
        .alarm_count = 1000000 / 384,
        // Al llegar a 1000000, se reseteara a 0 en este caso
        .reload_count = 0,
        // El timer contara de 0 a 1000000 en bucle, es decir, no sera one-shot
        .flags.auto_reload_on_alarm = true
    };

    ESP_ERROR_CHECK(gptimer_set_alarm_action(timerPulsos, &config_top));

    gptimer_event_callbacks_t callback_timer = {
        // Registro funcion que hara de ISR cuando timer1 llegue al top
        .on_alarm = isrPulsos
    };

    ESP_ERROR_CHECK(gptimer_register_event_callbacks(timerPulsos, &callback_timer, NULL));

    // No es necesario tener en cuenta el desborde ya que el timer es de 64 bits, por lo que contando a 1 MHz se podria contar por 500mil anos sin parar xd
    ESP_ERROR_CHECK(gptimer_enable(timerPulsos));
    ESP_ERROR_CHECK(gptimer_start(timerPulsos));

    return ESP_OK;
}

bool IRAM_ATTR isrPulsos(gptimer_handle_t timer, const gptimer_alarm_event_data_t *edata, void *user_ctx) {
    gpio_set_level(STEP, 1);
    gpio_set_level(STEP, 0);

    return true;
}



