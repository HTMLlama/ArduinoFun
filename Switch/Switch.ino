int blue = 9;
int red = 3;
int green = 6;

int rBgt = 255;
int gBgt = 255;
int bBgt = 255;

int btn = 2;
int btnState = 0;

int loopSpeed = 0;

void leave() {
   analogWrite(blue, bBgt);
   analogWrite(green, 0);    
   analogWrite(red, 0);
   delay(250);
   analogWrite(blue, 0);
   delay(250);
   analogWrite(blue, bBgt);
   delay(250);
   analogWrite(blue, 0);
   delay(250);
   analogWrite(blue, bBgt);
   delay(250);
   analogWrite(red, rBgt);
   analogWrite(blue, 0);
   
   exit(0);
}

void setup()  { 
  pinMode(blue, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
    
  pinMode(btn, INPUT);
  
  analogWrite(green, gBgt);
}

void loop() {
  btnState = digitalRead(btn);
  
  if(btnState == LOW) {
    analogWrite(green, gBgt);
    analogWrite(blue, 0);
    analogWrite(red, 0);
    
  } else {
    leave();
  }
  
  delay(loopSpeed);
}
