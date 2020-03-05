#ifndef GAME_FONT_MANAGER_H
#define GAME_FONT_MANAGER_H

#include "game.h"
#include <SDL_ttf.h>

class FontManager {
  public:
    static TTF_Font* LoadFont(const char* fileName, int fontSize);
    static void Draw(SDL_Texture* texture, SDL_Rect position);
};

#endif
