#ifndef GAME_ENTITY_H
#define GAME_ENTITY_H

#include "component.h"
#include "constants.h"
#include "entity_manager.h"
#include <map>
#include <string>
#include <vector>

class Component;
class EntityManager;

class Entity {
  public:
    explicit Entity(EntityManager& manager);
    Entity(EntityManager& manager, std::string name, LayerType layer);

    void update(float deltaTime);
    void render();
    void destroy();
    bool isActive() const;
    LayerType getLayer() const;

    template<typename T, typename... TArgs> T& addComponent(TArgs&&... args) {
        T* newComponent(new T(std::forward<TArgs>(args)...));
        newComponent->owner = this;
        components.emplace_back(newComponent);
        componentTypeMap[&typeid(*newComponent)] = newComponent;
        newComponent->initialize();
        return *newComponent;
    }

    template<typename T> T* getComponent() {
        return static_cast<T*>(componentTypeMap[&typeid(T)]);
    }

  private:
    EntityManager& manager;
    bool active;
    std::vector<Component*> components;
    std::string name;
    std::map<const std::type_info*, Component*> componentTypeMap;
    LayerType layer;
};

#endif
