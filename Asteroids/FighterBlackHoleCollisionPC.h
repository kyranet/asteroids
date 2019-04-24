#pragma once
#include "BlackHole.h"
#include "PhysicsComponent.h"

class FighterBlackHoleCollisionPC final : public PhysicsComponent {
  GameObject* fighter_ = nullptr;
  const vector<BlackHole*>* blackHoles_ = nullptr;

 public:
  FighterBlackHoleCollisionPC();
  ~FighterBlackHoleCollisionPC();
  void update(Container* c, Uint32 time) override;
  void receive(Container* c, const msg::Message& msg) override;
};
