---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: fps/formal-power-series.hpp
    title: fps/formal-power-series.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/fps/LC_inv_of_polynomials.test.cpp
    title: verify/fps/LC_inv_of_polynomials.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/fps/polynomial-gcd.md
    document_title: Polynomial Gcd
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
    \ = nullptr;\n#line 3 \"fps/polynomial-gcd.hpp\"\n\nnamespace polynomial_gcd {\n\
    template <class mint>\nusing FPS = FormalPowerSeries<mint>;\ntemplate <class mint>\n\
    using P = pair<FPS<mint>, FPS<mint>>;\ntemplate <class mint>\nstruct Mat {\n \
    \ using fps = FPS<mint>;\n  fps a00, a01, a10, a11;\n  Mat() = default;\n  Mat(const\
    \ fps& a00_, const fps& a01_, const fps& a10_, const fps& a11_) : a00(a00_), a01(a01_),\
    \ a10(a10_), a11(a11_) {}\n  Mat& operator*=(const Mat& r) {\n    fps b00 = a00\
    \ * r.a00 + a01 * r.a10;\n    fps b01 = a00 * r.a01 + a01 * r.a11;\n    fps b10\
    \ = a10 * r.a00 + a11 * r.a10;\n    fps b11 = a10 * r.a01 + a11 * r.a11;\n   \
    \ swap(a00, b00);\n    swap(a01, b01);\n    swap(a10, b10);\n    swap(a11, b11);\n\
    \    a00.shrink();\n    a01.shrink();\n    a10.shrink();\n    a11.shrink();\n\
    \    return *this;\n  }\n  static Mat I() { return Mat(fps{mint(1)}, fps(), fps(),\
    \ fps{mint(1)}); }\n  Mat operator*(const Mat& r) const { return Mat(*this) *=\
    \ r; }\n};\ntemplate <typename mint>\nP<mint> operator*(const Mat<mint>& m, const\
    \ P<mint>& a) {\n  using fps = FPS<mint>;\n  fps b0 = m.a00 * a.first + m.a01\
    \ * a.second;\n  fps b1 = m.a10 * a.first + m.a11 * a.second;\n  b0.shrink();\n\
    \  b1.shrink();\n  return {b0, b1};\n};\n\ntemplate <class mint>\nvoid StepGCD(Mat<mint>&\
    \ mat, P<mint>& p) {\n  auto q = p.first / p.second;\n  mat.a00 -= mat.a10 * q,\
    \ mat.a00.shrink();\n  mat.a01 -= mat.a11 * q, mat.a01.shrink();\n  swap(mat.a00,\
    \ mat.a10);\n  swap(mat.a01, mat.a11);\n  p.first -= p.second * q, p.first.shrink();\n\
    \  swap(p.first, p.second);\n}\ntemplate <class mint>\nMat<mint> HalfGCD(P<mint>\
    \ p) {\n  int n = (int)p.first.size() - 1, m = (int)p.second.size() - 1;\n  int\
    \ k = n / 2 + 1;\n  if (m < k) return Mat<mint>::I();\n  auto mat = HalfGCD(P<mint>{p.first\
    \ >> k, p.second >> k});\n  p = mat * p;\n  if (p.second.size() <= k) return mat;\n\
    \  StepGCD(mat, p);\n  if (p.second.size() <= k) return mat;\n  int l = 2 * k\
    \ - ((int)p.first.size() - 1);\n  return HalfGCD(P<mint>{p.first >> l, p.second\
    \ >> l}) * mat;\n}\ntemplate <class mint>\nMat<mint> ExtGCD(const FPS<mint>& f,\
    \ const FPS<mint>& g) {\n  P<mint> p{f, g};\n  p.first.shrink();\n  p.second.shrink();\n\
    \  if (p.first.size() < p.second.size()) {\n    auto mat = ExtGCD(p.second, p.first);\n\
    \    swap(mat.a00, mat.a01);\n    swap(mat.a10, mat.a11);\n    return mat;\n \
    \ }\n  auto res = Mat<mint>::I();\n  if (p.second.empty()) return res;\n  while\
    \ (true) {\n    Mat<mint> mat = HalfGCD(p);\n    p = mat * p;\n    if (p.second.empty())\
    \ return mat * res;\n    StepGCD(mat, p);\n    if (p.second.empty()) return mat\
    \ * res;\n    res = mat * res;\n  }\n}\n\ntemplate <class mint>\nFPS<mint> PolynomialGcd(FPS<mint>\
    \ f, FPS<mint> g) {\n  auto m = ExtGCD(f, g);\n  auto h = m.a00 * f + m.a01 *\
    \ g;\n  h.shrink();\n  if (!h.empty()) {\n    mint c = h.back().inv();\n    for\
    \ (auto& v : h) v *= c;\n  }\n  return h;\n}\n// f*h=1 (mod g)\ntemplate <class\
    \ mint>\noptional<FPS<mint>> PolynomialInv(FPS<mint> f, FPS<mint> g) {\n  auto\
    \ m = ExtGCD(f, g);\n  auto gcd = m.a00 * f + m.a01 * g;\n  gcd.shrink();\n  if\
    \ (gcd.size() != 1) return nullopt;\n  mint c = gcd[0].inv();\n  auto h = m.a00;\n\
    \  for (auto& v : h) v *= c;\n  return h;\n}\n};  // namespace polynomial_gcd\n\
    using polynomial_gcd::PolynomialGcd;\nusing polynomial_gcd::PolynomialInv;\n/**\n\
    \ * @brief Polynomial Gcd\n * @docs docs/fps/polynomial-gcd.md\n */\n"
  code: "#pragma once\n#include \"fps/formal-power-series.hpp\"\n\nnamespace polynomial_gcd\
    \ {\ntemplate <class mint>\nusing FPS = FormalPowerSeries<mint>;\ntemplate <class\
    \ mint>\nusing P = pair<FPS<mint>, FPS<mint>>;\ntemplate <class mint>\nstruct\
    \ Mat {\n  using fps = FPS<mint>;\n  fps a00, a01, a10, a11;\n  Mat() = default;\n\
    \  Mat(const fps& a00_, const fps& a01_, const fps& a10_, const fps& a11_) : a00(a00_),\
    \ a01(a01_), a10(a10_), a11(a11_) {}\n  Mat& operator*=(const Mat& r) {\n    fps\
    \ b00 = a00 * r.a00 + a01 * r.a10;\n    fps b01 = a00 * r.a01 + a01 * r.a11;\n\
    \    fps b10 = a10 * r.a00 + a11 * r.a10;\n    fps b11 = a10 * r.a01 + a11 * r.a11;\n\
    \    swap(a00, b00);\n    swap(a01, b01);\n    swap(a10, b10);\n    swap(a11,\
    \ b11);\n    a00.shrink();\n    a01.shrink();\n    a10.shrink();\n    a11.shrink();\n\
    \    return *this;\n  }\n  static Mat I() { return Mat(fps{mint(1)}, fps(), fps(),\
    \ fps{mint(1)}); }\n  Mat operator*(const Mat& r) const { return Mat(*this) *=\
    \ r; }\n};\ntemplate <typename mint>\nP<mint> operator*(const Mat<mint>& m, const\
    \ P<mint>& a) {\n  using fps = FPS<mint>;\n  fps b0 = m.a00 * a.first + m.a01\
    \ * a.second;\n  fps b1 = m.a10 * a.first + m.a11 * a.second;\n  b0.shrink();\n\
    \  b1.shrink();\n  return {b0, b1};\n};\n\ntemplate <class mint>\nvoid StepGCD(Mat<mint>&\
    \ mat, P<mint>& p) {\n  auto q = p.first / p.second;\n  mat.a00 -= mat.a10 * q,\
    \ mat.a00.shrink();\n  mat.a01 -= mat.a11 * q, mat.a01.shrink();\n  swap(mat.a00,\
    \ mat.a10);\n  swap(mat.a01, mat.a11);\n  p.first -= p.second * q, p.first.shrink();\n\
    \  swap(p.first, p.second);\n}\ntemplate <class mint>\nMat<mint> HalfGCD(P<mint>\
    \ p) {\n  int n = (int)p.first.size() - 1, m = (int)p.second.size() - 1;\n  int\
    \ k = n / 2 + 1;\n  if (m < k) return Mat<mint>::I();\n  auto mat = HalfGCD(P<mint>{p.first\
    \ >> k, p.second >> k});\n  p = mat * p;\n  if (p.second.size() <= k) return mat;\n\
    \  StepGCD(mat, p);\n  if (p.second.size() <= k) return mat;\n  int l = 2 * k\
    \ - ((int)p.first.size() - 1);\n  return HalfGCD(P<mint>{p.first >> l, p.second\
    \ >> l}) * mat;\n}\ntemplate <class mint>\nMat<mint> ExtGCD(const FPS<mint>& f,\
    \ const FPS<mint>& g) {\n  P<mint> p{f, g};\n  p.first.shrink();\n  p.second.shrink();\n\
    \  if (p.first.size() < p.second.size()) {\n    auto mat = ExtGCD(p.second, p.first);\n\
    \    swap(mat.a00, mat.a01);\n    swap(mat.a10, mat.a11);\n    return mat;\n \
    \ }\n  auto res = Mat<mint>::I();\n  if (p.second.empty()) return res;\n  while\
    \ (true) {\n    Mat<mint> mat = HalfGCD(p);\n    p = mat * p;\n    if (p.second.empty())\
    \ return mat * res;\n    StepGCD(mat, p);\n    if (p.second.empty()) return mat\
    \ * res;\n    res = mat * res;\n  }\n}\n\ntemplate <class mint>\nFPS<mint> PolynomialGcd(FPS<mint>\
    \ f, FPS<mint> g) {\n  auto m = ExtGCD(f, g);\n  auto h = m.a00 * f + m.a01 *\
    \ g;\n  h.shrink();\n  if (!h.empty()) {\n    mint c = h.back().inv();\n    for\
    \ (auto& v : h) v *= c;\n  }\n  return h;\n}\n// f*h=1 (mod g)\ntemplate <class\
    \ mint>\noptional<FPS<mint>> PolynomialInv(FPS<mint> f, FPS<mint> g) {\n  auto\
    \ m = ExtGCD(f, g);\n  auto gcd = m.a00 * f + m.a01 * g;\n  gcd.shrink();\n  if\
    \ (gcd.size() != 1) return nullopt;\n  mint c = gcd[0].inv();\n  auto h = m.a00;\n\
    \  for (auto& v : h) v *= c;\n  return h;\n}\n};  // namespace polynomial_gcd\n\
    using polynomial_gcd::PolynomialGcd;\nusing polynomial_gcd::PolynomialInv;\n/**\n\
    \ * @brief Polynomial Gcd\n * @docs docs/fps/polynomial-gcd.md\n */"
  dependsOn:
  - fps/formal-power-series.hpp
  isVerificationFile: false
  path: fps/polynomial-gcd.hpp
  requiredBy: []
  timestamp: '2025-10-31 21:40:36+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/fps/LC_inv_of_polynomials.test.cpp
documentation_of: fps/polynomial-gcd.hpp
layout: document
redirect_from:
- /library/fps/polynomial-gcd.hpp
- /library/fps/polynomial-gcd.hpp.html
title: Polynomial Gcd
---
多項式 $f(x),g(x)$ に対する $\gcd(f(x),g(x))$ を $n=\max(\deg f,\deg g)$ として $O(n(\log n)^2)$ 時間で計算する．

また $f(x)h(x)\equiv 1\pmod{g(x)}$ となる多項式 $h(x)$ も同じ計算量で求められる．

## Half-GCD 法

Euclid の互除法をそのまま適用すると，一回の反復で次数が $1$ しか減少しない場合に $\Omega(n^2\log n)$ 時間かかる．
解決するのが Half-GCD 法．

- [https://codeforces.com/blog/entry/101850]
- [https://dl.acm.org/doi/10.1145/800125.804045]

$f,g$ の GCD は互除法で求められる．

- $f_0=f,f_1=g$ とする（$\deg f\geq\deg g$）．
- $i=1,2,\dots$ について順に $f_{i-1}$ を $f_i$ で割った商を $q_i$ とし，$f_{i+1}=f_i-f_{i+1}q_i$ と定めていく．
- $f_{i+1}=0$ となったとき $\operatorname{GCD}(f,g)=f_i$ である．

過程は行列で表示できる：$M_i=\begin{pmatrix}0&1\\1&-q_i\end{pmatrix}$ とすると $\begin{pmatrix}f_i\\f_{i+1}\end{pmatrix}=M_i\cdots M_1\begin{pmatrix}f_0\\f_1\end{pmatrix}$ である．

$\deg f_t \gt \frac{1}{2}\deg f\geq \deg f_{t+1}$ となる $t$ について $\operatorname{HGCD}(f,g)=M_t\cdots M_1$ とおく．

HGCD は再帰的に計算できる（証明は後述）．ただし $\deg f\geq\deg g$ とし，`f >> k` は $f\operatorname{div}x^k$ を意味する．

```
def HGCD(f, g):
  if deg(g) <= deg(f) / 2: return I
  k = floor(deg(f) / 2) + 1
  M = HGCD(f >> k, g >> k)
  (f, g)^T = M * (f, g)^T
  if deg(g) <= deg(f) / 2: return M
  (通常の互除法の 1 step を行う)
  if deg(g) <= deg(f) / 2: return M
  l = 2 * k - deg(f)
  return HGCD(f >> l, g >> l) * M
```

2 回の HGCD ではどちらも次数が半分以下になっている．
また多項式除算を 1 回行っている．
従って $T(n)=2T(n/2)+n\log n$ を解いて $T(n)=n(\log n)^2$ であるから計算量は $O(n(\log n)^2)$ 時間である．


HGCD を用いれば以下のアルゴリズムで GCD が求められる．
ループごとに $f$ の次数が半減するので $T(n)+T(n/2)+T(n/4)+\cdots=O(n(\log n)^2)$ 時間．

```
def GCD(f, g):
  while g != 0:
    (f, g) = HGCD(f, g) * (f, g)
    if g == 0: break
    (f, g) = (g, f % g)
  return f
```


### 正当性

形式的 Laurent 級数（有限個の負冪の項を許す）として考えると，$f$ を $g$ で割った商 $q$ は

$$q(x^{-1})=\frac{f(x^{-1})}{g(x^{-1})}\bmod x$$

と表せる．



> **補題.** 多項式 $f,g\ (\deg f-\deg g=k)$ に対し $f$ を $g$ で割った商 $q$ は $f,g$ のそれぞれ上から $k+1$ 次の係数にのみ依存する（特に $\deg f$ の値によらない）．

<details>
<summary>証明</summary>

両辺に $x^k=x^{\deg f-\deg g}$ をかけると
$$\begin{align*}
x^kq(x^{-1})
&=\frac{x^{\deg f}f(x^{-1})}{x^{\deg g}g(x^{-1})}\bmod x^{k+1}\\
&=\frac{x^{\deg f}f(x^{-1})\bmod x^{k+1}}{x^{\deg g}g(x^{-1})\bmod x^{k+1}}\bmod x^{k+1}
\end{align*}$$
であるのでよい．
(証明終)

</details>

---

> **定理.** $(f,g)$ に対し互除法を適用して得られる行列を $M_1,M_2,\dots$ とする．非負整数 $k$ に対し，ある $t$ が存在して $\operatorname{HGCD}(f\operatorname{div}x^k,g\operatorname{div}x^k)=M_t\cdots M_1$ となる．

<details>
<summary>証明</summary>

$n=\deg f$ とする．

HGCD 側は $\deg f'_i\gt\frac{1}{2}(n-k)$ の間操作を行う．
これをみたす $i$ に対して以下を示すことができればよい．
- $\deg f_i=\deg f'_i+k$
- $f_i$ と $f'_i$ のそれぞれ上 $\deg f_{i-1}-\lfloor\frac{n+k}{2}\rfloor+1=\deg f'_{i-1}-\lfloor\frac{n-k}{2}\rfloor+1$ 次が一致する

(TODO: 証明する，実験では成り立ちそう & これより次数評価は緩められなさそう)
(証明終)

</details>