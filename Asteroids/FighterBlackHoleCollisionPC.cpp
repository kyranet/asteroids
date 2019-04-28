#include "FighterBlackHoleCollisionPC.h"
#include "Collisions.h"
#include "GameManager.h"
#include "Messages_defs.h"

FighterBlackHoleCollisionPC::FighterBlackHoleCollisionPC() = default;

FighterBlackHoleCollisionPC::~FighterBlackHoleCollisionPC() = default;

void FighterBlackHoleCollisionPC::update(Container* c, Uint32) {
  if (fighter_ != nullptr && blackHoles_ != nullptr) {
    if (reinterpret_cast<GameManager*>(c)->isRunning()) {
      for (auto i : *blackHoles_) {
        BlackHole* blackHole = i;
        if (fighter_->isActive() && i->isActive() &&
            Collisions::collidesWithRotation(fighter_, blackHole)) {
          c->globalSend(
              this, msg::FighterBlackHoleCollision(msg::None, msg::Broadcast,
                                                   fighter_, blackHole));
        }
      }
    }
  }
}

void FighterBlackHoleCollisionPC::receive(Container*,
                                          const msg::Message& msg) {
  switch (msg.type_) {
    case msg::BLACKHOLES_INFO: {
      blackHoles_ =
          reinterpret_cast<const msg::BlackHolesInfo&>(msg).blackHoles_;
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
