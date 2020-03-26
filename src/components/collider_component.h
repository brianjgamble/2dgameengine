#ifndef GAME_COLLIDER_COMPONENT_H
#define GAME_COLLIDER_COMPONENT_H

#include "../entity_manager.h"
#include "../game.h"
#include "transform_component.h"

class ColliderComponent : public Component {
  public:
    ColliderComponent(std::string colliderTag, int x, int y, int width,
                      int height);

    void initialize() override;
    void update(float deltaTime) override;
    void render() override {}

    [[nodiscard]] std::string getColliderTag() const;
    [[nodiscard]] const Rectangle& getCollider() const;

  private:
    std::string colliderTag;
    Rectangle collider;
    Rectangle sourceRectangle;
    Rectangle destinationRectangle;
    TransformComponent* transform;
};

#endif
