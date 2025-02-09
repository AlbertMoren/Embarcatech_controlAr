#ifndef PIXEL_H
#define PIXEL_H

#include "../config.h"
#include <stdint.h>
#include "hardware/pio.h"

/**
 * @brief Estrutura para representar um pixel no formato GRB.
 * 
 * Cada pixel é definido por três componentes de cor:
 * - G (Green - Verde)
 * - R (Red - Vermelho)
 * - B (Blue - Azul)
 */
typedef struct {
    uint8_t G; ///< Intensidade da cor verde
    uint8_t R; ///< Intensidade da cor vermelha
    uint8_t B; ///< Intensidade da cor azul
} pixel_t;

// Definição de um alias para a estrutura pixel_t
typedef pixel_t npLED_t;

// Declaração de variáveis globais para o controle dos LEDs
extern npLED_t leds[LED_COUNT]; ///< Array que armazena os estados dos LEDs
extern PIO np_pio; ///< Instância do PIO usada para controle dos LEDs
extern uint sm; ///< Número do state machine do PIO

/**
 * @brief Inicializa os LEDs no pino especificado.
 * 
 * Configura a comunicação com os LEDs e inicializa os registradores necessários.
 * 
 * @param pin Número do pino onde os LEDs estão conectados.
 */
void npInit(uint pin);

/**
 * @brief Define a cor de um LED específico.
 * 
 * Atualiza a cor do LED na posição especificada usando valores RGB.
 * 
 * @param index Índice do LED na matriz.
 * @param r Valor de intensidade do vermelho (0-255).
 * @param g Valor de intensidade do verde (0-255).
 * @param b Valor de intensidade do azul (0-255).
 */
void npSetLED(const uint index, const uint8_t r, const uint8_t g, const uint8_t b);

/**
 * @brief Limpa todos os LEDs, apagando suas cores.
 */
void npClear();

/**
 * @brief Atualiza os LEDs, enviando os dados armazenados para o hardware.
 */
void npWrite();

/**
 * @brief Converte coordenadas (x, y) para o índice correspondente no array de LEDs.
 * 
 * @param x Posição X na matriz de LEDs.
 * @param y Posição Y na matriz de LEDs.
 * @return Índice correspondente no array de LEDs.
 */
int getIndex(int x, int y);

/**
 * @brief Exibe uma animação ou padrão específico na direção superior.
 */
void print_Up();

/**
 * @brief Exibe uma animação ou padrão específico na direção inferior.
 */
void print_down();

/**
 * @brief Exibe um padrão de corrida ou sprint nos LEDs.
 */
void print_sprint();

#endif // PIXEL_H
