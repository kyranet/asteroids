#include "GameStatusViewGC.h"
#include "GameManager.h"

void GameStatusViewGC::render(Container* c, Uint32) {
  const auto gameManager = static_cast<GameManager*>(c);  // NOLINT

  if (gameManager->isRunning()) {
    string gameOverText;
    switch (gameManager->getWinner()) {
      case 0:
        // Do not print anything at all, just return early.
        return;
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

    Texture gameOverTexture(
        c->getGame()->getRenderer(), gameOverText,
        *c->getGame()->getServiceLocator()->getFonts()->getFont(
            Resources::ARIAL24),
        {COLOR(0x0022FFFF)});
    gameOverTexture.render(
        c->getGame()->getRenderer(),
        c->getGame()->getWindowWidth() / 2 - gameOverTexture.getWidth() / 2,
        c->getGame()->getWindowHeight() - 420);
  } else {
    const auto continueText = "Press ENTER to Continue";
    Texture gameOverTexture(
        c->getGame()->getRenderer(), continueText,
        *c->getGame()->getServiceLocator()->getFonts()->getFont(
            Resources::ARIAL24),
        {COLOR(0x0022FFFF)});
    gameOverTexture.render(
        c->getGame()->getRenderer(),
        c->getGame()->getWindowWidth() / 2 - gameOverTexture.getWidth() / 2,
        c->getGame()->getWindowHeight() - 400);
  }
}
