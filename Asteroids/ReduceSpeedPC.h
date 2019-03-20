#pragma once
#include "PhysicsComponent.h"

class ReduceSpeedPC : public PhysicsComponent {
 public:
  ReduceSpeedPC();
  ReduceSpeedPC(const float factor);
  virtual ~ReduceSpeedPC();
  virtual void update(Container* c, Uint32 time);

  float getFactor() const;
  void setFactor(const float factor);

 protected:
  float factor_;
};
