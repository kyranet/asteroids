#include "Bullet.h"

Bullet::Bullet() : Bullet(nullptr) {}
Bullet::Bullet(SDLGame* game) : Container(game) {}

Bullet::~Bullet() = default;

int Bullet::getPower() const { return power_; }
void Bullet::setPower(int p) { power_ = p; }
