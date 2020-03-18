#include "sprite_component.h"
#include "../game.h"

SpriteComponent::SpriteComponent(const std::string& assetTextureId) {
    isAnimated = false;
    isFixed    = false;
    setTexture(assetTextureId);
}

SpriteComponent::SpriteComponent(const std::string& assetTextureId,
                                 bool isFixed) {
    this->isAnimated = false;
    this->isFixed    = isFixed;
    setTexture(assetTextureId);
}

SpriteComponent::SpriteComponent(std::string id, int numFrames,
                                 int animationSpeed, bool hasDirections,
                                 bool isFixed) {
    isAnimated           = true;
    this->numFrames      = numFrames;
    this->animationSpeed = animationSpeed;
    this->isFixed        = isFixed;

    if (hasDirections) {
        Animation downAnimation  = Animation(0, numFrames, animationSpeed);
        Animation rightAnimation = Animation(1, numFrames, animationSpeed);
        Animation leftAnimation  = Animation(2, numFrames, animationSpeed);
        Animation upAnimation    = Animation(3, numFrames, animationSpeed);

        animations.emplace(Direction::down, downAnimation);
        animations.emplace(Direction::right, rightAnimation);
        animations.emplace(Direction::left, leftAnimation);
        animations.emplace(Direction::up, upAnimation);

        this->animationIndex   = 0;
        this->currentAnimation = Direction::down;
    }
    else {
        Animation singleAnimation = Animation(0, numFrames, animationSpeed);
        animations.emplace(Direction::none, singleAnimation);
        this->animationIndex   = 0;
        this->currentAnimation = Direction::none;
    }
    animate(this->currentAnimation);
    setTexture(id);
}

void SpriteComponent::setTexture(const std::string& assetTextureId) {
    texture = Game::assetManager->getTexture(assetTextureId);
}

void SpriteComponent::initialize() {
    transform         = owner->getComponent<TransformComponent>();
    sourceRectangle.x = 0;
    sourceRectangle.y = 0;
    transform->applyDimensionsTo(sourceRectangle);
}

void SpriteComponent::update(float deltaTime) {
    if (isAnimated) {
        sourceRectangle.x =
            sourceRectangle.w *
            static_cast<int>((SDL_GetTicks() / animationSpeed) % numFrames);
    }
    transform->applyVerticalFactorTo(sourceRectangle, animationIndex);

    destinationRectangle.x = static_cast<int>(transform->getPosition().x) -
                             (isFixed ? 0 : Game::camera.x);
    destinationRectangle.y = static_cast<int>(transform->getPosition().y) -
                             (isFixed ? 0 : Game::camera.y);
    transform->applyScaledDimensionsTo(destinationRectangle);
}

void SpriteComponent::render() {
    TextureManager::draw(texture, sourceRectangle, destinationRectangle,
                         spriteFlip);
}

void SpriteComponent::animate(Direction direction) {
    numFrames        = animations[direction].getNumFrames();
    animationIndex   = animations[direction].getIndex();
    animationSpeed   = animations[direction].getAnimationSpeed();
    currentAnimation = direction;
}
