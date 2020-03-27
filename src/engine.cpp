#include "engine.h"

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
