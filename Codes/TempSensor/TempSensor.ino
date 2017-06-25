/* 
Temperature sensor  which read temperature of surrounding atmosphere
using LM35 

LM 35 
Flat side up, left to right
Pin 1 - Vcc
Pin 2 - Output/Analog Pin A0
Pin 3 - Gnd

LCD Interfacing
Pin 1 - GND
Pin 2 - Vcc
Pin 3 - Gnd
Pin 4 - RS digitalPin 7
Pin 5 - R/W Gnd
Pin 6 - EN digitalPin 6
Pin 7 to 10 - NC 
Pin 11 - digitalPin 5  
Pin 12 - digitalPin 4
Pin 13 - digitalPin 3
Pin 14 - digitalPin 2
Pin 15 - Vcc
Pin 16 - Gnd
*/
// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2); 
  lcd.print("Temperature C");
}

void loop() {
  
 int sensorValue = analogRead(A0);
 float milliVolt = ( sensorValue/1024.0)*5000; 
 float cel = milliVolt/10;
 float farh = (cel*9)/5 + 32;

Serial.print("TEMPRATURE = ");
Serial.print(cel);
Serial.print("*C");
Serial.println();

lcd.setCursor(0, 1); 
lcd.print(cel); 
delay(1000);
}
