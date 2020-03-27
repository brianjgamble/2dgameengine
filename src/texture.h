#ifndef GAME_TEXTURE_H
#define GAME_TEXTURE_H

#include "rectangle.h"
#include <SDL_rect.h>
#include <SDL_render.h>
#include <string>

class Texture {
  public:
    explicit Texture(const std::string& fileName);
    ~Texture();

    void draw(Rectangle srcRect, Rectangle destRect);

  private:
    SDL_Texture* texture;
};

#endif
