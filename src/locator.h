#ifndef GAME_LOCATOR_H
#define GAME_LOCATOR_H

#include "renderer.h"

class Locator {
  public:
    static Renderer* getRenderer();
    static void provide(Renderer* aRenderer);
};

#endif
