#include "animation.h"

Animation::Animation(unsigned int index, unsigned int numFrames,
                     unsigned int animationSpeed) {
    this->index          = index;
    this->numFrames      = numFrames;
    this->animationSpeed = animationSpeed;
}
unsigned int Animation::getNumFrames() const {
    return numFrames;
}
unsigned int Animation::getIndex() const {
    return index;
}
unsigned int Animation::getAnimationSpeed() const {
    return animationSpeed;
}
