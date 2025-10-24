---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: fps/berlekamp-massey.hpp
    title: Berlekamp-Massey
  - icon: ':heavy_check_mark:'
    path: fps/bostan-mori.hpp
    title: Bostan-Mori
  - icon: ':heavy_check_mark:'
    path: fps/composition.hpp
    title: "FPS \u5408\u6210"
  - icon: ':heavy_check_mark:'
    path: fps/compositional-inv.hpp
    title: "\u9006\u95A2\u6570"
  - icon: ':heavy_check_mark:'
    path: fps/fps-ntt-friendly.hpp
    title: fps/fps-ntt-friendly.hpp
  - icon: ':warning:'
    path: fps/fps-rational.hpp
    title: fps/fps-rational.hpp
  - icon: ':heavy_check_mark:'
    path: fps/fps-sqrt.hpp
    title: fps/fps-sqrt.hpp
  - icon: ':heavy_check_mark:'
    path: fps/inverse-shift.hpp
    title: "Inverse \u306E\u6B21\u6570\u30B7\u30D5\u30C8"
  - icon: ':heavy_check_mark:'
    path: fps/linearly-recurrent-sequence.hpp
    title: "\u7DDA\u5F62\u6F38\u5316\u5F0F\u7528"
  - icon: ':heavy_check_mark:'
    path: fps/multipoint-evaluation.hpp
    title: Multipoint Evaluation
  - icon: ':heavy_check_mark:'
    path: fps/polynomial-interpolation.hpp
    title: "\u591A\u9805\u5F0F\u88DC\u9593"
  - icon: ':heavy_check_mark:'
    path: fps/power-projection.hpp
    title: Power Projection
  - icon: ':heavy_check_mark:'
    path: fps/prefix-sum-of-polynomial.hpp
    title: "\u591A\u9805\u5F0F\u306E Prefix Sum"
  - icon: ':heavy_check_mark:'
    path: fps/product-of-polynomials.hpp
    title: "\u591A\u9805\u5F0F\u306E\u7A4D"
  - icon: ':warning:'
    path: fps/sum-of-rationals.hpp
    title: "\u6709\u7406\u5F0F\u306E\u548C"
  - icon: ':heavy_check_mark:'
    path: fps/taylor-shift.hpp
    title: Taylor Shift
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/fps/LC_composition_of_formal_power_series.test.cpp
    title: verify/fps/LC_composition_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/fps/LC_composition_of_formal_power_series_large.test.cpp
    title: verify/fps/LC_composition_of_formal_power_series_large.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/fps/LC_compositional_inverse_of_formal_power_series.test.cpp
    title: verify/fps/LC_compositional_inverse_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/fps/LC_compositional_inverse_of_formal_power_series_large.test.cpp
    title: verify/fps/LC_compositional_inverse_of_formal_power_series_large.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/fps/LC_consecutive_terms_of_linear_recurrent_sequence.test.cpp
    title: verify/fps/LC_consecutive_terms_of_linear_recurrent_sequence.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/fps/LC_exp_of_formal_power_series.test.cpp
    title: verify/fps/LC_exp_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/fps/LC_find_linear_recurrence.test.cpp
    title: verify/fps/LC_find_linear_recurrence.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/fps/LC_inv_of_formal_power_series.test.cpp
    title: verify/fps/LC_inv_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/fps/LC_kth_term_of_linearly_recurrent_sequence.test.cpp
    title: verify/fps/LC_kth_term_of_linearly_recurrent_sequence.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/fps/LC_log_of_formal_power_series.test.cpp
    title: verify/fps/LC_log_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/fps/LC_multipoint_evaluation.test.cpp
    title: verify/fps/LC_multipoint_evaluation.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/fps/LC_multipoint_evaluation_on_geometric_sequence.test.cpp
    title: verify/fps/LC_multipoint_evaluation_on_geometric_sequence.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/fps/LC_polynomial_interpolation.test.cpp
    title: verify/fps/LC_polynomial_interpolation.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/fps/LC_polynomial_taylor_shift.test.cpp
    title: verify/fps/LC_polynomial_taylor_shift.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/fps/LC_pow_of_formal_power_series.test.cpp
    title: verify/fps/LC_pow_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/fps/LC_product_of_polynomial_sequence.test.cpp
    title: verify/fps/LC_product_of_polynomial_sequence.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/fps/LC_sqrt_of_formal_power_series.test.cpp
    title: verify/fps/LC_sqrt_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/fps/UNIT_prefix_sum_of_polynomial.test.cpp
    title: verify/fps/UNIT_prefix_sum_of_polynomial.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
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
    \ = nullptr;\n"
  code: "#pragma once\n\ntemplate <class mint>\nstruct FormalPowerSeries : vector<mint>\
    \ {\n  using vector<mint>::vector;\n  using FPS = FormalPowerSeries;\n  FPS &operator+=(const\
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
    \ = nullptr;"
  dependsOn: []
  isVerificationFile: false
  path: fps/formal-power-series.hpp
  requiredBy:
  - fps/power-projection.hpp
  - fps/sum-of-rationals.hpp
  - fps/composition.hpp
  - fps/polynomial-interpolation.hpp
  - fps/bostan-mori.hpp
  - fps/multipoint-evaluation.hpp
  - fps/taylor-shift.hpp
  - fps/fps-ntt-friendly.hpp
  - fps/inverse-shift.hpp
  - fps/product-of-polynomials.hpp
  - fps/prefix-sum-of-polynomial.hpp
  - fps/compositional-inv.hpp
  - fps/linearly-recurrent-sequence.hpp
  - fps/fps-sqrt.hpp
  - fps/fps-rational.hpp
  - fps/berlekamp-massey.hpp
  timestamp: '2025-10-21 21:13:36+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/fps/LC_product_of_polynomial_sequence.test.cpp
  - verify/fps/LC_compositional_inverse_of_formal_power_series_large.test.cpp
  - verify/fps/LC_composition_of_formal_power_series_large.test.cpp
  - verify/fps/LC_log_of_formal_power_series.test.cpp
  - verify/fps/LC_multipoint_evaluation_on_geometric_sequence.test.cpp
  - verify/fps/UNIT_prefix_sum_of_polynomial.test.cpp
  - verify/fps/LC_polynomial_taylor_shift.test.cpp
  - verify/fps/LC_polynomial_interpolation.test.cpp
  - verify/fps/LC_exp_of_formal_power_series.test.cpp
  - verify/fps/LC_find_linear_recurrence.test.cpp
  - verify/fps/LC_multipoint_evaluation.test.cpp
  - verify/fps/LC_consecutive_terms_of_linear_recurrent_sequence.test.cpp
  - verify/fps/LC_sqrt_of_formal_power_series.test.cpp
  - verify/fps/LC_kth_term_of_linearly_recurrent_sequence.test.cpp
  - verify/fps/LC_pow_of_formal_power_series.test.cpp
  - verify/fps/LC_compositional_inverse_of_formal_power_series.test.cpp
  - verify/fps/LC_inv_of_formal_power_series.test.cpp
  - verify/fps/LC_composition_of_formal_power_series.test.cpp
documentation_of: fps/formal-power-series.hpp
layout: document
redirect_from:
- /library/fps/formal-power-series.hpp
- /library/fps/formal-power-series.hpp.html
title: fps/formal-power-series.hpp
---
