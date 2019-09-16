int blue = 9;
int red = 3;
int green = 6;

int rBgt = 255;
int gBgt = 255;
int bBgt = 255;

int btn = 2;
int btnState = 0;

int knob = 15;
int knobValue = 0;

int loopSpeed = 0;

void leave() {
   analogWrite(blue, 255);
   analogWrite(green, 0);    
   analogWrite(red, 0);
   delay(250);
   analogWrite(blue, 0);
   delay(250);
   analogWrite(blue, 255);
   delay(250);
   analogWrite(blue, 0);
   delay(250);
   analogWrite(blue, 255);
   delay(250);
   analogWrite(red, 255);
   analogWrite(blue, 0);
   
   exit(0);
}

int colorValue(int color) {
  if(color >= 255) {
    return 255;
  } else if (color <= 0) {
    return 0;
  } else return color;
}

void setup()  { 
  pinMode(blue, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
    
  pinMode(btn, INPUT);
  pinMode(knob, INPUT);
  
  analogWrite(green, gBgt);
}

void loop() {
  btnState = digitalRead(btn);
  knobValue = analogRead(knob);
  
  if(btnState == LOW) {
    
    gBgt = knobValue;
    bBgt = knobValue - 255;
    rBgt = knobValue - 255 - 255;
    
    gBgt = colorValue(gBgt);
    bBgt = colorValue(bBgt);
    rBgt = colorValue(rBgt);
    
    analogWrite(green, gBgt);
    analogWrite(blue, bBgt);
    analogWrite(red, rBgt);
    
  } else {
    leave();
  }
  
  delay(loopSpeed);
}
