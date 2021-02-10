#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
lcd.begin(16,2);//16 by 2 are the dimensions of the LCD (in number of characters)
Serial.begin(9600);//launch the process of receiving serial data (via bluetooth) at 9600 bits/s
}

void loop() {
if(Serial.available()){
lcd.write(Serial.read());//these two lines mean that if there is data coming from the BT module, the Arduino prints it on the LCD.
}
}
