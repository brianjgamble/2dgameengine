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

enum LayerType {
    TILEMAP_LAYER    = 0,
    VEGETATION_LAYER = 1,
    ENEMY_LAYER      = 2,
    OBSTACLE_LAYER   = 3,
    PLAYER_LAYER     = 4,
    PROJECTILE_LAYER = 5,
    UI_LAYER         = 6
};

const unsigned int NUM_LAYERS = 7;

const SDL_Color WHITE_COLOR = {255, 255, 255, 255};
const SDL_Color GREEN_COLOR = {0, 255, 0, 255};

#endif