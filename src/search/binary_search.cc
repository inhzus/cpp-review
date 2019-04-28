//
// Copyright [2019] <Zhi Sun>
//

#include "search.h"

int traverse(vector<int> &v, int val, int low, int high) {
  if (low > high) {
    return -1;
  }
  int mid = (low + high) / 2;
  // int mid = low + (high - low) * (val -v[low]) / (v[high] - v[low]);
  if (v[mid] == val) {
    return mid;
  } else if (val < v[mid]) {
    return traverse(v, val, low, mid - 1);
  } else {
    return traverse(v, val, mid + 1, high);
  }
}

int binary_search(vector<int> &v, int val) {
  return traverse(v, val, 0, static_cast<int>(v.size() - 1));
}
