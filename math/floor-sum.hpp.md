---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/math/LC_sum_of_floor_of_linear.test.cpp
    title: verify/math/LC_sum_of_floor_of_linear.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/math/floor-sum.md
    document_title: Floor Sum
    links: []
  bundledCode: "#line 2 \"math/floor-sum.hpp\"\n\n// sum{i=0}^{n-1}floor((a*i+b)/m)\n\
    template <class T>\nT FloorSumUnsigned(unsigned long long n, unsigned long long\
    \ m, unsigned long long a, unsigned long long b) {\n  assert(m != 0);\n  if (n\
    \ == 0) return 0;\n  T res = 0;\n  while (true) {\n    if (a >= m) {\n      unsigned\
    \ long long q = a / m;\n      res += T(q) * (n / 2) * ((n - 1) | 1);\n      a\
    \ -= m * q;\n    }\n    if (b >= m) {\n      unsigned long long q = b / m;\n \
    \     res += T(q) * n;\n      b -= m * q;\n    }\n    unsigned long long y = a\
    \ * n + b;\n    if (y < m) break;\n    n = y / m, b = y - m * n;\n    swap(a,\
    \ m);\n  }\n  return res;\n}\n\n// sum{i=0}^{n-1}floor((a*i+b)/m)\ntemplate <class\
    \ T>\nT FloorSum(long long n, long long m, long long a, long long b) {\n  assert(m\
    \ != 0);\n  if (n <= 0) return 0;\n  if (m < 0) a = -a, b = -b, m = -m;\n  T res\
    \ = 0;\n  if (a < 0) {\n    long long q = (a + 1) / m - 1;\n    res += T(q) *\
    \ (n / 2) * ((n - 1) | 1);\n    a -= m * q;\n  }\n  if (b < 0) {\n    long long\
    \ q = (b + 1) / m - 1;\n    res += T(q) * n;\n    b -= m * q;\n  }\n  return res\
    \ + FloorSumUnsigned<T>(n, m, a, b);\n}\n\n/**\n * @brief Floor Sum\n * @docs\
    \ docs/math/floor-sum.md\n */\n"
  code: "#pragma once\n\n// sum{i=0}^{n-1}floor((a*i+b)/m)\ntemplate <class T>\nT\
    \ FloorSumUnsigned(unsigned long long n, unsigned long long m, unsigned long long\
    \ a, unsigned long long b) {\n  assert(m != 0);\n  if (n == 0) return 0;\n  T\
    \ res = 0;\n  while (true) {\n    if (a >= m) {\n      unsigned long long q =\
    \ a / m;\n      res += T(q) * (n / 2) * ((n - 1) | 1);\n      a -= m * q;\n  \
    \  }\n    if (b >= m) {\n      unsigned long long q = b / m;\n      res += T(q)\
    \ * n;\n      b -= m * q;\n    }\n    unsigned long long y = a * n + b;\n    if\
    \ (y < m) break;\n    n = y / m, b = y - m * n;\n    swap(a, m);\n  }\n  return\
    \ res;\n}\n\n// sum{i=0}^{n-1}floor((a*i+b)/m)\ntemplate <class T>\nT FloorSum(long\
    \ long n, long long m, long long a, long long b) {\n  assert(m != 0);\n  if (n\
    \ <= 0) return 0;\n  if (m < 0) a = -a, b = -b, m = -m;\n  T res = 0;\n  if (a\
    \ < 0) {\n    long long q = (a + 1) / m - 1;\n    res += T(q) * (n / 2) * ((n\
    \ - 1) | 1);\n    a -= m * q;\n  }\n  if (b < 0) {\n    long long q = (b + 1)\
    \ / m - 1;\n    res += T(q) * n;\n    b -= m * q;\n  }\n  return res + FloorSumUnsigned<T>(n,\
    \ m, a, b);\n}\n\n/**\n * @brief Floor Sum\n * @docs docs/math/floor-sum.md\n\
    \ */"
  dependsOn: []
  isVerificationFile: false
  path: math/floor-sum.hpp
  requiredBy: []
  timestamp: '2025-10-17 21:43:09+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/math/LC_sum_of_floor_of_linear.test.cpp
documentation_of: math/floor-sum.hpp
layout: document
redirect_from:
- /library/math/floor-sum.hpp
- /library/math/floor-sum.hpp.html
title: Floor Sum
---
## 使い方

以下の問題を解く．

> 整数 $n,m,a,b\ (m\neq 0)$ に対し以下の値を求めよ：
> $$f(n,m,a,b)=\sum_{i=0}^{n-1}\left\lfloor\frac{ai+b}{m}\right\rfloor$$

$an+b$ が `unsigned long long` におさまる必要がある．

## アルゴリズム

再帰的に考える．

$n=0$ のとき $f(n,m,a,b)=0$ である．

簡単な変形によって $m\geq 1$ および $0\leq a\lt m, 0\leq b\lt m$ として構わない．

$a\geq 0$ のとき $an+b=mq+r\,(0\leq r\lt m)$ とする．
$0\leq i\lt n$ に対し $0\leq\left\lfloor\frac{ai+b}{m}\right\rfloor\leq q$ であり，$\left\lfloor\frac{ai+b}{m}\right\rfloor\geq k$ となる $i$ の範囲は $\frac{mk-b}{a}\leq i$ であるから以下が成り立つ．

$$\begin{align*}
f(n,m,a,b)
&=\sum_{k=1}^{q}\left(n-\left\lceil\frac{mk-b}{a}\right\rceil\right)\\
&=\sum_{k=1}^{q}\left(n+\left\lfloor\frac{b-mk}{a}\right\rfloor\right)\\
&=\sum_{k=0}^{q-1}\left(n+\left\lfloor\frac{b-m(q-k)}{a}\right\rfloor\right)\\
&=\sum_{k=0}^{q-1}\left\lfloor\frac{mk+an+b-mq}{a}\right\rfloor\\
&=\sum_{k=0}^{q-1}\left\lfloor\frac{mk+r}{a}\right\rfloor\\
&=f(q,a,m,r)
\end{align*}$$

$m,a$ について Euclid の互除法と同じ議論ができ，$O(\log m)$ 回の反復で停止することが示せる．