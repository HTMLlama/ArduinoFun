/*
  Blink
 Turns on an LED on for one second, then off for one second, repeatedly.
 
 This example code is in the public domain.
 */

// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int redLed = 8;
int yellowLed = 10;
int greenLed = 12;
int cap = 30;
int i = 0;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(redLed, OUTPUT);
  pinMode(yellowLed, OUTPUT);
  pinMode(greenLed, OUTPUT);  
}

void blink(int on, int off, int led) {
  digitalWrite(led, HIGH);   
  delay(on);             
  digitalWrite(led, LOW);  
  delay(off);
}

// the loop routine runs over and over again forever:
void loop() {
  if(i >= cap) {
    exit(0);
  } 
  else {
    blink(100, 100, redLed);
    blink(200, 100, yellowLed);
    blink(400, 100, greenLed);
    blink(500, 100, redLed);
    blink(500, 100, yellowLed);
    blink(500, 100, greenLed);

    i++;
  }
}

