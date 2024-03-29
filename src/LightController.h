#include "FastLED.h"
#include <string.h>

#ifndef LIGHTCONTROLLERCLASS
#define LIGHTCONTROLLERCLASS

#define LED_COUNT 32
#define DATA_PIN 9
#define CLOCK_PIN 5

class LightController {
private:
  int clock = 0;
  int ledCount = LED_COUNT;
  CRGB leds[LED_COUNT];
public:
  LightController();
  int getLEDCount();
  int getLitLEDs();
  void blackAllLEDS();
  void updateLEDs();
  CRGB getLEDColor(int index);
  bool setLEDColor(CRGB color, int index, int brightness = NULL);
  CRGB createNewColor(int r, int g, int b);
};

#endif
