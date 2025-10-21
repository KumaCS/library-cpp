---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: math/util.hpp
    title: math/util.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/math/garner.md
    document_title: "Garner \u306E\u30A2\u30EB\u30B4\u30EA\u30BA\u30E0"
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
    #line 3 \"math/garner.hpp\"\n\ntemplate <class T>\nT Garner(const vector<T>& r,\
    \ const vector<T>& m) {\n  int n = r.size();\n  if (n == 0) return 0;\n  T p =\
    \ 1, x = 0;\n  for (int i = 0; i < n; i++) {\n    T t = (r[i] - x % m[i] + m[i])\
    \ * Math::inv_mod(p, m[i]) % m[i];\n    x += t * p;\n    p *= m[i];\n  }\n  return\
    \ x;\n}\ntemplate <class T>\nT Garner(const vector<T>& r, const vector<T>& m,\
    \ T mod) {\n  int n = r.size();\n  if (n == 0) return 0;\n  vector<T> y(n);\n\
    \  for (int i = 0; i < n; i++) {\n    T x = 0, p = 1;\n    for (int j = 0; j <\
    \ i; j++) {\n      x = (x + y[j] * p) % m[i];\n      p = p * m[j] % m[i];\n  \
    \  }\n    y[i] = (r[i] - x + m[i]) * Math::inv_mod(p, m[i]) % m[i];\n  }\n  T\
    \ res = 0;\n  for (int i = n - 1; i >= 0; i--) res = (res * m[i] + y[i]) % mod;\n\
    \  return res;\n}\n\n/**\n * @brief Garner \u306E\u30A2\u30EB\u30B4\u30EA\u30BA\
    \u30E0\n * @docs docs/math/garner.md\n */\n"
  code: "#pragma once\n#include \"math/util.hpp\"\n\ntemplate <class T>\nT Garner(const\
    \ vector<T>& r, const vector<T>& m) {\n  int n = r.size();\n  if (n == 0) return\
    \ 0;\n  T p = 1, x = 0;\n  for (int i = 0; i < n; i++) {\n    T t = (r[i] - x\
    \ % m[i] + m[i]) * Math::inv_mod(p, m[i]) % m[i];\n    x += t * p;\n    p *= m[i];\n\
    \  }\n  return x;\n}\ntemplate <class T>\nT Garner(const vector<T>& r, const vector<T>&\
    \ m, T mod) {\n  int n = r.size();\n  if (n == 0) return 0;\n  vector<T> y(n);\n\
    \  for (int i = 0; i < n; i++) {\n    T x = 0, p = 1;\n    for (int j = 0; j <\
    \ i; j++) {\n      x = (x + y[j] * p) % m[i];\n      p = p * m[j] % m[i];\n  \
    \  }\n    y[i] = (r[i] - x + m[i]) * Math::inv_mod(p, m[i]) % m[i];\n  }\n  T\
    \ res = 0;\n  for (int i = n - 1; i >= 0; i--) res = (res * m[i] + y[i]) % mod;\n\
    \  return res;\n}\n\n/**\n * @brief Garner \u306E\u30A2\u30EB\u30B4\u30EA\u30BA\
    \u30E0\n * @docs docs/math/garner.md\n */"
  dependsOn:
  - math/util.hpp
  isVerificationFile: false
  path: math/garner.hpp
  requiredBy: []
  timestamp: '2025-10-17 21:43:09+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/garner.hpp
layout: document
redirect_from:
- /library/math/garner.hpp
- /library/math/garner.hpp.html
title: "Garner \u306E\u30A2\u30EB\u30B4\u30EA\u30BA\u30E0"
---
$x\bmod m_1=r_1,x\bmod m_2=r_2,\dots,x\bmod m_n=r_n$ を満たす最小の非負整数 $x$ を求める．ただし $m_1,m_2,\dots,m_n$ のどの 2 つも互いに素．

## 解の mod をとらないとき

まず $n=2$ のときを考える．

$x=r_1+m_1y$ とおくと $y\equiv(r_2-r_1)m_1^{-1}\pmod{m_2}$ である．

従って $x=r_1+m_1((r_2-r_1)m_1^{-1}\bmod{m_2})$ として $x$ が求められる．

複数 mod のときも繰り返し用いればよい．

## 解の mod をとるとき

まず$n=2$ のときを考える．

$m_0$ を任意の mod とする（$m_1$ および $m_2$ と互いに素でなくとも構わない）．

$(x\bmod m_1)\bmod m_i$ の値がわかっているときに $(x\bmod m_1m_2)\bmod m_i$ の値を求める．

そのためには $(r_2-r_1)m_1^{-1}\bmod{m_2}$ の値がわかればよく，これは $(x\bmod m_1)\bmod m_2,m_1\bmod m_2$ の値から求められる．

その値（$y$ とする）が求まれば，計算済みの値にそれぞれ $m_1y$ を適宜 mod をとって加えればよい．

一般の $n$ に対しては，以下のように定める．

$$\begin{align*}
x_i&=\left(\sum_{j=1}^{i-1}y_j\left(\prod_{l=1}^{j-1}m_l\right)\right)\bmod{m_i}\quad (1\leq i\leq n)\\
y_i&=(r_i-x_i)\left(\prod_{l=1}^{i-1}m_l\right)^{-1}\bmod{m_i}\quad(1\leq i\leq n).
\end{align*}$$

このとき実際の値は $y_1+m_1y_2+\cdots+m_1\cdots m_{i-1}y_i$ であるから，これを適宜 mod を取り計算すればよい．

$x$ の値が非常に大きいような場合であっても，四則演算が各 mod の範囲でさえ行えれば計算できる．

## オンライン化

解の mod をとらないとき，単に直近の mod と解を持てばよい．

解の mod をとるとき，$m_i,y_i$ の値を管理しておけばよい．