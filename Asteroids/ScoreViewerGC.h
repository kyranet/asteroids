#pragma once
#include "GraphicsComponent.h"

class ScoreViewerGC final : public GraphicsComponent {
 public:
  ScoreViewerGC() = default;
  virtual ~ScoreViewerGC() = default;
  void render(Container* c, Uint32 time) override;
};
