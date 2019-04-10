#pragma once
#include <functional>
#include "BlockingQueue.h"
#include "sdl_includes.h"

class Worker final {
 public:
  Worker();
  ~Worker();
  void start();
  void stop();
  void execute(std::function<void()> f);

 private:
  static int start(void* o);
  void process();

  BlockingQueue<std::function<void()>> tasks_;
  SDL_Thread* t_{};
  bool running_;
};
