#include "asset_manager.h"
#include "font_manager.h"
#include "sound.h"
#include "texture.h"

void AssetManager::addTexture(std::string textureId,
                              const std::string& filePath) {
    textures.emplace(textureId, new Texture(filePath));
}

void AssetManager::addFont(std::string fontId, const std::string& filePath,
                           int fontSize) {
    fonts.emplace(fontId, FontManager::loadFont(filePath, fontSize));
}

Texture* AssetManager::getTexture(const std::string& textureId) {
    return textures[textureId];
}

TTF_Font* AssetManager::getFont(const std::string& fontId) {
    return fonts[fontId];
}

void AssetManager::addSound(std::string soundId, const std::string& filePath) {
    sounds.emplace(soundId, new Sound(filePath));
}

Sound* AssetManager::getSound(const std::string& soundId) {
    return sounds[soundId];
}

void AssetManager::cleanup() {
    sounds.clear();
}
