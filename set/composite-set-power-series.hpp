#pragma once
#include "set/subset-convolution.hpp"

namespace SetPowerSeries {
template <class mint, int sz = 21>
vector<mint> composite_egf(vector<mint> f, vector<mint> a) {
  static SubsetConvolution<mint, sz> sc;
  assert(a[0] == 0);
  if (f.empty()) return vector<mint>(a.size());
  int l = __builtin_ctz(a.size());
  f.resize(l + 1);
  vector<vector<mint>> g(l + 1);
  for (int i = 0; i <= l; i++) g[i] = vector<mint>(1 << (l - i), 0);
  for (int i = 0; i <= l; i++) g[i][0] = f[i];
  for (int k = 0; k < l; k++) {
    auto p = sc.lift(vector<mint>(a.begin() + (1 << k), a.begin() + (2 << k)));
    sc.ranked_zeta(p);
    for (int i = 0; i < l - k; i++) {
      auto q = sc.lift(vector<mint>(g[i + 1].begin(), g[i + 1].begin() + (1 << k)));
      sc.ranked_zeta(q);
      sc.ranked_mul(q, p);
      sc.ranked_mobius(q);
      auto h = sc.unlift(q);
      copy(h.begin(), h.end(), g[i].begin() + (1 << k));
    }
  }
  return g[0];
}
template <class mint, int sz = 21>
vector<mint> composite_polynomial(vector<mint> p, vector<mint> a) {
  if (p.empty()) return vector<mint>(a.size());
  int l = __builtin_ctz(a.size());
  if (a[0] != 0) {
    mint c = a[0];
    a[0] = 0;
    vector<mint> p1(l + 1, 0), binom(l + 1, 0);
    binom[0] = 1;
    mint r0 = 1;
    for (int i = 0; i < p.size(); i++) {
      if (i > l) r0 *= c;
      mint r = r0;
      for (int j = min(i, l); j >= 0; j--, r *= c) p1[j] += p[i] * binom[j] * r;
      for (int j = l; j > 0; j--) binom[j] += binom[j - 1];
    }
    swap(p, p1);
  }
  mint r = 1;
  for (int i = 1; i <= l; i++) p[i] *= (r *= i);
  return composite_egf<mint, sz>(p, a);
}

// log(a), [x^0]a=1
// require inverse of 1,...,sz
template <class mint, int sz = 21>
vector<mint> log(vector<mint> a) {
  static SubsetConvolution<mint, sz> sc;
  assert(a[0] == 1);
  int l = __builtin_ctz(a.size());
  if (l == 0) return {0};
  vector<mint> inv(l + 1, 1);
  rep(i, 1, l + 1) inv[i] = mint(i).inv();
  auto p = sc.lift(a);
  sc.ranked_zeta(p);
  for (int k = 0; k < p.size(); k++) {
    auto q = p[k];
    p[k][0] = 0;
    for (int i = 1; i <= l; i++) {
      mint v = i * q[i];
      for (int j = 1; j < i; j++) v -= j * p[k][j] * q[i - j];
      p[k][i] = v * inv[i];
    }
  }
  sc.ranked_mobius(p);
  return sc.unlift(p);
}
// log(a), [x^0]a=1
// not require inverse of 1,...,sz
template <class mint, int sz = 21>
vector<mint> log_arbitrary(vector<mint> a) {
  assert(a[0] == 1);
  int l = __builtin_ctz(a.size());
  if (l == 0) return {0};
  a[0] = 0;
  vector<mint> f(l + 1, 0);
  f[1] = 1;
  for (int i = 2; i <= l; i++) f[i] = f[i - 1] * (1 - i);
  return composite_egf<mint, sz>(f, a);
}
// a^m, [x^0]a=1
// require inverse of 1,...,sz
template <class mint, int sz = 21>
vector<mint> pow(vector<mint> a, mint m) {
  static SubsetConvolution<mint, sz> sc;
  assert(a[0] == 1);
  int l = __builtin_ctz(a.size());
  if (l == 0) return {1};
  vector<mint> inv(l + 1, 1);
  rep(i, 1, l + 1) inv[i] = mint(i).inv();
  auto p = sc.lift(a);
  sc.ranked_zeta(p);
  for (int k = 0; k < p.size(); k++) {
    auto q = p[k];
    p[k][0] = 1;
    for (int i = 1; i <= l; i++) {
      mint v = 0;
      for (int j = 1; j < i; j++) v += (m * j - (i - j)) * p[k][i - j] * q[j];
      v *= inv[i];
      v += m * p[k][0] * q[i];
      p[k][i] = v;
    }
  }
  sc.ranked_mobius(p);
  return sc.unlift(p);
}
// a^m, [x^0]a=1
// not require inverse of 1,...,sz
template <class mint, int sz = 21>
vector<mint> pow_arbitrary(vector<mint> a, mint m) {
  assert(a[0] == 1);
  int l = __builtin_ctz(a.size());
  if (l == 0) return {1};
  a[0] = 0;
  vector<mint> f(l + 1, 0);
  f[0] = 1;
  for (int i = 1; i <= l; i++) {
    f[i] = f[i - 1] * m;
    m -= 1;
  }
  return composite_egf<mint, sz>(f, a);
}
};  // namespace SetPowerSeries
/**
 * @brief Polynomial Composite Set Power Series
 * @docs docs/set/composite-set-power-series.md
 */