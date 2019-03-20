#pragma once

#include <vector>
#include "GameObject.h"
#include "Vector2D.h"

// you can replace these lines by corresponding
// includes once the classes are defined

class Asteroid;
class Bullet;

namespace msg {

struct Message {
  Message(msg::MessageType type, msg::ObjectId sender,
          msg::ObjectId destination)
      : type_(type), sender_(sender), destination_(destination) {}

  msg::MessageType type_;
  msg::ObjectId sender_;
  msg::ObjectId destination_;
};

struct Shoot : public msg::Message {
  Shoot(msg::ObjectId sender, msg::ObjectId destination, Vector2D pos,
        Vector2D dir, int bulletType)
      : Message(msg::FIGHTER_SHOOT, sender, destination),
        pos_(pos),
        dir_(dir),
        bulletType_(bulletType) {}

  Vector2D pos_;
  Vector2D dir_;
  int bulletType_;
};

struct BulletAsteroidCollision : public msg::Message {
  BulletAsteroidCollision(msg::ObjectId sender, msg::ObjectId destination,
                          Bullet* bullet, Asteroid* asteroid)
      : Message(msg::BULLET_ASTEROID_COLLISION, sender, destination),
        bullet_(bullet),
        asteroid_(asteroid) {}

  Bullet* bullet_;
  Asteroid* asteroid_;
};

struct FighterAsteroidCollision : public msg::Message {
  FighterAsteroidCollision(msg::ObjectId sender, msg::ObjectId destination,
                           GameObject* fighter, Asteroid* asteroid)
      : Message(msg::FIGHTER_ASTEROID_COLLISION, sender, destination),
        fighter_(fighter),
        asteroid_(asteroid) {}

  GameObject* fighter_;
  Asteroid* asteroid_;
};

struct AsteroidDestroyed : public msg::Message {
  AsteroidDestroyed(msg::ObjectId sender, msg::ObjectId destination, int points)
      : Message(msg::ASTEROID_DESTROYED, sender, destination),
        points_(points) {}

  int points_;
};

struct FighterInfo : public msg::Message {
  FighterInfo(msg::ObjectId sender, msg::ObjectId destination,
              GameObject* fighter)
      : Message(msg::FIGHTER_INFO, sender, destination), fighter_(fighter) {}

  GameObject* fighter_;
};

struct BulletsInfo : public msg::Message {
  BulletsInfo(msg::ObjectId sender, msg::ObjectId destination,
              const std::vector<Bullet*>* bullets)
      : Message(msg::BULLETS_INFO, sender, destination), bullets_(bullets) {}
  const std::vector<Bullet*>* bullets_;
};

struct AsteroidsInfo : public msg::Message {
  AsteroidsInfo(msg::ObjectId sender, msg::ObjectId destination,
                const std::vector<Asteroid*>* asteroids)
      : Message(msg::ASTEROIDS_INFO, sender, destination),
        asteroids_(asteroids) {}
  const std::vector<Asteroid*>* asteroids_;
};

};  // namespace msg
