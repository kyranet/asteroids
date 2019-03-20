#include "ThrustIC.h"

ThrustIC::ThrustIC() {}

ThrustIC::ThrustIC(const SDL_Keycode key, const float thrust,
                   const float speedLimit)
    : key_(key), thrust_(thrust), speedLimit_(speedLimit) {}

ThrustIC::~ThrustIC() {}

void ThrustIC::handleInput(Container* c, Uint32 time, const SDL_Event& event) {
  // If it's not a keydown, return earlier
  if (event.type != SDL_KEYDOWN) return;

  // If it's not the arrow up key, return earlier
  if (event.key.keysym.sym != SDLK_UP) return;

  // Set the velocity
  c->setVelocity(
      (c->getVelocity() + (Vector2D(0, -1).rotate(c->getRotation()) * thrust_))
          .normalize() *
      getSpeedLimit());
}

float ThrustIC::getThrust() const { return thrust_; }
void ThrustIC::setThrust(const float thrust) { thrust_ = thrust; }

float ThrustIC::getSpeedLimit() const { return speedLimit_; }
void ThrustIC::setSpeedLimit(const float speedLimit) {
  speedLimit_ = speedLimit;
}

SDL_Keycode ThrustIC::getKey() const { return key_; }
void ThrustIC::setKey(const SDL_Keycode key) { key_ = key; }
