#pragma once
#include "InputComponent.h"
class GunIC final : public InputComponent {
  SDL_Keycode key_;

 public:
  explicit GunIC(SDL_Keycode key);
  virtual ~GunIC();
  void handleInput(Container* c, Uint32 time) override;
};
