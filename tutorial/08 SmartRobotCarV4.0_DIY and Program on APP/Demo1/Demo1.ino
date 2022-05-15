#include "FastLED.h"
#define PIN_RBGLED 4
#define NUM_LEDS 1
CRGB leds[NUM_LEDS];


void setup() {
  Serial.begin(9600);
  FastLED.addLeds<NEOPIXEL, PIN_RBGLED>(leds, NUM_LEDS);
  FastLED.setBrightness(20);
}

void loop() {
  Event();
  delay(10);
}

void Event()
{
  int status = SerialPortDataAnalysis();
  if (status)
  {
    switch (status)
    {
      case 1: FastLED.showColor(Color(0, 0, 255)); break;
      case 2: FastLED.showColor(Color(255, 0, 255));break;
      case 3: FastLED.showColor(Color(0, 255, 255)); break;
      case 4: FastLED.showColor(Color(0, 255, 0)); break;
      default: break;
    }
  }
}


int SerialPortDataAnalysis(void)
{
  String SerialPortData = "";
  uint8_t c = "";
  if (Serial.available() > 0)
  {
    while (c != '}' && Serial.available() > 0)
    {
      c = Serial.read();
      SerialPortData += (char)c;
    }
    if (c == '}')
    {
      delay(50);
      return atoi((char*)(SerialPortData.substring(1, SerialPortData.length() - 1).c_str()));
    }
  }
  else
  {
    return 0;
  }
}

uint32_t Color(uint8_t r, uint8_t g, uint8_t b)
{
  return (((uint32_t)r << 16) | ((uint32_t)g << 8) | b);
}
