---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/number-theory/LC_counting_primes.test.cpp
    title: verify/number-theory/LC_counting_primes.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: docs/number-theory/prime-count.md
    document_title: "\u7D20\u6570\u30AB\u30A6\u30F3\u30C8"
    links: []
  bundledCode: "#line 2 \"number-theory/prime-count.hpp\"\n\nnamespace PrimeCount\
    \ {\nusing i64 = int64_t;\nstatic inline i64 div(i64 a, i64 b) { return double(a)\
    \ / b; }\n#define FUNC()                                                     \
    \  \\\n  vector<i64> xs{0};                                                 \\\
    \n  for (i64 i = N; i > 0; i = div(N, div(N, i) + 1)) xs.push_back(i); \\\n  vector<i64>\
    \ cnt(xs);                                               \\\n  for (auto &x :\
    \ cnt) --x;                                           \\\n  for (i64 x = 2, sq\
    \ = sqrtl(N), xsz = xs.size(); x <= sq; ++x) {    \\\n    if (cnt[xsz - x] ==\
    \ cnt[xsz - x + 1]) continue;                  \\\n    i64 x2 = x * x, pi = cnt[xsz\
    \ - x + 1];                           \\\n    for (i64 i = 1, n = xs[i]; i < xsz\
    \ && n >= x2; n = xs[++i])      \\\n      cnt[i] -= cnt[i * x <= sq ? i * x :\
    \ xsz - div(n, x)] - pi;     \\\n  }\npair<vector<i64>, vector<i64>> table(i64\
    \ N) {\n  FUNC()\n  return {xs, cnt};\n}\ni64 count(i64 N) {\n  if (N < 2) return\
    \ 0;\n  FUNC()\n  return cnt[1];\n}\n#undef FUNC\n};  // namespace PrimeCount\n\
    \n/**\n * @brief \u7D20\u6570\u30AB\u30A6\u30F3\u30C8\n * @docs docs/number-theory/prime-count.md\n\
    \ */\n"
  code: "#pragma once\n\nnamespace PrimeCount {\nusing i64 = int64_t;\nstatic inline\
    \ i64 div(i64 a, i64 b) { return double(a) / b; }\n#define FUNC()            \
    \                                           \\\n  vector<i64> xs{0};         \
    \                                        \\\n  for (i64 i = N; i > 0; i = div(N,\
    \ div(N, i) + 1)) xs.push_back(i); \\\n  vector<i64> cnt(xs);                \
    \                               \\\n  for (auto &x : cnt) --x;               \
    \                            \\\n  for (i64 x = 2, sq = sqrtl(N), xsz = xs.size();\
    \ x <= sq; ++x) {    \\\n    if (cnt[xsz - x] == cnt[xsz - x + 1]) continue; \
    \                 \\\n    i64 x2 = x * x, pi = cnt[xsz - x + 1];             \
    \              \\\n    for (i64 i = 1, n = xs[i]; i < xsz && n >= x2; n = xs[++i])\
    \      \\\n      cnt[i] -= cnt[i * x <= sq ? i * x : xsz - div(n, x)] - pi;  \
    \   \\\n  }\npair<vector<i64>, vector<i64>> table(i64 N) {\n  FUNC()\n  return\
    \ {xs, cnt};\n}\ni64 count(i64 N) {\n  if (N < 2) return 0;\n  FUNC()\n  return\
    \ cnt[1];\n}\n#undef FUNC\n};  // namespace PrimeCount\n\n/**\n * @brief \u7D20\
    \u6570\u30AB\u30A6\u30F3\u30C8\n * @docs docs/number-theory/prime-count.md\n */"
  dependsOn: []
  isVerificationFile: false
  path: number-theory/prime-count.hpp
  requiredBy: []
  timestamp: '2025-10-10 17:35:46+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/number-theory/LC_counting_primes.test.cpp
documentation_of: number-theory/prime-count.hpp
layout: document
redirect_from:
- /library/number-theory/prime-count.hpp
- /library/number-theory/prime-count.hpp.html
title: "\u7D20\u6570\u30AB\u30A6\u30F3\u30C8"
---
## 素数カウント

集合 $Q_N=\left\{\lfloor\frac{N}{x}\rfloor:1\leq x\leq N\right\}$ について，$Q_N=\{x_1,x_2,\dots,x_m\},x_1\lt x_2\lt\cdots\lt x_m$ とおく．
$\pi(x_1),\pi(x_2),\dots,\pi(x_m)$ を $O\left(\frac{N^{3/4}}{\log{N}}\right)$ 時間で列挙する．

### 概要

Lucy DP．

$N\leq 10^{12}$ 程度の場合，除算を double で行うことで定数倍高速化できる．