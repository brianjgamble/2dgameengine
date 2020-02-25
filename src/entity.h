#ifndef GAME_ENTITY_H
#define GAME_ENTITY_H

#include "component.h"
#include "entity_manager.h"
#include <string>
#include <vector>

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

    template<typename T, typename... TArgs> T& addComponent(TArgs&&... args);

  private:
    EntityManager& manager;
    bool active;
    std::vector<Component*> components;
    std::string name;
};

#endif
