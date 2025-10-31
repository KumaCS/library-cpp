---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: set/subset-convolution.hpp
    title: Subset Convolution
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/set/LC_polynomial_composite_set_power_series.test.cpp
    title: verify/set/LC_polynomial_composite_set_power_series.test.cpp
  - icon: ':x:'
    path: verify/set/UNIT_composite_set_power_series.test.cpp
    title: verify/set/UNIT_composite_set_power_series.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: docs/set/composite-set-power-series.md
    document_title: Polynomial Composite Set Power Series
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
    \ */\n#line 3 \"set/composite-set-power-series.hpp\"\n\nnamespace SetPowerSeries\
    \ {\ntemplate <class mint, int sz = 21>\nvector<mint> composite_egf(vector<mint>\
    \ f, vector<mint> a) {\n  static SubsetConvolution<mint, sz> sc;\n  assert(a[0]\
    \ == 0);\n  if (f.empty()) return vector<mint>(a.size());\n  int l = __builtin_ctz(a.size());\n\
    \  f.resize(l + 1);\n  vector<vector<mint>> g(l + 1);\n  for (int i = 0; i <=\
    \ l; i++) g[i] = vector<mint>(1 << (l - i), 0);\n  for (int i = 0; i <= l; i++)\
    \ g[i][0] = f[i];\n  for (int k = 0; k < l; k++) {\n    auto p = sc.lift(vector<mint>(a.begin()\
    \ + (1 << k), a.begin() + (2 << k)));\n    sc.ranked_zeta(p);\n    for (int i\
    \ = 0; i < l - k; i++) {\n      auto q = sc.lift(vector<mint>(g[i + 1].begin(),\
    \ g[i + 1].begin() + (1 << k)));\n      sc.ranked_zeta(q);\n      sc.ranked_mul(q,\
    \ p);\n      sc.ranked_mobius(q);\n      auto h = sc.unlift(q);\n      copy(h.begin(),\
    \ h.end(), g[i].begin() + (1 << k));\n    }\n  }\n  return g[0];\n}\ntemplate\
    \ <class mint, int sz = 21>\nvector<mint> composite_polynomial(vector<mint> p,\
    \ vector<mint> a) {\n  if (p.empty()) return vector<mint>(a.size());\n  int l\
    \ = __builtin_ctz(a.size());\n  if (a[0] != 0) {\n    mint c = a[0];\n    a[0]\
    \ = 0;\n    vector<mint> p1(l + 1, 0), binom(l + 1, 0);\n    binom[0] = 1;\n \
    \   mint r0 = 1;\n    for (int i = 0; i < p.size(); i++) {\n      if (i > l) r0\
    \ *= c;\n      mint r = r0;\n      for (int j = min(i, l); j >= 0; j--, r *= c)\
    \ p1[j] += p[i] * binom[j] * r;\n      for (int j = l; j > 0; j--) binom[j] +=\
    \ binom[j - 1];\n    }\n    swap(p, p1);\n  }\n  mint r = 1;\n  for (int i = 1;\
    \ i <= l; i++) p[i] *= (r *= i);\n  return composite_egf<mint, sz>(p, a);\n}\n\
    \n// log(a), [x^0]a=1\n// require inverse of 1,...,sz\ntemplate <class mint, int\
    \ sz = 21>\nvector<mint> log(vector<mint> a) {\n  static SubsetConvolution<mint,\
    \ sz> sc;\n  assert(a[0] == 1);\n  int l = __builtin_ctz(a.size());\n  if (l ==\
    \ 0) return {0};\n  vector<mint> inv(l + 1, 1);\n  rep(i, 1, l + 1) inv[i] = mint(i).inv();\n\
    \  auto p = sc.lift(a);\n  sc.ranked_zeta(p);\n  for (int k = 0; k < p.size();\
    \ k++) {\n    auto q = p[k];\n    p[k][0] = 0;\n    for (int i = 1; i <= l; i++)\
    \ {\n      mint v = i * q[i];\n      for (int j = 1; j < i; j++) v -= j * p[k][j]\
    \ * q[i - j];\n      p[k][i] = v * inv[i];\n    }\n  }\n  sc.ranked_mobius(p);\n\
    \  return sc.unlift(p);\n}\n// log(a), [x^0]a=1\n// not require inverse of 1,...,sz\n\
    template <class mint, int sz = 21>\nvector<mint> log_arbitrary(vector<mint> a)\
    \ {\n  assert(a[0] == 1);\n  int l = __builtin_ctz(a.size());\n  if (l == 0) return\
    \ {0};\n  a[0] = 0;\n  vector<mint> f(l + 1, 0);\n  f[1] = 1;\n  for (int i =\
    \ 2; i <= l; i++) f[i] = f[i - 1] * (1 - i);\n  return composite_egf<mint, sz>(f,\
    \ a);\n}\n// a^m, [x^0]a=1\n// require inverse of 1,...,sz\ntemplate <class mint,\
    \ int sz = 21>\nvector<mint> pow(vector<mint> a, mint m) {\n  static SubsetConvolution<mint,\
    \ sz> sc;\n  assert(a[0] == 1);\n  int l = __builtin_ctz(a.size());\n  if (l ==\
    \ 0) return {1};\n  vector<mint> inv(l + 1, 1);\n  rep(i, 1, l + 1) inv[i] = mint(i).inv();\n\
    \  auto p = sc.lift(a);\n  sc.ranked_zeta(p);\n  for (int k = 0; k < p.size();\
    \ k++) {\n    auto q = p[k];\n    p[k][0] = 1;\n    for (int i = 1; i <= l; i++)\
    \ {\n      mint v = 0;\n      for (int j = 1; j < i; j++) v += (m * j - (i - j))\
    \ * p[k][i - j] * q[j];\n      v *= inv[i];\n      v += m * p[k][0] * q[i];\n\
    \      p[k][i] = v;\n    }\n  }\n  sc.ranked_mobius(p);\n  return sc.unlift(p);\n\
    }\n// a^m, [x^0]a=1\n// not require inverse of 1,...,sz\ntemplate <class mint,\
    \ int sz = 21>\nvector<mint> pow_arbitrary(vector<mint> a, mint m) {\n  assert(a[0]\
    \ == 1);\n  int l = __builtin_ctz(a.size());\n  if (l == 0) return {1};\n  a[0]\
    \ = 0;\n  vector<mint> f(l + 1, 0);\n  f[0] = 1;\n  for (int i = 1; i <= l; i++)\
    \ {\n    f[i] = f[i - 1] * m;\n    m -= 1;\n  }\n  return composite_egf<mint,\
    \ sz>(f, a);\n}\n};  // namespace SetPowerSeries\n/**\n * @brief Polynomial Composite\
    \ Set Power Series\n * @docs docs/set/composite-set-power-series.md\n */\n"
  code: "#pragma once\n#include \"set/subset-convolution.hpp\"\n\nnamespace SetPowerSeries\
    \ {\ntemplate <class mint, int sz = 21>\nvector<mint> composite_egf(vector<mint>\
    \ f, vector<mint> a) {\n  static SubsetConvolution<mint, sz> sc;\n  assert(a[0]\
    \ == 0);\n  if (f.empty()) return vector<mint>(a.size());\n  int l = __builtin_ctz(a.size());\n\
    \  f.resize(l + 1);\n  vector<vector<mint>> g(l + 1);\n  for (int i = 0; i <=\
    \ l; i++) g[i] = vector<mint>(1 << (l - i), 0);\n  for (int i = 0; i <= l; i++)\
    \ g[i][0] = f[i];\n  for (int k = 0; k < l; k++) {\n    auto p = sc.lift(vector<mint>(a.begin()\
    \ + (1 << k), a.begin() + (2 << k)));\n    sc.ranked_zeta(p);\n    for (int i\
    \ = 0; i < l - k; i++) {\n      auto q = sc.lift(vector<mint>(g[i + 1].begin(),\
    \ g[i + 1].begin() + (1 << k)));\n      sc.ranked_zeta(q);\n      sc.ranked_mul(q,\
    \ p);\n      sc.ranked_mobius(q);\n      auto h = sc.unlift(q);\n      copy(h.begin(),\
    \ h.end(), g[i].begin() + (1 << k));\n    }\n  }\n  return g[0];\n}\ntemplate\
    \ <class mint, int sz = 21>\nvector<mint> composite_polynomial(vector<mint> p,\
    \ vector<mint> a) {\n  if (p.empty()) return vector<mint>(a.size());\n  int l\
    \ = __builtin_ctz(a.size());\n  if (a[0] != 0) {\n    mint c = a[0];\n    a[0]\
    \ = 0;\n    vector<mint> p1(l + 1, 0), binom(l + 1, 0);\n    binom[0] = 1;\n \
    \   mint r0 = 1;\n    for (int i = 0; i < p.size(); i++) {\n      if (i > l) r0\
    \ *= c;\n      mint r = r0;\n      for (int j = min(i, l); j >= 0; j--, r *= c)\
    \ p1[j] += p[i] * binom[j] * r;\n      for (int j = l; j > 0; j--) binom[j] +=\
    \ binom[j - 1];\n    }\n    swap(p, p1);\n  }\n  mint r = 1;\n  for (int i = 1;\
    \ i <= l; i++) p[i] *= (r *= i);\n  return composite_egf<mint, sz>(p, a);\n}\n\
    \n// log(a), [x^0]a=1\n// require inverse of 1,...,sz\ntemplate <class mint, int\
    \ sz = 21>\nvector<mint> log(vector<mint> a) {\n  static SubsetConvolution<mint,\
    \ sz> sc;\n  assert(a[0] == 1);\n  int l = __builtin_ctz(a.size());\n  if (l ==\
    \ 0) return {0};\n  vector<mint> inv(l + 1, 1);\n  rep(i, 1, l + 1) inv[i] = mint(i).inv();\n\
    \  auto p = sc.lift(a);\n  sc.ranked_zeta(p);\n  for (int k = 0; k < p.size();\
    \ k++) {\n    auto q = p[k];\n    p[k][0] = 0;\n    for (int i = 1; i <= l; i++)\
    \ {\n      mint v = i * q[i];\n      for (int j = 1; j < i; j++) v -= j * p[k][j]\
    \ * q[i - j];\n      p[k][i] = v * inv[i];\n    }\n  }\n  sc.ranked_mobius(p);\n\
    \  return sc.unlift(p);\n}\n// log(a), [x^0]a=1\n// not require inverse of 1,...,sz\n\
    template <class mint, int sz = 21>\nvector<mint> log_arbitrary(vector<mint> a)\
    \ {\n  assert(a[0] == 1);\n  int l = __builtin_ctz(a.size());\n  if (l == 0) return\
    \ {0};\n  a[0] = 0;\n  vector<mint> f(l + 1, 0);\n  f[1] = 1;\n  for (int i =\
    \ 2; i <= l; i++) f[i] = f[i - 1] * (1 - i);\n  return composite_egf<mint, sz>(f,\
    \ a);\n}\n// a^m, [x^0]a=1\n// require inverse of 1,...,sz\ntemplate <class mint,\
    \ int sz = 21>\nvector<mint> pow(vector<mint> a, mint m) {\n  static SubsetConvolution<mint,\
    \ sz> sc;\n  assert(a[0] == 1);\n  int l = __builtin_ctz(a.size());\n  if (l ==\
    \ 0) return {1};\n  vector<mint> inv(l + 1, 1);\n  rep(i, 1, l + 1) inv[i] = mint(i).inv();\n\
    \  auto p = sc.lift(a);\n  sc.ranked_zeta(p);\n  for (int k = 0; k < p.size();\
    \ k++) {\n    auto q = p[k];\n    p[k][0] = 1;\n    for (int i = 1; i <= l; i++)\
    \ {\n      mint v = 0;\n      for (int j = 1; j < i; j++) v += (m * j - (i - j))\
    \ * p[k][i - j] * q[j];\n      v *= inv[i];\n      v += m * p[k][0] * q[i];\n\
    \      p[k][i] = v;\n    }\n  }\n  sc.ranked_mobius(p);\n  return sc.unlift(p);\n\
    }\n// a^m, [x^0]a=1\n// not require inverse of 1,...,sz\ntemplate <class mint,\
    \ int sz = 21>\nvector<mint> pow_arbitrary(vector<mint> a, mint m) {\n  assert(a[0]\
    \ == 1);\n  int l = __builtin_ctz(a.size());\n  if (l == 0) return {1};\n  a[0]\
    \ = 0;\n  vector<mint> f(l + 1, 0);\n  f[0] = 1;\n  for (int i = 1; i <= l; i++)\
    \ {\n    f[i] = f[i - 1] * m;\n    m -= 1;\n  }\n  return composite_egf<mint,\
    \ sz>(f, a);\n}\n};  // namespace SetPowerSeries\n/**\n * @brief Polynomial Composite\
    \ Set Power Series\n * @docs docs/set/composite-set-power-series.md\n */"
  dependsOn:
  - set/subset-convolution.hpp
  isVerificationFile: false
  path: set/composite-set-power-series.hpp
  requiredBy: []
  timestamp: '2025-10-31 21:40:36+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/set/UNIT_composite_set_power_series.test.cpp
  - verify/set/LC_polynomial_composite_set_power_series.test.cpp
documentation_of: set/composite-set-power-series.hpp
layout: document
redirect_from:
- /library/set/composite-set-power-series.hpp
- /library/set/composite-set-power-series.hpp.html
title: Polynomial Composite Set Power Series
---
多項式 $\sum_{i=0}^{m-1}c_ix^i$，$2^n$ の集合冪級数 $a$ について $\sum_{i=0}^{m-1}c_ia^i$ を $O(n^22^m)$ 時間で計算する．

## EGF との合成

$[x^0]a=0$ のとき EGF $f(x)=\sum_{k\geq 0}f_k\frac{x^k}{k!}$ との合成 $f(a)=\sum_{k\geq 0}f_k\frac{a^k}{k!}$ を考える．

- [https://codeforces.com/blog/entry/92183]

$R[x_1,\dots,x_n]/(x_1^2,\dots,x_n^2)$ の元として考えると $[x_n^1]f(a)=[x_n^0]f'(a)[x_n^1]a$ が成り立つ．

従って $[x_n^0]f'(a)$ から $f(a)$ を得られる．

再帰的に計算すると長さ $2^i$ の subset convolution を $n-i$ 回行うことになり，計算量は $O(n^22^n)$ と評価できる．

## 多項式との合成

$[x^0]a=0$ のとき EGF との合成に帰着される．

$[x^0]a=c\neq 0$ のとき $f(x+c)$ と $a-c$ を合成すればよい．
$f(x+c)$ は $n$ 次まで求めれば十分なので $O(nm)$ 時間で計算できる．


## 別の手法

- [https://atcoder.jp/contests/xmascon20/tasks/xmascon20_h]
- [https://hos-lyric.hatenablog.com/entry/2021/01/14/201231]

ゼータ変換した先の多項式を FPS と合成することでも求められる．

log や pow は定数倍が改善する．