---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: fps/fps-sqrt.hpp
    title: fps/fps-sqrt.hpp
  - icon: ':x:'
    path: modint/mod-sqrt.hpp
    title: modint/mod-sqrt.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/fps/LC_sqrt_of_formal_power_series.test.cpp
    title: verify/fps/LC_sqrt_of_formal_power_series.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"modint/mod-pow.hpp\"\n\nunsigned int ModPow(unsigned int\
    \ a, unsigned long long n, unsigned int m) {\n  unsigned long long x = a, y =\
    \ 1;\n  while (n) {\n    if (n & 1) y = y * x % m;\n    x = x * x % m;\n    n\
    \ >>= 1;\n  }\n  return y;\n}\n"
  code: "#pragma once\n\nunsigned int ModPow(unsigned int a, unsigned long long n,\
    \ unsigned int m) {\n  unsigned long long x = a, y = 1;\n  while (n) {\n    if\
    \ (n & 1) y = y * x % m;\n    x = x * x % m;\n    n >>= 1;\n  }\n  return y;\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: modint/mod-pow.hpp
  requiredBy:
  - modint/mod-sqrt.hpp
  - fps/fps-sqrt.hpp
  timestamp: '2025-10-10 17:35:46+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/fps/LC_sqrt_of_formal_power_series.test.cpp
documentation_of: modint/mod-pow.hpp
layout: document
redirect_from:
- /library/modint/mod-pow.hpp
- /library/modint/mod-pow.hpp.html
title: modint/mod-pow.hpp
---
