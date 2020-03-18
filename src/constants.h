#ifndef GAME_CONSTANTS_H
#define GAME_CONSTANTS_H

#include <SDL.h>

const int WINDOW_WIDTH  = 800;
const int WINDOW_HEIGHT = 600;

const unsigned int FPS               = 60;
const unsigned int FRAME_TARGET_TIME = 1000 / FPS;

enum class CollisionType {
    none,
    player_enemy,
    player_projectile,
    enemy_projectile,
    player_vegetation,
    player_level_complete
};

enum class LayerType : unsigned int {
    tilemap    = 0,
    vegetation = 1,
    enemy      = 2,
    obstacle   = 3,
    player     = 4,
    projectile = 5,
    ui         = 6
};

enum class Direction { up, right, down, left, none };

const unsigned int NUM_LAYERS = 7;

const SDL_Color WHITE_COLOR = {255, 255, 255, 255};
const SDL_Color GREEN_COLOR = {0, 255, 0, 255};

#endif