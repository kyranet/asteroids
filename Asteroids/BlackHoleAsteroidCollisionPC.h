#pragma once
#include "PhysicsComponent.h"

class BlackHole;
class Asteroid;

class BlackHoleAsteroidCollisionPC final : public PhysicsComponent {
 private:
  const vector<BlackHole*>* blackHoles_ = nullptr;
  const vector<Asteroid*>* asteroids_ = nullptr;
  GameObject* fighter_ = nullptr;
 public:
  BlackHoleAsteroidCollisionPC();
  ~BlackHoleAsteroidCollisionPC();

  void update(Container* c, Uint32 time) override;
  void receive(Container* c, const msg::Message& msg) override;
};
