#pragma once
#include "InputComponent.h"

class RotationIC final : public InputComponent {
 public:
  RotationIC(SDL_Keycode keyLeft, SDL_Keycode keyRight, float alpha);
  virtual ~RotationIC();
  void handleInput(Container* c, Uint32 time) override;

 protected:
  SDL_Keycode keyLeft_;
  SDL_Keycode keyRight_;
  float alpha_;
};
