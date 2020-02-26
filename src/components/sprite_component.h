#ifndef GAME_SPRITE_COMPONENT_H
#define GAME_SPRITE_COMPONENT_H

#include "../asset_manager.h"
#include "../component.h"
#include "../texture_manager.h"
#include "transform_component.h"
#include <SDL.h>

class SpriteComponent : public Component {
  public:
    explicit SpriteComponent(const std::string& filePath);

    void setTexture(const std::string& assetTextureId);
    void initialize() override;
    void update(float deltaTime) override;
    void render() override;

  private:
    SDL_Texture* texture;
    SDL_Rect sourceRectangle;
    SDL_Rect destinationRectangle;
    SDL_RendererFlip spriteFlip = SDL_FLIP_NONE;
    TransformComponent* transform;
};

#endif
