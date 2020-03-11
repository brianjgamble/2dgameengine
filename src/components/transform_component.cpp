#include "transform_component.h"

TransformComponent::TransformComponent(int posX, int posY, int velX, int velY,
                                       int w, int h, int s)
    : position {glm::vec2 {posX, posY}}, velocity {glm::vec2 {velX, velY}},
      width {w}, height {h}, scale {s} {}

void TransformComponent::update(float deltaTime) {
    position.x += velocity.x * deltaTime;
    position.y += velocity.y * deltaTime;
}

glm::vec2 TransformComponent::getPosition() const {
    return position;
}

void TransformComponent::setPosition(glm::vec2 newPosition) {
    position.x = newPosition.x;
    position.y = newPosition.y;
}

void TransformComponent::applyDimensionsTo(SDL_Rect& rect) {
    rect.w = width;
    rect.h = height;
}

void TransformComponent::applyScaledDimensionsTo(SDL_Rect& rect) {
    rect.w = width * scale;
    rect.h = height * scale;
}

void TransformComponent::applyPositionTo(SDL_Rect& rect) {
    rect.x = position.x;
    rect.y = position.y;
}

void TransformComponent::applyVerticalFactorTo(SDL_Rect& rect, int factor) {
    rect.y = factor * height;
}

int TransformComponent::distanceFrom(glm::vec2 origin) {
    return glm::distance(position, origin);
}
