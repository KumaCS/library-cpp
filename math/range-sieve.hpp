#pragma once
#include "math/util.hpp"
#include "math/prime-sieve.hpp"

// lpf of [l,r]
vector<long long> RangeSieve(long long l, long long r) {
  assert(1 <= l && l <= r);
  const int sq = Math::isqrt(r);
  auto ps = PrimeSieve(sq);
  vector<long long> lpf(r - l + 1);
  iota(lpf.begin(), lpf.end(), l);
  for (long long p : ps) {
    for (long long k = Math::ceil(l, p) * p; k <= r; k += p)
      if (lpf[k - l] > p) lpf[k - l] = p;
  }
  return lpf;
}
/**
 * @brief 区間篩
 */