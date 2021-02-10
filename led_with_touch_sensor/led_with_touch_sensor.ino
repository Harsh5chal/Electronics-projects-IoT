#define touchpin 4 
int ledPin = 2; 
void setup() {
  pinMode(touchpin, INPUT); 
  pinMode(ledPin, OUTPUT);  
}
void loop() {
  int touchValue = digitalRead(touchpin); 
  if (touchValue == HIGH){      
    digitalWrite(ledPin, HIGH);   
  }
  else{       
    digitalWrite(ledPin,LOW); 
  } 
  delay(300);   
}
