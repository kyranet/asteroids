#pragma once
#include "PhysicsComponent.h"

class Asteroid;
class Bullet;

class BulletsAsteroidsCollisionPC final : public PhysicsComponent {
  const vector<Asteroid*>* asteroids_ = nullptr;
  const vector<Bullet*>* bullets_ = nullptr;

 public:
  BulletsAsteroidsCollisionPC() = default;
  ~BulletsAsteroidsCollisionPC() = default;
  void update(Container* c, Uint32 time) override;
  void receive(Container* c, const msg::Message& msg) override;
};
