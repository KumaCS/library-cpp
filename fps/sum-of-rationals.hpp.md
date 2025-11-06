---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: fps/formal-power-series.hpp
    title: fps/formal-power-series.hpp
  - icon: ':warning:'
    path: fps/fps-rational.hpp
    title: fps/fps-rational.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u6709\u7406\u5F0F\u306E\u548C"
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
    #line 3 \"fps/fps-rational.hpp\"\n\ntemplate <class mint>\nstruct FPSRational\
    \ {\n  using F = FormalPowerSeries<mint>;\n  using R = FPSRational;\n  F num,\
    \ den;\n  R& operator+=(const R& r) {\n    num *= r.den;\n    num += den * r.num;\n\
    \    den *= r.den;\n    return *this;\n  }\n  R& operator-=(const R& r) {\n  \
    \  num *= r.den;\n    num -= den * r.num;\n    den *= r.den;\n    return *this;\n\
    \  }\n  R& operator*=(const R& r) {\n    num *= r.num;\n    den *= r.den;\n  \
    \  return *this;\n  }\n  R& operator/=(const R& r) {\n    num *= r.den;\n    den\
    \ *= r.num;\n    return *this;\n  }\n  R operator+(const R& r) const { return\
    \ R(*this) += r; }\n  R operator-(const R& r) const { return R(*this) -= r; }\n\
    \  R operator*(const R& r) const { return R(*this) *= r; }\n  R operator/(const\
    \ R& r) const { return R(*this) /= r; }\n  R inv() const { return {den, num};\
    \ }\n  F approx(int deg) const { return (den * num.inv(deg)).pre(deg); }\n};\n\
    #line 4 \"fps/sum-of-rationals.hpp\"\n\ntemplate <class mint>\nFPSRational<mint>\
    \ SumOfRationals(vector<FPSRational<mint>> rs) {\n  if (rs.empty()) return {};\n\
    \  for (auto& r : rs) {\n    r.num.shrink(), r.den.shrink();\n    if (r.den.size()\
    \ < r.num.size()) r.num.resize(r.den.size());\n  }\n  static constexpr int B =\
    \ 1 << 5;\n  for (int i = 0, j = -1; i < rs.size(); i++) {\n    if (rs[i].den.size()\
    \ > B) continue;\n    if (j == -1 || rs[i].den.size() + rs[j].den.size() - 1 >\
    \ B) {\n      j = i;\n      continue;\n    }\n    rs[j] += rs[i];\n    swap(rs[i--],\
    \ rs.back());\n    rs.pop_back();\n  }\n  if (rs.size() == 1) return rs[0];\n\
    \  for (auto& r : rs) {\n    int sz = B;\n    while (sz < r.num.size() || sz <\
    \ r.den.size()) sz <<= 1;\n    r.num.resize(sz);\n    r.num.ntt();\n    r.den.resize(sz);\n\
    \    r.den.ntt();\n  }\n  for (int sz = B * 2; rs.size() > 1; sz <<= 1) {\n  \
    \  for (int i = 0, j = -1; i < rs.size(); i++) {\n      if (rs[i].den.size() >=\
    \ sz) continue;\n      rs[i].num.ntt_doubling();\n      rs[i].den.ntt_doubling();\n\
    \      if (j == -1) {\n        j = i;\n      } else {\n        for (int k = 0;\
    \ k < sz; k++) rs[j].num[k] = rs[j].num[k] * rs[i].den[k] + rs[j].den[k] * rs[i].num[k];\n\
    \        for (int k = 0; k < sz; k++) rs[j].den[k] *= rs[i].den[k];\n        swap(rs[i--],\
    \ rs.back());\n        rs.pop_back();\n        j = -1;\n      }\n    }\n  }\n\
    \  rs[0].num.intt();\n  rs[0].num.shrink();\n  rs[0].den.intt();\n  rs[0].den.shrink();\n\
    \  return rs[0];\n}\n/**\n * @brief \u6709\u7406\u5F0F\u306E\u548C\n */\n"
  code: "#pragma once\n#include \"fps/formal-power-series.hpp\"\n#include \"fps/fps-rational.hpp\"\
    \n\ntemplate <class mint>\nFPSRational<mint> SumOfRationals(vector<FPSRational<mint>>\
    \ rs) {\n  if (rs.empty()) return {};\n  for (auto& r : rs) {\n    r.num.shrink(),\
    \ r.den.shrink();\n    if (r.den.size() < r.num.size()) r.num.resize(r.den.size());\n\
    \  }\n  static constexpr int B = 1 << 5;\n  for (int i = 0, j = -1; i < rs.size();\
    \ i++) {\n    if (rs[i].den.size() > B) continue;\n    if (j == -1 || rs[i].den.size()\
    \ + rs[j].den.size() - 1 > B) {\n      j = i;\n      continue;\n    }\n    rs[j]\
    \ += rs[i];\n    swap(rs[i--], rs.back());\n    rs.pop_back();\n  }\n  if (rs.size()\
    \ == 1) return rs[0];\n  for (auto& r : rs) {\n    int sz = B;\n    while (sz\
    \ < r.num.size() || sz < r.den.size()) sz <<= 1;\n    r.num.resize(sz);\n    r.num.ntt();\n\
    \    r.den.resize(sz);\n    r.den.ntt();\n  }\n  for (int sz = B * 2; rs.size()\
    \ > 1; sz <<= 1) {\n    for (int i = 0, j = -1; i < rs.size(); i++) {\n      if\
    \ (rs[i].den.size() >= sz) continue;\n      rs[i].num.ntt_doubling();\n      rs[i].den.ntt_doubling();\n\
    \      if (j == -1) {\n        j = i;\n      } else {\n        for (int k = 0;\
    \ k < sz; k++) rs[j].num[k] = rs[j].num[k] * rs[i].den[k] + rs[j].den[k] * rs[i].num[k];\n\
    \        for (int k = 0; k < sz; k++) rs[j].den[k] *= rs[i].den[k];\n        swap(rs[i--],\
    \ rs.back());\n        rs.pop_back();\n        j = -1;\n      }\n    }\n  }\n\
    \  rs[0].num.intt();\n  rs[0].num.shrink();\n  rs[0].den.intt();\n  rs[0].den.shrink();\n\
    \  return rs[0];\n}\n/**\n * @brief \u6709\u7406\u5F0F\u306E\u548C\n */"
  dependsOn:
  - fps/formal-power-series.hpp
  - fps/fps-rational.hpp
  isVerificationFile: false
  path: fps/sum-of-rationals.hpp
  requiredBy: []
  timestamp: '2025-11-06 12:30:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: fps/sum-of-rationals.hpp
layout: document
redirect_from:
- /library/fps/sum-of-rationals.hpp
- /library/fps/sum-of-rationals.hpp.html
title: "\u6709\u7406\u5F0F\u306E\u548C"
---
