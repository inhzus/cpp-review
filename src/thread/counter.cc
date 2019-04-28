//
// Created by suun on 4/28/19.
//

#include "thread.h"

Counter::Counter() : cnt(0) {}

int Counter::get() const {
  std::shared_lock<std::shared_timed_mutex> lock(mutex);
  return cnt;
}

void Counter::increase() {
  std::unique_lock<std::shared_timed_mutex> lock(mutex);
  cnt++;
}

void Counter::reset() {
  std::unique_lock<std::shared_timed_mutex> lock(mutex);
  cnt = 0;
}
