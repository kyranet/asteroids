#pragma once
#include "GameObjectPool.h"
#include "ImageGC.h"
#include "NaturalMovePC.h"
#include "RotatingPC.h"
#include "ShowUpAtOppositeSidePC.h"
#include "Asteroid.h"

class Asteroids : public GameObjectPool<Asteroid, 50> {
  ImageGC asteroidImage_;
  NaturalMovePC naturalMove_;
  RotatingPC rotating_;
  ShowUpAtOppositeSidePC showUpAtOppositeSide_;

 public:
  explicit Asteroids(SDLGame* game);
  virtual ~Asteroids();
};
