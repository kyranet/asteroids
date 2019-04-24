#include "AsteroidsGame.h"
#include "InputHandler.h"
#include "Logger.h"

using namespace std;

AsteroidsGame::AsteroidsGame()
    : SDLGame("Asteroids", _WINDOW_WIDTH_, _WINDOW_HEIGHT_),
      exit_(false),
      fighter_(this, 75, 75,
               {static_cast<double>(getWindowWidth()) / 2.0,
                static_cast<double>(getWindowHeight()) / 2.0}),
      asteroids_(this),
      blackHoles_(this),
      bullets_(this),
      gameManager_(this) {
  initGame();
}

AsteroidsGame::~AsteroidsGame() { closeGame(); }

void AsteroidsGame::initGame() {
  Logger::getInstance()->initInstance("log.txt");

  actors_.push_back(&fighter_);
  actors_.push_back(&asteroids_);
  actors_.push_back(&bullets_);
  actors_.push_back(&gameManager_);
  actors_.push_back(&blackHoles_);

  addObserver(&fighter_);
  addObserver(&asteroids_);
  addObserver(&bullets_);
  addObserver(&gameManager_);
  addObserver(&blackHoles_);
}

void AsteroidsGame::closeGame() {}

void AsteroidsGame::start() {
  exit_ = false;

  while (!exit_) {
    const auto startTime = SDL_GetTicks();
    handleInput(startTime);
    update(startTime);
    render(startTime);

    const auto frameTime = SDL_GetTicks() - startTime;
    if (frameTime < 10) SDL_Delay(10 - frameTime);
  }
}

void AsteroidsGame::stop() { exit_ = true; }

void AsteroidsGame::handleInput(const Uint32 time) {
  const auto input = InputHandler::getInstance();
  input->update();
  if (input->isKeyDown(SDLK_ESCAPE)) {
    exit_ = true;
  } else if (input->isKeyDown(SDLK_f)) {
    const auto flags = SDL_GetWindowFlags(window_);
    if (flags & SDL_WINDOW_FULLSCREEN) {
      SDL_SetWindowFullscreen(window_, 0);
    } else {
      SDL_SetWindowFullscreen(window_, SDL_WINDOW_FULLSCREEN);
    }
  }

  for (auto o : actors_) {
    o->handleInput(time);
  }
}

void AsteroidsGame::update(Uint32 time) {
  for (GameObject* o : actors_) {
    o->update(time);
  }
}

void AsteroidsGame::render(Uint32 time) {
  SDL_SetRenderDrawColor(getRenderer(), COLOR(0x00AAAAFF));
  SDL_RenderClear(getRenderer());

  for (GameObject* o : actors_) {
    o->render(time);
  }

  SDL_RenderPresent(getRenderer());
}
