//
// Created by suun on 4/27/19.
//

#ifndef REVIEW_THREAD_H
#define REVIEW_THREAD_H
#include <vector>
#include <queue>
#include <memory>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <future>
#include <functional>
#include <stdexcept>

void mutex_blocking();
/*
 *  test on mutex blocking and condition_variable blocking.
 *  There is only one thread which hold the unique_lock, and the other threads are blocked.
 *  Condition_variable wait function without second parameter will be blocked the thread unless notified.
 *  If condition_variable wait function's pred returns false, it will be blocked unless notified.
 *  By now I have not found where to use notify all since unique lock is hold by only one thread at any time.
 */

class ThreadPool {
 public:
  explicit ThreadPool(size_t);
  ~ThreadPool();
// add new work item to the pool
  template<class F, class... Args>
  auto enqueue(F &&f, Args &&... args)
  -> std::future<typename std::result_of<F(Args...)>::type> {
    using return_type = typename std::result_of<F(Args...)>::type;

    auto task = std::make_shared<std::packaged_task<return_type()> >(
        std::bind(std::forward<F>(f), std::forward<Args>(args)...)
    );

    std::future<return_type> res = task->get_future();
    {
      std::unique_lock<std::mutex> lock(queue_mutex);

      // don't allow enqueueing after stopping the pool
      if (stop)
        throw std::runtime_error("enqueue on stopped ThreadPool");

      tasks.emplace([task]() { (*task)(); });
    }
    condition.notify_one();
    return res;
  }
 private:
  // need to keep track of threads so we can join them
  std::vector<std::thread> workers;
  // the task queue
  std::queue<std::function<void()> > tasks;

  // synchronization
  std::mutex queue_mutex;
  std::condition_variable condition;
  bool stop;
};

#endif //REVIEW_THREAD_H
