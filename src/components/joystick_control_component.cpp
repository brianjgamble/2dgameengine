#include "joystick_control_component.h"
#include <iostream>

JoystickControlComponent::JoystickControlComponent()
    : transform {nullptr}, sprite {nullptr} {
    // Check for joysticks
    if (SDL_NumJoysticks() < 1) {
        std::cerr << "No joysticks connected!" << std::endl;
    }
    else {
        // Load joystick
        joystick = SDL_JoystickOpen(0);
        if (joystick == nullptr) {
            std::cerr << "Warning: Unable to open game controller! SDL Error: "
                      << SDL_GetError() << std::endl;
        }
    }
}

JoystickControlComponent::~JoystickControlComponent() {
    if (SDL_JoystickGetAttached(joystick)) {
        SDL_JoystickClose(joystick);
    }
}

void JoystickControlComponent::initialize() {
    if (joystick) {
        transform = owner->getComponent<TransformComponent>();
        sprite    = owner->getComponent<SpriteComponent>();
    }
}

void JoystickControlComponent::update(float deltaTime) {
    if (Game::event.type == SDL_JOYHATMOTION) {
        auto value = Game::event.jhat.value;

        if (value == SDL_HAT_UP) {
            transform->moveUp();
            sprite->play("UpAnimation");
        }
        if (value == SDL_HAT_RIGHT) {
            transform->moveRight();
            sprite->play("RightAnimation");
        }
        if (value == SDL_HAT_DOWN) {
            transform->moveDown();
            sprite->play("DownAnimation");
        }
        if (value == SDL_HAT_LEFT) {
            transform->moveLeft();
            sprite->play("LeftAnimation");
        }
        else if (value == SDL_HAT_CENTERED) {
            transform->stop();
        }
    }
}
