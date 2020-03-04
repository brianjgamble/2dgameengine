#ifndef GAME_COLLISION_H
#define GAME_COLLISION_H

#include <SDL.h>

class Collision {
  public:
    static bool checkRectangleCollision(const SDL_Rect& rectangleA,
                                        const SDL_Rect& rectangleB);
};

#endif
