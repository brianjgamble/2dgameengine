#include "texture.h"
#include "locator.h"
#include <SDL_image.h>

Texture::Texture(const std::string& fileName) {
    SDL_Surface* surface = IMG_Load(fileName.c_str());
    texture =
        SDL_CreateTextureFromSurface(Locator::getRenderer()->toSDL(), surface);
    SDL_FreeSurface(surface);
}

Texture::~Texture() {
    SDL_DestroyTexture(texture);
}

void Texture::draw(SDL_Rect sourceRectangle, SDL_Rect destinationRectangle,
                   SDL_RendererFlip flip) {
    SDL_RenderCopyEx(Locator::getRenderer()->toSDL(), texture, &sourceRectangle,
                     &destinationRectangle, 0.0, nullptr, flip);
}
