#include "entity.h"
#include "components/transform_component.h"
#include <utility>

Entity::Entity(EntityManager& manager) : manager {manager} {
    active = true;
}

Entity::Entity(EntityManager& manager, std::string name, LayerType layer)
    : manager {manager}, name {std::move(name)}, layer {layer} {
    active = true;
}

Entity::~Entity() {
    components.clear();
    componentTypeMap.clear();
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

bool Entity::isActive() const {
    return active;
}

void Entity::deactivate() {
    active = false;
}

LayerType Entity::getLayer() const {
    return layer;
}
std::string Entity::getName() const {
    return name;
}

void Entity::moveCamera(Rectangle& camera) {
    auto* transform = getComponent<TransformComponent>();
    transform->center(camera);
}
