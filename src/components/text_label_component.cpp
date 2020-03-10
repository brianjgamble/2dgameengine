#include "text_label_component.h"

#include <utility>

TextLabelComponent::TextLabelComponent(int x, int y, const std::string& text,
                                       const std::string& fontFamily,
                                       SDL_Color color) {
    this->position.x = x;
    this->position.y = y;
    this->color      = color;
    setLabelText(text, fontFamily);
}

void TextLabelComponent::setLabelText(const std::string& text,
                                      const std::string& fontFamily) {
    SDL_Surface* surface = TTF_RenderText_Blended(
        Game::assetManager->getFont(fontFamily), text.c_str(), color);
    texture = SDL_CreateTextureFromSurface(Game::renderer, surface);
    SDL_FreeSurface(surface);
    SDL_QueryTexture(texture, nullptr, nullptr, &position.w, &position.h);
}

void TextLabelComponent::render() {
    FontManager::draw(texture, position);
}
