#include "entity_manager.h"
#include "collision.h"
#include "components/collider_component.h"
#include <utility>

void EntityManager::clearData() {
    for (auto& entity : entities) {
        entity->destroy();
    }
}
bool EntityManager::hasNoEntities() {
    return entities.empty();
}

void EntityManager::update(float deltaTime) {
    for (auto& entity : entities) {
        entity->update(deltaTime);
    }
}

void EntityManager::render() {
    for (int layerNumber = 0; layerNumber < NUM_LAYERS; layerNumber++) {
        for (auto& entity :
             getEntitiesByLayer(static_cast<LayerType>(layerNumber))) {
            entity->render();
        }
    }
}

Entity& EntityManager::addEntity(std::string entityName, LayerType layer) {
    auto* entity = new Entity(*this, std::move(entityName), layer);
    entities.emplace_back(entity);
    return *entity;
}

std::vector<Entity*> EntityManager::getEntities() const {
    return entities;
}

std::vector<Entity*> EntityManager::getEntitiesByLayer(LayerType layer) const {
    std::vector<Entity*> selectedEntities;
    for (auto& entity : entities) {
        if (entity->getLayer() == layer) {
            selectedEntities.emplace_back(entity);
        }
    }
    return selectedEntities;
}

unsigned int EntityManager::getEntityCount() {
    return entities.size();
}

std::string EntityManager::checkEntityCollisions(Entity& myEntity) const {
    auto* myCollider = myEntity.getComponent<ColliderComponent>();
    for (auto& entity : entities) {
        if (entity->getName() != myEntity.getName() &&
            entity->getName() == "Tile") {
            if (entity->hasComponent<ColliderComponent>()) {
                auto* otherCollider = entity->getComponent<ColliderComponent>();
                if (Collision::checkRectangleCollision(
                        myCollider->getCollider(),
                        otherCollider->getCollider())) {
                    return otherCollider->getColliderTag();
                }
            }
        }
    }
    return std::string();
}
