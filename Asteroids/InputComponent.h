#pragma once

#include "Component.h"
#include "Container.h"
#include "sdl_includes.h"

/*
 *
 */
class InputComponent : virtual public Component {
public:
	InputComponent();
	virtual ~InputComponent();
	virtual void handleInput(Container* c, Uint32 time, const SDL_Event& event) = 0;
};

