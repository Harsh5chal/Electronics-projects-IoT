int tP=8;
int eP=9;
int revrht=6;
int fowrht=7;
int revlft=4;
int fowlft=5;
float spd=343;
float tD;
float ping;

void setup(){
  pinMode(tP,OUTPUT);
  pinMode(eP,INPUT);
  pinMode(revlft,OUTPUT);
  pinMode(revrht,OUTPUT);
  pinMode(fowlft,OUTPUT);
  pinMode(fowrht,OUTPUT);
  Serial.begin(9600);
}

void loop(){
  digitalWrite(tP,HIGH);
  delayMicroseconds(2000);
  digitalWrite(tP,LOW);
  delayMicroseconds(15);
  digitalWrite(tP,HIGH);
  delayMicroseconds(10);

  ping = pulseIn(eP,HIGH);
  ping = ping/1000000;
  tD = spd*ping;
  tD = tD/2;
  tD = tD*100;
  Serial.println(tD);

  if(tD > 18.){
  digitalWrite(fowlft,HIGH);
  digitalWrite(fowrht,HIGH);
  digitalWrite(revlft,LOW);
  digitalWrite(revrht,LOW);
  }

  if(tD < 18.){
    digitalWrite(fowlft,LOW);
    digitalWrite(fowrht,LOW);
    digitalWrite(revlft,LOW);
    digitalWrite(revrht,LOW);
    delay(500);
    digitalWrite(fowlft,LOW);
    digitalWrite(fowrht,LOW);
    digitalWrite(revlft,HIGH);
    digitalWrite(revrht,HIGH);
    delay(500);
    digitalWrite(fowlft,LOW);
    digitalWrite(fowrht,LOW);
    digitalWrite(revlft,LOW);
    digitalWrite(revrht,LOW);
    delay(100);
    digitalWrite(fowlft,LOW);
    digitalWrite(fowrht,HIGH);
    digitalWrite(revlft,LOW);
    digitalWrite(revrht,LOW);
    delay(100);
    digitalWrite(fowlft,HIGH);
    digitalWrite(fowrht,LOW);
    digitalWrite(revlft,LOW);
    digitalWrite(revrht,LOW);
    delay(500);
    
  }


}
