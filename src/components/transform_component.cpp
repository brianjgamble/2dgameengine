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

void TransformComponent::applyDimensionsTo(Rectangle& rect) {
    auto d = Dimensions {width, height};
    rect.resize(d);
}

void TransformComponent::applyScaledDimensionsTo(Rectangle& rect) {
    auto d = Dimensions {width * scale, height * scale};
    rect.resize(d);
}

void TransformComponent::applyPositionTo(Rectangle& rect) {
    auto coord =
        Coordinate {static_cast<int>(position.x), static_cast<int>(position.y)};
    rect.moveTo(coord);
}

void TransformComponent::applyVerticalFactorTo(Rectangle& rect, int factor) {
    auto coord = rect.getCoordinate();
    coord.y    = factor * height;
    rect.moveTo(coord);
}

int TransformComponent::distanceFrom(glm::vec2 origin) {
    return glm::distance(position, origin);
}

void TransformComponent::setVelocity(float angleRadians, int speed) {
    int x    = static_cast<int>(glm::cos(angleRadians) * speed);
    int y    = static_cast<int>(glm::sin(angleRadians) * speed);
    velocity = glm::vec2(x, y);
}

void TransformComponent::center(Rectangle& rect) {
    int x = static_cast<int>(position.x) - static_cast<int>(WINDOW_WIDTH / 2);
    int y = static_cast<int>(position.y) - static_cast<int>(WINDOW_HEIGHT / 2);

    auto dim = rect.getDimensions();

    x = x < 0 ? 0 : x;
    y = y < 0 ? 0 : y;
    x = x > dim.w ? dim.w : x;
    y = y > dim.h ? dim.h : y;

    auto newCoord = Coordinate {x, y};
    rect.moveTo(newCoord);
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

void TransformComponent::stop() {
    velocity.x = 0;
    velocity.y = 0;
}
