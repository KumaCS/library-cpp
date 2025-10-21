---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: math/floor-monoid-product.hpp
    title: "\u30E2\u30CE\u30A4\u30C9\u7248 Floor Sum"
  - icon: ':x:'
    path: math/util.hpp
    title: math/util.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/math/polynomial-floor-sum.md
    document_title: "\u591A\u9805\u5F0F\u7248 floor sum"
    links: []
  bundledCode: "#line 2 \"math/util.hpp\"\n\nnamespace Math {\ntemplate <class T>\n\
    T safe_mod(T a, T b) {\n  assert(b != 0);\n  if (b < 0) a = -a, b = -b;\n  a %=\
    \ b;\n  return a >= 0 ? a : a + b;\n}\ntemplate <class T>\nT floor(T a, T b) {\n\
    \  assert(b != 0);\n  if (b < 0) a = -a, b = -b;\n  return a >= 0 ? a / b : (a\
    \ + 1) / b - 1;\n}\ntemplate <class T>\nT ceil(T a, T b) {\n  assert(b != 0);\n\
    \  if (b < 0) a = -a, b = -b;\n  return a > 0 ? (a - 1) / b + 1 : a / b;\n}\n\
    long long isqrt(long long n) {\n  if (n <= 0) return 0;\n  long long x = sqrt(n);\n\
    \  while ((x + 1) * (x + 1) <= n) x++;\n  while (x * x > n) x--;\n  return x;\n\
    }\n// return g=gcd(a,b)\n// a*x+b*y=g\n// - b!=0 -> 0<=x<|b|/g\n// - b=0  -> ax=g\n\
    template <class T>\nT ext_gcd(T a, T b, T& x, T& y) {\n  T a0 = a, b0 = b;\n \
    \ bool sgn_a = a < 0, sgn_b = b < 0;\n  if (sgn_a) a = -a;\n  if (sgn_b) b = -b;\n\
    \  if (b == 0) {\n    x = sgn_a ? -1 : 1;\n    y = 0;\n    return a;\n  }\n  T\
    \ x00 = 1, x01 = 0, x10 = 0, x11 = 1;\n  while (b != 0) {\n    T q = a / b, r\
    \ = a - b * q;\n    x00 -= q * x01;\n    x10 -= q * x11;\n    swap(x00, x01);\n\
    \    swap(x10, x11);\n    a = b, b = r;\n  }\n  x = x00, y = x10;\n  if (sgn_a)\
    \ x = -x;\n  if (sgn_b) y = -y;\n  if (b0 != 0) {\n    a0 /= a, b0 /= a;\n   \
    \ if (b0 < 0) a0 = -a0, b0 = -b0;\n    T q = x >= 0 ? x / b0 : (x + 1) / b0 -\
    \ 1;\n    x -= b0 * q;\n    y += a0 * q;\n  }\n  return a;\n}\ntemplate <class\
    \ T>\nT inv_mod(T x, T m) {\n  x %= m;\n  if (x < 0) x += m;\n  T a = m, b = x;\n\
    \  T y0 = 0, y1 = 1;\n  while (b > 0) {\n    T q = a / b;\n    swap(a -= q * b,\
    \ b);\n    swap(y0 -= q * y1, y1);\n  }\n  if (y0 < 0) y0 += m / a;\n  return\
    \ y0;\n}\ntemplate <class T>\nT pow_mod(T x, T n, T m) {\n  x = (x % m + m) %\
    \ m;\n  T y = 1;\n  while (n) {\n    if (n & 1) y = y * x % m;\n    x = x * x\
    \ % m;\n    n >>= 1;\n  }\n  return y;\n}\nconstexpr long long pow_mod_constexpr(long\
    \ long x, long long n, int m) {\n  if (m == 1) return 0;\n  unsigned int _m =\
    \ (unsigned int)(m);\n  unsigned long long r = 1;\n  unsigned long long y = x\
    \ % m;\n  if (y >= m) y += m;\n  while (n) {\n    if (n & 1) r = (r * y) % _m;\n\
    \    y = (y * y) % _m;\n    n >>= 1;\n  }\n  return r;\n}\n};  // namespace Math\n\
    #line 2 \"math/floor-monoid-product.hpp\"\n\ntemplate <class T, T (*op)(T, T),\
    \ T (*e)(), std::unsigned_integral U = uint64_t>\nT FloorMonoidProduct(U n, U\
    \ m, U a, U b, T x, T y, function<T(T, U)> pow = nullptr) {\n  if (!pow) {\n \
    \   pow = [](T t, U n) {\n      T p = e();\n      while (n) {\n        if (n &\
    \ 1) p = op(p, t);\n        t = op(t, t);\n        n >>= 1;\n      }\n      return\
    \ p;\n    };\n  }\n  assert(m != 0);\n  T pl = e(), pr = e();\n  while (true)\
    \ {\n    if (a >= m) {\n      U q = a / m;\n      x = op(x, pow(y, q));\n    \
    \  a -= m * q;\n    }\n    if (b >= m) {\n      U q = b / m;\n      pl = op(pl,\
    \ pow(y, q));\n      b -= m * q;\n    }\n    U c = a * n + b;\n    if (c < m)\
    \ {\n      pl = op(pl, pow(x, n));\n      break;\n    }\n    pr = op(op(y, pow(x,\
    \ c % m / a)), pr);\n    n = c / m - 1;\n    b = m + a - b - 1;\n    swap(a, m);\n\
    \    swap(x, y);\n  }\n  return op(pl, pr);\n}\n\n/**\n * @brief \u30E2\u30CE\u30A4\
    \u30C9\u7248 Floor Sum\n * @docs docs/math/floor-monoid-product.md\n */\n#line\
    \ 4 \"math/polynomial-floor-sum.hpp\"\n\ntemplate <class T, int D1, int D2>\n\
    struct PolynomialFloorSumMonoid {\n  static constexpr int D = max(D1, D2);\n \
    \ using M = PolynomialFloorSumMonoid;\n  using P = array<array<T, D2 + 1>, D1\
    \ + 1>;\n  T x, y;\n  P f;\n  static M e() { return {0, 0, P{}}; }\n  static M\
    \ op(M a, M b) {\n    static T binom[D + 1][D + 1];\n    if (binom[0][0] != T(1))\
    \ {\n      binom[0][0] = T(1);\n      for (int i = 0; i < D; i++)\n        for\
    \ (int j = 0; j <= i; j++) {\n          binom[i + 1][j] += binom[i][j];\n    \
    \      binom[i + 1][j + 1] += binom[i][j];\n        }\n    }\n    T pow_x[D1 +\
    \ 1], pow_y[D2 + 1];\n    pow_x[0] = 1, pow_y[0] = 1;\n    for (int i = 0; i <\
    \ D1; i++) pow_x[i + 1] = pow_x[i] * a.x;\n    for (int i = 0; i < D2; i++) pow_y[i\
    \ + 1] = pow_y[i] * a.y;\n    for (int i = 0; i <= D1; i++)\n      for (int j\
    \ = 0; j <= D2; j++) {\n        T v = b.f[i][j];\n        for (int k = i + 1;\
    \ k <= D1; k++)\n          b.f[k][j] += v * pow_x[k - i] * binom[k][i];\n    \
    \  }\n    for (int i = 0; i <= D1; i++)\n      for (int j = 0; j <= D2; j++) {\n\
    \        T v = b.f[i][j];\n        for (int k = j; k <= D2; k++)\n          a.f[i][k]\
    \ += v * pow_y[k - j] * binom[k][j];\n      }\n    return {a.x + b.x, a.y + b.y,\
    \ a.f};\n  }\n  static M elm_x() {\n    M t = e();\n    t.x = 1, t.f[0][0] = 1;\n\
    \    return t;\n  }\n  static M elm_y() {\n    M t = e();\n    t.y = 1;\n    return\
    \ t;\n  }\n};\n\n// enumerate sum{k=l}^{r-1}k^i*floor((a*k+b)/m))^j\ntemplate\
    \ <class T, int D1, int D2, std::signed_integral I = int64_t>\narray<array<T,\
    \ D2 + 1>, D1 + 1> PolynomialFloorSum(I l, I r, I m, I a, I b) {\n  assert(l <=\
    \ r && m != 0);\n  using U = conditional_t<is_same_v<I, __int128_t>, __uint128_t,\
    \ uint64_t>;\n  using M = PolynomialFloorSumMonoid<T, D1, D2>;\n  using P = array<array<T,\
    \ D2 + 1>, D1 + 1>;\n  if (m < 0) m = -m, a = -a, b = -b;\n  if (a < 0) {\n  \
    \  P c = PolynomialFloorSum<T, D1, D2, I>(-r + 1, -l + 1, m, -a, b);\n    for\
    \ (int i = 1; i <= D1; i += 2)\n      for (int j = 0; j <= D2; j++)\n        c[i][j]\
    \ = -c[i][j];\n    return c;\n  }\n  b += a * l;\n  I q = Math::floor(b, m);\n\
    \  b -= q * m;\n  M t = M::e();\n  t.x = l, t.y = q;\n  M z = FloorMonoidProduct<M,\
    \ M::op, M::e, U>(r - l, m, a, b, M::elm_x(), M::elm_y());\n  return M::op(t,\
    \ z).f;\n}\n\n// P(x,y): 2 variables polynomial, deg_x(P)<=D1, deg_y(Q)<=D2\n\
    // find sum{k=0}^{n-1}P(k,floor((a*k+b)/m))\ntemplate <class T, int D1, int D2,\
    \ std::signed_integral I = int64_t>\nT PolynomialFloorSum(array<array<T, D2 +\
    \ 1>, D1 + 1> poly, I l, I r, I m, I a, I b) {\n  using M = PolynomialFloorSumMonoid<T,\
    \ D1, D2>;\n  auto c = PolynomialFloorSum<T, D1, D2, I>(l, r, m, a, b);\n  T res\
    \ = 0;\n  for (int i = 0; i <= D1; i++)\n    for (int j = 0; j <= D2; j++)\n \
    \     res += poly[i][j] * c[i][j];\n  return res;\n}\n\n/**\n * @brief \u591A\u9805\
    \u5F0F\u7248 floor sum\n * @docs docs/math/polynomial-floor-sum.md\n */\n"
  code: "#pragma once\n#include \"math/util.hpp\"\n#include \"math/floor-monoid-product.hpp\"\
    \n\ntemplate <class T, int D1, int D2>\nstruct PolynomialFloorSumMonoid {\n  static\
    \ constexpr int D = max(D1, D2);\n  using M = PolynomialFloorSumMonoid;\n  using\
    \ P = array<array<T, D2 + 1>, D1 + 1>;\n  T x, y;\n  P f;\n  static M e() { return\
    \ {0, 0, P{}}; }\n  static M op(M a, M b) {\n    static T binom[D + 1][D + 1];\n\
    \    if (binom[0][0] != T(1)) {\n      binom[0][0] = T(1);\n      for (int i =\
    \ 0; i < D; i++)\n        for (int j = 0; j <= i; j++) {\n          binom[i +\
    \ 1][j] += binom[i][j];\n          binom[i + 1][j + 1] += binom[i][j];\n     \
    \   }\n    }\n    T pow_x[D1 + 1], pow_y[D2 + 1];\n    pow_x[0] = 1, pow_y[0]\
    \ = 1;\n    for (int i = 0; i < D1; i++) pow_x[i + 1] = pow_x[i] * a.x;\n    for\
    \ (int i = 0; i < D2; i++) pow_y[i + 1] = pow_y[i] * a.y;\n    for (int i = 0;\
    \ i <= D1; i++)\n      for (int j = 0; j <= D2; j++) {\n        T v = b.f[i][j];\n\
    \        for (int k = i + 1; k <= D1; k++)\n          b.f[k][j] += v * pow_x[k\
    \ - i] * binom[k][i];\n      }\n    for (int i = 0; i <= D1; i++)\n      for (int\
    \ j = 0; j <= D2; j++) {\n        T v = b.f[i][j];\n        for (int k = j; k\
    \ <= D2; k++)\n          a.f[i][k] += v * pow_y[k - j] * binom[k][j];\n      }\n\
    \    return {a.x + b.x, a.y + b.y, a.f};\n  }\n  static M elm_x() {\n    M t =\
    \ e();\n    t.x = 1, t.f[0][0] = 1;\n    return t;\n  }\n  static M elm_y() {\n\
    \    M t = e();\n    t.y = 1;\n    return t;\n  }\n};\n\n// enumerate sum{k=l}^{r-1}k^i*floor((a*k+b)/m))^j\n\
    template <class T, int D1, int D2, std::signed_integral I = int64_t>\narray<array<T,\
    \ D2 + 1>, D1 + 1> PolynomialFloorSum(I l, I r, I m, I a, I b) {\n  assert(l <=\
    \ r && m != 0);\n  using U = conditional_t<is_same_v<I, __int128_t>, __uint128_t,\
    \ uint64_t>;\n  using M = PolynomialFloorSumMonoid<T, D1, D2>;\n  using P = array<array<T,\
    \ D2 + 1>, D1 + 1>;\n  if (m < 0) m = -m, a = -a, b = -b;\n  if (a < 0) {\n  \
    \  P c = PolynomialFloorSum<T, D1, D2, I>(-r + 1, -l + 1, m, -a, b);\n    for\
    \ (int i = 1; i <= D1; i += 2)\n      for (int j = 0; j <= D2; j++)\n        c[i][j]\
    \ = -c[i][j];\n    return c;\n  }\n  b += a * l;\n  I q = Math::floor(b, m);\n\
    \  b -= q * m;\n  M t = M::e();\n  t.x = l, t.y = q;\n  M z = FloorMonoidProduct<M,\
    \ M::op, M::e, U>(r - l, m, a, b, M::elm_x(), M::elm_y());\n  return M::op(t,\
    \ z).f;\n}\n\n// P(x,y): 2 variables polynomial, deg_x(P)<=D1, deg_y(Q)<=D2\n\
    // find sum{k=0}^{n-1}P(k,floor((a*k+b)/m))\ntemplate <class T, int D1, int D2,\
    \ std::signed_integral I = int64_t>\nT PolynomialFloorSum(array<array<T, D2 +\
    \ 1>, D1 + 1> poly, I l, I r, I m, I a, I b) {\n  using M = PolynomialFloorSumMonoid<T,\
    \ D1, D2>;\n  auto c = PolynomialFloorSum<T, D1, D2, I>(l, r, m, a, b);\n  T res\
    \ = 0;\n  for (int i = 0; i <= D1; i++)\n    for (int j = 0; j <= D2; j++)\n \
    \     res += poly[i][j] * c[i][j];\n  return res;\n}\n\n/**\n * @brief \u591A\u9805\
    \u5F0F\u7248 floor sum\n * @docs docs/math/polynomial-floor-sum.md\n */"
  dependsOn:
  - math/util.hpp
  - math/floor-monoid-product.hpp
  isVerificationFile: false
  path: math/polynomial-floor-sum.hpp
  requiredBy: []
  timestamp: '2025-10-17 21:43:09+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/polynomial-floor-sum.hpp
layout: document
redirect_from:
- /library/math/polynomial-floor-sum.hpp
- /library/math/polynomial-floor-sum.hpp.html
title: "\u591A\u9805\u5F0F\u7248 floor sum"
---
## 使い方

以下の問題を $O(pq(p+q)\log m)$ 時間で解く．

> 整数 $l,r,m,a,b\ (m\neq 0)$ および非負整数 $p,q$ に対し以下の値を求めよ：
> $$f_{p,q}(l,r,m,a,b)=\sum_{i=l}^{r-1}i^p\left\lfloor\frac{ai+b}{m}\right\rfloor^q$$

型 `U` は $an+b$ が正しく計算できる必要がある．
