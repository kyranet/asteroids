#include "RotatingPC.h"

RotatingPC::RotatingPC(double alpha) : PhysicsComponent(), alpha_(alpha) {}

RotatingPC::~RotatingPC() {}

void RotatingPC::update(Container* c, Uint32 time) {
  c->setRotation(c->getRotation() + alpha_);
}
