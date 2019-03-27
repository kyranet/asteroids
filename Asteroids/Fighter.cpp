#include "Fighter.h"
#include "Messages_defs.h"

Fighter::Fighter(SDLGame* game, const int width, const int height,
                 const Vector2D& position)
    : Container(game),
      fighterImage_(game->getServiceLocator()->getTextures()->getTexture(
                        Resources::Airplanes),
                    {47, 90, 207, 250}),
      rotation_(SDLK_RIGHT, SDLK_LEFT, 5),
      thrust_(SDLK_UP, 0.5, 2.0),
      reduceSpeed_(0.995f),
      normalGun_(SDLK_SPACE) {
  setId(msg::Fighter);
  setWidth(width);
  setHeight(height);
  setPosition(position);
  setVelocity({0.0, 0.0});
  setRotation(90);
  setActive(false);
}

Fighter::~Fighter() = default;

void Fighter::handleInput(const Uint32 time, const SDL_Event& event) {
  if (event.type == SDL_KEYDOWN) {
    rotation_.handleInput(this, time, event);
    thrust_.handleInput(this, time, event);
    normalGun_.handleInput(this, time, event);
  }
}

void Fighter::update(const Uint32 time) {
  naturalMove_.update(this, time);
  oppositeSide_.update(this, time);
  reduceSpeed_.update(this, time);
}

void Fighter::render(const Uint32 time) { fighterImage_.render(this, time); }

void Fighter::receive(const void* senderObj, const msg::Message& msg) {
  Container::receive(senderObj, msg);
  switch (msg.type_) {
    case msg::GAME_START:
      globalSend(this, msg::FighterInfo(msg::Fighter, msg::Broadcast, this));
      break;
    case msg::ROUND_START:
      setPosition({400, 300});
      setVelocity(Vector2D(0, 0));
      setRotation(90);
      setActive(true);
      break;
    case msg::ROUND_OVER:
      setActive(false);
      break;
    default:
      break;
  }
}
