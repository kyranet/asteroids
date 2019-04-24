#include "LivesViewerGC.h"
#include "GameManager.h"

void LivesViewerGC::render(Container* c, Uint32) {
  const auto gameManager = static_cast<GameManager*>(c);  // NOLINT

  Texture textTexture(c->getGame()->getRenderer(),
                      "Lives " + std::to_string(gameManager->getLives()),
                      *c->getGame()->getServiceLocator()->getFonts()->getFont(
                          Resources::ARIAL24),
                      {COLOR(0x0022FFFF)});
  textTexture.render(
      c->getGame()->getRenderer(),
      c->getGame()->getWindowWidth() / 2 - textTexture.getWidth() / 2,
      c->getGame()->getWindowHeight() - 130);
}
