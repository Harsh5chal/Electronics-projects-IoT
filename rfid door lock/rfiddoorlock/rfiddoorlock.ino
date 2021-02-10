#include <SPI.h>
#include <MFRC522.h>
MFRC522 mfrc522(10, 9);
int granted = 8;
int denied = 7;
 
void setup(){
Serial.begin(9600);
SPI.begin();
mfrc522.PCD_Init();
pinMode(granted,OUTPUT);
pinMode(denied,OUTPUT);
Serial.println("Place the Card or Tag ");
}

void loop(){
if ( ! mfrc522.PICC_IsNewCardPresent()){
return;
}
if ( ! mfrc522.PICC_ReadCardSerial()) {
return;
}
Serial.print("Tag: ");
String content= "";
for (byte i = 0; i < mfrc522.uid.size; i++) {
Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
Serial.print(mfrc522.uid.uidByte[i], HEX);
content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
content.concat(String(mfrc522.uid.uidByte[i], HEX));
}
Serial.println();
content.toUpperCase();
content = content.substring(1);
if(content == "56 E0 67 AC"){
  digitalWrite(granted,HIGH);
  digitalWrite(denied,LOW);
Serial.println("Access Granted.");
Serial.println();
delay(900);
}else{
  digitalWrite(granted,LOW);
  digitalWrite(denied,HIGH);
Serial.println("Access Denied.");
delay(900);
}
}
