---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: fps/formal-power-series.hpp
    title: fps/formal-power-series.hpp
  - icon: ':heavy_check_mark:'
    path: fps/taylor-shift.hpp
    title: Taylor Shift
  - icon: ':heavy_check_mark:'
    path: math/lpf-table.hpp
    title: LPF Table
  - icon: ':heavy_check_mark:'
    path: modint/factorial.hpp
    title: "\u968E\u4E57, \u4E8C\u9805\u4FC2\u6570"
  - icon: ':heavy_check_mark:'
    path: modint/power-table.hpp
    title: Power Table
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/fps/LC_partition_function.test.cpp
    title: verify/fps/LC_partition_function.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/fps/LC_stirling_number_of_the_first_kind.test.cpp
    title: verify/fps/LC_stirling_number_of_the_first_kind.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/fps/LC_stirling_number_of_the_first_kind_fixed_k.test.cpp
    title: verify/fps/LC_stirling_number_of_the_first_kind_fixed_k.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/fps/LC_stirling_number_of_the_second_kind.test.cpp
    title: verify/fps/LC_stirling_number_of_the_second_kind.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/fps/LC_stirling_number_of_the_second_kind_fixed_k.test.cpp
    title: verify/fps/LC_stirling_number_of_the_second_kind_fixed_k.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/fps/famous-sequences.md
    document_title: "\u6709\u540D\u6570\u5217"
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
    };\n/**\n * @brief \u968E\u4E57, \u4E8C\u9805\u4FC2\u6570\n */\n#line 2 \"math/lpf-table.hpp\"\
    \n\nvector<int> LPFTable(int n) {\n  vector<int> lpf(n + 1, 0);\n  iota(lpf.begin(),\
    \ lpf.end(), 0);\n  for (int p = 2; p * p <= n; p += (p & 1) + 1) {\n    if (lpf[p]\
    \ != p) continue;\n    for (int i = p * p; i <= n; i += p)\n      if (lpf[i] ==\
    \ i) lpf[i] = p;\n  }\n  return lpf;\n}\n/**\n * @brief LPF Table\n */\n#line\
    \ 3 \"modint/power-table.hpp\"\n\n// 0^k,1^k,2^k,...,n^k\ntemplate <class T>\n\
    vector<T> PowerTable(int n, int k) {\n  assert(k >= 0);\n  vector<T> f;\n  if\
    \ (k == 0) {\n    f = vector<T>(n + 1, 0);\n    f[0] = 1;\n  } else {\n    f =\
    \ vector<T>(n + 1, 1);\n    f[0] = 0;\n    auto lpf = LPFTable(n);\n    for (int\
    \ i = 2; i <= n; i++)\n      f[i] = lpf[i] == i ? T(i).pow(k) : f[i / lpf[i]]\
    \ * f[lpf[i]];\n  }\n  return f;\n}\n/**\n * @brief Power Table\n */\n#line 2\
    \ \"fps/formal-power-series.hpp\"\n\ntemplate <class mint>\nstruct FormalPowerSeries\
    \ : vector<mint> {\n  using vector<mint>::vector;\n  using FPS = FormalPowerSeries;\n\
    \  FormalPowerSeries(const vector<mint>& r) : vector<mint>(r) {}\n  FormalPowerSeries(vector<mint>&&\
    \ r) : vector<mint>(std::move(r)) {}\n  FPS& operator=(const vector<mint>& r)\
    \ {\n    vector<mint>::operator=(r);\n    return *this;\n  }\n  FPS& operator+=(const\
    \ FPS& r) {\n    if (r.size() > this->size()) this->resize(r.size());\n    for\
    \ (int i = 0; i < (int)r.size(); i++) (*this)[i] += r[i];\n    return *this;\n\
    \  }\n  FPS& operator+=(const mint& r) {\n    if (this->empty()) this->resize(1);\n\
    \    (*this)[0] += r;\n    return *this;\n  }\n  FPS& operator-=(const FPS& r)\
    \ {\n    if (r.size() > this->size()) this->resize(r.size());\n    for (int i\
    \ = 0; i < (int)r.size(); i++) (*this)[i] -= r[i];\n    return *this;\n  }\n \
    \ FPS& operator-=(const mint& r) {\n    if (this->empty()) this->resize(1);\n\
    \    (*this)[0] -= r;\n    return *this;\n  }\n  FPS& operator*=(const mint& v)\
    \ {\n    for (int k = 0; k < (int)this->size(); k++) (*this)[k] *= v;\n    return\
    \ *this;\n  }\n  FPS& operator/=(const FPS& r) {\n    if (this->size() < r.size())\
    \ {\n      this->clear();\n      return *this;\n    }\n    int n = this->size()\
    \ - r.size() + 1;\n    if ((int)r.size() <= 64) {\n      FPS f(*this), g(r);\n\
    \      g.shrink();\n      mint coeff = g.at(g.size() - 1).inv();\n      for (auto&\
    \ x : g) x *= coeff;\n      int deg = (int)f.size() - (int)g.size() + 1;\n   \
    \   int gs = g.size();\n      FPS quo(deg);\n      for (int i = deg - 1; i >=\
    \ 0; i--) {\n        quo[i] = f[i + gs - 1];\n        for (int j = 0; j < gs;\
    \ j++) f[i + j] -= quo[i] * g[j];\n      }\n      *this = quo * coeff;\n     \
    \ this->resize(n, mint(0));\n      return *this;\n    }\n    return *this = ((*this).rev().pre(n)\
    \ * r.rev().inv(n)).pre(n).rev();\n  }\n  FPS& operator%=(const FPS& r) {\n  \
    \  *this -= *this / r * r;\n    shrink();\n    return *this;\n  }\n  FPS operator+(const\
    \ FPS& r) const { return FPS(*this) += r; }\n  FPS operator+(const mint& v) const\
    \ { return FPS(*this) += v; }\n  FPS operator-(const FPS& r) const { return FPS(*this)\
    \ -= r; }\n  FPS operator-(const mint& v) const { return FPS(*this) -= v; }\n\
    \  FPS operator*(const FPS& r) const { return FPS(*this) *= r; }\n  FPS operator*(const\
    \ mint& v) const { return FPS(*this) *= v; }\n  FPS operator/(const FPS& r) const\
    \ { return FPS(*this) /= r; }\n  FPS operator%(const FPS& r) const { return FPS(*this)\
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
    \ = nullptr;\n#line 4 \"fps/taylor-shift.hpp\"\n\n// f(x+a)\ntemplate <class mint>\n\
    FormalPowerSeries<mint> TaylorShift(FormalPowerSeries<mint> f, mint a) {\n  using\
    \ fps = FormalPowerSeries<mint>;\n  int n = f.size();\n  using fact = Factorial<mint>;\n\
    \  fact::reserve(n);\n  for (int i = 0; i < n; i++) f[i] *= fact::fact(i);\n \
    \ reverse(f.begin(), f.end());\n  fps g(n, mint(1));\n  for (int i = 1; i < n;\
    \ i++) g[i] = g[i - 1] * a * fact::inv(i);\n  f = (f * g).pre(n);\n  reverse(f.begin(),\
    \ f.end());\n  for (int i = 0; i < n; i++) f[i] *= fact::fact_inv(i);\n  return\
    \ f;\n}\n/**\n * @brief Taylor Shift\n * @docs docs/fps/taylor-shift.md\n */\n\
    #line 6 \"fps/famous-sequences.hpp\"\n\ntemplate <class mint>\nFormalPowerSeries<mint>\
    \ PartitionFunction(int n) {\n  FormalPowerSeries<mint> g(n + 1);\n  for (int\
    \ k = 0; k * (3 * k - 1) / 2 <= n; k++) g[k * (3 * k - 1) / 2] += k & 1 ? -1 :\
    \ 1;\n  for (int k = 1; k * (3 * k + 1) / 2 <= n; k++) g[k * (3 * k + 1) / 2]\
    \ += k & 1 ? -1 : 1;\n  return g.inv(n + 1);\n}\ntemplate <class mint>\nFormalPowerSeries<mint>\
    \ FirstKindStirlingNumbers(int n) {\n  FormalPowerSeries<mint> f{1};\n  for (int\
    \ l = 30; l >= 0; l--) {\n    if (f.size() > 1) f *= TaylorShift(f, mint(-(n >>\
    \ (l + 1))));\n    if ((n >> l) & 1) f = (f << 1) - f * mint((n >> l) - 1);\n\
    \  }\n  return f;\n}\ntemplate <class mint>\nFormalPowerSeries<mint> FirstKindStirlingNumbersFixedK(int\
    \ n, int k) {\n  using fact = Factorial<mint>;\n  if (k > n) return FormalPowerSeries<mint>{};\n\
    \  FormalPowerSeries<mint> f(n - k + 1);\n  for (int i = 0; i < f.size(); i++)\
    \ f[i] = fact::inv(i + 1) * (i & 1 ? -1 : 1);\n  f = f.pow(k);\n  f *= fact::fact_inv(k);\n\
    \  for (int i = 0; i < f.size(); i++) f[i] *= fact::fact(i + k);\n  return f;\n\
    }\ntemplate <class mint>\nFormalPowerSeries<mint> SecondKindStirlingNumbers(int\
    \ n) {\n  using fact = Factorial<mint>;\n  FormalPowerSeries<mint> f(n + 1);\n\
    \  for (int i = 0; i < f.size(); i++) f[i] = fact::fact_inv(i) * (i & 1 ? -1 :\
    \ 1);\n  FormalPowerSeries<mint> g(PowerTable<mint>(n, n));\n  for (int i = 0;\
    \ i < g.size(); i++) g[i] *= fact::fact_inv(i);\n  f *= g;\n  f.resize(n + 1);\n\
    \  return f;\n}\ntemplate <class mint>\nFormalPowerSeries<mint> SecondKindStirlingNumbersFixedK(int\
    \ n, int k) {\n  using fact = Factorial<mint>;\n  if (k > n) return FormalPowerSeries<mint>{};\n\
    \  FormalPowerSeries<mint> f(n - k + 1);\n  for (int i = 0; i < f.size(); i++)\
    \ f[i] = fact::fact_inv(i + 1);\n  f = f.pow(k);\n  f *= fact::fact_inv(k);\n\
    \  for (int i = 0; i < f.size(); i++) f[i] *= fact::fact(i + k);\n  return f;\n\
    }\n\n/**\n * @brief \u6709\u540D\u6570\u5217\n * @docs docs/fps/famous-sequences.md\n\
    \ */\n"
  code: "#pragma once\n#include \"modint/factorial.hpp\"\n#include \"modint/power-table.hpp\"\
    \n#include \"fps/formal-power-series.hpp\"\n#include \"fps/taylor-shift.hpp\"\n\
    \ntemplate <class mint>\nFormalPowerSeries<mint> PartitionFunction(int n) {\n\
    \  FormalPowerSeries<mint> g(n + 1);\n  for (int k = 0; k * (3 * k - 1) / 2 <=\
    \ n; k++) g[k * (3 * k - 1) / 2] += k & 1 ? -1 : 1;\n  for (int k = 1; k * (3\
    \ * k + 1) / 2 <= n; k++) g[k * (3 * k + 1) / 2] += k & 1 ? -1 : 1;\n  return\
    \ g.inv(n + 1);\n}\ntemplate <class mint>\nFormalPowerSeries<mint> FirstKindStirlingNumbers(int\
    \ n) {\n  FormalPowerSeries<mint> f{1};\n  for (int l = 30; l >= 0; l--) {\n \
    \   if (f.size() > 1) f *= TaylorShift(f, mint(-(n >> (l + 1))));\n    if ((n\
    \ >> l) & 1) f = (f << 1) - f * mint((n >> l) - 1);\n  }\n  return f;\n}\ntemplate\
    \ <class mint>\nFormalPowerSeries<mint> FirstKindStirlingNumbersFixedK(int n,\
    \ int k) {\n  using fact = Factorial<mint>;\n  if (k > n) return FormalPowerSeries<mint>{};\n\
    \  FormalPowerSeries<mint> f(n - k + 1);\n  for (int i = 0; i < f.size(); i++)\
    \ f[i] = fact::inv(i + 1) * (i & 1 ? -1 : 1);\n  f = f.pow(k);\n  f *= fact::fact_inv(k);\n\
    \  for (int i = 0; i < f.size(); i++) f[i] *= fact::fact(i + k);\n  return f;\n\
    }\ntemplate <class mint>\nFormalPowerSeries<mint> SecondKindStirlingNumbers(int\
    \ n) {\n  using fact = Factorial<mint>;\n  FormalPowerSeries<mint> f(n + 1);\n\
    \  for (int i = 0; i < f.size(); i++) f[i] = fact::fact_inv(i) * (i & 1 ? -1 :\
    \ 1);\n  FormalPowerSeries<mint> g(PowerTable<mint>(n, n));\n  for (int i = 0;\
    \ i < g.size(); i++) g[i] *= fact::fact_inv(i);\n  f *= g;\n  f.resize(n + 1);\n\
    \  return f;\n}\ntemplate <class mint>\nFormalPowerSeries<mint> SecondKindStirlingNumbersFixedK(int\
    \ n, int k) {\n  using fact = Factorial<mint>;\n  if (k > n) return FormalPowerSeries<mint>{};\n\
    \  FormalPowerSeries<mint> f(n - k + 1);\n  for (int i = 0; i < f.size(); i++)\
    \ f[i] = fact::fact_inv(i + 1);\n  f = f.pow(k);\n  f *= fact::fact_inv(k);\n\
    \  for (int i = 0; i < f.size(); i++) f[i] *= fact::fact(i + k);\n  return f;\n\
    }\n\n/**\n * @brief \u6709\u540D\u6570\u5217\n * @docs docs/fps/famous-sequences.md\n\
    \ */"
  dependsOn:
  - modint/factorial.hpp
  - modint/power-table.hpp
  - math/lpf-table.hpp
  - fps/formal-power-series.hpp
  - fps/taylor-shift.hpp
  isVerificationFile: false
  path: fps/famous-sequences.hpp
  requiredBy: []
  timestamp: '2025-11-03 00:29:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/fps/LC_stirling_number_of_the_second_kind_fixed_k.test.cpp
  - verify/fps/LC_stirling_number_of_the_first_kind_fixed_k.test.cpp
  - verify/fps/LC_partition_function.test.cpp
  - verify/fps/LC_stirling_number_of_the_first_kind.test.cpp
  - verify/fps/LC_stirling_number_of_the_second_kind.test.cpp
documentation_of: fps/famous-sequences.hpp
layout: document
redirect_from:
- /library/fps/famous-sequences.hpp
- /library/fps/famous-sequences.hpp.html
title: "\u6709\u540D\u6570\u5217"
---
## 分割数

非負整数 $n$ の分割数 $p_n$ とは，$n$ をいくつかの正整数の和（順序を区別しない）で表す方法の数．

母関数は $\prod_{k=1}^{\infty}\frac{1}{1-x^k}$ である．

オイラーの五角数定理より
$$\prod_{k=1}^{\infty}(1-x^k)=\sum_{k=-\infty}^{\infty}(-1)^kx^{k(3k-1)/2}$$
であることを用いれば $O(N\log N)$ 時間で $p_0,p_1,\dots,p_N$ が列挙できる．

## 第一種スターリング数

$s(n,k)$ を以下で定める．
$$x(x-1)\cdots(x-(n-1))=\sum_{k=0}^{n}s(n,k)x^k$$

$s(n,i)$ の $0\leq i\leq n$ での列挙が $O(n\log n)$ 時間でできる．
- 分割統治をするが，一方の結果を Taylor Shift すればもう一方の結果を得られる．

また 
$$\sum_{i,j}s(i,j)\frac{x^i}{i!}y^j=(1+x)^y=\exp(y\log(1+x))=\sum_{j}(\log(1+x))^j\frac{y^j}{j!}$$
となるので $s(i,k)$ の $k\leq i\leq n$ での列挙が $O((n-k)\log (n-k))$ 時間でできる．

## 第二種スターリング数

$S(n,k)$ を以下で定める．
$$x^n=\sum_{k=0}^{n}S(n,k)x(x-1)\cdots(x-(k-1))$$

整数 $i$ について $x=i$ としたとき
$$i^n=i![y^i]\left(\sum_{k=0}^{n}S(n,k)y^k\right)e^y$$
と表示できるので
$$\sum_{k=0}^{n}S(n,k)y^k=e^{-y}\left(\sum_{i=0}^{\infty}\frac{i^n}{i!}y^i\right)$$
であり，$S(n,i)$ の $0\leq i\leq n$ での列挙が $O(n\log n)$ 時間でできる．
また
$$\sum_{i=0}^{\infty}\frac{i^n}{i!}y^i=n![x^n]\sum_{i=0}^{\infty}\frac{e^{ix}}{i!}y^i=n![x^n]\exp(e^xy)$$
より
$$\sum_{n,k}S(n,k)\frac{x^n}{n!}y^k=\exp((e^x-1)y)=\sum_{i\geq 0}(e^x-1)^i\frac{y^i}{i!}$$
となるので $S(i,k)$ の $k\leq i\leq n$ での列挙が $O((n-k)\log (n-k))$ 時間でできる．