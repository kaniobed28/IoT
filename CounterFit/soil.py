
"""
CounterFit is used to  virtually connect sensors.
In this code I used the virtual soil moisture sensor.
"""
import time
from counterfit_connection import CounterFitConnection
from counterfit_shims_grove.adc import ADC #Importing ANALOGUE DIGITAL CONVERTOR
CounterFitConnection.init('127.0.0.1',5000) # Initializing the counterfit connction.
# The sensors can be accessed through the browser on local host port 5000.
adc = ADC()
while True:
    time.sleep(2)
    sensor = adc.read(1) # Virtually reading the soil moisture. 
    print("The soil moisture of the soil is",sensor) # Printing the sensor reading on screen.