//
// Copyright [2019] <Zhi Sun>
//

#include "sort.h"


void heapify(vector<int> &v, int start, int end) {
  int parent = start, child = parent * 2 + 1;
  while (child <= end) {
    if (child < end && v[child] < v[child + 1]) {
      child++;
    }
    if (v[parent] > v[child]) {
      return;
    } else {
      std::swap(v[parent], v[child]);
      parent = child;
      child = 2 * child + 1;
    }
  }
}

void heap_sort(vector<int> &v) {
  for (int i = v.size() / 2 - 1; i >= 0; i--) {
    heapify(v, i, v.size() - 1);
  }
  for (int i = v.size() - 1; i > 0; i--) {
    std::swap(v[i], v[0]);
    heapify(v, 0, i - 1);
  }
}
