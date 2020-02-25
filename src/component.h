#ifndef GAME_COMPONENT_H
#define GAME_COMPONENT_H

class Entity;

class Component {
  public:
    Entity* owner;

    virtual ~Component()                 = default;
    virtual void initialize()            = 0;
    virtual void update(float deltaTime) = 0;
    virtual void render()                = 0;
};

#endif
