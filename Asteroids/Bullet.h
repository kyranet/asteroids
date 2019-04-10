#pragma once
#include "Container.h"

class Bullet final : public Container {
    int power_;
public:
    Bullet();
    explicit Bullet(SDLGame* game);
    virtual ~Bullet();

    int getPower() const;
    void setPower(int power);
};
