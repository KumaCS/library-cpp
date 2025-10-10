#pragma once

namespace PrimeCount {
using i64 = int64_t;
static inline i64 div(i64 a, i64 b) { return double(a) / b; }
#define FUNC()                                                       \
  vector<i64> xs{0};                                                 \
  for (i64 i = N; i > 0; i = div(N, div(N, i) + 1)) xs.push_back(i); \
  vector<i64> cnt(xs);                                               \
  for (auto &x : cnt) --x;                                           \
  for (i64 x = 2, sq = sqrtl(N), xsz = xs.size(); x <= sq; ++x) {    \
    if (cnt[xsz - x] == cnt[xsz - x + 1]) continue;                  \
    i64 x2 = x * x, pi = cnt[xsz - x + 1];                           \
    for (i64 i = 1, n = xs[i]; i < xsz && n >= x2; n = xs[++i])      \
      cnt[i] -= cnt[i * x <= sq ? i * x : xsz - div(n, x)] - pi;     \
  }
pair<vector<i64>, vector<i64>> table(i64 N) {
  FUNC()
  return {xs, cnt};
}
i64 count(i64 N) {
  if (N < 2) return 0;
  FUNC()
  return cnt[1];
}
#undef FUNC
};  // namespace PrimeCount

/**
 * @brief 素数カウント
 * @docs docs/number-theory/prime-count.md
 */