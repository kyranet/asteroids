#include "Bullet.h"

Bullet::Bullet() : Bullet(nullptr) {}
Bullet::Bullet(SDLGame* game) : Container(game) {}

Bullet::~Bullet() = default;
