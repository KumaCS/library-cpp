---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: set/subset-convolution.hpp
    title: Subset Convolution
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/set/LC_power_projection_of_set_power_series.test.cpp
    title: verify/set/LC_power_projection_of_set_power_series.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: docs/set/power-projection-of-set-power-series.md
    document_title: Power Projection Of Set Power Series
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
    \ */\n#line 3 \"set/power-projection-of-set-power-series.hpp\"\n\nnamespace SetPowerSeries\
    \ {\ntemplate <class mint, int sz = 21>\nvector<mint> power_projection(const vector<mint>&\
    \ a, const vector<mint>& w, int m) {\n  static SubsetConvolution<mint, sz> sc;\n\
    \  int l = __builtin_ctz(a.size());\n  assert(a.size() == (1 << l));\n  mint c\
    \ = a[0];\n  vector<vector<mint>> g(l + 1);\n  g[0] = w;\n  for (int i = 1; i\
    \ <= l; i++) g[i] = vector<mint>(1 << (l - i), 0);\n  for (int k = l - 1; k >=\
    \ 0; k--) {\n    auto p = sc.lift(vector<mint>(a.begin() + (1 << k), a.begin()\
    \ + (2 << k)));\n    sc.ranked_zeta(p);\n    for (int i = 0; i < l - k; i++) {\n\
    \      auto h = vector<mint>(g[i].begin() + (1 << k), g[i].begin() + (2 << k));\n\
    \      reverse(h.begin(), h.end());\n      auto q = sc.lift(h);\n      sc.ranked_zeta(q);\n\
    \      sc.ranked_mul(q, p);\n      sc.ranked_mobius(q);\n      h = sc.unlift(q);\n\
    \      reverse(h.begin(), h.end());\n      for (int j = 0; j < h.size(); j++)\
    \ g[i + 1][j] += h[j];\n    }\n  }\n  vector<mint> f1(l + 1, 1);\n  for (int i\
    \ = 1; i <= l; i++) f1[i] = f1[i - 1] * i;\n  for (int i = 0; i <= l; i++) f1[i]\
    \ *= g[i][0];\n  vector<mint> f(m, 0), binom(l + 1, 0);\n  binom[0] = 1;\n  mint\
    \ r0 = 1;\n  for (int i = 0; i < m; i++) {\n    if (i > l) r0 *= c;\n    mint\
    \ r = r0;\n    for (int j = min(i, l); j >= 0; j--, r *= c) f[i] += f1[j] * binom[j]\
    \ * r;\n    for (int j = l; j > 0; j--) binom[j] += binom[j - 1];\n  }\n  return\
    \ f;\n}\n};  // namespace SetPowerSeries\n/**\n * @brief Power Projection Of Set\
    \ Power Series\n * @docs docs/set/power-projection-of-set-power-series.md\n */\n"
  code: "#pragma once\n#include \"set/subset-convolution.hpp\"\n\nnamespace SetPowerSeries\
    \ {\ntemplate <class mint, int sz = 21>\nvector<mint> power_projection(const vector<mint>&\
    \ a, const vector<mint>& w, int m) {\n  static SubsetConvolution<mint, sz> sc;\n\
    \  int l = __builtin_ctz(a.size());\n  assert(a.size() == (1 << l));\n  mint c\
    \ = a[0];\n  vector<vector<mint>> g(l + 1);\n  g[0] = w;\n  for (int i = 1; i\
    \ <= l; i++) g[i] = vector<mint>(1 << (l - i), 0);\n  for (int k = l - 1; k >=\
    \ 0; k--) {\n    auto p = sc.lift(vector<mint>(a.begin() + (1 << k), a.begin()\
    \ + (2 << k)));\n    sc.ranked_zeta(p);\n    for (int i = 0; i < l - k; i++) {\n\
    \      auto h = vector<mint>(g[i].begin() + (1 << k), g[i].begin() + (2 << k));\n\
    \      reverse(h.begin(), h.end());\n      auto q = sc.lift(h);\n      sc.ranked_zeta(q);\n\
    \      sc.ranked_mul(q, p);\n      sc.ranked_mobius(q);\n      h = sc.unlift(q);\n\
    \      reverse(h.begin(), h.end());\n      for (int j = 0; j < h.size(); j++)\
    \ g[i + 1][j] += h[j];\n    }\n  }\n  vector<mint> f1(l + 1, 1);\n  for (int i\
    \ = 1; i <= l; i++) f1[i] = f1[i - 1] * i;\n  for (int i = 0; i <= l; i++) f1[i]\
    \ *= g[i][0];\n  vector<mint> f(m, 0), binom(l + 1, 0);\n  binom[0] = 1;\n  mint\
    \ r0 = 1;\n  for (int i = 0; i < m; i++) {\n    if (i > l) r0 *= c;\n    mint\
    \ r = r0;\n    for (int j = min(i, l); j >= 0; j--, r *= c) f[i] += f1[j] * binom[j]\
    \ * r;\n    for (int j = l; j > 0; j--) binom[j] += binom[j - 1];\n  }\n  return\
    \ f;\n}\n};  // namespace SetPowerSeries\n/**\n * @brief Power Projection Of Set\
    \ Power Series\n * @docs docs/set/power-projection-of-set-power-series.md\n */"
  dependsOn:
  - set/subset-convolution.hpp
  isVerificationFile: false
  path: set/power-projection-of-set-power-series.hpp
  requiredBy: []
  timestamp: '2025-10-31 21:40:36+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/set/LC_power_projection_of_set_power_series.test.cpp
documentation_of: set/power-projection-of-set-power-series.hpp
layout: document
redirect_from:
- /library/set/power-projection-of-set-power-series.hpp
- /library/set/power-projection-of-set-power-series.hpp.html
title: Power Projection Of Set Power Series
---
$a$ を集合冪級数とする．
$\sum_{s}w_s[x^s]a^i$ を $i=0,\dots,M-1$ について列挙する．

$O(N^22^N+NM)$ 時間．

- [https://maspypy.com/%e9%9b%86%e5%90%88%e3%81%b9%e3%81%8d%e7%b4%9a%e6%95%b0%e9%96%a2%e9%80%a3-3-%e5%a4%9a%e9%a0%85%e5%bc%8f%e3%81%a8%e3%81%ae%e5%90%88%e6%88%90%e3%81%ae%e8%bb%a2%e7%bd%ae]

## 導入

$a$ を fix したとき，合成 $f(a)$ の計算は $\sum_{i}f_i[x^s]a^i$ の $s$ についての列挙．

この転置問題は $\sum_{s}w_s[x^s]a^i$ の $i$ についての列挙．

多項式 $f$ との合成は以下の要領で計算していた．

- $g(x)=f(x+c)$ とする
- $g$ を EGF にする
- $g$ と $a-c$ を合成する

$g(x)=f(x+c)$ のとき $g_i=\sum_{j\geq i}\binom{j}{i}c^{j-i}f_j$ である．この転置は難しくない．

また $g$ を EGF にするには $x^k$ の係数を $k!$ 倍すればよいので，特に転置は同じものである．

$[x^0]a=0$ のときの EGF との合成の転置を考える．
subset convolution $a\star b$ は $b$ を固定すれば $a$ について線形写像．
その転置アルゴリズムは $a\star b=\operatorname{rev}(\operatorname{rev}(a)\star b)$ である．
