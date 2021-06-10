/* ArcadeHID - steering wheel handling example
 * gamepad emulation
 *  
 * by Barito, 2021 
*/

#include <Joystick.h>

Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID,JOYSTICK_TYPE_GAMEPAD,
0, 0,                  // Button Count, Hat Switch Count
true, false, false,    // X, Y, Z Axis
false, false, false,   // No Rx, Ry, or Rz
false, false,          // No rudder or throttle
false, false, true);   // No accelerator, brake, or steering
 
const int steerPin = A0; 
int steerValue; 

void setup() {
Joystick.setXAxisRange(0, 1023); //Joystick.setXAxisRange(min, max);
Joystick.begin(); 
}

void loop() { 
SteerWheel();
}

void SteerWheel(){ 
steerValue = analogRead(steerPin); 
Joystick.setXAxis(steerValue);
}
