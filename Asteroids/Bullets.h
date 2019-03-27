#pragma once
#include "DeactivateOnBorderExitPC.h"
#include "GameObjectPool.h"
#include "ImageGC.h"
#include "Messages_defs.h"
#include "NaturalMovePC.h"
#include "Bullet.h"

class Bullets final : public GameObjectPool<Bullet, 10> {
  NaturalMovePC naturalMove_;
  DeactivateOnBorderExitPC deactivate_;
  ImageGC bulletImage_;

 public:
  explicit Bullets(SDLGame* game);
  virtual ~Bullets();
  void receive(const void* senderObj, const msg::Message& msg) override;
};
