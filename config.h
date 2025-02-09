#ifndef CONFIG_H
#define CONFIG_H

// Definições globais de hardware

#define BOTAO_A 5 ///< Pino GPIO associado ao botão A
#define BOTAO_B 6 ///< Pino GPIO associado ao botão B
#define LED_AZUL 12 ///< Pino GPIO do LED azul
#define LED_VERMELHO 13 ///< Pino GPIO do LED vermelho

#define I2C_SDA 14 ///< Pino GPIO para o barramento I2C (linha de dados)
#define I2C_SCL 15 ///< Pino GPIO para o barramento I2C (linha de clock)

#define SSD1306_BUFFER_SIZE (128 * 64 / 8) ///< Tamanho do buffer do display OLED SSD1306

#define BUZZER_PIN 21 ///< Pino GPIO do buzzer
#define BUZZER_FREQUENCY 100 ///< Frequência padrão do buzzer em Hz

#define LED_COUNT 25 ///< Número total de LEDs no sistema
#define LED_PIN 7 ///< Pino GPIO onde os LEDs estão conectados

#endif 