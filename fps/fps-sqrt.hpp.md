---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: fps/formal-power-series.hpp
    title: fps/formal-power-series.hpp
  - icon: ':question:'
    path: modint/mod-pow.hpp
    title: modint/mod-pow.hpp
  - icon: ':question:'
    path: modint/mod-sqrt.hpp
    title: modint/mod-sqrt.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/fps/LC_sqrt_of_formal_power_series.relaxed.test.cpp
    title: verify/fps/LC_sqrt_of_formal_power_series.relaxed.test.cpp
  - icon: ':x:'
    path: verify/fps/LC_sqrt_of_formal_power_series.test.cpp
    title: verify/fps/LC_sqrt_of_formal_power_series.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"fps/fps-sqrt.hpp\"\n\n#line 2 \"modint/mod-sqrt.hpp\"\n\n\
    #line 2 \"modint/mod-pow.hpp\"\n\nunsigned int ModPow(unsigned int a, unsigned\
    \ long long n, unsigned int m) {\n  unsigned long long x = a, y = 1;\n  while\
    \ (n) {\n    if (n & 1) y = y * x % m;\n    x = x * x % m;\n    n >>= 1;\n  }\n\
    \  return y;\n}\n#line 4 \"modint/mod-sqrt.hpp\"\n\nlong long ModSqrt(long long\
    \ a, long long p) {\n  if (a >= p) a %= p;\n  if (p == 2) return a & 1;\n  if\
    \ (a == 0) return 0;\n  if (ModPow(a, (p - 1) / 2, p) != 1) return -1;\n  if (p\
    \ % 4 == 3) return ModPow(a, (3 * p - 1) / 4, p);\n  unsigned int z = 2, q = p\
    \ - 1;\n  while (ModPow(z, (p - 1) / 2, p) == 1) z++;\n  int s = 0;\n  while (!(q\
    \ & 1)) {\n    s++;\n    q >>= 1;\n  }\n  int m = s;\n  unsigned int c = ModPow(z,\
    \ q, p);\n  unsigned int t = ModPow(a, q, p);\n  unsigned int r = ModPow(a, (q\
    \ + 1) / 2, p);\n  while (true) {\n    if (t == 1) return r;\n    unsigned int\
    \ pow = t;\n    int j = 1;\n    for (; j < m; j++) {\n      pow = 1ll * pow *\
    \ pow % p;\n      if (pow == 1) break;\n    }\n    unsigned int b = c;\n    for\
    \ (int i = 0; i < m - j - 1; i++) b = 1ll * b * b % p;\n    m = j;\n    c = 1ll\
    \ * b * b % p;\n    t = 1ll * t * c % p;\n    r = 1ll * r * b % p;\n  }\n}\n#line\
    \ 2 \"fps/formal-power-series.hpp\"\n\ntemplate <class mint>\nstruct FormalPowerSeries\
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
    \ = nullptr;\n#line 5 \"fps/fps-sqrt.hpp\"\n\ntemplate <typename mint>\nFormalPowerSeries<mint>\
    \ FpsSqrt(const FormalPowerSeries<mint> &f, int deg = -1) {\n  if (deg == -1)\
    \ deg = (int)f.size();\n  if ((int)f.size() == 0) return FormalPowerSeries<mint>(deg,\
    \ 0);\n  if (f[0] == mint(0)) {\n    for (int i = 1; i < (int)f.size(); i++) {\n\
    \      if (f[i] != mint(0)) {\n        if (i & 1) return {};\n        if (deg\
    \ - i / 2 <= 0) break;\n        auto ret = FpsSqrt(f >> i, deg - i / 2);\n   \
    \     if (ret.empty()) return {};\n        ret = ret << (i / 2);\n        if ((int)ret.size()\
    \ < deg) ret.resize(deg, mint(0));\n        return ret;\n      }\n    }\n    return\
    \ FormalPowerSeries<mint>(deg, 0);\n  }\n  int64_t sqr = ModSqrt(f[0].val(), mint::get_mod());\n\
    \  if (sqr == -1) return {};\n  assert(sqr * sqr % mint::get_mod() == f[0].val());\n\
    \  FormalPowerSeries<mint> ret = {mint(sqr)};\n  mint inv2 = mint(2).inv();\n\
    \  for (int i = 1; i < deg; i <<= 1) {\n    ret = (ret + f.pre(i << 1) * ret.inv(i\
    \ << 1)) * inv2;\n  }\n  return ret.pre(deg);\n}\n"
  code: "#pragma once\n\n#include \"modint/mod-sqrt.hpp\"\n#include \"fps/formal-power-series.hpp\"\
    \n\ntemplate <typename mint>\nFormalPowerSeries<mint> FpsSqrt(const FormalPowerSeries<mint>\
    \ &f, int deg = -1) {\n  if (deg == -1) deg = (int)f.size();\n  if ((int)f.size()\
    \ == 0) return FormalPowerSeries<mint>(deg, 0);\n  if (f[0] == mint(0)) {\n  \
    \  for (int i = 1; i < (int)f.size(); i++) {\n      if (f[i] != mint(0)) {\n \
    \       if (i & 1) return {};\n        if (deg - i / 2 <= 0) break;\n        auto\
    \ ret = FpsSqrt(f >> i, deg - i / 2);\n        if (ret.empty()) return {};\n \
    \       ret = ret << (i / 2);\n        if ((int)ret.size() < deg) ret.resize(deg,\
    \ mint(0));\n        return ret;\n      }\n    }\n    return FormalPowerSeries<mint>(deg,\
    \ 0);\n  }\n  int64_t sqr = ModSqrt(f[0].val(), mint::get_mod());\n  if (sqr ==\
    \ -1) return {};\n  assert(sqr * sqr % mint::get_mod() == f[0].val());\n  FormalPowerSeries<mint>\
    \ ret = {mint(sqr)};\n  mint inv2 = mint(2).inv();\n  for (int i = 1; i < deg;\
    \ i <<= 1) {\n    ret = (ret + f.pre(i << 1) * ret.inv(i << 1)) * inv2;\n  }\n\
    \  return ret.pre(deg);\n}\n"
  dependsOn:
  - modint/mod-sqrt.hpp
  - modint/mod-pow.hpp
  - fps/formal-power-series.hpp
  isVerificationFile: false
  path: fps/fps-sqrt.hpp
  requiredBy: []
  timestamp: '2025-10-31 21:40:36+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/fps/LC_sqrt_of_formal_power_series.test.cpp
  - verify/fps/LC_sqrt_of_formal_power_series.relaxed.test.cpp
documentation_of: fps/fps-sqrt.hpp
layout: document
redirect_from:
- /library/fps/fps-sqrt.hpp
- /library/fps/fps-sqrt.hpp.html
title: fps/fps-sqrt.hpp
---
