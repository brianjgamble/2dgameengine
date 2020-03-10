#include "texture_manager.h"

SDL_Texture* TextureManager::loadTexture(const std::string& fileName) {
    SDL_Surface* surface = IMG_Load(fileName.c_str());
    SDL_Texture* texture =
        SDL_CreateTextureFromSurface(Game::renderer, surface);
    SDL_FreeSurface(surface);
    return texture;
}
void TextureManager::draw(SDL_Texture* texture, SDL_Rect sourceRectangle,
                          SDL_Rect destinationRectangle,
                          SDL_RendererFlip flip) {
    SDL_RenderCopyEx(Game::renderer, texture, &sourceRectangle,
                     &destinationRectangle, 0.0, nullptr, flip);
}
