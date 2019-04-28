#include "BlackHoleAsteroidCollisionPC.h"
#include "Collisions.h"
#include "GameManager.h"
#include "Messages_defs.h"

BlackHoleAsteroidCollisionPC::BlackHoleAsteroidCollisionPC() = default;
BlackHoleAsteroidCollisionPC::~BlackHoleAsteroidCollisionPC() = default;

void BlackHoleAsteroidCollisionPC::update(Container* c, Uint32) {
  if (asteroids_ == nullptr || blackHoles_ == nullptr) return;
  if (!reinterpret_cast<GameManager*>(c)->isRunning()) return;

  for (auto& asteroid : *asteroids_) {
    // If the asteroid is not active, skip.
    if (!asteroid->isActive()) continue;
    for (auto& blackHole : *blackHoles_) {
      // If the blackhole is not active, skip.
      if (!blackHole->isActive()) continue;

      if (Collisions::collidesWithRotation(asteroid, blackHole)) {
        c->globalSend(this, msg::BlackHoleAsteroidCollision(
                                msg::None, msg::Broadcast, asteroid, blackHole,
                                fighter_));
      }
    }
  }
}

void BlackHoleAsteroidCollisionPC::receive(Container*,
                                           const msg::Message& msg) {
  switch (msg.type_) {
    case msg::BLACKHOLES_INFO: {
      blackHoles_ =
          reinterpret_cast<const msg::BlackHolesInfo&>(msg).blackHoles_;
      break;
    }
    case msg::ASTEROIDS_INFO: {
      asteroids_ = reinterpret_cast<const msg::AsteroidsInfo&>(msg).asteroids_;
      break;
    }
    case msg::FIGHTER_INFO: {
      fighter_ = reinterpret_cast<const msg::FighterInfo&>(msg).fighter_;
      break;
    }
    default:
      break;
  }
}
