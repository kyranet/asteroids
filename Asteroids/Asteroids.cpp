#include "Asteroids.h"

Asteroids::Asteroids(SDLGame* game)
    : GameObjectPool<Asteroid, 50>(game),
      asteroidImage_(ImageGC()),
      naturalMove_(NaturalMovePC()),
      rotating_(RotatingPC(5)),
      showUpAtOppositeSide_(ShowUpAtOppositeSidePC()) {
  for (auto asteroid : getAllObjects()) {
    asteroid->addC(&asteroidImage_);
    asteroid->addC(&naturalMove_);
    asteroid->addC(&rotating_);
    asteroid->addC(&showUpAtOppositeSide_);
  }
}

Asteroids::~Asteroids() = default;
