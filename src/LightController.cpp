#include "LightController.h"
#include "FastLED.h"
#include "Arduino.h"

LightController::LightController() {
  FastLED.addLeds<WS2801, DATA_PIN, CLOCK_PIN, RGB>(leds, ledCount).setCorrection(TypicalLEDStrip);
}

int LightController::getLEDCount() {
  return sizeof(leds) / sizeof(CRGB);
}

int LightController::getLitLEDs() {
  int s = 0;
  for(int i = 0; i < ledCount; i++) {
    Serial.println(leds[i].r);
  }
}

void LightController::blackAllLEDS() {
  for(int i = 0; i < ledCount; i++) {
    leds[i] = CRGB::Black;
  }
}

CRGB LightController::getLEDColor(int index) {
  if((index < 0 && index > ledCount)) {
    Serial.println("Failed to set LED color due to invalid index.");
    return NULL;
  }

  return leds[index];
}

bool LightController::setLEDColor(CRGB color, int index, int brightness = NULL) {
  if((index < 0 && index > ledCount)) {
    Serial.println("Failed to set LED color due to invalid index.");
    return false;
  }

  if(brightness != NULL) {
    if(brightness < 0 && brightness >= 255) {
      Serial.println("Failed to set LED color due to invalid brightness.");
      return false;
    } else {
      FastLED.setBrightness(brightness);
    }
  }

  leds[index] = color;
}

void LightController::updateLEDs() {
  FastLED.show();
}
