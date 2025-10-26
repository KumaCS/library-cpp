---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: fps/formal-power-series.hpp
    title: fps/formal-power-series.hpp
  - icon: ':question:'
    path: modint/factorial.hpp
    title: "\u968E\u4E57, \u4E8C\u9805\u4FC2\u6570"
  - icon: ':question:'
    path: modint/mod-pow.hpp
    title: modint/mod-pow.hpp
  - icon: ':question:'
    path: modint/mod-sqrt.hpp
    title: modint/mod-sqrt.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/fps/LC_convolution_mod.relaxed.test.cpp
    title: verify/fps/LC_convolution_mod.relaxed.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/fps/LC_convolution_mod.semirelaxed.test.cpp
    title: verify/fps/LC_convolution_mod.semirelaxed.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/fps/LC_exp_of_formal_power_series.relaxed.test.cpp
    title: verify/fps/LC_exp_of_formal_power_series.relaxed.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/fps/LC_inv_of_formal_power_series.relaxed.test.cpp
    title: verify/fps/LC_inv_of_formal_power_series.relaxed.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/fps/LC_log_of_formal_power_series.relaxed.test.cpp
    title: verify/fps/LC_log_of_formal_power_series.relaxed.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/fps/LC_sqrt_of_formal_power_series.relaxed.test.cpp
    title: verify/fps/LC_sqrt_of_formal_power_series.relaxed.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/fps/relaxed.md
    document_title: Relaxed
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
    \ = nullptr;\n#line 2 \"modint/mod-sqrt.hpp\"\n\n#line 2 \"modint/mod-pow.hpp\"\
    \n\nunsigned int ModPow(unsigned int a, unsigned long long n, unsigned int m)\
    \ {\n  unsigned long long x = a, y = 1;\n  while (n) {\n    if (n & 1) y = y *\
    \ x % m;\n    x = x * x % m;\n    n >>= 1;\n  }\n  return y;\n}\n#line 4 \"modint/mod-sqrt.hpp\"\
    \n\nlong long ModSqrt(long long a, long long p) {\n  if (a >= p) a %= p;\n  if\
    \ (p == 2) return a & 1;\n  if (a == 0) return 0;\n  if (ModPow(a, (p - 1) / 2,\
    \ p) != 1) return -1;\n  if (p % 4 == 3) return ModPow(a, (3 * p - 1) / 4, p);\n\
    \  unsigned int z = 2, q = p - 1;\n  while (ModPow(z, (p - 1) / 2, p) == 1) z++;\n\
    \  int s = 0;\n  while (!(q & 1)) {\n    s++;\n    q >>= 1;\n  }\n  int m = s;\n\
    \  unsigned int c = ModPow(z, q, p);\n  unsigned int t = ModPow(a, q, p);\n  unsigned\
    \ int r = ModPow(a, (q + 1) / 2, p);\n  while (true) {\n    if (t == 1) return\
    \ r;\n    unsigned int pow = t;\n    int j = 1;\n    for (; j < m; j++) {\n  \
    \    pow = 1ll * pow * pow % p;\n      if (pow == 1) break;\n    }\n    unsigned\
    \ int b = c;\n    for (int i = 0; i < m - j - 1; i++) b = 1ll * b * b % p;\n \
    \   m = j;\n    c = 1ll * b * b % p;\n    t = 1ll * t * c % p;\n    r = 1ll *\
    \ r * b % p;\n  }\n}\n#line 5 \"fps/relaxed.hpp\"\n\ntemplate <class mint>\nclass\
    \ RelaxedMultiply {\n  const int B = 6;\n  using fps = FormalPowerSeries<mint>;\n\
    \  int n;\n  fps f, g, h;\n  vector<fps> f0, g0;\n\n public:\n  RelaxedMultiply()\
    \ : n(0), f(1), g(1), f0(B), g0(B) {}\n  mint append(mint a, mint b) {\n    f[n]\
    \ = a, g[n] = b;\n    n++;\n    int m = n & -n;\n    int l = __builtin_ctz((unsigned\
    \ int)m);\n    if (n == m) {\n      f.resize(2 * m);\n      g.resize(2 * m);\n\
    \      h.resize(2 * m);\n      if (l < B) {\n        for (int i = 0; i < m; i++)\n\
    \          for (int j = m - 1 - i; j < m; j++)\n            h[i + j] += f[i] *\
    \ g[j];\n      } else {\n        auto f1 = f;\n        f1.ntt();\n        f0.push_back(fps(f1.begin(),\
    \ f1.begin() + m));\n        auto g1 = g;\n        g1.ntt();\n        g0.push_back(fps(g1.begin(),\
    \ g1.begin() + m));\n        for (int i = 0; i < 2 * m; i++) f1[i] *= g1[i];\n\
    \        f1.intt();\n        for (int i = m - 1; i < 2 * m - 1; i++) h[i] += f1[i];\n\
    \      }\n    } else {\n      if (l < B) {\n        int s = n - m;\n        for\
    \ (int i = 0; i < m; i++) {\n          int t = m - 1 - i;\n          for (int\
    \ j = 0; j < m; j++)\n            h[n - 1 + j] += f[s + i] * g[t + j] + g[s +\
    \ i] * f[t + j];\n        }\n      } else {\n        fps f1(2 * m), g1(2 * m),\
    \ h1(2 * m);\n        copy(f.begin() + (n - m), f.begin() + n, f1.begin());\n\
    \        copy(g.begin() + (n - m), g.begin() + n, g1.begin());\n        f1.ntt(),\
    \ g1.ntt();\n        for (int i = 0; i < 2 * m; i++) h1[i] += f1[i] * g0[l + 1][i]\
    \ + f0[l + 1][i] * g1[i];\n        h1.intt();\n        for (int i = m - 1; i <\
    \ 2 * m - 1; i++) h[n - m + i] += h1[i];\n      }\n    }\n    return h[n - 1];\n\
    \  }\n};\n\ntemplate <class mint>\nclass SemiRelaxedMultiply {\n  const int B\
    \ = 6;\n  using fps = FormalPowerSeries<mint>;\n  int n, m0;\n  fps f, g, h;\n\
    \  vector<fps> g0;\n\n public:\n  SemiRelaxedMultiply(const fps& g_) : n(0), m0(1\
    \ << B), f(1), g(g_) {\n    while (m0 < g.size()) m0 <<= 1;\n    g.resize(m0);\n\
    \    for (int k = 1; k <= m0; k <<= 1) {\n      fps g1(2 * k);\n      copy(g.begin(),\
    \ g.begin() + min(2 * k, m0), g1.begin());\n      g1.ntt();\n      g0.push_back(g1);\n\
    \    }\n  }\n  mint append(mint a) {\n    f[n] = a;\n    n++;\n    int m = n &\
    \ -n;\n    int l = __builtin_ctz((unsigned int)m);\n    if (n == m) {\n      f.resize(2\
    \ * m);\n      h.resize(2 * m);\n    }\n    while (l >= g0.size()) {\n      g0.push_back(g0.back());\n\
    \      g0.back().ntt_doubling();\n    }\n    if (l < B) {\n      int s = n - m;\n\
    \      for (int i = 0; i < m; i++) {\n        int t = m - 1 - i;\n        for\
    \ (int j = 0; j < m; j++)\n          h[n - 1 + j] += f[s + i] * g[t + j];\n  \
    \    }\n    } else {\n      fps f1(2 * m);\n      copy(f.begin() + (n - m), f.begin()\
    \ + n, f1.begin());\n      f1.ntt();\n      for (int i = 0; i < 2 * m; i++) f1[i]\
    \ *= g0[l][i];\n      f1.intt();\n      for (int i = m - 1; i < 2 * m - 1; i++)\
    \ h[n - m + i] += f1[i];\n    }\n    return h[n - 1];\n  }\n};\n\n// f(x)/g(x)\n\
    template <class mint>\nclass RelaxedDivide {\n  RelaxedMultiply<mint> mul;\n \
    \ int n;\n  mint c, v;\n\n public:\n  RelaxedDivide() : n(0) {}\n  mint append(mint\
    \ a, mint b) { return v = n++ == 0 ? a * (c = b.inv()) : (a - mul.append(v, b))\
    \ * c; }\n};\n\ntemplate <class mint>\nclass RelaxedInv {\n  RelaxedMultiply<mint>\
    \ mul;\n  int n;\n  mint c, v;\n\n public:\n  RelaxedInv() : n(0) {}\n  mint append(mint\
    \ a) { return v = n++ == 0 ? (c = a.inv()) : -mul.append(v, a) * c; }\n};\n\n\
    template <class mint>\nclass RelaxedExp {\n  using fact = Factorial<mint>;\n \
    \ RelaxedMultiply<mint> mul;\n  int n;\n  mint v;\n\n public:\n  RelaxedExp()\
    \ : n(0) {}\n  mint append(mint a) {\n    if (n++ == 0) {\n      assert(a == 0);\n\
    \      v = 1;\n    } else {\n      v = mul.append((n - 1) * a, v) * fact::inv(n\
    \ - 1);\n    }\n    return v;\n  }\n};\n\ntemplate <class mint>\nclass RelaxedLog\
    \ {\n  using fact = Factorial<mint>;\n  RelaxedMultiply<mint> mul;\n  int n;\n\
    \  mint a0, v;\n\n public:\n  RelaxedLog() : n(0) {}\n  mint append(mint a) {\n\
    \    if (n == 0) {\n      assert(a == 1);\n      n++;\n      return 0;\n    }\
    \ else if (n == 1) {\n      a0 = a, n++;\n      return v = a;\n    } else {\n\
    \      v = n * a - mul.append(v, a0);\n      a0 = a;\n      return v * fact::inv(n++);\n\
    \    }\n  }\n};\n\ntemplate <class mint>\nclass RelaxedSqrt {\n  RelaxedMultiply<mint>\
    \ mul;\n  int n;\n  mint c, v;\n\n public:\n  RelaxedSqrt() : n(0) {}\n  mint\
    \ append(mint a) {\n    if (n == 0) {\n      long long sq = ModSqrt(a.val(), mint::get_mod());\n\
    \      assert(sq != -1 && sq != 0);\n      c = mint(2 * sq).inv();\n      n++;\n\
    \      return sq;\n    } else {\n      return v = (n++ == 1 ? a : a - mul.append(v,\
    \ v)) * c;\n    }\n  }\n};\n\n/**\n * @brief Relaxed \n * @docs docs/fps/relaxed.md\n\
    \ */\n"
  code: "#pragma once\n#include \"modint/factorial.hpp\"\n#include \"fps/formal-power-series.hpp\"\
    \n#include \"modint/mod-sqrt.hpp\"\n\ntemplate <class mint>\nclass RelaxedMultiply\
    \ {\n  const int B = 6;\n  using fps = FormalPowerSeries<mint>;\n  int n;\n  fps\
    \ f, g, h;\n  vector<fps> f0, g0;\n\n public:\n  RelaxedMultiply() : n(0), f(1),\
    \ g(1), f0(B), g0(B) {}\n  mint append(mint a, mint b) {\n    f[n] = a, g[n] =\
    \ b;\n    n++;\n    int m = n & -n;\n    int l = __builtin_ctz((unsigned int)m);\n\
    \    if (n == m) {\n      f.resize(2 * m);\n      g.resize(2 * m);\n      h.resize(2\
    \ * m);\n      if (l < B) {\n        for (int i = 0; i < m; i++)\n          for\
    \ (int j = m - 1 - i; j < m; j++)\n            h[i + j] += f[i] * g[j];\n    \
    \  } else {\n        auto f1 = f;\n        f1.ntt();\n        f0.push_back(fps(f1.begin(),\
    \ f1.begin() + m));\n        auto g1 = g;\n        g1.ntt();\n        g0.push_back(fps(g1.begin(),\
    \ g1.begin() + m));\n        for (int i = 0; i < 2 * m; i++) f1[i] *= g1[i];\n\
    \        f1.intt();\n        for (int i = m - 1; i < 2 * m - 1; i++) h[i] += f1[i];\n\
    \      }\n    } else {\n      if (l < B) {\n        int s = n - m;\n        for\
    \ (int i = 0; i < m; i++) {\n          int t = m - 1 - i;\n          for (int\
    \ j = 0; j < m; j++)\n            h[n - 1 + j] += f[s + i] * g[t + j] + g[s +\
    \ i] * f[t + j];\n        }\n      } else {\n        fps f1(2 * m), g1(2 * m),\
    \ h1(2 * m);\n        copy(f.begin() + (n - m), f.begin() + n, f1.begin());\n\
    \        copy(g.begin() + (n - m), g.begin() + n, g1.begin());\n        f1.ntt(),\
    \ g1.ntt();\n        for (int i = 0; i < 2 * m; i++) h1[i] += f1[i] * g0[l + 1][i]\
    \ + f0[l + 1][i] * g1[i];\n        h1.intt();\n        for (int i = m - 1; i <\
    \ 2 * m - 1; i++) h[n - m + i] += h1[i];\n      }\n    }\n    return h[n - 1];\n\
    \  }\n};\n\ntemplate <class mint>\nclass SemiRelaxedMultiply {\n  const int B\
    \ = 6;\n  using fps = FormalPowerSeries<mint>;\n  int n, m0;\n  fps f, g, h;\n\
    \  vector<fps> g0;\n\n public:\n  SemiRelaxedMultiply(const fps& g_) : n(0), m0(1\
    \ << B), f(1), g(g_) {\n    while (m0 < g.size()) m0 <<= 1;\n    g.resize(m0);\n\
    \    for (int k = 1; k <= m0; k <<= 1) {\n      fps g1(2 * k);\n      copy(g.begin(),\
    \ g.begin() + min(2 * k, m0), g1.begin());\n      g1.ntt();\n      g0.push_back(g1);\n\
    \    }\n  }\n  mint append(mint a) {\n    f[n] = a;\n    n++;\n    int m = n &\
    \ -n;\n    int l = __builtin_ctz((unsigned int)m);\n    if (n == m) {\n      f.resize(2\
    \ * m);\n      h.resize(2 * m);\n    }\n    while (l >= g0.size()) {\n      g0.push_back(g0.back());\n\
    \      g0.back().ntt_doubling();\n    }\n    if (l < B) {\n      int s = n - m;\n\
    \      for (int i = 0; i < m; i++) {\n        int t = m - 1 - i;\n        for\
    \ (int j = 0; j < m; j++)\n          h[n - 1 + j] += f[s + i] * g[t + j];\n  \
    \    }\n    } else {\n      fps f1(2 * m);\n      copy(f.begin() + (n - m), f.begin()\
    \ + n, f1.begin());\n      f1.ntt();\n      for (int i = 0; i < 2 * m; i++) f1[i]\
    \ *= g0[l][i];\n      f1.intt();\n      for (int i = m - 1; i < 2 * m - 1; i++)\
    \ h[n - m + i] += f1[i];\n    }\n    return h[n - 1];\n  }\n};\n\n// f(x)/g(x)\n\
    template <class mint>\nclass RelaxedDivide {\n  RelaxedMultiply<mint> mul;\n \
    \ int n;\n  mint c, v;\n\n public:\n  RelaxedDivide() : n(0) {}\n  mint append(mint\
    \ a, mint b) { return v = n++ == 0 ? a * (c = b.inv()) : (a - mul.append(v, b))\
    \ * c; }\n};\n\ntemplate <class mint>\nclass RelaxedInv {\n  RelaxedMultiply<mint>\
    \ mul;\n  int n;\n  mint c, v;\n\n public:\n  RelaxedInv() : n(0) {}\n  mint append(mint\
    \ a) { return v = n++ == 0 ? (c = a.inv()) : -mul.append(v, a) * c; }\n};\n\n\
    template <class mint>\nclass RelaxedExp {\n  using fact = Factorial<mint>;\n \
    \ RelaxedMultiply<mint> mul;\n  int n;\n  mint v;\n\n public:\n  RelaxedExp()\
    \ : n(0) {}\n  mint append(mint a) {\n    if (n++ == 0) {\n      assert(a == 0);\n\
    \      v = 1;\n    } else {\n      v = mul.append((n - 1) * a, v) * fact::inv(n\
    \ - 1);\n    }\n    return v;\n  }\n};\n\ntemplate <class mint>\nclass RelaxedLog\
    \ {\n  using fact = Factorial<mint>;\n  RelaxedMultiply<mint> mul;\n  int n;\n\
    \  mint a0, v;\n\n public:\n  RelaxedLog() : n(0) {}\n  mint append(mint a) {\n\
    \    if (n == 0) {\n      assert(a == 1);\n      n++;\n      return 0;\n    }\
    \ else if (n == 1) {\n      a0 = a, n++;\n      return v = a;\n    } else {\n\
    \      v = n * a - mul.append(v, a0);\n      a0 = a;\n      return v * fact::inv(n++);\n\
    \    }\n  }\n};\n\ntemplate <class mint>\nclass RelaxedSqrt {\n  RelaxedMultiply<mint>\
    \ mul;\n  int n;\n  mint c, v;\n\n public:\n  RelaxedSqrt() : n(0) {}\n  mint\
    \ append(mint a) {\n    if (n == 0) {\n      long long sq = ModSqrt(a.val(), mint::get_mod());\n\
    \      assert(sq != -1 && sq != 0);\n      c = mint(2 * sq).inv();\n      n++;\n\
    \      return sq;\n    } else {\n      return v = (n++ == 1 ? a : a - mul.append(v,\
    \ v)) * c;\n    }\n  }\n};\n\n/**\n * @brief Relaxed \n * @docs docs/fps/relaxed.md\n\
    \ */"
  dependsOn:
  - modint/factorial.hpp
  - fps/formal-power-series.hpp
  - modint/mod-sqrt.hpp
  - modint/mod-pow.hpp
  isVerificationFile: false
  path: fps/relaxed.hpp
  requiredBy: []
  timestamp: '2025-10-26 03:52:03+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/fps/LC_inv_of_formal_power_series.relaxed.test.cpp
  - verify/fps/LC_convolution_mod.relaxed.test.cpp
  - verify/fps/LC_convolution_mod.semirelaxed.test.cpp
  - verify/fps/LC_exp_of_formal_power_series.relaxed.test.cpp
  - verify/fps/LC_log_of_formal_power_series.relaxed.test.cpp
  - verify/fps/LC_sqrt_of_formal_power_series.relaxed.test.cpp
documentation_of: fps/relaxed.hpp
layout: document
redirect_from:
- /library/fps/relaxed.hpp
- /library/fps/relaxed.hpp.html
title: Relaxed
---
多項式 $f(x),g(x)$ について $i=0,1,\dots$ について順に以下を処理する．

> $[x^i]f(x),[x^i]g(x)$ が新しく与えられる．$[x^i]f(x)g(x)$ を返す．

$N$ 次まで求めるとき $O(N(\log N)^2)$ 時間．

$g$ がはじめからわかっている場合 (semi-relaxed convolution) は定数倍が改善できる．

また inv/exp/log/sqrt なども積と同じ計算量で求められる．

## 積

適切に分割してまとめて計算する．

通常の畳み込みよりも middle product の方が相性がよい．

- https://qiita.com/Kiri8128/items/1738d5403764a0e26b4c

上の資料で middle product の項で提示されている形よりは以下の形の方が扱いやすいはず

![](https://kumacs.github.io/library-cpp/relaxed.png)

## inv / FPS 除算

より一般に $h(x)=f(x)/g(x)$ を求めることができる（$[x^0]g(x)\neq 0$）．

$f=gh$ より任意の $i$ に対し

$$h_i=\frac{1}{g_0}\left(f_i-\sum_{j=0}^{i-1}h_{i-1-j}g_{j+1}\right)$$

であるから積の計算に帰着される（特に定数倍は変化しない）．

## exp

$g(x)=\exp f(x)\ ([x^0]f(x)=0)$ のとき $g_0=1$ である．また $g'=f'g$ より $1$ 次以上の部分は積の計算に帰着される．

## log

$g(x)=\log f(x)\ ([x^0]f(x)=1)$ のとき $g_0=0$ である．また $g'=f'/f$ より $1$ 次以上の部分は FPS の除算に帰着される．

## sqrt

$g(x)=\sqrt{f(x)}\ ([x^0]f(x)\neq 0)$ のとき $g_0=\sqrt{f_0}$ である．また $g^2=f$ より $i\geq 1$ について

$$2g_0g_i+\sum_{j=1}^{i-1}g_jg_{i-j}=f_i$$

であるから積の計算に帰着できる．
