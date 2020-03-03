#ifndef GAME_GAME_H
#define GAME_GAME_H

#include <SDL.h>
#include <SDL_image.h>

class AssetManager;

class Game {
  public:
    Game();
    ~Game();

    void initialize(int width, int height);
    bool isRunning() const;
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

  private:
    bool running;
    SDL_Window* window;
    int ticksLastFrame;
};

#endif
