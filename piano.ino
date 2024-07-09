#include "notas.h"

const int buzzer = A0; // Pino do buzzer
const int potPin = A1; // Pino do potenciômetro
const int pinosBotoes[] = {13, 12, 11, 10, 9, 8, 7, 6}; // Pinos dos botões

void setup() {
  // Configurando os pinos dos botões como entradas
  for (int i = 0; i < 8; i++) {
    pinMode(pinosBotoes[i], INPUT_PULLUP);
  }
  pinMode(buzzer, OUTPUT);
  pinMode(potPin, INPUT);
}

int calculateFrequency(int baseNote, int octaveShift) {
  // Calcula a frequência ajustada com base na oitava
  return baseNote * pow(2, octaveShift);
}

void loop() {
  int potValue = analogRead(potPin); // Lê o valor do potenciômetro (0 a 1023)
  
  // Mapeia o valor do potenciômetro para um intervalo de oitavas (-2 a +2)
  int octaveShift = map(potValue, 0, 1023, -2, 2);
  
  for (int i = 0; i < 8; i++) {
    if (digitalRead(pinosBotoes[i]) == LOW) {
      int adjustedNote = calculateFrequency(notas[i], octaveShift);
      tone(buzzer, adjustedNote);
      while (digitalRead(pinosBotoes[i]) == LOW); // Espera até o botão ser solto
      noTone(buzzer);
    }
  }
}