//
// Copyright [2019] <Zhi Sun>
//

#include <iostream>
#include <cassert>
#include "algorithm.h"
#include "sort.h"
#include "search.h"
#include "thread.h"

using std::cout;
using std::endl;

template<class T>
void assert_array(T &a, T &b) {
  assert(a.size() == b.size());
  for (int i = 0; i < a.size(); i++) {
    assert(a[i] == b[i]);
  }
}

void test_sort() {
  {  // merge sort
    vector<int> v = {1, 3, 2, 6, 1, 0, 3, 8, 2, 3};
    vector<int> right = {0, 1, 1, 2, 2, 3, 3, 3, 6, 8};
    merge_sort(v);
    assert_array(v, right);
  }
}

void test_algorithm() {
  {
    int kmp = kmp_search("dgvjdcvvaf", "cvv");
    assert(kmp == 5);
  }
  {
    int kna = knapsack({0, 1, 1, 1, 1, 1}, {0, 5, 8, 6, 4, 5}, 10);
    assert(kna == 28);
    kna = knapsack({0, 8, 7, 6, 4}, {0, 14, 15, 20, 9}, 20);
    assert(kna == 44);
  }
  {
    int num = coin_change({1, 5, 7, 10}, 15);
    assert(num == 2);
  }
  {
    int lcs = findLCS("bdcaba", "abcbdab");
    assert(lcs == 4);
  }
}

void test_search() {
  {
    vector<int> v = {-1, 2, 6, 9, 12, 15};
    int r = binary_search(v, 6);
    assert(r == 2);
    r = binary_search(v, 3);
    assert(r == -1);
  }
}

void test_thread() {
  /*
  {
    mutex_blocking();
  }
  {
    auto f = [] {
      std::this_thread::sleep_for(std::chrono::seconds(1));
      printf("Wake up\n");
    };
    ThreadPool pool(4);
    for (int i = 0; i < 10; i++) {
      pool.enqueue(f);
    }
  }
   */
  {
    Counter counter;
    std::mutex outMutex;
    auto loop = [&] {
      for (int i = 0; i < 3; i++) {
        counter.increase();
        int cnt = counter.get();
        std::unique_lock<std::mutex> lock(outMutex);
        printf("thread %lu: %d\n",
            std::hash<std::thread::id>{}(std::this_thread::get_id()),
            cnt);
      }
    };
    std::thread firstThread(loop), secondThread(loop);
    counter.reset();
    firstThread.join();
    secondThread.join();
  }
}

int main() {
//  test_sort();
//  test_algorithm();
//  test_search();
  test_thread();
  return 0;
}
