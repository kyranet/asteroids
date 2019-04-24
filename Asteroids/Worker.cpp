#include "Worker.h"
#include <SDL_thread.h>
#include <iostream>

Worker::Worker() : tasks_(), t_(nullptr), running_(false) {}

Worker::~Worker() { stop(); }

void Worker::start() {
  if (!running_) {
    // This is commented out because SDL2 uses Windows-specific APIs in the
    // middle of 2019, and cygwin cannot use it because _beginthread and
    // _endthread do not exist.
#if defined(__WIN32__) && !defined(__CYGWIN__)
    running_ = true;
    t_ = SDL_CreateThread(start, "Worker", this);
#endif
  }
}

void Worker::stop() {
  if (running_) {
    running_ = false;
    execute([]() {});  // empty task to wake the thread up
    SDL_WaitThread(t_, nullptr);
  }
}

int Worker::start(void* o) {
  static_cast<Worker*>(o)->process();
  return 0;
}

void Worker::process() {
  while (running_ || tasks_.size() > 0) {
    auto task = tasks_.dequeue();
    task();
  }
}

void Worker::execute(std::function<void()> f) { tasks_.enqueue(f); }
