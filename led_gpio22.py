import machine

led_22 = machine.Pin(22, machine.Pin.OUT)

led_22.value(1) 

print("LED en el GPIO 22 encendido exitosamente!")


