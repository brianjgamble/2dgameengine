#include "engine.h"
#include "game.h"

Engine engine;

int main() {
    engine.startUp();

    if (engine.isRunning()) {
        Game game = Game {};
        game.run();
    }

    engine.shutDown();

    return 0;
}
