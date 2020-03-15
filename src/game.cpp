#include "game.h"
#include "asset_manager.h"
#include "components/text_label_component.h"
#include "constants.h"
#include "levels.h"
#include "map.h"
#include <iostream>

EntityManager manager;
SDL_Renderer* Game::renderer;
AssetManager* Game::assetManager = new AssetManager(&manager);
SDL_Event Game::event;
SDL_Rect Game::camera {0, 0, WINDOW_WIDTH, WINDOW_HEIGHT};
Entity* mainPlayer = nullptr;
Map* map;

Game::Game() {
    running = false;
}

bool Game::isRunning() const {
    return running;
}

void Game::initialize(int width, int height) {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cerr << "Error initializing SDL." << std::endl;
        return;
    }

    if (TTF_Init() != 0) {
        std::cerr << "Error initializing SDL TTF" << std::endl;
        return;
    }

    window = SDL_CreateWindow(nullptr, SDL_WINDOWPOS_CENTERED,
                              SDL_WINDOWPOS_CENTERED, width, height,
                              SDL_WINDOW_BORDERLESS);
    if (!window) {
        std::cerr << "Error creating SDL window." << std::endl;
        return;
    }

    renderer = SDL_CreateRenderer(window, -1, 0);
    if (!renderer) {
        std::cerr << "Error creating SDL renderer." << std::endl;
        return;
    }

    loadLevel(1);

    running = true;
}

void Game::loadLevel(int levelNumber) {
    Levels levels {assetManager, manager, map};
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
    SDL_SetRenderDrawColor(renderer, 21, 21, 21, 255);
    SDL_RenderClear(renderer);

    if (manager.hasNoEntities()) {
        return;
    }

    manager.render();

    SDL_RenderPresent(renderer);
}

void Game::destroy() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
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
