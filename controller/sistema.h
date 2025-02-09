#ifndef SISTEMA_H
#define SISTEMA_H

#include <stdint.h>
#include <stdbool.h>
#include "view/display.h"
#include "model/buzzer.h"
#include "view/leds.h"

// Estrutura que representa o sistema
typedef struct {
    Display display; // Componente de display do sistema
    Buzzer buzzer; // Componente de buzzer do sistema
    LED led; // Componente de LED do sistema
    int contador_pessoas; // Contador de pessoas no ambiente
    bool ac_ligado; // Estado do ar-condicionado (true se ligado, false se desligado)
    int temperatura; // Temperatura atual do ambiente
} Sistema;

// Protótipos das funções

/**
 * @brief Inicializa o sistema.
 * 
 * Esta função inicializa todos os componentes do sistema, como display, buzzer, LED,
 * e define os valores iniciais para o contador de pessoas, estado do ar-condicionado e temperatura.
 * 
 * @param sistema Ponteiro para a estrutura Sistema que representa o sistema.
 */
void sistema_init(Sistema *sistema);

/**
 * @brief Registra a entrada de uma pessoa no ambiente.
 * 
 * Incrementa o contador de pessoas e atualiza o estado do sistema, se necessário.
 * 
 * @param sistema Ponteiro para a estrutura Sistema que representa o sistema.
 */
void sistema_entrada_pessoa(Sistema *sistema);

/**
 * @brief Registra a saída de uma pessoa do ambiente.
 * 
 * Decrementa o contador de pessoas e atualiza o estado do sistema, se necessário.
 * 
 * @param sistema Ponteiro para a estrutura Sistema que representa o sistema.
 */
void sistema_saida_pessoa(Sistema *sistema);

/**
 * @brief Atualiza o display do sistema.
 * 
 * Exibe informações atualizadas, como o número de pessoas, estado do ar-condicionado e temperatura.
 * 
 * @param sistema Ponteiro para a estrutura Sistema que representa o sistema.
 */
void sistema_atualizar_display(Sistema *sistema);

/**
 * @brief Liga o ar-condicionado.
 * 
 * Altera o estado do ar-condicionado para ligado e atualiza o sistema.
 * 
 * @param sistema Ponteiro para a estrutura Sistema que representa o sistema.
 */
void sistema_ligar_ac(Sistema *sistema);

/**
 * @brief Desliga o ar-condicionado.
 * 
 * Altera o estado do ar-condicionado para desligado e atualiza o sistema.
 * 
 * @param sistema Ponteiro para a estrutura Sistema que representa o sistema.
 */
void sistema_desligar_ac(Sistema *sistema);

/**
 * @brief Verifica a temperatura do ambiente.
 * 
 * Verifica a temperatura atual e toma ações com base nela, como ligar ou desligar o ar-condicionado.
 * 
 * @param sistema Ponteiro para a estrutura Sistema que representa o sistema.
 */
void sistema_verificar_temperatura(Sistema *sistema);

#endif 