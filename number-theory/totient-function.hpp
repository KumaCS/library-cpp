#pragma once

#include "number-theory/prime-sieve.hpp"

namespace TotientFunction {
vector<int> table(int n) {
  vector<int> tot(n + 1, 1);
  tot[0] = 0;
  auto lpf = PrimeSieve::lpf(n);
  for (int x = 2; x <= n; x++) {
    int p = lpf[x];
    if (x / p % p == 0)
      tot[x] = tot[x / p] * p;
    else
      tot[x] = tot[x / p] * (p - 1);
  }
  return tot;
}
template <class T>
T sum(long long n) {
  const int lim = 2000000;
  if (n < lim) {
    vector<int> phi(n + 1);
    iota(phi.begin(), phi.end(), 0);
    vector<bool> f(n + 1, false);
    for (int i = 2; i <= n; i += (i & 1) + 1)
      if (!f[i])
        for (int j = i; j <= n; j += i) {
          f[j] = true;
          phi[j] -= phi[j] / i;
        }
    T ans = 0;
    for (auto v : phi) ans += v;
    return ans;
  } else {
    vector<T> sum_small(lim), sum_large(n / lim + 1);
    iota(sum_small.begin(), sum_small.end(), 0);
    vector<bool> f(lim, false);
    for (int i = 2; i < lim; i += (i & 1) + 1)
      if (!f[i])
        for (int j = i; j < lim; j += i) {
          f[j] = true;
          sum_small[j] -= sum_small[j] / i;
        }
    for (int i = 2; i < lim; i++) sum_small[i] += sum_small[i - 1];
    const int sz = sum_large.size();
    for (int k = sz - 1; k > 0; k--) {
      int m = 2;
      long long cur = n / k;
      sum_large[k] = (T)((cur + 1) / 2) * (cur | 1);
      for (; cur / m != cur / (m + 1) && m <= cur; m++)
        sum_large[k] -= k * m >= sz ? sum_small[cur / m] : sum_large[k * m];
      for (int arg = (int)(cur / m); arg >= 1; arg--)
        sum_large[k] -= (T)(cur / arg - cur / (arg + 1)) * (arg < lim ? sum_small[arg] : sum_large[n / arg]);
    }
    return sum_large[1];
  }
}
};  // namespace TotientFunction

/**
 * @brief Totient Function
 * @docs docs/number-theory/totient-function.md
 */
