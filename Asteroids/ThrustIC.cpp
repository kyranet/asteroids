#include "ThrustIC.h"
#include "InputHandler.h"

ThrustIC::ThrustIC(const SDL_Keycode key, const float thrust,
                   const float speedLimit)
    : key_(key), thrust_(thrust), speedLimit_(speedLimit) {}

ThrustIC::~ThrustIC() = default;

void ThrustIC::handleInput(Container* c, Uint32) {
  // If it's not the arrow up key, return earlier
  if (!InputHandler::getInstance()->isKeyDown(key_)) return;

  auto v =
      c->getVelocity() + Vector2D(0, -1).rotate(c->getRotation()) * thrust_;

  if (v.magnitude() > speedLimit_) v = v.normalize() * speedLimit_;

  // Set the velocity
  c->setVelocity(v);
}
