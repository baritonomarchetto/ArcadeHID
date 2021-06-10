/* ArcadeHID - buttons handling example
 * Keyboard emulation
 *  
 * by Barito, 2021 
*/

#include <Keyboard.h>

const byte button1Pin = 10;
const byte button2Pin = 14;

boolean button1State;
boolean button2State;

unsigned long button1dbTime;
unsigned long button2dbTime;

const int delayTime = 20;

void setup(){
pinMode(button1Pin, INPUT_PULLUP);
pinMode(button2Pin, INPUT_PULLUP);
button1State = digitalRead(button1State);
button2State = digitalRead(button2State);
Keyboard.begin();
}

void loop(){
Buttons();
}

void Buttons(){
//BUTTON 1
if(digitalRead(button1Pin) !=  button1State && millis()- button1dbTime > delayTime){
  if(button1State == LOW){
    Keyboard.press(97); // ASCII DEC "97" = "a"
  } 
  else {//if buttonstate == HIGH)
    Keyboard.release(97);
  }
}
//BUTTON 2
if(digitalRead(button2Pin) !=  button2State && millis()- button2dbTime > delayTime){
  if(button2State == LOW){
    Keyboard.press(98); // ASCII DEC "98" = "b"
  } 
  else {//if buttonstate == HIGH)
    Keyboard.release(98);
  }
}
}
