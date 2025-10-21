---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: fps/berlekamp-massey.hpp
    title: Berlekamp-Massey
  - icon: ':heavy_check_mark:'
    path: fps/bostan-mori.hpp
    title: Bostan-Mori
  - icon: ':question:'
    path: fps/formal-power-series.hpp
    title: fps/formal-power-series.hpp
  - icon: ':heavy_check_mark:'
    path: fps/inverse-shift.hpp
    title: "Inverse \u306E\u6B21\u6570\u30B7\u30D5\u30C8"
  _extendedRequiredBy: []
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
    _deprecated_at_docs: docs/fps/linearly-recurrent-sequence.md
    document_title: "\u7DDA\u5F62\u6F38\u5316\u5F0F\u7528"
    links: []
  bundledCode: "#line 1 \"fps/linearly-recurrent-sequence.hpp\"\n#pragma\n#line 2\
    \ \"fps/formal-power-series.hpp\"\n\ntemplate <class mint>\nstruct FormalPowerSeries\
    \ : vector<mint> {\n  using vector<mint>::vector;\n  using FPS = FormalPowerSeries;\n\
    \  FPS &operator+=(const FPS &r) {\n    if (r.size() > this->size()) this->resize(r.size());\n\
    \    for (int i = 0; i < (int)r.size(); i++) (*this)[i] += r[i];\n    return *this;\n\
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
    \ = nullptr;\n#line 3 \"fps/berlekamp-massey.hpp\"\n\ntemplate <class mint>\n\
    FormalPowerSeries<mint> BerlekampMassey(const FormalPowerSeries<mint>& a) {\n\
    \  int n = a.size();\n  FormalPowerSeries<mint> b, c;\n  b.reserve(n + 1), c.reserve(n\
    \ + 1);\n  b.push_back(1), c.push_back(1);\n  mint y = 1;\n  for (int k = 0; k\
    \ < n; k++) {\n    mint x = 0;\n    for (int i = 0; i < c.size(); i++) x += c[i]\
    \ * a[k - i];\n    b.insert(b.begin(), 0);\n    if (x == 0) continue;\n    mint\
    \ v = x / y;\n    if (b.size() > c.size()) {\n      for (int i = 0; i < b.size();\
    \ i++) b[i] *= -v;\n      for (int i = 0; i < c.size(); i++) b[i] += c[i];\n \
    \     swap(b, c);\n      y = x;\n    } else {\n      for (int i = 0; i < b.size();\
    \ i++) c[i] -= v * b[i];\n    }\n  }\n  return c;\n}\n\n/**\n * @brief Berlekamp-Massey\n\
    \ * @docs docs/fps/berlekamp-massey.md\n */\n#line 3 \"fps/bostan-mori.hpp\"\n\
    \n// [x^n]f(x)/g(x)\ntemplate <class mint>\nmint BostanMori(FormalPowerSeries<mint>\
    \ f, FormalPowerSeries<mint> g, long long n) {\n  g.shrink();\n  mint ret = 0;\n\
    \  if (f.size() >= g.size()) {\n    auto q = f / g;\n    if (n < q.size()) ret\
    \ += q[n];\n    f -= q * g;\n    f.shrink();\n  }\n  if (f.empty()) return ret;\n\
    \  FormalPowerSeries<mint>::set_ntt();\n  if (!FormalPowerSeries<mint>::ntt_ptr)\
    \ {\n    f.resize(g.size() - 1);\n    for (; n > 0; n >>= 1) {\n      auto g1\
    \ = g;\n      for (int i = 1; i < g1.size(); i += 2) g1[i] = -g1[i];\n      auto\
    \ p = f * g1, q = g * g1;\n      if (n & 1) {\n        for (int i = 0; i < f.size();\
    \ i++) f[i] = p[(i << 1) | 1];\n      } else {\n        for (int i = 0; i < f.size();\
    \ i++) f[i] = p[i << 1];\n      }\n      for (int i = 0; i < g.size(); i++) g[i]\
    \ = q[i << 1];\n    }\n    return ret + f[0] / g[0];\n  } else {\n    int m =\
    \ 1, log = 0;\n    while (m < g.size()) m <<= 1, log++;\n    mint wi = mint(FormalPowerSeries<mint>::ntt_root()).inv().pow((mint::get_mod()\
    \ - 1) >> (log + 1));\n    vector<int> rev(m);\n    for (int i = 0; i < rev.size();\
    \ i++) rev[i] = (rev[i / 2] / 2) | ((i & 1) << (log - 1));\n    vector<mint> pow(m,\
    \ 1);\n    for (int i = 1; i < m; i++) pow[rev[i]] = pow[rev[i - 1]] * wi;\n \
    \   f.resize(m), g.resize(m);\n    f.ntt(), g.ntt();\n    mint inv2 = mint(2).inv();\n\
    \    for (; n >= m; n >>= 1) {\n      f.ntt_doubling(), g.ntt_doubling();\n  \
    \    if (n & 1) {\n        for (int i = 0; i < m; i++) f[i] = (f[i << 1] * g[(i\
    \ << 1) | 1] - f[(i << 1) | 1] * g[i << 1]) * inv2 * pow[i];\n      } else {\n\
    \        for (int i = 0; i < m; i++) f[i] = (f[i << 1] * g[(i << 1) | 1] + f[(i\
    \ << 1) | 1] * g[i << 1]) * inv2;\n      }\n      for (int i = 0; i < m; i++)\
    \ g[i] = g[i << 1] * g[(i << 1) | 1];\n      f.resize(m), g.resize(m);\n    }\n\
    \    f.intt(), g.intt();\n    return ret + (f * g.inv())[n];\n  }\n}\n/**\n *\
    \ @brief Bostan-Mori\n * @docs docs/fps/bostan-mori.md\n */\n#line 3 \"fps/inverse-shift.hpp\"\
    \n\n// [x^n,...,x^{n+k-1}]1/f(x)\ntemplate <class mint>\nFormalPowerSeries<mint>\
    \ InverseShift(FormalPowerSeries<mint> f, long long n, int k = -1) {\n  using\
    \ fps = FormalPowerSeries<mint>;\n  assert(f[0] != 0);\n  if (k == -1) k = f.size();\n\
    \  int m = 1;\n  while (m < k) m <<= 1;\n\n  int log = __builtin_ctz((unsigned\
    \ int)m);\n  mint w = mint(fps::ntt_root()).pow((mint::get_mod() - 1) >> (log\
    \ + 1));\n  mint wi = w.inv();\n  vector<int> rev(m);\n  for (int i = 0; i < rev.size();\
    \ i++) rev[i] = (rev[i / 2] / 2) | ((i & 1) << (log - 1));\n  mint inv2 = mint(2).inv();\n\
    \n  f.resize(m);\n  f.ntt();\n  auto rec = [&](auto& rec, long long n) -> void\
    \ {\n    if (n < m) {\n      f.intt();\n      f = f.inv(n + m);\n      f >>= n;\n\
    \      f.ntt();\n      return;\n    }\n    f.ntt_doubling();\n    assert(f.size()\
    \ == 2 * m);\n    auto f1 = f;\n    for (int i = 0; i < m; i++) swap(f1[i << 1],\
    \ f1[(i << 1) | 1]);\n    for (int i = 0; i < m; i++) f[i] = f[i << 1] * f[(i\
    \ << 1) | 1];\n    f.resize(m);\n    rec(rec, (n - m + 1) / 2);\n    if (((n -\
    \ m) & 1) == 0) {\n      f.resize(2 * m);\n      for (int i = m - 1; i >= 0; i--)\
    \ {\n        f[(i << 1) | 1] = f[i];\n        f[i << 1] = f[i];\n      }\n   \
    \ } else {\n      mint p = 1;\n      for (auto i : rev) f[i] *= p, p *= w;\n \
    \     f.resize(2 * m);\n      for (int i = m - 1; i >= 0; i--) {\n        f[(i\
    \ << 1) | 1] = -f[i];\n        f[i << 1] = f[i];\n      }\n    }\n    for (int\
    \ i = 0; i < 2 * m; i++) f[i] *= f1[i];\n    auto odd = fps(f.begin() + m, f.end());\n\
    \    odd.intt();\n    mint p = 1;\n    for (int i = 0; i < m; i++) odd[i] *= p,\
    \ p *= wi;\n    odd.ntt();\n    f.resize(m);\n    for (int i = 0; i < m; i++)\
    \ f[i] = (f[i] - odd[i]) * inv2;\n  };\n  rec(rec, n);\n  f.intt();\n  f.resize(k);\n\
    \  return f;\n}\n/**\n * @brief Inverse \u306E\u6B21\u6570\u30B7\u30D5\u30C8\n\
    \ * @docs docs/fps/inverse-shift.md\n */\n#line 6 \"fps/linearly-recurrent-sequence.hpp\"\
    \n\n// a[i]=sum[j=1~d]c[j]a[i-j], i>=d\n// find a[n]\ntemplate <class mint>\n\
    mint LinearyRecurrentSequence(FormalPowerSeries<mint> a, FormalPowerSeries<mint>\
    \ c, long long n) {\n  assert(a.size() == c.size());\n  if (n < a.size()) return\
    \ a[n];\n  while (!c.empty() && c.back() == 0) c.pop_back();\n  if (c.size() <\
    \ a.size()) {\n    int z = a.size() - c.size();\n    n -= z;\n    a.erase(a.begin(),\
    \ a.begin() + z);\n  }\n  int d = c.size();\n  FormalPowerSeries<mint> q(d + 1);\n\
    \  q[0] = 1;\n  for (int i = 0; i < d; i++) q[i + 1] = -c[i];\n  auto p = (a *\
    \ q).pre(d);\n  return BostanMori(p, q, n);\n}\n\n// a[i]=sum[j=1~d]c[j]a[i-j],\
    \ i>=d\n// find a[n],a[n+1],...,a[n+k-1]\ntemplate <class mint>\nFormalPowerSeries<mint>\
    \ LinearyRecurrentSequence(FormalPowerSeries<mint> a, FormalPowerSeries<mint>\
    \ c, long long n, int k) {\n  assert(a.size() == c.size());\n  if (n + k < a.size())\
    \ {\n    a >>= (int)n;\n    return a.pre(k);\n  }\n  while (!c.empty() && c.back()\
    \ == 0) c.pop_back();\n  int d = c.size();\n  FormalPowerSeries<mint> ret{};\n\
    \  if (c.size() < a.size()) {\n    int z = a.size() - c.size();\n    if (n < z)\
    \ {\n      ret.reserve(k);\n      for (int i = n; i < z; i++) ret.push_back(a[i]);\n\
    \    }\n    n -= z;\n    if (n < 0) {\n      k += n;\n      n = 0;\n    }\n  \
    \  a >>= z;\n  }\n  FormalPowerSeries<mint> q(d + 1);\n  q[0] = 1;\n  for (int\
    \ i = 0; i < d; i++) q[i + 1] = -c[i];\n  auto p = (a * q).pre(d);\n  if (n <\
    \ a.size()) {\n    p *= q.inv(n + k);\n    p >>= n;\n  } else {\n    p *= (InverseShift(q,\
    \ n) * q).pre(d);\n    p %= q;\n    p *= q.inv(k);\n  }\n  p.resize(k);\n  if\
    \ (ret.empty()) {\n    return p;\n  } else {\n    for (auto v : p) ret.push_back(v);\n\
    \    return ret;\n  }\n}\n\ntemplate <class mint>\nmint LinearyRecurrentSequence(FormalPowerSeries<mint>\
    \ a, long long n) {\n  if (n < a.size()) return a[n];\n  auto b = BerlekampMassey(a);\n\
    \  int d = b.size() - 1;\n  a.resize(d);\n  int z = 0;\n  while (b.back() == 0)\
    \ b.pop_back(), z++;\n  a >>= z;\n  n -= z;\n  d -= z;\n  return BostanMori((a\
    \ * b).pre(b.size()), b, n);\n}\n\n/**\n * @brief \u7DDA\u5F62\u6F38\u5316\u5F0F\
    \u7528\n * @docs docs/fps/linearly-recurrent-sequence.md\n */\n"
  code: "#pragma\n#include \"fps/formal-power-series.hpp\"\n#include \"fps/berlekamp-massey.hpp\"\
    \n#include \"fps/bostan-mori.hpp\"\n#include \"fps/inverse-shift.hpp\"\n\n// a[i]=sum[j=1~d]c[j]a[i-j],\
    \ i>=d\n// find a[n]\ntemplate <class mint>\nmint LinearyRecurrentSequence(FormalPowerSeries<mint>\
    \ a, FormalPowerSeries<mint> c, long long n) {\n  assert(a.size() == c.size());\n\
    \  if (n < a.size()) return a[n];\n  while (!c.empty() && c.back() == 0) c.pop_back();\n\
    \  if (c.size() < a.size()) {\n    int z = a.size() - c.size();\n    n -= z;\n\
    \    a.erase(a.begin(), a.begin() + z);\n  }\n  int d = c.size();\n  FormalPowerSeries<mint>\
    \ q(d + 1);\n  q[0] = 1;\n  for (int i = 0; i < d; i++) q[i + 1] = -c[i];\n  auto\
    \ p = (a * q).pre(d);\n  return BostanMori(p, q, n);\n}\n\n// a[i]=sum[j=1~d]c[j]a[i-j],\
    \ i>=d\n// find a[n],a[n+1],...,a[n+k-1]\ntemplate <class mint>\nFormalPowerSeries<mint>\
    \ LinearyRecurrentSequence(FormalPowerSeries<mint> a, FormalPowerSeries<mint>\
    \ c, long long n, int k) {\n  assert(a.size() == c.size());\n  if (n + k < a.size())\
    \ {\n    a >>= (int)n;\n    return a.pre(k);\n  }\n  while (!c.empty() && c.back()\
    \ == 0) c.pop_back();\n  int d = c.size();\n  FormalPowerSeries<mint> ret{};\n\
    \  if (c.size() < a.size()) {\n    int z = a.size() - c.size();\n    if (n < z)\
    \ {\n      ret.reserve(k);\n      for (int i = n; i < z; i++) ret.push_back(a[i]);\n\
    \    }\n    n -= z;\n    if (n < 0) {\n      k += n;\n      n = 0;\n    }\n  \
    \  a >>= z;\n  }\n  FormalPowerSeries<mint> q(d + 1);\n  q[0] = 1;\n  for (int\
    \ i = 0; i < d; i++) q[i + 1] = -c[i];\n  auto p = (a * q).pre(d);\n  if (n <\
    \ a.size()) {\n    p *= q.inv(n + k);\n    p >>= n;\n  } else {\n    p *= (InverseShift(q,\
    \ n) * q).pre(d);\n    p %= q;\n    p *= q.inv(k);\n  }\n  p.resize(k);\n  if\
    \ (ret.empty()) {\n    return p;\n  } else {\n    for (auto v : p) ret.push_back(v);\n\
    \    return ret;\n  }\n}\n\ntemplate <class mint>\nmint LinearyRecurrentSequence(FormalPowerSeries<mint>\
    \ a, long long n) {\n  if (n < a.size()) return a[n];\n  auto b = BerlekampMassey(a);\n\
    \  int d = b.size() - 1;\n  a.resize(d);\n  int z = 0;\n  while (b.back() == 0)\
    \ b.pop_back(), z++;\n  a >>= z;\n  n -= z;\n  d -= z;\n  return BostanMori((a\
    \ * b).pre(b.size()), b, n);\n}\n\n/**\n * @brief \u7DDA\u5F62\u6F38\u5316\u5F0F\
    \u7528\n * @docs docs/fps/linearly-recurrent-sequence.md\n */"
  dependsOn:
  - fps/formal-power-series.hpp
  - fps/berlekamp-massey.hpp
  - fps/bostan-mori.hpp
  - fps/inverse-shift.hpp
  isVerificationFile: false
  path: fps/linearly-recurrent-sequence.hpp
  requiredBy: []
  timestamp: '2025-10-21 21:13:36+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/fps/LC_consecutive_terms_of_linear_recurrent_sequence.test.cpp
  - verify/fps/LC_kth_term_of_linearly_recurrent_sequence.test.cpp
documentation_of: fps/linearly-recurrent-sequence.hpp
layout: document
redirect_from:
- /library/fps/linearly-recurrent-sequence.hpp
- /library/fps/linearly-recurrent-sequence.hpp.html
title: "\u7DDA\u5F62\u6F38\u5316\u5F0F\u7528"
---
線形漸化式に関するライブラリ．

- `a, c` を入力に含むとき，初項が $a_0,\dots,a_{d-1}$ で漸化式 $a_i=\sum_{j=1}^{d}c_{j-1}a_{i-j}$ で定まる数列．
- `a` のみを入力に含むとき，Berlekamp-Massey アルゴリズムで漸化式を推定した上で計算する．
- `n, k` を入力に含むとき，$a_n,a_{n+1},\dots,a_{n+k-1}$ を計算する．
- `n` のみを入力に含むとき，$a_n$ のみを計算する．


## 連続する項

https://noshi91.hatenablog.com/entry/2023/06/04/233447

$\deg P(x)\lt d,\deg Q(x)=d,[x^0]Q(x)\neq 0$ とする．

次を満たす $S(x)$ を求められればよい．
$$\frac{P(x)}{Q(x)}=R(x)+x^n\cdot\frac{S(x)}{Q(x)},\quad \deg R(x)\lt n,\deg S(x)\lt d$$

$P(x)=Q(x)R(x)+x^nS(x)$ であるから $S(x)=x^{-n}P(x)\bmod Q(x)$ と表せる．

$\frac{1}{Q(x)}$ の $x^n$ から $x^{n+d-1}$ の係数を求めれば $P(x)$ のときの $S(x)$，すなわち $x^{-n}\bmod Q(x)$ が求められる．

`inverse-shift.hpp` で実装．

実質的に $\deg P(x)\geq\deg Q(x)$ であるようなケースに注意する．

例えば $a=(0,0,1,1,1,1,\dots)$ のようなケースに Berlekamp-Massey を用いると $q=(1,-1,0,0)$ が得られる．

このような場合，$q$ の末尾の $0$ の個数分 $a$ の先頭を取り除けばよい．