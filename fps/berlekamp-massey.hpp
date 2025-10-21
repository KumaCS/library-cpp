#pragma once
#include "fps/formal-power-series.hpp"

template <class mint>
FormalPowerSeries<mint> BerlekampMassey(const FormalPowerSeries<mint>& a) {
  int n = a.size();
  FormalPowerSeries<mint> b, c;
  b.reserve(n + 1), c.reserve(n + 1);
  b.push_back(1), c.push_back(1);
  mint y = 1;
  for (int k = 0; k < n; k++) {
    mint x = 0;
    for (int i = 0; i < c.size(); i++) x += c[i] * a[k - i];
    b.insert(b.begin(), 0);
    if (x == 0) continue;
    mint v = x / y;
    if (b.size() > c.size()) {
      for (int i = 0; i < b.size(); i++) b[i] *= -v;
      for (int i = 0; i < c.size(); i++) b[i] += c[i];
      swap(b, c);
      y = x;
    } else {
      for (int i = 0; i < b.size(); i++) c[i] -= v * b[i];
    }
  }
  return c;
}

/**
 * @brief Berlekamp-Massey
 * @docs docs/fps/berlekamp-massey.md
 */