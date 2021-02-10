int redPin= 7;
int greenPin = 6;
int bluePin = 5;
void setup()
{
 pinMode(redPin, OUTPUT);
 pinMode(greenPin, OUTPUT);
 pinMode(bluePin, OUTPUT);
}
void loop()
{
 setColor(255, 0, 0); // Red Color
 delay(1000);

setColor(0, 255, 0); // Green Color
 delay(1000);

setColor(0, 0, 255); // Blue Color
delay(1000);
setColor(255, 255, 255); // White Color
delay(1000);
setColor(170, 0, 255); // Purple Color
delay(1000);
}
//The values used under setColor function is the common cathode RGB LED.
/* For the common anode RGB LED,
the value of particular colour output must be 
setColor(255-valRed, 255-valGreen, 255-valBlue) respectively. */
void setColor(int valRed, int valGreen, int valBlue)
{
 analogWrite(redPin, valRed);
 analogWrite(greenPin, valGreen);
 analogWrite(bluePin, valBlue);
} 
