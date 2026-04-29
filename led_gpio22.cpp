#include <Arduino.h>

const int led_22 = 22;

void setup() {
  Serial.begin(115200);
  
  // Configurar el GPIO 22 como salida
  pinMode(led_22, OUTPUT);
  
  // Encender el LED (HIGH equivale a 1 o mandar voltaje)
  digitalWrite(led_22, HIGH); 
  
  Serial.println("¡LED en el GPIO 22 encendido exitosamente!");
}

void loop() {
  // Como solo queremos encenderlo una vez, el loop queda vacío
}
