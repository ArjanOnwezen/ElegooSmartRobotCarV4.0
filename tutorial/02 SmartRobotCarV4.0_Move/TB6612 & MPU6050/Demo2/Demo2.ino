#include <avr/wdt.h>
#include "DeviceDriverSet_xxx0.h"
#include "ApplicationFunctionSet_xxx0.cpp"

DeviceDriverSet_Motor AppMotor;
Application_xxx Application_ConquerorCarxxx0;

void setup() {
  AppMotor.DeviceDriverSet_Motor_Init();
  delay(2000);

}

void loop() {

  for (Application_ConquerorCarxxx0.Motion_Control = 0; Application_ConquerorCarxxx0.Motion_Control < 2; Application_ConquerorCarxxx0.Motion_Control = Application_ConquerorCarxxx0.Motion_Control + 1)
  {
    ApplicationFunctionSet_ConquerorCarMotionControl(Application_ConquerorCarxxx0.Motion_Control /*direction*/, 255 /*speed*/);
    delay(1000);
  }


}
