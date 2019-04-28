//
// Copyright [2019] <Zhi Sun>
//


#include "sort.h"

void merge_sort(vector<int> &v) {
  vector<int> dest(v.size(), 0);
  for (int seg = 1; seg < v.size(); seg <<= 1) {
    for (vector<int>::size_type p = 0; p < v.size(); p += 2 * seg) {
      auto ll = p, lh = std::min(v.size(), p + seg), rl = lh, rh = std::min(v.size(), rl + seg), i = p;
      while (ll < lh && rl < rh) {
        dest[i++] = v[ll] < v[rl] ? v[ll++] : v[rl++];
      }
      while (ll < lh) {
        dest[i++] = v[ll++];
      }
      while (rl < rh) {
        dest[i++] = v[rl++];
      }
    }
    std::swap(dest, v);
  }
}
