#include "RotationIC.h"
#include "InputHandler.h"

RotationIC::RotationIC(const SDL_Keycode keyLeft, const SDL_Keycode keyRight,
                       const float alpha)
    : keyLeft_(keyLeft), keyRight_(keyRight), alpha_(alpha) {}

RotationIC::~RotationIC() = default;

void RotationIC::handleInput(Container* c, Uint32 time) {
  const auto input = InputHandler::getInstance();

  if (input->isKeyDown(keyLeft_)) c->setRotation(c->getRotation() + alpha_);
  if (input->isKeyDown(keyRight_)) c->setRotation(c->getRotation() - alpha_);
}
