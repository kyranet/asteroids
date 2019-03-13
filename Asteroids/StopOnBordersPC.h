#pragma once

#include "Component.h"
#include "PhysicsComponent.h"

/*
 *
 */
class StopOnBordersPC: public PhysicsComponent {
public:
	StopOnBordersPC();
	StopOnBordersPC(bool left, bool right, bool top, bool bot);
	virtual ~StopOnBordersPC();
	virtual void update(Container* c, Uint32 time);

private:
	bool left_;
	bool right_;
	bool top_;
	bool bot_;
};

