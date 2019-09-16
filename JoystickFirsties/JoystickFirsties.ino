
#include "Joystick.h"

const int JOY_X = 21;
const int JOY_Y = 19;
const int JOY_B = 5;

const int TOG_A = 15;

String serOut = "";

int joyX = 0;
int joyY = 0;
int joyB = 0;
int togA = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(JOY_X, INPUT);
  pinMode(JOY_Y, INPUT);
  pinMode(JOY_B, INPUT);

  pinMode(TOG_A, INPUT);

  Serial.begin(9600);
}

void writeSer(int x, int y, int isBtn, int isA) {

  serOut = "x: " + String(x);
  serOut += "y: " + String(y);
  serOut += "btn: " + String(isBtn);
  serOut += "tog_a: " + String(isA);
  serOut += "\n";

  Serial.println(serOut);
}

void loop() {
  // put your main code here, to run repeatedly:
  joyX = analogRead(JOY_X);
  joyY = analogRead(JOY_Y);
  joyB = digitalRead(JOY_B);
  togA = digitalRead(TOG_A);

  writeSer(joyX, joyY, joyB, togA);

  delay(250);
}
