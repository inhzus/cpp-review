//
// Copyright [2019] <Zhi Sun>
//
#include "sort.h"


void recursive(vector<int> &v, int low, int high) {
  if (low >= high) {
    return;
  }
//  int mid = v[high];
//  int l = low, r = high - 1;
//  while (l < r) {
//    while (v[l] < mid && l < r) {
//      l++;
//    }
//    while (v[r] >= mid && l < r) {
//      r--;
//    }
//    std::swap(v[l], v[r]);
//  }
//  if (v[l] >= v[high]) {
//    std::swap(v[l], v[high]);
//  } else {
//    l++;
//  }
  int value = v[low], l = low, r = high;
  while (l < r) {
    while (v[l] < value && l < r) {
      l++;
    }
    while (v[r] >= value && l < r) {
      r++;
    }
    std::swap(v[l], v[r]);
  }
  std::swap(v[low], v[l]);

  recursive(v, low, l - 1);
  recursive(v, l + 1, high);
}


void quick_sort(vector<int> &v) {
  recursive(v, 0, v.size() - 1);
}
