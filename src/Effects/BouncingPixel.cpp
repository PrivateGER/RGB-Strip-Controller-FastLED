#include "BouncingPixel.h"

BouncingPixel::BouncingPixel(LightController& lightcontroller) {
	lc = &lightcontroller;
}

void BouncingPixel::Tick() {
	if(counter + 1 > (lc->getLEDCount() - 1)) {
		forwards = false;
	} else if (counter - 1 < 0) {
		forwards = true;
	}

	CRGB newColor;

	if(forwards) {
		newColor = new CRGB(0, 255, 0);
		counter++;
	} else {
		newColor = new CRGB(255, 0, 0);
		counter--;
	}

	lc->setLEDColor(newColor, counter, 128);
	lc->updateLEDs();
}
