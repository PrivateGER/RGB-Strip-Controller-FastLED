#include "RandomColors.h"

RandomColors::RandomColors(LightController& lightcontroller) {
  lc = &lightcontroller;
}

void RandomColors::Tick() {
  for(int i = 0; i < lc->getLEDCount(); i++) {
      CRGB color = lc->createNewColor(random(0, 255), random(0, 255), random(0, 255));
      lc->setLEDColor(color, i, 128);
  }
  lc->updateLEDs();
}
