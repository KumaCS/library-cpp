---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "Dirichlet \u7A4D\u306E prefix sum"
    links:
    - https://maspypy.com/dirichlet-%E7%A9%8D%E3%81%A8%E3%80%81%E6%95%B0%E8%AB%96%E9%96%A2%E6%95%B0%E3%81%AE%E7%B4%AF%E7%A9%8D%E5%92%8C
  bundledCode: "#line 2 \"number-theory/dirichlet-series-prefix-sum.hpp\"\n\n// https://maspypy.com/dirichlet-%E7%A9%8D%E3%81%A8%E3%80%81%E6%95%B0%E8%AB%96%E9%96%A2%E6%95%B0%E3%81%AE%E7%B4%AF%E7%A9%8D%E5%92%8C\n\
    /**\n * @brief Dirichlet \u7A4D\u306E prefix sum\n */\ntemplate <class mint>\n\
    struct DirichletSeriesPrefixSum {\n  using DP = DirichletSeriesPrefixSum<mint>;\n\
    \  using u64 = uint64_t;\n\n public:\n  u64 N;\n  size_t K, L;\n  vector<mint>\
    \ a, s, S;\n\n  DirichletSeriesPrefixSum(u64 n)\n      : N(n),\n        K(max(sqrt(N),\
    \ pow(max(1.0, N / log(N)), 2.0 / 3))),\n        L((N - 1) / K + 1) {\n    a.assign(K\
    \ + 1, 0);\n    s.assign(K + 1, 0);\n    S.assign(L + 1, 0);\n  }\n  DirichletSeriesPrefixSum(const\
    \ DP &d)\n      : N(d.N), K(d.K), L(d.L), a(d.a), s(d.s), S(d.S) {}\n  static\
    \ DP id(u64 n) {\n    DP z(n);\n    return z.add(1, 1);\n  }\n  // {floor(n/k):1<=k<=n}={x[0],...,x[m-1]},\
    \ x[i-1]<x[i]\n  // a[i]=sum_{1<=j<=x[i]}f(j)\n  DirichletSeriesPrefixSum(u64\
    \ n, const vector<mint> &a) {\n\n  }\n\n  // zeta(s-k)\n  static DP zeta(u64 n,\
    \ size_t k = 0) {\n    assert(k <= 2);\n    DP z(n);\n    for (size_t i = 1; i\
    \ <= z.K; i++) z.a[i] = mint(i).pow(k);\n    for (size_t i = 1; i <= z.K; i++)\
    \ z.s[i] = z.s[i - 1] + z.a[i];\n    for (size_t i = 1; i <= z.L; i++) {\n   \
    \   u64 x = n / i;\n      if (k == 0)\n        z.S[i] = x;\n      else if (k ==\
    \ 1)\n        z.S[i] = mint(x | 1) * mint((x + 1) / 2);\n      else if (k == 2)\
    \ {\n        array<u64, 3> xs{x, x + 1, 2 * x + 1};\n        xs[x & 1] /= 2;\n\
    \        xs[(3 - (x % 3)) % 3] /= 3;\n        z.S[i] = mint(xs[0]) * mint(xs[1])\
    \ * mint(xs[2]);\n      }\n    }\n    return z;\n  }\n\n  // n(n+1)...(n+k-1)/k!\n\
    \  static DP rising(u64 n, size_t k) {\n    if (k == 0) return zeta(n);\n    DP\
    \ z(n);\n    for (size_t i = 1; i <= z.K; i++) z.a[i] = rising_mint(i, k);\n \
    \   for (size_t i = 1; i <= z.K; i++) z.s[i] = z.s[i - 1] + z.a[i];\n    for (size_t\
    \ i = 1; i <= z.L; i++) {\n      u64 x = n / i;\n      z.S[i] = rising_mint(x,\
    \ k + 1);\n    }\n    return z;\n  }\n  // n(n-1)...(n-k+1)/k!\n  static DP falling(u64\
    \ n, size_t k) {\n    if (k == 0) return zeta(n);\n    DP z(n);\n    for (size_t\
    \ i = 1; i <= z.K; i++) z.a[i] = falling_mint(i, k);\n    for (size_t i = 1; i\
    \ <= z.K; i++) z.s[i] = z.s[i - 1] + z.a[i];\n    for (size_t i = 1; i <= z.L;\
    \ i++) {\n      u64 x = n / i;\n      z.S[i] = falling_mint(x + 1, k + 1);  //\
    \ -falling_mint(1, k + 1);\n    }\n    return z;\n  }\n\n  void calc_small_sum()\
    \ {\n    for (size_t i = 1; i <= K; i++) s[i] = s[i - 1] + a[i];\n  }\n\n  //\
    \ += v*x^(-s)\n  DP add(u64 x, mint v) {\n    DP f(*this);\n    if (1 <= x &&\
    \ x <= K) {\n      f.a[x] += v;\n      for (size_t i = x; i <= K; i++) f.s[i]\
    \ += v;\n    }\n    for (size_t i = 1; i <= L; i++)\n      if (x <= N / i) f.S[i]\
    \ += v;\n    return f;\n  }\n  // *= x^(-s)\n  DP shift(u64 x) {\n    DP f(N);\n\
    \    for (size_t i = 1; i <= K / x; i++) f.a[i * x] = a[i];\n    f.calc_small_sum();\n\
    \    for (size_t i = 1; i <= L; i++) {\n      u64 y = N / i / x;\n      f.S[i]\
    \ = y <= K ? s[y] : S[i * x];\n    }\n    return f;\n  }\n  DP inv() { return\
    \ id(N) / DP(*this); }\n\n  DP &operator+=(const DP &r) {\n    assert(N == r.N);\n\
    \    for (size_t i = 1; i <= K; i++) a[i] += r.a[i];\n    for (size_t i = 1; i\
    \ <= K; i++) s[i] += r.s[i];\n    for (size_t i = 1; i <= L; i++) S[i] += r.S[i];\n\
    \    return *this;\n  }\n  DP &operator-=(const DP &r) {\n    assert(N == r.N);\n\
    \    for (size_t i = 1; i <= K; i++) a[i] -= r.a[i];\n    for (size_t i = 1; i\
    \ <= K; i++) s[i] -= r.s[i];\n    for (size_t i = 1; i <= L; i++) S[i] -= r.S[i];\n\
    \    return *this;\n  }\n  DP &operator*=(const mint &r) {\n    for (auto &v :\
    \ a) v *= r;\n    for (auto &v : s) v *= r;\n    for (auto &v : S) v *= r;\n \
    \   return *this;\n  }\n  DP &operator*=(const DP &r) {\n    for (size_t i = 1;\
    \ i <= L; i++) {\n      mint v = 0;\n      size_t m = sqrt(N / i);\n      for\
    \ (size_t x = 1; x <= m; x++) {\n        u64 t = N / i / x;\n        v += a[x]\
    \ * (t <= K ? r.s[t] : r.S[i * x]);\n      }\n      for (size_t y = 1; y <= m;\
    \ y++) {\n        u64 t = N / i / y;\n        v += r.a[y] * ((t <= K ? s[t] :\
    \ S[i * y]) - s[m]);\n      }\n      S[i] = v;\n    }\n    for (size_t i = K;\
    \ i >= 1; i--) {\n      for (size_t j = 2; u64(i) * j <= K; j++) a[i * j] += a[i]\
    \ * r.a[j];\n      a[i] *= r.a[1];\n    }\n    calc_small_sum();\n    return *this;\n\
    \  }\n  DP &operator/=(const DP &r) {\n    mint inv = r.a[1].inv();\n    for (size_t\
    \ i = 1; i <= K; i++) {\n      a[i] *= inv;\n      for (size_t j = 2; u64(i) *\
    \ j <= K; j++) a[i * j] -= a[i] * r.a[j];\n      s[i] = s[i - 1] + a[i];\n   \
    \ }\n    for (size_t i = L; i >= 1; i--) {\n      size_t m = sqrt(N / i);\n  \
    \    for (size_t x = 1; x <= m; x++) {\n        u64 t = N / i / x;\n        S[i]\
    \ -= a[x] * (t <= K ? r.s[t] : r.S[i * x]);\n      }\n      for (size_t y = 2;\
    \ y <= m; y++) {\n        u64 t = N / i / y;\n        S[i] -= r.a[y] * ((t <=\
    \ K ? s[t] : S[i * y]) - s[m]);\n      }\n      S[i] *= inv;\n      S[i] += s[m];\n\
    \    }\n    return *this;\n  }\n  DP operator+(const DP &r) const { return DP(*this)\
    \ += r; }\n  DP operator-(const DP &r) const { return DP(*this) -= r; }\n  DP\
    \ operator*(const DP &r) const { return DP(*this) *= r; }\n  DP operator*(const\
    \ mint &r) const { return DP(*this) *= r; }\n  DP operator/(const DP &r) const\
    \ { return DP(*this) /= r; }\n\n  // sparse\n  DP &operator*=(const vector<pair<u64,\
    \ mint>> &r) {\n    DP f(N);\n    for (auto [x, v] : r) {\n      for (size_t i\
    \ = 1; i <= K / x; i++) f.a[i * x] += v * a[i];\n      for (size_t i = 1; i <=\
    \ L; i++) {\n        u64 t = N / i / x;\n        f.S[i] += v * (t <= K ? s[t]\
    \ : f.S[i * x]);\n      }\n    }\n    f.calc_small_sum();\n    return f;\n  }\n\
    \n  friend ostream &operator<<(ostream &os, const DP &f) {\n    os << \"a: \"\
    ;\n    for (size_t i = 1; i <= f.K; i++) os << f.a[i].val() << \",\\n\"[i == f.K];\n\
    \    os << \"s: \";\n    for (size_t i = 1; i <= f.K; i++) os << f.s[i].val()\
    \ << \",\\n\"[i == f.K];\n    os << \"S: \";\n    for (size_t i = f.L; i >= 1;\
    \ i--)\n      os << (f.N / i) << \":\" << f.S[i].val() << \",\\n\"[i == 1];\n\
    \    return os;\n  };\n\n private:\n  static mint rising_mint(i64 x, size_t k)\
    \ {\n    vector<i64> xs(k);\n    iota(xs.begin(), xs.end(), x);\n    for (i64\
    \ v = 2; v <= k; v++) {\n      i64 w = v;\n      for (auto &y : xs) {\n      \
    \  i64 g = gcd(w, y);\n        w /= g;\n        y /= g;\n      }\n      assert(w\
    \ == 1);\n    }\n    mint z = 1;\n    for (auto &y : xs) z *= y;\n    return z;\n\
    \  }\n  static mint falling_mint(i64 x, size_t k) {\n    return rising_mint(x\
    \ - k + 1, k);\n  }\n};\n"
  code: "#pragma once\n\n// https://maspypy.com/dirichlet-%E7%A9%8D%E3%81%A8%E3%80%81%E6%95%B0%E8%AB%96%E9%96%A2%E6%95%B0%E3%81%AE%E7%B4%AF%E7%A9%8D%E5%92%8C\n\
    /**\n * @brief Dirichlet \u7A4D\u306E prefix sum\n */\ntemplate <class mint>\n\
    struct DirichletSeriesPrefixSum {\n  using DP = DirichletSeriesPrefixSum<mint>;\n\
    \  using u64 = uint64_t;\n\n public:\n  u64 N;\n  size_t K, L;\n  vector<mint>\
    \ a, s, S;\n\n  DirichletSeriesPrefixSum(u64 n)\n      : N(n),\n        K(max(sqrt(N),\
    \ pow(max(1.0, N / log(N)), 2.0 / 3))),\n        L((N - 1) / K + 1) {\n    a.assign(K\
    \ + 1, 0);\n    s.assign(K + 1, 0);\n    S.assign(L + 1, 0);\n  }\n  DirichletSeriesPrefixSum(const\
    \ DP &d)\n      : N(d.N), K(d.K), L(d.L), a(d.a), s(d.s), S(d.S) {}\n  static\
    \ DP id(u64 n) {\n    DP z(n);\n    return z.add(1, 1);\n  }\n  // {floor(n/k):1<=k<=n}={x[0],...,x[m-1]},\
    \ x[i-1]<x[i]\n  // a[i]=sum_{1<=j<=x[i]}f(j)\n  DirichletSeriesPrefixSum(u64\
    \ n, const vector<mint> &a) {\n\n  }\n\n  // zeta(s-k)\n  static DP zeta(u64 n,\
    \ size_t k = 0) {\n    assert(k <= 2);\n    DP z(n);\n    for (size_t i = 1; i\
    \ <= z.K; i++) z.a[i] = mint(i).pow(k);\n    for (size_t i = 1; i <= z.K; i++)\
    \ z.s[i] = z.s[i - 1] + z.a[i];\n    for (size_t i = 1; i <= z.L; i++) {\n   \
    \   u64 x = n / i;\n      if (k == 0)\n        z.S[i] = x;\n      else if (k ==\
    \ 1)\n        z.S[i] = mint(x | 1) * mint((x + 1) / 2);\n      else if (k == 2)\
    \ {\n        array<u64, 3> xs{x, x + 1, 2 * x + 1};\n        xs[x & 1] /= 2;\n\
    \        xs[(3 - (x % 3)) % 3] /= 3;\n        z.S[i] = mint(xs[0]) * mint(xs[1])\
    \ * mint(xs[2]);\n      }\n    }\n    return z;\n  }\n\n  // n(n+1)...(n+k-1)/k!\n\
    \  static DP rising(u64 n, size_t k) {\n    if (k == 0) return zeta(n);\n    DP\
    \ z(n);\n    for (size_t i = 1; i <= z.K; i++) z.a[i] = rising_mint(i, k);\n \
    \   for (size_t i = 1; i <= z.K; i++) z.s[i] = z.s[i - 1] + z.a[i];\n    for (size_t\
    \ i = 1; i <= z.L; i++) {\n      u64 x = n / i;\n      z.S[i] = rising_mint(x,\
    \ k + 1);\n    }\n    return z;\n  }\n  // n(n-1)...(n-k+1)/k!\n  static DP falling(u64\
    \ n, size_t k) {\n    if (k == 0) return zeta(n);\n    DP z(n);\n    for (size_t\
    \ i = 1; i <= z.K; i++) z.a[i] = falling_mint(i, k);\n    for (size_t i = 1; i\
    \ <= z.K; i++) z.s[i] = z.s[i - 1] + z.a[i];\n    for (size_t i = 1; i <= z.L;\
    \ i++) {\n      u64 x = n / i;\n      z.S[i] = falling_mint(x + 1, k + 1);  //\
    \ -falling_mint(1, k + 1);\n    }\n    return z;\n  }\n\n  void calc_small_sum()\
    \ {\n    for (size_t i = 1; i <= K; i++) s[i] = s[i - 1] + a[i];\n  }\n\n  //\
    \ += v*x^(-s)\n  DP add(u64 x, mint v) {\n    DP f(*this);\n    if (1 <= x &&\
    \ x <= K) {\n      f.a[x] += v;\n      for (size_t i = x; i <= K; i++) f.s[i]\
    \ += v;\n    }\n    for (size_t i = 1; i <= L; i++)\n      if (x <= N / i) f.S[i]\
    \ += v;\n    return f;\n  }\n  // *= x^(-s)\n  DP shift(u64 x) {\n    DP f(N);\n\
    \    for (size_t i = 1; i <= K / x; i++) f.a[i * x] = a[i];\n    f.calc_small_sum();\n\
    \    for (size_t i = 1; i <= L; i++) {\n      u64 y = N / i / x;\n      f.S[i]\
    \ = y <= K ? s[y] : S[i * x];\n    }\n    return f;\n  }\n  DP inv() { return\
    \ id(N) / DP(*this); }\n\n  DP &operator+=(const DP &r) {\n    assert(N == r.N);\n\
    \    for (size_t i = 1; i <= K; i++) a[i] += r.a[i];\n    for (size_t i = 1; i\
    \ <= K; i++) s[i] += r.s[i];\n    for (size_t i = 1; i <= L; i++) S[i] += r.S[i];\n\
    \    return *this;\n  }\n  DP &operator-=(const DP &r) {\n    assert(N == r.N);\n\
    \    for (size_t i = 1; i <= K; i++) a[i] -= r.a[i];\n    for (size_t i = 1; i\
    \ <= K; i++) s[i] -= r.s[i];\n    for (size_t i = 1; i <= L; i++) S[i] -= r.S[i];\n\
    \    return *this;\n  }\n  DP &operator*=(const mint &r) {\n    for (auto &v :\
    \ a) v *= r;\n    for (auto &v : s) v *= r;\n    for (auto &v : S) v *= r;\n \
    \   return *this;\n  }\n  DP &operator*=(const DP &r) {\n    for (size_t i = 1;\
    \ i <= L; i++) {\n      mint v = 0;\n      size_t m = sqrt(N / i);\n      for\
    \ (size_t x = 1; x <= m; x++) {\n        u64 t = N / i / x;\n        v += a[x]\
    \ * (t <= K ? r.s[t] : r.S[i * x]);\n      }\n      for (size_t y = 1; y <= m;\
    \ y++) {\n        u64 t = N / i / y;\n        v += r.a[y] * ((t <= K ? s[t] :\
    \ S[i * y]) - s[m]);\n      }\n      S[i] = v;\n    }\n    for (size_t i = K;\
    \ i >= 1; i--) {\n      for (size_t j = 2; u64(i) * j <= K; j++) a[i * j] += a[i]\
    \ * r.a[j];\n      a[i] *= r.a[1];\n    }\n    calc_small_sum();\n    return *this;\n\
    \  }\n  DP &operator/=(const DP &r) {\n    mint inv = r.a[1].inv();\n    for (size_t\
    \ i = 1; i <= K; i++) {\n      a[i] *= inv;\n      for (size_t j = 2; u64(i) *\
    \ j <= K; j++) a[i * j] -= a[i] * r.a[j];\n      s[i] = s[i - 1] + a[i];\n   \
    \ }\n    for (size_t i = L; i >= 1; i--) {\n      size_t m = sqrt(N / i);\n  \
    \    for (size_t x = 1; x <= m; x++) {\n        u64 t = N / i / x;\n        S[i]\
    \ -= a[x] * (t <= K ? r.s[t] : r.S[i * x]);\n      }\n      for (size_t y = 2;\
    \ y <= m; y++) {\n        u64 t = N / i / y;\n        S[i] -= r.a[y] * ((t <=\
    \ K ? s[t] : S[i * y]) - s[m]);\n      }\n      S[i] *= inv;\n      S[i] += s[m];\n\
    \    }\n    return *this;\n  }\n  DP operator+(const DP &r) const { return DP(*this)\
    \ += r; }\n  DP operator-(const DP &r) const { return DP(*this) -= r; }\n  DP\
    \ operator*(const DP &r) const { return DP(*this) *= r; }\n  DP operator*(const\
    \ mint &r) const { return DP(*this) *= r; }\n  DP operator/(const DP &r) const\
    \ { return DP(*this) /= r; }\n\n  // sparse\n  DP &operator*=(const vector<pair<u64,\
    \ mint>> &r) {\n    DP f(N);\n    for (auto [x, v] : r) {\n      for (size_t i\
    \ = 1; i <= K / x; i++) f.a[i * x] += v * a[i];\n      for (size_t i = 1; i <=\
    \ L; i++) {\n        u64 t = N / i / x;\n        f.S[i] += v * (t <= K ? s[t]\
    \ : f.S[i * x]);\n      }\n    }\n    f.calc_small_sum();\n    return f;\n  }\n\
    \n  friend ostream &operator<<(ostream &os, const DP &f) {\n    os << \"a: \"\
    ;\n    for (size_t i = 1; i <= f.K; i++) os << f.a[i].val() << \",\\n\"[i == f.K];\n\
    \    os << \"s: \";\n    for (size_t i = 1; i <= f.K; i++) os << f.s[i].val()\
    \ << \",\\n\"[i == f.K];\n    os << \"S: \";\n    for (size_t i = f.L; i >= 1;\
    \ i--)\n      os << (f.N / i) << \":\" << f.S[i].val() << \",\\n\"[i == 1];\n\
    \    return os;\n  };\n\n private:\n  static mint rising_mint(i64 x, size_t k)\
    \ {\n    vector<i64> xs(k);\n    iota(xs.begin(), xs.end(), x);\n    for (i64\
    \ v = 2; v <= k; v++) {\n      i64 w = v;\n      for (auto &y : xs) {\n      \
    \  i64 g = gcd(w, y);\n        w /= g;\n        y /= g;\n      }\n      assert(w\
    \ == 1);\n    }\n    mint z = 1;\n    for (auto &y : xs) z *= y;\n    return z;\n\
    \  }\n  static mint falling_mint(i64 x, size_t k) {\n    return rising_mint(x\
    \ - k + 1, k);\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: number-theory/dirichlet-series-prefix-sum.hpp
  requiredBy: []
  timestamp: '2025-10-10 17:35:46+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: number-theory/dirichlet-series-prefix-sum.hpp
layout: document
redirect_from:
- /library/number-theory/dirichlet-series-prefix-sum.hpp
- /library/number-theory/dirichlet-series-prefix-sum.hpp.html
title: "Dirichlet \u7A4D\u306E prefix sum"
---
