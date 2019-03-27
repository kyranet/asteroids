#include "GameCtrlIC.h"
#include "GameManager.h"
#include "Messages_defs.h"

void GameCtrlIC::handleInput(Container* c, Uint32 time,
                             const SDL_Event& event) {
  // If it's not a key down, don't handle any input
  if (event.type != SDL_KEYDOWN) return;

  const auto gameManager = static_cast<GameManager*>(c);  // NOLINT
  if (!gameManager->isRunning() && event.key.keysym.sym == SDLK_RETURN) {
    if (gameManager->isRunning()) {
      c->globalSend(this,
                    msg::Message(msg::GAME_START, c->getId(), msg::Broadcast));
    }
    c->globalSend(this,
                  msg::Message(msg::ROUND_START, c->getId(), msg::Broadcast));
  }
}
