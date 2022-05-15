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

#define _is_print 1
#define _Test_print 0

DeviceDriverSet_Key AppKey;

/*f(x) int */
static boolean
function_xxx(long x, long s, long e) //f(x)
{
  if (s <= x && x <= e)
    return true;
  else
    return false;
}

/*运动方向控制序列*/
enum ConquerorCarMotionControl
{
  Forward,       //(1)
  Backward,      //(2)
  Left,          //(3)
  Right,         //(4)
  LeftForward,   //(5)
  LeftBackward,  //(6)
  RightForward,  //(7)
  RightBackward, //(8)
  stop_it        //(9)
};               //direction方向:（1）、（2）、 （3）、（4）、（5）、（6）

/*模式控制序列*/
enum ConquerorCarFunctionalModel
{
  Standby_mode,           /*空闲模式*/
  TraceBased_mode,        /*循迹模式*/
  ObstacleAvoidance_mode, /*避障模式*/
  Follow_mode,            /*跟随模式*/
  Rocker_mode,            /*摇杆模式*/
};

/*控制管理成员*/
struct Application_xxx
{
  ConquerorCarMotionControl Motion_Control;
  ConquerorCarFunctionalModel Functional_Mode;
  unsigned long CMD_CarControl_Millis;
  unsigned long CMD_LightingControl_Millis;
};
Application_xxx Application_ConquerorCarxxx0;

bool ApplicationFunctionSet_ConquerorCarLeaveTheGround(void);
void ApplicationFunctionSet_ConquerorCarLinearMotionControl(ConquerorCarMotionControl direction, uint8_t directionRecord, uint8_t speed, uint8_t Kp, uint8_t UpperLimit);
void ApplicationFunctionSet_ConquerorCarMotionControl(ConquerorCarMotionControl direction, uint8_t is_speed);

void ApplicationFunctionSet::ApplicationFunctionSet_Init(void)
{
  bool res_error = true;
  Serial.begin(9600);
  AppKey.DeviceDriverSet_Key_Init();
  while (Serial.read() >= 0)
  {
    /*清空串口缓存...*/
  }
  Application_ConquerorCarxxx0.Functional_Mode = Standby_mode;
}

/*按键命令*/
void ApplicationFunctionSet::ApplicationFunctionSet_KeyCommand(void)
{
  uint8_t get_keyValue;
  static uint8_t temp_keyValue = keyValue_Max;
  AppKey.DeviceDriverSet_key_Get(&get_keyValue);

  if (temp_keyValue != get_keyValue)
  {
    temp_keyValue = get_keyValue;
    switch (get_keyValue)
    {
    case /* constant-expression */ 1:
      /* code */
      Application_ConquerorCarxxx0.Functional_Mode = TraceBased_mode;
      Serial.println("Now is TraceBased_mode");
      break;
    case /* constant-expression */ 2:
      /* code */
      Application_ConquerorCarxxx0.Functional_Mode = ObstacleAvoidance_mode;
      Serial.println("Now is ObstacleAvoidance_mode");
      break;
    case /* constant-expression */ 3:
      /* code */
      Application_ConquerorCarxxx0.Functional_Mode = Follow_mode;
      Serial.println("Now is Follow_mode");
      break;
    case /* constant-expression */ 4:
      /* code */
      Application_ConquerorCarxxx0.Functional_Mode = Standby_mode;
      Serial.println("Now is Standby_mode");
      break;
    default:

      break;
    }
  }
}
