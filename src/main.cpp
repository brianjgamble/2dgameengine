#include "game.h"

int main() {
    Game game = Game {};

    while (game.isRunning()) {
        game.processInput();
        game.update();
        game.render();
    }

    return 0;
}
