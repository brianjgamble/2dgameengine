#include "tile_component.h"
#include "../game.h"

TileComponent::TileComponent(int sourceRectX, int sourceRectY, int x, int y,
                             int tileSize, int tileScale,
                             const std::string& assetTextureId)
    : sourceRectangle {sourceRectX, sourceRectY, tileSize, tileSize},
      destinationRectangle {x, y, tileSize * tileScale, tileSize * tileScale} {
    texture = Game::assetManager->getTexture(assetTextureId);

    position.x = x;
    position.y = y;
}

void TileComponent::update(float deltaTime) {
    auto coord = Game::camera.getCoordinate();
    int x      = static_cast<int>(position.x) - coord.x;
    int y      = static_cast<int>(position.y) - coord.y;

    destinationRectangle.moveTo(Coordinate {x, y});
}

void TileComponent::render() {
    texture->draw(sourceRectangle, destinationRectangle, SDL_FLIP_NONE);
}
