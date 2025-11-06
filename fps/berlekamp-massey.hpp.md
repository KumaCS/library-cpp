---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
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
    path: verify/fps/LC_find_linear_recurrence.test.cpp
    title: verify/fps/LC_find_linear_recurrence.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/fps/LC_kth_term_of_linearly_recurrent_sequence.test.cpp
    title: verify/fps/LC_kth_term_of_linearly_recurrent_sequence.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/fps/berlekamp-massey.md
    document_title: Berlekamp-Massey
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
    \ {\n    assert(sz >= 0);\n    if ((int)this->size() <= sz)\n      this->clear();\n\
    \    else\n      this->erase(this->begin(), this->begin() + sz);\n    return *this;\n\
    \  }\n  FPS operator>>(int sz) const {\n    if ((int)this->size() <= sz) return\
    \ {};\n    FPS ret(*this);\n    ret.erase(ret.begin(), ret.begin() + sz);\n  \
    \  return ret;\n  }\n  FPS operator<<=(int sz) {\n    assert(sz >= 0);\n    this->insert(this->begin(),\
    \ sz, mint(0));\n    return *this;\n  }\n  FPS operator<<(int sz) const {\n  \
    \  FPS ret(*this);\n    ret.insert(ret.begin(), sz, mint(0));\n    return ret;\n\
    \  }\n  FPS diff() const {\n    const int n = (int)this->size();\n    FPS ret(max(0,\
    \ n - 1));\n    mint one(1), coeff(1);\n    for (int i = 1; i < n; i++) {\n  \
    \    ret[i - 1] = (*this)[i] * coeff;\n      coeff += one;\n    }\n    return\
    \ ret;\n  }\n  FPS integral() const {\n    const int n = (int)this->size();\n\
    \    FPS ret(n + 1);\n    ret[0] = mint(0);\n    if (n > 0) ret[1] = mint(1);\n\
    \    auto mod = mint::get_mod();\n    for (int i = 2; i <= n; i++) ret[i] = (-ret[mod\
    \ % i]) * (mod / i);\n    for (int i = 0; i < n; i++) ret[i + 1] *= (*this)[i];\n\
    \    return ret;\n  }\n  mint eval(mint x) const {\n    mint r = 0, w = 1;\n \
    \   for (auto& v : *this) r += w * v, w *= x;\n    return r;\n  }\n  FPS log(int\
    \ deg = -1) const {\n    assert((*this)[0] == mint(1));\n    if (deg == -1) deg\
    \ = (int)this->size();\n    return (this->diff() * this->inv(deg)).pre(deg - 1).integral();\n\
    \  }\n  FPS pow(int64_t k, int deg = -1) const {\n    const int n = (int)this->size();\n\
    \    if (deg == -1) deg = n;\n    if (k == 0) {\n      FPS ret(deg);\n      if\
    \ (deg) ret[0] = 1;\n      return ret;\n    }\n    for (int i = 0; i < n; i++)\
    \ {\n      if ((*this)[i] != mint(0)) {\n        mint rev = mint(1) / (*this)[i];\n\
    \        FPS ret = (((*this * rev) >> i).log(deg) * k).exp(deg);\n        ret\
    \ *= (*this)[i].pow(k);\n        ret = (ret << (i * k)).pre(deg);\n        if\
    \ ((int)ret.size() < deg) ret.resize(deg, mint(0));\n        return ret;\n   \
    \   }\n      if (__int128_t(i + 1) * k >= deg) return FPS(deg, mint(0));\n   \
    \ }\n    return FPS(deg, mint(0));\n  }\n\n  static void* ntt_ptr;\n  static void\
    \ set_ntt();\n  FPS& operator*=(const FPS& r);\n  FPS middle_product(const FPS&\
    \ r) const;\n  void ntt();\n  void intt();\n  void ntt_doubling();\n  static int\
    \ ntt_root();\n  FPS inv(int deg = -1) const;\n  FPS exp(int deg = -1) const;\n\
    };\ntemplate <typename mint>\nvoid* FormalPowerSeries<mint>::ntt_ptr = nullptr;\n\
    #line 3 \"fps/berlekamp-massey.hpp\"\n\ntemplate <class mint>\nFormalPowerSeries<mint>\
    \ BerlekampMassey(const FormalPowerSeries<mint>& a) {\n  int n = a.size();\n \
    \ FormalPowerSeries<mint> b, c;\n  b.reserve(n + 1), c.reserve(n + 1);\n  b.push_back(1),\
    \ c.push_back(1);\n  mint y = 1;\n  for (int k = 0; k < n; k++) {\n    mint x\
    \ = 0;\n    for (int i = 0; i < c.size(); i++) x += c[i] * a[k - i];\n    b.insert(b.begin(),\
    \ 0);\n    if (x == 0) continue;\n    mint v = x / y;\n    if (b.size() > c.size())\
    \ {\n      for (int i = 0; i < b.size(); i++) b[i] *= -v;\n      for (int i =\
    \ 0; i < c.size(); i++) b[i] += c[i];\n      swap(b, c);\n      y = x;\n    }\
    \ else {\n      for (int i = 0; i < b.size(); i++) c[i] -= v * b[i];\n    }\n\
    \  }\n  return c;\n}\n\n/**\n * @brief Berlekamp-Massey\n * @docs docs/fps/berlekamp-massey.md\n\
    \ */\n"
  code: "#pragma once\n#include \"fps/formal-power-series.hpp\"\n\ntemplate <class\
    \ mint>\nFormalPowerSeries<mint> BerlekampMassey(const FormalPowerSeries<mint>&\
    \ a) {\n  int n = a.size();\n  FormalPowerSeries<mint> b, c;\n  b.reserve(n +\
    \ 1), c.reserve(n + 1);\n  b.push_back(1), c.push_back(1);\n  mint y = 1;\n  for\
    \ (int k = 0; k < n; k++) {\n    mint x = 0;\n    for (int i = 0; i < c.size();\
    \ i++) x += c[i] * a[k - i];\n    b.insert(b.begin(), 0);\n    if (x == 0) continue;\n\
    \    mint v = x / y;\n    if (b.size() > c.size()) {\n      for (int i = 0; i\
    \ < b.size(); i++) b[i] *= -v;\n      for (int i = 0; i < c.size(); i++) b[i]\
    \ += c[i];\n      swap(b, c);\n      y = x;\n    } else {\n      for (int i =\
    \ 0; i < b.size(); i++) c[i] -= v * b[i];\n    }\n  }\n  return c;\n}\n\n/**\n\
    \ * @brief Berlekamp-Massey\n * @docs docs/fps/berlekamp-massey.md\n */"
  dependsOn:
  - fps/formal-power-series.hpp
  isVerificationFile: false
  path: fps/berlekamp-massey.hpp
  requiredBy:
  - fps/linearly-recurrent-sequence.hpp
  timestamp: '2025-11-06 12:30:44+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/fps/LC_find_linear_recurrence.test.cpp
  - verify/fps/LC_consecutive_terms_of_linear_recurrent_sequence.test.cpp
  - verify/fps/LC_kth_term_of_linearly_recurrent_sequence.test.cpp
documentation_of: fps/berlekamp-massey.hpp
layout: document
redirect_from:
- /library/fps/berlekamp-massey.hpp
- /library/fps/berlekamp-massey.hpp.html
title: Berlekamp-Massey
---
Berlekamp-Massey のアルゴリズム．

数列 $a=(a_0,\dots,a_{n-1})$ に対し，以下を満たす $g(x)$ のうち最も次数の低いものを $O(n^2)$ 時間で求める．

$$\exists f(x),\quad \frac{f(x)}{g(x)}\bmod x^n=a_0+\cdots+a_{n-1}x^{n-1}$$

## アルゴリズム

$\frac{f_0+\cdots+f_{k-1}x^{k-1}}{g_0+\cdots+g_kx^k}\bmod x^{k+1}=a_0+\cdots+a_kx^k$ のとき

$a_kx^k$