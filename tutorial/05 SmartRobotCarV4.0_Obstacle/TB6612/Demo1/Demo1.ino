/*
 * @Author: ELEGOO
 * @Date: 2019-10-22 11:59:09
 * @LastEditTime: 2020-06-28 14:55:26
 * @LastEditors: Changhua
 * @Description: conqueror robot tank
 * @FilePath: 
 */
#include <avr/wdt.h>
#include "DeviceDriverSet_xxx0.h"

DeviceDriverSet_ULTRASONIC myUltrasonic;

void setup()
{
  Serial.begin(9600);
  myUltrasonic.DeviceDriverSet_ULTRASONIC_Init();
}

void loop()
{
  myUltrasonic.DeviceDriverSet_ULTRASONIC_Test();
}
