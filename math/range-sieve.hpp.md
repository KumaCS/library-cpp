---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: math/prime-sieve.hpp
    title: "\u7D20\u6570\u7BE9"
  - icon: ':heavy_check_mark:'
    path: math/util.hpp
    title: math/util.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u533A\u9593\u7BE9"
    links: []
  bundledCode: "#line 2 \"math/util.hpp\"\n\nnamespace Math {\ntemplate <class T>\n\
    T safe_mod(T a, T b) {\n  assert(b != 0);\n  if (b < 0) a = -a, b = -b;\n  a %=\
    \ b;\n  return a >= 0 ? a : a + b;\n}\ntemplate <class T>\nT floor(T a, T b) {\n\
    \  assert(b != 0);\n  if (b < 0) a = -a, b = -b;\n  return a >= 0 ? a / b : (a\
    \ + 1) / b - 1;\n}\ntemplate <class T>\nT ceil(T a, T b) {\n  assert(b != 0);\n\
    \  if (b < 0) a = -a, b = -b;\n  return a > 0 ? (a - 1) / b + 1 : a / b;\n}\n\
    long long isqrt(long long n) {\n  if (n <= 0) return 0;\n  long long x = sqrt(n);\n\
    \  while ((x + 1) * (x + 1) <= n) x++;\n  while (x * x > n) x--;\n  return x;\n\
    }\n// return g=gcd(a,b)\n// a*x+b*y=g\n// - b!=0 -> 0<=x<|b|/g\n// - b=0  -> ax=g\n\
    template <class T>\nT ext_gcd(T a, T b, T& x, T& y) {\n  T a0 = a, b0 = b;\n \
    \ bool sgn_a = a < 0, sgn_b = b < 0;\n  if (sgn_a) a = -a;\n  if (sgn_b) b = -b;\n\
    \  if (b == 0) {\n    x = sgn_a ? -1 : 1;\n    y = 0;\n    return a;\n  }\n  T\
    \ x00 = 1, x01 = 0, x10 = 0, x11 = 1;\n  while (b != 0) {\n    T q = a / b, r\
    \ = a - b * q;\n    x00 -= q * x01;\n    x10 -= q * x11;\n    swap(x00, x01);\n\
    \    swap(x10, x11);\n    a = b, b = r;\n  }\n  x = x00, y = x10;\n  if (sgn_a)\
    \ x = -x;\n  if (sgn_b) y = -y;\n  if (b0 != 0) {\n    a0 /= a, b0 /= a;\n   \
    \ if (b0 < 0) a0 = -a0, b0 = -b0;\n    T q = x >= 0 ? x / b0 : (x + 1) / b0 -\
    \ 1;\n    x -= b0 * q;\n    y += a0 * q;\n  }\n  return a;\n}\nconstexpr long\
    \ long inv_mod(long long x, long long m) {\n  x %= m;\n  if (x < 0) x += m;\n\
    \  long long a = m, b = x;\n  long long y0 = 0, y1 = 1;\n  while (b > 0) {\n \
    \   long long q = a / b;\n    swap(a -= q * b, b);\n    swap(y0 -= q * y1, y1);\n\
    \  }\n  if (y0 < 0) y0 += m / a;\n  return y0;\n}\nlong long pow_mod(long long\
    \ x, long long n, long long m) {\n  x = (x % m + m) % m;\n  long long y = 1;\n\
    \  while (n) {\n    if (n & 1) y = y * x % m;\n    x = x * x % m;\n    n >>= 1;\n\
    \  }\n  return y;\n}\nconstexpr long long pow_mod_constexpr(long long x, long\
    \ long n, int m) {\n  if (m == 1) return 0;\n  unsigned int _m = (unsigned int)(m);\n\
    \  unsigned long long r = 1;\n  unsigned long long y = x % m;\n  if (y >= m) y\
    \ += m;\n  while (n) {\n    if (n & 1) r = (r * y) % _m;\n    y = (y * y) % _m;\n\
    \    n >>= 1;\n  }\n  return r;\n}\nconstexpr bool is_prime_constexpr(int n) {\n\
    \  if (n <= 1) return false;\n  if (n == 2 || n == 7 || n == 61) return true;\n\
    \  if (n % 2 == 0) return false;\n  long long d = n - 1;\n  while (d % 2 == 0)\
    \ d /= 2;\n  constexpr long long bases[3] = {2, 7, 61};\n  for (long long a :\
    \ bases) {\n    long long t = d;\n    long long y = pow_mod_constexpr(a, t, n);\n\
    \    while (t != n - 1 && y != 1 && y != n - 1) {\n      y = y * y % n;\n    \
    \  t <<= 1;\n    }\n    if (y != n - 1 && t % 2 == 0) {\n      return false;\n\
    \    }\n  }\n  return true;\n}\ntemplate <int n>\nconstexpr bool is_prime = is_prime_constexpr(n);\n\
    };  // namespace Math\n#line 2 \"math/prime-sieve.hpp\"\n\nvector<int> PrimeSieve(int\
    \ n) {\n  vector<bool> f(n + 1, false);\n  for (int p = 2; p * p <= n; p += (p\
    \ & 1) + 1) {\n    if (f[p]) continue;\n    for (int i = p * p; i <= n; i += p)\
    \ f[i] = true;\n  }\n  vector<int> ps;\n  for (int p = 2; p <= n; p += (p & 1)\
    \ + 1)\n    if (!f[p]) ps.push_back(p);\n  return ps;\n}\n/**\n * @brief \u7D20\
    \u6570\u7BE9\n */\n#line 4 \"math/range-sieve.hpp\"\n\n// lpf of [l,r]\nvector<long\
    \ long> RangeSieve(long long l, long long r) {\n  assert(1 <= l && l <= r);\n\
    \  const int sq = Math::isqrt(r);\n  auto ps = PrimeSieve(sq);\n  vector<long\
    \ long> lpf(r - l + 1);\n  iota(lpf.begin(), lpf.end(), l);\n  for (long long\
    \ p : ps) {\n    for (long long k = Math::ceil(l, p) * p; k <= r; k += p)\n  \
    \    if (lpf[k - l] > p) lpf[k - l] = p;\n  }\n  return lpf;\n}\n/**\n * @brief\
    \ \u533A\u9593\u7BE9\n */\n"
  code: "#pragma once\n#include \"math/util.hpp\"\n#include \"math/prime-sieve.hpp\"\
    \n\n// lpf of [l,r]\nvector<long long> RangeSieve(long long l, long long r) {\n\
    \  assert(1 <= l && l <= r);\n  const int sq = Math::isqrt(r);\n  auto ps = PrimeSieve(sq);\n\
    \  vector<long long> lpf(r - l + 1);\n  iota(lpf.begin(), lpf.end(), l);\n  for\
    \ (long long p : ps) {\n    for (long long k = Math::ceil(l, p) * p; k <= r; k\
    \ += p)\n      if (lpf[k - l] > p) lpf[k - l] = p;\n  }\n  return lpf;\n}\n/**\n\
    \ * @brief \u533A\u9593\u7BE9\n */"
  dependsOn:
  - math/util.hpp
  - math/prime-sieve.hpp
  isVerificationFile: false
  path: math/range-sieve.hpp
  requiredBy: []
  timestamp: '2026-02-28 01:08:20+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/range-sieve.hpp
layout: document
redirect_from:
- /library/math/range-sieve.hpp
- /library/math/range-sieve.hpp.html
title: "\u533A\u9593\u7BE9"
---
