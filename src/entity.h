#ifndef GAME_ENTITY_H
#define GAME_ENTITY_H

#include "constants.h"
//#include "entity_manager.h"
#include "components/component_container.h"
#include "rectangle.h"
#include <map>
#include <string>
#include <vector>

class EntityManager;

class Entity : public ComponentContainer {
  public:
    explicit Entity(EntityManager& manager);
    Entity(EntityManager& manager, std::string name, LayerType layer);
    ~Entity();

    void update(float deltaTime);
    void render();
    void destroy();
    [[nodiscard]] bool isActive() const;
    [[nodiscard]] LayerType getLayer() const;
    [[nodiscard]] std::string getName() const;
    void moveCamera(Rectangle& camera);
    void deactivate() override;

  private:
    EntityManager& manager;
    bool active;
    std::string name;
    LayerType layer;
};

#endif
