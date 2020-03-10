#ifndef GAME_GAME_H
#define GAME_GAME_H

#include "../lib/sol/sol.hpp"
#include <SDL.h>
#include <SDL_image.h>

class AssetManager;

class Game {
  public:
    Game();
    ~Game() = default;

    void initialize(int width, int height);
    [[nodiscard]] bool isRunning() const;
    static SDL_Renderer* renderer;
    static AssetManager* assetManager;
    static SDL_Event event;
    static SDL_Rect camera;
    void loadLevel(int levelNumber);
    void processInput();
    void update();
    void render();
    void destroy();
    void handleCameraMovement();
    void checkCollisions();
    void processNextLevel(int levelNumber);
    void processGameOver();

  private:
    bool running;
    SDL_Window* window;
    int ticksLastFrame;
};

#endif
