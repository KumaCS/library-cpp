---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/barrett.hpp
    title: math/barrett.hpp
  - icon: ':heavy_check_mark:'
    path: math/util.hpp
    title: math/util.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/modint/LC_binomial_coefficient_prime_mod.test.cpp
    title: verify/modint/LC_binomial_coefficient_prime_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/modint/UNIT_dynamic_modint.test.cpp
    title: verify/modint/UNIT_dynamic_modint.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
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
    \ 1;\n    x -= b0 * q;\n    y += a0 * q;\n  }\n  return a;\n}\nlong long inv_mod(long\
    \ long x, long long m) {\n  x %= m;\n  if (x < 0) x += m;\n  long long a = m,\
    \ b = x;\n  long long y0 = 0, y1 = 1;\n  while (b > 0) {\n    long long q = a\
    \ / b;\n    swap(a -= q * b, b);\n    swap(y0 -= q * y1, y1);\n  }\n  if (y0 <\
    \ 0) y0 += m / a;\n  return y0;\n}\nlong long pow_mod(long long x, long long n,\
    \ long long m) {\n  x = (x % m + m) % m;\n  long long y = 1;\n  while (n) {\n\
    \    if (n & 1) y = y * x % m;\n    x = x * x % m;\n    n >>= 1;\n  }\n  return\
    \ y;\n}\nconstexpr long long pow_mod_constexpr(long long x, long long n, int m)\
    \ {\n  if (m == 1) return 0;\n  unsigned int _m = (unsigned int)(m);\n  unsigned\
    \ long long r = 1;\n  unsigned long long y = x % m;\n  if (y >= m) y += m;\n \
    \ while (n) {\n    if (n & 1) r = (r * y) % _m;\n    y = (y * y) % _m;\n    n\
    \ >>= 1;\n  }\n  return r;\n}\nconstexpr bool is_prime_constexpr(int n) {\n  if\
    \ (n <= 1) return false;\n  if (n == 2 || n == 7 || n == 61) return true;\n  if\
    \ (n % 2 == 0) return false;\n  long long d = n - 1;\n  while (d % 2 == 0) d /=\
    \ 2;\n  constexpr long long bases[3] = {2, 7, 61};\n  for (long long a : bases)\
    \ {\n    long long t = d;\n    long long y = pow_mod_constexpr(a, t, n);\n   \
    \ while (t != n - 1 && y != 1 && y != n - 1) {\n      y = y * y % n;\n      t\
    \ <<= 1;\n    }\n    if (y != n - 1 && t % 2 == 0) {\n      return false;\n  \
    \  }\n  }\n  return true;\n}\ntemplate <int n>\nconstexpr bool is_prime = is_prime_constexpr(n);\n\
    };  // namespace Math\n#line 2 \"math/barrett.hpp\"\n\nstruct barrett {\n  unsigned\
    \ int _m;\n  unsigned long long im;\n  explicit barrett(unsigned int m) : _m(m),\
    \ im((unsigned long long)(-1) / m + 1) {}\n  unsigned int umod() const { return\
    \ _m; }\n  unsigned int mul(unsigned int a, unsigned int b) const {\n    unsigned\
    \ long long z = a;\n    z *= b;\n#ifdef _MSC_VER\n    unsigned long long x;\n\
    \    _umul128(z, im, &x);\n#else\n    unsigned long long x = (unsigned long long)(((unsigned\
    \ __int128)(z)*im) >> 64);\n#endif\n    unsigned long long y = x * _m;\n    return\
    \ (unsigned int)(z - y + (z < y ? _m : 0));\n  }\n};\n#line 4 \"modint/dynamic-modint.hpp\"\
    \n\ntemplate <int id>\nstruct DynamicModInt {\n  using mint = DynamicModInt;\n\
    \  static void set_mod(int m) {\n    assert(1 <= m);\n    bar = barrett(m);\n\
    \  }\n  static constexpr unsigned int get_mod() { return (int)bar.umod(); }\n\
    \  static mint raw(int v) {\n    mint x;\n    x._v = v;\n    return x;\n  }\n\
    \  DynamicModInt() : _v(0) {}\n  DynamicModInt(int64_t v) {\n    long long x =\
    \ (long long)(v % (long long)(bar.umod()));\n    if (x < 0) x += umod();\n   \
    \ _v = (unsigned int)(x);\n  }\n  unsigned int val() const { return _v; }\n  mint&\
    \ operator++() {\n    _v++;\n    if (_v == umod()) _v = 0;\n    return *this;\n\
    \  }\n  mint& operator--() {\n    if (_v == 0) _v = umod();\n    _v--;\n    return\
    \ *this;\n  }\n  mint operator++(int) {\n    mint result = *this;\n    ++*this;\n\
    \    return result;\n  }\n  mint operator--(int) {\n    mint result = *this;\n\
    \    --*this;\n    return result;\n  }\n  mint& operator+=(const mint& rhs) {\n\
    \    _v += rhs._v;\n    if (_v >= umod()) _v -= umod();\n    return *this;\n \
    \ }\n  mint& operator-=(const mint& rhs) {\n    _v -= rhs._v;\n    if (_v >= umod())\
    \ _v += umod();\n    return *this;\n  }\n  mint& operator*=(const mint& rhs) {\n\
    \    _v = bar.mul(_v, rhs._v);\n    return *this;\n  }\n  mint& operator/=(const\
    \ mint& rhs) { return *this = *this * rhs.inv(); }\n  mint operator+() const {\
    \ return *this; }\n  mint operator-() const { return mint() - *this; }\n  mint\
    \ pow(long long n) const {\n    assert(0 <= n);\n    mint x = *this, r = 1;\n\
    \    while (n) {\n      if (n & 1) r *= x;\n      x *= x;\n      n >>= 1;\n  \
    \  }\n    return r;\n  }\n  mint inv() const {\n    auto inv = Math::inv_mod(_v,\
    \ umod());\n    return raw(inv);\n  }\n  friend mint operator+(const mint& lhs,\
    \ const mint& rhs) { return mint(lhs) += rhs; }\n  friend mint operator-(const\
    \ mint& lhs, const mint& rhs) { return mint(lhs) -= rhs; }\n  friend mint operator*(const\
    \ mint& lhs, const mint& rhs) { return mint(lhs) *= rhs; }\n  friend mint operator/(const\
    \ mint& lhs, const mint& rhs) { return mint(lhs) /= rhs; }\n  friend bool operator==(const\
    \ mint& lhs, const mint& rhs) { return lhs._v == rhs._v; }\n  friend bool operator!=(const\
    \ mint& lhs, const mint& rhs) { return lhs._v != rhs._v; }\n  friend istream&\
    \ operator>>(istream& is, mint& x) { return is >> x._v; }\n  friend ostream& operator<<(ostream&\
    \ os, const mint& x) { return os << x.val(); }\n\n private:\n  unsigned int _v;\n\
    \  static constexpr unsigned int umod() { return bar.umod(); }\n  static barrett\
    \ bar;\n};\ntemplate <int id>\nbarrett DynamicModInt<id>::bar(998244353);\n"
  code: "#pragma once\n#include \"math/util.hpp\"\n#include \"math/barrett.hpp\"\n\
    \ntemplate <int id>\nstruct DynamicModInt {\n  using mint = DynamicModInt;\n \
    \ static void set_mod(int m) {\n    assert(1 <= m);\n    bar = barrett(m);\n \
    \ }\n  static constexpr unsigned int get_mod() { return (int)bar.umod(); }\n \
    \ static mint raw(int v) {\n    mint x;\n    x._v = v;\n    return x;\n  }\n \
    \ DynamicModInt() : _v(0) {}\n  DynamicModInt(int64_t v) {\n    long long x =\
    \ (long long)(v % (long long)(bar.umod()));\n    if (x < 0) x += umod();\n   \
    \ _v = (unsigned int)(x);\n  }\n  unsigned int val() const { return _v; }\n  mint&\
    \ operator++() {\n    _v++;\n    if (_v == umod()) _v = 0;\n    return *this;\n\
    \  }\n  mint& operator--() {\n    if (_v == 0) _v = umod();\n    _v--;\n    return\
    \ *this;\n  }\n  mint operator++(int) {\n    mint result = *this;\n    ++*this;\n\
    \    return result;\n  }\n  mint operator--(int) {\n    mint result = *this;\n\
    \    --*this;\n    return result;\n  }\n  mint& operator+=(const mint& rhs) {\n\
    \    _v += rhs._v;\n    if (_v >= umod()) _v -= umod();\n    return *this;\n \
    \ }\n  mint& operator-=(const mint& rhs) {\n    _v -= rhs._v;\n    if (_v >= umod())\
    \ _v += umod();\n    return *this;\n  }\n  mint& operator*=(const mint& rhs) {\n\
    \    _v = bar.mul(_v, rhs._v);\n    return *this;\n  }\n  mint& operator/=(const\
    \ mint& rhs) { return *this = *this * rhs.inv(); }\n  mint operator+() const {\
    \ return *this; }\n  mint operator-() const { return mint() - *this; }\n  mint\
    \ pow(long long n) const {\n    assert(0 <= n);\n    mint x = *this, r = 1;\n\
    \    while (n) {\n      if (n & 1) r *= x;\n      x *= x;\n      n >>= 1;\n  \
    \  }\n    return r;\n  }\n  mint inv() const {\n    auto inv = Math::inv_mod(_v,\
    \ umod());\n    return raw(inv);\n  }\n  friend mint operator+(const mint& lhs,\
    \ const mint& rhs) { return mint(lhs) += rhs; }\n  friend mint operator-(const\
    \ mint& lhs, const mint& rhs) { return mint(lhs) -= rhs; }\n  friend mint operator*(const\
    \ mint& lhs, const mint& rhs) { return mint(lhs) *= rhs; }\n  friend mint operator/(const\
    \ mint& lhs, const mint& rhs) { return mint(lhs) /= rhs; }\n  friend bool operator==(const\
    \ mint& lhs, const mint& rhs) { return lhs._v == rhs._v; }\n  friend bool operator!=(const\
    \ mint& lhs, const mint& rhs) { return lhs._v != rhs._v; }\n  friend istream&\
    \ operator>>(istream& is, mint& x) { return is >> x._v; }\n  friend ostream& operator<<(ostream&\
    \ os, const mint& x) { return os << x.val(); }\n\n private:\n  unsigned int _v;\n\
    \  static constexpr unsigned int umod() { return bar.umod(); }\n  static barrett\
    \ bar;\n};\ntemplate <int id>\nbarrett DynamicModInt<id>::bar(998244353);"
  dependsOn:
  - math/util.hpp
  - math/barrett.hpp
  isVerificationFile: false
  path: modint/dynamic-modint.hpp
  requiredBy: []
  timestamp: '2025-11-01 12:35:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/modint/LC_binomial_coefficient_prime_mod.test.cpp
  - verify/modint/UNIT_dynamic_modint.test.cpp
documentation_of: modint/dynamic-modint.hpp
layout: document
redirect_from:
- /library/modint/dynamic-modint.hpp
- /library/modint/dynamic-modint.hpp.html
title: modint/dynamic-modint.hpp
---
