# Raspberry Pi Pico Wokwi CI

Ambiende de desenvolvimento para Raspberry Pi Pico com testes de integração com
[Wokwi](https://wokwi.com/).

## Atividades

### Atividade #1 - GPIO debounce

Botão debounce no GPIO com validação de um Custom Chip.

#### Validação

![](https://github.com/Pedro2712/raspberry-pi-pico-wokwi-ci/actions/workflows/atividade-1.yml/badge.svg)

[Abrir atividade →](atividade-1)

### Atividade #2 - Escrita serial

Escrita de mensagem via porta serial com validação.

#### Validação

![](https://github.com/Pedro2712/raspberry-pi-pico-wokwi-ci/actions/workflows/atividade-2.yml/badge.svg)

[Abrir atividade →](atividade-2)

### Atividade #3 - Escrita serial

Escrita de mensagem via porta serial com validação.

#### Validação

![](https://github.com/Pedro2712/raspberry-pi-pico-wokwi-ci/actions/workflows/atividade-3.yml/badge.svg)

[Abrir atividade →](atividade-3)

### Atividade #4 - Escrita serial

Escrita de mensagem via porta serial com validação.

#### Validação

![](https://github.com/Pedro2712/raspberry-pi-pico-wokwi-ci/actions/workflows/atividade-4.yml/badge.svg)

[Abrir atividade →](atividade-4)

## Compilando

```sh
mkdir build
cd build
cmake ..
make -j4 <atividade-*>
```

### Compilando chipes customizados

Algumas atividades podem exigir a compilação de um chipe customizado para
execução dos testes e simulações.
[Saiba mais](https://docs.wokwi.com/pt-BR/chips-api/getting-started).

```sh
make -j4 <atividade-*>-chip-<chipe>
```

## Simulando

Após compilar todas as dependências de uma atividade, para simular este projeto,
instale o
[Wokwi para o VS Code](https://marketplace.visualstudio.com/items?itemName=wokwi.wokwi-vscode).
Abra o diretório do projeto no Visual Studio Code, pressione F1 e selecione
"Wokwi: Start Simulator".

### Executando teste de integração

Com o Token do CLI obtido na
[dashboard do Wokwi](https://wokwi.com/dashboard/ci), exporte com ovariável de
ambiente e esecute o programa.

```sh
export WOKWI_CLI_TOKEN=<Token>
wokwi-cli <atividade-*>/test --scenario scenario.yml
```

## Licença

Este projeto utiliza uma licença do MIT. [Saiba mais](LICENSE).
