#include "asset_manager.h"
#include <utility>

void AssetManager::clearData() {
    textures.clear();
}

void AssetManager::addTexture(std::string textureId, std::string filePath) {
    textures.emplace(textureId,
                     TextureManager::loadTexture(std::move(filePath)));
}

void AssetManager::addFont(std::string fontId, std::string filePath,
                           int fontSize) {
    fonts.emplace(fontId, FontManager::LoadFont(filePath.c_str(), fontSize));
}

SDL_Texture* AssetManager::getTexture(const std::string& textureId) {
    return textures[textureId];
}
