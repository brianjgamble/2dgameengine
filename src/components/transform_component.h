#ifndef GAME_TRANSFORM_COMPONENT_H
#define GAME_TRANSFORM_COMPONENT_H

#include "../../lib/glm/glm.hpp"
#include "../entity_manager.h"

class TransformComponent : public Component {
  public:
    TransformComponent(int posX, int posY, int velX, int velY, int w, int h,
                       int s);

    void initialize() override {}
    void update(float deltaTime) override;
    void render() override {}

    int getWidth() const;
    int getHeight() const;
    glm::vec2 getPosition() const;
    int getScale() const;

    glm::vec2 velocity;

  private:
    glm::vec2 position;
    int width;
    int height;
    int scale;
};

#endif
