
#include "HID-Project.h"

#include <FastLED.h>
//#include <Keyboard.h>
//#include <Mouse.h>

///////////////////////////////////
#define NUM_LEDS 10
#define DATA_PIN 10
#define BRIGHTNESS 32
CRGB leds[NUM_LEDS];

int R = 255;
int G = 30;
int B = 198;
///////////////////////////////////
int debounce = 200;
bool toggle = 0;
bool toggle1 = 0;
///////////////////////////////////
char ctrlKey    = KEY_LEFT_CTRL;
char downArrow  = KEY_DOWN_ARROW;
char upArrow    = KEY_UP_ARROW;
char leftArrow  = KEY_LEFT_ARROW;
char rightArrow = KEY_RIGHT_ARROW;
char caps = KEY_CAPS_LOCK;
char F23 = KEY_F23;
char F24 = KEY_F24;

//char VolUp = 0xAF;
//char VolDn = 0xAE;
//char VolMute = 0xAD;
///////////////////////////////////

void setup() {
  Keyboard.begin();
  Consumer.begin();
///////////LED STUFF////////////////////////////////////////
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
  pinMode(DATA_PIN, OUTPUT);

  for (int i = 0; i <= NUM_LEDS; i++)
  {
    leds[i] = CRGB(R, G, B);
  }//end for
  FastLED.show();
  
////////////////////////////////////////////////////////////
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(9 , INPUT_PULLUP);
  pinMode(A3, INPUT_PULLUP);
  pinMode(A2, INPUT_PULLUP);
  pinMode(A1, INPUT_PULLUP);
  pinMode(A0, INPUT_PULLUP);
  pinMode(15, INPUT_PULLUP);
  pinMode(14, INPUT_PULLUP);
  pinMode(16, INPUT_PULLUP);
////////////////////////////////////////////////////////////
  
}//end setup/////////////////////////////////////////////////

void loop() 
{
////////////////////////////////////////////////////////////
  if(digitalRead(2)==LOW)//down arrow
    {
      Keyboard.write(KEY_DOWN_ARROW);
//      Keyboard.begin();
//      Keyboard.press(downArrow);
//      Keyboard.release(downArrow);
//      Keyboard.end();
      delay(debounce);
    }
////////////////////////////////////////////////////////////
  if(digitalRead(3)==LOW)//up arrow
    {
      Keyboard.write(KEY_UP_ARROW);
//      Keyboard.begin();
//      Keyboard.press(upArrow);
//      Keyboard.release(upArrow);
//      Keyboard.end();
      delay(debounce);
    }
////////////////////////////////////////////////////////////
  if(digitalRead(4)==LOW)//left arrow
    {
      Keyboard.write(KEY_LEFT_ARROW);
//      Keyboard.begin();
//      Keyboard.press(leftArrow);
//      Keyboard.release(leftArrow);
//      Keyboard.end();
      delay(debounce);
    }
////////////////////////////////////////////////////////////
  if(digitalRead(5)==LOW && toggle1 ==0)//ctrl spam
    {
      Serial.print("5"); Serial.println();
      //toggle1 = 1;
      //CtrlSpam();
      delay(debounce);
    }
////////////////////////////////////////////////////////////
  if(digitalRead(6)==LOW)//toggle discord mute
    {
      Keyboard.write(KEY_F23);
//      Keyboard.begin();
//      Keyboard.press(F23);
//      Keyboard.release(F23);
//      Keyboard.end();
      delay(debounce);
    }
////////////////////////////////////////////////////////////
  if(digitalRead(A3)==LOW)//caps lock
    {
      Keyboard.write(KEY_CAPS_LOCK);
//      Keyboard.begin();
//      Keyboard.press(caps);
//      Keyboard.release(caps);
//      Keyboard.end();
      delay(debounce);
    }
////////////////////////////////////////////////////////////
  if(digitalRead(A2)==LOW)//idk yet "green pulse"
    {
      Serial.print("A2"); Serial.println();
      delay(debounce);
    }
////////////////////////////////////////////////////////////
  if(digitalRead(A1)==LOW)//toggle deafen
    {
      Keyboard.write(KEY_F24);
//      Keyboard.begin();
//      Keyboard.press(F24);
//      Keyboard.release(F24);
//      Keyboard.end();
      delay(debounce);
    }

////////////////////////////////////////////////////////////
  if(digitalRead(15)==LOW)//right arrow
    {
      Keyboard.write(KEY_RIGHT_ARROW);
//      Keyboard.begin();
//      Keyboard.press(rightArrow);
//      Keyboard.release(rightArrow);
//      Keyboard.end();
      delay(debounce);
    }
////////////////////////////////////////////////////////////
  if(digitalRead(14)==LOW)//vol dn
    {
      Consumer.write(MEDIA_VOL_DOWN);
      Consumer.write(MEDIA_VOL_DOWN);
      Consumer.write(MEDIA_VOL_DOWN);
      Consumer.write(MEDIA_VOL_DOWN);
      Consumer.write(MEDIA_VOL_DOWN);
//      Keyboard.begin();
//      Keyboard.print(VolDn);
//      Keyboard.end();
      delay(debounce *2);
    }
////////////////////////////////////////////////////////////
  if(digitalRead(16)==LOW)//vol up
    {
      Consumer.write(MEDIA_VOL_UP);
      Consumer.write(MEDIA_VOL_UP);
      Consumer.write(MEDIA_VOL_UP);
      Consumer.write(MEDIA_VOL_UP);
      Consumer.write(MEDIA_VOL_UP);
//      Keyboard.begin();
//      Keyboard.print(VolUp);
//      Keyboard.end();
      delay(debounce*2);
    }
////////////////////////////////////////////////////////////
  if(digitalRead(A0)==LOW)//toggle volume mute
    {
      Consumer.write(MEDIA_VOL_MUTE);
//      Keyboard.begin();
//      Keyboard.print(VolMute);
//      Keyboard.end();
      delay(debounce*2);
    }
}//end loop/////////////////////////////////////////////////

void CtrlSpam()
{
  while(toggle1 ==1)  
  { 
    delay(150); 
    Keyboard.write(KEY_LEFT_CTRL);
//    delay(150); 
//    Keyboard.begin();
//    Keyboard.press(ctrlKey);
//    delay(125);
//    Keyboard.release(ctrlKey);
//    Keyboard.end();
    if(digitalRead(5)==LOW)
    {
      toggle1 = 0;
      delay(debounce);
    }
  }
}
