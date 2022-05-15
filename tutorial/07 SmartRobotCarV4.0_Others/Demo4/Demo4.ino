#define VOL_MEASURE_PIN A3
unsigned long vol_measure_time = 0;

void setup() {
  Serial.begin(9600);
  voltageInit();
}


void loop() 
{
    Voltage_Measure();
}

void voltageInit()
{
  pinMode(VOL_MEASURE_PIN, INPUT);
}

void Voltage_Measure()
{
    if (millis() - vol_measure_time > 1000) //Measured every 1000 milliseconds
  {
    vol_measure_time = millis();
    float voltage = (analogRead(VOL_MEASURE_PIN) * 5 ) * ((10 + 1.5) / 1.5)/ 1024; //Read voltage value
     //float voltage = (analogRead(VOL_MEASURE_PIN) * 0.0375);
    voltage = voltage + (voltage * 0.08);
    Serial.print("Current voltage value : ");
    Serial.println(voltage);
    if(voltage>7.8)
      Serial.println("The battery is fully charged");
    else
      Serial.println("Low battery");
  }
}
