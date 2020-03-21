#include "locator.h"

Renderer* renderer;

Renderer* Locator::getRenderer() {
    return renderer;
}

void Locator::provide(Renderer* aRenderer) {
    renderer = aRenderer;
}
