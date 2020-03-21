#ifndef GAME_SOUND_CONTROL_COMPONENT_H
#define GAME_SOUND_CONTROL_COMPONENT_H

#include "../asset_manager.h"
#include "component.h"
#include <SDL_mixer.h>
#include <string>

class SoundControlComponent : public Component {
  public:
    explicit SoundControlComponent(const std::string& assetSoundId, int volume);

    void initialize() override;
    void update(float deltaTime) override {}
    void render() override {}

  private:
    Sound* sound;
};

#endif
