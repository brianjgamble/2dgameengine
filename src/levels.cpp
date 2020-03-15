#include "levels.h"
#include "../lib/sol/sol.hpp"
#include "components/collider_component.h"
#include "components/joystick_control_component.h"
#include "components/keyboard_control_component.h"
#include "components/projectile_emitter_component.h"
#include "components/sprite_component.h"
#include <string>

Levels::Levels(AssetManager* assetMgr, EntityManager& entityMgr, Map* map)
    : assetMgr {assetMgr}, entityMgr {entityMgr}, map {map} {}

void Levels::loadLevel(int levelNumber) {
    sol::state lua;
    lua.open_libraries(sol::lib::base, sol::lib::os, sol::lib::math);

    std::string levelName = "Level" + std::to_string(levelNumber);
    lua.script_file("./assets/scripts/" + levelName + ".lua");

    /****************************************************/
    /* Loads assets from lua config file                */
    /****************************************************/
    sol::table levelData   = lua[levelName];
    sol::table levelAssets = levelData["assets"];

    unsigned int assetIndex = 0;
    while (true) {
        sol::optional<sol::table> existsAssetIndexMode =
            levelAssets[assetIndex];
        if (existsAssetIndexMode == sol::nullopt) {
            break;
        }
        else {
            sol::table asset      = levelAssets[assetIndex];
            std::string assetType = asset["type"];

            if (assetType == "texture") {
                std::string assetId   = asset["id"];
                std::string assetFile = asset["file"];
                assetMgr->addTexture(assetId, assetFile);
            }

            if (assetType == "font") {
                std::string assetId   = asset["id"];
                std::string assetFile = asset["file"];
                int fontSize          = asset["fontSize"];
                assetMgr->addFont(assetId, assetFile, fontSize);
            }
        }
        assetIndex++;
    }

    /****************************************************/
    /* Loads map and tile info from lua config file     */
    /****************************************************/
    sol::table levelMap      = levelData["map"];
    std::string mapTextureId = levelMap["textureAssetId"];
    std::string mapFile      = levelMap["file"];

    map = new Map(mapTextureId, static_cast<int>(levelMap["scale"]),
                  static_cast<int>(levelMap["tileSize"]));

    map->loadMap(mapFile, static_cast<int>(levelMap["mapSizeX"]),
                 static_cast<int>(levelMap["mapSizeY"]));

    /****************************************************/
    /* Loads entities from lua config file              */
    /****************************************************/
    sol::table levelEntities = levelData["entities"];
    unsigned int entityIndex = 0;

    while (true) {
        sol::optional<sol::table> existsEntityIndexNode =
            levelEntities[entityIndex];
        if (existsEntityIndexNode == sol::nullopt) {
            break;
        }
        else {
            sol::table entity      = levelEntities[entityIndex];
            std::string entityName = entity["name"];
            LayerType entityLayerType =
                static_cast<LayerType>(static_cast<int>(entity["layer"]));

            // add new entity
            auto& newEntity(entityMgr.addEntity(entityName, entityLayerType));

            // add transform component
            sol::optional<sol::table> existsTransformComponent =
                entity["components"]["transform"];
            if (existsTransformComponent != sol::nullopt) {
                newEntity.addComponent<TransformComponent>(
                    static_cast<int>(
                        entity["components"]["transform"]["position"]["x"]),
                    static_cast<int>(
                        entity["components"]["transform"]["position"]["y"]),
                    static_cast<int>(
                        entity["components"]["transform"]["velocity"]["x"]),
                    static_cast<int>(
                        entity["components"]["transform"]["velocity"]["y"]),
                    static_cast<int>(
                        entity["components"]["transform"]["width"]),
                    static_cast<int>(
                        entity["components"]["transform"]["height"]),
                    static_cast<int>(
                        entity["components"]["transform"]["scale"]));
            }

            // add sprite component
            sol::optional<sol::table> existsSpriteComponent =
                entity["components"]["sprite"];
            if (existsSpriteComponent != sol::nullopt) {
                std::string textureId =
                    entity["components"]["sprite"]["textureAssetId"];
                bool isAnimated = entity["components"]["sprite"]["animated"];
                if (isAnimated) {
                    newEntity.addComponent<SpriteComponent>(
                        textureId,
                        static_cast<int>(
                            entity["components"]["sprite"]["frameCount"]),
                        static_cast<int>(
                            entity["components"]["sprite"]["animationSpeed"]),
                        static_cast<bool>(
                            entity["components"]["sprite"]["hasDirections"]),
                        static_cast<bool>(
                            entity["components"]["sprite"]["fixed"]));
                }
                else {
                    newEntity.addComponent<SpriteComponent>(textureId, false);
                }
            }

            // add input control components
            sol::optional<sol::table> existsInputComponent =
                entity["components"]["input"];
            if (existsInputComponent != sol::nullopt) {
                sol::optional<sol::table> existsKeyboardInputComponent =
                    entity["components"]["input"]["keyboard"];

                // Add keyboard input
                if (existsKeyboardInputComponent != sol::nullopt) {
                    std::string upKey =
                        entity["components"]["input"]["keyboard"]["up"];
                    std::string rightKey =
                        entity["components"]["input"]["keyboard"]["right"];
                    std::string downKey =
                        entity["components"]["input"]["keyboard"]["down"];
                    std::string leftKey =
                        entity["components"]["input"]["keyboard"]["left"];
                    std::string shootKey =
                        entity["components"]["input"]["keyboard"]["shoot"];
                    newEntity.addComponent<KeyboardControlComponent>(
                        upKey, rightKey, downKey, leftKey, shootKey);
                }

                // Add joystick/dpad input
                newEntity.addComponent<JoystickControlComponent>();
            }

            // Add collider component
            sol::optional<sol::table> existsColliderComponent =
                entity["components"]["collider"];
            if (existsColliderComponent != sol::nullopt) {
                std::string colliderTag =
                    entity["components"]["collider"]["tag"];
                newEntity.addComponent<ColliderComponent>(
                    colliderTag,
                    static_cast<int>(
                        entity["components"]["transform"]["position"]["x"]),
                    static_cast<int>(
                        entity["components"]["transform"]["position"]["y"]),
                    static_cast<int>(
                        entity["components"]["transform"]["width"]),
                    static_cast<int>(
                        entity["components"]["transform"]["height"]));
            }

            // Add projectile emitter component
            sol::optional<sol::table> existsProjectileEmitterComponent =
                entity["components"]["projectileEmitter"];
            if (existsProjectileEmitterComponent != sol::nullopt) {
                int parentEntityXPos =
                    entity["components"]["transform"]["position"]["x"];
                int parentEntityYPos =
                    entity["components"]["transform"]["position"]["y"];
                int parentEntityWidth =
                    entity["components"]["transform"]["width"];
                int parentEntityHeight =
                    entity["components"]["transform"]["height"];
                int projectileWidth =
                    entity["components"]["projectileEmitter"]["width"];
                int projectileHeight =
                    entity["components"]["projectileEmitter"]["height"];
                int projectileSpeed =
                    entity["components"]["projectileEmitter"]["speed"];
                int projectileRange =
                    entity["components"]["projectileEmitter"]["range"];
                int projectileAngle =
                    entity["components"]["projectileEmitter"]["angle"];
                bool projectileShouldLoop =
                    entity["components"]["projectileEmitter"]["shouldLoop"];
                std::string textureAssetId =
                    entity["components"]["projectileEmitter"]["textureAssetId"];
                Entity& projectile(
                    entityMgr.addEntity("projectile", LayerType::projectile));
                projectile.addComponent<TransformComponent>(
                    parentEntityXPos + (parentEntityWidth / 2),
                    parentEntityYPos + (parentEntityHeight / 2), 0, 0,
                    projectileWidth, projectileHeight, 1);
                projectile.addComponent<SpriteComponent>(textureAssetId);
                projectile.addComponent<ProjectileEmitterComponent>(
                    projectileSpeed, projectileAngle, projectileRange,
                    projectileShouldLoop);
                projectile.addComponent<ColliderComponent>(
                    "PROJECTILE", parentEntityXPos, parentEntityYPos,
                    projectileWidth, projectileHeight);
            }
        }
        entityIndex++;
    }
}
