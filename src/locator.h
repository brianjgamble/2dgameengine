#ifndef GAME_LOCATOR_H
#define GAME_LOCATOR_H

#include <SDL_render.h>
class Locator {
  public:
    static SDL_Renderer* getRenderer();
    static void provide(SDL_Renderer* aRenderer);
};

#endif
