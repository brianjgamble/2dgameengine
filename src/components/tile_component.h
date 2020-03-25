#ifndef GAME_TILE_COMPONENT_H
#define GAME_TILE_COMPONENT_H

#include "../../lib/glm/glm.hpp"
#include "../asset_manager.h"
#include "../entity_manager.h"
#include <SDL.h>

class TileComponent : public Component {
  public:
    TileComponent(int sourceRectX, int sourceRectY, int x, int y, int tileSize,
                  int tileScale, const std::string& assetTextureId);

    void initialize() override {}
    void update(float deltaTime) override;
    void render() override;

  private:
    Texture* texture;
    SDL_Rect sourceRectangle;
    SDL_Rect destinationRectangle;
    glm::vec2 position;
};

#endif
