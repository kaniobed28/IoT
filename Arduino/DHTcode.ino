


#include <dht.h>
dht dhtsensor;
void setup()
{
    
    
    Serial.begin(9600);
    Serial.println("Temperature and Humidity");

}

void loop()
{
    dhtsensor.read11(A0); // READING THE SIGNALS FROM PIN A0
    delay(500); // WAITING FOR 500MS
    Serial.print("Temp: "); 
    float temp = dhtsensor.temperature;
    Serial.println(temp);// PRINTING TEMP VALUE ON SERIAL MONITOR
    delay(500);
    Serial.print("humi: ");
    float humi = dhtsensor.humidity; 
    Serial.println(humi); //PRINTING HUMIDITY VALUE ON SERIAL MONITOR
    delay(500);

}