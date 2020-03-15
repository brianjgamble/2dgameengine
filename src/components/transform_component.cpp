#include "transform_component.h"
#include "../constants.h"

TransformComponent::TransformComponent(int posX, int posY, int velX, int velY,
                                       int w, int h, int s)
    : position {glm::vec2 {posX, posY}}, velocity {glm::vec2 {velX, velY}},
      width {w}, height {h}, scale {s} {}

bool TransformComponent::operator==(const TransformComponent& rhs) const {
    return glm::all(glm::equal(position, rhs.position)) &&
           glm::all(glm::equal(velocity, rhs.velocity)) && width == rhs.width &&
           height == rhs.height && scale == rhs.scale;
}

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

void TransformComponent::setVelocity(float angleRadians, int speed) {
    int x    = static_cast<int>(glm::cos(angleRadians) * speed);
    int y    = static_cast<int>(glm::sin(angleRadians) * speed);
    velocity = glm::vec2(x, y);
}

void TransformComponent::center(SDL_Rect& rect) {
    rect.x = static_cast<int>(position.x) - static_cast<int>(WINDOW_WIDTH / 2);
    rect.y = static_cast<int>(position.y) - static_cast<int>(WINDOW_HEIGHT / 2);

    rect.x = rect.x < 0 ? 0 : rect.x;
    rect.y = rect.y < 0 ? 0 : rect.y;
    rect.x = rect.x > rect.w ? rect.w : rect.x;
    rect.y = rect.y > rect.h ? rect.h : rect.y;
}

void TransformComponent::moveUp() {
    velocity.x = 0;
    velocity.y = -50;
}

void TransformComponent::moveRight() {
    velocity.x = 50;
    velocity.y = 0;
}

void TransformComponent::moveDown() {
    velocity.x = 0;
    velocity.y = 50;
}

void TransformComponent::moveLeft() {
    velocity.x = -50;
    velocity.y = 0;
}
