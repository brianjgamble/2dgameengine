#ifndef GAME_ENTITY_H
#define GAME_ENTITY_H

#include <string>
#include <vector>

class Component;
class EntityManager;

class Entity {
  public:
    Entity(EntityManager& manager);
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
