
int blue = 9;
int red = 3;
int green = 6;

int rBgt = 50;
int gBgt = 50;
int bBgt = 50;

int rFade = 25;
int gFade = 15;
int bFade = 5;

int fadeSpeed = 25;

// the setup routine runs once when you press reset:
void setup()  { 
  pinMode(blue, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
} 

void loop()  { 
  analogWrite(blue, bBgt);  
  analogWrite(red, rBgt);
  analogWrite(green, gBgt);  

  rBgt = rBgt + rFade;
  gBgt = gBgt + gFade;
  bBgt = bBgt + bFade;

  // reverse the direction of the fading at the ends of the fade: 
  if (rBgt <= 50 || rBgt >= 255) {
    rFade = -rFade ; 
    
    if (gBgt <= 50 || gBgt >= 255) {
      gFade = -gFade ; 
      
      if (bBgt <= 50 || bBgt >= 255) {
        bFade = -bFade ; 
      }  
      
    } 
    
  }     
  
  //if (gBgt <= 0 || gBgt >= 255) {
  //  gFade = -gFade ; 
  //}     
  
  //if (bBgt <= 0 || bBgt >= 255) {
  //  bFade = -bFade ; 
  //}     
  
  // wait to see the dimming effect    
  delay(fadeSpeed);                            
}

