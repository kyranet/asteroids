#pragma once

#include <vector>

#include "Asteroids.h"
#include "Fighter.h"
#include "GameObject.h"
#include "SDLGame.h"
#include "GameManager.h"
#include "Bullets.h"

class AsteroidsGame final : public SDLGame {
 public:
  AsteroidsGame();
  virtual ~AsteroidsGame();

  // from SDLGame
  void start() override;
  void stop() override;

 private:
  void initGame();
  void closeGame();
  void handleInput(Uint32 time);
  void update(Uint32 time);
  void render(Uint32 time);

  const static int _WINDOW_WIDTH_ = 800;
  const static int _WINDOW_HEIGHT_ = 600;
  bool exit_;
  std::vector<GameObject*> actors_;
  Fighter fighter_;
  Asteroids asteroids_;
  Bullets bullets_;
  GameManager gameManager_;
};
