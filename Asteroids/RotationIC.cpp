#include "RotationIC.h"

RotationIC::RotationIC() {}

RotationIC::RotationIC(const SDL_Keycode keyLeft, const SDL_Keycode keyRight,
                       const float alpha)
    : keyLeft_(keyLeft), keyRight_(keyRight), alpha_(alpha) {}

RotationIC::~RotationIC() {}

void RotationIC::handleInput(Container* c, Uint32 time,
                             const SDL_Event& event) {
  // If it's not a keydown, return earlier
  if (event.type != SDL_KEYDOWN) return;

  if (event.key.keysym.sym == getKeyLeft())
    c->setRotation(c->getRotation() + getAlpha());
  else if (event.key.keysym.sym == getKeyRight())
    c->setRotation(c->getRotation() - getAlpha());
}

float RotationIC::getAlpha() const { return alpha_; }
void RotationIC::setAlpha(const float alpha) { alpha_ = alpha; }

SDL_Keycode RotationIC::getKeyLeft() const { return keyLeft_; };
void RotationIC::setKeyLeft(const SDL_Keycode keyLeft) { keyLeft_ = keyLeft; };

SDL_Keycode RotationIC::getKeyRight() const { return keyRight_; };
void RotationIC::setKeyRight(const SDL_Keycode keyRight) {
  keyRight_ = keyRight;
};
