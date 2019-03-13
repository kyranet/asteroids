#pragma once

#include "InputComponent.h"

/*
 *
 */
class DemoIC: public InputComponent {
public:
	DemoIC(SDL_Keycode ctrlKey);
	virtual ~DemoIC();
	virtual void handleInput(Container* c, Uint32 time, const SDL_Event& event);
private:
	SDL_Keycode ctrlKey_;
};

