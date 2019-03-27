#pragma once
#include "Asteroid.h"
#include "Bullet.h"
#include "PhysicsComponent.h"

class BulletsAsteroidsCollisionPC : public PhysicsComponent {
 public:
  BulletsAsteroidsCollisionPC() = default;
  virtual ~BulletsAsteroidsCollisionPC() = default;
  void update(Container* c, Uint32 time) override;
  void receive(Container* c, const msg::Message& msg) override;

 private:
  const vector<Asteroid*>* asteroids_;
  const vector<Bullet*>* bullets_;
};
