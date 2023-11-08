#include <stdio.h>
#include "pico/stdlib.h"

const uint LED_PIN = 28;
const uint BUTTON_PIN = 14;

int main() {
    stdio_init_all();

    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    gpio_init(BUTTON_PIN);
    gpio_set_dir(BUTTON_PIN, GPIO_IN);
    gpio_pull_down(BUTTON_PIN);

    printf("Start\n");
    while (true) {
        if (gpio_get(BUTTON_PIN) == 1) {
            gpio_put(LED_PIN, !gpio_get(LED_PIN));
        }
    }

    return 0;
}
