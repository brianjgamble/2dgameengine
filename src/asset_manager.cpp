#include "asset_manager.h"

#include <utility>

void AssetManager::clearData() {
    textures.clear();
}

void AssetManager::addTexture(std::string textureId, std::string filePath) {
    textures.emplace(textureId,
                     TextureManager::loadTexture(std::move(filePath)));
}

SDL_Texture* AssetManager::getTexture(const std::string& textureId) {
    return textures[textureId];
}
