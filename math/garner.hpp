#pragma once
#include "math/util.hpp"

template <class T>
T Garner(const vector<T>& r, const vector<T>& m) {
  int n = r.size();
  if (n == 0) return 0;
  T p = 1, x = 0;
  for (int i = 0; i < n; i++) {
    T t = (r[i] - x % m[i] + m[i]) * Math::inv_mod(p, m[i]) % m[i];
    x += t * p;
    p *= m[i];
  }
  return x;
}
template <class T>
T Garner(const vector<T>& r, const vector<T>& m, T mod) {
  int n = r.size();
  if (n == 0) return 0;
  vector<T> y(n);
  for (int i = 0; i < n; i++) {
    T x = 0, p = 1;
    for (int j = 0; j < i; j++) {
      x = (x + y[j] * p) % m[i];
      p = p * m[j] % m[i];
    }
    y[i] = (r[i] - x + m[i]) * Math::inv_mod(p, m[i]) % m[i];
  }
  T res = 0;
  for (int i = n - 1; i >= 0; i--) res = (res * m[i] + y[i]) % mod;
  return res;
}

/**
 * @brief Garner のアルゴリズム
 * @docs docs/math/garner.md
 */