#include "BlackHoles.h"
#include <cmath>
#include "BlackHole.h"
#include "Messages_defs.h"

BlackHoles::BlackHoles(SDLGame* game)
    : GameObjectPool<BlackHole, 8>(game),
      blackHoleImage_(getGame()->getServiceLocator()->getTextures()->getTexture(
          Resources::Asteroid)),
      rotating_(5) {
  setId(msg::BlackHoles);
  setActive(false);
  for (auto blackHole : getAllObjects()) {
    blackHole->addC(&blackHoleImage_);
    blackHole->addC(&rotating_);
    blackHole->setWidth(50);
    blackHole->setHeight(50);
  }
}

BlackHoles::~BlackHoles() = default;

void BlackHoles::receive(const void*, const msg::Message& msg) {
  switch (msg.type_) {
    case msg::GAME_START: {
      globalSend(this, msg::BlackHolesInfo(msg::BlackHoles, msg::Broadcast,
                                           &getAllObjects()));
      break;
    }
    case msg::GAME_OVER: {
      round_ = 0;
      break;
    }
    case msg::ROUND_START: {
      roundStart();
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
    default:
      break;
  }
}

void BlackHoles::roundStart() {
  const auto random = getGame()->getServiceLocator()->getRandomGenerator();
  setActive(true);

  const auto width = getGame()->getWindowWidth();
  const auto height = getGame()->getWindowHeight();
  for (int i = 0, m = static_cast<int>(std::pow(2, ++round_)); i < m; i++) {
    BlackHole* blackHole = getUnusedObject();
    blackHole->setWidth(50);
    blackHole->setHeight(50);
    int x, y;
    switch (random->nextInt(0, 4)) {
      case 0:  // right side
        x = random->nextInt(0, static_cast<int>(width * 0.25));
        y = random->nextInt(0, height);
        break;
      case 1:  // top side
        x = random->nextInt(0, width);
        y = random->nextInt(0, static_cast<int>(height * 0.25));
        break;
      case 2:  // left side
        x = random->nextInt(static_cast<int>(width * 0.75), width);
        y = random->nextInt(0, height);
        break;
      default:  // bottom side
        x = random->nextInt(0, width);
        y = random->nextInt(static_cast<int>(height * 0.75), height);
        break;
    }

    Vector2D p = Vector2D(x, y);
    blackHole->setPosition(p);

    blackHole->setActive(true);
  }
}

void BlackHoles::bulletAsteroidCollision(const msg::Message&) {}