#ifndef GAME_ASSET_MANAGER_H
#define GAME_ASSET_MANAGER_H

#include "entity_manager.h"
#include "texture_manager.h"
#include <map>
#include <string>

class AssetManager {
  public:
    explicit AssetManager(EntityManager* manager) : manager {manager} {}
    ~AssetManager() = default;

    void clearData();
    void addTexture(std::string textureId, std::string filePath);
    SDL_Texture* getTexture(const std::string& textureId);

  private:
    EntityManager* manager;
    std::map<std::string, SDL_Texture*> textures;
};

#endif
