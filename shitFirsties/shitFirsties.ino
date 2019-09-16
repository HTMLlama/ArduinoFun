
const int latchPin = 7;
const int clockPin = 11;
const int dataPin = 9;
const int outputEnablePin = 6;

void setup() {
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);  
  pinMode(clockPin, OUTPUT);
}

void loop() {
  updateShiftRegister();
  delay(50);
}

void updateShiftRegister()
{
   digitalWrite(latchPin, HIGH);
   shiftOut(dataPin, clockPin, LSBFIRST, B10110010);
   digitalWrite(latchPin, LOW);
}
//
//byte leds = 0;    // Variable to hold the pattern of which LEDs are currently turned on or off
//
///*
// * setup() - this function runs once when you turn your Arduino on
// * We initialize the serial connection with the computer
// */
//void setup() 
//{
//  // Set all the pins of 74HC595 as OUTPUT
//  pinMode(latchPin, OUTPUT);
//  pinMode(dataPin, OUTPUT);  
//  pinMode(clockPin, OUTPUT);
//  pinMode(outputEnablePin, OUTPUT); 
//}
//
///*
// * loop() - this function runs over and over again
// */
//void loop() 
//{
//  setBrightness(150);
//  leds = 0;   // Initially turns all the LEDs off, by giving the variable 'leds' the value 0
//  updateShiftRegister();
//  delay(500);
//  for (int i = 0; i < 8; i++) // Turn all the LEDs ON one by one.
//  {
//    bitSet(leds, i);    // Set the bit that controls that LED in the variable 'leds'
//    updateShiftRegister();
//    delay(500);
//  }
//  for (byte b = 255; b > 0; b--)  // Gradually fade all the LEDs back to off
//  {
//    setBrightness(b);
//    delay(500);
//  }
//}
//
///*
// * updateShiftRegister() - This function sets the latchPin to low, then calls the Arduino function 'shiftOut' to shift out contents of variable 'leds' in the shift register before putting the 'latchPin' high again.
// */
//void updateShiftRegister()
//{
//   digitalWrite(latchPin, LOW);
//   shiftOut(dataPin, clockPin, LSBFIRST, leds);
//   digitalWrite(latchPin, HIGH);
//}
//
///*
// * setBrightness() - Generates PWM signal and writes it to OE pin.
// */
//void setBrightness(byte brightness) // 0 to 255
//{
//  analogWrite(outputEnablePin, 255-brightness);
//}
