---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: fps/formal-power-series.hpp
    title: fps/formal-power-series.hpp
  - icon: ':x:'
    path: fps/multipoint-evaluation.hpp
    title: "\u591A\u70B9\u8A55\u4FA1"
  - icon: ':x:'
    path: modint/multi-inverse.hpp
    title: "\u8907\u6570\u306E\u8981\u7D20\u306E\u9006\u5143\u3092\u4E00\u62EC\u3067\
      \u8A08\u7B97"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/fps/LC_polynomial_interpolation.test.cpp
    title: verify/fps/LC_polynomial_interpolation.test.cpp
  - icon: ':x:'
    path: verify/fps/LC_polynomial_interpolation_on_geometric_sequence.test.cpp
    title: verify/fps/LC_polynomial_interpolation_on_geometric_sequence.test.cpp
  - icon: ':x:'
    path: verify/fps/UNIT_prefix_sum_of_polynomial.test.cpp
    title: verify/fps/UNIT_prefix_sum_of_polynomial.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: docs/fps/polynomial-interpolation.md
    document_title: "\u591A\u9805\u5F0F\u88DC\u9593"
    links: []
  bundledCode: "#line 2 \"fps/formal-power-series.hpp\"\n\ntemplate <class mint>\n\
    struct FormalPowerSeries : vector<mint> {\n  using vector<mint>::vector;\n  using\
    \ FPS = FormalPowerSeries;\n  FormalPowerSeries(const vector<mint>& r) : vector<mint>(r)\
    \ {}\n  FormalPowerSeries(vector<mint>&& r) : vector<mint>(std::move(r)) {}\n\
    \  FPS& operator=(const vector<mint>& r) {\n    vector<mint>::operator=(r);\n\
    \    return *this;\n  }\n  FPS& operator+=(const FPS& r) {\n    if (r.size() >\
    \ this->size()) this->resize(r.size());\n    for (int i = 0; i < (int)r.size();\
    \ i++) (*this)[i] += r[i];\n    return *this;\n  }\n  FPS& operator+=(const mint&\
    \ r) {\n    if (this->empty()) this->resize(1);\n    (*this)[0] += r;\n    return\
    \ *this;\n  }\n  FPS& operator-=(const FPS& r) {\n    if (r.size() > this->size())\
    \ this->resize(r.size());\n    for (int i = 0; i < (int)r.size(); i++) (*this)[i]\
    \ -= r[i];\n    return *this;\n  }\n  FPS& operator-=(const mint& r) {\n    if\
    \ (this->empty()) this->resize(1);\n    (*this)[0] -= r;\n    return *this;\n\
    \  }\n  FPS& operator*=(const mint& v) {\n    for (int k = 0; k < (int)this->size();\
    \ k++) (*this)[k] *= v;\n    return *this;\n  }\n  FPS& operator/=(const FPS&\
    \ r) {\n    if (this->size() < r.size()) {\n      this->clear();\n      return\
    \ *this;\n    }\n    int n = this->size() - r.size() + 1;\n    if ((int)r.size()\
    \ <= 64) {\n      FPS f(*this), g(r);\n      g.shrink();\n      mint coeff = g.at(g.size()\
    \ - 1).inv();\n      for (auto& x : g) x *= coeff;\n      int deg = (int)f.size()\
    \ - (int)g.size() + 1;\n      int gs = g.size();\n      FPS quo(deg);\n      for\
    \ (int i = deg - 1; i >= 0; i--) {\n        quo[i] = f[i + gs - 1];\n        for\
    \ (int j = 0; j < gs; j++) f[i + j] -= quo[i] * g[j];\n      }\n      *this =\
    \ quo * coeff;\n      this->resize(n, mint(0));\n      return *this;\n    }\n\
    \    return *this = ((*this).rev().pre(n) * r.rev().inv(n)).pre(n).rev();\n  }\n\
    \  FPS& operator%=(const FPS& r) {\n    *this -= *this / r * r;\n    shrink();\n\
    \    return *this;\n  }\n  FPS operator+(const FPS& r) const { return FPS(*this)\
    \ += r; }\n  FPS operator+(const mint& v) const { return FPS(*this) += v; }\n\
    \  FPS operator-(const FPS& r) const { return FPS(*this) -= r; }\n  FPS operator-(const\
    \ mint& v) const { return FPS(*this) -= v; }\n  FPS operator*(const FPS& r) const\
    \ { return FPS(*this) *= r; }\n  FPS operator*(const mint& v) const { return FPS(*this)\
    \ *= v; }\n  FPS operator/(const FPS& r) const { return FPS(*this) /= r; }\n \
    \ FPS operator%(const FPS& r) const { return FPS(*this) %= r; }\n  FPS operator-()\
    \ const {\n    FPS ret(this->size());\n    for (int i = 0; i < (int)this->size();\
    \ i++) ret[i] = -(*this)[i];\n    return ret;\n  }\n  void shrink() {\n    while\
    \ (this->size() && this->back() == mint(0)) this->pop_back();\n  }\n  FPS rev()\
    \ const {\n    FPS ret(*this);\n    reverse(begin(ret), end(ret));\n    return\
    \ ret;\n  }\n  FPS dot(FPS r) const {\n    FPS ret(min(this->size(), r.size()));\n\
    \    for (int i = 0; i < (int)ret.size(); i++) ret[i] = (*this)[i] * r[i];\n \
    \   return ret;\n  }\n  FPS pre(int sz) const {\n    return FPS(begin(*this),\
    \ begin(*this) + min((int)this->size(), sz));\n  }\n  FPS operator>>=(int sz)\
    \ {\n    assert(sz >= 0);\n    if ((int)this->size() <= sz) return {};\n    this->erase(this->begin(),\
    \ this->begin() + sz);\n    return *this;\n  }\n  FPS operator>>(int sz) const\
    \ {\n    if ((int)this->size() <= sz) return {};\n    FPS ret(*this);\n    ret.erase(ret.begin(),\
    \ ret.begin() + sz);\n    return ret;\n  }\n  FPS operator<<=(int sz) {\n    assert(sz\
    \ >= 0);\n    this->insert(this->begin(), sz, mint(0));\n    return *this;\n \
    \ }\n  FPS operator<<(int sz) const {\n    FPS ret(*this);\n    ret.insert(ret.begin(),\
    \ sz, mint(0));\n    return ret;\n  }\n  FPS diff() const {\n    const int n =\
    \ (int)this->size();\n    FPS ret(max(0, n - 1));\n    mint one(1), coeff(1);\n\
    \    for (int i = 1; i < n; i++) {\n      ret[i - 1] = (*this)[i] * coeff;\n \
    \     coeff += one;\n    }\n    return ret;\n  }\n  FPS integral() const {\n \
    \   const int n = (int)this->size();\n    FPS ret(n + 1);\n    ret[0] = mint(0);\n\
    \    if (n > 0) ret[1] = mint(1);\n    auto mod = mint::get_mod();\n    for (int\
    \ i = 2; i <= n; i++) ret[i] = (-ret[mod % i]) * (mod / i);\n    for (int i =\
    \ 0; i < n; i++) ret[i + 1] *= (*this)[i];\n    return ret;\n  }\n  mint eval(mint\
    \ x) const {\n    mint r = 0, w = 1;\n    for (auto& v : *this) r += w * v, w\
    \ *= x;\n    return r;\n  }\n  FPS log(int deg = -1) const {\n    assert((*this)[0]\
    \ == mint(1));\n    if (deg == -1) deg = (int)this->size();\n    return (this->diff()\
    \ * this->inv(deg)).pre(deg - 1).integral();\n  }\n  FPS pow(int64_t k, int deg\
    \ = -1) const {\n    const int n = (int)this->size();\n    if (deg == -1) deg\
    \ = n;\n    if (k == 0) {\n      FPS ret(deg);\n      if (deg) ret[0] = 1;\n \
    \     return ret;\n    }\n    for (int i = 0; i < n; i++) {\n      if ((*this)[i]\
    \ != mint(0)) {\n        mint rev = mint(1) / (*this)[i];\n        FPS ret = (((*this\
    \ * rev) >> i).log(deg) * k).exp(deg);\n        ret *= (*this)[i].pow(k);\n  \
    \      ret = (ret << (i * k)).pre(deg);\n        if ((int)ret.size() < deg) ret.resize(deg,\
    \ mint(0));\n        return ret;\n      }\n      if (__int128_t(i + 1) * k >=\
    \ deg) return FPS(deg, mint(0));\n    }\n    return FPS(deg, mint(0));\n  }\n\n\
    \  static void* ntt_ptr;\n  static void set_ntt();\n  FPS& operator*=(const FPS&\
    \ r);\n  FPS middle_product(const FPS& r) const;\n  void ntt();\n  void intt();\n\
    \  void ntt_doubling();\n  static int ntt_root();\n  FPS inv(int deg = -1) const;\n\
    \  FPS exp(int deg = -1) const;\n};\ntemplate <typename mint>\nvoid* FormalPowerSeries<mint>::ntt_ptr\
    \ = nullptr;\n#line 3 \"fps/multipoint-evaluation.hpp\"\n\n// f(x0),f(x1),...\n\
    template <class mint>\nvector<mint> MultipointEvaluation(FormalPowerSeries<mint>\
    \ f, const vector<mint>& x) {\n  using fps = FormalPowerSeries<mint>;\n  int m\
    \ = x.size();\n  if (m == 0) return {};\n  vector<fps> prod(2 * m);\n  for (int\
    \ i = 0; i < m; i++) prod[i + m] = fps{-x[i], 1};\n  for (int i = m - 1; i > 0;\
    \ i--) prod[i] = prod[i * 2] * prod[i * 2 + 1];\n  vector<fps> rem(2 * m);\n \
    \ rem[1] = f % prod[1];\n  for (int i = 2; i < 2 * m; i++) rem[i] = rem[i / 2]\
    \ % prod[i];\n  vector<mint> y(m);\n  for (int i = 0; i < m; i++) y[i] = rem[i\
    \ + m].empty() ? 0 : rem[i + m][0];\n  return y;\n}\n\n// f(a),f(ar),...,f(ar^{n-1})\n\
    template <class mint>\nvector<mint> MultipointEvaluationGeometric(FormalPowerSeries<mint>\
    \ f, mint a, mint r, int n) {\n  using fps = FormalPowerSeries<mint>;\n  assert(n\
    \ >= 0);\n  if (n == 0) return {};\n  if (f.empty()) return vector<mint>(n);\n\
    \  mint pa = 1;\n  for (int i = 1; i < f.size(); i++) f[i] *= (pa *= a);\n  if\
    \ (r == 0) {\n    vector<mint> res(n, f[0]);\n    for (int i = 1; i < f.size();\
    \ i++) res[0] += f[i];\n    return res;\n  }\n  mint ir = r.inv();\n  int sz =\
    \ n - 1 + (int)f.size();\n  fps rs(sz, 1), irs(sz, 1);\n  mint pr = 1, pir = 1;\n\
    \  for (int i = 2; i < sz; i++) {\n    rs[i] = rs[i - 1] * (pr *= r);\n    irs[i]\
    \ = irs[i - 1] * (pir *= ir);\n  }\n  for (int i = 0; i < f.size(); i++) f[i]\
    \ *= irs[i];\n  f = f.middle_product(rs);\n  for (int i = 0; i < f.size(); i++)\
    \ f[i] *= irs[i];\n  return f;\n}\n\n/**\n * @brief \u591A\u70B9\u8A55\u4FA1\n\
    \ * @docs docs/fps/multipoint-evaluation.md\n */\n#line 2 \"modint/multi-inverse.hpp\"\
    \n\ntemplate <class mint>\nvector<mint> MultiInverse(const vector<mint>& a) {\n\
    \  if (a.empty()) return {};\n  vector<mint> b(a.begin(), a.end());\n  for (int\
    \ i = 0; i + 1 < b.size(); i++) b[i + 1] *= b[i];\n  mint c = b.back().inv();\n\
    \  for (int i = a.size() - 1; i > 0; i--) {\n    b[i] = c * b[i - 1];\n    c *=\
    \ a[i];\n  }\n  b[0] = c;\n  return b;\n}\n/**\n * @brief \u8907\u6570\u306E\u8981\
    \u7D20\u306E\u9006\u5143\u3092\u4E00\u62EC\u3067\u8A08\u7B97\n */\n#line 5 \"\
    fps/polynomial-interpolation.hpp\"\n\n// f(x[i])=y[i]\ntemplate <class mint>\n\
    FormalPowerSeries<mint> PolynomialInterpolation(const vector<mint>& x, const vector<mint>&\
    \ y) {\n  using fps = FormalPowerSeries<mint>;\n  assert(x.size() == y.size());\n\
    \  int n = x.size();\n  if (n == 0) return {};\n  vector<fps> prod(2 * n);\n \
    \ for (int i = 0; i < n; i++) prod[i + n] = fps{-x[i], 1};\n  for (int i = n -\
    \ 1; i > 0; i--) prod[i] = prod[i * 2] * prod[i * 2 + 1];\n  vector<fps> fs(2\
    \ * n);\n  fs[1] = prod[1].diff();\n  for (int i = 2; i < 2 * n; i++) fs[i] =\
    \ fs[i / 2] % prod[i];\n  for (int i = n; i < n * 2; i++) fs[i] = fps{y[i - n]\
    \ / fs[i][0]};\n  for (int i = n - 1; i > 0; i--) fs[i] = fs[(i << 1) | 0] * prod[(i\
    \ << 1) | 1] + fs[(i << 1) | 1] * prod[(i << 1) | 0];\n  return fs[1];\n}\n\n\
    // f(ar^i)=y[i]\ntemplate <class mint>\nFormalPowerSeries<mint> PolynomialInterpolationGeometric(mint\
    \ a, mint r, const vector<mint>& y) {\n  using fps = FormalPowerSeries<mint>;\n\
    \  int n = y.size();\n  if (n == 0) return {};\n  if (n == 1) return {y[0]};\n\
    \  assert(a != 0);\n  assert(r != 1);\n  vector<mint> rs(n + 1, 1);\n  for (int\
    \ i = 1; i <= n; i++) rs[i] = rs[i - 1] * r;\n  vector<mint> rs1(n - 1);\n  for\
    \ (int i = 0; i < n - 1; i++) rs1[i] = 1 - rs[i + 1];\n  rs1 = MultiInverse(rs1);\n\
    \  fps f(n, 1);\n  for (int i = 1; i < n; i++) f[i] = f[i - 1] * a * (rs[n] -\
    \ rs[i - 1]) * rs1[i - 1];\n\n  fps g(n, 1);\n  {\n    vector<mint> s(n, 1);\n\
    \    for (int i = 1; i < n; i++) s[i] = s[i - 1] * a * (1 - rs[i]);\n    for (int\
    \ i = 1; i < n; i++) g[i] = -g[i - 1] * rs[n - 1 - i];\n    for (int i = 0; i\
    \ < n; i++) g[i] *= s[i] * s[n - 1 - i];\n    g = MultiInverse(g);\n  }\n  for\
    \ (int i = 0; i < n; i++) g[i] *= y[i];\n  g = MultipointEvaluationGeometric(g,\
    \ mint(1), r, n);\n  mint c = 1;\n  for (int i = 1; i < n; i++) g[i] *= (c *=\
    \ a);\n  f *= g;\n  f.resize(n);\n  reverse(f.begin(), f.end());\n  return f;\n\
    }\n\n/**\n * @brief \u591A\u9805\u5F0F\u88DC\u9593\n * @docs docs/fps/polynomial-interpolation.md\n\
    \ */\n"
  code: "#pragma once\n#include \"fps/formal-power-series.hpp\"\n#include \"fps/multipoint-evaluation.hpp\"\
    \n#include \"modint/multi-inverse.hpp\"\n\n// f(x[i])=y[i]\ntemplate <class mint>\n\
    FormalPowerSeries<mint> PolynomialInterpolation(const vector<mint>& x, const vector<mint>&\
    \ y) {\n  using fps = FormalPowerSeries<mint>;\n  assert(x.size() == y.size());\n\
    \  int n = x.size();\n  if (n == 0) return {};\n  vector<fps> prod(2 * n);\n \
    \ for (int i = 0; i < n; i++) prod[i + n] = fps{-x[i], 1};\n  for (int i = n -\
    \ 1; i > 0; i--) prod[i] = prod[i * 2] * prod[i * 2 + 1];\n  vector<fps> fs(2\
    \ * n);\n  fs[1] = prod[1].diff();\n  for (int i = 2; i < 2 * n; i++) fs[i] =\
    \ fs[i / 2] % prod[i];\n  for (int i = n; i < n * 2; i++) fs[i] = fps{y[i - n]\
    \ / fs[i][0]};\n  for (int i = n - 1; i > 0; i--) fs[i] = fs[(i << 1) | 0] * prod[(i\
    \ << 1) | 1] + fs[(i << 1) | 1] * prod[(i << 1) | 0];\n  return fs[1];\n}\n\n\
    // f(ar^i)=y[i]\ntemplate <class mint>\nFormalPowerSeries<mint> PolynomialInterpolationGeometric(mint\
    \ a, mint r, const vector<mint>& y) {\n  using fps = FormalPowerSeries<mint>;\n\
    \  int n = y.size();\n  if (n == 0) return {};\n  if (n == 1) return {y[0]};\n\
    \  assert(a != 0);\n  assert(r != 1);\n  vector<mint> rs(n + 1, 1);\n  for (int\
    \ i = 1; i <= n; i++) rs[i] = rs[i - 1] * r;\n  vector<mint> rs1(n - 1);\n  for\
    \ (int i = 0; i < n - 1; i++) rs1[i] = 1 - rs[i + 1];\n  rs1 = MultiInverse(rs1);\n\
    \  fps f(n, 1);\n  for (int i = 1; i < n; i++) f[i] = f[i - 1] * a * (rs[n] -\
    \ rs[i - 1]) * rs1[i - 1];\n\n  fps g(n, 1);\n  {\n    vector<mint> s(n, 1);\n\
    \    for (int i = 1; i < n; i++) s[i] = s[i - 1] * a * (1 - rs[i]);\n    for (int\
    \ i = 1; i < n; i++) g[i] = -g[i - 1] * rs[n - 1 - i];\n    for (int i = 0; i\
    \ < n; i++) g[i] *= s[i] * s[n - 1 - i];\n    g = MultiInverse(g);\n  }\n  for\
    \ (int i = 0; i < n; i++) g[i] *= y[i];\n  g = MultipointEvaluationGeometric(g,\
    \ mint(1), r, n);\n  mint c = 1;\n  for (int i = 1; i < n; i++) g[i] *= (c *=\
    \ a);\n  f *= g;\n  f.resize(n);\n  reverse(f.begin(), f.end());\n  return f;\n\
    }\n\n/**\n * @brief \u591A\u9805\u5F0F\u88DC\u9593\n * @docs docs/fps/polynomial-interpolation.md\n\
    \ */"
  dependsOn:
  - fps/formal-power-series.hpp
  - fps/multipoint-evaluation.hpp
  - modint/multi-inverse.hpp
  isVerificationFile: false
  path: fps/polynomial-interpolation.hpp
  requiredBy: []
  timestamp: '2025-10-31 21:54:34+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/fps/LC_polynomial_interpolation_on_geometric_sequence.test.cpp
  - verify/fps/UNIT_prefix_sum_of_polynomial.test.cpp
  - verify/fps/LC_polynomial_interpolation.test.cpp
documentation_of: fps/polynomial-interpolation.hpp
layout: document
redirect_from:
- /library/fps/polynomial-interpolation.hpp
- /library/fps/polynomial-interpolation.hpp.html
title: "\u591A\u9805\u5F0F\u88DC\u9593"
---
高々 $n-1$ 次の多項式 $f$ で $0\leq i\lt n$ に対し $f(x_i)=y_i$ を満たすものを $O(n(\log n)^2)$ 時間で求める．

また評価点が等比級数ならば $O(n\log n)$ 時間で求められる．

## アルゴリズム

$g(x)=\prod_{i=0}^{n-1}(x-x_i)$ とすれば Lagrange 補間より以下が成り立つ．

$$f(x)=\sum_{i=0}^{n-1}\frac{y_ig(x)}{g'(x_i)(x-x_i)}$$

以下のようにして $O(n(\log n)^2)$ 時間で計算できる．

- $g(x)$ は分割統治により $O(n(\log n)^2)$ 時間で計算できる．
- $g'(x_i)$ は多点評価により $O(n(\log n)^2)$ 時間で列挙できる．
- $\sum_{i=0}^{n-1}\frac{y_i}{g'(x_i)(x-x_i)}$ は有理数の和として分割統治により $O(n(\log n)^2)$ 時間で計算できる．

$g(x)$ の計算過程はそれ以降にも流用できる．

## 等比級数の場合

- [https://judge.yosupo.jp/problem/polynomial_interpolation_on_geometric_sequence]
- [https://noshi91.github.io/algorithm-encyclopedia/polynomial-interpolation-geometric#noredirect]

$i=0,\dots,n-1$ について $f(ar^i)$ がわかっているとする．ただし $0\leq i\lt j\lt n$ ならば $ar^i\neq ar^j$．

$f$ は以下のように表示できる．
$$f(x)=\sum_{i=0}^{n-1}y_i\prod_{j\neq i}\frac{x-ar^j}{a(r^i-r^j)}$$

$g(x)=x^{n-1}f(x^{-1})$ とすると $g$ は以下のように表示できる．
$$g(x)=\sum_{i=0}^{n-1}y_i\prod_{j\neq i}\frac{1-ar^jx}{a(r^i-r^j)}$$

分母は以下のように変形できる．
$$\begin{align*}
\prod_{j\neq i}a(r^i-r^j)
&=\prod_{j=0}^{i-1}a(r^i-r^j)\prod_{j=i+1}^{n-1}a(r^i-r^j)\\
&=\prod_{j=1}^{i}r^{i-j}a(r^j-1)\prod_{j=1}^{n-1-i}ar^i(1-r^j)\\
&=(-1)^{i}r^{i(i-1)/2+i(n-1-i)}\prod_{j=1}^{i}a(1-r^j)\prod_{j=1}^{n-1-i}a(1-r^j)
\end{align*}$$

よって $w_i=y_i\prod_{j\neq i}\frac{1}{a(r^i-r^j)}$ は全ての $i$ に対し $O(n)$ 時間で求められるので以下を計算できればよい．
$$g(x)=\sum_{i=0}^{n-1}w_i\prod_{j\neq i}(1-ar^jx)=\left(\prod_{i=0}^{n-1}(1-ar^ix)\right)\left(\sum_{i=0}^{n-1}\frac{w_i}{1-ar^ix}\right)$$

$F(x)=\prod_{i=0}^{n-1}(1-ar^ix)$ とおくと $(1-ax)F(rx)=F(x)(1-ar^nx)$ より $F_i=[x^i]F(x)$ について
$$F_0=1,\quad (1-r^i)F_i=a(r^n-r^{i-1})F_{i-1}$$
が成り立ち，$O(n)$ 時間で $F$ は求められる．

$G(x)=\sum_{i=0}^{n-1}\frac{w_i}{1-ar^ix}$ とおくと
$$G(x)=\sum_{i=0}^{n-1}\sum_{j=0}^{\infty}w_i(ar^ix)^j=\sum_{j=0}^{\infty}a^j\left(\sum_{i=0}^{n-1}w_ir^{ij}\right)x^j$$
である．$G$ は $n-1$ 次まで求められればよいので，多項式 $\sum_{i=0}^{n-1}w_ix^i$ を $x=r^0,r^1,\dots,r^{n-1}$ で多点評価すればよい．