#include "ScoreViewerGC.h"
#include "GameManager.h"

void ScoreViewerGC::render(Container* c, Uint32 time) {
  const auto gameManager = static_cast<GameManager*>(c);  // NOLINT

  Texture textTexture(c->getGame()->getRenderer(),
                      "Score " + std::to_string(gameManager->getScore()),
                      *c->getGame()->getServiceLocator()->getFonts()->getFont(
                          Resources::ARIAL24),
                      {COLOR(0x0022FFFF)});
  textTexture.render(c->getGame()->getRenderer(), c->getGame()->getWindowWidth() / 4, 30);
}
