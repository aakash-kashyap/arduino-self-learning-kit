/*
Seven Segment Display
  _a_
f|_g_|b
e|_d_|c .DP   // DP-> Dot Point

Pin Connections

a -> Digital Pin 2
b -> Digital Pin 3
c -> Digital Pin 4
d -> Digital Pin 5
e -> Digital Pin 6
f -> Digital Pin 7
g -> Digital Pin 8
DP-> Digital Pin 9
*/
int ledPin = 13; // led  connected at digital pin 13
int numbers[10][7] = {
  { 1, 1, 1, 1, 1, 1, 0 }, // = 0
  { 0, 1, 1, 0, 0, 0, 0 }, // = 1
  { 1, 1, 0, 1, 1, 0, 1 }, // = 2
  { 1, 1, 1, 1, 0, 0, 1 }, // = 3
  { 0, 1, 1, 0, 0, 1, 1 }, // = 4
  { 1, 0, 1, 1, 0, 1, 1 }, // = 5
  { 1, 0, 1, 1, 1, 1, 1 }, // = 6
  { 1, 1, 1, 0, 0, 0, 0 }, // = 7
  { 1, 1, 1, 1, 1, 1, 1 }, // = 8
  { 1, 1, 1, 1, 0, 1, 1 }  //  = 9
};

void writeDot(int dot) {
  digitalWrite(9, dot);
}

void sevenSegWrite(int digit) {
  int pin = 2;
  for (int segCount = 0; segCount < 7; ++segCount)
  {
    digitalWrite(pin, !(numbers[digit][segCount]));
    ++pin;
  }
}

void setup() {
  // put your setup code here, to run once:
  for (int i = 2; i <= 9; i++) {
    pinMode(i, OUTPUT);
  }

}

void loop() {
  // put your main code here, to run repeatedly:

  for (int count = 0; count <= 10; count++) {
    delay(1000);
    sevenSegWrite(count);
  }
  digitalWrite(ledPin, 1); // turn on led for 5 seconds
  delay(5000);
  digitalWrite(ledPin, 0);
}
