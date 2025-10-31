#pragma once
#include "fps/formal-power-series.hpp"
#include "fps/multipoint-evaluation.hpp"
#include "modint/multi-inverse.hpp"

// f(x[i])=y[i]
template <class mint>
FormalPowerSeries<mint> PolynomialInterpolation(const vector<mint>& x, const vector<mint>& y) {
  using fps = FormalPowerSeries<mint>;
  assert(x.size() == y.size());
  int n = x.size();
  if (n == 0) return {};
  vector<fps> prod(2 * n);
  for (int i = 0; i < n; i++) prod[i + n] = {-x[i], 1};
  for (int i = n - 1; i > 0; i--) prod[i] = prod[i * 2] * prod[i * 2 + 1];
  vector<fps> fs(2 * n);
  fs[1] = prod[1].diff();
  for (int i = 2; i < 2 * n; i++) fs[i] = fs[i / 2] % prod[i];
  for (int i = n; i < n * 2; i++) fs[i] = {y[i - n] / fs[i][0]};
  for (int i = n - 1; i > 0; i--) fs[i] = fs[(i << 1) | 0] * prod[(i << 1) | 1] + fs[(i << 1) | 1] * prod[(i << 1) | 0];
  return fs[1];
}

// f(ar^i)=y[i]
template <class mint>
FormalPowerSeries<mint> PolynomialInterpolationGeometric(mint a, mint r, const vector<mint>& y) {
  using fps = FormalPowerSeries<mint>;
  int n = y.size();
  if (n == 0) return {};
  if (n == 1) return {y[0]};
  assert(a != 0);
  assert(r != 1);
  vector<mint> rs(n + 1, 1);
  for (int i = 1; i <= n; i++) rs[i] = rs[i - 1] * r;
  vector<mint> rs1(n - 1);
  for (int i = 0; i < n - 1; i++) rs1[i] = 1 - rs[i + 1];
  rs1 = MultiInverse(rs1);
  fps f(n, 1);
  for (int i = 1; i < n; i++) f[i] = f[i - 1] * a * (rs[n] - rs[i - 1]) * rs1[i - 1];

  fps g(n, 1);
  {
    vector<mint> s(n, 1);
    for (int i = 1; i < n; i++) s[i] = s[i - 1] * a * (1 - rs[i]);
    for (int i = 1; i < n; i++) g[i] = -g[i - 1] * rs[n - 1 - i];
    for (int i = 0; i < n; i++) g[i] *= s[i] * s[n - 1 - i];
    g = MultiInverse(g);
  }
  for (int i = 0; i < n; i++) g[i] *= y[i];
  g = MultipointEvaluationGeometric(g, mint(1), r, n);
  mint c = 1;
  for (int i = 1; i < n; i++) g[i] *= (c *= a);
  f *= g;
  f.resize(n);
  reverse(f.begin(), f.end());
  return f;
}

/**
 * @brief 多項式補間
 * @docs docs/fps/polynomial-interpolation.md
 */