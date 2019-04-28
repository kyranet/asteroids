#include "BulletsBlackHolesCollisionPC.h"
#include "AsteroidsGame.h"
#include "BlackHole.h"
#include "Bullet.h"
#include "Collisions.h"
#include "GameManager.h"
#include "Messages_defs.h"

void BulletsBlackHolesCollisionPC::update(Container* c, Uint32) {
  const auto gameManager = reinterpret_cast<GameManager*>(c);

  // If the game is not running, exit immediately from the update
  if (!gameManager->isRunning()) return;

  for (auto bullet : *bullets_) {
    if (!bullet->isActive()) continue;

    for (auto& blackHole : *blackHoles_) {
      // If the asteroid is not active, skip
      if (!blackHole->isActive()) continue;
      // If there are no collisions, skip
      if (!Collisions::collidesWithRotation(bullet, blackHole)) continue;

      c->globalSend(this, msg::BulletBlackHoleCollision(
          msg::None, msg::Broadcast, bullet, blackHole));
    }
  }
}

void BulletsBlackHolesCollisionPC::receive(Container*, const msg::Message& msg) {
  switch (msg.type_) {
    case msg::BLACKHOLES_INFO: {
      const auto info = reinterpret_cast<const msg::BlackHolesInfo&>(msg);
      blackHoles_ = info.blackHoles_;
      break;
    }
    case msg::BULLETS_INFO: {
      const auto info = reinterpret_cast<const msg::BulletsInfo&>(msg);
      bullets_ = info.bullets_;
      break;
    }
    default:
      break;
  }
}