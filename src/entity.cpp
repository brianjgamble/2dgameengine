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
}

void Entity::update(float deltaTime) {
    for (auto& iter : components) {
        auto comp = iter.second;
        comp->update(deltaTime);
    }
}

void Entity::render() {
    for (auto& iter : components) {
        auto comp = iter.second;
        comp->render();
    }
}

void Entity::destroy() {
    active = false;
}

bool Entity::isActive() const {
    return active;
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
