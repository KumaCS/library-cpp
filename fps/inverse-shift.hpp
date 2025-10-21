#pragma once
#include "fps/formal-power-series.hpp"

// [x^n,...,x^{n+k-1}]1/f(x)
template <class mint>
FormalPowerSeries<mint> InverseShift(FormalPowerSeries<mint> f, long long n, int k = -1) {
  using fps = FormalPowerSeries<mint>;
  assert(f[0] != 0);
  if (k == -1) k = f.size();
  int m = 1;
  while (m < k) m <<= 1;

  int log = __builtin_ctz((unsigned int)m);
  mint w = mint(fps::ntt_root()).pow((mint::get_mod() - 1) >> (log + 1));
  mint wi = w.inv();
  vector<int> rev(m);
  for (int i = 0; i < rev.size(); i++) rev[i] = (rev[i / 2] / 2) | ((i & 1) << (log - 1));
  mint inv2 = mint(2).inv();

  f.resize(m);
  f.ntt();
  auto rec = [&](auto& rec, long long n) -> void {
    if (n < m) {
      f.intt();
      f = f.inv(n + m);
      f >>= n;
      f.ntt();
      return;
    }
    f.ntt_doubling();
    assert(f.size() == 2 * m);
    auto f1 = f;
    for (int i = 0; i < m; i++) swap(f1[i << 1], f1[(i << 1) | 1]);
    for (int i = 0; i < m; i++) f[i] = f[i << 1] * f[(i << 1) | 1];
    f.resize(m);
    rec(rec, (n - m + 1) / 2);
    if (((n - m) & 1) == 0) {
      f.resize(2 * m);
      for (int i = m - 1; i >= 0; i--) {
        f[(i << 1) | 1] = f[i];
        f[i << 1] = f[i];
      }
    } else {
      mint p = 1;
      for (auto i : rev) f[i] *= p, p *= w;
      f.resize(2 * m);
      for (int i = m - 1; i >= 0; i--) {
        f[(i << 1) | 1] = -f[i];
        f[i << 1] = f[i];
      }
    }
    for (int i = 0; i < 2 * m; i++) f[i] *= f1[i];
    auto odd = fps(f.begin() + m, f.end());
    odd.intt();
    mint p = 1;
    for (int i = 0; i < m; i++) odd[i] *= p, p *= wi;
    odd.ntt();
    f.resize(m);
    for (int i = 0; i < m; i++) f[i] = (f[i] - odd[i]) * inv2;
  };
  rec(rec, n);
  f.intt();
  f.resize(k);
  return f;
}
/**
 * @brief Inverse の次数シフト
 * @docs docs/fps/inverse-shift.md
 */