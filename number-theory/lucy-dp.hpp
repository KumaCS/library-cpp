#pragma once

#include "math/util.hpp"
#include "math/prime-sieve.hpp"

template <class T>
pair<vector<long long>, vector<T>> LucyDP(long long n, function<T(ll)> point_value, function<T(ll)> prefix_sum) {
  using ll = long long;
  const ll sq = Math::isqrt(n);

  vector<ll> qs(sq * 2 - (sq * sq == n));
  for (int i = 0; i < sq; i++) qs[i] = i + 1;
  for (int i = 0; i < sq; i++) qs[qs.size() - 1 - i] = n / (i + 1);
  vector<T> s(qs.size());
  auto v1 = point_value(1);
  for (int i = 0; i < qs.size(); i++) s[i] = prefix_sum(qs[i]) - v1;

  auto ps = PrimeSieve(sq);
  for (ll p : ps) {
    auto v = point_value(p);
    for (int i = (int)qs.size() - 1; i >= 0; i--) {
      ll q = qs[i];
      if (p * p > q) break;
      ll x = q / p;
      int j = x <= sq ? x - 1 : (int)s.size() - n / x;
      s[i] -= (s[j] - s[p - 2]) * v;
    }
  }

  return {qs, s};
}

/**
 * @brief Lucy DP
 * @docs docs/number-theory/lucy-dp.md
 */