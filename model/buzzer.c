#include "buzzer.h"
#include <stdint.h>
#include <hardware/pwm.h>
#include <pico/time.h>
#include "hardware/pwm.h"
#include "hardware/clocks.h"
#include "../config.h" 
#include "hardware/gpio.h" 

static void beep() {
    uint slice_num = pwm_gpio_to_slice_num(BUZZER_PIN);
    pwm_set_gpio_level(BUZZER_PIN, 2048); 
    sleep_ms(1000); 
    pwm_set_gpio_level(BUZZER_PIN, 0); 
    sleep_ms(100); 
}

static void init_impl() {
    gpio_set_function(BUZZER_PIN, GPIO_FUNC_PWM);
    uint slice_num = pwm_gpio_to_slice_num(BUZZER_PIN);
    pwm_config config = pwm_get_default_config();
    pwm_config_set_clkdiv(&config, clock_get_hz(clk_sys) / (BUZZER_FREQUENCY * 4096));
    pwm_init(slice_num, &config, true);
    pwm_set_gpio_level(BUZZER_PIN, 0);
}

void buzzer_init(Buzzer *buzzer) {
    buzzer->beep = beep;
    buzzer->init = init_impl;
}