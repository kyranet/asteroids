#pragma once
#include "PhysicsComponent.h"

class BlackHole;
class Bullet;

class BulletsBlackHolesCollisionPC final : public PhysicsComponent {
  const vector<BlackHole*>* blackHoles_ = nullptr;
  const vector<Bullet*>* bullets_ = nullptr;

 public:
  BulletsBlackHolesCollisionPC() = default;
  ~BulletsBlackHolesCollisionPC() = default;
  void update(Container* c, Uint32 time) override;
  void receive(Container* c, const msg::Message& msg) override;
};
