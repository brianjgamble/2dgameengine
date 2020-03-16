#include "renderer.h"
#include <iostream>

Renderer::Renderer(SDL_Window* window) {
    renderer = SDL_CreateRenderer(window, -1, 0);

    if (!renderer) {
        std::cerr << "Error creating SDL renderer." << std::endl;
        return;
    }
}

Renderer::~Renderer() {
    SDL_DestroyRenderer(renderer);
}

bool Renderer::isCreated() const {
    return renderer != nullptr;
}

SDL_Renderer* Renderer::toSDL() const {
    return renderer;
}
