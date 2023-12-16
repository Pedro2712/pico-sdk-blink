# Raspberry Pi Pico w - Embarcados

![](../../actions/workflows/atividade-1.yml/badge.svg)
![](../../actions/workflows/atividade-2.yml/badge.svg)
![](../../actions/workflows/atividade-3.yml/badge.svg)
![](../../actions/workflows/atividade-4.yml/badge.svg)

Configuração dos testes automáticos do Raspberry Pi Pico w.

## Para Testar localmente

### Instalar a biblioteca do Wokwi
```
curl -L https://wokwi.com/ci/install.sh | sh
```

### Exportar o token criado no servidor do Wokwi
```
export WOKWI_CLI_TOKEN=<Token>
```
Caso não tenha o token, acessar o seguinte site [Token Aqui](https://wokwi.com/dashboard/ci)

## Building

```
mkdir build
cd build
cmake ..
make -j4
```

## Simulation

To simulate this project, install [Wokwi for VS Code](https://marketplace.visualstudio.com/items?itemName=wokwi.wokwi-vscode). Open the project directory in Visual Studio Code, press **F1** and select "Wokwi: Start Simulator".

## Automated Testing

This project includes a Wokwi Automation Scenario in [blink.test.yaml](blink.test.yaml). The scenario runs the simulation for 1 second, and verifies that the LED is blinking. The scenario is run automatically on every commit, using [wokwi-ci-action](https://github.com/wokwi/wokwi-ci-action). You can also run the scenario locally, using the [wokwi-cli](https://github.com/wokwi/wokwi-cli) tool:

```
wokwi-cli <atividade>/test --scenario scenario.yml --timeout 1000
```
