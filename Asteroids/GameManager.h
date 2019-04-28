#pragma once
#include "BlackHoleAsteroidCollisionPC.h"
#include "BulletsAsteroidsCollisionPC.h"
#include "BulletsBlackHolesCollisionPC.h"
#include "Container.h"
#include "FighterAsteroidCollisionPC.h"
#include "FighterBlackHoleCollisionPC.h"
#include "GameCtrlIC.h"
#include "GameStatusViewGC.h"
#include "LivesViewerGC.h"
#include "ScoreViewerGC.h"

class GameManager final : public Container {
 public:
  explicit GameManager(SDLGame* game);
  virtual ~GameManager();
  void receive(const void* senderObj, const msg::Message& msg) override;
  bool isRunning() const;
  bool isGameOver() const;
  int getLives() const;
  int getScore() const;
  int getWinner() const;

 private:
  static int const maxLives_ = 3;
  bool running_;
  bool gameOver_;
  int score_;
  int lives_;
  // TODO: Ask the professor why is this not an enum
  int winner_;  // 0 = none, 1 = asteroids, 2 = fighter

  // Components of GameManager
  GameCtrlIC gameCtrl_;
  ScoreViewerGC scoreViewer_;
  GameStatusViewGC gameStatusView_;
  LivesViewerGC livesViewer_;
  FighterAsteroidCollisionPC fighterAsteroidCollision_;
  BulletsAsteroidsCollisionPC bulletsAsteroidsCollision_;
  BulletsBlackHolesCollisionPC bulletsBlackHolesCollision_;
  FighterBlackHoleCollisionPC fighterBlackHoleCollision_;
  BlackHoleAsteroidCollisionPC blackHoleAsteroidCollision_;
};
