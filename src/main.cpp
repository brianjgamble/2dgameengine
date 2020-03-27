#include "engine.h"
#include "game.h"

int main() {
    auto engine = Engine::get();
    engine.startUp();

    if (engine.isRunning()) {
        Game game = Game {};
        game.run();
    }

    engine.shutDown();
    return 0;
}
