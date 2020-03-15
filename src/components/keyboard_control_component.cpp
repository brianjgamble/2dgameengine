#include "keyboard_control_component.h"

KeyboardControlComponent::KeyboardControlComponent(
    const std::string& upKey, const std::string& rightKey,
    const std::string& downKey, const std::string& leftKey,
    const std::string& shootKey) {
    this->upKey    = GetSDLKeyStringCode(upKey);
    this->rightKey = GetSDLKeyStringCode(rightKey);
    this->downKey  = GetSDLKeyStringCode(downKey);
    this->leftKey  = GetSDLKeyStringCode(leftKey);
    this->shootKey = GetSDLKeyStringCode(shootKey);
}

std::string
KeyboardControlComponent::GetSDLKeyStringCode(const std::string& key) {
    if (key == "up")
        return "1073741906";
    if (key == "down")
        return "1073741905";
    if (key == "left")
        return "1073741904";
    if (key == "right")
        return "1073741903";
    if (key == "space")
        return "32";
    return std::to_string(static_cast<int>(key[0]));
}

void KeyboardControlComponent::initialize() {
    transform = owner->getComponent<TransformComponent>();
    sprite    = owner->getComponent<SpriteComponent>();
}

void KeyboardControlComponent::update(float deltaTime) {
    if (Game::event.type == SDL_KEYDOWN) {
        std::string keyCode = std::to_string(Game::event.key.keysym.sym);

        if (keyCode == upKey) {
            transform->moveUp();
            sprite->play("UpAnimation");
        }
        if (keyCode == rightKey) {
            transform->moveRight();
            sprite->play("RightAnimation");
        }
        if (keyCode == downKey) {
            transform->moveDown();
            sprite->play("DownAnimation");
        }
        if (keyCode == leftKey) {
            transform->moveLeft();
            sprite->play("LeftAnimation");
        }
        if (keyCode == shootKey) {
            // TODO:
            // shoot projectiles when 'shoot' key is pressed
        }
    }

    if (Game::event.type == SDL_KEYUP) {
        std::string keyCode = std::to_string(Game::event.key.keysym.sym);

        if (keyCode == upKey) {
            transform->velocity.y = 0;
        }
        if (keyCode == rightKey) {
            transform->velocity.x = 0;
        }
        if (keyCode == downKey) {
            transform->velocity.y = 0;
        }
        if (keyCode == leftKey) {
            transform->velocity.x = 0;
        }
    }
}
