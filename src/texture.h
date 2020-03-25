#ifndef GAME_TEXTURE_H
#define GAME_TEXTURE_H

#include <SDL_rect.h>
#include <SDL_render.h>
#include <string>

class Texture {
  public:
    explicit Texture(const std::string& fileName);
    ~Texture();

    void draw(SDL_Rect sourceRectangle, SDL_Rect destinationRectangle,
              SDL_RendererFlip flip);

  private:
    SDL_Texture* texture;
};

#endif
