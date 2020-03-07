#include "font_manager.h"

TTF_Font* FontManager::loadFont(const std::string& fileName, int fontSize) {
    return TTF_OpenFont(fileName.c_str(), fontSize);
}

void FontManager::draw(SDL_Texture* texture, SDL_Rect position) {
    SDL_RenderCopy(Game::renderer, texture, nullptr, &position);
}
