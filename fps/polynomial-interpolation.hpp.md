---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: fps/formal-power-series.hpp
    title: fps/formal-power-series.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/fps/LC_polynomial_interpolation.test.cpp
    title: verify/fps/LC_polynomial_interpolation.test.cpp
  - icon: ':x:'
    path: verify/fps/UNIT_prefix_sum_of_polynomial.test.cpp
    title: verify/fps/UNIT_prefix_sum_of_polynomial.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    _deprecated_at_docs: docs/fps/polynomial-interpolation.md
    document_title: "\u591A\u9805\u5F0F\u88DC\u9593"
    links: []
  bundledCode: "#line 2 \"fps/formal-power-series.hpp\"\n\ntemplate <class mint>\n\
    struct FormalPowerSeries : vector<mint> {\n  using vector<mint>::vector;\n  using\
    \ FPS = FormalPowerSeries;\n  FPS &operator+=(const FPS &r) {\n    if (r.size()\
    \ > this->size()) this->resize(r.size());\n    for (int i = 0; i < (int)r.size();\
    \ i++) (*this)[i] += r[i];\n    return *this;\n  }\n  FPS &operator+=(const mint\
    \ &r) {\n    if (this->empty()) this->resize(1);\n    (*this)[0] += r;\n    return\
    \ *this;\n  }\n  FPS &operator-=(const FPS &r) {\n    if (r.size() > this->size())\
    \ this->resize(r.size());\n    for (int i = 0; i < (int)r.size(); i++) (*this)[i]\
    \ -= r[i];\n    return *this;\n  }\n  FPS &operator-=(const mint &r) {\n    if\
    \ (this->empty()) this->resize(1);\n    (*this)[0] -= r;\n    return *this;\n\
    \  }\n  FPS &operator*=(const mint &v) {\n    for (int k = 0; k < (int)this->size();\
    \ k++) (*this)[k] *= v;\n    return *this;\n  }\n  FPS &operator/=(const FPS &r)\
    \ {\n    if (this->size() < r.size()) {\n      this->clear();\n      return *this;\n\
    \    }\n    int n = this->size() - r.size() + 1;\n    if ((int)r.size() <= 64)\
    \ {\n      FPS f(*this), g(r);\n      g.shrink();\n      mint coeff = g.at(g.size()\
    \ - 1).inv();\n      for (auto &x : g) x *= coeff;\n      int deg = (int)f.size()\
    \ - (int)g.size() + 1;\n      int gs = g.size();\n      FPS quo(deg);\n      for\
    \ (int i = deg - 1; i >= 0; i--) {\n        quo[i] = f[i + gs - 1];\n        for\
    \ (int j = 0; j < gs; j++) f[i + j] -= quo[i] * g[j];\n      }\n      *this =\
    \ quo * coeff;\n      this->resize(n, mint(0));\n      return *this;\n    }\n\
    \    return *this = ((*this).rev().pre(n) * r.rev().inv(n)).pre(n).rev();\n  }\n\
    \  FPS &operator%=(const FPS &r) {\n    *this -= *this / r * r;\n    shrink();\n\
    \    return *this;\n  }\n  FPS operator+(const FPS &r) const { return FPS(*this)\
    \ += r; }\n  FPS operator+(const mint &v) const { return FPS(*this) += v; }\n\
    \  FPS operator-(const FPS &r) const { return FPS(*this) -= r; }\n  FPS operator-(const\
    \ mint &v) const { return FPS(*this) -= v; }\n  FPS operator*(const FPS &r) const\
    \ { return FPS(*this) *= r; }\n  FPS operator*(const mint &v) const { return FPS(*this)\
    \ *= v; }\n  FPS operator/(const FPS &r) const { return FPS(*this) /= r; }\n \
    \ FPS operator%(const FPS &r) const { return FPS(*this) %= r; }\n  FPS operator-()\
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
    \ x) const {\n    mint r = 0, w = 1;\n    for (auto &v : *this) r += w * v, w\
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
    \  static void *ntt_ptr;\n  static void set_ntt();\n  FPS &operator*=(const FPS\
    \ &r);\n  FPS middle_product(const FPS &r) const;\n  void ntt();\n  void intt();\n\
    \  void ntt_doubling();\n  static int ntt_root();\n  FPS inv(int deg = -1) const;\n\
    \  FPS exp(int deg = -1) const;\n};\ntemplate <typename mint>\nvoid *FormalPowerSeries<mint>::ntt_ptr\
    \ = nullptr;\n#line 3 \"fps/polynomial-interpolation.hpp\"\n\ntemplate <class\
    \ mint>\nFormalPowerSeries<mint> PolynomialInterpolation(const vector<mint>& x,\
    \ const vector<mint>& y) {\n  using fps = FormalPowerSeries<mint>;\n  assert(x.size()\
    \ == y.size());\n  int n = x.size();\n  if (n == 0) return {y[0]};\n  vector<fps>\
    \ prod(2 * n);\n  for (int i = 0; i < n; i++) prod[i + n] = {-x[i], 1};\n  for\
    \ (int i = n - 1; i > 0; i--) prod[i] = prod[i * 2] * prod[i * 2 + 1];\n  vector<fps>\
    \ fs(2 * n);\n  fs[1] = prod[1].diff();\n  for (int i = 2; i < 2 * n; i++) fs[i]\
    \ = fs[i / 2] % prod[i];\n  for (int i = n; i < n * 2; i++) fs[i] = {y[i - n]\
    \ / fs[i][0]};\n  for (int i = n - 1; i > 0; i--) fs[i] = fs[(i << 1) | 0] * prod[(i\
    \ << 1) | 1] + fs[(i << 1) | 1] * prod[(i << 1) | 0];\n  return fs[1];\n}\n\n\
    /**\n * @brief \u591A\u9805\u5F0F\u88DC\u9593\n * @docs docs/fps/polynomial-interpolation.md\n\
    \ */\n"
  code: "#pragma once\n#include \"fps/formal-power-series.hpp\"\n\ntemplate <class\
    \ mint>\nFormalPowerSeries<mint> PolynomialInterpolation(const vector<mint>& x,\
    \ const vector<mint>& y) {\n  using fps = FormalPowerSeries<mint>;\n  assert(x.size()\
    \ == y.size());\n  int n = x.size();\n  if (n == 0) return {y[0]};\n  vector<fps>\
    \ prod(2 * n);\n  for (int i = 0; i < n; i++) prod[i + n] = {-x[i], 1};\n  for\
    \ (int i = n - 1; i > 0; i--) prod[i] = prod[i * 2] * prod[i * 2 + 1];\n  vector<fps>\
    \ fs(2 * n);\n  fs[1] = prod[1].diff();\n  for (int i = 2; i < 2 * n; i++) fs[i]\
    \ = fs[i / 2] % prod[i];\n  for (int i = n; i < n * 2; i++) fs[i] = {y[i - n]\
    \ / fs[i][0]};\n  for (int i = n - 1; i > 0; i--) fs[i] = fs[(i << 1) | 0] * prod[(i\
    \ << 1) | 1] + fs[(i << 1) | 1] * prod[(i << 1) | 0];\n  return fs[1];\n}\n\n\
    /**\n * @brief \u591A\u9805\u5F0F\u88DC\u9593\n * @docs docs/fps/polynomial-interpolation.md\n\
    \ */"
  dependsOn:
  - fps/formal-power-series.hpp
  isVerificationFile: false
  path: fps/polynomial-interpolation.hpp
  requiredBy: []
  timestamp: '2025-10-23 01:57:19+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/fps/UNIT_prefix_sum_of_polynomial.test.cpp
  - verify/fps/LC_polynomial_interpolation.test.cpp
documentation_of: fps/polynomial-interpolation.hpp
layout: document
redirect_from:
- /library/fps/polynomial-interpolation.hpp
- /library/fps/polynomial-interpolation.hpp.html
title: "\u591A\u9805\u5F0F\u88DC\u9593"
---
$n$ 次多項式 $f$ で $0\leq i\leq n$ に対し $f(x_i)=y_i$ を満たすものを $O(n(\log n)^2)$ 時間で求める．

## アルゴリズム

$g(x)=\prod_{i=0}^{n}(x-x_i)$ とすれば Lagrange 補間より以下が成り立つ．

$$f(x)=\sum_{i=0}^{n}\frac{y_ig(x)}{g'(x_i)(x-x_i)}$$

以下のようにして $O(n(\log n)^2)$ 時間で計算できる．

- $g(x)$ は分割統治により $O(n(\log n)^2)$ 時間で計算できる．
- $g'(x_i)$ は多点評価により $O(n(\log n)^2)$ 時間で列挙できる．
- $\sum_{i=0}^{n}\frac{y_i}{g'(x_i)(x-x_i)}$ は有理数の和として分割統治により $O(n(\log n)^2)$ 時間で計算できる．

$g(x)$ の計算過程はそれ以降にも流用できる．