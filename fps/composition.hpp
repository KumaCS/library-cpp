#pragma once
#include "fps/formal-power-series.hpp"
#include "fps/taylor-shift.hpp"

template <class mint>
FormalPowerSeries<mint> Composition(FormalPowerSeries<mint> f, FormalPowerSeries<mint> g, int n = -1) {
  if (n == -1) n = f.size();
  assert(n >= 0);
  if (n == 0 || f.size() == 0) return FormalPowerSeries<mint>(n);

  f = TaylorShift(f, g[0]);
  int k = 1;
  while (k < f.size()) k <<= 1;
  int l = 1, m = 2 * k * l;
  int log = __builtin_ctz((unsigned int)m);

  mint wi = mint(FormalPowerSeries<mint>::ntt_root()).inv().pow((mint::get_mod() - 1) >> (log + 1));
  vector<int> rev(m);
  for (int i = 0; i < rev.size(); i++) rev[i] = (rev[i / 2] / 2) | ((i & 1) << (log - 1));
  vector<mint> pow(m, 1);
  for (int i = 1; i < m; i++) pow[rev[i]] = pow[rev[i - 1]] * wi;

  mint inv2 = mint(2).inv();
  FormalPowerSeries<mint> P(m), Q(m);
  for (int i = 1; i < g.size() && i < k; i++) Q[i] = -g[i];
  auto rec = [&](auto rec, int k, int l, FormalPowerSeries<mint> Q) {
    if (k <= 1) {
      for (int i = 0; i < l && i < f.size(); i++) P[(l - 1 - i) * 2] = f[i];
      return;
    }
    Q.resize(2 * m), Q.ntt();
    FormalPowerSeries<mint> Q1(m);
    for (int i = 0; i < m; i++) {
      mint b = (i >> (log - 1)) == 0 ? 1 : -1;
      int j = i << 1;
      Q1[i] = Q[j] * Q[j ^ 1] + (Q[j] + Q[j ^ 1]) * b;
    }
    Q1.intt();
    k >>= 1, l <<= 1;
    for (int i = k; i < k * 2; i++)
      for (int j = 0; j < l; j++)
        Q1[i + j * k * 2] = 0;
    rec(rec, k, l, Q1);
    for (int i = k; i < k * 2; i++)
      for (int j = 0; j < l; j++)
        P[i + j * k * 2] = 0;
    P.resize(m);
    reverse(P.begin() + 1, P.end());
    P.ntt(), P.resize(2 * m);
    for (int i = m - 1; i >= 0; i--) {
      mint b = (i >> (log - 1)) == 0 ? 1 : -1;
      P[2 * i + 1] = -(Q[2 * i] + b) * pow[i] * P[i];
      P[2 * i] = (Q[2 * i + 1] + b) * pow[i] * P[i];
    }
    P.intt();
    reverse(P.begin() + 1, P.end());
  };
  rec(rec, k, l, Q);

  P.resize(k);
  P = P.rev();
  P.resize(n);
  return P;
}
/**
 * @brief FPS 合成
 * @docs docs/fps/composition.md
 */