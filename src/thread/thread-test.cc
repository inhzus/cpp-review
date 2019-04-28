//
// Created by suun on 4/28/19.
//

#include "thread.h"

void mutex_blocking() {
  std::mutex mtx;
  bool ready = false;
  std::condition_variable condition;
  std::vector<std::thread> threads;
  threads.reserve(10);
  for (int i = 0; i < 10; i++) {
    threads.emplace_back(
        [&, i] {
          {
            std::unique_lock<std::mutex> lock(mtx);
            condition.wait(lock, [&] {return ready; });
            printf("thread %d unlocked\n", i);
            std::this_thread::sleep_for(std::chrono::seconds(1));
            condition.notify_one();
          }
        }
    );
  }
  {
    std::this_thread::sleep_for(std::chrono::seconds(1));
    ready = true;
    condition.notify_one();
  }
  for (int i = 0; i < 10; i++) {
    threads[i].join();
  }
}
