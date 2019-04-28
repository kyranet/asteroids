#pragma once
#include "Container.h"

class BlackHole final : public Container {
 public:
  BlackHole();
  explicit BlackHole(SDLGame* game);
  ~BlackHole();
};
