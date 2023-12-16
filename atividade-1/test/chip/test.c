// Wokwi Custom Chip - For information and examples see:
// https://docs.wokwi.com/chips-api/getting-started
//
// SPDX-License-Identifier: MIT
// Copyright (C) 2022 Uri Shaked / wokwi.com

#include "wokwi-api.h"
#include <stdio.h>
#include <stdlib.h>

int status = 0;
int vezes = 0;
int count = 0;

typedef struct {
    pin_t pin_a;
    pin_t pin_b;
    pin_t pin_c;

    uint64_t t_start;

} chip_state_t;

// Função auxiliar para atualizar a saída com base no valor do pino A
static void update_output(chip_state_t *chip) {
    uint32_t a = pin_read(chip->pin_a);
    if (a) {
        printf("ON\n");
        count += 1;
    } else {
        printf("OFF\n");
    }
}

static void debounce_button(chip_state_t *chip) {
  status = !status;
  uint64_t teste = get_sim_nanos() / 1000000;
  printf("%llu\n", teste);
  pin_write(chip->pin_b, status);

}

// Função de callback chamada quando ocorre uma alteração no pino
static void chip_pin_change(void *user_data, pin_t pin, uint32_t value) {
    chip_state_t *chip = (chip_state_t *)user_data;

    // if (chip->pin_b == pin) {
    //     debounce_button((chip_state_t*)user_data);
    // }

    if (chip->pin_a == pin) {
      update_output((chip_state_t*)user_data);
    }
}

void chip_timer_callback(void *user_data) {
  chip_state_t *chip = (chip_state_t *)user_data;
  
  if (vezes < 5) {
    status = !status;
    vezes += 1;
    pin_write(chip->pin_b, status);
  } else {
    pin_write(chip->pin_b, 1);
  }
  
  if (count == 1) {
    pin_write(chip->pin_c, 1);
  } else {
    pin_write(chip->pin_c, 0);
  }
}

// Função de inicialização do chip
void chip_init() {
    // Aloca a estrutura do chip dinamicamente
    chip_state_t *chip = malloc(sizeof(chip_state_t));

    // Inicializa os pinos A e B
    chip->pin_a = pin_init("A", INPUT);
    chip->pin_b = pin_init("B", OUTPUT);
    chip->pin_c = pin_init("C", OUTPUT);

    chip->t_start = get_sim_nanos() / 1000000;

    // Configura a função de callback para mudanças no pino A
    const pin_watch_config_t watch_config = {
        .edge = BOTH,
        .pin_change = chip_pin_change,
        .user_data = chip,
    };

    const timer_config_t config = {
    .callback = chip_timer_callback,
    .user_data = chip,
  };

    pin_watch(chip->pin_a, &watch_config);
    pin_watch(chip->pin_b, &watch_config);
    pin_watch(chip->pin_c, &watch_config);

    timer_t timer_id = timer_init(&config);
    timer_start(timer_id, 1000, true);
}