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
#include "ArduinoJson-v6.11.1.h" //ArduinoJson
#define _is_print 1
#define _Test_print 1

ApplicationFunctionSet Application_FunctionSet;

/*f(x) int */
static boolean
function_xxx(long x, long s, long e) //f(x)
{
  if (s <= x && x <= e)
    return true;
  else
    return false;
}

void ApplicationFunctionSet::ApplicationFunctionSet_Init(void)
{
  bool res_error = true;
  Serial.begin(9600);
}


/*串口数据解析*/
void ApplicationFunctionSet::ApplicationFunctionSet_SerialPortDataAnalysis(void)
{
  static String SerialPortData = "";
  uint8_t c = "";
  if (Serial.available() > 0)
  {
    while (c != '}' && Serial.available() > 0)
    {
      // while (Serial.available() == 0)//强行等待一帧数据完成接收
      //   ;
      c = Serial.read();
      SerialPortData += (char)c;
    }
  }
  if (c == '}') //数据帧尾部校验
  {
#if _Test_print
    Serial.println(SerialPortData);
#endif

    StaticJsonDocument<200> doc;                                       //声明一个JsonDocument对象
    DeserializationError error = deserializeJson(doc, SerialPortData); //反序列化JSON数据
    SerialPortData = "";
    if (error)
    {
      Serial.println("error:deserializeJson");
    }
    else if (!error) //检查反序列化是否成功
    {
      int control_mode_N = doc["N"];
      char buf[3];
      uint8_t temp = doc["H"];
      sprintf(buf, "%d", temp);
      CommandSerialNumber = buf; //获取新命令的序号

      /*以下代码块请结合通讯协议V.docx 查看*/
      switch (control_mode_N)
      {
     case 1: /*<命令：N 1> */
        break;
      case 2: /*<命令：N 2>*/
        break;
      case 3: /*<命令：N 3>*/
        break;
      case 4: /*<命令：N 4>*/
        break;
      case 5: /*<命令：N 5>*/
        break;
      case 6: /*<命令：N 6>*/
        break;
      case 7: /*<命令：N 7>*/
        break;
      case 8: /*<命令：N 8>*/
        break;
      case 9: /*<命令：N 9>*/
        break;
      case 10: /*<命令：N 10>*/
        break;
      case 21: /*<命令：N 21>*/
        break;
      case 22: /*<命令：N 22>*/
        break;
      case 23: /*<命令：N 23>*/
        break;
      case 103: /*<命令：N 103>*/
        break;
      case 110: /*<命令：N 110>*/
        break;
      case 100: /*<命令：N 100>*/
        break;
      case 101: /*<命令：N 101>*/
        break;
      case 104: /*<命令：N 104>*/
        break;
      case 105: /*<命令：N 105>*/
        break;
      case 102: /*<命令：N 102>*/
        break;
      default:
        break;
      }
    }
  }
}
