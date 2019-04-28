#include <iostream>
#include <algorithm.h>

vector<int> get_next(const string &pattern) {
  vector<int> next(pattern.size(), 0);
  next[0] = -1;
  int i = 0, j = -1;
  while (i < pattern.size() - 1) {
    if (j == -1 || pattern[i] == pattern[j]) {
      i++;
      j++;
      next[i] = j;
    } else {
      j = next[j];
    }
  }
  return next;
}

int kmp_search(const string &v, const string &pattern) {
  int i = 0, j = 0;
  vector<int> next(std::move(get_next(pattern)));
  while (i != v.size() && j != pattern.size()) {
    if (j == -1 || v[i] == pattern[j]) {
      i++;
      j++;
    } else {
      j = next[j];
    }
  }
  if (j == pattern.size()) {
    return i - j;
  } else {
    return -1;
  }
}
