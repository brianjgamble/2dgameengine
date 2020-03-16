#ifndef GAME_RENDERER_H
#define GAME_RENDERER_H

#include <SDL_render.h>

class Renderer {
  public:
    explicit Renderer(SDL_Window* window);
    ~Renderer();

    [[nodiscard]] bool isCreated() const;
    [[nodiscard]] SDL_Renderer* toSDL() const;

  private:
    SDL_Renderer* renderer;
};

#endif
