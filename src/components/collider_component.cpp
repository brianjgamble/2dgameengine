#include "collider_component.h"

#include <utility>

ColliderComponent::ColliderComponent(std::string colliderTag, int x, int y,
                                     int width, int height) {
    this->colliderTag = std::move(colliderTag);
    this->collider    = {x, y, width, height};
}

void ColliderComponent::initialize() {
    if (owner->hasComponent<TransformComponent>()) {
        transform         = owner->getComponent<TransformComponent>();
        sourceRectangle.x = 0;
        sourceRectangle.y = 0;
        transform->updateDimensions(sourceRectangle);
        destinationRectangle = {collider.x, collider.y, collider.w, collider.h};
    }
}

void ColliderComponent::update(float deltaTime) {
    transform->updatePosition(collider);
    transform->updateScaledDimensions(collider);

    destinationRectangle.x = collider.x - Game::camera.x;
    destinationRectangle.y = collider.y - Game::camera.y;
}
std::string ColliderComponent::getColliderTag() const {
    return colliderTag;
}
SDL_Rect ColliderComponent::getCollider() const {
    return collider;
}
