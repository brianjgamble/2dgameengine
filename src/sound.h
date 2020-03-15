#ifndef GAME_SOUND_H
#define GAME_SOUND_H

#include <SDL_mixer.h>
#include <string>

class Sound {
  public:
    explicit Sound(const std::string& fileName);
    ~Sound();

    void setVolume(int volume);
    void play(bool loop);

  private:
    Mix_Chunk* mixChunk;
};

#endif
