
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

int touch = 17;
int touchValue = 0;

int loopSpeed = 100;

int RED = 0;
int GREEN = 1;
int BLUE = 2;
int colors[] = {RED, GREEN, BLUE};
int colorIndex = 0;
int color = RED;

boolean isUp = true;

void btnClicked() {
//   analogWrite(red, 255);
//   analogWrite(green, 0);    
//   analogWrite(blue, 0);
//   delay(250);
//   analogWrite(red, 0);
//   delay(250);
//   analogWrite(blue, 255);
//   delay(250);
//   analogWrite(blue, 0);
//   delay(250);
//   analogWrite(green, 255);
//   delay(250);
//   analogWrite(red, 255);
//   analogWrite(green  , 0);
//   
//   exit(0);

  colorIndex += 1;
  if (colorIndex >= sizeof(colors)) {
    colorIndex = 0;
  }
  
  delay(100);
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
  pinMode(touch, INPUT);
  
  Serial.begin(9600);
  
  analogWrite(green, gBgt);
}

void core() {
  
  if(btnState == HIGH) {
    btnClicked();
  }
  
  color = colors[colorIndex];
  
  if(color == RED ) {
    gBgt = 0;
    if(isUp) {rBgt += 1;} else {rBgt -= 1;}
    bBgt = 0;
  } else if (color == GREEN) {
    if(isUp) {gBgt += 1;} else {gBgt -= 1;}
    rBgt = 0;
    bBgt = 0;
  } else if(color == BLUE) {
    gBgt = 0;
    rBgt = 0;
    if(isUp) {bBgt += 1;} else {bBgt -= 1;}
  } else {
    gBgt = 150;
    rBgt = 150;
    bBgt = 150;
  }
  
  if(rBgt <= 0 || gBgt <= 0 || bBgt <= 0 || rBgt >= 255 || gBgt >= 255 || bBgt >= 255) {
    isUp = !isUp;
  }
  
  Serial.println("Red: ");
  Serial.println(rBgt);
  Serial.println(" Green: ");
  Serial.println(gBgt);
  Serial.println(" Blue: ");
  Serial.println(bBgt);
  
//  gBgt = remoteValue;
//  bBgt = remoteValue - 255;
//  rBgt = remoteValue - 255 - 255;
//    
//  gBgt = colorValue(gBgt);
//  bBgt = colorValue(bBgt);
//  rBgt = colorValue(rBgt);
}

void readSignals() {
  btnState = digitalRead(btn);
  knobValue = analogRead(knob);
  touchValue = digitalRead(touch);
}

void writeSignals() {
  analogWrite(green, gBgt);
  analogWrite(blue, bBgt);
  analogWrite(red, rBgt);
}

void loop() {
  readSignals();
  core();
  writeSignals();
  
  Serial.println(touchValue);
  
  delay(loopSpeed);
}
