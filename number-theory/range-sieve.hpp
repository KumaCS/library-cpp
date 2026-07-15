#pragma once

#include "math/util.hpp"
#include "number-theory/prime-sieve.hpp"

namespace RangeSieve {
using ll = long long;

namespace internal {
int prime_limit(ll r) {
  ll sq = Math::isqrt(r);
  assert(sq <= numeric_limits<int>::max());
  return (int)sq;
}

template <class F>
void for_multiples(ll l, ll r, ll p, F f) {
  assert(1 <= l && l <= r && p > 0);
  ll x = l;
  if (ll rem = l % p) {
    ll d = p - rem;
    if (r - l < d) return;
    x += d;
  }
  while (true) {
    f(x);
    if (r - x < p) break;
    x += p;
  }
}
};  // namespace internal

// lpf of [l,r]
vector<ll> lpf(ll l, ll r) {
  assert(1 <= l && l <= r);
  auto ps = PrimeSieve::table(internal::prime_limit(r));
  vector<ll> ret((size_t)(r - l) + 1);
  for (size_t i = 0; i < ret.size(); i++) ret[i] = l + (ll)i;
  for (ll p : ps) {
    internal::for_multiples(l, r, p, [&](ll k) {
      if (ret[k - l] > p) ret[k - l] = p;
    });
  }
  return ret;
}

vector<ll> table(ll l, ll r) {
  assert(1 <= l && l <= r);
  vector<bool> composite((size_t)(r - l) + 1);
  for (ll p : PrimeSieve::table(internal::prime_limit(r))) {
    internal::for_multiples(max(l, p * p), r, p, [&](ll x) {
      composite[x - l] = true;
    });
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
  vector<vector<pair<ll, int>>> factors((size_t)(r - l) + 1);
  vector<ll> rem((size_t)(r - l) + 1);
  for (size_t i = 0; i < rem.size(); i++) rem[i] = l + (ll)i;
  for (ll p : PrimeSieve::table(internal::prime_limit(r))) {
    internal::for_multiples(l, r, p, [&](ll x) {
      int e = 0;
      while (rem[x - l] % p == 0) rem[x - l] /= p, e++;
      factors[x - l].emplace_back(p, e);
    });
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
