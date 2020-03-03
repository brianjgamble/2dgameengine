#ifndef GAME_KEYBOARD_CONTROL_COMPONENT_H
#define GAME_KEYBOARD_CONTROL_COMPONENT_H

#include "../components/sprite_component.h"
#include "../components/transform_component.h"
#include "../entity_manager.h"
#include "../game.h"

class KeyboardControlComponent : public Component {
  public:
    KeyboardControlComponent() = default;
    KeyboardControlComponent(std::string upKey, std::string rightKey,
                             std::string downKey, std::string leftKey,
                             std::string shootKey);

    std::string GetSDLKeyStringCode(const std::string& key);

    void initialize() override;
    void update(float deltaTime) override;
    void render() override {}

  private:
    std::string upKey;
    std::string downKey;
    std::string rightKey;
    std::string leftKey;
    std::string shootKey;
    TransformComponent* transform;
    SpriteComponent* sprite;
};

#endif