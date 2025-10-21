#pragma once
#include "fps/formal-power-series.hpp"
#include "fps/power-projection.hpp"
#include "modint/factorial.hpp"

// [x^0]f=0,[x^1]f!=0
// find g s.t. f(g(x))=g(f(x))=x mod x^n
// O(n(log n)^2)
template <class mint>
FormalPowerSeries<mint> CompositionalInv(FormalPowerSeries<mint> f, int n = -1) {
  if (n == -1) n = f.size();
  assert(f[0] == 0 && f[1] != 0);
  mint c = f[1], ci = c.inv();
  using fact = Factorial<mint>;
  mint p = 1;
  for (int i = 1; i < f.size(); i++) f[i] *= (p *= ci);
  auto g = PowerProjection(f, f, n, n);
  f.resize(n);
  reverse_copy(g.begin(), g.end(), f.begin());
  for (int i = 1; i < n; i++) f[i] *= n * fact::inv(n - i);
  f = (f.log() * (-fact::inv(n))).exp();
  for (int i = n - 1; i > 0; i--) f[i] = f[i - 1] * ci;
  f[0] = 0;
  return f;
}
/**
 * @brief 逆関数
 * @docs docs/fps/compositional-inv.md
 */