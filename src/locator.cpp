#include "locator.h"

SDL_Renderer* renderer;

SDL_Renderer* Locator::getRenderer() {
    return renderer;
}

void Locator::provide(SDL_Renderer* aRenderer) {
    renderer = aRenderer;
}
