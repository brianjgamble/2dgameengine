#ifndef GAME_JOYSTICK_CONTROL_COMPONENT_H
#define GAME_JOYSTICK_CONTROL_COMPONENT_H

#include "../component.h"
#include "sprite_component.h"
#include "transform_component.h"
#include <SDL_joystick.h>

class JoystickControlComponent : public Component {
  public:
    JoystickControlComponent();
    ~JoystickControlComponent() override;

    void initialize() override;
    void update(float deltaTime) override;
    void render() override {}

  private:
    SDL_Joystick* joystick;
    TransformComponent* transform;
    SpriteComponent* sprite;
};

#endif
