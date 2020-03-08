#include "transform_component.h"

TransformComponent::TransformComponent(int posX, int posY, int velX, int velY,
                                       int w, int h, int s) {
    position = glm::vec2 {posX, posY};
    velocity = glm::vec2 {velX, velY};
    width    = w;
    height   = h;
    scale    = s;
}

void TransformComponent::update(float deltaTime) {
    position.x += velocity.x * deltaTime;
    position.y += velocity.y * deltaTime;
}

int TransformComponent::getWidth() const {
    return width;
}

int TransformComponent::getHeight() const {
    return height;
}

glm::vec2 TransformComponent::getPosition() const {
    return position;
}

void TransformComponent::setPosition(glm::vec2 newPosition) {
    position.x = newPosition.x;
    position.y = newPosition.y;
}

int TransformComponent::getScale() const {
    return scale;
}
