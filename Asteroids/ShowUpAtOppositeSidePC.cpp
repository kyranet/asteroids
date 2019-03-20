#include "ShowUpAtOppositeSidePC.h"

ShowUpAtOppositeSidePC::ShowUpAtOppositeSidePC() {}

ShowUpAtOppositeSidePC::~ShowUpAtOppositeSidePC() {}

void ShowUpAtOppositeSidePC::update(Container* c, Uint32 time) {
  auto game = c->getGame();
  auto position = c->getPosition();

  if (position.getX() < 0) {
    position.setX(game->getWindowWidth());
  } else if (position.getX() > game->getWindowWidth()) {
    position.setX(0);
  }

  if (position.getY() < 0) {
    position.setY(game->getWindowHeight());
  } else if (position.getY() > game->getWindowHeight()) {
    position.setY(0);
  }
}
