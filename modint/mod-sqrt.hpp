#pragma once

#include "math/util.hpp"

long long ModSqrt(long long a, long long p) {
  if (a >= p) a %= p;
  if (p == 2) return a & 1;
  if (a == 0) return 0;
  if (Math::pow_mod(a, (p - 1) / 2, p) != 1) return -1;
  if (p % 4 == 3) return Math::pow_mod(a, (3 * p - 1) / 4, p);
  unsigned int z = 2, q = p - 1;
  while (Math::pow_mod(z, (p - 1) / 2, p) == 1) z++;
  int s = 0;
  while (!(q & 1)) {
    s++;
    q >>= 1;
  }
  int m = s;
  unsigned int c = Math::pow_mod(z, q, p);
  unsigned int t = Math::pow_mod(a, q, p);
  unsigned int r = Math::pow_mod(a, (q + 1) / 2, p);
  while (true) {
    if (t == 1) return r;
    unsigned int pow = t;
    int j = 1;
    for (; j < m; j++) {
      pow = 1ll * pow * pow % p;
      if (pow == 1) break;
    }
    unsigned int b = c;
    for (int i = 0; i < m - j - 1; i++) b = 1ll * b * b % p;
    m = j;
    c = 1ll * b * b % p;
    t = 1ll * t * c % p;
    r = 1ll * r * b % p;
  }
}