#pragma once
#include "GraphicsComponent.h"

class LivesViewerGC final : public GraphicsComponent {
 public:
  LivesViewerGC() = default;
  virtual ~LivesViewerGC() = default;
  void render(Container* c, Uint32 time) override;
};
