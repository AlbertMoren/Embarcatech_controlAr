#ifndef DISPLAY_H
#define DISPLAY_H

#include <stdint.h>

// Estrutura para representar o display
typedef struct {
    void (*limpar_tela)(); // Ponteiro para função que limpa a tela do display
    void (*imprimir_tela)(char *msg[]); // Ponteiro para função que imprime uma mensagem na tela do display
} Display;

/**
 * @brief Inicializa a estrutura Display.
 * 
 * Esta função configura os ponteiros de função para as operações do display,
 * como limpar a tela e imprimir mensagens.
 * 
 * @param display Ponteiro para a estrutura Display que será inicializada.
 */
void display_init(Display *display);

#endif // DISPLAY_H