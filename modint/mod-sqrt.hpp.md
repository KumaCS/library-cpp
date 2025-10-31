---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: modint/mod-pow.hpp
    title: modint/mod-pow.hpp
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
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"modint/mod-sqrt.hpp\"\n\n#line 2 \"modint/mod-pow.hpp\"\n\
    \nunsigned int ModPow(unsigned int a, unsigned long long n, unsigned int m) {\n\
    \  unsigned long long x = a, y = 1;\n  while (n) {\n    if (n & 1) y = y * x %\
    \ m;\n    x = x * x % m;\n    n >>= 1;\n  }\n  return y;\n}\n#line 4 \"modint/mod-sqrt.hpp\"\
    \n\nlong long ModSqrt(long long a, long long p) {\n  if (a >= p) a %= p;\n  if\
    \ (p == 2) return a & 1;\n  if (a == 0) return 0;\n  if (ModPow(a, (p - 1) / 2,\
    \ p) != 1) return -1;\n  if (p % 4 == 3) return ModPow(a, (3 * p - 1) / 4, p);\n\
    \  unsigned int z = 2, q = p - 1;\n  while (ModPow(z, (p - 1) / 2, p) == 1) z++;\n\
    \  int s = 0;\n  while (!(q & 1)) {\n    s++;\n    q >>= 1;\n  }\n  int m = s;\n\
    \  unsigned int c = ModPow(z, q, p);\n  unsigned int t = ModPow(a, q, p);\n  unsigned\
    \ int r = ModPow(a, (q + 1) / 2, p);\n  while (true) {\n    if (t == 1) return\
    \ r;\n    unsigned int pow = t;\n    int j = 1;\n    for (; j < m; j++) {\n  \
    \    pow = 1ll * pow * pow % p;\n      if (pow == 1) break;\n    }\n    unsigned\
    \ int b = c;\n    for (int i = 0; i < m - j - 1; i++) b = 1ll * b * b % p;\n \
    \   m = j;\n    c = 1ll * b * b % p;\n    t = 1ll * t * c % p;\n    r = 1ll *\
    \ r * b % p;\n  }\n}\n"
  code: "#pragma once\n\n#include \"./mod-pow.hpp\"\n\nlong long ModSqrt(long long\
    \ a, long long p) {\n  if (a >= p) a %= p;\n  if (p == 2) return a & 1;\n  if\
    \ (a == 0) return 0;\n  if (ModPow(a, (p - 1) / 2, p) != 1) return -1;\n  if (p\
    \ % 4 == 3) return ModPow(a, (3 * p - 1) / 4, p);\n  unsigned int z = 2, q = p\
    \ - 1;\n  while (ModPow(z, (p - 1) / 2, p) == 1) z++;\n  int s = 0;\n  while (!(q\
    \ & 1)) {\n    s++;\n    q >>= 1;\n  }\n  int m = s;\n  unsigned int c = ModPow(z,\
    \ q, p);\n  unsigned int t = ModPow(a, q, p);\n  unsigned int r = ModPow(a, (q\
    \ + 1) / 2, p);\n  while (true) {\n    if (t == 1) return r;\n    unsigned int\
    \ pow = t;\n    int j = 1;\n    for (; j < m; j++) {\n      pow = 1ll * pow *\
    \ pow % p;\n      if (pow == 1) break;\n    }\n    unsigned int b = c;\n    for\
    \ (int i = 0; i < m - j - 1; i++) b = 1ll * b * b % p;\n    m = j;\n    c = 1ll\
    \ * b * b % p;\n    t = 1ll * t * c % p;\n    r = 1ll * r * b % p;\n  }\n}"
  dependsOn:
  - modint/mod-pow.hpp
  isVerificationFile: false
  path: modint/mod-sqrt.hpp
  requiredBy:
  - fps/relaxed.hpp
  - fps/sparse.hpp
  - fps/fps-sqrt.hpp
  timestamp: '2025-10-10 17:35:46+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
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
