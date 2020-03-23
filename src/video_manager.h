#ifndef GAME_VIDEO_MANAGER_H
#define GAME_VIDEO_MANAGER_H

#include "renderer.h"

class VideoManager {
  public:
    VideoManager()  = default;
    ~VideoManager() = default;

    void startUp();
    void shutDown();

    [[nodiscard]] bool isStarted() const;

  private:
    bool started {false};
    SDL_Window* window {nullptr};
    Renderer* renderer {nullptr};
};

#endif
