#include "video_manager.h"
#include "constants.h"
#include "locator.h"
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <iostream>

void VideoManager::startUp() {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cerr << "Error initializing SDL." << std::endl;
        return;
    }

    if (TTF_Init() != 0) {
        std::cerr << "Error initializing SDL TTF" << std::endl;
        return;
    }

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        std::cerr << "SDL_mixer could not initialize! SDL_mixer Error: "
                  << Mix_GetError() << std::endl;
        return;
    }

    window = SDL_CreateWindow(nullptr, SDL_WINDOWPOS_CENTERED,
                              SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH,
                              WINDOW_HEIGHT, SDL_WINDOW_BORDERLESS);
    if (!window) {
        std::cerr << "Error creating SDL window." << std::endl;
        return;
    }

    renderer = new Renderer(window);

    if (renderer->isCreated()) {
        Locator::provide(renderer);
        started = true;
    }
}

void VideoManager::shutDown() {
    delete renderer;
    Mix_CloseAudio();
    TTF_Quit();
    SDL_DestroyWindow(window);
    SDL_Quit();
}

bool VideoManager::isStarted() const {
    return started;
}
