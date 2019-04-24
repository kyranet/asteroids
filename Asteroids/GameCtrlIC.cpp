#include "GameCtrlIC.h"
#include "GameManager.h"
#include "InputHandler.h"
#include "Messages_defs.h"

void GameCtrlIC::handleInput(Container* c, Uint32) {
  // It's only the GameManager what sends messages to this controller
  const auto gameManager = reinterpret_cast<GameManager*>(c);
  if (!gameManager->isRunning() &&
      InputHandler::getInstance()->isKeyDown(SDLK_RETURN)) {
    if (gameManager->isGameOver()) {
      c->globalSend(this,
                    msg::Message(msg::GAME_START, c->getId(), msg::Broadcast));
    }
    c->globalSend(this,
                  msg::Message(msg::ROUND_START, c->getId(), msg::Broadcast));
  }
}
