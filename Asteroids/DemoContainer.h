#pragma once
#include "BounceOnBorderPC.h"
#include "Container.h"
#include "DemoGC.h"
#include "DemoIC.h"
#include "ImageGC.h"
#include "NaturalMovePC.h"

/*
 *
 */
class DemoContainer: public Container {
public:
	DemoContainer(SDLGame* game);
	virtual ~DemoContainer();
	void reset();
private:
	ImageGC tennisball_;
	DemoIC  backToCenter_;
	NaturalMovePC naturalMove_;
	BounceOnBorderPC bounceOnBorders_;
	DemoGC keysInfo_;
};

