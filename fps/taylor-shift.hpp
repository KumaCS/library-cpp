#pragma once

#include "../modint/factorial.hpp"
#include "./formal-power-series.hpp"

// f(x+a)
template <class mint>
FormalPowerSeries<mint> TaylorShift(FormalPowerSeries<mint> f, mint a, Factorial<mint>& fact) {
  using fps = FormalPowerSeries<mint>;
  int n = f.size();
  for (int i = 0; i < n; i++) f[i] *= fact.fact(i);
  reverse(f.begin(), f.end());
  fps g(n, mint(1));
  for (int i = 1; i < n; i++) g[i] = g[i - 1] * a * fact.inv(i);
  f = (f * g).pre(n);
  reverse(f.begin(), f.end());
  for (int i = 0; i < n; i++) f[i] *= fact.fact_inv(i);
  return f;
}