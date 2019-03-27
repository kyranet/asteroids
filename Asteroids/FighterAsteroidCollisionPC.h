#pragma once
#include "PhysicsComponent.h"
#include "Asteroid.h"

class FighterAsteroidCollisionPC final : public PhysicsComponent {
 public:
  FighterAsteroidCollisionPC();
  virtual ~FighterAsteroidCollisionPC() = default;
  void update(Container* c, Uint32 time) override;

private:
    GameObject *fighter_;
    const vector<Asteroid *>* asteroids_;
};
