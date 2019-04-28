//
// Copyright [2019] <Zhi Sun>
//

#include "algorithm.h"

int knapsack(const vector<int> &weight, const vector<int> &value, const int &space) {
  vector<vector<int>> v(weight.size(), vector<int>(space + 1, 0));
  for (int i = 1; i < v.size(); i++) {
    for (int j = 0; j <= space; j++) {
      if (weight[i] > j) {
        v[i][j] = v[i - 1][j];
      } else {
        v[i][j] = std::max(v[i - 1][j], value[i] + v[i - 1][j - weight[i]]);
      }
    }
  }
//  for (int j = 0; j <= space; j++) {
//    printf("%2d ", j);
//  }
//  printf("\n");
//  for (int i = 1; i < v.size(); i++) {
//    for (int j = 0; j <= space; j++) {
//      printf("%2d ", v[i][j]);
//    }
//    printf("\n");
//  }
  return v[v.size() - 1][space];
}
