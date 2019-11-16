#include "Effect.h"
#include "../LightController.h"

#ifndef RANDOM_COLOR_CLASS_DEFINED
#define RANDOM_COLOR_CLASS_DEFINED

class RandomColors : public Effect {
private:
public:
	RandomColors(LightController& lightcontroller);
	void Tick();
};

#endif
