#pragma once
#include "Container.h"
#include "GunIC.h"
#include "ImageGC.h"
#include "NaturalMovePC.h"
#include "ReduceSpeedPC.h"
#include "RotationIC.h"
#include "ShowUpAtOppositeSidePC.h"
#include "ThrustIC.h"

class Fighter final : public Container {
  ImageGC fighterImage_;
  NaturalMovePC naturalMove_;
  ShowUpAtOppositeSidePC oppositeSide_;
  RotationIC rotation_;
  ThrustIC thrust_;
  ReduceSpeedPC reduceSpeed_;
  GunIC normalGun_;

 public:
  Fighter(SDLGame* game, int width, int height, const Vector2D& position);
  virtual ~Fighter();
  void update(Uint32 time) override;
  void render(Uint32 time) override;
  void handleInput(Uint32 time, const SDL_Event& event) override;
  void receive(const void* senderObj, const msg::Message& msg) override;
};
