---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: modint/factorial.hpp
    title: "\u968E\u4E57, \u4E8C\u9805\u4FC2\u6570"
  _extendedRequiredBy:
  - icon: ':x:'
    path: fps/sum-of-exp-poly.hpp
    title: $\sum_{i}r^i poly(i)$
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/fps/LC_sum_of_exponential_times_polynomial.test.cpp
    title: verify/fps/LC_sum_of_exponential_times_polynomial.test.cpp
  - icon: ':x:'
    path: verify/fps/LC_sum_of_exponential_times_polynomial_limit.test.cpp
    title: verify/fps/LC_sum_of_exponential_times_polynomial_limit.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: docs/fps/interpolate.md
    document_title: Interpolate
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
    \ \u4E8C\u9805\u4FC2\u6570\n */\n#line 3 \"fps/interpolate.hpp\"\n\n// f(0),f(1),...,f(n-1)\
    \ -> f(x)\ntemplate <class mint>\nmint Interpolate(const vector<mint>& f, mint\
    \ x) {\n  int n = f.size();\n  vector<mint> l(n, 1), r(n, 1);\n  for (int i =\
    \ 0; i + 1 < n; i++) l[i + 1] = l[i] * (x - i);\n  for (int i = n - 1; i > 0;\
    \ i--) r[i - 1] = r[i] * (x - i);\n  using fact = Factorial<mint>;\n  mint s =\
    \ 0;\n  for (int i = 0; i < n; i++) {\n    mint v = f[i] * l[i] * r[i] * fact::fact_inv(i)\
    \ * fact::fact_inv(n - 1 - i);\n    if ((n - i) & 1)\n      s += v;\n    else\n\
    \      s -= v;\n  }\n  return s;\n}\n/**\n * @brief Interpolate\n * @docs docs/fps/interpolate.md\n\
    \ */\n"
  code: "#pragma once\n#include \"modint/factorial.hpp\"\n\n// f(0),f(1),...,f(n-1)\
    \ -> f(x)\ntemplate <class mint>\nmint Interpolate(const vector<mint>& f, mint\
    \ x) {\n  int n = f.size();\n  vector<mint> l(n, 1), r(n, 1);\n  for (int i =\
    \ 0; i + 1 < n; i++) l[i + 1] = l[i] * (x - i);\n  for (int i = n - 1; i > 0;\
    \ i--) r[i - 1] = r[i] * (x - i);\n  using fact = Factorial<mint>;\n  mint s =\
    \ 0;\n  for (int i = 0; i < n; i++) {\n    mint v = f[i] * l[i] * r[i] * fact::fact_inv(i)\
    \ * fact::fact_inv(n - 1 - i);\n    if ((n - i) & 1)\n      s += v;\n    else\n\
    \      s -= v;\n  }\n  return s;\n}\n/**\n * @brief Interpolate\n * @docs docs/fps/interpolate.md\n\
    \ */"
  dependsOn:
  - modint/factorial.hpp
  isVerificationFile: false
  path: fps/interpolate.hpp
  requiredBy:
  - fps/sum-of-exp-poly.hpp
  timestamp: '2025-10-21 21:13:36+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/fps/LC_sum_of_exponential_times_polynomial.test.cpp
  - verify/fps/LC_sum_of_exponential_times_polynomial_limit.test.cpp
documentation_of: fps/interpolate.hpp
layout: document
redirect_from:
- /library/fps/interpolate.hpp
- /library/fps/interpolate.hpp.html
title: Interpolate
---
Lagrange 補間．

$f$ が $N-1$ 次であると仮定し，$f(0),f(1),\dots,f(N-1)$ の値から $f(x)$ の値を求める．

$O(N)$ 時間．