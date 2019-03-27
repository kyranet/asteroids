#include "DeactivateOnBorderExitPC.h"

void DeactivateOnBorderExitPC::update(Container* c, Uint32 time) {
  auto position = c->getPosition();

  if (position.getX() <= 0 ||
      position.getY() >= c->getGame()->getWindowWidth() ||
      position.getY() <= 0 ||
      position.getY() >= c->getGame()->getWindowHeight()) {
    c->setActive(false);
  }
}
