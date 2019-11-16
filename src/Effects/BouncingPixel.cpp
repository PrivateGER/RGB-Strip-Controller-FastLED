#include "BouncingPixel.h"

BouncingPixel::BouncingPixel(LightController& lightcontroller) {
  lc = &lightcontroller;
  color = lc->createNewColor(255, 0, 0);
}

void BouncingPixel::Tick() {
  lc->blackAllLEDS();

  if(counter + 1 > lc->getLEDCount() - 1) {
		forwards = false;
		flick = true;
	} else if (counter - 1 < 0) {
		forwards = true;
		flick = true;
	}

  if(forwards) {
		counter++;
	} else {
		counter--;
	}

	if(flick) {
		flick = false;
		if(forwards) {
			lc->setLEDColor(color, 0, 128);
		} else {
			lc->setLEDColor(color, lc->getLEDCount()-1, 128);
		}
	}

  lc->setLEDColor(color, counter, 128);

	lc->updateLEDs();
}
