const int Pt = A0;          
const int redLed = 2;       
const int blueLed = 3;      
const int yellowLed = 4;    
const int orangeLed = 5;    
const int greenLed = 6;    

unsigned long prevIdleRed = 0;  
unsigned long prevIdleGreen = 0; 
const long timeInterval = 500;  

void setup() {
  pinMode(Pt, INPUT);
  pinMode(redLed, OUTPUT);
  pinMode(blueLed, OUTPUT);
  pinMode(yellowLed, OUTPUT);
  pinMode(orangeLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  const int potenRange = analogRead(A0);
  Serial.println(potenRange);

  if (potenRange <= 204) {
    unsigned long curIdleRed = millis();
    if (curIdleRed - prevIdleRed >= timeInterval) {
      prevIdleRed = curIdleRed;

      //Starts blink on and off
      if (digitalRead(redLed) == LOW) {
        digitalWrite(redLed, HIGH);
      } else {
        digitalWrite(redLed, LOW);
      }
    }

    digitalWrite(blueLed, LOW);
    digitalWrite(yellowLed, LOW);
    digitalWrite(orangeLed, LOW);
    digitalWrite(greenLed, LOW);
  }
  else if (potenRange <= 408) {
    digitalWrite(redLed, LOW);
    digitalWrite(blueLed, HIGH);
    digitalWrite(yellowLed, LOW);
    digitalWrite(orangeLed, LOW);
    digitalWrite(greenLed, LOW);
  }
  else if (potenRange <= 612) {
    digitalWrite(redLed, LOW);
    digitalWrite(blueLed, LOW);
    digitalWrite(yellowLed, HIGH);
    digitalWrite(orangeLed, LOW);
    digitalWrite(greenLed, LOW);
  }
  else if (potenRange <= 816) {
    digitalWrite(redLed, LOW);
    digitalWrite(blueLed, LOW);
    digitalWrite(yellowLed, LOW);
    digitalWrite(orangeLed, HIGH);
    digitalWrite(greenLed, LOW);
  }
  else if (potenRange <= 1023) {
    unsigned long curIdleGreen = millis();
    if (curIdleGreen - prevIdleGreen >= timeInterval) {
      prevIdleGreen = curIdleGreen;

      //Blinking on and off led
      if (digitalRead(greenLed) == LOW) {
        digitalWrite(greenLed, HIGH);
      } else {
        digitalWrite(greenLed, LOW);
      }
    }

    digitalWrite(redLed, LOW);
    digitalWrite(blueLed, LOW);
    digitalWrite(yellowLed, LOW);
    digitalWrite(orangeLed, LOW);
  }
}
