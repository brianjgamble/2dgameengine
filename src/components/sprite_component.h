#ifndef GAME_SPRITE_COMPONENT_H
#define GAME_SPRITE_COMPONENT_H

#include "../animation.h"
#include "../asset_manager.h"
#include "transform_component.h"
#include <SDL.h>

class SpriteComponent : public Component {
  public:
    explicit SpriteComponent(const std::string& assetTextureId);
    SpriteComponent(const std::string& assetTextureId, bool isFixed);
    SpriteComponent(const std::string& id, int numFrames, int animationSpeed,
                    bool hasDirections, bool isFixed);

    void setTexture(const std::string& assetTextureId);
    void initialize() override;
    void update(float deltaTime) override;
    void render() override;

    void animate(Movement movement);

  private:
    Texture* texture;
    Rectangle sourceRectangle;
    Rectangle destinationRectangle;
    TransformComponent* transform;
    bool isAnimated;
    unsigned int numFrames;
    unsigned int animationSpeed;
    bool isFixed;
    std::map<Movement, Animation> animations;
    Movement currentAnimation;
    unsigned int animationIndex = 0;
};

#endif
