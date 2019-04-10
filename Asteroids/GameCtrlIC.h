#pragma once
#include "InputComponent.h"

class GameCtrlIC final : public InputComponent {
 public:
  GameCtrlIC() = default;
  virtual ~GameCtrlIC() = default;
  void handleInput(Container* c, Uint32 time) override;
};
