#ifndef GAME_GAME_H
#define GAME_GAME_H

#include <SDL.h>
#include <SDL_image.h>

class AssetManager;

class Game {
  public:
    Game() : running {true}, ticksLastFrame {0} {}
    ~Game();

    void run();
    static AssetManager* assetManager;
    static SDL_Event event;
    static SDL_Rect camera;
    void loadLevel(int levelNumber);
    void processInput();
    void update();
    void render();
    void handleCameraMovement();
    void checkCollisions();
    void processNextLevel(int levelNumber);
    void processGameOver();

  private:
    bool running;
    int ticksLastFrame;
};

#endif
