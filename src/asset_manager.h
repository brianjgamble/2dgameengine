#ifndef GAME_ASSET_MANAGER_H
#define GAME_ASSET_MANAGER_H

#include "entity_manager.h"
#include "sound.h"
#include "texture.h"
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <map>
#include <string>

class AssetManager {
  public:
    explicit AssetManager(EntityManager* manager) : manager {manager} {}
    ~AssetManager() = default;

    void addTexture(std::string textureId, const std::string& filePath);
    void addFont(std::string fontId, const std::string& filePath, int fontSize);
    void addSound(std::string soundId, const std::string& filePath);

    Texture* getTexture(const std::string& textureId);
    TTF_Font* getFont(const std::string& fontId);
    Sound* getSound(const std::string& soundId);

    void cleanup();

  private:
    EntityManager* manager;
    std::map<std::string, Texture*> textures;
    std::map<std::string, TTF_Font*> fonts;
    std::map<std::string, Sound*> sounds;
};

#endif
