#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/time.h"

const uint LED_PIN = 28;
const uint LED_PIN2 = 27;
const uint BUTTON_PIN = 14;
const uint BUTTON_PIN2 = 13;
const uint DEBOUNCE_DELAY_MS = 250;

int main() {
    stdio_init_all();

    // Configuração dos pinos
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    gpio_init(LED_PIN2);
    gpio_set_dir(LED_PIN2, GPIO_OUT);

    gpio_init(BUTTON_PIN);
    gpio_set_dir(BUTTON_PIN, GPIO_IN);
    gpio_pull_down(BUTTON_PIN);
    gpio_init(BUTTON_PIN2);
    gpio_set_dir(BUTTON_PIN2, GPIO_IN);
    gpio_pull_down(BUTTON_PIN2);

    printf("Start\n");

    while (true) {
        // Leitura do botão com debounce
        if (gpio_get(BUTTON_PIN) == 1) {
            // Inverte o estado do LED
            gpio_put(LED_PIN, !gpio_get(LED_PIN));
            printf("Button press. LED state: %d\n", gpio_get(LED_PIN));
            sleep_ms(DEBOUNCE_DELAY_MS);
        }

        if (gpio_get(BUTTON_PIN2) == 1) {
            // Inverte o estado do LED
            gpio_put(LED_PIN2, gpio_get(LED_PIN2));
            printf("Button press 2. LED state: %d\n", gpio_get(LED_PIN2));
            sleep_ms(DEBOUNCE_DELAY_MS);
        }
    }

    return 0;
}
