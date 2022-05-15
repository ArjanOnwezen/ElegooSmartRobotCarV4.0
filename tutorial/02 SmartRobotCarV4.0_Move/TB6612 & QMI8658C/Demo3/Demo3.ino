#include <avr/wdt.h>
#include "QMI8658C.h"


QMI8658C AppQMI8658C;

void setup() {
  Serial.begin(9600);
  AppQMI8658C.QMI8658C_dveInit();
  delay(2000);
  AppQMI8658C.QMI8658C_calibration();
}

void loop() {
  static float Yaw;
  AppQMI8658C.QMI8658C_dveGetEulerAngles(&Yaw);
  Serial.print("Yaw:");
  Serial.println(Yaw);
}
