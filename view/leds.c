#include "leds.h"
#include <hardware/gpio.h>
#include "../config.h"

void ligar_leds(int vermelho, int azul) {
    gpio_put(LED_VERMELHO, vermelho);
    gpio_put(LED_AZUL, azul);
}

void init_led() {
    gpio_init(LED_VERMELHO);
    gpio_set_dir(LED_VERMELHO, GPIO_OUT);
    gpio_init(LED_AZUL);
    gpio_set_dir(LED_AZUL, GPIO_OUT);
}

void led_init(LED *led) {
    led->ligar = ligar_leds;
    led->init = init_led; 
}