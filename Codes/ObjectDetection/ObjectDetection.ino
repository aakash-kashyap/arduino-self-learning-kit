/* 
Object Detection Module which detects and motion in front of it
using ultrasonic Sensor

Ultrasonic Sensor HC-SR04
Gnd -- 0v
Vcc -- 5V
Trig Pin -- 13 digital Pin
Echo Pin -- 12 digital Pin

LCD Interfacing
Pin 1 - GND
Pin 2 - Vcc
Pin 3 - Gnd
Pin 4 - RS digitalPin 7
Pin 5 - R/W Gnd
Pin 6 - EN digitalPin 6
Pin 7 to 8 - NC
Pin 11 - digitalPin 5  
Pin 12 - digitalPin 4
Pin 13 - digitalPin 3
Pin 14 - digitalPin 2
Pin 15 - Vcc
Pin 16 - Gnd
*/

#define trigPin 13
#define echoPin 12
int upLimit = 50;
int lowLimit = 5;
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  

}

void loop() {
  long duration, distance;
  lcd.clear();
  lcd.begin(16, 2);
  lcd.print("Object detection");
  digitalWrite(trigPin, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin, HIGH);

  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;
  if (distance>lowLimit && distance<upLimit){
     lcd.setCursor(0, 1); 
     lcd.print(distance);
     lcd.setCursor(0, 5); 
     lcd.print("YES");
     delay(500);
  }
  delay(100);
}
