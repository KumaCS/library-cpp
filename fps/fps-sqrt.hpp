#pragma once

#include "../modint/mod-sqrt.hpp"
#include "./formal-power-series.hpp"

template <typename mint>
FormalPowerSeries<mint> FpsSqrt(const FormalPowerSeries<mint> &f, int deg = -1) {
  if (deg == -1) deg = (int)f.size();
  if ((int)f.size() == 0) return FormalPowerSeries<mint>(deg, 0);
  if (f[0] == mint(0)) {
    for (int i = 1; i < (int)f.size(); i++) {
      if (f[i] != mint(0)) {
        if (i & 1) return {};
        if (deg - i / 2 <= 0) break;
        auto ret = FpsSqrt(f >> i, deg - i / 2);
        if (ret.empty()) return {};
        ret = ret << (i / 2);
        if ((int)ret.size() < deg) ret.resize(deg, mint(0));
        return ret;
      }
    }
    return FormalPowerSeries<mint>(deg, 0);
  }
  int64_t sqr = ModSqrt(f[0].get(), mint::get_mod());
  if (sqr == -1) return {};
  assert(sqr * sqr % mint::get_mod() == f[0].get());
  FormalPowerSeries<mint> ret = {mint(sqr)};
  mint inv2 = mint(2).inv();
  for (int i = 1; i < deg; i <<= 1) {
    ret = (ret + f.pre(i << 1) * ret.inv(i << 1)) * inv2;
  }
  return ret.pre(deg);
}
