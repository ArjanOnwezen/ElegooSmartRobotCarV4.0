/*
 * @Author: ELEGOO
 * @Date: 2019-10-22 11:59:09
 * @LastEditTime: 2020-06-12 14:45:27
 * @LastEditors: Changhua
 * @Description: conqueror robot tank
 * @FilePath: 
 */
#ifndef _DeviceDriverSet_xxx0_H_
#define _DeviceDriverSet_xxx0_H_

#define _Test_DeviceDriverSet 0
#include <arduino.h>


/*Key Detection*/
class DeviceDriverSet_Key
{
public:
  void DeviceDriverSet_Key_Init(void);
#if _Test_DeviceDriverSet
  void DeviceDriverSet_Key_Test(void);
#endif
  void DeviceDriverSet_key_Get(uint8_t *get_keyValue);

public:
#define PIN_Key 2
#define keyValue_Max 4
public:
  static uint8_t keyValue;
};

#endif
