#include <string.h>
#include "../LightController.h"

#ifndef EFFECT_BASE_CLASS
#define EFFECT_BASE_CLASS

class Effect {
protected:
  LightController *lc;
public:
  int id = NULL;
};

#endif
