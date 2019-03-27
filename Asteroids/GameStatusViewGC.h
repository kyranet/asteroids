#pragma once
#include "GraphicsComponent.h"

class GameStatusViewGC final : public GraphicsComponent {
 public:
  GameStatusViewGC() = default;
  virtual ~GameStatusViewGC() = default;
  void render(Container* c, Uint32 time) override;
};
