#pragma once
#include "InputComponent.h"
class ThrustIC : public InputComponent {
 public:
  ThrustIC();
  ThrustIC(const SDL_Keycode key, const float thrust, const float speedLimit);
  virtual ~ThrustIC();
  virtual void handleInput(Container* c, Uint32 time, const SDL_Event& event);

  float getThrust() const;
  void setThrust(const float thrust);

  float getSpeedLimit() const;
  void setSpeedLimit(const float speedLimit);

  SDL_Keycode getKey() const;
  void setKey(const SDL_Keycode key);

 protected:
  SDL_Keycode key_;
  float thrust_;
  float speedLimit_;
};
