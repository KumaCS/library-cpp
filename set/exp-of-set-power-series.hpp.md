---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: set/subset-convolution.hpp
    title: Subset Convolution
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/set/LC_exp_of_set_power_series.test.cpp
    title: verify/set/LC_exp_of_set_power_series.test.cpp
  - icon: ':x:'
    path: verify/set/UNIT_composite_set_power_series.test.cpp
    title: verify/set/UNIT_composite_set_power_series.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: Exp Of Set Power Series
    links: []
  bundledCode: "#line 2 \"set/subset-convolution.hpp\"\n\ntemplate <class mint, int\
    \ n_>\nstruct SubsetConvolution {\n  static constexpr int n = n_;\n  using poly\
    \ = array<mint, n_ + 1>;\n  vector<int> pc;\n  SubsetConvolution() {\n    pc.assign(1\
    \ << n, 0);\n    for (int i = 1; i < pc.size(); i++) pc[i] = pc[i >> 1] + (i &\
    \ 1);\n  }\n  void poly_add(poly& p, const poly& q, int d) {\n    for (int i =\
    \ 0; i < d; i++) p[i] += q[i];\n  }\n  void poly_sub(poly& p, const poly& q, int\
    \ d) {\n    for (int i = d; i <= n; i++) p[i] -= q[i];\n  }\n  void poly_mul(poly&\
    \ p, const poly& q) {\n    poly r{};\n    for (int i = 0; i <= n; i++)\n     \
    \ for (int j = 0; j <= n - i; j++)\n        r[i + j] += p[i] * q[j];\n    swap(p,\
    \ r);\n  }\n  vector<poly> lift(const vector<mint>& a) {\n    int n = a.size();\n\
    \    assert(n == (n & -n));\n    vector<poly> b(n);\n    for (int i = 0; i < n;\
    \ i++) {\n      b[i].fill(0);\n      b[i][pc[i]] = a[i];\n    }\n    return b;\n\
    \  }\n  vector<mint> unlift(const vector<poly>& b) {\n    int n = b.size();\n\
    \    assert(n == (n & -n));\n    vector<mint> a(n);\n    for (int i = 0; i < n;\
    \ i++) a[i] = b[i][pc[i]];\n    return a;\n  }\n  void ranked_zeta(vector<poly>&\
    \ a) {\n    int n = a.size();\n    for (int i = 1; i < n; i <<= 1)\n      for\
    \ (int j = 0; j < n; j += i * 2)\n        for (int k = 0; k < i; k++)\n      \
    \    poly_add(a[i + j + k], a[j + k], pc[i + j + k]);\n  }\n  void ranked_mobius(vector<poly>&\
    \ a) {\n    int n = a.size();\n    for (int i = 1; i < n; i <<= 1)\n      for\
    \ (int j = 0; j < n; j += i * 2)\n        for (int k = 0; k < i; k++)\n      \
    \    poly_sub(a[i + j + k], a[j + k], pc[i + j + k]);\n  }\n  void ranked_mul(vector<poly>&\
    \ a, const vector<poly>& b) {\n    for (int i = 0; i < a.size(); i++) poly_mul(a[i],\
    \ b[i]);\n  }\n  vector<mint> multiply(const vector<mint>& a, const vector<mint>&\
    \ b) {\n    auto p = lift(a);\n    auto q = lift(b);\n    ranked_zeta(p);\n  \
    \  ranked_zeta(q);\n    ranked_mul(p, q);\n    ranked_mobius(p);\n    return unlift(p);\n\
    \  }\n};\n\n/**\n * @brief Subset Convolution\n * @docs docs/set/subset-convolution.md\n\
    \ */\n#line 3 \"set/exp-of-set-power-series.hpp\"\n\nnamespace SetPowerSeries\
    \ {\ntemplate <class mint, int sz = 21>\nvector<mint> exp(const vector<mint>&\
    \ a) {\n  static SubsetConvolution<mint, sz> sc;\n  assert(a[0] == 0);\n  int\
    \ l = __builtin_ctz(a.size());\n  assert(a.size() == (1 << l));\n\n  vector<mint>\
    \ f(1 << l, 0);\n  f[0] = 1;\n  for (int k = 0; k < l; k++) {\n    vector<mint>\
    \ g(f.begin(), f.begin() + (1 << k));\n    vector<mint> h(a.begin() + (1 << k),\
    \ a.begin() + (2 << k));\n    g = sc.multiply(g, h);\n    copy(g.begin(), g.end(),\
    \ f.begin() + (1 << k));\n  }\n  return f;\n}\n};  // namespace SetPowerSeries\n\
    /**\n * @brief Exp Of Set Power Series\n */\n"
  code: "#pragma once\n#include \"set/subset-convolution.hpp\"\n\nnamespace SetPowerSeries\
    \ {\ntemplate <class mint, int sz = 21>\nvector<mint> exp(const vector<mint>&\
    \ a) {\n  static SubsetConvolution<mint, sz> sc;\n  assert(a[0] == 0);\n  int\
    \ l = __builtin_ctz(a.size());\n  assert(a.size() == (1 << l));\n\n  vector<mint>\
    \ f(1 << l, 0);\n  f[0] = 1;\n  for (int k = 0; k < l; k++) {\n    vector<mint>\
    \ g(f.begin(), f.begin() + (1 << k));\n    vector<mint> h(a.begin() + (1 << k),\
    \ a.begin() + (2 << k));\n    g = sc.multiply(g, h);\n    copy(g.begin(), g.end(),\
    \ f.begin() + (1 << k));\n  }\n  return f;\n}\n};  // namespace SetPowerSeries\n\
    /**\n * @brief Exp Of Set Power Series\n */"
  dependsOn:
  - set/subset-convolution.hpp
  isVerificationFile: false
  path: set/exp-of-set-power-series.hpp
  requiredBy: []
  timestamp: '2025-10-29 02:30:28+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/set/UNIT_composite_set_power_series.test.cpp
  - verify/set/LC_exp_of_set_power_series.test.cpp
documentation_of: set/exp-of-set-power-series.hpp
layout: document
redirect_from:
- /library/set/exp-of-set-power-series.hpp
- /library/set/exp-of-set-power-series.hpp.html
title: Exp Of Set Power Series
---
