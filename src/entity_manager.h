#ifndef GAME_ENTITY_MANAGER_H
#define GAME_ENTITY_MANAGER_H

#include "component.h"
#include "entity.h"
#include <vector>

class EntityManager {
  public:
    void update(float deltaTime);
    void render();
    bool hasNoEntities();
    Entity& addEntity(const std::string& entityName, LayerType layer);
    std::vector<Entity*> getEntitiesByLayer(LayerType layer) const;
    Entity* getEntityByName(const std::string& entityName) const;
    CollisionType checkCollisions() const;
    Entity* getPlayer() const;

  private:
    std::vector<Entity*> entities;
};

#endif
