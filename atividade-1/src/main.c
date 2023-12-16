#include <stdio.h>
#include "pico/stdlib.h"

const uint LED_PIN = 16;
const uint BUTTON_PIN = 17;

int main() {
    stdio_init_all();

    // Configuração dos pinos
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    gpio_init(BUTTON_PIN);
    gpio_set_dir(BUTTON_PIN, GPIO_IN);
    gpio_pull_down(BUTTON_PIN);

    while (true) {
        if (gpio_get(BUTTON_PIN) == 1) {
            // Inverte o estado do LED
            gpio_put(LED_PIN, 1);
            sleep_ms(250);
        } else {
          gpio_put(LED_PIN, 0);
          sleep_ms(250);
         }
    }

    return 0;
}