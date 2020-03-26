#include "text_label_component.h"
#include "../game.h"
#include "../locator.h"

TextLabelComponent::TextLabelComponent(int x, int y, const std::string& text,
                                       const std::string& fontFamily,
                                       SDL_Color color) {
    this->position = {x, y};
    this->color      = color;
    setLabelText(text, fontFamily);
}

void TextLabelComponent::setLabelText(const std::string& text,
                                      const std::string& fontFamily) {
    SDL_Surface* surface = TTF_RenderText_Blended(
        Game::assetManager->getFont(fontFamily), text.c_str(), color);
    texture =
        SDL_CreateTextureFromSurface(Locator::getRenderer()->toSDL(), surface);
    SDL_FreeSurface(surface);

    auto dim = position.getDimensions();
    int w    = dim.w;
    int h    = dim.h;

    SDL_QueryTexture(texture, nullptr, nullptr, &w, &h);
}

void TextLabelComponent::render() {
    FontManager::draw(texture, position);
}
