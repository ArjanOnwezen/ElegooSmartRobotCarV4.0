#include <avr/wdt.h>
#include "MPU6050.h"
#include "MPU6050_getdata.h"

MPU6050_getdata AppMPU6050getdata;

void setup() {
  Serial.begin(9600);
  AppMPU6050getdata.MPU6050_dveInit();
  delay(2000);
  AppMPU6050getdata.MPU6050_calibration();
}

void loop() {
    static float Yaw;
    AppMPU6050getdata.MPU6050_dveGetEulerAngles(&Yaw);
    Serial.print("Yaw:");
    Serial.println(Yaw);
}
