#include "game.h"
#include "video_manager.h"

VideoManager videoManager;

int main() {
    // Start up the engine systems in the proper order
    videoManager.startUp();

    // Run the game
    if (videoManager.isStarted()) {
        Game game = Game {};
        game.run();
    }

    // Shut down the engine systems in the reverse order
    videoManager.shutDown();

    return 0;
}
