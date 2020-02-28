#include "game.h"
#include "../lib/glm/glm.hpp"
#include "asset_manager.h"
#include "components/keyboard_control_component.h"
#include "components/sprite_component.h"
#include "components/transform_component.h"
#include "constants.h"
#include <iostream>

EntityManager manager;
SDL_Renderer* Game::renderer;
AssetManager* Game::assetManager = new AssetManager(&manager);
SDL_Event Game::event;

Game::Game() {
    running = false;
}

Game::~Game() {}

bool Game::isRunning() const {
    return running;
}

void Game::initialize(int width, int height) {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cerr << "Error initializing SDL." << std::endl;
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

    loadLevel(0);

    running = true;
}

void Game::loadLevel(int levelNumber) {
    assetManager->addTexture("tank-image",
                             "./assets/images/tank-big-right.png");
    assetManager->addTexture("chopper-image",
                             "./assets/images/chopper-spritesheet.png");
    assetManager->addTexture("radar-image", "./assets/images/radar.png");

    Entity& chopperEntity(manager.addEntity("chopper"));
    chopperEntity.addComponent<TransformComponent>(240, 106, 0, 0, 32, 32, 1);
    chopperEntity.addComponent<SpriteComponent>("chopper-image", 2, 90, true,
                                                false);
    chopperEntity.addComponent<KeyboardControlComponent>("up", "right", "down",
                                                         "left", "space");

    Entity& tankEntity(manager.addEntity("tank"));
    tankEntity.addComponent<TransformComponent>(0, 0, 20, 20, 32, 32, 1);
    tankEntity.addComponent<SpriteComponent>("tank-image");

    Entity& radarEntity(manager.addEntity("Radar"));
    radarEntity.addComponent<TransformComponent>(720, 15, 0, 0, 64, 64, 1);
    radarEntity.addComponent<SpriteComponent>("radar-image", 8, 150, false,
                                              true);
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
