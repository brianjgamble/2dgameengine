#ifndef GAME_TEXT_LABEL_COMPONENT_H
#define GAME_TEXT_LABEL_COMPONENT_H

#include "../asset_manager.h"
#include "../entity_manager.h"
#include "../font_manager.h"
#include <SDL.h>
#include <SDL_ttf.h>

class TextLabelComponent : public Component {
  public:
    TextLabelComponent(int x, int y, const std::string& text, const std::string& fontFamily,
                       SDL_Color color);

    void initialize() override {}
    void update(float deltaTime) override {}
    void render() override;

    void setLabelText(const std::string& text, const std::string& fontFamily);

  private:
    SDL_Rect position;
    SDL_Color color;
    SDL_Texture* texture;
};

#endif
