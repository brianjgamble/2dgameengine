#include "asset_manager.h"
#include <utility>

void AssetManager::addTexture(std::string textureId, std::string filePath) {
    textures.emplace(textureId,
                     TextureManager::loadTexture(std::move(filePath)));
}

void AssetManager::addFont(std::string fontId, const std::string& filePath,
                           int fontSize) {
    fonts.emplace(fontId, FontManager::loadFont(filePath, fontSize));
}

SDL_Texture* AssetManager::getTexture(const std::string& textureId) {
    return textures[textureId];
}

TTF_Font* AssetManager::getFont(const std::string& fontId) {
    return fonts[fontId];
}
