#ifndef GAME_ANIMATION_H
#define GAME_ANIMATION_H

class Animation {
  public:
    Animation();
    Animation(unsigned int index, unsigned int numFrames,
              unsigned int animationSpeed);

    unsigned int getNumFrames() const;
    unsigned int getIndex() const;
    unsigned int getAnimationSpeed() const;

  private:
    unsigned int index;
    unsigned int numFrames;
    unsigned int animationSpeed;
};

#endif
