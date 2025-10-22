#pragma once
#include "modint/factorial.hpp"
#include "fps/formal-power-series.hpp"

// g(n)=sum_{i=0}^{n}f(i)
template <class mint>
FormalPowerSeries<mint> PrefixSumOfPolynomial(FormalPowerSeries<mint> f) {
  if (f.empty()) return {};
  using fact = Factorial<mint>;
  mint c = f[0];
  int d = f.size();
  fact::reserve(d);
  for (int i = 0; i < d; i++) f[i] *= fact::fact(i);
  reverse(f.begin(), f.end());
  FormalPowerSeries<mint> g(d);
  for (int i = 0; i < d; i++) g[i] = fact::fact_inv(i + 1) * (i & 1 ? -1 : 1);
  f *= g.inv();
  f.resize(d);
  f.push_back(c);
  reverse(f.begin(), f.end());
  for (int i = 1; i <= d; i++) f[i] *= fact::fact_inv(i);
  return f;
}
/**
 * @brief 多項式の Prefix Sum
 * @docs docs/fps/prefix-sum-of-polynomial.md
 */