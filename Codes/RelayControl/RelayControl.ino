
const int buttonPin = 2;     
const int ledPin =  13; 
const int relayPin = 8;     

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

void setup() {
  // initialize the LED pin and relay Pin as an output:
  pinMode(ledPin, OUTPUT);
  pinMode(relayPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // turn LED on:
    digitalWrite(ledPin, HIGH);
    digitalWrite(relayPin, HIGH);
  } else {
    // turn LED off:
    digitalWrite(ledPin, LOW);
    digitalWrite(relayPin, LOW);
  }
}
