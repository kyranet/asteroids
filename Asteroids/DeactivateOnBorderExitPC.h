#pragma once
#include "PhysicsComponent.h"

class DeactivateOnBorderExitPC final : public PhysicsComponent {
 public:
  void update(Container* c, Uint32 time) override;
};
