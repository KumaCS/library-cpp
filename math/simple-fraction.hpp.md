---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u6709\u7406\u6570 (\u7D04\u5206\u306A\u3057)"
    links: []
  bundledCode: "#line 2 \"math/simple-fraction.hpp\"\n\ntemplate <class T>\nstruct\
    \ SimpleFraction {\n  T a, b;\n  SimpleFraction() : a(0), b(1) {}\n  SimpleFraction(T\
    \ _a) : a(_a), b(1) {}\n  SimpleFraction(T _a, T _b) { init(_a, _b); }\n  template\
    \ <class V>\n  V get() const { return V(a) / b; }\n  using frac = SimpleFraction;\n\
    \  frac &init(T _a, T _b) {\n    a = _a, b = _b;\n    if (b < 0) a = -a, b = -b;\n\
    \    if (a == 0) b = 1;\n    return *this;\n  }\n  frac operator-() const { return\
    \ frac(-a, b); }\n  frac &operator+=(const frac &x) { return init(a * x.b + x.a\
    \ * b, b * x.b); }\n  frac &operator-=(const frac &x) { return init(a * x.b -\
    \ x.a * b, b * x.b); }\n  frac &operator*=(const frac &x) { return init(a * x.a,\
    \ b * x.b); }\n  frac &operator/=(const frac &x) { return init(a * x.b, b * x.a);\
    \ }\n  frac operator+(const frac &x) const { return frac(*this) += x; }\n  frac\
    \ operator-(const frac &x) const { return frac(*this) -= x; }\n  frac operator*(const\
    \ frac &x) const { return frac(*this) *= x; }\n  frac operator/(const frac &x)\
    \ const { return frac(*this) /= x; }\n  bool operator<(const frac &x) const {\
    \ return a * x.b < b * x.a; }\n  bool operator>(const frac &x) const { return\
    \ a * x.b > b * x.a; }\n  bool operator<=(const frac &x) const { return a * x.b\
    \ <= b * x.a; }\n  bool operator>=(const frac &x) const { return a * x.b >= b\
    \ * x.a; }\n  bool operator==(const frac &x) const { return a * x.b == b * x.a;\
    \ }\n  bool operator!=(const frac &x) const { return a * x.b != b * x.a; }\n \
    \ friend istream &operator>>(istream &is, frac &x) { return is >> x.a >> x.b;\
    \ }\n  friend ostream &operator<<(ostream &os, const frac &x) { return os << x.a\
    \ << '/' << x.b; }\n};\n\n/**\n * @brief \u6709\u7406\u6570 (\u7D04\u5206\u306A\
    \u3057)\n */\n"
  code: "#pragma once\n\ntemplate <class T>\nstruct SimpleFraction {\n  T a, b;\n\
    \  SimpleFraction() : a(0), b(1) {}\n  SimpleFraction(T _a) : a(_a), b(1) {}\n\
    \  SimpleFraction(T _a, T _b) { init(_a, _b); }\n  template <class V>\n  V get()\
    \ const { return V(a) / b; }\n  using frac = SimpleFraction;\n  frac &init(T _a,\
    \ T _b) {\n    a = _a, b = _b;\n    if (b < 0) a = -a, b = -b;\n    if (a == 0)\
    \ b = 1;\n    return *this;\n  }\n  frac operator-() const { return frac(-a, b);\
    \ }\n  frac &operator+=(const frac &x) { return init(a * x.b + x.a * b, b * x.b);\
    \ }\n  frac &operator-=(const frac &x) { return init(a * x.b - x.a * b, b * x.b);\
    \ }\n  frac &operator*=(const frac &x) { return init(a * x.a, b * x.b); }\n  frac\
    \ &operator/=(const frac &x) { return init(a * x.b, b * x.a); }\n  frac operator+(const\
    \ frac &x) const { return frac(*this) += x; }\n  frac operator-(const frac &x)\
    \ const { return frac(*this) -= x; }\n  frac operator*(const frac &x) const {\
    \ return frac(*this) *= x; }\n  frac operator/(const frac &x) const { return frac(*this)\
    \ /= x; }\n  bool operator<(const frac &x) const { return a * x.b < b * x.a; }\n\
    \  bool operator>(const frac &x) const { return a * x.b > b * x.a; }\n  bool operator<=(const\
    \ frac &x) const { return a * x.b <= b * x.a; }\n  bool operator>=(const frac\
    \ &x) const { return a * x.b >= b * x.a; }\n  bool operator==(const frac &x) const\
    \ { return a * x.b == b * x.a; }\n  bool operator!=(const frac &x) const { return\
    \ a * x.b != b * x.a; }\n  friend istream &operator>>(istream &is, frac &x) {\
    \ return is >> x.a >> x.b; }\n  friend ostream &operator<<(ostream &os, const\
    \ frac &x) { return os << x.a << '/' << x.b; }\n};\n\n/**\n * @brief \u6709\u7406\
    \u6570 (\u7D04\u5206\u306A\u3057)\n */"
  dependsOn: []
  isVerificationFile: false
  path: math/simple-fraction.hpp
  requiredBy: []
  timestamp: '2025-10-17 21:43:09+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/simple-fraction.hpp
layout: document
redirect_from:
- /library/math/simple-fraction.hpp
- /library/math/simple-fraction.hpp.html
title: "\u6709\u7406\u6570 (\u7D04\u5206\u306A\u3057)"
---
