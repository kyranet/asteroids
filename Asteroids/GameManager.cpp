#include "GameManager.h"
#include "Messages_defs.h"

GameManager::GameManager(SDLGame* game)
    : Container(game),
      running_(false),
      gameOver_(true),
      score_(0),
      lives_(maxLives_),
      winner_(0) {
  addC(&gameCtrl_);
  addC(&scoreViewer_);
  addC(&livesViewer_);
  addC(&gameStatusView_);
  addC(&fighterAsteroidCollision_);
  addC(&bulletsAsteroidsCollision_);
}

GameManager::~GameManager() = default;

void GameManager::receive(const void* senderObj, const msg::Message& msg) {
  Container::receive(senderObj, msg);

  switch (msg.type_) {
    case msg::GAME_START: {
      gameOver_ = false;
      winner_ = 0;
      score_ = 0;
      lives_ = maxLives_;
      break;
    }
    case msg::ROUND_START: {
      running_ = true;
      getGame()->getServiceLocator()->getAudios()->playMusic(
          Resources::ImperialMarch, -1);
      break;
    }
    case msg::ASTEROID_DESTROYED: {
      const auto asteroidDestroyed =
          static_cast<const msg::AsteroidDestroyed&>(msg);  // NOLINT
      score_ += asteroidDestroyed.points_;
      break;
    }
    case msg::NO_MORE_ASTEROIDS: {
      running_ = false;
      gameOver_ = true;
      winner_ = 2;
      getGame()->getServiceLocator()->getAudios()->haltMusic();
      globalSend(this,
                 msg::Message(msg::ROUND_OVER, msg::None, msg::Broadcast));
      globalSend(this, msg::Message(msg::GAME_OVER, msg::None, msg::Broadcast));
      break;
    }
    case msg::FIGHTER_ASTEROID_COLLISION: {
      getGame()->getServiceLocator()->getAudios()->playChannel(
          Resources::Explosion, 0);
      getGame()->getServiceLocator()->getAudios()->haltMusic();

      running_ = false;
      lives_--;
      globalSend(this,
                 msg::Message(msg::ROUND_OVER, msg::None, msg::Broadcast));

      if (lives_ == 0) {
        gameOver_ = true;
        winner_ = 1;
        globalSend(this,
                   msg::Message(msg::GAME_OVER, msg::None, msg::Broadcast));
      }
      break;
    }
    default:
      break;
  }
}

bool GameManager::isRunning() const { return running_; }
bool GameManager::isGameOver() const { return gameOver_; }
int GameManager::getWinner() const { return winner_; }
int GameManager::getLives() const { return lives_; }
int GameManager::getScore() const { return score_; }
