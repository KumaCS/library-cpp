---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/util.hpp
    title: math/util.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/number-theory/LC_enumerate_quotients.test.cpp
    title: verify/number-theory/LC_enumerate_quotients.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: docs/number-theory/enumerate-quotients.md
    document_title: "\u5546\u306E\u5217\u6319"
    links: []
  bundledCode: "#line 2 \"number-theory/enumerate-quotients.hpp\"\n\n#line 2 \"math/util.hpp\"\
    \n\nnamespace Math {\ntemplate <class T>\nT safe_mod(T a, T b) {\n  assert(b !=\
    \ 0);\n  if (b < 0) a = -a, b = -b;\n  a %= b;\n  return a >= 0 ? a : a + b;\n\
    }\ntemplate <class T>\nT floor(T a, T b) {\n  assert(b != 0);\n  if (b < 0) a\
    \ = -a, b = -b;\n  return a >= 0 ? a / b : (a + 1) / b - 1;\n}\ntemplate <class\
    \ T>\nT ceil(T a, T b) {\n  assert(b != 0);\n  if (b < 0) a = -a, b = -b;\n  return\
    \ a > 0 ? (a - 1) / b + 1 : a / b;\n}\nlong long isqrt(long long n) {\n  if (n\
    \ <= 0) return 0;\n  long long x = sqrt(n);\n  while ((x + 1) * (x + 1) <= n)\
    \ x++;\n  while (x * x > n) x--;\n  return x;\n}\n// return g=gcd(a,b)\n// a*x+b*y=g\n\
    // - b!=0 -> 0<=x<|b|/g\n// - b=0  -> ax=g\ntemplate <class T>\nT ext_gcd(T a,\
    \ T b, T& x, T& y) {\n  T a0 = a, b0 = b;\n  bool sgn_a = a < 0, sgn_b = b < 0;\n\
    \  if (sgn_a) a = -a;\n  if (sgn_b) b = -b;\n  if (b == 0) {\n    x = sgn_a ?\
    \ -1 : 1;\n    y = 0;\n    return a;\n  }\n  T x00 = 1, x01 = 0, x10 = 0, x11\
    \ = 1;\n  while (b != 0) {\n    T q = a / b, r = a - b * q;\n    x00 -= q * x01;\n\
    \    x10 -= q * x11;\n    swap(x00, x01);\n    swap(x10, x11);\n    a = b, b =\
    \ r;\n  }\n  x = x00, y = x10;\n  if (sgn_a) x = -x;\n  if (sgn_b) y = -y;\n \
    \ if (b0 != 0) {\n    a0 /= a, b0 /= a;\n    if (b0 < 0) a0 = -a0, b0 = -b0;\n\
    \    T q = x >= 0 ? x / b0 : (x + 1) / b0 - 1;\n    x -= b0 * q;\n    y += a0\
    \ * q;\n  }\n  return a;\n}\nlong long inv_mod(long long x, long long m) {\n \
    \ x %= m;\n  if (x < 0) x += m;\n  long long a = m, b = x;\n  long long y0 = 0,\
    \ y1 = 1;\n  while (b > 0) {\n    long long q = a / b;\n    swap(a -= q * b, b);\n\
    \    swap(y0 -= q * y1, y1);\n  }\n  if (y0 < 0) y0 += m / a;\n  return y0;\n\
    }\nlong long pow_mod(long long x, long long n, long long m) {\n  x = (x % m +\
    \ m) % m;\n  long long y = 1;\n  while (n) {\n    if (n & 1) y = y * x % m;\n\
    \    x = x * x % m;\n    n >>= 1;\n  }\n  return y;\n}\nconstexpr long long pow_mod_constexpr(long\
    \ long x, long long n, int m) {\n  if (m == 1) return 0;\n  unsigned int _m =\
    \ (unsigned int)(m);\n  unsigned long long r = 1;\n  unsigned long long y = x\
    \ % m;\n  if (y >= m) y += m;\n  while (n) {\n    if (n & 1) r = (r * y) % _m;\n\
    \    y = (y * y) % _m;\n    n >>= 1;\n  }\n  return r;\n}\nconstexpr bool is_prime_constexpr(int\
    \ n) {\n  if (n <= 1) return false;\n  if (n == 2 || n == 7 || n == 61) return\
    \ true;\n  if (n % 2 == 0) return false;\n  long long d = n - 1;\n  while (d %\
    \ 2 == 0) d /= 2;\n  constexpr long long bases[3] = {2, 7, 61};\n  for (long long\
    \ a : bases) {\n    long long t = d;\n    long long y = pow_mod_constexpr(a, t,\
    \ n);\n    while (t != n - 1 && y != 1 && y != n - 1) {\n      y = y * y % n;\n\
    \      t <<= 1;\n    }\n    if (y != n - 1 && t % 2 == 0) {\n      return false;\n\
    \    }\n  }\n  return true;\n}\ntemplate <int n>\nconstexpr bool is_prime = is_prime_constexpr(n);\n\
    };  // namespace Math\n#line 4 \"number-theory/enumerate-quotients.hpp\"\n\nnamespace\
    \ EnumerateQuotients {\nusing i64 = int64_t;\ni64 div(i64 a, i64 b) { return double(a)\
    \ / b; };\nvector<i64> table(i64 N) {\n  i64 sq = Math::isqrt(N);\n  vector<i64>\
    \ xs(sq);\n  iota(xs.begin(), xs.end(), 1);\n  if (N <= 1e12) {\n    for (i64\
    \ i = div(N, sq + 1); i > 0; i--) xs.push_back(div(N, i));\n  } else {\n    for\
    \ (i64 i = N / (sq + 1); i > 0; i--) xs.push_back(N / i);\n  }\n  return xs;\n\
    }\npair<i64, i64> get_range(i64 N, i64 q) {\n  return N <= 1e12 ? pair<i64, i64>{div(N,\
    \ q + 1), div(N, q)} : pair<i64, i64>{N / (q + 1), N / q};\n}\ntemplate <class\
    \ F>\nvoid iterate(i64 N, F f) {\n  i64 sq = Math::isqrt(N);\n  vector<i64> xs;\n\
    \  if (N <= 1e12) {\n    i64 x = N;\n    for (i64 q = 1; x <= sq; q++) {\n   \
    \   i64 y = div(N, q + 1);\n      f(q, y, x);\n      x = y;\n    }\n    for (;\
    \ x > 0; x--) f(div(N, x), x - 1, x);\n  } else {\n    i64 x = N;\n    for (i64\
    \ q = 1; x <= sq; q++) {\n      i64 y = N / (q + 1);\n      f(q, y, x);\n    \
    \  x = y;\n    }\n    for (; x > 0; x--) f(N / x, x - 1, x);\n  }\n}\n};  // namespace\
    \ EnumerateQuotients\n\n/**\n * @brief \u5546\u306E\u5217\u6319\n * @docs docs/number-theory/enumerate-quotients.md\n\
    \ */\n"
  code: "#pragma once\n\n#include \"math/util.hpp\"\n\nnamespace EnumerateQuotients\
    \ {\nusing i64 = int64_t;\ni64 div(i64 a, i64 b) { return double(a) / b; };\n\
    vector<i64> table(i64 N) {\n  i64 sq = Math::isqrt(N);\n  vector<i64> xs(sq);\n\
    \  iota(xs.begin(), xs.end(), 1);\n  if (N <= 1e12) {\n    for (i64 i = div(N,\
    \ sq + 1); i > 0; i--) xs.push_back(div(N, i));\n  } else {\n    for (i64 i =\
    \ N / (sq + 1); i > 0; i--) xs.push_back(N / i);\n  }\n  return xs;\n}\npair<i64,\
    \ i64> get_range(i64 N, i64 q) {\n  return N <= 1e12 ? pair<i64, i64>{div(N, q\
    \ + 1), div(N, q)} : pair<i64, i64>{N / (q + 1), N / q};\n}\ntemplate <class F>\n\
    void iterate(i64 N, F f) {\n  i64 sq = Math::isqrt(N);\n  vector<i64> xs;\n  if\
    \ (N <= 1e12) {\n    i64 x = N;\n    for (i64 q = 1; x <= sq; q++) {\n      i64\
    \ y = div(N, q + 1);\n      f(q, y, x);\n      x = y;\n    }\n    for (; x > 0;\
    \ x--) f(div(N, x), x - 1, x);\n  } else {\n    i64 x = N;\n    for (i64 q = 1;\
    \ x <= sq; q++) {\n      i64 y = N / (q + 1);\n      f(q, y, x);\n      x = y;\n\
    \    }\n    for (; x > 0; x--) f(N / x, x - 1, x);\n  }\n}\n};  // namespace EnumerateQuotients\n\
    \n/**\n * @brief \u5546\u306E\u5217\u6319\n * @docs docs/number-theory/enumerate-quotients.md\n\
    \ */"
  dependsOn:
  - math/util.hpp
  isVerificationFile: false
  path: number-theory/enumerate-quotients.hpp
  requiredBy: []
  timestamp: '2025-11-01 12:35:25+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/number-theory/LC_enumerate_quotients.test.cpp
documentation_of: number-theory/enumerate-quotients.hpp
layout: document
redirect_from:
- /library/number-theory/enumerate-quotients.hpp
- /library/number-theory/enumerate-quotients.hpp.html
title: "\u5546\u306E\u5217\u6319"
---
## 商の列挙

正整数 $N$ に対し，集合 $Q_N$ を

$$Q_N=\left\{\left\lfloor\frac{N}{x}\right\rfloor : x\in\mathbb{Z},1\leq x\leq N\right\}$$

で定める．$|Q_N|=O(\sqrt{N})$ である．

### `table(N)`

$Q_N$ の元を昇順に並べた列を求める．

### `get_range(N, y)`

$y\in Q_N$ に対し，$\left\lfloor\frac{N}{x}\right\rfloor=y$ となる $x$ の区間 $(l,r]$ を求める．

左側が開であることに注意．

### `iterate(N, f)`

$q\in Q_N$ について昇順に，$(l,r]=\operatorname{get\_range}(q)$ として関数 `f(q,l,r)` を呼び出す．