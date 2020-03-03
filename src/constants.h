#ifndef GAME_CONSTANTS_H
#define GAME_CONSTANTS_H

const int WINDOW_WIDTH  = 800;
const int WINDOW_HEIGHT = 600;

const unsigned int FPS               = 60;
const unsigned int FRAME_TARGET_TIME = 10000 / FPS;

enum LayerType {
    TILEMAP_LAYER    = 0,
    VEGETATION_LAYER = 1,
    ENEMIES_LAYER    = 2,
    PLAYER_LAYER     = 3,
    PROJECTILE_LAYER = 4,
    UI_LAYER         = 5
};

const unsigned int NUM_LAYERS = 6;

#endif