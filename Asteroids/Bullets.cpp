#include "Bullets.h"
#include "Bullet.h"
#include "Messages_defs.h"

Bullets::Bullets(SDLGame* game)
    : GameObjectPool(game),
      bulletImage_(getGame()->getServiceLocator()->getTextures()->getTexture(
          Resources::WhiteRect)) {
  setId(msg::BulletsShooter);
  for (auto bullet : getAllObjects()) {
    bullet->addC(&bulletImage_);
    bullet->addC(&naturalMove_);
    bullet->addC(&deactivate_);
  }
  setActive(false);
}

Bullets::~Bullets() = default;

void Bullets::receive(const void*, const msg::Message& msg) {
  switch (msg.type_) {
    case msg::GAME_START:
      globalSend(this, msg::BulletsInfo(msg::BulletsShooter, msg::Broadcast,
                                        &getAllObjects()));
      break;
    case msg::ROUND_START:
      setActive(true);
      break;
    case msg::ROUND_OVER:
      deactiveAllObjects();
      setActive(false);
      break;
    case msg::BULLET_ASTEROID_COLLISION: {
      const auto collision =
          static_cast<const msg::BulletAsteroidCollision&>(msg);  // NOLINT
      auto bullet = collision.bullet_;
      bullet->setActive(false);
      getGame()->getServiceLocator()->getAudios()->playChannel(
          Resources::Explosion, 0);
      break;
    }
    case msg::FIGHTER_SHOOT: {
      auto bullet = getUnusedObject();
      if (bullet == nullptr) return;
      bullet->setWidth(1);
      bullet->setHeight(5);

      const auto shoot = static_cast<const msg::Shoot&>(msg);  // NOLINT
      const auto position = shoot.pos_;
      bullet->setPosition(position - Vector2D(width_ / 2, height_));

      const auto direction = shoot.dir_;
      bullet->setVelocity(direction * 5);
      bullet->setRotation(Vector2D(0, -1).angle(direction));
      bullet->setActive(true);

      getGame()->getServiceLocator()->getAudios()->playChannel(
          Resources::GunShot, 0);
      break;
    }
    default:
      break;
  }
}
