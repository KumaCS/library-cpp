---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"modint/modint261.hpp\"\n\n// mod (2^61-1)\nstruct ModInt261\
    \ {\n  using mint = ModInt261;\n  using ll = long long;\n  using ull = unsigned\
    \ long long;\n  static const int b = 61;\n  static const ull m = (1ull << b) -\
    \ 1;\n\n public:\n  static constexpr ull get_mod() { return m; }\n  static mint\
    \ raw(int v) {\n    mint x;\n    x._v = v;\n    return x;\n  }\n\n  ModInt261()\
    \ : _v(0) {}\n  ModInt261(int v) : _v(v < 0 ? m + v : v) {}\n  ModInt261(ll v)\
    \ : _v(calc_mod(ull(v < 0 ? m + v : v))) {}\n  ModInt261(ull v) : _v(calc_mod(v))\
    \ {}\n  ull val() const { return _v; }\n  mint &operator++() {\n    _v++;\n  \
    \  if (_v == m) _v = 0;\n    return *this;\n  }\n  mint &operator--() {\n    if\
    \ (_v == 0) _v = m;\n    _v--;\n    return *this;\n  }\n  mint operator++(int)\
    \ {\n    mint result = *this;\n    ++*this;\n    return result;\n  }\n  mint operator--(int)\
    \ {\n    mint result = *this;\n    --*this;\n    return result;\n  }\n\n  mint\
    \ &operator+=(const mint &rhs) {\n    _v += rhs._v;\n    if (_v >= m) _v -= m;\n\
    \    return *this;\n  }\n  mint &operator-=(const mint &rhs) {\n    _v -= rhs._v;\n\
    \    if (_v >= m) _v += m;\n    return *this;\n  }\n  mint &operator*=(const mint\
    \ &rhs) {\n    __uint128_t z = _v;\n    z *= rhs._v;\n    _v = ull(z % m);\n \
    \   return *this;\n  }\n  mint &operator/=(const mint &rhs) { return *this = *this\
    \ * rhs.inv(); }\n\n  mint operator+() const { return *this; }\n  mint operator-()\
    \ const { return mint() - *this; }\n\n  mint pow(long long n) const {\n    assert(0\
    \ <= n);\n    mint x = *this, r = 1;\n    while (n) {\n      if (n & 1) r *= x;\n\
    \      x *= x;\n      n >>= 1;\n    }\n    return r;\n  }\n  mint inv() const\
    \ {\n    assert(_v);\n    return pow(m - 2);\n  }\n\n  friend mint operator+(const\
    \ mint &lhs, const mint &rhs) {\n    return mint(lhs) += rhs;\n  }\n  friend mint\
    \ operator-(const mint &lhs, const mint &rhs) {\n    return mint(lhs) -= rhs;\n\
    \  }\n  friend mint operator*(const mint &lhs, const mint &rhs) {\n    return\
    \ mint(lhs) *= rhs;\n  }\n  friend mint operator/(const mint &lhs, const mint\
    \ &rhs) {\n    return mint(lhs) /= rhs;\n  }\n  friend bool operator==(const mint\
    \ &lhs, const mint &rhs) {\n    return lhs._v == rhs._v;\n  }\n  friend bool operator!=(const\
    \ mint &lhs, const mint &rhs) {\n    return lhs._v != rhs._v;\n  }\n  friend istream\
    \ &operator>>(istream &is, mint &x) {\n    return is >> x._v;\n  }\n  friend ostream\
    \ &operator<<(ostream &os, const mint &x) {\n    return os << x.val();\n  }\n\n\
    \ private:\n  ull _v;\n  ull calc_mod(ull v) {\n    ull x = (v & m) + (v >> b);\n\
    \    if (x >= m) x -= m;\n    return x;\n  }\n};\n"
  code: "#pragma once\n\n// mod (2^61-1)\nstruct ModInt261 {\n  using mint = ModInt261;\n\
    \  using ll = long long;\n  using ull = unsigned long long;\n  static const int\
    \ b = 61;\n  static const ull m = (1ull << b) - 1;\n\n public:\n  static constexpr\
    \ ull get_mod() { return m; }\n  static mint raw(int v) {\n    mint x;\n    x._v\
    \ = v;\n    return x;\n  }\n\n  ModInt261() : _v(0) {}\n  ModInt261(int v) : _v(v\
    \ < 0 ? m + v : v) {}\n  ModInt261(ll v) : _v(calc_mod(ull(v < 0 ? m + v : v)))\
    \ {}\n  ModInt261(ull v) : _v(calc_mod(v)) {}\n  ull val() const { return _v;\
    \ }\n  mint &operator++() {\n    _v++;\n    if (_v == m) _v = 0;\n    return *this;\n\
    \  }\n  mint &operator--() {\n    if (_v == 0) _v = m;\n    _v--;\n    return\
    \ *this;\n  }\n  mint operator++(int) {\n    mint result = *this;\n    ++*this;\n\
    \    return result;\n  }\n  mint operator--(int) {\n    mint result = *this;\n\
    \    --*this;\n    return result;\n  }\n\n  mint &operator+=(const mint &rhs)\
    \ {\n    _v += rhs._v;\n    if (_v >= m) _v -= m;\n    return *this;\n  }\n  mint\
    \ &operator-=(const mint &rhs) {\n    _v -= rhs._v;\n    if (_v >= m) _v += m;\n\
    \    return *this;\n  }\n  mint &operator*=(const mint &rhs) {\n    __uint128_t\
    \ z = _v;\n    z *= rhs._v;\n    _v = ull(z % m);\n    return *this;\n  }\n  mint\
    \ &operator/=(const mint &rhs) { return *this = *this * rhs.inv(); }\n\n  mint\
    \ operator+() const { return *this; }\n  mint operator-() const { return mint()\
    \ - *this; }\n\n  mint pow(long long n) const {\n    assert(0 <= n);\n    mint\
    \ x = *this, r = 1;\n    while (n) {\n      if (n & 1) r *= x;\n      x *= x;\n\
    \      n >>= 1;\n    }\n    return r;\n  }\n  mint inv() const {\n    assert(_v);\n\
    \    return pow(m - 2);\n  }\n\n  friend mint operator+(const mint &lhs, const\
    \ mint &rhs) {\n    return mint(lhs) += rhs;\n  }\n  friend mint operator-(const\
    \ mint &lhs, const mint &rhs) {\n    return mint(lhs) -= rhs;\n  }\n  friend mint\
    \ operator*(const mint &lhs, const mint &rhs) {\n    return mint(lhs) *= rhs;\n\
    \  }\n  friend mint operator/(const mint &lhs, const mint &rhs) {\n    return\
    \ mint(lhs) /= rhs;\n  }\n  friend bool operator==(const mint &lhs, const mint\
    \ &rhs) {\n    return lhs._v == rhs._v;\n  }\n  friend bool operator!=(const mint\
    \ &lhs, const mint &rhs) {\n    return lhs._v != rhs._v;\n  }\n  friend istream\
    \ &operator>>(istream &is, mint &x) {\n    return is >> x._v;\n  }\n  friend ostream\
    \ &operator<<(ostream &os, const mint &x) {\n    return os << x.val();\n  }\n\n\
    \ private:\n  ull _v;\n  ull calc_mod(ull v) {\n    ull x = (v & m) + (v >> b);\n\
    \    if (x >= m) x -= m;\n    return x;\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: modint/modint261.hpp
  requiredBy: []
  timestamp: '2025-10-17 21:43:09+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: modint/modint261.hpp
layout: document
redirect_from:
- /library/modint/modint261.hpp
- /library/modint/modint261.hpp.html
title: modint/modint261.hpp
---
