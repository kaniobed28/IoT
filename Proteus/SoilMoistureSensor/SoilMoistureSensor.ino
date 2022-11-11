#define sensorpin A0
float result;
void setup(){
  pinMode(sensorpin,INPUT);
  Serial.begin(9600);
}
void loop(){
  result = analogRead(sensorpin);
  delay(100);
  Serial.println("soil moisture");
//  Serial.println(result);
  if (result >=800){
  Serial.println("very dry soil");
  }
  else if (result >=500){
  Serial.println("dry soil");
  }
  else if (result >=250){
  Serial.println("wet soil");
  }
  else{
  Serial.println("very wet soil");
  }

}
