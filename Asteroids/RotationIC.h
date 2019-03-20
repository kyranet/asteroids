#pragma once
#include "InputComponent.h"

class RotationIC : public InputComponent {
 public:
  RotationIC();
  RotationIC(const SDL_Keycode keyLeft, const SDL_Keycode keyRight,
             const float alpha);
  virtual ~RotationIC();
  virtual void handleInput(Container* c, Uint32 time, const SDL_Event& event);

  float getAlpha() const;
  void setAlpha(const float alpha);

  SDL_Keycode getKeyLeft() const;
  void setKeyLeft(const SDL_Keycode keyLeft);

  SDL_Keycode getKeyRight() const;
  void setKeyRight(const SDL_Keycode keyRight);

 protected:
  SDL_Keycode keyLeft_;
  SDL_Keycode keyRight_;
  float alpha_;
};
