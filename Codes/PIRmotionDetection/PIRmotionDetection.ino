int pirPin = 3;    //the digital pin connected to the PIR sensor's output
int buzzerPIn = 13; //the digital pin connected to the Buzzer
int calibrationTime = 10;        


void setup(){
  Serial.begin(9600);
  pinMode(pirPin, INPUT);
  pinMode(buzzerPIn, OUTPUT);
  digitalWrite(pirPin, LOW);

  //give the sensor some time to calibrate
  Serial.print("calibrating sensor ");
    for(int i = 0; i < calibrationTime; i++){
      Serial.print(".");
      delay(1000);
      }
    Serial.println(" done");
    Serial.println("SENSOR ACTIVE");
    delay(50);
  }


void loop(){

     if(digitalRead(pirPin) == HIGH){
       digitalWrite(buzzerPIn, HIGH);   //the Buzzer visualizes the sensors output pin state
       Serial.println("motion detected ");
        delay(100);
       }

     if(digitalRead(pirPin) == LOW){       
       digitalWrite(buzzerPIn, LOW); 
       delay(100);
       }

       delay(500);
  }

