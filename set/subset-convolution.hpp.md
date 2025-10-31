---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: set/composite-set-power-series.hpp
    title: Polynomial Composite Set Power Series
  - icon: ':question:'
    path: set/exp-of-set-power-series.hpp
    title: Exp Of Set Power Series
  - icon: ':x:'
    path: set/power-projection-of-set-power-series.hpp
    title: Power Projection Of Set Power Series
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/set/LC_exp_of_set_power_series.test.cpp
    title: verify/set/LC_exp_of_set_power_series.test.cpp
  - icon: ':x:'
    path: verify/set/LC_polynomial_composite_set_power_series.test.cpp
    title: verify/set/LC_polynomial_composite_set_power_series.test.cpp
  - icon: ':x:'
    path: verify/set/LC_power_projection_of_set_power_series.test.cpp
    title: verify/set/LC_power_projection_of_set_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/set/LC_subset_convolution.test.cpp
    title: verify/set/LC_subset_convolution.test.cpp
  - icon: ':x:'
    path: verify/set/UNIT_composite_set_power_series.test.cpp
    title: verify/set/UNIT_composite_set_power_series.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    _deprecated_at_docs: docs/set/subset-convolution.md
    document_title: Subset Convolution
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
    \ */\n"
  code: "#pragma once\n\ntemplate <class mint, int n_>\nstruct SubsetConvolution {\n\
    \  static constexpr int n = n_;\n  using poly = array<mint, n_ + 1>;\n  vector<int>\
    \ pc;\n  SubsetConvolution() {\n    pc.assign(1 << n, 0);\n    for (int i = 1;\
    \ i < pc.size(); i++) pc[i] = pc[i >> 1] + (i & 1);\n  }\n  void poly_add(poly&\
    \ p, const poly& q, int d) {\n    for (int i = 0; i < d; i++) p[i] += q[i];\n\
    \  }\n  void poly_sub(poly& p, const poly& q, int d) {\n    for (int i = d; i\
    \ <= n; i++) p[i] -= q[i];\n  }\n  void poly_mul(poly& p, const poly& q) {\n \
    \   poly r{};\n    for (int i = 0; i <= n; i++)\n      for (int j = 0; j <= n\
    \ - i; j++)\n        r[i + j] += p[i] * q[j];\n    swap(p, r);\n  }\n  vector<poly>\
    \ lift(const vector<mint>& a) {\n    int n = a.size();\n    assert(n == (n & -n));\n\
    \    vector<poly> b(n);\n    for (int i = 0; i < n; i++) {\n      b[i].fill(0);\n\
    \      b[i][pc[i]] = a[i];\n    }\n    return b;\n  }\n  vector<mint> unlift(const\
    \ vector<poly>& b) {\n    int n = b.size();\n    assert(n == (n & -n));\n    vector<mint>\
    \ a(n);\n    for (int i = 0; i < n; i++) a[i] = b[i][pc[i]];\n    return a;\n\
    \  }\n  void ranked_zeta(vector<poly>& a) {\n    int n = a.size();\n    for (int\
    \ i = 1; i < n; i <<= 1)\n      for (int j = 0; j < n; j += i * 2)\n        for\
    \ (int k = 0; k < i; k++)\n          poly_add(a[i + j + k], a[j + k], pc[i + j\
    \ + k]);\n  }\n  void ranked_mobius(vector<poly>& a) {\n    int n = a.size();\n\
    \    for (int i = 1; i < n; i <<= 1)\n      for (int j = 0; j < n; j += i * 2)\n\
    \        for (int k = 0; k < i; k++)\n          poly_sub(a[i + j + k], a[j + k],\
    \ pc[i + j + k]);\n  }\n  void ranked_mul(vector<poly>& a, const vector<poly>&\
    \ b) {\n    for (int i = 0; i < a.size(); i++) poly_mul(a[i], b[i]);\n  }\n  vector<mint>\
    \ multiply(const vector<mint>& a, const vector<mint>& b) {\n    auto p = lift(a);\n\
    \    auto q = lift(b);\n    ranked_zeta(p);\n    ranked_zeta(q);\n    ranked_mul(p,\
    \ q);\n    ranked_mobius(p);\n    return unlift(p);\n  }\n};\n\n/**\n * @brief\
    \ Subset Convolution\n * @docs docs/set/subset-convolution.md\n */"
  dependsOn: []
  isVerificationFile: false
  path: set/subset-convolution.hpp
  requiredBy:
  - set/composite-set-power-series.hpp
  - set/exp-of-set-power-series.hpp
  - set/power-projection-of-set-power-series.hpp
  timestamp: '2025-10-29 02:30:28+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/set/UNIT_composite_set_power_series.test.cpp
  - verify/set/LC_polynomial_composite_set_power_series.test.cpp
  - verify/set/LC_subset_convolution.test.cpp
  - verify/set/LC_exp_of_set_power_series.test.cpp
  - verify/set/LC_power_projection_of_set_power_series.test.cpp
documentation_of: set/subset-convolution.hpp
layout: document
redirect_from:
- /library/set/subset-convolution.hpp
- /library/set/subset-convolution.hpp.html
title: Subset Convolution
---
- [https://nyaannyaan.github.io/library/set-function/subset-convolution.hpp]
- [https://maspypy.com/category/%e9%9b%86%e5%90%88%e3%81%b9%e3%81%8d%e7%b4%9a%e6%95%b0]

$\{0,1,\dots,n-1\}$ の部分集合を $0$ 以上 $2^n$ 未満の整数と対応づけ，整数に対しても集合演算の記号を用いる．

また $S\cap T =\emptyset$ であるとき $S\cup T$ を $S\sqcup T$ とも表す．

$R$ を環とする．

## subset convolution

$(a_0,a_1,\dots,a_{2^n-1}),(b_0,b_1,\dots,b_{2^n-1})\in R^{2^n}$ の **subset convolution** $c\in R^{2^n}$ を以下で定める．

$$c_u=\sum_{s\sqcup t=u}a_sb_t$$

### アルゴリズム

or convolution $\sum_{s\cup t=u}a_sb_t$ はゼータ変換により $O(n2^n)$ 時間で計算できた．

$s\cup t=u$ のとき $s\cap t=\emptyset\iff |s|+|t|=|u|$ であるので変数 $X$ に対し

$$c_u=[X^{|u|}]\sum_{s\cup t=u}(a_sX^{|s|})(b_tX^{|t|})$$

として計算でき，計算量は $n$ 倍になる．

## set power series

$R^{2^n}$ に加算および定数倍は成分ごと，乗算は subset convolution として演算を定めた環を **set power series** と呼ぶ．

- 単位元は $(1,0,\dots,0)$．
- 剰余環 $R[x_0,\dots,x_{n-1}]/(x_0^2,\dots,x_{n-1}^2)$ に同型．

簡便のために列 $(a_0,a_1,\dots,a_{2^n-1})$ を一般の多項式のように $\sum_{i=0}^{2^n-1}a_ix^i$ とも表記する．

## EGF との合成

集合冪級数 $a$ について $\frac{a^k}{k!}$ を以下のように定める．

$$[x^t]\frac{a^k}{k!}=\sum_{\substack{0 \leq s_1 \lt s_2 \lt \cdots \lt s_k \lt 2^n \\ s_i\cap s_j=\emptyset(i\neq j)}}\prod_{i=1}^{k}a_{s_i}$$

$R$ において $\frac{1}{k!}$ が定義されなくてもよい．

$a_0=0$ なる集合冪級数について，EGF $f(x)=\sum_{i\geq 0}f_i\frac{x^i}{i!}$ との合成 $f(a)=\sum_{i\geq 0}f_i\frac{a^i}{i!}$ が定義できる．

詳細は `set/composite-set-power-series.hpp` を参照．

## power projection

$m=0,1,\dots,M$ に対し $\sum_{s}w_s(a^m)_s$ を $O(n^22^n)$ 時間で列挙する．

詳細は `set/power-projection-of-set-power-series.hpp` を参照．

## 数え上げ

### グラフの連結性

グラフについての何らかの条件があるとき

- $f_s$：頂点集合が $s$ の連結な部分グラフで条件を満たすものの個数
- $g_s$：頂点集合が $s$ の部分グラフで条件を満たすものの個数

とすると $\exp f=g, f=\log g$ であるので $g$ が計算できれば $f$ も計算できる．

- [https://atcoder.jp/contests/abc213/tasks/abc213_g]

### 多項式 / FPS との合成

- [https://atcoder.jp/contests/xmascon20/tasks/xmascon20_h]
