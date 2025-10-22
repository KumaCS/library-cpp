#pragma once
#include "fps/formal-power-series.hpp"

template <class mint>
FormalPowerSeries<mint> PolynomialInterpolation(const vector<mint>& x, const vector<mint>& y) {
  using fps = FormalPowerSeries<mint>;
  assert(x.size() == y.size());
  int n = x.size();
  if (n == 0) return {y[0]};
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

/**
 * @brief 多項式補間
 * @docs docs/fps/polynomial-interpolation.md
 */