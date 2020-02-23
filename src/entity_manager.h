#ifndef GAME_ENTITY_MANAGER_H
#define GAME_ENTITY_MANAGER_H

#include "component.h"
#include "entity.h"
#include <vector>

class EntityManager {
  public:
    void clearData();
    void update(float deltaTime);
    void render();
    bool hasNoEntities();
    Entity& addEntity(std::string entityName);
    std::vector<Entity*> getEntities() const;
    unsigned int getEntityCount();

  private:
    std::vector<Entity*> entities;
};

#endif
