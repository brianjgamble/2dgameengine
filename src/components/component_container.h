#ifndef GAME_COMPONENT_CONTAINER_H
#define GAME_COMPONENT_CONTAINER_H

#include "component.h"
#include <map>
#include <vector>

class ComponentContainer {
  public:
    template<typename T, typename... TArgs> T& addComponent(TArgs&&... args) {
        T* newComponent(new T(std::forward<TArgs>(args)...));
        newComponent->owner = this;
        components.emplace_back(newComponent);
        componentTypeMap[&typeid(*newComponent)] = newComponent;
        newComponent->initialize();
        return *newComponent;
    }

    template<typename T>[[nodiscard]] bool hasComponent() const {
        return componentTypeMap.count(&typeid(T));
    }

    template<typename T> T* getComponent() {
        return static_cast<T*>(componentTypeMap[&typeid(T)]);
    }

    virtual void deactivate() = 0;

  protected:
    std::vector<Component*> components;
    std::map<const std::type_info*, Component*> componentTypeMap;
};

#endif
