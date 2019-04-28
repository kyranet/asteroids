#include "Asteroids.h"
#include <sstream>
#include <stdexcept>
#include "AsteroidsGame.h"
#include "Logger.h"
#include "Messages_defs.h"

Asteroids::Asteroids(SDLGame* game)
    : GameObjectPool<Asteroid, 50>(game),
      asteroidImage_(getGame()->getServiceLocator()->getTextures()->getTexture(
          Resources::Asteroid)),
      rotating_(5) {
  setId(msg::Asteroids);
  setActive(false);
  for (auto asteroid : getAllObjects()) {
    asteroid->setGenerations(3);
    asteroid->addC(&asteroidImage_);
    asteroid->addC(&naturalMove_);
    asteroid->addC(&rotating_);
    asteroid->addC(&showUpAtOppositeSide_);
  }
}

Asteroids::~Asteroids() = default;

void Asteroids::receive(const void*, const msg::Message& msg) {
  switch (msg.type_) {
    case msg::GAME_START: {
      globalSend(this, msg::AsteroidsInfo(msg::Asteroids, msg::Broadcast,
                                          &getAllObjects()));
      break;
    }
    case msg::ROUND_START: {
      roundStart(msg);
      break;
    }
    case msg::ROUND_OVER: {
      deactiveAllObjects();
      setActive(false);
      break;
    }
    case msg::BULLET_ASTEROID_COLLISION: {
      bulletAsteroidCollision(msg);
      break;
    }
    case msg::BLACKHOLE_ASTEROID_COLLISION: {
      blackHoleAsteroidCollision(msg);
      break;
    }
    default:
      break;
  }
}

void Asteroids::roundStart(const msg::Message&) {
  auto r = getGame()->getServiceLocator()->getRandomGenerator();

  setActive(true);
  for (auto i = 0; i < 10; i++) {
    auto a = getUnusedObject();
    // If there are no unused objects, it's not possible for this loop to
    // continue running.
    if (a == nullptr) return;
    a->setWidth(20);
    a->setHeight(20);
    int x, y;
    const auto side = r->nextInt(0, 4);
    switch (side) {
      case 0:  // Right side
        x = 0;
        y = r->nextInt(0, getGame()->getWindowHeight());
        break;
      case 1:  // Top side
        x = r->nextInt(0, getGame()->getWindowHeight());
        y = 0;
        break;
      case 2:  // Bottom side
        x = getGame()->getWindowWidth();
        y = r->nextInt(0, getGame()->getWindowHeight());
        break;
      case 3:  // Left side
        x = r->nextInt(0, getGame()->getWindowHeight());
        y = getGame()->getWindowHeight();
        break;
      default:
        throw std::runtime_error("Unreachable");
    }

    auto p = Vector2D(x, y);
    a->setPosition(p);

    auto c = Vector2D(getGame()->getWindowWidth() / 2.0,
                      getGame()->getWindowHeight() / 2.0);
    auto v = (c - p).normalize() * (r->nextInt(1, 10) / 10.0);
    a->setVelocity(v);
    a->setActive(true);

    Logger::getInstance()->log([p, v]() {
      stringstream s;
      s << "New asteroid: " << p << " " << v;
      return s.str();
    });
  }
}

void Asteroids::bulletAsteroidCollision(const msg::Message& msg) {
  const auto collision =
      reinterpret_cast<const msg::BulletAsteroidCollision&>(msg);
  auto x = collision.asteroid_;

  const auto points = 4 - x->getGenerations();
  globalSend(this,
             msg::AsteroidDestroyed(msg::Asteroids, msg::Broadcast, points));

  if (x->getGenerations() > 1) {
    for (auto i = 1; i <= 2; i++) {
      auto a = getUnusedObject();
      a->setWidth(x->getWidth() * 0.75);
      a->setHeight(x->getHeight() * 0.75);
      a->setGenerations(x->getGenerations() - 1);

      auto v = x->getVelocity() * 1.1;
      a->setVelocity(v);
      a->setPosition(x->getPosition() + v);
      a->setRotation(x->getRotation() + i * 30);

      a->setActive(true);
    }
  }

  x->setActive(false);

  auto remainingAsteroids = 0;
  for (auto a : getAllObjects()) {
    if (a->isActive()) {
      remainingAsteroids++;
    }
  }
  if (remainingAsteroids == 0) {
    globalSend(this, msg::Message(msg::NO_MORE_ASTEROIDS, msg::Asteroids,
                                  msg::Broadcast));
  }

  getGame()->getServiceLocator()->getAudios()->playChannel(Resources::Explosion,
                                                           0);
}

void Asteroids::blackHoleAsteroidCollision(const msg::Message& msg) {
  const auto collision =
      reinterpret_cast<const msg::BlackHoleAsteroidCollision&>(msg);
  const auto fx = static_cast<int>(collision.fighter_->getPosition().getX()),
             fy = static_cast<int>(collision.fighter_->getPosition().getY());
  const auto mx = getGame()->getWindowWidth(),
             my = getGame()->getWindowHeight();
  const auto random = getGame()->getServiceLocator()->getRandomGenerator();

  // Calculate x
  int x;
  do {
    x = random->nextInt(0, mx);
  } while (abs(fx - x) < 100);

  // Calculate y
  int y;
  do {
    y = random->nextInt(0, my);
  } while (abs(fy - y) < 100);

  // Set the position for the asteroid
  collision.asteroid_->setPosition(Vector2D(x, y));
}
