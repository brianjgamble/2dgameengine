#ifndef GAME_WINDOW_H
#define GAME_WINDOW_H

#include <SDL_render.h>

class Window {
  public:
    Window(int width, int height);
    ~Window();

    [[nodiscard]] bool isActive() const;

    [[nodiscard]] SDL_Renderer* getRenderer() const;

  private:
    bool active {false};
    SDL_Window* window;
    SDL_Renderer* renderer;
};

#endif
