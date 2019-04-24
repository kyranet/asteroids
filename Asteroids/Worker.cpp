#include "Worker.h"

#include <SDL_thread.h>
#include <iostream>

Worker::Worker() : tasks_(), t_(nullptr), running_(false) {}

Worker::~Worker() { stop(); }

void Worker::start() {
  if (!running_) {
    running_ = true;
    // t_ = SDL_CreateThread(start, "Worker", this);
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
