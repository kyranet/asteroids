#pragma once

#include "PhysicsComponent.h"

/*
 *
 */
class BounceOnBorderPC: public PhysicsComponent {
public:
	BounceOnBorderPC();
	BounceOnBorderPC(bool left, bool right, bool top, bool bot);
	virtual ~BounceOnBorderPC();
	virtual void update(Container* c, Uint32 time);
private:
	bool left_;
	bool right_;
	bool top_;
	bool bot_;
};

