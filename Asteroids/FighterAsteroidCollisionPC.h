#pragma once
#include "Asteroid.h"
#include "PhysicsComponent.h"

class FighterAsteroidCollisionPC final : public PhysicsComponent {
 public:
  FighterAsteroidCollisionPC();
  virtual ~FighterAsteroidCollisionPC() = default;
  void update(Container* c, Uint32 time) override;
  void receive(Container* c, const msg::Message& msg) override;

 private:
  GameObject* fighter_ = nullptr;
  const vector<Asteroid*>* asteroids_ = nullptr;
};
