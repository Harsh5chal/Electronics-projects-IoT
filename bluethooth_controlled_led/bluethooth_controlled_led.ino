#include <LiquidCrystal.h> //Include the library that enables you to use the LCD

LiquidCrystal lcd(2,3,4,5,6,7);//Declare that your LCD is connected to pins 2,3,4,5,6 & 7 on your Arduino

void setup() {
lcd.begin(16,2);//16 by 2 are the dimensions of the LCD (in number of characters)
Serial.begin(9600);//launch the process of receiving serial data (via bluetooth) at 9600 bits/s
}

void loop() {
if(Serial.available()){
lcd.write(Serial.read());//these two lines mean that if there is data coming from the BT module, the Arduino prints it on the LCD.
}
}
