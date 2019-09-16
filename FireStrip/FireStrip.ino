
const int blue = 4;
const int red = 5;
const int green = 3;

int rBgt = 20;
int gBgt = 250;

int loopSpeed = 50;

int rMod = 2;
int gMod = 1;

void setup()  { 
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
}

void writeSignals() {
  analogWrite(green, gBgt);
  analogWrite(red, rBgt);
}

void loop() {
  rBgt = random(1, 150);
  writeSignals();
    
  delay(loopSpeed);
}
