#ifndef GAME_PROJECTILE_EMITTER_COMPONENT_H
#define GAME_PROJECTILE_EMITTER_COMPONENT_H

#include "../../lib/glm/glm.hpp"
#include "../components/transform_component.h"
#include "../entity_manager.h"

class ProjectileEmitterComponent : public Component {
  public:
    ProjectileEmitterComponent(int speed, int angleDeg, int range,
                               bool shouldLoop);

    void initialize() override;
    void update(float deltaTime) override;
    void render() override {}

  private:
    TransformComponent* transform;
    glm::vec2 origin;
    int speed;
    int range;
    float angleRad;
    bool shouldLoop;
};

#endif
