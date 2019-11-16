#include "Effect.h"
#include "../LightController.h"

#ifndef COLOR_DRAW_CLASS_DEFINED
#define COLOR_DRAW_CLASS_DEFINED

class ColorDraw : public Effect {
private:
	int counter = 0;
	bool forwards = true;
	bool flick = false;
public:
	ColorDraw(LightController& lightcontroller);
	void Tick();
};

#endif
