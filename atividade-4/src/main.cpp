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

    while (true) {
        sleep_ms(500);
        printf("agora\n");
        sleep_ms(500);
        printf("vai\n");
    }

    return 0;
}
