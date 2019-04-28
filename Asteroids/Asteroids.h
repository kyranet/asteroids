#pragma once
#include "Asteroid.h"
#include "GameObjectPool.h"
#include "ImageGC.h"
#include "NaturalMovePC.h"
#include "RotatingPC.h"
#include "ShowUpAtOppositeSidePC.h"

class Asteroids final : public GameObjectPool<Asteroid, 50> {
  ImageGC asteroidImage_;
  NaturalMovePC naturalMove_;
  RotatingPC rotating_;
  ShowUpAtOppositeSidePC showUpAtOppositeSide_;

  void roundStart(const msg::Message& msg);
  void bulletAsteroidCollision(const msg::Message& msg);
  void blackHoleAsteroidCollision(const msg::Message& msg);

 public:
  explicit Asteroids(SDLGame* game);
  ~Asteroids();
  void receive(const void* senderObj, const msg::Message& msg) override;
};
