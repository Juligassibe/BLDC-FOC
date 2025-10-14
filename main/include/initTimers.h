#ifndef INITTIMERS_H
#define INITTIMERS_H

#include "driver/gptimer.h"
#include "esp_err.h"
#include "esp_attr.h"
#include "initGPIO.h"

extern gptimer_handle_t timerPulsos;

esp_err_t initTimers();
bool IRAM_ATTR isrPulsos(gptimer_handle_t timer, const gptimer_alarm_event_data_t *edata, void *user_ctx);


#endif