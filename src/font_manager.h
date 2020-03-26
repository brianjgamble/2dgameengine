#ifndef GAME_FONT_MANAGER_H
#define GAME_FONT_MANAGER_H

#include "rectangle.h"
#include <SDL_ttf.h>
#include <string>

class FontManager {
  public:
    static TTF_Font* loadFont(const std::string& fileName, int fontSize);
    static void draw(SDL_Texture* texture, Rectangle position);
};

#endif
