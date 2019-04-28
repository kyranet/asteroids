#include "GameManager.h"
#include "Logger.h"
#include "Messages_defs.h"

GameManager::GameManager(SDLGame* game)
    : Container(game),
      running_(false),
      gameOver_(true),
      score_(0),
      lives_(maxLives_),
      winner_(0) {
  setId(msg::GameManager);
  addC(&gameCtrl_);
  addC(&scoreViewer_);
  addC(&livesViewer_);
  addC(&gameStatusView_);
  addC(&fighterAsteroidCollision_);
  addC(&bulletsAsteroidsCollision_);
  addC(&fighterBlackHoleCollision_);
  addC(&blackHoleAsteroidCollision_);
  addC(&bulletsBlackHolesCollision_);
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
          Resources::ImperialMarch);
      Logger::getInstance()->log("Round Start");
      break;
    }
    case msg::ROUND_OVER: {
      Logger::getInstance()->log("Round End");
      break;
    }
    case msg::ASTEROID_DESTROYED: {
      const auto asteroidDestroyed =
          reinterpret_cast<const msg::AsteroidDestroyed&>(msg);
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
      --lives_;
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
    case msg::FIGHTER_BLACKHOLE_COLLISION: {
      getGame()->getServiceLocator()->getAudios()->playChannel(
          Resources::Explosion, 0, -1);
      getGame()->getServiceLocator()->getAudios()->haltMusic();

      running_ = false;
      --lives_;
      globalSend(this,
                 msg::Message(msg::ROUND_OVER, msg::None, msg::Broadcast));

      if (lives_ == 0) {
        gameOver_ = true;
        winner_ = 1;
        globalSend(this,
                   msg::Message(msg::GAME_OVER, msg::None, msg::Broadcast));
      }
      Logger::getInstance()->log("Round End");
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
