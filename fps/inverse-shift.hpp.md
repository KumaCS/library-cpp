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
    _deprecated_at_docs: docs/fps/inverse-shift.md
    document_title: "Inverse \u306E\u6B21\u6570\u30B7\u30D5\u30C8"
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
    \ = nullptr;\n#line 3 \"fps/inverse-shift.hpp\"\n\n// [x^n,...,x^{n+k-1}]1/f(x)\n\
    template <class mint>\nFormalPowerSeries<mint> InverseShift(FormalPowerSeries<mint>\
    \ f, long long n, int k = -1) {\n  using fps = FormalPowerSeries<mint>;\n  assert(f[0]\
    \ != 0);\n  if (k == -1) k = f.size();\n  int m = 1;\n  while (m < k) m <<= 1;\n\
    \n  int log = __builtin_ctz((unsigned int)m);\n  mint w = mint(fps::ntt_root()).pow((mint::get_mod()\
    \ - 1) >> (log + 1));\n  mint wi = w.inv();\n  vector<int> rev(m);\n  for (int\
    \ i = 0; i < rev.size(); i++) rev[i] = (rev[i / 2] / 2) | ((i & 1) << (log - 1));\n\
    \  mint inv2 = mint(2).inv();\n\n  f.resize(m);\n  f.ntt();\n  auto rec = [&](auto&\
    \ rec, long long n) -> void {\n    if (n < m) {\n      f.intt();\n      f = f.inv(n\
    \ + m);\n      f >>= n;\n      f.ntt();\n      return;\n    }\n    f.ntt_doubling();\n\
    \    assert(f.size() == 2 * m);\n    auto f1 = f;\n    for (int i = 0; i < m;\
    \ i++) swap(f1[i << 1], f1[(i << 1) | 1]);\n    for (int i = 0; i < m; i++) f[i]\
    \ = f[i << 1] * f[(i << 1) | 1];\n    f.resize(m);\n    rec(rec, (n - m + 1) /\
    \ 2);\n    if (((n - m) & 1) == 0) {\n      f.resize(2 * m);\n      for (int i\
    \ = m - 1; i >= 0; i--) {\n        f[(i << 1) | 1] = f[i];\n        f[i << 1]\
    \ = f[i];\n      }\n    } else {\n      mint p = 1;\n      for (auto i : rev)\
    \ f[i] *= p, p *= w;\n      f.resize(2 * m);\n      for (int i = m - 1; i >= 0;\
    \ i--) {\n        f[(i << 1) | 1] = -f[i];\n        f[i << 1] = f[i];\n      }\n\
    \    }\n    for (int i = 0; i < 2 * m; i++) f[i] *= f1[i];\n    auto odd = fps(f.begin()\
    \ + m, f.end());\n    odd.intt();\n    mint p = 1;\n    for (int i = 0; i < m;\
    \ i++) odd[i] *= p, p *= wi;\n    odd.ntt();\n    f.resize(m);\n    for (int i\
    \ = 0; i < m; i++) f[i] = (f[i] - odd[i]) * inv2;\n  };\n  rec(rec, n);\n  f.intt();\n\
    \  f.resize(k);\n  return f;\n}\n/**\n * @brief Inverse \u306E\u6B21\u6570\u30B7\
    \u30D5\u30C8\n * @docs docs/fps/inverse-shift.md\n */\n"
  code: "#pragma once\n#include \"fps/formal-power-series.hpp\"\n\n// [x^n,...,x^{n+k-1}]1/f(x)\n\
    template <class mint>\nFormalPowerSeries<mint> InverseShift(FormalPowerSeries<mint>\
    \ f, long long n, int k = -1) {\n  using fps = FormalPowerSeries<mint>;\n  assert(f[0]\
    \ != 0);\n  if (k == -1) k = f.size();\n  int m = 1;\n  while (m < k) m <<= 1;\n\
    \n  int log = __builtin_ctz((unsigned int)m);\n  mint w = mint(fps::ntt_root()).pow((mint::get_mod()\
    \ - 1) >> (log + 1));\n  mint wi = w.inv();\n  vector<int> rev(m);\n  for (int\
    \ i = 0; i < rev.size(); i++) rev[i] = (rev[i / 2] / 2) | ((i & 1) << (log - 1));\n\
    \  mint inv2 = mint(2).inv();\n\n  f.resize(m);\n  f.ntt();\n  auto rec = [&](auto&\
    \ rec, long long n) -> void {\n    if (n < m) {\n      f.intt();\n      f = f.inv(n\
    \ + m);\n      f >>= n;\n      f.ntt();\n      return;\n    }\n    f.ntt_doubling();\n\
    \    assert(f.size() == 2 * m);\n    auto f1 = f;\n    for (int i = 0; i < m;\
    \ i++) swap(f1[i << 1], f1[(i << 1) | 1]);\n    for (int i = 0; i < m; i++) f[i]\
    \ = f[i << 1] * f[(i << 1) | 1];\n    f.resize(m);\n    rec(rec, (n - m + 1) /\
    \ 2);\n    if (((n - m) & 1) == 0) {\n      f.resize(2 * m);\n      for (int i\
    \ = m - 1; i >= 0; i--) {\n        f[(i << 1) | 1] = f[i];\n        f[i << 1]\
    \ = f[i];\n      }\n    } else {\n      mint p = 1;\n      for (auto i : rev)\
    \ f[i] *= p, p *= w;\n      f.resize(2 * m);\n      for (int i = m - 1; i >= 0;\
    \ i--) {\n        f[(i << 1) | 1] = -f[i];\n        f[i << 1] = f[i];\n      }\n\
    \    }\n    for (int i = 0; i < 2 * m; i++) f[i] *= f1[i];\n    auto odd = fps(f.begin()\
    \ + m, f.end());\n    odd.intt();\n    mint p = 1;\n    for (int i = 0; i < m;\
    \ i++) odd[i] *= p, p *= wi;\n    odd.ntt();\n    f.resize(m);\n    for (int i\
    \ = 0; i < m; i++) f[i] = (f[i] - odd[i]) * inv2;\n  };\n  rec(rec, n);\n  f.intt();\n\
    \  f.resize(k);\n  return f;\n}\n/**\n * @brief Inverse \u306E\u6B21\u6570\u30B7\
    \u30D5\u30C8\n * @docs docs/fps/inverse-shift.md\n */"
  dependsOn:
  - fps/formal-power-series.hpp
  isVerificationFile: false
  path: fps/inverse-shift.hpp
  requiredBy:
  - fps/linearly-recurrent-sequence.hpp
  timestamp: '2025-10-21 21:13:36+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/fps/LC_consecutive_terms_of_linear_recurrent_sequence.test.cpp
  - verify/fps/LC_kth_term_of_linearly_recurrent_sequence.test.cpp
documentation_of: fps/inverse-shift.hpp
layout: document
redirect_from:
- /library/fps/inverse-shift.hpp
- /library/fps/inverse-shift.hpp.html
title: "Inverse \u306E\u6B21\u6570\u30B7\u30D5\u30C8"
---
$d-1$ 次の FPS $f(x)$ について，$\dfrac{1}{f(x)}$ の $x^n$ から $x^{n+d-1}$ の係数を $O(d\log d\log n)$ 時間で求める．

これは $x^{-n}\bmod f(x)$ を求めることとも等価．

## アルゴリズム

$f(x)$ の $x^a$ から $x^{b-1}$ の係数を並べた列を $[x^{[a,b)}]f(x)$ で表すことにする．

以下が成り立つ．

$$[x^{[n,n+d)}]\frac{1}{Q(x)}=[x^{[n,n+d)}]\frac{Q(-x)}{Q(x)Q(-x)}$$

後から $Q(-x)$ を掛けることを考えると $[x^{[n-d,n+d)}]\dfrac{1}{Q(x)Q(-x)}$ を求めればよい．

$Q(x)Q(-x)=Q'(x^2)$ とおくと $[x^{[\lceil(n-d)/2\rceil,\lceil (n+d)/2\rceil)}]\dfrac{1}{Q'(x)}$ に帰着される．

$n$ が十分小さい場合は naive に計算してしまって構わない．
- 実装の場合分けを減らすため $n\leq d$ のとき naive に計算している．

## FFT 削減

疑似コードで書くと以下のようになる．

```
shift(n, f): // 1/f(x) の x^n から x^(n+d-1) を返す
  if n is small:
    return naive(n, f)
  f1(x) = f(-x)
  g(x^2) = f(x) * f1(x)
  g(x) = shift(ceil((n-d)/2), g) // d-1 次多項式とみなす
  g(x) = g(x^2) * x^((n-d)%2)
  return g(x) * f1(x) の x^d から x^(2d-1)
```

[FFT の回数を削減するテクニック集 - noshi91のメモ](https://noshi91.hatenablog.com/entry/2023/12/10/163348) のテクニックを使える部分が多い．