#pragma once
#include "fps/formal-power-series.hpp"

// [x^n]f(x)/g(x)
template <class mint>
mint BostanMori(FormalPowerSeries<mint> f, FormalPowerSeries<mint> g, long long n) {
  g.shrink();
  mint ret = 0;
  if (f.size() >= g.size()) {
    auto q = f / g;
    if (n < q.size()) ret += q[n];
    f -= q * g;
    f.shrink();
  }
  if (f.empty()) return ret;
  FormalPowerSeries<mint>::set_ntt();
  if (!FormalPowerSeries<mint>::ntt_ptr) {
    f.resize(g.size() - 1);
    for (; n > 0; n >>= 1) {
      auto g1 = g;
      for (int i = 1; i < g1.size(); i += 2) g1[i] = -g1[i];
      auto p = f * g1, q = g * g1;
      if (n & 1) {
        for (int i = 0; i < f.size(); i++) f[i] = p[(i << 1) | 1];
      } else {
        for (int i = 0; i < f.size(); i++) f[i] = p[i << 1];
      }
      for (int i = 0; i < g.size(); i++) g[i] = q[i << 1];
    }
    return ret + f[0] / g[0];
  } else {
    int m = 1, log = 0;
    while (m < g.size()) m <<= 1, log++;
    mint wi = mint(FormalPowerSeries<mint>::ntt_root()).inv().pow((mint::get_mod() - 1) >> (log + 1));
    vector<int> rev(m);
    for (int i = 0; i < rev.size(); i++) rev[i] = (rev[i / 2] / 2) | ((i & 1) << (log - 1));
    vector<mint> pow(m, 1);
    for (int i = 1; i < m; i++) pow[rev[i]] = pow[rev[i - 1]] * wi;
    f.resize(m), g.resize(m);
    f.ntt(), g.ntt();
    mint inv2 = mint(2).inv();
    for (; n >= m; n >>= 1) {
      f.ntt_doubling(), g.ntt_doubling();
      if (n & 1) {
        for (int i = 0; i < m; i++) f[i] = (f[i << 1] * g[(i << 1) | 1] - f[(i << 1) | 1] * g[i << 1]) * inv2 * pow[i];
      } else {
        for (int i = 0; i < m; i++) f[i] = (f[i << 1] * g[(i << 1) | 1] + f[(i << 1) | 1] * g[i << 1]) * inv2;
      }
      for (int i = 0; i < m; i++) g[i] = g[i << 1] * g[(i << 1) | 1];
      f.resize(m), g.resize(m);
    }
    f.intt(), g.intt();
    return ret + (f * g.inv())[n];
  }
}
/**
 * @brief Bostan-Mori
 * @docs docs/fps/bostan-mori.md
 */