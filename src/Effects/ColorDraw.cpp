#include "ColorDraw.h"

ColorDraw::ColorDraw(LightController& lightcontroller) {
	lc = &lightcontroller;
}

void ColorDraw::Tick() {
	if(counter + 1 > lc->getLEDCount() - 1) {
		forwards = false;
		flick = true;
	} else if (counter - 1 < 0) {
		forwards = true;
		flick = true;
	}

	CRGB newColor;

	if(forwards) {
		newColor = lc->createNewColor(0, 255, 0);
		counter++;
	} else {
		newColor = lc->createNewColor(255, 0, 0);
		counter--;
	}

	if(flick) {
		flick = false;
		if(forwards) {
			lc->setLEDColor(newColor, 0, 128);
		} else {
			lc->setLEDColor(newColor, lc->getLEDCount()-1, 128);
		}
	}

	lc->setLEDColor(newColor, counter, 128);
	lc->updateLEDs();
}
