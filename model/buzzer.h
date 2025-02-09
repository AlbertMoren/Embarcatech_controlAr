#ifndef BUZZER_H
#define BUZZER_H

// Estrutura para representar o buzzer
typedef struct {
    void (*beep)(); // Ponteiro para função que emite um beep (som curto)
    void (*init)(); // Ponteiro para função que inicializa o buzzer
} Buzzer;

/**
 * @brief Inicializa a estrutura Buzzer.
 * 
 * Esta função configura os ponteiros de função para as operações do buzzer,
 * como emitir um beep e inicializar o hardware do buzzer.
 * 
 * @param buzzer Ponteiro para a estrutura Buzzer que será inicializada.
 */
void buzzer_init(Buzzer *buzzer);

#endif // BUZZER_H