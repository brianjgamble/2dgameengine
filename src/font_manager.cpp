#include "font_manager.h"
#include "locator.h"

TTF_Font* FontManager::loadFont(const std::string& fileName, int fontSize) {
    return TTF_OpenFont(fileName.c_str(), fontSize);
}

void FontManager::draw(SDL_Texture* texture, SDL_Rect position) {
    SDL_RenderCopy(Locator::getRenderer(), texture, nullptr, &position);
}
