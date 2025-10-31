#pragma once
#include "set/subset-convolution.hpp"

namespace SetPowerSeries {
template <class mint, int sz = 21>
vector<mint> power_projection(const vector<mint>& a, const vector<mint>& w, int m) {
  static SubsetConvolution<mint, sz> sc;
  int l = __builtin_ctz(a.size());
  assert(a.size() == (1 << l));
  mint c = a[0];
  vector<vector<mint>> g(l + 1);
  g[0] = w;
  for (int i = 1; i <= l; i++) g[i] = vector<mint>(1 << (l - i), 0);
  for (int k = l - 1; k >= 0; k--) {
    auto p = sc.lift(vector<mint>(a.begin() + (1 << k), a.begin() + (2 << k)));
    sc.ranked_zeta(p);
    for (int i = 0; i < l - k; i++) {
      auto h = vector<mint>(g[i].begin() + (1 << k), g[i].begin() + (2 << k));
      reverse(h.begin(), h.end());
      auto q = sc.lift(h);
      sc.ranked_zeta(q);
      sc.ranked_mul(q, p);
      sc.ranked_mobius(q);
      h = sc.unlift(q);
      reverse(h.begin(), h.end());
      for (int j = 0; j < h.size(); j++) g[i + 1][j] += h[j];
    }
  }
  vector<mint> f1(l + 1, 1);
  for (int i = 1; i <= l; i++) f1[i] = f1[i - 1] * i;
  for (int i = 0; i <= l; i++) f1[i] *= g[i][0];
  vector<mint> f(m, 0), binom(l + 1, 0);
  binom[0] = 1;
  mint r0 = 1;
  for (int i = 0; i < m; i++) {
    if (i > l) r0 *= c;
    mint r = r0;
    for (int j = min(i, l); j >= 0; j--, r *= c) f[i] += f1[j] * binom[j] * r;
    for (int j = l; j > 0; j--) binom[j] += binom[j - 1];
  }
  return f;
}
};  // namespace SetPowerSeries
/**
 * @brief Power Projection Of Set Power Series
 * @docs docs/set/power-projection-of-set-power-series.md
 */