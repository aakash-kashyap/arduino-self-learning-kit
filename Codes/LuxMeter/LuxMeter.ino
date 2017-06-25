// include the library code:
#include <LiquidCrystal.h>
int resistence = 3.3;
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2); 
  lcd.print("Lux Meter");
}

void loop() {
  
 float sensorValue = analogRead(A0);
 Serial.println(sensorValue);
 float vOut = 5*(sensorValue/(sensorValue+resistence));
 float lux= (2500/vOut)-500;

lcd.setCursor(0, 1); 
lcd.print(lux); 
delay(100);
}
