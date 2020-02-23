#include "game.h"
#include "../lib/glm/glm.hpp"
#include "constants.h"
#include "entity_manager.h"
#include <iostream>

EntityManager manager;
SDL_Renderer* Game::renderer;

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

    running = true;
}

void Game::processInput() {
    SDL_Event event;
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

    // TODO:
    // here we call the manager.update to update all entities as
    // a function of deltaTime
}

void Game::render() {
    SDL_SetRenderDrawColor(renderer, 21, 21, 21, 255);
    SDL_RenderClear(renderer);

    // TODO:
    // here we call the amanger render to render all entities

    SDL_RenderPresent(renderer);
}

void Game::destroy() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Game::loadLevel(int levelNumber) {}
