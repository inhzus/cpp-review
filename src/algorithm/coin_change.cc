//
// Copyright [2019] <Zhi Sun>
//

#include "algorithm.h"

int coin_change(const vector<int> &coins, int n) {
  vector<int> v(n + 1, n + 1);
  v[0] = 0;
  string s;
  s.append(" ");
  // method 1
//  for (int i = 1; i <= n; i++) {
//    for (auto coin : coins) {
//      if (i >= coin) {
//        v[i] = std::min(v[i], 1 + v[i - coin]);
//      }
//    }
//  }
  // method 2
  for (auto coin : coins) {
    for (int i = coin; i <= n; i++) {
      v[i] = std::min(v[i], 1 + v[i - coin]);
    }
  }
  return v[n] == n + 1 ? -1 : v[n];

}