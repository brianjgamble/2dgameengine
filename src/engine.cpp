#include "engine.h"

Engine& Engine::get() {
    static Engine singleton;
    return singleton;
}

// Start up the engine systems in the proper order
void Engine::startUp() {
    videoManager.startUp();
}

// Shut down the engine systems in the reverse order
void Engine::shutDown() {
    videoManager.shutDown();
}

bool Engine::isRunning() const {
    return videoManager.isStarted();
}