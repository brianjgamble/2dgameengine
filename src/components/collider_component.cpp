#include "collider_component.h"

#include <utility>

ColliderComponent::ColliderComponent(std::string colliderTag, int x, int y,
                                     int width, int height) {
    this->colliderTag = std::move(colliderTag);
    this->collider    = {x, y, width, height};
}

void ColliderComponent::initialize() {
    if (owner->hasComponent<TransformComponent>()) {
        transform       = owner->getComponent<TransformComponent>();
        sourceRectangle = {0, 0, transform->getWidth(), transform->getHeight()};
        destinationRectangle = {collider.x, collider.y, collider.w, collider.h};
    }
}

void ColliderComponent::update(float deltaTime) {
    collider.x = transform->getPosition().x;
    collider.y = transform->getPosition().y;
    collider.w = transform->getWidth() * transform->getScale();
    collider.h = transform->getHeight() * transform->getScale();

    destinationRectangle.x = collider.x - Game::camera.x;
    destinationRectangle.y = collider.y - Game::camera.y;
}
std::string ColliderComponent::getColliderTag() const {
    return colliderTag;
}
SDL_Rect ColliderComponent::getCollider() const {
    return collider;
}
