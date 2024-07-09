# Projeto Arduino - Piano

Este projeto consiste na criação de um piano usando o Arduino com um sintetizador musical. Ele utiliza botões para tocar notas musicais e um potenciômetro para ajustar a oitava das notas. Um buzzer é usado para emitir os sons.

## Componentes Necessários

- 1 Arduino (Uno, Mega, etc.)
- 1 Buzzer
- 1 Potenciômetro
- 8 Botões
- Resistores
- Fios de conexão
- Protoboard (opcional)

## Esquema de Conexão

1. **Buzzer**: Conecte o pino positivo do buzzer ao pino A0 do Arduino e o pino negativo ao GND.
2. **Potenciômetro**: Conecte um dos terminais externos do potenciômetro ao 5V do Arduino, o outro terminal externo ao GND e o terminal central ao pino A1 do Arduino.
3. **Botões**: Conecte um terminal de cada botão a um dos pinos digitais do Arduino (13, 12, 11, 10, 9, 8, 7, 6). Conecte o outro terminal de cada botão ao GND. Use resistores de pull-up internos configurando os pinos como `INPUT_PULLUP` no código.

## Explicação do Código

1. **Inclusão de Biblioteca**:
   - `#include "notas.h"`: Biblioteca personalizada que contém as frequências das notas musicais.

2. **Definição de Pinos**:
   - `const int buzzer = A0;`: Define o pino do buzzer.
   - `const int potPin = A1;`: Define o pino do potenciômetro.
   - `const int pinosBotoes[] = {13, 12, 11, 10, 9, 8, 7, 6};`: Define os pinos dos botões.

3. **Configuração Inicial**:
   - `void setup()`: Configura os pinos dos botões como entradas com resistores de pull-up internos e os pinos do buzzer e do potenciômetro.

4. **Cálculo da Frequência**:
   - `int calculateFrequency(int baseNote, int octaveShift)`: Calcula a frequência ajustada com base na oitava.

5. **Loop Principal**:
   - `void loop()`: Lê o valor do potenciômetro e mapeia para um intervalo de oitavas. Verifica se algum botão foi pressionado, ajusta a frequência da nota e a toca no buzzer até que o botão seja solto.

## Notas

- Certifique-se de que a biblioteca `notas.h` está corretamente configurada com as frequências das notas musicais.
- Este projeto pode ser expandido para incluir mais funcionalidades, como um display LCD para mostrar a nota tocada.

## Visualização do Circuito

Link para a visualização: [https://wokwi.com/projects/402757127671193601](https://wokwi.com/projects/402757127671193601)

## Contato

Se você tiver alguma dúvida ou sugestão, sinta-se à vontade para abrir uma issue no repositório do GitHub ou enviar um e-mail para: [nathanfelipi2006@gmail.com](mailto:nathanfelipi2006@gmail.com).

Desenvolvido com ❤️ por [Nathan Felipi Almeida].
