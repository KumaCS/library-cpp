---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: fps/fps-sqrt.hpp
    title: fps/fps-sqrt.hpp
  - icon: ':heavy_check_mark:'
    path: fps/relaxed.hpp
    title: Relaxed
  - icon: ':heavy_check_mark:'
    path: fps/sparse.hpp
    title: "Sparse \u306A FPS \u6F14\u7B97"
  - icon: ':heavy_check_mark:'
    path: modint/mod-sqrt.hpp
    title: modint/mod-sqrt.hpp
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
  - icon: ':heavy_check_mark:'
    path: verify/fps/LC_log_of_formal_power_series_sparse.test.cpp
    title: verify/fps/LC_log_of_formal_power_series_sparse.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/fps/LC_pow_of_formal_power_series_sparse.test.cpp
    title: verify/fps/LC_pow_of_formal_power_series_sparse.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/fps/LC_sqrt_of_formal_power_series.relaxed.test.cpp
    title: verify/fps/LC_sqrt_of_formal_power_series.relaxed.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/fps/LC_sqrt_of_formal_power_series.test.cpp
    title: verify/fps/LC_sqrt_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/fps/LC_sqrt_of_formal_power_series_sparse.test.cpp
    title: verify/fps/LC_sqrt_of_formal_power_series_sparse.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"modint/mod-pow.hpp\"\n\nunsigned int ModPow(unsigned int\
    \ a, unsigned long long n, unsigned int m) {\n  unsigned long long x = a, y =\
    \ 1;\n  while (n) {\n    if (n & 1) y = y * x % m;\n    x = x * x % m;\n    n\
    \ >>= 1;\n  }\n  return y;\n}\n"
  code: "#pragma once\n\nunsigned int ModPow(unsigned int a, unsigned long long n,\
    \ unsigned int m) {\n  unsigned long long x = a, y = 1;\n  while (n) {\n    if\
    \ (n & 1) y = y * x % m;\n    x = x * x % m;\n    n >>= 1;\n  }\n  return y;\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: modint/mod-pow.hpp
  requiredBy:
  - modint/mod-sqrt.hpp
  - fps/relaxed.hpp
  - fps/sparse.hpp
  - fps/fps-sqrt.hpp
  timestamp: '2025-10-10 17:35:46+09:00'
  verificationStatus: LIBRARY_ALL_AC
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
documentation_of: modint/mod-pow.hpp
layout: document
redirect_from:
- /library/modint/mod-pow.hpp
- /library/modint/mod-pow.hpp.html
title: modint/mod-pow.hpp
---
