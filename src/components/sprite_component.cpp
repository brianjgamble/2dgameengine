#include "sprite_component.h"

SpriteComponent::SpriteComponent(const std::string& assetTextureId) {
    isAnimated = false;
    isFixed    = false;
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

        animations.emplace("DownAnimation", downAnimation);
        animations.emplace("RightAnimation", rightAnimation);
        animations.emplace("LeftAnimation", leftAnimation);
        animations.emplace("UpAnimation", upAnimation);

        this->animationIndex       = 0;
        this->currentAnimationName = "DownAnimation";
    }
    else {
        Animation singleAnimation = Animation(0, numFrames, animationSpeed);
        animations.emplace("SingleAnimation", singleAnimation);
        this->animationIndex       = 0;
        this->currentAnimationName = "SingleAnimation";
    }
    play(this->currentAnimationName);
    setTexture(id);
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
    if (isAnimated) {
        sourceRectangle.x =
            sourceRectangle.w * static_cast<int>((SDL_GetTicks() / animationSpeed) % numFrames);
    }
    sourceRectangle.y = animationIndex * transform->getHeight();

    destinationRectangle.x = static_cast<int>(transform->getPosition().x);
    destinationRectangle.y = static_cast<int>(transform->getPosition().y);
    destinationRectangle.w = transform->getWidth() * transform->getScale();
    destinationRectangle.h = transform->getHeight() * transform->getScale();
}

void SpriteComponent::render() {
    TextureManager::draw(texture, sourceRectangle, destinationRectangle,
                         spriteFlip);
}

void SpriteComponent::play(const std::string& animationName) {
    numFrames            = animations[animationName].getNumFrames();
    animationIndex       = animations[animationName].getIndex();
    animationSpeed       = animations[animationName].getAnimationSpeed();
    currentAnimationName = animationName;
}
