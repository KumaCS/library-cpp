#pragma once

#include "number-theory/miller-rabin.hpp"
#include "number-theory/pollard-rho.hpp"

long long PrimitiveRoot(long long p) {
  assert(p >= 2 && MillerRabin::is_prime(p));
  if (p == 2) return 1;

  auto factors = PollardRho::factorize(p - 1);

  for (long long g = 2;; g++) {
    bool ok = true;
    for (auto [q, e] : factors)
      if (MillerRabin::internal::power_mod(g, (p - 1) / q, p) == 1) {
        ok = false;
        break;
      }
    if (ok) return g;
  }
}

/**
 * @brief 原始根
 * @docs docs/number-theory/primitive-root.md
 */
