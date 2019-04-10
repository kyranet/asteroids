#include "ThrustIC.h"

ThrustIC::ThrustIC(const SDL_Keycode key, const float thrust,
                   const float speedLimit)
    : key_(key), thrust_(thrust), speedLimit_(speedLimit) {}

ThrustIC::~ThrustIC() = default;

void ThrustIC::handleInput(Container* c, Uint32 time, const SDL_Event& event) {
  // If it's not a keydown, return earlier
  if (event.type != SDL_KEYDOWN) return;

  // If it's not the arrow up key, return earlier
  if (event.key.keysym.sym != SDLK_UP) return;

  auto v =
      c->getVelocity() + (Vector2D(0, -1).rotate(c->getRotation()) * thrust_);

  if (v.magnitude() > speedLimit_) v = v.normalize() * speedLimit_;

  // Set the velocity
  c->setVelocity(v);
}
