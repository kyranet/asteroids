#pragma once

#include "GraphicsComponent.h"

/*
 *
 */
class DemoGC: public GraphicsComponent {
public:
	DemoGC();
	virtual ~DemoGC();
	virtual void render(Container* c, Uint32 time);

};

