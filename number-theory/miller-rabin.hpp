#pragma once

namespace MillerRabin {
using u64 = uint64_t;
using u128 = __uint128_t;

namespace internal {
u64 multiply_mod(u64 a, u64 b, u64 mod) { return u128(a) * b % mod; }

u64 power_mod(u64 a, u64 n, u64 mod) {
  u64 ret = 1;
  while (n) {
    if (n & 1) ret = multiply_mod(ret, a, mod);
    a = multiply_mod(a, a, mod);
    n >>= 1;
  }
  return ret;
}
};  // namespace internal

bool is_prime(long long n) {
  if (n < 2) return false;
  u64 x = n;
  for (u64 p : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
    if (x % p == 0) return x == p;
  }

  int s = __builtin_ctzll(x - 1);
  u64 d = (x - 1) >> s;
  for (u64 a : {2, 325, 9375, 28178, 450775, 9780504, 1795265022}) {
    if (a % x == 0) continue;
    u64 y = internal::power_mod(a % x, d, x);
    if (y == 1 || y == x - 1) continue;
    bool composite = true;
    for (int r = 1; r < s; r++) {
      y = internal::multiply_mod(y, y, x);
      if (y == x - 1) {
        composite = false;
        break;
      }
    }
    if (composite) return false;
  }
  return true;
}
};  // namespace MillerRabin

/**
 * @brief Miller-Rabin 素数判定
 * @docs docs/number-theory/miller-rabin.md
 */
