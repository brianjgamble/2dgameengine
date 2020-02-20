#include "constants.h"
#include "game.h"

int main() {
    Game game = Game {};

    game.initialize(WINDOW_WIDTH, WINDOW_HEIGHT);

    while (game.isRunning()) {
        game.processInput();
        game.update();
        game.render();
    }

    game.destroy();

    return 0;
}
