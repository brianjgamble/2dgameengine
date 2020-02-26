#ifndef GAME_GAME_H
#define GAME_GAME_H

#include <SDL.h>
#include <SDL_image.h>

class Game {
  public:
    Game();
    ~Game();

    void initialize(int width, int height);
    bool isRunning() const;
    static SDL_Renderer* renderer;
    void loadLevel(int levelNumber);
    void processInput();
    void update();
    void render();
    void destroy();

  private:
    bool running;
    SDL_Window* window;
    int ticksLastFrame;
};

#endif
