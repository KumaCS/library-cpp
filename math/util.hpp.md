---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: math/garner-online.hpp
    title: "Garner \u306E\u30A2\u30EB\u30B4\u30EA\u30BA\u30E0 (\u30AA\u30F3\u30E9\u30A4\
      \u30F3)"
  - icon: ':warning:'
    path: math/garner.hpp
    title: "Garner \u306E\u30A2\u30EB\u30B4\u30EA\u30BA\u30E0"
  - icon: ':warning:'
    path: math/polynomial-floor-sum.hpp
    title: "\u591A\u9805\u5F0F\u7248 floor sum"
  - icon: ':heavy_check_mark:'
    path: number-theory/enumerate-quotients.hpp
    title: "\u5546\u306E\u5217\u6319"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/number-theory/LC_enumerate_quotients.test.cpp
    title: verify/number-theory/LC_enumerate_quotients.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
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
    \ 1;\n    x -= b0 * q;\n    y += a0 * q;\n  }\n  return a;\n}\ntemplate <class\
    \ T>\nT inv_mod(T x, T m) {\n  x %= m;\n  if (x < 0) x += m;\n  T a = m, b = x;\n\
    \  T y0 = 0, y1 = 1;\n  while (b > 0) {\n    T q = a / b;\n    swap(a -= q * b,\
    \ b);\n    swap(y0 -= q * y1, y1);\n  }\n  if (y0 < 0) y0 += m / a;\n  return\
    \ y0;\n}\ntemplate <class T>\nT pow_mod(T x, T n, T m) {\n  x = (x % m + m) %\
    \ m;\n  T y = 1;\n  while (n) {\n    if (n & 1) y = y * x % m;\n    x = x * x\
    \ % m;\n    n >>= 1;\n  }\n  return y;\n}\nconstexpr long long pow_mod_constexpr(long\
    \ long x, long long n, int m) {\n  if (m == 1) return 0;\n  unsigned int _m =\
    \ (unsigned int)(m);\n  unsigned long long r = 1;\n  unsigned long long y = x\
    \ % m;\n  if (y >= m) y += m;\n  while (n) {\n    if (n & 1) r = (r * y) % _m;\n\
    \    y = (y * y) % _m;\n    n >>= 1;\n  }\n  return r;\n}\n};  // namespace Math\n"
  code: "#pragma once\n\nnamespace Math {\ntemplate <class T>\nT safe_mod(T a, T b)\
    \ {\n  assert(b != 0);\n  if (b < 0) a = -a, b = -b;\n  a %= b;\n  return a >=\
    \ 0 ? a : a + b;\n}\ntemplate <class T>\nT floor(T a, T b) {\n  assert(b != 0);\n\
    \  if (b < 0) a = -a, b = -b;\n  return a >= 0 ? a / b : (a + 1) / b - 1;\n}\n\
    template <class T>\nT ceil(T a, T b) {\n  assert(b != 0);\n  if (b < 0) a = -a,\
    \ b = -b;\n  return a > 0 ? (a - 1) / b + 1 : a / b;\n}\nlong long isqrt(long\
    \ long n) {\n  if (n <= 0) return 0;\n  long long x = sqrt(n);\n  while ((x +\
    \ 1) * (x + 1) <= n) x++;\n  while (x * x > n) x--;\n  return x;\n}\n// return\
    \ g=gcd(a,b)\n// a*x+b*y=g\n// - b!=0 -> 0<=x<|b|/g\n// - b=0  -> ax=g\ntemplate\
    \ <class T>\nT ext_gcd(T a, T b, T& x, T& y) {\n  T a0 = a, b0 = b;\n  bool sgn_a\
    \ = a < 0, sgn_b = b < 0;\n  if (sgn_a) a = -a;\n  if (sgn_b) b = -b;\n  if (b\
    \ == 0) {\n    x = sgn_a ? -1 : 1;\n    y = 0;\n    return a;\n  }\n  T x00 =\
    \ 1, x01 = 0, x10 = 0, x11 = 1;\n  while (b != 0) {\n    T q = a / b, r = a -\
    \ b * q;\n    x00 -= q * x01;\n    x10 -= q * x11;\n    swap(x00, x01);\n    swap(x10,\
    \ x11);\n    a = b, b = r;\n  }\n  x = x00, y = x10;\n  if (sgn_a) x = -x;\n \
    \ if (sgn_b) y = -y;\n  if (b0 != 0) {\n    a0 /= a, b0 /= a;\n    if (b0 < 0)\
    \ a0 = -a0, b0 = -b0;\n    T q = x >= 0 ? x / b0 : (x + 1) / b0 - 1;\n    x -=\
    \ b0 * q;\n    y += a0 * q;\n  }\n  return a;\n}\ntemplate <class T>\nT inv_mod(T\
    \ x, T m) {\n  x %= m;\n  if (x < 0) x += m;\n  T a = m, b = x;\n  T y0 = 0, y1\
    \ = 1;\n  while (b > 0) {\n    T q = a / b;\n    swap(a -= q * b, b);\n    swap(y0\
    \ -= q * y1, y1);\n  }\n  if (y0 < 0) y0 += m / a;\n  return y0;\n}\ntemplate\
    \ <class T>\nT pow_mod(T x, T n, T m) {\n  x = (x % m + m) % m;\n  T y = 1;\n\
    \  while (n) {\n    if (n & 1) y = y * x % m;\n    x = x * x % m;\n    n >>= 1;\n\
    \  }\n  return y;\n}\nconstexpr long long pow_mod_constexpr(long long x, long\
    \ long n, int m) {\n  if (m == 1) return 0;\n  unsigned int _m = (unsigned int)(m);\n\
    \  unsigned long long r = 1;\n  unsigned long long y = x % m;\n  if (y >= m) y\
    \ += m;\n  while (n) {\n    if (n & 1) r = (r * y) % _m;\n    y = (y * y) % _m;\n\
    \    n >>= 1;\n  }\n  return r;\n}\n};  // namespace Math"
  dependsOn: []
  isVerificationFile: false
  path: math/util.hpp
  requiredBy:
  - math/polynomial-floor-sum.hpp
  - math/garner.hpp
  - math/garner-online.hpp
  - number-theory/enumerate-quotients.hpp
  timestamp: '2025-10-17 21:43:09+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/number-theory/LC_enumerate_quotients.test.cpp
documentation_of: math/util.hpp
layout: document
redirect_from:
- /library/math/util.hpp
- /library/math/util.hpp.html
title: math/util.hpp
---
