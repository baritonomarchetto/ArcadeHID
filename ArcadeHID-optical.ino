/* ArcadeHID - optical encoders handling example
 * mouse emulation
 *  
 * by Barito, 2021 
*/

#include <Mouse.h> 

const int optAPin = 2;  //interrupt pin!
const int optBPin = 4;

void setup() {
pinMode (optAPin,INPUT_PULLUP);
pinMode (optBPin,INPUT_PULLUP);
attachInterrupt(digitalPinToInterrupt(optAPin), OpticalEncoder, RISING); //1X COUNTING, single interrupt
Mouse.begin();
}

void loop() {
//do nothing. The function is called by the interrupt
}

void OpticalEncoder(){ 
//check channel B to see which way encoder is turning
if(digitalRead(optBPin) == LOW){
  Mouse.move(1, 0, 0); //CCW
}
else{
  Mouse.move(-1, 0, 0); //CW
}
}
