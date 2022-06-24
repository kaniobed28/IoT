import time
from counterfit_connection import CounterFitConnection
from counterfit_shims_grove.adc import ADC
CounterFitConnection.init('127.0.0.1',5000)
adc = ADC()
while True:
    time.sleep(2)
    sensor = adc.read(1)
    print("The soil moisture of the soil is",sensor)