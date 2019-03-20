#pragma once
#include "Container.h"
#include "GunIC.h"
#include "ImageGC.h"
#include "NaturalMovePC.h"
#include "ReduceSpeedPC.h"
#include "RotationIC.h"
#include "ShowUpAtOppositeSidePC.h"
#include "ThrustIC.h"

class Fighter : public Container {
 public:
  Fighter(SDLGame* game);
  virtual ~Fighter();

 private:
  ImageGC fighterImage_;
  NaturalMovePC naturalMove_;
  ShowUpAtOppositeSidePC oppositeSide_;
  RotationIC rotation_;
  ThrustIC thrust_;
  ReduceSpeedPC reduceSpeed_;
  GunIC normalGun_;
};
