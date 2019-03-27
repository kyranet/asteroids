#include "Asteroid.h"

Asteroid::Asteroid() = default;
Asteroid::Asteroid(SDLGame* game) : Container(game) {}
Asteroid::~Asteroid() = default;

int Asteroid::getGenerations() const { return generations_; }

void Asteroid::setGenerations(const int generations) { generations_ = generations; }
