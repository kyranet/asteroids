#include "ReduceSpeedPC.h"

ReduceSpeedPC::ReduceSpeedPC() {}

ReduceSpeedPC::ReduceSpeedPC(const float factor) : factor_(factor) {}

ReduceSpeedPC::~ReduceSpeedPC() {}

void ReduceSpeedPC::update(Container* c, Uint32) {
  c->setVelocity(c->getVelocity() * factor_);
}

float ReduceSpeedPC::getFactor() const { return factor_; }
void ReduceSpeedPC::setFactor(const float factor) { factor_ = factor; }
