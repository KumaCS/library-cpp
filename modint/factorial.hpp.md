---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: fps/composition.hpp
    title: "FPS \u5408\u6210"
  - icon: ':heavy_check_mark:'
    path: fps/compositional-inv.hpp
    title: "\u9006\u95A2\u6570"
  - icon: ':x:'
    path: fps/count-subset-sum.hpp
    title: Count Subset Sum
  - icon: ':x:'
    path: fps/interpolate.hpp
    title: Interpolate
  - icon: ':heavy_check_mark:'
    path: fps/power-projection.hpp
    title: Power Projection
  - icon: ':x:'
    path: fps/prefix-sum-of-polynomial.hpp
    title: "\u591A\u9805\u5F0F\u306E Prefix Sum"
  - icon: ':question:'
    path: fps/relaxed.hpp
    title: Relaxed
  - icon: ':x:'
    path: fps/sampling-points-shift.hpp
    title: "\u8A55\u4FA1\u70B9\u30B7\u30D5\u30C8"
  - icon: ':question:'
    path: fps/sparse.hpp
    title: "Sparse \u306A FPS \u6F14\u7B97"
  - icon: ':x:'
    path: fps/sum-of-exp-poly.hpp
    title: $\sum_{i}r^i poly(i)$
  - icon: ':question:'
    path: fps/taylor-shift.hpp
    title: Taylor Shift
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/fps/LC_composition_of_formal_power_series.test.cpp
    title: verify/fps/LC_composition_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/fps/LC_composition_of_formal_power_series_large.test.cpp
    title: verify/fps/LC_composition_of_formal_power_series_large.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/fps/LC_compositional_inverse_of_formal_power_series.test.cpp
    title: verify/fps/LC_compositional_inverse_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/fps/LC_compositional_inverse_of_formal_power_series_large.test.cpp
    title: verify/fps/LC_compositional_inverse_of_formal_power_series_large.test.cpp
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
    path: verify/fps/LC_polynomial_taylor_shift.test.cpp
    title: verify/fps/LC_polynomial_taylor_shift.test.cpp
  - icon: ':x:'
    path: verify/fps/LC_pow_of_formal_power_series_sparse.test.cpp
    title: verify/fps/LC_pow_of_formal_power_series_sparse.test.cpp
  - icon: ':x:'
    path: verify/fps/LC_sharp_p_subset_sum.test.cpp
    title: verify/fps/LC_sharp_p_subset_sum.test.cpp
  - icon: ':x:'
    path: verify/fps/LC_shift_of_sampling_points_of_polynomial.test.cpp
    title: verify/fps/LC_shift_of_sampling_points_of_polynomial.test.cpp
  - icon: ':x:'
    path: verify/fps/LC_sqrt_of_formal_power_series.relaxed.test.cpp
    title: verify/fps/LC_sqrt_of_formal_power_series.relaxed.test.cpp
  - icon: ':x:'
    path: verify/fps/LC_sqrt_of_formal_power_series_sparse.test.cpp
    title: verify/fps/LC_sqrt_of_formal_power_series_sparse.test.cpp
  - icon: ':x:'
    path: verify/fps/LC_sum_of_exponential_times_polynomial.test.cpp
    title: verify/fps/LC_sum_of_exponential_times_polynomial.test.cpp
  - icon: ':x:'
    path: verify/fps/LC_sum_of_exponential_times_polynomial_limit.test.cpp
    title: verify/fps/LC_sum_of_exponential_times_polynomial_limit.test.cpp
  - icon: ':x:'
    path: verify/fps/UNIT_prefix_sum_of_polynomial.test.cpp
    title: verify/fps/UNIT_prefix_sum_of_polynomial.test.cpp
  - icon: ':x:'
    path: verify/modint/LC_binomial_coefficient_prime_mod.test.cpp
    title: verify/modint/LC_binomial_coefficient_prime_mod.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    document_title: "\u968E\u4E57, \u4E8C\u9805\u4FC2\u6570"
    links: []
  bundledCode: "#line 2 \"modint/factorial.hpp\"\n\ntemplate <class mint>\nstruct\
    \ Factorial {\n  static void reserve(int n) {\n    inv(n);\n    fact(n);\n   \
    \ fact_inv(n);\n  }\n  static mint inv(int n) {\n    static long long mod = mint::get_mod();\n\
    \    static vector<mint> buf({0, 1});\n    assert(n != 0);\n    if (mod != mint::get_mod())\
    \ {\n      mod = mint::get_mod();\n      buf = vector<mint>({0, 1});\n    }\n\
    \    while ((int)buf.capacity() <= n) buf.reserve(buf.capacity() * 2);\n    while\
    \ ((int)buf.size() <= n) {\n      long long k = buf.size(), q = (mod + k - 1)\
    \ / k;\n      buf.push_back(q * buf[k * q - mod]);\n    }\n    return buf[n];\n\
    \  }\n  static mint fact(int n) {\n    static long long mod = mint::get_mod();\n\
    \    static vector<mint> buf({1, 1});\n    assert(n >= 0);\n    if (mod != mint::get_mod())\
    \ {\n      mod = mint::get_mod();\n      buf = vector<mint>({1, 1});\n    }\n\
    \    while ((int)buf.capacity() <= n) buf.reserve(buf.capacity() * 2);\n    while\
    \ ((int)buf.size() <= n) {\n      long long k = buf.size();\n      buf.push_back(buf.back()\
    \ * k);\n    }\n    return buf[n];\n  }\n  static mint fact_inv(int n) {\n   \
    \ static long long mod = mint::get_mod();\n    static vector<mint> buf({1, 1});\n\
    \    assert(n >= 0);\n    if (mod != mint::get_mod()) {\n      mod = mint::get_mod();\n\
    \      buf = vector<mint>({1, 1});\n    }\n    if ((int)buf.size() <= n) inv(n);\n\
    \    while ((int)buf.capacity() <= n) buf.reserve(buf.capacity() * 2);\n    while\
    \ ((int)buf.size() <= n) {\n      long long k = buf.size();\n      buf.push_back(buf.back()\
    \ * inv(k));\n    }\n    return buf[n];\n  }\n  static mint binom(int n, int r)\
    \ {\n    if (r < 0 || r > n) return 0;\n    return fact(n) * fact_inv(r) * fact_inv(n\
    \ - r);\n  }\n  static mint binom_naive(int n, int r) {\n    if (r < 0 || r >\
    \ n) return 0;\n    mint res = fact_inv(r);\n    for (int i = 0; i < r; i++) res\
    \ *= n - i;\n    return res;\n  }\n  static mint multinom(const vector<int>& r)\
    \ {\n    int n = 0;\n    for (auto& x : r) {\n      if (x < 0) return 0;\n   \
    \   n += x;\n    }\n    mint res = fact(n);\n    for (auto& x : r) res *= fact_inv(x);\n\
    \    return res;\n  }\n  static mint P(int n, int r) {\n    if (r < 0 || r > n)\
    \ return 0;\n    return fact(n) * fact_inv(n - r);\n  }\n  // partition n items\
    \ to r groups (allow empty group)\n  static mint H(int n, int r) {\n    if (n\
    \ < 0 || r < 0) return 0;\n    return r == 0 ? 1 : binom(n + r - 1, r);\n  }\n\
    };\n/**\n * @brief \u968E\u4E57, \u4E8C\u9805\u4FC2\u6570\n */\n"
  code: "#pragma once\n\ntemplate <class mint>\nstruct Factorial {\n  static void\
    \ reserve(int n) {\n    inv(n);\n    fact(n);\n    fact_inv(n);\n  }\n  static\
    \ mint inv(int n) {\n    static long long mod = mint::get_mod();\n    static vector<mint>\
    \ buf({0, 1});\n    assert(n != 0);\n    if (mod != mint::get_mod()) {\n     \
    \ mod = mint::get_mod();\n      buf = vector<mint>({0, 1});\n    }\n    while\
    \ ((int)buf.capacity() <= n) buf.reserve(buf.capacity() * 2);\n    while ((int)buf.size()\
    \ <= n) {\n      long long k = buf.size(), q = (mod + k - 1) / k;\n      buf.push_back(q\
    \ * buf[k * q - mod]);\n    }\n    return buf[n];\n  }\n  static mint fact(int\
    \ n) {\n    static long long mod = mint::get_mod();\n    static vector<mint> buf({1,\
    \ 1});\n    assert(n >= 0);\n    if (mod != mint::get_mod()) {\n      mod = mint::get_mod();\n\
    \      buf = vector<mint>({1, 1});\n    }\n    while ((int)buf.capacity() <= n)\
    \ buf.reserve(buf.capacity() * 2);\n    while ((int)buf.size() <= n) {\n     \
    \ long long k = buf.size();\n      buf.push_back(buf.back() * k);\n    }\n   \
    \ return buf[n];\n  }\n  static mint fact_inv(int n) {\n    static long long mod\
    \ = mint::get_mod();\n    static vector<mint> buf({1, 1});\n    assert(n >= 0);\n\
    \    if (mod != mint::get_mod()) {\n      mod = mint::get_mod();\n      buf =\
    \ vector<mint>({1, 1});\n    }\n    if ((int)buf.size() <= n) inv(n);\n    while\
    \ ((int)buf.capacity() <= n) buf.reserve(buf.capacity() * 2);\n    while ((int)buf.size()\
    \ <= n) {\n      long long k = buf.size();\n      buf.push_back(buf.back() * inv(k));\n\
    \    }\n    return buf[n];\n  }\n  static mint binom(int n, int r) {\n    if (r\
    \ < 0 || r > n) return 0;\n    return fact(n) * fact_inv(r) * fact_inv(n - r);\n\
    \  }\n  static mint binom_naive(int n, int r) {\n    if (r < 0 || r > n) return\
    \ 0;\n    mint res = fact_inv(r);\n    for (int i = 0; i < r; i++) res *= n -\
    \ i;\n    return res;\n  }\n  static mint multinom(const vector<int>& r) {\n \
    \   int n = 0;\n    for (auto& x : r) {\n      if (x < 0) return 0;\n      n +=\
    \ x;\n    }\n    mint res = fact(n);\n    for (auto& x : r) res *= fact_inv(x);\n\
    \    return res;\n  }\n  static mint P(int n, int r) {\n    if (r < 0 || r > n)\
    \ return 0;\n    return fact(n) * fact_inv(n - r);\n  }\n  // partition n items\
    \ to r groups (allow empty group)\n  static mint H(int n, int r) {\n    if (n\
    \ < 0 || r < 0) return 0;\n    return r == 0 ? 1 : binom(n + r - 1, r);\n  }\n\
    };\n/**\n * @brief \u968E\u4E57, \u4E8C\u9805\u4FC2\u6570\n */"
  dependsOn: []
  isVerificationFile: false
  path: modint/factorial.hpp
  requiredBy:
  - fps/power-projection.hpp
  - fps/count-subset-sum.hpp
  - fps/relaxed.hpp
  - fps/composition.hpp
  - fps/sparse.hpp
  - fps/taylor-shift.hpp
  - fps/prefix-sum-of-polynomial.hpp
  - fps/compositional-inv.hpp
  - fps/interpolate.hpp
  - fps/sum-of-exp-poly.hpp
  - fps/sampling-points-shift.hpp
  timestamp: '2025-10-25 18:30:13+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/modint/LC_binomial_coefficient_prime_mod.test.cpp
  - verify/fps/LC_compositional_inverse_of_formal_power_series_large.test.cpp
  - verify/fps/LC_inv_of_formal_power_series.relaxed.test.cpp
  - verify/fps/LC_composition_of_formal_power_series_large.test.cpp
  - verify/fps/LC_inv_of_formal_power_series_sparse.test.cpp
  - verify/fps/LC_convolution_mod.relaxed.test.cpp
  - verify/fps/LC_sqrt_of_formal_power_series_sparse.test.cpp
  - verify/fps/LC_convolution_mod.semirelaxed.test.cpp
  - verify/fps/LC_exp_of_formal_power_series.relaxed.test.cpp
  - verify/fps/UNIT_prefix_sum_of_polynomial.test.cpp
  - verify/fps/LC_log_of_formal_power_series.relaxed.test.cpp
  - verify/fps/LC_polynomial_taylor_shift.test.cpp
  - verify/fps/LC_exp_of_formal_power_series_sparse.test.cpp
  - verify/fps/LC_shift_of_sampling_points_of_polynomial.test.cpp
  - verify/fps/LC_pow_of_formal_power_series_sparse.test.cpp
  - verify/fps/LC_sum_of_exponential_times_polynomial.test.cpp
  - verify/fps/LC_log_of_formal_power_series_sparse.test.cpp
  - verify/fps/LC_sqrt_of_formal_power_series.relaxed.test.cpp
  - verify/fps/LC_sharp_p_subset_sum.test.cpp
  - verify/fps/LC_sum_of_exponential_times_polynomial_limit.test.cpp
  - verify/fps/LC_compositional_inverse_of_formal_power_series.test.cpp
  - verify/fps/LC_composition_of_formal_power_series.test.cpp
documentation_of: modint/factorial.hpp
layout: document
redirect_from:
- /library/modint/factorial.hpp
- /library/modint/factorial.hpp.html
title: "\u968E\u4E57, \u4E8C\u9805\u4FC2\u6570"
---
