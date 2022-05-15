/*
 * @Author: ELEGOO
 * @Date: 2019-10-22 11:59:09
 * @LastEditTime: 2020-06-19 15:46:13
 * @LastEditors: Changhua
 * @Description: SmartRobot robot tank
 * @FilePath: 
 */
#ifndef _ApplicationFunctionSet_xxx0_H_
#define _ApplicationFunctionSet_xxx0_H_

#include <arduino.h>

class ApplicationFunctionSet
{
public:
  void ApplicationFunctionSet_Init(void);
  void ApplicationFunctionSet_Obstacle(void);           //避障
  
private:
  volatile uint16_t UltrasoundData_mm; //超声波数据
  volatile uint16_t UltrasoundData_cm; //超声波数据
  boolean UltrasoundDetectionStatus = false;
public:
  boolean Car_LeaveTheGround = true;
  const int ObstacleDetection = 20;
};
extern ApplicationFunctionSet Application_FunctionSet;
#endif
