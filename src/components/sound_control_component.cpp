#include "sound_control_component.h"
#include "../game.h"

SoundControlComponent::SoundControlComponent(const std::string& assetSoundId,
                                             int volume) {
    sound = Game::assetManager->getSound(assetSoundId);
    sound->setVolume(volume);
}

void SoundControlComponent::initialize() {
    sound->play(true);
}
