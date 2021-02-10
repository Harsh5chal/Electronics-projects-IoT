#include <dht11.h>
#include <MQ7.h>
#define DHT11PIN A0
dht11 DHT11;
int mqx_analogPin = A1; // connected to the output pin of MQ-X

void setup() {
  Serial.begin(9600);
}

void loop() {
  //dht
Serial.println();
  int chk = DHT11.read(DHT11PIN);
  Serial.print("Humidity (%): ");
  Serial.println((float)DHT11.humidity, 2);
  Serial.print("Temperature (C): ");
  Serial.println((float)DHT11.temperature, 2);
  //mq7
  int mqx_value = analogRead(mqx_analogPin);
  Serial.println(mqx_value);
  //ldr
  unsigned int AnalogValue;
  AnalogValue = analogRead(A2);
  Serial.println(AnalogValue);
  
  delay(5000);
}
