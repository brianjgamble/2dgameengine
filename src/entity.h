#ifndef GAME_ENTITY_H
#define GAME_ENTITY_H

#include <string>
#include <vector>
#include "entity_manager.h"
#include "component.h"

class Component;
class EntityManager;

class Entity {
  public:
    explicit Entity(EntityManager& manager);
    Entity(EntityManager& manager, std::string name);

    void update(float deltaTime);
    void render();
    void destroy();
    bool isActive() const;

  private:
    EntityManager& manager;
    bool active;
    std::vector<Component*> components;
    std::string name;
};

#endif
