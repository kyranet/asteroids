#pragma once
#include "PhysicsComponent.h"
class RotatingPC :
    public PhysicsComponent
{
private:
    double alpha_;
public:
    RotatingPC(double alpha);
    virtual ~RotatingPC();
    void update(Container* c, Uint32 time);
};

