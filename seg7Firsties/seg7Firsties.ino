#include <SevSeg.h>


int segA = 12;
int segC = 10;
int segF = 7;
int segD = 9;
int segE = 8;
int segB = 11;
int segG = 6;
int segDP = 13;

int p1 = 2;
int p2 = 3;
int p3 = 4;
int p4 = 5;

SevSeg sevSeg;

const int knob = 19;
int knobValue = 0;

const int buzzer = 14;

const int btn = 1;
int btnState = 0;

int spd = 200;

String disp = "A";
String demin = "";
int dispCount = 0;

// Variables will change:
int ledState = HIGH;         // the current state of the output pin
int buttonState;             // the current reading from the input pin
int lastButtonState = LOW;   // the previous reading from the input pin

// the following variables are unsigned longs because the time, measured in
// milliseconds, will quickly become a bigger number than can be stored in an int.
unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 50;

void setup()  { 

  pinMode(knob, INPUT);
  pinMode(btn, INPUT);

  byte digits = 4;
  byte digitPins[] = {p4, p3, p2, p1};
  byte segments[] = {
    segA, segC, segF, segG, segE, segB, segD, segDP
  };
  
  sevSeg.begin(
    COMMON_CATHODE, 
    digits, 
    digitPins, 
    segments, 
    false, 
    false, 
    false, 
    false
    );

    pinMode(buzzer, OUTPUT);

    Serial.begin(16000);
}

void displayChars(char str[]) {
  sevSeg.setChars(str);
  sevSeg.refreshDisplay();  
}

void loop() {
  knobValue = map(analogRead(knob), 0, 1023, 1, 999);
  btnState = digitalRead(btn);

  demin = disp + knobValue;
  int len = demin.length() + 1;
  char str[len];
  demin.toCharArray(str, len);
  displayChars(str);

  Serial.print(str);
  Serial.print("\n");                                  
  

  int reading = digitalRead(btn);

  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != buttonState) {
      buttonState = reading;
      if (buttonState == HIGH) {
        tone(buzzer, 1000);
        updateLetter();
      } else {
        noTone(buzzer);  
      }
    }
  }
  
  lastButtonState = reading;

}

void updateLetter() {
  dispCount += 1;
  
  if(dispCount > 5) {
    dispCount = 0;
  }

  switch(dispCount) {
    case 0:
      disp = "A";
      break;
    case 1: 
      disp = "B";
      break;
    case 2: 
      disp = "C";
      break;
    case 3: 
      disp = "D";
      break;
    case 4: 
      disp = "E";
      break;
    case 5:
      disp = "F";
      break;         
  }
  
}
