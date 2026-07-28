#pragma once

#include "math/util.hpp"
#include "number-theory/prime-sieve.hpp"

namespace RangeSieve {
using ll = long long;

namespace internal {
const vector<int>& primes(int limit) {
  static int n = 1;
  static vector<int> ps;
  if (n < limit) {
    while (n < limit) n *= 2;
    ps = PrimeSieve::table(n);
  }
  return ps;
}
};  // namespace internal

// lpf of [l,r]
vector<ll> lpf(ll l, ll r) {
  assert(1 <= l && l <= r);
  int limit = Math::isqrt(r);
  vector<ll> ret(r - l + 1);
  for (size_t i = 0; i < ret.size(); i++) ret[i] = l + (ll)i;
  for (ll p : internal::primes(limit)) {
    if (p > limit) break;
    for (ll x = Math::ceil(l, p) * p; x <= r; x += p)
      if (ret[x - l] > p) ret[x - l] = p;
  }
  return ret;
}

vector<ll> table(ll l, ll r) {
  assert(1 <= l && l <= r);
  int limit = Math::isqrt(r);
  vector<bool> composite(r - l + 1, false);
  for (ll p : internal::primes(limit)) {
    if (p > limit) break;
    for (ll x = max(Math::ceil(l, p), p) * p; x <= r; x += p)
      composite[x - l] = true;
  }
  vector<ll> ps;
  for (size_t i = 0; i < composite.size(); i++) {
    ll x = l + (ll)i;
    if (x >= 2 && !composite[i]) ps.push_back(x);
  }
  return ps;
}

vector<vector<pair<ll, int>>> factorize(ll l, ll r) {
  assert(1 <= l && l <= r);
  int limit = Math::isqrt(r);
  vector<vector<pair<ll, int>>> factors(r - l + 1);
  vector<ll> rem(r - l + 1);
  for (size_t i = 0; i < rem.size(); i++) rem[i] = l + (ll)i;
  for (ll p : internal::primes(limit)) {
    if (p > limit) break;
    for (ll x = Math::ceil(l, p) * p; x <= r; x += p) {
      int e = 0;
      while (rem[x - l] % p == 0) rem[x - l] /= p, e++;
      factors[x - l].emplace_back(p, e);
    }
  }
  for (size_t i = 0; i < rem.size(); i++)
    if (rem[i] > 1) factors[i].emplace_back(rem[i], 1);
  return factors;
}
};  // namespace RangeSieve

/**
 * @brief 区間篩
 * @docs docs/number-theory/range-sieve.md
 */
