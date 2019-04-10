#pragma once

#include <queue>
#include "sdl_includes.h"

using namespace std;
/*
 *
 */
template <typename T>
class BlockingQueue final {
  queue<T> queue_;
  SDL_cond *cond_;
  SDL_mutex *mutex_;

 public:
  BlockingQueue() : queue_() {
    mutex_ = SDL_CreateMutex();
    cond_ = SDL_CreateCond();
  }

  ~BlockingQueue() {
    SDL_DestroyMutex(mutex_);
    SDL_DestroyCond(cond_);
  }

  T dequeue() {
    SDL_LockMutex(mutex_);
    while (queue_.size() == 0) {
      SDL_CondWait(cond_, mutex_);
    }
    T v = queue_.front();
    queue_.pop();
    SDL_UnlockMutex(mutex_);
    return v;
  }

  void enqueue(T &e) {
    SDL_LockMutex(mutex_);
    if (queue_.size() == 0) {
      SDL_CondSignal(cond_);
    }
    queue_.push(e);
    SDL_UnlockMutex(mutex_);
  }

  int size() { return queue_.size(); }
};
