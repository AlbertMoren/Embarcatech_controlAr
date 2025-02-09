#include "botao.h"
#include "../config.h" 

static void configurar_botao(Botao *botao) {
    gpio_init(botao->pino);
    gpio_set_dir(botao->pino, GPIO_IN);
    gpio_pull_up(botao->pino);
}

void botao_init(Botao *botao, uint pino) {
    botao->pino = pino;
    botao->pressionado = false;
    botao->configurar = configurar_botao;
}