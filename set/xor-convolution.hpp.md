---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: set/hadamard-transform.hpp
    title: set/hadamard-transform.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/set/LC_bitwise_xor_convolution.test.cpp
    title: verify/set/LC_bitwise_xor_convolution.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"set/xor-convolution.hpp\"\n\n#line 2 \"set/hadamard-transform.hpp\"\
    \n\ntemplate <class T>\nvoid HadamardTransform(vector<T>& f, bool inv = false)\
    \ {\n  int n = f.size();\n  assert((n & (n - 1)) == 0);\n  for (int i = 1; i <\
    \ n; i <<= 1) {\n    for (int j = 0; j < n; j++) {\n      if ((j & i) == 0) {\n\
    \        T x = f[j], y = f[j | i];\n        f[j] = x + y, f[j | i] = x - y;\n\
    \      }\n    }\n  }\n  if (inv) {\n    if constexpr (is_integral<T>::value) {\n\
    \      for (auto& x : f) x /= n;\n    } else {\n      T invn = T(1) / T(f.size());\n\
    \      for (auto& x : f) x *= invn;\n    }\n  }\n}\n#line 4 \"set/xor-convolution.hpp\"\
    \n\ntemplate <class T>\nvector<T> XorConvolution(vector<T> a, vector<T> b) {\n\
    \  assert(a.size() == b.size());\n  HadamardTransform(a);\n  HadamardTransform(b);\n\
    \  for (int i = 0; i < a.size(); i++) a[i] *= b[i];\n  HadamardTransform(a, true);\n\
    \  return a;\n}\n"
  code: "#pragma once\n\n#include \"./hadamard-transform.hpp\"\n\ntemplate <class\
    \ T>\nvector<T> XorConvolution(vector<T> a, vector<T> b) {\n  assert(a.size()\
    \ == b.size());\n  HadamardTransform(a);\n  HadamardTransform(b);\n  for (int\
    \ i = 0; i < a.size(); i++) a[i] *= b[i];\n  HadamardTransform(a, true);\n  return\
    \ a;\n}"
  dependsOn:
  - set/hadamard-transform.hpp
  isVerificationFile: false
  path: set/xor-convolution.hpp
  requiredBy: []
  timestamp: '2025-10-10 17:35:46+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/set/LC_bitwise_xor_convolution.test.cpp
documentation_of: set/xor-convolution.hpp
layout: document
redirect_from:
- /library/set/xor-convolution.hpp
- /library/set/xor-convolution.hpp.html
title: set/xor-convolution.hpp
---
