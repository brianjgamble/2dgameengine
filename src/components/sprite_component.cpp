#include "sprite_component.h"

SpriteComponent::SpriteComponent(const std::string& filePath) {
    setTexture(filePath);
}

void SpriteComponent::setTexture(const std::string& assetTextureId) {
    texture = Game::assetManager->getTexture(assetTextureId);
}

void SpriteComponent::initialize() {
    transform         = owner->getComponent<TransformComponent>();
    sourceRectangle.x = 0;
    sourceRectangle.y = 0;
    sourceRectangle.w = transform->getWidth();
    sourceRectangle.h = transform->getHeight();
}

void SpriteComponent::update(float deltaTime) {
    destinationRectangle.x = (int)transform->getPosition().x;
    destinationRectangle.y = (int)transform->getPosition().y;
    destinationRectangle.w = transform->getWidth() * transform->getScale();
    destinationRectangle.h = transform->getHeight() * transform->getScale();
}

void SpriteComponent::render() {
    TextureManager::draw(texture, sourceRectangle, destinationRectangle,
                         spriteFlip);
}
