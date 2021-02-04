// Lights control is in beta - feel free to message me if it doesn't work!!!
//
// Ground digital pins 6-9 to press the joystick 
//  buttons 0, 1, 2, and 3.
// Lights can be hooked up to pins 2-5 and correlate directly with
//  pins 6-9.  
//
// NOTE: This sketch file is for use with Arduino Leonardo and
//       Arduino Micro only.
//
// Orig by Matthew Heironimus
// 2015-11-20
// Edits for Ltek Dance pad: 
// Todd Oakes
//  2020-06-14 
//  lights added 2021-02-04
//--------------------------------------------------------------------

#include <Joystick.h>

Joystick_ Joystick;
#define DEBOUNCE_DELAY 5
#define NBUTTONS 4
static const int buttonPins[NBUTTONS] = {6,7,8,9};
static const int lightPins[NBUTTONS] = {2,3,4,5};
static unsigned long lastButtonState[NBUTTONS]; 

void setup() {
  
  //pinMode(LED_BUILTIN, OUTPUT); //whats this do? from DanceCtl
  // Initialize Button Pins 4-9
  for (int i = 0; i < NBUTTONS; i++)
    pinMode(buttonPins[i], INPUT_PULLUP);
  
  // Initialize Joystick Library
  Joystick.begin();

  // Last state of the button
  
  for (int i = 0; i < NBUTTONS; i++)
  { 
   lastButtonState[i] = 0;
   pinMode(lightPins[i], OUTPUT);
   digitalWrite(lightPins[i], LOW);  
  }
  
}

// Constant that maps the phyical pin to the joystick button.
//const int pinToButtonMap = 4;


void loop() {
  unsigned long now = millis();
  static unsigned long lastButtonChange[NBUTTONS];
  
  // Read pin values
  for (int index = 0; index < NBUTTONS; index++)
  {
    int currentButtonState = !digitalRead(buttonPins[index]);
    if (currentButtonState != lastButtonState[index] && (lastButtonChange[index] + DEBOUNCE_DELAY) < now)
    {
      Joystick.setButton(index, currentButtonState);
      lastButtonState[index] = currentButtonState;
      lastButtonChange[index] = now;
      if (currentButtonState) //this if-else is just for lights control.
      {
        digitalWrite(lightPins[index], HIGH);  
      } 
      else 
      {
        digitalWrite(lightPins[index], LOW);  
      }
    }
  }

  //delay(50); //maybe change to DEBOUNCE_DELAY if it's still needed.
}
