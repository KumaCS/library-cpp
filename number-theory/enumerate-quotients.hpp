#pragma once

#include "math/util.hpp"

namespace EnumerateQuotients {
using i64 = int64_t;
i64 div(i64 a, i64 b) { return double(a) / b; };
vector<i64> table(i64 N) {
  i64 sq = Math::isqrt(N);
  vector<i64> xs(sq);
  iota(xs.begin(), xs.end(), 1);
  if (N <= 1e12) {
    for (i64 i = div(N, sq + 1); i > 0; i--) xs.push_back(div(N, i));
  } else {
    for (i64 i = N / (sq + 1); i > 0; i--) xs.push_back(N / i);
  }
  return xs;
}
pair<i64, i64> get_range(i64 N, i64 q) {
  i64 l = q == numeric_limits<i64>::max() ? 0 : (N <= 1e12 ? div(N, q + 1) : N / (q + 1));
  i64 r = N <= 1e12 ? div(N, q) : N / q;
  return {l, r};
}
template <class F>
void iterate(i64 N, F f) {
  i64 sq = Math::isqrt(N);
  if (N <= 1e12) {
    i64 x = N;
    for (i64 q = 1; x > sq; q++) {
      i64 y = div(N, q + 1);
      f(q, y, x);
      x = y;
    }
    for (; x > 0; x--) f(div(N, x), x - 1, x);
  } else {
    i64 x = N;
    for (i64 q = 1; x > sq; q++) {
      i64 y = N / (q + 1);
      f(q, y, x);
      x = y;
    }
    for (; x > 0; x--) f(N / x, x - 1, x);
  }
}

namespace internal {
i64 quotient_power(i64 N, i64 x, int k) {
  i64 p = 1;
  for (int e = 0; e < k; e++) {
    if (p > N / x) return 0;
    p *= x;
  }
  return N / p;
}
};  // namespace internal

pair<i64, i64> get_range(i64 N, i64 q, int k) {
  assert(N >= 0 && q >= 1 && k >= 1);
  if (k == 1) return get_range(N, q);
  i64 l = q == numeric_limits<i64>::max() ? 0 : Math::floor_root(N / (q + 1), k);
  i64 r = Math::floor_root(N / q, k);
  return {l, r};
}

template <class F>
void iterate(i64 N, int k, F f) {
  assert(N >= 0 && k >= 1);
  if (k == 1) {
    iterate(N, f);
    return;
  }
  if (N == 0) return;
  if (k >= 63) {
    f(N, 0, 1);
    return;
  }

  i64 s = Math::floor_root(N, k + 1);
  i64 max_q = internal::quotient_power(N, s + 1, k);
  i64 r = Math::floor_root(N, k);
  for (i64 q = 1; q <= max_q; q++) {
    i64 l = Math::floor_root(N / (q + 1), k);
    if (l < r) f(q, l, r);
    r = l;
  }
  for (; r > 0; r--) f(internal::quotient_power(N, r, k), r - 1, r);
}

vector<i64> table(i64 N, int k) {
  vector<i64> qs;
  iterate(N, k, [&](i64 q, i64, i64) { qs.push_back(q); });
  return qs;
}
};  // namespace EnumerateQuotients

/**
 * @brief 商の列挙
 * @docs docs/number-theory/enumerate-quotients.md
 */
