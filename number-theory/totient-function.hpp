#pragma once

#include "math/lpf-table.hpp"

namespace TotientFunction {
vector<int> table(int n) {
  vector<int> tot(n + 1, 1);
  tot[0] = 0;
  auto lpf = LPFTable(n);
  for (int x = 2; x <= n; x++) {
    int p = lpf[x];
    if (x / p % p == 0)
      tot[x] = tot[x / p] * p;
    else
      tot[x] = tot[x / p] * (p - 1);
  }
  return tot;
}
};  // namespace TotientFunction