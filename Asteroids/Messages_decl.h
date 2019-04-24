#pragma once

namespace msg {

enum ObjectId {
  None,  // special value indicating no object (or more precisely component)
  Broadcast,  // special value indicating all objects
  Fighter,
  Asteroids,
  Bullets,
  BulletsShooter,
  GameManager,
  BlackHoles
};

enum MessageType {
  GAME_START,
  GAME_OVER,
  ROUND_START,
  ROUND_OVER,
  FIGHTER_SHOOT,
  BULLET_ASTEROID_COLLISION,
  FIGHTER_ASTEROID_COLLISION,
  FIGHTER_BLACKHOLE_COLLISION,
  ASTEROID_DESTROYED,
  NO_MORE_ASTEROIDS,
  FIGHTER_INFO,
  BULLETS_INFO,
  ASTEROIDS_INFO,
  BLACKHOLES_INFO
};

struct Message;

}  // namespace msg
