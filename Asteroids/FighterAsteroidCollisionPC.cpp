#include "FighterAsteroidCollisionPC.h"
#include "Asteroids.h"
#include "AsteroidsGame.h"
#include "Collisions.h"
#include "GameManager.h"

FighterAsteroidCollisionPC::FighterAsteroidCollisionPC()
    : fighter_(nullptr), asteroids_(nullptr) {}

void FighterAsteroidCollisionPC::update(Container* c, Uint32 time) {
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
