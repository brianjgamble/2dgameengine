#ifndef GAME_ENTITY_H
#define GAME_ENTITY_H

#include "components/component.h"
#include "constants.h"
#include "entity_manager.h"
#include <map>
#include <string>
#include <vector>
#include "rectangle.h"

class Component;
class EntityManager;

class Entity {
  public:
    explicit Entity(EntityManager& manager);
    Entity(EntityManager& manager, std::string name, LayerType layer);
    ~Entity();

    void update(float deltaTime);
    void render();
    void destroy();
    bool isActive() const;
    LayerType getLayer() const;
    std::string getName() const;
    void moveCamera(Rectangle& camera);

    template<typename T, typename... TArgs> T& addComponent(TArgs&&... args) {
        T* newComponent(new T(std::forward<TArgs>(args)...));
        newComponent->owner                = this;
        components[&typeid(*newComponent)] = newComponent;
        newComponent->initialize();
        return *newComponent;
    }

    template<typename T> bool hasComponent() const {
        return components.count(&typeid(T));
    }

    template<typename T> T* getComponent() {
        return static_cast<T*>(components[&typeid(T)]);
    }

  private:
    EntityManager& manager;
    bool active;
    std::string name;
    std::map<const std::type_info*, Component*> components;
    LayerType layer;
};

#endif
