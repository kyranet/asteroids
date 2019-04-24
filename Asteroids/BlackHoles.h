#pragma once
#include "BlackHole.h"
#include "GameObjectPool.h"
#include "ImageGC.h"
#include "RotatingPC.h"

class BlackHoles final : public GameObjectPool<BlackHole, 8> {
  ImageGC blackHoleImage_;
  RotatingPC rotating_;
  int round_ = 0;

 public:
  explicit BlackHoles(SDLGame* game);
  virtual ~BlackHoles();
  void receive(const void* senderObj, const msg::Message& msg) override;
  void roundStart();
  void bulletAsteroidCollision(const msg::Message& msg);
};
