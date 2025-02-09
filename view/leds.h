#ifndef LED_H
#define LED_H

#include <stdint.h>

// Estrutura para representar um LED
typedef struct {
    void (*ligar)(int vermelho, int azul); // Ponteiro para função que liga o LED com intensidades específicas para vermelho e azul
    void (*init)(); // Ponteiro para função que inicializa o LED
} LED;

/**
 * @brief Inicializa a estrutura LED.
 * 
 * Esta função configura os ponteiros de função para as operações do LED,
 * como inicialização e controle das cores.
 * 
 * @param led Ponteiro para a estrutura LED que será inicializada.
 */
void led_init(LED *led);

#endif // LED_H
