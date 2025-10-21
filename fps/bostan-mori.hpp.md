---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: fps/formal-power-series.hpp
    title: fps/formal-power-series.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: fps/linearly-recurrent-sequence.hpp
    title: "\u7DDA\u5F62\u6F38\u5316\u5F0F\u7528"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/fps/LC_consecutive_terms_of_linear_recurrent_sequence.test.cpp
    title: verify/fps/LC_consecutive_terms_of_linear_recurrent_sequence.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/fps/LC_kth_term_of_linearly_recurrent_sequence.test.cpp
    title: verify/fps/LC_kth_term_of_linearly_recurrent_sequence.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/fps/bostan-mori.md
    document_title: Bostan-Mori
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
    \ = nullptr;\n#line 3 \"fps/bostan-mori.hpp\"\n\n// [x^n]f(x)/g(x)\ntemplate <class\
    \ mint>\nmint BostanMori(FormalPowerSeries<mint> f, FormalPowerSeries<mint> g,\
    \ long long n) {\n  g.shrink();\n  mint ret = 0;\n  if (f.size() >= g.size())\
    \ {\n    auto q = f / g;\n    if (n < q.size()) ret += q[n];\n    f -= q * g;\n\
    \    f.shrink();\n  }\n  if (f.empty()) return ret;\n  FormalPowerSeries<mint>::set_ntt();\n\
    \  if (!FormalPowerSeries<mint>::ntt_ptr) {\n    f.resize(g.size() - 1);\n   \
    \ for (; n > 0; n >>= 1) {\n      auto g1 = g;\n      for (int i = 1; i < g1.size();\
    \ i += 2) g1[i] = -g1[i];\n      auto p = f * g1, q = g * g1;\n      if (n & 1)\
    \ {\n        for (int i = 0; i < f.size(); i++) f[i] = p[(i << 1) | 1];\n    \
    \  } else {\n        for (int i = 0; i < f.size(); i++) f[i] = p[i << 1];\n  \
    \    }\n      for (int i = 0; i < g.size(); i++) g[i] = q[i << 1];\n    }\n  \
    \  return ret + f[0] / g[0];\n  } else {\n    int m = 1, log = 0;\n    while (m\
    \ < g.size()) m <<= 1, log++;\n    mint wi = mint(FormalPowerSeries<mint>::ntt_root()).inv().pow((mint::get_mod()\
    \ - 1) >> (log + 1));\n    vector<int> rev(m);\n    for (int i = 0; i < rev.size();\
    \ i++) rev[i] = (rev[i / 2] / 2) | ((i & 1) << (log - 1));\n    vector<mint> pow(m,\
    \ 1);\n    for (int i = 1; i < m; i++) pow[rev[i]] = pow[rev[i - 1]] * wi;\n \
    \   f.resize(m), g.resize(m);\n    f.ntt(), g.ntt();\n    mint inv2 = mint(2).inv();\n\
    \    for (; n >= m; n >>= 1) {\n      f.ntt_doubling(), g.ntt_doubling();\n  \
    \    if (n & 1) {\n        for (int i = 0; i < m; i++) f[i] = (f[i << 1] * g[(i\
    \ << 1) | 1] - f[(i << 1) | 1] * g[i << 1]) * inv2 * pow[i];\n      } else {\n\
    \        for (int i = 0; i < m; i++) f[i] = (f[i << 1] * g[(i << 1) | 1] + f[(i\
    \ << 1) | 1] * g[i << 1]) * inv2;\n      }\n      for (int i = 0; i < m; i++)\
    \ g[i] = g[i << 1] * g[(i << 1) | 1];\n      f.resize(m), g.resize(m);\n    }\n\
    \    f.intt(), g.intt();\n    return ret + (f * g.inv())[n];\n  }\n}\n/**\n *\
    \ @brief Bostan-Mori\n * @docs docs/fps/bostan-mori.md\n */\n"
  code: "#pragma once\n#include \"fps/formal-power-series.hpp\"\n\n// [x^n]f(x)/g(x)\n\
    template <class mint>\nmint BostanMori(FormalPowerSeries<mint> f, FormalPowerSeries<mint>\
    \ g, long long n) {\n  g.shrink();\n  mint ret = 0;\n  if (f.size() >= g.size())\
    \ {\n    auto q = f / g;\n    if (n < q.size()) ret += q[n];\n    f -= q * g;\n\
    \    f.shrink();\n  }\n  if (f.empty()) return ret;\n  FormalPowerSeries<mint>::set_ntt();\n\
    \  if (!FormalPowerSeries<mint>::ntt_ptr) {\n    f.resize(g.size() - 1);\n   \
    \ for (; n > 0; n >>= 1) {\n      auto g1 = g;\n      for (int i = 1; i < g1.size();\
    \ i += 2) g1[i] = -g1[i];\n      auto p = f * g1, q = g * g1;\n      if (n & 1)\
    \ {\n        for (int i = 0; i < f.size(); i++) f[i] = p[(i << 1) | 1];\n    \
    \  } else {\n        for (int i = 0; i < f.size(); i++) f[i] = p[i << 1];\n  \
    \    }\n      for (int i = 0; i < g.size(); i++) g[i] = q[i << 1];\n    }\n  \
    \  return ret + f[0] / g[0];\n  } else {\n    int m = 1, log = 0;\n    while (m\
    \ < g.size()) m <<= 1, log++;\n    mint wi = mint(FormalPowerSeries<mint>::ntt_root()).inv().pow((mint::get_mod()\
    \ - 1) >> (log + 1));\n    vector<int> rev(m);\n    for (int i = 0; i < rev.size();\
    \ i++) rev[i] = (rev[i / 2] / 2) | ((i & 1) << (log - 1));\n    vector<mint> pow(m,\
    \ 1);\n    for (int i = 1; i < m; i++) pow[rev[i]] = pow[rev[i - 1]] * wi;\n \
    \   f.resize(m), g.resize(m);\n    f.ntt(), g.ntt();\n    mint inv2 = mint(2).inv();\n\
    \    for (; n >= m; n >>= 1) {\n      f.ntt_doubling(), g.ntt_doubling();\n  \
    \    if (n & 1) {\n        for (int i = 0; i < m; i++) f[i] = (f[i << 1] * g[(i\
    \ << 1) | 1] - f[(i << 1) | 1] * g[i << 1]) * inv2 * pow[i];\n      } else {\n\
    \        for (int i = 0; i < m; i++) f[i] = (f[i << 1] * g[(i << 1) | 1] + f[(i\
    \ << 1) | 1] * g[i << 1]) * inv2;\n      }\n      for (int i = 0; i < m; i++)\
    \ g[i] = g[i << 1] * g[(i << 1) | 1];\n      f.resize(m), g.resize(m);\n    }\n\
    \    f.intt(), g.intt();\n    return ret + (f * g.inv())[n];\n  }\n}\n/**\n *\
    \ @brief Bostan-Mori\n * @docs docs/fps/bostan-mori.md\n */"
  dependsOn:
  - fps/formal-power-series.hpp
  isVerificationFile: false
  path: fps/bostan-mori.hpp
  requiredBy:
  - fps/linearly-recurrent-sequence.hpp
  timestamp: '2025-10-21 21:13:36+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/fps/LC_consecutive_terms_of_linear_recurrent_sequence.test.cpp
  - verify/fps/LC_kth_term_of_linearly_recurrent_sequence.test.cpp
documentation_of: fps/bostan-mori.hpp
layout: document
redirect_from:
- /library/fps/bostan-mori.hpp
- /library/fps/bostan-mori.hpp.html
title: Bostan-Mori
---
Bostan-Mori 法．

高々 $m$ 次のFPS $f,g$ に対し $[x^n]\frac{f(x)}{g(x)}$ を $O(m\log m\log n)$ 時間で求める．

## アルゴリズム

以下の変形をする．

$$\frac{f(x)}{g(x)}=\frac{f(x)g(-x)}{g(x)g(-x)}$$

$g(x)g(-x)$ は偶関数であるから $g(x)g(-x)=g'(x^2)$ とおける．

$n$ が偶数のとき，$f(x)g(-x)$ の偶数次の部分を $f'(x^2)$ とすれば以下が成り立つ．

$$[x^n]\frac{f(x)}{g(x)}=[x^n]\frac{f'(x^2)}{g'(x^2)}=[x^{n/2}]\frac{f'(x)}{g'(x)}$$

$n$ が奇数のときも同様．

## 定数倍高速化

$\max(\deg f,\deg g)+1$ 以上の最小の二冪を $m$ とし，$1$ の原始 $2m$ 乗根 $\omega$ をとる．

$g'(\omega^{2i})=g(\omega^i)g(\omega^{i+m})$ であるので，$g$ に長さ $2m$ の FFT をし，適当に積を取って長さ $m$ の IFTT をすれば $g'$ が求められる．

また FFT のダブリングを用いればさらに定数倍が改善できる．