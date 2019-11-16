#include "Effect.h"
#include "../LightController.h"

#ifndef BOUNCING_PIXEL_CLASS_DEFINED
#define BOUNCING_PIXEL_CLASS_DEFINED

class BouncingPixel : public Effect {
private:
  int counter = 0;
  boolean forwards = false;
  boolean flick = false;
  CRGB color;
public:
	BouncingPixel(LightController& lightcontroller);
	void Tick();
};

#endif
