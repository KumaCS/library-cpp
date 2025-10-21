#pragma once
#include "fps/formal-power-series.hpp"

// sum_{i=0}^{n-1}r^i*poly(i)
// f[i]=poly(i)
template <class mint>
mint SumOfExpPoly(long long n, mint r, vector<mint>& f) {
  int d = f.size();
  mint p = 1;
  vector<mint> g(d + 1, 0);
  for (int i = 0; i < d; i++) {
    g[i + 1] = g[i] + f[i] * p;
    p *= r;
  }

  return s;
}
/**
 * @brief Prefix Sum of Polynomial
 * @docs docs/fps/prefix-sum-of-polynomial.md
 */