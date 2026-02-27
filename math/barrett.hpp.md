---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: modint/dynamic-modint.hpp
    title: modint/dynamic-modint.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/fps/LC_montmort_number_mod.test.cpp
    title: verify/fps/LC_montmort_number_mod.test.cpp
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
  bundledCode: "#line 2 \"math/barrett.hpp\"\n\nstruct barrett {\n  unsigned int _m;\n\
    \  unsigned long long im;\n  explicit barrett(unsigned int m) : _m(m), im((unsigned\
    \ long long)(-1) / m + 1) {}\n  unsigned int umod() const { return _m; }\n  unsigned\
    \ int mul(unsigned int a, unsigned int b) const {\n    unsigned long long z =\
    \ a;\n    z *= b;\n#ifdef _MSC_VER\n    unsigned long long x;\n    _umul128(z,\
    \ im, &x);\n#else\n    unsigned long long x = (unsigned long long)(((unsigned\
    \ __int128)(z)*im) >> 64);\n#endif\n    unsigned long long y = x * _m;\n    return\
    \ (unsigned int)(z - y + (z < y ? _m : 0));\n  }\n};\n"
  code: "#pragma once\n\nstruct barrett {\n  unsigned int _m;\n  unsigned long long\
    \ im;\n  explicit barrett(unsigned int m) : _m(m), im((unsigned long long)(-1)\
    \ / m + 1) {}\n  unsigned int umod() const { return _m; }\n  unsigned int mul(unsigned\
    \ int a, unsigned int b) const {\n    unsigned long long z = a;\n    z *= b;\n\
    #ifdef _MSC_VER\n    unsigned long long x;\n    _umul128(z, im, &x);\n#else\n\
    \    unsigned long long x = (unsigned long long)(((unsigned __int128)(z)*im) >>\
    \ 64);\n#endif\n    unsigned long long y = x * _m;\n    return (unsigned int)(z\
    \ - y + (z < y ? _m : 0));\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: math/barrett.hpp
  requiredBy:
  - modint/dynamic-modint.hpp
  timestamp: '2025-11-01 00:19:27+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/fps/LC_montmort_number_mod.test.cpp
  - verify/modint/LC_binomial_coefficient_prime_mod.test.cpp
  - verify/modint/UNIT_dynamic_modint.test.cpp
documentation_of: math/barrett.hpp
layout: document
redirect_from:
- /library/math/barrett.hpp
- /library/math/barrett.hpp.html
title: math/barrett.hpp
---
