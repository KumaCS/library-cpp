#pragma once
#include "modint/factorial.hpp"
#include "fps/formal-power-series.hpp"

// f(0),f(1),...,f(n-1) -> f(c),...,f(c+m-1)
template <class mint>
vector<mint> SamplingPointsShift(const vector<mint>& f, mint c, int m) {
  using fps = FormalPowerSeries<mint>;
  using fact = Factorial<mint>;
  int n = f.size();
  fact::reserve(m);
  fps f1(n), ei(n);
  for (int i = 0; i < n; i++) f1[i] = f[i] * fact::fact_inv(i);
  for (int i = 0; i < n; i++) ei[i] = fact::fact_inv(i) * (i % 2 ? -1 : 1);
  f1 *= ei;
  for (int i = n; i < f1.size(); i++) f1[i] = 0;
  for (int i = 0; i < n; i++) f1[i] *= fact::fact(i);
  fps g(n, 1);
  for (int i = 1; i < n; i++) g[i] = g[i - 1] * (c + 1 - i) * fact::inv(i);
  g = g.middle_product(f1);
  for (int i = 0; i < n; i++) g[i] *= fact::fact_inv(i);
  fps e(m);
  for (int i = 0; i < m; i++) e[i] = fact::fact_inv(i);
  g *= e;
  g.resize(m);
  for (int i = 0; i < m; i++) g[i] *= fact::fact(i);
  return g;
}
/**
 * @brief 評価点シフト
 * @docs docs/fps/sampling-points-shift.md
 */