---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: set/xor-convolution.hpp
    title: set/xor-convolution.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/set/LC_bitwise_xor_convolution.test.cpp
    title: verify/set/LC_bitwise_xor_convolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"set/hadamard-transform.hpp\"\n\ntemplate <class T>\nvoid\
    \ HadamardTransform(vector<T>& f, bool inv = false) {\n  int n = f.size();\n \
    \ assert((n & (n - 1)) == 0);\n  for (int i = 1; i < n; i <<= 1) {\n    for (int\
    \ j = 0; j < n; j++) {\n      if ((j & i) == 0) {\n        T x = f[j], y = f[j\
    \ | i];\n        f[j] = x + y, f[j | i] = x - y;\n      }\n    }\n  }\n  if (inv)\
    \ {\n    if constexpr (is_integral<T>::value) {\n      for (auto& x : f) x /=\
    \ n;\n    } else {\n      T invn = T(1) / T(f.size());\n      for (auto& x : f)\
    \ x *= invn;\n    }\n  }\n}\n"
  code: "#pragma once\n\ntemplate <class T>\nvoid HadamardTransform(vector<T>& f,\
    \ bool inv = false) {\n  int n = f.size();\n  assert((n & (n - 1)) == 0);\n  for\
    \ (int i = 1; i < n; i <<= 1) {\n    for (int j = 0; j < n; j++) {\n      if ((j\
    \ & i) == 0) {\n        T x = f[j], y = f[j | i];\n        f[j] = x + y, f[j |\
    \ i] = x - y;\n      }\n    }\n  }\n  if (inv) {\n    if constexpr (is_integral<T>::value)\
    \ {\n      for (auto& x : f) x /= n;\n    } else {\n      T invn = T(1) / T(f.size());\n\
    \      for (auto& x : f) x *= invn;\n    }\n  }\n}"
  dependsOn: []
  isVerificationFile: false
  path: set/hadamard-transform.hpp
  requiredBy:
  - set/xor-convolution.hpp
  timestamp: '2025-10-10 17:35:46+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/set/LC_bitwise_xor_convolution.test.cpp
documentation_of: set/hadamard-transform.hpp
layout: document
redirect_from:
- /library/set/hadamard-transform.hpp
- /library/set/hadamard-transform.hpp.html
title: set/hadamard-transform.hpp
---
