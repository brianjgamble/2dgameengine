#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H

#include "video_manager.h"

class Engine {
  public:
    Engine()  = default;
    ~Engine() = default;

    void startUp();
    void shutDown();
    [[nodiscard]] bool isRunning() const;

  private:
    VideoManager videoManager {};
};

#endif
