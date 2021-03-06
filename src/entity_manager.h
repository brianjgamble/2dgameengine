#ifndef GAME_ENTITY_MANAGER_H
#define GAME_ENTITY_MANAGER_H

#include "components/component.h"
#include "entity.h"
#include <vector>

class EntityManager {
  public:
    void update(float deltaTime);
    void render();
    bool hasEntities();
    Entity& addEntity(const std::string& entityName, LayerType layer);
    std::vector<Entity*> getEntitiesByLayer(LayerType layer) const;
    Entity* getEntityByName(const std::string& entityName) const;
    CollisionType checkCollisions() const;
    Entity* getPlayer() const;
    void cleanup();

  private:
    std::vector<Entity*> entities;
};

#endif
