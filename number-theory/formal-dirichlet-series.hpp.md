---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/number-theory/formal-dirichlet-series.md
    document_title: "\u5F62\u5F0F\u7684 Dirichlet \u7D1A\u6570"
    links: []
  bundledCode: "#line 2 \"number-theory/formal-dirichlet-series.hpp\"\n\ntemplate\
    \ <class mint>\nstruct FormalDirichletSeries : vector<mint> {\n  using vector<mint>::vector;\n\
    \  using FDS = FormalDirichletSeries;\n  FDS& operator+=(const mint& v) {\n  \
    \  if (1 < this->size()) (*this)[1] += v;\n    return *this;\n  }\n  FDS& operator+=(const\
    \ FDS& r) {\n    if (r.size() > this->size()) this->resize(r.size());\n    for\
    \ (int i = 1; i < (int)r.size(); i++) (*this)[i] += r[i];\n    return *this;\n\
    \  }\n  FDS& operator-=(const mint& v) {\n    if (1 < this->size()) (*this)[1]\
    \ -= v;\n    return *this;\n  }\n  FDS& operator-=(const FDS& r) {\n    if (r.size()\
    \ > this->size()) this->resize(r.size());\n    for (int i = 1; i < (int)r.size();\
    \ i++) (*this)[i] -= r[i];\n    return *this;\n  }\n  FDS& operator*=(const mint&\
    \ v) {\n    for (int i = 1; i < (int)this->size(); i++) (*this)[i] *= v;\n   \
    \ return *this;\n  }\n  FDS& operator*=(const FDS& r) {\n    FDS p(this->size(),\
    \ 0);\n    for (int i = 1; i < (int)r.size(); i++)\n      for (int j = 1; i *\
    \ j < (int)p.size(); j++)\n        p[i * j] += r[i] * (*this)[j];\n    return\
    \ *this = p;\n  }\n  FDS& operator/=(const FDS& r) {\n    mint c = r[1].inv();\n\
    \    for (int i = 1; i < (int)this->size(); i++) {\n      (*this)[i] *= c;\n \
    \     for (int j = 2; j < (int)r.size() && i * j < (int)this->size(); j++)\n \
    \       (*this)[i * j] -= (*this)[i] * r[j];\n    }\n    return *this;\n  }\n\
    \  FDS operator+(const mint& v) const { return FDS(*this) += v; }\n  FDS operator+(const\
    \ FDS& r) const { return FDS(*this) += r; }\n  FDS operator-(const mint& v) const\
    \ { return FDS(*this) -= v; }\n  FDS operator-(const FDS& r) const { return FDS(*this)\
    \ -= r; }\n  FDS operator*(const mint& v) const { return FDS(*this) *= v; }\n\
    \  FDS operator*(const FDS& r) const { return FDS(*this) *= r; }\n  FDS operator/(const\
    \ FDS& r) const { return FDS(*this) /= r; }\n  FDS operator-() const {\n    FDS\
    \ ret(this->size());\n    for (int i = 1; i < (int)this->size(); i++) ret[i] =\
    \ -(*this)[i];\n    return ret;\n  }\n\n  static vector<mint> inv;\n  static void\
    \ init_inv() {\n    if (inv.empty()) {\n      inv.assign(33, 0);\n      inv[1]\
    \ = mint(1);\n      auto mod = mint::get_mod();\n      for (int i = 2; i < (int)inv.size();\
    \ i++) inv[i] = (-inv[mod % i]) * (mod / i);\n    }\n  }\n  FDS integral() const\
    \ {\n    int n = this->size();\n    if (n <= 1) return FDS(n);\n    calc_lpf(n);\n\
    \    FDS ret(n);\n    init_inv();\n    for (int i = 2; i < ret.size(); i++) ret[i]\
    \ = (*this)[i] * inv[npf[i]];\n    return ret;\n  }\n  FDS diff() const {\n  \
    \  calc_lpf(this->size());\n    FDS ret(this->size());\n    for (int i = 1; i\
    \ < (int)this->size(); i++) ret[i] = (*this)[i] * npf[i];\n    return ret;\n \
    \ }\n  FDS log(int n = -1) const {\n    if (n == -1) n = (int)this->size();\n\
    \    if (n <= 1) return FDS(n);\n    assert((*this)[1] == mint(1));\n    FDS f\
    \ = *this;\n    f.resize(n);\n    return (f.diff() / f).integral();\n  }\n  FDS\
    \ exp(int n = -1) const {\n    if (n == -1) n = (int)this->size();\n    if (n\
    \ <= 1) return FDS(n);\n    assert((*this)[1] == mint(0));\n    auto df = this->diff();\n\
    \    FDS ret(n);\n    if (1 < n) ret[1] = 1;\n    init_inv();\n    for (int i\
    \ = 1; i < n; i++) {\n      if (i > 1) ret[i] *= inv[npf[i]];\n      for (int\
    \ j = 2; j < df.size() && i * j < n; j++) ret[i * j] += df[j] * ret[i];\n    }\n\
    \    return ret;\n  }\n\n  static vector<int> npf;\n  static vector<int> lpf;\n\
    \  static void calc_lpf(int n) {\n    if (lpf.empty()) {\n      lpf = {0, 1, 2,\
    \ 3, 2, 5, 2, 7};\n      npf = {0, 0, 1, 1, 2, 1, 2, 1};\n    }\n    int l = lpf.size(),\
    \ r = l;\n    while (r <= n) r <<= 1;\n    if (l == r) return;\n    lpf.resize(r);\n\
    \    npf.resize(r);\n    for (int i = 2; i < l; i++) {\n      if (lpf[i] != i)\
    \ continue;\n      for (int j = i * 2; j < r; j += i)\n        if (lpf[j] == 0)\
    \ lpf[j] = i;\n    }\n    for (int i = l; i < r; i++) {\n      if (lpf[i] != 0)\
    \ continue;\n      lpf[i] = i;\n      for (int j = i * 2; j < r; j += i)\n   \
    \     if (lpf[j] == 0) lpf[j] = i;\n    }\n    for (int i = l; i < r; i++)\n \
    \     npf[i] = npf[i / lpf[i]] + 1;\n  }\n};\ntemplate <typename mint>\nvector<mint>\
    \ FormalDirichletSeries<mint>::inv = {};\ntemplate <typename mint>\nvector<int>\
    \ FormalDirichletSeries<mint>::npf = {};\ntemplate <typename mint>\nvector<int>\
    \ FormalDirichletSeries<mint>::lpf = {};\n/**\n * @brief \u5F62\u5F0F\u7684 Dirichlet\
    \ \u7D1A\u6570\n * @docs docs/number-theory/formal-dirichlet-series.md\n */\n"
  code: "#pragma once\n\ntemplate <class mint>\nstruct FormalDirichletSeries : vector<mint>\
    \ {\n  using vector<mint>::vector;\n  using FDS = FormalDirichletSeries;\n  FDS&\
    \ operator+=(const mint& v) {\n    if (1 < this->size()) (*this)[1] += v;\n  \
    \  return *this;\n  }\n  FDS& operator+=(const FDS& r) {\n    if (r.size() > this->size())\
    \ this->resize(r.size());\n    for (int i = 1; i < (int)r.size(); i++) (*this)[i]\
    \ += r[i];\n    return *this;\n  }\n  FDS& operator-=(const mint& v) {\n    if\
    \ (1 < this->size()) (*this)[1] -= v;\n    return *this;\n  }\n  FDS& operator-=(const\
    \ FDS& r) {\n    if (r.size() > this->size()) this->resize(r.size());\n    for\
    \ (int i = 1; i < (int)r.size(); i++) (*this)[i] -= r[i];\n    return *this;\n\
    \  }\n  FDS& operator*=(const mint& v) {\n    for (int i = 1; i < (int)this->size();\
    \ i++) (*this)[i] *= v;\n    return *this;\n  }\n  FDS& operator*=(const FDS&\
    \ r) {\n    FDS p(this->size(), 0);\n    for (int i = 1; i < (int)r.size(); i++)\n\
    \      for (int j = 1; i * j < (int)p.size(); j++)\n        p[i * j] += r[i] *\
    \ (*this)[j];\n    return *this = p;\n  }\n  FDS& operator/=(const FDS& r) {\n\
    \    mint c = r[1].inv();\n    for (int i = 1; i < (int)this->size(); i++) {\n\
    \      (*this)[i] *= c;\n      for (int j = 2; j < (int)r.size() && i * j < (int)this->size();\
    \ j++)\n        (*this)[i * j] -= (*this)[i] * r[j];\n    }\n    return *this;\n\
    \  }\n  FDS operator+(const mint& v) const { return FDS(*this) += v; }\n  FDS\
    \ operator+(const FDS& r) const { return FDS(*this) += r; }\n  FDS operator-(const\
    \ mint& v) const { return FDS(*this) -= v; }\n  FDS operator-(const FDS& r) const\
    \ { return FDS(*this) -= r; }\n  FDS operator*(const mint& v) const { return FDS(*this)\
    \ *= v; }\n  FDS operator*(const FDS& r) const { return FDS(*this) *= r; }\n \
    \ FDS operator/(const FDS& r) const { return FDS(*this) /= r; }\n  FDS operator-()\
    \ const {\n    FDS ret(this->size());\n    for (int i = 1; i < (int)this->size();\
    \ i++) ret[i] = -(*this)[i];\n    return ret;\n  }\n\n  static vector<mint> inv;\n\
    \  static void init_inv() {\n    if (inv.empty()) {\n      inv.assign(33, 0);\n\
    \      inv[1] = mint(1);\n      auto mod = mint::get_mod();\n      for (int i\
    \ = 2; i < (int)inv.size(); i++) inv[i] = (-inv[mod % i]) * (mod / i);\n    }\n\
    \  }\n  FDS integral() const {\n    int n = this->size();\n    if (n <= 1) return\
    \ FDS(n);\n    calc_lpf(n);\n    FDS ret(n);\n    init_inv();\n    for (int i\
    \ = 2; i < ret.size(); i++) ret[i] = (*this)[i] * inv[npf[i]];\n    return ret;\n\
    \  }\n  FDS diff() const {\n    calc_lpf(this->size());\n    FDS ret(this->size());\n\
    \    for (int i = 1; i < (int)this->size(); i++) ret[i] = (*this)[i] * npf[i];\n\
    \    return ret;\n  }\n  FDS log(int n = -1) const {\n    if (n == -1) n = (int)this->size();\n\
    \    if (n <= 1) return FDS(n);\n    assert((*this)[1] == mint(1));\n    FDS f\
    \ = *this;\n    f.resize(n);\n    return (f.diff() / f).integral();\n  }\n  FDS\
    \ exp(int n = -1) const {\n    if (n == -1) n = (int)this->size();\n    if (n\
    \ <= 1) return FDS(n);\n    assert((*this)[1] == mint(0));\n    auto df = this->diff();\n\
    \    FDS ret(n);\n    if (1 < n) ret[1] = 1;\n    init_inv();\n    for (int i\
    \ = 1; i < n; i++) {\n      if (i > 1) ret[i] *= inv[npf[i]];\n      for (int\
    \ j = 2; j < df.size() && i * j < n; j++) ret[i * j] += df[j] * ret[i];\n    }\n\
    \    return ret;\n  }\n\n  static vector<int> npf;\n  static vector<int> lpf;\n\
    \  static void calc_lpf(int n) {\n    if (lpf.empty()) {\n      lpf = {0, 1, 2,\
    \ 3, 2, 5, 2, 7};\n      npf = {0, 0, 1, 1, 2, 1, 2, 1};\n    }\n    int l = lpf.size(),\
    \ r = l;\n    while (r <= n) r <<= 1;\n    if (l == r) return;\n    lpf.resize(r);\n\
    \    npf.resize(r);\n    for (int i = 2; i < l; i++) {\n      if (lpf[i] != i)\
    \ continue;\n      for (int j = i * 2; j < r; j += i)\n        if (lpf[j] == 0)\
    \ lpf[j] = i;\n    }\n    for (int i = l; i < r; i++) {\n      if (lpf[i] != 0)\
    \ continue;\n      lpf[i] = i;\n      for (int j = i * 2; j < r; j += i)\n   \
    \     if (lpf[j] == 0) lpf[j] = i;\n    }\n    for (int i = l; i < r; i++)\n \
    \     npf[i] = npf[i / lpf[i]] + 1;\n  }\n};\ntemplate <typename mint>\nvector<mint>\
    \ FormalDirichletSeries<mint>::inv = {};\ntemplate <typename mint>\nvector<int>\
    \ FormalDirichletSeries<mint>::npf = {};\ntemplate <typename mint>\nvector<int>\
    \ FormalDirichletSeries<mint>::lpf = {};\n/**\n * @brief \u5F62\u5F0F\u7684 Dirichlet\
    \ \u7D1A\u6570\n * @docs docs/number-theory/formal-dirichlet-series.md\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: number-theory/formal-dirichlet-series.hpp
  requiredBy: []
  timestamp: '2025-11-20 21:02:27+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: number-theory/formal-dirichlet-series.hpp
layout: document
redirect_from:
- /library/number-theory/formal-dirichlet-series.hpp
- /library/number-theory/formal-dirichlet-series.hpp.html
title: "\u5F62\u5F0F\u7684 Dirichlet \u7D1A\u6570"
---
形式的 Dirichlet 級数ライブラリ．

prefix の具体的な値を管理する．

## 形式的 Dirichlet 級数

$R$ を環とする．

$R$ の数列 $A,B:\mathbb{N}\to R$ の Dirichlet 積 $A*B:\mathbb{N}\to R$ を以下で定める．
$$(A*B)(k)=\sum_{ij=k}A(i)B(j)$$

$R^{\mathbb{N}}$ に対して加算を成分毎の加算，乗算を Dirichlet 積とすると環になる．これを形式的 Dirichlet 級数環と呼ぶことにする．
以下特に断りのない場合積の記号 $*$ は省略する．

Dirichlet 級数の記法を流用し $A\in R^{\mathbb{N}}$ を以下のようにも表す：
$$\sum_{n=1}^{\infty}\frac{A(n)}{n^{-s}}.$$
また $[n^{-s}]A=A(n)$ とする．

この記法を用いれば加法の単位元は $0$，乗法の単位元は $1$ である．
また Dirichlet 級数 $A$ の逆元が存在する必要十分条件は $[1^{-s}]A$ が逆元を持つことである．

## 乗算/除算

$A,B$ の前 $N$ 項がわかっているとき，$AB$ の前 $N$ 項が $O(N\log N)$ 時間で計算できる．

## exp/log

- [https://atcoder.jp/contests/abc428/editorial/14241]

形式的 Dirichlet 級数 $A$ について $[1^{-s}]A$ が適当な条件を満たすとき形式的冪級数 $\exp x,\log x$ との合成によって $\exp A,\log A$ を考えることができる．

$A$ から $\exp A$ や $\log A$ を高速に計算できないだろうか．

ここで $n$ の重複を込めた素因数の個数を $\Omega(n)$ として，演算子 $\mathfrak{D}$ を
$$\mathfrak{D}\left(\sum_{n\geq 1}\frac{a_n}{n^s}\right)=\sum_{n\geq 1}\frac{a_n\Omega(n)}{n^s}$$

によって定める．これは微分に対応する演算になっており，以下の性質を満たす．
- $\mathfrak{D}(A+B)=(\mathfrak{D} A)+(\mathfrak{D} B)$．
- $\mathfrak{D}(AB)=(\mathfrak{D} A)B+A(\mathfrak{D} B)$．
- $\mathfrak{D}(A^k)=k(\mathfrak{D} A)A^{k-1}$．
- 形式的冪級数 $f$ に対し，合成 $f(A)$ が定義されるならば $\mathfrak{D}(f(A))=f'(A)(\mathfrak{D} A)$．

> 逆に上二つの性質を満たす演算子は $\mathfrak{D}(p^{-s})$ を定めれば決まる．
> $\mathfrak{D}(p^{-s})=p^{-s}$ とすれば上記の $\mathfrak{D}$ が得られる．

従って以下が成り立つ．
$$\mathfrak{D}\exp A=(\mathfrak{D} A)\exp A,\quad \mathfrak{D}\log A=\frac{\mathfrak{D} A}{A}$$

これを用いれば $A$ の前 $N$ 項がわかっているとき $\exp,\log$ の前 $N$ 項は $O(N\log N)$ 時間で計算できる．
