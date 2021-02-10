#include <Keypad.h>
#include <Servo.h>

Servo servo_Motor; 
char* password = "123";
int position = 0;
const byte ROWS = 4; 
const byte COLS = 4; 
char keys[ROWS][COLS] = {
{'1','2','3','A'},
{'4','5','6','B'},
{'7','8','9','C'},
{'*','0','#','D'}
};

byte rowPins[ROWS] = { 8, 7, 6, 9 };
byte colPins[COLS] = { 5, 4, 3, 2 };
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
int redPin = 12;
int greenPin = 13;

void setup()
{
pinMode(redPin, OUTPUT);
pinMode(greenPin, OUTPUT);
servo_Motor.attach(11);
setLocked(true);
}

void loop()
{
char key = keypad.getKey();
if (key == '*' || key == '#')
{
position = 0;
setLocked(true);
}
if (key == password[position])
{
position ++;
}
if (position == 3)
{
setLocked(false);
}
delay(100);
}
void setLocked(int locked)
{
if (locked)
{
digitalWrite(redPin, HIGH);
digitalWrite(greenPin, LOW);
servo_Motor.write(11);
}
else
{
digitalWrite(redPin, LOW);
digitalWrite(greenPin, HIGH);
servo_Motor.write(90);
}
}
