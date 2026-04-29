import machine
import time

led = machine.Pin(2, machine.Pin.OUT)

print("¡Hola Mundo! Iniciando sistema IoT en mi cumple 29...")

while True:
    led.value(not led.value())
    print("ESP32 volando con antigravity...")
    time.sleep(1)


