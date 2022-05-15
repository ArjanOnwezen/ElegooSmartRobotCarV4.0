#include "DeviceDriverSet_xxx0.h"

DeviceDriverSet_ITR20001 AppITR20001;

void setup() {
  Serial.begin(9600);
  AppITR20001.DeviceDriverSet_ITR20001_Init();
}

void loop() {
    static unsigned long print_time = 0;
    if (millis() - print_time > 500)
    {
      print_time = millis();
      Serial.print("ITR20001_getAnaloguexxx_L=");
      Serial.println(AppITR20001.DeviceDriverSet_ITR20001_getAnaloguexxx_L());
      Serial.print("ITR20001_getAnaloguexxx_M=");
      Serial.println(AppITR20001.DeviceDriverSet_ITR20001_getAnaloguexxx_M());
      Serial.print("ITR20001_getAnaloguexxx_R=");
      Serial.println(AppITR20001.DeviceDriverSet_ITR20001_getAnaloguexxx_R());
    }

}
