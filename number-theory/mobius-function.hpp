#pragma once

#include "math/lpf-table.hpp"

namespace MobiusFunction {
vector<int> table(int n) {
  vector<int> mu(n + 1, 1);
  mu[0] = 0;
  auto lpf = LPFTable(n);
  for (int x = 2; x <= n; x++) {
    int p = lpf[x];
    if (x / p % p == 0)
      mu[x] = 0;
    else
      mu[x] = -mu[x / p];
  }
  return mu;
}
};  // namespace MobiusFunction