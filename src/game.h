#ifndef GAME_GAME_H
#define GAME_GAME_H

#include <SDL.h>

class Game {
  public:
    Game();
    ~Game();

    void initialize(int width, int height);
    bool isRunning() const;
    void processInput();
    void update();
    void render();
    void destroy();

  private:
    bool running;
    SDL_Window* window;
    SDL_Renderer* renderer;
    int ticksLastFrame;
};

#endif
