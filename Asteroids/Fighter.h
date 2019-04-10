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
  void receive(const void* senderObj, const msg::Message& msg) override;
};
