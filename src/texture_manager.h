#ifndef GAME_TEXTURE_MANAGER_H
#define GAME_TEXTURE_MANAGER_H

#include "game.h"
#include <string>

class TextureManager {
  public:
    static SDL_Texture* loadTexture(const std::string& fileName);
    static void draw(SDL_Texture* texture, SDL_Rect sourceRectangle,
                     SDL_Rect destinationRectangle, SDL_RendererFlip flip);
};

#endif
