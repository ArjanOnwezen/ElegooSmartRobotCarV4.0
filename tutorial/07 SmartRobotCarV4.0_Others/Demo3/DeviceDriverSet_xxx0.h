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
/*IRrecv*/
#include <IRremote.h>
class DeviceDriverSet_IRrecv
{
public:
  void DeviceDriverSet_IRrecv_Init(void);
  bool DeviceDriverSet_IRrecv_Get(uint8_t *IRrecv_Get /*out*/);
  void DeviceDriverSet_IRrecv_Test(void);

public:
  unsigned long IR_PreMillis;

private:
#define RECV_PIN 9

/*A:4294967295*/
#define aRECV_upper 16736925
#define aRECV_lower 16754775
#define aRECV_Left 16720605
#define aRECV_right 16761405
#define aRECV_ok 16712445
#define aRECV_1 16738455
#define aRECV_2 16750695
#define aRECV_3 16756815
#define aRECV_4 16724175
#define aRECV_5 16718055
#define aRECV_6 16743045
#define aRECV_7 16716015
#define aRECV_8 16726215
#define aRECV_9 16734885
// #define aRECV_ *16728765
// #define aRECV_0 16730805
// #define aRECV_ # 16732845
/*B:*/
#define bRECV_upper 5316027
#define bRECV_lower 2747854299
#define bRECV_Left 1386468383
#define bRECV_right 553536955
#define bRECV_ok 3622325019
#define bRECV_1 3238126971
#define bRECV_2 2538093563
#define bRECV_3 4039382595
#define bRECV_4 2534850111
#define bRECV_5 1033561079
#define bRECV_6 1635910171
#define bRECV_7 2351064443
#define bRECV_8 1217346747
#define bRECV_9 71952287
  // #define bRECV_ *851901943
  // #define bRECV_0 465573243
  // #define bRECV_ # 1053031451
};

#endif
