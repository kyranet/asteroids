#pragma once
#include "PhysicsComponent.h"
class ShowUpAtOppositeSidePC : public PhysicsComponent {
 public:
  ShowUpAtOppositeSidePC();
  virtual ~ShowUpAtOppositeSidePC();
  virtual void update(Container* c, Uint32 time);
};
