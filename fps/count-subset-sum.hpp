#pragma once
#include "modint/factorial.hpp"
#include "fps/formal-power-series.hpp"

// #{ I | sum[i in I]a[i] = k } for k=0,1,...,n
template <class mint>
FormalPowerSeries<mint> CountSubsetSum(vector<int> a, int n) {
  using fact = Factorial<mint>;
  using fps = FormalPowerSeries<mint>;
  vector<int> c(n + 1, 0);
  for (auto v : a)
    if (0 <= v && v <= n) c[v]++;
  FormalPowerSeries<mint> f(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    if (c[i] == 0) continue;
    mint s = c[i];
    for (int j = 1; i * j <= n; j++) {
      f[i * j] += s * fact::inv(j);
      s = -s;
    }
  }
  return f.exp();
}
/**
 * @brief Count Subset Sum
 * @docs docs/fps/count-subset-sum.md
 */