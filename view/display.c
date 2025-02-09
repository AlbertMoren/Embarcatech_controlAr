#include "display.h"
#include "../inc/ssd1306.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "pico/stdlib.h"
#include "pico/binary_info.h"
#include "hardware/i2c.h"
#include "../config.h"

void limpar_tela() {
    struct render_area frame_area = {
        .start_column = 0,
        .end_column = 127, 
        .start_page = 0,
        .end_page = 7      
    };

    uint8_t ssd[ssd1306_buffer_length];
    memset(ssd, 0, ssd1306_buffer_length);

    render_on_display(ssd, &frame_area);
    ssd1306_send_buffer(ssd, ssd1306_buffer_length);
}

void imprimir_tela(char *msg[]) {
    struct render_area frame_area = {
        .start_column = 0,
        .end_column = ssd1306_width - 1,
        .start_page = 0,
        .end_page = ssd1306_n_pages - 1
    };

    calculate_render_area_buffer_length(&frame_area);

    uint8_t ssd[ssd1306_buffer_length];
    memset(ssd, 0, ssd1306_buffer_length);
    render_on_display(ssd, &frame_area);

    int x_positions[] = {25, 10, 74, 92, 10, 74};
    int y_positions[] = {0, 16, 16, 16, 32, 32};

    for (uint i = 0; i < 6; i++) {
        ssd1306_draw_string(ssd, x_positions[i], y_positions[i], msg[i]);
    }

    render_on_display(ssd, &frame_area);
}

void display_init(Display *display) {
    i2c_init(i2c1, ssd1306_i2c_clock * 1000);
    gpio_set_function(I2C_SDA, GPIO_FUNC_I2C);
    gpio_set_function(I2C_SCL, GPIO_FUNC_I2C);
    gpio_pull_up(I2C_SDA);
    gpio_pull_up(I2C_SCL);
    ssd1306_init();
    display->limpar_tela = limpar_tela;
    display->imprimir_tela = imprimir_tela;
}