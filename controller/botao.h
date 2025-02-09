#ifndef BOTAO_H
#define BOTAO_H

#include <stdint.h>
#include <stdbool.h>
#include <hardware/gpio.h>
#include <pico/stdlib.h>
#include "../config.h"

// Estrutura para representar um botão
typedef struct {
    uint pino; // Pino do botão (número do pino GPIO)
    bool pressionado; // Estado do botão (true se pressionado, false caso contrário)
    void (*configurar)(); // Ponteiro para função que configura o pino do botão
} Botao;

// Protótipos das funções

/**
 * @brief Inicializa um botão.
 * 
 * Esta função configura o pino do botão como entrada e inicializa o estado do botão.
 * 
 * @param botao Ponteiro para a estrutura Botao que representa o botão.
 * @param pino Número do pino GPIO onde o botão está conectado.
 */
void botao_init(Botao *botao, uint pino);

#endif // BOTAO_H