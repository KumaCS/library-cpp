---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: fps/formal-power-series.hpp
    title: fps/formal-power-series.hpp
  - icon: ':heavy_check_mark:'
    path: modint/factorial.hpp
    title: "\u968E\u4E57, \u4E8C\u9805\u4FC2\u6570"
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: fps/compositional-inv.hpp
    title: "\u9006\u95A2\u6570"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/fps/LC_compositional_inverse_of_formal_power_series.test.cpp
    title: verify/fps/LC_compositional_inverse_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/fps/LC_compositional_inverse_of_formal_power_series_large.test.cpp
    title: verify/fps/LC_compositional_inverse_of_formal_power_series_large.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/fps/power-projection.md
    document_title: Power Projection
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
    \ = nullptr;\n#line 2 \"modint/factorial.hpp\"\n\ntemplate <class mint>\nstruct\
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
    };\n/**\n * @brief \u968E\u4E57, \u4E8C\u9805\u4FC2\u6570\n */\n#line 4 \"fps/power-projection.hpp\"\
    \n\n// transpose of composition\n// [x^0]f(x^{-1})g(x)^i, i=0,...,n-1\n// O(n(log\
    \ n)^2)\ntemplate <class mint>\nFormalPowerSeries<mint> TransposedComposition(FormalPowerSeries<mint>\
    \ f, FormalPowerSeries<mint> g, int n) {\n  if (g[0] != 0) {\n    mint c = g[0];\n\
    \    g[0] = 0;\n    auto h1 = TransposedComposition(f, g, n);\n    using fact\
    \ = Factorial<mint>;\n    for (int i = 0; i < n; i++) h1[i] *= fact::fact_inv(i);\n\
    \    FormalPowerSeries<mint> h2(n);\n    h2[0] = 1;\n    for (int i = 1; i < n;\
    \ i++) h2[i] = h2[i - 1] * c;\n    for (int i = 0; i < n; i++) h2[i] *= fact::fact_inv(i);\n\
    \    h1 *= h2;\n    h1.resize(n);\n    for (int i = 0; i < n; i++) h1[i] *= fact::fact(i);\n\
    \    return h1;\n  }\n\n  int k = 1;\n  while (k < f.size() || k < n) k <<= 1;\n\
    \  int l = 1, m = 2 * k * l;\n  FormalPowerSeries<mint> P(m), Q(m);\n  for (int\
    \ i = 0; i < f.size(); i++) P[k - 1 - i] = f[i];\n  for (int i = 0; i < g.size()\
    \ && i < k; i++) Q[i] = -g[i];\n  int log = __builtin_ctz((unsigned int)m);\n\
    \  mint wi = mint(FormalPowerSeries<mint>::ntt_root()).inv().pow((mint::get_mod()\
    \ - 1) >> (log + 1));\n  vector<int> rev(m);\n  for (int i = 0; i < rev.size();\
    \ i++) rev[i] = (rev[i / 2] / 2) | ((i & 1) << (log - 1));\n  vector<mint> pow(m,\
    \ 1);\n  for (int i = 1; i < m; i++) pow[rev[i]] = pow[rev[i - 1]] * wi;\n  mint\
    \ inv2 = mint(2).inv();\n  \n  while (k > 1) {\n    P.resize(2 * m), P.ntt();\n\
    \    Q.resize(2 * m), Q.ntt();\n    for (int i = 0; i < m; i++) {\n      mint\
    \ b = (i >> (log - 1)) == 0 ? 1 : -1;\n      int j = i << 1;\n      P[i] = pow[i]\
    \ * (P[j] * (Q[j ^ 1] + b) - P[j ^ 1] * (Q[j] + b)) * inv2;\n      Q[i] = Q[j]\
    \ * Q[j ^ 1] + (Q[j] + Q[j ^ 1]) * b;\n    }\n    P.resize(m), P.intt();\n   \
    \ Q.resize(m), Q.intt();\n    k >>= 1, l <<= 1;\n    for (int i = k; i < k * 2;\
    \ i++)\n      for (int j = 0; j < l; j++) {\n        P[i + j * k * 2] = 0;\n \
    \       Q[i + j * k * 2] = 0;\n      }\n  }\n  FormalPowerSeries<mint> P1(n);\n\
    \  for (int i = 0; i < n; i++) P1[i] = P[(l - 1 - i) * 2];\n  return P1;\n}\n\n\
    // [x^k]f(x)g(x)^0,...,f(x)g(x)^(n-1)\n// O((n+k)log^2(n+k))\ntemplate <class\
    \ mint>\nvector<mint> PowerProjection(FormalPowerSeries<mint> f, FormalPowerSeries<mint>\
    \ g, int k, int n) {\n  assert(n >= 0 && k >= 0);\n  if (n == 0) return {};\n\
    \  f.resize(k + 1);\n  f = f.rev();\n  return TransposedComposition(f, g, n);\n\
    }\n/**\n * @brief Power Projection\n * @docs docs/fps/power-projection.md\n */\n"
  code: "#pragma once\n#include \"fps/formal-power-series.hpp\"\n#include \"modint/factorial.hpp\"\
    \n\n// transpose of composition\n// [x^0]f(x^{-1})g(x)^i, i=0,...,n-1\n// O(n(log\
    \ n)^2)\ntemplate <class mint>\nFormalPowerSeries<mint> TransposedComposition(FormalPowerSeries<mint>\
    \ f, FormalPowerSeries<mint> g, int n) {\n  if (g[0] != 0) {\n    mint c = g[0];\n\
    \    g[0] = 0;\n    auto h1 = TransposedComposition(f, g, n);\n    using fact\
    \ = Factorial<mint>;\n    for (int i = 0; i < n; i++) h1[i] *= fact::fact_inv(i);\n\
    \    FormalPowerSeries<mint> h2(n);\n    h2[0] = 1;\n    for (int i = 1; i < n;\
    \ i++) h2[i] = h2[i - 1] * c;\n    for (int i = 0; i < n; i++) h2[i] *= fact::fact_inv(i);\n\
    \    h1 *= h2;\n    h1.resize(n);\n    for (int i = 0; i < n; i++) h1[i] *= fact::fact(i);\n\
    \    return h1;\n  }\n\n  int k = 1;\n  while (k < f.size() || k < n) k <<= 1;\n\
    \  int l = 1, m = 2 * k * l;\n  FormalPowerSeries<mint> P(m), Q(m);\n  for (int\
    \ i = 0; i < f.size(); i++) P[k - 1 - i] = f[i];\n  for (int i = 0; i < g.size()\
    \ && i < k; i++) Q[i] = -g[i];\n  int log = __builtin_ctz((unsigned int)m);\n\
    \  mint wi = mint(FormalPowerSeries<mint>::ntt_root()).inv().pow((mint::get_mod()\
    \ - 1) >> (log + 1));\n  vector<int> rev(m);\n  for (int i = 0; i < rev.size();\
    \ i++) rev[i] = (rev[i / 2] / 2) | ((i & 1) << (log - 1));\n  vector<mint> pow(m,\
    \ 1);\n  for (int i = 1; i < m; i++) pow[rev[i]] = pow[rev[i - 1]] * wi;\n  mint\
    \ inv2 = mint(2).inv();\n  \n  while (k > 1) {\n    P.resize(2 * m), P.ntt();\n\
    \    Q.resize(2 * m), Q.ntt();\n    for (int i = 0; i < m; i++) {\n      mint\
    \ b = (i >> (log - 1)) == 0 ? 1 : -1;\n      int j = i << 1;\n      P[i] = pow[i]\
    \ * (P[j] * (Q[j ^ 1] + b) - P[j ^ 1] * (Q[j] + b)) * inv2;\n      Q[i] = Q[j]\
    \ * Q[j ^ 1] + (Q[j] + Q[j ^ 1]) * b;\n    }\n    P.resize(m), P.intt();\n   \
    \ Q.resize(m), Q.intt();\n    k >>= 1, l <<= 1;\n    for (int i = k; i < k * 2;\
    \ i++)\n      for (int j = 0; j < l; j++) {\n        P[i + j * k * 2] = 0;\n \
    \       Q[i + j * k * 2] = 0;\n      }\n  }\n  FormalPowerSeries<mint> P1(n);\n\
    \  for (int i = 0; i < n; i++) P1[i] = P[(l - 1 - i) * 2];\n  return P1;\n}\n\n\
    // [x^k]f(x)g(x)^0,...,f(x)g(x)^(n-1)\n// O((n+k)log^2(n+k))\ntemplate <class\
    \ mint>\nvector<mint> PowerProjection(FormalPowerSeries<mint> f, FormalPowerSeries<mint>\
    \ g, int k, int n) {\n  assert(n >= 0 && k >= 0);\n  if (n == 0) return {};\n\
    \  f.resize(k + 1);\n  f = f.rev();\n  return TransposedComposition(f, g, n);\n\
    }\n/**\n * @brief Power Projection\n * @docs docs/fps/power-projection.md\n */"
  dependsOn:
  - fps/formal-power-series.hpp
  - modint/factorial.hpp
  isVerificationFile: false
  path: fps/power-projection.hpp
  requiredBy:
  - fps/compositional-inv.hpp
  timestamp: '2025-10-31 21:40:36+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/fps/LC_compositional_inverse_of_formal_power_series_large.test.cpp
  - verify/fps/LC_compositional_inverse_of_formal_power_series.test.cpp
documentation_of: fps/power-projection.hpp
layout: document
redirect_from:
- /library/fps/power-projection.hpp
- /library/fps/power-projection.hpp.html
title: Power Projection
---
多項式 $f,g$ に対して $h_i=[x^k]f(x)g(x)^i$ とする．

$h_0,h_1,\dots,h_n$ を $O((n+k)(\log(n+k))^2)$ 時間で列挙する．

FPS の合成アルゴリズムである Kinoshita-Li 合成は FPS の合成の転置問題が power projection であることに基づいている．

- Yasunori Kinoshita and Baitian Li, Power Series Composition in Near-Linear Time, 2024 (https://arxiv.org/abs/2404.05177)

## アルゴリズム

$[x^0]g(x)=c$ とすれば以下が成り立つ．

$$h_i=\sum_{j}\binom{i}{j}c^{i-j}\cdot[x^k]f(x)(g(x)-c)^j$$

よって $[x^k]f(x)(g(x)-c)^i$ を列挙できれば，$h_i$ は畳み込みにより $O(k\log k)$ 時間で計算できる．

以下 $[x^0]g(x)=0$ であると仮定する．二変数 FPS として $h_i$ は次のように表現できる．

$$h_i=[x^ky^i]\frac{f(x)}{1-g(x)y}$$

$y$ についての FPS である $[x^k]\frac{f(x)}{1-g(x)y}$ が求められればよい．

Bostan-Mori 法の適用を考えると，イテレーション毎に $x$ の次数が半減，$y$ の次数が倍増するため，結局 $x$ の次数と $y$ の次数の積は $O(n+k)$ であり各イテレーションは $O((n+k)\log(n+k))$ 時間で行える．

従って全体では $O((n+k)(\log (n+k))^2)$ 時間で解ける．

## FFT 回数の削減

$h_i=[x^{k-1}]\cdots$ および $k$ が二冪であると仮定して構わない．
こうすると Bostan-Mori のイテレーション内で考えるべき $x$ の次数が常に奇数になる．

また分母が $1+y\cdot hoge$ の形であるのは扱いづらいので $y$ について reverse して考える．
すなわち $\frac{f(x)}{y-g(x)}$ についての Bostan-Mori を考える．

このときイテレーションにおいて出てくる形は $[x^{k-1}]\frac{p(x,y)}{y^l+q(x,y)}$ とおける．
ここで $k,l$ は二冪であり $p,q$ 共に $x$ の次数は $k$ 未満，$y$ の次数は $l$ 未満である．

$k=1$ のとき，仮定 $[x^0]g(x)=0$ より $[x^0]q(x,y)=0$ が成り立つため，$y$ の reverse を考慮すれば $[x^0]y^{l-1}p(x,y^{-1})$ が求めたいものである．

$k\geq 2$ のとき，まず分母の遷移を考える．
$(y^l+q(x,y))(y^l+q(-x,y))=y^{2l}+q'(x^2,y)$ とおくと

$$q'(x^2,y)=q(x,y)q(-x,y)+(q(x,y)+q(-x,y))y^l$$

である．
$m=2kl$ として $1$ の原始 $2m$ 乗根 $\omega$ をとり，$x=\omega,y=\omega^{2k}$ とすれば以下が成り立つ．

$$q'(\omega^{2i},\omega^{2ki})=q(\omega^i,\omega^{2ki})q(-\omega^i,\omega^{2ki})+(q(\omega^i,\omega^{2ki})+q(-\omega^i,\omega^{2ki}))\omega^{2kli}$$

$q(-\omega^i,\omega^{2ki})=q(\omega^{i+m},\omega^{2k(i+m)})$，また $\omega^{2kl}=\omega^m=-1$ であるから，左辺の値は $q(t,t^{2k})$ に対し長さ $2m$ の FFT を行うことで求められる．
また $q'$ において $x$ の次数は $k/2$ 未満，$y$ の次数は $2l$ 未満であるから，左辺を求めた上で長さ $m$ の IFFT を行うことで $q'(t,t^k)$ が得られる．

分母についても同様に考えられる．