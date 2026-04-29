// Definir el pin del LED (usualmente el 2 en el ESP32)
const int ledPin = 2;

void setup() {
  // Iniciar la comunicación serial
  Serial.begin(115200);
  
  // Configurar el pin del LED como salida
  pinMode(ledPin, OUTPUT);
  
  Serial.println("¡Hola Mundo! Iniciando sistema IoT...");
}

void loop() {
  // Leer el estado actual del LED e invertirlo (si está encendido se apaga y viceversa)
  digitalWrite(ledPin, !digitalRead(ledPin)); 
  
  Serial.println("ESP32 volando (sin antigravity, pero en C++)...");
  
  // Esperar 1000 milisegundos (1 segundo)
  delay(1000);
}

