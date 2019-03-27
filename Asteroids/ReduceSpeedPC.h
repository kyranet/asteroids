#pragma once
#include "PhysicsComponent.h"

class ReduceSpeedPC final : public PhysicsComponent {
 public:
  ReduceSpeedPC();
  ReduceSpeedPC(float factor);
  virtual ~ReduceSpeedPC();
  void update(Container* c, Uint32 time) override;

  float getFactor() const;
  void setFactor(float factor);

 protected:
  float factor_;
};
