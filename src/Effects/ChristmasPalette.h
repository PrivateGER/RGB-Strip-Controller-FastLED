#include "Effect.h"
#include "../LightController.h"

#ifndef CHRISTMAS_PALETTE_CLASS_DEFINED
#define CHRISTMAS_PALETTE_CLASS_DEFINED

#define CHRISTMAS_COLOR_SIZE 3

class ChristmasPalette : public Effect {
private:
	int counter = 0;
	int internalClock = 0;
	CRGB colors[CHRISTMAS_COLOR_SIZE];
public:
	ChristmasPalette(LightController& lightcontroller);
	void Tick();
};

#endif
