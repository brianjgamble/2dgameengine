#ifndef GAME_WINDOW_H
#define GAME_WINDOW_H

#include "renderer.h"

class Window {
  public:
    Window(int width, int height);
    ~Window();

    [[nodiscard]] bool isActive() const;
    [[nodiscard]] Renderer* getRenderer() const;

  private:
    bool active {false};
    SDL_Window* window;
    Renderer* renderer;
};

#endif
