#include "GameStatusViewGC.h"
#include "GameManager.h"

void GameStatusViewGC::render(Container* c, Uint32 time) {
  const auto gameManager = static_cast<GameManager*>(c);  // NOLINT

  string continueText;
  if (gameManager->isRunning()) {
    string gameOverText;
    switch (gameManager->getWinner()) {
      case 0:
        gameOverText = "";
        break;
      case 1:
        gameOverText = "Game Over! Asteroids Won :(";
        break;
      case 2:
        gameOverText = "Game Over! Fighter Won :)";
        break;
      default:
        std::cerr << "Invalid winner value "
                  << to_string(gameManager->getWinner()) << ".\n";
    }

    continueText = "Press ENTER to Start a New Game";

    Texture gameOverTexture(
        c->getGame()->getRenderer(), gameOverText,
        *c->getGame()->getServiceLocator()->getFonts()->getFont(
            Resources::ARIAL24),
        {COLOR(0x0022FFFF)});
    gameOverTexture.render(c->getGame()->getRenderer(),
                           c->getGame()->getWindowWidth() / 4,
                           c->getGame()->getWindowHeight() - 50);
  } else {
    continueText = "Press ENTER to Continue";
  }

  Texture gameOverTexture(
      c->getGame()->getRenderer(), continueText,
      *c->getGame()->getServiceLocator()->getFonts()->getFont(
          Resources::ARIAL24),
      {COLOR(0x0022FFFF)});
  gameOverTexture.render(c->getGame()->getRenderer(),
                         c->getGame()->getWindowWidth() / 4,
                         c->getGame()->getWindowHeight() - 100);
}
