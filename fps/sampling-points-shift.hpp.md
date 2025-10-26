---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: fps/formal-power-series.hpp
    title: fps/formal-power-series.hpp
  - icon: ':question:'
    path: modint/factorial.hpp
    title: "\u968E\u4E57, \u4E8C\u9805\u4FC2\u6570"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/fps/LC_shift_of_sampling_points_of_polynomial.test.cpp
    title: verify/fps/LC_shift_of_sampling_points_of_polynomial.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/fps/sampling-points-shift.md
    document_title: "\u8A55\u4FA1\u70B9\u30B7\u30D5\u30C8"
    links: []
  bundledCode: "#line 2 \"modint/factorial.hpp\"\n\ntemplate <class mint>\nstruct\
    \ Factorial {\n  static void reserve(int n) {\n    inv(n);\n    fact(n);\n   \
    \ fact_inv(n);\n  }\n  static mint inv(int n) {\n    static long long mod = mint::get_mod();\n\
    \    static vector<mint> buf({0, 1});\n    assert(n != 0);\n    if (mod != mint::get_mod())\
    \ {\n      mod = mint::get_mod();\n      buf = vector<mint>({0, 1});\n    }\n\
    \    while ((int)buf.capacity() <= n) buf.reserve(buf.capacity() * 2);\n    while\
    \ ((int)buf.size() <= n) {\n      long long k = buf.size(), q = (mod + k - 1)\
    \ / k;\n      buf.push_back(q * buf[k * q - mod]);\n    }\n    return buf[n];\n\
    \  }\n  static mint fact(int n) {\n    static long long mod = mint::get_mod();\n\
    \    static vector<mint> buf({1, 1});\n    assert(n >= 0);\n    if (mod != mint::get_mod())\
    \ {\n      mod = mint::get_mod();\n      buf = vector<mint>({1, 1});\n    }\n\
    \    while ((int)buf.capacity() <= n) buf.reserve(buf.capacity() * 2);\n    while\
    \ ((int)buf.size() <= n) {\n      long long k = buf.size();\n      buf.push_back(buf.back()\
    \ * k);\n    }\n    return buf[n];\n  }\n  static mint fact_inv(int n) {\n   \
    \ static long long mod = mint::get_mod();\n    static vector<mint> buf({1, 1});\n\
    \    assert(n >= 0);\n    if (mod != mint::get_mod()) {\n      mod = mint::get_mod();\n\
    \      buf = vector<mint>({1, 1});\n    }\n    if ((int)buf.size() <= n) inv(n);\n\
    \    while ((int)buf.capacity() <= n) buf.reserve(buf.capacity() * 2);\n    while\
    \ ((int)buf.size() <= n) {\n      long long k = buf.size();\n      buf.push_back(buf.back()\
    \ * inv(k));\n    }\n    return buf[n];\n  }\n  static mint binom(int n, int r)\
    \ {\n    if (r < 0 || r > n) return 0;\n    return fact(n) * fact_inv(r) * fact_inv(n\
    \ - r);\n  }\n  static mint binom_naive(int n, int r) {\n    if (r < 0 || r >\
    \ n) return 0;\n    mint res = fact_inv(r);\n    for (int i = 0; i < r; i++) res\
    \ *= n - i;\n    return res;\n  }\n  static mint multinom(const vector<int>& r)\
    \ {\n    int n = 0;\n    for (auto& x : r) {\n      if (x < 0) return 0;\n   \
    \   n += x;\n    }\n    mint res = fact(n);\n    for (auto& x : r) res *= fact_inv(x);\n\
    \    return res;\n  }\n  static mint P(int n, int r) {\n    if (r < 0 || r > n)\
    \ return 0;\n    return fact(n) * fact_inv(n - r);\n  }\n  // partition n items\
    \ to r groups (allow empty group)\n  static mint H(int n, int r) {\n    if (n\
    \ < 0 || r < 0) return 0;\n    return r == 0 ? 1 : binom(n + r - 1, r);\n  }\n\
    };\n/**\n * @brief \u968E\u4E57, \u4E8C\u9805\u4FC2\u6570\n */\n#line 2 \"fps/formal-power-series.hpp\"\
    \n\ntemplate <class mint>\nstruct FormalPowerSeries : vector<mint> {\n  using\
    \ vector<mint>::vector;\n  using FPS = FormalPowerSeries;\n  FPS &operator+=(const\
    \ FPS &r) {\n    if (r.size() > this->size()) this->resize(r.size());\n    for\
    \ (int i = 0; i < (int)r.size(); i++) (*this)[i] += r[i];\n    return *this;\n\
    \  }\n  FPS &operator+=(const mint &r) {\n    if (this->empty()) this->resize(1);\n\
    \    (*this)[0] += r;\n    return *this;\n  }\n  FPS &operator-=(const FPS &r)\
    \ {\n    if (r.size() > this->size()) this->resize(r.size());\n    for (int i\
    \ = 0; i < (int)r.size(); i++) (*this)[i] -= r[i];\n    return *this;\n  }\n \
    \ FPS &operator-=(const mint &r) {\n    if (this->empty()) this->resize(1);\n\
    \    (*this)[0] -= r;\n    return *this;\n  }\n  FPS &operator*=(const mint &v)\
    \ {\n    for (int k = 0; k < (int)this->size(); k++) (*this)[k] *= v;\n    return\
    \ *this;\n  }\n  FPS &operator/=(const FPS &r) {\n    if (this->size() < r.size())\
    \ {\n      this->clear();\n      return *this;\n    }\n    int n = this->size()\
    \ - r.size() + 1;\n    if ((int)r.size() <= 64) {\n      FPS f(*this), g(r);\n\
    \      g.shrink();\n      mint coeff = g.at(g.size() - 1).inv();\n      for (auto\
    \ &x : g) x *= coeff;\n      int deg = (int)f.size() - (int)g.size() + 1;\n  \
    \    int gs = g.size();\n      FPS quo(deg);\n      for (int i = deg - 1; i >=\
    \ 0; i--) {\n        quo[i] = f[i + gs - 1];\n        for (int j = 0; j < gs;\
    \ j++) f[i + j] -= quo[i] * g[j];\n      }\n      *this = quo * coeff;\n     \
    \ this->resize(n, mint(0));\n      return *this;\n    }\n    return *this = ((*this).rev().pre(n)\
    \ * r.rev().inv(n)).pre(n).rev();\n  }\n  FPS &operator%=(const FPS &r) {\n  \
    \  *this -= *this / r * r;\n    shrink();\n    return *this;\n  }\n  FPS operator+(const\
    \ FPS &r) const { return FPS(*this) += r; }\n  FPS operator+(const mint &v) const\
    \ { return FPS(*this) += v; }\n  FPS operator-(const FPS &r) const { return FPS(*this)\
    \ -= r; }\n  FPS operator-(const mint &v) const { return FPS(*this) -= v; }\n\
    \  FPS operator*(const FPS &r) const { return FPS(*this) *= r; }\n  FPS operator*(const\
    \ mint &v) const { return FPS(*this) *= v; }\n  FPS operator/(const FPS &r) const\
    \ { return FPS(*this) /= r; }\n  FPS operator%(const FPS &r) const { return FPS(*this)\
    \ %= r; }\n  FPS operator-() const {\n    FPS ret(this->size());\n    for (int\
    \ i = 0; i < (int)this->size(); i++) ret[i] = -(*this)[i];\n    return ret;\n\
    \  }\n  void shrink() {\n    while (this->size() && this->back() == mint(0)) this->pop_back();\n\
    \  }\n  FPS rev() const {\n    FPS ret(*this);\n    reverse(begin(ret), end(ret));\n\
    \    return ret;\n  }\n  FPS dot(FPS r) const {\n    FPS ret(min(this->size(),\
    \ r.size()));\n    for (int i = 0; i < (int)ret.size(); i++) ret[i] = (*this)[i]\
    \ * r[i];\n    return ret;\n  }\n  FPS pre(int sz) const {\n    return FPS(begin(*this),\
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
    \ = nullptr;\n#line 4 \"fps/sampling-points-shift.hpp\"\n\n// f(0),f(1),...,f(n-1)\
    \ -> f(c),...,f(c+m-1)\ntemplate <class mint>\nvector<mint> SamplingPointsShift(const\
    \ vector<mint>& f, mint c, int m) {\n  using fps = FormalPowerSeries<mint>;\n\
    \  using fact = Factorial<mint>;\n  int n = f.size();\n  fact::reserve(m);\n \
    \ fps f1(n), ei(n);\n  for (int i = 0; i < n; i++) f1[i] = f[i] * fact::fact_inv(i);\n\
    \  for (int i = 0; i < n; i++) ei[i] = fact::fact_inv(i) * (i % 2 ? -1 : 1);\n\
    \  f1 *= ei;\n  for (int i = n; i < f1.size(); i++) f1[i] = 0;\n  for (int i =\
    \ 0; i < n; i++) f1[i] *= fact::fact(i);\n  fps g(n, 1);\n  for (int i = 1; i\
    \ < n; i++) g[i] = g[i - 1] * (c + 1 - i) * fact::inv(i);\n  g = g.middle_product(f1);\n\
    \  for (int i = 0; i < n; i++) g[i] *= fact::fact_inv(i);\n  fps e(m);\n  for\
    \ (int i = 0; i < m; i++) e[i] = fact::fact_inv(i);\n  g *= e;\n  g.resize(m);\n\
    \  for (int i = 0; i < m; i++) g[i] *= fact::fact(i);\n  return g;\n}\n/**\n *\
    \ @brief \u8A55\u4FA1\u70B9\u30B7\u30D5\u30C8\n * @docs docs/fps/sampling-points-shift.md\n\
    \ */\n"
  code: "#pragma once\n#include \"modint/factorial.hpp\"\n#include \"fps/formal-power-series.hpp\"\
    \n\n// f(0),f(1),...,f(n-1) -> f(c),...,f(c+m-1)\ntemplate <class mint>\nvector<mint>\
    \ SamplingPointsShift(const vector<mint>& f, mint c, int m) {\n  using fps = FormalPowerSeries<mint>;\n\
    \  using fact = Factorial<mint>;\n  int n = f.size();\n  fact::reserve(m);\n \
    \ fps f1(n), ei(n);\n  for (int i = 0; i < n; i++) f1[i] = f[i] * fact::fact_inv(i);\n\
    \  for (int i = 0; i < n; i++) ei[i] = fact::fact_inv(i) * (i % 2 ? -1 : 1);\n\
    \  f1 *= ei;\n  for (int i = n; i < f1.size(); i++) f1[i] = 0;\n  for (int i =\
    \ 0; i < n; i++) f1[i] *= fact::fact(i);\n  fps g(n, 1);\n  for (int i = 1; i\
    \ < n; i++) g[i] = g[i - 1] * (c + 1 - i) * fact::inv(i);\n  g = g.middle_product(f1);\n\
    \  for (int i = 0; i < n; i++) g[i] *= fact::fact_inv(i);\n  fps e(m);\n  for\
    \ (int i = 0; i < m; i++) e[i] = fact::fact_inv(i);\n  g *= e;\n  g.resize(m);\n\
    \  for (int i = 0; i < m; i++) g[i] *= fact::fact(i);\n  return g;\n}\n/**\n *\
    \ @brief \u8A55\u4FA1\u70B9\u30B7\u30D5\u30C8\n * @docs docs/fps/sampling-points-shift.md\n\
    \ */"
  dependsOn:
  - modint/factorial.hpp
  - fps/formal-power-series.hpp
  isVerificationFile: false
  path: fps/sampling-points-shift.hpp
  requiredBy: []
  timestamp: '2025-10-26 03:52:03+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/fps/LC_shift_of_sampling_points_of_polynomial.test.cpp
documentation_of: fps/sampling-points-shift.hpp
layout: document
redirect_from:
- /library/fps/sampling-points-shift.hpp
- /library/fps/sampling-points-shift.hpp.html
title: "\u8A55\u4FA1\u70B9\u30B7\u30D5\u30C8"
---
以下の問題を $O((N+M)\log(N+M))$ 時間で解く．

> 次数 $N$ 未満の多項式 $f(x)$ について $f(0),f(1),\dots,f(N-1)$ が与えられる．
> $f(c),f(c+1),\dots,f(c+M-1)$ を列挙せよ．

## アルゴリズム

下降階乗冪を用いて $f(x)=\sum_{i=0}^{N-1}a_ix^{\underline{i}}$ とおくと $0\leq i\lt N$ に対し

$$f(k)=k!\sum_{i=0}^{k}\frac{a_i}{(k-i)!}$$

が成り立つため，$a_i$ は

$$a_i=[x^i]e^{-x}\sum_{k=0}^{N-1}\frac{f(k)}{k!}x^k$$

として計算できる．

また下降階乗冪について $(a+b)^{\underline{n}}=\sum_{i=0}^{n}\binom{n}{i}a^{\underline{i}}b^{\underline{n-i}}$ が成り立つため，$f(x+c)=\sum_{i=0}^{N-1}b_ix^{\underline{i}}$ とおくと

$$b_i=\frac{1}{i!}\sum_{j}(i+j)!a_{i+j}\cdot\frac{c^{\underline{j}}}{j!}$$

が成り立つ．あとは $a_i$ の計算の逆をすればよい．