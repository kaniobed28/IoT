from machine import ADC, Pin
import time

# Define the ADC pin
adc_pin = 32

def blink_led(pin_num):
    Pin(pin_num,Pin.OUT).on()
    time.sleep(1)
    Pin(pin_num,Pin.OUT).off()
    time.sleep(1)

# Create an ADC object
adc = ADC(Pin(adc_pin))

# Set a pull-down resistor to stabilize the input
adc.atten(ADC.ATTN_11DB)

# Blinky loop with analog reading
while True:
    # Read the analog value
    analog_value = adc.read()
    if analog_value <= 2500:
        blink_led(25)
    elif analog_value <= 3500:
        blink_led(26)
    else:
        blink_led(27)

    # Print the analog value
    print("Analog Value:", analog_value)

    # Wait for a short duration before reading again
    time.sleep(1)
