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
    path: fps/interpolate.hpp
    title: Interpolate
  - icon: ':heavy_check_mark:'
    path: fps/power-projection.hpp
    title: Power Projection
  - icon: ':x:'
    path: fps/sum-of-exp-poly.hpp
    title: $\sum_{i}r^i poly(i)$
  - icon: ':heavy_check_mark:'
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
    path: verify/fps/LC_polynomial_taylor_shift.test.cpp
    title: verify/fps/LC_polynomial_taylor_shift.test.cpp
  - icon: ':x:'
    path: verify/fps/LC_sum_of_exponential_times_polynomial.test.cpp
    title: verify/fps/LC_sum_of_exponential_times_polynomial.test.cpp
  - icon: ':x:'
    path: verify/fps/LC_sum_of_exponential_times_polynomial_limit.test.cpp
    title: verify/fps/LC_sum_of_exponential_times_polynomial_limit.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    document_title: "\u968E\u4E57, \u4E8C\u9805\u4FC2\u6570"
    links: []
  bundledCode: "#line 2 \"modint/factorial.hpp\"\n\ntemplate <class mint>\nstruct\
    \ Factorial {\n  static mint inv(int n) {\n    static long long mod = mint::get_mod();\n\
    \    static vector<mint> _inv({0, 1});\n    assert(n != 0);\n    if (mod != mint::get_mod())\
    \ {\n      mod = mint::get_mod();\n      _inv = vector<mint>({0, 1});\n    }\n\
    \    while (_inv.size() <= n) {\n      long long k = _inv.size(), q = (mod + k\
    \ - 1) / k;\n      _inv.push_back(q * _inv[k * q - mod]);\n    }\n    return _inv[n];\n\
    \  }\n  static mint fact(int n) {\n    static long long mod = mint::get_mod();\n\
    \    static vector<mint> _fact({1, 1});\n    assert(n >= 0);\n    if (mod != mint::get_mod())\
    \ {\n      mod = mint::get_mod();\n      _fact = vector<mint>({1, 1});\n    }\n\
    \    while (_fact.size() <= n) {\n      long long k = _fact.size();\n      _fact.push_back(_fact.back()\
    \ * k);\n    }\n    return _fact[n];\n  }\n  static mint fact_inv(int n) {\n \
    \   static long long mod = mint::get_mod();\n    static vector<mint> _fact_inv({1,\
    \ 1});\n    assert(n >= 0);\n    if (mod != mint::get_mod()) {\n      mod = mint::get_mod();\n\
    \      _fact_inv = vector<mint>({1, 1});\n    }\n    while (_fact_inv.size() <=\
    \ n) {\n      long long k = _fact_inv.size();\n      _fact_inv.push_back(_fact_inv.back()\
    \ * inv(k));\n    }\n    return _fact_inv[n];\n  }\n  static mint binom(int n,\
    \ int r) {\n    if (r < 0 || r > n) return 0;\n    return fact(n) * fact_inv(r)\
    \ * fact_inv(n - r);\n  }\n  static mint binom_naive(int n, int r) {\n    if (r\
    \ < 0 || r > n) return 0;\n    mint res = fact_inv(r);\n    for (int i = 0; i\
    \ < r; i++) res *= n - i;\n    return res;\n  }\n  static mint multinom(const\
    \ vector<int>& r) {\n    int n = 0;\n    for (auto& x : r) {\n      if (x < 0)\
    \ return 0;\n      n += x;\n    }\n    mint res = fact(n);\n    for (auto& x :\
    \ r) res *= fact_inv(x);\n    return res;\n  }\n  static mint P(int n, int r)\
    \ {\n    if (r < 0 || r > n) return 0;\n    return fact(n) * fact_inv(n - r);\n\
    \  }\n  // partition n items to r groups (allow empty group)\n  static mint H(int\
    \ n, int r) {\n    if (n < 0 || r < 0) return 0;\n    return r == 0 ? 1 : binom(n\
    \ + r - 1, r);\n  }\n};  // namespace Factorial\n/**\n * @brief \u968E\u4E57,\
    \ \u4E8C\u9805\u4FC2\u6570\n */\n"
  code: "#pragma once\n\ntemplate <class mint>\nstruct Factorial {\n  static mint\
    \ inv(int n) {\n    static long long mod = mint::get_mod();\n    static vector<mint>\
    \ _inv({0, 1});\n    assert(n != 0);\n    if (mod != mint::get_mod()) {\n    \
    \  mod = mint::get_mod();\n      _inv = vector<mint>({0, 1});\n    }\n    while\
    \ (_inv.size() <= n) {\n      long long k = _inv.size(), q = (mod + k - 1) / k;\n\
    \      _inv.push_back(q * _inv[k * q - mod]);\n    }\n    return _inv[n];\n  }\n\
    \  static mint fact(int n) {\n    static long long mod = mint::get_mod();\n  \
    \  static vector<mint> _fact({1, 1});\n    assert(n >= 0);\n    if (mod != mint::get_mod())\
    \ {\n      mod = mint::get_mod();\n      _fact = vector<mint>({1, 1});\n    }\n\
    \    while (_fact.size() <= n) {\n      long long k = _fact.size();\n      _fact.push_back(_fact.back()\
    \ * k);\n    }\n    return _fact[n];\n  }\n  static mint fact_inv(int n) {\n \
    \   static long long mod = mint::get_mod();\n    static vector<mint> _fact_inv({1,\
    \ 1});\n    assert(n >= 0);\n    if (mod != mint::get_mod()) {\n      mod = mint::get_mod();\n\
    \      _fact_inv = vector<mint>({1, 1});\n    }\n    while (_fact_inv.size() <=\
    \ n) {\n      long long k = _fact_inv.size();\n      _fact_inv.push_back(_fact_inv.back()\
    \ * inv(k));\n    }\n    return _fact_inv[n];\n  }\n  static mint binom(int n,\
    \ int r) {\n    if (r < 0 || r > n) return 0;\n    return fact(n) * fact_inv(r)\
    \ * fact_inv(n - r);\n  }\n  static mint binom_naive(int n, int r) {\n    if (r\
    \ < 0 || r > n) return 0;\n    mint res = fact_inv(r);\n    for (int i = 0; i\
    \ < r; i++) res *= n - i;\n    return res;\n  }\n  static mint multinom(const\
    \ vector<int>& r) {\n    int n = 0;\n    for (auto& x : r) {\n      if (x < 0)\
    \ return 0;\n      n += x;\n    }\n    mint res = fact(n);\n    for (auto& x :\
    \ r) res *= fact_inv(x);\n    return res;\n  }\n  static mint P(int n, int r)\
    \ {\n    if (r < 0 || r > n) return 0;\n    return fact(n) * fact_inv(n - r);\n\
    \  }\n  // partition n items to r groups (allow empty group)\n  static mint H(int\
    \ n, int r) {\n    if (n < 0 || r < 0) return 0;\n    return r == 0 ? 1 : binom(n\
    \ + r - 1, r);\n  }\n};  // namespace Factorial\n/**\n * @brief \u968E\u4E57,\
    \ \u4E8C\u9805\u4FC2\u6570\n */"
  dependsOn: []
  isVerificationFile: false
  path: modint/factorial.hpp
  requiredBy:
  - fps/power-projection.hpp
  - fps/composition.hpp
  - fps/taylor-shift.hpp
  - fps/compositional-inv.hpp
  - fps/interpolate.hpp
  - fps/sum-of-exp-poly.hpp
  timestamp: '2025-10-21 21:13:36+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/fps/LC_compositional_inverse_of_formal_power_series_large.test.cpp
  - verify/fps/LC_composition_of_formal_power_series_large.test.cpp
  - verify/fps/LC_polynomial_taylor_shift.test.cpp
  - verify/fps/LC_sum_of_exponential_times_polynomial.test.cpp
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
