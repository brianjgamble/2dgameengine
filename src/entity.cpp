#include "entity.h"
#include <utility>

Entity::Entity(EntityManager& manager) : manager {manager} {
    active = true;
}

Entity::Entity(EntityManager& manager, std::string name)
    : manager {manager}, name {std::move(name)} {
    active = true;
}

void Entity::update(float deltaTime) {
    for (auto& component : components) {
        component->update(deltaTime);
    }
}

void Entity::render() {
    for (auto& component : components) {
        component->render();
    }
}

void Entity::destroy() {
    active = false;
}

bool Entity::isActive() const {
    return active;
}