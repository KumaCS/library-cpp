#pragma once
#include "fps/formal-power-series.hpp"

template <class mint>
FormalPowerSeries<mint> ProductOfPolynomials(vector<FormalPowerSeries<mint>> fs) {
  if (fs.empty()) return {1};
  for (auto& f : fs) f.shrink();
  for (auto& f : fs)
    if (f.empty()) return {};
  static constexpr int B = 1 << 6;
  for (int i = 0, j = -1; i < fs.size(); i++) {
    if (fs[i].size() > B) continue;
    if (j == -1 || fs[i].size() + fs[j].size() - 1 > B) {
      j = i;
      continue;
    }
    fs[j] *= fs[i];
    swap(fs[i--], fs.back());
    fs.pop_back();
  }
  if (fs.size() == 1) return fs[0];
  for (auto& f : fs) {
    int sz = B;
    while (sz < f.size()) sz <<= 1;
    f.resize(sz);
    f.ntt();
  }
  for (int sz = B * 2; fs.size() > 1; sz <<= 1) {
    for (int i = 0, j = -1; i < fs.size(); i++) {
      if (fs[i].size() >= sz) continue;
      fs[i].ntt_doubling();
      if (j == -1) {
        j = i;
      } else {
        for (int k = 0; k < sz; k++) fs[j][k] *= fs[i][k];
        swap(fs[i--], fs.back());
        fs.pop_back();
        j = -1;
      }
    }
  }
  fs[0].intt();
  fs[0].shrink();
  return fs[0];
}
/**
 * @brief 多項式の積
 * @docs docs/fps/product-of-polynomials.md
 */