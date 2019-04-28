#pragma once
#include "Container.h"

class Asteroid final : public Container {
  int generations_ = 0;

 public:
  Asteroid();
  explicit Asteroid(SDLGame* game);
  ~Asteroid();
  int getGenerations() const;
  void setGenerations(int generations);
};
