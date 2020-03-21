#ifndef GAME_TRANSFORM_COMPONENT_H
#define GAME_TRANSFORM_COMPONENT_H

#include "../../lib/glm/glm.hpp"
#include "component.h"
#include <SDL_rect.h>

class TransformComponent : public Component {
  public:
    TransformComponent(int posX, int posY, int velX, int velY, int w, int h,
                       int s);

    bool operator==(const TransformComponent& rhs) const;
    void initialize() override {}
    void update(float deltaTime) override;
    void render() override {}

    [[nodiscard]] glm::vec2 getPosition() const;
    void setPosition(glm::vec2 newPosition);

    void applyDimensionsTo(SDL_Rect& rect);
    void applyScaledDimensionsTo(SDL_Rect& rect);
    void applyPositionTo(SDL_Rect& rect);
    void applyVerticalFactorTo(SDL_Rect& rect, int factor);

    int distanceFrom(glm::vec2 origin);

    void setVelocity(float angleRadians, int speed);
    glm::vec2 velocity;

    void center(SDL_Rect& rect);

    void moveUp();
    void moveRight();
    void moveDown();
    void moveLeft();
    void stop();

  private:
    glm::vec2 position;
    int width;
    int height;
    int scale;
};

#endif
