

int buzzer = 9;           // the pin that the Buzzer is attached to
int loudeness = 0;    // how bright the LED is
int counter = 5;    // how many points to fade the LED by

// the setup routine runs once when you press reset:
void setup() {
  // declare pin 9 to be an output:
  pinMode(buzzer, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // set the loudeness of pin 9:
  analogWrite(buzzer, loudeness);

  // change the loudeness for next time through the loop:
  loudeness = loudeness + counter;

  // reverse the direction of the fading at the ends of the fade:
  if (loudeness == 0 || loudeness == 255) {
    counter = -counter ;
  }
  // wait for 30 milliseconds to see the dimming effect
  delay(300);
}

