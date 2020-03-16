#ifndef GAME_GAME_H
#define GAME_GAME_H

#include "window.h"
#include <SDL.h>
#include <SDL_image.h>

class AssetManager;

class Game {
  public:
    Game();
    ~Game();

    [[nodiscard]] bool isRunning() const;
    static SDL_Renderer* renderer;
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
    bool running {false};
    Window* window;
    int ticksLastFrame;
};

#endif
