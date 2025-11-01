---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/util.hpp
    title: math/util.hpp
  _extendedRequiredBy:
  - icon: ':x:'
    path: fps/fps-sqrt.hpp
    title: fps/fps-sqrt.hpp
  - icon: ':question:'
    path: fps/relaxed.hpp
    title: Relaxed
  - icon: ':question:'
    path: fps/sparse.hpp
    title: "Sparse \u306A FPS \u6F14\u7B97"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/fps/LC_convolution_mod.relaxed.test.cpp
    title: verify/fps/LC_convolution_mod.relaxed.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/fps/LC_convolution_mod.semirelaxed.test.cpp
    title: verify/fps/LC_convolution_mod.semirelaxed.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/fps/LC_exp_of_formal_power_series.relaxed.test.cpp
    title: verify/fps/LC_exp_of_formal_power_series.relaxed.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/fps/LC_exp_of_formal_power_series_sparse.test.cpp
    title: verify/fps/LC_exp_of_formal_power_series_sparse.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/fps/LC_inv_of_formal_power_series.relaxed.test.cpp
    title: verify/fps/LC_inv_of_formal_power_series.relaxed.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/fps/LC_inv_of_formal_power_series_sparse.test.cpp
    title: verify/fps/LC_inv_of_formal_power_series_sparse.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/fps/LC_log_of_formal_power_series.relaxed.test.cpp
    title: verify/fps/LC_log_of_formal_power_series.relaxed.test.cpp
  - icon: ':x:'
    path: verify/fps/LC_log_of_formal_power_series_sparse.test.cpp
    title: verify/fps/LC_log_of_formal_power_series_sparse.test.cpp
  - icon: ':x:'
    path: verify/fps/LC_pow_of_formal_power_series_sparse.test.cpp
    title: verify/fps/LC_pow_of_formal_power_series_sparse.test.cpp
  - icon: ':x:'
    path: verify/fps/LC_sqrt_of_formal_power_series.relaxed.test.cpp
    title: verify/fps/LC_sqrt_of_formal_power_series.relaxed.test.cpp
  - icon: ':x:'
    path: verify/fps/LC_sqrt_of_formal_power_series.test.cpp
    title: verify/fps/LC_sqrt_of_formal_power_series.test.cpp
  - icon: ':x:'
    path: verify/fps/LC_sqrt_of_formal_power_series_sparse.test.cpp
    title: verify/fps/LC_sqrt_of_formal_power_series_sparse.test.cpp
  - icon: ':x:'
    path: verify/modint/UNIT_mod_sqrt.test.cpp
    title: verify/modint/UNIT_mod_sqrt.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"modint/mod-sqrt.hpp\"\n\n#line 2 \"math/util.hpp\"\n\nnamespace\
    \ Math {\ntemplate <class T>\nT safe_mod(T a, T b) {\n  assert(b != 0);\n  if\
    \ (b < 0) a = -a, b = -b;\n  a %= b;\n  return a >= 0 ? a : a + b;\n}\ntemplate\
    \ <class T>\nT floor(T a, T b) {\n  assert(b != 0);\n  if (b < 0) a = -a, b =\
    \ -b;\n  return a >= 0 ? a / b : (a + 1) / b - 1;\n}\ntemplate <class T>\nT ceil(T\
    \ a, T b) {\n  assert(b != 0);\n  if (b < 0) a = -a, b = -b;\n  return a > 0 ?\
    \ (a - 1) / b + 1 : a / b;\n}\nlong long isqrt(long long n) {\n  if (n <= 0) return\
    \ 0;\n  long long x = sqrt(n);\n  while ((x + 1) * (x + 1) <= n) x++;\n  while\
    \ (x * x > n) x--;\n  return x;\n}\n// return g=gcd(a,b)\n// a*x+b*y=g\n// - b!=0\
    \ -> 0<=x<|b|/g\n// - b=0  -> ax=g\ntemplate <class T>\nT ext_gcd(T a, T b, T&\
    \ x, T& y) {\n  T a0 = a, b0 = b;\n  bool sgn_a = a < 0, sgn_b = b < 0;\n  if\
    \ (sgn_a) a = -a;\n  if (sgn_b) b = -b;\n  if (b == 0) {\n    x = sgn_a ? -1 :\
    \ 1;\n    y = 0;\n    return a;\n  }\n  T x00 = 1, x01 = 0, x10 = 0, x11 = 1;\n\
    \  while (b != 0) {\n    T q = a / b, r = a - b * q;\n    x00 -= q * x01;\n  \
    \  x10 -= q * x11;\n    swap(x00, x01);\n    swap(x10, x11);\n    a = b, b = r;\n\
    \  }\n  x = x00, y = x10;\n  if (sgn_a) x = -x;\n  if (sgn_b) y = -y;\n  if (b0\
    \ != 0) {\n    a0 /= a, b0 /= a;\n    if (b0 < 0) a0 = -a0, b0 = -b0;\n    T q\
    \ = x >= 0 ? x / b0 : (x + 1) / b0 - 1;\n    x -= b0 * q;\n    y += a0 * q;\n\
    \  }\n  return a;\n}\nlong long inv_mod(long long x, long long m) {\n  x %= m;\n\
    \  if (x < 0) x += m;\n  long long a = m, b = x;\n  long long y0 = 0, y1 = 1;\n\
    \  while (b > 0) {\n    long long q = a / b;\n    swap(a -= q * b, b);\n    swap(y0\
    \ -= q * y1, y1);\n  }\n  if (y0 < 0) y0 += m / a;\n  return y0;\n}\nlong long\
    \ pow_mod(long long x, long long n, long long m) {\n  x = (x % m + m) % m;\n \
    \ long long y = 1;\n  while (n) {\n    if (n & 1) y = y * x % m;\n    x = x *\
    \ x % m;\n    n >>= 1;\n  }\n  return y;\n}\nconstexpr long long pow_mod_constexpr(long\
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
    };  // namespace Math\n#line 4 \"modint/mod-sqrt.hpp\"\n\nlong long ModSqrt(long\
    \ long a, long long p) {\n  if (a >= p) a %= p;\n  if (p == 2) return a & 1;\n\
    \  if (a == 0) return 0;\n  if (Math::pow_mod(a, (p - 1) / 2, p) != 1) return\
    \ -1;\n  if (p % 4 == 3) return Math::pow_mod(a, (3 * p - 1) / 4, p);\n  unsigned\
    \ int z = 2, q = p - 1;\n  while (Math::pow_mod(z, (p - 1) / 2, p) == 1) z++;\n\
    \  int s = 0;\n  while (!(q & 1)) {\n    s++;\n    q >>= 1;\n  }\n  int m = s;\n\
    \  unsigned int c = Math::pow_mod(z, q, p);\n  unsigned int t = Math::pow_mod(a,\
    \ q, p);\n  unsigned int r = Math::pow_mod(a, (q + 1) / 2, p);\n  while (true)\
    \ {\n    if (t == 1) return r;\n    unsigned int pow = t;\n    int j = 1;\n  \
    \  for (; j < m; j++) {\n      pow = 1ll * pow * pow % p;\n      if (pow == 1)\
    \ break;\n    }\n    unsigned int b = c;\n    for (int i = 0; i < m - j - 1; i++)\
    \ b = 1ll * b * b % p;\n    m = j;\n    c = 1ll * b * b % p;\n    t = 1ll * t\
    \ * c % p;\n    r = 1ll * r * b % p;\n  }\n}\n"
  code: "#pragma once\n\n#include \"math/util.hpp\"\n\nlong long ModSqrt(long long\
    \ a, long long p) {\n  if (a >= p) a %= p;\n  if (p == 2) return a & 1;\n  if\
    \ (a == 0) return 0;\n  if (Math::pow_mod(a, (p - 1) / 2, p) != 1) return -1;\n\
    \  if (p % 4 == 3) return Math::pow_mod(a, (3 * p - 1) / 4, p);\n  unsigned int\
    \ z = 2, q = p - 1;\n  while (Math::pow_mod(z, (p - 1) / 2, p) == 1) z++;\n  int\
    \ s = 0;\n  while (!(q & 1)) {\n    s++;\n    q >>= 1;\n  }\n  int m = s;\n  unsigned\
    \ int c = Math::pow_mod(z, q, p);\n  unsigned int t = Math::pow_mod(a, q, p);\n\
    \  unsigned int r = Math::pow_mod(a, (q + 1) / 2, p);\n  while (true) {\n    if\
    \ (t == 1) return r;\n    unsigned int pow = t;\n    int j = 1;\n    for (; j\
    \ < m; j++) {\n      pow = 1ll * pow * pow % p;\n      if (pow == 1) break;\n\
    \    }\n    unsigned int b = c;\n    for (int i = 0; i < m - j - 1; i++) b = 1ll\
    \ * b * b % p;\n    m = j;\n    c = 1ll * b * b % p;\n    t = 1ll * t * c % p;\n\
    \    r = 1ll * r * b % p;\n  }\n}"
  dependsOn:
  - math/util.hpp
  isVerificationFile: false
  path: modint/mod-sqrt.hpp
  requiredBy:
  - fps/relaxed.hpp
  - fps/sparse.hpp
  - fps/fps-sqrt.hpp
  timestamp: '2025-11-01 12:35:25+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/modint/UNIT_mod_sqrt.test.cpp
  - verify/fps/LC_inv_of_formal_power_series.relaxed.test.cpp
  - verify/fps/LC_inv_of_formal_power_series_sparse.test.cpp
  - verify/fps/LC_convolution_mod.relaxed.test.cpp
  - verify/fps/LC_sqrt_of_formal_power_series_sparse.test.cpp
  - verify/fps/LC_convolution_mod.semirelaxed.test.cpp
  - verify/fps/LC_exp_of_formal_power_series.relaxed.test.cpp
  - verify/fps/LC_log_of_formal_power_series.relaxed.test.cpp
  - verify/fps/LC_exp_of_formal_power_series_sparse.test.cpp
  - verify/fps/LC_pow_of_formal_power_series_sparse.test.cpp
  - verify/fps/LC_log_of_formal_power_series_sparse.test.cpp
  - verify/fps/LC_sqrt_of_formal_power_series.test.cpp
  - verify/fps/LC_sqrt_of_formal_power_series.relaxed.test.cpp
documentation_of: modint/mod-sqrt.hpp
layout: document
redirect_from:
- /library/modint/mod-sqrt.hpp
- /library/modint/mod-sqrt.hpp.html
title: modint/mod-sqrt.hpp
---
