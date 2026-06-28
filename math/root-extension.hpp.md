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
  bundledCode: "#line 2 \"math/root-extension.hpp\"\n\n// T[x]/(x^s-r)\ntemplate <class\
    \ T, int s, auto r>\nstruct RootExtension {\n  using F = RootExtension;\n  array<T,\
    \ s> a;\n  RootExtension() { a.fill(T{}); }\n  RootExtension(const T& x) {\n \
    \   a.fill(T{});\n    a[0] = x;\n  }\n  T& operator[](int k) { return a[k]; }\n\
    \  F& operator+=(const F& o) {\n    for (int i = 0; i < s; i++) a[i] += o.a[i];\n\
    \    return *this;\n  }\n  F& operator-=(const F& o) {\n    for (int i = 0; i\
    \ < s; i++) a[i] -= o.a[i];\n    return *this;\n  }\n  F& operator*=(const F&\
    \ o) {\n    const T _r = T{r};\n    array<T, s> b{};\n    for (int i = 0; i <\
    \ s; i++) {\n      for (int j = 0; j < s - i; j++) b[i + j] += a[i] * o.a[j];\n\
    \      for (int j = s - i; j < s; j++) b[i + j - s] += _r * a[i] * o.a[j];\n \
    \   }\n    swap(a, b);\n    return *this;\n  }\n  F operator+(const F& o) const\
    \ { return F(*this) += o; }\n  F operator-(const F& o) const { return F(*this)\
    \ -= o; }\n  F operator*(const F& o) const { return F(*this) *= o; }\n  F operator-()\
    \ const {\n    F ret(*this);\n    for (auto& v : ret.a) v = -v;\n    return ret;\n\
    \  }\n  F pow(long long n) const {\n    F ret = T{1}, x = *this;\n    while (n)\
    \ {\n      if (n & 1) ret *= x;\n      x *= x;\n      n >>= 1;\n    }\n    return\
    \ ret;\n  }\n  T test() const { return T{r}; }\n};\n"
  code: "#pragma once\n\n// T[x]/(x^s-r)\ntemplate <class T, int s, auto r>\nstruct\
    \ RootExtension {\n  using F = RootExtension;\n  array<T, s> a;\n  RootExtension()\
    \ { a.fill(T{}); }\n  RootExtension(const T& x) {\n    a.fill(T{});\n    a[0]\
    \ = x;\n  }\n  T& operator[](int k) { return a[k]; }\n  F& operator+=(const F&\
    \ o) {\n    for (int i = 0; i < s; i++) a[i] += o.a[i];\n    return *this;\n \
    \ }\n  F& operator-=(const F& o) {\n    for (int i = 0; i < s; i++) a[i] -= o.a[i];\n\
    \    return *this;\n  }\n  F& operator*=(const F& o) {\n    const T _r = T{r};\n\
    \    array<T, s> b{};\n    for (int i = 0; i < s; i++) {\n      for (int j = 0;\
    \ j < s - i; j++) b[i + j] += a[i] * o.a[j];\n      for (int j = s - i; j < s;\
    \ j++) b[i + j - s] += _r * a[i] * o.a[j];\n    }\n    swap(a, b);\n    return\
    \ *this;\n  }\n  F operator+(const F& o) const { return F(*this) += o; }\n  F\
    \ operator-(const F& o) const { return F(*this) -= o; }\n  F operator*(const F&\
    \ o) const { return F(*this) *= o; }\n  F operator-() const {\n    F ret(*this);\n\
    \    for (auto& v : ret.a) v = -v;\n    return ret;\n  }\n  F pow(long long n)\
    \ const {\n    F ret = T{1}, x = *this;\n    while (n) {\n      if (n & 1) ret\
    \ *= x;\n      x *= x;\n      n >>= 1;\n    }\n    return ret;\n  }\n  T test()\
    \ const { return T{r}; }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: math/root-extension.hpp
  requiredBy: []
  timestamp: '2026-06-28 15:22:40+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/root-extension.hpp
layout: document
redirect_from:
- /library/math/root-extension.hpp
- /library/math/root-extension.hpp.html
title: math/root-extension.hpp
---
