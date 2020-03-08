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
    destroyInactiveEntities();
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

CollisionType EntityManager::checkCollisions() const {
    for (int i = 0; i < entities.size() - 1; i++) {
        auto& thisEntity = entities[i];
        if (thisEntity->hasComponent<ColliderComponent>()) {
            auto* thisCollider = thisEntity->getComponent<ColliderComponent>();
            for (int j = i + 1; j < entities.size(); j++) {
                auto& thatEntity = entities[j];
                if (thisEntity->getName() != thatEntity->getName() &&
                    thatEntity->hasComponent<ColliderComponent>()) {
                    auto* thatCollider =
                        thatEntity->getComponent<ColliderComponent>();
                    if (Collision::checkRectangleCollision(
                            thisCollider->getCollider(),
                            thatCollider->getCollider())) {
                        if (thisCollider->getColliderTag() == "PLAYER" &&
                            thatCollider->getColliderTag() == "ENEMY") {
                            return PLAYER_ENEMY_COLLISION;
                        }
                        if (thisCollider->getColliderTag() == "PLAYER" &&
                            thatCollider->getColliderTag() == "PROJECTILE") {
                            return PLAYER_PROJECTILE_COLLISION;
                        }
                        if (thisCollider->getColliderTag() == "ENEMY" &&
                            thatCollider->getColliderTag() ==
                                "FRIENDLY_PROJECTILE") {
                            return ENEMY_PROJECTILE_COLLISION;
                        }
                        if (thisCollider->getColliderTag() == "PLAYER" &&
                            thatCollider->getColliderTag() ==
                                "LEVEL_COMPLETE") {
                            return PLAYER_LEVEL_COMPLETE_COLLISION;
                        }
                    }
                }
            }
        }
    }
    return NO_COLLISION;
}

void EntityManager::destroyInactiveEntities() {
    for (int i = 0; i < entities.size(); i++) {
        if (!entities[i]->isActive()) {
            entities.erase(entities.begin() + i);
        }
    }
}
