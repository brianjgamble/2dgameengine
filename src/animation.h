#ifndef GAME_ANIMATION_H
#define GAME_ANIMATION_H

class Animation {
  public:
    Animation() = default;
    Animation(unsigned int index, unsigned int numFrames,
              unsigned int animationSpeed);

    [[nodiscard]] unsigned int getNumFrames() const;
    [[nodiscard]] unsigned int getIndex() const;
    [[nodiscard]] unsigned int getAnimationSpeed() const;

  private:
    unsigned int index;
    unsigned int numFrames;
    unsigned int animationSpeed;
};

#endif
