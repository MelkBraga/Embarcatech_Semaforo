#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include "hardware/timer.h"

#define LED_VERMELHO 11
#define LED_AMARELO 12
#define LED_VERDE 13

volatile int estado = 0; // 0: vermelho, 1: amarelo, 2: verde

// Função para configurar PWM em um pino
void configurar_pwm(uint gpio) {
    gpio_set_function(gpio, GPIO_FUNC_PWM);
    uint slice_num = pwm_gpio_to_slice_num(gpio);
    pwm_set_wrap(slice_num, 255); 
    pwm_set_chan_level(slice_num, pwm_gpio_to_channel(gpio), 0); // Inicia desligado
    pwm_set_enabled(slice_num, true);
}

// Função para definir a intensidade do LED e gerar um amarelo equilibrado
void set_pwm_duty(uint gpio, uint8_t duty) {
    uint slice_num = pwm_gpio_to_slice_num(gpio);
    uint channel = pwm_gpio_to_channel(gpio); 
    pwm_set_chan_level(slice_num, channel, duty);
}

// Callback do temporizador
bool repeating_timer_callback(struct repeating_timer *t) {

    set_pwm_duty(LED_VERMELHO, 0);
    set_pwm_duty(LED_AMARELO, 0);
    set_pwm_duty(LED_VERDE, 0);

    // Liga o LED correspondente ao estado atual com a intensidade correta
    switch (estado) {
        case 0:
            set_pwm_duty(LED_VERMELHO, 255); // Vermelho
            break;
        case 1:
            set_pwm_duty(LED_AMARELO, 255); // Amarelo
            break;
        case 2:
            set_pwm_duty(LED_VERDE, 255); // Verde
            break;
    }
    
    estado = (estado + 1) % 3;
    return true;
}

int main() {
    stdio_init_all();
    
    // Inicializa os pinos dos LEDs com PWM
    configurar_pwm(LED_VERMELHO);
    configurar_pwm(LED_AMARELO);
    configurar_pwm(LED_VERDE);

    // Chama a função de atualização manualmente para já inciar com o LED vermelho aceso, evitando o atraso inicial
    repeating_timer_callback(NULL);

    // Inicializa o temporizador periódico de 3 segundos
    struct repeating_timer timer;
    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);

    // Loop principal
    while (true) {
        printf("Semáforo mudando em 3...\n");
        sleep_ms(1000); // Intervalo de 1 segundo entre as mensagens
        printf("Semáforo mudando em 2...\n");
        sleep_ms(1000); 
        printf("Semáforo mudando em 1...\n");
        sleep_ms(1000); 
    }
    return 0;
}
