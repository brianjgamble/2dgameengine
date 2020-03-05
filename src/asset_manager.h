#ifndef GAME_ASSET_MANAGER_H
#define GAME_ASSET_MANAGER_H

#include "entity_manager.h"
#include "font_manager.h"
#include "texture_manager.h"
#include <SDL_ttf.h>
#include <map>
#include <string>

class AssetManager {
  public:
    explicit AssetManager(EntityManager* manager) : manager {manager} {}
    ~AssetManager() = default;

    void clearData();
    void addTexture(std::string textureId, std::string filePath);
    void addFont(std::string fontId, std::string filePath, int fontSize);

    SDL_Texture* getTexture(const std::string& textureId);

  private:
    EntityManager* manager;
    std::map<std::string, SDL_Texture*> textures;
    std::map<std::string, TTF_Font*> fonts;
};

#endif
