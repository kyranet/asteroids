#pragma once
#include "InputComponent.h"
class ThrustIC final : public InputComponent {
 public:
  ThrustIC(SDL_Keycode key, float thrust, float speedLimit);
  virtual ~ThrustIC();
  void handleInput(Container* c, Uint32 time, const SDL_Event& event) override;

 protected:
  SDL_Keycode key_;
  float thrust_;
  float speedLimit_;
};
