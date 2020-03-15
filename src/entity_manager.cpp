#include "entity_manager.h"
#include "collision.h"
#include "components/collider_component.h"

bool EntityManager::hasNoEntities() {
    return entities.empty();
}

void EntityManager::update(float deltaTime) {
    for (int i = 0; i < entities.size(); i++) {
        if (entities[i]->isActive()) {
            entities[i]->update(deltaTime);
        }
        else {
            entities.erase(entities.begin() + i);
        }
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

Entity& EntityManager::addEntity(const std::string& entityName,
                                 LayerType layer) {
    auto* entity = new Entity(*this, entityName, layer);
    entities.emplace_back(entity);
    return *entity;
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

Entity* EntityManager::getEntityByName(const std::string& entityName) const {
    for (auto* entity : entities) {
        if (entity->getName() == entityName) {
            return entity;
        }
    }
    return nullptr;
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
                            return CollisionType::player_enemy;
                        }
                        if (thisCollider->getColliderTag() == "PLAYER" &&
                            thatCollider->getColliderTag() == "PROJECTILE") {
                            return CollisionType::player_projectile;
                        }
                        if (thisCollider->getColliderTag() == "ENEMY" &&
                            thatCollider->getColliderTag() ==
                                "FRIENDLY_PROJECTILE") {
                            return CollisionType::enemy_projectile;
                        }
                        if (thisCollider->getColliderTag() == "PLAYER" &&
                            thatCollider->getColliderTag() ==
                                "LEVEL_COMPLETE") {
                            return CollisionType::player_level_complete;
                        }
                    }
                }
            }
        }
    }
    return CollisionType::none;
}

Entity* EntityManager::getPlayer() const {
    return getEntityByName("player");
}
