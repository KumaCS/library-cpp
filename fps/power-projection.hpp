#pragma once
#include "fps/formal-power-series.hpp"
#include "modint/factorial.hpp"

// transpose of composition
// [x^0]f(x^{-1})g(x)^i, i=0,...,n-1
// O(n(log n)^2)
template <class mint>
FormalPowerSeries<mint> TransposedComposition(FormalPowerSeries<mint> f, FormalPowerSeries<mint> g, int n) {
  if (g[0] != 0) {
    mint c = g[0];
    g[0] = 0;
    auto h1 = TransposedComposition(f, g, n);
    using fact = Factorial<mint>;
    for (int i = 0; i < n; i++) h1[i] *= fact::fact_inv(i);
    FormalPowerSeries<mint> h2(n);
    h2[0] = 1;
    for (int i = 1; i < n; i++) h2[i] = h2[i - 1] * c;
    for (int i = 0; i < n; i++) h2[i] *= fact::fact_inv(i);
    h1 *= h2;
    h1.resize(n);
    for (int i = 0; i < n; i++) h1[i] *= fact::fact(i);
    return h1;
  }

  int k = 1;
  while (k < f.size() || k < n) k <<= 1;
  int l = 1, m = 2 * k * l;
  FormalPowerSeries<mint> P(m), Q(m);
  for (int i = 0; i < f.size(); i++) P[k - 1 - i] = f[i];
  for (int i = 0; i < g.size() && i < k; i++) Q[i] = -g[i];
  int log = __builtin_ctz((unsigned int)m);
  mint wi = mint(FormalPowerSeries<mint>::ntt_root()).inv().pow((mint::get_mod() - 1) >> (log + 1));
  vector<int> rev(m);
  for (int i = 0; i < rev.size(); i++) rev[i] = (rev[i / 2] / 2) | ((i & 1) << (log - 1));
  vector<mint> pow(m, 1);
  for (int i = 1; i < m; i++) pow[rev[i]] = pow[rev[i - 1]] * wi;
  mint inv2 = mint(2).inv();
  
  while (k > 1) {
    P.resize(2 * m), P.ntt();
    Q.resize(2 * m), Q.ntt();
    for (int i = 0; i < m; i++) {
      mint b = (i >> (log - 1)) == 0 ? 1 : -1;
      int j = i << 1;
      P[i] = pow[i] * (P[j] * (Q[j ^ 1] + b) - P[j ^ 1] * (Q[j] + b)) * inv2;
      Q[i] = Q[j] * Q[j ^ 1] + (Q[j] + Q[j ^ 1]) * b;
    }
    P.resize(m), P.intt();
    Q.resize(m), Q.intt();
    k >>= 1, l <<= 1;
    for (int i = k; i < k * 2; i++)
      for (int j = 0; j < l; j++) {
        P[i + j * k * 2] = 0;
        Q[i + j * k * 2] = 0;
      }
  }
  FormalPowerSeries<mint> P1(n);
  for (int i = 0; i < n; i++) P1[i] = P[(l - 1 - i) * 2];
  return P1;
}

// [x^k]f(x)g(x)^0,...,f(x)g(x)^(n-1)
// O((n+k)log^2(n+k))
template <class mint>
vector<mint> PowerProjection(FormalPowerSeries<mint> f, FormalPowerSeries<mint> g, int k, int n) {
  assert(n >= 0 && k >= 0);
  if (n == 0) return {};
  f.resize(k + 1);
  f = f.rev();
  return TransposedComposition(f, g, n);
}
/**
 * @brief Power Projection
 * @docs docs/fps/power-projection.md
 */