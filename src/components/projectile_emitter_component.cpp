#include "projectile_emitter_component.h"

ProjectileEmitterComponent::ProjectileEmitterComponent(int speed, int angleDeg,
                                                       int range,
                                                       bool shouldLoop) {
    this->speed      = speed;
    this->range      = range;
    this->shouldLoop = shouldLoop;
    this->angleRad   = glm::radians(static_cast<float>(angleDeg));
}

void ProjectileEmitterComponent::initialize() {
    transform = owner->getComponent<TransformComponent>();
    origin = glm::vec2(transform->getPosition().x, transform->getPosition().y);
    transform->setVelocity(angleRad, speed);
}

void ProjectileEmitterComponent::update(float deltaTime) {
    if (transform->distanceFrom(origin) > range) {
        if (shouldLoop) {
            transform->setPosition(origin);
        }
        else {
            owner->deactivate();
        }
    }
}
