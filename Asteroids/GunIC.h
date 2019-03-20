#pragma once
#include "InputComponent.h"
class GunIC : public InputComponent {
 public:
  GunIC();
  virtual ~GunIC();
  virtual void handleInput(Container* c, Uint32 time, const SDL_Event& event);
};
