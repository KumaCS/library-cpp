#pragma once
#include "math/lpf-table.hpp"

// 0^k,1^k,2^k,...,n^k
template <class T>
vector<T> PowerTable(int n, int k) {
  assert(k >= 0);
  vector<T> f;
  if (k == 0) {
    f = vector<T>(n + 1, 0);
    f[0] = 1;
  } else {
    f = vector<T>(n + 1, 1);
    f[0] = 0;
    auto lpf = LPFTable(n);
    for (int i = 2; i <= n; i++)
      f[i] = lpf[i] == i ? T(i).pow(k) : f[i / lpf[i]] * f[lpf[i]];
  }
  return f;
}
/**
 * @brief Power Table
 */