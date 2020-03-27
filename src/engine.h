#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H

#include "video_manager.h"

class Engine {
  public:
    Engine()  = default;
    ~Engine() = default;

    static Engine& get();

    void startUp();
    void shutDown();
    [[nodiscard]] bool isRunning() const;

  private:
    VideoManager videoManager {};
};

#endif
