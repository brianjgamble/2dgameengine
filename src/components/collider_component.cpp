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
        sourceRectangle = {};
        transform->applyDimensionsTo(sourceRectangle);
        destinationRectangle = {collider};
    }
}

void ColliderComponent::update(float deltaTime) {
    transform->applyPositionTo(collider);
    transform->applyScaledDimensionsTo(collider);

    auto coord = collider - Game::camera;
    destinationRectangle.moveTo(coord);
}

std::string ColliderComponent::getColliderTag() const {
    return colliderTag;
}

const Rectangle& ColliderComponent::getCollider() const {
    return collider;
}
