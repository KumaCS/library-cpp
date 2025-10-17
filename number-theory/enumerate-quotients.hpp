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
  return N <= 1e12 ? pair<i64, i64>{div(N, q + 1), div(N, q)} : pair<i64, i64>{N / (q + 1), N / q};
}
template <class F>
void iterate(i64 N, F f) {
  i64 sq = Math::isqrt(N);
  vector<i64> xs;
  if (N <= 1e12) {
    i64 x = N;
    for (i64 q = 1; x <= sq; q++) {
      i64 y = div(N, q + 1);
      f(q, y, x);
      x = y;
    }
    for (; x > 0; x--) f(div(N, x), x - 1, x);
  } else {
    i64 x = N;
    for (i64 q = 1; x <= sq; q++) {
      i64 y = N / (q + 1);
      f(q, y, x);
      x = y;
    }
    for (; x > 0; x--) f(N / x, x - 1, x);
  }
}
};  // namespace EnumerateQuotients

/**
 * @brief 商の列挙
 * @docs docs/number-theory/enumerate-quotients.md
 */