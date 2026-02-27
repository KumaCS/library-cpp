#pragma once

#include "math/util.hpp"
#include "math/prime-sieve.hpp"

template <class T>
T SumOfMultiplicativeFunction(long long n, T e, vector<T> prime_sum, function<T(ll, int, ll)> prime_power_value) {
  using ll = long long;
  ll sq = Math::isqrt(n);
  auto ps = PrimeSieve(sq);
  auto dfs = [&](auto dfs, ll x, T f, int p_idx, int r, ll q) -> T {
    ll m = n / x;
    T ret{};
    ll p = ps[p_idx];
    ret += f * prime_power_value(p, r + 1, q * p);
    if (p * p <= m) ret += dfs(dfs, x * p, f, p_idx, r + 1, q * p);
    f *= prime_power_value(p, r, q);
    ret += f * (prime_sum[m <= sq ? m - 1 : prime_sum.size() - x] - prime_sum[p - 1]);
    for (int j = p_idx + 1; j < (int)ps.size(); j++) {
      ll p1 = ps[j];
      if (p1 * p1 > m) break;
      ret += dfs(dfs, x * p1, f, j, 1, p1);
    }
    return ret;
  };

  T ret = prime_sum.back() + e;
  for (int i = 0; i < (int)ps.size(); i++) {
    int p = ps[i];
    ret += dfs(dfs, p, e, i, 1, p);
  }
  return ret;
}
