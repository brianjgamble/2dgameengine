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

void Texture::draw(Rectangle srcRect, Rectangle destRect,
                   SDL_RendererFlip flip) {
    auto srcCoord = srcRect.getCoordinate();
    auto srcDim   = srcRect.getDimensions();

    auto destCoord = destRect.getCoordinate();
    auto destDim   = destRect.getDimensions();

    SDL_Rect source {srcCoord.x, srcCoord.y, srcDim.w, srcDim.h};
    SDL_Rect destination {destCoord.x, destCoord.y, destDim.w, destDim.h};

    SDL_RenderCopyEx(Locator::getRenderer()->toSDL(), texture, &source,
                     &destination, 0.0, nullptr, flip);
}
