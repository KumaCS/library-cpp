#pragma once

#include "number-theory/miller-rabin.hpp"

namespace PollardRho {
using ll = long long;
using u64 = uint64_t;

namespace internal {
u64 random() {
  static u64 x = 0x243f6a8885a308d3ULL;
  x ^= x << 7;
  x ^= x >> 9;
  return x;
}

u64 find_factor(u64 n) {
  if (n % 2 == 0) return 2;
  if (n % 3 == 0) return 3;

  while (true) {
    u64 y = random() % (n - 1) + 1;
    u64 c = random() % (n - 1) + 1;
    u64 m = 128, g = 1, r = 1, q = 1, x = 0, z = 0;
    auto f = [&](u64 v) {
      return (MillerRabin::internal::multiply_mod(v, v, n) + c) % n;
    };
    while (g == 1) {
      x = y;
      for (u64 i = 0; i < r; i++) y = f(y);
      for (u64 k = 0; k < r && g == 1; k += m) {
        z = y;
        for (u64 i = 0; i < min(m, r - k); i++) {
          y = f(y);
          u64 d = x > y ? x - y : y - x;
          q = MillerRabin::internal::multiply_mod(q, d, n);
        }
        g = gcd(q, n);
      }
      r <<= 1;
    }
    if (g == n) {
      do {
        z = f(z);
        u64 d = x > z ? x - z : z - x;
        g = gcd(d, n);
      } while (g == 1);
    }
    if (g != n) return g;
  }
}

void factorize(u64 n, vector<u64>& factors) {
  if (n == 1) return;
  if (MillerRabin::is_prime(n)) {
    factors.push_back(n);
    return;
  }
  u64 d = find_factor(n);
  factorize(d, factors);
  factorize(n / d, factors);
}
};  // namespace internal

vector<pair<ll, int>> factorize(ll n) {
  assert(n >= 1);
  vector<u64> factors;
  internal::factorize(n, factors);
  sort(factors.begin(), factors.end());

  vector<pair<ll, int>> ret;
  for (u64 p : factors) {
    if (ret.empty() || ret.back().first != (ll)p)
      ret.emplace_back(p, 1);
    else
      ret.back().second++;
  }
  return ret;
}

vector<ll> divisors(ll n) {
  vector<ll> ret{1};
  for (auto [p, e] : factorize(n)) {
    size_t size = ret.size();
    ll q = 1;
    while (e--) {
      q *= p;
      for (size_t i = 0; i < size; i++) ret.push_back(ret[i] * q);
    }
  }
  sort(ret.begin(), ret.end());
  return ret;
}
};  // namespace PollardRho

/**
 * @brief Pollard's rho algorithm
 * @docs docs/number-theory/pollard-rho.md
 */
