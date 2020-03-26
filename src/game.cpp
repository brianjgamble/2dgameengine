#include "game.h"
#include "asset_manager.h"
#include "constants.h"
#include "levels.h"
#include "locator.h"
#include "map.h"
#include <iostream>

EntityManager manager;
AssetManager* Game::assetManager = new AssetManager(&manager);
SDL_Event Game::event;
Rectangle Game::camera {0, 0, WINDOW_WIDTH, WINDOW_HEIGHT};
Entity* mainPlayer = nullptr;

Game::~Game() {
    manager.cleanup();
    assetManager->cleanup();
}

void Game::run() {
    loadLevel(1);

    while (running) {
        processInput();
        update();
        render();
    }
}

void Game::loadLevel(int levelNumber) {
    Levels levels {assetManager, manager};
    levels.loadLevel(levelNumber);
    mainPlayer = manager.getPlayer();
}

void Game::processInput() {
    SDL_PollEvent(&event);

    switch (event.type) {
        case SDL_QUIT:
            running = false;
            break;

        case SDL_KEYDOWN:
            if (event.key.keysym.sym == SDLK_ESCAPE) {
                running = false;
            }

        default:
            break;
    }
}

void Game::update() {
    // Wait until 16ms has elapsed since the last frame
    auto elapsed = SDL_GetTicks() - ticksLastFrame;
    if (FRAME_TARGET_TIME > elapsed) {
        SDL_Delay(FRAME_TARGET_TIME - elapsed);
    }

    // Delta time is the difference in ticks from last frame
    // converted to seconds
    float deltaTime = (SDL_GetTicks() - ticksLastFrame) / 1000.0f;

    // Clamp deltaTime to a maximum value
    deltaTime = (deltaTime > 0.05f) ? 0.05f : deltaTime;

    // Sets the new ticks for the current frame to be used in the
    // next pass
    ticksLastFrame = SDL_GetTicks();

    manager.update(deltaTime);

    handleCameraMovement();
    checkCollisions();
}

void Game::render() {
    auto* r = Locator::getRenderer()->toSDL();

    SDL_SetRenderDrawColor(r, 21, 21, 21, 255);
    SDL_RenderClear(r);

    if (manager.hasNoEntities()) {
        return;
    }

    manager.render();

    SDL_RenderPresent(r);
}

void Game::handleCameraMovement() {
    if (mainPlayer) {
        mainPlayer->moveCamera(camera);
    }
}

void Game::checkCollisions() {
    switch (manager.checkCollisions()) {
        case CollisionType::player_enemy:
        case CollisionType::player_projectile:
            processGameOver();
            break;

        case CollisionType::player_level_complete:
            processNextLevel(1);
            break;

        default:
            return;
    }
}

void Game::processNextLevel(int levelNumber) {
    std::cout << "Next Level" << std::endl;
    running = false;
}

void Game::processGameOver() {
    std::cout << "Game Over" << std::endl;
    running = false;
}
