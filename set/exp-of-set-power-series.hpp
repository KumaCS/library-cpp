#pragma once
#include "set/subset-convolution.hpp"

namespace SetPowerSeries {
template <class mint, int sz = 21>
vector<mint> exp(const vector<mint>& a) {
  static SubsetConvolution<mint, sz> sc;
  assert(a[0] == 0);
  int l = __builtin_ctz(a.size());
  assert(a.size() == (1 << l));

  vector<mint> f(1 << l, 0);
  f[0] = 1;
  for (int k = 0; k < l; k++) {
    vector<mint> g(f.begin(), f.begin() + (1 << k));
    vector<mint> h(a.begin() + (1 << k), a.begin() + (2 << k));
    g = sc.multiply(g, h);
    copy(g.begin(), g.end(), f.begin() + (1 << k));
  }
  return f;
}
};  // namespace SetPowerSeries
/**
 * @brief Exp Of Set Power Series
 */