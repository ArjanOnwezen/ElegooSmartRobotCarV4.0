/*
   @Author: ELEGOO
   @Date: 2019-10-22 11:59:09
   @LastEditTime: 2020-06-28 14:55:26
   @LastEditors: Changhua
   @Description: conqueror robot tank
   @FilePath:
*/
#include <avr/wdt.h>
#include "DeviceDriverSet_xxx0.h"

DeviceDriverSet_Servo AppServo;

void setup()
{
  // put your setup code here, to run once:
  AppServo.DeviceDriverSet_Servo_Init(90);

  for (int i = 0; i <= 180; i += 10)
  {
    AppServo.DeviceDriverSet_Servo_control(i);
  }

  for (int i = 180; i >= 90; i -= 10)
  {
    AppServo.DeviceDriverSet_Servo_control(i);
  }
}

void loop()
{


}
