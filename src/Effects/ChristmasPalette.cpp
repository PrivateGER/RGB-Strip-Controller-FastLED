#include "ChristmasPalette.h"

ChristmasPalette::ChristmasPalette(LightController& lightcontroller) {
	lc = &lightcontroller;

 colors[0] = lc->createNewColor(0, 255, 0);
 colors[1] = lc->createNewColor(255, 178, 0);
 colors[2] = lc->createNewColor(255, 0, 0);


}

void ChristmasPalette::Tick() {
  if(internalClock <= 10) {
    internalClock++;
    return;
  }
  internalClock = 0;

	if(counter != 0) counter--;
  for(int i = 0; i < lc->getLEDCount(); i++) {
      if(counter > CHRISTMAS_COLOR_SIZE - 1) {
        counter = 0;
      }

      lc->setLEDColor(colors[counter], i, 128);
      counter++;
  }

	lc->updateLEDs();
}
