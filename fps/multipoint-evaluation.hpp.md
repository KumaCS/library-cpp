---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: fps/formal-power-series.hpp
    title: fps/formal-power-series.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/fps/LC_multipoint_evaluation.test.cpp
    title: verify/fps/LC_multipoint_evaluation.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/fps/LC_multipoint_evaluation_on_geometric_sequence.test.cpp
    title: verify/fps/LC_multipoint_evaluation_on_geometric_sequence.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/fps/UNIT_prefix_sum_of_polynomial.test.cpp
    title: verify/fps/UNIT_prefix_sum_of_polynomial.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/fps/multipoint-evaluation.md
    document_title: Multipoint Evaluation
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
    \ = nullptr;\n#line 3 \"fps/multipoint-evaluation.hpp\"\n\n// f(x0),f(x1),...\n\
    template <class mint>\nvector<mint> MultipointEvaluation(FormalPowerSeries<mint>\
    \ f, const vector<mint>& x) {\n  using fps = FormalPowerSeries<mint>;\n  int m\
    \ = x.size();\n  if (m == 0) return {};\n  vector<fps> prod(2 * m);\n  for (int\
    \ i = 0; i < m; i++) prod[i + m] = {-x[i], 1};\n  for (int i = m - 1; i > 0; i--)\
    \ prod[i] = prod[i * 2] * prod[i * 2 + 1];\n  vector<fps> rem(2 * m);\n  rem[1]\
    \ = f % prod[1];\n  for (int i = 2; i < 2 * m; i++) rem[i] = rem[i / 2] % prod[i];\n\
    \  vector<mint> y(m);\n  for (int i = 0; i < m; i++) y[i] = rem[i + m].empty()\
    \ ? 0 : rem[i + m][0];\n  return y;\n}\n\n// f(a),f(ar),...,f(ar^{n-1})\ntemplate\
    \ <class mint>\nvector<mint> MultipointEvaluationGeometric(FormalPowerSeries<mint>\
    \ f, mint a, mint r, int n) {\n  using fps = FormalPowerSeries<mint>;\n  assert(n\
    \ >= 0);\n  if (n == 0) return {};\n  if (f.empty()) return vector<mint>(n);\n\
    \  mint pa = 1;\n  for (int i = 1; i < f.size(); i++) f[i] *= (pa *= a);\n  if\
    \ (r == 0) {\n    vector<mint> res(n, f[0]);\n    for (int i = 1; i < f.size();\
    \ i++) res[0] += f[i];\n    return res;\n  }\n  mint ir = r.inv();\n  int sz =\
    \ n - 1 + (int)f.size();\n  fps rs(sz, 1), irs(sz, 1);\n  mint pr = 1, pir = 1;\n\
    \  for (int i = 2; i < sz; i++) {\n    rs[i] = rs[i - 1] * (pr *= r);\n    irs[i]\
    \ = irs[i - 1] * (pir *= ir);\n  }\n  for (int i = 0; i < f.size(); i++) f[i]\
    \ *= irs[i];\n  f = f.middle_product(rs);\n  for (int i = 0; i < f.size(); i++)\
    \ f[i] *= irs[i];\n  return f;\n}\n\n/**\n * @brief Multipoint Evaluation\n *\
    \ @docs docs/fps/multipoint-evaluation.md\n */\n"
  code: "#pragma once\n#include \"fps/formal-power-series.hpp\"\n\n// f(x0),f(x1),...\n\
    template <class mint>\nvector<mint> MultipointEvaluation(FormalPowerSeries<mint>\
    \ f, const vector<mint>& x) {\n  using fps = FormalPowerSeries<mint>;\n  int m\
    \ = x.size();\n  if (m == 0) return {};\n  vector<fps> prod(2 * m);\n  for (int\
    \ i = 0; i < m; i++) prod[i + m] = {-x[i], 1};\n  for (int i = m - 1; i > 0; i--)\
    \ prod[i] = prod[i * 2] * prod[i * 2 + 1];\n  vector<fps> rem(2 * m);\n  rem[1]\
    \ = f % prod[1];\n  for (int i = 2; i < 2 * m; i++) rem[i] = rem[i / 2] % prod[i];\n\
    \  vector<mint> y(m);\n  for (int i = 0; i < m; i++) y[i] = rem[i + m].empty()\
    \ ? 0 : rem[i + m][0];\n  return y;\n}\n\n// f(a),f(ar),...,f(ar^{n-1})\ntemplate\
    \ <class mint>\nvector<mint> MultipointEvaluationGeometric(FormalPowerSeries<mint>\
    \ f, mint a, mint r, int n) {\n  using fps = FormalPowerSeries<mint>;\n  assert(n\
    \ >= 0);\n  if (n == 0) return {};\n  if (f.empty()) return vector<mint>(n);\n\
    \  mint pa = 1;\n  for (int i = 1; i < f.size(); i++) f[i] *= (pa *= a);\n  if\
    \ (r == 0) {\n    vector<mint> res(n, f[0]);\n    for (int i = 1; i < f.size();\
    \ i++) res[0] += f[i];\n    return res;\n  }\n  mint ir = r.inv();\n  int sz =\
    \ n - 1 + (int)f.size();\n  fps rs(sz, 1), irs(sz, 1);\n  mint pr = 1, pir = 1;\n\
    \  for (int i = 2; i < sz; i++) {\n    rs[i] = rs[i - 1] * (pr *= r);\n    irs[i]\
    \ = irs[i - 1] * (pir *= ir);\n  }\n  for (int i = 0; i < f.size(); i++) f[i]\
    \ *= irs[i];\n  f = f.middle_product(rs);\n  for (int i = 0; i < f.size(); i++)\
    \ f[i] *= irs[i];\n  return f;\n}\n\n/**\n * @brief Multipoint Evaluation\n *\
    \ @docs docs/fps/multipoint-evaluation.md\n */"
  dependsOn:
  - fps/formal-power-series.hpp
  isVerificationFile: false
  path: fps/multipoint-evaluation.hpp
  requiredBy: []
  timestamp: '2025-10-21 21:13:36+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/fps/LC_multipoint_evaluation_on_geometric_sequence.test.cpp
  - verify/fps/UNIT_prefix_sum_of_polynomial.test.cpp
  - verify/fps/LC_multipoint_evaluation.test.cpp
documentation_of: fps/multipoint-evaluation.hpp
layout: document
redirect_from:
- /library/fps/multipoint-evaluation.hpp
- /library/fps/multipoint-evaluation.hpp.html
title: Multipoint Evaluation
---
多点評価．

$n$ 次の多項式 $f$ に対し $f(x_1),f(x_2),\dots,f(x_m)$ を $O(m(\log m)^2+n\log n)$ 時間で求める．

また評価点が等比数列 $a,ar,\dots,ar^{m-1}$ の場合には $O(m\log m+n\log n)$ 時間で求められる（chirp z-transform）．

## アルゴリズム

### 一般

剰余の定理により $f(x)\bmod (x-x_i)$ を求めればよく，ダブリングすればよい．

- 参考：[Multipoint Evaluation の アルゴリズム - 37zigenのHP](https://37zigen.com/multipoint-evaluation/)

転置原理を用いることで定数倍のよりよい実装が得られるらしいが未実装．

- 参考：[転置原理まとめ - Mathenachia](https://www.mathenachia.blog/tellegens)

### 等比数列

chirp z-transform と呼ばれる変換で，DFT の一般化になっている．

$f=\sum_{i=0}^{n-1}f_ix^i$ とおくと，$j$ について列挙したい値は以下のように変形できる．

$$\begin{align*}
f(ar^j)
&=\sum_{i=0}^{n-1}f_ia^ir^{ij}\\
&=\sum_{i=0}^{n-1}f_ia^ir^{\binom{i+j}{2}-\binom{i}{2}-\binom{j}{2}}\\
&=r^{-\binom{j}{2}}\sum_{i=0}^{n-1}r^{\binom{i+j}{2}}f_ia^ir^{-\binom{i}{2}}
\end{align*}$$

middle product で $O((n+m)\log(n+m))$ 時間．