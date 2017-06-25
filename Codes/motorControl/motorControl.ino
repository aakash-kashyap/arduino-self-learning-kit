/* 
Dc motor control using motor driver IC L293D
Two DC motors are connectd to arduino via motor driver IC
*/

//left motor pins
int leftMotorPin1=2;
int leftMotorPin2=3;

//right motor pins
int rightMotorPin1=4;
int rightMotorPin2=5;

void setup() {
  

pinMode(leftMotorPin1,OUTPUT);
pinMode(leftMotorPin2,OUTPUT);

pinMode(rightMotorPin1,OUTPUT);
pinMode(rightMotorPin2,OUTPUT);

}

void loop() {

// moves forward for 5 seconds
digitalWrite(leftMotorPin1,HIGH);
digitalWrite(rightMotorPin1,HIGH);
delay(5000);

// moves backward for 5 seconds
digitalWrite(leftMotorPin1,LOW);
digitalWrite(rightMotorPin1,LOW);
delay(5000);
}

