#include "RotationIC.h"

RotationIC::RotationIC(const SDL_Keycode keyLeft, const SDL_Keycode keyRight,
                       const float alpha)
    : keyLeft_(keyLeft), keyRight_(keyRight), alpha_(alpha) {}

RotationIC::~RotationIC() = default;

void RotationIC::handleInput(Container* c, Uint32 time,
                             const SDL_Event& event) {
  // If it's not a keydown, return earlier
  if (event.type != SDL_KEYDOWN) return;

  if (event.key.keysym.sym == keyLeft_)
    c->setRotation(c->getRotation() + alpha_);
  else if (event.key.keysym.sym == keyRight_)
    c->setRotation(c->getRotation() - alpha_);
}
