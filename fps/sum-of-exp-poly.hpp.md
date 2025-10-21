---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: fps/interpolate.hpp
    title: Interpolate
  - icon: ':question:'
    path: modint/factorial.hpp
    title: "\u968E\u4E57, \u4E8C\u9805\u4FC2\u6570"
  _extendedRequiredBy: []
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
    _deprecated_at_docs: docs/fps/sum-of-exp-poly.md
    document_title: $\sum_{i}r^i poly(i)$
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
    \ */\n#line 4 \"fps/sum-of-exp-poly.hpp\"\n\n// sum_{i=0}^{infty}r^i*poly(i)\n\
    // f[i]=poly(i)\ntemplate <class mint>\nmint SumOfExpPolyLimit(mint r, vector<mint>&\
    \ f) {\n  if (r == 0) return f[0];\n  assert(r != 1);\n  int k = f.size();\n \
    \ vector<mint> g(k + 1, 0);\n  mint prod = 1;\n  for (int i = 0; i < k; i++) {\n\
    \    g[i + 1] = g[i] + f[i] * prod;\n    prod *= r;\n  }\n  using fact = Factorial<mint>;\n\
    \  mint c = 0;\n  prod = 1;\n  for (int i = 0; i <= k; i++) {\n    c += fact::binom(k,\
    \ i) * prod * g[k - i];\n    prod *= -r;\n  }\n  c /= (1 - r).pow(k);\n  return\
    \ c;\n}\n// sum_{i=0}^{n-1}r^i*poly(i)\n// f[i]=poly(i)\ntemplate <class mint>\n\
    mint SumOfExpPoly(long long n, mint r, vector<mint>& f) {\n  if (n <= 0) return\
    \ 0;\n  if (r == 0) return f[0];\n  int k = f.size();\n  vector<mint> g(k + 1,\
    \ 0);\n  mint prod = 1;\n  for (int i = 0; i < k; i++) {\n    g[i + 1] = g[i]\
    \ + f[i] * prod;\n    prod *= r;\n  }\n  if (r == 1) return Interpolate(g, mint(n));\n\
    \  mint c = 0;\n  prod = 1;\n  using fact = Factorial<mint>;\n  for (int i = 0;\
    \ i <= k; i++) {\n    c += fact::binom(k, i) * prod * g[k - i];\n    prod *= -r;\n\
    \  }\n  c /= (1 - r).pow(k);\n  for (int i = 0; i <= k; i++) g[i] -= c;\n  mint\
    \ ir = r.inv();\n  prod = 1;\n  for (int i = 1; i <= k; i++) g[i] *= (prod *=\
    \ ir);\n  return Interpolate(g, mint(n)) * r.pow(n) + c;\n}\n/**\n * @brief $\\\
    sum_{i}r^i poly(i)$\n * @docs docs/fps/sum-of-exp-poly.md\n */\n"
  code: "#pragma once\n#include \"fps/interpolate.hpp\"\n#include \"modint/factorial.hpp\"\
    \n\n// sum_{i=0}^{infty}r^i*poly(i)\n// f[i]=poly(i)\ntemplate <class mint>\n\
    mint SumOfExpPolyLimit(mint r, vector<mint>& f) {\n  if (r == 0) return f[0];\n\
    \  assert(r != 1);\n  int k = f.size();\n  vector<mint> g(k + 1, 0);\n  mint prod\
    \ = 1;\n  for (int i = 0; i < k; i++) {\n    g[i + 1] = g[i] + f[i] * prod;\n\
    \    prod *= r;\n  }\n  using fact = Factorial<mint>;\n  mint c = 0;\n  prod =\
    \ 1;\n  for (int i = 0; i <= k; i++) {\n    c += fact::binom(k, i) * prod * g[k\
    \ - i];\n    prod *= -r;\n  }\n  c /= (1 - r).pow(k);\n  return c;\n}\n// sum_{i=0}^{n-1}r^i*poly(i)\n\
    // f[i]=poly(i)\ntemplate <class mint>\nmint SumOfExpPoly(long long n, mint r,\
    \ vector<mint>& f) {\n  if (n <= 0) return 0;\n  if (r == 0) return f[0];\n  int\
    \ k = f.size();\n  vector<mint> g(k + 1, 0);\n  mint prod = 1;\n  for (int i =\
    \ 0; i < k; i++) {\n    g[i + 1] = g[i] + f[i] * prod;\n    prod *= r;\n  }\n\
    \  if (r == 1) return Interpolate(g, mint(n));\n  mint c = 0;\n  prod = 1;\n \
    \ using fact = Factorial<mint>;\n  for (int i = 0; i <= k; i++) {\n    c += fact::binom(k,\
    \ i) * prod * g[k - i];\n    prod *= -r;\n  }\n  c /= (1 - r).pow(k);\n  for (int\
    \ i = 0; i <= k; i++) g[i] -= c;\n  mint ir = r.inv();\n  prod = 1;\n  for (int\
    \ i = 1; i <= k; i++) g[i] *= (prod *= ir);\n  return Interpolate(g, mint(n))\
    \ * r.pow(n) + c;\n}\n/**\n * @brief $\\sum_{i}r^i poly(i)$\n * @docs docs/fps/sum-of-exp-poly.md\n\
    \ */"
  dependsOn:
  - fps/interpolate.hpp
  - modint/factorial.hpp
  isVerificationFile: false
  path: fps/sum-of-exp-poly.hpp
  requiredBy: []
  timestamp: '2025-10-21 21:13:36+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/fps/LC_sum_of_exponential_times_polynomial.test.cpp
  - verify/fps/LC_sum_of_exponential_times_polynomial_limit.test.cpp
documentation_of: fps/sum-of-exp-poly.hpp
layout: document
redirect_from:
- /library/fps/sum-of-exp-poly.hpp
- /library/fps/sum-of-exp-poly.hpp.html
title: $\sum_{i}r^i poly(i)$
---
多項式 $f$ について以下の値を計算する．

- $\sum_{i=0}^{n-1}r^if(i)$
- $\sum_{i=0}^{\infty}r^if(i),\quad|r|\lt 1$
  - 有理数として $|r|\lt 1$ を満たすものが modint で与えられる

$d=\deg f$ とし，$f(0),\dots,f(d)$ が与えられるものとする．

## 仕組み

$r=0$ は自明．

$r=1$ のとき単に Lagrange 補間すればよい．

以下 $r\neq 0,1$ とする．

数列 $\{r^if(i)\}$ は $\dfrac{p(x)}{(1-rx)^{d+1}}$ の形の母関数をもつ．

従って $a_i=\sum_{i=0}^{n-1}r^if(i)$ とすれば $\{a_i\}$ の母関数は
$$\frac{xp(x)}{(1-rx)^{d+1}(1-x)}=\frac{q(x)}{(1-rx)^{d+1}}+\frac{c}{1-x}$$
と部分分数分解できる．
$q(x)$ は高々 $d$ 次であるから，両辺に $(1-rx)^{d+1}$ を掛けて $x^{d+1}$ の係数を考えれば次のように $c$ が求められる．
$$c=(1-r)^{-(d+1)}\sum_{i=0}^{d+1}\binom{d+1}{i}(-r)^{d+1-i}a_i$$

また $\frac{q(x)}{(1-rx)^{d+1}}$ は $\{a_i-c\}$ の母関数であるが，この母関数から得られる数列は $r$ の冪と多項式の和の形であるから Lagrange 補間で求められる．

無限和のとき $\{a_i-c\}$ は $0$ に収束するので求める値は単に $c$ である．