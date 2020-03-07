#ifndef GAME_FONT_MANAGER_H
#define GAME_FONT_MANAGER_H

#include "game.h"
#include <SDL_ttf.h>
#include <string>

class FontManager {
  public:
    static TTF_Font* loadFont(const std::string& fileName, int fontSize);
    static void draw(SDL_Texture* texture, SDL_Rect position);
};

#endif
