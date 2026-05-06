// --- Definición de constantes (usamos 'byte' o 'uint8_t' para ahorrar memoria en pines) ---
const uint8_t potPin = 34;    // Pin analógico donde conectamos el potenciómetro
const uint8_t ledPin = 2;     // Pin PWM donde conectamos el LED (generalmente el LED integrado)

// --- Variables globales ---
int potValue = 0;             // Almacena la lectura bruta (0 a 4095)
int ledValue = 0;             // Almacena el valor mapeado para el LED (0 a 255)
int lastLedValue = -1;        // Para comparar y solo imprimir si el valor cambia

void setup() {
  // Inicializa la comunicación serial a 115200 (más estándar y rápido para ESP32)
  Serial.begin(115200);       
  
  // Configura el pin del LED como salida
  pinMode(ledPin, OUTPUT);    
  
  Serial.println("Sistema iniciado. Gira el potenciometro...");
}

void loop() {
  // 1. Leer el valor del potenciómetro (Lectura de 12 bits: 0 - 4095)
  potValue = analogRead(potPin);
  
  // 2. Escalar el valor: de 12 bits (entrada) a 8 bits (salida PWM)
  // Se usa map para convertir el rango 0-4095 a 0-255
  ledValue = map(potValue, 0, 4095, 0, 255);
  
  // 3. Aplicar el brillo al LED mediante PWM (Pulse Width Modulation)
  analogWrite(ledPin, ledValue);
  
  // 4. Optimización: Solo imprimir en el monitor serial si el valor ha cambiado significativamente
  // Esto evita saturar el puerto serie con datos idénticos
  if (abs(ledValue - lastLedValue) > 1) { 
    Serial.print("Entrada (Pot): ");
    Serial.print(potValue);
    Serial.print(" \t| Brillo LED: ");
    Serial.println(ledValue);
    
    lastLedValue = ledValue;   // Actualizamos el último valor guardado
  }
  
  // Pequeña pausa para estabilizar las lecturas del ADC (conversor analógico-digital)
  delay(15);
}