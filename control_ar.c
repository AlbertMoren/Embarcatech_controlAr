#include <stdio.h>
#include <pico/stdlib.h>
#include <hardware/gpio.h>
#include <pico/time.h>
#include "controller/sistema.h"
#include "controller/botao.h"
#include "config.h"
#include "view/pixel.h"

// Instâncias globais do sistema e dos botões
Sistema sistema; ///< Estrutura que gerencia o sistema principal
Botao botao_a;  ///< Estrutura para representar o botão A
Botao botao_b;  ///< Estrutura para representar o botão B

/**
 * @brief Função de interrupção para os botões.
 * 
 * Essa função é chamada automaticamente quando um dos botões é pressionado.
 * Ela verifica qual botão gerou a interrupção e atualiza seu estado.
 * 
 * @param gpio Número do pino GPIO que gerou a interrupção.
 * @param events Evento de interrupção ocorrido (exemplo: borda de descida).
 */
void interrupcao_botao(uint gpio, uint32_t events) {
    if (events & GPIO_IRQ_EDGE_FALL) { // Verifica se foi uma interrupção na borda de descida
        if (gpio == BOTAO_A) {
            botao_a.pressionado = true; // Marca o botão A como pressionado
        } else if (gpio == BOTAO_B) {
            botao_b.pressionado = true; // Marca o botão B como pressionado
        }
    }
}

/**
 * @brief Função principal do programa.
 * 
 * Inicializa o sistema, configura os botões e entra em um loop infinito
 * para monitorar interações do usuário.
 * 
 * @return Retorna 0 ao final da execução (caso saia do loop, o que não deve ocorrer).
 */
int main() {
    // Inicializa a comunicação serial padrão (necessário para saída de debug via USB)
    stdio_init_all();

    // Inicializa os LEDs na placa
    npInit(LED_PIN);

    // Inicializa a estrutura do sistema
    sistema_init(&sistema);

    // Inicializa os botões com seus respectivos pinos
    botao_init(&botao_a, BOTAO_A);
    botao_init(&botao_b, BOTAO_B);

    // Configura os botões
    botao_a.configurar(&botao_a);
    botao_b.configurar(&botao_b);

    // Configura as interrupções para os botões
    gpio_set_irq_enabled_with_callback(BOTAO_A, GPIO_IRQ_EDGE_FALL, true, &interrupcao_botao);
    gpio_set_irq_enabled_with_callback(BOTAO_B, GPIO_IRQ_EDGE_FALL, true, &interrupcao_botao);

    // Loop principal do programa
    while (true) {
        // Verifica se o botão A foi pressionado
        if (botao_a.pressionado) {
            botao_a.pressionado = false; // Reseta o estado do botão
            sistema_entrada_pessoa(&sistema); // Executa a ação correspondente
        }

        // Verifica se o botão B foi pressionado
        if (botao_b.pressionado) {
            botao_b.pressionado = false; // Reseta o estado do botão
            sistema_saida_pessoa(&sistema); // Executa a ação correspondente
        }

        // Mantém o loop rodando de forma eficiente
        tight_loop_contents();
        sleep_ms(100); // Pequeno atraso para evitar polling excessivo
    }

    return 0;
}
