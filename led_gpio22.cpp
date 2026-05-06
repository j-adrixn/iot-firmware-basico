/**
 * @file LED_ON_OFF.cpp
 * @brief Control de salida digital para conmutación de un LED.
 * 
 * Este programa configura el pin GPIO 22 del ESP32 como salida digital
 * para realizar un ciclo infinito de encendido y apagado (blinking)
 * con un intervalo de 1000 milisegundos.
 */

#include <Arduino.h>

// Definición del pin GPIO conectado al LED según el requerimiento técnico
const int ledPin = 22;

/**
 * Función de configuración inicial (se ejecuta una sola vez).
 * Se utiliza para inicializar los periféricos y modos de trabajo de los pines.
 */
void setup() {
  // Configura el pin GPIO 22 como salida (OUTPUT) para permitir el flujo de corriente al LED
  pinMode(ledPin, OUTPUT);
}

/**
 * Bucle principal del sistema (se ejecuta de forma cíclica).
 * Contiene la lógica de control para la oscilación del estado del pin.
 */
void loop() {
  // Establece el estado del pin en nivel lógico ALTO (3.3V), encendiendo el LED
  digitalWrite(ledPin, HIGH);
  
  // Detiene la ejecución del procesador por 1000 milisegundos (1 segundo)
  delay(1000);
  
  // Establece el estado del pin en nivel lógico BAJO (0V), apagando el LED
  digitalWrite(ledPin, LOW);
  
  // Mantiene el estado de apagado por otros 1000 milisegundos antes de reiniciar el ciclo
  delay(1000);
}