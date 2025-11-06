#pragma once
#include "modint/factorial.hpp"
#include "modint/power-table.hpp"
#include "fps/formal-power-series.hpp"
#include "fps/taylor-shift.hpp"

template <class mint>
FormalPowerSeries<mint> PartitionFunction(int n) {
  FormalPowerSeries<mint> g(n + 1);
  for (int k = 0; k * (3 * k - 1) / 2 <= n; k++) g[k * (3 * k - 1) / 2] += k & 1 ? -1 : 1;
  for (int k = 1; k * (3 * k + 1) / 2 <= n; k++) g[k * (3 * k + 1) / 2] += k & 1 ? -1 : 1;
  return g.inv(n + 1);
}
template <class mint>
FormalPowerSeries<mint> BellNumber(int n) {
  using fact = Factorial<mint>;
  FormalPowerSeries<mint> f(n + 1);
  for (int i = 1; i < f.size(); i++) f[i] = fact::fact_inv(i);
  f = f.exp();
  for (int i = 0; i < f.size(); i++) f[i] *= fact::fact(i);
  return f;
}
template <class mint>
vector<mint> MontmortNumber(int n) {
  vector<mint> f(n + 1);
  f[0] = 1, f[1] = 0;
  for (int i = 2; i < f.size(); i++) f[i] = (i - 1) * (f[i - 1] + f[i - 2]);
  return f;
}
template <class mint>
FormalPowerSeries<mint> FirstKindStirlingNumbers(int n) {
  FormalPowerSeries<mint> f{1};
  for (int l = 30; l >= 0; l--) {
    if (f.size() > 1) f *= TaylorShift(f, mint(-(n >> (l + 1))));
    if ((n >> l) & 1) f = (f << 1) - f * mint((n >> l) - 1);
  }
  return f;
}
template <class mint>
FormalPowerSeries<mint> FirstKindStirlingNumbersFixedK(int n, int k) {
  using fact = Factorial<mint>;
  if (k > n) return FormalPowerSeries<mint>{};
  FormalPowerSeries<mint> f(n - k + 1);
  for (int i = 0; i < f.size(); i++) f[i] = fact::inv(i + 1) * (i & 1 ? -1 : 1);
  f = f.pow(k);
  f *= fact::fact_inv(k);
  for (int i = 0; i < f.size(); i++) f[i] *= fact::fact(i + k);
  return f;
}
template <class mint>
FormalPowerSeries<mint> SecondKindStirlingNumbers(int n) {
  using fact = Factorial<mint>;
  FormalPowerSeries<mint> f(n + 1);
  for (int i = 0; i < f.size(); i++) f[i] = fact::fact_inv(i) * (i & 1 ? -1 : 1);
  FormalPowerSeries<mint> g(PowerTable<mint>(n, n));
  for (int i = 0; i < g.size(); i++) g[i] *= fact::fact_inv(i);
  f *= g;
  f.resize(n + 1);
  return f;
}
template <class mint>
FormalPowerSeries<mint> SecondKindStirlingNumbersFixedK(int n, int k) {
  using fact = Factorial<mint>;
  if (k > n) return FormalPowerSeries<mint>{};
  FormalPowerSeries<mint> f(n - k + 1);
  for (int i = 0; i < f.size(); i++) f[i] = fact::fact_inv(i + 1);
  f = f.pow(k);
  f *= fact::fact_inv(k);
  for (int i = 0; i < f.size(); i++) f[i] *= fact::fact(i + k);
  return f;
}

/**
 * @brief 有名数列
 * @docs docs/fps/famous-sequences.md
 */