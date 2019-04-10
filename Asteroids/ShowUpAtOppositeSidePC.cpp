#include "ShowUpAtOppositeSidePC.h"

ShowUpAtOppositeSidePC::ShowUpAtOppositeSidePC() = default;
ShowUpAtOppositeSidePC::~ShowUpAtOppositeSidePC() = default;

void ShowUpAtOppositeSidePC::update(Container* c, Uint32 time) {
  const auto game = c->getGame();
  const auto width = c->getWidth();
  const auto height = c->getHeight();
  auto position = c->getPosition();

  if (position.getX() + width < 0) {
    position.setX(game->getWindowWidth());
  } else if (position.getX() > game->getWindowWidth()) {
    position.setX(1 - width);
  }

  if (position.getY() + height < 0) {
    position.setY(game->getWindowHeight());
  } else if (position.getY() > game->getWindowHeight()) {
    position.setY(1 - height);
  }

  c->setPosition(position);
}
