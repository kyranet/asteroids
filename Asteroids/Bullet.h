#pragma once
#include "Container.h"

class Bullet : public Container {
public:
    Bullet();
    explicit Bullet(SDLGame* game);
    virtual ~Bullet();
};
