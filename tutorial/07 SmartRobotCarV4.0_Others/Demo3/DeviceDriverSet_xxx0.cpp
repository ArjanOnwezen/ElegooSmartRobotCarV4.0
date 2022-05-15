/*
 * @Author: ELEGOO
 * @Date: 2019-10-22 11:59:09
 * @LastEditTime: 2020-06-12 16:36:20
 * @LastEditors: Changhua
 * @Description: conqueror robot tank
 * @FilePath: 
 */
#include "DeviceDriverSet_xxx0.h"

/*IRrecv*/
IRrecv irrecv(RECV_PIN); //  Create an infrared receive drive object
decode_results results;  //  Create decoding object
void DeviceDriverSet_IRrecv::DeviceDriverSet_IRrecv_Init(void)
{
  irrecv.enableIRIn(); //Enable infrared communication NEC
}
bool DeviceDriverSet_IRrecv::DeviceDriverSet_IRrecv_Get(uint8_t *IRrecv_Get /*out*/)
{
  if (irrecv.decode(&results))
  {
    IR_PreMillis = millis();
    switch (results.value)
    {
    case /* constant-expression */ aRECV_upper:
    case /* constant-expression */ bRECV_upper:
      /* code */ *IRrecv_Get = 1;
      break;
    case /* constant-expression */ aRECV_lower:
    case /* constant-expression */ bRECV_lower:
      /* code */ *IRrecv_Get = 2;
      break;
    case /* constant-expression */ aRECV_Left:
    case /* constant-expression */ bRECV_Left:
      /* code */ *IRrecv_Get = 3;
      break;
    case /* constant-expression */ aRECV_right:
    case /* constant-expression */ bRECV_right:
      /* code */ *IRrecv_Get = 4;
      break;
    case /* constant-expression */ aRECV_ok:
    case /* constant-expression */ bRECV_ok:
      /* code */ *IRrecv_Get = 5;
      break;

    case /* constant-expression */ aRECV_1:
    case /* constant-expression */ bRECV_1:
      /* code */ *IRrecv_Get = 6;
      break;
    case /* constant-expression */ aRECV_2:
    case /* constant-expression */ bRECV_2:
      /* code */ *IRrecv_Get = 7;
      break;
    case /* constant-expression */ aRECV_3:
    case /* constant-expression */ bRECV_3:
      /* code */ *IRrecv_Get = 8;
      break;
    case /* constant-expression */ aRECV_4:
    case /* constant-expression */ bRECV_4:
      /* code */ *IRrecv_Get = 9;
      break;
    case /* constant-expression */ aRECV_5:
    case /* constant-expression */ bRECV_5:
      /* code */ *IRrecv_Get = 10;
      break;
    case /* constant-expression */ aRECV_6:
    case /* constant-expression */ bRECV_6:
      /* code */ *IRrecv_Get = 11;
      break;
    default:
      // *IRrecv_Get = 5;
      irrecv.resume();
      return false;
      break;
    }
    irrecv.resume();
    return true;
  }
  else
  {
    return false;
  }
}

#if _Test_DeviceDriverSet
void DeviceDriverSet_IRrecv::DeviceDriverSet_IRrecv_Test(void)
{
  if (irrecv.decode(&results))
  {
    Serial.print("IRrecv_Test:");
    Serial.println(results.value);
    irrecv.resume();
  }
}
#endif
