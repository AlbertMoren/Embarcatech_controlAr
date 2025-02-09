#include "sistema.h"
#include <stdio.h>
#include <pico/stdlib.h>
#include <hardware/gpio.h>
#include <pico/time.h>
#include "view/pixel.h"

void sistema_init(Sistema *sistema) {
    display_init(&sistema->display);
    buzzer_init(&sistema->buzzer);
    led_init(&sistema->led);
    sistema->contador_pessoas = 0;
    sistema->ac_ligado = false;
    sistema->temperatura = 24;
    sistema->buzzer.init();
    sistema->led.init();
}

void sistema_atualizar_display(Sistema *sistema) {
    sistema_verificar_temperatura(sistema);
    char temperatura_str[20];
    char quant_pessoas_str[20];
    sprintf(temperatura_str, "%d", sistema->temperatura);
    sprintf(quant_pessoas_str, "%d", sistema->contador_pessoas);
    char *text[] = {"ac_ligado", "temp:", temperatura_str, "C", "Pessoas", quant_pessoas_str};
    sistema->display.limpar_tela();
    sistema->display.imprimir_tela(text);
}

void sistema_ligar_ac(Sistema *sistema) {
    sistema->led.ligar(1, 0);
    sistema->ac_ligado = true;
    sistema_atualizar_display(sistema);
    sistema->buzzer.beep();
}

void sistema_desligar_ac(Sistema *sistema) {
    sistema->led.ligar(0, 1);
    absolute_time_t tempo_inicial = get_absolute_time();
    while (absolute_time_diff_us(tempo_inicial, get_absolute_time()) < 5000000) {
        tight_loop_contents();
    }
    sistema->ac_ligado = false;
    sistema->led.ligar(0, 0);
    sistema->display.limpar_tela();
}

void sistema_entrada_pessoa(Sistema *sistema) {
    sistema->contador_pessoas++;
    if (!sistema->ac_ligado) {
        sistema_ligar_ac(sistema);
    }
    sistema_atualizar_display(sistema);
}

void sistema_saida_pessoa(Sistema *sistema) {
    if (sistema->contador_pessoas > 0) {
        sistema->contador_pessoas--;
        sistema_atualizar_display(sistema);
        if (sistema->contador_pessoas == 0) {
            sistema_desligar_ac(sistema);
        }
    }
}

void sistema_verificar_temperatura(Sistema *sistema) {
    int last_temp = sistema->temperatura;
    if (sistema->contador_pessoas == 1 || sistema->contador_pessoas == 2 || sistema->contador_pessoas == 0) {
        sistema->temperatura = 24;
    } else if (sistema->contador_pessoas >= 3 && sistema->contador_pessoas <= 5) {
        sistema->temperatura = 22;
    } else {
        sistema->temperatura = 20;
    }
    if (sistema->temperatura > last_temp){
        print_Up();
    }
    else if (sistema->temperatura < last_temp){
        print_down();
    }
}