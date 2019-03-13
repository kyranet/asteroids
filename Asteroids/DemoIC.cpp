#include "DemoIC.h"

#include "DemoContainer.h"
DemoIC::DemoIC(SDL_Keycode ctrlKey) :
		ctrlKey_(ctrlKey) {
}

DemoIC::~DemoIC() {
}

void DemoIC::handleInput(Container* c, Uint32 time, const SDL_Event& event) {
	if (event.type == SDL_KEYDOWN) {
		if (event.key.keysym.sym == ctrlKey_) {
			static_cast<DemoContainer*>(c)->reset();
		}
	}
}
