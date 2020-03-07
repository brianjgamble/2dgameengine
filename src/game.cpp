#include "game.h"
#include "../lib/glm/glm.hpp"
#include "asset_manager.h"
#include "components/collider_component.h"
#include "components/keyboard_control_component.h"
#include "components/sprite_component.h"
#include "components/text_label_component.h"
#include "constants.h"
#include "map.h"
#include <iostream>

EntityManager manager;
SDL_Renderer* Game::renderer;
AssetManager* Game::assetManager = new AssetManager(&manager);
SDL_Event Game::event;
SDL_Rect Game::camera {0, 0, WINDOW_WIDTH, WINDOW_HEIGHT};
Map* map;

Game::Game() {
    running = false;
}

Game::~Game() {}

bool Game::isRunning() const {
    return running;
}

void Game::initialize(int width, int height) {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cerr << "Error initializing SDL." << std::endl;
        return;
    }

    if (TTF_Init() != 0) {
        std::cerr << "Error initializing SDL TTF" << std::endl;
        return;
    }

    window = SDL_CreateWindow(nullptr, SDL_WINDOWPOS_CENTERED,
                              SDL_WINDOWPOS_CENTERED, width, height,
                              SDL_WINDOW_BORDERLESS);
    if (!window) {
        std::cerr << "Error creating SDL window." << std::endl;
        return;
    }

    renderer = SDL_CreateRenderer(window, -1, 0);
    if (!renderer) {
        std::cerr << "Error creating SDL renderer." << std::endl;
        return;
    }

    loadLevel(0);

    running = true;
}

Entity& player(manager.addEntity("chopper", PLAYER_LAYER));

void Game::loadLevel(int levelNumber) {
    assetManager->addTexture("tank-image",
                             "./assets/images/tank-big-right.png");
    assetManager->addTexture("chopper-image",
                             "./assets/images/chopper-spritesheet.png");
    assetManager->addTexture("radar-image", "./assets/images/radar.png");
    assetManager->addTexture("jungle-tiletexture",
                             "./assets/tilemaps/jungle.png");
    assetManager->addTexture("heliport-image", "./assets/images/heliport.png");
    assetManager->addFont("charriot-font", "./assets/fonts/charriot.ttf", 14);

    map = new Map("jungle-tiletexture", 2, 32);
    map->loadMap("./assets/tilemaps/jungle.map", 25, 20);

    player.addComponent<TransformComponent>(240, 106, 0, 0, 32, 32, 1);
    player.addComponent<SpriteComponent>("chopper-image", 2, 90, true, false);
    player.addComponent<KeyboardControlComponent>("up", "right", "down", "left",
                                                  "space");
    player.addComponent<ColliderComponent>("PLAYER", 240, 106, 32, 32);

    Entity& tankEntity(manager.addEntity("tank", ENEMY_LAYER));
    tankEntity.addComponent<TransformComponent>(150, 495, 5, 0, 32, 32, 1);
    tankEntity.addComponent<SpriteComponent>("tank-image");
    tankEntity.addComponent<ColliderComponent>("ENEMY", 150, 495, 32, 32);

    Entity& heliport(manager.addEntity("Heliport", OBSTACLE_LAYER));
    heliport.addComponent<TransformComponent>(470, 420, 0, 0, 32, 32, 1);
    heliport.addComponent<SpriteComponent>("heliport-image");
    heliport.addComponent<ColliderComponent>("LEVEL_COMPLETE", 470, 420, 32,
                                             32);

    Entity& radarEntity(manager.addEntity("Radar", UI_LAYER));
    radarEntity.addComponent<TransformComponent>(720, 15, 0, 0, 64, 64, 1);
    radarEntity.addComponent<SpriteComponent>("radar-image", 8, 150, false,
                                              true);

    Entity& labelLevelName(manager.addEntity("LabelLevelName", UI_LAYER));
    labelLevelName.addComponent<TextLabelComponent>(
        10, 10, "First Level...", "charriot-font", WHITE_COLOR);
}

void Game::processInput() {
    SDL_PollEvent(&event);

    switch (event.type) {
        case SDL_QUIT:
            running = false;
            break;

        case SDL_KEYDOWN:
            if (event.key.keysym.sym == SDLK_ESCAPE) {
                running = false;
            }

        default:
            break;
    }
}

void Game::update() {
    // Wait until 16ms has elapsed since the last frame
    auto elapsed = SDL_GetTicks() - ticksLastFrame;
    if (FRAME_TARGET_TIME > elapsed) {
        SDL_Delay(FRAME_TARGET_TIME - elapsed);
    }

    // Delta time is the difference in ticks from last frame
    // converted to seconds
    float deltaTime = (SDL_GetTicks() - ticksLastFrame) / 1000.0f;

    // Clamp deltaTime to a maximum value
    deltaTime = (deltaTime > 0.05f) ? 0.05f : deltaTime;

    // Sets the new ticks for the current frame to be used in the
    // next pass
    ticksLastFrame = SDL_GetTicks();

    manager.update(deltaTime);

    handleCameraMovement();
    checkCollisions();
}

void Game::render() {
    SDL_SetRenderDrawColor(renderer, 21, 21, 21, 255);
    SDL_RenderClear(renderer);

    if (manager.hasNoEntities()) {
        return;
    }

    manager.render();

    SDL_RenderPresent(renderer);
}

void Game::destroy() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Game::handleCameraMovement() {
    auto* mainPlayerTransform = player.getComponent<TransformComponent>();

    camera.x = mainPlayerTransform->getPosition().x - (WINDOW_WIDTH / 2);
    camera.y = mainPlayerTransform->getPosition().y - (WINDOW_HEIGHT / 2);

    camera.x = camera.x < 0 ? 0 : camera.x;
    camera.y = camera.y < 0 ? 0 : camera.y;
    camera.x = camera.x > camera.w ? camera.w : camera.x;
    camera.y = camera.y > camera.h ? camera.h : camera.y;
}

void Game::checkCollisions() {
    CollisionType collisionType = manager.checkCollisions();
    if (collisionType == PLAYER_ENEMY_COLLISION) {
        processGameOver();
    }
    if (collisionType == PLAYER_LEVEL_COMPLETE_COLLISION) {
        processNextLevel(1);
    }
}

void Game::processNextLevel(int levelNumber) {
    std::cout << "Next Level" << std::endl;
    running = false;
}

void Game::processGameOver() {
    std::cout << "Game Over" << std::endl;
    running = false;
}
