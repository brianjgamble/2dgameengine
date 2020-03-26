#include "font_manager.h"
#include "locator.h"

TTF_Font* FontManager::loadFont(const std::string& fileName, int fontSize) {
    return TTF_OpenFont(fileName.c_str(), fontSize);
}

void FontManager::draw(SDL_Texture* texture, Rectangle position) {
    auto coord = position.getCoordinate();
    auto dim   = position.getDimensions();
    SDL_Rect r = {coord.x, coord.y, dim.w, dim.h};

    SDL_RenderCopy(Locator::getRenderer()->toSDL(), texture, nullptr, &r);
}
