#pragma once
#include "modint/factorial.hpp"
#include "modint/mod-sqrt.hpp"
#include "fps/formal-power-series.hpp"

namespace FPSSparse {
template <class mint>
FormalPowerSeries<mint> inv(map<int, mint> f, int n) {
  assert(f[0] != 0);
  if (n == 0) return {};
  mint c = f[0].inv();
  FormalPowerSeries<mint> g(n);
  g[0] = c;
  for (int i = 1; i < n; i++) {
    for (auto [j, v] : f)
      if (j <= i) g[i] -= v * g[i - j];
    g[i] *= c;
  }
  return g;
}
template <class mint>
FormalPowerSeries<mint> exp(map<int, mint> f, int n) {
  assert(f[0] == 0);
  if (n == 0) return {};
  FormalPowerSeries<mint> g(n);
  g[0] = 1;
  for (int i = 1; i < n; i++) {
    for (auto [j, v] : f)
      if (j <= i) g[i] += j * v * g[i - j];
    g[i] *= Factorial<mint>::inv(i);
  }
  return g;
}
template <class mint>
FormalPowerSeries<mint> log(map<int, mint> f, int n) {
  assert(f[0] == 1);
  if (n == 0) return {};
  FormalPowerSeries<mint> g(n);
  g[0] = 0;
  for (auto [j, v] : f)
    if (0 < j && j < n) g[j - 1] = v * j;
  for (int i = 1; i < n; i++) {
    for (auto [j, v] : f)
      if (0 < j && j <= i) g[i] -= v * g[i - j];
  }
  for (int i = n - 1; i > 0; i--) g[i] = g[i - 1] * Factorial<mint>::inv(i);
  g[0] = 0;
  return g;
}
template <class mint>
FormalPowerSeries<mint> pow(map<int, mint> f, long long m, int n) {
  if (n == 0) return {};
  FormalPowerSeries<mint> g(n, 0);
  if (m == 0) {
    g[0] = 1;
    return g;
  }
  if (f[0] == 0) {
    if (m >= n) return g;
    int s = 1;
    while (s < n && f[s] == 0) s++;
    if (s * m >= n) return g;
    map<int, mint> f1;
    for (auto [i, v] : f) f1[i - s] = v;
    auto g1 = pow(f1, m, int(n - s * m));
    copy(g1.begin(), g1.end(), g.begin() + int(s * m));
    return g;
  }
  g[0] = f[0].pow(m);
  mint c = f[0].inv();
  for (int i = 1; i < n; i++) {
    for (auto [j, v] : f) {
      if (0 < j && j <= i) g[i] += j * f[j] * g[i - j] * m;
      if (0 < j && j < i) g[i] -= f[j] * (i - j) * g[i - j];
    }
    g[i] *= c * Factorial<mint>::inv(i);
  }
  return g;
}
template <class mint>
FormalPowerSeries<mint> sqrt(map<int, mint> f, int n) {
  if (n == 0) return {};
  if (f.empty()) return FormalPowerSeries<mint>(n, 0);
  FormalPowerSeries<mint> g(n, 0);
  if (f[0] == 0) {
    int s = 1;
    while (s < n * 2 && f[s] == 0) s++;
    if (s & 1) return {};
    s /= 2;
    if (s >= n) return g;
    map<int, mint> f1;
    for (auto [i, v] : f) f1[i - s * 2] = v;
    auto g1 = sqrt(f1, int(n - s));
    if (g1.empty()) return {};
    copy(g1.begin(), g1.end(), g.begin() + s);
    return g;
  }
  long long sq = ModSqrt(f[0].val(), mint::get_mod());
  if (sq < 0) return {};
  g[0] = sq;
  mint c = f[0].inv(), inv2 = mint(2).inv();
  for (int i = 1; i < n; i++) {
    for (auto [j, v] : f) {
      if (0 < j && j <= i) g[i] += j * f[j] * g[i - j] * inv2;
      if (0 < j && j < i) g[i] -= f[j] * (i - j) * g[i - j];
    }
    g[i] *= c * Factorial<mint>::inv(i);
  }
  return g;
}
};  // namespace FPSSparse

/**
 * @brief Sparse な FPS 演算
 * @docs docs/fps/sparse.md
 */