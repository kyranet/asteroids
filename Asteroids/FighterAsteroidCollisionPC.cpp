#include "FighterAsteroidCollisionPC.h"
#include "Asteroids.h"
#include "AsteroidsGame.h"
#include "Collisions.h"
#include "GameManager.h"

FighterAsteroidCollisionPC::FighterAsteroidCollisionPC()
    : fighter_(nullptr), asteroids_(nullptr) {}

void FighterAsteroidCollisionPC::update(Container* c, Uint32) {
  // If fighter or asteroids are null, exit immediately from the update
  if (fighter_ == nullptr || asteroids_ == nullptr) return;

  // If the fighter is not active, exit immediately from the update
  if (!fighter_->isActive()) return;

  const auto gameManager = static_cast<GameManager*>(c);  // NOLINT

  // If the game is not running, exit immediately from the update
  if (!gameManager->isRunning()) return;

  for (auto asteroid : *asteroids_) {
    // If the asteroid is not active, skip
    if (!asteroid->isActive()) continue;
    // If there are no collisions, skip
    if (!Collisions::collidesWithRotation(fighter_, asteroid)) continue;

    c->globalSend(this, msg::FighterAsteroidCollision(msg::None, msg::Broadcast,
                                                      fighter_, asteroid));
  }
}

void FighterAsteroidCollisionPC::receive(Container*,
                                         const msg::Message& msg) {
  switch (msg.type_) {
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
