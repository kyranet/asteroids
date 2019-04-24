#include "InputHandler.h"

InputHandler* InputHandler::instance_ = nullptr;

void InputHandler::clearState() {
  keyDown_ = false;
  keyUp_ = false;
  kbState_ = nullptr;
  for (auto i = 0; i < 3; i++) {
    mbState_[i] = false;
  }
}

void InputHandler::update() {
  SDL_Event event;

  clearState();

  while (SDL_PollEvent(&event)) {
    switch (event.type) {
      case SDL_KEYDOWN:
        onKeyDown(event);
        break;
      case SDL_KEYUP:
        onKeyUp(event);
        break;
      case SDL_MOUSEMOTION:
        onMouseMotion(event);
        break;
      case SDL_MOUSEBUTTONUP:
        onMouseButtonUp(event);
        break;
      case SDL_MOUSEBUTTONDOWN:
        onMouseButtonDown(event);
        break;
      default:
        break;
    }
  }
}

bool InputHandler::isAnyKeyDown() const { return keyDown_; }

bool InputHandler::isAnyKeyUp() const { return keyUp_; }

bool InputHandler::isKeyDown(const SDL_Scancode key) const {
  return kbState_ != nullptr && kbState_[key] == 1;
}

bool InputHandler::isKeyDown(const SDL_Keycode key) const {
  return isKeyDown(SDL_GetScancodeFromKey(key));
}

const Vector2D& InputHandler::getMousePos() const { return mousePos_; }

int InputHandler::getMouseButtonState(const int b) { return mbState_[b]; }

InputHandler::InputHandler() { clearState(); }

InputHandler::~InputHandler() = default;

void InputHandler::onKeyDown(SDL_Event&) {
  keyDown_ = true;
  kbState_ = SDL_GetKeyboardState(nullptr);
}

void InputHandler::onKeyUp(SDL_Event&) {
  keyUp_ = true;
  kbState_ = SDL_GetKeyboardState(nullptr);
}

void InputHandler::onMouseMotion(SDL_Event& event) {
  mousePos_.set(event.motion.x, event.motion.y);
}

void InputHandler::onMouseButtonUp(SDL_Event& event) {
  if (event.button.button == SDL_BUTTON_LEFT) {
    mbState_[LEFT] = false;
  } else if (event.button.button == SDL_BUTTON_MIDDLE) {
    mbState_[MIDDLE] = false;
  } else if (event.button.button == SDL_BUTTON_RIGHT) {
    mbState_[RIGHT] = false;
  }
}

void InputHandler::onMouseButtonDown(SDL_Event& event) {
  if (event.button.button == SDL_BUTTON_LEFT) {
    mbState_[LEFT] = true;
  } else if (event.button.button == SDL_BUTTON_MIDDLE) {
    mbState_[MIDDLE] = true;
  } else if (event.button.button == SDL_BUTTON_RIGHT) {
    mbState_[RIGHT] = true;
  }
}
