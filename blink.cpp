#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/time.h"

const uint LED_PIN = 28;
const uint BUTTON_PIN = 14;
const uint DEBOUNCE_DELAY_MS = 500;

int main() {
    stdio_init_all();

    // Configuração dos pinos
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    gpio_init(BUTTON_PIN);
    gpio_set_dir(BUTTON_PIN, GPIO_IN);
    gpio_pull_down(BUTTON_PIN);

    printf("Start\n");

    while (true) {
        // Leitura do botão com debounce
        if (gpio_get(BUTTON_PIN) == 1) {
            // Inverte o estado do LED
            gpio_put(LED_PIN, !gpio_get(LED_PIN));
            printf("Button pressed. LED state: %d\n", gpio_get(LED_PIN));
            sleep_ms(DEBOUNCE_DELAY_MS);
        }
    }

    return 0;
}
