#include "sound.h"
#include <iostream>

Sound::Sound(const std::string& fileName) {
    mixChunk = Mix_LoadWAV(fileName.c_str());
    if (mixChunk == nullptr) {
        std::cerr << "Failed to load scratch sound effect! SDL_mixer Error: "
                  << Mix_GetError() << std::endl;
    }
}

Sound::~Sound() {
    if (mixChunk) {
        Mix_FreeChunk(mixChunk);
    }
}

void Sound::play(bool loop) {
    if (mixChunk) {
        Mix_PlayChannel(-1, mixChunk, loop ? -1 : 0);
    }
}

void Sound::setVolume(int volume) {
    if (mixChunk) {
        mixChunk->volume = volume;
    }
}
