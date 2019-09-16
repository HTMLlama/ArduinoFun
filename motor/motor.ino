#include "Servo.h"

const int SERVO_PIN = 11;
Servo servo;

//int fanSpeed = 0;
//bool isFanUp = true;

void setup() {
  // put your setup code here, to run once:
//  pinMode(SERVO_PIN, OUTPUT);
  servo.attach(SERVO_PIN);
}

void loop() {

  servo.write(random(0, 180));
  delay(random(150, 1000));

//  // Make servo go to 0 degrees 
//   servo.write(0); 
//   delay(1000); 
//   // Make servo go to 90 degrees 
//   servo.write(90); 
//   delay(1000); 
//   // Make servo go to 180 degrees 
//   servo.write(180); 
//   delay(1000);
//
//   servo.write(60); 
//   delay(1000);
   
//  digitalWrite(SERVO_PIN, LOW);
//
//  if(fanSpeed >= 255 || fanSpeed <= 0) {
//      isFanUp = !isFanUp;
//  }
//
//  if(isFanUp) {
//      fanSpeed++;
//  } else {
//      fanSpeed--;
//  }
//
//  delay(50);
}
