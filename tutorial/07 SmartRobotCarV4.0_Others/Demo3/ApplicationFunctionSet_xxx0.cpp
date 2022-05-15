/*
 * @Author: ELEGOO
 * @Date: 2019-10-22 11:59:09
 * @LastEditTime: 2020-06-28 14:10:45
 * @LastEditors: Changhua
 * @Description: conqueror robot tank
 * @FilePath: 
 */
#include <hardwareSerial.h>
#include <stdio.h>
#include <string.h>
#include "ApplicationFunctionSet_xxx0.h"
#include "DeviceDriverSet_xxx0.h"

#include "ArduinoJson-v6.11.1.h" //ArduinoJson

#define _is_print 1
#define _Test_print 0

DeviceDriverSet_IRrecv AppIRrecv;
/*f(x) int */
static boolean
function_xxx(long x, long s, long e) //f(x)
{
  if (s <= x && x <= e)
    return true;
  else
    return false;
}


/*模式控制序列*/
enum ConquerorCarFunctionalModel
{
  Standby_mode,           /*空闲模式*/
  TraceBased_mode,        /*循迹模式*/
  ObstacleAvoidance_mode, /*避障模式*/
  Follow_mode,            /*跟随模式*/
  Rocker_mode,            /*摇杆模式*/
};

struct Application_xxx
{
  ConquerorCarFunctionalModel Functional_Mode;
};

Application_xxx Application_ConquerorCarxxx0;

void ApplicationFunctionSet::ApplicationFunctionSet_Init(void)
{
  bool res_error = true;
  Serial.begin(9600);
  AppIRrecv.DeviceDriverSet_IRrecv_Init();
}

void ApplicationFunctionSet::ApplicationFunctionSet_IRrecv(void)
{
  uint8_t IRrecv_button;
  static bool IRrecv_en = false;
  if (AppIRrecv.DeviceDriverSet_IRrecv_Get(&IRrecv_button /*out*/))
  {
    IRrecv_en = true;
    //Serial.println(IRrecv_button);
  }
  if (true == IRrecv_en)
  {
    switch (IRrecv_button)
    {
    case /* constant-expression */ 1:
      /* code */
      Serial.println("Forward");
      break;
    case /* constant-expression */ 2:
      /* code */
      Serial.println("Backward");
      break;
    case /* constant-expression */ 3:
      /* code */
      Serial.println("Left");
      break;
    case /* constant-expression */ 4:
      /* code */
      Serial.println("Right");
      break;
    case /* constant-expression */ 5:
      /* code */
      Serial.println("Standby_mode");
      break;
    case /* constant-expression */ 6:
    Serial.println("TraceBased_mode");
      break;
    case /* constant-expression */ 7:
    Serial.println("ObstacleAvoidance_mode");
      break;
    case /* constant-expression */ 8:
    Serial.println("Follow_mode");
      break;
    default:
     Serial.println("Standby_mode");
      break;
    }
  }
}
